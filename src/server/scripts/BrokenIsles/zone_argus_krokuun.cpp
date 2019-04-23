/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "SpellMgr.h"
#include "ScriptedGossip.h"
#include "Log.h"
#include "Conversation.h"
#include "CreatureTextMgr.h"
#include "PhasingHandler.h"
enum
{
    ZONE_KROKUUN            = 8574,
    AREA_KROKUUN_VINDICAAR  = 8714
};

// Zone 8574
class zone_argus_krokuun : public ZoneScript
{
public:
    zone_argus_krokuun() : ZoneScript("zone_argus_krokuun") { }

    void OnPlayerEnter(Player* player) override
    {
        player->GetScheduler().Schedule(Milliseconds(2s), ZONE_KROKUUN, [](TaskContext context)
        {
            if (Player* player = GetContextPlayer())
                if (player->GetAreaId() == AREA_KROKUUN_VINDICAAR)
                    if (player->GetPositionZ() <= 700.0f)
                        player->NearTeleportTo(383.17f, 1413.87f, 770.0f, 0.438168f);

            context.Repeat();
        });
    }

    void OnPlayerExit(Player* player) override
    {
        player->GetScheduler().CancelGroup(ZONE_KROKUUN);
    }
};

// 251924
class spell_garothi_obliterator_fiery_mortars : public SpellScript
{
    PrepareSpellScript(spell_garothi_obliterator_fiery_mortars);

    void HandleDummy(SpellEffIndex /* effIndex */)
    {
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_garothi_obliterator_fiery_mortars::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

#define GOSSIP_VEREESA_READY "I'm ready."
enum
{
    QUEST_A_THE_HAND_OF_FATE = 47221,
    QUEST_THE_DREAMWAY = 40644,
    SPELL_ASSIGN_DRUID_SPELL_BAR= 204543,
    QUEST_H_THE_HAND_OF_FATE = 47835,
    KILLED_MONSTER_CREDIT_THE_HAND_OF_FATE = 121751,
       
    QUEST_A_TWO_IF_BY_SEA = 47222,   
    SPELL_TELEPORT_AZUREMYST_ISLE = 243270,
    QUEST_H_TWO_IF_BY_SEA = 47867,
    KILLED_MONSTER_CREDIT_TWO_IF_BY_SEA = 121787,

    QUEST_LIGHTS_EXODUS = 47223,
    QUEST_THE_VINDICAAR = 47224,
    QUEST_INTO_THE_NIGHT = 48440,
    SPELL_PLAY_MOVIE_TO_ARGUS = 243785,

    DB_PHASE_THE_VINDICAAR = 8655,
    DB_PHASE_AFTER_THE_VINDICAAR = 8657,

    NPC_VINDICATOR_BOROS = 121756, //??????
    NPC_ARATOR_THE_REDEEMER = 121755, //???????
    NPC_VEREESA_WINDRUNNER =  121754,///Alliance
    NPC_LADY_LIADRIN_122065 = 122065,///Horde

    NPC_ILLIDAN_STORMRAGE_120978 = 120978,
    NPC_ILLIDAN_STORMRAGE_126408 = 126408,
    NPC_PROPHET_VELEN_120977 = 120977, ///???? map in 1750
    NPC_GRAND_ARTIFICER_ROMUUL_121263 = 121263,
    NPC_LOTHRAXION_121261 = 121261,
    NPC_PROPHET_VELEN_126307 = 126307,///???? map in 1669 ????  ????
};

enum
{
    TALK_01 = 0,
    TALK_02 = 1,
    TALK_03 = 2,
    TALK_04 = 3,
    TALK_05 = 4,
    TALK_06 = 5,
    TALK_07 = 6,
    TALK_08 = 7,

    EVENT_TALK_01 = 1,
    EVENT_TALK_02 = 2,
    EVENT_TALK_03 = 3,
    EVENT_TALK_04 = 4,
    EVENT_TALK_05 = 5,
    EVENT_TALK_06 = 6,
    EVENT_TALK_07 = 7,
    EVENT_TALK_08 = 8,
    EVENT_TALK_09 = 9,
};

enum Talks
{
    SAY_EVENT = 0,
    SAY_EVENT_2 = 1,
    SAY_EVENT_3 = 2,
};
// npc_vereesa_windrunner_121754
class npc_vereesa_windrunner_121754 : public CreatureScript
{
public:
    npc_vereesa_windrunner_121754() : CreatureScript("npc_vereesa_windrunner_121754") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/) override
    {
        if (!player)
            return false;

        CloseGossipMenuFor(player);
        if (player->HasQuest(QUEST_A_TWO_IF_BY_SEA))
        {
            player->KilledMonsterCredit(KILLED_MONSTER_CREDIT_TWO_IF_BY_SEA);
            player->TeleportTo(1750 ,-4235.34f, -11335.4f, 8.85f, 4.432787f);
        }
        return true;
    }

    struct npc_vereesa_windrunner_121754AI : public ScriptedAI
    {
        npc_vereesa_windrunner_121754AI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override { Intr = false; }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who || !who->IsInWorld())
                return;
            if (!me->IsWithinDist(who, 15.0f, false))
                return;

            Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

            if (!player)
                return;
            
            if (player->HasQuest(QUEST_A_THE_HAND_OF_FATE))
            {  
                if (!player->GetQuestObjectiveData(QUEST_A_THE_HAND_OF_FATE, 0))
                {
                    if (!Intr)
                        Intr = true;
                    player->KilledMonsterCredit(KILLED_MONSTER_CREDIT_THE_HAND_OF_FATE); // QUEST_A_THE_HAND_OF_FATE storageIndex 0 KillCredit
                }
            }
            
        }
        bool Intr;
        uint32 checkTimer = 4000;

