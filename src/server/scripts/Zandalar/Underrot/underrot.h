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

#ifndef DEF_UNDERROT_H_
#define DEF_UNDERROT_H_

#include "CreatureAIImpl.h"

#define DataHeader "Underrot"
#define UnderrotScriptName "instance_underrot"

uint32 const EncounterCount = 4;

enum UnderrotDataTypes
{
    // Encounters
    DATA_ELDER_LEAXA            = 0,
    DATA_SPORECALLER_ZANCHA,
    DATA_CRAGMAW_THE_INFESTED,
    DATA_UNBOUND_ABOMINATION
};

enum UnderrotCreatureIds
{
    // Bosses
    BOSS_ELDER_LEAXA            = 131318,
    BOSS_SPORECALLER_ZANCHA     = 131383,
    BOSS_CRAGMAW_THE_INFESTED   = 131817,
    BOSS_UNBOUND_ABOMINATION    = 133007
};

enum UnderrotGameObjectIds
{
    GO_PYRAMID_DOOR_UNBOUND_ABOMINATION_ENTRANCE        = 296385,
    GO_WALL_DOOR_SHORTCUT_ENTRANCE                      = 295356
};

template <class AI, class T>
inline AI* GetUnderrotAI(T* obj)
{
    return GetInstanceAI<AI>(obj, UnderrotScriptName);
}

#define RegisterUnderrotCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetUnderrotAI)

#endif
