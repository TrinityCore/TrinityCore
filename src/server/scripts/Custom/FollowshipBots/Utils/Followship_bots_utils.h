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

#include <cmath>
#include <string>
#include <vector>
#include <random>
#include <cstdint>

#include "Creature.h"
#include "CreatureAIImpl.h"
#include "MotionMaster.h"
#include "Player.h"
#include "Unit.h"

#include "Followship_bots_ai_base.h"
#include "Followship_bots_defines.h"
#include "Followship_bots_utils_combat.h"
#include "Followship_bots_utils_gossip.h"
#include "Followship_bots_utils_spells.h"
#include "Followship_bots_utils_stats.h"

#include "Weather.h"


namespace FSBUtils
{
    const char* BotClassToString(FSB_Class cls);
    const char* BotRaceToString(FSB_Race race);
    const char* BotRoleToString(FSB_Roles role);
    const char* ChatterTypeToString(FSB_ChatterType type);
    const char* GenderToString(Gender gender);
    const char* PowerTypeToString(Powers power);

    Classes FSBToTCClass(FSB_Class botClass);
    Races BotRaceToTC(FSB_Race race);

    Team GetTeamFromFSBRace(FSB_Race race);

    uint32 GetFactionForFSBRace(FSB_Race race);

    Language GetLanguageForFSBRace(FSB_Race race);
    Language GetTeamLanguageForFSBRace(FSB_Race race);

    constexpr float SIDE_OFFSET_MAX = float(M_PI) / 6.0f; // +-30 degrees from pure left/right

    // Returns a random angle slightly to the left of the player
    float GetRandomLeftAngle();

    // Returns a random angle slightly to the right of the player
    float GetRandomRightAngle();

    bool TryChargeHire(Player* player, uint32 duration);

    bool BotIsHealerClass(Creature* bot);
    bool BotIsCasterRole(Creature* bot);

    Unit* FindCreatureByName(WorldObject* bot, std::string name, float range = 50.0f);
    std::vector<Creature*> FindNearbyBots(Creature* center, float radius = 300.f);

    bool IsBotInTradeCity(Creature* bot);

    std::string WeatherStateToText(WeatherState state);
}
