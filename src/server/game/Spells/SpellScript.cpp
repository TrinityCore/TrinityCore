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
#include "StringConvert.h"
#include "Unit.h"
#include <string>

bool SpellScriptBase::_Validate(SpellInfo const* entry)
{
    if (!Validate(entry))
    {
        TC_LOG_ERROR("scripts", "Spell `{}` did not pass Validate() function of script `{}` - script will be not added to the spell", entry->Id, m_scriptName);
        return false;
    }
    return true;
}

SpellScriptBase::SpellScriptBase(): m_currentScriptState(SPELL_SCRIPT_STATE_NONE), m_scriptSpellId(0)
{
}

SpellScriptBase::~SpellScriptBase() = default;

bool SpellScriptBase::ValidateSpellInfoImpl(uint32 spellId)
{
    if (!sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE))
    {
        TC_LOG_ERROR("scripts.spells", "SpellScriptBase::ValidateSpellInfo: Spell {} does not exist.", spellId);
        return false;
    }

    return true;
}

bool SpellScriptBase::ValidateSpellEffectImpl(uint32 spellId, SpellEffIndex effectIndex)
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);
    if (!spellInfo)
    {
        TC_LOG_ERROR("scripts.spells", "SpellScriptBase::ValidateSpellEffect: Spell {} does not exist.", spellId);
        return false;
    }

    if (spellInfo->GetEffects().size() <= effectIndex)
    {
        TC_LOG_ERROR("scripts.spells", "SpellScriptBase::ValidateSpellEffect: Spell {} does not have EFFECT_{}.", spellId, uint32(effectIndex));
        return false;
    }

    return true;
}

void SpellScriptBase::_Register()
{
    m_currentScriptState = SPELL_SCRIPT_STATE_REGISTRATION;
    Register();
    m_currentScriptState = SPELL_SCRIPT_STATE_NONE;
}

void SpellScriptBase::_Unload()
{
    m_currentScriptState = SPELL_SCRIPT_STATE_UNLOADING;
    Unload();
    m_currentScriptState = SPELL_SCRIPT_STATE_NONE;
}

void SpellScriptBase::_Init(std::string const& scriptname, uint32 spellId)
{
    m_currentScriptState = SPELL_SCRIPT_STATE_NONE;
    m_scriptName = scriptname;
    m_scriptSpellId = spellId;

#ifdef TRINITY_API_USE_DYNAMIC_LINKING
    // Acquire a strong reference to the binary code
    // to keep it loaded until all spells are destroyed.
    m_moduleReference = sScriptMgr->AcquireModuleReferenceOfScriptName(scriptname);
#endif // #ifndef TRINITY_API_USE_DYNAMIC_LINKING
}

std::string_view SpellScriptBase::GetScriptName() const
{
    return m_scriptName;
}

SpellScriptBase::EffectHook::EffectHook(uint8 effIndex)
{
    // effect index must be in range <0;2>, allow use of special effindexes
    ASSERT(effIndex == EFFECT_ALL || effIndex == EFFECT_FIRST_FOUND || effIndex < MAX_SPELL_EFFECTS);
    _effIndex = effIndex;
}

SpellScriptBase::EffectHook::EffectHook(EffectHook&& right) noexcept = default;
SpellScriptBase::EffectHook& SpellScriptBase::EffectHook::operator=(EffectHook&& right) noexcept = default;
SpellScriptBase::EffectHook::~EffectHook() = default;

uint32 SpellScriptBase::EffectHook::GetAffectedEffectsMask(SpellInfo const* spellInfo) const
{
    uint32 mask = 0;
    if (_effIndex == EFFECT_ALL || _effIndex == EFFECT_FIRST_FOUND)
    {
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if (_effIndex == EFFECT_FIRST_FOUND && mask)
                return mask;
            if (CheckEffect(spellInfo, i))
                mask |= 1 << i;
        }
    }
    else
    {
        if (CheckEffect(spellInfo, _effIndex))
            mask |= 1 << _effIndex;
    }
    return mask;
}

