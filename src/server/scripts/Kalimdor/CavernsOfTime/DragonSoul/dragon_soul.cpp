/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2014-2018 RoG_WoW Source <http://wow.rog.snet>
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
#include "dragon_soul.h"
#include "PhasingHandler.h"
#include "GameObject.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "Vehicle.h"

enum Adds
{
    NPC_TIME_WARDEN_1               = 56142,
    NPC_TIME_WARDEN_2               = 57474,
    NPC_DREAM_WARDEN                = 56140,
    NPC_LIFE_WARDEN_1               = 56139,
    NPC_LIFE_WARDEN_2               = 57473,
    NPC_FACELESS_DESTROYER          = 57746,
    NPC_FACELESS_CORRUPTOR          = 57749,
    NPC_RUIN_TENTACLE               = 57751,
    NPC_DREAM_WARDEN_1              = 56140,
    NPC_DREAM_WARDEN_2              = 57475,
    NPC_TWILIGHT_ASSAULTER_1        = 56249,
    NPC_TWILIGHT_ASSAULTER_2        = 56250,
    NPC_TWILIGHT_ASSAULTER_3        = 56251,
    NPC_TWILIGHT_ASSAULTER_4        = 56252,
    NPC_TWILIGHT_ASSAULTER_5        = 57795,

    NPC_ANCIENT_WATER_LORD          = 57160,
    NPC_EARTHEN_DESTROYER           = 57158,
    NPC_EARTHEN_SOLDIER             = 57159,
    NPC_TWILIGHT_SIEGE_CAPTAIN      = 57280,
    NPC_TWILIGHT_PORTAL             = 57231,

    NPC_CRIMSON_GLOBULE             = 57386,
    NPC_ACIDIC_GLOBULE              = 57333,
    NPC_GLOWING_GLOBULE             = 57387,
    NPC_DARK_GLOBULE                = 57382,
    NPC_SHADOWED_GLOBULE            = 57388,
    NPC_COBALT_GLOBULE              = 57384,

    NPC_FLAIL_OF_GORATH             = 57877,
    NPC_CLAW_OF_GORATH              = 57890,
    NPC_TENTACLE_TOSS_STALKER       = 57836,
    NPC_EYE_OF_GORATH               = 57875,
};

enum Spells
{
    // Ancient Water Lord
    SPELL_DRENCHED                  = 107801,
    SPELL_FLOOD_AOE                 = 107796,
    SPELL_FLOOD                     = 107797,
    SPELL_FLOOD_CHANNEL             = 107791,

    // Earthen Destroyer
    SPELL_BOULDER_SMASH_AOE         = 107596,
    SPELL_BOULDER_SMASH             = 107597,
    SPELL_DUST_STORM                = 107682,

    // Earthen Soldier
    SPELL_ZERO_POWER                = 78725,
    SPELL_SHADOW_BOLT               = 95440,
    SPELL_TWILIGHT_CORRUPTION       = 107852,
    SPELL_TWILIGHT_RAGE             = 107872,

    // Twilight Siege Captain
    SPELL_TWILIGHT_SUBMISSION       = 108183,
    SPELL_TWILIGHT_VOLLEY           = 108172,
    SPELL_TWILIGHT_PORTAL_BEAM      = 108096,

    // Crimson Globule
    SPELL_CRIMSON_BLOOD_OF_SHUMA    = 110750,
    SPELL_SEARING_BLOOD             = 108218,

    // Acidic Globule
    SPELL_ACIDIC_BLOOD_OF_SHUMA     = 110743,
    SPELL_DIGESTIVE_ACID            = 108419,

    // Glowing Globule
    SPELL_GLOWING_BLOOD_OF_SHUMA_1  = 110753, // dummy
    SPELL_GLOWING_BLOOD_OF_SHUMA_2  = 108221, // haste

    // Dark Globule
    SPELL_BLACK_BLOOD_OF_SHUMA      = 110746,
    SPELL_PSYCHIC_SLICE             = 105671,

    // Shadowed Globule
    SPELL_SHADOWED_BLOOD_OF_SHUMA   = 110748,
    SPELL_DEEP_CORRUPTION           = 108220,
    SPELL_DEEP_CORRUPTION_AURA      = 109389,
    SPELL_DEEP_CORRUPTION_DMG       = 109390,

    // Cobalt Globule
    SPELL_COBALT_BLOOD_OF_SHUMA     = 110747,
    SPELL_MANA_VOID                 = 108223,
    SPELL_MANA_VOID_BURN            = 108222,
    SPELL_MANA_VOID_DUMMY           = 108224, // calculate power
    SPELL_MANA_DIFFUSION            = 108228,

    // Flail of Go'rath
    SPELL_SLUDGE_SPEW               = 110102,
    SPELL_WILD_FLAIL                = 109199,
    SPELL_BLOOD_OF_GORATH_DUMMY_1   = 109352,

    // Claw of Go'rath
    SPELL_OOZE_SPIT                 = 109396,
    SPELL_TENTACLE_TOSS_AOE_1       = 109197, // select target for picking up
    SPELL_TENTACLE_TOSS_SCRIPT_1    = 109233, // pick up
    SPELL_TENTECLE_TOSS_VEHICLE     = 109214,
    SPELL_TENTACLE_TOSS_AOE_2       = 109237, // select target to toss
    SPELL_TENTACLE_TOSS_SUMMON      = 109238,
    SPELL_TENTACLE_TOSS_SCRIPT_2    = 109243,
    SPELL_TENTACLE_TOSS_FORCE       = 109241,
    SPELL_TENTACLE_TOSS_JUMP        = 109240,
    SPELL_TENTACLE_TOSS_DMG         = 109258,
    SPELL_BLOOD_OF_GORATH_DUMMY_2   = 109365,

    // Eye of Go'rath
    SPELL_SHADOW_GAZE               = 109391,
    SPELL_BLOOD_OF_GORATH_DUMMY_3   = 103932,

    //Wyrmrest Event
    SPELL_DEFEND_WYRMREST           = 107576,
    SPELL_ATTACK_WYRMREST           = 107577,
    SPELL_FLAME_BREATH                = 95681,
    SPELL_TWILIGHT_BREATH            = 95692,
    SPELL_MOLTEN_METEOR_DW          = 105022,
};

