#ifndef MESH_H
#define MESH_H

struct default_3d_vertex
{
    vec3 position;
    vec3 normal;
    vec2 texcoord;
    vec4 color;
};

struct Mesh
{
    VAO vao;
    Buffer<default_3d_vertex, GL_ARRAY_BUFFER> vbo;
    Buffer<u32, GL_ELEMENT_ARRAY_BUFFER> ebo;
    Transform3D<f32> transform;
    std::array<Material, materialCount> materials;
    int drawMode = GL_TRIANGLES;
    bool drawIndexed = false;
    usize indexCount = 0;
    template <typename CL, typename CR = std::vector<u32>>
    inline void Build(
        const CL& vertices,
        const CR& indices = {},
        int flag = GL_STATIC_DRAW,
        typename std::enable_if_t<
            all_container_v<CL, CR> && 
            is_inner_type_same_v<default_3d_vertex, CL> &&
            is_inner_type_same_v<u32, CR>>* = 0)
    {
        vao.Build();
        vbo.Build(vertices, flag);
        vbo.AddAttrib(0, 3, offsetof(default_3d_vertex, position));
        vbo.AddAttrib(1, 3, offsetof(default_3d_vertex, normal));
        vbo.AddAttrib(2, 2, offsetof(default_3d_vertex, texcoord));
        vbo.AddAttrib(3, 4, offsetof(default_3d_vertex, color));
        drawIndexed = !indices.empty();
        if(drawIndexed) 
        {
            indexCount = indices.size();
            ebo.Build(indices, flag);
        }
        else
            indexCount = vertices.size();
    }
    template <typename CL, typename CR = std::vector<u32>>
    inline void Map(
        const CL& vertices,
        const CR& indices = {},
        typename std::enable_if_t<
            all_container_v<CL, CR> &&
            is_inner_type_same_v<default_3d_vertex, CL> &&
            is_inner_type_same_v<u32, CR>>* = 0)
    {
        vao.Bind();
        vbo.Resize(vertices.size());
        vbo.Map(vertices);
        drawIndexed = !indices.empty();
        if(drawIndexed)
        {
            indexCount = indices.size();
            ebo.Map(indices);
        }
        else
        {
            indexCount = vertices.size();
            ebo.Release();
        }
        vao.Unbind();
    }
};

inline const vec2 from_ai_vec2(const aiVector2D& vec)
{
    return {vec.x, vec.y};
}

inline const vec3 from_ai_vec3(const aiVector3D& vec)
{
    return {vec.x, vec.y, vec.z};
}

inline const mat4 from_ai_mat4(const aiMatrix4x4& mat)
{
    mat4 res = mat4::identity();
    res[0][0] = mat.a1; res[1][0] = mat.a2; res[2][0] = mat.a3; res[3][0] = mat.a4;
    res[0][1] = mat.b1; res[1][1] = mat.b2; res[2][1] = mat.b3; res[3][1] = mat.b4;
    res[0][2] = mat.c1; res[1][2] = mat.c2; res[2][2] = mat.c3; res[3][2] = mat.c4;
    res[0][3] = mat.d1; res[1][3] = mat.d2; res[2][3] = mat.d3; res[3][3] = mat.d4;
    return res;
}

inline const quat from_ai_quat(const aiQuaternion& quat)
{
    return {quat.w, quat.x, quat.y, quat.z};
}

inline void SubdivideFace(std::vector<default_3d_vertex>& vertices, const vec3& pos0, const vec3& pos1, const vec3& pos2, int depth)
{
    if (depth == 0)
    {
        vertices.push_back({pos0});
        vertices.push_back({pos1});
        vertices.push_back({pos2});
        return;
    }
    const vec3 pos01 = (pos0 + pos1).norm();
    const vec3 pos12 = (pos1 + pos2).norm();
    const vec3 pos02 = (pos0 + pos2).norm();
    SubdivideFace(vertices, pos0, pos01, pos02, depth-1);
    SubdivideFace(vertices, pos1, pos12, pos01, depth-1);
    SubdivideFace(vertices, pos2, pos02, pos12, depth-1);
    SubdivideFace(vertices, pos01, pos12, pos02, depth-1);
}

