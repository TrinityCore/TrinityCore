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

#include "highmaul.h"
#include "InstanceScript.h"
#include "Group.h"
#include "WorldStatePackets.h"

DoorData const g_DoorData[] =
{
    { eHighmaulGameobjects::GateArenaExit,      eHighmaulDatas::BossKargathBladefist,   DoorType::DOOR_TYPE_PASSAGE     },
    { eHighmaulGameobjects::EarthenPillar,      eHighmaulDatas::BossTheButcher,         DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::FungalGiantDoor,    eHighmaulDatas::BossTheButcher,         DoorType::DOOR_TYPE_PASSAGE     },
    { eHighmaulGameobjects::WindDoor,           eHighmaulDatas::BossTheButcher,         DoorType::DOOR_TYPE_PASSAGE     },
    { eHighmaulGameobjects::WindDoor,           eHighmaulDatas::BossBrackenspore,       DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::Earthwall1,         eHighmaulDatas::BossTectus,             DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::Earthwall2,         eHighmaulDatas::BossTectus,             DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::Earthwall3,         eHighmaulDatas::BossTectus,             DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::Earthwall4,         eHighmaulDatas::BossTectus,             DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::HighmaulLFRDoor,    eHighmaulDatas::BossTectus,             DoorType::DOOR_TYPE_PASSAGE     },
    { eHighmaulGameobjects::TwinOgronEntrance,  eHighmaulDatas::BossTwinOgron,          DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::TwinOgronExit,      eHighmaulDatas::BossTwinOgron,          DoorType::DOOR_TYPE_PASSAGE     },
    { eHighmaulGameobjects::FelBreakerEntrance, eHighmaulDatas::BossKoragh,             DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::FelBreakerExitDoor, eHighmaulDatas::BossKoragh,             DoorType::DOOR_TYPE_PASSAGE     },
    { eHighmaulGameobjects::ThroneRoomDoor,     eHighmaulDatas::BossImperatorMargok,    DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::StairBlockingDoor,  eHighmaulDatas::BossImperatorMargok,    DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::StairBlockingDoor,  eHighmaulDatas::BossImperatorMargok,    DoorType::DOOR_TYPE_ROOM        },
    { eHighmaulGameobjects::StairBlockingDoor,  eHighmaulDatas::BossImperatorMargok,    DoorType::DOOR_TYPE_ROOM        },
    { 0,                                        0,                                      DoorType::DOOR_TYPE_ROOM        } ///< End
};

void AddSC_instance_highmaul()
{
  
}
