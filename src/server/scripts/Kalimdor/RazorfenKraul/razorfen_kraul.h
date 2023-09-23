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

#ifndef DEF_RAZORFEN_KRAUL_H
#define DEF_RAZORFEN_KRAUL_H

#include "CreatureAIImpl.h"

#define RFKScriptName "instance_razorfen_kraul"
#define DataHeader "RFK"

enum RFKBossIds
{
    BOSS_HUNTER_BONETUSK            = 0,
    BOSS_ROOGUG                     = 1,
    BOSS_WARLORD_RAMTUSK            = 2,
    BOSS_GROYAT_THE_BLIND_HUNTER    = 3,
    BOSS_CHARLGA_RAZORFLANK         = 4,

    MAX_ENCOUNTER
};

enum RFKCreatureIds
{
    NPC_HUNTER_BONETUSK         = 75001,
    NPC_ROOGUG                  = 6168,
    NPC_WARLORD_RAMTUSK         = 74462,
    NPC_GROYAT_THE_BLIND_HUNTER = 75247,
    NPC_CHARLGA_RAZORFLANK      = 4421,
};

#define EVENT_WARD_KEEPER 1

template <class AI, class T>
inline AI* GetRazorfenKraulAI(T* obj)
{
    return GetInstanceAI<AI>(obj, RFKScriptName);
}

#endif
