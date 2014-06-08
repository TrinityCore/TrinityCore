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
#include "SpellScript.h"
#include "Transport.h"
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

    SAY_JAINA_SYLVANAS_ESCAPE_1         = 0,
    SAY_JAINA_SYLVANAS_ESCAPE_2         = 1,
    SAY_JAINA_SYLVANAS_ESCAPE_3         = 2,
    SAY_JAINA_SYLVANAS_ESCAPE_4         = 3,
    SAY_JAINA_SYLVANAS_ESCAPE_5         = 4,
    SAY_JAINA_SYLVANAS_ESCAPE_6         = 5,
    SAY_JAINA_SYLVANAS_ESCAPE_7         = 6, // unused
    SAY_JAINA_SYLVANAS_ESCAPE_8         = 7,

    SAY_JAINA_ESCAPE_9                  = 8,
    SAY_JAINA_ESCAPE_10                 = 9,

    SAY_SYLVANAS_ESCAPE_9               = 8,

    SAY_LK_ESCAPE_1                     = 0,
    SAY_LK_ESCAPE_2                     = 1,
    SAY_LK_ESCAPE_ICEWALL_SUMMONED_1    = 2,
    SAY_LK_ESCAPE_ICEWALL_SUMMONED_2    = 3,
    SAY_LK_ESCAPE_ICEWALL_SUMMONED_3    = 4,
    SAY_LK_ESCAPE_ICEWALL_SUMMONED_4    = 5,
    SAY_LK_ESCAPE_GHOULS                = 6,
    SAY_LK_ESCAPE_ABOMINATION           = 7,
    SAY_LK_ESCAPE_WINTER                = 8,
    SAY_LK_ESCAPE_HARVEST_SOUL          = 9,

    SAY_FALRIC_INTRO_1                  = 5,
    SAY_FALRIC_INTRO_2                  = 6,

    SAY_MARWYN_INTRO_1                  = 4
};

enum Events
{
    EVENT_WALK_INTRO1                   = 1,
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

    EVENT_REMORSELESS_WINTER,
    EVENT_ESCAPE_SUMMON_GHOULS,
    EVENT_ESCAPE_SUMMON_WITCH_DOCTOR,
    EVENT_ESCAPE_SUMMON_LUMBERING_ABOMINATION,

    EVENT_OPEN_IMPENETRABLE_DOOR,
    EVENT_CLOSE_IMPENETRABLE_DOOR,
    EVENT_KORELN_LORALEN_DEATH
};

enum Misc
{
    ACTION_START_INTRO,
    ACTION_SKIP_INTRO,

    JAINA_SYLVANAS_MAX_HEALTH          = 252000,

    POINT_SHADOW_THRONE_DOOR           = 1,
    POINT_ATTACK_ICEWALL               = 2,
    POINT_TRAP                         = 3,

    SOUND_LK_SLAY_1                    = 17214,
    SOUND_LK_SLAY_2                    = 17215,
    SOUND_LK_FURY_OF_FROSTMOURNE       = 17224
};

enum Spells
{
    // Misc
    SPELL_TAKE_FROSTMOURNE             = 72729,
    SPELL_FROSTMOURNE_DESPAWN          = 72726,
    SPELL_FROSTMOURNE_VISUAL           = 73220,
    SPELL_FROSTMOURNE_SOUNDS           = 70667,
    SPELL_BOSS_SPAWN_AURA              = 72712, // Falric and Marwyn
    SPELL_UTHER_DESPAWN                = 70693,

    // Jaina, Sylvanas
    SPELL_CAST_VISUAL                  = 65633, // wrong
    SPELL_SUMMON_SOULS                 = 72711,
    SPELL_TAUNT_ARTHAS                 = 69857,
    SPELL_JAINA_ICE_BARRIER            = 69787, // Jaina Ice Barrier
    SPELL_JAINA_ICE_PRISON             = 69708, // Jaina Ice Prison
    SPELL_JAINA_DESTROY_ICE_WALL       = 69784, // Jaina
    SPELL_SYLVANAS_CLOAK_OF_DARKNESS   = 70188, // Sylvanas Cloak of Darkness
    SPELL_SYLVANAS_DARK_BINDING        = 70194, // Sylvanas Dark Binding
    SPELL_SYLVANAS_DESTROY_ICE_WALL    = 70224, // Sylvanas
    SPELL_SYLVANAS_BLINDING_RETREAT    = 70199, // Sylvanas Blinding Retreat

    // Lich King
    SPELL_REMORSELESS_WINTER           = 69780, // Lich King Remorseless Winter
    SPELL_SOUL_REAPER                  = 69409, // Lich King Soul Reaper
    SPELL_FURY_OF_FROSTMOURNE          = 70063, // Lich King Fury of Frostmourne
    SPELL_RAISE_DEAD                   = 69818,
    SPELL_SUMMON_RISEN_WITCH_DOCTOR    = 69836,
    SPELL_SUMMON_LUMBERING_ABOMINATION = 69835,
    SPELL_SUMMON_ICE_WALL              = 69768, // Visual effect and icewall summoning
    SPELL_PAIN_AND_SUFFERING           = 74115, // Lich King Pain and Suffering
    SPELL_STUN_BREAK_JAINA             = 69764, // Lich King visual spell, another Stun Break is 69763, should remove the stun effect
    SPELL_STUN_BREAK_SYLVANAS          = 70200,
    SPELL_HARVEST_SOUL                 = 69866, // Lich King Harvest Soul

    // Koreln, Loralen
    SPELL_FEIGN_DEATH                  = 29266,

    // Raging Ghoul
    SPELL_GHOUL_JUMP                   = 70150,
    SPELL_RAGING_GHOUL_SPAWN           = 69636,

    // Risen Witch Doctor
    SPELL_CURSE_OF_DOOM                = 70144,
    SPELL_SHADOW_BOLT_VOLLEY           = 70145,
    SPELL_SHADOW_BOLT                  = 70080,
    SPELL_RISEN_WITCH_DOCTOR_SPAWN     = 69639,

    // Lumbering Abomination
    SPELL_CLEAVE                       = 40505,
    SPELL_VOMIT_SPRAY                  = 70176
};

enum HorGossipMenu
{
    GOSSIP_MENU_JAINA_FINAL            = 10930,
    GOSSIP_MENU_SYLVANAS_FINAL         = 10931
};

Position const NpcJainaOrSylvanasEscapeRoute[] =
{
    { 5601.217285f, 2207.652832f, 731.541931f, 5.223304f }, // leave the throne room
    { 5607.224375f, 2173.913330f, 731.126038f, 2.608723f }, // adjust route
    { 5583.427246f, 2138.784180f, 731.150391f, 4.260901f }, // stop for talking
    { 5560.281738f, 2104.025635f, 731.410889f, 4.058383f }, // attack the first icewall
    { 5510.990723f, 2000.772217f, 734.716064f, 3.973213f }, // attack the second icewall
    { 5452.641113f, 1905.762329f, 746.530579f, 4.118834f }, // attack the third icewall
    { 5338.126953f, 1768.429810f, 767.237244f, 3.855189f }, // attack the fourth icewall
    { 5259.06f,     1669.27f,     784.3008f,   0.0f      }, // trap (sniffed)
    { 5265.53f,     1681.6f,      784.2947f,   4.13643f  }  // final position (sniffed)
};

Position const LichKingMoveAwayPos      = { 5400.069824f, 2102.7131689f, 707.69525f, 0.843803f }; // Lich King walks away
Position const LichKingFirstSummon      = { 5600.076172f, 2192.270996f, 731.750488f, 4.330935f }; // Lich King First summons
Position const JainaSylvanasShadowThroneDoor = { 5577.243f, 2235.852f, 733.0128f, 2.209562f }; // Jaina/Sylvanas move to door
Position const LichKingFinalPos         = { 5283.742188f, 1706.335693f, 783.293518f, 4.138510f }; // Lich King Final Pos

// sniffed
Position const KorelnOrLoralenPos[] =
{
    { 5253.061f, 1953.616f, 707.6948f, 0.8377581f },
    { 5283.226f, 1992.300f, 707.7445f, 0.8377581f },
    { 5360.711f, 2064.797f, 707.6948f, 0.0f }
};

Position const SylvanasIntroPosition[] =
{
    { 0.0f,     0.0f,     0.0f,      0.0f       }, // 0 - Spawn
    { 5263.2f,  1950.96f, 707.6948f, 0.8028514f }, // 1 - Move to Door
    { 5306.82f, 1998.17f, 709.341f,  1.239184f  }, // 2 - Move to Frostmourne
};

