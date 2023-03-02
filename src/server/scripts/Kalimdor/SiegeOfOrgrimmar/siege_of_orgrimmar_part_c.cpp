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
#include "GameObjectAI.h"

enum Adds
{
    // Before Malkorok
    NPC_ORGRIMMAR_PEON = 72893,
    NPC_KORKRON_WAR_WOLF = 72768,
    NPC_KORKRON_GUNNER_1 = 73659, // no loot ?
    NPC_KORKRON_GUNNER_2 = 72784,
    NPC_KORKRON_DARK_FARSEER = 72770,
    NPC_KORKRON_BLOOD_AXE_1 = 73660, // no loot ?
    NPC_KORKRON_BLOOD_AXE_2 = 72728,
    NPC_DARKSPEAR_VANGUARD_1 = 73728,
    NPC_DARKSPEAR_VANGUARD_2 = 73727,
    NPC_DARKSPEAR_VANGUARD_3 = 73726,

    // After Malkorok
    NPC_STOREROOM_GUARD = 73152,
    NPC_KORKRON_SHREDER = 73767,
    NPC_KORKRON_IRON_SENTINEL = 73745,

    // Before Thok the Bloodthirsty
    NPC_MONSTROUS_GASTRAPOD = 73164,
    NPC_TESLA_COIL = 73198,
    NPC_ENRAGED_MUSHAN_BEAST = 73185,
    NPC_PTERRORDAX = 73223,
    NPC_KORKRON_JAILER = 73195,
    NPC_CAPTIVE_CAVE_BAT = 73188,
    NPC_STARVED_YETTI = 73184,
};

void AddSC_siege_of_orgrimmar_part_c()
{
    
}
