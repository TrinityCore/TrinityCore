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
#include "Vehicle.h"
#include "InstanceScript.h"
#include "SpellMgr.h"

enum ScriptedTexts
{
    SAY_ZAELA_AGGRO = 0,
    SAY_ZAELA_ADDS = 1,
    SAY_ZAELA_TOWERS = 2,
    SAY_ZAELA_EVENT_1 = 3,
    SAY_ZAELA_EVENT_2 = 4,
    SAY_ZAELA_EVENT_3 = 5,
};

#define SAY_ZAELA_DEATH_SOUND 38392

Position galakrasNpcPos[4] =
{
    { 1360.96f, -5404.39f, 10.32f, 1.75f}, // jaina moves at the ship
    { 1360.96f, -5404.39f, 10.32f, 4.89f}, // jaina's orientation

    { 1431.70f, -4898.23f, 11.34f, 1.75f}, // jaina/lor'themar position after intro
    { 1421.77f, -4901.12f, 11.36f, 1.76f}  // wrynn/sylvanas position after intro
};

enum Spells
{
    // Common
    SPELL_IN_A_TOWER = 147317,
    SPELL_TOWER_STRENGTH = 148120,

    // Kor'kron Elite Sniper
    SPELL_SNIPED = 146743,

    // Anti-Air Turret
    SPELL_ANTI_AIR_CANNON = 146488,
    SPELL_ANTI_AIR_CANNON_AURA = 147514,

    // Master Cannoneer Dagryn
    SPELL_SHOOT = 146773,

    SPELL_MUZZLE_SPRAY = 147825,
    SPELL_MUZZLE_SPAY_2 = 147823, // triggered by 147825
    SPELL_MUZZLE_SPRAY_DMG = 147824, // triggered by 147823
    SPELL_MUZZLE_SPRAY_DUMMY = 147830,

    // Lieutenant Krugruk
    SPELL_THUNDER_CLAP = 147683,
    SPELL_ARCING_SMASH = 147688,

    // Dragonmaw Flameslinger
    SPELL_FLAME_ARROWS = 146763, // cast 3 secs
    SPELL_FLAME_ARROWS_2 = 147552, // cast 4 secs, not used ?
    SPELL_FLAME_ARROWS_AOE = 147438, // targetting ?
    SPELL_FLAME_ARROWS_DMG = 146764,
    SPELL_FLAME_ARROWS_PERIODIC = 146765,

    // High Enforcer Thranok
    SPELL_CRUSHERS_CALL_AOE = 146769,
    SPELL_CRUSHERS_CALL_TRIGGER = 146778,
    SPELL_CRUSHERS_CALL_AOE_2 = 146775,
    SPELL_CRUSHERS_CALL_JUMP = 146780,
    SPELL_SHATTERING_CLEAVE = 146849,
    SPELL_SKULL_CRACKER = 146848,

    // Kogra the Snake
    SPELL_CURSE_OF_VENOM = 147711,
    SPELL_POISON_TIPPED_BLADES = 146902,
    SPELL_VENOM_BOLT_VOLLEY = 147713,

    // Dragonmaw Bonecrusher
    SPELL_SHATTERING_ROAR = 147204,
    SPELL_FRACTURE = 146899,
    SPELL_FRACTURE_DMG = 146901,

    // Dragonmaw Ebon Stalker
    SPELL_SHADOW_ASSAULT = 146868,
    SPELL_SHADOW_ASSAULT_DMG = 146872,
    SPELL_SHADOW_STALK = 146864,

    // Dragonmaw Flagbearer
    SPELL_DRAGONMAW_FLAGBEARER = 145232,
    SPELL_WAR_BANNER_SUMMON = 146736,
    SPELL_WAR_BANNER_AURA = 146735,
    SPELL_WAR_BANNER_VISUAL = 147328,

    // Dragommaw Grunt (1)
    SPELL_THROW_AXE = 147669,

    // Dragonmaw Grunt (2)
    SPELL_DRAGONS_CLEAVE = 148025,
    SPELL_FIXATE = 148243,

    // Dragonmaw Proto-drake
    SPELL_DRAKE_FIRE_AOE = 148351,
    SPELL_DRAKE_FIRE_MISSILE = 148352,
    SPELL_DRAKE_FIRE_DMG = 148560,
    SPELL_FLAME_BREATH = 146776,

    // Dragonmaw Tidal Shaman
    SPELL_CHAIN_HEAL = 146757,
    SPELL_HEALING_TIDE_TOTEM = 146753,
    SPELL_HEALING_TIDE_AURA = 146725,
    SPELL_HEALING_TIDE_HEAL = 146726,
    SPELL_TIDAL_WAVE_AOE = 148522,
    SPELL_TIDAL_WAVE_DUMMY = 148519,
    SPELL_TIDAL_WAVE_DMG = 147820,

    // Galakras
    SPELL_EJECT_ALL_PASSENGERS = 50630,

    SPELL_PULSING_FLAMES = 147042,
    SPELL_PULSING_FLAMES_DMG = 147043,

