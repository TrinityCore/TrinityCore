/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
SDName: Boss_Felblood_Kaelthas
SD%Complete: 80
SDComment: Normal and Heroic Support. Issues: Arcane Spheres do not initially follow targets.
SDCategory: Magisters' Terrace
EndScriptData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "magisters_terrace.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum Says
{
    SAY_AGGRO                   = 0,                //This yell should be done when the room is cleared. For now, set it as a movelineofsight yell.
    SAY_PHOENIX                 = 1,
    SAY_FLAMESTRIKE             = 2,
    SAY_GRAVITY_LAPSE           = 3,
    SAY_TIRED                   = 4,
    SAY_RECAST_GRAVITY          = 5,
    SAY_DEATH                   = 6
};


enum Spells
{
    // Phase 1 spells
    SPELL_FIREBALL_NORMAL         = 44189,                 // Deals 2700-3300 damage at current target
    SPELL_FIREBALL_HEROIC         = 46164,                 //       4950-6050

    SPELL_PHOENIX                 = 44194,                 // Summons a phoenix (Doesn't work?)
    SPELL_PHOENIX_BURN            = 44197,                 // A spell Phoenix uses to damage everything around
    SPELL_REBIRTH_DMG             = 44196,                 // DMG if a Phoenix rebirth happen

    SPELL_FLAMESTRIKE1_NORMAL     = 44190,                 // Damage part
    SPELL_FLAMESTRIKE1_HEROIC     = 46163,                 // Heroic damage part
    SPELL_FLAMESTRIKE2            = 44191,                 // Flamestrike indicator before the damage
    SPELL_FLAMESTRIKE3            = 44192,                 // Summons the trigger + animation (projectile)

    SPELL_SHOCK_BARRIER           = 46165,                 // Heroic only; 10k damage shield, followed by Pyroblast
    SPELL_PYROBLAST               = 36819,                 // Heroic only; 45-55k fire damage

// Phase 2 spells
    SPELL_GRAVITY_LAPSE_INITIAL   = 44224,                 // Cast at the beginning of every Gravity Lapse
    SPELL_GRAVITY_LAPSE_CHANNEL   = 44251,                 // Channeled; blue beam animation to every enemy in range
    SPELL_TELEPORT_CENTER         = 44218,                 // Should teleport people to the center. Requires DB entry in spell_target_position.
    SPELL_GRAVITY_LAPSE_FLY       = 44227,                 // Hastens flyspeed and allows flying for 1 minute. For some reason removes 44226.
    SPELL_GRAVITY_LAPSE_DOT       = 44226,                 // Knocks up in the air and applies a 300 DPS DoT.
    SPELL_ARCANE_SPHERE_PASSIVE   = 44263,                 // Passive auras on Arcane Spheres
    SPELL_POWER_FEEDBACK          = 44233                 // Stuns him, making him take 50% more damage for 10 seconds. Cast after Gravity Lapse
};



enum Creatures
{
    CREATURE_PHOENIX              = 24674,
    CREATURE_PHOENIX_EGG          = 24675,
    CREATURE_ARCANE_SPHERE        = 24708
};


/** Locations **/
float KaelLocations[3][2]=
{
    {148.744659f, 181.377426f},
    {140.823883f, 195.403046f},
    {156.574188f, 195.650482f},
};

#define LOCATION_Z                  -16.727455f

class boss_felblood_kaelthas : public CreatureScript
{
public:
    boss_felblood_kaelthas() : CreatureScript("boss_felblood_kaelthas") { }

    CreatureAI* GetAI(Creature* c) const override
    {
        return GetMagistersTerraceAI<boss_felblood_kaelthasAI>(c);
    }

    struct boss_felblood_kaelthasAI : public ScriptedAI
    {
        boss_felblood_kaelthasAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            /// @todo Timers
            FireballTimer = 0;
            PhoenixTimer = 10000;
            FlameStrikeTimer = 25000;
            CombatPulseTimer = 0;

            PyroblastTimer = 60000;

            GravityLapseTimer = 0;
            GravityLapsePhase = 0;

