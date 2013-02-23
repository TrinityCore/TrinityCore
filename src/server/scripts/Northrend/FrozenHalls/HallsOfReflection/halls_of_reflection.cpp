/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "halls_of_reflection.h"
#include "ScriptedEscortAI.h"

enum Texts
{
    SAY_TRASH_DEATH                               = 0,
};

enum Yells
{
    // Part one, Alliance
    SAY_JAINA_INTRO_1                           = 0,
    SAY_JAINA_INTRO_2                           = 1,
    SAY_JAINA_INTRO_3                           = 2,
    SAY_JAINA_INTRO_4                           = 3,
    SAY_UTHER_INTRO_A2_1                        = 0,
    SAY_JAINA_INTRO_5                           = 4,
    SAY_UTHER_INTRO_A2_2                        = 1,
    SAY_JAINA_INTRO_6                           = 5,
    SAY_UTHER_INTRO_A2_3                        = 2,
    SAY_JAINA_INTRO_7                           = 6,
    SAY_UTHER_INTRO_A2_4                        = 3,
    SAY_JAINA_INTRO_8                           = 7,
    SAY_UTHER_INTRO_A2_5                        = 4,
    SAY_JAINA_INTRO_9                           = 8,
    SAY_UTHER_INTRO_A2_6                        = 5,
    SAY_UTHER_INTRO_A2_7                        = 6,
    SAY_JAINA_INTRO_10                          = 9,
    SAY_UTHER_INTRO_A2_8                        = 7,
    SAY_JAINA_INTRO_11                          = 10,
    SAY_UTHER_INTRO_A2_9                        = 8,

    // Part one, Horde
    SAY_SYLVANAS_INTRO_1                        = 0,
    SAY_SYLVANAS_INTRO_2                        = 1,
    SAY_SYLVANAS_INTRO_3                        = 2,
    SAY_UTHER_INTRO_H2_1                        = 9,
    SAY_SYLVANAS_INTRO_4                        = 3,
    SAY_UTHER_INTRO_H2_2                        = 10,
    SAY_SYLVANAS_INTRO_5                        = 4,
    SAY_UTHER_INTRO_H2_3                        = 11,
    SAY_SYLVANAS_INTRO_6                        = 5,
    SAY_UTHER_INTRO_H2_4                        = 12,
    SAY_SYLVANAS_INTRO_7                        = 6,
    SAY_UTHER_INTRO_H2_5                        = 13,
    SAY_UTHER_INTRO_H2_6                        = 14,
    SAY_SYLVANAS_INTRO_8                        = 7,
    SAY_UTHER_INTRO_H2_7                        = 15,

    SAY_LK_INTRO_1                              = 0,
    SAY_LK_INTRO_2                              = 1,
    SAY_LK_INTRO_3                              = 2,
    SAY_FALRIC_INTRO_1                          = 5,
    SAY_MARWYN_INTRO_1                          = 5,
    SAY_FALRIC_INTRO_2                          = 6,

    SAY_JAINA_INTRO_END                         = 11,
    SAY_SYLVANAS_INTRO_END                      = 8,
    SAY_LK_JAINA_INTRO_END                      = 3,
    SAY_LK_SYLVANAS_INTRO_END                   = 4,

    /*INTRO - Pre Escape*/
    SAY_LICH_KING_AGGRO_A              = 0,
    SAY_LICH_KING_AGGRO_H              = 1,
    SAY_JAINA_AGGRO                    = 0,
    SAY_SYLVANA_AGGRO                  = 0,

    /*ESCAPE*/
    SAY_JAINA_WALL_01                  = 1,
    SAY_SYLVANA_WALL_01                = 1,
    SAY_LICH_KING_WALL_02              = 2,
    SAY_JAINA_WALL_02                  = 2,
    SAY_SYLVANA_WALL_02                = 2,
    SAY_LICH_KING_WALL_03              = 3,
    SAY_JAINA_WALL_03                  = 3,
    SAY_SYLVANA_WALL_03                = 3,
    SAY_JAINA_WALL_04                  = 4,
    SAY_SYLVANA_WALL_04                = 4,
    SAY_LICH_KING_WALL_04              = 4,
    SAY_JAINA_ESCAPE_01                = 5,
    SAY_SYLVANA_ESCAPE_01              = 5,
    SAY_JAINA_ESCAPE_02                = 6,
    SAY_SYLVANA_ESCAPE_02              = 6,
    SAY_JAINA_TRAP                     = 7,
    SAY_SYLVANA_TRAP                   = 7,
    SAY_ALLIANCE_FIRE                  = 0,
    SAY_HORDE_FIRE                     = 0,
    SAY_JAINA_FINAL_1                  = 1,
    SAY_SYLVANA_FINAL_1                = 1,
    SAY_JAINA_FINAL_2                  = 8,
    SAY_SYLVANA_FINAL_2                = 8,
    SAY_JAINA_FINAL_3                  = 9,
};

enum Events
{
    EVENT_START_PREINTRO                        = 1,
    EVENT_PREINTRO_1                            = 2,
    EVENT_PREINTRO_2                            = 3,

    EVENT_START_INTRO                           = 4,
    EVENT_SKIP_INTRO                            = 5,

    EVENT_INTRO_A2_1                            = 6,
    EVENT_INTRO_A2_2                            = 7,
    EVENT_INTRO_A2_3                            = 8,
    EVENT_INTRO_A2_4                            = 9,
    EVENT_INTRO_A2_5                            = 10,
    EVENT_INTRO_A2_6                            = 11,
    EVENT_INTRO_A2_7                            = 12,
    EVENT_INTRO_A2_8                            = 13,
    EVENT_INTRO_A2_9                            = 14,
    EVENT_INTRO_A2_10                           = 15,
    EVENT_INTRO_A2_11                           = 16,
    EVENT_INTRO_A2_12                           = 17,
    EVENT_INTRO_A2_13                           = 18,
    EVENT_INTRO_A2_14                           = 19,
    EVENT_INTRO_A2_15                           = 20,
    EVENT_INTRO_A2_16                           = 21,
    EVENT_INTRO_A2_17                           = 22,
    EVENT_INTRO_A2_18                           = 23,
    EVENT_INTRO_A2_19                           = 24,

    EVENT_INTRO_H2_1                            = 25,
    EVENT_INTRO_H2_2                            = 26,
    EVENT_INTRO_H2_3                            = 27,
    EVENT_INTRO_H2_3_1                          = 28,
    EVENT_INTRO_H2_4                            = 29,
    EVENT_INTRO_H2_5                            = 30,
    EVENT_INTRO_H2_6                            = 31,
    EVENT_INTRO_H2_7                            = 32,
    EVENT_INTRO_H2_8                            = 33,
    EVENT_INTRO_H2_9                            = 34,
    EVENT_INTRO_H2_10                           = 35,
    EVENT_INTRO_H2_11                           = 36,
    EVENT_INTRO_H2_12                           = 37,
    EVENT_INTRO_H2_13                           = 38,
    EVENT_INTRO_H2_14                           = 39,
    EVENT_INTRO_H2_15                           = 40,

    EVENT_INTRO_LK_1                            = 41,
    EVENT_INTRO_LK_2                            = 42,
    EVENT_INTRO_LK_3                            = 43,
    EVENT_INTRO_LK_4                            = 44,
    EVENT_INTRO_LK_5                            = 45,
    EVENT_INTRO_LK_6                            = 46,
    EVENT_INTRO_LK_7                            = 47,
    EVENT_INTRO_LK_8                            = 48,
    EVENT_INTRO_LK_9                            = 49,
    EVENT_INTRO_LK_10                           = 50,

