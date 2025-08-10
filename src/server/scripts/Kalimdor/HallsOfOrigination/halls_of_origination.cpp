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

#include "halls_of_origination.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"

 // 207669 - The Maker's Lift Controller
struct go_hoo_the_makers_lift_controller : public GameObjectAI
{
    go_hoo_the_makers_lift_controller(GameObject* go) : GameObjectAI(go), _instance(nullptr) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        ClearGossipMenuFor(player);
        player->PlayerTalkClass->SendCloseGossip();

        if (GameObject* elevator = _instance->GetGameObject(DATA_LIFT_OF_THE_MAKERS))
            elevator->SetGoState(GOState(GO_STATE_TRANSPORT_ACTIVE + gossipListId));

        return false;
    }
private:
    InstanceScript* _instance;
};

void AddSC_halls_of_origination()
{
    RegisterHallsOfOriginationGameObjectAI(go_hoo_the_makers_lift_controller);
}
