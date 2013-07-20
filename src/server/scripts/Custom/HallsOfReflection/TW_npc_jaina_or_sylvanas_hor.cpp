/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "TW_halls_of_reflection.h"

enum SylvanasYells{
	SAY_SYLVANAS_INTRO_1,
	SAY_SYLVANAS_INTRO_2,
	SAY_SYLVANAS_INTRO_3,
	SAY_SYLVANAS_INTRO_4,
	SAY_SYLVANAS_INTRO_5,
	SAY_SYLVANAS_INTRO_6,
	SAY_SYLVANAS_INTRO_7,
	SAY_SYLVANAS_INTRO_8,
	SAY_SYLVANAS_INTRO_END,
};

enum JainaYells{
	SAY_JAINA_INTRO_1,
	SAY_JAINA_INTRO_2,
	SAY_JAINA_INTRO_3,
	SAY_JAINA_INTRO_4,
	SAY_JAINA_INTRO_5,
	SAY_JAINA_INTRO_6,
	SAY_JAINA_INTRO_7,
	SAY_JAINA_INTRO_8,
	SAY_JAINA_INTRO_9,
	SAY_JAINA_INTRO_10,
	SAY_JAINA_INTRO_11,
	SAY_JAINA_INTRO_END,
};

enum UtherYellsH{
	SAY_UTHER_INTRO_H2_1,
	SAY_UTHER_INTRO_H2_2,
	SAY_UTHER_INTRO_H2_3,
	SAY_UTHER_INTRO_H2_4,
	SAY_UTHER_INTRO_H2_5,
	SAY_UTHER_INTRO_H2_6,
	SAY_UTHER_INTRO_H2_7,
};

enum UtherYellsA{
	SAY_UTHER_INTRO_A2_1,
	SAY_UTHER_INTRO_A2_2,
	SAY_UTHER_INTRO_A2_3,
	SAY_UTHER_INTRO_A2_4,
	SAY_UTHER_INTRO_A2_5,
	SAY_UTHER_INTRO_A2_6,
	SAY_UTHER_INTRO_A2_7,
	SAY_UTHER_INTRO_A2_8,
	SAY_UTHER_INTRO_A2_9,
};

enum LichKingYells{
	SAY_LK_INTRO_1,
	SAY_LK_INTRO_2,
	SAY_LK_INTRO_3,
};

enum FalricYells{
	SAY_FALRIC_INTRO_1 = 5,
	SAY_FALRIC_INTRO_2 = 6,
};

enum MarwynYells{
	SAY_MARWYN_INTRO_1 = 4,
};

/*enum Yells
{
    SAY_JAINA_INTRO_1                             = -1668001,
    SAY_JAINA_INTRO_2                             = -1668002,
    SAY_JAINA_INTRO_3                             = -1668003,
    SAY_JAINA_INTRO_4                             = -1668004,
    SAY_UTHER_INTRO_A2_1                          = -1668005,
    SAY_JAINA_INTRO_5                             = -1668006,
    SAY_UTHER_INTRO_A2_2                          = -1668007,
    SAY_JAINA_INTRO_6                             = -1668008,
    SAY_UTHER_INTRO_A2_3                          = -1668009,
    SAY_JAINA_INTRO_7                             = -1668010,
    SAY_UTHER_INTRO_A2_4                          = -1668011,
    SAY_JAINA_INTRO_8                             = -1668012,
    SAY_UTHER_INTRO_A2_5                          = -1668013,
    SAY_JAINA_INTRO_9                             = -1668014,
    SAY_UTHER_INTRO_A2_6                          = -1668015,
    SAY_UTHER_INTRO_A2_7                          = -1668016,
    SAY_JAINA_INTRO_10                            = -1668017,
    SAY_UTHER_INTRO_A2_8                          = -1668018,
    SAY_JAINA_INTRO_11                            = -1668019,
    SAY_UTHER_INTRO_A2_9                          = -1668020,

    SAY_SYLVANAS_INTRO_1                          = -1668021,
    SAY_SYLVANAS_INTRO_2                          = -1668022,
    SAY_SYLVANAS_INTRO_3                          = -1668023,
    SAY_UTHER_INTRO_H2_1                          = -1668024,
    SAY_SYLVANAS_INTRO_4                          = -1668025,
    SAY_UTHER_INTRO_H2_2                          = -1668026,
    SAY_SYLVANAS_INTRO_5                          = -1668027,
    SAY_UTHER_INTRO_H2_3                          = -1668028,
    SAY_SYLVANAS_INTRO_6                          = -1668029,
    SAY_UTHER_INTRO_H2_4                          = -1668030,
    SAY_SYLVANAS_INTRO_7                          = -1668031,
    SAY_UTHER_INTRO_H2_5                          = -1668032,
    SAY_UTHER_INTRO_H2_6                          = -1668033,
    SAY_SYLVANAS_INTRO_8                          = -1668034,
    SAY_UTHER_INTRO_H2_7                          = -1668035,

    SAY_LK_INTRO_1                                = -1668036,
    SAY_LK_INTRO_2                                = -1668037,
    SAY_LK_INTRO_3                                = -1668038,
    SAY_FALRIC_INTRO_1                            = -1668039,
    SAY_MARWYN_INTRO_1                            = -1668040,
    SAY_FALRIC_INTRO_2                            = -1668041,

    SAY_JAINA_INTRO_END                           = -1668042,
    SAY_SYLVANAS_INTRO_END                        = -1668043,
};*/

