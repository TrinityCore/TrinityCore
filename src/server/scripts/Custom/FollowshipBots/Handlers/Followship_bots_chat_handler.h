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

#pragma once

#include <atomic>
#include <map>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <vector>

#include "ObjectGuid.h"
#include "SharedDefines.h"
#include "Unit.h"

#include "GenAI_channel_prompts.h"
#include "GenAI_conversation_prompts.h"
#include "GenAI_mail_prompts.h"

class Channel;
class Creature;
class Player;

namespace FSBChat { enum class ChatChannelType : int; }

class FSBChatMgr
{
public:
    static FSBChatMgr* Get();

    struct PendingBotReply
    {
        std::atomic<bool> ready{ false };
        std::mutex        mutex;

        // Written by async thread
        FSBChannelPrompts::BotChatResponse response;

        // Written before dispatch, read on main thread to act on result
        // Never store raw pointers - re-acquire objects by GUID on main thread
        ObjectGuid  botGuid;
        uint32      channelId = 0;
        Team        botTeam = ALLIANCE;
        ObjectGuid  playerGuid;
        std::string playerName;
        std::string playerRequest;
        uint32      deliverAfter = 0;
    };

    struct PendingRandomChat
    {
        std::atomic<bool> ready{ false };
        std::mutex        mutex;

        std::string result;

        ObjectGuid  botGuid;
        FSBChat::ChatChannelType channelType;
        ObjectGuid  attackerGuid;
        bool        hasAttacker = false;
    };

    struct PendingMailContent
    {
        std::atomic<bool> ready{ false };
        std::mutex        mutex;

        FSBMailPrompts::MailContent mailContent;

        ObjectGuid  botGuid;
        ObjectGuid  playerGuid;
        uint32      amount = 0;
        std::string botReply;
        uint32      creatureEntry = 0;
    };

    // Active bot registry for /who and whisper routing
    void RegisterActiveBot(Creature* bot);
    void UnregisterActiveBot(Creature* bot);
    std::vector<Creature*> GetActiveBots();
    Creature* FindActiveBotByName(std::string const& name) const;
    Creature* FindActiveBotByGuid(ObjectGuid guid) const;
    static std::string SanitizeBotName(std::string const& name);

    // Bot channel membership
    void JoinBotChannels(Creature* bot);
    void LeaveBotChannels(Creature* bot);
    void UpdateBotChannels(Creature* bot);

    // Player chat reply handler
    void HandlePlayerGeneralChat(Player* player, Channel* channel, std::string const& msg);
    void HandleBotWhisper(Player* player, Creature* bot, std::string const& msg);

    // Async dispatch for random channel chat (Trade/LFG/General)
    void DispatchAsyncRandomChat(Creature* bot, FSBChat::ChatChannelType channel, Unit* attacker = nullptr);

    // Async dispatch for gold mail content generation
    void DispatchAsyncMailContent(Creature* bot, Player* player, uint32 amount,
        std::string const& playerRequest, std::string const& botReply);

    // Global update (called from WorldScript::OnUpdate)
    void Update(uint32 diff);

private:
    std::unordered_map<ObjectGuid, Creature*> _activeBots;
    mutable std::mutex _activeBotsMutex;
    std::unordered_map<ObjectGuid, uint32> _botReplyCooldowns;

    std::vector<std::shared_ptr<PendingBotReply>> _pendingReplies;
    std::mutex                                    _pendingRepliesMutex;

    std::vector<std::shared_ptr<PendingRandomChat>> _pendingRandomChats;
    std::mutex                                       _pendingRandomChatsMutex;

    std::vector<std::shared_ptr<PendingMailContent>> _pendingMailContent;
    std::mutex                                        _pendingMailContentMutex;
};

namespace FSBChat
{
    enum class ConversationRole
    {
        Starter,
        Responder,
        Follower,
        Extra
    };

    struct ConversationLine
    {
        ConversationRole role;
        std::string text;
    };

    struct ConversationTemplate
    {
        std::string topic;
        std::vector<ConversationLine> lines;
    };

    struct ActiveConversation
    {
        ConversationTemplate* tmpl = nullptr;
        std::vector<Creature*> participants;
        std::map<ConversationRole, size_t> roleMap;
        size_t currentLine = 0;
        uint32 nextSpeakTime = 0;

        // GenAI fields
        bool isGenAIGenerated = false;
        FSBConvPrompts::ConversationTopic topic;
        std::string topicDescription;
        std::vector<std::pair<std::string, std::string>> history; // {speakerName, line}
        size_t maxLines = 0;
        size_t currentSpeakerIndex = 0;
        std::shared_ptr<FSBConvPrompts::ConversationGenAIState> convGenAIState;
    };

    enum class ChatChannelType
    {
        General,
        Trade,
        LocalDefense,
        CombatDefense, // is basically for LocalDefense but specific to bot combat
        LFG,
        Custom
    };

    struct RandomChatTemplate
    {
        uint32 zoneId;                     // 0 = any zone
        ChatChannelType channel;           // General, Trade, LFG, etc.
        Team team;                       // Alliance, Horde, Neutral
        uint32 spellId;
        uint32 itemId;
        std::string text;                  // The actual chat line
    };

    void BotSendGeneralChat(Creature* bot, std::string const& msg);
    void BotSendTradeChat(Creature* bot, std::string const& msg);
    void BotSendLocalDefenseChat(Creature* bot, std::string const& msg);
    void BotSendLFGChat(Creature* bot, std::string const& msg);
    void BotSendRaidChat(Creature* bot, std::string const& msg);

    extern std::vector<ConversationTemplate> ChatTables;
    extern std::vector<ActiveConversation> activeConversations;
    size_t CountUniqueRoles(const ConversationTemplate& tmpl);

    void StartBotConversation(Creature* starter);
    void StartBotGenAIConversation(Creature* starter);
    void UpdateBotConversations();
    bool IsBotInConversation(Creature* bot);

    extern std::vector<RandomChatTemplate> RandomChatTables;

    void StartBotRandomChat(Creature* bot, ChatChannelType channel);

    // used for chat initiated on combat
    void StartBotRandomChat(Creature* bot, ChatChannelType channel, Unit* attacker);

    // Static fallback when AI returns empty or GenAI is disabled
    void SendStaticRandomChat(Creature* bot, ChatChannelType channel, Unit* attacker = nullptr);

    std::string BuildItemLink(uint32 itemId, uint32 level = 0);
}