    EVENT_INTRO_END                             = 51,

    // Trash Events
    EVENT_ACTIVATE_TRASH                        = 52,

    // Ghostly Priest
    EVENT_SHADOW_WORD_PAIN                      = 53,
    EVENT_CIRCLE_OF_DESTRUCTION                 = 54,
    EVENT_COWER_IN_FEAR                         = 55,
    EVENT_DARK_MENDING                          = 56,

    // Phantom Mage
    EVENT_FIREBALL                              = 57,
    EVENT_FLAMESTRIKE                           = 58,
    EVENT_FROSTBOLT                             = 59,
    EVENT_CHAINS_OF_ICE                         = 60,
    EVENT_HALLUCINATION                         = 61,

    // Shadowy Mercenary
    EVENT_SHADOW_STEP                           = 62,
    EVENT_DEADLY_POISON                         = 63,
    EVENT_ENVENOMED_DAGGER_THROW                = 64,
    EVENT_KIDNEY_SHOT                           = 65,

    // Spectral Footman
    EVENT_SPECTRAL_STRIKE                       = 66,
    EVENT_SHIELD_BASH                           = 67,
    EVENT_TORTURED_ENRAGE                       = 68,

    // Tortured Rifleman
    EVENT_SHOOT                                 = 69,
    EVENT_CURSED_ARROW                          = 70,
    EVENT_FROST_TRAP                            = 71,
    EVENT_ICE_SHOT                              = 72,

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

enum Phases
{
    PHASE_INTRO     = 1,
    PHASE_ONE       = 2,

    PHASE_INTRO_MASK    = 1 << PHASE_INTRO,
    PHASE_ONE_MASK      = 1 << PHASE_ONE,
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
private:
    bool m_isSylvana;

public:
    npc_jaina_or_sylvanas_hor(bool isSylvana, const char* name) : CreatureScript(name), m_isSylvana(isSylvana) { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
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

        QuestStatus status = player->GetQuestStatus(m_isSylvana ? QUEST_DELIVRANCE_FROM_THE_PIT_H2 : QUEST_DELIVRANCE_FROM_THE_PIT_A2);
        if (status == QUEST_STATUS_COMPLETE || status == QUEST_STATUS_REWARDED)
            player->ADD_GOSSIP_ITEM( 0, "Can you remove the sword?", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        // once last quest is completed, she offers this shortcut of the starting event
        QuestStatus status2 = player->GetQuestStatus(m_isSylvana ? QUEST_WRATH_OF_THE_LICH_KING_H2 : QUEST_WRATH_OF_THE_LICH_KING_A2);
        if (status2 == QUEST_STATUS_COMPLETE || status2 == QUEST_STATUS_REWARDED)
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

        void DoAction(int32 actionId)
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

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);
            switch (events.ExecuteEvent())
            {
                case EVENT_START_PREINTRO:
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    me->GetMotionMaster()->MovePoint(0, MoveDoorPos);

                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        events.ScheduleEvent(EVENT_PREINTRO_1, 0);
                    else
                        events.ScheduleEvent(EVENT_START_INTRO, 0);
                    break;

                case EVENT_PREINTRO_1:
                        Talk(SAY_JAINA_INTRO_1);
                        events.ScheduleEvent(EVENT_PREINTRO_2, 6000);
                    break;

                case EVENT_PREINTRO_2:
                        Talk(SAY_JAINA_INTRO_2);
                        events.ScheduleEvent(EVENT_START_INTRO, 7000);
                    break;

                case EVENT_START_INTRO:
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    me->GetMotionMaster()->MovePoint(0, MoveThronePos);
                    // Begining of intro is differents between factions as the speech sequence and timers are differents.
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        events.ScheduleEvent(EVENT_INTRO_A2_1, 0);
                    else
                        events.ScheduleEvent(EVENT_INTRO_H2_1, 0);
                    break;

            // A2 Intro Events
                case EVENT_INTRO_A2_1:
                    Talk(SAY_JAINA_INTRO_3);
                    events.ScheduleEvent(EVENT_INTRO_A2_2, 5000);
                    break;
                case EVENT_INTRO_A2_2:
                    Talk(SAY_JAINA_INTRO_4);
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
                        pUther->CastSpell(pUther, SPELL_BOSS_SPAWN_AURA, true);
                        pUther->SetReactState(REACT_PASSIVE); // be sure he will not aggro arthas
                        uiUther = pUther->GetGUID();
                        me->SetUInt64Value(UNIT_FIELD_TARGET, uiUther);
                        pUther->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                    }
                    events.ScheduleEvent(EVENT_INTRO_A2_5, 2000);
                    break;
                case EVENT_INTRO_A2_5:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        pUther->AI()->Talk(SAY_UTHER_INTRO_A2_1);
                    events.ScheduleEvent(EVENT_INTRO_A2_6, 3000);
                    break;
                case EVENT_INTRO_A2_6:
                    Talk(SAY_JAINA_INTRO_5);
                    events.ScheduleEvent(EVENT_INTRO_A2_7, 6000);
                    break;
                case EVENT_INTRO_A2_7:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        pUther->AI()->Talk(SAY_UTHER_INTRO_A2_2);
                    events.ScheduleEvent(EVENT_INTRO_A2_8, 6500);
                    break;
                case EVENT_INTRO_A2_8:
                    Talk(SAY_JAINA_INTRO_6);
                    events.ScheduleEvent(EVENT_INTRO_A2_9, 2000);
                    break;
                case EVENT_INTRO_A2_9:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        pUther->AI()->Talk(SAY_UTHER_INTRO_A2_3);
                    events.ScheduleEvent(EVENT_INTRO_A2_10, 9000);
                    break;
                case EVENT_INTRO_A2_10:
                    Talk(SAY_JAINA_INTRO_7);
                    events.ScheduleEvent(EVENT_INTRO_A2_11, 5000);
                    break;
                case EVENT_INTRO_A2_11:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        pUther->AI()->Talk(SAY_UTHER_INTRO_A2_4);
                    events.ScheduleEvent(EVENT_INTRO_A2_12, 11000);
                    break;
                case EVENT_INTRO_A2_12:
                    Talk(SAY_JAINA_INTRO_8);
                    events.ScheduleEvent(EVENT_INTRO_A2_13, 4000);
                    break;
                case EVENT_INTRO_A2_13:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        pUther->AI()->Talk(SAY_UTHER_INTRO_A2_5);
                    events.ScheduleEvent(EVENT_INTRO_A2_14, 12500);
                    break;
                case EVENT_INTRO_A2_14:
                    Talk(SAY_JAINA_INTRO_9);
                    events.ScheduleEvent(EVENT_INTRO_A2_15, 10000);
                    break;
                case EVENT_INTRO_A2_15:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        pUther->AI()->Talk(SAY_UTHER_INTRO_A2_6);
                    events.ScheduleEvent(EVENT_INTRO_A2_16, 22000);
                    break;
                case EVENT_INTRO_A2_16:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        pUther->AI()->Talk(SAY_UTHER_INTRO_A2_7);
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
                        pUther->AI()->Talk(SAY_UTHER_INTRO_A2_8);
                    }
                    events.ScheduleEvent(EVENT_INTRO_A2_19, 11000);
                    break;
                case EVENT_INTRO_A2_19:
                    Talk(SAY_JAINA_INTRO_11);
                    events.ScheduleEvent(EVENT_INTRO_LK_1, 2000);
                    break;

