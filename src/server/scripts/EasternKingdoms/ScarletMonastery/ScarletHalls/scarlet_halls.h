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

#ifndef DEF_SCARLET_HALLS_H_
#define DEF_SCARLET_HALLS_H_

#include "CreatureAIImpl.h"

#define DataHeader "ScarletHalls"
#define ScarletHallsScriptName "instance_scarlet_halls"

uint32 const EncounterCount = 3;

enum ScarletHallsTypes
{
    // Encounters
    DATA_HOUNDMASTER_BRAUN      = 0,
    DATA_ARMSMASTER_HARLAN      = 1,
    DATA_FLAMEWEAVER_KOEGLER    = 2
};

enum ScarletHallsCreatureIds
{
    // Bosses
    BOSS_HOUNDMASTER_BRAUN      = 59303,
    BOSS_ARMSMASTER_HARLAN      = 58632,
    BOSS_FLAMEWEAVER_KOEGLER    = 59150
};

enum ScarletHallsGameObjectIds
{
    GO_HERODS_DOOR_HARLAN_ENCOUNTER_ENTRANCE    = 210480
};

template <class AI, class T>
inline AI* GetScarletHallsAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ScarletHallsScriptName);
}

#define RegisterScarletHallsCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetScarletHallsAI)

#endif
