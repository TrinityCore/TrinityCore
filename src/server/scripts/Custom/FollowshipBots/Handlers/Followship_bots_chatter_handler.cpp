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

#include "Log.h"

#include "DB2Stores.h"

#include "Followship_bots_config.h"
#include "Followship_bots_mgr.h"

#include "Followship_bots_ai_base.h"

#include "Followship_bots_chatter_handler.h"
#include "Followship_bots_events_handler.h"

std::unordered_map<uint32, std::vector<FSBChatterDBLine>> FSBChatter::BotChatterLinesMap;

namespace FSBChatter
{
    static std::vector<FSBChatterDBLine const*> FilterChatterCandidates(Creature* bot, std::vector<FSBChatterDBLine> const& lines)
    {
        std::vector<FSBChatterDBLine const*> candidates;
        if (!bot)
            return candidates;

        uint32 botZoneId = bot->GetZoneId();
        uint8 botRaceId  = static_cast<uint8>(FSBMgr::Get()->GetBotRaceForEntry(bot->GetEntry()));
        uint8 botClassId = static_cast<uint8>(FSBMgr::Get()->GetBotClassForEntry(bot->GetEntry()));

        for (auto const& line : lines)
        {
            if ((line.zoneId == 0 || line.zoneId == static_cast<int32>(botZoneId)) &&
                (line.fsbRaceId == 0 || line.fsbRaceId == botRaceId) &&
                (line.fsbClassId == 0 || line.fsbClassId == botClassId))
            {
                candidates.push_back(&line);
            }
        }
        return candidates;
    }

    std::string GetRandomEmoteText(Creature* bot, Unit* target, FSB_ChatterEmotes emote)
    {
        for (auto const& entry : FSBEmoteTextTable)
        {
            if (entry.emote == emote)
            {
                if (entry.lines.empty())
                {
                    TC_LOG_ERROR("scripts.fsb.chatter", "FSB: GetRandomEmoteText: No lines found for emote {}", static_cast<uint8>(emote));
                    return "";
                }

                std::string line = entry.lines[urand(0, entry.lines.size() - 1)];

                if (bot)
                    ReplaceAll(line, "{bot}", bot->GetName());
                if (target)
                    ReplaceAll(line, "{target}", target->GetName());

                TC_LOG_DEBUG("scripts.fsb.chatter", "FSB: GetRandomEmoteText: String [{}] selected for emote {}", line, static_cast<uint8>(emote));
                return line;
            }
        }

        TC_LOG_ERROR("scripts.fsb.chatter", "FSB: GetRandomEmoteText: Emote {} not found in FSBEmoteTextTable", static_cast<uint8>(emote));
        return "";
    }

    std::string GetRandomReply(Creature* bot, Unit* target, FSB_ChatterCategory category, FSB_ChatterType chatterType, uint32 spellId, uint8 duration)
    {
        Player* player = FSBMgr::Get()->GetBotOwner(bot);

        // DB-driven path (all categories)
        uint32 key = (static_cast<uint32>(category) << 8) | static_cast<uint32>(chatterType);
        auto it = BotChatterLinesMap.find(key);
        if (it == BotChatterLinesMap.end() || it->second.empty())
        {
            TC_LOG_ERROR("scripts.fsb.chatter", "FSB: No DB chatter lines found for category {} key {}", static_cast<uint8>(category), key);
            return "";
        }

        std::vector<FSBChatterDBLine const*> candidates = FilterChatterCandidates(bot, it->second);
        if (candidates.empty())
        {
            TC_LOG_ERROR("scripts.fsb.chatter", "FSB: DB lines exist for category {} key {} but none match bot zone/race/class filters", static_cast<uint8>(category), key);
            return "";
        }

        FSBChatterDBLine const* chosen = candidates[urand(0, candidates.size() - 1)];
        std::string line = chosen->lineText;

        // Token replacement
        if (bot)
            ReplaceAll(line, "{bot}", bot->GetName());
        if (target)
            ReplaceAll(line, "{target}", target->GetName());
        if (player)
            ReplaceAll(line, "{player}", player->GetName());
        if (spellId)
            ReplaceAll(line, "{spell}", FSBSpellsUtils::GetSpellName(spellId));
        if (duration == 1)
            ReplaceAll(line, "{duration}", "1 hour");
        if (duration > 1)
            ReplaceAll(line, "{duration}", std::to_string(duration) + " hours");

        TC_LOG_DEBUG("scripts.fsb.chatter", "FSB: Chatter GetRandomReply (DB): String [{}] selected for category {} key {}", line, static_cast<uint8>(category), key);
        return line;
    }

    std::string GetDummyEmoteString(FSB_ChatterCategory category, FSB_ChatterType type)
    {
        if (category == FSB_ChatterCategory::emote_joke && type == FSB_ChatterType::Positive)
            return "emote:laugh";
        if ((category == FSB_ChatterCategory::emote_flirt || category == FSB_ChatterCategory::emote_kiss) && type == FSB_ChatterType::Negative)
            return "emote:rudeno";
        if (category == FSB_ChatterCategory::emote_oom)
            return "emote:oom";
        if (category == FSB_ChatterCategory::emote_heal)
            return "emote:heal";
        if (category == FSB_ChatterCategory::emote_help)
            return "emote:help";
        return "";
    }

