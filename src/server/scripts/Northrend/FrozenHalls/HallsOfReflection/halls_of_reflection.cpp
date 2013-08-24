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

    SAY_JAINA_ESCAPE_1                  = 0,
    SAY_JAINA_ESCAPE_2                  = 1,
    SAY_JAINA_ESCAPE_3                  = 2,
    SAY_JAINA_ESCAPE_4                  = 3,
    SAY_JAINA_ESCAPE_5                  = 4,
    SAY_JAINA_ESCAPE_6                  = 5,
    SAY_JAINA_ESCAPE_7                  = 6,
    SAY_JAINA_ESCAPE_8                  = 7,
    SAY_JAINA_ESCAPE_9                  = 8,
    SAY_JAINA_ESCAPE_10                 = 9,

    SAY_SYLVANAS_INTRO_1                = 0,
    SAY_SYLVANAS_INTRO_2                = 1,
    SAY_SYLVANAS_INTRO_3                = 2,
    SAY_SYLVANAS_INTRO_4                = 3,
    SAY_SYLVANAS_INTRO_5                = 4,
    SAY_SYLVANAS_INTRO_6                = 5,
    SAY_SYLVANAS_INTRO_7                = 6,
    SAY_SYLVANAS_INTRO_8                = 7,
    SAY_SYLVANAS_INTRO_END              = 8,

    SAY_SYLVANAS_ESCAPE_1               = 0,
    SAY_SYLVANAS_ESCAPE_2               = 1,
    SAY_SYLVANAS_ESCAPE_3               = 2,
    SAY_SYLVANAS_ESCAPE_4               = 3,
    SAY_SYLVANAS_ESCAPE_5               = 4,
    SAY_SYLVANAS_ESCAPE_6               = 5,
    SAY_SYLVANAS_ESCAPE_7               = 6,
    SAY_SYLVANAS_ESCAPE_8               = 7,
    SAY_SYLVANAS_ESCAPE_9               = 8,

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

    SAY_LK_ESCAPE_1                     = 0,
    SAY_LK_ESCAPE_2                     = 1,
    SAY_LK_ESCAPE_3                     = 2,
    SAY_LK_ESCAPE_4                     = 3,
    SAY_LK_ESCAPE_5                     = 4,
    SAY_LK_ESCAPE_6                     = 5,
    SAY_LK_ESCAPE_7                     = 6,
    SAY_LK_ESCAPE_8                     = 7,
    SAY_LK_ESCAPE_9                     = 8,
    SAY_LK_ESCAPE_10                    = 9,
    SAY_LK_ESCAPE_11                    = 10,

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

    EVENT_ESCAPE,
    EVENT_ESCAPE_1,
    EVENT_ESCAPE_2,
    EVENT_ESCAPE_3,
    EVENT_ESCAPE_4,
    EVENT_ESCAPE_5,
    EVENT_ESCAPE_6,
    EVENT_ESCAPE_7,
    EVENT_ESCAPE_8,
    EVENT_ESCAPE_9,
    EVENT_ESCAPE_10,
    EVENT_ESCAPE_11,
    EVENT_ESCAPE_12,
    EVENT_ESCAPE_13,
    EVENT_ESCAPE_14,
    EVENT_ESCAPE_15,
    EVENT_ESCAPE_16,
    EVENT_ESCAPE_17,
    EVENT_ESCAPE_18,
    EVENT_ESCAPE_19,
    EVENT_ESCAPE_20,
    EVENT_ESCAPE_21,
    EVENT_ESCAPE_22,
    EVENT_ESCAPE_23,
    EVENT_ESCAPE_24,
    EVENT_ESCAPE_25,
    EVENT_ESCAPE_26,
    EVENT_ESCAPE_27,

    EVENT_OPEN_FROSTWORN_DOOR,
    EVENT_CLOSE_FROSTWORN_DOOR,
};

enum Misc
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
    SPELL_JAINA_ICEBARRIER             = 69787, // Jaina Ice Barrier
    SPELL_JAINA_ICEPRISON              = 69708, // Jaina Ice Prison
    SPELL_SYLVANAS_CLOAKOFDARKNESS     = 70188, // Sylvanas Cloak of Darkness
    SPELL_SYLVANAS_DARKBINDING         = 70194, // Sylvanas Dark Binding
    SPELL_REMORSELESS_WINTER           = 69780, // Lich King Remorseless Winter
    SPELL_SOUL_REAPER                  = 69409, // Lich King Soul Reaper
    SPELL_FURY_OF_FROSTMOURNE          = 70063, // Lich King Fury of FrostMourne
    SPELL_JAINA_DESTROY_ICE_WALL       = 69784, // Jaina
    SPELL_SYLVANAS_DESTROY_ICE_WALL    = 70225, // Sylvanas
    SPELL_SYLVANAS_JUMP                = 68339, // Sylvanas Jump
    SPELL_RAISE_DEAD                   = 69818,
    SPELL_HARVEST_SOUL                 = 70070,
    SPELL_SUMMON_RISE_WITCH_DOCTOR     = 69836,
    SPELL_SUMMON_LUMBERING_ABOMINATION = 69835,
    SPELL_SUMMON_ICE_WALL              = 69768, // Visual effect and icewall summoning

    //Raging gnoul
    SPELL_EMERGE_VISUAL                = 50142,
    SPELL_GHOUL_JUMP                   = 70150,

    //Witch Doctor
    SPELL_COURSE_OF_DOOM               = 70144,
    SPELL_SHADOW_BOLT_VOLLEY           = 70145,
    SPELL_SHADOW_BOLT                  = 70080,

    //Lumbering Abomination
    SPELL_ABON_STRIKE                  = 40505,
    SPELL_VOMIT_SPRAY                  = 70176,
};

const Position HallsofReflectionLocs[] =
{
    {5283.234863f, 1990.946777f, 707.695679f, 0.929097f},   // 2 Loralen Follows
    {5408.031250f, 2102.918213f, 707.695251f, 0.792756f},   // 9 Sylvanas Follows
    {5401.866699f, 2110.837402f, 707.695251f, 0.800610f},   // 10 Loralen follows
};

const Position NpcJainaOrSylvanasEscapeRoute[] =
{
    {5601.217285f, 2207.652832f, 731.541931f, 5.223304f}, // leave the throne room
    {5607.224375f, 2173.913330f, 731.126038f, 2.608723f}, // adjust route
    {5583.427246f, 2138.784180f, 731.150391f, 4.260901f}, // stop for talking
    {5560.281738f, 2104.025635f, 731.410889f, 4.058383f}, // attack the first icewall
    {5510.990723f, 2000.772217f, 734.716064f, 3.973213f}, // attack the second icewall
    {5452.641113f, 1905.762329f, 746.530579f, 4.118834f}, // attack the third icewall
    {5338.126953f, 1768.429810f, 767.237244f, 3.855189f}, // attack the fourth icewall
    {5257.712402f, 1669.379395f, 784.300110f, 0.908373f}, // face the Lich king
    {5261.191895f, 1681.901611f, 784.285278f, 4.410465f}, // final position
};

const Position IceWalls[] =
{
    {5547.833f, 2083.701f,731.4332f,4.24115f}, // first icewall
    {5503.213f, 1969.547f,737.0245f,4.293779f},// second icewall
    {5439.976f, 1879.005f,752.7048f,4.207591f},// third icewall
    {5318.289f, 1749.184f,771.9423f,4.054276f},// fourth icewall
};

