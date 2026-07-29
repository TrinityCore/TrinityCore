/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "WorldSession.h"   // must come first for stupid clang
#include "ScriptMgr.h"
#include <algorithm>
#include <mutex>
#include <thread>
#include "Battleground.h"
#include "Chat.h"
#include "ChatPackets.h"
#include "Channel.h"
#include "ChannelMgr.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "GameTime.h"
#include "Log.h"
#include "World.h"
#include "Creature.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Language.h"
#include "SharedDefines.h"
#include "Weather.h"
#include "WowTime.h"

#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"
#include "Followship_bots_chat_handler.h"
#include "Followship_bots_mail_handler.h"
#include "GenAI_mail_prompts.h"

#include "Followship_bots_ai_base.h"
#include "Followship_bots_config.h"

#include "GenAI_client.h"
#include "GenAI_channel_prompts.h"

// ------------------------------------------------------------------
// Helper: gold allowance (main-thread only - uses urand)
// ------------------------------------------------------------------

static bool ShouldAllowGold(FSB_BaseAI const* ai)
{
    if (!FollowshipBotsConfig::configFSBAllowGold)
        return false;

    uint32 goldCount = ai->botChatData.goldGivenCount;
    uint32 goldNow = getMSTime();
    uint32 chance = (goldCount >= 5) ? 0u : static_cast<uint32>(std::max(0, 10 - static_cast<int32>(goldCount) * 2));
    bool onCooldown = goldCount > 0 && (goldNow < ai->botChatData.lastGoldGiveTime + 3600000u);
    return !onCooldown && chance > 0 && urand(0, 99) < chance;
}

// ------------------------------------------------------------------
// FSBChatMgr singleton
// ------------------------------------------------------------------

FSBChatMgr* FSBChatMgr::Get()
{
    static FSBChatMgr instance;
    return &instance;
}

void FSBChatMgr::RegisterActiveBot(Creature* bot)
{
    if (!bot)
        return;
    std::lock_guard<std::mutex> lock(_activeBotsMutex);
    _activeBots[bot->GetGUID()] = bot;
}

void FSBChatMgr::UnregisterActiveBot(Creature* bot)
{
    if (!bot)
        return;
    std::lock_guard<std::mutex> lock(_activeBotsMutex);
    _activeBots.erase(bot->GetGUID());
}

std::vector<Creature*> FSBChatMgr::GetActiveBots()
{
    std::lock_guard<std::mutex> lock(_activeBotsMutex);
    std::vector<Creature*> result;
    result.reserve(_activeBots.size());

    for (auto it = _activeBots.begin(); it != _activeBots.end();)
    {
        Creature* bot = it->second;
        if (!bot || !bot->IsInWorld())
        {
            it = _activeBots.erase(it);
            continue;
        }
        result.push_back(bot);
        ++it;
    }

    return result;
}

std::string FSBChatMgr::SanitizeBotName(std::string const& name)
{
    std::string result;
    result.reserve(name.length());
    for (char c : name)
    {
        if (c == ' ' || c == '-' || c == '\'')
            continue;
        result += c;
    }
    return result;
}

Creature* FSBChatMgr::FindActiveBotByName(std::string const& name) const
{
    std::lock_guard<std::mutex> lock(_activeBotsMutex);
    // Exact match first
    for (auto const& pair : _activeBots)
    {
        Creature* bot = pair.second;
        if (bot && bot->IsInWorld() && bot->GetName() == name)
            return bot;
    }

    // Fall back to sanitized name match (case-insensitive)
    std::string searchSanitized = SanitizeBotName(name);
    if (searchSanitized.empty())
        return nullptr;

    std::wstring searchWide;
    if (!Utf8toWStr(searchSanitized, searchWide))
        return nullptr;
    wstrToLower(searchWide);

    for (auto const& pair : _activeBots)
    {
        Creature* bot = pair.second;
        if (!bot || !bot->IsInWorld())
            continue;

        std::string botSanitized = SanitizeBotName(bot->GetName());
        std::wstring botWide;
        if (!Utf8toWStr(botSanitized, botWide))
            continue;
        wstrToLower(botWide);

        if (botWide == searchWide)
            return bot;
    }
    return nullptr;
}

Creature* FSBChatMgr::FindActiveBotByGuid(ObjectGuid guid) const
{
    std::lock_guard<std::mutex> lock(_activeBotsMutex);
    auto it = _activeBots.find(guid);
    if (it != _activeBots.end())
    {
        Creature* bot = it->second;
        if (bot && bot->IsInWorld())
            return bot;
    }
    return nullptr;
}

void FSBChatMgr::JoinBotChannels(Creature* bot)
{
    if (!bot || !bot->IsBot())
        return;

    FSB_BaseAI* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
    if (!ai || ai->botHired)
        return;

    Team botTeam = FSBUtils::GetTeamFromFSBRace(FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()));
    ChannelMgr* mgr = ChannelMgr::ForTeam(botTeam);
    if (!mgr)
        return;

    uint32 zoneId = bot->GetZoneId();
    AreaTableEntry const* zone = sAreaTableStore.LookupEntry(zoneId);
    if (!zone)
        return;

    bool anyJoined = false;
    if (Channel* general = mgr->GetChannel(1, "", nullptr, false, zone))
    {
        general->JoinBot(bot);
        anyJoined = true;
    }

    if (Channel* trade = mgr->GetChannel(2, "", nullptr, false, zone))
    {
        trade->JoinBot(bot);
        anyJoined = true;
    }

    if (Channel* localDef = mgr->GetChannel(22, "", nullptr, false, zone))
    {
        localDef->JoinBot(bot);
        anyJoined = true;
    }

    if (Channel* lfg = mgr->GetChannel(26, "", nullptr, false, zone))
    {
        lfg->JoinBot(bot);
        anyJoined = true;
    }

    if (anyJoined)
        ai->_lastChannelZoneId = zoneId;
}

void FSBChatMgr::LeaveBotChannels(Creature* bot)
{
    if (!bot || !bot->IsBot())
        return;

    Team botTeam = FSBUtils::GetTeamFromFSBRace(FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()));
    ChannelMgr* mgr = ChannelMgr::ForTeam(botTeam);
    if (!mgr)
        return;

    uint32 zoneId = bot->GetZoneId();
    AreaTableEntry const* zone = sAreaTableStore.LookupEntry(zoneId);
    if (!zone)
        return;

    if (Channel* general = mgr->GetChannel(1, "", nullptr, false, zone))
        general->LeaveBot(bot);

    if (Channel* trade = mgr->GetChannel(2, "", nullptr, false, zone))
        trade->LeaveBot(bot);

    if (Channel* localDef = mgr->GetChannel(22, "", nullptr, false, zone))
        localDef->LeaveBot(bot);

    if (Channel* lfg = mgr->GetChannel(26, "", nullptr, false, zone))
        lfg->LeaveBot(bot);
}

void FSBChatMgr::UpdateBotChannels(Creature* bot)
{
    if (!bot || !bot->IsBot())
        return;

    FSB_BaseAI* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
    if (!ai || ai->botHired)
        return;

    uint32 currentZone = bot->GetZoneId();
    if (ai->_lastChannelZoneId == currentZone)
        return;

    LeaveBotChannels(bot);
    JoinBotChannels(bot);
}

