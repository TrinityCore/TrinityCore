#ifndef DEF_PLAGUE_FALL_H_
#define DEF_PLAGUE_FALL_H_

#include "CreatureAIImpl.h"

#define DataHeader "ABT"
#define ABTScriptName "instance_plaguefall"

template <class AI, class T>
inline AI* GetPlagueFallAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ABTScriptName);
}

#define RegisterPlagueFallCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetPlagueFallAI)

#endif