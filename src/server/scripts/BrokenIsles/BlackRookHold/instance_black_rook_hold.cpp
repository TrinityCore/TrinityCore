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

#include "black_rook_hold.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    {GO_AMALGAM_DOOR_1,         DATA_AMALGAM,           DOOR_TYPE_ROOM},
    {GO_AMALGAM_DOOR_2,         DATA_AMALGAM,           DOOR_TYPE_ROOM},
    {GO_AMALGAM_DOOR_3,         DATA_AMALGAM,           DOOR_TYPE_ROOM},
    {GO_AMALGAM_DOOR_4,         DATA_AMALGAM,           DOOR_TYPE_ROOM},
    {GO_ILLYSANNA_DOOR_1,       DATA_ILLYSANNA,         DOOR_TYPE_PASSAGE},
    {GO_ILLYSANNA_DOOR_2,       DATA_ILLYSANNA,         DOOR_TYPE_PASSAGE},
    {GO_ILLYSANNA_DOOR_3,       DATA_ILLYSANNA,         DOOR_TYPE_ROOM},
    {GO_SMASHSPITE_DOOR,        DATA_SMASHSPITE,        DOOR_TYPE_ROOM},
    {GO_SMASH_KURT_DOOR_1,      DATA_SMASHSPITE,        DOOR_TYPE_PASSAGE},
    {GO_SMASH_KURT_DOOR_2,      DATA_SMASHSPITE,        DOOR_TYPE_PASSAGE},
    {GO_KURTALOS_DOOR,          DATA_KURTALOS,          DOOR_TYPE_ROOM},
};

void AddSC_instance_black_rook_hold()
{
  
}
