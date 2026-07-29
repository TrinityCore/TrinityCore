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

#include "Creature.h"
#include "Followship_bots_defines.h"
#include "Followship_bots_chatter_handler.h"

class FSB_BaseAI;

namespace FSBGenAIPrompts
{
    enum class FSB_AcknowledgeContext
    {
        FollowDistanceClose,
        FollowDistanceNormal,
        FollowDistanceWide,
        FollowAngleFront,
        FollowAngleBehind,
        FollowAngleRight,
        FollowAngleLeft,
        StayCommand,
        FollowCommand,
        LanguageCommand
    };

    void DispatchBotInfoRequest(Creature* bot);
    void DispatchBotRoleAcknowledge(Creature* bot);
    void DispatchBotAcknowledge(Creature* bot, FSB_AcknowledgeContext context);
    void DispatchBotDismissed(Creature* bot);
    void DispatchBotHired(Creature* bot, uint32 durationHours);
    void DispatchBotRecovery(Creature* bot, uint32 spellId);
    void DispatchBotBuff(Creature* bot, ObjectGuid targetGuid, uint32 spellId);
    void DispatchBotPotion(Creature* bot, uint32 spellId, bool isManaPotion);
    void DispatchBotHeal(Creature* bot, ObjectGuid targetGuid, uint32 spellId);
    void DispatchBotCombatSpell(Creature* bot, ObjectGuid targetGuid, uint32 spellId);
    void DispatchBotTargetKilled(Creature* bot, ObjectGuid victimGuid);
    void DispatchBotDeath(Creature* bot, ObjectGuid killerGuid);
    void DispatchBotRevived(Creature* bot);
    void DispatchBotRevivedTarget(Creature* healer, ObjectGuid targetGuid);
    void DispatchBotRevivedSelf(Creature* bot);

    enum class FSB_DistressContext
    {
        OutOfMana,
        LowHealth,
        CriticalHealth
    };

    void DispatchBotDistress(Creature* bot, FSB_DistressContext context);
    void DispatchBotWhisperAFK(Creature* bot);
    void DispatchBotTalk(Creature* bot);
    void DispatchBotMemberDied(Creature* bot, ObjectGuid deadUnitGuid);
    void DispatchBotCooking(Creature* bot);
    void DispatchBotSocialReply(Creature* targetBot, ObjectGuid initiatorGuid, FSB_ChatterCategory category);

    std::string BuildStandardSystemPrompt(Creature* bot);
}
