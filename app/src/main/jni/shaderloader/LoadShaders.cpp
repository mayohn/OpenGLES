#include <stdio.h>
#include "LoadShaders.h"
#include "../renderers/JniRenderer.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
static const GLchar *ReaderShader(const char *fileName) {
    char *glslPath = (char *) malloc(strlen(mGLSLPath) + strlen(fileName));
    strcpy(glslPath, mGLSLPath);
    strcat(glslPath, fileName);
    LOGI("文件地址=%s", glslPath);
    FILE *inflie = fopen(glslPath, "rb");
    if (!inflie) {
        LOGI("文件打开失败%s", fileName);
        return NULL;
    }
    fseek(inflie, 0, SEEK_END);
    int len = ftell(inflie);
    fseek(inflie, 0, SEEK_SET);
    GLchar *source = new GLchar[len + 1];
    fread(source, 1, len, inflie);
    fclose(inflie);
    source[len] = 0;
    return const_cast<const GLchar *>(source);

}

GLuint LoadShaders(ShaderInfo *shaders) {
    LOGI("load glsl....");
    if (shaders == NULL)return 0;
    GLuint program = glCreateProgram();
    ShaderInfo *entry = shaders;
    while (entry->type != GL_NONE) {
        GLuint shader = glCreateShader(entry->type);
        entry->shader = shader;
        const GLchar *source = ReaderShader(entry->fileName);
        if (source == NULL) {
            for (entry = shaders; entry->type != GL_NONE; ++entry) {
                glDeleteShader(entry->shader);
                entry->shader = 0;
                LOGI("shader source is null");
            }
            return 0;
        } else {
            LOGI("shader load success");
        }
        glShaderSource(shader, 1, &source, NULL);
        delete[]source;
        glCompileShader(shader);
        GLint compiled;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            GLchar log[1000];
            glGetShaderInfoLog(shader, 1000, NULL, log);
            LOGI("shader compliied failed%s",log);
            return 0;
        } else {
            LOGI("shader compliied success");
        }
        glAttachShader(program, shader);
        ++entry;
    }
    glLinkProgram(program);
    GLint linked;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (!linked) {
        LOGI("linked source failed");
        return 0;
    } else {
        LOGI("shader link success");
    }
    return program;
}
#ifdef __cplusplus
}
#endif // __cplusplus