    SPELL_FLAMES_OF_GALAKROND = 147068,
    SPELL_FLAMES_OF_GALAKROND_AREATRIGGER = 146991,
    SPELL_FLAMES_OF_GALAKROND_DMG = 146992,
    SPELL_FLAMES_OF_GALAKROND_PERIODIC = 147029,

    // Demolitions Crew
    SPELL_GOT_THE_BOMB = 147966,
    SPELL_THE_MOST_COMPLICATED_BOMB_1 = 147916,   // for right tower
    SPELL_THE_MOST_COMPLICATED_BOMB_2 = 147897,   // for left tower

    // Kor'kron Demolisher
    SPELL_BOMBARD_MISSILE_1 = 148301, // hit onpy players
    SPELL_BOMBARD_MISSILE_2 = 148302,
    SPELL_BOMBART_DMG_1 = 148310,
    SPELL_BOMBART_DMG_2 = 148311,
};

enum Adds
{
    NPC_KORKRON_ELITE_SNIPER = 72261,
    NPC_ANTI_AIR_TURRET = 72408,
    NPC_MASTER_CANNONEER_DAGRYN = 72356,
    NPC_LIEUTENANT_KRUGRUK = 72357,
    NPC_HIGH_ENFORCER_THRANOK = 72355,
    NPC_KORGRA_THE_SNAKE = 72456,
    NPC_DRAGONMAW_FLAMESLINGER = 72353,
    NPC_DRAGONMAW_BONECRUSHER = 72945,
    NPC_DRAGONMAW_EBON_STALKER = 72352,
    NPC_DRAGONMAW_FLAGBEARER = 72942,
    NPC_DRAGONMAW_GRUNT_1 = 72941, // called by galakras
    NPC_DRAGONMAW_GRUNT_2 = 73530, // near towers
    NPC_DRAGONMAW_PROTO_DRAKE = 72943,
    NPC_DRAGONMAW_TIDAL_SHAMAN = 72958,
    NPC_HEALING_TIDE_TOTEM = 73094,
    NPC_KORKRON_DEMOLISHER = 72947,

    NPC_TOWER_LEFT = 73565,
    NPC_TOWER_RIGHT = 73628,

    NPC_DEMOLITIONS_EXPERT_1 = 73495,    // right tower
    NPC_DEMOLITIONS_ASSISTANT_1 = 73496,    // right tower
    NPC_DEMOLITIONS_EXPERT_2 = 73493,    // left tower
    NPC_DEMOLITIONS_ASSISTANT_2 = 73494,    // left tower
};

enum Events
{
    // Galakras
    EVENT_DOWN = 1,
    EVENT_AGGRO,
    EVENT_PULSING_FLAMES,
    EVENT_FLAMES_OF_GALAKROND,
    EVENT_SPAWN_LEFT_DEMOLISHER,
    EVENT_SPAWN_RIGHT_DEMOLISHER,

    //
    EVENT_SHOOT,
    EVENT_MUZZLE_SPRAY,

    EVENT_THUNDER_CLAP,
    EVENT_ARCING_SMASH,

    EVENT_FLAME_ARROWS,

    // High Enforcer Thranok
    EVENT_CRUSHERS_CALL,
    EVENT_SHATTERING_CLEAVE,
    EVENT_SKULL_CRACKER,

    // Kogra the Snake
    EVENT_VENOM_BOLT_VOLLEY,
    EVENT_POISON_TIPPED_BLADES,

    // Dragonmaw Bonecrusher
    EVENT_SHATTERING_ROAR,
    EVENT_FRACTURE,

    // Dragonmaw Ebon Stalker
    EVENT_SHADOW_ASSAULT,
    EVENT_SHADOW_STALK,

    // Dragonmaw Flagbearer
    EVENT_WAR_BANNER,

    // Dragommaw Grunt (1)
    EVENT_THROW_AXE,

    // Dragonmaw Grunt (2)
    EVENT_DRAGONS_CLEAVE,
    EVENT_FIXATE,

    // Dragonmaw Proto-drake
    EVENT_DRAKE_FIRE_AOE,
    EVENT_FLAME_BREATH,

    // Dragonmaw Tidal Shaman
    EVENT_CHAIN_HEAL,
    EVENT_HEALING_TIDE_TOTEM,
    EVENT_TIDAL_WAVE,

    // Kor'kron Demolisher
    EVENT_MOVE_TO_ATTACK,
    EVENT_BOMBARD,
};

enum Actions
{
    ACTION_LEFT_TOWER_BROKEN = 1,
    ACTION_RIGHT_TOWER_BROKEN,
    ACTION_LEFT_TOWER_DEFENDER_DIED,
    ACTION_RIGHT_TOWER_DEFENDER_DIED,
    ACTION_LEFT_TOWER_ALL_DEFENDERS_DIED,
    ACTION_RIGHT_TOWER_ALL_DEFENDERS_DIED,
    ACTION_GALAKRAS_DOWN,
};

