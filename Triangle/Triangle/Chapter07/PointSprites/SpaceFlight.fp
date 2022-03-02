// SpaceFlight Shader
// Fragment Shader
// Richard S. Wright Jr.
// OpenGL SuperBible
#version 120

varying vec4 vStarColor;
varying mat2 rotation_matrix;

uniform sampler2D  starImage;

void main(void)
{
    //vec2 p = gl_PointCoord * 2.0 - vec2(1.0);
    //if(dot(p, p) > 1.0)
    //    discard;
    //if(dot(p, p) > sin(atan(p.y, p.x) * 5.0))
    //    discard;
    
    vec2 pt = gl_PointCoord - vec2(0.5);
        
    gl_FragColor = texture2D(starImage, pt * rotation_matrix + vec2(0.5)) * vStarColor;
    //gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
    
