/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef TRIAL_OF_CHAMPION_H_
#define TRIAL_OF_CHAMPION_H_

#define ToCScriptName "instance_trial_of_the_champion"
#define DataHeader "TC"

Position const LesserChampLoc[18] =
{
	// Horde Lesser Champions
	{ 715.12f, 612.69f, 411.77f },
	{ 715.97f, 618.20f, 411.56f },
	{ 716.55f, 623.53f, 411.79f },
	{ 717.10f, 627.32f, 411.83f },
	{ 717.91f, 632.39f, 411.87f },
	{ 718.54f, 636.32f, 411.89f },
	{ 718.82f, 641.95f, 411.90f },
	{ 719.28f, 645.82f, 411.91f },
	{ 719.86f, 650.74f, 411.92f },
	// Alliance Lesser Champions
	{ 774.66f, 600.71f, 411.71f },
	{ 775.31f, 604.16f, 411.75f },
	{ 775.96f, 607.60f, 411.76f },
	{ 776.95f, 612.87f, 411.76f },
	{ 777.60f, 616.31f, 411.76f },
	{ 778.22f, 619.64f, 411.71f },
	{ 779.11f, 624.34f, 411.83f },
	{ 779.69f, 627.44f, 411.87f },
	{ 780.34f, 630.89f, 411.89f }
};

Position const GrandChampFinalLoc[6] =
{
	// Horde Grand Champions
	{ 706.49f, 618.48f, 411.88f },
	{ 709.00f, 633.73f, 411.92f },
	{ 709.17f, 646.25f, 412.39f },
	// Alliance Grand Champions
	{ 780.96f, 603.13f, 411.84f },
	{ 783.76f, 615.98f, 411.84f },
	{ 785.75f, 625.89f, 411.89f }
};

Position const announcerEncounterPos = { 732.5243f, 663.007f, 412.3932f };
Position const announcerWaitPos = { 742.7739f, 629.849f, 411.1722f };
Position const bossExitPos = { 746.776f, 665.221f, 411.743f, 4.82f };

float const hordeOrientation = 6.175f; // Facing towards alliance spectators
float const allianceOrientation = 3.114f; // Facing towards horde spectators
float const gateOrientation = 1.582f; // Facing towards main gate
float const centerOrientation = 4.714f; // Facing towards the center of arena

enum DataTypes
{
	// Encounter States/Boss GUIDs
	DATA_GRAND_CHAMPIONS,
	DATA_ARGENT_CHALLENGE,
	DATA_BLACK_KNIGHT,

	MAX_ENCOUNTER,

	// Additional Data
	DATA_ANNOUNCER,
	DATA_MAIN_GATE,
	DATA_TIRION,
	DATA_VARIAN,
	DATA_JAINA,
	DATA_GARROSH,
	DATA_THRALL,

	DATA_CHAMPION_S_CACHE,
	DATA_EADRIC_S_CACHE,
	DATA_CONFESSOR_S_CACHE,

	DATA_TEAM_IN_INSTANCE,

	DATA_LESSER_CHAMPIONS_PREPARE,
	DATA_LESSER_CHAMPIONS_DEFEATED,
	DATA_START,
	DATA_REMOVE_VEHICLES,
	DATA_GRAND_CHAMPIONS_DONE,
	DATA_ARGENT_CHAMPION_PREPARE,
	DATA_ARGENT_SOLDIER_DEFEATED,
	DATA_BLACK_KNIGHT_PREPARE,
	DATA_BLACK_KNIGHT_PRECAST,
	DATA_BLACK_KNIGHT_DONE,

	DATA_GRAND_CHAMPION_VEHICLE_1,
	DATA_GRAND_CHAMPION_VEHICLE_2,
	DATA_GRAND_CHAMPION_VEHICLE_3,

	DATA_GRAND_CHAMPION_1,
	DATA_GRAND_CHAMPION_2,
	DATA_GRAND_CHAMPION_3,

	DATA_ARGENT_CHAMPION,

	DATA_BLACK_KNIGHT_VEHICLE
};

