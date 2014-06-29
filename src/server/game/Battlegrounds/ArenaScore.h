/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_ARENA_SCORE_H
#define TRINITY_ARENA_SCORE_H

#include "BattlegroundScore.h"
#include "SharedDefines.h"

struct ArenaScore : public BattlegroundScore
{
    friend class BattlegroundBE;
    friend class BattlegroundDS;
    friend class BattlegroundNA;
    friend class BattlegroundRL;
    friend class BattlegroundRV;

    protected:
        ArenaScore(uint64 playerGuid, uint32 team) : BattlegroundScore(playerGuid), TeamId(team == ALLIANCE ? 1 : 0) { }

        void AppendToPacket(WorldPacket& data) final
        {
            data << uint64(PlayerGuid);

            data << uint32(KillingBlows);
            data << uint8(TeamId);
            data << uint32(DamageDone);
            data << uint32(HealingDone);

            BuildObjectivesBlock(data);
        }

        void BuildObjectivesBlock(WorldPacket& data) final
        {
            data << uint32(0); // Objectives Count
        }

        // For Logging purpose
        std::string ToString() const override
        {
            std::ostringstream stream;
            stream << "Damage done: " << DamageDone << ", Healing done: " << HealingDone << ", Killing blows: " << KillingBlows;
            return stream.str();
        }

        uint8 TeamId; // bgTeamId
};

#endif // TRINITY_ARENA_SCORE_H
