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

#include "Define.h"
#include "SharedDefines.h"

#include "Followship_bots_chatter_handler.h"

#include "Random.h"

#include <array>
#include <string>
#include <string_view>

namespace FSBBattlegroundChat
{
    enum class BGChatState : uint8
    {
        None,
        Defend,
        HoldMid,
        Attack,
        Return,
        Protect
    };

    inline std::array<std::string, 20> const SpawnChatLines = {{
        "Hello everyone!",
        "How is everyone today?",
        "Ready to kick some [enemyTeam] ass?",
        "I am gonna rest for a bit while you lot take care of the [enemyTeam].",
        "For the [ownTeam]!!!!",
        "Let's get this win for the [ownTeam]!",
        "Time to show the [enemyTeam] what we're made of.",
        "Good luck everyone, let's make the [ownTeam] proud.",
        "I'll do my part, you do yours.",
        "Another day, another battlefield.",
        "Let's crush the [enemyTeam] and go home.",
        "The [enemyTeam] won't know what hit them.",
        "Stay focused, fight for the [ownTeam].",
        "I'm here to help secure the victory.",
        "No mercy for the [enemyTeam] today.",
        "Let's work together and win this.",
        "The [ownTeam] will prevail!",
        "I'm ready when you are.",
        "Don't let the [enemyTeam] get comfortable.",
        "Victory belongs to the [ownTeam]!"
    }};

    inline std::string FormatChatLine(std::string const& line, Team botTeam)
    {
        std::string result = line;
        std::string own = botTeam == ALLIANCE ? "Alliance" : "Horde";
        std::string enemy = botTeam == ALLIANCE ? "Horde" : "Alliance";
        FSBChatter::ReplaceAll(result, "[ownTeam]", own);
        FSBChatter::ReplaceAll(result, "[enemyTeam]", enemy);
        return result;
    }

    // WSG state chat messages (10+ per category)

    static constexpr inline std::array<std::string_view, 10> WSGDefendMessages = {{
        "I'll stay back and defend the flag room.",
        "Guarding our base, nothing gets past me.",
        "I'm on defense, keep the [enemyTeam] out.",
        "Defending the flag, don't worry about our base.",
        "Standing guard at the flag room.",
        "No one touches our flag while I'm here.",
        "Defense duty, I've got our back.",
        "I'll hold down the fort, you go on offense.",
        "Our flag is safe with me guarding it.",
        "Staying back to protect our base."
    }};

    static constexpr inline std::array<std::string_view, 10> WSGHoldMidMessages = {{
        "I'll hold mid, control the battlefield.",
        "Controlling the center, watch the roads.",
        "Taking mid, keep the [enemyTeam] pinned.",
        "Holding the midfield, no one slips past.",
        "Mid is ours, I'm keeping it that way.",
        "I'll secure the center for the [ownTeam].",
        "Patrolling mid, stay alert.",
        "Midfield control is key, I've got this.",
        "Keeping the center locked down.",
        "I'm on mid duty, covering the crossings."
    }};

    static constexpr inline std::array<std::string_view, 10> WSGAttackMessages = {{
        "Going for their flag, cover me!",
        "I'll run the flag, need backup!",
        "Heading into their base, watch my six.",
        "Time to grab their flag, let's go!",
        "Pushing for the [enemyTeam] flag room.",
        "I'm making a run for the flag, support me.",
        "Attacking their base, don't let them stop me.",
        "Flag run incoming, clear the path!",
        "Going offensive, I'll get that flag.",
        "Rushing their flag, keep them busy!"
    }};

    static constexpr inline std::array<std::string_view, 10> WSGReturnMessages = {{
        "Got the flag! Heading home!",
        "Flag secured, clear a path back!",
        "I have their flag, cover my run!",
        "Bringing the flag home, don't let them catch me!",
        "Flag in hand, running for our base!",
        "I've got the flag, someone clear the route!",
        "Heading back with the flag, protect me!",
        "Flag captured, sprinting home now!",
        "On my way back with their flag, escort me!",
        "Got it! Making a break for our base!"
    }};

