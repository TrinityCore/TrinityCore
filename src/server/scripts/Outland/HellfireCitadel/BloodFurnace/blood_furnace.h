/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef BLOOD_FURNACE_H_
#define BLOOD_FURNACE_H_

#define BFScriptName "instance_blood_furnace"
#define DataHeader   "BF"

uint32 const EncounterCount = 3;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_THE_MAKER              = 0,
    DATA_BROGGOK                = 1,
    DATA_KELIDAN_THE_BREAKER    = 2,

    // Additional Data
    DATA_DOOR_4                 = 3,
    DATA_PRISON_CELL1           = 4,
    DATA_PRISON_CELL2           = 5,
    DATA_PRISON_CELL3           = 6,
    DATA_PRISON_CELL4           = 7,
    DATA_PRISON_CELL5           = 8,
    DATA_PRISON_CELL6           = 9,
    DATA_PRISON_CELL7           = 10,
    DATA_PRISON_CELL8           = 11,
    DATA_BROGGOK_LEVER          = 12
};

enum CreatureIds
{
    NPC_THE_MAKER               = 17381,
    NPC_BROGGOK                 = 17380,
    NPC_KELIDAN_THE_BREAKER     = 17377,
    NPC_PRISONER                = 17398,
    NPC_BROGGOK_POISON_CLOUD    = 17662
};

enum GameObjectIds
{
    GO_PRISON_DOOR_01           = 181766, // Final Exit Door
    GO_PRISON_DOOR_02           = 181811, // The Maker Front Door
    GO_PRISON_DOOR_03           = 181812, // The Maker Rear Door
    GO_PRISON_DOOR_04           = 181819, // Broggok Rear Door
    GO_PRISON_DOOR_05           = 181822, // Broggok Front Door
    GO_SUMMON_DOOR              = 181823, // Kelidan Exit Door

    GO_PRISON_CELL_DOOR_1       = 181813, // The Maker Prison Cell front right
    GO_PRISON_CELL_DOOR_2       = 181814, // The Maker Prison Cell back right
    GO_PRISON_CELL_DOOR_3       = 181816, // The Maker Prison Cell front left
    GO_PRISON_CELL_DOOR_4       = 181815, // The Maker Prison Cell back left
    GO_PRISON_CELL_DOOR_5       = 181821, // Broggok Prison Cell front right
    GO_PRISON_CELL_DOOR_6       = 181818, // Broggok Prison Cell back right
    GO_PRISON_CELL_DOOR_7       = 181820, // Broggok Prison Cell front left
    GO_PRISON_CELL_DOOR_8       = 181817, // Broggok Prison Cell back left

    GO_BROGGOK_LEVER            = 181982
};

enum ActionIds
{
    ACTION_ACTIVATE_BROGGOK     = 1,
    ACTION_RESET_BROGGOK        = 2,
    ACTION_PREPARE_BROGGOK      = 3
};

template<class AI>
AI* GetBloodFurnaceAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, BFScriptName);
}

#endif // BLOOD_FURNACE_H_

