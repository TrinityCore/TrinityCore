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

#include "UnitDefines.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/***************************************************************\
|* data for enum 'UnitFlags' in 'UnitDefines.h' auto-generated *|
\***************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<UnitFlags>::ToString(UnitFlags value)
{
    switch (value)
    {
        case UNIT_FLAG_SERVER_CONTROLLED: return { "UNIT_FLAG_SERVER_CONTROLLED", "UNIT_FLAG_SERVER_CONTROLLED", "set only when unit movement is controlled by server - by SPLINE/MONSTER_MOVE packets, together with UNIT_FLAG_STUNNED; only set to units controlled by client; client function CGUnit_C::IsClientControlled returns false when set for owner" };
        case UNIT_FLAG_NON_ATTACKABLE: return { "UNIT_FLAG_NON_ATTACKABLE", "UNIT_FLAG_NON_ATTACKABLE", "not attackable" };
        case UNIT_FLAG_REMOVE_CLIENT_CONTROL: return { "UNIT_FLAG_REMOVE_CLIENT_CONTROL", "UNIT_FLAG_REMOVE_CLIENT_CONTROL", "This is a legacy flag used to disable movement player's movement while controlling other units, SMSG_CLIENT_CONTROL replaces this functionality clientside now. CONFUSED and FLEEING flags have the same effect on client movement asDISABLE_MOVE_CONTROL in addition to preventing spell casts/autoattack (they all allow climbing steeper hills and emotes while moving)" };
        case UNIT_FLAG_PLAYER_CONTROLLED: return { "UNIT_FLAG_PLAYER_CONTROLLED", "UNIT_FLAG_PLAYER_CONTROLLED", "controlled by player, use _IMMUNE_TO_PC instead of _IMMUNE_TO_NPC" };
        case UNIT_FLAG_RENAME: return { "UNIT_FLAG_RENAME", "UNIT_FLAG_RENAME", "" };
        case UNIT_FLAG_PREPARATION: return { "UNIT_FLAG_PREPARATION", "UNIT_FLAG_PREPARATION", "don't take reagents for spells with SPELL_ATTR5_NO_REAGENT_WHILE_PREP" };
        case UNIT_FLAG_UNK_6: return { "UNIT_FLAG_UNK_6", "UNIT_FLAG_UNK_6", "" };
        case UNIT_FLAG_NOT_ATTACKABLE_1: return { "UNIT_FLAG_NOT_ATTACKABLE_1", "UNIT_FLAG_NOT_ATTACKABLE_1", "?? (UNIT_FLAG_PLAYER_CONTROLLED | UNIT_FLAG_NOT_ATTACKABLE_1) is NON_PVP_ATTACKABLE" };
        case UNIT_FLAG_IMMUNE_TO_PC: return { "UNIT_FLAG_IMMUNE_TO_PC", "UNIT_FLAG_IMMUNE_TO_PC", "disables combat/assistance with PlayerCharacters (PC) - see Unit::IsValidAttackTarget, Unit::IsValidAssistTarget" };
        case UNIT_FLAG_IMMUNE_TO_NPC: return { "UNIT_FLAG_IMMUNE_TO_NPC", "UNIT_FLAG_IMMUNE_TO_NPC", "disables combat/assistance with NonPlayerCharacters (NPC) - see Unit::IsValidAttackTarget, Unit::IsValidAssistTarget" };
        case UNIT_FLAG_LOOTING: return { "UNIT_FLAG_LOOTING", "UNIT_FLAG_LOOTING", "loot animation" };
        case UNIT_FLAG_PET_IN_COMBAT: return { "UNIT_FLAG_PET_IN_COMBAT", "UNIT_FLAG_PET_IN_COMBAT", "on player pets: whether the pet is chasing a target to attack || on other units: whether any of the unit's minions is in combat" };
        case UNIT_FLAG_PVP: return { "UNIT_FLAG_PVP", "UNIT_FLAG_PVP", "changed in 3.0.3" };
        case UNIT_FLAG_SILENCED: return { "UNIT_FLAG_SILENCED", "UNIT_FLAG_SILENCED", "silenced, 2.1.1" };
        case UNIT_FLAG_CANNOT_SWIM: return { "UNIT_FLAG_CANNOT_SWIM", "UNIT_FLAG_CANNOT_SWIM", "2.0.8" };
        case UNIT_FLAG_SWIMMING: return { "UNIT_FLAG_SWIMMING", "UNIT_FLAG_SWIMMING", "shows swim animation in water" };
        case UNIT_FLAG_NON_ATTACKABLE_2: return { "UNIT_FLAG_NON_ATTACKABLE_2", "UNIT_FLAG_NON_ATTACKABLE_2", "removes attackable icon, if on yourself, cannot assist self but can cast TARGET_SELF spells - added by SPELL_AURA_MOD_UNATTACKABLE" };
        case UNIT_FLAG_PACIFIED: return { "UNIT_FLAG_PACIFIED", "UNIT_FLAG_PACIFIED", "3.0.3 ok" };
        case UNIT_FLAG_STUNNED: return { "UNIT_FLAG_STUNNED", "UNIT_FLAG_STUNNED", "3.0.3 ok" };
        case UNIT_FLAG_IN_COMBAT: return { "UNIT_FLAG_IN_COMBAT", "UNIT_FLAG_IN_COMBAT", "" };
        case UNIT_FLAG_TAXI_FLIGHT: return { "UNIT_FLAG_TAXI_FLIGHT", "UNIT_FLAG_TAXI_FLIGHT", "disable casting at client side spell not allowed by taxi flight (mounted?), probably used with 0x4 flag" };
        case UNIT_FLAG_DISARMED: return { "UNIT_FLAG_DISARMED", "UNIT_FLAG_DISARMED", "3.0.3, disable melee spells casting..., \042Required melee weapon\042 added to melee spells tooltip." };
        case UNIT_FLAG_CONFUSED: return { "UNIT_FLAG_CONFUSED", "UNIT_FLAG_CONFUSED", "" };
        case UNIT_FLAG_FLEEING: return { "UNIT_FLAG_FLEEING", "UNIT_FLAG_FLEEING", "" };
        case UNIT_FLAG_POSSESSED: return { "UNIT_FLAG_POSSESSED", "UNIT_FLAG_POSSESSED", "under direct client control by a player (possess or vehicle)" };
        case UNIT_FLAG_NOT_SELECTABLE: return { "UNIT_FLAG_NOT_SELECTABLE", "UNIT_FLAG_NOT_SELECTABLE", "" };
        case UNIT_FLAG_SKINNABLE: return { "UNIT_FLAG_SKINNABLE", "UNIT_FLAG_SKINNABLE", "" };
        case UNIT_FLAG_MOUNT: return { "UNIT_FLAG_MOUNT", "UNIT_FLAG_MOUNT", "" };
        case UNIT_FLAG_UNK_28: return { "UNIT_FLAG_UNK_28", "UNIT_FLAG_UNK_28", "" };
        case UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT: return { "UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT", "UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT", "Prevent automatically playing emotes from parsing chat text, for example \042lol\042 in /say, ending message with ? or !, or using /yell" };
        case UNIT_FLAG_SHEATHE: return { "UNIT_FLAG_SHEATHE", "UNIT_FLAG_SHEATHE", "" };
        case UNIT_FLAG_IMMUNE: return { "UNIT_FLAG_IMMUNE", "UNIT_FLAG_IMMUNE", "Immune to damage" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<UnitFlags>::Count() { return 32; }

template <>
TC_API_EXPORT UnitFlags EnumUtils<UnitFlags>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return UNIT_FLAG_SERVER_CONTROLLED;
        case 1: return UNIT_FLAG_NON_ATTACKABLE;
        case 2: return UNIT_FLAG_REMOVE_CLIENT_CONTROL;
        case 3: return UNIT_FLAG_PLAYER_CONTROLLED;
        case 4: return UNIT_FLAG_RENAME;
        case 5: return UNIT_FLAG_PREPARATION;
        case 6: return UNIT_FLAG_UNK_6;
        case 7: return UNIT_FLAG_NOT_ATTACKABLE_1;
        case 8: return UNIT_FLAG_IMMUNE_TO_PC;
        case 9: return UNIT_FLAG_IMMUNE_TO_NPC;
        case 10: return UNIT_FLAG_LOOTING;
        case 11: return UNIT_FLAG_PET_IN_COMBAT;
        case 12: return UNIT_FLAG_PVP;
        case 13: return UNIT_FLAG_SILENCED;
        case 14: return UNIT_FLAG_CANNOT_SWIM;
        case 15: return UNIT_FLAG_SWIMMING;
        case 16: return UNIT_FLAG_NON_ATTACKABLE_2;
        case 17: return UNIT_FLAG_PACIFIED;
        case 18: return UNIT_FLAG_STUNNED;
        case 19: return UNIT_FLAG_IN_COMBAT;
        case 20: return UNIT_FLAG_TAXI_FLIGHT;
        case 21: return UNIT_FLAG_DISARMED;
        case 22: return UNIT_FLAG_CONFUSED;
        case 23: return UNIT_FLAG_FLEEING;
        case 24: return UNIT_FLAG_POSSESSED;
        case 25: return UNIT_FLAG_NOT_SELECTABLE;
        case 26: return UNIT_FLAG_SKINNABLE;
        case 27: return UNIT_FLAG_MOUNT;
        case 28: return UNIT_FLAG_UNK_28;
        case 29: return UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT;
        case 30: return UNIT_FLAG_SHEATHE;
        case 31: return UNIT_FLAG_IMMUNE;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<UnitFlags>::ToIndex(UnitFlags value)
{
    switch (value)
    {
        case UNIT_FLAG_SERVER_CONTROLLED: return 0;
        case UNIT_FLAG_NON_ATTACKABLE: return 1;
        case UNIT_FLAG_REMOVE_CLIENT_CONTROL: return 2;
        case UNIT_FLAG_PLAYER_CONTROLLED: return 3;
        case UNIT_FLAG_RENAME: return 4;
        case UNIT_FLAG_PREPARATION: return 5;
        case UNIT_FLAG_UNK_6: return 6;
        case UNIT_FLAG_NOT_ATTACKABLE_1: return 7;
        case UNIT_FLAG_IMMUNE_TO_PC: return 8;
        case UNIT_FLAG_IMMUNE_TO_NPC: return 9;
        case UNIT_FLAG_LOOTING: return 10;
        case UNIT_FLAG_PET_IN_COMBAT: return 11;
        case UNIT_FLAG_PVP: return 12;
        case UNIT_FLAG_SILENCED: return 13;
        case UNIT_FLAG_CANNOT_SWIM: return 14;
        case UNIT_FLAG_SWIMMING: return 15;
        case UNIT_FLAG_NON_ATTACKABLE_2: return 16;
        case UNIT_FLAG_PACIFIED: return 17;
        case UNIT_FLAG_STUNNED: return 18;
        case UNIT_FLAG_IN_COMBAT: return 19;
        case UNIT_FLAG_TAXI_FLIGHT: return 20;
        case UNIT_FLAG_DISARMED: return 21;
        case UNIT_FLAG_CONFUSED: return 22;
        case UNIT_FLAG_FLEEING: return 23;
        case UNIT_FLAG_POSSESSED: return 24;
        case UNIT_FLAG_NOT_SELECTABLE: return 25;
        case UNIT_FLAG_SKINNABLE: return 26;
        case UNIT_FLAG_MOUNT: return 27;
        case UNIT_FLAG_UNK_28: return 28;
        case UNIT_FLAG_PREVENT_EMOTES_FROM_CHAT_TEXT: return 29;
        case UNIT_FLAG_SHEATHE: return 30;
        case UNIT_FLAG_IMMUNE: return 31;
        default: throw std::out_of_range("value");
    }
}

/**************************************************************\
|* data for enum 'NPCFlags' in 'UnitDefines.h' auto-generated *|
\**************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<NPCFlags>::ToString(NPCFlags value)
{
    switch (value)
    {
        case UNIT_NPC_FLAG_GOSSIP: return { "UNIT_NPC_FLAG_GOSSIP", "has gossip menu", "100%" };
        case UNIT_NPC_FLAG_QUESTGIVER: return { "UNIT_NPC_FLAG_QUESTGIVER", "is quest giver", "guessed, probably ok" };
        case UNIT_NPC_FLAG_UNK1: return { "UNIT_NPC_FLAG_UNK1", "UNIT_NPC_FLAG_UNK1", "" };
        case UNIT_NPC_FLAG_UNK2: return { "UNIT_NPC_FLAG_UNK2", "UNIT_NPC_FLAG_UNK2", "" };
        case UNIT_NPC_FLAG_TRAINER: return { "UNIT_NPC_FLAG_TRAINER", "is trainer", "100%" };
        case UNIT_NPC_FLAG_TRAINER_CLASS: return { "UNIT_NPC_FLAG_TRAINER_CLASS", "is class trainer", "100%" };
        case UNIT_NPC_FLAG_TRAINER_PROFESSION: return { "UNIT_NPC_FLAG_TRAINER_PROFESSION", "is profession trainer", "100%" };
        case UNIT_NPC_FLAG_VENDOR: return { "UNIT_NPC_FLAG_VENDOR", "is vendor (generic)", "100%" };
        case UNIT_NPC_FLAG_VENDOR_AMMO: return { "UNIT_NPC_FLAG_VENDOR_AMMO", "is vendor (ammo)", "100%, general goods vendor" };
        case UNIT_NPC_FLAG_VENDOR_FOOD: return { "UNIT_NPC_FLAG_VENDOR_FOOD", "is vendor (food)", "100%" };
        case UNIT_NPC_FLAG_VENDOR_POISON: return { "UNIT_NPC_FLAG_VENDOR_POISON", "is vendor (poison)", "guessed" };
        case UNIT_NPC_FLAG_VENDOR_REAGENT: return { "UNIT_NPC_FLAG_VENDOR_REAGENT", "is vendor (reagents)", "100%" };
        case UNIT_NPC_FLAG_REPAIR: return { "UNIT_NPC_FLAG_REPAIR", "can repair", "100%" };
        case UNIT_NPC_FLAG_FLIGHTMASTER: return { "UNIT_NPC_FLAG_FLIGHTMASTER", "is flight master", "100%" };
        case UNIT_NPC_FLAG_SPIRITHEALER: return { "UNIT_NPC_FLAG_SPIRITHEALER", "is spirit healer", "guessed" };
        case UNIT_NPC_FLAG_SPIRITGUIDE: return { "UNIT_NPC_FLAG_SPIRITGUIDE", "is spirit guide", "guessed" };
        case UNIT_NPC_FLAG_INNKEEPER: return { "UNIT_NPC_FLAG_INNKEEPER", "is innkeeper", "" };
        case UNIT_NPC_FLAG_BANKER: return { "UNIT_NPC_FLAG_BANKER", "is banker", "100%" };
        case UNIT_NPC_FLAG_PETITIONER: return { "UNIT_NPC_FLAG_PETITIONER", "handles guild/arena petitions", "100% 0xC0000 = guild petitions, 0x40000 = arena team petitions" };
        case UNIT_NPC_FLAG_TABARDDESIGNER: return { "UNIT_NPC_FLAG_TABARDDESIGNER", "is guild tabard designer", "100%" };
        case UNIT_NPC_FLAG_BATTLEMASTER: return { "UNIT_NPC_FLAG_BATTLEMASTER", "is battlemaster", "100%" };
        case UNIT_NPC_FLAG_AUCTIONEER: return { "UNIT_NPC_FLAG_AUCTIONEER", "is auctioneer", "100%" };
        case UNIT_NPC_FLAG_STABLEMASTER: return { "UNIT_NPC_FLAG_STABLEMASTER", "is stable master", "100%" };
        case UNIT_NPC_FLAG_GUILD_BANKER: return { "UNIT_NPC_FLAG_GUILD_BANKER", "is guild banker", "cause client to send 997 opcode" };
        case UNIT_NPC_FLAG_SPELLCLICK: return { "UNIT_NPC_FLAG_SPELLCLICK", "has spell click enabled", "cause client to send 1015 opcode (spell click)" };
        case UNIT_NPC_FLAG_PLAYER_VEHICLE: return { "UNIT_NPC_FLAG_PLAYER_VEHICLE", "is player vehicle", "players with mounts that have vehicle data should have it set" };
        case UNIT_NPC_FLAG_MAILBOX: return { "UNIT_NPC_FLAG_MAILBOX", "is mailbox", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<NPCFlags>::Count() { return 27; }

template <>
TC_API_EXPORT NPCFlags EnumUtils<NPCFlags>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return UNIT_NPC_FLAG_GOSSIP;
        case 1: return UNIT_NPC_FLAG_QUESTGIVER;
        case 2: return UNIT_NPC_FLAG_UNK1;
        case 3: return UNIT_NPC_FLAG_UNK2;
        case 4: return UNIT_NPC_FLAG_TRAINER;
        case 5: return UNIT_NPC_FLAG_TRAINER_CLASS;
        case 6: return UNIT_NPC_FLAG_TRAINER_PROFESSION;
        case 7: return UNIT_NPC_FLAG_VENDOR;
        case 8: return UNIT_NPC_FLAG_VENDOR_AMMO;
        case 9: return UNIT_NPC_FLAG_VENDOR_FOOD;
        case 10: return UNIT_NPC_FLAG_VENDOR_POISON;
        case 11: return UNIT_NPC_FLAG_VENDOR_REAGENT;
        case 12: return UNIT_NPC_FLAG_REPAIR;
        case 13: return UNIT_NPC_FLAG_FLIGHTMASTER;
        case 14: return UNIT_NPC_FLAG_SPIRITHEALER;
        case 15: return UNIT_NPC_FLAG_SPIRITGUIDE;
        case 16: return UNIT_NPC_FLAG_INNKEEPER;
        case 17: return UNIT_NPC_FLAG_BANKER;
        case 18: return UNIT_NPC_FLAG_PETITIONER;
        case 19: return UNIT_NPC_FLAG_TABARDDESIGNER;
        case 20: return UNIT_NPC_FLAG_BATTLEMASTER;
        case 21: return UNIT_NPC_FLAG_AUCTIONEER;
        case 22: return UNIT_NPC_FLAG_STABLEMASTER;
        case 23: return UNIT_NPC_FLAG_GUILD_BANKER;
        case 24: return UNIT_NPC_FLAG_SPELLCLICK;
        case 25: return UNIT_NPC_FLAG_PLAYER_VEHICLE;
        case 26: return UNIT_NPC_FLAG_MAILBOX;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<NPCFlags>::ToIndex(NPCFlags value)
{
    switch (value)
    {
        case UNIT_NPC_FLAG_GOSSIP: return 0;
        case UNIT_NPC_FLAG_QUESTGIVER: return 1;
        case UNIT_NPC_FLAG_UNK1: return 2;
        case UNIT_NPC_FLAG_UNK2: return 3;
        case UNIT_NPC_FLAG_TRAINER: return 4;
        case UNIT_NPC_FLAG_TRAINER_CLASS: return 5;
        case UNIT_NPC_FLAG_TRAINER_PROFESSION: return 6;
        case UNIT_NPC_FLAG_VENDOR: return 7;
        case UNIT_NPC_FLAG_VENDOR_AMMO: return 8;
        case UNIT_NPC_FLAG_VENDOR_FOOD: return 9;
        case UNIT_NPC_FLAG_VENDOR_POISON: return 10;
        case UNIT_NPC_FLAG_VENDOR_REAGENT: return 11;
        case UNIT_NPC_FLAG_REPAIR: return 12;
        case UNIT_NPC_FLAG_FLIGHTMASTER: return 13;
        case UNIT_NPC_FLAG_SPIRITHEALER: return 14;
        case UNIT_NPC_FLAG_SPIRITGUIDE: return 15;
        case UNIT_NPC_FLAG_INNKEEPER: return 16;
        case UNIT_NPC_FLAG_BANKER: return 17;
        case UNIT_NPC_FLAG_PETITIONER: return 18;
        case UNIT_NPC_FLAG_TABARDDESIGNER: return 19;
        case UNIT_NPC_FLAG_BATTLEMASTER: return 20;
        case UNIT_NPC_FLAG_AUCTIONEER: return 21;
        case UNIT_NPC_FLAG_STABLEMASTER: return 22;
        case UNIT_NPC_FLAG_GUILD_BANKER: return 23;
        case UNIT_NPC_FLAG_SPELLCLICK: return 24;
        case UNIT_NPC_FLAG_PLAYER_VEHICLE: return 25;
        case UNIT_NPC_FLAG_MAILBOX: return 26;
        default: throw std::out_of_range("value");
    }
}
}
