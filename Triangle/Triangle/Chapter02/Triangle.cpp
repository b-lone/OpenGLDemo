//
//  main.cpp
//  Triangle
//
//  Created by Archie on 2022/1/14.
//

#include "GLTools.h"
#include "GLShaderManager.h"
#include <glut/glut.h>
#include <iostream>
#include <time.h>

#define max(a, b) a > b ? a : b
#define min(a, b) a < b ? a : b

GLBatch triangleBatch;
GLShaderManager shaderManager;

GLfloat vVerts[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
};

void changeSize(int w, int h)
{
    glViewport(0, 0, w, h);
}

void setupRC()
{
    glClearColor(0.0, 0.0, 1.0, 1.0);
    
    shaderManager.InitializeStockShaders();
    
    triangleBatch.Begin(GL_TRIANGLES, 3);
    triangleBatch.CopyVertexData3f(vVerts);
    triangleBatch.End();
}

void renderScene()
{
//    time_t t;
//    time(&t);
//    static int count = 0;
//    printf("%s | %ld | %d\n", __func__, t, ++count);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    GLfloat vRed[] = { 1.0f, 0.0f, 0.0f, 1.0f };
    shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
    triangleBatch.Draw();
    
    glutSwapBuffers();
    
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y)
{
    GLfloat stepSize = 0.025f;
    
    GLfloat left = vVerts[0];
    GLfloat down = vVerts[1];
    GLfloat right = vVerts[3];
    GLfloat up = vVerts[7];
    
    switch (key) {
        case GLUT_KEY_LEFT:
            left = max(left - stepSize, -1.0f);
            right = left + 1.0f;
            break;
        case GLUT_KEY_DOWN:
            down = max(down - stepSize, -1.0f);
            up = down + 1.0f;
            break;
        case GLUT_KEY_RIGHT:
            right = min(right + stepSize, 1.0f);
            left = right - 1.0f;
            break;
        case GLUT_KEY_UP:
            up = min(up + stepSize, 1.0f);
            down = up - 1.0f;
            break;
        default:
            break;
    }
    
    vVerts[0] = left;
    vVerts[1] = down;
    vVerts[3] = right;
    vVerts[4] = down;
    vVerts[6] = (left + right) / 2;
    vVerts[7] = up;
    
    triangleBatch.CopyVertexData3f(vVerts);
    
//    glutPostRedisplay();
}

GLvoid PrintVersion()
{
    const GLubyte* name = glGetString(GL_VENDOR);            //返回负责当前OpenGL实现厂商的名字
    const GLubyte* biaoshifu = glGetString(GL_RENDERER);    //返回一个渲染器标识符，通常是个硬件平台
    const GLubyte* OpenGLVersion = glGetString(GL_VERSION);    //返回当前OpenGL实现的版本号
    const GLubyte* glsl = glGetString(GL_SHADING_LANGUAGE_VERSION);//返回着色预压编译器版本号
    const GLubyte* gluVersion = gluGetString(GLU_VERSION);    //返回当前GLU工具库版本
    printf("OpenGL实现厂商的名字：%s\n", name);
    printf("渲染器标识符：%s\n", biaoshifu);
    printf("OpenGL实现的版本号：%s\n", OpenGLVersion);
    printf("OpenGL着色语言版本：%s\n", glsl);
    printf("GLU工具库版本：%s\n", gluVersion);
}

int main(int argc, char* argv[])
{
    gltSetWorkingDirectory(argv[0]);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Triangle");
    glutReshapeFunc(changeSize);
    glutDisplayFunc(renderScene);
    glutSpecialFunc(specialKeys);
    
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        printf("GLEW Error\n");
        return 1;
    }
    
    setupRC();
    
    PrintVersion();
    
    glutMainLoop();
    return 0;
}
