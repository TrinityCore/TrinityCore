#ifndef DEF_THEATER_OF_PAIN_H_
#define DEF_THEATER_OF_PAIN_H_

#include "CreatureAIImpl.h"

#define DataHeader "ABT"
#define ABTScriptName "instance_theater_of_pain"

template <class AI, class T>
inline AI* GetTheaterOfPainAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ABTScriptName);
}

#define RegisterTheaterOfPainCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetTheaterOfPainheAI)

#endif
