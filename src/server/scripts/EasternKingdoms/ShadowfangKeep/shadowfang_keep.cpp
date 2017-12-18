 /*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "ScriptedEscortAI.h"
#include "shadowfang_keep.h"
#include "Player.h"

enum SKShieldOfBones
{
    SPELL_SHIELD_OF_BONES_TRIGGERED = 91631,
};

class spell_sfk_shield_of_bones: public SpellScriptLoader
{
    public:
        spell_sfk_shield_of_bones() : SpellScriptLoader("spell_sfk_shield_of_bones") { }

        class spell_sfk_shield_of_bones_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sfk_shield_of_bones_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHIELD_OF_BONES_TRIGGERED });
            }

            void OnAuraRemoveHandler(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
                    if (Unit* caster = GetCaster())
                        caster->CastSpell(caster, SPELL_SHIELD_OF_BONES_TRIGGERED, true);
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_sfk_shield_of_bones_AuraScript::OnAuraRemoveHandler, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sfk_shield_of_bones_AuraScript();
        }
};

void AddSC_shadowfang_keep()
{
    new spell_sfk_shield_of_bones();
}
