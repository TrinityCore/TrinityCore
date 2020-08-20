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

namespace Trinity::Impl
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
        case SPELL_ATTR1_UNK11: return { "SPELL_ATTR1_UNK11", "Unknown attribute 11@Attr1", "Aura?" };
        case SPELL_ATTR1_IS_PICKPOCKET: return { "SPELL_ATTR1_IS_PICKPOCKET", "Pickpocket (client only)", "" };
        case SPELL_ATTR1_FARSIGHT: return { "SPELL_ATTR1_FARSIGHT", "Farsight aura (client only)", "" };
        case SPELL_ATTR1_CHANNEL_TRACK_TARGET: return { "SPELL_ATTR1_CHANNEL_TRACK_TARGET", "Track target while channeling", "While channeling, adjust facing to face target" };
        case SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY: return { "SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY", "Immunity cancels preapplied auras", "For immunity spells, cancel all auras that this spell would make you immune to when the spell is applied" };
        case SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE: return { "SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE", "Unaffected by school immunities", "Will not pierce Divine Shield, Ice Block and other full invulnerabilities" };
        case SPELL_ATTR1_UNAUTOCASTABLE_BY_PET: return { "SPELL_ATTR1_UNAUTOCASTABLE_BY_PET", "Cannot be autocast by pet", "" };
        case SPELL_ATTR1_UNK18: return { "SPELL_ATTR1_UNK18", "Unknown attribute 18@Attr1", "Stun, Polymorph, Daze, Hex - CC?" };
        case SPELL_ATTR1_CANT_TARGET_SELF: return { "SPELL_ATTR1_CANT_TARGET_SELF", "Cannot be self-cast", "" };
        case SPELL_ATTR1_REQ_COMBO_POINTS1: return { "SPELL_ATTR1_REQ_COMBO_POINTS1", "Requires combo points (type 1)", "" };
        case SPELL_ATTR1_UNK21: return { "SPELL_ATTR1_UNK21", "Unknown attribute 21@Attr1", "" };
        case SPELL_ATTR1_REQ_COMBO_POINTS2: return { "SPELL_ATTR1_REQ_COMBO_POINTS2", "Requires combo points (type 2)", "" };
        case SPELL_ATTR1_UNK23: return { "SPELL_ATTR1_UNK23", "Unknwon attribute 23@Attr1", "" };
        case SPELL_ATTR1_IS_FISHING: return { "SPELL_ATTR1_IS_FISHING", "Fishing (client only)", "" };
        case SPELL_ATTR1_UNK25: return { "SPELL_ATTR1_UNK25", "Unknown attribute 25@Attr1", "" };
        case SPELL_ATTR1_UNK26: return { "SPELL_ATTR1_UNK26", "Unknown attribute 26@Attr1", "Related to [target=focus] and [target=mouseover] macros?" };
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
        case 11: return SPELL_ATTR1_UNK11;
        case 12: return SPELL_ATTR1_IS_PICKPOCKET;
        case 13: return SPELL_ATTR1_FARSIGHT;
        case 14: return SPELL_ATTR1_CHANNEL_TRACK_TARGET;
        case 15: return SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY;
        case 16: return SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE;
        case 17: return SPELL_ATTR1_UNAUTOCASTABLE_BY_PET;
        case 18: return SPELL_ATTR1_UNK18;
        case 19: return SPELL_ATTR1_CANT_TARGET_SELF;
        case 20: return SPELL_ATTR1_REQ_COMBO_POINTS1;
        case 21: return SPELL_ATTR1_UNK21;
        case 22: return SPELL_ATTR1_REQ_COMBO_POINTS2;
        case 23: return SPELL_ATTR1_UNK23;
        case 24: return SPELL_ATTR1_IS_FISHING;
        case 25: return SPELL_ATTR1_UNK25;
        case 26: return SPELL_ATTR1_UNK26;
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
        case SPELL_ATTR1_UNK11: return 11;
        case SPELL_ATTR1_IS_PICKPOCKET: return 12;
        case SPELL_ATTR1_FARSIGHT: return 13;
        case SPELL_ATTR1_CHANNEL_TRACK_TARGET: return 14;
        case SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY: return 15;
        case SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE: return 16;
        case SPELL_ATTR1_UNAUTOCASTABLE_BY_PET: return 17;
        case SPELL_ATTR1_UNK18: return 18;
        case SPELL_ATTR1_CANT_TARGET_SELF: return 19;
        case SPELL_ATTR1_REQ_COMBO_POINTS1: return 20;
        case SPELL_ATTR1_UNK21: return 21;
        case SPELL_ATTR1_REQ_COMBO_POINTS2: return 22;
        case SPELL_ATTR1_UNK23: return 23;
        case SPELL_ATTR1_IS_FISHING: return 24;
        case SPELL_ATTR1_UNK25: return 25;
        case SPELL_ATTR1_UNK26: return 26;
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
        case SPELL_ATTR2_DAMAGE_REDUCED_SHIELD: return { "SPELL_ATTR2_DAMAGE_REDUCED_SHIELD", "Damage reduction ability", "Causes BG flags to be dropped if combined with ATTR1_DISPEL_AURAS_ON_IMMUNITY" };
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
        case 21: return SPELL_ATTR2_DAMAGE_REDUCED_SHIELD;
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
        case SPELL_ATTR2_DAMAGE_REDUCED_SHIELD: return 21;
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
        case SPELL_ATTR3_BLOCKABLE_SPELL: return { "SPELL_ATTR3_BLOCKABLE_SPELL", "Blockable spell", "" };
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
        case 3: return SPELL_ATTR3_BLOCKABLE_SPELL;
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
        case SPELL_ATTR3_BLOCKABLE_SPELL: return 3;
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
        case SPELL_ATTR4_UNK21: return { "SPELL_ATTR4_UNK21", "Keep when entering arena", "" };
        case SPELL_ATTR4_UNK22: return { "SPELL_ATTR4_UNK22", "Unknown attribute 22@Attr4", "" };
        case SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS: return { "SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS", "Cannot trigger item spells", "" };
        case SPELL_ATTR4_UNK24: return { "SPELL_ATTR4_UNK24", "Unknown attribute 24@Attr4", "Shoot-type spell?" };
        case SPELL_ATTR4_IS_PET_SCALING: return { "SPELL_ATTR4_IS_PET_SCALING", "Pet Scaling aura", "" };
        case SPELL_ATTR4_CAST_ONLY_IN_OUTLAND: return { "SPELL_ATTR4_CAST_ONLY_IN_OUTLAND", "Only in Outland/Northrend", "" };
        case SPELL_ATTR4_INHERIT_CRIT_FROM_AURA: return { "SPELL_ATTR4_INHERIT_CRIT_FROM_AURA", "Inherit critical chance from triggering aura", "" };
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
        case 21: return SPELL_ATTR4_UNK21;
        case 22: return SPELL_ATTR4_UNK22;
        case 23: return SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS;
        case 24: return SPELL_ATTR4_UNK24;
        case 25: return SPELL_ATTR4_IS_PET_SCALING;
        case 26: return SPELL_ATTR4_CAST_ONLY_IN_OUTLAND;
        case 27: return SPELL_ATTR4_INHERIT_CRIT_FROM_AURA;
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
        case SPELL_ATTR4_UNK21: return 21;
        case SPELL_ATTR4_UNK22: return 22;
        case SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS: return 23;
        case SPELL_ATTR4_UNK24: return 24;
        case SPELL_ATTR4_IS_PET_SCALING: return 25;
        case SPELL_ATTR4_CAST_ONLY_IN_OUTLAND: return 26;
        case SPELL_ATTR4_INHERIT_CRIT_FROM_AURA: return 27;
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
        case SPELL_ATTR5_UNK8: return { "SPELL_ATTR5_UNK8", "Unknown attribute 8@Attr5", "" };
        case SPELL_ATTR5_START_PERIODIC_AT_APPLY: return { "SPELL_ATTR5_START_PERIODIC_AT_APPLY", "Immediately do periodic tick on apply", "" };
        case SPELL_ATTR5_HIDE_DURATION: return { "SPELL_ATTR5_HIDE_DURATION", "Do not send aura duration to client", "" };
        case SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET: return { "SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET", "Auto-target target of target (client only)", "" };
        case SPELL_ATTR5_UNK12: return { "SPELL_ATTR5_UNK12", "Unknown attribute 12@Attr5", "Cleave related?" };
        case SPELL_ATTR5_HASTE_AFFECT_DURATION: return { "SPELL_ATTR5_HASTE_AFFECT_DURATION", "Duration scales with Haste Rating", "" };
        case SPELL_ATTR5_UNK14: return { "SPELL_ATTR5_UNK14", "Unknown attribute 14@Attr5", "" };
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
        case 8: return SPELL_ATTR5_UNK8;
        case 9: return SPELL_ATTR5_START_PERIODIC_AT_APPLY;
        case 10: return SPELL_ATTR5_HIDE_DURATION;
        case 11: return SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET;
        case 12: return SPELL_ATTR5_UNK12;
        case 13: return SPELL_ATTR5_HASTE_AFFECT_DURATION;
        case 14: return SPELL_ATTR5_UNK14;
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
        case SPELL_ATTR5_UNK8: return 8;
        case SPELL_ATTR5_START_PERIODIC_AT_APPLY: return 9;
        case SPELL_ATTR5_HIDE_DURATION: return 10;
        case SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET: return 11;
        case SPELL_ATTR5_UNK12: return 12;
        case SPELL_ATTR5_HASTE_AFFECT_DURATION: return 13;
        case SPELL_ATTR5_UNK14: return 14;
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
        case SPELL_ATTR7_REACTIVATE_AT_RESURRECT: return { "SPELL_ATTR7_REACTIVATE_AT_RESURRECT", "Reactivate at resurrect (client only)", "" };
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
        case SPELL_ATTR7_UNK23: return { "SPELL_ATTR7_UNK23", "Unknown attribute 23@Attr7", "" };
        case SPELL_ATTR7_UNK24: return { "SPELL_ATTR7_UNK24", "Unknown attribute 24@Attr7", "" };
        case SPELL_ATTR7_UNK25: return { "SPELL_ATTR7_UNK25", "Unknown attribute 25@Attr7", "" };
        case SPELL_ATTR7_UNK26: return { "SPELL_ATTR7_UNK26", "Unknown attribute 26@Attr7", "" };
        case SPELL_ATTR7_UNK27: return { "SPELL_ATTR7_UNK27", "Unknown attribute 27@Attr7", "" };
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
        case 2: return SPELL_ATTR7_REACTIVATE_AT_RESURRECT;
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
        case 23: return SPELL_ATTR7_UNK23;
        case 24: return SPELL_ATTR7_UNK24;
        case 25: return SPELL_ATTR7_UNK25;
        case 26: return SPELL_ATTR7_UNK26;
        case 27: return SPELL_ATTR7_UNK27;
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
        case SPELL_ATTR7_REACTIVATE_AT_RESURRECT: return 2;
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
        case SPELL_ATTR7_UNK23: return 23;
        case SPELL_ATTR7_UNK24: return 24;
        case SPELL_ATTR7_UNK25: return 25;
        case SPELL_ATTR7_UNK26: return 26;
        case SPELL_ATTR7_UNK27: return 27;
        case SPELL_ATTR7_CONSOLIDATED_RAID_BUFF: return 28;
        case SPELL_ATTR7_UNK29: return 29;
        case SPELL_ATTR7_UNK30: return 30;
        case SPELL_ATTR7_CLIENT_INDICATOR: return 31;
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
