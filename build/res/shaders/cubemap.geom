#version 330 core
layout (points) in;
layout (triangle_strip, max_vertices = 14) out;
#define NUM_INDICES 14

uniform mat4 u_projection;
uniform mat4 u_view;

out vec4 Position;

void main()
{
    const vec3 vertices[8] = vec3[]
    (
        vec3(-1.0f, -1.0f,  1.0f),
        vec3( 1.0f, -1.0f,  1.0f),
        vec3(-1.0f,  1.0f,  1.0f),
        vec3( 1.0f,  1.0f,  1.0f),
        vec3(-1.0f, -1.0f, -1.0f),
        vec3( 1.0f, -1.0f, -1.0f),
        vec3(-1.0f,  1.0f, -1.0f),
        vec3( 1.0f,  1.0f, -1.0f)
    );
    const int indices[NUM_INDICES] = int[]
    (
        0, 1, 2, 3, 7, 
        1, 5, 4, 7, 6, 
        2, 4, 0, 1
    );
    for(int i = 0; i < NUM_INDICES; i++)
    {
        Position = gl_in[0].gl_Position + vec4(vertices[indices[i]], 0.0);
        gl_Position = (u_projection * u_view * Position).xyww;
        EmitVertex();
    }
    EndPrimitive();
}