/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "Player.h"
#include "halls_of_reflection.h"

enum Text
{
    SAY_JAINA_INTRO_1                   = 0,
    SAY_JAINA_INTRO_2                   = 1,
    SAY_JAINA_INTRO_3                   = 2,
    SAY_JAINA_INTRO_4                   = 3,
    SAY_JAINA_INTRO_5                   = 4,
    SAY_JAINA_INTRO_6                   = 5,
    SAY_JAINA_INTRO_7                   = 6,
    SAY_JAINA_INTRO_8                   = 7,
    SAY_JAINA_INTRO_9                   = 8,
    SAY_JAINA_INTRO_10                  = 9,
    SAY_JAINA_INTRO_11                  = 10,
    SAY_JAINA_INTRO_END                 = 11,

    SAY_SYLVANAS_INTRO_1                = 0,
    SAY_SYLVANAS_INTRO_2                = 1,
    SAY_SYLVANAS_INTRO_3                = 2,
    SAY_SYLVANAS_INTRO_4                = 3,
    SAY_SYLVANAS_INTRO_5                = 4,
    SAY_SYLVANAS_INTRO_6                = 5,
    SAY_SYLVANAS_INTRO_7                = 6,
    SAY_SYLVANAS_INTRO_8                = 7,
    SAY_SYLVANAS_INTRO_END              = 8,

    SAY_UTHER_INTRO_A2_1                = 0,
    SAY_UTHER_INTRO_A2_2                = 1,
    SAY_UTHER_INTRO_A2_3                = 2,
    SAY_UTHER_INTRO_A2_4                = 3,
    SAY_UTHER_INTRO_A2_5                = 4,
    SAY_UTHER_INTRO_A2_6                = 5,
    SAY_UTHER_INTRO_A2_7                = 6,
    SAY_UTHER_INTRO_A2_8                = 7,
    SAY_UTHER_INTRO_A2_9                = 8,
    SAY_UTHER_INTRO_H2_1                = 9,
    SAY_UTHER_INTRO_H2_2                = 10,
    SAY_UTHER_INTRO_H2_3                = 11,
    SAY_UTHER_INTRO_H2_4                = 12,
    SAY_UTHER_INTRO_H2_5                = 13,
    SAY_UTHER_INTRO_H2_6                = 14,
    SAY_UTHER_INTRO_H2_7                = 15,

    SAY_LK_INTRO_1                      = 0,
    SAY_LK_INTRO_2                      = 1,
    SAY_LK_INTRO_3                      = 2,
    SAY_LK_JAINA_INTRO_END              = 3,
    SAY_LK_SYLVANAS_INTRO_END           = 4,

    SAY_FALRIC_INTRO_1                  = 5,
    SAY_FALRIC_INTRO_2                  = 6,

    SAY_MARWYN_INTRO_1                  = 4,
};

enum Events
{
    EVENT_WALK_INTRO1   = 1,
    EVENT_WALK_INTRO2,
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
    EVENT_INTRO_LK_11,

    EVENT_INTRO_END,

    EVENT_OPEN_FROSTWORN_DOOR,
    EVENT_CLOSE_FROSTWORN_DOOR,
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

enum Spells
{
    SPELL_CAST_VISUAL                  = 65633, // Jaina/Sylavana
    SPELL_BOSS_SPAWN_AURA              = 72712, // Falric and Marwyn
    SPELL_UTHER_DESPAWN                = 70693,
    SPELL_TAKE_FROSTMOURNE             = 72729,
    SPELL_FROSTMOURNE_DESPAWN          = 72726,
    SPELL_FROSTMOURNE_VISUAL           = 73220,
    SPELL_FROSTMOURNE_SOUNDS           = 70667,
};

const Position HallsofReflectionLocs[]=
{
    {5283.234863f, 1990.946777f, 707.695679f, 0.929097f},   // 2 Loralen Follows
    {5408.031250f, 2102.918213f, 707.695251f, 0.792756f},   // 9 Sylvanas Follows
    {5401.866699f, 2110.837402f, 707.695251f, 0.800610f},   // 10 Loralen follows
};

const Position IntroPos              = {5265.89f, 1952.98f, 707.6978f, 0.0f}; // Jaina/Sylvanas Intro Start Position
const Position MoveThronePos         = {5306.952148f, 1998.499023f, 709.341431f, 1.277278f}; // Jaina/Sylvanas walks to throne
const Position UtherSpawnPos         = {5308.310059f, 2003.857178f, 709.341431f, 4.650315f};
const Position LichKingSpawnPos      = {5362.917480f, 2062.307129f, 707.695374f, 3.945812f};
const Position LichKingMoveThronePos = {5312.080566f, 2009.172119f, 709.341431f, 3.973301f}; // Lich King walks to throne
const Position LichKingMoveAwayPos   = {5400.069824f, 2102.7131689f, 707.69525f, 0.843803f}; // Lich King walks away

class npc_jaina_or_sylvanas_hor : public CreatureScript
{
    public:
        npc_jaina_or_sylvanas_hor() : CreatureScript("npc_jaina_or_sylvanas_hor") { }

