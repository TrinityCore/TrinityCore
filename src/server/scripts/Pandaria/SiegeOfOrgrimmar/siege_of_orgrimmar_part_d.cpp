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

#include "siege_of_orgrimmar.hpp"

// TODO:
// script some spells for NPC_GATECRUSHER_SAVAH 73670
// script all spells for NPC_WINDREAVER_TARRATH 73667
// script all spells for NPC_KLAXXI_SKIRMISHER 73012

enum Adds
{
    // Before the paragons
    NPC_GATECRUSHER_SAVAH = 73670,
    NPC_WINDREAVER_TARRATH = 73667,
    NPC_GRANDMASTER_ALCHEMIST_KIXEN = 73696,
    NPC_KORTHIK_HONOR_GUARD = 72954,
    NPC_KLAXXI_SKIRMISHER = 73012,
    NPC_SRATHIK_AMBER_MASTER = 72929,
    NPC_RESONATING_AMBER = 72966,
    NPC_KOVOK = 72927,

    // Before Garrosh
    NPC_KORKRON_REAPER = 73414,
    NPC_ICHOR_OF_YSHAARJ = 73415,
    NPC_HARBRINGER_OF_YSHAARJ = 73452,
    NPC_MANIFESTATION = 73454,
};

enum Spells
{
    // Gatecrusher Sav'ah
    SPELL_ENRAGE = 61369,
    SPELL_BRUTAL_HEMORRHAGE = 148375,
    SPELL_PREMEDITATED_SLAUGHTER_AOE = 148397,
    SPELL_PREMEDITATED_SLAUGHTER_1 = 148391, // triggered after 148397
    SPELL_PREMEDITATED_SLAUGHTER_SCRIPT = 148423,
    SPELL_PREMEDITATED_SLAUGHTER_2 = 148426, // triggered after 148423

    // Windreaver Tar'rath
    SPELL_WINDREAVER_TECHNIQUE = 148370,
    SPELL_WINDREAVER_TECHNIQUE_DMG = 148371,

    // Grand Master Alchemist Ki'xen
    SPELL_ALCHEMICAL_MASTERY = 148456,

    // Kor'thik Honor Guard
    SPELL_PIERCE = 146556,
    SPELL_FRENZIED_ASSAULT_AOE = 146531, // target players
    SPELL_FRENZIED_ASSAULT_JUMP = 146527,
    SPELL_FRENZIED_ASSAULT = 146536,
    SPELL_FRENZIED_ASSAULT_DMG = 146535,

    // Klaxxi Skirmisher
    SPELL_FLY_BY_AOE = 146687, // target players
    SPELL_FLY_BY_CHARGE_1 = 146693,
    SPELL_FLY_BY_SCRIPT_1 = 146699, // triggered by 146693
    SPELL_FLY_BY_AURA = 146694,
    SPELL_FLY_BY_SCRIPT_2 = 146698,
    SPELL_FLY_BY_CHARGE_2 = 146700,
    SPELL_FLY_BY_REMOVE = 146702, // removes 146694

    // Sra'thik Amber-Master
    SPELL_AMBER_BLAST = 146511,
    SPELL_RESONATING_AMBER_AOE = 146499, // target players
    SPELL_RESONATING_AMBER_SUMMON = 146455,
    SPELL_RESONATING_AMBER_AURA = 146454,
    SPELL_RESONATING_AMBER_DMG = 146452,
    SPELL_RESONATING_AMBER_SCALE = 146502, // triggered by 146501 (periodic)
    SPELL_AMBER_GROWTH = 146501,

    // Kovok
    SPELL_GROUND_SLAM = 146621,
    SPELL_MIGHTY_CLEAVE = 146605,
    SPELL_POISON_BLAST = 146606,

    // Kor'kron Reaper
    SPELL_CHARGE = 147640,
    SPELL_REAPING_WHIRLWIND = 147642,
    SPELL_REAPER = 147644,

    // Ichor of Y'Shaarj
    SPELL_EMPOWERING_CORRUPTION = 147564,

    // Harbringer of Y'Shaarj
    SPELL_GRASP_OF_YSHAARJ = 147647,
    SPELL_GRASP_OF_YSHAARJ_SUMMON = 147648,
    SPELL_YSHAARJ_TOUCHED = 147553,

    // Manifestation
    SPELL_BOUND_YSHAARJ_POWER = 147754,
};

void AddSC_siege_of_orgrimmar_part_d()
{
    
}