        void UpdateAI(uint32 diff) override
        {
            if (checkTimer <= diff)
            {
                if (Intr) {
                    //talk
                    me->AI()->Talk(SAY_EVENT);
                    //delay 1s
                    if (Creature* arator_the_redeemer = me->FindNearestCreature(NPC_ARATOR_THE_REDEEMER, me->GetVisibilityRange()))
                    {

                        arator_the_redeemer->GetScheduler().Schedule(1s, 2s, [arator_the_redeemer](TaskContext context)
                        {
                            arator_the_redeemer->AI()->Talk(SAY_EVENT);
                        });
                    }
                    //delay 2s
                    if (Creature* vindicator_boros = me->FindNearestCreature(NPC_VINDICATOR_BOROS, me->GetVisibilityRange()))
                    {

                        vindicator_boros->GetScheduler().Schedule(2s, 3s, [vindicator_boros](TaskContext context)
                        {
                            vindicator_boros->AI()->Talk(SAY_EVENT);
                        });
                    }
                    Intr = false;
                }
                checkTimer = 4000;               
            }
            else checkTimer -= diff;
        }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) 
        {
            if (quest->GetQuestId() == QUEST_A_TWO_IF_BY_SEA)
            {

            }
            return true;
        }


    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vereesa_windrunner_121754AI(creature);
    }


    bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* quest, uint32 /*item*/) override
    {
        if (quest->GetQuestId() == QUEST_THE_DREAMWAY)
        {
            player->RemoveAurasDueToSpell(SPELL_ASSIGN_DRUID_SPELL_BAR);
        }

        return true;
    }
};

struct npc_lady_liadrin_122065 : public ScriptedAI
{
    npc_lady_liadrin_122065(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void Reset() override
    {
        Initialize();
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
     }

    void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);

