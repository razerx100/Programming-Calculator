#include <jni.h>
#include <string>
#include <calculator.hpp>

static int inputBinary = 2131230910, inputDecimal = 2131230912;
static int inputAscii = 2131230909, inputBit = 2131230911;
static int inputHex = 2131230913;

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_programmingcalculator_MainActivity_binaryButtonFunction(JNIEnv *env, jobject thiz,
                                                                         jstring str, jint inputId) {
    jboolean isCopy;
    std::string data = std::string(env->GetStringUTFChars(str, &isCopy));

    if(inputId == inputDecimal)
        return env->NewStringUTF(decimalToBinary(data).c_str());
    else if(inputId == inputHex)
        return env->NewStringUTF(hexToBinary(data).c_str());
    else if(inputId == inputBinary)
        return env->NewStringUTF(binaryToBinary(data).c_str());
    else if(inputId == inputAscii)
        return env->NewStringUTF(asciiToBinary(data).c_str());
    else if(inputId == inputBit)
        return env->NewStringUTF(maxBinaryWithBits(data).c_str());
    else
        return env->NewStringUTF("");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_programmingcalculator_MainActivity_asciiButtonFunction(JNIEnv *env, jobject thiz,
                                                                        jstring str, jint inputId) {
    jboolean isCopy;
    std::string data = std::string(env->GetStringUTFChars(str, &isCopy));

    if(inputId == inputAscii)
        return env->NewStringUTF(asciiToAscii(data).c_str());
    else if(inputId == inputDecimal)
        return env->NewStringUTF(decimalToAscii(data).c_str());
    else if(inputId == inputBinary)
        return env->NewStringUTF(binaryToAscii(data).c_str());
    else if(inputId == inputHex)
        return env->NewStringUTF(hexToAscii(data).c_str());
    else if(inputId == inputBit)
        return env->NewStringUTF(maxAsciiWithBits(data).c_str());
    else
        return env->NewStringUTF("");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_programmingcalculator_MainActivity_hexButtonFunction(JNIEnv *env, jobject thiz,
                                                                      jstring str, jint inputId) {
    jboolean isCopy;
    std::string data = std::string(env->GetStringUTFChars(str, &isCopy));

    if(inputId == inputDecimal)
        return env->NewStringUTF(decimalToHex(data).c_str());
    else if(inputId == inputAscii)
        return env->NewStringUTF(asciiToHex(data).c_str());
    else if(inputId == inputBinary)
        return env->NewStringUTF(binaryToHex(data).c_str());
    else if(inputId == inputHex)
        return env->NewStringUTF(hexToHex(data).c_str());
    else if(inputId == inputBit)
        return env->NewStringUTF(maxHexWithBits(data).c_str());
    else
        return env->NewStringUTF("");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_programmingcalculator_MainActivity_decimalButtonFunction(JNIEnv *env, jobject thiz,
                                                                          jstring str, jint inputId) {
    jboolean isCopy;
    std::string data = std::string(env->GetStringUTFChars(str, &isCopy));

    if(inputId == inputDecimal){
        return env->NewStringUTF(decimalToDecimal(data).c_str());
    } else if(inputId == inputAscii)
        return env->NewStringUTF(asciiToDecimal(data).c_str());
    else if(inputId == inputBinary)
        return env->NewStringUTF(binaryToDecimal(data).c_str());
    else if(inputId == inputHex)
        return env->NewStringUTF(hexToDecimal(data).c_str());
    else if(inputId == inputBit)
        return env->NewStringUTF(maxDecimalWithBits(data).c_str());
    else
        return env->NewStringUTF("");
}
