// Copyright (c) 2013 The Berkelium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// =========================================
// WARNING:
//   THIS FILE IS AUTOMATICALLY GENERATED!
//   !! ANY CHANGES WILL BE OVERWRITTEN !!
//
// See berkelium/berkelium-api/update.sh
// =========================================

#include "org_berkelium_impl_HostVersionImpl.h"
#include "org_berkelium_impl_BerkeliumFactoryImpl.h"
#include "org_berkelium_impl_RuntimeImpl.h"
#include "org_berkelium_impl_HostExecutableImpl.h"
#include "org_berkelium_impl_ProfileImpl.h"
#include "org_berkelium_impl_LoggerImpl.h"
#include "org_berkelium_impl_LogDelegateImpl.h"
#include "org_berkelium_impl_HostDelegateImpl.h"
#include "org_berkelium_impl_InstanceImpl.h"
#include "org_berkelium_impl_WindowImpl.h"
#include "org_berkelium_impl_WindowDelegateImpl.h"
#include "org_berkelium_impl_TabImpl.h"
#include "org_berkelium_impl_TabDelegateImpl.h"
#include "org_berkelium_impl_BerkeliumJavaImpl.h"

#include "berkelium.h"

#include <stdlib.h>
#include <string.h>

#include <sstream>

jclass IllegalArgumentException;

jclass BerkeliumJavaImpl;
jmethodID BerkeliumJavaImpl_mapIn;
jmethodID BerkeliumJavaImpl_mapOut;
jmethodID BerkeliumJavaImpl_mapNew;

jclass BK_Java_Classes[BK_Env_Enum_MAX];
jmethodID BK_Java_Class_ctors[BK_Env_Enum_MAX];
jfieldID BK_Java_Class_IDs[BK_Env_Enum_MAX];

const char* BK_Java_Class_Names[] = {
      "org/berkelium/impl/HostVersionImpl",
      "org/berkelium/impl/BerkeliumFactoryImpl",
      "org/berkelium/impl/RuntimeImpl",
      "org/berkelium/impl/HostExecutableImpl",
      "org/berkelium/impl/ProfileImpl",
      "org/berkelium/impl/LoggerImpl",
      "org/berkelium/impl/LogDelegateImpl",
      "org/berkelium/impl/HostDelegateImpl",
      "org/berkelium/impl/InstanceImpl",
      "org/berkelium/impl/WindowImpl",
      "org/berkelium/impl/WindowDelegateImpl",
      "org/berkelium/impl/TabImpl",
      "org/berkelium/impl/TabDelegateImpl",
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* jvm, void* reserved)
{
	JNIEnv* env;

	if(jvm->GetEnv((void**)&env, JNI_VERSION_1_1)) {
		return JNI_ERR;
	}

	jclass c = env->FindClass("org/berkelium/impl/BerkeliumJavaImpl");
	if(c == NULL) {
		return JNI_ERR;
	}
	c = (jclass)env->NewGlobalRef(c);
	jmethodID mi = env->GetStaticMethodID(c, "mapIn", "(ILorg/berkelium/impl/BerkeliumObjectImpl;)J");
	if(mi == NULL) {
		return JNI_ERR;
	}
	jmethodID mo = env->GetStaticMethodID(c, "mapOut", "(IJ)Lorg/berkelium/impl/BerkeliumObjectImpl;");
	if(mo == NULL) {
		return JNI_ERR;
	}
	jmethodID mn = env->GetStaticMethodID(c, "mapNew", "(IJJLorg/berkelium/impl/BerkeliumObjectImpl;)V");
	if(mn == NULL) {
		return JNI_ERR;
	}
	BerkeliumJavaImpl = c;
	BerkeliumJavaImpl_mapIn = mi;
	BerkeliumJavaImpl_mapOut = mo;
	BerkeliumJavaImpl_mapNew = mn;

	c = env->FindClass("java/lang/IllegalArgumentException");
	if(c == NULL) {
		return JNI_ERR;
	}
	IllegalArgumentException = c;

	for(int i = 0; i < BK_Env_Enum_MAX; i++) {
		c = env->FindClass(BK_Java_Class_Names[i]);
		if(c == NULL) {
			return JNI_ERR;
		}
		c = (jclass)env->NewGlobalRef(c);
		BK_Java_Classes[i] = c;
		jmethodID m = env->GetMethodID(c, "<init>", "()V");
		if(m == NULL) {
			return JNI_ERR;
		}
		BK_Java_Class_ctors[i] = m;
		jfieldID f = env->GetFieldID(c, "id", "I");
		if(f == NULL) {
			return JNI_ERR;
		}
		BK_Java_Class_IDs[i] = f;
	}

	return JNI_VERSION_1_1;
}

