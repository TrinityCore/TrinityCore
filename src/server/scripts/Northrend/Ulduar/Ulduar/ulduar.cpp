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
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

// 61906 - Random Aggro Periodic (5 sec)
class spell_ulduar_random_aggro_periodic : public AuraScript
{
    PrepareAuraScript(spell_ulduar_random_aggro_periodic);

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        target->GetThreatManager().ResetAllThreat();
        if (!target->IsAIEnabled())
            return;

        if (Unit* victim = target->GetAI()->SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true, false))
        {
            target->GetThreatManager().AddThreat(victim, 3000000.0f, nullptr, true, true);
            target->GetAI()->AttackStart(victim);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_ulduar_random_aggro_periodic::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 64014 - Expedition Base Camp Teleport
// 64025 - Halls of Invention Teleport
// 64028 - Colossal Forge Teleport
// 64029 - Shattered Walkway Teleport
// 64030 - Antechamber Teleport
// 64032 - Formation Grounds Teleport
// 65042 - Prison of Yogg-Saron Teleport
class spell_ulduar_teleporter : public SpellScript
{
    PrepareSpellScript(spell_ulduar_teleporter);

    SpellCastResult CheckRequirement()
    {
        if (GetExplTargetUnit()->GetTypeId() != TYPEID_PLAYER)
            return SPELL_FAILED_DONT_REPORT;

        if (GetExplTargetUnit()->IsInCombat())
        {
            Spell::SendCastResult(GetExplTargetUnit()->ToPlayer(), GetSpellInfo(), 0, SPELL_FAILED_AFFECTING_COMBAT);
            return SPELL_FAILED_AFFECTING_COMBAT;
        }

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_ulduar_teleporter::CheckRequirement);
    }
};

void AddSC_ulduar()
{
    RegisterSpellScript(spell_ulduar_teleporter);
    RegisterSpellScript(spell_ulduar_random_aggro_periodic);
}
