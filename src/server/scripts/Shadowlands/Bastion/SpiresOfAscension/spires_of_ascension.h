#ifndef DEF_SPIRES_OF_ASCENSION_H_
#define DEF_SPIRES_OF_ASCENSION_H_

#include "CreatureAIImpl.h"

#define DataHeader "ABT"
#define ABTScriptName "instance_spires_of_ascension"


template <class AI, class T>
inline AI* GetSpiresOfAscensionAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ABTScriptName);
}

#define RegisterSpiresOfAscensionCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSpiresOfAscensionAI)

#endif