enum Events
{
    // Ancient Water Lord
    EVENT_DRENCHED              = 1,
    EVENT_FLOOD                 = 2,

    // Earthen Destroyer
    EVENT_BOULDER_SMASH         = 3,
    EVENT_DUST_STORM            = 4,

    // Earthen Soldier
    EVENT_SHADOW_BOLT           = 5,
    EVENT_TWILIGHT_CORRUPTION   = 6,

    // Twilight Siege Captain
    EVENT_TWILIGHT_VOLLEY       = 7,
    EVENT_TWILIGHT_SUBMISSION   = 8,

    // Twilight Portal
    EVENT_CHECK_PLAYERS         = 9,

    // Crimson Globule
    EVENT_SEARING_BLOOD         = 10,

    // Acidic Globule
    EVENT_DIGESTIVE_ACID        = 11,

    // Dark Globule
    EVENT_PSYCHIC_SLICE         = 12,

    // Shadowed Globule
    EVENT_DEEP_CORRUPTION       = 13,

    // Cobalt Globule
    EVENT_MANA_VOID             = 14,

    // Flail of Go'rath
    EVENT_SLUDGE_SPEW           = 15,
    EVENT_WILD_FLAIL            = 16,

    // Claw of Go'rath
    EVENT_OOZE_SPIT             = 16,
    EVENT_TENTACLE_TOSS         = 17,
    EVENT_TENTACLE_TOSS_VEHICLE = 18,
    EVENT_TENTACLE_TOSS_LAUNCH  = 19,

    // Eye of Go'rath
    EVENT_SHADOW_GAZE           = 20,

    // Thrall
    EVENT_TALK_ULTRAXION_WIN_1  = 21,
    EVENT_TALK_ULTRAXION_WIN_2  = 22,
    EVENT_SPAWN_SHIP            = 23,
    EVENT_SPAWN_NPC             = 24,

    //Dragon Wyrmrest
    EVENT_START_ATTACK          = 25,
    EVENT_MOVE_AROUND           = 26,
    EVENT_ACTION_REPEAT         = 27,
    EVENT_TWILIGHT_BREATH       = 28,
    EVENT_DEATHWING_SIEGE       = 29,
};

enum Actions
{
    ACTION_ULTRAXION_WIN    = 1,
};

enum Points
{
    POINT_DEATHWING_1 = 1,
    POINT_DEATHWING_2 = 2,
    POINT_DEATHWING_3 = 3,
    POINT_DEATHWING_4 = 4,
    POINT_DEATHWING_5 = 5,
    POINT_DEATHWING_6 = 6,
    POINT_DEATHWING_7 = 7,
    POINT_DEATHWING_8 = 8,
    POINT_DEATHWING_9 = 9,
    POINT_DEATHWING_10 = 10,
    POINT_DEATHWING_11 = 11,
    POINT_DEATHWING_12 = 12,
};


const Position DeathwingSiege[12] =
{
    { -1969.16f, -2379.87f, 243.93f, 6.14057f },
    { -1935.50f, -2502.21f, 204.95f, 5.87592f },
    { -1826.41f, -2597.81f, 267.58f, 0.69333f },
    { -1655.68f, -2577.24f, 227.80f, 2.05207f },
    { -1585.79f, -2480.94f, 201.33f, 2.85318f },
    { -1583.75f, -2386.00f, 259.68f, 3.32834f },
    { -1617.22f, -2239.97f, 241.06f, 3.96845f },
    { -1717.91f, -2217.45f, 233.04f, 4.46717f },
    { -1809.89f, -2188.79f, 174.59f, 4.80096f },
    { -1892.86f, -2231.99f, 189.19f, 5.38216f },
    { -1954.47f, -2349.66f, 294.99f, 4.30165f },
    { -1921.95f, -2452.96f, 283.69f, 6.12116f },
};

