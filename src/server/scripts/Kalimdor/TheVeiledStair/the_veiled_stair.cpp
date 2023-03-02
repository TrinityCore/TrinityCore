///*
// * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
// * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
// * Copyright 2023 AzgathCore
// *
//   * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "ScriptedGossip.h"
//#include "ScriptedEscortAI.h"
//#include "DB2Stores.h"
//#include "AchievementMgr.h"
//#include "the_veiled_stair.h"
//
//
//// 64616 - Wrathion
//class npc_wrathion : public CreatureScript
//{
//    public:
//        npc_wrathion() : CreatureScript("npc_wrathion") {}
//
//        bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest)
//        {
//            if (quest->GetQuestId() == QUEST_A_LEGEND_IN_THE_MAKING)
//            {
//                if (player->GetTeam() == ALLIANCE)
//                {
//                    player->KilledMonsterCredit(LEGEND_MAKING_KILL_CREDIT);
//                }
//
//                else
//                {
//                    player->KilledMonsterCredit(LEGEND_MAKING_KILL_CREDIT);
//                }
//                    return true;
//            }
//
//            return true;
//        }
//};
//
//// 64822 - Wrathion
//class npc_wrathion_mason : public CreatureScript
//{
//    public:
//        npc_wrathion_mason() : CreatureScript("npc_wrathion_mason") {}
//
//        bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 /*opt*/)
//        {
//            if (quest->GetQuestId() == 31482)
//            {
//                if (creature->IsQuestGiver() && creature->AI())
//                {
//                    creature->DespawnOrUnsummon();
//
//                    if (AchievementEntry const* AchievWC = sAchievementStore.LookupEntry(7533)) // Chapter I: Trial of the Black Prince
//                        player->CompletedAchievement(AchievWC);
//                }
//            }
//            return true;
//        }
//
//        struct npc_wrathion_masonAI : public EscortAI
//        {
//            npc_wrathion_masonAI(Creature* creature) : EscortAI(creature)
//            {
//                playerGUID = ObjectGuid::Empty;
//            }
//
//            EventMap events;
//            ObjectGuid playerGUID;
//
//            void Reset() override
//            {
//                events.Reset();
//            }
//
//            void IsSummonedBy(Unit* summoner) override
//            {
//                if (Player* player = summoner->ToPlayer())
//                {
//                    if (player->GetQuestStatus(31482) == QUEST_STATUS_INCOMPLETE)
//                    {
//                        SetDespawnAtFar(false);
//                        SetDespawnAtEnd(false);
//                        me->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);
//                        events.ScheduleEvent(EVENT_FIRST_MOVE, 2000);
//                        playerGUID = player->GetGUID();
//                    }
//                }
//            }
//
//            void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
//            {
//                switch (waypointId)
//                {
//                    case 1:
//                        Talk(1);
//                        break;
//                    case 3:
//                        SetEscortPaused(true);
//                        me->SetFacingTo(4.719869f);
//                        me->SetOrientation(4.719869f);
//                        Talk(2);
//                        break;
//                    case 4:
//                        me->SetFacingTo(5.442434f);
//                        me->SetOrientation(5.442434f);
//                        break;
//                    default:
//                        break;
//                }
//            }
//
//            void UpdateAI(uint32 diff) override
//            {
//                EscortAI::UpdateAI(diff);
//                events.Update(diff);
//
//                if (Player* player = ObjectAccessor::GetPlayer(*me, playerGUID))
//                {
//                    while (uint32 eventId = events.ExecuteEvent())
//                    {
//                        switch (eventId)
//                        {
//                            case EVENT_FIRST_MOVE:
//                                Talk(0);
//                                Start(false, false, player->GetGUID());
//                                break;
//                            case EVENT_THIRD_TALK:
//                                Talk(3);
//                                
//                                break;
//                            case EVENT_SECOND_MOVE:
//                                SetEscortPaused(false);
//                                break;
//                            case EVENT_FOURTH_TALK:
//                                Talk(4);
//                                break;
//                            case EVENT_FIFTH_TALK:
//                                Talk(5);
//                                break;
//                            case EVENT_SIXTH_TALK:
//                                Talk(6);
//                                break;
//                            case EVENT_SEVENTH_TALK:
//                                Talk(7);
//                                break;
//                            case EVENT_EIGHTH_TALK:
//                                Talk(8);
//                                break;
//                            case EVENT_FINAL:
//                                player->KilledMonsterCredit(64664);
//                                //me->AddNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);//��ʱע��
//                                break;
//                            default:
//                                break;
//                        }
//                    }
//                }
//            }
//        };
//
//        CreatureAI* GetAI(Creature* creature) const override
//        {
//            return new npc_wrathion_masonAI(creature);
//        }
//};
//
//void AddSC_the_veiled_stair()
//{
//    new npc_wrathion_mason();
//}