    // AI of Part1
    struct npc_jaina_or_sylvanas_horAI : public ScriptedAI
    {
        npc_jaina_or_sylvanas_horAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;
        uint64 utherGUID;
        uint64 lichkingGUID;

        EventMap events;

        void sGossipSelect(Player* player, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            switch (action)
            {
                case 0:
                    player->CLOSE_GOSSIP_MENU();
                    events.ScheduleEvent(EVENT_START_INTRO, 1000);
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP|UNIT_NPC_FLAG_QUESTGIVER);
                    break;
                case 1:
                    player->CLOSE_GOSSIP_MENU();
                    events.ScheduleEvent(EVENT_SKIP_INTRO, 1000);
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP|UNIT_NPC_FLAG_QUESTGIVER);
                    break;
            }
        }

        void Reset()
        {
            events.Reset();

            utherGUID = 0;
            lichkingGUID = 0;

            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP|UNIT_NPC_FLAG_QUESTGIVER);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            events.ScheduleEvent(EVENT_WALK_INTRO1, 3000);
        }

        void UpdateAI(uint32 diff)
        {
            events.Update(diff);
            switch (events.ExecuteEvent())
            {
                case EVENT_WALK_INTRO1:
                    me->GetMotionMaster()->MovePoint(0, IntroPos);
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                    {
                        Talk(SAY_JAINA_INTRO_1);
                        events.ScheduleEvent(EVENT_WALK_INTRO2, 7000);
                    }
                    else
                    {
                        Talk(SAY_SYLVANAS_INTRO_1);
                        events.ScheduleEvent(EVENT_WALK_INTRO2, 9000);
                    }
                    break;
                case EVENT_WALK_INTRO2:
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        Talk(SAY_JAINA_INTRO_2);
                    else
                        Talk(SAY_SYLVANAS_INTRO_2);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP|UNIT_NPC_FLAG_QUESTGIVER);
                    break;
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
                    Talk(SAY_JAINA_INTRO_3);
                    events.ScheduleEvent(EVENT_INTRO_A2_2, 7000);
                    break;
                case EVENT_INTRO_A2_2:
                    Talk(SAY_JAINA_INTRO_4);
                    events.ScheduleEvent(EVENT_INTRO_A2_3, 10000);
                    break;
                case EVENT_INTRO_A2_3:
                    me->CastSpell(me, SPELL_CAST_VISUAL, false);
                    me->CastSpell(me, SPELL_FROSTMOURNE_SOUNDS, true);
                    instance->HandleGameObject(instance->GetData64(DATA_FROSTMOURNE), true);
                    events.ScheduleEvent(EVENT_INTRO_A2_4, 10000);
                    break;
                case EVENT_INTRO_A2_4:
                    if (Creature* uther = me->SummonCreature(NPC_UTHER, UtherSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        uther->GetMotionMaster()->MoveIdle();
                        utherGUID = uther->GetGUID();
                    }
                    events.ScheduleEvent(EVENT_INTRO_A2_5, 2000);
                    break;
                case EVENT_INTRO_A2_5:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_1);
                    events.ScheduleEvent(EVENT_INTRO_A2_6, 3000);
                    break;
                case EVENT_INTRO_A2_6:
                    Talk(SAY_JAINA_INTRO_5);
                    events.ScheduleEvent(EVENT_INTRO_A2_7, 7000);
                    break;
                case EVENT_INTRO_A2_7:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_2);
                    events.ScheduleEvent(EVENT_INTRO_A2_8, 7000);
                    break;
                case EVENT_INTRO_A2_8:
                    Talk(SAY_JAINA_INTRO_6);
                    events.ScheduleEvent(EVENT_INTRO_A2_9, 1200);
                    break;
                case EVENT_INTRO_A2_9:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_3);
                    events.ScheduleEvent(EVENT_INTRO_A2_10, 11000);
                    break;
                case EVENT_INTRO_A2_10:
                    Talk(SAY_JAINA_INTRO_7);
                    events.ScheduleEvent(EVENT_INTRO_A2_11, 6000);
                    break;
                case EVENT_INTRO_A2_11:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_4);
                    events.ScheduleEvent(EVENT_INTRO_A2_12, 12000);
                    break;
                case EVENT_INTRO_A2_12:
                    Talk(SAY_JAINA_INTRO_8);
                    events.ScheduleEvent(EVENT_INTRO_A2_13, 6000);
                    break;
                case EVENT_INTRO_A2_13:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_5);
                    events.ScheduleEvent(EVENT_INTRO_A2_14, 13000);
                    break;
                case EVENT_INTRO_A2_14:
                    Talk(SAY_JAINA_INTRO_9);
                    events.ScheduleEvent(EVENT_INTRO_A2_15, 12000);
                    break;
                case EVENT_INTRO_A2_15:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_6);
                    events.ScheduleEvent(EVENT_INTRO_A2_16, 25000);
                    break;
                case EVENT_INTRO_A2_16:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_7);
                    events.ScheduleEvent(EVENT_INTRO_A2_17, 6000);
                    break;
                case EVENT_INTRO_A2_17:
                    Talk(SAY_JAINA_INTRO_10);
                    events.ScheduleEvent(EVENT_INTRO_A2_18, 5000);
                    break;
                case EVENT_INTRO_A2_18:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                    {
                        uther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_8);
                    }
                    events.ScheduleEvent(EVENT_INTRO_A2_19, 12000);
                    break;
                case EVENT_INTRO_A2_19:
                    Talk(SAY_JAINA_INTRO_11);
                    events.ScheduleEvent(EVENT_INTRO_LK_1, 3000);
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
                    me->CastSpell(me, SPELL_CAST_VISUAL, false);
                    me->CastSpell(me, SPELL_FROSTMOURNE_SOUNDS, true);
                    instance->HandleGameObject(instance->GetData64(DATA_FROSTMOURNE), true);
                    events.ScheduleEvent(EVENT_INTRO_H2_4, 6000);
                    break;
                case EVENT_INTRO_H2_4:
                    // spawn UTHER during speach 2
                    if (Creature* uther = me->SummonCreature(NPC_UTHER, UtherSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        uther->GetMotionMaster()->MoveIdle();
                        utherGUID = uther->GetGUID();
                    }
                    events.ScheduleEvent(EVENT_INTRO_H2_5, 2000);
                    break;
                case EVENT_INTRO_H2_5:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_1);
                    events.ScheduleEvent(EVENT_INTRO_H2_6, 11000);
                    break;
                case EVENT_INTRO_H2_6:
                    Talk(SAY_SYLVANAS_INTRO_4);
                    events.ScheduleEvent(EVENT_INTRO_H2_7, 3000);
                    break;
                case EVENT_INTRO_H2_7:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_2);
                    events.ScheduleEvent(EVENT_INTRO_H2_8, 6000);
                    break;
                case EVENT_INTRO_H2_8:
                    Talk(SAY_SYLVANAS_INTRO_5);
                    events.ScheduleEvent(EVENT_INTRO_H2_9, 5000);
                    break;
                case EVENT_INTRO_H2_9:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_3);
                    events.ScheduleEvent(EVENT_INTRO_H2_10, 19000);
                    break;
                case EVENT_INTRO_H2_10:
                    Talk(SAY_SYLVANAS_INTRO_6);
                    events.ScheduleEvent(EVENT_INTRO_H2_11, 1500);
                    break;
                case EVENT_INTRO_H2_11:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_4);
                    events.ScheduleEvent(EVENT_INTRO_H2_12, 19500);
                    break;
                case EVENT_INTRO_H2_12:
                    Talk(SAY_SYLVANAS_INTRO_7);
                    events.ScheduleEvent(EVENT_INTRO_H2_13, 2000);
                    break;
                case EVENT_INTRO_H2_13:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                    {
                        uther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_5);
                    }
                    events.ScheduleEvent(EVENT_INTRO_H2_14, 12000);
                    break;
                case EVENT_INTRO_H2_14:
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_6);
                    events.ScheduleEvent(EVENT_INTRO_H2_15, 8000);
                    break;
                case EVENT_INTRO_H2_15:
                    Talk(SAY_SYLVANAS_INTRO_8);
                    events.ScheduleEvent(EVENT_INTRO_LK_1, 2000);
                    break;
                // Remaining Intro Events common for both faction
                case EVENT_INTRO_LK_1:
                    // Spawn LK in front of door, and make him move to the sword.
                    if (Creature* lichking = me->SummonCreature(NPC_LICH_KING_PART1, LichKingSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        lichking->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                        lichking->GetMotionMaster()->MovePoint(0, LichKingMoveThronePos);
                        //lichking->SetReactState(REACT_PASSIVE);
                        lichkingGUID = lichking->GetGUID();
                        events.ScheduleEvent(EVENT_OPEN_FROSTWORN_DOOR, 0);
                        events.ScheduleEvent(EVENT_CLOSE_FROSTWORN_DOOR, 4000);
                    }
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                    {
                        uther->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            uther->AI()->Talk(SAY_UTHER_INTRO_A2_9);
                        else
                            uther->AI()->Talk(SAY_UTHER_INTRO_H2_7);
                    }
                    events.ScheduleEvent(EVENT_INTRO_LK_2, 10000);
                    break;
                case EVENT_INTRO_LK_2:
                    if (Creature* lichking = me->GetCreature(*me, lichkingGUID))
                        lichking->AI()->Talk(SAY_LK_INTRO_1);
                    events.ScheduleEvent(EVENT_INTRO_LK_3, 1000);
                    break;
                case EVENT_INTRO_LK_3:
                    // The Lich King banishes Uther to the abyss.
                    if (Creature* uther = me->GetCreature(*me, utherGUID))
                    {
                        uther->CastSpell(uther, SPELL_UTHER_DESPAWN, true);
                        uther->DespawnOrUnsummon(5000);
                        utherGUID = 0;
                    }
                    events.ScheduleEvent(EVENT_INTRO_LK_4, 9000);
                    break;
                case EVENT_INTRO_LK_4:
                    // He steps forward and removes the runeblade from the heap of skulls.
                    if (Creature* lichking = me->GetCreature(*me, lichkingGUID))
                    {
                        if (GameObject* frostmourne = ObjectAccessor::GetGameObject(*me, instance->GetData64(DATA_FROSTMOURNE)))
                            frostmourne->SetPhaseMask(2, true);
                        lichking->CastSpell(lichking, SPELL_TAKE_FROSTMOURNE, true);
                        lichking->CastSpell(lichking, SPELL_FROSTMOURNE_VISUAL, true);
                    }
                    events.ScheduleEvent(EVENT_INTRO_LK_5, 8000);
                    break;
                case EVENT_INTRO_LK_5:
                    if (Creature* lichking = me->GetCreature(*me, lichkingGUID))
                        lichking->AI()->Talk(SAY_LK_INTRO_2);
                    events.ScheduleEvent(EVENT_INTRO_LK_6, 8000);
                    break;
                case EVENT_INTRO_LK_6:
                    // summon Falric and Marwyn. then go back to the door
                    if (Creature* falric = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_FALRIC_EVENT)))
                    {
                        falric->CastSpell(falric, SPELL_BOSS_SPAWN_AURA, true);
                        falric->SetVisible(true);
                    }
                    if (Creature* marwyn = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_MARWYN_EVENT)))
                    {
                        marwyn->CastSpell(marwyn, SPELL_BOSS_SPAWN_AURA, true);
                        marwyn->SetVisible(true);
                    }
                    if (Creature* lichking = me->GetCreature(*me, lichkingGUID))
                    {
                        lichking->AI()->Talk(SAY_LK_INTRO_3);
                        lichking->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                        lichking->GetMotionMaster()->MovePoint(0, LichKingMoveAwayPos);
                    }
                    events.ScheduleEvent(EVENT_INTRO_LK_7, 10000);
                    events.ScheduleEvent(EVENT_OPEN_FROSTWORN_DOOR, 5000);
                    break;
                case EVENT_INTRO_LK_7:
                    if (Creature* marwyn = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_MARWYN_EVENT)))
                        marwyn->AI()->Talk(SAY_MARWYN_INTRO_1);
                    events.ScheduleEvent(EVENT_INTRO_LK_8, 1000);
                    break;
                case EVENT_INTRO_LK_8:
                    if (Creature* falric = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_FALRIC_EVENT)))
                        falric->AI()->Talk(SAY_FALRIC_INTRO_1);
                    events.ScheduleEvent(EVENT_INTRO_LK_9, 5000);
                    break;
                case EVENT_INTRO_LK_9:
                    if (Creature* falric = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_FALRIC_EVENT)))
                        falric->AI()->Talk(SAY_FALRIC_INTRO_2);
                    events.ScheduleEvent(EVENT_INTRO_LK_10, 7000);
                    break;
                case EVENT_INTRO_LK_10:
                    if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        Talk(SAY_JAINA_INTRO_END);
                    else
                        Talk(SAY_SYLVANAS_INTRO_END);
                    me->GetMotionMaster()->MovePoint(0, LichKingMoveAwayPos);
                    /// @todo Loralen/Koreln shall run also
                    events.ScheduleEvent(EVENT_INTRO_LK_11, 5000);
                    break;
                case EVENT_INTRO_LK_11:
                    if (Creature* lichking = me->GetCreature(*me, lichkingGUID))
                    {
                        if (instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            lichking->AI()->Talk(SAY_LK_JAINA_INTRO_END);
                        else
                            lichking->AI()->Talk(SAY_LK_SYLVANAS_INTRO_END);
                    }
                    events.ScheduleEvent(EVENT_INTRO_END, 5000);
                    break;
                case EVENT_INTRO_END:
                    if (instance)
                    {
                        instance->SetData(DATA_INTRO_EVENT, DONE);
                        instance->ProcessEvent(0, EVENT_SPAWN_WAVES);
                    }
                    // Loralen or Koreln disappearAndDie()
                    if (Creature* lichking = me->GetCreature(*me, lichkingGUID))
                    {
                        lichking->DespawnOrUnsummon(5000);
                        lichkingGUID = 0;
                    }
                    me->DespawnOrUnsummon(10000);
                    events.ScheduleEvent(EVENT_CLOSE_FROSTWORN_DOOR, 7000);
                    break;
                case EVENT_SKIP_INTRO:
                    me->GetMotionMaster()->MovePoint(0, MoveThronePos);
                    /// @todo Loralen/Koreln shall run also
                    if (Creature* lichking = me->SummonCreature(NPC_LICH_KING_PART1, LichKingSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        lichking->SetUnitMovementFlags(MOVEMENTFLAG_WALKING);
                        lichking->GetMotionMaster()->MovePoint(0, LichKingMoveThronePos);
                        lichking->SetReactState(REACT_PASSIVE);
                        lichkingGUID = lichking->GetGUID();
                        events.ScheduleEvent(EVENT_OPEN_FROSTWORN_DOOR, 0);
                        events.ScheduleEvent(EVENT_CLOSE_FROSTWORN_DOOR, 4000);
                    }
                    events.ScheduleEvent(EVENT_INTRO_LK_4, 15000);
                    break;
                case EVENT_OPEN_FROSTWORN_DOOR:
                    if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetData64(DATA_FROSTWORN_DOOR)))
                        instance->HandleGameObject(0 ,true, gate);
                    break;
                case EVENT_CLOSE_FROSTWORN_DOOR:
                    if (GameObject* gate = ObjectAccessor::GetGameObject(*me, instance->GetData64(DATA_FROSTWORN_DOOR)))
                        instance->HandleGameObject(0 ,false, gate);
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_jaina_or_sylvanas_horAI(creature);
    }
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