            FirstGravityLapse = true;
            HasTaunted = false;

            Phase = 0;
        }

        InstanceScript* instance;

        uint32 FireballTimer;
        uint32 PhoenixTimer;
        uint32 FlameStrikeTimer;
        uint32 CombatPulseTimer;

        //Heroic only
        uint32 PyroblastTimer;

        uint32 GravityLapseTimer;
        uint32 GravityLapsePhase;
        // 0 = No Gravity Lapse
        // 1 = Casting Gravity Lapse visual
        // 2 = Teleported people to self
        // 3 = Knocked people up in the air
        // 4 = Applied an aura that allows them to fly, channeling visual, relased Arcane Orbs.

        bool FirstGravityLapse;
        bool HasTaunted;

        uint8 Phase;
        // 0 = Not started
        // 1 = Fireball; Summon Phoenix; Flamestrike
        // 2 = Gravity Lapses

        void Reset() override
        {
            Initialize();

            instance->SetBossState(DATA_KAELTHAS, NOT_STARTED);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            instance->SetBossState(DATA_KAELTHAS, DONE);

            // Enable the Translocation Orb Exit
            if (GameObject* escapeOrb = ObjectAccessor::GetGameObject(*me, instance->GetGuidData(DATA_ESCAPE_ORB)))
                escapeOrb->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
        {
            if (damage > me->GetHealth())
                RemoveGravityLapse(); // Remove Gravity Lapse so that players fall to ground if they kill him when in air.
        }

        void EnterCombat(Unit* /*who*/) override
        {
            instance->SetBossState(DATA_KAELTHAS, IN_PROGRESS);
        }

        void MoveInLineOfSight(Unit* who) override

        {
            if (!HasTaunted && me->IsWithinDistInMap(who, 40.0f))
            {
                Talk(SAY_AGGRO);
                HasTaunted = true;
            }

            ScriptedAI::MoveInLineOfSight(who);
        }

        void SetThreatList(Creature* summonedUnit)
        {
            if (!summonedUnit)
                return;

            ThreatContainer::StorageType const &threatlist = me->getThreatManager().getThreatList();
            ThreatContainer::StorageType::const_iterator i = threatlist.begin();
            for (i = threatlist.begin(); i != threatlist.end(); ++i)
            {
                Unit* unit = ObjectAccessor::GetUnit(*me, (*i)->getUnitGuid());
                if (unit && unit->IsAlive())
                {
                    float threat = me->getThreatManager().getThreat(unit);
                    summonedUnit->AddThreat(unit, threat);
                }
            }
        }

        void TeleportPlayersToSelf()
        {
            float x = KaelLocations[0][0];
            float y = KaelLocations[0][1];
            me->SetPosition(x, y, LOCATION_Z, 0.0f);
            ThreatContainer::StorageType threatlist = me->getThreatManager().getThreatList();
            ThreatContainer::StorageType::const_iterator i = threatlist.begin();
            for (i = threatlist.begin(); i != threatlist.end(); ++i)
            {
                Unit* unit = ObjectAccessor::GetUnit(*me, (*i)->getUnitGuid());
                if (unit && (unit->GetTypeId() == TYPEID_PLAYER))
                    unit->CastSpell(unit, SPELL_TELEPORT_CENTER, true);
            }
            DoCast(me, SPELL_TELEPORT_CENTER, true);
        }

        void CastGravityLapseKnockUp()
        {
            ThreatContainer::StorageType threatlist = me->getThreatManager().getThreatList();
            ThreatContainer::StorageType::const_iterator i = threatlist.begin();
            for (i = threatlist.begin(); i != threatlist.end(); ++i)
            {
                Unit* unit = ObjectAccessor::GetUnit(*me, (*i)->getUnitGuid());
                if (unit && (unit->GetTypeId() == TYPEID_PLAYER))
                    // Knockback into the air
                    unit->CastSpell(unit, SPELL_GRAVITY_LAPSE_DOT, true, 0, 0, me->GetGUID());
            }
        }

        void CastGravityLapseFly()                              // Use Fly Packet hack for now as players can't cast "fly" spells unless in map 530. Has to be done a while after they get knocked into the air...
        {
            ThreatContainer::StorageType threatlist = me->getThreatManager().getThreatList();
            ThreatContainer::StorageType::const_iterator i = threatlist.begin();
            for (i = threatlist.begin(); i != threatlist.end(); ++i)
            {
                Unit* unit = ObjectAccessor::GetUnit(*me, (*i)->getUnitGuid());
                if (unit && (unit->GetTypeId() == TYPEID_PLAYER))
                {
                    // Also needs an exception in spell system.
                    unit->CastSpell(unit, SPELL_GRAVITY_LAPSE_FLY, true, 0, 0, me->GetGUID());
                    unit->SetCanFly(true);
                }
            }
        }

        void RemoveGravityLapse()
        {
            ThreatContainer::StorageType threatlist = me->getThreatManager().getThreatList();
            ThreatContainer::StorageType::const_iterator i = threatlist.begin();
            for (i = threatlist.begin(); i != threatlist.end(); ++i)
            {
                Unit* unit = ObjectAccessor::GetUnit(*me, (*i)->getUnitGuid());
                if (unit && (unit->GetTypeId() == TYPEID_PLAYER))
                {
                    unit->RemoveAurasDueToSpell(SPELL_GRAVITY_LAPSE_FLY);
                    unit->RemoveAurasDueToSpell(SPELL_GRAVITY_LAPSE_DOT);
                    unit->SetCanFly(false);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            switch (Phase)
            {
                case 0:
                {
                    // *Heroic mode only:
                    if (IsHeroic())
                    {
                        if (PyroblastTimer <= diff)
                        {
                            me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                            me->InterruptSpell(CURRENT_GENERIC_SPELL);
                            DoCast(me, SPELL_SHOCK_BARRIER, true);
                            DoCastVictim(SPELL_PYROBLAST);
                            PyroblastTimer = 60000;
                        } else PyroblastTimer -= diff;
                    }

                    if (FireballTimer <= diff)
                    {
                        DoCastVictim(SPELL_FIREBALL_NORMAL);
                        FireballTimer = urand(2000, 6000);
                    } else FireballTimer -= diff;

                    if (PhoenixTimer <= diff)
                    {
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);

                        uint8 random = urand(1, 2);
                        float x = KaelLocations[random][0];
                        float y = KaelLocations[random][1];

                        Creature* Phoenix = me->SummonCreature(CREATURE_PHOENIX, x, y, LOCATION_Z, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);
                        if (Phoenix)
                        {
                            Phoenix->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
                            SetThreatList(Phoenix);
                            Phoenix->AI()->AttackStart(target);
                        }

                        Talk(SAY_PHOENIX);

                        PhoenixTimer = 60000;
                    } else PhoenixTimer -= diff;

                    if (FlameStrikeTimer <= diff)
                    {
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                        {
                            me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                            me->InterruptSpell(CURRENT_GENERIC_SPELL);
                            DoCast(target, SPELL_FLAMESTRIKE3, true);
                            Talk(SAY_FLAMESTRIKE);
                        }
                        FlameStrikeTimer = urand(15000, 25000);
                    } else FlameStrikeTimer -= diff;

                    // Below 50%
                    if (HealthBelowPct(50))
                    {
                        me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_INTERRUPT_CAST, true);
                        me->StopMoving();
                        me->GetMotionMaster()->Clear();
                        me->GetMotionMaster()->MoveIdle();
                        GravityLapseTimer = 0;
                        GravityLapsePhase = 0;
                        Phase = 1;
                    }

                    DoMeleeAttackIfReady();
                }
                break;

                case 1:
                {
                    if (GravityLapseTimer <= diff)
                    {
                        switch (GravityLapsePhase)
                        {
                            case 0:
                                if (FirstGravityLapse)          // Different yells at 50%, and at every following Gravity Lapse
                                {
                                    Talk(SAY_GRAVITY_LAPSE);
                                    FirstGravityLapse = false;

                                    instance->SetData(DATA_KAELTHAS_STATUES, 1);
                                }
                                else
                                    Talk(SAY_RECAST_GRAVITY);

                                DoCast(me, SPELL_GRAVITY_LAPSE_INITIAL);
                                GravityLapseTimer = 2000 + diff;// Don't interrupt the visual spell
                                GravityLapsePhase = 1;
                                break;

                            case 1:
                                TeleportPlayersToSelf();
                                GravityLapseTimer = 1000;
                                GravityLapsePhase = 2;
                                break;

                            case 2:
                                CastGravityLapseKnockUp();
                                GravityLapseTimer = 1000;
                                GravityLapsePhase = 3;
                                break;

                            case 3:
                                CastGravityLapseFly();
                                GravityLapseTimer = 30000;
                                GravityLapsePhase = 4;

                                for (uint8 i = 0; i < 3; ++i)
                                {
                                    Unit* target = NULL;
                                    target = SelectTarget(SELECT_TARGET_RANDOM, 0);

                                    Creature* Orb = DoSpawnCreature(CREATURE_ARCANE_SPHERE, 5, 5, 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 30000);
                                    if (Orb && target)
                                    {
                                        Orb->SetSpeedRate(MOVE_RUN, 0.5f);
                                        Orb->AddThreat(target, 1000000.0f);
                                        Orb->AI()->AttackStart(target);
                                    }
                                }

                                DoCast(me, SPELL_GRAVITY_LAPSE_CHANNEL);
                                break;

                            case 4:
                                me->InterruptNonMeleeSpells(false);
                                Talk(SAY_TIRED);
                                DoCast(me, SPELL_POWER_FEEDBACK);
                                RemoveGravityLapse();
                                GravityLapseTimer = 10000;
                                GravityLapsePhase = 0;
                                break;
                        }
                    } else GravityLapseTimer -= diff;
                }
                break;
            }
        }
    };
};