Position const JainaIntroPosition[] =
{
    { 0.0f,     0.0f,     0.0f,      0.0f      }, // 0 - Spawn
    { 5265.89f, 1952.98f, 707.6978f, 0.0f      }, // 1 - Move to Door
    { 5306.95f, 1998.49f, 709.3414f, 1.277278f }  // 2 - Move to Frostmourne
};

Position const UtherSpawnPos = { 5307.814f, 2003.168f, 709.4244f, 4.537856f };

Position const LichKingIntroPosition[] =
{
    { 5362.463f, 2062.693f, 707.7781f, 3.944444f }, // 0 - Spawn
    { 5332.83f,  2031.24f,  707.6948f, 0.0f      }, // 1 - Door
    { 5312.93f,  2010.24f,  709.34f,   0.0f      }, // 2 - Move to Frostmourne
    { 5319.028f, 2016.662f, 707.6948f, 0.0f      }, // 3 - Move back
    { 5332.285f, 2030.832f, 707.6948f, 0.0f      }, // 4 - Move back 2
    { 5355.488f, 2055.149f, 707.6907f, 0.0f      }  // 5 - Move back 3
};

Position const FalricPosition[] =
{
    { 5276.583f, 2037.45f, 709.4025f, 5.532694f }, // 0 - Spawn
    { 5283.95f,  2030.53f, 709.3191f, 0.0f      }  // 1 - Intro
};

Position const MarwynPosition[] =
{
    { 5342.232f, 1975.696f, 709.4025f, 2.391101f }, // 0 - Spawn
    { 5335.01f,  1982.37f,  709.3191f, 0.0f      }  // 1 - Intro
};

Position const SylvanasShadowThroneDoorPosition = { 5576.79f, 2235.73f, 733.0029f, 2.687807f };

Position const IceWallTargetPosition[] =
{
    { 5547.833f, 2083.701f, 731.4332f, 1.029744f  }, // 1st Icewall
    { 5503.213f, 1969.547f, 737.0245f, 1.27409f   }, // 2nd Icewall
    { 5439.976f, 1879.005f, 752.7048f, 1.064651f  }, // 3rd Icewall
    { 5318.289f, 1749.184f, 771.9423f, 0.8726646f }  // 4th Icewall
};

class npc_jaina_or_sylvanas_intro_hor : public CreatureScript
{
    public:
        npc_jaina_or_sylvanas_intro_hor() : CreatureScript("npc_jaina_or_sylvanas_intro_hor") { }

        struct npc_jaina_or_sylvanas_intro_horAI : public ScriptedAI
        {
            npc_jaina_or_sylvanas_intro_horAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = me->GetInstanceScript();
                _utherGUID = 0;
                _lichkingGUID = 0;
            }

            void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                player->PlayerTalkClass->ClearMenus();

