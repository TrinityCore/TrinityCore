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

#ifndef DEF_BARADIN_HOLD_H_
#define DEF_BARADIN_HOLD_H_

#define BHScriptName "instance_baradin_hold"

uint32 const EncounterCount = 3;

enum DataTypes
{
    DATA_ARGALOTH           = 0,
    DATA_OCCUTHAR           = 1,
    DATA_ALIZABAL           = 2
};

enum CreatureIds
{
    BOSS_ARGALOTH           = 47120,
    BOSS_OCCUTHAR           = 52363,
    BOSS_ALIZABAL           = 55869,

    NPC_EYE_OF_OCCUTHAR     = 52389,
    NPC_FOCUS_FIRE_DUMMY    = 52369,
    NPC_OCCUTHAR_EYE        = 52368
};

enum GameObjectIds
{
    GO_ARGALOTH_DOOR        = 207619,
    GO_OCCUTHAR_DOOR        = 208953,
    GO_ALIZABAL_DOOR        = 209849
};

template<class AI>
CreatureAI* GetBaradinHoldAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(BHScriptName))
                return new AI(creature);
    return NULL;
}

#endif
