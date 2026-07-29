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

#ifndef CUSTOM_MONK_DEFINES_H
#define CUSTOM_MONK_DEFINES_H

namespace Custom::Monk
{
    namespace Creatures
    {
        static constexpr uint32 NPC_JADE_SERPENT_STATUE = 60849;
        static constexpr uint32 NPC_BLACK_OX_STATUE    = 61146;
    }

    namespace Spells
    {
        static constexpr uint32 SUMMON_SERPENT_STATUE  = 115313;
        static constexpr uint32 SOOTHING_MIST_OWNER   = 115175;
        static constexpr uint32 SOOTHING_MIST_STATUE  = 198533;
        static constexpr uint32 BLACK_OX_STATUE_AURA  = 163177;
        static constexpr uint32 PROVOKE               = 115546;
    }

    namespace Events
    {
        static constexpr int8 FOLLOW_OWNER = 1;
        static constexpr int8 CHECK_OWNER_SPELL = 2;
    }
}

#endif // CUSTOM_MONK_DEFINES_H
