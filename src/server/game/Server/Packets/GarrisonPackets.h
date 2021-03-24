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

#ifndef GarrisonPackets_h__
#define GarrisonPackets_h__

#include "Packet.h"
#include "ItemPacketsCommon.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Position.h"
#include "PacketUtilities.h"
#include <list>
#include <unordered_set>
#include <vector>

struct GarrAbilityEntry;

namespace WorldPackets
{
    namespace Garrison
    {
        class GarrisonCreateResult final : public ServerPacket
        {
        public:
            GarrisonCreateResult() : ServerPacket(SMSG_GARRISON_CREATE_RESULT, 4 + 4) { }

            WorldPacket const* Write() override;

            uint32 GarrSiteLevelID = 0;
            uint32 Result = 0;
        };

        class GarrisonDeleteResult final : public ServerPacket
        {
        public:
            GarrisonDeleteResult() : ServerPacket(SMSG_GARRISON_DELETE_RESULT, 4 + 4) { }

            WorldPacket const* Write() override;

            uint32 Result = 0;
            uint32 GarrSiteID = 0;
        };

        class GetGarrisonInfo final : public ClientPacket
        {
        public:
            GetGarrisonInfo(WorldPacket&& packet) : ClientPacket(CMSG_GET_GARRISON_INFO, std::move(packet)) { }

            void Read() override { }
        };

        struct GarrisonPlotInfo
        {
            uint32 GarrPlotInstanceID = 0;
            TaggedPosition<Position::XYZO> PlotPos;
            uint32 PlotType = 0;
        };

        struct GarrisonBuildingInfo
        {
            uint32 GarrPlotInstanceID = 0;
            uint32 GarrBuildingID = 0;
            Timestamp<> TimeBuilt;
            uint32 CurrentGarSpecID = 0;
            Timestamp<> TimeSpecCooldown = time_t(2288912640);   // 06/07/1906 18:35:44 - another in the series of magic blizz dates
            bool Active = false;
        };

        struct GarrisonFollower
        {
            uint64 DbID = 0;
            uint32 GarrFollowerID = 0;
            uint32 Quality = 0;
            uint32 FollowerLevel = 0;
            uint32 ItemLevelWeapon = 0;
            uint32 ItemLevelArmor = 0;
            uint32 Xp = 0;
            uint32 Durability = 0;
            uint32 CurrentBuildingID = 0;
            uint32 CurrentMissionID = 0;
            std::list<GarrAbilityEntry const*> AbilityID;
            uint32 ZoneSupportSpellID = 0;
            uint32 FollowerStatus = 0;
            int32 Health = 0;
            Timestamp<> HealingTimestamp;
            int8 BoardIndex = 0;
            std::string CustomName;
        };

        struct GarrisonEncounter
        {
            int32 GarrEncounterID = 0;
            std::vector<int32> Mechanics;
            int32 GarrAutoCombatantID = 0;
            int32 Health = 0;
            int32 MaxHealth = 0;
            int32 Attack = 0;
            int8 BoardIndex = 0;
        };

        struct GarrisonMissionReward
        {
            int32 ItemID = 0;
            uint32 ItemQuantity = 0;
            int32 CurrencyID = 0;
            uint32 CurrencyQuantity = 0;
            uint32 FollowerXP = 0;
            uint32 GarrMssnBonusAbilityID = 0;
            int32 ItemFileDataID = 0;
            Optional<Item::ItemInstance> ItemInstance;
        };

        struct GarrisonMission
        {
            uint64 DbID = 0;
            int32 MissionRecID = 0;
            Timestamp<> OfferTime;
            Duration<Seconds> OfferDuration;
            Timestamp<> StartTime = time_t(2288912640);
            Duration<Seconds> TravelDuration;
            Duration<Seconds> MissionDuration;
            int32 MissionState = 0;
            int32 SuccessChance = 0;
            uint32 Flags = 0;
            float MissionScalar = 1.0f;
            int32 ContentTuningID = 0;
            std::vector<GarrisonEncounter> Encounters;
            std::vector<GarrisonMissionReward> Rewards;
            std::vector<GarrisonMissionReward> OvermaxRewards;
        };

        struct GarrisonMissionBonusAbility
        {
            uint32 GarrMssnBonusAbilityID = 0;
            Timestamp<> StartTime;
        };

        struct GarrisonTalentSocketData
        {
            int32 SoulbindConduitID = 0;
            int32 SoulbindConduitRank = 0;
        };

