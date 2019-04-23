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

#include "Cell.h"
#include "CellImpl.h"
#include "firelands.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum SayMajordomo
{
    MAJORDOMO_CRY_1 = 0,
    MAJORDOMO_CRY_2 = 1,
    MAJORDOMO_CRY_3 = 2,
};
enum Spells
{
    // Ancient Core Hound
    SPELL_DINNER_TIME                           = 99693,
    SPELL_DINNER_TIME_VEHICLE                   = 99694,
    SPELL_FLAME_BREATH                          = 99736,
    SPELL_TERRIFYING_ROAR                       = 99692,

    // Ancient Lava Dweller
    SPELL_LAVA_SHOWER                           = 97549,
    SPELL_LAVA_SHOWER_MISSILE                   = 97551,
    SPELL_LAVA_SPIT                             = 97306,

    // Fire Scorpion
    SPELL_FIERY_BLOOD                           = 99993,
    SPELL_SLIGHTLY_WARM_PINCERS                 = 99984,

    // Fire Turtle Hatchling
    SPELL_SHELL_SPIN                            = 100263,

    // Fire Archon
    SPELL_FLAME_TORRENT                         = 100795,
    SPELL_FIERY_TORMENT                         = 100797,
    SPELL_FIERY_TORMENT_DMG                     = 100802,

    // Molten Lord
    SPELL_FLAME_STOMP                           = 99530,
    SPELL_MELT_ARMOR                            = 99532,
    SPELL_SUMMON_LAVA_JETS                      = 99555,
    SPELL_SUMMON_LAVA_JET                       = 99538,

    // Molten Flamefather
    SPELL_EARTHQUAKE                            = 100724,
    SPELL_MAGMA_CONDUIT                         = 100728,

    // Magma Conduit
    SPELL_VOLCANO_SMOKE                         = 97699,
    SPELL_VOLCANO_BASE                          = 98250,
    SPELL_SUMMON_MAGMAKIN                       = 100746,
    SPELL_SUMMON_MAGMAKIN_DMG                   = 100748,

    // Magmakin
    SPELL_ERUPTION                              = 100755,

    // Harbinger of Flame
    SPELL_FIRE_IT_UP                            = 100093,
    SPELL_FIEROBLAST_TRASH                      = 100094,
    SPELL_FIEROCLAST_BARRAGE                    = 100095,
    SPELL_FIRE_CHANNELING                       = 100109,

    // Blazing Monstrosity
    SPELL_RIDE_MONSTROSITY                      = 93970,
    SPELL_SHARE_HEALTH_LEFT                     = 101502,
    SPELL_SHARE_HEALTH_RIGHT                    = 101503,
    SPELL_SLEEP_ULTRA_HIGH_PRIORITY             = 99480,
    SPELL_GENERIC_DUMMY_CAST                    = 100088,
    SPELL_LEFT_SIDE_SMACK_L                     = 100076,
    SPELL_RIGHT_SIDE_SMACK_L                    = 100078,
    SPELL_HEAD_BONK_L                           = 100080,
    SPELL_TICKLE_L                              = 100082,
    SPELL_KNOCKBACK_RIGHT                       = 100084,
    SPELL_KNOCKBACK_LEFT                        = 100085,
    SPELL_KNOCKBACK_FORWARD                     = 100086,
    SPELL_KNOCKBACK_BACK                        = 100087,
    SPELL_HEAD_BONK_R                           = 100089,
    SPELL_LEFT_SIDE_SMACK_R                     = 100090,
    SPELL_RIGHT_SIDE_SMACK_R                    = 100091,
    SPELL_TICKLE_R                              = 100092,
    SPELL_MOLTEN_BARRAGE_EFFECT_L               = 100071,
    SPELL_MOLTEN_BARRAGE_LEFT                   = 100072,
    SPELL_MOLTEN_BARRAGE_RIGHT                  = 100073,
    SPELL_MOLTEN_BARRAGE_EFFECT_R               = 100074,
    SPELL_MOLTEN_BARRAGE_VISUAL                 = 100075,
    SPELL_AGGRO_CLOSEST                         = 100462,
    SPELL_INVISIBILITY_AND_STEALTH_DETECTION    = 18950,

    // Egg Pile
    SPELL_SUMMON_SMOULDERING_HATCHLING          = 100096,
    SPELL_MOLTEN_EGG_TRASH_CALL_L               = 100097,
    SPELL_MOLTEN_EGG_TRASH_CALL_R               = 100098,
    SPELL_ALYSRAZOR_COSMETIC_EGG_XPLOSION       = 100099,

    // Volcanus
    SPELL_FLAMEWAKE                             = 100191,

    //Flame waker cauterizer
    SPELL_CAUTERIZE                             = 99618,
    SPELL_CONFLAGRATION                         = 99625,
    SPELL_FLAME_SHIELD                          = 99687,

    //flamewaker trainee
    SPELL_DEVASTATE                             = 78660,
    SPELL_ENSNARE                               = 99800,
    SPELL_FLAMING_SPEAR                         = 99695,
    SPELL_MORTAL_STRIKE                         = 16856,
    SPELL_SHOCKWAVE                             = 99610,

    //kar the semperardent
    SPELL_SOUL_BURN                             = 99567,
    SPELL_SUMMON_FIRE                           = 99601,
    SPELL_SUMMON_LAVA                           = 99575,

    //pyrelord
    SPELL_IGNITE                                = 101166,
    SPELL_IGNITE_ELEMENTAL                      = 99916,

    //unbound smoldering elemental
    SPELL_BLAZING_FLAME                         = 999181,
    SPELL_UNBREAKABLE_SHELL                     = 99913,

    //majordomo staghelm
    SPELL_SMOULDERING_ROOTS                     = 100556,
    SPELL_VOLCANO_TREMBLING_GROUND              = 98402,
    SPELL_SACRIFICE_TO_FLAME                    = 100558,
    //flamewaker animator
    SPELL_DEFENSIVE_CASTING                     = 100742,
    SPELL_MAGMA_CHARGING                        = 74911,

    //flamewaker subjugator
    SPELL_FURIOUS                               = 100527,
    SPELL_BURNING_MOTIVATION                    = 100423,

    //unstable magma
    SPELL_CONSUMING_FLAMES                      = 100505,
    SPELL_LAVA_SURGE                            = 100549,
    SPELL_PYROCLASM                             = 100515,
    SPELL_SUPER_HEATED                          = 100566,
    SPELL_STABILIZED                            = 100410,

    //molten erupter
    SPELL_MOLTEN_BLAST                          = 99613,
    SPELL_MOLTEN_BOLT                           = 99579,

    //molten spewer
    SPELL_MOLTEN_VOLLEY                         = 99611,
};
enum Action
{
    //Kar
    KAR_ACTION_START_ENCOUNTER,
    KAR_ACTION_MOVE_BACK,
    KAR_ACTION_ATTACK,

    //flamewaker animator
    ACTION_STOP_CHANNELING,

    //unstable magma
    ACTION_ANIMATOR_DEATH,
    ACTION_FULL_CHARGED,
};

enum Adds
{
    NPC_MAGMAKIN                        = 54144,
    NPC_MAGMA_CONDUIT                   = 54145, // 97699, 98250, 100746

    NPC_STALKER                         = 45979,
    NPC_FLAMEWAKER_SENTINEL             = 53640,
    NPC_UNBOUND_SMOLDERING_ELEMENTAL    = 53732,
    NPC_UNSTABLE_PYRELORD               = 53630,
    NPC_LAVA_SPAWN                      = 53622,
    NPC_UNSTABLE_MAGMA                  = 53901,
    NPC_FLAMEWAKER_ANIMATOR             = 53187,
};
enum ModelId
{
    MI_HAWK                             = 38012,
    MI_MAJORDOMO                        = 37953,
    NPC_CAPTIVE_DRUID_OF_THE_TALON      = 54019,
};

enum Events
{
    // Ancient Core Hound
    EVENT_DINNER_TIME                   = 1,
    EVENT_FLAME_BREATH                  = 2,
    EVENT_TERRIFYING_ROAR               = 3,

    // Ancient Lava Dweller
    EVENT_LAVA_SHOWER                   = 4,

    // Fire Turtle Hatchling
    EVENT_SHELL_SPIN                    = 5,

    // Fire Archon
    EVENT_FIERY_TORMENT                 = 6,
    EVENT_FLAME_TORRENT                 = 7,

    // Molten Lord
    EVENT_MELT_ARMOR                    = 8,
    EVENT_FLAME_STOMP                   = 9,
    EVENT_SUMMON_LAVA_JETS              = 10,

    // Molten Flamefather
    EVENT_EARTHQUAKE                    = 11,
    EVENT_MAGMA_CONDUIT                 = 12,

    // Blazing Monstrosity
    EVENT_START_SPITTING                = 13,
    EVENT_CONTINUE_SPITTING             = 14,

    // Harbinger of Flame
    EVENT_FIEROBLAST                    = 15,
    EVENT_FIEROCLAST_BARRAGE            = 16,

    // Egg Pile
    EVENT_SUMMON_SMOULDERING_HATCHLING  = 17,

    // Volcanus
    EVENT_FLAMEWAKE                     = 18,

    //Flamewaker cauteriser
    EVENT_CAUTERIZE                     = 19,
    EVENT_CONFLAGRATION                 = 20,
    EVENT_FLAME_SHIELD                  = 21,

