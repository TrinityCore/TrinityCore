/*
 * Copyright (C) 2022 BfaCore Reforged
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

#ifndef DEF_SEAT_OF_TRIUMVIRATE_H
#define DEF_SEAT_OF_TRIUMVIRATE_H

#define SoTScriptName "instance_seat_of_triumvirate"
#define DataHeader    "SOT"

uint32 const EncounterCount = 4;

enum SOTDataTypes
{
    DATA_ZURAAL_THE_ASCENDED    = 0,
    DATA_SAPRISH                = 1,
    DATA_VICEROY_NEZHAR         = 2,
    DATA_LURA                   = 3
};

enum SOTCreatureIds
{
    NPC_ZURAAL_THE_ASCENDED = 122313,
    NPC_SAPRISH             = 122316,
    NPC_VICEROY_NEZHAR      = 124309,
    NPC_LURA                = 122314,

    NPC_LURA_DOOR           = 125104,
};

enum SOTSpells
{
    SPELL_PHYSICAL_REALM    = 244074,
};

enum GameObjectIds
{
    GO_DOOR_ROOM_ZURAAL_THE_ASCENDED = 273789, //boos1
    GO_DOOR_ROOM_VICEROY_NEZHAR = 272062, //boos3
};

#endif // DEF_SEAT_OF_TRIUMVIRATE_H
