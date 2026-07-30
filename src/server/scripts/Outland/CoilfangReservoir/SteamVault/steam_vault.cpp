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

enum MainChambersAccessPanelMisc
{
    EMOTE_PANEL_USED             = 0,
    EMOTE_MAIN_DOOR_OPENS        = 1
};

// 184125, 184126 - Main Chambers Access Panel
struct go_main_chambers_access_panel : public GameObjectAI
{
    go_main_chambers_access_panel(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool OnGossipHello(Player* /*player*/) override
    {
        me->ActivateObject(GameObjectActions(GameObjectActions::MakeInert));

        if (Creature* controller = _instance->GetCreature(DATA_DOOR_CONTROLLER))
            controller->AI()->Talk(EMOTE_PANEL_USED);

        if (_instance->GetBossState(DATA_HYDROMANCER_THESPIA) == DONE && _instance->GetBossState(DATA_MEKGINEER_STEAMRIGGER) == DONE)
        {
            if (Creature* controller = _instance->GetCreature(DATA_DOOR_CONTROLLER))
                controller->AI()->Talk(EMOTE_MAIN_DOOR_OPENS);

            if (GameObject* go = _instance->GetGameObject(DATA_MAIN_CHAMBERS_DOOR))
            {
                _instance->HandleGameObject(ObjectGuid::Empty, true, go);
                go->ActivateObject(GameObjectActions(GameObjectActions::MakeInert));
            }
        }

        return false;
    }

private:
    InstanceScript* _instance;
};

void AddSC_steam_vault()
{
    RegisterSteamVaultGameObjectAI(go_main_chambers_access_panel);
}