    //flamewaker trainee
    EVENT_DEVASTATE                     = 22,
    EVENT_ENSNARE                       = 23,
    EVENT_FLAMING_SPEAR                 = 24,
    EVENT_MORTAL_STRIKE                 = 25,
    EVENT_SHOCKWAVE                     = 26,

    //kar the semperardent
    EVENT_SOUL_BURN                     = 27,
    EVENT_SUMMON_FIRE_1                 = 28,
    EVENT_SUMMON_FIRE_2                 = 29,
    EVENT_SUMMON_FIRE_3                 = 30,
    EVENT_SUMMON_LAVA                   = 31,
    EVENT_ENCOUNTER_START               = 32,
    EVENT_MOVE_BACK                     = 33,
    EVENT_CHECK_RESET                   = 34,

    //pyrelord
    EVENT_IGNITE                        = 35,
    EVENT_IGNITE_ELEMENTAL              = 36,

    //unbound smoldering elemental
    EVENT_BLAZING_FLAME                 = 37,
    EVENT_UNBREAKABLE_SHELL             = 38,

    //majordomo
    EVENT_CRY_1                         = 39,
    EVENT_PLAYER_IMMOBILIZE             = 40,
    EVENT_CRY_2                         = 41,
    EVENT_DRUID_KILL                    = 42,
    EVENT_GROUND_TREMBLING              = 43,
    EVENT_CRY_3                         = 44,
    EVENT_GO_AWAY                       = 45,
    EVENT_BREAK_VOLCANO                 = 46,
    EVENT_SUMMON_ALYSRAZOR              = 47,

    //flamewaker animator
    EVENT_CHECK_MAGMA                   = 48,

    //flamewaker subjugator
    EVENT_FURIOUS                       = 49,
    EVENT_BURNING_MOTIVATION            = 50,

    //unstable magma
    EVENT_LAVA_SURGE                    = 51,
    EVENT_PYROCLASM                     = 52,

    //molten erupter
    EVENT_MOLTEN_BLAST                  = 53,
    EVENT_MOLTEN_BOLT                   = 54,

    //molten spewer
    EVENT_MOLTEN_VOLLEY                 = 55,


};
enum DataKar
{
    DATA_BEGIN_KAR = 1,
};
enum KarEvent
{
    EVENT_KAR_AGGRO_NOT_DONE = 1,
    EVENT_KAR_AGGRO_LAUNCHED = 2,
    EVENT_KAR_AGGRO_DONE = 3,

};
Position const PyrelordUnstablePosition[11]
{
    { -247.42f,     -375.238037f,   92.113007f  },
    { -233.77300f,  -361.313263f,   82.792107f  },
    { -223.805603f, -360.980499f,   79.345146f  },
    { -214.113251f, -350.457642f,   73.4162f    },
    { -210.242691f, -342.095123f,   70.070435f  },
    { -197.794189f, -347.22f,       68.086f     },
    { -193.2411f,   -330.751953f,   62.857f     },
    //position d'invocation des seigneurs du feu apres son deplacement
    {-268.909241f,  -401.785278f,   99.608948f  },
    {-273.090118f,  -419.548767f,   102.883415f },
    {-292.661438f,  -417.168243f,   101.807571f },
    {-306.280884f,  -424.822296f,   101.617920f },
};

Position const KarSecondPosition[1]
{
    { -327.273f,    -410.983f,      102.934f },
};

enum MiscData
{
    MODEL_INVISIBLE_STALKER     = 11686,
    ANIM_KIT_BIRD_WAKE          = 1469,
    ANIM_KIT_BIRD_TURN          = 1473,
};