struct npc_gauntlet_trash : public ScriptedAI
{
    npc_gauntlet_trash(Creature* creature) : ScriptedAI(creature),
        instance(creature->GetInstanceScript())
    {
    }

    void Reset()
    {
        me->CastSpell(me, SPELL_WELL_OF_SOULS, true);
        events.Reset();
    }

    void EnterEvadeMode()
    {
        if (instance->GetData(DATA_WAVE_COUNT) != NOT_STARTED)
            instance->SetData(DATA_WAVE_COUNT, NOT_STARTED);
    }

    void SetData(uint32 type, uint32 value)
    {
        if (type)
            return;

        InternalWaveId = value;
    }

    uint32 GetData(uint32 type) const
    {
        if (type)
            return 0;

        return InternalWaveId;
    }

protected:
    EventMap events;
    InstanceScript* instance;
    uint32 InternalWaveId;
};

class npc_ghostly_priest : public CreatureScript
{
public:
    npc_ghostly_priest() : CreatureScript("npc_ghostly_priest") { }

    struct npc_ghostly_priestAI : public npc_gauntlet_trash
    {
        npc_ghostly_priestAI(Creature* creature) : npc_gauntlet_trash(creature)
        {
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000); /// @todo adjust timers
            events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000);
            events.ScheduleEvent(EVENT_COWER_IN_FEAR, 10000);
            events.ScheduleEvent(EVENT_DARK_MENDING, 20000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_SHADOW_WORD_PAIN:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_SHADOW_WORD_PAIN);
                    events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000);
                    break;
                case EVENT_CIRCLE_OF_DESTRUCTION:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_CIRCLE_OF_DESTRUCTION);
                    events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000);
                    break;
                case EVENT_COWER_IN_FEAR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_COWER_IN_FEAR);
                    events.ScheduleEvent(EVENT_COWER_IN_FEAR, 10000);
                    break;
                case EVENT_DARK_MENDING:
                    // find an ally with missing HP
                    if (Unit* target = DoSelectLowestHpFriendly(40, DUNGEON_MODE(30000, 50000)))
                    {
                        DoCast(target, SPELL_DARK_MENDING);
                        events.ScheduleEvent(EVENT_DARK_MENDING, 20000);
                    }
                    else
                    {
                        // no friendly unit with missing hp. re-check in just 5 sec.
                        events.ScheduleEvent(EVENT_DARK_MENDING, 5000);
                    }
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ghostly_priestAI(creature);
    }
};

