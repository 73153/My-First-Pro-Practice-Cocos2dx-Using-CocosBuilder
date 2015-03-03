
#include "../SoundManager/SoundManager.h"
#include "SimpleAudioEngine.h"
#include "../GameManager/GameManager.h"
using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;
SoundManager* SoundManager::m_mySingleton = NULL;
SoundManager::SoundManager():sound_narrator_id(0),soundFX(0),sound_background_id(0),sound_instractunalnoah_id(0),arr_instractunalNoah(NULL)
{
    arr_instractunalNoah=CCArray::create();
    arr_instractunalNoah->retain();
}
SoundManager* SoundManager::sharedSoundManager()
{
    //If the singleton has no instance yet, create one
    if(NULL == m_mySingleton)
    {
        //Create an instance to the singleton
        m_mySingleton = new SoundManager();
    }
    //Return the singleton object
    return m_mySingleton;
}
#pragma mark -
#pragma mark play sound
#pragma mark -
unsigned int SoundManager::playSoundEffect(const char* filename,bool islooping)
{
    //    if (this->isEffectPlaying(soundFX))
    //    {
    //        SimpleAudioEngine::sharedEngine()->stopEffect(soundFX);
    //        soundFX=SimpleAudioEngine::sharedEngine()->playEffect(filename, islooping);
    //    }
    //    else
    //    {
    soundFX=0;
    soundFX=SimpleAudioEngine::sharedEngine()->playEffect(filename, islooping);
    //    }
    
    //set if mute
    // CCString *str=CCString::createWithFormat("%s",filename);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    //      string s = str->m_sString;
    //      size_t f1 = s.find(".wav");
    //      s.replace(f1, std::string(".wav").length(), ".ogg");
    //      size_t f2 = s.find(".ogg");
    //      s.replace(f2, std::string(".ogg").length(), ".ogg");
    //      size_t f3 = s.find(".wav");
    //      s.replace(f3, std::string(".wav").length(), ".ogg");
    //     if (CCFileUtils::sharedFileUtils()->isFileExist(s))
    //     {
    //         CCLog("%s",s.c_str());
    //     }
    //    size_t f4 = s.find(".ogg");
    //    s.replace(f4, std::string(".ogg").length(), ".wav");
    //    size_t f5 = s.find(".ogg");
    //    s.replace(f5, std::string(".ogg").length(), ".ogg");
    //    size_t f6 = s.find(".ogg");
    //    s.replace(f6, std::string(".ogg").length(), ".wav");
#endif
    
    //soundFX=SimpleAudioEngine::sharedEngine()->playEffect(filename);
    return soundFX;
}
void SoundManager::stopSoundEffect(unsigned int stop_sound)
{
    SimpleAudioEngine::sharedEngine()->stopEffect(stop_sound);
}
bool SoundManager::isEffectPlaying( unsigned int stop_sound){
    return true;
}
void SoundManager::stopAllEffect()
{
    SimpleAudioEngine::sharedEngine()->stopEffect(soundFX);
    SimpleAudioEngine::sharedEngine()->stopEffect(sound_instractunalnoah_id);
    SimpleAudioEngine::sharedEngine()->stopEffect(sound_narrator_id);
    SimpleAudioEngine::sharedEngine()->stopEffect(sound_background_id);
    SimpleAudioEngine::sharedEngine()->stopAllEffects();
}
#pragma mark -
#pragma mark Load sounds
#pragma mark -
void SoundManager::loadSondEffect(int scene)
{
    TargetPlatform detectTagetPlatform = CCApplication::sharedApplication()->getTargetPlatform();
    if(detectTagetPlatform==kTargetAndroid)
        return;
    switch (1)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound_6_iPhone.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("brick-break.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Ball Hit On Stick 1.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Ball Hit On Stick 2 Final.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Boll Drop 2 Final.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound 1.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound 2.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound 3.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound 4.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound 5.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound 6.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Cheers 3 FInal.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Coin Pickup 2 Final.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Power Up 1.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Power Up 2.wav");
            SimpleAudioEngine::sharedEngine()->preloadEffect("Power Up 3.wav");
            
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound_6_iPhone.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("brick-break.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Ball_Hit_On_Stick 1.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Ball_Hit_On_Stick_2_Final.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Boll_Drop_2_Final.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound_1.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound_2.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound_3.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound_4.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound_5.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Brick_Sound_6.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Cheers_3_FInal.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Coin_Pickup_2_Final.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Power_Up_1.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Power_Up_2.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Power_Up_3.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/Jerremyhelm Evil Laugh.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/mean.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/narratorScene2.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/narratorScene1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/Philhelm Whimper.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/Smash Glass.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/thief.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Scene 1 and 2/GuitarBackgound.wav");
            
            break;
        }
            //        case 2:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/ambient.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/Annehelm Scream.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/Boo Crowd.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/choke.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/Crash Metal 5.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/drunk.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/fireFadeIn.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/fireFadeOut.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/fireLong.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/Horror Crazy People.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/instructionalNoahScene2-1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/instructionalNoahScene2-2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/instructionalNoahScene2-3.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/Jerremyhelm Evil Laugh.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/mean.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/narratorScene2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/narratorScene1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/Philhelm Whimper.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/Smash Glass.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 1 and 2/thief.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Scene 1 and 2/GuitarBackgound.wav");
            //            break;
            //        }
            //        case 3:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Scene 3/doveFlap.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 5/forceFieldHumm.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/Impact laser.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/explosionNear.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/explosionFar.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/PHAZE DOWN.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/fireballExplosionMidair.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/doveSkaw.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/noahCantBelieve.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/noahDontKnow.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/noahDontUnderstand.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/doveFlap.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/fireballLaunchFar.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/fireballLaunchNear.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/narratorScene3.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/instructionalNoahScene3-1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/instructionalNoahScene3-2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 3/instructionalNoahScene3-3.wav");
            //            break;
            //        }
            //        case 4:
            //        {
            //          SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 4/narratorScene4.wav");
            //          SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 4/instructionalNoahScene4-1.wav");
            //          SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 4/instructionalNoahScene4-2.wav");
            //          SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 4/instructionalNoahScene4-3.wav");
            //            break;
            //        }
            //        case 5:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 5/forceFieldHumm.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 5/instructionalNoahScene5-1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 5/instructionalNoahScene5-2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 5/instructionalNoahScene5-3.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 5/narratorScene5.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 5/scene5BackgroundMusic.wav");
            //            break;
            //        }
            //        case 6:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Scene 5/scene5BackgroundMusic.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 6/Bus_School_Horn.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 6/ELEPHANT.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 6/fieldWhistle.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 6/instructionalNoahScene6-1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 6/instructionalNoahScene6-2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 6/instructionalNoahScene6-3.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 6/instructionalNoahScene6-4.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 6/narratorScene6.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 6/Whoosh_1.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 6/Whoosh_2.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 6/Whoosh_2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 6/Whoosh_3.ogg");
            //            break;
            //        }
            //        case 7:
            //        {
            //               SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 7/instructionalNoahScene7-1.wav");
            //               SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 7/instructionalNoahScene7-2.wav");
            //               SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 7/narratorScene7.wav");
            //               SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 7/rushingFloodwaters.wav");
            //            break;
            //        }
            //        case 8:
            //        {
            //
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/arkPieceDone1.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/arkPieceDone2.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/arkPieceDone3.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/arkPieceDone4.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/arkPieceDone5.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/arkPieceDone6.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/arkPieceDone7.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/arkPieceDone8.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/arkPieceDone9.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/gamePiano.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/HOUSE Impact.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/magic_flourish_04.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/magic_flourish_05.wav");
            //               // SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/magicZing.ogg");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/noahArkBuildFinished.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/noahArkDeck1Done.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/noahArkDeck2Done.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/noahArkFrameDone.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/noahArkStarting.wav");
            //                SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 9/pieceToPlace.wav");
            //            break;
            //        }
            //        case 9:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/instructionalNoahScene8-1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/instructionalNoahScene8-2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/crowdBooing.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whimpyGuy1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/crowdBooing.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whimpyGuy1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whimpyGuy2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whimpyGuy3.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whimpyGuy4.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whimpyGuy5.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whimpyGuy6.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whimpyGuy7.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whimpyGuy7.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/gurlFriend1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/gurlFriend2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/gurlFriend3.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/gurlFriend4.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/gurlFriend5.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/gurlFriend6.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/gurlFriend7.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/gurlFriend8.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/gurlFriend9.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whiteBeard1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whiteBeard2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whiteBeard3.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whiteBeard4.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whiteBeard5.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whiteBeard6.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/whiteBeard7.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/blackbeard.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 8/burns.wav");
            //
            //
            //            break;
            //        }
            //        case 10:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/AllTheOthers.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/BackRattleSnake.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/CamelRisingHump.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/ChameleonAppear.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/CrocodileChomp.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/DucksMix.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/ElephantFade.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/Goat.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/instructionalNoahScene10-1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/instructionalNoahScene10-2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/instructionalNoahScene10-3.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/KangarooBoingUp.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/Mantis.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/narratorScene10.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/noah_scene_10_ver3.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/OtterChuckle.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/PelicanHallo.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/PigROTFL.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/PorcupineOhNo.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/PossumChatter.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/SheepBaah.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/Tiger.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 10/ZebraWhinny.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Scene 10/scene10BackgroundMusic.wav");
            //            break;
            //        }
            //        case 11:
            //        {
            //
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/scene11Instructions.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/NoahGreatjob.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/jingle.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/cerdito.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/elefante.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/gallina.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/gato.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/leon.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/mono.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/oveja.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/panda.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/rana.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/vaca.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/Bell Transition.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/wrong match deny.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 11/card flip.ogg");
            //
            //            break;
            //        }
            //        case 12:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 12/WATER RISING.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 12/Cloud 1_raindrop with reverb.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 12/Cloud 2_multiple drops no pitch drop with reverb.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 12/wind.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 12/thunder1.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 12/thunder2.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 12/instructionalNoahScene12-1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 12/instructionalNoahScene12-2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 12/scene12Narrator.wav");
            //            break;
            //        }
            //        case 13:
            //        {
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/animalFalling.wav");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/loadTheBoatCheer.caf");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/short_flourish_09.caf");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_boa.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_cat.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_chiken.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_cow.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_elephant.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_goat.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_husky.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_komodo.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_lion.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_monkey.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_panda.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_panther.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_peacock.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_pig.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/LTB_sheep.m4a");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/animalSplash.wav");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/final victory cheer.wav");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/rubberBoing.wav");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/RubberRubb.wav");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/scene13BackgroundMusic.wav");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/scene13Congratulations.wav");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/scene13CongratulationsMinor.wav");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/scene13Instructions.wav");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/splat.wav");
            //                    SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 13/victory.wav");
            //                        break;
            //        }
            //        case 14:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/acoustic_A.m4a");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/acoustic_B.m4a");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/acoustic_C.m4a");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/acoustic_D.m4a");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/acoustic_E.m4a");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/acoustic_F.m4a");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/acoustic_G.m4a");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/acoustic_MOON.m4a");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/coolmallet_A.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/coolmallet_B.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/coolmallet_C.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/coolmallet_D.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/coolmallet_E.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/coolmallet_F.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/coolmallet_G.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/coolmallet_MOON.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/instructionalNoahScene14-1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/instructionalNoahScene14-2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Scene 14/NighBackgroundMusic.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 14/scene14Narrator.ogg");
            //            break;
            //        }
            //        case 15:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 15/fishingNoahGotFish.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 15/instructionalNoahScene15-1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 15/instructionalNoahScene15-2.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 15/instructionalNoahScene15-3.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 15/narratorScene15.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 15/oceanAmbience.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Scene 15/scene15BackMusic.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 15/splashFromFish.ogg");
            //            break;
            //        }
            //        case 16:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 16/areYouReadyGo.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 16/narratorScene16.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 16/raincloud sound fx.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 16/scene16DoveTakeFlight.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 16/scene16IdleDove.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 16/scene16NoahInstruction.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 16/scene16NoahOnTouch5.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 16/scene16onTouch.ogg");
            //            break;
            //        }
            //        case 17:
            //        {
            //             SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/narratorScene17_2.ogg");
            //             SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/narratorScene17_1.ogg");
            //             SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/hiFivePow.ogg");
            //             SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/arkCrashing.ogg");
            //             SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/animalBouncing.ogg");
            //
            //            break;
            //        }
            //        case 18:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/bearTouchedSound.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/hippoTouchedSound.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/rabbitTouchedSound1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/rabbitTouchedSound2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/racoonTouchedSound.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/snakeTouchedSound1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/snakeTouchedSound2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/snakeTouchedSound3.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/snakeTouchedSound4.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/snakeTouchedSound5.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/snakeTouchedSound6.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/snakeTouchedSound7.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/snakeTouchedSound8.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/StlDmA.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/StlDmB.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/StlDmC.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/StlDmD.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/StlDmE.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/StlDmF.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/StlDmG.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/StlDmMOON.wav");
            //            break;
            //        }
            //        case 19:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/instructionalNoahScene17c-1.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/instructionalNoahScene17c-2.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/countryMorning.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadEffect("Scene 17/flowerChime.ogg");
            //            break;
            //        }
        default:
        {
            break;
        }
    }
}
#pragma mark -
#pragma mark Remove sounds
#pragma mark -
void SoundManager::unLoadSoundEffect(int scene)
{
    TargetPlatform detectTagetPlatform = CCApplication::sharedApplication()->getTargetPlatform();
    if(detectTagetPlatform==kTargetAndroid)
        return;
    switch (1)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            
            SimpleAudioEngine::sharedEngine()->unloadEffect("brick-break.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound_6_iPhone.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Ball Hit On Stick 1.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Ball Hit On Stick 2 Final.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Boll Drop 2 Final.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound 1.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound 2.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound 3.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound 4.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound 5.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound 6.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Cheers 3 FInal.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Coin Pickup 2 Final.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Power Up 1.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Power Up 2.wav");
            SimpleAudioEngine::sharedEngine()->unloadEffect("Power Up 3.wav");
            
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound_6_iPhone.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("brick-break.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Ball_Hit_On_Stick 1.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Ball_Hit_On_Stick_2_Final.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Boll_Drop_2_Final.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound_1.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound_2.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound_3.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound_4.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound_5.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Brick_Sound_6.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Cheers_3_FInal.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Coin_Pickup_2_Final.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Power_Up_1.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Power_Up_2.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Power_Up_3.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/ambient.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Annehelm Scream.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Boo Crowd.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/choke.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Crash Metal 5.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/drunk.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/fireFadeIn.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/fireFadeOut.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/fireLong.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Horror Crazy People.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/instructionalNoahScene2-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/instructionalNoahScene2-2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/instructionalNoahScene2-3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Jerremyhelm Evil Laugh.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/mean.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/narratorScene2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/narratorScene1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Philhelm Whimper.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Smash Glass.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/thief.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Scene 1 and 2/GuitarBackgound.wav");
            
            break;
        }
            //        case 2:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/ambient.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Annehelm Scream.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Boo Crowd.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/choke.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Crash Metal 5.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/drunk.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/fireFadeIn.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/fireFadeOut.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/fireLong.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Horror Crazy People.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/instructionalNoahScene2-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/instructionalNoahScene2-2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/instructionalNoahScene2-3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Jerremyhelm Evil Laugh.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/mean.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/narratorScene2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/narratorScene1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Philhelm Whimper.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/Smash Glass.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 1 and 2/thief.ogg");
            //            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Scene 1 and 2/GuitarBackgound.wav");
            //            break;
            //        }
            //        case 3:
            //        {
            //            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Scene 3/doveFlap.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/forceFieldHumm.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/Impact laser.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/explosionNear.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/explosionFar.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/PHAZE DOWN.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/fireballExplosionMidair.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/doveSkaw.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/noahCantBelieve.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/noahDontKnow.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/noahDontUnderstand.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/doveFlap.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/fireballLaunchFar.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/fireballLaunchNear.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/narratorScene3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/instructionalNoahScene3-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/instructionalNoahScene3-2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 3/instructionalNoahScene3-3.wav");
            //            break;
            //        }
            //        case 4:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 4/narratorScene4.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 4/instructionalNoahScene4-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 4/instructionalNoahScene4-2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 4/instructionalNoahScene4-3.wav");
            //            break;
            //        }
            //        case 5:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 5/forceFieldHumm.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 5/instructionalNoahScene5-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 5/instructionalNoahScene5-2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 5/instructionalNoahScene5-3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 5/narratorScene5.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 5/scene5BackgroundMusic.wav");
            //            break;
            //        }
            //        case 6:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/scene5BackgroundMusic.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/Bus_School_Horn.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/ELEPHANT.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/fieldWhistle.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/instructionalNoahScene6-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/instructionalNoahScene6-2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/instructionalNoahScene6-3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/instructionalNoahScene6-4.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/narratorScene6.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/Whoosh_1.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/Whoosh_2.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/Whoosh_2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 6/Whoosh_3.ogg");
            //            break;
            //        }
            //        case 7:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 7/instructionalNoahScene7-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 7/instructionalNoahScene7-2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 7/narratorScene7.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 7/rushingFloodwaters.wav");
            //            break;
            //        }
            //        case 8:
            //        {
            //
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/arkPieceDone1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/arkPieceDone2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/arkPieceDone3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/arkPieceDone4.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/arkPieceDone5.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/arkPieceDone6.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/arkPieceDone7.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/arkPieceDone8.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/arkPieceDone9.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/gamePiano.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/HOUSE Impact.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/magic_flourish_04.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/magic_flourish_05.wav");
            //            //SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/magicZing.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/noahArkBuildFinished.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/noahArkDeck1Done.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/noahArkDeck2Done.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/noahArkFrameDone.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/noahArkStarting.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 9/pieceToPlace.wav");
            //            break;
            //        }
            //        case 9:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/instructionalNoahScene8-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/instructionalNoahScene8-2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/crowdBooing.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whimpyGuy1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whimpyGuy2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whimpyGuy3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whimpyGuy4.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whimpyGuy5.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whimpyGuy6.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whimpyGuy7.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whimpyGuy7.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/gurlFriend1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/gurlFriend2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/gurlFriend3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/gurlFriend4.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/gurlFriend5.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/gurlFriend6.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/gurlFriend7.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/gurlFriend8.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/gurlFriend9.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whiteBeard1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whiteBeard2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whiteBeard3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whiteBeard4.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whiteBeard5.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whiteBeard6.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/whiteBeard7.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/blackbeard.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 8/burns.wav");
            //
            //
            //            break;
            //        }
            //        case 10:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/AllTheOthers.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/BackRattleSnake.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/CamelRisingHump.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/ChameleonAppear.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/CrocodileChomp.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/DucksMix.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/ElephantFade.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/Goat.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/instructionalNoahScene10-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/instructionalNoahScene10-2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/instructionalNoahScene10-3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/KangarooBoingUp.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/Mantis.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/narratorScene10.wav");
            //           // SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/noah_scene_10_ver3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/OtterChuckle.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/PelicanHallo.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/PigROTFL.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/PorcupineOhNo.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/PossumChatter.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/SheepBaah.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/Tiger.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 10/ZebraWhinny.wav");
            //            SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("Scene 10/scene10BackgroundMusic.wav");
            //            break;
            //        }
            //        case 11:
            //        {
            //
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/scene11Instructions.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/NoahGreatjob.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/jingle.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/cerdito.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/elefante.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/gallina.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/gato.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/leon.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/mono.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/oveja.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/panda.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/rana.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/vaca.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/Bell Transition.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/wrong match deny.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 11/card flip.ogg");
            //
            //            break;
            //        }
            //        case 12:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 12/WATER RISING.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 12/Cloud 1_raindrop with reverb.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 12/Cloud 2_multiple drops no pitch drop with reverb.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 12/wind.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 12/thunder1.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 12/thunder2.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 12/instructionalNoahScene12-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 12/instructionalNoahScene12-2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 12/scene12Narrator.wav");
            //            break;
            //        }
            //        case 13:
            //        {
            //
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/animalFalling.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/loadTheBoatCheer.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/short_flourish_09.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_boa.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_cat.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_chiken.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_cow.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_elephant.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_goat.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_husky.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_komodo.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_lion.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_monkey.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_panda.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_panther.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_peacock.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_pig.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/LTB_sheep.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/animalSplash.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/final victory cheer.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/rubberBoing.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/RubberRubb.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/scene13BackgroundMusic.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/scene13Congratulations.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/scene13CongratulationsMinor.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/scene13Instructions.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/splat.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 13/victory.wav");
            //            break;
            //        }
            //        case 14:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/acoustic_A.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/acoustic_B.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/acoustic_C.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/acoustic_D.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/acoustic_E.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/acoustic_F.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/acoustic_G.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/acoustic_MOON.m4a");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/coolmallet_A.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/coolmallet_B.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/coolmallet_C.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/coolmallet_D.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/coolmallet_E.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/coolmallet_F.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/coolmallet_G.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/coolmallet_MOON.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/instructionalNoahScene14-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/instructionalNoahScene14-2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 14/scene14Narrator.ogg");
            //            break;
            //        }
            //        case 15:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 15/fishingNoahGotFish.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 15/instructionalNoahScene15-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 15/instructionalNoahScene15-2.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 15/instructionalNoahScene15-3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 15/narratorScene15.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 15/oceanAmbience.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 15/scene15BackMusic.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 15/splashFromFish.ogg");
            //            break;
            //        }
            //        case 16:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 16/areYouReadyGo.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 16/narratorScene16.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 16/raincloud sound fx.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 16/scene16DoveTakeFlight.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 16/scene16IdleDove.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 16/scene16NoahInstruction.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 16/scene16NoahOnTouch5.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 16/scene16onTouch.ogg");
            //            break;
            //        }
            //        case 17:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/narratorScene17_2.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/narratorScene17_1.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/hiFivePow.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/arkCrashing.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/animalBouncing.ogg");
            //
            //            break;
            //        }
            //        case 18:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/bearTouchedSound.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/hippoTouchedSound.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/rabbitTouchedSound1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/rabbitTouchedSound2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/racoonTouchedSound.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/snakeTouchedSound1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/snakeTouchedSound2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/snakeTouchedSound3.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/snakeTouchedSound4.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/snakeTouchedSound5.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/snakeTouchedSound6.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/snakeTouchedSound7.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/snakeTouchedSound8.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/StlDmA.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/StlDmB.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/StlDmC.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/StlDmD.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/StlDmE.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/StlDmF.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/StlDmG.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/StlDmMOON.wav");
            //            break;
            //        }
            //        case 19:
            //        {
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/instructionalNoahScene17c-1.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/instructionalNoahScene17c-2.wav");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/countryMorning.ogg");
            //            SimpleAudioEngine::sharedEngine()->unloadEffect("Scene 17/flowerChime.ogg");
            //            break;
            //        }
        default:
        {
            break;
        }
    }
    CCLog("unload sound effect callled");
    SimpleAudioEngine::sharedEngine()->end();
}
#pragma mark -
#pragma mark Background sound
#pragma mark -
void SoundManager::startBackgroundSound()
{
    int scene=GameManager::sharedGameManager()->getcurrent_scene().getValue();
    switch (scene)
    {
        case 0:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 10/noah_scene_10_ver3.wav", true);
            break;
        }
        case 1:
        {
            
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 1 and 2/GuitarBackgound.wav", true);
            break;
        }
        case 2:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 1 and 2/GuitarBackgound.wav", true);
            break;
        }
        case 3:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 1 and 2/GuitarBackgound.wav", true);
            break;
        }
        case 4:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 5/scene5BackgroundMusic.wav", true);
            break;
        }
        case 5:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 5/scene5BackgroundMusic.wav",true);
            break;
        }
        case 6:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 5/scene5BackgroundMusic.wav",true);
            break;
        }
        case 7:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 5/scene5BackgroundMusic.wav",true);
            break;
        }
        case 8:{
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 5/scene5BackgroundMusic.wav",true);
            break;
        }
        case 9:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 9/gamePiano.wav",true);
            break;
        }
        case 10:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 10/noah_scene_10_ver3.wav",true);
            break;
        }
        case 11:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 11/scene11BackgroundMusic.ogg",true);
            break;
        }
        case 12:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 10/scene10BackgroundMusic.wav",true);
            
            break;
        }
        case 13:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 13/scene13BackgroundMusic.wav",false);
            break;
        }
        case 14:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 5/scene5BackgroundMusic.wav",true);
            break;
        }
        case 15:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 15/scene15BackMusic.wav",true);
            break;
        }
        case 16:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 13/scene13BackgroundMusic.wav",false);
            break;
        }
        case 17:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 15/scene15BackMusic.wav",true);
            break;
        }
        case 18:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 17/scene18BacgroundMusic.wav",false);
            break;
        }
        case 19:
        {
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic("Scene 15/scene15BackMusic.wav",false);
            
            break;
        }
        default:
        {
            break;
        }
    }
}
void SoundManager::stopBackgroundSound()
{
    CCLOG("Stoped background music");
    if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
    {
        SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    }
}
bool SoundManager::is_backgroundMusicPlaying()
{
    return  SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying();
}
#pragma mark -
#pragma mark Play Narrator
#pragma mark -
void SoundManager::startNarrator()
{
    int scene=GameManager::sharedGameManager()->getcurrent_scene().getValue();
    switch (scene)
    {
        case 0:
        {
            break;
        }
        case 1:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 1 and 2/narratorScene1.wav");
            
            
            break;
        }
        case 2:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 1 and 2/narratorScene2.wav");
            break;
        }
        case 3:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 3/narratorScene3.wav");
            break;
        }
        case 4:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 4/narratorScene4.wav");
            break;
        }
        case 5:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 5/narratorScene5.wav");
            break;
        }
        case 6:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 6/narratorScene6.wav");
            break;
        }
        case 7:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 7/narratorScene7.wav");
            break;
        }
        case 8:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("narratorScene8.wav");
            break;
        }
        case 9:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 8/narratorScene8.wav");
            
            break;
        }
        case 10:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 10/narratorScene10.wav");
            break;
        }
        case 11:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 11/scene11Instructions.ogg");
            break;
        }
        case 12:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 12/scene12Narrator.wav");
            break;
        }
        case 13:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 13/scene13Instructions.wav");
            break;
        }
        case 14:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 14/scene14Narrator.ogg");
            break;
        }
        case 15:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 15/narratorScene15.wav");
            break;
        }
        case 16:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 16/narratorScene16.ogg");
            break;
        }
        case 17:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 17/narratorScene17_1.ogg");
            break;
        }
        case 18:
        {
            break;
        }
        case 19:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 17/scene17cNarrator.wav");
            break;
        }
        default:
        {
            sound_narrator_id=SimpleAudioEngine::sharedEngine()->playEffect("Scene 17/noah_scene_10_ver3.wav");
            break;
        }
    }
    
}
void SoundManager::stopNarrator()
{
    SimpleAudioEngine::sharedEngine()->stopEffect(sound_narrator_id);
}
bool SoundManager::isNarratorPlaying()
{
    
}
#pragma mark -
#pragma mark set effect volume
#pragma mark -
void SoundManager::setEffectVolume(float volume)
{
    SimpleAudioEngine::sharedEngine()->setEffectsVolume(volume);
}
float SoundManager::getEffectVolume()
{
    return  SimpleAudioEngine::sharedEngine()->getEffectsVolume();
}
#pragma mark -
#pragma mark  background musicvolume
#pragma mark -
void SoundManager::set_Backgound_MusicVolume(float volume)
{
    SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(volume);
}
float SoundManager::get_Backgrond_MusicVolume()
{
    return  SimpleAudioEngine::sharedEngine()->getEffectsVolume();
}
#pragma mark -
#pragma mark  instractunal noah
#pragma mark -
unsigned int SoundManager::startInstractunalNoah(CCString *name)
{
    sound_instractunalnoah_id=SimpleAudioEngine::sharedEngine()->playEffect(name->getCString(), false);
    //set if mute
    
    return sound_instractunalnoah_id;
}
void SoundManager::stopInstractunalNoah()
{
    SimpleAudioEngine::sharedEngine()->stopEffect(sound_instractunalnoah_id);
}
bool SoundManager::isInstractunalNoahplaying()
{
    
}