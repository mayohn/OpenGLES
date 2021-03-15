//
// Created by mayongheng on 2021/3/15.
//

#include "JniRenderer.h"

#define VERTEX_POS_SIZE 3
#define VERTEX_COLOR_SIZE 4
#define VERTEX_POS_INDEX 0
#define VERTEX_COLOR_INDEX 1
#define VERTEX_STRIDE (sizeof(GLfloat)*(VERTEX_POS_SIZE+VERTEX_COLOR_SIZE))

//指定存储生成的缓冲区对象名称的数组。
GLuint vboIds[2];
GLuint vaoId;
GLuint program;

void VertexArrayRenderer::onSurfaceCreated() {
    const char *vertexGLSLName = "04vertex.glsl";
    const char *fragmentGLSLName = "04fragment.glsl";
    ShaderInfo shaders[] =
            {
                    {GL_VERTEX_SHADER,   vertexGLSLName},
                    {GL_FRAGMENT_SHADER, fragmentGLSLName},
                    {GL_NONE, NULL}
            };
    program = LoadShaders(shaders);
    // Use the program object

    GLfloat vertices[3 * (VERTEX_POS_SIZE + VERTEX_COLOR_SIZE)] = {
            0.0f, 0.5f, 0.0f,
            1.0f, 0.0f, 0.0f, 1.0f,
            -0.5f, -0.5f, 0.0f,
            0.0f, 1.0f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.0f,
            0.0f, 0.0f, 1.0f, 1.0f,
    };
    GLushort indices[3] = {0, 1, 2};
    glGenBuffers(2, vboIds);
    if (vboIds == NULL)return;
    glBindBuffer(GL_ARRAY_BUFFER, vboIds[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIds[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &vaoId);
    glBindVertexArray(vaoId);
    glBindBuffer(GL_ARRAY_BUFFER, vboIds[0]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIds[1]);
    glEnableVertexAttribArray(VERTEX_POS_INDEX);
    glEnableVertexAttribArray(VERTEX_COLOR_INDEX);
    glVertexAttribPointer(VERTEX_POS_INDEX, VERTEX_POS_SIZE, GL_FLOAT, GL_FALSE, VERTEX_STRIDE,
                          (const void *) 0);
    glVertexAttribPointer(VERTEX_COLOR_INDEX, VERTEX_COLOR_SIZE, GL_FLOAT, GL_FALSE, VERTEX_STRIDE,
                          (const void *) (VERTEX_POS_SIZE * sizeof(GLfloat)));
    glBindVertexArray(0);
    glClearColor(0, 0, 0, 0);
}

void VertexArrayRenderer::onSurfaceChanged(jint width, jint height) {
    glViewport(0, 0, width, height);
}

void VertexArrayRenderer::onDrawFrame() {
    if (vaoId) {
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);
        glBindVertexArray(vaoId);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, 0);
        glBindVertexArray(0);
    }
}
