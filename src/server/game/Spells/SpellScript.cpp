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
#include "Spell.h"
#include "ScriptMgr.h"
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
        if (!sSpellMgr->GetSpellInfo(*begin, DIFFICULTY_NONE))
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

_SpellScript::EffectHook::EffectHook(uint8 _effIndex)
{
    // effect index must be in range <0;2>, allow use of special effindexes
    ASSERT(_effIndex == EFFECT_ALL || _effIndex == EFFECT_FIRST_FOUND || _effIndex < MAX_SPELL_EFFECTS);
    effIndex = _effIndex;
}

uint32 _SpellScript::EffectHook::GetAffectedEffectsMask(SpellInfo const* spellEntry) const
{
    uint32 mask = 0;
    if ((effIndex == EFFECT_ALL) || (effIndex == EFFECT_FIRST_FOUND))
    {
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if ((effIndex == EFFECT_FIRST_FOUND) && mask)
                return mask;
            if (CheckEffect(spellEntry, i))
                mask |= 1 << i;
        }
    }
    else
    {
        if (CheckEffect(spellEntry, effIndex))
            mask |= 1 << effIndex;
    }
    return mask;
}

bool _SpellScript::EffectHook::IsEffectAffected(SpellInfo const* spellEntry, uint8 effIndexToCheck) const
{
    return (GetAffectedEffectsMask(spellEntry) & 1 << effIndexToCheck) != 0;
}

std::string _SpellScript::EffectHook::EffIndexToString() const
{
    switch (effIndex)
    {
        case EFFECT_ALL:
            return "EFFECT_ALL";
        case EFFECT_FIRST_FOUND:
            return "EFFECT_FIRST_FOUND";
        case EFFECT_0:
            return "EFFECT_0";
        case EFFECT_1:
            return "EFFECT_1";
        case EFFECT_2:
            return "EFFECT_2";
    }
    return "Invalid Value";
}

bool _SpellScript::EffectNameCheck::Check(SpellInfo const* spellEntry, uint8 effIndex) const
{
    SpellEffectInfo const* effect = spellEntry->GetEffect(effIndex);
    if (!effect)
        return false;
    if (!effect->Effect && !effName)
        return true;
    if (!effect->Effect)
        return false;
    return (effName == SPELL_EFFECT_ANY) || (effect->Effect == effName);
}

std::string _SpellScript::EffectNameCheck::ToString() const
{
    switch (effName)
    {
        case SPELL_EFFECT_ANY:
            return "SPELL_EFFECT_ANY";
        default:
            char num[10];
            sprintf (num, "%u", effName);
            return num;
    }
}

bool _SpellScript::EffectAuraNameCheck::Check(SpellInfo const* spellEntry, uint8 effIndex) const
{
    SpellEffectInfo const* effect = spellEntry->GetEffect(effIndex);
    if (!effect)
        return false;
    if (!effect->ApplyAuraName && !effAurName)
        return true;
    if (!effect->ApplyAuraName)
        return false;
    return (effAurName == SPELL_AURA_ANY) || (effect->ApplyAuraName == effAurName);
}

std::string _SpellScript::EffectAuraNameCheck::ToString() const
{
    switch (effAurName)
    {
        case SPELL_AURA_ANY:
            return "SPELL_AURA_ANY";
        default:
            char num[10];
            sprintf (num, "%u", effAurName);
            return num;
    }
}

SpellScript::CastHandler::CastHandler(SpellCastFnType _pCastHandlerScript)
{
    pCastHandlerScript = _pCastHandlerScript;
}

void SpellScript::CastHandler::Call(SpellScript* spellScript)
{
    (spellScript->*pCastHandlerScript)();
}

SpellScript::CheckCastHandler::CheckCastHandler(SpellCheckCastFnType checkCastHandlerScript)
{
    _checkCastHandlerScript = checkCastHandlerScript;
}

SpellCastResult SpellScript::CheckCastHandler::Call(SpellScript* spellScript)
{
    return (spellScript->*_checkCastHandlerScript)();
}

SpellScript::EffectHandler::EffectHandler(SpellEffectFnType _pEffectHandlerScript, uint8 _effIndex, uint16 _effName)
    : _SpellScript::EffectNameCheck(_effName), _SpellScript::EffectHook(_effIndex)
{
    pEffectHandlerScript = _pEffectHandlerScript;
}

