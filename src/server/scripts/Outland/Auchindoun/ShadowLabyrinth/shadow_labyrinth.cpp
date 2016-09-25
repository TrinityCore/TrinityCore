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

#include "SpellScript.h"

enum Spells
{
    SPELL_MARK_OF_MALICE_TRIGGERED = 33494
};

class spell_mark_of_malice : public SpellScriptLoader
{
    public:
        spell_mark_of_malice() : SpellScriptLoader("spell_mark_of_malice") { }

        class spell_mark_of_malice_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mark_of_malice_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MARK_OF_MALICE_TRIGGERED))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                // just drop charges
                if (aurEff->GetBase()->GetCharges() > 1)
                    return;

                GetTarget()->CastSpell(GetTarget(), SPELL_MARK_OF_MALICE_TRIGGERED, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_mark_of_malice_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_mark_of_malice_AuraScript();
        }
};

void AddSC_shadow_labyrinth()
{
    new spell_mark_of_malice();
}