class npc_felkael_flamestrike : public CreatureScript
{
public:
    npc_felkael_flamestrike() : CreatureScript("npc_felkael_flamestrike") { }

    CreatureAI* GetAI(Creature* c) const override
    {
        return GetMagistersTerraceAI<npc_felkael_flamestrikeAI>(c);
    }

    struct npc_felkael_flamestrikeAI : public ScriptedAI
    {
        npc_felkael_flamestrikeAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            FlameStrikeTimer = 5000;
        }

        uint32 FlameStrikeTimer;

        void Reset() override
        {
            Initialize();

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->setFaction(14);

            DoCast(me, SPELL_FLAMESTRIKE2, true);
        }

        void EnterCombat(Unit* /*who*/) override { }
        void MoveInLineOfSight(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (FlameStrikeTimer <= diff)
            {
                DoCast(me, SPELL_FLAMESTRIKE1_NORMAL, true);
                me->KillSelf();
            } else FlameStrikeTimer -= diff;
        }
    };
};

class npc_felkael_phoenix : public CreatureScript
{
public:
    npc_felkael_phoenix() : CreatureScript("npc_felkael_phoenix") { }

    CreatureAI* GetAI(Creature* c) const override
    {
        return GetMagistersTerraceAI<npc_felkael_phoenixAI>(c);
    }

