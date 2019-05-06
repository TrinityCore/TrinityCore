/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef DEF_GNOMEREGAN_H
#define DEF_GNOMEREGAN_H

#include "CreatureAIImpl.h"

#define GNOScriptName "instance_gnomeregan"
#define DataHeader "GNO"

enum GNOGameObjectIds
{
    GO_CAVE_IN_LEFT     = 146085,
    GO_CAVE_IN_RIGHT    = 146086,
    GO_RED_ROCKET       = 103820
};

enum GNOCreatureIds
{
    NPC_BLASTMASTER_EMI_SHORTFUSE   = 7998,
    NPC_CAVERNDEEP_AMBUSHER         = 6207,
    NPC_GRUBBIS                     = 7361,
    NPC_VICIOUS_FALLOUT             = 7079,
    NPC_CHOMPER                     = 6215,
    NPC_ELECTROCUTIONER             = 6235,
    NPC_CROWD_PUMMELER              = 6229,
    NPC_MEKGINEER                   = 7800,
};

enum GNOData
{
    DATA_BLASTMASTER_EVENT = 0,
    DATA_VICIOUS_FALLOUT   = 1,
    DATA_ELECTROCUTIONER   = 2,
    DATA_CROWD_PUMMELER    = 3,
    DATA_THERMAPLUGG       = 4,

    MAX_ENCOUNTER
};

enum GNOData64
{
    DATA_GO_CAVE_IN_LEFT,
    DATA_GO_CAVE_IN_RIGHT,
    DATA_NPC_BASTMASTER_EMI_SHORTFUSE
};

template <class AI, class T>
inline AI* GetGnomereganAI(T* obj)
{
    return GetInstanceAI<AI>(obj, GNOScriptName);
}

#endif
