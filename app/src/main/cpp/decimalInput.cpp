 #include <jni.h>
#include <string>
#include <helper.hpp>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_programmingcalculator_MainActivity_decimalToBinary(JNIEnv *env, jobject thiz,
                                                                    jstring str) {
    jboolean isCopy;
    std::string data = std::string(env->GetStringUTFChars(str, &isCopy));
    if (!is_number(data))
        return env->NewStringUTF("");
    else {
        unsigned int value = std::stoul(data);
        std::string bin;
        if(is_zero(data))
            bin = data;
        else{
            while (value > 0){
                if(value & 1U)
                    bin.insert(0,"1");
                else
                    bin.insert(0,"0");
                value = value >> 1U;
            }
        }
        formatBinary(bin);
        return env->NewStringUTF(bin.c_str());
    }
}
