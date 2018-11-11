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

/**************************************************************\
|* data for enum 'Powers' in 'SharedDefines.h' auto-generated *|
\**************************************************************/
template <>
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<Powers>::ToString(Powers value)
{
    switch (value)
    {
        case POWER_HEALTH: return {"POWER_HEALTH", "Health", ""};
        case POWER_MANA: return {"POWER_MANA", "Mana", ""};
        case POWER_RAGE: return {"POWER_RAGE", "Rage", ""};
        case POWER_FOCUS: return {"POWER_FOCUS", "Focus", ""};
        case POWER_ENERGY: return {"POWER_ENERGY", "Energy", ""};
        case POWER_HAPPINESS: return {"POWER_HAPPINESS", "Happiness", ""};
        case POWER_RUNE: return {"POWER_RUNE", "Runes", ""};
        case POWER_RUNIC_POWER: return {"POWER_RUNIC_POWER", "Runic Power", ""};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<Powers>::Count() { return 8; }
template <>
TC_API_EXPORT Powers Trinity::Impl::EnumUtils<Powers>::FromIndex(size_t index)
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
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<SpellSchools>::ToString(SpellSchools value)
{
    switch (value)
    {
        case SPELL_SCHOOL_NORMAL: return {"SPELL_SCHOOL_NORMAL", "Physical", ""};
        case SPELL_SCHOOL_HOLY: return {"SPELL_SCHOOL_HOLY", "Holy", ""};
        case SPELL_SCHOOL_FIRE: return {"SPELL_SCHOOL_FIRE", "Fire", ""};
        case SPELL_SCHOOL_NATURE: return {"SPELL_SCHOOL_NATURE", "Nature", ""};
        case SPELL_SCHOOL_FROST: return {"SPELL_SCHOOL_FROST", "Frost", ""};
        case SPELL_SCHOOL_SHADOW: return {"SPELL_SCHOOL_SHADOW", "Shadow", ""};
        case SPELL_SCHOOL_ARCANE: return {"SPELL_SCHOOL_ARCANE", "Arcane", ""};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<SpellSchools>::Count() { return 7; }
template <>
TC_API_EXPORT SpellSchools Trinity::Impl::EnumUtils<SpellSchools>::FromIndex(size_t index)
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
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<SpellAttr0>::ToString(SpellAttr0 value)
{
    switch (value)
    {
        case SPELL_ATTR0_UNK0: return {"SPELL_ATTR0_UNK0", "SPELL_ATTR0_UNK0", "0"};
        case SPELL_ATTR0_REQ_AMMO: return {"SPELL_ATTR0_REQ_AMMO", "SPELL_ATTR0_REQ_AMMO", "1 on next ranged"};
        case SPELL_ATTR0_ON_NEXT_SWING: return {"SPELL_ATTR0_ON_NEXT_SWING", "SPELL_ATTR0_ON_NEXT_SWING", "2"};
        case SPELL_ATTR0_IS_REPLENISHMENT: return {"SPELL_ATTR0_IS_REPLENISHMENT", "SPELL_ATTR0_IS_REPLENISHMENT", "3 not set in 3.0.3"};
        case SPELL_ATTR0_ABILITY: return {"SPELL_ATTR0_ABILITY", "SPELL_ATTR0_ABILITY", "4 client puts 'ability' instead of 'spell' in game strings for these spells"};
        case SPELL_ATTR0_TRADESPELL: return {"SPELL_ATTR0_TRADESPELL", "SPELL_ATTR0_TRADESPELL", "5 trade spells (recipes), will be added by client to a sublist of profession spell"};
        case SPELL_ATTR0_PASSIVE: return {"SPELL_ATTR0_PASSIVE", "SPELL_ATTR0_PASSIVE", "6 Passive spell"};
        case SPELL_ATTR0_HIDDEN_CLIENTSIDE: return {"SPELL_ATTR0_HIDDEN_CLIENTSIDE", "SPELL_ATTR0_HIDDEN_CLIENTSIDE", "7 Spells with this attribute are not visible in spellbook or aura bar"};
        case SPELL_ATTR0_HIDE_IN_COMBAT_LOG: return {"SPELL_ATTR0_HIDE_IN_COMBAT_LOG", "SPELL_ATTR0_HIDE_IN_COMBAT_LOG", "8 This attribite controls whether spell appears in combat logs"};
        case SPELL_ATTR0_TARGET_MAINHAND_ITEM: return {"SPELL_ATTR0_TARGET_MAINHAND_ITEM", "SPELL_ATTR0_TARGET_MAINHAND_ITEM", "9 Client automatically selects item from mainhand slot as a cast target"};
        case SPELL_ATTR0_ON_NEXT_SWING_2: return {"SPELL_ATTR0_ON_NEXT_SWING_2", "SPELL_ATTR0_ON_NEXT_SWING_2", "10"};
        case SPELL_ATTR0_UNK11: return {"SPELL_ATTR0_UNK11", "SPELL_ATTR0_UNK11", "11"};
        case SPELL_ATTR0_DAYTIME_ONLY: return {"SPELL_ATTR0_DAYTIME_ONLY", "SPELL_ATTR0_DAYTIME_ONLY", "12 only useable at daytime, not set in 2.4.2"};
        case SPELL_ATTR0_NIGHT_ONLY: return {"SPELL_ATTR0_NIGHT_ONLY", "SPELL_ATTR0_NIGHT_ONLY", "13 only useable at night, not set in 2.4.2"};
        case SPELL_ATTR0_INDOORS_ONLY: return {"SPELL_ATTR0_INDOORS_ONLY", "SPELL_ATTR0_INDOORS_ONLY", "14 only useable indoors, not set in 2.4.2"};
        case SPELL_ATTR0_OUTDOORS_ONLY: return {"SPELL_ATTR0_OUTDOORS_ONLY", "SPELL_ATTR0_OUTDOORS_ONLY", "15 Only useable outdoors."};
        case SPELL_ATTR0_NOT_SHAPESHIFT: return {"SPELL_ATTR0_NOT_SHAPESHIFT", "SPELL_ATTR0_NOT_SHAPESHIFT", "16 Not while shapeshifted"};
        case SPELL_ATTR0_ONLY_STEALTHED: return {"SPELL_ATTR0_ONLY_STEALTHED", "SPELL_ATTR0_ONLY_STEALTHED", "17 Must be in stealth"};
        case SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE: return {"SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE", "SPELL_ATTR0_DONT_AFFECT_SHEATH_STATE", "18 client won't hide unit weapons in sheath on cast/channel"};
        case SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION: return {"SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION", "SPELL_ATTR0_LEVEL_DAMAGE_CALCULATION", "19 spelldamage depends on caster level"};
        case SPELL_ATTR0_STOP_ATTACK_TARGET: return {"SPELL_ATTR0_STOP_ATTACK_TARGET", "SPELL_ATTR0_STOP_ATTACK_TARGET", "20 Stop attack after use this spell (and not begin attack if use)"};
        case SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK: return {"SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK", "SPELL_ATTR0_IMPOSSIBLE_DODGE_PARRY_BLOCK", "21 Cannot be dodged/parried/blocked"};
        case SPELL_ATTR0_CAST_TRACK_TARGET: return {"SPELL_ATTR0_CAST_TRACK_TARGET", "SPELL_ATTR0_CAST_TRACK_TARGET", "22 Client automatically forces player to face target when casting"};
        case SPELL_ATTR0_CASTABLE_WHILE_DEAD: return {"SPELL_ATTR0_CASTABLE_WHILE_DEAD", "SPELL_ATTR0_CASTABLE_WHILE_DEAD", "23 castable while dead?"};
        case SPELL_ATTR0_CASTABLE_WHILE_MOUNTED: return {"SPELL_ATTR0_CASTABLE_WHILE_MOUNTED", "SPELL_ATTR0_CASTABLE_WHILE_MOUNTED", "24 castable while mounted"};
        case SPELL_ATTR0_DISABLED_WHILE_ACTIVE: return {"SPELL_ATTR0_DISABLED_WHILE_ACTIVE", "SPELL_ATTR0_DISABLED_WHILE_ACTIVE", "25 Activate and start cooldown after aura fade or remove summoned creature or go"};
        case SPELL_ATTR0_NEGATIVE_1: return {"SPELL_ATTR0_NEGATIVE_1", "SPELL_ATTR0_NEGATIVE_1", "26 Many negative spells have this attr"};
        case SPELL_ATTR0_CASTABLE_WHILE_SITTING: return {"SPELL_ATTR0_CASTABLE_WHILE_SITTING", "SPELL_ATTR0_CASTABLE_WHILE_SITTING", "27 castable while sitting"};
        case SPELL_ATTR0_CANT_USED_IN_COMBAT: return {"SPELL_ATTR0_CANT_USED_IN_COMBAT", "SPELL_ATTR0_CANT_USED_IN_COMBAT", "28 Cannot be used in combat"};
        case SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY: return {"SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY", "SPELL_ATTR0_UNAFFECTED_BY_INVULNERABILITY", "29 unaffected by invulnerability (hmm possible not...)"};
        case SPELL_ATTR0_HEARTBEAT_RESIST_CHECK: return {"SPELL_ATTR0_HEARTBEAT_RESIST_CHECK", "SPELL_ATTR0_HEARTBEAT_RESIST_CHECK", "30 random chance the effect will end TODO: implement core support"};
        case SPELL_ATTR0_CANT_CANCEL: return {"SPELL_ATTR0_CANT_CANCEL", "SPELL_ATTR0_CANT_CANCEL", "31 positive aura can't be canceled"};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<SpellAttr0>::Count() { return 32; }
template <>
TC_API_EXPORT SpellAttr0 Trinity::Impl::EnumUtils<SpellAttr0>::FromIndex(size_t index)
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
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<SpellAttr1>::ToString(SpellAttr1 value)
{
    switch (value)
    {
        case SPELL_ATTR1_DISMISS_PET: return {"SPELL_ATTR1_DISMISS_PET", "SPELL_ATTR1_DISMISS_PET", "0 for spells without this flag client doesn't allow to summon pet if caster has a pet"};
        case SPELL_ATTR1_DRAIN_ALL_POWER: return {"SPELL_ATTR1_DRAIN_ALL_POWER", "SPELL_ATTR1_DRAIN_ALL_POWER", "1 use all power (Only paladin Lay of Hands and Bunyanize)"};
        case SPELL_ATTR1_CHANNELED_1: return {"SPELL_ATTR1_CHANNELED_1", "SPELL_ATTR1_CHANNELED_1", "2 clientside checked? cancelable?"};
        case SPELL_ATTR1_CANT_BE_REDIRECTED: return {"SPELL_ATTR1_CANT_BE_REDIRECTED", "SPELL_ATTR1_CANT_BE_REDIRECTED", "3"};
        case SPELL_ATTR1_UNK4: return {"SPELL_ATTR1_UNK4", "SPELL_ATTR1_UNK4", "4 stealth and whirlwind"};
        case SPELL_ATTR1_NOT_BREAK_STEALTH: return {"SPELL_ATTR1_NOT_BREAK_STEALTH", "SPELL_ATTR1_NOT_BREAK_STEALTH", "5 Not break stealth"};
        case SPELL_ATTR1_CHANNELED_2: return {"SPELL_ATTR1_CHANNELED_2", "SPELL_ATTR1_CHANNELED_2", "6"};
        case SPELL_ATTR1_CANT_BE_REFLECTED: return {"SPELL_ATTR1_CANT_BE_REFLECTED", "SPELL_ATTR1_CANT_BE_REFLECTED", "7"};
        case SPELL_ATTR1_CANT_TARGET_IN_COMBAT: return {"SPELL_ATTR1_CANT_TARGET_IN_COMBAT", "SPELL_ATTR1_CANT_TARGET_IN_COMBAT", "8 can target only out of combat units"};
        case SPELL_ATTR1_MELEE_COMBAT_START: return {"SPELL_ATTR1_MELEE_COMBAT_START", "SPELL_ATTR1_MELEE_COMBAT_START", "9 player starts melee combat after this spell is cast"};
        case SPELL_ATTR1_NO_THREAT: return {"SPELL_ATTR1_NO_THREAT", "SPELL_ATTR1_NO_THREAT", "10 no generates threat on cast 100% (old NO_INITIAL_AGGRO)"};
        case SPELL_ATTR1_UNK11: return {"SPELL_ATTR1_UNK11", "SPELL_ATTR1_UNK11", "11 aura"};
        case SPELL_ATTR1_IS_PICKPOCKET: return {"SPELL_ATTR1_IS_PICKPOCKET", "SPELL_ATTR1_IS_PICKPOCKET", "12 Pickpocket"};
        case SPELL_ATTR1_FARSIGHT: return {"SPELL_ATTR1_FARSIGHT", "SPELL_ATTR1_FARSIGHT", "13 Client removes farsight on aura loss"};
        case SPELL_ATTR1_CHANNEL_TRACK_TARGET: return {"SPELL_ATTR1_CHANNEL_TRACK_TARGET", "SPELL_ATTR1_CHANNEL_TRACK_TARGET", "14 Client automatically forces player to face target when channeling"};
        case SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY: return {"SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY", "SPELL_ATTR1_DISPEL_AURAS_ON_IMMUNITY", "15 remove auras on immunity"};
        case SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE: return {"SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE", "SPELL_ATTR1_UNAFFECTED_BY_SCHOOL_IMMUNE", "16 on immuniy"};
        case SPELL_ATTR1_UNAUTOCASTABLE_BY_PET: return {"SPELL_ATTR1_UNAUTOCASTABLE_BY_PET", "SPELL_ATTR1_UNAUTOCASTABLE_BY_PET", "17"};
        case SPELL_ATTR1_UNK18: return {"SPELL_ATTR1_UNK18", "SPELL_ATTR1_UNK18", "18 stun, polymorph, daze, hex"};
        case SPELL_ATTR1_CANT_TARGET_SELF: return {"SPELL_ATTR1_CANT_TARGET_SELF", "SPELL_ATTR1_CANT_TARGET_SELF", "19"};
        case SPELL_ATTR1_REQ_COMBO_POINTS1: return {"SPELL_ATTR1_REQ_COMBO_POINTS1", "SPELL_ATTR1_REQ_COMBO_POINTS1", "20 Req combo points on target"};
        case SPELL_ATTR1_UNK21: return {"SPELL_ATTR1_UNK21", "SPELL_ATTR1_UNK21", "21"};
        case SPELL_ATTR1_REQ_COMBO_POINTS2: return {"SPELL_ATTR1_REQ_COMBO_POINTS2", "SPELL_ATTR1_REQ_COMBO_POINTS2", "22 Req combo points on target"};
        case SPELL_ATTR1_UNK23: return {"SPELL_ATTR1_UNK23", "SPELL_ATTR1_UNK23", "23"};
        case SPELL_ATTR1_IS_FISHING: return {"SPELL_ATTR1_IS_FISHING", "SPELL_ATTR1_IS_FISHING", "24 only fishing spells"};
        case SPELL_ATTR1_UNK25: return {"SPELL_ATTR1_UNK25", "SPELL_ATTR1_UNK25", "25"};
        case SPELL_ATTR1_UNK26: return {"SPELL_ATTR1_UNK26", "SPELL_ATTR1_UNK26", "26 works correctly with [target=focus] and [target=mouseover] macros?"};
        case SPELL_ATTR1_UNK27: return {"SPELL_ATTR1_UNK27", "SPELL_ATTR1_UNK27", "27 melee spell?"};
        case SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR: return {"SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR", "SPELL_ATTR1_DONT_DISPLAY_IN_AURA_BAR", "28 client doesn't display these spells in aura bar"};
        case SPELL_ATTR1_CHANNEL_DISPLAY_SPELL_NAME: return {"SPELL_ATTR1_CHANNEL_DISPLAY_SPELL_NAME", "SPELL_ATTR1_CHANNEL_DISPLAY_SPELL_NAME", "29 spell name is displayed in cast bar instead of 'channeling' text"};
        case SPELL_ATTR1_ENABLE_AT_DODGE: return {"SPELL_ATTR1_ENABLE_AT_DODGE", "SPELL_ATTR1_ENABLE_AT_DODGE", "30 Overpower"};
        case SPELL_ATTR1_UNK31: return {"SPELL_ATTR1_UNK31", "SPELL_ATTR1_UNK31", "31"};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<SpellAttr1>::Count() { return 32; }
template <>
TC_API_EXPORT SpellAttr1 Trinity::Impl::EnumUtils<SpellAttr1>::FromIndex(size_t index)
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
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<SpellAttr2>::ToString(SpellAttr2 value)
{
    switch (value)
    {
        case SPELL_ATTR2_CAN_TARGET_DEAD: return {"SPELL_ATTR2_CAN_TARGET_DEAD", "SPELL_ATTR2_CAN_TARGET_DEAD", "0 can target dead unit or corpse"};
        case SPELL_ATTR2_UNK1: return {"SPELL_ATTR2_UNK1", "SPELL_ATTR2_UNK1", "1 vanish, shadowform, Ghost Wolf and other"};
        case SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS: return {"SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS", "SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS", "2 26368 4.0.1 dbc change"};
        case SPELL_ATTR2_UNK3: return {"SPELL_ATTR2_UNK3", "SPELL_ATTR2_UNK3", "3"};
        case SPELL_ATTR2_DISPLAY_IN_STANCE_BAR: return {"SPELL_ATTR2_DISPLAY_IN_STANCE_BAR", "SPELL_ATTR2_DISPLAY_IN_STANCE_BAR", "4 client displays icon in stance bar when learned, even if not shapeshift"};
        case SPELL_ATTR2_AUTOREPEAT_FLAG: return {"SPELL_ATTR2_AUTOREPEAT_FLAG", "SPELL_ATTR2_AUTOREPEAT_FLAG", "5"};
        case SPELL_ATTR2_CANT_TARGET_TAPPED: return {"SPELL_ATTR2_CANT_TARGET_TAPPED", "SPELL_ATTR2_CANT_TARGET_TAPPED", "6 target must be tapped by caster"};
        case SPELL_ATTR2_UNK7: return {"SPELL_ATTR2_UNK7", "SPELL_ATTR2_UNK7", "7"};
        case SPELL_ATTR2_UNK8: return {"SPELL_ATTR2_UNK8", "SPELL_ATTR2_UNK8", "8 not set in 3.0.3"};
        case SPELL_ATTR2_UNK9: return {"SPELL_ATTR2_UNK9", "SPELL_ATTR2_UNK9", "9"};
        case SPELL_ATTR2_UNK10: return {"SPELL_ATTR2_UNK10", "SPELL_ATTR2_UNK10", "10 related to tame"};
        case SPELL_ATTR2_HEALTH_FUNNEL: return {"SPELL_ATTR2_HEALTH_FUNNEL", "SPELL_ATTR2_HEALTH_FUNNEL", "11"};
        case SPELL_ATTR2_UNK12: return {"SPELL_ATTR2_UNK12", "SPELL_ATTR2_UNK12", "12 Cleave, Heart Strike, Maul, Sunder Armor, Swipe"};
        case SPELL_ATTR2_PRESERVE_ENCHANT_IN_ARENA: return {"SPELL_ATTR2_PRESERVE_ENCHANT_IN_ARENA", "SPELL_ATTR2_PRESERVE_ENCHANT_IN_ARENA", "13 Items enchanted by spells with this flag preserve the enchant to arenas"};
        case SPELL_ATTR2_UNK14: return {"SPELL_ATTR2_UNK14", "SPELL_ATTR2_UNK14", "14"};
        case SPELL_ATTR2_UNK15: return {"SPELL_ATTR2_UNK15", "SPELL_ATTR2_UNK15", "15 not set in 3.0.3"};
        case SPELL_ATTR2_TAME_BEAST: return {"SPELL_ATTR2_TAME_BEAST", "SPELL_ATTR2_TAME_BEAST", "16"};
        case SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS: return {"SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS", "SPELL_ATTR2_NOT_RESET_AUTO_ACTIONS", "17 don't reset timers for melee autoattacks (swings) or ranged autoattacks (autoshoots)"};
        case SPELL_ATTR2_REQ_DEAD_PET: return {"SPELL_ATTR2_REQ_DEAD_PET", "SPELL_ATTR2_REQ_DEAD_PET", "18 Only Revive pet and Heart of the Pheonix"};
        case SPELL_ATTR2_NOT_NEED_SHAPESHIFT: return {"SPELL_ATTR2_NOT_NEED_SHAPESHIFT", "SPELL_ATTR2_NOT_NEED_SHAPESHIFT", "19 does not necessarly need shapeshift"};
        case SPELL_ATTR2_UNK20: return {"SPELL_ATTR2_UNK20", "SPELL_ATTR2_UNK20", "20"};
        case SPELL_ATTR2_DAMAGE_REDUCED_SHIELD: return {"SPELL_ATTR2_DAMAGE_REDUCED_SHIELD", "SPELL_ATTR2_DAMAGE_REDUCED_SHIELD", "21 for ice blocks, pala immunity buffs, priest absorb shields, but used also for other spells -> not sure!"};
        case SPELL_ATTR2_UNK22: return {"SPELL_ATTR2_UNK22", "SPELL_ATTR2_UNK22", "22 Ambush, Backstab, Cheap Shot, Death Grip, Garrote, Judgements, Mutilate, Pounce, Ravage, Shiv, Shred"};
        case SPELL_ATTR2_IS_ARCANE_CONCENTRATION: return {"SPELL_ATTR2_IS_ARCANE_CONCENTRATION", "SPELL_ATTR2_IS_ARCANE_CONCENTRATION", "23 Only mage Arcane Concentration have this flag"};
        case SPELL_ATTR2_UNK24: return {"SPELL_ATTR2_UNK24", "SPELL_ATTR2_UNK24", "24"};
        case SPELL_ATTR2_UNK25: return {"SPELL_ATTR2_UNK25", "SPELL_ATTR2_UNK25", "25"};
        case SPELL_ATTR2_UNAFFECTED_BY_AURA_SCHOOL_IMMUNE: return {"SPELL_ATTR2_UNAFFECTED_BY_AURA_SCHOOL_IMMUNE", "SPELL_ATTR2_UNAFFECTED_BY_AURA_SCHOOL_IMMUNE", "26 unaffected by school immunity"};
        case SPELL_ATTR2_UNK27: return {"SPELL_ATTR2_UNK27", "SPELL_ATTR2_UNK27", "27"};
        case SPELL_ATTR2_UNK28: return {"SPELL_ATTR2_UNK28", "SPELL_ATTR2_UNK28", "28"};
        case SPELL_ATTR2_CANT_CRIT: return {"SPELL_ATTR2_CANT_CRIT", "SPELL_ATTR2_CANT_CRIT", "29 Spell can't crit"};
        case SPELL_ATTR2_TRIGGERED_CAN_TRIGGER_PROC: return {"SPELL_ATTR2_TRIGGERED_CAN_TRIGGER_PROC", "SPELL_ATTR2_TRIGGERED_CAN_TRIGGER_PROC", "30 spell can trigger even if triggered"};
        case SPELL_ATTR2_FOOD_BUFF: return {"SPELL_ATTR2_FOOD_BUFF", "SPELL_ATTR2_FOOD_BUFF", "31 Food or Drink Buff (like Well Fed)"};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<SpellAttr2>::Count() { return 32; }
template <>
TC_API_EXPORT SpellAttr2 Trinity::Impl::EnumUtils<SpellAttr2>::FromIndex(size_t index)
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
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<SpellAttr3>::ToString(SpellAttr3 value)
{
    switch (value)
    {
        case SPELL_ATTR3_UNK0: return {"SPELL_ATTR3_UNK0", "SPELL_ATTR3_UNK0", "0"};
        case SPELL_ATTR3_IGNORE_PROC_SUBCLASS_MASK: return {"SPELL_ATTR3_IGNORE_PROC_SUBCLASS_MASK", "SPELL_ATTR3_IGNORE_PROC_SUBCLASS_MASK", "1 Ignores subclass mask check when checking proc"};
        case SPELL_ATTR3_UNK2: return {"SPELL_ATTR3_UNK2", "SPELL_ATTR3_UNK2", "2"};
        case SPELL_ATTR3_BLOCKABLE_SPELL: return {"SPELL_ATTR3_BLOCKABLE_SPELL", "SPELL_ATTR3_BLOCKABLE_SPELL", "3 Only dmg class melee in 3.1.3"};
        case SPELL_ATTR3_IGNORE_RESURRECTION_TIMER: return {"SPELL_ATTR3_IGNORE_RESURRECTION_TIMER", "SPELL_ATTR3_IGNORE_RESURRECTION_TIMER", "4 you don't have to wait to be resurrected with these spells"};
        case SPELL_ATTR3_UNK5: return {"SPELL_ATTR3_UNK5", "SPELL_ATTR3_UNK5", "5"};
        case SPELL_ATTR3_UNK6: return {"SPELL_ATTR3_UNK6", "SPELL_ATTR3_UNK6", "6"};
        case SPELL_ATTR3_STACK_FOR_DIFF_CASTERS: return {"SPELL_ATTR3_STACK_FOR_DIFF_CASTERS", "SPELL_ATTR3_STACK_FOR_DIFF_CASTERS", "7 separate stack for every caster"};
        case SPELL_ATTR3_ONLY_TARGET_PLAYERS: return {"SPELL_ATTR3_ONLY_TARGET_PLAYERS", "SPELL_ATTR3_ONLY_TARGET_PLAYERS", "8 can only target players"};
        case SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2: return {"SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2", "SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2", "9 triggered from effect?"};
        case SPELL_ATTR3_MAIN_HAND: return {"SPELL_ATTR3_MAIN_HAND", "SPELL_ATTR3_MAIN_HAND", "10 Main hand weapon required"};
        case SPELL_ATTR3_BATTLEGROUND: return {"SPELL_ATTR3_BATTLEGROUND", "SPELL_ATTR3_BATTLEGROUND", "11 Can only be cast in battleground"};
        case SPELL_ATTR3_ONLY_TARGET_GHOSTS: return {"SPELL_ATTR3_ONLY_TARGET_GHOSTS", "SPELL_ATTR3_ONLY_TARGET_GHOSTS", "12"};
        case SPELL_ATTR3_DONT_DISPLAY_CHANNEL_BAR: return {"SPELL_ATTR3_DONT_DISPLAY_CHANNEL_BAR", "SPELL_ATTR3_DONT_DISPLAY_CHANNEL_BAR", "13 Clientside attribute - will not display channeling bar"};
        case SPELL_ATTR3_IS_HONORLESS_TARGET: return {"SPELL_ATTR3_IS_HONORLESS_TARGET", "SPELL_ATTR3_IS_HONORLESS_TARGET", "14 \042Honorless Target\042 only this spells have this flag"};
        case SPELL_ATTR3_UNK15: return {"SPELL_ATTR3_UNK15", "SPELL_ATTR3_UNK15", "15 Auto Shoot, Shoot, Throw,  - this is autoshot flag"};
        case SPELL_ATTR3_CANT_TRIGGER_PROC: return {"SPELL_ATTR3_CANT_TRIGGER_PROC", "SPELL_ATTR3_CANT_TRIGGER_PROC", "16 confirmed with many patchnotes"};
        case SPELL_ATTR3_NO_INITIAL_AGGRO: return {"SPELL_ATTR3_NO_INITIAL_AGGRO", "SPELL_ATTR3_NO_INITIAL_AGGRO", "17 Soothe Animal, 39758, Mind Soothe"};
        case SPELL_ATTR3_IGNORE_HIT_RESULT: return {"SPELL_ATTR3_IGNORE_HIT_RESULT", "SPELL_ATTR3_IGNORE_HIT_RESULT", "18 Spell should always hit its target"};
        case SPELL_ATTR3_DISABLE_PROC: return {"SPELL_ATTR3_DISABLE_PROC", "SPELL_ATTR3_DISABLE_PROC", "19 during aura proc no spells can trigger (20178, 20375)"};
        case SPELL_ATTR3_DEATH_PERSISTENT: return {"SPELL_ATTR3_DEATH_PERSISTENT", "SPELL_ATTR3_DEATH_PERSISTENT", "20 Death persistent spells"};
        case SPELL_ATTR3_UNK21: return {"SPELL_ATTR3_UNK21", "SPELL_ATTR3_UNK21", "21 unused"};
        case SPELL_ATTR3_REQ_WAND: return {"SPELL_ATTR3_REQ_WAND", "SPELL_ATTR3_REQ_WAND", "22 Req wand"};
        case SPELL_ATTR3_UNK23: return {"SPELL_ATTR3_UNK23", "SPELL_ATTR3_UNK23", "23"};
        case SPELL_ATTR3_REQ_OFFHAND: return {"SPELL_ATTR3_REQ_OFFHAND", "SPELL_ATTR3_REQ_OFFHAND", "24 Req offhand weapon"};
        case SPELL_ATTR3_TREAT_AS_PERIODIC: return {"SPELL_ATTR3_TREAT_AS_PERIODIC", "SPELL_ATTR3_TREAT_AS_PERIODIC", "25 Makes the spell appear as periodic in client combat logs - used by spells that trigger another spell on each tick"};
        case SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED: return {"SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED", "SPELL_ATTR3_CAN_PROC_WITH_TRIGGERED", "26 auras with this attribute can proc from triggered spell casts with SPELL_ATTR3_TRIGGERED_CAN_TRIGGER_PROC_2 (67736 + 52999)"};
        case SPELL_ATTR3_DRAIN_SOUL: return {"SPELL_ATTR3_DRAIN_SOUL", "SPELL_ATTR3_DRAIN_SOUL", "27 only drain soul has this flag"};
        case SPELL_ATTR3_UNK28: return {"SPELL_ATTR3_UNK28", "SPELL_ATTR3_UNK28", "28"};
        case SPELL_ATTR3_NO_DONE_BONUS: return {"SPELL_ATTR3_NO_DONE_BONUS", "SPELL_ATTR3_NO_DONE_BONUS", "29 Ignore caster spellpower and done damage mods?  client doesn't apply spellmods for those spells"};
        case SPELL_ATTR3_DONT_DISPLAY_RANGE: return {"SPELL_ATTR3_DONT_DISPLAY_RANGE", "SPELL_ATTR3_DONT_DISPLAY_RANGE", "30 client doesn't display range in tooltip for those spells"};
        case SPELL_ATTR3_UNK31: return {"SPELL_ATTR3_UNK31", "SPELL_ATTR3_UNK31", "31"};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<SpellAttr3>::Count() { return 32; }
template <>
TC_API_EXPORT SpellAttr3 Trinity::Impl::EnumUtils<SpellAttr3>::FromIndex(size_t index)
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
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<SpellAttr4>::ToString(SpellAttr4 value)
{
    switch (value)
    {
        case SPELL_ATTR4_IGNORE_RESISTANCES: return {"SPELL_ATTR4_IGNORE_RESISTANCES", "SPELL_ATTR4_IGNORE_RESISTANCES", "0 spells with this attribute will completely ignore the target's resistance (these spells can't be resisted)"};
        case SPELL_ATTR4_PROC_ONLY_ON_CASTER: return {"SPELL_ATTR4_PROC_ONLY_ON_CASTER", "SPELL_ATTR4_PROC_ONLY_ON_CASTER", "1 proc only on effects with TARGET_UNIT_CASTER?"};
        case SPELL_ATTR4_FADES_WHILE_LOGGED_OUT: return {"SPELL_ATTR4_FADES_WHILE_LOGGED_OUT", "SPELL_ATTR4_FADES_WHILE_LOGGED_OUT", "2 duration is removed from aura while player is logged out"};
        case SPELL_ATTR4_UNK3: return {"SPELL_ATTR4_UNK3", "SPELL_ATTR4_UNK3", "3"};
        case SPELL_ATTR4_UNK4: return {"SPELL_ATTR4_UNK4", "SPELL_ATTR4_UNK4", "4 This will no longer cause guards to attack on use??"};
        case SPELL_ATTR4_UNK5: return {"SPELL_ATTR4_UNK5", "SPELL_ATTR4_UNK5", "5"};
        case SPELL_ATTR4_NOT_STEALABLE: return {"SPELL_ATTR4_NOT_STEALABLE", "SPELL_ATTR4_NOT_STEALABLE", "6 although such auras might be dispellable, they cannot be stolen"};
        case SPELL_ATTR4_CAN_CAST_WHILE_CASTING: return {"SPELL_ATTR4_CAN_CAST_WHILE_CASTING", "SPELL_ATTR4_CAN_CAST_WHILE_CASTING", "7 Can be cast while another cast is in progress - see CanCastWhileCasting(SpellRec const*,CGUnit_C *,int &)"};
        case SPELL_ATTR4_FIXED_DAMAGE: return {"SPELL_ATTR4_FIXED_DAMAGE", "SPELL_ATTR4_FIXED_DAMAGE", "8 Ignores resilience and any (except mechanic related) damage or % damage taken auras on target."};
        case SPELL_ATTR4_TRIGGER_ACTIVATE: return {"SPELL_ATTR4_TRIGGER_ACTIVATE", "SPELL_ATTR4_TRIGGER_ACTIVATE", "9 initially disabled / trigger activate from event (Execute, Riposte, Deep Freeze end other)"};
        case SPELL_ATTR4_SPELL_VS_EXTEND_COST: return {"SPELL_ATTR4_SPELL_VS_EXTEND_COST", "SPELL_ATTR4_SPELL_VS_EXTEND_COST", "10 Rogue Shiv have this flag"};
        case SPELL_ATTR4_UNK11: return {"SPELL_ATTR4_UNK11", "SPELL_ATTR4_UNK11", "11"};
        case SPELL_ATTR4_UNK12: return {"SPELL_ATTR4_UNK12", "SPELL_ATTR4_UNK12", "12"};
        case SPELL_ATTR4_UNK13: return {"SPELL_ATTR4_UNK13", "SPELL_ATTR4_UNK13", "13"};
        case SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS: return {"SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS", "SPELL_ATTR4_DAMAGE_DOESNT_BREAK_AURAS", "14 doesn't break auras by damage from these spells"};
        case SPELL_ATTR4_UNK15: return {"SPELL_ATTR4_UNK15", "SPELL_ATTR4_UNK15", "15"};
        case SPELL_ATTR4_NOT_USABLE_IN_ARENA: return {"SPELL_ATTR4_NOT_USABLE_IN_ARENA", "SPELL_ATTR4_NOT_USABLE_IN_ARENA", "16"};
        case SPELL_ATTR4_USABLE_IN_ARENA: return {"SPELL_ATTR4_USABLE_IN_ARENA", "SPELL_ATTR4_USABLE_IN_ARENA", "17"};
        case SPELL_ATTR4_AREA_TARGET_CHAIN: return {"SPELL_ATTR4_AREA_TARGET_CHAIN", "SPELL_ATTR4_AREA_TARGET_CHAIN", "18 (NYI)hits area targets one after another instead of all at once"};
        case SPELL_ATTR4_UNK19: return {"SPELL_ATTR4_UNK19", "SPELL_ATTR4_UNK19", "19 proc dalayed, after damage or don't proc on absorb?"};
        case SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER: return {"SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER", "SPELL_ATTR4_NOT_CHECK_SELFCAST_POWER", "20 supersedes message \042More powerful spell applied\042 for self casts."};
        case SPELL_ATTR4_UNK21: return {"SPELL_ATTR4_UNK21", "SPELL_ATTR4_UNK21", "21 Pally aura, dk presence, dudu form, warrior stance, shadowform, hunter track"};
        case SPELL_ATTR4_UNK22: return {"SPELL_ATTR4_UNK22", "SPELL_ATTR4_UNK22", "22 Seal of Command (42058, 57770) and Gymer's Smash 55426"};
        case SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS: return {"SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS", "SPELL_ATTR4_CANT_TRIGGER_ITEM_SPELLS", "23 spells with this flag should not trigger item spells / enchants (mostly in conjunction with SPELL_ATTR0_STOP_ATTACK_TARGET)"};
        case SPELL_ATTR4_UNK24: return {"SPELL_ATTR4_UNK24", "SPELL_ATTR4_UNK24", "24 some shoot spell"};
        case SPELL_ATTR4_IS_PET_SCALING: return {"SPELL_ATTR4_IS_PET_SCALING", "SPELL_ATTR4_IS_PET_SCALING", "25 pet scaling auras"};
        case SPELL_ATTR4_CAST_ONLY_IN_OUTLAND: return {"SPELL_ATTR4_CAST_ONLY_IN_OUTLAND", "SPELL_ATTR4_CAST_ONLY_IN_OUTLAND", "26 Can only be used in Outland."};
        case SPELL_ATTR4_INHERIT_CRIT_FROM_AURA: return {"SPELL_ATTR4_INHERIT_CRIT_FROM_AURA", "SPELL_ATTR4_INHERIT_CRIT_FROM_AURA", "27 Volley, Arcane Missiles, Penance -> related to critical on channeled periodical damage spell"};
        case SPELL_ATTR4_UNK28: return {"SPELL_ATTR4_UNK28", "SPELL_ATTR4_UNK28", "28 Aimed Shot"};
        case SPELL_ATTR4_UNK29: return {"SPELL_ATTR4_UNK29", "SPELL_ATTR4_UNK29", "29"};
        case SPELL_ATTR4_UNK30: return {"SPELL_ATTR4_UNK30", "SPELL_ATTR4_UNK30", "30"};
        case SPELL_ATTR4_UNK31: return {"SPELL_ATTR4_UNK31", "SPELL_ATTR4_UNK31", "31 Polymorph (chicken) 228 and Sonic Boom (38052, 38488)"};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<SpellAttr4>::Count() { return 32; }
template <>
TC_API_EXPORT SpellAttr4 Trinity::Impl::EnumUtils<SpellAttr4>::FromIndex(size_t index)
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
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<SpellAttr5>::ToString(SpellAttr5 value)
{
    switch (value)
    {
        case SPELL_ATTR5_CAN_CHANNEL_WHEN_MOVING: return {"SPELL_ATTR5_CAN_CHANNEL_WHEN_MOVING", "SPELL_ATTR5_CAN_CHANNEL_WHEN_MOVING", "0 available casting channel spell when moving"};
        case SPELL_ATTR5_NO_REAGENT_WHILE_PREP: return {"SPELL_ATTR5_NO_REAGENT_WHILE_PREP", "SPELL_ATTR5_NO_REAGENT_WHILE_PREP", "1 not need reagents if UNIT_FLAG_PREPARATION"};
        case SPELL_ATTR5_REMOVE_ON_ARENA_ENTER: return {"SPELL_ATTR5_REMOVE_ON_ARENA_ENTER", "SPELL_ATTR5_REMOVE_ON_ARENA_ENTER", "2 remove this aura on arena enter"};
        case SPELL_ATTR5_USABLE_WHILE_STUNNED: return {"SPELL_ATTR5_USABLE_WHILE_STUNNED", "SPELL_ATTR5_USABLE_WHILE_STUNNED", "3 usable while stunned"};
        case SPELL_ATTR5_UNK4: return {"SPELL_ATTR5_UNK4", "SPELL_ATTR5_UNK4", "4"};
        case SPELL_ATTR5_SINGLE_TARGET_SPELL: return {"SPELL_ATTR5_SINGLE_TARGET_SPELL", "SPELL_ATTR5_SINGLE_TARGET_SPELL", "5 Only one target can be apply at a time"};
        case SPELL_ATTR5_UNK6: return {"SPELL_ATTR5_UNK6", "SPELL_ATTR5_UNK6", "6"};
        case SPELL_ATTR5_UNK7: return {"SPELL_ATTR5_UNK7", "SPELL_ATTR5_UNK7", "7"};
        case SPELL_ATTR5_UNK8: return {"SPELL_ATTR5_UNK8", "SPELL_ATTR5_UNK8", "8"};
        case SPELL_ATTR5_START_PERIODIC_AT_APPLY: return {"SPELL_ATTR5_START_PERIODIC_AT_APPLY", "SPELL_ATTR5_START_PERIODIC_AT_APPLY", "9 begin periodic tick at aura apply"};
        case SPELL_ATTR5_HIDE_DURATION: return {"SPELL_ATTR5_HIDE_DURATION", "SPELL_ATTR5_HIDE_DURATION", "10 do not send duration to client"};
        case SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET: return {"SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET", "SPELL_ATTR5_ALLOW_TARGET_OF_TARGET_AS_TARGET", "11 (NYI) uses target's target as target if original target not valid (intervene for example)"};
        case SPELL_ATTR5_UNK12: return {"SPELL_ATTR5_UNK12", "SPELL_ATTR5_UNK12", "12 Cleave related?"};
        case SPELL_ATTR5_HASTE_AFFECT_DURATION: return {"SPELL_ATTR5_HASTE_AFFECT_DURATION", "SPELL_ATTR5_HASTE_AFFECT_DURATION", "13 haste effects decrease duration of this"};
        case SPELL_ATTR5_UNK14: return {"SPELL_ATTR5_UNK14", "SPELL_ATTR5_UNK14", "14"};
        case SPELL_ATTR5_UNK15: return {"SPELL_ATTR5_UNK15", "SPELL_ATTR5_UNK15", "15 Inflits on multiple targets?"};
        case SPELL_ATTR5_UNK16: return {"SPELL_ATTR5_UNK16", "SPELL_ATTR5_UNK16", "16"};
        case SPELL_ATTR5_USABLE_WHILE_FEARED: return {"SPELL_ATTR5_USABLE_WHILE_FEARED", "SPELL_ATTR5_USABLE_WHILE_FEARED", "17 usable while feared"};
        case SPELL_ATTR5_USABLE_WHILE_CONFUSED: return {"SPELL_ATTR5_USABLE_WHILE_CONFUSED", "SPELL_ATTR5_USABLE_WHILE_CONFUSED", "18 usable while confused"};
        case SPELL_ATTR5_DONT_TURN_DURING_CAST: return {"SPELL_ATTR5_DONT_TURN_DURING_CAST", "SPELL_ATTR5_DONT_TURN_DURING_CAST", "19 Blocks caster's turning when casting (client does not automatically turn caster's model to face UNIT_FIELD_TARGET)"};
        case SPELL_ATTR5_UNK20: return {"SPELL_ATTR5_UNK20", "SPELL_ATTR5_UNK20", "20"};
        case SPELL_ATTR5_UNK21: return {"SPELL_ATTR5_UNK21", "SPELL_ATTR5_UNK21", "21"};
        case SPELL_ATTR5_UNK22: return {"SPELL_ATTR5_UNK22", "SPELL_ATTR5_UNK22", "22"};
        case SPELL_ATTR5_UNK23: return {"SPELL_ATTR5_UNK23", "SPELL_ATTR5_UNK23", "23"};
        case SPELL_ATTR5_UNK24: return {"SPELL_ATTR5_UNK24", "SPELL_ATTR5_UNK24", "24"};
        case SPELL_ATTR5_UNK25: return {"SPELL_ATTR5_UNK25", "SPELL_ATTR5_UNK25", "25"};
        case SPELL_ATTR5_SKIP_CHECKCAST_LOS_CHECK: return {"SPELL_ATTR5_SKIP_CHECKCAST_LOS_CHECK", "SPELL_ATTR5_SKIP_CHECKCAST_LOS_CHECK", "26 aoe related - Boulder, Cannon, Corpse Explosion, Fire Nova, Flames, Frost Bomb, Living Bomb, Seed of Corruption, Starfall, Thunder Clap, Volley"};
        case SPELL_ATTR5_DONT_SHOW_AURA_IF_SELF_CAST: return {"SPELL_ATTR5_DONT_SHOW_AURA_IF_SELF_CAST", "SPELL_ATTR5_DONT_SHOW_AURA_IF_SELF_CAST", "27 Auras with this attribute are not visible on units that are the caster"};
        case SPELL_ATTR5_DONT_SHOW_AURA_IF_NOT_SELF_CAST: return {"SPELL_ATTR5_DONT_SHOW_AURA_IF_NOT_SELF_CAST", "SPELL_ATTR5_DONT_SHOW_AURA_IF_NOT_SELF_CAST", "28 Auras with this attribute are not visible on units that are not the caster"};
        case SPELL_ATTR5_UNK29: return {"SPELL_ATTR5_UNK29", "SPELL_ATTR5_UNK29", "29"};
        case SPELL_ATTR5_UNK30: return {"SPELL_ATTR5_UNK30", "SPELL_ATTR5_UNK30", "30"};
        case SPELL_ATTR5_UNK31: return {"SPELL_ATTR5_UNK31", "SPELL_ATTR5_UNK31", "31 Forces all nearby enemies to focus attacks caster"};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<SpellAttr5>::Count() { return 32; }
template <>
TC_API_EXPORT SpellAttr5 Trinity::Impl::EnumUtils<SpellAttr5>::FromIndex(size_t index)
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
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<SpellAttr6>::ToString(SpellAttr6 value)
{
    switch (value)
    {
        case SPELL_ATTR6_DONT_DISPLAY_COOLDOWN: return {"SPELL_ATTR6_DONT_DISPLAY_COOLDOWN", "SPELL_ATTR6_DONT_DISPLAY_COOLDOWN", "0 client doesn't display cooldown in tooltip for these spells"};
        case SPELL_ATTR6_ONLY_IN_ARENA: return {"SPELL_ATTR6_ONLY_IN_ARENA", "SPELL_ATTR6_ONLY_IN_ARENA", "1 only usable in arena"};
        case SPELL_ATTR6_IGNORE_CASTER_AURAS: return {"SPELL_ATTR6_IGNORE_CASTER_AURAS", "SPELL_ATTR6_IGNORE_CASTER_AURAS", "2"};
        case SPELL_ATTR6_ASSIST_IGNORE_IMMUNE_FLAG: return {"SPELL_ATTR6_ASSIST_IGNORE_IMMUNE_FLAG", "SPELL_ATTR6_ASSIST_IGNORE_IMMUNE_FLAG", "3 skips checking UNIT_FLAG_IMMUNE_TO_PC and UNIT_FLAG_IMMUNE_TO_NPC flags on assist"};
        case SPELL_ATTR6_UNK4: return {"SPELL_ATTR6_UNK4", "SPELL_ATTR6_UNK4", "4"};
        case SPELL_ATTR6_DONT_CONSUME_PROC_CHARGES: return {"SPELL_ATTR6_DONT_CONSUME_PROC_CHARGES", "SPELL_ATTR6_DONT_CONSUME_PROC_CHARGES", "5 dont consume proc charges"};
        case SPELL_ATTR6_USE_SPELL_CAST_EVENT: return {"SPELL_ATTR6_USE_SPELL_CAST_EVENT", "SPELL_ATTR6_USE_SPELL_CAST_EVENT", "6 Auras with this attribute trigger SPELL_CAST combat log event instead of SPELL_AURA_START (clientside attribute)"};
        case SPELL_ATTR6_UNK7: return {"SPELL_ATTR6_UNK7", "SPELL_ATTR6_UNK7", "7"};
        case SPELL_ATTR6_CANT_TARGET_CROWD_CONTROLLED: return {"SPELL_ATTR6_CANT_TARGET_CROWD_CONTROLLED", "SPELL_ATTR6_CANT_TARGET_CROWD_CONTROLLED", "8"};
        case SPELL_ATTR6_UNK9: return {"SPELL_ATTR6_UNK9", "SPELL_ATTR6_UNK9", "9"};
        case SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS: return {"SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS", "SPELL_ATTR6_CAN_TARGET_POSSESSED_FRIENDS", "10 NYI!"};
        case SPELL_ATTR6_NOT_IN_RAID_INSTANCE: return {"SPELL_ATTR6_NOT_IN_RAID_INSTANCE", "SPELL_ATTR6_NOT_IN_RAID_INSTANCE", "11 not usable in raid instance"};
        case SPELL_ATTR6_CASTABLE_WHILE_ON_VEHICLE: return {"SPELL_ATTR6_CASTABLE_WHILE_ON_VEHICLE", "SPELL_ATTR6_CASTABLE_WHILE_ON_VEHICLE", "12 castable while caster is on vehicle"};
        case SPELL_ATTR6_CAN_TARGET_INVISIBLE: return {"SPELL_ATTR6_CAN_TARGET_INVISIBLE", "SPELL_ATTR6_CAN_TARGET_INVISIBLE", "13 ignore visibility requirement for spell target (phases, invisibility, etc.)"};
        case SPELL_ATTR6_UNK14: return {"SPELL_ATTR6_UNK14", "SPELL_ATTR6_UNK14", "14"};
        case SPELL_ATTR6_UNK15: return {"SPELL_ATTR6_UNK15", "SPELL_ATTR6_UNK15", "15 only 54368, 67892"};
        case SPELL_ATTR6_UNK16: return {"SPELL_ATTR6_UNK16", "SPELL_ATTR6_UNK16", "16"};
        case SPELL_ATTR6_UNK17: return {"SPELL_ATTR6_UNK17", "SPELL_ATTR6_UNK17", "17 Mount spell"};
        case SPELL_ATTR6_CAST_BY_CHARMER: return {"SPELL_ATTR6_CAST_BY_CHARMER", "SPELL_ATTR6_CAST_BY_CHARMER", "18 client won't allow to cast these spells when unit is not possessed && charmer of caster will be original caster"};
        case SPELL_ATTR6_UNK19: return {"SPELL_ATTR6_UNK19", "SPELL_ATTR6_UNK19", "19 only 47488, 50782"};
        case SPELL_ATTR6_ONLY_VISIBLE_TO_CASTER: return {"SPELL_ATTR6_ONLY_VISIBLE_TO_CASTER", "SPELL_ATTR6_ONLY_VISIBLE_TO_CASTER", "20 Auras with this attribute are only visible to their caster (or pet's owner)"};
        case SPELL_ATTR6_CLIENT_UI_TARGET_EFFECTS: return {"SPELL_ATTR6_CLIENT_UI_TARGET_EFFECTS", "SPELL_ATTR6_CLIENT_UI_TARGET_EFFECTS", "21 it's only client-side attribute"};
        case SPELL_ATTR6_UNK22: return {"SPELL_ATTR6_UNK22", "SPELL_ATTR6_UNK22", "22 only 72054"};
        case SPELL_ATTR6_UNK23: return {"SPELL_ATTR6_UNK23", "SPELL_ATTR6_UNK23", "23"};
        case SPELL_ATTR6_CAN_TARGET_UNTARGETABLE: return {"SPELL_ATTR6_CAN_TARGET_UNTARGETABLE", "SPELL_ATTR6_CAN_TARGET_UNTARGETABLE", "24"};
        case SPELL_ATTR6_NOT_RESET_SWING_IF_INSTANT: return {"SPELL_ATTR6_NOT_RESET_SWING_IF_INSTANT", "SPELL_ATTR6_NOT_RESET_SWING_IF_INSTANT", "25 Exorcism, Flash of Light"};
        case SPELL_ATTR6_UNK26: return {"SPELL_ATTR6_UNK26", "SPELL_ATTR6_UNK26", "26 related to player castable positive buff"};
        case SPELL_ATTR6_LIMIT_PCT_HEALING_MODS: return {"SPELL_ATTR6_LIMIT_PCT_HEALING_MODS", "SPELL_ATTR6_LIMIT_PCT_HEALING_MODS", "27 some custom rules - complicated"};
        case SPELL_ATTR6_UNK28: return {"SPELL_ATTR6_UNK28", "SPELL_ATTR6_UNK28", "28 Death Grip"};
        case SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS: return {"SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS", "SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS", "29 ignores done percent damage mods? some custom rules - complicated"};
        case SPELL_ATTR6_UNK30: return {"SPELL_ATTR6_UNK30", "SPELL_ATTR6_UNK30", "30"};
        case SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS: return {"SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS", "SPELL_ATTR6_IGNORE_CATEGORY_COOLDOWN_MODS", "31 Spells with this attribute skip applying modifiers to category cooldowns"};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<SpellAttr6>::Count() { return 32; }
template <>
TC_API_EXPORT SpellAttr6 Trinity::Impl::EnumUtils<SpellAttr6>::FromIndex(size_t index)
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
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<SpellAttr7>::ToString(SpellAttr7 value)
{
    switch (value)
    {
        case SPELL_ATTR7_UNK0: return {"SPELL_ATTR7_UNK0", "SPELL_ATTR7_UNK0", "0 Shaman's new spells (Call of the ...), Feign Death."};
        case SPELL_ATTR7_IGNORE_DURATION_MODS: return {"SPELL_ATTR7_IGNORE_DURATION_MODS", "SPELL_ATTR7_IGNORE_DURATION_MODS", "1 Duration is not affected by duration modifiers"};
        case SPELL_ATTR7_REACTIVATE_AT_RESURRECT: return {"SPELL_ATTR7_REACTIVATE_AT_RESURRECT", "SPELL_ATTR7_REACTIVATE_AT_RESURRECT", "2 Paladin's auras and 65607 only."};
        case SPELL_ATTR7_IS_CHEAT_SPELL: return {"SPELL_ATTR7_IS_CHEAT_SPELL", "SPELL_ATTR7_IS_CHEAT_SPELL", "3 Cannot cast if caster doesn't have UnitFlag2 & UNIT_FLAG2_ALLOW_CHEAT_SPELLS"};
        case SPELL_ATTR7_UNK4: return {"SPELL_ATTR7_UNK4", "SPELL_ATTR7_UNK4", "4 Only 47883 (Soulstone Resurrection) and test spell."};
        case SPELL_ATTR7_SUMMON_PLAYER_TOTEM: return {"SPELL_ATTR7_SUMMON_PLAYER_TOTEM", "SPELL_ATTR7_SUMMON_PLAYER_TOTEM", "5 Only Shaman player totems."};
        case SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE: return {"SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE", "SPELL_ATTR7_NO_PUSHBACK_ON_DAMAGE", "6 Does not cause spell pushback on damage"};
        case SPELL_ATTR7_UNK7: return {"SPELL_ATTR7_UNK7", "SPELL_ATTR7_UNK7", "7 66218 (Launch) spell."};
        case SPELL_ATTR7_HORDE_ONLY: return {"SPELL_ATTR7_HORDE_ONLY", "SPELL_ATTR7_HORDE_ONLY", "8 Teleports, mounts and other spells."};
        case SPELL_ATTR7_ALLIANCE_ONLY: return {"SPELL_ATTR7_ALLIANCE_ONLY", "SPELL_ATTR7_ALLIANCE_ONLY", "9 Teleports, mounts and other spells."};
        case SPELL_ATTR7_DISPEL_CHARGES: return {"SPELL_ATTR7_DISPEL_CHARGES", "SPELL_ATTR7_DISPEL_CHARGES", "10 Dispel and Spellsteal individual charges instead of whole aura."};
        case SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER: return {"SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER", "SPELL_ATTR7_INTERRUPT_ONLY_NONPLAYER", "11 Only non-player casts interrupt, though Feral Charge - Bear has it."};
        case SPELL_ATTR7_UNK12: return {"SPELL_ATTR7_UNK12", "SPELL_ATTR7_UNK12", "12 Not set in 3.2.2a."};
        case SPELL_ATTR7_UNK13: return {"SPELL_ATTR7_UNK13", "SPELL_ATTR7_UNK13", "13 Not set in 3.2.2a."};
        case SPELL_ATTR7_UNK14: return {"SPELL_ATTR7_UNK14", "SPELL_ATTR7_UNK14", "14 Only 52150 (Raise Dead - Pet) spell."};
        case SPELL_ATTR7_UNK15: return {"SPELL_ATTR7_UNK15", "SPELL_ATTR7_UNK15", "15 Exorcism. Usable on players? 100% crit chance on undead and demons?"};
        case SPELL_ATTR7_CAN_RESTORE_SECONDARY_POWER: return {"SPELL_ATTR7_CAN_RESTORE_SECONDARY_POWER", "SPELL_ATTR7_CAN_RESTORE_SECONDARY_POWER", "16 These spells can replenish a powertype, which is not the current powertype."};
        case SPELL_ATTR7_UNK17: return {"SPELL_ATTR7_UNK17", "SPELL_ATTR7_UNK17", "17 Only 27965 (Suicide) spell."};
        case SPELL_ATTR7_HAS_CHARGE_EFFECT: return {"SPELL_ATTR7_HAS_CHARGE_EFFECT", "SPELL_ATTR7_HAS_CHARGE_EFFECT", "18 Only spells that have Charge among effects."};
        case SPELL_ATTR7_ZONE_TELEPORT: return {"SPELL_ATTR7_ZONE_TELEPORT", "SPELL_ATTR7_ZONE_TELEPORT", "19 Teleports to specific zones."};
        case SPELL_ATTR7_UNK20: return {"SPELL_ATTR7_UNK20", "SPELL_ATTR7_UNK20", "20 Blink, Divine Shield, Ice Block"};
        case SPELL_ATTR7_UNK21: return {"SPELL_ATTR7_UNK21", "SPELL_ATTR7_UNK21", "21 Not set"};
        case SPELL_ATTR7_IGNORE_COLD_WEATHER_FLYING: return {"SPELL_ATTR7_IGNORE_COLD_WEATHER_FLYING", "SPELL_ATTR7_IGNORE_COLD_WEATHER_FLYING", "22 Loaned Gryphon, Loaned Wind Rider"};
        case SPELL_ATTR7_UNK23: return {"SPELL_ATTR7_UNK23", "SPELL_ATTR7_UNK23", "23 Motivate, Mutilate, Shattering Throw"};
        case SPELL_ATTR7_UNK24: return {"SPELL_ATTR7_UNK24", "SPELL_ATTR7_UNK24", "24 Motivate, Mutilate, Perform Speech, Shattering Throw"};
        case SPELL_ATTR7_UNK25: return {"SPELL_ATTR7_UNK25", "SPELL_ATTR7_UNK25", "25"};
        case SPELL_ATTR7_UNK26: return {"SPELL_ATTR7_UNK26", "SPELL_ATTR7_UNK26", "26"};
        case SPELL_ATTR7_UNK27: return {"SPELL_ATTR7_UNK27", "SPELL_ATTR7_UNK27", "27 Not set"};
        case SPELL_ATTR7_CONSOLIDATED_RAID_BUFF: return {"SPELL_ATTR7_CONSOLIDATED_RAID_BUFF", "SPELL_ATTR7_CONSOLIDATED_RAID_BUFF", "28 May be collapsed in raid buff frame (clientside attribute)"};
        case SPELL_ATTR7_UNK29: return {"SPELL_ATTR7_UNK29", "SPELL_ATTR7_UNK29", "29 only 69028, 71237"};
        case SPELL_ATTR7_UNK30: return {"SPELL_ATTR7_UNK30", "SPELL_ATTR7_UNK30", "30 Burning Determination, Divine Sacrifice, Earth Shield, Prayer of Mending"};
        case SPELL_ATTR7_CLIENT_INDICATOR: return {"SPELL_ATTR7_CLIENT_INDICATOR", "SPELL_ATTR7_CLIENT_INDICATOR", ""};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<SpellAttr7>::Count() { return 32; }
template <>
TC_API_EXPORT SpellAttr7 Trinity::Impl::EnumUtils<SpellAttr7>::FromIndex(size_t index)
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

/*****************************************************************\
|* data for enum 'Mechanics' in 'SharedDefines.h' auto-generated *|
\*****************************************************************/
template <>
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<Mechanics>::ToString(Mechanics value)
{
    switch (value)
    {
        case MECHANIC_NONE: return {"MECHANIC_NONE", "MECHANIC_NONE", ""};
        case MECHANIC_CHARM: return {"MECHANIC_CHARM", "MECHANIC_CHARM", ""};
        case MECHANIC_DISORIENTED: return {"MECHANIC_DISORIENTED", "MECHANIC_DISORIENTED", ""};
        case MECHANIC_DISARM: return {"MECHANIC_DISARM", "MECHANIC_DISARM", ""};
        case MECHANIC_DISTRACT: return {"MECHANIC_DISTRACT", "MECHANIC_DISTRACT", ""};
        case MECHANIC_FEAR: return {"MECHANIC_FEAR", "MECHANIC_FEAR", ""};
        case MECHANIC_GRIP: return {"MECHANIC_GRIP", "MECHANIC_GRIP", ""};
        case MECHANIC_ROOT: return {"MECHANIC_ROOT", "MECHANIC_ROOT", ""};
        case MECHANIC_SLOW_ATTACK: return {"MECHANIC_SLOW_ATTACK", "MECHANIC_SLOW_ATTACK", ""};
        case MECHANIC_SILENCE: return {"MECHANIC_SILENCE", "MECHANIC_SILENCE", ""};
        case MECHANIC_SLEEP: return {"MECHANIC_SLEEP", "MECHANIC_SLEEP", ""};
        case MECHANIC_SNARE: return {"MECHANIC_SNARE", "MECHANIC_SNARE", ""};
        case MECHANIC_STUN: return {"MECHANIC_STUN", "MECHANIC_STUN", ""};
        case MECHANIC_FREEZE: return {"MECHANIC_FREEZE", "MECHANIC_FREEZE", ""};
        case MECHANIC_KNOCKOUT: return {"MECHANIC_KNOCKOUT", "MECHANIC_KNOCKOUT", ""};
        case MECHANIC_BLEED: return {"MECHANIC_BLEED", "MECHANIC_BLEED", ""};
        case MECHANIC_BANDAGE: return {"MECHANIC_BANDAGE", "MECHANIC_BANDAGE", ""};
        case MECHANIC_POLYMORPH: return {"MECHANIC_POLYMORPH", "MECHANIC_POLYMORPH", ""};
        case MECHANIC_BANISH: return {"MECHANIC_BANISH", "MECHANIC_BANISH", ""};
        case MECHANIC_SHIELD: return {"MECHANIC_SHIELD", "MECHANIC_SHIELD", ""};
        case MECHANIC_SHACKLE: return {"MECHANIC_SHACKLE", "MECHANIC_SHACKLE", ""};
        case MECHANIC_MOUNT: return {"MECHANIC_MOUNT", "MECHANIC_MOUNT", ""};
        case MECHANIC_INFECTED: return {"MECHANIC_INFECTED", "MECHANIC_INFECTED", ""};
        case MECHANIC_TURN: return {"MECHANIC_TURN", "MECHANIC_TURN", ""};
        case MECHANIC_HORROR: return {"MECHANIC_HORROR", "MECHANIC_HORROR", ""};
        case MECHANIC_INVULNERABILITY: return {"MECHANIC_INVULNERABILITY", "MECHANIC_INVULNERABILITY", ""};
        case MECHANIC_INTERRUPT: return {"MECHANIC_INTERRUPT", "MECHANIC_INTERRUPT", ""};
        case MECHANIC_DAZE: return {"MECHANIC_DAZE", "MECHANIC_DAZE", ""};
        case MECHANIC_DISCOVERY: return {"MECHANIC_DISCOVERY", "MECHANIC_DISCOVERY", ""};
        case MECHANIC_IMMUNE_SHIELD: return {"MECHANIC_IMMUNE_SHIELD", "MECHANIC_IMMUNE_SHIELD", "Divine (Blessing) Shield/Protection and Ice Block"};
        case MECHANIC_SAPPED: return {"MECHANIC_SAPPED", "MECHANIC_SAPPED", ""};
        case MECHANIC_ENRAGED: return {"MECHANIC_ENRAGED", "MECHANIC_ENRAGED", ""};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<Mechanics>::Count() { return 32; }
template <>
TC_API_EXPORT Mechanics Trinity::Impl::EnumUtils<Mechanics>::FromIndex(size_t index)
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
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<SpellDmgClass>::ToString(SpellDmgClass value)
{
    switch (value)
    {
        case SPELL_DAMAGE_CLASS_NONE: return {"SPELL_DAMAGE_CLASS_NONE", "None", ""};
        case SPELL_DAMAGE_CLASS_MAGIC: return {"SPELL_DAMAGE_CLASS_MAGIC", "Magic", ""};
        case SPELL_DAMAGE_CLASS_MELEE: return {"SPELL_DAMAGE_CLASS_MELEE", "Melee", ""};
        case SPELL_DAMAGE_CLASS_RANGED: return {"SPELL_DAMAGE_CLASS_RANGED", "Ranged", ""};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<SpellDmgClass>::Count() { return 4; }
template <>
TC_API_EXPORT SpellDmgClass Trinity::Impl::EnumUtils<SpellDmgClass>::FromIndex(size_t index)
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
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<SpellPreventionType>::ToString(SpellPreventionType value)
{
    switch (value)
    {
        case SPELL_PREVENTION_TYPE_NONE: return {"SPELL_PREVENTION_TYPE_NONE", "None", ""};
        case SPELL_PREVENTION_TYPE_SILENCE: return {"SPELL_PREVENTION_TYPE_SILENCE", "Silence", ""};
        case SPELL_PREVENTION_TYPE_PACIFY: return {"SPELL_PREVENTION_TYPE_PACIFY", "Pacify", ""};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<SpellPreventionType>::Count() { return 3; }
template <>
TC_API_EXPORT SpellPreventionType Trinity::Impl::EnumUtils<SpellPreventionType>::FromIndex(size_t index)
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
TC_API_EXPORT EnumText Trinity::Impl::EnumUtils<SpellFamilyNames>::ToString(SpellFamilyNames value)
{
    switch (value)
    {
        case SPELLFAMILY_GENERIC: return {"SPELLFAMILY_GENERIC", "Generic", ""};
        case SPELLFAMILY_UNK1: return {"SPELLFAMILY_UNK1", "Unk1 (events, holidays, ...)", ""};
        case SPELLFAMILY_MAGE: return {"SPELLFAMILY_MAGE", "Mage", ""};
        case SPELLFAMILY_WARRIOR: return {"SPELLFAMILY_WARRIOR", "Warrior", ""};
        case SPELLFAMILY_WARLOCK: return {"SPELLFAMILY_WARLOCK", "Warlock", ""};
        case SPELLFAMILY_PRIEST: return {"SPELLFAMILY_PRIEST", "Priest", ""};
        case SPELLFAMILY_DRUID: return {"SPELLFAMILY_DRUID", "Druid", ""};
        case SPELLFAMILY_ROGUE: return {"SPELLFAMILY_ROGUE", "Rogue", ""};
        case SPELLFAMILY_HUNTER: return {"SPELLFAMILY_HUNTER", "Hunter", ""};
        case SPELLFAMILY_PALADIN: return {"SPELLFAMILY_PALADIN", "Paladin", ""};
        case SPELLFAMILY_SHAMAN: return {"SPELLFAMILY_SHAMAN", "Shaman", ""};
        case SPELLFAMILY_UNK2: return {"SPELLFAMILY_UNK2", "Unk2 (Silence resistance?)", ""};
        case SPELLFAMILY_POTION: return {"SPELLFAMILY_POTION", "Potion", ""};
        case SPELLFAMILY_DEATHKNIGHT: return {"SPELLFAMILY_DEATHKNIGHT", "Death Knight", ""};
        case SPELLFAMILY_PET: return {"SPELLFAMILY_PET", "Pet", ""};
        default: throw std::out_of_range("value");
    }
}
template <>
TC_API_EXPORT size_t Trinity::Impl::EnumUtils<SpellFamilyNames>::Count() { return 15; }
template <>
TC_API_EXPORT SpellFamilyNames Trinity::Impl::EnumUtils<SpellFamilyNames>::FromIndex(size_t index)
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

