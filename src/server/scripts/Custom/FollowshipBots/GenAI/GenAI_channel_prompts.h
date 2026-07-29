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

#include <deque>
#include <string>
#include <vector>

class Creature;
class Player;

#include "Followship_bots_defines.h"
#include "GenAI_chat_memory.h"

namespace FSBChannelPrompts
{
    struct BotChatContext
    {
        uint32 entry = 0;
        uint8 level = 0;
        uint32 zoneId = 0;
        uint32 areaId = 0;
        FSB_Class botClass = FSB_Class::None;
        FSB_Race botRace = FSB_Race::None;
        FSB_ChatterType personality = FSB_ChatterType::None;
        FSB_Roles role = FSB_Roles::FSB_ROLE_NONE;
        uint32 goldGivenCount = 0;
        uint32 lastGoldGiveTime = 0;
        std::string botName;
        bool allowGold = false;
        std::string inGameTime;
        int8 inGameHour = -1;
        std::string weather;
        uint32 weatherStateRaw = 0;
    };
    inline const std::vector<std::string> TradeSellingExamples =
    {
        "WTS [ITEM] PST",
        "Anyone need [ITEM]?",
        "Offloading [ITEM] come find me",
        "Want [ITEM]? Message me",
        "For sale: [ITEM]",
        "Cheap [ITEM] going fast",
        "Grab [ITEM] before I vendor it",
        "Need [ITEM]? Hit me up",
        "Selling [ITEM] in [LOCATION]",
        "[ITEM] available, first come first serve",
        "WTT [ITEM] for something cool",
        "Clearing out [ITEM]"
    };

    inline const std::vector<std::string> TradeBuyingExamples =
    {
        "WTB [ITEM] PST",
        "Wanna buy [ITEM]",
        "Need [ITEM] ASAP",
        "Anyone have [ITEM]?",
        "Anyone selling [ITEM]?",
        "Buying [ITEM] hit me up",
        "Looking for [ITEM]",
        "LF [ITEM] will pay well",
        "Need [ITEM] send price",
        "WTB [ITEM] in [LOCATION]"
    };

    inline const std::vector<std::string> TradeFreeExamples =
    {
        "Giving away [ITEM] for free",
        "Free [ITEM] near the mailbox",
        "Who wants [ITEM]?",
        "Take [ITEM] off my hands",
        "[ITEM] going free first come first serve",
        "Want [ITEM]? It's free"
    };

    inline const std::vector<std::string> LFGDungeonExamples =
    {
        "LFM [DUNGEON]",
        "LFG [DUNGEON] PST",
        "Need group for [DUNGEON]",
        "Forming group for [DUNGEON]",
        "Anyone up for [DUNGEON]?",
        "Running [DUNGEON] need more",
        "Looking for more for [DUNGEON]",
        "[CLASS] looking for [DUNGEON] group",
        "[DUNGEON] run forming now",
        "Join me for [DUNGEON]",
        "[DUNGEON] - need healer and dps",
        "Speed run [DUNGEON] anyone?"
    };

    inline const std::vector<std::string> LFGRaidExamples =
    {
        "LFR [DUNGEON]",
        "Looking for raid for [DUNGEON]",
        "Need raiders for [DUNGEON]",
        "Forming raid for [DUNGEON]",
        "Assembling raid for [DUNGEON]",
        "[DUNGEON] raid group forming",
        "[DUNGEON] - recruiting dps and healers",
        "Raid [DUNGEON] tonight need more",
        "[CLASS] lf raid for [DUNGEON]",
        "Anyone wanna raid [DUNGEON]?",
        "[DUNGEON] progression run forming",
        "Join the [DUNGEON] raid"
    };

    // General chat example pools
    inline const std::vector<std::string> GeneralZoneExamples =
    {
        "{area} sure is lively today",
        "I love the atmosphere in {area}",
        "{area} never gets old",
        "Wish {area} had a better inn",
        "Can't wait to leave {area}",
        "The guards in {area} are on edge lately",
        "{area} looks different at night",
        "Anyone else love the music in {area}?"
    };

    inline const std::vector<std::string> GeneralLoreExamples =
    {
        "Remember the Corrupted Blood incident?",
        "At least I have chicken...",
        "50 DKP minus! Classic wipe",
        "Did someone say Thunderfury?",
        "Leeroy Jenkins would charge this mob",
        "Illegal Danish was peak WoW cinema",
        "The AQ gate opening lag was unreal",
        "Bubblehearth was the ultimate escape",
        "The South Park episode was spot on",
        "Thunderfury, Blessed Blade of the Windseeker",
        "Many whelps, handle it!",
        "Arcanite Reaper... HOOOOO!"
    };