class npc_firelands_molten_erupter : public CreatureScript
{
public:
    npc_firelands_molten_erupter() : CreatureScript("npc_firelands_molten_erupter") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_firelands_molten_erupterAI(pCreature);
    }
    struct npc_firelands_molten_erupterAI : public ScriptedAI
    {
        npc_firelands_molten_erupterAI(Creature* pCreature) : ScriptedAI(pCreature)
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
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
        }
        EventMap events;
        void Reset() override
        {
            events.Reset();
        }
        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_MOLTEN_BLAST, urand(7000, 9000));
            events.ScheduleEvent(EVENT_MOLTEN_BOLT, 5000);
        }
        void UpdateAI(uint32 diff) override
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
                case EVENT_MOLTEN_BLAST:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(pTarget, SPELL_MOLTEN_BLAST);
                    events.ScheduleEvent(EVENT_MOLTEN_BLAST, urand(15000, 20000));
                    break;
                case EVENT_MOLTEN_BOLT:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(pTarget, SPELL_MOLTEN_BOLT);
                    events.ScheduleEvent(EVENT_MOLTEN_BOLT, urand(20000, 25000));
                    break;
                }

            }
            DoMeleeAttackIfReady();
        }
    };
};
class npc_firelands_molten_spewer : public CreatureScript
{
public:
    npc_firelands_molten_spewer() : CreatureScript("npc_firelands_molten_spewer") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_firelands_molten_spewerAI(pCreature);
    }
    struct npc_firelands_molten_spewerAI : public ScriptedAI
    {
        npc_firelands_molten_spewerAI(Creature* pCreature) : ScriptedAI(pCreature)
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
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
        }
        EventMap events;
        void Reset() override
        {
            events.Reset();
        }
        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_MOLTEN_BLAST, urand(7000, 9000));
            events.ScheduleEvent(EVENT_MOLTEN_VOLLEY, urand(10000,20000));
        }
        void UpdateAI(uint32 diff) override
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
                case EVENT_MOLTEN_BLAST:
                    if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(pTarget, SPELL_MOLTEN_BLAST);
                    events.ScheduleEvent(EVENT_MOLTEN_BLAST, urand(15000, 20000));
                    break;
                case EVENT_MOLTEN_VOLLEY:
                    me->CastSpell(me, SPELL_MOLTEN_VOLLEY, true);
                    events.ScheduleEvent(EVENT_MOLTEN_BOLT, urand(35000, 40000));
                    break;
                }
            }

        DoMeleeAttackIfReady();
    }
};
};
class npc_firelands_unbound_pyrelord : public CreatureScript
{
public:
    npc_firelands_unbound_pyrelord() : CreatureScript("npc_firelands_unbound_pyrelord") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_firelands_unbound_pyrelordAI(pCreature);
    }

    struct npc_firelands_unbound_pyrelordAI : public ScriptedAI
    {
        npc_firelands_unbound_pyrelordAI(Creature* pCreature) : ScriptedAI(pCreature)
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
        int ignitElementalCount;
        void Reset() override
        {
            events.Reset();
            ignitElementalCount = 0;
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_IGNITE, urand(7000, 9000));
            events.ScheduleEvent(EVENT_IGNITE_ELEMENTAL, 5000);
        }

        void UpdateAI(uint32 diff) override
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
                case EVENT_IGNITE:
                    DoCastVictim(SPELL_IGNITE);
                    events.ScheduleEvent(EVENT_CONFLAGRATION, urand(8000, 12000));
                    break;
                case EVENT_IGNITE_ELEMENTAL:
                {
                    int pctHealth = 0;
                    switch (ignitElementalCount)
                    {
                    case 0:
                        pctHealth = 80;
                        break;
                    case 1:
                        pctHealth = 60;
                        break;
                    case 2:
                        pctHealth = 40;
                        break;
                    case 3:
                        pctHealth = 20;
                        break;

                    }
                        if (!HealthAbovePct(pctHealth))
                             {
                                std::list<Creature*> creatures;
                                me->GetCreatureListWithEntryInGrid(creatures, NPC_UNBOUND_SMOLDERING_ELEMENTAL, 100.0f);
                                if (!creatures.empty())
                                    {
                                        std::list<Creature*>::iterator iter;
                                        for (iter = creatures.begin(); iter != creatures.end(); iter++)
                                         {
                                            if ((*iter)->HasAura(SPELL_UNBREAKABLE_SHELL))
                                            {
                                                DoCast((*iter), SPELL_IGNITE_ELEMENTAL);
                                                (*iter)->RemoveAurasDueToSpell(SPELL_UNBREAKABLE_SHELL);
                                                ignitElementalCount++;
                                                break;
                                            }
                                         }
                                    }
                            }

                    events.ScheduleEvent(EVENT_IGNITE_ELEMENTAL, urand(5000, 5000));
                    break;
                }

                }
            }

            DoMeleeAttackIfReady();
        }
    };
};
class npc_firelands_flamewaker_cauterizer : public CreatureScript
{
public:
    npc_firelands_flamewaker_cauterizer() : CreatureScript("npc_firelands_flamewaker_cauterizer") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_firelands_flamewaker_cauterizerAI(pCreature);
    }

    struct npc_firelands_flamewaker_cauterizerAI : public ScriptedAI
    {
        npc_firelands_flamewaker_cauterizerAI(Creature* pCreature) : ScriptedAI(pCreature)
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
            events.ScheduleEvent(EVENT_CAUTERIZE, urand(7000, 9000));
            events.ScheduleEvent(EVENT_CONFLAGRATION, urand(8000, 20000));
            events.ScheduleEvent(EVENT_FLAME_SHIELD, urand(5000, 10000));
        }

        void UpdateAI(uint32 diff) override
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
                case EVENT_CAUTERIZE:
                {
                   std::list<Creature*> creatures;
                   me->GetCreatureListWithEntryInGrid(creatures, NPC_FLAMEWAKER_SENTINEL, 30.0f);
                   if (!creatures.empty())
                   {
                        Trinity::Containers::RandomResize(creatures, 1);
                        if (Creature* pTarget = creatures.front())
                           DoCast(pTarget, SPELL_CAUTERIZE, true);
                    }

                    events.ScheduleEvent(EVENT_CAUTERIZE, urand(15000, 20000));
                 break;
                }
                case EVENT_CONFLAGRATION:
                    DoCastVictim(SPELL_CONFLAGRATION);
                    events.ScheduleEvent(EVENT_CONFLAGRATION, urand(20000, 25000));
                    break;
                case EVENT_FLAME_SHIELD:
                    DoCast(me, SPELL_FLAME_SHIELD);
                    events.ScheduleEvent(EVENT_FLAME_SHIELD, urand(25000, 30000));
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};
class npc_firelands_flamewaker_animator : public CreatureScript
{
public:
    npc_firelands_flamewaker_animator() : CreatureScript("npc_firelands_flamewaker_animator") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_firelands_flamewaker_animatorAI(pCreature);
    }

    struct npc_firelands_flamewaker_animatorAI : public ScriptedAI
    {
        npc_firelands_flamewaker_animatorAI(Creature* pCreature) : ScriptedAI(pCreature)
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
            me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PREPARATION);

            magma = nullptr;
        }

        EventMap events;

        void Reset() override
        {
            events.Reset();
            me->AddAura(SPELL_DEFENSIVE_CASTING, me);
        }

        void DoAction(int32 const param) override
        {
            switch (param)
            {
                case ACTION_STOP_CHANNELING:
                    me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                    break;
                default:
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (!me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            {
                magma = me->FindNearestCreature(NPC_UNSTABLE_MAGMA, 100, true);

                if (magma != nullptr)
                    me->CastSpell(magma, SPELL_MAGMA_CHARGING, true);
            }

            events.ScheduleEvent(EVENT_CHECK_MAGMA, 1000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (magma == nullptr)
                magma = me->FindNearestCreature(NPC_UNSTABLE_MAGMA, 100, true);

            if (magma != nullptr)
                magma->GetAI()->DoAction(ACTION_ANIMATOR_DEATH);

        }
        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHECK_MAGMA:
                    {
                        if (magma)
                        {
                            uint32 energy = magma->GetPower(POWER_MANA);
                            energy += (me->HasAura(SPELL_BURNING_MOTIVATION) ? 2 : 1);
                            magma->SetPower(POWER_MANA, energy);
                        }

                        events.Repeat(IsHeroic() ? 3000 : 4000);
                        break;
                    }
                }
            }


        }
    private :
        Creature* magma;
    };
};
class npc_firelands_unstable_magma : public CreatureScript
{
public:
    npc_firelands_unstable_magma() : CreatureScript("npc_firelands_unstable_magma") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_firelands_unstable_magmaAI(pCreature);
    }

    struct npc_firelands_unstable_magmaAI : public ScriptedAI
    {
        npc_firelands_unstable_magmaAI(Creature* pCreature) : ScriptedAI(pCreature)
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
            animatorDeadCount = 0;
        }

        EventMap events;

        void Reset() override
        {
            animatorDeadCount = 0;
            events.Reset();
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_MANA, 100);
            me->SetPower(POWER_MANA, 0);
            me->CastSpell(me, SPELL_SUPER_HEATED,true);
            me->CastSpell(me, SPELL_STABILIZED,true);
        }
        void DoAction(int32 const param) override
        {
            switch (param)
            {
                case ACTION_ANIMATOR_DEATH:
                    animatorDeadCount++;
                    if (animatorDeadCount >= 3)
                    {
                        if (me->HasAura(SPELL_STABILIZED))
                        {
                            events.CancelEvent(EVENT_CHECK_MAGMA);
                            me->RemoveAurasDueToSpell(SPELL_STABILIZED);
                            me->CastSpell(me, SPELL_CONSUMING_FLAMES, true);
                            DoZoneInCombat(me, 50);
                        }
                    }
                    break;
                case ACTION_FULL_CHARGED:
                    if (me->HasAura(SPELL_STABILIZED))
                    {
                        me->RemoveAurasDueToSpell(SPELL_STABILIZED);
                        me->CastSpell(me, SPELL_CONSUMING_FLAMES, true);
                        DoZoneInCombat(me, 50);
                    }
                    break;
                default:
                    break;
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {

        }

        void UpdateAI(uint32 diff) override
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
                    case EVENT_LAVA_SURGE:
                        me->CastSpell(me->GetVictim(), SPELL_LAVA_SURGE);
                        events.Repeat(7000, 15000);
                        break;
                    case EVENT_PYROCLASM:
                        me->CastSpell(me, SPELL_PYROCLASM, true);
                        events.CancelEvent(EVENT_CHECK_MAGMA);
                        events.CancelEvent(EVENT_PYROCLASM);
                        break;
                    case EVENT_CHECK_MAGMA:
                        if (me->GetPower(POWER_MANA) >= 100)
                            events.ScheduleEvent(EVENT_PYROCLASM, 100);

                        DoAction(ACTION_FULL_CHARGED);
                        events.Repeat(1500);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private :
        uint32 animatorDeadCount;
    };
};
class npc_firelands_flamewaker_subjugator : public CreatureScript
{
public:
    npc_firelands_flamewaker_subjugator() : CreatureScript("npc_firelands_flamewaker_subjugator") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_firelands_flamewaker_subjugatorAI(pCreature);
    }

    struct npc_firelands_flamewaker_subjugatorAI : public ScriptedAI
    {
        npc_firelands_flamewaker_subjugatorAI(Creature* pCreature) : ScriptedAI(pCreature)
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

        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (HealthBelowPct(75))
            {
                if (!firstProcent)
                {
                    events.ScheduleEvent(EVENT_BURNING_MOTIVATION, 100);
                    firstProcent = true;
                }
                else if (HealthBelowPct(50))
                {
                    if (!secondProcent)
                    {
                        events.ScheduleEvent(EVENT_BURNING_MOTIVATION, 100);
                        secondProcent = true;
                    }
                    else if (HealthBelowPct(25))
                    {
                        if (!thirdProcent)
                        {
                            events.ScheduleEvent(EVENT_BURNING_MOTIVATION, 100);
                            thirdProcent = true;
                        }
                    }
                }
            }

            if (HealthBelowPct(30))
                if (!me->HasAura(SPELL_FURIOUS))
                    me->CastSpell(me, SPELL_FURIOUS, true);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BURNING_MOTIVATION:
                    {
                        std::list<Creature*> creature;
                        me->GetCreatureListWithEntryInGrid(creature, NPC_FLAMEWAKER_ANIMATOR, 100.0f);
                        if (!creature.empty())
                        {
                            for (std::list<Creature*>::const_iterator itr = creature.begin(); itr != creature.end(); ++itr)
                            {
                                if (Creature* animator = (*itr)->ToCreature())
                                {
                                    if (animator->HasAura(SPELL_DEFENSIVE_CASTING))
                                    {
                                        me->CastSpell(animator, SPELL_BURNING_MOTIVATION, true);
                                        animator->RemoveAurasDueToSpell(SPELL_DEFENSIVE_CASTING);
                                        break;
                                    }
                                }
                            }
                        }

                        events.CancelEvent(EVENT_BURNING_MOTIVATION);
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }
    private :
        bool firstProcent;
        bool secondProcent;
        bool thirdProcent;
    };
};
class npc_firelands_flamewaker_trainee : public CreatureScript
{
public:
    npc_firelands_flamewaker_trainee() : CreatureScript("npc_firelands_flamewaker_trainee") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_firelands_flamewaker_traineeAI(pCreature);
    }

    struct npc_firelands_flamewaker_traineeAI : public ScriptedAI
    {
        npc_firelands_flamewaker_traineeAI(Creature* pCreature) : ScriptedAI(pCreature)
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
            events.ScheduleEvent(EVENT_DEVASTATE, urand(5000, 9000));
            events.ScheduleEvent(EVENT_ENSNARE, urand(8000, 20000));
            events.ScheduleEvent(EVENT_FLAMING_SPEAR, urand(8000, 13000));
            events.ScheduleEvent(EVENT_MORTAL_STRIKE, urand(13000, 16000));
            events.ScheduleEvent(EVENT_SHOCKWAVE, urand(15000, 18000));
        }

        void UpdateAI(uint32 diff) override
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
                    case EVENT_DEVASTATE:
                        DoCastVictim(SPELL_DEVASTATE);
                        events.Repeat(10000, 15000);
                        break;
                    case EVENT_ENSNARE:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(pTarget, SPELL_ENSNARE);

                        events.Repeat(8000, 15000);
                        break;
                    case EVENT_FLAMING_SPEAR:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(pTarget, SPELL_FLAMING_SPEAR);

                        events.Repeat(8000, 13000);
                        break;
                    case EVENT_MORTAL_STRIKE:
                        DoCastVictim(SPELL_MORTAL_STRIKE);
                        events.Repeat(13000, 16000);
                        break;
                    case EVENT_SHOCKWAVE:
                        DoCastVictim(SPELL_SHOCKWAVE);
                        events.Repeat(25000, 28000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};
