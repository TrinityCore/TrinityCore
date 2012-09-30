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
#include "halls_of_reflection.h"
#include "ScriptedEscortAI.h"

enum Yells
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
    SAY_LK_JAINA_INTRO_END                        = -1594473,
    SAY_LK_SYLVANAS_INTRO_END                     = -1594474,
};

enum Events
{
    EVENT_NONE,

    EVENT_START_PREINTRO,
    EVENT_PREINTRO_1,
    EVENT_PREINTRO_2,

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
    EVENT_INTRO_LK_10,

    EVENT_INTRO_END,
};

enum Achievement
{
    ACHIEV_HOR_H                        = 4521,
    ACHIEV_HOR                          = 4518,
    ACHIEV_NOT_RETREATING               =4526
};

enum eEnum
{
    ACTION_START_INTRO,
    ACTION_SKIP_INTRO,

    QUEST_DELIVRANCE_FROM_THE_PIT_A2              = 24710,
    QUEST_DELIVRANCE_FROM_THE_PIT_H2              = 24712,
    QUEST_WRATH_OF_THE_LICH_KING_A2               = 24500,
    QUEST_WRATH_OF_THE_LICH_KING_H2               = 24802,
    MAX_ENCOUNTER_TIME                            = 6 * 60 * IN_MILLISECONDS,
    KILL_CREDIT_WOTLK                             = 38211,
};

enum Spells
{
    SPELL_CAST_VISUAL                  = 65633, //Jaina/Sylavana invocation for Uther
    SPELL_BOSS_SPAWN_AURA              = 72712, //Falric and Marwyn
    SPELL_UTHER_DESPAWN                = 70693,
    SPELL_TAKE_FROSTMOURNE             = 72729,
    SPELL_FROSTMOURNE_DESPAWN          = 72726,
    SPELL_FROSTMOURNE_VISUAL           = 73220,
    SPELL_FROSTMOURNE_SOUNDS           = 70667,
};

enum Misc
{
    SPELL_SOUL_REAPER                  = 73797,
    SPELL_RAISE_DEAD                   = 69818,
    SPELL_ICE_PRISON                   = 69708,
    SPELL_HARVEST_SOUL                 = 70070,

    //Raging ghoul
    SPELL_EMERGE_VISUAL                = 50142,
    SPELL_GHOUL_JUMP                   = 70150,

    //Witch Doctor
    SPELL_COURSE_OF_DOOM               = 70144,
    H_SPELL_COURSE_OF_DOOM             = 70183,
    SPELL_SHADOW_BOLT_VOLLEY           = 70145,
    H_SPELL_SHADOW_BOLT_VOLLEY         = 70184,
    SPELL_SHADOW_BOLT                  = 70080,
    H_SPELL_SHADOW_BOLT                = 70182,

    //Lumbering Abomination
    SPELL_ABON_STRIKE                  = 40505,
    SPELL_VOMIT_SPRAY                  = 70176,
    H_SPELL_VOMIT_SPRAY                = 70181,

    SAY_LICH_KING_WALL_01              = -1594486,
    SAY_LICH_KING_GHOUL                = -1594482,
    SAY_LICH_KING_ABON                 = -1594483,
    SAY_LICH_KING_WINTER               = -1594481,
    SAY_LICH_KING_END_DUN              = -1594504,
    SAY_LICH_KING_WIN                  = -1594485,
};

const Position HallsofReflectionLocs[]=
{
    {5283.234863f, 1990.946777f, 707.695679f, 0.929097f},   // 2 Loralen Follows
    {5408.031250f, 2102.918213f, 707.695251f, 0.792756f},   // 9 Sylvanas Follows
    {5401.866699f, 2110.837402f, 707.695251f, 0.800610f},   // 10 Loralen follows
};

const Position SpawnPos              = {5262.540527f, 1949.693726f, 707.695007f, 0.808736f}; // Jaina/Sylvanas Beginning Position
const Position MoveDoorPos           = {5268.254395f, 1955.522705f, 707.699585f, 1.277278f};
const Position MoveThronePos         = {5306.952148f, 1998.499023f, 709.341431f, 1.277278f}; // Jaina/Sylvanas walks to throne
const Position UtherSpawnPos         = {5308.310059f, 2003.857178f, 709.341431f, 4.650315f};
const Position LichKingSpawnPos      = {5362.917480f, 2062.307129f, 707.695374f, 3.945812f};
const Position LichKingMoveThronePos = {5312.080566f, 2009.172119f, 709.341431f, 3.973301f}; // Lich King walks to throne
const Position LichKingMoveAwayPos   = {5400.069824f, 2102.7131689f, 707.69525f, 0.843803f}; // Lich King walks away

