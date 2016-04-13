/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "heart_of_fear.h"

enum ePhases
{
    PHASE_PLATEFORME_1  = 1,
    PHASE_PLATEFORME_2  = 2,
    PHASE_PLATEFORME_3  = 3,
    PHASE_MIDDLE        = 4,
};

// Les commentaires sont selon la vision que l'on a face à la salle
Position zorlockPosition[4] =
{
    {-2234.10f, 216.77f, 409.89f, 2.34f}, // Gauche
    {-2317.15f, 301.34f, 409.89f, 5.47f}, // Droite
    {-2315.61f, 218.21f, 409.89f, 0.72f}, // Fond
    {-2275.52f, 258.37f, 406.38f, 0.77f}, // Middle
};

enum eSpells
{
    SPELL_PHEROMONES_OF_ZEAL_FLOOR  = 123811,
    SPELL_PHEROMONES_OF_ZEAL_DAMAGE = 123812,
    SPELL_PHEROMONES_OF_ZEAL_INHALE = 124018,

    // Shared
    SPELL_INHALE                    = 122852,
    SPELL_EXHALE                    = 122761, // Todo

    // Plateforme 1
    SPELL_ATTENUATION               = 122440, // Todo
    SPELL_SONIC_RING_VISUAL         = 122336,
    SPELL_SONIC_RING                = 122336,

    // Plateforme 2
    SPELL_NOISE_CANCELLING          = 122707,
    SPELL_NOISE_CANCELLING_BUFF     = 122706,
    SPELL_FORCE_AND_VERVE           = 122713,

    // Plateforme 3
    SPELL_CONVERT                   = 122740,

    // Transition End
    SPELL_SONG_OF_EMPRESS           = 130133
};

enum eEvents
{
    // Shared
    EVENT_INHALE            = 1,
    EVENT_EXHALE            = 2,
    
    // Plateforme 1
    EVENT_ATTENUATION       = 3,
    
    // Plateforme 2
    EVENT_NOISE_CANCELLING  = 4,
    EVENT_FORCE_AND_VERVE   = 5,
    
    // Plateforme 3
    EVENT_CONVERT           = 6,

    // Middle
    EVENT_REMOVE_PHEROMONES = 7
};

#define TIMER_TO_SET urand(0, 60000)

class boss_vizier_zorlock : public CreatureScript
{
    public:
        boss_vizier_zorlock() : CreatureScript("boss_vizier_zorlock") {}

        struct boss_vizier_zorlockAI : public BossAI
        {
            boss_vizier_zorlockAI(Creature* creature) : BossAI(creature, DATA_ZORLOCK) {}

            uint8 actualPhase;
            uint8 phaseCount;
            float nextPhasePct;

            std::list<uint8> randomPlateforme;

            void Reset()
            {
                _Reset();

                phaseCount   = 1; // Begin at 1 because we jump to a plateforme at EnterCombat
                nextPhasePct = 80.0f;

                randomPlateforme.push_back(0);
                randomPlateforme.push_back(1);
                randomPlateforme.push_back(2);

                Trinity::Containers::RandomResizeList(randomPlateforme, 3); // Rand l'ordre des plateformes
 
                events.ScheduleEvent(EVENT_INHALE, TIMER_TO_SET);
                events.ScheduleEvent(EVENT_EXHALE, TIMER_TO_SET);
            }

            void EnterCombat(Unit* attacker)
            {
                _EnterCombat();
                DoZoneInCombat(me, 200.0f);

                uint8 nextPlateforme = randomPlateforme.front();
                randomPlateforme.pop_front();

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                me->GetMotionMaster()->MoveJump(zorlockPosition[nextPlateforme].GetPositionX(), zorlockPosition[nextPlateforme].GetPositionY(), 409.89f, 20.0f, 20.0f, nextPlateforme + 1);

                // zorlockPosition[3] == Middle
                me->CastSpell(zorlockPosition[3].GetPositionX(), zorlockPosition[3].GetPositionY(), zorlockPosition[3].GetPositionZ(), SPELL_PHEROMONES_OF_ZEAL_FLOOR, true);
            }

