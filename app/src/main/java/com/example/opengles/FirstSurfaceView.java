package com.example.opengles;

import android.content.Context;
import android.opengl.GLES10;
import android.opengl.GLSurfaceView;
import android.opengl.GLU;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import static android.opengl.GLES20.*;


public class FirstSurfaceView extends GLSurfaceView {
    private SceneRender sceneRender;

    public FirstSurfaceView(Context context) {
        super(context);
        sceneRender = new SceneRender();
        setEGLContextClientVersion(3);
        setRenderer(sceneRender);
        setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
    }

    public class SceneRender implements Renderer {

        @Override
        public void onSurfaceCreated(GL10 gl, EGLConfig config) {
            gl.glClearColor(0, 0, 0, 0);
            gl.glShadeModel(GL10.GL_FLOAT);
        }

        @Override
        public void onSurfaceChanged(GL10 gl, int width, int height) {
            gl.glViewport(0, 0, width, height);
            gl.glMatrixMode(GL10.GL_PROJECTION);
            gl.glLoadIdentity();
            gl.glFrustumf(-1.0f, 1.0f, 1.0f, 1.0f, 1.5f, 20.0f);
            gl.glMatrixMode(GL10.GL_PROJECTION);
        }

        @Override
        public void onDrawFrame(GL10 gl) {
            gl.glClear(GL_COLOR_BUFFER_BIT);
            gl.glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
            gl.glLoadIdentity();
            GLU.gluLookAt(gl, 0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
            gl.glScalef(1.0f, 2.0f, 1.0f);
//            gluWireCube(1.0f);
            gl.glFlush();
        }
    }
}