enum Events
{
    EVENT_NONE,

    EVENT_START_INTRO,
    EVENT_SKIP_INTRO,

    EVENT_INTRO_A2_1,
    EVENT_INTRO_A2_2,
    EVENT_INTRO_A2_3,
    EVENT_INTRO_A2_4,
    EVENT_INTRO_A2_5,
    EVENT_INTRO_A2_6,
    EVENT_INTRO_A2_7,
    EVENT_INTRO_A2_8,
    EVENT_INTRO_A2_9,
    EVENT_INTRO_A2_10,
    EVENT_INTRO_A2_11,
    EVENT_INTRO_A2_12,
    EVENT_INTRO_A2_13,
    EVENT_INTRO_A2_14,
    EVENT_INTRO_A2_15,
    EVENT_INTRO_A2_16,
    EVENT_INTRO_A2_17,
    EVENT_INTRO_A2_18,
    EVENT_INTRO_A2_19,

    EVENT_INTRO_H2_1,
    EVENT_INTRO_H2_2,
    EVENT_INTRO_H2_3,
    EVENT_INTRO_H2_4,
    EVENT_INTRO_H2_5,
    EVENT_INTRO_H2_6,
    EVENT_INTRO_H2_7,
    EVENT_INTRO_H2_8,
    EVENT_INTRO_H2_9,
    EVENT_INTRO_H2_10,
    EVENT_INTRO_H2_11,
    EVENT_INTRO_H2_12,
    EVENT_INTRO_H2_13,
    EVENT_INTRO_H2_14,
    EVENT_INTRO_H2_15,

    EVENT_INTRO_LK_1,
    EVENT_INTRO_LK_2,
    EVENT_INTRO_LK_3,
    EVENT_INTRO_LK_4,
    EVENT_INTRO_LK_5,
    EVENT_INTRO_LK_6,
    EVENT_INTRO_LK_7,
    EVENT_INTRO_LK_8,
    EVENT_INTRO_LK_9,

    EVENT_INTRO_END,
};

enum eEnum
{
    ACTION_START_INTRO,
    ACTION_SKIP_INTRO,

    QUEST_DELIVRANCE_FROM_THE_PIT_A2              = 24710,
    QUEST_DELIVRANCE_FROM_THE_PIT_H2              = 24712,
    QUEST_WRATH_OF_THE_LICH_KING_A2               = 24500,
    QUEST_WRATH_OF_THE_LICH_KING_H2               = 24802,
};