inline void InvertNormals(std::vector<default_3d_vertex>& vertices)
{
    for(default_3d_vertex& v : vertices)
        v.normal = -v.normal;
}

inline void BuildCube(Mesh& mesh, bool map = false)
{
    const std::vector<default_3d_vertex> vertices = 
    {
        {{-0.5f, -0.5f, -0.5f}, { 0.0f,  0.0f, -1.0f}, {0.0f, 0.0f}, 1.0f},
        {{ 0.5f,  0.5f, -0.5f}, { 0.0f,  0.0f, -1.0f}, {1.0f, 1.0f}, 1.0f},
        {{ 0.5f, -0.5f, -0.5f}, { 0.0f,  0.0f, -1.0f}, {1.0f, 0.0f}, 1.0f},
        {{ 0.5f,  0.5f, -0.5f}, { 0.0f,  0.0f, -1.0f}, {1.0f, 1.0f}, 1.0f},
        {{-0.5f, -0.5f, -0.5f}, { 0.0f,  0.0f, -1.0f}, {0.0f, 0.0f}, 1.0f},
        {{-0.5f,  0.5f, -0.5f}, { 0.0f,  0.0f, -1.0f}, {0.0f, 1.0f}, 1.0f},
        {{-0.5f, -0.5f,  0.5f}, { 0.0f,  0.0f,  1.0f}, {0.0f, 0.0f}, 1.0f},
        {{ 0.5f, -0.5f,  0.5f}, { 0.0f,  0.0f,  1.0f}, {1.0f, 0.0f}, 1.0f},
        {{ 0.5f,  0.5f,  0.5f}, { 0.0f,  0.0f,  1.0f}, {1.0f, 1.0f}, 1.0f},
        {{ 0.5f,  0.5f,  0.5f}, { 0.0f,  0.0f,  1.0f}, {1.0f, 1.0f}, 1.0f},
        {{-0.5f,  0.5f,  0.5f}, { 0.0f,  0.0f,  1.0f}, {0.0f, 1.0f}, 1.0f},
        {{-0.5f, -0.5f,  0.5f}, { 0.0f,  0.0f,  1.0f}, {0.0f, 0.0f}, 1.0f},
        {{-0.5f,  0.5f,  0.5f}, {-1.0f,  0.0f,  0.0f}, {1.0f, 0.0f}, 1.0f},
        {{-0.5f,  0.5f, -0.5f}, {-1.0f,  0.0f,  0.0f}, {1.0f, 1.0f}, 1.0f},
        {{-0.5f, -0.5f, -0.5f}, {-1.0f,  0.0f,  0.0f}, {0.0f, 1.0f}, 1.0f},
        {{-0.5f, -0.5f, -0.5f}, {-1.0f,  0.0f,  0.0f}, {0.0f, 1.0f}, 1.0f},
        {{-0.5f, -0.5f,  0.5f}, {-1.0f,  0.0f,  0.0f}, {0.0f, 0.0f}, 1.0f},
        {{-0.5f,  0.5f,  0.5f}, {-1.0f,  0.0f,  0.0f}, {1.0f, 0.0f}, 1.0f},
        {{ 0.5f,  0.5f,  0.5f}, { 1.0f,  0.0f,  0.0f}, {1.0f, 0.0f}, 1.0f},
        {{ 0.5f, -0.5f, -0.5f}, { 1.0f,  0.0f,  0.0f}, {0.0f, 1.0f}, 1.0f},
        {{ 0.5f,  0.5f, -0.5f}, { 1.0f,  0.0f,  0.0f}, {1.0f, 1.0f}, 1.0f},
        {{ 0.5f, -0.5f, -0.5f}, { 1.0f,  0.0f,  0.0f}, {0.0f, 1.0f}, 1.0f},
        {{ 0.5f,  0.5f,  0.5f}, { 1.0f,  0.0f,  0.0f}, {1.0f, 0.0f}, 1.0f},
        {{ 0.5f, -0.5f,  0.5f}, { 1.0f,  0.0f,  0.0f}, {0.0f, 0.0f}, 1.0f},
        {{-0.5f, -0.5f, -0.5f}, { 0.0f, -1.0f,  0.0f}, {0.0f, 1.0f}, 1.0f},
        {{ 0.5f, -0.5f, -0.5f}, { 0.0f, -1.0f,  0.0f}, {1.0f, 1.0f}, 1.0f},
        {{ 0.5f, -0.5f,  0.5f}, { 0.0f, -1.0f,  0.0f}, {1.0f, 0.0f}, 1.0f},
        {{ 0.5f, -0.5f,  0.5f}, { 0.0f, -1.0f,  0.0f}, {1.0f, 0.0f}, 1.0f},
        {{-0.5f, -0.5f,  0.5f}, { 0.0f, -1.0f,  0.0f}, {0.0f, 0.0f}, 1.0f},
        {{-0.5f, -0.5f, -0.5f}, { 0.0f, -1.0f,  0.0f}, {0.0f, 1.0f}, 1.0f},
        {{-0.5f,  0.5f, -0.5f}, { 0.0f,  1.0f,  0.0f}, {0.0f, 1.0f}, 1.0f},
        {{ 0.5f,  0.5f , 0.5f}, { 0.0f,  1.0f,  0.0f}, {1.0f, 0.0f}, 1.0f},
        {{ 0.5f,  0.5f, -0.5f}, { 0.0f,  1.0f,  0.0f}, {1.0f, 1.0f}, 1.0f},
        {{ 0.5f,  0.5f,  0.5f}, { 0.0f,  1.0f,  0.0f}, {1.0f, 0.0f}, 1.0f},
        {{-0.5f,  0.5f, -0.5f}, { 0.0f,  1.0f,  0.0f}, {0.0f, 1.0f}, 1.0f},
        {{-0.5f,  0.5f,  0.5f}, { 0.0f,  1.0f,  0.0f}, {0.0f, 0.0f}, 1.0f}
    };
    if(map)
        mesh.Map(vertices);
    else
        mesh.Build(vertices);
}

