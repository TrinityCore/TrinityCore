/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef AIWORLD_WOLFBEHAVIORPOLICY_H
#define AIWORLD_WOLFBEHAVIORPOLICY_H

#include <cmath>
#include <cstdint>

// The first living-world cohort uses the configured WolfLoose species.
// Pure policy: no engine objects and no implicit authority to execute actions.
namespace WolfBehaviorPolicy
{
    constexpr float HungerPerSecond = 0.003f;
    constexpr float HuntHunger = 0.65f;
    constexpr std::uint64_t FeedDurationMs = 5000;
    constexpr std::uint64_t RestDurationMs = 20000;

    inline bool ShouldFlee(float healthPressure, bool alreadyFleeing)
    {
        // Start below 30% health; do not alternate fight/flee while healing.
        return !std::isfinite(healthPressure) || healthPressure >= (alreadyFleeing ? 0.50f : 0.70f);
    }

    inline bool WantsHunt(float hunger, float healthPressure, bool busy)
    {
        return !busy && std::isfinite(hunger) && std::isfinite(healthPressure)
            && hunger >= HuntHunger && !ShouldFlee(healthPressure, false);
    }

    inline bool Elapsed(std::uint64_t now, std::uint64_t started, std::uint64_t duration)
    {
        return now >= started && now - started >= duration;
    }
}

#endif
