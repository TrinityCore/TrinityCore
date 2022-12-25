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

#ifndef HELLFIRE_CITADEL_H
#define HELLFIRE_CITADEL_H
#define DataHeader "HELLFIRE_CITADEL"

enum DataTypes
{
    DATA_IRON_REAVER,
    DATA_SIEGEMASTER_MARTAK,
    DATA_GOREFIEND,
    DATA_FEL_LORD_ZAKUUN,
    DATA_TYRANT_VELHARI,
    DATA_MANNOROTH,
    DATA_KILROGG_DEADEYE,    
    DATA_SOULBOUND_CONSTRUCT,
    DATA_GURTOGG_BLOODBOIL,
    DATA_HELLFIRE_ARCHIMONDE,
    DATA_XHULHORAC,
    DATA_HELLFIRE_KORMROK,
    DATA_SHADOW_LORD_ISKAR,
    DATA_MAX_ENCOUNTERS
};
enum Creatures
{
    NPC_IRON_REAVER = 90284,
    NPC_SIEGEMASTER_MARTAK = 93023,
    NPC_GOREFIEND = 90199,
    NPC_FEL_LORD_ZAKUUN = 89890,
    NPC_TYRANT_VELHARI = 90269,
    NPC_MANNOROTH = 91349,
    NPC_KILROGG_DEADEYE = 90378,   
    NPC_SOULBOUND_CONSTRUCT = 90296,
    NPC_GURTOGG_BLOODBOIL = 92146,
    NPC_HELLFIRE_ARCHIMONDE = 91331,
    NPC_XHULHORAC = 93068,
    NPC_HELLFIRE_KORMROK = 90435,
    NPC_SHADOW_LORD_ISKAR = 90316,
};
enum Gameobjects
{
    GO_SIEGEMASTER_MARTAK_DOOR_2 = 242454,
    GO_SIEGEMASTER_MARTAK_DOOR_1 = 242464,
    GO_FEL_LORD_ZAKUUN_DOOR_1 = 242510,
    GO_FEL_LORD_ZAKUUN_DOOR_2 = 240687,
    GO_HELLFIRE_ARCHIMONDE_DOOR_1 = 241485,
    GO_SOULBOUND_CONSTRUCT_DOOR_1 = 242362,
    GO_SOULBOUND_CONSTRUCT_DOOR_2 = 242363,
    GO_SOULBOUND_CONSTRUCT_DOOR_3 = 242360,
    GO_SOULBOUND_CONSTRUCT_DOOR_4 = 242361,
    GO_TYRANT_VELHARI_DOOR_1 = 241649,
    GO_TYRANT_VELHARI_DOOR_2 = 241650,
    GO_TYRANT_VELHARI_DOOR_3 = 242359,
    GO_TYRANT_VELHARI_DOOR_4 = 242358,
    GO_SHADOW_LORD_ISKAR_DOOR_1 = 243183,
    GO_SHADOW_LORD_ISKAR_DOOR_2 = 242419,
    GO_SHADOW_LORD_ISKAR_DOOR_3 = 242280,
    GO_SHADOW_LORD_ISKAR_DOOR_4 = 243482,
};
#endif // HELLFIRE_CITADEL_H