const Position HallsofReflectionLocs[]=
{
    {5283.234863f, 1990.946777f, 707.695679f, 0.929097f},   // 2 Loralen Follows
    {5408.031250f, 2102.918213f, 707.695251f, 0.792756f},   // 9 Sylvanas Follows
    {5401.866699f, 2110.837402f, 707.695251f, 0.800610f},   // 10 Loralen follows
};

const Position SpawnPos              = {5262.540527f, 1949.693726f, 707.695007f, 0.808736f}; // Jaina/Sylvanas Beginning Position
const Position MoveThronePos         = {5306.952148f, 1998.499023f, 709.341431f, 1.277278f}; // Jaina/Sylvanas walks to throne
const Position UtherSpawnPos         = {5308.310059f, 2003.857178f, 709.341431f, 4.650315f};
const Position LichKingSpawnPos      = {5362.917480f, 2062.307129f, 707.695374f, 3.945812f};
const Position LichKingMoveThronePos = {5312.080566f, 2009.172119f, 709.341431f, 3.973301f}; // Lich King walks to throne
const Position LichKingMoveAwayPos   = {5400.069824f, 2102.7131689f, 707.69525f, 0.843803f}; // Lich King walks away

class TW_npc_jaina_or_sylvanas_hor : public CreatureScript
{
private:
    bool m_isSylvana;

public:
    TW_npc_jaina_or_sylvanas_hor(bool isSylvana, const char* name) : CreatureScript(name), m_isSylvana(isSylvana) { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();
                if (creature->AI())
                    creature->AI()->DoAction(ACTION_START_INTRO);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->CLOSE_GOSSIP_MENU();
                if (creature->AI())
                    creature->AI()->DoAction(ACTION_SKIP_INTRO);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                break;
        }

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        QuestStatus status = player->GetQuestStatus(m_isSylvana ? QUEST_DELIVRANCE_FROM_THE_PIT_H2 : QUEST_DELIVRANCE_FROM_THE_PIT_A2);
        if (status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_REWARDED)
            player->ADD_GOSSIP_ITEM( 0, "Can you remove the sword?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        // once last quest is completed, she offers this shortcut of the starting event
        status = player->GetQuestStatus(m_isSylvana ? QUEST_WRATH_OF_THE_LICH_KING_H2 : QUEST_WRATH_OF_THE_LICH_KING_A2);
        if (status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_REWARDED)
            player->ADD_GOSSIP_ITEM( 0, "Dark Lady, I think I hear Arthas coming. Whatever you're going to do, do it quickly.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_jaina_or_sylvanas_horAI(creature);
    }

    // AI of Part1: handle the intro till start of gauntlet event.
    struct TW_npc_jaina_or_sylvanas_horAI : public ScriptedAI
    {
        TW_npc_jaina_or_sylvanas_horAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        uint64 uiUther;
        uint64 uiLichKing;

        EventMap events;

        void Reset()
        {
            events.Reset();

            uiUther = 0;
            uiLichKing = 0;

            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            me->SetVisible(true);
        }

        void DoAction(int32 actionId)
        {
            switch (actionId)
            {
                case ACTION_START_INTRO:
                    events.ScheduleEvent(EVENT_START_INTRO, 0);
                    break;
                case ACTION_SKIP_INTRO:
                    events.ScheduleEvent(EVENT_SKIP_INTRO, 0);
                    break;
            }
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);
            switch (events.ExecuteEvent())
            {
                case EVENT_START_INTRO:
                    me->GetMotionMaster()->MovePoint(0, MoveThronePos);
                    // Begining of intro is differents between fActions as the speech sequence and timers are differents.
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        events.ScheduleEvent(EVENT_INTRO_A2_1, 0);
                    else
                        events.ScheduleEvent(EVENT_INTRO_H2_1, 0);
                    break;

            // A2 Intro Events
                case EVENT_INTRO_A2_1:
					//DebugPlayerSay("Intro shitA");
                    Talk(SAY_JAINA_INTRO_3);
                    events.ScheduleEvent(EVENT_INTRO_A2_2, 5000);
                    break;
                case EVENT_INTRO_A2_2:
                    Talk(SAY_JAINA_INTRO_4);
                    events.ScheduleEvent(EVENT_INTRO_A2_3, 10000);
                    break;
                case EVENT_INTRO_A2_3:
                    // TODO: she's doing some kind of spell casting emote
                    instance->HandleGameObject(instance->GetData64(DATA_FROSTMOURNE), true);
                    events.ScheduleEvent(EVENT_INTRO_A2_4, 10000);
                    break;
                case EVENT_INTRO_A2_4:
                    // spawn UTHER during speach 2
                    if (Creature* pUther = me->SummonCreature(NPC_UTHER, UtherSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        pUther->GetMotionMaster()->MoveIdle();
                        pUther->SetReactState(REACT_PASSIVE); // be sure he will not aggro arthas
                        uiUther = pUther->GetGUID();
                    }
                    events.ScheduleEvent(EVENT_INTRO_A2_5, 2000);
                    break;
                case EVENT_INTRO_A2_5:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        Talk(SAY_UTHER_INTRO_A2_1, uiUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_6, 3000);
                    break;
                case EVENT_INTRO_A2_6:
                    Talk(SAY_JAINA_INTRO_5);
                    events.ScheduleEvent(EVENT_INTRO_A2_7, 6000);
                    break;
                case EVENT_INTRO_A2_7:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        Talk(SAY_UTHER_INTRO_A2_2, uiUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_8, 6500);
                    break;
                case EVENT_INTRO_A2_8:
                    Talk(SAY_JAINA_INTRO_6);
                    events.ScheduleEvent(EVENT_INTRO_A2_9, 2000);
                    break;
                case EVENT_INTRO_A2_9:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        Talk(SAY_UTHER_INTRO_A2_3, uiUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_10, 9000);
                    break;
                case EVENT_INTRO_A2_10:
                    Talk(SAY_JAINA_INTRO_7);
                    events.ScheduleEvent(EVENT_INTRO_A2_11, 5000);
                    break;
                case EVENT_INTRO_A2_11:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        Talk(SAY_UTHER_INTRO_A2_4, uiUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_12, 11000);
                    break;
                case EVENT_INTRO_A2_12:
                    Talk(SAY_JAINA_INTRO_8);
                    events.ScheduleEvent(EVENT_INTRO_A2_13, 4000);
                    break;
                case EVENT_INTRO_A2_13:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        Talk(SAY_UTHER_INTRO_A2_5, uiUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_14, 12500);
                    break;
                case EVENT_INTRO_A2_14:
                    Talk(SAY_JAINA_INTRO_9);
                    events.ScheduleEvent(EVENT_INTRO_A2_15, 10000);
                    break;
                case EVENT_INTRO_A2_15:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        Talk(SAY_UTHER_INTRO_A2_6, uiUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_16, 22000);
                    break;
                case EVENT_INTRO_A2_16:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        Talk(SAY_UTHER_INTRO_A2_7, uiUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_17, 4000);
                    break;
                case EVENT_INTRO_A2_17:
                    Talk(SAY_JAINA_INTRO_10);
                    events.ScheduleEvent(EVENT_INTRO_A2_18, 2000);
                    break;
                case EVENT_INTRO_A2_18:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                    {
                        pUther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                        Talk(SAY_UTHER_INTRO_A2_8, uiUther);
                    }
                    events.ScheduleEvent(EVENT_INTRO_A2_19, 11000);
                    break;
                case EVENT_INTRO_A2_19:
                    Talk(SAY_JAINA_INTRO_11);
                    events.ScheduleEvent(EVENT_INTRO_LK_1, 2000);
                    break;

            // H2 Intro Events
                case EVENT_INTRO_H2_1:
					//DebugPlayerSay("Intro shit");
                    Talk(SAY_SYLVANAS_INTRO_1);
                    events.ScheduleEvent(EVENT_INTRO_H2_2, 8000);
                    break;
                case EVENT_INTRO_H2_2:
                    Talk(SAY_SYLVANAS_INTRO_2);
                    events.ScheduleEvent(EVENT_INTRO_H2_3, 6000);
                    break;
                case EVENT_INTRO_H2_3:
                    Talk(SAY_SYLVANAS_INTRO_3);
                    // TODO: she's doing some kind of spell casting emote
                    events.ScheduleEvent(EVENT_INTRO_H2_4, 6000);
                    break;
                case EVENT_INTRO_H2_4:
                    // spawn UTHER during speach 2
                    if (Creature* pUther = me->SummonCreature(NPC_UTHER, UtherSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        pUther->GetMotionMaster()->MoveIdle();
                        pUther->SetReactState(REACT_PASSIVE); // be sure he will not aggro arthas
                        uiUther = pUther->GetGUID();
                    }
                    events.ScheduleEvent(EVENT_INTRO_H2_5, 2000);
                    break;
                case EVENT_INTRO_H2_5:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        Talk(SAY_UTHER_INTRO_H2_1, uiUther);
                    events.ScheduleEvent(EVENT_INTRO_H2_6, 11000);
                    break;
                case EVENT_INTRO_H2_6:
                    Talk(SAY_SYLVANAS_INTRO_4);
                    events.ScheduleEvent(EVENT_INTRO_H2_7, 3000);
                    break;
                case EVENT_INTRO_H2_7:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        Talk(SAY_UTHER_INTRO_H2_2, uiUther);
                    events.ScheduleEvent(EVENT_INTRO_H2_8, 6000);
                    break;
                case EVENT_INTRO_H2_8:
                    Talk(SAY_SYLVANAS_INTRO_5);
                    events.ScheduleEvent(EVENT_INTRO_H2_9, 5000);
                    break;
                case EVENT_INTRO_H2_9:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        Talk(SAY_UTHER_INTRO_H2_3, uiUther);
                    events.ScheduleEvent(EVENT_INTRO_H2_10, 19000);
                    break;
                case EVENT_INTRO_H2_10:
                    Talk(SAY_SYLVANAS_INTRO_6);
                    events.ScheduleEvent(EVENT_INTRO_H2_11, 1500);
                    break;
                case EVENT_INTRO_H2_11:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        Talk(SAY_UTHER_INTRO_H2_4, uiUther);
                    events.ScheduleEvent(EVENT_INTRO_H2_12, 19500);
                    break;
                case EVENT_INTRO_H2_12:
                    Talk(SAY_SYLVANAS_INTRO_7);
                    events.ScheduleEvent(EVENT_INTRO_H2_13, 2000);
                    break;
                case EVENT_INTRO_H2_13:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                    {
                        pUther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                        Talk(SAY_UTHER_INTRO_H2_5, uiUther);
                    }
                    events.ScheduleEvent(EVENT_INTRO_H2_14, 12000);
                    break;
                case EVENT_INTRO_H2_14:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        Talk(SAY_UTHER_INTRO_H2_6, uiUther);
                    events.ScheduleEvent(EVENT_INTRO_H2_15, 8000);
                    break;
                case EVENT_INTRO_H2_15:
                    Talk(SAY_SYLVANAS_INTRO_8);
                    events.ScheduleEvent(EVENT_INTRO_LK_1, 2000);
                    break;

            // Remaining Intro Events common for both faction
                case EVENT_INTRO_LK_1:
					//DebugPlayerSay("LK spawned");
                    // Spawn LK in front of door, and make him move to the sword.
                    if (Creature* pLichKing = me->SummonCreature(NPC_LICH_KING_EVENT, LichKingSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        pLichKing->GetMotionMaster()->MovePoint(0, LichKingMoveThronePos);
                        pLichKing->SetReactState(REACT_PASSIVE);
                        uiLichKing = pLichKing->GetGUID();
                    }

                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                    {
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            Talk(SAY_UTHER_INTRO_A2_9, uiUther);
                        else
                            Talk(SAY_UTHER_INTRO_H2_7, uiUther);
                    }

                    events.ScheduleEvent(EVENT_INTRO_LK_2, 11000);
                    break;

                case EVENT_INTRO_LK_2:
                     if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                         Talk(SAY_LK_INTRO_1, uiLichKing);
                     events.ScheduleEvent(EVENT_INTRO_LK_3, 2000);
                     break;

                case EVENT_INTRO_LK_3:
                     // The Lich King banishes Uther to the abyss.
                     if (Creature* pUther = me->GetCreature(*me, uiUther))
                     {
                         pUther->DisappearAndDie();
                         uiUther = 0;
                     }

                     // He steps forward and removes the runeblade from the heap of skulls.

                     events.ScheduleEvent(EVENT_INTRO_LK_4, 4000);
                     break;

                case EVENT_INTRO_LK_4:
                      if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                          Talk(SAY_LK_INTRO_2, uiLichKing);
                    events.ScheduleEvent(EVENT_INTRO_LK_5, 10000);
                    break;

                case EVENT_INTRO_LK_5:
                    // summon Falric and Marwyn. then go back to the door
                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        pFalric->SetVisible(true);
                    if (Creature* pMarwyn = me->GetCreature(*me, instance->GetData64(DATA_MARWYN)))
                        pMarwyn->SetVisible(true);

                    if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                    {
                        pLichKing->GetMotionMaster()->MovePoint(0, LichKingSpawnPos);
                        Talk(SAY_LK_INTRO_3, uiLichKing);
                    }

                    events.ScheduleEvent(EVENT_INTRO_LK_6, 8000);
                    break;

                case EVENT_INTRO_LK_6:
                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        Talk(SAY_FALRIC_INTRO_1, instance->GetData64(DATA_FALRIC));

                    events.ScheduleEvent(EVENT_INTRO_LK_7, 2000);
                    break;

                case EVENT_INTRO_LK_7:
                    if (Creature* pMarwyn = me->GetCreature(*me, instance->GetData64(DATA_MARWYN)))
                        Talk(SAY_MARWYN_INTRO_1, instance->GetData64(DATA_MARWYN));

                    events.ScheduleEvent(EVENT_INTRO_LK_8, 2000);
                    break;

                case EVENT_INTRO_LK_8:
                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        Talk(SAY_FALRIC_INTRO_2, instance->GetData64(DATA_FALRIC));

                    events.ScheduleEvent(EVENT_INTRO_LK_9, 5000);
                    break;

                case EVENT_INTRO_LK_9:
					//DebugPlayerSay("Jaina/Syl now running away");
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        Talk(SAY_JAINA_INTRO_END);
                    else
                        Talk(SAY_SYLVANAS_INTRO_END);

                    me->GetMotionMaster()->MovePoint(0, LichKingSpawnPos);
                    // TODO: Loralen/Koreln shall run also
                    events.ScheduleEvent(EVENT_INTRO_END, 10000);
                    break;

                case EVENT_INTRO_END:
					//DebugPlayerSay("shit should now get summoned");
                    if (instance)
                        instance->SetData(DATA_WAVE_COUNT, SPECIAL);   // start first wave

                    // Loralen or Koreln disappearAndDie()
                    me->DisappearAndDie();
                    break;

                case EVENT_SKIP_INTRO:
                    // TODO: implement

                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        pFalric->SetVisible(true);
                    if (Creature* pMarwyn = me->GetCreature(*me, instance->GetData64(DATA_MARWYN)))
                        pMarwyn->SetVisible(true);

                    me->GetMotionMaster()->MovePoint(0, LichKingSpawnPos);
                    // TODO: Loralen/Koreln shall run also

                    events.ScheduleEvent(EVENT_INTRO_END, 15000);
                    break;
            }
        }

		/*void DebugPlayerSay( const char *text ){
			Map::PlayerList const &PlayerList = instance->instance->GetPlayers();
		
			if(PlayerList.isEmpty()){
				return;
			}
			
			Player *player = PlayerList.begin()->GetSource();
			if( player == 0 ){
				player->Say(text, LANG_UNIVERSAL);
			}
		}*/
    };

};

void AddSC_TW_npc_jaina_or_sylvanas_hor()
{
    new TW_npc_jaina_or_sylvanas_hor(true, "TW_npc_sylvanas_hor_part1");
    new TW_npc_jaina_or_sylvanas_hor(false, "TW_npc_jaina_hor_part1");
}

