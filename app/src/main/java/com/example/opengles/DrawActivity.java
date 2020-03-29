package com.example.opengles;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.widget.LinearLayout;

import androidx.annotation.Nullable;

import com.example.opengles.renderers.AirHockeyRenderer;
import com.example.opengles.renderers.JniAirHockeyRenderer;
import com.example.opengles.renderers.Program01Renderer;
import com.example.opengles.renderers.Program02Renderer;
import com.example.opengles.renderers.Program03Renderer;

public class DrawActivity extends Activity {
    private LinearLayout layout;
    private GLSurfaceView glSurfaceView;
    private GLSurfaceView.Renderer renderer;
    private boolean rendererSet;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_draw);
        layout = findViewById(R.id.layout);
        glSurfaceView = new GLSurfaceView(this);
        glSurfaceView.setEGLContextClientVersion(3);
        int i = getIntent().getIntExtra("Type", 0);
        switch (i) {
            case 0:
                renderer = new AirHockeyRenderer(DrawActivity.this);
                break;
            case 1:
                renderer = new JniAirHockeyRenderer(DrawActivity.this);
                break;
            case 2:
                renderer=new Program01Renderer(DrawActivity.this);
                break;
            case 3:
                renderer=new Program02Renderer(DrawActivity.this);
                break;
            case 4:
                renderer=new Program03Renderer(DrawActivity.this);
                break;
        }
        glSurfaceView.setRenderer(renderer);
        rendererSet = true;
        layout.removeAllViews();
        layout.addView(glSurfaceView);
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (rendererSet) {
            glSurfaceView.onResume();
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        if (rendererSet) {
            glSurfaceView.onPause();
        }
    }
}
