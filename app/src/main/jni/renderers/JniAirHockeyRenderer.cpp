//
// Created by mayongheng on 2020/3/15.
//
#include "JniRenderer.h"

enum VAO_IDs {
    Triangles, NumVAOs
};
enum Buffer_IDs {
    ArrayBuffer, NumBuffers
};
enum Attrib_IDs {
    vPosition = 0,
    uColor = 0
};
char *mGLSLPath;
GLuint LoadShaders(ShaderInfo *);

static GLuint VAOs[NumVAOs];
static GLuint Buffers[NumBuffers];
const GLuint NumVertices = 6;

void JniAirHockeyRenderer::onSurfaceCreated() {
    LOGI("onSurfaceCreated");
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    GLfloat vertiecs[20] = {
            //三角形
            -0.5f, -0.5f,
            0.5f, 0.5f,
            -0.5f, 0.5f,
            //三角形
            -0.5f, -0.5f,
            0.5f, -0.5f,
            0.5f, 0.5f,
            //中间线
            -0.5f, 0.0f,
            0.5f, 0.0f,
            //两点
            0.0f, -0.25f,
            0.0f, 0.25f

    };
    //copy vertices from cpu to the gpu
    glGenBuffers(1, Buffers);
//绑定生成的 vertexBufferId 到 GL_ARRAY_BUFFER 上面去, target
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
//绑定 FloatBuffer 数据,
//第一个参数, buffer 的类型(目标)
//第二个参数是数据的长度, 这个地方的长度直接是 triangleBuffer 的长度, 这个  float 是4字节的, 所以可以直接使用数组的长度 * 4 得到
//第三个参数是 buffer 数据(坐标数据)
//第四个参数指定了 用法 , 是静态的画布上面
    // LOGI("user info----name:size:%d", sizeof(vertiecs));
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertiecs), vertiecs, GL_STATIC_DRAW);
    char *vertexGLSLName = "simple_vertex_shader.glsl";
    char *fragmentGLSLName = "simple_fragment_shader.glsl";
    ShaderInfo shaders[] =
            {
                    {GL_VERTEX_SHADER,   vertexGLSLName},
                    {GL_FRAGMENT_SHADER, fragmentGLSLName},
                    {GL_NONE, NULL}
            };
    GLuint program = LoadShaders(shaders);
    glUseProgram(program);

    glVertexAttribPointer(vPosition, 2, GL_FLOAT,
                          GL_FALSE, 0, (GLvoid *) 0);
    glEnableVertexAttribArray(vPosition);
}

void JniAirHockeyRenderer::onSurfaceChanged(jint width, jint height) {
    LOGI("onSurfaceChanged");
    glViewport(0, 0, width, height);
}

void JniAirHockeyRenderer::onDrawFrame() {
    LOGI("onDrawFrame");
    glClear(GL_COLOR_BUFFER_BIT);
    glUniform4f(uColor, 1.0f, 1.0f, 1.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glUniform4f(uColor, 1.0f, 0.0f, 0.0f, 1.0f);
    glDrawArrays(GL_LINES, 6, 2);

    glUniform4f(uColor, 0.0f, 0.0f, 1.0f, 1.0f);
    glDrawArrays(GL_POINTS, 8, 1);

    glUniform4f(uColor, 1.0f, 0.0f, 0.0f, 1.0f);
    glDrawArrays(GL_POINTS, 9, 1);
}

