package com.example.jnidemo;

/**
 * Created by liuyao-s on 2018/4/8.
 */

public class JniUtils {
    static {
        System.loadLibrary("native-lib");
    }
    public static native String stringFromJNI();
}
