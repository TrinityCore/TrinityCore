/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_BLACKROCKCAVERNS_H
#define DEF_BLACKROCKCAVERNS_H

#define BCScriptName "instance_blackrock_caverns"

uint32 const EncounterCount             = 5;

enum DataTypes
{
    DATA_ROMOGG_BONECRUSHER             = 0,
    DATA_CORLA                          = 1,
    DATA_KARSH_STEELBENDER              = 2,
    DATA_BEAUTY                         = 3,
    DATA_ASCENDANT_LORD_OBSIDIUS        = 4
};

enum CreatureIds
{
    NPC_TWILIGHT_FLAME_CALLER           = 39708,
    NPC_RAZ_THE_CRAZED                  = 39670,
    NPC_ROMOGG_BONECRUSHER              = 39665
};

template<class AI>
CreatureAI* GetBlackrockCavernsAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(BCScriptName))
                return new AI(creature);
    return NULL;
}

#endif
