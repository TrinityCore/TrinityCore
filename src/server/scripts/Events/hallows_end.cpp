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

#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum HallowsEnd
{
    ITEM_WATER_BUCKET = 32971,
    SPELL_HAS_WATER_BUCKET = 42336,
};

class spell_hallows_end_has_water_bucket : public SpellScriptLoader
{
public:
    spell_hallows_end_has_water_bucket() : SpellScriptLoader("spell_hallows_end_has_water_bucket") {}

    class spell_hallows_end_has_water_bucket_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hallows_end_has_water_bucket_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_HAS_WATER_BUCKET });
        }

        void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetCaster())
                if (caster->GetTypeId() == TYPEID_PLAYER)
                    if (!caster->ToPlayer()->HasItemCount(ITEM_WATER_BUCKET, 1, false))
                        caster->RemoveAurasDueToSpell(SPELL_HAS_WATER_BUCKET);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_hallows_end_has_water_bucket_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_hallows_end_has_water_bucket_AuraScript();
    }
};

void AddSC_event_hallows_end()
{
    new spell_hallows_end_has_water_bucket();
}