class npc_phantom_mage : public CreatureScript
{
public:
    npc_phantom_mage() : CreatureScript("npc_phantom_mage") { }

    struct npc_phantom_mageAI : public npc_gauntlet_trash
    {
        npc_phantom_mageAI(Creature* creature) : npc_gauntlet_trash(creature)
        {
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_FIREBALL, 3000); /// @todo adjust timers
            events.ScheduleEvent(EVENT_FLAMESTRIKE, 6000);
            events.ScheduleEvent(EVENT_FROSTBOLT, 9000);
            events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 12000);
            events.ScheduleEvent(EVENT_HALLUCINATION, 40000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_FIREBALL:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_FIREBALL);
                    events.ScheduleEvent(EVENT_FIREBALL, 15000);
                    break;
                case EVENT_FLAMESTRIKE:
                    DoCast(SPELL_FLAMESTRIKE);
                    events.ScheduleEvent(EVENT_FLAMESTRIKE, 15000);
                    break;
                case EVENT_FROSTBOLT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_FROSTBOLT);
                    events.ScheduleEvent(EVENT_FROSTBOLT, 15000);
                    break;
                case EVENT_CHAINS_OF_ICE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_CHAINS_OF_ICE);
                    events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 15000);
                    break;
                case EVENT_HALLUCINATION:
                    DoCast(SPELL_HALLUCINATION);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_phantom_mageAI(creature);
    }
};

