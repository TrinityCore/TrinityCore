/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "Player.h"
#include "InstanceScript.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Conversation.h"
#include "ObjectMgr.h"
#include "eternal_palace.h"

DoorData const doorData[] =
{
    { GO_SIVARA_ENCOUNTER, DATA_COMMANDER_SIVARA, DOOR_TYPE_ROOM },
    { GO_SIVARA_LEFT, DATA_COMMANDER_SIVARA, DOOR_TYPE_PASSAGE },
    { GO_SIVARA_RIGHT, DATA_COMMANDER_SIVARA, DOOR_TYPE_PASSAGE },
    { GO_LADY_ASHVANE_ENCOUNTER, DATA_LADY_ASHVANE, DOOR_TYPE_ROOM },
};

struct instance_eternal_palace : public InstanceScript
{
    instance_eternal_palace(InstanceMap* map) : InstanceScript(map), intro_conv(false)
    {
        SetHeaders(DataHeader);
        SetBossNumber(EncounterCount);
    }

    void Initialize() override
    {
        LoadDoorData(doorData);
    }

    void OnPlayerEnter(Player* player) override
    {
        intro_conv = true;
        if (intro_conv == true)
        {
            intro_conv = false;
            //Conversation::CreateConversation(1000, player, player->GetPosition(), { player->GetGUID() });
        }
    }

private:
    bool intro_conv;
};

//329650 - Ashvane arcane wall
struct go_ashvane_arcane_wall : public GameObjectAI
{
    go_ashvane_arcane_wall(GameObject* go) : GameObjectAI(go) { }

    void Reset() override
    {
        go->GetScheduler().CancelAll();
        go->GetScheduler().Schedule(1s, [this] (TaskContext context)
        {
            if (InstanceScript* instance = go->GetInstanceScript())
            {
                if (instance->GetBossState(DATA_COMMANDER_SIVARA == DONE) && instance->GetBossState(DATA_BLACKWATER_BEHEMOTH == DONE) && instance->GetBossState(DATA_RADIANCE_OF_AZSHARA == DONE))
                    go->RemoveFromWorld();

                if (go->IsInWorld())
                    context.Repeat(1s);
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

enum Generic
{
    SPELL_AQUA_LANCE = 295799,
    SPELL_AQUA_LANCE_AT = 295808,
    SPELL_RAGE_OF_AZSHARA = 303944,
    SPELL_SKEWER = 295766,
    EVENT_AQUA_LANCE = 1,
    EVENT_RAGE_OF_AZSHARA,
    EVENT_SKEWER,
    SPEL_CONDUCTIVE_PULSE = 295822,
    EVENT_CONDUCTIVE_PULSE = 4,
    SPELL_SHOCKING_LIGHTNING = 295818,
    EVENT_SHOCKING_LIGHTNING = 5,
    SPELL_STOMP = 296691,
    EVENT_STOMP = 6,
};

//152311,152312,156133
struct npc_generic_ashvane : public ScriptedAI
{
    npc_generic_ashvane(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void EnterCombat(Unit* u) override
    {
        switch (me->GetEntry())
        {
        case NPC_ZANJIR_MYRMIDON:
             events.ScheduleEvent(EVENT_AQUA_LANCE, 1500);
             events.ScheduleEvent(EVENT_RAGE_OF_AZSHARA, 3000);
             events.ScheduleEvent(EVENT_SKEWER, 5000);
             break;

        case NPC_AZSHARI_WITCH:
             events.ScheduleEvent(EVENT_CONDUCTIVE_PULSE, 1500);
             events.ScheduleEvent(EVENT_RAGE_OF_AZSHARA, 3000);
             events.ScheduleEvent(EVENT_SHOCKING_LIGHTNING, 5000);
             break;

        case NPC_DREADCOIL_HULK:
             events.ScheduleEvent(EVENT_STOMP, 1500);
             events.ScheduleEvent(EVENT_RAGE_OF_AZSHARA, 3000);
             break;
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_AQUA_LANCE:
             DoCastRandom(SPELL_AQUA_LANCE, 100.0f);
             events.Repeat(10s);
             break;

        case EVENT_RAGE_OF_AZSHARA:
             DoCastAOE(SPELL_RAGE_OF_AZSHARA);
             break;

        case EVENT_SKEWER:
             DoCastVictim(SPELL_SKEWER);
             events.Repeat(5s);
             break;

        case EVENT_CONDUCTIVE_PULSE:
             DoCastAOE(SPEL_CONDUCTIVE_PULSE);
             events.Repeat(10s);
             break;

        case EVENT_SHOCKING_LIGHTNING:
             DoCastRandom(SPELL_SHOCKING_LIGHTNING, 100.0f);
             events.Repeat(15s);
             break;

        case EVENT_STOMP:
             DoCastAOE(SPELL_STOMP);
             events.Repeat(10s);
             break;
        }
    }

    void JustDied(Unit* u) override
    {
        switch (me->GetEntry())
        {
        case NPC_ZANJIR_MYRMIDON:
             if (GameObject* go = me->FindNearestGameObject(332142, 100.0f))
                go->RemoveFromWorld();
             break;

        case NPC_AZSHARI_WITCH:
             if (GameObject* go = me->FindNearestGameObject(332132, 100.0f))
                 go->RemoveFromWorld();
            break;

        case NPC_DREADCOIL_HULK:
             if (GameObject* go = me->FindNearestGameObject(332134, 100.0f))
                 go->RemoveFromWorld();
             break;
        }
    }
};

void AddSC_instance_eternal_palace()
{
    RegisterInstanceScript(instance_eternal_palace, 2164);
    RegisterGameObjectAI(go_ashvane_arcane_wall);
    RegisterCreatureAI(npc_generic_ashvane);
}
