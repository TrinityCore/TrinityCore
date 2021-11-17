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
#include "CreatureAIImpl.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Mistletoe
{
    SPELL_CREATE_MISTLETOE          = 26206,
    SPELL_CREATE_HOLLY              = 26207,
    SPELL_CREATE_SNOWFLAKES         = 45036
};

// 26218 - Mistletoe
class spell_winter_veil_mistletoe : public SpellScript
{
    PrepareSpellScript(spell_winter_veil_mistletoe);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_CREATE_MISTLETOE,
            SPELL_CREATE_HOLLY,
            SPELL_CREATE_SNOWFLAKES
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Player* target = GetHitPlayer())
        {
            uint32 spellId = RAND(SPELL_CREATE_HOLLY, SPELL_CREATE_MISTLETOE, SPELL_CREATE_SNOWFLAKES);
            GetCaster()->CastSpell(target, spellId, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_winter_veil_mistletoe::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 26275 - PX-238 Winter Wondervolt TRAP
enum PX238WinterWondervolt
{
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_1  = 26157,
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_2  = 26272,
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_3  = 26273,
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_4  = 26274
};

uint32 const WonderboltTransformSpells[] =
{
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_1,
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_2,
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_3,
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_4
};

// 26275 - PX-238 Winter Wondervolt TRAP
class spell_winter_veil_px_238_winter_wondervolt : public SpellScript
{
    PrepareSpellScript(spell_winter_veil_px_238_winter_wondervolt);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(WonderboltTransformSpells);
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        if (Unit* target = GetHitUnit())
        {
            for (uint32 spell : WonderboltTransformSpells)
                if (target->HasAura(spell))
                    return;

            target->CastSpell(target, Trinity::Containers::SelectRandomContainerElement(WonderboltTransformSpells), true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_winter_veil_px_238_winter_wondervolt::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_event_winter_veil()
{
    RegisterSpellScript(spell_winter_veil_mistletoe);
    RegisterSpellScript(spell_winter_veil_px_238_winter_wondervolt);
}
