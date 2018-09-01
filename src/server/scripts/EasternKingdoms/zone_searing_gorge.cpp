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
#include "Creature.h"
#include "CreatureAI.h"
#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "EventMap.h"
#include "Random.h"
#include "TemporarySummon.h"
#include "MotionMaster.h"
#include "WaypointDefines.h"
#include <mutex>

enum PillowFight
{
    NPC_SLEEPY_DARK_IRON_WORKER = 14635,
    NPC_CHAMBERMAID_PILLACLENCHER = 14636,
    GAMEOBJECT_DARK_IRON_PILLOW_EVENT_GENERATOR = 179829,

    EVENT_WAVE_1 = 1,
    EVENT_WAVE_2 = 2,
    EVENT_CHAMBERMAID = 3
};

class go_dark_iron_pillow_event_generator : public GameObjectScript
{
public:
    go_dark_iron_pillow_event_generator() : GameObjectScript("go_dark_iron_pillow_event_generator") {}


    struct go_dark_iron_pillow_event_generatorAI : public GameObjectAI
    {
        go_dark_iron_pillow_event_generatorAI(GameObject* go) : GameObjectAI(go), owner(go) {};

        void InitializeAI() override
        {
            events.ScheduleEvent(EVENT_WAVE_1,      60000, 0, 0);
            events.ScheduleEvent(EVENT_WAVE_2,     180000, 0, 0);
            events.ScheduleEvent(EVENT_CHAMBERMAID,300000, 0, 0);
        }
        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);
            while(uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_WAVE_1:
                    for (size_t i = 0; i < 10; i++)
                    {
                        if (TempSummon* summon = owner->SummonCreature(NPC_SLEEPY_DARK_IRON_WORKER, -6568.03f, -1306.73f, 208.70f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000))
                        {
                            summon->ToCreature()->GetMotionMaster()->MovePath(NPC_SLEEPY_DARK_IRON_WORKER*100+i, true);
                            if (i == 0)
                                summon->ToCreature()->AI()->Talk(0);
                        }
                    }
                    break;
                case EVENT_WAVE_2:
                    for (size_t i = 0; i < 10; i++)
                    {
                        if (TempSummon* summon = owner->SummonCreature(NPC_SLEEPY_DARK_IRON_WORKER, -6481.22f, -1349.06f, 212.10f, 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 120000))
                        {
                            summon->ToCreature()->GetMotionMaster()->MovePath(NPC_SLEEPY_DARK_IRON_WORKER * 100+10+i, true);

                            if (i == 0)
                                summon->ToCreature()->AI()->Talk(1);
                        }
                    }
                    break;
                case EVENT_CHAMBERMAID:
                    owner->SummonCreature(NPC_CHAMBERMAID_PILLACLENCHER, -6545.88f, -1345.29f, 208.89f,0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 300000);
                    break;
                }
            }
        }

        EventMap events;
        GameObject *owner;
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_dark_iron_pillow_event_generatorAI(go);
    }
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
                
                if(GameObject *go = player->SummonGameObject(GAMEOBJECT_DARK_IRON_PILLOW_EVENT_GENERATOR, pos, QuaternionData(), 0, GO_SUMMON_TIMED_DESPAWN))
                    go->DespawnOrUnsummon(65000ms);
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
    new go_dark_iron_pillow_event_generator();
}
