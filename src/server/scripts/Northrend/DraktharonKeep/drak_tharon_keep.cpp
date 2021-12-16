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

#include "CreatureAIImpl.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"

enum SummonRandomDrakkari
{
    SPELL_SUMMON_DRAKKARI_SHAMAN      = 49958,
    SPELL_SUMMON_DRAKKARI_GUARDIAN    = 49959
};

// 49960 - Summon Random Drakkari
class spell_summon_random_drakkari : public SpellScript
{
    PrepareSpellScript(spell_summon_random_drakkari);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_DRAKKARI_SHAMAN, SPELL_SUMMON_DRAKKARI_GUARDIAN });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), RAND(SPELL_SUMMON_DRAKKARI_SHAMAN, SPELL_SUMMON_DRAKKARI_GUARDIAN), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_summon_random_drakkari::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_drak_tharon_keep()
{
    RegisterSpellScript(spell_summon_random_drakkari);
}
