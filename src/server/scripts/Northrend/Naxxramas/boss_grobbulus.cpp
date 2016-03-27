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
#include "naxxramas.h"

enum Spells
{
    SPELL_BOMBARD_SLIME         = 28280,
    SPELL_SLIME_SPRAY           = 28157,
    SPELL_MUTATING_INJECTION    = 28169,
    SPELL_MUTATING_EXPLOSION    = 28206,
    SPELL_POISON_CLOUD          = 28240,
    SPELL_POISON_CLOUD_PASSIVE  = 28158,
    SPELL_BERSERK               = 26662
};

enum Events
{
    EVENT_BERSERK               = 1,
    EVENT_CLOUD                 = 2,
    EVENT_INJECT                = 3,
    EVENT_SPRAY                 = 4
};

enum CreatureId
{
    NPC_FALLOUT_SLIME           = 16290
};

class boss_grobbulus : public CreatureScript
{
    public:
        boss_grobbulus() : CreatureScript("boss_grobbulus") { }

        struct boss_grobbulusAI : public BossAI
        {
            boss_grobbulusAI(Creature* creature) : BossAI(creature, BOSS_GROBBULUS) { }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_CLOUD, Seconds(15));
                events.ScheduleEvent(EVENT_INJECT, Seconds(20));
                events.ScheduleEvent(EVENT_SPRAY, randtime(Seconds(15), Seconds(30))); // not sure
                events.ScheduleEvent(EVENT_BERSERK, Minutes(12));
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_SLIME_SPRAY)
                    me->SummonCreature(NPC_FALLOUT_SLIME, *target, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT);
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
                        case EVENT_CLOUD:
                            DoCastAOE(SPELL_POISON_CLOUD);
                            events.Repeat(Seconds(15));
                            return;
                        case EVENT_BERSERK:
                            DoCastAOE(SPELL_BERSERK, true);
                            return;
                        case EVENT_SPRAY:
                            DoCastAOE(SPELL_SLIME_SPRAY);
                            events.Repeat(randtime(Seconds(15), Seconds(30)));
                            return;
                        case EVENT_INJECT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_MUTATING_INJECTION))
                                DoCast(target, SPELL_MUTATING_INJECTION);
                            events.Repeat(Seconds(8) + Milliseconds(uint32(std::round(120 * me->GetHealthPct()))));
                            return;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_grobbulusAI(creature);
        }
};

class npc_grobbulus_poison_cloud : public CreatureScript
{
    public:
        npc_grobbulus_poison_cloud() : CreatureScript("npc_grobbulus_poison_cloud") { }

        struct npc_grobbulus_poison_cloudAI : public ScriptedAI
        {
            npc_grobbulus_poison_cloudAI(Creature* creature) : ScriptedAI(creature)
            {
                SetCombatMovement(false);
                creature->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                // no visual when casting in ctor or Reset()
                DoCast(me, SPELL_POISON_CLOUD_PASSIVE, true);
            }

            void UpdateAI(uint32 /*diff*/) override { }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_grobbulus_poison_cloudAI(creature);
        }
};

// 28169 - Mutating Injection
class spell_grobbulus_mutating_injection : public SpellScriptLoader
{
    public:
        spell_grobbulus_mutating_injection() : SpellScriptLoader("spell_grobbulus_mutating_injection") { }

        class spell_grobbulus_mutating_injection_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_grobbulus_mutating_injection_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MUTATING_EXPLOSION)
                    || !sSpellMgr->GetSpellInfo(SPELL_POISON_CLOUD))
                    return false;
                return true;
            }

            void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                if (removeMode != AURA_REMOVE_BY_ENEMY_SPELL && removeMode != AURA_REMOVE_BY_EXPIRE)
                    return;

                if (Unit* caster = GetCaster())
                {
                    caster->CastSpell(GetTarget(), SPELL_MUTATING_EXPLOSION, true);
                    GetTarget()->CastSpell(GetTarget(), SPELL_POISON_CLOUD, true, NULL, aurEff, GetCasterGUID());
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_grobbulus_mutating_injection_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_grobbulus_mutating_injection_AuraScript();
        }
};

// 28158, 54362 - Poison (Grobbulus)
class spell_grobbulus_poison_cloud : public SpellScriptLoader
{
    public:
        spell_grobbulus_poison_cloud() : SpellScriptLoader("spell_grobbulus_poison_cloud") { }

        class spell_grobbulus_poison_cloud_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_grobbulus_poison_cloud_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!sSpellMgr->GetSpellInfo(spellInfo->Effects[EFFECT_0].TriggerSpell))
                    return false;
                return true;
            }

            void PeriodicTick(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                uint32 triggerSpell = GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell;
                int32 mod = int32(((float(aurEff->GetTickNumber()) / aurEff->GetTotalTicks()) * 0.9f + 0.1f) * 10000 * 2 / 3);
                GetTarget()->CastCustomSpell(triggerSpell, SPELLVALUE_RADIUS_MOD, mod, (Unit*)NULL, TRIGGERED_FULL_MASK, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_grobbulus_poison_cloud_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_grobbulus_poison_cloud_AuraScript();
        }
};

void AddSC_boss_grobbulus()
{
    new boss_grobbulus();
    new npc_grobbulus_poison_cloud();
    new spell_grobbulus_mutating_injection();
    new spell_grobbulus_poison_cloud();
}