    inline const std::vector<std::string> GeneralClassExamples =
    {
        "Being a [CLASS] is tough sometimes",
        "[CLASS] problems: running out of mana",
        "Every [CLASS] needs a healer friend",
        "I rolled [CLASS] because it looked cool",
        "[CLASS] main since vanilla",
        "Being [CLASS] is underrated",
        "[CLASS] life chose me",
        "Anyone else [CLASS] here?"
    };

    inline const std::vector<std::string> GeneralNPCExamples =
    {
        "Thrall really let the Horde down in BfA",
        "Jaina has been through so much",
        "Sylvanas did nothing wrong... or did she?",
        "Illidan was right all along",
        "Varian's sacrifice still hits hard",
        "Anduin needs to grow a spine",
        "Tyrande went full vengeance mode",
        "Genn Greymane needs to chill",
        "Bolvar as the Lich King was wild",
        "Khadgar's beard has its own fan club"
    };

    inline const std::vector<std::string> GeneralPvPExamples =
    {
        "Alterac Valley lasted 8 hours minimum",
        "Southshore vs Tarren Mill was true world PvP",
        "High Warlord grind was brutal",
        "Grand Marshal title meant no sleep",
        "Warsong Gulch flag running was an art",
        "Nothing beats a good world PvP brawl",
        "Arathi Basin was my favorite battleground",
        "Eye of the Storm was chaos incarnate"
    };

    inline const std::vector<std::string> GeneralSocialExamples =
    {
        "Anyone else miss old Azeroth?",
        "What's your favorite expansion?",
        "Leveling an alt is surprisingly fun",
        "The economy is weird right now",
        "Guild recruitment is impossible these days",
        "Anyone want to group up for quests?",
        "Vanilla was better, fight me",
        "The new patch changed everything"
    };

    inline const std::vector<std::string> GeneralWorldExamples =
    {
        "It's getting dark, better watch the roads",
        "This rain never stops in {area}",
        "Beautiful morning in {area}",
        "The stars look amazing tonight",
        "Fog is rolling in through {area}",
        "Perfect weather for grinding in {area}",
        "Getting chilly as the sun sets"
    };

    inline const std::vector<std::string> GeneralAchievementExamples =
    {
        "Finally got [ACHIEVEMENT], took forever",
        "Anyone else working toward [ACHIEVEMENT]?",
        "[ACHIEVEMENT] was harder than it looks",
        "Proud owner of [ACHIEVEMENT]",
        "[ACHIEVEMENT] complete, what's next?",
        "Grinding for [ACHIEVEMENT] all week"
    };

    // Time-of-day example pools (5 periods, 10 examples each)
    inline const std::vector<std::string> GeneralDawnExamples =
    {
        "The sunrise is beautiful today",
        "Dawn light on the water is stunning",
        "Early morning mist, love it",
        "First light always gets me going",
        "Nothing like a dawn patrol to start the day",
        "The sky is turning pink, gorgeous",
        "Up before the sun, as usual",
        "Morning dew on the grass smells amazing",
        "Dawn is my favorite time to explore",
        "Watching the sun come up over the hills"
    };

    inline const std::vector<std::string> GeneralMorningExamples =
    {
        "Bright morning, perfect for adventuring",
        "Morning air really wakes you up",
        "Love the quiet mornings around here",
        "Sun's up, time to get moving",
        "Clear skies this morning, great day ahead",
        "Morning light makes everything look better",
        "Good morning everyone, ready for some quests",
        "Fresh morning breeze, can't beat it",
        "The morning sun feels nice after last night",
        "Nothing like a morning stroll through the zone"
    };

    inline const std::vector<std::string> GeneralAfternoonExamples =
    {
        "Sun is high, perfect time for adventure",
        "Afternoon heat is no joke around here",
        "Long shadows coming, afternoon already",
        "Perfect afternoon for a long journey",
        "The midday sun is beating down today",
        "Afternoon grind, anyone else working?",
        "Warm afternoon, ideal weather for exploring",
        "Sun's still high, plenty of daylight left",
        "Afternoon light makes the zone look golden",
        "Could use a break from this afternoon heat"
    };

    inline const std::vector<std::string> GeneralEveningExamples =
    {
        "Sun's going down, evening already",
        "Twilight colors are amazing tonight",
        "Evening is the best time to relax",
        "Getting dark, should probably wrap up soon",
        "Love the evening breeze around here",
        "Dusk is falling, time to head back",
        "The evening sky looks incredible today",
        "Sunset over the mountains, breathtaking",
        "Evening shadows creeping in, kind of eerie",
        "Perfect evening for a drink at the inn"
    };

