/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_BATTLEGROUND_SCORE_H
#define TRINITY_BATTLEGROUND_SCORE_H

#include "WorldPacket.h"

class BattlegroundScore
{
    friend class BattlegroundMap;
    friend class ArenaMap;
    protected:
        BattlegroundScore() : KillingBlows(0), Deaths(0), HonorableKills(0),
            BonusHonor(0), DamageDone(0), HealingDone(0) {};
        virtual ~BattlegroundScore() {};

        virtual void AppendToPacket(WorldPacket* data) 
        {
            *data << KillingBlows;
            *data << HonorableKills;
            *data << Deaths;
            *data << BonusHonor;
            *data << DamageDone;
            *data << HealingDone;
        }

        template <class T> uint32 GetMemberCount() { return sizeof(T) / sizeof(uint32); }

        // Default score, present in every type 
        uint32 KillingBlows;
        uint32 Deaths;
        uint32 HonorableKills;
        uint32 BonusHonor;
        uint32 DamageDone;
        uint32 HealingDone;
};

#endif