// ADS Point lighting Shader
// Fragment Shader
// Richard S. Wright Jr.
// OpenGL SuperBible
#version 120

varying vec4 vVaryingColor;

void main(void)
{
    gl_FragColor = vVaryingColor;
}