class npc_firelands_kar : public CreatureScript
{
public:
    npc_firelands_kar() : CreatureScript("npc_firelands_kar") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_firelands_karAI(pCreature);
    }

    struct npc_firelands_karAI : public ScriptedAI
    {
        npc_firelands_karAI(Creature* pCreature) : ScriptedAI(pCreature)
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
            aggroEventState = EVENT_KAR_AGGRO_NOT_DONE;
        }

        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        uint32 GetData(uint32 id) const override
        {
            switch (id)
            {
                case DATA_BEGIN_KAR:
                    return aggroEventState;
                    break;
            }
            return 0;

        }

        void SetData(uint32 id, uint32 value) override
        {
            switch (id)
            {
                case DATA_BEGIN_KAR:
                    aggroEventState = value;
                    break;
            }
        }

        void JustReachedHome() override
        {
            if (GetData(DATA_BEGIN_KAR) == EVENT_KAR_AGGRO_DONE)
            {
                std::list<Creature*> lava;
                GetCreatureListWithEntryInGrid(lava, me, NPC_LAVA_SPAWN, 100.0f);

                if (lava.empty())
                    return;

                for (std::list<Creature*>::iterator iter = lava.begin(); iter != lava.end(); ++iter)
                    (*iter)->DespawnOrUnsummon();

            }
            if (GetData(DATA_BEGIN_KAR) != EVENT_KAR_AGGRO_DONE)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, NPC_UNSTABLE_PYRELORD, 200.0f);

                if (creatures.empty())
                    return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    (*iter)->DespawnOrUnsummon();
                SetData(DATA_BEGIN_KAR, EVENT_KAR_AGGRO_NOT_DONE);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (GetData(DATA_BEGIN_KAR) == EVENT_KAR_AGGRO_DONE)
            {
                events.ScheduleEvent(EVENT_SOUL_BURN, urand(5000, 9000));
                events.ScheduleEvent(EVENT_SUMMON_LAVA, urand(8000, 13000));
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (GetData(DATA_BEGIN_KAR) == EVENT_KAR_AGGRO_DONE)
            {
                if (Player* p = who->ToPlayer())
                {
                    me->SetInCombatWith(p);
                }
            }
        }
        void DoAction(int32 const param) override
        {
            switch (param)
            {
                case KAR_ACTION_START_ENCOUNTER:
                    SetData(DATA_BEGIN_KAR, EVENT_KAR_AGGRO_LAUNCHED);
                    DoZoneInCombat(me,200);
                    events.ScheduleEvent(EVENT_ENCOUNTER_START, 100);
                    break;
                case KAR_ACTION_MOVE_BACK:
                    SetData(DATA_BEGIN_KAR, EVENT_KAR_AGGRO_DONE);
                    events.ScheduleEvent(EVENT_MOVE_BACK, 100);
                    break;
                case KAR_ACTION_ATTACK:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    events.ScheduleEvent(EVENT_SOUL_BURN, 1000);
                    events.ScheduleEvent(EVENT_SUMMON_LAVA, 3000);
                    break;
                default:
                    break;
            }
        }
        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 1)
            {
                if (GetData(DATA_BEGIN_KAR) == (uint32)EVENT_KAR_AGGRO_LAUNCHED)
                    SetData(DATA_BEGIN_KAR, EVENT_KAR_AGGRO_DONE);

                me->CastSpell(PyrelordUnstablePosition[10].GetPositionX(), PyrelordUnstablePosition[10].GetPositionY(), PyrelordUnstablePosition[10].GetPositionZ(), SPELL_SUMMON_FIRE, true);
                me->CastSpell(PyrelordUnstablePosition[9].GetPositionX(), PyrelordUnstablePosition[9].GetPositionY(), PyrelordUnstablePosition[9].GetPositionZ(), SPELL_SUMMON_FIRE, true);
                me->CastSpell(PyrelordUnstablePosition[8].GetPositionX(), PyrelordUnstablePosition[8].GetPositionY(), PyrelordUnstablePosition[8].GetPositionZ(), SPELL_SUMMON_FIRE, true);
                me->CastSpell(PyrelordUnstablePosition[7].GetPositionX(), PyrelordUnstablePosition[7].GetPositionY(), PyrelordUnstablePosition[7].GetPositionZ(), SPELL_SUMMON_FIRE, true);

            }
        }
        void UpdateAI(uint32 diff) override
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
                    case EVENT_ENCOUNTER_START:
                        me->CastSpell(me->GetPositionX() + 10, me->GetPositionY(), me->GetPositionZ(), SPELL_SUMMON_FIRE, true);
                        me->CastSpell(me->GetPositionX() - 10, me->GetPositionY(), me->GetPositionZ(), SPELL_SUMMON_FIRE, true);
                        me->CastSpell(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 10, SPELL_SUMMON_FIRE, true);
                        me->CastSpell(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() - 10, SPELL_SUMMON_FIRE, true);
                        events.ScheduleEvent(EVENT_SUMMON_FIRE_1, 500);
                        events.CancelEvent(EVENT_ENCOUNTER_START);
                        break;
                    case EVENT_SOUL_BURN:
                        DoCastVictim(SPELL_SOUL_BURN);
                        events.ScheduleEvent(EVENT_SOUL_BURN, urand(10000, 15000));
                        break;
                    case EVENT_SUMMON_FIRE_1:
                        me->CastSpell(PyrelordUnstablePosition[6].GetPositionX(), PyrelordUnstablePosition[6].GetPositionY(), PyrelordUnstablePosition[6].GetPositionZ(), SPELL_SUMMON_FIRE, true);
                        me->CastSpell(PyrelordUnstablePosition[5].GetPositionX(), PyrelordUnstablePosition[5].GetPositionY(), PyrelordUnstablePosition[5].GetPositionZ(), SPELL_SUMMON_FIRE, true);
                        me->CastSpell(PyrelordUnstablePosition[4].GetPositionX(), PyrelordUnstablePosition[4].GetPositionY(), PyrelordUnstablePosition[4].GetPositionZ(), SPELL_SUMMON_FIRE, true);
                        events.ScheduleEvent(EVENT_SUMMON_FIRE_2, 3000);
                        events.CancelEvent(EVENT_SUMMON_FIRE_1);
                        break;
                    case EVENT_SUMMON_FIRE_2:
                        me->CastSpell(PyrelordUnstablePosition[3].GetPositionX(), PyrelordUnstablePosition[3].GetPositionY(), PyrelordUnstablePosition[3].GetPositionZ(), SPELL_SUMMON_FIRE, true);
                        me->CastSpell(PyrelordUnstablePosition[2].GetPositionX(), PyrelordUnstablePosition[2].GetPositionY(), PyrelordUnstablePosition[2].GetPositionZ(), SPELL_SUMMON_FIRE, true);
                        me->CastSpell(PyrelordUnstablePosition[1].GetPositionX(), PyrelordUnstablePosition[1].GetPositionY(), PyrelordUnstablePosition[1].GetPositionZ(), SPELL_SUMMON_FIRE, true);
                        events.ScheduleEvent(EVENT_SUMMON_FIRE_3, 2000);
                        events.CancelEvent(EVENT_SUMMON_FIRE_2);
                        break;
                    case EVENT_SUMMON_FIRE_3:
                        me->CastSpell(PyrelordUnstablePosition[0].GetPositionX(), PyrelordUnstablePosition[0].GetPositionY(), PyrelordUnstablePosition[0].GetPositionZ(), SPELL_SUMMON_FIRE, true);
                        events.CancelEvent(EVENT_SUMMON_FIRE_3);
                        break;
                    case EVENT_MOVE_BACK:
                        //Kar va a son deuxieme point

                        SetData(DATA_BEGIN_KAR, EVENT_KAR_AGGRO_DONE);
                        me->SetHomePosition(KarSecondPosition[0].GetPositionX(), KarSecondPosition[0].GetPositionY(), KarSecondPosition[0].GetPositionZ(), 0);
                        me->GetMotionMaster()->MovePoint(1, KarSecondPosition[0].GetPositionX(), KarSecondPosition[0].GetPositionY(), KarSecondPosition[0].GetPositionZ());
                        break;
                    case EVENT_SUMMON_LAVA:
                        DoCast(me,SPELL_SUMMON_LAVA,true);
                        events.ScheduleEvent(EVENT_SUMMON_LAVA, urand(50000, 60000));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:

        uint32 aggroEventState;
    };
};
class AreaTrigger_event_kar : public AreaTriggerScript
{
public:
    AreaTrigger_event_kar() : AreaTriggerScript("at_event_kar") {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool /*entered*/) override
    {
        if (Creature *kar = player->FindNearestCreature(NPC_KAR, 300, true))
            if (kar->GetAI()->GetData(DATA_BEGIN_KAR) == EVENT_KAR_AGGRO_NOT_DONE)
                if (Creature* Kar = player->FindNearestCreature(NPC_KAR, 200, true))
                    Kar->GetAI()->DoAction(KAR_ACTION_START_ENCOUNTER);

        return true;
    }
};