            // H2 Intro Events
                case EVENT_INTRO_H2_1:
                    Talk(SAY_SYLVANAS_INTRO_1);
                    events.ScheduleEvent(EVENT_INTRO_H2_2, 8000);
                    break;
                case EVENT_INTRO_H2_2:
                    Talk(SAY_SYLVANAS_INTRO_2);
                    events.ScheduleEvent(EVENT_INTRO_H2_3, 6000);
                    break;
                case EVENT_INTRO_H2_3:
                    Talk(SAY_SYLVANAS_INTRO_3);
                    DoCast(me, SPELL_CAST_VISUAL);
                    events.ScheduleEvent(EVENT_INTRO_H2_3_1, 2000);
                    break;
                case EVENT_INTRO_H2_3_1:
                    instance->HandleGameObject(instance->GetData64(DATA_FROSTMOURNE), true);
                    me->CastSpell(me, SPELL_FROSTMOURNE_SOUNDS, true);
                    events.ScheduleEvent(EVENT_INTRO_H2_4, 6000);
                    break;
                case EVENT_INTRO_H2_4:
                    // spawn UTHER during speach 2
                    if (Creature* pUther = me->SummonCreature(NPC_UTHER, UtherSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        pUther->GetMotionMaster()->MoveIdle();
                        pUther->CastSpell(pUther, SPELL_BOSS_SPAWN_AURA, true);
                        pUther->SetReactState(REACT_PASSIVE); // be sure he will not aggro arthas
                        uiUther = pUther->GetGUID();
                        me->SetUInt64Value(UNIT_FIELD_TARGET, uiUther);
                        pUther->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                    }
                    events.ScheduleEvent(EVENT_INTRO_H2_5, 2000);
                    break;
                case EVENT_INTRO_H2_5:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        pUther->AI()->Talk(SAY_UTHER_INTRO_H2_1);
                    events.ScheduleEvent(EVENT_INTRO_H2_6, 11000);
                    break;
                case EVENT_INTRO_H2_6:
                    Talk(SAY_SYLVANAS_INTRO_4);
                    events.ScheduleEvent(EVENT_INTRO_H2_7, 3000);
                    break;
                case EVENT_INTRO_H2_7:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        pUther->AI()->Talk(SAY_UTHER_INTRO_H2_2);
                    events.ScheduleEvent(EVENT_INTRO_H2_8, 6000);
                    break;
                case EVENT_INTRO_H2_8:
                    Talk(SAY_SYLVANAS_INTRO_5);
                    events.ScheduleEvent(EVENT_INTRO_H2_9, 5000);
                    break;
                case EVENT_INTRO_H2_9:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        pUther->AI()->Talk(SAY_UTHER_INTRO_H2_3);
                    events.ScheduleEvent(EVENT_INTRO_H2_10, 19000);
                    break;
                case EVENT_INTRO_H2_10:
                    Talk(SAY_SYLVANAS_INTRO_6);
                    events.ScheduleEvent(EVENT_INTRO_H2_11, 1500);
                    break;
                case EVENT_INTRO_H2_11:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        pUther->AI()->Talk(SAY_UTHER_INTRO_H2_4);
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
                        pUther->AI()->Talk(SAY_UTHER_INTRO_H2_5);
                    }
                    events.ScheduleEvent(EVENT_INTRO_H2_14, 12000);
                    break;
                case EVENT_INTRO_H2_14:
                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                        pUther->AI()->Talk(SAY_UTHER_INTRO_H2_6);
                    events.ScheduleEvent(EVENT_INTRO_H2_15, 8000);
                    break;
                case EVENT_INTRO_H2_15:
                    Talk(SAY_SYLVANAS_INTRO_8);
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

                        if(GameObject* pGate = instance->instance->GetGameObject(instance->GetData64(DATA_FROSTWORN_DOOR)))
                             pGate->SetGoState(GO_STATE_ACTIVE);

                        me->SetUInt64Value(UNIT_FIELD_TARGET, uiLichKing);
                        pLichKing->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                    }

                    if (Creature* pUther = me->GetCreature(*me, uiUther))
                    {
                        if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                            pUther->SetOrientation(0.851610);
                        pUther->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            pUther->AI()->Talk(SAY_UTHER_INTRO_A2_9);
                        else
                            pUther->AI()->Talk(SAY_UTHER_INTRO_H2_7);
                    }

                    events.ScheduleEvent(EVENT_INTRO_LK_2, 11000);
                    break;

                case EVENT_INTRO_LK_2:
                     if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                         pLichKing->AI()->Talk(SAY_LK_INTRO_1);
                    if(GameObject* pGate = instance->instance->GetGameObject(instance->GetData64(DATA_FROSTWORN_DOOR)))
                        pGate->SetGoState(GO_STATE_READY);
                     events.ScheduleEvent(EVENT_INTRO_LK_3, 2000);
                     break;

                case EVENT_INTRO_LK_3:
                     // The Lich King banishes Uther to the abyss.
                     if (Creature* pUther = me->GetCreature(*me, uiUther))
                         pUther->CastSpell(pUther, SPELL_UTHER_DESPAWN, true); // todo, either this spell is broken or it's triggered by another spell, because the LK should be able to cast it on uther.  Currently it cannot be cast on someone else.
                     events.ScheduleEvent(EVENT_INTRO_LK_4, 5000);
                     break;

