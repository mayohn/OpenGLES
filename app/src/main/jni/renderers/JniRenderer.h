//
// Created by mayongheng on 2020/3/15.
//

#ifndef OPENGLES_JNIRENDERER_H
#define OPENGLES_JNIRENDERER_H

#include <jni.h>
#include <string.h>
#include <stdlib.h>
#include <GLES3/gl31.h>
#include <GLES3/gl3ext.h>
#include "../shaderloader/LoadShaders.h"

#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

extern char *mGLSLPath;
class Renderder {
public:
    virtual void onSurfaceCreated() {}

    virtual void onSurfaceChanged(jint width, jint height) {}

    virtual void onDrawFrame() {}
};

class JniAirHockeyRenderer : public Renderder {
public:

    void onSurfaceCreated();

    void onSurfaceChanged(jint width, jint height);

    void onDrawFrame();
};
class Program01Renderer : public Renderder {
public:
    void onSurfaceCreated();

    void onSurfaceChanged(jint width, jint height);

    void onDrawFrame();
};
class Program02Renderer : public Renderder {
public:
    void onSurfaceCreated();

    void onSurfaceChanged(jint width, jint height);

    void onDrawFrame();
};
class Program03Renderer : public Renderder {
public:
    void onSurfaceCreated();

    void onSurfaceChanged(jint width, jint height);

    void onDrawFrame();
};
class VertexArrayRenderer : public Renderder {
public:
    void onSurfaceCreated();

    void onSurfaceChanged(jint width, jint height);

    void onDrawFrame();
};
#ifdef __cplusplus
}
#endif
#endif //OPENGLES_JNIRENDERER_H