class npc_jaina_or_sylvanas_hor : public CreatureScript
{
public:
    npc_jaina_or_sylvanas_hor(const char* name) : CreatureScript(name) { }

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
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        QuestStatus status = player->GetQuestStatus(player->GetTeamId() == TEAM_HORDE ? QUEST_DELIVRANCE_FROM_THE_PIT_H2 : QUEST_DELIVRANCE_FROM_THE_PIT_A2);
        if (status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_REWARDED)
            player->ADD_GOSSIP_ITEM( 0, "Can you remove the sword?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        // once last quest is completed, she offers this shortcut of the starting event, while the other remains as an option
        status = player->GetQuestStatus(player->GetTeamId() == TEAM_HORDE ? QUEST_WRATH_OF_THE_LICH_KING_H2 : QUEST_WRATH_OF_THE_LICH_KING_A2);
        if (status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_REWARDED)
            player->ADD_GOSSIP_ITEM( 0, "Dark Lady, I think I hear Arthas coming. Whatever you're going to do, do it quickly.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_jaina_or_sylvanas_horAI(creature);
    }

    // AI of Part1: handle the intro till start of gauntlet event.
    struct npc_jaina_or_sylvanas_horAI : public ScriptedAI
    {
        npc_jaina_or_sylvanas_horAI(Creature* creature) : ScriptedAI(creature)
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

        void DoAction(const int32 actionId)
        {
            switch (actionId)
            {
                case ACTION_START_INTRO:
                    events.ScheduleEvent(EVENT_START_PREINTRO, 0);
                    break;
                case ACTION_SKIP_INTRO:
                    events.ScheduleEvent(EVENT_SKIP_INTRO, 0);
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!instance)
                return;

            events.Update(diff);
            switch (events.ExecuteEvent())
            {
                case EVENT_START_PREINTRO:
                    me->SetWalk(false);
                    me->GetMotionMaster()->MovePoint(0, MoveDoorPos);

                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        events.ScheduleEvent(EVENT_PREINTRO_1, 0);
                    else
                        events.ScheduleEvent(EVENT_START_INTRO, 0);
                    break;

                case EVENT_PREINTRO_1:
                    DoScriptText(SAY_JAINA_INTRO_1, me);
                    events.ScheduleEvent(EVENT_PREINTRO_2, 6000);
                    break;

                case EVENT_PREINTRO_2:
                    DoScriptText(SAY_JAINA_INTRO_2, me);
                    events.ScheduleEvent(EVENT_START_INTRO, 7000);
                    break;

                case EVENT_START_INTRO:
                    me->SetWalk(false);
                    me->GetMotionMaster()->MovePoint(0, MoveThronePos);
                    // Begining of intro is differents between fActions as the speech sequence and timers are differents.
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        events.ScheduleEvent(EVENT_INTRO_A2_1, 0);
                    else
                        events.ScheduleEvent(EVENT_INTRO_H2_1, 0);
                    break;

            // A2 Intro Events
                case EVENT_INTRO_A2_1:
                    DoScriptText(SAY_JAINA_INTRO_3, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_2, 5000);
                    break;
                case EVENT_INTRO_A2_2:
                    DoScriptText(SAY_JAINA_INTRO_4, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_3, 10000);
                    break;
                case EVENT_INTRO_A2_3:
                    DoCast(me, SPELL_CAST_VISUAL);
                    me->CastSpell(me, SPELL_FROSTMOURNE_SOUNDS, true);
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
                        me->SetTarget(uiUther);
                        pUther->SetTarget(me->GetGUID());
                    }
                    events.ScheduleEvent(EVENT_INTRO_A2_5, 2000);
                    break;
                case EVENT_INTRO_A2_5:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        DoScriptText(SAY_UTHER_INTRO_A2_1, pUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_6, 3000);
                    break;
                case EVENT_INTRO_A2_6:
                    DoScriptText(SAY_JAINA_INTRO_5, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_7, 6000);
                    break;
                case EVENT_INTRO_A2_7:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        DoScriptText(SAY_UTHER_INTRO_A2_2, pUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_8, 6500);
                    break;
                case EVENT_INTRO_A2_8:
                    DoScriptText(SAY_JAINA_INTRO_6, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_9, 2000);
                    break;
                case EVENT_INTRO_A2_9:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        DoScriptText(SAY_UTHER_INTRO_A2_3, pUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_10, 9000);
                    break;
                case EVENT_INTRO_A2_10:
                    DoScriptText(SAY_JAINA_INTRO_7, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_11, 5000);
                    break;
                case EVENT_INTRO_A2_11:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        DoScriptText(SAY_UTHER_INTRO_A2_4, pUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_12, 11000);
                    break;
                case EVENT_INTRO_A2_12:
                    DoScriptText(SAY_JAINA_INTRO_8, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_13, 4000);
                    break;
                case EVENT_INTRO_A2_13:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        DoScriptText(SAY_UTHER_INTRO_A2_5, pUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_14, 12500);
                    break;
                case EVENT_INTRO_A2_14:
                    DoScriptText(SAY_JAINA_INTRO_9, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_15, 10000);
                    break;
                case EVENT_INTRO_A2_15:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        DoScriptText(SAY_UTHER_INTRO_A2_6, pUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_16, 22000);
                    break;
                case EVENT_INTRO_A2_16:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        DoScriptText(SAY_UTHER_INTRO_A2_7, pUther);
                    events.ScheduleEvent(EVENT_INTRO_A2_17, 4000);
                    break;
                case EVENT_INTRO_A2_17:
                    DoScriptText(SAY_JAINA_INTRO_10, me);
                    events.ScheduleEvent(EVENT_INTRO_A2_18, 2000);
                    break;
                case EVENT_INTRO_A2_18:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                    {
                        pUther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                        DoScriptText(SAY_UTHER_INTRO_A2_8, pUther);
                    }
                    events.ScheduleEvent(EVENT_INTRO_A2_19, 11000);
                    break;
                case EVENT_INTRO_A2_19:
                    DoScriptText(SAY_JAINA_INTRO_11, me);
                    events.ScheduleEvent(EVENT_INTRO_LK_1, 2000);
                    break;

            // H2 Intro Events
                case EVENT_INTRO_H2_1:
                    DoScriptText(SAY_SYLVANAS_INTRO_1, me);
                    events.ScheduleEvent(EVENT_INTRO_H2_2, 8000);
                    break;
                case EVENT_INTRO_H2_2:
                    DoScriptText(SAY_SYLVANAS_INTRO_2, me);
                    events.ScheduleEvent(EVENT_INTRO_H2_3, 6000);
                    break;
                case EVENT_INTRO_H2_3:
                    DoScriptText(SAY_SYLVANAS_INTRO_3, me);
                    DoCast(me, SPELL_CAST_VISUAL);
                    instance->HandleGameObject(instance->GetData64(DATA_FROSTMOURNE), true);
                    me->CastSpell(me, SPELL_FROSTMOURNE_SOUNDS, true);
                    events.ScheduleEvent(EVENT_INTRO_H2_4, 6000);
                    break;
                case EVENT_INTRO_H2_4:
                    // spawn UTHER during speach 2
                    if (Creature* pUther = me->SummonCreature(NPC_UTHER, UtherSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        pUther->GetMotionMaster()->MoveIdle();
                        pUther->SetReactState(REACT_PASSIVE); // be sure he will not aggro arthas
                        uiUther = pUther->GetGUID();
                        me->SetTarget(uiUther);
                        pUther->SetTarget(me->GetGUID());
                    }
                    events.ScheduleEvent(EVENT_INTRO_H2_5, 2000);
                    break;
                case EVENT_INTRO_H2_5:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        DoScriptText(SAY_UTHER_INTRO_H2_1, pUther);
                    events.ScheduleEvent(EVENT_INTRO_H2_6, 11000);
                    break;
                case EVENT_INTRO_H2_6:
                    DoScriptText(SAY_SYLVANAS_INTRO_4, me);
                    events.ScheduleEvent(EVENT_INTRO_H2_7, 3000);
                    break;
                case EVENT_INTRO_H2_7:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        DoScriptText(SAY_UTHER_INTRO_H2_2, pUther);
                    events.ScheduleEvent(EVENT_INTRO_H2_8, 6000);
                    break;
                case EVENT_INTRO_H2_8:
                    DoScriptText(SAY_SYLVANAS_INTRO_5, me);
                    events.ScheduleEvent(EVENT_INTRO_H2_9, 5000);
                    break;
                case EVENT_INTRO_H2_9:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        DoScriptText(SAY_UTHER_INTRO_H2_3, pUther);
                    events.ScheduleEvent(EVENT_INTRO_H2_10, 19000);
                    break;
                case EVENT_INTRO_H2_10:
                    DoScriptText(SAY_SYLVANAS_INTRO_6, me);
                    events.ScheduleEvent(EVENT_INTRO_H2_11, 1500);
                    break;
                case EVENT_INTRO_H2_11:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        DoScriptText(SAY_UTHER_INTRO_H2_4, pUther);
                    events.ScheduleEvent(EVENT_INTRO_H2_12, 19500);
                    break;
                case EVENT_INTRO_H2_12:
                    DoScriptText(SAY_SYLVANAS_INTRO_7, me);
                    events.ScheduleEvent(EVENT_INTRO_H2_13, 2000);
                    break;
                case EVENT_INTRO_H2_13:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                    {
                        pUther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                        DoScriptText(SAY_UTHER_INTRO_H2_5, pUther);
                    }
                    events.ScheduleEvent(EVENT_INTRO_H2_14, 12000);
                    break;
                case EVENT_INTRO_H2_14:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        DoScriptText(SAY_UTHER_INTRO_H2_6, pUther);
                    events.ScheduleEvent(EVENT_INTRO_H2_15, 8000);
                    break;
                case EVENT_INTRO_H2_15:
                    DoScriptText(SAY_SYLVANAS_INTRO_8, me);
                    events.ScheduleEvent(EVENT_INTRO_LK_1, 2000);
                    break;

            // Remaining Intro Events common for both faction
                case EVENT_INTRO_LK_1:
                    // Spawn LK in front of door, and make him move to the sword.
                    if (Creature* pLichKing = me->SummonCreature(NPC_LICH_KING_EVENT, LichKingSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        pLichKing->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                        pLichKing->GetMotionMaster()->MovePoint(0, LichKingMoveThronePos);
                        pLichKing->SetReactState(REACT_PASSIVE);
                        uiLichKing = pLichKing->GetGUID();

                        if (GameObject* gate = instance->instance->GetGameObject(instance->GetData64(DATA_FROSTWORN_DOOR)))
                            gate->SetGoState(GO_STATE_ACTIVE);

                        me->SetTarget(uiLichKing);
                        pLichKing->SetTarget(me->GetGUID());
                    }

                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                    {
                        pUther->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            DoScriptText(SAY_UTHER_INTRO_A2_9, pUther);
                        else
                            DoScriptText(SAY_UTHER_INTRO_H2_7, pUther);
                    }

                    events.ScheduleEvent(EVENT_INTRO_LK_2, 11000);
                    break;

                case EVENT_INTRO_LK_2:
                     if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                         DoScriptText(SAY_LK_INTRO_1, pLichKing);
                     if (GameObject* pGate = instance->instance->GetGameObject(instance->GetData64(DATA_FROSTWORN_DOOR)))
                         pGate->SetGoState(GO_STATE_READY);
                     events.ScheduleEvent(EVENT_INTRO_LK_3, 2000);
                     break;

                case EVENT_INTRO_LK_3:
                     // The Lich King banishes Uther to the abyss.
                     if (Creature* pUther = me->GetCreature(*me, uiUther))
                     {
                         pUther->CastSpell(pUther, SPELL_UTHER_DESPAWN, true);
                         pUther->DisappearAndDie();
                         uiUther = 0;
                     }
                     events.ScheduleEvent(EVENT_INTRO_LK_4, 5000);
                     break;

                case EVENT_INTRO_LK_4:
                      if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                          DoScriptText(SAY_LK_INTRO_2, pLichKing);
                    // He steps forward and removes the runeblade from the heap of skulls.
                    if (GameObject* pFrostmourne = me->FindNearestGameObject(GO_FROSTMOURNE, 11.0f))
                        pFrostmourne->SetPhaseMask(0, true);

                    if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                    {
                        pLichKing->CastSpell(pLichKing, SPELL_TAKE_FROSTMOURNE, true);
                        pLichKing->CastSpell(pLichKing, SPELL_FROSTMOURNE_VISUAL, true);
                    }

                    me->RemoveAllAuras();

                    events.ScheduleEvent(EVENT_INTRO_LK_5, 10000);
                    break;

                case EVENT_INTRO_LK_5:
                    // summon Falric and Marwyn. then go back to the door
                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                    {
                        pFalric->CastSpell(pFalric, SPELL_BOSS_SPAWN_AURA, true);
                        pFalric->SetVisible(true);
                        pFalric->GetMotionMaster()->MovePoint(0, 5283.309f, 2031.173f, 709.319f);
                    }
                    if (Creature* pMarwyn = me->GetCreature(*me, instance->GetData64(DATA_MARWYN)))
                    {
                        pMarwyn->CastSpell(pMarwyn, SPELL_BOSS_SPAWN_AURA, true);
                        pMarwyn->SetVisible(true);
                        pMarwyn->GetMotionMaster()->MovePoint(0, 5335.585f, 1981.439f, 709.319f);
                    }

                    if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                    {
                        pLichKing->GetMotionMaster()->MovePoint(0, LichKingSpawnPos);
                        DoScriptText(SAY_LK_INTRO_3, pLichKing);
                    }

                    events.ScheduleEvent(EVENT_INTRO_LK_6, 8000);
                    break;

                case EVENT_INTRO_LK_6:
                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        DoScriptText(SAY_FALRIC_INTRO_1, pFalric);

                    events.ScheduleEvent(EVENT_INTRO_LK_7, 2000);
                    break;

                case EVENT_INTRO_LK_7:
                    if (Creature* pMarwyn = me->GetCreature(*me, instance->GetData64(DATA_MARWYN)))
                        DoScriptText(SAY_MARWYN_INTRO_1, pMarwyn);

                    if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                    {
                        if (GameObject* Gate = instance->instance->GetGameObject(instance->GetData64(DATA_FROSTWORN_DOOR)))
                            Gate->SetGoState(GO_STATE_ACTIVE);
                        pLichKing->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                        pLichKing->GetMotionMaster()->MovePoint(0, LichKingMoveAwayPos);
                    }

                    events.ScheduleEvent(EVENT_INTRO_LK_8, 2000);
                    break;

                case EVENT_INTRO_LK_8:
                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        DoScriptText(SAY_FALRIC_INTRO_2, pFalric);

                    events.ScheduleEvent(EVENT_INTRO_LK_9, 2000);
                    break;

                case EVENT_INTRO_LK_9:
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        DoScriptText(SAY_JAINA_INTRO_END, me);
                    else
                        DoScriptText(SAY_SYLVANAS_INTRO_END, me);

                    me->GetMotionMaster()->MovePoint(0, LichKingMoveAwayPos);

                    if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                    {
                        pLichKing->SetWalk(false);
                        pLichKing->GetMotionMaster()->MovePoint(0, LichKingMoveAwayPos);
                    }

                    events.ScheduleEvent(EVENT_INTRO_LK_10, 5000);
                    break;

                case EVENT_INTRO_LK_10:
                    if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            DoScriptText(SAY_LK_JAINA_INTRO_END, pLichKing);
                        else
                            DoScriptText(SAY_LK_SYLVANAS_INTRO_END, pLichKing);

                    events.ScheduleEvent(EVENT_INTRO_END, 7000);
                    break;

                case EVENT_INTRO_END:
                    if (instance)
                    {
                        instance->SetData(DATA_INTRO_EVENT, DONE);
                        instance->SetData(DATA_WAVES_STATE, IN_PROGRESS);   // start first wave
                    }

                    if (GameObject* pGate = instance->instance->GetGameObject(instance->GetData64(DATA_FROSTWORN_DOOR)))
                        pGate->SetGoState(GO_STATE_READY);

                    // Loralen or Koreln disappearAndDie()
                    me->DisappearAndDie();
                    if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                        pLichKing->DisappearAndDie();

                    break;

                case EVENT_SKIP_INTRO:
                    // Spawn LK in front of door, and make him move to the sword.
                    if (Creature* pLichKing = me->SummonCreature(NPC_LICH_KING_EVENT, LichKingSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        pLichKing->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                        pLichKing->GetMotionMaster()->MovePoint(0, LichKingMoveThronePos);
                        pLichKing->SetReactState(REACT_PASSIVE);
                        uiLichKing = pLichKing->GetGUID();
                        me->SetTarget(uiLichKing);
                        pLichKing->SetTarget(me->GetGUID());
                    }

                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        pFalric->SetVisible(true);
                    if (Creature* pMarwyn = me->GetCreature(*me, instance->GetData64(DATA_MARWYN)))
                        pMarwyn->SetVisible(true);

                    me->GetMotionMaster()->MovePoint(0, MoveThronePos);
                    // Optionally: Loralen/Koreln shall run also

                    events.ScheduleEvent(EVENT_INTRO_LK_4, 20000);
                    break;
            }
        }
    };

};

enum TrashSpells
{
    // Ghostly Priest
    SPELL_SHADOW_WORD_PAIN                        = 72318,
    H_SPELL_SHADOW_WORD_PAIN                      = 72319,
    SPELL_CIRCLE_OF_DESTRUCTION                   = 72320,
    H_SPELL_CIRCLE_OF_DESTRUCTION                 = 72323,
    SPELL_COWER_IN_FEAR                           = 72321,
    SPELL_DARK_MENDING                            = 72322,
    H_SPELL_DARK_MENDING                          = 72324,

    // Phantom Mage
    SPELL_FIREBALL                                = 72163,
    H_SPELL_FIREBALL                              = 72164,
    SPELL_FLAMESTRIKE                             = 72169,
    H_SPELL_FLAMESTRIKE                           = 72170,
    SPELL_FROSTBOLT                               = 72166,
    H_SPELL_FROSTBOLT                             = 72167,
    SPELL_CHAINS_OF_ICE                           = 72121,
    SPELL_HALLUCINATION                           = 72342,

    // Phantom Hallucination (same as phantom mage + HALLUCINATION_2 when dies)
    SPELL_HALLUCINATION_2                         = 72344,

    // Shadowy Mercenary
    SPELL_SHADOW_STEP                             = 72326,
    H_SPELL_SHADOW_STEP                           = 72327,
    SPELL_DEADLY_POISON                           = 72329,
    H_SPELL_DEADLY_POISON                         = 72330,
    SPELL_ENVENOMED_DAGGER_THROW                  = 72333,
    H_SPELL_ENVENOMED_DAGGER_THROW                = 72334,
    SPELL_KIDNEY_SHOT                             = 72335,

    // Spectral Footman
    SPELL_SPECTRAL_STRIKE                         = 72198,
    H_SPELL_SPECTRAL_STRIKE                       = 72688,
    SPELL_SHIELD_BASH                             = 72194,
    H_SPELL_SHIELD_BASH                           = 72196,
    SPELL_TORTURED_ENRAGE                         = 72203,

    // Tortured Rifleman
    SPELL_SHOOT                                   = 72208,
    H_SPELL_SHOOT                                 = 72211,
    SPELL_CURSED_ARROW                            = 72222,
    SPELL_FROST_TRAP                              = 72215,
    SPELL_ICE_SHOT                                = 72268,
    H_SPELL_ICE_SHOT                              = 72269,

    // Quel'Delar Event
    SPELL_QUELDELAR_AURA                          = 70013,
};

enum TrashEvents
{
    EVENT_TRASH_NONE,

    // Ghostly Priest
    EVENT_SHADOW_WORD_PAIN,
    EVENT_CIRCLE_OF_DESTRUCTION,
    EVENT_COWER_IN_FEAR,
    EVENT_DARK_MENDING,

    // Phantom Mage
    EVENT_FIREBALL,
    EVENT_FLAMESTRIKE,
    EVENT_FROSTBOLT,
    EVENT_CHAINS_OF_ICE,
    EVENT_HALLUCINATION,

    // Shadowy Mercenary
    EVENT_SHADOW_STEP,
    EVENT_DEADLY_POISON,
    EVENT_ENVENOMED_DAGGER_THROW,
    EVENT_KIDNEY_SHOT,

    // Spectral Footman
    EVENT_SPECTRAL_STRIKE,
    EVENT_SHIELD_BASH,
    EVENT_TORTURED_ENRAGE,

    // Tortured Rifleman
    EVENT_SHOOT,
    EVENT_CURSED_ARROW,
    EVENT_FROST_TRAP,
    EVENT_ICE_SHOT,
};

class npc_ghostly_priest : public CreatureScript
{
public:
    npc_ghostly_priest() : CreatureScript("npc_ghostly_priest") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ghostly_priestAI(creature);
    }

    struct npc_ghostly_priestAI: public ScriptedAI
    {
        npc_ghostly_priestAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000); // TODO: adjust timers
            events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000);
            events.ScheduleEvent(EVENT_COWER_IN_FEAR, 10000);
            events.ScheduleEvent(EVENT_DARK_MENDING, DUNGEON_MODE(20000, 5000));
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOW_WORD_PAIN:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, DUNGEON_MODE(SPELL_SHADOW_WORD_PAIN, H_SPELL_SHADOW_WORD_PAIN));
                        events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000);
                        return;
                    case EVENT_CIRCLE_OF_DESTRUCTION:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, DUNGEON_MODE(SPELL_CIRCLE_OF_DESTRUCTION, H_SPELL_CIRCLE_OF_DESTRUCTION));
                        events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000);
                        return;
                    case EVENT_COWER_IN_FEAR:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_COWER_IN_FEAR);
                        events.ScheduleEvent(EVENT_COWER_IN_FEAR, 10000);
                        return;
                    case EVENT_DARK_MENDING:
                        // find an ally with missing HP
                        if (Unit* target = DoSelectLowestHpFriendly(40, DUNGEON_MODE(30000, 50000)))
                        {
                            DoCast(target, DUNGEON_MODE(SPELL_DARK_MENDING, H_SPELL_DARK_MENDING));
                            events.ScheduleEvent(EVENT_DARK_MENDING, DUNGEON_MODE(20000, 5000));
                        }
                        else
                        {
                            // no friendly unit with missing hp. re-check in just 5 sec.
                            events.ScheduleEvent(EVENT_DARK_MENDING, 1000);
                        }
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_phantom_mage : public CreatureScript
{
public:
    npc_phantom_mage() : CreatureScript("npc_phantom_mage") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_phantom_mageAI(creature);
    }

    struct npc_phantom_mageAI: public ScriptedAI
    {
        npc_phantom_mageAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_FIREBALL, 3000); // TODO: adjust timers
            events.ScheduleEvent(EVENT_FLAMESTRIKE, 6000);
            events.ScheduleEvent(EVENT_FROSTBOLT, 9000);
            events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 12000);
            events.ScheduleEvent(EVENT_HALLUCINATION, 40000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FIREBALL:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, DUNGEON_MODE(SPELL_FIREBALL, H_SPELL_FIREBALL));
                        events.ScheduleEvent(EVENT_FIREBALL, 15000);
                        return;
                    case EVENT_FLAMESTRIKE:
                        DoCast(DUNGEON_MODE(SPELL_FLAMESTRIKE, H_SPELL_FLAMESTRIKE));
                        events.ScheduleEvent(EVENT_FLAMESTRIKE, 15000);
                        return;
                    case EVENT_FROSTBOLT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, DUNGEON_MODE(SPELL_FROSTBOLT, H_SPELL_FROSTBOLT));
                        events.ScheduleEvent(EVENT_FROSTBOLT, 15000);
                        return;
                    case EVENT_CHAINS_OF_ICE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_CHAINS_OF_ICE);
                        events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 15000);
                        return;
                    case EVENT_HALLUCINATION:
                        DoCast(SPELL_HALLUCINATION);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_phantom_hallucination : public CreatureScript
{
public:
    npc_phantom_hallucination() : CreatureScript("npc_phantom_hallucination") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_phantom_hallucinationAI(creature);
    }

    struct npc_phantom_hallucinationAI : public npc_phantom_mage::npc_phantom_mageAI
    {
        npc_phantom_hallucinationAI(Creature* creature) : npc_phantom_mage::npc_phantom_mageAI(creature)
        {
        }

        void JustDied(Unit* /*killer*/)
        {
            DoCast(SPELL_HALLUCINATION_2);
        }
    };

};