class npc_dragon_soul_ancient_water_lord : public CreatureScript
{
    public:
        npc_dragon_soul_ancient_water_lord() : CreatureScript("npc_dragon_soul_ancient_water_lord") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_ancient_water_lordAI (pCreature);
        }

        struct npc_dragon_soul_ancient_water_lordAI : public ScriptedAI
        {
            npc_dragon_soul_ancient_water_lordAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_FLOOD, urand(8000, 12000));
                events.ScheduleEvent(EVENT_DRENCHED, urand(3000, 6000));
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DRENCHED:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(pTarget, SPELL_DRENCHED);
                            events.ScheduleEvent(EVENT_DRENCHED, urand(13000, 15000));
                            break;
                        case EVENT_FLOOD:
                            DoCastAOE(SPELL_FLOOD_AOE);
                            events.ScheduleEvent(EVENT_FLOOD, urand(18000, 25000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_dragon_soul_earthen_destroyer : public CreatureScript
{
    public:
        npc_dragon_soul_earthen_destroyer() : CreatureScript("npc_dragon_soul_earthen_destroyer") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_earthen_destroyerAI (pCreature);
        }

        struct npc_dragon_soul_earthen_destroyerAI : public ScriptedAI
        {
            npc_dragon_soul_earthen_destroyerAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_BOULDER_SMASH, urand(3000, 5000));
                events.ScheduleEvent(EVENT_DUST_STORM, urand(7000, 11000));
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BOULDER_SMASH:
                            DoCastAOE(SPELL_BOULDER_SMASH_AOE);
                            events.ScheduleEvent(EVENT_BOULDER_SMASH, urand(6000, 7000));
                            break;
                        case EVENT_DUST_STORM:
                            DoCast(me, SPELL_DUST_STORM);
                            events.ScheduleEvent(EVENT_DUST_STORM, urand(15000, 20000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_dragon_soul_earthen_soldier : public CreatureScript
{
    public:
        npc_dragon_soul_earthen_soldier() : CreatureScript("npc_dragon_soul_earthen_soldier") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_earthen_soldierAI (pCreature);
        }

        struct npc_dragon_soul_earthen_soldierAI : public ScriptedAI
        {
            npc_dragon_soul_earthen_soldierAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            EventMap events;

            void Reset() override
            {
                DoCast(me, SPELL_ZERO_POWER, true);
                me->SetPowerType(POWER_ENERGY);
                me->SetMaxPower(POWER_ENERGY, 0);
                me->SetPower(POWER_ENERGY, 0);
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(3000, 5000));
                events.ScheduleEvent(EVENT_TWILIGHT_CORRUPTION, urand(6000, 7000));
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (me->GetPower(POWER_ENERGY) == 100)
                {
                    DoCast(me, SPELL_TWILIGHT_RAGE);
                    return;
                }

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHADOW_BOLT:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(pTarget, SPELL_SHADOW_BOLT);
                            events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(6000, 9000));
                            break;
                        case EVENT_TWILIGHT_CORRUPTION:
                            DoCast(me, SPELL_TWILIGHT_CORRUPTION);
                            events.ScheduleEvent(EVENT_TWILIGHT_CORRUPTION, urand(12000, 14000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_dragon_soul_twilight_siege_captain : public CreatureScript
{
    public:
        npc_dragon_soul_twilight_siege_captain() : CreatureScript("npc_dragon_soul_twilight_siege_captain") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_twilight_siege_captainAI (pCreature);
        }

        struct npc_dragon_soul_twilight_siege_captainAI : public ScriptedAI
        {
            npc_dragon_soul_twilight_siege_captainAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            EventMap events;

            void Reset() override
            {
                if (Creature* portal = me->FindNearestCreature(NPC_TWILIGHT_PORTAL, 30.0f, false))
                {
                    if (portal->isDead())
                        portal->Respawn();
                }

                if (Creature* portal = me->FindNearestCreature(NPC_TWILIGHT_PORTAL, 30.0f, true))
                {
                    me->CastSpell(portal, SPELL_TWILIGHT_PORTAL_BEAM, true);
                }

                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                me->CastStop();
                events.ScheduleEvent(EVENT_TWILIGHT_VOLLEY, urand(3000, 5000));
                events.ScheduleEvent(EVENT_TWILIGHT_SUBMISSION, urand(10000, 12000));
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TWILIGHT_VOLLEY:
                            DoCastAOE(SPELL_TWILIGHT_VOLLEY);
                            events.ScheduleEvent(EVENT_TWILIGHT_VOLLEY, urand(5000, 10000));
                            break;
                        case EVENT_TWILIGHT_SUBMISSION:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(pTarget, SPELL_TWILIGHT_SUBMISSION);
                            events.ScheduleEvent(EVENT_TWILIGHT_SUBMISSION, urand(7000, 10000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_dragon_soul_twilight_portal : public CreatureScript
{
    public:
        npc_dragon_soul_twilight_portal() : CreatureScript("npc_dragon_soul_twilight_portal") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_twilight_portalAI (pCreature);
        }

        struct npc_dragon_soul_twilight_portalAI : public Scripted_NoMovementAI
        {
            npc_dragon_soul_twilight_portalAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_CHECK_PLAYERS, 5000);
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                if (!me->HasAura(SPELL_TWILIGHT_PORTAL_BEAM))
                    me->DespawnOrUnsummon();

                events.Update(diff);

                if (events.ExecuteEvent())
                {
                    if (!SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f))
                    {
                        events.Reset();
                        EnterEvadeMode();
                    }
                    else
                        events.ScheduleEvent(EVENT_CHECK_PLAYERS, 5000);
                }
            }
        };
};

class npc_dragon_soul_crimson_globule : public CreatureScript
{
    public:
        npc_dragon_soul_crimson_globule() : CreatureScript("npc_dragon_soul_crimson_globule") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_crimson_globuleAI (pCreature);
        }

        struct npc_dragon_soul_crimson_globuleAI : public ScriptedAI
        {
            npc_dragon_soul_crimson_globuleAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_SEARING_BLOOD, urand(7000, 14000));
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (events.ExecuteEvent())
                {
                    me->CastCustomSpell(SPELL_SEARING_BLOOD, SPELLVALUE_MAX_TARGETS, RAID_MODE(3, 8), me);
                    events.ScheduleEvent(EVENT_SEARING_BLOOD, (me->HasAura(SPELL_GLOWING_BLOOD_OF_SHUMA_2) ? 7000 : 14000));
                }

                DoMeleeAttackIfReady();
            }
        private:
            EventMap events;
        };
};

class npc_dragon_soul_acidic_globule : public CreatureScript
{
    public:
        npc_dragon_soul_acidic_globule() : CreatureScript("npc_dragon_soul_acidic_globule") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_acidic_globuleAI (pCreature);
        }

        struct npc_dragon_soul_acidic_globuleAI : public ScriptedAI
        {
            npc_dragon_soul_acidic_globuleAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_DIGESTIVE_ACID, urand(7000, 14000));
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (events.ExecuteEvent())
                {
                    DoCastAOE(SPELL_DIGESTIVE_ACID);
                    events.ScheduleEvent(EVENT_DIGESTIVE_ACID, (me->HasAura(SPELL_GLOWING_BLOOD_OF_SHUMA_2) ? 7000 : 14000));
                }

                DoMeleeAttackIfReady();
            }
        private:
            EventMap events;
        };
};

class npc_dragon_soul_dark_globule : public CreatureScript
{
    public:
        npc_dragon_soul_dark_globule() : CreatureScript("npc_dragon_soul_dark_globule") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_dark_globuleAI (pCreature);
        }

        struct npc_dragon_soul_dark_globuleAI : public ScriptedAI
        {
            npc_dragon_soul_dark_globuleAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_PSYCHIC_SLICE, urand(7000, 14000));
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (events.ExecuteEvent())
                {
                    DoCastVictim(SPELL_PSYCHIC_SLICE);
                    events.ScheduleEvent(EVENT_PSYCHIC_SLICE, (me->HasAura(SPELL_GLOWING_BLOOD_OF_SHUMA_2) ? 7000 : 14000));
                }

                DoMeleeAttackIfReady();
            }
        private:
            EventMap events;
        };
};