                switch (gossipListId)
                {
                    case 0:
                        player->PlayerTalkClass->SendCloseGossip();
                        _events.ScheduleEvent(EVENT_START_INTRO, 1000);
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                        break;
                    case 1:
                        player->PlayerTalkClass->SendCloseGossip();
                        _events.ScheduleEvent(EVENT_SKIP_INTRO, 1000);
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                        break;
                    default:
                        break;
                }
            }

            void Reset() override
            {
                _events.Reset();

                _utherGUID = 0;
                _lichkingGUID = 0;

                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                me->SetStandState(UNIT_STAND_STATE_STAND);
                _events.ScheduleEvent(EVENT_WALK_INTRO1, 3000);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                switch (_events.ExecuteEvent())
                {
                    case EVENT_WALK_INTRO1:
                        if (Creature* korelnOrLoralen = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_KORELN_LORALEN)))
                            korelnOrLoralen->GetMotionMaster()->MovePoint(0, KorelnOrLoralenPos[0]);

                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        {
                            me->GetMotionMaster()->MovePoint(0, JainaIntroPosition[1]);
                            Talk(SAY_JAINA_INTRO_1);
                            _events.ScheduleEvent(EVENT_WALK_INTRO2, 7000);
                        }
                        else
                        {
                            me->GetMotionMaster()->MovePoint(0, SylvanasIntroPosition[1]);
                            Talk(SAY_SYLVANAS_INTRO_1);
                            _events.ScheduleEvent(EVENT_WALK_INTRO2, 9000);
                        }
                        break;
                    case EVENT_WALK_INTRO2:
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            Talk(SAY_JAINA_INTRO_2);
                        else
                            Talk(SAY_SYLVANAS_INTRO_2);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                        break;
                    case EVENT_START_INTRO:
                        if (Creature* korelnOrLoralen = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_KORELN_LORALEN)))
                            korelnOrLoralen->GetMotionMaster()->MovePoint(0, KorelnOrLoralenPos[1]);
                        // Begining of intro is differents between factions as the speech sequence and timers are differents.
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                        {
                            me->GetMotionMaster()->MovePoint(0, JainaIntroPosition[2]);
                            _events.ScheduleEvent(EVENT_INTRO_A2_1, 0);
                        }
                        else
                        {
                            me->GetMotionMaster()->MovePoint(0, SylvanasIntroPosition[2]);
                            _events.ScheduleEvent(EVENT_INTRO_H2_1, 0);
                        }
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
                            _utherGUID = uther->GetGUID();
                        _events.ScheduleEvent(EVENT_INTRO_A2_5, 2000);
                        break;
                    case EVENT_INTRO_A2_5:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                            uther->AI()->Talk(SAY_UTHER_INTRO_A2_1);
                        _events.ScheduleEvent(EVENT_INTRO_A2_6, 3000);
                        break;
                    case EVENT_INTRO_A2_6:
                        Talk(SAY_JAINA_INTRO_5);
                        _events.ScheduleEvent(EVENT_INTRO_A2_7, 7000);
                        break;
                    case EVENT_INTRO_A2_7:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                            uther->AI()->Talk(SAY_UTHER_INTRO_A2_2);
                        _events.ScheduleEvent(EVENT_INTRO_A2_8, 7000);
                        break;
                    case EVENT_INTRO_A2_8:
                        Talk(SAY_JAINA_INTRO_6);
                        _events.ScheduleEvent(EVENT_INTRO_A2_9, 1200);
                        break;
                    case EVENT_INTRO_A2_9:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                            uther->AI()->Talk(SAY_UTHER_INTRO_A2_3);
                        _events.ScheduleEvent(EVENT_INTRO_A2_10, 11000);
                        break;
                    case EVENT_INTRO_A2_10:
                        Talk(SAY_JAINA_INTRO_7);
                        _events.ScheduleEvent(EVENT_INTRO_A2_11, 6000);
                        break;
                    case EVENT_INTRO_A2_11:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                            uther->AI()->Talk(SAY_UTHER_INTRO_A2_4);
                        _events.ScheduleEvent(EVENT_INTRO_A2_12, 12000);
                        break;
                    case EVENT_INTRO_A2_12:
                        Talk(SAY_JAINA_INTRO_8);
                        _events.ScheduleEvent(EVENT_INTRO_A2_13, 6000);
                        break;
                    case EVENT_INTRO_A2_13:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                            uther->AI()->Talk(SAY_UTHER_INTRO_A2_5);
                        _events.ScheduleEvent(EVENT_INTRO_A2_14, 13000);
                        break;
                    case EVENT_INTRO_A2_14:
                        Talk(SAY_JAINA_INTRO_9);
                        _events.ScheduleEvent(EVENT_INTRO_A2_15, 12000);
                        break;
                    case EVENT_INTRO_A2_15:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                            uther->AI()->Talk(SAY_UTHER_INTRO_A2_6);
                        _events.ScheduleEvent(EVENT_INTRO_A2_16, 25000);
                        break;
                    case EVENT_INTRO_A2_16:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                            uther->AI()->Talk(SAY_UTHER_INTRO_A2_7);
                        _events.ScheduleEvent(EVENT_INTRO_A2_17, 6000);
                        break;
                    case EVENT_INTRO_A2_17:
                        Talk(SAY_JAINA_INTRO_10);
                        _events.ScheduleEvent(EVENT_INTRO_A2_18, 5000);
                        break;
                    case EVENT_INTRO_A2_18:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
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
                            _utherGUID = uther->GetGUID();
                        _events.ScheduleEvent(EVENT_INTRO_H2_5, 2000);
                        break;
                    case EVENT_INTRO_H2_5:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                            uther->AI()->Talk(SAY_UTHER_INTRO_H2_1);
                        _events.ScheduleEvent(EVENT_INTRO_H2_6, 11000);
                        break;
                    case EVENT_INTRO_H2_6:
                        Talk(SAY_SYLVANAS_INTRO_4);
                        _events.ScheduleEvent(EVENT_INTRO_H2_7, 3000);
                        break;
                    case EVENT_INTRO_H2_7:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                            uther->AI()->Talk(SAY_UTHER_INTRO_H2_2);
                        _events.ScheduleEvent(EVENT_INTRO_H2_8, 6000);
                        break;
                    case EVENT_INTRO_H2_8:
                        Talk(SAY_SYLVANAS_INTRO_5);
                        _events.ScheduleEvent(EVENT_INTRO_H2_9, 5000);
                        break;
                    case EVENT_INTRO_H2_9:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                            uther->AI()->Talk(SAY_UTHER_INTRO_H2_3);
                        _events.ScheduleEvent(EVENT_INTRO_H2_10, 19000);
                        break;
                    case EVENT_INTRO_H2_10:
                        Talk(SAY_SYLVANAS_INTRO_6);
                        _events.ScheduleEvent(EVENT_INTRO_H2_11, 1500);
                        break;
                    case EVENT_INTRO_H2_11:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                            uther->AI()->Talk(SAY_UTHER_INTRO_H2_4);
                        _events.ScheduleEvent(EVENT_INTRO_H2_12, 19500);
                        break;
                    case EVENT_INTRO_H2_12:
                        Talk(SAY_SYLVANAS_INTRO_7);
                        _events.ScheduleEvent(EVENT_INTRO_H2_13, 2000);
                        break;
                    case EVENT_INTRO_H2_13:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                        {
                            uther->HandleEmoteCommand(EMOTE_ONESHOT_NO);
                            uther->AI()->Talk(SAY_UTHER_INTRO_H2_5);
                        }
                        _events.ScheduleEvent(EVENT_INTRO_H2_14, 12000);
                        break;
                    case EVENT_INTRO_H2_14:
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
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
                        if (Creature* lichking = me->SummonCreature(NPC_THE_LICH_KING_INTRO, LichKingIntroPosition[0], TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            lichking->SetWalk(true);
                            lichking->GetMotionMaster()->MovePoint(0, LichKingIntroPosition[2]);
                            _lichkingGUID = lichking->GetGUID();
                            _events.ScheduleEvent(EVENT_OPEN_IMPENETRABLE_DOOR, 0);
                            _events.ScheduleEvent(EVENT_CLOSE_IMPENETRABLE_DOOR, 4000);
                        }
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
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
                        if (Creature* lichking = ObjectAccessor::GetCreature(*me, _lichkingGUID))
                            lichking->AI()->Talk(SAY_LK_INTRO_1);
                        _events.ScheduleEvent(EVENT_INTRO_LK_3, 1000);
                        break;
                    case EVENT_INTRO_LK_3:
                        // The Lich King banishes Uther to the abyss.
                        if (Creature* uther = ObjectAccessor::GetCreature(*me, _utherGUID))
                        {
                            uther->CastSpell(uther, SPELL_UTHER_DESPAWN, true);
                            uther->DespawnOrUnsummon(5000);
                            _utherGUID = 0;
                        }
                        _events.ScheduleEvent(EVENT_INTRO_LK_4, 9000);
                        break;
                    case EVENT_INTRO_LK_4:
                        // He steps forward and removes the runeblade from the heap of skulls.
                        if (Creature* lichking = ObjectAccessor::GetCreature(*me, _lichkingGUID))
                        {
                            if (GameObject* frostmourne = ObjectAccessor::GetGameObject(*me, _instance->GetData64(DATA_FROSTMOURNE)))
                                frostmourne->SetLootState(GO_JUST_DEACTIVATED);
                            lichking->CastSpell(lichking, SPELL_TAKE_FROSTMOURNE, true);
                            lichking->CastSpell(lichking, SPELL_FROSTMOURNE_VISUAL, true);
                        }
                        _events.ScheduleEvent(EVENT_INTRO_LK_5, 8000);
                        break;
                    case EVENT_INTRO_LK_5:
                        if (Creature* lichking = ObjectAccessor::GetCreature(*me, _lichkingGUID))
                            lichking->AI()->Talk(SAY_LK_INTRO_2);
                        _events.ScheduleEvent(EVENT_INTRO_LK_6, 10000);
                        break;
                    case EVENT_INTRO_LK_6:
                        // summon Falric and Marwyn. then go back to the door
                        if (Creature* falric = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_FALRIC)))
                        {
                            falric->CastSpell(falric, SPELL_BOSS_SPAWN_AURA, true);
                            falric->SetVisible(true);
                        }
                        if (Creature* marwyn = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_MARWYN)))
                        {
                            marwyn->CastSpell(marwyn, SPELL_BOSS_SPAWN_AURA, true);
                            marwyn->SetVisible(true);
                        }
                        if (Creature* lichking = ObjectAccessor::GetCreature(*me, _lichkingGUID))
                        {
                            lichking->AI()->Talk(SAY_LK_INTRO_3);
                            lichking->SetWalk(true);
                            lichking->GetMotionMaster()->MovePoint(0, LichKingMoveAwayPos);
                        }
                        _events.ScheduleEvent(EVENT_INTRO_LK_7, 10000);
                        _events.ScheduleEvent(EVENT_OPEN_IMPENETRABLE_DOOR, 5000);
                        break;
                    case EVENT_INTRO_LK_7:
                        if (Creature* marwyn = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_MARWYN)))
                        {
                            marwyn->AI()->Talk(SAY_MARWYN_INTRO_1);
                            marwyn->SetWalk(true);
                            marwyn->GetMotionMaster()->MovePoint(0, MarwynPosition[1]);
                        }
                        _events.ScheduleEvent(EVENT_INTRO_LK_8, 1000);
                        break;
                    case EVENT_INTRO_LK_8:
                        if (Creature* falric = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_FALRIC)))
                        {
                            falric->AI()->Talk(SAY_FALRIC_INTRO_1);
                            falric->SetWalk(true);
                            falric->GetMotionMaster()->MovePoint(0, FalricPosition[1]);
                        }
                        _events.ScheduleEvent(EVENT_INTRO_LK_9, 5000);
                        break;
                    case EVENT_INTRO_LK_9:
                        if (Creature* falric = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_FALRIC)))
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
                        /// @todo: needs some improvements
                        if (Creature* korelnOrLoralen = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_KORELN_LORALEN)))
                            korelnOrLoralen->GetMotionMaster()->MovePoint(1, KorelnOrLoralenPos[2]);
                        _events.ScheduleEvent(EVENT_INTRO_LK_11, 5000);
                        break;
                    case EVENT_INTRO_LK_11:
                        if (Creature* lichking = ObjectAccessor::GetCreature(*me, _lichkingGUID))
                        {
                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                lichking->AI()->Talk(SAY_LK_JAINA_INTRO_END);
                            else
                                lichking->AI()->Talk(SAY_LK_SYLVANAS_INTRO_END);
                        }
                        _events.ScheduleEvent(EVENT_INTRO_END, 5000);
                        break;
                    case EVENT_INTRO_END:
                        _instance->SetData(DATA_INTRO_EVENT, DONE);
                        _events.ScheduleEvent(EVENT_KORELN_LORALEN_DEATH, 8000);
                        if (Creature* lichking = ObjectAccessor::GetCreature(*me, _lichkingGUID))
                        {
                            lichking->DespawnOrUnsummon(5000);
                            _lichkingGUID = 0;
                        }
                        me->DespawnOrUnsummon(10000);
                        _events.ScheduleEvent(EVENT_CLOSE_IMPENETRABLE_DOOR, 7000);
                        break;
                    case EVENT_SKIP_INTRO:
                        if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                            me->GetMotionMaster()->MovePoint(0, JainaIntroPosition[2]);
                        else
                            me->GetMotionMaster()->MovePoint(0, SylvanasIntroPosition[2]);

                        if (Creature* korelnOrLoralen = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_KORELN_LORALEN)))
                            korelnOrLoralen->GetMotionMaster()->MovePoint(0, KorelnOrLoralenPos[1]);

                        if (Creature* lichking = me->SummonCreature(NPC_THE_LICH_KING_INTRO, LichKingIntroPosition[0], TEMPSUMMON_MANUAL_DESPAWN))
                        {
                            lichking->SetWalk(true);
                            lichking->GetMotionMaster()->MovePoint(0, LichKingIntroPosition[2]);
                            lichking->SetReactState(REACT_PASSIVE);
                            _lichkingGUID = lichking->GetGUID();
                            _events.ScheduleEvent(EVENT_OPEN_IMPENETRABLE_DOOR, 0);
                            _events.ScheduleEvent(EVENT_CLOSE_IMPENETRABLE_DOOR, 4000);
                        }
                        _events.ScheduleEvent(EVENT_INTRO_LK_4, 15000);
                        break;
                    case EVENT_OPEN_IMPENETRABLE_DOOR:
                        _instance->HandleGameObject(_instance->GetData64(DATA_IMPENETRABLE_DOOR), true);
                        break;
                    case EVENT_CLOSE_IMPENETRABLE_DOOR:
                        _instance->HandleGameObject(_instance->GetData64(DATA_IMPENETRABLE_DOOR), false);
                        break;
                    case EVENT_KORELN_LORALEN_DEATH:
                        if (Creature* korelnOrLoralen = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_KORELN_LORALEN)))
                            korelnOrLoralen->CastSpell(korelnOrLoralen, SPELL_FEIGN_DEATH);
                        break;
                    default:
                        break;
                }
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            uint64 _utherGUID;
            uint64 _lichkingGUID;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<npc_jaina_or_sylvanas_intro_horAI>(creature);
        }
};

