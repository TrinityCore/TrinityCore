#ifndef DEF_CASTLE_NATHRIA_H_
#define DEF_CASTLE_NATHRIA_H_

#include "CreatureAIImpl.h"

#define DataHeader "ABT"
#define ABTScriptName "instance_castle_nathria"

template <class AI, class T>
inline AI* GetCastleNathriaAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ABTScriptName);
}

#define RegisterCastleNathriaCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetCastleNathriaAI)

#endif