class npc_dragon_soul_shadowed_globule : public CreatureScript
{
    public:
        npc_dragon_soul_shadowed_globule() : CreatureScript("npc_dragon_soul_shadowed_globule") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_shadowed_globuleAI (pCreature);
        }

        struct npc_dragon_soul_shadowed_globuleAI : public ScriptedAI
        {
            npc_dragon_soul_shadowed_globuleAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_DEEP_CORRUPTION, urand(12000, 24000));
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (events.ExecuteEvent())
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(pTarget, SPELL_DEEP_CORRUPTION);
                    events.ScheduleEvent(EVENT_DEEP_CORRUPTION, (me->HasAura(SPELL_GLOWING_BLOOD_OF_SHUMA_2) ? 12000 : 24000));
                }

                DoMeleeAttackIfReady();
            }
        private:
            EventMap events;
        };
};

class npc_dragon_soul_cobalt_globule : public CreatureScript
{
    public:
        npc_dragon_soul_cobalt_globule() : CreatureScript("npc_dragon_soul_cobalt_globule") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_cobalt_globuleAI (pCreature);
        }

        struct npc_dragon_soul_cobalt_globuleAI : public ScriptedAI
        {
            npc_dragon_soul_cobalt_globuleAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_MANA_VOID, 3000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                DoCastAOE(SPELL_MANA_DIFFUSION);
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (events.ExecuteEvent())
                    DoCast(me, SPELL_MANA_VOID);

                DoMeleeAttackIfReady();
            }
        private:
            EventMap events;
        };
};

class npc_dragon_soul_flail_of_gorath : public CreatureScript
{
    public:
        npc_dragon_soul_flail_of_gorath() : CreatureScript("npc_dragon_soul_flail_of_gorath") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_flail_of_gorathAI (pCreature);
        }

        struct npc_dragon_soul_flail_of_gorathAI : public Scripted_NoMovementAI
        {
            npc_dragon_soul_flail_of_gorathAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_SLUDGE_SPEW, urand(2000, 4000));
                events.ScheduleEvent(EVENT_TENTACLE_TOSS, 10000);
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SLUDGE_SPEW:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(pTarget, SPELL_SLUDGE_SPEW);
                            events.ScheduleEvent(EVENT_SLUDGE_SPEW, urand(6000, 8000));
                            break;
                        case EVENT_WILD_FLAIL:
                            DoCastAOE(SPELL_WILD_FLAIL);
                            events.ScheduleEvent(EVENT_WILD_FLAIL, urand(7000, 10000));
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap events;
        };
};

class npc_dragon_soul_claw_of_gorath : public CreatureScript
{
    public:
        npc_dragon_soul_claw_of_gorath() : CreatureScript("npc_dragon_soul_claw_of_gorath") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_claw_of_gorathAI (pCreature);
        }

        struct npc_dragon_soul_claw_of_gorathAI : public Scripted_NoMovementAI
        {
            npc_dragon_soul_claw_of_gorathAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
            }

        EventMap events;

        void Reset() override
        {
            launch = false;
            damage = false;
            events.Reset();
        }

        void PassengerBoarded(Unit* /*who*/, int8 /*seatId*/, bool apply) override
        {
            if (apply)
                events.ScheduleEvent(EVENT_TENTACLE_TOSS, urand(6000, 18000));
            else
            {
                events.ScheduleEvent(EVENT_TENTACLE_TOSS_VEHICLE, urand(5000, 15000));
                events.CancelEvent(EVENT_TENTACLE_TOSS); // If Logout player
                events.CancelEvent(EVENT_TENTACLE_TOSS_LAUNCH); // If Logout player
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
                events.ScheduleEvent(EVENT_OOZE_SPIT, 5000);
                events.ScheduleEvent(EVENT_TENTACLE_TOSS_VEHICLE, urand(3000, 9000));
        }

        void JustDied(Unit* /*pKiller*/) override
        {
            playerVehicle = me->GetVehicleKit()->GetPassenger(0);
            if (playerVehicle)
                playerVehicle->ExitVehicle();
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!UpdateVictim())
                return;

            if (playerVehicle && launch && !damage)
            if (playerVehicle->FindNearestCreature(NPC_TENTACLE_TOSS_STALKER, 1.0f, true))
            {
                damage = true;
                playerVehicle->CastSpell(playerVehicle, SPELL_TENTACLE_TOSS_DMG, true);
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_OOZE_SPIT:
                        if (!me->IsWithinMeleeRange(me->GetVictim()))
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_OOZE_SPIT);
                        events.ScheduleEvent(EVENT_OOZE_SPIT, 4000);
                        break;
                    case EVENT_TENTACLE_TOSS_VEHICLE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            target->EnterVehicle(me, 0);
                            //target->ClearUnitState(UNIT_STATE_ONVEHICLE);
                            launch = false;
                            damage = false;
                            playerVehicle = target;
                        }
                        break;
                    case EVENT_TENTACLE_TOSS:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                        {
                            if (pTarget != playerVehicle)
                                me->CastSpell(pTarget, SPELL_TENTACLE_TOSS_SUMMON, true);
                            else
                                me->SummonCreature(NPC_TENTACLE_TOSS_STALKER, me->GetPositionX() + urand(10.0f, 40.0f), me->GetPositionY() + urand(10.0f, 40.0f), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 10000);
                        }
                        events.ScheduleEvent(EVENT_TENTACLE_TOSS_LAUNCH, 1600);
                        break;
                    case EVENT_TENTACLE_TOSS_LAUNCH:
                        playerVehicle = me->GetVehicleKit()->GetPassenger(0);
                        if (playerVehicle)
                        {
                            launch = true;
                            if (Creature* tentacle = me->FindNearestCreature(NPC_TENTACLE_TOSS_STALKER, 100.0f))
                            {
                                playerVehicle->ExitVehicle();
                                playerVehicle->GetMotionMaster()->MoveJump(tentacle->GetPosition(), 50.0f, 10.0f);
                            }
                        }
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        Unit* playerVehicle;
        bool launch;
        bool damage;
    };
};

