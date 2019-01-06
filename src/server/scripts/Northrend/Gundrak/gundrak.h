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

#ifndef GUNDRAK_H_
#define GUNDRAK_H_

#include "CreatureAIImpl.h"

#define GundrakScriptName "instance_gundrak"
#define DataHeader "GD"

uint32 const EncounterCount = 5;

enum GDDataTypes
{
    // Encounter Ids // Encounter States // Boss GUIDs
    DATA_SLAD_RAN                    = 0,
    DATA_DRAKKARI_COLOSSUS           = 1,
    DATA_MOORABI                     = 2,
    DATA_GAL_DARAH                   = 3,
    DATA_ECK_THE_FEROCIOUS           = 4,

    // Additional Objects
    DATA_SLAD_RAN_ALTAR              = 5,
    DATA_DRAKKARI_COLOSSUS_ALTAR     = 6,
    DATA_MOORABI_ALTAR               = 7,

    DATA_SLAD_RAN_STATUE             = 8,
    DATA_DRAKKARI_COLOSSUS_STATUE    = 9,
    DATA_MOORABI_STATUE              = 10,
    DATA_GAL_DARAH_STATUE            = 11,

    DATA_TRAPDOOR                    = 12,
    DATA_COLLISION                   = 13,
    DATA_BRIDGE                      = 14,

    DATA_STATUE_ACTIVATE             = 15,
};

enum GDCreatureIds
{
    NPC_SLAD_RAN                     = 29304,
    NPC_MOORABI                      = 29305,
    NPC_GAL_DARAH                    = 29306,
    NPC_DRAKKARI_COLOSSUS            = 29307,
    NPC_RUIN_DWELLER                 = 29920,
    NPC_ECK_THE_FEROCIOUS            = 29932,
    NPC_ALTAR_TRIGGER                = 30298,
    NPC_RHINO_SPIRIT                 = 29791
};

enum GDGameObjectIds
{
    GO_SLAD_RAN_ALTAR                = 192518,
    GO_MOORABI_ALTAR                 = 192519,
    GO_DRAKKARI_COLOSSUS_ALTAR       = 192520,
    GO_SLAD_RAN_STATUE               = 192564,
    GO_MOORABI_STATUE                = 192565,
    GO_GAL_DARAH_STATUE              = 192566,
    GO_DRAKKARI_COLOSSUS_STATUE      = 192567,
    GO_ECK_THE_FEROCIOUS_DOOR        = 192632,
    GO_ECK_THE_FEROCIOUS_DOOR_BEHIND = 192569,
    GO_GAL_DARAH_DOOR_1              = 193208,
    GO_GAL_DARAH_DOOR_2              = 193209,
    GO_GAL_DARAH_DOOR_3              = 192568,
    GO_TRAPDOOR                      = 193188,
    GO_COLLISION                     = 192633,
};

enum GDSpellIds
{
    SPELL_FIRE_BEAM_MAMMOTH          = 57068,
    SPELL_FIRE_BEAM_SNAKE            = 57071,
    SPELL_FIRE_BEAM_ELEMENTAL        = 57072
};

enum GDInstanceMisc
{
    TIMER_STATUE_ACTIVATION          = 3500
};

template <class AI, class T>
inline AI* GetGundrakAI(T* obj)
{
    return GetInstanceAI<AI>(obj, GundrakScriptName);
}

#endif // GUNDRAK_H_