class npc_jaina_or_sylvanas_escape_hor : public CreatureScript
{
    public:
        npc_jaina_or_sylvanas_escape_hor() : CreatureScript("npc_jaina_or_sylvanas_escape_hor") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            // override default gossip
            if (InstanceScript* instance = creature->GetInstanceScript())
                if (instance->GetBossState(DATA_THE_LICH_KING_ESCAPE) == DONE)
                {
                    player->PrepareGossipMenu(creature, creature->GetEntry() == NPC_JAINA_ESCAPE ? GOSSIP_MENU_JAINA_FINAL : GOSSIP_MENU_SYLVANAS_FINAL, true);
                    player->SendPreparedGossip(creature);
                    return true;
                }

            // load default gossip
            return false;
        }

        struct npc_jaina_or_sylvanas_escape_horAI : public ScriptedAI
        {
            npc_jaina_or_sylvanas_escape_horAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript()), _icewall(0), _prefight(false), _invincibility(true) { }

            void Reset() override
            {
                _events.Reset();
                _icewall = 0;
                _events.ScheduleEvent(EVENT_ESCAPE, 1000);
                _instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_NOT_RETREATING_EVENT);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                    lichking->AI()->EnterEvadeMode(); // event failed
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (damage >= me->GetHealth() && _invincibility)
                    damage = me->GetHealth() - 1;
            }

            void DoAction(int32 actionId) override
            {
                switch (actionId)
                {
                    case ACTION_START_PREFIGHT:
                        if (_prefight)
                            return;
                        _prefight = true;
                        _events.ScheduleEvent(EVENT_ESCAPE_1, 1000);
                        break;
                    case ACTION_WALL_BROKEN:
                        ++_icewall;
                        if (_icewall < 4)
                            _events.ScheduleEvent(EVENT_ESCAPE_13, 3000);
                        else
                            _events.ScheduleEvent(EVENT_ESCAPE_15, 3000);
                        break;
                    case ACTION_GUNSHIP_ARRIVAL:
                        _events.ScheduleEvent(EVENT_ESCAPE_16, 5000);
                        break;
                    case ACTION_GUNSHIP_ARRIVAL_2:
                        _events.ScheduleEvent(EVENT_ESCAPE_17, 5000);
                        break;
                    default:
                        break;
                }
            }

            void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
            {
                player->PlayerTalkClass->ClearMenus();

                switch (gossipListId)
                {
                    case 0:
                        player->PlayerTalkClass->SendCloseGossip();
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        _events.ScheduleEvent(EVENT_ESCAPE_6, 0);
                        break;
                    default:
                        break;
                }
            }

            void DestroyIceWall()
            {
                if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                    me->RemoveAurasDueToSpell(SPELL_JAINA_DESTROY_ICE_WALL);
                else
                    me->RemoveAurasDueToSpell(SPELL_SYLVANAS_DESTROY_ICE_WALL);

                _instance->HandleGameObject(_instance->GetData64(DATA_ICEWALL), true);
                me->m_Events.AddEvent(new GameObjectDeleteDelayEvent(me, _instance->GetData64(DATA_ICEWALL)), me->m_Events.CalculateTime(5000));

                if (Creature* wallTarget = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ICEWALL_TARGET)))
                    wallTarget->DespawnOrUnsummon();
            }

            void SummonIceWall()
            {
                if (_icewall < 4)
                {
                    if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                    {
                        lichking->StopMoving();
                        if (Creature* wallTarget = me->SummonCreature(NPC_ICE_WALL_TARGET, IceWallTargetPosition[_icewall], TEMPSUMMON_MANUAL_DESPAWN, 720000))
                            lichking->CastSpell(wallTarget, SPELL_SUMMON_ICE_WALL);

                        lichking->AI()->SetData(DATA_ICEWALL, _icewall);
                    }
                }
            }

            void AttackIceWall()
            {
                if (_icewall < 4)
                    Talk(SAY_JAINA_SYLVANAS_ESCAPE_2 + _icewall);

                if (Creature* wallTarget = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ICEWALL_TARGET)))
                    me->SetFacingToObject(wallTarget);

                if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                    DoCast(me, SPELL_JAINA_DESTROY_ICE_WALL, true);
                else
                    DoCast(me, SPELL_SYLVANAS_DESTROY_ICE_WALL, true);
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case POINT_SHADOW_THRONE_DOOR:
                        if (me->GetEntry() == NPC_JAINA_ESCAPE)
                            me->RemoveAurasDueToSpell(SPELL_JAINA_ICE_BARRIER);
                        else
                            me->RemoveAurasDueToSpell(SPELL_SYLVANAS_CLOAK_OF_DARKNESS);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        me->SetHealth(JAINA_SYLVANAS_MAX_HEALTH);
                        me->SetFacingTo(SylvanasShadowThroneDoorPosition.GetOrientation());
                        break;
                    case POINT_ATTACK_ICEWALL:
                        AttackIceWall();
                        break;
                    case POINT_TRAP:
                        Talk(SAY_JAINA_SYLVANAS_ESCAPE_8);
                        if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                            me->SetFacingToObject(lichking);
                        break;
                    default:
                        break;
                }
            }

            void DeleteAllFromThreatList(Unit* target, uint64 except)
            {
                ThreatContainer::StorageType threatlist = target->getThreatManager().getThreatList();
                for (auto i : threatlist)
                {
                    if (i->getUnitGuid() == except)
                        continue;

                    i->removeReference();
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 event = _events.ExecuteEvent())
                {
                    switch (event)
                    {
                        case EVENT_ESCAPE:
                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                DoCast(me, SPELL_JAINA_ICE_BARRIER);
                            else
                                DoCast(me, SPELL_SYLVANAS_CLOAK_OF_DARKNESS);

                            if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                            {
                                AttackStart(lichking);
                                lichking->AI()->AttackStart(me);
                                me->CastSpell(lichking, SPELL_TAUNT_ARTHAS, true);
                            }
                            me->SetHealth(JAINA_SYLVANAS_MAX_HEALTH);
                            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                            break;
                        case EVENT_ESCAPE_1:
                            if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                            {
                                if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                    lichking->AI()->Talk(SAY_LK_ESCAPE_1);
                                else
                                    lichking->AI()->Talk(SAY_LK_ESCAPE_2);
                                _events.ScheduleEvent(EVENT_ESCAPE_2, 8000);
                            }
                            break;
                        case EVENT_ESCAPE_2:
                            me->AttackStop();
                            me->StopMoving();
                            me->SetReactState(REACT_PASSIVE);

                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                DoCast(me, SPELL_JAINA_ICE_PRISON, false);
                            else
                                DoCast(me, SPELL_SYLVANAS_BLINDING_RETREAT, true);

                            if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                            {
                                lichking->SetReactState(REACT_PASSIVE);
                                lichking->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
                            }

                            _events.ScheduleEvent(EVENT_ESCAPE_3, 1500);
                            break;
                        case EVENT_ESCAPE_3:
                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == HORDE)
                                DoCastAOE(SPELL_SYLVANAS_DARK_BINDING, true);
                            _events.ScheduleEvent(EVENT_ESCAPE_4, 1000);
                            break;
                        case EVENT_ESCAPE_4:
                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                DoCast(me, SPELL_CREDIT_FINDING_JAINA);
                            else
                                DoCast(me, SPELL_CREDIT_FINDING_SYLVANAS);
                            Talk(SAY_JAINA_SYLVANAS_ESCAPE_1);

                            if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                            {
                                lichking->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                                lichking->RemoveAllAttackers();

                                DeleteAllFromThreatList(lichking, me->GetGUID());
                            }

                            _events.ScheduleEvent(EVENT_ESCAPE_5, 2000);
                            break;
                        case EVENT_ESCAPE_5:
                            me->GetMotionMaster()->MovePoint(POINT_SHADOW_THRONE_DOOR, SylvanasShadowThroneDoorPosition);
                            break;
                        case EVENT_ESCAPE_6:
                            if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                            {
                                lichking->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_PACIFIED);

                                if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                {
                                    lichking->CastSpell(lichking, SPELL_STUN_BREAK_JAINA);
                                    lichking->RemoveAurasDueToSpell(SPELL_JAINA_ICE_PRISON);
                                }
                                else
                                {
                                    lichking->CastSpell(lichking, SPELL_STUN_BREAK_SYLVANAS);
                                    lichking->RemoveAurasDueToSpell(SPELL_SYLVANAS_DARK_BINDING);
                                }
                            }
                            _invincibility = false;
                            _instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_NOT_RETREATING_EVENT);
                            _events.ScheduleEvent(EVENT_ESCAPE_7, 1000);
                            break;
                        case EVENT_ESCAPE_7:
                            if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                                lichking->HandleEmoteCommand(TEXT_EMOTE_ROAR);
                            me->GetMotionMaster()->MovePoint(0, NpcJainaOrSylvanasEscapeRoute[0]);
                            _events.ScheduleEvent(EVENT_ESCAPE_8, 3000);
                            break;
                        case EVENT_ESCAPE_8:
                            if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                                lichking->GetMotionMaster()->MovePoint(0, NpcJainaOrSylvanasEscapeRoute[0]);
                            _events.ScheduleEvent(EVENT_ESCAPE_9, 1000);
                            break;
                        case EVENT_ESCAPE_9:
                            me->GetMotionMaster()->MovePoint(0, NpcJainaOrSylvanasEscapeRoute[1]);
                            _events.ScheduleEvent(EVENT_ESCAPE_10, 5000);
                            break;
                        case EVENT_ESCAPE_10:
                            me->GetMotionMaster()->MovePoint(0, NpcJainaOrSylvanasEscapeRoute[2]);
                            if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                                lichking->GetMotionMaster()->MovePoint(1, LichKingFirstSummon);
                            _events.ScheduleEvent(EVENT_ESCAPE_11, 6000);
                            break;
                        case EVENT_ESCAPE_11:
                            SummonIceWall();
                            _events.ScheduleEvent(EVENT_ESCAPE_12, 4000);
                            break;
                        case EVENT_ESCAPE_12:
                            if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                                lichking->CastSpell(lichking, SPELL_PAIN_AND_SUFFERING, true);

                            me->GetMotionMaster()->MovePoint(POINT_ATTACK_ICEWALL, NpcJainaOrSylvanasEscapeRoute[3]);
                            break;
                        case EVENT_ESCAPE_13: // ICEWALL BROKEN
                            DestroyIceWall();

                            if (_icewall && _icewall < 4)
                                me->GetMotionMaster()->MovePoint(POINT_ATTACK_ICEWALL, NpcJainaOrSylvanasEscapeRoute[_icewall + 3]);
                            _events.ScheduleEvent(EVENT_ESCAPE_14, 8000);
                            break;
                        case EVENT_ESCAPE_14:
                            SummonIceWall();
                            break;
                        case EVENT_ESCAPE_15: // FINAL PART
                            DestroyIceWall();

                            Talk(SAY_JAINA_SYLVANAS_ESCAPE_6);

                            if (Creature* lichking = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_THE_LICH_KING_ESCAPE)))
                            {
                                lichking->GetMotionMaster()->MovePoint(2, LichKingFinalPos);
                                lichking->RemoveAurasDueToSpell(SPELL_REMORSELESS_WINTER);
                            }
                            me->GetMotionMaster()->MovePoint(POINT_TRAP, NpcJainaOrSylvanasEscapeRoute[7]);
                            break;
                        case EVENT_ESCAPE_16:
                            me->RemoveAurasDueToSpell(SPELL_HARVEST_SOUL);
                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                Talk(SAY_JAINA_ESCAPE_9);
                            if (Transport* gunship = ObjectAccessor::GetTransport(*me, _instance->GetData64(DATA_GUNSHIP)))
                                gunship->EnableMovement(true);
                            _instance->SetBossState(DATA_THE_LICH_KING_ESCAPE, DONE);
                            break;
                        case EVENT_ESCAPE_17:
                            if (_instance->GetData(DATA_TEAM_IN_INSTANCE) == ALLIANCE)
                                Talk(SAY_JAINA_ESCAPE_10);
                            else
                                Talk(SAY_SYLVANAS_ESCAPE_9);
                            DoCast(me, SPELL_CREDIT_ESCAPING_ARTHAS);
                            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP | UNIT_NPC_FLAG_QUESTGIVER);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            uint32 _icewall; // icewall number
            bool _prefight;
            bool _invincibility;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<npc_jaina_or_sylvanas_escape_horAI>(creature);
        }
};

