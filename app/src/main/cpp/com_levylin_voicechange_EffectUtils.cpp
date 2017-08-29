#include <unistd.h>
#include "com_levylin_voicechange_EffectUtils.h">
#include "inc/fmod.hpp"
#include "common.h"
#include "MyLog.h"

using namespace FMOD;

/*
 * Class:     com_levylin_voicechange_EffectUtils
 * Method:    fix
 * Signature: (Ljava/lang/String;I)V
 */
JNIEXPORT void JNICALL Java_com_levylin_voicechange_EffectUtils_fix
        (JNIEnv *env, jclass clz, jstring path, jint type) {
    System *system = 0;
    System_Create(&system);
    system->init(32, FMOD_INIT_NORMAL, 0);
    const char *path_cstr = env->GetStringUTFChars(path, 0);
    Sound *sound = 0;
    system->createSound(Common_MediaPath(path_cstr), FMOD_DEFAULT, 0, &sound);
    sound->setLoopCount(1);
    Channel *channel;
    DSP *dsp;
    float frequency;
    switch (type) {
        default:
        case com_levylin_voicechange_EffectUtils_MODE_NORMAL:
            LOGI("%s","原声");
            system->playSound(sound, 0, false, &channel);
            break;
        case com_levylin_voicechange_EffectUtils_MODE_LUOLI:
            LOGI("%s","萝莉");
            system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
            dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH, 2.5);
            system->playSound(sound, 0, false, &channel);
            channel->addDSP(0, dsp);
            break;
        case com_levylin_voicechange_EffectUtils_MODE_DASHU:
            LOGI("%s","大叔");
            system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
            dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH,0.8);
            system->playSound(sound, NULL, false, &channel);
            channel->addDSP(0, dsp);
            break;
        case com_levylin_voicechange_EffectUtils_MODE_JINGSONG:
            LOGI("%s","惊悚");
            //FMOD_DSP_TYPE_TREMOLO 颤抖
            system->createDSPByType(FMOD_DSP_TYPE_TREMOLO, &dsp);
            dsp->setParameterFloat(FMOD_DSP_TREMOLO_SKEW,0.5);
            system->playSound(sound, NULL, false, &channel);
            channel->addDSP(0, dsp);
            break;
        case com_levylin_voicechange_EffectUtils_MODE_GAOGUAI:
            LOGI("%s","搞怪");
            //提高语速
            system->createDSPByType(FMOD_DSP_TYPE_NORMALIZE, &dsp);
            system->playSound(sound, NULL, false, &channel);
            channel->addDSP(0, dsp);
            channel->getFrequency(&frequency);
            frequency = frequency*1.6f;
            channel->setFrequency(frequency);
            break;
        case com_levylin_voicechange_EffectUtils_MODE_KONGLING:
            LOGI("%s","空灵");
            system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dsp);
            dsp->setParameterFloat(FMOD_DSP_ECHO_DELAY,300);
            dsp->setParameterFloat(FMOD_DSP_ECHO_FEEDBACK,20);
            system->playSound(sound, NULL, false, &channel);
            channel->addDSP(0, dsp);
            break;
    }

    //获取时间长度
    Sound *currentsound = 0;
    channel->getCurrentSound(&currentsound);
    unsigned int lenms = 0;
    currentsound->getLength(&lenms, FMOD_TIMEUNIT_MS);
    LOGI("Time %d", lenms);
    usleep(lenms * 1000);
    LOGI("play finish");
    //播放结束释放资源
    env->ReleaseStringUTFChars(path, path_cstr);
    sound->release();
    system->close();
    system->release();
}