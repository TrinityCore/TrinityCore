/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Containers.h"
#include "Formulas.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "TemporarySummon.h"

// 213712
class spell_toy_careful_swing : public SpellScript
{
    PrepareSpellScript(spell_toy_careful_swing);

    SpellCastResult CheckCast()
    {
        if (!GetExplTargetUnit())
            return SPELL_FAILED_BAD_TARGETS;

        if (!GetExplTargetUnit()->ToCreature())
            return SPELL_FAILED_BAD_TARGETS;

        if (Trinity::XP::GetColorCode(GetCaster()->getLevel(), GetExplTargetUnit()->getLevel()) != XP_GRAY)
            return SPELL_FAILED_BAD_TARGETS;

        if (GetExplTargetUnit()->ToCreature()->GetCreatureTemplate()->rank != CREATURE_ELITE_NORMAL)
            return SPELL_FAILED_BAD_TARGETS;

        if (!GetCaster()->GetMap()->GetEntry()->IsContinent())
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_toy_careful_swing::CheckCast);
    }
};

void AddSC_toy_spell_scripts()
{
    RegisterSpellScript(spell_toy_careful_swing);
}
