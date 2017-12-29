/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "Garrison.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "GarrisonMgr.h"
#include "Log.h"
#include "Map.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "VehicleDefines.h"

Garrison::Garrison(Player* owner) : _owner(owner), _siteLevel(nullptr), _followerActivationsRemainingToday(1)
{
}

bool Garrison::Create(uint32 garrSiteId)
{
    GarrSiteLevelEntry const* siteLevel = sGarrisonMgr.GetGarrSiteLevelEntry(garrSiteId, 1);
    if (!siteLevel)
        return false;

    _siteLevel = siteLevel;

    WorldPackets::Garrison::GarrisonCreateResult garrisonCreateResult;
    garrisonCreateResult.GarrSiteLevelID = _siteLevel->ID;
    _owner->SendDirectMessage(garrisonCreateResult.Write());
    _owner->SendUpdatePhasing();
    return true;
}

void Garrison::Delete()
{
    WorldPackets::Garrison::GarrisonDeleteResult garrisonDelete;
    garrisonDelete.Result = GARRISON_SUCCESS;
    garrisonDelete.GarrSiteID = _siteLevel->SiteID;
    _owner->SendDirectMessage(garrisonDelete.Write());
}

bool Garrison::LoadFromDB()
{
    ObjectGuid::LowType lowGuid = _owner->GetGUID().GetCounter();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GARRISON);
    stmt->setUInt64(0, lowGuid);
    stmt->setUInt8(1, _garrisonType);
    PreparedQueryResult garrisonStmt = CharacterDatabase.Query(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GARRISON_FOLLOWERS);
    stmt->setUInt64(0, lowGuid);
    stmt->setUInt8(1, _garrisonType);
    PreparedQueryResult followersStmt = CharacterDatabase.Query(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GARRISON_FOLLOWER_ABILITIES);
    stmt->setUInt64(0, lowGuid);
    stmt->setUInt8(1, _garrisonType);
    PreparedQueryResult abilitiesStmt = CharacterDatabase.Query(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GARRISON_MISSIONS);
    stmt->setUInt64(0, lowGuid);
    stmt->setUInt8(1, _garrisonType);
    PreparedQueryResult missionsStmt = CharacterDatabase.Query(stmt);

    if (!garrisonStmt)
        return false;

    Field* fields = garrisonStmt->Fetch();
    _siteLevel = sGarrSiteLevelStore.LookupEntry(fields[0].GetUInt32());
    _followerActivationsRemainingToday = fields[1].GetUInt32();
    if (!_siteLevel)
        return false;

    //           0           1        2      3                4               5   6                7               8       9
    // SELECT dbId, followerId, quality, level, itemLevelWeapon, itemLevelArmor, xp, currentBuilding, currentMission, status FROM character_garrison_followers WHERE guid = ? AND garrison_type = ?
    if (followersStmt)
    {
        do
        {
            fields = followersStmt->Fetch();

            uint64 dbId = fields[0].GetUInt64();
            uint32 followerId = fields[1].GetUInt32();
            if (!sGarrFollowerStore.LookupEntry(followerId))
                continue;

            _followerIds.insert(followerId);
            Follower& follower = _followers[dbId];
            follower.PacketInfo.DbID = dbId;
            follower.PacketInfo.GarrFollowerID = followerId;
            follower.PacketInfo.Quality = fields[2].GetUInt32();
            follower.PacketInfo.FollowerLevel = fields[3].GetUInt32();
            follower.PacketInfo.ItemLevelWeapon = fields[4].GetUInt32();
            follower.PacketInfo.ItemLevelArmor = fields[5].GetUInt32();
            follower.PacketInfo.Xp = fields[6].GetUInt32();
            follower.PacketInfo.CurrentMissionID = fields[8].GetUInt32();
            follower.PacketInfo.FollowerStatus = fields[9].GetUInt32();
            if (!sGarrBuildingStore.LookupEntry(follower.PacketInfo.CurrentBuildingID))
                follower.PacketInfo.CurrentBuildingID = 0;

            //if (!sGarrMissionStore.LookupEntry(follower.PacketInfo.CurrentMissionID))
            //    follower.PacketInfo.CurrentMissionID = 0;

        } while (followersStmt->NextRow());

        if (abilitiesStmt)
        {
            do
            {
                fields = abilitiesStmt->Fetch();
                uint64 dbId = fields[0].GetUInt64();
                GarrAbilityEntry const* ability = sGarrAbilityStore.LookupEntry(fields[1].GetUInt32());

                if (!ability)
                    continue;

                auto itr = _followers.find(dbId);
                if (itr == _followers.end())
                    continue;

                itr->second.PacketInfo.AbilityID.push_back(ability);
            } while (abilitiesStmt->NextRow());
        }
    }

    // SELECT dbId, missionId, offerTime, startTime, status
    if (missionsStmt)
    {
        do
        {
            fields = missionsStmt->Fetch();

            uint64 dbId = fields[0].GetUInt64();
            uint32 missionId = fields[1].GetUInt32();

            GarrMissionEntry const* missionEntry = sGarrMissionStore.LookupEntry(missionId);
            if (!missionEntry)
                continue;

            _missionIds.insert(missionId);
            Mission& mission = _missions[dbId];
            mission.PacketInfo.DbID             = dbId;
            mission.PacketInfo.MissionRecID     = missionId;
            mission.PacketInfo.OfferTime        = time_t(fields[2].GetUInt32());
            mission.PacketInfo.OfferDuration    = missionEntry->OfferTime;
            mission.PacketInfo.StartTime        = time_t(fields[3].GetUInt32());
            mission.PacketInfo.TravelDuration   = missionEntry->TravelTime;
            mission.PacketInfo.MissionDuration  = missionEntry->Duration;
            mission.PacketInfo.MissionState     = fields[4].GetUInt8();

        } while (missionsStmt->NextRow());
    }

    return true;
}

