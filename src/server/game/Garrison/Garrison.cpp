/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "Creature.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Garrison.h"
#include "GarrisonAI.h"
#include "GameObject.h"
#include "GarrisonMgr.h"
#include "Log.h"
#include "Map.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "VehicleDefines.h"

Garrison::Garrison(Player* owner) : _owner(owner), _siteLevel(nullptr), _followerActivationsRemainingToday(1)
{
    _timers[GUPDATE_MISSIONS_DISTRIBUTION].SetInterval(MINUTE*IN_MILLISECONDS);
}

bool Garrison::Create(uint32 garrSiteId)
{
    GarrSiteLevelEntry const* siteLevel = sGarrisonMgr.GetGarrSiteLevelEntry(garrSiteId, 1);
    if (!siteLevel)
        return false;

    SetSiteLevel(siteLevel);

    WorldPackets::Garrison::GarrisonCreateResult garrisonCreateResult;
    garrisonCreateResult.GarrSiteLevelID = _siteLevel->ID;
    _owner->SendDirectMessage(garrisonCreateResult.Write());
    PhasingHandler::OnConditionChange(_owner);

    return true;
}

void Garrison::Update(uint32 const diff)
{
    // Update the different timers
    for (uint8 i = 0; i < GUPDATE_COUNT; ++i)
    {
        if (_timers[i].GetCurrent() >= 0)
            _timers[i].Update(diff);
        else
            _timers[i].SetCurrent(0);
    }

    if (_timers[GUPDATE_MISSIONS_DISTRIBUTION].Passed())
    {
        _timers[GUPDATE_MISSIONS_DISTRIBUTION].Reset();
        GenerateMissions();
    }
}

void Garrison::Delete()
{
    WorldPackets::Garrison::GarrisonDeleteResult garrisonDelete;
    garrisonDelete.Result = GARRISON_SUCCESS;
    garrisonDelete.GarrSiteID = _siteLevel->GarrSiteID;
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

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHARACTER_GARRISON_MISSION_REWARDS);
    stmt->setUInt64(0, lowGuid);
    stmt->setUInt8(1, _garrisonType);
    PreparedQueryResult rewardsStmt = CharacterDatabase.Query(stmt);

    if (!garrisonStmt)
        return false;

    Field* fields = garrisonStmt->Fetch();
    GarrSiteLevelEntry const* siteLevel = sGarrSiteLevelStore.LookupEntry(fields[0].GetUInt32());
    _followerActivationsRemainingToday = fields[1].GetUInt32();
    if (!siteLevel)
        return false;

    SetSiteLevel(siteLevel);

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

            if (mission.PacketInfo.StartTime == 0)
                mission.PacketInfo.StartTime = time_t(2254525440);

        } while (missionsStmt->NextRow());

        if (rewardsStmt)
        {
            do
            {
                fields = rewardsStmt->Fetch();
                uint64 dbId = fields[0].GetUInt64();
                uint8 type  = fields[1].GetUInt8();

                auto itr = _missions.find(dbId);
                if (itr == _missions.end())
                    continue;

                WorldPackets::Garrison::GarrisonMissionReward reward;
                reward.ItemID           = fields[2].GetInt32();
                reward.ItemQuantity     = fields[3].GetUInt32();
                reward.CurrencyID       = fields[4].GetInt32();
                reward.CurrencyQuantity = fields[5].GetUInt32();
                reward.FollowerXP       = fields[6].GetUInt32();
                reward.BonusAbilityID   = fields[7].GetUInt32();

                if (type == GarrisonMission::RewardType::Normal)
                    itr->second.Rewards.push_back(reward);
                else
                    itr->second.BonusRewards.push_back(reward);

            } while (abilitiesStmt->NextRow());
        }
    }

    return true;
}

void Garrison::SaveToDB(SQLTransaction trans)
{
    DeleteFromDB(trans);

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
        stmt->setUInt32(index++, mission.PacketInfo.StartTime != time_t(2254525440) ? mission.PacketInfo.StartTime: 0);
        stmt->setUInt32(index++, mission.PacketInfo.MissionState);
        trans->Append(stmt);

        uint8 rewardType = GarrisonMission::RewardType::Normal;
        for (auto rewards : { mission.Rewards, mission.BonusRewards })
        {
            for (WorldPackets::Garrison::GarrisonMissionReward reward : rewards)
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_GARRISON_MISSION_REWARDS);
                stmt->setUInt64(0, mission.PacketInfo.DbID);
                stmt->setUInt8(1, rewardType++);
                stmt->setInt32(2, reward.ItemID);
                stmt->setUInt32(3, reward.ItemQuantity);
                stmt->setInt32(4, reward.CurrencyID);
                stmt->setUInt32(5, reward.CurrencyQuantity);
                stmt->setUInt32(6, reward.FollowerXP);
                stmt->setUInt32(7, reward.BonusAbilityID);
                trans->Append(stmt);
            }
        }
    }
}

