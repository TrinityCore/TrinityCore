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

#include "MiscPackets.h"
#include "Common.h"

WorldPacket const* WorldPackets::Misc::SetupCurrency::Write()
{
    _worldPacket.WriteBits(Data.size(), 23);

    for (Record const& data : Data)
    {
        _worldPacket.WriteBit(data.WeeklyQuantity.is_initialized());
        _worldPacket.WriteBits(data.Flags, 4);
        _worldPacket.WriteBit(data.MaxWeeklyQuantity.is_initialized());
        _worldPacket.WriteBit(data.TrackedQuantity.is_initialized());
    }

    _worldPacket.FlushBits();

    for (Record const& data : Data)
    {
        _worldPacket << uint32(data.Quantity);

        if (data.MaxWeeklyQuantity.is_initialized())
            _worldPacket << uint32(*data.MaxWeeklyQuantity);
        if (data.TrackedQuantity.is_initialized())
            _worldPacket << uint32(*data.TrackedQuantity);

        _worldPacket << uint32(data.Type);

        if (data.WeeklyQuantity.is_initialized())
            _worldPacket << uint32(*data.WeeklyQuantity);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::RequestPVPRewardsResponse::Write()
{
    _worldPacket << uint32(MaxRewardPointsThisWeek);
    _worldPacket << uint32(RewardPointsThisWeek);
    _worldPacket << uint32(ArenaMaxRewardPointsThisWeek);
    _worldPacket << uint32(RatedRewardPointsThisWeek);
    _worldPacket << uint32(ArenaRewardPointsThisWeek);
    _worldPacket << uint32(RatedMaxRewardPointsThisWeek);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::TriggerMovie::Write()
{
    _worldPacket << int32(MovieID);

    return &_worldPacket;
}
WorldPacket const* WorldPackets::Misc::TriggerCinematic::Write()
{
    _worldPacket << int32(CinematicID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::StreamingMovies::Write()
{
    _worldPacket.WriteBits(MovieIDs.size(), 25);
    _worldPacket.FlushBits();

    for (uint16 moveId : MovieIDs)
        _worldPacket << int16(moveId);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PhaseShiftChange::Write()
{
    _worldPacket.WriteBit(Client[2]);
    _worldPacket.WriteBit(Client[3]);
    _worldPacket.WriteBit(Client[1]);
    _worldPacket.WriteBit(Client[6]);
    _worldPacket.WriteBit(Client[4]);
    _worldPacket.WriteBit(Client[5]);
    _worldPacket.WriteBit(Client[0]);
    _worldPacket.WriteBit(Client[7]);

    _worldPacket.WriteByteSeq(Client[7]);
    _worldPacket.WriteByteSeq(Client[4]);

    _worldPacket << uint32(UiMapPhaseIDs.size() * 2);           // size in bytes
    for (uint16 uiMapPhaseId : UiMapPhaseIDs)
        _worldPacket << uint16(uiMapPhaseId);                   // phase id, controls only map display (visible on all maps)

    _worldPacket.WriteByteSeq(Client[1]);

    _worldPacket << uint32(Phaseshift.PhaseShiftFlags);

    _worldPacket.WriteByteSeq(Client[2]);
    _worldPacket.WriteByteSeq(Client[6]);

    _worldPacket << uint32(PreloadMapIDs.size() * 2);           // size in bytes
    for (uint16 preloadMapId : PreloadMapIDs)
        _worldPacket << uint16(preloadMapId);                   // Inactive terrain swap map id

    _worldPacket << uint32 (Phaseshift.Phases.size() * 2);      // size in bytes
    for (uint16 phaseId : Phaseshift.Phases)
        _worldPacket << uint16(phaseId);                        // active phase ids

    _worldPacket.WriteByteSeq(Client[3]);
    _worldPacket.WriteByteSeq(Client[0]);

    _worldPacket << uint32(VisibleMapIDs.size() * 2);           // size in bytes
    for (uint16 visibleMapId : VisibleMapIDs)
        _worldPacket << uint16(visibleMapId);                   // Active terrain swap map id

    _worldPacket.WriteByteSeq(Client[5]);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::UITime::Write()
{
    _worldPacket << uint32(Time);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PlaySound::Write()
{
    _worldPacket << uint32(SoundKitID);
    _worldPacket << SourceObjectGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PlayObjectSound::Write()
{
    _worldPacket << uint32(SoundKitID);
    _worldPacket << SourceObjectGUID;
    _worldPacket << TargetObjectGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PlayMusic::Write()
{
    _worldPacket << uint32(SoundKitID);
    _worldPacket << SourceObjectGUID;

    return &_worldPacket;
}

WorldPackets::Misc::Weather::Weather() : ServerPacket(SMSG_WEATHER, 4 + 4 + 1) { }

WorldPackets::Misc::Weather::Weather(WeatherState weatherID, float intensity /*= 0.0f*/, bool abrupt /*= false*/)
    : ServerPacket(SMSG_WEATHER, 4 + 4 + 1), Abrupt(abrupt), Intensity(intensity), WeatherID(weatherID) { }

WorldPacket const* WorldPackets::Misc::Weather::Write()
{
    _worldPacket << uint32(WeatherID);
    _worldPacket << float(Intensity);
    _worldPacket << uint8(Abrupt);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::OverrideLight::Write()
{
    _worldPacket << uint32(AreaLightID);
    _worldPacket << uint32(OverrideLightID);
    _worldPacket << uint32(TransitionMilliseconds);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::DurabilityDamageDeath::Write()
{
    _worldPacket << int32(Percent);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PlayOneShotAnimKit::Write()
{
    _worldPacket << Unit.WriteAsPacked();
    _worldPacket << uint16(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetAIAnimKit::Write()
{
    _worldPacket << Unit.WriteAsPacked();
    _worldPacket << uint16(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetMeleeAnimKit::Write()
{
    _worldPacket << Unit.WriteAsPacked();
    _worldPacket << uint16(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetMovementAnimKit::Write()
{
    _worldPacket << Unit.WriteAsPacked();
    _worldPacket << uint16(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::UnitHealthFrequent::Write()
{
    _worldPacket << UnitGUID.WriteAsPacked();
    _worldPacket << int32(Health);

    return &_worldPacket;
}
