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

#include "QueryPackets.h"

void WorldPackets::Query::QueryCreature::Read()
{
    _worldPacket >> CreatureID;
}

WorldPacket const* WorldPackets::Query::QueryCreatureResponse::Write()
{
    _worldPacket << CreatureID;
    _worldPacket.WriteBit(Allow);

    _worldPacket.FlushBits();

    if (Allow)
    {
        _worldPacket.WriteBits(Stats.Title.length() + 1, 11);
        _worldPacket.WriteBits(Stats.TitleAlt.length() + 1, 11);
        _worldPacket.WriteBits(Stats.CursorName.length() + 1, 6);
        _worldPacket.WriteBit(Stats.Leader);

        for (uint32 i = 0; i < MAX_CREATURE_NAMES; ++i)
        {
            _worldPacket.WriteBits(Stats.Name[i].length() + 1, 11);
            _worldPacket.WriteBits(Stats.NameAlt[i].length() + 1, 11);
        }

        for (uint32 i = 0; i < MAX_CREATURE_NAMES; ++i)
        {
            if (!Stats.Name[i].empty())
                _worldPacket << Stats.Name[i];

            if (!Stats.NameAlt[i].empty())
                _worldPacket << Stats.NameAlt[i];
        }

        for (uint8 i = 0; i < 2; ++i)
            _worldPacket << Stats.Flags[i];

        _worldPacket << Stats.CreatureType;
        _worldPacket << Stats.CreatureFamily;
        _worldPacket << Stats.Classification;

        for (uint32 i = 0; i < MAX_KILL_CREDIT; ++i)
            _worldPacket << Stats.ProxyCreatureID[i];

        for (uint32 i = 0; i < MAX_CREATURE_MODELS; ++i)
            _worldPacket << Stats.CreatureDisplayID[i];

        _worldPacket << Stats.HpMulti;
        _worldPacket << Stats.EnergyMulti;

        _worldPacket << int32(Stats.QuestItems.size());
        _worldPacket << Stats.CreatureMovementInfoID;
        _worldPacket << Stats.RequiredExpansion;

        _worldPacket << int32(0); // FlagQuest

        if (!Stats.Title.empty())
            _worldPacket << Stats.Title;

        if (!Stats.TitleAlt.empty())
            _worldPacket << Stats.TitleAlt;

        if (!Stats.CursorName.empty())
            _worldPacket << Stats.CursorName;

        for (int32 questItem : Stats.QuestItems)
            _worldPacket << questItem;
    }

    return &_worldPacket;
}