const Position IntroPos                 = {5265.89f, 1952.98f, 707.6978f, 0.0f};                // Jaina/Sylvanas Intro Start Position
const Position MoveThronePos            = {5306.952148f, 1998.499023f, 709.341431f, 1.277278f}; // Jaina/Sylvanas walks to throne
const Position UtherSpawnPos            = {5308.310059f, 2003.857178f, 709.341431f, 4.650315f};
const Position LichKingSpawnPos         = {5362.917480f, 2062.307129f, 707.695374f, 3.945812f};
const Position LichKingMoveThronePos    = {5312.080566f, 2009.172119f, 709.341431f, 3.973301f}; // Lich King walks to throne
const Position LichKingMoveAwayPos      = {5400.069824f, 2102.7131689f, 707.69525f, 0.843803f}; // Lich King walks away
const Position LichKingSpawnPos2        = {5552.733398f, 2262.718506f, 733.011047f, 4.009696f}; // Lich King Spawn Position 2
const Position LichKingFirstSummon      = {5600.076172f, 2192.270996f, 731.750488f, 4.330935f}; // Lich King First summons
const Position JainaShadowThroneDoor    = {5577.243f, 2235.852f, 733.0128f, 2.209562f};         // Jaina Spawn Position 2
const Position SylvanasShadowThroneDoor = {5577.243f, 2235.852f, 733.0128f, 2.209562f};         // Sylvanas Spawn Position 2
const Position FalricStartPos           = {5283.878906f, 2030.459595f, 709.319641f, 5.506670f}; // Falric start position
const Position MarwynStartPos           = {5334.979980f, 1982.399536f, 709.320129f, 2.347014f}; // Marwyn start position
const Position LichKingFinalPos         = {5283.742188f, 1706.335693f, 783.293518f, 4.138510f}; // Lich King Final Pos
const Position ChestPos                 = {5246.187500f, 1649.079468f, 784.301758f, 0.901268f}; // Chest position
const Position FinalPortalPos           = {5270.634277f ,1639.101196f, 784.303040f, 1.682743f}; // Final portal position

class npc_jaina_or_sylvanas_hor : public CreatureScript
{
    public:
        npc_jaina_or_sylvanas_hor() : CreatureScript("npc_jaina_or_sylvanas_hor") { }

    // AI of Part1
    struct npc_jaina_or_sylvanas_horAI : public ScriptedAI
    {
        npc_jaina_or_sylvanas_horAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = me->GetInstanceScript();
        }

        InstanceScript* _instance;
        uint64 _utherGUID;
        uint64 _lichkingGUID;

        EventMap _events;

