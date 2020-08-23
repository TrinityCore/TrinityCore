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

/*********************************************************************\
|* data for enum 'QuestShareMessages' in 'QuestDef.h' auto-generated *|
\*********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<QuestShareMessages>::ToString(QuestShareMessages value)
{
    switch (value)
    {
        case QUEST_PARTY_MSG_SHARING_QUEST: return { "QUEST_PARTY_MSG_SHARING_QUEST", "QUEST_PARTY_MSG_SHARING_QUEST", "" };
        case QUEST_PARTY_MSG_CANT_TAKE_QUEST: return { "QUEST_PARTY_MSG_CANT_TAKE_QUEST", "QUEST_PARTY_MSG_CANT_TAKE_QUEST", "" };
        case QUEST_PARTY_MSG_ACCEPT_QUEST: return { "QUEST_PARTY_MSG_ACCEPT_QUEST", "QUEST_PARTY_MSG_ACCEPT_QUEST", "" };
        case QUEST_PARTY_MSG_DECLINE_QUEST: return { "QUEST_PARTY_MSG_DECLINE_QUEST", "QUEST_PARTY_MSG_DECLINE_QUEST", "" };
        case QUEST_PARTY_MSG_BUSY: return { "QUEST_PARTY_MSG_BUSY", "QUEST_PARTY_MSG_BUSY", "" };
        case QUEST_PARTY_MSG_LOG_FULL: return { "QUEST_PARTY_MSG_LOG_FULL", "QUEST_PARTY_MSG_LOG_FULL", "" };
        case QUEST_PARTY_MSG_HAVE_QUEST: return { "QUEST_PARTY_MSG_HAVE_QUEST", "QUEST_PARTY_MSG_HAVE_QUEST", "" };
        case QUEST_PARTY_MSG_FINISH_QUEST: return { "QUEST_PARTY_MSG_FINISH_QUEST", "QUEST_PARTY_MSG_FINISH_QUEST", "" };
        case QUEST_PARTY_MSG_CANT_BE_SHARED_TODAY: return { "QUEST_PARTY_MSG_CANT_BE_SHARED_TODAY", "QUEST_PARTY_MSG_CANT_BE_SHARED_TODAY", "" };
        case QUEST_PARTY_MSG_SHARING_TIMER_EXPIRED: return { "QUEST_PARTY_MSG_SHARING_TIMER_EXPIRED", "QUEST_PARTY_MSG_SHARING_TIMER_EXPIRED", "" };
        case QUEST_PARTY_MSG_NOT_IN_PARTY: return { "QUEST_PARTY_MSG_NOT_IN_PARTY", "QUEST_PARTY_MSG_NOT_IN_PARTY", "" };
        case QUEST_PARTY_MSG_NOT_ELIGIBLE_TODAY: return { "QUEST_PARTY_MSG_NOT_ELIGIBLE_TODAY", "QUEST_PARTY_MSG_NOT_ELIGIBLE_TODAY", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<QuestShareMessages>::Count() { return 12; }

template <>
TC_API_EXPORT QuestShareMessages EnumUtils<QuestShareMessages>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return QUEST_PARTY_MSG_SHARING_QUEST;
        case 1: return QUEST_PARTY_MSG_CANT_TAKE_QUEST;
        case 2: return QUEST_PARTY_MSG_ACCEPT_QUEST;
        case 3: return QUEST_PARTY_MSG_DECLINE_QUEST;
        case 4: return QUEST_PARTY_MSG_BUSY;
        case 5: return QUEST_PARTY_MSG_LOG_FULL;
        case 6: return QUEST_PARTY_MSG_HAVE_QUEST;
        case 7: return QUEST_PARTY_MSG_FINISH_QUEST;
        case 8: return QUEST_PARTY_MSG_CANT_BE_SHARED_TODAY;
        case 9: return QUEST_PARTY_MSG_SHARING_TIMER_EXPIRED;
        case 10: return QUEST_PARTY_MSG_NOT_IN_PARTY;
        case 11: return QUEST_PARTY_MSG_NOT_ELIGIBLE_TODAY;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<QuestShareMessages>::ToIndex(QuestShareMessages value)
{
    switch (value)
    {
        case QUEST_PARTY_MSG_SHARING_QUEST: return 0;
        case QUEST_PARTY_MSG_CANT_TAKE_QUEST: return 1;
        case QUEST_PARTY_MSG_ACCEPT_QUEST: return 2;
        case QUEST_PARTY_MSG_DECLINE_QUEST: return 3;
        case QUEST_PARTY_MSG_BUSY: return 4;
        case QUEST_PARTY_MSG_LOG_FULL: return 5;
        case QUEST_PARTY_MSG_HAVE_QUEST: return 6;
        case QUEST_PARTY_MSG_FINISH_QUEST: return 7;
        case QUEST_PARTY_MSG_CANT_BE_SHARED_TODAY: return 8;
        case QUEST_PARTY_MSG_SHARING_TIMER_EXPIRED: return 9;
        case QUEST_PARTY_MSG_NOT_IN_PARTY: return 10;
        case QUEST_PARTY_MSG_NOT_ELIGIBLE_TODAY: return 11;
        default: throw std::out_of_range("value");
    }
}
}
