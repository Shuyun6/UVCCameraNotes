#include "_onload.h"
#include "utilbase.h"

#define LOCAL_DEBUG 0

//引用serenegiant_usb_UVCCamera.cpp中的函数
extern int register_uvccamera(JNIEnv *env);

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
#if LOCAL_DEBUG
    LOGD("JNI_OnLoad");
#endif

    JNIEnv *env;
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    // register native methods in UVCCamera.java
    int result = register_uvccamera(env);
	setVM(vm);
#if LOCAL_DEBUG
    LOGD("JNI_OnLoad:finshed:result=%d", result);
#endif
    return JNI_VERSION_1_6;
}
