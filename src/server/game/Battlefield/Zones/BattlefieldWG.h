/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_BATTLEFIELD_WG_
#define TRINITY_BATTLEFIELD_WG_

#include "Battlefield.h"

enum WintergraspNPCEntries
{
    NPC_WINTERGRASP_TOWER_CANNON                = 28366,
    NPC_WINTERGRASP_GUARD_HORDE                 = 30739,
    NPC_WINTERGRASP_GUARD_ALLIANCE              = 30740,
    NPC_WINTERGRASP_STALKER                     = 27869,

    NPC_WINTERGRASP_VIERON_BLAZEFEATHER         = 31102,
    NPC_WINTERGRASP_STONE_GUARD_MUKAR           = 32296, // <WINTERGRASP QUARTERMASTER>
    NPC_WINTERGRASP_HOODOO_MASTER_FU_JIN        = 31101, // <MASTER HEXXER>
    NPC_WINTERGRASP_CHAMPION_ROS_SLAI           = 39173, // <WINTERGRASP QUARTERMASTER>
    NPC_WINTERGRASP_COMMANDER_DARDOSH           = 31091,
    NPC_WINTERGRASP_TACTICAL_OFFICER_KILRATH    = 31151,
    NPC_WINTERGRASP_SIEGESMITH_STRONGHOOF       = 31106,
    NPC_WINTERGRASP_PRIMALIST_MULFORT           = 31053,
    NPC_WINTERGRASP_LIEUTENANT_MURP             = 31107,

    NPC_WINTERGRASP_BOWYER_RANDOLPH             = 31052,
    NPC_WINTERGRASP_KNIGHT_DAMERON              = 32294, // <WINTERGRASP QUARTERMASTER>
    NPC_WINTERGRASP_SORCERESS_KAYLANA           = 31051, // <ENCHANTRESS>
    NPC_WINTERGRASP_MARSHAL_MAGRUDER            = 39172, // <WINTERGRASP QUARTERMASTER>
    NPC_WINTERGRASP_COMMANDER_ZANNETH           = 31036,
    NPC_WINTERGRASP_TACTICAL_OFFICER_AHBRAMIS   = 31153,
    NPC_WINTERGRASP_SIEGE_MASTER_STOUTHANDLE    = 31108,
    NPC_WINTERGRASP_ANCHORITE_TESSA             = 31054,
    NPC_WINTERGRASP_SENIOR_DEMOLITIONIST_LEGOSO = 31109,

    NPC_TAUNKA_SPIRIT_GUIDE                     = 31841, // Horde spirit guide for Wintergrasp
    NPC_DWARVEN_SPIRIT_GUIDE                    = 31842, // Alliance spirit guide for Wintergrasp

    NPC_WINTERGRASP_GOBLIN_MECHANIC             = 30400,
    NPC_WINTERGRASP_GNOMISH_ENGINEER            = 30499,
    NPC_WINTERGRASP_CONTROL_ARMS                = 27852,
    NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE       = 28312,
    NPC_WINTERGRASP_SIEGE_ENGINE_HORDE          = 32627,
    NPC_WINTERGRASP_SIEGE_TURRET_HORDE          = 32629,
    NPC_WINTERGRASP_SIEGE_TURRET_ALLIANCE       = 28319,
    NPC_WINTERGRASP_CATAPULT                    = 27881,
    NPC_WINTERGRASP_DEMOLISHER                  = 28094,

    NPC_WINTERGRASP_PVP_KILL_HORDE              = 39019,
    NPC_WINTERGRASP_PVP_KILL_ALLIANCE           = 31086
};

class TC_GAME_API BattlefieldWintergrasp : public Battlefield
{
public:
    explicit BattlefieldWintergrasp();
    ~BattlefieldWintergrasp() { }

private:
    BattlefieldWintergrasp(BattlefieldWintergrasp const&) = delete;
};

#endif
