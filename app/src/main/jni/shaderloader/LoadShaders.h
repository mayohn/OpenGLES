//
// Created by mayongheng on 2020/3/14.
//

#ifndef __LOAD_SHADERS_H__
#define __LOAD_SHADERS_H__

#include "GLES3/gl31.h"
#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus
#define LOG_TAG    "test===="
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG,__VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
typedef struct {
    GLenum type;
    const char *fileName;
    GLuint shader;
} ShaderInfo;

GLuint LoadShaders(ShaderInfo *);

#ifdef __cplusplus
};
#endif // __cplusplus

#endif // __LOAD_SHADERS_H__