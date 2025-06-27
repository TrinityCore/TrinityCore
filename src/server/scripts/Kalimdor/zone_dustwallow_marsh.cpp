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
#include "Player.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum OozeZap
{
    SPELL_OOZE_CHANNEL_CREDIT   = 42486
};

// 42489 - Cast Ooze Zap When Energized
class spell_ooze_zap : public SpellScript
{
    PrepareSpellScript(spell_ooze_zap);

    SpellCastResult CheckRequirement()
    {
        if (!GetCaster()->HasAura(GetEffectInfo(EFFECT_1).CalcValue()))
            return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW; // This is actually correct

        if (!GetExplTargetUnit())
            return SPELL_FAILED_BAD_TARGETS;

        return SPELL_CAST_OK;
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (GetHitUnit())
            GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ooze_zap::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnCheckCast += SpellCheckCastFn(spell_ooze_zap::CheckRequirement);
    }
};

// 42485 - End of Ooze Channel
class spell_ooze_zap_channel_end : public SpellScript
{
    PrepareSpellScript(spell_ooze_zap_channel_end);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_OOZE_CHANNEL_CREDIT });
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (Player* player = GetCaster()->ToPlayer())
            player->CastSpell(player, SPELL_OOZE_CHANNEL_CREDIT, true);
        GetHitUnit()->KillSelf();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ooze_zap_channel_end::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 42492 - Cast Energized
class spell_energize_aoe : public SpellScript
{
    PrepareSpellScript(spell_energize_aoe);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
        {
            if ((*itr)->GetTypeId() == TYPEID_PLAYER && (*itr)->ToPlayer()->GetQuestStatus(GetEffectInfo(EFFECT_1).CalcValue()) == QUEST_STATUS_INCOMPLETE)
                ++itr;
            else
                targets.erase(itr++);
        }
        targets.push_back(GetCaster());
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetCaster()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_energize_aoe::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_energize_aoe::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_energize_aoe::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

/*######
## Quest 11140: Recover the Cargo!
######*/

enum RecoverTheCargo
{
    SPELL_SUMMON_LOCKBOX        = 42288,
    SPELL_SUMMON_BURROWER       = 42289
};

// 42287 - Salvage Wreckage
class spell_dustwallow_marsh_salvage_wreckage : public SpellScript
{
    PrepareSpellScript(spell_dustwallow_marsh_salvage_wreckage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_LOCKBOX, SPELL_SUMMON_BURROWER });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), roll_chance_i(50) ? SPELL_SUMMON_LOCKBOX : SPELL_SUMMON_BURROWER);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_dustwallow_marsh_salvage_wreckage::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_dustwallow_marsh()
{
    RegisterSpellScript(spell_ooze_zap);
    RegisterSpellScript(spell_ooze_zap_channel_end);
    RegisterSpellScript(spell_energize_aoe);
    RegisterSpellScript(spell_dustwallow_marsh_salvage_wreckage);
}
