#ifndef GRAPHICS_3D_H
#define GRAPHICS_3D_H

#include "includes.h"

struct default_3d_vertex
{
    v3f position;
    v3f normal;
    v2f texcoord;
    v4f color;
};

struct Renderable3D
{
    std::vector<GLuint> textures;
    std::vector<default_3d_vertex> vertices;
    std::vector<uint16_t> indices;
    Transform3D transform;
};

inline void BuildCube(Renderable3D& renderable)
{
    renderable.indices =
    {
        2, 6, 7, 2, 3, 7,
        0, 4, 5, 0, 1, 5,
        0, 2, 6, 0, 4, 6,
        1, 3, 7, 1, 5, 7,
        0, 2, 3, 0, 1, 3,
        4, 6, 7, 4, 5, 7
    };
    renderable.vertices = 
    {
        {{-1.0f, -1.0f,  1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{ 1.0f, -1.0f,  1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{-1.0f,  1.0f,  1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{ 1.0f,  1.0f,  1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{-1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{ 1.0f, -1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{-1.0f,  1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
        {{ 1.0f,  1.0f, -1.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}}
    };
}

struct Renderer3D
{
    Window* window = nullptr;
    VAO vao;
    Buffer<default_3d_vertex, GL_ARRAY_BUFFER> vbo;
    Buffer<uint16_t, GL_ELEMENT_ARRAY_BUFFER> ebo;
    inline Renderer3D() = default;
    inline Renderer3D(Window* window);
    inline void Draw(Renderable3D& object);
};

#endif

#ifdef GRAPHICS_3D_H
#undef GRAPHICS_3D_H

inline Renderer3D::Renderer3D(Window* window) : window(window)
{
    vao.Build();
    vbo.Build(GL_DYNAMIC_DRAW);
    ebo.Build(GL_DYNAMIC_DRAW);
    vbo.AddAttrib(0, 3, offsetof(default_3d_vertex, position));
    vbo.AddAttrib(1, 3, offsetof(default_3d_vertex, normal));
    vbo.AddAttrib(2, 2, offsetof(default_3d_vertex, texcoord));
    vbo.AddAttrib(3, 4, offsetof(default_3d_vertex, color));
}

inline void Renderer3D::Draw(Renderable3D& object)
{
    window->EnableDepth(true);
    window->SetShader(3);
    window->GetShader(3).SetUniformMat("model", object.transform.TransformMat());
    vao.Bind();
    vbo.Map(object.vertices);
    ebo.Map(object.indices);
    glDrawElements(GL_TRIANGLES, object.indices.size(), GL_UNSIGNED_SHORT, NULL);
    vao.Unbind();
}

#endif