bool SpellScriptBase::EffectHook::IsEffectAffected(SpellInfo const* spellInfo, uint8 effIndex) const
{
    return (GetAffectedEffectsMask(spellInfo) & 1 << effIndex) != 0;
}

std::string SpellScriptBase::EffectHook::EffIndexToString() const
{
    if (_effIndex == EFFECT_ALL)
        return "EFFECT_ALL";
    if (_effIndex == EFFECT_FIRST_FOUND)
        return "EFFECT_FIRST_FOUND";
    if (_effIndex < MAX_SPELL_EFFECTS)
        return Trinity::StringFormat("EFFECT_{}", uint32(_effIndex));
    return "Invalid Value";
}

SpellScript::EffectBase::EffectBase(uint8 effIndex, uint16 effName)
    : EffectHook(effIndex), _effName(effName)
{
}

SpellScript::EffectBase::EffectBase(EffectBase&& right) noexcept = default;
SpellScript::EffectBase& SpellScript::EffectBase::operator=(EffectBase&& right) noexcept = default;
SpellScript::EffectBase::~EffectBase() = default;

std::string SpellScript::EffectBase::ToString() const
{
    switch (_effName)
    {
        case SPELL_EFFECT_ANY:
            return Trinity::StringFormat("Index: {}, Effect: SPELL_EFFECT_ANY", EffIndexToString());
        default:
            return Trinity::StringFormat("Index: {}, Effect: SPELL_EFFECT_{}", EffIndexToString(), _effName);
    }
}

bool SpellScript::EffectBase::CheckEffect(SpellInfo const* spellInfo, uint8 effIndex) const
{
    if (spellInfo->GetEffects().size() <= effIndex)
        return false;
    SpellEffectInfo const& spellEffectInfo = spellInfo->GetEffect(SpellEffIndex(effIndex));
    if (!spellEffectInfo.Effect && !_effName)
        return true;
    if (!spellEffectInfo.Effect)
        return false;
    return (_effName == SPELL_EFFECT_ANY) || (spellEffectInfo.Effect == _effName);
}

SpellScript::TargetHook::TargetHook(uint8 effectIndex, uint16 targetType, bool area, bool dest)
    : EffectHook(effectIndex), _targetType(targetType), _area(area), _dest(dest) { }

SpellScript::TargetHook::TargetHook(TargetHook&& right) noexcept = default;
SpellScript::TargetHook& SpellScript::TargetHook::operator=(TargetHook&& right) noexcept = default;
SpellScript::TargetHook::~TargetHook() = default;

std::string SpellScript::TargetHook::ToString() const
{
    return Trinity::StringFormat("Index: {} Target: {}", EffIndexToString(), _targetType);
}

