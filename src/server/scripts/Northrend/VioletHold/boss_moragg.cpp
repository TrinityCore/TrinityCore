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

struct boss_moragg : public BossAI
{
    boss_moragg(Creature* creature) : BossAI(creature, DATA_MORAGG) { }

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
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 50.0f, true))
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

// 54438, 59523 - Ray of Pain
// 54442, 59524 - Ray of Suffering
class spell_moragg_ray : public AuraScript
{
    PrepareAuraScript(spell_moragg_ray);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();

        if (UnitAI* AI = GetTarget()->GetAI())
            if (Unit* target = AI->SelectTarget(SelectTargetMethod::Random, 0, 45.0f, true))
            {
                uint32 triggerSpell = aurEff->GetSpellEffectInfo().TriggerSpell;
                GetTarget()->CastSpell(target, triggerSpell, aurEff);
            }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_moragg_ray::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 54396 - Optic Link
class spell_moragg_optic_link : public AuraScript
{
    PrepareAuraScript(spell_moragg_optic_link);

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
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_moragg_optic_link::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_moragg_optic_link::OnUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

void AddSC_boss_moragg()
{
    RegisterVioletHoldCreatureAI(boss_moragg);
    RegisterSpellScript(spell_moragg_ray);
    RegisterSpellScript(spell_moragg_optic_link);
}
