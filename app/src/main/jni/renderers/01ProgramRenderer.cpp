//
// Created by mayongheng on 2020/3/16.
//

#include "JniRenderer.h"

static GLuint Buffers[1];

void Program01Renderer::onSurfaceCreated() {

}

void Program01Renderer::onSurfaceChanged(jint width, jint height) {
    glViewport(0, 0, width, height);
}

void Program01Renderer::onDrawFrame() {
    GLfloat vVertices[] = {0.0f, 0.5f, 0.0f,
                           -0.5f, -0.5f, 0.0f,
                           0.5f, -0.5f, 0.0f
    };



    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);
    const char *vertexGLSLName = "01triangles_vertex_shader.glsl";
    const char *fragmentGLSLName = "01triangles_fragment_shader.glsl";
    ShaderInfo shaders[] =
            {
                    {GL_VERTEX_SHADER,  vertexGLSLName},
                    {GL_FRAGMENT_SHADER, fragmentGLSLName},
                    {GL_NONE, NULL}
            };
    GLuint program = LoadShaders(shaders);
    // Use the program object
    glUseProgram(program);
    glClearColor ( 1.0f, 1.0f, 1.0f, 0.0f );
    // Load the vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
