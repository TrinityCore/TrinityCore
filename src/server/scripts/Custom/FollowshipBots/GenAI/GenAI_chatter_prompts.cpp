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

#include "GenAI_chatter_prompts.h"
#include "GenAI_client.h"

#include "Followship_bots_ai_base.h"
#include "Followship_bots_priest.h"
#include "Followship_bots_config.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_chatter_handler.h"
#include "Followship_bots_events_handler.h"
#include "ObjectAccessor.h"

#include "DB2Stores.h"
#include "Log.h"
#include "StringFormat.h"

#include <mutex>
#include <random>
#include <thread>

namespace FSBGenAIPrompts
{
    static std::string PickIntroSet(std::string const& botName, std::string const& zoneName)
    {
        char const* introSets[] =
        {
            "- Vary how you introduce yourself. Examples: 'My name is...', 'I am called...', '{}, at your service...', 'Folks around here know me as...'",
            "- Vary how you introduce yourself. Examples: 'They call me {}...', '{} is my name...', 'You may call me {}...', 'I go by the name {}...'",
            "- Vary how you introduce yourself. Examples: 'Greetings, I am {}...', 'Well met! {} here...', 'The name\'s {}...', '{} - that\'s the name they gave me...'",
            "- Vary how you introduce yourself. Examples: 'A pleasure. I am {}...', 'If you must know, I am {}...', '{}, wanderer of {z}...', 'Some know me as {}...'"
        };

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 3);
        std::string result = introSets[dist(gen)];

        size_t pos = 0;
        while ((pos = result.find("{}", pos)) != std::string::npos)
        {
            result.replace(pos, 2, botName);
            pos += botName.length();
        }

        pos = 0;
        while ((pos = result.find("{z}", pos)) != std::string::npos)
        {
            result.replace(pos, 3, zoneName);
            pos += zoneName.length();
        }