class npc_the_lich_king_escape_hor : public CreatureScript
{
    public:
        npc_the_lich_king_escape_hor() : CreatureScript("npc_the_lich_king_escape_hor") { }

        struct npc_the_lich_king_escape_horAI : public ScriptedAI
        {
            npc_the_lich_king_escape_horAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = me->GetInstanceScript();
                _instance->SetBossState(DATA_THE_LICH_KING_ESCAPE, NOT_STARTED);
                _summonsCount = 0;
                _icewall = 0;
                _despawn = false;
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (damage >= me->GetHealth())
                    damage = me->GetHealth() - 1;
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type == POINT_MOTION_TYPE)
                {
                    switch (pointId)
                    {
                        case 1:
                            if (Creature* target = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ESCAPE_LEADER)))
                                me->GetMotionMaster()->MoveChase(target);
                            break;
                        case 2:
                            Talk(SAY_LK_ESCAPE_HARVEST_SOUL);

                            if (Creature* target = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ESCAPE_LEADER)))
                                DoCast(target, SPELL_HARVEST_SOUL);

                            if (Transport* gunship = ObjectAccessor::GetTransport(*me, _instance->GetData64(DATA_GUNSHIP)))
                                gunship->EnableMovement(true);
                            break;
                        default:
                            break;
                    }
                }
            }

            void JustSummoned(Creature* /*summon*/) override
            {
                ++_summonsCount;
            }

            void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
            {
                // should never happen
                if (!_summonsCount)
                    return;

                --_summonsCount;

                // All summons dead and no summon events scheduled
                if (!_summonsCount && _events.Empty())
                {
                    if (Creature* jainaOrSylvanas = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ESCAPE_LEADER)))
                        jainaOrSylvanas->AI()->DoAction(ACTION_WALL_BROKEN);
                }
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    DoPlaySoundToSet(me, RAND(SOUND_LK_SLAY_1, SOUND_LK_SLAY_2));
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type != DATA_ICEWALL)
                    return;

                _icewall = data;

                switch (_icewall)
                {
                    case 0: // 6 Ghouls, 1 Witch Doctor
                        DoZoneInCombat();
                        _events.ScheduleEvent(EVENT_REMORSELESS_WINTER, 0);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_GHOULS, 8000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_WITCH_DOCTOR, 14000);
                        Talk(SAY_LK_ESCAPE_ICEWALL_SUMMONED_1);
                        break;
                    case 1: // 6 Ghouls, 2 Witch Doctor, 1 Lumbering Abomination
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_GHOULS, 8000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_LUMBERING_ABOMINATION, 13000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_WITCH_DOCTOR, 16000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_WITCH_DOCTOR, 18000);
                        Talk(SAY_LK_ESCAPE_ICEWALL_SUMMONED_2);
                        break;
                    case 2: // 6 Ghouls, 2 Witch Doctor, 2 Lumbering Abomination
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_GHOULS, 9000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_LUMBERING_ABOMINATION, 14000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_WITCH_DOCTOR, 17000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_LUMBERING_ABOMINATION, 19000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_WITCH_DOCTOR, 39000);
                        Talk(SAY_LK_ESCAPE_ICEWALL_SUMMONED_3);
                        break;
                    case 3: // 12 Ghouls, 4 Witch Doctor, 3 Lumbering Abomination
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_GHOULS, 9000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_WITCH_DOCTOR, 17000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_WITCH_DOCTOR, 19000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_LUMBERING_ABOMINATION, 40000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_LUMBERING_ABOMINATION, 46000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_GHOULS, 55000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_WITCH_DOCTOR, 62000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_WITCH_DOCTOR, 66000);
                        _events.ScheduleEvent(EVENT_ESCAPE_SUMMON_LUMBERING_ABOMINATION, 14000);
                        Talk(SAY_LK_ESCAPE_ICEWALL_SUMMONED_4);
                        break;
                    default:
                        break;
                }
            }

            void EnterEvadeMode() override
            {
                if (_despawn)
                    return;

                _instance->SetBossState(DATA_THE_LICH_KING_ESCAPE, FAIL);
                me->StopMoving();
                DoPlaySoundToSet(me, SOUND_LK_FURY_OF_FROSTMOURNE);
                DoCastAOE(SPELL_FURY_OF_FROSTMOURNE);
                me->DespawnOrUnsummon(12000);
                _despawn = true;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!SelectVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 event = _events.ExecuteEvent())
                {
                    switch (event)
                    {
                        case EVENT_REMORSELESS_WINTER:
                            me->StopMoving();
                            Talk(SAY_LK_ESCAPE_WINTER);
                            DoCast(me, SPELL_REMORSELESS_WINTER);
                            break;
                        case EVENT_ESCAPE_SUMMON_GHOULS:
                            me->StopMoving();
                            Talk(SAY_LK_ESCAPE_GHOULS);
                            DoCast(me, SPELL_RAISE_DEAD);
                            break;
                        case EVENT_ESCAPE_SUMMON_WITCH_DOCTOR:
                            DoCast(me, SPELL_SUMMON_RISEN_WITCH_DOCTOR);
                            break;
                        case EVENT_ESCAPE_SUMMON_LUMBERING_ABOMINATION:
                            Talk(SAY_LK_ESCAPE_ABOMINATION);
                            DoCast(me, SPELL_SUMMON_LUMBERING_ABOMINATION);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool SelectVictim()
            {
                if (!me->IsInCombat())
                    return false;

                if (!me->HasReactState(REACT_PASSIVE))
                {
                    if (Unit* victim = me->SelectVictim())
                        AttackStart(victim);
                    return me->GetVictim();
                }
                else if (me->getThreatManager().getThreatList().size() < 2 && me->HasAura(SPELL_REMORSELESS_WINTER))
                {
                    EnterEvadeMode();
                    return false;
                }

                return true;
            }

            InstanceScript* _instance;
            EventMap _events;
            uint8 _icewall;
            uint32 _summonsCount;
            bool _despawn;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<npc_the_lich_king_escape_horAI>(creature);
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
    AURA_HALLUCINATION                            = 72343,

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
    SPELL_ICE_SHOT                                = 72268
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
    EVENT_ICE_SHOT
};

struct npc_gauntlet_trash : public ScriptedAI
{
    npc_gauntlet_trash(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()), InternalWaveId(0) { }

    void Reset() override
    {
        me->CastSpell(me, SPELL_WELL_OF_SOULS, true);
        _events.Reset();
    }

    void EnterEvadeMode() override
    {
        if (_instance->GetData(DATA_WAVE_COUNT) != NOT_STARTED)
            _instance->SetData(DATA_WAVE_COUNT, NOT_STARTED);
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type)
            return;

        InternalWaveId = value;
    }

    uint32 GetData(uint32 type) const override
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
            npc_ghostly_priestAI(Creature* creature) : npc_gauntlet_trash(creature) { }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, urand(6000, 15000));
                _events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000);
                _events.ScheduleEvent(EVENT_COWER_IN_FEAR, 10000);
                _events.ScheduleEvent(EVENT_DARK_MENDING, 20000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (_events.ExecuteEvent())
                {
                    case EVENT_SHADOW_WORD_PAIN:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_SHADOW_WORD_PAIN);
                        _events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, urand(6000, 15000));
                        break;
                    case EVENT_CIRCLE_OF_DESTRUCTION:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 10.0f, true))
                            DoCast(target, SPELL_CIRCLE_OF_DESTRUCTION);
                        _events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000);
                        break;
                    case EVENT_COWER_IN_FEAR:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true))
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
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<npc_ghostly_priestAI>(creature);
        }
};

