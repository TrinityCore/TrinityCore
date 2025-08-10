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

#include "QuestDef.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/********************************************************************\
|* data for enum 'QuestFailedReason' in 'QuestDef.h' auto-generated *|
\********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<QuestFailedReason>::ToString(QuestFailedReason value)
{
    switch (value)
    {
        case QUEST_ERR_NONE: return { "QUEST_ERR_NONE", "QUEST_ERR_NONE", "" };
        case QUEST_ERR_FAILED_LOW_LEVEL: return { "QUEST_ERR_FAILED_LOW_LEVEL", "QUEST_ERR_FAILED_LOW_LEVEL", "\042You are not high enough level for that quest.\042\042" };
        case QUEST_ERR_FAILED_WRONG_RACE: return { "QUEST_ERR_FAILED_WRONG_RACE", "QUEST_ERR_FAILED_WRONG_RACE", "\042That quest is not available to your race.\042" };
        case QUEST_ERR_ALREADY_DONE: return { "QUEST_ERR_ALREADY_DONE", "QUEST_ERR_ALREADY_DONE", "\042You have completed that daily quest today.\042" };
        case QUEST_ERR_ONLY_ONE_TIMED: return { "QUEST_ERR_ONLY_ONE_TIMED", "QUEST_ERR_ONLY_ONE_TIMED", "\042You can only be on one timed quest at a time\042" };
        case QUEST_ERR_ALREADY_ON1: return { "QUEST_ERR_ALREADY_ON1", "QUEST_ERR_ALREADY_ON1", "\042You are already on that quest\042" };
        case QUEST_ERR_FAILED_EXPANSION: return { "QUEST_ERR_FAILED_EXPANSION", "QUEST_ERR_FAILED_EXPANSION", "\042This quest requires an expansion enabled account.\042" };
        case QUEST_ERR_ALREADY_ON2: return { "QUEST_ERR_ALREADY_ON2", "QUEST_ERR_ALREADY_ON2", "\042You are already on that quest\042" };
        case QUEST_ERR_FAILED_MISSING_ITEMS: return { "QUEST_ERR_FAILED_MISSING_ITEMS", "QUEST_ERR_FAILED_MISSING_ITEMS", "\042You don't have the required items with you.  Check storage.\042" };
        case QUEST_ERR_FAILED_NOT_ENOUGH_MONEY: return { "QUEST_ERR_FAILED_NOT_ENOUGH_MONEY", "QUEST_ERR_FAILED_NOT_ENOUGH_MONEY", "\042You don't have enough money for that quest\042" };
        case QUEST_ERR_FAILED_CAIS: return { "QUEST_ERR_FAILED_CAIS", "QUEST_ERR_FAILED_CAIS", "\042You cannot complete quests once you have reached tired time\042" };
        case QUEST_ERR_ALREADY_DONE_DAILY: return { "QUEST_ERR_ALREADY_DONE_DAILY", "QUEST_ERR_ALREADY_DONE_DAILY", "\042You have completed that daily quest today.\042" };
        case QUEST_ERR_FAILED_SPELL: return { "QUEST_ERR_FAILED_SPELL", "QUEST_ERR_FAILED_SPELL", "\042You haven't learned the required spell.\042" };
        case QUEST_ERR_HAS_IN_PROGRESS: return { "QUEST_ERR_HAS_IN_PROGRESS", "QUEST_ERR_HAS_IN_PROGRESS", "\042Progress Bar objective not completed\042" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<QuestFailedReason>::Count() { return 14; }

template <>
TC_API_EXPORT QuestFailedReason EnumUtils<QuestFailedReason>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return QUEST_ERR_NONE;
        case 1: return QUEST_ERR_FAILED_LOW_LEVEL;
        case 2: return QUEST_ERR_FAILED_WRONG_RACE;
        case 3: return QUEST_ERR_ALREADY_DONE;
        case 4: return QUEST_ERR_ONLY_ONE_TIMED;
        case 5: return QUEST_ERR_ALREADY_ON1;
        case 6: return QUEST_ERR_FAILED_EXPANSION;
        case 7: return QUEST_ERR_ALREADY_ON2;
        case 8: return QUEST_ERR_FAILED_MISSING_ITEMS;
        case 9: return QUEST_ERR_FAILED_NOT_ENOUGH_MONEY;
        case 10: return QUEST_ERR_FAILED_CAIS;
        case 11: return QUEST_ERR_ALREADY_DONE_DAILY;
        case 12: return QUEST_ERR_FAILED_SPELL;
        case 13: return QUEST_ERR_HAS_IN_PROGRESS;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<QuestFailedReason>::ToIndex(QuestFailedReason value)
{
    switch (value)
    {
        case QUEST_ERR_NONE: return 0;
        case QUEST_ERR_FAILED_LOW_LEVEL: return 1;
        case QUEST_ERR_FAILED_WRONG_RACE: return 2;
        case QUEST_ERR_ALREADY_DONE: return 3;
        case QUEST_ERR_ONLY_ONE_TIMED: return 4;
        case QUEST_ERR_ALREADY_ON1: return 5;
        case QUEST_ERR_FAILED_EXPANSION: return 6;
        case QUEST_ERR_ALREADY_ON2: return 7;
        case QUEST_ERR_FAILED_MISSING_ITEMS: return 8;
        case QUEST_ERR_FAILED_NOT_ENOUGH_MONEY: return 9;
        case QUEST_ERR_FAILED_CAIS: return 10;
        case QUEST_ERR_ALREADY_DONE_DAILY: return 11;
        case QUEST_ERR_FAILED_SPELL: return 12;
        case QUEST_ERR_HAS_IN_PROGRESS: return 13;
        default: throw std::out_of_range("value");
    }
}

/******************************************************************\
|* data for enum 'QuestPushReason' in 'QuestDef.h' auto-generated *|
\******************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<QuestPushReason>::ToString(QuestPushReason value)
{
    switch (value)
    {
        case QuestPushReason::Success: return { "Success", "Success", "\042Sharing quest with %s...\042" };
        case QuestPushReason::Invalid: return { "Invalid", "Invalid", "\042%s is not eligible for that quest\042" };
        case QuestPushReason::InvalidToRecipient: return { "InvalidToRecipient", "InvalidToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You are not eligible for that quest.\042" };
        case QuestPushReason::Accepted: return { "Accepted", "Accepted", "\042%s has accepted your quest\042" };
        case QuestPushReason::Declined: return { "Declined", "Declined", "\042%s has declined your quest\042" };
        case QuestPushReason::Busy: return { "Busy", "Busy", "\042%s is busy\042" };
        case QuestPushReason::Dead: return { "Dead", "Dead", "\042%s is dead.\042" };
        case QuestPushReason::DeadToRecipient: return { "DeadToRecipient", "DeadToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You are dead.\042" };
        case QuestPushReason::LogFull: return { "LogFull", "LogFull", "\042%s's quest log is full\042" };
        case QuestPushReason::LogFullToRecipient: return { "LogFullToRecipient", "LogFullToRecipient", "\042%s's attempt to share quest \042%s\042 failed. Your quest log is full.\042" };
        case QuestPushReason::OnQuest: return { "OnQuest", "OnQuest", "\042%s is already on that quest\042" };
        case QuestPushReason::OnQuestToRecipient: return { "OnQuestToRecipient", "OnQuestToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You are already on that quest.\042" };
        case QuestPushReason::AlreadyDone: return { "AlreadyDone", "AlreadyDone", "\042%s has completed that quest\042" };
        case QuestPushReason::AlreadyDoneToRecipient: return { "AlreadyDoneToRecipient", "AlreadyDoneToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You have completed that quest.\042" };
        case QuestPushReason::NotDaily: return { "NotDaily", "NotDaily", "\042That quest cannot be shared today\042" };
        case QuestPushReason::TimerExpired: return { "TimerExpired", "TimerExpired", "\042Quest sharing timer has expired\042" };
        case QuestPushReason::NotInParty: return { "NotInParty", "NotInParty", "\042You are not in a party\042" };
        case QuestPushReason::DifferentServerDaily: return { "DifferentServerDaily", "DifferentServerDaily", "\042%s is not eligible for that quest today\042" };
        case QuestPushReason::DifferentServerDailyToRecipient: return { "DifferentServerDailyToRecipient", "DifferentServerDailyToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You are not eligible for that quest today.\042" };
        case QuestPushReason::NotAllowed: return { "NotAllowed", "NotAllowed", "\042That quest cannot be shared\042" };
        case QuestPushReason::Prerequisite: return { "Prerequisite", "Prerequisite", "\042%s hasn't completed all of the prerequisite quests required for that quest.\042" };
        case QuestPushReason::PrerequisiteToRecipient: return { "PrerequisiteToRecipient", "PrerequisiteToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You must complete all of the prerequisite quests first.\042" };
        case QuestPushReason::LowLevel: return { "LowLevel", "LowLevel", "\042%s is too low level for that quest.\042" };
        case QuestPushReason::LowLevelToRecipient: return { "LowLevelToRecipient", "LowLevelToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You are too low level for that quest.\042" };
        case QuestPushReason::HighLevel: return { "HighLevel", "HighLevel", "\042%s is too high level for that quest.\042" };
        case QuestPushReason::HighLevelToRecipient: return { "HighLevelToRecipient", "HighLevelToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You are too high level for that quest.\042" };
        case QuestPushReason::Class: return { "Class", "Class", "\042%s is the wrong class for that quest.\042" };
        case QuestPushReason::ClassToRecipient: return { "ClassToRecipient", "ClassToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You are the wrong class for that quest.\042" };
        case QuestPushReason::Race: return { "Race", "Race", "\042%s is the wrong race for that quest.\042" };
        case QuestPushReason::RaceToRecipient: return { "RaceToRecipient", "RaceToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You are the wrong race for that quest.\042" };
        case QuestPushReason::LowFaction: return { "LowFaction", "LowFaction", "\042%s's reputation is too low for that quest.\042" };
        case QuestPushReason::LowFactionToRecipient: return { "LowFactionToRecipient", "LowFactionToRecipient", "\042%s's attempt to share quest \042%s\042 failed. Your reputation is too low for that quest.\042" };
        case QuestPushReason::HighFaction: return { "HighFaction", "HighFaction", "\042%s's reputation is too high for that quest.\042" };
        case QuestPushReason::HighFactionToRecipient: return { "HighFactionToRecipient", "HighFactionToRecipient", "\042%s's attempt to share quest \042%s\042 failed. Your reputation is too high for that quest.\042" };
        case QuestPushReason::Expansion: return { "Expansion", "Expansion", "\042%s doesn't own the required expansion for that quest.\042" };
        case QuestPushReason::ExpansionToRecipient: return { "ExpansionToRecipient", "ExpansionToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You do not own the required expansion for that quest.\042" };
        case QuestPushReason::NotGarrisonOwner: return { "NotGarrisonOwner", "NotGarrisonOwner", "\042%s must own a garrison to accept that quest.\042" };
        case QuestPushReason::NotGarrisonOwnerToRecipient: return { "NotGarrisonOwnerToRecipient", "NotGarrisonOwnerToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You must own a garrison to accept that quest.\042" };
        case QuestPushReason::WrongCovenant: return { "WrongCovenant", "WrongCovenant", "\042%s is in the wrong covenant for that quest.\042" };
        case QuestPushReason::WrongCovenantToRecipient: return { "WrongCovenantToRecipient", "WrongCovenantToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You are in the wrong covenant for that quest.\042" };
        case QuestPushReason::NewPlayerExperience: return { "NewPlayerExperience", "NewPlayerExperience", "\042%s must complete Exile's Reach to accept that quest.\042" };
        case QuestPushReason::NewPlayerExperienceToRecipient: return { "NewPlayerExperienceToRecipient", "NewPlayerExperienceToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You must complete Exile's Reach to accept that quest.\042" };
        case QuestPushReason::WrongFaction: return { "WrongFaction", "WrongFaction", "\042%s is the wrong faction for that quest.\042" };
        case QuestPushReason::WrongFactionToRecipient: return { "WrongFactionToRecipient", "WrongFactionToRecipient", "\042%s's attempt to share quest \042%s\042 failed. You are the wrong faction for that quest.\042" };
        case QuestPushReason::CrossFactionRestricted: return { "CrossFactionRestricted", "CrossFactionRestricted", "\042Quests can't be shared in cross-faction groups.\042" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<QuestPushReason>::Count() { return 45; }

template <>
TC_API_EXPORT QuestPushReason EnumUtils<QuestPushReason>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return QuestPushReason::Success;
        case 1: return QuestPushReason::Invalid;
        case 2: return QuestPushReason::InvalidToRecipient;
        case 3: return QuestPushReason::Accepted;
        case 4: return QuestPushReason::Declined;
        case 5: return QuestPushReason::Busy;
        case 6: return QuestPushReason::Dead;
        case 7: return QuestPushReason::DeadToRecipient;
        case 8: return QuestPushReason::LogFull;
        case 9: return QuestPushReason::LogFullToRecipient;
        case 10: return QuestPushReason::OnQuest;
        case 11: return QuestPushReason::OnQuestToRecipient;
        case 12: return QuestPushReason::AlreadyDone;
        case 13: return QuestPushReason::AlreadyDoneToRecipient;
        case 14: return QuestPushReason::NotDaily;
        case 15: return QuestPushReason::TimerExpired;
        case 16: return QuestPushReason::NotInParty;
        case 17: return QuestPushReason::DifferentServerDaily;
        case 18: return QuestPushReason::DifferentServerDailyToRecipient;
        case 19: return QuestPushReason::NotAllowed;
        case 20: return QuestPushReason::Prerequisite;
        case 21: return QuestPushReason::PrerequisiteToRecipient;
        case 22: return QuestPushReason::LowLevel;
        case 23: return QuestPushReason::LowLevelToRecipient;
        case 24: return QuestPushReason::HighLevel;
        case 25: return QuestPushReason::HighLevelToRecipient;
        case 26: return QuestPushReason::Class;
        case 27: return QuestPushReason::ClassToRecipient;
        case 28: return QuestPushReason::Race;
        case 29: return QuestPushReason::RaceToRecipient;
        case 30: return QuestPushReason::LowFaction;
        case 31: return QuestPushReason::LowFactionToRecipient;
        case 32: return QuestPushReason::HighFaction;
        case 33: return QuestPushReason::HighFactionToRecipient;
        case 34: return QuestPushReason::Expansion;
        case 35: return QuestPushReason::ExpansionToRecipient;
        case 36: return QuestPushReason::NotGarrisonOwner;
        case 37: return QuestPushReason::NotGarrisonOwnerToRecipient;
        case 38: return QuestPushReason::WrongCovenant;
        case 39: return QuestPushReason::WrongCovenantToRecipient;
        case 40: return QuestPushReason::NewPlayerExperience;
        case 41: return QuestPushReason::NewPlayerExperienceToRecipient;
        case 42: return QuestPushReason::WrongFaction;
        case 43: return QuestPushReason::WrongFactionToRecipient;
        case 44: return QuestPushReason::CrossFactionRestricted;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<QuestPushReason>::ToIndex(QuestPushReason value)
{
    switch (value)
    {
        case QuestPushReason::Success: return 0;
        case QuestPushReason::Invalid: return 1;
        case QuestPushReason::InvalidToRecipient: return 2;
        case QuestPushReason::Accepted: return 3;
        case QuestPushReason::Declined: return 4;
        case QuestPushReason::Busy: return 5;
        case QuestPushReason::Dead: return 6;
        case QuestPushReason::DeadToRecipient: return 7;
        case QuestPushReason::LogFull: return 8;
        case QuestPushReason::LogFullToRecipient: return 9;
        case QuestPushReason::OnQuest: return 10;
        case QuestPushReason::OnQuestToRecipient: return 11;
        case QuestPushReason::AlreadyDone: return 12;
        case QuestPushReason::AlreadyDoneToRecipient: return 13;
        case QuestPushReason::NotDaily: return 14;
        case QuestPushReason::TimerExpired: return 15;
        case QuestPushReason::NotInParty: return 16;
        case QuestPushReason::DifferentServerDaily: return 17;
        case QuestPushReason::DifferentServerDailyToRecipient: return 18;
        case QuestPushReason::NotAllowed: return 19;
        case QuestPushReason::Prerequisite: return 20;
        case QuestPushReason::PrerequisiteToRecipient: return 21;
        case QuestPushReason::LowLevel: return 22;
        case QuestPushReason::LowLevelToRecipient: return 23;
        case QuestPushReason::HighLevel: return 24;
        case QuestPushReason::HighLevelToRecipient: return 25;
        case QuestPushReason::Class: return 26;
        case QuestPushReason::ClassToRecipient: return 27;
        case QuestPushReason::Race: return 28;
        case QuestPushReason::RaceToRecipient: return 29;
        case QuestPushReason::LowFaction: return 30;
        case QuestPushReason::LowFactionToRecipient: return 31;
        case QuestPushReason::HighFaction: return 32;
        case QuestPushReason::HighFactionToRecipient: return 33;
        case QuestPushReason::Expansion: return 34;
        case QuestPushReason::ExpansionToRecipient: return 35;
        case QuestPushReason::NotGarrisonOwner: return 36;
        case QuestPushReason::NotGarrisonOwnerToRecipient: return 37;
        case QuestPushReason::WrongCovenant: return 38;
        case QuestPushReason::WrongCovenantToRecipient: return 39;
        case QuestPushReason::NewPlayerExperience: return 40;
        case QuestPushReason::NewPlayerExperienceToRecipient: return 41;
        case QuestPushReason::WrongFaction: return 42;
        case QuestPushReason::WrongFactionToRecipient: return 43;
        case QuestPushReason::CrossFactionRestricted: return 44;
        default: throw std::out_of_range("value");
    }
}
}
