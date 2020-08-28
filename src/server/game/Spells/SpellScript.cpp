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

#include "SpellScript.h"
#include "Log.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include <sstream>
#include <string>

bool _SpellScript::_Validate(SpellInfo const* entry)
{
    if (!Validate(entry))
    {
        TC_LOG_ERROR("scripts", "Spell `%u` did not pass Validate() function of script `%s` - script will be not added to the spell", entry->Id, m_scriptName->c_str());
        return false;
    }
    return true;
}

bool _SpellScript::_ValidateSpellInfo(uint32 const* begin, uint32 const* end)
{
    bool allValid = true;
    while (begin != end)
    {
        if (!sSpellMgr->GetSpellInfo(*begin))
        {
            TC_LOG_ERROR("scripts.spells", "_SpellScript::ValidateSpellInfo: Spell %u does not exist.", *begin);
            allValid = false;
        }

        ++begin;
    }
    return allValid;
}

void _SpellScript::_Register()
{
    m_currentScriptState = SPELL_SCRIPT_STATE_REGISTRATION;
    Register();
    m_currentScriptState = SPELL_SCRIPT_STATE_NONE;
}

void _SpellScript::_Unload()
{
    m_currentScriptState = SPELL_SCRIPT_STATE_UNLOADING;
    Unload();
    m_currentScriptState = SPELL_SCRIPT_STATE_NONE;
}

void _SpellScript::_Init(std::string const* scriptname, uint32 spellId)
{
    m_currentScriptState = SPELL_SCRIPT_STATE_NONE;
    m_scriptName = scriptname;
    m_scriptSpellId = spellId;

#ifdef TRINITY_API_USE_DYNAMIC_LINKING
    // Acquire a strong reference to the binary code
    // to keep it loaded until all spells are destroyed.
    m_moduleReference = sScriptMgr->AcquireModuleReferenceOfScriptName(*scriptname);
#endif // #ifndef TRINITY_API_USE_DYNAMIC_LINKING
}

std::string const* _SpellScript::_GetScriptName() const
{
    return m_scriptName;
}

bool SpellScript::_Validate(SpellInfo const* entry)
{
    for (auto itr = OnEffectLaunch.begin(); itr != OnEffectLaunch.end(); ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectLaunch` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectLaunchTarget.begin(); itr != OnEffectLaunchTarget.end(); ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectLaunchTarget` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectHit.begin(); itr != OnEffectHit.end(); ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectHit` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectHitTarget.begin(); itr != OnEffectHitTarget.end(); ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectHitTarget` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectSuccessfulDispel.begin(); itr != OnEffectSuccessfulDispel.end(); ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectSuccessfulDispel` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnObjectAreaTargetSelect.begin(); itr != OnObjectAreaTargetSelect.end(); ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnObjectAreaTargetSelect` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnObjectTargetSelect.begin(); itr != OnObjectTargetSelect.end(); ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnObjectTargetSelect` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnDestinationTargetSelect.begin(); itr != OnDestinationTargetSelect.end(); ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnDestinationTargetSelect` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    return _SpellScript::_Validate(entry);
}

bool SpellScript::_Load(Spell* spell)
{
    m_spell = spell;
    _PrepareScriptCall((SpellScriptHookType)SPELL_SCRIPT_STATE_LOADING);
    bool load = Load();
    _FinishScriptCall();
    return load;
}

void SpellScript::_InitHit()
{
    m_hitPreventEffectMask = 0;
    m_hitPreventDefaultEffectMask = 0;
}

void SpellScript::_PrepareScriptCall(SpellScriptHookType hookType)
{
    m_currentScriptState = hookType;
}

void SpellScript::_FinishScriptCall()
{
    m_currentScriptState = SPELL_SCRIPT_STATE_NONE;
}

bool SpellScript::IsInCheckCastHook() const
{
    return m_currentScriptState == SPELL_SCRIPT_HOOK_CHECK_CAST;
}
bool SpellScript::IsInTargetHook() const
{
    switch (m_currentScriptState)
    {
        case SPELL_SCRIPT_HOOK_EFFECT_LAUNCH_TARGET:
        case SPELL_SCRIPT_HOOK_EFFECT_HIT_TARGET:
        case SPELL_SCRIPT_HOOK_BEFORE_HIT:
        case SPELL_SCRIPT_HOOK_HIT:
        case SPELL_SCRIPT_HOOK_AFTER_HIT:
            return true;
    }
    return false;
}

bool SpellScript::IsInModifiableHook() const
{
    // after hit hook executed after damage/healing is already done
    // modifying it at this point has no effect
    switch (m_currentScriptState)
    {
        case SPELL_SCRIPT_HOOK_EFFECT_LAUNCH_TARGET:
        case SPELL_SCRIPT_HOOK_EFFECT_HIT_TARGET:
        case SPELL_SCRIPT_HOOK_BEFORE_HIT:
        case SPELL_SCRIPT_HOOK_HIT:
            return true;
    }
    return false;
}

bool SpellScript::IsInHitPhase() const
{
    return (m_currentScriptState >= HOOK_SPELL_HIT_START && m_currentScriptState < HOOK_SPELL_HIT_END);
}

bool SpellScript::IsInEffectHook() const
{
    return (m_currentScriptState >= SPELL_SCRIPT_HOOK_EFFECT_LAUNCH && m_currentScriptState <= SPELL_SCRIPT_HOOK_EFFECT_HIT_TARGET);
}

Unit* SpellScript::GetCaster() const
{
     return m_spell->GetCaster();
}

Unit* SpellScript::GetOriginalCaster() const
{
     return m_spell->GetOriginalCaster();
}

SpellInfo const* SpellScript::GetSpellInfo() const
{
    return m_spell->GetSpellInfo();
}

WorldLocation const* SpellScript::GetExplTargetDest() const
{
    if (m_spell->m_targets.HasDst())
        return m_spell->m_targets.GetDstPos();
    return nullptr;
}

void SpellScript::SetExplTargetDest(WorldLocation& loc)
{
    m_spell->m_targets.SetDst(loc);
}

WorldObject* SpellScript::GetExplTargetWorldObject() const
{
    return m_spell->m_targets.GetObjectTarget();
}

Unit* SpellScript::GetExplTargetUnit() const
{
    return m_spell->m_targets.GetUnitTarget();
}

GameObject* SpellScript::GetExplTargetGObj() const
{
    return m_spell->m_targets.GetGOTarget();
}

Item* SpellScript::GetExplTargetItem() const
{
    return m_spell->m_targets.GetItemTarget();
}

Unit* SpellScript::GetHitUnit() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::GetHitUnit was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return nullptr;
    }
    return m_spell->unitTarget;
}

