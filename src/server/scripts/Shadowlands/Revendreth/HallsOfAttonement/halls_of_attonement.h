#ifndef DEF_HALLS_OF_ATTONEMENT_H_
#define DEF_HALLS_OF_ATTONEMENT_H_

#include "CreatureAIImpl.h"

#define DataHeader "ABT"
#define ABTScriptName "instance_halls_of_attonement"

template <class AI, class T>
inline AI* GetHallsOfAttonementAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ABTScriptName);
}

#define RegisterHallsOfAttonementCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetHallsOfAttonementAI)

#endif
