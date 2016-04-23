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
#include "Player.h"

class spell_summon_troublemaker : public SpellScriptLoader
{
public:
    spell_summon_troublemaker() : SpellScriptLoader("spell_summon_troublemaker") { }

    class spell_summon_troublemaker_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_summon_troublemaker_SpellScript);

        void HandleSummon(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            uint32 entry = GetSpellInfo()->GetEffect(effIndex)->MiscValue;
            SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(GetSpellInfo()->GetEffect(effIndex)->MiscValueB);
            if (!entry || !properties)
                return;

            int32 duration = GetSpellInfo()->GetDuration();
            int32 radius;
            if (urand(0, 2) == 0)
                radius = urand(0, 6);
            else
                radius = 7;
            float angle = M_PI * (urand(0, 7) / 7.f);
            float x = 1181.75f + radius * sin(angle);
            float y = 3444.5f + radius * cos(angle);
            float z = 102.9385f;

            GetHitDest()->Relocate(x, y, z);

            Position const SpawnPosition = { x, y, z, 3.285759f };

            if (TempSummon* summon = GetCaster()->GetMap()->SummonCreature(entry, SpawnPosition, properties, duration, GetCaster()))
                summon->SetTempSummonType(TEMPSUMMON_CORPSE_TIMED_DESPAWN);
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_summon_troublemaker_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_summon_troublemaker_SpellScript();
    }
};

enum MeditationTimerSpells
{
    SPELL_CAVE_OF_SCROLLS_CREDIT = 102447,
    SPELL_CAVE_OF_SCROLLS_COMP_TIMER_AURA = 128598
};

class spell_meditation_timer_bar : public SpellScriptLoader
{
public:
    spell_meditation_timer_bar() : SpellScriptLoader("spell_meditation_timer_bar") { }

    class spell_meditation_timer_bar_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_meditation_timer_bar_AuraScript);

        void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* target = GetTarget())
            {
                target->ModifyPower(POWER_ALTERNATE_POWER, 1);

                if (target->GetPowerPct(POWER_ALTERNATE_POWER) == 100)
                {
                    target->CastSpell(GetTarget(), SPELL_CAVE_OF_SCROLLS_CREDIT, true);
                    target->CastSpell(GetTarget(), SPELL_CAVE_OF_SCROLLS_COMP_TIMER_AURA, true);
                    target->RemoveAura(GetId());
                }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_meditation_timer_bar_AuraScript::HandleEffectPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_meditation_timer_bar_AuraScript();
    }
};

class spell_cave_of_scrolls_comp_timer_aura : public SpellScriptLoader
{
public:
    spell_cave_of_scrolls_comp_timer_aura() : SpellScriptLoader("spell_cave_of_scrolls_comp_timer_aura") { }

    class spell_cave_of_scrolls_comp_timer_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_cave_of_scrolls_comp_timer_aura_AuraScript);

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* target = GetTarget())
                target->FindNearestCreature(54567, 40.f, true)->AI()->Talk(1, target);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_cave_of_scrolls_comp_timer_aura_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_cave_of_scrolls_comp_timer_aura_AuraScript();
    }
};

class spell_summon_living_air : public SpellScriptLoader
{
public:
    spell_summon_living_air() : SpellScriptLoader("spell_summon_living_air") { }

    class spell_summon_living_air_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_summon_living_air_SpellScript);

        void HandleSummon(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            uint32 entry = GetSpellInfo()->GetEffect(effIndex)->MiscValue;
            SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(GetSpellInfo()->GetEffect(effIndex)->MiscValueB);
            if (!entry || !properties)
                return;

            Position const SpawnPosition[6] =
            {
                {1237.073f, 3697.739f, 93.62743f},
                {1230.608f, 3701.063f, 93.94895f},
                {1229.429f, 3732.776f, 92.22045f},
                {1223.438f, 3700.607f, 93.93437f},
                {1239.606f, 3732.907f, 94.10403f},
                {1224.92f, 3727.201f, 92.4472f}
            };

            int32 duration = GetSpellInfo()->GetDuration();
            uint32 randomPos = urand(0, 5);
            
            if (TempSummon* summon = GetCaster()->GetMap()->SummonCreature(entry, SpawnPosition[randomPos], properties, duration, GetCaster()))
                summon->SetTempSummonType(TEMPSUMMON_CORPSE_TIMED_DESPAWN);
        }

        void Register()
        {
            OnEffectHit += SpellEffectFn(spell_summon_living_air_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_summon_living_air_SpellScript();
    }
};

enum FanTheFlamesSpells
{
    SPELL_THROW_WOOD        = 109090,
    SPELL_BLOW_AIR          = 109095,
    SPELL_BLOW_AIR_BIG      = 109105,
    SPELL_BLOW_AIR_BIGGER   = 109109
};

enum FanTheFlamesNPCs
{
    NPC_HUO = 57779
};

class spell_fan_the_flames : public SpellScriptLoader
{
public:
    spell_fan_the_flames() : SpellScriptLoader("spell_fan_the_flames") { }

    class spell_fan_the_flames_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_fan_the_flames_AuraScript);

        uint32 counter = 0;

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();

            counter++;

            if (Unit* target = GetTarget()->FindNearestCreature(NPC_HUO, GetSpellInfo()->GetMaxRange(), true))
            {
                if (counter == 1 || counter == 4 || counter == 6)
                    caster->CastSpell(target, SPELL_THROW_WOOD, true);
                if (counter == 8 || counter == 10 || counter == 13 || counter == 15)
                    caster->CastSpell(target, SPELL_BLOW_AIR, true);
                if (counter == 12 || counter == 14)
                    caster->CastSpell(target, SPELL_BLOW_AIR_BIG, true);
                if (counter == 16)
                    caster->CastSpell(target, SPELL_BLOW_AIR_BIGGER, true);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_fan_the_flames_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_fan_the_flames_AuraScript();
    }
};

void AddSC_the_wandering_isle()
{
    new spell_summon_troublemaker();
    new spell_meditation_timer_bar();
    new spell_cave_of_scrolls_comp_timer_aura();
    new spell_summon_living_air();
    new spell_fan_the_flames();
}
