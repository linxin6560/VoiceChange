package com.levylin.voicechange;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.view.View;

import org.fmod.FMOD;

/**
 * 变声类
 * Created by LinXin on 2017/8/27.
 */
public class VoiceChangeActivity extends AppCompatActivity {

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.act_voice_change);
        FMOD.init(this);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        FMOD.close();
    }

    public void playNormal(View view) {
        playEffect(EffectUtils.MODE_NORMAL);
    }

    public void playLuoli(View view) {
        playEffect(EffectUtils.MODE_LUOLI);
    }


    public void playKongLing(View view) {
        playEffect(EffectUtils.MODE_KONGLING);
    }

    public void playGaoGuai(View view) {
        playEffect(EffectUtils.MODE_GAOGUAI);
    }

    public void playJingSong(View view) {
        playEffect(EffectUtils.MODE_JINGSONG);
    }

    public void playDashu(View view) {
        playEffect(EffectUtils.MODE_DASHU);
    }

    private void playEffect(final int type) {
        new Thread() {
            @Override
            public void run() {
                EffectUtils.fix("swish.wav", type);
            }
        }.start();
    }
}