class npc_shadowy_mercenary : public CreatureScript
{
public:
    npc_shadowy_mercenary() : CreatureScript("npc_shadowy_mercenary") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_shadowy_mercenaryAI(creature);
    }

    struct npc_shadowy_mercenaryAI: public ScriptedAI
    {
        npc_shadowy_mercenaryAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHADOW_STEP, 8000); // TODO: adjust timers
            events.ScheduleEvent(EVENT_DEADLY_POISON, 5000);
            events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
            events.ScheduleEvent(EVENT_KIDNEY_SHOT, 12000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOW_STEP:
                        DoCast(DUNGEON_MODE(SPELL_SHADOW_STEP, H_SPELL_SHADOW_STEP));
                        events.ScheduleEvent(EVENT_SHADOW_STEP, 8000);
                        return;
                    case EVENT_DEADLY_POISON:
                        DoCast(me->getVictim(), DUNGEON_MODE(SPELL_DEADLY_POISON, H_SPELL_DEADLY_POISON));
                        events.ScheduleEvent(EVENT_DEADLY_POISON, 10000);
                        return;
                    case EVENT_ENVENOMED_DAGGER_THROW:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, DUNGEON_MODE(SPELL_ENVENOMED_DAGGER_THROW, H_SPELL_ENVENOMED_DAGGER_THROW));
                        events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
                        return;
                    case EVENT_KIDNEY_SHOT:
                        DoCast(me->getVictim(), SPELL_KIDNEY_SHOT);
                        events.ScheduleEvent(EVENT_KIDNEY_SHOT, 10000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_spectral_footman : public CreatureScript
{
public:
    npc_spectral_footman() : CreatureScript("npc_spectral_footman") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_spectral_footmanAI(creature);
    }

    struct npc_spectral_footmanAI: public ScriptedAI
    {
        npc_spectral_footmanAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000); // TODO: adjust timers
            events.ScheduleEvent(EVENT_SHIELD_BASH, 10000);
            events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPECTRAL_STRIKE:
                        DoCast(me->getVictim(), DUNGEON_MODE(SPELL_SPECTRAL_STRIKE, H_SPELL_SPECTRAL_STRIKE));
                        events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000);
                        return;
                    case EVENT_SHIELD_BASH:
                        DoCast(me->getVictim(), DUNGEON_MODE(SPELL_SHIELD_BASH, H_SPELL_SHIELD_BASH));
                        events.ScheduleEvent(EVENT_SHIELD_BASH, 5000);
                        return;
                    case EVENT_TORTURED_ENRAGE:
                        DoCast(SPELL_TORTURED_ENRAGE);
                        events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_tortured_rifleman : public CreatureScript
{
public:
    npc_tortured_rifleman() : CreatureScript("npc_tortured_rifleman") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_tortured_riflemanAI(creature);
    }

    struct npc_tortured_riflemanAI  : public ScriptedAI
    {
        npc_tortured_riflemanAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHOOT, 2000); // TODO: adjust timers
            events.ScheduleEvent(EVENT_CURSED_ARROW, 10000);
            events.ScheduleEvent(EVENT_FROST_TRAP, 1000);
            events.ScheduleEvent(EVENT_ICE_SHOT, 15000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHOOT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, DUNGEON_MODE(SPELL_SHOOT, H_SPELL_SHOOT));
                        events.ScheduleEvent(EVENT_SHOOT, 2000);
                        return;
                    case EVENT_CURSED_ARROW:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_CURSED_ARROW);
                        events.ScheduleEvent(EVENT_CURSED_ARROW, 10000);
                        return;
                    case EVENT_FROST_TRAP:
                        DoCast(SPELL_FROST_TRAP);
                        events.ScheduleEvent(EVENT_FROST_TRAP, 30000);
                        return;
                    case EVENT_ICE_SHOT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, DUNGEON_MODE(SPELL_ICE_SHOT, H_SPELL_ICE_SHOT));
                        events.ScheduleEvent(EVENT_ICE_SHOT, 15000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

enum GENERAL_EVENT
{
    SAY_AGGRO                    = -1594519,
    SAY_DEATH                    = -1594520,

    SPELL_SHIELD_THROWN          = 69222,
    H_SPELL_SHIELD_THROWN        = 73076,
    SPELL_SPIKE                  = 69184,
    H_SPELL_SPIKE                = 70399,
    SPELL_CLONE_NAME             = 57507,
    SPELL_CLONE_MODEL            = 45204,

    // Reflection'Spells
    SPELL_BALEFUL_STRIKE         = 69933,
    SPELL_SPIRIT_BURST           = 69900,
    H_SPELL_BALEFUL_STRIKE       = 70400,
    H_SPELL_SPIRIT_BURST         = 73046,
};


class npc_frostworn_general : public CreatureScript
{
public:
    npc_frostworn_general() : CreatureScript("npc_frostworn_general") { }

    struct npc_frostworn_generalAI : public ScriptedAI
    {
        npc_frostworn_generalAI(Creature *creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 uiShieldTimer;
        uint32 uiSpikeTimer;
        uint32 uiCloneTimer;

        void Reset()
        {
            if (!instance)
                return;
            uiShieldTimer = 5000;
            uiSpikeTimer = 14000;
            uiCloneTimer = 22000;
            instance->SetData(DATA_FROSWORN_EVENT, NOT_STARTED);
        }

        void JustDied(Unit* pKiller)
        {
            if (!instance)
                return;
            DoScriptText(SAY_DEATH, me);
            instance->SetData(DATA_FROSWORN_EVENT, DONE);
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!instance)
                return;

            if (me->getVictim())
                return;

            if (who->GetTypeId() != TYPEID_PLAYER
                || instance->GetData(DATA_MARWYN_EVENT) != DONE
                || !me->IsWithinDistInMap(who, 20.0f))
                return;

            if (who->GetTypeId() == TYPEID_PLAYER)
                if (Player* player = who->ToPlayer())
                    if (player->isGameMaster())
                        return;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            AttackStart(who);
        }

        void EnterCombat(Unit* pVictim)
        {
            if (!instance)
                return;
            DoScriptText(SAY_AGGRO, me);
            instance->SetData(DATA_FROSWORN_EVENT, IN_PROGRESS);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiShieldTimer < uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, DUNGEON_MODE(SPELL_SHIELD_THROWN, H_SPELL_SHIELD_THROWN));
                uiShieldTimer = urand(8000, 12000);
            }
            else
                uiShieldTimer -= uiDiff;

            if (uiSpikeTimer < uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, DUNGEON_MODE(SPELL_SPIKE,H_SPELL_SPIKE));
                uiSpikeTimer = urand(15000, 20000);
            }
            else
                uiSpikeTimer -= uiDiff;

            if (uiCloneTimer < uiDiff)
            {
                SummonClones();
                uiCloneTimer = 60000;
            }
            else
                uiCloneTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }

        void SummonClones()
        {
            std::list<Unit *> playerList;
            SelectTargetList(playerList, 5, SELECT_TARGET_TOPAGGRO, 0, true);

            if (playerList.empty())
                return;

            for (std::list<Unit*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
            {
                if (Unit* pTemp = (*itr))
                {
                    if (Creature* pReflection = me->SummonCreature(NPC_REFLECTION, pTemp->GetPositionX(), pTemp->GetPositionY(), pTemp->GetPositionZ(), pTemp->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000))
                    {
                        pReflection->SetName(pTemp->GetName());
                        pTemp->CastSpell(pReflection, SPELL_CLONE_NAME, true);
                        pTemp->CastSpell(pReflection, SPELL_CLONE_MODEL, true);
                        pReflection->setFaction(me->getFaction());
                        pReflection->AI()->AttackStart(pTemp);
                    }
                }
            }

        }
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_frostworn_generalAI(creature);
    }
};

