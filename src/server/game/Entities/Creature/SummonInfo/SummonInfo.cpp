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

#include "SummonInfo.h"
#include "DB2Store.h"
#include "ObjectAccessor.h"
#include "SummonInfoArgs.h"

SummonInfo::SummonInfo(Creature* summonedCreature, SummonInfoArgs const& args) : _summonedCreature(summonedCreature)
{
    _remainingDuration = args.Duration;
    _summonerGUID = args.SummonerGUID;

    SummonPropertiesEntry const* summonProperties = nullptr;
    if (args.SummonPropertiesID.has_value())
        summonProperties = sSummonPropertiesStore.LookupEntry(*args.SummonPropertiesID);

    if (summonProperties)
    {
        _shouldDespawnOnSummonerLogout = summonProperties->GetFlags().HasFlag(SummonPropertiesFlags::DespawnOnSummonerLogout);
        _shouldDespawnOnSummonerDeath = summonProperties->GetFlags().HasFlag(SummonPropertiesFlags::DespawnOnSummonerDeath);
        _shouldDespawnWhenExpired = summonProperties->GetFlags().HasFlag(SummonPropertiesFlags::DespawnWhenExpired);
    }
    else
    {
        _shouldDespawnWhenExpired = false;
        _shouldDespawnOnSummonerLogout = false;
        _shouldDespawnOnSummonerDeath = false;
    }
}

Creature* SummonInfo::GetSummonedCreature() const
{
    return _summonedCreature;
}

Optional<Milliseconds> SummonInfo::GetRemainingDuration() const
{
    return _remainingDuration;
}

Unit* SummonInfo::GetUnitSummoner() const
{
    if (!_summonerGUID.has_value())
        return nullptr;

    return ObjectAccessor::GetUnit(*_summonedCreature, *_summonerGUID);
}

GameObject* SummonInfo::GetGameObjectSummoner() const
{
    if (!_summonerGUID.has_value())
        return nullptr;

    return ObjectAccessor::GetGameObject(*_summonedCreature, *_summonerGUID);
}

bool SummonInfo::ShouldDespawnOnSummonerLogout() const
{
    return _shouldDespawnOnSummonerLogout;
}

void SummonInfo::SetShouldDespawnOnSummonerLogout(bool set)
{
    _shouldDespawnOnSummonerLogout = set;
}

bool SummonInfo::ShouldDespawnOnSummonerDeath() const
{
    return _shouldDespawnOnSummonerDeath;
}

void SummonInfo::SetShouldDespawnOnSummonerDeath(bool set)
{
    _shouldDespawnOnSummonerDeath = set;
}

bool SummonInfo::ShouldDespawnWhenExpired() const
{
    return _shouldDespawnWhenExpired;
}

void SummonInfo::SetShouldDespawnWhenExpired(bool set)
{
    _shouldDespawnWhenExpired = set;
}
