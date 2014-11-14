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

#ifndef QueryPackets_h__
#define QueryPackets_h__

#include "Packet.h"
#include "Creature.h"

namespace WorldPackets
{
    namespace Query
    {
        class QueryCreature final : public ClientPacket
        {
        public:
            QueryCreature(WorldPacket&& packet) : ClientPacket(CMSG_CREATURE_QUERY, std::move(packet)) { }

            void Read() override;

            uint32 CreatureID = 0;
        };

        struct CreatureStats
        {
            std::string Title;
            std::string TitleAlt;
            std::string CursorName;
            int32 CreatureType = 0;
            int32 CreatureFamily = 0;
            int32 Classification = 0;
            float HpMulti = 0.0f;
            float EnergyMulti = 0.0f;
            bool Leader = false;
            std::vector<int32> QuestItems;
            uint32 CreatureMovementInfoID = 0;
            uint32 RequiredExpansion = 0;
            uint32 Flags[2];
            uint32 ProxyCreatureID[MAX_KILL_CREDIT];
            uint32 CreatureDisplayID[MAX_CREATURE_MODELS];
            std::string Name[MAX_CREATURE_NAMES];
            std::string NameAlt[MAX_CREATURE_NAMES];
        };

        class QueryCreatureResponse final : public ServerPacket
        {
        public:
            QueryCreatureResponse() : ServerPacket(SMSG_CREATURE_QUERY_RESPONSE, 2+4+4+4+12) { }

            WorldPacket const* Write() override;

            bool Allow = false;
            CreatureStats Stats;
            uint32 CreatureID = 0;
        };
    }
}

#endif // QueryPackets_h__
