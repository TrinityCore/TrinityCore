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

#include "AuthenticationPackets.h"

WorldPackets::Auth::AuthResponse::AuthResponse()
    : ServerPacket(SMSG_AUTH_RESPONSE, 132) 
{
    WaitInfo.HasValue = false;
    SuccessInfo.HasValue = false;
}

void WorldPackets::Auth::AuthResponse::Write()
{
    _worldPacket << uint8(Result);
    _worldPacket.WriteBit(SuccessInfo.HasValue);
    _worldPacket.WriteBit(WaitInfo.HasValue);

    if (SuccessInfo.HasValue)
    {
        _worldPacket << uint32(SuccessInfo.value.VirtualRealmAddress);
        _worldPacket << uint32(SuccessInfo.value.VirtualRealms.size());
        _worldPacket << uint32(SuccessInfo.value.TimeRemain);
        _worldPacket << uint32(SuccessInfo.value.TimeOptions);
        _worldPacket << uint32(SuccessInfo.value.TimeRested);
        _worldPacket << uint8(SuccessInfo.value.ActiveExpansionLevel);
        _worldPacket << uint8(SuccessInfo.value.AccountExpansionLevel);
        _worldPacket << uint32(SuccessInfo.value.TimeSecondsUntilPCKick);
        _worldPacket << uint32(SuccessInfo.value.AvailableRaces->size());
        _worldPacket << uint32(SuccessInfo.value.AvailableClasses->size());
        _worldPacket << uint32(SuccessInfo.value.Templates.size());
        _worldPacket << uint32(SuccessInfo.value.CurrencyID);

        for (auto& realm : SuccessInfo.value.VirtualRealms)
        {
            _worldPacket << uint32(realm.RealmAddress);
            _worldPacket.WriteBit(realm.IsLocal);
            _worldPacket.WriteBit(realm.IsInternalRealm);
            _worldPacket.WriteBits(realm.RealmNameActual.length(), 8);
            _worldPacket.WriteBits(realm.RealmNameNormalized.length(), 8);
            _worldPacket.WriteString(realm.RealmNameActual);
            _worldPacket.WriteString(realm.RealmNameNormalized);
        }

        for (auto& race : *SuccessInfo.value.AvailableRaces)
        {
            _worldPacket << uint8(race.first); /// the current race
            _worldPacket << uint8(race.second); /// the required Expansion
        }

        for (auto& klass : *SuccessInfo.value.AvailableClasses)
        {
            _worldPacket << uint8(klass.first); /// the current class
            _worldPacket << uint8(klass.second); /// the required Expansion
        }

        for (auto& templat : SuccessInfo.value.Templates)
        {
            _worldPacket << uint32(templat.TemplateSetId);
            _worldPacket << uint32(templat.TemplateClasses.size());
            for (auto& templatClass : templat.TemplateClasses)
            {
                _worldPacket << uint8(templatClass.Class);
                _worldPacket << uint8(templatClass.FactionGroup);
            }

            _worldPacket.WriteBits(templat.Name.length(), 7);
            _worldPacket.WriteBits(templat.Description.length(), 10);
            _worldPacket.WriteString(templat.Name);
            _worldPacket.WriteString(templat.Description);
        }

        _worldPacket.WriteBit(SuccessInfo.value.IsExpansionTrial);
        _worldPacket.WriteBit(SuccessInfo.value.ForceCharacterTemplate);
        _worldPacket.WriteBit(SuccessInfo.value.NumPlayersHorde != 0);
        _worldPacket.WriteBit(SuccessInfo.value.NumPlayersAlliance != 0);
        _worldPacket.WriteBit(SuccessInfo.value.IsVeteranTrial);

        if (SuccessInfo.value.NumPlayersHorde)
            _worldPacket << uint16(SuccessInfo.value.NumPlayersHorde);

        if (SuccessInfo.value.NumPlayersAlliance)
            _worldPacket << uint16(SuccessInfo.value.NumPlayersAlliance);
    }

    if (WaitInfo.HasValue)
    {
        _worldPacket << uint32(WaitInfo.value.WaitCount);
        _worldPacket.WriteBit(WaitInfo.value.HasFCM);
    }

    _worldPacket.FlushBits();
}