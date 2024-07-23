#version 330 core

in VertexInput
{
    vec2 Texcoord;
    vec4 Color;
} Input;

uniform bool meshHasTexture;
uniform sampler2D meshTextureData;
uniform vec3 meshColor;

void main()
{
    vec3 materialColor = meshColor * Input.Color.rgb;
    if(meshHasTexture)
        materialColor *= texture(meshTextureData, Input.Texcoord);
    gl_FragColor = vec4(materialColor, 1.0);
}