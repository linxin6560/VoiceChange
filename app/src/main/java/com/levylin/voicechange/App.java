package com.levylin.voicechange;

import android.app.Application;

/**
 * Created by LinXin on 2017/8/28.
 */
public class App extends Application {

    static {
        try {
            System.loadLibrary("fmodD");
        } catch (UnsatisfiedLinkError e) {
        }
        try {
            System.loadLibrary("fmodL");
        } catch (UnsatisfiedLinkError e) {
        }
        try {
            System.loadLibrary("fmod");
        } catch (UnsatisfiedLinkError e) {
        }
        System.loadLibrary("effects");
        System.loadLibrary("effect_utils");
    }
}
