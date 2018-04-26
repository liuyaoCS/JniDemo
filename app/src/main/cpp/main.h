//
// Created by liuyao-s on 2018/4/8.
//

#ifndef JNIDEMO_NATIVE_LIB_H
#define JNIDEMO_NATIVE_LIB_H

#include <jni.h>
//#include <android/log.h>


#define initJNI  Java_com_example_jnidemo_JniUtils_initJNI

//#define TAG "ly-s"
//#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG, __VA_ARGS__)


extern "C" {
   void initJNI(JNIEnv *, jobject);
};


#endif //JNIDEMO_NATIVE_LIB_H