// =========================================
//
//	Berkelium to JNI #defines
//
// =========================================

#define BK_TO_JOBECT(X) (jobject)(X)
#define BK_TO_JBOOLEAN(X) ((X) ? JNI_TRUE : JNI_FALSE)

bk_bk_obj Berkelium_Java_MapIn(BK_Env_Enum type, bk_ext_obj bkJavaId, void* data)
{
	//fprintf(stderr, "Berkelium_Java_MapIn\n");
	JNIEnv* env = (JNIEnv*)data;
	bk_bk_obj ret((bk_bk_obj)env->CallStaticLongMethod(BerkeliumJavaImpl, BerkeliumJavaImpl_mapIn, type, bkJavaId));
	//fprintf(stderr, "MapIn: %p\n", ret);
	return ret;
}

bk_ext_obj Berkelium_Java_MapOut(BK_Env_Enum type, bk_bk_obj bkNativeId, void* data)
{
	//fprintf(stderr, "Berkelium_Java_MapOut\n");
	JNIEnv* env = (JNIEnv*)data;
	return env->CallStaticObjectMethod(BerkeliumJavaImpl, BerkeliumJavaImpl_mapOut, type, bkNativeId);
}

bk_ext_obj Berkelium_Java_MapNew(BK_Env_Enum type, bk_bk_obj bkNativeId, void* obj, void* data)
{
	//fprintf(stderr, "Berkelium_Java_MapNew\n");
	JNIEnv* env = (JNIEnv*)data;
	if(type < 0 || type >= BK_Env_Enum_MAX) {
		return NULL;
	}
	bk_ext_obj bkJavaId = env->NewObject(BK_Java_Classes[type], BK_Java_Class_ctors[type]);
	env->CallStaticVoidMethod(BerkeliumJavaImpl, BerkeliumJavaImpl_mapNew, type, bkNativeId, obj, bkJavaId);
	return bkJavaId;
}

void Berkelium_Java_MapInError(BK_Env_Enum expected, BK_Env_Enum actual, bk_ext_obj id, void* data)
{
	std::stringstream ss;

	ss << "Expected " << BK_Env_Enum_To_String_Or_Err(expected) << "(" << expected << ")";
	ss << " but got " << BK_Env_Enum_To_String_Or_Err(actual) << "(" << actual << ")";
	ss << " for id " << id;

	std::string str(ss.str());
	fprintf(stderr, "Berkelium_Java_MapInError %s\n", str.c_str());
	JNIEnv* env = (JNIEnv*)data;
	env->ThrowNew(IllegalArgumentException, str.c_str());
}

inline void setupBkEnv(BK_Env& bkenv, JNIEnv* env)
{
	bkenv.mapIn = Berkelium_Java_MapIn;
	bkenv.mapOut = Berkelium_Java_MapOut;
	bkenv.mapNew = Berkelium_Java_MapNew;
	bkenv.mapInError = Berkelium_Java_MapInError;
	bkenv.data = env;
}

inline jstring BK_TO_JSTRING(JNIEnv* env, char* str)
{
	if(str == NULL) {
		return NULL;
	}
	jstring ret = (jstring)env->NewGlobalRef(env->NewStringUTF(str));
	free(str);
	return ret;
}

inline char* JSTRING_TO_BK(JNIEnv* env, jstring str)
{
	if(str == NULL) {
		return NULL;
	}
	jboolean iscopy = false;
	const char* tmp = env->GetStringUTFChars(str, &iscopy);
	jint len = env->GetStringUTFLength(str);
	char* ret = (char*)malloc(len);
	memcpy(ret, tmp, len);
	env->ReleaseStringUTFChars(str, tmp);
	return ret;
}