class AreaTrigger_event_kar_moveback : public AreaTriggerScript
{
public:
    AreaTrigger_event_kar_moveback() : AreaTriggerScript("at_event_kar_moveback") {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool /*entered*/) override
    {
        if (Creature *kar = player->FindNearestCreature(NPC_KAR, 200, true))
            if (kar->GetAI()->GetData(DATA_BEGIN_KAR) == EVENT_KAR_AGGRO_LAUNCHED)
                if (kar)
                    kar->GetAI()->DoAction(KAR_ACTION_MOVE_BACK);

        return true;
    }
};
class AreaTrigger_event_kar_attack : public AreaTriggerScript
{
public:
    AreaTrigger_event_kar_attack() : AreaTriggerScript("at_event_kar_attack") {}

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool /*entered*/) override
    {
        if (Creature *kar = player->FindNearestCreature(NPC_KAR, 200, true))
            if (kar->GetAI()->GetData(DATA_BEGIN_KAR) == EVENT_KAR_AGGRO_DONE)
                if (kar)
                    kar->GetAI()->DoAction(KAR_ACTION_ATTACK);

        return true;
    }

};
class npc_firelands_flamewaker_cauterizer_two : public CreatureScript
{
public:
    npc_firelands_flamewaker_cauterizer_two() : CreatureScript("npc_firelands_flamewaker_cauterizer_two") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_firelands_flamewaker_cauterizer_twoAI(pCreature);
    }

    struct npc_firelands_flamewaker_cauterizer_twoAI : public ScriptedAI
    {
        npc_firelands_flamewaker_cauterizer_twoAI(Creature* pCreature) : ScriptedAI(pCreature)
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
            events.ScheduleEvent(EVENT_CAUTERIZE, urand(7000, 9000));
            events.ScheduleEvent(EVENT_CONFLAGRATION, urand(8000, 20000));
        }

        void UpdateAI(uint32 diff) override
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
                    case EVENT_CAUTERIZE:
                    {
                        std::list<Creature*> creatures;
                        me->GetCreatureListWithEntryInGrid(creatures, NPC_FLAMEWAKER_SENTINEL, 30.0f);
                        if (!creatures.empty())
                        {
                            Trinity::Containers::RandomResize(creatures, 1);
                            if (Creature* pTarget = creatures.front())
                               DoCast(pTarget, SPELL_CAUTERIZE, true);
                        }

                        events.Repeat(Seconds(15), Seconds(20));
                        break;
                    }
                    case EVENT_CONFLAGRATION:
                        DoCastVictim(SPELL_CONFLAGRATION);
                        events.Repeat(Seconds(20), Seconds(25));
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};
class npc_firelands_ancient_core_hound : public CreatureScript
{
    public:
        npc_firelands_ancient_core_hound() : CreatureScript("npc_firelands_ancient_core_hound") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_firelands_ancient_core_houndAI (pCreature);
        }

        struct npc_firelands_ancient_core_houndAI : public ScriptedAI
        {
            npc_firelands_ancient_core_houndAI(Creature* pCreature) : ScriptedAI(pCreature)
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
                events.ScheduleEvent(EVENT_DINNER_TIME, urand (15000, 20000));
                events.ScheduleEvent(EVENT_TERRIFYING_ROAR, urand(8000, 20000));
                events.ScheduleEvent(EVENT_FLAME_BREATH, urand(5000, 10000));
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_DINNER_TIME:
                            DoCastVictim(SPELL_DINNER_TIME);
                            events.Repeat(30000, 40000);
                            break;
                        case EVENT_FLAME_BREATH:
                            DoCastVictim(SPELL_FLAME_BREATH);
                            events.Repeat(15000, 20000);
                            break;
                        case EVENT_TERRIFYING_ROAR:
                            DoCast(me, SPELL_TERRIFYING_ROAR);
                            events.Repeat(30000, 35000);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};
class npc_firelands_ancient_lava_dweller : public CreatureScript
{
    public:
        npc_firelands_ancient_lava_dweller() : CreatureScript("npc_firelands_ancient_lava_dweller") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_firelands_ancient_lava_dwellerAI (pCreature);
        }

        struct npc_firelands_ancient_lava_dwellerAI : public Scripted_NoMovementAI
        {
            npc_firelands_ancient_lava_dwellerAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
            }

            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_LAVA_SHOWER, urand(15000, 20000));
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_LAVA_SHOWER:
                            DoCast(me, SPELL_LAVA_SHOWER);
                            events.ScheduleEvent(EVENT_LAVA_SHOWER, urand(45000, 55000));
                            break;
                    }
                }

                DoSpellAttackIfReady(SPELL_LAVA_SPIT);
            }
        };
};

class npc_firelands_fire_scorpion : public CreatureScript
{
    public:
        npc_firelands_fire_scorpion() : CreatureScript("npc_firelands_fire_scorpion") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_firelands_fire_scorpionAI (pCreature);
        }

        struct npc_firelands_fire_scorpionAI : public ScriptedAI
        {
            npc_firelands_fire_scorpionAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SNARE, true);
            }

            void JustDied(Unit* /*killer*/) override
            {
                DoCast(me, SPELL_FIERY_BLOOD);
            }
        };
};

class npc_firelands_fire_turtle_hatchling : public CreatureScript
{
    public:
        npc_firelands_fire_turtle_hatchling() : CreatureScript("npc_firelands_fire_turtle_hatchling") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_firelands_fire_turtle_hatchlingAI (pCreature);
        }

        struct npc_firelands_fire_turtle_hatchlingAI : public ScriptedAI
        {
            npc_firelands_fire_turtle_hatchlingAI(Creature* pCreature) : ScriptedAI(pCreature)
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
                events.ScheduleEvent(EVENT_SHELL_SPIN, urand(10000, 20000));
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_SHELL_SPIN:
                            DoCast(me, SPELL_SHELL_SPIN);
                            events.ScheduleEvent(EVENT_SHELL_SPIN, urand(35000, 50000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_firelands_flame_archon : public CreatureScript
{
    public:
        npc_firelands_flame_archon() : CreatureScript("npc_firelands_flame_archon") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_firelands_flame_archonAI (pCreature);
        }

        struct npc_firelands_flame_archonAI : public ScriptedAI
        {
            npc_firelands_flame_archonAI(Creature* pCreature) : ScriptedAI(pCreature)
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
                events.ScheduleEvent(EVENT_FLAME_TORRENT, 10000);
                events.ScheduleEvent(EVENT_FIERY_TORMENT, 20000);
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_FLAME_TORRENT:
                            DoCast(me, SPELL_FLAME_TORRENT);
                            events.ScheduleEvent(EVENT_FLAME_TORRENT, 40000);
                            break;
                        case EVENT_FIERY_TORMENT:
                            DoCast(me, SPELL_FIERY_TORMENT);
                            events.ScheduleEvent(EVENT_FIERY_TORMENT, 40000);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_firelands_molten_lord : public CreatureScript
{
    public:
        npc_firelands_molten_lord() : CreatureScript("npc_firelands_molten_lord") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_firelands_molten_lordAI (pCreature);
        }

        struct npc_firelands_molten_lordAI : public ScriptedAI
        {
            npc_firelands_molten_lordAI(Creature* pCreature) : ScriptedAI(pCreature)
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
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_FLAME_STOMP, 5000);
                events.ScheduleEvent(EVENT_MELT_ARMOR, urand(3000, 7000));
                events.ScheduleEvent(EVENT_SUMMON_LAVA_JETS, 10000);
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_FLAME_STOMP:
                            DoCast(me, SPELL_FLAME_STOMP);
                            events.ScheduleEvent(EVENT_FLAME_STOMP, urand(10000, 18000));
                            break;
                        case EVENT_MELT_ARMOR:
                            DoCastVictim(SPELL_MELT_ARMOR);
                            events.ScheduleEvent(EVENT_MELT_ARMOR, urand(7000, 14000));
                            break;
                        case EVENT_SUMMON_LAVA_JETS:
                            DoCast(me, SPELL_SUMMON_LAVA_JETS);
                            events.ScheduleEvent(EVENT_SUMMON_LAVA_JETS, urand(20000, 25000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_firelands_molten_flamefather : public CreatureScript
{
    public:
        npc_firelands_molten_flamefather() : CreatureScript("npc_firelands_molten_flamefather") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_firelands_molten_flamefatherAI (pCreature);
        }

        struct npc_firelands_molten_flamefatherAI : public ScriptedAI
        {
            npc_firelands_molten_flamefatherAI(Creature* pCreature) : ScriptedAI(pCreature), summons(me)
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
            SummonList summons;

            void Reset() override
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_EARTHQUAKE, urand(5000, 10000));
                events.ScheduleEvent(EVENT_MAGMA_CONDUIT, urand(6000, 7000));
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
                if (me->IsInCombat())
                    DoZoneInCombat(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_EARTHQUAKE:
                            DoCastAOE(SPELL_EARTHQUAKE);
                            events.ScheduleEvent(EVENT_EARTHQUAKE, urand(10000, 15000));
                            break;
                        case EVENT_MAGMA_CONDUIT:
                            DoCastAOE(SPELL_MAGMA_CONDUIT);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_firelands_magma_conduit : public CreatureScript
{
    public:
        npc_firelands_magma_conduit() : CreatureScript("npc_firelands_magma_conduit") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_firelands_magma_conduitAI (pCreature);
        }

        struct npc_firelands_magma_conduitAI : public Scripted_NoMovementAI
        {
            npc_firelands_magma_conduitAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature), summons(me)
            {
                me->SetReactState(REACT_PASSIVE);
            }

            SummonList summons;

            void Reset() override
            {
                summons.DespawnAll();
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
                if (me->IsInCombat())
                    DoZoneInCombat(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!UpdateVictim())
                {
                    me->DespawnOrUnsummon();
                    return;
                }
            }
        };
};

class npc_firelands_magmakin : public CreatureScript
{
    public:
        npc_firelands_magmakin() : CreatureScript("npc_firelands_magmakin") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_firelands_magmakinAI (pCreature);
        }

        struct npc_firelands_magmakinAI : public ScriptedAI
        {
            npc_firelands_magmakinAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->SetSpeed(MOVE_RUN, 2.0f);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (!UpdateVictim())
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                if (me->GetDistance(me->GetVictim()) < 2.0f)
                    DoCastAOE(SPELL_ERUPTION, true);
            }
        };
};

class spell_firelands_ancient_core_hound_dinner_time : public SpellScriptLoader
{
    public:
        spell_firelands_ancient_core_hound_dinner_time() :  SpellScriptLoader("spell_firelands_ancient_core_hound_dinner_time") { }

        class spell_firelands_ancient_core_hound_dinner_time_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_firelands_ancient_core_hound_dinner_time_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                GetTarget()->SetControlled(true, UNIT_STATE_STUNNED);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                GetTarget()->SetControlled(false, UNIT_STATE_STUNNED);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_firelands_ancient_core_hound_dinner_time_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_firelands_ancient_core_hound_dinner_time_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_firelands_ancient_core_hound_dinner_time_AuraScript();
        }
};

class spell_firelands_ancient_core_hound_flame_breath : public SpellScriptLoader
{
    public:
        spell_firelands_ancient_core_hound_flame_breath() :  SpellScriptLoader("spell_firelands_ancient_core_hound_flame_breath") { }

        class spell_firelands_ancient_core_hound_flame_breath_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_firelands_ancient_core_hound_flame_breath_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                GetTarget()->SetControlled(true, UNIT_STATE_STUNNED);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                GetTarget()->SetControlled(false, UNIT_STATE_STUNNED);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_firelands_ancient_core_hound_flame_breath_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_firelands_ancient_core_hound_flame_breath_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_firelands_ancient_core_hound_flame_breath_AuraScript();
        }
};

class spell_firelands_ancient_lava_dweller_lava_shower : public SpellScriptLoader
{
    public:
        spell_firelands_ancient_lava_dweller_lava_shower() : SpellScriptLoader("spell_firelands_ancient_lava_dweller_lava_shower") { }

        class spell_firelands_ancient_lava_dweller_lava_shower_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_firelands_ancient_lava_dweller_lava_shower_AuraScript);

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (!GetCaster())
                    return;

                if (GetCaster()->GetAI())
                    if (Unit* pTarget = GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                        GetCaster()->CastSpell(pTarget, SPELL_LAVA_SHOWER_MISSILE, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_firelands_ancient_lava_dweller_lava_shower_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_firelands_ancient_lava_dweller_lava_shower_AuraScript();
        }
};

class spell_firelands_fire_turtle_hatchling_shell_spin : public SpellScriptLoader
{
    public:
        spell_firelands_fire_turtle_hatchling_shell_spin() :  SpellScriptLoader("spell_firelands_fire_turtle_hatchling_shell_spin") { }

        class spell_firelands_fire_turtle_hatchling_shell_spin_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_firelands_fire_turtle_hatchling_shell_spin_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                GetTarget()->SetControlled(true, UNIT_STATE_ROOT);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                GetTarget()->SetControlled(false, UNIT_STATE_ROOT);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_firelands_fire_turtle_hatchling_shell_spin_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_firelands_fire_turtle_hatchling_shell_spin_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_firelands_fire_turtle_hatchling_shell_spin_AuraScript();
        }
};

