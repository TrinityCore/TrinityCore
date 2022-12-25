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

#include "GameObjectAI.h"
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

#include "throne_of_thunder.h"

/*
    NOTE:
    Ji-Kun's young are located throughout the roost and progress through different stages of life. After a period of incubation Young Eggs of Ji-Kun will hatch into Hatchlings.
    When fed by Ji-Kun, the Hatchlings then mature into Fledglings. Both Fledgling Eggs and Mature Eggs will hatch into Juveniles.
*/

enum Spells
{
    // Ji-Kun.

    // Infected talons
    SPELL_INFECTED_TALONS_AURA = 140094, // Boss check aura on successful melee ability.
    SPELL_INFECTED_TALONS_DAMAGE = 140092, // Player debuff.

    // Talon Rake
    SPELL_TALON_RAKE = 134366, // Damage + increase.

    // Quills
    SPELL_QUILLS = 134380, // Triggers SPELL_QUILLS_DAMAGE damage and SPELL_QUILLS_PERIODIC (Effect 1).
    SPELL_QUILLS_DAMAGE = 134381, // Quills damage.
    SPELL_QUILLS_PERIODIC = 138649, // Periodic dummy - cast of SPELL_QUILLS_VISUAL.
    SPELL_QUILLS_VISUAL = 138650, // Quills visual.

    // Down Draft
    SPELL_DOWN_DRAFT = 134370, // Areatrigger aura.

    // Caw
    SPELL_CAW = 138923, // Script Effect for SPELL_CAW_MISSILE (Effect 0).
    SPELL_CAW_MISSILE = 138926, // Triggers SPELL_CAW_DAMAGE.
    SPELL_CAW_DAMAGE = 134375, // Damage in 8 yards.

    /*
        Flying mechanic:

        When an egg or hatchling from the lower nests located around Ji-Kun's roost is slain it leaves behind a feather for players to loot.
        This feather grants the player Daedalian Wings. Daedalian Wings grants the player an extra action button that allows players to take flight for 10 sec.
    */

    // Drop feather
    SPELL_DROP_FEATHER = 140016, // 140016 Summons lootable feather.

    // Daedelian Wings
    SPELL_DAEDELIAN_WINGS = 134339, // 140014 LFR version (No CD trigger). Flight spell + SPELL_LESSON_OF_ICARUS trigger. Stacks added / aura removed using this spell.
    SPELL_LESSON_OF_ICARUS = 140571, // Cooldown 1 minute Dummy (Effect 0) - Cannot pickup wings.
    SPELL_FLIGHT_ACTION_BUTTON = 133755, // Action button spell on Daedelian Wings. Removes 1 stack and makes player fly.

    /*
        Feed mechanic:

        Ji-Kun spits up globs of food for her young. If a Hatchling has called out for food, Ji-Kun will aim this ability in their direction;
        otherwise the food will land at random locations around Ji-Kun's platform. When the food lands on the ground, it forms a Feed Pool.
        While a glob of food is traveling through the air, players with Flight can intercept it to prevent a Feed Pool from forming.
        Doing so afflicts the player with Slimed, but also grants Primal Nutriment.
    */

    // Feed young
    SPELL_FEED_YOUNG = 137528, // Triggers SPELL_REGURGITATE each 1 sec on Normal / 2.5 sec on Heroic.
    SPELL_REGURGITATE = 134385, // Script effect (Effect 0) for summoning NPC_FEED_POOL / NPC_FEED_HATCHLINGS.

    // Feed pool
    SPELL_FEED_POOL_DMG = 138319, // Periodic damage.
    SPELL_FEED_POOL_VISUAL = 138854, // Green visual, on platform.
    SPELL_FEED_POOL_VISUAL_HATCHLING = 139284, // Yellow visual, on hatchlings in nest.
    SPELL_SUMMON_POOL = 134259, // Main platform, summons NPC_POOL_OF_FEED.
    SPELL_SUMMON_POOL_HATCHLINGS = 139285, // Hatchling nest, summons NPC_POOL_OF_FEED_HATCHLING.

