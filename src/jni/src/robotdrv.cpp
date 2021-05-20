#include <string.h>

#include <iostream>

#include "com_aubo_aubojdr_RobotDrv.h"
#include "internal/util.h"
#include "rsdef.h"

#define ARM_DOF 6

// namespace aubojdr {

JNIEXPORT jint JNICALL Java_com_aubo_aubojdr_RobotDrv_initialize(JNIEnv *env,
                                                                 jobject jc) {
  return (jint)rs_initialize();
}

JNIEXPORT jint JNICALL Java_com_aubo_aubojdr_RobotDrv_uninitialize(JNIEnv *env,
                                                                   jobject jc) {
  return (jint)rs_uninitialize();
}

JNIEXPORT jint JNICALL
Java_com_aubo_aubojdr_RobotDrv_createContext(JNIEnv *env, jobject jc) {
  RSHD rshd = -1;
  return (jint)rs_create_context(&rshd);
}

JNIEXPORT jint JNICALL Java_com_aubo_aubojdr_RobotDrv_destoryContext(
    JNIEnv *env, jobject jc, jint rshd) {
  return (jint)rs_destory_context(rshd);
}

JNIEXPORT jint JNICALL Java_com_aubo_aubojdr_RobotDrv_login(
    JNIEnv *env, jobject jc, jint rshd, jstring ip, jint port) {
  return (jint)rs_login((RSHD)rshd, aubojdr::jstring2str(env, ip).c_str(),
                        static_cast<int>(port));
}

JNIEXPORT jint JNICALL Java_com_aubo_aubojdr_RobotDrv_logout(JNIEnv *env,
                                                             jobject jc,
                                                             jint rshd) {
  return (jint)rs_logout((RSHD)rshd);
}

JNIEXPORT jint JNICALL Java_com_aubo_aubojdr_RobotDrv_moveJ(
    JNIEnv *env, jobject jc, jint rshd, jdoubleArray waypoint) {
  double joint_radian[ARM_DOF] = {0};

  jsize len = env->GetArrayLength(waypoint);
  jboolean isCopy;
  jdouble *body = env->GetDoubleArrayElements(waypoint, &isCopy);

  for (int i = 0; i < len && i < ARM_DOF; i++) {
    joint_radian[i] = body[i];
  }

  // Release the pointer to the jdoubleArray
  if (isCopy == JNI_TRUE) {
    env->ReleaseDoubleArrayElements(waypoint, body, JNI_ABORT);
  }

  return (jint)rs_move_joint((RSHD)rshd, joint_radian);
}

JNIEXPORT jint JNICALL Java_com_aubo_aubojdr_RobotDrv_moveL(
    JNIEnv *env, jobject jc, jint rshd, jdoubleArray waypoint) {
  double joint_radian[ARM_DOF] = {0};

  jsize len = env->GetArrayLength(waypoint);
  jboolean isCopy;
  jdouble *body = env->GetDoubleArrayElements(waypoint, &isCopy);

  for (int i = 0; i < len && i < ARM_DOF; i++) {
    joint_radian[i] = body[i];
  }

  // Release the pointer to the jdoubleArray
  if (isCopy == JNI_TRUE) {
    env->ReleaseDoubleArrayElements(waypoint, body, JNI_ABORT);
  }

  return (jint)rs_move_line((RSHD)rshd, joint_radian);
}

//}  // namespace aubojdr