                case EVENT_INTRO_LK_4:
                      if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                          pLichKing->AI()->Talk(SAY_LK_INTRO_2);
                     // He steps forward and removes the runeblade from the heap of skulls.
                      if (GameObject *pFrostmourne = me->FindNearestGameObject(GO_FROSTMOURNE, 11.0f))
                         pFrostmourne->SetPhaseMask(0,true);

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
                        pFalric->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        pFalric->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                        pFalric->GetMotionMaster()->MovePoint(0, 5283.309f, 2031.173f, 709.319f);
                    }
                    if (Creature* pMarwyn = me->GetCreature(*me, instance->GetData64(DATA_MARWYN)))
                    {
                        pMarwyn->CastSpell(pMarwyn, SPELL_BOSS_SPAWN_AURA, true);
                        pMarwyn->SetVisible(true);
                        pMarwyn->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        pMarwyn->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                        pMarwyn->GetMotionMaster()->MovePoint(0, 5335.585f, 1981.439f, 709.319f);
                    }

                    if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                        pLichKing->AI()->Talk(SAY_LK_INTRO_3);

                    events.ScheduleEvent(EVENT_INTRO_LK_6, 8000);
                    break;

                case EVENT_INTRO_LK_6:
                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        pFalric->AI()->Talk(SAY_FALRIC_INTRO_1);

                    events.ScheduleEvent(EVENT_INTRO_LK_7, 2000);
                    break;

                case EVENT_INTRO_LK_7:
                    if (Creature* pMarwyn = me->GetCreature(*me, instance->GetData64(DATA_MARWYN)))
                    {
                        pMarwyn->AI()->Talk(SAY_MARWYN_INTRO_1);
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                    }
                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);

                    if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                    {
                        if(GameObject* pGate = instance->instance->GetGameObject(instance->GetData64(DATA_FROSTWORN_DOOR)))
                            pGate->SetGoState(GO_STATE_ACTIVE);
                        pLichKing->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                        pLichKing->GetMotionMaster()->MovePoint(0, LichKingMoveAwayPos);
                    }

                    events.ScheduleEvent(EVENT_INTRO_LK_8, 2000);
                    break;

                case EVENT_INTRO_LK_8:
                    if (Creature* pFalric = me->GetCreature(*me, instance->GetData64(DATA_FALRIC)))
                        pFalric->AI()->Talk(SAY_FALRIC_INTRO_2);

                    instance->SetData(DATA_WAVE_STATE, SPECIAL);   // start first wave
                    events.ScheduleEvent(EVENT_INTRO_LK_9, 5000);
                    break;

                case EVENT_INTRO_LK_9:
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        Talk(SAY_JAINA_INTRO_END);
                    else
                        Talk(SAY_SYLVANAS_INTRO_END);

                    me->GetMotionMaster()->MovePoint(0, LichKingMoveAwayPos);

                    if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                    {
                        pLichKing->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                        pLichKing->GetMotionMaster()->MovePoint(0, LichKingMoveAwayPos);
                    }

                    events.ScheduleEvent(EVENT_INTRO_LK_10, 5000);
                    break;

                case EVENT_INTRO_LK_10:
                     if (Creature* pLichKing = me->GetCreature(*me, uiLichKing))
                         if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            pLichKing->AI()->Talk(SAY_LK_JAINA_INTRO_END);
                         else
                             pLichKing->AI()->Talk(SAY_LK_SYLVANAS_INTRO_END);

                     events.ScheduleEvent(EVENT_INTRO_END, 7000);
                     break;

                case EVENT_INTRO_END:
                    if (instance)
                    {
                        instance->SetData(DATA_INTRO_EVENT, DONE);
                    }

                    if(GameObject* pGate = instance->instance->GetGameObject(instance->GetData64(DATA_FROSTWORN_DOOR)))
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
                        me->SetUInt64Value(UNIT_FIELD_TARGET, uiLichKing);
                        pLichKing->SetUInt64Value(UNIT_FIELD_TARGET, me->GetGUID());
                    }

                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    me->GetMotionMaster()->MovePoint(0, MoveThronePos);
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
    SPELL_CIRCLE_OF_DESTRUCTION                   = 72320,
    SPELL_COWER_IN_FEAR                           = 72321,
    SPELL_DARK_MENDING                            = 72322,

    // Phantom Mage
    SPELL_FIREBALL                                = 72163,
    SPELL_FLAMESTRIKE                             = 72169,
    SPELL_FROSTBOLT                               = 72166,
    SPELL_CHAINS_OF_ICE                           = 72121,
    SPELL_HALLUCINATION                           = 72342,

    // Phantom Hallucination (same as phantom mage + HALLUCINATION_2 when dies)
    SPELL_HALLUCINATION_2                         = 72344,

    // Shadowy Mercenary
    SPELL_SHADOW_STEP                             = 72326,
    SPELL_DEADLY_POISON                           = 72329,
    SPELL_ENVENOMED_DAGGER_THROW                  = 72333,
    SPELL_KIDNEY_SHOT                             = 72335,

    // Spectral Footman
    SPELL_SPECTRAL_STRIKE                         = 72198,
    SPELL_SHIELD_BASH                             = 72194,
    SPELL_TORTURED_ENRAGE                         = 72203,

    // Tortured Rifleman
    SPELL_SHOOT                                   = 72208,
    SPELL_CURSED_ARROW                            = 72222,
    SPELL_FROST_TRAP                              = 72215,
    SPELL_ICE_SHOT                                = 72268,

    // Quel'Delar Event
    SPELL_QUELDELAR_AURA                          = 70013,
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
        npc_ghostly_priestAI(Creature* c) : ScriptedAI(c)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void JustReachedHome()
        {
            instance->SetData(DATA_WAVE_STATE, FAIL);
        }
        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000, 0, PHASE_ONE); // TODO: adjust timers
            events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_COWER_IN_FEAR, 20000, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_DARK_MENDING, 20000, 0, PHASE_ONE);
        }

        void JustDied(Unit* /*killer*/)
        {
            if (roll_chance_i(5))
                Talk(SAY_TRASH_DEATH);
        }

        void DoAction(int32 actionId)
        {
            switch (actionId)
            {
                case ACTION_TRASH_ACTIVATE:
                    events.SetPhase(PHASE_INTRO);
                    events.ScheduleEvent(EVENT_ACTIVATE_TRASH, 5000, 0, PHASE_INTRO);
                    break;
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() && !(events.GetPhaseMask() & PHASE_INTRO_MASK))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ACTIVATE_TRASH:
                    	events.Reset();
                        events.SetPhase(PHASE_ONE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                        me->SetReactState(REACT_AGGRESSIVE);
						if (Unit* unit = me->SelectNearestTarget())
						    AttackStart(unit);
							
                        DoZoneInCombat();
                        return;
                    case EVENT_SHADOW_WORD_PAIN:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_SHADOW_WORD_PAIN);
                        events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000, 0, PHASE_ONE);
                        return;
                    case EVENT_CIRCLE_OF_DESTRUCTION:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_CIRCLE_OF_DESTRUCTION);
                        events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000, 0, PHASE_ONE);
                        return;
                    case EVENT_COWER_IN_FEAR:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_COWER_IN_FEAR);
                        events.ScheduleEvent(EVENT_COWER_IN_FEAR, 20000, 0, PHASE_ONE);
                        return;
                    case EVENT_DARK_MENDING:
                        // find an ally with missing HP
                        if (Unit* target = DoSelectLowestHpFriendly(40, DUNGEON_MODE(30000, 50000)))
                        {
                            DoCast(target, SPELL_DARK_MENDING);
                            events.ScheduleEvent(EVENT_DARK_MENDING, 20000, 0, PHASE_ONE);
                        }
                        else
                        {
                            // no friendly unit with missing hp. re-check in just 5 sec.
                            events.ScheduleEvent(EVENT_DARK_MENDING, 5000, 0, PHASE_ONE);
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
        npc_phantom_mageAI(Creature* c) : ScriptedAI(c)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void Reset()
        {
            events.Reset();
        }
        
        void JustReachedHome()
        {
            instance->SetData(DATA_WAVE_STATE, FAIL);
        }

        void DoAction(int32 actionId)
        {
            switch (actionId)
            {
                case ACTION_TRASH_ACTIVATE:
                    events.SetPhase(PHASE_INTRO);
                    events.ScheduleEvent(EVENT_ACTIVATE_TRASH, 5000, 0, PHASE_INTRO);
                    break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (roll_chance_i(5))
                Talk(SAY_TRASH_DEATH);
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_FIREBALL, 3000, 0, PHASE_ONE); // TODO: adjust timers
            events.ScheduleEvent(EVENT_FLAMESTRIKE, 15000, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_FROSTBOLT, 9000, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 12000, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_HALLUCINATION, 40000, 0, PHASE_ONE);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() && !(events.GetPhaseMask() & PHASE_INTRO_MASK))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ACTIVATE_TRASH:
                        events.Reset();
                        events.SetPhase(PHASE_ONE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                        me->SetReactState(REACT_AGGRESSIVE);
						if (Unit* unit = me->SelectNearestTarget())
	                        AttackStart(unit);
							
                        DoZoneInCombat();
                        return;
                    case EVENT_FIREBALL:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_FIREBALL);
                        events.ScheduleEvent(EVENT_FIREBALL, 15000, 0, PHASE_ONE);
                        return;
                    case EVENT_FLAMESTRIKE:
                        DoCast(SPELL_FLAMESTRIKE);
                        events.ScheduleEvent(EVENT_FLAMESTRIKE, 15000, 0, PHASE_ONE);
                        return;
                    case EVENT_FROSTBOLT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_FROSTBOLT);
                        events.ScheduleEvent(EVENT_FROSTBOLT, 15000, 0, PHASE_ONE);
                        return;
                    case EVENT_CHAINS_OF_ICE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_CHAINS_OF_ICE);
                        events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 15000, 0, PHASE_ONE);
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
        npc_phantom_hallucinationAI(Creature* c) : npc_phantom_mage::npc_phantom_mageAI(c)
        {
        }

        void JustDied(Unit* /*who*/)
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
        npc_shadowy_mercenaryAI(Creature* c) : ScriptedAI(c)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void JustReachedHome()
        {
            instance->SetData(DATA_WAVE_STATE, FAIL);
        }
        
        void DoAction(int32 actionId)
        {
            switch (actionId)
            {
                case ACTION_TRASH_ACTIVATE:
                    events.SetPhase(PHASE_INTRO);
                    events.ScheduleEvent(EVENT_ACTIVATE_TRASH, 5000, 0, PHASE_INTRO);
                    break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (roll_chance_i(5))
                Talk(SAY_TRASH_DEATH);
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHADOW_STEP, 8000, 0, PHASE_ONE); // TODO: adjust timers
            events.ScheduleEvent(EVENT_DEADLY_POISON, 5000, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 15000, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_KIDNEY_SHOT, 24000, 0, PHASE_ONE);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() && !(events.GetPhaseMask() & PHASE_INTRO_MASK))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ACTIVATE_TRASH:
                        events.Reset();
                        events.SetPhase(PHASE_ONE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                        me->SetReactState(REACT_AGGRESSIVE);
						if (Unit* unit = me->SelectNearestTarget())
                            AttackStart(unit);
							
                        DoZoneInCombat();
                        return;
                    case EVENT_SHADOW_STEP:
                        DoCast(SPELL_SHADOW_STEP);
                        events.ScheduleEvent(EVENT_SHADOW_STEP, 8000, 0, PHASE_ONE);
                        return;
                    case EVENT_DEADLY_POISON:
                        DoCast(me->getVictim(), SPELL_DEADLY_POISON);
                        events.ScheduleEvent(EVENT_DEADLY_POISON, 10000, 0, PHASE_ONE);
                        return;
                    case EVENT_ENVENOMED_DAGGER_THROW:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_ENVENOMED_DAGGER_THROW);
                        events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 15000, 0, PHASE_ONE);
                        return;
                    case EVENT_KIDNEY_SHOT:
                        DoCast(me->getVictim(), SPELL_KIDNEY_SHOT);
                        events.ScheduleEvent(EVENT_KIDNEY_SHOT, 20000, 0, PHASE_ONE);
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
        npc_spectral_footmanAI(Creature* c) : ScriptedAI(c)  
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void Reset()
        {
            events.Reset();
        }
        
        void JustReachedHome()
        {
            instance->SetData(DATA_WAVE_STATE, FAIL);
        }

        void DoAction(int32 actionId)
        {
            switch (actionId)
            {
                case ACTION_TRASH_ACTIVATE:
                    events.SetPhase(PHASE_INTRO);
                    events.ScheduleEvent(EVENT_ACTIVATE_TRASH, 5000, 0, PHASE_INTRO);
                    break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (roll_chance_i(5))
                Talk(SAY_TRASH_DEATH);
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000, 0, PHASE_ONE); // TODO: adjust timers
            events.ScheduleEvent(EVENT_SHIELD_BASH, 10000, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000, 0, PHASE_ONE);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() && !(events.GetPhaseMask() & PHASE_INTRO_MASK))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ACTIVATE_TRASH:
                        events.Reset();
                        events.SetPhase(PHASE_ONE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
                        me->SetReactState(REACT_AGGRESSIVE);
						if (Unit* unit = me->SelectNearestTarget())
                           AttackStart(unit);
							
                        DoZoneInCombat();
                        return;
                    case EVENT_SPECTRAL_STRIKE:
                        DoCast(me->getVictim(), SPELL_SPECTRAL_STRIKE);
                        events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000, 0, PHASE_ONE);
                        return;
                    case EVENT_SHIELD_BASH:
                        DoCast(me->getVictim(), SPELL_SHIELD_BASH);
                        events.ScheduleEvent(EVENT_SHIELD_BASH, 5000, 0, PHASE_ONE);
                        return;
                    case EVENT_TORTURED_ENRAGE:
                        DoCast(SPELL_TORTURED_ENRAGE);
                        events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000, 0, PHASE_ONE);
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
        npc_tortured_riflemanAI(Creature* c) : ScriptedAI(c)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void JustReachedHome()
        {
            instance->SetData(DATA_WAVE_STATE, FAIL);
        }
        
        void DoAction(int32 actionId)
        {
            switch (actionId)
            {
                case ACTION_TRASH_ACTIVATE:
                    events.SetPhase(PHASE_INTRO);
                    events.ScheduleEvent(EVENT_ACTIVATE_TRASH, 5000, 0, PHASE_INTRO);
                    break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (roll_chance_i(5))
                Talk(SAY_TRASH_DEATH);
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHOOT, 2000, 0, PHASE_ONE); // TODO: adjust timers
            events.ScheduleEvent(EVENT_CURSED_ARROW, 10000, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_FROST_TRAP, 1000, 0, PHASE_ONE);
            events.ScheduleEvent(EVENT_ICE_SHOT, 15000, 0, PHASE_ONE);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() && !(events.GetPhaseMask() & PHASE_INTRO_MASK))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ACTIVATE_TRASH:
                        events.Reset();
                        events.SetPhase(PHASE_ONE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                        me->SetReactState(REACT_AGGRESSIVE);
						if (Unit* unit = me->SelectNearestTarget())
                            AttackStart(unit);
							
                        DoZoneInCombat();
                        break;
                    case EVENT_SHOOT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_SHOOT);
                        events.ScheduleEvent(EVENT_SHOOT, 2000, 0, PHASE_ONE);
                        return;
                    case EVENT_CURSED_ARROW:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_CURSED_ARROW);
                        events.ScheduleEvent(EVENT_CURSED_ARROW, 10000, 0, PHASE_ONE);
                        return;
                    case EVENT_FROST_TRAP:
                        DoCast(SPELL_FROST_TRAP);
                        events.ScheduleEvent(EVENT_FROST_TRAP, 30000, 0, PHASE_ONE);
                        return;
                    case EVENT_ICE_SHOT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_ICE_SHOT);
                        events.ScheduleEvent(EVENT_ICE_SHOT, 15000, 0, PHASE_ONE);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

