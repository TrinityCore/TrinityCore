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

#include "AdventureJournalPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::AdventureJournal
{
void AdventureJournalOpenQuest::Read()
{
    _worldPacket >> AdventureJournalID;
}

void AdventureJournalUpdateSuggestions::Read()
{
    _worldPacket >> Bits<1>(OnLevelUp);
}

ByteBuffer& operator<<(ByteBuffer& data, AdventureJournalEntry const& adventureJournalEntry)
{
    data << int32(adventureJournalEntry.AdventureJournalID);
    data << int32(adventureJournalEntry.Priority);

    return data;
}

WorldPacket const* AdventureJournalDataResponse::Write()
{
    _worldPacket << Bits<1>(OnLevelUp);
    _worldPacket << Size<uint32>(Entries);

    for (AdventureJournalEntry const& adventureJournalEntry : Entries)
        _worldPacket << adventureJournalEntry;

    return &_worldPacket;
}
}