        void sGossipSelect(Player* player, uint32 /*sender*/, uint32 action) OVERRIDE
        {
            player->PlayerTalkClass->ClearMenus();
            switch (action)
            {
                case 0:
                    player->CLOSE_GOSSIP_MENU();
                    _events.ScheduleEvent(EVENT_START_INTRO, 1000);
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP|UNIT_NPC_FLAG_QUESTGIVER);
                    break;
                case 1:
                    player->CLOSE_GOSSIP_MENU();
                    _events.ScheduleEvent(EVENT_SKIP_INTRO, 1000);
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP|UNIT_NPC_FLAG_QUESTGIVER);
                    break;
            }
        }

        void Reset() OVERRIDE
        {
            _events.Reset();

            _utherGUID = 0;
            _lichkingGUID = 0;

            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP|UNIT_NPC_FLAG_QUESTGIVER);
            me->SetStandState(UNIT_STAND_STATE_STAND);
            _events.ScheduleEvent(EVENT_WALK_INTRO1, 3000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            _events.Update(diff);
            switch (_events.ExecuteEvent())
            {
                case EVENT_WALK_INTRO1:
                    me->GetMotionMaster()->MovePoint(0, IntroPos);
                    if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                    {
                        Talk(SAY_JAINA_INTRO_1);
                        _events.ScheduleEvent(EVENT_WALK_INTRO2, 7000);
                    }
                    else
                    {
                        Talk(SAY_SYLVANAS_INTRO_1);
                        _events.ScheduleEvent(EVENT_WALK_INTRO2, 9000);
                    }
                    break;
                case EVENT_WALK_INTRO2:
                    if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        Talk(SAY_JAINA_INTRO_2);
                    else
                        Talk(SAY_SYLVANAS_INTRO_2);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP|UNIT_NPC_FLAG_QUESTGIVER);
                    break;
                case EVENT_START_INTRO:
                    me->GetMotionMaster()->MovePoint(0, MoveThronePos);
                    // Begining of intro is differents between fActions as the speech sequence and timers are differents.
                    if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        _events.ScheduleEvent(EVENT_INTRO_A2_1, 0);
                    else
                        _events.ScheduleEvent(EVENT_INTRO_H2_1, 0);
                    break;
                // A2 Intro Events
                case EVENT_INTRO_A2_1:
                    Talk(SAY_JAINA_INTRO_3);
                    _events.ScheduleEvent(EVENT_INTRO_A2_2, 7000);
                    break;
                case EVENT_INTRO_A2_2:
                    Talk(SAY_JAINA_INTRO_4);
                    _events.ScheduleEvent(EVENT_INTRO_A2_3, 10000);
                    break;
                case EVENT_INTRO_A2_3:
                    me->CastSpell(me, SPELL_CAST_VISUAL, false);
                    me->CastSpell(me, SPELL_FROSTMOURNE_SOUNDS, true);
                    _instance->HandleGameObject(_instance->GetData64(DATA_FROSTMOURNE), true);
                    _events.ScheduleEvent(EVENT_INTRO_A2_4, 10000);
                    break;
                case EVENT_INTRO_A2_4:
                    if (Creature* uther = me->SummonCreature(NPC_UTHER, UtherSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        uther->GetMotionMaster()->MoveIdle();
                        _utherGUID = uther->GetGUID();
                    }
                    _events.ScheduleEvent(EVENT_INTRO_A2_5, 2000);
                    break;
                case EVENT_INTRO_A2_5:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_1);
                    _events.ScheduleEvent(EVENT_INTRO_A2_6, 3000);
                    break;
                case EVENT_INTRO_A2_6:
                    Talk(SAY_JAINA_INTRO_5);
                    _events.ScheduleEvent(EVENT_INTRO_A2_7, 7000);
                    break;
                case EVENT_INTRO_A2_7:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_2);
                    _events.ScheduleEvent(EVENT_INTRO_A2_8, 7000);
                    break;
                case EVENT_INTRO_A2_8:
                    Talk(SAY_JAINA_INTRO_6);
                    _events.ScheduleEvent(EVENT_INTRO_A2_9, 1200);
                    break;
                case EVENT_INTRO_A2_9:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_3);
                    _events.ScheduleEvent(EVENT_INTRO_A2_10, 11000);
                    break;
                case EVENT_INTRO_A2_10:
                    Talk(SAY_JAINA_INTRO_7);
                    _events.ScheduleEvent(EVENT_INTRO_A2_11, 6000);
                    break;
                case EVENT_INTRO_A2_11:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_4);
                    _events.ScheduleEvent(EVENT_INTRO_A2_12, 12000);
                    break;
                case EVENT_INTRO_A2_12:
                    Talk(SAY_JAINA_INTRO_8);
                    _events.ScheduleEvent(EVENT_INTRO_A2_13, 6000);
                    break;
                case EVENT_INTRO_A2_13:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_5);
                    _events.ScheduleEvent(EVENT_INTRO_A2_14, 13000);
                    break;
                case EVENT_INTRO_A2_14:
                    Talk(SAY_JAINA_INTRO_9);
                    _events.ScheduleEvent(EVENT_INTRO_A2_15, 12000);
                    break;
                case EVENT_INTRO_A2_15:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_6);
                    _events.ScheduleEvent(EVENT_INTRO_A2_16, 25000);
                    break;
                case EVENT_INTRO_A2_16:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_7);
                    _events.ScheduleEvent(EVENT_INTRO_A2_17, 6000);
                    break;
                case EVENT_INTRO_A2_17:
                    Talk(SAY_JAINA_INTRO_10);
                    _events.ScheduleEvent(EVENT_INTRO_A2_18, 5000);
                    break;
                case EVENT_INTRO_A2_18:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                    {
                        uther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                        uther->AI()->Talk(SAY_UTHER_INTRO_A2_8);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_A2_19, 12000);
                    break;
                case EVENT_INTRO_A2_19:
                    Talk(SAY_JAINA_INTRO_11);
                    _events.ScheduleEvent(EVENT_INTRO_LK_1, 3000);
                    break;
                // H2 Intro Events
                case EVENT_INTRO_H2_1:
                    Talk(SAY_SYLVANAS_INTRO_1);
                    _events.ScheduleEvent(EVENT_INTRO_H2_2, 8000);
                    break;
                case EVENT_INTRO_H2_2:
                    Talk(SAY_SYLVANAS_INTRO_2);
                    _events.ScheduleEvent(EVENT_INTRO_H2_3, 6000);
                    break;
                case EVENT_INTRO_H2_3:
                    Talk(SAY_SYLVANAS_INTRO_3);
                    me->CastSpell(me, SPELL_CAST_VISUAL, false);
                    me->CastSpell(me, SPELL_FROSTMOURNE_SOUNDS, true);
                    _instance->HandleGameObject(_instance->GetData64(DATA_FROSTMOURNE), true);
                    _events.ScheduleEvent(EVENT_INTRO_H2_4, 6000);
                    break;
                case EVENT_INTRO_H2_4:
                    // spawn UTHER during speach 2
                    if (Creature* uther = me->SummonCreature(NPC_UTHER, UtherSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        uther->GetMotionMaster()->MoveIdle();
                        _utherGUID = uther->GetGUID();
                    }
                    _events.ScheduleEvent(EVENT_INTRO_H2_5, 2000);
                    break;
                case EVENT_INTRO_H2_5:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_1);
                    _events.ScheduleEvent(EVENT_INTRO_H2_6, 11000);
                    break;
                case EVENT_INTRO_H2_6:
                    Talk(SAY_SYLVANAS_INTRO_4);
                    _events.ScheduleEvent(EVENT_INTRO_H2_7, 3000);
                    break;
                case EVENT_INTRO_H2_7:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_2);
                    _events.ScheduleEvent(EVENT_INTRO_H2_8, 6000);
                    break;
                case EVENT_INTRO_H2_8:
                    Talk(SAY_SYLVANAS_INTRO_5);
                    _events.ScheduleEvent(EVENT_INTRO_H2_9, 5000);
                    break;
                case EVENT_INTRO_H2_9:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_3);
                    _events.ScheduleEvent(EVENT_INTRO_H2_10, 19000);
                    break;
                case EVENT_INTRO_H2_10:
                    Talk(SAY_SYLVANAS_INTRO_6);
                    _events.ScheduleEvent(EVENT_INTRO_H2_11, 1500);
                    break;
                case EVENT_INTRO_H2_11:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_4);
                    _events.ScheduleEvent(EVENT_INTRO_H2_12, 19500);
                    break;
                case EVENT_INTRO_H2_12:
                    Talk(SAY_SYLVANAS_INTRO_7);
                    _events.ScheduleEvent(EVENT_INTRO_H2_13, 2000);
                    break;
                case EVENT_INTRO_H2_13:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                    {
                        uther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_5);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_H2_14, 12000);
                    break;
                case EVENT_INTRO_H2_14:
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                        uther->AI()->Talk(SAY_UTHER_INTRO_H2_6);
                    _events.ScheduleEvent(EVENT_INTRO_H2_15, 8000);
                    break;
                case EVENT_INTRO_H2_15:
                    Talk(SAY_SYLVANAS_INTRO_8);
                    _events.ScheduleEvent(EVENT_INTRO_LK_1, 2000);
                    break;
                // Remaining Intro Events common for both faction
                case EVENT_INTRO_LK_1:
                    // Spawn LK in front of door, and make him move to the sword.
                    if (Creature* lichking = me->SummonCreature(NPC_LICH_KING_PART1, LichKingSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        lichking->SetWalk(true);
                        lichking->GetMotionMaster()->MovePoint(0, LichKingMoveThronePos);
                        _lichkingGUID = lichking->GetGUID();
                        _events.ScheduleEvent(EVENT_OPEN_FROSTWORN_DOOR, 0);
                        _events.ScheduleEvent(EVENT_CLOSE_FROSTWORN_DOOR, 4000);
                    }
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                    {
                        uther->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_COWER);
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            uther->AI()->Talk(SAY_UTHER_INTRO_A2_9);
                        else
                            uther->AI()->Talk(SAY_UTHER_INTRO_H2_7);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_LK_2, 10000);
                    break;
                case EVENT_INTRO_LK_2:
                    if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        lichking->AI()->Talk(SAY_LK_INTRO_1);
                    _events.ScheduleEvent(EVENT_INTRO_LK_3, 1000);
                    break;
                case EVENT_INTRO_LK_3:
                    // The Lich King banishes Uther to the abyss.
                    if (Creature* uther = me->GetCreature(*me, _utherGUID))
                    {
                        uther->CastSpell(uther, SPELL_UTHER_DESPAWN, true);
                        uther->DespawnOrUnsummon(5000);
                        _utherGUID = 0;
                    }
                    _events.ScheduleEvent(EVENT_INTRO_LK_4, 9000);
                    break;
                case EVENT_INTRO_LK_4:
                    // He steps forward and removes the runeblade from the heap of skulls.
                    if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                    {
                        if (GameObject* frostmourne = ObjectAccessor::GetGameObject(*me, _instance->GetData64(DATA_FROSTMOURNE)))
                            frostmourne->SetPhaseMask(2, true);
                        lichking->CastSpell(lichking, SPELL_TAKE_FROSTMOURNE, true);
                        lichking->CastSpell(lichking, SPELL_FROSTMOURNE_VISUAL, true);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_LK_5, 8000);
                    break;
                case EVENT_INTRO_LK_5:
                    if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        lichking->AI()->Talk(SAY_LK_INTRO_2);
                    _events.ScheduleEvent(EVENT_INTRO_LK_6, 10000);
                    break;
                case EVENT_INTRO_LK_6:
                    // summon Falric and Marwyn. then go back to the door
                    if (Creature* falric = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_FALRIC_EVENT)))
                    {
                        falric->CastSpell(falric, SPELL_BOSS_SPAWN_AURA, true);
                        falric->SetVisible(true);
                    }
                    if (Creature* marwyn = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_MARWYN_EVENT)))
                    {
                        marwyn->CastSpell(marwyn, SPELL_BOSS_SPAWN_AURA, true);
                        marwyn->SetVisible(true);
                    }
                    if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                    {
                        lichking->AI()->Talk(SAY_LK_INTRO_3);
                        lichking->SetWalk(true);
                        lichking->GetMotionMaster()->MovePoint(0, LichKingMoveAwayPos);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_LK_7, 10000);
                    _events.ScheduleEvent(EVENT_OPEN_FROSTWORN_DOOR, 5000);
                    break;
                case EVENT_INTRO_LK_7:
                    if (Creature* marwyn = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_MARWYN_EVENT)))
                    {
                        marwyn->AI()->Talk(SAY_MARWYN_INTRO_1);
                        marwyn->SetWalk(true);
                        marwyn->GetMotionMaster()->MovePoint(0, MarwynStartPos);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_LK_8, 1000);
                    break;
                case EVENT_INTRO_LK_8:
                    if (Creature* falric = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_FALRIC_EVENT)))
                    {
                        falric->AI()->Talk(SAY_FALRIC_INTRO_1);
                        falric->SetWalk(true);
                        falric->GetMotionMaster()->MovePoint(0, FalricStartPos);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_LK_9, 5000);
                    break;
                case EVENT_INTRO_LK_9:
                    if (Creature* falric = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_FALRIC_EVENT)))
                        falric->AI()->Talk(SAY_FALRIC_INTRO_2);
                    _instance->ProcessEvent(0, EVENT_SPAWN_WAVES);
                    _events.ScheduleEvent(EVENT_INTRO_LK_10, 4000);
                    break;
                case EVENT_INTRO_LK_10:
                    if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        Talk(SAY_JAINA_INTRO_END);
                    else
                        Talk(SAY_SYLVANAS_INTRO_END);
                    me->GetMotionMaster()->MovePoint(0, LichKingMoveAwayPos);
                    /// @todo Loralen/Koreln shall run also
                    _events.ScheduleEvent(EVENT_INTRO_LK_11, 5000);
                    break;
                case EVENT_INTRO_LK_11:
                    if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                    {
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            lichking->AI()->Talk(SAY_LK_JAINA_INTRO_END);
                        else
                            lichking->AI()->Talk(SAY_LK_SYLVANAS_INTRO_END);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_END, 5000);
                    break;
                case EVENT_INTRO_END:
                    if (_instance)
                        _instance->SetData(DATA_INTRO_EVENT, DONE);
                    // Loralen or Koreln disappearAndDie()
                    if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                    {
                        lichking->DespawnOrUnsummon(5000);
                        _lichkingGUID = 0;
                    }
                    me->DespawnOrUnsummon(10000);
                    _events.ScheduleEvent(EVENT_CLOSE_FROSTWORN_DOOR, 7000);
                    break;
                case EVENT_SKIP_INTRO:
                    me->GetMotionMaster()->MovePoint(0, MoveThronePos);
                    /// @todo Loralen/Koreln shall run also
                    if (Creature* lichking = me->SummonCreature(NPC_LICH_KING_PART1, LichKingSpawnPos, TEMPSUMMON_MANUAL_DESPAWN))
                    {
                        lichking->SetWalk(true);
                        lichking->GetMotionMaster()->MovePoint(0, LichKingMoveThronePos);
                        lichking->SetReactState(REACT_PASSIVE);
                        _lichkingGUID = lichking->GetGUID();
                        _events.ScheduleEvent(EVENT_OPEN_FROSTWORN_DOOR, 0);
                        _events.ScheduleEvent(EVENT_CLOSE_FROSTWORN_DOOR, 4000);
                    }
                    _events.ScheduleEvent(EVENT_INTRO_LK_4, 15000);
                    break;
                case EVENT_OPEN_FROSTWORN_DOOR:
                    if (GameObject* gate = ObjectAccessor::GetGameObject(*me, _instance->GetData64(DATA_FROSTWORN_DOOR)))
                        _instance->HandleGameObject(0, true, gate);
                    break;
                case EVENT_CLOSE_FROSTWORN_DOOR:
                    if (GameObject* gate = ObjectAccessor::GetGameObject(*me, _instance->GetData64(DATA_FROSTWORN_DOOR)))
                        _instance->HandleGameObject(0, false, gate);
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_jaina_or_sylvanas_horAI(creature);
    }
};