enum GENERAL_EVENT
{
    SAY_GEN_AGGRO                         = 0,
    SAY_GEN_DEATH                         = 1,

    SPELL_SHIELD_THROWN                   = 69222,
    H_SPELL_SHIELD_THROWN                 = 73076,
    SPELL_SPIKE                           = 69184,
    H_SPELL_SPIKE                         = 70399,
    SPELL_CLONE_NAME                      = 57507,
    SPELL_CLONE_MODEL                     = 45204,

    // Reflection'Spells
    SPELL_BALEFUL_STRIKE                  = 69933,
    SPELL_SPIRIT_BURST                    = 69900,
    H_SPELL_BALEFUL_STRIKE                = 70400,
    H_SPELL_SPIRIT_BURST                  = 73046,
};

class npc_frostworn_general : public CreatureScript
{
public:
    npc_frostworn_general() : CreatureScript("npc_frostworn_general") { }

    struct npc_frostworn_generalAI : public ScriptedAI
    {
        npc_frostworn_generalAI(Creature *creature) : ScriptedAI(creature)
        {
            instance = (InstanceScript*)creature->GetInstanceScript();
            Reset();
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

        void JustDied(Unit* /*killer*/)
        {
            if (!instance)
                return;
            Talk(SAY_GEN_DEATH);
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
                || !me->IsWithinDistInMap(who, 20.0f)
                ) return;

            if (Player* player = (Player*)who)
                if (player->isGameMaster())
                    return;

            AttackStart(who);
        }

