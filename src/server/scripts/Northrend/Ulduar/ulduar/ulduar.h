/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_ULDUAR_H
#define DEF_ULDUAR_H

enum Encounter
{
    BOSS_LEVIATHAN,
    BOSS_IGNIS,
    BOSS_RAZORSCALE,
    BOSS_XT002,
    BOSS_ASSEMBLY,
    BOSS_KOLOGARN,
    BOSS_AURIAYA,
    BOSS_MIMIRON,
    BOSS_HODIR,
    BOSS_THORIM,
    BOSS_FREYA,
    BOSS_VEZAX,
    BOSS_YOGGSARON,
    BOSS_ALGALON,
    MAX_BOSS_NUMBER
};

enum Data64
{
    DATA_LEVIATHAN,
    DATA_NORGANNON,
    DATA_IGNIS,
    DATA_RAZORSCALE,
    DATA_EXP_COMMANDER,
    DATA_XT002,
    DATA_STEELBREAKER,
    DATA_MOLGEIM,
    DATA_BRUNDIR,
    DATA_KOLOGARN,
    DATA_AURIAYA,
    DATA_BRIGHTLEAF,
    DATA_IRONBRANCH,
    DATA_STONEBARK,
    DATA_FREYA,
    DATA_THORIM,
    DATA_RUNIC_COLOSSUS,
    DATA_RUNE_GIANT,
    DATA_MIMIRON,
    DATA_LEVIATHAN_MK_II,
    DATA_VX_001,
    DATA_AERIAL_UNIT,
    DATA_MAGNETIC_CORE,
    DATA_VEZAX,
    DATA_YS_FREYA,
    DATA_YS_THORIM,
    DATA_YS_MIMIRON,
    DATA_YS_HODIR,
    DATA_YOGGSARON_BRAIN,
    DATA_YOGGSARON
};

enum Data
{
    DATA_LEVIATHAN_DOOR,
    DATA_TOWER_DESTROYED,
    DATA_RUNIC_DOOR,
    DATA_STONE_DOOR,
    DATA_CALL_TRAM,
    DATA_MIMIRON_ELEVATOR,
    DATA_HODIR_RARE_CHEST
};

#endif
