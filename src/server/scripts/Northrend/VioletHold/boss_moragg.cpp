/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "violet_hold.h"

enum Spells
{
    SPELL_CORROSIVE_SALIVA                     = 54527,
    SPELL_OPTIC_LINK                           = 54396,
    SPELL_RAY_OF_PAIN                          = 54438,
    SPELL_RAY_OF_SUFFERING                     = 54442,

    // Visual
    SPELL_OPTIC_LINK_LEVEL_1                   = 54393,
    SPELL_OPTIC_LINK_LEVEL_2                   = 54394,
    SPELL_OPTIC_LINK_LEVEL_3                   = 54395
};

class boss_moragg : public CreatureScript
{
    public:
        boss_moragg() : CreatureScript("boss_moragg") { }

        struct boss_moraggAI : public BossAI
        {
            boss_moraggAI(Creature* creature) : BossAI(creature, DATA_MORAGG) { }

            void Reset() override
            {
                BossAI::Reset();
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
            }

            void JustReachedHome() override
            {
                BossAI::JustReachedHome();
                instance->SetData(DATA_HANDLE_CELLS, DATA_MORAGG);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                scheduler.Update(diff,
                    std::bind(&BossAI::DoMeleeAttackIfReady, this));
            }

            void ScheduleTasks() override
            {
                scheduler.Async([this]
                {
                    DoCast(me, SPELL_RAY_OF_PAIN);
                    DoCast(me, SPELL_RAY_OF_SUFFERING);
                });

                scheduler.Schedule(Seconds(15), [this](TaskContext task)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                        DoCast(target, SPELL_OPTIC_LINK);
                    task.Repeat(Seconds(25));
                });

                scheduler.Schedule(Seconds(5), [this](TaskContext task)
                {
                    DoCastVictim(SPELL_CORROSIVE_SALIVA);
                    task.Repeat(Seconds(10));
                });
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetVioletHoldAI<boss_moraggAI>(creature);
        }
};

class spell_moragg_ray : public SpellScriptLoader
{
    public:
        spell_moragg_ray() : SpellScriptLoader("spell_moragg_ray") { }

        class spell_moragg_ray_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_moragg_ray_AuraScript);

            void OnPeriodic(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                if (UnitAI* AI = GetTarget()->GetAI())
                    if (Unit* target = AI->SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                    {
                        uint32 triggerSpell = GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell;
                        GetTarget()->CastSpell(target, triggerSpell, aurEff);
                    }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_moragg_ray_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_moragg_ray_AuraScript();
        }
};

class spell_moragg_optic_link : public SpellScriptLoader
{
public:
    spell_moragg_optic_link() : SpellScriptLoader("spell_moragg_optic_link") { }

    class spell_moragg_optic_link_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_moragg_optic_link_AuraScript);

        void OnPeriodic(AuraEffect const* aurEff)
        {
            if (Unit* caster = GetCaster())
            {
                if (aurEff->GetTickNumber() >= 8)
                    caster->CastSpell(GetTarget(), SPELL_OPTIC_LINK_LEVEL_3, aurEff);

                if (aurEff->GetTickNumber() >= 4)
                    caster->CastSpell(GetTarget(), SPELL_OPTIC_LINK_LEVEL_2, aurEff);

                caster->CastSpell(GetTarget(), SPELL_OPTIC_LINK_LEVEL_1, aurEff);
            }
        }

        void OnUpdate(AuraEffect* aurEff)
        {
            switch (aurEff->GetTickNumber())
            {
                case 1:
                    aurEff->SetAmount(aurEff->GetAmount() + 250); // base amount is 500
                    break;
                case 4:
                    aurEff->SetAmount(aurEff->GetAmount() * 2); // goes to 1500
                    break;
                case 8:
                    aurEff->SetAmount(aurEff->GetAmount() * 2); // goes to 3000
                    break;
                default:
                    break;
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_moragg_optic_link_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_moragg_optic_link_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_moragg_optic_link_AuraScript();
    }
};

void AddSC_boss_moragg()
{
    new boss_moragg();
    new spell_moragg_ray();
    new spell_moragg_optic_link();
}