bool SpellScript::TargetHook::CheckEffect(SpellInfo const* spellInfo, uint8 effIndex) const
{
    if (!_targetType)
        return false;

    if (spellInfo->GetEffects().size() <= effIndex)
        return false;

    SpellEffectInfo const& spellEffectInfo = spellInfo->GetEffect(SpellEffIndex(effIndex));
    if (spellEffectInfo.TargetA.GetTarget() != _targetType &&
        spellEffectInfo.TargetB.GetTarget() != _targetType)
        return false;

    SpellImplicitTargetInfo targetInfo(_targetType);
    switch (targetInfo.GetSelectionCategory())
    {
        case TARGET_SELECT_CATEGORY_CHANNEL: // SINGLE
            return !_area;
        case TARGET_SELECT_CATEGORY_NEARBY: // BOTH
            return true;
        case TARGET_SELECT_CATEGORY_CONE: // AREA
        case TARGET_SELECT_CATEGORY_LINE: // AREA
            return _area;
        case TARGET_SELECT_CATEGORY_AREA: // AREA
            if (targetInfo.GetObjectType() == TARGET_OBJECT_TYPE_UNIT_AND_DEST)
                return _area || _dest;
            return _area;
        case TARGET_SELECT_CATEGORY_DEFAULT:
            switch (targetInfo.GetObjectType())
            {
                case TARGET_OBJECT_TYPE_SRC: // EMPTY
                    return false;
                case TARGET_OBJECT_TYPE_DEST: // DEST
                    return _dest;
                default:
                    switch (targetInfo.GetReferenceType())
                    {
                        case TARGET_REFERENCE_TYPE_CASTER: // SINGLE
                            return !_area;
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

SpellScript::SpellScript(): m_spell(nullptr), m_hitPreventEffectMask(0), m_hitPreventDefaultEffectMask(0)
{
}

SpellScript::~SpellScript() = default;

bool SpellScript::_Validate(SpellInfo const* entry)
{
    for (EffectHandler& hook : OnEffectLaunch)
        if (!hook.GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectLaunch` of SpellScript won't be executed", entry->Id, hook.ToString(), m_scriptName);

    for (EffectHandler& hook : OnEffectLaunchTarget)
        if (!hook.GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectLaunchTarget` of SpellScript won't be executed", entry->Id, hook.ToString(), m_scriptName);

    for (EffectHandler& hook : OnEffectHit)
        if (!hook.GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectHit` of SpellScript won't be executed", entry->Id, hook.ToString(), m_scriptName);

    for (EffectHandler& hook : OnEffectHitTarget)
        if (!hook.GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectHitTarget` of SpellScript won't be executed", entry->Id, hook.ToString(), m_scriptName);

    for (EffectHandler& hook : OnEffectSuccessfulDispel)
        if (!hook.GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectSuccessfulDispel` of SpellScript won't be executed", entry->Id, hook.ToString(), m_scriptName);

    for (ObjectAreaTargetSelectHandler& hook : OnObjectAreaTargetSelect)
        if (!hook.GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnObjectAreaTargetSelect` of SpellScript won't be executed", entry->Id, hook.ToString(), m_scriptName);

    for (ObjectTargetSelectHandler& hook : OnObjectTargetSelect)
        if (!hook.GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnObjectTargetSelect` of SpellScript won't be executed", entry->Id, hook.ToString(), m_scriptName);

    for (DestinationTargetSelectHandler& hook : OnDestinationTargetSelect)
        if (!hook.GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnDestinationTargetSelect` of SpellScript won't be executed", entry->Id, hook.ToString(), m_scriptName);

    if (CalcDamage.size())
    {
        if (!entry->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE)
            && !entry->HasEffect(SPELL_EFFECT_POWER_DRAIN)
            && !entry->HasEffect(SPELL_EFFECT_HEALTH_LEECH)
            && !entry->HasEffect(SPELL_EFFECT_WEAPON_DAMAGE)
            && !entry->HasEffect(SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL)
            && !entry->HasEffect(SPELL_EFFECT_NORMALIZED_WEAPON_DMG)
            && !entry->HasEffect(SPELL_EFFECT_WEAPON_PERCENT_DAMAGE))
            TC_LOG_ERROR("scripts", "Spell `{}` script `{}` does not have a damage effect - handler bound to hook `CalcDamage` of SpellScript won't be executed", entry->Id, m_scriptName);
    }

    if (CalcHealing.size())
    {
        if (!entry->HasEffect(SPELL_EFFECT_HEAL)
            && !entry->HasEffect(SPELL_EFFECT_HEAL_PCT)
            && !entry->HasEffect(SPELL_EFFECT_HEAL_MECHANICAL)
            && !entry->HasEffect(SPELL_EFFECT_HEALTH_LEECH))
            TC_LOG_ERROR("scripts", "Spell `{}` script `{}` does not have a damage effect - handler bound to hook `CalcHealing` of SpellScript won't be executed", entry->Id, m_scriptName);
    }

    return SpellScriptBase::_Validate(entry);
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

bool SpellScript::IsAfterTargetSelectionPhase() const
{
    return IsInHitPhase()
        || IsInEffectHook()
        || m_currentScriptState == SPELL_SCRIPT_HOOK_ON_CAST
        || m_currentScriptState == SPELL_SCRIPT_HOOK_AFTER_CAST
        || m_currentScriptState == SPELL_SCRIPT_HOOK_CALC_CRIT_CHANCE
        || m_currentScriptState == SPELL_SCRIPT_HOOK_CALC_DAMAGE
        || m_currentScriptState == SPELL_SCRIPT_HOOK_CALC_HEALING;
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
    return (m_currentScriptState >= SPELL_SCRIPT_HOOK_EFFECT_LAUNCH && m_currentScriptState <= SPELL_SCRIPT_HOOK_EFFECT_HIT_TARGET)
        || m_currentScriptState == SPELL_SCRIPT_HOOK_EFFECT_SUCCESSFUL_DISPEL;
}

Unit* SpellScript::GetCaster() const
{
    return m_spell->GetCaster()->ToUnit();
}

GameObject* SpellScript::GetGObjCaster() const
{
    return m_spell->GetCaster()->ToGameObject();
}

Unit* SpellScript::GetOriginalCaster() const
{
    return m_spell->GetOriginalCaster();
}

SpellInfo const* SpellScript::GetSpellInfo() const
{
    return m_spell->GetSpellInfo();
}

SpellEffectInfo const& SpellScript::GetEffectInfo(SpellEffIndex effIndex) const
{
    return GetSpellInfo()->GetEffect(effIndex);
}

SpellValue const* SpellScript::GetSpellValue() const
{
    return m_spell->m_spellValue;
}

WorldLocation const* SpellScript::GetExplTargetDest() const
{
    if (m_spell->m_targets.HasDst())
        return m_spell->m_targets.GetDstPos();
    return nullptr;
}

void SpellScript::SetExplTargetDest(WorldLocation const& loc)
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

int64 SpellScript::GetUnitTargetCountForEffect(SpellEffIndex effect) const
{
    if (!IsAfterTargetSelectionPhase())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetUnitTargetCountForEffect was called, but function has no effect in current hook! (spell has not selected targets yet)",
            m_scriptName, m_scriptSpellId);
        return 0;
    }
    return m_spell->GetUnitTargetCountForEffect(effect);
}

int64 SpellScript::GetGameObjectTargetCountForEffect(SpellEffIndex effect) const
{
    if (!IsAfterTargetSelectionPhase())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetGameObjectTargetCountForEffect was called, but function has no effect in current hook! (spell has not selected targets yet)",
            m_scriptName, m_scriptSpellId);
        return 0;
    }
    return m_spell->GetGameObjectTargetCountForEffect(effect);
}

int64 SpellScript::GetItemTargetCountForEffect(SpellEffIndex effect) const
{
    if (!IsAfterTargetSelectionPhase())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetItemTargetCountForEffect was called, but function has no effect in current hook! (spell has not selected targets yet)",
            m_scriptName, m_scriptSpellId);
        return 0;
    }
    return m_spell->GetItemTargetCountForEffect(effect);
}

int64 SpellScript::GetCorpseTargetCountForEffect(SpellEffIndex effect) const
{
    if (!IsAfterTargetSelectionPhase())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetCorpseTargetCountForEffect was called, but function has no effect in current hook! (spell has not selected targets yet)",
            m_scriptName, m_scriptSpellId);
        return 0;
    }
    return m_spell->GetCorpseTargetCountForEffect(effect);
}

