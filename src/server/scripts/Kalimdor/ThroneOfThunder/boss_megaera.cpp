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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"
#include "Unit.h"
#include "Player.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h" 
#include "VehicleDefines.h"
#include "SpellInfo.h"
#include <utility>
#include "Group.h"

#include "throne_of_thunder.h"

enum Yells
{
    // Boss
    ANN_RAMPAGE = 0,      // Megaera begins to [Rampage].
    ANN_SUBSIDE                           // Megaera's rage subsides.
};

enum Spells
{
    // Boss
    SPELL_SUBMERGE = 103963, // Submerge visual (when casted makes head submerge).
    SPELL_EMERGE = 139832, // Submerged visual (when removed makes head emerge).

    SPELL_CONCEALING_FOG = 137973, // Dummy on eff 0 for attackable state (body + back head).

    // Rampage - When a head dies.
    SPELL_RAMPAGE = 139458, // Periodic dummy on eff 0 for damage increase on the specific spells (+25% for each extra available head of type).

    SPELL_RAMPAGE_FIRE_CAST = 139433,
    SPELL_RAMPAGE_FROST_CAST = 139440,
    SPELL_RAMPAGE_POISON_CAST = 139504,
    SPELL_RAMPAGE_ARCANE_CAST = 139513,

    SPELL_RAMPAGE_FIRE = 139548, // Flaming Head.
    SPELL_RAMPAGE_FROST = 139549, // Frozen Head.
    SPELL_RAMPAGE_POISON = 139551, // Venomous Head.
    SPELL_RAMPAGE_ARCANE = 139552, // Arcane Head - Heroic only!.

    // Hydra Frenzy.
    SPELL_HYDRA_FRENZY = 139942, // Attack speed increase (others when a head dies, this + heal to full).

    // Elemental Bonds.
    SPELL_ELEMENTAL_BONDS_FIRE = 139586, // 15% dmg increase aura for each additional Flaming Head, on each.
    SPELL_ELEMENTAL_BONDS_FROST = 139587, // 15% dmg increase aura for each additional Frozen Head, on each.
    SPELL_ELEMENTAL_BONDS_VENOM = 139588, // 15% dmg increase aura for each additional Venomous Head, on each.
    SPELL_ELEMENTAL_BONDS_ARCAN = 139589, // 15% dmg increase aura for each additional Arcane Head, on each.

    // Megaera's Rage - When there's no melee target.
    SPELL_MEGAERAS_RAGE_FIRE = 139758, // Flaming Head.
    SPELL_MEGAERAS_RAGE_FROST = 139816, // Frozen Head.
    SPELL_MEGAERAS_RAGE_POISON = 139818, // Venomous Head.
    SPELL_MEGAERAS_RAGE_ARCANE = 139820, // Arcane Head - Heroic only!.

    // Flaming Head
    SPELL_CINDERS = 139822, // When in Concealing Fog. Melts Icy Ground. Pool NPC summoned when removed / every 3 seconds on Heroic.
    SPELL_CINDERS_SUMMON = 139834, // Summons NPC_CINDERS.
    SPELL_CINDERS_AURA = 139835, // Pool npc aura (per. dmg. trigger for 139836).

    SPELL_IGNITE_FLESH = 137729, // Triggers 137330 dmg each sec and SPELL_IGNITE_FLESH_AURA on targets.
    SPELL_IGNITE_FLESH_AURA = 137731, // Periodic damage aura on players hit by main spell.

    // Frozen Head
    // Torrent of Ice : NPC_TORRENT_OF_ICE summoned at player location, follows him having SPELL_TORRENT_OF_ICE_NPC_A. SPELL_TORRENT_OF_ICE cast on it.
    SPELL_TORRENT_OF_ICE = 139866, // When in Concealing Fog. Each sec triggers SPELL_TORRENT_OF_ICE_SUMMON.
    SPELL_TORRENT_OF_ICE_SUMMON = 139870, // Summons NPC_ICY_GROUND.
    SPELL_TORRENT_OF_ICE_TARGET = 139857, // Target aura ("Torrent of Ice is targeting you!").
    SPELL_TORRENT_OF_ICE_NPC_A = 139890, // NPC aura (60k periodic damage).

    SPELL_ICY_GROUND_AURA = 139909, // Periodic damage and slow aura on NPC_ICY_GROUND.
    SPELL_ICY_GROUND_GROW = 140213, // 1% scale increase (Heroic only!). 1 min -> double size. Not good as-is!
    SPELL_ICY_GROUND_VISUAL = 139875, // Triggers SPELL_ICY_GROUND_DUMMY.
    SPELL_ICY_GROUND_DUMMY = 139877, // Check for target and add stacks (SPELL_ICY_GROUND_AURA).

    SPELL_ARCTIC_FREEZE = 139841, // Triggers damage and SPELL_ARCTIC_FREEZE_DUMMY.
    SPELL_ARCTIC_FREEZE_DUMMY = 139843, // Stack checker and adder - 5 stacks = SPELL_ARCTIC_FREEZE_STUN on player.
    SPELL_ARCTIC_FREEZE_STUN = 139844, // 20 sec stun.

    // Venomous Head
    SPELL_ACID_RAIN_SUMMON = 139845, // Summons dummy npc (remove trigger spell)
    SPELL_ACID_RAIN_VISUAL = 139847, // Visual for dummy npc
    SPELL_ACID_RAIN_MISSILE = 139848, // Should target dummy npc only (needs trigger spell added (DAMAGE below))
    SPELL_ACID_RAIN_DAMAGE = 139850, // Damage, needs spellscript for range.

