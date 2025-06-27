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
#include "SpellInfo.h"
#include "SpellScript.h"
#include "Unit.h"
#include "utgarde_pinnacle.h"

enum UtgardeSpells
{
    SPELL_BEAST_MARK_NORMAL   = 59237,
    SPELL_BEAST_MARK_DAMAGE_N = 48877,
    SPELL_BEAST_MARK_DAMAGE_H = 48876
};

// 48876 - Beast's Mark
// 59237 - Beast's Mark
class spell_utgarde_pinnacle_beast_mark : public AuraScript
{
    PrepareAuraScript(spell_utgarde_pinnacle_beast_mark);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_BEAST_MARK_DAMAGE_N, SPELL_BEAST_MARK_DAMAGE_H });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        if (DamageInfo* damageInfo = eventInfo.GetDamageInfo())
        {
            Unit* attacker = damageInfo->GetAttacker();
            if (!attacker || !damageInfo->GetDamage())
                return false;

            return attacker->GetCreatureType() == CREATURE_TYPE_BEAST;
        }

        return false;
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        Unit* target = GetTarget();
        uint32 spellId = (m_scriptSpellId == SPELL_BEAST_MARK_NORMAL) ? SPELL_BEAST_MARK_DAMAGE_N : SPELL_BEAST_MARK_DAMAGE_H;
        target->CastSpell(target, spellId, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_utgarde_pinnacle_beast_mark::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_utgarde_pinnacle_beast_mark::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

void AddSC_utgarde_pinnacle()
{
    RegisterSpellScript(spell_utgarde_pinnacle_beast_mark);
}
