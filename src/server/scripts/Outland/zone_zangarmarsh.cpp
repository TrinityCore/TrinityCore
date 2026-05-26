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
#include "SpellScript.h"
#include "Unit.h"

/*######
## Quest 9718: As the Crow Flies
######*/

enum AsTheCrowFlies
{
    SPELL_STORMCROW_SHAPE     = 31746,
    SPELL_WHISPER_AURA_1      = 31773,
    SPELL_WHISPER_AURA_2      = 31774,
    SPELL_WHISPER_AURA_3      = 31775,
    SPELL_WHISPER_AURA_4      = 31776,
    SPELL_WHISPER_AURA_5      = 31777
};

// 31606 - Stormcrow Amulet
class spell_zangarmarsh_stormcrow_amulet : public AuraScript
{
    PrepareAuraScript(spell_zangarmarsh_stormcrow_amulet);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_STORMCROW_SHAPE, SPELL_WHISPER_AURA_1 });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_STORMCROW_SHAPE, true);
        target->CastSpell(target, SPELL_WHISPER_AURA_1, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_zangarmarsh_stormcrow_amulet::AfterApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 31773, 31774, 31775, 31776 - As the Crow Flies Whisper Aura
class spell_zangarmarsh_whisper_aura : public AuraScript
{
    PrepareAuraScript(spell_zangarmarsh_whisper_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WHISPER_AURA_5 });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        switch (GetId())
        {
            case SPELL_WHISPER_AURA_1:
                GetTarget()->CastSpell(GetTarget(), SPELL_WHISPER_AURA_2, true);
                break;
            case SPELL_WHISPER_AURA_2:
                GetTarget()->CastSpell(GetTarget(), SPELL_WHISPER_AURA_3, true);
                break;
            case SPELL_WHISPER_AURA_3:
                GetTarget()->CastSpell(GetTarget(), SPELL_WHISPER_AURA_4, true);
                break;
            case SPELL_WHISPER_AURA_4:
                GetTarget()->CastSpell(GetTarget(), SPELL_WHISPER_AURA_5, true);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_zangarmarsh_whisper_aura::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_zangarmarsh()
{
    RegisterSpellScript(spell_zangarmarsh_stormcrow_amulet);
    RegisterSpellScript(spell_zangarmarsh_whisper_aura);
}