    void PlayDummyEmote(Creature* bot, const std::string& dummyEmoteString)
    {
        if (!bot || dummyEmoteString.empty())
            return;

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        if (!ai)
            return;

        auto botRace = ai->botRace;
        auto botGender = FSBMgr::Get()->GetBotGenderForEntry(bot->GetEntry());

        TextEmotes tEmote = TEXT_EMOTE_AGREE;
        Emote emote = EMOTE_ONESHOT_NONE;

        if (dummyEmoteString == "emote:laugh")
        {
            tEmote = TEXT_EMOTE_LAUGH;
            emote = EMOTE_ONESHOT_LAUGH;
        }
        else if (dummyEmoteString == "emote:rudeno")
        {
            tEmote = RAND(TEXT_EMOTE_NO, TEXT_EMOTE_RASP);
            emote = (tEmote == TEXT_EMOTE_NO) ? EMOTE_ONESHOT_NO : EMOTE_ONESHOT_RUDE;
        }
        else if (dummyEmoteString == "emote:oom")
            tEmote = TEXT_EMOTE_OOM;
        else if (dummyEmoteString == "emote:heal")
            tEmote = TEXT_EMOTE_HEALME;
        else if (dummyEmoteString == "emote:help")
            tEmote = TEXT_EMOTE_HELPME;

        auto soundInfo = sDB2Manager.GetTextSoundEmoteFor(tEmote, FSBUtils::BotRaceToTC(botRace), botGender, 0);
        if (soundInfo)
            bot->PlayDistanceSound(soundInfo->SoundID);

        bot->HandleEmoteCommand(emote);
    }

    void DemandTimedReply(Creature* bot, Unit* target, FSB_ChatterCategory category, FSB_ReplyType replyType, FSB_ChatterSource chatterSource)
    {
        if (!bot)
            return;

        // we only expect the bot to be dead for those 2 categories
        if ((category != FSB_ChatterCategory::botDeath &&
            category != FSB_ChatterCategory::botDeathHired) &&
            !bot->IsAlive())
            return;

        if (target && !target->IsAlive())
            return;

        FSB_ChatterType type = FSB_ChatterType::None;

        if(target && chatterSource == FSB_ChatterSource::Target)
            type = FSBMgr::Get()->GetBotChatterTypeForEntry(target->GetEntry());

        else if (chatterSource == FSB_ChatterSource::Bot)
            type = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());

        std::string replyString = GetRandomReply(bot, target, category, type, 0);

        TC_LOG_DEBUG("scripts.fsb.chatter", "FSB: Chatter DemandTimedReply: Bot {} String {} selected for category {} and chatterType {}", bot->GetName(), replyString, category, type);

        if (category == FSB_ChatterCategory::botDeath ||
            category == FSB_ChatterCategory::botDeathHired ||
            category == FSB_ChatterCategory::botMemberDied ||
            category == FSB_ChatterCategory::botRevivedTarget)
            target = nullptr;

        FSBEvents::ScheduleBotEventWithChatter(bot, FSB_EVENT_HIRED_TIMED_CHATTER_REPLY, 3s, 5s, replyType, replyString, target);

        std::string dummyEmote = GetDummyEmoteString(category, type);
        if (!dummyEmote.empty())
            FSBEvents::ScheduleBotEventWithChatter(bot, FSB_EVENT_HIRED_TIMED_DUMMY_EMOTE, 3s, 5s, replyType, dummyEmote, target);
    }

    void DemandTargetReply(Creature* bot, Creature* target, FSB_ChatterCategory category, FSB_ReplyType replyType)
    {
        if (!bot)
            return;

        if (!bot->IsAlive())
            return;

        if (!target || !target->IsAlive())
            return;

        FSB_ChatterType type = FSBMgr::Get()->GetBotChatterTypeForEntry(target->GetEntry());

        std::string replyString = GetRandomReply(bot, target, category, type, 0);

        TC_LOG_DEBUG("scripts.fsb.chatter", "FSB: Chatter DemandTargetReply: Bot {} Target {} String {} selected for category {} and chatterType {}", bot->GetName(), target->GetName(), replyString, category, type);

        FSBEvents::ScheduleBotEventWithChatter(bot, FSB_EVENT_HIRED_TIMED_CHATTER_REPLY, 3s, 5s, replyType, replyString, target);

        std::string dummyEmote = GetDummyEmoteString(category, type);
        if (!dummyEmote.empty())
            FSBEvents::ScheduleBotEventWithChatter(bot, FSB_EVENT_HIRED_TIMED_DUMMY_EMOTE, 3s, 5s, replyType, dummyEmote, target);
    }

    void DemandBotChatter(Creature* bot, Unit* target, FSB_ChatterCategory category, FSB_ReplyType replyType, FSB_ChatterSource chatterSource, uint32 spellId, uint16 duration)
    {
        if (!bot)
            return;

        if (urand(0, 99) > FollowshipBotsConfig::configFSBChatterRate)
            return;

        FSB_ChatterType type = FSB_ChatterType::None;

        if (chatterSource == FSB_ChatterSource::Bot)
            type = FSBMgr::Get()->GetBotChatterTypeForEntry(bot->GetEntry());

        std::string chatter = GetRandomReply(bot, target, category, type, spellId, duration);

        if (chatter.empty())
            return;

        auto* ai = dynamic_cast<FSB_BaseAI*>(bot->AI());
        Language botLanguage = ai ? ai->botLanguage : LANG_UNIVERSAL;

        if (replyType == FSB_ReplyType::Say)
            bot->Say(chatter, botLanguage);

        if (replyType == FSB_ReplyType::Yell)
            bot->Yell(chatter, botLanguage);

        if (replyType == FSB_ReplyType::Whisper)
        {
            Player* player = FSBMgr::Get()->GetBotOwner(bot);

            if(player)
                bot->Whisper(chatter, LANG_UNIVERSAL, player);
        }

    }

    void ReplaceAll(std::string& text, const std::string& from, const std::string& to)
    {
        size_t pos = 0;
        while ((pos = text.find(from, pos)) != std::string::npos)
        {
            text.replace(pos, from.length(), to);
            pos += to.length();
        }
    }
}


