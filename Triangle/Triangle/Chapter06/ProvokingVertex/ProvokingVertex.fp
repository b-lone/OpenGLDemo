// ProvokingVertex flat shader demo
// Fragment Shader
// Richard S. Wright Jr.
// OpenGL SuperBible
#version 120

flat attribute vec4 vVaryingColor;

void main(void)
{ 
   gl_FragColor = vVaryingColor;
}
