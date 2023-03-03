/*
* Copyright (C) 2021 BfaCore Reforged
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

#ifndef ANTORUS_THE_BURNING_THRONE_H
#define ANTORUS_THE_BURNING_THRONE_H

#define DataHeader "ATBT"

enum DataTypes
{
    DATA_GAROTHI_WORLDBREAKER = 0,
    DATA_FHARG = 1,
    DATA_ADMIRAL_SVIRAX = 2,
    DATA_PORTAL_KEEPER_HASABEL = 3,
    DATA_ESSENCE_OF_EONAR = 4,
    DATA_IMONAR_THE_SOULHUNTER = 5,
    DATA_KINGAROTH = 6,
    DATA_VARIMATHRAS = 7,
    DATA_NOURA_MOTHER_OF_FLAMES = 8,
    DATA_AGGRAMAR = 9,
    DATA_ARGUS_THE_UNMAKER = 10,
    DATA_SHATUG,
    DATA_DECIMATOR,
    DATA_ANNIHILATOR,
    DATA_ANNIHILATION,
    DATA_ASARA_MOTHER_OF_NIGHT,
    DATA_DIIMA_MOTHER_OF_GLOOM,
    DATA_THURAYA_MOTHER_OF_THE_COSMOS,
    DATA_MAX_ENCOUNTERS,
};

enum Creatures
{
    BOSS_GAROTHI_WORLDBREAKER = 122450,
    NPC_FHARG = 122477,
    NPC_ADMIRAL_SVIRAX = 122367,
    NPC_PORTAL_KEEPER_HASABEL = 122104,
    NPC_ESSENCE_OF_EONAR = 122500,
    NPC_IMONAR_THE_SOULHUNTER = 124158,
    NPC_KINGAROTH = 122578,
    NPC_VARIMATHRAS = 122366,
    NPC_NOURA_MOTHER_OF_FLAMES = 122468,
    NPC_AGGRAMAR = 121975,
    NPC_ARGUS_THE_UNMAKER = 124828,
    //1 boss mobs
    NPC_ANNIHILATOR = 122778,
    NPC_DECIMATOR = 122773,
    NPC_ANNIHILATION = 122818,
    NPC_GAROTHI_WORLDBREAKER = 124167,
    //2 boss
    NPC_SHATUG = 122135,
    //3 boss
    //MOTHER_OF_FLAMES
    NPC_ASARA_MOTHER_OF_NIGHT = 122467,
    NPC_DIIMA_MOTHER_OF_GLOOM = 122469,
    NPC_THURAYA_MOTHER_OF_THE_COSMOS = 125436,
};

enum CosmeticSpells
{

};

enum Gameobjects
{

    GO_DOOR_1 = 277365,
    GO_DOOR_2 = 278488,
    GO_DOOR_3 = 277359,
    GO_DOOR_4 = 277358,

    GO_BOSS4_BOX = 276503,
    GO_BOSS6_1 = 249386,
    GO_BOSS6_2 = 273911,

    GO_BOSS7_1 = 272485,

    GO_BOSS9_1 = 277476,
    GO_BOSS9_2 = 272486,
    GO_BOSS10 = 273686,
    GO_BOSS_VARIMATHRAS = 277180,
    GO_DOOR_PORTAL_KEEPER_HASABEL = 277521,
};

#endif // ANTORUS_THE_BURNING_THRONE_H
