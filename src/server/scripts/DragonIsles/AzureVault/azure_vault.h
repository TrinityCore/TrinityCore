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

#ifndef DEF_AZURE_VAULT_H_
#define DEF_AZURE_VAULT_H_

#include "CreatureAIImpl.h"

#define DataHeader "AzureVault"
#define AVScriptName "instance_azure_vault"

uint32 const EncounterCount = 4;

enum AVDataTypes
{
    // Encounters
    DATA_LEYMOR             = 0,
    DATA_AZUREBLADE,
    DATA_TELASH_GREYWING,
    DATA_UMBRELSKUL,

    DATA_LEYMOR_INTRO_DONE
};

enum AVCreatureIds
{
    // Bosses
    BOSS_LEYMOR             = 186644,
    BOSS_AZUREBLADE         = 186739,
    BOSS_TELASH_GREYWING    = 199614,
    BOSS_UMBRELSKUL         = 186738,

    // Leymor
    NPC_ARCANE_TENDER       = 191164,
};

enum AVGameObjectIds
{
    GO_ARCANE_VAULTS_DOOR_LEYMOR_ENTRANCE       = 380536,
    GO_ARCANE_VAULTS_DOOR_LEYMOR_EXIT           = 377951
};

enum AVActionIds
{
    ACTION_FINISH_LEYMOR_INTRO  = 251501
};

template <class AI, class T>
inline AI* GetAzureVaultAI(T* obj)
{
    return GetInstanceAI<AI>(obj, AVScriptName);
}

#define RegisterAzureVaultCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetAzureVaultAI)

#endif