class npc_jaina_or_sylvanas_escape_hor : public CreatureScript
{
    public:
        npc_jaina_or_sylvanas_escape_hor() : CreatureScript("npc_jaina_or_sylvanas_escape_hor") { }

    // AI of Part2
    struct npc_jaina_or_sylvanas_escape_horAI : public ScriptedAI
    {
        npc_jaina_or_sylvanas_escape_horAI(Creature* creature) : ScriptedAI(creature),
            _instance(creature->GetInstanceScript()), _lichkingGUID(0), _walltargetGUID(0),
            _icewallGUID(0), _icewall(0), _isattackingwall(0)
        {
            _instance = me->GetInstanceScript();
        }

        InstanceScript* _instance;
        uint64 _lichkingGUID;
        uint64 _walltargetGUID; // dummy
        uint64 _icewallGUID; // object
        uint32 _icewall; // icewall number
        uint32 _isattackingwall; //sylvannas attacking icewall

        EventMap _events;


        void Reset() OVERRIDE
        {
            _events.Reset();
            if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                lichking->DespawnOrUnsummon(1);
            _lichkingGUID = 0;
            _walltargetGUID = 0;
            _icewallGUID = 0;
            _icewall = 0;
            _isattackingwall = false;
            _events.ScheduleEvent(EVENT_ESCAPE, 0);
        }

        void JustDied(Unit* /*Killer*/) OVERRIDE
        {
            if (_instance)
            _instance->SetData(DATA_ESCAPE_EVENT, FAIL);
        }

        void DoAction(int32 actionID) OVERRIDE
        {
            switch (actionID)
            {
                case ACTION_START_ESCAPING:  // called by InstanceScript when we need to start the escaping event
                    _events.ScheduleEvent(EVENT_ESCAPE_1, 1000);
                    break;
                case ACTION_WALL_BROKEN:
                    _icewall++;
                    if (_icewall != 4)
                        _events.ScheduleEvent(EVENT_ESCAPE_17,3000);
                    else
                        _events.ScheduleEvent(EVENT_ESCAPE_23,3000);
                    _isattackingwall = false;
                    break;
            }
        }