    inline const std::vector<std::string> GeneralNightExamples =
    {
        "Stars are bright tonight",
        "Should probably find an inn soon",
        "Night patrols are the worst",
        "It's getting late, better watch the roads",
        "Midnight and still grinding",
        "The night sky is so clear out here",
        "Dark roads are dangerous, stay alert",
        "Nighttime really changes this place",
        "Moonlight on the water is gorgeous",
        "Late night adventuring has its own charm"
    };

    // Weather example pools (15 WeatherState values, 10 examples each)
    inline const std::vector<std::string> GeneralWeatherFineExamples =
    {
        "Love the clear skies right now",
        "Perfect weather for a long journey",
        "Can't complain about this sunshine",
        "Clear skies, smooth sailing today",
        "Beautiful day, not a cloud in sight",
        "This weather is just perfect",
        "Clear and bright, love it",
        "Perfect day to be out and about",
        "Nothing but blue skies today",
        "This fine weather is a rare gift"
    };

    inline const std::vector<std::string> GeneralWeatherFogExamples =
    {
        "The fog is thick enough to cut",
        "Can barely see anything in this fog",
        "Fog rolling in, kind of spooky",
        "This fog makes everything feel mysterious",
        "Careful out there, fog's reducing visibility",
        "Love the eerie atmosphere the fog brings",
        "Fog like this, anything could be lurking",
        "The fog really changes the mood around here",
        "Hard to navigate in this thick fog",
        "Foggy days have their own charm"
    };

    inline const std::vector<std::string> GeneralWeatherDrizzleExamples =
    {
        "Wish it would stop drizzling already",
        "Just a light drizzle, not too bad",
        "This drizzle is annoying but manageable",
        "Light rain, nothing to worry about",
        "The drizzle makes everything slippery",
        "Not quite rain but still getting wet",
        "This drizzle is messing up my gear",
        "A little drizzle never hurt anyone",
        "Drizzle again? Typical around here",
        "At least it's not a full downpour yet"
    };

    inline const std::vector<std::string> GeneralWeatherLightRainExamples =
    {
        "Light rain, good day to stay indoors",
        "The rain is gentle today, kind of nice",
        "Light rain won't stop me from questing",
        "Enjoying the light rain actually",
        "A little rain never hurt anyone",
        "The rain makes the roads slippery though",
        "Light rain freshens up the air",
        "Rain or shine, still adventuring",
        "This light rain is kind of peaceful",
        "Good thing it's only light rain"
    };

    inline const std::vector<std::string> GeneralWeatherMediumRainExamples =
    {
        "This rain is relentless today",
        "Steady rain all day, soaking wet",
        "The rain won't let up, typical",
        "Medium rain, time to find some cover",
        "Rain like this makes questing miserable",
        "The rain is really coming down now",
        "Should have brought a bigger cloak",
        "This rain is going to ruin my armor",
        "Nothing but rain, rain, rain today",
        "At least the rain keeps the mobs away"
    };

    inline const std::vector<std::string> GeneralWeatherHeavyRainExamples =
    {
        "This heavy rain is brutal",
        "Can barely see through this downpour",
        "Heavy rain, should find shelter fast",
        "The rain is hammering down out here",
        "This downpour is no joke",
        "Heavy rain flooding the roads already",
        "Never seen rain this heavy around here",
        "The storm is really letting loose now",
        "Heavy rain makes everything harder",
        "Drenched to the bone in this downpour"
    };

    inline const std::vector<std::string> GeneralWeatherLightSnowExamples =
    {
        "Light snow makes everything look peaceful",
        "A dusting of snow, quite pretty",
        "Light snow falling, love the look",
        "The snow is starting to come down",
        "Light snow, not too cold yet",
        "Snowflakes drifting down, kind of magical",
        "Light snow covering the ground nicely",
        "The first snow is always special",
        "Light snow makes the zone look beautiful",
        "Snow starting to fall, better bundle up"
    };

    inline const std::vector<std::string> GeneralWeatherMediumSnowExamples =
    {
        "Snow is really coming down now",
        "The snow is piling up fast",
        "Steady snowfall, getting cold out here",
        "Snow everywhere, hard to see the path",
        "This snow is making travel difficult",
        "Medium snow, time to find a warm inn",
        "The snowfall is beautiful but freezing",
        "Snow this thick slows everything down",
        "Pretty sure I'm lost in this snow",
        "The snow just keeps falling"
    };

    inline const std::vector<std::string> GeneralWeatherHeavySnowExamples =
    {
        "Heavy snow, can barely see ahead",
        "This blizzard is intense",
        "Heavy snow blocking the roads",
        "The snow is waist deep in places",
        "Heavy snowfall, should find shelter now",
        "Blizzard conditions out here, stay safe",
        "The snow is coming down so hard",
        "Heavy snow makes everything a struggle",
        "Can't see two feet in this snowstorm",
        "This heavy snow is no joke"
    };

