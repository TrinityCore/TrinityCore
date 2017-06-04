/*
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
 * This program is free software licensed under GPL version 3
 * Please see the included DOCS/LICENSE.md for more information
 */

#include "Hooks.h"
#include "HookHelpers.h"
#include "LuaEngine.h"
#include "BindingMap.h"
#include "ElunaIncludes.h"
#include "ElunaTemplate.h"

using namespace Hooks;

#define START_HOOK(EVENT) \
    if (!IsEnabled())\
        return;\
    auto key = EventKey<PlayerEvents>(EVENT);\
    if (!PlayerEventBindings->HasBindingsFor(key))\
        return;\
    LOCK_ELUNA

#define START_HOOK_WITH_RETVAL(EVENT, RETVAL) \
    if (!IsEnabled())\
        return RETVAL;\
    auto key = EventKey<PlayerEvents>(EVENT);\
    if (!PlayerEventBindings->HasBindingsFor(key))\
        return RETVAL;\
    LOCK_ELUNA

void Eluna::OnLearnTalents(Player* pPlayer, uint32 talentId, uint32 talentRank, uint32 spellid)
{
    START_HOOK(PLAYER_EVENT_ON_LEARN_TALENTS);
    Push(pPlayer);
    Push(talentId);
    Push(talentRank);
    Push(spellid);
    CallAllFunctions(PlayerEventBindings, key);
}

bool Eluna::OnCommand(Player* player, const char* text)
{
    // If from console, player is NULL
    if (!player || player->GetSession()->GetSecurity() >= SEC_ADMINISTRATOR)
    {
        std::string reload = text;
        std::transform(reload.begin(), reload.end(), reload.begin(), ::tolower);
        if (reload.find("reload eluna") == 0)
        {
            ReloadEluna();
            return false;
        }
    }

    START_HOOK_WITH_RETVAL(PLAYER_EVENT_ON_COMMAND, true);
    Push(player);
    Push(text);
    return CallAllFunctionsBool(PlayerEventBindings, key, true);
}

