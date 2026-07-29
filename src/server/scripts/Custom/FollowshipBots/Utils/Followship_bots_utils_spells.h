/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <optional>
#include <string>
#include <vector>
#include <random>

#include "Player.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "Unit.h"
#include "SpellAuraDefines.h"

#include "Followship_bots_defines.h"
#include "Followship_bots_utils_stats.h"

#include "Followship_bots_druid.h"
#include "Followship_bots_hunter.h"
#include "Followship_bots_mage.h"
#include "Followship_bots_monk.h"
#include "Followship_bots_paladin.h"
#include "Followship_bots_priest.h"
#include "Followship_bots_rogue.h"
#include "Followship_bots_shaman.h"
#include "Followship_bots_warlock.h"
#include "Followship_bots_warrior.h"

enum FSB_RACIAL_SPELLS
{
    SPELL_DWARF_STONEFORM = 20594,
    SPELL_DRAENEI_GIFT_NAARU = 28880,
    SPELL_HUMAN_WILL_TO_SURVIVE = 59752,
    SPELL_PANDAREN_QUAKING_PALM = 107079, //2m
    SPELL_ORC_BLOOD_FURY = 33697,
    SPELL_UNDEAD_WILL_OF_FORSAKEN = 7744,
    SPELL_TAUREN_WAR_STOMP = 20549,
    SPELL_TROLL_BERSERKING = 26297,
    SPELL_BLOODELF_ARCANE_TORRENT = 28730,
    SPELL_GOBLIN_ROCKET_BARRAGE = 69041,
};

enum FSB_RECOVERY_SPELLS
{
    SPELL_DRINK_CONJURED_CRYSTAL_WATER = 22734,
    SPELL_FOOD_SCALED_WITH_LVL = 1131,

    SPELL_RECUPERATE = 1231418,

    // Draenei spells
    //SPELL_DRAENEI_GIFT_NAARU = 28880, //416250,

    // Mage spells
    SPELL_MAGE_CONJURED_MANA_PUDDING = 167152
};

enum FSB_SPECIAL_SPELLS
{
    SPELL_SPECIAL_CAMP_FIRE = 818,
    SPELL_SPECIAL_COOKING_POT = 383081,
    SPELL_SPECIAL_COOK_SAUSAGES = 171760,
    SPELL_SPECIAL_ROMANTIC_PICNIC = 45094,

    SPELL_SPECIAL_GHOST = 8326
};

// Mana Potion Spells
struct PotionSpell
{
    uint8 minLevel;
    uint8 maxLevel;
    uint32 spellId;
};

static constexpr PotionSpell ManaPotionTable[] =
{
    {  1,  15,  437 },   // Minor Mana Potion 120
    { 16,  29,  438 },   // Lesser Mana Potion 159
    { 30,  40,  17530 }, // Superior Mana Potion 494
    { 41,  50,  17531 }, // Major Mana Potion 512
    { 51,  60,  28499 }, // Super Mana Potion 682
    { 61,  80,  43186 } // Runic Mana Potion 956
};

static constexpr PotionSpell HealthPotionTable[] =
{
    {  1,  15,  439 },   // Minor HP Potion 120
    { 16,  29,  440 },   // Lesser HP Potion 159
    { 30,  40,  4042 }, // Superior HP Potion 494
    { 41,  50,  17534 }, // Major HP Potion 512
    { 51,  60,  28495 }, // Super HP Potion 682
    { 61,  80,  43185 } // Runic HP Potion 956
};

enum FSB_StandardGroundMounts
{
    // N Elf
    SPELL_MOUNT_STRIPED_NIGHTSABER = 10793,
    SPELL_MOUNT_STRIPED_FROSTSABER = 8394,
    SPELL_MOUNT_STRIPED_DAWNSABER = 66847,

    SPELL_MOUNT_SWITFT_STORMSABER = 23338,
    SPELL_MOUNT_SWITFT_FROSTSABER = 18766,
    SPELL_MOUNT_SWITFT_MISTSABER = 18767,

    // Human
    SPELL_MOUNT_PINTO = 472,
    SPELL_MOUNT_STALLION = 470,
    SPELL_MOUNT_CHESTNUT = 6648,
    SPELL_MOUNT_BROWN_HORSE = 458,

    SPELL_MOUNT_PALOMINO = 23227,
    SPELL_MOUNT_WHITE_STEED = 23228,
    SPELL_MOUNT_BROWN_STEED = 23229,

