#include <string>
#include "main.h"

JSTRING stringFromJNI(JNIEnv *env,jobject /* this */) {
    std::string hello = "Hello from jni";
    return env->NewStringUTF(hello.c_str());
}
