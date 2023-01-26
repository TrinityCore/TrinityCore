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

#include "UnitAICommon.h"
#include "Map.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Unit.h"

DefaultTargetSelector::DefaultTargetSelector(Unit const* unit, float dist, bool playerOnly, bool withTank, int32 aura)
    : _me(unit), _dist(dist), _playerOnly(playerOnly), _exception(!withTank ? unit->GetThreatManager().GetLastVictim() : nullptr), _aura(aura)
{
}

bool DefaultTargetSelector::operator()(Unit const* target) const
{
    if (!_me)
        return false;

    if (!target)
        return false;

    if (_exception && target == _exception)
        return false;

    if (_playerOnly && (target->GetTypeId() != TYPEID_PLAYER))
        return false;

    if (_dist > 0.0f && !_me->IsWithinCombatRange(target, _dist))
        return false;

    if (_dist < 0.0f && _me->IsWithinCombatRange(target, -_dist))
        return false;

    if (_aura)
    {
        if (_aura > 0)
        {
            if (!target->HasAura(_aura))
                return false;
        }
        else
        {
            if (target->HasAura(-_aura))
                return false;
        }
    }

    return true;
}

SpellTargetSelector::SpellTargetSelector(Unit* caster, uint32 spellId) :
    _caster(caster), _spellInfo(sSpellMgr->GetSpellInfo(spellId, caster->GetMap()->GetDifficultyID()))
{
    ASSERT(_spellInfo);
}

bool SpellTargetSelector::operator()(Unit const* target) const
{
    if (!target)
        return false;

    if (_spellInfo->CheckTarget(_caster, target) != SPELL_CAST_OK)
        return false;

    // copypasta from Spell::CheckRange
    float minRange = 0.0f;
    float maxRange = 0.0f;
    float rangeMod = 0.0f;
    if (_spellInfo->RangeEntry)
    {
        if (_spellInfo->RangeEntry->Flags & SPELL_RANGE_MELEE)
        {
            rangeMod = _caster->GetCombatReach() + 4.0f / 3.0f;
            rangeMod += target->GetCombatReach();

            rangeMod = std::max(rangeMod, NOMINAL_MELEE_RANGE);
        }
        else
        {
            float meleeRange = 0.0f;
            if (_spellInfo->RangeEntry->Flags & SPELL_RANGE_RANGED)
            {
                meleeRange = _caster->GetCombatReach() + 4.0f / 3.0f;
                meleeRange += target->GetCombatReach();

                meleeRange = std::max(meleeRange, NOMINAL_MELEE_RANGE);
            }

            minRange = _caster->GetSpellMinRangeForTarget(target, _spellInfo) + meleeRange;
            maxRange = _caster->GetSpellMaxRangeForTarget(target, _spellInfo);

            rangeMod = _caster->GetCombatReach();
            rangeMod += target->GetCombatReach();

            if (minRange > 0.0f && !(_spellInfo->RangeEntry->Flags & SPELL_RANGE_RANGED))
                minRange += rangeMod;
        }

        if (_caster->isMoving() && target->isMoving() && !_caster->IsWalking() && !target->IsWalking() &&
            (_spellInfo->RangeEntry->Flags & SPELL_RANGE_MELEE || target->GetTypeId() == TYPEID_PLAYER))
            rangeMod += 8.0f / 3.0f;
    }

    maxRange += rangeMod;

    minRange *= minRange;
    maxRange *= maxRange;

    if (target != _caster)
    {
        if (_caster->GetExactDistSq(target) > maxRange)
            return false;

        if (minRange > 0.0f && _caster->GetExactDistSq(target) < minRange)
            return false;
    }

    return true;
}

bool NonTankTargetSelector::operator()(Unit const* target) const
{
    if (!target)
        return false;

    if (_playerOnly && target->GetTypeId() != TYPEID_PLAYER)
        return false;

    if (Unit* currentVictim = _source->GetThreatManager().GetCurrentVictim())
        return target != currentVictim;

    return target != _source->GetVictim();
}

bool PowerUsersSelector::operator()(Unit const* target) const
{
    if (!_me || !target)
        return false;

    if (target->GetPowerType() != _power)
        return false;

    if (_playerOnly && target->GetTypeId() != TYPEID_PLAYER)
        return false;

    if (_dist > 0.0f && !_me->IsWithinCombatRange(target, _dist))
        return false;

    if (_dist < 0.0f && _me->IsWithinCombatRange(target, -_dist))
        return false;

    return true;
}

bool FarthestTargetSelector::operator()(Unit const* target) const
{
    if (!_me || !target)
        return false;

    if (_playerOnly && target->GetTypeId() != TYPEID_PLAYER)
        return false;

    if (_dist > 0.0f && !_me->IsWithinCombatRange(target, _dist))
        return false;

    if (_inLos && !_me->IsWithinLOSInMap(target))
        return false;

    return true;
}
