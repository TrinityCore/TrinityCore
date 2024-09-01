/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "SharedDefines.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/*************************************************************\
|* data for enum 'Races' in 'SharedDefines.h' auto-generated *|
\*************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<Races>::ToString(Races value)
{
    switch (value)
    {
        case RACE_HUMAN: return { "RACE_HUMAN", "Human", "" };
        case RACE_ORC: return { "RACE_ORC", "Orc", "" };
        case RACE_DWARF: return { "RACE_DWARF", "Dwarf", "" };
        case RACE_NIGHTELF: return { "RACE_NIGHTELF", "Night Elf", "" };
        case RACE_UNDEAD_PLAYER: return { "RACE_UNDEAD_PLAYER", "Undead", "" };
        case RACE_TAUREN: return { "RACE_TAUREN", "Tauren", "" };
        case RACE_GNOME: return { "RACE_GNOME", "Gnome", "" };
        case RACE_TROLL: return { "RACE_TROLL", "Troll", "" };
        case RACE_BLOODELF: return { "RACE_BLOODELF", "Blood Elf", "" };
        case RACE_DRAENEI: return { "RACE_DRAENEI", "Draenei", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Races>::Count() { return 10; }

template <>
TC_API_EXPORT Races EnumUtils<Races>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return RACE_HUMAN;
        case 1: return RACE_ORC;
        case 2: return RACE_DWARF;
        case 3: return RACE_NIGHTELF;
        case 4: return RACE_UNDEAD_PLAYER;
        case 5: return RACE_TAUREN;
        case 6: return RACE_GNOME;
        case 7: return RACE_TROLL;
        case 8: return RACE_BLOODELF;
        case 9: return RACE_DRAENEI;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Races>::ToIndex(Races value)
{
    switch (value)
    {
        case RACE_HUMAN: return 0;
        case RACE_ORC: return 1;
        case RACE_DWARF: return 2;
        case RACE_NIGHTELF: return 3;
        case RACE_UNDEAD_PLAYER: return 4;
        case RACE_TAUREN: return 5;
        case RACE_GNOME: return 6;
        case RACE_TROLL: return 7;
        case RACE_BLOODELF: return 8;
        case RACE_DRAENEI: return 9;
        default: throw std::out_of_range("value");
    }
}

/***************************************************************\
|* data for enum 'Classes' in 'SharedDefines.h' auto-generated *|
\***************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<Classes>::ToString(Classes value)
{
    switch (value)
    {
        case CLASS_WARRIOR: return { "CLASS_WARRIOR", "Warrior", "" };
        case CLASS_PALADIN: return { "CLASS_PALADIN", "Paladin", "" };
        case CLASS_HUNTER: return { "CLASS_HUNTER", "Hunter", "" };
        case CLASS_ROGUE: return { "CLASS_ROGUE", "Rogue", "" };
        case CLASS_PRIEST: return { "CLASS_PRIEST", "Priest", "" };
        case CLASS_DEATH_KNIGHT: return { "CLASS_DEATH_KNIGHT", "Death Knight", "" };
        case CLASS_SHAMAN: return { "CLASS_SHAMAN", "Shaman", "" };
        case CLASS_MAGE: return { "CLASS_MAGE", "Mage", "" };
        case CLASS_WARLOCK: return { "CLASS_WARLOCK", "Warlock", "" };
        case CLASS_DRUID: return { "CLASS_DRUID", "Druid", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Classes>::Count() { return 10; }

template <>
TC_API_EXPORT Classes EnumUtils<Classes>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return CLASS_WARRIOR;
        case 1: return CLASS_PALADIN;
        case 2: return CLASS_HUNTER;
        case 3: return CLASS_ROGUE;
        case 4: return CLASS_PRIEST;
        case 5: return CLASS_DEATH_KNIGHT;
        case 6: return CLASS_SHAMAN;
        case 7: return CLASS_MAGE;
        case 8: return CLASS_WARLOCK;
        case 9: return CLASS_DRUID;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Classes>::ToIndex(Classes value)
{
    switch (value)
    {
        case CLASS_WARRIOR: return 0;
        case CLASS_PALADIN: return 1;
        case CLASS_HUNTER: return 2;
        case CLASS_ROGUE: return 3;
        case CLASS_PRIEST: return 4;
        case CLASS_DEATH_KNIGHT: return 5;
        case CLASS_SHAMAN: return 6;
        case CLASS_MAGE: return 7;
        case CLASS_WARLOCK: return 8;
        case CLASS_DRUID: return 9;
        default: throw std::out_of_range("value");
    }
}

/**************************************************************\
|* data for enum 'Powers' in 'SharedDefines.h' auto-generated *|
\**************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<Powers>::ToString(Powers value)
{
    switch (value)
    {
        case POWER_HEALTH: return { "POWER_HEALTH", "Health", "" };
        case POWER_MANA: return { "POWER_MANA", "Mana", "" };
        case POWER_RAGE: return { "POWER_RAGE", "Rage", "" };
        case POWER_FOCUS: return { "POWER_FOCUS", "Focus", "" };
        case POWER_ENERGY: return { "POWER_ENERGY", "Energy", "" };
        case POWER_HAPPINESS: return { "POWER_HAPPINESS", "Happiness", "" };
        case POWER_RUNE: return { "POWER_RUNE", "Runes", "" };
        case POWER_RUNIC_POWER: return { "POWER_RUNIC_POWER", "Runic Power", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Powers>::Count() { return 8; }

template <>
TC_API_EXPORT Powers EnumUtils<Powers>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return POWER_HEALTH;
        case 1: return POWER_MANA;
        case 2: return POWER_RAGE;
        case 3: return POWER_FOCUS;
        case 4: return POWER_ENERGY;
        case 5: return POWER_HAPPINESS;
        case 6: return POWER_RUNE;
        case 7: return POWER_RUNIC_POWER;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Powers>::ToIndex(Powers value)
{
    switch (value)
    {
        case POWER_HEALTH: return 0;
        case POWER_MANA: return 1;
        case POWER_RAGE: return 2;
        case POWER_FOCUS: return 3;
        case POWER_ENERGY: return 4;
        case POWER_HAPPINESS: return 5;
        case POWER_RUNE: return 6;
        case POWER_RUNIC_POWER: return 7;
        default: throw std::out_of_range("value");
    }
}

/********************************************************************\
|* data for enum 'SpellSchools' in 'SharedDefines.h' auto-generated *|
\********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellSchools>::ToString(SpellSchools value)
{
    switch (value)
    {
        case SPELL_SCHOOL_NORMAL: return { "SPELL_SCHOOL_NORMAL", "Physical", "" };
        case SPELL_SCHOOL_HOLY: return { "SPELL_SCHOOL_HOLY", "Holy", "" };
        case SPELL_SCHOOL_FIRE: return { "SPELL_SCHOOL_FIRE", "Fire", "" };
        case SPELL_SCHOOL_NATURE: return { "SPELL_SCHOOL_NATURE", "Nature", "" };
        case SPELL_SCHOOL_FROST: return { "SPELL_SCHOOL_FROST", "Frost", "" };
        case SPELL_SCHOOL_SHADOW: return { "SPELL_SCHOOL_SHADOW", "Shadow", "" };
        case SPELL_SCHOOL_ARCANE: return { "SPELL_SCHOOL_ARCANE", "Arcane", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellSchools>::Count() { return 7; }

template <>
TC_API_EXPORT SpellSchools EnumUtils<SpellSchools>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_SCHOOL_NORMAL;
        case 1: return SPELL_SCHOOL_HOLY;
        case 2: return SPELL_SCHOOL_FIRE;
        case 3: return SPELL_SCHOOL_NATURE;
        case 4: return SPELL_SCHOOL_FROST;
        case 5: return SPELL_SCHOOL_SHADOW;
        case 6: return SPELL_SCHOOL_ARCANE;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellSchools>::ToIndex(SpellSchools value)
{
    switch (value)
    {
        case SPELL_SCHOOL_NORMAL: return 0;
        case SPELL_SCHOOL_HOLY: return 1;
        case SPELL_SCHOOL_FIRE: return 2;
        case SPELL_SCHOOL_NATURE: return 3;
        case SPELL_SCHOOL_FROST: return 4;
        case SPELL_SCHOOL_SHADOW: return 5;
        case SPELL_SCHOOL_ARCANE: return 6;
        default: throw std::out_of_range("value");
    }
}

/******************************************************************\
|* data for enum 'SpellAttr0' in 'SharedDefines.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr0>::ToString(SpellAttr0 value)
{
    switch (value)
    {
        case SPELL_ATTR0_UNK0: return { "SPELL_ATTR0_UNK0", "Unknown attribute 0@Attr0", "" };
        case SPELL_ATTR0_REQ_AMMO: return { "SPELL_ATTR0_REQ_AMMO", "Treat as ranged attack", "Use ammo, ranged attack range modifiers, ranged haste, etc." };
        case SPELL_ATTR0_ON_NEXT_SWING: return { "SPELL_ATTR0_ON_NEXT_SWING", "On next melee (type 1)", "Both \042on next swing\042 attributes have identical handling in server & client" };
        case SPELL_ATTR0_IS_REPLENISHMENT: return { "SPELL_ATTR0_IS_REPLENISHMENT", "Replenishment (client only)", "" };
        case SPELL_ATTR0_ABILITY: return { "SPELL_ATTR0_ABILITY", "Treat as ability", "Cannot be reflected, not affected by cast speed modifiers, etc." };
        case SPELL_ATTR0_TRADESPELL: return { "SPELL_ATTR0_TRADESPELL", "Trade skill recipe", "Displayed in recipe list, not affected by cast speed modifiers" };
        case SPELL_ATTR0_PASSIVE: return { "SPELL_ATTR0_PASSIVE", "Passive spell", "Spell is automatically cast on self by core" };
        case SPELL_ATTR0_HIDDEN_CLIENTSIDE: return { "SPELL_ATTR0_HIDDEN_CLIENTSIDE", "Hidden in UI (client only)", "Not visible in spellbook or aura bar" };
        case SPELL_ATTR0_HIDE_IN_COMBAT_LOG: return { "SPELL_ATTR0_HIDE_IN_COMBAT_LOG", "Hidden in combat log (client only)", "Spell will not appear in combat logs" };
        case SPELL_ATTR0_TARGET_MAINHAND_ITEM: return { "SPELL_ATTR0_TARGET_MAINHAND_ITEM", "Auto-target mainhand item (client only)", "Client will automatically select main-hand item as cast target" };
        case SPELL_ATTR0_ON_NEXT_SWING_2: return { "SPELL_ATTR0_ON_NEXT_SWING_2", "On next melee (type 2)", "Both \042on next swing\042 attributes have identical handling in server & client" };
        case SPELL_ATTR0_UNK11: return { "SPELL_ATTR0_UNK11", "Unknown attribute 11@Attr0", "" };
        case SPELL_ATTR0_DAYTIME_ONLY: return { "SPELL_ATTR0_DAYTIME_ONLY", "Only usable during daytime (unused)", "" };
        case SPELL_ATTR0_NIGHT_ONLY: return { "SPELL_ATTR0_NIGHT_ONLY", "Only usable during nighttime (unused)", "" };
        case SPELL_ATTR0_INDOORS_ONLY: return { "SPELL_ATTR0_INDOORS_ONLY", "Only usable indoors", "" };
        case SPELL_ATTR0_OUTDOORS_ONLY: return { "SPELL_ATTR0_OUTDOORS_ONLY", "Only usable outdoors", "" };
        case SPELL_ATTR0_NOT_SHAPESHIFT: return { "SPELL_ATTR0_NOT_SHAPESHIFT", "Not usable while shapeshifted", "" };
        case SPELL_ATTR0_ONLY_STEALTHED: return { "SPELL_ATTR0_ONLY_STEALTHED", "Only usable in stealth", "" };
        case SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE: return { "SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE", "Don't shealthe weapons (client only)", "" };
        case SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION: return { "SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION", "Scale with caster level", "For non-player casts, scale impact and power cost with caster's level" };
        case SPELL_ATTR0_STOP_ATTACK_TARGET: return { "SPELL_ATTR0_STOP_ATTACK_TARGET", "Stop attacking after cast", "After casting this, the current auto-attack will be interrupted" };
        case SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK: return { "SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK", "Prevent physical avoidance", "Spell cannot be dodged, parried or blocked" };
        case SPELL_ATTR0_CAST_TRACK_TARGET: return { "SPELL_ATTR0_CAST_TRACK_TARGET", "Automatically face target during cast (client only)", "" };
        case SPELL_ATTR0_CASTABLE_WHILE_DEAD: return { "SPELL_ATTR0_CASTABLE_WHILE_DEAD", "Can be cast while dead", "Spells without this flag cannot be cast by dead units in non-triggered contexts" };
        case SPELL_ATTR0_CASTABLE_WHILE_MOUNTED: return { "SPELL_ATTR0_CASTABLE_WHILE_MOUNTED", "Can be cast while mounted", "" };
        case SPELL_ATTR0_DISABLED_WHILE_ACTIVE: return { "SPELL_ATTR0_DISABLED_WHILE_ACTIVE", "Cooldown starts on expiry", "Spell is unusable while already active, and cooldown does not begin until the effects have worn off" };
        case SPELL_ATTR0_NEGATIVE_1: return { "SPELL_ATTR0_NEGATIVE_1", "Is negative spell", "Forces the spell to be treated as a negative spell" };
        case SPELL_ATTR0_CASTABLE_WHILE_SITTING: return { "SPELL_ATTR0_CASTABLE_WHILE_SITTING", "Can be cast while sitting", "" };
        case SPELL_ATTR0_CANT_USED_IN_COMBAT: return { "SPELL_ATTR0_CANT_USED_IN_COMBAT", "Cannot be used in combat", "" };
        case SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY: return { "SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY", "Pierce invulnerability", "Allows spell to pierce invulnerability, unless the invulnerability spell also has this attribute" };
        case SPELL_ATTR0_HEARTBEAT_RESIST_CHECK: return { "SPELL_ATTR0_HEARTBEAT_RESIST_CHECK", "Periodic resistance checks", "Periodically re-rolls against resistance to potentially expire aura early" };
        case SPELL_ATTR0_CANT_CANCEL: return { "SPELL_ATTR0_CANT_CANCEL", "Aura cannot be cancelled", "Prevents the player from voluntarily canceling a positive aura" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr0>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr0 EnumUtils<SpellAttr0>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR0_UNK0;
        case 1: return SPELL_ATTR0_REQ_AMMO;
        case 2: return SPELL_ATTR0_ON_NEXT_SWING;
        case 3: return SPELL_ATTR0_IS_REPLENISHMENT;
        case 4: return SPELL_ATTR0_ABILITY;
        case 5: return SPELL_ATTR0_TRADESPELL;
        case 6: return SPELL_ATTR0_PASSIVE;
        case 7: return SPELL_ATTR0_HIDDEN_CLIENTSIDE;
        case 8: return SPELL_ATTR0_HIDE_IN_COMBAT_LOG;
        case 9: return SPELL_ATTR0_TARGET_MAINHAND_ITEM;
        case 10: return SPELL_ATTR0_ON_NEXT_SWING_2;
        case 11: return SPELL_ATTR0_UNK11;
        case 12: return SPELL_ATTR0_DAYTIME_ONLY;
        case 13: return SPELL_ATTR0_NIGHT_ONLY;
        case 14: return SPELL_ATTR0_INDOORS_ONLY;
        case 15: return SPELL_ATTR0_OUTDOORS_ONLY;
        case 16: return SPELL_ATTR0_NOT_SHAPESHIFT;
        case 17: return SPELL_ATTR0_ONLY_STEALTHED;
        case 18: return SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE;
        case 19: return SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION;
        case 20: return SPELL_ATTR0_STOP_ATTACK_TARGET;
        case 21: return SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK;
        case 22: return SPELL_ATTR0_CAST_TRACK_TARGET;
        case 23: return SPELL_ATTR0_CASTABLE_WHILE_DEAD;
        case 24: return SPELL_ATTR0_CASTABLE_WHILE_MOUNTED;
        case 25: return SPELL_ATTR0_DISABLED_WHILE_ACTIVE;
        case 26: return SPELL_ATTR0_NEGATIVE_1;
        case 27: return SPELL_ATTR0_CASTABLE_WHILE_SITTING;
        case 28: return SPELL_ATTR0_CANT_USED_IN_COMBAT;
        case 29: return SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY;
        case 30: return SPELL_ATTR0_HEARTBEAT_RESIST_CHECK;
        case 31: return SPELL_ATTR0_CANT_CANCEL;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr0>::ToIndex(SpellAttr0 value)
{
    switch (value)
    {
        case SPELL_ATTR0_UNK0: return 0;
        case SPELL_ATTR0_REQ_AMMO: return 1;
        case SPELL_ATTR0_ON_NEXT_SWING: return 2;
        case SPELL_ATTR0_IS_REPLENISHMENT: return 3;
        case SPELL_ATTR0_ABILITY: return 4;
        case SPELL_ATTR0_TRADESPELL: return 5;
        case SPELL_ATTR0_PASSIVE: return 6;
        case SPELL_ATTR0_HIDDEN_CLIENTSIDE: return 7;
        case SPELL_ATTR0_HIDE_IN_COMBAT_LOG: return 8;
        case SPELL_ATTR0_TARGET_MAINHAND_ITEM: return 9;
        case SPELL_ATTR0_ON_NEXT_SWING_2: return 10;
        case SPELL_ATTR0_UNK11: return 11;
        case SPELL_ATTR0_DAYTIME_ONLY: return 12;
        case SPELL_ATTR0_NIGHT_ONLY: return 13;
        case SPELL_ATTR0_INDOORS_ONLY: return 14;
        case SPELL_ATTR0_OUTDOORS_ONLY: return 15;
        case SPELL_ATTR0_NOT_SHAPESHIFT: return 16;
        case SPELL_ATTR0_ONLY_STEALTHED: return 17;
        case SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE: return 18;
        case SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION: return 19;
        case SPELL_ATTR0_STOP_ATTACK_TARGET: return 20;
        case SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK: return 21;
        case SPELL_ATTR0_CAST_TRACK_TARGET: return 22;
        case SPELL_ATTR0_CASTABLE_WHILE_DEAD: return 23;
        case SPELL_ATTR0_CASTABLE_WHILE_MOUNTED: return 24;
        case SPELL_ATTR0_DISABLED_WHILE_ACTIVE: return 25;
        case SPELL_ATTR0_NEGATIVE_1: return 26;
        case SPELL_ATTR0_CASTABLE_WHILE_SITTING: return 27;
        case SPELL_ATTR0_CANT_USED_IN_COMBAT: return 28;
        case SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY: return 29;
        case SPELL_ATTR0_HEARTBEAT_RESIST_CHECK: return 30;
        case SPELL_ATTR0_CANT_CANCEL: return 31;
        default: throw std::out_of_range("value");
    }
}

/******************************************************************\
|* data for enum 'SpellAttr1' in 'SharedDefines.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr1>::ToString(SpellAttr1 value)
{
    switch (value)
    {
        case SPELL_ATTR1_DISMISS_PET: return { "SPELL_ATTR1_DISMISS_PET", "Dismiss Pet on cast", "Without this attribute, summoning spells will fail if caster already has a pet" };
        case SPELL_ATTR1_DRAIN_ALL_POWER: return { "SPELL_ATTR1_DRAIN_ALL_POWER", "Drain all power", "Ignores listed power cost and drains entire pool instead" };
        case SPELL_ATTR1_CHANNELED_1: return { "SPELL_ATTR1_CHANNELED_1", "Channeled (type 1)", "Both \042channeled\042 attributes have identical handling in server & client" };
        case SPELL_ATTR1_CANT_BE_REDIRECTED: return { "SPELL_ATTR1_CANT_BE_REDIRECTED", "Ignore redirection effects", "Spell will not be attracted by SPELL_MAGNET auras (Grounding Totem)" };
        case SPELL_ATTR1_UNK4: return { "SPELL_ATTR1_UNK4", "Unknown attribute 4@Attr1", "" };
        case SPELL_ATTR1_NOT_BREAK_STEALTH: return { "SPELL_ATTR1_NOT_BREAK_STEALTH", "Does not break stealth", "" };
        case SPELL_ATTR1_CHANNELED_2: return { "SPELL_ATTR1_CHANNELED_2", "Channeled (type 2)", "Both \042channeled\042 attributes have identical handling in server & client" };
        case SPELL_ATTR1_CANT_BE_REFLECTED: return { "SPELL_ATTR1_CANT_BE_REFLECTED", "Ignore reflection effects", "Spell will pierce through Spell Reflection and similar" };
        case SPELL_ATTR1_CANT_TARGET_IN_COMBAT: return { "SPELL_ATTR1_CANT_TARGET_IN_COMBAT", "Target cannot be in combat", "" };
        case SPELL_ATTR1_MELEE_COMBAT_START: return { "SPELL_ATTR1_MELEE_COMBAT_START", "Starts auto-attack (client only)", "Caster will begin auto-attacking the target on cast" };
        case SPELL_ATTR1_NO_THREAT: return { "SPELL_ATTR1_NO_THREAT", "Does not generate threat", "Also does not cause target to engage" };
        case SPELL_ATTR1_DONT_REFRESH_DURATION_ON_RECAST: return { "SPELL_ATTR1_DONT_REFRESH_DURATION_ON_RECAST", "Aura will not refresh its duration when recast", "" };
        case SPELL_ATTR1_IS_PICKPOCKET: return { "SPELL_ATTR1_IS_PICKPOCKET", "Pickpocket (client only)", "" };
        case SPELL_ATTR1_FARSIGHT: return { "SPELL_ATTR1_FARSIGHT", "Farsight aura (client only)", "" };
        case SPELL_ATTR1_CHANNEL_TRACK_TARGET: return { "SPELL_ATTR1_CHANNEL_TRACK_TARGET", "Track target while channeling", "While channeling, adjust facing to face target" };
        case SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY: return { "SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY", "Immunity cancels preapplied auras", "For immunity spells, cancel all auras that this spell would make you immune to when the spell is applied" };
        case SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE: return { "SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE", "Unaffected by school immunities", "Will not pierce Divine Shield, Ice Block and other full invulnerabilities" };
        case SPELL_ATTR1_UNAUTOCASTABLE_BY_PET: return { "SPELL_ATTR1_UNAUTOCASTABLE_BY_PET", "Cannot be autocast by pet", "" };
        case SPELL_ATTR1_PREVENTS_ANIM: return { "SPELL_ATTR1_PREVENTS_ANIM", "NYI, auras apply UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT", "" };
        case SPELL_ATTR1_CANT_TARGET_SELF: return { "SPELL_ATTR1_CANT_TARGET_SELF", "Cannot be self-cast", "" };
        case SPELL_ATTR1_REQ_COMBO_POINTS1: return { "SPELL_ATTR1_REQ_COMBO_POINTS1", "Requires combo points (type 1)", "" };
        case SPELL_ATTR1_UNK21: return { "SPELL_ATTR1_UNK21", "Unknown attribute 21@Attr1", "" };
        case SPELL_ATTR1_REQ_COMBO_POINTS2: return { "SPELL_ATTR1_REQ_COMBO_POINTS2", "Requires combo points (type 2)", "" };
        case SPELL_ATTR1_UNK23: return { "SPELL_ATTR1_UNK23", "Unknwon attribute 23@Attr1", "" };
        case SPELL_ATTR1_IS_FISHING: return { "SPELL_ATTR1_IS_FISHING", "Fishing (client only)", "" };
        case SPELL_ATTR1_UNK25: return { "SPELL_ATTR1_UNK25", "Unknown attribute 25@Attr1", "" };
        case SPELL_ATTR1_REQUIRE_ALL_TARGETS: return { "SPELL_ATTR1_REQUIRE_ALL_TARGETS", "Require All Targets", "" };
        case SPELL_ATTR1_UNK27: return { "SPELL_ATTR1_UNK27", "Unknown attribute 27@Attr1", "Melee spell?" };
        case SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR: return { "SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR", "Hide in aura bar (client only)", "" };
        case SPELL_ATTR1_CHANNEL_DISPLAY_SPELL_NAME: return { "SPELL_ATTR1_CHANNEL_DISPLAY_SPELL_NAME", "Show spell name during channel (client only)", "" };
        case SPELL_ATTR1_ENABLE_AT_DODGE: return { "SPELL_ATTR1_ENABLE_AT_DODGE", "Enable at dodge", "" };
        case SPELL_ATTR1_UNK31: return { "SPELL_ATTR1_UNK31", "Unknown attribute 31@Attr1", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr1>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr1 EnumUtils<SpellAttr1>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR1_DISMISS_PET;
        case 1: return SPELL_ATTR1_DRAIN_ALL_POWER;
        case 2: return SPELL_ATTR1_CHANNELED_1;
        case 3: return SPELL_ATTR1_CANT_BE_REDIRECTED;
        case 4: return SPELL_ATTR1_UNK4;
        case 5: return SPELL_ATTR1_NOT_BREAK_STEALTH;
        case 6: return SPELL_ATTR1_CHANNELED_2;
        case 7: return SPELL_ATTR1_CANT_BE_REFLECTED;
        case 8: return SPELL_ATTR1_CANT_TARGET_IN_COMBAT;
        case 9: return SPELL_ATTR1_MELEE_COMBAT_START;
        case 10: return SPELL_ATTR1_NO_THREAT;
        case 11: return SPELL_ATTR1_DONT_REFRESH_DURATION_ON_RECAST;
        case 12: return SPELL_ATTR1_IS_PICKPOCKET;
        case 13: return SPELL_ATTR1_FARSIGHT;
        case 14: return SPELL_ATTR1_CHANNEL_TRACK_TARGET;
        case 15: return SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY;
        case 16: return SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE;
        case 17: return SPELL_ATTR1_UNAUTOCASTABLE_BY_PET;
        case 18: return SPELL_ATTR1_PREVENTS_ANIM;
        case 19: return SPELL_ATTR1_CANT_TARGET_SELF;
        case 20: return SPELL_ATTR1_REQ_COMBO_POINTS1;
        case 21: return SPELL_ATTR1_UNK21;
        case 22: return SPELL_ATTR1_REQ_COMBO_POINTS2;
        case 23: return SPELL_ATTR1_UNK23;
        case 24: return SPELL_ATTR1_IS_FISHING;
        case 25: return SPELL_ATTR1_UNK25;
        case 26: return SPELL_ATTR1_REQUIRE_ALL_TARGETS;
        case 27: return SPELL_ATTR1_UNK27;
        case 28: return SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR;
        case 29: return SPELL_ATTR1_CHANNEL_DISPLAY_SPELL_NAME;
        case 30: return SPELL_ATTR1_ENABLE_AT_DODGE;
        case 31: return SPELL_ATTR1_UNK31;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr1>::ToIndex(SpellAttr1 value)
{
    switch (value)
    {
        case SPELL_ATTR1_DISMISS_PET: return 0;
        case SPELL_ATTR1_DRAIN_ALL_POWER: return 1;
        case SPELL_ATTR1_CHANNELED_1: return 2;
        case SPELL_ATTR1_CANT_BE_REDIRECTED: return 3;
        case SPELL_ATTR1_UNK4: return 4;
        case SPELL_ATTR1_NOT_BREAK_STEALTH: return 5;
        case SPELL_ATTR1_CHANNELED_2: return 6;
        case SPELL_ATTR1_CANT_BE_REFLECTED: return 7;
        case SPELL_ATTR1_CANT_TARGET_IN_COMBAT: return 8;
        case SPELL_ATTR1_MELEE_COMBAT_START: return 9;
        case SPELL_ATTR1_NO_THREAT: return 10;
        case SPELL_ATTR1_DONT_REFRESH_DURATION_ON_RECAST: return 11;
        case SPELL_ATTR1_IS_PICKPOCKET: return 12;
        case SPELL_ATTR1_FARSIGHT: return 13;
        case SPELL_ATTR1_CHANNEL_TRACK_TARGET: return 14;
        case SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY: return 15;
        case SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE: return 16;
        case SPELL_ATTR1_UNAUTOCASTABLE_BY_PET: return 17;
        case SPELL_ATTR1_PREVENTS_ANIM: return 18;
        case SPELL_ATTR1_CANT_TARGET_SELF: return 19;
        case SPELL_ATTR1_REQ_COMBO_POINTS1: return 20;
        case SPELL_ATTR1_UNK21: return 21;
        case SPELL_ATTR1_REQ_COMBO_POINTS2: return 22;
        case SPELL_ATTR1_UNK23: return 23;
        case SPELL_ATTR1_IS_FISHING: return 24;
        case SPELL_ATTR1_UNK25: return 25;
        case SPELL_ATTR1_REQUIRE_ALL_TARGETS: return 26;
        case SPELL_ATTR1_UNK27: return 27;
        case SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR: return 28;
        case SPELL_ATTR1_CHANNEL_DISPLAY_SPELL_NAME: return 29;
        case SPELL_ATTR1_ENABLE_AT_DODGE: return 30;
        case SPELL_ATTR1_UNK31: return 31;
        default: throw std::out_of_range("value");
    }
}

/******************************************************************\
|* data for enum 'SpellAttr2' in 'SharedDefines.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr2>::ToString(SpellAttr2 value)
{
    switch (value)
    {
        case SPELL_ATTR2_CAN_TARGET_DEAD: return { "SPELL_ATTR2_CAN_TARGET_DEAD", "Can target dead players or corpses", "" };
        case SPELL_ATTR2_UNK1: return { "SPELL_ATTR2_UNK1", "Unknown attribute 1@Attr2", "" };
        case SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS: return { "SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS", "Ignore Line of Sight", "" };
        case SPELL_ATTR2_UNK3: return { "SPELL_ATTR2_UNK3", "Ignore aura scaling", "" };
        case SPELL_ATTR2_DISPLAY_IN_STANCE_BAR: return { "SPELL_ATTR2_DISPLAY_IN_STANCE_BAR", "Show in stance bar (client only)", "" };
        case SPELL_ATTR2_AUTOREPEAT_FLAG: return { "SPELL_ATTR2_AUTOREPEAT_FLAG", "Ranged auto-attack spell", "" };
        case SPELL_ATTR2_CANT_TARGET_TAPPED: return { "SPELL_ATTR2_CANT_TARGET_TAPPED", "Cannot target others' tapped units", "Can only target untapped units, or those tapped by caster" };
        case SPELL_ATTR2_UNK7: return { "SPELL_ATTR2_UNK7", "Unknown attribute 7@Attr2", "" };
        case SPELL_ATTR2_UNK8: return { "SPELL_ATTR2_UNK8", "Unknown attribute 8@Attr2", "" };
        case SPELL_ATTR2_UNK9: return { "SPELL_ATTR2_UNK9", "Unknown attribute 9@Attr2", "" };
        case SPELL_ATTR2_UNK10: return { "SPELL_ATTR2_UNK10", "Unknown attribute 10@Attr2", "Related to taming?" };
        case SPELL_ATTR2_HEALTH_FUNNEL: return { "SPELL_ATTR2_HEALTH_FUNNEL", "Health Funnel", "" };
        case SPELL_ATTR2_UNK12: return { "SPELL_ATTR2_UNK12", "Unknown attribute 12@Attr2", "" };
        case SPELL_ATTR2_PRESERVE_ENCHANT_IN_ARENA: return { "SPELL_ATTR2_PRESERVE_ENCHANT_IN_ARENA", "Enchant persists when entering arena", "" };
        case SPELL_ATTR2_UNK14: return { "SPELL_ATTR2_UNK14", "Unknown attribute 14@Attr2", "" };
        case SPELL_ATTR2_UNK15: return { "SPELL_ATTR2_UNK15", "Unknown attribute 15@Attr2", "" };
        case SPELL_ATTR2_TAME_BEAST: return { "SPELL_ATTR2_TAME_BEAST", "Tame Beast", "" };
        case SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS: return { "SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS", "Don't reset swing timer", "Does not reset melee/ranged autoattack timer on cast" };
        case SPELL_ATTR2_REQ_DEAD_PET: return { "SPELL_ATTR2_REQ_DEAD_PET", "Requires dead pet", "" };
        case SPELL_ATTR2_NOT_NEED_SHAPESHIFT: return { "SPELL_ATTR2_NOT_NEED_SHAPESHIFT", "Also allow outside shapeshift", "Even if Stances are nonzero, allow spell to be cast outside of shapeshift (though not in a different shapeshift)" };
        case SPELL_ATTR2_UNK20: return { "SPELL_ATTR2_UNK20", "Unknown attribute 20@Attr2", "" };
        case SPELL_ATTR2_FAIL_ON_ALL_TARGETS_IMMUNE: return { "SPELL_ATTR2_FAIL_ON_ALL_TARGETS_IMMUNE", "Fail on all targets immune", "Causes BG flags to be dropped if combined with ATTR1_DISPEL_AURAS_ON_IMMUNITY" };
        case SPELL_ATTR2_UNK22: return { "SPELL_ATTR2_UNK22", "Unknown attribute 22@Attr2", "" };
        case SPELL_ATTR2_IS_ARCANE_CONCENTRATION: return { "SPELL_ATTR2_IS_ARCANE_CONCENTRATION", "Arcane Concentration", "" };
        case SPELL_ATTR2_UNK24: return { "SPELL_ATTR2_UNK24", "Unknown attribute 24@Attr2", "" };
        case SPELL_ATTR2_UNK25: return { "SPELL_ATTR2_UNK25", "Unknown attribute 25@Attr2", "" };
        case SPELL_ATTR2_UNAFFECTED_BY_AURA_SCHOOL_IMMUNE: return { "SPELL_ATTR2_UNAFFECTED_BY_AURA_SCHOOL_IMMUNE", "Pierce aura application immunities", "Allow aura to be applied despite target being immune to new aura applications" };
        case SPELL_ATTR2_UNK27: return { "SPELL_ATTR2_UNK27", "Unknown attribute 27@Attr2", "" };
        case SPELL_ATTR2_UNK28: return { "SPELL_ATTR2_UNK28", "Unknown attribute 28@Attr2", "" };
        case SPELL_ATTR2_CANT_CRIT: return { "SPELL_ATTR2_CANT_CRIT", "Cannot critically strike", "" };
        case SPELL_ATTR2_TRIGGERED_CAN_TRIGGER_PROC: return { "SPELL_ATTR2_TRIGGERED_CAN_TRIGGER_PROC", "Allow triggered spell to trigger (type 1)", "Without this attribute, any triggered spell will be unable to trigger other auras' procs" };
        case SPELL_ATTR2_FOOD_BUFF: return { "SPELL_ATTR2_FOOD_BUFF", "Food buff (client only)", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr2>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr2 EnumUtils<SpellAttr2>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR2_CAN_TARGET_DEAD;
        case 1: return SPELL_ATTR2_UNK1;
        case 2: return SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS;
        case 3: return SPELL_ATTR2_UNK3;
        case 4: return SPELL_ATTR2_DISPLAY_IN_STANCE_BAR;
        case 5: return SPELL_ATTR2_AUTOREPEAT_FLAG;
        case 6: return SPELL_ATTR2_CANT_TARGET_TAPPED;
        case 7: return SPELL_ATTR2_UNK7;
        case 8: return SPELL_ATTR2_UNK8;
        case 9: return SPELL_ATTR2_UNK9;
        case 10: return SPELL_ATTR2_UNK10;
        case 11: return SPELL_ATTR2_HEALTH_FUNNEL;
        case 12: return SPELL_ATTR2_UNK12;
        case 13: return SPELL_ATTR2_PRESERVE_ENCHANT_IN_ARENA;
        case 14: return SPELL_ATTR2_UNK14;
        case 15: return SPELL_ATTR2_UNK15;
        case 16: return SPELL_ATTR2_TAME_BEAST;
        case 17: return SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS;
        case 18: return SPELL_ATTR2_REQ_DEAD_PET;
        case 19: return SPELL_ATTR2_NOT_NEED_SHAPESHIFT;
        case 20: return SPELL_ATTR2_UNK20;
        case 21: return SPELL_ATTR2_FAIL_ON_ALL_TARGETS_IMMUNE;
        case 22: return SPELL_ATTR2_UNK22;
        case 23: return SPELL_ATTR2_IS_ARCANE_CONCENTRATION;
        case 24: return SPELL_ATTR2_UNK24;
        case 25: return SPELL_ATTR2_UNK25;
        case 26: return SPELL_ATTR2_UNAFFECTED_BY_AURA_SCHOOL_IMMUNE;
        case 27: return SPELL_ATTR2_UNK27;
        case 28: return SPELL_ATTR2_UNK28;
        case 29: return SPELL_ATTR2_CANT_CRIT;
        case 30: return SPELL_ATTR2_TRIGGERED_CAN_TRIGGER_PROC;
        case 31: return SPELL_ATTR2_FOOD_BUFF;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr2>::ToIndex(SpellAttr2 value)
{
    switch (value)
    {
        case SPELL_ATTR2_CAN_TARGET_DEAD: return 0;
        case SPELL_ATTR2_UNK1: return 1;
        case SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS: return 2;
        case SPELL_ATTR2_UNK3: return 3;
        case SPELL_ATTR2_DISPLAY_IN_STANCE_BAR: return 4;
        case SPELL_ATTR2_AUTOREPEAT_FLAG: return 5;
        case SPELL_ATTR2_CANT_TARGET_TAPPED: return 6;
        case SPELL_ATTR2_UNK7: return 7;
        case SPELL_ATTR2_UNK8: return 8;
        case SPELL_ATTR2_UNK9: return 9;
        case SPELL_ATTR2_UNK10: return 10;
        case SPELL_ATTR2_HEALTH_FUNNEL: return 11;
        case SPELL_ATTR2_UNK12: return 12;
        case SPELL_ATTR2_PRESERVE_ENCHANT_IN_ARENA: return 13;
        case SPELL_ATTR2_UNK14: return 14;
        case SPELL_ATTR2_UNK15: return 15;
        case SPELL_ATTR2_TAME_BEAST: return 16;
        case SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS: return 17;
        case SPELL_ATTR2_REQ_DEAD_PET: return 18;
        case SPELL_ATTR2_NOT_NEED_SHAPESHIFT: return 19;
        case SPELL_ATTR2_UNK20: return 20;
        case SPELL_ATTR2_FAIL_ON_ALL_TARGETS_IMMUNE: return 21;
        case SPELL_ATTR2_UNK22: return 22;
        case SPELL_ATTR2_IS_ARCANE_CONCENTRATION: return 23;
        case SPELL_ATTR2_UNK24: return 24;
        case SPELL_ATTR2_UNK25: return 25;
        case SPELL_ATTR2_UNAFFECTED_BY_AURA_SCHOOL_IMMUNE: return 26;
        case SPELL_ATTR2_UNK27: return 27;
        case SPELL_ATTR2_UNK28: return 28;
        case SPELL_ATTR2_CANT_CRIT: return 29;
        case SPELL_ATTR2_TRIGGERED_CAN_TRIGGER_PROC: return 30;
        case SPELL_ATTR2_FOOD_BUFF: return 31;
        default: throw std::out_of_range("value");
    }
}

/******************************************************************\
|* data for enum 'SpellAttr3' in 'SharedDefines.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr3>::ToString(SpellAttr3 value)
{
    switch (value)
    {
        case SPELL_ATTR3_UNK0: return { "SPELL_ATTR3_UNK0", "Unknown attribute 0@Attr3", "" };
        case SPELL_ATTR3_IGNORE_PROC_SUBCLASS_MASK: return { "SPELL_ATTR3_IGNORE_PROC_SUBCLASS_MASK", "SPELL_ATTR3_IGNORE_PROC_SUBCLASS_MASK", "1 Ignores subclass mask check when checking proc" };
        case SPELL_ATTR3_UNK2: return { "SPELL_ATTR3_UNK2", "Unknown attribute 2@Attr3", "" };
        case SPELL_ATTR3_COMPLETELY_BLOCKED: return { "SPELL_ATTR3_COMPLETELY_BLOCKED", "Completely Blocked", "" };
        case SPELL_ATTR3_IGNORE_RESURRECTION_TIMER: return { "SPELL_ATTR3_IGNORE_RESURRECTION_TIMER", "Ignore resurrection timer", "" };
        case SPELL_ATTR3_UNK5: return { "SPELL_ATTR3_UNK5", "Unknown attribute 5@Attr3", "" };
        case SPELL_ATTR3_UNK6: return { "SPELL_ATTR3_UNK6", "Unknown attribute 6@Attr3", "" };
        case SPELL_ATTR3_STACK_FOR_DIFF_CASTERS: return { "SPELL_ATTR3_STACK_FOR_DIFF_CASTERS", "Stack separately for each caster", "" };
        case SPELL_ATTR3_ONLY_TARGET_PLAYERS: return { "SPELL_ATTR3_ONLY_TARGET_PLAYERS", "Can only target players", "" };
        case SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2: return { "SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2", "Allow triggered spell to trigger (type 2)", "Without this attribute, any triggered spell will be unable to trigger other auras' procs" };
        case SPELL_ATTR3_MAIN_HAND: return { "SPELL_ATTR3_MAIN_HAND", "Require main hand weapon", "" };
        case SPELL_ATTR3_BATTLEGROUND: return { "SPELL_ATTR3_BATTLEGROUND", "Can only be cast in battleground", "" };
        case SPELL_ATTR3_ONLY_TARGET_GHOSTS: return { "SPELL_ATTR3_ONLY_TARGET_GHOSTS", "Can only target ghost players", "" };
        case SPELL_ATTR3_DONT_DISPLAY_CHANNEL_BAR: return { "SPELL_ATTR3_DONT_DISPLAY_CHANNEL_BAR", "Do not display channel bar (client only)", "" };
        case SPELL_ATTR3_IS_HONORLESS_TARGET: return { "SPELL_ATTR3_IS_HONORLESS_TARGET", "Honorless Target", "" };
        case SPELL_ATTR3_UNK15: return { "SPELL_ATTR3_UNK15", "Unknown attribute 15@Attr3", "Auto Shoot, Shoot, Throw - ranged normal attack attribute?" };
        case SPELL_ATTR3_CANT_TRIGGER_PROC: return { "SPELL_ATTR3_CANT_TRIGGER_PROC", "Cannot trigger procs", "" };
        case SPELL_ATTR3_NO_INITIAL_AGGRO: return { "SPELL_ATTR3_NO_INITIAL_AGGRO", "No initial aggro", "" };
        case SPELL_ATTR3_IGNORE_HIT_RESULT: return { "SPELL_ATTR3_IGNORE_HIT_RESULT", "Ignore hit result", "Spell cannot miss, or be dodged/parried/blocked" };
        case SPELL_ATTR3_DISABLE_PROC: return { "SPELL_ATTR3_DISABLE_PROC", "Cannot trigger spells during aura proc", "" };
        case SPELL_ATTR3_DEATH_PERSISTENT: return { "SPELL_ATTR3_DEATH_PERSISTENT", "Persists through death", "" };
        case SPELL_ATTR3_UNK21: return { "SPELL_ATTR3_UNK21", "Unknown attribute 21@Attr3", "" };
        case SPELL_ATTR3_REQ_WAND: return { "SPELL_ATTR3_REQ_WAND", "Requires equipped Wand", "" };
        case SPELL_ATTR3_UNK23: return { "SPELL_ATTR3_UNK23", "Unknown attribute 23@Attr3", "" };
        case SPELL_ATTR3_REQ_OFFHAND: return { "SPELL_ATTR3_REQ_OFFHAND", "Requires offhand weapon", "" };
        case SPELL_ATTR3_TREAT_AS_PERIODIC: return { "SPELL_ATTR3_TREAT_AS_PERIODIC", "Treat as periodic effect", "" };
        case SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED: return { "SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED", "Can trigger from triggered spells", "" };
        case SPELL_ATTR3_DRAIN_SOUL: return { "SPELL_ATTR3_DRAIN_SOUL", "Drain Soul", "" };
        case SPELL_ATTR3_UNK28: return { "SPELL_ATTR3_UNK28", "Unknown attribute 28@Attr3", "" };
        case SPELL_ATTR3_NO_DONE_BONUS: return { "SPELL_ATTR3_NO_DONE_BONUS", "Damage dealt is unaffected by modifiers", "" };
        case SPELL_ATTR3_DONT_DISPLAY_RANGE: return { "SPELL_ATTR3_DONT_DISPLAY_RANGE", "Do not show range in tooltip (client only)", "" };
        case SPELL_ATTR3_UNK31: return { "SPELL_ATTR3_UNK31", "Unknown attribute 31@Attr3", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr3>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr3 EnumUtils<SpellAttr3>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR3_UNK0;
        case 1: return SPELL_ATTR3_IGNORE_PROC_SUBCLASS_MASK;
        case 2: return SPELL_ATTR3_UNK2;
        case 3: return SPELL_ATTR3_COMPLETELY_BLOCKED;
        case 4: return SPELL_ATTR3_IGNORE_RESURRECTION_TIMER;
        case 5: return SPELL_ATTR3_UNK5;
        case 6: return SPELL_ATTR3_UNK6;
        case 7: return SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
        case 8: return SPELL_ATTR3_ONLY_TARGET_PLAYERS;
        case 9: return SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2;
        case 10: return SPELL_ATTR3_MAIN_HAND;
        case 11: return SPELL_ATTR3_BATTLEGROUND;
        case 12: return SPELL_ATTR3_ONLY_TARGET_GHOSTS;
        case 13: return SPELL_ATTR3_DONT_DISPLAY_CHANNEL_BAR;
        case 14: return SPELL_ATTR3_IS_HONORLESS_TARGET;
        case 15: return SPELL_ATTR3_UNK15;
        case 16: return SPELL_ATTR3_CANT_TRIGGER_PROC;
        case 17: return SPELL_ATTR3_NO_INITIAL_AGGRO;
        case 18: return SPELL_ATTR3_IGNORE_HIT_RESULT;
        case 19: return SPELL_ATTR3_DISABLE_PROC;
        case 20: return SPELL_ATTR3_DEATH_PERSISTENT;
        case 21: return SPELL_ATTR3_UNK21;
        case 22: return SPELL_ATTR3_REQ_WAND;
        case 23: return SPELL_ATTR3_UNK23;
        case 24: return SPELL_ATTR3_REQ_OFFHAND;
        case 25: return SPELL_ATTR3_TREAT_AS_PERIODIC;
        case 26: return SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED;
        case 27: return SPELL_ATTR3_DRAIN_SOUL;
        case 28: return SPELL_ATTR3_UNK28;
        case 29: return SPELL_ATTR3_NO_DONE_BONUS;
        case 30: return SPELL_ATTR3_DONT_DISPLAY_RANGE;
        case 31: return SPELL_ATTR3_UNK31;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr3>::ToIndex(SpellAttr3 value)
{
    switch (value)
    {
        case SPELL_ATTR3_UNK0: return 0;
        case SPELL_ATTR3_IGNORE_PROC_SUBCLASS_MASK: return 1;
        case SPELL_ATTR3_UNK2: return 2;
        case SPELL_ATTR3_COMPLETELY_BLOCKED: return 3;
        case SPELL_ATTR3_IGNORE_RESURRECTION_TIMER: return 4;
        case SPELL_ATTR3_UNK5: return 5;
        case SPELL_ATTR3_UNK6: return 6;
        case SPELL_ATTR3_STACK_FOR_DIFF_CASTERS: return 7;
        case SPELL_ATTR3_ONLY_TARGET_PLAYERS: return 8;
        case SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2: return 9;
        case SPELL_ATTR3_MAIN_HAND: return 10;
        case SPELL_ATTR3_BATTLEGROUND: return 11;
        case SPELL_ATTR3_ONLY_TARGET_GHOSTS: return 12;
        case SPELL_ATTR3_DONT_DISPLAY_CHANNEL_BAR: return 13;
        case SPELL_ATTR3_IS_HONORLESS_TARGET: return 14;
        case SPELL_ATTR3_UNK15: return 15;
        case SPELL_ATTR3_CANT_TRIGGER_PROC: return 16;
        case SPELL_ATTR3_NO_INITIAL_AGGRO: return 17;
        case SPELL_ATTR3_IGNORE_HIT_RESULT: return 18;
        case SPELL_ATTR3_DISABLE_PROC: return 19;
        case SPELL_ATTR3_DEATH_PERSISTENT: return 20;
        case SPELL_ATTR3_UNK21: return 21;
        case SPELL_ATTR3_REQ_WAND: return 22;
        case SPELL_ATTR3_UNK23: return 23;
        case SPELL_ATTR3_REQ_OFFHAND: return 24;
        case SPELL_ATTR3_TREAT_AS_PERIODIC: return 25;
        case SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED: return 26;
        case SPELL_ATTR3_DRAIN_SOUL: return 27;
        case SPELL_ATTR3_UNK28: return 28;
        case SPELL_ATTR3_NO_DONE_BONUS: return 29;
        case SPELL_ATTR3_DONT_DISPLAY_RANGE: return 30;
        case SPELL_ATTR3_UNK31: return 31;
        default: throw std::out_of_range("value");
    }
}

/******************************************************************\
|* data for enum 'SpellAttr4' in 'SharedDefines.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr4>::ToString(SpellAttr4 value)
{
    switch (value)
    {
        case SPELL_ATTR4_IGNORE_RESISTANCES: return { "SPELL_ATTR4_IGNORE_RESISTANCES", "Cannot be resisted", "" };
        case SPELL_ATTR4_PROC_ONLY_ON_CASTER: return { "SPELL_ATTR4_PROC_ONLY_ON_CASTER", "Only proc on self-cast", "" };
        case SPELL_ATTR4_FADES_WHILE_LOGGED_OUT: return { "SPELL_ATTR4_FADES_WHILE_LOGGED_OUT", "Buff expires while offline", "Debuffs (except Resurrection Sickness) will automatically do this" };
        case SPELL_ATTR4_UNK3: return { "SPELL_ATTR4_UNK3", "Unknown attribute 3@Attr4", "" };
        case SPELL_ATTR4_UNK4: return { "SPELL_ATTR4_UNK4", "Treat as delayed spell", "" };
        case SPELL_ATTR4_UNK5: return { "SPELL_ATTR4_UNK5", "Unknown attribute 5@Attr4", "" };
        case SPELL_ATTR4_NOT_STEALABLE: return { "SPELL_ATTR4_NOT_STEALABLE", "Aura cannot be stolen", "" };
        case SPELL_ATTR4_CAN_CAST_WHILE_CASTING: return { "SPELL_ATTR4_CAN_CAST_WHILE_CASTING", "Can be cast while casting", "Ignores already in-progress cast and still casts" };
        case SPELL_ATTR4_FIXED_DAMAGE: return { "SPELL_ATTR4_FIXED_DAMAGE", "Deals fixed damage", "" };
        case SPELL_ATTR4_TRIGGER_ACTIVATE: return { "SPELL_ATTR4_TRIGGER_ACTIVATE", "Spell is initially disabled (client only)", "" };
        case SPELL_ATTR4_SPELL_VS_EXTEND_COST: return { "SPELL_ATTR4_SPELL_VS_EXTEND_COST", "Attack speed modifies cost", "Adds 10 to power cost for each 1s of weapon speed" };
        case SPELL_ATTR4_UNK11: return { "SPELL_ATTR4_UNK11", "Unknown attribute 11@Attr4", "" };
        case SPELL_ATTR4_UNK12: return { "SPELL_ATTR4_UNK12", "Unknown attribute 12@Attr4", "" };
        case SPELL_ATTR4_UNK13: return { "SPELL_ATTR4_UNK13", "Unknown attribute 13@Attr4", "" };
        case SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS: return { "SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS", "Damage does not break auras", "" };
        case SPELL_ATTR4_UNK15: return { "SPELL_ATTR4_UNK15", "Unknown attribute 15@Attr4", "" };
        case SPELL_ATTR4_NOT_USABLE_IN_ARENA: return { "SPELL_ATTR4_NOT_USABLE_IN_ARENA", "Not usable in arena", "Makes spell unusable despite CD <= 10min" };
        case SPELL_ATTR4_USABLE_IN_ARENA: return { "SPELL_ATTR4_USABLE_IN_ARENA", "Usable in arena", "Makes spell usable despite CD > 10min" };
        case SPELL_ATTR4_AREA_TARGET_CHAIN: return { "SPELL_ATTR4_AREA_TARGET_CHAIN", "Chain area targets", "[NYI] Hits area targets over time instead of all at once" };
        case SPELL_ATTR4_UNK19: return { "SPELL_ATTR4_UNK19", "Unknown attribute 19@Attr4", "" };
        case SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER: return { "SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER", "Allow self-cast to override stronger aura (client only)", "" };
        case SPELL_ATTR4_DONT_REMOVE_IN_ARENA: return { "SPELL_ATTR4_DONT_REMOVE_IN_ARENA", "Keep when entering arena", "" };
        case SPELL_ATTR4_UNK22: return { "SPELL_ATTR4_UNK22", "Unknown attribute 22@Attr4", "" };
        case SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS: return { "SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS", "Cannot trigger item spells", "" };
        case SPELL_ATTR4_UNK24: return { "SPELL_ATTR4_UNK24", "Unknown attribute 24@Attr4", "Shoot-type spell?" };
        case SPELL_ATTR4_IS_PET_SCALING: return { "SPELL_ATTR4_IS_PET_SCALING", "Pet Scaling aura", "" };
        case SPELL_ATTR4_CAST_ONLY_IN_OUTLAND: return { "SPELL_ATTR4_CAST_ONLY_IN_OUTLAND", "Only in Outland/Northrend", "" };
        case SPELL_ATTR4_FORCE_DISPLAY_CASTBAR: return { "SPELL_ATTR4_FORCE_DISPLAY_CASTBAR", "Force Display Castbar", "" };
        case SPELL_ATTR4_UNK28: return { "SPELL_ATTR4_UNK28", "Unknown attribute 28@Attr4", "" };
        case SPELL_ATTR4_UNK29: return { "SPELL_ATTR4_UNK29", "Unknown attribute 29@Attr4", "" };
        case SPELL_ATTR4_UNK30: return { "SPELL_ATTR4_UNK30", "Unknown attribute 30@Attr4", "" };
        case SPELL_ATTR4_UNK31: return { "SPELL_ATTR4_UNK31", "Unknown attribute 31@Attr4", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr4>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr4 EnumUtils<SpellAttr4>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR4_IGNORE_RESISTANCES;
        case 1: return SPELL_ATTR4_PROC_ONLY_ON_CASTER;
        case 2: return SPELL_ATTR4_FADES_WHILE_LOGGED_OUT;
        case 3: return SPELL_ATTR4_UNK3;
        case 4: return SPELL_ATTR4_UNK4;
        case 5: return SPELL_ATTR4_UNK5;
        case 6: return SPELL_ATTR4_NOT_STEALABLE;
        case 7: return SPELL_ATTR4_CAN_CAST_WHILE_CASTING;
        case 8: return SPELL_ATTR4_FIXED_DAMAGE;
        case 9: return SPELL_ATTR4_TRIGGER_ACTIVATE;
        case 10: return SPELL_ATTR4_SPELL_VS_EXTEND_COST;
        case 11: return SPELL_ATTR4_UNK11;
        case 12: return SPELL_ATTR4_UNK12;
        case 13: return SPELL_ATTR4_UNK13;
        case 14: return SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS;
        case 15: return SPELL_ATTR4_UNK15;
        case 16: return SPELL_ATTR4_NOT_USABLE_IN_ARENA;
        case 17: return SPELL_ATTR4_USABLE_IN_ARENA;
        case 18: return SPELL_ATTR4_AREA_TARGET_CHAIN;
        case 19: return SPELL_ATTR4_UNK19;
        case 20: return SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER;
        case 21: return SPELL_ATTR4_DONT_REMOVE_IN_ARENA;
        case 22: return SPELL_ATTR4_UNK22;
        case 23: return SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS;
        case 24: return SPELL_ATTR4_UNK24;
        case 25: return SPELL_ATTR4_IS_PET_SCALING;
        case 26: return SPELL_ATTR4_CAST_ONLY_IN_OUTLAND;
        case 27: return SPELL_ATTR4_FORCE_DISPLAY_CASTBAR;
        case 28: return SPELL_ATTR4_UNK28;
        case 29: return SPELL_ATTR4_UNK29;
        case 30: return SPELL_ATTR4_UNK30;
        case 31: return SPELL_ATTR4_UNK31;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr4>::ToIndex(SpellAttr4 value)
{
    switch (value)
    {
        case SPELL_ATTR4_IGNORE_RESISTANCES: return 0;
        case SPELL_ATTR4_PROC_ONLY_ON_CASTER: return 1;
        case SPELL_ATTR4_FADES_WHILE_LOGGED_OUT: return 2;
        case SPELL_ATTR4_UNK3: return 3;
        case SPELL_ATTR4_UNK4: return 4;
        case SPELL_ATTR4_UNK5: return 5;
        case SPELL_ATTR4_NOT_STEALABLE: return 6;
        case SPELL_ATTR4_CAN_CAST_WHILE_CASTING: return 7;
        case SPELL_ATTR4_FIXED_DAMAGE: return 8;
        case SPELL_ATTR4_TRIGGER_ACTIVATE: return 9;
        case SPELL_ATTR4_SPELL_VS_EXTEND_COST: return 10;
        case SPELL_ATTR4_UNK11: return 11;
        case SPELL_ATTR4_UNK12: return 12;
        case SPELL_ATTR4_UNK13: return 13;
        case SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS: return 14;
        case SPELL_ATTR4_UNK15: return 15;
        case SPELL_ATTR4_NOT_USABLE_IN_ARENA: return 16;
        case SPELL_ATTR4_USABLE_IN_ARENA: return 17;
        case SPELL_ATTR4_AREA_TARGET_CHAIN: return 18;
        case SPELL_ATTR4_UNK19: return 19;
        case SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER: return 20;
        case SPELL_ATTR4_DONT_REMOVE_IN_ARENA: return 21;
        case SPELL_ATTR4_UNK22: return 22;
        case SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS: return 23;
        case SPELL_ATTR4_UNK24: return 24;
        case SPELL_ATTR4_IS_PET_SCALING: return 25;
        case SPELL_ATTR4_CAST_ONLY_IN_OUTLAND: return 26;
        case SPELL_ATTR4_FORCE_DISPLAY_CASTBAR: return 27;
        case SPELL_ATTR4_UNK28: return 28;
        case SPELL_ATTR4_UNK29: return 29;
        case SPELL_ATTR4_UNK30: return 30;
        case SPELL_ATTR4_UNK31: return 31;
        default: throw std::out_of_range("value");
    }
}

/******************************************************************\
|* data for enum 'SpellAttr5' in 'SharedDefines.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr5>::ToString(SpellAttr5 value)
{
    switch (value)
    {
        case SPELL_ATTR5_CAN_CHANNEL_WHEN_MOVING: return { "SPELL_ATTR5_CAN_CHANNEL_WHEN_MOVING", "Can be channeled while moving", "" };
        case SPELL_ATTR5_NO_REAGENT_WHILE_PREP: return { "SPELL_ATTR5_NO_REAGENT_WHILE_PREP", "No reagents during arena preparation", "" };
        case SPELL_ATTR5_REMOVE_ON_ARENA_ENTER: return { "SPELL_ATTR5_REMOVE_ON_ARENA_ENTER", "Remove when entering arena", "Force this aura to be removed on entering arena, regardless of other properties" };
        case SPELL_ATTR5_USABLE_WHILE_STUNNED: return { "SPELL_ATTR5_USABLE_WHILE_STUNNED", "Usable while stunned", "" };
        case SPELL_ATTR5_UNK4: return { "SPELL_ATTR5_UNK4", "Unknown attribute 4@Attr5", "" };
        case SPELL_ATTR5_SINGLE_TARGET_SPELL: return { "SPELL_ATTR5_SINGLE_TARGET_SPELL", "Single-target aura", "Remove previous application to another unit if applied" };
        case SPELL_ATTR5_UNK6: return { "SPELL_ATTR5_UNK6", "Unknown attribute 6@Attr5", "" };
        case SPELL_ATTR5_UNK7: return { "SPELL_ATTR5_UNK7", "Unknown attribute 7@Attr5", "" };
        case SPELL_ATTR5_CANT_TARGET_PLAYER_CONTROLLED: return { "SPELL_ATTR5_CANT_TARGET_PLAYER_CONTROLLED", "Cannot target player controlled units but can target players", "" };
        case SPELL_ATTR5_START_PERIODIC_AT_APPLY: return { "SPELL_ATTR5_START_PERIODIC_AT_APPLY", "Immediately do periodic tick on apply", "" };
        case SPELL_ATTR5_HIDE_DURATION: return { "SPELL_ATTR5_HIDE_DURATION", "Do not send aura duration to client", "" };
        case SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET: return { "SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET", "Auto-target target of target (client only)", "" };
        case SPELL_ATTR5_UNK12: return { "SPELL_ATTR5_UNK12", "Unknown attribute 12@Attr5", "Cleave related?" };
        case SPELL_ATTR5_HASTE_AFFECT_DURATION: return { "SPELL_ATTR5_HASTE_AFFECT_DURATION", "Duration scales with Haste Rating", "" };
        case SPELL_ATTR5_NOT_USABLE_WHILE_CHARMED: return { "SPELL_ATTR5_NOT_USABLE_WHILE_CHARMED", "Charmed units cannot cast this spell", "" };
        case SPELL_ATTR5_UNK15: return { "SPELL_ATTR5_UNK15", "Unknown attribute 15@Attr5", "Related to multi-target spells?" };
        case SPELL_ATTR5_UNK16: return { "SPELL_ATTR5_UNK16", "Unknown attribute 16@Attr5", "" };
        case SPELL_ATTR5_USABLE_WHILE_FEARED: return { "SPELL_ATTR5_USABLE_WHILE_FEARED", "Usable while feared", "" };
        case SPELL_ATTR5_USABLE_WHILE_CONFUSED: return { "SPELL_ATTR5_USABLE_WHILE_CONFUSED", "Usable while confused", "" };
        case SPELL_ATTR5_DONT_TURN_DURING_CAST: return { "SPELL_ATTR5_DONT_TURN_DURING_CAST", "Do not auto-turn while casting", "" };
        case SPELL_ATTR5_UNK20: return { "SPELL_ATTR5_UNK20", "Unknown attribute 20@Attr5", "" };
        case SPELL_ATTR5_UNK21: return { "SPELL_ATTR5_UNK21", "Unknown attribute 21@Attr5", "" };
        case SPELL_ATTR5_UNK22: return { "SPELL_ATTR5_UNK22", "Unknown attribute 22@Attr5", "" };
        case SPELL_ATTR5_UNK23: return { "SPELL_ATTR5_UNK23", "Unknown attribute 23@Attr5", "" };
        case SPELL_ATTR5_UNK24: return { "SPELL_ATTR5_UNK24", "Unknown attribute 24@Attr5", "" };
        case SPELL_ATTR5_UNK25: return { "SPELL_ATTR5_UNK25", "Unknown attribute 25@Attr5", "" };
        case SPELL_ATTR5_SKIP_CHECKCAST_LOS_CHECK: return { "SPELL_ATTR5_SKIP_CHECKCAST_LOS_CHECK", "Ignore line of sight checks", "" };
        case SPELL_ATTR5_DONT_SHOW_AURA_IF_SELF_CAST: return { "SPELL_ATTR5_DONT_SHOW_AURA_IF_SELF_CAST", "Don't show aura if self-cast (client only)", "" };
        case SPELL_ATTR5_DONT_SHOW_AURA_IF_NOT_SELF_CAST: return { "SPELL_ATTR5_DONT_SHOW_AURA_IF_NOT_SELF_CAST", "Don't show aura unless self-cast (client only)", "" };
        case SPELL_ATTR5_UNK29: return { "SPELL_ATTR5_UNK29", "Unknown attribute 29@Attr5", "" };
        case SPELL_ATTR5_UNK30: return { "SPELL_ATTR5_UNK30", "Unknown attribute 30@Attr5", "" };
        case SPELL_ATTR5_UNK31: return { "SPELL_ATTR5_UNK31", "Unknown attribute 31@Attr5", "Forces nearby enemies to attack caster?" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr5>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr5 EnumUtils<SpellAttr5>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR5_CAN_CHANNEL_WHEN_MOVING;
        case 1: return SPELL_ATTR5_NO_REAGENT_WHILE_PREP;
        case 2: return SPELL_ATTR5_REMOVE_ON_ARENA_ENTER;
        case 3: return SPELL_ATTR5_USABLE_WHILE_STUNNED;
        case 4: return SPELL_ATTR5_UNK4;
        case 5: return SPELL_ATTR5_SINGLE_TARGET_SPELL;
        case 6: return SPELL_ATTR5_UNK6;
        case 7: return SPELL_ATTR5_UNK7;
        case 8: return SPELL_ATTR5_CANT_TARGET_PLAYER_CONTROLLED;
        case 9: return SPELL_ATTR5_START_PERIODIC_AT_APPLY;
        case 10: return SPELL_ATTR5_HIDE_DURATION;
        case 11: return SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET;
        case 12: return SPELL_ATTR5_UNK12;
        case 13: return SPELL_ATTR5_HASTE_AFFECT_DURATION;
        case 14: return SPELL_ATTR5_NOT_USABLE_WHILE_CHARMED;
        case 15: return SPELL_ATTR5_UNK15;
        case 16: return SPELL_ATTR5_UNK16;
        case 17: return SPELL_ATTR5_USABLE_WHILE_FEARED;
        case 18: return SPELL_ATTR5_USABLE_WHILE_CONFUSED;
        case 19: return SPELL_ATTR5_DONT_TURN_DURING_CAST;
        case 20: return SPELL_ATTR5_UNK20;
        case 21: return SPELL_ATTR5_UNK21;
        case 22: return SPELL_ATTR5_UNK22;
        case 23: return SPELL_ATTR5_UNK23;
        case 24: return SPELL_ATTR5_UNK24;
        case 25: return SPELL_ATTR5_UNK25;
        case 26: return SPELL_ATTR5_SKIP_CHECKCAST_LOS_CHECK;
        case 27: return SPELL_ATTR5_DONT_SHOW_AURA_IF_SELF_CAST;
        case 28: return SPELL_ATTR5_DONT_SHOW_AURA_IF_NOT_SELF_CAST;
        case 29: return SPELL_ATTR5_UNK29;
        case 30: return SPELL_ATTR5_UNK30;
        case 31: return SPELL_ATTR5_UNK31;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr5>::ToIndex(SpellAttr5 value)
{
    switch (value)
    {
        case SPELL_ATTR5_CAN_CHANNEL_WHEN_MOVING: return 0;
        case SPELL_ATTR5_NO_REAGENT_WHILE_PREP: return 1;
        case SPELL_ATTR5_REMOVE_ON_ARENA_ENTER: return 2;
        case SPELL_ATTR5_USABLE_WHILE_STUNNED: return 3;
        case SPELL_ATTR5_UNK4: return 4;
        case SPELL_ATTR5_SINGLE_TARGET_SPELL: return 5;
        case SPELL_ATTR5_UNK6: return 6;
        case SPELL_ATTR5_UNK7: return 7;
        case SPELL_ATTR5_CANT_TARGET_PLAYER_CONTROLLED: return 8;
        case SPELL_ATTR5_START_PERIODIC_AT_APPLY: return 9;
        case SPELL_ATTR5_HIDE_DURATION: return 10;
        case SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET: return 11;
        case SPELL_ATTR5_UNK12: return 12;
        case SPELL_ATTR5_HASTE_AFFECT_DURATION: return 13;
        case SPELL_ATTR5_NOT_USABLE_WHILE_CHARMED: return 14;
        case SPELL_ATTR5_UNK15: return 15;
        case SPELL_ATTR5_UNK16: return 16;
        case SPELL_ATTR5_USABLE_WHILE_FEARED: return 17;
        case SPELL_ATTR5_USABLE_WHILE_CONFUSED: return 18;
        case SPELL_ATTR5_DONT_TURN_DURING_CAST: return 19;
        case SPELL_ATTR5_UNK20: return 20;
        case SPELL_ATTR5_UNK21: return 21;
        case SPELL_ATTR5_UNK22: return 22;
        case SPELL_ATTR5_UNK23: return 23;
        case SPELL_ATTR5_UNK24: return 24;
        case SPELL_ATTR5_UNK25: return 25;
        case SPELL_ATTR5_SKIP_CHECKCAST_LOS_CHECK: return 26;
        case SPELL_ATTR5_DONT_SHOW_AURA_IF_SELF_CAST: return 27;
        case SPELL_ATTR5_DONT_SHOW_AURA_IF_NOT_SELF_CAST: return 28;
        case SPELL_ATTR5_UNK29: return 29;
        case SPELL_ATTR5_UNK30: return 30;
        case SPELL_ATTR5_UNK31: return 31;
        default: throw std::out_of_range("value");
    }
}

/******************************************************************\
|* data for enum 'SpellAttr6' in 'SharedDefines.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr6>::ToString(SpellAttr6 value)
{
    switch (value)
    {
        case SPELL_ATTR6_DONT_DISPLAY_COOLDOWN: return { "SPELL_ATTR6_DONT_DISPLAY_COOLDOWN", "Don't display cooldown (client only)", "" };
        case SPELL_ATTR6_ONLY_IN_ARENA: return { "SPELL_ATTR6_ONLY_IN_ARENA", "Only usable in arena", "" };
        case SPELL_ATTR6_IGNORE_CASTER_AURAS: return { "SPELL_ATTR6_IGNORE_CASTER_AURAS", "Ignore all preventing caster auras", "" };
        case SPELL_ATTR6_ASSIST_IGNORE_IMMUNE_FLAG: return { "SPELL_ATTR6_ASSIST_IGNORE_IMMUNE_FLAG", "Ignore immunity flags when assisting", "" };
        case SPELL_ATTR6_UNK4: return { "SPELL_ATTR6_UNK4", "Unknown attribute 4@Attr6", "" };
        case SPELL_ATTR6_DONT_CONSUME_PROC_CHARGES: return { "SPELL_ATTR6_DONT_CONSUME_PROC_CHARGES", "Don't consume proc charges", "" };
        case SPELL_ATTR6_USE_SPELL_CAST_EVENT: return { "SPELL_ATTR6_USE_SPELL_CAST_EVENT", "Generate spell_cast event instead of aura_start (client only)", "" };
        case SPELL_ATTR6_UNK7: return { "SPELL_ATTR6_UNK7", "Unknown attribute 7@Attr6", "" };
        case SPELL_ATTR6_CANT_TARGET_CROWD_CONTROLLED: return { "SPELL_ATTR6_CANT_TARGET_CROWD_CONTROLLED", "Do not implicitly target in CC", "Implicit targeting (chaining and area targeting) will not impact crowd controlled targets" };
        case SPELL_ATTR6_UNK9: return { "SPELL_ATTR6_UNK9", "Unknown attribute 9@Attr6", "" };
        case SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS: return { "SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS", "Can target possessed friends", "[NYI]" };
        case SPELL_ATTR6_NOT_IN_RAID_INSTANCE: return { "SPELL_ATTR6_NOT_IN_RAID_INSTANCE", "Unusable in raid instances", "" };
        case SPELL_ATTR6_CASTABLE_WHILE_ON_VEHICLE: return { "SPELL_ATTR6_CASTABLE_WHILE_ON_VEHICLE", "Castable while caster is on vehicle", "" };
        case SPELL_ATTR6_CAN_TARGET_INVISIBLE: return { "SPELL_ATTR6_CAN_TARGET_INVISIBLE", "Can target invisible units", "" };
        case SPELL_ATTR6_UNK14: return { "SPELL_ATTR6_UNK14", "Unknown attribute 14@Attr6", "" };
        case SPELL_ATTR6_UNK15: return { "SPELL_ATTR6_UNK15", "Unknown attribute 15@Attr6", "" };
        case SPELL_ATTR6_UNK16: return { "SPELL_ATTR6_UNK16", "Unknown attribute 16@Attr6", "" };
        case SPELL_ATTR6_UNK17: return { "SPELL_ATTR6_UNK17", "Unknown attribute 17@Attr6", "Mount related?" };
        case SPELL_ATTR6_CAST_BY_CHARMER: return { "SPELL_ATTR6_CAST_BY_CHARMER", "Spell is cast by charmer", "Client will prevent casting if not possessed, charmer will be caster for all intents and purposes" };
        case SPELL_ATTR6_UNK19: return { "SPELL_ATTR6_UNK19", "Unknown attribute 19@Attr6", "" };
        case SPELL_ATTR6_ONLY_VISIBLE_TO_CASTER: return { "SPELL_ATTR6_ONLY_VISIBLE_TO_CASTER", "Only visible to caster (client only)", "" };
        case SPELL_ATTR6_CLIENT_UI_TARGET_EFFECTS: return { "SPELL_ATTR6_CLIENT_UI_TARGET_EFFECTS", "Client UI target effects (client only)", "" };
        case SPELL_ATTR6_UNK22: return { "SPELL_ATTR6_UNK22", "Unknown attribute 22@Attr6", "" };
        case SPELL_ATTR6_UNK23: return { "SPELL_ATTR6_UNK23", "Unknown attribute 23@Attr6", "" };
        case SPELL_ATTR6_CAN_TARGET_UNTARGETABLE: return { "SPELL_ATTR6_CAN_TARGET_UNTARGETABLE", "Can target untargetable units", "" };
        case SPELL_ATTR6_NOT_RESET_SWING_IF_INSTANT: return { "SPELL_ATTR6_NOT_RESET_SWING_IF_INSTANT", "Do not reset swing timer if cast time is instant", "" };
        case SPELL_ATTR6_UNK26: return { "SPELL_ATTR6_UNK26", "Unknown attribute 26@Attr6", "Player castable buff?" };
        case SPELL_ATTR6_LIMIT_PCT_HEALING_MODS: return { "SPELL_ATTR6_LIMIT_PCT_HEALING_MODS", "Limit applicable %healing modifiers", "This prevents certain healing modifiers from applying - see implementation if you really care about details" };
        case SPELL_ATTR6_UNK28: return { "SPELL_ATTR6_UNK28", "Unknown attribute 28@Attr6", "Death grip?" };
        case SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS: return { "SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS", "Limit applicable %damage modifiers", "This prevents certain damage modifiers from applying - see implementation if you really care about details" };
        case SPELL_ATTR6_UNK30: return { "SPELL_ATTR6_UNK30", "Unknown attribute 30@Attr6", "" };
        case SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS: return { "SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS", "Ignore cooldown modifiers for category cooldown", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr6>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr6 EnumUtils<SpellAttr6>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR6_DONT_DISPLAY_COOLDOWN;
        case 1: return SPELL_ATTR6_ONLY_IN_ARENA;
        case 2: return SPELL_ATTR6_IGNORE_CASTER_AURAS;
        case 3: return SPELL_ATTR6_ASSIST_IGNORE_IMMUNE_FLAG;
        case 4: return SPELL_ATTR6_UNK4;
        case 5: return SPELL_ATTR6_DONT_CONSUME_PROC_CHARGES;
        case 6: return SPELL_ATTR6_USE_SPELL_CAST_EVENT;
        case 7: return SPELL_ATTR6_UNK7;
        case 8: return SPELL_ATTR6_CANT_TARGET_CROWD_CONTROLLED;
        case 9: return SPELL_ATTR6_UNK9;
        case 10: return SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS;
        case 11: return SPELL_ATTR6_NOT_IN_RAID_INSTANCE;
        case 12: return SPELL_ATTR6_CASTABLE_WHILE_ON_VEHICLE;
        case 13: return SPELL_ATTR6_CAN_TARGET_INVISIBLE;
        case 14: return SPELL_ATTR6_UNK14;
        case 15: return SPELL_ATTR6_UNK15;
        case 16: return SPELL_ATTR6_UNK16;
        case 17: return SPELL_ATTR6_UNK17;
        case 18: return SPELL_ATTR6_CAST_BY_CHARMER;
        case 19: return SPELL_ATTR6_UNK19;
        case 20: return SPELL_ATTR6_ONLY_VISIBLE_TO_CASTER;
        case 21: return SPELL_ATTR6_CLIENT_UI_TARGET_EFFECTS;
        case 22: return SPELL_ATTR6_UNK22;
        case 23: return SPELL_ATTR6_UNK23;
        case 24: return SPELL_ATTR6_CAN_TARGET_UNTARGETABLE;
        case 25: return SPELL_ATTR6_NOT_RESET_SWING_IF_INSTANT;
        case 26: return SPELL_ATTR6_UNK26;
        case 27: return SPELL_ATTR6_LIMIT_PCT_HEALING_MODS;
        case 28: return SPELL_ATTR6_UNK28;
        case 29: return SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS;
        case 30: return SPELL_ATTR6_UNK30;
        case 31: return SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr6>::ToIndex(SpellAttr6 value)
{
    switch (value)
    {
        case SPELL_ATTR6_DONT_DISPLAY_COOLDOWN: return 0;
        case SPELL_ATTR6_ONLY_IN_ARENA: return 1;
        case SPELL_ATTR6_IGNORE_CASTER_AURAS: return 2;
        case SPELL_ATTR6_ASSIST_IGNORE_IMMUNE_FLAG: return 3;
        case SPELL_ATTR6_UNK4: return 4;
        case SPELL_ATTR6_DONT_CONSUME_PROC_CHARGES: return 5;
        case SPELL_ATTR6_USE_SPELL_CAST_EVENT: return 6;
        case SPELL_ATTR6_UNK7: return 7;
        case SPELL_ATTR6_CANT_TARGET_CROWD_CONTROLLED: return 8;
        case SPELL_ATTR6_UNK9: return 9;
        case SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS: return 10;
        case SPELL_ATTR6_NOT_IN_RAID_INSTANCE: return 11;
        case SPELL_ATTR6_CASTABLE_WHILE_ON_VEHICLE: return 12;
        case SPELL_ATTR6_CAN_TARGET_INVISIBLE: return 13;
        case SPELL_ATTR6_UNK14: return 14;
        case SPELL_ATTR6_UNK15: return 15;
        case SPELL_ATTR6_UNK16: return 16;
        case SPELL_ATTR6_UNK17: return 17;
        case SPELL_ATTR6_CAST_BY_CHARMER: return 18;
        case SPELL_ATTR6_UNK19: return 19;
        case SPELL_ATTR6_ONLY_VISIBLE_TO_CASTER: return 20;
        case SPELL_ATTR6_CLIENT_UI_TARGET_EFFECTS: return 21;
        case SPELL_ATTR6_UNK22: return 22;
        case SPELL_ATTR6_UNK23: return 23;
        case SPELL_ATTR6_CAN_TARGET_UNTARGETABLE: return 24;
        case SPELL_ATTR6_NOT_RESET_SWING_IF_INSTANT: return 25;
        case SPELL_ATTR6_UNK26: return 26;
        case SPELL_ATTR6_LIMIT_PCT_HEALING_MODS: return 27;
        case SPELL_ATTR6_UNK28: return 28;
        case SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS: return 29;
        case SPELL_ATTR6_UNK30: return 30;
        case SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS: return 31;
        default: throw std::out_of_range("value");
    }
}

/******************************************************************\
|* data for enum 'SpellAttr7' in 'SharedDefines.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr7>::ToString(SpellAttr7 value)
{
    switch (value)
    {
        case SPELL_ATTR7_UNK0: return { "SPELL_ATTR7_UNK0", "Unknown attribute 0@Attr7", "" };
        case SPELL_ATTR7_IGNORE_DURATION_MODS: return { "SPELL_ATTR7_IGNORE_DURATION_MODS", "Ignore duration modifiers", "" };
        case SPELL_ATTR7_DISABLE_AURA_WHILE_DEAD: return { "SPELL_ATTR7_DISABLE_AURA_WHILE_DEAD", "Disable Aura While Dead", "" };
        case SPELL_ATTR7_IS_CHEAT_SPELL: return { "SPELL_ATTR7_IS_CHEAT_SPELL", "Is cheat spell", "Cannot cast if caster doesn't have UnitFlag2 & UNIT_FLAG2_ALLOW_CHEAT_SPELLS" };
        case SPELL_ATTR7_UNK4: return { "SPELL_ATTR7_UNK4", "Unknown attribute 4@Attr7", "Soulstone related?" };
        case SPELL_ATTR7_SUMMON_PLAYER_TOTEM: return { "SPELL_ATTR7_SUMMON_PLAYER_TOTEM", "Summons player-owned totem", "" };
        case SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE: return { "SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE", "Damage dealt by this does not cause spell pushback", "" };
        case SPELL_ATTR7_UNK7: return { "SPELL_ATTR7_UNK7", "Unknown attribute 7@Attr7", "" };
        case SPELL_ATTR7_HORDE_ONLY: return { "SPELL_ATTR7_HORDE_ONLY", "Horde only", "" };
        case SPELL_ATTR7_ALLIANCE_ONLY: return { "SPELL_ATTR7_ALLIANCE_ONLY", "Alliance only", "" };
        case SPELL_ATTR7_DISPEL_CHARGES: return { "SPELL_ATTR7_DISPEL_CHARGES", "Dispel/Spellsteal remove individual charges", "" };
        case SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER: return { "SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER", "Only interrupt non-player casting", "" };
        case SPELL_ATTR7_UNK12: return { "SPELL_ATTR7_UNK12", "Unknown attribute 12@Attr7", "" };
        case SPELL_ATTR7_UNK13: return { "SPELL_ATTR7_UNK13", "Unknown attribute 13@Attr7", "" };
        case SPELL_ATTR7_UNK14: return { "SPELL_ATTR7_UNK14", "Unknown attribute 14@Attr7", "" };
        case SPELL_ATTR7_UNK15: return { "SPELL_ATTR7_UNK15", "Unknown attribute 15@Attr7", "Exorcism - guaranteed crit vs families?" };
        case SPELL_ATTR7_CAN_RESTORE_SECONDARY_POWER: return { "SPELL_ATTR7_CAN_RESTORE_SECONDARY_POWER", "Can restore secondary power", "Only spells with this attribute can replenish a non-active power type" };
        case SPELL_ATTR7_UNK17: return { "SPELL_ATTR7_UNK17", "Unknown attribute 17@Attr7", "" };
        case SPELL_ATTR7_HAS_CHARGE_EFFECT: return { "SPELL_ATTR7_HAS_CHARGE_EFFECT", "Has charge effect", "" };
        case SPELL_ATTR7_ZONE_TELEPORT: return { "SPELL_ATTR7_ZONE_TELEPORT", "Is zone teleport", "" };
        case SPELL_ATTR7_UNK20: return { "SPELL_ATTR7_UNK20", "Unknown attribute 20@Attr7", "Invulnerability related?" };
        case SPELL_ATTR7_UNK21: return { "SPELL_ATTR7_UNK21", "Unknown attribute 21@Attr7", "" };
        case SPELL_ATTR7_IGNORE_COLD_WEATHER_FLYING: return { "SPELL_ATTR7_IGNORE_COLD_WEATHER_FLYING", "Ignore cold weather flying restriction", "Set for loaner mounts, allows them to be used despite lacking required flight skill" };
        case SPELL_ATTR7_CANT_DODGE: return { "SPELL_ATTR7_CANT_DODGE", "Spell cannot be dodged", "" };
        case SPELL_ATTR7_CANT_PARRY: return { "SPELL_ATTR7_CANT_PARRY", "Spell cannot be parried", "" };
        case SPELL_ATTR7_CANT_MISS: return { "SPELL_ATTR7_CANT_MISS", "Spell cannot be missed", "" };
        case SPELL_ATTR7_UNK26: return { "SPELL_ATTR7_UNK26", "Unknown attribute 26@Attr7", "" };
        case SPELL_ATTR7_BYPASS_NO_RESURRECT_AURA: return { "SPELL_ATTR7_BYPASS_NO_RESURRECT_AURA", "Bypasses the prevent resurrection aura", "" };
        case SPELL_ATTR7_CONSOLIDATED_RAID_BUFF: return { "SPELL_ATTR7_CONSOLIDATED_RAID_BUFF", "Consolidate in raid buff frame (client only)", "" };
        case SPELL_ATTR7_UNK29: return { "SPELL_ATTR7_UNK29", "Unknown attribute 29@Attr7", "" };
        case SPELL_ATTR7_UNK30: return { "SPELL_ATTR7_UNK30", "Unknown attribute 30@Attr7", "" };
        case SPELL_ATTR7_CLIENT_INDICATOR: return { "SPELL_ATTR7_CLIENT_INDICATOR", "Client indicator (client only)", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr7>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr7 EnumUtils<SpellAttr7>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR7_UNK0;
        case 1: return SPELL_ATTR7_IGNORE_DURATION_MODS;
        case 2: return SPELL_ATTR7_DISABLE_AURA_WHILE_DEAD;
        case 3: return SPELL_ATTR7_IS_CHEAT_SPELL;
        case 4: return SPELL_ATTR7_UNK4;
        case 5: return SPELL_ATTR7_SUMMON_PLAYER_TOTEM;
        case 6: return SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE;
        case 7: return SPELL_ATTR7_UNK7;
        case 8: return SPELL_ATTR7_HORDE_ONLY;
        case 9: return SPELL_ATTR7_ALLIANCE_ONLY;
        case 10: return SPELL_ATTR7_DISPEL_CHARGES;
        case 11: return SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER;
        case 12: return SPELL_ATTR7_UNK12;
        case 13: return SPELL_ATTR7_UNK13;
        case 14: return SPELL_ATTR7_UNK14;
        case 15: return SPELL_ATTR7_UNK15;
        case 16: return SPELL_ATTR7_CAN_RESTORE_SECONDARY_POWER;
        case 17: return SPELL_ATTR7_UNK17;
        case 18: return SPELL_ATTR7_HAS_CHARGE_EFFECT;
        case 19: return SPELL_ATTR7_ZONE_TELEPORT;
        case 20: return SPELL_ATTR7_UNK20;
        case 21: return SPELL_ATTR7_UNK21;
        case 22: return SPELL_ATTR7_IGNORE_COLD_WEATHER_FLYING;
        case 23: return SPELL_ATTR7_CANT_DODGE;
        case 24: return SPELL_ATTR7_CANT_PARRY;
        case 25: return SPELL_ATTR7_CANT_MISS;
        case 26: return SPELL_ATTR7_UNK26;
        case 27: return SPELL_ATTR7_BYPASS_NO_RESURRECT_AURA;
        case 28: return SPELL_ATTR7_CONSOLIDATED_RAID_BUFF;
        case 29: return SPELL_ATTR7_UNK29;
        case 30: return SPELL_ATTR7_UNK30;
        case 31: return SPELL_ATTR7_CLIENT_INDICATOR;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr7>::ToIndex(SpellAttr7 value)
{
    switch (value)
    {
        case SPELL_ATTR7_UNK0: return 0;
        case SPELL_ATTR7_IGNORE_DURATION_MODS: return 1;
        case SPELL_ATTR7_DISABLE_AURA_WHILE_DEAD: return 2;
        case SPELL_ATTR7_IS_CHEAT_SPELL: return 3;
        case SPELL_ATTR7_UNK4: return 4;
        case SPELL_ATTR7_SUMMON_PLAYER_TOTEM: return 5;
        case SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE: return 6;
        case SPELL_ATTR7_UNK7: return 7;
        case SPELL_ATTR7_HORDE_ONLY: return 8;
        case SPELL_ATTR7_ALLIANCE_ONLY: return 9;
        case SPELL_ATTR7_DISPEL_CHARGES: return 10;
        case SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER: return 11;
        case SPELL_ATTR7_UNK12: return 12;
        case SPELL_ATTR7_UNK13: return 13;
        case SPELL_ATTR7_UNK14: return 14;
        case SPELL_ATTR7_UNK15: return 15;
        case SPELL_ATTR7_CAN_RESTORE_SECONDARY_POWER: return 16;
        case SPELL_ATTR7_UNK17: return 17;
        case SPELL_ATTR7_HAS_CHARGE_EFFECT: return 18;
        case SPELL_ATTR7_ZONE_TELEPORT: return 19;
        case SPELL_ATTR7_UNK20: return 20;
        case SPELL_ATTR7_UNK21: return 21;
        case SPELL_ATTR7_IGNORE_COLD_WEATHER_FLYING: return 22;
        case SPELL_ATTR7_CANT_DODGE: return 23;
        case SPELL_ATTR7_CANT_PARRY: return 24;
        case SPELL_ATTR7_CANT_MISS: return 25;
        case SPELL_ATTR7_UNK26: return 26;
        case SPELL_ATTR7_BYPASS_NO_RESURRECT_AURA: return 27;
        case SPELL_ATTR7_CONSOLIDATED_RAID_BUFF: return 28;
        case SPELL_ATTR7_UNK29: return 29;
        case SPELL_ATTR7_UNK30: return 30;
        case SPELL_ATTR7_CLIENT_INDICATOR: return 31;
        default: throw std::out_of_range("value");
    }
}

/***********************************************************************\
|* data for enum 'SpellCastResult' in 'SharedDefines.h' auto-generated *|
\***********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellCastResult>::ToString(SpellCastResult value)
{
    switch (value)
    {
        case SPELL_FAILED_SUCCESS: return { "SPELL_FAILED_SUCCESS", "SPELL_FAILED_SUCCESS", "" };
        case SPELL_FAILED_AFFECTING_COMBAT: return { "SPELL_FAILED_AFFECTING_COMBAT", "SPELL_FAILED_AFFECTING_COMBAT", "" };
        case SPELL_FAILED_ALREADY_AT_FULL_HEALTH: return { "SPELL_FAILED_ALREADY_AT_FULL_HEALTH", "SPELL_FAILED_ALREADY_AT_FULL_HEALTH", "" };
        case SPELL_FAILED_ALREADY_AT_FULL_MANA: return { "SPELL_FAILED_ALREADY_AT_FULL_MANA", "SPELL_FAILED_ALREADY_AT_FULL_MANA", "" };
        case SPELL_FAILED_ALREADY_AT_FULL_POWER: return { "SPELL_FAILED_ALREADY_AT_FULL_POWER", "SPELL_FAILED_ALREADY_AT_FULL_POWER", "" };
        case SPELL_FAILED_ALREADY_BEING_TAMED: return { "SPELL_FAILED_ALREADY_BEING_TAMED", "SPELL_FAILED_ALREADY_BEING_TAMED", "" };
        case SPELL_FAILED_ALREADY_HAVE_CHARM: return { "SPELL_FAILED_ALREADY_HAVE_CHARM", "SPELL_FAILED_ALREADY_HAVE_CHARM", "" };
        case SPELL_FAILED_ALREADY_HAVE_SUMMON: return { "SPELL_FAILED_ALREADY_HAVE_SUMMON", "SPELL_FAILED_ALREADY_HAVE_SUMMON", "" };
        case SPELL_FAILED_ALREADY_OPEN: return { "SPELL_FAILED_ALREADY_OPEN", "SPELL_FAILED_ALREADY_OPEN", "" };
        case SPELL_FAILED_AURA_BOUNCED: return { "SPELL_FAILED_AURA_BOUNCED", "SPELL_FAILED_AURA_BOUNCED", "" };
        case SPELL_FAILED_AUTOTRACK_INTERRUPTED: return { "SPELL_FAILED_AUTOTRACK_INTERRUPTED", "SPELL_FAILED_AUTOTRACK_INTERRUPTED", "" };
        case SPELL_FAILED_BAD_IMPLICIT_TARGETS: return { "SPELL_FAILED_BAD_IMPLICIT_TARGETS", "SPELL_FAILED_BAD_IMPLICIT_TARGETS", "" };
        case SPELL_FAILED_BAD_TARGETS: return { "SPELL_FAILED_BAD_TARGETS", "SPELL_FAILED_BAD_TARGETS", "" };
        case SPELL_FAILED_CANT_BE_CHARMED: return { "SPELL_FAILED_CANT_BE_CHARMED", "SPELL_FAILED_CANT_BE_CHARMED", "" };
        case SPELL_FAILED_CANT_BE_DISENCHANTED: return { "SPELL_FAILED_CANT_BE_DISENCHANTED", "SPELL_FAILED_CANT_BE_DISENCHANTED", "" };
        case SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL: return { "SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL", "SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL", "" };
        case SPELL_FAILED_CANT_BE_MILLED: return { "SPELL_FAILED_CANT_BE_MILLED", "SPELL_FAILED_CANT_BE_MILLED", "" };
        case SPELL_FAILED_CANT_BE_PROSPECTED: return { "SPELL_FAILED_CANT_BE_PROSPECTED", "SPELL_FAILED_CANT_BE_PROSPECTED", "" };
        case SPELL_FAILED_CANT_CAST_ON_TAPPED: return { "SPELL_FAILED_CANT_CAST_ON_TAPPED", "SPELL_FAILED_CANT_CAST_ON_TAPPED", "" };
        case SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE: return { "SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE", "SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE", "" };
        case SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED: return { "SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED", "SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED", "" };
        case SPELL_FAILED_CANT_STEALTH: return { "SPELL_FAILED_CANT_STEALTH", "SPELL_FAILED_CANT_STEALTH", "" };
        case SPELL_FAILED_CASTER_AURASTATE: return { "SPELL_FAILED_CASTER_AURASTATE", "SPELL_FAILED_CASTER_AURASTATE", "" };
        case SPELL_FAILED_CASTER_DEAD: return { "SPELL_FAILED_CASTER_DEAD", "SPELL_FAILED_CASTER_DEAD", "" };
        case SPELL_FAILED_CHARMED: return { "SPELL_FAILED_CHARMED", "SPELL_FAILED_CHARMED", "" };
        case SPELL_FAILED_CHEST_IN_USE: return { "SPELL_FAILED_CHEST_IN_USE", "SPELL_FAILED_CHEST_IN_USE", "" };
        case SPELL_FAILED_CONFUSED: return { "SPELL_FAILED_CONFUSED", "SPELL_FAILED_CONFUSED", "" };
        case SPELL_FAILED_DONT_REPORT: return { "SPELL_FAILED_DONT_REPORT", "SPELL_FAILED_DONT_REPORT", "" };
        case SPELL_FAILED_EQUIPPED_ITEM: return { "SPELL_FAILED_EQUIPPED_ITEM", "SPELL_FAILED_EQUIPPED_ITEM", "" };
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS: return { "SPELL_FAILED_EQUIPPED_ITEM_CLASS", "SPELL_FAILED_EQUIPPED_ITEM_CLASS", "" };
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND: return { "SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND", "SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND", "" };
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND: return { "SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND", "SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND", "" };
        case SPELL_FAILED_ERROR: return { "SPELL_FAILED_ERROR", "SPELL_FAILED_ERROR", "" };
        case SPELL_FAILED_FIZZLE: return { "SPELL_FAILED_FIZZLE", "SPELL_FAILED_FIZZLE", "" };
        case SPELL_FAILED_FLEEING: return { "SPELL_FAILED_FLEEING", "SPELL_FAILED_FLEEING", "" };
        case SPELL_FAILED_FOOD_LOWLEVEL: return { "SPELL_FAILED_FOOD_LOWLEVEL", "SPELL_FAILED_FOOD_LOWLEVEL", "" };
        case SPELL_FAILED_HIGHLEVEL: return { "SPELL_FAILED_HIGHLEVEL", "SPELL_FAILED_HIGHLEVEL", "" };
        case SPELL_FAILED_HUNGER_SATIATED: return { "SPELL_FAILED_HUNGER_SATIATED", "SPELL_FAILED_HUNGER_SATIATED", "" };
        case SPELL_FAILED_IMMUNE: return { "SPELL_FAILED_IMMUNE", "SPELL_FAILED_IMMUNE", "" };
        case SPELL_FAILED_INCORRECT_AREA: return { "SPELL_FAILED_INCORRECT_AREA", "SPELL_FAILED_INCORRECT_AREA", "" };
        case SPELL_FAILED_INTERRUPTED: return { "SPELL_FAILED_INTERRUPTED", "SPELL_FAILED_INTERRUPTED", "" };
        case SPELL_FAILED_INTERRUPTED_COMBAT: return { "SPELL_FAILED_INTERRUPTED_COMBAT", "SPELL_FAILED_INTERRUPTED_COMBAT", "" };
        case SPELL_FAILED_ITEM_ALREADY_ENCHANTED: return { "SPELL_FAILED_ITEM_ALREADY_ENCHANTED", "SPELL_FAILED_ITEM_ALREADY_ENCHANTED", "" };
        case SPELL_FAILED_ITEM_GONE: return { "SPELL_FAILED_ITEM_GONE", "SPELL_FAILED_ITEM_GONE", "" };
        case SPELL_FAILED_ITEM_NOT_FOUND: return { "SPELL_FAILED_ITEM_NOT_FOUND", "SPELL_FAILED_ITEM_NOT_FOUND", "" };
        case SPELL_FAILED_ITEM_NOT_READY: return { "SPELL_FAILED_ITEM_NOT_READY", "SPELL_FAILED_ITEM_NOT_READY", "" };
        case SPELL_FAILED_LEVEL_REQUIREMENT: return { "SPELL_FAILED_LEVEL_REQUIREMENT", "SPELL_FAILED_LEVEL_REQUIREMENT", "" };
        case SPELL_FAILED_LINE_OF_SIGHT: return { "SPELL_FAILED_LINE_OF_SIGHT", "SPELL_FAILED_LINE_OF_SIGHT", "" };
        case SPELL_FAILED_LOWLEVEL: return { "SPELL_FAILED_LOWLEVEL", "SPELL_FAILED_LOWLEVEL", "" };
        case SPELL_FAILED_LOW_CASTLEVEL: return { "SPELL_FAILED_LOW_CASTLEVEL", "SPELL_FAILED_LOW_CASTLEVEL", "" };
        case SPELL_FAILED_MAINHAND_EMPTY: return { "SPELL_FAILED_MAINHAND_EMPTY", "SPELL_FAILED_MAINHAND_EMPTY", "" };
        case SPELL_FAILED_MOVING: return { "SPELL_FAILED_MOVING", "SPELL_FAILED_MOVING", "" };
        case SPELL_FAILED_NEED_AMMO: return { "SPELL_FAILED_NEED_AMMO", "SPELL_FAILED_NEED_AMMO", "" };
        case SPELL_FAILED_NEED_AMMO_POUCH: return { "SPELL_FAILED_NEED_AMMO_POUCH", "SPELL_FAILED_NEED_AMMO_POUCH", "" };
        case SPELL_FAILED_NEED_EXOTIC_AMMO: return { "SPELL_FAILED_NEED_EXOTIC_AMMO", "SPELL_FAILED_NEED_EXOTIC_AMMO", "" };
        case SPELL_FAILED_NEED_MORE_ITEMS: return { "SPELL_FAILED_NEED_MORE_ITEMS", "SPELL_FAILED_NEED_MORE_ITEMS", "" };
        case SPELL_FAILED_NOPATH: return { "SPELL_FAILED_NOPATH", "SPELL_FAILED_NOPATH", "" };
        case SPELL_FAILED_NOT_BEHIND: return { "SPELL_FAILED_NOT_BEHIND", "SPELL_FAILED_NOT_BEHIND", "" };
        case SPELL_FAILED_NOT_FISHABLE: return { "SPELL_FAILED_NOT_FISHABLE", "SPELL_FAILED_NOT_FISHABLE", "" };
        case SPELL_FAILED_NOT_FLYING: return { "SPELL_FAILED_NOT_FLYING", "SPELL_FAILED_NOT_FLYING", "" };
        case SPELL_FAILED_NOT_HERE: return { "SPELL_FAILED_NOT_HERE", "SPELL_FAILED_NOT_HERE", "" };
        case SPELL_FAILED_NOT_INFRONT: return { "SPELL_FAILED_NOT_INFRONT", "SPELL_FAILED_NOT_INFRONT", "" };
        case SPELL_FAILED_NOT_IN_CONTROL: return { "SPELL_FAILED_NOT_IN_CONTROL", "SPELL_FAILED_NOT_IN_CONTROL", "" };
        case SPELL_FAILED_NOT_KNOWN: return { "SPELL_FAILED_NOT_KNOWN", "SPELL_FAILED_NOT_KNOWN", "" };
        case SPELL_FAILED_NOT_MOUNTED: return { "SPELL_FAILED_NOT_MOUNTED", "SPELL_FAILED_NOT_MOUNTED", "" };
        case SPELL_FAILED_NOT_ON_TAXI: return { "SPELL_FAILED_NOT_ON_TAXI", "SPELL_FAILED_NOT_ON_TAXI", "" };
        case SPELL_FAILED_NOT_ON_TRANSPORT: return { "SPELL_FAILED_NOT_ON_TRANSPORT", "SPELL_FAILED_NOT_ON_TRANSPORT", "" };
        case SPELL_FAILED_NOT_READY: return { "SPELL_FAILED_NOT_READY", "SPELL_FAILED_NOT_READY", "" };
        case SPELL_FAILED_NOT_SHAPESHIFT: return { "SPELL_FAILED_NOT_SHAPESHIFT", "SPELL_FAILED_NOT_SHAPESHIFT", "" };
        case SPELL_FAILED_NOT_STANDING: return { "SPELL_FAILED_NOT_STANDING", "SPELL_FAILED_NOT_STANDING", "" };
        case SPELL_FAILED_NOT_TRADEABLE: return { "SPELL_FAILED_NOT_TRADEABLE", "SPELL_FAILED_NOT_TRADEABLE", "" };
        case SPELL_FAILED_NOT_TRADING: return { "SPELL_FAILED_NOT_TRADING", "SPELL_FAILED_NOT_TRADING", "" };
        case SPELL_FAILED_NOT_UNSHEATHED: return { "SPELL_FAILED_NOT_UNSHEATHED", "SPELL_FAILED_NOT_UNSHEATHED", "" };
        case SPELL_FAILED_NOT_WHILE_GHOST: return { "SPELL_FAILED_NOT_WHILE_GHOST", "SPELL_FAILED_NOT_WHILE_GHOST", "" };
        case SPELL_FAILED_NOT_WHILE_LOOTING: return { "SPELL_FAILED_NOT_WHILE_LOOTING", "SPELL_FAILED_NOT_WHILE_LOOTING", "" };
        case SPELL_FAILED_NO_AMMO: return { "SPELL_FAILED_NO_AMMO", "SPELL_FAILED_NO_AMMO", "" };
        case SPELL_FAILED_NO_CHARGES_REMAIN: return { "SPELL_FAILED_NO_CHARGES_REMAIN", "SPELL_FAILED_NO_CHARGES_REMAIN", "" };
        case SPELL_FAILED_NO_CHAMPION: return { "SPELL_FAILED_NO_CHAMPION", "SPELL_FAILED_NO_CHAMPION", "" };
        case SPELL_FAILED_NO_COMBO_POINTS: return { "SPELL_FAILED_NO_COMBO_POINTS", "SPELL_FAILED_NO_COMBO_POINTS", "" };
        case SPELL_FAILED_NO_DUELING: return { "SPELL_FAILED_NO_DUELING", "SPELL_FAILED_NO_DUELING", "" };
        case SPELL_FAILED_NO_ENDURANCE: return { "SPELL_FAILED_NO_ENDURANCE", "SPELL_FAILED_NO_ENDURANCE", "" };
        case SPELL_FAILED_NO_FISH: return { "SPELL_FAILED_NO_FISH", "SPELL_FAILED_NO_FISH", "" };
        case SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED: return { "SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED", "SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED", "" };
        case SPELL_FAILED_NO_MOUNTS_ALLOWED: return { "SPELL_FAILED_NO_MOUNTS_ALLOWED", "SPELL_FAILED_NO_MOUNTS_ALLOWED", "" };
        case SPELL_FAILED_NO_PET: return { "SPELL_FAILED_NO_PET", "SPELL_FAILED_NO_PET", "" };
        case SPELL_FAILED_NO_POWER: return { "SPELL_FAILED_NO_POWER", "SPELL_FAILED_NO_POWER", "" };
        case SPELL_FAILED_NOTHING_TO_DISPEL: return { "SPELL_FAILED_NOTHING_TO_DISPEL", "SPELL_FAILED_NOTHING_TO_DISPEL", "" };
        case SPELL_FAILED_NOTHING_TO_STEAL: return { "SPELL_FAILED_NOTHING_TO_STEAL", "SPELL_FAILED_NOTHING_TO_STEAL", "" };
        case SPELL_FAILED_ONLY_ABOVEWATER: return { "SPELL_FAILED_ONLY_ABOVEWATER", "SPELL_FAILED_ONLY_ABOVEWATER", "" };
        case SPELL_FAILED_ONLY_DAYTIME: return { "SPELL_FAILED_ONLY_DAYTIME", "SPELL_FAILED_ONLY_DAYTIME", "" };
        case SPELL_FAILED_ONLY_INDOORS: return { "SPELL_FAILED_ONLY_INDOORS", "SPELL_FAILED_ONLY_INDOORS", "" };
        case SPELL_FAILED_ONLY_MOUNTED: return { "SPELL_FAILED_ONLY_MOUNTED", "SPELL_FAILED_ONLY_MOUNTED", "" };
        case SPELL_FAILED_ONLY_NIGHTTIME: return { "SPELL_FAILED_ONLY_NIGHTTIME", "SPELL_FAILED_ONLY_NIGHTTIME", "" };
        case SPELL_FAILED_ONLY_OUTDOORS: return { "SPELL_FAILED_ONLY_OUTDOORS", "SPELL_FAILED_ONLY_OUTDOORS", "" };
        case SPELL_FAILED_ONLY_SHAPESHIFT: return { "SPELL_FAILED_ONLY_SHAPESHIFT", "SPELL_FAILED_ONLY_SHAPESHIFT", "" };
        case SPELL_FAILED_ONLY_STEALTHED: return { "SPELL_FAILED_ONLY_STEALTHED", "SPELL_FAILED_ONLY_STEALTHED", "" };
        case SPELL_FAILED_ONLY_UNDERWATER: return { "SPELL_FAILED_ONLY_UNDERWATER", "SPELL_FAILED_ONLY_UNDERWATER", "" };
        case SPELL_FAILED_OUT_OF_RANGE: return { "SPELL_FAILED_OUT_OF_RANGE", "SPELL_FAILED_OUT_OF_RANGE", "" };
        case SPELL_FAILED_PACIFIED: return { "SPELL_FAILED_PACIFIED", "SPELL_FAILED_PACIFIED", "" };
        case SPELL_FAILED_POSSESSED: return { "SPELL_FAILED_POSSESSED", "SPELL_FAILED_POSSESSED", "" };
        case SPELL_FAILED_REAGENTS: return { "SPELL_FAILED_REAGENTS", "SPELL_FAILED_REAGENTS", "" };
        case SPELL_FAILED_REQUIRES_AREA: return { "SPELL_FAILED_REQUIRES_AREA", "SPELL_FAILED_REQUIRES_AREA", "" };
        case SPELL_FAILED_REQUIRES_SPELL_FOCUS: return { "SPELL_FAILED_REQUIRES_SPELL_FOCUS", "SPELL_FAILED_REQUIRES_SPELL_FOCUS", "" };
        case SPELL_FAILED_ROOTED: return { "SPELL_FAILED_ROOTED", "SPELL_FAILED_ROOTED", "" };
        case SPELL_FAILED_SILENCED: return { "SPELL_FAILED_SILENCED", "SPELL_FAILED_SILENCED", "" };
        case SPELL_FAILED_SPELL_IN_PROGRESS: return { "SPELL_FAILED_SPELL_IN_PROGRESS", "SPELL_FAILED_SPELL_IN_PROGRESS", "" };
        case SPELL_FAILED_SPELL_LEARNED: return { "SPELL_FAILED_SPELL_LEARNED", "SPELL_FAILED_SPELL_LEARNED", "" };
        case SPELL_FAILED_SPELL_UNAVAILABLE: return { "SPELL_FAILED_SPELL_UNAVAILABLE", "SPELL_FAILED_SPELL_UNAVAILABLE", "" };
        case SPELL_FAILED_STUNNED: return { "SPELL_FAILED_STUNNED", "SPELL_FAILED_STUNNED", "" };
        case SPELL_FAILED_TARGETS_DEAD: return { "SPELL_FAILED_TARGETS_DEAD", "SPELL_FAILED_TARGETS_DEAD", "" };
        case SPELL_FAILED_TARGET_AFFECTING_COMBAT: return { "SPELL_FAILED_TARGET_AFFECTING_COMBAT", "SPELL_FAILED_TARGET_AFFECTING_COMBAT", "" };
        case SPELL_FAILED_TARGET_AURASTATE: return { "SPELL_FAILED_TARGET_AURASTATE", "SPELL_FAILED_TARGET_AURASTATE", "" };
        case SPELL_FAILED_TARGET_DUELING: return { "SPELL_FAILED_TARGET_DUELING", "SPELL_FAILED_TARGET_DUELING", "" };
        case SPELL_FAILED_TARGET_ENEMY: return { "SPELL_FAILED_TARGET_ENEMY", "SPELL_FAILED_TARGET_ENEMY", "" };
        case SPELL_FAILED_TARGET_ENRAGED: return { "SPELL_FAILED_TARGET_ENRAGED", "SPELL_FAILED_TARGET_ENRAGED", "" };
        case SPELL_FAILED_TARGET_FRIENDLY: return { "SPELL_FAILED_TARGET_FRIENDLY", "SPELL_FAILED_TARGET_FRIENDLY", "" };
        case SPELL_FAILED_TARGET_IN_COMBAT: return { "SPELL_FAILED_TARGET_IN_COMBAT", "SPELL_FAILED_TARGET_IN_COMBAT", "" };
        case SPELL_FAILED_TARGET_IS_PLAYER: return { "SPELL_FAILED_TARGET_IS_PLAYER", "SPELL_FAILED_TARGET_IS_PLAYER", "" };
        case SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED: return { "SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED", "SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED", "" };
        case SPELL_FAILED_TARGET_NOT_DEAD: return { "SPELL_FAILED_TARGET_NOT_DEAD", "SPELL_FAILED_TARGET_NOT_DEAD", "" };
        case SPELL_FAILED_TARGET_NOT_IN_PARTY: return { "SPELL_FAILED_TARGET_NOT_IN_PARTY", "SPELL_FAILED_TARGET_NOT_IN_PARTY", "" };
        case SPELL_FAILED_TARGET_NOT_LOOTED: return { "SPELL_FAILED_TARGET_NOT_LOOTED", "SPELL_FAILED_TARGET_NOT_LOOTED", "" };
        case SPELL_FAILED_TARGET_NOT_PLAYER: return { "SPELL_FAILED_TARGET_NOT_PLAYER", "SPELL_FAILED_TARGET_NOT_PLAYER", "" };
        case SPELL_FAILED_TARGET_NO_POCKETS: return { "SPELL_FAILED_TARGET_NO_POCKETS", "SPELL_FAILED_TARGET_NO_POCKETS", "" };
        case SPELL_FAILED_TARGET_NO_WEAPONS: return { "SPELL_FAILED_TARGET_NO_WEAPONS", "SPELL_FAILED_TARGET_NO_WEAPONS", "" };
        case SPELL_FAILED_TARGET_NO_RANGED_WEAPONS: return { "SPELL_FAILED_TARGET_NO_RANGED_WEAPONS", "SPELL_FAILED_TARGET_NO_RANGED_WEAPONS", "" };
        case SPELL_FAILED_TARGET_UNSKINNABLE: return { "SPELL_FAILED_TARGET_UNSKINNABLE", "SPELL_FAILED_TARGET_UNSKINNABLE", "" };
        case SPELL_FAILED_THIRST_SATIATED: return { "SPELL_FAILED_THIRST_SATIATED", "SPELL_FAILED_THIRST_SATIATED", "" };
        case SPELL_FAILED_TOO_CLOSE: return { "SPELL_FAILED_TOO_CLOSE", "SPELL_FAILED_TOO_CLOSE", "" };
        case SPELL_FAILED_TOO_MANY_OF_ITEM: return { "SPELL_FAILED_TOO_MANY_OF_ITEM", "SPELL_FAILED_TOO_MANY_OF_ITEM", "" };
        case SPELL_FAILED_TOTEM_CATEGORY: return { "SPELL_FAILED_TOTEM_CATEGORY", "SPELL_FAILED_TOTEM_CATEGORY", "" };
        case SPELL_FAILED_TOTEMS: return { "SPELL_FAILED_TOTEMS", "SPELL_FAILED_TOTEMS", "" };
        case SPELL_FAILED_TRY_AGAIN: return { "SPELL_FAILED_TRY_AGAIN", "SPELL_FAILED_TRY_AGAIN", "" };
        case SPELL_FAILED_UNIT_NOT_BEHIND: return { "SPELL_FAILED_UNIT_NOT_BEHIND", "SPELL_FAILED_UNIT_NOT_BEHIND", "" };
        case SPELL_FAILED_UNIT_NOT_INFRONT: return { "SPELL_FAILED_UNIT_NOT_INFRONT", "SPELL_FAILED_UNIT_NOT_INFRONT", "" };
        case SPELL_FAILED_WRONG_PET_FOOD: return { "SPELL_FAILED_WRONG_PET_FOOD", "SPELL_FAILED_WRONG_PET_FOOD", "" };
        case SPELL_FAILED_NOT_WHILE_FATIGUED: return { "SPELL_FAILED_NOT_WHILE_FATIGUED", "SPELL_FAILED_NOT_WHILE_FATIGUED", "" };
        case SPELL_FAILED_TARGET_NOT_IN_INSTANCE: return { "SPELL_FAILED_TARGET_NOT_IN_INSTANCE", "SPELL_FAILED_TARGET_NOT_IN_INSTANCE", "" };
        case SPELL_FAILED_NOT_WHILE_TRADING: return { "SPELL_FAILED_NOT_WHILE_TRADING", "SPELL_FAILED_NOT_WHILE_TRADING", "" };
        case SPELL_FAILED_TARGET_NOT_IN_RAID: return { "SPELL_FAILED_TARGET_NOT_IN_RAID", "SPELL_FAILED_TARGET_NOT_IN_RAID", "" };
        case SPELL_FAILED_TARGET_FREEFORALL: return { "SPELL_FAILED_TARGET_FREEFORALL", "SPELL_FAILED_TARGET_FREEFORALL", "" };
        case SPELL_FAILED_NO_EDIBLE_CORPSES: return { "SPELL_FAILED_NO_EDIBLE_CORPSES", "SPELL_FAILED_NO_EDIBLE_CORPSES", "" };
        case SPELL_FAILED_ONLY_BATTLEGROUNDS: return { "SPELL_FAILED_ONLY_BATTLEGROUNDS", "SPELL_FAILED_ONLY_BATTLEGROUNDS", "" };
        case SPELL_FAILED_TARGET_NOT_GHOST: return { "SPELL_FAILED_TARGET_NOT_GHOST", "SPELL_FAILED_TARGET_NOT_GHOST", "" };
        case SPELL_FAILED_TRANSFORM_UNUSABLE: return { "SPELL_FAILED_TRANSFORM_UNUSABLE", "SPELL_FAILED_TRANSFORM_UNUSABLE", "" };
        case SPELL_FAILED_WRONG_WEATHER: return { "SPELL_FAILED_WRONG_WEATHER", "SPELL_FAILED_WRONG_WEATHER", "" };
        case SPELL_FAILED_DAMAGE_IMMUNE: return { "SPELL_FAILED_DAMAGE_IMMUNE", "SPELL_FAILED_DAMAGE_IMMUNE", "" };
        case SPELL_FAILED_PREVENTED_BY_MECHANIC: return { "SPELL_FAILED_PREVENTED_BY_MECHANIC", "SPELL_FAILED_PREVENTED_BY_MECHANIC", "" };
        case SPELL_FAILED_PLAY_TIME: return { "SPELL_FAILED_PLAY_TIME", "SPELL_FAILED_PLAY_TIME", "" };
        case SPELL_FAILED_REPUTATION: return { "SPELL_FAILED_REPUTATION", "SPELL_FAILED_REPUTATION", "" };
        case SPELL_FAILED_MIN_SKILL: return { "SPELL_FAILED_MIN_SKILL", "SPELL_FAILED_MIN_SKILL", "" };
        case SPELL_FAILED_NOT_IN_ARENA: return { "SPELL_FAILED_NOT_IN_ARENA", "SPELL_FAILED_NOT_IN_ARENA", "" };
        case SPELL_FAILED_NOT_ON_SHAPESHIFT: return { "SPELL_FAILED_NOT_ON_SHAPESHIFT", "SPELL_FAILED_NOT_ON_SHAPESHIFT", "" };
        case SPELL_FAILED_NOT_ON_STEALTHED: return { "SPELL_FAILED_NOT_ON_STEALTHED", "SPELL_FAILED_NOT_ON_STEALTHED", "" };
        case SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE: return { "SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE", "SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE", "" };
        case SPELL_FAILED_NOT_ON_MOUNTED: return { "SPELL_FAILED_NOT_ON_MOUNTED", "SPELL_FAILED_NOT_ON_MOUNTED", "" };
        case SPELL_FAILED_TOO_SHALLOW: return { "SPELL_FAILED_TOO_SHALLOW", "SPELL_FAILED_TOO_SHALLOW", "" };
        case SPELL_FAILED_TARGET_NOT_IN_SANCTUARY: return { "SPELL_FAILED_TARGET_NOT_IN_SANCTUARY", "SPELL_FAILED_TARGET_NOT_IN_SANCTUARY", "" };
        case SPELL_FAILED_TARGET_IS_TRIVIAL: return { "SPELL_FAILED_TARGET_IS_TRIVIAL", "SPELL_FAILED_TARGET_IS_TRIVIAL", "" };
        case SPELL_FAILED_BM_OR_INVISGOD: return { "SPELL_FAILED_BM_OR_INVISGOD", "SPELL_FAILED_BM_OR_INVISGOD", "" };
        case SPELL_FAILED_EXPERT_RIDING_REQUIREMENT: return { "SPELL_FAILED_EXPERT_RIDING_REQUIREMENT", "SPELL_FAILED_EXPERT_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT: return { "SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT", "SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_NOT_IDLE: return { "SPELL_FAILED_NOT_IDLE", "SPELL_FAILED_NOT_IDLE", "" };
        case SPELL_FAILED_NOT_INACTIVE: return { "SPELL_FAILED_NOT_INACTIVE", "SPELL_FAILED_NOT_INACTIVE", "" };
        case SPELL_FAILED_PARTIAL_PLAYTIME: return { "SPELL_FAILED_PARTIAL_PLAYTIME", "SPELL_FAILED_PARTIAL_PLAYTIME", "" };
        case SPELL_FAILED_NO_PLAYTIME: return { "SPELL_FAILED_NO_PLAYTIME", "SPELL_FAILED_NO_PLAYTIME", "" };
        case SPELL_FAILED_NOT_IN_BATTLEGROUND: return { "SPELL_FAILED_NOT_IN_BATTLEGROUND", "SPELL_FAILED_NOT_IN_BATTLEGROUND", "" };
        case SPELL_FAILED_NOT_IN_RAID_INSTANCE: return { "SPELL_FAILED_NOT_IN_RAID_INSTANCE", "SPELL_FAILED_NOT_IN_RAID_INSTANCE", "" };
        case SPELL_FAILED_ONLY_IN_ARENA: return { "SPELL_FAILED_ONLY_IN_ARENA", "SPELL_FAILED_ONLY_IN_ARENA", "" };
        case SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE: return { "SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE", "SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE", "" };
        case SPELL_FAILED_ON_USE_ENCHANT: return { "SPELL_FAILED_ON_USE_ENCHANT", "SPELL_FAILED_ON_USE_ENCHANT", "" };
        case SPELL_FAILED_NOT_ON_GROUND: return { "SPELL_FAILED_NOT_ON_GROUND", "SPELL_FAILED_NOT_ON_GROUND", "" };
        case SPELL_FAILED_CUSTOM_ERROR: return { "SPELL_FAILED_CUSTOM_ERROR", "SPELL_FAILED_CUSTOM_ERROR", "" };
        case SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW: return { "SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW", "SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW", "" };
        case SPELL_FAILED_TOO_MANY_SOCKETS: return { "SPELL_FAILED_TOO_MANY_SOCKETS", "SPELL_FAILED_TOO_MANY_SOCKETS", "" };
        case SPELL_FAILED_INVALID_GLYPH: return { "SPELL_FAILED_INVALID_GLYPH", "SPELL_FAILED_INVALID_GLYPH", "" };
        case SPELL_FAILED_UNIQUE_GLYPH: return { "SPELL_FAILED_UNIQUE_GLYPH", "SPELL_FAILED_UNIQUE_GLYPH", "" };
        case SPELL_FAILED_GLYPH_SOCKET_LOCKED: return { "SPELL_FAILED_GLYPH_SOCKET_LOCKED", "SPELL_FAILED_GLYPH_SOCKET_LOCKED", "" };
        case SPELL_FAILED_NO_VALID_TARGETS: return { "SPELL_FAILED_NO_VALID_TARGETS", "SPELL_FAILED_NO_VALID_TARGETS", "" };
        case SPELL_FAILED_ITEM_AT_MAX_CHARGES: return { "SPELL_FAILED_ITEM_AT_MAX_CHARGES", "SPELL_FAILED_ITEM_AT_MAX_CHARGES", "" };
        case SPELL_FAILED_NOT_IN_BARBERSHOP: return { "SPELL_FAILED_NOT_IN_BARBERSHOP", "SPELL_FAILED_NOT_IN_BARBERSHOP", "" };
        case SPELL_FAILED_FISHING_TOO_LOW: return { "SPELL_FAILED_FISHING_TOO_LOW", "SPELL_FAILED_FISHING_TOO_LOW", "" };
        case SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW: return { "SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW", "SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW", "" };
        case SPELL_FAILED_SUMMON_PENDING: return { "SPELL_FAILED_SUMMON_PENDING", "SPELL_FAILED_SUMMON_PENDING", "" };
        case SPELL_FAILED_MAX_SOCKETS: return { "SPELL_FAILED_MAX_SOCKETS", "SPELL_FAILED_MAX_SOCKETS", "" };
        case SPELL_FAILED_PET_CAN_RENAME: return { "SPELL_FAILED_PET_CAN_RENAME", "SPELL_FAILED_PET_CAN_RENAME", "" };
        case SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED: return { "SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED", "SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED", "" };
        case SPELL_FAILED_UNKNOWN: return { "SPELL_FAILED_UNKNOWN", "SPELL_FAILED_UNKNOWN", "actually doesn't exist in client" };
        case SPELL_CAST_OK: return { "SPELL_CAST_OK", "SPELL_CAST_OK", "custom value, must not be sent to client" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellCastResult>::Count() { return 189; }

template <>
TC_API_EXPORT SpellCastResult EnumUtils<SpellCastResult>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_FAILED_SUCCESS;
        case 1: return SPELL_FAILED_AFFECTING_COMBAT;
        case 2: return SPELL_FAILED_ALREADY_AT_FULL_HEALTH;
        case 3: return SPELL_FAILED_ALREADY_AT_FULL_MANA;
        case 4: return SPELL_FAILED_ALREADY_AT_FULL_POWER;
        case 5: return SPELL_FAILED_ALREADY_BEING_TAMED;
        case 6: return SPELL_FAILED_ALREADY_HAVE_CHARM;
        case 7: return SPELL_FAILED_ALREADY_HAVE_SUMMON;
        case 8: return SPELL_FAILED_ALREADY_OPEN;
        case 9: return SPELL_FAILED_AURA_BOUNCED;
        case 10: return SPELL_FAILED_AUTOTRACK_INTERRUPTED;
        case 11: return SPELL_FAILED_BAD_IMPLICIT_TARGETS;
        case 12: return SPELL_FAILED_BAD_TARGETS;
        case 13: return SPELL_FAILED_CANT_BE_CHARMED;
        case 14: return SPELL_FAILED_CANT_BE_DISENCHANTED;
        case 15: return SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL;
        case 16: return SPELL_FAILED_CANT_BE_MILLED;
        case 17: return SPELL_FAILED_CANT_BE_PROSPECTED;
        case 18: return SPELL_FAILED_CANT_CAST_ON_TAPPED;
        case 19: return SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE;
        case 20: return SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED;
        case 21: return SPELL_FAILED_CANT_STEALTH;
        case 22: return SPELL_FAILED_CASTER_AURASTATE;
        case 23: return SPELL_FAILED_CASTER_DEAD;
        case 24: return SPELL_FAILED_CHARMED;
        case 25: return SPELL_FAILED_CHEST_IN_USE;
        case 26: return SPELL_FAILED_CONFUSED;
        case 27: return SPELL_FAILED_DONT_REPORT;
        case 28: return SPELL_FAILED_EQUIPPED_ITEM;
        case 29: return SPELL_FAILED_EQUIPPED_ITEM_CLASS;
        case 30: return SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND;
        case 31: return SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND;
        case 32: return SPELL_FAILED_ERROR;
        case 33: return SPELL_FAILED_FIZZLE;
        case 34: return SPELL_FAILED_FLEEING;
        case 35: return SPELL_FAILED_FOOD_LOWLEVEL;
        case 36: return SPELL_FAILED_HIGHLEVEL;
        case 37: return SPELL_FAILED_HUNGER_SATIATED;
        case 38: return SPELL_FAILED_IMMUNE;
        case 39: return SPELL_FAILED_INCORRECT_AREA;
        case 40: return SPELL_FAILED_INTERRUPTED;
        case 41: return SPELL_FAILED_INTERRUPTED_COMBAT;
        case 42: return SPELL_FAILED_ITEM_ALREADY_ENCHANTED;
        case 43: return SPELL_FAILED_ITEM_GONE;
        case 44: return SPELL_FAILED_ITEM_NOT_FOUND;
        case 45: return SPELL_FAILED_ITEM_NOT_READY;
        case 46: return SPELL_FAILED_LEVEL_REQUIREMENT;
        case 47: return SPELL_FAILED_LINE_OF_SIGHT;
        case 48: return SPELL_FAILED_LOWLEVEL;
        case 49: return SPELL_FAILED_LOW_CASTLEVEL;
        case 50: return SPELL_FAILED_MAINHAND_EMPTY;
        case 51: return SPELL_FAILED_MOVING;
        case 52: return SPELL_FAILED_NEED_AMMO;
        case 53: return SPELL_FAILED_NEED_AMMO_POUCH;
        case 54: return SPELL_FAILED_NEED_EXOTIC_AMMO;
        case 55: return SPELL_FAILED_NEED_MORE_ITEMS;
        case 56: return SPELL_FAILED_NOPATH;
        case 57: return SPELL_FAILED_NOT_BEHIND;
        case 58: return SPELL_FAILED_NOT_FISHABLE;
        case 59: return SPELL_FAILED_NOT_FLYING;
        case 60: return SPELL_FAILED_NOT_HERE;
        case 61: return SPELL_FAILED_NOT_INFRONT;
        case 62: return SPELL_FAILED_NOT_IN_CONTROL;
        case 63: return SPELL_FAILED_NOT_KNOWN;
        case 64: return SPELL_FAILED_NOT_MOUNTED;
        case 65: return SPELL_FAILED_NOT_ON_TAXI;
        case 66: return SPELL_FAILED_NOT_ON_TRANSPORT;
        case 67: return SPELL_FAILED_NOT_READY;
        case 68: return SPELL_FAILED_NOT_SHAPESHIFT;
        case 69: return SPELL_FAILED_NOT_STANDING;
        case 70: return SPELL_FAILED_NOT_TRADEABLE;
        case 71: return SPELL_FAILED_NOT_TRADING;
        case 72: return SPELL_FAILED_NOT_UNSHEATHED;
        case 73: return SPELL_FAILED_NOT_WHILE_GHOST;
        case 74: return SPELL_FAILED_NOT_WHILE_LOOTING;
        case 75: return SPELL_FAILED_NO_AMMO;
        case 76: return SPELL_FAILED_NO_CHARGES_REMAIN;
        case 77: return SPELL_FAILED_NO_CHAMPION;
        case 78: return SPELL_FAILED_NO_COMBO_POINTS;
        case 79: return SPELL_FAILED_NO_DUELING;
        case 80: return SPELL_FAILED_NO_ENDURANCE;
        case 81: return SPELL_FAILED_NO_FISH;
        case 82: return SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED;
        case 83: return SPELL_FAILED_NO_MOUNTS_ALLOWED;
        case 84: return SPELL_FAILED_NO_PET;
        case 85: return SPELL_FAILED_NO_POWER;
        case 86: return SPELL_FAILED_NOTHING_TO_DISPEL;
        case 87: return SPELL_FAILED_NOTHING_TO_STEAL;
        case 88: return SPELL_FAILED_ONLY_ABOVEWATER;
        case 89: return SPELL_FAILED_ONLY_DAYTIME;
        case 90: return SPELL_FAILED_ONLY_INDOORS;
        case 91: return SPELL_FAILED_ONLY_MOUNTED;
        case 92: return SPELL_FAILED_ONLY_NIGHTTIME;
        case 93: return SPELL_FAILED_ONLY_OUTDOORS;
        case 94: return SPELL_FAILED_ONLY_SHAPESHIFT;
        case 95: return SPELL_FAILED_ONLY_STEALTHED;
        case 96: return SPELL_FAILED_ONLY_UNDERWATER;
        case 97: return SPELL_FAILED_OUT_OF_RANGE;
        case 98: return SPELL_FAILED_PACIFIED;
        case 99: return SPELL_FAILED_POSSESSED;
        case 100: return SPELL_FAILED_REAGENTS;
        case 101: return SPELL_FAILED_REQUIRES_AREA;
        case 102: return SPELL_FAILED_REQUIRES_SPELL_FOCUS;
        case 103: return SPELL_FAILED_ROOTED;
        case 104: return SPELL_FAILED_SILENCED;
        case 105: return SPELL_FAILED_SPELL_IN_PROGRESS;
        case 106: return SPELL_FAILED_SPELL_LEARNED;
        case 107: return SPELL_FAILED_SPELL_UNAVAILABLE;
        case 108: return SPELL_FAILED_STUNNED;
        case 109: return SPELL_FAILED_TARGETS_DEAD;
        case 110: return SPELL_FAILED_TARGET_AFFECTING_COMBAT;
        case 111: return SPELL_FAILED_TARGET_AURASTATE;
        case 112: return SPELL_FAILED_TARGET_DUELING;
        case 113: return SPELL_FAILED_TARGET_ENEMY;
        case 114: return SPELL_FAILED_TARGET_ENRAGED;
        case 115: return SPELL_FAILED_TARGET_FRIENDLY;
        case 116: return SPELL_FAILED_TARGET_IN_COMBAT;
        case 117: return SPELL_FAILED_TARGET_IS_PLAYER;
        case 118: return SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED;
        case 119: return SPELL_FAILED_TARGET_NOT_DEAD;
        case 120: return SPELL_FAILED_TARGET_NOT_IN_PARTY;
        case 121: return SPELL_FAILED_TARGET_NOT_LOOTED;
        case 122: return SPELL_FAILED_TARGET_NOT_PLAYER;
        case 123: return SPELL_FAILED_TARGET_NO_POCKETS;
        case 124: return SPELL_FAILED_TARGET_NO_WEAPONS;
        case 125: return SPELL_FAILED_TARGET_NO_RANGED_WEAPONS;
        case 126: return SPELL_FAILED_TARGET_UNSKINNABLE;
        case 127: return SPELL_FAILED_THIRST_SATIATED;
        case 128: return SPELL_FAILED_TOO_CLOSE;
        case 129: return SPELL_FAILED_TOO_MANY_OF_ITEM;
        case 130: return SPELL_FAILED_TOTEM_CATEGORY;
        case 131: return SPELL_FAILED_TOTEMS;
        case 132: return SPELL_FAILED_TRY_AGAIN;
        case 133: return SPELL_FAILED_UNIT_NOT_BEHIND;
        case 134: return SPELL_FAILED_UNIT_NOT_INFRONT;
        case 135: return SPELL_FAILED_WRONG_PET_FOOD;
        case 136: return SPELL_FAILED_NOT_WHILE_FATIGUED;
        case 137: return SPELL_FAILED_TARGET_NOT_IN_INSTANCE;
        case 138: return SPELL_FAILED_NOT_WHILE_TRADING;
        case 139: return SPELL_FAILED_TARGET_NOT_IN_RAID;
        case 140: return SPELL_FAILED_TARGET_FREEFORALL;
        case 141: return SPELL_FAILED_NO_EDIBLE_CORPSES;
        case 142: return SPELL_FAILED_ONLY_BATTLEGROUNDS;
        case 143: return SPELL_FAILED_TARGET_NOT_GHOST;
        case 144: return SPELL_FAILED_TRANSFORM_UNUSABLE;
        case 145: return SPELL_FAILED_WRONG_WEATHER;
        case 146: return SPELL_FAILED_DAMAGE_IMMUNE;
        case 147: return SPELL_FAILED_PREVENTED_BY_MECHANIC;
        case 148: return SPELL_FAILED_PLAY_TIME;
        case 149: return SPELL_FAILED_REPUTATION;
        case 150: return SPELL_FAILED_MIN_SKILL;
        case 151: return SPELL_FAILED_NOT_IN_ARENA;
        case 152: return SPELL_FAILED_NOT_ON_SHAPESHIFT;
        case 153: return SPELL_FAILED_NOT_ON_STEALTHED;
        case 154: return SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE;
        case 155: return SPELL_FAILED_NOT_ON_MOUNTED;
        case 156: return SPELL_FAILED_TOO_SHALLOW;
        case 157: return SPELL_FAILED_TARGET_NOT_IN_SANCTUARY;
        case 158: return SPELL_FAILED_TARGET_IS_TRIVIAL;
        case 159: return SPELL_FAILED_BM_OR_INVISGOD;
        case 160: return SPELL_FAILED_EXPERT_RIDING_REQUIREMENT;
        case 161: return SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT;
        case 162: return SPELL_FAILED_NOT_IDLE;
        case 163: return SPELL_FAILED_NOT_INACTIVE;
        case 164: return SPELL_FAILED_PARTIAL_PLAYTIME;
        case 165: return SPELL_FAILED_NO_PLAYTIME;
        case 166: return SPELL_FAILED_NOT_IN_BATTLEGROUND;
        case 167: return SPELL_FAILED_NOT_IN_RAID_INSTANCE;
        case 168: return SPELL_FAILED_ONLY_IN_ARENA;
        case 169: return SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE;
        case 170: return SPELL_FAILED_ON_USE_ENCHANT;
        case 171: return SPELL_FAILED_NOT_ON_GROUND;
        case 172: return SPELL_FAILED_CUSTOM_ERROR;
        case 173: return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
        case 174: return SPELL_FAILED_TOO_MANY_SOCKETS;
        case 175: return SPELL_FAILED_INVALID_GLYPH;
        case 176: return SPELL_FAILED_UNIQUE_GLYPH;
        case 177: return SPELL_FAILED_GLYPH_SOCKET_LOCKED;
        case 178: return SPELL_FAILED_NO_VALID_TARGETS;
        case 179: return SPELL_FAILED_ITEM_AT_MAX_CHARGES;
        case 180: return SPELL_FAILED_NOT_IN_BARBERSHOP;
        case 181: return SPELL_FAILED_FISHING_TOO_LOW;
        case 182: return SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW;
        case 183: return SPELL_FAILED_SUMMON_PENDING;
        case 184: return SPELL_FAILED_MAX_SOCKETS;
        case 185: return SPELL_FAILED_PET_CAN_RENAME;
        case 186: return SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED;
        case 187: return SPELL_FAILED_UNKNOWN;
        case 188: return SPELL_CAST_OK;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellCastResult>::ToIndex(SpellCastResult value)
{
    switch (value)
    {
        case SPELL_FAILED_SUCCESS: return 0;
        case SPELL_FAILED_AFFECTING_COMBAT: return 1;
        case SPELL_FAILED_ALREADY_AT_FULL_HEALTH: return 2;
        case SPELL_FAILED_ALREADY_AT_FULL_MANA: return 3;
        case SPELL_FAILED_ALREADY_AT_FULL_POWER: return 4;
        case SPELL_FAILED_ALREADY_BEING_TAMED: return 5;
        case SPELL_FAILED_ALREADY_HAVE_CHARM: return 6;
        case SPELL_FAILED_ALREADY_HAVE_SUMMON: return 7;
        case SPELL_FAILED_ALREADY_OPEN: return 8;
        case SPELL_FAILED_AURA_BOUNCED: return 9;
        case SPELL_FAILED_AUTOTRACK_INTERRUPTED: return 10;
        case SPELL_FAILED_BAD_IMPLICIT_TARGETS: return 11;
        case SPELL_FAILED_BAD_TARGETS: return 12;
        case SPELL_FAILED_CANT_BE_CHARMED: return 13;
        case SPELL_FAILED_CANT_BE_DISENCHANTED: return 14;
        case SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL: return 15;
        case SPELL_FAILED_CANT_BE_MILLED: return 16;
        case SPELL_FAILED_CANT_BE_PROSPECTED: return 17;
        case SPELL_FAILED_CANT_CAST_ON_TAPPED: return 18;
        case SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE: return 19;
        case SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED: return 20;
        case SPELL_FAILED_CANT_STEALTH: return 21;
        case SPELL_FAILED_CASTER_AURASTATE: return 22;
        case SPELL_FAILED_CASTER_DEAD: return 23;
        case SPELL_FAILED_CHARMED: return 24;
        case SPELL_FAILED_CHEST_IN_USE: return 25;
        case SPELL_FAILED_CONFUSED: return 26;
        case SPELL_FAILED_DONT_REPORT: return 27;
        case SPELL_FAILED_EQUIPPED_ITEM: return 28;
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS: return 29;
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND: return 30;
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND: return 31;
        case SPELL_FAILED_ERROR: return 32;
        case SPELL_FAILED_FIZZLE: return 33;
        case SPELL_FAILED_FLEEING: return 34;
        case SPELL_FAILED_FOOD_LOWLEVEL: return 35;
        case SPELL_FAILED_HIGHLEVEL: return 36;
        case SPELL_FAILED_HUNGER_SATIATED: return 37;
        case SPELL_FAILED_IMMUNE: return 38;
        case SPELL_FAILED_INCORRECT_AREA: return 39;
        case SPELL_FAILED_INTERRUPTED: return 40;
        case SPELL_FAILED_INTERRUPTED_COMBAT: return 41;
        case SPELL_FAILED_ITEM_ALREADY_ENCHANTED: return 42;
        case SPELL_FAILED_ITEM_GONE: return 43;
        case SPELL_FAILED_ITEM_NOT_FOUND: return 44;
        case SPELL_FAILED_ITEM_NOT_READY: return 45;
        case SPELL_FAILED_LEVEL_REQUIREMENT: return 46;
        case SPELL_FAILED_LINE_OF_SIGHT: return 47;
        case SPELL_FAILED_LOWLEVEL: return 48;
        case SPELL_FAILED_LOW_CASTLEVEL: return 49;
        case SPELL_FAILED_MAINHAND_EMPTY: return 50;
        case SPELL_FAILED_MOVING: return 51;
        case SPELL_FAILED_NEED_AMMO: return 52;
        case SPELL_FAILED_NEED_AMMO_POUCH: return 53;
        case SPELL_FAILED_NEED_EXOTIC_AMMO: return 54;
        case SPELL_FAILED_NEED_MORE_ITEMS: return 55;
        case SPELL_FAILED_NOPATH: return 56;
        case SPELL_FAILED_NOT_BEHIND: return 57;
        case SPELL_FAILED_NOT_FISHABLE: return 58;
        case SPELL_FAILED_NOT_FLYING: return 59;
        case SPELL_FAILED_NOT_HERE: return 60;
        case SPELL_FAILED_NOT_INFRONT: return 61;
        case SPELL_FAILED_NOT_IN_CONTROL: return 62;
        case SPELL_FAILED_NOT_KNOWN: return 63;
        case SPELL_FAILED_NOT_MOUNTED: return 64;
        case SPELL_FAILED_NOT_ON_TAXI: return 65;
        case SPELL_FAILED_NOT_ON_TRANSPORT: return 66;
        case SPELL_FAILED_NOT_READY: return 67;
        case SPELL_FAILED_NOT_SHAPESHIFT: return 68;
        case SPELL_FAILED_NOT_STANDING: return 69;
        case SPELL_FAILED_NOT_TRADEABLE: return 70;
        case SPELL_FAILED_NOT_TRADING: return 71;
        case SPELL_FAILED_NOT_UNSHEATHED: return 72;
        case SPELL_FAILED_NOT_WHILE_GHOST: return 73;
        case SPELL_FAILED_NOT_WHILE_LOOTING: return 74;
        case SPELL_FAILED_NO_AMMO: return 75;
        case SPELL_FAILED_NO_CHARGES_REMAIN: return 76;
        case SPELL_FAILED_NO_CHAMPION: return 77;
        case SPELL_FAILED_NO_COMBO_POINTS: return 78;
        case SPELL_FAILED_NO_DUELING: return 79;
        case SPELL_FAILED_NO_ENDURANCE: return 80;
        case SPELL_FAILED_NO_FISH: return 81;
        case SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED: return 82;
        case SPELL_FAILED_NO_MOUNTS_ALLOWED: return 83;
        case SPELL_FAILED_NO_PET: return 84;
        case SPELL_FAILED_NO_POWER: return 85;
        case SPELL_FAILED_NOTHING_TO_DISPEL: return 86;
        case SPELL_FAILED_NOTHING_TO_STEAL: return 87;
        case SPELL_FAILED_ONLY_ABOVEWATER: return 88;
        case SPELL_FAILED_ONLY_DAYTIME: return 89;
        case SPELL_FAILED_ONLY_INDOORS: return 90;
        case SPELL_FAILED_ONLY_MOUNTED: return 91;
        case SPELL_FAILED_ONLY_NIGHTTIME: return 92;
        case SPELL_FAILED_ONLY_OUTDOORS: return 93;
        case SPELL_FAILED_ONLY_SHAPESHIFT: return 94;
        case SPELL_FAILED_ONLY_STEALTHED: return 95;
        case SPELL_FAILED_ONLY_UNDERWATER: return 96;
        case SPELL_FAILED_OUT_OF_RANGE: return 97;
        case SPELL_FAILED_PACIFIED: return 98;
        case SPELL_FAILED_POSSESSED: return 99;
        case SPELL_FAILED_REAGENTS: return 100;
        case SPELL_FAILED_REQUIRES_AREA: return 101;
        case SPELL_FAILED_REQUIRES_SPELL_FOCUS: return 102;
        case SPELL_FAILED_ROOTED: return 103;
        case SPELL_FAILED_SILENCED: return 104;
        case SPELL_FAILED_SPELL_IN_PROGRESS: return 105;
        case SPELL_FAILED_SPELL_LEARNED: return 106;
        case SPELL_FAILED_SPELL_UNAVAILABLE: return 107;
        case SPELL_FAILED_STUNNED: return 108;
        case SPELL_FAILED_TARGETS_DEAD: return 109;
        case SPELL_FAILED_TARGET_AFFECTING_COMBAT: return 110;
        case SPELL_FAILED_TARGET_AURASTATE: return 111;
        case SPELL_FAILED_TARGET_DUELING: return 112;
        case SPELL_FAILED_TARGET_ENEMY: return 113;
        case SPELL_FAILED_TARGET_ENRAGED: return 114;
        case SPELL_FAILED_TARGET_FRIENDLY: return 115;
        case SPELL_FAILED_TARGET_IN_COMBAT: return 116;
        case SPELL_FAILED_TARGET_IS_PLAYER: return 117;
        case SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED: return 118;
        case SPELL_FAILED_TARGET_NOT_DEAD: return 119;
        case SPELL_FAILED_TARGET_NOT_IN_PARTY: return 120;
        case SPELL_FAILED_TARGET_NOT_LOOTED: return 121;
        case SPELL_FAILED_TARGET_NOT_PLAYER: return 122;
        case SPELL_FAILED_TARGET_NO_POCKETS: return 123;
        case SPELL_FAILED_TARGET_NO_WEAPONS: return 124;
        case SPELL_FAILED_TARGET_NO_RANGED_WEAPONS: return 125;
        case SPELL_FAILED_TARGET_UNSKINNABLE: return 126;
        case SPELL_FAILED_THIRST_SATIATED: return 127;
        case SPELL_FAILED_TOO_CLOSE: return 128;
        case SPELL_FAILED_TOO_MANY_OF_ITEM: return 129;
        case SPELL_FAILED_TOTEM_CATEGORY: return 130;
        case SPELL_FAILED_TOTEMS: return 131;
        case SPELL_FAILED_TRY_AGAIN: return 132;
        case SPELL_FAILED_UNIT_NOT_BEHIND: return 133;
        case SPELL_FAILED_UNIT_NOT_INFRONT: return 134;
        case SPELL_FAILED_WRONG_PET_FOOD: return 135;
        case SPELL_FAILED_NOT_WHILE_FATIGUED: return 136;
        case SPELL_FAILED_TARGET_NOT_IN_INSTANCE: return 137;
        case SPELL_FAILED_NOT_WHILE_TRADING: return 138;
        case SPELL_FAILED_TARGET_NOT_IN_RAID: return 139;
        case SPELL_FAILED_TARGET_FREEFORALL: return 140;
        case SPELL_FAILED_NO_EDIBLE_CORPSES: return 141;
        case SPELL_FAILED_ONLY_BATTLEGROUNDS: return 142;
        case SPELL_FAILED_TARGET_NOT_GHOST: return 143;
        case SPELL_FAILED_TRANSFORM_UNUSABLE: return 144;
        case SPELL_FAILED_WRONG_WEATHER: return 145;
        case SPELL_FAILED_DAMAGE_IMMUNE: return 146;
        case SPELL_FAILED_PREVENTED_BY_MECHANIC: return 147;
        case SPELL_FAILED_PLAY_TIME: return 148;
        case SPELL_FAILED_REPUTATION: return 149;
        case SPELL_FAILED_MIN_SKILL: return 150;
        case SPELL_FAILED_NOT_IN_ARENA: return 151;
        case SPELL_FAILED_NOT_ON_SHAPESHIFT: return 152;
        case SPELL_FAILED_NOT_ON_STEALTHED: return 153;
        case SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE: return 154;
        case SPELL_FAILED_NOT_ON_MOUNTED: return 155;
        case SPELL_FAILED_TOO_SHALLOW: return 156;
        case SPELL_FAILED_TARGET_NOT_IN_SANCTUARY: return 157;
        case SPELL_FAILED_TARGET_IS_TRIVIAL: return 158;
        case SPELL_FAILED_BM_OR_INVISGOD: return 159;
        case SPELL_FAILED_EXPERT_RIDING_REQUIREMENT: return 160;
        case SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT: return 161;
        case SPELL_FAILED_NOT_IDLE: return 162;
        case SPELL_FAILED_NOT_INACTIVE: return 163;
        case SPELL_FAILED_PARTIAL_PLAYTIME: return 164;
        case SPELL_FAILED_NO_PLAYTIME: return 165;
        case SPELL_FAILED_NOT_IN_BATTLEGROUND: return 166;
        case SPELL_FAILED_NOT_IN_RAID_INSTANCE: return 167;
        case SPELL_FAILED_ONLY_IN_ARENA: return 168;
        case SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE: return 169;
        case SPELL_FAILED_ON_USE_ENCHANT: return 170;
        case SPELL_FAILED_NOT_ON_GROUND: return 171;
        case SPELL_FAILED_CUSTOM_ERROR: return 172;
        case SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW: return 173;
        case SPELL_FAILED_TOO_MANY_SOCKETS: return 174;
        case SPELL_FAILED_INVALID_GLYPH: return 175;
        case SPELL_FAILED_UNIQUE_GLYPH: return 176;
        case SPELL_FAILED_GLYPH_SOCKET_LOCKED: return 177;
        case SPELL_FAILED_NO_VALID_TARGETS: return 178;
        case SPELL_FAILED_ITEM_AT_MAX_CHARGES: return 179;
        case SPELL_FAILED_NOT_IN_BARBERSHOP: return 180;
        case SPELL_FAILED_FISHING_TOO_LOW: return 181;
        case SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW: return 182;
        case SPELL_FAILED_SUMMON_PENDING: return 183;
        case SPELL_FAILED_MAX_SOCKETS: return 184;
        case SPELL_FAILED_PET_CAN_RENAME: return 185;
        case SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED: return 186;
        case SPELL_FAILED_UNKNOWN: return 187;
        case SPELL_CAST_OK: return 188;
        default: throw std::out_of_range("value");
    }
}

/*********************************************************************\
|* data for enum 'AuraStateType' in 'SharedDefines.h' auto-generated *|
\*********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<AuraStateType>::ToString(AuraStateType value)
{
    switch (value)
    {
        case AURA_STATE_NONE: return { "AURA_STATE_NONE", "AURA_STATE_NONE", "C   |" };
        case AURA_STATE_DEFENSE: return { "AURA_STATE_DEFENSE", "AURA_STATE_DEFENSE", "C   |" };
        case AURA_STATE_HEALTHLESS_20_PERCENT: return { "AURA_STATE_HEALTHLESS_20_PERCENT", "AURA_STATE_HEALTHLESS_20_PERCENT", "CcT |" };
        case AURA_STATE_BERSERKING: return { "AURA_STATE_BERSERKING", "AURA_STATE_BERSERKING", "C T |" };
        case AURA_STATE_FROZEN: return { "AURA_STATE_FROZEN", "AURA_STATE_FROZEN", "c t| frozen target" };
        case AURA_STATE_JUDGEMENT: return { "AURA_STATE_JUDGEMENT", "AURA_STATE_JUDGEMENT", "C   |" };
        case AURA_STATE_HUNTER_PARRY: return { "AURA_STATE_HUNTER_PARRY", "AURA_STATE_HUNTER_PARRY", "C   |" };
        case AURA_STATE_WARRIOR_VICTORY_RUSH: return { "AURA_STATE_WARRIOR_VICTORY_RUSH", "AURA_STATE_WARRIOR_VICTORY_RUSH", "C   | warrior victory rush" };
        case AURA_STATE_FAERIE_FIRE: return { "AURA_STATE_FAERIE_FIRE", "AURA_STATE_FAERIE_FIRE", "c t|" };
        case AURA_STATE_HEALTHLESS_35_PERCENT: return { "AURA_STATE_HEALTHLESS_35_PERCENT", "AURA_STATE_HEALTHLESS_35_PERCENT", "C T |" };
        case AURA_STATE_CONFLAGRATE: return { "AURA_STATE_CONFLAGRATE", "AURA_STATE_CONFLAGRATE", "T |" };
        case AURA_STATE_SWIFTMEND: return { "AURA_STATE_SWIFTMEND", "AURA_STATE_SWIFTMEND", "T |" };
        case AURA_STATE_DEADLY_POISON: return { "AURA_STATE_DEADLY_POISON", "AURA_STATE_DEADLY_POISON", "T |" };
        case AURA_STATE_ENRAGE: return { "AURA_STATE_ENRAGE", "AURA_STATE_ENRAGE", "C   |" };
        case AURA_STATE_BLEEDING: return { "AURA_STATE_BLEEDING", "AURA_STATE_BLEEDING", "T|" };
        case AURA_STATE_UNKNOWN19: return { "AURA_STATE_UNKNOWN19", "AURA_STATE_UNKNOWN19", "|" };
        case AURA_STATE_UNKNOWN22: return { "AURA_STATE_UNKNOWN22", "AURA_STATE_UNKNOWN22", "C  t| varius spells (63884, 50240)" };
        case AURA_STATE_HEALTH_ABOVE_75_PERCENT: return { "AURA_STATE_HEALTH_ABOVE_75_PERCENT", "AURA_STATE_HEALTH_ABOVE_75_PERCENT", "C   |" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<AuraStateType>::Count() { return 18; }

template <>
TC_API_EXPORT AuraStateType EnumUtils<AuraStateType>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return AURA_STATE_NONE;
        case 1: return AURA_STATE_DEFENSE;
        case 2: return AURA_STATE_HEALTHLESS_20_PERCENT;
        case 3: return AURA_STATE_BERSERKING;
        case 4: return AURA_STATE_FROZEN;
        case 5: return AURA_STATE_JUDGEMENT;
        case 6: return AURA_STATE_HUNTER_PARRY;
        case 7: return AURA_STATE_WARRIOR_VICTORY_RUSH;
        case 8: return AURA_STATE_FAERIE_FIRE;
        case 9: return AURA_STATE_HEALTHLESS_35_PERCENT;
        case 10: return AURA_STATE_CONFLAGRATE;
        case 11: return AURA_STATE_SWIFTMEND;
        case 12: return AURA_STATE_DEADLY_POISON;
        case 13: return AURA_STATE_ENRAGE;
        case 14: return AURA_STATE_BLEEDING;
        case 15: return AURA_STATE_UNKNOWN19;
        case 16: return AURA_STATE_UNKNOWN22;
        case 17: return AURA_STATE_HEALTH_ABOVE_75_PERCENT;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<AuraStateType>::ToIndex(AuraStateType value)
{
    switch (value)
    {
        case AURA_STATE_NONE: return 0;
        case AURA_STATE_DEFENSE: return 1;
        case AURA_STATE_HEALTHLESS_20_PERCENT: return 2;
        case AURA_STATE_BERSERKING: return 3;
        case AURA_STATE_FROZEN: return 4;
        case AURA_STATE_JUDGEMENT: return 5;
        case AURA_STATE_HUNTER_PARRY: return 6;
        case AURA_STATE_WARRIOR_VICTORY_RUSH: return 7;
        case AURA_STATE_FAERIE_FIRE: return 8;
        case AURA_STATE_HEALTHLESS_35_PERCENT: return 9;
        case AURA_STATE_CONFLAGRATE: return 10;
        case AURA_STATE_SWIFTMEND: return 11;
        case AURA_STATE_DEADLY_POISON: return 12;
        case AURA_STATE_ENRAGE: return 13;
        case AURA_STATE_BLEEDING: return 14;
        case AURA_STATE_UNKNOWN19: return 15;
        case AURA_STATE_UNKNOWN22: return 16;
        case AURA_STATE_HEALTH_ABOVE_75_PERCENT: return 17;
        default: throw std::out_of_range("value");
    }
}

/*****************************************************************\
|* data for enum 'Mechanics' in 'SharedDefines.h' auto-generated *|
\*****************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<Mechanics>::ToString(Mechanics value)
{
    switch (value)
    {
        case MECHANIC_NONE: return { "MECHANIC_NONE", "MECHANIC_NONE", "" };
        case MECHANIC_CHARM: return { "MECHANIC_CHARM", "MECHANIC_CHARM", "" };
        case MECHANIC_DISORIENTED: return { "MECHANIC_DISORIENTED", "MECHANIC_DISORIENTED", "" };
        case MECHANIC_DISARM: return { "MECHANIC_DISARM", "MECHANIC_DISARM", "" };
        case MECHANIC_DISTRACT: return { "MECHANIC_DISTRACT", "MECHANIC_DISTRACT", "" };
        case MECHANIC_FEAR: return { "MECHANIC_FEAR", "MECHANIC_FEAR", "" };
        case MECHANIC_GRIP: return { "MECHANIC_GRIP", "MECHANIC_GRIP", "" };
        case MECHANIC_ROOT: return { "MECHANIC_ROOT", "MECHANIC_ROOT", "" };
        case MECHANIC_SLOW_ATTACK: return { "MECHANIC_SLOW_ATTACK", "MECHANIC_SLOW_ATTACK", "" };
        case MECHANIC_SILENCE: return { "MECHANIC_SILENCE", "MECHANIC_SILENCE", "" };
        case MECHANIC_SLEEP: return { "MECHANIC_SLEEP", "MECHANIC_SLEEP", "" };
        case MECHANIC_SNARE: return { "MECHANIC_SNARE", "MECHANIC_SNARE", "" };
        case MECHANIC_STUN: return { "MECHANIC_STUN", "MECHANIC_STUN", "" };
        case MECHANIC_FREEZE: return { "MECHANIC_FREEZE", "MECHANIC_FREEZE", "" };
        case MECHANIC_KNOCKOUT: return { "MECHANIC_KNOCKOUT", "MECHANIC_KNOCKOUT", "" };
        case MECHANIC_BLEED: return { "MECHANIC_BLEED", "MECHANIC_BLEED", "" };
        case MECHANIC_BANDAGE: return { "MECHANIC_BANDAGE", "MECHANIC_BANDAGE", "" };
        case MECHANIC_POLYMORPH: return { "MECHANIC_POLYMORPH", "MECHANIC_POLYMORPH", "" };
        case MECHANIC_BANISH: return { "MECHANIC_BANISH", "MECHANIC_BANISH", "" };
        case MECHANIC_SHIELD: return { "MECHANIC_SHIELD", "MECHANIC_SHIELD", "" };
        case MECHANIC_SHACKLE: return { "MECHANIC_SHACKLE", "MECHANIC_SHACKLE", "" };
        case MECHANIC_MOUNT: return { "MECHANIC_MOUNT", "MECHANIC_MOUNT", "" };
        case MECHANIC_INFECTED: return { "MECHANIC_INFECTED", "MECHANIC_INFECTED", "" };
        case MECHANIC_TURN: return { "MECHANIC_TURN", "MECHANIC_TURN", "" };
        case MECHANIC_HORROR: return { "MECHANIC_HORROR", "MECHANIC_HORROR", "" };
        case MECHANIC_INVULNERABILITY: return { "MECHANIC_INVULNERABILITY", "MECHANIC_INVULNERABILITY", "" };
        case MECHANIC_INTERRUPT: return { "MECHANIC_INTERRUPT", "MECHANIC_INTERRUPT", "" };
        case MECHANIC_DAZE: return { "MECHANIC_DAZE", "MECHANIC_DAZE", "" };
        case MECHANIC_DISCOVERY: return { "MECHANIC_DISCOVERY", "MECHANIC_DISCOVERY", "" };
        case MECHANIC_IMMUNE_SHIELD: return { "MECHANIC_IMMUNE_SHIELD", "MECHANIC_IMMUNE_SHIELD", "Divine (Blessing) Shield/Protection and Ice Block" };
        case MECHANIC_SAPPED: return { "MECHANIC_SAPPED", "MECHANIC_SAPPED", "" };
        case MECHANIC_ENRAGED: return { "MECHANIC_ENRAGED", "MECHANIC_ENRAGED", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Mechanics>::Count() { return 32; }

template <>
TC_API_EXPORT Mechanics EnumUtils<Mechanics>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return MECHANIC_NONE;
        case 1: return MECHANIC_CHARM;
        case 2: return MECHANIC_DISORIENTED;
        case 3: return MECHANIC_DISARM;
        case 4: return MECHANIC_DISTRACT;
        case 5: return MECHANIC_FEAR;
        case 6: return MECHANIC_GRIP;
        case 7: return MECHANIC_ROOT;
        case 8: return MECHANIC_SLOW_ATTACK;
        case 9: return MECHANIC_SILENCE;
        case 10: return MECHANIC_SLEEP;
        case 11: return MECHANIC_SNARE;
        case 12: return MECHANIC_STUN;
        case 13: return MECHANIC_FREEZE;
        case 14: return MECHANIC_KNOCKOUT;
        case 15: return MECHANIC_BLEED;
        case 16: return MECHANIC_BANDAGE;
        case 17: return MECHANIC_POLYMORPH;
        case 18: return MECHANIC_BANISH;
        case 19: return MECHANIC_SHIELD;
        case 20: return MECHANIC_SHACKLE;
        case 21: return MECHANIC_MOUNT;
        case 22: return MECHANIC_INFECTED;
        case 23: return MECHANIC_TURN;
        case 24: return MECHANIC_HORROR;
        case 25: return MECHANIC_INVULNERABILITY;
        case 26: return MECHANIC_INTERRUPT;
        case 27: return MECHANIC_DAZE;
        case 28: return MECHANIC_DISCOVERY;
        case 29: return MECHANIC_IMMUNE_SHIELD;
        case 30: return MECHANIC_SAPPED;
        case 31: return MECHANIC_ENRAGED;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Mechanics>::ToIndex(Mechanics value)
{
    switch (value)
    {
        case MECHANIC_NONE: return 0;
        case MECHANIC_CHARM: return 1;
        case MECHANIC_DISORIENTED: return 2;
        case MECHANIC_DISARM: return 3;
        case MECHANIC_DISTRACT: return 4;
        case MECHANIC_FEAR: return 5;
        case MECHANIC_GRIP: return 6;
        case MECHANIC_ROOT: return 7;
        case MECHANIC_SLOW_ATTACK: return 8;
        case MECHANIC_SILENCE: return 9;
        case MECHANIC_SLEEP: return 10;
        case MECHANIC_SNARE: return 11;
        case MECHANIC_STUN: return 12;
        case MECHANIC_FREEZE: return 13;
        case MECHANIC_KNOCKOUT: return 14;
        case MECHANIC_BLEED: return 15;
        case MECHANIC_BANDAGE: return 16;
        case MECHANIC_POLYMORPH: return 17;
        case MECHANIC_BANISH: return 18;
        case MECHANIC_SHIELD: return 19;
        case MECHANIC_SHACKLE: return 20;
        case MECHANIC_MOUNT: return 21;
        case MECHANIC_INFECTED: return 22;
        case MECHANIC_TURN: return 23;
        case MECHANIC_HORROR: return 24;
        case MECHANIC_INVULNERABILITY: return 25;
        case MECHANIC_INTERRUPT: return 26;
        case MECHANIC_DAZE: return 27;
        case MECHANIC_DISCOVERY: return 28;
        case MECHANIC_IMMUNE_SHIELD: return 29;
        case MECHANIC_SAPPED: return 30;
        case MECHANIC_ENRAGED: return 31;
        default: throw std::out_of_range("value");
    }
}

/*********************************************************************\
|* data for enum 'SpellDmgClass' in 'SharedDefines.h' auto-generated *|
\*********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellDmgClass>::ToString(SpellDmgClass value)
{
    switch (value)
    {
        case SPELL_DAMAGE_CLASS_NONE: return { "SPELL_DAMAGE_CLASS_NONE", "None", "" };
        case SPELL_DAMAGE_CLASS_MAGIC: return { "SPELL_DAMAGE_CLASS_MAGIC", "Magic", "" };
        case SPELL_DAMAGE_CLASS_MELEE: return { "SPELL_DAMAGE_CLASS_MELEE", "Melee", "" };
        case SPELL_DAMAGE_CLASS_RANGED: return { "SPELL_DAMAGE_CLASS_RANGED", "Ranged", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellDmgClass>::Count() { return 4; }

template <>
TC_API_EXPORT SpellDmgClass EnumUtils<SpellDmgClass>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_DAMAGE_CLASS_NONE;
        case 1: return SPELL_DAMAGE_CLASS_MAGIC;
        case 2: return SPELL_DAMAGE_CLASS_MELEE;
        case 3: return SPELL_DAMAGE_CLASS_RANGED;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellDmgClass>::ToIndex(SpellDmgClass value)
{
    switch (value)
    {
        case SPELL_DAMAGE_CLASS_NONE: return 0;
        case SPELL_DAMAGE_CLASS_MAGIC: return 1;
        case SPELL_DAMAGE_CLASS_MELEE: return 2;
        case SPELL_DAMAGE_CLASS_RANGED: return 3;
        default: throw std::out_of_range("value");
    }
}

/***************************************************************************\
|* data for enum 'SpellPreventionType' in 'SharedDefines.h' auto-generated *|
\***************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellPreventionType>::ToString(SpellPreventionType value)
{
    switch (value)
    {
        case SPELL_PREVENTION_TYPE_NONE: return { "SPELL_PREVENTION_TYPE_NONE", "None", "" };
        case SPELL_PREVENTION_TYPE_SILENCE: return { "SPELL_PREVENTION_TYPE_SILENCE", "Silence", "" };
        case SPELL_PREVENTION_TYPE_PACIFY: return { "SPELL_PREVENTION_TYPE_PACIFY", "Pacify", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellPreventionType>::Count() { return 3; }

template <>
TC_API_EXPORT SpellPreventionType EnumUtils<SpellPreventionType>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_PREVENTION_TYPE_NONE;
        case 1: return SPELL_PREVENTION_TYPE_SILENCE;
        case 2: return SPELL_PREVENTION_TYPE_PACIFY;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellPreventionType>::ToIndex(SpellPreventionType value)
{
    switch (value)
    {
        case SPELL_PREVENTION_TYPE_NONE: return 0;
        case SPELL_PREVENTION_TYPE_SILENCE: return 1;
        case SPELL_PREVENTION_TYPE_PACIFY: return 2;
        default: throw std::out_of_range("value");
    }
}

/*************************************************************\
|* data for enum 'Emote' in 'SharedDefines.h' auto-generated *|
\*************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<Emote>::ToString(Emote value)
{
    switch (value)
    {
        case EMOTE_ONESHOT_TALK: return { "EMOTE_ONESHOT_TALK", "EMOTE_ONESHOT_TALK", "" };
        case EMOTE_ONESHOT_BOW: return { "EMOTE_ONESHOT_BOW", "EMOTE_ONESHOT_BOW", "" };
        case EMOTE_ONESHOT_WAVE: return { "EMOTE_ONESHOT_WAVE", "EMOTE_ONESHOT_WAVE", "" };
        case EMOTE_ONESHOT_CHEER: return { "EMOTE_ONESHOT_CHEER", "EMOTE_ONESHOT_CHEER", "" };
        case EMOTE_ONESHOT_EXCLAMATION: return { "EMOTE_ONESHOT_EXCLAMATION", "EMOTE_ONESHOT_EXCLAMATION", "" };
        case EMOTE_ONESHOT_QUESTION: return { "EMOTE_ONESHOT_QUESTION", "EMOTE_ONESHOT_QUESTION", "" };
        case EMOTE_ONESHOT_EAT: return { "EMOTE_ONESHOT_EAT", "EMOTE_ONESHOT_EAT", "" };
        case EMOTE_STATE_DANCE: return { "EMOTE_STATE_DANCE", "EMOTE_STATE_DANCE", "" };
        case EMOTE_ONESHOT_LAUGH: return { "EMOTE_ONESHOT_LAUGH", "EMOTE_ONESHOT_LAUGH", "" };
        case EMOTE_STATE_SLEEP: return { "EMOTE_STATE_SLEEP", "EMOTE_STATE_SLEEP", "" };
        case EMOTE_STATE_SIT: return { "EMOTE_STATE_SIT", "EMOTE_STATE_SIT", "" };
        case EMOTE_ONESHOT_RUDE: return { "EMOTE_ONESHOT_RUDE", "EMOTE_ONESHOT_RUDE", "" };
        case EMOTE_ONESHOT_ROAR: return { "EMOTE_ONESHOT_ROAR", "EMOTE_ONESHOT_ROAR", "" };
        case EMOTE_ONESHOT_KNEEL: return { "EMOTE_ONESHOT_KNEEL", "EMOTE_ONESHOT_KNEEL", "" };
        case EMOTE_ONESHOT_KISS: return { "EMOTE_ONESHOT_KISS", "EMOTE_ONESHOT_KISS", "" };
        case EMOTE_ONESHOT_CRY: return { "EMOTE_ONESHOT_CRY", "EMOTE_ONESHOT_CRY", "" };
        case EMOTE_ONESHOT_CHICKEN: return { "EMOTE_ONESHOT_CHICKEN", "EMOTE_ONESHOT_CHICKEN", "" };
        case EMOTE_ONESHOT_BEG: return { "EMOTE_ONESHOT_BEG", "EMOTE_ONESHOT_BEG", "" };
        case EMOTE_ONESHOT_APPLAUD: return { "EMOTE_ONESHOT_APPLAUD", "EMOTE_ONESHOT_APPLAUD", "" };
        case EMOTE_ONESHOT_SHOUT: return { "EMOTE_ONESHOT_SHOUT", "EMOTE_ONESHOT_SHOUT", "" };
        case EMOTE_ONESHOT_FLEX: return { "EMOTE_ONESHOT_FLEX", "EMOTE_ONESHOT_FLEX", "" };
        case EMOTE_ONESHOT_SHY: return { "EMOTE_ONESHOT_SHY", "EMOTE_ONESHOT_SHY", "" };
        case EMOTE_ONESHOT_POINT: return { "EMOTE_ONESHOT_POINT", "EMOTE_ONESHOT_POINT", "" };
        case EMOTE_STATE_STAND: return { "EMOTE_STATE_STAND", "EMOTE_STATE_STAND", "" };
        case EMOTE_STATE_READY_UNARMED: return { "EMOTE_STATE_READY_UNARMED", "EMOTE_STATE_READY_UNARMED", "" };
        case EMOTE_STATE_WORK_SHEATHED: return { "EMOTE_STATE_WORK_SHEATHED", "EMOTE_STATE_WORK_SHEATHED", "" };
        case EMOTE_STATE_POINT: return { "EMOTE_STATE_POINT", "EMOTE_STATE_POINT", "" };
        case EMOTE_STATE_NONE: return { "EMOTE_STATE_NONE", "EMOTE_STATE_NONE", "" };
        case EMOTE_ONESHOT_WOUND: return { "EMOTE_ONESHOT_WOUND", "EMOTE_ONESHOT_WOUND", "" };
        case EMOTE_ONESHOT_WOUND_CRITICAL: return { "EMOTE_ONESHOT_WOUND_CRITICAL", "EMOTE_ONESHOT_WOUND_CRITICAL", "" };
        case EMOTE_ONESHOT_ATTACK_UNARMED: return { "EMOTE_ONESHOT_ATTACK_UNARMED", "EMOTE_ONESHOT_ATTACK_UNARMED", "" };
        case EMOTE_ONESHOT_ATTACK1H: return { "EMOTE_ONESHOT_ATTACK1H", "EMOTE_ONESHOT_ATTACK1H", "" };
        case EMOTE_ONESHOT_ATTACK2HTIGHT: return { "EMOTE_ONESHOT_ATTACK2HTIGHT", "EMOTE_ONESHOT_ATTACK2HTIGHT", "" };
        case EMOTE_ONESHOT_ATTACK2H_LOOSE: return { "EMOTE_ONESHOT_ATTACK2H_LOOSE", "EMOTE_ONESHOT_ATTACK2H_LOOSE", "" };
        case EMOTE_ONESHOT_PARRY_UNARMED: return { "EMOTE_ONESHOT_PARRY_UNARMED", "EMOTE_ONESHOT_PARRY_UNARMED", "" };
        case EMOTE_ONESHOT_PARRY_SHIELD: return { "EMOTE_ONESHOT_PARRY_SHIELD", "EMOTE_ONESHOT_PARRY_SHIELD", "" };
        case EMOTE_ONESHOT_READY_UNARMED: return { "EMOTE_ONESHOT_READY_UNARMED", "EMOTE_ONESHOT_READY_UNARMED", "" };
        case EMOTE_ONESHOT_READY1H: return { "EMOTE_ONESHOT_READY1H", "EMOTE_ONESHOT_READY1H", "" };
        case EMOTE_ONESHOT_READY_BOW: return { "EMOTE_ONESHOT_READY_BOW", "EMOTE_ONESHOT_READY_BOW", "" };
        case EMOTE_ONESHOT_SPELL_PRECAST: return { "EMOTE_ONESHOT_SPELL_PRECAST", "EMOTE_ONESHOT_SPELL_PRECAST", "" };
        case EMOTE_ONESHOT_SPELL_CAST: return { "EMOTE_ONESHOT_SPELL_CAST", "EMOTE_ONESHOT_SPELL_CAST", "" };
        case EMOTE_ONESHOT_BATTLE_ROAR: return { "EMOTE_ONESHOT_BATTLE_ROAR", "EMOTE_ONESHOT_BATTLE_ROAR", "" };
        case EMOTE_ONESHOT_SPECIALATTACK1H: return { "EMOTE_ONESHOT_SPECIALATTACK1H", "EMOTE_ONESHOT_SPECIALATTACK1H", "" };
        case EMOTE_ONESHOT_KICK: return { "EMOTE_ONESHOT_KICK", "EMOTE_ONESHOT_KICK", "" };
        case EMOTE_ONESHOT_ATTACK_THROWN: return { "EMOTE_ONESHOT_ATTACK_THROWN", "EMOTE_ONESHOT_ATTACK_THROWN", "" };
        case EMOTE_STATE_STUN: return { "EMOTE_STATE_STUN", "EMOTE_STATE_STUN", "" };
        case EMOTE_STATE_DEAD: return { "EMOTE_STATE_DEAD", "EMOTE_STATE_DEAD", "" };
        case EMOTE_ONESHOT_SALUTE: return { "EMOTE_ONESHOT_SALUTE", "EMOTE_ONESHOT_SALUTE", "" };
        case EMOTE_STATE_KNEEL: return { "EMOTE_STATE_KNEEL", "EMOTE_STATE_KNEEL", "" };
        case EMOTE_STATE_USE_STANDING: return { "EMOTE_STATE_USE_STANDING", "EMOTE_STATE_USE_STANDING", "" };
        case EMOTE_ONESHOT_WAVE_NO_SHEATHE: return { "EMOTE_ONESHOT_WAVE_NO_SHEATHE", "EMOTE_ONESHOT_WAVE_NO_SHEATHE", "" };
        case EMOTE_ONESHOT_CHEER_NO_SHEATHE: return { "EMOTE_ONESHOT_CHEER_NO_SHEATHE", "EMOTE_ONESHOT_CHEER_NO_SHEATHE", "" };
        case EMOTE_ONESHOT_EAT_NO_SHEATHE: return { "EMOTE_ONESHOT_EAT_NO_SHEATHE", "EMOTE_ONESHOT_EAT_NO_SHEATHE", "" };
        case EMOTE_STATE_STUN_NO_SHEATHE: return { "EMOTE_STATE_STUN_NO_SHEATHE", "EMOTE_STATE_STUN_NO_SHEATHE", "" };
        case EMOTE_ONESHOT_DANCE: return { "EMOTE_ONESHOT_DANCE", "EMOTE_ONESHOT_DANCE", "" };
        case EMOTE_ONESHOT_SALUTE_NO_SHEATH: return { "EMOTE_ONESHOT_SALUTE_NO_SHEATH", "EMOTE_ONESHOT_SALUTE_NO_SHEATH", "" };
        case EMOTE_STATE_USE_STANDING_NO_SHEATHE: return { "EMOTE_STATE_USE_STANDING_NO_SHEATHE", "EMOTE_STATE_USE_STANDING_NO_SHEATHE", "" };
        case EMOTE_ONESHOT_LAUGH_NO_SHEATHE: return { "EMOTE_ONESHOT_LAUGH_NO_SHEATHE", "EMOTE_ONESHOT_LAUGH_NO_SHEATHE", "" };
        case EMOTE_STATE_WORK: return { "EMOTE_STATE_WORK", "EMOTE_STATE_WORK", "" };
        case EMOTE_STATE_SPELL_PRECAST: return { "EMOTE_STATE_SPELL_PRECAST", "EMOTE_STATE_SPELL_PRECAST", "" };
        case EMOTE_ONESHOT_READY_RIFLE: return { "EMOTE_ONESHOT_READY_RIFLE", "EMOTE_ONESHOT_READY_RIFLE", "" };
        case EMOTE_STATE_READY_RIFLE: return { "EMOTE_STATE_READY_RIFLE", "EMOTE_STATE_READY_RIFLE", "" };
        case EMOTE_STATE_WORK_MINING: return { "EMOTE_STATE_WORK_MINING", "EMOTE_STATE_WORK_MINING", "" };
        case EMOTE_STATE_WORK_CHOPWOOD: return { "EMOTE_STATE_WORK_CHOPWOOD", "EMOTE_STATE_WORK_CHOPWOOD", "" };
        case EMOTE_STATE_APPLAUD: return { "EMOTE_STATE_APPLAUD", "EMOTE_STATE_APPLAUD", "" };
        case EMOTE_ONESHOT_LIFTOFF: return { "EMOTE_ONESHOT_LIFTOFF", "EMOTE_ONESHOT_LIFTOFF", "" };
        case EMOTE_ONESHOT_YES: return { "EMOTE_ONESHOT_YES", "EMOTE_ONESHOT_YES", "" };
        case EMOTE_ONESHOT_NO: return { "EMOTE_ONESHOT_NO", "EMOTE_ONESHOT_NO", "" };
        case EMOTE_ONESHOT_TRAIN: return { "EMOTE_ONESHOT_TRAIN", "EMOTE_ONESHOT_TRAIN", "" };
        case EMOTE_ONESHOT_LAND: return { "EMOTE_ONESHOT_LAND", "EMOTE_ONESHOT_LAND", "" };
        case EMOTE_STATE_AT_EASE: return { "EMOTE_STATE_AT_EASE", "EMOTE_STATE_AT_EASE", "" };
        case EMOTE_STATE_READY1H: return { "EMOTE_STATE_READY1H", "EMOTE_STATE_READY1H", "" };
        case EMOTE_STATE_SPELL_KNEEL_START: return { "EMOTE_STATE_SPELL_KNEEL_START", "EMOTE_STATE_SPELL_KNEEL_START", "" };
        case EMOTE_STATE_SUBMERGED: return { "EMOTE_STATE_SUBMERGED", "EMOTE_STATE_SUBMERGED", "" };
        case EMOTE_ONESHOT_SUBMERGE: return { "EMOTE_ONESHOT_SUBMERGE", "EMOTE_ONESHOT_SUBMERGE", "" };
        case EMOTE_STATE_READY2H: return { "EMOTE_STATE_READY2H", "EMOTE_STATE_READY2H", "" };
        case EMOTE_STATE_READY_BOW: return { "EMOTE_STATE_READY_BOW", "EMOTE_STATE_READY_BOW", "" };
        case EMOTE_ONESHOT_MOUNT_SPECIAL: return { "EMOTE_ONESHOT_MOUNT_SPECIAL", "EMOTE_ONESHOT_MOUNT_SPECIAL", "" };
        case EMOTE_STATE_TALK: return { "EMOTE_STATE_TALK", "EMOTE_STATE_TALK", "" };
        case EMOTE_STATE_FISHING: return { "EMOTE_STATE_FISHING", "EMOTE_STATE_FISHING", "" };
        case EMOTE_ONESHOT_FISHING: return { "EMOTE_ONESHOT_FISHING", "EMOTE_ONESHOT_FISHING", "" };
        case EMOTE_ONESHOT_LOOT: return { "EMOTE_ONESHOT_LOOT", "EMOTE_ONESHOT_LOOT", "" };
        case EMOTE_STATE_WHIRLWIND: return { "EMOTE_STATE_WHIRLWIND", "EMOTE_STATE_WHIRLWIND", "" };
        case EMOTE_STATE_DROWNED: return { "EMOTE_STATE_DROWNED", "EMOTE_STATE_DROWNED", "" };
        case EMOTE_STATE_HOLD_BOW: return { "EMOTE_STATE_HOLD_BOW", "EMOTE_STATE_HOLD_BOW", "" };
        case EMOTE_STATE_HOLD_RIFLE: return { "EMOTE_STATE_HOLD_RIFLE", "EMOTE_STATE_HOLD_RIFLE", "" };
        case EMOTE_STATE_HOLD_THROWN: return { "EMOTE_STATE_HOLD_THROWN", "EMOTE_STATE_HOLD_THROWN", "" };
        case EMOTE_ONESHOT_DROWN: return { "EMOTE_ONESHOT_DROWN", "EMOTE_ONESHOT_DROWN", "" };
        case EMOTE_ONESHOT_STOMP: return { "EMOTE_ONESHOT_STOMP", "EMOTE_ONESHOT_STOMP", "" };
        case EMOTE_ONESHOT_ATTACK_OFF: return { "EMOTE_ONESHOT_ATTACK_OFF", "EMOTE_ONESHOT_ATTACK_OFF", "" };
        case EMOTE_ONESHOT_ATTACK_OFF_PIERCE: return { "EMOTE_ONESHOT_ATTACK_OFF_PIERCE", "EMOTE_ONESHOT_ATTACK_OFF_PIERCE", "" };
        case EMOTE_STATE_ROAR: return { "EMOTE_STATE_ROAR", "EMOTE_STATE_ROAR", "" };
        case EMOTE_STATE_LAUGH: return { "EMOTE_STATE_LAUGH", "EMOTE_STATE_LAUGH", "" };
        case EMOTE_ONESHOT_CREATURE_SPECIAL: return { "EMOTE_ONESHOT_CREATURE_SPECIAL", "EMOTE_ONESHOT_CREATURE_SPECIAL", "" };
        case EMOTE_ONESHOT_JUMPLANDRUN: return { "EMOTE_ONESHOT_JUMPLANDRUN", "EMOTE_ONESHOT_JUMPLANDRUN", "" };
        case EMOTE_ONESHOT_JUMPEND: return { "EMOTE_ONESHOT_JUMPEND", "EMOTE_ONESHOT_JUMPEND", "" };
        case EMOTE_ONESHOT_TALK_NO_SHEATHE: return { "EMOTE_ONESHOT_TALK_NO_SHEATHE", "EMOTE_ONESHOT_TALK_NO_SHEATHE", "" };
        case EMOTE_ONESHOT_POINT_NO_SHEATHE: return { "EMOTE_ONESHOT_POINT_NO_SHEATHE", "EMOTE_ONESHOT_POINT_NO_SHEATHE", "" };
        case EMOTE_STATE_CANNIBALIZE: return { "EMOTE_STATE_CANNIBALIZE", "EMOTE_STATE_CANNIBALIZE", "" };
        case EMOTE_ONESHOT_JUMPSTART: return { "EMOTE_ONESHOT_JUMPSTART", "EMOTE_ONESHOT_JUMPSTART", "" };
        case EMOTE_STATE_DANCESPECIAL: return { "EMOTE_STATE_DANCESPECIAL", "EMOTE_STATE_DANCESPECIAL", "" };
        case EMOTE_ONESHOT_DANCESPECIAL: return { "EMOTE_ONESHOT_DANCESPECIAL", "EMOTE_ONESHOT_DANCESPECIAL", "" };
        case EMOTE_ONESHOT_CUSTOM_SPELL_01: return { "EMOTE_ONESHOT_CUSTOM_SPELL_01", "EMOTE_ONESHOT_CUSTOM_SPELL_01", "" };
        case EMOTE_ONESHOT_CUSTOM_SPELL_02: return { "EMOTE_ONESHOT_CUSTOM_SPELL_02", "EMOTE_ONESHOT_CUSTOM_SPELL_02", "" };
        case EMOTE_ONESHOT_CUSTOM_SPELL_03: return { "EMOTE_ONESHOT_CUSTOM_SPELL_03", "EMOTE_ONESHOT_CUSTOM_SPELL_03", "" };
        case EMOTE_ONESHOT_CUSTOM_SPELL_04: return { "EMOTE_ONESHOT_CUSTOM_SPELL_04", "EMOTE_ONESHOT_CUSTOM_SPELL_04", "" };
        case EMOTE_ONESHOT_CUSTOM_SPELL_05: return { "EMOTE_ONESHOT_CUSTOM_SPELL_05", "EMOTE_ONESHOT_CUSTOM_SPELL_05", "" };
        case EMOTE_ONESHOT_CUSTOM_SPELL_06: return { "EMOTE_ONESHOT_CUSTOM_SPELL_06", "EMOTE_ONESHOT_CUSTOM_SPELL_06", "" };
        case EMOTE_ONESHOT_CUSTOM_SPELL_07: return { "EMOTE_ONESHOT_CUSTOM_SPELL_07", "EMOTE_ONESHOT_CUSTOM_SPELL_07", "" };
        case EMOTE_ONESHOT_CUSTOM_SPELL_08: return { "EMOTE_ONESHOT_CUSTOM_SPELL_08", "EMOTE_ONESHOT_CUSTOM_SPELL_08", "" };
        case EMOTE_ONESHOT_CUSTOM_SPELL_09: return { "EMOTE_ONESHOT_CUSTOM_SPELL_09", "EMOTE_ONESHOT_CUSTOM_SPELL_09", "" };
        case EMOTE_ONESHOT_CUSTOM_SPELL_10: return { "EMOTE_ONESHOT_CUSTOM_SPELL_10", "EMOTE_ONESHOT_CUSTOM_SPELL_10", "" };
        case EMOTE_STATE_EXCLAIM: return { "EMOTE_STATE_EXCLAIM", "EMOTE_STATE_EXCLAIM", "" };
        case EMOTE_STATE_DANCE_CUSTOM: return { "EMOTE_STATE_DANCE_CUSTOM", "EMOTE_STATE_DANCE_CUSTOM", "" };
        case EMOTE_STATE_SIT_CHAIR_MED: return { "EMOTE_STATE_SIT_CHAIR_MED", "EMOTE_STATE_SIT_CHAIR_MED", "" };
        case EMOTE_STATE_CUSTOM_SPELL_01: return { "EMOTE_STATE_CUSTOM_SPELL_01", "EMOTE_STATE_CUSTOM_SPELL_01", "" };
        case EMOTE_STATE_CUSTOM_SPELL_02: return { "EMOTE_STATE_CUSTOM_SPELL_02", "EMOTE_STATE_CUSTOM_SPELL_02", "" };
        case EMOTE_STATE_EAT: return { "EMOTE_STATE_EAT", "EMOTE_STATE_EAT", "" };
        case EMOTE_STATE_CUSTOM_SPELL_04: return { "EMOTE_STATE_CUSTOM_SPELL_04", "EMOTE_STATE_CUSTOM_SPELL_04", "" };
        case EMOTE_STATE_CUSTOM_SPELL_03: return { "EMOTE_STATE_CUSTOM_SPELL_03", "EMOTE_STATE_CUSTOM_SPELL_03", "" };
        case EMOTE_STATE_CUSTOM_SPELL_05: return { "EMOTE_STATE_CUSTOM_SPELL_05", "EMOTE_STATE_CUSTOM_SPELL_05", "" };
        case EMOTE_STATE_SPELLEFFECT_HOLD: return { "EMOTE_STATE_SPELLEFFECT_HOLD", "EMOTE_STATE_SPELLEFFECT_HOLD", "" };
        case EMOTE_STATE_EAT_NO_SHEATHE: return { "EMOTE_STATE_EAT_NO_SHEATHE", "EMOTE_STATE_EAT_NO_SHEATHE", "" };
        case EMOTE_STATE_MOUNT: return { "EMOTE_STATE_MOUNT", "EMOTE_STATE_MOUNT", "" };
        case EMOTE_STATE_READY2HL: return { "EMOTE_STATE_READY2HL", "EMOTE_STATE_READY2HL", "" };
        case EMOTE_STATE_SIT_CHAIR_HIGH: return { "EMOTE_STATE_SIT_CHAIR_HIGH", "EMOTE_STATE_SIT_CHAIR_HIGH", "" };
        case EMOTE_STATE_FALL: return { "EMOTE_STATE_FALL", "EMOTE_STATE_FALL", "" };
        case EMOTE_STATE_LOOT: return { "EMOTE_STATE_LOOT", "EMOTE_STATE_LOOT", "" };
        case EMOTE_STATE_SUBMERGED_NEW: return { "EMOTE_STATE_SUBMERGED_NEW", "EMOTE_STATE_SUBMERGED_NEW", "" };
        case EMOTE_ONESHOT_COWER: return { "EMOTE_ONESHOT_COWER", "EMOTE_ONESHOT_COWER", "" };
        case EMOTE_STATE_COWER: return { "EMOTE_STATE_COWER", "EMOTE_STATE_COWER", "" };
        case EMOTE_ONESHOT_USE_STANDING: return { "EMOTE_ONESHOT_USE_STANDING", "EMOTE_ONESHOT_USE_STANDING", "" };
        case EMOTE_STATE_STEALTH_STAND: return { "EMOTE_STATE_STEALTH_STAND", "EMOTE_STATE_STEALTH_STAND", "" };
        case EMOTE_ONESHOT_OMNICAST_GHOUL: return { "EMOTE_ONESHOT_OMNICAST_GHOUL", "EMOTE_ONESHOT_OMNICAST_GHOUL", "" };
        case EMOTE_ONESHOT_ATTACK_BOW: return { "EMOTE_ONESHOT_ATTACK_BOW", "EMOTE_ONESHOT_ATTACK_BOW", "" };
        case EMOTE_ONESHOT_ATTACK_RIFLE: return { "EMOTE_ONESHOT_ATTACK_RIFLE", "EMOTE_ONESHOT_ATTACK_RIFLE", "" };
        case EMOTE_STATE_SWIM_IDLE: return { "EMOTE_STATE_SWIM_IDLE", "EMOTE_STATE_SWIM_IDLE", "" };
        case EMOTE_STATE_ATTACK_UNARMED: return { "EMOTE_STATE_ATTACK_UNARMED", "EMOTE_STATE_ATTACK_UNARMED", "" };
        case EMOTE_ONESHOT_SPELL_CAST_W_SOUND: return { "EMOTE_ONESHOT_SPELL_CAST_W_SOUND", "EMOTE_ONESHOT_SPELL_CAST_W_SOUND", "" };
        case EMOTE_ONESHOT_DODGE: return { "EMOTE_ONESHOT_DODGE", "EMOTE_ONESHOT_DODGE", "" };
        case EMOTE_ONESHOT_PARRY1H: return { "EMOTE_ONESHOT_PARRY1H", "EMOTE_ONESHOT_PARRY1H", "" };
        case EMOTE_ONESHOT_PARRY2H: return { "EMOTE_ONESHOT_PARRY2H", "EMOTE_ONESHOT_PARRY2H", "" };
        case EMOTE_ONESHOT_PARRY2HL: return { "EMOTE_ONESHOT_PARRY2HL", "EMOTE_ONESHOT_PARRY2HL", "" };
        case EMOTE_STATE_FLYFALL: return { "EMOTE_STATE_FLYFALL", "EMOTE_STATE_FLYFALL", "" };
        case EMOTE_ONESHOT_FLYDEATH: return { "EMOTE_ONESHOT_FLYDEATH", "EMOTE_ONESHOT_FLYDEATH", "" };
        case EMOTE_STATE_FLY_FALL: return { "EMOTE_STATE_FLY_FALL", "EMOTE_STATE_FLY_FALL", "" };
        case EMOTE_ONESHOT_FLY_SIT_GROUND_DOWN: return { "EMOTE_ONESHOT_FLY_SIT_GROUND_DOWN", "EMOTE_ONESHOT_FLY_SIT_GROUND_DOWN", "" };
        case EMOTE_ONESHOT_FLY_SIT_GROUND_UP: return { "EMOTE_ONESHOT_FLY_SIT_GROUND_UP", "EMOTE_ONESHOT_FLY_SIT_GROUND_UP", "" };
        case EMOTE_ONESHOT_EMERGE: return { "EMOTE_ONESHOT_EMERGE", "EMOTE_ONESHOT_EMERGE", "" };
        case EMOTE_ONESHOT_DRAGON_SPIT: return { "EMOTE_ONESHOT_DRAGON_SPIT", "EMOTE_ONESHOT_DRAGON_SPIT", "" };
        case EMOTE_STATE_SPECIAL_UNARMED: return { "EMOTE_STATE_SPECIAL_UNARMED", "EMOTE_STATE_SPECIAL_UNARMED", "" };
        case EMOTE_ONESHOT_FLYGRAB: return { "EMOTE_ONESHOT_FLYGRAB", "EMOTE_ONESHOT_FLYGRAB", "" };
        case EMOTE_STATE_FLYGRABCLOSED: return { "EMOTE_STATE_FLYGRABCLOSED", "EMOTE_STATE_FLYGRABCLOSED", "" };
        case EMOTE_ONESHOT_FLYGRABTHROWN: return { "EMOTE_ONESHOT_FLYGRABTHROWN", "EMOTE_ONESHOT_FLYGRABTHROWN", "" };
        case EMOTE_STATE_FLY_SIT_GROUND: return { "EMOTE_STATE_FLY_SIT_GROUND", "EMOTE_STATE_FLY_SIT_GROUND", "" };
        case EMOTE_STATE_WALK_BACKWARDS: return { "EMOTE_STATE_WALK_BACKWARDS", "EMOTE_STATE_WALK_BACKWARDS", "" };
        case EMOTE_ONESHOT_FLYTALK: return { "EMOTE_ONESHOT_FLYTALK", "EMOTE_ONESHOT_FLYTALK", "" };
        case EMOTE_ONESHOT_FLYATTACK1H: return { "EMOTE_ONESHOT_FLYATTACK1H", "EMOTE_ONESHOT_FLYATTACK1H", "" };
        case EMOTE_STATE_CUSTOM_SPELL_08: return { "EMOTE_STATE_CUSTOM_SPELL_08", "EMOTE_STATE_CUSTOM_SPELL_08", "" };
        case EMOTE_ONESHOT_FLY_DRAGON_SPIT: return { "EMOTE_ONESHOT_FLY_DRAGON_SPIT", "EMOTE_ONESHOT_FLY_DRAGON_SPIT", "" };
        case EMOTE_STATE_SIT_CHAIR_LOW: return { "EMOTE_STATE_SIT_CHAIR_LOW", "EMOTE_STATE_SIT_CHAIR_LOW", "" };
        case EMOTE_ONESHOT_STUN: return { "EMOTE_ONESHOT_STUN", "EMOTE_ONESHOT_STUN", "" };
        case EMOTE_ONESHOT_SPELL_CAST_OMNI: return { "EMOTE_ONESHOT_SPELL_CAST_OMNI", "EMOTE_ONESHOT_SPELL_CAST_OMNI", "" };
        case EMOTE_STATE_READY_THROWN: return { "EMOTE_STATE_READY_THROWN", "EMOTE_STATE_READY_THROWN", "" };
        case EMOTE_ONESHOT_WORK_CHOPWOOD: return { "EMOTE_ONESHOT_WORK_CHOPWOOD", "EMOTE_ONESHOT_WORK_CHOPWOOD", "" };
        case EMOTE_ONESHOT_WORK_MINING: return { "EMOTE_ONESHOT_WORK_MINING", "EMOTE_ONESHOT_WORK_MINING", "" };
        case EMOTE_STATE_SPELL_CHANNEL_OMNI: return { "EMOTE_STATE_SPELL_CHANNEL_OMNI", "EMOTE_STATE_SPELL_CHANNEL_OMNI", "" };
        case EMOTE_STATE_SPELL_CHANNEL_DIRECTED: return { "EMOTE_STATE_SPELL_CHANNEL_DIRECTED", "EMOTE_STATE_SPELL_CHANNEL_DIRECTED", "" };
        case EMOTE_STAND_STATE_NONE: return { "EMOTE_STAND_STATE_NONE", "EMOTE_STAND_STATE_NONE", "" };
        case EMOTE_STATE_READYJOUST: return { "EMOTE_STATE_READYJOUST", "EMOTE_STATE_READYJOUST", "" };
        case EMOTE_STATE_STRANGULATE: return { "EMOTE_STATE_STRANGULATE", "EMOTE_STATE_STRANGULATE", "" };
        case EMOTE_STATE_READY_SPELL_OMNI: return { "EMOTE_STATE_READY_SPELL_OMNI", "EMOTE_STATE_READY_SPELL_OMNI", "" };
        case EMOTE_STATE_HOLD_JOUST: return { "EMOTE_STATE_HOLD_JOUST", "EMOTE_STATE_HOLD_JOUST", "" };
        case EMOTE_ONESHOT_CRY_JAINA: return { "EMOTE_ONESHOT_CRY_JAINA", "EMOTE_ONESHOT_CRY_JAINA", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Emote>::Count() { return 174; }

template <>
TC_API_EXPORT Emote EnumUtils<Emote>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return EMOTE_ONESHOT_TALK;
        case 1: return EMOTE_ONESHOT_BOW;
        case 2: return EMOTE_ONESHOT_WAVE;
        case 3: return EMOTE_ONESHOT_CHEER;
        case 4: return EMOTE_ONESHOT_EXCLAMATION;
        case 5: return EMOTE_ONESHOT_QUESTION;
        case 6: return EMOTE_ONESHOT_EAT;
        case 7: return EMOTE_STATE_DANCE;
        case 8: return EMOTE_ONESHOT_LAUGH;
        case 9: return EMOTE_STATE_SLEEP;
        case 10: return EMOTE_STATE_SIT;
        case 11: return EMOTE_ONESHOT_RUDE;
        case 12: return EMOTE_ONESHOT_ROAR;
        case 13: return EMOTE_ONESHOT_KNEEL;
        case 14: return EMOTE_ONESHOT_KISS;
        case 15: return EMOTE_ONESHOT_CRY;
        case 16: return EMOTE_ONESHOT_CHICKEN;
        case 17: return EMOTE_ONESHOT_BEG;
        case 18: return EMOTE_ONESHOT_APPLAUD;
        case 19: return EMOTE_ONESHOT_SHOUT;
        case 20: return EMOTE_ONESHOT_FLEX;
        case 21: return EMOTE_ONESHOT_SHY;
        case 22: return EMOTE_ONESHOT_POINT;
        case 23: return EMOTE_STATE_STAND;
        case 24: return EMOTE_STATE_READY_UNARMED;
        case 25: return EMOTE_STATE_WORK_SHEATHED;
        case 26: return EMOTE_STATE_POINT;
        case 27: return EMOTE_STATE_NONE;
        case 28: return EMOTE_ONESHOT_WOUND;
        case 29: return EMOTE_ONESHOT_WOUND_CRITICAL;
        case 30: return EMOTE_ONESHOT_ATTACK_UNARMED;
        case 31: return EMOTE_ONESHOT_ATTACK1H;
        case 32: return EMOTE_ONESHOT_ATTACK2HTIGHT;
        case 33: return EMOTE_ONESHOT_ATTACK2H_LOOSE;
        case 34: return EMOTE_ONESHOT_PARRY_UNARMED;
        case 35: return EMOTE_ONESHOT_PARRY_SHIELD;
        case 36: return EMOTE_ONESHOT_READY_UNARMED;
        case 37: return EMOTE_ONESHOT_READY1H;
        case 38: return EMOTE_ONESHOT_READY_BOW;
        case 39: return EMOTE_ONESHOT_SPELL_PRECAST;
        case 40: return EMOTE_ONESHOT_SPELL_CAST;
        case 41: return EMOTE_ONESHOT_BATTLE_ROAR;
        case 42: return EMOTE_ONESHOT_SPECIALATTACK1H;
        case 43: return EMOTE_ONESHOT_KICK;
        case 44: return EMOTE_ONESHOT_ATTACK_THROWN;
        case 45: return EMOTE_STATE_STUN;
        case 46: return EMOTE_STATE_DEAD;
        case 47: return EMOTE_ONESHOT_SALUTE;
        case 48: return EMOTE_STATE_KNEEL;
        case 49: return EMOTE_STATE_USE_STANDING;
        case 50: return EMOTE_ONESHOT_WAVE_NO_SHEATHE;
        case 51: return EMOTE_ONESHOT_CHEER_NO_SHEATHE;
        case 52: return EMOTE_ONESHOT_EAT_NO_SHEATHE;
        case 53: return EMOTE_STATE_STUN_NO_SHEATHE;
        case 54: return EMOTE_ONESHOT_DANCE;
        case 55: return EMOTE_ONESHOT_SALUTE_NO_SHEATH;
        case 56: return EMOTE_STATE_USE_STANDING_NO_SHEATHE;
        case 57: return EMOTE_ONESHOT_LAUGH_NO_SHEATHE;
        case 58: return EMOTE_STATE_WORK;
        case 59: return EMOTE_STATE_SPELL_PRECAST;
        case 60: return EMOTE_ONESHOT_READY_RIFLE;
        case 61: return EMOTE_STATE_READY_RIFLE;
        case 62: return EMOTE_STATE_WORK_MINING;
        case 63: return EMOTE_STATE_WORK_CHOPWOOD;
        case 64: return EMOTE_STATE_APPLAUD;
        case 65: return EMOTE_ONESHOT_LIFTOFF;
        case 66: return EMOTE_ONESHOT_YES;
        case 67: return EMOTE_ONESHOT_NO;
        case 68: return EMOTE_ONESHOT_TRAIN;
        case 69: return EMOTE_ONESHOT_LAND;
        case 70: return EMOTE_STATE_AT_EASE;
        case 71: return EMOTE_STATE_READY1H;
        case 72: return EMOTE_STATE_SPELL_KNEEL_START;
        case 73: return EMOTE_STATE_SUBMERGED;
        case 74: return EMOTE_ONESHOT_SUBMERGE;
        case 75: return EMOTE_STATE_READY2H;
        case 76: return EMOTE_STATE_READY_BOW;
        case 77: return EMOTE_ONESHOT_MOUNT_SPECIAL;
        case 78: return EMOTE_STATE_TALK;
        case 79: return EMOTE_STATE_FISHING;
        case 80: return EMOTE_ONESHOT_FISHING;
        case 81: return EMOTE_ONESHOT_LOOT;
        case 82: return EMOTE_STATE_WHIRLWIND;
        case 83: return EMOTE_STATE_DROWNED;
        case 84: return EMOTE_STATE_HOLD_BOW;
        case 85: return EMOTE_STATE_HOLD_RIFLE;
        case 86: return EMOTE_STATE_HOLD_THROWN;
        case 87: return EMOTE_ONESHOT_DROWN;
        case 88: return EMOTE_ONESHOT_STOMP;
        case 89: return EMOTE_ONESHOT_ATTACK_OFF;
        case 90: return EMOTE_ONESHOT_ATTACK_OFF_PIERCE;
        case 91: return EMOTE_STATE_ROAR;
        case 92: return EMOTE_STATE_LAUGH;
        case 93: return EMOTE_ONESHOT_CREATURE_SPECIAL;
        case 94: return EMOTE_ONESHOT_JUMPLANDRUN;
        case 95: return EMOTE_ONESHOT_JUMPEND;
        case 96: return EMOTE_ONESHOT_TALK_NO_SHEATHE;
        case 97: return EMOTE_ONESHOT_POINT_NO_SHEATHE;
        case 98: return EMOTE_STATE_CANNIBALIZE;
        case 99: return EMOTE_ONESHOT_JUMPSTART;
        case 100: return EMOTE_STATE_DANCESPECIAL;
        case 101: return EMOTE_ONESHOT_DANCESPECIAL;
        case 102: return EMOTE_ONESHOT_CUSTOM_SPELL_01;
        case 103: return EMOTE_ONESHOT_CUSTOM_SPELL_02;
        case 104: return EMOTE_ONESHOT_CUSTOM_SPELL_03;
        case 105: return EMOTE_ONESHOT_CUSTOM_SPELL_04;
        case 106: return EMOTE_ONESHOT_CUSTOM_SPELL_05;
        case 107: return EMOTE_ONESHOT_CUSTOM_SPELL_06;
        case 108: return EMOTE_ONESHOT_CUSTOM_SPELL_07;
        case 109: return EMOTE_ONESHOT_CUSTOM_SPELL_08;
        case 110: return EMOTE_ONESHOT_CUSTOM_SPELL_09;
        case 111: return EMOTE_ONESHOT_CUSTOM_SPELL_10;
        case 112: return EMOTE_STATE_EXCLAIM;
        case 113: return EMOTE_STATE_DANCE_CUSTOM;
        case 114: return EMOTE_STATE_SIT_CHAIR_MED;
        case 115: return EMOTE_STATE_CUSTOM_SPELL_01;
        case 116: return EMOTE_STATE_CUSTOM_SPELL_02;
        case 117: return EMOTE_STATE_EAT;
        case 118: return EMOTE_STATE_CUSTOM_SPELL_04;
        case 119: return EMOTE_STATE_CUSTOM_SPELL_03;
        case 120: return EMOTE_STATE_CUSTOM_SPELL_05;
        case 121: return EMOTE_STATE_SPELLEFFECT_HOLD;
        case 122: return EMOTE_STATE_EAT_NO_SHEATHE;
        case 123: return EMOTE_STATE_MOUNT;
        case 124: return EMOTE_STATE_READY2HL;
        case 125: return EMOTE_STATE_SIT_CHAIR_HIGH;
        case 126: return EMOTE_STATE_FALL;
        case 127: return EMOTE_STATE_LOOT;
        case 128: return EMOTE_STATE_SUBMERGED_NEW;
        case 129: return EMOTE_ONESHOT_COWER;
        case 130: return EMOTE_STATE_COWER;
        case 131: return EMOTE_ONESHOT_USE_STANDING;
        case 132: return EMOTE_STATE_STEALTH_STAND;
        case 133: return EMOTE_ONESHOT_OMNICAST_GHOUL;
        case 134: return EMOTE_ONESHOT_ATTACK_BOW;
        case 135: return EMOTE_ONESHOT_ATTACK_RIFLE;
        case 136: return EMOTE_STATE_SWIM_IDLE;
        case 137: return EMOTE_STATE_ATTACK_UNARMED;
        case 138: return EMOTE_ONESHOT_SPELL_CAST_W_SOUND;
        case 139: return EMOTE_ONESHOT_DODGE;
        case 140: return EMOTE_ONESHOT_PARRY1H;
        case 141: return EMOTE_ONESHOT_PARRY2H;
        case 142: return EMOTE_ONESHOT_PARRY2HL;
        case 143: return EMOTE_STATE_FLYFALL;
        case 144: return EMOTE_ONESHOT_FLYDEATH;
        case 145: return EMOTE_STATE_FLY_FALL;
        case 146: return EMOTE_ONESHOT_FLY_SIT_GROUND_DOWN;
        case 147: return EMOTE_ONESHOT_FLY_SIT_GROUND_UP;
        case 148: return EMOTE_ONESHOT_EMERGE;
        case 149: return EMOTE_ONESHOT_DRAGON_SPIT;
        case 150: return EMOTE_STATE_SPECIAL_UNARMED;
        case 151: return EMOTE_ONESHOT_FLYGRAB;
        case 152: return EMOTE_STATE_FLYGRABCLOSED;
        case 153: return EMOTE_ONESHOT_FLYGRABTHROWN;
        case 154: return EMOTE_STATE_FLY_SIT_GROUND;
        case 155: return EMOTE_STATE_WALK_BACKWARDS;
        case 156: return EMOTE_ONESHOT_FLYTALK;
        case 157: return EMOTE_ONESHOT_FLYATTACK1H;
        case 158: return EMOTE_STATE_CUSTOM_SPELL_08;
        case 159: return EMOTE_ONESHOT_FLY_DRAGON_SPIT;
        case 160: return EMOTE_STATE_SIT_CHAIR_LOW;
        case 161: return EMOTE_ONESHOT_STUN;
        case 162: return EMOTE_ONESHOT_SPELL_CAST_OMNI;
        case 163: return EMOTE_STATE_READY_THROWN;
        case 164: return EMOTE_ONESHOT_WORK_CHOPWOOD;
        case 165: return EMOTE_ONESHOT_WORK_MINING;
        case 166: return EMOTE_STATE_SPELL_CHANNEL_OMNI;
        case 167: return EMOTE_STATE_SPELL_CHANNEL_DIRECTED;
        case 168: return EMOTE_STAND_STATE_NONE;
        case 169: return EMOTE_STATE_READYJOUST;
        case 170: return EMOTE_STATE_STRANGULATE;
        case 171: return EMOTE_STATE_READY_SPELL_OMNI;
        case 172: return EMOTE_STATE_HOLD_JOUST;
        case 173: return EMOTE_ONESHOT_CRY_JAINA;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Emote>::ToIndex(Emote value)
{
    switch (value)
    {
        case EMOTE_ONESHOT_TALK: return 0;
        case EMOTE_ONESHOT_BOW: return 1;
        case EMOTE_ONESHOT_WAVE: return 2;
        case EMOTE_ONESHOT_CHEER: return 3;
        case EMOTE_ONESHOT_EXCLAMATION: return 4;
        case EMOTE_ONESHOT_QUESTION: return 5;
        case EMOTE_ONESHOT_EAT: return 6;
        case EMOTE_STATE_DANCE: return 7;
        case EMOTE_ONESHOT_LAUGH: return 8;
        case EMOTE_STATE_SLEEP: return 9;
        case EMOTE_STATE_SIT: return 10;
        case EMOTE_ONESHOT_RUDE: return 11;
        case EMOTE_ONESHOT_ROAR: return 12;
        case EMOTE_ONESHOT_KNEEL: return 13;
        case EMOTE_ONESHOT_KISS: return 14;
        case EMOTE_ONESHOT_CRY: return 15;
        case EMOTE_ONESHOT_CHICKEN: return 16;
        case EMOTE_ONESHOT_BEG: return 17;
        case EMOTE_ONESHOT_APPLAUD: return 18;
        case EMOTE_ONESHOT_SHOUT: return 19;
        case EMOTE_ONESHOT_FLEX: return 20;
        case EMOTE_ONESHOT_SHY: return 21;
        case EMOTE_ONESHOT_POINT: return 22;
        case EMOTE_STATE_STAND: return 23;
        case EMOTE_STATE_READY_UNARMED: return 24;
        case EMOTE_STATE_WORK_SHEATHED: return 25;
        case EMOTE_STATE_POINT: return 26;
        case EMOTE_STATE_NONE: return 27;
        case EMOTE_ONESHOT_WOUND: return 28;
        case EMOTE_ONESHOT_WOUND_CRITICAL: return 29;
        case EMOTE_ONESHOT_ATTACK_UNARMED: return 30;
        case EMOTE_ONESHOT_ATTACK1H: return 31;
        case EMOTE_ONESHOT_ATTACK2HTIGHT: return 32;
        case EMOTE_ONESHOT_ATTACK2H_LOOSE: return 33;
        case EMOTE_ONESHOT_PARRY_UNARMED: return 34;
        case EMOTE_ONESHOT_PARRY_SHIELD: return 35;
        case EMOTE_ONESHOT_READY_UNARMED: return 36;
        case EMOTE_ONESHOT_READY1H: return 37;
        case EMOTE_ONESHOT_READY_BOW: return 38;
        case EMOTE_ONESHOT_SPELL_PRECAST: return 39;
        case EMOTE_ONESHOT_SPELL_CAST: return 40;
        case EMOTE_ONESHOT_BATTLE_ROAR: return 41;
        case EMOTE_ONESHOT_SPECIALATTACK1H: return 42;
        case EMOTE_ONESHOT_KICK: return 43;
        case EMOTE_ONESHOT_ATTACK_THROWN: return 44;
        case EMOTE_STATE_STUN: return 45;
        case EMOTE_STATE_DEAD: return 46;
        case EMOTE_ONESHOT_SALUTE: return 47;
        case EMOTE_STATE_KNEEL: return 48;
        case EMOTE_STATE_USE_STANDING: return 49;
        case EMOTE_ONESHOT_WAVE_NO_SHEATHE: return 50;
        case EMOTE_ONESHOT_CHEER_NO_SHEATHE: return 51;
        case EMOTE_ONESHOT_EAT_NO_SHEATHE: return 52;
        case EMOTE_STATE_STUN_NO_SHEATHE: return 53;
        case EMOTE_ONESHOT_DANCE: return 54;
        case EMOTE_ONESHOT_SALUTE_NO_SHEATH: return 55;
        case EMOTE_STATE_USE_STANDING_NO_SHEATHE: return 56;
        case EMOTE_ONESHOT_LAUGH_NO_SHEATHE: return 57;
        case EMOTE_STATE_WORK: return 58;
        case EMOTE_STATE_SPELL_PRECAST: return 59;
        case EMOTE_ONESHOT_READY_RIFLE: return 60;
        case EMOTE_STATE_READY_RIFLE: return 61;
        case EMOTE_STATE_WORK_MINING: return 62;
        case EMOTE_STATE_WORK_CHOPWOOD: return 63;
        case EMOTE_STATE_APPLAUD: return 64;
        case EMOTE_ONESHOT_LIFTOFF: return 65;
        case EMOTE_ONESHOT_YES: return 66;
        case EMOTE_ONESHOT_NO: return 67;
        case EMOTE_ONESHOT_TRAIN: return 68;
        case EMOTE_ONESHOT_LAND: return 69;
        case EMOTE_STATE_AT_EASE: return 70;
        case EMOTE_STATE_READY1H: return 71;
        case EMOTE_STATE_SPELL_KNEEL_START: return 72;
        case EMOTE_STATE_SUBMERGED: return 73;
        case EMOTE_ONESHOT_SUBMERGE: return 74;
        case EMOTE_STATE_READY2H: return 75;
        case EMOTE_STATE_READY_BOW: return 76;
        case EMOTE_ONESHOT_MOUNT_SPECIAL: return 77;
        case EMOTE_STATE_TALK: return 78;
        case EMOTE_STATE_FISHING: return 79;
        case EMOTE_ONESHOT_FISHING: return 80;
        case EMOTE_ONESHOT_LOOT: return 81;
        case EMOTE_STATE_WHIRLWIND: return 82;
        case EMOTE_STATE_DROWNED: return 83;
        case EMOTE_STATE_HOLD_BOW: return 84;
        case EMOTE_STATE_HOLD_RIFLE: return 85;
        case EMOTE_STATE_HOLD_THROWN: return 86;
        case EMOTE_ONESHOT_DROWN: return 87;
        case EMOTE_ONESHOT_STOMP: return 88;
        case EMOTE_ONESHOT_ATTACK_OFF: return 89;
        case EMOTE_ONESHOT_ATTACK_OFF_PIERCE: return 90;
        case EMOTE_STATE_ROAR: return 91;
        case EMOTE_STATE_LAUGH: return 92;
        case EMOTE_ONESHOT_CREATURE_SPECIAL: return 93;
        case EMOTE_ONESHOT_JUMPLANDRUN: return 94;
        case EMOTE_ONESHOT_JUMPEND: return 95;
        case EMOTE_ONESHOT_TALK_NO_SHEATHE: return 96;
        case EMOTE_ONESHOT_POINT_NO_SHEATHE: return 97;
        case EMOTE_STATE_CANNIBALIZE: return 98;
        case EMOTE_ONESHOT_JUMPSTART: return 99;
        case EMOTE_STATE_DANCESPECIAL: return 100;
        case EMOTE_ONESHOT_DANCESPECIAL: return 101;
        case EMOTE_ONESHOT_CUSTOM_SPELL_01: return 102;
        case EMOTE_ONESHOT_CUSTOM_SPELL_02: return 103;
        case EMOTE_ONESHOT_CUSTOM_SPELL_03: return 104;
        case EMOTE_ONESHOT_CUSTOM_SPELL_04: return 105;
        case EMOTE_ONESHOT_CUSTOM_SPELL_05: return 106;
        case EMOTE_ONESHOT_CUSTOM_SPELL_06: return 107;
        case EMOTE_ONESHOT_CUSTOM_SPELL_07: return 108;
        case EMOTE_ONESHOT_CUSTOM_SPELL_08: return 109;
        case EMOTE_ONESHOT_CUSTOM_SPELL_09: return 110;
        case EMOTE_ONESHOT_CUSTOM_SPELL_10: return 111;
        case EMOTE_STATE_EXCLAIM: return 112;
        case EMOTE_STATE_DANCE_CUSTOM: return 113;
        case EMOTE_STATE_SIT_CHAIR_MED: return 114;
        case EMOTE_STATE_CUSTOM_SPELL_01: return 115;
        case EMOTE_STATE_CUSTOM_SPELL_02: return 116;
        case EMOTE_STATE_EAT: return 117;
        case EMOTE_STATE_CUSTOM_SPELL_04: return 118;
        case EMOTE_STATE_CUSTOM_SPELL_03: return 119;
        case EMOTE_STATE_CUSTOM_SPELL_05: return 120;
        case EMOTE_STATE_SPELLEFFECT_HOLD: return 121;
        case EMOTE_STATE_EAT_NO_SHEATHE: return 122;
        case EMOTE_STATE_MOUNT: return 123;
        case EMOTE_STATE_READY2HL: return 124;
        case EMOTE_STATE_SIT_CHAIR_HIGH: return 125;
        case EMOTE_STATE_FALL: return 126;
        case EMOTE_STATE_LOOT: return 127;
        case EMOTE_STATE_SUBMERGED_NEW: return 128;
        case EMOTE_ONESHOT_COWER: return 129;
        case EMOTE_STATE_COWER: return 130;
        case EMOTE_ONESHOT_USE_STANDING: return 131;
        case EMOTE_STATE_STEALTH_STAND: return 132;
        case EMOTE_ONESHOT_OMNICAST_GHOUL: return 133;
        case EMOTE_ONESHOT_ATTACK_BOW: return 134;
        case EMOTE_ONESHOT_ATTACK_RIFLE: return 135;
        case EMOTE_STATE_SWIM_IDLE: return 136;
        case EMOTE_STATE_ATTACK_UNARMED: return 137;
        case EMOTE_ONESHOT_SPELL_CAST_W_SOUND: return 138;
        case EMOTE_ONESHOT_DODGE: return 139;
        case EMOTE_ONESHOT_PARRY1H: return 140;
        case EMOTE_ONESHOT_PARRY2H: return 141;
        case EMOTE_ONESHOT_PARRY2HL: return 142;
        case EMOTE_STATE_FLYFALL: return 143;
        case EMOTE_ONESHOT_FLYDEATH: return 144;
        case EMOTE_STATE_FLY_FALL: return 145;
        case EMOTE_ONESHOT_FLY_SIT_GROUND_DOWN: return 146;
        case EMOTE_ONESHOT_FLY_SIT_GROUND_UP: return 147;
        case EMOTE_ONESHOT_EMERGE: return 148;
        case EMOTE_ONESHOT_DRAGON_SPIT: return 149;
        case EMOTE_STATE_SPECIAL_UNARMED: return 150;
        case EMOTE_ONESHOT_FLYGRAB: return 151;
        case EMOTE_STATE_FLYGRABCLOSED: return 152;
        case EMOTE_ONESHOT_FLYGRABTHROWN: return 153;
        case EMOTE_STATE_FLY_SIT_GROUND: return 154;
        case EMOTE_STATE_WALK_BACKWARDS: return 155;
        case EMOTE_ONESHOT_FLYTALK: return 156;
        case EMOTE_ONESHOT_FLYATTACK1H: return 157;
        case EMOTE_STATE_CUSTOM_SPELL_08: return 158;
        case EMOTE_ONESHOT_FLY_DRAGON_SPIT: return 159;
        case EMOTE_STATE_SIT_CHAIR_LOW: return 160;
        case EMOTE_ONESHOT_STUN: return 161;
        case EMOTE_ONESHOT_SPELL_CAST_OMNI: return 162;
        case EMOTE_STATE_READY_THROWN: return 163;
        case EMOTE_ONESHOT_WORK_CHOPWOOD: return 164;
        case EMOTE_ONESHOT_WORK_MINING: return 165;
        case EMOTE_STATE_SPELL_CHANNEL_OMNI: return 166;
        case EMOTE_STATE_SPELL_CHANNEL_DIRECTED: return 167;
        case EMOTE_STAND_STATE_NONE: return 168;
        case EMOTE_STATE_READYJOUST: return 169;
        case EMOTE_STATE_STRANGULATE: return 170;
        case EMOTE_STATE_READY_SPELL_OMNI: return 171;
        case EMOTE_STATE_HOLD_JOUST: return 172;
        case EMOTE_ONESHOT_CRY_JAINA: return 173;
        default: throw std::out_of_range("value");
    }
}

/*******************************************************************\
|* data for enum 'WeatherType' in 'SharedDefines.h' auto-generated *|
\*******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<WeatherType>::ToString(WeatherType value)
{
    switch (value)
    {
        case WEATHER_TYPE_FINE: return { "WEATHER_TYPE_FINE", "WEATHER_TYPE_FINE", "" };
        case WEATHER_TYPE_RAIN: return { "WEATHER_TYPE_RAIN", "WEATHER_TYPE_RAIN", "" };
        case WEATHER_TYPE_SNOW: return { "WEATHER_TYPE_SNOW", "WEATHER_TYPE_SNOW", "" };
        case WEATHER_TYPE_STORM: return { "WEATHER_TYPE_STORM", "WEATHER_TYPE_STORM", "" };
        case WEATHER_TYPE_THUNDERS: return { "WEATHER_TYPE_THUNDERS", "WEATHER_TYPE_THUNDERS", "" };
        case WEATHER_TYPE_BLACKRAIN: return { "WEATHER_TYPE_BLACKRAIN", "WEATHER_TYPE_BLACKRAIN", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<WeatherType>::Count() { return 6; }

template <>
TC_API_EXPORT WeatherType EnumUtils<WeatherType>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return WEATHER_TYPE_FINE;
        case 1: return WEATHER_TYPE_RAIN;
        case 2: return WEATHER_TYPE_SNOW;
        case 3: return WEATHER_TYPE_STORM;
        case 4: return WEATHER_TYPE_THUNDERS;
        case 5: return WEATHER_TYPE_BLACKRAIN;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<WeatherType>::ToIndex(WeatherType value)
{
    switch (value)
    {
        case WEATHER_TYPE_FINE: return 0;
        case WEATHER_TYPE_RAIN: return 1;
        case WEATHER_TYPE_SNOW: return 2;
        case WEATHER_TYPE_STORM: return 3;
        case WEATHER_TYPE_THUNDERS: return 4;
        case WEATHER_TYPE_BLACKRAIN: return 5;
        default: throw std::out_of_range("value");
    }
}

/***************************************************************\
|* data for enum 'ChatMsg' in 'SharedDefines.h' auto-generated *|
\***************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<ChatMsg>::ToString(ChatMsg value)
{
    switch (value)
    {
        case CHAT_MSG_ADDON: return { "CHAT_MSG_ADDON", "CHAT_MSG_ADDON", "-1" };
        case CHAT_MSG_SYSTEM: return { "CHAT_MSG_SYSTEM", "CHAT_MSG_SYSTEM", "" };
        case CHAT_MSG_SAY: return { "CHAT_MSG_SAY", "CHAT_MSG_SAY", "" };
        case CHAT_MSG_PARTY: return { "CHAT_MSG_PARTY", "CHAT_MSG_PARTY", "" };
        case CHAT_MSG_RAID: return { "CHAT_MSG_RAID", "CHAT_MSG_RAID", "" };
        case CHAT_MSG_GUILD: return { "CHAT_MSG_GUILD", "CHAT_MSG_GUILD", "" };
        case CHAT_MSG_OFFICER: return { "CHAT_MSG_OFFICER", "CHAT_MSG_OFFICER", "" };
        case CHAT_MSG_YELL: return { "CHAT_MSG_YELL", "CHAT_MSG_YELL", "" };
        case CHAT_MSG_WHISPER: return { "CHAT_MSG_WHISPER", "CHAT_MSG_WHISPER", "" };
        case CHAT_MSG_WHISPER_FOREIGN: return { "CHAT_MSG_WHISPER_FOREIGN", "CHAT_MSG_WHISPER_FOREIGN", "" };
        case CHAT_MSG_WHISPER_INFORM: return { "CHAT_MSG_WHISPER_INFORM", "CHAT_MSG_WHISPER_INFORM", "" };
        case CHAT_MSG_EMOTE: return { "CHAT_MSG_EMOTE", "CHAT_MSG_EMOTE", "" };
        case CHAT_MSG_TEXT_EMOTE: return { "CHAT_MSG_TEXT_EMOTE", "CHAT_MSG_TEXT_EMOTE", "" };
        case CHAT_MSG_MONSTER_SAY: return { "CHAT_MSG_MONSTER_SAY", "CHAT_MSG_MONSTER_SAY", "" };
        case CHAT_MSG_MONSTER_PARTY: return { "CHAT_MSG_MONSTER_PARTY", "CHAT_MSG_MONSTER_PARTY", "" };
        case CHAT_MSG_MONSTER_YELL: return { "CHAT_MSG_MONSTER_YELL", "CHAT_MSG_MONSTER_YELL", "" };
        case CHAT_MSG_MONSTER_WHISPER: return { "CHAT_MSG_MONSTER_WHISPER", "CHAT_MSG_MONSTER_WHISPER", "" };
        case CHAT_MSG_MONSTER_EMOTE: return { "CHAT_MSG_MONSTER_EMOTE", "CHAT_MSG_MONSTER_EMOTE", "" };
        case CHAT_MSG_CHANNEL: return { "CHAT_MSG_CHANNEL", "CHAT_MSG_CHANNEL", "" };
        case CHAT_MSG_CHANNEL_JOIN: return { "CHAT_MSG_CHANNEL_JOIN", "CHAT_MSG_CHANNEL_JOIN", "" };
        case CHAT_MSG_CHANNEL_LEAVE: return { "CHAT_MSG_CHANNEL_LEAVE", "CHAT_MSG_CHANNEL_LEAVE", "" };
        case CHAT_MSG_CHANNEL_LIST: return { "CHAT_MSG_CHANNEL_LIST", "CHAT_MSG_CHANNEL_LIST", "" };
        case CHAT_MSG_CHANNEL_NOTICE: return { "CHAT_MSG_CHANNEL_NOTICE", "CHAT_MSG_CHANNEL_NOTICE", "" };
        case CHAT_MSG_CHANNEL_NOTICE_USER: return { "CHAT_MSG_CHANNEL_NOTICE_USER", "CHAT_MSG_CHANNEL_NOTICE_USER", "" };
        case CHAT_MSG_AFK: return { "CHAT_MSG_AFK", "CHAT_MSG_AFK", "" };
        case CHAT_MSG_DND: return { "CHAT_MSG_DND", "CHAT_MSG_DND", "" };
        case CHAT_MSG_IGNORED: return { "CHAT_MSG_IGNORED", "CHAT_MSG_IGNORED", "" };
        case CHAT_MSG_SKILL: return { "CHAT_MSG_SKILL", "CHAT_MSG_SKILL", "" };
        case CHAT_MSG_LOOT: return { "CHAT_MSG_LOOT", "CHAT_MSG_LOOT", "" };
        case CHAT_MSG_MONEY: return { "CHAT_MSG_MONEY", "CHAT_MSG_MONEY", "" };
        case CHAT_MSG_OPENING: return { "CHAT_MSG_OPENING", "CHAT_MSG_OPENING", "" };
        case CHAT_MSG_TRADESKILLS: return { "CHAT_MSG_TRADESKILLS", "CHAT_MSG_TRADESKILLS", "" };
        case CHAT_MSG_PET_INFO: return { "CHAT_MSG_PET_INFO", "CHAT_MSG_PET_INFO", "" };
        case CHAT_MSG_COMBAT_MISC_INFO: return { "CHAT_MSG_COMBAT_MISC_INFO", "CHAT_MSG_COMBAT_MISC_INFO", "" };
        case CHAT_MSG_COMBAT_XP_GAIN: return { "CHAT_MSG_COMBAT_XP_GAIN", "CHAT_MSG_COMBAT_XP_GAIN", "" };
        case CHAT_MSG_COMBAT_HONOR_GAIN: return { "CHAT_MSG_COMBAT_HONOR_GAIN", "CHAT_MSG_COMBAT_HONOR_GAIN", "" };
        case CHAT_MSG_COMBAT_FACTION_CHANGE: return { "CHAT_MSG_COMBAT_FACTION_CHANGE", "CHAT_MSG_COMBAT_FACTION_CHANGE", "" };
        case CHAT_MSG_BG_SYSTEM_NEUTRAL: return { "CHAT_MSG_BG_SYSTEM_NEUTRAL", "CHAT_MSG_BG_SYSTEM_NEUTRAL", "" };
        case CHAT_MSG_BG_SYSTEM_ALLIANCE: return { "CHAT_MSG_BG_SYSTEM_ALLIANCE", "CHAT_MSG_BG_SYSTEM_ALLIANCE", "" };
        case CHAT_MSG_BG_SYSTEM_HORDE: return { "CHAT_MSG_BG_SYSTEM_HORDE", "CHAT_MSG_BG_SYSTEM_HORDE", "" };
        case CHAT_MSG_RAID_LEADER: return { "CHAT_MSG_RAID_LEADER", "CHAT_MSG_RAID_LEADER", "" };
        case CHAT_MSG_RAID_WARNING: return { "CHAT_MSG_RAID_WARNING", "CHAT_MSG_RAID_WARNING", "" };
        case CHAT_MSG_RAID_BOSS_EMOTE: return { "CHAT_MSG_RAID_BOSS_EMOTE", "CHAT_MSG_RAID_BOSS_EMOTE", "" };
        case CHAT_MSG_RAID_BOSS_WHISPER: return { "CHAT_MSG_RAID_BOSS_WHISPER", "CHAT_MSG_RAID_BOSS_WHISPER", "" };
        case CHAT_MSG_FILTERED: return { "CHAT_MSG_FILTERED", "CHAT_MSG_FILTERED", "" };
        case CHAT_MSG_BATTLEGROUND: return { "CHAT_MSG_BATTLEGROUND", "CHAT_MSG_BATTLEGROUND", "" };
        case CHAT_MSG_BATTLEGROUND_LEADER: return { "CHAT_MSG_BATTLEGROUND_LEADER", "CHAT_MSG_BATTLEGROUND_LEADER", "" };
        case CHAT_MSG_RESTRICTED: return { "CHAT_MSG_RESTRICTED", "CHAT_MSG_RESTRICTED", "" };
        case CHAT_MSG_BATTLENET: return { "CHAT_MSG_BATTLENET", "CHAT_MSG_BATTLENET", "" };
        case CHAT_MSG_ACHIEVEMENT: return { "CHAT_MSG_ACHIEVEMENT", "CHAT_MSG_ACHIEVEMENT", "" };
        case CHAT_MSG_GUILD_ACHIEVEMENT: return { "CHAT_MSG_GUILD_ACHIEVEMENT", "CHAT_MSG_GUILD_ACHIEVEMENT", "" };
        case CHAT_MSG_ARENA_POINTS: return { "CHAT_MSG_ARENA_POINTS", "CHAT_MSG_ARENA_POINTS", "" };
        case CHAT_MSG_PARTY_LEADER: return { "CHAT_MSG_PARTY_LEADER", "CHAT_MSG_PARTY_LEADER", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<ChatMsg>::Count() { return 53; }

template <>
TC_API_EXPORT ChatMsg EnumUtils<ChatMsg>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return CHAT_MSG_ADDON;
        case 1: return CHAT_MSG_SYSTEM;
        case 2: return CHAT_MSG_SAY;
        case 3: return CHAT_MSG_PARTY;
        case 4: return CHAT_MSG_RAID;
        case 5: return CHAT_MSG_GUILD;
        case 6: return CHAT_MSG_OFFICER;
        case 7: return CHAT_MSG_YELL;
        case 8: return CHAT_MSG_WHISPER;
        case 9: return CHAT_MSG_WHISPER_FOREIGN;
        case 10: return CHAT_MSG_WHISPER_INFORM;
        case 11: return CHAT_MSG_EMOTE;
        case 12: return CHAT_MSG_TEXT_EMOTE;
        case 13: return CHAT_MSG_MONSTER_SAY;
        case 14: return CHAT_MSG_MONSTER_PARTY;
        case 15: return CHAT_MSG_MONSTER_YELL;
        case 16: return CHAT_MSG_MONSTER_WHISPER;
        case 17: return CHAT_MSG_MONSTER_EMOTE;
        case 18: return CHAT_MSG_CHANNEL;
        case 19: return CHAT_MSG_CHANNEL_JOIN;
        case 20: return CHAT_MSG_CHANNEL_LEAVE;
        case 21: return CHAT_MSG_CHANNEL_LIST;
        case 22: return CHAT_MSG_CHANNEL_NOTICE;
        case 23: return CHAT_MSG_CHANNEL_NOTICE_USER;
        case 24: return CHAT_MSG_AFK;
        case 25: return CHAT_MSG_DND;
        case 26: return CHAT_MSG_IGNORED;
        case 27: return CHAT_MSG_SKILL;
        case 28: return CHAT_MSG_LOOT;
        case 29: return CHAT_MSG_MONEY;
        case 30: return CHAT_MSG_OPENING;
        case 31: return CHAT_MSG_TRADESKILLS;
        case 32: return CHAT_MSG_PET_INFO;
        case 33: return CHAT_MSG_COMBAT_MISC_INFO;
        case 34: return CHAT_MSG_COMBAT_XP_GAIN;
        case 35: return CHAT_MSG_COMBAT_HONOR_GAIN;
        case 36: return CHAT_MSG_COMBAT_FACTION_CHANGE;
        case 37: return CHAT_MSG_BG_SYSTEM_NEUTRAL;
        case 38: return CHAT_MSG_BG_SYSTEM_ALLIANCE;
        case 39: return CHAT_MSG_BG_SYSTEM_HORDE;
        case 40: return CHAT_MSG_RAID_LEADER;
        case 41: return CHAT_MSG_RAID_WARNING;
        case 42: return CHAT_MSG_RAID_BOSS_EMOTE;
        case 43: return CHAT_MSG_RAID_BOSS_WHISPER;
        case 44: return CHAT_MSG_FILTERED;
        case 45: return CHAT_MSG_BATTLEGROUND;
        case 46: return CHAT_MSG_BATTLEGROUND_LEADER;
        case 47: return CHAT_MSG_RESTRICTED;
        case 48: return CHAT_MSG_BATTLENET;
        case 49: return CHAT_MSG_ACHIEVEMENT;
        case 50: return CHAT_MSG_GUILD_ACHIEVEMENT;
        case 51: return CHAT_MSG_ARENA_POINTS;
        case 52: return CHAT_MSG_PARTY_LEADER;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<ChatMsg>::ToIndex(ChatMsg value)
{
    switch (value)
    {
        case CHAT_MSG_ADDON: return 0;
        case CHAT_MSG_SYSTEM: return 1;
        case CHAT_MSG_SAY: return 2;
        case CHAT_MSG_PARTY: return 3;
        case CHAT_MSG_RAID: return 4;
        case CHAT_MSG_GUILD: return 5;
        case CHAT_MSG_OFFICER: return 6;
        case CHAT_MSG_YELL: return 7;
        case CHAT_MSG_WHISPER: return 8;
        case CHAT_MSG_WHISPER_FOREIGN: return 9;
        case CHAT_MSG_WHISPER_INFORM: return 10;
        case CHAT_MSG_EMOTE: return 11;
        case CHAT_MSG_TEXT_EMOTE: return 12;
        case CHAT_MSG_MONSTER_SAY: return 13;
        case CHAT_MSG_MONSTER_PARTY: return 14;
        case CHAT_MSG_MONSTER_YELL: return 15;
        case CHAT_MSG_MONSTER_WHISPER: return 16;
        case CHAT_MSG_MONSTER_EMOTE: return 17;
        case CHAT_MSG_CHANNEL: return 18;
        case CHAT_MSG_CHANNEL_JOIN: return 19;
        case CHAT_MSG_CHANNEL_LEAVE: return 20;
        case CHAT_MSG_CHANNEL_LIST: return 21;
        case CHAT_MSG_CHANNEL_NOTICE: return 22;
        case CHAT_MSG_CHANNEL_NOTICE_USER: return 23;
        case CHAT_MSG_AFK: return 24;
        case CHAT_MSG_DND: return 25;
        case CHAT_MSG_IGNORED: return 26;
        case CHAT_MSG_SKILL: return 27;
        case CHAT_MSG_LOOT: return 28;
        case CHAT_MSG_MONEY: return 29;
        case CHAT_MSG_OPENING: return 30;
        case CHAT_MSG_TRADESKILLS: return 31;
        case CHAT_MSG_PET_INFO: return 32;
        case CHAT_MSG_COMBAT_MISC_INFO: return 33;
        case CHAT_MSG_COMBAT_XP_GAIN: return 34;
        case CHAT_MSG_COMBAT_HONOR_GAIN: return 35;
        case CHAT_MSG_COMBAT_FACTION_CHANGE: return 36;
        case CHAT_MSG_BG_SYSTEM_NEUTRAL: return 37;
        case CHAT_MSG_BG_SYSTEM_ALLIANCE: return 38;
        case CHAT_MSG_BG_SYSTEM_HORDE: return 39;
        case CHAT_MSG_RAID_LEADER: return 40;
        case CHAT_MSG_RAID_WARNING: return 41;
        case CHAT_MSG_RAID_BOSS_EMOTE: return 42;
        case CHAT_MSG_RAID_BOSS_WHISPER: return 43;
        case CHAT_MSG_FILTERED: return 44;
        case CHAT_MSG_BATTLEGROUND: return 45;
        case CHAT_MSG_BATTLEGROUND_LEADER: return 46;
        case CHAT_MSG_RESTRICTED: return 47;
        case CHAT_MSG_BATTLENET: return 48;
        case CHAT_MSG_ACHIEVEMENT: return 49;
        case CHAT_MSG_GUILD_ACHIEVEMENT: return 50;
        case CHAT_MSG_ARENA_POINTS: return 51;
        case CHAT_MSG_PARTY_LEADER: return 52;
        default: throw std::out_of_range("value");
    }
}

/************************************************************************\
|* data for enum 'SpellFamilyNames' in 'SharedDefines.h' auto-generated *|
\************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellFamilyNames>::ToString(SpellFamilyNames value)
{
    switch (value)
    {
        case SPELLFAMILY_GENERIC: return { "SPELLFAMILY_GENERIC", "Generic", "" };
        case SPELLFAMILY_UNK1: return { "SPELLFAMILY_UNK1", "Unk1 (events, holidays, ...)", "" };
        case SPELLFAMILY_MAGE: return { "SPELLFAMILY_MAGE", "Mage", "" };
        case SPELLFAMILY_WARRIOR: return { "SPELLFAMILY_WARRIOR", "Warrior", "" };
        case SPELLFAMILY_WARLOCK: return { "SPELLFAMILY_WARLOCK", "Warlock", "" };
        case SPELLFAMILY_PRIEST: return { "SPELLFAMILY_PRIEST", "Priest", "" };
        case SPELLFAMILY_DRUID: return { "SPELLFAMILY_DRUID", "Druid", "" };
        case SPELLFAMILY_ROGUE: return { "SPELLFAMILY_ROGUE", "Rogue", "" };
        case SPELLFAMILY_HUNTER: return { "SPELLFAMILY_HUNTER", "Hunter", "" };
        case SPELLFAMILY_PALADIN: return { "SPELLFAMILY_PALADIN", "Paladin", "" };
        case SPELLFAMILY_SHAMAN: return { "SPELLFAMILY_SHAMAN", "Shaman", "" };
        case SPELLFAMILY_UNK2: return { "SPELLFAMILY_UNK2", "Unk2 (Silence resistance?)", "" };
        case SPELLFAMILY_POTION: return { "SPELLFAMILY_POTION", "Potion", "" };
        case SPELLFAMILY_DEATHKNIGHT: return { "SPELLFAMILY_DEATHKNIGHT", "Death Knight", "" };
        case SPELLFAMILY_PET: return { "SPELLFAMILY_PET", "Pet", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellFamilyNames>::Count() { return 15; }

template <>
TC_API_EXPORT SpellFamilyNames EnumUtils<SpellFamilyNames>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELLFAMILY_GENERIC;
        case 1: return SPELLFAMILY_UNK1;
        case 2: return SPELLFAMILY_MAGE;
        case 3: return SPELLFAMILY_WARRIOR;
        case 4: return SPELLFAMILY_WARLOCK;
        case 5: return SPELLFAMILY_PRIEST;
        case 6: return SPELLFAMILY_DRUID;
        case 7: return SPELLFAMILY_ROGUE;
        case 8: return SPELLFAMILY_HUNTER;
        case 9: return SPELLFAMILY_PALADIN;
        case 10: return SPELLFAMILY_SHAMAN;
        case 11: return SPELLFAMILY_UNK2;
        case 12: return SPELLFAMILY_POTION;
        case 13: return SPELLFAMILY_DEATHKNIGHT;
        case 14: return SPELLFAMILY_PET;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellFamilyNames>::ToIndex(SpellFamilyNames value)
{
    switch (value)
    {
        case SPELLFAMILY_GENERIC: return 0;
        case SPELLFAMILY_UNK1: return 1;
        case SPELLFAMILY_MAGE: return 2;
        case SPELLFAMILY_WARRIOR: return 3;
        case SPELLFAMILY_WARLOCK: return 4;
        case SPELLFAMILY_PRIEST: return 5;
        case SPELLFAMILY_DRUID: return 6;
        case SPELLFAMILY_ROGUE: return 7;
        case SPELLFAMILY_HUNTER: return 8;
        case SPELLFAMILY_PALADIN: return 9;
        case SPELLFAMILY_SHAMAN: return 10;
        case SPELLFAMILY_UNK2: return 11;
        case SPELLFAMILY_POTION: return 12;
        case SPELLFAMILY_DEATHKNIGHT: return 13;
        case SPELLFAMILY_PET: return 14;
        default: throw std::out_of_range("value");
    }
}
}