    // Draenei
    SPELL_MOUNT_BROWN_ELEKK = 34406,
    SPELL_MOUNT_GRAY_ELEKK = 35710,
    SPELL_MOUNT_PURPLE_ELEKK = 35711,

    SPELL_MOUNT_GREAT_GREEN_ELEKK = 35712,
    SPELL_MOUNT_GREAT_BLUE_ELEKK = 35713,
    SPELL_MOUNT_GREAT_PURPLE_ELEKK = 35714,

    // Dwarf
    SPELL_MOUNT_GRAY_RAM = 6777,
    SPELL_MOUNT_WHITE_RAM = 6898,
    SPELL_MOUNT_BROWN_RAM = 6899,

    SPELL_MOUNT_SWIFT_BROWN_RAM = 23238,
    SPELL_MOUNT_SWIFT_GRAY_RAM = 23239,
    SPELL_MOUNT_SWIFT_WHITE_RAM = 23240,

    // Gnome
    SPELL_MOUNT_RED_MECH = 10873,
    SPELL_MOUNT_BLUE_MECH = 10969,
    SPELL_MOUNT_GREEN_MECH = 17453,
    SPELL_MOUNT_NOPAINT_MECH = 17454,

    SPELL_MOUNT_SWIFT_YELLOW_MECH = 23222,
    SPELL_MOUNT_SWIFT_WHITE_MECH = 23223,
    SPELL_MOUNT_SWIFT_GREEN_MECH = 23225,

    // Worgen
    SPELL_MOUNT_MOUNTAIN_HORSE = 103195,

    SPELL_MOUNT_SWIFT_MOUNTAIN_HORSE = 103196,

    // Pandaren
    SPELL_MOUNT_GREEN_DRAGON_TURTLE = 120395,
    SPELL_MOUNT_BLACK_DRAGON_TURTLE = 127286,
    SPELL_MOUNT_BLUE_DRAGON_TURTLE = 127287,
    SPELL_MOUNT_BROWN_DRAGON_TURTLE = 127288,
    SPELL_MOUNT_PURPLE_DRAGON_TURTLE = 127289,
    SPELL_MOUNT_RED_DRAGON_TURTLE = 127290,

    SPELL_MOUNT_GREEN_GREAT_TURTLE = 127293,
    SPELL_MOUNT_BLACK_GREAT_TURTLE = 127295,
    SPELL_MOUNT_PURPLE_GREAT_TURTLE = 127310,
    SPELL_MOUNT_BLUE_GREAT_TURTLE = 127302,
    SPELL_MOUNT_BROWN_GREAT_TURTLE = 127308,
    SPELL_MOUNT_RED_GREAT_TURTLE = 120822,
};

using MountSpellList = std::vector<uint32>;
using MountRaceLevelMap = std::map<uint8 /*level*/, MountSpellList>;
using MountRaceMap = std::map<FSB_Race /*race*/, MountRaceLevelMap>;

