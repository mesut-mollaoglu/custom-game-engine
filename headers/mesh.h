#ifndef MESH_H
#define MESH_H

#include "includes.h"

struct default_3d_vertex
{
    vec3f position;
    vec3f normal;
    vec2f texcoord;
    vec4f color;
};

struct Mesh
{
    VAO vao;
    Buffer<default_3d_vertex, GL_ARRAY_BUFFER> vbo;
    Buffer<uint16_t, GL_ELEMENT_ARRAY_BUFFER> ebo;
    Transform3D<float> transform;
    Material material;
    int drawMode = GL_TRIANGLES;
    bool drawIndexed = false;
    size_t indexCount = 0;
};

inline void BuildMesh(Mesh& mesh, const std::vector<default_3d_vertex>& vertices, const std::vector<uint16_t>& indices = {}, const int mapFlag = GL_STATIC_DRAW)
{
    mesh.vao.Build();
    mesh.vbo.Build(vertices, mapFlag);
    mesh.vbo.AddAttrib(0, 3, offsetof(default_3d_vertex, position));
    mesh.vbo.AddAttrib(1, 3, offsetof(default_3d_vertex, normal));
    mesh.vbo.AddAttrib(2, 2, offsetof(default_3d_vertex, texcoord));
    mesh.vbo.AddAttrib(3, 4, offsetof(default_3d_vertex, color));
    if(!indices.empty()) 
    {
        mesh.drawIndexed = true;
        mesh.indexCount = indices.size();
        mesh.ebo.Build(indices, mapFlag);
    }
    else
        mesh.indexCount = vertices.size();
}

inline const vec3f from_ai_vec3(const aiVector3D& vec)
{
    return {vec.x, vec.y, vec.z};
}

inline const mat4x4f from_ai_mat4(const aiMatrix4x4& mat)
{
    mat4x4f res = mat4x4f::identity();
    res[0][0] = mat.a1; res[1][0] = mat.a2; res[2][0] = mat.a3; res[3][0] = mat.a4;
    res[0][1] = mat.b1; res[1][1] = mat.b2; res[2][1] = mat.b3; res[3][1] = mat.b4;
    res[0][2] = mat.c1; res[1][2] = mat.c2; res[2][2] = mat.c3; res[3][2] = mat.c4;
    res[0][3] = mat.d1; res[1][3] = mat.d2; res[2][3] = mat.d3; res[3][3] = mat.d4;
    return res;
}

inline const quatf from_ai_quat(const aiQuaternion& quat)
{
    return {quat.w, quat.x, quat.y, quat.z};
}

inline void MapMesh(Mesh& mesh, const std::vector<default_3d_vertex>& vertices, const std::vector<uint16_t>& indices = {})
{
    mesh.vao.Bind();
    mesh.vbo.Resize(vertices.size());
    mesh.vbo.Map(vertices);
    mesh.drawIndexed = !indices.empty();
    if(mesh.drawIndexed)
    {
        mesh.ebo.Resize(mesh.indexCount = indices.size());
        mesh.ebo.Map(indices);
    }
    else
    {
        mesh.indexCount = vertices.size();
        mesh.ebo.Release();
    }
    mesh.vao.Unbind();
}

inline void SubdivideFace(std::vector<default_3d_vertex>& vertices, const vec3f& pos0, const vec3f& pos1, const vec3f& pos2, int depth)
{
    if (depth == 0)
    {
        vertices.push_back({pos0});
        vertices.push_back({pos1});
        vertices.push_back({pos2});
        return;
    }
    const vec3f pos01 = (pos0 + pos1).norm();
    const vec3f pos12 = (pos1 + pos2).norm();
    const vec3f pos02 = (pos0 + pos2).norm();
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

inline void BuildCube(Mesh& mesh)
{
    BuildMesh(mesh,
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
    });
}

inline void BuildCylinderCap(std::vector<default_3d_vertex>& vertices, std::vector<uint16_t>& indices, bool isTop, const size_t& offset, const size_t& tesselation)
{
    const float ang = two_pi / tesselation;
    const float y = isTop ? 1.0f : -1.0f;
    for(size_t i = 0; i < tesselation; i++)
    {
        const vec2f uv = {std::cos(ang * i), std::sin(ang * i)};
        const vec3f pos = {uv.x, y, uv.y};
        vertices.push_back({
            .position = pos * 0.5f,
            .normal = pos,
            .texcoord = uv * 0.5f + 0.5f,
            .color = 1.0f
        });
    }
    for(size_t i = 0; i < tesselation - 2; i++)
    {
        indices.push_back(offset + 1);
        indices.push_back(offset + i + 1);
        indices.push_back(offset + i + 2);
    }
}

inline void BuildCone(Mesh& mesh, const size_t& tesselation = 48)
{
    std::vector<default_3d_vertex> vertices;
    std::vector<uint16_t> indices;
    const float ang = two_pi / tesselation;
    for(size_t i = 0; i < tesselation; i++)
    {
        const vec3f pos = {std::cos(ang * i), -1.0f, std::sin(ang * i)};
        vertices.push_back({
            .position = pos * 0.5f,
            .normal = pos,
            .texcoord = {(float)i / tesselation, 1.0f},
            .color = 1.0f
        });
    }
    vertices.push_back({
        .position = {0.0f, 0.5f, 0.0f},
        .normal = vec3f::up(),
        .texcoord = 0.0f,
        .color = 1.0f
    });
    for(size_t i = 0; i < tesselation; i++) 
    {
    	indices.push_back(i);
    	indices.push_back(tesselation);
    	indices.push_back((i + 1) % tesselation);
    }
    BuildCylinderCap(vertices, indices, false, tesselation, tesselation);
    BuildMesh(mesh, vertices, indices);
}