        if (player->HasQuest(QUEST_H_TWO_IF_BY_SEA) || player->GetQuestStatus(QUEST_H_TWO_IF_BY_SEA)== QUEST_STATUS_COMPLETE|| player->GetQuestStatus(QUEST_H_TWO_IF_BY_SEA) == QUEST_STATUS_REWARDED)
        {
            player->KilledMonsterCredit(KILLED_MONSTER_CREDIT_TWO_IF_BY_SEA);
            player->TeleportTo(1750, -4295.41f, -11368.2f, 10.64f, 5.764124f);///SMSG_CUSTOM_LOAD_SCREEN TeleportSpellID: 247215 LoadingScreenID: 1377
        }
    }
    void Initialize()
    {
        m_playerGUID = ObjectGuid::Empty;
    }

    void AddPlayer()
    {
        if (!HasPlayer(m_playerGUID))
            pList.insert(m_playerGUID);
    }

    bool HasPlayer(ObjectGuid guid)
    {
        return (pList.find(guid) != pList.end());
    }

    void RemovePlayer()
    {
        if (HasPlayer(m_playerGUID))
            pList.erase(m_playerGUID);
        m_playerGUID = ObjectGuid::Empty;
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 15.0f, false))
        {
            RemovePlayer();
            return;
        }
        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();
        if (!player)
            return;
        if (!HasPlayer(player->GetGUID()) && (player->HasQuest(QUEST_H_THE_HAND_OF_FATE) ) && !player->GetQuestObjectiveData(QUEST_H_THE_HAND_OF_FATE, 0))
        {
            m_playerGUID = player->GetGUID();
            AddPlayer();
            Conversation::CreateConversation(5335, player, player->GetPosition(), { player->GetGUID() });
            player->KilledMonsterCredit(KILLED_MONSTER_CREDIT_THE_HAND_OF_FATE); // QUEST_THE_HAND_OF_FATE storageIndex 0 KillCredit
            ///talk
            if (Creature* boros = me->FindNearestCreature(NPC_VINDICATOR_BOROS, 15.0f))
            {
                boros->AI()->Talk(1);
            }
            _scheduler.Schedule(3s, 4s, [this, player](TaskContext context)
            {
                me->AI()->Talk(0);
            });

            _scheduler.Schedule(5s, 6s, [this, player](TaskContext context)
            {
                me->AI()->Talk(1);
            });
           
            m_playerGUID = ObjectGuid::Empty;
        }
    }
private: 
    TaskScheduler _scheduler;
    std::set<ObjectGuid> pList;
    ObjectGuid   m_playerGUID;
};

// npc_vindicator_boros_121756
class npc_vindicator_boros_121756 : public CreatureScript
{
public:
    npc_vindicator_boros_121756() : CreatureScript("npc_vindicator_boros_121756") { }


    struct npc_vindicator_boros_121756AI : public ScriptedAI
    {
        npc_vindicator_boros_121756AI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override { Intr = false; }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who || !who->IsInWorld())
                return;
            if (!me->IsWithinDist(who, 15.0f, false))
                return;

            Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

            if (!player)
                return;

            if (player->HasQuest(QUEST_A_TWO_IF_BY_SEA))
            {
                if (player->GetQuestObjectiveData(QUEST_A_TWO_IF_BY_SEA, 0))
                {
                    if (!Intr)
                        Intr = true;
                }
            }

        }
        bool Intr;
        uint32 checkTimer = 4000;

        void UpdateAI(uint32 diff) override
        {
            if (checkTimer <= diff)
            {
                if (Intr) {

                    //delay 2s
                    if (Creature* vereesa_windrunner = me->FindNearestCreature(NPC_VEREESA_WINDRUNNER, me->GetVisibilityRange()))
                    {

                        vereesa_windrunner->GetScheduler().Schedule(2s, 3s, [vereesa_windrunner](TaskContext context)
                        {
                            vereesa_windrunner->AI()->Talk(SAY_EVENT_2);
                        });
                    }

                    //delay 1s
                    if (Creature* arator_the_redeemer = me->FindNearestCreature(NPC_ARATOR_THE_REDEEMER, 15.0f))
                    {

                        arator_the_redeemer->GetScheduler().Schedule(1s, 2s, [arator_the_redeemer](TaskContext context)
                        {
                            arator_the_redeemer->AI()->Talk(SAY_EVENT);
                        });
                    }
                    
                }
                checkTimer = 4000;
            }
            else checkTimer -= diff;
        }

        
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_vindicator_boros_121756AI(creature);
    }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_LIGHTS_EXODUS)
        {
            //to do
            creature->AI()->Talk(SAY_EVENT_2);
            //LET'S GO
        }
        return true;
    }

    bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* quest, uint32 /*item*/) override
    {
        if (quest->GetQuestId() == QUEST_THE_DREAMWAY)
        {
            player->RemoveAurasDueToSpell(SPELL_ASSIGN_DRUID_SPELL_BAR);
         }

        return true;
    }
};

