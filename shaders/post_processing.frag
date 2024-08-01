#version 330 core

#define edge mat3(-1, -1, -1, -1, 8, -1, -1, -1, -1)
#define sharpen mat3(0, -1, 0, -1, 5, -1, 0, -1, 0)
#define blur mat3(1, 1, 1, 1, 1, 1, 1, 1, 1) * 0.1111
#define gaussian mat3(1, 2, 1, 2, 4, 2, 1, 2, 1) * 0.0625
#define emboss mat3(-2, -1, 0, -1, 1, 1, 0, 1, 2)

in VertexInput
{
    vec2 Position;
    vec2 Texcoord;
} Input;

uniform sampler2D scrQuad;
uniform int postProcessID;
uniform vec2 resolution;

vec2 FindCoord(int index)
{
    return vec2[9] (
        vec2(-1, -1), vec2(0, -1), vec2(1, -1),
        vec2(-1,  0), vec2(0,  0), vec2(1,  0), 
        vec2(-1,  1), vec2(0,  1), vec2(1,  1)
    )[index] / resolution;
}

mat3[3] CalcRegion(vec2 texcoord)
{
    vec4[9] region;
    for (int i = 0; i < 9; i++)
        region[i] = texture(scrQuad, texcoord + FindCoord(i));
    mat3[3] result;
    
    for (int i = 0; i < 3; i++)
        result[i] = mat3(
        	region[0][i], region[1][i], region[2][i],
        	region[3][i], region[4][i], region[5][i],
        	region[6][i], region[7][i], region[8][i]
    	);
    return result;
}

vec3 Convolute(mat3 kernel, vec2 texcoord)
{
    vec3 result;
    mat3[3] region = CalcRegion(texcoord);
    for (int i = 0; i < 3; i++)
    {
        mat3 rc = region[i];
        mat3 c = kernel * rc;
        float r = c[0][0] + c[1][0] + c[2][0]
                + c[0][1] + c[1][1] + c[2][1]
                + c[0][2] + c[1][2] + c[2][2];        
        result[i] = r;
    }
    return result;
}

vec4 Blur(vec2 texcoord)
{
    return vec4(Convolute(blur, texcoord), 1.0);
}

vec4 GaussianBlur(vec2 texcoord)
{
    return vec4(Convolute(gaussian, texcoord), 1.0);
}

vec4 EdgeDetection(vec2 texcoord)
{
    return vec4(Convolute(edge, texcoord), 1.0);
}

vec4 InvertFrag(vec4 color)
{
    return vec4(vec3(1.0 - color.rgb), color.a);
}

void main()
{
    vec2 texcoord = vec2(Input.Texcoord.x, 1.0 - Input.Texcoord.y);
    vec4 color = texture(scrQuad, texcoord);
    switch(postProcessID)
    {
        case 0: gl_FragColor = color; break;
        case 1: gl_FragColor = InvertFrag(color); break;
        case 2: gl_FragColor = Blur(texcoord); break;
        case 3: gl_FragColor = GaussianBlur(texcoord); break;
        case 4: gl_FragColor = EdgeDetection(texcoord); break;
        default: break;
    }
}