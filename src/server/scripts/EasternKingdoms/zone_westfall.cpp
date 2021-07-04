/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2011-2016 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

 /* ScriptData
 SDName: Westfall
 SD%Complete: 90
 SDComment: Quest support: 1651
 SDCategory: Westfall
 EndScriptData */

 /* ContentData
 npc_daphne_stilwell
 EndContentData */

#include "script_helper.h"
#include "Creature.h"
#include "GameObjectAI.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Vehicle.h"


 // #############################################  quest 26209: Murder Was The Case That They Gave Me

enum eQuest26209
{
    NPC_INVESTIGATOR_42309 = 42309,
    NPC_HORATIO_LANE_42308 = 42308,
    NPC_WEST_PLAINS_DRIFTERS = 42391,
    NPC_HOMELESS_STORMWIND_CITIZEN_42384 = 42384,
    NPC_HOMELESS_STORMWIND_CITIZEN_42386 = 42386,
    NPC_TRANSIENT = 42383,
    NPC_RAGMUFFIN = 42413,
    NPC_WESTFALL_STEW_PROXY = 42625,
    NPC_FURLBROW_MURDER_INFO_001 = 42414,
    NPC_FURLBROW_MURDER_INFO_002 = 42415,
    NPC_FURLBROW_MURDER_INFO_003 = 42416,
    NPC_FURLBROW_MURDER_INFO_004 = 42417,
    NPC_VERNA_FURLBROW = 238,
    NPC_OLD_BLANCHY = 582,
    NPC_WESTFALL_STEW = 42617,

    QUEST_HEROS_CALL_WESTFALL1 = 26378,
    QUEST_HEROS_CALL_WESTFALL2 = 28562,
    QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME = 26209,
    QUEST_MEET_TWO_SHOED_LOE = 26215,

    SPELL_DETECT_QUEST_INVIS_0 = 79489,
    SPELL_DETECT_QUEST_INVIS_1 = 79229,
    SPELL_DETECT_QUEST_INVIS_2 = 79341,
    SPELL_DETECT_QUEST_INVIS_3 = 79498,
    SPELL_DETECT_QUEST_INVIS_4 = 101419, SPELL_COSMETIC_SLEEP_ZZZ = 78677,
};

// 42308
class npc_horatio_lane_42308 : public CreatureScript
{
public:
    npc_horatio_lane_42308() : CreatureScript("npc_horatio_lane_42308") { }

    struct npc_horatio_lane_42308AI : public ScriptedAI
    {
        npc_horatio_lane_42308AI(Creature* creature) : ScriptedAI(creature)
        {
            m_homePosition = Position(-9850.017f, 916.479f, 30.302f, 0.0f);
            m_investigationPosition = Position(-9852.655f, 910.777f, 29.948f, 0.0f);
        }

        EventMap  m_events;
        bool      m_story_started;
        uint64    m_playerGUID, m_vernaGUID, m_invest_vernaGUID, m_horseGUID, m_invest_horseGUID;
        Position  m_homePosition, m_investigationPosition;

        void Reset() override
        {
            m_playerGUID = 0;
            m_vernaGUID = 0;
            m_invest_vernaGUID = 0;
            m_invest_horseGUID = 0;
            m_horseGUID = 0;
            m_story_started = false;
            if (me->GetAreaId() == 916)
            {
                me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(1030, m_homePosition);
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!m_story_started)
                if (Player* player = who->ToPlayer())
                    if (player->HasAura(SPELL_DETECT_QUEST_INVIS_0))
                        if (me->GetDistance2d(player) < 15.0f)
                        {
                            FindAllMember();
                            m_playerGUID = player->GetGUID();
                            m_story_started = true;
                            m_events.RescheduleEvent(EVENT_START_TALK, 1000);
                            m_events.RescheduleEvent(EVENT_MASTER_RESET, 180000);
                        }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (m_story_started)
                if (type == POINT_MOTION_TYPE)
                    switch (id)
                    {
                    case 1030:
                    {
                        me->SetFacingTo(3.95f);
                        break;
                    }
                    case 1031:
                    {
                        m_events.ScheduleEvent(EVENT_TALK_PART_03, 1000);
                        break;
                    }
                    case 1032:
                    {
                        me->HandleEmoteCommand(EMOTE_STATE_STAND);
                        me->SetFacingTo(3.95f);
                        m_events.ScheduleEvent(EVENT_TALK_PART_06, 1000);
                        break;
                    }
                    }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MASTER_RESET:
                {
                    Reset();
                    break;
                }
                case EVENT_START_TALK:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (Creature* invest = ObjectAccessor::GetCreature(*me, m_invest_vernaGUID))
                            invest->AI()->Talk(0, player);

                    m_events.ScheduleEvent(EVENT_TALK_PART_00, 5000);
                    break;
                }
                case EVENT_TALK_PART_00:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (Creature* invest = ObjectAccessor::GetCreature(*me, m_invest_vernaGUID))
                            invest->AI()->Talk(1, player);

                    m_events.ScheduleEvent(EVENT_TALK_PART_01, 5000);
                    break;
                }
                case EVENT_TALK_PART_01:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (Creature* invest = ObjectAccessor::GetCreature(*me, m_invest_horseGUID))
                            invest->AI()->Talk(2, player);

                    m_events.ScheduleEvent(EVENT_TALK_PART_02, 7000);
                    break;
                }
                case EVENT_TALK_PART_02:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        Talk(0, player);
                    me->GetMotionMaster()->MovePoint(1031, m_investigationPosition);
                    break;
                }
                case EVENT_TALK_PART_03:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        Talk(1, player);
                    me->SetFacingTo(5.083f);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);

                    m_events.ScheduleEvent(EVENT_TALK_PART_04, 5000);
                    break;
                }
                case EVENT_TALK_PART_04:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        Talk(2, player);
                    m_events.ScheduleEvent(EVENT_TALK_PART_05, 10000);
                    break;
                }
                case EVENT_TALK_PART_05:
                {
                    me->GetMotionMaster()->MovePoint(1032, m_homePosition);
                    break;
                }
                case EVENT_TALK_PART_06:
                {
                    // generate a cooldown before video shows again.
                    m_events.ScheduleEvent(EVENT_TALK_PART_07, 60000);
                    break;
                }
                case EVENT_TALK_PART_07:
                {
                    Reset();
                    break;
                }
                }
            }
        }

        void FindAllMember()
        {
            if (!m_vernaGUID)
                if (Creature* verna = me->FindNearestCreature(NPC_VERNA_FURLBROW, 20.0f))
                    m_vernaGUID = verna->GetGUID();
            if (!m_invest_vernaGUID)
                if (Creature* verna = ObjectAccessor::GetCreature(*me, m_vernaGUID))
                    if (Creature* invest = verna->FindNearestCreature(NPC_INVESTIGATOR_42309, 10.0f))
                        m_invest_vernaGUID = invest->GetGUID();
            if (!m_horseGUID)
                if (Creature* horse = me->FindNearestCreature(NPC_OLD_BLANCHY, 20.0f))
                    m_horseGUID = horse->GetGUID();
            if (!m_invest_horseGUID)
                if (Creature* horse = ObjectAccessor::GetCreature(*me, m_horseGUID))
                    if (Creature* invest = horse->FindNearestCreature(NPC_INVESTIGATOR_42309, 10.0f))
                        m_invest_horseGUID = invest->GetGUID();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_horatio_lane_42308AI(creature);
    }
};

