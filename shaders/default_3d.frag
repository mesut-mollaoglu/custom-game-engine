#version 330 core

in VertexInput
{
    vec2 Texcoord;
    vec4 Color;
} Input;

uniform bool meshHasTexture[MATERIAL_COUNT];
uniform sampler2D meshTextureData[MATERIAL_COUNT];
uniform vec3 meshColor[MATERIAL_COUNT];

void main()
{
    vec3 finalColor;
    for(int i = 0; i < MATERIAL_COUNT; i++)
    {
        vec3 materialColor = meshColor[i] * Input.Color.rgb;
        if(meshHasTexture[i])
            materialColor *= texture(meshTextureData[i], Input.Texcoord);
        finalColor += materialColor;
    }
    gl_FragColor = vec4(finalColor, 1.0);
}