class spell_firelands_flame_archon_fiery_torment : public SpellScriptLoader
{
    public:
        spell_firelands_flame_archon_fiery_torment() :  SpellScriptLoader("spell_firelands_flame_archon_fiery_torment") { }

        class spell_firelands_flame_archon_fiery_torment_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_firelands_flame_archon_fiery_torment_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                GetTarget()->SetControlled(true, UNIT_STATE_STUNNED);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                GetTarget()->SetControlled(false, UNIT_STATE_STUNNED);
            }

            void PeriodicTick(AuraEffect const* /*aurEff*/)
            {
                if (!GetCaster())
                    return;

                if (GetCaster()->GetAI())
                    if (Unit* pTarget = GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_NEAREST, 0, 100.0f, true))
                        GetCaster()->CastSpell(pTarget, SPELL_FIERY_TORMENT_DMG, true);
            }


            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_firelands_flame_archon_fiery_torment_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_firelands_flame_archon_fiery_torment_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_firelands_flame_archon_fiery_torment_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_firelands_flame_archon_fiery_torment_AuraScript();
        }
};

class spell_firelands_molten_lord_summon_lava_jets : public SpellScriptLoader
{
    public:
        spell_firelands_molten_lord_summon_lava_jets() : SpellScriptLoader("spell_firelands_molten_lord_summon_lava_jets") { }


        class spell_firelands_molten_lord_summon_lava_jets_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_firelands_molten_lord_summon_lava_jets_SpellScript);


            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), 99538, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_firelands_molten_lord_summon_lava_jets_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_firelands_molten_lord_summon_lava_jets_SpellScript();
        }
};


enum Texts
{
    // Egg Pile
    EMOTE_CRACKING_EGGS         = 0,    // The Molten Eggs begin to crack and splinter!
};

#define SPELL_SHARE_HEALTH          (me->GetEntry() == NPC_BLAZING_MONSTROSITY_LEFT ? SPELL_SHARE_HEALTH_LEFT : SPELL_SHARE_HEALTH_RIGHT)
#define SPELL_MOLTEN_BARRAGE        (me->GetEntry() == NPC_BLAZING_MONSTROSITY_LEFT ? SPELL_MOLTEN_BARRAGE_LEFT : SPELL_MOLTEN_BARRAGE_RIGHT)
#define SPELL_MOLTEN_BARRAGE_EFFECT (me->GetEntry() == NPC_BLAZING_MONSTROSITY_LEFT ? SPELL_MOLTEN_BARRAGE_EFFECT_L : SPELL_MOLTEN_BARRAGE_EFFECT_R)

class RespawnEggEvent : public BasicEvent
{
    public:
        explicit RespawnEggEvent(Creature* egg) : _egg(egg) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _egg->RestoreDisplayId();
            return true;
        }

    private:
        Creature* _egg;
};

class MoltenEggCheck
{
    public:
        explicit MoltenEggCheck(Creature* pile) : _eggPile(pile) { }

        bool operator()(Unit* object) const
        {
            if (object->GetEntry() != NPC_MOLTEN_EGG_TRASH)
                return false;

            if (object->GetDisplayId() != object->GetNativeDisplayId())
                return false;

            if (_eggPile->GetDistance2d(object) > 20.0f)
                return false;

            return true;
        }

    private:
        Creature* _eggPile;
};

class TrashRespawnWorker
{
    public:
        void operator()(Creature* creature) const
        {
            switch (creature->GetEntry())
            {
                case NPC_BLAZING_MONSTROSITY_LEFT:
                case NPC_BLAZING_MONSTROSITY_RIGHT:
                case NPC_EGG_PILE:
                case NPC_HARBINGER_OF_FLAME:
                case NPC_MOLTEN_EGG_TRASH:
                    if (!creature->IsAlive())
                        creature->Respawn(true);
                    break;
                case NPC_SMOULDERING_HATCHLING:
                    creature->DespawnOrUnsummon();
                    break;
            }
        }
};

static void AlysrazorTrashEvaded(Creature* creature)
{
    TrashRespawnWorker check;
    Trinity::CreatureWorker<TrashRespawnWorker> worker(creature, check);
    Cell::VisitGridObjects(creature, worker, SIZE_OF_GRIDS);
}

class npc_majordomo_staghelm : public CreatureScript
{
public:
    npc_majordomo_staghelm() : CreatureScript("npc_majordomo_staghelm") { }

    struct npc_majordomo_staghelmAI : public ScriptedAI
    {
        npc_majordomo_staghelmAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void EnterCombat(Unit* /*target*/) override
        {
            _events.Reset();
            DoZoneInCombat(me, 200);
            _events.ScheduleEvent(EVENT_CRY_1, 1000);
        }

        void Reset() override
        {
            if (GameObject* volcano = me->FindNearestGameObject(GO_VOLCANO, 300))
            {
                volcano->ModifyHealth(1);
                volcano->SetDestructibleState(GO_DESTRUCTIBLE_INTACT);
            }
            me->GetMotionMaster()->MoveTargetedHome();
        }

        void DamageTaken(Unit* /*done_by*/, uint32& damage) override
        {
            if (damage > me->GetHealth())
                damage = me->GetHealth() - 1;
        }

