/*
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <memory.h>
#include "Object.h"
#include "TSIncludes.h"
#include "TSQuest.h"

TSQuest::TSQuest(Quest const* quest)
{
    this->quest = quest;
}

TSQuest::TSQuest()
{
    this->quest = nullptr;
}

/**
 * Returns 'true' if the [Quest] has the specified flag, false otherwise.
 * Below flags are based off of 3.3.5a. Subject to change.
 *
 * <pre>
 * enum QuestFlags
 * {
 *     // Flags used at server and sent to client
 *     QUEST_FLAGS_NONE                    = 0x0,
 *     QUEST_FLAGS_STAY_ALIVE              = 0x1,       // Not used currently
 *     QUEST_FLAGS_PARTY_ACCEPT            = 0x2,       // Not used currently. If player in party, all players that can accept this quest will receive confirmation box to accept quest CMSG_QUEST_CONFIRM_ACCEPT/SMSG_QUEST_CONFIRM_ACCEPT
 *     QUEST_FLAGS_EXPLORATION             = 0x4,       // Not used currently
 *     QUEST_FLAGS_SHARABLE                = 0x8,       // Can be shared: Player::CanShareQuest()
 *     QUEST_FLAGS_HAS_CONDITION           = 0x10,      // Not used currently
 *     QUEST_FLAGS_HIDE_REWARD_POI         = 0x20,      // Not used currently: Unsure of content
 *     QUEST_FLAGS_RAID                    = 0x40,      // Not used currently
 *     QUEST_FLAGS_TBC                     = 0x80,      // Not used currently: Available if TBC expansion enabled only
 *     QUEST_FLAGS_NO_MONEY_FROM_XP        = 0x100,     // Not used currently: Experience is not converted to gold at max level
bool TSQuest::log() 
 *     QUEST_FLAGS_TRACKING                = 0x400,     // These quests are automatically rewarded on quest complete and they will never appear in quest log client side.
 *     QUEST_FLAGS_DEPRECATE_REPUTATION    = 0x800,     // Not used currently
 *     QUEST_FLAGS_DAILY                   = 0x1000,    // Used to know quest is Daily one
 *     QUEST_FLAGS_FLAGS_PVP               = 0x2000,    // Having this quest in log forces PvP flag
 *     QUEST_FLAGS_UNAVAILABLE             = 0x4000,    // Used on quests that are not generically available
 *     QUEST_FLAGS_WEEKLY                  = 0x8000,
 *     QUEST_FLAGS_AUTOCOMPLETE            = 0x10000,   // auto complete
 *     QUEST_FLAGS_DISPLAY_ITEM_IN_TRACKER = 0x20000,   // Displays usable item in quest tracker
 *     QUEST_FLAGS_OBJ_TEXT                = 0x40000,   // use Objective text as Complete text
 *     QUEST_FLAGS_AUTO_ACCEPT             = 0x80000,   // The client recognizes this flag as auto-accept. However, NONE of the current quests (3.3.5a) have this flag. Maybe blizz used to use it, or will use it in the future.
 *
 *     // ... 4.x added flags up to 0x80000000 - all unknown for now
 * </pre>
 *
 * @param [QuestFlags] flag : all available flags can be seen above
 * @return bool hasFlag
 */
bool TSQuest::HasFlag(uint32 flag) 
{
#if defined TRINITY || AZEROTHCORE
    return quest->HasFlag(flag);
#else
    return quest->HasQuestFlag((QuestFlags)flag);
#endif
}
    
#ifndef CLASSIC
/**
 * Returns 'true' if the [Quest] is a daily quest, false otherwise.
 *
 * @return bool isDaily
 */
bool TSQuest::IsDaily() 
{
    return quest->IsDaily();
}
#endif
    
/**
 * Returns 'true' if the [Quest] is repeatable, false otherwise.
 *
 * @return bool isRepeatable
 */
bool TSQuest::IsRepeatable() 
{
    return quest->IsRepeatable();
}
    
/**
 * Returns entry ID of the [Quest].
 *
 * @return uint32 entryId
 */
uint32 TSQuest::GetId() 
{
    return quest->GetQuestId();
}
    
/**
 * Returns the [Quest]'s level.
 *
 * @return uint32 level
 */
uint32 TSQuest::GetLevel() 
{
    return quest->GetQuestLevel();
}
    
/**
 * Returns the minimum level required to pick up the [Quest].
 *
 * @return uint32 minLevel
 */
uint32 TSQuest::GetMinLevel() 
{
    return quest->GetMinLevel();
}
    
/**
 * Returns the next [Quest] entry ID.
 *
 * @return int32 entryId
 */
int32 TSQuest::GetNextQuestId() 
{
    return quest->GetNextQuestId();
}
    
/**
 * Returns the previous [Quest] entry ID.
 *
 * @return int32 entryId
 */
int32 TSQuest::GetPrevQuestId() 
{
    return quest->GetPrevQuestId();
}
    
/**
 * Returns the next [Quest] entry ID in the specific [Quest] chain.
 *
 * @return int32 entryId
 */
int32 TSQuest::GetNextQuestInChain() 
{
    return quest->GetNextQuestInChain();
}
    
/**
 * Returns the [Quest]'s flags.
 *
 * @return [QuestFlags] flags
 */
uint32 TSQuest::GetFlags() 
{
#if defined TRINITY || AZEROTHCORE
    return quest->GetFlags();
#else
    return quest->GetQuestFlags();
#endif
}
    
/**
 * Returns the [Quest]'s type.
 *
 * TODO: Document types available.
 *
 * @return uint32 type
 */
uint32 TSQuest::GetType() 
{
    return quest->GetType();
}
    
/*int TSQuest::GetMaxLevel(lua_State* L, Quest* quest)
{
    return quest->GetMaxLevel();
}*/
