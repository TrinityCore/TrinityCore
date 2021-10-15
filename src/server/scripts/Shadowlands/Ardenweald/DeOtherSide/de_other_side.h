/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

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
