/*
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
 * This program is free software licensed under GPL version 3
 * Please see the included DOCS/LICENSE.md for more information
 */

#include "Hooks.h"
#include "HookHelpers.h"
#include "LuaEngine.h"
#include "BindingMap.h"
#include "ElunaTemplate.h"

using namespace Hooks;

#define START_HOOK(EVENT) \
    if (!IsEnabled())\
        return;\
    auto key = EventKey<GuildEvents>(EVENT);\
    if (!GuildEventBindings->HasBindingsFor(key))\
        return;\
    LOCK_ELUNA

void Eluna::OnAddMember(Guild* guild, Player* player, uint32 plRank)
{
    START_HOOK(GUILD_EVENT_ON_ADD_MEMBER);
    Push(guild);
    Push(player);
    Push(plRank);
    CallAllFunctions(GuildEventBindings, key);
}

void Eluna::OnRemoveMember(Guild* guild, Player* player, bool isDisbanding)
{
    START_HOOK(GUILD_EVENT_ON_REMOVE_MEMBER);
    Push(guild);
    Push(player);
    Push(isDisbanding);
    CallAllFunctions(GuildEventBindings, key);
}

void Eluna::OnMOTDChanged(Guild* guild, const std::string& newMotd)
{
    START_HOOK(GUILD_EVENT_ON_MOTD_CHANGE);
    Push(guild);
    Push(newMotd);
    CallAllFunctions(GuildEventBindings, key);
}

void Eluna::OnInfoChanged(Guild* guild, const std::string& newInfo)
{
    START_HOOK(GUILD_EVENT_ON_INFO_CHANGE);
    Push(guild);
    Push(newInfo);
    CallAllFunctions(GuildEventBindings, key);
}

void Eluna::OnCreate(Guild* guild, Player* leader, const std::string& name)
{
    START_HOOK(GUILD_EVENT_ON_CREATE);
    Push(guild);
    Push(leader);
    Push(name);
    CallAllFunctions(GuildEventBindings, key);
}

void Eluna::OnDisband(Guild* guild)
{
    START_HOOK(GUILD_EVENT_ON_DISBAND);
    Push(guild);
    CallAllFunctions(GuildEventBindings, key);
}

void Eluna::OnMemberWitdrawMoney(Guild* guild, Player* player, uint32& amount, bool isRepair)
{
    START_HOOK(GUILD_EVENT_ON_MONEY_WITHDRAW);
    Push(guild);
    Push(player);
    Push(amount);
    Push(isRepair); // isRepair not a part of Mangos, implement?
    int amountIndex = lua_gettop(L) - 1;
    int n = SetupStack(GuildEventBindings, key, 4);

    while (n > 0)
    {
        int r = CallOneFunction(n--, 4, 1);

        if (lua_isnumber(L, r))
        {
            amount = CHECKVAL<uint32>(L, r);
            // Update the stack for subsequent calls.
            ReplaceArgument(amount, amountIndex);
        }

        lua_pop(L, 1);
    }

    CleanUpStack(4);
}

void Eluna::OnMemberDepositMoney(Guild* guild, Player* player, uint32& amount)
{
    START_HOOK(GUILD_EVENT_ON_MONEY_DEPOSIT);
    Push(guild);
    Push(player);
    Push(amount);
    int amountIndex = lua_gettop(L);
    int n = SetupStack(GuildEventBindings, key, 3);

    while (n > 0)
    {
        int r = CallOneFunction(n--, 3, 1);

        if (lua_isnumber(L, r))
        {
            amount = CHECKVAL<uint32>(L, r);
            // Update the stack for subsequent calls.
            ReplaceArgument(amount, amountIndex);
        }

        lua_pop(L, 1);
    }

    CleanUpStack(3);
}

void Eluna::OnItemMove(Guild* guild, Player* player, Item* pItem, bool isSrcBank, uint8 srcContainer, uint8 srcSlotId,
    bool isDestBank, uint8 destContainer, uint8 destSlotId)
{
    START_HOOK(GUILD_EVENT_ON_ITEM_MOVE);
    Push(guild);
    Push(player);
    Push(pItem);
    Push(isSrcBank);
    Push(srcContainer);
    Push(srcSlotId);
    Push(isDestBank);
    Push(destContainer);
    Push(destSlotId);
    CallAllFunctions(GuildEventBindings, key);
}

void Eluna::OnEvent(Guild* guild, uint8 eventType, uint32 playerGuid1, uint32 playerGuid2, uint8 newRank)
{
    START_HOOK(GUILD_EVENT_ON_EVENT);
    Push(guild);
    Push(eventType);
    Push(playerGuid1);
    Push(playerGuid2);
    Push(newRank);
    CallAllFunctions(GuildEventBindings, key);
}

void Eluna::OnBankEvent(Guild* guild, uint8 eventType, uint8 tabId, uint32 playerGuid, uint32 itemOrMoney, uint16 itemStackCount, uint8 destTabId)
{
    START_HOOK(GUILD_EVENT_ON_BANK_EVENT);
    Push(guild);
    Push(eventType);
    Push(tabId);
    Push(playerGuid);
    Push(itemOrMoney);
    Push(itemStackCount);
    Push(destTabId);
    CallAllFunctions(GuildEventBindings, key);
}
