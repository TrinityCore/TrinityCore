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

#include <string>
#include <unordered_map>
#include <vector>

#include "Creature.h"

#include "Followship_bots_defines.h"

enum FSB_ChatterCategory
{
    chatter_none,
    targetKilled,
    targetKilledHired,
    botDismissed,
    botAcknowledge,
    botFollow,
    botStay,
    botMemberDied,
    botRevived,
    botRevivedSelf,
    botDeathHired,
    botDeath,
    botHiredPermanent,
    botRevivedTarget,
    botHealTarget,
    botHealSelf,
    botCombatMana,
    botCombatHealth,
    botCombatSpell,
    botBuffSelf,
    botBuffTarget,
    botOOCRecovery,
    botOOCRecoveryHired,
    botHire,

    emote_oom,
    emote_heal,
    emote_help,
    emote_whistle,
    emote_sleep,
    emote_sigh,

    emote_kiss,
    emote_flirt,
    emote_joke,
    emote_talk,
    emote_cooking,

    whisper_afk,
    

};

enum class FSB_ChatterEmotes : uint8
{
    emote_kiss,
    emote_whistle,
    emote_flirt,
    emote_joke,
    emote_sigh,
    emote_sleep,
    // ... future emotes
};

struct FSBEmoteTextEntry
{
    FSB_ChatterEmotes emote;
    std::vector<std::string> lines;
};

enum FSB_ChatterSource
{
    None,
    Bot,
    Target
};

namespace FSBChatter
{
    std::string GetRandomReply(Creature* bot, Unit* target, FSB_ChatterCategory category, FSB_ChatterType chatterType, uint32 spellId = 0, uint8 duration = 0);
    void DemandTimedReply(Creature* bot, Unit* target, FSB_ChatterCategory category, FSB_ReplyType replyType, FSB_ChatterSource chatterSource);
    void DemandTargetReply(Creature* bot, Creature* target, FSB_ChatterCategory category, FSB_ReplyType replyType);
    void DemandBotChatter(Creature* bot, Unit* target, FSB_ChatterCategory category, FSB_ReplyType replyType = FSB_ReplyType::Say, FSB_ChatterSource chatterSource = FSB_ChatterSource::None, uint32 spellId = 0, uint16 duration = 0);

    std::string GetDummyEmoteString(FSB_ChatterCategory category, FSB_ChatterType type);
    void PlayDummyEmote(Creature* bot, const std::string& dummyEmoteString);
    void ReplaceAll(std::string& text, const std::string& from, const std::string& to);

    std::string GetRandomEmoteText(Creature* bot, Unit* target, FSB_ChatterEmotes emote);

    extern std::unordered_map<uint32, std::vector<FSBChatterDBLine>> BotChatterLinesMap;
    inline std::vector<FSBEmoteTextEntry> FSBEmoteTextTable =
    {
        {
            FSB_ChatterEmotes::emote_kiss,
            {
                "{bot} blows a kiss to {target}.",
                "{bot} sends a warm kiss toward {target}.",
                "{bot} winks and blows a kiss at {target}.",
            }
        },
        {
            FSB_ChatterEmotes::emote_flirt,
            {
                "{bot} gives {target} a playful wink.",
                "{bot} flashes {target} a charming smile.",
                "{bot} tilts their head and gives {target} a flirty grin.",
                "{bot} shoots {target} a mischievous look.",
                "{bot} gives {target} a slow, teasing wink.",
                "{bot} smirks softly in {target}'s direction.",
                "{bot} gives {target} a warm, inviting smile.",
                "{bot} glances at {target} with a hint of playful interest.",
                "{bot} offers {target} a coy, knowing smile.",
                "{bot} gives {target} a subtle but unmistakably flirty look."
            }
        },
        {
            FSB_ChatterEmotes::emote_joke,
            {
                "{bot} tells a joke.",
                "{bot} tells a funny quote.",
                "{bot} whispers a small joke.",
                "{bot} makes a funny face and jokes.",
                "{bot} tells a joke to themselves.",
                "{bot} tells a funny story.",
                "{bot} recollects a funny event."
            }
        },
        {
            FSB_ChatterEmotes::emote_whistle,
            {
                "{bot} whistles idly.",
                "{bot} lets out a long, bored whistle.",
                "{bot} whistles a wandering little tune.",
                "{bot} glances around and whistles softly.",
                "{bot} taps their foot and whistles impatiently.",
                "{bot} hums a tune before breaking into a whistle.",
                "{bot} whistles to pass the time.",
                "{bot} looks around, clearly bored, and whistles.",
                "{bot} gives a casual whistle into the air.",
                "{bot} whistles while waiting for something to happen."
            }
        },
        {
            FSB_ChatterEmotes::emote_sigh,
            {
                "{bot} lets out a long, weary sigh.",
                "{bot} sighs softly, looking a bit drained.",
                "{bot} exhales heavily, clearly tired of it all.",
                "{bot} sighs and stares off into the distance.",
                "{bot} releases a deep, frustrated sigh.",
                "{bot} sighs as if carrying the weight of the world.",
                "{bot} takes a slow breath and sighs quietly.",
                "{bot} sighs, sounding resigned.",
                "{bot} gives a tired sigh and shakes their head.",
                "{bot} sighs, clearly not impressed."
            }
        },
        {
            FSB_ChatterEmotes::emote_sleep,
            {
                "{bot} yawns loudly.",
                "{bot} lays down for a nap.",
                "{bot} feels sleepy.",
                "{bot} goes for a power nap.",
                "{bot} uses the ground as a bed.",
                "{bot} lays down to rest.",
                "{bot} takes a quick rest."
            }
        },
    };
    // key = (category << 8) | chatter_type
}