enum DisplayIds
{
    DISPLAY_ITEM_KORKRON_HAND_CANNON = 103953,
    DISPLAY_ITEM_DAGRYN_DISCARDED_LONGBOW = 104735,
    DISPLAY_TEM_ARCWEAVER_SPELL_SWORD = 112787,
};

enum eData
{
    DATA_WAVE_SPAWNED = 1,
    DATA_LEFT_TOWER_DEFENDER,
    DATA_RIGHT_TOWER_DEFENDER,
    DATA_LEFT_TOWER_ATTACKER,
    DATA_RIGHT_TOWER_ATTACKER,
    DATA_LEFT_TOWER_DEFENDER_DIED,
    DATA_RIGHT_TOWER_DEFENDER_DIED,
    DATA_RIGHT_TOWER_ALL_DEFENDERS_DIED,
    DATA_LEFT_TOWER_ALL_DEFENDERS_DIED,
    DATA_DEFENDERS_LEFT,
    DATA_LAST_FLAMES_OF_GALAKROND_TARGET,
};

enum TowerDefenders
{
    DEFENDER_NONE = 0,
    LEFT_TOWER_DEFENDER = 1,
    RIGHT_TOWER_DEFENDER = 2,
};

enum TowerAttackers
{
    ATTACKER_NONE = 0,
    LEFT_TOWER_ATTACKER = 1,
    RIGHT_TOWER_ATTACKER = 2,
};

struct StaticAddInfo
{
    uint32 entry;
    Position pos;
};

const Position sniperPos = { 1342.19f, -4702.86f, 36.93f, 5.09f };

#define TOWER_TURRETS_COUNT 2
const Position turretPos[TOWER_TURRETS_COUNT] =
{
    {1372.11f, -4851.76f, 72.05f, 5.48f}, // left
    {1457.19f, -4818.57f, 68.80f, 4.30f}  // right
};

#define FIRST_BOSS_WAVE 3
#define FIRST_TOWER_WAVE 4
#define SECOND_BOSS_WAVE 6
#define SECOND_TOWER_WAVE 8

#define ANTI_AIR_TURRET_COOLDOWN 4000
#define ANTI_AIR_TURRET_HITS 2

#define TOWER_ADDS_COUNT 8
#define DEFENDERS_COUNT (TOWER_ADDS_COUNT - 1)
const StaticAddInfo leftTowerAdds[TOWER_ADDS_COUNT] =
{
    { NPC_LIEUTENANT_KRUGRUK, {1363.26f, -4843.40f, 71.82f, 2.38f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1381.14f, -4840.58f, 71.61f, 5.67f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1376.99f, -4846.52f, 71.77f, 5.70f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1364.22f, -4856.67f, 71.51f, 5.31f} },
    { NPC_DRAGONMAW_GRUNT_2, {1363.53f, -4837.55f, 33.08f, 5.48f} },
    { NPC_DRAGONMAW_GRUNT_2, {1360.16f, -4840.86f, 33.06f, 5.48f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1359.52f, -4835.97f, 33.11f, 5.48f} },
    { NPC_TOWER_LEFT, {1361.79f, -4837.99f, 33.08f, 5.47f} }
};
const StaticAddInfo rightTowerAdds[TOWER_ADDS_COUNT] =
{
    { NPC_MASTER_CANNONEER_DAGRYN, {1461.62f, -4807.18f, 68.47f, 1.26f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1450.27f, -4815.10f, 68.39f, 4.12f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1465.98f, -4822.74f, 68.32f, 4.25f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1462.31f, -4822.44f, 68.52f, 4.25f} },
    { NPC_DRAGONMAW_GRUNT_2, {1459.45f, -4804.19f, 29.68f, 4.36f} },
    { NPC_DRAGONMAW_GRUNT_2, {1463.44f, -4805.61f, 29.67f, 4.36f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1462.74f, -4800.81f, 29.68f, 4.36f} },
    { NPC_TOWER_RIGHT, {1462.65f, -4804.30f, 29.68f, 4.40f} }
};

enum Timers
{
    TIMER_WAVE_FIRST = 5000,
    TIMER_WAVE = 55000,
    TIMER_DEMOLISHER = 20000,
    TIMER_ADDS_DESPAWN = 5000,
};

const Position addsSpawnPos[1] =
{
    { 1407.03f, -4815.50f, 21.13f, 5.07f }
};

const Position demolisherAttackPos[4] =
{
    { 1409.67f, -4820.75f, 19.98f, 3.52f},  // facing to left tower
    { 1409.67f, -4820.75f, 19.98f, 0.27f},  // facing to right tower

    { 1361.79f, -4837.99f, 33.08f, 5.47f},  // attack left tower
    { 1462.65f, -4804.30f, 29.68f, 4.40f}   // attack right tower
};

const Position fallPos = { 1408.86f, -4814.65f, 21.14f, 4.93f };

enum Points
{
    POINT_DEMOLISHER_ATTACK_LEFT = 1,
    POINT_DEMOLISHER_ATTACK_RIGHT = 2,
};

void AddSC_boss_galakras()
{
    
}
