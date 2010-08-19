/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <string>
#include "SpellScript.h"
#include "Spell.h"
#include "SpellAuras.h"

bool _SpellScript::_Validate(SpellEntry const * entry, const char * scriptname)
{
    if (!Validate(entry))
    {
        sLog.outError("TSCR: Spell `%u` did not pass Validate() function of script `%s` - script will be not added to the spell", entry->Id, scriptname);
        return false;
    }
    return true;
}

_SpellScript::EffectHook::EffectHook(uint8 _effIndex)
{
    // effect index must be in range <0;2>, allow use of special effindexes
    ASSERT(_effIndex == EFFECT_ALL || _effIndex == EFFECT_FIRST_FOUND || _effIndex < MAX_SPELL_EFFECTS);
    effIndex = _effIndex;
}

uint8 _SpellScript::EffectHook::GetAffectedEffectsMask(SpellEntry const * spellEntry)
{
    uint8 mask = 0;
    if ((effIndex == EFFECT_ALL) || (effIndex == EFFECT_FIRST_FOUND))
    {
        for(uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        {
            if ((effIndex == EFFECT_FIRST_FOUND) && mask)
                return mask;
            if (CheckEffect(spellEntry, effIndex))
                mask |= (uint8)1<<effIndex;
        }
    }
    else
    {
        if (CheckEffect(spellEntry, effIndex))
            mask |= (uint8)1<<effIndex;
    }
    return mask;
}

bool _SpellScript::EffectHook::IsEffectAffected(SpellEntry const * spellEntry, uint8 effIndex)
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

bool _SpellScript::EffectNameCheck::Check(SpellEntry const * spellEntry, uint8 effIndex)
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
            sprintf (num,"%u",effName);
            return num;
    }
}

bool _SpellScript::EffectAuraNameCheck::Check(SpellEntry const * spellEntry, uint8 effIndex)
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
            sprintf (num,"%u",effAurName);
            return num;
    }
}

SpellScript::EffectHandler::EffectHandler(EffectHandlerFnType _pEffectHandlerScript,uint8 _effIndex, uint16 _effName)
    : _SpellScript::EffectNameCheck(_effName), _SpellScript::EffectHook(_effIndex)
{
    pEffectHandlerScript = _pEffectHandlerScript;
}

std::string SpellScript::EffectHandler::ToString()
{
    return "Index: " + EffIndexToString() + " Name: " +_SpellScript::EffectNameCheck::ToString();
}

bool SpellScript::EffectHandler::CheckEffect(SpellEntry const * spellEntry, uint8 effIndex)
{
    return _SpellScript::EffectNameCheck::Check(spellEntry, effIndex);
}

void SpellScript::EffectHandler::Call(SpellScript * spellScript, SpellEffIndex effIndex)
{
    (spellScript->*pEffectHandlerScript)(effIndex);
}

bool SpellScript::_Validate(SpellEntry const * entry, const char * scriptname)
{
    for (std::list<EffectHandler>::iterator itr = EffectHandlers.begin(); itr != EffectHandlers.end();  ++itr)
    {
        if (!(*itr).GetAffectedEffectsMask(entry))
        {
            sLog.outError("TSCR: Spell `%u` Effect `%s` of script`%s` did not match dbc effect data - bound handler won't be executed", entry->Id, (*itr).ToString().c_str(), scriptname);
        }
    }
    return _SpellScript::_Validate(entry, scriptname);
}

bool SpellScript::_Load(Spell * spell)
{
    m_spell = spell;
    return Load();
}

void SpellScript::_InitHit()
{
    m_hitPreventEffectMask = 0;
    m_hitPreventDefaultEffectMask = 0;
}

Unit * SpellScript::GetCaster()
{
     return m_spell->GetCaster();
}

Unit * SpellScript::GetOriginalCaster()
{
     return m_spell->GetOriginalCaster();
}

SpellEntry const * SpellScript::GetSpellInfo()
{
    return m_spell->GetSpellInfo();
}

WorldLocation * SpellScript::GetDest()
{
    if (m_spell->m_targets.HasDst())
        return &m_spell->m_targets.m_dstPos;
    return NULL;
}

Unit * SpellScript::GetHitUnit()
{
    return m_spell->unitTarget;
}

Creature * SpellScript::GetHitCreature()
{
    if (m_spell->unitTarget)
        return m_spell->unitTarget->ToCreature();
    else
        return NULL;
}

Player * SpellScript::GetHitPlayer()
{
    if (m_spell->unitTarget)
        return m_spell->unitTarget->ToPlayer();
    else
        return NULL;
}

Item * SpellScript::GetHitItem()
{
    return m_spell->itemTarget;
}

GameObject * SpellScript::GetHitGObj()
{
    return m_spell->gameObjTarget;
}

int32 SpellScript::GetHitDamage()
{
    return m_spell->m_damage;
}

void SpellScript::SetHitDamage(int32 damage)
{
    m_spell->m_damage = damage;
}

int32 SpellScript::GetHitHeal()
{
    return m_spell->m_healing;
}

void SpellScript::SetHitHeal(int32 heal)
{
    m_spell->m_healing = heal;
}

Aura* SpellScript::GetHitAura()
{
    if (!m_spell->m_spellAura)
        return NULL;
    if (m_spell->m_spellAura->IsRemoved())
        return NULL;
    return m_spell->m_spellAura;
}

void SpellScript::PreventHitAura()
{
    if (m_spell->m_spellAura)
        m_spell->m_spellAura->Remove();
}

void SpellScript::PreventHitEffect(SpellEffIndex effIndex)
{
    m_hitPreventEffectMask |= 1 << effIndex;
    PreventHitDefaultEffect(effIndex);
}

void SpellScript::PreventHitDefaultEffect(SpellEffIndex effIndex)
{
    m_hitPreventDefaultEffectMask |= 1 << effIndex;
}

int32 SpellScript::GetEffectValue()
{
    return m_spell->damage;
}

Item * SpellScript::GetCastItem()
{
    return m_spell->m_CastItem;
}

void SpellScript::CreateItem(uint32 effIndex, uint32 itemId) 
{
    m_spell->DoCreateItem(effIndex, itemId);
}
