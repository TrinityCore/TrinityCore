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

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "Unit.h"

enum eSpellsThousandsNeedles
{
    SPELL_SPEEDBARGE_DIVING_HELM_CHECK  = 75651,
    SPELL_SPEEDBARGE_DIVING_HELM_EFFECT = 75627,
};

class spell_thousand_needles_speedbarge_diving_helm_check : public SpellScriptLoader
{
public:
    spell_thousand_needles_speedbarge_diving_helm_check() : SpellScriptLoader("spell_thousand_needles_speedbarge_diving_helm_check") { }

    class spell_thousand_needles_speedbarge_diving_helm_check_SpellScript : public AuraScript
    {
    public:
        spell_thousand_needles_speedbarge_diving_helm_check_SpellScript() : AuraScript() { checkTimer = 1000; }

        PrepareAuraScript(spell_thousand_needles_speedbarge_diving_helm_check_SpellScript);

        uint32 checkTimer;

        void OnUpdate(uint32 p_Diff)
        {
            if (checkTimer <= p_Diff)
            {
                if (Unit* caster = GetCaster())
                {
                    if (caster->IsInWater())
                    {
                        caster->RemoveAurasDueToSpell(SPELL_SPEEDBARGE_DIVING_HELM_CHECK);
                        caster->AddAura(SPELL_SPEEDBARGE_DIVING_HELM_EFFECT, caster);
                    }
                }

                checkTimer = 1000;
            }
            else
                checkTimer -= p_Diff;
        }

    private:

        void Register() override
        {
            OnAuraUpdate += AuraUpdateFn(spell_thousand_needles_speedbarge_diving_helm_check_SpellScript::OnUpdate);
        }
    };
    AuraScript* GetAuraScript() const override
    {
        return new spell_thousand_needles_speedbarge_diving_helm_check_SpellScript();
    }
};

class spell_thousand_needles_speedbarge_diving_helm_effect : public SpellScriptLoader
{
public:
    spell_thousand_needles_speedbarge_diving_helm_effect() : SpellScriptLoader("spell_thousand_needles_speedbarge_diving_helm_effect") { }

    class spell_thousand_needles_speedbarge_diving_helm_effect_SpellScript : public AuraScript
    {
    public:
        spell_thousand_needles_speedbarge_diving_helm_effect_SpellScript() : AuraScript() { checkTimer = 1000; }

        PrepareAuraScript(spell_thousand_needles_speedbarge_diving_helm_effect_SpellScript);

        uint32 checkTimer;

        void OnUpdate(uint32 p_Diff)
        {
            if (checkTimer <= p_Diff)
            {
                if (Unit* caster = GetCaster())
                {
                    if (!caster->IsInWater())
                    {
                        caster->RemoveAurasDueToSpell(SPELL_SPEEDBARGE_DIVING_HELM_EFFECT);
                        caster->AddAura(SPELL_SPEEDBARGE_DIVING_HELM_CHECK, caster);
                    }
                }

                checkTimer = 1000;
            }
            else
                checkTimer -= p_Diff;
        }

    private:

        void Register() override
        {
            OnAuraUpdate += AuraUpdateFn(spell_thousand_needles_speedbarge_diving_helm_effect_SpellScript::OnUpdate);
        }
    };
    AuraScript* GetAuraScript() const override
    {
        return new spell_thousand_needles_speedbarge_diving_helm_effect_SpellScript();
    }
};

void AddSC_thousand_needles()
{
    new spell_thousand_needles_speedbarge_diving_helm_check();
    new spell_thousand_needles_speedbarge_diving_helm_effect();
}