    inline const std::vector<std::string> GeneralWeatherLightSandstormExamples =
    {
        "Light sandstorm blowing in, gritty",
        "Sand in the air, better cover up",
        "This light sandstorm stings the eyes",
        "Sand starting to swirl around",
        "Light sandstorm, annoying but manageable",
        "The sand is getting everywhere already",
        "Light sandstorm picking up",
        "Sand in the wind, gritty day",
        "This sandstorm is messing up my gear",
        "Light sand in the air, unpleasant"
    };

    inline const std::vector<std::string> GeneralWeatherMediumSandstormExamples =
    {
        "Sandstorm blowing in, better find cover",
        "This sandstorm is getting serious",
        "Medium sandstorm, can barely see",
        "The sand is whipping around hard",
        "Sandstorm this bad ruins visibility",
        "Should have stayed inside for this sandstorm",
        "The sandstorm is relentless today",
        "Sand everywhere, this is miserable",
        "Medium sandstorm makes travel dangerous",
        "The sand is stinging my face out here"
    };

    inline const std::vector<std::string> GeneralWeatherHeavySandstormExamples =
    {
        "Heavy sandstorm, can't see a thing",
        "This sandstorm is a full blizzard of sand",
        "Heavy sandstorm, totally blinded out here",
        "The sand is tearing at everything",
        "Worst sandstorm I've seen in ages",
        "Heavy sandstorm, need to find shelter now",
        "Can't breathe in this sandstorm",
        "The heavy sand is burying the roads",
        "This sandstorm is absolutely brutal",
        "Heavy sandstorm, no visibility at all"
    };

    inline const std::vector<std::string> GeneralWeatherThunderExamples =
    {
        "Thunderstorm rolling in, dramatic stuff",
        "The thunder is shaking the ground",
        "Lightning just struck nearby, yikes",
        "Thunderstorm makes everything intense",
        "The storm is really cracking out there",
        "Thunder and lightning, quite a show",
        "This thunderstorm is kind of exciting",
        "The thunder rattles your bones",
        "Storm's right overhead, better stay low",
        "Thunderstorm weather, stay safe everyone"
    };

    inline const std::vector<std::string> GeneralWeatherBlackRainExamples =
    {
        "Black rain, this is unsettling",
        "The rain looks wrong, dark and twisted",
        "Black rain falling, something's not right",
        "This black rain gives me the creeps",
        "Never seen rain this dark before",
        "Black rain, the sky looks corrupted",
        "The dark rain is spreading dread",
        "Black rain makes everything feel cursed",
        "This black rain is deeply wrong",
        "The rain is black, what's happening"
    };

    inline const std::vector<std::string> GeneralWeatherBlackSnowExamples =
    {
        "Black snow, this can't be natural",
        "The snow is dark, something is very wrong",
        "Black snow falling, this is ominous",
        "Never seen black snow before, terrifying",
        "The dark snow feels corrupted",
        "Black snow covering everything in darkness",
        "This black snow is deeply disturbing",
        "The snow is black, the end must be near",
        "Black snow, the land feels tainted",
        "Dark snow falling, this is a bad omen"
    };

    struct BotChatResponse
    {
        std::string reply;
        std::string action = "none";
        uint32 amount = 0;
    };

    struct PlayerSnapshot
    {
        std::string name;
        uint8       race = 0;
        uint8       playerClass = 0;
        uint32      level = 0;
    };

    // --- Async-ready context structs (by-value, safe to pass to threads) ---
    struct TradeChatContext
    {
        std::string systemPrompt;
        std::string userPrompt;
        std::string itemLink;
        std::string itemName;
        std::string areaName;
    };

    struct LFGChatContext
    {
        std::string systemPrompt;
        std::string userPrompt;
        std::string dungeonName;
    };

    struct GeneralChatContext
    {
        std::string systemPrompt;
        std::string userPrompt;
        std::string placeholder;
        std::string replacement;
    };

    // Prepare (main thread): gather data from Creature*, build prompts, use urand
    TradeChatContext PrepareTradeMessage(Creature* bot);
    LFGChatContext PrepareLFGMessage(Creature* bot);
    GeneralChatContext PrepareGeneralMessage(BotChatContext const& ctx);

    // Generate (worker thread): call LLM API, do post-processing — no TC object access
    std::string GenerateTradeMessage(TradeChatContext const& ctx);
    std::string GenerateLFGMessage(LFGChatContext const& ctx);
    std::string GenerateGeneralMessage(GeneralChatContext const& ctx);

    BotChatResponse GenerateReplyToPlayer(BotChatContext const& ctx, PlayerSnapshot const& player, std::string const& playerMsg,
        std::deque<BotChatMemoryEntry> const& memory);
}