void Garrison::DeleteFromDB(SQLTransaction trans)
{
    Garrison::DeleteFromDB(trans, _owner->GetGUID().GetCounter(), GetType());
}

void Garrison::DeleteFromDB(SQLTransaction trans, ObjectGuid::LowType guid, GarrisonType garrType)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_GARRISON);
    stmt->setUInt64(0, guid);
    stmt->setUInt8(1, garrType);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_GARRISON_MISSIONS);
    stmt->setUInt64(0, guid);
    stmt->setUInt8(1, garrType);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_GARRISON_FOLLOWERS);
    stmt->setUInt64(0, guid);
    stmt->setUInt8(1, garrType);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_GARRISON_BLUEPRINTS);
    stmt->setUInt64(0, guid);
    stmt->setUInt8(1, garrType);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHARACTER_GARRISON_BUILDINGS);
    stmt->setUInt64(0, guid);
    stmt->setUInt8(1, garrType);
    trans->Append(stmt);
}

void Garrison::Enter()
{
    _owner->SetCurrentGarrison(_garrisonType);
    AI()->OnPlayerEnter(_owner);
}

void Garrison::Leave()
{
    _owner->SetCurrentGarrison(GARRISON_TYPE_NONE);
    AI()->OnPlayerLeave(_owner);
}

uint32 Garrison::GetScriptId() const
{
    return sObjectMgr->GetScriptIdForGarrison(_siteLevel->ID);
}

GarrisonFactionIndex Garrison::GetFaction() const
{
    return _owner->GetTeam() == HORDE ? GARRISON_FACTION_INDEX_HORDE : GARRISON_FACTION_INDEX_ALLIANCE;
}

void Garrison::SetSiteLevel(GarrSiteLevelEntry const* siteLevel)
{
    _siteLevel = siteLevel;
    AI_Initialize();
}

void Garrison::AI_Initialize()
{
    AI_Destroy();
    GarrisonAI* ai = sScriptMgr->GetGarrisonAI(this);
    if (!ai)
        ai = new NullGarrisonAI(this);

    _ai.reset(ai);
}

void Garrison::AI_Destroy()
{
    _ai.reset();
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
    follower.PacketInfo.FollowerLevel = followerEntry->FollowerLevel;
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

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    SaveToDB(trans);
    CharacterDatabase.CommitTransaction(trans);
}

Garrison::Follower const* Garrison::GetFollower(uint64 dbId) const
{
    auto itr = _followers.find(dbId);
    if (itr != _followers.end())
        return &itr->second;

    return nullptr;
}

uint32 Garrison::GetActiveFollowersCount() const
{
    return std::count_if(_followers.begin(), _followers.end(), [](auto followerItr)
    {
        return followerItr.second.PacketInfo.FollowerStatus != FOLLOWER_STATUS_INACTIVE;
    });
}

uint32 Garrison::GetAverageFollowerILevel() const
{
    uint32 followerIlevels = 0;
    uint32 activeFollowerCount = 0;

    for (auto itr : _followers)
    {
        if (itr.second.PacketInfo.FollowerStatus != FOLLOWER_STATUS_INACTIVE)
        {
            followerIlevels += itr.second.GetItemLevel();
            ++activeFollowerCount;
        }
    }

    return ceil(float(followerIlevels) / float(activeFollowerCount));
}

uint32 Garrison::GetMaxFollowerLevel() const
{
    uint32 maxFollowerLevel = 0;

    for (auto itr : _followers)
        if (itr.second.PacketInfo.FollowerStatus != FOLLOWER_STATUS_INACTIVE)
            maxFollowerLevel = std::max(maxFollowerLevel, itr.second.PacketInfo.FollowerLevel);

    return maxFollowerLevel;
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
    mission.PacketInfo.OfferTime = time(nullptr);
    mission.PacketInfo.OfferDuration = missionEntry->OfferTime;
    mission.PacketInfo.StartTime = time_t(2254525440);
    mission.PacketInfo.TravelDuration = missionEntry->TravelTime;
    mission.PacketInfo.MissionDuration = missionEntry->Duration;
    mission.PacketInfo.MissionState = 0;
    mission.PacketInfo.Unknown1 = 0;
    mission.PacketInfo.Unknown2 = 0;

    // TODO : Generate rewards for mission
    WorldPackets::Garrison::GarrisonMissionReward reward;
    reward.ItemID = 140587;
    reward.ItemQuantity = 1;
    reward.CurrencyID = 0;
    reward.CurrencyQuantity = 0;
    reward.FollowerXP = 0;
    reward.BonusAbilityID = 0;
    reward.Unknown = 1118739;
    mission.Rewards.push_back(reward);

    WorldPackets::Garrison::GarrisonAddMissionResult garrisonAddMissionResult;
    garrisonAddMissionResult.GarrType       = GetType();
    garrisonAddMissionResult.Result         = GarrisonMission::AddResult::Success;
    garrisonAddMissionResult.State          = GarrisonMission::State::Available;
    garrisonAddMissionResult.Mission        = mission.PacketInfo;
    garrisonAddMissionResult.Rewards        = mission.Rewards;
    garrisonAddMissionResult.BonusRewards   = mission.BonusRewards;
    garrisonAddMissionResult.Success        = true;
    _owner->SendDirectMessage(garrisonAddMissionResult.Write());
}

