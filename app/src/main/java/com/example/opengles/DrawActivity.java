package com.example.opengles;

import android.app.Activity;
import android.graphics.PixelFormat;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.widget.LinearLayout;

import androidx.annotation.Nullable;

import com.example.opengles.renderers.AirHockeyRenderer;
import com.example.opengles.renderers.JniAirHockeyRenderer;
import com.example.opengles.renderers.Program01Renderer;
import com.example.opengles.renderers.Program02Renderer;
import com.example.opengles.renderers.Program03Renderer;
import com.example.opengles.renderers.VertexArrayRenderer;

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
        setTranslucent(glSurfaceView);
        int i = getIntent().getIntExtra("Type", 0);
        switch (i) {
            case 0:
                renderer = new AirHockeyRenderer(DrawActivity.this);
                break;
            case 1:
                renderer = new JniAirHockeyRenderer(DrawActivity.this);
                break;
            case 2:
                renderer = new Program01Renderer(DrawActivity.this);
                break;
            case 3:
                renderer = new Program02Renderer(DrawActivity.this);
                break;
            case 4:
                renderer = new Program03Renderer(DrawActivity.this);
                break;
            case 5:
                renderer = new VertexArrayRenderer(DrawActivity.this);
                break;
        }
        glSurfaceView.setRenderer(renderer);
        rendererSet = true;
        layout.removeAllViews();
//        Display display = getWindowManager().getDefaultDisplay();
//        int width = display.getWidth();
//        int height = display.getHeight();
//        LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams((int) 768, (int) 480);
//        layoutParams.width = width / 2;
//        layoutParams.height = height / 2;
//        glSurfaceView.setLayoutParams(layoutParams);
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

    /**
     * 设置透明背景的方法
     * 这个方法需要在setRenderer之前调用才有效
     */
    private void setTranslucent(GLSurfaceView glSurfaceView) {
        glSurfaceView.setEGLConfigChooser(8, 8, 8, 8, 16, 0);
        glSurfaceView.getHolder().setFormat(PixelFormat.TRANSLUCENT);
        // 将GLSurfaceView置顶
        glSurfaceView.setZOrderOnTop(true);
    }
}
