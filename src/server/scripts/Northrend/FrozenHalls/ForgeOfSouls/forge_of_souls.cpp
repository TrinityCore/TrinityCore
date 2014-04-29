/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "forge_of_souls.h"
#include "Player.h"

enum Events
{
    EVENT_NONE,

    // Jaina/Sylvanas Intro
    EVENT_INTRO_1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,
    EVENT_INTRO_4,
    EVENT_INTRO_5,
    EVENT_INTRO_6,
    EVENT_INTRO_7,
    EVENT_INTRO_8,
};

/****************************************SYLVANAS************************************/
#define GOSSIP_SYLVANAS_ITEM    "What would you have of me, Banshee Queen?"
#define GOSSIP_JAINA_ITEM       "What would you have of me, my lady?"

enum Yells
{
    SAY_JAINA_INTRO_1                           = 0,
    SAY_JAINA_INTRO_2                           = 1,
    SAY_JAINA_INTRO_3                           = 2,
    SAY_JAINA_INTRO_4                           = 3,
    SAY_JAINA_INTRO_5                           = 4,
    SAY_JAINA_INTRO_6                           = 5,
    SAY_JAINA_INTRO_7                           = 6,
    SAY_JAINA_INTRO_8                           = 7,

    SAY_SYLVANAS_INTRO_1                        = 0,
    SAY_SYLVANAS_INTRO_2                        = 1,
    SAY_SYLVANAS_INTRO_3                        = 2,
    SAY_SYLVANAS_INTRO_4                        = 3,
    SAY_SYLVANAS_INTRO_5                        = 4,
    SAY_SYLVANAS_INTRO_6                        = 5,
};

enum Misc
{
    GOSSIP_SPEECHINTRO                           = 13525,
    ACTION_INTRO,
};

enum Phase
{
    PHASE_NORMAL,
    PHASE_INTRO,
};

class npc_sylvanas_fos : public CreatureScript
{
public:
    npc_sylvanas_fos() : CreatureScript("npc_sylvanas_fos") { }

    struct npc_sylvanas_fosAI : public ScriptedAI
    {
        npc_sylvanas_fosAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        InstanceScript* instance;

        EventMap events;
        Phase phase;

        void Reset() override
        {
            events.Reset();
            phase = PHASE_NORMAL;
        }

        void DoAction(int32 actionId) override
        {
            switch (actionId)
            {
                case ACTION_INTRO:
                {
                    phase = PHASE_INTRO;
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    events.Reset();
                    events.ScheduleEvent(EVENT_INTRO_1, 1000);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (phase == PHASE_INTRO)
            {
                events.Update(diff);
                switch (events.ExecuteEvent())
                {
                    case EVENT_INTRO_1:
                        Talk(SAY_SYLVANAS_INTRO_1);
                        events.ScheduleEvent(EVENT_INTRO_2, 11500);
                        break;

                    case EVENT_INTRO_2:
                        Talk(SAY_SYLVANAS_INTRO_2);
                        events.ScheduleEvent(EVENT_INTRO_3, 10500);
                        break;

                    case EVENT_INTRO_3:
                        Talk(SAY_SYLVANAS_INTRO_3);
                        events.ScheduleEvent(EVENT_INTRO_4, 9500);
                        break;

                    case EVENT_INTRO_4:
                        Talk(SAY_SYLVANAS_INTRO_4);
                        events.ScheduleEvent(EVENT_INTRO_5, 10500);
                        break;

                    case EVENT_INTRO_5:
                        Talk(SAY_SYLVANAS_INTRO_5);
                        events.ScheduleEvent(EVENT_INTRO_6, 9500);
                        break;

                    case EVENT_INTRO_6:
                        Talk(SAY_SYLVANAS_INTRO_6);
                        // End of Intro
                        phase = PHASE_NORMAL;
                        break;
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);
            DoMeleeAttackIfReady();
        }
    };

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->GetEntry() == NPC_JAINA_PART1)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_JAINA_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        else
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SYLVANAS_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();

                if (creature->AI())
                    creature->AI()->DoAction(ACTION_INTRO);
                break;
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_sylvanas_fosAI>(creature);
    }
};

class npc_jaina_fos : public CreatureScript
{
public:
    npc_jaina_fos() : CreatureScript("npc_jaina_fos") { }

    struct npc_jaina_fosAI: public ScriptedAI
    {
        npc_jaina_fosAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }

        InstanceScript* instance;

        EventMap events;
        Phase phase;

        void Reset() override
        {
            events.Reset();
            phase = PHASE_NORMAL;
        }

        void DoAction(int32 actionId) override
        {
            switch (actionId)
            {
                case ACTION_INTRO:
                {
                    phase = PHASE_INTRO;
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    events.Reset();
                    events.ScheduleEvent(EVENT_INTRO_1, 1000);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (phase == PHASE_INTRO)
            {
                events.Update(diff);
                switch (events.ExecuteEvent())
                {
                    case EVENT_INTRO_1:
                        Talk(SAY_JAINA_INTRO_1);
                        events.ScheduleEvent(EVENT_INTRO_2, 8000);
                        break;

                    case EVENT_INTRO_2:
                        Talk(SAY_JAINA_INTRO_2);
                        events.ScheduleEvent(EVENT_INTRO_3, 8500);
                        break;

                    case EVENT_INTRO_3:
                        Talk(SAY_JAINA_INTRO_3);
                        events.ScheduleEvent(EVENT_INTRO_4, 8000);
                        break;

                    case EVENT_INTRO_4:
                        Talk(SAY_JAINA_INTRO_4);
                        events.ScheduleEvent(EVENT_INTRO_5, 10000);
                        break;

                    case EVENT_INTRO_5:
                        Talk(SAY_JAINA_INTRO_5);
                        events.ScheduleEvent(EVENT_INTRO_6, 8000);
                        break;

                    case EVENT_INTRO_6:
                        Talk(SAY_JAINA_INTRO_6);
                        events.ScheduleEvent(EVENT_INTRO_7, 12000);
                        break;

                    case EVENT_INTRO_7:
                        Talk(SAY_JAINA_INTRO_7);
                        events.ScheduleEvent(EVENT_INTRO_8, 8000);
                        break;

                    case EVENT_INTRO_8:
                        Talk(SAY_JAINA_INTRO_8);
                        // End of Intro
                        phase = PHASE_NORMAL;
                        break;
                }
            }

            //Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            DoMeleeAttackIfReady();
        }
    };

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->GetEntry() == NPC_JAINA_PART1)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_JAINA_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        else
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SYLVANAS_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();

                if (creature->AI())
                    creature->AI()->DoAction(ACTION_INTRO);
                break;
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_jaina_fosAI>(creature);
    }
};

void AddSC_forge_of_souls()
{
    new npc_sylvanas_fos();
    new npc_jaina_fos();
}
