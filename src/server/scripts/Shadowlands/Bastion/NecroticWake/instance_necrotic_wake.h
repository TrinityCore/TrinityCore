#ifndef DEF_NECROTIC_WAKE_H_
#define DEF_NECROTIC_WAKE_H_

#include "CreatureAIImpl.h"

#define DataHeader "ABT"
#define ABTScriptName "instance_necrotic_wake"

template <class AI, class T>
inline AI* GetNecroticWakeAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ABTScriptName);
}

#define RegisterNecroticWakeCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetNecroticWakeAI)

#endif
