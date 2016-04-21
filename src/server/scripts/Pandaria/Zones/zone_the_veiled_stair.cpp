/*
* Copyright (C) 2011-2015 Project SkyFire <http://www.projectskyfire.org/>
* Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2005-2015 MaNGOS <http://getmangos.com/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
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

enum Events
{
    EVENT_NONE,
    EVENT_START,
    EVENT_DRINK_REQUEST,
    EVENT_TALK_0,
    EVENT_TALK_1,
    EVENT_TALK_2,
    EVENT_TALK_3,
    EVENT_TALK_4,
    EVENT_TALK_5,
    EVENT_TALK_6,
    EVENT_TALK_7,
    EVENT_TALK_8,
    EVENT_TALK_9,
    EVENT_TALK_10,
    EVENT_TALK_11,
    EVENT_TALK_12,
    EVENT_END
};

enum eNum
{
    ACTION_START_EVENT,
    ACTION_WALK_1,
    ACTION_WALK_2,
    ACTION_GO_HOME,

    QUEST_A_LEGEND_IN_THE_MAKING = 31454,
    NPC_THUN                     = 62917,
};

enum Says
{
    SAY_0,
    SAY_1,
    SAY_2,
    SAY_3,
    SAY_4,
    SAY_5,
    SAY_6,
    SAY_7,
    SAY_8,
    SAY_9,
    SAY_10,
    SAY_11,
    SAY_12,
    SAY_13,
    SAY_14,
    SAY_15
};

class tvs_black_prince : public CreatureScript
{
    public:
        tvs_black_prince() : CreatureScript("tvs_black_prince") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (creature->IsQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            if (player->GetQuestStatus(QUEST_A_LEGEND_IN_THE_MAKING) == QUEST_STATUS_INCOMPLETE)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Вот теперь можно выпить.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            player->PlayerTalkClass->SendGossipMenu(player->GetGossipTextId(creature), creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF+1)
            {
                player->CLOSE_GOSSIP_MENU();
                if (creature->AI())
                {
                    creature->AI()->SetGUID(player->GetGUID());
                    creature->AI()->DoAction(ACTION_START_EVENT);
                }
            }

            return true;
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new tvs_black_princeAI(creature);
        }

        struct tvs_black_princeAI : public ScriptedAI
        {
            tvs_black_princeAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;
            uint64 uiPlayerGUID;
            std::list<Player*> playerList;

            void Reset()
            {
                events.Reset();
                uiPlayerGUID = 0;
                me->SetWalk(true);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                me->GetMotionMaster()->MoveTargetedHome();
            }

            void DoAction(int32 actionId) override
            {
                switch (actionId)
                {
                    case ACTION_START_EVENT:
                        events.ScheduleEvent(EVENT_START, 0);
                        break;
                    case ACTION_WALK_1:
                        me->GetMotionMaster()->MovePoint(0, 826.767f, -170.001f, me->GetPositionZ());
                        break;
                    case ACTION_WALK_2:
                        me->GetMotionMaster()->MovePoint(0, 822.281f,-167.378f, me->GetPositionZ());
                        break;
                    case ACTION_GO_HOME:
                        me->GetMotionMaster()->MovePoint(0, me->GetHomePosition());
                        break;
                    default:
                        break;
                }
            }

            void SetGUID(uint64 uiGuid, int32 /*iId*/)
            {
                uiPlayerGUID = uiGuid;
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_START:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        Talk(SAY_0);
                        events.ScheduleEvent(EVENT_DRINK_REQUEST, 3 * IN_MILLISECONDS);
                        break;
                    case EVENT_DRINK_REQUEST:
                        if (Creature* thoon = me->SummonCreature(NPC_THUN, 824.738098f, -175.243927f, 415.224095f, 1.902595f, TEMPSUMMON_TIMED_DESPAWN, 50 * IN_MILLISECONDS))
                            me->SetFacingToObject(thoon);

                        Talk(SAY_1);
                        me->AI()->DoAction(ACTION_WALK_1);
                        events.ScheduleEvent(EVENT_TALK_0, 4 * IN_MILLISECONDS);
                        break;
                    case EVENT_TALK_0:
                        me->SetFacingTo(2.577323f);
                        Talk(SAY_2);
                        events.ScheduleEvent(EVENT_TALK_1, 6 * IN_MILLISECONDS);
                        break;
                    case EVENT_TALK_1:
                        Talk(SAY_3);
                        events.ScheduleEvent(EVENT_TALK_2, 15 * IN_MILLISECONDS);
                        break;
                        //here must be visual part part
                    case EVENT_TALK_2:
                        Talk(SAY_4);
                        events.ScheduleEvent(EVENT_TALK_3, 7 * IN_MILLISECONDS);
                        break;
                    case EVENT_TALK_3:
                        Talk(SAY_5);
                        if (Creature* thoon = me->FindNearestCreature(NPC_THUN, 20.0f))
                        {
                            thoon->SetWalk(true);
                            thoon->GetMotionMaster()->MovePoint(0, 825.229f, -172.467f, thoon->GetPositionZ());
                            thoon->SetFacingToObject(me);
                        }
                        events.ScheduleEvent(EVENT_TALK_4, 7 * IN_MILLISECONDS);
                        break;
                    case EVENT_TALK_4:
                        /*if (Creature* thoon = me->FindNearestCreature(NPC_THUN, 20.0f))
                        {
                            me->SetFacingToObject(thoon);
                            Talk(SAY_6);
                            thoon->SetFacingToObject(thoon->GetPlayer(*thoon, uiPlayerGUID));
                            thoon->GetMotionMaster()->MovePoint(0, 819.735f, -171.292f, thoon->GetPositionZ());
                        }*/
                        events.ScheduleEvent(EVENT_TALK_5, 6 * IN_MILLISECONDS);
                        break;
                    case EVENT_TALK_5:
                        me->SetFacingTo(2.577323f);
                        Talk(SAY_7);
                        events.ScheduleEvent(EVENT_TALK_6, 12 * IN_MILLISECONDS);
                        break;
                    case EVENT_TALK_6:
                        Talk(SAY_8);
                        events.ScheduleEvent(EVENT_TALK_7, 13 * IN_MILLISECONDS);
                        break;
                    case EVENT_TALK_7:
                        Talk(SAY_9);
                        events.ScheduleEvent(EVENT_TALK_8, 6 * IN_MILLISECONDS);
                        break;
                    case EVENT_TALK_8:
                        Talk(SAY_10);
                        events.ScheduleEvent(EVENT_TALK_9, 6 * IN_MILLISECONDS);
                        break;
                    case EVENT_TALK_9:
                        Talk(SAY_11);
                        events.ScheduleEvent(EVENT_TALK_10, 6 * IN_MILLISECONDS);
                        break;
                    case EVENT_TALK_10:
                        me->AI()->DoAction(ACTION_WALK_2);
                        /*if (Player* player = me->GetPlayer(*me, uiPlayerGUID))
                        {
                            //banner must be placed here
                            if (player->GetTeam() == ALLIANCE)
                                Talk(SAY_12);
                            else
                                Talk(SAY_13);
                        }*/
                        events.ScheduleEvent(EVENT_TALK_11, 8 * IN_MILLISECONDS);
                        break;
                    case EVENT_TALK_11:
                        Talk(SAY_14);
                        events.ScheduleEvent(EVENT_TALK_12, 9 * IN_MILLISECONDS);
                        break;
                    case EVENT_TALK_12:
                        me->AI()->DoAction(ACTION_GO_HOME);
                        Talk(SAY_15);
                        events.ScheduleEvent(EVENT_END, 6 * IN_MILLISECONDS);
                        break;
                    case EVENT_END:
                        GetPlayerListInGrid(playerList, me, 15.0f);
                        for (auto player: playerList)
                            player->KilledMonsterCredit(64649, GetGUID(0));

                        me->AI()->Reset();
                        break;
                    default:
                        break;
                }
            }
        };
};

void AddSC_the_veiled_stair()
{
    new tvs_black_prince();
}