class npc_phantom_mage : public CreatureScript
{
    public:
        npc_phantom_mage() : CreatureScript("npc_phantom_mage") { }

        struct npc_phantom_mageAI : public npc_gauntlet_trash
        {
            npc_phantom_mageAI(Creature* creature) : npc_gauntlet_trash(creature) { }

            void EnterEvadeMode() override
            {
                if (!me->HasAura(AURA_HALLUCINATION))
                    npc_gauntlet_trash::EnterEvadeMode();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_FIREBALL, 3000);
                _events.ScheduleEvent(EVENT_FLAMESTRIKE, 6000);
                _events.ScheduleEvent(EVENT_FROSTBOLT, 9000);
                _events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 12000);
                _events.ScheduleEvent(EVENT_HALLUCINATION, 40000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (_events.ExecuteEvent())
                {
                    case EVENT_FIREBALL:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_FIREBALL);
                        _events.ScheduleEvent(EVENT_FIREBALL, 15000);
                        break;
                    case EVENT_FLAMESTRIKE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_FLAMESTRIKE);
                        _events.ScheduleEvent(EVENT_FLAMESTRIKE, 15000);
                        break;
                    case EVENT_FROSTBOLT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_FROSTBOLT);
                        _events.ScheduleEvent(EVENT_FROSTBOLT, 15000);
                        break;
                    case EVENT_CHAINS_OF_ICE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_CHAINS_OF_ICE);
                        _events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 15000);
                        break;
                    case EVENT_HALLUCINATION:
                        // removing any dots on mage or else the invisibility spell will break duration
                        me->RemoveAllAuras();
                        DoCast(me, SPELL_HALLUCINATION);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<npc_phantom_mageAI>(creature);
        }
};

class npc_phantom_hallucination : public CreatureScript
{
    public:
        npc_phantom_hallucination() : CreatureScript("npc_phantom_hallucination") { }

        struct npc_phantom_hallucinationAI : public npc_phantom_mage::npc_phantom_mageAI
        {
            npc_phantom_hallucinationAI(Creature* creature) : npc_phantom_mage::npc_phantom_mageAI(creature) { }

            void Reset() override
            {
                DoZoneInCombat(me, 150.0f);
            }

            void EnterEvadeMode() override
            {
                if (me->GetOwner() && !me->GetOwner()->HasAura(AURA_HALLUCINATION))
                    npc_phantom_mage::npc_phantom_mageAI::EnterEvadeMode();
            }

            void JustDied(Unit* /*killer*/) override
            {
                DoCastAOE(SPELL_HALLUCINATION_2);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
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
            npc_shadowy_mercenaryAI(Creature* creature) : npc_gauntlet_trash(creature) { }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_SHADOW_STEP, 23000);
                _events.ScheduleEvent(EVENT_DEADLY_POISON, 5000);
                _events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
                _events.ScheduleEvent(EVENT_KIDNEY_SHOT, 12000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (_events.ExecuteEvent())
                {
                    case EVENT_SHADOW_STEP:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(target, SPELL_SHADOW_STEP);
                        _events.ScheduleEvent(EVENT_SHADOW_STEP, 8000);
                        break;
                    case EVENT_DEADLY_POISON:
                        DoCastVictim(SPELL_DEADLY_POISON);
                        _events.ScheduleEvent(EVENT_DEADLY_POISON, 10000);
                        break;
                    case EVENT_ENVENOMED_DAGGER_THROW:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_ENVENOMED_DAGGER_THROW);
                        _events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
                        break;
                    case EVENT_KIDNEY_SHOT:
                        DoCastVictim(SPELL_KIDNEY_SHOT);
                        _events.ScheduleEvent(EVENT_KIDNEY_SHOT, 10000);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<npc_shadowy_mercenaryAI>(creature);
        }
};

class npc_spectral_footman : public CreatureScript
{
    public:
        npc_spectral_footman() : CreatureScript("npc_spectral_footman") { }

        struct npc_spectral_footmanAI : public npc_gauntlet_trash
        {
            npc_spectral_footmanAI(Creature* creature) : npc_gauntlet_trash(creature) { }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 14000);
                _events.ScheduleEvent(EVENT_SHIELD_BASH, 10000);
                _events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000);
            }

            void UpdateAI(uint32 diff) override
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
                        DoCast(me, SPELL_TORTURED_ENRAGE);
                        _events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<npc_spectral_footmanAI>(creature);
        }
};

class npc_tortured_rifleman : public CreatureScript
{
    public:
        npc_tortured_rifleman() : CreatureScript("npc_tortured_rifleman") { }

        struct npc_tortured_riflemanAI : public npc_gauntlet_trash
        {
            npc_tortured_riflemanAI(Creature* creature) : npc_gauntlet_trash(creature) { }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.ScheduleEvent(EVENT_SHOOT, 1);
                _events.ScheduleEvent(EVENT_CURSED_ARROW, 7000);
                _events.ScheduleEvent(EVENT_FROST_TRAP, 10000);
                _events.ScheduleEvent(EVENT_ICE_SHOT, 15000);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (_events.ExecuteEvent())
                {
                    case EVENT_SHOOT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_SHOOT);
                        _events.ScheduleEvent(EVENT_SHOOT, 2000);
                        break;
                    case EVENT_CURSED_ARROW:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_CURSED_ARROW);
                        _events.ScheduleEvent(EVENT_CURSED_ARROW, 10000);
                        break;
                    case EVENT_FROST_TRAP:
                        DoCast(me, SPELL_FROST_TRAP);
                        _events.ScheduleEvent(EVENT_FROST_TRAP, 30000);
                        break;
                    case EVENT_ICE_SHOT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            DoCast(target, SPELL_ICE_SHOT);
                        _events.ScheduleEvent(EVENT_ICE_SHOT, 15000);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<npc_tortured_riflemanAI>(creature);
        }
};

