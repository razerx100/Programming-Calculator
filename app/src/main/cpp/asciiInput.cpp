 #include <jni.h>
#include <string>
#include <helper.hpp>

 extern "C"
 JNIEXPORT jstring JNICALL
 Java_com_example_programmingcalculator_MainActivity_asciiToDecimal(JNIEnv *env, jobject thiz,
                                                                    jstring str) {
     jboolean isCopy;
     std::string data = std::string(env->GetStringUTFChars(str, &isCopy));
     if (data.empty() or is_number(data))
         return env->NewStringUTF("");
     else {
         std::string num = std::to_string(static_cast<int>(data[0]));
         return env->NewStringUTF(num.c_str());
     }
 }