inline void BuildCylinder(Mesh& mesh, const size_t& tesselation = 48)
{
    std::vector<default_3d_vertex> vertices;
    std::vector<uint16_t> indices;
    const float ang = two_pi / tesselation;
    for(size_t i = 0; i < tesselation; i++)
    {
        const vec3f top = {std::cos(ang * i), 1.0f, std::sin(ang * i)};
        const vec2f uv = {(float)i / tesselation, 0.0f};
        vertices.push_back({
            .position = top * 0.5f,
            .normal = top,
            .texcoord = uv,
            .color = 1.0f
        });
        const vec3f bottom = {top.x, -1.0f, top.z};
        vertices.push_back({
            .position = bottom * 0.5f,
            .normal = bottom,
            .texcoord = {uv.x, 1.0f},
            .color = 1.0f
        });
    }
    const size_t size = 2 * tesselation;
    for(size_t i = 0; i < size; i++)
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
    BuildMesh(mesh, vertices, indices);
}

inline void BuildIcosehadron(Mesh& mesh, const int depth = 3)
{
    static constexpr float x = 0.525731112119133606f;
    static constexpr float z = 0.850650808352039932f;
    static constexpr vec3f defVertices[12] = 
    {
        {-x, 0.0f, z}, {x, 0.0f, z}, {-x, 0.0f, -z}, {x, 0.0f, -z},
        {0.0f, z, x}, {0.0f, z, -x}, {0.0f, -z, x}, {0.0f, -z, -x},
        {z, x, 0.0f}, {-z, x, 0.0f}, {z, -x, 0.0f}, {-z, -x, 0.0f}
    };
    static constexpr vec3us defIndices[20] = 
    {
        {0,4,1}, {0,9,4}, {9,5,4}, {4,5,8}, {4,8,1},
        {8,10,1}, {8,3,10}, {5,3,8}, {5,2,3}, {2,7,3},
        {7,10,3}, {7,6,10}, {7,11,6}, {11,0,6}, {0,1,6},
        {6,1,10}, {9,0,11}, {9,11,2}, {9,2,5}, {7,2,11}
    };
    auto CalculateTexcoord = [](const vec3f& pos) -> const vec2f
    {
        return {0.5f * (1.0f + std::atan2(pos.z, pos.x) * (float)one_over_pi), std::acos(pos.y) * (float)one_over_pi};
    };
    std::vector<default_3d_vertex> vertices;
    for(size_t i = 0; i < std::size(defIndices); i++)
        SubdivideFace(vertices, defVertices[defIndices[i][0]], defVertices[defIndices[i][1]], defVertices[defIndices[i][2]], depth);
    for(size_t i = 0; i < vertices.size(); i+=3)
    {
        const vec3f normal = surface_normal(vertices[i].position, vertices[i + 1].position, vertices[i + 2].position);
        vertices[i].normal = vertices[i + 1].normal = vertices[i + 2].normal = normal;
        vertices[i].color = vertices[i + 1].color = vertices[i + 2].color = 1.0f;
        vertices[i].texcoord = CalculateTexcoord(vertices[i].position);
        vertices[i + 1].texcoord = CalculateTexcoord(vertices[i + 1].position);
        vertices[i + 2].texcoord = CalculateTexcoord(vertices[i + 2].position);
    }
    BuildMesh(mesh, vertices);
    return;
}

inline void BuildCapsule(Mesh& mesh, const float height = 1.0f, const size_t& tesselation = 18)
{
    const size_t sectorCount = tesselation * 2;
    const size_t stackCount = tesselation;
    std::vector<default_3d_vertex> vertices;
    std::vector<uint16_t> indices;
    const float sectorStep = two_pi / sectorCount;
    const float stackStep = pi / stackCount;
    for(size_t i = 0; i <= stackCount; i++)
    {
        const float stackAngle = half_pi - i * stackStep;    
        for(size_t j = 0; j <= sectorCount; j++)
        {
            const float sectorAngle = j * sectorStep;
            const vec3f pos = 
            {
                std::cos(stackAngle) * std::cos(sectorAngle),
                std::cos(stackAngle) * std::sin(sectorAngle) + (j >= stackCount ? -height : height),
                std::sin(stackAngle)
            };
            vec2f uv = {(float)j / sectorCount, (float)i / stackCount};
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
    const size_t stride = sectorCount + 1;
    indices.reserve(stride * stackCount);
    for (size_t i = 0; i < stackCount; i++)
        for (size_t j = 0; j <= sectorCount; j++)
        {
            const size_t offset0 = i + 1;
            const size_t offset1 = (j + 1) % stride;
            indices.push_back(i * stride + j);
            indices.push_back(offset0 * stride + j);
            indices.push_back(i * stride + offset1);
            indices.push_back(i * stride + offset1);
            indices.push_back(offset0 * stride + j);
            indices.push_back(offset0 * stride + offset1);
        }
    BuildMesh(mesh, vertices, indices);
}

inline void BuildSphere(Mesh& mesh, const size_t& tesselation = 18)
{
    BuildCapsule(mesh, 0.0f, tesselation);
}

inline void ProcessMesh(std::vector<default_3d_vertex>& vertices, std::vector<uint16_t>& indices, aiMesh* mesh, const aiScene* scene)
{
    return;
}

inline void BuildMeshFromFile(Mesh& mesh, const std::string& file)
{
    Assimp::Importer importer;
    const aiScene *scene = importer.ReadFile(file, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) 
        return;
    //TODO
}

#endif