class npc_spiritual_reflection : public CreatureScript
{
public:
    npc_spiritual_reflection() : CreatureScript("npc_spiritual_reflection") { }

    struct npc_spiritual_reflectionAI : public ScriptedAI
    {
        npc_spiritual_reflectionAI(Creature *creature) : ScriptedAI(creature)
        {
            Reset();
        }

        InstanceScript* instance;
        uint32 uiStrikeTimer;

        void Reset()
        {
            uiStrikeTimer = urand(1000,3000);
        }

        void JustDied(Unit* pKiller)
        {
            DoCast(pKiller, DUNGEON_MODE(SPELL_SPIRIT_BURST, H_SPELL_SPIRIT_BURST));
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiStrikeTimer < uiDiff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, DUNGEON_MODE(SPELL_BALEFUL_STRIKE, H_SPELL_BALEFUL_STRIKE));
                uiStrikeTimer = urand(3000, 8000);
            }
            else
                uiStrikeTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_spiritual_reflectionAI(creature);
    }
};

enum Defs
{
    /*INTRO - Pre Escape*/
    SAY_LICH_KING_AGGRO_A              = -1594477,
    SAY_LICH_KING_AGGRO_H              = -1594478,
    SAY_JAINA_AGGRO                    = -1594479,
    SAY_SYLVANA_AGGRO                  = -1594480,

    /*ESCAPE*/
    SAY_JAINA_WALL_01                  = -1594487,
    SAY_SYLVANA_WALL_01                = -1594488,
    SAY_JAINA_WALL_02                  = -1594489,
    SAY_SYLVANA_WALL_02                = -1594490,
    SAY_LICH_KING_WALL_02              = -1594491,
    SAY_LICH_KING_WALL_03              = -1594492,
    SAY_LICH_KING_WALL_04              = -1594493,
    SAY_JAINA_WALL_03                  = -1594494,
    SAY_JAINA_WALL_04                  = -1594495,
    SAY_SYLVANA_WALL_03                = -1594496,
    SAY_SYLVANA_WALL_04                = -1594497,
    SAY_JAINA_ESCAPE_01                = -1594498,
    SAY_JAINA_ESCAPE_02                = -1594499,
    SAY_SYLVANA_ESCAPE_01              = -1594500,
    SAY_SYLVANA_ESCAPE_02              = -1594501,
    SAY_JAINA_TRAP                     = -1594502,
    SAY_SYLVANA_TRAP                   = -1594503,
    SAY_MATHEAS_JAINA                  = -1594505,
    SAY_JAINA_FIRE                     = -1594526,
    SAY_SYLVANA_FIRE                   = -1594522,
    SAY_SYLVANA_FINAL_1                = -1594523,
    SAY_SYLVANA_FINAL_2                = -1594521,
    SAY_JAINA_FINAL_1                  = -1594527,
    SAY_JAINA_FINAL_2                  = -1594524,
    SAY_JAINA_FINAL_3                  = -1594525,
    SAY_LICH_KING_END_01               = -1594506,
    SAY_LICH_KING_END_02               = -1594507,
    SAY_LICH_KING_END_03               = -1594508,

    /*SPELLS AND VISUAL EFFECTS*/
    SPELL_WINTER                       = 69780,
    SPELL_FURY_OF_FROSTMOURNE          = 70063,
    SPELL_ICE_PRISON_VISUAL            = 69708,
    SPELL_DARK_ARROW                   = 70194,
    SPELL_ICE_BARRIER                  = 69787,
    SPELL_DESTROY_ICE_WALL_01          = 69784, //Jaina
    SPELL_DESTROY_ICE_WALL_03          = 70225, //Sylvana
    SPELL_SYLVANA_JUMP                 = 68339,
    SPELL_SYLVANA_STEP                 = 69087,
    SPELL_FIRE_CANNON                  = 67461,

    FACTION                            = 113
};

const Position CannonSpawns[4] =
{
    {5230.00f, 1658.75f, 802.22f, 0.00f},
    {5245.74f, 1644.44f, 802.35f, 0.00f},
    {5260.64f, 1636.07f, 802.16f, 0.00f},
    {5275.90f, 1633.22f, 802.25f, 0.00f},
};

class npc_jaina_and_sylvana_hor_part2 : public CreatureScript
{
public:
    npc_jaina_and_sylvana_hor_part2() : CreatureScript("npc_jaina_and_sylvana_hor_part2") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        InstanceScript* instance = creature->GetInstanceScript();

        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();
                ((npc_jaina_and_sylvana_hor_part2AI*)creature->AI())->Start(false,true);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                creature->SetTarget(0);