        void EnterCombat(Unit * /*victim*/)
        {
            if (!instance)
                return;
            Talk(SAY_GEN_AGGRO);
            instance->SetData(DATA_FROSWORN_EVENT, IN_PROGRESS);
        }

        void UpdateAI(uint32 uiDiff)
        {
            if(!UpdateVictim())
                return;

            if(uiShieldTimer < uiDiff)
            {
                if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                   DoCast(target, SPELL_SHIELD_THROWN);
                uiShieldTimer = urand(8000, 12000);
            }
            else
                uiShieldTimer -= uiDiff;

            if (uiSpikeTimer < uiDiff)
            {
                if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_SPIKE);
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
            for (std::list<Unit*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
            {
                Unit* pTemp = (*itr);
                Creature* pReflection = me->SummonCreature(NPC_REFLECTION, pTemp->GetPositionX(), pTemp->GetPositionY(), pTemp->GetPositionZ(), pTemp->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
                pReflection->SetName(pTemp->GetName());
                pTemp->CastSpell(pReflection, SPELL_CLONE_NAME, true);
                pTemp->CastSpell(pReflection, SPELL_CLONE_MODEL, true);
                pReflection->setFaction(me->getFaction());
                pReflection->AI()->AttackStart(pTemp);
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

        void JustDied(Unit* /*killer*/)
        {
            DoCastAOE(SPELL_SPIRIT_BURST, true);
        }

        void UpdateAI(uint32 uiDiff)
        {
            if(!UpdateVictim())
                return;

            if(uiStrikeTimer < uiDiff)
            {
                if(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                   DoCast(target, SPELL_BALEFUL_STRIKE);
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

    FACTION                            = 2076,
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

    bool OnGossipSelect(Player * plr, Creature * creature, uint32 /*sender*/, uint32 action)
    {
        InstanceScript * instance = (InstanceScript*)creature->GetInstanceScript();
        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                plr->CLOSE_GOSSIP_MENU();
                CAST_AI(npc_jaina_and_sylvana_hor_part2AI, creature->AI())->Start(false,true);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                creature->SetUInt64Value(UNIT_FIELD_TARGET, 0);
                creature->setActive(true);

                if(instance)
                {
                    instance->SetData64(DATA_ESCAPE_LIDER, creature->GetGUID());
                    instance->SetData(DATA_LICHKING_EVENT, IN_PROGRESS);
                }
                return true;
            default:
                return false;
        }
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        InstanceScript*   m_pInstance = (InstanceScript*)creature->GetInstanceScript();

        if(!m_pInstance)
            return false;

        if(m_pInstance->GetData(DATA_LICHKING_EVENT) == DONE)
            return false;

        if(creature->isQuestGiver())
           player->PrepareQuestMenu( creature->GetGUID());

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "We are ready!", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_jaina_and_sylvana_hor_part2AI(creature);
    }

    struct npc_jaina_and_sylvana_hor_part2AI : public npc_escortAI
    {
        npc_jaina_and_sylvana_hor_part2AI(Creature *creature) : npc_escortAI(creature)
        {
            m_pInstance = (InstanceScript*)creature->GetInstanceScript();
            Reset();
        }

        InstanceScript* m_pInstance;

        uint32 CastTimer;
        uint32 StepTimer;
        uint32 Step;
        int32 HoldTimer;
        uint32 Count;
        bool Fight;
        bool Event;
        bool PreFight;
        bool WallCast;
        uint64 m_uiLichKingGUID;
        uint64 m_uiLiderGUID;
        uint64 m_uiIceWallGUID;
        uint64 m_uipWallTargetGUID;
        uint64 uiCaptain;
        Creature* pLichKing;
        uint32 m_chestID;

        void Reset()
        {
            if(!m_pInstance)
                return;

            if(m_pInstance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS)
                return;

            Step = 0;
            StepTimer = 500;
            Fight = true;
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            m_uipWallTargetGUID = 0;
            me->SetHealth(me->GetMaxHealth() * 0.05);

            if(me->GetEntry() == NPC_JAINA_OUTRO)
            {
                me->CastSpell(me, SPELL_ICE_BARRIER, false);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);
            }
            if(m_pInstance->GetData(DATA_LICHKING_EVENT) == DONE)
                me->SetVisible(false);

        }

        void AttackStart(Unit* who)
        {
            if(!who)
                return;

            if(me->GetEntry() != NPC_SYLVANA_OUTRO)
                return;

            if(m_pInstance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS || Fight != true)
                return;

            npc_escortAI::AttackStart(who);

        }

        void JustDied(Unit* /*killer*/)
        {
            if(!m_pInstance)
                return;
            m_pInstance->SetData(DATA_LICHKING_EVENT, FAIL);
        }

        void WaypointReached(uint32 i)
        {
            switch(i)
            {
                case 3:
                    m_pInstance->SetData(DATA_ICE_WALL_1, IN_PROGRESS);
                    if(GameObject* pGate = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(GO_ICE_WALL_1)))
                    {
                        pGate->SetGoState(GO_STATE_READY);
                        m_uiIceWallGUID = pGate->GetGUID();
                    }
                    break;
                case 4:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_WALL_01);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_WALL_01);
                    CastTimer = 1000;
                    HoldTimer = 30000;
                    SetEscortPaused(true);
                    if (Creature *pWallTarget = me->SummonCreature(NPC_ICE_WALL,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                    {
                        m_uipWallTargetGUID = pWallTarget->GetGUID();
                        pWallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        if(me->GetEntry() == NPC_JAINA_OUTRO)
                            me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                    }
                    WallCast = true;
                    break;
                case 6:
                    m_pInstance->SetData(DATA_ICE_WALL_2, IN_PROGRESS);
                    if (Creature* pWallTarget = m_pInstance->instance->GetCreature(m_uipWallTargetGUID))
                    {
                        if(pWallTarget->isAlive())
                        {
                            pWallTarget->DespawnOrUnsummon();
                            m_uipWallTargetGUID = 0;
                        }
                    }
                    break;
                case 8:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_WALL_02);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_WALL_02);
                    CastTimer = 1000;
                    HoldTimer = 30000;
                    SetEscortPaused(true);
                    if (Creature *pWallTarget = me->SummonCreature(NPC_ICE_WALL,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                    {
                        m_uipWallTargetGUID = pWallTarget->GetGUID();
                        pWallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        if(me->GetEntry() == NPC_JAINA_OUTRO)
                            me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                    }
                    WallCast = true;
                    break;
                case 9:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_ESCAPE_01);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_ESCAPE_01);
                    break;
                case 11:
                    m_pInstance->SetData(DATA_ICE_WALL_3, IN_PROGRESS);
                    if (Creature* pWallTarget = m_pInstance->instance->GetCreature(m_uipWallTargetGUID))
                    {
                        if(pWallTarget->isAlive())
                        {
                            pWallTarget->DespawnOrUnsummon();
                            m_uipWallTargetGUID = 0;
                        }
                    }
                    break;
                case 12:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_WALL_03);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_WALL_03);
                    CastTimer = 1000;
                    HoldTimer = 30000;
                    SetEscortPaused(true);
                    if (Creature *pWallTarget = me->SummonCreature(NPC_ICE_WALL,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                    {
                        m_uipWallTargetGUID = pWallTarget->GetGUID();
                        pWallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        if(me->GetEntry() == NPC_JAINA_OUTRO)
                            me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                    }
                    WallCast = true;
                    break;
                case 13:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_ESCAPE_02);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_ESCAPE_02);
                    break;
                case 15:
                    m_pInstance->SetData(DATA_ICE_WALL_4, IN_PROGRESS);
                    if (Creature* pWallTarget = m_pInstance->instance->GetCreature(m_uipWallTargetGUID))
                    {
                        if(pWallTarget->isAlive())
                        {
                            pWallTarget->DespawnOrUnsummon();
                            m_uipWallTargetGUID = 0;
                        }
                    }
                    break;
                case 16:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_WALL_04);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_WALL_04);
                    CastTimer = 1000;
                    HoldTimer = 30000;
                    SetEscortPaused(true);
                    if (Creature *pWallTarget = me->SummonCreature(NPC_ICE_WALL,me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000))
                    {
                        m_uipWallTargetGUID = pWallTarget->GetGUID();
                        pWallTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        if(me->GetEntry() == NPC_JAINA_OUTRO)
                            me->CastSpell(me, SPELL_DESTROY_ICE_WALL_01, false);
                    }
                    WallCast = true;
                    break;
                case 19:
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        Talk(SAY_JAINA_TRAP);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_TRAP);
                    break;
                case 20:
                    if (Creature* pWallTarget = m_pInstance->instance->GetCreature(m_uipWallTargetGUID))
                    {
                        if(pWallTarget->isAlive())
                        {
                            pWallTarget->DespawnOrUnsummon();
                            m_uipWallTargetGUID = 0;
                        }
                    }
                    SetEscortPaused(true);
                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if(!who || !m_pInstance)
                return;