std::string SpellScript::EffectHandler::ToString() const
{
    return "Index: " + EffIndexToString() + " Name: " +_SpellScript::EffectNameCheck::ToString();
}

bool SpellScript::EffectHandler::CheckEffect(SpellInfo const* spellEntry, uint8 effIndexToCheck) const
{
    return _SpellScript::EffectNameCheck::Check(spellEntry, effIndexToCheck);
}

void SpellScript::EffectHandler::Call(SpellScript* spellScript, SpellEffIndex effIndexToHandle)
{
    (spellScript->*pEffectHandlerScript)(effIndexToHandle);
}

SpellScript::BeforeHitHandler::BeforeHitHandler(SpellBeforeHitFnType pBeforeHitHandlerScript)
{
    _pBeforeHitHandlerScript = pBeforeHitHandlerScript;
}

void SpellScript::BeforeHitHandler::Call(SpellScript* spellScript, SpellMissInfo missInfo)
{
    (spellScript->*_pBeforeHitHandlerScript)(missInfo);
}

SpellScript::HitHandler::HitHandler(SpellHitFnType _pHitHandlerScript)
{
    pHitHandlerScript = _pHitHandlerScript;
}

void SpellScript::HitHandler::Call(SpellScript* spellScript)
{
    (spellScript->*pHitHandlerScript)();
}

SpellScript::OnCalcCritChanceHandler::OnCalcCritChanceHandler(SpellOnCalcCritChanceFnType onCalcCritChanceHandlerScript)
{
    _onCalcCritChanceHandlerScript = onCalcCritChanceHandlerScript;
}

void SpellScript::OnCalcCritChanceHandler::Call(SpellScript* spellScript, Unit* victim, float& critChance) const
{
    (spellScript->*_onCalcCritChanceHandlerScript)(victim, critChance);
}

SpellScript::TargetHook::TargetHook(uint8 _effectIndex, uint16 _targetType, bool _area, bool _dest)
    : _SpellScript::EffectHook(_effectIndex), targetType(_targetType), area(_area), dest(_dest) { }

std::string SpellScript::TargetHook::ToString() const
{
    std::ostringstream oss;
    oss << "Index: " << EffIndexToString() << " Target: " << targetType;
    return oss.str();
}

bool SpellScript::TargetHook::CheckEffect(SpellInfo const* spellEntry, uint8 effIndexToCheck) const
{
    if (!targetType)
        return false;

    SpellEffectInfo const* effect = spellEntry->GetEffect(effIndexToCheck);
    if (!effect)
        return false;

    if (effect->TargetA.GetTarget() != targetType &&
        effect->TargetB.GetTarget() != targetType)
        return false;

    SpellImplicitTargetInfo targetInfo(targetType);
    switch (targetInfo.GetSelectionCategory())
    {
        case TARGET_SELECT_CATEGORY_CHANNEL: // SINGLE
            return !area;
        case TARGET_SELECT_CATEGORY_NEARBY: // BOTH
            return true;
        case TARGET_SELECT_CATEGORY_CONE: // AREA
        case TARGET_SELECT_CATEGORY_AREA: // AREA
            return area;
        case TARGET_SELECT_CATEGORY_DEFAULT:
            switch (targetInfo.GetObjectType())
            {
                case TARGET_OBJECT_TYPE_SRC: // EMPTY
                    return false;
                case TARGET_OBJECT_TYPE_DEST: // DEST
                    return dest;
                default:
                    switch (targetInfo.GetReferenceType())
                    {
                        case TARGET_REFERENCE_TYPE_CASTER: // SINGLE
                            return !area;
                        case TARGET_REFERENCE_TYPE_TARGET: // BOTH
                            return true;
                        default:
                            break;
                    }
                    break;
            }
            break;
        default:
            break;
    }

    return false;
}

SpellScript::ObjectAreaTargetSelectHandler::ObjectAreaTargetSelectHandler(SpellObjectAreaTargetSelectFnType _pObjectAreaTargetSelectHandlerScript, uint8 _effIndex, uint16 _targetType)
    : TargetHook(_effIndex, _targetType, true, false)
{
    pObjectAreaTargetSelectHandlerScript = _pObjectAreaTargetSelectHandlerScript;
}