void FSBChatMgr::HandlePlayerGeneralChat(Player* player, Channel* channel, std::string const& msg)
{
    if (!FollowshipBotsConfig::configFSBGeneralReplyEnabled)
        return;

    if (!player || !channel || msg.empty())
        return;

    if (channel->GetChannelId() != 1)
        return;

    std::vector<Creature*> channelBots;
    for (Creature* bot : GetActiveBots())
        if (channel->IsBotOn(bot->GetGUID()))
            channelBots.push_back(bot);

    // First pass: add message to all bot memories - main thread, safe
    for (Creature* bot : channelBots)
        if (FSB_BaseAI* ai = dynamic_cast<FSB_BaseAI*>(bot->AI()))
            ai->AddChatMemory(1, player->GetName(), msg, true);

    uint32 now = getMSTime();
    uint32 cooldownMs = FollowshipBotsConfig::configFSBGeneralReplyCooldownMs;
    uint32 chance = std::min(FollowshipBotsConfig::configFSBGeneralReplyChance, 100u);

    // Snapshot player data now - Player* is NOT safe to touch after this function returns
    FSBChannelPrompts::PlayerSnapshot playerSnap;
    playerSnap.name = player->GetName();
    playerSnap.race = player->GetRace();
    playerSnap.playerClass = player->GetClass();
    playerSnap.level = player->GetLevel();

    ObjectGuid playerGuid = player->GetGUID();

    for (Creature* bot : channelBots)
    {
        if (!bot->IsAlive())
            continue;

        if (FSBMgr::Get()->IsBotOwned(bot))
            continue;

        auto cdIt = _botReplyCooldowns.find(bot->GetGUID());
        if (cdIt != _botReplyCooldowns.end() && now < cdIt->second + cooldownMs)
            continue;

        if (urand(0, 99) >= chance)
            continue;

        FSB_BaseAI* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
            continue;

        // Build everything by VALUE before leaving the main thread
        FSBChannelPrompts::BotChatContext ctx;
        ctx.entry = bot->GetEntry();
        ctx.level = bot->GetLevel();
        ctx.zoneId = bot->GetZoneId();
        ctx.areaId = bot->GetAreaId();
        ctx.botClass = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());
        ctx.botRace = FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry());
        ctx.personality = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        ctx.role = FSBMgr::Get()->GetRole(bot);
        ctx.allowGold = ShouldAllowGold(ai);
        ctx.goldGivenCount = ai->botChatData.goldGivenCount;
        ctx.lastGoldGiveTime = ai->botChatData.lastGoldGiveTime;
        ctx.botName = bot->GetName();

        if (WowTime const* wowTime = GameTime::GetWowTime())
        {
            int8 hour = wowTime->GetHour();
            int8 minute = wowTime->GetMinute();
            if (hour >= 0 && minute >= 0)
            {
                char buf[16];
                snprintf(buf, sizeof(buf), "%02d:%02d", hour, minute);
                ctx.inGameTime = buf;
                ctx.inGameHour = hour;
            }
        }

        if (Map* map = bot->GetMap())
        {
            WeatherState ws = map->GetZoneWeather(bot->GetZoneId());
            ctx.weather = FSBUtils::WeatherStateToText(ws);
            ctx.weatherStateRaw = static_cast<uint32>(ws);
        }

        // Snapshot memory - the deque on the AI may change while the thread runs
        std::deque<BotChatMemoryEntry> memoryCopy = ai->GetChatMemory();

        auto state = std::make_shared<PendingBotReply>();
        state->botGuid = bot->GetGUID();
        state->channelId = channel->GetChannelId();
        state->botTeam = FSBUtils::GetTeamFromFSBRace(FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()));
        state->playerGuid = playerGuid;
        state->playerName = playerSnap.name;
        state->playerRequest = msg;

        // Zero raw pointers captured - everything is by value
        std::thread([state,
            ctx = std::move(ctx),
            msgCopy = msg,
            memoryCopy = std::move(memoryCopy),
            playerSnap = playerSnap]() mutable
            {
                try
                {
                    FSBChannelPrompts::BotChatResponse resp =
                        FSBChannelPrompts::GenerateReplyToPlayer(ctx, playerSnap, msgCopy, memoryCopy);

                    {
                        std::lock_guard<std::mutex> lock(state->mutex);
                        state->response = std::move(resp);
                    }
                }
                catch (...)
                {
                    // Silently drop LLM failures - empty reply is skipped in Update
                }
                state->ready.store(true, std::memory_order_release);
            }).detach();

        {
            std::lock_guard<std::mutex> lock(_pendingRepliesMutex);
            _pendingReplies.push_back(state);
        }

        _botReplyCooldowns[bot->GetGUID()] = now;
    }
}

void FSBChatMgr::HandleBotWhisper(Player* player, Creature* bot, std::string const& msg)
{
    if (!player || !bot || msg.empty())
        return;

    // Send whisper inform so sender sees "To BotName: msg"
    WorldPackets::Chat::Chat informPacket;
    informPacket.Initialize(CHAT_MSG_WHISPER_INFORM, LANG_UNIVERSAL, bot, bot, msg);
    informPacket.SenderName = FSBChatMgr::SanitizeBotName(bot->GetName());
    player->SendDirectMessage(informPacket.Write());

    FSB_BaseAI* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
    if (!ai)
        return;

    // Add to bot memory
    ai->AddChatMemory(0, player->GetName(), msg, true);

    // Snapshot player data - safe to read here since we're on the main thread
    FSBChannelPrompts::PlayerSnapshot playerSnap;
    playerSnap.name = player->GetName();
    playerSnap.race = player->GetRace();
    playerSnap.playerClass = player->GetClass();
    playerSnap.level = player->GetLevel();

    FSBChannelPrompts::BotChatContext ctx;
    ctx.entry = bot->GetEntry();
    ctx.level = bot->GetLevel();
    ctx.zoneId = bot->GetZoneId();
    ctx.areaId = bot->GetAreaId();
    ctx.botClass = FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry());
    ctx.botRace = FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry());
    ctx.personality = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
    ctx.role = FSBMgr::Get()->GetRole(bot);
    ctx.allowGold = ShouldAllowGold(ai);
    ctx.goldGivenCount = ai->botChatData.goldGivenCount;
    ctx.lastGoldGiveTime = ai->botChatData.lastGoldGiveTime;
    ctx.botName = bot->GetName();

    if (WowTime const* wowTime = GameTime::GetWowTime())
    {
        int8 hour = wowTime->GetHour();
        int8 minute = wowTime->GetMinute();
        if (hour >= 0 && minute >= 0)
        {
            char buf[16];
            snprintf(buf, sizeof(buf), "%02d:%02d", hour, minute);
            ctx.inGameTime = buf;
            ctx.inGameHour = hour;
        }
    }

    if (Map* map = bot->GetMap())
    {
        WeatherState ws = map->GetZoneWeather(bot->GetZoneId());
        ctx.weather = FSBUtils::WeatherStateToText(ws);
        ctx.weatherStateRaw = static_cast<uint32>(ws);
    }

    // Snapshot memory - the deque on the AI may change while the thread runs
    std::deque<BotChatMemoryEntry> memoryCopy = ai->GetChatMemory();

    auto state = std::make_shared<PendingBotReply>();
    state->botGuid = bot->GetGUID();
    state->channelId = 0; // 0 signals a whisper reply
    state->botTeam = FSBUtils::GetTeamFromFSBRace(FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()));
    state->playerGuid = player->GetGUID();
    state->playerName = playerSnap.name;
    state->playerRequest = msg;

    // Zero raw pointers captured - everything is by value
    std::thread([state,
        ctx = std::move(ctx),
        msgCopy = msg,
        memoryCopy = std::move(memoryCopy),
        playerSnap = playerSnap]() mutable
        {
            try
            {
                FSBChannelPrompts::BotChatResponse resp =
                    FSBChannelPrompts::GenerateReplyToPlayer(ctx, playerSnap, msgCopy, memoryCopy);

                {
                    std::lock_guard<std::mutex> lock(state->mutex);
                    state->response = std::move(resp);
                }
            }
            catch (...)
            {
                // Silently drop LLM failures - empty reply is skipped in Update
            }
            state->ready.store(true, std::memory_order_release);
        }).detach();

    {
        std::lock_guard<std::mutex> lock(_pendingRepliesMutex);
        _pendingReplies.push_back(state);
    }
}

