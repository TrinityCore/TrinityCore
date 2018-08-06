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

#include "WorldSession.h"
#include "WodGarrison.h"
#include "ClassHall.h"
#include "GarrisonAI.h"
#include "GarrisonMgr.h"
#include "GarrisonPackets.h"
#include "ObjectMgr.h"
#include "Player.h"

void WorldSession::HandleGetGarrisonInfo(WorldPackets::Garrison::GetGarrisonInfo& /*getGarrisonInfo*/)
{
    _player->SendGarrisonInfo();
}

void WorldSession::HandleGarrisonPurchaseBuilding(WorldPackets::Garrison::GarrisonPurchaseBuilding& garrisonPurchaseBuilding)
{
    if (!_player->GetNPCIfCanInteractWith(garrisonPurchaseBuilding.NpcGUID, UNIT_NPC_FLAG_GARRISON_ARCHITECT))
        return;

    if (Garrison* garrison = _player->GetGarrison(GARRISON_TYPE_GARRISON))
        garrison->ToWodGarrison()->PlaceBuilding(garrisonPurchaseBuilding.PlotInstanceID, garrisonPurchaseBuilding.BuildingID);
}

void WorldSession::HandleGarrisonCancelConstruction(WorldPackets::Garrison::GarrisonCancelConstruction& garrisonCancelConstruction)
{
    if (!_player->GetNPCIfCanInteractWith(garrisonCancelConstruction.NpcGUID, UNIT_NPC_FLAG_GARRISON_ARCHITECT))
        return;

    if (Garrison* garrison = _player->GetGarrison(GARRISON_TYPE_GARRISON))
        garrison->ToWodGarrison()->CancelBuildingConstruction(garrisonCancelConstruction.PlotInstanceID);
}

void WorldSession::HandleGarrisonCheckUpgradeable(WorldPackets::Garrison::GarrisonCheckUpgradeable& /*garrisonCheckUpgradeable*/)
{
    bool canUpgrade = false;
    if (Garrison* garrison = _player->GetGarrison(GARRISON_TYPE_GARRISON))
        canUpgrade = garrison->ToWodGarrison()->CanUpgrade(false);

    SendPacket(WorldPackets::Garrison::GarrisonCheckUpgradeableResult(canUpgrade).Write());
}

void WorldSession::HandleGarrisonUpgrade(WorldPackets::Garrison::GarrisonUpgrade& garrisonUpgrade)
{
    if (!_player->GetNPCIfCanInteractWith(garrisonUpgrade.NpcGUID, UNIT_NPC_FLAG_GARRISON_ARCHITECT))
        return;

    if (Garrison* garrison = _player->GetGarrison(GARRISON_TYPE_GARRISON))
    {
        /*bool result = */garrison->ToWodGarrison()->Upgrade();
        //SendPacket(WorldPackets::Garrison::GarrisonUpgradeResult().Write());
    }
}

void WorldSession::HandleGarrisonRequestBlueprintAndSpecializationData(WorldPackets::Garrison::GarrisonRequestBlueprintAndSpecializationData& /*garrisonRequestBlueprintAndSpecializationData*/)
{
    _player->SendGarrisonBlueprintAndSpecializationData();
}

void WorldSession::HandleGarrisonGetBuildingLandmarks(WorldPackets::Garrison::GarrisonGetBuildingLandmarks& /*garrisonGetBuildingLandmarks*/)
{
    if (Garrison* garrison = _player->GetGarrison(GARRISON_TYPE_GARRISON))
        garrison->ToWodGarrison()->SendBuildingLandmarks(_player);
}

void WorldSession::HandleGarrisonOpenMissionNpc(WorldPackets::Garrison::GarrisonOpenMissionNpcClient& garrisonOpenMissionNpcClient)
{
    if (!_player->GetNPCIfCanInteractWith(garrisonOpenMissionNpcClient.NpcGUID, UNIT_NPC_FLAG_GARRISON_MISSION_NPC))
        return;

    GarrisonType garType = GARRISON_TYPE_CLASS_HALL; // Todo : differenciate depending of NPC

    Garrison const* garrison = _player->GetGarrison(garType);

    if (!garrison)
        return;

    if (garType == GARRISON_TYPE_CLASS_HALL)
    {
        SendPacket(WorldPackets::Garrison::ShowAdventureMap(garrisonOpenMissionNpcClient.NpcGUID).Write());
    }
    else
    {
        WorldPackets::Garrison::GarrisonOpenMissionNpc garrisonOpenMissionNpc;
        for (auto const& p : garrison->GetMissions())
        {
            garrisonOpenMissionNpc.Missions.push_back(p.first);
        }
        SendPacket(garrisonOpenMissionNpc.Write());
    }
}

void WorldSession::HandleGarrisonRequestScoutingMap(WorldPackets::Garrison::GarrisonRequestScoutingMap& scoutingMap)
{
    WorldPackets::Garrison::GarrisonScoutingMapResult result;
    result.ID = scoutingMap.ID;
    result.Active = true;
    SendPacket(result.Write());
}

void WorldSession::HandleGarrisonStartMission(WorldPackets::Garrison::GarrisonStartMission& startMission)
{
    if (!_player->GetNPCIfCanInteractWith(startMission.NpcGUID, UNIT_NPC_FLAG_GARRISON_MISSION_NPC))
        return;

    GarrMissionEntry const* missionEntry = sGarrMissionStore.LookupEntry(startMission.MissionID);
    if (!missionEntry)
        return;

    Garrison* garrison = _player->GetGarrison(GarrisonType(missionEntry->GarrTypeID));
    if (!garrison)
        return;

    garrison->StartMission(startMission.MissionID, startMission.Followers);
}

void WorldSession::HandleGarrisonCompleteMission(WorldPackets::Garrison::GarrisonCompleteMission& completeMission)
{
    if (!_player->GetNPCIfCanInteractWith(completeMission.NpcGUID, UNIT_NPC_FLAG_GARRISON_MISSION_NPC))
        return;

    GarrMissionEntry const* missionEntry = sGarrMissionStore.LookupEntry(completeMission.MissionID);
    if (!missionEntry)
        return;

    Garrison* garrison = _player->GetGarrison(GarrisonType(missionEntry->GarrTypeID));
    if (!garrison)
        return;

    garrison->CompleteMission(completeMission.MissionID);
}

void WorldSession::HandleGarrisonMissionBonusRoll(WorldPackets::Garrison::GarrisonMissionBonusRoll& missionBonusRoll)
{
    if (!_player->GetNPCIfCanInteractWith(missionBonusRoll.NpcGUID, UNIT_NPC_FLAG_GARRISON_MISSION_NPC))
        return;

    GarrMissionEntry const* missionEntry = sGarrMissionStore.LookupEntry(missionBonusRoll.MissionID);
    if (!missionEntry)
        return;

    Garrison* garrison = _player->GetGarrison(GarrisonType(missionEntry->GarrTypeID));
    if (!garrison)
        return;

    garrison->CalculateMissonBonusRoll(missionBonusRoll.MissionID);
}