enum Creatures
{
	// Horde Champions
	NPC_MOKRA                                       = 35572,
	NPC_ERESSEA                                     = 35569,
	NPC_RUNOK                                       = 35571,
	NPC_ZULTORE                                     = 35570,
	NPC_VISCERI                                     = 35617,

	// Alliance Champions
	NPC_JACOB                                       = 34705,
	NPC_AMBROSE                                     = 34702,
	NPC_COLOSOS                                     = 34701,
	NPC_JAELYNE                                     = 34657,
	NPC_LANA                                        = 34703,

	// Horde Lesser Champions
	NPC_ORGRIMMAR_CHAMPION                          = 35314,
	NPC_SILVERMOON_CHAMPION                         = 35326,
	NPC_THUNDER_BLUFF_CHAMPION                      = 35325,
	NPC_SEN_JIN_CHAMPION                            = 35323,
	NPC_UNDERCITY_CHAMPION                          = 35327,

	// Alliance Lesser Champions
	NPC_STORMWIND_CHAMPION                          = 35328,
	NPC_GNOMEREGAN_CHAMPION                         = 35331,
	NPC_EXODAR_CHAMPION                             = 35330,
	NPC_DARNASSUS_CHAMPION                          = 35332,
	NPC_IRONFORGE_CHAMPION                          = 35329,

	// Argent Champions
	NPC_EADRIC                                      = 35119,
	NPC_PALETRESS                                   = 34928,

	NPC_ARGENT_LIGHWIELDER                          = 35309,
	NPC_ARGENT_MONK                                 = 35305,
	NPC_PRIESTESS                                   = 35307,

	// Memories
	NPC_MEMORY_HOGGER                               = 34942,
	NPC_MEMORY_VANCLEEF                             = 35028,
	NPC_MEMORY_MUTANUS                              = 35029,
	NPC_MEMORY_HEROD                                = 35030,
	NPC_MEMORY_LUCIFRON                             = 35031,
	NPC_MEMORY_THUNDERAAN                           = 35032,
	NPC_MEMORY_CHROMAGGUS                           = 35033,
	NPC_MEMORY_HAKKAR                               = 35034,
	NPC_MEMORY_VEKNILASH                            = 35036,
	NPC_MEMORY_KALITHRESH                           = 35037,
	NPC_MEMORY_MALCHEZAAR                           = 35038,
	NPC_MEMORY_GRUUL                                = 35039,
	NPC_MEMORY_VASHJ                                = 35040,
	NPC_MEMORY_ARCHIMONDE                           = 35041,
	NPC_MEMORY_ILLIDAN                              = 35042,
	NPC_MEMORY_DELRISSA                             = 35043,
	NPC_MEMORY_MURU                                 = 35044,
	NPC_MEMORY_INGVAR                               = 35045,
	NPC_MEMORY_CYANIGOSA                            = 35046,
	NPC_MEMORY_ECK                                  = 35047,
	NPC_MEMORY_ONYXIA                               = 35048,
	NPC_MEMORY_HEIGAN                               = 35049,
	NPC_MEMORY_IGNIS                                = 35050,
	NPC_MEMORY_VEZAX                                = 35051,
	NPC_MEMORY_ALGALON                              = 35052,

	// The Black Knight
	NPC_BLACK_KNIGHT                                = 35451,

	NPC_RISEN_GHOUL                                 = 35590,
	NPC_RISEN_JAEREN                                = 35545,
	NPC_RISEN_ARELAS                                = 35564,
	NPC_DESECRATION_STALKER                         = 35614,

	// Announcers
	NPC_JAEREN                                      = 35004,
	NPC_ARELAS                                      = 35005,

