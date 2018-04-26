#include "main.h"
#include "test/Test.h"

/**
 *
 * @param env
 * @param jobj can't pass class ref,must be object ref
 */
void callJavaLog(JNIEnv *env,jobject jobj){
//    jclass cls = env->FindClass("com/example/jnidemo/JniUtils");
    jclass cls = env->GetObjectClass(jobj);
    jmethodID mid = env->GetStaticMethodID( cls, "log", "()V");
    env->CallStaticVoidMethod(cls, mid);
}
void callJavaShow(JNIEnv *env,jobject jobj){
    jclass cls = env->GetObjectClass(jobj);
    jmethodID mid = env->GetMethodID( cls, "show", "(Ljava/lang/String;)Ljava/lang/String;");

    const char *name="ly";
    jstring jname=env->NewStringUTF(name);
    /*attention: jobj*/
    jstring jstr= (jstring) env->CallObjectMethod(jobj, mid, jname);
    const char* ret=env->GetStringUTFChars(jstr, JNI_FALSE);
    LOGI("%s",ret);
}
void getField(JNIEnv *env,jobject jobj){
    jclass cls = env->GetObjectClass(jobj);
    jfieldID jfid=env->GetStaticFieldID(cls,"TAG","Ljava/lang/String;");
    jstring  jtag = (jstring) env->GetStaticObjectField(cls, jfid);
    const char* tag=  env->GetStringUTFChars(jtag, JNI_FALSE);
    LOGI("tag is %s",tag);
}

void initJNI(JNIEnv *env,jobject instance) {

    callJavaLog(env,instance);
    callJavaShow(env,instance);
    getField(env,instance);

    //test
    test();
}