Creature* SpellScript::GetHitCreature() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::GetHitCreature was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return nullptr;
    }
    if (m_spell->unitTarget)
        return m_spell->unitTarget->ToCreature();
    else
        return nullptr;
}

Player* SpellScript::GetHitPlayer() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::GetHitPlayer was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return nullptr;
    }
    if (m_spell->unitTarget)
        return m_spell->unitTarget->ToPlayer();
    else
        return nullptr;
}

Item* SpellScript::GetHitItem() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::GetHitItem was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return nullptr;
    }
    return m_spell->itemTarget;
}

GameObject* SpellScript::GetHitGObj() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::GetHitGObj was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return nullptr;
    }
    return m_spell->gameObjTarget;
}

Corpse* SpellScript::GetHitCorpse() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::GetHitCorpse was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return nullptr;
    }
    return m_spell->corpseTarget;
}

WorldLocation* SpellScript::GetHitDest() const
{
    if (!IsInEffectHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::GetHitDest was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return nullptr;
    }
    return m_spell->destTarget;
}

int32 SpellScript::GetHitDamage() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::GetHitDamage was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return 0;
    }
    return m_spell->m_damage;
}

void SpellScript::SetHitDamage(int32 damage)
{
    if (!IsInModifiableHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::SetHitDamage was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }
    m_spell->m_damage = damage;
}

int32 SpellScript::GetHitHeal() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::GetHitHeal was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return 0;
    }
    return m_spell->m_healing;
}

void SpellScript::SetHitHeal(int32 heal)
{
    if (!IsInModifiableHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::SetHitHeal was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }
    m_spell->m_healing = heal;
}

Aura* SpellScript::GetHitAura() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::GetHitAura was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return nullptr;
    }
    if (!m_spell->m_spellAura)
        return nullptr;
    if (m_spell->m_spellAura->IsRemoved())
        return nullptr;
    return m_spell->m_spellAura;
}

void SpellScript::PreventHitAura()
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::PreventHitAura was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }
    if (m_spell->m_spellAura)
        m_spell->m_spellAura->Remove();
}

void SpellScript::PreventHitEffect(SpellEffIndex effIndex)
{
    if (!IsInHitPhase() && !IsInEffectHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::PreventHitEffect was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }
    m_hitPreventEffectMask |= 1 << effIndex;
    PreventHitDefaultEffect(effIndex);
}