void SpellScript::ObjectAreaTargetSelectHandler::Call(SpellScript* spellScript, std::list<WorldObject*>& targets)
{
    (spellScript->*pObjectAreaTargetSelectHandlerScript)(targets);
}

SpellScript::ObjectTargetSelectHandler::ObjectTargetSelectHandler(SpellObjectTargetSelectFnType _pObjectTargetSelectHandlerScript, uint8 _effIndex, uint16 _targetType)
    : TargetHook(_effIndex, _targetType, false, false)
{
    pObjectTargetSelectHandlerScript = _pObjectTargetSelectHandlerScript;
}

void SpellScript::ObjectTargetSelectHandler::Call(SpellScript* spellScript, WorldObject*& target)
{
    (spellScript->*pObjectTargetSelectHandlerScript)(target);
}

SpellScript::DestinationTargetSelectHandler::DestinationTargetSelectHandler(SpellDestinationTargetSelectFnType _DestinationTargetSelectHandlerScript, uint8 _effIndex, uint16 _targetType)
    : TargetHook(_effIndex, _targetType, false, true)
{
    DestinationTargetSelectHandlerScript = _DestinationTargetSelectHandlerScript;
}

void SpellScript::DestinationTargetSelectHandler::Call(SpellScript* spellScript, SpellDestination& target)
{
    (spellScript->*DestinationTargetSelectHandlerScript)(target);
}