// 42391
class npc_west_plains_drifters : public CreatureScript
{
public:
    npc_west_plains_drifters() : CreatureScript("npc_west_plains_drifters") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetAreaId() == 916)
            if (!creature->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                if (!creature->IsInCombat())
                    if (player->GetQuestStatus(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME) == QUEST_STATUS_INCOMPLETE)
                    {
                        player->ADD_GOSSIP_ITEM_DB(11635, 0, GOSSIP_SENDER_MAIN, 1001);
                        player->ADD_GOSSIP_ITEM_DB(11635, 1, GOSSIP_SENDER_MAIN, 1002);
                        player->SEND_GOSSIP_MENU(16250, creature->GetGUID());
                        return true;
                    }

        return false;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        switch (action)
        {
        case 1001:
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            creature->Attack(player, true);
            player->Attack(creature, true);
            creature->AI()->Talk(0, player);
            break;
        case 1002:
            if (urand(0, 1) == 0)
            {
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                creature->Attack(player, true);
                player->Attack(creature, true);
                creature->AI()->Talk(0, player);
                break;
            }
            uint32 a1 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42414);
            uint32 a2 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42415);
            uint32 a3 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42416);
            uint32 a4 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42417);
            if (a1 == 0)
            {
                player->KilledMonsterCredit(42414);
                creature->AI()->Talk(1, player);
            }
            else if (a2 == 0)
            {
                player->KilledMonsterCredit(42415);
                creature->AI()->Talk(2, player);
            }
            else if (a3 == 0)
            {
                player->KilledMonsterCredit(42416);
                creature->AI()->Talk(3, player);
            }
            else if (a4 == 0)
            {
                player->KilledMonsterCredit(42417);
                creature->AI()->Talk(4, player);
            }
            creature->GetMotionMaster()->MoveRandom(10);
            break;
        }
        player->CLOSE_GOSSIP_MENU();

        return true;
    }

    struct npc_west_plains_driftersAI : public ScriptedAI
    {
        npc_west_plains_driftersAI(Creature *c) : ScriptedAI(c) { }

        EventMap m_events;

        void Reset() override
        {
            switch (me->GetAreaId())
            {
            case 108: // sentinel hill
            {
                if (me->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                    m_events.RescheduleEvent(EVENT_CHECK_FOR_PLAYER, 1000);
                break;
            }
            case 916: // jansens stead
            {
                if (!me->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                break;
            }
            }
        }

        void JustDied(Unit* killer) override
        {
            Position pos = me->GetNearPosition(frand(1.5f, 2.5f), 0);
            me->SummonCreature(NPC_RAGMUFFIN, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
            pos = me->GetNearPosition(frand(1.5f, 2.5f), 2);
            me->SummonCreature(NPC_RAGMUFFIN, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
            pos = me->GetNearPosition(frand(1.5f, 2.5f), 4);
            me->SummonCreature(NPC_RAGMUFFIN, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_FOR_PLAYER:
                {
                    if (Creature* feed = me->FindNearestCreature(NPC_WESTFALL_STEW, 10.0f, true))
                        if (Unit* charm = feed->GetCharmerOrOwner())
                            if (Player* player = charm->ToPlayer())
                            {
                                player->KilledMonsterCredit(NPC_WESTFALL_STEW);
                                me->RemoveAllAuras();
                                //me->SetByteValue(UNIT_FIELD_BYTES_1, 0, UNIT_STAND_STATE_STAND);
                                me->HandleEmoteCommand(EMOTE_STATE_USE_STANDING);
                                // Talk(11, player);
                                me->DespawnOrUnsummon(5000);
                                break;
                            }
                    m_events.ScheduleEvent(EVENT_CHECK_FOR_PLAYER, 1000);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_west_plains_driftersAI(creature);
    }
};

// 42383
class npc_transient : public CreatureScript
{
public:
    npc_transient() : CreatureScript("npc_transient") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetAreaId() == 916)
            if (!creature->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                if (!creature->IsInCombat())
                    if (player->GetQuestStatus(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME) == QUEST_STATUS_INCOMPLETE)
                    {
                        player->ADD_GOSSIP_ITEM_DB(11635, 0, GOSSIP_SENDER_MAIN, 1001);
                        player->ADD_GOSSIP_ITEM_DB(11635, 1, GOSSIP_SENDER_MAIN, 1002);
                        player->SEND_GOSSIP_MENU(16250, creature->GetGUID());
                        return true;
                    }

        return false;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        switch (action)
        {
        case 1001:
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            creature->Attack(player, true);
            player->Attack(creature, true);
            creature->AI()->Talk(0, player);
            break;
        case 1002:
            if (urand(0, 1) == 0)
            {
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                creature->Attack(player, true);
                player->Attack(creature, true);
                creature->AI()->Talk(0, player);
                break;
            }
            uint32 a1 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42414);
            uint32 a2 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42415);
            uint32 a3 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42416);
            uint32 a4 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42417);
            if (a1 == 0)
            {
                player->KilledMonsterCredit(42414);
                creature->AI()->Talk(1, player);
            }
            else if (a2 == 0)
            {
                player->KilledMonsterCredit(42415);
                creature->AI()->Talk(2, player);
            }
            else if (a3 == 0)
            {
                player->KilledMonsterCredit(42416);
                creature->AI()->Talk(3, player);
            }
            else if (a4 == 0)
            {
                player->KilledMonsterCredit(42417);
                creature->AI()->Talk(4, player);
            }
            creature->GetMotionMaster()->MoveRandom(10);
            break;
        }
        player->CLOSE_GOSSIP_MENU();

        return true;
    }

    struct npc_transientAI : public ScriptedAI
    {
        npc_transientAI(Creature *c) : ScriptedAI(c) { }

        EventMap m_events;

        void Reset() override
        {
            switch (me->GetAreaId())
            {
            case 108: // sentinel hill
            {
                if (me->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                    m_events.RescheduleEvent(EVENT_CHECK_FOR_PLAYER, 1000);
                break;
            }
            case 916: // jansens stead
            {
                if (!me->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                break;
            }
            }
        }

        void JustDied(Unit* killer) override
        {
            Position pos = me->GetNearPosition(frand(1.5f, 2.5f), 0);
            me->SummonCreature(NPC_RAGMUFFIN, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
            pos = me->GetNearPosition(frand(1.5f, 2.5f), 2);
            me->SummonCreature(NPC_RAGMUFFIN, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
            pos = me->GetNearPosition(frand(1.5f, 2.5f), 4);
            me->SummonCreature(NPC_RAGMUFFIN, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_FOR_PLAYER:
                {
                    if (Creature* feed = me->FindNearestCreature(NPC_WESTFALL_STEW, 10.0f, true))
                        if (Unit* charm = feed->GetCharmerOrOwner())
                            if (Player* player = charm->ToPlayer())
                            {
                                player->KilledMonsterCredit(NPC_WESTFALL_STEW);
                                me->RemoveAllAuras();
                                //me->SetByteValue(UNIT_FIELD_BYTES_1, 0, UNIT_STAND_STATE_STAND);
                                me->HandleEmoteCommand(EMOTE_STATE_USE_STANDING);
                                Talk(11, player);
                                me->DespawnOrUnsummon(5000);
                                break;
                            }
                    m_events.ScheduleEvent(EVENT_CHECK_FOR_PLAYER, 1000);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_transientAI(creature);
    }
};

// 42386
class npc_homeless_stormwind_citizen_42386 : public CreatureScript
{
public:
    npc_homeless_stormwind_citizen_42386() : CreatureScript("npc_homeless_stormwind_citizen_42386") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetAreaId() == 916)
            if (!creature->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                if (!creature->IsInCombat())
                    if (player->GetQuestStatus(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME) == QUEST_STATUS_INCOMPLETE)
                    {
                        player->ADD_GOSSIP_ITEM_DB(11635, 0, GOSSIP_SENDER_MAIN, 1001);
                        player->ADD_GOSSIP_ITEM_DB(11635, 1, GOSSIP_SENDER_MAIN, 1002);
                        player->SEND_GOSSIP_MENU(16250, creature->GetGUID());
                        return true;
                    }

        return false;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        switch (action)
        {
        case 1001:
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            creature->Attack(player, true);
            player->Attack(creature, true);
            creature->AI()->Talk(0, player);
            break;
        case 1002:
            if (urand(0, 1) == 0)
            {
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                creature->Attack(player, true);
                player->Attack(creature, true);
                creature->AI()->Talk(0, player);
                break;
            }
            uint32 a1 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42414);
            uint32 a2 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42415);
            uint32 a3 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42416);
            uint32 a4 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42417);
            if (a1 == 0)
            {
                player->KilledMonsterCredit(42414);
                creature->AI()->Talk(1, player);
            }
            else if (a2 == 0)
            {
                player->KilledMonsterCredit(42415);
                creature->AI()->Talk(2, player);
            }
            else if (a3 == 0)
            {
                player->KilledMonsterCredit(42416);
                creature->AI()->Talk(3, player);
            }
            else if (a4 == 0)
            {
                player->KilledMonsterCredit(42417);
                creature->AI()->Talk(4, player);
            }
            creature->GetMotionMaster()->MoveRandom(10);
            break;
        }

        player->CLOSE_GOSSIP_MENU();

        return true;
    }

    struct npc_homeless_stormwind_citizen_42386AI : public ScriptedAI
    {
        npc_homeless_stormwind_citizen_42386AI(Creature *c) : ScriptedAI(c) { }

        EventMap m_events;

        void Reset() override
        {
            switch (me->GetAreaId())
            {
            case 108: // sentinel hill
            {
                if (me->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                    m_events.RescheduleEvent(EVENT_CHECK_FOR_PLAYER, 1000);
                break;
            }
            case 916: // jansens stead
            {
                if (!me->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                break;
            }
            }
        }

        void JustDied(Unit* killer) override
        {
            Position pos = me->GetNearPosition(frand(1.5f, 2.5f), 0);
            me->SummonCreature(NPC_RAGMUFFIN, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
            pos = me->GetNearPosition(frand(1.5f, 2.5f), 2);
            me->SummonCreature(NPC_RAGMUFFIN, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
            pos = me->GetNearPosition(frand(1.5f, 2.5f), 4);
            me->SummonCreature(NPC_RAGMUFFIN, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_FOR_PLAYER:
                {
                    if (Creature* feed = me->FindNearestCreature(NPC_WESTFALL_STEW, 10.0f, true))
                        if (Unit* charm = feed->GetCharmerOrOwner())
                            if (Player* player = charm->ToPlayer())
                            {
                                player->KilledMonsterCredit(NPC_WESTFALL_STEW);
                                me->RemoveAllAuras();
                                //me->SetByteValue(UNIT_FIELD_BYTES_1, 0, UNIT_STAND_STATE_STAND);
                                me->HandleEmoteCommand(EMOTE_STATE_USE_STANDING);
                                Talk(11, player);
                                me->DespawnOrUnsummon(5000);
                                break;
                            }
                    m_events.ScheduleEvent(EVENT_CHECK_FOR_PLAYER, 1000);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_homeless_stormwind_citizen_42386AI(creature);
    }
};

// 42384
class npc_homeless_stormwind_citizen_42384 : public CreatureScript
{
public:
    npc_homeless_stormwind_citizen_42384() : CreatureScript("npc_homeless_stormwind_citizen_42384") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetAreaId() == 916)
            if (!creature->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                if (!creature->IsInCombat())
                    if (player->GetQuestStatus(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME) == QUEST_STATUS_INCOMPLETE)
                    {
                        player->ADD_GOSSIP_ITEM_DB(11635, 0, GOSSIP_SENDER_MAIN, 1001);
                        player->ADD_GOSSIP_ITEM_DB(11635, 1, GOSSIP_SENDER_MAIN, 1002);
                        player->SEND_GOSSIP_MENU(16250, creature->GetGUID());
                        return true;
                    }

        return false;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        switch (action)
        {
        case 1001:
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            creature->Attack(player, true);
            player->Attack(creature, true);
            creature->AI()->Talk(0, player);
            break;
        case 1002:
            if (urand(0, 1) == 0)
            {
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                creature->Attack(player, true);
                player->Attack(creature, true);
                creature->AI()->Talk(0, player);
                break;
            }
            uint32 a1 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42414);
            uint32 a2 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42415);
            uint32 a3 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42416);
            uint32 a4 = player->GetReqKillOrCastCurrentCount(QUEST_MURDER_WAS_THE_CASE_THAT_THEY_GAVE_ME, 42417);
            if (a1 == 0)
            {
                player->KilledMonsterCredit(42414);
                creature->AI()->Talk(1, player);
            }
            else if (a2 == 0)
            {
                player->KilledMonsterCredit(42415);
                creature->AI()->Talk(2, player);
            }
            else if (a3 == 0)
            {
                player->KilledMonsterCredit(42416);
                creature->AI()->Talk(3, player);
            }
            else if (a4 == 0)
            {
                player->KilledMonsterCredit(42417);
                creature->AI()->Talk(4, player);
            }
            creature->GetMotionMaster()->MoveRandom(10);
            break;
        }
        player->CLOSE_GOSSIP_MENU();

        return true;
    }

    struct npc_homeless_stormwind_citizen_42384AI : public ScriptedAI
    {
        npc_homeless_stormwind_citizen_42384AI(Creature *c) : ScriptedAI(c) { }

        EventMap m_events;

        void Reset() override
        {
            switch (me->GetAreaId())
            {
            case 108: // sentinel hill
            {
                if (me->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                    m_events.RescheduleEvent(EVENT_CHECK_FOR_PLAYER, 1000);
                break;
            }
            case 916: // jansens stead
            {
                if (!me->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                break;
            }
            }
        }

        void JustDied(Unit* killer) override
        {
            Position pos = me->GetNearPosition(frand(1.5f, 2.5f), 0);
            me->SummonCreature(NPC_RAGMUFFIN, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
            pos = me->GetNearPosition(frand(1.5f, 2.5f), 2);
            me->SummonCreature(NPC_RAGMUFFIN, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
            pos = me->GetNearPosition(frand(1.5f, 2.5f), 4);
            me->SummonCreature(NPC_RAGMUFFIN, pos, TEMPSUMMON_TIMED_DESPAWN, 20000);
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_FOR_PLAYER:
                {
                    if (Creature* feed = me->FindNearestCreature(NPC_WESTFALL_STEW, 10.0f, true))
                        if (Unit* charm = feed->GetCharmerOrOwner())
                            if (Player* player = charm->ToPlayer())
                            {
                                player->KilledMonsterCredit(NPC_WESTFALL_STEW);
                                me->RemoveAllAuras();
                                //me->SetByteValue(UNIT_FIELD_BYTES_1, 0, UNIT_STAND_STATE_STAND);
                                me->HandleEmoteCommand(EMOTE_STATE_USE_STANDING);
                                Talk(11, player);
                                me->DespawnOrUnsummon(5000);
                                break;
                            }
                    m_events.ScheduleEvent(EVENT_CHECK_FOR_PLAYER, 1000);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_homeless_stormwind_citizen_42384AI(creature);
    }
};

// 42413
class npc_ragamuffin_42413 : public CreatureScript
{
public:
    npc_ragamuffin_42413() : CreatureScript("npc_ragamuffin_42413") { }

    struct npc_ragamuffin_42413AI : public ScriptedAI
    {
        npc_ragamuffin_42413AI(Creature *c) : ScriptedAI(c) { }

        EventMap m_events;
        uint64   m_homelessGUID;

        void Reset() override
        {
            me->GetMotionMaster()->MoveRandom(2.0f);
            m_homelessGUID = 0;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            m_homelessGUID = summoner->GetGUID();
            m_events.ScheduleEvent(EVENT_START_TALK, urand(1000, 6000));
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_TALK:
                {
                    if (Creature* homeless = ObjectAccessor::GetCreature(*me, m_homelessGUID))
                        Talk(0, homeless);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ragamuffin_42413AI(creature);
    }
};

// #############################################  quest 26215 Meet Two-Shoed Lou

enum eQuest26215
{
    NPC_INVESTIGATOR_42559 = 42559,
    NPC_HORATIO_LANE_42558 = 42558,
    NPC_TWO_SHOED_LOU_ALIVE = 42405,
    NPC_TWO_SHOED_LOU_DEATH = 42560,
};

// #############################################  quest = 26228  Livin' the Life

enum eQuest26228
{
    NPC_GLUBTOK_THE_FOREMAN = 42492,
    NPC_SHADOWY_FIGURE = 42515,
    NPC_TWO_SHOED_LOUS_OLD_HOUSE = 42500,
    QUEST_LIVIN_THE_LIFE = 26228,
    SPELL_SHROUD_OF_SHADOWS = 79192, // used by old script
    SPELL_VANISH_VISUAL = 24222, // used by old script
    SPELL_SUMMON_GLUBTOK = 79263,
    SPELL_SUMMON_SHADOWY_FIGURE = 79265,
    SPELL_SUMMON_LOUS_HOUSE = 79262,
};

class npc_lues_old_house : public CreatureScript
{
public:
    npc_lues_old_house() : CreatureScript("npc_lues_old_house") { }

    struct npc_lues_old_houseAI : public ScriptedAI
    {
        npc_lues_old_houseAI(Creature *c) : ScriptedAI(c) { }

        uint32 _timer;
        uint32 _phase;

        void Reset() override
        {
            _timer = 0;
            _phase = 0;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Player* player = summoner->ToPlayer())
            {
                player->CastSpell(player, SPELL_SUMMON_GLUBTOK);
                player->CastSpell(player, SPELL_SUMMON_SHADOWY_FIGURE);
                _phase = 1; _timer = 1000;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (_timer <= diff)
            {
                _timer = 1000;
                DoWork();
            }
            else
                _timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            if (_phase == 1)
            {
                if (Creature* grubtok = me->FindNearestCreature(NPC_GLUBTOK_THE_FOREMAN, 40.0f))
                    return;
                else
                    me->DespawnOrUnsummon();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_lues_old_houseAI(creature);
    }
};

class npc_shadowy_figure : public CreatureScript
{
public:
    npc_shadowy_figure() : CreatureScript("npc_shadowy_figure") { }

    struct npc_shadowy_figureAI : public ScriptedAI
    {
        npc_shadowy_figureAI(Creature *c) : ScriptedAI(c) { }

        uint32		_timer;
        uint32		_phase;
        Player*		_player;

        void Reset() override
        {
            _timer = 0;
            _phase = 0;
            _player = nullptr;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Player* player = summoner->ToPlayer())
            {
                _player = player;
                _timer = 1000;
                _phase = 1;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (_timer <= diff)
            {
                _timer = 1000;
                DoWork();
            }
            else
                _timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            Creature* _glubtok = me->FindNearestCreature(NPC_GLUBTOK_THE_FOREMAN, 40.0f, true);

            if (!_glubtok)
                return;

            switch (_phase)
            {
            case 1:
                _phase++; _timer = 7000;
                me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(0, -9841.677f, 1400.042f, 37.129f);
                break;
            case 2:
                _phase++; _timer = 5000;
                _glubtok->AI()->Talk(0);
                break;
            case 3:
                _phase++; _timer = 8500;
                me->AI()->Talk(0);
                break;
            case 4:
                _phase++; _timer = 4000;
                _glubtok->AI()->Talk(1);
                break;
            case 5:
                _phase++; _timer = 6500;
                me->AI()->Talk(1);
                break;
            case 6:
                _phase++; _timer = 6500;
                me->AI()->Talk(2);
                break;
            case 7:
                _phase++; _timer = 4000;
                _glubtok->AI()->Talk(2);
                break;
            case 8:
                _phase++; _timer = 7000;
                me->AI()->Talk(3);
                break;
            case 9:
                _phase++; _timer = 7000;
                _glubtok->AI()->Talk(3);
                break;
            case 10:
                _phase++; _timer = 6000;
                _glubtok->AI()->Talk(4);
                break;
            case 11:
                _phase++; _timer = 6000;
                me->AI()->Talk(4);
                break;
            case 12:
                _phase++; _timer = 6000;
                me->AI()->Talk(5);
                break;
            case 13:
                _phase++; _timer = 2000;
                if (_player && _player->IsAlive())
                {
                    _player->KilledMonsterCredit(NPC_GLUBTOK_THE_FOREMAN);
                    _player->CompleteQuest(QUEST_LIVIN_THE_LIFE);
                }
                me->DespawnOrUnsummon(1000);
                _glubtok->DespawnOrUnsummon(1000);
                break;
            case 14:
                _phase = 0; _timer = 0;
                if (_player && _player->IsAlive())
                {
                    _player->ExitVehicle();
                }
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_shadowy_figureAI(creature);
    }
};

// #############################################  quest = 26232  Lou's Parting Thoughts

enum eQuest26232
{
    NPC_THUG = 42387,
    NPC_JIMB = 42498,
    QUEST_LOUS_PARTING_THOUGHTS = 26232,
    SOUND_WOMAN_SCREAM = 17852,
};

class npc_thug : public CreatureScript
{
public:
    npc_thug() : CreatureScript("npc_thug") { }

    struct npc_thugAI : public ScriptedAI
    {
        npc_thugAI(Creature *c) : ScriptedAI(c) { }

        uint32      m_timer;
        uint32      m_event;
        uint32      m_phase;
        Player*     m_player;
        Creature*   m_thug1;
        Creature*   m_thug2;
        Creature*   m_thug3;

        void Reset() override
        {
            m_timer = 0; m_phase = 0; m_event = 1000;
            m_player = nullptr; m_thug1 = nullptr; m_thug2 = nullptr; m_thug3 = nullptr;
        }

        void JustDied(Unit* killer) override
        {
            Player* player = killer->ToPlayer();
            Creature* thug = killer->FindNearestCreature(NPC_THUG, 25.0f, true);
            if (!thug && player)
            {
                player->KilledMonsterCredit(NPC_FURLBROW_MURDER_INFO_004);
                player->PlayDistanceSound(SOUND_WOMAN_SCREAM);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (m_timer <= diff)
            {
                m_timer = 1000;
                DoWork();
            }
            else
                m_timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            switch (m_phase)
            {
            case 0:
                if (Player* player = me->FindNearestPlayer(12.0f))
                    if (player->GetQuestStatus(QUEST_LOUS_PARTING_THOUGHTS) == QUEST_STATUS_INCOMPLETE)
                        if (HaveHighestGuid())
                        {
                            m_phase = 1; m_timer = 1000; m_player = player;
                        }
                        else
                        {
                            m_phase = 20; m_timer = 0;
                        }
                break;
            case 1:
                m_phase = 2; m_timer = 7000;
                m_thug1->AI()->Talk(0);
                break;
            case 2:
                m_phase = 3; m_timer = 5000;
                m_thug2->AI()->Talk(1);
                break;
            case 3:
                m_phase = 4; m_timer = 8000;
                m_thug2->AI()->Talk(2);
                break;
            case 4:
                m_phase = 5; m_timer = 8000;
                m_thug3->AI()->Talk(3);
                break;
            case 5:
                m_phase = 6; m_timer = 5000;
                m_thug1->AI()->Talk(4);
                break;
            case 6:
                m_phase = 7; m_timer = 3000;
                m_thug1->AI()->Talk(5);
                break;
            case 7:
                m_phase = 8; m_timer = 3000;
                m_thug1->AI()->Talk(6);
                break;
            case 8:
                m_phase = 20; m_timer = 0;
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                m_thug1->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                m_thug2->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                m_thug3->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                m_player->Attack(me, false);
                me->Attack(m_player, false);
                m_thug1->Attack(m_player, false);
                m_thug2->Attack(m_player, false);
                m_thug3->Attack(m_player, false);
                break;
            }
        }

        bool HaveHighestGuid()
        {
            std::list<Creature*> list;
            me->GetCreatureListWithEntryInGrid(list, NPC_THUG, 15.0f);

            if (list.empty())
                return false;

            if (list.size() != 4)
                return false;

            Creature* target = nullptr;
            uint32 tmpGuid = 0;
            for (std::list<Creature*>::iterator itr = list.begin(); itr != list.end(); ++itr)
            {
                target = *itr;
                if (target->GetGUIDLow() > tmpGuid)
                    tmpGuid = target->GetGUIDLow();
            }

            uint8 i = 0;
            for (std::list<Creature*>::iterator itr = list.begin(); itr != list.end(); ++itr)
            {
                target = *itr;
                if (target->GetGUIDLow() != tmpGuid)
                {
                    i++;
                    switch (i)
                    {
                    case 1:
                        m_thug1 = target;
                        break;
                    case 2:
                        m_thug2 = target;
                        break;
                    case 3:
                        m_thug3 = target;
                        break;
                    }
                }
            }

            if (me->GetGUIDLow() == tmpGuid)
                return true;

            return false;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_thugAI(creature);
    }
};

class npc_horatio_lane_42558 : public CreatureScript
{
public:
    npc_horatio_lane_42558() : CreatureScript("npc_horatio_lane_42558") { }

    struct npc_horatio_lane_42558AI : public ScriptedAI
    {
        npc_horatio_lane_42558AI(Creature* creature) : ScriptedAI(creature) { }

        uint32  m_timer;
        uint32  m_phase;
        uint32  m_cooldown;
        Player* m_player;

        void Reset() override
        {
            m_timer = 0; m_phase = 0; m_cooldown = 0;
            m_player = nullptr;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
                if (m_phase == 0)
                    if (player->GetQuestStatus(QUEST_LOUS_PARTING_THOUGHTS) == QUEST_STATUS_COMPLETE)
                        if (player->HasAura(SPELL_DETECT_QUEST_INVIS_2))
                            if (me->GetDistance2d(player) < 15)
                            {
                                m_phase = 1; m_timer = 1000; m_cooldown = 180000;
                                m_player = player;
                            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (m_timer <= diff)
            {
                m_timer = 1000;
                DoWork();
            }
            else
                m_timer -= diff;

            if (m_cooldown > 0)
            {
                if (m_cooldown <= diff)
                {
                    Reset();
                }
                else
                    m_cooldown -= diff;
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            switch (m_phase)
            {
            case 1:
                m_phase++; m_timer = 6000;
                if (Creature* jimb = me->FindNearestCreature(NPC_JIMB, 10))
                    if (Creature* invest = jimb->FindNearestCreature(NPC_INVESTIGATOR_42559, 10))
                        invest->AI()->Talk(0);
                break;
            case 2:
                m_phase++; m_timer = 6000;
                if (Creature* jimb = me->FindNearestCreature(NPC_JIMB, 10))
                    if (Creature* invest = jimb->FindNearestCreature(NPC_INVESTIGATOR_42559, 10))
                        if (Creature* homeless = invest->FindNearestCreature(NPC_HOMELESS_STORMWIND_CITIZEN_42384, 10))
                            homeless->AI()->Talk(0);
                break;
            case 3:
                m_phase++; m_timer = 6000;
                if (Creature* jimb = me->FindNearestCreature(NPC_JIMB, 10))
                    if (Creature* invest = jimb->FindNearestCreature(NPC_INVESTIGATOR_42559, 10))
                        invest->AI()->Talk(1);
                break;
            case 4:
                m_phase++; m_timer = 6000;
                Talk(0);
                break;
            case 5:
                m_phase++; m_timer = 6000;
                Talk(1);
                break;
            case 6:
                m_phase++; m_timer = 6000;
                Talk(2);
                break;
            case 7:
                m_phase++; m_timer = 6000;
                Talk(3);
                break;
            case 8:
                m_phase++; m_timer = 6000;
                Talk(4);
                break;
            case 9:
                Reset();
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_horatio_lane_42558AI(creature);
    }
};

// #############################################  quest = 26257  It's Alive!

enum eQuest26257
{
    NPC_OVERLOADED_HARVEST_GOLEM_42381 = 42381,
    NPC_OVERLOADED_HARVEST_GOLEM_42601 = 42601,
    SPELL_UNBOUND_ENERGY = 79084,
    SPELL_WAKE_HARVEST_GOLEM = 79436,
    SPELL_REAPING_BLOWS = 79425,
    SPELL_ROCKET_BOOST = 79430,
};

// 42381
class npc_overloaded_harvest_golem_42381 : public CreatureScript
{
public:
    npc_overloaded_harvest_golem_42381() : CreatureScript("npc_overloaded_harvest_golem_42381") { }

    struct npc_overloaded_harvest_golem_42381AI : public ScriptedAI
    {
        npc_overloaded_harvest_golem_42381AI(Creature* creature) : ScriptedAI(creature) { }

        uint32  _timer;
        uint32  _phase;

        void Reset() override
        {
            _timer = urand(3000, 15000); _phase = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (_timer <= diff)
            {
                _timer = 1000;
                DoWork();
            }
            else
                _timer -= diff;

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            _timer = urand(3000, 20000);
            if (Creature* golem = me->FindRandomCreatureInRange(NPC_OVERLOADED_HARVEST_GOLEM_42381, 25.0f, true))
                me->CastSpell(golem, SPELL_UNBOUND_ENERGY);
            else
                me->CastSpell(me, SPELL_UNBOUND_ENERGY);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_overloaded_harvest_golem_42381AI(creature);
    }
};

// 79084
class spell_unbound_energy_79084 : public SpellScriptLoader
{
public:
    spell_unbound_energy_79084() : SpellScriptLoader("spell_unbound_energy_79084") { }

    class spell_unbound_energy_79084_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_unbound_energy_79084_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(RandomCheck(7.0f));
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_unbound_energy_79084_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_unbound_energy_79084_SpellScript();
    }
};

// #############################################  quest = 26236, 26241, 26266   Saldean's

enum eQuest26236
{
    NPC_FARMER_SALDEAN = 233,
    NPC_SALMA_SALDEAN = 235,
    NPC_HOPE_SALDEAN = 42575,
    NPC_ORPHAN = 42385,
    QUEST_SHAKEDOWN_AT_THE_SALDEANS = 26236,
    QUEST_WESTFALL_STEW = 26241,
    QUEST_HOPE_FOR_THE_PEOPLE = 26266,
};

// 235
class npc_salma_saldean_235 : public CreatureScript
{
public:
    npc_salma_saldean_235() : CreatureScript("npc_salma_saldean_235") { }

    bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 /*opt*/)
    {
        if (quest->GetQuestId() == QUEST_WESTFALL_STEW)
        {
            creature->AI()->Talk(0, player);
            CAST_AI(npc_salma_saldean_235AI, creature->AI())->StartAnimation();
            return true;
        }

        return false;
    }


    struct npc_salma_saldean_235AI : public ScriptedAI
    {
        npc_salma_saldean_235AI(Creature* creature) : ScriptedAI(creature) { }

        uint32  _timer;
        uint32  _phase;

        void Reset() override
        {
            _timer = 0; _phase = 0;
        }

        void StartAnimation()
        {
            if (_phase == 0)
            {
                _timer = 2000;
                _phase = 1;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (_timer <= diff)
            {
                _timer = 1000;
                DoWork();
            }
            else
                _timer -= diff;

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            switch (_phase)
            {
            case 1:
                me->GetMotionMaster()->MovePath(me->GetGUIDLow() * 10, false);
                _phase = 2;
                _timer = 5000;
                break;
            case 2:
                Talk(1);
                _phase = 3;
                _timer = 2000;
                break;
            case 3:
            {
                std::list<Creature*> orphans = me->FindNearestCreatures(NPC_ORPHAN, 8.0f);
                for (std::list<Creature*>::iterator itr = orphans.begin(); itr != orphans.end(); ++itr)
                {
                    if (Creature* orphan = (*itr))
                        if (orphan->GetPositionZ() < 40.0f)
                            orphan->GetMotionMaster()->MovePath(orphan->GetGUIDLow() * 10, false);
                }
                _phase = 4;
                _timer = 7000;
                break;
            }
            case 4:
                if (Creature* orphan = me->FindRandomCreatureInRange(NPC_ORPHAN, 6.0f, true))
                {
                    orphan->AI()->Talk(0);
                }
                _phase = 5;
                _timer = 2000;
                break;
            case 5:
                if (Creature* orphan = me->FindRandomCreatureInRange(NPC_ORPHAN, 6.0f, true))
                {
                    orphan->AI()->Talk(1);
                }
                _phase = 6;
                _timer = 15000;
                break;
            case 6:
            {
                std::list<Creature*> orphans = me->FindNearestCreatures(NPC_ORPHAN, 8.0f);
                for (std::list<Creature*>::iterator itr = orphans.begin(); itr != orphans.end(); ++itr)
                {
                    if (Creature* orphan = (*itr))
                        if (orphan->GetPositionZ() < 40.0f)
                            orphan->GetMotionMaster()->MovePath(orphan->GetGUIDLow() * 10 + 1, false);
                }
                _phase = 7;
                _timer = 2000;
                break;
            }
            case 7:
                me->GetMotionMaster()->MovePath(me->GetGUIDLow() * 10 + 1, false);
                _phase = 0;
                _timer = 0;
                break;
            case 8:
                _phase = 0;
                _timer = 0;
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_salma_saldean_235AI(creature);
    }
};

// #############################################  preprare sentinel hill area..

enum eSentinellHill
{
    NPC_SMALL_TIME_HUSTLER = 42390,
    NPC_WEST_PLAINS_DRIFTER = 42391,
    NPC_DEFIAS_KNUCKLEDUSTER = 449,
    NPC_DEFIAS_PILLAGER = 589,
    NPC_DEFIAS_HENCHMAN = 594,
    NPC_RIVERPAW_BRUTE_124 = 124,
    NPC_RIVERPAW_BANDIT_452 = 452,
    NPC_RIVERPAW_HERBALIST_501 = 501,
    NPC_RIVERPAW_BANDIT_54371 = 54371,
    NPC_RIVERPAW_BRUTE_54372 = 54372,
    NPC_RIVERPAW_HERBALIST_54373 = 54373,
    NPC_SENTINEL_HILL_GUARD = 42407,
    NPC_WESTFALL_BRIGADE_GUARD = 51915,
    NPC_MARSHAL_GRYAN_STOUTMANTLE_234 = 234,
    NPC_RIPSNARL = 42750,
    SPELL_DIRT_TOSS = 80382,
    SPELL_ROTTEN_APPLE_AROMA = 58511,
    SPELL_ROTTEN_BANANA_AROMA = 58514,
    SPELL_SPIT = 58519,
    EVENT_HOMELESS = 1,
    EVENT_SHOWFIGHT = 2,
    QUEST_FEEDING_THE_HUNGRY_AND_THE_HOPELESS = 26271,
    QUEST_IN_DEFENCE_OF_WESTFALL = 26286,
    QUEST_SECRETS_REVEALED = 26319,
};

// 42407  51915
class npc_sentinel_hill_guard : public CreatureScript
{
public:
    npc_sentinel_hill_guard() : CreatureScript("npc_sentinel_hill_guard") { }

    struct npc_sentinel_hill_guardAI : public ScriptedAI
    {
        npc_sentinel_hill_guardAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    _events;
        uint32      _phaseHomeless;
        Creature*   _homeless;
        Creature*   _defias;

        void Reset() override
        {
            _phaseHomeless = 0;
            _homeless = nullptr;
            _defias = nullptr;
            _events.ScheduleEvent(EVENT_HOMELESS, 2000);
            if (me->GetAreaId() == 108)
                _events.ScheduleEvent(EVENT_SHOWFIGHT, 1500);
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (IsShowfight(attacker) && me->GetHealthPct() < 70.0f)
                damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 _eventId = _events.ExecuteEvent())
            {
                switch (_eventId)
                {
                case EVENT_HOMELESS:
                    switch (_phaseHomeless)
                    {
                    case 0:
                        if (me->GetAreaId() == 108 && GetRandomHomeless())
                        {
                            _phaseHomeless = 1;
                            _events.ScheduleEvent(EVENT_HOMELESS, 1000);
                        }
                        else
                            _events.ScheduleEvent(EVENT_HOMELESS, 20000);
                        break;
                    case 1:
                        if (_homeless && !_homeless->HasAura(SPELL_COSMETIC_SLEEP_ZZZ))
                            _homeless->AI()->Talk(10);
                        _phaseHomeless = 2;
                        _events.ScheduleEvent(EVENT_HOMELESS, 1000);
                        break;
                    case 2:
                        if (_homeless)
                            _homeless->HandleEmoteCommand(RAND(EMOTE_ONESHOT_TALK, EMOTE_ONESHOT_EXCLAMATION, EMOTE_ONESHOT_QUESTION, EMOTE_ONESHOT_RUDE, EMOTE_ONESHOT_ROAR, EMOTE_ONESHOT_POINT, EMOTE_ONESHOT_TALK_NO_SHEATHE, EMOTE_ONESHOT_POINT_NO_SHEATHE));
                        _phaseHomeless = 3;
                        _events.ScheduleEvent(EVENT_HOMELESS, 1000);
                        break;
                    case 3:
                        if (_homeless)
                            _homeless->CastSpell(me, RAND(SPELL_DIRT_TOSS, SPELL_ROTTEN_APPLE_AROMA, SPELL_ROTTEN_BANANA_AROMA, SPELL_SPIT), true);
                        _phaseHomeless = 0;
                        _events.ScheduleEvent(EVENT_HOMELESS, urand(45000, 75000));
                        break;
                    default:
                        _phaseHomeless = 0;
                        _events.ScheduleEvent(EVENT_HOMELESS, 1000);
                        break;
                    }
                    break;
                case EVENT_SHOWFIGHT:
                    if (!me->IsInCombat())
                        if (Unit* target = me->SelectNearestTarget(5.0f))
                            me->Attack(target, true);

                    _events.ScheduleEvent(EVENT_SHOWFIGHT, 10000);
                    break;
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }

        bool GetRandomHomeless()
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, NPC_TRANSIENT, 10.0f);
            GetCreatureListWithEntryInGrid(creatureList, me, NPC_HOMELESS_STORMWIND_CITIZEN_42384, 10.0f);
            GetCreatureListWithEntryInGrid(creatureList, me, NPC_HOMELESS_STORMWIND_CITIZEN_42386, 10.0f);
            GetCreatureListWithEntryInGrid(creatureList, me, NPC_SMALL_TIME_HUSTLER, 10.0f);
            GetCreatureListWithEntryInGrid(creatureList, me, NPC_WEST_PLAINS_DRIFTER, 10.0f);

            if (creatureList.empty())
                return false;

            uint32 rol = urand(0, creatureList.size() - 1);
            std::list<Creature*>::const_iterator itr = creatureList.begin();
            std::advance(itr, rol);
            _homeless = (*itr);
            return true;
        }

        bool IsShowfight(Unit* attacker)
        {
            switch (attacker->GetEntry())
            {
            case NPC_DEFIAS_KNUCKLEDUSTER:
            case NPC_DEFIAS_PILLAGER:
            case NPC_DEFIAS_HENCHMAN:
            case NPC_RIVERPAW_BANDIT_54371:
            case NPC_RIVERPAW_BRUTE_54372:
            case NPC_RIVERPAW_HERBALIST_54373:
            case NPC_RIVERPAW_BANDIT_452:
            case NPC_RIVERPAW_BRUTE_124:
            case NPC_RIVERPAW_HERBALIST_501:
                return true;
            }
            return false;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_sentinel_hill_guardAI(creature);
    }
};

// 54371  54372  54373
class npc_riverpaw_sentinel_hill : public CreatureScript
{
public:
    npc_riverpaw_sentinel_hill() : CreatureScript("npc_riverpaw_sentinel_hill") { }

    struct npc_riverpaw_sentinel_hillAI : public ScriptedAI
    {
        npc_riverpaw_sentinel_hillAI(Creature *c) : ScriptedAI(c) { }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (IsShowfight(attacker) && me->GetHealthPct() < 70.0f)
                damage = 0;
        }

        bool IsShowfight(Unit* attacker)
        {
            if (Creature* creature = attacker->ToCreature())
            {
                if (creature->GetEntry() == NPC_SENTINEL_HILL_GUARD) return true;
                if (creature->GetEntry() == NPC_WESTFALL_BRIGADE_GUARD) return true;
            }
            return false;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_riverpaw_sentinel_hillAI(creature);
    }
};

// 449  589  594
class npc_defias_sentinel_hill : public CreatureScript
{
public:
    npc_defias_sentinel_hill() : CreatureScript("npc_defias_sentinel_hill") { }

    struct npc_defias_sentinel_hillAI : public ScriptedAI
    {
        npc_defias_sentinel_hillAI(Creature *c) : ScriptedAI(c) { }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (IsShowfight(attacker) && me->GetHealthPct() < 70.0f)
                damage = 0;
        }

        bool IsShowfight(Unit* attacker)
        {
            if (Creature* creature = attacker->ToCreature())
            {
                if (creature->GetEntry() == 42407) return true;
                if (creature->GetEntry() == 51915) return true;
            }
            return false;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_defias_sentinel_hillAI(creature);
    }
};

// 124  452  501
class npc_riverpaw_westfall : public CreatureScript
{
public:
    npc_riverpaw_westfall() : CreatureScript("npc_riverpaw_westfall") { }

    struct npc_riverpaw_westfallAI : public ScriptedAI
    {
        npc_riverpaw_westfallAI(Creature *c) : ScriptedAI(c) { }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (IsShowfight(attacker) && me->GetHealthPct() < 70.0f)
                damage = 0;
        }

        bool IsShowfight(Unit* attacker)
        {
            if (Creature* creature = attacker->ToCreature())
            {
                if (creature->GetEntry() == NPC_SENTINEL_HILL_GUARD) return true;
                if (creature->GetEntry() == NPC_WESTFALL_BRIGADE_GUARD) return true;
            }
            return false;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_riverpaw_westfallAI(creature);
    }
};

// 42635
class npc_ripsnarl_sentinel_hill_42635 : public CreatureScript
{
public:
    npc_ripsnarl_sentinel_hill_42635() : CreatureScript("npc_ripsnarl_sentinel_hill_42635") { }

    struct npc_ripsnarl_sentinel_hill_42635AI : public ScriptedAI
    {
        npc_ripsnarl_sentinel_hill_42635AI(Creature *c) : ScriptedAI(c) { }

        std::list<uint64> _playerList1;
        std::list<uint64> _playerList2;
        uint64      m_playerGUID;
        uint32      _timer;
        uint32      _phase;

        void Reset() override
        {
            _timer = 1000;
            _phase = 0;
            m_playerGUID = 0;
            me->AddUnitState(UNIT_STATE_STUNNED | UNIT_STATE_ROOT);
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_STUNNED);
            me->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_DISABLE_TURN);
        }

        void UpdateAI(uint32 diff) override
        {
            if (_timer <= diff)
            {
                _timer = 1000;
                DoWork();
            }
            else
                _timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            switch (_phase)
            {
            case 0:
                if (Player* player = me->FindNearestPlayer(10.0f, true))
                {
                    m_playerGUID = player->GetGUID();
                    if (!HasPlayerSeenVideo1(player->GetGUID()))
                    {
                        if (player->GetQuestStatus(QUEST_HOPE_FOR_THE_PEOPLE) == QUEST_STATUS_COMPLETE || player->GetQuestStatus(QUEST_FEEDING_THE_HUNGRY_AND_THE_HOPELESS) == QUEST_STATUS_INCOMPLETE)
                        {
                            _playerList1.push_back(player->GetGUID());
                            _phase = 1;
                        }
                    }
                    else if (!HasPlayerSeenVideo2(player->GetGUID()))
                    {
                        if (player->GetQuestStatus(QUEST_IN_DEFENCE_OF_WESTFALL) == QUEST_STATUS_REWARDED && player->GetQuestStatus(QUEST_SECRETS_REVEALED) != QUEST_STATUS_REWARDED)
                        {
                            _phase = 20;
                            _playerList2.push_back(player->GetGUID());
                        }
                    }
                }
                break;
            case 1:
                if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    if (Creature* marshal = me->FindNearestCreature(NPC_MARSHAL_GRYAN_STOUTMANTLE_234, 15.0f))
                        marshal->AI()->Talk(10, player);

                _timer = 7000; _phase = 2;
                break;
            case 2:
                if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    if (Creature* horatio = me->FindNearestCreature(NPC_HORATIO_LANE_42308, 15.0f))
                    {
                        horatio->AI()->Talk(10, player);
                        horatio->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                    }

                _timer = 7000; _phase = 3;
                break;
            case 3:
                if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    if (Creature* horatio = me->FindNearestCreature(NPC_HORATIO_LANE_42308, 15.0f))
                    {
                        horatio->AI()->Talk(11, player);
                        horatio->HandleEmoteCommand(EMOTE_ONESHOT_QUESTION);
                    }

                _timer = 7000; _phase = 4;
                break;
            case 4:
                if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    if (Creature* marshal = me->FindNearestCreature(NPC_MARSHAL_GRYAN_STOUTMANTLE_234, 15.0f))
                        marshal->AI()->Talk(11, player);

                _timer = 7000; _phase = 5;
                break;
            case 5:
                if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    Talk(10, player);
                _timer = 7000; _phase = 6;
                break;
            case 6:
                if (Creature* horatio = me->FindNearestCreature(NPC_HORATIO_LANE_42308, 15.0f))
                {
                    horatio->GetMotionMaster()->MovePath(423081, false);
                }
                _timer = 4000; _phase = 7;
                break;
            case 7:
                if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    if (Creature* horatio = me->FindNearestCreature(NPC_HORATIO_LANE_42308, 15.0f))
                    {
                        horatio->AI()->Talk(12, player);
                        horatio->CastSpell(horatio, 78935);
                    }

                _timer = 5000; _phase = 8;
                break;
            case 8:
                if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    if (Creature* horatio = me->FindNearestCreature(NPC_HORATIO_LANE_42308, 15.0f))
                    {
                        horatio->AI()->Talk(13, player);
                        horatio->CastSpell(horatio, 78935);
                    }

                _timer = 5000; _phase = 9;
                break;
            case 9:
                if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    if (Creature* horatio = me->FindNearestCreature(NPC_HORATIO_LANE_42308, 15.0f))
                    {
                        horatio->AI()->Talk(14, player);
                    }

                _timer = 4000; _phase = 10;
                break;
            case 10: // walk
                if (Creature* horatio = me->FindNearestCreature(NPC_HORATIO_LANE_42308, 15.0f))
                {
                    horatio->GetMotionMaster()->MovePath(423082, false);
                }
                _timer = 3000; _phase = 11;
                break;
            case 11:
                if (Creature* horatio = me->FindNearestCreature(NPC_HORATIO_LANE_42308, 15.0f))
                    if (Creature* marshal = me->FindNearestCreature(NPC_MARSHAL_GRYAN_STOUTMANTLE_234, 15.0f))
                    {
                        horatio->RemoveAura(78935);
                        horatio->SetFacingToObject(marshal);
                    }
                _phase = 0;
                break;
            case 20:
                if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    if (Creature* marshal = me->FindNearestCreature(NPC_MARSHAL_GRYAN_STOUTMANTLE_234, 15.0f))
                        marshal->AI()->Talk(12, player);

                _timer = 7000; _phase = 21;
                break;
            case 21:
                Talk(11);
                _timer = 7000; _phase = 22;
                break;
            case 22:
                if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    if (Creature* marshal = me->FindNearestCreature(NPC_MARSHAL_GRYAN_STOUTMANTLE_234, 15.0f))
                        marshal->AI()->Talk(13, player);

                _phase = 0;
                break;
            }
        }

        bool HasPlayerSeenVideo1(uint64 guid)
        {
            for (std::list<uint64>::iterator itr = _playerList1.begin(); itr != _playerList1.end(); ++itr)
                if (guid == *itr)
                    return true;

            return false;
        }
        bool HasPlayerSeenVideo2(uint64 guid)
        {
            for (std::list<uint64>::iterator itr = _playerList2.begin(); itr != _playerList2.end(); ++itr)
                if (guid == *itr)
                    return true;

            return false;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ripsnarl_sentinel_hill_42635AI(creature);
    }
};

// #############################################  Quest 26290

enum eQuest26290
{
    NPC_HELIX_GEARBREAKER = 42655,
    NPC_HELIXS_LUMBERING_OAF = 42654,
    NPC_SHADOWY_FIGURE_42662 = 42662,
    QUEST_SECRETS_OF_THE_TOWER = 26290,
    SPELL_POTION_OF_SHROUDING = 79528,
    SPELL_QUEST_CREDIT_26290 = 79534,
    SPELL_RIDE_VEHICLE_HARDCODET = 46598,
};

class npc_agent_kearnen : public CreatureScript
{
public:
    npc_agent_kearnen() : CreatureScript("npc_agent_kearnen") { }

    struct npc_agent_kearnenAI : public ScriptedAI
    {
        npc_agent_kearnenAI(Creature *c) : ScriptedAI(c) { }

        uint32      _timer;
        uint32      _phase;

        void Reset() override
        {
            _timer = 1000;
            _phase = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            if (_timer <= diff)
            {
                _timer = 1000;
                DoWork();
            }
            else
                _timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            std::list<Player*> playerList = me->FindNearestPlayers(70.0f);
            if (playerList.empty())
                return;

            for (std::list<Player*>::iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
            {
                if (Player* player = *itr)
                    if (player->GetQuestStatus(QUEST_SECRETS_OF_THE_TOWER) == QUEST_STATUS_INCOMPLETE && player->IsInCombat())
                    {
                        Unit::AttackerSet unitList = player->getAttackers();
                        if (!unitList.empty())
                            for (std::set<Unit*>::iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                                if (Creature* npc = (*itr)->ToCreature())
                                    if (npc->GetEntry() == 42656)
                                    {
                                        me->CastSpell(npc, 79526, true);
                                        Talk(0, player);
                                        _timer = 3000; // make a small delay between the shoot from here
                                        return;
                                    }
                    }
                    else if (player->GetQuestStatus(QUEST_SECRETS_OF_THE_TOWER) == QUEST_STATUS_COMPLETE)
                    {
                        if (player->GetDistance2d(me) < 10.0f)
                        {
                            Talk(1, player);
                            _timer = 30000;
                        }
                    }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_agent_kearnenAI(creature);
    }
};

class npc_helix_gearbreaker : public CreatureScript
{
public:
    npc_helix_gearbreaker() : CreatureScript("npc_helix_gearbreaker") { }

    struct npc_helix_gearbreakerAI : public ScriptedAI
    {
        npc_helix_gearbreakerAI(Creature *c) : ScriptedAI(c) { }

        uint32      _timer;
        uint32      _phase;
        Player*     _player;

        void Reset() override
        {
            _timer = 0;
            _phase = 0;
            _player = nullptr;
        }

        void StartAnim(Player* player)
        {
            if (_phase == 0)
            {
                _phase = 1;
                _timer = 5000;
                _player = player;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (_timer <= diff)
            {
                _timer = 1000;
                DoWork();
            }
            else
                _timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            Creature* shadow = me->FindNearestCreature(NPC_SHADOWY_FIGURE_42662, 10.0f);
            if (!shadow)
                return;

            if (!_player)
            {
                _phase = 0;
                _timer = 0;
            }

            switch (_phase)
            {
            case 1:
                if (_player)
                    if (_player->GetPositionZ() > 70.1f)
                    {
                        _timer = 7000; _phase = 2;
                    }
            case 2:
                me->HandleEmoteCommand(1);
                Talk(0);
                _timer = 7000; _phase = 3;
                break;
            case 3:
                shadow->HandleEmoteCommand(1);
                shadow->AI()->Talk(0);
                _timer = 7000; _phase = 4;
                break;
            case 4:
                me->HandleEmoteCommand(1);
                Talk(1);
                _timer = 7000; _phase = 5;
                break;
            case 5:
                shadow->HandleEmoteCommand(1);
                shadow->AI()->Talk(1);
                _timer = 7000; _phase = 6;
                break;
            case 6:
                me->HandleEmoteCommand(1);
                Talk(2);
                _timer = 7000; _phase = 7;
                break;
            case 7:
                shadow->HandleEmoteCommand(1);
                shadow->AI()->Talk(2);
                _timer = 7000; _phase = 8;
                break;
            case 8:
                shadow->HandleEmoteCommand(1);
                shadow->AI()->Talk(3);
                _timer = 7000; _phase = 9;
                break;
            case 9:
                me->HandleEmoteCommand(6);
                Talk(3);
                _timer = 7000; _phase = 10;
                break;
            case 10:
                shadow->HandleEmoteCommand(273);
                shadow->AI()->Talk(4);
                _timer = 3000; _phase = 11;
                break;
            case 11:
                if (_player)
                    _player->CastSpell(_player, SPELL_QUEST_CREDIT_26290);

                _player = nullptr;
                _timer = 60000; _phase = 12;
                break;
            case 12:
                _timer = 0; _phase = 0;
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_helix_gearbreakerAI(creature);
    }
};

class item_potion_of_shrouding : public ItemScript
{
public:
    item_potion_of_shrouding() : ItemScript("item_potion_of_shrouding") { }

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& targets) override
    {
        Creature* helixGear = player->FindNearestCreature(NPC_HELIX_GEARBREAKER, 50.0f);
        Creature* helixOar = player->FindNearestCreature(NPC_HELIXS_LUMBERING_OAF, 50.0f);
        if (helixGear && helixOar)
        {
            helixGear->AddAura(SPELL_RIDE_VEHICLE_HARDCODET, helixGear);
            helixGear->CastSpell(helixOar, SPELL_RIDE_VEHICLE_HARDCODET);
            CAST_AI(npc_helix_gearbreaker::npc_helix_gearbreakerAI, helixGear->AI())->StartAnim(player);
            return false;
        }

        return false;
    }
};

// ############################################# quest 26297 The Dawning of a New Day

enum eQuest26297
{
    NPC_SHADOWY_FIGURE_42680 = 42680,
    QUEST_THE_DAWNING_OF_A_NEW_DAY = 26297,
    SPELL_SUMMON_SHADOWY_FIGURE1 = 79552,
    SPELL_SUMMON_SHADOWY_FIGURE2 = 79551,
};

class npc_van_cleef_dummy : public CreatureScript
{
public:
    npc_van_cleef_dummy() : CreatureScript("npc_van_cleef_dummy") { }

    struct npc_van_cleef_dummyAI : public ScriptedAI
    {
        npc_van_cleef_dummyAI(Creature *c) : ScriptedAI(c) { }

        uint32      _timer;
        uint32      _phase;
        Player*     _player;
        Creature*   _shadowy;

        void Reset() override
        {
            _timer = 1000;
            _phase = 0;
            _player = nullptr;
            _shadowy = nullptr;
        }

        void JustSummoned(Creature* summon)
        {
            summon->CastSpell(summon, 79192);
            _shadowy = summon;
        }

        void UpdateAI(uint32 diff) override
        {
            if (_timer <= diff)
            {
                _timer = 1000;
                DoWork();
            }
            else
                _timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            switch (_phase)
            {
            case 0:
            {
                std::list<Player*> playerList = me->FindNearestPlayers(25.0);
                if (playerList.empty())
                    return;

                for (std::list<Player*>::iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                {
                    Player* player = (*itr);
                    if (player->GetQuestStatus(QUEST_THE_DAWNING_OF_A_NEW_DAY) == QUEST_STATUS_INCOMPLETE)
                    {
                        _player = player;
                        _phase = 1; _timer = 1000;
                        me->CastSpell(me, SPELL_SUMMON_SHADOWY_FIGURE1);
                        return;
                    }
                }
                break;
            }
            case 1:
                _shadowy->AI()->Talk(0);
                _phase = 2; _timer = 7000;
                break;
            case 2:
                AwakeAllHomeless();
                _phase = 3; _timer = 5000;
                break;
            case 3:
                _shadowy->AI()->Talk(1);
                _phase = 4; _timer = 7000;
                break;
            case 4:
                _shadowy->AI()->Talk(2);
                _phase = 5; _timer = 7000;
                break;
            case 5:
                _shadowy->AI()->Talk(3);
                _phase = 6; _timer = 7000;
                break;
            case 6:
                _shadowy->AI()->Talk(4);
                _phase = 7; _timer = 7000;
                break;
            case 7:
                _shadowy->AI()->Talk(5);
                _phase = 8; _timer = 7000;
                break;
            case 8:
                _shadowy->AI()->Talk(6);
                _phase = 9; _timer = 7000;
                break;
            case 9:
                _shadowy->AI()->Talk(7);
                _phase = 10; _timer = 7000;
                break;
            case 10:
                if (_player)
                    _player->KilledMonsterCredit(42680);

                _shadowy->DespawnOrUnsummon(8000);
                _phase = 11; _timer = 10000;
                break;
            case 11:
                LetSleepAllHomeless();
                _phase = 0; _timer = 0;
                break;
            }
        }

        void AwakeAllHomeless()
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, NPC_HOMELESS_STORMWIND_CITIZEN_42384, 25.0f);
            GetCreatureListWithEntryInGrid(creatureList, me, NPC_HOMELESS_STORMWIND_CITIZEN_42386, 25.0f);
            if (creatureList.empty())
                return;

            for (std::list<Creature*>::iterator itr = creatureList.begin(); itr != creatureList.end(); ++itr)
            {
                Creature* creature = (*itr);
                creature->RemoveAura(SPELL_COSMETIC_SLEEP_ZZZ);
                creature->SetByteValue(UNIT_FIELD_BYTES_1, 0, UNIT_STAND_STATE_STAND);
            }
        }

        void LetSleepAllHomeless()
        {
            std::list<Creature*> creatureList;
            GetCreatureListWithEntryInGrid(creatureList, me, NPC_HOMELESS_STORMWIND_CITIZEN_42384, 25.0f);
            GetCreatureListWithEntryInGrid(creatureList, me, NPC_HOMELESS_STORMWIND_CITIZEN_42386, 25.0f);
            if (creatureList.empty())
                return;

            for (std::list<Creature*>::iterator itr = creatureList.begin(); itr != creatureList.end(); ++itr)
            {
                Creature* creature = (*itr);
                creature->AddAura(SPELL_COSMETIC_SLEEP_ZZZ, creature);
                creature->SetByteValue(UNIT_FIELD_BYTES_1, 0, UNIT_STAND_STATE_SLEEP);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_van_cleef_dummyAI(creature);
    }
};

// ############################################# quest 26320 Vision of the past

enum eQuest26320
{
    NPC_VANESSA_VAN_CLEEF = 42371,
    NPC_VISION_OF_THE_PAST = 42693,
    NPC_EDWIN_VAN_CLEEF = 42697,
    NPC_DEFIAS_BLACKGUARD = 42698,
    NPC_ALLIANCE_WARRIOR = 42699,
    NPC_ALLIANCE_PRIEST = 42700,
    NPC_ALLIANCE_ROGUE = 42701,
    NPC_ALLIANCE_HUNTER = 42702,
    NPC_ALLIANCE_MAGE = 42703,

    QUEST_VISION_OF_THE_PAST = 26320,
    SPELL_VISION_OF_THE_PAST1 = 79586,
    SPELL_VISION_OF_THE_PAST2 = 79587,  // give us the aura for phaseId 231
    SPELL_VISION_OF_THE_PAST_FINISH = 79620,
};

// 42693
class npc_vision_of_the_past : public CreatureScript
{
public:
    npc_vision_of_the_past() : CreatureScript("npc_vision_of_the_past") { }

    struct npc_vision_of_the_past_VehicleAI : public VehicleAI
    {
        npc_vision_of_the_past_VehicleAI(Creature *c) : VehicleAI(c) { }

        EventMap    m_events;
        uint64      m_playerGUID;
        uint64      m_edwinGUID;
        uint64      m_blackguard1GUID;
        uint64      m_blackguard2GUID;
        uint64      m_warrierGUID;
        uint64      m_priestGUID;
        uint64      m_rogueGUID;
        uint64      m_hunterGUID;
        uint64      m_mageGUID;
        uint64      m_vanessaGUID;

        void Reset() override
        {
            m_playerGUID = 0;
            m_edwinGUID = 0;
            m_blackguard1GUID = 0;
            m_blackguard2GUID = 0;
            m_warrierGUID = 0;
            m_priestGUID = 0;
            m_rogueGUID = 0;
            m_hunterGUID = 0;
            m_mageGUID = 0;
            m_vanessaGUID = 0;
            me->SetDisplayId(11686);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Player* player = summoner->ToPlayer())
                if (player->GetQuestStatus(QUEST_VISION_OF_THE_PAST) == QUEST_STATUS_INCOMPLETE)
                    m_playerGUID = player->GetGUID();
        }

        void JustSummoned(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
            case NPC_EDWIN_VAN_CLEEF:
                m_edwinGUID = summon->GetGUID();
                break;
            case NPC_DEFIAS_BLACKGUARD:
                if (m_blackguard1GUID == 0)
                    m_blackguard1GUID = summon->GetGUID();
                else if (m_blackguard2GUID == 0)
                    m_blackguard2GUID = summon->GetGUID();
                break;
            case NPC_ALLIANCE_WARRIOR:
                m_warrierGUID = summon->GetGUID();
                break;
            case NPC_ALLIANCE_PRIEST:
                m_priestGUID = summon->GetGUID();
                break;
            case NPC_ALLIANCE_ROGUE:
                m_rogueGUID = summon->GetGUID();
                break;
            case NPC_ALLIANCE_HUNTER:
                m_hunterGUID = summon->GetGUID();
                break;
            case NPC_ALLIANCE_MAGE:
                m_mageGUID = summon->GetGUID();
                break;
            case NPC_VANESSA_VAN_CLEEF:
                m_vanessaGUID = summon->GetGUID();
                break;
            }
        }

        void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
        {
            if (Player* player = passenger->ToPlayer())
                if (apply)
                {
                    m_events.RescheduleEvent(EVENT_START_FLYING, 10);
                    m_events.RescheduleEvent(EVENT_MASTER_RESET, 360000);
                }
                else
                {
                    me->DespawnOrUnsummon(10);
                }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE && id == 5)
            {
                m_events.ScheduleEvent(EVENT_START_TALK, 10);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MASTER_RESET:
                {
                    me->DespawnOrUnsummon(10);
                    break;
                }
                case EVENT_START_FLYING:
                {
                    me->NearTeleportTo(-97.8f, -690.0f, 24.4f, 4.5f);
                    m_events.ScheduleEvent(EVENT_START_FLY, 200);
                    break;
                }
                case EVENT_START_FLY:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        me->SetVisible(false);
                        player->SetVisible(false);
                        me->SetDisableGravity(true);
                        me->SetCanFly(true);
                        me->SetSpeed(MOVE_WALK, 6.0f, true);
                        me->SetSpeed(MOVE_FLIGHT, 6.0f, true);
                        me->SetWalk(false);
                        me->GetMotionMaster()->MovePath(426930, false);
                    }
                    break;
                }
                case EVENT_START_TALK:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        Talk(0, player); /* 5 Years ago... */

                    SpawnVisionMember();

                    m_events.ScheduleEvent(EVENT_TALK_PART_00, 6000);
                    break;
                }
                case EVENT_TALK_PART_00:
                {
                    if (Creature* warrier = ObjectAccessor::GetCreature(*me, m_warrierGUID))
                        warrier->AI()->Talk(0); /* There's nowhere left to hide, VanCleef! The Defias are THROUGH! */

                    m_events.ScheduleEvent(EVENT_TALK_PART_01, 6000);
                    break;
                }
                case EVENT_TALK_PART_01:
                {
                    if (Creature* warrier = ObjectAccessor::GetCreature(*me, m_warrierGUID))
                        warrier->AI()->Talk(1); /* We're here to finish this! Face us, coward! */

                    if (Creature* cleef = ObjectAccessor::GetCreature(*me, m_edwinGUID))
                        cleef->GetMotionMaster()->MovePath(4269700, false);

                    m_events.ScheduleEvent(EVENT_TALK_PART_02, 6000);
                    break;
                }
                case EVENT_TALK_PART_02:
                {
                    if (Creature* cleef = ObjectAccessor::GetCreature(*me, m_edwinGUID))
                        cleef->AI()->Talk(0); /* None may callenge the Brotherhood! */

                    m_events.ScheduleEvent(EVENT_TALK_PART_03, 3000);
                    break;
                }
                case EVENT_TALK_PART_03:
                {
                    if (Creature* cleef = ObjectAccessor::GetCreature(*me, m_edwinGUID))
                        cleef->AI()->Talk(1); /* %s calls more of his allies out of the shadows */

                    SpawnBlackguards();

                    m_events.ScheduleEvent(EVENT_TALK_PART_04, 2000);
                    break;
                }
                case EVENT_TALK_PART_04:
                {
                    if (Creature* defias = ObjectAccessor::GetCreature(*me, m_blackguard1GUID))
                    {
                        defias->AI()->Talk(0); /* %s jumps out of the shadows! */
                        defias->GetMotionMaster()->MovePath(4269801, false);
                    }

                    if (Creature* defias = ObjectAccessor::GetCreature(*me, m_blackguard2GUID))
                    {
                        defias->AI()->Talk(0); /* %s jumps out of the shadows! */
                        defias->GetMotionMaster()->MovePath(4269802, false);
                    }

                    m_events.ScheduleEvent(EVENT_TALK_PART_05, 2000);
                    break;
                }
                case EVENT_TALK_PART_05:
                {
                    if (Creature* cleef = ObjectAccessor::GetCreature(*me, m_edwinGUID))
                    {
                        cleef->AI()->Talk(2); /* Lapdogs, all of you! */
                        cleef->SetReactState(REACT_AGGRESSIVE);
                    }

                    if (Creature* defias = ObjectAccessor::GetCreature(*me, m_blackguard1GUID))
                    {
                        defias->SetReactState(REACT_AGGRESSIVE);
                    }

                    if (Creature* defias = ObjectAccessor::GetCreature(*me, m_blackguard2GUID))
                    {
                        defias->SetReactState(REACT_AGGRESSIVE);
                    }

                    /* ToDo: here the fight is started.. */

                    m_events.ScheduleEvent(EVENT_TALK_PART_06, 5000);
                    break;
                }
                case EVENT_TALK_PART_06:
                {
                    if (Creature* cleef = ObjectAccessor::GetCreature(*me, m_edwinGUID))
                        cleef->AI()->Talk(3); /* Fools! Our cause is righteous! */

                    m_events.ScheduleEvent(EVENT_TALK_PART_07, 5000);
                    break;
                }
                case EVENT_TALK_PART_07:
                {
                    if (Creature* cleef = ObjectAccessor::GetCreature(*me, m_edwinGUID))
                        cleef->AI()->Talk(2); /* Lapdogs, all of you! */

                    m_events.ScheduleEvent(EVENT_TALK_PART_08, 5000);
                    break;
                }
                case EVENT_TALK_PART_08:
                {
                    if (Creature* cleef = ObjectAccessor::GetCreature(*me, m_edwinGUID))
                        cleef->AI()->Talk(4); /* The Brotherhood shall prevail! */

                    m_events.ScheduleEvent(EVENT_START_FIGHT, 5000);
                    break;
                }
                case EVENT_START_FIGHT:
                {

                    /* ToDo: fight until edwin & guards are death*/

                    if (Creature* warrier = ObjectAccessor::GetCreature(*me, m_warrierGUID))
                    {
                        if (Creature* cleef = ObjectAccessor::GetCreature(*me, m_edwinGUID))
                            warrier->Kill(cleef);
                        if (Creature* defias = ObjectAccessor::GetCreature(*me, m_blackguard1GUID))
                            warrier->Kill(defias);
                        if (Creature* defias = ObjectAccessor::GetCreature(*me, m_blackguard2GUID))
                            warrier->Kill(defias);
                    }
                    m_events.ScheduleEvent(EVENT_TALK_PART_09, 3000);
                    break;
                }
                case EVENT_TALK_PART_09:
                {
                    if (Creature* warrier = ObjectAccessor::GetCreature(*me, m_warrierGUID))
                        warrier->AI()->Talk(2); /* Victory for the Alliance! Glory to Stormwind! */

                    m_events.ScheduleEvent(EVENT_TALK_PART_10, 6000);
                    break;
                }

                case EVENT_TALK_PART_10:
                {
                    if (Creature* warrier = ObjectAccessor::GetCreature(*me, m_warrierGUID))
                    {
                        warrier->AI()->Talk(3); /* Let us return to Sentinel Hill, allies, and inform Gryan of VanCleef's demise! */
                        warrier->GetMotionMaster()->MovePath(4269900, false);
                    }
                    if (Creature* priest = ObjectAccessor::GetCreature(*me, m_priestGUID))
                        priest->GetMotionMaster()->MovePath(4270000, false);
                    if (Creature* rogue = ObjectAccessor::GetCreature(*me, m_rogueGUID))
                        rogue->GetMotionMaster()->MovePath(4270100, false);
                    if (Creature* hunter = ObjectAccessor::GetCreature(*me, m_hunterGUID))
                        hunter->GetMotionMaster()->MovePath(4270200, false);
                    if (Creature* mage = ObjectAccessor::GetCreature(*me, m_mageGUID))
                        mage->GetMotionMaster()->MovePath(4270300, false);
                    m_events.ScheduleEvent(EVENT_TALK_PART_11, 8000);
                    break;
                }
                case EVENT_TALK_PART_11:
                {
                    SpawnVanessa();

                    if (Creature* vanessa = ObjectAccessor::GetCreature(*me, m_vanessaGUID))
                        vanessa->GetMotionMaster()->MovePath(4237100, false);

                    m_events.ScheduleEvent(EVENT_TALK_PART_12, 5000);
                    break;
                }
                case EVENT_TALK_PART_12:
                {
                    if (Creature* vanessa = ObjectAccessor::GetCreature(*me, m_vanessaGUID))
                        vanessa->AI()->Talk(0); /* Daddy... */

                    m_events.ScheduleEvent(EVENT_TALK_PART_13, 3000);
                    break;
                }
                case EVENT_TALK_PART_13:
                {
                    DespawnAllSummonedMembers();

                    m_events.ScheduleEvent(EVENT_TALK_PART_14, 3000);
                    break;
                }
                case EVENT_TALK_PART_14:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        player->CastSpell(player, SPELL_VISION_OF_THE_PAST_FINISH, true);
                        player->KilledMonsterCredit(NPC_VANESSA_VAN_CLEEF);
                    }
                    m_events.ScheduleEvent(EVENT_TALK_PART_15, 6000);
                    break;
                }
                case EVENT_TALK_PART_15:
                {
                    if (Creature* vanessa = ObjectAccessor::GetCreature(*me, m_vanessaGUID))
                        vanessa->DespawnOrUnsummon(1);

                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        me->RemoveAura(SPELL_VISION_OF_THE_PAST1);
                        me->RemoveAura(SPELL_VISION_OF_THE_PAST2);
                        player->RemoveAura(SPELL_VISION_OF_THE_PAST1);
                        player->RemoveAura(SPELL_VISION_OF_THE_PAST2);
                        player->SetVisible(true);
                        player->TeleportTo(0, -10916.2f, 1521.1f, 51.552f, 4.587f);
                    }
                    m_events.ScheduleEvent(EVENT_TALK_PART_16, 10);
                    break;
                }
                case EVENT_TALK_PART_16:
                {
                    me->DespawnOrUnsummon(10);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void SpawnVisionMember()
        {
            me->SummonCreature(NPC_EDWIN_VAN_CLEEF, -87.37f, -819.90f, 39.30f, 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
            me->SummonCreature(NPC_ALLIANCE_WARRIOR, -63.06597f, -819.1649f, 41.35357f, 3.054326f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
            me->SummonCreature(NPC_ALLIANCE_PRIEST, -60.69618f, -819.1945f, 41.58845f, 3.054326f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
            me->SummonCreature(NPC_ALLIANCE_ROGUE, -61.40104f, -821.882f, 41.52324f, 3.106686f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
            me->SummonCreature(NPC_ALLIANCE_HUNTER, -58.5382f, -819.1337f, 41.79993f, 3.071779f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
            me->SummonCreature(NPC_ALLIANCE_MAGE, -61.44097f, -816.7239f, 41.51037f, 2.96706f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
        }

        void SpawnBlackguards()
        {
            me->SummonCreature(NPC_DEFIAS_BLACKGUARD, -78.28f, -824.78f, 40.00f, 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
            me->SummonCreature(NPC_DEFIAS_BLACKGUARD, -77.81f, -815.10f, 40.02f, 0.2f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300000);
        }

        void SpawnVanessa()
        {
            me->SummonCreature(NPC_VANESSA_VAN_CLEEF, -82.94046f, -819.675f, 39.62264f, 6.253996f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 120000);
        }

        void DespawnAllSummonedMembers()
        {
            if (Creature* warrier = ObjectAccessor::GetCreature(*me, m_warrierGUID))
                warrier->DespawnOrUnsummon(1);
            if (Creature* priest = ObjectAccessor::GetCreature(*me, m_priestGUID))
                priest->DespawnOrUnsummon(1);
            if (Creature* rogue = ObjectAccessor::GetCreature(*me, m_rogueGUID))
                rogue->DespawnOrUnsummon(1);
            if (Creature* hunter = ObjectAccessor::GetCreature(*me, m_hunterGUID))
                hunter->DespawnOrUnsummon(1);
            if (Creature* mage = ObjectAccessor::GetCreature(*me, m_mageGUID))
                mage->DespawnOrUnsummon(1);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_vision_of_the_past_VehicleAI(creature);
    }
};

// 43515
class npc_moonbrook_player_trigger_43515 : public CreatureScript
{
public:
    npc_moonbrook_player_trigger_43515() : CreatureScript("npc_moonbrook_player_trigger_43515") { }

    struct npc_moonbrook_player_trigger_43515AI : public ScriptedAI
    {
        npc_moonbrook_player_trigger_43515AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap m_events;
        std::map<uint64, uint32> pList;

        void Reset() override
        {
            m_events.RescheduleEvent(EVENT_COOLDOWN_00, 1000);
        }

        void CreatureMoveInLineOfSight(Unit* who) override
        {
            if (Player* player = who->ToPlayer())
                if (player->GetQuestStatus(QUEST_VISION_OF_THE_PAST) == QUEST_STATUS_INCOMPLETE)
                    if (me->GetPosition().GetExactDist2d(player) < 10.0f  && abs(me->GetPositionZ() - player->GetPositionZ()) < 2.0f)
                        if (CanPlayerTalk(player->GetGUID()))
                        {
                            Talk(1, player);
                            pList[player->GetGUID()] = 30;
                        }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_COOLDOWN_00:
                {
                    if (pList.size() > 0)
                    {
                        std::list<uint64> eList;
                        for (auto pGuid : pList)
                            if (pGuid.second > 0)
                            {
                                pList[pGuid.first] = pGuid.second - 1;
                                if (pList[pGuid.first] == 0)
                                    eList.push_back(pGuid.first);
                            }

                        for (auto guid : eList)
                            pList.erase(guid);
                    }

                    m_events.RescheduleEvent(EVENT_COOLDOWN_00, 1000);
                    break;
                }
                }
            }
        }

        bool CanPlayerTalk(uint64 playerGUID)
        {
            if (pList.size() > 0)
                if (pList.find(playerGUID) != pList.end())
                    return false;

            return true;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_moonbrook_player_trigger_43515AI(creature);
    }
};

// ############################################# quest 26322    Rise of the Brotherhood

enum eQuest26322
{
    QUEST_RISE_OF_THE_BROTHERHOOD = 26322,
    // NPC_MARSHAL_GRYAN_STOUTMANTLE_234 = 234,
    NPC_HORATIO_LANE_42744 = 42744,
    NPC_STORMWIND_INVESTIGATOR_42745 = 42745,
    NPC_RIPSNARL_42748 = 42748,
    NPC_HOPE_SALDEAN_42749 = 42749,
    NPC_MARSHAL_GRYAN_STOUTMANTLE_42750 = 42750,
    NPC_CAPTAIN_DANUVIN = 42751,
    NPC_SCOUT_GALIAAN = 42752,
    NPC_KING_WARIAN_WRYNN = 29611,
    NPC_GLUBTOK_42755 = 42755,
    NPC_HELIX_GEARBREAKER_42753 = 42753,
    NPC_DEFIAS_BLACKGUARD_42769 = 42769,
    NPC_SENTINEL_HILL_FIRE_TRIGGER = 42793,
    SPELL_DESPAWN_ROB_ACTORS = 79672,
    SPELL_SUMMON_All_ACTORS = 79679,
    SPELL_GENERIC_TRIGGER_1_GRYAN = 79785,
    SPELL_GENERIC_TRIGGER_1_HOPE = 79786,
    SPELL_GENERIC_TRIGGER_1_RIPSNARL = 79787,
    SPELL_GENERIC_TRIGGER_1_HORATIO = 79788,
    SPELL_GENERIC_TRIGGER_10_BLACKGUARDS = 79789,
    SPELL_GENERIC_TRIGGER_2_GRYAN = 79790,
    SPELL_GENERIC_TRIGGER_10_HELIX = 79791,
    SPELL_GENERIC_TRIGGER_10_RIPSNARL = 79792,
    SPELL_GENERIC_TRIGGER_10_GLUBTOK = 79793,
    SPELL_GENERIC_TRIGGER_10_HOPE = 79794,
    SPELL_GENERIC_TORCH_TOSS_TRIGGER = 79779,
    SPELL_VANESSA_TRANSFORM = 79709,
    SPELL_SPAWN_SMOKE = 79705,
    SPELL_SUMMON_GLUBTOK_42755 = 79762,
    SPELL_SUMMON_HELIX_42753 = 79763,
    SPELL_SUMMON_DEFIAS_BLACKGUARD1 = 79708,
    SPELL_SUMMON_DEFIAS_BLACKGUARD2 = 79712,
    SPELL_SIMPLE_TELEPORT = 64195,
    SPELL_TIE_UP_GOOD_GUYS1 = 79723,
    SPELL_TIE_UP_GOOD_GUYS2 = 79795,
    SPELL_TIED_UP = 79724,
    SPELL_RIPSNARL_TRANSFORM_HUMAN = 79745,
    SPELL_ADMIRALS_HAT = 79750,
    SPELL_QUEST_CREDIT_DEFIAS_FINALE_EVENT = 79758,
    SPELL_TOSS_TORCH = 79778,
    SPELL_CLIFFWALKER_FIRE = 78573,
};

// 234
class npc_marshal_gryan_stoutmantle_234 : public CreatureScript
{
public:
    npc_marshal_gryan_stoutmantle_234() : CreatureScript("npc_marshal_gryan_stoutmantle_234") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_RISE_OF_THE_BROTHERHOOD)
        {
            creature->AI()->SetGUID(player->GetGUID(), PLAYER_GUID);
            creature->AI()->DoAction(1);
        }

        return true;
    }

    struct npc_marshal_gryan_stoutmantle_234AI : public ScriptedAI
    {
        npc_marshal_gryan_stoutmantle_234AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap  m_events;
        uint64    m_playerGUID;

        void Reset() override
        {
            m_playerGUID = 0;
        }

        void DoAction(int32 /*param*/) override
        {
            m_events.ScheduleEvent(EVENT_START_PLAY, 250);
        }

        void SetGUID(uint64 guid, int32 id) override
        {
            switch (id)
            {
            case PLAYER_GUID:
            {
                switch (id)
                {
                case PLAYER_GUID:
                    m_playerGUID = guid;
                }
                break;
            }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_PLAY:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        player->CastSpell(player, SPELL_SUMMON_All_ACTORS);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_marshal_gryan_stoutmantle_234AI(creature);
    }
};

// 523
class npc_thor_523 : public CreatureScript
{
public:
    npc_thor_523() : CreatureScript("npc_thor_523") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestStatus(QUEST_RISE_OF_THE_BROTHERHOOD) == QUEST_STATUS_COMPLETE)
        {
            player->RemoveAllAuras();
            creature->CastSpell(creature, SPELL_DESPAWN_ROB_ACTORS);
        }

        return false;
    }
};

// 42744
class npc_lieutenant_horatio_laine_42744 : public CreatureScript
{
public:
    npc_lieutenant_horatio_laine_42744() : CreatureScript("npc_lieutenant_horatio_laine_42744") { }

    struct npc_lieutenant_horatio_laine_42744AI : public ScriptedAI
    {
        npc_lieutenant_horatio_laine_42744AI(Creature* creature) : ScriptedAI(creature) { }

        uint32  _phase;
        uint32  _timer;

        void Reset() override
        {
            me->SetOrientation(4.398f);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            switch (spell->Id)
            {
            case SPELL_DESPAWN_ROB_ACTORS:
                me->DespawnOrUnsummon(10);
                break;
            case SPELL_GENERIC_TRIGGER_1_HORATIO:
            {
                _phase = 1;
                _timer = 1500;
                break;
            }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (_timer <= diff)
            {
                _timer = 1000;
                DoWork();
            }
            else
                _timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            switch (_phase)
            {
            case 0:
                break;
            case 1: // 51:22
                Talk(0);

                _timer = 3000; _phase = 2;
                break;
            case 2: // 51:25
                Talk(1);

                _timer = 4000; _phase = 3;
                break;
            case 3:
                me->CastSpell(me, SPELL_TIED_UP);
                _timer = 5000; _phase = 4;
                break;
            case 4:
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lieutenant_horatio_laine_42744AI(creature);
    }
};

// 42748
class npc_ripsnarl_42748 : public CreatureScript
{
public:
    npc_ripsnarl_42748() : CreatureScript("npc_Ripsnarl_42748") { }

    struct npc_ripsnarl_42748AI : public ScriptedAI
    {
        npc_ripsnarl_42748AI(Creature* creature) : ScriptedAI(creature) { }

        uint32  _phase;
        uint32  _timer;
        uint64  m_playerGUID;

        void Reset() override
        {
            m_playerGUID = 0;
            _phase = 0;
            _timer = 0;
            me->SetOrientation(0.489f);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Player* player = summoner->ToPlayer())
                m_playerGUID = player->GetGUID();
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_GENERIC_TRIGGER_1_RIPSNARL)
            {
                _phase = 1;
                _timer = 300;
            }
            else if (spell->Id == SPELL_GENERIC_TRIGGER_10_RIPSNARL)
            {
                me->GetMotionMaster()->MovePoint(1201, -10516.03f, 1062.179f, 55.78939f);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
                switch (id)
                {
                case 1201:
                {
                    me->DespawnOrUnsummon(1000);
                    break;
                }
                }
        }

        void UpdateAI(uint32 diff) override
        {
            if (_timer <= diff)
            {
                _timer = 1000;
                DoWork();
            }
            else
                _timer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        void DoWork()
        {
            switch (_phase)
            {
            case 0:
                break;
            case 1:
                me->CastSpell(me, SPELL_RIPSNARL_TRANSFORM_HUMAN, true);
                //me->SetDisplayId(33062);

                _timer = 3700; _phase = 2;
                break;
            case 2:
                me->GetMotionMaster()->MovePoint(0, -10514.8f, 1045.6f, 60.80753f);
                Talk(0);

                _timer = 3000; _phase = 3;
                break;
            case 3:
                me->GetMotionMaster()->MovePath(427481, false);

                _timer = 2000; _phase = 4;
                break;
            case 4:
                me->CastSpell(me, SPELL_ADMIRALS_HAT, true);

                _timer = 5000; _phase = 5;
                break;
            case 5:
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ripsnarl_42748AI(creature);
    }
};

// 42751
class npc_captain_danuvin_42751 : public CreatureScript
{
public:
    npc_captain_danuvin_42751() : CreatureScript("npc_captain_danuvin_42751") { }

    struct npc_captain_danuvin_42751AI : public ScriptedAI
    {
        npc_captain_danuvin_42751AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetOrientation(1.920f);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            switch (spell->Id)
            {
            case SPELL_DESPAWN_ROB_ACTORS:
                me->DespawnOrUnsummon(10);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_captain_danuvin_42751AI(creature);
    }
};

// 42752
class npc_scout_galiaan_42752 : public CreatureScript
{
public:
    npc_scout_galiaan_42752() : CreatureScript("npc_scout_galiaan_42752") { }

    struct npc_scout_galiaan_42752AI : public ScriptedAI
    {
        npc_scout_galiaan_42752AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetOrientation(1.920f);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            switch (spell->Id)
            {
            case SPELL_DESPAWN_ROB_ACTORS:
                me->DespawnOrUnsummon(10);
                break;
            }
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_scout_galiaan_42752AI(creature);
    }
};

// 42745
class npc_stormwind_investigator_42745 : public CreatureScript
{
public:
    npc_stormwind_investigator_42745() : CreatureScript("npc_stormwind_investigator_42745") { }

    struct npc_stormwind_investigator_42745AI : public ScriptedAI
    {
        npc_stormwind_investigator_42745AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetOrientation(4.555f);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            switch (spell->Id)
            {
            case SPELL_DESPAWN_ROB_ACTORS:
                me->DespawnOrUnsummon(10);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_stormwind_investigator_42745AI(creature);
    }
};

// 42753
class npc_helix_gearbreaker_42753 : public CreatureScript
{
public:
    npc_helix_gearbreaker_42753() : CreatureScript("npc_helix_gearbreaker_42753") { }

    struct npc_helix_gearbreaker_42753AI : public ScriptedAI
    {
        npc_helix_gearbreaker_42753AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->GetMotionMaster()->MovePath(427531, false);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_GENERIC_TRIGGER_10_HELIX)
            {
                me->GetMotionMaster()->MovePoint(1201, -10519.46f, 1061.701f, 55.5351f);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
                switch (id)
                {
                case 1201:
                {
                    me->DespawnOrUnsummon(1000);
                    break;
                }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_helix_gearbreaker_42753AI(creature);
    }
};

// 42755
class npc_glubtok_42755 : public CreatureScript
{
public:
    npc_glubtok_42755() : CreatureScript("npc_glubtok_42755") { }

    struct npc_glubtok_42755AI : public ScriptedAI
    {
        npc_glubtok_42755AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetOrientation(4.642f);
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            if (spell->Id == SPELL_GENERIC_TRIGGER_10_GLUBTOK)
            {
                me->GetMotionMaster()->MovePath(427551, false);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE)
                switch (id)
                {
                case 3:
                {
                    me->DespawnOrUnsummon(1000);
                    break;
                }
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_glubtok_42755AI(creature);
    }
};

// 42769
class npc_defias_blackguard_42769 : public CreatureScript
{
public:
    npc_defias_blackguard_42769() : CreatureScript("npc_defias_blackguard_42769") { }

    struct npc_defias_blackguard_42769AI : public ScriptedAI
    {
        npc_defias_blackguard_42769AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap m_events;

        void Reset() override
        {
            me->CastSpell(me, 79705, true); // ID - 79705 Spawn Smoke (Defias Blackguard)
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == 2)
            {
                m_events.RescheduleEvent(EVENT_START_FIGHT, 250);
            }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_GENERIC_TRIGGER_10_BLACKGUARDS:
            {
                me->GetMotionMaster()->MovePath(4276901 + urand(0, 13), false);
                break;
            }
            case SPELL_GENERIC_TORCH_TOSS_TRIGGER:
            {
                m_events.RescheduleEvent(EVENT_START_WALK, 250);
                break;
            }
            case SPELL_DESPAWN_ROB_ACTORS:
            {
                me->DespawnOrUnsummon(10);
                break;
            }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_WALK:
                {
                    me->RemoveAura(SPELL_TOSS_TORCH);
                    me->GetMotionMaster()->MovePath(4276901 + urand(0, 13), false);
                    break;
                }
                case EVENT_START_FIGHT:
                {
                    if (Creature* npc = me->FindNearestCreature(NPC_SENTINEL_HILL_FIRE_TRIGGER, 50.0f))
                        npc->CastSpell(npc, SPELL_CLIFFWALKER_FIRE, true);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_defias_blackguard_42769AI(creature);
    }
};

// 42771
class npc_rise_of_the_brotherhood_event_dummy_42771 : public CreatureScript
{
public:
    npc_rise_of_the_brotherhood_event_dummy_42771() : CreatureScript("npc_rise_of_the_brotherhood_event_dummy_42771") { }

    struct npc_rise_of_the_brotherhood_event_dummy_42771AI : public ScriptedAI
    {
        npc_rise_of_the_brotherhood_event_dummy_42771AI(Creature* creature) : ScriptedAI(creature) { }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
            case 79708:
            {
                me->CastSpell(me, 79712, true);
                break;
            }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_rise_of_the_brotherhood_event_dummy_42771AI(creature);
    }
};

// 42749
class npc_hope_saldean_42749 : public CreatureScript
{
public:
    npc_hope_saldean_42749() : CreatureScript("npc_hope_saldean_42749") { }

    struct npc_hope_saldean_42749AI : public ScriptedAI
    {
        npc_hope_saldean_42749AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap m_events;
        uint64   m_playerGUID;
        uint64   m_gryanGUID;
        uint64   m_glubtokGUID;
        uint64   m_ripsnarlGUID;
        uint32   m_point;

        void Reset() override
        {
            m_playerGUID = 0;
            m_gryanGUID = 0;
            m_glubtokGUID = 0;
            m_ripsnarlGUID = 0;
            m_point = 0;
            me->SetOrientation(2.024f);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Player* player = summoner->ToPlayer())
                m_playerGUID = player->GetGUID();
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE)
            {
                if (m_point == 1204 && id == 3)
                    m_events.ScheduleEvent(EVENT_TALK_PART_15, 100);
            }
            else if (type == POINT_MOTION_TYPE)
                switch (id)
                {
                case 1201:
                {
                    Talk(0);
                    m_events.ScheduleEvent(EVENT_TALK_PART_00, 5000);
                    break;
                }
                case 1202:
                {
                    me->HandleEmoteCommand(54);
                    m_events.ScheduleEvent(EVENT_TALK_PART_10, 2000);
                    break;
                }
                case 1203:
                {
                    m_events.ScheduleEvent(EVENT_TALK_PART_13, 1000);
                    break;
                }
                case 1205:
                {
                    m_events.ScheduleEvent(EVENT_TALK_PART_20, 1000);
                    break;
                }
                }
        }

        void SpellHit(Unit* caster, SpellInfo const* spell)
        {
            switch (spell->Id)
            {
            case SPELL_GENERIC_TRIGGER_1_HOPE:
            {
                m_events.RescheduleEvent(EVENT_START_WALK, 1000);
                break;
            }
            case SPELL_GENERIC_TRIGGER_10_HOPE:
            {
                me->DespawnOrUnsummon(2000);
                break;
            }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_WALK:
                {
                    me->GetMotionMaster()->MovePoint(1201, -10507.4f, 1042.33f, 60.518f);
                    break;
                }
                case EVENT_TALK_PART_00:
                {
                    if (Creature* gryan = GetGryan())
                    {
                        gryan->SetFacingToObject(me);
                        gryan->AI()->Talk(5);
                    }
                    m_events.ScheduleEvent(EVENT_TALK_PART_01, 4000);
                    break;
                }
                case EVENT_TALK_PART_01:
                {
                    Talk(1);
                    m_events.ScheduleEvent(EVENT_TALK_PART_02, 5000);
                    break;
                }
                case EVENT_TALK_PART_02:
                {
                    Talk(2);
                    m_events.ScheduleEvent(EVENT_TALK_PART_03, 7000);
                    break;
                }
                case EVENT_TALK_PART_03:
                {
                    me->CastSpell(me, SPELL_VANESSA_TRANSFORM, true);
                    m_events.ScheduleEvent(EVENT_TALK_PART_04, 2000);
                    break;
                }
                case EVENT_TALK_PART_04:
                {
                    Talk(3);
                    m_events.ScheduleEvent(EVENT_TALK_PART_05, 2000);
                    break;
                }
                case EVENT_TALK_PART_05:
                {
                    if (Player* player = me->FindNearestPlayer(25.0f, true))
                    {
                        player->CastSpell(player, SPELL_SUMMON_DEFIAS_BLACKGUARD1);
                        player->CastSpell(player, SPELL_SUMMON_GLUBTOK_42755);
                        player->CastSpell(player, SPELL_SUMMON_HELIX_42753);
                    }
                    m_events.ScheduleEvent(EVENT_TALK_PART_06, 1000);
                    break;
                }
                case EVENT_TALK_PART_06:
                {
                    if (Creature* glubtok = GetGlubtok())
                        glubtok->CastSpell(glubtok, SPELL_SIMPLE_TELEPORT);
                    m_events.ScheduleEvent(EVENT_TALK_PART_07, 5000);
                    break;
                }
                case EVENT_TALK_PART_07:
                {
                    Talk(4); // tie them
                    m_events.ScheduleEvent(EVENT_TALK_PART_08, 2000);
                    break;
                }
                case EVENT_TALK_PART_08:
                {
                    me->CastSpell(me, SPELL_TIE_UP_GOOD_GUYS2);
                    m_events.ScheduleEvent(EVENT_TALK_PART_09, 1000);
                    break;
                }
                case EVENT_TALK_PART_09:
                {
                    me->GetMotionMaster()->MovePoint(1202, -10512.44f, 1044.438f, 60.51799f);
                    break;
                }
                case EVENT_TALK_PART_10:
                {
                    Talk(5);
                    m_events.ScheduleEvent(EVENT_TALK_PART_11, 1000);
                    break;
                }
                case EVENT_TALK_PART_11:
                {
                    if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                        if (Creature* npc = GetRipsnarl())
                            player->CastSpell(npc, SPELL_GENERIC_TRIGGER_1_RIPSNARL, true);
                    m_events.ScheduleEvent(EVENT_TALK_PART_12, 6500);
                    break;
                }
                case EVENT_TALK_PART_12:
                {
                    me->GetMotionMaster()->MovePoint(1203, -10512.44f, 1044.438f, 60.51799f);
                    break;
                }
                case EVENT_TALK_PART_13:
                {
                    if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    {
                        me->SetFacingToObject(player);
                        Talk(6, player);
                    }
                    m_events.ScheduleEvent(EVENT_TALK_PART_14, 7000);
                    break;
                }
                case EVENT_TALK_PART_14:
                {
                    m_point = 1204;
                    me->GetMotionMaster()->MovePath(427491, false); // 4 points
                    break;
                }
                case EVENT_TALK_PART_15:
                {
                    if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                        if (Creature* horatio = me->FindNearestCreature(NPC_HORATIO_LANE_42744, 25.0f))
                        {
                            me->SetFacingToObject(horatio);
                            player->CastSpell(player, SPELL_GENERIC_TRIGGER_1_HORATIO);
                        }
                    m_events.ScheduleEvent(EVENT_TALK_PART_16, 6000);
                    break;
                }
                case EVENT_TALK_PART_16:
                {
                    Talk(7);
                    m_events.ScheduleEvent(EVENT_TALK_PART_17, 10000);
                    break;
                }
                case EVENT_TALK_PART_17:
                {
                    Talk(8);
                    m_events.ScheduleEvent(EVENT_TALK_PART_18, 5000);
                    break;
                }
                case EVENT_TALK_PART_18:
                {
                    Talk(9);
                    m_events.ScheduleEvent(EVENT_TALK_PART_19, 6000);
                    break;
                }
                case EVENT_TALK_PART_19:
                {
                    me->GetMotionMaster()->MovePoint(1205, -10518.14f, 1067.859f, 54.86662f);
                    break;
                }
                case EVENT_TALK_PART_20:
                {
                    if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    {
                        player->CastSpell(player, SPELL_GENERIC_TRIGGER_10_BLACKGUARDS, true);
                        player->CastSpell(player, SPELL_GENERIC_TRIGGER_2_GRYAN, true);
                        player->CastSpell(player, SPELL_GENERIC_TRIGGER_10_HELIX, true);
                        player->CastSpell(player, SPELL_GENERIC_TRIGGER_10_RIPSNARL, true);
                        player->CastSpell(player, SPELL_GENERIC_TRIGGER_10_GLUBTOK, true);
                        player->CastSpell(player, SPELL_GENERIC_TRIGGER_10_HOPE, true);
                    }
                    m_events.ScheduleEvent(EVENT_TALK_PART_21, 5000);
                    break;
                }
                case EVENT_TALK_PART_21:
                {
                    std::list<Creature*> npcList = me->FindNearestCreatures(NPC_DEFIAS_BLACKGUARD_42769, 50.0f);
                    for (auto npc : npcList)
                        npc->CastSpell(npc, SPELL_GENERIC_TORCH_TOSS_TRIGGER);
                    m_events.ScheduleEvent(EVENT_TALK_PART_22, 5000);
                    break;
                }
                case EVENT_TALK_PART_22:
                {
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

        Creature* GetGryan()
        {
            if (Creature* gryan = ObjectAccessor::GetCreature(*me, m_gryanGUID))
                return gryan;
            if (Creature* gryan = me->FindNearestCreature(NPC_MARSHAL_GRYAN_STOUTMANTLE_42750, 50.0f))
            {
                m_gryanGUID = gryan->GetGUID();
                return gryan;
            }
            return nullptr;
        }

        Creature* GetGlubtok()
        {
            if (Creature* glubtok = ObjectAccessor::GetCreature(*me, m_glubtokGUID))
                return glubtok;
            if (Creature* glubtok = me->FindNearestCreature(NPC_GLUBTOK_THE_FOREMAN, 50.0f))
            {
                m_glubtokGUID = glubtok->GetGUID();
                return glubtok;
            }
            return nullptr;
        }

        Creature* GetRipsnarl()
        {
            if (Creature* ripsnarl = ObjectAccessor::GetCreature(*me, m_ripsnarlGUID))
                return ripsnarl;
            if (Creature* ripsnarl = me->FindNearestCreature(NPC_RIPSNARL_42748, 50.0f))
            {
                m_ripsnarlGUID = ripsnarl->GetGUID();
                return ripsnarl;
            }
            return nullptr;
        }

    };

    CreatureAI* GetAI(Creature* creature) const override   // empty phase, waiting on next trigger
    {
        return new npc_hope_saldean_42749AI(creature);
    }
};

// 42750
class npc_marshal_gryan_stoutmantle_42750 : public CreatureScript
{
public:
    npc_marshal_gryan_stoutmantle_42750() : CreatureScript("npc_marshal_gryan_stoutmantle_42750") { }

    struct npc_marshal_gryan_stoutmantle_42750AI : public ScriptedAI
    {
        npc_marshal_gryan_stoutmantle_42750AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap m_events;
        uint64   m_playerGUID;

        void Reset() override
        {
            m_playerGUID = 0;
            me->SetOrientation(1.204f);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Player* player = summoner->ToPlayer())
                m_playerGUID = player->GetGUID();
        }

        void SpellHit(Unit* caster, SpellInfo const* spell) override
        {
            switch (spell->Id)
            {
            case SPELL_GENERIC_TRIGGER_1_GRYAN: // tic 0
            {
                m_events.RescheduleEvent(EVENT_START_TALK, 1000);
                break;
            }
            case SPELL_GENERIC_TRIGGER_2_GRYAN: // tic 101
            {
                m_events.RescheduleEvent(EVENT_START_WALK, 1000);
                break;
            }
            case SPELL_DESPAWN_ROB_ACTORS:
            {
                me->DespawnOrUnsummon(10);
                break;
            }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                    // video start. 
                case EVENT_START_TALK:
                {
                    if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                        Talk(4, player); // tic 1
                    m_events.ScheduleEvent(EVENT_TALK_PART_00, 2000);
                    break;
                }
                case EVENT_TALK_PART_00:
                {
                    if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                        player->CastSpell(player, SPELL_GENERIC_TRIGGER_1_HOPE, false); // tic 3
                    break;
                }
                // video end part
                case EVENT_START_WALK:
                {
                    if (Player* player = sObjectAccessor->GetPlayer(*me, m_playerGUID))
                    {
                        me->CastSpell(player, SPELL_QUEST_CREDIT_DEFIAS_FINALE_EVENT, false); // tic 102
                        player->RemoveAura(SPELL_TIED_UP);
                        Talk(6, player);
                    }
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_marshal_gryan_stoutmantle_42750AI(creature);
    }
};

// 79723
class spell_tie_up_good_guys_79723 : public SpellScriptLoader
{
public:
    spell_tie_up_good_guys_79723() : SpellScriptLoader("spell_tie_up_good_guys_79723") { }

    class spell_tie_up_good_guys_79723_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_tie_up_good_guys_79723_SpellScript);

        std::list<uint32> ggList;

        bool Load() override
        {
            ggList.clear();
            ggList.push_back(42750);
            ggList.push_back(42744);
            ggList.push_back(42745);
            ggList.push_back(42751);
            ggList.push_back(42752);
            return true;
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(RemoveFromList(ggList, false, false));
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_tie_up_good_guys_79723_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_tie_up_good_guys_79723_SpellScript();
    }
};


// ToDo: is not checked:  npc_daphne_stilwell

enum DaphneStilwell
{
    SAY_DS_START = 0,
    SAY_DS_DOWN_1 = 1,
    SAY_DS_DOWN_2 = 2,
    SAY_DS_DOWN_3 = 3,
    SAY_DS_PROLOGUE = 4,

    SPELL_SHOOT = 6660,
    QUEST_TOME_VALOR = 1651,
    NPC_DEFIAS_RAIDER = 6180,
    EQUIP_ID_RIFLE = 2511
};

class npc_daphne_stilwell : public CreatureScript
{
public:
    npc_daphne_stilwell() : CreatureScript("npc_daphne_stilwell") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest) override
    {
        if (quest->GetQuestId() == QUEST_TOME_VALOR)
        {
            creature->AI()->Talk(SAY_DS_START);

            if (npc_escortAI* pEscortAI = CAST_AI(npc_daphne_stilwell::npc_daphne_stilwellAI, creature->AI()))
                pEscortAI->Start(true, true, player->GetGUID());
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_daphne_stilwellAI(creature);
    }

    struct npc_daphne_stilwellAI : public npc_escortAI
    {
        npc_daphne_stilwellAI(Creature* creature) : npc_escortAI(creature) { }

        uint32 uiWPHolder;
        uint32 uiShootTimer;

        void Reset() override
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
            {
                switch (uiWPHolder)
                {
                case 7:
                    Talk(SAY_DS_DOWN_1);
                    break;
                case 8:
                    Talk(SAY_DS_DOWN_2);
                    break;
                case 9:
                    Talk(SAY_DS_DOWN_3);
                    break;
                }
            }
            else
                uiWPHolder = 0;

            uiShootTimer = 0;
        }

        void WaypointReached(uint32 waypointId) override
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            uiWPHolder = waypointId;

            switch (waypointId)
            {
            case 4:
                SetEquipmentSlots(false, EQUIP_NO_CHANGE, EQUIP_NO_CHANGE, EQUIP_ID_RIFLE);
                me->SetSheath(SHEATH_STATE_RANGED);
                me->HandleEmoteCommand(EMOTE_STATE_USE_STANDING_NO_SHEATHE);
                break;
            case 7:
                me->SummonCreature(NPC_DEFIAS_RAIDER, -11450.836f, 1569.755f, 54.267f, 4.230f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(NPC_DEFIAS_RAIDER, -11449.697f, 1569.124f, 54.421f, 4.206f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(NPC_DEFIAS_RAIDER, -11448.237f, 1568.307f, 54.620f, 4.206f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                break;
            case 8:
                me->SetSheath(SHEATH_STATE_RANGED);
                me->SummonCreature(NPC_DEFIAS_RAIDER, -11450.836f, 1569.755f, 54.267f, 4.230f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(NPC_DEFIAS_RAIDER, -11449.697f, 1569.124f, 54.421f, 4.206f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(NPC_DEFIAS_RAIDER, -11448.237f, 1568.307f, 54.620f, 4.206f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(NPC_DEFIAS_RAIDER, -11448.037f, 1570.213f, 54.961f, 4.283f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                break;
            case 9:
                me->SetSheath(SHEATH_STATE_RANGED);
                me->SummonCreature(NPC_DEFIAS_RAIDER, -11450.836f, 1569.755f, 54.267f, 4.230f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(NPC_DEFIAS_RAIDER, -11449.697f, 1569.124f, 54.421f, 4.206f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(NPC_DEFIAS_RAIDER, -11448.237f, 1568.307f, 54.620f, 4.206f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(NPC_DEFIAS_RAIDER, -11448.037f, 1570.213f, 54.961f, 4.283f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                me->SummonCreature(NPC_DEFIAS_RAIDER, -11449.018f, 1570.738f, 54.828f, 4.220f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                break;
            case 10:
                SetRun(false);
                break;
            case 11:
                Talk(SAY_DS_PROLOGUE);
                break;
            case 13:
                SetEquipmentSlots(true);
                me->SetSheath(SHEATH_STATE_UNARMED);
                me->HandleEmoteCommand(EMOTE_STATE_USE_STANDING_NO_SHEATHE);
                break;
            case 17:
                player->GroupEventHappens(QUEST_TOME_VALOR, me);
                break;
            }
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);

                me->GetMotionMaster()->MoveChase(who, 30.0f);
            }
        }

        void JustSummoned(Creature* summoned) override
        {
            summoned->AI()->AttackStart(me);
        }

        void Update(const uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);

            if (!UpdateVictim())
                return;

            if (uiShootTimer <= diff)
            {
                uiShootTimer = 1500;

                if (!me->IsWithinDist(me->GetVictim(), ATTACK_DISTANCE))
                    DoCastVictim(SPELL_SHOOT);
            }
            else uiShootTimer -= diff;
        }
    };
};


void AddSC_westfall()
{
    new npc_daphne_stilwell();
    new npc_horatio_lane_42308();
    new npc_west_plains_drifters();
    new npc_transient();
    new npc_homeless_stormwind_citizen_42384();
    new npc_homeless_stormwind_citizen_42386();
    new npc_ragamuffin_42413();
    new npc_lues_old_house();
    new npc_shadowy_figure();
    new npc_thug();
    new npc_horatio_lane_42558();
    new npc_overloaded_harvest_golem_42381();
    new spell_unbound_energy_79084();
    new npc_salma_saldean_235();
    new npc_sentinel_hill_guard();
    new npc_riverpaw_sentinel_hill();
    new npc_defias_sentinel_hill();
    new npc_riverpaw_westfall();
    new npc_ripsnarl_sentinel_hill_42635();
    new npc_agent_kearnen();
    new item_potion_of_shrouding();
    new npc_helix_gearbreaker();
    new npc_van_cleef_dummy();
    new npc_moonbrook_player_trigger_43515();
    new npc_vision_of_the_past();
    new npc_marshal_gryan_stoutmantle_234();
    new npc_lieutenant_horatio_laine_42744();
    new npc_stormwind_investigator_42745();
    new npc_ripsnarl_42748();
    new npc_hope_saldean_42749();
    new npc_marshal_gryan_stoutmantle_42750();
    new npc_captain_danuvin_42751();
    new npc_scout_galiaan_42752();
    new npc_helix_gearbreaker_42753();
    new npc_glubtok_42755();
    new npc_defias_blackguard_42769();
    new npc_rise_of_the_brotherhood_event_dummy_42771();
    new spell_tie_up_good_guys_79723();
    new npc_thor_523;
}