void FSBChatMgr::DispatchAsyncRandomChat(Creature* bot, FSBChat::ChatChannelType channel, Unit* attacker)
{
    if (!bot)
        return;

    auto state = std::make_shared<PendingRandomChat>();
    state->botGuid = bot->GetGUID();
    state->channelType = channel;

    if (attacker)
    {
        state->attackerGuid = attacker->GetGUID();
        state->hasAttacker = true;
    }

    if (channel == FSBChat::ChatChannelType::Trade)
    {
        FSBChannelPrompts::TradeChatContext ctx = FSBChannelPrompts::PrepareTradeMessage(bot);
        std::thread([state, ctx]() {
            try
            {
                std::string result = FSBChannelPrompts::GenerateTradeMessage(ctx);
                {
                    std::lock_guard<std::mutex> lock(state->mutex);
                    state->result = std::move(result);
                }
            }
            catch (...) {}
            state->ready.store(true, std::memory_order_release);
        }).detach();
    }
    else if (channel == FSBChat::ChatChannelType::LFG)
    {
        FSBChannelPrompts::LFGChatContext ctx = FSBChannelPrompts::PrepareLFGMessage(bot);
        std::thread([state, ctx]() {
            try
            {
                std::string result = FSBChannelPrompts::GenerateLFGMessage(ctx);
                {
                    std::lock_guard<std::mutex> lock(state->mutex);
                    state->result = std::move(result);
                }
            }
            catch (...) {}
            state->ready.store(true, std::memory_order_release);
        }).detach();
    }
    else if (channel == FSBChat::ChatChannelType::General)
    {
        FSBChannelPrompts::BotChatContext ctx;
        ctx.entry = bot->GetEntry();
        ctx.areaId = bot->GetAreaId();
        ctx.zoneId = bot->GetZoneId();

        if (WowTime const* wowTime = GameTime::GetWowTime())
        {
            int8 hour = wowTime->GetHour();
            int8 minute = wowTime->GetMinute();
            if (hour >= 0 && minute >= 0)
            {
                char buf[16];
                snprintf(buf, sizeof(buf), "%02d:%02d", hour, minute);
                ctx.inGameTime = buf;
                ctx.inGameHour = hour;
            }
        }

        if (Map* map = bot->GetMap())
        {
            WeatherState ws = map->GetZoneWeather(bot->GetZoneId());
            ctx.weather = FSBUtils::WeatherStateToText(ws);
            ctx.weatherStateRaw = static_cast<uint32>(ws);
        }

        FSBChannelPrompts::GeneralChatContext genCtx = FSBChannelPrompts::PrepareGeneralMessage(ctx);
        std::thread([state, genCtx]() {
            try
            {
                std::string result = FSBChannelPrompts::GenerateGeneralMessage(genCtx);
                {
                    std::lock_guard<std::mutex> lock(state->mutex);
                    state->result = std::move(result);
                }
            }
            catch (...) {}
            state->ready.store(true, std::memory_order_release);
        }).detach();
    }
    else
        return;

    std::lock_guard<std::mutex> lock(_pendingRandomChatsMutex);
    _pendingRandomChats.push_back(std::move(state));
}

void FSBChatMgr::DispatchAsyncMailContent(Creature* bot, Player* player, uint32 amount,
    std::string const& playerRequest, std::string const& botReply)
{
    if (!bot || !player)
        return;

    FSBMailPrompts::MailGenContext mailCtx = FSBMailPrompts::PrepareMailContext(bot, player, amount, playerRequest, botReply);

    auto state = std::make_shared<PendingMailContent>();
    state->botGuid = bot->GetGUID();
    state->playerGuid = player->GetGUID();
    state->amount = amount;
    state->botReply = botReply;
    state->creatureEntry = bot->GetEntry();

    std::thread([state, mailCtx]() {
        try
        {
            FSBMailPrompts::MailContent mail = FSBMailPrompts::GenerateGoldMailContent(mailCtx);
            {
                std::lock_guard<std::mutex> lock(state->mutex);
                state->mailContent = std::move(mail);
            }
        }
        catch (...) {}
        state->ready.store(true, std::memory_order_release);
    }).detach();

    std::lock_guard<std::mutex> lock(_pendingMailContentMutex);
    _pendingMailContent.push_back(std::move(state));
}

void FSBChatMgr::Update(uint32 /*diff*/)
{
    uint32 now = getMSTime();

    // Collect replies that are ready AND past their delivery delay
    std::vector<std::shared_ptr<PendingBotReply>> readyReplies;
    {
        std::lock_guard<std::mutex> lock(_pendingRepliesMutex);
        for (auto it = _pendingReplies.begin(); it != _pendingReplies.end(); )
        {
            auto& state = *it;

            if (!state->ready.load(std::memory_order_acquire))
            {
                ++it;
                continue;
            }

            // First time we see this reply as ready - stamp the delivery time
            // urand is main-thread only so this is the correct place for it
            if (state->deliverAfter == 0)
                state->deliverAfter = now + urand(4000, 8000);

            // Not yet time to deliver
            if (now < state->deliverAfter)
            {
                ++it;
                continue;
            }

            // Ready and delay elapsed - hand off for processing
            readyReplies.push_back(std::move(state));
            it = _pendingReplies.erase(it);
        }
    }

    // Snapshot active bots once for the broadcast loop
    std::vector<Creature*> activeBots = GetActiveBots();

    // Process outside the lock - all TC object access happens here on the main thread
    for (auto& state : readyReplies)
    {
        FSBChannelPrompts::BotChatResponse resp;
        {
            std::lock_guard<std::mutex> lock(state->mutex);
            resp = std::move(state->response);
        }

        if (resp.reply.empty())
            continue;

        Creature* bot = FindActiveBotByGuid(state->botGuid);
        if (!bot || !bot->IsInWorld() || !bot->IsAlive())
            continue;

        FSB_BaseAI* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
            continue;

        if (state->channelId == 0)
        {
            // Whisper reply
            Player* player = ObjectAccessor::FindPlayer(state->playerGuid);
            if (!player)
                continue;

            WorldPackets::Chat::Chat packet;
            packet.Initialize(CHAT_MSG_WHISPER, LANG_UNIVERSAL, bot, bot, resp.reply);
            packet.SenderName = FSBChatMgr::SanitizeBotName(bot->GetName());
            player->SendDirectMessage(packet.Write());

            if (resp.action == "give_gold" && resp.amount > 0)
            {
                uint32 amount = std::min(resp.amount, FollowshipBotsConfig::configFSBMaxGoldAmount);
                DispatchAsyncMailContent(bot, player, amount, state->playerRequest, resp.reply);
                TC_LOG_INFO("scripts.fsb.chat", "FSB ChatMgr: bot {} sending {} copper to {} via mail (async)",
                    bot->GetName(), amount, state->playerName);
                ai->botChatData.goldGivenCount++;
                ai->botChatData.lastGoldGiveTime = getMSTime();
                ai->ClearChatMemory();
            }
        }
        else
        {
            // Channel reply
            ChannelMgr* mgr = ChannelMgr::ForTeam(state->botTeam);
            if (!mgr)
                continue;

            uint32 zoneId = bot->GetZoneId();
            AreaTableEntry const* zone = sAreaTableStore.LookupEntry(zoneId);
            if (!zone)
                continue;

            Channel* channel = mgr->GetChannel(state->channelId, "", nullptr, false, zone);
            if (!channel || !channel->IsBotOn(bot->GetGUID()))
                continue;

            channel->BotSay(bot, resp.reply);

            for (Creature* listener : activeBots)
                if (listener != bot && channel->IsBotOn(listener->GetGUID()))
                    if (FSB_BaseAI* listenerAI = dynamic_cast<FSB_BaseAI*>(listener->AI()))
                        listenerAI->AddChatMemory(state->channelId, bot->GetName(), resp.reply, false);

            if (resp.action == "give_gold" && resp.amount > 0)
            {
                Player* player = ObjectAccessor::FindPlayer(state->playerGuid);
                if (player)
                {
                    uint32 amount = std::min(resp.amount, FollowshipBotsConfig::configFSBMaxGoldAmount);
                    DispatchAsyncMailContent(bot, player, amount, state->playerRequest, resp.reply);
                    TC_LOG_INFO("scripts.fsb.chat", "FSB ChatMgr: bot {} sending {} copper to {} via mail (async)",
                        bot->GetName(), amount, state->playerName);
                    ai->botChatData.goldGivenCount++;
                    ai->botChatData.lastGoldGiveTime = getMSTime();
                    ai->ClearChatMemory();
                }
            }
        }
    }

    // --- Process pending random chat ---
    std::vector<std::shared_ptr<PendingRandomChat>> readyChats;
    {
        std::lock_guard<std::mutex> lock(_pendingRandomChatsMutex);
        for (auto it = _pendingRandomChats.begin(); it != _pendingRandomChats.end(); )
        {
            if ((*it)->ready.load(std::memory_order_acquire))
            {
                readyChats.push_back(std::move(*it));
                it = _pendingRandomChats.erase(it);
            }
            else
                ++it;
        }
    }

    for (auto& state : readyChats)
    {
        std::string msg;
        {
            std::lock_guard<std::mutex> lock(state->mutex);
            msg = std::move(state->result);
        }

        Creature* bot = FindActiveBotByGuid(state->botGuid);
        if (!bot || !bot->IsInWorld() || !bot->IsAlive())
            continue;

        if (msg.empty())
        {
            Unit* attacker = state->hasAttacker ? ObjectAccessor::GetUnit(*bot, state->attackerGuid) : nullptr;
            FSBChat::SendStaticRandomChat(bot, state->channelType, attacker);
            continue;
        }

        switch (state->channelType)
        {
        case FSBChat::ChatChannelType::Trade:         FSBChat::BotSendTradeChat(bot, msg); break;
        case FSBChat::ChatChannelType::LFG:           FSBChat::BotSendLFGChat(bot, msg); break;
        case FSBChat::ChatChannelType::General:       FSBChat::BotSendGeneralChat(bot, msg); break;
        case FSBChat::ChatChannelType::LocalDefense:
        case FSBChat::ChatChannelType::CombatDefense: FSBChat::BotSendLocalDefenseChat(bot, msg); break;
        default:                                      FSBChat::BotSendGeneralChat(bot, msg); break;
        }
    }

    // --- Process pending mail content ---
    std::vector<std::shared_ptr<PendingMailContent>> readyMails;
    {
        std::lock_guard<std::mutex> lock(_pendingMailContentMutex);
        for (auto it = _pendingMailContent.begin(); it != _pendingMailContent.end(); )
        {
            if ((*it)->ready.load(std::memory_order_acquire))
            {
                readyMails.push_back(std::move(*it));
                it = _pendingMailContent.erase(it);
            }
            else
                ++it;
        }
    }

    for (auto& state : readyMails)
    {
        FSBMailPrompts::MailContent mail;
        {
            std::lock_guard<std::mutex> lock(state->mutex);
            mail = std::move(state->mailContent);
        }

        Player* player = ObjectAccessor::FindPlayer(state->playerGuid);
        if (!player)
            continue;

        if (mail.subject.empty())
            mail.subject = "Some spare coin";
        if (mail.body.empty())
            mail.body = state->botReply;

        FSBMail::SendMail(state->creatureEntry, player, mail.subject, mail.body, {}, state->amount,
            FollowshipBotsConfig::configFSBGoldMailDelay);

        TC_LOG_INFO("scripts.fsb.chat", "FSB ChatMgr: bot sent {} copper to {} via mail (async)",
            state->amount, player->GetName());
    }
}