Unit* SpellScript::GetHitUnit() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetHitUnit was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return nullptr;
    }
    return m_spell->unitTarget;
}

Creature* SpellScript::GetHitCreature() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetHitCreature was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
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
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetHitPlayer was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
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
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetHitItem was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return nullptr;
    }
    return m_spell->itemTarget;
}

GameObject* SpellScript::GetHitGObj() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetHitGObj was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return nullptr;
    }
    return m_spell->gameObjTarget;
}

Corpse* SpellScript::GetHitCorpse() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetHitCorpse was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return nullptr;
    }
    return m_spell->m_corpseTarget;
}

WorldLocation* SpellScript::GetHitDest() const
{
    if (!IsInEffectHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetHitDest was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return nullptr;
    }
    return m_spell->destTarget;
}

int32 SpellScript::GetHitDamage() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetHitDamage was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return 0;
    }
    return m_spell->m_damage;
}

void SpellScript::SetHitDamage(int32 damage)
{
    if (!IsInModifiableHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::SetHitDamage was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return;
    }
    m_spell->m_damage = damage;
}

int32 SpellScript::GetHitHeal() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetHitHeal was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return 0;
    }
    return m_spell->m_healing;
}

void SpellScript::SetHitHeal(int32 heal)
{
    if (!IsInModifiableHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::SetHitHeal was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return;
    }
    m_spell->m_healing = heal;
}