class npc_dragon_soul_eye_of_gorath : public CreatureScript
{
    public:
        npc_dragon_soul_eye_of_gorath() : CreatureScript("npc_dragon_soul_eye_of_gorath") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_eye_of_gorathAI (pCreature);
        }

        struct npc_dragon_soul_eye_of_gorathAI : public Scripted_NoMovementAI
        {
            npc_dragon_soul_eye_of_gorathAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_SHADOW_GAZE, urand(3000, 5000));
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(5 * IN_MILLISECONDS);
            }

            void UpdateAI(uint32 const diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (events.ExecuteEvent())
                {
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        DoCast(pTarget, SPELL_SHADOW_GAZE);
                    events.ScheduleEvent(EVENT_SHADOW_GAZE, urand(3000, 4000));
                }
            }

        private:
            EventMap events;
        };
};


class npc_dragon_soul_teleport : public CreatureScript
{
    public:
        npc_dragon_soul_teleport() : CreatureScript("npc_dragon_soul_teleport") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
        {
            if (InstanceScript* pInstance = pCreature->GetInstanceScript())
            {
                switch (pCreature->GetEntry())
                {
                    case NPC_EIENDORMI:
                        if (pInstance->GetBossState(DATA_MORCHOK) == DONE)
                        {
                            if (Creature*dragon = pPlayer->SummonCreature(NPC_VEHICLE_EIENDORMI, pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(),
                                pPlayer->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300 * IN_MILLISECONDS))
                                pPlayer->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, dragon, false);
                            SendGossipMenuFor(pPlayer, DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                        }
                        break;
                    case NPC_VALEERA:
                        if (pInstance->GetBossState(DATA_MORCHOK) == DONE)
                        {
                            if (Creature*dragon = pPlayer->SummonCreature(NPC_VEHICLE_VALEERA, pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(),
                                pPlayer->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300 * IN_MILLISECONDS))
                                pPlayer->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, dragon, false);
                            SendGossipMenuFor(pPlayer, DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                        }
                        break;
                        break;
                    case NPC_TRAVEL_TO_WYRMREST_TEMPLE:
                    case NPC_TRAVEL_TO_WYRMREST_BASE:
                        pPlayer->NearTeleportTo(teleportPos[0].GetPositionX(), teleportPos[0].GetPositionY(), teleportPos[0].GetPositionZ(), teleportPos[0].GetOrientation());
                        break;
                    case NPC_TRAVEL_TO_WYRMREST_SUMMIT:
                        pPlayer->NearTeleportTo(teleportPos[3].GetPositionX(), teleportPos[3].GetPositionY(), teleportPos[3].GetPositionZ(), teleportPos[3].GetOrientation());
                        break;
                    case NPC_NETHESTRASZ:
                        if (pInstance->GetBossState(DATA_YORSAHJ) == DONE && pInstance->GetBossState(DATA_ZONOZZ) == DONE)
                        {
                            if (Creature*dragon = pPlayer->SummonCreature(NPC_VEHICLE_NETHESTRASZ, pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(),
                                pPlayer->GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300 * IN_MILLISECONDS))
                                pPlayer->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, dragon, false);
                            SendGossipMenuFor(pPlayer, DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
                        }
                        break;
                    case NPC_TRAVEL_TO_EYE_OF_ETERNITY:
                        if (pInstance->GetBossState(DATA_YORSAHJ) == DONE && pInstance->GetBossState(DATA_ZONOZZ) == DONE)
                            pPlayer->NearTeleportTo(teleportPos[4].GetPositionX(), teleportPos[4].GetPositionY(), teleportPos[4].GetPositionZ(), teleportPos[4].GetOrientation());
                        break;
                    case NPC_TRAVEL_TO_DECK:
                        if (pInstance->GetBossState(DATA_BLACKHORN) == DONE && pInstance->GetBossState(DATA_ULTRAXION) == DONE)
                            pPlayer->NearTeleportTo(skyfirePos.GetPositionX(), skyfirePos.GetPositionY(), skyfirePos.GetPositionZ(), skyfirePos.GetOrientation());
                        break;
                    case NPC_TRAVEL_TO_MAELSTORM:
                        if (pInstance->GetBossState(DATA_BLACKHORN) == DONE && pInstance->GetBossState(DATA_ULTRAXION) == DONE)
                            pPlayer->NearTeleportTo(madnessdeathwingPos.GetPositionX(), madnessdeathwingPos.GetPositionY(), madnessdeathwingPos.GetPositionZ(), madnessdeathwingPos.GetOrientation());
                        break;
                    default:
                        break;
                }

            }
            return true;
        }
};

#define GOSSIP_OPTION_1 "Begin charging."