                if (instance)
                {
                    instance->SetData(DATA_ICE_WALL_1, NOT_STARTED);
                    instance->SetData(DATA_ICE_WALL_2, NOT_STARTED);
                    instance->SetData(DATA_ICE_WALL_3, NOT_STARTED);
                    instance->SetData(DATA_ICE_WALL_4, NOT_STARTED);
                    instance->SetData64(DATA_ESCAPE_LEADER, creature->GetGUID());
                    instance->SetData(DATA_LICHKING_EVENT, IN_PROGRESS);
                }
                return true;
            default:
                return false;
        }
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        InstanceScript* instance = creature->GetInstanceScript();

        if (!instance)
            return false;

        if (instance->GetData(DATA_LICHKING_EVENT) == DONE)
            return false;

        if (creature->isQuestGiver())
            player->PrepareQuestMenu( creature->GetGUID());

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Lets go!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_jaina_and_sylvana_hor_part2AI(creature);
    }

    struct npc_jaina_and_sylvana_hor_part2AI : public npc_escortAI
    {
        npc_jaina_and_sylvana_hor_part2AI(Creature* creature) : npc_escortAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 encounterTime;
        uint32 castTimer;
        uint32 stepTimer;
        uint32 subStep;
        uint32 Count;
        bool inFight;
        bool Event;
        bool PreFight;
        bool WallCast;
        uint64 uiLichKingGUID;
        uint64 leaderGUID;
        uint64 iceWallGUID;
        uint64 wallTargetGUID;
        uint64 captain;
        uint32 chestID;
        uint32 summonsCounter;

        void Reset()
        {
            if (!instance)
                return;

            if (instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS)
                return;

            subStep = 0;
            stepTimer = 500;
            inFight = true;
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER | UNIT_NPC_FLAG_GOSSIP);
            wallTargetGUID = 0;
            uiLichKingGUID = 0;
            summonsCounter = 1;
            WallCast = false;
            iceWallGUID = 0;
            Count = 0;

            if (me->GetEntry() == NPC_JAINA_PART2)
            {
                me->CastSpell(me, SPELL_ICE_BARRIER, false);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);
            }
            if (instance->GetData(DATA_LICHKING_EVENT) == DONE)
                me->SetVisible(false);
        }

        void AttackStart(Unit* who)
        {
            if (!who || !instance)
                return;

            if (me->GetEntry() != NPC_SYLVANAS_PART2 && me->GetEntry() != NPC_JAINA_PART2)
                return;

            if (instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS || inFight != true)
                return;

            npc_escortAI::AttackStart(who);

        }

        void JustDied(Unit* pKiller)
        {
            if (!instance)
                return;

            summonsCounter = 1;
            instance->SetData(DATA_LICHKING_EVENT, FAIL);
        }

        void WaypointReached(uint32 i)
        {
            if (!instance)
                return;

            switch (i)
            {
            case 3:
                instance->SetData(DATA_ICE_WALL_1, IN_PROGRESS);
                if (GameObject* gate = instance->instance->GetGameObject(instance->GetData64(GO_ICE_WALL_1)))
                {
                    // Once we reached this point, we can close the door again
                    instance->HandleGameObject(instance->GetData64(DATA_RUN_DOOR), false);

                    gate->SetGoState(GO_STATE_READY);
                    iceWallGUID = gate->GetGUID();
                }
                break;
            case 4:
                if (me->GetEntry() == NPC_JAINA_PART2)
                    DoScriptText(SAY_JAINA_WALL_01, me);
                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                    DoScriptText(SAY_SYLVANA_WALL_01, me);
                castTimer = 1000;
                SetEscortPaused(true);
                if (Creature* wallTarget = me->SummonCreature(NPC_ICE_WALL,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                {
                    wallTargetGUID = wallTarget->GetGUID();
                    wallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    if (me->GetEntry() == NPC_JAINA_PART2)
                        me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                    else if (me->GetEntry() == NPC_SYLVANAS_PART2)
                        me->CastSpell(me, SPELL_DESTROY_ICE_WALL_03, false);
                }
                WallCast = true;
                break;
            case 6:
                instance->SetData(DATA_ICE_WALL_2, IN_PROGRESS);
                if (Creature* wallTarget = instance->instance->GetCreature(wallTargetGUID))
                {
                    if (wallTarget->isAlive())
                    {
                        wallTarget->DespawnOrUnsummon();
                        wallTargetGUID = 0;
                    }
                }
                break;
            case 7:
                if (me->GetEntry() == NPC_JAINA_PART2)
                    DoScriptText(SAY_JAINA_WALL_02, me);
                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                    DoScriptText(SAY_SYLVANA_WALL_02, me);
                castTimer = 1000;
                SetEscortPaused(true);
                if (Creature* wallTarget = me->SummonCreature(NPC_ICE_WALL, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 720000))
                {
                    wallTargetGUID = wallTarget->GetGUID();
                    wallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    if (me->GetEntry() == NPC_JAINA_PART2)
                        me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                    else if (me->GetEntry() == NPC_SYLVANAS_PART2)
                        me->CastSpell(me, SPELL_DESTROY_ICE_WALL_03, false);
                }
                WallCast = true;
                break;
            case 9:
                if (me->GetEntry() == NPC_JAINA_PART2)
                    DoScriptText(SAY_JAINA_ESCAPE_01, me);
                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                    DoScriptText(SAY_SYLVANA_ESCAPE_01, me);
                break;
            case 10:
                instance->SetData(DATA_ICE_WALL_3, IN_PROGRESS);
                if (Creature* wallTarget = instance->instance->GetCreature(wallTargetGUID))
                {
                    if (wallTarget->isAlive())
                    {
                        wallTarget->DespawnOrUnsummon();
                        wallTargetGUID = 0;
                    }
                }
                break;
            case 11:
                if (me->GetEntry() == NPC_JAINA_PART2)
                    DoScriptText(SAY_JAINA_WALL_03, me);
                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                    DoScriptText(SAY_SYLVANA_WALL_03, me);
                castTimer = 1000;
                SetEscortPaused(true);
                if (Creature* wallTarget = me->SummonCreature(NPC_ICE_WALL,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                {
                    wallTargetGUID = wallTarget->GetGUID();
                    wallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    if (me->GetEntry() == NPC_JAINA_PART2)
                        me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                    else if (me->GetEntry() == NPC_SYLVANAS_PART2)
                        me->CastSpell(me, SPELL_DESTROY_ICE_WALL_03, false);
                }
                WallCast = true;
                break;
            case 13:
                if (me->GetEntry() == NPC_JAINA_PART2)
                    DoScriptText(SAY_JAINA_ESCAPE_02, me);
                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                    DoScriptText(SAY_SYLVANA_ESCAPE_02, me);
                break;
            case 15:
                instance->SetData(DATA_ICE_WALL_4, IN_PROGRESS);
                if (Creature* wallTarget = instance->instance->GetCreature(wallTargetGUID))
                {
                    if (wallTarget->isAlive())
                    {
                        wallTarget->DespawnOrUnsummon();
                        wallTargetGUID = 0;
                    }
                }
                break;
            case 16:
                if (me->GetEntry() == NPC_JAINA_PART2)
                    DoScriptText(SAY_JAINA_WALL_04, me);
                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                    DoScriptText(SAY_SYLVANA_WALL_04, me);
                castTimer = 1000;
                SetEscortPaused(true);
                if (Creature* wallTarget = me->SummonCreature(NPC_ICE_WALL,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                {
                    wallTargetGUID = wallTarget->GetGUID();
                    wallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    if (me->GetEntry() == NPC_JAINA_PART2)
                        me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                    else if (me->GetEntry() == NPC_SYLVANAS_PART2)
                        me->CastSpell(me, SPELL_DESTROY_ICE_WALL_03, false);
                }
                WallCast = true;
                break;
            case 20:
                if (me->GetEntry() == NPC_JAINA_PART2)
                    DoScriptText(SAY_JAINA_TRAP, me);
                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                    DoScriptText(SAY_SYLVANA_TRAP, me);
                SetEscortPaused(true);
                instance->SetData(DATA_LICHKING_EVENT, SPECIAL);
                break;
            case 21:
                if (Creature* wallTarget = instance->instance->GetCreature(wallTargetGUID))
                {
                    if (wallTarget->isAlive())
                    {
                        wallTarget->DespawnOrUnsummon();
                        wallTargetGUID = 0;
                    }
                }
                SetEscortPaused(true);
                if (me->GetEntry() == NPC_JAINA_PART2)
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);
                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                instance->SetData(DATA_LICHKING_EVENT, DONE);
                break;
            }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!who || !instance)
                return;

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = who->ToPlayer();

            if (player)
            {
                if (me->IsWithinDistInMap(who, 50.0f)
                    && instance->GetData(DATA_FROSWORN_EVENT) == DONE
                    && instance->GetData(DATA_PHASE) == 3)
                {
                    Event = true;
                    me->setFaction(FACTION);
                    instance->SetData(DATA_PHASE, 4);
                }
            }
        }

        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
        {
            if (!instance)
                return;

            if (instance->GetData(DATA_LICHKING_EVENT) != IN_PROGRESS)
            {
                uiDamage = 0;
                return;
            }
        }

        void JumpNextStep(uint32 Time)
        {
            stepTimer = Time;
            subStep++;
        }

        void Intro()
        {
            if (!instance)
                return;

            uiLichKingGUID = instance->GetData64(DATA_LICHKING);
            Creature* uiLichKing = GetLichKing();

            if (!uiLichKing)
                return;

            switch (subStep)
            {
            case 0:
                me->SetWalk(false);
                encounterTime = 0;
                me->SetTarget(uiLichKing->GetGUID());
                JumpNextStep(100);
                break;
            case 1:
                HoRQuestComplete(NPC_SYLVANAS_PART2);
                HoRQuestComplete(NPC_JAINA_PART2);
                if (uiLichKing)
                {
                    if (me->GetEntry() == NPC_JAINA_PART2)
                        DoScriptText(SAY_LICH_KING_AGGRO_A, uiLichKing);
                    if (me->GetEntry() == NPC_SYLVANAS_PART2)
                        DoScriptText(SAY_LICH_KING_AGGRO_H, uiLichKing);
                    uiLichKing->AI()->AttackStart(me);
                    me->AI()->AttackStart(uiLichKing);
                }
                JumpNextStep(3000);
                break;
            case 2:
                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                {
                    inFight = false;
                    if (uiLichKing)
                        me->GetMotionMaster()->MovePoint(0, (me->GetPositionX()-5)+rand()%10, (me->GetPositionY()-5)+rand()%10, me->GetPositionZ());
                    JumpNextStep(3000);
                }
                else
                    JumpNextStep(100);
                break;
            case 3:
                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                    inFight = true;
                JumpNextStep(100);
                break;
            case 4:
                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                {
                    if (uiLichKing)
                        me->CastSpell(uiLichKing, SPELL_SYLVANA_STEP, false);
                    JumpNextStep(3000);
                }
                else
                    JumpNextStep(100);
                break;
            case 5:
                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                {
                    inFight = false;
                    if (uiLichKing)
                        me->GetMotionMaster()->MovePoint(0, (me->GetPositionX()-5)+rand()%10, (me->GetPositionY()-5)+rand()%10, me->GetPositionZ());
                    JumpNextStep(3000);
                }
                else
                    JumpNextStep(12000);
                break;
            case 6:
                inFight = true;

                if (uiLichKing)
                {
                    if (me->GetEntry() == NPC_SYLVANAS_PART2)
                        DoCast(SPELL_SYLVANA_JUMP);
                    DoCast(uiLichKing, me->GetEntry() == NPC_JAINA_PART2 ? SPELL_ICE_PRISON_VISUAL : SPELL_DARK_ARROW, false);
                    uiLichKing->AttackStop();
                }
                JumpNextStep(1480);
                break;
            case 7:
                me->RemoveAllAuras();

                if (uiLichKing && !uiLichKing->HasAura(SPELL_ICE_PRISON_VISUAL))
                    uiLichKing->AddAura(me->GetEntry() == NPC_JAINA_PART2 ? SPELL_ICE_PRISON_VISUAL : SPELL_DARK_ARROW, uiLichKing);

                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                me->AttackStop();

                if (me->GetEntry() == NPC_JAINA_PART2)
                {
                    me->RemoveAurasDueToSpell(SPELL_ICE_BARRIER);
                    DoScriptText(SAY_JAINA_AGGRO, me);
                }

                if (me->GetEntry() == NPC_SYLVANAS_PART2)
                    DoScriptText(SAY_SYLVANA_AGGRO, me);

                JumpNextStep(3000);
                break;
            case 8:
                me->GetMotionMaster()->MovePoint(0, 5577.187f, 2236.003f, 733.012f);
                if (uiLichKing && !uiLichKing->HasAura(SPELL_ICE_PRISON_VISUAL))
                {
                    uiLichKing->AddAura(me->GetEntry() == NPC_JAINA_PART2 ? SPELL_ICE_PRISON_VISUAL : SPELL_DARK_ARROW, uiLichKing);
                    me->SetTarget(uiLichKing->GetGUID());
                }
                JumpNextStep(10000);
                break;
            case 9:
                if (uiLichKing && (!uiLichKing->HasAura(SPELL_ICE_PRISON_VISUAL) || !uiLichKing->HasAura(SPELL_DARK_ARROW)))
                {
                    uiLichKing->AddAura(me->GetEntry() == NPC_JAINA_PART2 ? SPELL_ICE_PRISON_VISUAL : SPELL_DARK_ARROW, uiLichKing);
                    me->SetTarget(uiLichKing->GetGUID());
                }
                me->RemoveAllAuras();
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                Count = 1;
                JumpNextStep(100);
                break;
            }
        }

        void Outro()
        {
            if (!instance)
                return;

            switch (subStep)
            {
            case 10:
                JumpNextStep(5000);
                break;
            case 11:
                if (GameObject* Gunship = instance->instance->GetGameObject(instance->GetData64(me->GetEntry() == NPC_JAINA_PART2 ? GO_SKYBREAKER : GO_ORGRIM_HAMMER)))
                    Gunship->SetPhaseMask(1, true);

                if (Creature* Captain = me->SummonCreature(me->GetEntry() == NPC_JAINA_PART2? NPC_BARTLETT : NPC_KORM, OutroSpawns[2]))
                {
                    DoScriptText(me->GetEntry() == NPC_JAINA_PART2 ? SAY_JAINA_FIRE : SAY_SYLVANA_FIRE, Captain);
                    captain = Captain->GetGUID();

                    // Dungeon Browser reward triggering
                    instance->UpdateEncounterState(ENCOUNTER_CREDIT_CAST_SPELL, 72830, me);

                    if (Captain->GetEntry() == NPC_BARTLETT)    //Alliance Loot
                    {
                        GameObject* chest = instance->instance->GetGameObject(instance->GetData64(IsHeroic() ? GO_CAPTAIN_CHEST_4 : GO_CAPTAIN_CHEST_2));
                        if (chest)
                        {
                            chest->SetPhaseMask(1, true);    // make visible
                        }
                    }
                    else    // Horde Loot
                    {
                        GameObject* chest = instance->instance->GetGameObject(instance->GetData64(IsHeroic() ? GO_CAPTAIN_CHEST_3 : GO_CAPTAIN_CHEST_1));
                        if (chest)
                        {
                            chest->SetPhaseMask(1, true);    // make visible
                        }
                    }
                }
                if (GameObject* Cave = instance->instance->GetGameObject(instance->GetData64(GO_CAVE)))
                {
                    Creature* caveTarget = me->SummonCreature(NPC_ICE_WALL,Cave->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 720000);
                    caveTarget->SetFloatValue(OBJECT_FIELD_SCALE_X, 4);

                    for (int8 i = 0; i < 4; i++)
                    {
                        if (Creature* pCannoner = me->SummonCreature(NPC_ICE_WALL, CannonSpawns[i], TEMPSUMMON_MANUAL_DESPAWN, 720000))
                        {
                            pCannoner->setFaction(me->getFaction());
                            pCannoner->CastSpell(caveTarget, SPELL_FIRE_CANNON, true);
                        }

                    }
                }
                JumpNextStep(6000);
                break;
            case 12:
                if (GameObject* Cave = instance->instance->GetGameObject(instance->GetData64(GO_CAVE)))
                    Cave->SetGoState(GO_STATE_READY);
                me->RemoveAllAuras();

                if (Creature* uiLichKing = GetLichKing())
                    uiLichKing->DespawnOrUnsummon();

                HoRQuestComplete(KILL_CREDIT_WOTLK);
                JumpNextStep(10000);
                break;
            case 13:
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                instance->SetData(DATA_LICHKING_EVENT, DONE);
                if (Creature* Captain = me->GetCreature(*me, captain))
                    DoScriptText(me->GetEntry() == NPC_JAINA_PART2 ? SAY_JAINA_FINAL_1 : SAY_SYLVANA_FINAL_1, Captain);
                me->SummonGameObject(me->GetEntry() == NPC_JAINA_PART2 ? GO_STAIRS_SKYBREAKER : GO_STAIRS_ORGRIM_HAMMER, 5247.45f, 1627.72f, 784.302f, 5.88208f, 0, 0, 0.199211f, -0.979957f, 1*DAY);
                JumpNextStep(5000);
                break;
            case 14:
                DoScriptText(me->GetEntry() == NPC_JAINA_PART2 ? SAY_JAINA_FINAL_2 : SAY_SYLVANA_FINAL_2, me);
                JumpNextStep(8000);
                break;
            case 15:
                DoScriptText(me->GetEntry() == NPC_JAINA_PART2 ? SAY_JAINA_FINAL_3:-0, me);
                JumpNextStep(2000);
                break;
            case 16:
                me->SetOrientation(0.68f);
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                JumpNextStep(5000);
                if (instance)
                {
                    if (IsHeroic())
                    {
                        instance->DoCompleteAchievement(ACHIEV_HOR_H);
                        if (encounterTime <= MAX_ENCOUNTER_TIME)
                            instance->DoCompleteAchievement(ACHIEV_NOT_RETREATING);
                    }
                    else
                    {
                        //instance->DoCompleteAchievement(ACHIEV_HOR);
                        instance->DoCompleteAchievement(ACHIEV_HOR);
                    }
                }
                instance->SetData(DATA_PHASE, 7);
                break;
            }
        }

        void HoRQuestComplete(uint32 killCredit)
        {
            if (instance)
            {
                Map::PlayerList const &PlayerList = instance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    i->getSource()->KilledMonsterCredit(killCredit, 0);
            }
        }

        // Did Lich King finish spawning of this wave?
        bool IsValidWall()
        {
            if (!instance)
                return false;

            switch (Count)
            {
                case 1:
                    if (instance->GetData(DATA_ICE_WALL_1) == DONE)
                        return true;
                    break;
                case 2:
                    if (instance->GetData(DATA_ICE_WALL_2) == DONE)
                        return true;
                    break;
                case 3:
                    if (instance->GetData(DATA_ICE_WALL_3) == DONE)
                        return true;
                    break;
                case 4:
                    if (instance->GetData(DATA_ICE_WALL_4) == DONE)
                        return true;
                    break;
            }
            return false;
        }

        Creature* GetLichKing()
        {
            if (!instance)
                return NULL;

            if (!instance->instance)
                return NULL;

            if (uiLichKingGUID)
                if (Creature* uiLichKing = instance->instance->GetCreature(uiLichKingGUID))
                    return uiLichKing;

            return NULL;
        }

        void UpdateEscortAI(const uint32 diff)
        {
            if (!instance || !Event)
                return;

            DoMeleeAttackIfReady();

            if (instance->GetData(DATA_PHASE) == 4 && instance->GetData(DATA_LICHKING_EVENT) != IN_PROGRESS)
            {
                if (stepTimer < diff)
                    Intro();
                else
                    stepTimer -= diff;
                encounterTime += diff;
            }

            if (instance->GetData(DATA_LICHKING_EVENT) == SPECIAL
                && instance->GetData(DATA_PHASE) != 6)       //End Cinematic
            {
                instance->SetData(DATA_PHASE, 6);
                subStep = 10;
                stepTimer = 0;
            }

            if (instance->GetData(DATA_PHASE) == 6)
            {
                if (stepTimer < diff)
                {
                    Outro();
                }
                else
                    stepTimer -= diff;
                return;
            }

            if (WallCast == true && castTimer < diff)
            {
                if (me->GetEntry() == NPC_SYLVANAS_PART2 || me->GetEntry() == NPC_JAINA_PART2)
                {
                    if (Creature* wallTarget = instance->instance->GetCreature(wallTargetGUID))
                        me->CastSpell(wallTarget, me->GetEntry()==NPC_SYLVANAS_PART2 ? SPELL_DESTROY_ICE_WALL_03 : SPELL_DESTROY_ICE_WALL_01, false);
                    castTimer = 1000;
                }
            }
            else
                castTimer -= diff;

            summonsCounter = 1;

            if (WallCast == true) // Save performance here, only needed when wallcasting
                if (Creature* uiLichKing = GetLichKing())
                    if (uiLichKing->AI())
                        summonsCounter = uiLichKing->AI()->GetData(DATA_CURRENT_SUMMONS);

            if (WallCast == true && summonsCounter == 0 && IsValidWall())
            {
                WallCast = false;
                me->InterruptNonMeleeSpells(false);
                SetEscortPaused(false);
                if (GameObject* gate = instance->instance->GetGameObject(iceWallGUID))
                    gate->SetGoState(GO_STATE_ACTIVE);

                /*
                Lich King himself handles the ice wall data
                switch (Count)
                {
                case 1: instance->SetData(DATA_ICE_WALL_1, DONE); break;
                case 2: instance->SetData(DATA_ICE_WALL_2, DONE); break;
                case 3: instance->SetData(DATA_ICE_WALL_3, DONE); break;
                case 4: instance->SetData(DATA_ICE_WALL_4, DONE); break;
                }*/

                ++Count;
                switch (Count)
                {
                    case 2:
                        if (GameObject* gate = instance->instance->GetGameObject(instance->GetData64(GO_ICE_WALL_2)))
                        {
                            gate->SetGoState(GO_STATE_READY);

                            if (Creature* uiLichKing = GetLichKing())
                                if (uiLichKing->isAlive())
                                    DoScriptText(SAY_LICH_KING_WALL_02, uiLichKing);
                            iceWallGUID = gate->GetGUID();
                        }
                        break;
                    case 3:
                        if (GameObject* gate = instance->instance->GetGameObject(instance->GetData64(GO_ICE_WALL_3)))
                        {
                            gate->SetGoState(GO_STATE_READY);

                            if (Creature* uiLichKing = GetLichKing())
                                if (uiLichKing->isAlive())
                                    DoScriptText(SAY_LICH_KING_WALL_03, uiLichKing);
                            iceWallGUID = gate->GetGUID();
                        }
                        break;
                    case 4:
                        if (GameObject* gate = instance->instance->GetGameObject(instance->GetData64(GO_ICE_WALL_4)))
                        {
                            gate->SetGoState(GO_STATE_READY);

                            if (Creature* uiLichKing = GetLichKing())
                                if (uiLichKing->isAlive())
                                    DoScriptText(SAY_LICH_KING_WALL_04, uiLichKing);
                            iceWallGUID = gate->GetGUID();
                        }
                        break;
                    case 5:
                        if (Creature* uiLichKing = GetLichKing())
                        {
                            if (uiLichKing->isAlive())
                            {
                                uiLichKing->RemoveAurasDueToSpell(SPELL_WINTER);
                                uiLichKing->SetSpeed(MOVE_WALK, 2.5f, true);
                                subStep = 0;
                            }
                        }
                        break;
                }
            }

            return;
        }
    };
};

class at_hor_waves_restarter : public AreaTriggerScript
{
public:
    at_hor_waves_restarter() : AreaTriggerScript("at_hor_waves_restarter") {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/)
    {
        InstanceScript* instance = player->GetInstanceScript();

        if (!instance)
            return true;

        if (player->isGameMaster())
            return true;

        if (instance->GetData(DATA_WAVES_STATE) == IN_PROGRESS)
            return true;

        if (instance->GetData(DATA_INTRO_EVENT) == DONE)
        {
            if (instance->GetData(DATA_FALRIC_EVENT) != DONE)    // Event of Falric failed -> both Marwyn and Falric are there
            {
                if (Creature* pFalric = player->GetCreature(*player, instance->GetData64(DATA_FALRIC)))
                {
                    if (!pFalric->isInCombat())
                        pFalric->CastSpell(pFalric, SPELL_BOSS_SPAWN_AURA, true);

                    pFalric->SetVisible(true);
                }
                if (Creature* pMarwyn = player->GetCreature(*player, instance->GetData64(DATA_MARWYN)))
                {
                    if (!pMarwyn->isInCombat())
                        pMarwyn->CastSpell(pMarwyn, SPELL_BOSS_SPAWN_AURA, true);

                    pMarwyn->SetVisible(true);
                }
            }
            else if (instance->GetData(DATA_MARWYN_EVENT) != DONE)    // Event of Marwyn failed -> only Marwyn is present
            {
                if (Creature* pMarwyn = player->GetCreature(*player, instance->GetData64(DATA_MARWYN)))
                {
                    if (!pMarwyn->isInCombat())
                        pMarwyn->CastSpell(pMarwyn, SPELL_BOSS_SPAWN_AURA, true);

                    pMarwyn->SetVisible(true);
                }
            }
            else // Marwyn and Falric done, open both doors
            {
                instance->HandleGameObject(instance->GetData64(DATA_FRONT_DOOR), true);
                instance->HandleGameObject(instance->GetData64(DATA_FROSTWORN_DOOR), true);
                return true;
            }
            instance->SetData(DATA_WAVES_STATE, IN_PROGRESS);
        }
        return true;
    }
};

class npc_queldelar : public CreatureScript
{
public:
    npc_queldelar() : CreatureScript("npc_queldelar") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_queldelarAI(creature);
    }
    struct npc_queldelarAI  : public ScriptedAI
    {
        npc_queldelarAI(Creature *c) : ScriptedAI(c)
        {
        }
        void MoveInLineOfSight(Unit* who)
        {
            if (!who)
                return;
            if (me->IsWithinDistInMap(who, 20) && who->HasAura(SPELL_QUELDELAR_AURA))
            {
                me->SummonCreature(NPC_QUELDELAR, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
                me->DisappearAndDie();
            }
        }
    };
};

const Position QuelDelarWaypoints[10] =
{
    {5297.322f,  2005.171f,  711.845f},
	{5292.493f,  2015.819f,  717.026f},
	{5291.562f,  2032.451f,  727.654f},
	{5307.162f,  2039.597f,  728.787f},
	{5332.974f,  2032.601f,  728.787f},
	{5340.196f,  2003.876f,  725.913f},
	{5334.647f,  1987.584f,  721.567f},
	{5321.635f,  1976.464f,  717.414f},
	{5308.645f,  1975.355f,  715.051f},
	{5293.111f,  1989.329f,  709.471f},
};

enum SchwertSpells
{
	SPELL_STRIKE       = 29426,
	SPELL_KLINGENSTURM = 67541,
	SPELL_DEADLYSTRIKE = 16856,
	SPELL_WIRBEL       = 67716,
	SPELL_WHIRLWIND    = 70300, //Visueller Effekt
	SPELL_MISSLES      = 70848,
};

enum EventsQuelDelar
{
	EVENT_STRIKE,
	EVENT_KLINGENSTURM,
	EVENT_DEADLYSTRIKE,
	EVENT_WIRBEL,
	EVENT_MISSLES,
};

class npc_queldelar_schwert : public CreatureScript
{
    public:
        npc_queldelar_schwert() : CreatureScript("npc_queldelar_schwert") { }

		CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_queldelar_schwertAI(pCreature);
        }

        struct npc_queldelar_schwertAI : public ScriptedAI
        {
            npc_queldelar_schwertAI(Creature* creature) : ScriptedAI(creature)
            {
            }

			uint8 count;
			bool player_reached;
			EventMap events;

			void Reset()
            {
				//Falsche Timer, mir Fehlen für die richtigen die passenden Informationen
                events.Reset();
		        events.ScheduleEvent(EVENT_STRIKE, 6000);
		        events.ScheduleEvent(EVENT_KLINGENSTURM, 20000);
		        events.ScheduleEvent(EVENT_DEADLYSTRIKE, 9000);
		        events.ScheduleEvent(EVENT_WIRBEL, 14000);
				events.ScheduleEvent(EVENT_MISSLES, 300);

				count = 0;
				player_reached = false;
	        }

			void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE || id != count)
                    return;

                if (id < 9)
                {
                    ++count;
					player_reached = false;
                }
                else 
                {
					me->SetSpeed(MOVE_FLIGHT, 1.0f);
					me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
					me->SetReactState(REACT_AGGRESSIVE);
					me->RemoveAura(SPELL_WHIRLWIND);
					player_reached = true;
                }
            }

			void UpdateAI(const uint32 diff)
            {
				if (!player_reached)
				{
					me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
				    me->SetReactState(REACT_PASSIVE);
				    me->AddAura(SPELL_WHIRLWIND, me);
					me->SetSpeed(MOVE_FLIGHT, 2.0f);
					me->GetMotionMaster()->MovePoint(count, QuelDelarWaypoints[count]);

					events.Update(diff);

				    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
						    case EVENT_MISSLES:
								DoCast(me, SPELL_MISSLES);
				                events.ScheduleEvent(EVENT_MISSLES, 300);
				                break;
						}
					}
				}

                if (!UpdateVictim())
                    return;

                events.Update(diff);

				while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
			            case EVENT_STRIKE:
				            DoCast(me->getVictim(), SPELL_STRIKE);
				            events.ScheduleEvent(EVENT_STRIKE, 6000);
				            break;
			            case EVENT_KLINGENSTURM:
				            DoCast(me->getVictim(), SPELL_KLINGENSTURM);
				            events.ScheduleEvent(EVENT_KLINGENSTURM, 20000);
				            break;
			            case EVENT_DEADLYSTRIKE:
				            DoCast(me->getVictim(), SPELL_DEADLYSTRIKE);
				            events.ScheduleEvent(EVENT_DEADLYSTRIKE, 9000);
							break;
		    	        case EVENT_WIRBEL:
				            DoCast(me->getVictim(), SPELL_WIRBEL);
				            events.ScheduleEvent(EVENT_WIRBEL, 14000);
				            break;
					}
				}
				DoMeleeAttackIfReady();
			}
		};
};

