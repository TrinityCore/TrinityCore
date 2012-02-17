/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

//! TODO - Boss not scripted, just ported required spellscript from core

#include "ScriptMgr.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_POSITIVE_CHARGE           = 39090,
    SPELL_POSITIVE_CHARGE_STACK     = 39089,
    SPELL_NEGATIVE_CHARGE           = 39093,
    SPELL_NEGATIVE_CHARGE_STACK     = 39092
};

class spell_capacitus_polarity_shift : public SpellScriptLoader
{
    public:
        spell_capacitus_polarity_shift() : SpellScriptLoader("spell_capacitus_polarity_shift") { }

        class spell_capacitus_polarity_shift_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_capacitus_polarity_shift_SpellScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_POSITIVE_CHARGE))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_POSITIVE_CHARGE_STACK))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_CHARGE))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_CHARGE_STACK))
                    return false;
                return true;
            }

            void HandleTargets(std::list<Unit*>& targetList)
            {
                uint8 count = 0;
                for (std::list<Unit*>::iterator ihit = targetList.begin(); ihit != targetList.end(); ++ihit)
                    if ((*ihit)->GetGUID() != GetCaster()->GetGUID())
                        if (Player* target = (*ihit)->ToPlayer())
                            if (target->HasAura(GetTriggeringSpell()->Id))
                                ++count;

                if (count)
                {
                    uint32 spellId = 0;

                    if (GetSpellInfo()->Id == SPELL_POSITIVE_CHARGE)
                        spellId = SPELL_POSITIVE_CHARGE_STACK;
                    else // if (GetSpellInfo()->Id == SPELL_NEGATIVE_CHARGE)
                        spellId = SPELL_NEGATIVE_CHARGE_STACK;

                    GetCaster()->SetAuraStack(spellId, GetCaster(), count);
                }
            }

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetTriggeringSpell())
                    return;

                Unit* target = GetHitUnit();

                if (target->HasAura(GetTriggeringSpell()->Id))
                    SetHitDamage(0);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_capacitus_polarity_shift_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_capacitus_polarity_shift_SpellScript::HandleTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_capacitus_polarity_shift_SpellScript();
        }
};

void AddSC_boss_mechano_lord_capacitus()
{
    new spell_capacitus_polarity_shift();
}
