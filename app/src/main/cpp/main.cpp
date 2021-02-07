#include <jni.h>
#include <string>

bool is_number(const std::string& str){
    return !str.empty() and std::find_if(str.begin(), str.end(), [](char c){return !std::isdigit(c);}) == str.end();
}

bool is_zero(const std::string& str){
    return std::find_if(str.begin(), str.end(), [](char c){return c != '0';}) == str.end();
}

void formatBinary(std::string& str){
    for(int i = str.length() - 4; i > 0; i -= 4)
        str.insert(i, " ");
}

void formatDecimal(std::string& str){
    for(int i = str.length() - 3; i > 0; i -= 3)
        str.insert(i, " ");
}

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