namespace FSBChat
{
    // -------------------------------------------------------
    // Helpers to get built-in channels
    // General: channelId = 1
    // Trade:  channelId = 2
    // LocalDefense: 22
    // LFG: 26
    // -------------------------------------------------------

    static Channel* GetZoneChannel(Creature* bot, uint32 channelId)
    {
        if (!bot)
            return nullptr;

        Team botTeam = FSBUtils::GetTeamFromFSBRace(FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()));

        ChannelMgr* mgr = ChannelMgr::ForTeam(botTeam);
        if (!mgr)
            return nullptr;

        uint32 zoneId = bot->GetZoneId();
        AreaTableEntry const* zone = sAreaTableStore.LookupEntry(zoneId);
        if (!zone)
            return nullptr;

        Channel* channel = mgr->GetChannel(channelId, "", nullptr, false, zone);

        return channel;
    }

    static Channel* GetGeneralChannel(Creature* bot)
    {
        // General channelId is 1 in Channel.db2
        return GetZoneChannel(bot, 1);
    }

    static Channel* GetTradeChannel(Creature* bot)
    {
        // Trade channelId is 2
        return GetZoneChannel(bot, 2);
    }

    static Channel* GetLocalDefenseChannel(Creature* bot)
    {
        // LocalDefense channelId is 22
        return GetZoneChannel(bot, 22);
    }

    static Channel* GetLFGChannel(Creature* bot)
    {
        // LookingForGroup channelId is 26
        return GetZoneChannel(bot, 26);
    }

    static void SendBotChannelMessage(Creature* bot, Channel* channel, std::string const& msg)
    {
        if (!bot || !channel || msg.empty())
            return;

        channel->SendBotMessage(bot, msg);
    }

    inline bool IsValidBot(Creature* c)
    {
        if (!c || !c->IsInWorld() || !c->IsAlive())
            return false;

        auto baseAI = dynamic_cast<FSB_BaseAI*>(c->GetAI());
        if (!baseAI)
            return false;

        if (baseAI->botHired)
            return false;

        return true;
    }

    // -------------------------------------------------------
    // Public API: Bot chat helpers
    // -------------------------------------------------------

    void BotSendGeneralChat(Creature* bot, std::string const& msg)
    {
        if (Channel* channel = GetGeneralChannel(bot))
            SendBotChannelMessage(bot, channel, msg);
        else TC_LOG_DEBUG("scripts.fsb.chatter", "FSB: BotSendGeneralChat Channel not found for bot {} with message {}", bot->GetName(), msg);
    }

    void BotSendTradeChat(Creature* bot, std::string const& msg)
    {
        if (Channel* channel = GetTradeChannel(bot))
            SendBotChannelMessage(bot, channel, msg);
        else TC_LOG_DEBUG("scripts.fsb.chatter", "FSB: BotSendTradeChat Channel not found for bot {} with message {}", bot->GetName(), msg);
    }

    void BotSendLocalDefenseChat(Creature* bot, std::string const& msg)
    {
        if (Channel* channel = GetLocalDefenseChannel(bot))
            SendBotChannelMessage(bot, channel, msg);
        else TC_LOG_DEBUG("scripts.fsb.chatter", "FSB: BotSendLocalDefenseChat Channel not found for bot {} with message {}", bot->GetName(), msg);
    }

    void BotSendLFGChat(Creature* bot, std::string const& msg)
    {
        if (Channel* channel = GetLFGChannel(bot))
            SendBotChannelMessage(bot, channel, msg);
        else TC_LOG_DEBUG("scripts.fsb.chatter", "FSB: BotSendLFGChat Channel not found for bot {} with message {}", bot->GetName(), msg);
    }

    void BotSendRaidChat(Creature* bot, std::string const& msg)
    {
        if (!bot || !bot->IsInWorld() || msg.empty())
            return;

        BattlegroundMap* bgMap = bot->GetMap()->ToBattlegroundMap();
        if (!bgMap)
            return;

        Battleground* bg = bgMap->GetBG();
        if (!bg)
            return;

        Team team = FSBUtils::GetTeamFromFSBRace(FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()));
        if (team != ALLIANCE && team != HORDE)
            return;

        WorldPackets::Chat::Chat packet;
        packet.Initialize(CHAT_MSG_RAID, LANG_UNIVERSAL, bot, nullptr, msg);
        bg->SendPacketToTeam(team, packet.Write());
    }

    // Global (or file-static) storage for all running conversations
    std::vector<ActiveConversation> activeConversations;

    void StartBotConversation(Creature* starter)
    {
        if (!starter || !starter->IsAlive())
            return;

        // Pick a random template
        size_t index = urand(0, (ChatTables.size() - 1));
        ConversationTemplate* tmpl = &ChatTables[index];

        // find nearby bots
        auto bots = FSBUtils::FindNearbyBots(starter);

        size_t needed = CountUniqueRoles(*tmpl);

        // Starter is always valid (we checked earlier)
        std::vector<Creature*> participants;
        participants.push_back(starter);

        // Shuffle the nearby bots
        Trinity::Containers::RandomShuffle(bots);

        // Add valid bots only
        for (size_t i = 0; i < bots.size() && participants.size() < needed; ++i)
        {
            Creature* candidate = bots[i];

            if (!IsValidBot(candidate))
                continue;

            participants.push_back(candidate);
        }

        // If we still don't have enough valid bots, abort
        if (participants.size() < needed)
            return;

        // Build role ? participant index map
        std::map<ConversationRole, size_t> roleMap;

        // Starter ALWAYS gets index 0
        roleMap[ConversationRole::Starter] = 0;

        // Collect unique non-starter roles in order of appearance
        std::vector<ConversationRole> orderedRoles;
        for (auto const& line : tmpl->lines)
        {
            if (line.role == ConversationRole::Starter)
                continue;

            if (std::find(orderedRoles.begin(), orderedRoles.end(), line.role) == orderedRoles.end())
                orderedRoles.push_back(line.role);
        }

        // Assign remaining roles starting at index 1
        for (size_t i = 0; i < orderedRoles.size(); ++i)
            roleMap[orderedRoles[i]] = i + 1;

        // Build conversation
        ActiveConversation conv;
        conv.tmpl = tmpl;
        conv.participants = participants;
        conv.roleMap = roleMap;
        conv.currentLine = 0;
        conv.nextSpeakTime = GameTime::GetGameTime() + urand(1, 5);

        activeConversations.push_back(conv);
    }

    void StartBotGenAIConversation(Creature* starter)
    {
        if (!starter || !starter->IsAlive())
            return;

        if (!FSBGenAI::IsEnabled())
            return;

        auto topic = FSBConvPrompts::PickRandomTopic();
        size_t needed = urand(2, 5);
        size_t maxLines = urand(3, 10);

        auto bots = FSBUtils::FindNearbyBots(starter);
        std::vector<Creature*> participants;
        participants.push_back(starter);

        Trinity::Containers::RandomShuffle(bots);

        for (size_t i = 0; i < bots.size() && participants.size() < needed; ++i)
        {
            Creature* candidate = bots[i];
            if (!IsValidBot(candidate))
                continue;
            if (IsBotInConversation(candidate))
                continue;

            participants.push_back(candidate);
        }

        if (participants.size() < needed)
            return;

        ActiveConversation conv;
        conv.isGenAIGenerated = true;
        conv.topic = topic;
        conv.topicDescription = FSBConvPrompts::BuildTopicDescription(starter, topic);
        conv.participants = participants;
        conv.maxLines = maxLines;
        conv.currentLine = 0;
        conv.currentSpeakerIndex = 0;
        conv.nextSpeakTime = GameTime::GetGameTime() + urand(1, 5);

        activeConversations.push_back(conv);
    }

    void UpdateBotConversations()
    {
        uint32 now = GameTime::GetGameTime();

        for (auto it = activeConversations.begin(); it != activeConversations.end(); )
        {
            ActiveConversation& conv = *it;

            if (conv.isGenAIGenerated)
            {
                if (conv.convGenAIState && conv.convGenAIState->ready.load())
                {
                    std::string response;
                    {
                        std::lock_guard<std::mutex> lock(conv.convGenAIState->mutex);
                        response = std::move(conv.convGenAIState->result);
                    }

                    size_t speakerIndex = conv.currentSpeakerIndex;
                    if (speakerIndex < conv.participants.size())
                    {
                        Creature* speaker = conv.participants[speakerIndex];
                        if (!IsValidBot(speaker))
                        {
                            it = activeConversations.erase(it);
                            continue;
                        }

                        if (!response.empty())
                        {
                            TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: bot {} spoke LLM response: {}", speaker->GetName(), response);
                            BotSendGeneralChat(speaker, response);
                            conv.history.emplace_back(speaker->GetName(), response);
                        }
                        else
                        {
                            // LLM returned empty/failed response - fall back to a static scripted conversation
                            TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: bot {} conversation LLM empty; falling back to static StartBotConversation", speaker->GetName());
                            size_t nextIdx = it - activeConversations.begin();
                            it = activeConversations.erase(it);
                            StartBotConversation(speaker);
                            it = activeConversations.begin() + nextIdx;
                            continue;
                        }
                    }

                    conv.convGenAIState.reset();
                    conv.currentLine++;
                    conv.currentSpeakerIndex = (conv.currentSpeakerIndex + 1) % conv.participants.size();

                    if (conv.currentLine >= conv.maxLines)
                    {
                        it = activeConversations.erase(it);
                        continue;
                    }

                    conv.nextSpeakTime = now + urand(2, 5);
                }
                else if (now >= conv.nextSpeakTime && !conv.convGenAIState)
                {
                    size_t speakerIndex = conv.currentSpeakerIndex;
                    if (speakerIndex >= conv.participants.size())
                    {
                        it = activeConversations.erase(it);
                        continue;
                    }

                    Creature* speaker = conv.participants[speakerIndex];
                    if (!IsValidBot(speaker))
                    {
                        it = activeConversations.erase(it);
                        continue;
                    }

                    FSBConvPrompts::DispatchConversationTurn(speaker, conv);
                }

                ++it;
                continue;
            }

            if (now >= conv.nextSpeakTime)
            {
                auto& line = conv.tmpl->lines[conv.currentLine];

                // Find which participant should speak
                auto itRole = conv.roleMap.find(line.role);
                if (itRole != conv.roleMap.end())
                {
                    size_t speakerIndex = itRole->second;
                    if (speakerIndex < conv.participants.size())
                    {
                        Creature* speaker = conv.participants[speakerIndex];
                        if (!IsValidBot(speaker))
                        {
                            it = activeConversations.erase(it);
                            continue;
                        }

                        BotSendGeneralChat(speaker, line.text);
                    }
                }

                conv.currentLine++;

                // End of conversation?
                if (conv.currentLine >= conv.tmpl->lines.size())
                {
                    it = activeConversations.erase(it);
                    continue;
                }
                else
                {
                    conv.nextSpeakTime = now + urand(2, 5);
                }
            }

            ++it;
        }
    }

    bool IsBotInConversation(Creature* bot)
    {
        for (auto const& conv : activeConversations)
            for (auto* p : conv.participants)
                if (p == bot)
                    return true;

        return false;
    }

    size_t CountUniqueRoles(const ConversationTemplate& tmpl)
    {
        std::set<ConversationRole> roles;
        for (auto const& line : tmpl.lines)
            roles.insert(line.role);
        return roles.size();
    }

    const char* GetColorCode(uint32 quality)
    {
        switch (quality)
        {
        case 0: return "|cff9d9d9d"; // Poor (gray)
        case 1: return "|cffffffff"; // Common (white)
        case 2: return "|cff1eff00"; // Uncommon (green)
        case 3: return "|cff0070dd"; // Rare (blue)
        case 4: return "|cffa335ee"; // Epic (purple)
        case 5: return "|cffff8000"; // Legendary (orange)
        case 6: return "|cffe6cc80"; // Artifact (gold)
        default: return "|cffffffff"; // fallback white
        }
    }

    std::string BuildItemLink(uint32 itemId, uint32 level /*= 0*/)
    {
        if (!itemId)
            return "";

        std::string name = "<unknown>";
        const char* qualityTag = "|cffffffff"; // default white

        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemId))
        {
            name = proto->GetName(LOCALE_enUS);
            qualityTag = GetColorCode(proto->GetQuality());
        }

        std::ostringstream ss;
        ss << qualityTag
            << "|Hitem:" << itemId << ":0:0:0:0:0:0:0:" << level << ":0:0:0:0:0|h["
            << name << "]|h|r";

        return ss.str();
    }

    inline std::string BuildSpellLink(uint32 spellId)
    {
        if (!spellId)
            return "";

        const char* color = "|cff71d5ff"; // standard spell link color
        std::string name = FSBSpellsUtils::GetSpellName(spellId);

        std::ostringstream ss;
        ss << color
            << "|Hspell:" << spellId << "|h["
            << name << "]|h|r";

        return ss.str();
    }

    inline void ReplaceAll(std::string& text, const std::string& from, const std::string& to)
    {
        size_t pos = 0;
        while ((pos = text.find(from, pos)) != std::string::npos)
        {
            text.replace(pos, from.length(), to);
            pos += to.length();
        }
    }

    inline std::string GetAreaName(uint32 areaId)
    {
        if (AreaTableEntry const* area = sAreaTableStore.LookupEntry(areaId))
        {
            std::string name = area->AreaName[LOCALE_enUS];
            return name;
        }

        return "<unknown area>";
    }

    std::vector<uint32> tradeItems = { 2840, 2835, 2589, 2318 };

    inline uint32 GetRandomItemId(const std::vector<uint32>& items)
    {
        if (items.empty())
            return 0;

        return items[urand(0, items.size() - 1)];
    }


    inline RandomChatTemplate* GetRandomMatchingLine(Creature* bot, ChatChannelType channel)
    {
        if (!bot)
            return nullptr;

        uint32 zoneId = bot->GetZoneId();
        Team team = FSBUtils::GetTeamFromFSBRace(FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()));

        std::vector<RandomChatTemplate*> matches;

        for (auto& entry : RandomChatTables)
        {
            if (entry.channel != channel)
                continue;

            if (entry.zoneId != 0 && entry.zoneId != zoneId)
                continue;

            if (entry.team != Team::PANDARIA_NEUTRAL && entry.team != team)
                continue;

            matches.push_back(&entry);
        }

        if (matches.empty())
            return nullptr;

        return matches[urand(0, matches.size() - 1)];
    }

    void SendStaticRandomChat(Creature* bot, ChatChannelType channel, Unit* attacker)
    {
        if (!bot)
            return;

        RandomChatTemplate* line = GetRandomMatchingLine(bot, channel);
        if (!line)
            return;

        std::string msg = line->text;

        if (line->spellId)
            ReplaceAll(msg, "{spell}", BuildSpellLink(line->spellId));

        if (line->itemId)
            ReplaceAll(msg, "{item}", BuildItemLink(line->itemId, bot->GetLevel()));

        ReplaceAll(msg, "{area}", GetAreaName(bot->GetAreaId()));
        ReplaceAll(msg, "{item}", BuildItemLink(GetRandomItemId(tradeItems), bot->GetLevel()));

        if (attacker && attacker->IsAlive())
            ReplaceAll(msg, "{target}", attacker->GetName());
        else if (Unit* v = bot->GetVictim())
            ReplaceAll(msg, "{target}", v->GetName());
        else
            ReplaceAll(msg, "{target}", "");

        switch (channel)
        {
        case ChatChannelType::General:        BotSendGeneralChat(bot, msg); break;
        case ChatChannelType::Trade:          BotSendTradeChat(bot, msg); break;
        case ChatChannelType::LocalDefense:   BotSendLocalDefenseChat(bot, msg); break;
        case ChatChannelType::LFG:            BotSendLFGChat(bot, msg); break;
        case ChatChannelType::CombatDefense:  BotSendLocalDefenseChat(bot, msg); break;
        default:                              BotSendGeneralChat(bot, msg); break;
        }
    }

    void StartBotRandomChat(Creature* bot, ChatChannelType channel)
    {
        if (!bot)
            return;

        if (FSBGenAI::IsEnabled() &&
            (channel == ChatChannelType::Trade || channel == ChatChannelType::LFG || channel == ChatChannelType::General))
        {
            FSBChatMgr::Get()->DispatchAsyncRandomChat(bot, channel);
            return;
        }

        SendStaticRandomChat(bot, channel);
    }

    void StartBotRandomChat(Creature* bot, ChatChannelType channel, Unit* attacker)
    {
        if (!bot)
            return;

        if (FSBGenAI::IsEnabled() &&
            (channel == ChatChannelType::Trade || channel == ChatChannelType::LFG || channel == ChatChannelType::General))
        {
            FSBChatMgr::Get()->DispatchAsyncRandomChat(bot, channel, attacker);
            return;
        }

        SendStaticRandomChat(bot, channel, attacker);
    }

    std::vector<RandomChatTemplate> RandomChatTables =
    {
        // Stormwind
        { 1519, ChatChannelType::General,      Team::ALLIANCE,          0,      0,      "Stormwind sure is crowded today..." },
        { 1519, ChatChannelType::LFG,          Team::ALLIANCE,          0,      0,      "LFM for Deadmines, need tank and healer!" },

        // Elwyn
        {   12, ChatChannelType::General,      Team::ALLIANCE,          0,      0,      "The marshal in Goldshire was not looking happy today..." },

        {   12, ChatChannelType::LocalDefense, Team::ALLIANCE,          0,      0,      "Another wolf attack near the farms!" },

        // No zone - generic
        {    0, ChatChannelType::General,      Team::PANDARIA_NEUTRAL,  0,      0,      "Anyone else feel like the respawn timers are getting shorter?" },
        {    0, ChatChannelType::General,      Team::PANDARIA_NEUTRAL,  0,      0,      "I am in {area} today... who knows where I will be tomorrow!" },
        {    0, ChatChannelType::General,      Team::PANDARIA_NEUTRAL,  0,      0,      "Yesterday I was in the Blasted Lands, today I am back in {area}." },
        {    0, ChatChannelType::General,      Team::PANDARIA_NEUTRAL,  1953,   0,      "Mages should just stop with their {spell} inside the inn." },

        {    0, ChatChannelType::Trade,        Team::PANDARIA_NEUTRAL,  0,      2770,   "WTS 20x {item} cheap!" },
        {    0, ChatChannelType::Trade,        Team::PANDARIA_NEUTRAL,  0,      0,      "WTS tons of {item} cheap!" },
        {    0, ChatChannelType::Trade,        Team::PANDARIA_NEUTRAL,  0,      0,      "WTB {item} please send offer!" },
        {    0, ChatChannelType::Trade,        Team::PANDARIA_NEUTRAL,  0,      0,      "Anyone have some {item} I can buy?" },
        {    0, ChatChannelType::Trade,        Team::PANDARIA_NEUTRAL,  0,      0,      "Giving some {item} for free, contact me!" },
        {    0, ChatChannelType::Trade,        Team::PANDARIA_NEUTRAL,  0,      0,      "Does anyone need {item} otherwise they go on auction..." },

        // No zone - generic combat related messages
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Am being attacked, someone please help." },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is attacking me, someone please help." },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I'm under attack, need assistance!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is attacking me, requesting help!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Help! I'm being ambushed!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Under attack here, anyone nearby in {area}?" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is on me! Need backup!" },

        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Taking heavy hits, someone help!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I could use a hand over here in {area}!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} picked a fight with me!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Being attacked! Anyone available?" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Trouble here in {area}! Need support!" },

        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I'm taking damage, someone intervene!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is trying to kill me!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Assistance needed, I'm under attack!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Help defend me, I'm being targeted!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is hostile, requesting aid!" },

        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I'm in combat and need help!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Someone assist me, I'm being attacked!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is engaging me, need backup!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Under fire here in {area}, help!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I'm being overwhelmed, someone help!" },

        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Danger! I'm being attacked!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is after me, need assistance!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Help me fend this off!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I'm in trouble, someone help!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is attacking, requesting immediate aid!" },

        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Need defenders here, I'm under attack!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I'm being assaulted, help!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is hostile, need help now!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Anyone nearby? I'm being attacked!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I need backup immediately!" },

        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I'm taking hits, someone assist!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is trying to take me down!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Help! I'm being overwhelmed!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Under attack, requesting reinforcements!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is on me, need help fast!" },

        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I'm being targeted, someone help me in {area}!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Hostile contact! Need assistance!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is attacking, requesting backup!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Help me, I'm under attack!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I'm engaged in combat, need support!" },

        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Someone help me fight this off!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is attacking me, need defenders!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I'm being attacked, requesting aid!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Trouble here, I'm under attack!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is hostile, need help immediately!" },

        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I'm in danger, someone help me!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Being attacked in {area}! Need backup now!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "{target} is engaging me, requesting assistance!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "Help! I'm in danger and need support!" },
        { 0, ChatChannelType::CombatDefense, Team::PANDARIA_NEUTRAL, 0, 0, "I'm being attacked, defenders to me!" }
        
    };

    std::vector<ConversationTemplate> ChatTables = {
    {
        "TavernGossip",
        {
            { ConversationRole::Starter,   "Did you hear what happened in Goldshire last night?" },
            { ConversationRole::Responder, "Oh, don't tell me. another drunken mage blew up the inn?" },
            { ConversationRole::Follower,  "No no, this time it was a paladin. Much louder." }
        }
    },
    {
        "StormwindShenanigans",
        {
            { ConversationRole::Starter,   "Did you see that mage trying to teleport onto the Cathedral roof again?" },
            { ConversationRole::Responder, "He missed and landed in the canal. The fish are still traumatized." },
            { ConversationRole::Follower,  "I heard the guards thought he was a murloc and almost threw a net on him." },
            { ConversationRole::Extra,     "Honestly, with the noises he made climbing out, I don't blame them." }
        }
    },
    {
        "StormwindKingDebate",
        {
            { ConversationRole::Starter,   "If there was a vote tomorrow for who should be king of Stormwind, who would win?" },
            { ConversationRole::Responder, "Ragnaros...?" },
            { ConversationRole::Starter,   "That was a serious question..." },
            { ConversationRole::Responder, "That was a serious answer." },
            { ConversationRole::Starter,   "You can't be serious, really!" },
            { ConversationRole::Responder, "Ok, sorry, I'll try again." },
            { ConversationRole::Responder, "Hogger, yeah that's the one... Hogger!" },
            { ConversationRole::Starter,   "Anyone else... please!" },
        }
    },
    {
        "MageQuarterDisaster",
        {
            { ConversationRole::Starter,   "Why does the Mage Quarter always smell like burnt eyebrows?" },
            { ConversationRole::Responder, "Because mages keep trying spells they found scribbled on napkins." },
            { ConversationRole::Follower,  "Last week someone summoned a sheep that exploded into more sheep." },
            { ConversationRole::Extra,     "Honestly, that was an improvement over the usual smell." }
        }
    },

    {
        "DwarvenEngineeringDebate",
        {
            { ConversationRole::Starter,   "Is it true dwarves invented a cannon that fires smaller cannons?" },
            { ConversationRole::Responder, "Aye, but the recoil launched Ironforge three inches to the left." },
            { ConversationRole::Follower,  "They said it was 'within acceptable engineering tolerances'." }
        }
    },

    {
        "StormwindCanalMystery",
        {
            { ConversationRole::Starter,   "Something big is living in the Stormwind canals." },
            { ConversationRole::Responder, "If it's big, it's probably a mage experiment gone wrong." },
            { ConversationRole::Follower,  "If it's small, it's definitely a mage experiment gone wrong." }
        }
    },

    {
        "GoldshireRumors",
        {
            { ConversationRole::Starter,   "I heard Goldshire had to hire extra guards last night." },
            { ConversationRole::Responder, "To stop trouble?" },
            { ConversationRole::Starter,   "No, to stop people from *starting* trouble." }
        }
    },

    {
        "StormwindPolitics",
        {
            { ConversationRole::Starter,   "Stormwind politics are getting weird again." },
            { ConversationRole::Responder, "Again? They never stopped." },
            { ConversationRole::Follower,  "Last council meeting ended with a pie fight." },
            { ConversationRole::Extra,     "And the pie won." }
        }
    },

    {
        "ElwynnForestFacts",
        {
            { ConversationRole::Starter,   "Fun fact: Elwynn Forest has more wolves than trees." },
            { ConversationRole::Responder, "That can't be true." },
            { ConversationRole::Starter,   "Have you *seen* how fast they... uhm *respawn*?" },
            { ConversationRole::Responder, "Aahaha I see what you mean..." },
        }
    },

    {
        "StormwindGuardLife",
        {
            { ConversationRole::Starter,   "Being a Stormwind guard must be exhausting." },
            { ConversationRole::Responder, "Standing still all day?" },
            { ConversationRole::Starter,   "No, pretending not to see half the nonsense happening around them." }
        }
    },

    {
        "CathedralSquareDrama",
        {
            { ConversationRole::Starter,   "Why was Cathedral Square blocked off this morning?" },
            { ConversationRole::Responder, "A paladin tried to bless the fountain." },
            { ConversationRole::Follower,  "He slipped, fell in, and declared it holy water." },
            { ConversationRole::Extra,     "Honestly, I respect the commitment." }
        }
    },

    {
        "StormwindAuctionChaos",
        {
            { ConversationRole::Starter,   "The Auction House was wild today." },
            { ConversationRole::Responder, "What happened?" },
            { ConversationRole::Starter,   "Someone listed a single linen cloth for 999 gold." },
            { ConversationRole::Follower,  "And someone bought it, didn't they?" },
            { ConversationRole::Starter,   "Instantly." },
            { ConversationRole::Responder, "You're joking..." },
            { ConversationRole::Starter,   "Wish I was..." }
        }
    },

    {
        "ParkPhilosophers",
        {
            { ConversationRole::Starter,   "Why do people in the Stormwind Park always talk like philosophers?" },
            { ConversationRole::Responder, "Because they're druids. They can't help it." },
            { ConversationRole::Follower,  "Last one asked me if my spirit animal was 'emotionally fulfilled'." }
        }
    },

    {
        "StormwindFoodDebate",
        {
            { ConversationRole::Starter,   "Stormwind needs better food vendors." },
            { ConversationRole::Responder, "What's wrong with the current ones?" },
            { ConversationRole::Starter,   "I ordered soup. It came in a bucket." },
            { ConversationRole::Extra,     "That's just 'rustic presentation'." }
        }
    },

    {
        "GryphonRiderConfessions",
        {
            { ConversationRole::Starter,   "Gryphon riders must have nerves of steel." },
            { ConversationRole::Responder, "Or no nerves at all." },
            { ConversationRole::Follower,  "One told me he fell asleep mid-flight once." },
            { ConversationRole::Extra,     "The gryphon landed better than he does." }
        }
    },

    {
        "StormwindBankSecrets",
        {
            { ConversationRole::Starter,   "What do you think is really inside the Stormwind Bank vault?" },
            { ConversationRole::Responder, "Gold." },
            { ConversationRole::Starter,   "No, I mean *really*." },
            { ConversationRole::Follower,  "Probably a very confused kobold." }
        }
    },

    {
        "TradeDistrictChaos",
        {
            { ConversationRole::Starter,   "Trade District was on fire again." },
            { ConversationRole::Responder, "Literal or metaphorical?" },
            { ConversationRole::Starter,   "Both." }
        }
    },

    {
        "StormwindFashionPolice",
        {
            { ConversationRole::Starter,   "Stormwind needs a fashion police force." },
            { ConversationRole::Responder, "Why?" },
            { ConversationRole::Starter,   "I saw a mage wearing plate boots with a robe." },
            { ConversationRole::Follower,  "That should be illegal." },
            { ConversationRole::Responder, "It is..." },
        }
    },

    {
        "StormwindBridgePhobia",
        {
            { ConversationRole::Starter,   "Why do people avoid the bridge near the Mage Tower?" },
            { ConversationRole::Responder, "Because it collapses every Tuesday." },
            { ConversationRole::Follower,  "Maintenance day?" },
            { ConversationRole::Starter,   "No, mage experiments." }
        }
    },

    {
        "StormwindZooRumors",
        {
            { ConversationRole::Starter,   "Is it true Stormwind once had a zoo?" },
            { ConversationRole::Responder, "Yes, but everything escaped." },
            { ConversationRole::Follower,  "Including the staff." }
        }
    },

    {
        "StormwindLibraryFacts",
        {
            { ConversationRole::Starter,   "Stormwind Library has a book that screams when opened." },
            { ConversationRole::Responder, "Sounds like me on Monday mornings." }
        }
    },

    {
        "StormwindInnDrama",
        {
            { ConversationRole::Starter,   "The innkeeper threw someone out again." },
            { ConversationRole::Responder, "What did they do?" },
            { ConversationRole::Starter,   "They asked for a refund on their 'rested experience'." }
        }
    },

    {
        "StormwindRandomFacts",
        {
            { ConversationRole::Starter,   "Random fact: Stormwind has exactly 37 benches." },
            { ConversationRole::Responder, "Who counted them?" },
            { ConversationRole::Starter,   "Someone with too much time and not enough quests." }
        }
    },

    {
        "StormwindBridgePhilosophy",
        {
            { ConversationRole::Starter,   "Have you ever noticed how everyone walks slower on this bridge?" },
            { ConversationRole::Responder, "It's because the view makes people think deep thoughts." },
            { ConversationRole::Follower,  "Last week I saw a mage staring at the water for ten minutes." },
            { ConversationRole::Extra,     "Was he meditating?" },
            { ConversationRole::Follower,  "No, he dropped his wand and was trying to fish it out with telekinesis." },
            { ConversationRole::Responder, "That explains the explosion I heard." },
            { ConversationRole::Starter,   "Stormwind bridges are never boring." }
        }
    },
    {
        "ElwynnForestEconomics",
        {
            { ConversationRole::Starter,   "Why do wolves in Elwynn drop copper coins?" },
            { ConversationRole::Responder, "Maybe they're saving up for armor upgrades." },
            { ConversationRole::Follower,  "Or maybe adventurers keep dropping money while running away." },
            { ConversationRole::Extra,     "Honestly, wolves probably have a better savings account than I do." },
            { ConversationRole::Responder, "At this point, I'd trust a wolf with my finances." },
            { ConversationRole::Starter,   "Elwynn Forest: where the wildlife is wealthier than the guards." }
        }
    },
    {
        "StormwindInnConspiracy",
        {
            { ConversationRole::Starter,   "Have you noticed the innkeeper never sleeps?" },
            { ConversationRole::Responder, "I've never seen him blink either." },
            { ConversationRole::Follower,  "Maybe he's secretly a titan construct." },
            { ConversationRole::Extra,     "A titan construct serving ale?" },
            { ConversationRole::Follower,  "Hey, everyone needs a hobby." },
            { ConversationRole::Responder, "Explains why the ale never runs out." },
            { ConversationRole::Starter,   "Stormwind's greatest mystery isn't the canals. it's the innkeeper." }
        }
    },
    {
        "MageQuarterTimeTravel",
        {
            { ConversationRole::Starter,   "A mage told me he traveled five minutes into the future." },
            { ConversationRole::Responder, "That's just called taking a nap." },
            { ConversationRole::Follower,  "No, he insists it was a temporal displacement." },
            { ConversationRole::Extra,     "Did anything change?" },
            { ConversationRole::Follower,  "He said his tea got cold." },
            { ConversationRole::Responder, "Revolutionary." },
            { ConversationRole::Starter,   "Mages will call anything a spell if it makes them feel important." }
        }
    },
    {
        "StormwindGuardUnion",
        {
            { ConversationRole::Starter,   "Did you hear the guards are forming a union?" },
            { ConversationRole::Responder, "About time. Standing still all day can't be healthy." },
            { ConversationRole::Follower,  "Their demands include chairs, better boots, and fewer dramatic speeches." },
            { ConversationRole::Extra,     "Fewer speeches? But that's half their job!" },
            { ConversationRole::Follower,  "Exactly. They want to cut it down to one heroic line per hour." },
            { ConversationRole::Responder, "Honestly, I'd sign that petition." },
            { ConversationRole::Starter,   "Stormwind might finally become a quieter place." }
        }
    },
    {
        "CathedralSquareConfessions",
        {
            { ConversationRole::Starter,   "A priest told me he once tried to bless a squirrel." },
            { ConversationRole::Responder, "Why would he do that?" },
            { ConversationRole::Follower,  "He said it looked 'spiritually confused'." },
            { ConversationRole::Extra,     "And what happened?" },
            { ConversationRole::Follower,  "The squirrel stole his lunch and ran off." },
            { ConversationRole::Responder, "A holy squirrel with a sandwich. Terrifying." },
            { ConversationRole::Starter,   "Cathedral Square is getting stranger every day." }
        }
    },
    {
        "StormwindMarketInflation",
        {
            { ConversationRole::Starter,   "Why is bread so expensive in Stormwind lately?" },
            { ConversationRole::Responder, "Supply issues. The baker's oven exploded again." },
            { ConversationRole::Follower,  "That's the third time this month!" },
            { ConversationRole::Extra,     "Maybe he should stop experimenting with 'arcane yeast'." },
            { ConversationRole::Follower,  "He said it would rise faster." },
            { ConversationRole::Responder, "It rose so fast it hit the ceiling." },
            { ConversationRole::Starter,   "Stormwind's economy is held together by duct tape and hope." }
        }
    },
    {
        "GryphonAerialAccidents",
        {
            { ConversationRole::Starter,   "I heard a gryphon rider dropped his lunch mid-flight." },
            { ConversationRole::Responder, "That's unfortunate." },
            { ConversationRole::Follower,  "Unfortunate for him, delicious for the wolves below." },
            { ConversationRole::Extra,     "Do gryphons get upset when food falls off?" },
            { ConversationRole::Follower,  "Apparently this one circled back to look for it." },
            { ConversationRole::Responder, "A noble creature. with priorities." },
            { ConversationRole::Starter,   "Stormwind's skies are full of drama." }
        }
    },
    {
        "StormwindLibraryDebate",
        {
            { ConversationRole::Starter,   "The library banned a book for being 'too loud'." },
            { ConversationRole::Responder, "How can a book be loud?" },
            { ConversationRole::Follower,  "It screamed every time someone opened it." },
            { ConversationRole::Extra,     "Sounds cursed." },
            { ConversationRole::Follower,  "The librarian said it was just 'overly dramatic'." },
            { ConversationRole::Responder, "Honestly, same." },
            { ConversationRole::Starter,   "Stormwind literature is wild." }
        }
    },
    {
        "StormwindParkDruidCircle",
        {
            { ConversationRole::Starter,   "The druids in the park held a meeting today." },
            { ConversationRole::Responder, "About what?" },
            { ConversationRole::Follower,  "Apparently the trees are 'feeling underappreciated'." },
            { ConversationRole::Extra,     "Did the trees say that?" },
            { ConversationRole::Follower,  "The druids said they could 'sense it'." },
            { ConversationRole::Responder, "I sense they need a hobby." },
            { ConversationRole::Starter,   "Stormwind Park is basically a nature-themed soap opera." }
        }
    },
    
    {
        "ThunderfuryDebate",
        {
            { ConversationRole::Starter,   "Alright, be honest. if someone actually looted |cffff8000|Hitem:19019:0:0:0:0:0:0:0:0|h[Thunderfury, Blessed Blade of the Windseeker]|h|r today, what would happen?" },
            { ConversationRole::Responder, "Stormwind would hear the scream from Ironforge." },
            { ConversationRole::Follower,  "Half the city would whisper 'Did someone say Thunderfury?' for hours." },
            { ConversationRole::Extra,     "And the other half would pretend they don't care while secretly crying." },
            { ConversationRole::Responder, "Let's be real, even the gryphon riders would stop mid-air to look." },
            { ConversationRole::Follower,  "I once saw a mage faint when someone linked it in trade chat." },
            { ConversationRole::Starter,   "Thunderfury: the only item that causes emotional damage just by existing." }
        }
    },
    {
        "PaladinBubbleArgument",
        {
            { ConversationRole::Starter,   "I swear, paladins rely on |cff71d5ff|Hspell:642|h[Divine Shield]|h|r way too much." },
            { ConversationRole::Responder, "It's not reliance, it's 'strategic invulnerability'." },
            { ConversationRole::Follower,  "Strategic? They bubble when they stub their toe." },
            { ConversationRole::Extra,     "I saw one bubble because a squirrel startled him." },
            { ConversationRole::Responder, "Hey, squirrels in Elwynn are vicious." },
            { ConversationRole::Follower,  "Still doesn't justify bubbling during a cooking fire mishap." },
            { ConversationRole::Starter,   "Paladins don't tank danger. they tank embarrassment." }
        }
    },

    };
}
