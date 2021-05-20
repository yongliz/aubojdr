#ifndef UTIL_H
#define UTIL_H

#include <jni.h>
#include <string.h>

#include <iostream>

namespace aubojdr {
/**
 * @brief char* to jstring
 * @param rshd
 * @return jstring
 */
jstring str2jstring(JNIEnv* env, const char* pat);

/**
 * @brief jstring to std::string
 * @param rshd
 * @return std::string
 */
std::string jstring2str(JNIEnv* env, jstring jstr);

}  // namespace aubojdr
#endif