// npc_lightforged_beacon_122045
class npc_lightforged_beacon_122045 : public CreatureScript
{
public:
    npc_lightforged_beacon_122045() : CreatureScript("npc_lightforged_beacon_122045") { }

    struct npc_lightforged_beacon_122045AI : public ScriptedAI
    {
        npc_lightforged_beacon_122045AI(Creature* creature) : ScriptedAI(creature) {}

        void OnSpellClick(Unit* who, bool& /*result*/) override
        {

            if (!who || !who->IsInWorld())
                return;
            if (!who->ToPlayer() || who->ToPlayer()->IsBeingTeleported())
                return;
            Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

            if (!player)
                return;
            player->KilledMonsterCredit(120981);
            player->TeleportTo(1750, -3961.16f, -11977.3f, 158.64f, 2.645221f);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lightforged_beacon_122045AI(creature);
    }

};
enum
{
    MOVIE_TO_ARGUS = 678,
    SPELL_TO_ARGUS = 241454,
};
class play_to_argus_cast_to_argus : public PlayerScript
{
public:
    play_to_argus_cast_to_argus() : PlayerScript("play_to_argus_cast_to_argus") { }

    void OnMovieComplete(Player* player, uint32 movieId)
    {
        if (movieId == MOVIE_TO_ARGUS)
        {
            player->CastSpell(player, SPELL_TO_ARGUS, true);
            player->TeleportTo(1669, 459.02f, 1450.02f, 757.57f, 0.4366814f);
        }
            
    }
};
enum {
    CONVERSATION_NEAR_TO_VELEN = 5063,
    CONVERSATION_ACCEPT_INTO_THE_NIGHT =5711,
    MENU_ID_TO_ARGUS = 21013,
    OPTION_ID_TO_ARGUS = 0,
    NPC_TEXT_TO_ARGUS  = 31708,
};
// npc_prophet_velen_120977 
class npc_prophet_velen_120977 : public CreatureScript
{
public:
    npc_prophet_velen_120977() : CreatureScript("npc_prophet_velen_120977") { }
    