inline void BuildCylinderCap(std::vector<default_3d_vertex>& vertices, std::vector<u32>& indices, bool isTop, const usize& offset, const usize& tesselation)
{
    const f32 ang = two_pi<f32> / tesselation;
    const f32 y = isTop ? 1.0f : -1.0f;
    for(usize i = 0; i < tesselation; i++)
    {
        const vec2 uv = {std::cos(ang * i), std::sin(ang * i)};
        const vec3 pos = {uv.x, y, uv.y};
        vertices.push_back({
            .position = pos * 0.5f,
            .normal = pos,
            .texcoord = uv * 0.5f + 0.5f,
            .color = 1.0f
        });
    }
    for(usize i = 0; i < tesselation - 2; i++)
    {
        indices.push_back(offset + 1);
        indices.push_back(offset + i + 1);
        indices.push_back(offset + i + 2);
    }
}

inline void BuildCone(Mesh& mesh, const usize& tesselation = 48, bool map = false)
{
    std::vector<default_3d_vertex> vertices;
    std::vector<u32> indices;
    const f32 ang = two_pi<f32> / tesselation;
    vertices.reserve(tesselation + 1);
    indices.reserve(3 * tesselation);
    for(usize i = 0; i < tesselation; i++)
    {
        const vec3 pos = {std::cos(ang * i), -1.0f, std::sin(ang * i)};
        vertices.push_back({
            .position = pos * 0.5f,
            .normal = pos,
            .texcoord = {(f32)i / tesselation, 1.0f},
            .color = 1.0f
        });
    }
    vertices.push_back({
        .position = {0.0f, 0.5f, 0.0f},
        .normal = vec3::up(),
        .texcoord = 0.0f,
        .color = 1.0f
    });
    for(usize i = 0; i < tesselation; i++) 
    {
    	indices.push_back(i);
    	indices.push_back(tesselation);
    	indices.push_back((i + 1) % tesselation);
    }
    BuildCylinderCap(vertices, indices, false, tesselation, tesselation);
    if(map)
        mesh.Map(vertices, indices);
    else
        mesh.Build(vertices, indices);
}

