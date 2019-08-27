#version 330 core

layout(location = 0) out vec4 color;
layout(location = 1) out vec4 texColor;

uniform sampler2D u_Texture;
uniform vec4 u_Color;

in vec2 v_TexCoord;

void main()
{
    vec4 texColor = texture(u_Texture, v_TexCoord);
    color = texColor;
//    color = texColor * u_Color;
//    color = u_Color;
};