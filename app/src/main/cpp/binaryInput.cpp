 #include <jni.h>
#include <string>
#include <helper.hpp>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_programmingcalculator_MainActivity_binaryToDecimal(JNIEnv *env, jobject thiz,
                                                                    jstring str) {
    jboolean isCopy;
    std::string data = std::string(env->GetStringUTFChars(str, &isCopy));
    if (!is_number(data))
        return env->NewStringUTF("");
    else {
        std::string dec;
        unsigned int num = 0;
        if(is_zero(data))
            dec = data;
        else{
            int index = 0, size = data.length();
            while (index < size - 1){
                if(data[index] == '1')
                    num = num | 1U;
                num = num << 1U;
                index++;
            }
            if(data[index] == '1')
                num = num | 1U;
            dec = std::to_string(num);
        }
        formatDecimal(dec);
        return env->NewStringUTF(dec.c_str());
    }
}
