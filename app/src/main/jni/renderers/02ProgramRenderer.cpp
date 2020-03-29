
#include "JniRenderer.h"


void Program02Renderer::onSurfaceCreated() {
    char *vertexGLSLName = "02program_vertex_shader.glsl";
    char *fragmentGLSLName = "02program_fragment_shader.glsl";
    ShaderInfo shaders[] =
            {
                    {GL_VERTEX_SHADER,   vertexGLSLName},
                    {GL_FRAGMENT_SHADER, fragmentGLSLName},
                    {GL_NONE, NULL}
            };
    GLuint program = LoadShaders(shaders);
    glUseProgram(program);
    GLint numUniforms;
    GLint maxUniformLenght;
    char *uniformName;
    GLint index;
    glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &numUniforms);
    LOGI("统一变量数量%d", numUniforms);
    glGetProgramiv(program, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxUniformLenght);
    LOGI("统一变量名称字符的最大数量%d", maxUniformLenght);

    uniformName = static_cast<char *>(malloc(sizeof(char) * maxUniformLenght));
    for (index = 0; index < numUniforms; index++) {
        GLint size;
        GLenum type;
        GLint location;
        glGetActiveUniform(program, index, maxUniformLenght, NULL, &size, &type, uniformName);
        LOGI("统一变量size=%d，name=%s", size, uniformName);
        location = glGetUniformLocation(program, uniformName);
        LOGI("统一变量location=%d", location);
        switch (type) {
            case GL_FLOAT:
                LOGI("统一变量type=GL_FLOAT");
                break;
            case GL_FLOAT_VEC2:
                LOGI("统一变量type=GL_FLOAT_VEC2");
                break;
            case GL_FLOAT_VEC4:
                LOGI("统一变量type=GL_FLOAT_VEC4");
                break;
        }
    }
}

void Program02Renderer::onSurfaceChanged(jint width, jint height) {
    glViewport(0, 0, width, height);
}

void Program02Renderer::onDrawFrame() {
}
