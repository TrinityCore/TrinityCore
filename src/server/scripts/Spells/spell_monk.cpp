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

/*
 * Scripts for spells with SPELLFAMILY_MONK and SPELLFAMILY_GENERIC spells used by monk players.
 * Scriptnames of files in this file should be prefixed with "spell_monk_".
 */

#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

enum MonkSpells
{
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHANNEL = 117952,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC = 123333,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK = 117962,
    SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD = 117953,
    SPELL_MONK_PROVOKE = 116189,
    SPELL_MONK_PROVOKE_OX = 118635,
    SPELL_MONK_STANCE_OF_THE_SPIRITED_CRANE = 154436
};

enum Creatures
{
    BLACK_OX_STATUE = 61146
};

// 117952 - Crackling Jade Lightning
class spell_monk_crackling_jade_lightning : public SpellScriptLoader
{
public:
    spell_monk_crackling_jade_lightning() : SpellScriptLoader("spell_monk_crackling_jade_lightning") { }

    class spell_monk_crackling_jade_lightning_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_crackling_jade_lightning_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC))
                return false;
            return true;
        }

        void OnTick(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->HasAura(SPELL_MONK_STANCE_OF_THE_SPIRITED_CRANE))
                    caster->CastSpell(caster, SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHI_PROC, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_monk_crackling_jade_lightning_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_monk_crackling_jade_lightning_AuraScript();
    }
};

// 117959 - Crackling Jade Lightning
class spell_monk_crackling_jade_lightning_knockback_proc_aura : public SpellScriptLoader
{
public:
    spell_monk_crackling_jade_lightning_knockback_proc_aura() : SpellScriptLoader("spell_monk_crackling_jade_lightning_knockback_proc_aura") { }

    class spell_monk_crackling_jade_lightning_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_monk_crackling_jade_lightning_aura_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (GetTarget()->HasAura(SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD))
                return false;

            if (eventInfo.GetActor()->GetGUID() != GetTarget()->GetChannelObjectGuid())
                return false;

            Spell* currentChanneledSpell = GetTarget()->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
            if (!currentChanneledSpell || currentChanneledSpell->GetSpellInfo()->Id != SPELL_MONK_CRACKLING_JADE_LIGHTNING_CHANNEL)
                return false;

            return true;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            GetTarget()->CastSpell(eventInfo.GetActor(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK, TRIGGERED_FULL_MASK);
            GetTarget()->CastSpell(GetTarget(), SPELL_MONK_CRACKLING_JADE_LIGHTNING_KNOCKBACK_CD, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_monk_crackling_jade_lightning_aura_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_monk_crackling_jade_lightning_aura_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_monk_crackling_jade_lightning_aura_AuraScript();
    }
};

// Provoke - 115546
class spell_monk_provoke : public SpellScriptLoader
{
public:
    spell_monk_provoke() : SpellScriptLoader("spell_monk_provoke") { }

    class spell_monk_provoke_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_monk_provoke_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* target = GetExplTargetUnit();
            if (!target)
                return SPELL_FAILED_NO_VALID_TARGETS;
            else if (target->GetTypeId() == TYPEID_PLAYER)
                return SPELL_FAILED_BAD_TARGETS;
            else if (!target->IsWithinLOSInMap(GetCaster()))
                return SPELL_FAILED_LINE_OF_SIGHT;
            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    if(target->GetEntry() == BLACK_OX_STATUE)
                        caster->CastSpell(target, SPELL_MONK_PROVOKE_OX, true);
                    else
                        caster->CastSpell(target, SPELL_MONK_PROVOKE, true);
                }
            }
        }

        void Register()
        {
            OnCheckCast += SpellCheckCastFn(spell_monk_provoke_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_monk_provoke_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_monk_provoke_SpellScript();
    }
};

void AddSC_monk_spell_scripts()
{
    new spell_monk_crackling_jade_lightning();
    new spell_monk_crackling_jade_lightning_knockback_proc_aura();
    new spell_monk_provoke();
}
