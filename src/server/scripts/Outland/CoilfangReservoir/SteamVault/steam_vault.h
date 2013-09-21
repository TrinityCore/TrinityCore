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

#ifndef DEF_STEAM_VAULT_H
#define DEF_STEAM_VAULT_H

#define SteamVaultScriptName "instance_steam_vault"

uint32 const EncounterCount = 3;

enum DataTypes
{
    DATA_HYDROMANCER_THESPIA        = 0,
    DATA_MEKGINEER_STEAMRIGGER      = 1,
    DATA_WARLORD_KALITHRESH         = 2,
    DATA_DISTILLER                  = 3
};

enum CreatureIds
{
    NPC_HYDROMANCER_THESPIA         = 17797,
    NPC_MEKGINEER_STEAMRIGGER       = 17796,
    NPC_WARLORD_KALITHRESH          = 17798
};

enum GameObjectIds
{
    GO_MAIN_CHAMBERS_DOOR           = 183049,
    GO_ACCESS_PANEL_HYDRO           = 184125,
    GO_ACCESS_PANEL_MEK             = 184126
};

template<class AI>
AI* GetSteamVaultAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, SteamVaultScriptName);
}

#endif