void SpellScript::PreventHitDefaultEffect(SpellEffIndex effIndex)
{
    if (!IsInHitPhase() && !IsInEffectHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::PreventHitDefaultEffect was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }
    m_hitPreventDefaultEffectMask |= 1 << effIndex;
}

int32 SpellScript::GetEffectValue() const
{
    if (!IsInEffectHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::GetEffectValue was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return 0;
    }

    return m_spell->damage;
}

void SpellScript::SetEffectValue(int32 value)
{
    if (!IsInEffectHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::SetEffectValue was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }

    m_spell->damage = value;
}

Item* SpellScript::GetCastItem() const
{
    return m_spell->m_CastItem;
}

void SpellScript::CreateItem(uint32 effIndex, uint32 itemId)
{
    m_spell->DoCreateItem(effIndex, itemId);
}

SpellInfo const* SpellScript::GetTriggeringSpell() const
{
    return m_spell->m_triggeredByAuraSpell;
}

void SpellScript::FinishCast(SpellCastResult result, uint32* param1 /*= nullptr*/, uint32* param2 /*= nullptr*/)
{
    m_spell->SendCastResult(result, param1, param2);
    m_spell->finish(result == SPELL_CAST_OK);
}

void SpellScript::SetCustomCastResultMessage(SpellCustomErrors result)
{
    if (!IsInCheckCastHook())
    {
        TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u`: function SpellScript::SetCustomCastResultMessage was called while spell not in check cast phase!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }

    m_spell->m_customError = result;
}

SpellValue const* SpellScript::GetSpellValue() const
{
    return m_spell->m_spellValue;
}

bool AuraScript::_Validate(SpellInfo const* entry)
{
    for (auto itr = DoCheckAreaTarget.begin(); itr != DoCheckAreaTarget.end();  ++itr)
        if (!entry->HasAreaAuraEffect() && !entry->HasEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA) && !entry->HasEffect(SPELL_EFFECT_APPLY_AURA))
            TC_LOG_ERROR("scripts", "Spell `%u` of script `%s` does not have apply aura effect - handler bound to hook `DoCheckAreaTarget` of AuraScript won't be executed", entry->Id, m_scriptName->c_str());

    for (auto itr = OnDispel.begin(); itr != OnDispel.end();  ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `%u` of script `%s` does not have apply aura effect - handler bound to hook `OnDispel` of AuraScript won't be executed", entry->Id, m_scriptName->c_str());

    for (auto itr = AfterDispel.begin(); itr != AfterDispel.end();  ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `%u` of script `%s` does not have apply aura effect - handler bound to hook `AfterDispel` of AuraScript won't be executed", entry->Id, m_scriptName->c_str());

    for (auto itr = OnEffectApply.begin(); itr != OnEffectApply.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectApply` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectRemove.begin(); itr != OnEffectRemove.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectRemove` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = AfterEffectApply.begin(); itr != AfterEffectApply.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectApply` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = AfterEffectRemove.begin(); itr != AfterEffectRemove.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectRemove` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectPeriodic.begin(); itr != OnEffectPeriodic.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectPeriodic` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectUpdatePeriodic.begin(); itr != OnEffectUpdatePeriodic.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectUpdatePeriodic` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = DoEffectCalcAmount.begin(); itr != DoEffectCalcAmount.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `DoEffectCalcAmount` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = DoEffectCalcPeriodic.begin(); itr != DoEffectCalcPeriodic.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `DoEffectCalcPeriodic` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = DoEffectCalcSpellMod.begin(); itr != DoEffectCalcSpellMod.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `DoEffectCalcSpellMod` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectAbsorb.begin(); itr != OnEffectAbsorb.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectAbsorb` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = AfterEffectAbsorb.begin(); itr != AfterEffectAbsorb.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectAbsorb` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectManaShield.begin(); itr != OnEffectManaShield.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectManaShield` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = AfterEffectManaShield.begin(); itr != AfterEffectManaShield.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectManaShield` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectSplit.begin(); itr != OnEffectSplit.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectSplit` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = DoCheckProc.begin(); itr != DoCheckProc.end(); ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `%u` of script `%s` does not have apply aura effect - handler bound to hook `DoCheckProc` of AuraScript won't be executed", entry->Id, m_scriptName->c_str());

    for (auto itr = DoCheckEffectProc.begin(); itr != DoCheckEffectProc.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `DoCheckEffectProc` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = DoPrepareProc.begin(); itr != DoPrepareProc.end(); ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `%u` of script `%s` does not have apply aura effect - handler bound to hook `DoPrepareProc` of AuraScript won't be executed", entry->Id, m_scriptName->c_str());

    for (auto itr = OnProc.begin(); itr != OnProc.end(); ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `%u` of script `%s` does not have apply aura effect - handler bound to hook `OnProc` of AuraScript won't be executed", entry->Id, m_scriptName->c_str());

    for (auto itr = AfterProc.begin(); itr != AfterProc.end(); ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `%u` of script `%s` does not have apply aura effect - handler bound to hook `AfterProc` of AuraScript won't be executed", entry->Id, m_scriptName->c_str());

    for (auto itr = OnEffectProc.begin(); itr != OnEffectProc.end(); ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectProc` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = AfterEffectProc.begin(); itr != AfterEffectProc.end(); ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectProc` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    return _SpellScript::_Validate(entry);
}

bool AuraScript::_Load(Aura* aura)
{
    m_aura = aura;
    _PrepareScriptCall((AuraScriptHookType)SPELL_SCRIPT_STATE_LOADING, nullptr);
    bool load = Load();
    _FinishScriptCall();
    return load;
}

void AuraScript::_PrepareScriptCall(AuraScriptHookType hookType, AuraApplication const* aurApp)
{
    m_scriptStates.push(ScriptStateStore(m_currentScriptState, m_auraApplication, m_defaultActionPrevented));
    m_currentScriptState = hookType;
    m_defaultActionPrevented = false;
    m_auraApplication = aurApp;
}

void AuraScript::_FinishScriptCall()
{
    ScriptStateStore stateStore = m_scriptStates.top();
    m_currentScriptState = stateStore._currentScriptState;
    m_auraApplication = stateStore._auraApplication;
    m_defaultActionPrevented = stateStore._defaultActionPrevented;
    m_scriptStates.pop();
}

bool AuraScript::_IsDefaultActionPrevented()
{
    switch (m_currentScriptState)
    {
        case AURA_SCRIPT_HOOK_EFFECT_APPLY:
        case AURA_SCRIPT_HOOK_EFFECT_REMOVE:
        case AURA_SCRIPT_HOOK_EFFECT_PERIODIC:
        case AURA_SCRIPT_HOOK_EFFECT_ABSORB:
        case AURA_SCRIPT_HOOK_EFFECT_SPLIT:
        case AURA_SCRIPT_HOOK_PREPARE_PROC:
        case AURA_SCRIPT_HOOK_PROC:
        case AURA_SCRIPT_HOOK_EFFECT_PROC:
            return m_defaultActionPrevented;
        default:
            ASSERT(false && "AuraScript::_IsDefaultActionPrevented is called in a wrong place");
            return false;
    }
}

void AuraScript::PreventDefaultAction()
{
    switch (m_currentScriptState)
    {
        case AURA_SCRIPT_HOOK_EFFECT_APPLY:
        case AURA_SCRIPT_HOOK_EFFECT_REMOVE:
        case AURA_SCRIPT_HOOK_EFFECT_PERIODIC:
        case AURA_SCRIPT_HOOK_EFFECT_ABSORB:
        case AURA_SCRIPT_HOOK_EFFECT_SPLIT:
        case AURA_SCRIPT_HOOK_PREPARE_PROC:
        case AURA_SCRIPT_HOOK_PROC:
        case AURA_SCRIPT_HOOK_EFFECT_PROC:
            m_defaultActionPrevented = true;
            break;
        default:
            TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u` AuraScript::PreventDefaultAction called in a hook in which the call won't have effect!", m_scriptName->c_str(), m_scriptSpellId);
            break;
    }
}

SpellInfo const* AuraScript::GetSpellInfo() const
{
    return m_aura->GetSpellInfo();
}

uint32 AuraScript::GetId() const
{
    return m_aura->GetId();
}

ObjectGuid AuraScript::GetCasterGUID() const
{
    return m_aura->GetCasterGUID();
}

Unit* AuraScript::GetCaster() const
{
    return m_aura->GetCaster();
}

WorldObject* AuraScript::GetOwner() const
{
    return m_aura->GetOwner();
}

Unit* AuraScript::GetUnitOwner() const
{
    return m_aura->GetUnitOwner();
}

DynamicObject* AuraScript::GetDynobjOwner() const
{
    return m_aura->GetDynobjOwner();
}

void AuraScript::Remove(AuraRemoveFlags removeMode)
{
    m_aura->Remove(removeMode);
}

Aura* AuraScript::GetAura() const
{
    return m_aura;
}

AuraObjectType AuraScript::GetType() const
{
    return m_aura->GetType();
}

int32 AuraScript::GetDuration() const
{
    return m_aura->GetDuration();
}

void AuraScript::SetDuration(int32 duration, bool withMods)
{
    m_aura->SetDuration(duration, withMods);
}

void AuraScript::RefreshDuration()
{
    m_aura->RefreshDuration();
}

time_t AuraScript::GetApplyTime() const
{
    return m_aura->GetApplyTime();
}

int32 AuraScript::GetMaxDuration() const
{
    return m_aura->GetMaxDuration();
}

void AuraScript::SetMaxDuration(int32 duration)
{
    m_aura->SetMaxDuration(duration);
}

int32 AuraScript::CalcMaxDuration() const
{
    return m_aura->CalcMaxDuration();
}

bool AuraScript::IsExpired() const
{
    return m_aura->IsExpired();
}

bool AuraScript::IsPermanent() const
{
    return m_aura->IsPermanent();
}

uint8 AuraScript::GetCharges() const
{
    return m_aura->GetCharges();
}

void AuraScript::SetCharges(uint8 charges)
{
    m_aura->SetCharges(charges);
}

uint8 AuraScript::CalcMaxCharges() const
{
    return m_aura->CalcMaxCharges();
}

bool AuraScript::ModCharges(int8 num, AuraRemoveFlags removeMode /*= AuraRemoveFlags::ByDefault*/)
{
    return m_aura->ModCharges(num, removeMode);
}

bool AuraScript::DropCharge(AuraRemoveFlags removeMode)
{
    return m_aura->DropCharge(removeMode);
}

uint8 AuraScript::GetStackAmount() const
{
    return m_aura->GetStackAmount();
}

void AuraScript::SetStackAmount(uint8 num)
{
    m_aura->SetStackAmount(num);
}

bool AuraScript::ModStackAmount(int32 num, AuraRemoveFlags removeMode)
{
    return m_aura->ModStackAmount(num, removeMode);
}

bool AuraScript::IsPassive() const
{
    return m_aura->IsPassive();
}

bool AuraScript::IsDeathPersistent() const
{
    return m_aura->IsDeathPersistent();
}

bool AuraScript::HasEffect(uint8 effIndex) const
{
    return m_aura->HasEffect(effIndex);
}

AuraEffect* AuraScript::GetEffect(uint8 effIndex) const
{
    return m_aura->GetEffect(effIndex);
}

bool AuraScript::HasEffectType(AuraType type) const
{
    return m_aura->HasEffectType(type);
}

Unit* AuraScript::GetTarget() const
{
    switch (m_currentScriptState)
    {
        case AURA_SCRIPT_HOOK_EFFECT_APPLY:
        case AURA_SCRIPT_HOOK_EFFECT_REMOVE:
        case AURA_SCRIPT_HOOK_EFFECT_AFTER_APPLY:
        case AURA_SCRIPT_HOOK_EFFECT_AFTER_REMOVE:
        case AURA_SCRIPT_HOOK_EFFECT_PERIODIC:
        case AURA_SCRIPT_HOOK_EFFECT_ABSORB:
        case AURA_SCRIPT_HOOK_EFFECT_AFTER_ABSORB:
        case AURA_SCRIPT_HOOK_EFFECT_MANASHIELD:
        case AURA_SCRIPT_HOOK_EFFECT_AFTER_MANASHIELD:
        case AURA_SCRIPT_HOOK_EFFECT_SPLIT:
        case AURA_SCRIPT_HOOK_CHECK_PROC:
        case AURA_SCRIPT_HOOK_CHECK_EFFECT_PROC:
        case AURA_SCRIPT_HOOK_PREPARE_PROC:
        case AURA_SCRIPT_HOOK_PROC:
        case AURA_SCRIPT_HOOK_AFTER_PROC:
        case AURA_SCRIPT_HOOK_EFFECT_PROC:
        case AURA_SCRIPT_HOOK_EFFECT_AFTER_PROC:
            return m_auraApplication->GetTarget();
        default:
            TC_LOG_ERROR("scripts", "Script: `%s` Spell: `%u` AuraScript::GetTarget called in a hook in which the call won't have effect!", m_scriptName->c_str(), m_scriptSpellId);
    }

    return nullptr;
}

AuraApplication const* AuraScript::GetTargetApplication() const
{
    return m_auraApplication;
}