        void JustReachedHome() override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
            {
                if (instance->GetData(DATA_MAJORDOMO_ALYSRAZOR) == EVENT_MAJORDOMO_DONE)
                {
                    me->DespawnOrUnsummon(10000);
                }
                else
                {
                    me->SetDisplayId(MI_MAJORDOMO);
                    me->SetCanFly(false);
                    me->SetDisableGravity(false);

                    std::list<Creature*> creatures;
                    GetCreatureListWithEntryInGrid(creatures, me, NPC_CAPTIVE_DRUID_OF_THE_TALON, 200.0f);

                    for (auto creature: creatures)
                        creature->Respawn();
                }
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
            {
                switch (id)
                {
                    case 1:
                    {
                        _events.ScheduleEvent(EVENT_SUMMON_ALYSRAZOR, 100);
                        break;
                    }
                    case 2:
                    {
                        if (Creature* alysrazor = me->FindNearestCreature(NPC_ALYSRAZOR, 300, true))
                        {
                            alysrazor->GetAI()->DoAction(ACTION_LAUNCH_EVENT_ALYSRAZOR);
                        }
                        else
                        {
                            Reset();
                            break;
                        }
                        me->DespawnOrUnsummon(10000);
                        break;
                    }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CRY_1:
                    {
                        Talk(MAJORDOMO_CRY_1);
                        _events.ScheduleEvent(EVENT_PLAYER_IMMOBILIZE, 1000);
                        _events.ScheduleEvent(EVENT_CRY_2, 4000);
                        break;
                    }
                    case EVENT_PLAYER_IMMOBILIZE:
                    {
                        std::list<Player*> players;
                        me->GetPlayerListInGrid(players, 100.0f);
                        for (auto player : players)
                        {
                            if (player)
                                player->CastSpell(player, SPELL_SMOULDERING_ROOTS);
                        }
                        break;
                    }
                    case EVENT_CRY_2:
                    {
                        Talk(MAJORDOMO_CRY_2);
                        _events.ScheduleEvent(EVENT_DRUID_KILL, 100);
                        _events.ScheduleEvent(EVENT_GROUND_TREMBLING, 1000);
                        _events.ScheduleEvent(EVENT_CRY_3, 5000);
                        break;
                    }
                    case EVENT_DRUID_KILL:
                    {
                        std::list<Creature*> creatures;
                        GetCreatureListWithEntryInGrid(creatures, me, NPC_CAPTIVE_DRUID_OF_THE_TALON, 200.0f);
                        for (auto creature : creatures)
                            me->CastSpell(creature, SPELL_SACRIFICE_TO_FLAME, true);

                        break;
                    }
                    case EVENT_GROUND_TREMBLING:
                        break;
                    case EVENT_CRY_3:
                        Talk(MAJORDOMO_CRY_3);
                        _events.ScheduleEvent(EVENT_GO_AWAY, 5000);
                        break;
                    case EVENT_GO_AWAY:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                        me->SetDisplayId(MI_HAWK);
                        me->SetCanFly(true);
                        me->SetDisableGravity(true);
                        me->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                        me->GetMotionMaster()->MovePoint(1, 77.05f, -379.10f, 135.54f);
                        break;
                    case EVENT_BREAK_VOLCANO:
                    {
                        if (InstanceScript * instance = me->GetInstanceScript())
                            instance->SetData(DATA_MAJORDOMO_ALYSRAZOR, EVENT_MAJORDOMO_DONE);

                        me->SetHomePosition(134.79f, -447.93f, 267.67f,0);
                        if (GameObject* volcano = me->FindNearestGameObject(GO_VOLCANO, 300))
                        {
                            volcano->ModifyHealth(-1000000);
                            volcano->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                        }

                        me->SetSpeed(MOVE_RUN, 5.0f);
                        me->SetSpeed(MOVE_FLIGHT, 5.0f);
                        me->GetMotionMaster()->MovePoint(2, 117.96f, -422.2151f, 184.279f);
                        break;
                    }
                    case EVENT_SUMMON_ALYSRAZOR:
                    {
                        if (Creature *alysrazor = me->SummonCreature(NPC_ALYSRAZOR, 108.0f, -408.306f, 21.55f))
                        {
                            alysrazor->CastSpell(alysrazor, SPELL_VOLCANO_TREMBLING_GROUND, true);
                        }
                        _events.ScheduleEvent(EVENT_BREAK_VOLCANO, 100);
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_majordomo_staghelmAI(creature);
    }
};

class npc_harbinger_of_flame : public CreatureScript
{
    public:
        npc_harbinger_of_flame() : CreatureScript("npc_harbinger_of_flame") { }

        struct npc_harbinger_of_flameAI : public ScriptedAI
        {
            npc_harbinger_of_flameAI(Creature* creature) : ScriptedAI(creature)
            {
            }
            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon();
            }
            void EnterCombat(Unit* /*target*/) override
            {
                if (Creature* bird = ObjectAccessor::GetCreature(*me, me->GetGuidValue(UNIT_DYNAMIC_FIELD_CHANNEL_OBJECTS)))
                    DoZoneInCombat(bird, 200.0f);

                me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                _events.Reset();
                _events.ScheduleEvent(EVENT_FIEROBLAST, 1);
                _events.ScheduleEvent(EVENT_FIEROCLAST_BARRAGE, 6000);
            }

            void JustReachedHome() override
            {
                AlysrazorTrashEvaded(me);
            }

            void MoveInLineOfSight(Unit* unit) override
            {
                if (me->IsInCombat())
                    return;

                if (!unit->IsCharmedOwnedByPlayerOrPlayer())
                    return;

                ScriptedAI::MoveInLineOfSight(unit);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!me->IsInCombat())
                    if (!me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                        if (Creature* fireBird = me->FindNearestCreature((me->GetHomePosition().GetPositionY() > -275.0f ? NPC_BLAZING_MONSTROSITY_LEFT : NPC_BLAZING_MONSTROSITY_RIGHT), 100.0f))
                            DoCast(fireBird, SPELL_FIRE_CHANNELING);

                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIEROBLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, false, -SPELL_RIDE_MONSTROSITY))
                                DoCast(target, SPELL_FIEROBLAST_TRASH);
                            _events.RescheduleEvent(EVENT_FIEROBLAST, 500);  // cast time is longer, but thanks to UNIT_STATE_CASTING check it won't trigger more often (need this because this creature gets a stacking haste aura)
                            break;
                        case EVENT_FIEROCLAST_BARRAGE:
                            DoCastAOE(SPELL_FIEROCLAST_BARRAGE);
                            _events.ScheduleEvent(EVENT_FIEROCLAST_BARRAGE, urand(9000, 12000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_harbinger_of_flameAI(creature);
        }
};

class npc_egg_pile : public CreatureScript
{
    public:
        npc_egg_pile() : CreatureScript("npc_egg_pile") { }

        struct npc_egg_pileAI : public CreatureAI
        {
            npc_egg_pileAI(Creature* creature) : CreatureAI(creature)
            {
            }

            void AttackStart(Unit* /*target*/) override { }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                _events.Reset();
                _callHatchlingSpell = 0;
            }

            void JustDied(Unit* /*killer*/) override
            {
                _events.Reset();
                std::list<Creature*> eggs;
                GetCreatureListWithEntryInGrid(eggs, me, NPC_MOLTEN_EGG_TRASH, 20.0f);
                for (std::list<Creature*>::const_iterator itr = eggs.begin(); itr != eggs.end(); ++itr)
                    (*itr)->CastSpell(*itr, SPELL_ALYSRAZOR_COSMETIC_EGG_XPLOSION, TRIGGERED_FULL_MASK);

                DoCast(me, SPELL_ALYSRAZOR_COSMETIC_EGG_XPLOSION, true);
            }

            void JustReachedHome() override
            {
                AlysrazorTrashEvaded(me);
            }

            void DoAction(int32 const action) override
            {
                if (action != NPC_BLAZING_MONSTROSITY_LEFT &&
                    action != NPC_BLAZING_MONSTROSITY_RIGHT)
                    return;

                if (action == NPC_BLAZING_MONSTROSITY_LEFT)
                    Talk(EMOTE_CRACKING_EGGS);

                _callHatchlingSpell = (action == NPC_BLAZING_MONSTROSITY_LEFT) ? SPELL_MOLTEN_EGG_TRASH_CALL_L : SPELL_MOLTEN_EGG_TRASH_CALL_R;
                DoZoneInCombat();
                _events.Reset();
                _events.ScheduleEvent(EVENT_SUMMON_SMOULDERING_HATCHLING, 1);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_SMOULDERING_HATCHLING:
                        {
                            std::list<Creature*> eggs;
                            MoltenEggCheck check(me);
                            GetCreatureListWithEntryInGrid(eggs, me, NPC_MOLTEN_EGG_TRASH, 20.0f);
                            //me->VisitNearbyGridObject(20.0f, eggs);
                            if (!eggs.empty())
                            {
                                Creature* egg = Trinity::Containers::SelectRandomContainerElement(eggs);
                                egg->CastSpell(egg, SPELL_SUMMON_SMOULDERING_HATCHLING, TRIGGERED_FULL_MASK);
                                egg->SetDisplayId(MODEL_INVISIBLE_STALKER);
                                egg->m_Events.AddEvent(new RespawnEggEvent(egg), egg->m_Events.CalculateTime(5000));
                            }
                            if (_callHatchlingSpell)
                                DoCastAOE(_callHatchlingSpell, true);
                            _events.ScheduleEvent(EVENT_SUMMON_SMOULDERING_HATCHLING, urand(6000, 10000));
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            uint32 _callHatchlingSpell;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_egg_pileAI(creature);
        }
};

class npc_firelands_dull_focus : public CreatureScript
{
    public:

        npc_firelands_dull_focus() : CreatureScript("npc_firelands_dull_focus") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
        {
            InstanceScript* pInstance = pCreature->GetInstanceScript();
            if (!pInstance)
                return true;

            if (!pPlayer)
                return true;

            if (pPlayer->GetQuestStatus(29234) != QUEST_STATUS_INCOMPLETE)
                return true;

            uint32 spellId = 0;

            switch (pCreature->GetEntry())
            {
                case NPC_DULL_RHYOLITH_FOCUS: spellId = SPELL_CHARGED_RHYOLITH_FOCUS; break;
                case NPC_DULL_EMBERSTONE_FOCUS: spellId = SPELL_CHARGED_EMBERSTONE_FOCUS; break;
                case NPC_DULL_CHITINOUS_FOCUS: spellId = SPELL_CHARGED_CHITINOUS_FOCUS; break;
                case NPC_DULL_PYRESHELL_FOCUS: spellId = SPELL_CHARGED_PYRESHELL_FOCUS; break;
                default: break;
            }

            if (spellId)
            {
                pPlayer->CastSpell(pPlayer, spellId, true);
                pCreature->DespawnOrUnsummon();
            }
            return true;
        }
};
//portail pour la zone de l'enclume lance quand l'EVENT_PORTALS est actif GO_CIRCLE_OF_THORNS_PORTAL3
class go_firelands_circle_of_thorns_portal : public GameObjectScript
{
    public:
        go_firelands_circle_of_thorns_portal() : GameObjectScript("go_firelands_circle_of_thorns_portal") { }

        bool OnGossipHello(Player* pPlayer, GameObject* go) override
        {
            InstanceScript* pInstance = go->GetInstanceScript();
            if (!pInstance)
                return true;

            if (!pPlayer)
                return true;

            if (pInstance->GetData(DATA_EVENT) != DONE)
                return true;

            bool bIn = (go->GetPositionZ() <= 100.0f);

            if (bIn)
            {
                pPlayer->NearTeleportTo(504.063416f, 476.256317f, 246.745483f, 2.30f, false);
            }
            else
                pPlayer->NearTeleportTo(173.153091f, 283.155334f, 84.603622f, 3.69f, false);

            return true;
        }
};
//volcanus est un pnj de l'encounter de la zone speciale debloquée par la quete legendaire
class npc_firelands_volcanus : public CreatureScript
{
    public:
        npc_firelands_volcanus() : CreatureScript("npc_firelands_volcanus") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_firelands_volcanusAI(creature);
        }

        struct npc_firelands_volcanusAI : public CreatureAI
        {
            npc_firelands_volcanusAI(Creature* creature) : CreatureAI(creature)
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
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
            }

            void Reset() override
            {
                me->SetFloatValue(UNIT_FIELD_BOUNDINGRADIUS, 7);
                me->SetFloatValue(UNIT_FIELD_COMBATREACH, 7);
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_FLAMEWAKE, 3000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* pStalker = me->SummonCreature(NPC_STALKER, me->GetHomePosition(), TEMPSUMMON_TIMED_DESPAWN, 10000))
                {
                    pStalker->RemoveAllAuras();
                    pStalker->CastSpell(pStalker, SPELL_BRANCH_OF_NORDRASSIL_WIN_COSMETIC);
                }
                me->DespawnOrUnsummon(500);
            }

            void UpdateAI(uint32 diff) override
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
                        case EVENT_FLAMEWAKE:
                            DoCastAOE(SPELL_FLAMEWAKE);
                            DoCast(me, SPELL_FIRE_IT_UP, true);
                            events.ScheduleEvent(EVENT_FLAMEWAKE, 10000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };
};

class spell_alysrazor_cosmetic_egg_xplosion : public SpellScriptLoader
{
    public:
        spell_alysrazor_cosmetic_egg_xplosion() : SpellScriptLoader("spell_alysrazor_cosmetic_egg_xplosion") { }

        class spell_alysrazor_cosmetic_egg_xplosion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_alysrazor_cosmetic_egg_xplosion_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sCreatureDisplayInfoStore.LookupEntry(MODEL_INVISIBLE_STALKER))
                    return false;
                return true;
            }

