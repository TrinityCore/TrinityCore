/*
 * Copyright 2023 AzgathCore
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

#include "boss_iron_maidens.h"
#include "blackrock_foundry.h"
#include "DB2Stores.h"
#include  "CriteriaHandler.h"
#include "LFGMgr.h"

DoorData const g_DoorData[] =
{
    { eFoundryGameObjects::GruulSpikeDoor,              eFoundryDatas::DataGruul,               DoorType::DOOR_TYPE_ROOM },
    { eFoundryGameObjects::BKFoundrySpikeTrapGate,      eFoundryDatas::DataOregorger,           DoorType::DOOR_TYPE_ROOM},
    { eFoundryGameObjects::FurnacePortcullis,           eFoundryDatas::DataOregorger,           DoorType::DOOR_TYPE_PASSAGE},
    { eFoundryGameObjects::BlastFurnaceEncounterDoor,   eFoundryDatas::DataBlastFurnace,        DoorType::DOOR_TYPE_ROOM},
    { eFoundryGameObjects::HansgarAndFranzokEntrance,   eFoundryDatas::DataHansgarAndFranzok,   DoorType::DOOR_TYPE_ROOM },
    { eFoundryGameObjects::HansgarAndFranzokExit,       eFoundryDatas::DataHansgarAndFranzok,   DoorType::DOOR_TYPE_PASSAGE },
    { eFoundryGameObjects::FirewallDoor,                eFoundryDatas::DataFlamebenderKagraz,   DoorType::DOOR_TYPE_ROOM },
    { eFoundryGameObjects::BurningFrontDoor,            eFoundryDatas::DataFlamebenderKagraz,   DoorType::DOOR_TYPE_PASSAGE },
    { eFoundryGameObjects::KromogsDoorSouth,            eFoundryDatas::DataKromog,              DoorType::DOOR_TYPE_ROOM },
    { eFoundryGameObjects::KromogsDoorEast,             eFoundryDatas::DataKromog,              DoorType::DOOR_TYPE_PASSAGE },
    { eFoundryGameObjects::BlackForgePortcullis,        eFoundryDatas::DataKromog,              DoorType::DOOR_TYPE_PASSAGE },
    { eFoundryGameObjects::BlackForgeGate,              eFoundryDatas::DataKromog,              DoorType::DOOR_TYPE_PASSAGE },
    { eFoundryGameObjects::KromogDoor,                  eFoundryDatas::DataKromog,              DoorType::DOOR_TYPE_PASSAGE },
    { eFoundryGameObjects::TheBeastGate,                eFoundryDatas::DataBeastlordDarmac,     DoorType::DOOR_TYPE_ROOM },
    { eFoundryGameObjects::TerminusDoor,                eFoundryDatas::DataBeastlordDarmac,     DoorType::DOOR_TYPE_PASSAGE },
    { eFoundryGameObjects::FreightElevatorDoor,         eFoundryDatas::DataOperatorThogar,      DoorType::DOOR_TYPE_PASSAGE },
    { eFoundryGameObjects::IronMaidensRampDoor,         eFoundryDatas::DataIronMaidens,         DoorType::DOOR_TYPE_ROOM },
    { eFoundryGameObjects::IronMaidensExitDoor,         eFoundryDatas::DataIronMaidens,         DoorType::DOOR_TYPE_ROOM },
    { eFoundryGameObjects::BlackhandsGate,              eFoundryDatas::DataBlackhand,           DoorType::DOOR_TYPE_ROOM },
    { 0,                                                0,                                      DoorType::DOOR_TYPE_ROOM } ///< End
};

void AddSC_instance_blackrock_foundry()
{
   
}
