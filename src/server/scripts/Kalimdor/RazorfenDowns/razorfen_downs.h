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

#ifndef DEF_RAZORFEN_DOWNS_H
#define DEF_RAZORFEN_DOWNS_H

#include "CreatureAIImpl.h"

#define RFDScriptName "instance_razorfen_downs"
#define DataHeader "RFD"

uint32 const EncounterCount = 5;

enum RFDDataTypes
{
    // Main Bosses
    DATA_TUTEN_KASH                        = 0,
    DATA_MORDRESH_FIRE_EYE                 = 1,
    DATA_GLUTTON                           = 2,
    DATA_AMNENNAR_THE_COLD_BRINGER         = 3,
    // Events
    DATA_GONG                              = 4,
    DATA_WAVE                              = 5,
    DATA_EXTINGUISHING_THE_IDOL            = 6
};

enum RFDCreatureIds
{
    // Used in Tuten Kash summon event
    NPC_TOMB_FIEND                         = 7349,
    NPC_TOMB_REAVER                        = 7351,
    NPC_TUTEN_KASH                         = 7355,
    // Used for quest 3525 "Extinguishing the Idol"
    NPC_IDOL_ROOM_SPAWNER                  = 8611,
    NPC_WITHERED_BATTLE_BOAR               = 7333,
    NPC_DEATHS_HEAD_GEOMANCER              = 7335,
    NPC_WITHERED_QUILGUARD                 = 7329,
    NPC_PLAGUEMAW_THE_ROTTING              = 7356
};

enum RFDGameObjectIds
{
    // Used for Tuten Kash summon event
    GO_GONG                                = 148917,
    // Used for quest 3525 "Extinguishing the Idol"
    GO_IDOL_OVEN_FIRE                      = 151951,
    GO_IDOL_CUP_FIRE                       = 151952,
    GO_IDOL_MOUTH_FIRE                     = 151973,
    GO_BELNISTRASZS_BRAZIER                = 152097
};

template<typename AI>
inline AI* GetRazorfenDownsAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, RFDScriptName);
}

#endif