            if(who->GetTypeId() != TYPEID_PLAYER)
                return;

            Player* player = (Player *)who;

            if(player->GetTeam() == ALLIANCE && me->GetEntry() == NPC_SYLVANA_OUTRO)
                return;

            if(player->GetTeam() == HORDE && me->GetEntry() == NPC_JAINA_OUTRO)
                return;

            if(me->IsWithinDistInMap(who, 50.0f)
                && m_pInstance->GetData(DATA_FROSWORN_EVENT) == DONE
                && m_pInstance->GetData(DATA_PHASE) == 3)
            {
                player = (Player *)who;
                Event = true;
                me->setFaction(FACTION);
                m_pInstance->SetData(DATA_PHASE, 4);
            }
        }

        void DamageTaken(Unit* /*doneby*/, uint32 &uiDamage)
        {
            if(!m_pInstance)
                return;

            if(m_pInstance->GetData(DATA_LICHKING_EVENT) != IN_PROGRESS)
            {
                uiDamage = 0;
                return;
            }

            if(m_pInstance->GetData(DATA_LICHKING_EVENT) == IN_PROGRESS && WallCast == true)
            {
                HoldTimer = HoldTimer + 100;
                return;
            }
        }

        void JumpNextStep(uint32 Time)
        {
            StepTimer = Time;
            Step++;
        }

        void Intro()
        {
            switch(Step)
            {
                case 0:
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_WALKING);
                    m_uiLichKingGUID = m_pInstance->GetData64(DATA_LICHKING);
                    pLichKing = m_pInstance->instance->GetCreature(m_uiLichKingGUID);
                    me->SetUInt64Value(UNIT_FIELD_TARGET, pLichKing->GetGUID());
                    JumpNextStep(100);
                    break;
                case 1:
                    HoRQuestComplete(me->GetEntry());
                    if(pLichKing)
                    {
                        if(me->GetEntry() == NPC_JAINA_OUTRO)
                            pLichKing->AI()->Talk(SAY_LICH_KING_AGGRO_A);
                        if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                            pLichKing->AI()->Talk(SAY_LICH_KING_AGGRO_H);
                        pLichKing->AI()->AttackStart(me);
                        me->AI()->AttackStart(pLichKing);
                    }
                    JumpNextStep(3000);
                    break;
                case 2:
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                    {
                        Fight = false;
                        if(pLichKing)
                            me->GetMotionMaster()->MovePoint(0, (me->GetPositionX()-5)+rand()%10, (me->GetPositionY()-5)+rand()%10, me->GetPositionZ());
                        JumpNextStep(3000);
                    }
                    else
                        JumpNextStep(100);
                    break;
                case 3:
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Fight = true;
                    JumpNextStep(100);
                    break;
                case 4:
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                    {
                        if(pLichKing)
                            me->CastSpell(pLichKing, SPELL_SYLVANA_STEP, false);
                        JumpNextStep(3000);
                    }
                    else
                        JumpNextStep(100);
                    break;
                case 5:
                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                    {
                        Fight = false;
                        if(pLichKing)
                            me->GetMotionMaster()->MovePoint(0, (me->GetPositionX()-5)+rand()%10, (me->GetPositionY()-5)+rand()%10, me->GetPositionZ());
                        JumpNextStep(3000);
                    }
                    else
                        JumpNextStep(12000);
                    break;
                case 6:
                    Fight = true;

                    if(pLichKing)
                    {
                        if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                            DoCast(SPELL_SYLVANA_JUMP);
                        DoCast(pLichKing, me->GetEntry() == NPC_JAINA_OUTRO ? SPELL_ICE_PRISON_VISUAL : SPELL_DARK_ARROW, false);
                        pLichKing->AttackStop();
                    }
                    JumpNextStep(1480);
                    break;
                case 7:
                    me->RemoveAllAuras();

                    if(pLichKing && !pLichKing->HasAura(SPELL_ICE_PRISON_VISUAL))
                        pLichKing->AddAura(me->GetEntry() == NPC_JAINA_OUTRO ? SPELL_ICE_PRISON_VISUAL : SPELL_DARK_ARROW, pLichKing);

                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                    me->AttackStop();

                    if(me->GetEntry() == NPC_JAINA_OUTRO)
                    {
                        me->RemoveAurasDueToSpell(SPELL_ICE_BARRIER);
                        Talk(SAY_JAINA_AGGRO);
                    }

                    if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                        Talk(SAY_SYLVANA_AGGRO);

                    JumpNextStep(3000);
                    break;
                case 8:
                    me->GetMotionMaster()->MovePoint(0, 5577.187f, 2236.003f, 733.012f);
                    if(pLichKing && !pLichKing->HasAura(SPELL_ICE_PRISON_VISUAL))
                    {
                        pLichKing->AddAura(me->GetEntry() == NPC_JAINA_OUTRO ? SPELL_ICE_PRISON_VISUAL : SPELL_DARK_ARROW, pLichKing);
                        me->SetUInt64Value(UNIT_FIELD_TARGET, pLichKing->GetGUID());
                    }
                    JumpNextStep(5000);
                    break;
                case 9:
                    if(pLichKing && (!pLichKing->HasAura(SPELL_ICE_PRISON_VISUAL) || !pLichKing->HasAura(SPELL_DARK_ARROW)))
                    {
                        pLichKing->AddAura(me->GetEntry() == NPC_JAINA_OUTRO ? SPELL_ICE_PRISON_VISUAL : SPELL_DARK_ARROW, pLichKing);
                        me->SetUInt64Value(UNIT_FIELD_TARGET, pLichKing->GetGUID());
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
            switch(Step)
            {
                case 10:
                    JumpNextStep(10000);
                    break;
                case 11:
                    if(GameObject* pGunship = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(me->GetEntry() == NPC_JAINA_OUTRO ? GO_SKYBREAKER : GO_ORGRIM_HAMMER)))
                        pGunship->SetPhaseMask(1, true);

                    if(Creature* pCaptain = me->SummonCreature(me->GetEntry() == NPC_JAINA_OUTRO? NPC_BARTLETT : NPC_KORM, 5251.17f, 1610.2f, 795.812f, 2.07997f))
                    {
                        pCaptain->AI()->Talk(SAY_HORDE_FIRE);
                        uiCaptain = pCaptain->GetGUID();
                    }
                    if(GameObject* pCave = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(GO_CAVE)))
                    {
                        Creature *pCaveTarget = me->SummonCreature(NPC_ICE_WALL,pCave->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation(),TEMPSUMMON_MANUAL_DESPAWN,720000);
                        pCaveTarget->SetFloatValue(OBJECT_FIELD_SCALE_X, 4);

                        for(int8 i = 0; i<4; i++)
                        {
                            if(Creature* pCannoner = me->SummonCreature(NPC_ICE_WALL, CannonSpawns[i],TEMPSUMMON_MANUAL_DESPAWN,720000))
                            {
                                pCannoner->setFaction(me->getFaction());
                                pCannoner->CastSpell(pCaveTarget, SPELL_FIRE_CANNON, true);
                            }

                        }
                    }
                    JumpNextStep(6000);
                    break;
                case 12:
                    if(GameObject* pCave = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(GO_CAVE)))
                        pCave->SetGoState(GO_STATE_READY);
                    me->RemoveAllAuras();

