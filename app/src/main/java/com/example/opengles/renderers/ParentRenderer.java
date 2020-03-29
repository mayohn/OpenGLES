package com.example.opengles.renderers;

import android.content.Context;
import android.opengl.GLSurfaceView;

import com.example.opengles.jni.JniRenderer;

import java.io.File;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class ParentRenderer implements GLSurfaceView.Renderer {
    protected String name = "ParentRenderer";
    private static final String SEPARATOR = File.separator;//路径分隔符
    protected JniRenderer jniRenderer;
    protected String mGLSLPath;

    public ParentRenderer(Context context, String name) {
        this.name = name;
        mGLSLPath = context.getApplicationContext().getExternalFilesDir(null).getAbsolutePath() + SEPARATOR + "glsl" + SEPARATOR;
        jniRenderer = new JniRenderer();
        jniRenderer.setGLSLPath(mGLSLPath, name);
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        jniRenderer.onSurfaceCreated();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        jniRenderer.onSurfaceChanged(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        jniRenderer.onDrawFrame();
    }
}
