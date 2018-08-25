/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "Player.h"
#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"

#include <mutex>

enum PillowFight
{
    NPC_SLEEPY_DARK_IRON_WORKER = 14635,
    NPC_CHAMBERMAID_PILLACLENCHER = 14636,
    GAMEOBJECT_DARK_IRON_PILLOW_EVENT_GENERATOR = 179829
};


static std::mutex triggerLock;
class go_dark_iron_pillow : public GameObjectScript
{
public:
    go_dark_iron_pillow() : GameObjectScript("go_dark_iron_pillow") {}


    struct go_dark_iron_pillowAI : public GameObjectAI
    {
        go_dark_iron_pillowAI(GameObject* go) : GameObjectAI(go) {};

        bool GossipHello(Player* player) override
        {
            std::lock_guard<std::mutex> triggerGuard(triggerLock);

            if (!player->FindNearestGameObject(GAMEOBJECT_DARK_IRON_PILLOW_EVENT_GENERATOR, 200.0f))
            {
                Position pos = { -6545.88f, -1345.29f, 208.89f };
                
                player->SummonGameObject(GAMEOBJECT_DARK_IRON_PILLOW_EVENT_GENERATOR, pos, QuaternionData(), 65000, GO_SUMMON_TIMED_DESPAWN);
            }

            return false;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_dark_iron_pillowAI(go);
    }
};

void AddSC_searing_gorge()
{
    new go_dark_iron_pillow();
}
