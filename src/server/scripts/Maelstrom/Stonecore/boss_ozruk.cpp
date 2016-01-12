/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Vehicle.h"
#include "stonecore.h"

enum Spells
{
    SPELL_ELEMENTIUM_BULWARK      = 78939,
    SPELL_GROUND_SLAM             = 78903,
    SPELL_ELEMENTIUM_SPIKE_SHIELD = 78835,
    SPELL_SHATTER                 = 78807,
    SPELL_ENRAGE                  = 80467,

    // Rupture Controller and Rupture
    SPELL_RUPTURE                 = 92393,
//  SPELL_RUPTURE_SUMMON_CENTER?  = 95669, // summons rupture 8 yards front
//  SPELL_RUPTURE_SUMMON_LEFT?    = 95348, // summons rupture 3 yards left?
//  SPELL_RUPTURE_SUMMON_RIGHT?   = 92383, // summons rupture 3 yards right?
    SPELL_RUPTURE_DAMAGE          = 92381,
};

enum NPCs
{
    NPC_BOUNCER_SPIKE             = 42189,
    NPC_RUPTURE_CONTROLLER        = 49597,
    NPC_RUPTURE                   = 49576,
};

enum Texts
{
    SAY_AGGRO                   = 0,
    SAY_ELEMENTIUM_BULWARK      = 1,
    SAY_ELEMENTIUM_SPIKE_SHIELD = 2,
    SAY_ENRAGE                  = 3,
    SAY_DEATH                   = 4,
};

enum Events
{
    EVENT_NONE,

    EVENT_ELEMENTIUM_BULWARK,
    EVENT_GROUND_SLAM,
    EVENT_ELEMENTIUM_SPIKE_SHIELD,
    EVENT_SHATTER,
    EVENT_ENRAGE,

    EVENT_START_ATTACK,
};

// TO-DO:
// - Find heroic sniffs and spawn Ruptures using spells commented above.
// - Make Bouncer Spikes enter ozruk without jump animation.

class boss_ozruk : public CreatureScript
{
    public:
        boss_ozruk() : CreatureScript("boss_ozruk") { }

        struct boss_ozrukAI : public BossAI
        {
            boss_ozrukAI(Creature* creature) : BossAI(creature, DATA_OZRUK) { }

            void Reset() override
            {
                _Reset();

                me->SetReactState(REACT_AGGRESSIVE);

                events.ScheduleEvent(EVENT_ELEMENTIUM_BULWARK, 5000);
                events.ScheduleEvent(EVENT_GROUND_SLAM, 10000);
                events.ScheduleEvent(EVENT_ELEMENTIUM_SPIKE_SHIELD, 13000);
            }

            void EnterCombat(Unit* /*victim*/) override
            {
                _EnterCombat();

                Talk(SAY_AGGRO);
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == NPC_RUPTURE_CONTROLLER)
                {
                    summon->CastSpell(summon, SPELL_RUPTURE, true);
                    summon->DespawnOrUnsummon(10000);
                }

                BossAI::JustSummoned(summon);
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
            {
                if (!me->HealthBelowPctDamaged(25, damage) || me->HasAura(SPELL_ENRAGE))
                    return;

                DoCast(me, SPELL_ENRAGE);
                Talk(SAY_ENRAGE);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                Talk(SAY_DEATH);
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
                        case EVENT_ELEMENTIUM_BULWARK:
                            DoCast(me, SPELL_ELEMENTIUM_BULWARK);
                            Talk(SAY_ELEMENTIUM_BULWARK);
                            break;
                        case EVENT_GROUND_SLAM:
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            DoCast(me, SPELL_GROUND_SLAM);
                            events.ScheduleEvent(EVENT_START_ATTACK, 4600);
                            break;
                        case EVENT_ELEMENTIUM_SPIKE_SHIELD:
                            DoCast(me, SPELL_ELEMENTIUM_SPIKE_SHIELD);
                            Talk(SAY_ELEMENTIUM_SPIKE_SHIELD);
                            events.ScheduleEvent(EVENT_SHATTER, 10000);
                            break;
                        case EVENT_SHATTER:
                            summons.DespawnEntry(NPC_BOUNCER_SPIKE);
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            DoCast(me, SPELL_SHATTER);
                            events.ScheduleEvent(EVENT_START_ATTACK, 4600);
                            // Spells are cast in same order everytime after Shatter, so we schedule them here 
                            events.ScheduleEvent(EVENT_ELEMENTIUM_BULWARK, urand(3000,4000));
                            events.ScheduleEvent(EVENT_GROUND_SLAM, urand(7000,9000));
                            events.ScheduleEvent(EVENT_ELEMENTIUM_SPIKE_SHIELD, urand(10000,12000));
                            break;
                        case EVENT_START_ATTACK:
                            me->SetReactState(REACT_AGGRESSIVE);
                            DoStartMovement(me->GetVictim());
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_ozrukAI>(creature);
        }
};

// 92393 - Rupture
class spell_rupture : public SpellScriptLoader
{
public:
    spell_rupture() : SpellScriptLoader("spell_rupture") { }

    class spell_rupture_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_rupture_AuraScript);

        void HandleEffectPeriodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();

            float dist = aurEff->GetTickNumber() * 8.0f;

            // probably hack, should use spells (see Spells enum above)
            Position pos = caster->GetNearPosition(dist, 0.0f);
            SummonRupture(caster, pos);

            pos = caster->GetNearPosition(dist, 0.2f);
            SummonRupture(caster, pos);

            pos = caster->GetNearPosition(dist, -0.2f);
            SummonRupture(caster, pos);
        }

        void SummonRupture(Unit* caster, Position pos)
        {
            Creature* rupture = caster->SummonCreature(NPC_RUPTURE, pos, TEMPSUMMON_TIMED_DESPAWN, 2500);
            if (!rupture)
                return;

            rupture->CastSpell(rupture, SPELL_RUPTURE_DAMAGE, true);
        }

        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_rupture_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_rupture_AuraScript();
    }
};

// 78835 - Elementium Spike Shield
class spell_elementium_spike_shield : public SpellScriptLoader
{
public:
    spell_elementium_spike_shield() : SpellScriptLoader("spell_elementium_spike_shield") { }

    class spell_elementium_spike_shield_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_elementium_spike_shield_SpellScript);

        void HandleBouncerSpikes()
        {
            Unit* caster = GetCaster();
            Vehicle* vehicle = caster->GetVehicleKit();
            if (!vehicle)
                return;

            for (uint8 i = 0; i < vehicle->GetAvailableSeatCount(); i++)
                if (Creature* summon = caster->SummonCreature(NPC_BOUNCER_SPIKE, caster->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 10000))
                    summon->EnterVehicle(caster, i);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_elementium_spike_shield_SpellScript::HandleBouncerSpikes);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_elementium_spike_shield_SpellScript();
    }
};

void AddSC_boss_ozruk()
{
    new boss_ozruk();
    new spell_rupture();
    new spell_elementium_spike_shield();
}