void Garrison::SaveToDB(SQLTransaction trans)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_GARRISON);
    stmt->setUInt64(0, _owner->GetGUID().GetCounter());
    stmt->setUInt8(1, _garrisonType);
    stmt->setUInt32(2, _siteLevel->ID);
    stmt->setUInt32(3, _followerActivationsRemainingToday);
    trans->Append(stmt);

    for (auto const& p : _followers)
    {
        Follower const& follower = p.second;
        uint8 index = 0;
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_GARRISON_FOLLOWERS);
        stmt->setUInt64(index++, follower.PacketInfo.DbID);
        stmt->setUInt64(index++, _owner->GetGUID().GetCounter());
        stmt->setUInt8(index++, _garrisonType);
        stmt->setUInt32(index++, follower.PacketInfo.GarrFollowerID);
        stmt->setUInt32(index++, follower.PacketInfo.Quality);
        stmt->setUInt32(index++, follower.PacketInfo.FollowerLevel);
        stmt->setUInt32(index++, follower.PacketInfo.ItemLevelWeapon);
        stmt->setUInt32(index++, follower.PacketInfo.ItemLevelArmor);
        stmt->setUInt32(index++, follower.PacketInfo.Xp);
        stmt->setUInt32(index++, follower.PacketInfo.CurrentBuildingID);
        stmt->setUInt32(index++, follower.PacketInfo.CurrentMissionID);
        stmt->setUInt32(index++, follower.PacketInfo.FollowerStatus);
        trans->Append(stmt);

        uint8 slot = 0;
        for (GarrAbilityEntry const* ability : follower.PacketInfo.AbilityID)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_GARRISON_FOLLOWER_ABILITIES);
            stmt->setUInt64(0, follower.PacketInfo.DbID);
            stmt->setUInt32(1, ability->ID);
            stmt->setUInt8(2, slot++);
            trans->Append(stmt);
        }
    }

    for (auto const& p : _missions)
    {
        Mission const& mission = p.second;
        uint8 index = 0;
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_GARRISON_MISSIONS);
        stmt->setUInt64(index++, mission.PacketInfo.DbID);
        stmt->setUInt64(index++, _owner->GetGUID().GetCounter());
        stmt->setUInt8(index++, _garrisonType);
        stmt->setUInt32(index++, mission.PacketInfo.MissionRecID);
        stmt->setUInt32(index++, mission.PacketInfo.OfferTime);
        stmt->setUInt32(index++, mission.PacketInfo.StartTime);
        stmt->setUInt32(index++, mission.PacketInfo.MissionState);
        trans->Append(stmt);
    }
}

void Garrison::Enter() const
{
    if (MapEntry const* map = sMapStore.LookupEntry(_siteLevel->MapID))
        if (int32(_owner->GetMapId()) == map->ParentMapID)
            _owner->SeamlessTeleportToMap(_siteLevel->MapID);
}

void Garrison::Leave() const
{
    if (MapEntry const* map = sMapStore.LookupEntry(_siteLevel->MapID))
        if (_owner->GetMapId() == _siteLevel->MapID)
            _owner->SeamlessTeleportToMap(map->ParentMapID);
}

