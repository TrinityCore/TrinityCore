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

#include "Define.h"
#include "ScriptMgr.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include "SpellDefines.h"
#include "SpellScript.h"
#include "Unit.h"

namespace Orgrimmar
{
    namespace Spells
    {
        static constexpr uint32 MOPHordeIntroMoviePlay = 130409;
        static constexpr uint32 FadeToBlack            = 130411;
    }
}

// 130412 - Art of War Movie Aura
class spell_art_of_war_movie_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({
            Orgrimmar::Spells::MOPHordeIntroMoviePlay,
            Orgrimmar::Spells::FadeToBlack
        });
    }

    void HandleAfterEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(GetTarget(), Orgrimmar::Spells::FadeToBlack, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void HandleAfterEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(GetTarget(), Orgrimmar::Spells::MOPHordeIntroMoviePlay, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR
        });
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_art_of_war_movie_aura::HandleAfterEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
        AfterEffectRemove += AuraEffectRemoveFn(spell_art_of_war_movie_aura::HandleAfterEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_orgrimmar()
{
    RegisterSpellScript(spell_art_of_war_movie_aura);
}
