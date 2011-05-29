/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include <string>
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellScript.h"

bool _SpellScript::_Validate(SpellEntry const* entry)
{
    if (!Validate(entry))
    {
        sLog->outError("TSCR: Spell `%u` did not pass Validate() function of script `%s` - script will be not added to the spell", entry->Id, m_scriptName->c_str());
        return false;
    }
    return true;
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
}

_SpellScript::EffectHook::EffectHook(uint8 _effIndex)
{
    // effect index must be in range <0;2>, allow use of special effindexes
    ASSERT(_effIndex == EFFECT_ALL || _effIndex == EFFECT_FIRST_FOUND || _effIndex < MAX_SPELL_EFFECTS);
    effIndex = _effIndex;
}

uint8 _SpellScript::EffectHook::GetAffectedEffectsMask(SpellEntry const* spellEntry)
{
    uint8 mask = 0;
    if ((effIndex == EFFECT_ALL) || (effIndex == EFFECT_FIRST_FOUND))
    {
        for(uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if ((effIndex == EFFECT_FIRST_FOUND) && mask)
                return mask;
            if (CheckEffect(spellEntry, i))
                mask |= (uint8)1<<i;
        }
    }
    else
    {
        if (CheckEffect(spellEntry, effIndex))
            mask |= (uint8)1<<effIndex;
    }
    return mask;
}

bool _SpellScript::EffectHook::IsEffectAffected(SpellEntry const* spellEntry, uint8 effIndex)
{
    return GetAffectedEffectsMask(spellEntry) & 1<<effIndex;
}

std::string _SpellScript::EffectHook::EffIndexToString()
{
    switch(effIndex)
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

bool _SpellScript::EffectNameCheck::Check(SpellEntry const* spellEntry, uint8 effIndex)
{
    if (!spellEntry->Effect[effIndex] && !effName)
        return true;
    if (!spellEntry->Effect[effIndex])
        return false;
    return (effName == SPELL_EFFECT_ANY) || (spellEntry->Effect[effIndex] == effName);
}

std::string _SpellScript::EffectNameCheck::ToString()
{
    switch(effName)
    {
        case SPELL_EFFECT_ANY:
            return "SPELL_EFFECT_ANY";
        default:
            char num[10];
            sprintf (num, "%u", effName);
            return num;
    }
}

bool _SpellScript::EffectAuraNameCheck::Check(SpellEntry const* spellEntry, uint8 effIndex)
{
    if (!spellEntry->EffectApplyAuraName[effIndex] && !effAurName)
        return true;
    if (!spellEntry->EffectApplyAuraName[effIndex])
        return false;
    return (effAurName == SPELL_EFFECT_ANY) || (spellEntry->EffectApplyAuraName[effIndex] == effAurName);
}

std::string _SpellScript::EffectAuraNameCheck::ToString()
{
    switch(effAurName)
    {
        case SPELL_AURA_ANY:
            return "SPELL_AURA_ANY";
        default:
            char num[10];
            sprintf (num, "%u", effAurName);
            return num;
    }
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

std::string SpellScript::EffectHandler::ToString()
{
    return "Index: " + EffIndexToString() + " Name: " +_SpellScript::EffectNameCheck::ToString();
}

bool SpellScript::EffectHandler::CheckEffect(SpellEntry const* spellEntry, uint8 effIndex)
{
    return _SpellScript::EffectNameCheck::Check(spellEntry, effIndex);
}

void SpellScript::EffectHandler::Call(SpellScript* spellScript, SpellEffIndex effIndex)
{
    (spellScript->*pEffectHandlerScript)(effIndex);
}

SpellScript::HitHandler::HitHandler(SpellHitFnType _pHitHandlerScript)
{
    pHitHandlerScript = _pHitHandlerScript;
}

void SpellScript::HitHandler::Call(SpellScript* spellScript)
{
    (spellScript->*pHitHandlerScript)();
}

SpellScript::UnitTargetHandler::UnitTargetHandler(SpellUnitTargetFnType _pUnitTargetHandlerScript, uint8 _effIndex, uint16 _targetType)
    : _SpellScript::EffectHook(_effIndex), targetType(_targetType)
{
    pUnitTargetHandlerScript = _pUnitTargetHandlerScript;
}

std::string SpellScript::UnitTargetHandler::ToString()
{
    std::ostringstream oss;
    oss << "Index: " << EffIndexToString() << " Target: " << targetType;
    return oss.str();
}

bool SpellScript::UnitTargetHandler::CheckEffect(SpellEntry const* spellEntry, uint8 effIndex)
{
    if (!targetType)
        return false;
    return (effIndex == EFFECT_ALL) || (spellEntry->EffectImplicitTargetA[effIndex] == targetType || spellEntry->EffectImplicitTargetB[effIndex] == targetType);
}

void SpellScript::UnitTargetHandler::Call(SpellScript* spellScript, std::list<Unit*>& unitTargets)
{
    (spellScript->*pUnitTargetHandlerScript)(unitTargets);
}

bool SpellScript::_Validate(SpellEntry const * entry)
{
    for (std::list<EffectHandler>::iterator itr = OnEffect.begin(); itr != OnEffect.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffect` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<UnitTargetHandler>::iterator itr = OnUnitTargetSelect.begin(); itr != OnUnitTargetSelect.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnUnitTargetSelect` of SpellScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

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

Unit* SpellScript::GetCaster()
{
     return m_spell->GetCaster();
}

Unit* SpellScript::GetOriginalCaster()
{
     return m_spell->GetOriginalCaster();
}

SpellEntry const* SpellScript::GetSpellInfo()
{
    return m_spell->GetSpellInfo();
}

WorldLocation* SpellScript::GetTargetDest()
{
    if (m_spell->m_targets.HasDst())
        return &m_spell->m_targets.m_dstPos;
    return NULL;
}

Unit* SpellScript::GetTargetUnit()
{
    return m_spell->m_targets.getUnitTarget();
}

GameObject* SpellScript::GetTargetGObj()
{
    return m_spell->m_targets.getGOTarget();
}

Item* SpellScript::GetTargetItem()
{
    return m_spell->m_targets.getItemTarget();
}

Unit* SpellScript::GetHitUnit()
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::GetHitUnit was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return NULL;
    }
    return m_spell->unitTarget;
}

Creature* SpellScript::GetHitCreature()
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::GetHitCreature was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return NULL;
    }
    if (m_spell->unitTarget)
        return m_spell->unitTarget->ToCreature();
    else
        return NULL;
}

