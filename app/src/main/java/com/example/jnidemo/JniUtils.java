package com.example.jnidemo;

import android.util.Log;

/**
 * Created by liuyao-s on 2018/4/8.
 */

public class JniUtils {
    private static final String TAG = "ly-s";
    static {
        System.loadLibrary("jni_demo");
    }

    public  native void initJNI();

    private static void log(){
        Log.i(TAG,"hi,i am java log");
    }
    private String show(String name){
        return "hi,"+name+" am java show";
    }
}