        struct GarrisonTalent
        {
            int32 GarrTalentID = 0;
            int32 Rank = 0;
            Timestamp<> ResearchStartTime;
            int32 Flags = 0;
            Optional<GarrisonTalentSocketData> Socket;
        };

        struct GarrisonCollectionEntry
        {
            int32 EntryID = 0;
            int32 Rank = 0;
        };

        struct GarrisonCollection
        {
            int32 Type = 0;
            std::vector<GarrisonCollectionEntry> Entries;
        };

        struct GarrisonEventEntry
        {
            int32 EntryID = 0;
            int64 EventValue = 0;
        };

        struct GarrisonEventList
        {
            int32 Type = 0;
            std::vector<GarrisonEventEntry> Events;
        };

        struct GarrisonSpecGroup
        {
            int32 ChrSpecializationID = 0;
            int32 SoulbindID = 0;
        };

        struct GarrisonInfo
        {
            int32 GarrTypeID = 0;
            uint32 GarrSiteID = 0;
            uint32 GarrSiteLevelID = 0;
            uint32 NumFollowerActivationsRemaining = 0;
            uint32 NumMissionsStartedToday = 0;   // might mean something else, but sending 0 here enables follower abilities "Increase success chance of the first mission of the day by %."
            int32 MinAutoTroopLevel = 0;
            std::vector<GarrisonPlotInfo*> Plots;
            std::vector<GarrisonBuildingInfo const*> Buildings;
            std::vector<GarrisonFollower const*> Followers;
            std::vector<GarrisonFollower const*> AutoTroops;
            std::vector<GarrisonMission const*> Missions;
            std::vector<std::vector<GarrisonMissionReward>> MissionRewards;
            std::vector<std::vector<GarrisonMissionReward>> MissionOvermaxRewards;
            std::vector<GarrisonMissionBonusAbility const*> MissionAreaBonuses;
            std::vector<GarrisonTalent> Talents;
            std::vector<GarrisonCollection> Collections;
            std::vector<GarrisonEventList> EventLists;
            std::vector<GarrisonSpecGroup> SpecGroups;
            std::vector<bool> CanStartMission;
            std::vector<int32> ArchivedMissions;
        };

        struct FollowerSoftCapInfo
        {
            int32 GarrFollowerTypeID;
            uint32 Count;
        };

        class GetGarrisonInfoResult final : public ServerPacket
        {
        public:
            GetGarrisonInfoResult() : ServerPacket(SMSG_GET_GARRISON_INFO_RESULT) { }

            WorldPacket const* Write() override;

            uint32 FactionIndex = 0;
            std::vector<GarrisonInfo> Garrisons;
            std::vector<FollowerSoftCapInfo> FollowerSoftCaps;
        };

        struct GarrisonRemoteBuildingInfo
        {
            GarrisonRemoteBuildingInfo() : GarrPlotInstanceID(0), GarrBuildingID(0) { }
            GarrisonRemoteBuildingInfo(uint32 plotInstanceId, uint32 buildingId) : GarrPlotInstanceID(plotInstanceId), GarrBuildingID(buildingId) { }

            uint32 GarrPlotInstanceID;
            uint32 GarrBuildingID;
        };

        struct GarrisonRemoteSiteInfo
        {
            uint32 GarrSiteLevelID = 0;
            std::vector<GarrisonRemoteBuildingInfo> Buildings;
        };

        class GarrisonRemoteInfo final : public ServerPacket
        {
        public:
            GarrisonRemoteInfo() : ServerPacket(SMSG_GARRISON_REMOTE_INFO) { }

            WorldPacket const* Write() override;

            std::vector<GarrisonRemoteSiteInfo> Sites;
        };

        class GarrisonPurchaseBuilding final : public ClientPacket
        {
        public:
            GarrisonPurchaseBuilding(WorldPacket&& packet) : ClientPacket(CMSG_GARRISON_PURCHASE_BUILDING, std::move(packet)) { }

            void Read() override;

            ObjectGuid NpcGUID;
            uint32 BuildingID = 0;
            uint32 PlotInstanceID = 0;
        };

        class GarrisonPlaceBuildingResult final : public ServerPacket
        {
        public:
            GarrisonPlaceBuildingResult() : ServerPacket(SMSG_GARRISON_PLACE_BUILDING_RESULT) { }

            WorldPacket const* Write() override;

            int32 GarrTypeID = 0;
            uint32 Result = 0;
            GarrisonBuildingInfo BuildingInfo;
            bool PlayActivationCinematic = false;
        };