    bool OnGossipHello(Player* player, Creature* creature) 
    {
            TC_LOG_ERROR("server.worldserver", "OnGossipHello ");
            if (player->GetQuestStatus(QUEST_LIGHTS_EXODUS)== QUEST_STATUS_COMPLETE)
            {
                //TC_LOG_ERROR("server.worldserver", "QUEST_LIGHTS_EXODUS OnGossipHello ");
                if (creature->IsQuestGiver())
                    player->PrepareQuestMenu(creature->GetGUID()); /* return true*/
                SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());    
            }
            else if (player->GetMapId()==1750 && (player->GetQuestStatus(QUEST_INTO_THE_NIGHT) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_INTO_THE_NIGHT) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(QUEST_INTO_THE_NIGHT) == QUEST_STATUS_REWARDED))
            {
                //TC_LOG_ERROR("server.worldserver", "QUEST_INTO_THE_NIGHT OnGossipHello ");
                ClearGossipMenuFor(player);
                AddGossipItemFor(player, GOSSIP_ICON_CHAT, GOSSIP_VEREESA_READY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(player, NPC_TEXT_TO_ARGUS, creature->GetGUID());
            }
            else
            {
                if (creature->IsQuestGiver())
                    player->PrepareQuestMenu(creature->GetGUID()); /* return true*/
                SendGossipMenuFor(player, player->GetGossipTextId(creature), creature->GetGUID());
            }

        return true;
    }
    
    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
    {
        if (!player)
            return false;

        
        switch (action)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:
            CloseGossipMenuFor(player);
            player->CastSpell(player, SPELL_PLAY_MOVIE_TO_ARGUS, true);
            break;
        }
        return true;
    }


    enum
    {
        TALK_01 = 0,
        TALK_02 = 1,
        TALK_03 = 2,
        TALK_04 = 3,
        TALK_05 = 4,
        TALK_06 = 5,
        TALK_07 = 6,
        TALK_08 = 7,

        EVENT_TALK_01 = 1,
        EVENT_TALK_02 = 2,
        EVENT_TALK_03 = 3,
        EVENT_TALK_04 = 4,
        EVENT_TALK_05 = 5,
        EVENT_TALK_06 = 6,
        EVENT_TALK_07 = 7,
        EVENT_TALK_08 = 8,
        EVENT_TALK_09 = 9,
    };
    struct npc_prophet_velen_120977AI : public ScriptedAI
    {
        npc_prophet_velen_120977AI(Creature* creature) : ScriptedAI(creature) { Initialize(); }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who || !who->IsInWorld())
                return;
            if (!me->IsWithinDist(who, me->GetVisibilityRange(), false))
                return;

            Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

            if (!player)
                return;

            if (player->HasQuest(QUEST_LIGHTS_EXODUS))
            {
                if (!Intr)
                {
                    Intr = true;
                    Conversation::CreateConversation(CONVERSATION_NEAR_TO_VELEN, player, *player, { player->GetGUID() });
                    //talk
                }

                if (!NearIntr)
                {
                    events.Reset();
                    events.ScheduleEvent(EVENT_TALK_01, 2s);
                }                 
            }
            if (player->HasQuest(QUEST_THE_VINDICAAR))
            {
                if (!NearIntr3)
                {
                    NearIntr3 = true;
                    events.Reset();
                    events.ScheduleEvent(EVENT_TALK_07, 1s);
                }               
            }
                
            if (player->HasQuest(QUEST_INTO_THE_NIGHT))
            {
                if (!NearIntr2)
                {
                    Conversation::CreateConversation(CONVERSATION_ACCEPT_INTO_THE_NIGHT, player, *player, { player->GetGUID() });
                    NearIntr2 = true;
                    events.Reset();
                    events.ScheduleEvent(EVENT_TALK_09, 1s);
                }
            }

        }

        void DoAction(int32 param)
        {
            if (param== EVENT_TALK_04)
                events.ScheduleEvent(EVENT_TALK_04, 1s);
        }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
        {
            if (quest->GetQuestId() == QUEST_THE_VINDICAAR)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_TALK_03, 1s);
            }
            else if (quest->GetQuestId() == QUEST_INTO_THE_NIGHT)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_TALK_08, 1s);
            }
            return true;
        }

        void Initialize()
        {
            events.Reset();
            Intr = false;
            NearIntr = false;
            NearIntr2 = false;
            NearIntr3 = false;
        }


        void UpdateAI(uint32 diff) override
        {
            ScriptedAI::UpdateAI(diff);
            events.Update(diff);
            Creature* velen = me;
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TALK_01:
                    TC_LOG_ERROR("server.worldserver", "EVENT_TALK_01");
                    //ILLIDAN SAY
                    if (Creature* illidan_stormrage = me->FindNearestCreature(NPC_ILLIDAN_STORMRAGE_120978, me->GetVisibilityRange()))
                    {

                        illidan_stormrage->GetScheduler().Schedule(1s, 2s, [illidan_stormrage](TaskContext context)
                        {
                            illidan_stormrage->AI()->Talk(TALK_01);///???????????????????????????????
                        });
                    }
                    events.ScheduleEvent(EVENT_TALK_02, 3s);
                    events.ScheduleEvent(EVENT_TALK_02, 3s);
                    break;
                case EVENT_TALK_02:
                    me->AI()->Talk(TALK_01);///??,????????????????????
                    break;
                case EVENT_TALK_03:
                    me->AI()->Talk(TALK_02);///??????,$p??????????
                    break;

                case EVENT_TALK_04:
                    me->AI()->Talk(TALK_03);///????????????????????????
                    events.ScheduleEvent(EVENT_TALK_05, 8s);
                    break;
                case EVENT_TALK_05:
                    me->AI()->Talk(TALK_04);///?????????????????.????????????.
                    //?????????
                    PhasingHandler::AddPhase(me, DB_PHASE_AFTER_THE_VINDICAAR, true);
                    events.ScheduleEvent(EVENT_TALK_06, 3s);
                    break;
                case EVENT_TALK_06:
                    Talk(TALK_05);///?????.???,???,???,?????????!
                    PhasingHandler::RemovePhase(me, DB_PHASE_AFTER_THE_VINDICAAR, true);
                    break;
                case EVENT_TALK_07:
                    //???? talk 
                    if (Creature* lothraxion = me->FindNearestCreature(NPC_LOTHRAXION_121261, me->GetVisibilityRange()))
                    {

                        lothraxion->GetScheduler().Schedule(1s, 2s, [lothraxion](TaskContext context)
                        {
                            lothraxion->AI()->Talk(SAY_EVENT);///???????????????????????????
                        });
                    }
                    
                    velen->GetScheduler().Schedule(2s, 3s, [velen](TaskContext context)
                    {
                        velen->AI()->Talk(TALK_06);///??????????????,???????,???????,?????
                    });
                    //?????? talk 
                    if (Creature* grand_artificer_romuul = me->FindNearestCreature(NPC_GRAND_ARTIFICER_ROMUUL_121263, me->GetVisibilityRange()))
                    {

                        grand_artificer_romuul->GetScheduler().Schedule(3s, 4s, [grand_artificer_romuul](TaskContext context)
                        {
                            grand_artificer_romuul->AI()->Talk(SAY_EVENT);///??,????????
                        });
                    }
                    break;
                case EVENT_TALK_08:                   
                    me->AI()->Talk(TALK_07);///??????????????
                    break;
                case EVENT_TALK_09:
                   
                    break;
                }
            }
        }

    private:
        EventMap events;
        
        bool Intr;
        bool NearIntr;
        bool NearIntr2;
        bool NearIntr3;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_prophet_velen_120977AI(creature);
    }

};

