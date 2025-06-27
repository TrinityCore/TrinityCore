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

#ifndef DEF_SUNKEN_TEMPLE_H
#define DEF_SUNKEN_TEMPLE_H

#include "CreatureAIImpl.h"

#define STScriptName "instance_sunken_temple"
#define DataHeader "ST"

enum STBossIds
{
    BOSS_AVATAR_OF_HAKKAR       = 0,
    BOSS_JAMMALAN_THE_PROPHET   = 1,
    BOSS_DREAMSCYTHE            = 2,
    BOSS_WEAVER                 = 3,
    BOSS_MORPHAZ                = 4,
    BOSS_HAZZAS                 = 5,
    BOSS_SHADE_OF_ERANIKUS      = 6,
    BOSS_ATALALARION            = 7,
    BOSS_EVENT_ELITE_TROLLS     = 8,

    MAX_ENCOUNTER
};

enum STCreatureIds
{
    NPC_AVATAR_OF_HAKKAR        = 8443,
    NPC_JAMMALAN_THE_PROPHET    = 5710,
    NPC_DREAMSCYTHE             = 5721,
    NPC_WEAVER                  = 5720,
    NPC_MORPHAZ                 = 5719,
    NPC_HAZZAS                  = 5722,
    NPC_SHADE_OF_ERANIKUS       = 5709,
    NPC_ATALALARION             = 8580,
    NPC_ZOLO                    = 5712,
    NPC_GASHER                  = 5713,
    NPC_LORO                    = 5714,
    NPC_HUKKU                   = 5715,
    NPC_ZUL_LOR                 = 5716,
    NPC_MIJAN                   = 5717,
};

enum STGameObjectIds
{
    GO_ATALAI_STATUE1 = 148830,
    GO_ATALAI_STATUE2 = 148831,
    GO_ATALAI_STATUE3 = 148832,
    GO_ATALAI_STATUE4 = 148833,
    GO_ATALAI_STATUE5 = 148834,
    GO_ATALAI_STATUE6 = 148835,
    GO_ATALAI_LIGHT1  = 148883,
    GO_ATALAI_LIGHT2  = 148937,
    GO_FORCEFIELD     = 149431,
};

enum STEvents
{
    EVENT_STATE = 1
};

enum STShareSpells
{
    SPELL_SUPPRESSION      = 12623,
    SPELL_GREEN_CHANNELING = 13540
};

template <class AI, class T>
inline AI* GetSunkenTempleAI(T* obj)
{
    return GetInstanceAI<AI>(obj, STScriptName);
}

#endif