class npc_phantom_hallucination : public CreatureScript
{
public:
    npc_phantom_hallucination() : CreatureScript("npc_phantom_hallucination") { }

    struct npc_phantom_hallucinationAI : public npc_phantom_mage::npc_phantom_mageAI
    {
        npc_phantom_hallucinationAI(Creature* creature) : npc_phantom_mage::npc_phantom_mageAI(creature) {}

        void JustDied(Unit* /*killer*/)
        {
            DoCast(SPELL_HALLUCINATION_2);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_phantom_hallucinationAI(creature);
    }
};

class npc_shadowy_mercenary : public CreatureScript
{
public:
    npc_shadowy_mercenary() : CreatureScript("npc_shadowy_mercenary") { }

    struct npc_shadowy_mercenaryAI : public npc_gauntlet_trash
    {
        npc_shadowy_mercenaryAI(Creature* creature) : npc_gauntlet_trash(creature)
        {
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHADOW_STEP, 8000); /// @todo adjust timers
            events.ScheduleEvent(EVENT_DEADLY_POISON, 5000);
            events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
            events.ScheduleEvent(EVENT_KIDNEY_SHOT, 12000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_SHADOW_STEP:
                    DoCast(SPELL_SHADOW_STEP);
                    events.ScheduleEvent(EVENT_SHADOW_STEP, 8000);
                    break;
                case EVENT_DEADLY_POISON:
                    DoCast(me->GetVictim(), SPELL_DEADLY_POISON);
                    events.ScheduleEvent(EVENT_DEADLY_POISON, 10000);
                    break;
                case EVENT_ENVENOMED_DAGGER_THROW:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_ENVENOMED_DAGGER_THROW);
                    events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
                    break;
                case EVENT_KIDNEY_SHOT:
                    DoCast(me->GetVictim(), SPELL_KIDNEY_SHOT);
                    events.ScheduleEvent(EVENT_KIDNEY_SHOT, 10000);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_shadowy_mercenaryAI(creature);
    }
};

class npc_spectral_footman : public CreatureScript
{
public:
    npc_spectral_footman() : CreatureScript("npc_spectral_footman") { }