class boss_lich_king_hor : public CreatureScript
{
public:
    boss_lich_king_hor() : CreatureScript("boss_lich_king_hor") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_lich_king_horAI(creature);
    }

    struct boss_lich_king_horAI : public npc_escortAI
    {
        boss_lich_king_horAI(Creature* creature) : npc_escortAI(creature), summons(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        uint32 subStep;
        uint32 stepTimer;
        bool StartEscort;
        bool nonFight;
        float walkSpeed;
        uint32 guardCounter;
        std::list<uint64> guardGuids;
        SummonList summons;

        void Reset()
        {
            if (!instance)
                return;
            nonFight = false;
            StartEscort = false;
            walkSpeed = 1.0f;
            instance->SetData(DATA_CURRENT_WALL, 0);
            subStep = 0;
            guardCounter = 0;
            guardGuids.clear();
            summons.DespawnAll();
        }

        void JustDied(Unit* pKiller)
        {
            summons.DespawnAll();
        }

        void WaypointReached(uint32 i)
        {
            if (!instance)
                return;

            if (instance->GetData(DATA_ICE_WALL_1) == IN_PROGRESS)
            {
                SetEscortPaused(true);
            }

            // LK has stopped Sylvans / Jayna from escaping
            if (i== 19 && instance->GetData(DATA_LICHKING_EVENT) != SPECIAL)    // Sylvanas / Jayna may already have reached this point
            {
                SetEscortPaused(true);
                instance->SetData(DATA_LICHKING_EVENT, SPECIAL);
                DoScriptText(SAY_LICH_KING_WIN, me);

                if (Unit* Leader = Unit::GetUnit((*me), instance->GetData64(DATA_ESCAPE_LEADER)))
                    me->CastSpell(Leader, SPELL_HARVEST_SOUL, false);
            }

            // Sylvanas / Jayna has escaped
            if (i < 19 && instance->GetData(DATA_LICHKING_EVENT) == SPECIAL)
            {
                SetEscortPaused(true);
                DoScriptText(SAY_LICH_KING_END_DUN, me);
            }
        }

        void AttackStart(Unit* who)
        {
            if (!instance || !who)
                return;

            if (nonFight)
                return;

            if (instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS || who->GetTypeId() == TYPEID_PLAYER)
                return;

            npc_escortAI::AttackStart(who);
        }

        void JustSummoned(Creature* summoned)
        {
            if (!instance || !summoned)
                return;

            summons.Summon(summoned);

            if (Unit* Leader = Unit::GetUnit((*me), instance->GetData64(DATA_ESCAPE_LEADER)))
            {
                if (summoned->AI())
                    summoned->AI()->AttackStart(Leader);

                summoned->AddThreat(Leader, 100.0f);
            }
        }

        void SummonedCreatureDespawn(Creature* summon)
        {
            if (!summon)
                return;

            summons.Despawn(summon);
            guardGuids.remove(summon->GetGUID());

            if (guardGuids.size() > 0)
                guardCounter = guardGuids.size();
            else
                guardCounter = 0;
        }

        uint32 GetData(uint32 data)
        {
            switch (data)
            {
                case DATA_CURRENT_SUMMONS:
                    return guardCounter;
                default:
                    return npc_escortAI::GetData(data);
            }
        }

        void CallGuard(uint32 creatureId)
        {
            if (!creatureId)
                return;

            Position summonPos;
            summonPos.m_positionX = (me->GetPositionX()-5)+rand()%10;
            summonPos.m_positionY = (me->GetPositionY()-5)+rand()%10;
            summonPos.m_positionZ = me->GetPositionZ();
            summonPos.m_orientation = 4.17f;

            uint8 count = 1;

            if (creatureId == NPC_RAGING_GHOUL)
                count = 6;

            for (uint8 i = 0; i < count; i++)
            {
                if (TempSummon* summon = me->SummonCreature(creatureId, summonPos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 600000))
                {
                    guardCounter++;
                    guardGuids.push_back(summon->GetGUID());
                }
            }
        }

        void Wall01()
        {
            if (!instance)
                return;

            switch (subStep)
            {
                case 0:
                    DoScriptText(SAY_LICH_KING_WALL_01, me);
                    stepTimer = 2000;
                    ++subStep;
                    break;
                case 1:
                    CallGuard(NPC_RAGING_GHOUL);
                    DoScriptText(SAY_LICH_KING_GHOUL, me);
                    stepTimer = 7000;
                    ++subStep;
                    break;
                case 2:
                    DoCast(me, SPELL_WINTER);
                    DoScriptText(SAY_LICH_KING_WINTER, me);
                    me->SetSpeed(MOVE_WALK, walkSpeed, true);
                    stepTimer = 1000;
                    ++subStep;
                    break;
                case 3:
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    /* Increased difficulty on heroic mode. */
                    if (IsHeroic())
                    {
                        CallGuard(NPC_RISEN_WITCH_DOCTOR);
                        CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    }
                    instance->SetData(DATA_ICE_WALL_1, DONE);
                    stepTimer = 100;
                    subStep = 0;
                    SetEscortPaused(false);
                    break;
            }
        }

        void Wall02()
        {
            if (!instance)
                return;

            switch (subStep)
            {
                case 0:
                    DoScriptText(SAY_LICH_KING_GHOUL, me);
                    CallGuard(NPC_RAGING_GHOUL);
                    stepTimer = 1000;
                    ++subStep;
                    break;
                case 1:
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_ABON);
                    /* Increased difficulty on heroic mode. */
                    if (IsHeroic())
                    {
                        CallGuard(NPC_ABON);
                        CallGuard(NPC_ABON);
                    }
                    instance->SetData(DATA_ICE_WALL_2, DONE);
                    stepTimer = 100;
                    subStep = 0;
                    break;
            }
        }

        void Wall03()
        {
            if (!instance)
                return;

            switch (subStep)
            {
                case 0:
                    CallGuard(NPC_RAGING_GHOUL);
                    DoScriptText(SAY_LICH_KING_GHOUL, me);
                    stepTimer = 1000;
                    ++subStep;
                    break;
                case 1:
                    DoScriptText(SAY_LICH_KING_ABON, me);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_ABON);
                    CallGuard(NPC_ABON);
                    /* Increased difficulty on heroic mode. */
                    if (IsHeroic())
                    {
                        CallGuard(NPC_RISEN_WITCH_DOCTOR);
                        CallGuard(NPC_ABON);
                    }
                    instance->SetData(DATA_ICE_WALL_3, DONE);
                    stepTimer = 100;
                    subStep = 0;
                    break;
            }
        }

        void Wall04()
        {
            if (!instance)
                return;

            switch (subStep)
            {
                case 0:
                    CallGuard(NPC_RAGING_GHOUL);
                    DoScriptText(SAY_LICH_KING_GHOUL, me);
                    stepTimer = 1000;
                    ++subStep;
                    break;
                case 1:
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_ABON);
                    CallGuard(NPC_ABON);
                    DoScriptText(SAY_LICH_KING_ABON, me);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    CallGuard(NPC_RISEN_WITCH_DOCTOR);
                    /* Increased difficulty on heroic mode. */
                    if (IsHeroic())
                    {
                        CallGuard(NPC_RISEN_WITCH_DOCTOR);
                        CallGuard(NPC_ABON);
                    }
                    instance->SetData(DATA_ICE_WALL_4, DONE);
                    ++subStep;
                    break;
            }
        }

        void UpdateEscortAI(const uint32 diff)
        {
            if (!instance)
                return;
            if (instance->GetData(DATA_LICHKING_EVENT) == NOT_STARTED || instance->GetData(DATA_LICHKING_EVENT) == FAIL)
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }

            // Start chase for leader
            if (instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS && StartEscort != true)
            {
                if (me->isInCombat())
                    EnterEvadeMode();
                StartEscort = true;
                me->RemoveAurasDueToSpell(SPELL_ICE_PRISON);
                me->RemoveAurasDueToSpell(SPELL_DARK_ARROW);
                nonFight = true;
                me->AttackStop();
                me->SetSpeed(MOVE_WALK, 2.5f, true);
                Start(false, false);
                subStep = 0;
                stepTimer = 100;
            }

            // Leader caught, wipe
            if (Unit* Leader = Unit::GetUnit((*me), instance->GetData64(DATA_ESCAPE_LEADER)))
            {
                if (Leader->IsWithinDistInMap(me, 2.0f) && instance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS)
                {
                    SetEscortPaused(false);
                    me->StopMoving();
                    DoScriptText(SAY_LICH_KING_WIN, me);
                    me->CastSpell(me, SPELL_FURY_OF_FROSTMOURNE, true);    // dummy-cast
                    me->Kill(me);
                    me->Kill(Leader);
                }
            }

            // Note: The number of the current wall is set by the script of Sylvanas / Jayna
            // Used this stepping to avoid doing everything at the same time
            if (instance->GetData(DATA_ICE_WALL_1) == IN_PROGRESS)
            {
                if (stepTimer < diff)
                {
                    Wall01();
                }
                else
                    stepTimer -= diff;
            }
            else if (instance->GetData(DATA_ICE_WALL_2) == IN_PROGRESS)
            {
                if (stepTimer < diff)
                {
                    Wall02();
                }
                else
                    stepTimer -= diff;
            }
            else if (instance->GetData(DATA_ICE_WALL_3) == IN_PROGRESS)
            {
                if (stepTimer < diff)
                {
                    Wall03();
                }
                else
                    stepTimer -= diff;
            }
            else if (instance->GetData(DATA_ICE_WALL_4) == IN_PROGRESS)
            {
                if (stepTimer < diff)
                {
                    Wall04();
                }
                else
                    stepTimer -= diff;
            }

            return;
        }
    };
};

