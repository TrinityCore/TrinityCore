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

#ifndef Garrison_h__
#define Garrison_h__

#include "Define.h"
#include "DatabaseEnvFwd.h"
#include "GarrisonAI.h"
#include "GarrisonPackets.h"
#include "GarrisonMgr.h"
#include "Optional.h"
#include <unordered_map>

class ClassHall;
class GameObject;
class GarrisonAI;
class Map;
class Player;
class WodGarrison;
struct GarrSiteLevelEntry;

class TC_GAME_API Garrison
{
public:
    struct Follower
    {
        uint32 GetItemLevel() const;
        void EarnXP(Player* owner, uint32 xp);
        uint32 _EarnXP(uint32 xp);
        uint32 GetRequiredLevelUpXP() const;

        WorldPackets::Garrison::GarrisonFollower PacketInfo;
    };

    struct Mission
    {
        WorldPackets::Garrison::GarrisonMission PacketInfo;
        std::vector<WorldPackets::Garrison::GarrisonMissionReward> Rewards;
        std::vector<WorldPackets::Garrison::GarrisonMissionReward> BonusRewards;
        bool CanStartMission = true;
    };

    explicit Garrison(Player* owner);
    Player* GetOwner() const { return _owner; }

    virtual bool LoadFromDB();
    virtual void SaveToDB(SQLTransaction& trans);
    void DeleteFromDB(SQLTransaction& trans);
    static void DeleteFromDB(SQLTransaction& trans, ObjectGuid::LowType guid, GarrisonType garrType);

    virtual bool Create(uint32 garrSiteId);
    void Update(uint32 const diff);
    virtual void Delete();

    virtual void Enter();
    virtual void Leave();

    uint32 GetScriptId() const;
    void AI_Initialize();
    void AI_Destroy();
    GarrisonAI* AI() { return _ai.get(); }

    virtual bool IsAllowedArea(AreaTableEntry const* /*area*/) const { return false; }

    GarrisonFactionIndex GetFaction() const;
    GarrisonType GetType() const { return _garrisonType; }
    void SetSiteLevel(GarrSiteLevelEntry const* siteLevel);
    GarrSiteLevelEntry const* GetSiteLevel() const { return _siteLevel; }

    // Followers
    void AddFollower(uint32 garrFollowerId);
    Follower* GetFollower(uint64 dbId);
    std::unordered_map<uint64 /*dbId*/, Garrison::Follower> const& GetFollowers() const { return _followers; }
    uint32 GetActiveFollowersCount() const;
    uint32 GetAverageFollowerILevel() const;
    uint32 GetMaxFollowerLevel() const;

    uint32 GetFollowerActivationLimit() const { return _followerActivationsRemainingToday; }
    void ResetFollowerActivationLimit() { _followerActivationsRemainingToday = 1; }

    // Missions
    void AddMission(uint32 garrMissionId);
    Mission* GetMission(uint64 dbId);
    Mission* GetMissionByID(uint32 ID);
    void DeleteMission(uint64 dbId);
    std::unordered_map<uint64 /*dbId*/, Garrison::Mission> const& GetMissions() const { return _missions; }
    std::vector<Follower*> GetMissionFollowers(uint32 garrMissionId);
    bool HasMission(uint32 garrMissionId) const;
    void StartMission(uint32 garrMissionId, std::vector<uint64 /*DbID*/> Followers);
    void SendStartMissionResult(bool success, Garrison::Mission* mission = nullptr, std::vector<uint64 /*DbID*/>* Followers = nullptr);
    void CompleteMission(uint32 garrMissionId);
    void CalculateMissonBonusRoll(uint32 garrMissionId);
    void RewardMission(Mission* mission, bool withOvermaxReward);

    std::pair<std::vector<GarrMissionEntry const*>, std::vector<double>> GetAvailableMissions() const;
    void GenerateMissions();

    bool IsWodGarrison() const { return GetType() == GARRISON_TYPE_GARRISON; }
    WodGarrison* ToWodGarrison() { if (IsWodGarrison()) return reinterpret_cast<WodGarrison*>(this); else return nullptr; }
    WodGarrison const* ToWodGarrison() const { if (IsWodGarrison()) return reinterpret_cast<WodGarrison const*>(this); else return nullptr; }

    bool IsClassHall() const { return GetType() == GARRISON_TYPE_CLASS_HALL; }
    ClassHall* ToClassHall() { if (IsClassHall()) return reinterpret_cast<ClassHall*>(this); else return nullptr; }
    ClassHall const* ToClassHall() const { if (IsClassHall()) return reinterpret_cast<ClassHall const*>(this); else return nullptr; }

protected:
    GarrisonType _garrisonType;

    Map* FindMap() const;

    Player* _owner;
    GarrSiteLevelEntry const* _siteLevel;
    std::unique_ptr<GarrisonAI> _ai;
    IntervalTimer _timers[GUPDATE_COUNT];

    std::unordered_map<uint64 /*dbId*/, Garrison::Follower> _followers;
    std::unordered_set<uint32> _followerIds;
    uint32 _followerActivationsRemainingToday;

    std::unordered_map<uint64 /*dbId*/, Garrison::Mission> _missions;
    std::unordered_set<uint32> _missionIds;
};

#endif // Garrison_h__