    struct npc_spectral_footmanAI : public npc_gauntlet_trash
    {
        npc_spectral_footmanAI(Creature* creature) : npc_gauntlet_trash(creature)
        {
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000); /// @todo adjust timers
            events.ScheduleEvent(EVENT_SHIELD_BASH, 10000);
            events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_SPECTRAL_STRIKE:
                    DoCast(me->GetVictim(), SPELL_SPECTRAL_STRIKE);
                    events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000);
                    break;
                case EVENT_SHIELD_BASH:
                    DoCast(me->GetVictim(), SPELL_SHIELD_BASH);
                    events.ScheduleEvent(EVENT_SHIELD_BASH, 5000);
                    break;
                case EVENT_TORTURED_ENRAGE:
                    DoCast(SPELL_TORTURED_ENRAGE);
                    events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_spectral_footmanAI(creature);
    }
};

class npc_tortured_rifleman : public CreatureScript
{
public:
    npc_tortured_rifleman() : CreatureScript("npc_tortured_rifleman") { }

    struct npc_tortured_riflemanAI : public npc_gauntlet_trash
    {
        npc_tortured_riflemanAI(Creature* creature) : npc_gauntlet_trash(creature)
        {
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHOOT, 2000); /// @todo adjust timers
            events.ScheduleEvent(EVENT_CURSED_ARROW, 10000);
            events.ScheduleEvent(EVENT_FROST_TRAP, 1000);
            events.ScheduleEvent(EVENT_ICE_SHOT, 15000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_SHOOT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_SHOOT);
                    events.ScheduleEvent(EVENT_SHOOT, 2000);
                    break;
                case EVENT_CURSED_ARROW:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_CURSED_ARROW);
                    events.ScheduleEvent(EVENT_CURSED_ARROW, 10000);
                    break;
                case EVENT_FROST_TRAP:
                    DoCast(SPELL_FROST_TRAP);
                    events.ScheduleEvent(EVENT_FROST_TRAP, 30000);
                    break;
                case EVENT_ICE_SHOT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_ICE_SHOT);
                    events.ScheduleEvent(EVENT_ICE_SHOT, 15000);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_tortured_riflemanAI(creature);
    }
};