class npc_dragon_soul_thrall : public CreatureScript
{
    public:
        npc_dragon_soul_thrall() : CreatureScript("npc_dragon_soul_thrall") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
        {
            if (InstanceScript* pInstance = pCreature->GetInstanceScript())
            {
                if (pInstance->GetBossState(DATA_HAGARA) == DONE &&
                    pInstance->GetBossState(DATA_ULTRAXION) != DONE)
                {
                    AddGossipItemFor(pPlayer, 0, GOSSIP_OPTION_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                    SendGossipMenuFor(pPlayer, 1, pCreature->GetGUID());
                    return true;
                }
            }
            return false;
        }

        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*sender*/, uint32 /*action*/) override
        {
            pPlayer->PlayerTalkClass->SendCloseGossip();
            if (InstanceScript* pInstance = pCreature->GetInstanceScript())
            {
                if (pInstance->GetBossState(DATA_HAGARA) == DONE &&
                    pInstance->GetBossState(DATA_ULTRAXION) != DONE)
                {
                    if (!pCreature->FindNearestCreature(NPC_ULTRAXION, 500.0f, true))
                    {
                        if (Creature* pUltraxion = pCreature->SummonCreature(NPC_ULTRAXION, ultraxionPos[0], TEMPSUMMON_MANUAL_DESPAWN, 1000000))
                        {
                            PhasingHandler::RemovePhase(pUltraxion, 169);
                            PhasingHandler::AddPhase(pUltraxion, 173);
                        }
                        pCreature->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    }
                    else if (Creature* pUltraxion = pCreature->FindNearestCreature(NPC_ULTRAXION, 500.0f, true))
                        pUltraxion->AI()->DoAction(2); //Start Event
                }
            }
            return true;
        }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_thrallAI (pCreature);
        }

        struct npc_dragon_soul_thrallAI : public ScriptedAI
        {
            npc_dragon_soul_thrallAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
            }

            void Reset() override
            {
                if (Creature* dragonSoul = me->FindNearestCreature(NPC_THE_DRAGON_SOUL, 50.0f, true))
                    dragonSoul->SetDisableGravity(true);
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_ULTRAXION_WIN)
                    events.ScheduleEvent(EVENT_TALK_ULTRAXION_WIN_1, 10000);
            }

            void UpdateAI(uint32 const diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TALK_ULTRAXION_WIN_1:
                            if (Creature* pAlextrasza = me->FindNearestCreature(NPC_ALEXTRASZA_THE_LIFE_BINDER, 300.0f))
                                pAlextrasza->AI()->Talk(2); // SAY_ULTRAXION_WIN
                            events.ScheduleEvent(EVENT_TALK_ULTRAXION_WIN_2, 15000);
                            break;
                        case EVENT_TALK_ULTRAXION_WIN_2:
                            Talk(1);
                            events.ScheduleEvent(EVENT_SPAWN_SHIP, 15000);
                            break;
                        case EVENT_SPAWN_SHIP:
                            if (InstanceScript* pInstance = me->GetInstanceScript())
                            {
                                if (GameObject* pShip = pInstance->GetGameObject(DATA_ALLIANCE_SHIP))
                                    pShip->RemoveFlag(GO_FLAG_DESTROYED);
                            }
                            events.ScheduleEvent(EVENT_SPAWN_NPC, 8000);
                            break;
                        case EVENT_SPAWN_NPC:
                            if (InstanceScript* pInstance = me->GetInstanceScript())
                            {
                                if (Creature* pSwayze = pInstance->GetCreature(DATA_SWAYZE))
                                {
                                    pSwayze->SetVisible(true);
                                    pSwayze->AI()->Talk(9);
                                }
                                if (Creature* pReevs = pInstance->GetCreature(DATA_REEVS))
                                    pReevs->SetVisible(true);
                            }
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap events;
        };
};

class spell_dragon_soul_trigger_spell_from_aoe : public SpellScriptLoader
{
    public:
        spell_dragon_soul_trigger_spell_from_aoe(char const* scriptName, uint32 triggerId) : SpellScriptLoader(scriptName), _triggerId(triggerId){ }

        class spell_dragon_soul_trigger_spell_from_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dragon_soul_trigger_spell_from_aoe_SpellScript);

        public:
            spell_dragon_soul_trigger_spell_from_aoe_SpellScript(uint32 triggerId) : SpellScript(), _triggerId(triggerId) { }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.size() <= 1)
                    return;

                std::list<WorldObject*> tempList;

                for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    if (GetCaster()->GetDistance((*itr)) >= 15.0f)
                        tempList.push_back((*itr));

                if (!tempList.empty())
                {
                    targets.clear();
                    targets.push_back(Trinity::Containers::SelectRandomContainerElement(tempList));
                }
                else
                    Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleDummy()
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), _triggerId, true);
            }

            void Register() override
            {
                if (m_scriptSpellId == SPELL_BOULDER_SMASH_AOE)
                {
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dragon_soul_trigger_spell_from_aoe_SpellScript::FilterTargets, EFFECT_0,TARGET_UNIT_SRC_AREA_ENEMY);
                }
                AfterHit += SpellHitFn(spell_dragon_soul_trigger_spell_from_aoe_SpellScript::HandleDummy);
            }

        private:
            uint32 _triggerId;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dragon_soul_trigger_spell_from_aoe_SpellScript(_triggerId);
        }

    private:
        uint32 _triggerId;
};

class spell_dragon_soul_shadowed_globule_deep_corruption : public SpellScriptLoader
{
    public:
        spell_dragon_soul_shadowed_globule_deep_corruption() : SpellScriptLoader("spell_dragon_soul_shadowed_globule_deep_corruption") { }

        class spell_dragon_soul_shadowed_globule_deep_corruption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dragon_soul_shadowed_globule_deep_corruption_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (!GetCaster())
                    return;

                if (Aura* aur = GetAura())
                {
                    if (aur->GetStackAmount() >= 5)
                    {
                        GetCaster()->CastSpell(GetCaster(), SPELL_DEEP_CORRUPTION_DMG, true);
                        aur->Remove();
                    }
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_dragon_soul_shadowed_globule_deep_corruption_AuraScript::HandlePeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dragon_soul_shadowed_globule_deep_corruption_AuraScript();
        }
};

class spell_dragon_soul_cobalt_globule_mana_void : public SpellScriptLoader
{
    public:
        spell_dragon_soul_cobalt_globule_mana_void() : SpellScriptLoader("spell_dragon_soul_cobalt_globule_mana_void") { }

        class spell_dragon_soul_cobalt_globule_mana_void_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dragon_soul_cobalt_globule_mana_void_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                targets.remove_if(ManaCheck());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dragon_soul_cobalt_globule_mana_void_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dragon_soul_cobalt_globule_mana_void_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }

        private:
            class ManaCheck
            {
                public:
                    ManaCheck() {}

                    bool operator()(WorldObject* unit)
                    {
                        if (unit->GetTypeId() != TYPEID_PLAYER)
                            return true;
                        return (unit->ToPlayer()->GetPowerType() != POWER_MANA);
                    }
            };

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dragon_soul_cobalt_globule_mana_void_SpellScript();
        }
};

