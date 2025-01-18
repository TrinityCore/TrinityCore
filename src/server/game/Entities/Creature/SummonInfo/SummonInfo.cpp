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
#include "Creature.h"
#include "DB2Stores.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "SummonInfoArgs.h"

SummonInfo::SummonInfo(Creature* summonedCreature, SummonInfoArgs const& args) :
    _summonedCreature(ASSERT_NOTNULL(summonedCreature)), _despawnOnSummonerLogout(false), _despawnOnSummonerDeath(false), _despawnWhenExpired(false)
{
    InitializeSummonSettings(args);
}

void SummonInfo::InitializeSummonSettings(SummonInfoArgs const& args)
{
    _summonerGUID = args.SummonerGUID;
    _maxHealth = args.MaxHealth;
    _remainingDuration = args.Duration;
    _summonSpellId = args.SummonSpellId;

    if (!args.SummonPropertiesId.has_value())
        return;

    SummonPropertiesEntry const* summonProperties = sSummonPropertiesStore.LookupEntry(*args.SummonPropertiesId);
    if (!summonProperties)
    {
        TC_LOG_ERROR("entities.unit", "Creature {} has been summoned with a non-existing SummonProperties.db2 entry (RecId: {}). Possible dirty DB2 data or missing hotfix entry.", _summonedCreature->GetGUID().ToString(), *args.SummonPropertiesId);
        return;
    }

    if (summonProperties->Faction)
        _factionId = summonProperties->Faction;

    _despawnOnSummonerLogout = summonProperties->GetFlags().HasFlag(SummonPropertiesFlags::DespawnOnSummonerLogout);
    _despawnOnSummonerDeath = summonProperties->GetFlags().HasFlag(SummonPropertiesFlags::DespawnOnSummonerDeath);
    _despawnWhenExpired = summonProperties->GetFlags().HasFlag(SummonPropertiesFlags::DespawnWhenExpired);

    if (_despawnOnSummonerDeath && summonProperties->GetFlags().HasFlag(SummonPropertiesFlags::DontDespawnOnSummonerDeath))
        _despawnOnSummonerDeath = false;
}

Creature* SummonInfo::GetSummonedCreature() const
{
    return _summonedCreature;
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

Optional<Milliseconds> SummonInfo::GetRemainingDuration() const
{
    return _remainingDuration;
}

Optional<uint64> SummonInfo::GetMaxHealth() const
{
    return _maxHealth;
}

Optional<uint32> SummonInfo::GetSummonSpellId() const
{
    return _summonSpellId;
}

Optional<uint32> SummonInfo::GetFactionId() const
{
    return _factionId;
}

bool SummonInfo::DespawnsOnSummonerLogout() const
{
    return _despawnOnSummonerLogout;
}

void SummonInfo::SetDespawnOnSummonerLogout(bool set)
{
    _despawnOnSummonerLogout = set;
}

bool SummonInfo::DespawnsOnSummonerDeath() const
{
    return _despawnOnSummonerDeath;
}

void SummonInfo::SetDespawnOnSummonerDeath(bool set)
{
    _despawnOnSummonerDeath = set;
}

bool SummonInfo::DespawnsWhenExpired() const
{
    return _despawnWhenExpired;
}

void SummonInfo::SetDespawnWhenExpired(bool set)
{
    _despawnWhenExpired = set;
}
