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

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"

#include <mutex>

enum PillowFight
{
    NPC_SLEEPY_DARK_IRON_WORKER = 14635,
    NPC_CHAMBERMAID_PILLACLENCHER = 14636
};

class event_dark_iron_rush : public WorldMapScript
{
public:
    event_dark_iron_rush() : WorldMapScript("event_dark_iron_rush", 0), duration(0), numWave(0), running(false) {}

    void OnUpdate(Map* map, uint32 diff) override
    {
        if (running && numWave < 3)
        {
            duration += diff;
            if (numWave == 0 && duration > 60000)
            {
                for (size_t i = 0; i < 10; i++)
                {
                    Position pos = { -6568.03f + frand(-5,5),-1306.73f + frand(-5,5),208.7f, frand(0.0f, 2.0f * (float)M_PI) };
                    TempSummon* summon = map->SummonCreature(NPC_SLEEPY_DARK_IRON_WORKER, pos, nullptr, 60000);
                    summon->SetTempSummonType(TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT);

                    if(i == 0)
                        summon->ToCreature()->AI()->Talk(0);
                }
                numWave++;
            }
            else if (numWave == 1 && duration > 180000)
            {
                for (size_t i = 0; i < 10; i++)
                {
                    Position pos = {-6483.42f + frand(-5,5), -1350.1f + frand(-5,5), 212.1f, frand(0.0f, 2.0f * (float)M_PI) };
                    TempSummon* summon = map->SummonCreature(NPC_SLEEPY_DARK_IRON_WORKER, pos, nullptr, 60000);
                    summon->SetTempSummonType(TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT);

                    if (i == 0)
                        summon->ToCreature()->AI()->Talk(1);
                }
                numWave++;
            }
            else if (numWave == 2 && duration > 300000)
            {
                Position pos = { -6545.88f, -1345.29f, 208.89f };
                TempSummon* summon = map->SummonCreature(NPC_CHAMBERMAID_PILLACLENCHER, pos, nullptr, 300000);
                summon->SetTempSummonType(TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT);
                numWave++;
                running = false;
            }
        }
    }

    void Trigger()
    {
        std::lock_guard<std::mutex> triggerGuard(triggerLock);
        if (!running)
        {
            running = true;
            duration = 0;
            numWave = 0;
        }
    }

    uint32_t duration;
    uint32_t numWave;
    bool running;

    std::mutex triggerLock;
};

static event_dark_iron_rush *edir_p = NULL;


class go_dark_iron_pillow : public GameObjectScript
{
public:
    go_dark_iron_pillow() : GameObjectScript("go_dark_iron_pillow") {}


    struct go_dark_iron_pillowAI : public GameObjectAI
    {
        go_dark_iron_pillowAI(GameObject* go) : GameObjectAI(go) {};

        bool GossipHello(Player* /*player*/) override
        {
            if (edir_p) edir_p->Trigger();

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
    edir_p = new event_dark_iron_rush();
}