class npc_raging_ghoul : public CreatureScript
{
public:
    npc_raging_ghoul() : CreatureScript("npc_raging_ghoul") { }

    struct npc_raging_ghoulAI : public ScriptedAI
    {
        npc_raging_ghoulAI(Creature* creature) : ScriptedAI(creature) {}

        bool jumped;

        void Reset()
        {
            DoCast(me, SPELL_EMERGE_VISUAL);
            jumped = false;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f))
            {
                if (!jumped && me->IsWithinDistInMap(target, 30.0f) && !me->IsWithinDistInMap(target, 5.0f))
                {
                    jumped = true;
                    DoCast(target, SPELL_GHOUL_JUMP);
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_raging_ghoulAI(creature);
    }

};

class npc_risen_witch_doctor : public CreatureScript
{
public:
    npc_risen_witch_doctor() : CreatureScript("npc_risen_witch_doctor") { }

    struct npc_risen_witch_doctorAI : public ScriptedAI
    {
        npc_risen_witch_doctorAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 boltTimer;
        uint32 boltVolleyTimer;
        uint32 curseTimer;

        void Reset()
        {
            DoCast(me, SPELL_EMERGE_VISUAL);
            boltTimer = 6000;
            boltVolleyTimer = 15000;
            curseTimer = 7000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (curseTimer < diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    DoCast(target, DUNGEON_MODE(SPELL_COURSE_OF_DOOM, H_SPELL_COURSE_OF_DOOM));
                curseTimer = urand(10000, 15000);
            } else curseTimer -= diff;

            if (boltTimer < diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    DoCast(target, DUNGEON_MODE(SPELL_SHADOW_BOLT, H_SPELL_SHADOW_BOLT));
                boltTimer = urand(2000, 3000);
            } else boltTimer -= diff;

            if (boltVolleyTimer < diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    DoCast(target, DUNGEON_MODE(SPELL_SHADOW_BOLT_VOLLEY, H_SPELL_SHADOW_BOLT_VOLLEY));
                boltVolleyTimer = urand(15000, 22000);
            } else boltVolleyTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_risen_witch_doctorAI(creature);
    }

};

class npc_abon : public CreatureScript
{
public:
    npc_abon() : CreatureScript("npc_abon") { }