GarrisonFactionIndex Garrison::GetFaction() const
{
    return _owner->GetTeam() == HORDE ? GARRISON_FACTION_INDEX_HORDE : GARRISON_FACTION_INDEX_ALLIANCE;
}

void Garrison::AddFollower(uint32 garrFollowerId)
{
    WorldPackets::Garrison::GarrisonAddFollowerResult addFollowerResult;
    addFollowerResult.GarrTypeID = (int32)_garrisonType;
    GarrFollowerEntry const* followerEntry = sGarrFollowerStore.LookupEntry(garrFollowerId);
    if (_followerIds.count(garrFollowerId) || !followerEntry)
    {
        addFollowerResult.Result = GARRISON_ERROR_FOLLOWER_EXISTS;
        _owner->SendDirectMessage(addFollowerResult.Write());
        return;
    }

    _followerIds.insert(garrFollowerId);
    uint64 dbId = sGarrisonMgr.GenerateFollowerDbId();
    Follower& follower = _followers[dbId];
    follower.PacketInfo.DbID = dbId;
    follower.PacketInfo.GarrFollowerID = garrFollowerId;
    follower.PacketInfo.Quality = followerEntry->Quality;   // TODO: handle magic upgrades
    follower.PacketInfo.FollowerLevel = followerEntry->Level;
    follower.PacketInfo.ItemLevelWeapon = followerEntry->ItemLevelWeapon;
    follower.PacketInfo.ItemLevelArmor = followerEntry->ItemLevelArmor;
    follower.PacketInfo.Xp = 0;
    follower.PacketInfo.CurrentBuildingID = 0;
    follower.PacketInfo.CurrentMissionID = 0;
    follower.PacketInfo.AbilityID = sGarrisonMgr.RollFollowerAbilities(garrFollowerId, followerEntry, follower.PacketInfo.Quality, GetFaction(), true);
    follower.PacketInfo.FollowerStatus = 0;

    addFollowerResult.Follower = follower.PacketInfo;
    _owner->SendDirectMessage(addFollowerResult.Write());

    _owner->UpdateCriteria(CRITERIA_TYPE_RECRUIT_GARRISON_FOLLOWER, follower.PacketInfo.DbID);
}

Garrison::Follower const* Garrison::GetFollower(uint64 dbId) const
{
    auto itr = _followers.find(dbId);
    if (itr != _followers.end())
        return &itr->second;

    return nullptr;
}

void Garrison::AddMission(uint32 garrMissionId)
{
    GarrMissionEntry const* missionEntry = sGarrMissionStore.LookupEntry(garrMissionId);
    if (_missionIds.count(garrMissionId) || !missionEntry)
        return;

    _missionIds.insert(garrMissionId);
    uint64 dbId = sGarrisonMgr.GenerateMissionDbId();
    Mission& mission = _missions[dbId];
    mission.PacketInfo.DbID = dbId;
    mission.PacketInfo.MissionRecID = garrMissionId;
    mission.PacketInfo.OfferTime = time_t(0);
    mission.PacketInfo.OfferDuration = missionEntry->OfferTime;
    mission.PacketInfo.StartTime = time_t(2288912640);
    mission.PacketInfo.TravelDuration = missionEntry->TravelTime;
    mission.PacketInfo.MissionDuration = missionEntry->Duration;
    mission.PacketInfo.MissionState = 0;
    mission.PacketInfo.Unknown1 = 0;
    mission.PacketInfo.Unknown2 = 0;

    WorldPackets::Garrison::GarrisonMissionReward reward;
    reward.ItemID = 140587;
    reward.Quantity = 1;
    reward.CurrencyID = 0;
    reward.CurrencyQuantity = 0;
    reward.FollowerXP = 0;
    reward.BonusAbilityID = 0;
    reward.Unknown = 1118739;
    mission.Rewards.push_back(reward);
}

Garrison::Mission const* Garrison::GetMission(uint64 dbId) const
{
    auto itr = _missions.find(dbId);
    if (itr != _missions.end())
        return &itr->second;

    return nullptr;
}

Map* Garrison::FindMap() const
{
    return sMapMgr->FindMap(_siteLevel->MapID, _owner->GetGUID().GetCounter());
}

uint32 Garrison::Follower::GetItemLevel() const
{
    return (PacketInfo.ItemLevelWeapon + PacketInfo.ItemLevelArmor) / 2;
}