        void sGossipSelect(Player* player, uint32 /*sender*/, uint32 action) OVERRIDE
        {
            player->PlayerTalkClass->ClearMenus();
            switch (action)
            {
                case 0:
                    player->CLOSE_GOSSIP_MENU();
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP|UNIT_NPC_FLAG_QUESTGIVER);
                    _events.ScheduleEvent(EVENT_ESCAPE_7, 0);
                    break;
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            _events.Update(diff);

            while (uint32 event = _events.ExecuteEvent())
            {
                switch (event)
                {
                    case EVENT_ESCAPE:
                        if (Creature* lichking = me->SummonCreature(NPC_LICH_KING_PART2, LichKingSpawnPos2, TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            me->Attack(lichking,true);
                            lichking->Attack(me,true);
                            me->SetReactState(REACT_PASSIVE);
                            lichking->SetReactState(REACT_PASSIVE);
                            _lichkingGUID = lichking->GetGUID();
                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                me->AI()->DoCast(me, SPELL_JAINA_ICEBARRIER);
                            else
                                me->AI()->DoCast(me, SPELL_SYLVANAS_CLOAKOFDARKNESS);
                        }
                        me->SetHealth(252000);
                        break;
                    case EVENT_ESCAPE_1:
                        _instance->SetData(DATA_ESCAPE_EVENT, IN_PROGRESS);
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                lichking->AI()->Talk(SAY_LK_ESCAPE_1);
                            else
                                lichking->AI()->Talk(SAY_LK_ESCAPE_2);
                            _events.ScheduleEvent(EVENT_ESCAPE_2, 8000);
                        }
                        break;
                    case EVENT_ESCAPE_2:
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            me->AI()->DoCast(me,SPELL_CAST_VISUAL,true);
                        else
                            me->AI()->DoCast(me,SPELL_SYLVANAS_JUMP,true);
                        _events.ScheduleEvent(EVENT_ESCAPE_3, 1000);
                        break;
                    case EVENT_ESCAPE_3:
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                lichking->AI()->DoCast(lichking, SPELL_JAINA_ICEPRISON, true);
                            else
                                lichking->AI()->DoCast(lichking, SPELL_SYLVANAS_DARKBINDING, true);
                        }
                        _events.ScheduleEvent(EVENT_ESCAPE_4, 2000);
                        break;
                    case EVENT_ESCAPE_4:
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            me->AI()->Talk(SAY_JAINA_ESCAPE_1);
                        else
                            me->AI()->Talk(SAY_SYLVANAS_ESCAPE_1);
                        _events.ScheduleEvent(EVENT_ESCAPE_5, 2000);
                        break;
                    case EVENT_ESCAPE_5:
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                            lichking->CombatStop();
                        me->GetMotionMaster()->MovePoint(0, JainaShadowThroneDoor);
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            me->RemoveAurasDueToSpell(SPELL_JAINA_ICEBARRIER);
                        else
                            me->RemoveAurasDueToSpell(SPELL_SYLVANAS_CLOAKOFDARKNESS);
                        _events.ScheduleEvent(EVENT_ESCAPE_6, 5000);
                        break;
                    case EVENT_ESCAPE_6:
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP|UNIT_NPC_FLAG_QUESTGIVER);
                        break;
                    case EVENT_ESCAPE_7:
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                lichking->RemoveAurasDueToSpell(SPELL_JAINA_ICEPRISON);
                            else
                                lichking->RemoveAurasDueToSpell(SPELL_SYLVANAS_DARKBINDING);
                        }
                        _events.ScheduleEvent(EVENT_ESCAPE_8, 1000);
                        break;
                    case EVENT_ESCAPE_8:
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                            lichking->HandleEmoteCommand(TEXT_EMOTE_ROAR);
                        me->GetMotionMaster()->MovePoint(0, NpcJainaOrSylvanasEscapeRoute[0]);
                        _events.ScheduleEvent(EVENT_ESCAPE_9, 3000);
                        break;
                    case EVENT_ESCAPE_9:
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                            lichking->GetMotionMaster()->MovePoint(0, NpcJainaOrSylvanasEscapeRoute[0]);
                        _events.ScheduleEvent(EVENT_ESCAPE_10, 1000);
                        break;
                    case EVENT_ESCAPE_10:
                        me->GetMotionMaster()->MovePoint(0, NpcJainaOrSylvanasEscapeRoute[1]);
                        _events.ScheduleEvent(EVENT_ESCAPE_11, 5000);
                        break;
                    case EVENT_ESCAPE_11:
                        me->GetMotionMaster()->MovePoint(0, NpcJainaOrSylvanasEscapeRoute[2]);
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                            lichking->GetMotionMaster()->MovePoint(0, LichKingFirstSummon);
                        _events.ScheduleEvent(EVENT_ESCAPE_12, 6000);
                        break;
                    case EVENT_ESCAPE_12:
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            lichking->AI()->Talk(SAY_LK_ESCAPE_3);
                            lichking->AI()->DoCast(me, SPELL_RAISE_DEAD);
                            lichking->Attack(me,true);
                        }
                        _events.ScheduleEvent(EVENT_ESCAPE_13, 4000);
                        break;
                    case EVENT_ESCAPE_13:
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            lichking->AI()->DoCast(lichking, SPELL_REMORSELESS_WINTER, true);
                            lichking->AI()->DoCast(lichking, SPELL_SUMMON_RISE_WITCH_DOCTOR);
                            lichking->GetMotionMaster()->MoveIdle();
                            lichking->GetMotionMaster()->MoveChase(me);
                        }
                        if (Creature* walltarget = me->SummonCreature(NPC_ICE_WALL,IceWalls[0].GetPositionX(), IceWalls[0].GetPositionY(), IceWalls[0].GetPositionZ(), IceWalls[0].GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 720000))
                        {
                            _walltargetGUID = walltarget->GetGUID();
                            walltarget->AI()->DoCast(walltarget, SPELL_SUMMON_ICE_WALL);
                            walltarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            me->Attack(walltarget,false);
                        }
                         me->GetMotionMaster()->MovePoint(0, NpcJainaOrSylvanasEscapeRoute[3]);
                        _events.ScheduleEvent(EVENT_ESCAPE_14, 8000);
                        break;
                    case EVENT_ESCAPE_14:
                        if (Creature* walltarget = me->GetCreature(*me, _walltargetGUID))
                        {
                            if (GameObject* icewall = walltarget->FindNearestGameObject(GO_ICE_WALL, 50.00f))
                            {
                                _icewallGUID = icewall->GetGUID();
                                icewall->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                                _instance->HandleGameObject(0, false, icewall);
                                if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                    me->AI()->Talk(SAY_JAINA_ESCAPE_2);
                                else
                                    me->AI()->Talk(SAY_SYLVANAS_ESCAPE_2);
                            }
                        }
                        _events.ScheduleEvent(EVENT_ESCAPE_15, 1000);
                        break;
                    case EVENT_ESCAPE_15:
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            lichking->GetMotionMaster()->MoveIdle();
                            lichking->GetMotionMaster()->MoveChase(me);
                            lichking->SetReactState(REACT_PASSIVE);
                        }
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            me->AI()->DoCast(me, SPELL_JAINA_DESTROY_ICE_WALL, false);
                        else
                        {
                            _isattackingwall = true;
                            me->AI()->DoCast(me, SPELL_SYLVANAS_DESTROY_ICE_WALL, false);
                            _events.ScheduleEvent(EVENT_ESCAPE_16, 1000);
                        }
                        break;
                    case EVENT_ESCAPE_16:
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                        {
                            me->AI()->DoCast(me, SPELL_SYLVANAS_DESTROY_ICE_WALL, false);
                            if (_isattackingwall)
                                _events.ScheduleEvent(EVENT_ESCAPE_16, 1000);
                        }
                        break;
                    case EVENT_ESCAPE_17:// ICEWALL BROKEN
                        me->GetMotionMaster()->MoveIdle();
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            lichking->StopMoving();
                            lichking->AI()->Talk(SAY_LK_ESCAPE_3);
                            lichking->AI()->DoCast(me, SPELL_RAISE_DEAD);
                        }
                        if (Creature* walltarget = me->GetCreature(*me, _walltargetGUID))
                            walltarget->DespawnOrUnsummon(0);
                        if (GameObject* icewall = ObjectAccessor::GetGameObject(*me, _icewallGUID))
                        {
                            _instance->HandleGameObject(0 ,true, icewall);
                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                me->RemoveAurasDueToSpell(SPELL_JAINA_DESTROY_ICE_WALL);
                            else
                                me->RemoveAurasDueToSpell(SPELL_SYLVANAS_DESTROY_ICE_WALL);
                        }
                        if (_icewall && _icewall < 4)
                            me->GetMotionMaster()->MovePoint(0, NpcJainaOrSylvanasEscapeRoute[_icewall + 3]);
                        _events.ScheduleEvent(EVENT_ESCAPE_18, 2000);
                        break;
                    case EVENT_ESCAPE_18:
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            lichking->GetMotionMaster()->MoveIdle();
                            lichking->GetMotionMaster()->MoveChase(me);
                        }
                        _events.ScheduleEvent(EVENT_ESCAPE_19, 6000);
                        break;
                    case EVENT_ESCAPE_19:
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            if (_icewall && _icewall < 4)
                                lichking->AI()->DoCast(lichking, SPELL_SUMMON_RISE_WITCH_DOCTOR);
                            lichking->GetMotionMaster()->MoveIdle();
                            lichking->GetMotionMaster()->MoveChase(me);
                            lichking->SetReactState(REACT_PASSIVE);
                            lichking->Attack(me,true);
                        }
                        if (Creature* walltarget = me->SummonCreature(NPC_ICE_WALL, IceWalls[_icewall].GetPositionX(), IceWalls[_icewall].GetPositionY(), IceWalls[_icewall].GetPositionZ(), IceWalls[_icewall].GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN, 720000))
                        {
                            _walltargetGUID = walltarget->GetGUID();
                            walltarget->AI()->DoCast(walltarget, SPELL_SUMMON_ICE_WALL);
                            walltarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            me->Attack(walltarget,false);
                        }
                        _events.ScheduleEvent(EVENT_ESCAPE_20, 3000);
                        break;
                    case EVENT_ESCAPE_20:
                        if (Creature* walltarget = me->GetCreature(*me, _walltargetGUID))
                        {
                            if (GameObject* icewall = walltarget->FindNearestGameObject(GO_ICE_WALL, 50.00f))
                            {
                                _icewallGUID = icewall->GetGUID();
                                _instance->HandleGameObject(0, false, icewall);
                                icewall->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_INTERACT_COND);
                                if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                {
                                    if (_icewall == 1)
                                        me->AI()->Talk(SAY_JAINA_ESCAPE_3);
                                    else if (_icewall == 2)
                                        me->AI()->Talk(SAY_JAINA_ESCAPE_4);
                                    else if (_icewall == 3)
                                        me->AI()->Talk(SAY_JAINA_ESCAPE_5);
                                }
                                else if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                {
                                    if (_icewall == 1)
                                        me->AI()->Talk(SAY_SYLVANAS_ESCAPE_3);
                                    else if (_icewall == 2)
                                        me->AI()->Talk(SAY_SYLVANAS_ESCAPE_4);
                                    else if (_icewall == 3)
                                        me->AI()->Talk(SAY_SYLVANAS_ESCAPE_5);
                                }
                            }
                        }
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            if (_icewall && _icewall < 3)
                                lichking->AI()->DoCast(lichking, SPELL_SUMMON_RISE_WITCH_DOCTOR);
                            else
                                lichking->AI()->DoCast(lichking, SPELL_SUMMON_LUMBERING_ABOMINATION);
                        }
                        if (_icewall == 3)
                            _events.ScheduleEvent(EVENT_ESCAPE_21, 16000); // last wall, really far
                        else
                            _events.ScheduleEvent(EVENT_ESCAPE_21, 9000);
                        break;
                    case EVENT_ESCAPE_21:
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            me->AI()->DoCast(me, SPELL_JAINA_DESTROY_ICE_WALL, false);
                        else
                        {
                            me->AI()->DoCast(me, SPELL_SYLVANAS_DESTROY_ICE_WALL, false);
                            _isattackingwall = true;
                            _events.ScheduleEvent(EVENT_ESCAPE_22, 1000);
                        }
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            if (_icewall == 1)
                                lichking->AI()->DoCast(lichking, SPELL_SUMMON_LUMBERING_ABOMINATION);
                            else if (_icewall > 1 && _icewall < 4)
                                lichking->AI()->DoCast(lichking, SPELL_SUMMON_RISE_WITCH_DOCTOR);
                        }
                        break;
                    case EVENT_ESCAPE_22:
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            if (_icewall >= 2 && _icewall < 4)
                                lichking->AI()->DoCast(lichking, SPELL_SUMMON_LUMBERING_ABOMINATION);
                        }
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                        {
                            me->AI()->DoCast(me, SPELL_SYLVANAS_DESTROY_ICE_WALL, false);
                            if (_isattackingwall)
                                _events.ScheduleEvent(EVENT_ESCAPE_22, 1000);
                        }
                        break;

                    case EVENT_ESCAPE_23:// FINAL PART
                        if (Creature* walltarget = me->GetCreature(*me, _walltargetGUID))
                            walltarget->DespawnOrUnsummon(0);
                        if (GameObject* icewall = ObjectAccessor::GetGameObject(*me, _icewallGUID))
                        {
                            _instance->HandleGameObject(0 ,true, icewall);
                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            {
                                me->RemoveAurasDueToSpell(SPELL_JAINA_DESTROY_ICE_WALL);
                                me->AI()->Talk(SAY_JAINA_ESCAPE_6);
                            }
                            else
                            {
                                me->RemoveAurasDueToSpell(SPELL_SYLVANAS_DESTROY_ICE_WALL);
                                me->AI()->Talk(SAY_SYLVANAS_ESCAPE_6);
                            }
                        }
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                        {
                            lichking->GetMotionMaster()->MovePoint(0, LichKingFinalPos);
                            lichking->AI()->Talk(SAY_LK_ESCAPE_11);
                        }
                        me->GetMotionMaster()->MovePoint(0, NpcJainaOrSylvanasEscapeRoute[8]);
                        _events.ScheduleEvent(EVENT_ESCAPE_24, 10000);
                        break;
                    case EVENT_ESCAPE_24:
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            me->AI()->Talk(SAY_JAINA_ESCAPE_8);
                        else
                            me->AI()->Talk(SAY_SYLVANAS_ESCAPE_8);
                        _events.ScheduleEvent(EVENT_ESCAPE_25, 5000);
                        break;
                    case EVENT_ESCAPE_25:
                        if (GameObject* cave = _instance->instance->GetGameObject(_instance->GetData64(DATA_CAVE_IN)))
                           cave->SetGoState(GO_STATE_READY);
                        _events.ScheduleEvent(EVENT_ESCAPE_26, 4000);
                        break;
                    case EVENT_ESCAPE_26:
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            me->AI()->Talk(SAY_JAINA_ESCAPE_10);
                        else
                            me->AI()->Talk(SAY_SYLVANAS_ESCAPE_9);
                        _events.ScheduleEvent(EVENT_ESCAPE_27, 4000);
                        break;
                    case EVENT_ESCAPE_27:
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            me->SummonGameObject(GO_CAPTAIN_CHEST_1, ChestPos.GetPositionX(), ChestPos.GetPositionY(), ChestPos.GetPositionZ(), ChestPos.GetOrientation(), 0, 0, 0, 0, 720000);
                        else
                            me->SummonGameObject(GO_CAPTAIN_CHEST_3, ChestPos.GetPositionX(), ChestPos.GetPositionY(), ChestPos.GetPositionZ(), ChestPos.GetOrientation(), 0, 0, 0, 0, 720000);
                        me->SummonGameObject(GO_PORTAL, FinalPortalPos.GetPositionX(), FinalPortalPos.GetPositionY(), FinalPortalPos.GetPositionZ(), FinalPortalPos.GetOrientation(), 0, 0, 0, 0, 720000);
                        if (Creature* lichking = me->GetCreature(*me, _lichkingGUID))
                            lichking->DespawnOrUnsummon(1);
                        break;
                    }
                }
            }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_jaina_or_sylvanas_escape_horAI(creature);
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
        _instance(creature->GetInstanceScript())
    {
    }

    void Reset() OVERRIDE
    {
        me->CastSpell(me, SPELL_WELL_OF_SOULS, true);
        _events.Reset();
    }

    void EnterEvadeMode() OVERRIDE
    {
        if (_instance->GetData(DATA_WAVE_COUNT) != NOT_STARTED)
            _instance->SetData(DATA_WAVE_COUNT, NOT_STARTED);
    }

    void SetData(uint32 type, uint32 value) OVERRIDE
    {
        if (type)
            return;

        InternalWaveId = value;
    }

    uint32 GetData(uint32 type) const OVERRIDE
    {
        if (type)
            return 0;

        return InternalWaveId;
    }

