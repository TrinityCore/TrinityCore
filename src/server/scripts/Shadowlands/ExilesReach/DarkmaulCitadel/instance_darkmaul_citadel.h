#ifndef DEF_DARKMAUL_CITADEL_H_
#define DEF_DARKMAUL_CITADEL_H_

#include "CreatureAIImpl.h"

#define DataHeader "ABT"
#define ABTScriptName "instance_darkmaul_citadel"

template <class AI, class T>
inline AI* GetDarkMaulCitadelAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ABTScriptName);
}

#define RegisterDarkMaulCitadelCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetDarkMaulCitadelAI)

#endif
