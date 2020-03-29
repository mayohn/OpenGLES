precision mediump float;

uniform vec4 u_Color;
layout(std140) uniform LightBlock
{
    vec3 lightDirection;
    vec4 lightPosition;
};
void main()
{
    gl_FragColor = u_Color;
}