enum GeneralEvents
{
    //General
    EVENT_SHIELD                 = 0,
    EVENT_SPIKE                  = 1,
    EVENT_CLONE                  = 2,

    SAY_AGGRO                    = 0,
    SAY_DEATH                    = 1,

    SPELL_SHIELD_THROWN          = 69222, // 73076 on hc
    SPELL_SPIKE                  = 69184, // 70399 on hc
    SPELL_CLONE_NAME             = 57507,
    SPELL_CLONE_MODEL            = 45204,

    // Reflection
    EVENT_BALEFUL_STRIKE         = 0,

    SPELL_BALEFUL_STRIKE         = 69933, // 70400 on hc
    SPELL_SPIRIT_BURST           = 69900, // 73046 on hc
};

class npc_frostworn_general : public CreatureScript
{
public:
    npc_frostworn_general() : CreatureScript("npc_frostworn_general") { }

    struct npc_frostworn_generalAI : public ScriptedAI
    {
        npc_frostworn_generalAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            Reset();
        }

        InstanceScript* instance;

        EventMap events;

        void Reset()
        {
            events.Reset();
            instance->SetData(DATA_FROSWORN_EVENT, NOT_STARTED);
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
            instance->SetData(DATA_FROSWORN_EVENT, DONE);
        }