Player* SpellScript::GetHitPlayer()
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::GetHitPlayer was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return NULL;
    }
    if (m_spell->unitTarget)
        return m_spell->unitTarget->ToPlayer();
    else
        return NULL;
}

Item* SpellScript::GetHitItem()
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::GetHitItem was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return NULL;
    }
    return m_spell->itemTarget;
}

GameObject* SpellScript::GetHitGObj()
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::GetHitGObj was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return NULL;
    }
    return m_spell->gameObjTarget;
}

int32 SpellScript::GetHitDamage()
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::GetHitDamage was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return 0;
    }
    return m_spell->m_damage;
}

void SpellScript::SetHitDamage(int32 damage)
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::SetHitDamage was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }
    m_spell->m_damage = damage;
}

int32 SpellScript::GetHitHeal()
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::GetHitHeal was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return 0;
    }
    return m_spell->m_healing;
}

void SpellScript::SetHitHeal(int32 heal)
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::SetHitHeal was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }
    m_spell->m_healing = heal;
}

Aura* SpellScript::GetHitAura()
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::GetHitAura was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return NULL;
    }
    if (!m_spell->m_spellAura)
        return NULL;
    if (m_spell->m_spellAura->IsRemoved())
        return NULL;
    return m_spell->m_spellAura;
}

void SpellScript::PreventHitAura()
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::PreventHitAura was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }
    if (m_spell->m_spellAura)
        m_spell->m_spellAura->Remove();
}

void SpellScript::PreventHitEffect(SpellEffIndex effIndex)
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::PreventHitEffect was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }
    m_hitPreventEffectMask |= 1 << effIndex;
    PreventHitDefaultEffect(effIndex);
}

void SpellScript::PreventHitDefaultEffect(SpellEffIndex effIndex)
{
    if (!IsInHitPhase())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::PreventHitDefaultEffect was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }
    m_hitPreventDefaultEffectMask |= 1 << effIndex;
}

int32 SpellScript::GetEffectValue()
{
    if (!IsInEffectHook())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::PreventHitDefaultEffect was called while spell not in hit phase!", m_scriptName->c_str(), m_scriptSpellId);
        return 0;
    }
    return m_spell->damage;
}

Item* SpellScript::GetCastItem()
{
    return m_spell->m_CastItem;
}

void SpellScript::CreateItem(uint32 effIndex, uint32 itemId)
{
    m_spell->DoCreateItem(effIndex, itemId);
}

void SpellScript::FinishCast(SpellCastResult result)
{
    m_spell->SendCastResult(result);
    m_spell->finish(result == SPELL_CAST_OK);
}

void SpellScript::SetCustomCastResultMessage(SpellCustomErrors result)
{
    if (!IsInCheckCastHook())
    {
        sLog->outError("TSCR: Script: `%s` Spell: `%u`: function SpellScript::SetCustomCastResultMessage was called while spell not in check cast phase!", m_scriptName->c_str(), m_scriptSpellId);
        return;
    }

    m_spell->m_customError = result;
}

