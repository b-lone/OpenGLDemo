// Starfield Shader
// Fragment Shader
// Richard S. Wright Jr.
// OpenGL SuperBible
#version 120

uniform sampler2D  starImage;

void main(void)
{ 
    gl_FragColor = texture2D(starImage, gl_PointCoord);
}
    
