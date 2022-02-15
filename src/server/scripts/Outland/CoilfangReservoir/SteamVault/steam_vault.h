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

#ifndef DEF_STEAM_VAULT_H
#define DEF_STEAM_VAULT_H

#include "CreatureAIImpl.h"

#define SteamVaultScriptName "instance_steam_vault"
#define DataHeader "SV"

uint32 const EncounterCount = 3;

enum SVDataTypes
{
    DATA_HYDROMANCER_THESPIA   = 0,
    DATA_MEKGINEER_STEAMRIGGER = 1,
    DATA_WARLORD_KALITHRESH    = 2,

    // Additional Data
    DATA_DISTILLER              = 3,
    DATA_ACCESS_PANEL_HYDRO     = 4,
    DATA_ACCESS_PANEL_MEK       = 5,
    DATA_DOOR_CONTROLLER        = 6,
    DATA_MAIN_DOOR              = 7
};

enum SVCreatureIds
{
    NPC_HYDROMANCER_THESPIA      = 17797,
    NPC_MEKGINEER_STEAMRIGGER    = 17796,
    NPC_WARLORD_KALITHRESH       = 17798,
    NPC_COILFANG_DOOR_CONTROLLER = 20926
};

enum SVGameObjectIds
{
    GO_MAIN_CHAMBERS_DOOR = 183049,
    GO_ACCESS_PANEL_HYDRO = 184125,
    GO_ACCESS_PANEL_MEK   = 184126
};

enum SVMisc
{
    ACTION_OPEN_DOOR               = 1,
    CONTROLLER_TEXT_ACESS_USED     = 0,
    CONTROLLER_TEXT_MAIN_DOOR_OPEN = 1
};

template <class AI, class T>
inline AI* GetSteamVaultAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SteamVaultScriptName);
}

#define RegisterSteamVaultAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSteamVaultAI)

#endif
