/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

namespace Trinity
{
namespace Impl
{

/*********************************************************************\
|* data for enum 'SpellEffIndex' in 'SharedDefines.h' auto-generated *|
\*********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellEffIndex>::ToString(SpellEffIndex value)
{
    switch (value)
    {
        case EFFECT_0: return { "EFFECT_0", "EFFECT_0", "" };
        case EFFECT_1: return { "EFFECT_1", "EFFECT_1", "" };
        case EFFECT_2: return { "EFFECT_2", "EFFECT_2", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellEffIndex>::Count() { return 3; }

template <>
TC_API_EXPORT SpellEffIndex EnumUtils<SpellEffIndex>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return EFFECT_0;
        case 1: return EFFECT_1;
        case 2: return EFFECT_2;
        default: throw std::out_of_range("index");
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

/***************************************************************************\
|* data for enum 'SpellInterruptFlags' in 'SharedDefines.h' auto-generated *|
\***************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellInterruptFlags>::ToString(SpellInterruptFlags value)
{
    switch (value)
    {
        case SPELL_INTERRUPT_FLAG_MOVEMENT: return { "SPELL_INTERRUPT_FLAG_MOVEMENT", "SPELL_INTERRUPT_FLAG_MOVEMENT", "why need this for instant?" };
        case SPELL_INTERRUPT_FLAG_PUSH_BACK: return { "SPELL_INTERRUPT_FLAG_PUSH_BACK", "SPELL_INTERRUPT_FLAG_PUSH_BACK", "push back" };
        case SPELL_INTERRUPT_FLAG_UNK3: return { "SPELL_INTERRUPT_FLAG_UNK3", "SPELL_INTERRUPT_FLAG_UNK3", "any info?" };
        case SPELL_INTERRUPT_FLAG_INTERRUPT: return { "SPELL_INTERRUPT_FLAG_INTERRUPT", "SPELL_INTERRUPT_FLAG_INTERRUPT", "interrupt" };
        case SPELL_INTERRUPT_FLAG_ABORT_ON_DMG: return { "SPELL_INTERRUPT_FLAG_ABORT_ON_DMG", "SPELL_INTERRUPT_FLAG_ABORT_ON_DMG", "SPELL_INTERRUPT_UNK               = 0x20                // unk, 564 of 727 spells having this spell start with \042Glyph\042" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellInterruptFlags>::Count() { return 5; }

template <>
TC_API_EXPORT SpellInterruptFlags EnumUtils<SpellInterruptFlags>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_INTERRUPT_FLAG_MOVEMENT;
        case 1: return SPELL_INTERRUPT_FLAG_PUSH_BACK;
        case 2: return SPELL_INTERRUPT_FLAG_UNK3;
        case 3: return SPELL_INTERRUPT_FLAG_INTERRUPT;
        case 4: return SPELL_INTERRUPT_FLAG_ABORT_ON_DMG;
        default: throw std::out_of_range("index");
    }
}

/**********************************************************************************\
|* data for enum 'SpellChannelInterruptFlags' in 'SharedDefines.h' auto-generated *|
\**********************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellChannelInterruptFlags>::ToString(SpellChannelInterruptFlags value)
{
    switch (value)
    {
        case CHANNEL_INTERRUPT_FLAG_INTERRUPT: return { "CHANNEL_INTERRUPT_FLAG_INTERRUPT", "CHANNEL_INTERRUPT_FLAG_INTERRUPT", "interrupt" };
        case CHANNEL_FLAG_DELAY: return { "CHANNEL_FLAG_DELAY", "CHANNEL_FLAG_DELAY", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellChannelInterruptFlags>::Count() { return 2; }

template <>
TC_API_EXPORT SpellChannelInterruptFlags EnumUtils<SpellChannelInterruptFlags>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return CHANNEL_INTERRUPT_FLAG_INTERRUPT;
        case 1: return CHANNEL_FLAG_DELAY;
        default: throw std::out_of_range("index");
    }
}

/*******************************************************************************\
|* data for enum 'SpellAuraInterruptFlags' in 'SharedDefines.h' auto-generated *|
\*******************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellAuraInterruptFlags>::ToString(SpellAuraInterruptFlags value)
{
    switch (value)
    {
        case AURA_INTERRUPT_FLAG_HITBYSPELL: return { "AURA_INTERRUPT_FLAG_HITBYSPELL", "AURA_INTERRUPT_FLAG_HITBYSPELL", "0    removed when getting hit by a negative spell?" };
        case AURA_INTERRUPT_FLAG_TAKE_DAMAGE: return { "AURA_INTERRUPT_FLAG_TAKE_DAMAGE", "AURA_INTERRUPT_FLAG_TAKE_DAMAGE", "1    removed by any damage" };
        case AURA_INTERRUPT_FLAG_CAST: return { "AURA_INTERRUPT_FLAG_CAST", "AURA_INTERRUPT_FLAG_CAST", "2    cast any spells" };
        case AURA_INTERRUPT_FLAG_MOVE: return { "AURA_INTERRUPT_FLAG_MOVE", "AURA_INTERRUPT_FLAG_MOVE", "3    removed by any movement" };
        case AURA_INTERRUPT_FLAG_TURNING: return { "AURA_INTERRUPT_FLAG_TURNING", "AURA_INTERRUPT_FLAG_TURNING", "4    removed by any turning" };
        case AURA_INTERRUPT_FLAG_JUMP: return { "AURA_INTERRUPT_FLAG_JUMP", "AURA_INTERRUPT_FLAG_JUMP", "5    removed by entering combat" };
        case AURA_INTERRUPT_FLAG_NOT_MOUNTED: return { "AURA_INTERRUPT_FLAG_NOT_MOUNTED", "AURA_INTERRUPT_FLAG_NOT_MOUNTED", "6    removed by dismounting" };
        case AURA_INTERRUPT_FLAG_NOT_ABOVEWATER: return { "AURA_INTERRUPT_FLAG_NOT_ABOVEWATER", "AURA_INTERRUPT_FLAG_NOT_ABOVEWATER", "7    removed by entering water" };
        case AURA_INTERRUPT_FLAG_NOT_UNDERWATER: return { "AURA_INTERRUPT_FLAG_NOT_UNDERWATER", "AURA_INTERRUPT_FLAG_NOT_UNDERWATER", "8    removed by leaving water" };
        case AURA_INTERRUPT_FLAG_NOT_SHEATHED: return { "AURA_INTERRUPT_FLAG_NOT_SHEATHED", "AURA_INTERRUPT_FLAG_NOT_SHEATHED", "9    removed by unsheathing" };
        case AURA_INTERRUPT_FLAG_TALK: return { "AURA_INTERRUPT_FLAG_TALK", "AURA_INTERRUPT_FLAG_TALK", "10   talk to npc / loot? action on creature" };
        case AURA_INTERRUPT_FLAG_USE: return { "AURA_INTERRUPT_FLAG_USE", "AURA_INTERRUPT_FLAG_USE", "11   mine/use/open action on gameobject" };
        case AURA_INTERRUPT_FLAG_MELEE_ATTACK: return { "AURA_INTERRUPT_FLAG_MELEE_ATTACK", "AURA_INTERRUPT_FLAG_MELEE_ATTACK", "12   removed by attacking" };
        case AURA_INTERRUPT_FLAG_SPELL_ATTACK: return { "AURA_INTERRUPT_FLAG_SPELL_ATTACK", "AURA_INTERRUPT_FLAG_SPELL_ATTACK", "13   ???" };
        case AURA_INTERRUPT_FLAG_UNK14: return { "AURA_INTERRUPT_FLAG_UNK14", "AURA_INTERRUPT_FLAG_UNK14", "14" };
        case AURA_INTERRUPT_FLAG_TRANSFORM: return { "AURA_INTERRUPT_FLAG_TRANSFORM", "AURA_INTERRUPT_FLAG_TRANSFORM", "15   removed by transform?" };
        case AURA_INTERRUPT_FLAG_UNK16: return { "AURA_INTERRUPT_FLAG_UNK16", "AURA_INTERRUPT_FLAG_UNK16", "16" };
        case AURA_INTERRUPT_FLAG_MOUNT: return { "AURA_INTERRUPT_FLAG_MOUNT", "AURA_INTERRUPT_FLAG_MOUNT", "17   misdirect, aspect, swim speed" };
        case AURA_INTERRUPT_FLAG_NOT_SEATED: return { "AURA_INTERRUPT_FLAG_NOT_SEATED", "AURA_INTERRUPT_FLAG_NOT_SEATED", "18   removed by standing up (used by food and drink mostly and sleep/Fake Death like)" };
        case AURA_INTERRUPT_FLAG_CHANGE_MAP: return { "AURA_INTERRUPT_FLAG_CHANGE_MAP", "AURA_INTERRUPT_FLAG_CHANGE_MAP", "19   leaving map/getting teleported" };
        case AURA_INTERRUPT_FLAG_IMMUNE_OR_LOST_SELECTION: return { "AURA_INTERRUPT_FLAG_IMMUNE_OR_LOST_SELECTION", "AURA_INTERRUPT_FLAG_IMMUNE_OR_LOST_SELECTION", "20   removed by auras that make you invulnerable, or make other to lose selection on you" };
        case AURA_INTERRUPT_FLAG_UNK21: return { "AURA_INTERRUPT_FLAG_UNK21", "AURA_INTERRUPT_FLAG_UNK21", "21" };
        case AURA_INTERRUPT_FLAG_TELEPORTED: return { "AURA_INTERRUPT_FLAG_TELEPORTED", "AURA_INTERRUPT_FLAG_TELEPORTED", "22" };
        case AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT: return { "AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT", "AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT", "23   removed by entering pvp combat" };
        case AURA_INTERRUPT_FLAG_DIRECT_DAMAGE: return { "AURA_INTERRUPT_FLAG_DIRECT_DAMAGE", "AURA_INTERRUPT_FLAG_DIRECT_DAMAGE", "24   removed by any direct damage" };
        case AURA_INTERRUPT_FLAG_LANDING: return { "AURA_INTERRUPT_FLAG_LANDING", "AURA_INTERRUPT_FLAG_LANDING", "25   removed by hitting the ground" };
        case AURA_INTERRUPT_FLAG_LEAVE_COMBAT: return { "AURA_INTERRUPT_FLAG_LEAVE_COMBAT", "AURA_INTERRUPT_FLAG_LEAVE_COMBAT", "31   removed by leaving combat" };
        case AURA_INTERRUPT_FLAG_NOT_VICTIM: return { "AURA_INTERRUPT_FLAG_NOT_VICTIM", "AURA_INTERRUPT_FLAG_NOT_VICTIM", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellAuraInterruptFlags>::Count() { return 28; }

template <>
TC_API_EXPORT SpellAuraInterruptFlags EnumUtils<SpellAuraInterruptFlags>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return AURA_INTERRUPT_FLAG_HITBYSPELL;
        case 1: return AURA_INTERRUPT_FLAG_TAKE_DAMAGE;
        case 2: return AURA_INTERRUPT_FLAG_CAST;
        case 3: return AURA_INTERRUPT_FLAG_MOVE;
        case 4: return AURA_INTERRUPT_FLAG_TURNING;
        case 5: return AURA_INTERRUPT_FLAG_JUMP;
        case 6: return AURA_INTERRUPT_FLAG_NOT_MOUNTED;
        case 7: return AURA_INTERRUPT_FLAG_NOT_ABOVEWATER;
        case 8: return AURA_INTERRUPT_FLAG_NOT_UNDERWATER;
        case 9: return AURA_INTERRUPT_FLAG_NOT_SHEATHED;
        case 10: return AURA_INTERRUPT_FLAG_TALK;
        case 11: return AURA_INTERRUPT_FLAG_USE;
        case 12: return AURA_INTERRUPT_FLAG_MELEE_ATTACK;
        case 13: return AURA_INTERRUPT_FLAG_SPELL_ATTACK;
        case 14: return AURA_INTERRUPT_FLAG_UNK14;
        case 15: return AURA_INTERRUPT_FLAG_TRANSFORM;
        case 16: return AURA_INTERRUPT_FLAG_UNK16;
        case 17: return AURA_INTERRUPT_FLAG_MOUNT;
        case 18: return AURA_INTERRUPT_FLAG_NOT_SEATED;
        case 19: return AURA_INTERRUPT_FLAG_CHANGE_MAP;
        case 20: return AURA_INTERRUPT_FLAG_IMMUNE_OR_LOST_SELECTION;
        case 21: return AURA_INTERRUPT_FLAG_UNK21;
        case 22: return AURA_INTERRUPT_FLAG_TELEPORTED;
        case 23: return AURA_INTERRUPT_FLAG_ENTER_PVP_COMBAT;
        case 24: return AURA_INTERRUPT_FLAG_DIRECT_DAMAGE;
        case 25: return AURA_INTERRUPT_FLAG_LANDING;
        case 26: return AURA_INTERRUPT_FLAG_LEAVE_COMBAT;
        case 27: return AURA_INTERRUPT_FLAG_NOT_VICTIM;
        default: throw std::out_of_range("index");
    }
}

/********************************************************************\
|* data for enum 'SpellEffects' in 'SharedDefines.h' auto-generated *|
\********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<SpellEffects>::ToString(SpellEffects value)
{
    switch (value)
    {
        case SPELL_EFFECT_INSTAKILL: return { "SPELL_EFFECT_INSTAKILL", "SPELL_EFFECT_INSTAKILL", "" };
        case SPELL_EFFECT_SCHOOL_DAMAGE: return { "SPELL_EFFECT_SCHOOL_DAMAGE", "SPELL_EFFECT_SCHOOL_DAMAGE", "" };
        case SPELL_EFFECT_DUMMY: return { "SPELL_EFFECT_DUMMY", "SPELL_EFFECT_DUMMY", "" };
        case SPELL_EFFECT_PORTAL_TELEPORT: return { "SPELL_EFFECT_PORTAL_TELEPORT", "SPELL_EFFECT_PORTAL_TELEPORT", "" };
        case SPELL_EFFECT_TELEPORT_UNITS: return { "SPELL_EFFECT_TELEPORT_UNITS", "SPELL_EFFECT_TELEPORT_UNITS", "" };
        case SPELL_EFFECT_APPLY_AURA: return { "SPELL_EFFECT_APPLY_AURA", "SPELL_EFFECT_APPLY_AURA", "" };
        case SPELL_EFFECT_ENVIRONMENTAL_DAMAGE: return { "SPELL_EFFECT_ENVIRONMENTAL_DAMAGE", "SPELL_EFFECT_ENVIRONMENTAL_DAMAGE", "" };
        case SPELL_EFFECT_POWER_DRAIN: return { "SPELL_EFFECT_POWER_DRAIN", "SPELL_EFFECT_POWER_DRAIN", "" };
        case SPELL_EFFECT_HEALTH_LEECH: return { "SPELL_EFFECT_HEALTH_LEECH", "SPELL_EFFECT_HEALTH_LEECH", "" };
        case SPELL_EFFECT_HEAL: return { "SPELL_EFFECT_HEAL", "SPELL_EFFECT_HEAL", "" };
        case SPELL_EFFECT_BIND: return { "SPELL_EFFECT_BIND", "SPELL_EFFECT_BIND", "" };
        case SPELL_EFFECT_PORTAL: return { "SPELL_EFFECT_PORTAL", "SPELL_EFFECT_PORTAL", "" };
        case SPELL_EFFECT_RITUAL_BASE: return { "SPELL_EFFECT_RITUAL_BASE", "SPELL_EFFECT_RITUAL_BASE", "" };
        case SPELL_EFFECT_RITUAL_SPECIALIZE: return { "SPELL_EFFECT_RITUAL_SPECIALIZE", "SPELL_EFFECT_RITUAL_SPECIALIZE", "" };
        case SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL: return { "SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL", "SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL", "" };
        case SPELL_EFFECT_QUEST_COMPLETE: return { "SPELL_EFFECT_QUEST_COMPLETE", "SPELL_EFFECT_QUEST_COMPLETE", "" };
        case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL: return { "SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL", "SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL", "" };
        case SPELL_EFFECT_RESURRECT: return { "SPELL_EFFECT_RESURRECT", "SPELL_EFFECT_RESURRECT", "" };
        case SPELL_EFFECT_ADD_EXTRA_ATTACKS: return { "SPELL_EFFECT_ADD_EXTRA_ATTACKS", "SPELL_EFFECT_ADD_EXTRA_ATTACKS", "" };
        case SPELL_EFFECT_DODGE: return { "SPELL_EFFECT_DODGE", "SPELL_EFFECT_DODGE", "" };
        case SPELL_EFFECT_EVADE: return { "SPELL_EFFECT_EVADE", "SPELL_EFFECT_EVADE", "" };
        case SPELL_EFFECT_PARRY: return { "SPELL_EFFECT_PARRY", "SPELL_EFFECT_PARRY", "" };
        case SPELL_EFFECT_BLOCK: return { "SPELL_EFFECT_BLOCK", "SPELL_EFFECT_BLOCK", "" };
        case SPELL_EFFECT_CREATE_ITEM: return { "SPELL_EFFECT_CREATE_ITEM", "SPELL_EFFECT_CREATE_ITEM", "" };
        case SPELL_EFFECT_WEAPON: return { "SPELL_EFFECT_WEAPON", "SPELL_EFFECT_WEAPON", "" };
        case SPELL_EFFECT_DEFENSE: return { "SPELL_EFFECT_DEFENSE", "SPELL_EFFECT_DEFENSE", "" };
        case SPELL_EFFECT_PERSISTENT_AREA_AURA: return { "SPELL_EFFECT_PERSISTENT_AREA_AURA", "SPELL_EFFECT_PERSISTENT_AREA_AURA", "" };
        case SPELL_EFFECT_SUMMON: return { "SPELL_EFFECT_SUMMON", "SPELL_EFFECT_SUMMON", "" };
        case SPELL_EFFECT_LEAP: return { "SPELL_EFFECT_LEAP", "SPELL_EFFECT_LEAP", "" };
        case SPELL_EFFECT_ENERGIZE: return { "SPELL_EFFECT_ENERGIZE", "SPELL_EFFECT_ENERGIZE", "" };
        case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE: return { "SPELL_EFFECT_WEAPON_PERCENT_DAMAGE", "SPELL_EFFECT_WEAPON_PERCENT_DAMAGE", "" };
        case SPELL_EFFECT_TRIGGER_MISSILE: return { "SPELL_EFFECT_TRIGGER_MISSILE", "SPELL_EFFECT_TRIGGER_MISSILE", "" };
        case SPELL_EFFECT_OPEN_LOCK: return { "SPELL_EFFECT_OPEN_LOCK", "SPELL_EFFECT_OPEN_LOCK", "" };
        case SPELL_EFFECT_SUMMON_CHANGE_ITEM: return { "SPELL_EFFECT_SUMMON_CHANGE_ITEM", "SPELL_EFFECT_SUMMON_CHANGE_ITEM", "" };
        case SPELL_EFFECT_APPLY_AREA_AURA_PARTY: return { "SPELL_EFFECT_APPLY_AREA_AURA_PARTY", "SPELL_EFFECT_APPLY_AREA_AURA_PARTY", "" };
        case SPELL_EFFECT_LEARN_SPELL: return { "SPELL_EFFECT_LEARN_SPELL", "SPELL_EFFECT_LEARN_SPELL", "" };
        case SPELL_EFFECT_SPELL_DEFENSE: return { "SPELL_EFFECT_SPELL_DEFENSE", "SPELL_EFFECT_SPELL_DEFENSE", "" };
        case SPELL_EFFECT_DISPEL: return { "SPELL_EFFECT_DISPEL", "SPELL_EFFECT_DISPEL", "" };
        case SPELL_EFFECT_LANGUAGE: return { "SPELL_EFFECT_LANGUAGE", "SPELL_EFFECT_LANGUAGE", "" };
        case SPELL_EFFECT_DUAL_WIELD: return { "SPELL_EFFECT_DUAL_WIELD", "SPELL_EFFECT_DUAL_WIELD", "" };
        case SPELL_EFFECT_JUMP: return { "SPELL_EFFECT_JUMP", "SPELL_EFFECT_JUMP", "" };
        case SPELL_EFFECT_JUMP_DEST: return { "SPELL_EFFECT_JUMP_DEST", "SPELL_EFFECT_JUMP_DEST", "" };
        case SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER: return { "SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER", "SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER", "" };
        case SPELL_EFFECT_SKILL_STEP: return { "SPELL_EFFECT_SKILL_STEP", "SPELL_EFFECT_SKILL_STEP", "" };
        case SPELL_EFFECT_ADD_HONOR: return { "SPELL_EFFECT_ADD_HONOR", "SPELL_EFFECT_ADD_HONOR", "" };
        case SPELL_EFFECT_SPAWN: return { "SPELL_EFFECT_SPAWN", "SPELL_EFFECT_SPAWN", "" };
        case SPELL_EFFECT_TRADE_SKILL: return { "SPELL_EFFECT_TRADE_SKILL", "SPELL_EFFECT_TRADE_SKILL", "" };
        case SPELL_EFFECT_STEALTH: return { "SPELL_EFFECT_STEALTH", "SPELL_EFFECT_STEALTH", "" };
        case SPELL_EFFECT_DETECT: return { "SPELL_EFFECT_DETECT", "SPELL_EFFECT_DETECT", "" };
        case SPELL_EFFECT_TRANS_DOOR: return { "SPELL_EFFECT_TRANS_DOOR", "SPELL_EFFECT_TRANS_DOOR", "" };
        case SPELL_EFFECT_FORCE_CRITICAL_HIT: return { "SPELL_EFFECT_FORCE_CRITICAL_HIT", "SPELL_EFFECT_FORCE_CRITICAL_HIT", "" };
        case SPELL_EFFECT_GUARANTEE_HIT: return { "SPELL_EFFECT_GUARANTEE_HIT", "SPELL_EFFECT_GUARANTEE_HIT", "" };
        case SPELL_EFFECT_ENCHANT_ITEM: return { "SPELL_EFFECT_ENCHANT_ITEM", "SPELL_EFFECT_ENCHANT_ITEM", "" };
        case SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY: return { "SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY", "SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY", "" };
        case SPELL_EFFECT_TAMECREATURE: return { "SPELL_EFFECT_TAMECREATURE", "SPELL_EFFECT_TAMECREATURE", "" };
        case SPELL_EFFECT_SUMMON_PET: return { "SPELL_EFFECT_SUMMON_PET", "SPELL_EFFECT_SUMMON_PET", "" };
        case SPELL_EFFECT_LEARN_PET_SPELL: return { "SPELL_EFFECT_LEARN_PET_SPELL", "SPELL_EFFECT_LEARN_PET_SPELL", "" };
        case SPELL_EFFECT_WEAPON_DAMAGE: return { "SPELL_EFFECT_WEAPON_DAMAGE", "SPELL_EFFECT_WEAPON_DAMAGE", "" };
        case SPELL_EFFECT_CREATE_RANDOM_ITEM: return { "SPELL_EFFECT_CREATE_RANDOM_ITEM", "SPELL_EFFECT_CREATE_RANDOM_ITEM", "" };
        case SPELL_EFFECT_PROFICIENCY: return { "SPELL_EFFECT_PROFICIENCY", "SPELL_EFFECT_PROFICIENCY", "" };
        case SPELL_EFFECT_SEND_EVENT: return { "SPELL_EFFECT_SEND_EVENT", "SPELL_EFFECT_SEND_EVENT", "" };
        case SPELL_EFFECT_POWER_BURN: return { "SPELL_EFFECT_POWER_BURN", "SPELL_EFFECT_POWER_BURN", "" };
        case SPELL_EFFECT_THREAT: return { "SPELL_EFFECT_THREAT", "SPELL_EFFECT_THREAT", "" };
        case SPELL_EFFECT_TRIGGER_SPELL: return { "SPELL_EFFECT_TRIGGER_SPELL", "SPELL_EFFECT_TRIGGER_SPELL", "" };
        case SPELL_EFFECT_APPLY_AREA_AURA_RAID: return { "SPELL_EFFECT_APPLY_AREA_AURA_RAID", "SPELL_EFFECT_APPLY_AREA_AURA_RAID", "" };
        case SPELL_EFFECT_CREATE_MANA_GEM: return { "SPELL_EFFECT_CREATE_MANA_GEM", "SPELL_EFFECT_CREATE_MANA_GEM", "" };
        case SPELL_EFFECT_HEAL_MAX_HEALTH: return { "SPELL_EFFECT_HEAL_MAX_HEALTH", "SPELL_EFFECT_HEAL_MAX_HEALTH", "" };
        case SPELL_EFFECT_INTERRUPT_CAST: return { "SPELL_EFFECT_INTERRUPT_CAST", "SPELL_EFFECT_INTERRUPT_CAST", "" };
        case SPELL_EFFECT_DISTRACT: return { "SPELL_EFFECT_DISTRACT", "SPELL_EFFECT_DISTRACT", "" };
        case SPELL_EFFECT_PULL: return { "SPELL_EFFECT_PULL", "SPELL_EFFECT_PULL", "" };
        case SPELL_EFFECT_PICKPOCKET: return { "SPELL_EFFECT_PICKPOCKET", "SPELL_EFFECT_PICKPOCKET", "" };
        case SPELL_EFFECT_ADD_FARSIGHT: return { "SPELL_EFFECT_ADD_FARSIGHT", "SPELL_EFFECT_ADD_FARSIGHT", "" };
        case SPELL_EFFECT_UNTRAIN_TALENTS: return { "SPELL_EFFECT_UNTRAIN_TALENTS", "SPELL_EFFECT_UNTRAIN_TALENTS", "" };
        case SPELL_EFFECT_APPLY_GLYPH: return { "SPELL_EFFECT_APPLY_GLYPH", "SPELL_EFFECT_APPLY_GLYPH", "" };
        case SPELL_EFFECT_HEAL_MECHANICAL: return { "SPELL_EFFECT_HEAL_MECHANICAL", "SPELL_EFFECT_HEAL_MECHANICAL", "" };
        case SPELL_EFFECT_SUMMON_OBJECT_WILD: return { "SPELL_EFFECT_SUMMON_OBJECT_WILD", "SPELL_EFFECT_SUMMON_OBJECT_WILD", "" };
        case SPELL_EFFECT_SCRIPT_EFFECT: return { "SPELL_EFFECT_SCRIPT_EFFECT", "SPELL_EFFECT_SCRIPT_EFFECT", "" };
        case SPELL_EFFECT_ATTACK: return { "SPELL_EFFECT_ATTACK", "SPELL_EFFECT_ATTACK", "" };
        case SPELL_EFFECT_SANCTUARY: return { "SPELL_EFFECT_SANCTUARY", "SPELL_EFFECT_SANCTUARY", "" };
        case SPELL_EFFECT_ADD_COMBO_POINTS: return { "SPELL_EFFECT_ADD_COMBO_POINTS", "SPELL_EFFECT_ADD_COMBO_POINTS", "" };
        case SPELL_EFFECT_CREATE_HOUSE: return { "SPELL_EFFECT_CREATE_HOUSE", "SPELL_EFFECT_CREATE_HOUSE", "" };
        case SPELL_EFFECT_BIND_SIGHT: return { "SPELL_EFFECT_BIND_SIGHT", "SPELL_EFFECT_BIND_SIGHT", "" };
        case SPELL_EFFECT_DUEL: return { "SPELL_EFFECT_DUEL", "SPELL_EFFECT_DUEL", "" };
        case SPELL_EFFECT_STUCK: return { "SPELL_EFFECT_STUCK", "SPELL_EFFECT_STUCK", "" };
        case SPELL_EFFECT_SUMMON_PLAYER: return { "SPELL_EFFECT_SUMMON_PLAYER", "SPELL_EFFECT_SUMMON_PLAYER", "" };
        case SPELL_EFFECT_ACTIVATE_OBJECT: return { "SPELL_EFFECT_ACTIVATE_OBJECT", "SPELL_EFFECT_ACTIVATE_OBJECT", "" };
        case SPELL_EFFECT_GAMEOBJECT_DAMAGE: return { "SPELL_EFFECT_GAMEOBJECT_DAMAGE", "SPELL_EFFECT_GAMEOBJECT_DAMAGE", "" };
        case SPELL_EFFECT_GAMEOBJECT_REPAIR: return { "SPELL_EFFECT_GAMEOBJECT_REPAIR", "SPELL_EFFECT_GAMEOBJECT_REPAIR", "" };
        case SPELL_EFFECT_GAMEOBJECT_SET_DESTRUCTION_STATE: return { "SPELL_EFFECT_GAMEOBJECT_SET_DESTRUCTION_STATE", "SPELL_EFFECT_GAMEOBJECT_SET_DESTRUCTION_STATE", "" };
        case SPELL_EFFECT_KILL_CREDIT: return { "SPELL_EFFECT_KILL_CREDIT", "SPELL_EFFECT_KILL_CREDIT", "" };
        case SPELL_EFFECT_THREAT_ALL: return { "SPELL_EFFECT_THREAT_ALL", "SPELL_EFFECT_THREAT_ALL", "" };
        case SPELL_EFFECT_ENCHANT_HELD_ITEM: return { "SPELL_EFFECT_ENCHANT_HELD_ITEM", "SPELL_EFFECT_ENCHANT_HELD_ITEM", "" };
        case SPELL_EFFECT_FORCE_DESELECT: return { "SPELL_EFFECT_FORCE_DESELECT", "SPELL_EFFECT_FORCE_DESELECT", "" };
        case SPELL_EFFECT_SELF_RESURRECT: return { "SPELL_EFFECT_SELF_RESURRECT", "SPELL_EFFECT_SELF_RESURRECT", "" };
        case SPELL_EFFECT_SKINNING: return { "SPELL_EFFECT_SKINNING", "SPELL_EFFECT_SKINNING", "" };
        case SPELL_EFFECT_CHARGE: return { "SPELL_EFFECT_CHARGE", "SPELL_EFFECT_CHARGE", "" };
        case SPELL_EFFECT_CAST_BUTTON: return { "SPELL_EFFECT_CAST_BUTTON", "SPELL_EFFECT_CAST_BUTTON", "" };
        case SPELL_EFFECT_KNOCK_BACK: return { "SPELL_EFFECT_KNOCK_BACK", "SPELL_EFFECT_KNOCK_BACK", "" };
        case SPELL_EFFECT_DISENCHANT: return { "SPELL_EFFECT_DISENCHANT", "SPELL_EFFECT_DISENCHANT", "" };
        case SPELL_EFFECT_INEBRIATE: return { "SPELL_EFFECT_INEBRIATE", "SPELL_EFFECT_INEBRIATE", "" };
        case SPELL_EFFECT_FEED_PET: return { "SPELL_EFFECT_FEED_PET", "SPELL_EFFECT_FEED_PET", "" };
        case SPELL_EFFECT_DISMISS_PET: return { "SPELL_EFFECT_DISMISS_PET", "SPELL_EFFECT_DISMISS_PET", "" };
        case SPELL_EFFECT_REPUTATION: return { "SPELL_EFFECT_REPUTATION", "SPELL_EFFECT_REPUTATION", "" };
        case SPELL_EFFECT_SUMMON_OBJECT_SLOT1: return { "SPELL_EFFECT_SUMMON_OBJECT_SLOT1", "SPELL_EFFECT_SUMMON_OBJECT_SLOT1", "" };
        case SPELL_EFFECT_SUMMON_OBJECT_SLOT2: return { "SPELL_EFFECT_SUMMON_OBJECT_SLOT2", "SPELL_EFFECT_SUMMON_OBJECT_SLOT2", "" };
        case SPELL_EFFECT_SUMMON_OBJECT_SLOT3: return { "SPELL_EFFECT_SUMMON_OBJECT_SLOT3", "SPELL_EFFECT_SUMMON_OBJECT_SLOT3", "" };
        case SPELL_EFFECT_SUMMON_OBJECT_SLOT4: return { "SPELL_EFFECT_SUMMON_OBJECT_SLOT4", "SPELL_EFFECT_SUMMON_OBJECT_SLOT4", "" };
        case SPELL_EFFECT_DISPEL_MECHANIC: return { "SPELL_EFFECT_DISPEL_MECHANIC", "SPELL_EFFECT_DISPEL_MECHANIC", "" };
        case SPELL_EFFECT_RESURRECT_PET: return { "SPELL_EFFECT_RESURRECT_PET", "SPELL_EFFECT_RESURRECT_PET", "" };
        case SPELL_EFFECT_DESTROY_ALL_TOTEMS: return { "SPELL_EFFECT_DESTROY_ALL_TOTEMS", "SPELL_EFFECT_DESTROY_ALL_TOTEMS", "" };
        case SPELL_EFFECT_DURABILITY_DAMAGE: return { "SPELL_EFFECT_DURABILITY_DAMAGE", "SPELL_EFFECT_DURABILITY_DAMAGE", "" };
        case SPELL_EFFECT_112: return { "SPELL_EFFECT_112", "SPELL_EFFECT_112", "" };
        case SPELL_EFFECT_RESURRECT_NEW: return { "SPELL_EFFECT_RESURRECT_NEW", "SPELL_EFFECT_RESURRECT_NEW", "" };
        case SPELL_EFFECT_ATTACK_ME: return { "SPELL_EFFECT_ATTACK_ME", "SPELL_EFFECT_ATTACK_ME", "" };
        case SPELL_EFFECT_DURABILITY_DAMAGE_PCT: return { "SPELL_EFFECT_DURABILITY_DAMAGE_PCT", "SPELL_EFFECT_DURABILITY_DAMAGE_PCT", "" };
        case SPELL_EFFECT_SKIN_PLAYER_CORPSE: return { "SPELL_EFFECT_SKIN_PLAYER_CORPSE", "SPELL_EFFECT_SKIN_PLAYER_CORPSE", "" };
        case SPELL_EFFECT_SPIRIT_HEAL: return { "SPELL_EFFECT_SPIRIT_HEAL", "SPELL_EFFECT_SPIRIT_HEAL", "" };
        case SPELL_EFFECT_SKILL: return { "SPELL_EFFECT_SKILL", "SPELL_EFFECT_SKILL", "" };
        case SPELL_EFFECT_APPLY_AREA_AURA_PET: return { "SPELL_EFFECT_APPLY_AREA_AURA_PET", "SPELL_EFFECT_APPLY_AREA_AURA_PET", "" };
        case SPELL_EFFECT_TELEPORT_GRAVEYARD: return { "SPELL_EFFECT_TELEPORT_GRAVEYARD", "SPELL_EFFECT_TELEPORT_GRAVEYARD", "" };
        case SPELL_EFFECT_NORMALIZED_WEAPON_DMG: return { "SPELL_EFFECT_NORMALIZED_WEAPON_DMG", "SPELL_EFFECT_NORMALIZED_WEAPON_DMG", "" };
        case SPELL_EFFECT_122: return { "SPELL_EFFECT_122", "SPELL_EFFECT_122", "" };
        case SPELL_EFFECT_SEND_TAXI: return { "SPELL_EFFECT_SEND_TAXI", "SPELL_EFFECT_SEND_TAXI", "" };
        case SPELL_EFFECT_PULL_TOWARDS: return { "SPELL_EFFECT_PULL_TOWARDS", "SPELL_EFFECT_PULL_TOWARDS", "" };
        case SPELL_EFFECT_MODIFY_THREAT_PERCENT: return { "SPELL_EFFECT_MODIFY_THREAT_PERCENT", "SPELL_EFFECT_MODIFY_THREAT_PERCENT", "" };
        case SPELL_EFFECT_STEAL_BENEFICIAL_BUFF: return { "SPELL_EFFECT_STEAL_BENEFICIAL_BUFF", "SPELL_EFFECT_STEAL_BENEFICIAL_BUFF", "" };
        case SPELL_EFFECT_PROSPECTING: return { "SPELL_EFFECT_PROSPECTING", "SPELL_EFFECT_PROSPECTING", "" };
        case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND: return { "SPELL_EFFECT_APPLY_AREA_AURA_FRIEND", "SPELL_EFFECT_APPLY_AREA_AURA_FRIEND", "" };
        case SPELL_EFFECT_APPLY_AREA_AURA_ENEMY: return { "SPELL_EFFECT_APPLY_AREA_AURA_ENEMY", "SPELL_EFFECT_APPLY_AREA_AURA_ENEMY", "" };
        case SPELL_EFFECT_REDIRECT_THREAT: return { "SPELL_EFFECT_REDIRECT_THREAT", "SPELL_EFFECT_REDIRECT_THREAT", "" };
        case SPELL_EFFECT_PLAY_SOUND: return { "SPELL_EFFECT_PLAY_SOUND", "SPELL_EFFECT_PLAY_SOUND", "" };
        case SPELL_EFFECT_PLAY_MUSIC: return { "SPELL_EFFECT_PLAY_MUSIC", "SPELL_EFFECT_PLAY_MUSIC", "" };
        case SPELL_EFFECT_UNLEARN_SPECIALIZATION: return { "SPELL_EFFECT_UNLEARN_SPECIALIZATION", "SPELL_EFFECT_UNLEARN_SPECIALIZATION", "" };
        case SPELL_EFFECT_KILL_CREDIT2: return { "SPELL_EFFECT_KILL_CREDIT2", "SPELL_EFFECT_KILL_CREDIT2", "" };
        case SPELL_EFFECT_CALL_PET: return { "SPELL_EFFECT_CALL_PET", "SPELL_EFFECT_CALL_PET", "" };
        case SPELL_EFFECT_HEAL_PCT: return { "SPELL_EFFECT_HEAL_PCT", "SPELL_EFFECT_HEAL_PCT", "" };
        case SPELL_EFFECT_ENERGIZE_PCT: return { "SPELL_EFFECT_ENERGIZE_PCT", "SPELL_EFFECT_ENERGIZE_PCT", "" };
        case SPELL_EFFECT_LEAP_BACK: return { "SPELL_EFFECT_LEAP_BACK", "SPELL_EFFECT_LEAP_BACK", "" };
        case SPELL_EFFECT_CLEAR_QUEST: return { "SPELL_EFFECT_CLEAR_QUEST", "SPELL_EFFECT_CLEAR_QUEST", "" };
        case SPELL_EFFECT_FORCE_CAST: return { "SPELL_EFFECT_FORCE_CAST", "SPELL_EFFECT_FORCE_CAST", "" };
        case SPELL_EFFECT_FORCE_CAST_WITH_VALUE: return { "SPELL_EFFECT_FORCE_CAST_WITH_VALUE", "SPELL_EFFECT_FORCE_CAST_WITH_VALUE", "" };
        case SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE: return { "SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE", "SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE", "" };
        case SPELL_EFFECT_APPLY_AREA_AURA_OWNER: return { "SPELL_EFFECT_APPLY_AREA_AURA_OWNER", "SPELL_EFFECT_APPLY_AREA_AURA_OWNER", "" };
        case SPELL_EFFECT_KNOCK_BACK_DEST: return { "SPELL_EFFECT_KNOCK_BACK_DEST", "SPELL_EFFECT_KNOCK_BACK_DEST", "" };
        case SPELL_EFFECT_PULL_TOWARDS_DEST: return { "SPELL_EFFECT_PULL_TOWARDS_DEST", "SPELL_EFFECT_PULL_TOWARDS_DEST", "" };
        case SPELL_EFFECT_ACTIVATE_RUNE: return { "SPELL_EFFECT_ACTIVATE_RUNE", "SPELL_EFFECT_ACTIVATE_RUNE", "" };
        case SPELL_EFFECT_QUEST_FAIL: return { "SPELL_EFFECT_QUEST_FAIL", "SPELL_EFFECT_QUEST_FAIL", "" };
        case SPELL_EFFECT_TRIGGER_MISSILE_SPELL_WITH_VALUE: return { "SPELL_EFFECT_TRIGGER_MISSILE_SPELL_WITH_VALUE", "SPELL_EFFECT_TRIGGER_MISSILE_SPELL_WITH_VALUE", "" };
        case SPELL_EFFECT_CHARGE_DEST: return { "SPELL_EFFECT_CHARGE_DEST", "SPELL_EFFECT_CHARGE_DEST", "" };
        case SPELL_EFFECT_QUEST_START: return { "SPELL_EFFECT_QUEST_START", "SPELL_EFFECT_QUEST_START", "" };
        case SPELL_EFFECT_TRIGGER_SPELL_2: return { "SPELL_EFFECT_TRIGGER_SPELL_2", "SPELL_EFFECT_TRIGGER_SPELL_2", "" };
        case SPELL_EFFECT_SUMMON_RAF_FRIEND: return { "SPELL_EFFECT_SUMMON_RAF_FRIEND", "SPELL_EFFECT_SUMMON_RAF_FRIEND", "" };
        case SPELL_EFFECT_CREATE_TAMED_PET: return { "SPELL_EFFECT_CREATE_TAMED_PET", "SPELL_EFFECT_CREATE_TAMED_PET", "" };
        case SPELL_EFFECT_DISCOVER_TAXI: return { "SPELL_EFFECT_DISCOVER_TAXI", "SPELL_EFFECT_DISCOVER_TAXI", "" };
        case SPELL_EFFECT_TITAN_GRIP: return { "SPELL_EFFECT_TITAN_GRIP", "SPELL_EFFECT_TITAN_GRIP", "" };
        case SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC: return { "SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC", "SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC", "" };
        case SPELL_EFFECT_CREATE_ITEM_2: return { "SPELL_EFFECT_CREATE_ITEM_2", "SPELL_EFFECT_CREATE_ITEM_2", "" };
        case SPELL_EFFECT_MILLING: return { "SPELL_EFFECT_MILLING", "SPELL_EFFECT_MILLING", "" };
        case SPELL_EFFECT_ALLOW_RENAME_PET: return { "SPELL_EFFECT_ALLOW_RENAME_PET", "SPELL_EFFECT_ALLOW_RENAME_PET", "" };
        case SPELL_EFFECT_FORCE_CAST_2: return { "SPELL_EFFECT_FORCE_CAST_2", "SPELL_EFFECT_FORCE_CAST_2", "" };
        case SPELL_EFFECT_TALENT_SPEC_COUNT: return { "SPELL_EFFECT_TALENT_SPEC_COUNT", "SPELL_EFFECT_TALENT_SPEC_COUNT", "" };
        case SPELL_EFFECT_TALENT_SPEC_SELECT: return { "SPELL_EFFECT_TALENT_SPEC_SELECT", "SPELL_EFFECT_TALENT_SPEC_SELECT", "" };
        case SPELL_EFFECT_163: return { "SPELL_EFFECT_163", "SPELL_EFFECT_163", "" };
        case SPELL_EFFECT_REMOVE_AURA: return { "SPELL_EFFECT_REMOVE_AURA", "SPELL_EFFECT_REMOVE_AURA", "" };
        case TOTAL_SPELL_EFFECTS: return { "TOTAL_SPELL_EFFECTS", "TOTAL_SPELL_EFFECTS", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<SpellEffects>::Count() { return 165; }

template <>
TC_API_EXPORT SpellEffects EnumUtils<SpellEffects>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return SPELL_EFFECT_INSTAKILL;
        case 1: return SPELL_EFFECT_SCHOOL_DAMAGE;
        case 2: return SPELL_EFFECT_DUMMY;
        case 3: return SPELL_EFFECT_PORTAL_TELEPORT;
        case 4: return SPELL_EFFECT_TELEPORT_UNITS;
        case 5: return SPELL_EFFECT_APPLY_AURA;
        case 6: return SPELL_EFFECT_ENVIRONMENTAL_DAMAGE;
        case 7: return SPELL_EFFECT_POWER_DRAIN;
        case 8: return SPELL_EFFECT_HEALTH_LEECH;
        case 9: return SPELL_EFFECT_HEAL;
        case 10: return SPELL_EFFECT_BIND;
        case 11: return SPELL_EFFECT_PORTAL;
        case 12: return SPELL_EFFECT_RITUAL_BASE;
        case 13: return SPELL_EFFECT_RITUAL_SPECIALIZE;
        case 14: return SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL;
        case 15: return SPELL_EFFECT_QUEST_COMPLETE;
        case 16: return SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL;
        case 17: return SPELL_EFFECT_RESURRECT;
        case 18: return SPELL_EFFECT_ADD_EXTRA_ATTACKS;
        case 19: return SPELL_EFFECT_DODGE;
        case 20: return SPELL_EFFECT_EVADE;
        case 21: return SPELL_EFFECT_PARRY;
        case 22: return SPELL_EFFECT_BLOCK;
        case 23: return SPELL_EFFECT_CREATE_ITEM;
        case 24: return SPELL_EFFECT_WEAPON;
        case 25: return SPELL_EFFECT_DEFENSE;
        case 26: return SPELL_EFFECT_PERSISTENT_AREA_AURA;
        case 27: return SPELL_EFFECT_SUMMON;
        case 28: return SPELL_EFFECT_LEAP;
        case 29: return SPELL_EFFECT_ENERGIZE;
        case 30: return SPELL_EFFECT_WEAPON_PERCENT_DAMAGE;
        case 31: return SPELL_EFFECT_TRIGGER_MISSILE;
        case 32: return SPELL_EFFECT_OPEN_LOCK;
        case 33: return SPELL_EFFECT_SUMMON_CHANGE_ITEM;
        case 34: return SPELL_EFFECT_APPLY_AREA_AURA_PARTY;
        case 35: return SPELL_EFFECT_LEARN_SPELL;
        case 36: return SPELL_EFFECT_SPELL_DEFENSE;
        case 37: return SPELL_EFFECT_DISPEL;
        case 38: return SPELL_EFFECT_LANGUAGE;
        case 39: return SPELL_EFFECT_DUAL_WIELD;
        case 40: return SPELL_EFFECT_JUMP;
        case 41: return SPELL_EFFECT_JUMP_DEST;
        case 42: return SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER;
        case 43: return SPELL_EFFECT_SKILL_STEP;
        case 44: return SPELL_EFFECT_ADD_HONOR;
        case 45: return SPELL_EFFECT_SPAWN;
        case 46: return SPELL_EFFECT_TRADE_SKILL;
        case 47: return SPELL_EFFECT_STEALTH;
        case 48: return SPELL_EFFECT_DETECT;
        case 49: return SPELL_EFFECT_TRANS_DOOR;
        case 50: return SPELL_EFFECT_FORCE_CRITICAL_HIT;
        case 51: return SPELL_EFFECT_GUARANTEE_HIT;
        case 52: return SPELL_EFFECT_ENCHANT_ITEM;
        case 53: return SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY;
        case 54: return SPELL_EFFECT_TAMECREATURE;
        case 55: return SPELL_EFFECT_SUMMON_PET;
        case 56: return SPELL_EFFECT_LEARN_PET_SPELL;
        case 57: return SPELL_EFFECT_WEAPON_DAMAGE;
        case 58: return SPELL_EFFECT_CREATE_RANDOM_ITEM;
        case 59: return SPELL_EFFECT_PROFICIENCY;
        case 60: return SPELL_EFFECT_SEND_EVENT;
        case 61: return SPELL_EFFECT_POWER_BURN;
        case 62: return SPELL_EFFECT_THREAT;
        case 63: return SPELL_EFFECT_TRIGGER_SPELL;
        case 64: return SPELL_EFFECT_APPLY_AREA_AURA_RAID;
        case 65: return SPELL_EFFECT_CREATE_MANA_GEM;
        case 66: return SPELL_EFFECT_HEAL_MAX_HEALTH;
        case 67: return SPELL_EFFECT_INTERRUPT_CAST;
        case 68: return SPELL_EFFECT_DISTRACT;
        case 69: return SPELL_EFFECT_PULL;
        case 70: return SPELL_EFFECT_PICKPOCKET;
        case 71: return SPELL_EFFECT_ADD_FARSIGHT;
        case 72: return SPELL_EFFECT_UNTRAIN_TALENTS;
        case 73: return SPELL_EFFECT_APPLY_GLYPH;
        case 74: return SPELL_EFFECT_HEAL_MECHANICAL;
        case 75: return SPELL_EFFECT_SUMMON_OBJECT_WILD;
        case 76: return SPELL_EFFECT_SCRIPT_EFFECT;
        case 77: return SPELL_EFFECT_ATTACK;
        case 78: return SPELL_EFFECT_SANCTUARY;
        case 79: return SPELL_EFFECT_ADD_COMBO_POINTS;
        case 80: return SPELL_EFFECT_CREATE_HOUSE;
        case 81: return SPELL_EFFECT_BIND_SIGHT;
        case 82: return SPELL_EFFECT_DUEL;
        case 83: return SPELL_EFFECT_STUCK;
        case 84: return SPELL_EFFECT_SUMMON_PLAYER;
        case 85: return SPELL_EFFECT_ACTIVATE_OBJECT;
        case 86: return SPELL_EFFECT_GAMEOBJECT_DAMAGE;
        case 87: return SPELL_EFFECT_GAMEOBJECT_REPAIR;
        case 88: return SPELL_EFFECT_GAMEOBJECT_SET_DESTRUCTION_STATE;
        case 89: return SPELL_EFFECT_KILL_CREDIT;
        case 90: return SPELL_EFFECT_THREAT_ALL;
        case 91: return SPELL_EFFECT_ENCHANT_HELD_ITEM;
        case 92: return SPELL_EFFECT_FORCE_DESELECT;
        case 93: return SPELL_EFFECT_SELF_RESURRECT;
        case 94: return SPELL_EFFECT_SKINNING;
        case 95: return SPELL_EFFECT_CHARGE;
        case 96: return SPELL_EFFECT_CAST_BUTTON;
        case 97: return SPELL_EFFECT_KNOCK_BACK;
        case 98: return SPELL_EFFECT_DISENCHANT;
        case 99: return SPELL_EFFECT_INEBRIATE;
        case 100: return SPELL_EFFECT_FEED_PET;
        case 101: return SPELL_EFFECT_DISMISS_PET;
        case 102: return SPELL_EFFECT_REPUTATION;
        case 103: return SPELL_EFFECT_SUMMON_OBJECT_SLOT1;
        case 104: return SPELL_EFFECT_SUMMON_OBJECT_SLOT2;
        case 105: return SPELL_EFFECT_SUMMON_OBJECT_SLOT3;
        case 106: return SPELL_EFFECT_SUMMON_OBJECT_SLOT4;
        case 107: return SPELL_EFFECT_DISPEL_MECHANIC;
        case 108: return SPELL_EFFECT_RESURRECT_PET;
        case 109: return SPELL_EFFECT_DESTROY_ALL_TOTEMS;
        case 110: return SPELL_EFFECT_DURABILITY_DAMAGE;
        case 111: return SPELL_EFFECT_112;
        case 112: return SPELL_EFFECT_RESURRECT_NEW;
        case 113: return SPELL_EFFECT_ATTACK_ME;
        case 114: return SPELL_EFFECT_DURABILITY_DAMAGE_PCT;
        case 115: return SPELL_EFFECT_SKIN_PLAYER_CORPSE;
        case 116: return SPELL_EFFECT_SPIRIT_HEAL;
        case 117: return SPELL_EFFECT_SKILL;
        case 118: return SPELL_EFFECT_APPLY_AREA_AURA_PET;
        case 119: return SPELL_EFFECT_TELEPORT_GRAVEYARD;
        case 120: return SPELL_EFFECT_NORMALIZED_WEAPON_DMG;
        case 121: return SPELL_EFFECT_122;
        case 122: return SPELL_EFFECT_SEND_TAXI;
        case 123: return SPELL_EFFECT_PULL_TOWARDS;
        case 124: return SPELL_EFFECT_MODIFY_THREAT_PERCENT;
        case 125: return SPELL_EFFECT_STEAL_BENEFICIAL_BUFF;
        case 126: return SPELL_EFFECT_PROSPECTING;
        case 127: return SPELL_EFFECT_APPLY_AREA_AURA_FRIEND;
        case 128: return SPELL_EFFECT_APPLY_AREA_AURA_ENEMY;
        case 129: return SPELL_EFFECT_REDIRECT_THREAT;
        case 130: return SPELL_EFFECT_PLAY_SOUND;
        case 131: return SPELL_EFFECT_PLAY_MUSIC;
        case 132: return SPELL_EFFECT_UNLEARN_SPECIALIZATION;
        case 133: return SPELL_EFFECT_KILL_CREDIT2;
        case 134: return SPELL_EFFECT_CALL_PET;
        case 135: return SPELL_EFFECT_HEAL_PCT;
        case 136: return SPELL_EFFECT_ENERGIZE_PCT;
        case 137: return SPELL_EFFECT_LEAP_BACK;
        case 138: return SPELL_EFFECT_CLEAR_QUEST;
        case 139: return SPELL_EFFECT_FORCE_CAST;
        case 140: return SPELL_EFFECT_FORCE_CAST_WITH_VALUE;
        case 141: return SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE;
        case 142: return SPELL_EFFECT_APPLY_AREA_AURA_OWNER;
        case 143: return SPELL_EFFECT_KNOCK_BACK_DEST;
        case 144: return SPELL_EFFECT_PULL_TOWARDS_DEST;
        case 145: return SPELL_EFFECT_ACTIVATE_RUNE;
        case 146: return SPELL_EFFECT_QUEST_FAIL;
        case 147: return SPELL_EFFECT_TRIGGER_MISSILE_SPELL_WITH_VALUE;
        case 148: return SPELL_EFFECT_CHARGE_DEST;
        case 149: return SPELL_EFFECT_QUEST_START;
        case 150: return SPELL_EFFECT_TRIGGER_SPELL_2;
        case 151: return SPELL_EFFECT_SUMMON_RAF_FRIEND;
        case 152: return SPELL_EFFECT_CREATE_TAMED_PET;
        case 153: return SPELL_EFFECT_DISCOVER_TAXI;
        case 154: return SPELL_EFFECT_TITAN_GRIP;
        case 155: return SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC;
        case 156: return SPELL_EFFECT_CREATE_ITEM_2;
        case 157: return SPELL_EFFECT_MILLING;
        case 158: return SPELL_EFFECT_ALLOW_RENAME_PET;
        case 159: return SPELL_EFFECT_FORCE_CAST_2;
        case 160: return SPELL_EFFECT_TALENT_SPEC_COUNT;
        case 161: return SPELL_EFFECT_TALENT_SPEC_SELECT;
        case 162: return SPELL_EFFECT_163;
        case 163: return SPELL_EFFECT_REMOVE_AURA;
        case 164: return TOTAL_SPELL_EFFECTS;
        default: throw std::out_of_range("index");
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
}
}