class npc_dragon_soul_wyrmrest_defense_dragon : public CreatureScript
{
public:
    npc_dragon_soul_wyrmrest_defense_dragon() : CreatureScript("npc_dragon_soul_wyrmrest_defense_dragon") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_dragon_soul_wyrmrest_defense_dragonAI(pCreature);
    }

    struct npc_dragon_soul_wyrmrest_defense_dragonAI : public ScriptedAI
    {
        npc_dragon_soul_wyrmrest_defense_dragonAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        }

        EventMap events;
        uint32 count;
        bool active;

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->SetCanFly(true);
            me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);
            me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
            me->AddAura(SPELL_DEFEND_WYRMREST, me);
            me->SetSpeed(MOVE_FLIGHT, 1.0f);
            count = 0;
            active = false;
            events.Reset();
        }

        void DoAction(const int32 action) override
        {
            if (action == ACTION_START_WYRMREST_EVENT)
            {
                if (!active)
                {
                    active = true;
                    if (Unit * target = me->FindNearestCreature(NPC_HARBRINGER_OF_TWILIGHT, 100.0f, true))
                    {
                        AttackStart(target);
                        me->SetFacingToObject(target);
                        events.ScheduleEvent(EVENT_START_ATTACK, 2000);
                    }
                    else if (Unit * target = me->FindNearestCreature(NPC_HARBRINGER_OF_DESTRUCTION, 100.0f, true))
                    {
                        AttackStart(target);
                        me->SetFacingToObject(target);
                        events.ScheduleEvent(EVENT_START_ATTACK, 2000);
                    }
                    else if (Unit * target = me->FindNearestCreature(NPC_FORCE_OF_DESTRUCTION, 100.0f, true))
                    {
                        AttackStart(target);
                        me->SetFacingToObject(target);
                        events.ScheduleEvent(EVENT_START_ATTACK, 2000);
                    }
                    else if (Unit * target = me->FindNearestCreature(NPC_PORTENT_OF_TWILIGHT, 100.0f, true))
                    {
                        AttackStart(target);
                        me->SetFacingToObject(target);
                        events.ScheduleEvent(EVENT_START_ATTACK, 2000);
                    }
                }
            }
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_ATTACK:
                        DoCast(SPELL_FLAME_BREATH);
                        count++;
                        events.ScheduleEvent(EVENT_START_ATTACK, urand(7000, 8000));
                        if (count >= 10)
                        events.ScheduleEvent(EVENT_MOVE_AROUND, 1000);
                    break;
                case EVENT_MOVE_AROUND:
                    events.CancelEvent(EVENT_START_ATTACK);
                    count = 0;
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MoveTargetedHome();
                    events.ScheduleEvent(EVENT_ACTION_REPEAT, 20000);
                    break;
                case EVENT_ACTION_REPEAT:
                    active = false;
                    me->AI()->DoAction(ACTION_START_WYRMREST_EVENT);
                    break;
                }
            }
        }
    };
};

class npc_dragon_soul_wyrmrest_attack_dragon : public CreatureScript
{
public:
    npc_dragon_soul_wyrmrest_attack_dragon() : CreatureScript("npc_dragon_soul_wyrmrest_attack_dragon") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_dragon_soul_wyrmrest_attack_dragonAI(pCreature);
    }

    struct npc_dragon_soul_wyrmrest_attack_dragonAI : public ScriptedAI
    {
        npc_dragon_soul_wyrmrest_attack_dragonAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        }

        EventMap events;
        uint32 count;
        bool active;

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->SetCanFly(true);
            me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);
            me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
            me->AddAura(SPELL_ATTACK_WYRMREST, me);
            me->SetSpeed(MOVE_FLIGHT, 1.0f);
            count = 0;
            active = false;
            events.Reset();
        }

        void DoAction(const int32 action) override
        {
            if (action == ACTION_START_WYRMREST_EVENT)
            {
                if (!active)
                {
                    active = true;

                    if (Unit * target = me->FindNearestCreature(NPC_ARCANE_WARDEN, 100.0f, true))
                    {
                        AttackStart(target);
                        me->SetFacingToObject(target);

                        events.ScheduleEvent(EVENT_TWILIGHT_BREATH, 2000);
                    }
                    else if (Unit * target = me->FindNearestCreature(NPC_CHAMPION_OF_LIFE, 100.0f, true))
                    {
                        AttackStart(target);
                        me->SetFacingToObject(target);

                        events.ScheduleEvent(EVENT_TWILIGHT_BREATH, 2000);
                    }
                    else if (Unit * target = me->FindNearestCreature(NPC_CHAMPION_OF_MAGIC, 100.0f, true))
                    {
                        AttackStart(target);
                        me->SetFacingToObject(target);

                        events.ScheduleEvent(EVENT_TWILIGHT_BREATH, 2000);
                    }
                    else if (Unit * target = me->FindNearestCreature(NPC_CHAMPION_OF_TIME, 100.0f, true))
                    {
                        AttackStart(target);
                        me->SetFacingToObject(target);

                        events.ScheduleEvent(EVENT_TWILIGHT_BREATH, 2000);
                    }
                    else if (Unit * target = me->FindNearestCreature(NPC_CHAMPION_OF_EMERALD_DREAM, 100.0f, true))
                    {
                        AttackStart(target);
                        me->SetFacingToObject(target);

                        events.ScheduleEvent(EVENT_TWILIGHT_BREATH, 2000);
                    }
                }
            }
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TWILIGHT_BREATH:
                        DoCast(SPELL_TWILIGHT_BREATH);
                        count++;
                        events.ScheduleEvent(EVENT_TWILIGHT_BREATH, urand(7000, 8000));
                        if (count >= 10)
                        events.ScheduleEvent(EVENT_MOVE_AROUND, 1000);
                    break;
                case EVENT_MOVE_AROUND:
                    events.CancelEvent(EVENT_TWILIGHT_BREATH);
                    count = 0;
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->SetSpeed(MOVE_FLIGHT, 2.0f);
                    me->GetMotionMaster()->MoveTargetedHome();
                    events.ScheduleEvent(EVENT_ACTION_REPEAT, 20000);
                    break;
                case EVENT_ACTION_REPEAT:
                    active = false;
                    me->AI()->DoAction(ACTION_START_WYRMREST_EVENT);
                    break;
                }
            }
        }
    };
};