protected:
    EventMap _events;
    InstanceScript* _instance;
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

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000); /// @todo adjust timers
            _events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000);
            _events.ScheduleEvent(EVENT_COWER_IN_FEAR, 10000);
            _events.ScheduleEvent(EVENT_DARK_MENDING, 20000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (_events.ExecuteEvent())
            {
                case EVENT_SHADOW_WORD_PAIN:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_SHADOW_WORD_PAIN);
                    _events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000);
                    break;
                case EVENT_CIRCLE_OF_DESTRUCTION:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_CIRCLE_OF_DESTRUCTION);
                    _events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000);
                    break;
                case EVENT_COWER_IN_FEAR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_COWER_IN_FEAR);
                    _events.ScheduleEvent(EVENT_COWER_IN_FEAR, 10000);
                    break;
                case EVENT_DARK_MENDING:
                    // find an ally with missing HP
                    if (Unit* target = DoSelectLowestHpFriendly(40, DUNGEON_MODE(30000, 50000)))
                    {
                        DoCast(target, SPELL_DARK_MENDING);
                        _events.ScheduleEvent(EVENT_DARK_MENDING, 20000);
                    }
                    else
                    {
                        // no friendly unit with missing hp. re-check in just 5 sec.
                        _events.ScheduleEvent(EVENT_DARK_MENDING, 5000);
                    }
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
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

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _events.ScheduleEvent(EVENT_FIREBALL, 3000); /// @todo adjust timers
            _events.ScheduleEvent(EVENT_FLAMESTRIKE, 6000);
            _events.ScheduleEvent(EVENT_FROSTBOLT, 9000);
            _events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 12000);
            _events.ScheduleEvent(EVENT_HALLUCINATION, 40000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (_events.ExecuteEvent())
            {
                case EVENT_FIREBALL:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_FIREBALL);
                    _events.ScheduleEvent(EVENT_FIREBALL, 15000);
                    break;
                case EVENT_FLAMESTRIKE:
                    DoCast(SPELL_FLAMESTRIKE);
                    _events.ScheduleEvent(EVENT_FLAMESTRIKE, 15000);
                    break;
                case EVENT_FROSTBOLT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_FROSTBOLT);
                    _events.ScheduleEvent(EVENT_FROSTBOLT, 15000);
                    break;
                case EVENT_CHAINS_OF_ICE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_CHAINS_OF_ICE);
                    _events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 15000);
                    break;
                case EVENT_HALLUCINATION:
                    DoCast(SPELL_HALLUCINATION);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
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

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            DoCast(SPELL_HALLUCINATION_2);
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
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

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _events.ScheduleEvent(EVENT_SHADOW_STEP, 8000); /// @todo adjust timers
            _events.ScheduleEvent(EVENT_DEADLY_POISON, 5000);
            _events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
            _events.ScheduleEvent(EVENT_KIDNEY_SHOT, 12000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (_events.ExecuteEvent())
            {
                case EVENT_SHADOW_STEP:
                    DoCast(SPELL_SHADOW_STEP);
                    _events.ScheduleEvent(EVENT_SHADOW_STEP, 8000);
                    break;
                case EVENT_DEADLY_POISON:
                    DoCastVictim(SPELL_DEADLY_POISON);
                    _events.ScheduleEvent(EVENT_DEADLY_POISON, 10000);
                    break;
                case EVENT_ENVENOMED_DAGGER_THROW:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_ENVENOMED_DAGGER_THROW);
                    _events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
                    break;
                case EVENT_KIDNEY_SHOT:
                    DoCastVictim(SPELL_KIDNEY_SHOT);
                    _events.ScheduleEvent(EVENT_KIDNEY_SHOT, 10000);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
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

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000); /// @todo adjust timers
            _events.ScheduleEvent(EVENT_SHIELD_BASH, 10000);
            _events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (_events.ExecuteEvent())
            {
                case EVENT_SPECTRAL_STRIKE:
                    DoCastVictim(SPELL_SPECTRAL_STRIKE);
                    _events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000);
                    break;
                case EVENT_SHIELD_BASH:
                    DoCastVictim(SPELL_SHIELD_BASH);
                    _events.ScheduleEvent(EVENT_SHIELD_BASH, 5000);
                    break;
                case EVENT_TORTURED_ENRAGE:
                    DoCast(SPELL_TORTURED_ENRAGE);
                    _events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
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

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _events.ScheduleEvent(EVENT_SHOOT, 1); /// @todo adjust timers
            _events.ScheduleEvent(EVENT_CURSED_ARROW, 7000);
            _events.ScheduleEvent(EVENT_FROST_TRAP, 10000);
            _events.ScheduleEvent(EVENT_ICE_SHOT, 15000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (_events.ExecuteEvent())
            {
                case EVENT_SHOOT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_SHOOT);
                    _events.ScheduleEvent(EVENT_SHOOT, 2000);
                    break;
                case EVENT_CURSED_ARROW:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_CURSED_ARROW);
                    _events.ScheduleEvent(EVENT_CURSED_ARROW, 10000);
                    break;
                case EVENT_FROST_TRAP:
                    DoCast(SPELL_FROST_TRAP);
                    _events.ScheduleEvent(EVENT_FROST_TRAP, 30000);
                    break;
                case EVENT_ICE_SHOT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_ICE_SHOT);
                    _events.ScheduleEvent(EVENT_ICE_SHOT, 15000);
                    break;
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_tortured_riflemanAI(creature);
    }
};


