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
        case CLASS_MONK: return { "CLASS_MONK", "Monk", "" };
        case CLASS_DRUID: return { "CLASS_DRUID", "Druid", "" };
        case CLASS_DEMON_HUNTER: return { "CLASS_DEMON_HUNTER", "Demon Hunter", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Classes>::Count() { return 12; }

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
        case 9: return CLASS_MONK;
        case 10: return CLASS_DRUID;
        case 11: return CLASS_DEMON_HUNTER;
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
        case CLASS_MONK: return 9;
        case CLASS_DRUID: return 10;
        case CLASS_DEMON_HUNTER: return 11;
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
        case POWER_COMBO_POINTS: return { "POWER_COMBO_POINTS", "Combo Points", "" };
        case POWER_RUNES: return { "POWER_RUNES", "Runes", "" };
        case POWER_RUNIC_POWER: return { "POWER_RUNIC_POWER", "Runic Power", "" };
        case POWER_SOUL_SHARDS: return { "POWER_SOUL_SHARDS", "Soul Shards", "" };
        case POWER_LUNAR_POWER: return { "POWER_LUNAR_POWER", "Lunar Power", "" };
        case POWER_HOLY_POWER: return { "POWER_HOLY_POWER", "Holy Power", "" };
        case POWER_ALTERNATE_POWER: return { "POWER_ALTERNATE_POWER", "Alternate", "" };
        case POWER_MAELSTROM: return { "POWER_MAELSTROM", "Maelstrom", "" };
        case POWER_CHI: return { "POWER_CHI", "Chi", "" };
        case POWER_INSANITY: return { "POWER_INSANITY", "Insanity", "" };
        case POWER_BURNING_EMBERS: return { "POWER_BURNING_EMBERS", "Burning Embers (Obsolete)", "" };
        case POWER_DEMONIC_FURY: return { "POWER_DEMONIC_FURY", "Demonic Fury (Obsolete)", "" };
        case POWER_ARCANE_CHARGES: return { "POWER_ARCANE_CHARGES", "Arcane Charges", "" };
        case POWER_FURY: return { "POWER_FURY", "Fury", "" };
        case POWER_PAIN: return { "POWER_PAIN", "Pain", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Powers>::Count() { return 20; }

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
        case 5: return POWER_COMBO_POINTS;
        case 6: return POWER_RUNES;
        case 7: return POWER_RUNIC_POWER;
        case 8: return POWER_SOUL_SHARDS;
        case 9: return POWER_LUNAR_POWER;
        case 10: return POWER_HOLY_POWER;
        case 11: return POWER_ALTERNATE_POWER;
        case 12: return POWER_MAELSTROM;
        case 13: return POWER_CHI;
        case 14: return POWER_INSANITY;
        case 15: return POWER_BURNING_EMBERS;
        case 16: return POWER_DEMONIC_FURY;
        case 17: return POWER_ARCANE_CHARGES;
        case 18: return POWER_FURY;
        case 19: return POWER_PAIN;
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
        case POWER_COMBO_POINTS: return 5;
        case POWER_RUNES: return 6;
        case POWER_RUNIC_POWER: return 7;
        case POWER_SOUL_SHARDS: return 8;
        case POWER_LUNAR_POWER: return 9;
        case POWER_HOLY_POWER: return 10;
        case POWER_ALTERNATE_POWER: return 11;
        case POWER_MAELSTROM: return 12;
        case POWER_CHI: return 13;
        case POWER_INSANITY: return 14;
        case POWER_BURNING_EMBERS: return 15;
        case POWER_DEMONIC_FURY: return 16;
        case POWER_ARCANE_CHARGES: return 17;
        case POWER_FURY: return 18;
        case POWER_PAIN: return 19;
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
        case SPELL_ATTR1_CAST_WHEN_LEARNED: return { "SPELL_ATTR1_CAST_WHEN_LEARNED", "Cast When Learned", "" };
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
        case 31: return SPELL_ATTR1_CAST_WHEN_LEARNED;
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
        case SPELL_ATTR1_CAST_WHEN_LEARNED: return 31;
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
        case SPELL_ATTR2_IGNORE_ACTION_AURA_INTERRUPT_FLAGS: return { "SPELL_ATTR2_IGNORE_ACTION_AURA_INTERRUPT_FLAGS", "Not an Action", "" };
        case SPELL_ATTR2_CANT_CRIT: return { "SPELL_ATTR2_CANT_CRIT", "Cannot critically strike", "" };
        case SPELL_ATTR2_ACTIVE_THREAT: return { "SPELL_ATTR2_ACTIVE_THREAT", "Active Threat", "" };
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
        case 28: return SPELL_ATTR2_IGNORE_ACTION_AURA_INTERRUPT_FLAGS;
        case 29: return SPELL_ATTR2_CANT_CRIT;
        case 30: return SPELL_ATTR2_ACTIVE_THREAT;
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
        case SPELL_ATTR2_IGNORE_ACTION_AURA_INTERRUPT_FLAGS: return 28;
        case SPELL_ATTR2_CANT_CRIT: return 29;
        case SPELL_ATTR2_ACTIVE_THREAT: return 30;
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
        case SPELL_ATTR3_NO_PROC_EQUIP_REQUIREMENT: return { "SPELL_ATTR3_NO_PROC_EQUIP_REQUIREMENT", "No Proc Equip Requirement", "Ignores subclass mask check when checking proc" };
        case SPELL_ATTR3_UNK2: return { "SPELL_ATTR3_UNK2", "Unknown attribute 2@Attr3", "" };
        case SPELL_ATTR3_BLOCKABLE_SPELL: return { "SPELL_ATTR3_BLOCKABLE_SPELL", "Blockable spell", "" };
        case SPELL_ATTR3_IGNORE_RESURRECTION_TIMER: return { "SPELL_ATTR3_IGNORE_RESURRECTION_TIMER", "Ignore resurrection timer", "" };
        case SPELL_ATTR3_UNK5: return { "SPELL_ATTR3_UNK5", "Unknown attribute 5@Attr3", "" };
        case SPELL_ATTR3_UNK6: return { "SPELL_ATTR3_UNK6", "Unknown attribute 6@Attr3", "" };
        case SPELL_ATTR3_STACK_FOR_DIFF_CASTERS: return { "SPELL_ATTR3_STACK_FOR_DIFF_CASTERS", "Stack separately for each caster", "" };
        case SPELL_ATTR3_ONLY_TARGET_PLAYERS: return { "SPELL_ATTR3_ONLY_TARGET_PLAYERS", "Can only target players", "" };
        case SPELL_ATTR3_NOT_A_PROC: return { "SPELL_ATTR3_NOT_A_PROC", "Not a Proc", "Without this attribute, any triggered spell will be unable to trigger other auras' procs" };
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
        case SPELL_ATTR3_CAN_PROC_FROM_PROCS: return { "SPELL_ATTR3_CAN_PROC_FROM_PROCS", "Can Proc From Procs", "" };
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
        case 1: return SPELL_ATTR3_NO_PROC_EQUIP_REQUIREMENT;
        case 2: return SPELL_ATTR3_UNK2;
        case 3: return SPELL_ATTR3_BLOCKABLE_SPELL;
        case 4: return SPELL_ATTR3_IGNORE_RESURRECTION_TIMER;
        case 5: return SPELL_ATTR3_UNK5;
        case 6: return SPELL_ATTR3_UNK6;
        case 7: return SPELL_ATTR3_STACK_FOR_DIFF_CASTERS;
        case 8: return SPELL_ATTR3_ONLY_TARGET_PLAYERS;
        case 9: return SPELL_ATTR3_NOT_A_PROC;
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
        case 26: return SPELL_ATTR3_CAN_PROC_FROM_PROCS;
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
        case SPELL_ATTR3_NO_PROC_EQUIP_REQUIREMENT: return 1;
        case SPELL_ATTR3_UNK2: return 2;
        case SPELL_ATTR3_BLOCKABLE_SPELL: return 3;
        case SPELL_ATTR3_IGNORE_RESURRECTION_TIMER: return 4;
        case SPELL_ATTR3_UNK5: return 5;
        case SPELL_ATTR3_UNK6: return 6;
        case SPELL_ATTR3_STACK_FOR_DIFF_CASTERS: return 7;
        case SPELL_ATTR3_ONLY_TARGET_PLAYERS: return 8;
        case SPELL_ATTR3_NOT_A_PROC: return 9;
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
        case SPELL_ATTR3_CAN_PROC_FROM_PROCS: return 26;
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
        case SPELL_ATTR4_AURA_EXPIRES_OFFLINE: return { "SPELL_ATTR4_AURA_EXPIRES_OFFLINE", "Aura Expires Offline", "Debuffs (except Resurrection Sickness) will automatically do this" };
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
        case SPELL_ATTR4_COMBAT_LOG_NO_CASTER: return { "SPELL_ATTR4_COMBAT_LOG_NO_CASTER", "Do Not Log Caster", "" };
        case SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS: return { "SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS", "Damage does not break auras", "" };
        case SPELL_ATTR4_HIDDEN_IN_SPELLBOOK: return { "SPELL_ATTR4_HIDDEN_IN_SPELLBOOK", "Not In Spellbook", "" };
        case SPELL_ATTR4_NOT_USABLE_IN_ARENA_OR_RATED_BG: return { "SPELL_ATTR4_NOT_USABLE_IN_ARENA_OR_RATED_BG", "Not In Arena or Rated Battleground", "Makes spell unusable despite CD <= 10min" };
        case SPELL_ATTR4_USABLE_IN_ARENA: return { "SPELL_ATTR4_USABLE_IN_ARENA", "Usable in arena", "Makes spell usable despite CD > 10min" };
        case SPELL_ATTR4_AREA_TARGET_CHAIN: return { "SPELL_ATTR4_AREA_TARGET_CHAIN", "Chain area targets", "[NYI] Hits area targets over time instead of all at once" };
        case SPELL_ATTR4_UNK19: return { "SPELL_ATTR4_UNK19", "Unknown attribute 19@Attr4", "" };
        case SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER: return { "SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER", "Allow self-cast to override stronger aura (client only)", "" };
        case SPELL_ATTR4_DONT_REMOVE_IN_ARENA: return { "SPELL_ATTR4_DONT_REMOVE_IN_ARENA", "Allow Entering Arena", "" };
        case SPELL_ATTR4_UNK22: return { "SPELL_ATTR4_UNK22", "Unknown attribute 22@Attr4", "" };
        case SPELL_ATTR4_SUPPRESS_WEAPON_PROCS: return { "SPELL_ATTR4_SUPPRESS_WEAPON_PROCS", "Suppress Weapon Procs", "" };
        case SPELL_ATTR4_UNK24: return { "SPELL_ATTR4_UNK24", "Unknown attribute 24@Attr4", "Shoot-type spell?" };
        case SPELL_ATTR4_IS_PET_SCALING: return { "SPELL_ATTR4_IS_PET_SCALING", "Pet Scaling aura", "" };
        case SPELL_ATTR4_CAST_ONLY_IN_OUTLAND: return { "SPELL_ATTR4_CAST_ONLY_IN_OUTLAND", "Only in Outland/Northrend", "" };
        case SPELL_ATTR4_UNK27: return { "SPELL_ATTR4_UNK27", "Unknown attribute 27@Attr4", "" };
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
        case 2: return SPELL_ATTR4_AURA_EXPIRES_OFFLINE;
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
        case 13: return SPELL_ATTR4_COMBAT_LOG_NO_CASTER;
        case 14: return SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS;
        case 15: return SPELL_ATTR4_HIDDEN_IN_SPELLBOOK;
        case 16: return SPELL_ATTR4_NOT_USABLE_IN_ARENA_OR_RATED_BG;
        case 17: return SPELL_ATTR4_USABLE_IN_ARENA;
        case 18: return SPELL_ATTR4_AREA_TARGET_CHAIN;
        case 19: return SPELL_ATTR4_UNK19;
        case 20: return SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER;
        case 21: return SPELL_ATTR4_DONT_REMOVE_IN_ARENA;
        case 22: return SPELL_ATTR4_UNK22;
        case 23: return SPELL_ATTR4_SUPPRESS_WEAPON_PROCS;
        case 24: return SPELL_ATTR4_UNK24;
        case 25: return SPELL_ATTR4_IS_PET_SCALING;
        case 26: return SPELL_ATTR4_CAST_ONLY_IN_OUTLAND;
        case 27: return SPELL_ATTR4_UNK27;
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
        case SPELL_ATTR4_AURA_EXPIRES_OFFLINE: return 2;
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
        case SPELL_ATTR4_COMBAT_LOG_NO_CASTER: return 13;
        case SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS: return 14;
        case SPELL_ATTR4_HIDDEN_IN_SPELLBOOK: return 15;
        case SPELL_ATTR4_NOT_USABLE_IN_ARENA_OR_RATED_BG: return 16;
        case SPELL_ATTR4_USABLE_IN_ARENA: return 17;
        case SPELL_ATTR4_AREA_TARGET_CHAIN: return 18;
        case SPELL_ATTR4_UNK19: return 19;
        case SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER: return 20;
        case SPELL_ATTR4_DONT_REMOVE_IN_ARENA: return 21;
        case SPELL_ATTR4_UNK22: return 22;
        case SPELL_ATTR4_SUPPRESS_WEAPON_PROCS: return 23;
        case SPELL_ATTR4_UNK24: return 24;
        case SPELL_ATTR4_IS_PET_SCALING: return 25;
        case SPELL_ATTR4_CAST_ONLY_IN_OUTLAND: return 26;
        case SPELL_ATTR4_UNK27: return 27;
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
        case SPELL_ATTR5_REMOVE_ENTERING_ARENA: return { "SPELL_ATTR5_REMOVE_ENTERING_ARENA", "Remove Entering Arena", "Force this aura to be removed on entering arena, regardless of other properties" };
        case SPELL_ATTR5_USABLE_WHILE_STUNNED: return { "SPELL_ATTR5_USABLE_WHILE_STUNNED", "Usable while stunned", "" };
        case SPELL_ATTR5_UNK4: return { "SPELL_ATTR5_UNK4", "Unknown attribute 4@Attr5", "" };
        case SPELL_ATTR5_SINGLE_TARGET_SPELL: return { "SPELL_ATTR5_SINGLE_TARGET_SPELL", "Single-target aura", "Remove previous application to another unit if applied" };
        case SPELL_ATTR5_UNK6: return { "SPELL_ATTR5_UNK6", "Unknown attribute 6@Attr5", "" };
        case SPELL_ATTR5_UNK7: return { "SPELL_ATTR5_UNK7", "Unknown attribute 7@Attr5", "" };
        case SPELL_ATTR5_CANT_TARGET_PLAYER_CONTROLLED: return { "SPELL_ATTR5_CANT_TARGET_PLAYER_CONTROLLED", "Not On Player Controlled NPC", "" };
        case SPELL_ATTR5_START_PERIODIC_AT_APPLY: return { "SPELL_ATTR5_START_PERIODIC_AT_APPLY", "Immediately do periodic tick on apply", "" };
        case SPELL_ATTR5_HIDE_DURATION: return { "SPELL_ATTR5_HIDE_DURATION", "Do not send aura duration to client", "" };
        case SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET: return { "SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET", "Auto-target target of target (client only)", "" };
        case SPELL_ATTR5_UNK12: return { "SPELL_ATTR5_UNK12", "Unknown attribute 12@Attr5", "Cleave related?" };
        case SPELL_ATTR5_HASTE_AFFECT_DURATION: return { "SPELL_ATTR5_HASTE_AFFECT_DURATION", "Duration scales with Haste Rating", "" };
        case SPELL_ATTR5_NOT_USABLE_WHILE_CHARMED: return { "SPELL_ATTR5_NOT_USABLE_WHILE_CHARMED", "Not Available While Charmed", "" };
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
        case SPELL_ATTR5_ALWAYS_AOE_LINE_OF_SIGHT: return { "SPELL_ATTR5_ALWAYS_AOE_LINE_OF_SIGHT", "Ignore line of sight checks", "" };
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
        case 2: return SPELL_ATTR5_REMOVE_ENTERING_ARENA;
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
        case 26: return SPELL_ATTR5_ALWAYS_AOE_LINE_OF_SIGHT;
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
        case SPELL_ATTR5_REMOVE_ENTERING_ARENA: return 2;
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
        case SPELL_ATTR5_ALWAYS_AOE_LINE_OF_SIGHT: return 26;
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
        case SPELL_ATTR6_DO_NOT_CONSUME_RESOURCES: return { "SPELL_ATTR6_DO_NOT_CONSUME_RESOURCES", "Don't consume proc charges", "" };
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
        case SPELL_ATTR6_IGNORE_HEALING_MODIFIERS: return { "SPELL_ATTR6_IGNORE_HEALING_MODIFIERS", "Limit applicable %healing modifiers", "This prevents certain healing modifiers from applying - see implementation if you really care about details" };
        case SPELL_ATTR6_UNK28: return { "SPELL_ATTR6_UNK28", "Unknown attribute 28@Attr6", "Death grip?" };
        case SPELL_ATTR6_IGNORE_CASTER_DAMAGE_MODIFIERS: return { "SPELL_ATTR6_IGNORE_CASTER_DAMAGE_MODIFIERS", "Limit applicable %damage modifiers", "This prevents certain damage modifiers from applying - see implementation if you really care about details" };
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
        case 5: return SPELL_ATTR6_DO_NOT_CONSUME_RESOURCES;
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
        case 27: return SPELL_ATTR6_IGNORE_HEALING_MODIFIERS;
        case 28: return SPELL_ATTR6_UNK28;
        case 29: return SPELL_ATTR6_IGNORE_CASTER_DAMAGE_MODIFIERS;
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
        case SPELL_ATTR6_DO_NOT_CONSUME_RESOURCES: return 5;
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
        case SPELL_ATTR6_IGNORE_HEALING_MODIFIERS: return 27;
        case SPELL_ATTR6_UNK28: return 28;
        case SPELL_ATTR6_IGNORE_CASTER_DAMAGE_MODIFIERS: return 29;
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
        case SPELL_ATTR7_SUMMON_TOTEM: return { "SPELL_ATTR7_SUMMON_TOTEM", "Summons player-owned totem", "" };
        case SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE: return { "SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE", "Damage dealt by this does not cause spell pushback", "" };
        case SPELL_ATTR7_UNK7: return { "SPELL_ATTR7_UNK7", "Unknown attribute 7@Attr7", "" };
        case SPELL_ATTR7_HORDE_ONLY: return { "SPELL_ATTR7_HORDE_ONLY", "Horde only", "" };
        case SPELL_ATTR7_ALLIANCE_ONLY: return { "SPELL_ATTR7_ALLIANCE_ONLY", "Alliance only", "" };
        case SPELL_ATTR7_DISPEL_CHARGES: return { "SPELL_ATTR7_DISPEL_CHARGES", "Dispel/Spellsteal remove individual charges", "" };
        case SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER: return { "SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER", "Can Cause Interrupt", "Only interrupt non-player casting" };
        case SPELL_ATTR7_SILENCE_ONLY_NONPLAYER: return { "SPELL_ATTR7_SILENCE_ONLY_NONPLAYER", "Can Cause Silence", "" };
        case SPELL_ATTR7_CAN_ALWAYS_BE_INTERRUPTED: return { "SPELL_ATTR7_CAN_ALWAYS_BE_INTERRUPTED", "No UI Not Interruptible", "Can always be interrupted, even if caster is immune" };
        case SPELL_ATTR7_UNK14: return { "SPELL_ATTR7_UNK14", "Unknown attribute 14@Attr7", "" };
        case SPELL_ATTR7_UNK15: return { "SPELL_ATTR7_UNK15", "Unknown attribute 15@Attr7", "Exorcism - guaranteed crit vs families?" };
        case SPELL_ATTR7_HIDDEN_IN_SPELLBOOK_WHEN_LEARNED: return { "SPELL_ATTR7_HIDDEN_IN_SPELLBOOK_WHEN_LEARNED", "Only In Spellbook Until Learned", "After learning these spells become hidden in spellbook (but are visible when not learned for low level characters)" };
        case SPELL_ATTR7_UNK17: return { "SPELL_ATTR7_UNK17", "Unknown attribute 17@Attr7", "" };
        case SPELL_ATTR7_HAS_CHARGE_EFFECT: return { "SPELL_ATTR7_HAS_CHARGE_EFFECT", "Has charge effect", "" };
        case SPELL_ATTR7_ZONE_TELEPORT: return { "SPELL_ATTR7_ZONE_TELEPORT", "Is zone teleport", "" };
        case SPELL_ATTR7_UNK20: return { "SPELL_ATTR7_UNK20", "Unknown attribute 20@Attr7", "Invulnerability related?" };
        case SPELL_ATTR7_UNK21: return { "SPELL_ATTR7_UNK21", "Unknown attribute 21@Attr7", "" };
        case SPELL_ATTR7_IGNORES_COLD_WEATHER_FLYING_REQUIREMENT: return { "SPELL_ATTR7_IGNORES_COLD_WEATHER_FLYING_REQUIREMENT", "Ignores Cold Weather Flying Requirement", "" };
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
        case 5: return SPELL_ATTR7_SUMMON_TOTEM;
        case 6: return SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE;
        case 7: return SPELL_ATTR7_UNK7;
        case 8: return SPELL_ATTR7_HORDE_ONLY;
        case 9: return SPELL_ATTR7_ALLIANCE_ONLY;
        case 10: return SPELL_ATTR7_DISPEL_CHARGES;
        case 11: return SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER;
        case 12: return SPELL_ATTR7_SILENCE_ONLY_NONPLAYER;
        case 13: return SPELL_ATTR7_CAN_ALWAYS_BE_INTERRUPTED;
        case 14: return SPELL_ATTR7_UNK14;
        case 15: return SPELL_ATTR7_UNK15;
        case 16: return SPELL_ATTR7_HIDDEN_IN_SPELLBOOK_WHEN_LEARNED;
        case 17: return SPELL_ATTR7_UNK17;
        case 18: return SPELL_ATTR7_HAS_CHARGE_EFFECT;
        case 19: return SPELL_ATTR7_ZONE_TELEPORT;
        case 20: return SPELL_ATTR7_UNK20;
        case 21: return SPELL_ATTR7_UNK21;
        case 22: return SPELL_ATTR7_IGNORES_COLD_WEATHER_FLYING_REQUIREMENT;
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
        case SPELL_ATTR7_SUMMON_TOTEM: return 5;
        case SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE: return 6;
        case SPELL_ATTR7_UNK7: return 7;
        case SPELL_ATTR7_HORDE_ONLY: return 8;
        case SPELL_ATTR7_ALLIANCE_ONLY: return 9;
        case SPELL_ATTR7_DISPEL_CHARGES: return 10;
        case SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER: return 11;
        case SPELL_ATTR7_SILENCE_ONLY_NONPLAYER: return 12;
        case SPELL_ATTR7_CAN_ALWAYS_BE_INTERRUPTED: return 13;
        case SPELL_ATTR7_UNK14: return 14;
        case SPELL_ATTR7_UNK15: return 15;
        case SPELL_ATTR7_HIDDEN_IN_SPELLBOOK_WHEN_LEARNED: return 16;
        case SPELL_ATTR7_UNK17: return 17;
        case SPELL_ATTR7_HAS_CHARGE_EFFECT: return 18;
        case SPELL_ATTR7_ZONE_TELEPORT: return 19;
        case SPELL_ATTR7_UNK20: return 20;
        case SPELL_ATTR7_UNK21: return 21;
        case SPELL_ATTR7_IGNORES_COLD_WEATHER_FLYING_REQUIREMENT: return 22;
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

/******************************************************************\
|* data for enum 'SpellAttr8' in 'SharedDefines.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr8>::ToString(SpellAttr8 value)
{
    switch (value)
    {
        case SPELL_ATTR8_CANT_MISS: return { "SPELL_ATTR8_CANT_MISS", "No Attack Block", "" };
        case SPELL_ATTR8_UNK1: return { "SPELL_ATTR8_UNK1", "Unknown attribute 1@Attr8", "" };
        case SPELL_ATTR8_UNK2: return { "SPELL_ATTR8_UNK2", "Unknown attribute 2@Attr8", "" };
        case SPELL_ATTR8_UNK3: return { "SPELL_ATTR8_UNK3", "Unknown attribute 3@Attr8", "" };
        case SPELL_ATTR8_UNK4: return { "SPELL_ATTR8_UNK4", "Unknown attribute 4@Attr8", "" };
        case SPELL_ATTR8_UNK5: return { "SPELL_ATTR8_UNK5", "Unknown attribute 5@Attr8", "" };
        case SPELL_ATTR8_UNK6: return { "SPELL_ATTR8_UNK6", "Unknown attribute 6@Attr8", "" };
        case SPELL_ATTR8_UNK7: return { "SPELL_ATTR8_UNK7", "Unknown attribute 7@Attr8", "" };
        case SPELL_ATTR8_AFFECT_PARTY_AND_RAID: return { "SPELL_ATTR8_AFFECT_PARTY_AND_RAID", "Use Target's Level for Spell Scaling", "" };
        case SPELL_ATTR8_DONT_RESET_PERIODIC_TIMER: return { "SPELL_ATTR8_DONT_RESET_PERIODIC_TIMER", "Periodic Can Crit", "(WRONG) Periodic auras with this flag keep old periodic timer when refreshing at close to one tick remaining (kind of anti DoT clipping)" };
        case SPELL_ATTR8_NAME_CHANGED_DURING_TRANSFORM: return { "SPELL_ATTR8_NAME_CHANGED_DURING_TRANSFORM", "Mirror creature name", "" };
        case SPELL_ATTR8_UNK11: return { "SPELL_ATTR8_UNK11", "Unknown attribute 11@Attr8", "" };
        case SPELL_ATTR8_AURA_SEND_AMOUNT: return { "SPELL_ATTR8_AURA_SEND_AMOUNT", "Aura Points On Client", "" };
        case SPELL_ATTR8_UNK13: return { "SPELL_ATTR8_UNK13", "Unknown attribute 13@Attr8", "" };
        case SPELL_ATTR8_UNK14: return { "SPELL_ATTR8_UNK14", "Unknown attribute 14@Attr8", "" };
        case SPELL_ATTR8_WATER_MOUNT: return { "SPELL_ATTR8_WATER_MOUNT", "Requires location to be on liquid surface", "" };
        case SPELL_ATTR8_UNK16: return { "SPELL_ATTR8_UNK16", "Unknown attribute 16@Attr8", "" };
        case SPELL_ATTR8_UNK17: return { "SPELL_ATTR8_UNK17", "Unknown attribute 17@Attr8", "" };
        case SPELL_ATTR8_REMEMBER_SPELLS: return { "SPELL_ATTR8_REMEMBER_SPELLS", "SPELL_ATTR8_REMEMBER_SPELLS", "TTILE Ignore Spellcast Override Cost" };
        case SPELL_ATTR8_USE_COMBO_POINTS_ON_ANY_TARGET: return { "SPELL_ATTR8_USE_COMBO_POINTS_ON_ANY_TARGET", "Allow Targets Hidden by Spawn Tracking", "" };
        case SPELL_ATTR8_ARMOR_SPECIALIZATION: return { "SPELL_ATTR8_ARMOR_SPECIALIZATION", "Requires Equipped Inv Types", "" };
        case SPELL_ATTR8_UNK21: return { "SPELL_ATTR8_UNK21", "Unknown attribute 21@Attr8", "" };
        case SPELL_ATTR8_UNK22: return { "SPELL_ATTR8_UNK22", "Unknown attribute 22@Attr8", "" };
        case SPELL_ATTR8_BATTLE_RESURRECTION: return { "SPELL_ATTR8_BATTLE_RESURRECTION", "Enforce In Combat Ressurection Limit", "Used to limit the number of resurrections in boss encounters" };
        case SPELL_ATTR8_HEALING_SPELL: return { "SPELL_ATTR8_HEALING_SPELL", "Heal Prediction", "" };
        case SPELL_ATTR8_UNK25: return { "SPELL_ATTR8_UNK25", "Unknown attribute 25@Attr8", "" };
        case SPELL_ATTR8_RAID_MARKER: return { "SPELL_ATTR8_RAID_MARKER", "Skip Is Known Check", "" };
        case SPELL_ATTR8_UNK27: return { "SPELL_ATTR8_UNK27", "Unknown attribute 27@Attr8", "" };
        case SPELL_ATTR8_NOT_IN_BG_OR_ARENA: return { "SPELL_ATTR8_NOT_IN_BG_OR_ARENA", "Not in Battleground", "" };
        case SPELL_ATTR8_MASTERY_AFFECTS_POINTS: return { "SPELL_ATTR8_MASTERY_AFFECTS_POINTS", "Mastery Affects Points", "" };
        case SPELL_ATTR8_UNK30: return { "SPELL_ATTR8_UNK30", "Unknown attribute 30@Attr8", "" };
        case SPELL_ATTR8_ATTACK_IGNORE_IMMUNE_TO_PC_FLAG: return { "SPELL_ATTR8_ATTACK_IGNORE_IMMUNE_TO_PC_FLAG", "Can Attack ImmunePC", "Do not check UNIT_FLAG_IMMUNE_TO_PC in IsValidAttackTarget" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr8>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr8 EnumUtils<SpellAttr8>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR8_CANT_MISS;
        case 1: return SPELL_ATTR8_UNK1;
        case 2: return SPELL_ATTR8_UNK2;
        case 3: return SPELL_ATTR8_UNK3;
        case 4: return SPELL_ATTR8_UNK4;
        case 5: return SPELL_ATTR8_UNK5;
        case 6: return SPELL_ATTR8_UNK6;
        case 7: return SPELL_ATTR8_UNK7;
        case 8: return SPELL_ATTR8_AFFECT_PARTY_AND_RAID;
        case 9: return SPELL_ATTR8_DONT_RESET_PERIODIC_TIMER;
        case 10: return SPELL_ATTR8_NAME_CHANGED_DURING_TRANSFORM;
        case 11: return SPELL_ATTR8_UNK11;
        case 12: return SPELL_ATTR8_AURA_SEND_AMOUNT;
        case 13: return SPELL_ATTR8_UNK13;
        case 14: return SPELL_ATTR8_UNK14;
        case 15: return SPELL_ATTR8_WATER_MOUNT;
        case 16: return SPELL_ATTR8_UNK16;
        case 17: return SPELL_ATTR8_UNK17;
        case 18: return SPELL_ATTR8_REMEMBER_SPELLS;
        case 19: return SPELL_ATTR8_USE_COMBO_POINTS_ON_ANY_TARGET;
        case 20: return SPELL_ATTR8_ARMOR_SPECIALIZATION;
        case 21: return SPELL_ATTR8_UNK21;
        case 22: return SPELL_ATTR8_UNK22;
        case 23: return SPELL_ATTR8_BATTLE_RESURRECTION;
        case 24: return SPELL_ATTR8_HEALING_SPELL;
        case 25: return SPELL_ATTR8_UNK25;
        case 26: return SPELL_ATTR8_RAID_MARKER;
        case 27: return SPELL_ATTR8_UNK27;
        case 28: return SPELL_ATTR8_NOT_IN_BG_OR_ARENA;
        case 29: return SPELL_ATTR8_MASTERY_AFFECTS_POINTS;
        case 30: return SPELL_ATTR8_UNK30;
        case 31: return SPELL_ATTR8_ATTACK_IGNORE_IMMUNE_TO_PC_FLAG;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr8>::ToIndex(SpellAttr8 value)
{
    switch (value)
    {
        case SPELL_ATTR8_CANT_MISS: return 0;
        case SPELL_ATTR8_UNK1: return 1;
        case SPELL_ATTR8_UNK2: return 2;
        case SPELL_ATTR8_UNK3: return 3;
        case SPELL_ATTR8_UNK4: return 4;
        case SPELL_ATTR8_UNK5: return 5;
        case SPELL_ATTR8_UNK6: return 6;
        case SPELL_ATTR8_UNK7: return 7;
        case SPELL_ATTR8_AFFECT_PARTY_AND_RAID: return 8;
        case SPELL_ATTR8_DONT_RESET_PERIODIC_TIMER: return 9;
        case SPELL_ATTR8_NAME_CHANGED_DURING_TRANSFORM: return 10;
        case SPELL_ATTR8_UNK11: return 11;
        case SPELL_ATTR8_AURA_SEND_AMOUNT: return 12;
        case SPELL_ATTR8_UNK13: return 13;
        case SPELL_ATTR8_UNK14: return 14;
        case SPELL_ATTR8_WATER_MOUNT: return 15;
        case SPELL_ATTR8_UNK16: return 16;
        case SPELL_ATTR8_UNK17: return 17;
        case SPELL_ATTR8_REMEMBER_SPELLS: return 18;
        case SPELL_ATTR8_USE_COMBO_POINTS_ON_ANY_TARGET: return 19;
        case SPELL_ATTR8_ARMOR_SPECIALIZATION: return 20;
        case SPELL_ATTR8_UNK21: return 21;
        case SPELL_ATTR8_UNK22: return 22;
        case SPELL_ATTR8_BATTLE_RESURRECTION: return 23;
        case SPELL_ATTR8_HEALING_SPELL: return 24;
        case SPELL_ATTR8_UNK25: return 25;
        case SPELL_ATTR8_RAID_MARKER: return 26;
        case SPELL_ATTR8_UNK27: return 27;
        case SPELL_ATTR8_NOT_IN_BG_OR_ARENA: return 28;
        case SPELL_ATTR8_MASTERY_AFFECTS_POINTS: return 29;
        case SPELL_ATTR8_UNK30: return 30;
        case SPELL_ATTR8_ATTACK_IGNORE_IMMUNE_TO_PC_FLAG: return 31;
        default: throw std::out_of_range("value");
    }
}

/******************************************************************\
|* data for enum 'SpellAttr9' in 'SharedDefines.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr9>::ToString(SpellAttr9 value)
{
    switch (value)
    {
        case SPELL_ATTR9_UNK0: return { "SPELL_ATTR9_UNK0", "Unknown attribute 0@Attr9", "" };
        case SPELL_ATTR9_UNK1: return { "SPELL_ATTR9_UNK1", "Unknown attribute 1@Attr9", "" };
        case SPELL_ATTR9_RESTRICTED_FLIGHT_AREA: return { "SPELL_ATTR9_RESTRICTED_FLIGHT_AREA", "Only When Illegally Mounted", "" };
        case SPELL_ATTR9_UNK3: return { "SPELL_ATTR9_UNK3", "Unknown attribute 3@Attr9", "" };
        case SPELL_ATTR9_SPECIAL_DELAY_CALCULATION: return { "SPELL_ATTR9_SPECIAL_DELAY_CALCULATION", "Missile Speed is Delay (in sec)", "" };
        case SPELL_ATTR9_SUMMON_PLAYER_TOTEM: return { "SPELL_ATTR9_SUMMON_PLAYER_TOTEM", "Ignore Totem Requirements for Casting", "" };
        case SPELL_ATTR9_UNK6: return { "SPELL_ATTR9_UNK6", "Unknown attribute 6@Attr9", "" };
        case SPELL_ATTR9_UNK7: return { "SPELL_ATTR9_UNK7", "Unknown attribute 7@Attr9", "" };
        case SPELL_ATTR9_AIMED_SHOT: return { "SPELL_ATTR9_AIMED_SHOT", "Cooldown Ignores Ranged Weapon", "" };
        case SPELL_ATTR9_NOT_USABLE_IN_ARENA: return { "SPELL_ATTR9_NOT_USABLE_IN_ARENA", "Not In Arena", "" };
        case SPELL_ATTR9_UNK10: return { "SPELL_ATTR9_UNK10", "Unknown attribute 10@Attr9", "" };
        case SPELL_ATTR9_UNK11: return { "SPELL_ATTR9_UNK11", "Unknown attribute 11@Attr9", "" };
        case SPELL_ATTR9_UNK12: return { "SPELL_ATTR9_UNK12", "Unknown attribute 12@Attr9", "" };
        case SPELL_ATTR9_SLAM: return { "SPELL_ATTR9_SLAM", "Haste Affects Melee Ability Casttime", "" };
        case SPELL_ATTR9_USABLE_IN_RATED_BATTLEGROUNDS: return { "SPELL_ATTR9_USABLE_IN_RATED_BATTLEGROUNDS", "Ignore Default Rated Battleground Restrictions", "" };
        case SPELL_ATTR9_UNK15: return { "SPELL_ATTR9_UNK15", "Unknown attribute 15@Attr9", "" };
        case SPELL_ATTR9_UNK16: return { "SPELL_ATTR9_UNK16", "Unknown attribute 16@Attr9", "" };
        case SPELL_ATTR9_UNK17: return { "SPELL_ATTR9_UNK17", "Unknown attribute 17@Attr9", "" };
        case SPELL_ATTR9_UNK18: return { "SPELL_ATTR9_UNK18", "Unknown attribute 18@Attr9", "" };
        case SPELL_ATTR9_UNK19: return { "SPELL_ATTR9_UNK19", "Unknown attribute 19@Attr9", "" };
        case SPELL_ATTR9_UNK20: return { "SPELL_ATTR9_UNK20", "Unknown attribute 20@Attr9", "" };
        case SPELL_ATTR9_UNK21: return { "SPELL_ATTR9_UNK21", "Unknown attribute 21@Attr9", "" };
        case SPELL_ATTR9_UNK22: return { "SPELL_ATTR9_UNK22", "Unknown attribute 22@Attr9", "" };
        case SPELL_ATTR9_UNK23: return { "SPELL_ATTR9_UNK23", "Unknown attribute 23@Attr9", "" };
        case SPELL_ATTR9_UNK24: return { "SPELL_ATTR9_UNK24", "Unknown attribute 24@Attr9", "" };
        case SPELL_ATTR9_UNK25: return { "SPELL_ATTR9_UNK25", "Unknown attribute 25@Attr9", "" };
        case SPELL_ATTR9_UNK26: return { "SPELL_ATTR9_UNK26", "Unknown attribute 26@Attr9", "" };
        case SPELL_ATTR9_UNK27: return { "SPELL_ATTR9_UNK27", "Unknown attribute 27@Attr9", "" };
        case SPELL_ATTR9_UNK28: return { "SPELL_ATTR9_UNK28", "Unknown attribute 28@Attr9", "" };
        case SPELL_ATTR9_UNK29: return { "SPELL_ATTR9_UNK29", "Unknown attribute 29@Attr9", "" };
        case SPELL_ATTR9_UNK30: return { "SPELL_ATTR9_UNK30", "Unknown attribute 30@Attr9", "" };
        case SPELL_ATTR9_UNK31: return { "SPELL_ATTR9_UNK31", "Unknown attribute 31@Attr9", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr9>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr9 EnumUtils<SpellAttr9>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR9_UNK0;
        case 1: return SPELL_ATTR9_UNK1;
        case 2: return SPELL_ATTR9_RESTRICTED_FLIGHT_AREA;
        case 3: return SPELL_ATTR9_UNK3;
        case 4: return SPELL_ATTR9_SPECIAL_DELAY_CALCULATION;
        case 5: return SPELL_ATTR9_SUMMON_PLAYER_TOTEM;
        case 6: return SPELL_ATTR9_UNK6;
        case 7: return SPELL_ATTR9_UNK7;
        case 8: return SPELL_ATTR9_AIMED_SHOT;
        case 9: return SPELL_ATTR9_NOT_USABLE_IN_ARENA;
        case 10: return SPELL_ATTR9_UNK10;
        case 11: return SPELL_ATTR9_UNK11;
        case 12: return SPELL_ATTR9_UNK12;
        case 13: return SPELL_ATTR9_SLAM;
        case 14: return SPELL_ATTR9_USABLE_IN_RATED_BATTLEGROUNDS;
        case 15: return SPELL_ATTR9_UNK15;
        case 16: return SPELL_ATTR9_UNK16;
        case 17: return SPELL_ATTR9_UNK17;
        case 18: return SPELL_ATTR9_UNK18;
        case 19: return SPELL_ATTR9_UNK19;
        case 20: return SPELL_ATTR9_UNK20;
        case 21: return SPELL_ATTR9_UNK21;
        case 22: return SPELL_ATTR9_UNK22;
        case 23: return SPELL_ATTR9_UNK23;
        case 24: return SPELL_ATTR9_UNK24;
        case 25: return SPELL_ATTR9_UNK25;
        case 26: return SPELL_ATTR9_UNK26;
        case 27: return SPELL_ATTR9_UNK27;
        case 28: return SPELL_ATTR9_UNK28;
        case 29: return SPELL_ATTR9_UNK29;
        case 30: return SPELL_ATTR9_UNK30;
        case 31: return SPELL_ATTR9_UNK31;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr9>::ToIndex(SpellAttr9 value)
{
    switch (value)
    {
        case SPELL_ATTR9_UNK0: return 0;
        case SPELL_ATTR9_UNK1: return 1;
        case SPELL_ATTR9_RESTRICTED_FLIGHT_AREA: return 2;
        case SPELL_ATTR9_UNK3: return 3;
        case SPELL_ATTR9_SPECIAL_DELAY_CALCULATION: return 4;
        case SPELL_ATTR9_SUMMON_PLAYER_TOTEM: return 5;
        case SPELL_ATTR9_UNK6: return 6;
        case SPELL_ATTR9_UNK7: return 7;
        case SPELL_ATTR9_AIMED_SHOT: return 8;
        case SPELL_ATTR9_NOT_USABLE_IN_ARENA: return 9;
        case SPELL_ATTR9_UNK10: return 10;
        case SPELL_ATTR9_UNK11: return 11;
        case SPELL_ATTR9_UNK12: return 12;
        case SPELL_ATTR9_SLAM: return 13;
        case SPELL_ATTR9_USABLE_IN_RATED_BATTLEGROUNDS: return 14;
        case SPELL_ATTR9_UNK15: return 15;
        case SPELL_ATTR9_UNK16: return 16;
        case SPELL_ATTR9_UNK17: return 17;
        case SPELL_ATTR9_UNK18: return 18;
        case SPELL_ATTR9_UNK19: return 19;
        case SPELL_ATTR9_UNK20: return 20;
        case SPELL_ATTR9_UNK21: return 21;
        case SPELL_ATTR9_UNK22: return 22;
        case SPELL_ATTR9_UNK23: return 23;
        case SPELL_ATTR9_UNK24: return 24;
        case SPELL_ATTR9_UNK25: return 25;
        case SPELL_ATTR9_UNK26: return 26;
        case SPELL_ATTR9_UNK27: return 27;
        case SPELL_ATTR9_UNK28: return 28;
        case SPELL_ATTR9_UNK29: return 29;
        case SPELL_ATTR9_UNK30: return 30;
        case SPELL_ATTR9_UNK31: return 31;
        default: throw std::out_of_range("value");
    }
}

/*******************************************************************\
|* data for enum 'SpellAttr10' in 'SharedDefines.h' auto-generated *|
\*******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr10>::ToString(SpellAttr10 value)
{
    switch (value)
    {
        case SPELL_ATTR10_UNK0: return { "SPELL_ATTR10_UNK0", "Unknown attribute 0@Attr10", "" };
        case SPELL_ATTR10_UNK1: return { "SPELL_ATTR10_UNK1", "Unknown attribute 1@Attr10", "" };
        case SPELL_ATTR10_USES_RANGED_SLOT_COSMETIC_ONLY: return { "SPELL_ATTR10_USES_RANGED_SLOT_COSMETIC_ONLY", "Uses Ranged Slot (Cosmetic Only)", "" };
        case SPELL_ATTR10_UNK3: return { "SPELL_ATTR10_UNK3", "Unknown attribute 3@Attr10", "" };
        case SPELL_ATTR10_WATER_SPOUT: return { "SPELL_ATTR10_WATER_SPOUT", "NPC Knockback - ignore doors", "" };
        case SPELL_ATTR10_UNK5: return { "SPELL_ATTR10_UNK5", "Unknown attribute 5@Attr10", "" };
        case SPELL_ATTR10_UNK6: return { "SPELL_ATTR10_UNK6", "Unknown attribute 6@Attr10", "" };
        case SPELL_ATTR10_TELEPORT_PLAYER: return { "SPELL_ATTR10_TELEPORT_PLAYER", "Ignore instance lock and farm limit on teleport", "" };
        case SPELL_ATTR10_UNK8: return { "SPELL_ATTR10_UNK8", "Unknown attribute 8@Attr10", "" };
        case SPELL_ATTR10_UNK9: return { "SPELL_ATTR10_UNK9", "Unknown attribute 9@Attr10", "" };
        case SPELL_ATTR10_UNK10: return { "SPELL_ATTR10_UNK10", "Unknown attribute 10@Attr10", "" };
        case SPELL_ATTR10_HERB_GATHERING_MINING: return { "SPELL_ATTR10_HERB_GATHERING_MINING", "Lock chest at precast", "" };
        case SPELL_ATTR10_USE_SPELL_BASE_LEVEL_FOR_SCALING: return { "SPELL_ATTR10_USE_SPELL_BASE_LEVEL_FOR_SCALING", "Use Spell Base Level For Scaling", "" };
        case SPELL_ATTR10_RESET_COOLDOWN_ON_ENCOUNTER_END: return { "SPELL_ATTR10_RESET_COOLDOWN_ON_ENCOUNTER_END", "Reset cooldown upon ending an encounter", "" };
        case SPELL_ATTR10_ROLLING_PERIODIC: return { "SPELL_ATTR10_ROLLING_PERIODIC", "Rolling Periodic", "Add remaining periodic damage to new aura when refreshed" };
        case SPELL_ATTR10_UNK15: return { "SPELL_ATTR10_UNK15", "Unknown attribute 15@Attr10", "" };
        case SPELL_ATTR10_UNK16: return { "SPELL_ATTR10_UNK16", "Unknown attribute 16@Attr10", "" };
        case SPELL_ATTR10_CAN_DODGE_PARRY_WHILE_CASTING: return { "SPELL_ATTR10_CAN_DODGE_PARRY_WHILE_CASTING", "Allow Defense While Casting", "" };
        case SPELL_ATTR10_UNK18: return { "SPELL_ATTR10_UNK18", "Unknown attribute 18@Attr10", "" };
        case SPELL_ATTR10_UNK19: return { "SPELL_ATTR10_UNK19", "Unknown attribute 19@Attr10", "" };
        case SPELL_ATTR10_UNK20: return { "SPELL_ATTR10_UNK20", "Unknown attribute 20@Attr10", "" };
        case SPELL_ATTR10_UNK21: return { "SPELL_ATTR10_UNK21", "Unknown attribute 21@Attr10", "" };
        case SPELL_ATTR10_UNK22: return { "SPELL_ATTR10_UNK22", "Unknown attribute 22@Attr10", "" };
        case SPELL_ATTR10_UNK23: return { "SPELL_ATTR10_UNK23", "Unknown attribute 23@Attr10", "" };
        case SPELL_ATTR10_UNK24: return { "SPELL_ATTR10_UNK24", "Unknown attribute 24@Attr10", "" };
        case SPELL_ATTR10_UNK25: return { "SPELL_ATTR10_UNK25", "Unknown attribute 25@Attr10", "" };
        case SPELL_ATTR10_UNK26: return { "SPELL_ATTR10_UNK26", "Unknown attribute 26@Attr10", "" };
        case SPELL_ATTR10_UNK27: return { "SPELL_ATTR10_UNK27", "Unknown attribute 27@Attr10", "" };
        case SPELL_ATTR10_UNK28: return { "SPELL_ATTR10_UNK28", "Unknown attribute 28@Attr10", "" };
        case SPELL_ATTR10_MOUNT_IS_NOT_ACCOUNT_WIDE: return { "SPELL_ATTR10_MOUNT_IS_NOT_ACCOUNT_WIDE", "This Mount is NOT at the account level", "" };
        case SPELL_ATTR10_UNK30: return { "SPELL_ATTR10_UNK30", "Unknown attribute 30@Attr10", "" };
        case SPELL_ATTR10_UNK31: return { "SPELL_ATTR10_UNK31", "Unknown attribute 31@Attr10", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr10>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr10 EnumUtils<SpellAttr10>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR10_UNK0;
        case 1: return SPELL_ATTR10_UNK1;
        case 2: return SPELL_ATTR10_USES_RANGED_SLOT_COSMETIC_ONLY;
        case 3: return SPELL_ATTR10_UNK3;
        case 4: return SPELL_ATTR10_WATER_SPOUT;
        case 5: return SPELL_ATTR10_UNK5;
        case 6: return SPELL_ATTR10_UNK6;
        case 7: return SPELL_ATTR10_TELEPORT_PLAYER;
        case 8: return SPELL_ATTR10_UNK8;
        case 9: return SPELL_ATTR10_UNK9;
        case 10: return SPELL_ATTR10_UNK10;
        case 11: return SPELL_ATTR10_HERB_GATHERING_MINING;
        case 12: return SPELL_ATTR10_USE_SPELL_BASE_LEVEL_FOR_SCALING;
        case 13: return SPELL_ATTR10_RESET_COOLDOWN_ON_ENCOUNTER_END;
        case 14: return SPELL_ATTR10_ROLLING_PERIODIC;
        case 15: return SPELL_ATTR10_UNK15;
        case 16: return SPELL_ATTR10_UNK16;
        case 17: return SPELL_ATTR10_CAN_DODGE_PARRY_WHILE_CASTING;
        case 18: return SPELL_ATTR10_UNK18;
        case 19: return SPELL_ATTR10_UNK19;
        case 20: return SPELL_ATTR10_UNK20;
        case 21: return SPELL_ATTR10_UNK21;
        case 22: return SPELL_ATTR10_UNK22;
        case 23: return SPELL_ATTR10_UNK23;
        case 24: return SPELL_ATTR10_UNK24;
        case 25: return SPELL_ATTR10_UNK25;
        case 26: return SPELL_ATTR10_UNK26;
        case 27: return SPELL_ATTR10_UNK27;
        case 28: return SPELL_ATTR10_UNK28;
        case 29: return SPELL_ATTR10_MOUNT_IS_NOT_ACCOUNT_WIDE;
        case 30: return SPELL_ATTR10_UNK30;
        case 31: return SPELL_ATTR10_UNK31;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr10>::ToIndex(SpellAttr10 value)
{
    switch (value)
    {
        case SPELL_ATTR10_UNK0: return 0;
        case SPELL_ATTR10_UNK1: return 1;
        case SPELL_ATTR10_USES_RANGED_SLOT_COSMETIC_ONLY: return 2;
        case SPELL_ATTR10_UNK3: return 3;
        case SPELL_ATTR10_WATER_SPOUT: return 4;
        case SPELL_ATTR10_UNK5: return 5;
        case SPELL_ATTR10_UNK6: return 6;
        case SPELL_ATTR10_TELEPORT_PLAYER: return 7;
        case SPELL_ATTR10_UNK8: return 8;
        case SPELL_ATTR10_UNK9: return 9;
        case SPELL_ATTR10_UNK10: return 10;
        case SPELL_ATTR10_HERB_GATHERING_MINING: return 11;
        case SPELL_ATTR10_USE_SPELL_BASE_LEVEL_FOR_SCALING: return 12;
        case SPELL_ATTR10_RESET_COOLDOWN_ON_ENCOUNTER_END: return 13;
        case SPELL_ATTR10_ROLLING_PERIODIC: return 14;
        case SPELL_ATTR10_UNK15: return 15;
        case SPELL_ATTR10_UNK16: return 16;
        case SPELL_ATTR10_CAN_DODGE_PARRY_WHILE_CASTING: return 17;
        case SPELL_ATTR10_UNK18: return 18;
        case SPELL_ATTR10_UNK19: return 19;
        case SPELL_ATTR10_UNK20: return 20;
        case SPELL_ATTR10_UNK21: return 21;
        case SPELL_ATTR10_UNK22: return 22;
        case SPELL_ATTR10_UNK23: return 23;
        case SPELL_ATTR10_UNK24: return 24;
        case SPELL_ATTR10_UNK25: return 25;
        case SPELL_ATTR10_UNK26: return 26;
        case SPELL_ATTR10_UNK27: return 27;
        case SPELL_ATTR10_UNK28: return 28;
        case SPELL_ATTR10_MOUNT_IS_NOT_ACCOUNT_WIDE: return 29;
        case SPELL_ATTR10_UNK30: return 30;
        case SPELL_ATTR10_UNK31: return 31;
        default: throw std::out_of_range("value");
    }
}

/*******************************************************************\
|* data for enum 'SpellAttr11' in 'SharedDefines.h' auto-generated *|
\*******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr11>::ToString(SpellAttr11 value)
{
    switch (value)
    {
        case SPELL_ATTR11_UNK0: return { "SPELL_ATTR11_UNK0", "Unknown attribute 0@Attr11", "" };
        case SPELL_ATTR11_UNK1: return { "SPELL_ATTR11_UNK1", "Unknown attribute 1@Attr11", "" };
        case SPELL_ATTR11_SCALES_WITH_ITEM_LEVEL: return { "SPELL_ATTR11_SCALES_WITH_ITEM_LEVEL", "Scales with Casting Item's Level", "" };
        case SPELL_ATTR11_UNK3: return { "SPELL_ATTR11_UNK3", "Unknown attribute 3@Attr11", "" };
        case SPELL_ATTR11_UNK4: return { "SPELL_ATTR11_UNK4", "Unknown attribute 4@Attr11", "" };
        case SPELL_ATTR11_ABSORB_ENVIRONMENTAL_DAMAGE: return { "SPELL_ATTR11_ABSORB_ENVIRONMENTAL_DAMAGE", "Absorb Falling Damage", "" };
        case SPELL_ATTR11_UNK6: return { "SPELL_ATTR11_UNK6", "Unknown attribute 6@Attr11", "" };
        case SPELL_ATTR11_RANK_IGNORES_CASTER_LEVEL: return { "SPELL_ATTR11_RANK_IGNORES_CASTER_LEVEL", "Ignore Caster's spell level", "Spell_C_GetSpellRank returns SpellLevels->MaxLevel * 5 instead of std::min(SpellLevels->MaxLevel, caster->Level) * 5" };
        case SPELL_ATTR11_UNK8: return { "SPELL_ATTR11_UNK8", "Unknown attribute 8@Attr11", "" };
        case SPELL_ATTR11_UNK9: return { "SPELL_ATTR11_UNK9", "Unknown attribute 9@Attr11", "" };
        case SPELL_ATTR11_UNK10: return { "SPELL_ATTR11_UNK10", "Unknown attribute 10@Attr11", "" };
        case SPELL_ATTR11_NOT_USABLE_IN_INSTANCES: return { "SPELL_ATTR11_NOT_USABLE_IN_INSTANCES", "Not in Instances", "" };
        case SPELL_ATTR11_UNK12: return { "SPELL_ATTR11_UNK12", "Unknown attribute 12@Attr11", "" };
        case SPELL_ATTR11_UNK13: return { "SPELL_ATTR11_UNK13", "Unknown attribute 13@Attr11", "" };
        case SPELL_ATTR11_UNK14: return { "SPELL_ATTR11_UNK14", "Unknown attribute 14@Attr11", "" };
        case SPELL_ATTR11_UNK15: return { "SPELL_ATTR11_UNK15", "Unknown attribute 15@Attr11", "" };
        case SPELL_ATTR11_NOT_USABLE_IN_CHALLENGE_MODE: return { "SPELL_ATTR11_NOT_USABLE_IN_CHALLENGE_MODE", "Not in Mythic+ Mode (Challenge Mode)", "" };
        case SPELL_ATTR11_UNK17: return { "SPELL_ATTR11_UNK17", "Unknown attribute 17@Attr11", "" };
        case SPELL_ATTR11_UNK18: return { "SPELL_ATTR11_UNK18", "Unknown attribute 18@Attr11", "" };
        case SPELL_ATTR11_UNK19: return { "SPELL_ATTR11_UNK19", "Unknown attribute 19@Attr11", "" };
        case SPELL_ATTR11_UNK20: return { "SPELL_ATTR11_UNK20", "Unknown attribute 20@Attr11", "" };
        case SPELL_ATTR11_UNK21: return { "SPELL_ATTR11_UNK21", "Unknown attribute 21@Attr11", "" };
        case SPELL_ATTR11_UNK22: return { "SPELL_ATTR11_UNK22", "Unknown attribute 22@Attr11", "" };
        case SPELL_ATTR11_UNK23: return { "SPELL_ATTR11_UNK23", "Unknown attribute 23@Attr11", "" };
        case SPELL_ATTR11_UNK24: return { "SPELL_ATTR11_UNK24", "Unknown attribute 24@Attr11", "" };
        case SPELL_ATTR11_UNK25: return { "SPELL_ATTR11_UNK25", "Unknown attribute 25@Attr11", "" };
        case SPELL_ATTR11_UNK26: return { "SPELL_ATTR11_UNK26", "Unknown attribute 26@Attr11", "" };
        case SPELL_ATTR11_UNK27: return { "SPELL_ATTR11_UNK27", "Unknown attribute 27@Attr11", "" };
        case SPELL_ATTR11_UNK28: return { "SPELL_ATTR11_UNK28", "Unknown attribute 28@Attr11", "" };
        case SPELL_ATTR11_UNK29: return { "SPELL_ATTR11_UNK29", "Unknown attribute 29@Attr11", "" };
        case SPELL_ATTR11_UNK30: return { "SPELL_ATTR11_UNK30", "Unknown attribute 30@Attr11", "" };
        case SPELL_ATTR11_UNK31: return { "SPELL_ATTR11_UNK31", "Unknown attribute 31@Attr11", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr11>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr11 EnumUtils<SpellAttr11>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR11_UNK0;
        case 1: return SPELL_ATTR11_UNK1;
        case 2: return SPELL_ATTR11_SCALES_WITH_ITEM_LEVEL;
        case 3: return SPELL_ATTR11_UNK3;
        case 4: return SPELL_ATTR11_UNK4;
        case 5: return SPELL_ATTR11_ABSORB_ENVIRONMENTAL_DAMAGE;
        case 6: return SPELL_ATTR11_UNK6;
        case 7: return SPELL_ATTR11_RANK_IGNORES_CASTER_LEVEL;
        case 8: return SPELL_ATTR11_UNK8;
        case 9: return SPELL_ATTR11_UNK9;
        case 10: return SPELL_ATTR11_UNK10;
        case 11: return SPELL_ATTR11_NOT_USABLE_IN_INSTANCES;
        case 12: return SPELL_ATTR11_UNK12;
        case 13: return SPELL_ATTR11_UNK13;
        case 14: return SPELL_ATTR11_UNK14;
        case 15: return SPELL_ATTR11_UNK15;
        case 16: return SPELL_ATTR11_NOT_USABLE_IN_CHALLENGE_MODE;
        case 17: return SPELL_ATTR11_UNK17;
        case 18: return SPELL_ATTR11_UNK18;
        case 19: return SPELL_ATTR11_UNK19;
        case 20: return SPELL_ATTR11_UNK20;
        case 21: return SPELL_ATTR11_UNK21;
        case 22: return SPELL_ATTR11_UNK22;
        case 23: return SPELL_ATTR11_UNK23;
        case 24: return SPELL_ATTR11_UNK24;
        case 25: return SPELL_ATTR11_UNK25;
        case 26: return SPELL_ATTR11_UNK26;
        case 27: return SPELL_ATTR11_UNK27;
        case 28: return SPELL_ATTR11_UNK28;
        case 29: return SPELL_ATTR11_UNK29;
        case 30: return SPELL_ATTR11_UNK30;
        case 31: return SPELL_ATTR11_UNK31;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr11>::ToIndex(SpellAttr11 value)
{
    switch (value)
    {
        case SPELL_ATTR11_UNK0: return 0;
        case SPELL_ATTR11_UNK1: return 1;
        case SPELL_ATTR11_SCALES_WITH_ITEM_LEVEL: return 2;
        case SPELL_ATTR11_UNK3: return 3;
        case SPELL_ATTR11_UNK4: return 4;
        case SPELL_ATTR11_ABSORB_ENVIRONMENTAL_DAMAGE: return 5;
        case SPELL_ATTR11_UNK6: return 6;
        case SPELL_ATTR11_RANK_IGNORES_CASTER_LEVEL: return 7;
        case SPELL_ATTR11_UNK8: return 8;
        case SPELL_ATTR11_UNK9: return 9;
        case SPELL_ATTR11_UNK10: return 10;
        case SPELL_ATTR11_NOT_USABLE_IN_INSTANCES: return 11;
        case SPELL_ATTR11_UNK12: return 12;
        case SPELL_ATTR11_UNK13: return 13;
        case SPELL_ATTR11_UNK14: return 14;
        case SPELL_ATTR11_UNK15: return 15;
        case SPELL_ATTR11_NOT_USABLE_IN_CHALLENGE_MODE: return 16;
        case SPELL_ATTR11_UNK17: return 17;
        case SPELL_ATTR11_UNK18: return 18;
        case SPELL_ATTR11_UNK19: return 19;
        case SPELL_ATTR11_UNK20: return 20;
        case SPELL_ATTR11_UNK21: return 21;
        case SPELL_ATTR11_UNK22: return 22;
        case SPELL_ATTR11_UNK23: return 23;
        case SPELL_ATTR11_UNK24: return 24;
        case SPELL_ATTR11_UNK25: return 25;
        case SPELL_ATTR11_UNK26: return 26;
        case SPELL_ATTR11_UNK27: return 27;
        case SPELL_ATTR11_UNK28: return 28;
        case SPELL_ATTR11_UNK29: return 29;
        case SPELL_ATTR11_UNK30: return 30;
        case SPELL_ATTR11_UNK31: return 31;
        default: throw std::out_of_range("value");
    }
}

/*******************************************************************\
|* data for enum 'SpellAttr12' in 'SharedDefines.h' auto-generated *|
\*******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr12>::ToString(SpellAttr12 value)
{
    switch (value)
    {
        case SPELL_ATTR12_UNK0: return { "SPELL_ATTR12_UNK0", "Unknown attribute 0@Attr12", "" };
        case SPELL_ATTR12_UNK1: return { "SPELL_ATTR12_UNK1", "Unknown attribute 1@Attr12", "" };
        case SPELL_ATTR12_UNK2: return { "SPELL_ATTR12_UNK2", "Unknown attribute 2@Attr12", "" };
        case SPELL_ATTR12_UNK3: return { "SPELL_ATTR12_UNK3", "Unknown attribute 3@Attr12", "" };
        case SPELL_ATTR12_UNK4: return { "SPELL_ATTR12_UNK4", "Unknown attribute 4@Attr12", "" };
        case SPELL_ATTR12_UNK5: return { "SPELL_ATTR12_UNK5", "Unknown attribute 5@Attr12", "" };
        case SPELL_ATTR12_UNK6: return { "SPELL_ATTR12_UNK6", "Unknown attribute 6@Attr12", "" };
        case SPELL_ATTR12_UNK7: return { "SPELL_ATTR12_UNK7", "Unknown attribute 7@Attr12", "" };
        case SPELL_ATTR12_UNK8: return { "SPELL_ATTR12_UNK8", "Unknown attribute 8@Attr12", "" };
        case SPELL_ATTR12_IGNORE_CASTING_DISABLED: return { "SPELL_ATTR12_IGNORE_CASTING_DISABLED", "Active Passive", "Ignores aura 263 SPELL_AURA_DISABLE_CASTING_EXCEPT_ABILITIES" };
        case SPELL_ATTR12_UNK10: return { "SPELL_ATTR12_UNK10", "Unknown attribute 10@Attr12", "" };
        case SPELL_ATTR12_UNK11: return { "SPELL_ATTR12_UNK11", "Unknown attribute 11@Attr12", "" };
        case SPELL_ATTR12_UNK12: return { "SPELL_ATTR12_UNK12", "Unknown attribute 12@Attr12", "" };
        case SPELL_ATTR12_UNK13: return { "SPELL_ATTR12_UNK13", "Unknown attribute 13@Attr12", "" };
        case SPELL_ATTR12_UNK14: return { "SPELL_ATTR12_UNK14", "Unknown attribute 14@Attr12", "" };
        case SPELL_ATTR12_UNK15: return { "SPELL_ATTR12_UNK15", "Unknown attribute 15@Attr12", "" };
        case SPELL_ATTR12_UNK16: return { "SPELL_ATTR12_UNK16", "Unknown attribute 16@Attr12", "" };
        case SPELL_ATTR12_UNK17: return { "SPELL_ATTR12_UNK17", "Unknown attribute 17@Attr12", "" };
        case SPELL_ATTR12_UNK18: return { "SPELL_ATTR12_UNK18", "Unknown attribute 18@Attr12", "" };
        case SPELL_ATTR12_UNK19: return { "SPELL_ATTR12_UNK19", "Unknown attribute 19@Attr12", "" };
        case SPELL_ATTR12_UNK20: return { "SPELL_ATTR12_UNK20", "Unknown attribute 20@Attr12", "" };
        case SPELL_ATTR12_UNK21: return { "SPELL_ATTR12_UNK21", "Unknown attribute 21@Attr12", "" };
        case SPELL_ATTR12_UNK22: return { "SPELL_ATTR12_UNK22", "Unknown attribute 22@Attr12", "" };
        case SPELL_ATTR12_START_COOLDOWN_ON_CAST_START: return { "SPELL_ATTR12_START_COOLDOWN_ON_CAST_START", "Trigger Cooldown On Spell Start", "" };
        case SPELL_ATTR12_IS_GARRISON_BUFF: return { "SPELL_ATTR12_IS_GARRISON_BUFF", "Never Learn", "" };
        case SPELL_ATTR12_UNK25: return { "SPELL_ATTR12_UNK25", "Unknown attribute 25@Attr12", "" };
        case SPELL_ATTR12_UNK26: return { "SPELL_ATTR12_UNK26", "Unknown attribute 26@Attr12", "" };
        case SPELL_ATTR12_IS_READINESS_SPELL: return { "SPELL_ATTR12_IS_READINESS_SPELL", "Recompute Aura on Mercenary Mode", "" };
        case SPELL_ATTR12_UNK28: return { "SPELL_ATTR12_UNK28", "Unknown attribute 28@Attr12", "" };
        case SPELL_ATTR12_UNK29: return { "SPELL_ATTR12_UNK29", "Unknown attribute 29@Attr12", "" };
        case SPELL_ATTR12_UNK30: return { "SPELL_ATTR12_UNK30", "Unknown attribute 30@Attr12", "" };
        case SPELL_ATTR12_UNK31: return { "SPELL_ATTR12_UNK31", "Unknown attribute 31@Attr12", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr12>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr12 EnumUtils<SpellAttr12>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR12_UNK0;
        case 1: return SPELL_ATTR12_UNK1;
        case 2: return SPELL_ATTR12_UNK2;
        case 3: return SPELL_ATTR12_UNK3;
        case 4: return SPELL_ATTR12_UNK4;
        case 5: return SPELL_ATTR12_UNK5;
        case 6: return SPELL_ATTR12_UNK6;
        case 7: return SPELL_ATTR12_UNK7;
        case 8: return SPELL_ATTR12_UNK8;
        case 9: return SPELL_ATTR12_IGNORE_CASTING_DISABLED;
        case 10: return SPELL_ATTR12_UNK10;
        case 11: return SPELL_ATTR12_UNK11;
        case 12: return SPELL_ATTR12_UNK12;
        case 13: return SPELL_ATTR12_UNK13;
        case 14: return SPELL_ATTR12_UNK14;
        case 15: return SPELL_ATTR12_UNK15;
        case 16: return SPELL_ATTR12_UNK16;
        case 17: return SPELL_ATTR12_UNK17;
        case 18: return SPELL_ATTR12_UNK18;
        case 19: return SPELL_ATTR12_UNK19;
        case 20: return SPELL_ATTR12_UNK20;
        case 21: return SPELL_ATTR12_UNK21;
        case 22: return SPELL_ATTR12_UNK22;
        case 23: return SPELL_ATTR12_START_COOLDOWN_ON_CAST_START;
        case 24: return SPELL_ATTR12_IS_GARRISON_BUFF;
        case 25: return SPELL_ATTR12_UNK25;
        case 26: return SPELL_ATTR12_UNK26;
        case 27: return SPELL_ATTR12_IS_READINESS_SPELL;
        case 28: return SPELL_ATTR12_UNK28;
        case 29: return SPELL_ATTR12_UNK29;
        case 30: return SPELL_ATTR12_UNK30;
        case 31: return SPELL_ATTR12_UNK31;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr12>::ToIndex(SpellAttr12 value)
{
    switch (value)
    {
        case SPELL_ATTR12_UNK0: return 0;
        case SPELL_ATTR12_UNK1: return 1;
        case SPELL_ATTR12_UNK2: return 2;
        case SPELL_ATTR12_UNK3: return 3;
        case SPELL_ATTR12_UNK4: return 4;
        case SPELL_ATTR12_UNK5: return 5;
        case SPELL_ATTR12_UNK6: return 6;
        case SPELL_ATTR12_UNK7: return 7;
        case SPELL_ATTR12_UNK8: return 8;
        case SPELL_ATTR12_IGNORE_CASTING_DISABLED: return 9;
        case SPELL_ATTR12_UNK10: return 10;
        case SPELL_ATTR12_UNK11: return 11;
        case SPELL_ATTR12_UNK12: return 12;
        case SPELL_ATTR12_UNK13: return 13;
        case SPELL_ATTR12_UNK14: return 14;
        case SPELL_ATTR12_UNK15: return 15;
        case SPELL_ATTR12_UNK16: return 16;
        case SPELL_ATTR12_UNK17: return 17;
        case SPELL_ATTR12_UNK18: return 18;
        case SPELL_ATTR12_UNK19: return 19;
        case SPELL_ATTR12_UNK20: return 20;
        case SPELL_ATTR12_UNK21: return 21;
        case SPELL_ATTR12_UNK22: return 22;
        case SPELL_ATTR12_START_COOLDOWN_ON_CAST_START: return 23;
        case SPELL_ATTR12_IS_GARRISON_BUFF: return 24;
        case SPELL_ATTR12_UNK25: return 25;
        case SPELL_ATTR12_UNK26: return 26;
        case SPELL_ATTR12_IS_READINESS_SPELL: return 27;
        case SPELL_ATTR12_UNK28: return 28;
        case SPELL_ATTR12_UNK29: return 29;
        case SPELL_ATTR12_UNK30: return 30;
        case SPELL_ATTR12_UNK31: return 31;
        default: throw std::out_of_range("value");
    }
}

/*******************************************************************\
|* data for enum 'SpellAttr13' in 'SharedDefines.h' auto-generated *|
\*******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr13>::ToString(SpellAttr13 value)
{
    switch (value)
    {
        case SPELL_ATTR13_UNK0: return { "SPELL_ATTR13_UNK0", "Unknown attribute 0@Attr13", "" };
        case SPELL_ATTR13_UNK1: return { "SPELL_ATTR13_UNK1", "Unknown attribute 0@Attr13", "" };
        case SPELL_ATTR13_PASSIVE_IS_UPGRADE: return { "SPELL_ATTR13_PASSIVE_IS_UPGRADE", "Is Upgrade", "Displays \042Upgrade\042 in spell tooltip instead of \042Passive\042" };
        case SPELL_ATTR13_UNK3: return { "SPELL_ATTR13_UNK3", "Unknown attribute 3@Attr13", "" };
        case SPELL_ATTR13_UNK4: return { "SPELL_ATTR13_UNK4", "Unknown attribute 4@Attr13", "" };
        case SPELL_ATTR13_UNK5: return { "SPELL_ATTR13_UNK5", "Unknown attribute 5@Attr13", "" };
        case SPELL_ATTR13_UNK6: return { "SPELL_ATTR13_UNK6", "Unknown attribute 6@Attr13", "" };
        case SPELL_ATTR13_UNK7: return { "SPELL_ATTR13_UNK7", "Unknown attribute 7@Attr13", "" };
        case SPELL_ATTR13_UNK8: return { "SPELL_ATTR13_UNK8", "Unknown attribute 8@Attr13", "" };
        case SPELL_ATTR13_UNK9: return { "SPELL_ATTR13_UNK9", "Unknown attribute 9@Attr13", "" };
        case SPELL_ATTR13_UNK10: return { "SPELL_ATTR13_UNK10", "Unknown attribute 10@Attr13", "" };
        case SPELL_ATTR13_UNK11: return { "SPELL_ATTR13_UNK11", "Unknown attribute 11@Attr13", "" };
        case SPELL_ATTR13_UNK12: return { "SPELL_ATTR13_UNK12", "Unknown attribute 12@Attr13", "" };
        case SPELL_ATTR13_UNK13: return { "SPELL_ATTR13_UNK13", "Unknown attribute 13@Attr13", "" };
        case SPELL_ATTR13_UNK14: return { "SPELL_ATTR13_UNK14", "Unknown attribute 14@Attr13", "" };
        case SPELL_ATTR13_UNK15: return { "SPELL_ATTR13_UNK15", "Unknown attribute 15@Attr13", "" };
        case SPELL_ATTR13_UNK16: return { "SPELL_ATTR13_UNK16", "Unknown attribute 16@Attr13", "" };
        case SPELL_ATTR13_UNK17: return { "SPELL_ATTR13_UNK17", "Unknown attribute 17@Attr13", "" };
        case SPELL_ATTR13_ACTIVATES_REQUIRED_SHAPESHIFT: return { "SPELL_ATTR13_ACTIVATES_REQUIRED_SHAPESHIFT", "Do Not Enforce Shapeshift Requirements", "" };
        case SPELL_ATTR13_UNK19: return { "SPELL_ATTR13_UNK19", "Unknown attribute 19@Attr13", "" };
        case SPELL_ATTR13_UNK20: return { "SPELL_ATTR13_UNK20", "Unknown attribute 20@Attr13", "" };
        case SPELL_ATTR13_UNK21: return { "SPELL_ATTR13_UNK21", "Unknown attribute 21@Attr13", "" };
        case SPELL_ATTR13_UNK22: return { "SPELL_ATTR13_UNK22", "Unknown attribute 22@Attr13", "" };
        case SPELL_ATTR13_UNK23: return { "SPELL_ATTR13_UNK23", "Unknown attribute 23@Attr13", "" };
        case SPELL_ATTR13_UNK24: return { "SPELL_ATTR13_UNK24", "Unknown attribute 24@Attr13", "" };
        case SPELL_ATTR13_UNK25: return { "SPELL_ATTR13_UNK25", "Unknown attribute 25@Attr13", "" };
        case SPELL_ATTR13_UNK26: return { "SPELL_ATTR13_UNK26", "Unknown attribute 26@Attr13", "" };
        case SPELL_ATTR13_UNK27: return { "SPELL_ATTR13_UNK27", "Unknown attribute 27@Attr13", "" };
        case SPELL_ATTR13_UNK28: return { "SPELL_ATTR13_UNK28", "Unknown attribute 28@Attr13", "" };
        case SPELL_ATTR13_UNK29: return { "SPELL_ATTR13_UNK29", "Unknown attribute 29@Attr13", "" };
        case SPELL_ATTR13_UNK30: return { "SPELL_ATTR13_UNK30", "Unknown attribute 30@Attr13", "" };
        case SPELL_ATTR13_UNK31: return { "SPELL_ATTR13_UNK31", "Unknown attribute 31@Attr13", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr13>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr13 EnumUtils<SpellAttr13>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR13_UNK0;
        case 1: return SPELL_ATTR13_UNK1;
        case 2: return SPELL_ATTR13_PASSIVE_IS_UPGRADE;
        case 3: return SPELL_ATTR13_UNK3;
        case 4: return SPELL_ATTR13_UNK4;
        case 5: return SPELL_ATTR13_UNK5;
        case 6: return SPELL_ATTR13_UNK6;
        case 7: return SPELL_ATTR13_UNK7;
        case 8: return SPELL_ATTR13_UNK8;
        case 9: return SPELL_ATTR13_UNK9;
        case 10: return SPELL_ATTR13_UNK10;
        case 11: return SPELL_ATTR13_UNK11;
        case 12: return SPELL_ATTR13_UNK12;
        case 13: return SPELL_ATTR13_UNK13;
        case 14: return SPELL_ATTR13_UNK14;
        case 15: return SPELL_ATTR13_UNK15;
        case 16: return SPELL_ATTR13_UNK16;
        case 17: return SPELL_ATTR13_UNK17;
        case 18: return SPELL_ATTR13_ACTIVATES_REQUIRED_SHAPESHIFT;
        case 19: return SPELL_ATTR13_UNK19;
        case 20: return SPELL_ATTR13_UNK20;
        case 21: return SPELL_ATTR13_UNK21;
        case 22: return SPELL_ATTR13_UNK22;
        case 23: return SPELL_ATTR13_UNK23;
        case 24: return SPELL_ATTR13_UNK24;
        case 25: return SPELL_ATTR13_UNK25;
        case 26: return SPELL_ATTR13_UNK26;
        case 27: return SPELL_ATTR13_UNK27;
        case 28: return SPELL_ATTR13_UNK28;
        case 29: return SPELL_ATTR13_UNK29;
        case 30: return SPELL_ATTR13_UNK30;
        case 31: return SPELL_ATTR13_UNK31;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr13>::ToIndex(SpellAttr13 value)
{
    switch (value)
    {
        case SPELL_ATTR13_UNK0: return 0;
        case SPELL_ATTR13_UNK1: return 1;
        case SPELL_ATTR13_PASSIVE_IS_UPGRADE: return 2;
        case SPELL_ATTR13_UNK3: return 3;
        case SPELL_ATTR13_UNK4: return 4;
        case SPELL_ATTR13_UNK5: return 5;
        case SPELL_ATTR13_UNK6: return 6;
        case SPELL_ATTR13_UNK7: return 7;
        case SPELL_ATTR13_UNK8: return 8;
        case SPELL_ATTR13_UNK9: return 9;
        case SPELL_ATTR13_UNK10: return 10;
        case SPELL_ATTR13_UNK11: return 11;
        case SPELL_ATTR13_UNK12: return 12;
        case SPELL_ATTR13_UNK13: return 13;
        case SPELL_ATTR13_UNK14: return 14;
        case SPELL_ATTR13_UNK15: return 15;
        case SPELL_ATTR13_UNK16: return 16;
        case SPELL_ATTR13_UNK17: return 17;
        case SPELL_ATTR13_ACTIVATES_REQUIRED_SHAPESHIFT: return 18;
        case SPELL_ATTR13_UNK19: return 19;
        case SPELL_ATTR13_UNK20: return 20;
        case SPELL_ATTR13_UNK21: return 21;
        case SPELL_ATTR13_UNK22: return 22;
        case SPELL_ATTR13_UNK23: return 23;
        case SPELL_ATTR13_UNK24: return 24;
        case SPELL_ATTR13_UNK25: return 25;
        case SPELL_ATTR13_UNK26: return 26;
        case SPELL_ATTR13_UNK27: return 27;
        case SPELL_ATTR13_UNK28: return 28;
        case SPELL_ATTR13_UNK29: return 29;
        case SPELL_ATTR13_UNK30: return 30;
        case SPELL_ATTR13_UNK31: return 31;
        default: throw std::out_of_range("value");
    }
}

/*******************************************************************\
|* data for enum 'SpellAttr14' in 'SharedDefines.h' auto-generated *|
\*******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAttr14>::ToString(SpellAttr14 value)
{
    switch (value)
    {
        case SPELL_ATTR14_UNK0: return { "SPELL_ATTR14_UNK0", "Unknown attribute 0@Attr14", "" };
        case SPELL_ATTR14_REAGENT_COST_CONSUMES_CHARGES: return { "SPELL_ATTR14_REAGENT_COST_CONSUMES_CHARGES", "Reagent Consume Charges", "Consumes item charges for reagent costs instead of whole items" };
        case SPELL_ATTR14_UNK2: return { "SPELL_ATTR14_UNK2", "Unknown attribute 2@Attr14", "" };
        case SPELL_ATTR14_HIDE_PASSIVE_FROM_TOOLTIP: return { "SPELL_ATTR14_HIDE_PASSIVE_FROM_TOOLTIP", "Don't show \042Passive\042 or \042Upgrade\042 in tooltip", "" };
        case SPELL_ATTR14_UNK4: return { "SPELL_ATTR14_UNK4", "Unknown attribute 4@Attr14", "" };
        case SPELL_ATTR14_UNK5: return { "SPELL_ATTR14_UNK5", "Unknown attribute 5@Attr14", "" };
        case SPELL_ATTR14_UNK6: return { "SPELL_ATTR14_UNK6", "Unknown attribute 6@Attr14", "" };
        case SPELL_ATTR14_UNK7: return { "SPELL_ATTR14_UNK7", "Unknown attribute 7@Attr14", "" };
        case SPELL_ATTR14_UNK8: return { "SPELL_ATTR14_UNK8", "Unknown attribute 8@Attr14", "" };
        case SPELL_ATTR14_UNK9: return { "SPELL_ATTR14_UNK9", "Unknown attribute 9@Attr14", "" };
        case SPELL_ATTR14_UNK10: return { "SPELL_ATTR14_UNK10", "Unknown attribute 10@Attr14", "" };
        case SPELL_ATTR14_UNK11: return { "SPELL_ATTR14_UNK11", "Unknown attribute 11@Attr14", "" };
        case SPELL_ATTR14_UNK12: return { "SPELL_ATTR14_UNK12", "Unknown attribute 12@Attr14", "" };
        case SPELL_ATTR14_UNK13: return { "SPELL_ATTR14_UNK13", "Unknown attribute 13@Attr14", "" };
        case SPELL_ATTR14_UNK14: return { "SPELL_ATTR14_UNK14", "Unknown attribute 14@Attr14", "" };
        case SPELL_ATTR14_UNK15: return { "SPELL_ATTR14_UNK15", "Unknown attribute 15@Attr14", "" };
        case SPELL_ATTR14_UNK16: return { "SPELL_ATTR14_UNK16", "Unknown attribute 16@Attr14", "" };
        case SPELL_ATTR14_UNK17: return { "SPELL_ATTR14_UNK17", "Unknown attribute 17@Attr14", "" };
        case SPELL_ATTR14_UNK18: return { "SPELL_ATTR14_UNK18", "Unknown attribute 18@Attr14", "" };
        case SPELL_ATTR14_UNK19: return { "SPELL_ATTR14_UNK19", "Unknown attribute 19@Attr14", "" };
        case SPELL_ATTR14_UNK20: return { "SPELL_ATTR14_UNK20", "Unknown attribute 20@Attr14", "" };
        case SPELL_ATTR14_UNK21: return { "SPELL_ATTR14_UNK21", "Unknown attribute 21@Attr14", "" };
        case SPELL_ATTR14_UNK22: return { "SPELL_ATTR14_UNK22", "Unknown attribute 22@Attr14", "" };
        case SPELL_ATTR14_UNK23: return { "SPELL_ATTR14_UNK23", "Unknown attribute 23@Attr14", "" };
        case SPELL_ATTR14_UNK24: return { "SPELL_ATTR14_UNK24", "Unknown attribute 24@Attr14", "" };
        case SPELL_ATTR14_UNK25: return { "SPELL_ATTR14_UNK25", "Unknown attribute 25@Attr14", "" };
        case SPELL_ATTR14_UNK26: return { "SPELL_ATTR14_UNK26", "Unknown attribute 26@Attr14", "" };
        case SPELL_ATTR14_UNK27: return { "SPELL_ATTR14_UNK27", "Unknown attribute 27@Attr14", "" };
        case SPELL_ATTR14_UNK28: return { "SPELL_ATTR14_UNK28", "Unknown attribute 28@Attr14", "" };
        case SPELL_ATTR14_UNK29: return { "SPELL_ATTR14_UNK29", "Unknown attribute 29@Attr14", "" };
        case SPELL_ATTR14_UNK30: return { "SPELL_ATTR14_UNK30", "Unknown attribute 30@Attr14", "" };
        case SPELL_ATTR14_UNK31: return { "SPELL_ATTR14_UNK31", "Unknown attribute 31@Attr14", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr14>::Count() { return 32; }

template <>
TC_API_EXPORT SpellAttr14 EnumUtils<SpellAttr14>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_ATTR14_UNK0;
        case 1: return SPELL_ATTR14_REAGENT_COST_CONSUMES_CHARGES;
        case 2: return SPELL_ATTR14_UNK2;
        case 3: return SPELL_ATTR14_HIDE_PASSIVE_FROM_TOOLTIP;
        case 4: return SPELL_ATTR14_UNK4;
        case 5: return SPELL_ATTR14_UNK5;
        case 6: return SPELL_ATTR14_UNK6;
        case 7: return SPELL_ATTR14_UNK7;
        case 8: return SPELL_ATTR14_UNK8;
        case 9: return SPELL_ATTR14_UNK9;
        case 10: return SPELL_ATTR14_UNK10;
        case 11: return SPELL_ATTR14_UNK11;
        case 12: return SPELL_ATTR14_UNK12;
        case 13: return SPELL_ATTR14_UNK13;
        case 14: return SPELL_ATTR14_UNK14;
        case 15: return SPELL_ATTR14_UNK15;
        case 16: return SPELL_ATTR14_UNK16;
        case 17: return SPELL_ATTR14_UNK17;
        case 18: return SPELL_ATTR14_UNK18;
        case 19: return SPELL_ATTR14_UNK19;
        case 20: return SPELL_ATTR14_UNK20;
        case 21: return SPELL_ATTR14_UNK21;
        case 22: return SPELL_ATTR14_UNK22;
        case 23: return SPELL_ATTR14_UNK23;
        case 24: return SPELL_ATTR14_UNK24;
        case 25: return SPELL_ATTR14_UNK25;
        case 26: return SPELL_ATTR14_UNK26;
        case 27: return SPELL_ATTR14_UNK27;
        case 28: return SPELL_ATTR14_UNK28;
        case 29: return SPELL_ATTR14_UNK29;
        case 30: return SPELL_ATTR14_UNK30;
        case 31: return SPELL_ATTR14_UNK31;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAttr14>::ToIndex(SpellAttr14 value)
{
    switch (value)
    {
        case SPELL_ATTR14_UNK0: return 0;
        case SPELL_ATTR14_REAGENT_COST_CONSUMES_CHARGES: return 1;
        case SPELL_ATTR14_UNK2: return 2;
        case SPELL_ATTR14_HIDE_PASSIVE_FROM_TOOLTIP: return 3;
        case SPELL_ATTR14_UNK4: return 4;
        case SPELL_ATTR14_UNK5: return 5;
        case SPELL_ATTR14_UNK6: return 6;
        case SPELL_ATTR14_UNK7: return 7;
        case SPELL_ATTR14_UNK8: return 8;
        case SPELL_ATTR14_UNK9: return 9;
        case SPELL_ATTR14_UNK10: return 10;
        case SPELL_ATTR14_UNK11: return 11;
        case SPELL_ATTR14_UNK12: return 12;
        case SPELL_ATTR14_UNK13: return 13;
        case SPELL_ATTR14_UNK14: return 14;
        case SPELL_ATTR14_UNK15: return 15;
        case SPELL_ATTR14_UNK16: return 16;
        case SPELL_ATTR14_UNK17: return 17;
        case SPELL_ATTR14_UNK18: return 18;
        case SPELL_ATTR14_UNK19: return 19;
        case SPELL_ATTR14_UNK20: return 20;
        case SPELL_ATTR14_UNK21: return 21;
        case SPELL_ATTR14_UNK22: return 22;
        case SPELL_ATTR14_UNK23: return 23;
        case SPELL_ATTR14_UNK24: return 24;
        case SPELL_ATTR14_UNK25: return 25;
        case SPELL_ATTR14_UNK26: return 26;
        case SPELL_ATTR14_UNK27: return 27;
        case SPELL_ATTR14_UNK28: return 28;
        case SPELL_ATTR14_UNK29: return 29;
        case SPELL_ATTR14_UNK30: return 30;
        case SPELL_ATTR14_UNK31: return 31;
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
        case SPELL_FAILED_ALREADY_HAVE_PET: return { "SPELL_FAILED_ALREADY_HAVE_PET", "SPELL_FAILED_ALREADY_HAVE_PET", "" };
        case SPELL_FAILED_ALREADY_OPEN: return { "SPELL_FAILED_ALREADY_OPEN", "SPELL_FAILED_ALREADY_OPEN", "" };
        case SPELL_FAILED_AURA_BOUNCED: return { "SPELL_FAILED_AURA_BOUNCED", "SPELL_FAILED_AURA_BOUNCED", "" };
        case SPELL_FAILED_AUTOTRACK_INTERRUPTED: return { "SPELL_FAILED_AUTOTRACK_INTERRUPTED", "SPELL_FAILED_AUTOTRACK_INTERRUPTED", "" };
        case SPELL_FAILED_BAD_IMPLICIT_TARGETS: return { "SPELL_FAILED_BAD_IMPLICIT_TARGETS", "SPELL_FAILED_BAD_IMPLICIT_TARGETS", "" };
        case SPELL_FAILED_BAD_TARGETS: return { "SPELL_FAILED_BAD_TARGETS", "SPELL_FAILED_BAD_TARGETS", "" };
        case SPELL_FAILED_PVP_TARGET_WHILE_UNFLAGGED: return { "SPELL_FAILED_PVP_TARGET_WHILE_UNFLAGGED", "SPELL_FAILED_PVP_TARGET_WHILE_UNFLAGGED", "" };
        case SPELL_FAILED_CANT_BE_CHARMED: return { "SPELL_FAILED_CANT_BE_CHARMED", "SPELL_FAILED_CANT_BE_CHARMED", "" };
        case SPELL_FAILED_CANT_BE_DISENCHANTED: return { "SPELL_FAILED_CANT_BE_DISENCHANTED", "SPELL_FAILED_CANT_BE_DISENCHANTED", "" };
        case SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL: return { "SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL", "SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL", "" };
        case SPELL_FAILED_CANT_BE_ENCHANTED: return { "SPELL_FAILED_CANT_BE_ENCHANTED", "SPELL_FAILED_CANT_BE_ENCHANTED", "" };
        case SPELL_FAILED_CANT_BE_MILLED: return { "SPELL_FAILED_CANT_BE_MILLED", "SPELL_FAILED_CANT_BE_MILLED", "" };
        case SPELL_FAILED_CANT_BE_PROSPECTED: return { "SPELL_FAILED_CANT_BE_PROSPECTED", "SPELL_FAILED_CANT_BE_PROSPECTED", "" };
        case SPELL_FAILED_CANT_CAST_ON_TAPPED: return { "SPELL_FAILED_CANT_CAST_ON_TAPPED", "SPELL_FAILED_CANT_CAST_ON_TAPPED", "" };
        case SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE: return { "SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE", "SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE", "" };
        case SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED: return { "SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED", "SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED", "" };
        case SPELL_FAILED_CANT_STEALTH: return { "SPELL_FAILED_CANT_STEALTH", "SPELL_FAILED_CANT_STEALTH", "" };
        case SPELL_FAILED_CANT_UNTALENT: return { "SPELL_FAILED_CANT_UNTALENT", "SPELL_FAILED_CANT_UNTALENT", "" };
        case SPELL_FAILED_CASTER_AURASTATE: return { "SPELL_FAILED_CASTER_AURASTATE", "SPELL_FAILED_CASTER_AURASTATE", "" };
        case SPELL_FAILED_CASTER_DEAD: return { "SPELL_FAILED_CASTER_DEAD", "SPELL_FAILED_CASTER_DEAD", "" };
        case SPELL_FAILED_CHARMED: return { "SPELL_FAILED_CHARMED", "SPELL_FAILED_CHARMED", "" };
        case SPELL_FAILED_CHEST_IN_USE: return { "SPELL_FAILED_CHEST_IN_USE", "SPELL_FAILED_CHEST_IN_USE", "" };
        case SPELL_FAILED_CONFUSED: return { "SPELL_FAILED_CONFUSED", "SPELL_FAILED_CONFUSED", "" };
        case SPELL_FAILED_DISABLED_BY_POWER_SCALING: return { "SPELL_FAILED_DISABLED_BY_POWER_SCALING", "SPELL_FAILED_DISABLED_BY_POWER_SCALING", "" };
        case SPELL_FAILED_DONT_REPORT: return { "SPELL_FAILED_DONT_REPORT", "SPELL_FAILED_DONT_REPORT", "" };
        case SPELL_FAILED_EQUIPPED_ITEM: return { "SPELL_FAILED_EQUIPPED_ITEM", "SPELL_FAILED_EQUIPPED_ITEM", "" };
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS: return { "SPELL_FAILED_EQUIPPED_ITEM_CLASS", "SPELL_FAILED_EQUIPPED_ITEM_CLASS", "" };
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND: return { "SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND", "SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND", "" };
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND: return { "SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND", "SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND", "" };
        case SPELL_FAILED_ERROR: return { "SPELL_FAILED_ERROR", "SPELL_FAILED_ERROR", "" };
        case SPELL_FAILED_FALLING: return { "SPELL_FAILED_FALLING", "SPELL_FAILED_FALLING", "" };
        case SPELL_FAILED_FIZZLE: return { "SPELL_FAILED_FIZZLE", "SPELL_FAILED_FIZZLE", "" };
        case SPELL_FAILED_FLEEING: return { "SPELL_FAILED_FLEEING", "SPELL_FAILED_FLEEING", "" };
        case SPELL_FAILED_FOOD_LOWLEVEL: return { "SPELL_FAILED_FOOD_LOWLEVEL", "SPELL_FAILED_FOOD_LOWLEVEL", "" };
        case SPELL_FAILED_GARRISON_NOT_OWNED: return { "SPELL_FAILED_GARRISON_NOT_OWNED", "SPELL_FAILED_GARRISON_NOT_OWNED", "" };
        case SPELL_FAILED_GARRISON_OWNED: return { "SPELL_FAILED_GARRISON_OWNED", "SPELL_FAILED_GARRISON_OWNED", "" };
        case SPELL_FAILED_GARRISON_MAX_LEVEL: return { "SPELL_FAILED_GARRISON_MAX_LEVEL", "SPELL_FAILED_GARRISON_MAX_LEVEL", "" };
        case SPELL_FAILED_GARRISON_NOT_UPGRADEABLE: return { "SPELL_FAILED_GARRISON_NOT_UPGRADEABLE", "SPELL_FAILED_GARRISON_NOT_UPGRADEABLE", "" };
        case SPELL_FAILED_GARRISON_FOLLOWER_ON_MISSION: return { "SPELL_FAILED_GARRISON_FOLLOWER_ON_MISSION", "SPELL_FAILED_GARRISON_FOLLOWER_ON_MISSION", "" };
        case SPELL_FAILED_GARRISON_FOLLOWER_IN_BUILDING: return { "SPELL_FAILED_GARRISON_FOLLOWER_IN_BUILDING", "SPELL_FAILED_GARRISON_FOLLOWER_IN_BUILDING", "" };
        case SPELL_FAILED_GARRISON_FOLLOWER_MAX_LEVEL: return { "SPELL_FAILED_GARRISON_FOLLOWER_MAX_LEVEL", "SPELL_FAILED_GARRISON_FOLLOWER_MAX_LEVEL", "" };
        case SPELL_FAILED_GARRISON_FOLLOWER_MIN_ITEM_LEVEL: return { "SPELL_FAILED_GARRISON_FOLLOWER_MIN_ITEM_LEVEL", "SPELL_FAILED_GARRISON_FOLLOWER_MIN_ITEM_LEVEL", "" };
        case SPELL_FAILED_GARRISON_FOLLOWER_MAX_ITEM_LEVEL: return { "SPELL_FAILED_GARRISON_FOLLOWER_MAX_ITEM_LEVEL", "SPELL_FAILED_GARRISON_FOLLOWER_MAX_ITEM_LEVEL", "" };
        case SPELL_FAILED_GARRISON_FOLLOWER_MAX_QUALITY: return { "SPELL_FAILED_GARRISON_FOLLOWER_MAX_QUALITY", "SPELL_FAILED_GARRISON_FOLLOWER_MAX_QUALITY", "" };
        case SPELL_FAILED_GARRISON_FOLLOWER_NOT_MAX_LEVEL: return { "SPELL_FAILED_GARRISON_FOLLOWER_NOT_MAX_LEVEL", "SPELL_FAILED_GARRISON_FOLLOWER_NOT_MAX_LEVEL", "" };
        case SPELL_FAILED_GARRISON_FOLLOWER_HAS_ABILITY: return { "SPELL_FAILED_GARRISON_FOLLOWER_HAS_ABILITY", "SPELL_FAILED_GARRISON_FOLLOWER_HAS_ABILITY", "" };
        case SPELL_FAILED_GARRISON_FOLLOWER_HAS_SINGLE_MISSION_ABILITY: return { "SPELL_FAILED_GARRISON_FOLLOWER_HAS_SINGLE_MISSION_ABILITY", "SPELL_FAILED_GARRISON_FOLLOWER_HAS_SINGLE_MISSION_ABILITY", "" };
        case SPELL_FAILED_GARRISON_FOLLOWER_REQUIRES_EPIC: return { "SPELL_FAILED_GARRISON_FOLLOWER_REQUIRES_EPIC", "SPELL_FAILED_GARRISON_FOLLOWER_REQUIRES_EPIC", "" };
        case SPELL_FAILED_GARRISON_MISSION_NOT_IN_PROGRESS: return { "SPELL_FAILED_GARRISON_MISSION_NOT_IN_PROGRESS", "SPELL_FAILED_GARRISON_MISSION_NOT_IN_PROGRESS", "" };
        case SPELL_FAILED_GARRISON_MISSION_COMPLETE: return { "SPELL_FAILED_GARRISON_MISSION_COMPLETE", "SPELL_FAILED_GARRISON_MISSION_COMPLETE", "" };
        case SPELL_FAILED_GARRISON_NO_MISSIONS_AVAILABLE: return { "SPELL_FAILED_GARRISON_NO_MISSIONS_AVAILABLE", "SPELL_FAILED_GARRISON_NO_MISSIONS_AVAILABLE", "" };
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
        case SPELL_FAILED_ONLY_INDOORS: return { "SPELL_FAILED_ONLY_INDOORS", "SPELL_FAILED_ONLY_INDOORS", "" };
        case SPELL_FAILED_ONLY_MOUNTED: return { "SPELL_FAILED_ONLY_MOUNTED", "SPELL_FAILED_ONLY_MOUNTED", "" };
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
        case SPELL_FAILED_TARGET_IN_PET_BATTLE: return { "SPELL_FAILED_TARGET_IN_PET_BATTLE", "SPELL_FAILED_TARGET_IN_PET_BATTLE", "" };
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
        case SPELL_FAILED_VISION_OBSCURED: return { "SPELL_FAILED_VISION_OBSCURED", "SPELL_FAILED_VISION_OBSCURED", "" };
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
        case SPELL_FAILED_NOT_IN_RATED_BATTLEGROUND: return { "SPELL_FAILED_NOT_IN_RATED_BATTLEGROUND", "SPELL_FAILED_NOT_IN_RATED_BATTLEGROUND", "" };
        case SPELL_FAILED_NOT_ON_SHAPESHIFT: return { "SPELL_FAILED_NOT_ON_SHAPESHIFT", "SPELL_FAILED_NOT_ON_SHAPESHIFT", "" };
        case SPELL_FAILED_NOT_ON_STEALTHED: return { "SPELL_FAILED_NOT_ON_STEALTHED", "SPELL_FAILED_NOT_ON_STEALTHED", "" };
        case SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE: return { "SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE", "SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE", "" };
        case SPELL_FAILED_NOT_ON_MOUNTED: return { "SPELL_FAILED_NOT_ON_MOUNTED", "SPELL_FAILED_NOT_ON_MOUNTED", "" };
        case SPELL_FAILED_TOO_SHALLOW: return { "SPELL_FAILED_TOO_SHALLOW", "SPELL_FAILED_TOO_SHALLOW", "" };
        case SPELL_FAILED_TARGET_NOT_IN_SANCTUARY: return { "SPELL_FAILED_TARGET_NOT_IN_SANCTUARY", "SPELL_FAILED_TARGET_NOT_IN_SANCTUARY", "" };
        case SPELL_FAILED_TARGET_IS_TRIVIAL: return { "SPELL_FAILED_TARGET_IS_TRIVIAL", "SPELL_FAILED_TARGET_IS_TRIVIAL", "" };
        case SPELL_FAILED_BM_OR_INVISGOD: return { "SPELL_FAILED_BM_OR_INVISGOD", "SPELL_FAILED_BM_OR_INVISGOD", "" };
        case SPELL_FAILED_GROUND_MOUNT_NOT_ALLOWED: return { "SPELL_FAILED_GROUND_MOUNT_NOT_ALLOWED", "SPELL_FAILED_GROUND_MOUNT_NOT_ALLOWED", "" };
        case SPELL_FAILED_FLOATING_MOUNT_NOT_ALLOWED: return { "SPELL_FAILED_FLOATING_MOUNT_NOT_ALLOWED", "SPELL_FAILED_FLOATING_MOUNT_NOT_ALLOWED", "" };
        case SPELL_FAILED_UNDERWATER_MOUNT_NOT_ALLOWED: return { "SPELL_FAILED_UNDERWATER_MOUNT_NOT_ALLOWED", "SPELL_FAILED_UNDERWATER_MOUNT_NOT_ALLOWED", "" };
        case SPELL_FAILED_FLYING_MOUNT_NOT_ALLOWED: return { "SPELL_FAILED_FLYING_MOUNT_NOT_ALLOWED", "SPELL_FAILED_FLYING_MOUNT_NOT_ALLOWED", "" };
        case SPELL_FAILED_APPRENTICE_RIDING_REQUIREMENT: return { "SPELL_FAILED_APPRENTICE_RIDING_REQUIREMENT", "SPELL_FAILED_APPRENTICE_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_JOURNEYMAN_RIDING_REQUIREMENT: return { "SPELL_FAILED_JOURNEYMAN_RIDING_REQUIREMENT", "SPELL_FAILED_JOURNEYMAN_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_EXPERT_RIDING_REQUIREMENT: return { "SPELL_FAILED_EXPERT_RIDING_REQUIREMENT", "SPELL_FAILED_EXPERT_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT: return { "SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT", "SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_MASTER_RIDING_REQUIREMENT: return { "SPELL_FAILED_MASTER_RIDING_REQUIREMENT", "SPELL_FAILED_MASTER_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_COLD_RIDING_REQUIREMENT: return { "SPELL_FAILED_COLD_RIDING_REQUIREMENT", "SPELL_FAILED_COLD_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_FLIGHT_MASTER_RIDING_REQUIREMENT: return { "SPELL_FAILED_FLIGHT_MASTER_RIDING_REQUIREMENT", "SPELL_FAILED_FLIGHT_MASTER_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_CS_RIDING_REQUIREMENT: return { "SPELL_FAILED_CS_RIDING_REQUIREMENT", "SPELL_FAILED_CS_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_PANDA_RIDING_REQUIREMENT: return { "SPELL_FAILED_PANDA_RIDING_REQUIREMENT", "SPELL_FAILED_PANDA_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_DRAENOR_RIDING_REQUIREMENT: return { "SPELL_FAILED_DRAENOR_RIDING_REQUIREMENT", "SPELL_FAILED_DRAENOR_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_BROKEN_ISLES_RIDING_REQUIREMENT: return { "SPELL_FAILED_BROKEN_ISLES_RIDING_REQUIREMENT", "SPELL_FAILED_BROKEN_ISLES_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_MOUNT_NO_FLOAT_HERE: return { "SPELL_FAILED_MOUNT_NO_FLOAT_HERE", "SPELL_FAILED_MOUNT_NO_FLOAT_HERE", "" };
        case SPELL_FAILED_MOUNT_NO_UNDERWATER_HERE: return { "SPELL_FAILED_MOUNT_NO_UNDERWATER_HERE", "SPELL_FAILED_MOUNT_NO_UNDERWATER_HERE", "" };
        case SPELL_FAILED_MOUNT_ABOVE_WATER_HERE: return { "SPELL_FAILED_MOUNT_ABOVE_WATER_HERE", "SPELL_FAILED_MOUNT_ABOVE_WATER_HERE", "" };
        case SPELL_FAILED_MOUNT_COLLECTED_ON_OTHER_CHAR: return { "SPELL_FAILED_MOUNT_COLLECTED_ON_OTHER_CHAR", "SPELL_FAILED_MOUNT_COLLECTED_ON_OTHER_CHAR", "" };
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
        case SPELL_FAILED_GLYPH_EXCLUSIVE_CATEGORY: return { "SPELL_FAILED_GLYPH_EXCLUSIVE_CATEGORY", "SPELL_FAILED_GLYPH_EXCLUSIVE_CATEGORY", "" };
        case SPELL_FAILED_GLYPH_INVALID_SPEC: return { "SPELL_FAILED_GLYPH_INVALID_SPEC", "SPELL_FAILED_GLYPH_INVALID_SPEC", "" };
        case SPELL_FAILED_GLYPH_NO_SPEC: return { "SPELL_FAILED_GLYPH_NO_SPEC", "SPELL_FAILED_GLYPH_NO_SPEC", "" };
        case SPELL_FAILED_NO_ACTIVE_GLYPHS: return { "SPELL_FAILED_NO_ACTIVE_GLYPHS", "SPELL_FAILED_NO_ACTIVE_GLYPHS", "" };
        case SPELL_FAILED_NO_VALID_TARGETS: return { "SPELL_FAILED_NO_VALID_TARGETS", "SPELL_FAILED_NO_VALID_TARGETS", "" };
        case SPELL_FAILED_ITEM_AT_MAX_CHARGES: return { "SPELL_FAILED_ITEM_AT_MAX_CHARGES", "SPELL_FAILED_ITEM_AT_MAX_CHARGES", "" };
        case SPELL_FAILED_NOT_IN_BARBERSHOP: return { "SPELL_FAILED_NOT_IN_BARBERSHOP", "SPELL_FAILED_NOT_IN_BARBERSHOP", "" };
        case SPELL_FAILED_FISHING_TOO_LOW: return { "SPELL_FAILED_FISHING_TOO_LOW", "SPELL_FAILED_FISHING_TOO_LOW", "" };
        case SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW: return { "SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW", "SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW", "" };
        case SPELL_FAILED_SUMMON_PENDING: return { "SPELL_FAILED_SUMMON_PENDING", "SPELL_FAILED_SUMMON_PENDING", "" };
        case SPELL_FAILED_MAX_SOCKETS: return { "SPELL_FAILED_MAX_SOCKETS", "SPELL_FAILED_MAX_SOCKETS", "" };
        case SPELL_FAILED_PET_CAN_RENAME: return { "SPELL_FAILED_PET_CAN_RENAME", "SPELL_FAILED_PET_CAN_RENAME", "" };
        case SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED: return { "SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED", "SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED", "" };
        case SPELL_FAILED_TARGET_HAS_RESURRECT_PENDING: return { "SPELL_FAILED_TARGET_HAS_RESURRECT_PENDING", "SPELL_FAILED_TARGET_HAS_RESURRECT_PENDING", "" };
        case SPELL_FAILED_NO_ACTIONS: return { "SPELL_FAILED_NO_ACTIONS", "SPELL_FAILED_NO_ACTIONS", "" };
        case SPELL_FAILED_CURRENCY_WEIGHT_MISMATCH: return { "SPELL_FAILED_CURRENCY_WEIGHT_MISMATCH", "SPELL_FAILED_CURRENCY_WEIGHT_MISMATCH", "" };
        case SPELL_FAILED_WEIGHT_NOT_ENOUGH: return { "SPELL_FAILED_WEIGHT_NOT_ENOUGH", "SPELL_FAILED_WEIGHT_NOT_ENOUGH", "" };
        case SPELL_FAILED_WEIGHT_TOO_MUCH: return { "SPELL_FAILED_WEIGHT_TOO_MUCH", "SPELL_FAILED_WEIGHT_TOO_MUCH", "" };
        case SPELL_FAILED_NO_VACANT_SEAT: return { "SPELL_FAILED_NO_VACANT_SEAT", "SPELL_FAILED_NO_VACANT_SEAT", "" };
        case SPELL_FAILED_NO_LIQUID: return { "SPELL_FAILED_NO_LIQUID", "SPELL_FAILED_NO_LIQUID", "" };
        case SPELL_FAILED_ONLY_NOT_SWIMMING: return { "SPELL_FAILED_ONLY_NOT_SWIMMING", "SPELL_FAILED_ONLY_NOT_SWIMMING", "" };
        case SPELL_FAILED_BY_NOT_MOVING: return { "SPELL_FAILED_BY_NOT_MOVING", "SPELL_FAILED_BY_NOT_MOVING", "" };
        case SPELL_FAILED_IN_COMBAT_RES_LIMIT_REACHED: return { "SPELL_FAILED_IN_COMBAT_RES_LIMIT_REACHED", "SPELL_FAILED_IN_COMBAT_RES_LIMIT_REACHED", "" };
        case SPELL_FAILED_NOT_IN_ARENA: return { "SPELL_FAILED_NOT_IN_ARENA", "SPELL_FAILED_NOT_IN_ARENA", "" };
        case SPELL_FAILED_TARGET_NOT_GROUNDED: return { "SPELL_FAILED_TARGET_NOT_GROUNDED", "SPELL_FAILED_TARGET_NOT_GROUNDED", "" };
        case SPELL_FAILED_EXCEEDED_WEEKLY_USAGE: return { "SPELL_FAILED_EXCEEDED_WEEKLY_USAGE", "SPELL_FAILED_EXCEEDED_WEEKLY_USAGE", "" };
        case SPELL_FAILED_NOT_IN_LFG_DUNGEON: return { "SPELL_FAILED_NOT_IN_LFG_DUNGEON", "SPELL_FAILED_NOT_IN_LFG_DUNGEON", "" };
        case SPELL_FAILED_BAD_TARGET_FILTER: return { "SPELL_FAILED_BAD_TARGET_FILTER", "SPELL_FAILED_BAD_TARGET_FILTER", "" };
        case SPELL_FAILED_NOT_ENOUGH_TARGETS: return { "SPELL_FAILED_NOT_ENOUGH_TARGETS", "SPELL_FAILED_NOT_ENOUGH_TARGETS", "" };
        case SPELL_FAILED_NO_SPEC: return { "SPELL_FAILED_NO_SPEC", "SPELL_FAILED_NO_SPEC", "" };
        case SPELL_FAILED_CANT_ADD_BATTLE_PET: return { "SPELL_FAILED_CANT_ADD_BATTLE_PET", "SPELL_FAILED_CANT_ADD_BATTLE_PET", "" };
        case SPELL_FAILED_CANT_UPGRADE_BATTLE_PET: return { "SPELL_FAILED_CANT_UPGRADE_BATTLE_PET", "SPELL_FAILED_CANT_UPGRADE_BATTLE_PET", "" };
        case SPELL_FAILED_WRONG_BATTLE_PET_TYPE: return { "SPELL_FAILED_WRONG_BATTLE_PET_TYPE", "SPELL_FAILED_WRONG_BATTLE_PET_TYPE", "" };
        case SPELL_FAILED_NO_DUNGEON_ENCOUNTER: return { "SPELL_FAILED_NO_DUNGEON_ENCOUNTER", "SPELL_FAILED_NO_DUNGEON_ENCOUNTER", "" };
        case SPELL_FAILED_NO_TELEPORT_FROM_DUNGEON: return { "SPELL_FAILED_NO_TELEPORT_FROM_DUNGEON", "SPELL_FAILED_NO_TELEPORT_FROM_DUNGEON", "" };
        case SPELL_FAILED_MAX_LEVEL_TOO_LOW: return { "SPELL_FAILED_MAX_LEVEL_TOO_LOW", "SPELL_FAILED_MAX_LEVEL_TOO_LOW", "" };
        case SPELL_FAILED_CANT_REPLACE_ITEM_BONUS: return { "SPELL_FAILED_CANT_REPLACE_ITEM_BONUS", "SPELL_FAILED_CANT_REPLACE_ITEM_BONUS", "" };
        case GRANT_PET_LEVEL_FAIL: return { "GRANT_PET_LEVEL_FAIL", "GRANT_PET_LEVEL_FAIL", "" };
        case SPELL_FAILED_SKILL_LINE_NOT_KNOWN: return { "SPELL_FAILED_SKILL_LINE_NOT_KNOWN", "SPELL_FAILED_SKILL_LINE_NOT_KNOWN", "" };
        case SPELL_FAILED_BLUEPRINT_KNOWN: return { "SPELL_FAILED_BLUEPRINT_KNOWN", "SPELL_FAILED_BLUEPRINT_KNOWN", "" };
        case SPELL_FAILED_FOLLOWER_KNOWN: return { "SPELL_FAILED_FOLLOWER_KNOWN", "SPELL_FAILED_FOLLOWER_KNOWN", "" };
        case SPELL_FAILED_CANT_OVERRIDE_ENCHANT_VISUAL: return { "SPELL_FAILED_CANT_OVERRIDE_ENCHANT_VISUAL", "SPELL_FAILED_CANT_OVERRIDE_ENCHANT_VISUAL", "" };
        case SPELL_FAILED_ITEM_NOT_A_WEAPON: return { "SPELL_FAILED_ITEM_NOT_A_WEAPON", "SPELL_FAILED_ITEM_NOT_A_WEAPON", "" };
        case SPELL_FAILED_SAME_ENCHANT_VISUAL: return { "SPELL_FAILED_SAME_ENCHANT_VISUAL", "SPELL_FAILED_SAME_ENCHANT_VISUAL", "" };
        case SPELL_FAILED_TOY_USE_LIMIT_REACHED: return { "SPELL_FAILED_TOY_USE_LIMIT_REACHED", "SPELL_FAILED_TOY_USE_LIMIT_REACHED", "" };
        case SPELL_FAILED_TOY_ALREADY_KNOWN: return { "SPELL_FAILED_TOY_ALREADY_KNOWN", "SPELL_FAILED_TOY_ALREADY_KNOWN", "" };
        case SPELL_FAILED_SHIPMENTS_FULL: return { "SPELL_FAILED_SHIPMENTS_FULL", "SPELL_FAILED_SHIPMENTS_FULL", "" };
        case SPELL_FAILED_NO_SHIPMENTS_FOR_CONTAINER: return { "SPELL_FAILED_NO_SHIPMENTS_FOR_CONTAINER", "SPELL_FAILED_NO_SHIPMENTS_FOR_CONTAINER", "" };
        case SPELL_FAILED_NO_BUILDING_FOR_SHIPMENT: return { "SPELL_FAILED_NO_BUILDING_FOR_SHIPMENT", "SPELL_FAILED_NO_BUILDING_FOR_SHIPMENT", "" };
        case SPELL_FAILED_NOT_ENOUGH_SHIPMENTS_FOR_CONTAINER: return { "SPELL_FAILED_NOT_ENOUGH_SHIPMENTS_FOR_CONTAINER", "SPELL_FAILED_NOT_ENOUGH_SHIPMENTS_FOR_CONTAINER", "" };
        case SPELL_FAILED_HAS_MISSION: return { "SPELL_FAILED_HAS_MISSION", "SPELL_FAILED_HAS_MISSION", "" };
        case SPELL_FAILED_BUILDING_ACTIVATE_NOT_READY: return { "SPELL_FAILED_BUILDING_ACTIVATE_NOT_READY", "SPELL_FAILED_BUILDING_ACTIVATE_NOT_READY", "" };
        case SPELL_FAILED_NOT_SOULBOUND: return { "SPELL_FAILED_NOT_SOULBOUND", "SPELL_FAILED_NOT_SOULBOUND", "" };
        case SPELL_FAILED_RIDING_VEHICLE: return { "SPELL_FAILED_RIDING_VEHICLE", "SPELL_FAILED_RIDING_VEHICLE", "" };
        case SPELL_FAILED_VETERAN_TRIAL_ABOVE_SKILL_RANK_MAX: return { "SPELL_FAILED_VETERAN_TRIAL_ABOVE_SKILL_RANK_MAX", "SPELL_FAILED_VETERAN_TRIAL_ABOVE_SKILL_RANK_MAX", "" };
        case SPELL_FAILED_NOT_WHILE_MERCENARY: return { "SPELL_FAILED_NOT_WHILE_MERCENARY", "SPELL_FAILED_NOT_WHILE_MERCENARY", "" };
        case SPELL_FAILED_SPEC_DISABLED: return { "SPELL_FAILED_SPEC_DISABLED", "SPELL_FAILED_SPEC_DISABLED", "" };
        case SPELL_FAILED_CANT_BE_OBLITERATED: return { "SPELL_FAILED_CANT_BE_OBLITERATED", "SPELL_FAILED_CANT_BE_OBLITERATED", "" };
        case SPELL_FAILED_CANT_BE_SCRAPPED: return { "SPELL_FAILED_CANT_BE_SCRAPPED", "SPELL_FAILED_CANT_BE_SCRAPPED", "" };
        case SPELL_FAILED_FOLLOWER_CLASS_SPEC_CAP: return { "SPELL_FAILED_FOLLOWER_CLASS_SPEC_CAP", "SPELL_FAILED_FOLLOWER_CLASS_SPEC_CAP", "" };
        case SPELL_FAILED_TRANSPORT_NOT_READY: return { "SPELL_FAILED_TRANSPORT_NOT_READY", "SPELL_FAILED_TRANSPORT_NOT_READY", "" };
        case SPELL_FAILED_TRANSMOG_SET_ALREADY_KNOWN: return { "SPELL_FAILED_TRANSMOG_SET_ALREADY_KNOWN", "SPELL_FAILED_TRANSMOG_SET_ALREADY_KNOWN", "" };
        case SPELL_FAILED_DISABLED_BY_AURA_LABEL: return { "SPELL_FAILED_DISABLED_BY_AURA_LABEL", "SPELL_FAILED_DISABLED_BY_AURA_LABEL", "" };
        case SPELL_FAILED_DISABLED_BY_MAX_USABLE_LEVEL: return { "SPELL_FAILED_DISABLED_BY_MAX_USABLE_LEVEL", "SPELL_FAILED_DISABLED_BY_MAX_USABLE_LEVEL", "" };
        case SPELL_FAILED_SPELL_ALREADY_KNOWN: return { "SPELL_FAILED_SPELL_ALREADY_KNOWN", "SPELL_FAILED_SPELL_ALREADY_KNOWN", "" };
        case SPELL_FAILED_MUST_KNOW_SUPERCEDING_SPELL: return { "SPELL_FAILED_MUST_KNOW_SUPERCEDING_SPELL", "SPELL_FAILED_MUST_KNOW_SUPERCEDING_SPELL", "" };
        case SPELL_FAILED_YOU_CANNOT_USE_THAT_IN_PVP_INSTANCE: return { "SPELL_FAILED_YOU_CANNOT_USE_THAT_IN_PVP_INSTANCE", "SPELL_FAILED_YOU_CANNOT_USE_THAT_IN_PVP_INSTANCE", "" };
        case SPELL_FAILED_NO_ARTIFACT_EQUIPPED: return { "SPELL_FAILED_NO_ARTIFACT_EQUIPPED", "SPELL_FAILED_NO_ARTIFACT_EQUIPPED", "" };
        case SPELL_FAILED_WRONG_ARTIFACT_EQUIPPED: return { "SPELL_FAILED_WRONG_ARTIFACT_EQUIPPED", "SPELL_FAILED_WRONG_ARTIFACT_EQUIPPED", "" };
        case SPELL_FAILED_TARGET_IS_UNTARGETABLE_BY_ANYONE: return { "SPELL_FAILED_TARGET_IS_UNTARGETABLE_BY_ANYONE", "SPELL_FAILED_TARGET_IS_UNTARGETABLE_BY_ANYONE", "" };
        case SPELL_FAILED_SPELL_EFFECT_FAILED: return { "SPELL_FAILED_SPELL_EFFECT_FAILED", "SPELL_FAILED_SPELL_EFFECT_FAILED", "" };
        case SPELL_FAILED_NEED_ALL_PARTY_MEMBERS: return { "SPELL_FAILED_NEED_ALL_PARTY_MEMBERS", "SPELL_FAILED_NEED_ALL_PARTY_MEMBERS", "" };
        case SPELL_FAILED_ARTIFACT_AT_FULL_POWER: return { "SPELL_FAILED_ARTIFACT_AT_FULL_POWER", "SPELL_FAILED_ARTIFACT_AT_FULL_POWER", "" };
        case SPELL_FAILED_AP_ITEM_FROM_PREVIOUS_TIER: return { "SPELL_FAILED_AP_ITEM_FROM_PREVIOUS_TIER", "SPELL_FAILED_AP_ITEM_FROM_PREVIOUS_TIER", "" };
        case SPELL_FAILED_AREA_TRIGGER_CREATION: return { "SPELL_FAILED_AREA_TRIGGER_CREATION", "SPELL_FAILED_AREA_TRIGGER_CREATION", "" };
        case SPELL_FAILED_AZERITE_EMPOWERED_ONLY: return { "SPELL_FAILED_AZERITE_EMPOWERED_ONLY", "SPELL_FAILED_AZERITE_EMPOWERED_ONLY", "" };
        case SPELL_FAILED_AZERITE_EMPOWERED_NO_CHOICES_TO_UNDO: return { "SPELL_FAILED_AZERITE_EMPOWERED_NO_CHOICES_TO_UNDO", "SPELL_FAILED_AZERITE_EMPOWERED_NO_CHOICES_TO_UNDO", "" };
        case SPELL_FAILED_WRONG_FACTION: return { "SPELL_FAILED_WRONG_FACTION", "SPELL_FAILED_WRONG_FACTION", "" };
        case SPELL_FAILED_NOT_ENOUGH_CURRENCY: return { "SPELL_FAILED_NOT_ENOUGH_CURRENCY", "SPELL_FAILED_NOT_ENOUGH_CURRENCY", "" };
        case SPELL_FAILED_BATTLE_FOR_AZEROTH_RIDING_REQUIREMENT: return { "SPELL_FAILED_BATTLE_FOR_AZEROTH_RIDING_REQUIREMENT", "SPELL_FAILED_BATTLE_FOR_AZEROTH_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_MOUNT_EQUIPMENT_ERROR: return { "SPELL_FAILED_MOUNT_EQUIPMENT_ERROR", "SPELL_FAILED_MOUNT_EQUIPMENT_ERROR", "" };
        case SPELL_FAILED_NOT_WHILE_LEVEL_LINKED: return { "SPELL_FAILED_NOT_WHILE_LEVEL_LINKED", "SPELL_FAILED_NOT_WHILE_LEVEL_LINKED", "" };
        case SPELL_FAILED_LEVEL_LINKED_LOW_LEVEL: return { "SPELL_FAILED_LEVEL_LINKED_LOW_LEVEL", "SPELL_FAILED_LEVEL_LINKED_LOW_LEVEL", "" };
        case SPELL_FAILED_SUMMON_MAP_CONDITION: return { "SPELL_FAILED_SUMMON_MAP_CONDITION", "SPELL_FAILED_SUMMON_MAP_CONDITION", "" };
        case SPELL_FAILED_SET_COVENANT_ERROR: return { "SPELL_FAILED_SET_COVENANT_ERROR", "SPELL_FAILED_SET_COVENANT_ERROR", "" };
        case SPELL_FAILED_RUNEFORGE_LEGENDARY_UPGRADE: return { "SPELL_FAILED_RUNEFORGE_LEGENDARY_UPGRADE", "SPELL_FAILED_RUNEFORGE_LEGENDARY_UPGRADE", "" };
        case SPELL_FAILED_SET_CHROMIE_TIME_ERROR: return { "SPELL_FAILED_SET_CHROMIE_TIME_ERROR", "SPELL_FAILED_SET_CHROMIE_TIME_ERROR", "" };
        case SPELL_FAILED_INELIGIBLE_WEAPON_APPEARANCE: return { "SPELL_FAILED_INELIGIBLE_WEAPON_APPEARANCE", "SPELL_FAILED_INELIGIBLE_WEAPON_APPEARANCE", "" };
        case SPELL_FAILED_PLAYER_CONDITION: return { "SPELL_FAILED_PLAYER_CONDITION", "SPELL_FAILED_PLAYER_CONDITION", "" };
        case SPELL_FAILED_NOT_WHILE_CHROMIE_TIMED: return { "SPELL_FAILED_NOT_WHILE_CHROMIE_TIMED", "SPELL_FAILED_NOT_WHILE_CHROMIE_TIMED", "" };
        case SPELL_FAILED_OPTIONAL_REAGENTS: return { "SPELL_FAILED_OPTIONAL_REAGENTS", "SPELL_FAILED_OPTIONAL_REAGENTS", "" };
        case SPELL_FAILED_SPECTATOR_OR_COMMENTATOR: return { "SPELL_FAILED_SPECTATOR_OR_COMMENTATOR", "SPELL_FAILED_SPECTATOR_OR_COMMENTATOR", "" };
        case SPELL_FAILED_SOULBIND_CONDUIT_LEARN_FAILED_INVALID_COVENANT: return { "SPELL_FAILED_SOULBIND_CONDUIT_LEARN_FAILED_INVALID_COVENANT", "SPELL_FAILED_SOULBIND_CONDUIT_LEARN_FAILED_INVALID_COVENANT", "" };
        case SPELL_FAILED_SHADOWLANDS_RIDING_REQUIREMENT: return { "SPELL_FAILED_SHADOWLANDS_RIDING_REQUIREMENT", "SPELL_FAILED_SHADOWLANDS_RIDING_REQUIREMENT", "" };
        case SPELL_FAILED_NOT_IN_MAGE_TOWER: return { "SPELL_FAILED_NOT_IN_MAGE_TOWER", "SPELL_FAILED_NOT_IN_MAGE_TOWER", "" };
        case SPELL_FAILED_GARRISON_FOLLOWER_AT_MIN_LEVEL: return { "SPELL_FAILED_GARRISON_FOLLOWER_AT_MIN_LEVEL", "SPELL_FAILED_GARRISON_FOLLOWER_AT_MIN_LEVEL", "" };
        case SPELL_FAILED_UNKNOWN: return { "SPELL_FAILED_UNKNOWN", "SPELL_FAILED_UNKNOWN", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellCastResult>::Count() { return 314; }

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
        case 8: return SPELL_FAILED_ALREADY_HAVE_PET;
        case 9: return SPELL_FAILED_ALREADY_OPEN;
        case 10: return SPELL_FAILED_AURA_BOUNCED;
        case 11: return SPELL_FAILED_AUTOTRACK_INTERRUPTED;
        case 12: return SPELL_FAILED_BAD_IMPLICIT_TARGETS;
        case 13: return SPELL_FAILED_BAD_TARGETS;
        case 14: return SPELL_FAILED_PVP_TARGET_WHILE_UNFLAGGED;
        case 15: return SPELL_FAILED_CANT_BE_CHARMED;
        case 16: return SPELL_FAILED_CANT_BE_DISENCHANTED;
        case 17: return SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL;
        case 18: return SPELL_FAILED_CANT_BE_ENCHANTED;
        case 19: return SPELL_FAILED_CANT_BE_MILLED;
        case 20: return SPELL_FAILED_CANT_BE_PROSPECTED;
        case 21: return SPELL_FAILED_CANT_CAST_ON_TAPPED;
        case 22: return SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE;
        case 23: return SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED;
        case 24: return SPELL_FAILED_CANT_STEALTH;
        case 25: return SPELL_FAILED_CANT_UNTALENT;
        case 26: return SPELL_FAILED_CASTER_AURASTATE;
        case 27: return SPELL_FAILED_CASTER_DEAD;
        case 28: return SPELL_FAILED_CHARMED;
        case 29: return SPELL_FAILED_CHEST_IN_USE;
        case 30: return SPELL_FAILED_CONFUSED;
        case 31: return SPELL_FAILED_DISABLED_BY_POWER_SCALING;
        case 32: return SPELL_FAILED_DONT_REPORT;
        case 33: return SPELL_FAILED_EQUIPPED_ITEM;
        case 34: return SPELL_FAILED_EQUIPPED_ITEM_CLASS;
        case 35: return SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND;
        case 36: return SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND;
        case 37: return SPELL_FAILED_ERROR;
        case 38: return SPELL_FAILED_FALLING;
        case 39: return SPELL_FAILED_FIZZLE;
        case 40: return SPELL_FAILED_FLEEING;
        case 41: return SPELL_FAILED_FOOD_LOWLEVEL;
        case 42: return SPELL_FAILED_GARRISON_NOT_OWNED;
        case 43: return SPELL_FAILED_GARRISON_OWNED;
        case 44: return SPELL_FAILED_GARRISON_MAX_LEVEL;
        case 45: return SPELL_FAILED_GARRISON_NOT_UPGRADEABLE;
        case 46: return SPELL_FAILED_GARRISON_FOLLOWER_ON_MISSION;
        case 47: return SPELL_FAILED_GARRISON_FOLLOWER_IN_BUILDING;
        case 48: return SPELL_FAILED_GARRISON_FOLLOWER_MAX_LEVEL;
        case 49: return SPELL_FAILED_GARRISON_FOLLOWER_MIN_ITEM_LEVEL;
        case 50: return SPELL_FAILED_GARRISON_FOLLOWER_MAX_ITEM_LEVEL;
        case 51: return SPELL_FAILED_GARRISON_FOLLOWER_MAX_QUALITY;
        case 52: return SPELL_FAILED_GARRISON_FOLLOWER_NOT_MAX_LEVEL;
        case 53: return SPELL_FAILED_GARRISON_FOLLOWER_HAS_ABILITY;
        case 54: return SPELL_FAILED_GARRISON_FOLLOWER_HAS_SINGLE_MISSION_ABILITY;
        case 55: return SPELL_FAILED_GARRISON_FOLLOWER_REQUIRES_EPIC;
        case 56: return SPELL_FAILED_GARRISON_MISSION_NOT_IN_PROGRESS;
        case 57: return SPELL_FAILED_GARRISON_MISSION_COMPLETE;
        case 58: return SPELL_FAILED_GARRISON_NO_MISSIONS_AVAILABLE;
        case 59: return SPELL_FAILED_HIGHLEVEL;
        case 60: return SPELL_FAILED_HUNGER_SATIATED;
        case 61: return SPELL_FAILED_IMMUNE;
        case 62: return SPELL_FAILED_INCORRECT_AREA;
        case 63: return SPELL_FAILED_INTERRUPTED;
        case 64: return SPELL_FAILED_INTERRUPTED_COMBAT;
        case 65: return SPELL_FAILED_ITEM_ALREADY_ENCHANTED;
        case 66: return SPELL_FAILED_ITEM_GONE;
        case 67: return SPELL_FAILED_ITEM_NOT_FOUND;
        case 68: return SPELL_FAILED_ITEM_NOT_READY;
        case 69: return SPELL_FAILED_LEVEL_REQUIREMENT;
        case 70: return SPELL_FAILED_LINE_OF_SIGHT;
        case 71: return SPELL_FAILED_LOWLEVEL;
        case 72: return SPELL_FAILED_LOW_CASTLEVEL;
        case 73: return SPELL_FAILED_MAINHAND_EMPTY;
        case 74: return SPELL_FAILED_MOVING;
        case 75: return SPELL_FAILED_NEED_AMMO;
        case 76: return SPELL_FAILED_NEED_AMMO_POUCH;
        case 77: return SPELL_FAILED_NEED_EXOTIC_AMMO;
        case 78: return SPELL_FAILED_NEED_MORE_ITEMS;
        case 79: return SPELL_FAILED_NOPATH;
        case 80: return SPELL_FAILED_NOT_BEHIND;
        case 81: return SPELL_FAILED_NOT_FISHABLE;
        case 82: return SPELL_FAILED_NOT_FLYING;
        case 83: return SPELL_FAILED_NOT_HERE;
        case 84: return SPELL_FAILED_NOT_INFRONT;
        case 85: return SPELL_FAILED_NOT_IN_CONTROL;
        case 86: return SPELL_FAILED_NOT_KNOWN;
        case 87: return SPELL_FAILED_NOT_MOUNTED;
        case 88: return SPELL_FAILED_NOT_ON_TAXI;
        case 89: return SPELL_FAILED_NOT_ON_TRANSPORT;
        case 90: return SPELL_FAILED_NOT_READY;
        case 91: return SPELL_FAILED_NOT_SHAPESHIFT;
        case 92: return SPELL_FAILED_NOT_STANDING;
        case 93: return SPELL_FAILED_NOT_TRADEABLE;
        case 94: return SPELL_FAILED_NOT_TRADING;
        case 95: return SPELL_FAILED_NOT_UNSHEATHED;
        case 96: return SPELL_FAILED_NOT_WHILE_GHOST;
        case 97: return SPELL_FAILED_NOT_WHILE_LOOTING;
        case 98: return SPELL_FAILED_NO_AMMO;
        case 99: return SPELL_FAILED_NO_CHARGES_REMAIN;
        case 100: return SPELL_FAILED_NO_COMBO_POINTS;
        case 101: return SPELL_FAILED_NO_DUELING;
        case 102: return SPELL_FAILED_NO_ENDURANCE;
        case 103: return SPELL_FAILED_NO_FISH;
        case 104: return SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED;
        case 105: return SPELL_FAILED_NO_MOUNTS_ALLOWED;
        case 106: return SPELL_FAILED_NO_PET;
        case 107: return SPELL_FAILED_NO_POWER;
        case 108: return SPELL_FAILED_NOTHING_TO_DISPEL;
        case 109: return SPELL_FAILED_NOTHING_TO_STEAL;
        case 110: return SPELL_FAILED_ONLY_ABOVEWATER;
        case 111: return SPELL_FAILED_ONLY_INDOORS;
        case 112: return SPELL_FAILED_ONLY_MOUNTED;
        case 113: return SPELL_FAILED_ONLY_OUTDOORS;
        case 114: return SPELL_FAILED_ONLY_SHAPESHIFT;
        case 115: return SPELL_FAILED_ONLY_STEALTHED;
        case 116: return SPELL_FAILED_ONLY_UNDERWATER;
        case 117: return SPELL_FAILED_OUT_OF_RANGE;
        case 118: return SPELL_FAILED_PACIFIED;
        case 119: return SPELL_FAILED_POSSESSED;
        case 120: return SPELL_FAILED_REAGENTS;
        case 121: return SPELL_FAILED_REQUIRES_AREA;
        case 122: return SPELL_FAILED_REQUIRES_SPELL_FOCUS;
        case 123: return SPELL_FAILED_ROOTED;
        case 124: return SPELL_FAILED_SILENCED;
        case 125: return SPELL_FAILED_SPELL_IN_PROGRESS;
        case 126: return SPELL_FAILED_SPELL_LEARNED;
        case 127: return SPELL_FAILED_SPELL_UNAVAILABLE;
        case 128: return SPELL_FAILED_STUNNED;
        case 129: return SPELL_FAILED_TARGETS_DEAD;
        case 130: return SPELL_FAILED_TARGET_AFFECTING_COMBAT;
        case 131: return SPELL_FAILED_TARGET_AURASTATE;
        case 132: return SPELL_FAILED_TARGET_DUELING;
        case 133: return SPELL_FAILED_TARGET_ENEMY;
        case 134: return SPELL_FAILED_TARGET_ENRAGED;
        case 135: return SPELL_FAILED_TARGET_FRIENDLY;
        case 136: return SPELL_FAILED_TARGET_IN_COMBAT;
        case 137: return SPELL_FAILED_TARGET_IN_PET_BATTLE;
        case 138: return SPELL_FAILED_TARGET_IS_PLAYER;
        case 139: return SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED;
        case 140: return SPELL_FAILED_TARGET_NOT_DEAD;
        case 141: return SPELL_FAILED_TARGET_NOT_IN_PARTY;
        case 142: return SPELL_FAILED_TARGET_NOT_LOOTED;
        case 143: return SPELL_FAILED_TARGET_NOT_PLAYER;
        case 144: return SPELL_FAILED_TARGET_NO_POCKETS;
        case 145: return SPELL_FAILED_TARGET_NO_WEAPONS;
        case 146: return SPELL_FAILED_TARGET_NO_RANGED_WEAPONS;
        case 147: return SPELL_FAILED_TARGET_UNSKINNABLE;
        case 148: return SPELL_FAILED_THIRST_SATIATED;
        case 149: return SPELL_FAILED_TOO_CLOSE;
        case 150: return SPELL_FAILED_TOO_MANY_OF_ITEM;
        case 151: return SPELL_FAILED_TOTEM_CATEGORY;
        case 152: return SPELL_FAILED_TOTEMS;
        case 153: return SPELL_FAILED_TRY_AGAIN;
        case 154: return SPELL_FAILED_UNIT_NOT_BEHIND;
        case 155: return SPELL_FAILED_UNIT_NOT_INFRONT;
        case 156: return SPELL_FAILED_VISION_OBSCURED;
        case 157: return SPELL_FAILED_WRONG_PET_FOOD;
        case 158: return SPELL_FAILED_NOT_WHILE_FATIGUED;
        case 159: return SPELL_FAILED_TARGET_NOT_IN_INSTANCE;
        case 160: return SPELL_FAILED_NOT_WHILE_TRADING;
        case 161: return SPELL_FAILED_TARGET_NOT_IN_RAID;
        case 162: return SPELL_FAILED_TARGET_FREEFORALL;
        case 163: return SPELL_FAILED_NO_EDIBLE_CORPSES;
        case 164: return SPELL_FAILED_ONLY_BATTLEGROUNDS;
        case 165: return SPELL_FAILED_TARGET_NOT_GHOST;
        case 166: return SPELL_FAILED_TRANSFORM_UNUSABLE;
        case 167: return SPELL_FAILED_WRONG_WEATHER;
        case 168: return SPELL_FAILED_DAMAGE_IMMUNE;
        case 169: return SPELL_FAILED_PREVENTED_BY_MECHANIC;
        case 170: return SPELL_FAILED_PLAY_TIME;
        case 171: return SPELL_FAILED_REPUTATION;
        case 172: return SPELL_FAILED_MIN_SKILL;
        case 173: return SPELL_FAILED_NOT_IN_RATED_BATTLEGROUND;
        case 174: return SPELL_FAILED_NOT_ON_SHAPESHIFT;
        case 175: return SPELL_FAILED_NOT_ON_STEALTHED;
        case 176: return SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE;
        case 177: return SPELL_FAILED_NOT_ON_MOUNTED;
        case 178: return SPELL_FAILED_TOO_SHALLOW;
        case 179: return SPELL_FAILED_TARGET_NOT_IN_SANCTUARY;
        case 180: return SPELL_FAILED_TARGET_IS_TRIVIAL;
        case 181: return SPELL_FAILED_BM_OR_INVISGOD;
        case 182: return SPELL_FAILED_GROUND_MOUNT_NOT_ALLOWED;
        case 183: return SPELL_FAILED_FLOATING_MOUNT_NOT_ALLOWED;
        case 184: return SPELL_FAILED_UNDERWATER_MOUNT_NOT_ALLOWED;
        case 185: return SPELL_FAILED_FLYING_MOUNT_NOT_ALLOWED;
        case 186: return SPELL_FAILED_APPRENTICE_RIDING_REQUIREMENT;
        case 187: return SPELL_FAILED_JOURNEYMAN_RIDING_REQUIREMENT;
        case 188: return SPELL_FAILED_EXPERT_RIDING_REQUIREMENT;
        case 189: return SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT;
        case 190: return SPELL_FAILED_MASTER_RIDING_REQUIREMENT;
        case 191: return SPELL_FAILED_COLD_RIDING_REQUIREMENT;
        case 192: return SPELL_FAILED_FLIGHT_MASTER_RIDING_REQUIREMENT;
        case 193: return SPELL_FAILED_CS_RIDING_REQUIREMENT;
        case 194: return SPELL_FAILED_PANDA_RIDING_REQUIREMENT;
        case 195: return SPELL_FAILED_DRAENOR_RIDING_REQUIREMENT;
        case 196: return SPELL_FAILED_BROKEN_ISLES_RIDING_REQUIREMENT;
        case 197: return SPELL_FAILED_MOUNT_NO_FLOAT_HERE;
        case 198: return SPELL_FAILED_MOUNT_NO_UNDERWATER_HERE;
        case 199: return SPELL_FAILED_MOUNT_ABOVE_WATER_HERE;
        case 200: return SPELL_FAILED_MOUNT_COLLECTED_ON_OTHER_CHAR;
        case 201: return SPELL_FAILED_NOT_IDLE;
        case 202: return SPELL_FAILED_NOT_INACTIVE;
        case 203: return SPELL_FAILED_PARTIAL_PLAYTIME;
        case 204: return SPELL_FAILED_NO_PLAYTIME;
        case 205: return SPELL_FAILED_NOT_IN_BATTLEGROUND;
        case 206: return SPELL_FAILED_NOT_IN_RAID_INSTANCE;
        case 207: return SPELL_FAILED_ONLY_IN_ARENA;
        case 208: return SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE;
        case 209: return SPELL_FAILED_ON_USE_ENCHANT;
        case 210: return SPELL_FAILED_NOT_ON_GROUND;
        case 211: return SPELL_FAILED_CUSTOM_ERROR;
        case 212: return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
        case 213: return SPELL_FAILED_TOO_MANY_SOCKETS;
        case 214: return SPELL_FAILED_INVALID_GLYPH;
        case 215: return SPELL_FAILED_UNIQUE_GLYPH;
        case 216: return SPELL_FAILED_GLYPH_SOCKET_LOCKED;
        case 217: return SPELL_FAILED_GLYPH_EXCLUSIVE_CATEGORY;
        case 218: return SPELL_FAILED_GLYPH_INVALID_SPEC;
        case 219: return SPELL_FAILED_GLYPH_NO_SPEC;
        case 220: return SPELL_FAILED_NO_ACTIVE_GLYPHS;
        case 221: return SPELL_FAILED_NO_VALID_TARGETS;
        case 222: return SPELL_FAILED_ITEM_AT_MAX_CHARGES;
        case 223: return SPELL_FAILED_NOT_IN_BARBERSHOP;
        case 224: return SPELL_FAILED_FISHING_TOO_LOW;
        case 225: return SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW;
        case 226: return SPELL_FAILED_SUMMON_PENDING;
        case 227: return SPELL_FAILED_MAX_SOCKETS;
        case 228: return SPELL_FAILED_PET_CAN_RENAME;
        case 229: return SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED;
        case 230: return SPELL_FAILED_TARGET_HAS_RESURRECT_PENDING;
        case 231: return SPELL_FAILED_NO_ACTIONS;
        case 232: return SPELL_FAILED_CURRENCY_WEIGHT_MISMATCH;
        case 233: return SPELL_FAILED_WEIGHT_NOT_ENOUGH;
        case 234: return SPELL_FAILED_WEIGHT_TOO_MUCH;
        case 235: return SPELL_FAILED_NO_VACANT_SEAT;
        case 236: return SPELL_FAILED_NO_LIQUID;
        case 237: return SPELL_FAILED_ONLY_NOT_SWIMMING;
        case 238: return SPELL_FAILED_BY_NOT_MOVING;
        case 239: return SPELL_FAILED_IN_COMBAT_RES_LIMIT_REACHED;
        case 240: return SPELL_FAILED_NOT_IN_ARENA;
        case 241: return SPELL_FAILED_TARGET_NOT_GROUNDED;
        case 242: return SPELL_FAILED_EXCEEDED_WEEKLY_USAGE;
        case 243: return SPELL_FAILED_NOT_IN_LFG_DUNGEON;
        case 244: return SPELL_FAILED_BAD_TARGET_FILTER;
        case 245: return SPELL_FAILED_NOT_ENOUGH_TARGETS;
        case 246: return SPELL_FAILED_NO_SPEC;
        case 247: return SPELL_FAILED_CANT_ADD_BATTLE_PET;
        case 248: return SPELL_FAILED_CANT_UPGRADE_BATTLE_PET;
        case 249: return SPELL_FAILED_WRONG_BATTLE_PET_TYPE;
        case 250: return SPELL_FAILED_NO_DUNGEON_ENCOUNTER;
        case 251: return SPELL_FAILED_NO_TELEPORT_FROM_DUNGEON;
        case 252: return SPELL_FAILED_MAX_LEVEL_TOO_LOW;
        case 253: return SPELL_FAILED_CANT_REPLACE_ITEM_BONUS;
        case 254: return GRANT_PET_LEVEL_FAIL;
        case 255: return SPELL_FAILED_SKILL_LINE_NOT_KNOWN;
        case 256: return SPELL_FAILED_BLUEPRINT_KNOWN;
        case 257: return SPELL_FAILED_FOLLOWER_KNOWN;
        case 258: return SPELL_FAILED_CANT_OVERRIDE_ENCHANT_VISUAL;
        case 259: return SPELL_FAILED_ITEM_NOT_A_WEAPON;
        case 260: return SPELL_FAILED_SAME_ENCHANT_VISUAL;
        case 261: return SPELL_FAILED_TOY_USE_LIMIT_REACHED;
        case 262: return SPELL_FAILED_TOY_ALREADY_KNOWN;
        case 263: return SPELL_FAILED_SHIPMENTS_FULL;
        case 264: return SPELL_FAILED_NO_SHIPMENTS_FOR_CONTAINER;
        case 265: return SPELL_FAILED_NO_BUILDING_FOR_SHIPMENT;
        case 266: return SPELL_FAILED_NOT_ENOUGH_SHIPMENTS_FOR_CONTAINER;
        case 267: return SPELL_FAILED_HAS_MISSION;
        case 268: return SPELL_FAILED_BUILDING_ACTIVATE_NOT_READY;
        case 269: return SPELL_FAILED_NOT_SOULBOUND;
        case 270: return SPELL_FAILED_RIDING_VEHICLE;
        case 271: return SPELL_FAILED_VETERAN_TRIAL_ABOVE_SKILL_RANK_MAX;
        case 272: return SPELL_FAILED_NOT_WHILE_MERCENARY;
        case 273: return SPELL_FAILED_SPEC_DISABLED;
        case 274: return SPELL_FAILED_CANT_BE_OBLITERATED;
        case 275: return SPELL_FAILED_CANT_BE_SCRAPPED;
        case 276: return SPELL_FAILED_FOLLOWER_CLASS_SPEC_CAP;
        case 277: return SPELL_FAILED_TRANSPORT_NOT_READY;
        case 278: return SPELL_FAILED_TRANSMOG_SET_ALREADY_KNOWN;
        case 279: return SPELL_FAILED_DISABLED_BY_AURA_LABEL;
        case 280: return SPELL_FAILED_DISABLED_BY_MAX_USABLE_LEVEL;
        case 281: return SPELL_FAILED_SPELL_ALREADY_KNOWN;
        case 282: return SPELL_FAILED_MUST_KNOW_SUPERCEDING_SPELL;
        case 283: return SPELL_FAILED_YOU_CANNOT_USE_THAT_IN_PVP_INSTANCE;
        case 284: return SPELL_FAILED_NO_ARTIFACT_EQUIPPED;
        case 285: return SPELL_FAILED_WRONG_ARTIFACT_EQUIPPED;
        case 286: return SPELL_FAILED_TARGET_IS_UNTARGETABLE_BY_ANYONE;
        case 287: return SPELL_FAILED_SPELL_EFFECT_FAILED;
        case 288: return SPELL_FAILED_NEED_ALL_PARTY_MEMBERS;
        case 289: return SPELL_FAILED_ARTIFACT_AT_FULL_POWER;
        case 290: return SPELL_FAILED_AP_ITEM_FROM_PREVIOUS_TIER;
        case 291: return SPELL_FAILED_AREA_TRIGGER_CREATION;
        case 292: return SPELL_FAILED_AZERITE_EMPOWERED_ONLY;
        case 293: return SPELL_FAILED_AZERITE_EMPOWERED_NO_CHOICES_TO_UNDO;
        case 294: return SPELL_FAILED_WRONG_FACTION;
        case 295: return SPELL_FAILED_NOT_ENOUGH_CURRENCY;
        case 296: return SPELL_FAILED_BATTLE_FOR_AZEROTH_RIDING_REQUIREMENT;
        case 297: return SPELL_FAILED_MOUNT_EQUIPMENT_ERROR;
        case 298: return SPELL_FAILED_NOT_WHILE_LEVEL_LINKED;
        case 299: return SPELL_FAILED_LEVEL_LINKED_LOW_LEVEL;
        case 300: return SPELL_FAILED_SUMMON_MAP_CONDITION;
        case 301: return SPELL_FAILED_SET_COVENANT_ERROR;
        case 302: return SPELL_FAILED_RUNEFORGE_LEGENDARY_UPGRADE;
        case 303: return SPELL_FAILED_SET_CHROMIE_TIME_ERROR;
        case 304: return SPELL_FAILED_INELIGIBLE_WEAPON_APPEARANCE;
        case 305: return SPELL_FAILED_PLAYER_CONDITION;
        case 306: return SPELL_FAILED_NOT_WHILE_CHROMIE_TIMED;
        case 307: return SPELL_FAILED_OPTIONAL_REAGENTS;
        case 308: return SPELL_FAILED_SPECTATOR_OR_COMMENTATOR;
        case 309: return SPELL_FAILED_SOULBIND_CONDUIT_LEARN_FAILED_INVALID_COVENANT;
        case 310: return SPELL_FAILED_SHADOWLANDS_RIDING_REQUIREMENT;
        case 311: return SPELL_FAILED_NOT_IN_MAGE_TOWER;
        case 312: return SPELL_FAILED_GARRISON_FOLLOWER_AT_MIN_LEVEL;
        case 313: return SPELL_FAILED_UNKNOWN;
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
        case SPELL_FAILED_ALREADY_HAVE_PET: return 8;
        case SPELL_FAILED_ALREADY_OPEN: return 9;
        case SPELL_FAILED_AURA_BOUNCED: return 10;
        case SPELL_FAILED_AUTOTRACK_INTERRUPTED: return 11;
        case SPELL_FAILED_BAD_IMPLICIT_TARGETS: return 12;
        case SPELL_FAILED_BAD_TARGETS: return 13;
        case SPELL_FAILED_PVP_TARGET_WHILE_UNFLAGGED: return 14;
        case SPELL_FAILED_CANT_BE_CHARMED: return 15;
        case SPELL_FAILED_CANT_BE_DISENCHANTED: return 16;
        case SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL: return 17;
        case SPELL_FAILED_CANT_BE_ENCHANTED: return 18;
        case SPELL_FAILED_CANT_BE_MILLED: return 19;
        case SPELL_FAILED_CANT_BE_PROSPECTED: return 20;
        case SPELL_FAILED_CANT_CAST_ON_TAPPED: return 21;
        case SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE: return 22;
        case SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED: return 23;
        case SPELL_FAILED_CANT_STEALTH: return 24;
        case SPELL_FAILED_CANT_UNTALENT: return 25;
        case SPELL_FAILED_CASTER_AURASTATE: return 26;
        case SPELL_FAILED_CASTER_DEAD: return 27;
        case SPELL_FAILED_CHARMED: return 28;
        case SPELL_FAILED_CHEST_IN_USE: return 29;
        case SPELL_FAILED_CONFUSED: return 30;
        case SPELL_FAILED_DISABLED_BY_POWER_SCALING: return 31;
        case SPELL_FAILED_DONT_REPORT: return 32;
        case SPELL_FAILED_EQUIPPED_ITEM: return 33;
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS: return 34;
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND: return 35;
        case SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND: return 36;
        case SPELL_FAILED_ERROR: return 37;
        case SPELL_FAILED_FALLING: return 38;
        case SPELL_FAILED_FIZZLE: return 39;
        case SPELL_FAILED_FLEEING: return 40;
        case SPELL_FAILED_FOOD_LOWLEVEL: return 41;
        case SPELL_FAILED_GARRISON_NOT_OWNED: return 42;
        case SPELL_FAILED_GARRISON_OWNED: return 43;
        case SPELL_FAILED_GARRISON_MAX_LEVEL: return 44;
        case SPELL_FAILED_GARRISON_NOT_UPGRADEABLE: return 45;
        case SPELL_FAILED_GARRISON_FOLLOWER_ON_MISSION: return 46;
        case SPELL_FAILED_GARRISON_FOLLOWER_IN_BUILDING: return 47;
        case SPELL_FAILED_GARRISON_FOLLOWER_MAX_LEVEL: return 48;
        case SPELL_FAILED_GARRISON_FOLLOWER_MIN_ITEM_LEVEL: return 49;
        case SPELL_FAILED_GARRISON_FOLLOWER_MAX_ITEM_LEVEL: return 50;
        case SPELL_FAILED_GARRISON_FOLLOWER_MAX_QUALITY: return 51;
        case SPELL_FAILED_GARRISON_FOLLOWER_NOT_MAX_LEVEL: return 52;
        case SPELL_FAILED_GARRISON_FOLLOWER_HAS_ABILITY: return 53;
        case SPELL_FAILED_GARRISON_FOLLOWER_HAS_SINGLE_MISSION_ABILITY: return 54;
        case SPELL_FAILED_GARRISON_FOLLOWER_REQUIRES_EPIC: return 55;
        case SPELL_FAILED_GARRISON_MISSION_NOT_IN_PROGRESS: return 56;
        case SPELL_FAILED_GARRISON_MISSION_COMPLETE: return 57;
        case SPELL_FAILED_GARRISON_NO_MISSIONS_AVAILABLE: return 58;
        case SPELL_FAILED_HIGHLEVEL: return 59;
        case SPELL_FAILED_HUNGER_SATIATED: return 60;
        case SPELL_FAILED_IMMUNE: return 61;
        case SPELL_FAILED_INCORRECT_AREA: return 62;
        case SPELL_FAILED_INTERRUPTED: return 63;
        case SPELL_FAILED_INTERRUPTED_COMBAT: return 64;
        case SPELL_FAILED_ITEM_ALREADY_ENCHANTED: return 65;
        case SPELL_FAILED_ITEM_GONE: return 66;
        case SPELL_FAILED_ITEM_NOT_FOUND: return 67;
        case SPELL_FAILED_ITEM_NOT_READY: return 68;
        case SPELL_FAILED_LEVEL_REQUIREMENT: return 69;
        case SPELL_FAILED_LINE_OF_SIGHT: return 70;
        case SPELL_FAILED_LOWLEVEL: return 71;
        case SPELL_FAILED_LOW_CASTLEVEL: return 72;
        case SPELL_FAILED_MAINHAND_EMPTY: return 73;
        case SPELL_FAILED_MOVING: return 74;
        case SPELL_FAILED_NEED_AMMO: return 75;
        case SPELL_FAILED_NEED_AMMO_POUCH: return 76;
        case SPELL_FAILED_NEED_EXOTIC_AMMO: return 77;
        case SPELL_FAILED_NEED_MORE_ITEMS: return 78;
        case SPELL_FAILED_NOPATH: return 79;
        case SPELL_FAILED_NOT_BEHIND: return 80;
        case SPELL_FAILED_NOT_FISHABLE: return 81;
        case SPELL_FAILED_NOT_FLYING: return 82;
        case SPELL_FAILED_NOT_HERE: return 83;
        case SPELL_FAILED_NOT_INFRONT: return 84;
        case SPELL_FAILED_NOT_IN_CONTROL: return 85;
        case SPELL_FAILED_NOT_KNOWN: return 86;
        case SPELL_FAILED_NOT_MOUNTED: return 87;
        case SPELL_FAILED_NOT_ON_TAXI: return 88;
        case SPELL_FAILED_NOT_ON_TRANSPORT: return 89;
        case SPELL_FAILED_NOT_READY: return 90;
        case SPELL_FAILED_NOT_SHAPESHIFT: return 91;
        case SPELL_FAILED_NOT_STANDING: return 92;
        case SPELL_FAILED_NOT_TRADEABLE: return 93;
        case SPELL_FAILED_NOT_TRADING: return 94;
        case SPELL_FAILED_NOT_UNSHEATHED: return 95;
        case SPELL_FAILED_NOT_WHILE_GHOST: return 96;
        case SPELL_FAILED_NOT_WHILE_LOOTING: return 97;
        case SPELL_FAILED_NO_AMMO: return 98;
        case SPELL_FAILED_NO_CHARGES_REMAIN: return 99;
        case SPELL_FAILED_NO_COMBO_POINTS: return 100;
        case SPELL_FAILED_NO_DUELING: return 101;
        case SPELL_FAILED_NO_ENDURANCE: return 102;
        case SPELL_FAILED_NO_FISH: return 103;
        case SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED: return 104;
        case SPELL_FAILED_NO_MOUNTS_ALLOWED: return 105;
        case SPELL_FAILED_NO_PET: return 106;
        case SPELL_FAILED_NO_POWER: return 107;
        case SPELL_FAILED_NOTHING_TO_DISPEL: return 108;
        case SPELL_FAILED_NOTHING_TO_STEAL: return 109;
        case SPELL_FAILED_ONLY_ABOVEWATER: return 110;
        case SPELL_FAILED_ONLY_INDOORS: return 111;
        case SPELL_FAILED_ONLY_MOUNTED: return 112;
        case SPELL_FAILED_ONLY_OUTDOORS: return 113;
        case SPELL_FAILED_ONLY_SHAPESHIFT: return 114;
        case SPELL_FAILED_ONLY_STEALTHED: return 115;
        case SPELL_FAILED_ONLY_UNDERWATER: return 116;
        case SPELL_FAILED_OUT_OF_RANGE: return 117;
        case SPELL_FAILED_PACIFIED: return 118;
        case SPELL_FAILED_POSSESSED: return 119;
        case SPELL_FAILED_REAGENTS: return 120;
        case SPELL_FAILED_REQUIRES_AREA: return 121;
        case SPELL_FAILED_REQUIRES_SPELL_FOCUS: return 122;
        case SPELL_FAILED_ROOTED: return 123;
        case SPELL_FAILED_SILENCED: return 124;
        case SPELL_FAILED_SPELL_IN_PROGRESS: return 125;
        case SPELL_FAILED_SPELL_LEARNED: return 126;
        case SPELL_FAILED_SPELL_UNAVAILABLE: return 127;
        case SPELL_FAILED_STUNNED: return 128;
        case SPELL_FAILED_TARGETS_DEAD: return 129;
        case SPELL_FAILED_TARGET_AFFECTING_COMBAT: return 130;
        case SPELL_FAILED_TARGET_AURASTATE: return 131;
        case SPELL_FAILED_TARGET_DUELING: return 132;
        case SPELL_FAILED_TARGET_ENEMY: return 133;
        case SPELL_FAILED_TARGET_ENRAGED: return 134;
        case SPELL_FAILED_TARGET_FRIENDLY: return 135;
        case SPELL_FAILED_TARGET_IN_COMBAT: return 136;
        case SPELL_FAILED_TARGET_IN_PET_BATTLE: return 137;
        case SPELL_FAILED_TARGET_IS_PLAYER: return 138;
        case SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED: return 139;
        case SPELL_FAILED_TARGET_NOT_DEAD: return 140;
        case SPELL_FAILED_TARGET_NOT_IN_PARTY: return 141;
        case SPELL_FAILED_TARGET_NOT_LOOTED: return 142;
        case SPELL_FAILED_TARGET_NOT_PLAYER: return 143;
        case SPELL_FAILED_TARGET_NO_POCKETS: return 144;
        case SPELL_FAILED_TARGET_NO_WEAPONS: return 145;
        case SPELL_FAILED_TARGET_NO_RANGED_WEAPONS: return 146;
        case SPELL_FAILED_TARGET_UNSKINNABLE: return 147;
        case SPELL_FAILED_THIRST_SATIATED: return 148;
        case SPELL_FAILED_TOO_CLOSE: return 149;
        case SPELL_FAILED_TOO_MANY_OF_ITEM: return 150;
        case SPELL_FAILED_TOTEM_CATEGORY: return 151;
        case SPELL_FAILED_TOTEMS: return 152;
        case SPELL_FAILED_TRY_AGAIN: return 153;
        case SPELL_FAILED_UNIT_NOT_BEHIND: return 154;
        case SPELL_FAILED_UNIT_NOT_INFRONT: return 155;
        case SPELL_FAILED_VISION_OBSCURED: return 156;
        case SPELL_FAILED_WRONG_PET_FOOD: return 157;
        case SPELL_FAILED_NOT_WHILE_FATIGUED: return 158;
        case SPELL_FAILED_TARGET_NOT_IN_INSTANCE: return 159;
        case SPELL_FAILED_NOT_WHILE_TRADING: return 160;
        case SPELL_FAILED_TARGET_NOT_IN_RAID: return 161;
        case SPELL_FAILED_TARGET_FREEFORALL: return 162;
        case SPELL_FAILED_NO_EDIBLE_CORPSES: return 163;
        case SPELL_FAILED_ONLY_BATTLEGROUNDS: return 164;
        case SPELL_FAILED_TARGET_NOT_GHOST: return 165;
        case SPELL_FAILED_TRANSFORM_UNUSABLE: return 166;
        case SPELL_FAILED_WRONG_WEATHER: return 167;
        case SPELL_FAILED_DAMAGE_IMMUNE: return 168;
        case SPELL_FAILED_PREVENTED_BY_MECHANIC: return 169;
        case SPELL_FAILED_PLAY_TIME: return 170;
        case SPELL_FAILED_REPUTATION: return 171;
        case SPELL_FAILED_MIN_SKILL: return 172;
        case SPELL_FAILED_NOT_IN_RATED_BATTLEGROUND: return 173;
        case SPELL_FAILED_NOT_ON_SHAPESHIFT: return 174;
        case SPELL_FAILED_NOT_ON_STEALTHED: return 175;
        case SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE: return 176;
        case SPELL_FAILED_NOT_ON_MOUNTED: return 177;
        case SPELL_FAILED_TOO_SHALLOW: return 178;
        case SPELL_FAILED_TARGET_NOT_IN_SANCTUARY: return 179;
        case SPELL_FAILED_TARGET_IS_TRIVIAL: return 180;
        case SPELL_FAILED_BM_OR_INVISGOD: return 181;
        case SPELL_FAILED_GROUND_MOUNT_NOT_ALLOWED: return 182;
        case SPELL_FAILED_FLOATING_MOUNT_NOT_ALLOWED: return 183;
        case SPELL_FAILED_UNDERWATER_MOUNT_NOT_ALLOWED: return 184;
        case SPELL_FAILED_FLYING_MOUNT_NOT_ALLOWED: return 185;
        case SPELL_FAILED_APPRENTICE_RIDING_REQUIREMENT: return 186;
        case SPELL_FAILED_JOURNEYMAN_RIDING_REQUIREMENT: return 187;
        case SPELL_FAILED_EXPERT_RIDING_REQUIREMENT: return 188;
        case SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT: return 189;
        case SPELL_FAILED_MASTER_RIDING_REQUIREMENT: return 190;
        case SPELL_FAILED_COLD_RIDING_REQUIREMENT: return 191;
        case SPELL_FAILED_FLIGHT_MASTER_RIDING_REQUIREMENT: return 192;
        case SPELL_FAILED_CS_RIDING_REQUIREMENT: return 193;
        case SPELL_FAILED_PANDA_RIDING_REQUIREMENT: return 194;
        case SPELL_FAILED_DRAENOR_RIDING_REQUIREMENT: return 195;
        case SPELL_FAILED_BROKEN_ISLES_RIDING_REQUIREMENT: return 196;
        case SPELL_FAILED_MOUNT_NO_FLOAT_HERE: return 197;
        case SPELL_FAILED_MOUNT_NO_UNDERWATER_HERE: return 198;
        case SPELL_FAILED_MOUNT_ABOVE_WATER_HERE: return 199;
        case SPELL_FAILED_MOUNT_COLLECTED_ON_OTHER_CHAR: return 200;
        case SPELL_FAILED_NOT_IDLE: return 201;
        case SPELL_FAILED_NOT_INACTIVE: return 202;
        case SPELL_FAILED_PARTIAL_PLAYTIME: return 203;
        case SPELL_FAILED_NO_PLAYTIME: return 204;
        case SPELL_FAILED_NOT_IN_BATTLEGROUND: return 205;
        case SPELL_FAILED_NOT_IN_RAID_INSTANCE: return 206;
        case SPELL_FAILED_ONLY_IN_ARENA: return 207;
        case SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE: return 208;
        case SPELL_FAILED_ON_USE_ENCHANT: return 209;
        case SPELL_FAILED_NOT_ON_GROUND: return 210;
        case SPELL_FAILED_CUSTOM_ERROR: return 211;
        case SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW: return 212;
        case SPELL_FAILED_TOO_MANY_SOCKETS: return 213;
        case SPELL_FAILED_INVALID_GLYPH: return 214;
        case SPELL_FAILED_UNIQUE_GLYPH: return 215;
        case SPELL_FAILED_GLYPH_SOCKET_LOCKED: return 216;
        case SPELL_FAILED_GLYPH_EXCLUSIVE_CATEGORY: return 217;
        case SPELL_FAILED_GLYPH_INVALID_SPEC: return 218;
        case SPELL_FAILED_GLYPH_NO_SPEC: return 219;
        case SPELL_FAILED_NO_ACTIVE_GLYPHS: return 220;
        case SPELL_FAILED_NO_VALID_TARGETS: return 221;
        case SPELL_FAILED_ITEM_AT_MAX_CHARGES: return 222;
        case SPELL_FAILED_NOT_IN_BARBERSHOP: return 223;
        case SPELL_FAILED_FISHING_TOO_LOW: return 224;
        case SPELL_FAILED_ITEM_ENCHANT_TRADE_WINDOW: return 225;
        case SPELL_FAILED_SUMMON_PENDING: return 226;
        case SPELL_FAILED_MAX_SOCKETS: return 227;
        case SPELL_FAILED_PET_CAN_RENAME: return 228;
        case SPELL_FAILED_TARGET_CANNOT_BE_RESURRECTED: return 229;
        case SPELL_FAILED_TARGET_HAS_RESURRECT_PENDING: return 230;
        case SPELL_FAILED_NO_ACTIONS: return 231;
        case SPELL_FAILED_CURRENCY_WEIGHT_MISMATCH: return 232;
        case SPELL_FAILED_WEIGHT_NOT_ENOUGH: return 233;
        case SPELL_FAILED_WEIGHT_TOO_MUCH: return 234;
        case SPELL_FAILED_NO_VACANT_SEAT: return 235;
        case SPELL_FAILED_NO_LIQUID: return 236;
        case SPELL_FAILED_ONLY_NOT_SWIMMING: return 237;
        case SPELL_FAILED_BY_NOT_MOVING: return 238;
        case SPELL_FAILED_IN_COMBAT_RES_LIMIT_REACHED: return 239;
        case SPELL_FAILED_NOT_IN_ARENA: return 240;
        case SPELL_FAILED_TARGET_NOT_GROUNDED: return 241;
        case SPELL_FAILED_EXCEEDED_WEEKLY_USAGE: return 242;
        case SPELL_FAILED_NOT_IN_LFG_DUNGEON: return 243;
        case SPELL_FAILED_BAD_TARGET_FILTER: return 244;
        case SPELL_FAILED_NOT_ENOUGH_TARGETS: return 245;
        case SPELL_FAILED_NO_SPEC: return 246;
        case SPELL_FAILED_CANT_ADD_BATTLE_PET: return 247;
        case SPELL_FAILED_CANT_UPGRADE_BATTLE_PET: return 248;
        case SPELL_FAILED_WRONG_BATTLE_PET_TYPE: return 249;
        case SPELL_FAILED_NO_DUNGEON_ENCOUNTER: return 250;
        case SPELL_FAILED_NO_TELEPORT_FROM_DUNGEON: return 251;
        case SPELL_FAILED_MAX_LEVEL_TOO_LOW: return 252;
        case SPELL_FAILED_CANT_REPLACE_ITEM_BONUS: return 253;
        case GRANT_PET_LEVEL_FAIL: return 254;
        case SPELL_FAILED_SKILL_LINE_NOT_KNOWN: return 255;
        case SPELL_FAILED_BLUEPRINT_KNOWN: return 256;
        case SPELL_FAILED_FOLLOWER_KNOWN: return 257;
        case SPELL_FAILED_CANT_OVERRIDE_ENCHANT_VISUAL: return 258;
        case SPELL_FAILED_ITEM_NOT_A_WEAPON: return 259;
        case SPELL_FAILED_SAME_ENCHANT_VISUAL: return 260;
        case SPELL_FAILED_TOY_USE_LIMIT_REACHED: return 261;
        case SPELL_FAILED_TOY_ALREADY_KNOWN: return 262;
        case SPELL_FAILED_SHIPMENTS_FULL: return 263;
        case SPELL_FAILED_NO_SHIPMENTS_FOR_CONTAINER: return 264;
        case SPELL_FAILED_NO_BUILDING_FOR_SHIPMENT: return 265;
        case SPELL_FAILED_NOT_ENOUGH_SHIPMENTS_FOR_CONTAINER: return 266;
        case SPELL_FAILED_HAS_MISSION: return 267;
        case SPELL_FAILED_BUILDING_ACTIVATE_NOT_READY: return 268;
        case SPELL_FAILED_NOT_SOULBOUND: return 269;
        case SPELL_FAILED_RIDING_VEHICLE: return 270;
        case SPELL_FAILED_VETERAN_TRIAL_ABOVE_SKILL_RANK_MAX: return 271;
        case SPELL_FAILED_NOT_WHILE_MERCENARY: return 272;
        case SPELL_FAILED_SPEC_DISABLED: return 273;
        case SPELL_FAILED_CANT_BE_OBLITERATED: return 274;
        case SPELL_FAILED_CANT_BE_SCRAPPED: return 275;
        case SPELL_FAILED_FOLLOWER_CLASS_SPEC_CAP: return 276;
        case SPELL_FAILED_TRANSPORT_NOT_READY: return 277;
        case SPELL_FAILED_TRANSMOG_SET_ALREADY_KNOWN: return 278;
        case SPELL_FAILED_DISABLED_BY_AURA_LABEL: return 279;
        case SPELL_FAILED_DISABLED_BY_MAX_USABLE_LEVEL: return 280;
        case SPELL_FAILED_SPELL_ALREADY_KNOWN: return 281;
        case SPELL_FAILED_MUST_KNOW_SUPERCEDING_SPELL: return 282;
        case SPELL_FAILED_YOU_CANNOT_USE_THAT_IN_PVP_INSTANCE: return 283;
        case SPELL_FAILED_NO_ARTIFACT_EQUIPPED: return 284;
        case SPELL_FAILED_WRONG_ARTIFACT_EQUIPPED: return 285;
        case SPELL_FAILED_TARGET_IS_UNTARGETABLE_BY_ANYONE: return 286;
        case SPELL_FAILED_SPELL_EFFECT_FAILED: return 287;
        case SPELL_FAILED_NEED_ALL_PARTY_MEMBERS: return 288;
        case SPELL_FAILED_ARTIFACT_AT_FULL_POWER: return 289;
        case SPELL_FAILED_AP_ITEM_FROM_PREVIOUS_TIER: return 290;
        case SPELL_FAILED_AREA_TRIGGER_CREATION: return 291;
        case SPELL_FAILED_AZERITE_EMPOWERED_ONLY: return 292;
        case SPELL_FAILED_AZERITE_EMPOWERED_NO_CHOICES_TO_UNDO: return 293;
        case SPELL_FAILED_WRONG_FACTION: return 294;
        case SPELL_FAILED_NOT_ENOUGH_CURRENCY: return 295;
        case SPELL_FAILED_BATTLE_FOR_AZEROTH_RIDING_REQUIREMENT: return 296;
        case SPELL_FAILED_MOUNT_EQUIPMENT_ERROR: return 297;
        case SPELL_FAILED_NOT_WHILE_LEVEL_LINKED: return 298;
        case SPELL_FAILED_LEVEL_LINKED_LOW_LEVEL: return 299;
        case SPELL_FAILED_SUMMON_MAP_CONDITION: return 300;
        case SPELL_FAILED_SET_COVENANT_ERROR: return 301;
        case SPELL_FAILED_RUNEFORGE_LEGENDARY_UPGRADE: return 302;
        case SPELL_FAILED_SET_CHROMIE_TIME_ERROR: return 303;
        case SPELL_FAILED_INELIGIBLE_WEAPON_APPEARANCE: return 304;
        case SPELL_FAILED_PLAYER_CONDITION: return 305;
        case SPELL_FAILED_NOT_WHILE_CHROMIE_TIMED: return 306;
        case SPELL_FAILED_OPTIONAL_REAGENTS: return 307;
        case SPELL_FAILED_SPECTATOR_OR_COMMENTATOR: return 308;
        case SPELL_FAILED_SOULBIND_CONDUIT_LEARN_FAILED_INVALID_COVENANT: return 309;
        case SPELL_FAILED_SHADOWLANDS_RIDING_REQUIREMENT: return 310;
        case SPELL_FAILED_NOT_IN_MAGE_TOWER: return 311;
        case SPELL_FAILED_GARRISON_FOLLOWER_AT_MIN_LEVEL: return 312;
        case SPELL_FAILED_UNKNOWN: return 313;
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
        case AURA_STATE_DEFENSIVE: return { "AURA_STATE_DEFENSIVE", "AURA_STATE_DEFENSIVE", "CcTt|" };
        case AURA_STATE_WOUNDED_20_PERCENT: return { "AURA_STATE_WOUNDED_20_PERCENT", "AURA_STATE_WOUNDED_20_PERCENT", "CcT |" };
        case AURA_STATE_UNBALANCED: return { "AURA_STATE_UNBALANCED", "AURA_STATE_UNBALANCED", "CcT | NYI" };
        case AURA_STATE_FROZEN: return { "AURA_STATE_FROZEN", "AURA_STATE_FROZEN", "c t|" };
        case AURA_STATE_MARKED: return { "AURA_STATE_MARKED", "AURA_STATE_MARKED", "C  t| NYI" };
        case AURA_STATE_WOUNDED_25_PERCENT: return { "AURA_STATE_WOUNDED_25_PERCENT", "AURA_STATE_WOUNDED_25_PERCENT", "T |" };
        case AURA_STATE_DEFENSIVE_2: return { "AURA_STATE_DEFENSIVE_2", "AURA_STATE_DEFENSIVE_2", "Cc  | NYI" };
        case AURA_STATE_BANISHED: return { "AURA_STATE_BANISHED", "AURA_STATE_BANISHED", "c  | NYI" };
        case AURA_STATE_DAZED: return { "AURA_STATE_DAZED", "AURA_STATE_DAZED", "t|" };
        case AURA_STATE_VICTORIOUS: return { "AURA_STATE_VICTORIOUS", "AURA_STATE_VICTORIOUS", "C   |" };
        case AURA_STATE_RAMPAGE: return { "AURA_STATE_RAMPAGE", "AURA_STATE_RAMPAGE", "| NYI" };
        case AURA_STATE_FAERIE_FIRE: return { "AURA_STATE_FAERIE_FIRE", "AURA_STATE_FAERIE_FIRE", "c t|" };
        case AURA_STATE_WOUNDED_35_PERCENT: return { "AURA_STATE_WOUNDED_35_PERCENT", "AURA_STATE_WOUNDED_35_PERCENT", "CcT |" };
        case AURA_STATE_RAID_ENCOUNTER_2: return { "AURA_STATE_RAID_ENCOUNTER_2", "AURA_STATE_RAID_ENCOUNTER_2", "cT |" };
        case AURA_STATE_DRUID_PERIODIC_HEAL: return { "AURA_STATE_DRUID_PERIODIC_HEAL", "AURA_STATE_DRUID_PERIODIC_HEAL", "T |" };
        case AURA_STATE_ROGUE_POISONED: return { "AURA_STATE_ROGUE_POISONED", "AURA_STATE_ROGUE_POISONED", "|" };
        case AURA_STATE_ENRAGED: return { "AURA_STATE_ENRAGED", "AURA_STATE_ENRAGED", "C   |" };
        case AURA_STATE_BLEED: return { "AURA_STATE_BLEED", "AURA_STATE_BLEED", "T |" };
        case AURA_STATE_VULNERABLE: return { "AURA_STATE_VULNERABLE", "AURA_STATE_VULNERABLE", "| NYI" };
        case AURA_STATE_ARENA_PREPARATION: return { "AURA_STATE_ARENA_PREPARATION", "AURA_STATE_ARENA_PREPARATION", "c  |" };
        case AURA_STATE_WOUND_HEALTH_20_80: return { "AURA_STATE_WOUND_HEALTH_20_80", "AURA_STATE_WOUND_HEALTH_20_80", "T |" };
        case AURA_STATE_RAID_ENCOUNTER: return { "AURA_STATE_RAID_ENCOUNTER", "AURA_STATE_RAID_ENCOUNTER", "CcTt|" };
        case AURA_STATE_HEALTHY_75_PERCENT: return { "AURA_STATE_HEALTHY_75_PERCENT", "AURA_STATE_HEALTHY_75_PERCENT", "C   |" };
        case AURA_STATE_WOUND_HEALTH_35_80: return { "AURA_STATE_WOUND_HEALTH_35_80", "AURA_STATE_WOUND_HEALTH_35_80", "T |" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<AuraStateType>::Count() { return 25; }

template <>
TC_API_EXPORT AuraStateType EnumUtils<AuraStateType>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return AURA_STATE_NONE;
        case 1: return AURA_STATE_DEFENSIVE;
        case 2: return AURA_STATE_WOUNDED_20_PERCENT;
        case 3: return AURA_STATE_UNBALANCED;
        case 4: return AURA_STATE_FROZEN;
        case 5: return AURA_STATE_MARKED;
        case 6: return AURA_STATE_WOUNDED_25_PERCENT;
        case 7: return AURA_STATE_DEFENSIVE_2;
        case 8: return AURA_STATE_BANISHED;
        case 9: return AURA_STATE_DAZED;
        case 10: return AURA_STATE_VICTORIOUS;
        case 11: return AURA_STATE_RAMPAGE;
        case 12: return AURA_STATE_FAERIE_FIRE;
        case 13: return AURA_STATE_WOUNDED_35_PERCENT;
        case 14: return AURA_STATE_RAID_ENCOUNTER_2;
        case 15: return AURA_STATE_DRUID_PERIODIC_HEAL;
        case 16: return AURA_STATE_ROGUE_POISONED;
        case 17: return AURA_STATE_ENRAGED;
        case 18: return AURA_STATE_BLEED;
        case 19: return AURA_STATE_VULNERABLE;
        case 20: return AURA_STATE_ARENA_PREPARATION;
        case 21: return AURA_STATE_WOUND_HEALTH_20_80;
        case 22: return AURA_STATE_RAID_ENCOUNTER;
        case 23: return AURA_STATE_HEALTHY_75_PERCENT;
        case 24: return AURA_STATE_WOUND_HEALTH_35_80;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<AuraStateType>::ToIndex(AuraStateType value)
{
    switch (value)
    {
        case AURA_STATE_NONE: return 0;
        case AURA_STATE_DEFENSIVE: return 1;
        case AURA_STATE_WOUNDED_20_PERCENT: return 2;
        case AURA_STATE_UNBALANCED: return 3;
        case AURA_STATE_FROZEN: return 4;
        case AURA_STATE_MARKED: return 5;
        case AURA_STATE_WOUNDED_25_PERCENT: return 6;
        case AURA_STATE_DEFENSIVE_2: return 7;
        case AURA_STATE_BANISHED: return 8;
        case AURA_STATE_DAZED: return 9;
        case AURA_STATE_VICTORIOUS: return 10;
        case AURA_STATE_RAMPAGE: return 11;
        case AURA_STATE_FAERIE_FIRE: return 12;
        case AURA_STATE_WOUNDED_35_PERCENT: return 13;
        case AURA_STATE_RAID_ENCOUNTER_2: return 14;
        case AURA_STATE_DRUID_PERIODIC_HEAL: return 15;
        case AURA_STATE_ROGUE_POISONED: return 16;
        case AURA_STATE_ENRAGED: return 17;
        case AURA_STATE_BLEED: return 18;
        case AURA_STATE_VULNERABLE: return 19;
        case AURA_STATE_ARENA_PREPARATION: return 20;
        case AURA_STATE_WOUND_HEALTH_20_80: return 21;
        case AURA_STATE_RAID_ENCOUNTER: return 22;
        case AURA_STATE_HEALTHY_75_PERCENT: return 23;
        case AURA_STATE_WOUND_HEALTH_35_80: return 24;
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
        case MECHANIC_WOUNDED: return { "MECHANIC_WOUNDED", "MECHANIC_WOUNDED", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Mechanics>::Count() { return 33; }

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
        case 32: return MECHANIC_WOUNDED;
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
        case MECHANIC_WOUNDED: return 32;
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
        case SPELL_PREVENTION_TYPE_NO_ACTIONS: return { "SPELL_PREVENTION_TYPE_NO_ACTIONS", "No actions", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellPreventionType>::Count() { return 4; }

template <>
TC_API_EXPORT SpellPreventionType EnumUtils<SpellPreventionType>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_PREVENTION_TYPE_NONE;
        case 1: return SPELL_PREVENTION_TYPE_SILENCE;
        case 2: return SPELL_PREVENTION_TYPE_PACIFY;
        case 3: return SPELL_PREVENTION_TYPE_NO_ACTIONS;
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
        case SPELL_PREVENTION_TYPE_NO_ACTIONS: return 3;
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
        case EMOTE_STATE_STRANGULATE2: return { "EMOTE_STATE_STRANGULATE2", "EMOTE_STATE_STRANGULATE2", "" };
        case EMOTE_STATE_READY_SPELL_OMNI: return { "EMOTE_STATE_READY_SPELL_OMNI", "EMOTE_STATE_READY_SPELL_OMNI", "" };
        case EMOTE_STATE_HOLD_JOUST: return { "EMOTE_STATE_HOLD_JOUST", "EMOTE_STATE_HOLD_JOUST", "" };
        case EMOTE_ONESHOT_CRY_JAINA: return { "EMOTE_ONESHOT_CRY_JAINA", "EMOTE_ONESHOT_CRY_JAINA", "" };
        case EMOTE_ONESHOT_SPECIAL_UNARMED: return { "EMOTE_ONESHOT_SPECIAL_UNARMED", "EMOTE_ONESHOT_SPECIAL_UNARMED", "" };
        case EMOTE_STATE_DANCE_NOSHEATHE: return { "EMOTE_STATE_DANCE_NOSHEATHE", "EMOTE_STATE_DANCE_NOSHEATHE", "" };
        case EMOTE_ONESHOT_SNIFF: return { "EMOTE_ONESHOT_SNIFF", "EMOTE_ONESHOT_SNIFF", "" };
        case EMOTE_ONESHOT_DRAGONSTOMP: return { "EMOTE_ONESHOT_DRAGONSTOMP", "EMOTE_ONESHOT_DRAGONSTOMP", "" };
        case EMOTE_ONESHOT_KNOCKDOWN: return { "EMOTE_ONESHOT_KNOCKDOWN", "EMOTE_ONESHOT_KNOCKDOWN", "" };
        case EMOTE_STATE_READ: return { "EMOTE_STATE_READ", "EMOTE_STATE_READ", "" };
        case EMOTE_ONESHOT_FLYEMOTETALK: return { "EMOTE_ONESHOT_FLYEMOTETALK", "EMOTE_ONESHOT_FLYEMOTETALK", "" };
        case EMOTE_STATE_READ_ALLOWMOVEMENT: return { "EMOTE_STATE_READ_ALLOWMOVEMENT", "EMOTE_STATE_READ_ALLOWMOVEMENT", "" };
        case EMOTE_STATE_CUSTOM_SPELL_06: return { "EMOTE_STATE_CUSTOM_SPELL_06", "EMOTE_STATE_CUSTOM_SPELL_06", "" };
        case EMOTE_STATE_CUSTOM_SPELL_07: return { "EMOTE_STATE_CUSTOM_SPELL_07", "EMOTE_STATE_CUSTOM_SPELL_07", "" };
        case EMOTE_STATE_CUSTOM_SPELL_08_2: return { "EMOTE_STATE_CUSTOM_SPELL_08_2", "EMOTE_STATE_CUSTOM_SPELL_08_2", "" };
        case EMOTE_STATE_CUSTOM_SPELL_09: return { "EMOTE_STATE_CUSTOM_SPELL_09", "EMOTE_STATE_CUSTOM_SPELL_09", "" };
        case EMOTE_STATE_CUSTOM_SPELL_10: return { "EMOTE_STATE_CUSTOM_SPELL_10", "EMOTE_STATE_CUSTOM_SPELL_10", "" };
        case EMOTE_STATE_READY1H_ALLOW_MOVEMENT: return { "EMOTE_STATE_READY1H_ALLOW_MOVEMENT", "EMOTE_STATE_READY1H_ALLOW_MOVEMENT", "" };
        case EMOTE_STATE_READY2H_ALLOW_MOVEMENT: return { "EMOTE_STATE_READY2H_ALLOW_MOVEMENT", "EMOTE_STATE_READY2H_ALLOW_MOVEMENT", "" };
        case EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMED: return { "EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMED", "EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMED", "" };
        case EMOTE_ONESHOT_MONKOFFENSE_SPECIALUNARMED: return { "EMOTE_ONESHOT_MONKOFFENSE_SPECIALUNARMED", "EMOTE_ONESHOT_MONKOFFENSE_SPECIALUNARMED", "" };
        case EMOTE_ONESHOT_MONKOFFENSE_PARRYUNARMED: return { "EMOTE_ONESHOT_MONKOFFENSE_PARRYUNARMED", "EMOTE_ONESHOT_MONKOFFENSE_PARRYUNARMED", "" };
        case EMOTE_STATE_MONKOFFENSE_READYUNARMED: return { "EMOTE_STATE_MONKOFFENSE_READYUNARMED", "EMOTE_STATE_MONKOFFENSE_READYUNARMED", "" };
        case EMOTE_ONESHOT_PALMSTRIKE: return { "EMOTE_ONESHOT_PALMSTRIKE", "EMOTE_ONESHOT_PALMSTRIKE", "" };
        case EMOTE_STATE_CRANE: return { "EMOTE_STATE_CRANE", "EMOTE_STATE_CRANE", "" };
        case EMOTE_ONESHOT_OPEN: return { "EMOTE_ONESHOT_OPEN", "EMOTE_ONESHOT_OPEN", "" };
        case EMOTE_STATE_READ_CHRISTMAS: return { "EMOTE_STATE_READ_CHRISTMAS", "EMOTE_STATE_READ_CHRISTMAS", "" };
        case EMOTE_ONESHOT_FLYATTACK2HL: return { "EMOTE_ONESHOT_FLYATTACK2HL", "EMOTE_ONESHOT_FLYATTACK2HL", "" };
        case EMOTE_ONESHOT_FLYATTACKTHROWN: return { "EMOTE_ONESHOT_FLYATTACKTHROWN", "EMOTE_ONESHOT_FLYATTACKTHROWN", "" };
        case EMOTE_STATE_FLYREADYSPELLDIRECTED: return { "EMOTE_STATE_FLYREADYSPELLDIRECTED", "EMOTE_STATE_FLYREADYSPELLDIRECTED", "" };
        case EMOTE_STATE_FLY_READY_1H: return { "EMOTE_STATE_FLY_READY_1H", "EMOTE_STATE_FLY_READY_1H", "" };
        case EMOTE_STATE_MEDITATE: return { "EMOTE_STATE_MEDITATE", "EMOTE_STATE_MEDITATE", "" };
        case EMOTE_STATE_FLY_READY_2HL: return { "EMOTE_STATE_FLY_READY_2HL", "EMOTE_STATE_FLY_READY_2HL", "" };
        case EMOTE_ONESHOT_TOGROUND: return { "EMOTE_ONESHOT_TOGROUND", "EMOTE_ONESHOT_TOGROUND", "" };
        case EMOTE_ONESHOT_TOFLY: return { "EMOTE_ONESHOT_TOFLY", "EMOTE_ONESHOT_TOFLY", "" };
        case EMOTE_STATE_ATTACKTHROWN: return { "EMOTE_STATE_ATTACKTHROWN", "EMOTE_STATE_ATTACKTHROWN", "" };
        case EMOTE_STATE_SPELL_CHANNEL_DIRECTED_NOSOUND: return { "EMOTE_STATE_SPELL_CHANNEL_DIRECTED_NOSOUND", "EMOTE_STATE_SPELL_CHANNEL_DIRECTED_NOSOUND", "" };
        case EMOTE_ONESHOT_WORK: return { "EMOTE_ONESHOT_WORK", "EMOTE_ONESHOT_WORK", "" };
        case EMOTE_STATE_READYUNARMED_NOSOUND: return { "EMOTE_STATE_READYUNARMED_NOSOUND", "EMOTE_STATE_READYUNARMED_NOSOUND", "" };
        case EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMEDOFF: return { "EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMEDOFF", "EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMEDOFF", "" };
        case EMOTE_RECLINED_MOUNT_PASSENGER: return { "EMOTE_RECLINED_MOUNT_PASSENGER", "EMOTE_RECLINED_MOUNT_PASSENGER", "" };
        case EMOTE_ONESHOT_QUESTION_2: return { "EMOTE_ONESHOT_QUESTION_2", "EMOTE_ONESHOT_QUESTION_2", "" };
        case EMOTE_ONESHOT_SPELL_CHANNEL_DIRECTED_NOSOUND: return { "EMOTE_ONESHOT_SPELL_CHANNEL_DIRECTED_NOSOUND", "EMOTE_ONESHOT_SPELL_CHANNEL_DIRECTED_NOSOUND", "" };
        case EMOTE_STATE_KNEEL_2: return { "EMOTE_STATE_KNEEL_2", "EMOTE_STATE_KNEEL_2", "" };
        case EMOTE_ONESHOT_FLYATTACKUNARMED: return { "EMOTE_ONESHOT_FLYATTACKUNARMED", "EMOTE_ONESHOT_FLYATTACKUNARMED", "" };
        case EMOTE_ONESHOT_FLYCOMBATWOUND: return { "EMOTE_ONESHOT_FLYCOMBATWOUND", "EMOTE_ONESHOT_FLYCOMBATWOUND", "" };
        case EMOTE_ONESHOT_MOUNTSELFSPECIAL: return { "EMOTE_ONESHOT_MOUNTSELFSPECIAL", "EMOTE_ONESHOT_MOUNTSELFSPECIAL", "" };
        case EMOTE_ONESHOT_ATTACKUNARMED_NOSOUND: return { "EMOTE_ONESHOT_ATTACKUNARMED_NOSOUND", "EMOTE_ONESHOT_ATTACKUNARMED_NOSOUND", "" };
        case EMOTE_STATE_WOUNDCRITICAL_DOESNT_WORK: return { "EMOTE_STATE_WOUNDCRITICAL_DOESNT_WORK", "EMOTE_STATE_WOUNDCRITICAL_DOESNT_WORK", "" };
        case EMOTE_ONESHOT_ATTACK1H_NO_SOUND: return { "EMOTE_ONESHOT_ATTACK1H_NO_SOUND", "EMOTE_ONESHOT_ATTACK1H_NO_SOUND", "" };
        case EMOTE_STATE_MOUNT_SELF_IDLE: return { "EMOTE_STATE_MOUNT_SELF_IDLE", "EMOTE_STATE_MOUNT_SELF_IDLE", "" };
        case EMOTE_ONESHOT_WALK: return { "EMOTE_ONESHOT_WALK", "EMOTE_ONESHOT_WALK", "" };
        case EMOTE_STATE_OPENED: return { "EMOTE_STATE_OPENED", "EMOTE_STATE_OPENED", "" };
        case EMOTE_STATE_CUSTOMSPELL03: return { "EMOTE_STATE_CUSTOMSPELL03", "EMOTE_STATE_CUSTOMSPELL03", "" };
        case EMOTE_ONESHOT_BREATHOFFIRE: return { "EMOTE_ONESHOT_BREATHOFFIRE", "EMOTE_ONESHOT_BREATHOFFIRE", "" };
        case EMOTE_STATE_ATTACK1H: return { "EMOTE_STATE_ATTACK1H", "EMOTE_STATE_ATTACK1H", "" };
        case EMOTE_STATE_WORK_CHOPWOOD_2: return { "EMOTE_STATE_WORK_CHOPWOOD_2", "EMOTE_STATE_WORK_CHOPWOOD_2", "" };
        case EMOTE_STATE_USESTANDING_LOOP: return { "EMOTE_STATE_USESTANDING_LOOP", "EMOTE_STATE_USESTANDING_LOOP", "" };
        case EMOTE_STATE_USESTANDING: return { "EMOTE_STATE_USESTANDING", "EMOTE_STATE_USESTANDING", "" };
        case EMOTE_ONESHOT_SHEATH: return { "EMOTE_ONESHOT_SHEATH", "EMOTE_ONESHOT_SHEATH", "" };
        case EMOTE_ONESHOT_LAUGH_NO_SOUND: return { "EMOTE_ONESHOT_LAUGH_NO_SOUND", "EMOTE_ONESHOT_LAUGH_NO_SOUND", "" };
        case EMOTE_RECLINED_MOUNT: return { "EMOTE_RECLINED_MOUNT", "EMOTE_RECLINED_MOUNT", "" };
        case EMOTE_ONESHOT_ATTACK1H_2: return { "EMOTE_ONESHOT_ATTACK1H_2", "EMOTE_ONESHOT_ATTACK1H_2", "" };
        case EMOTE_STATE_CRY_NOSOUND: return { "EMOTE_STATE_CRY_NOSOUND", "EMOTE_STATE_CRY_NOSOUND", "" };
        case EMOTE_ONESHOT_CRY_NOSOUND: return { "EMOTE_ONESHOT_CRY_NOSOUND", "EMOTE_ONESHOT_CRY_NOSOUND", "" };
        case EMOTE_ONESHOT_COMBATCRITICAL: return { "EMOTE_ONESHOT_COMBATCRITICAL", "EMOTE_ONESHOT_COMBATCRITICAL", "" };
        case EMOTE_STATE_TRAIN: return { "EMOTE_STATE_TRAIN", "EMOTE_STATE_TRAIN", "" };
        case EMOTE_STATE_WORK_CHOPWOOD_LUMBER_AXE: return { "EMOTE_STATE_WORK_CHOPWOOD_LUMBER_AXE", "EMOTE_STATE_WORK_CHOPWOOD_LUMBER_AXE", "" };
        case EMOTE_ONESHOT_SPECIALATTACK2H: return { "EMOTE_ONESHOT_SPECIALATTACK2H", "EMOTE_ONESHOT_SPECIALATTACK2H", "" };
        case EMOTE_STATE_READ_AND_TALK: return { "EMOTE_STATE_READ_AND_TALK", "EMOTE_STATE_READ_AND_TALK", "" };
        case EMOTE_ONESHOT_STAND_VAR1: return { "EMOTE_ONESHOT_STAND_VAR1", "EMOTE_ONESHOT_STAND_VAR1", "" };
        case EMOTE_REXXAR_STRANGLES_GOBLIN: return { "EMOTE_REXXAR_STRANGLES_GOBLIN", "EMOTE_REXXAR_STRANGLES_GOBLIN", "" };
        case EMOTE_ONESHOT_STAND_VAR2: return { "EMOTE_ONESHOT_STAND_VAR2", "EMOTE_ONESHOT_STAND_VAR2", "" };
        case EMOTE_ONESHOT_DEATH: return { "EMOTE_ONESHOT_DEATH", "EMOTE_ONESHOT_DEATH", "" };
        case EMOTE_STATE_TALKONCE: return { "EMOTE_STATE_TALKONCE", "EMOTE_STATE_TALKONCE", "" };
        case EMOTE_STATE_ATTACK2H: return { "EMOTE_STATE_ATTACK2H", "EMOTE_STATE_ATTACK2H", "" };
        case EMOTE_STATE_SIT_GROUND: return { "EMOTE_STATE_SIT_GROUND", "EMOTE_STATE_SIT_GROUND", "" };
        case EMOTE_STATE_WORK_CHOPWOOD3: return { "EMOTE_STATE_WORK_CHOPWOOD3", "EMOTE_STATE_WORK_CHOPWOOD3", "" };
        case EMOTE_STATE_CUSTOMSPELL01: return { "EMOTE_STATE_CUSTOMSPELL01", "EMOTE_STATE_CUSTOMSPELL01", "" };
        case EMOTE_ONESHOT_COMBATWOUND: return { "EMOTE_ONESHOT_COMBATWOUND", "EMOTE_ONESHOT_COMBATWOUND", "" };
        case EMOTE_ONESHOT_TALK_EXCLAMATION: return { "EMOTE_ONESHOT_TALK_EXCLAMATION", "EMOTE_ONESHOT_TALK_EXCLAMATION", "" };
        case EMOTE_ONESHOT_QUESTION2: return { "EMOTE_ONESHOT_QUESTION2", "EMOTE_ONESHOT_QUESTION2", "" };
        case EMOTE_STATE_CRY: return { "EMOTE_STATE_CRY", "EMOTE_STATE_CRY", "" };
        case EMOTE_STATE_USESTANDING_LOOP2: return { "EMOTE_STATE_USESTANDING_LOOP2", "EMOTE_STATE_USESTANDING_LOOP2", "" };
        case EMOTE_STATE_WORK_SMITH: return { "EMOTE_STATE_WORK_SMITH", "EMOTE_STATE_WORK_SMITH", "" };
        case EMOTE_STATE_WORK_CHOPWOOD4: return { "EMOTE_STATE_WORK_CHOPWOOD4", "EMOTE_STATE_WORK_CHOPWOOD4", "" };
        case EMOTE_STATE_CUSTOMSPELL02: return { "EMOTE_STATE_CUSTOMSPELL02", "EMOTE_STATE_CUSTOMSPELL02", "" };
        case EMOTE_STATE_READ_AND_SIT: return { "EMOTE_STATE_READ_AND_SIT", "EMOTE_STATE_READ_AND_SIT", "" };
        case EMOTE_STATE_PARRY_UNARMED: return { "EMOTE_STATE_PARRY_UNARMED", "EMOTE_STATE_PARRY_UNARMED", "" };
        case EMOTE_STATE_BLOCK_SHIELD: return { "EMOTE_STATE_BLOCK_SHIELD", "EMOTE_STATE_BLOCK_SHIELD", "" };
        case EMOTE_STATE_SIT_GROUND_2: return { "EMOTE_STATE_SIT_GROUND_2", "EMOTE_STATE_SIT_GROUND_2", "" };
        case EMOTE_ONESHOT_MOUNTSPECIAL: return { "EMOTE_ONESHOT_MOUNTSPECIAL", "EMOTE_ONESHOT_MOUNTSPECIAL", "" };
        case EMOTE_ONESHOT_SETTLE: return { "EMOTE_ONESHOT_SETTLE", "EMOTE_ONESHOT_SETTLE", "" };
        case EMOTE_STATE_ATTACK_UNARMED_STILL: return { "EMOTE_STATE_ATTACK_UNARMED_STILL", "EMOTE_STATE_ATTACK_UNARMED_STILL", "" };
        case EMOTE_STATE_READ_BOOK_AND_TALK: return { "EMOTE_STATE_READ_BOOK_AND_TALK", "EMOTE_STATE_READ_BOOK_AND_TALK", "" };
        case EMOTE_ONESHOT_SLAM: return { "EMOTE_ONESHOT_SLAM", "EMOTE_ONESHOT_SLAM", "" };
        case EMOTE_ONESHOT_GRABTHROWN: return { "EMOTE_ONESHOT_GRABTHROWN", "EMOTE_ONESHOT_GRABTHROWN", "" };
        case EMOTE_ONESHOT_READYSPELLDIRECTED_NOSOUND: return { "EMOTE_ONESHOT_READYSPELLDIRECTED_NOSOUND", "EMOTE_ONESHOT_READYSPELLDIRECTED_NOSOUND", "" };
        case EMOTE_STATE_READYSPELLOMNI_WITH_SOUND: return { "EMOTE_STATE_READYSPELLOMNI_WITH_SOUND", "EMOTE_STATE_READYSPELLOMNI_WITH_SOUND", "" };
        case EMOTE_ONESHOT_TALK_BARSERVER: return { "EMOTE_ONESHOT_TALK_BARSERVER", "EMOTE_ONESHOT_TALK_BARSERVER", "" };
        case EMOTE_ONESHOT_WAVE_BARSERVER: return { "EMOTE_ONESHOT_WAVE_BARSERVER", "EMOTE_ONESHOT_WAVE_BARSERVER", "" };
        case EMOTE_STATE_WORK_MINING2: return { "EMOTE_STATE_WORK_MINING2", "EMOTE_STATE_WORK_MINING2", "" };
        case EMOTE_STATE_READY2HL_ALLOW_MOVEMENT: return { "EMOTE_STATE_READY2HL_ALLOW_MOVEMENT", "EMOTE_STATE_READY2HL_ALLOW_MOVEMENT", "" };
        case EMOTE_STATE_USESTANDING_NOSHEATHE_STILL: return { "EMOTE_STATE_USESTANDING_NOSHEATHE_STILL", "EMOTE_STATE_USESTANDING_NOSHEATHE_STILL", "" };
        case EMOTE_ONESHOT_WORK_STILL: return { "EMOTE_ONESHOT_WORK_STILL", "EMOTE_ONESHOT_WORK_STILL", "" };
        case EMOTE_STATE_HOLD_THROWN_INTERRUPTS: return { "EMOTE_STATE_HOLD_THROWN_INTERRUPTS", "EMOTE_STATE_HOLD_THROWN_INTERRUPTS", "" };
        case EMOTE_ONESHOT_CANNIBALIZE: return { "EMOTE_ONESHOT_CANNIBALIZE", "EMOTE_ONESHOT_CANNIBALIZE", "" };
        case EMOTE_ONESHOT_NO_NOT_SWIMMING: return { "EMOTE_ONESHOT_NO_NOT_SWIMMING", "EMOTE_ONESHOT_NO_NOT_SWIMMING", "" };
        case EMOTE_STATE_READYGLV: return { "EMOTE_STATE_READYGLV", "EMOTE_STATE_READYGLV", "" };
        case EMOTE_ONESHOT_COMBATABILITYGLV01: return { "EMOTE_ONESHOT_COMBATABILITYGLV01", "EMOTE_ONESHOT_COMBATABILITYGLV01", "" };
        case EMOTE_ONESHOT_COMBATABILITYGLVOFF01: return { "EMOTE_ONESHOT_COMBATABILITYGLVOFF01", "EMOTE_ONESHOT_COMBATABILITYGLVOFF01", "" };
        case EMOTE_ONESHOT_COMBATABILITYGLVBIG02: return { "EMOTE_ONESHOT_COMBATABILITYGLVBIG02", "EMOTE_ONESHOT_COMBATABILITYGLVBIG02", "" };
        case EMOTE_ONESHOT_PARRYGLV: return { "EMOTE_ONESHOT_PARRYGLV", "EMOTE_ONESHOT_PARRYGLV", "" };
        case EMOTE_STATE_WORK_MINING3: return { "EMOTE_STATE_WORK_MINING3", "EMOTE_STATE_WORK_MINING3", "" };
        case EMOTE_ONESHOT_TALK_NOSHEATHE: return { "EMOTE_ONESHOT_TALK_NOSHEATHE", "EMOTE_ONESHOT_TALK_NOSHEATHE", "" };
        case EMOTE_ONESHOT_STAND_VAR3: return { "EMOTE_ONESHOT_STAND_VAR3", "EMOTE_ONESHOT_STAND_VAR3", "" };
        case EMOTE_STATE_KNEEL2: return { "EMOTE_STATE_KNEEL2", "EMOTE_STATE_KNEEL2", "" };
        case EMOTE_ONESHOT_CUSTOM0: return { "EMOTE_ONESHOT_CUSTOM0", "EMOTE_ONESHOT_CUSTOM0", "" };
        case EMOTE_ONESHOT_CUSTOM1: return { "EMOTE_ONESHOT_CUSTOM1", "EMOTE_ONESHOT_CUSTOM1", "" };
        case EMOTE_ONESHOT_CUSTOM2: return { "EMOTE_ONESHOT_CUSTOM2", "EMOTE_ONESHOT_CUSTOM2", "" };
        case EMOTE_ONESHOT_CUSTOM3: return { "EMOTE_ONESHOT_CUSTOM3", "EMOTE_ONESHOT_CUSTOM3", "" };
        case EMOTE_STATE_FLY_READY_UNARMED: return { "EMOTE_STATE_FLY_READY_UNARMED", "EMOTE_STATE_FLY_READY_UNARMED", "" };
        case EMOTE_ONESHOT_CHEER_FORTHEALLIANCE: return { "EMOTE_ONESHOT_CHEER_FORTHEALLIANCE", "EMOTE_ONESHOT_CHEER_FORTHEALLIANCE", "" };
        case EMOTE_ONESHOT_CHEER_FORTHEHORDE: return { "EMOTE_ONESHOT_CHEER_FORTHEHORDE", "EMOTE_ONESHOT_CHEER_FORTHEHORDE", "" };
        case EMOTE_ONESHOT_STAND_VAR4: return { "EMOTE_ONESHOT_STAND_VAR4", "EMOTE_ONESHOT_STAND_VAR4", "" };
        case EMOTE_ONESHOT_FLYEMOTEEXCLAMATION: return { "EMOTE_ONESHOT_FLYEMOTEEXCLAMATION", "EMOTE_ONESHOT_FLYEMOTEEXCLAMATION", "" };
        case EMOTE_STATE_EMOTEEAT: return { "EMOTE_STATE_EMOTEEAT", "EMOTE_STATE_EMOTEEAT", "" };
        case EMOTE_STATE_MONKHEAL_CHANNELOMNI: return { "EMOTE_STATE_MONKHEAL_CHANNELOMNI", "EMOTE_STATE_MONKHEAL_CHANNELOMNI", "" };
        case EMOTE_STATE_MONKDEFENSE_READYUNARMED: return { "EMOTE_STATE_MONKDEFENSE_READYUNARMED", "EMOTE_STATE_MONKDEFENSE_READYUNARMED", "" };
        case EMOTE_ONESHOT_STAND: return { "EMOTE_ONESHOT_STAND", "EMOTE_ONESHOT_STAND", "" };
        case EMOTE_STATE_WAPOURHOLD: return { "EMOTE_STATE_WAPOURHOLD", "EMOTE_STATE_WAPOURHOLD", "" };
        case EMOTE_STATE_READYBLOWDART: return { "EMOTE_STATE_READYBLOWDART", "EMOTE_STATE_READYBLOWDART", "" };
        case EMOTE_STATE_WORK_CHOPMEAT: return { "EMOTE_STATE_WORK_CHOPMEAT", "EMOTE_STATE_WORK_CHOPMEAT", "" };
        case EMOTE_STATE_MONK2HLIDLE: return { "EMOTE_STATE_MONK2HLIDLE", "EMOTE_STATE_MONK2HLIDLE", "" };
        case EMOTE_STATE_WAPERCH: return { "EMOTE_STATE_WAPERCH", "EMOTE_STATE_WAPERCH", "" };
        case EMOTE_STATE_WAGUARDSTAND01: return { "EMOTE_STATE_WAGUARDSTAND01", "EMOTE_STATE_WAGUARDSTAND01", "" };
        case EMOTE_STATE_READ_AND_SIT_CHAIR_MED: return { "EMOTE_STATE_READ_AND_SIT_CHAIR_MED", "EMOTE_STATE_READ_AND_SIT_CHAIR_MED", "" };
        case EMOTE_STATE_WAGUARDSTAND02: return { "EMOTE_STATE_WAGUARDSTAND02", "EMOTE_STATE_WAGUARDSTAND02", "" };
        case EMOTE_STATE_WAGUARDSTAND03: return { "EMOTE_STATE_WAGUARDSTAND03", "EMOTE_STATE_WAGUARDSTAND03", "" };
        case EMOTE_STATE_WAGUARDSTAND04: return { "EMOTE_STATE_WAGUARDSTAND04", "EMOTE_STATE_WAGUARDSTAND04", "" };
        case EMOTE_STATE_WACHANT02: return { "EMOTE_STATE_WACHANT02", "EMOTE_STATE_WACHANT02", "" };
        case EMOTE_STATE_WALEAN01: return { "EMOTE_STATE_WALEAN01", "EMOTE_STATE_WALEAN01", "" };
        case EMOTE_STATE_DRUNKWALK: return { "EMOTE_STATE_DRUNKWALK", "EMOTE_STATE_DRUNKWALK", "" };
        case EMOTE_STATE_WASCRUBBING: return { "EMOTE_STATE_WASCRUBBING", "EMOTE_STATE_WASCRUBBING", "" };
        case EMOTE_STATE_WACHANT01: return { "EMOTE_STATE_WACHANT01", "EMOTE_STATE_WACHANT01", "" };
        case EMOTE_STATE_WACHANT03: return { "EMOTE_STATE_WACHANT03", "EMOTE_STATE_WACHANT03", "" };
        case EMOTE_STATE_WASUMMON01: return { "EMOTE_STATE_WASUMMON01", "EMOTE_STATE_WASUMMON01", "" };
        case EMOTE_STATE_WATRANCE01: return { "EMOTE_STATE_WATRANCE01", "EMOTE_STATE_WATRANCE01", "" };
        case EMOTE_STATE_CUSTOMSPELL05: return { "EMOTE_STATE_CUSTOMSPELL05", "EMOTE_STATE_CUSTOMSPELL05", "" };
        case EMOTE_STATE_WAHAMMERLOOP: return { "EMOTE_STATE_WAHAMMERLOOP", "EMOTE_STATE_WAHAMMERLOOP", "" };
        case EMOTE_STATE_WABOUND01: return { "EMOTE_STATE_WABOUND01", "EMOTE_STATE_WABOUND01", "" };
        case EMOTE_STATE_WABOUND02: return { "EMOTE_STATE_WABOUND02", "EMOTE_STATE_WABOUND02", "" };
        case EMOTE_STATE_WASACKHOLD: return { "EMOTE_STATE_WASACKHOLD", "EMOTE_STATE_WASACKHOLD", "" };
        case EMOTE_STATE_WASIT01: return { "EMOTE_STATE_WASIT01", "EMOTE_STATE_WASIT01", "" };
        case EMOTE_STATE_WAROWINGSTANDLEFT: return { "EMOTE_STATE_WAROWINGSTANDLEFT", "EMOTE_STATE_WAROWINGSTANDLEFT", "" };
        case EMOTE_STATE_WAROWINGSTANDRIGHT: return { "EMOTE_STATE_WAROWINGSTANDRIGHT", "EMOTE_STATE_WAROWINGSTANDRIGHT", "" };
        case EMOTE_STATE_LOOT_BITE_SOUND: return { "EMOTE_STATE_LOOT_BITE_SOUND", "EMOTE_STATE_LOOT_BITE_SOUND", "" };
        case EMOTE_ONESHOT_WASUMMON01: return { "EMOTE_ONESHOT_WASUMMON01", "EMOTE_ONESHOT_WASUMMON01", "" };
        case EMOTE_ONESHOT_STAND_VAR2_2: return { "EMOTE_ONESHOT_STAND_VAR2_2", "EMOTE_ONESHOT_STAND_VAR2_2", "" };
        case EMOTE_ONESHOT_FALCONEER_START: return { "EMOTE_ONESHOT_FALCONEER_START", "EMOTE_ONESHOT_FALCONEER_START", "" };
        case EMOTE_STATE_FALCONEER_LOOP: return { "EMOTE_STATE_FALCONEER_LOOP", "EMOTE_STATE_FALCONEER_LOOP", "" };
        case EMOTE_ONESHOT_FALCONEER_END: return { "EMOTE_ONESHOT_FALCONEER_END", "EMOTE_ONESHOT_FALCONEER_END", "" };
        case EMOTE_STATE_WAPERCH_NOINTERACT: return { "EMOTE_STATE_WAPERCH_NOINTERACT", "EMOTE_STATE_WAPERCH_NOINTERACT", "" };
        case EMOTE_ONESHOT_WASTANDDRINK: return { "EMOTE_ONESHOT_WASTANDDRINK", "EMOTE_ONESHOT_WASTANDDRINK", "" };
        case EMOTE_STATE_WALEAN02: return { "EMOTE_STATE_WALEAN02", "EMOTE_STATE_WALEAN02", "" };
        case EMOTE_ONESHOT_READ_END: return { "EMOTE_ONESHOT_READ_END", "EMOTE_ONESHOT_READ_END", "" };
        case EMOTE_STATE_WAGUARDSTAND04_ALLOW_MOVEMENT: return { "EMOTE_STATE_WAGUARDSTAND04_ALLOW_MOVEMENT", "EMOTE_STATE_WAGUARDSTAND04_ALLOW_MOVEMENT", "" };
        case EMOTE_STATE_READYCROSSBOW: return { "EMOTE_STATE_READYCROSSBOW", "EMOTE_STATE_READYCROSSBOW", "" };
        case EMOTE_ONESHOT_WASTANDDRINK_NOSHEATH: return { "EMOTE_ONESHOT_WASTANDDRINK_NOSHEATH", "EMOTE_ONESHOT_WASTANDDRINK_NOSHEATH", "" };
        case EMOTE_STATE_WAHANG01: return { "EMOTE_STATE_WAHANG01", "EMOTE_STATE_WAHANG01", "" };
        case EMOTE_STATE_WABEGGARSTAND: return { "EMOTE_STATE_WABEGGARSTAND", "EMOTE_STATE_WABEGGARSTAND", "" };
        case EMOTE_STATE_WADRUNKSTAND: return { "EMOTE_STATE_WADRUNKSTAND", "EMOTE_STATE_WADRUNKSTAND", "" };
        case EMOTE_ONESHOT_WACRIERTALK: return { "EMOTE_ONESHOT_WACRIERTALK", "EMOTE_ONESHOT_WACRIERTALK", "" };
        case EMOTE_STATE_HOLD_CROSSBOW: return { "EMOTE_STATE_HOLD_CROSSBOW", "EMOTE_STATE_HOLD_CROSSBOW", "" };
        case EMOTE_STATE_WASIT02: return { "EMOTE_STATE_WASIT02", "EMOTE_STATE_WASIT02", "" };
        case EMOTE_STATE_WACRANKSTAND: return { "EMOTE_STATE_WACRANKSTAND", "EMOTE_STATE_WACRANKSTAND", "" };
        case EMOTE_ONESHOT_READ_START: return { "EMOTE_ONESHOT_READ_START", "EMOTE_ONESHOT_READ_START", "" };
        case EMOTE_ONESHOT_READ_LOOP: return { "EMOTE_ONESHOT_READ_LOOP", "EMOTE_ONESHOT_READ_LOOP", "" };
        case EMOTE_ONESHOT_WADRUNKDRINK: return { "EMOTE_ONESHOT_WADRUNKDRINK", "EMOTE_ONESHOT_WADRUNKDRINK", "" };
        case EMOTE_STATE_SIT_CHAIR_MED_EAT: return { "EMOTE_STATE_SIT_CHAIR_MED_EAT", "EMOTE_STATE_SIT_CHAIR_MED_EAT", "" };
        case EMOTE_STATE_KNEEL_COPY: return { "EMOTE_STATE_KNEEL_COPY", "EMOTE_STATE_KNEEL_COPY", "" };
        case EMOTE_STATE_WORK_CHOPMEAT_NOSHEATHE: return { "EMOTE_STATE_WORK_CHOPMEAT_NOSHEATHE", "EMOTE_STATE_WORK_CHOPMEAT_NOSHEATHE", "" };
        case EMOTE_ONESHOT_BARPATRON_POINT: return { "EMOTE_ONESHOT_BARPATRON_POINT", "EMOTE_ONESHOT_BARPATRON_POINT", "" };
        case EMOTE_STATE_STAND_NOSOUND: return { "EMOTE_STATE_STAND_NOSOUND", "EMOTE_STATE_STAND_NOSOUND", "" };
        case EMOTE_STATE_MOUNT_FLIGHT_IDLE_NOSOUND: return { "EMOTE_STATE_MOUNT_FLIGHT_IDLE_NOSOUND", "EMOTE_STATE_MOUNT_FLIGHT_IDLE_NOSOUND", "" };
        case EMOTE_STATE_USESTANDING_LOOP3: return { "EMOTE_STATE_USESTANDING_LOOP3", "EMOTE_STATE_USESTANDING_LOOP3", "" };
        case EMOTE_ONESHOT_VEHICLEGRAB: return { "EMOTE_ONESHOT_VEHICLEGRAB", "EMOTE_ONESHOT_VEHICLEGRAB", "" };
        case EMOTE_STATE_USESTANDING_LOOP4: return { "EMOTE_STATE_USESTANDING_LOOP4", "EMOTE_STATE_USESTANDING_LOOP4", "" };
        case EMOTE_STATE_BARPATRON_STAND: return { "EMOTE_STATE_BARPATRON_STAND", "EMOTE_STATE_BARPATRON_STAND", "" };
        case EMOTE_ONESHOT_WABEGGARPOINT: return { "EMOTE_ONESHOT_WABEGGARPOINT", "EMOTE_ONESHOT_WABEGGARPOINT", "" };
        case EMOTE_STATE_WACRIERSTAND01: return { "EMOTE_STATE_WACRIERSTAND01", "EMOTE_STATE_WACRIERSTAND01", "" };
        case EMOTE_ONESHOT_WABEGGARBEG: return { "EMOTE_ONESHOT_WABEGGARBEG", "EMOTE_ONESHOT_WABEGGARBEG", "" };
        case EMOTE_STATE_WABOATWHEELSTAND: return { "EMOTE_STATE_WABOATWHEELSTAND", "EMOTE_STATE_WABOATWHEELSTAND", "" };
        case EMOTE_STATE_WASIT03: return { "EMOTE_STATE_WASIT03", "EMOTE_STATE_WASIT03", "" };
        case EMOTE_STATE_BARSWEEP_STAND: return { "EMOTE_STATE_BARSWEEP_STAND", "EMOTE_STATE_BARSWEEP_STAND", "" };
        case EMOTE_STATE_WAGUARDSTAND05: return { "EMOTE_STATE_WAGUARDSTAND05", "EMOTE_STATE_WAGUARDSTAND05", "" };
        case EMOTE_STATE_WAGUARDSTAND06: return { "EMOTE_STATE_WAGUARDSTAND06", "EMOTE_STATE_WAGUARDSTAND06", "" };
        case EMOTE_STATE_BARTENDSTAND: return { "EMOTE_STATE_BARTENDSTAND", "EMOTE_STATE_BARTENDSTAND", "" };
        case EMOTE_STATE_WAHAMMERLOOP2: return { "EMOTE_STATE_WAHAMMERLOOP2", "EMOTE_STATE_WAHAMMERLOOP2", "" };
        case EMOTE_STATE_WORK_MINING_NO_COMBAT: return { "EMOTE_STATE_WORK_MINING_NO_COMBAT", "EMOTE_STATE_WORK_MINING_NO_COMBAT", "" };
        case EMOTE_ONESHOT_CASTSTRONG: return { "EMOTE_ONESHOT_CASTSTRONG", "EMOTE_ONESHOT_CASTSTRONG", "" };
        case EMOTE_STATE_CUSTOMSPELL07: return { "EMOTE_STATE_CUSTOMSPELL07", "EMOTE_STATE_CUSTOMSPELL07", "" };
        case EMOTE_STATE_WALK: return { "EMOTE_STATE_WALK", "EMOTE_STATE_WALK", "" };
        case EMOTE_ONESHOT_CLOSE: return { "EMOTE_ONESHOT_CLOSE", "EMOTE_ONESHOT_CLOSE", "" };
        case EMOTE_STATE_WACRATEHOLD: return { "EMOTE_STATE_WACRATEHOLD", "EMOTE_STATE_WACRATEHOLD", "" };
        case EMOTE_STATE_FLYCUSTOMSPELL02: return { "EMOTE_STATE_FLYCUSTOMSPELL02", "EMOTE_STATE_FLYCUSTOMSPELL02", "" };
        case EMOTE_ONESHOT_SLEEP: return { "EMOTE_ONESHOT_SLEEP", "EMOTE_ONESHOT_SLEEP", "" };
        case EMOTE_STATE_STAND_SETEMOTESTATE: return { "EMOTE_STATE_STAND_SETEMOTESTATE", "EMOTE_STATE_STAND_SETEMOTESTATE", "" };
        case EMOTE_ONESHOT_WAWALKTALK: return { "EMOTE_ONESHOT_WAWALKTALK", "EMOTE_ONESHOT_WAWALKTALK", "" };
        case EMOTE_ONESHOT_TAKE_OFF_FINISH: return { "EMOTE_ONESHOT_TAKE_OFF_FINISH", "EMOTE_ONESHOT_TAKE_OFF_FINISH", "" };
        case EMOTE_ONESHOT_ATTACK2H: return { "EMOTE_ONESHOT_ATTACK2H", "EMOTE_ONESHOT_ATTACK2H", "" };
        case EMOTE_STATE_WA_BARREL_HOLD: return { "EMOTE_STATE_WA_BARREL_HOLD", "EMOTE_STATE_WA_BARREL_HOLD", "" };
        case EMOTE_STATE_WA_BARREL_WALK: return { "EMOTE_STATE_WA_BARREL_WALK", "EMOTE_STATE_WA_BARREL_WALK", "" };
        case EMOTE_STATE_CUSTOMSPELL04: return { "EMOTE_STATE_CUSTOMSPELL04", "EMOTE_STATE_CUSTOMSPELL04", "" };
        case EMOTE_STATE_FLYWAPERCH01: return { "EMOTE_STATE_FLYWAPERCH01", "EMOTE_STATE_FLYWAPERCH01", "" };
        case EMOTE_ONESHOT_PALSPELLCAST1HUP: return { "EMOTE_ONESHOT_PALSPELLCAST1HUP", "EMOTE_ONESHOT_PALSPELLCAST1HUP", "" };
        case EMOTE_ONESHOT_READYSPELLOMNI: return { "EMOTE_ONESHOT_READYSPELLOMNI", "EMOTE_ONESHOT_READYSPELLOMNI", "" };
        case EMOTE_ONESHOT_SPELLCAST_DIRECTED: return { "EMOTE_ONESHOT_SPELLCAST_DIRECTED", "EMOTE_ONESHOT_SPELLCAST_DIRECTED", "" };
        case EMOTE_STATE_FLYCUSTOMSPELL07: return { "EMOTE_STATE_FLYCUSTOMSPELL07", "EMOTE_STATE_FLYCUSTOMSPELL07", "" };
        case EMOTE_STATE_FLYCHANNELCASTOMNI: return { "EMOTE_STATE_FLYCHANNELCASTOMNI", "EMOTE_STATE_FLYCHANNELCASTOMNI", "" };
        case EMOTE_STATE_CLOSED: return { "EMOTE_STATE_CLOSED", "EMOTE_STATE_CLOSED", "" };
        case EMOTE_STATE_CUSTOMSPELL10: return { "EMOTE_STATE_CUSTOMSPELL10", "EMOTE_STATE_CUSTOMSPELL10", "" };
        case EMOTE_STATE_WAWHEELBARROWSTAND: return { "EMOTE_STATE_WAWHEELBARROWSTAND", "EMOTE_STATE_WAWHEELBARROWSTAND", "" };
        case EMOTE_STATE_CUSTOMSPELL06: return { "EMOTE_STATE_CUSTOMSPELL06", "EMOTE_STATE_CUSTOMSPELL06", "" };
        case EMOTE_STATE_CUSTOM1: return { "EMOTE_STATE_CUSTOM1", "EMOTE_STATE_CUSTOM1", "" };
        case EMOTE_STATE_WASIT04: return { "EMOTE_STATE_WASIT04", "EMOTE_STATE_WASIT04", "" };
        case EMOTE_ONESHOT_BARSWEEP_STAND: return { "EMOTE_ONESHOT_BARSWEEP_STAND", "EMOTE_ONESHOT_BARSWEEP_STAND", "" };
        case EMOTE_TORGHAST_TALKING_HEAD_MAW_CAST_SOUND: return { "EMOTE_TORGHAST_TALKING_HEAD_MAW_CAST_SOUND", "EMOTE_TORGHAST_TALKING_HEAD_MAW_CAST_SOUND", "" };
        case EMOTE_TORGHAST_TALKING_HEAD_MAW_CAST_SOUND2: return { "EMOTE_TORGHAST_TALKING_HEAD_MAW_CAST_SOUND2", "EMOTE_TORGHAST_TALKING_HEAD_MAW_CAST_SOUND2", "" };
        case EMOTE_ONESHOT_STAND_VAR0: return { "EMOTE_ONESHOT_STAND_VAR0", "EMOTE_ONESHOT_STAND_VAR0", "" };
        case EMOTE_ONESHOT_FLYCUSTOMSPELL01: return { "EMOTE_ONESHOT_FLYCUSTOMSPELL01", "EMOTE_ONESHOT_FLYCUSTOMSPELL01", "" };
        case EMOTE_ONESHOT_SPELLEFFECT_DECAY: return { "EMOTE_ONESHOT_SPELLEFFECT_DECAY", "EMOTE_ONESHOT_SPELLEFFECT_DECAY", "" };
        case EMOTE_STATE_CREATURE_SPECIAL: return { "EMOTE_STATE_CREATURE_SPECIAL", "EMOTE_STATE_CREATURE_SPECIAL", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<Emote>::Count() { return 404; }

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
        case 171: return EMOTE_STATE_STRANGULATE2;
        case 172: return EMOTE_STATE_READY_SPELL_OMNI;
        case 173: return EMOTE_STATE_HOLD_JOUST;
        case 174: return EMOTE_ONESHOT_CRY_JAINA;
        case 175: return EMOTE_ONESHOT_SPECIAL_UNARMED;
        case 176: return EMOTE_STATE_DANCE_NOSHEATHE;
        case 177: return EMOTE_ONESHOT_SNIFF;
        case 178: return EMOTE_ONESHOT_DRAGONSTOMP;
        case 179: return EMOTE_ONESHOT_KNOCKDOWN;
        case 180: return EMOTE_STATE_READ;
        case 181: return EMOTE_ONESHOT_FLYEMOTETALK;
        case 182: return EMOTE_STATE_READ_ALLOWMOVEMENT;
        case 183: return EMOTE_STATE_CUSTOM_SPELL_06;
        case 184: return EMOTE_STATE_CUSTOM_SPELL_07;
        case 185: return EMOTE_STATE_CUSTOM_SPELL_08_2;
        case 186: return EMOTE_STATE_CUSTOM_SPELL_09;
        case 187: return EMOTE_STATE_CUSTOM_SPELL_10;
        case 188: return EMOTE_STATE_READY1H_ALLOW_MOVEMENT;
        case 189: return EMOTE_STATE_READY2H_ALLOW_MOVEMENT;
        case 190: return EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMED;
        case 191: return EMOTE_ONESHOT_MONKOFFENSE_SPECIALUNARMED;
        case 192: return EMOTE_ONESHOT_MONKOFFENSE_PARRYUNARMED;
        case 193: return EMOTE_STATE_MONKOFFENSE_READYUNARMED;
        case 194: return EMOTE_ONESHOT_PALMSTRIKE;
        case 195: return EMOTE_STATE_CRANE;
        case 196: return EMOTE_ONESHOT_OPEN;
        case 197: return EMOTE_STATE_READ_CHRISTMAS;
        case 198: return EMOTE_ONESHOT_FLYATTACK2HL;
        case 199: return EMOTE_ONESHOT_FLYATTACKTHROWN;
        case 200: return EMOTE_STATE_FLYREADYSPELLDIRECTED;
        case 201: return EMOTE_STATE_FLY_READY_1H;
        case 202: return EMOTE_STATE_MEDITATE;
        case 203: return EMOTE_STATE_FLY_READY_2HL;
        case 204: return EMOTE_ONESHOT_TOGROUND;
        case 205: return EMOTE_ONESHOT_TOFLY;
        case 206: return EMOTE_STATE_ATTACKTHROWN;
        case 207: return EMOTE_STATE_SPELL_CHANNEL_DIRECTED_NOSOUND;
        case 208: return EMOTE_ONESHOT_WORK;
        case 209: return EMOTE_STATE_READYUNARMED_NOSOUND;
        case 210: return EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMEDOFF;
        case 211: return EMOTE_RECLINED_MOUNT_PASSENGER;
        case 212: return EMOTE_ONESHOT_QUESTION_2;
        case 213: return EMOTE_ONESHOT_SPELL_CHANNEL_DIRECTED_NOSOUND;
        case 214: return EMOTE_STATE_KNEEL_2;
        case 215: return EMOTE_ONESHOT_FLYATTACKUNARMED;
        case 216: return EMOTE_ONESHOT_FLYCOMBATWOUND;
        case 217: return EMOTE_ONESHOT_MOUNTSELFSPECIAL;
        case 218: return EMOTE_ONESHOT_ATTACKUNARMED_NOSOUND;
        case 219: return EMOTE_STATE_WOUNDCRITICAL_DOESNT_WORK;
        case 220: return EMOTE_ONESHOT_ATTACK1H_NO_SOUND;
        case 221: return EMOTE_STATE_MOUNT_SELF_IDLE;
        case 222: return EMOTE_ONESHOT_WALK;
        case 223: return EMOTE_STATE_OPENED;
        case 224: return EMOTE_STATE_CUSTOMSPELL03;
        case 225: return EMOTE_ONESHOT_BREATHOFFIRE;
        case 226: return EMOTE_STATE_ATTACK1H;
        case 227: return EMOTE_STATE_WORK_CHOPWOOD_2;
        case 228: return EMOTE_STATE_USESTANDING_LOOP;
        case 229: return EMOTE_STATE_USESTANDING;
        case 230: return EMOTE_ONESHOT_SHEATH;
        case 231: return EMOTE_ONESHOT_LAUGH_NO_SOUND;
        case 232: return EMOTE_RECLINED_MOUNT;
        case 233: return EMOTE_ONESHOT_ATTACK1H_2;
        case 234: return EMOTE_STATE_CRY_NOSOUND;
        case 235: return EMOTE_ONESHOT_CRY_NOSOUND;
        case 236: return EMOTE_ONESHOT_COMBATCRITICAL;
        case 237: return EMOTE_STATE_TRAIN;
        case 238: return EMOTE_STATE_WORK_CHOPWOOD_LUMBER_AXE;
        case 239: return EMOTE_ONESHOT_SPECIALATTACK2H;
        case 240: return EMOTE_STATE_READ_AND_TALK;
        case 241: return EMOTE_ONESHOT_STAND_VAR1;
        case 242: return EMOTE_REXXAR_STRANGLES_GOBLIN;
        case 243: return EMOTE_ONESHOT_STAND_VAR2;
        case 244: return EMOTE_ONESHOT_DEATH;
        case 245: return EMOTE_STATE_TALKONCE;
        case 246: return EMOTE_STATE_ATTACK2H;
        case 247: return EMOTE_STATE_SIT_GROUND;
        case 248: return EMOTE_STATE_WORK_CHOPWOOD3;
        case 249: return EMOTE_STATE_CUSTOMSPELL01;
        case 250: return EMOTE_ONESHOT_COMBATWOUND;
        case 251: return EMOTE_ONESHOT_TALK_EXCLAMATION;
        case 252: return EMOTE_ONESHOT_QUESTION2;
        case 253: return EMOTE_STATE_CRY;
        case 254: return EMOTE_STATE_USESTANDING_LOOP2;
        case 255: return EMOTE_STATE_WORK_SMITH;
        case 256: return EMOTE_STATE_WORK_CHOPWOOD4;
        case 257: return EMOTE_STATE_CUSTOMSPELL02;
        case 258: return EMOTE_STATE_READ_AND_SIT;
        case 259: return EMOTE_STATE_PARRY_UNARMED;
        case 260: return EMOTE_STATE_BLOCK_SHIELD;
        case 261: return EMOTE_STATE_SIT_GROUND_2;
        case 262: return EMOTE_ONESHOT_MOUNTSPECIAL;
        case 263: return EMOTE_ONESHOT_SETTLE;
        case 264: return EMOTE_STATE_ATTACK_UNARMED_STILL;
        case 265: return EMOTE_STATE_READ_BOOK_AND_TALK;
        case 266: return EMOTE_ONESHOT_SLAM;
        case 267: return EMOTE_ONESHOT_GRABTHROWN;
        case 268: return EMOTE_ONESHOT_READYSPELLDIRECTED_NOSOUND;
        case 269: return EMOTE_STATE_READYSPELLOMNI_WITH_SOUND;
        case 270: return EMOTE_ONESHOT_TALK_BARSERVER;
        case 271: return EMOTE_ONESHOT_WAVE_BARSERVER;
        case 272: return EMOTE_STATE_WORK_MINING2;
        case 273: return EMOTE_STATE_READY2HL_ALLOW_MOVEMENT;
        case 274: return EMOTE_STATE_USESTANDING_NOSHEATHE_STILL;
        case 275: return EMOTE_ONESHOT_WORK_STILL;
        case 276: return EMOTE_STATE_HOLD_THROWN_INTERRUPTS;
        case 277: return EMOTE_ONESHOT_CANNIBALIZE;
        case 278: return EMOTE_ONESHOT_NO_NOT_SWIMMING;
        case 279: return EMOTE_STATE_READYGLV;
        case 280: return EMOTE_ONESHOT_COMBATABILITYGLV01;
        case 281: return EMOTE_ONESHOT_COMBATABILITYGLVOFF01;
        case 282: return EMOTE_ONESHOT_COMBATABILITYGLVBIG02;
        case 283: return EMOTE_ONESHOT_PARRYGLV;
        case 284: return EMOTE_STATE_WORK_MINING3;
        case 285: return EMOTE_ONESHOT_TALK_NOSHEATHE;
        case 286: return EMOTE_ONESHOT_STAND_VAR3;
        case 287: return EMOTE_STATE_KNEEL2;
        case 288: return EMOTE_ONESHOT_CUSTOM0;
        case 289: return EMOTE_ONESHOT_CUSTOM1;
        case 290: return EMOTE_ONESHOT_CUSTOM2;
        case 291: return EMOTE_ONESHOT_CUSTOM3;
        case 292: return EMOTE_STATE_FLY_READY_UNARMED;
        case 293: return EMOTE_ONESHOT_CHEER_FORTHEALLIANCE;
        case 294: return EMOTE_ONESHOT_CHEER_FORTHEHORDE;
        case 295: return EMOTE_ONESHOT_STAND_VAR4;
        case 296: return EMOTE_ONESHOT_FLYEMOTEEXCLAMATION;
        case 297: return EMOTE_STATE_EMOTEEAT;
        case 298: return EMOTE_STATE_MONKHEAL_CHANNELOMNI;
        case 299: return EMOTE_STATE_MONKDEFENSE_READYUNARMED;
        case 300: return EMOTE_ONESHOT_STAND;
        case 301: return EMOTE_STATE_WAPOURHOLD;
        case 302: return EMOTE_STATE_READYBLOWDART;
        case 303: return EMOTE_STATE_WORK_CHOPMEAT;
        case 304: return EMOTE_STATE_MONK2HLIDLE;
        case 305: return EMOTE_STATE_WAPERCH;
        case 306: return EMOTE_STATE_WAGUARDSTAND01;
        case 307: return EMOTE_STATE_READ_AND_SIT_CHAIR_MED;
        case 308: return EMOTE_STATE_WAGUARDSTAND02;
        case 309: return EMOTE_STATE_WAGUARDSTAND03;
        case 310: return EMOTE_STATE_WAGUARDSTAND04;
        case 311: return EMOTE_STATE_WACHANT02;
        case 312: return EMOTE_STATE_WALEAN01;
        case 313: return EMOTE_STATE_DRUNKWALK;
        case 314: return EMOTE_STATE_WASCRUBBING;
        case 315: return EMOTE_STATE_WACHANT01;
        case 316: return EMOTE_STATE_WACHANT03;
        case 317: return EMOTE_STATE_WASUMMON01;
        case 318: return EMOTE_STATE_WATRANCE01;
        case 319: return EMOTE_STATE_CUSTOMSPELL05;
        case 320: return EMOTE_STATE_WAHAMMERLOOP;
        case 321: return EMOTE_STATE_WABOUND01;
        case 322: return EMOTE_STATE_WABOUND02;
        case 323: return EMOTE_STATE_WASACKHOLD;
        case 324: return EMOTE_STATE_WASIT01;
        case 325: return EMOTE_STATE_WAROWINGSTANDLEFT;
        case 326: return EMOTE_STATE_WAROWINGSTANDRIGHT;
        case 327: return EMOTE_STATE_LOOT_BITE_SOUND;
        case 328: return EMOTE_ONESHOT_WASUMMON01;
        case 329: return EMOTE_ONESHOT_STAND_VAR2_2;
        case 330: return EMOTE_ONESHOT_FALCONEER_START;
        case 331: return EMOTE_STATE_FALCONEER_LOOP;
        case 332: return EMOTE_ONESHOT_FALCONEER_END;
        case 333: return EMOTE_STATE_WAPERCH_NOINTERACT;
        case 334: return EMOTE_ONESHOT_WASTANDDRINK;
        case 335: return EMOTE_STATE_WALEAN02;
        case 336: return EMOTE_ONESHOT_READ_END;
        case 337: return EMOTE_STATE_WAGUARDSTAND04_ALLOW_MOVEMENT;
        case 338: return EMOTE_STATE_READYCROSSBOW;
        case 339: return EMOTE_ONESHOT_WASTANDDRINK_NOSHEATH;
        case 340: return EMOTE_STATE_WAHANG01;
        case 341: return EMOTE_STATE_WABEGGARSTAND;
        case 342: return EMOTE_STATE_WADRUNKSTAND;
        case 343: return EMOTE_ONESHOT_WACRIERTALK;
        case 344: return EMOTE_STATE_HOLD_CROSSBOW;
        case 345: return EMOTE_STATE_WASIT02;
        case 346: return EMOTE_STATE_WACRANKSTAND;
        case 347: return EMOTE_ONESHOT_READ_START;
        case 348: return EMOTE_ONESHOT_READ_LOOP;
        case 349: return EMOTE_ONESHOT_WADRUNKDRINK;
        case 350: return EMOTE_STATE_SIT_CHAIR_MED_EAT;
        case 351: return EMOTE_STATE_KNEEL_COPY;
        case 352: return EMOTE_STATE_WORK_CHOPMEAT_NOSHEATHE;
        case 353: return EMOTE_ONESHOT_BARPATRON_POINT;
        case 354: return EMOTE_STATE_STAND_NOSOUND;
        case 355: return EMOTE_STATE_MOUNT_FLIGHT_IDLE_NOSOUND;
        case 356: return EMOTE_STATE_USESTANDING_LOOP3;
        case 357: return EMOTE_ONESHOT_VEHICLEGRAB;
        case 358: return EMOTE_STATE_USESTANDING_LOOP4;
        case 359: return EMOTE_STATE_BARPATRON_STAND;
        case 360: return EMOTE_ONESHOT_WABEGGARPOINT;
        case 361: return EMOTE_STATE_WACRIERSTAND01;
        case 362: return EMOTE_ONESHOT_WABEGGARBEG;
        case 363: return EMOTE_STATE_WABOATWHEELSTAND;
        case 364: return EMOTE_STATE_WASIT03;
        case 365: return EMOTE_STATE_BARSWEEP_STAND;
        case 366: return EMOTE_STATE_WAGUARDSTAND05;
        case 367: return EMOTE_STATE_WAGUARDSTAND06;
        case 368: return EMOTE_STATE_BARTENDSTAND;
        case 369: return EMOTE_STATE_WAHAMMERLOOP2;
        case 370: return EMOTE_STATE_WORK_MINING_NO_COMBAT;
        case 371: return EMOTE_ONESHOT_CASTSTRONG;
        case 372: return EMOTE_STATE_CUSTOMSPELL07;
        case 373: return EMOTE_STATE_WALK;
        case 374: return EMOTE_ONESHOT_CLOSE;
        case 375: return EMOTE_STATE_WACRATEHOLD;
        case 376: return EMOTE_STATE_FLYCUSTOMSPELL02;
        case 377: return EMOTE_ONESHOT_SLEEP;
        case 378: return EMOTE_STATE_STAND_SETEMOTESTATE;
        case 379: return EMOTE_ONESHOT_WAWALKTALK;
        case 380: return EMOTE_ONESHOT_TAKE_OFF_FINISH;
        case 381: return EMOTE_ONESHOT_ATTACK2H;
        case 382: return EMOTE_STATE_WA_BARREL_HOLD;
        case 383: return EMOTE_STATE_WA_BARREL_WALK;
        case 384: return EMOTE_STATE_CUSTOMSPELL04;
        case 385: return EMOTE_STATE_FLYWAPERCH01;
        case 386: return EMOTE_ONESHOT_PALSPELLCAST1HUP;
        case 387: return EMOTE_ONESHOT_READYSPELLOMNI;
        case 388: return EMOTE_ONESHOT_SPELLCAST_DIRECTED;
        case 389: return EMOTE_STATE_FLYCUSTOMSPELL07;
        case 390: return EMOTE_STATE_FLYCHANNELCASTOMNI;
        case 391: return EMOTE_STATE_CLOSED;
        case 392: return EMOTE_STATE_CUSTOMSPELL10;
        case 393: return EMOTE_STATE_WAWHEELBARROWSTAND;
        case 394: return EMOTE_STATE_CUSTOMSPELL06;
        case 395: return EMOTE_STATE_CUSTOM1;
        case 396: return EMOTE_STATE_WASIT04;
        case 397: return EMOTE_ONESHOT_BARSWEEP_STAND;
        case 398: return EMOTE_TORGHAST_TALKING_HEAD_MAW_CAST_SOUND;
        case 399: return EMOTE_TORGHAST_TALKING_HEAD_MAW_CAST_SOUND2;
        case 400: return EMOTE_ONESHOT_STAND_VAR0;
        case 401: return EMOTE_ONESHOT_FLYCUSTOMSPELL01;
        case 402: return EMOTE_ONESHOT_SPELLEFFECT_DECAY;
        case 403: return EMOTE_STATE_CREATURE_SPECIAL;
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
        case EMOTE_STATE_STRANGULATE2: return 171;
        case EMOTE_STATE_READY_SPELL_OMNI: return 172;
        case EMOTE_STATE_HOLD_JOUST: return 173;
        case EMOTE_ONESHOT_CRY_JAINA: return 174;
        case EMOTE_ONESHOT_SPECIAL_UNARMED: return 175;
        case EMOTE_STATE_DANCE_NOSHEATHE: return 176;
        case EMOTE_ONESHOT_SNIFF: return 177;
        case EMOTE_ONESHOT_DRAGONSTOMP: return 178;
        case EMOTE_ONESHOT_KNOCKDOWN: return 179;
        case EMOTE_STATE_READ: return 180;
        case EMOTE_ONESHOT_FLYEMOTETALK: return 181;
        case EMOTE_STATE_READ_ALLOWMOVEMENT: return 182;
        case EMOTE_STATE_CUSTOM_SPELL_06: return 183;
        case EMOTE_STATE_CUSTOM_SPELL_07: return 184;
        case EMOTE_STATE_CUSTOM_SPELL_08_2: return 185;
        case EMOTE_STATE_CUSTOM_SPELL_09: return 186;
        case EMOTE_STATE_CUSTOM_SPELL_10: return 187;
        case EMOTE_STATE_READY1H_ALLOW_MOVEMENT: return 188;
        case EMOTE_STATE_READY2H_ALLOW_MOVEMENT: return 189;
        case EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMED: return 190;
        case EMOTE_ONESHOT_MONKOFFENSE_SPECIALUNARMED: return 191;
        case EMOTE_ONESHOT_MONKOFFENSE_PARRYUNARMED: return 192;
        case EMOTE_STATE_MONKOFFENSE_READYUNARMED: return 193;
        case EMOTE_ONESHOT_PALMSTRIKE: return 194;
        case EMOTE_STATE_CRANE: return 195;
        case EMOTE_ONESHOT_OPEN: return 196;
        case EMOTE_STATE_READ_CHRISTMAS: return 197;
        case EMOTE_ONESHOT_FLYATTACK2HL: return 198;
        case EMOTE_ONESHOT_FLYATTACKTHROWN: return 199;
        case EMOTE_STATE_FLYREADYSPELLDIRECTED: return 200;
        case EMOTE_STATE_FLY_READY_1H: return 201;
        case EMOTE_STATE_MEDITATE: return 202;
        case EMOTE_STATE_FLY_READY_2HL: return 203;
        case EMOTE_ONESHOT_TOGROUND: return 204;
        case EMOTE_ONESHOT_TOFLY: return 205;
        case EMOTE_STATE_ATTACKTHROWN: return 206;
        case EMOTE_STATE_SPELL_CHANNEL_DIRECTED_NOSOUND: return 207;
        case EMOTE_ONESHOT_WORK: return 208;
        case EMOTE_STATE_READYUNARMED_NOSOUND: return 209;
        case EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMEDOFF: return 210;
        case EMOTE_RECLINED_MOUNT_PASSENGER: return 211;
        case EMOTE_ONESHOT_QUESTION_2: return 212;
        case EMOTE_ONESHOT_SPELL_CHANNEL_DIRECTED_NOSOUND: return 213;
        case EMOTE_STATE_KNEEL_2: return 214;
        case EMOTE_ONESHOT_FLYATTACKUNARMED: return 215;
        case EMOTE_ONESHOT_FLYCOMBATWOUND: return 216;
        case EMOTE_ONESHOT_MOUNTSELFSPECIAL: return 217;
        case EMOTE_ONESHOT_ATTACKUNARMED_NOSOUND: return 218;
        case EMOTE_STATE_WOUNDCRITICAL_DOESNT_WORK: return 219;
        case EMOTE_ONESHOT_ATTACK1H_NO_SOUND: return 220;
        case EMOTE_STATE_MOUNT_SELF_IDLE: return 221;
        case EMOTE_ONESHOT_WALK: return 222;
        case EMOTE_STATE_OPENED: return 223;
        case EMOTE_STATE_CUSTOMSPELL03: return 224;
        case EMOTE_ONESHOT_BREATHOFFIRE: return 225;
        case EMOTE_STATE_ATTACK1H: return 226;
        case EMOTE_STATE_WORK_CHOPWOOD_2: return 227;
        case EMOTE_STATE_USESTANDING_LOOP: return 228;
        case EMOTE_STATE_USESTANDING: return 229;
        case EMOTE_ONESHOT_SHEATH: return 230;
        case EMOTE_ONESHOT_LAUGH_NO_SOUND: return 231;
        case EMOTE_RECLINED_MOUNT: return 232;
        case EMOTE_ONESHOT_ATTACK1H_2: return 233;
        case EMOTE_STATE_CRY_NOSOUND: return 234;
        case EMOTE_ONESHOT_CRY_NOSOUND: return 235;
        case EMOTE_ONESHOT_COMBATCRITICAL: return 236;
        case EMOTE_STATE_TRAIN: return 237;
        case EMOTE_STATE_WORK_CHOPWOOD_LUMBER_AXE: return 238;
        case EMOTE_ONESHOT_SPECIALATTACK2H: return 239;
        case EMOTE_STATE_READ_AND_TALK: return 240;
        case EMOTE_ONESHOT_STAND_VAR1: return 241;
        case EMOTE_REXXAR_STRANGLES_GOBLIN: return 242;
        case EMOTE_ONESHOT_STAND_VAR2: return 243;
        case EMOTE_ONESHOT_DEATH: return 244;
        case EMOTE_STATE_TALKONCE: return 245;
        case EMOTE_STATE_ATTACK2H: return 246;
        case EMOTE_STATE_SIT_GROUND: return 247;
        case EMOTE_STATE_WORK_CHOPWOOD3: return 248;
        case EMOTE_STATE_CUSTOMSPELL01: return 249;
        case EMOTE_ONESHOT_COMBATWOUND: return 250;
        case EMOTE_ONESHOT_TALK_EXCLAMATION: return 251;
        case EMOTE_ONESHOT_QUESTION2: return 252;
        case EMOTE_STATE_CRY: return 253;
        case EMOTE_STATE_USESTANDING_LOOP2: return 254;
        case EMOTE_STATE_WORK_SMITH: return 255;
        case EMOTE_STATE_WORK_CHOPWOOD4: return 256;
        case EMOTE_STATE_CUSTOMSPELL02: return 257;
        case EMOTE_STATE_READ_AND_SIT: return 258;
        case EMOTE_STATE_PARRY_UNARMED: return 259;
        case EMOTE_STATE_BLOCK_SHIELD: return 260;
        case EMOTE_STATE_SIT_GROUND_2: return 261;
        case EMOTE_ONESHOT_MOUNTSPECIAL: return 262;
        case EMOTE_ONESHOT_SETTLE: return 263;
        case EMOTE_STATE_ATTACK_UNARMED_STILL: return 264;
        case EMOTE_STATE_READ_BOOK_AND_TALK: return 265;
        case EMOTE_ONESHOT_SLAM: return 266;
        case EMOTE_ONESHOT_GRABTHROWN: return 267;
        case EMOTE_ONESHOT_READYSPELLDIRECTED_NOSOUND: return 268;
        case EMOTE_STATE_READYSPELLOMNI_WITH_SOUND: return 269;
        case EMOTE_ONESHOT_TALK_BARSERVER: return 270;
        case EMOTE_ONESHOT_WAVE_BARSERVER: return 271;
        case EMOTE_STATE_WORK_MINING2: return 272;
        case EMOTE_STATE_READY2HL_ALLOW_MOVEMENT: return 273;
        case EMOTE_STATE_USESTANDING_NOSHEATHE_STILL: return 274;
        case EMOTE_ONESHOT_WORK_STILL: return 275;
        case EMOTE_STATE_HOLD_THROWN_INTERRUPTS: return 276;
        case EMOTE_ONESHOT_CANNIBALIZE: return 277;
        case EMOTE_ONESHOT_NO_NOT_SWIMMING: return 278;
        case EMOTE_STATE_READYGLV: return 279;
        case EMOTE_ONESHOT_COMBATABILITYGLV01: return 280;
        case EMOTE_ONESHOT_COMBATABILITYGLVOFF01: return 281;
        case EMOTE_ONESHOT_COMBATABILITYGLVBIG02: return 282;
        case EMOTE_ONESHOT_PARRYGLV: return 283;
        case EMOTE_STATE_WORK_MINING3: return 284;
        case EMOTE_ONESHOT_TALK_NOSHEATHE: return 285;
        case EMOTE_ONESHOT_STAND_VAR3: return 286;
        case EMOTE_STATE_KNEEL2: return 287;
        case EMOTE_ONESHOT_CUSTOM0: return 288;
        case EMOTE_ONESHOT_CUSTOM1: return 289;
        case EMOTE_ONESHOT_CUSTOM2: return 290;
        case EMOTE_ONESHOT_CUSTOM3: return 291;
        case EMOTE_STATE_FLY_READY_UNARMED: return 292;
        case EMOTE_ONESHOT_CHEER_FORTHEALLIANCE: return 293;
        case EMOTE_ONESHOT_CHEER_FORTHEHORDE: return 294;
        case EMOTE_ONESHOT_STAND_VAR4: return 295;
        case EMOTE_ONESHOT_FLYEMOTEEXCLAMATION: return 296;
        case EMOTE_STATE_EMOTEEAT: return 297;
        case EMOTE_STATE_MONKHEAL_CHANNELOMNI: return 298;
        case EMOTE_STATE_MONKDEFENSE_READYUNARMED: return 299;
        case EMOTE_ONESHOT_STAND: return 300;
        case EMOTE_STATE_WAPOURHOLD: return 301;
        case EMOTE_STATE_READYBLOWDART: return 302;
        case EMOTE_STATE_WORK_CHOPMEAT: return 303;
        case EMOTE_STATE_MONK2HLIDLE: return 304;
        case EMOTE_STATE_WAPERCH: return 305;
        case EMOTE_STATE_WAGUARDSTAND01: return 306;
        case EMOTE_STATE_READ_AND_SIT_CHAIR_MED: return 307;
        case EMOTE_STATE_WAGUARDSTAND02: return 308;
        case EMOTE_STATE_WAGUARDSTAND03: return 309;
        case EMOTE_STATE_WAGUARDSTAND04: return 310;
        case EMOTE_STATE_WACHANT02: return 311;
        case EMOTE_STATE_WALEAN01: return 312;
        case EMOTE_STATE_DRUNKWALK: return 313;
        case EMOTE_STATE_WASCRUBBING: return 314;
        case EMOTE_STATE_WACHANT01: return 315;
        case EMOTE_STATE_WACHANT03: return 316;
        case EMOTE_STATE_WASUMMON01: return 317;
        case EMOTE_STATE_WATRANCE01: return 318;
        case EMOTE_STATE_CUSTOMSPELL05: return 319;
        case EMOTE_STATE_WAHAMMERLOOP: return 320;
        case EMOTE_STATE_WABOUND01: return 321;
        case EMOTE_STATE_WABOUND02: return 322;
        case EMOTE_STATE_WASACKHOLD: return 323;
        case EMOTE_STATE_WASIT01: return 324;
        case EMOTE_STATE_WAROWINGSTANDLEFT: return 325;
        case EMOTE_STATE_WAROWINGSTANDRIGHT: return 326;
        case EMOTE_STATE_LOOT_BITE_SOUND: return 327;
        case EMOTE_ONESHOT_WASUMMON01: return 328;
        case EMOTE_ONESHOT_STAND_VAR2_2: return 329;
        case EMOTE_ONESHOT_FALCONEER_START: return 330;
        case EMOTE_STATE_FALCONEER_LOOP: return 331;
        case EMOTE_ONESHOT_FALCONEER_END: return 332;
        case EMOTE_STATE_WAPERCH_NOINTERACT: return 333;
        case EMOTE_ONESHOT_WASTANDDRINK: return 334;
        case EMOTE_STATE_WALEAN02: return 335;
        case EMOTE_ONESHOT_READ_END: return 336;
        case EMOTE_STATE_WAGUARDSTAND04_ALLOW_MOVEMENT: return 337;
        case EMOTE_STATE_READYCROSSBOW: return 338;
        case EMOTE_ONESHOT_WASTANDDRINK_NOSHEATH: return 339;
        case EMOTE_STATE_WAHANG01: return 340;
        case EMOTE_STATE_WABEGGARSTAND: return 341;
        case EMOTE_STATE_WADRUNKSTAND: return 342;
        case EMOTE_ONESHOT_WACRIERTALK: return 343;
        case EMOTE_STATE_HOLD_CROSSBOW: return 344;
        case EMOTE_STATE_WASIT02: return 345;
        case EMOTE_STATE_WACRANKSTAND: return 346;
        case EMOTE_ONESHOT_READ_START: return 347;
        case EMOTE_ONESHOT_READ_LOOP: return 348;
        case EMOTE_ONESHOT_WADRUNKDRINK: return 349;
        case EMOTE_STATE_SIT_CHAIR_MED_EAT: return 350;
        case EMOTE_STATE_KNEEL_COPY: return 351;
        case EMOTE_STATE_WORK_CHOPMEAT_NOSHEATHE: return 352;
        case EMOTE_ONESHOT_BARPATRON_POINT: return 353;
        case EMOTE_STATE_STAND_NOSOUND: return 354;
        case EMOTE_STATE_MOUNT_FLIGHT_IDLE_NOSOUND: return 355;
        case EMOTE_STATE_USESTANDING_LOOP3: return 356;
        case EMOTE_ONESHOT_VEHICLEGRAB: return 357;
        case EMOTE_STATE_USESTANDING_LOOP4: return 358;
        case EMOTE_STATE_BARPATRON_STAND: return 359;
        case EMOTE_ONESHOT_WABEGGARPOINT: return 360;
        case EMOTE_STATE_WACRIERSTAND01: return 361;
        case EMOTE_ONESHOT_WABEGGARBEG: return 362;
        case EMOTE_STATE_WABOATWHEELSTAND: return 363;
        case EMOTE_STATE_WASIT03: return 364;
        case EMOTE_STATE_BARSWEEP_STAND: return 365;
        case EMOTE_STATE_WAGUARDSTAND05: return 366;
        case EMOTE_STATE_WAGUARDSTAND06: return 367;
        case EMOTE_STATE_BARTENDSTAND: return 368;
        case EMOTE_STATE_WAHAMMERLOOP2: return 369;
        case EMOTE_STATE_WORK_MINING_NO_COMBAT: return 370;
        case EMOTE_ONESHOT_CASTSTRONG: return 371;
        case EMOTE_STATE_CUSTOMSPELL07: return 372;
        case EMOTE_STATE_WALK: return 373;
        case EMOTE_ONESHOT_CLOSE: return 374;
        case EMOTE_STATE_WACRATEHOLD: return 375;
        case EMOTE_STATE_FLYCUSTOMSPELL02: return 376;
        case EMOTE_ONESHOT_SLEEP: return 377;
        case EMOTE_STATE_STAND_SETEMOTESTATE: return 378;
        case EMOTE_ONESHOT_WAWALKTALK: return 379;
        case EMOTE_ONESHOT_TAKE_OFF_FINISH: return 380;
        case EMOTE_ONESHOT_ATTACK2H: return 381;
        case EMOTE_STATE_WA_BARREL_HOLD: return 382;
        case EMOTE_STATE_WA_BARREL_WALK: return 383;
        case EMOTE_STATE_CUSTOMSPELL04: return 384;
        case EMOTE_STATE_FLYWAPERCH01: return 385;
        case EMOTE_ONESHOT_PALSPELLCAST1HUP: return 386;
        case EMOTE_ONESHOT_READYSPELLOMNI: return 387;
        case EMOTE_ONESHOT_SPELLCAST_DIRECTED: return 388;
        case EMOTE_STATE_FLYCUSTOMSPELL07: return 389;
        case EMOTE_STATE_FLYCHANNELCASTOMNI: return 390;
        case EMOTE_STATE_CLOSED: return 391;
        case EMOTE_STATE_CUSTOMSPELL10: return 392;
        case EMOTE_STATE_WAWHEELBARROWSTAND: return 393;
        case EMOTE_STATE_CUSTOMSPELL06: return 394;
        case EMOTE_STATE_CUSTOM1: return 395;
        case EMOTE_STATE_WASIT04: return 396;
        case EMOTE_ONESHOT_BARSWEEP_STAND: return 397;
        case EMOTE_TORGHAST_TALKING_HEAD_MAW_CAST_SOUND: return 398;
        case EMOTE_TORGHAST_TALKING_HEAD_MAW_CAST_SOUND2: return 399;
        case EMOTE_ONESHOT_STAND_VAR0: return 400;
        case EMOTE_ONESHOT_FLYCUSTOMSPELL01: return 401;
        case EMOTE_ONESHOT_SPELLEFFECT_DECAY: return 402;
        case EMOTE_STATE_CREATURE_SPECIAL: return 403;
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
        case CHAT_MSG_ADDON: return { "CHAT_MSG_ADDON", "CHAT_MSG_ADDON", "" };
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
        case CHAT_MSG_RESTRICTED: return { "CHAT_MSG_RESTRICTED", "CHAT_MSG_RESTRICTED", "" };
        case CHAT_MSG_BATTLENET: return { "CHAT_MSG_BATTLENET", "CHAT_MSG_BATTLENET", "" };
        case CHAT_MSG_ACHIEVEMENT: return { "CHAT_MSG_ACHIEVEMENT", "CHAT_MSG_ACHIEVEMENT", "" };
        case CHAT_MSG_GUILD_ACHIEVEMENT: return { "CHAT_MSG_GUILD_ACHIEVEMENT", "CHAT_MSG_GUILD_ACHIEVEMENT", "" };
        case CHAT_MSG_ARENA_POINTS: return { "CHAT_MSG_ARENA_POINTS", "CHAT_MSG_ARENA_POINTS", "" };
        case CHAT_MSG_PARTY_LEADER: return { "CHAT_MSG_PARTY_LEADER", "CHAT_MSG_PARTY_LEADER", "" };
        case CHAT_MSG_TARGETICONS: return { "CHAT_MSG_TARGETICONS", "CHAT_MSG_TARGETICONS", "" };
        case CHAT_MSG_BN_WHISPER: return { "CHAT_MSG_BN_WHISPER", "CHAT_MSG_BN_WHISPER", "" };
        case CHAT_MSG_BN_WHISPER_INFORM: return { "CHAT_MSG_BN_WHISPER_INFORM", "CHAT_MSG_BN_WHISPER_INFORM", "" };
        case CHAT_MSG_BN_CONVERSATION: return { "CHAT_MSG_BN_CONVERSATION", "CHAT_MSG_BN_CONVERSATION", "" };
        case CHAT_MSG_BN_CONVERSATION_NOTICE: return { "CHAT_MSG_BN_CONVERSATION_NOTICE", "CHAT_MSG_BN_CONVERSATION_NOTICE", "" };
        case CHAT_MSG_BN_CONVERSATION_LIST: return { "CHAT_MSG_BN_CONVERSATION_LIST", "CHAT_MSG_BN_CONVERSATION_LIST", "" };
        case CHAT_MSG_BN_INLINE_TOAST_ALERT: return { "CHAT_MSG_BN_INLINE_TOAST_ALERT", "CHAT_MSG_BN_INLINE_TOAST_ALERT", "" };
        case CHAT_MSG_BN_INLINE_TOAST_BROADCAST: return { "CHAT_MSG_BN_INLINE_TOAST_BROADCAST", "CHAT_MSG_BN_INLINE_TOAST_BROADCAST", "" };
        case CHAT_MSG_BN_INLINE_TOAST_BROADCAST_INFORM: return { "CHAT_MSG_BN_INLINE_TOAST_BROADCAST_INFORM", "CHAT_MSG_BN_INLINE_TOAST_BROADCAST_INFORM", "" };
        case CHAT_MSG_BN_INLINE_TOAST_CONVERSATION: return { "CHAT_MSG_BN_INLINE_TOAST_CONVERSATION", "CHAT_MSG_BN_INLINE_TOAST_CONVERSATION", "" };
        case CHAT_MSG_BN_WHISPER_PLAYER_OFFLINE: return { "CHAT_MSG_BN_WHISPER_PLAYER_OFFLINE", "CHAT_MSG_BN_WHISPER_PLAYER_OFFLINE", "" };
        case CHAT_MSG_COMBAT_GUILD_XP_GAIN: return { "CHAT_MSG_COMBAT_GUILD_XP_GAIN", "CHAT_MSG_COMBAT_GUILD_XP_GAIN", "" };
        case CHAT_MSG_CURRENCY: return { "CHAT_MSG_CURRENCY", "CHAT_MSG_CURRENCY", "" };
        case CHAT_MSG_QUEST_BOSS_EMOTE: return { "CHAT_MSG_QUEST_BOSS_EMOTE", "CHAT_MSG_QUEST_BOSS_EMOTE", "" };
        case CHAT_MSG_PET_BATTLE_COMBAT_LOG: return { "CHAT_MSG_PET_BATTLE_COMBAT_LOG", "CHAT_MSG_PET_BATTLE_COMBAT_LOG", "" };
        case CHAT_MSG_PET_BATTLE_INFO: return { "CHAT_MSG_PET_BATTLE_INFO", "CHAT_MSG_PET_BATTLE_INFO", "" };
        case CHAT_MSG_INSTANCE_CHAT: return { "CHAT_MSG_INSTANCE_CHAT", "CHAT_MSG_INSTANCE_CHAT", "" };
        case CHAT_MSG_INSTANCE_CHAT_LEADER: return { "CHAT_MSG_INSTANCE_CHAT_LEADER", "CHAT_MSG_INSTANCE_CHAT_LEADER", "" };
        case MAX_CHAT_MSG_TYPE: return { "MAX_CHAT_MSG_TYPE", "MAX_CHAT_MSG_TYPE", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<ChatMsg>::Count() { return 70; }

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
        case 45: return CHAT_MSG_RESTRICTED;
        case 46: return CHAT_MSG_BATTLENET;
        case 47: return CHAT_MSG_ACHIEVEMENT;
        case 48: return CHAT_MSG_GUILD_ACHIEVEMENT;
        case 49: return CHAT_MSG_ARENA_POINTS;
        case 50: return CHAT_MSG_PARTY_LEADER;
        case 51: return CHAT_MSG_TARGETICONS;
        case 52: return CHAT_MSG_BN_WHISPER;
        case 53: return CHAT_MSG_BN_WHISPER_INFORM;
        case 54: return CHAT_MSG_BN_CONVERSATION;
        case 55: return CHAT_MSG_BN_CONVERSATION_NOTICE;
        case 56: return CHAT_MSG_BN_CONVERSATION_LIST;
        case 57: return CHAT_MSG_BN_INLINE_TOAST_ALERT;
        case 58: return CHAT_MSG_BN_INLINE_TOAST_BROADCAST;
        case 59: return CHAT_MSG_BN_INLINE_TOAST_BROADCAST_INFORM;
        case 60: return CHAT_MSG_BN_INLINE_TOAST_CONVERSATION;
        case 61: return CHAT_MSG_BN_WHISPER_PLAYER_OFFLINE;
        case 62: return CHAT_MSG_COMBAT_GUILD_XP_GAIN;
        case 63: return CHAT_MSG_CURRENCY;
        case 64: return CHAT_MSG_QUEST_BOSS_EMOTE;
        case 65: return CHAT_MSG_PET_BATTLE_COMBAT_LOG;
        case 66: return CHAT_MSG_PET_BATTLE_INFO;
        case 67: return CHAT_MSG_INSTANCE_CHAT;
        case 68: return CHAT_MSG_INSTANCE_CHAT_LEADER;
        case 69: return MAX_CHAT_MSG_TYPE;
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
        case CHAT_MSG_RESTRICTED: return 45;
        case CHAT_MSG_BATTLENET: return 46;
        case CHAT_MSG_ACHIEVEMENT: return 47;
        case CHAT_MSG_GUILD_ACHIEVEMENT: return 48;
        case CHAT_MSG_ARENA_POINTS: return 49;
        case CHAT_MSG_PARTY_LEADER: return 50;
        case CHAT_MSG_TARGETICONS: return 51;
        case CHAT_MSG_BN_WHISPER: return 52;
        case CHAT_MSG_BN_WHISPER_INFORM: return 53;
        case CHAT_MSG_BN_CONVERSATION: return 54;
        case CHAT_MSG_BN_CONVERSATION_NOTICE: return 55;
        case CHAT_MSG_BN_CONVERSATION_LIST: return 56;
        case CHAT_MSG_BN_INLINE_TOAST_ALERT: return 57;
        case CHAT_MSG_BN_INLINE_TOAST_BROADCAST: return 58;
        case CHAT_MSG_BN_INLINE_TOAST_BROADCAST_INFORM: return 59;
        case CHAT_MSG_BN_INLINE_TOAST_CONVERSATION: return 60;
        case CHAT_MSG_BN_WHISPER_PLAYER_OFFLINE: return 61;
        case CHAT_MSG_COMBAT_GUILD_XP_GAIN: return 62;
        case CHAT_MSG_CURRENCY: return 63;
        case CHAT_MSG_QUEST_BOSS_EMOTE: return 64;
        case CHAT_MSG_PET_BATTLE_COMBAT_LOG: return 65;
        case CHAT_MSG_PET_BATTLE_INFO: return 66;
        case CHAT_MSG_INSTANCE_CHAT: return 67;
        case CHAT_MSG_INSTANCE_CHAT_LEADER: return 68;
        case MAX_CHAT_MSG_TYPE: return 69;
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
        case SPELLFAMILY_TOTEMS: return { "SPELLFAMILY_TOTEMS", "SPELLFAMILY_TOTEMS", "" };
        case SPELLFAMILY_MONK: return { "SPELLFAMILY_MONK", "SPELLFAMILY_MONK", "" };
        case SPELLFAMILY_WARLOCK_PET: return { "SPELLFAMILY_WARLOCK_PET", "SPELLFAMILY_WARLOCK_PET", "" };
        case SPELLFAMILY_UNK66: return { "SPELLFAMILY_UNK66", "SPELLFAMILY_UNK66", "" };
        case SPELLFAMILY_UNK71: return { "SPELLFAMILY_UNK71", "SPELLFAMILY_UNK71", "" };
        case SPELLFAMILY_UNK78: return { "SPELLFAMILY_UNK78", "SPELLFAMILY_UNK78", "" };
        case SPELLFAMILY_UNK91: return { "SPELLFAMILY_UNK91", "SPELLFAMILY_UNK91", "" };
        case SPELLFAMILY_UNK100: return { "SPELLFAMILY_UNK100", "SPELLFAMILY_UNK100", "" };
        case SPELLFAMILY_DEMON_HUNTER: return { "SPELLFAMILY_DEMON_HUNTER", "SPELLFAMILY_DEMON_HUNTER", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellFamilyNames>::Count() { return 24; }

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
        case 15: return SPELLFAMILY_TOTEMS;
        case 16: return SPELLFAMILY_MONK;
        case 17: return SPELLFAMILY_WARLOCK_PET;
        case 18: return SPELLFAMILY_UNK66;
        case 19: return SPELLFAMILY_UNK71;
        case 20: return SPELLFAMILY_UNK78;
        case 21: return SPELLFAMILY_UNK91;
        case 22: return SPELLFAMILY_UNK100;
        case 23: return SPELLFAMILY_DEMON_HUNTER;
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
        case SPELLFAMILY_TOTEMS: return 15;
        case SPELLFAMILY_MONK: return 16;
        case SPELLFAMILY_WARLOCK_PET: return 17;
        case SPELLFAMILY_UNK66: return 18;
        case SPELLFAMILY_UNK71: return 19;
        case SPELLFAMILY_UNK78: return 20;
        case SPELLFAMILY_UNK91: return 21;
        case SPELLFAMILY_UNK100: return 22;
        case SPELLFAMILY_DEMON_HUNTER: return 23;
        default: throw std::out_of_range("value");
    }
}
}