    SPELL_SLIMED = 134256, // On players intercepting Ji-Kun's food globules. Periodic damage and Script Effect (Effect 1) for SPELL_SLIMED_DMG_INCREASE.
    SPELL_SLIMED_DMG_INCREASE = 138309, // 10% damage increase from next Slimed.

    SPELL_PRIMAL_NUTRIMENT = 140741, // On players intercepting Ji-Kun's food globules. Eff 0 + 1 Dummy A. H / D incr., SPELL_PRIMAL_NUTRIMENT_INCREASE trigger on Eff 2.
    SPELL_PRIMAL_NUTRIMENT_INCREASE = 112879, // 30% Healing and 100% Damage increase.

    // Ji-Kun's Flock.

    // Hatchling

    SPELL_HATCHLING_CHEEP = 139296, // Triggers SPELL_HATCHLING_CHEEP_DAMAGE in 10 yards.
    SPELL_HATCHLING_CHEEP_DAMAGE = 139298,
    SPELL_CHEEP_AOE = 140129,
    SPELL_INCUBATION_LOW_NEST = 134347, // 10 sec incubation
    SPELL_INCUBATION_HIGH_NEST = 134335, // 20 sec incubation

    SPELL_SUMMON_YOUNG_HATCHLING = 134336,
    SPELL_SUMMON_JUVENILE = 138905,

    SPELL_HATCHLING_EVOLUTION = 134322,

    SPELL_HATCHLING_EATING = 134321,

    // Fledgling

    SPELL_FLEDGLING_LAY_EGG = 134367, // Summons NPC_FLEDGLING_EGG_JIKUN.
    SPELL_FLEDGLING_CHEEP = 140570, // Needs target limitation.

    // Juvenile

    SPELL_JUVENILE_CHEEP = 140227, // Script effect (Effect 0) for SPELL_JUVENILE_CHEEP_DAMAGE in 60 yards.
    SPELL_JUVENILE_CHEEP_DAMAGE = 140129, // Damage in 10 yards.

    // Nest Guardian - HEROIC!

    SPELL_GUARDIAN_TALON_STRIKE = 139100, // Weapon damage 180 degree arc.
    SPELL_GUARDIAN_SCREECH = 140640, // Damage, Interrupt, Script Effect (Effect 2) for SPELL_GUARDIAN_SCREECH_SLOW. If not actively engaged in melee combat.
    SPELL_GUARDIAN_SCREECH_SLOW = 134372, // Slow casting on targets (Removed after casting any spell). Mana users.

    SPELL_BEAM_VISUAL = 137526, // visual aur of beam

    SPELL_TALON_STRIKE = 139100,
    SPELL_SCREECH = 140640,
    SPELL_SCREECH_STACKS = 134372,
};

enum FeedMovementPoints
{
    POINT_GREEN_FEED_AIR = 1,
    POINT_GREEN_FEED_GROUND = 2,
    POINT_FEED_CAME_TO_HATCHLING = 3,
    POINT_FOOD_AIR = 4,
};

enum JuvenileMovementPoints
{
    POINT_MOVE_TO_CENTER_FLY = 1,
};

enum HatchlingMovementPoints
{
    POINT_MOVE_TO_EAT_POOL = 1,
};

enum JikunMovementPoints
{
    POINT1 = 1,
    POINT2 = 2,
};

enum EventsJiKun
{
    EVENT_TALON_RAKE = 1,
    EVENT_QUILLS,
    EVENT_DOWN_DRAFT,
    EVENT_DOWN_DRAFT_FALL,
    EVENT_CAW,
    EVENT_CAW_MISSILE,
    EVENT_ACTIVATE_NEST, // old codish
    EVENT_FEED_YOUNG,
    EVENT_CHECK_MELEE,
    EVENT_TALON_STRIKE,
    EVENT_QUILLS_MELEE,
    EVENT_ACTIVATE_NESTS,
};

