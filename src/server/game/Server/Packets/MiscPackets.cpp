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
        _worldPacket.WriteBit(data.WeeklyQuantity.has_value());
        _worldPacket.WriteBits(data.Flags, 4);
        _worldPacket.WriteBit(data.MaxWeeklyQuantity.has_value());
        _worldPacket.WriteBit(data.TrackedQuantity.has_value());
    }

    _worldPacket.FlushBits();

    for (Record const& data : Data)
    {
        _worldPacket << uint32(data.Quantity);

        if (data.MaxWeeklyQuantity.has_value())
            _worldPacket << uint32(*data.MaxWeeklyQuantity);
        if (data.TrackedQuantity.has_value())
            _worldPacket << uint32(*data.TrackedQuantity);

        _worldPacket << uint32(data.Type);

        if (data.WeeklyQuantity.has_value())
            _worldPacket << uint32(*data.WeeklyQuantity);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::RequestPVPRewardsResponse::Write()
{
    _worldPacket << int32(RatedMaxRewardPointsThisWeek);
    _worldPacket << int32(RewardPointsThisWeek);
    _worldPacket << int32(ArenaMaxRewardPointsThisWeek);
    _worldPacket << int32(RatedRewardPointsThisWeek);
    _worldPacket << int32(ArenaRewardPointsThisWeek);
    _worldPacket << int32(MaxRewardPointsThisWeek);

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

WorldPacket const* WorldPackets::Misc::StartTimer::Write()
{
    _worldPacket << uint32(Type);
    _worldPacket << uint32(TimeLeft);
    _worldPacket << uint32(TotalTime);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::DestroyObject::Write()
{
    _worldPacket << Guid;
    _worldPacket << uint8(IsDead);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::StandStateUpdate::Write()
{
    _worldPacket << uint8(State);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetAnimTier::Write()
{
    _worldPacket << Unit.WriteAsPacked();
    _worldPacket << int32(Tier);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetPlayHoverAnim::Write()
{
    _worldPacket.WriteBit(UnitGUID[4]);
    _worldPacket.WriteBit(UnitGUID[0]);
    _worldPacket.WriteBit(UnitGUID[1]);
    _worldPacket.WriteBit(PlayHoverAnim);
    _worldPacket.WriteBit(UnitGUID[3]);
    _worldPacket.WriteBit(UnitGUID[7]);
    _worldPacket.WriteBit(UnitGUID[5]);
    _worldPacket.WriteBit(UnitGUID[2]);
    _worldPacket.WriteBit(UnitGUID[6]);
    _worldPacket.FlushBits();

    _worldPacket.WriteByteSeq(UnitGUID[3]);
    _worldPacket.WriteByteSeq(UnitGUID[2]);
    _worldPacket.WriteByteSeq(UnitGUID[1]);
    _worldPacket.WriteByteSeq(UnitGUID[7]);
    _worldPacket.WriteByteSeq(UnitGUID[0]);
    _worldPacket.WriteByteSeq(UnitGUID[5]);
    _worldPacket.WriteByteSeq(UnitGUID[4]);
    _worldPacket.WriteByteSeq(UnitGUID[6]);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::StartMirrorTimer::Write()
{
    _worldPacket << int32(Timer);
    _worldPacket << int32(Value);
    _worldPacket << int32(MaxValue);
    _worldPacket << int32(Scale);
    _worldPacket << uint8(Paused);
    _worldPacket << int32(SpellID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PauseMirrorTimer::Write()
{
    _worldPacket << int32(Timer);
    _worldPacket << uint8(Paused);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::StopMirrorTimer::Write()
{
    _worldPacket << int32(Timer);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::CrossedInebriationThreshold::Write()
{
    _worldPacket << Guid;
    _worldPacket << int32(Threshold);
    _worldPacket << int32(ItemID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::LevelUpInfo::Write()
{
    _worldPacket << int32(Level);
    _worldPacket << int32(HealthDelta);

    for (int32 power : PowerDelta)
        _worldPacket << power;

    for (int32 stat : StatDelta)
        _worldPacket << stat;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::BindPointUpdate::Write()
{
    _worldPacket << BindPosition;
    _worldPacket << uint32(BindMapID);
    _worldPacket << uint32(BindAreaID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::WorldServerInfo::Write()
{
    _worldPacket.WriteBit(RestrictedAccountMaxLevel.has_value());
    _worldPacket.WriteBit(RestrictedAccountMaxMoney.has_value());
    _worldPacket.WriteBit(IneligibleForLootMask.has_value());
    _worldPacket.FlushBits();

    if (IneligibleForLootMask)
        _worldPacket << uint32(*IneligibleForLootMask);

    _worldPacket << uint8(IsTournamentRealm);

    if (RestrictedAccountMaxMoney)
        _worldPacket << uint32(*RestrictedAccountMaxMoney);

    if (RestrictedAccountMaxLevel)
        _worldPacket << uint32(*RestrictedAccountMaxLevel);

    _worldPacket << uint32(WeeklyReset);
    _worldPacket << uint32(DifficultyID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::LoginSetTimeSpeed::Write()
{
    _worldPacket.AppendPackedTime(GameTime);
    _worldPacket << float(NewSpeed);
    _worldPacket << uint32(GameTimeHolidayOffset);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::ZoneUnderAttack::Write()
{
    _worldPacket << int32(AreaID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::Dismount::Write()
{
    _worldPacket << Guid.WriteAsPacked();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::LoadCUFProfiles::Write()
{
    _worldPacket.WriteBits(CUFProfiles.size(), 20);

    for (CUFProfile const* cufProfile : CUFProfiles)
    {
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_UNK_157]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_AUTO_ACTIVATE_10_PLAYERS]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_AUTO_ACTIVATE_5_PLAYERS]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_AUTO_ACTIVATE_25_PLAYERS]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_DISPLAY_HEAL_PREDICTION]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_AUTO_ACTIVATE_PVE]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_DISPLAY_HORIZONTAL_GROUPS]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_AUTO_ACTIVATE_40_PLAYERS]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_AUTO_ACTIVATE_3_PLAYERS]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_DISPLAY_AGGRO_HIGHLIGHT]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_DISPLAY_BORDER]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_AUTO_ACTIVATE_2_PLAYERS]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_DISPLAY_NON_BOSS_DEBUFFS]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_DISPLAY_MAIN_TANK_AND_ASSIST]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_UNK_156]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_AUTO_ACTIVATE_SPEC_2]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_USE_CLASS_COLORS]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_DISPLAY_POWER_BAR]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_AUTO_ACTIVATE_SPEC_1]);
        _worldPacket.WriteBits(cufProfile->ProfileName.size(), 8);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_DISPLAY_ONLY_DISPELLABLE_DEBUFFS]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_KEEP_GROUPS_TOGETHER]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_UNK_145]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_AUTO_ACTIVATE_15_PLAYERS]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_DISPLAY_PETS]);
        _worldPacket.WriteBit(cufProfile->BoolOptions[CUF_AUTO_ACTIVATE_PVP]);
    }

    _worldPacket.FlushBits();

    for (CUFProfile const* cufProfile : CUFProfiles)
    {
        // Other Options
        _worldPacket << uint16(cufProfile->LeftOffset);
        _worldPacket << uint16(cufProfile->FrameHeight);
        _worldPacket << uint16(cufProfile->BottomOffset);
        _worldPacket << uint8(cufProfile->BottomPoint);
        _worldPacket << uint16(cufProfile->TopOffset);
        _worldPacket << uint8(cufProfile->TopPoint);
        _worldPacket << uint8(cufProfile->HealthText);
        _worldPacket << uint8(cufProfile->SortBy);
        _worldPacket << uint16(cufProfile->FrameWidth);
        _worldPacket << uint8(cufProfile->LeftPoint);
        _worldPacket.WriteString(cufProfile->ProfileName);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::DeathReleaseLoc::Write()
{
    _worldPacket << int32(MapID);
    _worldPacket << Loc;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::BinderConfirm::Write()
{
    _worldPacket << Unit;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::RequestCemeteryListResponse::Write()
{
    _worldPacket.WriteBit(IsGossipTriggered);
    _worldPacket.WriteBits(CemeteryID.size(), 24);
    _worldPacket.FlushBits();

    for (uint32 cemetery : CemeteryID)
        _worldPacket << cemetery;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::CorpseReclaimDelay::Write()
{
    _worldPacket << uint32(Remaining);

    return &_worldPacket;
}

void WorldPackets::Misc::SetCurrencyFlags::Read()
{
    _worldPacket >> Flags;
    _worldPacket >> CurrencyID;
}

WorldPacket const* WorldPackets::Misc::MapObjEvents::Write()
{
    _worldPacket << uint32(UniqueID);
    _worldPacket << uint32(Events.size());
    for (uint8 const& eventData : Events)
        _worldPacket << uint8(eventData);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetCurrency::Write()
{
    _worldPacket.WriteBit(WeeklyQuantity.has_value());
    _worldPacket.WriteBit(TrackedQuantity.has_value());
    _worldPacket.WriteBit(SuppressChatLog);
    _worldPacket.FlushBits();

    if (TrackedQuantity.has_value())
        _worldPacket << int32(*TrackedQuantity);

    _worldPacket << int32(Quantity);
    _worldPacket << int32(Type);

    if (WeeklyQuantity.has_value())
        _worldPacket << int32(*WeeklyQuantity);

    return &_worldPacket;
}