    static constexpr inline std::array<std::string_view, 10> WSGProtectMessages = {{
        "I'll protect the flag carrier!",
        "Covering the runner, stay close!",
        "Escorting the carrier, don't let them through!",
        "Keeping the flag carrier safe, watch for attackers!",
        "I'm on escort duty, nobody touches our runner!",
        "Protecting our flag carrier at all costs!",
        "Stay near the carrier, we can't lose this!",
        "Forming up around the flag runner, let's move!",
        "I've got the carrier's back, push forward!",
        "Shielding our runner, keep the [enemyTeam] away!"
    }};

    // AB state chat messages (10 per category, with [node] placeholder)

    static constexpr inline std::array<std::string_view, 10> ABAttackMessages = {{
        "Heading to the [node], need backup!",
        "Rushing the [node], cover me!",
        "Going for the [node], let's take it!",
        "Assaulting the [node], don't let them stop us!",
        "Pushing the [node], send help if you can!",
        "I'm on my way to the [node], watch my flank!",
        "Time to cap the [node], let's move!",
        "Attacking the [node], keep the [enemyTeam] busy!",
        "Making a play for the [node], support me!",
        "The [node] is ours for the taking, charging in!"
    }};

    static constexpr inline std::array<std::string_view, 10> ABDefendMessages = {{
        "Holding the [node], don't let them through!",
        "Defending the [node], I've got this!",
        "Staying at the [node], nothing gets past me.",
        "Guarding the [node], we can't lose it!",
        "I'm on defense at the [node], hold the line!",
        "The [node] is safe with me, focus elsewhere.",
        "Locking down the [node], no [enemyTeam] getting in!",
        "Standing guard at the [node], stay sharp!",
        "Keeping the [node] secure, don't worry about this one.",
        "Defense duty at the [node], I'll hold it down."
    }};

    inline std::string GetABNodeName(uint8 abState)
    {
        switch (abState)
        {
        case 1:  return "Stables";
        case 2:  return "Gold Mine";
        case 3:  return "Lumber Mill";
        case 4:  return "Blacksmith";
        case 5:  return "Farm";
        case 6:  return "Stables";
        case 7:  return "Gold Mine";
        case 8:  return "Lumber Mill";
        case 9:  return "Blacksmith";
        case 10: return "Farm";
        default: return "a node";
        }
    }

    inline std::string GetStateChatMessage(uint32 bgTypeId, Team botTeam, BGChatState state,
        std::string const& nodeName = "")
    {
        if (state == BGChatState::None)
            return "";

        std::string_view msg;

        if (bgTypeId == BATTLEGROUND_WS || bgTypeId == BATTLEGROUND_WG_CTF)
        {
            switch (state)
            {
            case BGChatState::Defend:
                msg = WSGDefendMessages[urand(0, WSGDefendMessages.size() - 1)];
                break;
            case BGChatState::HoldMid:
                msg = WSGHoldMidMessages[urand(0, WSGHoldMidMessages.size() - 1)];
                break;
            case BGChatState::Attack:
                msg = WSGAttackMessages[urand(0, WSGAttackMessages.size() - 1)];
                break;
            case BGChatState::Return:
                msg = WSGReturnMessages[urand(0, WSGReturnMessages.size() - 1)];
                break;
            case BGChatState::Protect:
                msg = WSGProtectMessages[urand(0, WSGProtectMessages.size() - 1)];
                break;
            default:
                break;
            }
        }
        else if (bgTypeId == BATTLEGROUND_AB || bgTypeId == BATTLEGROUND_DOM_AB ||
                 bgTypeId == BATTLEGROUND_AB_CS || bgTypeId == BATTLEGROUND_BRAWL_AB2)
        {
            switch (state)
            {
            case BGChatState::Attack:
                msg = ABAttackMessages[urand(0, ABAttackMessages.size() - 1)];
                break;
            case BGChatState::Defend:
                msg = ABDefendMessages[urand(0, ABDefendMessages.size() - 1)];
                break;
            default:
                break;
            }
        }

        if (msg.empty())
            return "";

        std::string result = FormatChatLine(std::string(msg), botTeam);
        if (!nodeName.empty())
            FSBChatter::ReplaceAll(result, "[node]", nodeName);
        return result;
    }
}