	// Spectators
	NPC_TIRION                                      = 34996,
	NPC_JAINA                                       = 34992,
	NPC_VARIAN                                      = 34990,
	NPC_THRALL                                      = 34994,
	NPC_GARROSH                                     = 34995,
	NPC_SPECTATOR_HORDE                             = 34883,
	NPC_SPECTATOR_ALLIANCE                          = 34887,
	NPC_SPECTATOR_HUMAN                             = 34900,
	NPC_SPECTATOR_ORC                               = 34901,
	NPC_SPECTATOR_TROLL                             = 34902,
	NPC_SPECTATOR_TAUREN                            = 34903,
	NPC_SPECTATOR_BELF                              = 34904,
	NPC_SPECTATOR_UNDEAD                            = 34905,
	NPC_SPECTATOR_DWARF                             = 34906,
	NPC_SPECTATOR_DRAENEI                           = 34908,
	NPC_SPECTATOR_NELF                              = 34909,
	NPC_SPECTATOR_GNOME                             = 34910
};

enum GameObjects
{
	GO_MAIN_GATE                                    = 195647,
	GO_NORTH_PORTCULLIS                             = 195650,

	GO_CHAMPION_S_CACHE                             = 195709,
	GO_CHAMPION_S_CACHE_H                           = 195710,

	GO_EADRIC_S_CACHE                               = 195374,
	GO_EADRIC_S_CACHE_H                             = 195375,

	GO_CONFESSOR_S_CACHE                            = 195323,
	GO_CONFESSOR_S_CACHE_H                          = 195324
};

enum Vehicles
{
	// Grand Champions Alliance Vehicles
	VEHICLE_MARSHAL_JACOB_ALERIUS_MOUNT             = 35637,
	VEHICLE_AMBROSE_BOLTSPARK_MOUNT                 = 35633,
	VEHICLE_COLOSOS_MOUNT                           = 35768,
	VEHICLE_EVENSONG_MOUNT                          = 34658,
	VEHICLE_LANA_STOUTHAMMER_MOUNT                  = 35636,

	// Grand Champions Horde Vehicles
	VEHICLE_MOKRA_SKULLCRUSHER_MOUNT                = 35638,
	VEHICLE_ERESSEA_DAWNSINGER_MOUNT                = 35635,
	VEHICLE_RUNOK_WILDMANE_MOUNT                    = 35640,
	VEHICLE_ZUL_TORE_MOUNT                          = 35641,
	VEHICLE_DEATHSTALKER_VESCERI_MOUNT              = 35634,

	// Player vehicles
	VEHICLE_ARGENT_WARHORSE_COSMETIC                = 35644,
	VEHICLE_ARGENT_WARHORSE_A                       = 36557,
	VEHICLE_ARGENT_BATTLEWORG_H                     = 36558,
	VEHICLE_ARGENT_BATTLEWORG_COSMETIC              = 36559,

	// The Black Knight's vehicle
	VEHICLE_BLACK_KNIGHT                            = 35491
};

enum WaypointData
{
	DATA_GENERATE_WAYPOINTS_FOR_BOSS_1              = 1,
	DATA_GENERATE_WAYPOINTS_FOR_BOSS_2,
	DATA_GENERATE_WAYPOINTS_FOR_BOSS_3,
	DATA_GENERATE_WAYPOINTS_FOR_ADDS
};

enum WaypointPaths
{
	WAYPOINT_MAP_BOSS_1                             = 1,
	WAYPOINT_MAP_BOSS_2,
	WAYPOINT_MAP_BOSS_3,
	WAYPOINT_MAP_ADDS
};

enum Seats
{
	SEAT_ID_0                                       = 0
};

enum PennantSpells
{
	SPELL_PENNANT_DARNASSUS                         = 63406,
	SPELL_PENNANT_EXODAR                            = 63423,
	SPELL_PENNANT_GNOMEREGAN                        = 63396,
	SPELL_PENNANT_IRONFORGE                         = 63427,
	SPELL_PENNANT_ORGRIMMAR                         = 63433,
	SPELL_PENNANT_SEN_JIN                           = 63399,
	SPELL_PENNANT_SILVERMOON                        = 63403,
	SPELL_PENNANT_STORMWIND                         = 62594,
	SPELL_PENNANT_THUNDER_BLUFF                     = 63436,
	SPELL_PENNANT_UNDERCITY                         = 63430
};

template<class AI>
AI* GetTrialOfChampionAI(Creature* creature)
{
	return GetInstanceAI<AI>(creature, ToCScriptName);
}

#endif