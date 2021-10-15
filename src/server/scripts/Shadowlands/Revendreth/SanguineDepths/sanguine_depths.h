#ifndef DEF_SANGUINE_DEPTHS_H_
#define DEF_SANGUINE_DEPTHS_H_

#include "CreatureAIImpl.h"

#define DataHeader "ABT"
#define ABTScriptName "instance_sanquine_depths"

template <class AI, class T>
inline AI* GeSanguineDepthsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ABTScriptName);
}

#define RegisterSanguineDepthsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSanguineDepthsAI)

#endif