static MountRaceMap MountSpells =
{
    {
        FSB_Race::Human,
        {
            { 10, { SPELL_MOUNT_STALLION, SPELL_MOUNT_PINTO, SPELL_MOUNT_CHESTNUT, SPELL_MOUNT_BROWN_HORSE } },
            { 20, { SPELL_MOUNT_PALOMINO, SPELL_MOUNT_WHITE_STEED, SPELL_MOUNT_BROWN_STEED } }
        }
    },

    {
        FSB_Race::Draenei,
        {
            { 10, { SPELL_MOUNT_BROWN_ELEKK, SPELL_MOUNT_GRAY_ELEKK, SPELL_MOUNT_PURPLE_ELEKK } },
            { 20, { SPELL_MOUNT_GREAT_GREEN_ELEKK, SPELL_MOUNT_GREAT_BLUE_ELEKK, SPELL_MOUNT_GREAT_PURPLE_ELEKK } }
        }
    },
    
    {
        FSB_Race::NightElf,
        {
            { 10, { SPELL_MOUNT_STRIPED_NIGHTSABER, SPELL_MOUNT_STRIPED_FROSTSABER, SPELL_MOUNT_STRIPED_DAWNSABER } },
            { 20, { SPELL_MOUNT_SWITFT_STORMSABER, SPELL_MOUNT_SWITFT_FROSTSABER, SPELL_MOUNT_SWITFT_MISTSABER } }
        }
    },

    {
        FSB_Race::Dwarf,
        {
            { 10, { SPELL_MOUNT_BROWN_RAM, SPELL_MOUNT_GRAY_RAM, SPELL_MOUNT_WHITE_RAM } },
            { 20, { SPELL_MOUNT_SWIFT_BROWN_RAM, SPELL_MOUNT_SWIFT_GRAY_RAM, SPELL_MOUNT_SWIFT_WHITE_RAM } }
        }
    },

    {
        FSB_Race::Gnome,
        {
            { 10, { SPELL_MOUNT_RED_MECH, SPELL_MOUNT_GREEN_MECH, SPELL_MOUNT_BLUE_MECH, SPELL_MOUNT_NOPAINT_MECH} },
            { 20, { SPELL_MOUNT_SWIFT_WHITE_MECH, SPELL_MOUNT_SWIFT_YELLOW_MECH, SPELL_MOUNT_SWIFT_GREEN_MECH } },
        }
    },

    {
        FSB_Race::Pandaren,
        {
            { 10, {SPELL_MOUNT_GREEN_DRAGON_TURTLE, SPELL_MOUNT_BLACK_DRAGON_TURTLE, SPELL_MOUNT_BLUE_DRAGON_TURTLE,
                    SPELL_MOUNT_BROWN_DRAGON_TURTLE, SPELL_MOUNT_PURPLE_DRAGON_TURTLE, SPELL_MOUNT_RED_DRAGON_TURTLE } },
            { 20, {SPELL_MOUNT_GREEN_GREAT_TURTLE, SPELL_MOUNT_BLACK_GREAT_TURTLE, SPELL_MOUNT_BLUE_GREAT_TURTLE,
                    SPELL_MOUNT_BROWN_GREAT_TURTLE, SPELL_MOUNT_PURPLE_GREAT_TURTLE, SPELL_MOUNT_RED_GREAT_TURTLE } },
        }
    },

    {
        FSB_Race::Worgen,
        {
            { 10, { SPELL_MOUNT_MOUNTAIN_HORSE} },
            { 20, { SPELL_MOUNT_SWIFT_MOUNTAIN_HORSE } },
        }
    }
};

struct DispelAbility
{
    uint32 spellId;
    std::vector<DispelType> dispels;
    uint32 cooldown;
};

extern std::unordered_map<FSB_Class, DispelAbility> DispelTable;

enum OffensiveDispelType
{
    OFFDISPEL_MAGIC,
    OFFDISPEL_STEAL
};

struct OffensiveDispelAbility
{
    uint32 spellId;
    OffensiveDispelType type;
};

extern std::unordered_map<FSB_Class, OffensiveDispelAbility> OffensiveDispelTable;

namespace FSBSpellsUtils
{
    bool IsSpellReady(uint32 spellId);
    void PutSpellOnCooldown(uint32 spellId, uint32 cooldownMs);

    bool CanCastNow(Unit* me, uint32 now, uint32 globalCooldownUntil);
    bool BotHasHealSpells(Creature* bot);
    bool BotHasHealSpellsForSelf(Creature* bot);

    bool IsCrowdControlWithRandomTarget(uint32 spellId);

    DispelType ConvertAuraToDispelType(Aura* aura);

    // Gets mana potion spell per level
    uint32 GetManaPotionSpellForLevel(uint8 level);
    // Gets hp potion spell per level
    uint32 GetHealthPotionSpellForLevel(uint8 level);

    /// Returns the English name of a spell by its ID, or "unknown spell" if not found.
    std::string GetSpellName(uint32 spellId);

    const MountSpellList* GetMountSpellsForBot(FSB_Race race, uint8 level);
    uint32 GetRandomMountSpellForBot(Creature* bot);
    bool CastRandomMountLevelSpell(Creature* bot);

    Aura* FindEnemyBuffToDispel(Unit* enemy);

    bool HasAnyMechanic(Unit* u, std::initializer_list<Mechanics> mechanics);
    bool HasAnyAuraType(Unit* u, std::initializer_list<AuraType> auraTypes);
    bool HasAnyNegativeDispel(Unit* u, std::initializer_list<DispelType> dispels);

    bool CheckSpellContextRequirements(Creature* bot, uint32 spellId, Unit* target);
    bool CheckDwarfStoneformRequirements(Creature* bot);
    bool CheckRepentanceRequirements(Creature* bot, Unit* target);
    bool CheckCrowdControlRequirements(Creature* bot, float range);
    bool CheckNoNpcInRangeRequirement(Creature* bot, uint32 entry, float range);

    std::string GetSpellCastResultString(SpellCastResult result);
}

