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

/*
 * Scripts for spells with SPELLFAMILY_DEMONHUNTER and SPELLFAMILY_GENERIC spells used by demon hunter players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dh_".
 */

#include "ScriptMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Unit.h"

enum DemonHunterSpells
{
    SPELL_DH_CHAOS_STRIKE_ENERGIZE                  = 193840,
    SPELL_DH_FIRST_BLOOD                            = 206416,
    SPELL_DH_SIGIL_OF_CHAINS_GRIP                   = 208674,
    SPELL_DH_SIGIL_OF_CHAINS_SLOW                   = 204843,
    SPELL_DH_SIGIL_OF_CHAINS_TARGET_SELECT          = 204834,
    SPELL_DH_SIGIL_OF_CHAINS_VISUAL                 = 208673,
    SPELL_DH_SIGIL_OF_FLAME_AOE                     = 204598,
    SPELL_DH_SIGIL_OF_MISERY_AOE                    = 207685,
    SPELL_DH_SIGIL_OF_SILENCE_AOE                   = 204490,
};

// 197125 - Chaos Strike
class spell_dh_chaos_strike : public AuraScript
{
    PrepareAuraScript(spell_dh_chaos_strike);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_CHAOS_STRIKE_ENERGIZE });
    }

    void HandleEffectProc(AuraEffect* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, aurEff->GetAmount());
        args.SetTriggeringAura(aurEff);
        GetTarget()->CastSpell(GetTarget(), SPELL_DH_CHAOS_STRIKE_ENERGIZE, args);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_dh_chaos_strike::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};


// 206416 - First Blood
class spell_dh_first_blood : public AuraScript
{
    PrepareAuraScript(spell_dh_first_blood);

public:
    ObjectGuid const& GetFirstTarget() const { return _firstTargetGUID; }
    void SetFirstTarget(ObjectGuid const& targetGuid) { _firstTargetGUID = targetGuid; }

private:
    void Register() override
    {
    }

private:
    ObjectGuid _firstTargetGUID;
};

// 188499 - Blade Dance
// 210152 - Death Sweep
class spell_dh_blade_dance : public SpellScript
{
    PrepareSpellScript(spell_dh_blade_dance);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FIRST_BLOOD });
    }

    void DecideFirstTarget(std::list<WorldObject*>& targetList)
    {
        if (targetList.empty())
            return;

        Aura* aura = GetCaster()->GetAura(SPELL_DH_FIRST_BLOOD);
        if (!aura)
            return;

        ObjectGuid firstTargetGUID = ObjectGuid::Empty;
        ObjectGuid selectedTarget = GetCaster()->GetTarget();

        // Prefer the selected target if he is one of the enemies
        if (targetList.size() > 1 && !selectedTarget.IsEmpty())
        {
            auto it = std::find_if(targetList.begin(), targetList.end(), [selectedTarget](WorldObject* object)
            {
                return object->GetGUID() == selectedTarget;
            });
            if (it != targetList.end())
                firstTargetGUID = (*it)->GetGUID();
        }

        if (firstTargetGUID.IsEmpty())
            firstTargetGUID = targetList.front()->GetGUID();

        if (spell_dh_first_blood* script = aura->GetScript<spell_dh_first_blood>())
            script->SetFirstTarget(firstTargetGUID);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dh_blade_dance::DecideFirstTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 199552 - Blade Dance
// 200685 - Blade Dance
// 210153 - Death Sweep
// 210155 - Death Sweep
class spell_dh_blade_dance_damage : public SpellScript
{
    PrepareSpellScript(spell_dh_blade_dance_damage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_FIRST_BLOOD });
    }

    void HandleHitTarget()
    {
        int32 damage = GetHitDamage();

        if (AuraEffect* aurEff = GetCaster()->GetAuraEffect(SPELL_DH_FIRST_BLOOD, EFFECT_0))
            if (spell_dh_first_blood* script = aurEff->GetBase()->GetScript<spell_dh_first_blood>())
                if (GetHitUnit()->GetGUID() == script->GetFirstTarget())
                    AddPct(damage, aurEff->GetAmount());

        SetHitDamage(damage);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_dh_blade_dance_damage::HandleHitTarget);
    }
};

// 204596 - Sigil of Flame
// 207684 - Sigil of Misery
// 202137 - Sigil of Silence
template<uint32 TriggerSpellId>
class areatrigger_dh_generic_sigil : public AreaTriggerEntityScript
{
public:
    areatrigger_dh_generic_sigil(char const* script) : AreaTriggerEntityScript(script) { }

    template<uint32 Trigger>
    struct areatrigger_dh_generic_sigilAI : AreaTriggerAI
    {
        areatrigger_dh_generic_sigilAI(AreaTrigger* at) : AreaTriggerAI(at) { }

        void OnRemove() override
        {
            if (Unit* caster = at->GetCaster())
                caster->CastSpell(at->GetPosition(), Trigger);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* at) const override
    {
        return new areatrigger_dh_generic_sigilAI<TriggerSpellId>(at);
    }
};

// 208673 - Sigil of Chains
class spell_dh_sigil_of_chains : public SpellScript
{
    PrepareSpellScript(spell_dh_sigil_of_chains);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DH_SIGIL_OF_CHAINS_SLOW, SPELL_DH_SIGIL_OF_CHAINS_GRIP });
    }

    void HandleEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (WorldLocation const* loc = GetExplTargetDest())
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_DH_SIGIL_OF_CHAINS_SLOW, true);
            GetHitUnit()->CastSpell(loc->GetPosition(), SPELL_DH_SIGIL_OF_CHAINS_GRIP, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_dh_sigil_of_chains::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 202138 - Sigil of Chains
struct areatrigger_dh_sigil_of_chains : AreaTriggerAI
{
    areatrigger_dh_sigil_of_chains(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
        {
            caster->CastSpell(at->GetPosition(), SPELL_DH_SIGIL_OF_CHAINS_VISUAL);
            caster->CastSpell(at->GetPosition(), SPELL_DH_SIGIL_OF_CHAINS_TARGET_SELECT);
        }
    }
};

void AddSC_demon_hunter_spell_scripts()
{
    RegisterAuraScript(spell_dh_chaos_strike);

    new areatrigger_dh_generic_sigil<SPELL_DH_SIGIL_OF_SILENCE_AOE>("areatrigger_dh_sigil_of_silence");
    new areatrigger_dh_generic_sigil<SPELL_DH_SIGIL_OF_MISERY_AOE>("areatrigger_dh_sigil_of_misery");
    new areatrigger_dh_generic_sigil<SPELL_DH_SIGIL_OF_FLAME_AOE>("areatrigger_dh_sigil_of_flame");
    RegisterAreaTriggerAI(areatrigger_dh_sigil_of_chains);
    RegisterSpellScript(spell_dh_sigil_of_chains);

    // Havoc

    /* Spells & Auras */


    /* Auras */

    RegisterAuraScript(spell_dh_first_blood);

    /* AreaTrigger */


    /* Spells */

    RegisterSpellScript(spell_dh_blade_dance);
    RegisterSpellScript(spell_dh_blade_dance_damage);

}