    SPELL_ROT_ARMOR = 139838, // Triggers 139839 per. dmg. + 139840 damage taken debuff. 

    // Arcane Head - Heroic only!
    SPELL_NETHER_TEAR = 140138,

    SPELL_DIFFUSION = 139991, // Triggers per. dmg. and SPELL_DIFFUSION_PER_DUMMY.
    SPELL_DIFFUSION_PER_DUMMY = 139993, // Periodic dummy for 10% health redirect.

    // Nether Wyrm
    SPELL_NETHER_SPIKE = 140178,
    SPELL_SUPPRESSION = 140179,

    SPELL_MEGAERA_ACHIEVEMENT_HANDLER = 140353,
};

enum Npcs
{
    // Boss
    NPC_FLAMING_HEAD = 70212,
    NPC_FROZEN_HEAD = 70235,
    NPC_VENOMOUS_HEAD = 70247,
    NPC_ARCANE_HEAD = 70252, // After flaming head dies - Heroic only!

    // Flaming Head
    NPC_CINDERS = 70432,

    // Frozen Head
    NPC_TORRENT_OF_ICE = 70439,
    NPC_ICY_GROUND = 70446,

    // Arcane Head - Heroic only!
    NPC_NETHER_WYRM = 70507,  // From Nether Tear.
    NPC_NETHER_TEAR = 70506,

    // Venomous Head
    NPC_ACID_RAIN = 70435
};

enum GOs
{
    GO_CACHE_OF_ANCIENT_TREAS = 218805 // Loot chest.
};

enum Events
{
    // Boss
    EVENT_RAMPAGE = 1,
    EVENT_MEGAERAS_RAGE,

    EVENT_SUBMERGE,
    EVENT_EMERGE,
    EVENT_BERSERK,

    EVENT_RELOCATE_HEAD,
    EVENT_REEMERGE_HEAD,
    EVENT_SUBMERGE_HEAD,
    EVENT_START_HEADS,

    // Heads - General
    EVENT_CHECK_MEGAERAS_RAGE,

    // Flaming Head
    EVENT_CINDERS,
    EVENT_IGNITE_FLESH,

    // Frozen Head
    EVENT_TORRENT_OF_ICE,
    EVENT_ARCTIC_FREEZE,
    EVENT_SUMMON_ICY_GROUND,
    EVENT_APPLYSLOW_TO_PLAYERS,

    // Venomous Head
    EVENT_ACID_RAIN,
    EVENT_ROT_ARMOR,

    // Arcane Head - Heroic only!
    EVENT_NETHER_TEAR,
    EVENT_DIFFUSION,
    EVENT_SUMMON_WRYMS,

    // Icy Ground
    EVENT_CHECK_ICY_GROUND_AND_CINDERS,
    EVENT_ICY_GROUND_GROW,

    // Nether Wyrm - From Arcane Head - Heroic only! 
    EVENT_NETHER_SPIKE,
    EVENT_SUPPRESSION,
    EVENT_SUMMON_WRYMS25,
    EVENT_TORRENT_SELECTION,
};

enum Timers
{
    // Boss
    TIMER_BERSERK_H = 600000, // 10 minutes (Heroic).
    TIMER_BERSERK = 780000  // 13 minutes.
};

enum Actions
{
    ACTION_SET_IN_COMBAT = 1,
    ACTION_MEGAERAS_RAGE,
    ACTION_DELAY_EVENTS
};

enum HeadPositions
{
    VENOMOUS_HEAD,
    FROZEN_HEAD,
    FLAMING_HEAD,
    ARCANE_HEAD
};

// Front Head positions.
Position const headPositions[4] =
{
    { 6394.10f, 4497.44f, -210.24f, 1.56f },    // VENOMOUS
    { 6417.99f, 4507.41f, -210.58f, 2.18f },    // FROZEN
    { 6437.47f, 4535.20f, -210.62f, 2.62f },    // FLAMING
    { 6435.48f, 4565.67f, -210.57f, 3.34f }     // ARCANE
};

// Concealing Fog Head positions.
Position const concealingPositions[7] =
{
    { 6457.16f, 4489.78f, -210.032f, 2.46f}, // Middle.

    { 6447.39f, 4481.54f, -210.032f, 2.38f}, // Right.
    { 6436.35f, 4473.30f, -210.032f, 1.79f},
    { 6410.10f, 4471.53f, -210.032f, 1.71f},

    { 6468.27f, 4503.42f, -210.032f, 2.58f}, // Left.
    { 6472.02f, 4524.07f, -210.032f, 2.94f},
    { 6465.45f, 4545.15f, -210.032f, 3.13f},
};

// Front Head orientations.
float headOrientations[2] =
{
    2.29f,                             // Right.
    2.70f                              // Left.
};

// Concealing Fog Head orientations.
float concealingOrientations[7] =
{
    2.46f,                             // Middle.

    2.38f,                             // Right.
    1.79f,
    1.71f,

    2.58f,                             // Left.
    2.94f,
    3.13f
};

class HeadPair
{
private:
    Position position;
    uint64 uiGuid;

public:
    HeadPair(Position pos, uint64 guid) : uiGuid(guid), position(pos) {}

    Position GetPosition() const
    {
        return position;
    }

    uint64 GetGUID() const
    {
        return uiGuid;
    }

    void SetGUID(uint64 _guid)
    {
        uiGuid = _guid;
    }
};

// Megaera spawn / original body position.
Position const bossSpawnPos = { 6442.61f, 4599.18f, -210.032f };

void AddSC_boss_megaera()
{
    
}
