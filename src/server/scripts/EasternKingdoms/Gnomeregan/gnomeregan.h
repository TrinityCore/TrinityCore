/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#define MAX_GNOME_FACES 6

enum GNOGameObjectIds
{
    GO_CAVE_IN_LEFT     = 146085,
    GO_CAVE_IN_RIGHT    = 146086,
    GO_RED_ROCKET       = 103820,

    //Mekgineer Thermaplugg
    GO_GNOME_FACE_01    = 142211,
    GO_GNOME_FACE_02    = 142210,
    GO_GNOME_FACE_03    = 142209,
    GO_GNOME_FACE_04    = 142208,
    GO_GNOME_FACE_05    = 142213,
    GO_GNOME_FACE_06    = 142212,

    GO_BUTTON_01        = 142214,
    GO_BUTTON_02        = 142215,
    GO_BUTTON_03        = 142216,
    GO_BUTTON_04        = 142217,
    GO_BUTTON_05        = 142218,
    GO_BUTTON_06        = 142219,

    GO_THE_FINAL_CHAMBER = 142207
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
    NPC_MEKGINEER_THERMAPLUGG       = 7800,
    NPC_WALKING_BOMB                = 7915
};

enum GNOData
{
    DATA_BLASTMASTER_EVENT = 0,
    DATA_VICIOUS_FALLOUT   = 1,
    DATA_ELECTROCUTIONER   = 2,
    DATA_CROWD_PUMMELER    = 3,
    DATA_THERMAPLUGG       = 4,
    MAX_ENCOUNTER,

    // Extra
    DATA_GO_CAVE_IN_LEFT,
    DATA_GO_CAVE_IN_RIGHT,
    DATA_NPC_BLASTMASTER_EMI_SHORTFUSE,
    DATA_THE_FINAL_CHAMBER,
    DATA_FACE_01,
    DATA_FACE_02,
    DATA_FACE_03,
    DATA_FACE_04,
    DATA_FACE_05,
    DATA_FACE_06
};

template <class AI, class T>
inline AI* GetGnomereganAI(T* obj)
{
    return GetInstanceAI<AI>(obj, GNOScriptName);
}

#endif