class npc_light_crystal_122052 : public CreatureScript
{
public:
    npc_light_crystal_122052() : CreatureScript("npc_light_crystal_122052") { }

    enum
    {
        EVENT_UPDATE_PHASES = 1
    };

    

    struct npc_light_crystal_122052AI : public ScriptedAI
    {
        npc_light_crystal_122052AI(Creature* creature) : ScriptedAI(creature) { events.Reset(); }

        void OnSpellClick(Unit* who, bool& /*result*/) override
        {
            if (!who || !who->IsInWorld())
                return;
            if (!who->ToPlayer())
                return;
            //quest accept ?? ??????,  . ????????
            //3s ?? ???????????????????????.
            //11s ?? ?????????????????.????????????.
            //13s ???
            //14s ?? ?????.???,???,???,?????????!
            //TC_LOG_ERROR("server.worldserver", "OnSpellClick");
            if (Creature* prophet_velen = me->FindNearestCreature(NPC_PROPHET_VELEN_120977, me->GetVisibilityRange()))
            {
                prophet_velen->GetScheduler().Schedule(1s, 2s, [prophet_velen](TaskContext context)
                {
                    prophet_velen->AI()->DoAction(4);
                });
            }
            events.ScheduleEvent(EVENT_UPDATE_PHASES, 13000);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);
            switch (events.ExecuteEvent())
                {
                case EVENT_UPDATE_PHASES:
                    std::list<Player*> players;
                    me->GetPlayerListInGrid(players, me->GetVisibilityRange());
                    for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        if ((*itr)->ToPlayer()->GetQuestStatus(QUEST_THE_VINDICAAR) == QUEST_STATUS_INCOMPLETE && (*itr)->ToPlayer()->GetQuestObjectiveData(QUEST_THE_VINDICAAR,2))
                        {
                            TC_LOG_ERROR("server.worldserver", "EVENT_UPDATE_PHASES");
                            PhasingHandler::AddPhase(*itr, DB_PHASE_AFTER_THE_VINDICAAR, true);
                            PhasingHandler::RemovePhase(*itr, DB_PHASE_THE_VINDICAAR, true);
                        }
                    }
                    break;
                }
           
        }
    //private:
    //    EventMap events;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_light_crystal_122052AI(creature);
    }

};
///NPC_PROPHET_VELEN_126307
class npc_prophet_velen_126307 : public CreatureScript
{
public:
    npc_prophet_velen_126307() : CreatureScript("npc_prophet_velen_126307") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_INTO_THE_NIGHT)
        {
            Conversation::CreateConversation(CONVERSATION_ACCEPT_INTO_THE_NIGHT, player, *player, { player->GetGUID() });
        }
        return true;
    }
    struct npc_prophet_velen_126307AI : public ScriptedAI
    {
        npc_prophet_velen_126307AI(Creature* creature) : ScriptedAI(creature) { Initialize(); }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!who || !who->IsInWorld())
                return;
            if (!me->IsWithinDist(who, me->GetVisibilityRange(), false))
                return;

            Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

            if (!player)
                return;


            if (player->HasQuest(QUEST_INTO_THE_NIGHT))
            {
                if (!Intr)
                {
                    Intr = true;
                    events.Reset();
                    events.ScheduleEvent(EVENT_TALK_01, 1s);
                }
            }

        }

        void DoAction(int32 param)
        {
            if (param == EVENT_TALK_04)
                events.ScheduleEvent(EVENT_TALK_04, 1s);
        }

        bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
        {
            
            if (quest->GetQuestId() == QUEST_THE_VINDICAAR)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_TALK_03, 1s);
            }
            else if (quest->GetQuestId() == QUEST_INTO_THE_NIGHT)
            {
                events.Reset();
                events.ScheduleEvent(EVENT_TALK_08, 1s);
            }
            return true;
        }

        void Initialize()
        {
            events.Reset();
            Intr = false;
            NearIntr = false;
            NearIntr2 = false;
            NearIntr3 = false;
        }


        void UpdateAI(uint32 diff) override
        {
            ScriptedAI::UpdateAI(diff);
            events.Update(diff);
            Creature* velen = me;
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TALK_01:
                    //illidan_stormrage talk 
                    if (Creature* illidan_stormrage = me->FindNearestCreature(NPC_ILLIDAN_STORMRAGE_126408, me->GetVisibilityRange()))
                    {

                        illidan_stormrage->GetScheduler().Schedule(1s, 2s, [illidan_stormrage](TaskContext context)
                        {
                            illidan_stormrage->AI()->Talk(TALK_01);///????????????--???????
                        });
                    }

                    velen->GetScheduler().Schedule(2s, 3s, [velen](TaskContext context)
                    {
                        velen->AI()->Talk(TALK_01);///????????????????!???,??????!
                    });
                    //?????? talk 
                    if (Creature* grand_artificer_romuul = me->FindNearestCreature(NPC_GRAND_ARTIFICER_ROMUUL_121263, me->GetVisibilityRange()))
                    {

                        grand_artificer_romuul->GetScheduler().Schedule(3s, 4s, [grand_artificer_romuul](TaskContext context)
                        {
                            grand_artificer_romuul->AI()->Talk(TALK_02);///??,????????
                        });
                    }
                    break;
                case EVENT_TALK_02:
                    me->AI()->Talk(TALK_01);///??,????????????????????
                    break;
                case EVENT_TALK_03:
                    me->AI()->Talk(TALK_02);///??????,$p??????????
                    break;

                case EVENT_TALK_04:
                    me->AI()->Talk(TALK_03);///????????????????????????
                    events.ScheduleEvent(EVENT_TALK_05, 8s);
                    break;
                case EVENT_TALK_05:
                    me->AI()->Talk(TALK_04);///?????????????????.????????????.
                                            //?????????
                    PhasingHandler::AddPhase(me, DB_PHASE_AFTER_THE_VINDICAAR, true);
                    events.ScheduleEvent(EVENT_TALK_06, 3s);
                    break;
                case EVENT_TALK_06:
                    Talk(TALK_05);///?????.???,???,???,?????????!
                    PhasingHandler::RemovePhase(me, DB_PHASE_AFTER_THE_VINDICAAR, true);
                    break;
                case EVENT_TALK_07:
                    
                    //???? talk 
                    if (Creature* lothraxion = me->FindNearestCreature(NPC_LOTHRAXION_121261, me->GetVisibilityRange()))
                    {

                        lothraxion->GetScheduler().Schedule(1s, 2s, [lothraxion](TaskContext context)
                        {
                            lothraxion->AI()->Talk(SAY_EVENT);///???????????????????????????
                        });
                    }

                    velen->GetScheduler().Schedule(2s, 3s, [velen](TaskContext context)
                    {
                        velen->AI()->Talk(TALK_06);///??????????????,???????,???????,?????
                    });
                    //?????? talk 
                    if (Creature* grand_artificer_romuul = me->FindNearestCreature(NPC_GRAND_ARTIFICER_ROMUUL_121263, me->GetVisibilityRange()))
                    {

                        grand_artificer_romuul->GetScheduler().Schedule(3s, 4s, [grand_artificer_romuul](TaskContext context)
                        {
                            grand_artificer_romuul->AI()->Talk(SAY_EVENT);///??,????????
                        });
                    }
                    break;
                case EVENT_TALK_08:
                    me->AI()->Talk(TALK_07);///??????????????
                    break;
                case EVENT_TALK_09:
                    //illidan_stormrage talk
                    
                    if (Creature* illidan_stormrage = me->FindNearestCreature(NPC_ILLIDAN_STORMRAGE_126408, me->GetVisibilityRange()))
                    {

                        illidan_stormrage->GetScheduler().Schedule(1s, 2s, [illidan_stormrage](TaskContext context)
                        {
                            illidan_stormrage->AI()->Talk(TALK_01);///????????????--???????
                        });
                    }

                    velen->GetScheduler().Schedule(2s, 3s, [velen](TaskContext context)
                    {
                        velen->AI()->Talk(TALK_08);///????????????????!???,??????!
                    });
                    //?????? talk 
                    if (Creature* grand_artificer_romuul = me->FindNearestCreature(NPC_GRAND_ARTIFICER_ROMUUL_121263, me->GetVisibilityRange()))
                    {

                        grand_artificer_romuul->GetScheduler().Schedule(3s, 4s, [grand_artificer_romuul](TaskContext context)
                        {
                            grand_artificer_romuul->AI()->Talk(TALK_02);///??,????????
                        });
                    }
                    break;
                }
            }
        }

    private:
        EventMap events;

        bool Intr;
        bool NearIntr;
        bool NearIntr2;
        bool NearIntr3;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_prophet_velen_126307AI(creature);
    }

};