            void MovementInform(uint32 uiType, uint32 phase)
            {
                if (uiType != POINT_MOTION_TYPE
                 && uiType != EFFECT_MOTION_TYPE)
                    return;

                events.Reset();

                // These two are in all phases
                events.ScheduleEvent(EVENT_INHALE, TIMER_TO_SET);
                events.ScheduleEvent(EVENT_EXHALE, TIMER_TO_SET);

                if (phase >= 1 && phase <= 3)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    me->AddUnitState(UNIT_STATE_ROOT);
                    me->CastSpell(me, SPELL_SONG_OF_EMPRESS, false);

                    switch (phase)
                    {
                        case PHASE_PLATEFORME_1:
                        {
                            events.ScheduleEvent(EVENT_ATTENUATION,         TIMER_TO_SET);
                            break;
                        }
                        case PHASE_PLATEFORME_2:
                        {
                            events.ScheduleEvent(EVENT_NOISE_CANCELLING,    TIMER_TO_SET);
                            break;
                        }
                        case PHASE_PLATEFORME_3:
                        {
                            events.ScheduleEvent(EVENT_CONVERT,             TIMER_TO_SET);
                            break;
                        }
                    }
                }
                else if (phase == 4)
                {
                    me->CastSpell(me, SPELL_PHEROMONES_OF_ZEAL_INHALE, false);
                    events.ScheduleEvent(EVENT_REMOVE_PHEROMONES,   100); // We don't update while casting
                    events.ScheduleEvent(EVENT_ATTENUATION,         TIMER_TO_SET);
                    events.ScheduleEvent(EVENT_NOISE_CANCELLING,    TIMER_TO_SET);
                    events.ScheduleEvent(EVENT_CONVERT,             TIMER_TO_SET);
                }
            }

            void JustDied(Unit* attacker)
            {
                _JustDied();
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                summons.Despawn(summon);
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (me->HasAura(SPELL_SONG_OF_EMPRESS))
                {
                    if (attacker->IsWithinMeleeRange(me))
                    {
                        me->RemoveAurasDueToSpell(SPELL_SONG_OF_EMPRESS);
                        me->ClearUnitState(UNIT_STATE_ROOT);
                    }
                }

                if (phaseCount < PHASE_MIDDLE)
                {
                    if (me->HealthBelowPctDamaged(nextPhasePct, damage))
                    {
                        ++phaseCount;
                        nextPhasePct -= 20.0f;

                        uint8 nextPlateforme = 3; // Middle

                        if (phaseCount < PHASE_MIDDLE)
                        {
                            uint8 nextPlateforme = randomPlateforme.front();
                            randomPlateforme.pop_front();
                            actualPhase = nextPlateforme + 1;
                        }
                        else
                            actualPhase = PHASE_MIDDLE;

                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                        me->GetMotionMaster()->MoveJump(zorlockPosition[nextPlateforme].GetPositionX(), zorlockPosition[nextPlateforme].GetPositionY(), zorlockPosition[nextPlateforme].GetPositionZ(), 20.0f, 20.0f, actualPhase);
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint8 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INHALE:
                            me->CastSpell(me, SPELL_INHALE, false);
                            events.ScheduleEvent(EVENT_INHALE, TIMER_TO_SET);
                            break;
                        case EVENT_EXHALE:
                            // Todo
                            events.ScheduleEvent(EVENT_EXHALE, TIMER_TO_SET);
                            break;
                        case EVENT_ATTENUATION:
                            // Todo
                            events.ScheduleEvent(EVENT_ATTENUATION, TIMER_TO_SET);
                            break;
                        case EVENT_NOISE_CANCELLING:
                            me->CastSpell(me->GetPositionX() + frand(0.0f, 5.0f), me->GetPositionY() + frand(0.0f, 5.0f), me->GetPositionZ(), SPELL_NOISE_CANCELLING, false);
                            events.ScheduleEvent(EVENT_FORCE_AND_VERVE,     2000);
                            break;
                        case EVENT_FORCE_AND_VERVE:
                            me->CastSpell(me, SPELL_FORCE_AND_VERVE, false);
                            events.ScheduleEvent(EVENT_NOISE_CANCELLING, TIMER_TO_SET);
                            break;
                        case EVENT_CONVERT:
                        {
                            uint8 maxConvertPlayers = instance->instance->Is25ManRaid() ? 5 : 2;

                            for (uint8 i = 0; i < maxConvertPlayers; ++i)
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2, 0, true, -SPELL_CONVERT))
                                    me->CastSpell(target, SPELL_CONVERT, true);

                            events.ScheduleEvent(EVENT_CONVERT, TIMER_TO_SET);
                            break;
                        }
                        case EVENT_REMOVE_PHEROMONES:
                            me->RemoveAurasDueToSpell(SPELL_PHEROMONES_OF_ZEAL_FLOOR);
                            me->RemoveDynObject(SPELL_PHEROMONES_OF_ZEAL_FLOOR);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_vizier_zorlockAI(creature);
        }
};

class mob_sonic_ring : public CreatureScript
{
    public:
        mob_sonic_ring() : CreatureScript("mob_sonic_ring") {}

        struct mob_sonic_ringAI : public ScriptedAI
        {
            mob_sonic_ringAI(Creature* creature) : ScriptedAI(creature)
            {}

            void Reset()
            {
            }

            void MovementInform(uint32 type, uint32 id)
            {
            }