enum GeneralEvents
{
    //General
    EVENT_SHIELD                 = 1,
    EVENT_SPIKE                  = 2,
    EVENT_CLONE                  = 3,

    SAY_AGGRO                    = 0,
    SAY_DEATH                    = 1,

    SPELL_SHIELD_THROWN          = 69222, // 73076 on hc
    SPELL_SPIKE                  = 69184, // 70399 on hc
    SPELL_CLONE_NAME             = 57507,
    SPELL_CLONE_MODEL            = 45204,

    // Reflection
    EVENT_BALEFUL_STRIKE         = 1,

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
            _instance = me->GetInstanceScript();
            Reset();
        }

        InstanceScript* _instance;
        EventMap _events;

        void Reset() OVERRIDE
        {
            _events.Reset();
            _instance->SetData(DATA_FROSWORN_EVENT, NOT_STARTED);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            Talk(SAY_DEATH);
            _instance->SetData(DATA_FROSWORN_EVENT, DONE);
        }

        void EnterCombat(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
            _events.ScheduleEvent(EVENT_SHIELD, 5000);
            _events.ScheduleEvent(EVENT_SPIKE, 14000);
            _events.ScheduleEvent(EVENT_CLONE, 22000);
            _instance->SetData(DATA_FROSWORN_EVENT, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 event = _events.ExecuteEvent())
            {
                switch (event)
                {
                    case EVENT_SHIELD:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SHIELD_THROWN);
                        _events.ScheduleEvent(EVENT_SHIELD, urand(8000, 12000));
                        break;
                    case EVENT_SPIKE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_SPIKE);
                        _events.ScheduleEvent(EVENT_SPIKE, urand(15000, 20000));
                        break;
                    case EVENT_CLONE:
                        SummonClones();
                        _events.ScheduleEvent(EVENT_CLONE, 60000);
                        break;
                }
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

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
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

        EventMap _events;

        void Reset() OVERRIDE
        {
            _events.Reset();
        }

        void EnterCombat(Unit* /*victim*/) OVERRIDE
        {
            _events.ScheduleEvent(EVENT_BALEFUL_STRIKE, 3000);
        }

        void JustDied(Unit* killer) OVERRIDE
        {
            DoCast(killer, SPELL_SPIRIT_BURST);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (_events.ExecuteEvent())
            {
                case EVENT_BALEFUL_STRIKE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_BALEFUL_STRIKE);
                    _events.ScheduleEvent(EVENT_BALEFUL_STRIKE, urand(3000, 8000));
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_spiritual_reflectionAI(creature);
    }
};

class at_hor_intro_start : public AreaTriggerScript
{
public:
    at_hor_intro_start() : AreaTriggerScript("at_hor_intro_start") {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/) OVERRIDE
    {
        InstanceScript* _instance = player->GetInstanceScript();

        if (player->IsGameMaster())
            return true;

        if (_instance->GetData(DATA_INTRO_EVENT) == NOT_STARTED)
            _instance->SetData(DATA_INTRO_EVENT, IN_PROGRESS);

        return true;
    }
};

class at_hor_waves_restarter : public AreaTriggerScript
{
public:
    at_hor_waves_restarter() : AreaTriggerScript("at_hor_waves_restarter") {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/) OVERRIDE
    {
        InstanceScript* _instance = player->GetInstanceScript();

        if (player->IsGameMaster())
            return true;

        if (_instance->GetData(DATA_WAVE_COUNT))
            return true;

        if (_instance->GetData(DATA_INTRO_EVENT) == DONE && _instance->GetBossState(DATA_MARWYN_EVENT) != DONE)
        {
            _instance->ProcessEvent(0, EVENT_SPAWN_WAVES);

            if (Creature* falric = player->GetCreature(*player, _instance->GetData64(DATA_FALRIC_EVENT)))
            {
                falric->CastSpell(falric, SPELL_BOSS_SPAWN_AURA, true);
                falric->SetVisible(true);
            }
            if (Creature* marwyn = player->GetCreature(*player, _instance->GetData64(DATA_MARWYN_EVENT)))
            {
                marwyn->CastSpell(marwyn, SPELL_BOSS_SPAWN_AURA, true);
                marwyn->SetVisible(true);
            }
        }
        return true;
    }
};

class at_shadow_throne : public AreaTriggerScript
{
public:
    at_shadow_throne() : AreaTriggerScript("at_shadow_throne") { }

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/) OVERRIDE
    {
        InstanceScript* _instance = player->GetInstanceScript();

        if (player->IsGameMaster())
            return true;

        if (_instance->GetData(DATA_ESCAPE_EVENT) == NOT_STARTED)
            _instance->SetData(DATA_ESCAPE_EVENT, IN_PROGRESS);

        return true;
    }
};