inline BK_LogSource LogSource_TO_BK(JNIEnv* env, jobject instance)
{
	jclass cls = env->FindClass("org/berkelium/api/LogSource");

	jmethodID ordinal(env->GetMethodID(cls, "ordinal", "()I"));
	return (BK_LogSource)env->CallIntMethod(instance, ordinal);
}

inline BK_LogType LogType_TO_BK(JNIEnv* env, jobject instance)
{
	jclass cls = env->FindClass("org/berkelium/api/LogType");

	jmethodID ordinal(env->GetMethodID(cls, "ordinal", "()I"));
	return (BK_LogType)env->CallIntMethod(instance, ordinal);
}

// =========================================
//
//	BerkeliumFactory
//
// =========================================

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_BerkeliumFactoryImpl_createRuntime(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_BerkeliumFactory_createRuntime(&bkenv));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_BerkeliumFactoryImpl_getDefaultRuntime(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_BerkeliumFactory_getDefaultRuntime(&bkenv));
}

// =========================================
//
//	HostExecutable
//
// =========================================

JNIEXPORT jstring JNICALL Java_org_berkelium_impl_HostExecutableImpl_getPath(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JSTRING(env, BK_HostExecutable_getPath(&bkenv, (BK_HostExecutable)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_HostExecutableImpl_getRuntime(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_HostExecutable_getRuntime(&bkenv, (BK_HostExecutable)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_HostExecutableImpl_getVersion(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_HostExecutable_getVersion(&bkenv, (BK_HostExecutable)_this));
}

// =========================================
//
//	HostVersion
//
// =========================================

JNIEXPORT jint JNICALL Java_org_berkelium_impl_HostVersionImpl_getBuild(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_HostVersion_getBuild(&bkenv, (BK_HostVersion)_this);
}

JNIEXPORT jint JNICALL Java_org_berkelium_impl_HostVersionImpl_getMajor(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_HostVersion_getMajor(&bkenv, (BK_HostVersion)_this);
}

JNIEXPORT jint JNICALL Java_org_berkelium_impl_HostVersionImpl_getMinor(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_HostVersion_getMinor(&bkenv, (BK_HostVersion)_this);
}

JNIEXPORT jint JNICALL Java_org_berkelium_impl_HostVersionImpl_getPatch(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_HostVersion_getPatch(&bkenv, (BK_HostVersion)_this);
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_HostVersionImpl_getRuntime(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_HostVersion_getRuntime(&bkenv, (BK_HostVersion)_this));
}

JNIEXPORT jstring JNICALL Java_org_berkelium_impl_HostVersionImpl_getVersionString(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JSTRING(env, BK_HostVersion_getVersionString(&bkenv, (BK_HostVersion)_this));
}

JNIEXPORT jboolean JNICALL Java_org_berkelium_impl_HostVersionImpl_isMinVersion(JNIEnv* env, jobject _this, jstring version)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JBOOLEAN(BK_HostVersion_isMinVersion(&bkenv, (BK_HostVersion)_this, JSTRING_TO_BK(env, version)));
}

// =========================================
//
//	Instance
//
// =========================================

JNIEXPORT void JNICALL Java_org_berkelium_impl_InstanceImpl_addHostDelegate(JNIEnv* env, jobject _this, jobject delegate)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Instance_addHostDelegate(&bkenv, (BK_Instance)_this, (BK_HostDelegate)delegate);
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_InstanceImpl_close(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Instance_close(&bkenv, (BK_Instance)_this);
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_InstanceImpl_createWindow(JNIEnv* env, jobject _this, jboolean incognito)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Instance_createWindow(&bkenv, (BK_Instance)_this, incognito));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_InstanceImpl_getExecutable(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Instance_getExecutable(&bkenv, (BK_Instance)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_InstanceImpl_getProfile(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Instance_getProfile(&bkenv, (BK_Instance)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_InstanceImpl_getRuntime(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Instance_getRuntime(&bkenv, (BK_Instance)_this));
}

JNIEXPORT jint JNICALL Java_org_berkelium_impl_InstanceImpl_getWindowCount(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_Instance_getWindowCount(&bkenv, (BK_Instance)_this);
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_InstanceImpl_getWindowList(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Instance_getWindowList(&bkenv, (BK_Instance)_this));
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_InstanceImpl_internalUpdate(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Instance_internalUpdate(&bkenv, (BK_Instance)_this);
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_InstanceImpl_removeHostDelegate(JNIEnv* env, jobject _this, jobject delegate)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Instance_removeHostDelegate(&bkenv, (BK_Instance)_this, (BK_HostDelegate)delegate);
}

// =========================================
//
//	Profile
//
// =========================================

JNIEXPORT jstring JNICALL Java_org_berkelium_impl_ProfileImpl_getApplicationName(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JSTRING(env, BK_Profile_getApplicationName(&bkenv, (BK_Profile)_this));
}

JNIEXPORT jstring JNICALL Java_org_berkelium_impl_ProfileImpl_getProfilePath(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JSTRING(env, BK_Profile_getProfilePath(&bkenv, (BK_Profile)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_ProfileImpl_getRuntime(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Profile_getRuntime(&bkenv, (BK_Profile)_this));
}

JNIEXPORT jboolean JNICALL Java_org_berkelium_impl_ProfileImpl_isFound(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JBOOLEAN(BK_Profile_isFound(&bkenv, (BK_Profile)_this));
}

JNIEXPORT jboolean JNICALL Java_org_berkelium_impl_ProfileImpl_isInUse(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JBOOLEAN(BK_Profile_isInUse(&bkenv, (BK_Profile)_this));
}

JNIEXPORT jboolean JNICALL Java_org_berkelium_impl_ProfileImpl_isLocked(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JBOOLEAN(BK_Profile_isLocked(&bkenv, (BK_Profile)_this));
}

JNIEXPORT jboolean JNICALL Java_org_berkelium_impl_ProfileImpl_isSameVersion(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JBOOLEAN(BK_Profile_isSameVersion(&bkenv, (BK_Profile)_this));
}

JNIEXPORT jboolean JNICALL Java_org_berkelium_impl_ProfileImpl_isTooNew(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JBOOLEAN(BK_Profile_isTooNew(&bkenv, (BK_Profile)_this));
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_ProfileImpl_setLocked(JNIEnv* env, jobject _this, jboolean locked)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Profile_setLocked(&bkenv, (BK_Profile)_this, locked);
}

// =========================================
//
//	Runtime
//
// =========================================

JNIEXPORT void JNICALL Java_org_berkelium_impl_RuntimeImpl_addLogDelegate(JNIEnv* env, jobject _this, jobject delegate)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Runtime_addLogDelegate(&bkenv, (BK_Runtime)_this, (BK_LogDelegate)delegate);
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_RuntimeImpl_createTemporaryProfile(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Runtime_createTemporaryProfile(&bkenv, (BK_Runtime)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_RuntimeImpl_forExecutable(JNIEnv* env, jobject _this, jstring pathTo)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Runtime_forExecutable(&bkenv, (BK_Runtime)_this, JSTRING_TO_BK(env, pathTo)));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_RuntimeImpl_forProfile(JNIEnv* env, jobject _this, jstring application)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Runtime_forProfile(&bkenv, (BK_Runtime)_this, JSTRING_TO_BK(env, application)));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_RuntimeImpl_forProfilePath(JNIEnv* env, jobject _this, jstring path)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Runtime_forProfilePath(&bkenv, (BK_Runtime)_this, JSTRING_TO_BK(env, path)));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_RuntimeImpl_forSystemInstalled(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Runtime_forSystemInstalled(&bkenv, (BK_Runtime)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_RuntimeImpl_forVersion__Ljava_lang_String_2(JNIEnv* env, jobject _this, jstring version)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Runtime_forVersionS(&bkenv, (BK_Runtime)_this, JSTRING_TO_BK(env, version)));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_RuntimeImpl_forVersion__IIII(JNIEnv* env, jobject _this, jint vMajor, jint vMinor, jint vBuild, jint vPatch)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Runtime_forVersion4I(&bkenv, (BK_Runtime)_this, vMajor, vMinor, vBuild, vPatch));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_RuntimeImpl_getChromeProfile(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Runtime_getChromeProfile(&bkenv, (BK_Runtime)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_RuntimeImpl_getChromiumProfile(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Runtime_getChromiumProfile(&bkenv, (BK_Runtime)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_RuntimeImpl_getLogger(JNIEnv* env, jobject _this, jstring clazz, jstring name)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Runtime_getLogger(&bkenv, (BK_Runtime)_this, JSTRING_TO_BK(env, clazz), JSTRING_TO_BK(env, name)));
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_RuntimeImpl_log(JNIEnv* env, jobject _this, jobject source, jobject type, jstring clazz, jstring name, jstring message)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Runtime_log(&bkenv, (BK_Runtime)_this, LogSource_TO_BK(env, source), LogType_TO_BK(env, type), JSTRING_TO_BK(env, clazz), JSTRING_TO_BK(env, name), JSTRING_TO_BK(env, message));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_RuntimeImpl_open(JNIEnv* env, jobject _this, jobject executable, jobject profile)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Runtime_open(&bkenv, (BK_Runtime)_this, (BK_HostExecutable)executable, (BK_Profile)profile));
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_RuntimeImpl_removeLogDelegate(JNIEnv* env, jobject _this, jobject delegate)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Runtime_removeLogDelegate(&bkenv, (BK_Runtime)_this, (BK_LogDelegate)delegate);
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_RuntimeImpl_setDefaultExecutable(JNIEnv* env, jobject _this, jstring pathTo)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Runtime_setDefaultExecutable(&bkenv, (BK_Runtime)_this, JSTRING_TO_BK(env, pathTo));
}

// =========================================
//
//	Tab
//
// =========================================

JNIEXPORT void JNICALL Java_org_berkelium_impl_TabImpl_addTabDelegate(JNIEnv* env, jobject _this, jobject delegate)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Tab_addTabDelegate(&bkenv, (BK_Tab)_this, (BK_TabDelegate)delegate);
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_TabImpl_close(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Tab_close(&bkenv, (BK_Tab)_this);
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_TabImpl_getRuntime(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Tab_getRuntime(&bkenv, (BK_Tab)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_TabImpl_getTabDelegate(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Tab_getTabDelegate(&bkenv, (BK_Tab)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_TabImpl_getWindow(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Tab_getWindow(&bkenv, (BK_Tab)_this));
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_TabImpl_internalUpdate(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Tab_internalUpdate(&bkenv, (BK_Tab)_this);
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_TabImpl_navigateTo(JNIEnv* env, jobject _this, jstring url)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Tab_navigateTo(&bkenv, (BK_Tab)_this, JSTRING_TO_BK(env, url));
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_TabImpl_removeTabDelegate(JNIEnv* env, jobject _this, jobject delegate)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Tab_removeTabDelegate(&bkenv, (BK_Tab)_this, (BK_TabDelegate)delegate);
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_TabImpl_resize(JNIEnv* env, jobject _this, jint width, jint height)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Tab_resize(&bkenv, (BK_Tab)_this, width, height);
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_TabImpl_sync(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Tab_sync(&bkenv, (BK_Tab)_this);
}

// =========================================
//
//	Window
//
// =========================================

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_WindowImpl_createTab(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Window_createTab(&bkenv, (BK_Window)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_WindowImpl_getInstance(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Window_getInstance(&bkenv, (BK_Window)_this));
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_WindowImpl_getRuntime(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Window_getRuntime(&bkenv, (BK_Window)_this));
}

JNIEXPORT jint JNICALL Java_org_berkelium_impl_WindowImpl_getTabCount(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_Window_getTabCount(&bkenv, (BK_Window)_this);
}

JNIEXPORT jobject JNICALL Java_org_berkelium_impl_WindowImpl_getTabList(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JOBECT(BK_Window_getTabList(&bkenv, (BK_Window)_this));
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_WindowImpl_internalUpdate(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Window_internalUpdate(&bkenv, (BK_Window)_this);
}

JNIEXPORT jboolean JNICALL Java_org_berkelium_impl_WindowImpl_isIncognito(JNIEnv* env, jobject _this)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	return BK_TO_JBOOLEAN(BK_Window_isIncognito(&bkenv, (BK_Window)_this));
}

JNIEXPORT void JNICALL Java_org_berkelium_impl_WindowImpl_moveTo(JNIEnv* env, jobject _this, jobject tab, jint index)
{
	BK_Env bkenv;
	setupBkEnv(bkenv, env);
	BK_Window_moveTo(&bkenv, (BK_Window)_this, (BK_Tab)tab, index);
}