inline void BuildCylinder(Mesh& mesh, const usize& tesselation = 48, bool map = false)
{
    std::vector<default_3d_vertex> vertices;
    std::vector<u32> indices;
    const f32 ang = two_pi<f32> / tesselation;
    vertices.reserve(2 * tesselation);
    for(usize i = 0; i < tesselation; i++)
    {
        const vec3 top = {std::cos(ang * i), 1.0f, std::sin(ang * i)};
        const vec2 uv = {(f32)i / tesselation, 0.0f};
        vertices.push_back({
            .position = top * 0.5f,
            .normal = top,
            .texcoord = uv,
            .color = 1.0f
        });
        const vec3 bottom = {top.x, -1.0f, top.z};
        vertices.push_back({
            .position = bottom * 0.5f,
            .normal = bottom,
            .texcoord = {uv.x, 1.0f},
            .color = 1.0f
        });
    }
    const usize size = 2 * tesselation;
    indices.reserve(6 * size);
    for(usize i = 0; i < size; i++)
    {
        indices.push_back(i);
        indices.push_back((i + 1) % size);
        indices.push_back((i + 2) % size);
        indices.push_back((i + 1) % size);
        indices.push_back((i + 2) % size);
        indices.push_back((i + 3) % size);
    }
    BuildCylinderCap(vertices, indices, false, 2 * tesselation, tesselation);
    BuildCylinderCap(vertices, indices, true, 3 * tesselation, tesselation);
    if(map)
        mesh.Map(vertices, indices);
    else
        mesh.Build(vertices, indices);
}

inline void BuildIcosehadron(Mesh& mesh, int depth = 3, bool map = false)
{
    static constexpr f32 x = 0.525731112119133606f;
    static constexpr f32 z = 0.850650808352039932f;
    static constexpr vec3 defVertices[12] = 
    {
        {-x, 0.0f, z}, {x, 0.0f, z}, {-x, 0.0f, -z}, {x, 0.0f, -z},
        {0.0f, z, x}, {0.0f, z, -x}, {0.0f, -z, x}, {0.0f, -z, -x},
        {z, x, 0.0f}, {-z, x, 0.0f}, {z, -x, 0.0f}, {-z, -x, 0.0f}
    };
    static constexpr usvec3 defIndices[20] = 
    {
        {0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},
        {8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},
        {7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6},
        {6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11}
    };
    auto CalculateTexcoord = [](const vec3& pos) -> const vec2
    {
        return {0.5f * (1.0f + std::atan2(pos.z, pos.x) * one_over_pi<f32>), std::acos(pos.y) * one_over_pi<f32>};
    };
    std::vector<default_3d_vertex> vertices;
    for(usize i = 0; i < std::size(defIndices); i++)
        SubdivideFace(vertices, defVertices[defIndices[i][0]], defVertices[defIndices[i][1]], defVertices[defIndices[i][2]], depth);
    for(usize i = 0; i < vertices.size(); i+=3)
    {
        const vec3 normal = surface_normal(vertices[i].position, vertices[i + 1].position, vertices[i + 2].position);
        vertices[i].normal = vertices[i + 1].normal = vertices[i + 2].normal = normal;
        vertices[i].color = vertices[i + 1].color = vertices[i + 2].color = 1.0f;
        vertices[i].texcoord = CalculateTexcoord(vertices[i].position);
        vertices[i + 1].texcoord = CalculateTexcoord(vertices[i + 1].position);
        vertices[i + 2].texcoord = CalculateTexcoord(vertices[i + 2].position);
    }
    if(map)
        mesh.Map(vertices);
    else
        mesh.Build(vertices);
}