    struct npc_felkael_phoenixAI : public ScriptedAI
    {
        npc_felkael_phoenixAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
            instance = creature->GetInstanceScript();
        }

        void Initialize()
        {
            BurnTimer = 2000;
            Death_Timer = 3000;
            Rebirth = false;
            FakeDeath = false;
        }

        InstanceScript* instance;
        uint32 BurnTimer;
        uint32 Death_Timer;
        bool Rebirth;
        bool FakeDeath;

        void Reset() override
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE + UNIT_FLAG_NON_ATTACKABLE);
            me->SetDisableGravity(true);
            DoCast(me, SPELL_PHOENIX_BURN, true);
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void DamageTaken(Unit* /*killer*/, uint32 &damage) override
        {
            if (damage < me->GetHealth())
                return;

            //Prevent glitch if in fake death
            if (FakeDeath)
            {
                damage = 0;
                return;
            }
            //Don't really die in all phases of Kael'Thas
            if (instance->GetBossState(DATA_KAELTHAS) == 0)
            {
                //prevent death
                damage = 0;
                FakeDeath = true;

                me->InterruptNonMeleeSpells(false);
                me->SetHealth(0);
                me->StopMoving();
                me->RemoveAllAurasOnDeath();
                me->ModifyAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, false);
                me->ModifyAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, false);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->ClearAllReactives();
                me->SetTarget(ObjectGuid::Empty);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveIdle();
                me->SetStandState(UNIT_STAND_STATE_DEAD);
           }
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->SummonCreature(CREATURE_PHOENIX_EGG, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 45000);
        }

        void UpdateAI(uint32 diff) override
        {
            //If we are fake death, we cast revbirth and after that we kill the phoenix to spawn the egg.
            if (FakeDeath)
            {
                if (!Rebirth)
                {
                    DoCast(me, SPELL_REBIRTH_DMG);
                    Rebirth = true;
                }

                if (Rebirth)
                {
                    if (Death_Timer <= diff)
                    {
                        me->SummonCreature(CREATURE_PHOENIX_EGG, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 45000);
                        me->DisappearAndDie();
                        Rebirth = false;
                    } else Death_Timer -= diff;
                }
            }

            if (!UpdateVictim())
                return;

            if (BurnTimer <= diff)
            {
                //spell Burn should possible do this, but it doesn't, so do this for now.
                uint16 dmg = urand(1650, 2050);
                me->DealDamage(me, dmg, 0, DOT, SPELL_SCHOOL_MASK_FIRE, NULL, false);
                BurnTimer += 2000;
            } BurnTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_felkael_phoenix_egg : public CreatureScript
{
public:
    npc_felkael_phoenix_egg() : CreatureScript("npc_felkael_phoenix_egg") { }

    CreatureAI* GetAI(Creature* c) const override
    {
        return GetMagistersTerraceAI<npc_felkael_phoenix_eggAI>(c);
    }

    struct npc_felkael_phoenix_eggAI : public ScriptedAI
    {
        npc_felkael_phoenix_eggAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            HatchTimer = 10000;
        }

        uint32 HatchTimer;

        void Reset() override
        {
            Initialize();
        }

        void EnterCombat(Unit* /*who*/) override { }
        void MoveInLineOfSight(Unit* /*who*/) override { }


        void UpdateAI(uint32 diff) override
        {
            if (HatchTimer <= diff)
            {
                me->SummonCreature(CREATURE_PHOENIX, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);
                me->KillSelf();
            } else HatchTimer -= diff;
        }
    };
};

