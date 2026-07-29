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

#include "GenAI_conversation_prompts.h"
#include "GenAI_client.h"

#include "Followship_bots_ai_base.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_utils.h"

#include "Followship_bots_chat_handler.h"

#include "Containers.h"
#include "DB2Stores.h"
#include "GameTime.h"
#include "Log.h"
#include "Map.h"
#include "Random.h"
#include "StringFormat.h"
#include "Weather.h"
#include "WowTime.h"

#include <random>
#include <thread>
#include <unordered_map>

namespace FSBConvPrompts
{
    // -------------------------------------------------------------------------
    // Topic catalog (formatTemplate + dataSource)
    // -------------------------------------------------------------------------
    ConversationTopic PickRandomTopic()
    {
        static const ConversationTopic topics[] =
        {
            // Joke
            { ConversationTopicCategory::Joke,       ConversationTopicSubCategory::ZoneJoke,          "Make a funny observation about {}",                       TopicDataSource::ZoneFeature },
            { ConversationTopicCategory::Joke,       ConversationTopicSubCategory::NPCJoke,           "Crack a lighthearted joke about {}",                    TopicDataSource::ZoneNPC },
            { ConversationTopicCategory::Joke,       ConversationTopicSubCategory::BossJoke,          "Tell a funny take on a famous boss encounter with {}",  TopicDataSource::GlobalBoss },
            { ConversationTopicCategory::Joke,       ConversationTopicSubCategory::ProfessionJoke,    "Joke about the {} profession and its quirks",             TopicDataSource::GlobalProfession },
            { ConversationTopicCategory::Joke,       ConversationTopicSubCategory::ClassJoke,       "Make a playful joke about {} players",                    TopicDataSource::GlobalClass },
            // Complaint
            { ConversationTopicCategory::Complaint,    ConversationTopicSubCategory::ZoneComplaint,    "Complain about {}",                                       TopicDataSource::ZoneIssue },
            { ConversationTopicCategory::Complaint,    ConversationTopicSubCategory::NPCComplaint,     "Grumble about {}",                                        TopicDataSource::ZoneNPC },
            { ConversationTopicCategory::Complaint,    ConversationTopicSubCategory::ClassComplaint,   "Complain about {}",                                       TopicDataSource::GlobalClass },
            // ZoneEvent
            { ConversationTopicCategory::ZoneEvent,  ConversationTopicSubCategory::ZoneEvent,        "Talk about {} that supposedly happened around here",    TopicDataSource::ZoneEventSubject },
            { ConversationTopicCategory::ZoneEvent,  ConversationTopicSubCategory::NPCEvent,         "Gossip about {} and something they did recently",         TopicDataSource::ZoneNPC },
            // RandomTake / Political
            { ConversationTopicCategory::RandomTake, ConversationTopicSubCategory::FactionOpinion,   "Share a bold or controversial opinion about {}",          TopicDataSource::GlobalFaction },
            { ConversationTopicCategory::RandomTake, ConversationTopicSubCategory::RaceOpinion,        "Give a hot take about {}",                                TopicDataSource::GlobalRace },
            { ConversationTopicCategory::RandomTake, ConversationTopicSubCategory::ClassOpinion,      "Share a strong opinion about {}",                         TopicDataSource::GlobalClass },
            // Question
            { ConversationTopicCategory::Question,   ConversationTopicSubCategory::ThematicQuestion, "Ask the group a curious or playful question about {}",  TopicDataSource::GlobalTheme },
            // Story
            { ConversationTopicCategory::Story,      ConversationTopicSubCategory::AdventureStory,   "Tell a short, exaggerated story about an adventure involving {}", TopicDataSource::ZoneFeature },
            { ConversationTopicCategory::Story,      ConversationTopicSubCategory::BossEncounterStory, "Share a dramatic tale about facing {}",                   TopicDataSource::GlobalBoss },
            // TimeOfDay
            { ConversationTopicCategory::TimeOfDay,  ConversationTopicSubCategory::TimeOfDayComment,   "Comment about the time of day - it's currently {}",       TopicDataSource::InGameTime },
            // Weather
            { ConversationTopicCategory::Weather,    ConversationTopicSubCategory::WeatherComment,     "Talk about the current weather - it's {} right now",       TopicDataSource::CurrentWeather },
        };

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, int(std::size(topics)) - 1);
        return topics[dist(gen)];
    }

    std::string ResolveDataItem(Creature* bot, TopicDataSource source)
    {
        uint32 zoneId = bot->GetZoneId();

        switch (source)
        {
            case TopicDataSource::ZoneFeature:
            {
                auto it = ZoneFeatures.find(zoneId);
                if (it != ZoneFeatures.end() && !it->second.empty())
                    return Trinity::Containers::SelectRandomContainerElement(it->second);
                AreaTableEntry const* area = sAreaTableStore.LookupEntry(zoneId);
                return area ? area->AreaName[LOCALE_enUS] : "this place";
            }
            case TopicDataSource::ZoneNPC:
            {
                auto it = ZoneNPCs.find(zoneId);
                if (it != ZoneNPCs.end() && !it->second.empty())
                    return Trinity::Containers::SelectRandomContainerElement(it->second);
                return "someone around here";
            }
            case TopicDataSource::ZoneIssue:
            {
                auto it = ZoneIssues.find(zoneId);
                if (it != ZoneIssues.end() && !it->second.empty())
                    return Trinity::Containers::SelectRandomContainerElement(it->second);
                return "things around here";
            }
            case TopicDataSource::ZoneEventSubject:
            {
                auto it = ZoneEventSubjects.find(zoneId);
                if (it != ZoneEventSubjects.end() && !it->second.empty())
                    return Trinity::Containers::SelectRandomContainerElement(it->second);
                return "something that happened";
            }
            case TopicDataSource::GlobalBoss:
                return Trinity::Containers::SelectRandomContainerElement(BossNames);
            case TopicDataSource::GlobalProfession:
                return Trinity::Containers::SelectRandomContainerElement(Professions);
            case TopicDataSource::GlobalFaction:
                return Trinity::Containers::SelectRandomContainerElement(Factions);
            case TopicDataSource::GlobalRace:
                return FSBUtils::BotRaceToString(static_cast<FSB_Race>(urand(1, static_cast<int32>(FSB_Race::HaranirHorde))));
            case TopicDataSource::GlobalClass:
                return FSBUtils::BotClassToString(static_cast<FSB_Class>(urand(1, 11)));
            case TopicDataSource::GlobalTheme:
                return Trinity::Containers::SelectRandomContainerElement(Themes);
            case TopicDataSource::InGameTime:
            {
                if (WowTime const* wowTime = GameTime::GetWowTime())
                {
                    int8 hour = wowTime->GetHour();
                    int8 minute = wowTime->GetMinute();
                    if (hour >= 0 && minute >= 0)
                    {
                        char buf[32];
                        const char* period;
                        if (hour >= 5 && hour <= 7)       period = "dawn";
                        else if (hour >= 8 && hour <= 11) period = "morning";
                        else if (hour >= 12 && hour <= 16) period = "afternoon";
                        else if (hour >= 17 && hour <= 19) period = "evening";
                        else                                period = "night";
                        snprintf(buf, sizeof(buf), "%02d:%02d, %s", hour, minute, period);
                        return buf;
                    }
                }
                return "some time of day";
            }
            case TopicDataSource::CurrentWeather:
            {
                if (Map* map = bot->GetMap())
                {
                    WeatherState ws = map->GetZoneWeather(bot->GetZoneId());
                    return FSBUtils::WeatherStateToText(ws);
                }
                return "clear";
            }
            default:
                return "something interesting";
        }
    }

    std::string BuildTopicDescription(Creature* bot, ConversationTopic const& topic)
    {
        std::string item = ResolveDataItem(bot, topic.dataSource);
        return fmt::format(fmt::runtime(topic.formatTemplate), item);
    }

    static std::string GetCategoryNoun(ConversationTopicCategory cat)
    {
        switch (cat)
        {
            case ConversationTopicCategory::Joke:
                return "joke";
            case ConversationTopicCategory::Complaint:
                return "complaint";
            case ConversationTopicCategory::ZoneEvent:
                return "commentary";
            case ConversationTopicCategory::RandomTake:
            case ConversationTopicCategory::Political:
                return "opinion";
            case ConversationTopicCategory::Question:
                return "question";
            case ConversationTopicCategory::Story:
                return "story";
            case ConversationTopicCategory::TimeOfDay:
                return "remark about the time";
            case ConversationTopicCategory::Weather:
                return "remark about the weather";
            default:
                return "remark";
        }
    }

    std::string BuildConversationSystemPrompt(Creature* bot)
    {
        uint32 entry = bot->GetEntry();
        std::string const& botName = bot->GetName();
        FSB_Class botClass = FSBMgr::Get()->GetBotClassForEntry(entry);
        FSB_Race botRace = FSBMgr::Get()->GetBotRaceForEntry(entry);
        FSB_ChatterType chatterType = FSBMgr::Get()->GetBotChatterTypeForEntry(entry);
        Gender botGender = FSBMgr::Get()->GetBotGenderForEntry(entry);

        uint32 zoneId = bot->GetZoneId();
        AreaTableEntry const* areaEntry = sAreaTableStore.LookupEntry(zoneId);
        std::string zoneName = areaEntry ? areaEntry->AreaName[LOCALE_enUS] : "Azeroth";

        std::string prompt = Trinity::StringFormat(
            "You are a character in World of Warcraft named {}.\n"
            "You are a {} {} {} currently in {}.\n"
            "Your personality is {}. This is your defining trait - every reply must clearly sound like a {} person in tone, word choice, and attitude.\n\n"
            "Rules:\n"
            "- Reply in first person, staying fully in the game world.\n"
            "- NEVER refer to yourself as an NPC, bot, AI, or game character.\n"
            "- Keep your reply to 1 sentence only, max 20 words.\n"
            "- Do not copy example lines word-for-word. Invent your own variation.\n"
            "- The current zone ({}) may or may not naturally appear in your reply.",
            botName,
            FSBUtils::GenderToString(botGender),
            FSBUtils::BotRaceToString(botRace),
            FSBUtils::BotClassToString(botClass),
            zoneName,
            FSBUtils::ChatterTypeToString(chatterType),
            FSBUtils::ChatterTypeToString(chatterType),
            zoneName);

        if (WowTime const* wowTime = GameTime::GetWowTime())
        {
            int8 hour = wowTime->GetHour();
            int8 minute = wowTime->GetMinute();
            if (hour >= 0 && minute >= 0)
            {
                char buf[16];
                snprintf(buf, sizeof(buf), "%02d:%02d", hour, minute);
                prompt += "\nThe current in-game time is " + std::string(buf) + ".\n";
            }
        }

        if (Map* map = bot->GetMap())
        {
            WeatherState ws = map->GetZoneWeather(bot->GetZoneId());
            std::string weatherText = FSBUtils::WeatherStateToText(ws);
            if (!weatherText.empty())
                prompt += "The weather here is currently " + weatherText + ".\n";
        }

        return prompt;
    }

    void DispatchConversationTurn(Creature* speaker, FSBChat::ActiveConversation& conv)
    {
        if (!speaker)
            return;

        if (conv.convGenAIState)
            return;

        std::string systemPrompt = BuildConversationSystemPrompt(speaker);

        std::string historyText;
        for (auto const& [name, line] : conv.history)
        {
            if (!historyText.empty())
                historyText += "\n";
            historyText += name + ": " + line;
        }

        std::string topicDesc = conv.topicDescription;
        std::string categoryNoun = GetCategoryNoun(conv.topic.category);

        std::string userMessage;
        if (!historyText.empty())
        {
            auto const& lastEntry = conv.history.back();
            std::string lastSpeaker = lastEntry.first;
            std::string lastLine = lastEntry.second;

            userMessage = Trinity::StringFormat(
                "Topic: {}\n"
                "So far in this conversation:\n{}\n\n"
                "{} just said: \"{}\"\n\n"
                "Write your reply following these three rules:\n"
                "1. RESPOND to what {} actually said - react to their specific point, do not ignore it.\n"
                "2. SOUND like yourself - your own personality and tone, not theirs.\n"
                "3. START DIFFERENTLY - do not open with the same words, structure, or rhythm as their line. Take a fresh angle: push back, ask something new, or twist the subject.\n"
                "One sentence, max 20 words.",
                topicDesc,
                historyText,
                lastSpeaker,
                lastLine,
                lastSpeaker);
        }
        else
        {
            userMessage = Trinity::StringFormat(
                "Topic: {}\n"
                "You are starting this conversation. Open with a {} line that reflects your personality and grabs attention.\n"
                "Keep it to 1 sentence, max 20 words.",
                topicDesc,
                categoryNoun);
        }

        TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: === SYSTEM PROMPT for {} ===\n{}", speaker->GetName(), systemPrompt);
        TC_LOG_DEBUG("scripts.fsb.genai", "FSB GenAI: === USER MESSAGE for {} ===\n{}", speaker->GetName(), userMessage);

        conv.convGenAIState = std::make_shared<ConversationGenAIState>();
        auto state = conv.convGenAIState;
        TC_LOG_INFO("scripts.fsb.genai", "FSB GenAI: dispatched conversation turn for bot {}", speaker->GetName());

        std::thread([systemPrompt, userMessage, state]() {
            std::string result = FSBGenAI::GetBotResponse(systemPrompt, userMessage);
            std::lock_guard<std::mutex> lock(state->mutex);
            state->result = std::move(result);
            state->ready = true;
        }).detach();
    }

}