inline void BuildCapsule(Mesh& mesh, f32 height = 1.0f, const usize& tesselation = 18, bool map = false)
{
    const usize sectorCount = tesselation * 2;
    const usize stackCount = tesselation;
    std::vector<default_3d_vertex> vertices;
    std::vector<u32> indices;
    const f32 sectorStep = two_pi<f32> / sectorCount;
    const f32 stackStep = pi<f32> / stackCount;
    vertices.reserve(stackCount * sectorCount);
    for(usize i = 0; i <= stackCount; i++)
    {
        const f32 stackAngle = half_pi<f32> - i * stackStep;    
        for(usize j = 0; j <= sectorCount; j++)
        {
            const f32 sectorAngle = j * sectorStep;
            const vec3 pos = 
            {
                std::cos(stackAngle) * std::cos(sectorAngle),
                std::cos(stackAngle) * std::sin(sectorAngle) + (j >= stackCount ? -height : height),
                std::sin(stackAngle)
            };
            vec2 uv = {(f32)j / sectorCount, (f32)i / stackCount};
            if(j == stackCount && height != 0.0f)
                uv.x = 1.0f;
            vertices.push_back({
                .position = pos * 0.5f,
                .normal = pos,
                .texcoord = uv,
                .color = 1.0f
            });
        }
    }
    const usize stride = sectorCount + 1;
    indices.reserve(stride * stackCount);
    for (usize i = 0; i < stackCount; i++)
        for (usize j = 0; j <= sectorCount; j++)
        {
            const usize offset0 = i + 1;
            const usize offset1 = (j + 1) % stride;
            indices.push_back(i * stride + j);
            indices.push_back(offset0 * stride + j);
            indices.push_back(i * stride + offset1);
            indices.push_back(i * stride + offset1);
            indices.push_back(offset0 * stride + j);
            indices.push_back(offset0 * stride + offset1);
        }
    if(map)
        mesh.Map(vertices, indices);
    else
        mesh.Build(vertices, indices);
}

inline void BuildSphere(Mesh& mesh, const usize& tesselation = 18, bool map = false)
{
    BuildCapsule(mesh, 0.0f, tesselation, map);
}

inline void BuildModelFromFile(std::vector<Mesh>& model, const std::string& file)
{
    model.clear();
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(file, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        return;
    auto processNode = [&](aiNode* node, const aiScene* scene)
    {
        auto processNodeHelper = [&](aiNode* node, const aiScene* scene, auto& processNodeRef) mutable -> void
        {
            for(usize i = 0; i < node->mNumMeshes; i++)
            {
                Mesh newMesh;
                aiMesh *mesh = scene->mMeshes[node->mMeshes[i]]; 
                std::vector<default_3d_vertex> vertices;
                std::vector<u32> indices;
                for(usize j = 0; j < mesh->mNumVertices; j++)
                    vertices.push_back({
                        .position = from_ai_vec3(mesh->mVertices[j]),
                        .normal = from_ai_vec3(mesh->mNormals[j]),
                        .texcoord = mesh->mTextureCoords[0] ? (vec2)from_ai_vec3(mesh->mTextureCoords[0][j]).xy : vec2::zero(),
                        .color = 1.0f
                    });
                for(usize j = 0; j < mesh->mNumFaces; j++)
                    for(usize k = 0; k < mesh->mFaces[j].mNumIndices; k++)
                        indices.push_back(mesh->mFaces[j].mIndices[k]);
                newMesh.Build(vertices, indices);
                model.push_back(std::move(newMesh));
                //TODO: Materials
            }
            for(usize i = 0; i < node->mNumChildren; i++)
                processNodeRef(node->mChildren[i], scene, processNodeRef);
        };
        processNodeHelper(node, scene, processNodeHelper);
    };
    processNode(scene->mRootNode, scene);
}

#endif