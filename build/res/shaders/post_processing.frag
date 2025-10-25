#version 330 core

#define edge float[9](-1, -1, -1, -1, 9, -1, -1, -1, -1)
#define sharpen float[9](0, -1, 0, -1, 5, -1, 0, -1, 0)
#define blur float[9](1, 1, 1, 1, 1, 1, 1, 1, 1)
#define gaussian float[9](1, 2, 1, 2, 4, 2, 1, 2, 1)
#define emboss float[9](-2, -1, 0, -1, 1, 1, 0, 1, 2)
#define dilation float[9](0, 1, 0, 1, 1, 1, 0, 1, 0)

in VertexInput
{
    vec2 Position;
    vec2 Texcoord;
} Input;

uniform sampler2D u_scrQuad;
uniform int u_postProcMode;

vec2 FindCoord(int index)
{
    const float sampleDistance = 200.0;
    return vec2[9] (
        vec2(-1.0, -1.0), vec2(0.0, -1.0), vec2(1.0, -1.0),
        vec2(-1.0,  0.0), vec2(0.0,  0.0), vec2(1.0,  0.0), 
        vec2(-1.0,  1.0), vec2(0.0,  1.0), vec2(1.0,  1.0)
    )[index] / sampleDistance;
}

vec3 Convolute(float kernel[9], vec2 texcoord)
{
    vec3 result;
    for (int i = 0; i < 9; i++)
        result += texture(u_scrQuad, texcoord + FindCoord(i)).rgb * kernel[i];
    return result;
}

vec4 Monochrome(vec4 color)
{
    const vec3 grayscale = vec3(0.2125, 0.7154, 0.0721);
    return vec4(vec3(dot(color.rgb, grayscale)), color.a);
}

vec4 Sepia(vec4 color)
{
    const vec3 red = vec3(0.393, 0.769, 0.189);
    const vec3 green = vec3(0.349, 0.686, 0.168);
    const vec3 blue = vec3(0.272, 0.534, 0.131);
    vec3 result;
    result.r = dot(color.rgb, red);
    result.g = dot(color.rgb, green);
    result.b = dot(color.rgb, blue);
    return vec4(result, color.a);
}

void main()
{
    vec2 texcoord = vec2(Input.Texcoord.x, 1.0 - Input.Texcoord.y);
    vec4 color = texture(u_scrQuad, texcoord);
    switch(u_postProcMode)
    {
        case 0: gl_FragColor = color; break;
        case 1: gl_FragColor = vec4(vec3(1.0 - color.rgb), color.a); break;
        case 2: gl_FragColor = vec4(Convolute(blur, texcoord) * 0.1111, 1.0); break;
        case 3: gl_FragColor = vec4(Convolute(gaussian, texcoord) * 0.0625, 1.0); break;
        case 4: gl_FragColor = vec4(Convolute(edge, texcoord), 1.0); break;
        case 5: gl_FragColor = vec4(Convolute(sharpen, texcoord), 1.0); break;
        case 6: gl_FragColor = vec4(Convolute(emboss, texcoord), 1.0); break;
        case 7: gl_FragColor = Monochrome(color); break;
        case 8: gl_FragColor = Sepia(color); break;
        case 9: gl_FragColor = vec4(Convolute(dilation, texcoord) * 0.2, 1.0); break;
        default: break;
    }
}