        class GarrisonCancelConstruction final : public ClientPacket
        {
        public:
            GarrisonCancelConstruction(WorldPacket&& packet) : ClientPacket(CMSG_GARRISON_CANCEL_CONSTRUCTION, std::move(packet)) { }

            void Read() override;

            ObjectGuid NpcGUID;
            uint32 PlotInstanceID = 0;
        };

        class GarrisonBuildingRemoved final : public ServerPacket
        {
        public:
            GarrisonBuildingRemoved() : ServerPacket(SMSG_GARRISON_BUILDING_REMOVED, 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            int32 GarrTypeID = 0;
            uint32 Result = 0;
            uint32 GarrPlotInstanceID = 0;
            uint32 GarrBuildingID = 0;
        };

        class GarrisonLearnBlueprintResult final : public ServerPacket
        {
        public:
            GarrisonLearnBlueprintResult() : ServerPacket(SMSG_GARRISON_LEARN_BLUEPRINT_RESULT, 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            int32 GarrTypeID = 0;
            uint32 BuildingID = 0;
            uint32 Result = 0;
        };

        class GarrisonUnlearnBlueprintResult final : public ServerPacket
        {
        public:
            GarrisonUnlearnBlueprintResult() : ServerPacket(SMSG_GARRISON_UNLEARN_BLUEPRINT_RESULT, 4 + 4) { }

            WorldPacket const* Write() override;

            int32 GarrTypeID = 0;
            uint32 BuildingID = 0;
            uint32 Result = 0;
        };

        class GarrisonRequestBlueprintAndSpecializationData final : public ClientPacket
        {
        public:
            GarrisonRequestBlueprintAndSpecializationData(WorldPacket&& packet) : ClientPacket(CMSG_GARRISON_REQUEST_BLUEPRINT_AND_SPECIALIZATION_DATA, std::move(packet)) { }

            void Read() override { }
        };

        class GarrisonRequestBlueprintAndSpecializationDataResult final : public ServerPacket
        {
        public:
            GarrisonRequestBlueprintAndSpecializationDataResult() : ServerPacket(SMSG_GARRISON_REQUEST_BLUEPRINT_AND_SPECIALIZATION_DATA_RESULT, 400) { }

            WorldPacket const* Write() override;

            int32 GarrTypeID = 0;
            std::unordered_set<uint32> const* SpecializationsKnown = nullptr;
            std::unordered_set<uint32> const* BlueprintsKnown = nullptr;
        };

        class GarrisonGetMapData final : public ClientPacket
        {
        public:
            GarrisonGetMapData(WorldPacket&& packet) : ClientPacket(CMSG_GARRISON_GET_MAP_DATA, std::move(packet)) { }

            void Read() override { }
        };

        struct GarrisonBuildingMapData
        {
            GarrisonBuildingMapData() : GarrBuildingPlotInstID(0), Pos() { }
            GarrisonBuildingMapData(uint32 buildingPlotInstId, Position const& pos) : GarrBuildingPlotInstID(buildingPlotInstId), Pos(pos) { }

            uint32 GarrBuildingPlotInstID;
            TaggedPosition<Position::XYZ> Pos;
        };

        class GarrisonMapDataResponse final : public ServerPacket
        {
        public:
            GarrisonMapDataResponse() : ServerPacket(SMSG_GARRISON_MAP_DATA_RESPONSE) { }

            WorldPacket const* Write() override;

            std::vector<GarrisonBuildingMapData> Buildings;
        };

        class GarrisonPlotPlaced final : public ServerPacket
        {
        public:
            GarrisonPlotPlaced() : ServerPacket(SMSG_GARRISON_PLOT_PLACED) { }

            WorldPacket const* Write() override;

            int32 GarrTypeID = 0;
            GarrisonPlotInfo* PlotInfo = nullptr;
        };

        class GarrisonPlotRemoved final : public ServerPacket
        {
        public:
            GarrisonPlotRemoved() : ServerPacket(SMSG_GARRISON_PLOT_REMOVED, 4) { }

            WorldPacket const* Write() override;

            uint32 GarrPlotInstanceID = 0;
        };

        class GarrisonAddFollowerResult final : public ServerPacket
        {
        public:
            GarrisonAddFollowerResult() : ServerPacket(SMSG_GARRISON_ADD_FOLLOWER_RESULT, 8 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 4 + 5 * 4 + 4) { }

            WorldPacket const* Write() override;

            int32 GarrTypeID = 0;
            GarrisonFollower Follower;
            uint32 Result = 0;
        };