enum FrostswornGeneral
{
    // General
    EVENT_SHIELD                 = 1,
    EVENT_SPIKE                  = 2,
    EVENT_CLONE                  = 3,

    SAY_AGGRO                    = 0,
    SAY_DEATH                    = 1,

    SPELL_SHIELD_THROWN          = 69222,
    SPELL_SPIKE                  = 69184,
    SPELL_CLONE                  = 69828,
    SPELL_GHOST_VISUAL           = 69861,

    // Reflection
    EVENT_BALEFUL_STRIKE         = 1,

    SPELL_BALEFUL_STRIKE         = 69933,
    SPELL_SPIRIT_BURST           = 69900
};

class npc_frostsworn_general : public CreatureScript
{
    public:
        npc_frostsworn_general() : CreatureScript("npc_frostsworn_general") { }

        struct npc_frostsworn_generalAI : public ScriptedAI
        {
            npc_frostsworn_generalAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                _events.Reset();
                _instance->SetData(DATA_FROSTSWORN_GENERAL, NOT_STARTED);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _events.Reset();
                _instance->SetData(DATA_FROSTSWORN_GENERAL, DONE);
            }

            void EnterCombat(Unit* /*victim*/) override
            {
                Talk(SAY_AGGRO);
                DoZoneInCombat();
                _events.ScheduleEvent(EVENT_SHIELD, 5000);
                _events.ScheduleEvent(EVENT_SPIKE, 14000);
                _events.ScheduleEvent(EVENT_CLONE, 22000);
                _instance->SetData(DATA_FROSTSWORN_GENERAL, IN_PROGRESS);
            }

            void UpdateAI(uint32 diff) override
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
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                                DoCast(target, SPELL_SHIELD_THROWN);
                            _events.ScheduleEvent(EVENT_SHIELD, urand(8000, 12000));
                            break;
                        case EVENT_SPIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                                DoCast(target, SPELL_SPIKE);
                            _events.ScheduleEvent(EVENT_SPIKE, urand(15000, 20000));
                            break;
                        case EVENT_CLONE:
                            SummonClones();
                            _events.ScheduleEvent(EVENT_CLONE, 60000);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

            void SummonClones()
            {
                std::list<Unit*> playerList;
                SelectTargetList(playerList, 5, SELECT_TARGET_TOPAGGRO, 0.0f, true);
                for (Unit* target : playerList)
                {
                    if (Creature* reflection = me->SummonCreature(NPC_REFLECTION, *target, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000))
                    {
                        target->CastSpell(reflection, SPELL_CLONE, true);
                        target->CastSpell(reflection, SPELL_GHOST_VISUAL, true);
                        reflection->AI()->AttackStart(target);
                    }
                }
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<npc_frostsworn_generalAI>(creature);
        }
};

class npc_spiritual_reflection : public CreatureScript
{
    public:
        npc_spiritual_reflection() : CreatureScript("npc_spiritual_reflection") { }

        struct npc_spiritual_reflectionAI : public ScriptedAI
        {
            npc_spiritual_reflectionAI(Creature *creature) : ScriptedAI(creature) { }

            void Reset() override
            {
                _events.Reset();
            }

            void EnterCombat(Unit* /*victim*/) override
            {
                _events.ScheduleEvent(EVENT_BALEFUL_STRIKE, 3000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                DoCastAOE(SPELL_SPIRIT_BURST);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (_events.ExecuteEvent())
                {
                    case EVENT_BALEFUL_STRIKE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 8.0f, true))
                            DoCast(target, SPELL_BALEFUL_STRIKE);
                        _events.ScheduleEvent(EVENT_BALEFUL_STRIKE, urand(3000, 8000));
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_spiritual_reflectionAI(creature);
        }
};

// 5689
class at_hor_intro_start : public AreaTriggerScript
{
    public:
        at_hor_intro_start() : AreaTriggerScript("at_hor_intro_start") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/) override
        {
            if (player->IsGameMaster())
                return true;

            InstanceScript* _instance = player->GetInstanceScript();

            if (_instance->GetData(DATA_INTRO_EVENT) == NOT_STARTED)
                _instance->SetData(DATA_INTRO_EVENT, IN_PROGRESS);

            return true;
        }
};

class at_hor_waves_restarter : public AreaTriggerScript
{
    public:
        at_hor_waves_restarter() : AreaTriggerScript("at_hor_waves_restarter") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/) override
        {
            if (player->IsGameMaster())
                return true;

            InstanceScript* _instance = player->GetInstanceScript();

            if (_instance->GetData(DATA_WAVE_COUNT))
                return true;

            if (_instance->GetData(DATA_INTRO_EVENT) == DONE && _instance->GetBossState(DATA_MARWYN) != DONE)
            {
                _instance->ProcessEvent(0, EVENT_SPAWN_WAVES);

                if (Creature* falric = ObjectAccessor::GetCreature(*player, _instance->GetData64(DATA_FALRIC)))
                {
                    falric->CastSpell(falric, SPELL_BOSS_SPAWN_AURA, true);
                    falric->SetVisible(true);
                }
                if (Creature* marwyn = ObjectAccessor::GetCreature(*player, _instance->GetData64(DATA_MARWYN)))
                {
                    marwyn->CastSpell(marwyn, SPELL_BOSS_SPAWN_AURA, true);
                    marwyn->SetVisible(true);
                }
            }
            return true;
        }
};

// 5740
class at_hor_impenetrable_door : public AreaTriggerScript
{
    public:
        at_hor_impenetrable_door() : AreaTriggerScript("at_hor_impenetrable_door") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
        {
            if (player->IsGameMaster())
                return true;

            InstanceScript* _instance = player->GetInstanceScript();
            if (_instance->GetBossState(DATA_MARWYN) == DONE)
                return true;

            /// return false to handle teleport by db
            return false;
        }
};

// 5605
class at_hor_shadow_throne : public AreaTriggerScript
{
    public:
        at_hor_shadow_throne() : AreaTriggerScript("at_hor_shadow_throne") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*at*/) override
        {
            if (player->IsGameMaster())
                return true;

            InstanceScript* _instance = player->GetInstanceScript();

            if (_instance->GetBossState(DATA_THE_LICH_KING_ESCAPE) == NOT_STARTED)
                _instance->SetBossState(DATA_THE_LICH_KING_ESCAPE, IN_PROGRESS);

            return true;
        }
};

enum EscapeEvents
{
    // Raging Ghoul
    EVENT_RAGING_GHOUL_JUMP = 1,

    // Risen Witch Doctor
    EVENT_RISEN_WITCH_DOCTOR_CURSE,
    EVENT_RISEN_WITCH_DOCTOR_SHADOW_BOLT,
    EVENT_RISEN_WITCH_DOCTOR_SHADOW_BOLT_VOLLEY,

    // Lumbering Abomination
    EVENT_LUMBERING_ABOMINATION_VOMIT_SPRAY,
    EVENT_LUMBERING_ABOMINATION_CLEAVE
};

namespace hor
{

class StartMovementEvent : public BasicEvent
{
    public:
        StartMovementEvent(Creature* owner) : _owner(owner) { }

        bool Execute(uint64 /*execTime*/, uint32 /*diff*/) override
        {
            _owner->SetReactState(REACT_AGGRESSIVE);
            if (Unit* target = _owner->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                _owner->AI()->AttackStart(target);
            return true;
        }

    private:
        Creature* _owner;
};

} // namespace hor

struct npc_escape_event_trash : public ScriptedAI
{
    npc_escape_event_trash(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (_instance->GetBossState(DATA_THE_LICH_KING_ESCAPE) == FAIL || _instance->GetBossState(DATA_THE_LICH_KING_ESCAPE) == NOT_STARTED)
            me->DespawnOrUnsummon();
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoZoneInCombat(me, 0.0f);
        if (Creature* leader = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ESCAPE_LEADER)))
        {
            me->SetInCombatWith(leader);
            leader->SetInCombatWith(me);
            me->AddThreat(leader, 0.0f);
        }
    }

protected:
    EventMap _events;
    InstanceScript* _instance;
};

class npc_raging_ghoul : public CreatureScript
{
    public:
        npc_raging_ghoul() : CreatureScript("npc_raging_ghoul") { }

        struct npc_raging_ghoulAI : public npc_escape_event_trash
        {
            npc_raging_ghoulAI(Creature* creature) : npc_escape_event_trash(creature) { }