            void UpdateAI(uint32 diff)
            {
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_sonic_ringAI(creature);
        }
};

// 363 - pheromon of zeal
/*class sat_pheromon_of_zeal : public SpellAreaTriggerScript
{
public:
    sat_pheromon_of_zeal() : SpellAreaTriggerScript("sat_pheromon_of_zeal") {}

    class sat_pheromon_of_zeal_interface : public IAreaTriggerAura
    {
        bool CheckTriggering(WorldObject* triggering) override
        {
            Unit* unit = triggering->ToUnit();
            if (!unit)
                return false;

            if (unit->GetPositionZ() >= 407.0f)
                return false;

            if (!m_target->IsWithinDistInMap(unit, m_range))
                return false;

            if (!m_caster->_IsValidAttackTarget(unit, m_spellInfo, m_target))
                return false;

            return true;
        }

        void OnTriggeringApply(WorldObject* triggering) override
        {
            m_caster->CastSpell(SPELL_PHEROMONES_OF_ZEAL_DAMAGE, triggering->ToUnit());
        }

        void OnTriggeringRemove(WorldObject* triggering) override
        {
            triggering->ToUnit()->RemoveAura(SPELL_PHEROMONES_OF_ZEAL_DAMAGE, m_caster->GetGUID());
        }
    };

    IAreaTrigger* GetInterface() const override
    {
        return new sat_pheromon_of_zeal_interface();
    }
};*/

// 351 - noise cancelling
/*class sat_noise_cancelling : public SpellAreaTriggerScript
{
public:
    sat_noise_cancelling() : SpellAreaTriggerScript("sat_noise_cancelling") {}

    class sat_noise_cancelling_interface : public IAreaTriggerAura
    {
        bool CheckTriggering(WorldObject* triggering) override
        {
            Unit* unit = triggering->ToUnit();
            if (!unit)
                return false;

            if (!m_target->IsWithinDistInMap(unit, m_range))
                return false;

            if (!m_caster->_IsValidAttackTarget(unit, m_spellInfo, m_target))
                return false;

            return true;
        }
        void OnTriggeringApply(WorldObject* triggering) override
        {
            m_caster->AddAura(SPELL_NOISE_CANCELLING_BUFF, triggering->ToUnit());
        }

        void OnTriggeringRemove(WorldObject* triggering) override
        {
            triggering->ToUnit()->RemoveAura(SPELL_NOISE_CANCELLING_BUFF, m_caster->GetGUID());
        }
    };

    IAreaTrigger* GetInterface() const override
    {
        return new sat_noise_cancelling_interface();
    }
};
*/
// spell_force_and_verve_damage - 122718 
class spell_force_and_verve_damage : public SpellScriptLoader
{
    public:
        spell_force_and_verve_damage() : SpellScriptLoader("spell_force_and_verve_damage") { }

        class spell_force_and_verve_damage_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_force_and_verve_damage_SpellScript);

            void HandleEffect(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        if (Aura* cancellingAura = target->GetAura(SPELL_NOISE_CANCELLING_BUFF))
                        {
                            float reducePct = cancellingAura->GetEffect(0)->GetBaseAmount();
                            SetHitDamage(GetHitDamage() * (reducePct / 100));
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_force_and_verve_damage_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_force_and_verve_damage_SpellScript();
        }
};

// spell_zorlock_sonic_ring - 122336 
class spell_zorlock_sonic_ring : public SpellScriptLoader
{
    public:
        spell_zorlock_sonic_ring() : SpellScriptLoader("spell_zorlock_sonic_ring") { }

        class spell_zorlock_sonic_ring_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_zorlock_sonic_ring_SpellScript);

            void HandleEffect(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        if (Aura* cancellingAura = target->GetAura(SPELL_NOISE_CANCELLING_BUFF))
                        {
                            float reducePct = cancellingAura->GetEffect(1)->GetBaseAmount();
                            SetHitDamage(GetHitDamage() * (reducePct / 100));
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_zorlock_sonic_ring_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_zorlock_sonic_ring_SpellScript();
        }
};

// spell_zorlock_convert - 122740
class spell_zorlock_convert : public SpellScriptLoader
{
    public:
        spell_zorlock_convert() : SpellScriptLoader("spell_zorlock_convert") { }

        class spell_zorlock_convert_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_zorlock_convert_AuraScript);

            void OnTick(AuraEffect const* aurEff)
            {
                if (Unit* player = GetTarget())
                    if (player->GetHealthPct() <= 50.0f)
                        player->RemoveAura(GetAura());
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_zorlock_convert_AuraScript::OnTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_zorlock_convert_AuraScript();
        }
};

void AddSC_boss_vizier_zorlock()
{
    new boss_vizier_zorlock();
    new mob_sonic_ring();
    //new sat_pheromon_of_zeal();
    //new sat_noise_cancelling();
    new spell_force_and_verve_damage();
    new spell_zorlock_sonic_ring();
    new spell_zorlock_convert();
}