        class GarrisonRemoveFollowerResult final : public ServerPacket
        {
        public:
            GarrisonRemoveFollowerResult() : ServerPacket(SMSG_GARRISON_REMOVE_FOLLOWER_RESULT, 8 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            uint64 FollowerDBID = 0;
            int32 GarrTypeID = 0;
            uint32 Result = 0;
            uint32 Destroyed = 0;
        };

        class GarrisonBuildingActivated final : public ServerPacket
        {
        public:
            GarrisonBuildingActivated() : ServerPacket(SMSG_GARRISON_BUILDING_ACTIVATED, 4) { }

            WorldPacket const* Write() override;

            uint32 GarrPlotInstanceID = 0;
        };

        class GarrisonAssignFollowerToBuilding final : public ClientPacket
        {
        public:
            GarrisonAssignFollowerToBuilding(WorldPacket && packet) : ClientPacket(CMSG_GARRISON_ASSIGN_FOLLOWER_TO_BUILDING, std::move(packet)) { }
            
            void Read() override;
            
            ObjectGuid NpcGUID;
            uint32 PlotInstanceID;
            uint64 FollowerDBID;
        };

        class GarrisonAddMissionResult final : public ServerPacket
        {
        public:
            GarrisonAddMissionResult() : ServerPacket(SMSG_GARRISON_ADD_MISSION_RESULT, 4) { }

            uint32 GarrType = 0;
            uint32 Result = 0;
            uint8 State = 0;
            GarrisonMission Mission;

            std::vector<GarrisonMissionReward> Rewards;
            std::vector<GarrisonMissionReward> BonusRewards;

            bool Success = true;

            WorldPacket const* Write() override;
        };

        class GarrisonCompleteMissionResult final : public ServerPacket
        {
        public:
            GarrisonCompleteMissionResult() : ServerPacket(SMSG_GARRISON_COMPLETE_MISSION_RESULT, 4) { }

            uint32 Result = 0;
            GarrisonMission Mission;
            std::map<uint64 /*followerDBID*/, uint32 /*unk*/> Followers;
            bool Succeed = false;

            WorldPacket const* Write() override;
        };

        class GarrisonFollowerChangeXP final : public ServerPacket
        {
        public:
            GarrisonFollowerChangeXP() : ServerPacket(SMSG_GARRISON_FOLLOWER_CHANGED_XP, 4) { }

            uint32 XP = 0;
            uint32 Unk = 0;
            GarrisonFollower OldFollower;
            GarrisonFollower NewFollower;

            WorldPacket const* Write() override;
        };

        class GarrisonMissionBonusRollResult final : public ServerPacket
        {
        public:
            GarrisonMissionBonusRollResult() : ServerPacket(SMSG_GARRISON_MISSION_BONUS_ROLL_RESULT, 4) { }

            GarrisonMission Mission;
            uint32 Result = 0;

            WorldPacket const* Write() override;
        };

        class GarrisonOpenMissionNpc final : public ServerPacket
        {
        public:
            GarrisonOpenMissionNpc() : ServerPacket(SMSG_GARRISON_OPEN_MISSION_NPC, 4) { }

            WorldPacket const* Write() override;

            uint32 garrType = 3;
            uint32 result = 0;
            std::vector<uint32 /* dbID */> Missions;
            bool   unk4 = false;
            bool   preventXmlOpenMissionEvent = false;
        };

        class GarrisonRecruitFollowerResult final : public ServerPacket
        {
        public:
            GarrisonRecruitFollowerResult() : ServerPacket(SMSG_GARRISON_RECRUIT_FOLLOWER_RESULT, 64) { }

            uint32 resultID = 0;
            std::vector <GarrisonFollower> followers;

            WorldPacket const* Write() override;
        };

        WorldPacket InsertGarrisonFollower(WorldPacket& worldPacke, WorldPackets::Garrison::GarrisonFollower follower);

        class GarrisonOpenRecruitmentNpc final : public ServerPacket
        {
        public:
            GarrisonOpenRecruitmentNpc() : ServerPacket(SMSG_GARRISON_OPEN_RECRUITMENT_NPC, 4) { }

            ObjectGuid NpcGUID;
            uint32 Unk1 = 0;
            //uint32 Unk2 = 0;
            //uint32 Unk3 = 0;
            std::vector <GarrisonFollower> followers;
            bool CanRecruitFollower = false;
            bool Unk4 = false;
            WorldPacket const* Write() override;
        };
    }
}

#endif // GarrisonPackets_h__
