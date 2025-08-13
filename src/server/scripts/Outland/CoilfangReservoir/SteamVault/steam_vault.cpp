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

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "steam_vault.h"

// 184125, 184126 - Main Chambers Access Panel
struct go_main_chambers_access_panel : public GameObjectAI
{
    go_main_chambers_access_panel(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool OnGossipHello(Player* /*player*/) override
    {
        if (Creature* controller = _instance->GetCreature(DATA_DOOR_CONTROLLER))
            controller->AI()->Talk(CONTROLLER_TEXT_ACESS_USED);

        _instance->SetData(ACTION_OPEN_DOOR, 0);
        me->SetFlag(GO_FLAG_NOT_SELECTABLE);
        me->SetGoState(GO_STATE_ACTIVE);
        return true;
    }

private:
    InstanceScript* _instance;
};

void AddSC_steam_vault()
{
    RegisterSteamVaultGameObjectAI(go_main_chambers_access_panel);
}