bool SpellScript::_Validate(SpellInfo const* entry)
{
    for (auto itr = OnEffectLaunch.begin(); itr != OnEffectLaunch.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectLaunch` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectLaunchTarget.begin(); itr != OnEffectLaunchTarget.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectLaunchTarget` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectHit.begin(); itr != OnEffectHit.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectHit` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectHitTarget.begin(); itr != OnEffectHitTarget.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectHitTarget` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectSuccessfulDispel.begin(); itr != OnEffectSuccessfulDispel.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectSuccessfulDispel` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnObjectAreaTargetSelect.begin(); itr != OnObjectAreaTargetSelect.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnObjectAreaTargetSelect` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnObjectTargetSelect.begin(); itr != OnObjectTargetSelect.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnObjectTargetSelect` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnDestinationTargetSelect.begin(); itr != OnDestinationTargetSelect.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
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
        case SPELL_SCRIPT_HOOK_EFFECT_SUCCESSFUL_DISPEL:
        case SPELL_SCRIPT_HOOK_BEFORE_HIT:
        case SPELL_SCRIPT_HOOK_HIT:
        case SPELL_SCRIPT_HOOK_AFTER_HIT:
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
    return (m_currentScriptState >= SPELL_SCRIPT_HOOK_EFFECT_LAUNCH && m_currentScriptState <= SPELL_SCRIPT_HOOK_EFFECT_HIT_TARGET)
        || m_currentScriptState == SPELL_SCRIPT_HOOK_EFFECT_SUCCESSFUL_DISPEL;
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
    if (!IsInTargetHook())
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
    if (!IsInTargetHook())
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

SpellEffectInfo const* SpellScript::GetEffectInfo() const
{
    ASSERT(IsInEffectHook(), "Script: `%s` Spell: `%u`: function SpellScript::GetEffectInfo was called, but function has no effect in current hook!", m_scriptName->c_str(), m_scriptSpellId);

    return m_spell->effectInfo;
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

void SpellScript::CreateItem(uint32 effIndex, uint32 itemId, ItemContext context)
{
    m_spell->DoCreateItem(effIndex, itemId, context);
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

Difficulty SpellScript::GetCastDifficulty() const
{
    return m_spell->GetCastDifficulty();
}

SpellValue const* SpellScript::GetSpellValue() const
{
    return m_spell->m_spellValue;
}

SpellEffectInfo const* SpellScript::GetEffectInfo(SpellEffIndex effIndex) const
{
    return GetSpellInfo()->GetEffect(effIndex);
}

bool AuraScript::_Validate(SpellInfo const* entry)
{
    for (auto itr = DoCheckAreaTarget.begin(); itr != DoCheckAreaTarget.end(); ++itr)
        if (!entry->HasAreaAuraEffect() && !entry->HasEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA) && !entry->HasEffect(SPELL_EFFECT_APPLY_AURA))
            TC_LOG_ERROR("scripts", "Spell `%u` of script `%s` does not have apply aura effect - handler bound to hook `DoCheckAreaTarget` of AuraScript won't be executed", entry->Id, m_scriptName->c_str());

    for (auto itr = OnDispel.begin(); itr != OnDispel.end(); ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `%u` of script `%s` does not have apply aura effect - handler bound to hook `OnDispel` of AuraScript won't be executed", entry->Id, m_scriptName->c_str());

    for (auto itr = AfterDispel.begin(); itr != AfterDispel.end(); ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `%u` of script `%s` does not have apply aura effect - handler bound to hook `AfterDispel` of AuraScript won't be executed", entry->Id, m_scriptName->c_str());

    for (auto itr = OnEffectApply.begin(); itr != OnEffectApply.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectApply` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectRemove.begin(); itr != OnEffectRemove.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectRemove` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = AfterEffectApply.begin(); itr != AfterEffectApply.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectApply` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = AfterEffectRemove.begin(); itr != AfterEffectRemove.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectRemove` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectPeriodic.begin(); itr != OnEffectPeriodic.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectPeriodic` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectUpdatePeriodic.begin(); itr != OnEffectUpdatePeriodic.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectUpdatePeriodic` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = DoEffectCalcAmount.begin(); itr != DoEffectCalcAmount.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `DoEffectCalcAmount` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = DoEffectCalcPeriodic.begin(); itr != DoEffectCalcPeriodic.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `DoEffectCalcPeriodic` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = DoEffectCalcSpellMod.begin(); itr != DoEffectCalcSpellMod.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `DoEffectCalcSpellMod` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = DoEffectCalcCritChance.begin(); itr != DoEffectCalcCritChance.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `DoEffectCalcCritChance` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectAbsorb.begin(); itr != OnEffectAbsorb.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectAbsorb` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = AfterEffectAbsorb.begin(); itr != AfterEffectAbsorb.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectAbsorb` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectManaShield.begin(); itr != OnEffectManaShield.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectManaShield` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = AfterEffectManaShield.begin(); itr != AfterEffectManaShield.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectManaShield` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = OnEffectSplit.begin(); itr != OnEffectSplit.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectSplit` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

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
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectProc` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    for (auto itr = AfterEffectProc.begin(); itr != AfterEffectProc.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectProc` of AuraScript won't be executed", entry->Id, itr->ToString().c_str(), m_scriptName->c_str());

    return _SpellScript::_Validate(entry);
}

AuraScript::CheckAreaTargetHandler::CheckAreaTargetHandler(AuraCheckAreaTargetFnType _pHandlerScript)
{
    pHandlerScript = _pHandlerScript;
}

bool AuraScript::CheckAreaTargetHandler::Call(AuraScript* auraScript, Unit* _target)
{
    return (auraScript->*pHandlerScript)(_target);
}

AuraScript::AuraDispelHandler::AuraDispelHandler(AuraDispelFnType _pHandlerScript)
{
    pHandlerScript = _pHandlerScript;
}

void AuraScript::AuraDispelHandler::Call(AuraScript* auraScript, DispelInfo* _dispelInfo)
{
    (auraScript->*pHandlerScript)(_dispelInfo);
}

AuraScript::EffectBase::EffectBase(uint8 _effIndex, uint16 _effName)
    : _SpellScript::EffectAuraNameCheck(_effName), _SpellScript::EffectHook(_effIndex) { }

bool AuraScript::EffectBase::CheckEffect(SpellInfo const* spellEntry, uint8 effIndexToCheck) const
{
    return _SpellScript::EffectAuraNameCheck::Check(spellEntry, effIndexToCheck);
}

std::string AuraScript::EffectBase::ToString() const
{
    return "Index: " + EffIndexToString() + " AuraName: " +_SpellScript::EffectAuraNameCheck::ToString();
}

AuraScript::EffectPeriodicHandler::EffectPeriodicHandler(AuraEffectPeriodicFnType _pEffectHandlerScript, uint8 _effIndex, uint16 _effName)
    : AuraScript::EffectBase(_effIndex, _effName)
{
    pEffectHandlerScript = _pEffectHandlerScript;
}

void AuraScript::EffectPeriodicHandler::Call(AuraScript* auraScript, AuraEffect const* _aurEff)
{
    (auraScript->*pEffectHandlerScript)(_aurEff);
}

AuraScript::EffectUpdatePeriodicHandler::EffectUpdatePeriodicHandler(AuraEffectUpdatePeriodicFnType _pEffectHandlerScript, uint8 _effIndex, uint16 _effName)
    : AuraScript::EffectBase(_effIndex, _effName)
{
    pEffectHandlerScript = _pEffectHandlerScript;
}

void AuraScript::EffectUpdatePeriodicHandler::Call(AuraScript* auraScript, AuraEffect* aurEff)
{
    (auraScript->*pEffectHandlerScript)(aurEff);
}

AuraScript::EffectCalcAmountHandler::EffectCalcAmountHandler(AuraEffectCalcAmountFnType _pEffectHandlerScript, uint8 _effIndex, uint16 _effName)
    : AuraScript::EffectBase(_effIndex, _effName)
{
    pEffectHandlerScript = _pEffectHandlerScript;
}

void AuraScript::EffectCalcAmountHandler::Call(AuraScript* auraScript, AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
{
    (auraScript->*pEffectHandlerScript)(aurEff, amount, canBeRecalculated);
}

AuraScript::EffectCalcPeriodicHandler::EffectCalcPeriodicHandler(AuraEffectCalcPeriodicFnType _pEffectHandlerScript, uint8 _effIndex, uint16 _effName)
    : AuraScript::EffectBase(_effIndex, _effName)
{
    pEffectHandlerScript = _pEffectHandlerScript;
}

void AuraScript::EffectCalcPeriodicHandler::Call(AuraScript* auraScript, AuraEffect const* aurEff, bool& isPeriodic, int32& periodicTimer)
{
    (auraScript->*pEffectHandlerScript)(aurEff, isPeriodic, periodicTimer);
}

AuraScript::EffectCalcSpellModHandler::EffectCalcSpellModHandler(AuraEffectCalcSpellModFnType _pEffectHandlerScript, uint8 _effIndex, uint16 _effName)
    : AuraScript::EffectBase(_effIndex, _effName)
{
    pEffectHandlerScript = _pEffectHandlerScript;
}

void AuraScript::EffectCalcSpellModHandler::Call(AuraScript* auraScript, AuraEffect const* aurEff, SpellModifier*& spellMod)
{
    (auraScript->*pEffectHandlerScript)(aurEff, spellMod);
}

AuraScript::EffectCalcCritChanceHandler::EffectCalcCritChanceHandler(AuraEffectCalcCritChanceFnType effectHandlerScript, uint8 effIndex, uint16 effName)
    : AuraScript::EffectBase(effIndex, effName)
{
    _effectHandlerScript = effectHandlerScript;
}

void AuraScript::EffectCalcCritChanceHandler::Call(AuraScript* auraScript, AuraEffect const* aurEff, Unit* victim, float& critChance) const
{
    (auraScript->*_effectHandlerScript)(aurEff, victim, critChance);
}

AuraScript::EffectApplyHandler::EffectApplyHandler(AuraEffectApplicationModeFnType _pEffectHandlerScript, uint8 _effIndex, uint16 _effName, AuraEffectHandleModes _mode)
    : AuraScript::EffectBase(_effIndex, _effName)
{
    pEffectHandlerScript = _pEffectHandlerScript;
    mode = _mode;
}

void AuraScript::EffectApplyHandler::Call(AuraScript* auraScript, AuraEffect const* _aurEff, AuraEffectHandleModes _mode)
{
    if (_mode & mode)
        (auraScript->*pEffectHandlerScript)(_aurEff, _mode);
}

AuraScript::EffectAbsorbHandler::EffectAbsorbHandler(AuraEffectAbsorbFnType _pEffectHandlerScript, uint8 _effIndex, bool overKill)
    : AuraScript::EffectBase(_effIndex, overKill ? SPELL_AURA_SCHOOL_ABSORB_OVERKILL : SPELL_AURA_SCHOOL_ABSORB)
{
    pEffectHandlerScript = _pEffectHandlerScript;
}

void AuraScript::EffectAbsorbHandler::Call(AuraScript* auraScript, AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
{
    (auraScript->*pEffectHandlerScript)(aurEff, dmgInfo, absorbAmount);
}

AuraScript::EffectManaShieldHandler::EffectManaShieldHandler(AuraEffectAbsorbFnType _pEffectHandlerScript, uint8 _effIndex)
    : AuraScript::EffectBase(_effIndex, SPELL_AURA_MANA_SHIELD)
{
    pEffectHandlerScript = _pEffectHandlerScript;
}

void AuraScript::EffectManaShieldHandler::Call(AuraScript* auraScript, AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
{
    (auraScript->*pEffectHandlerScript)(aurEff, dmgInfo, absorbAmount);
}

AuraScript::EffectSplitHandler::EffectSplitHandler(AuraEffectSplitFnType _pEffectHandlerScript, uint8 _effIndex)
    : AuraScript::EffectBase(_effIndex, SPELL_AURA_SPLIT_DAMAGE_PCT)
{
    pEffectHandlerScript = _pEffectHandlerScript;
}

void AuraScript::EffectSplitHandler::Call(AuraScript* auraScript, AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& splitAmount)
{
    (auraScript->*pEffectHandlerScript)(aurEff, dmgInfo, splitAmount);
}

AuraScript::CheckProcHandler::CheckProcHandler(AuraCheckProcFnType handlerScript)
{
    _HandlerScript = handlerScript;
}

bool AuraScript::CheckProcHandler::Call(AuraScript* auraScript, ProcEventInfo& eventInfo)
{
    return (auraScript->*_HandlerScript)(eventInfo);
}

AuraScript::CheckEffectProcHandler::CheckEffectProcHandler(AuraCheckEffectProcFnType handlerScript, uint8 effIndex, uint16 effName)
    : AuraScript::EffectBase(effIndex, effName)
{
    _HandlerScript = handlerScript;
}

bool AuraScript::CheckEffectProcHandler::Call(AuraScript* auraScript, AuraEffect const* aurEff, ProcEventInfo& eventInfo)
{
    return (auraScript->*_HandlerScript)(aurEff, eventInfo);
}

AuraScript::AuraProcHandler::AuraProcHandler(AuraProcFnType handlerScript)
{
    _HandlerScript = handlerScript;
}

void AuraScript::AuraProcHandler::Call(AuraScript* auraScript, ProcEventInfo& eventInfo)
{
    (auraScript->*_HandlerScript)(eventInfo);
}

AuraScript::EffectProcHandler::EffectProcHandler(AuraEffectProcFnType effectHandlerScript, uint8 effIndex, uint16 effName)
    : AuraScript::EffectBase(effIndex, effName)
{
    _EffectHandlerScript = effectHandlerScript;
}

void AuraScript::EffectProcHandler::Call(AuraScript* auraScript, AuraEffect* aurEff, ProcEventInfo& eventInfo)
{
    (auraScript->*_EffectHandlerScript)(aurEff, eventInfo);
}

AuraScript::EnterLeaveCombatHandler::EnterLeaveCombatHandler(AuraEnterLeaveCombatFnType handlerScript)
{
    _handlerScript = handlerScript;
}

void AuraScript::EnterLeaveCombatHandler::Call(AuraScript* auraScript, bool isNowInCombat) const
{
    (auraScript->*_handlerScript)(isNowInCombat);
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

bool AuraScript::_IsDefaultActionPrevented() const
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

void AuraScript::Remove(AuraRemoveMode removeMode)
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

bool AuraScript::ModCharges(int8 num, AuraRemoveMode removeMode /*= AURA_REMOVE_BY_DEFAULT*/)
{
    return m_aura->ModCharges(num, removeMode);
}

bool AuraScript::DropCharge(AuraRemoveMode removeMode)
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

bool AuraScript::ModStackAmount(int32 num, AuraRemoveMode removeMode)
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
        case AURA_SCRIPT_HOOK_ENTER_LEAVE_COMBAT:
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

Difficulty AuraScript::GetCastDifficulty() const
{
    return GetAura()->GetCastDifficulty();
}
