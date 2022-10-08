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

#include "Creature.h"
#include "GameObject.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SceneMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "PhasingHandler.h"

enum
{
    QUEST_BY_ANY_MEANS = 41121,
    DATA_ALTURAS_START_EVENT = 27,
};

class zone_special_violet_hold : public PlayerScript {
public:
    zone_special_violet_hold() : PlayerScript("zone_special_violet_hold") {}

    uint32 checkTimer = 1000;
    bool _eventStarted = false;

    void OnUpdate(Player* player, uint32 diff) override
    {
        if (checkTimer <= diff)
        {
            if (player->getClass() == CLASS_DEMON_HUNTER && player->GetMapId() == 1494 &&
                player->GetQuestStatus(QUEST_BY_ANY_MEANS) == QUEST_STATUS_INCOMPLETE && !_eventStarted) {
                if (Creature* creature = player->FindNearestCreature(99473, 10.0f)) {
                    creature->GetAI()->SetData(DATA_ALTURAS_START_EVENT, DATA_ALTURAS_START_EVENT);
                    _eventStarted = true;
                }
            }
            checkTimer = 1000;
        }
        else checkTimer -= diff;
    }
};

class go_violethold_exit_portal : public GameObjectScript
{
public:
    go_violethold_exit_portal() : GameObjectScript("go_violethold_exit_portal")
    {
        checkTimer = 1000;
    }

    uint32 checkTimer;

    void OnUpdate(GameObject* p_Object, uint32 diff) override
    {
        if (checkTimer < diff)
        {
            checkTimer -= diff;
            return;
        }

        checkTimer = 1000;

        std::list<Player*> playerList;
        GetPlayerListInGrid(playerList, p_Object, 2.0f);

        for (Player* player : playerList)
            player->TeleportTo(1220, -953.287f, 4334.03f, 740.184f, 0.307976f);
    }
};

class npc_warden_alturas_vh : public CreatureScript
{
public:
    npc_warden_alturas_vh() : CreatureScript("npc_warden_alturas_vh") { }

    enum {
        TEXT_LOWER_BARRIER = 0,
        TEXT_OPEN_CELL = 1,
        TEXT_MEET_TALDATH = 2,
        TEXT_WERE_NEVER_HERE = 3,
        EVENT_MOVE_TO_CIRCLE = 11,
        EVENT_ASK_TO_LOWER_BARRIER = 12,
        EVENT_MOVE_FURTHER = 13,
        EVENT_MOVE_FURTHER_1 = 14,
        EVENT_MOVE_FURTHER_2 = 15,
        EVENT_MOVE_FURTHER_3 = 16,
        EVENT_MOVE_FURTHER_4 = 17,
        EVENT_MOVE_FURTHER_5 = 18,
        EVENT_MEET_TALDATH = 19,
        EVENT_SAY_GOODBYE = 20,
        EVENT_CAST_TELEPORT = 21,
    };

    struct npc_warden_alturas_vh_AI : public ScriptedAI
    {
        npc_warden_alturas_vh_AI(Creature* creature) : ScriptedAI(creature) {
            Initialize();
        }

        void Reset() override
        {
            _events.Reset();
        }

        void Initialize() {}

        void UpdateAI(uint32 diff) override
        {
            UpdateVictim();
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MOVE_TO_CIRCLE: {
                    _events.ScheduleEvent(EVENT_ASK_TO_LOWER_BARRIER, 7000);
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(1, 1305.759f, -263.837f, 44.169f);
                    break;
                }
                case EVENT_ASK_TO_LOWER_BARRIER: {
                    _events.ScheduleEvent(EVENT_MOVE_FURTHER, 8000);
                    Talk(TEXT_LOWER_BARRIER, me->GetOwner());
                    break;
                }
                case EVENT_MOVE_FURTHER: {
                    _events.ScheduleEvent(EVENT_MOVE_FURTHER_1, 5000);
                    Talk(TEXT_OPEN_CELL, me->GetOwner());
                    me->SetWalk(false);
                    me->GetMotionMaster()->MovePoint(2, 1337.645f, -263.426f, 38.656f);
                    break;
                }
                case EVENT_MOVE_FURTHER_1: {
                    _events.ScheduleEvent(EVENT_MOVE_FURTHER_2, 6000);
                    Talk(TEXT_OPEN_CELL, me->GetOwner());
                    me->SetOrientation(0.01502f);
                    me->GetMotionMaster()->MovePoint(3, 1382.611f, -263.272f, 43.333f);
                    break;
                }
                case EVENT_MOVE_FURTHER_2: {
                    _events.ScheduleEvent(EVENT_MOVE_FURTHER_3, 2000);
                    me->GetMotionMaster()->MovePoint(4, 1390.999f, -250.864f, 48.092f);
                    break;
                }
                case EVENT_MOVE_FURTHER_3: {
                    _events.ScheduleEvent(EVENT_MOVE_FURTHER_4, 1500);
                    me->GetMotionMaster()->MovePoint(5, 1399.311f, -246.174f, 52.416f);
                    break;
                }
                case EVENT_MOVE_FURTHER_4: {
                    _events.ScheduleEvent(EVENT_MOVE_FURTHER_5, 1000);
                    me->GetMotionMaster()->MovePoint(6, 1401.761f, -245.726f, 52.420f);
                    break;
                }
                case EVENT_MOVE_FURTHER_5: {
                    _events.ScheduleEvent(EVENT_MEET_TALDATH, 9000);
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(7, 1414.849f, -263.256f, 52.421f);
                    break;
                }
                case EVENT_MEET_TALDATH: {
                    _events.ScheduleEvent(EVENT_SAY_GOODBYE, 7000);
                    Talk(TEXT_MEET_TALDATH, me->GetOwner());
                    break;
                }
                case EVENT_SAY_GOODBYE: {
                    _events.ScheduleEvent(EVENT_CAST_TELEPORT, 2000);
                    Talk(TEXT_WERE_NEVER_HERE, me->GetOwner());
                    break;
                }
                case EVENT_CAST_TELEPORT: {
                    me->CastSpell(me, 52096, true); // cosmetic-teleport-effect
                    me->DespawnOrUnsummon();
                    break;
                }
                default:
                    break;
                }
            }
            // no melee attacks
        }

        void SetData(uint32 id, uint32 /*value*/) override
        {
            switch (id)
            {
                case DATA_ALTURAS_START_EVENT: {
                    _events.ScheduleEvent(EVENT_MOVE_TO_CIRCLE, 1000);
                    break;
                }
            }
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_warden_alturas_vh_AI(creature);
    }
};

void AddSC_scenario_the_violet_hold_dh()
{
    new zone_special_violet_hold();
    new go_violethold_exit_portal();
    new npc_warden_alturas_vh();
}
