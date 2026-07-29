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
#include "Followship_bots_spells_handler.h"

enum class FSBBuffTargetScope
{
    Self,       // cast on the bot
    Group,      // cast on owner + other bots owned by the same player (only if hired)
    BGAllies    // cast on same-faction players/bots within 30 yards in a battleground
};

namespace FSBBuffs
{
    // Predict whether any buff targets exist for the given scope without casting.
    bool BotHasAnyBuffTargets(Creature* bot, FSBBuffTargetScope scope);

    // Try to cast one missing buff. Returns true if a cast was issued this tick.
    bool BotCastGenericBuff(Creature* bot, FSBBuffTargetScope scope, uint32& outSpellId);

    // Druid special path.
    bool BotCastDruidBuffs(Creature* bot, FSBBuffTargetScope scope, uint32& outSpellId);

    // Run one OOC buff tick: self -> group (if hired) -> BG allies (if in BG).
    // Returns true if a buff was cast this tick.
    bool HandlePeriodicBuffs(Creature* bot, uint32& selfBuffTimer, uint32& buffTimer);
}