bool SpellScript::IsHitCrit() const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::IsHitCrit was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return false;
    }
    if (Unit* hitUnit = GetHitUnit())
    {
        auto itr = std::find_if(m_spell->m_UniqueTargetInfo.begin(), m_spell->m_UniqueTargetInfo.end(), [hitUnit](Spell::TargetInfo const& targetInfo)
        {
            return targetInfo.TargetGUID == hitUnit->GetGUID();
        });
        ASSERT(itr != m_spell->m_UniqueTargetInfo.end());
        return itr->IsCrit;
    }
    return false;
}

Aura* SpellScript::GetHitAura(bool dynObjAura /*= false*/) const
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetHitAura was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return nullptr;
    }

    Aura* aura = m_spell->_spellAura;
    if (dynObjAura)
        aura = m_spell->_dynObjAura;

    if (!aura || aura->IsRemoved())
        return nullptr;

    return aura;
}

void SpellScript::PreventHitAura()
{
    if (!IsInTargetHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::PreventHitAura was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return;
    }
    if (UnitAura* aura = m_spell->_spellAura)
        aura->Remove();
    if (DynObjAura* aura = m_spell->_dynObjAura)
        aura->Remove();
}

void SpellScript::PreventHitEffect(SpellEffIndex effIndex)
{
    if (!IsInHitPhase() && !IsInEffectHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::PreventHitEffect was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return;
    }
    m_hitPreventEffectMask |= 1 << effIndex;
    PreventHitDefaultEffect(effIndex);
}

void SpellScript::PreventHitDefaultEffect(SpellEffIndex effIndex)
{
    if (!IsInHitPhase() && !IsInEffectHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::PreventHitDefaultEffect was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return;
    }
    m_hitPreventDefaultEffectMask |= 1 << effIndex;
}

SpellEffectInfo const& SpellScript::GetEffectInfo() const
{
    ASSERT(IsInEffectHook(), "Script: `" STRING_VIEW_FMT "` Spell: `%u`: function SpellScript::GetEffectInfo was called, but function has no effect in current hook!", STRING_VIEW_FMT_ARG(m_scriptName), m_scriptSpellId);

    return *m_spell->effectInfo;
}

int32 SpellScript::GetEffectValue() const
{
    if (!IsInEffectHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetEffectValue was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return 0;
    }

    return m_spell->damage;
}

void SpellScript::SetEffectValue(int32 value)
{
    if (!IsInEffectHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::SetEffectValue was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return;
    }

    m_spell->damage = value;
}

float SpellScript::GetEffectVariance() const
{
    if (!IsInEffectHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::GetEffectVariance was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return 0.0f;
    }

    return m_spell->variance;
}

void SpellScript::SetEffectVariance(float variance)
{
    if (!IsInEffectHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::SetEffectVariance was called, but function has no effect in current hook!", m_scriptName, m_scriptSpellId);
        return;
    }

    m_spell->variance = variance;
}

Item* SpellScript::GetCastItem() const
{
    return m_spell->m_CastItem;
}

void SpellScript::CreateItem(uint32 itemId, ItemContext context)
{
    m_spell->DoCreateItem(itemId, context);
}

SpellInfo const* SpellScript::GetTriggeringSpell() const
{
    return m_spell->m_triggeredByAuraSpell;
}

void SpellScript::FinishCast(SpellCastResult result, int32* param1 /*= nullptr*/, int32* param2 /*= nullptr*/)
{
    m_spell->SendCastResult(result, param1, param2);
    m_spell->finish(result);
}