        void EnterCombat(Unit* /*victim*/)
        {
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_SHIELD, 5000);
            events.ScheduleEvent(EVENT_SPIKE, 14000);
            events.ScheduleEvent(EVENT_CLONE, 22000);
            instance->SetData(DATA_FROSWORN_EVENT, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_SHIELD:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_SHIELD_THROWN);
                    events.ScheduleEvent(EVENT_SHIELD, urand(8000, 12000));
                    break;
                case EVENT_SPIKE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_SPIKE);
                    events.ScheduleEvent(EVENT_SPIKE, urand(15000, 20000));
                    break;
                case EVENT_CLONE:
                    SummonClones();
                    events.ScheduleEvent(EVENT_CLONE, 60000);
                    break;
            }

            DoMeleeAttackIfReady();
        }

        void SummonClones()
        {
            std::list<Unit *> playerList;
            SelectTargetList(playerList, 5, SELECT_TARGET_TOPAGGRO, 0, true);
            for (std::list<Unit*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
            {
                Unit* temp = (*itr);
                Creature* reflection = me->SummonCreature(NPC_REFLECTION, temp->GetPositionX(), temp->GetPositionY(), temp->GetPositionZ(), temp->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
                reflection->SetName(temp->GetName());
                temp->CastSpell(reflection, SPELL_CLONE_NAME, true);
                temp->CastSpell(reflection, SPELL_CLONE_MODEL, true);
                reflection->setFaction(me->getFaction());
                reflection->AI()->AttackStart(temp);
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

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*victim*/)
        {
            events.ScheduleEvent(EVENT_BALEFUL_STRIKE, 3000);
        }

        void JustDied(Unit* killer)
        {
            DoCast(killer, SPELL_SPIRIT_BURST);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_BALEFUL_STRIKE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_BALEFUL_STRIKE);
                    events.ScheduleEvent(EVENT_BALEFUL_STRIKE, urand(3000, 8000));
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_spiritual_reflectionAI(creature);
    }
};

class at_hor_intro_start : public AreaTriggerScript
{
public:
    at_hor_intro_start() : AreaTriggerScript("at_hor_intro_start") {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/)
    {
        InstanceScript* instance = player->GetInstanceScript();

        if (player->IsGameMaster())
            return true;

        if (instance->GetData(DATA_INTRO_EVENT) == NOT_STARTED)
        {
            instance->SetData(DATA_INTRO_EVENT, IN_PROGRESS);
        }

        return true;
    }
};

class at_hor_waves_restarter : public AreaTriggerScript
{
public:
    at_hor_waves_restarter() : AreaTriggerScript("at_hor_waves_restarter") {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/)
    {
        InstanceScript* instance = player->GetInstanceScript();

        if (player->IsGameMaster())
            return true;

        if (instance->GetData(DATA_WAVE_COUNT))
            return true;

        if (instance->GetData(DATA_INTRO_EVENT) == DONE && instance->GetBossState(DATA_MARWYN_EVENT) != DONE)
        {
            instance->ProcessEvent(0, EVENT_SPAWN_WAVES);

            if (Creature* falric = player->GetCreature(*player, instance->GetData64(DATA_FALRIC_EVENT)))
            {
                falric->CastSpell(falric, SPELL_BOSS_SPAWN_AURA, true);
                falric->SetVisible(true);
            }
            if (Creature* marwyn = player->GetCreature(*player, instance->GetData64(DATA_MARWYN_EVENT)))
            {
                marwyn->CastSpell(marwyn, SPELL_BOSS_SPAWN_AURA, true);
                marwyn->SetVisible(true);
            }
        }
        return true;
    }
};

void AddSC_halls_of_reflection()
{
    new npc_jaina_or_sylvanas_hor();
    new npc_ghostly_priest();
    new npc_phantom_mage();
    new npc_phantom_hallucination();
    new npc_shadowy_mercenary();
    new npc_spectral_footman();
    new npc_tortured_rifleman();
    new at_hor_intro_start();
    new at_hor_waves_restarter();
    new npc_frostworn_general();
    new npc_spiritual_reflection();
}