            void Reset() override
            {
                npc_escape_event_trash::Reset();
                _events.ScheduleEvent(EVENT_RAGING_GHOUL_JUMP, 5000);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                me->CastSpell(me, SPELL_RAGING_GHOUL_SPAWN, true);
                me->SetReactState(REACT_PASSIVE);
                me->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                me->m_Events.AddEvent(new hor::StartMovementEvent(me), me->m_Events.CalculateTime(5000));

                npc_escape_event_trash::IsSummonedBy(summoner);
            }

            void UpdateAI(uint32 diff) override
            {
                npc_escape_event_trash::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (_events.ExecuteEvent())
                {
                    case EVENT_RAGING_GHOUL_JUMP:
                        if (Unit* victim = me->GetVictim())
                        {
                            if (me->IsInRange(victim, 5.0f, 30.0f))
                            {
                                DoCast(victim, SPELL_GHOUL_JUMP);
                                return;
                            }
                        }
                        _events.ScheduleEvent(EVENT_RAGING_GHOUL_JUMP, 500);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<npc_raging_ghoulAI>(creature);
        }
};

class npc_risen_witch_doctor : public CreatureScript
{
    public:
        npc_risen_witch_doctor() : CreatureScript("npc_risen_witch_doctor") { }

        struct npc_risen_witch_doctorAI : public npc_escape_event_trash
        {
            npc_risen_witch_doctorAI(Creature* creature) : npc_escape_event_trash(creature) { }

            void Reset() override
            {
                npc_escape_event_trash::Reset();
                _events.ScheduleEvent(EVENT_RISEN_WITCH_DOCTOR_SHADOW_BOLT, 6000);
                _events.ScheduleEvent(EVENT_RISEN_WITCH_DOCTOR_SHADOW_BOLT_VOLLEY, 15000);
                _events.ScheduleEvent(EVENT_RISEN_WITCH_DOCTOR_CURSE, 7000);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                me->CastSpell(me, SPELL_RISEN_WITCH_DOCTOR_SPAWN, true);
                me->SetReactState(REACT_PASSIVE);
                me->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                me->m_Events.AddEvent(new hor::StartMovementEvent(me), me->m_Events.CalculateTime(5000));

                npc_escape_event_trash::IsSummonedBy(summoner);
            }

            void UpdateAI(uint32 diff) override
            {
                npc_escape_event_trash::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (_events.ExecuteEvent())
                {
                    case EVENT_RISEN_WITCH_DOCTOR_CURSE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                            DoCast(target, SPELL_CURSE_OF_DOOM);
                        _events.ScheduleEvent(EVENT_RISEN_WITCH_DOCTOR_CURSE, urand(10000, 15000));
                        break;
                    case EVENT_RISEN_WITCH_DOCTOR_SHADOW_BOLT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 20.0f, true))
                            DoCast(target, SPELL_SHADOW_BOLT);
                        _events.ScheduleEvent(EVENT_RISEN_WITCH_DOCTOR_SHADOW_BOLT, urand(2000, 3000));
                        break;
                    case EVENT_RISEN_WITCH_DOCTOR_SHADOW_BOLT_VOLLEY:
                        if (SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                            DoCastAOE(SPELL_SHADOW_BOLT_VOLLEY);
                        _events.ScheduleEvent(EVENT_RISEN_WITCH_DOCTOR_SHADOW_BOLT_VOLLEY, urand(15000, 22000));
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<npc_risen_witch_doctorAI>(creature);
        }
};

class npc_lumbering_abomination : public CreatureScript
{
    public:
        npc_lumbering_abomination() : CreatureScript("npc_lumbering_abomination") { }

        struct npc_lumbering_abominationAI : public npc_escape_event_trash
        {
            npc_lumbering_abominationAI(Creature* creature) : npc_escape_event_trash(creature) { }

            void Reset() override
            {
                npc_escape_event_trash::Reset();
                _events.ScheduleEvent(EVENT_LUMBERING_ABOMINATION_VOMIT_SPRAY, 15000);
                _events.ScheduleEvent(EVENT_LUMBERING_ABOMINATION_CLEAVE, 6000);
            }

            void UpdateAI(uint32 diff) override
            {
                npc_escape_event_trash::UpdateAI(diff);

                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (_events.ExecuteEvent())
                {
                    case EVENT_LUMBERING_ABOMINATION_VOMIT_SPRAY:
                        DoCastVictim(SPELL_VOMIT_SPRAY);
                        _events.ScheduleEvent(EVENT_LUMBERING_ABOMINATION_VOMIT_SPRAY, urand(15000, 20000));
                        break;
                    case EVENT_LUMBERING_ABOMINATION_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        _events.ScheduleEvent(EVENT_LUMBERING_ABOMINATION_CLEAVE, urand(7000, 9000));
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<npc_lumbering_abominationAI>(creature);
        }
};

// 72900 - Start Halls of Reflection Quest AE
class spell_hor_start_halls_of_reflection_quest_ae : public SpellScriptLoader
{
    public:
        spell_hor_start_halls_of_reflection_quest_ae() : SpellScriptLoader("spell_hor_start_halls_of_reflection_quest_ae") { }

        class spell_hor_start_halls_of_reflection_quest_ae_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hor_start_halls_of_reflection_quest_ae_SpellScript);

            void StartQuests(SpellEffIndex /*effIndex*/)
            {
                if (Player* target = GetHitPlayer())
                {
                    // CanTakeQuest and CanAddQuest checks done in spell effect execution
                    if (target->GetTeam() == ALLIANCE)
                        target->CastSpell(target, SPELL_START_HALLS_OF_REFLECTION_QUEST_A, true);
                    else
                        target->CastSpell(target, SPELL_START_HALLS_OF_REFLECTION_QUEST_H, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hor_start_halls_of_reflection_quest_ae_SpellScript::StartQuests, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hor_start_halls_of_reflection_quest_ae_SpellScript();
        }
};

// 70190 - Evasion
class spell_hor_evasion : public SpellScriptLoader
{
    public:
        spell_hor_evasion() : SpellScriptLoader("spell_hor_evasion") { }

        class spell_hor_evasion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hor_evasion_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void SetDest(SpellDestination& dest)
            {
                WorldObject* target = GetExplTargetWorldObject();
                Position pos(*target);
                Position home = GetCaster()->ToCreature()->GetHomePosition();

                // prevent evasion outside the room
                if (pos.IsInDist2d(&home, 15.0f))
                    return;

                float angle = pos.GetAngle(&home);
                float dist = GetSpellInfo()->Effects[EFFECT_0].CalcRadius(GetCaster());
                target->MovePosition(pos, dist, angle);

                dest.Relocate(pos);
            }

            void Register() override
            {
                OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_hor_evasion_SpellScript::SetDest, EFFECT_0, TARGET_DEST_TARGET_RADIUS);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hor_evasion_SpellScript();
        }
};

// 70017 - Gunship Cannon Fire
class spell_hor_gunship_cannon_fire : public SpellScriptLoader
{
    public:
        spell_hor_gunship_cannon_fire() : SpellScriptLoader("spell_hor_gunship_cannon_fire") { }

        class spell_hor_gunship_cannon_fire_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hor_gunship_cannon_fire_AuraScript);

            void HandlePeriodic(AuraEffect const* /*aurEff*/)
            {
                if (!urand(0, 2))
                {
                    if (GetTarget()->GetEntry() == NPC_GUNSHIP_CANNON_HORDE)
                        GetTarget()->CastSpell((Unit*)NULL, SPELL_GUNSHIP_CANNON_FIRE_MISSILE_HORDE, true);
                    else
                        GetTarget()->CastSpell((Unit*)NULL, SPELL_GUNSHIP_CANNON_FIRE_MISSILE_ALLIANCE, true);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_hor_gunship_cannon_fire_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_hor_gunship_cannon_fire_AuraScript();
        }
};

void AddSC_halls_of_reflection()
{
    new at_hor_intro_start();
    new at_hor_waves_restarter();
    new at_hor_impenetrable_door();
    new at_hor_shadow_throne();
    new npc_jaina_or_sylvanas_intro_hor();
    new npc_jaina_or_sylvanas_escape_hor();
    new npc_the_lich_king_escape_hor();
    new npc_ghostly_priest();
    new npc_phantom_mage();
    new npc_phantom_hallucination();
    new npc_shadowy_mercenary();
    new npc_spectral_footman();
    new npc_tortured_rifleman();
    new npc_frostsworn_general();
    new npc_spiritual_reflection();
    new npc_raging_ghoul();
    new npc_risen_witch_doctor();
    new npc_lumbering_abomination();
    new spell_hor_start_halls_of_reflection_quest_ae();
    new spell_hor_evasion();
    new spell_hor_gunship_cannon_fire();
}