class npc_arcane_sphere : public CreatureScript
{
public:
    npc_arcane_sphere() : CreatureScript("npc_arcane_sphere") { }

    CreatureAI* GetAI(Creature* c) const override
    {
        return GetMagistersTerraceAI<npc_arcane_sphereAI>(c);
    }

    struct npc_arcane_sphereAI : public ScriptedAI
    {
        npc_arcane_sphereAI(Creature* creature) : ScriptedAI(creature) { Reset(); }

        uint32 DespawnTimer;
        uint32 ChangeTargetTimer;

        void Reset() override
        {
            DespawnTimer = 30000;
            ChangeTargetTimer = urand(6000, 12000);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetDisableGravity(true);
            me->setFaction(14);
            DoCast(me, SPELL_ARCANE_SPHERE_PASSIVE, true);
        }

        void EnterCombat(Unit* /*who*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (DespawnTimer <= diff)
                me->KillSelf();
            else
                DespawnTimer -= diff;

            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (ChangeTargetTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                {
                    me->AddThreat(target, 1.0f);
                    me->TauntApply(target);
                    AttackStart(target);
                }

                ChangeTargetTimer = urand(5000, 15000);
            } else ChangeTargetTimer -= diff;
        }
    };
};

void AddSC_boss_felblood_kaelthas()
{
    new boss_felblood_kaelthas();
    new npc_arcane_sphere();
    new npc_felkael_phoenix();
    new npc_felkael_phoenix_egg();
    new npc_felkael_flamestrike();
}
