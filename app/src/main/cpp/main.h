//
// Created by liuyao-s on 2018/4/8.
//

#ifndef JNIDEMO_NATIVE_LIB_H
#define JNIDEMO_NATIVE_LIB_H

#include <jni.h>

#define JSTRING JNIEXPORT jstring JNICALL
#define stringFromJNI  Java_com_example_jnidemo_JniUtils_stringFromJNI

extern "C" {
   JSTRING stringFromJNI(JNIEnv *, jobject);
};


#endif //JNIDEMO_NATIVE_LIB_H