class npc_dragon_soul_wyrmrest_deathwing_siege : public CreatureScript
{
public:
    npc_dragon_soul_wyrmrest_deathwing_siege() : CreatureScript("npc_dragon_soul_wyrmrest_deathwing_siege") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_dragon_soul_wyrmrest_deathwing_siegeAI(pCreature);
    }

    struct npc_dragon_soul_wyrmrest_deathwing_siegeAI : public ScriptedAI
    {
        npc_dragon_soul_wyrmrest_deathwing_siegeAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        }

        EventMap events;
        uint32 count;
        uint32 pointFly;

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
            me->SetCanFly(true);
            me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);
            me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
            me->SetSpeed(MOVE_FLIGHT, 5.0f);
            pointFly = 0;
            count = 0;
            events.Reset();
        }

        void DoAction(const int32 action) override
        {
            if (action == ACTION_START_WYRMREST_EVENT)
            {
                if (Unit * target = me->FindNearestCreature(NPC_TARGET_DUMMY, 100.0f, true))
                {
                    AttackStart(target);
                    me->SetFacingToObject(target);
                    me->StopMoving();

                    me->GetMotionMaster()->MovePoint(POINT_DEATHWING_1, DeathwingSiege[0]);
                }
            }
            else if (action == ACTION_DEATHWING_ATTACK)
            {
                events.ScheduleEvent(EVENT_DEATHWING_SIEGE, 1000);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                case POINT_DEATHWING_1:
                {
                    count = 0;
                    pointFly = POINT_DEATHWING_1;
                    me->AI()->DoAction(ACTION_DEATHWING_ATTACK);
                    break;
                }
                case POINT_DEATHWING_2:
                    pointFly = POINT_DEATHWING_2;
                    me->AI()->DoAction(ACTION_DEATHWING_ATTACK);
                    break;
                case POINT_DEATHWING_3:
                    pointFly = POINT_DEATHWING_3;
                    me->AI()->DoAction(ACTION_DEATHWING_ATTACK);
                    break;
                case POINT_DEATHWING_4:
                    pointFly = POINT_DEATHWING_4;
                    me->AI()->DoAction(ACTION_DEATHWING_ATTACK);
                    break;
                case POINT_DEATHWING_5:
                    pointFly = POINT_DEATHWING_5;
                    me->AI()->DoAction(ACTION_DEATHWING_ATTACK);
                    break;
                case POINT_DEATHWING_6:
                    pointFly = POINT_DEATHWING_6;
                    me->AI()->DoAction(ACTION_DEATHWING_ATTACK);
                    break;
                case POINT_DEATHWING_7:
                    pointFly = POINT_DEATHWING_7;
                    me->AI()->DoAction(ACTION_DEATHWING_ATTACK);
                    break;
                case POINT_DEATHWING_8:
                    pointFly = POINT_DEATHWING_8;
                    me->AI()->DoAction(ACTION_DEATHWING_ATTACK);
                    break;
                case POINT_DEATHWING_9:
                    pointFly = POINT_DEATHWING_9;
                    me->AI()->DoAction(ACTION_DEATHWING_ATTACK);
                    break;
                case POINT_DEATHWING_10:
                    pointFly = POINT_DEATHWING_10;
                    me->AI()->DoAction(ACTION_DEATHWING_ATTACK);
                    break;
                case POINT_DEATHWING_11:
                    pointFly = POINT_DEATHWING_11;
                    me->AI()->DoAction(ACTION_DEATHWING_ATTACK);
                    break;
                case POINT_DEATHWING_12:
                    pointFly = POINT_DEATHWING_12;
                    me->AI()->DoAction(ACTION_DEATHWING_ATTACK);
                    break;
                }
            }
        }

        void UpdateAI(uint32 const diff) override
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
                case EVENT_DEATHWING_SIEGE:
                {
                    std::list<Creature*> targetSiege;
                    Creature* deathwing = me;
                    GetCreatureListWithEntryInGrid(targetSiege, me, NPC_TARGET_DUMMY, 500.0f);
                    if (targetSiege.empty())
                        return;

                    targetSiege.remove_if([&deathwing](Creature* c) {return !deathwing->IsWithinLOSInMap(c); });

                    if (targetSiege.size() > 1)
                    {
                        Trinity::Containers::RandomResize(targetSiege, 1);
                        if (Creature* target = targetSiege.front())
                        {
                            me->SetFacingToObject(target);
                            me->CastSpell(target, SPELL_MOLTEN_METEOR_DW, true);
                        }
                    }
                    events.ScheduleEvent(EVENT_MOVE_AROUND, 5000);
                    break;
                }
                case EVENT_MOVE_AROUND:
                {
                    count++;
                    me->CastStop();
                    me->AttackStop();
                    if (count >= 12)
                        count = 0;
                    if (pointFly == POINT_DEATHWING_12)
                        pointFly = 0;
                    me->GetMotionMaster()->MovePoint(pointFly + 1, DeathwingSiege[count]);
                    break;
                }
                }
            }
        }
    };
};

void AddSC_dragon_soul()
{
    new npc_dragon_soul_ancient_water_lord();
    new npc_dragon_soul_earthen_destroyer();
    new npc_dragon_soul_earthen_soldier();
    new npc_dragon_soul_twilight_siege_captain();
    new npc_dragon_soul_twilight_portal();
    new npc_dragon_soul_crimson_globule();
    new npc_dragon_soul_acidic_globule();
    new npc_dragon_soul_dark_globule();
    new npc_dragon_soul_shadowed_globule();
    new npc_dragon_soul_cobalt_globule();
    new npc_dragon_soul_flail_of_gorath();
    new npc_dragon_soul_claw_of_gorath();
    new npc_dragon_soul_eye_of_gorath();
    new npc_dragon_soul_teleport();
    new npc_dragon_soul_thrall();
    new npc_dragon_soul_wyrmrest_defense_dragon();
    new npc_dragon_soul_wyrmrest_attack_dragon();
    new npc_dragon_soul_wyrmrest_deathwing_siege();
    new spell_dragon_soul_trigger_spell_from_aoe("spell_dragon_soul_ancient_water_lord_flood", SPELL_FLOOD);
    new spell_dragon_soul_trigger_spell_from_aoe("spell_dragon_soul_earthen_destroyer_boulder_smash", SPELL_BOULDER_SMASH);
    new spell_dragon_soul_shadowed_globule_deep_corruption();
    new spell_dragon_soul_cobalt_globule_mana_void();
    new spell_dragon_soul_trigger_spell_from_aoe("spell_dragon_soul_claw_of_gorath_tentacle_toss_aoe_1", SPELL_TENTACLE_TOSS_SCRIPT_1);
    new spell_dragon_soul_trigger_spell_from_aoe("spell_dragon_soul_claw_of_gorath_tentacle_toss_aoe_2", SPELL_TENTACLE_TOSS_SUMMON);
}