void SpellScript::SetCustomCastResultMessage(SpellCustomErrors result)
{
    if (!IsInCheckCastHook())
    {
        TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}`: function SpellScript::SetCustomCastResultMessage was called while spell not in check cast phase!", m_scriptName, m_scriptSpellId);
        return;
    }

    m_spell->m_customError = result;
}

Difficulty SpellScript::GetCastDifficulty() const
{
    return m_spell->GetCastDifficulty();
}

bool AuraScript::_Validate(SpellInfo const* entry)
{
    for (auto itr = DoCheckAreaTarget.begin(); itr != DoCheckAreaTarget.end(); ++itr)
        if (!entry->HasAreaAuraEffect() && !entry->HasEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA) && !entry->HasEffect(SPELL_EFFECT_APPLY_AURA))
            TC_LOG_ERROR("scripts", "Spell `{}` of script `{}` does not have apply aura effect - handler bound to hook `DoCheckAreaTarget` of AuraScript won't be executed", entry->Id, m_scriptName);

    for (auto itr = OnDispel.begin(); itr != OnDispel.end(); ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `{}` of script `{}` does not have apply aura effect - handler bound to hook `OnDispel` of AuraScript won't be executed", entry->Id, m_scriptName);

    for (auto itr = AfterDispel.begin(); itr != AfterDispel.end(); ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `{}` of script `{}` does not have apply aura effect - handler bound to hook `AfterDispel` of AuraScript won't be executed", entry->Id, m_scriptName);

    for (auto itr = OnEffectApply.begin(); itr != OnEffectApply.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectApply` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = OnEffectRemove.begin(); itr != OnEffectRemove.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectRemove` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = AfterEffectApply.begin(); itr != AfterEffectApply.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `AfterEffectApply` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = AfterEffectRemove.begin(); itr != AfterEffectRemove.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `AfterEffectRemove` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = OnEffectPeriodic.begin(); itr != OnEffectPeriodic.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectPeriodic` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = OnEffectUpdatePeriodic.begin(); itr != OnEffectUpdatePeriodic.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectUpdatePeriodic` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = DoEffectCalcAmount.begin(); itr != DoEffectCalcAmount.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `DoEffectCalcAmount` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = DoEffectCalcPeriodic.begin(); itr != DoEffectCalcPeriodic.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `DoEffectCalcPeriodic` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = DoEffectCalcSpellMod.begin(); itr != DoEffectCalcSpellMod.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `DoEffectCalcSpellMod` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = DoEffectCalcCritChance.begin(); itr != DoEffectCalcCritChance.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `DoEffectCalcCritChance` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (EffectCalcDamageAndHealingHandler const& hook : DoEffectCalcDamageAndHealing)
        if (!hook.GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `DoEffectCalcDamageAndHealing` of AuraScript won't be executed", entry->Id, hook.ToString(), m_scriptName);

    for (auto itr = OnEffectAbsorb.begin(); itr != OnEffectAbsorb.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectAbsorb` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = AfterEffectAbsorb.begin(); itr != AfterEffectAbsorb.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `AfterEffectAbsorb` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = OnEffectManaShield.begin(); itr != OnEffectManaShield.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectManaShield` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = AfterEffectManaShield.begin(); itr != AfterEffectManaShield.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `AfterEffectManaShield` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = OnEffectSplit.begin(); itr != OnEffectSplit.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectSplit` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = DoCheckProc.begin(); itr != DoCheckProc.end(); ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `{}` of script `{}` does not have apply aura effect - handler bound to hook `DoCheckProc` of AuraScript won't be executed", entry->Id, m_scriptName);

    for (auto itr = DoCheckEffectProc.begin(); itr != DoCheckEffectProc.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `DoCheckEffectProc` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = DoPrepareProc.begin(); itr != DoPrepareProc.end(); ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `{}` of script `{}` does not have apply aura effect - handler bound to hook `DoPrepareProc` of AuraScript won't be executed", entry->Id, m_scriptName);

    for (auto itr = OnProc.begin(); itr != OnProc.end(); ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `{}` of script `{}` does not have apply aura effect - handler bound to hook `OnProc` of AuraScript won't be executed", entry->Id, m_scriptName);

    for (auto itr = AfterProc.begin(); itr != AfterProc.end(); ++itr)
        if (!entry->HasEffect(SPELL_EFFECT_APPLY_AURA) && !entry->HasAreaAuraEffect())
            TC_LOG_ERROR("scripts", "Spell `{}` of script `{}` does not have apply aura effect - handler bound to hook `AfterProc` of AuraScript won't be executed", entry->Id, m_scriptName);

    for (auto itr = OnEffectProc.begin(); itr != OnEffectProc.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `OnEffectProc` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    for (auto itr = AfterEffectProc.begin(); itr != AfterEffectProc.end(); ++itr)
        if (!itr->GetAffectedEffectsMask(entry))
            TC_LOG_ERROR("scripts", "Spell `{}` Effect `{}` of script `{}` did not match dbc effect data - handler bound to hook `AfterEffectProc` of AuraScript won't be executed", entry->Id, itr->ToString(), m_scriptName);

    return SpellScriptBase::_Validate(entry);
}

AuraScript::EffectBase::EffectBase(uint8 effIndex, uint16 auraType)
    : EffectHook(effIndex), _auraType(auraType) { }

AuraScript::EffectBase::EffectBase(EffectBase&& right) noexcept = default;
AuraScript::EffectBase& AuraScript::EffectBase::operator=(EffectBase&& right) noexcept = default;
AuraScript::EffectBase::~EffectBase() = default;

bool AuraScript::EffectBase::CheckEffect(SpellInfo const* spellInfo, uint8 effIndex) const
{
    if (spellInfo->GetEffects().size() <= effIndex)
        return false;
    SpellEffectInfo const& spellEffectInfo = spellInfo->GetEffect(SpellEffIndex(effIndex));
    if (!spellEffectInfo.ApplyAuraName && !_auraType)
        return true;
    if (!spellEffectInfo.ApplyAuraName)
        return false;
    return (_auraType == SPELL_AURA_ANY) || (spellEffectInfo.ApplyAuraName == _auraType);
}

std::string AuraScript::EffectBase::ToString() const
{
    switch (_auraType)
    {
        case SPELL_AURA_ANY:
            return Trinity::StringFormat("Index: {}, AuraName: SPELL_AURA_ANY", EffIndexToString());
        default:
            return Trinity::StringFormat("Index: {}, AuraName: SPELL_AURA_{}", EffIndexToString(), _auraType);
    }
}

AuraScript::AuraScript(): SpellScriptBase(), m_aura(nullptr), m_auraApplication(nullptr), m_defaultActionPrevented(false)
{
}

AuraScript::~AuraScript() = default;

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
            ABORT_MSG("AuraScript::_IsDefaultActionPrevented is called in a wrong place");
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
            TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}` AuraScript::PreventDefaultAction called in a hook in which the call won't have effect!", m_scriptName, m_scriptSpellId);
            break;
    }
}

SpellInfo const* AuraScript::GetSpellInfo() const
{
    return m_aura->GetSpellInfo();
}

SpellEffectInfo const& AuraScript::GetEffectInfo(SpellEffIndex effIndex) const
{
    return m_aura->GetSpellInfo()->GetEffect(effIndex);
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
    if (WorldObject* caster = m_aura->GetCaster())
        return caster->ToUnit();
    return nullptr;
}

GameObject* AuraScript::GetGObjCaster() const
{
    if (WorldObject* caster = m_aura->GetCaster())
        return caster->ToGameObject();
    return nullptr;
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
        case AURA_SCRIPT_HOOK_EFFECT_CALC_CRIT_CHANCE:
        case AURA_SCRIPT_HOOK_EFFECT_CALC_DAMAGE_AND_HEALING:
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
            TC_LOG_ERROR("scripts", "Script: `{}` Spell: `{}` AuraScript::GetTarget called in a hook in which the call won't have effect!", m_scriptName, m_scriptSpellId);
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