                    if (pLichKing)
                        pLichKing->DespawnOrUnsummon();

                    HoRQuestComplete(38211);
                    JumpNextStep(10000);
                    break;
                case 13:
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_STAND);
                    m_pInstance->SetData(DATA_LICHKING_EVENT, DONE);
                    m_pInstance->DoCastSpellOnPlayers(SPELL_ACHIEV_CHECK);
                    if(Creature* pCaptain = me->GetCreature(*me, uiCaptain))
                        pCaptain->AI()->Talk(SAY_JAINA_FINAL_1);
                    me->SummonGameObject(me->GetEntry() == NPC_JAINA_OUTRO ? GO_STAIRS_SKYBREAKER : GO_STAIRS_ORGRIM_HAMMER, 5247.45f, 1627.72f, 784.302f, 5.88208f, 0, 0, 0.199211f, -0.979957f, 1*DAY);
                    JumpNextStep(10000);
                    break;
                case 14:
                    if (m_pInstance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        Talk(SAY_JAINA_FINAL_2);

                    else
                        Talk(SAY_SYLVANA_FINAL_2);

                    JumpNextStep(20000);
                    break;
                case 15:
                    if (m_pInstance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        Talk(SAY_JAINA_FINAL_3);

                    JumpNextStep(5000);
                    break;
                case 16:
                    me->SetOrientation(0.68f);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    JumpNextStep(5000);
                    break;
            }
        }

        void HoRQuestComplete(uint32 killCredit)
        {
            if(m_pInstance)
            {
                Map::PlayerList const &PlayerList = m_pInstance->instance->GetPlayers();
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    i->getSource()->KilledMonsterCredit(killCredit, 0);
            }
        }

        void UpdateEscortAI(const uint32 diff)
        {
            if(!m_pInstance || !Event)
                return;

            DoMeleeAttackIfReady();

            if(m_pInstance->GetData(DATA_PHASE) == 4 && m_pInstance->GetData(DATA_LICHKING_EVENT) != IN_PROGRESS)
            {
                if(StepTimer < diff)
                    Intro();
                else
                    StepTimer -= diff;
            }

            if(m_pInstance->GetData(DATA_LICHKING_EVENT) == SPECIAL
                && m_pInstance->GetData(DATA_PHASE) != 6)       //End Cinematic
            {
                m_pInstance->SetData(DATA_PHASE, 6);
                Step = 10;
            }

            if (m_pInstance->GetData(DATA_PHASE) == 6)
            {
                if(StepTimer < diff)
                    Outro();
                else
                    StepTimer -= diff;
                return;
            }

            if(WallCast == true && CastTimer < diff)
            {
                if(me->GetEntry() == NPC_SYLVANA_OUTRO)
                {
                   if (Creature* pWallTarget = m_pInstance->instance->GetCreature(m_uipWallTargetGUID))
                        me->CastSpell(pWallTarget, SPELL_DESTROY_ICE_WALL_03, false);
                    CastTimer = 1000;
                }
            }
            else
                CastTimer -= diff;

            if (WallCast == true && HoldTimer < 10000 && ( m_pInstance->GetData(DATA_SUMMONS) == 0 || !me->isInCombat()))
            {
                WallCast = false;
                me->InterruptNonMeleeSpells(false);
                SetEscortPaused(false);
                if(GameObject* pGate = m_pInstance->instance->GetGameObject(m_uiIceWallGUID))
                    pGate->SetGoState(GO_STATE_ACTIVE);
                ++Count;
                switch(Count)
                {
                    case 2:
                        if(GameObject* pGate = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(GO_ICE_WALL_2)))
                        {
                            pGate->SetGoState(GO_STATE_READY);
                            if(pLichKing && pLichKing->isAlive())
                                pLichKing->AI()->Talk(SAY_LICH_KING_WALL_02);
                            m_uiIceWallGUID = pGate->GetGUID();
                        }
                        break;
                    case 3:
                        if(GameObject* pGate = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(GO_ICE_WALL_3)))
                        {
                            pGate->SetGoState(GO_STATE_READY);
                            if(pLichKing && pLichKing->isAlive())
                                pLichKing->AI()->Talk(SAY_LICH_KING_WALL_03);
                            m_uiIceWallGUID = pGate->GetGUID();
                        }
                        break;
                    case 4:
                        if(GameObject* pGate = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(GO_ICE_WALL_4)))
                        {
                            pGate->SetGoState(GO_STATE_READY);
                            if(pLichKing && pLichKing->isAlive())
                                pLichKing->AI()->Talk(SAY_LICH_KING_WALL_04);
                            m_uiIceWallGUID = pGate->GetGUID();
                        }
                        break;
                    case 5:
                        if(pLichKing && pLichKing->isAlive())
                        {
                            pLichKing->RemoveAurasDueToSpell(SPELL_WINTER);
                            pLichKing->SetSpeed(MOVE_WALK, 2.5f, true);
                            Step = 0;
                        }
                        break;
                }
            }
            else
            {
                HoldTimer -= diff;
                if (HoldTimer <= 0)
                    HoldTimer = 0;
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

            if (instance->GetData(DATA_INTRO_EVENT) == DONE && instance->GetData(DATA_MARWYN_EVENT) != DONE && instance->GetData(DATA_WAVE_STATE) == FAIL)
            {
                instance->SetData(DATA_WAVE_STATE, IN_PROGRESS);

                if (Creature* pFalric = player->GetCreature(*player, instance->GetData64(DATA_FALRIC)))
                {
                    pFalric->CastSpell(pFalric, SPELL_BOSS_SPAWN_AURA, true);
                    pFalric->SetVisible(true);
                }
                if (Creature* pMarwyn = player->GetCreature(*player, instance->GetData64(DATA_MARWYN)))
                {
                    pMarwyn->CastSpell(pMarwyn, SPELL_BOSS_SPAWN_AURA, true);
                    pMarwyn->SetVisible(true);
                }
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

void AddSC_halls_of_reflection()
{
    new npc_jaina_or_sylvanas_hor(true, "npc_sylvanas_hor_part1");
    new npc_jaina_or_sylvanas_hor(false, "npc_jaina_hor_part1");
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
}
