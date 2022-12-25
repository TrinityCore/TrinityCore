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

#include "trial_of_valor.h"
#include "GameObject.h"
#include "WorldPacket.h"
#include "InstancePackets.h"

DoorData const doorData[] =
{
    { Data::GameObjects::GoGarmDoor,    Data::BossIDs::GarmID,      DOOR_TYPE_ROOM },
    { Data::GameObjects::GoGarmDoor2,   Data::BossIDs::GarmID,      DOOR_TYPE_PASSAGE },
    { Data::GameObjects::GoOdynDoor,    Data::BossIDs::OdynID,      DOOR_TYPE_ROOM },
    { Data::GameObjects::GoGarmDoor2,   Data::BossIDs::HelyaID,     DOOR_TYPE_ROOM },
    { 0,                                0,                          DOOR_TYPE_ROOM }
};

ObjectData const creatureData[] =
{
    { Data::Creatures::Odyn,            Data::BossIDs::OdynID   },
    { Data::Creatures::Guarm,           Data::BossIDs::GarmID   },
    { Data::Creatures::Helya,           Data::BossIDs::HelyaID  },
    { 0,                                                    0   } // END
};

ObjectData const objectData[] =
{
    { 0,                    0, }
};

void AddSC_instance_trial_of_valor()
{
  
}