        return result;
    }

    void DispatchBotInfoRequest(Creature* bot)
    {
        if (!bot)
            return;

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());

        if (!FSBGenAI::IsEnabled())
        {
            bot->Say(FSB_GOSSIP_ITEM_PRIEST_INFO, ai ? ai->botLanguage : LANG_UNIVERSAL);
            return;
        }

        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded string.", bot->GetName());
            bot->Say(FSB_GOSSIP_ITEM_PRIEST_INFO, LANG_UNIVERSAL);
            return;
        }

        uint32 entry = bot->GetEntry();
        std::string const& botName = bot->GetName();
        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(entry);
        FSB_Race botRace = FSBMgr::Get()->GetBotRaceForEntry(entry);
        FSB_ChatterType chatterType = FSBMgr::Get()->GetBotChatterTypeForEntry(entry);
        Gender botGender = FSBMgr::Get()->GetBotGenderForEntry(entry);

        uint32 zoneId = bot->GetZoneId();
        AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(zoneId);
        std::string zoneName = areaEntry ? areaEntry->AreaName[LOCALE_enUS] : "Azeroth";

        /* using FSBUtils::ChatterTypeToString / GenderToString */

        std::string chosenIntro = PickIntroSet(botName, zoneName);

        std::string systemPrompt = Trinity::StringFormat(
            "You are a character in World of Warcraft named {}.\n"
            "You are a {} {} {} currently in {}.\n"
            "Your personality is {}.\n\n"
            "Rules:\n"
            "- Reply in first person, staying fully in the game world.\n"
            "- NEVER refer to yourself as an NPC, bot, AI, or game character.\n"
            "{}\n"
            "- Do not copy the examples above word-for-word. Invent your own creative way of introducing yourself.\n"
            "- Keep your reply to 2 or 3 sentences but never more.\n"
            "- The current zone ({}) should naturally appear in your reply.",
            botName,
            FSBUtils::GenderToString(botGender),
            FSBUtils::BotRaceToString(botRace),
            FSBUtils::BotClassToString(botClass),
            zoneName,
            FSBUtils::ChatterTypeToString(chatterType),
            chosenIntro,
            zoneName);

        auto botLanguage = ai->botLanguage;

        ai->genAIFallbackAction = [bot, botLanguage]() {
            bot->Say(FSB_GOSSIP_ITEM_PRIEST_INFO, botLanguage);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched async request for bot {}", botName);
        std::thread([systemPrompt, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt,
                "Tell me something about yourself!");
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    std::string BuildStandardSystemPrompt(Creature* bot)
    {
        uint32 entry = bot->GetEntry();
        std::string const& botName = bot->GetName();
        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(entry);
        FSB_Race botRace = FSBMgr::Get()->GetBotRaceForEntry(entry);
        FSB_ChatterType chatterType = FSBMgr::Get()->GetBotChatterTypeForEntry(entry);
        Gender botGender = FSBMgr::Get()->GetBotGenderForEntry(entry);
        FSB_Roles botRole = FSBMgr::Get()->GetRole(bot);

        uint32 zoneId = bot->GetZoneId();
        AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(zoneId);
        std::string zoneName = areaEntry ? areaEntry->AreaName[LOCALE_enUS] : "Azeroth";

        return Trinity::StringFormat(
            "You are a character in World of Warcraft named {}.\n"
            "You are a {} {} {} currently in {}.\n"
            "Your role is {}.\n"
            "Your personality is {}.\n\n"
            "Rules:\n"
            "- Reply in first person, staying fully in the game world.\n"
            "- NEVER refer to yourself as an NPC, bot, AI, or game character.\n"
            "- Keep your reply to 1 sentence only.\n"
            "- Do not copy the example below word-for-word. Invent your own creative variation.\n"
            "- The current zone ({}) may naturally appear in your reply.",
            botName,
            FSBUtils::GenderToString(botGender),
            FSBUtils::BotRaceToString(botRace),
            FSBUtils::BotClassToString(botClass),
            zoneName,
            FSBUtils::BotRoleToString(botRole),
            FSBUtils::ChatterTypeToString(chatterType),
            zoneName);
    }

    void DispatchBotRoleAcknowledge(Creature* bot)
    {
        if (!bot)
            return;

        if (!FSBGenAI::IsEnabled())
        {
            FSBChatter::DemandTimedReply(bot, nullptr, FSB_ChatterCategory::botAcknowledge, FSB_ReplyType::Say, FSB_ChatterSource::None);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            FSBChatter::DemandTimedReply(bot, nullptr, FSB_ChatterCategory::botAcknowledge, FSB_ReplyType::Say, FSB_ChatterSource::None);
            return;
        }

        FSB_Roles botRole = FSBMgr::Get()->GetRole(bot);

        Player* owner = FSBMgr::Get()->GetBotOwner(bot);
        std::string ownerName = owner ? owner->GetName() : "commander";

        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, FSB_ChatterCategory::botAcknowledge, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string userMessage = Trinity::StringFormat(
            "{} just assigned you the {} role. Acknowledge the command with a brief, creative response relevant to your personality. "
            "Example style (do not copy): \"{}\"",
            ownerName,
            FSBUtils::BotRoleToString(botRole),
            seedLine.empty() ? "On it, commander." : seedLine);

        ai->genAIFallbackAction = [bot]() {
            FSBChatter::DemandTimedReply(bot, nullptr, FSB_ChatterCategory::botAcknowledge, FSB_ReplyType::Say, FSB_ChatterSource::None);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched role acknowledge for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    static FSB_ChatterCategory GetAcknowledgeCategory(FSB_AcknowledgeContext context)
    {
        switch (context)
        {
            case FSB_AcknowledgeContext::StayCommand:    return FSB_ChatterCategory::botStay;
            case FSB_AcknowledgeContext::FollowCommand:  return FSB_ChatterCategory::botFollow;
            default:                                      return FSB_ChatterCategory::botAcknowledge;
        }
    }

    static char const* GetAcknowledgeDescription(FSB_AcknowledgeContext context)
    {
        switch (context)
        {
            case FSB_AcknowledgeContext::FollowDistanceClose:  return "follow at close distance";
            case FSB_AcknowledgeContext::FollowDistanceNormal: return "follow at normal distance";
            case FSB_AcknowledgeContext::FollowDistanceWide:   return "follow at wide distance";
            case FSB_AcknowledgeContext::FollowAngleFront:     return "follow from the front";
            case FSB_AcknowledgeContext::FollowAngleBehind:    return "follow from behind";
            case FSB_AcknowledgeContext::FollowAngleRight:   return "follow from the right";
            case FSB_AcknowledgeContext::FollowAngleLeft:    return "follow from the left";
            case FSB_AcknowledgeContext::StayCommand:        return "stay here and hold position";
            case FSB_AcknowledgeContext::FollowCommand:      return "follow again";
            case FSB_AcknowledgeContext::LanguageCommand:    return "switch your language";
            default:                                         return "obey the command";
        }
    }

    void DispatchBotAcknowledge(Creature* bot, FSB_AcknowledgeContext context)
    {
        if (!bot)
            return;

        FSB_ChatterCategory category = GetAcknowledgeCategory(context);

        if (!FSBGenAI::IsEnabled())
        {
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::None);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::None);
            return;
        }

        Player* owner = FSBMgr::Get()->GetBotOwner(bot);
        std::string ownerName = owner ? owner->GetName() : "commander";

        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string userMessage = Trinity::StringFormat(
            "{} just told you to {}. Acknowledge the command with a brief, creative response relevant to your personality. "
            "Example style (do not copy): \"{}\"",
            ownerName,
            GetAcknowledgeDescription(context),
            seedLine.empty() ? "On it, commander." : seedLine);

        ai->genAIFallbackAction = [bot, category]() {
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::None);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched acknowledge for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotDismissed(Creature* bot)
    {
        if (!bot)
            return;

        if (!FSBGenAI::IsEnabled())
        {
            FSBChatter::DemandBotChatter(bot, nullptr, FSB_ChatterCategory::botDismissed);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            FSBChatter::DemandBotChatter(bot, nullptr, FSB_ChatterCategory::botDismissed);
            return;
        }

        Player* owner = FSBMgr::Get()->GetBotOwner(bot);
        std::string ownerName = owner ? owner->GetName() : "commander";

        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, FSB_ChatterCategory::botDismissed, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string userMessage = Trinity::StringFormat(
            "{} is dismissing you from service. Respond with a brief, creative farewell relevant to your personality. "
            "Example style (do not copy): \"{}\"",
            ownerName,
            seedLine.empty() ? "Time's up. I'm off - good luck out there." : seedLine);

        ai->genAIFallbackAction = [bot]() {
            FSBChatter::DemandBotChatter(bot, nullptr, FSB_ChatterCategory::botDismissed);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched dismissal for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotHired(Creature* bot, uint32 durationHours)
    {
        if (!bot)
            return;

        bool isPermanent = (durationHours == 0);
        FSB_ChatterCategory category = isPermanent ? FSB_ChatterCategory::botHiredPermanent : FSB_ChatterCategory::botHire;
        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());

        if (!FSBGenAI::IsEnabled())
        {
            if (isPermanent)
                FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            else
            {
                std::string chatter = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, 0, durationHours);
                if (!chatter.empty())
                    bot->Say(chatter, ai ? ai->botLanguage : LANG_UNIVERSAL);
            }
            return;
        }

        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            if (isPermanent)
                FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            else
            {
                std::string chatter = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, 0, durationHours);
                if (!chatter.empty())
                    bot->Say(chatter, LANG_UNIVERSAL);
            }
            return;
        }

        Player* owner = FSBMgr::Get()->GetBotOwner(bot);
        std::string ownerName = owner ? owner->GetName() : "commander";

        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, 0, isPermanent ? 0 : durationHours);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string userMessage;
        if (isPermanent)
        {
            userMessage = Trinity::StringFormat(
                "{} just hired you as a permanent companion. Greet them with a brief, creative response relevant to your personality. "
                "Example style (do not copy): \"{}\"",
                ownerName,
                seedLine.empty() ? "Looks like we're in this together now." : seedLine);
        }
        else
        {
            std::string durationStr = durationHours == 1 ? "1 hour" : std::to_string(durationHours) + " hours";
            userMessage = Trinity::StringFormat(
                "{} just hired you for {}. Greet them with a brief, creative response relevant to your personality. "
                "Example style (do not copy): \"{}\"",
                ownerName,
                durationStr,
                seedLine.empty() ? "Alright, let's band together." : seedLine);
        }

        auto botLanguage = ai->botLanguage;

        ai->genAIFallbackAction = [bot, botLanguage, category, durationHours]() {
            FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
            if (category == FSB_ChatterCategory::botHiredPermanent)
                FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            else
            {
                std::string chatter = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, 0, durationHours);
                if (!chatter.empty())
                    bot->Say(chatter, botLanguage);
            }
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched hire for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotRecovery(Creature* bot, uint32 spellId)
    {
        if (!bot)
            return;

        Player* owner = FSBMgr::Get()->GetBotOwner(bot);
        FSB_ChatterCategory category = owner ? FSB_ChatterCategory::botOOCRecoveryHired : FSB_ChatterCategory::botOOCRecovery;
        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());

        if (!FSBGenAI::IsEnabled())
        {
            FSBChatter::DemandBotChatter(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            FSBChatter::DemandBotChatter(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            return;
        }

        std::string ownerName = owner ? owner->GetName() : "commander";

        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, spellId, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string spellName = spellId ? FSBSpellsUtils::GetSpellName(spellId) : "a moment of rest";

        std::string userMessage;
        if (owner)
        {
            userMessage = Trinity::StringFormat(
                "You are recovering after a tough battle, low on strength or energy, and use {} to catch your breath. "
                "Address {} with a brief, creative comment about it relevant to your personality. "
                "Example style (do not copy): \"{}\"",
                spellName,
                ownerName,
                seedLine.empty() ? "Hey, I really need a break..." : seedLine);
        }
        else
        {
            userMessage = Trinity::StringFormat(
                "You are recovering after a tough battle, low on strength or energy, and use {} to catch your breath. "
                "Make a brief, creative comment about it relevant to your personality. "
                "Example style (do not copy): \"{}\"",
                spellName,
                seedLine.empty() ? "Okay, deep breaths. I can do this." : seedLine);
        }

        ai->genAIFallbackAction = [bot, category, spellId]() {
            FSBChatter::DemandBotChatter(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched recovery for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotBuff(Creature* bot, ObjectGuid targetGuid, uint32 spellId)
    {
        if (!bot)
            return;

        bool isSelfBuff = targetGuid == bot->GetGUID();
        FSB_ChatterCategory category = isSelfBuff ? FSB_ChatterCategory::botBuffSelf : FSB_ChatterCategory::botBuffTarget;
        FSB_ChatterType chatterType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());

        if (!FSBGenAI::IsEnabled())
        {
            if (isSelfBuff)
                FSBChatter::DemandBotChatter(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            else
            {
                Unit* target = ObjectAccessor::GetUnit(*bot, targetGuid);
                FSBChatter::DemandBotChatter(bot, target, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            }
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            if (isSelfBuff)
                FSBChatter::DemandBotChatter(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            else
            {
                Unit* target = ObjectAccessor::GetUnit(*bot, targetGuid);
                FSBChatter::DemandBotChatter(bot, target, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            }
            return;
        }

        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, chatterType, spellId, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string spellName = spellId ? FSBSpellsUtils::GetSpellName(spellId) : "a spell";

        std::string userMessage;
        if (isSelfBuff)
        {
            userMessage = Trinity::StringFormat(
                "You just cast a beneficial {} on yourself. Make a brief, creative comment about it relevant to your personality. "
                "Example style (do not copy): \"{}\"",
                spellName,
                seedLine.empty() ? "Am gonna be needing this!" : seedLine);
        }
        else
        {
            Unit* targetUnit = ObjectAccessor::GetUnit(*bot, targetGuid);
            std::string targetName = targetUnit ? targetUnit->GetName() : "your ally";
            userMessage = Trinity::StringFormat(
                "You just cast a beneficial {} on {}. Make a brief, creative comment about it relevant to your personality. "
                "Example style (do not copy): \"{}\"",
                spellName,
                targetName,
                seedLine.empty() ? "Hey, no need to thank me!" : seedLine);
        }

        if (isSelfBuff)
        {
            ai->genAIFallbackAction = [bot, category, spellId]() {
                FSBChatter::DemandBotChatter(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            };
        }
        else
        {
            ai->genAIFallbackAction = [bot, targetGuid, category, spellId]() {
                Unit* target = ObjectAccessor::GetUnit(*bot, targetGuid);
                FSBChatter::DemandBotChatter(bot, target, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            };
        }
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched buff for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotPotion(Creature* bot, uint32 spellId, bool isManaPotion)
    {
        if (!bot)
            return;

        FSB_ChatterCategory category = isManaPotion ? FSB_ChatterCategory::botCombatMana : FSB_ChatterCategory::botCombatHealth;
        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());

        if (!FSBGenAI::IsEnabled())
        {
            FSBChatter::DemandBotChatter(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            FSBChatter::DemandBotChatter(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            return;
        }

        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, spellId, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string spellName = spellId ? FSBSpellsUtils::GetSpellName(spellId) : "a potion";

        std::string userMessage;
        if (isManaPotion)
        {
            userMessage = Trinity::StringFormat(
                "You are in the middle of combat and your mana is dangerously low. "
                "You quickly drink {} to restore your magical energy. "
                "Make a brief, desperate but personality-relevant comment about it. "
                "Example style (do not copy): \"{}\"",
                spellName,
                seedLine.empty() ? "Ugh, my brain's running on empty!" : seedLine);
        }
        else
        {
            userMessage = Trinity::StringFormat(
                "You are in the middle of combat and your health is critically low. "
                "You quickly drink {} to stay alive. "
                "Make a brief, desperate but personality-relevant comment about it. "
                "Example style (do not copy): \"{}\"",
                spellName,
                seedLine.empty() ? "This is my last chance..." : seedLine);
        }

        ai->genAIFallbackAction = [bot, category, spellId]() {
            FSBChatter::DemandBotChatter(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched potion for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotHeal(Creature* bot, ObjectGuid targetGuid, uint32 spellId)
    {
        if (!bot)
            return;

        bool isSelfHeal = targetGuid == bot->GetGUID();
        FSB_ChatterCategory category = isSelfHeal ? FSB_ChatterCategory::botHealSelf : FSB_ChatterCategory::botHealTarget;
        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());

        if (!FSBGenAI::IsEnabled())
        {
            if (isSelfHeal)
                FSBChatter::DemandBotChatter(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            else
            {
                Unit* target = ObjectAccessor::GetUnit(*bot, targetGuid);
                FSBChatter::DemandBotChatter(bot, target, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            }
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            if (isSelfHeal)
                FSBChatter::DemandBotChatter(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            else
            {
                Unit* target = ObjectAccessor::GetUnit(*bot, targetGuid);
                FSBChatter::DemandBotChatter(bot, target, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            }
            return;
        }

        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, spellId, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string spellName = spellId ? FSBSpellsUtils::GetSpellName(spellId) : "healing magic";
        bool inCombat = bot->IsInCombat();

        std::string userMessage;
        if (isSelfHeal)
        {
            if (inCombat)
            {
                userMessage = Trinity::StringFormat(
                    "You are in the middle of combat and your health is dangerously low. "
                    "You use {} on yourself to stay alive. "
                    "Make a brief, urgent but personality-relevant comment about it. "
                    "Example style (do not copy): \"{}\"",
                    spellName,
                    seedLine.empty() ? "Not done yet." : seedLine);
            }
            else
            {
                userMessage = Trinity::StringFormat(
                    "You take a moment to heal yourself with {} while things are calm. "
                    "Make a brief, casual but personality-relevant comment about it. "
                    "Example style (do not copy): \"{}\"",
                    spellName,
                    seedLine.empty() ? "All patched up and good to go." : seedLine);
            }
        }
        else
        {
            Unit* targetUnit = ObjectAccessor::GetUnit(*bot, targetGuid);
            std::string targetName = targetUnit ? targetUnit->GetName() : "your ally";
            if (inCombat)
            {
                userMessage = Trinity::StringFormat(
                    "You are in the middle of combat and {} is wounded. "
                    "You quickly cast {} on them to keep them standing. "
                    "Make a brief, urgent but personality-relevant comment about it. "
                    "Example style (do not copy): \"{}\"",
                    targetName,
                    spellName,
                    seedLine.empty() ? "Hold still, I'm trying to fix whatever that was." : seedLine);
            }
            else
            {
                userMessage = Trinity::StringFormat(
                    "You take a moment to heal {} with {} while things are calm. "
                    "Make a brief, casual but personality-relevant comment about it. "
                    "Example style (do not copy): \"{}\"",
                    targetName,
                    spellName,
                    seedLine.empty() ? "Ah, just what you needed!" : seedLine);
            }
        }

        if (isSelfHeal)
        {
            ai->genAIFallbackAction = [bot, category, spellId]() {
                FSBChatter::DemandBotChatter(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            };
        }
        else
        {
            ai->genAIFallbackAction = [bot, targetGuid, category, spellId]() {
                Unit* target = ObjectAccessor::GetUnit(*bot, targetGuid);
                FSBChatter::DemandBotChatter(bot, target, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            };
        }
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched heal for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotCombatSpell(Creature* bot, ObjectGuid targetGuid, uint32 spellId)
    {
        if (!bot)
            return;

        FSB_ChatterCategory category = FSB_ChatterCategory::botCombatSpell;
        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());

        if (!FSBGenAI::IsEnabled())
        {
            Unit* target = ObjectAccessor::GetUnit(*bot, targetGuid);
            FSBChatter::DemandBotChatter(bot, target, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            Unit* target = ObjectAccessor::GetUnit(*bot, targetGuid);
            FSBChatter::DemandBotChatter(bot, target, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
            return;
        }

        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, spellId, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string spellName = spellId ? FSBSpellsUtils::GetSpellName(spellId) : "a spell";
        Unit* targetUnit = ObjectAccessor::GetUnit(*bot, targetGuid);
        std::string targetName = targetUnit ? targetUnit->GetName() : "your foe";

        std::string userMessage = Trinity::StringFormat(
            "You are in the middle of combat and cast offensively {} on {}. "
            "Make a brief, urgent but personality-relevant comment about it. "
            "Example style (do not copy): \"{}\"",
            spellName,
            targetName,
            seedLine.empty() ? "Take this!" : seedLine);

        ai->genAIFallbackAction = [bot, targetGuid, category, spellId]() {
            Unit* target = ObjectAccessor::GetUnit(*bot, targetGuid);
            FSBChatter::DemandBotChatter(bot, target, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, spellId);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched combat spell for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotTargetKilled(Creature* bot, ObjectGuid victimGuid)
    {
        if (!bot)
            return;

        Player* owner = FSBMgr::Get()->GetBotOwner(bot);
        bool isHired = (owner != nullptr);
        FSB_ChatterCategory category = isHired ? FSB_ChatterCategory::targetKilledHired : FSB_ChatterCategory::targetKilled;

        if (!FSBGenAI::IsEnabled())
        {
            Unit* victim = ObjectAccessor::GetUnit(*bot, victimGuid);
            FSBChatter::DemandBotChatter(bot, victim, category);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            Unit* victim = ObjectAccessor::GetUnit(*bot, victimGuid);
            FSBChatter::DemandBotChatter(bot, victim, category);
            return;
        }

        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        Unit* victimUnit = ObjectAccessor::GetUnit(*bot, victimGuid);
        std::string victimName = victimUnit ? victimUnit->GetName() : "your foe";

        std::string userMessage;
        if (isHired)
        {
            std::string ownerName = owner->GetName();
            userMessage = Trinity::StringFormat(
                "You just landed the final blow on {}. You are fighting alongside your companion {}. "
                "Make a brief, personality-relevant comment about the kill. "
                "Example style (do not copy): \"{}\"",
                victimName,
                ownerName,
                seedLine.empty() ? "That's one less problem to worry about." : seedLine);
        }
        else
        {
            userMessage = Trinity::StringFormat(
                "You just landed the final blow on {}. "
                "Make a brief, personality-relevant comment about the kill. "
                "Example style (do not copy): \"{}\"",
                victimName,
                seedLine.empty() ? "Rest in pieces." : seedLine);
        }

        ai->genAIFallbackAction = [bot, victimGuid, category]() {
            Unit* victim = ObjectAccessor::GetUnit(*bot, victimGuid);
            FSBChatter::DemandBotChatter(bot, victim, category);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched target killed for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotDeath(Creature* bot, ObjectGuid killerGuid)
    {
        if (!bot)
            return;

        Player* owner = FSBMgr::Get()->GetBotOwner(bot);
        bool isHired = (owner != nullptr);
        FSB_ChatterCategory category = isHired ? FSB_ChatterCategory::botDeathHired : FSB_ChatterCategory::botDeath;

        if (!FSBGenAI::IsEnabled())
        {
            Unit* killer = ObjectAccessor::GetUnit(*bot, killerGuid);
            FSBChatter::DemandBotChatter(bot, killer, category, FSB_ReplyType::Yell, FSB_ChatterSource::Bot);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            Unit* killer = ObjectAccessor::GetUnit(*bot, killerGuid);
            FSBChatter::DemandBotChatter(bot, killer, category, FSB_ReplyType::Yell, FSB_ChatterSource::Bot);
            return;
        }

        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        Unit* killerUnit = ObjectAccessor::GetUnit(*bot, killerGuid);
        std::string killerName = killerUnit ? killerUnit->GetName() : "your foe";

        std::string userMessage;
        if (isHired)
        {
            std::string ownerName = owner->GetName();
            userMessage = Trinity::StringFormat(
                "You just died at the hands of {}. {} was relying on you. "
                "Make a brief, personality-relevant dying comment. "
                "Example style (do not copy): \"{}\"",
                killerName,
                ownerName,
                seedLine.empty() ? "Well, this seems suboptimal." : seedLine);
        }
        else
        {
            userMessage = Trinity::StringFormat(
                "You just died at the hands of {}. "
                "Make a brief, personality-relevant dying comment. "
                "Example style (do not copy): \"{}\"",
                killerName,
                seedLine.empty() ? "Ah yes, the sweet embrace of death." : seedLine);
        }

        ai->genAIFallbackAction = [bot, killerGuid, category]() {
            Unit* killer = ObjectAccessor::GetUnit(*bot, killerGuid);
            FSBChatter::DemandBotChatter(bot, killer, category, FSB_ReplyType::Yell, FSB_ChatterSource::Bot);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        ai->pendingGenAIState->replyType = FSB_ReplyType::Yell;
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched death for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotRevived(Creature* bot)
    {
        if (!bot)
            return;

        FSB_ChatterCategory category = FSB_ChatterCategory::botRevived;

        if (!FSBGenAI::IsEnabled())
        {
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            return;
        }

        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string userMessage = Trinity::StringFormat(
            "You were just resurrected and are back on your feet. "
            "Make a brief, personality-relevant comment about being revived. "
            "Example style (do not copy): \"{}\"",
            seedLine.empty() ? "Back among the living." : seedLine);

        ai->genAIFallbackAction = [bot, category]() {
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched revived for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotRevivedTarget(Creature* healer, ObjectGuid targetGuid)
    {
        if (!healer)
            return;

        FSB_ChatterCategory category = FSB_ChatterCategory::botRevivedTarget;
        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(healer->GetEntry());

        if (!FSBGenAI::IsEnabled())
        {
            Unit* target = ObjectAccessor::GetUnit(*healer, targetGuid);
            FSBChatter::DemandBotChatter(healer, target, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, 0);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(healer->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for healer {}, falling back to hardcoded chatter.", healer->GetName());
            Unit* target = ObjectAccessor::GetUnit(*healer, targetGuid);
            FSBChatter::DemandBotChatter(healer, target, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, 0);
            return;
        }

        std::string seedLine = FSBChatter::GetRandomReply(healer, nullptr, category, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(healer);

        Unit* targetUnit = ObjectAccessor::GetUnit(*healer, targetGuid);
        std::string targetName = targetUnit ? targetUnit->GetName() : "your ally";

        std::string userMessage = Trinity::StringFormat(
            "You just resurrected {} back to life. "
            "Make a brief, personality-relevant comment about the revival. "
            "Example style (do not copy): \"{}\"",
            targetName,
            seedLine.empty() ? "Rise again, friend." : seedLine);

        ai->genAIFallbackAction = [healer, targetGuid, category]() {
            Unit* target = ObjectAccessor::GetUnit(*healer, targetGuid);
            FSBChatter::DemandBotChatter(healer, target, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot, 0);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched revived target for healer {}", healer->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotRevivedSelf(Creature* bot)
    {
        if (!bot)
            return;

        FSB_ChatterCategory category = FSB_ChatterCategory::botRevivedSelf;

        if (!FSBGenAI::IsEnabled())
        {
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            return;
        }

        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string userMessage = Trinity::StringFormat(
            "You just used your own power to resurrect yourself from death. "
            "Make a brief, proud personality-relevant comment about your self-revival. "
            "Example style (do not copy): \"{}\"",
            seedLine.empty() ? "I don't wait for resurrections. I MAKE them." : seedLine);

        ai->genAIFallbackAction = [bot, category]() {
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched revived self for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    static FSB_ChatterCategory GetDistressCategory(FSB_DistressContext context)
    {
        switch (context)
        {
            case FSB_DistressContext::OutOfMana:      return FSB_ChatterCategory::emote_oom;
            case FSB_DistressContext::LowHealth:      return FSB_ChatterCategory::emote_help;
            case FSB_DistressContext::CriticalHealth: return FSB_ChatterCategory::emote_heal;
            default:                                   return FSB_ChatterCategory::chatter_none;
        }
    }

    static char const* GetDistressEmoteString(FSB_DistressContext context)
    {
        switch (context)
        {
            case FSB_DistressContext::OutOfMana:      return "emote:oom";
            case FSB_DistressContext::LowHealth:      return "emote:help";
            case FSB_DistressContext::CriticalHealth: return "emote:heal";
            default:                                   return "";
        }
    }

    static char const* GetDistressDescription(FSB_DistressContext context)
    {
        switch (context)
        {
            case FSB_DistressContext::OutOfMana:
                return "You are completely out of mana in the middle of combat. "
                       "Make a brief, desperate but personality-relevant comment about needing mana.";
            case FSB_DistressContext::LowHealth:
                return "You are in combat and your health has dropped to 50%. "
                       "Make a brief, concerned but personality-relevant comment calling for help.";
            case FSB_DistressContext::CriticalHealth:
                return "You are in combat and critically low on health (~20%). "
                       "Make a brief, urgent but personality-relevant comment begging for healing.";
            default:
                return "";
        }
    }

    void DispatchBotDistress(Creature* bot, FSB_DistressContext context)
    {
        if (!bot)
            return;

        FSB_ChatterCategory category = GetDistressCategory(context);
        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        char const* emoteString = GetDistressEmoteString(context);
        char const* description = GetDistressDescription(context);

        // Always schedule the WoW built-in emote (TEXT_EMOTE_OOM / HELPME / HEALME)
        // This preserves the emote animation and race/gender-specific sound
        FSBEvents::ScheduleBotEventWithChatter(bot, FSB_EVENT_HIRED_TIMED_DUMMY_EMOTE, 3s, 5s, FSB_ReplyType::Say, emoteString, nullptr);

        if (!FSBGenAI::IsEnabled())
        {
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            return;
        }

        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string userMessage = Trinity::StringFormat(
            "{} Example style (do not copy): \"{}\"",
            description,
            seedLine.empty() ? "I'm out of mana and need help!" : seedLine);

        ai->genAIFallbackAction = [bot, category]() {
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched distress for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotWhisperAFK(Creature* bot)
    {
        if (!bot)
            return;

        Player* player = FSBMgr::Get()->GetBotOwner(bot);

        if (!FSBGenAI::IsEnabled())
        {
            if (player)
                FSBChatter::DemandTimedReply(bot, player, FSB_ChatterCategory::whisper_afk, FSB_ReplyType::Whisper, FSB_ChatterSource::Bot);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            if (player)
                FSBChatter::DemandTimedReply(bot, player, FSB_ChatterCategory::whisper_afk, FSB_ReplyType::Whisper, FSB_ChatterSource::Bot);
            return;
        }

        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        std::string seedLine = FSBChatter::GetRandomReply(bot, player, FSB_ChatterCategory::whisper_afk, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string playerName = player ? player->GetName() : "your owner";
        std::string userMessage = Trinity::StringFormat(
            "Your owner {} has been AFK for a while. Whisper them a brief, fun, personality-relevant message checking in or poking fun. "
            "Example style (do not copy): \"{}\"",
            playerName,
            seedLine.empty() ? "Still here, waiting on you..." : seedLine);

        ai->genAIFallbackAction = [bot]() {
            if (Player* owner = FSBMgr::Get()->GetBotOwner(bot))
                FSBChatter::DemandTimedReply(bot, owner, FSB_ChatterCategory::whisper_afk, FSB_ReplyType::Whisper, FSB_ChatterSource::Bot);
        };
        ai->genAIDeliverAction = [bot](std::string const& response) {
            if (Player* owner = FSBMgr::Get()->GetBotOwner(bot))
                bot->Whisper(response, LANG_UNIVERSAL, owner);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched whisper_afk for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotTalk(Creature* bot)
    {
        if (!bot)
            return;

        if (!FSBGenAI::IsEnabled())
        {
            FSBChatter::DemandTimedReply(bot, nullptr, FSB_ChatterCategory::emote_talk, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            FSBChatter::DemandTimedReply(bot, nullptr, FSB_ChatterCategory::emote_talk, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            return;
        }

        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, FSB_ChatterCategory::emote_talk, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string userMessage = Trinity::StringFormat(
            "You're waiting around while your owner is AFK. Make a brief, personality-relevant spoken comment or observation. "
            "Example style (do not copy): \"{}\"",
            seedLine.empty() ? "So. how long are we gonna be here?" : seedLine);

        ai->genAIFallbackAction = [bot]() {
            FSBChatter::DemandTimedReply(bot, nullptr, FSB_ChatterCategory::emote_talk, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched emote_talk for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotMemberDied(Creature* bot, ObjectGuid deadUnitGuid)
    {
        if (!bot)
            return;

        FSB_ChatterCategory category = FSB_ChatterCategory::botMemberDied;

        if (!FSBGenAI::IsEnabled())
        {
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Yell, FSB_ChatterSource::Bot);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Yell, FSB_ChatterSource::Bot);
            return;
        }

        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        Unit* deadUnit = ObjectAccessor::GetUnit(*bot, deadUnitGuid);
        std::string deadName = deadUnit ? deadUnit->GetName() : "one of your companions";

        std::string userMessage = Trinity::StringFormat(
            "One of your group members, {}, has just died. Yell a brief, emotional, personality-relevant reaction to their death. "
            "Example style (do not copy): \"{}\"",
            deadName,
            seedLine.empty() ? "No! Not them!" : seedLine);

        ai->genAIFallbackAction = [bot, category]() {
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Yell, FSB_ChatterSource::Bot);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        ai->pendingGenAIState->replyType = FSB_ReplyType::Yell;
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched member died for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotCooking(Creature* bot)
    {
        if (!bot)
            return;

        FSB_ChatterCategory category = FSB_ChatterCategory::emote_cooking;

        if (!FSBGenAI::IsEnabled())
        {
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            return;
        }

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for bot {}, falling back to hardcoded chatter.", bot->GetName());
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
            return;
        }

        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());
        std::string seedLine = FSBChatter::GetRandomReply(bot, nullptr, category, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(bot);

        std::string userMessage = Trinity::StringFormat(
            "You just lit a campfire and are preparing to cook. Say a brief, personality-relevant comment about cooking or the fire. "
            "Example style (do not copy): \"{}\"",
            seedLine.empty() ? "Fire's ready! Who's hungry?" : seedLine);

        ai->genAIFallbackAction = [bot, category]() {
            FSBChatter::DemandTimedReply(bot, nullptr, category, FSB_ReplyType::Say, FSB_ChatterSource::Bot);
        };
        ai->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = ai->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched emote_cooking for bot {}", bot->GetName());
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

    void DispatchBotSocialReply(Creature* targetBot, ObjectGuid initiatorGuid, FSB_ChatterCategory category)
    {
        if (!targetBot)
            return;

        if (!FSBGenAI::IsEnabled())
        {
            Unit* initiator = ObjectAccessor::GetUnit(*targetBot, initiatorGuid);
            if (initiator)
                if (Creature* initiatorCreature = initiator->ToCreature())
                    FSBChatter::DemandTargetReply(initiatorCreature, targetBot, category, FSB_ReplyType::Say);
            return;
        }

        auto* targetAI = dynamic_cast<FSB_BaseAI*>(targetBot->AI());
        if (!targetAI)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: could not get AI for target bot {}, falling back to hardcoded chatter.", targetBot->GetName());
            Unit* initiator = ObjectAccessor::GetUnit(*targetBot, initiatorGuid);
            if (initiator)
                if (Creature* initiatorCreature = initiator->ToCreature())
                    FSBChatter::DemandTargetReply(initiatorCreature, targetBot, category, FSB_ReplyType::Say);
            return;
        }

        if (targetAI->pendingGenAIState)
        {
            TC_LOG_WARN("scripts.fsb.genai", "FSB GenAI: target bot {} already has pending request, falling back to hardcoded chatter.", targetBot->GetName());
            Unit* initiator = ObjectAccessor::GetUnit(*targetBot, initiatorGuid);
            if (initiator)
                if (Creature* initiatorCreature = initiator->ToCreature())
                    FSBChatter::DemandTargetReply(initiatorCreature, targetBot, category, FSB_ReplyType::Say);
            return;
        }

        Unit* initiator = ObjectAccessor::GetUnit(*targetBot, initiatorGuid);
        Creature* initiatorCreature = initiator ? initiator->ToCreature() : nullptr;
        std::string initiatorName = initiator ? initiator->GetName() : "someone";

        FSB_ChatterType personalityType = FSBMgr::Get()->GetBotChatterTypeForEntry(targetBot->GetEntry());
        std::string seedLine = FSBChatter::GetRandomReply(initiatorCreature, targetBot, category, personalityType, 0, 0);

        std::string systemPrompt = BuildStandardSystemPrompt(targetBot);

        std::string interactionDesc;
        switch (category)
        {
            case FSB_ChatterCategory::emote_joke:  interactionDesc = "told you a joke"; break;
            case FSB_ChatterCategory::emote_kiss:  interactionDesc = "blew you a kiss"; break;
            case FSB_ChatterCategory::emote_flirt: interactionDesc = "flirted with you"; break;
            default:                               interactionDesc = "interacted with you"; break;
        }

        std::string userMessage = Trinity::StringFormat(
            "{} just {}. Respond briefly and in character. "
            "Example style (do not copy): \"{}\"",
            initiatorName,
            interactionDesc,
            seedLine.empty() ? "..." : seedLine);

        std::string dummyEmoteString = FSBChatter::GetDummyEmoteString(category, personalityType);

        targetAI->genAIFallbackAction = [targetBot, initiatorGuid, category]() {
            Unit* initiator = ObjectAccessor::GetUnit(*targetBot, initiatorGuid);
            if (!initiator)
                return;
            Creature* initiatorCreature = initiator->ToCreature();
            if (!initiatorCreature)
                return;
            FSBChatter::DemandTargetReply(initiatorCreature, targetBot, category, FSB_ReplyType::Say);
        };

        targetAI->genAIDeliverAction = [targetBot, targetAI, dummyEmoteString](std::string const& response) {
            targetBot->Say(response, targetAI->botLanguage);
            FSBChatter::PlayDummyEmote(targetBot, dummyEmoteString);
        };

        targetAI->pendingGenAIState = std::make_shared<FSB_BaseAI::GenAIRequestState>();
        auto state = targetAI->pendingGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched {} for target bot {} (initiator {})", category, targetBot->GetName(), initiatorName);
        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }
}