// 125820
struct npc_imp_mother_laglath : public ScriptedAI
{
    npc_imp_mother_laglath(Creature* creature) : ScriptedAI(creature) {}

    enum SpellData
    {
        SPELL_ELDER_WRATH   = 251683,
        SPELL_MATRON_RAGE   = 251689,
        SPELL_WRATH_BOLT    = 251703
    };

    void Reset() override
    {
        me->GetScheduler().SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });

        me->GetScheduler().Schedule(20s, [](TaskContext context)
        {
            GetContextUnit()->CastSpell(nullptr, SPELL_MATRON_RAGE, false);
            context.Repeat();
        })
        .Schedule(3s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                GetContextUnit()->CastSpell(target, SPELL_WRATH_BOLT, false);
            context.Repeat();
        })
        .Schedule(1s, [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0))
                if (me->IsWithinCombatRange(target, 5.f))
                    GetContextUnit()->CastSpell(target, SPELL_ELDER_WRATH, false);

            context.Repeat();
        });
    }
};

void AddSC_zone_argus_krokuun()
{
    new zone_argus_krokuun();
    RegisterSpellScript(spell_garothi_obliterator_fiery_mortars);

    new npc_vereesa_windrunner_121754();
    RegisterCreatureAI(npc_lady_liadrin_122065);
    new npc_vindicator_boros_121756();
    new npc_lightforged_beacon_122045();
    new play_to_argus_cast_to_argus();
    new npc_prophet_velen_120977();
    new npc_light_crystal_122052();
    new npc_prophet_velen_126307();
	
	RegisterCreatureAI(npc_imp_mother_laglath);
}
