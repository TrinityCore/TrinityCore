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

#ifndef DEF_VAULT_OF_THE_WARDENS_H
#define DEF_VAULT_OF_THE_WARDENS_H

enum eData
{
    DATA_SALTHERIL = 0,
    DATA_TORMENTORUM = 1,
    DATA_ASHGOLM = 2,
    DATA_GLAZER = 3,
    DATA_CORDANA_SPIRIT = 4,
    DATA_CORDANA = 5,
    MAX_ENCOUNTER,

    DATA_ASHGOLM_SYSTEM,
    DATA_CORDANA_ACTIONS
};

enum eCreatures
{
    //Tirathon
    NPC_TIRATHON_SALTHERIL = 95885,
    NPC_TIRATHON_BEAM_TARGET = 96241,

    //Inquisitor
    NPC_SHADOWMOON_WARLOCK = 99704, //Orks
    NPC_FELGUARD_ANNIHILATOR = 99644, //Orks
    NPC_SHADOWMOON_TECHNICIAN = 99645, //Orks
    NPC_ENORMOUS_STONE_QUILEN = 99675, //Mogu
    NPC_MOGUSHAN_SECRET_KEEPER = 99676, //Mogu
    NPC_VOID_TOUCHED_JUGGERNAUT = 99655, //Void
    NPC_DERANGED_MINDFLAYER = 99657, //Void
    NPC_FACELESS_VOIDCASTER = 99651, //Void
    NPC_LINGERING_CORRUPTION = 99678, //Corruption

    //Ashgolm
    NPC_EMBER = 99233,
    NPC_COUNTERMEASURES = 99240,

    //Glazer
    NPC_GLAZER = 95887,
    NPC_GLAZER_BEAM = 102310,
    NPC_LENS = 98082,
    NPC_BEAM_TARGET_TRIGGER = 98118,

    NPC_SPIRIT_OF_VENGEANCE = 100364,

    //Cordana
    NPC_CORDANA = 95888,
    NPC_GLOWING_SENTRY = 100525,
    NPC_AVATAR_OF_SHADOW = 104293,
    NPC_ELUNES = 103342,
};

enum eGameObjects
{
    GO_SALTHERIL_DOOR_1 = 246055,
    GO_SALTHERIL_DOOR_2 = 246054,
    GO_SALTHERIL_DOOR_3 = 246053,
    GO_SALTHERIL_DOOR_4 = 247081,
    GO_SALTHERIL_DOOR_5 = 247082,
    GO_TORMENTORUM_DOOR_1 = 246112,
    GO_ASHGOLM_PLATFORM = 246418,
    GO_ASHGOLM_BRIDGE = 246057,
    GO_GLAZER_BRIDGE = 246727,
    GO_CORDANA_DOOR = 246049,

    //Ashgolm
    GO_ASHGOLM_VOLCANO = 247010,

    //Torment cages
    GO_CAGE_1 = 246506, //Orks
    GO_CAGE_2 = 246507,
    GO_CAGE_3 = 246508,
    GO_CAGE_4 = 246509, //Mogu
    GO_CAGE_5 = 246510,
    GO_CAGE_6 = 246511,
    GO_CAGE_7 = 246512, //Void
    GO_CAGE_8 = 246513,
    GO_CAGE_9 = 246514,
    GO_CAGE_10 = 246515, //Corruptions
    GO_CAGE_11 = 246516,
    GO_CAGE_12 = 246517,

    GO_BOSS01_FIRWALL_1 = 247082,
    GO_BOSS01_FIRWALL_2 = 247081,
    GO_BOSS01_DOOR_1 = 246054,
    GO_BOSS01_DOOR_2 = 246053,
    GO_AFTER_BOSS01_DOOR = 247080,
    GO_DOOR_1 = 246112,
};

#endif
