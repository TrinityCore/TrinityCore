/*
* Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
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

#ifndef THE_VORTEX_PINNACLE_H_
#define THE_VORTEX_PINNACLE_H_

#include "Map.h"
#include "Creature.h"
#include "ObjectMgr.h"

#define BOSSNUMBER 3

enum DataTypes
{
    DATA_GRAND_VIZIER_ERTAN         = 0,
    DATA_ALTAIRUS                   = 1,
    DATA_ASAAD                      = 2
};

enum CreatureIds
{
    BOSS_GRAND_VIZIER_ERTAN         = 43878,
    BOSS_ALTAIRUS                   = 43873,
    BOSS_ASAAD                      = 43875,

    NPC_ERTANS_VORTEX               = 46007,
    NPC_SKYFALL_STAR                = 45932
};

enum GameObjectIds
{
};

template<class AI>
CreatureAI* GetTheVortexPinnacleAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_the_vortex_pinnacle"))
                return new AI(creature);
    return NULL;
}

#endif
