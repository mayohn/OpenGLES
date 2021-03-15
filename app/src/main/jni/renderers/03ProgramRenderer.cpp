//
// Created by mayongheng on 2020/3/22.
//


#include "JniRenderer.h"


void Program03Renderer::onSurfaceCreated() {
    const char *vertexGLSLName = "03program_vertex_shader.glsl";
    const char *fragmentGLSLName = "03program_fragment_shader.glsl";
    ShaderInfo shaders[] =
            {
                    {GL_VERTEX_SHADER,   vertexGLSLName},
                    {GL_FRAGMENT_SHADER, fragmentGLSLName},
                    {GL_NONE, NULL}
            };
    GLint program = LoadShaders(shaders);
    glUseProgram(program);
}

void Program03Renderer::onSurfaceChanged(jint width, jint height) {
    glViewport(0, 0, width, height);
}

void Program03Renderer::onDrawFrame() {
    GLint maxVertexAttribs;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &maxVertexAttribs);
    LOGI("支持最大顶点数量%d",maxVertexAttribs);
}