void Eluna::OnLootItem(Player* pPlayer, Item* pItem, uint32 count, uint64 guid)
{
    START_HOOK(PLAYER_EVENT_ON_LOOT_ITEM);
    Push(pPlayer);
    Push(pItem);
    Push(count);
    Push(guid);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnLootMoney(Player* pPlayer, uint32 amount)
{
    START_HOOK(PLAYER_EVENT_ON_LOOT_MONEY);
    Push(pPlayer);
    Push(amount);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnFirstLogin(Player* pPlayer)
{
    START_HOOK(PLAYER_EVENT_ON_FIRST_LOGIN);
    Push(pPlayer);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnRepop(Player* pPlayer)
{
    START_HOOK(PLAYER_EVENT_ON_REPOP);
    Push(pPlayer);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnResurrect(Player* pPlayer)
{
    START_HOOK(PLAYER_EVENT_ON_RESURRECT);
    Push(pPlayer);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnQuestAbandon(Player* pPlayer, uint32 questId)
{
    START_HOOK(PLAYER_EVENT_ON_QUEST_ABANDON);
    Push(pPlayer);
    Push(questId);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnEquip(Player* pPlayer, Item* pItem, uint8 bag, uint8 slot)
{
    START_HOOK(PLAYER_EVENT_ON_EQUIP);
    Push(pPlayer);
    Push(pItem);
    Push(bag);
    Push(slot);
    CallAllFunctions(PlayerEventBindings, key);
}

InventoryResult Eluna::OnCanUseItem(const Player* pPlayer, uint32 itemEntry)
{
    START_HOOK_WITH_RETVAL(PLAYER_EVENT_ON_CAN_USE_ITEM, EQUIP_ERR_OK);
    InventoryResult result = EQUIP_ERR_OK;
    Push(pPlayer);
    Push(itemEntry);
    int n = SetupStack(PlayerEventBindings, key, 2);

    while (n > 0)
    {
        int r = CallOneFunction(n--, 2, 1);

        if (lua_isnumber(L, r))
            result = (InventoryResult)CHECKVAL<uint32>(L, r);

        lua_pop(L, 1);
    }

    CleanUpStack(2);
    return result;
}
void Eluna::OnPlayerEnterCombat(Player* pPlayer, Unit* pEnemy)
{
    START_HOOK(PLAYER_EVENT_ON_ENTER_COMBAT);
    Push(pPlayer);
    Push(pEnemy);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnPlayerLeaveCombat(Player* pPlayer)
{
    START_HOOK(PLAYER_EVENT_ON_LEAVE_COMBAT);
    Push(pPlayer);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnPVPKill(Player* pKiller, Player* pKilled)
{
    START_HOOK(PLAYER_EVENT_ON_KILL_PLAYER);
    Push(pKiller);
    Push(pKilled);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnCreatureKill(Player* pKiller, Creature* pKilled)
{
    START_HOOK(PLAYER_EVENT_ON_KILL_CREATURE);
    Push(pKiller);
    Push(pKilled);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnPlayerKilledByCreature(Creature* pKiller, Player* pKilled)
{
    START_HOOK(PLAYER_EVENT_ON_KILLED_BY_CREATURE);
    Push(pKiller);
    Push(pKilled);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnLevelChanged(Player* pPlayer, uint8 oldLevel)
{
    START_HOOK(PLAYER_EVENT_ON_LEVEL_CHANGE);
    Push(pPlayer);
    Push(oldLevel);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnFreeTalentPointsChanged(Player* pPlayer, uint32 newPoints)
{
    START_HOOK(PLAYER_EVENT_ON_TALENTS_CHANGE);
    Push(pPlayer);
    Push(newPoints);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnTalentsReset(Player* pPlayer, bool noCost)
{
    START_HOOK(PLAYER_EVENT_ON_TALENTS_RESET);
    Push(pPlayer);
    Push(noCost);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnMoneyChanged(Player* pPlayer, int32& amount)
{
    START_HOOK(PLAYER_EVENT_ON_MONEY_CHANGE);
    Push(pPlayer);
    Push(amount);
    int amountIndex = lua_gettop(L);
    int n = SetupStack(PlayerEventBindings, key, 2);

    while (n > 0)
    {
        int r = CallOneFunction(n--, 2, 1);

        if (lua_isnumber(L, r))
        {
            amount = CHECKVAL<int32>(L, r);
            // Update the stack for subsequent calls.
            ReplaceArgument(amount, amountIndex);
        }

        lua_pop(L, 1);
    }

    CleanUpStack(2);
}

void Eluna::OnGiveXP(Player* pPlayer, uint32& amount, Unit* pVictim)
{
    START_HOOK(PLAYER_EVENT_ON_GIVE_XP);
    Push(pPlayer);
    Push(amount);
    Push(pVictim);
    int amountIndex = lua_gettop(L) - 1;
    int n = SetupStack(PlayerEventBindings, key, 3);

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

void Eluna::OnReputationChange(Player* pPlayer, uint32 factionID, int32& standing, bool incremental)
{
    START_HOOK(PLAYER_EVENT_ON_REPUTATION_CHANGE);
    Push(pPlayer);
    Push(factionID);
    Push(standing);
    Push(incremental);
    int standingIndex = lua_gettop(L) - 1;
    int n = SetupStack(PlayerEventBindings, key, 4);

    while (n > 0)
    {
        int r = CallOneFunction(n--, 4, 1);

        if (lua_isnumber(L, r))
        {
            standing = CHECKVAL<int32>(L, r);
            // Update the stack for subsequent calls.
            ReplaceArgument(standing, standingIndex);
        }

        lua_pop(L, 1);
    }

    CleanUpStack(4);
}

void Eluna::OnDuelRequest(Player* pTarget, Player* pChallenger)
{
    START_HOOK(PLAYER_EVENT_ON_DUEL_REQUEST);
    Push(pTarget);
    Push(pChallenger);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnDuelStart(Player* pStarter, Player* pChallenger)
{
    START_HOOK(PLAYER_EVENT_ON_DUEL_START);
    Push(pStarter);
    Push(pChallenger);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnDuelEnd(Player* pWinner, Player* pLoser, DuelCompleteType type)
{
    START_HOOK(PLAYER_EVENT_ON_DUEL_END);
    Push(pWinner);
    Push(pLoser);
    Push(type);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnEmote(Player* pPlayer, uint32 emote)
{
    START_HOOK(PLAYER_EVENT_ON_EMOTE);
    Push(pPlayer);
    Push(emote);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnTextEmote(Player* pPlayer, uint32 textEmote, uint32 emoteNum, uint64 guid)
{
    START_HOOK(PLAYER_EVENT_ON_TEXT_EMOTE);
    Push(pPlayer);
    Push(textEmote);
    Push(emoteNum);
    Push(guid);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnSpellCast(Player* pPlayer, Spell* pSpell, bool skipCheck)
{
    START_HOOK(PLAYER_EVENT_ON_SPELL_CAST);
    Push(pPlayer);
    Push(pSpell);
    Push(skipCheck);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnLogin(Player* pPlayer)
{
    START_HOOK(PLAYER_EVENT_ON_LOGIN);
    Push(pPlayer);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnLogout(Player* pPlayer)
{
    START_HOOK(PLAYER_EVENT_ON_LOGOUT);
    Push(pPlayer);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnCreate(Player* pPlayer)
{
    START_HOOK(PLAYER_EVENT_ON_CHARACTER_CREATE);
    Push(pPlayer);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnDelete(uint32 guidlow)
{
    START_HOOK(PLAYER_EVENT_ON_CHARACTER_DELETE);
    Push(guidlow);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnSave(Player* pPlayer)
{
    START_HOOK(PLAYER_EVENT_ON_SAVE);
    Push(pPlayer);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnBindToInstance(Player* pPlayer, Difficulty difficulty, uint32 mapid, bool permanent)
{
    START_HOOK(PLAYER_EVENT_ON_BIND_TO_INSTANCE);
    Push(pPlayer);
    Push(difficulty);
    Push(mapid);
    Push(permanent);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnUpdateZone(Player* pPlayer, uint32 newZone, uint32 newArea)
{
    START_HOOK(PLAYER_EVENT_ON_UPDATE_ZONE);
    Push(pPlayer);
    Push(newZone);
    Push(newArea);
    CallAllFunctions(PlayerEventBindings, key);
}

void Eluna::OnMapChanged(Player* player)
{
    START_HOOK(PLAYER_EVENT_ON_MAP_CHANGE);
    Push(player);
    CallAllFunctions(PlayerEventBindings, key);
}

bool Eluna::OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg)
{
    if (lang == LANG_ADDON)
        return OnAddonMessage(pPlayer, type, msg, NULL, NULL, NULL, NULL);

    START_HOOK_WITH_RETVAL(PLAYER_EVENT_ON_CHAT, true);
    bool result = true;
    Push(pPlayer);
    Push(msg);
    Push(type);
    Push(lang);
    int n = SetupStack(PlayerEventBindings, key, 4);

    while (n > 0)
    {
        int r = CallOneFunction(n--, 4, 2);

        if (lua_isboolean(L, r + 0) && !lua_toboolean(L, r + 0))
            result = false;

        if (lua_isstring(L, r + 1))
            msg = std::string(lua_tostring(L, r + 1));

        lua_pop(L, 2);
    }

    CleanUpStack(4);
    return result;
}

bool Eluna::OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Group* pGroup)
{
    if (lang == LANG_ADDON)
        return OnAddonMessage(pPlayer, type, msg, NULL, NULL, pGroup, NULL);

    START_HOOK_WITH_RETVAL(PLAYER_EVENT_ON_GROUP_CHAT, true);
    bool result = true;
    Push(pPlayer);
    Push(msg);
    Push(type);
    Push(lang);
    Push(pGroup);
    int n = SetupStack(PlayerEventBindings, key, 5);

    while (n > 0)
    {
        int r = CallOneFunction(n--, 5, 2);

        if (lua_isboolean(L, r + 0) && !lua_toboolean(L, r + 0))
            result = false;

        if (lua_isstring(L, r + 1))
            msg = std::string(lua_tostring(L, r + 1));

        lua_pop(L, 2);
    }

    CleanUpStack(5);
    return result;
}

bool Eluna::OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Guild* pGuild)
{
    if (lang == LANG_ADDON)
        return OnAddonMessage(pPlayer, type, msg, NULL, pGuild, NULL, NULL);

    START_HOOK_WITH_RETVAL(PLAYER_EVENT_ON_GUILD_CHAT, true);
    bool result = true;
    Push(pPlayer);
    Push(msg);
    Push(type);
    Push(lang);
    Push(pGuild);
    int n = SetupStack(PlayerEventBindings, key, 5);

    while (n > 0)
    {
        int r = CallOneFunction(n--, 5, 2);

        if (lua_isboolean(L, r + 0) && !lua_toboolean(L, r + 0))
            result = false;

        if (lua_isstring(L, r + 1))
            msg = std::string(lua_tostring(L, r + 1));

        lua_pop(L, 2);
    }

    CleanUpStack(5);
    return result;
}

bool Eluna::OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Channel* pChannel)
{
    if (lang == LANG_ADDON)
        return OnAddonMessage(pPlayer, type, msg, NULL, NULL, NULL, pChannel);

    START_HOOK_WITH_RETVAL(PLAYER_EVENT_ON_CHANNEL_CHAT, true);
    bool result = true;
    Push(pPlayer);
    Push(msg);
    Push(type);
    Push(lang);
    Push(pChannel->GetChannelId());
    int n = SetupStack(PlayerEventBindings, key, 5);

    while (n > 0)
    {
        int r = CallOneFunction(n--, 5, 2);

        if (lua_isboolean(L, r + 0) && !lua_toboolean(L, r + 0))
            result = false;

        if (lua_isstring(L, r + 1))
            msg = std::string(lua_tostring(L, r + 1));

        lua_pop(L, 2);
    }

    CleanUpStack(5);
    return result;
}

bool Eluna::OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Player* pReceiver)
{
    if (lang == LANG_ADDON)
        return OnAddonMessage(pPlayer, type, msg, pReceiver, NULL, NULL, NULL);

    START_HOOK_WITH_RETVAL(PLAYER_EVENT_ON_WHISPER, true);
    bool result = true;
    Push(pPlayer);
    Push(msg);
    Push(type);
    Push(lang);
    Push(pReceiver);
    int n = SetupStack(PlayerEventBindings, key, 5);

    while (n > 0)
    {
        int r = CallOneFunction(n--, 5, 2);

        if (lua_isboolean(L, r + 0) && !lua_toboolean(L, r + 0))
            result = false;

        if (lua_isstring(L, r + 1))
            msg = std::string(lua_tostring(L, r + 1));

        lua_pop(L, 2);
    }

    CleanUpStack(5);
    return result;
}