    struct npc_abonAI : public ScriptedAI
    {
        npc_abonAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 strikeTimer;
        uint32 vomitTimer;

        void Reset()
        {
            vomitTimer = 15000;
            strikeTimer = 6000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (strikeTimer < diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    DoCast(target, SPELL_ABON_STRIKE);
                strikeTimer = urand(7000, 9000);
            } else strikeTimer -= diff;

            if (vomitTimer < diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    DoCast(target, DUNGEON_MODE(SPELL_VOMIT_SPRAY, H_SPELL_VOMIT_SPRAY));
                vomitTimer = urand(15000, 20000);
            } else vomitTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_abonAI(creature);
    }
};

void AddSC_halls_of_reflection()
{
    new npc_jaina_or_sylvanas_hor("npc_sylvanas_hor_part1");
    new npc_jaina_or_sylvanas_hor("npc_jaina_hor_part1");
    new npc_jaina_and_sylvana_hor_part2();
    new npc_ghostly_priest();
    new npc_phantom_mage();
    new npc_phantom_hallucination();
    new npc_shadowy_mercenary();
    new npc_spectral_footman();
    new npc_tortured_rifleman();
    new at_hor_waves_restarter();
    new npc_frostworn_general();
    new npc_spiritual_reflection();
    new npc_queldelar();
    new boss_lich_king_hor();
    new npc_raging_ghoul();
    new npc_risen_witch_doctor();
    new npc_abon();
}