Garrison::Mission const* Garrison::GetMission(uint64 dbId) const
{
    auto itr = _missions.find(dbId);
    if (itr != _missions.end())
        return &itr->second;

    return nullptr;
}

bool Garrison::HasMission(uint32 garrMissionId) const
{
    return std::count_if(GetMissions().begin(), GetMissions().end(), [garrMissionId](auto missionItr)
    {
        return missionItr.second.PacketInfo.MissionRecID == garrMissionId;
    });
}

void Garrison::StartMission(uint32 garrMissionId, std::vector<uint64 /*DbID*/> /*Followers*/)
{
    GarrMissionEntry const* missionEntry = sGarrMissionStore.LookupEntry(garrMissionId);
    if (!missionEntry)
    {
        // Send error
        return;
    }

    if (!HasMission(missionEntry->ID))
    {
        // Send error
        return;
    }


}

std::pair<std::vector<GarrMissionEntry const*>, std::vector<double>> Garrison::GetAvailableMissions() const
{
    std::vector<GarrMissionEntry const*> availableMissions;
    std::vector<double> weights;

    uint32 const maxFollowerlevel       = GetMaxFollowerLevel();
    uint32 const activeFolowerCount     = GetActiveFollowersCount();
    uint32 const averageFollowerILevel  = GetAverageFollowerILevel();

    for (uint32 i = 0; i < sGarrMissionStore.GetNumRows(); ++i)
    {
        GarrMissionEntry const* missionEntry = sGarrMissionStore.LookupEntry(i);

        if (!missionEntry)
            continue;

        if (HasMission(missionEntry->ID))
            continue;

        // Most missions with Duration <= 10 are tests
        if (missionEntry->Duration <= 10)
            continue;

        if (missionEntry->GarrTypeID != GetType())
            continue;

        if (missionEntry->RequiredLevel > maxFollowerlevel)
            continue;

        if (missionEntry->RequiredFollowersCount > activeFolowerCount)
            continue;

        if (missionEntry->RequiredItemLevel > averageFollowerILevel)
            continue;

        uint32 requiredClass = sGarrisonMgr.GetClassByMissionType(missionEntry->MissionType);
        if (requiredClass != CLASS_NONE && requiredClass != _owner->getClass())
            continue;

        uint32 requiredTeam = sGarrisonMgr.GetFactionByMissionType(missionEntry->MissionType);
        if (requiredTeam != TEAM_OTHER && requiredTeam != _owner->GetTeamId())
            continue;

        double weight = 100.0;
        if (missionEntry->Flags & GarrisonMission::Flags::Rare)
            weight = 25.0;

        availableMissions.push_back(missionEntry);
        weights.push_back(weight);
    }

    return std::make_pair(availableMissions, weights);
}

void Garrison::GenerateMissions()
{
    uint32 maxMissionCount = ceil(GetActiveFollowersCount() * GARRISON_MISSION_DISTRIB_FOLLOWER_COEFF);

    if (GetMissions().size() >= maxMissionCount)
        return;

    uint32 missionToAddCount = urand(0, maxMissionCount - GetMissions().size());

    if (!missionToAddCount)
        return;

    std::pair<std::vector<GarrMissionEntry const*>, std::vector<double>> availableMissionWithWeights = GetAvailableMissions();

    for (uint32 i = 0; i < missionToAddCount; ++i)
    {
        auto missionItr = Trinity::Containers::SelectRandomWeightedContainerElement(availableMissionWithWeights.first, availableMissionWithWeights.second);
        if (missionItr == availableMissionWithWeights.first.end())
            return;

        AddMission((*missionItr)->ID);

        // We will remove mission from available missions, also remove corresponding weight from vector
        auto distance = std::distance(availableMissionWithWeights.first.cbegin(), missionItr);
        auto weightItr = availableMissionWithWeights.second.begin();
        std::advance(weightItr, distance);

        availableMissionWithWeights.first.erase(missionItr);
        availableMissionWithWeights.second.erase(weightItr);
    }

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    SaveToDB(trans);
    CharacterDatabase.CommitTransaction(trans);
}

Map* Garrison::FindMap() const
{
    return sMapMgr->FindMap(_siteLevel->MapID, _owner->GetGUID().GetCounter());
}

uint32 Garrison::Follower::GetItemLevel() const
{
    return (PacketInfo.ItemLevelWeapon + PacketInfo.ItemLevelArmor) / 2;
}