enum EventsHatchlings
{
    EVENT_FIND_EAT = 1,
    EVENT_CHEEP,
    EVENT_LAY_EGG,
    EVENT_FEED_POOL_DAMAGE,
};

enum EventsJuvenile
{
    EVENT_START_FLY_AWAY = 1,
    EVENT_JUVENILE_CHEEP,
};

enum EggsJikun
{
    EVENT_SUMMON_HATCHLING = 1,
};

enum Npcs
{
    // Ji-Kun.
    NPC_YOUNG_EGG_OF_JIKUN = 68194, // Hatches to Hatchling.
    NPC_FLEDGLING_EGG_JIKUN = 68202, // Hatches to Juvenile.
    NPC_MATURE_EGG_OF_JIKUN = 69628, // Hatches to Juvenile.

    NPC_JIKUN_HATCHLING = 68192,
    NPC_JIKUN_FLEDGLING = 68193,
    NPC_JIKUN_JUVENILE = 70095,

    NPC_JIKUN_NEST_GUARDIAN = 70134, // HEROIC only!

    NPC_FEED_POOL = 68178, // Feed NPC's. also spawn visual 48142
    NPC_FEED_HATCHLINGS = 70130, // spawn visual 48210

    NPC_POOL_OF_FEED = 68188, // Feed Pool NPC's.
    NPC_POOL_OF_FEED_HATCHLING = 70216,

    NPC_BEAM_NEST = 68208, // Visual beam of active nest
};

enum Gameobjects
{
    GOB_FEATHER_OF_JIKUN = 216453,
};

// Center
const Position Center = { 6146.085f, 4319.261f, -30.608f, 2.739f };

// Ji-Kun intro movement.
Position const IntroMoving[2] =
{
    { 6213.971f, 4289.072f, -14.402f, 2.873f },
    { 6146.085f, 4319.261f, -30.608f, 2.739f }
};

// Ji-Kun low nest positions.
Position const NestPositionsGround[5] =
{
    { 6071.182f, 4285.108f, -101.469f, 1.873f },
    { 6096.028f, 4339.460f, -93.655f, 1.873f },
    { 6159.814f, 4370.529f, -70.502f, 1.873f },
    { 6220.071f, 4333.520f, -57.075f, 1.873f },
    { 6192.708f, 4267.664f, -70.764f, 1.873f }
};

// Ji-Kun high nest positions.
Position const NestPositionsHigh[5] =
{
    { 6078.422f, 4270.403f, 42.407f, 1.873f },
    { 6082.500f, 4371.428f, 45.238f, 1.873f },
    { 6151.905f, 4330.750f, 72.997f, 1.873f },
    { 6217.987f, 4352.961f, 68.138f, 1.873f },
    { 6173.894f, 4239.375f, 43.848f, 1.873f }
};

enum Actions
{
    ACTION_FOOD_AIR = 5,
};

uint32 const EggsLowNest = 15; // size of eggs on low nests
uint32 const EggsHighNest = 10;// size of eggs on high nests

Unit* SelectRandomTargetWithGuidOnRange(Unit* FromWho, uint32 entry, float range, bool player)
{
    std::list<Player*> PlayerList;
    std::list<Creature*> CreatureList;

    if (player)
        GetPlayerListInGrid(PlayerList, FromWho, range);
    else
        GetCreatureListWithEntryInGrid(CreatureList, FromWho, entry, range);

    if (player && !PlayerList.empty())
    {
        if (Player* target = Trinity::Containers::SelectRandomContainerElement(PlayerList))
            return target->ToUnit();
    }
    else if (!CreatureList.empty())
    {
        if (Creature* target = Trinity::Containers::SelectRandomContainerElement(CreatureList))
            return target->ToUnit();
    }

    return NULL;
}

void AddSC_boss_jikun()
{
    
}
