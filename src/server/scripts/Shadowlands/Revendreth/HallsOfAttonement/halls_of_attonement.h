/*
 * Copyright 2023
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
#include "ScriptMgr.h"
#include "Player.h"
#include "InstanceScript.h"

enum Creatures
{
	Echelon = 156827,
	Halkias = 165408,
	High_Adjudicator_Aleez = 165410,
	Lord_Chamberlain = 164218,
	Acrobatic_Steward = 175588,
	Ancient_Swoop = 151846,
	Animated_Sin = 167806,
	Binding_of_Misery = 180786,
	
};

enum Objects
{
	Anvil = 192628,
	Challengers_Cache = 354986,
	Snow_Patch = 358375,
	Xyraths_Booby_Trapped_Cache = 375536,
};

enum Quests
{
	The_Eternal_Traveler = 57686,
};

enum Loot
{
    Xyraths_Spare_Outfit = 190241,
    Red_Velvet_Delicacy = 190242,
};

enum Achievements 
{
	Breaking_Bad = 14284,
	Halls_of_Atonement = 14370,
	Heroic_Halls_of_Atonement = 14410,
	Keystone_Hero_Halls_of_Atonement = 15048,
	Mythic_Halls_of_Atonement = 14411,
	Mythic_Halls_of_Atonement_Guild_Run = 14380,
	Nobody_Puts_Denathrius_in_a_Corner = 14352,
};

struct zone_halls_of_attorment : public InstanceScript
{
    zone_halls_of_attorment(InstanceMap* map) : InstanceScript(map, zone_halls_of_attorment) { } 
};

void AddSC_zone_halls_of_attorment()
{
    void zone_halls_of_attorment();
};