class npc_raging_ghoul : public CreatureScript
{
public:
    npc_raging_ghoul() : CreatureScript("npc_raging_ghoul") { }

    struct npc_raging_ghoulAI : public ScriptedAI
    {
        npc_raging_ghoulAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = me->GetInstanceScript();
        }

        InstanceScript* _instance;
        uint32 _emergeTimer;
        bool _doEmerge;
        bool _doJump;
        uint64 _leaderGUID;

        void Reset() OVERRIDE
        {
            _emergeTimer = 4000;
            _doEmerge = false;
            _doJump = false;
            if (_instance && _instance->GetData(DATA_ESCAPE_EVENT) == IN_PROGRESS)
                _instance->SetData(DATA_SUMMONS, 1);

        }

        void IsSummonedBy(Unit*) OVERRIDE
        {
            DoCast(me, SPELL_EMERGE_VISUAL);
            DoZoneInCombat(me, 100.00f);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
             if (_instance)
                 _instance->SetData(DATA_SUMMONS, 0);
        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!who)
                return;

            if (!_doEmerge)
                return;

            ScriptedAI::AttackStart(who);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!_instance)
                return;

            if (_instance->GetData(DATA_ESCAPE_EVENT) == IN_PROGRESS)
            {
                _leaderGUID = _instance->GetData64(DATA_ESCAPE_LEADER);
                Creature* leader = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ESCAPE_LEADER));

                if (_doEmerge != true)
                {
                    if (_emergeTimer < diff)
                    {
                        _doEmerge = true;
                        if (leader)
                        {
                            DoResetThreat();
                            me->GetMotionMaster()->MoveIdle();
                            me->GetMotionMaster()->MoveChase(leader);
                        }
                    }
                    else
                        _emergeTimer -= diff;
                }

                if (me->Attack(leader,true))/*(Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f))*/
                {
                    if (!_doJump && me->IsWithinDistInMap(leader, 30.0f) && !me->IsWithinDistInMap(leader, 5.0f))
                    {
                        _doJump = true;
                        DoCast(leader, SPELL_GHOUL_JUMP);
                    }
                }
            }
            else if (_instance->GetData(DATA_ESCAPE_EVENT) == FAIL || _instance->GetData(DATA_ESCAPE_EVENT) == NOT_STARTED)
                me->DespawnOrUnsummon();
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
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
        npc_risen_witch_doctorAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = me->GetInstanceScript();
        }

        InstanceScript* _instance;
        uint32 _emergeTimer;
        bool _doEmerge;
        uint64 _leaderGUID;
        uint32 _boltTimer;
        uint32 _boltVolleyTimer;
        uint32 _curseTimer;

        void Reset() OVERRIDE
        {
            _emergeTimer = 5000;
            _boltTimer = 6000;
            _boltVolleyTimer = 15000;
            _curseTimer = 7000;
            _doEmerge = false;
            if (_instance)
                if (_instance->GetData(DATA_ESCAPE_EVENT) == IN_PROGRESS)
                    _instance->SetData(DATA_SUMMONS, 1);
        }

        void IsSummonedBy(Unit*) OVERRIDE
        {
            DoCast(me, SPELL_EMERGE_VISUAL);
            DoZoneInCombat(me, 100.00f);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (_instance)
                _instance->SetData(DATA_SUMMONS, 0);

        }

        void AttackStart(Unit* who) OVERRIDE
        {
            if (!who)
                return;

            if (_doEmerge == false)
                return;

            ScriptedAI::AttackStart(who);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!_instance)
                return;

            if (_instance->GetData(DATA_ESCAPE_EVENT) == IN_PROGRESS)
            {
                if (_doEmerge != true)
                {
                    if (_emergeTimer < diff)
                    {
                        _doEmerge = true;
                        _leaderGUID = _instance->GetData64(DATA_ESCAPE_LEADER);

                        if (Creature* leader =  ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ESCAPE_LEADER)))
                        {
                            DoResetThreat();
                            me->GetMotionMaster()->MoveIdle();
                            me->GetMotionMaster()->MoveChase(leader);
                        }
                    }
                    else
                        _emergeTimer -= diff;
                }

                if (_curseTimer < diff)
                {
                    if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, SPELL_COURSE_OF_DOOM);
                    _curseTimer = urand(10000, 15000);
                }
                else
                    _curseTimer -= diff;

                if (_boltTimer < diff)
                {
                    if (Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        DoCast(target, SPELL_SHADOW_BOLT);
                    _boltTimer = urand(2000, 3000);
                }
                else
                    _boltTimer -= diff;

                if (_boltVolleyTimer < diff)
                {
                    if (Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        DoCast(target, SPELL_SHADOW_BOLT_VOLLEY);
                    _boltVolleyTimer = urand(15000, 22000);
                }
                else
                    _boltVolleyTimer -= diff;
            }
            else if (_instance->GetData(DATA_ESCAPE_EVENT) == FAIL || _instance->GetData(DATA_ESCAPE_EVENT) == NOT_STARTED)
                me->DespawnOrUnsummon();
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_risen_witch_doctorAI(creature);
    }
};


class npc_lumbering_abomination : public CreatureScript
{
public:
    npc_lumbering_abomination() : CreatureScript("npc_lumbering_abomination") { }

    struct npc_lumbering_abominationAI : public ScriptedAI
    {
        npc_lumbering_abominationAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = me->GetInstanceScript();
        }

        InstanceScript* _instance;
        uint64 _leaderGUID;
        bool _doWalk;
        uint32 _strikeTimer;
        uint32 _vomitTimer;

        void Reset() OVERRIDE
        {
            _doWalk = false;
            _vomitTimer = 15000;
            _strikeTimer = 6000;
            if (_instance)
                if (_instance->GetData(DATA_ESCAPE_EVENT) == IN_PROGRESS)
                    _instance->SetData(DATA_SUMMONS, 1);
        }

        void IsSummonedBy(Unit*) OVERRIDE
        {
            DoCast(me, SPELL_EMERGE_VISUAL);
            DoZoneInCombat(me, 100.00f);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!_instance)
                return;

            if (_instance->GetData(DATA_ESCAPE_EVENT) == IN_PROGRESS)
            {
                if (_doWalk != true)
                {
                    _doWalk = true;
                    _leaderGUID = _instance->GetData64(DATA_ESCAPE_LEADER);
                    if (Creature* leader =  ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ESCAPE_LEADER)))
                    {
                        DoResetThreat();
                        me->GetMotionMaster()->MoveIdle();
                        me->GetMotionMaster()->MoveChase(leader);
                    }
                }
                if (_strikeTimer < diff)
                {
                    if (Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        DoCast(target, SPELL_ABON_STRIKE);
                    _strikeTimer = urand(7000, 9000);
                }
                else
                    _strikeTimer -= diff;

                if (_vomitTimer < diff)
                {
                        if (Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            DoCast(target, SPELL_VOMIT_SPRAY);
                        _vomitTimer = urand(15000, 20000);
                }
                else
                    _vomitTimer -= diff;
            }
            else if (_instance->GetData(DATA_ESCAPE_EVENT) == FAIL || _instance->GetData(DATA_ESCAPE_EVENT) == NOT_STARTED)
                me->DespawnOrUnsummon();
            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (_instance)
                _instance->SetData(DATA_SUMMONS, 0);
        }

    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_lumbering_abominationAI(creature);
    }
};

void AddSC_halls_of_reflection()
{
    new at_hor_intro_start();
    new at_hor_waves_restarter();
    new at_shadow_throne();
    new npc_jaina_or_sylvanas_hor();
    new npc_jaina_or_sylvanas_escape_hor();
    new npc_ghostly_priest();
    new npc_phantom_mage();
    new npc_phantom_hallucination();
    new npc_shadowy_mercenary();
    new npc_spectral_footman();
    new npc_tortured_rifleman();
    new npc_raging_ghoul();
    new npc_risen_witch_doctor();
    new npc_lumbering_abomination();
    new npc_frostworn_general();
    new npc_spiritual_reflection();
}