            void HandleExplosion(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->SetDisplayId(MODEL_INVISIBLE_STALKER);
                if (Creature* creature = GetHitCreature())
                    creature->DespawnOrUnsummon(4000);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_alysrazor_cosmetic_egg_xplosion_SpellScript::HandleExplosion, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_alysrazor_cosmetic_egg_xplosion_SpellScript();
        }
};

class spell_alysrazor_turn_monstrosity : public SpellScriptLoader
{
    public:
        spell_alysrazor_turn_monstrosity() : SpellScriptLoader("spell_alysrazor_turn_monstrosity") { }

        class spell_alysrazor_turn_monstrosity_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_alysrazor_turn_monstrosity_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_GENERIC_DUMMY_CAST))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_KNOCKBACK_RIGHT))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_KNOCKBACK_LEFT))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_KNOCKBACK_FORWARD))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_KNOCKBACK_BACK))
                    return false;
                return true;
            }

            void KnockBarrage(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->GetMotionMaster()->MoveIdle();
                if (TempSummon* summ = GetHitUnit()->ToTempSummon())
                    if (Unit* summoner = summ->GetSummoner())
                        GetHitUnit()->CastSpell(summoner, SPELL_GENERIC_DUMMY_CAST, TRIGGERED_FULL_MASK);

                float angle = 0.0f;
                if (Unit* bird = GetCaster()->GetVehicleBase())
                {
                    bird->SetInFront(GetHitUnit());
                    angle = bird->GetOrientation();
                }

                uint32 spellId = 0;
                switch (GetSpellInfo()->Id)
                {
                    case SPELL_RIGHT_SIDE_SMACK_R:
                    case SPELL_RIGHT_SIDE_SMACK_L:
                        spellId = SPELL_KNOCKBACK_RIGHT;
                        angle -= float(M_PI) * 0.5f;
                        break;
                    case SPELL_LEFT_SIDE_SMACK_R:
                    case SPELL_LEFT_SIDE_SMACK_L:
                        spellId = SPELL_KNOCKBACK_LEFT;
                        angle += float(M_PI) * 0.5f;
                        break;
                    case SPELL_HEAD_BONK_R:
                    case SPELL_HEAD_BONK_L:
                        spellId = SPELL_KNOCKBACK_FORWARD;
                        break;
                    case SPELL_TICKLE_R:
                    case SPELL_TICKLE_L:
                        spellId = SPELL_KNOCKBACK_BACK;
                        angle -= float(M_PI);
                        break;
                }

                // Cannot wait for object update to process facing spline, it's needed in next spell cast
                GetHitUnit()->SetOrientation(angle);
                GetHitUnit()->SetFacingTo(angle);
                GetHitUnit()->AddUnitState(UNIT_STATE_CANNOT_TURN);
                GetHitUnit()->CastSpell(GetHitUnit(), spellId, TRIGGERED_FULL_MASK);
            }

            void TurnBird(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->PlayOneShotAnimKitId(ANIM_KIT_BIRD_TURN);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_alysrazor_turn_monstrosity_SpellScript::KnockBarrage, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffectHitTarget += SpellEffectFn(spell_alysrazor_turn_monstrosity_SpellScript::TurnBird, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_alysrazor_turn_monstrosity_SpellScript();
        }
};

class spell_alysrazor_aggro_closest : public SpellScriptLoader
{
    public:
        spell_alysrazor_aggro_closest() : SpellScriptLoader("spell_alysrazor_aggro_closest") { }

        class spell_alysrazor_aggro_closest_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_alysrazor_aggro_closest_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void HandleEffect(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                float curThreat = GetCaster()->getThreatManager().getThreat(GetHitUnit(), true);
                GetCaster()->getThreatManager().addThreat(GetHitUnit(), -curThreat + 50000.0f / std::min(1.0f, GetCaster()->GetDistance(GetHitUnit())));
            }

            void UpdateThreat()
            {
                GetCaster()->ClearUnitState(UNIT_STATE_CASTING);
                GetCaster()->GetAI()->AttackStart(GetCaster()->ToCreature()->SelectVictim());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_alysrazor_aggro_closest_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
                AfterCast += SpellCastFn(spell_alysrazor_aggro_closest_SpellScript::UpdateThreat);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_alysrazor_aggro_closest_SpellScript();
        }
};

void AddSC_firelands()
{
    new npc_firelands_ancient_core_hound();
    new npc_firelands_ancient_lava_dweller();
    new npc_firelands_fire_scorpion();
    new npc_firelands_fire_turtle_hatchling();
    new npc_firelands_flame_archon();
    new npc_firelands_molten_lord();
    new npc_firelands_molten_flamefather();
    new npc_firelands_magma_conduit();
    new npc_firelands_magmakin();
    new npc_firelands_flamewaker_cauterizer();
    new npc_firelands_flamewaker_cauterizer_two();
    new npc_firelands_flamewaker_trainee();
    new npc_firelands_flamewaker_animator();
    new npc_firelands_flamewaker_subjugator();
    new npc_firelands_unstable_magma();
    new npc_firelands_kar();
    new AreaTrigger_event_kar();
    new AreaTrigger_event_kar_moveback();
    new AreaTrigger_event_kar_attack();
    new npc_firelands_unbound_pyrelord();
    new npc_firelands_molten_erupter();

    new npc_firelands_molten_spewer();

    new spell_firelands_ancient_core_hound_dinner_time();
    new spell_firelands_ancient_core_hound_flame_breath();
    new spell_firelands_ancient_lava_dweller_lava_shower();
    new spell_firelands_fire_turtle_hatchling_shell_spin();
    new spell_firelands_flame_archon_fiery_torment();
    new spell_firelands_molten_lord_summon_lava_jets();

    // alysrazor event
    new npc_harbinger_of_flame();
    new npc_egg_pile();
    new spell_alysrazor_cosmetic_egg_xplosion();
    new spell_alysrazor_turn_monstrosity();
    new spell_alysrazor_aggro_closest();

    new npc_firelands_dull_focus();
    new go_firelands_circle_of_thorns_portal();
    new npc_firelands_volcanus();
    new npc_majordomo_staghelm();
}
