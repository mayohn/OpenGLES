package com.example.opengles.jni;


public class JniRenderer {
    static {
        System.loadLibrary("renderer");
    }

    public native void setGLSLPath(String path,String tag);

    public native void onSurfaceCreated();

    public native void onSurfaceChanged(int width, int height);

    public native void onDrawFrame();
}