bool AuraScript::_Validate(SpellEntry const * entry)
{
    for (std::list<EffectApplyHandler>::iterator itr = OnEffectApply.begin(); itr != OnEffectApply.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectApply` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<EffectApplyHandler>::iterator itr = OnEffectRemove.begin(); itr != OnEffectRemove.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectRemove` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<EffectApplyHandler>::iterator itr = AfterEffectApply.begin(); itr != AfterEffectApply.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectApply` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<EffectApplyHandler>::iterator itr = AfterEffectRemove.begin(); itr != AfterEffectRemove.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectRemove` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<EffectPeriodicHandler>::iterator itr = OnEffectPeriodic.begin(); itr != OnEffectPeriodic.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectPeriodic` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<EffectUpdatePeriodicHandler>::iterator itr = OnEffectUpdatePeriodic.begin(); itr != OnEffectUpdatePeriodic.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectUpdatePeriodic` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<EffectCalcAmountHandler>::iterator itr = DoEffectCalcAmount.begin(); itr != DoEffectCalcAmount.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `DoEffectCalcAmount` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<EffectCalcPeriodicHandler>::iterator itr = DoEffectCalcPeriodic.begin(); itr != DoEffectCalcPeriodic.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `DoEffectCalcPeriodic` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<EffectCalcSpellModHandler>::iterator itr = DoEffectCalcSpellMod.begin(); itr != DoEffectCalcSpellMod.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `DoEffectCalcSpellMod` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<EffectAbsorbHandler>::iterator itr = OnEffectAbsorb.begin(); itr != OnEffectAbsorb.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectAbsorb` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<EffectAbsorbHandler>::iterator itr = AfterEffectAbsorb.begin(); itr != AfterEffectAbsorb.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectAbsorb` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<EffectManaShieldHandler>::iterator itr = OnEffectManaShield.begin(); itr != OnEffectManaShield.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `OnEffectManaShield` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    for (std::list<EffectManaShieldHandler>::iterator itr = AfterEffectManaShield.begin(); itr != AfterEffectManaShield.end();  ++itr)
        if (!(*itr).GetAffectedEffectsMask(entry))
            sLog->outError("TSCR: Spell `%u` Effect `%s` of script `%s` did not match dbc effect data - handler bound to hook `AfterEffectManaShield` of AuraScript won't be executed", entry->Id, (*itr).ToString().c_str(), m_scriptName->c_str());

    return _SpellScript::_Validate(entry);
}

AuraScript::EffectBase::EffectBase(uint8 _effIndex, uint16 _effName)
    : _SpellScript::EffectAuraNameCheck(_effName), _SpellScript::EffectHook(_effIndex)
{
}

bool AuraScript::EffectBase::CheckEffect(SpellEntry const* spellEntry, uint8 effIndex)
{
    return _SpellScript::EffectAuraNameCheck::Check(spellEntry, effIndex);
}

std::string AuraScript::EffectBase::ToString()
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

AuraScript::EffectApplyHandler::EffectApplyHandler(AuraEffectApplicationModeFnType _pEffectHandlerScript, uint8 _effIndex, uint16 _effName, AuraEffectHandleModes _mode)
    : AuraScript::EffectBase(_effIndex, _effName)
{
    pEffectHandlerScript = _pEffectHandlerScript;
    mode = _mode;
}

void AuraScript::EffectApplyHandler::Call(AuraScript* auraScript, AuraEffect const * _aurEff, AuraEffectHandleModes _mode)
{
    if (_mode & mode)
        (auraScript->*pEffectHandlerScript)(_aurEff, _mode);
}

AuraScript::EffectAbsorbHandler::EffectAbsorbHandler(AuraEffectAbsorbFnType _pEffectHandlerScript, uint8 _effIndex)
    : AuraScript::EffectBase(_effIndex, SPELL_AURA_SCHOOL_ABSORB)
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

bool AuraScript::_Load(Aura* aura)
{
    m_aura = aura;
    _PrepareScriptCall((AuraScriptHookType)SPELL_SCRIPT_STATE_LOADING, NULL);
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
            m_defaultActionPrevented = true;
            break;
        default:
            sLog->outError("TSCR: Script: `%s` Spell: `%u` AuraScript::PreventDefaultAction called in a hook in which the call won't have effect!", m_scriptName->c_str(), m_scriptSpellId);
            break;
    }
}

SpellEntry const* AuraScript::GetSpellProto() const
{
    return m_aura->GetSpellProto();
}

uint32 AuraScript::GetId() const
{
    return m_aura->GetId();
}

uint64 const& AuraScript::GetCasterGUID() const
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

void AuraScript::Remove(uint32 removeMode)
{
    m_aura->Remove((AuraRemoveMode)removeMode);
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

bool AuraScript::DropCharge()
{
    return m_aura->DropCharge();
}

uint8 AuraScript::GetStackAmount() const
{
    return m_aura->GetStackAmount();
}

void AuraScript::SetStackAmount(uint8 num)
{
    m_aura->SetStackAmount(num);
}

void AuraScript::ModStackAmount(int32 num, AuraRemoveMode removeMode)
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
            return m_auraApplication->GetTarget();
        default:
            sLog->outError("TSCR: Script: `%s` Spell: `%u` AuraScript::GetTarget called in a hook in which the call won't have effect!", m_scriptName->c_str(), m_scriptSpellId);
    }

    return NULL;
}

AuraApplication const* AuraScript::GetTargetApplication() const
{
    return m_auraApplication;
}

