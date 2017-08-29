package com.levylin.voicechange;

import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.view.View;

/**
 * 主界面
 * Created by LinXin on 2017/8/28.
 */
public class MActivity extends AppCompatActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.act_m_activity);
    }

    public void playSound(View view) {
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }

    public void playEffect(View view) {
        Intent intent = new Intent(this, VoiceChangeActivity.class);
        startActivity(intent);
    }
}
