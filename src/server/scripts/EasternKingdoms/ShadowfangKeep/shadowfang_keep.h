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

#ifndef DEF_SHADOWFANG_H
#define DEF_SHADOWFANG_H

#include "CreatureAIImpl.h"

#define SFKScriptName "instance_shadowfang_keep"
#define DataHeader "SK"

enum SKDataTypes
{
    TYPE_FREE_NPC               = 1,
    TYPE_RETHILGORE             = 2,
    TYPE_FENRUS                 = 3,
    TYPE_NANDOS                 = 4,
    BOSS_ARUGAL                 = 5,
    DATA_APOTHECARY_HUMMEL      = 6,
    DATA_SPAWN_VALENTINE_ADDS   = 7
};

enum SKCreatures
{
    NPC_ASH                             = 3850,
    NPC_ADA                             = 3849,
    NPC_ARCHMAGE_ARUGAL                 = 4275,
    NPC_ARUGAL_VOIDWALKER               = 4627,
    NPC_DND_CRAZED_APOTHECARY_GENERATOR = 36212
};

enum SKGameObjects
{
    GO_COURTYARD_DOOR   = 18895, //door to open when talking to NPC's
    GO_SORCERER_DOOR    = 18972, //door to open when Fenrus the Devourer
    GO_ARUGAL_DOOR      = 18971  //door to open when Wolf Master Nandos
};

template <class AI, class T>
inline AI* GetShadowfangKeepAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SFKScriptName);
}

#endif
