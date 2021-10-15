#ifndef DEF_DE_OTHER_SIDE_H_
#define DEF_DE_OTHER_SIDE_H_

#include "CreatureAIImpl.h"

#define DataHeader "ABT"
#define ABTScriptName "instance_de_other_side"

enum Data
{
	DATA_HAKKAR_THE_SOULFLAYER = 1,
	DATA_THE_MANASTORMS,
	DATA_DEALER_XYEXA,
	DATA_MUEHZALA
};

enum Creatures
{
	NPC_HAKKAR_OS = 164558,
	NPC_SON_OF_HAKKAR = 170488,
	NPC_MILLHOUSE_MANASTORM = 164556,
	NPC_MILLIFICENT_MANASTORM = 164555,
	NPC_POWER_CRYSTAL = 164560,
	NPC_DEALER_XYEXA = 164450,
	NPC_MUEHZALA = 166608,
	NPC_BWONSAMDI = 166659,
};

template <class AI, class T>
inline AI* GetDeOtherSideAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ABTScriptName);
}

#define RegisterDeOtherSideACreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetDeOtherSideAI)

#endif
