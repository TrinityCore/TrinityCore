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

WorldPacket const* WorldPackets::Misc::BindPointUpdate::Write()
{
    _worldPacket << BindPosition;
    _worldPacket << uint32(BindMapID);
    _worldPacket << uint32(BindAreaID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::InvalidatePlayer::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::LoginSetTimeSpeed::Write()
{
    _worldPacket << ServerTime;
    _worldPacket << GameTime;
    _worldPacket << float(NewSpeed);
    _worldPacket << uint32(ServerTimeHolidayOffset);
    _worldPacket << uint32(GameTimeHolidayOffset);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetCurrency::Write()
{
    _worldPacket << int32(Type);
    _worldPacket << int32(Quantity);
    _worldPacket << uint32(Flags);
    _worldPacket << uint32(Toasts.size());

    for (WorldPackets::Item::UiEventToast const& toast : Toasts)
        _worldPacket << toast;

    _worldPacket.WriteBit(WeeklyQuantity.has_value());
    _worldPacket.WriteBit(TrackedQuantity.has_value());
    _worldPacket.WriteBit(MaxQuantity.has_value());
    _worldPacket.WriteBit(TotalEarned.has_value());
    _worldPacket.WriteBit(SuppressChatLog);
    _worldPacket.WriteBit(QuantityChange.has_value());
    _worldPacket.WriteBit(QuantityGainSource.has_value());
    _worldPacket.WriteBit(QuantityLostSource.has_value());
    _worldPacket.WriteBit(FirstCraftOperationID.has_value());
    _worldPacket.WriteBit(NextRechargeTime.has_value());
    _worldPacket.WriteBit(RechargeCycleStartTime.has_value());
    _worldPacket.WriteBit(OverflownCurrencyID.has_value());
    _worldPacket.FlushBits();

    if (WeeklyQuantity)
        _worldPacket << int32(*WeeklyQuantity);

    if (TrackedQuantity)
        _worldPacket << int32(*TrackedQuantity);

    if (MaxQuantity)
        _worldPacket << int32(*MaxQuantity);

    if (TotalEarned)
        _worldPacket << int32(*TotalEarned);

    if (QuantityChange)
        _worldPacket << int32(*QuantityChange);

    if (QuantityGainSource)
        _worldPacket << int32(*QuantityGainSource);

    if (QuantityLostSource)
        _worldPacket << int32(*QuantityLostSource);

    if (FirstCraftOperationID)
        _worldPacket << uint32(*FirstCraftOperationID);

    if (NextRechargeTime)
        _worldPacket << *NextRechargeTime;

    if (RechargeCycleStartTime)
        _worldPacket << *RechargeCycleStartTime;

    if (OverflownCurrencyID)
        _worldPacket << int32(*OverflownCurrencyID);

    return &_worldPacket;
}

void WorldPackets::Misc::SetSelection::Read()
{
    _worldPacket >> Selection;
}

WorldPacket const* WorldPackets::Misc::SetupCurrency::Write()
{
    _worldPacket << uint32(Data.size());

    for (Record const& data : Data)
    {
        _worldPacket << int32(data.Type);
        _worldPacket << int32(data.Quantity);

        _worldPacket.WriteBit(data.WeeklyQuantity.has_value());
        _worldPacket.WriteBit(data.MaxWeeklyQuantity.has_value());
        _worldPacket.WriteBit(data.TrackedQuantity.has_value());
        _worldPacket.WriteBit(data.MaxQuantity.has_value());
        _worldPacket.WriteBit(data.TotalEarned.has_value());
        _worldPacket.WriteBit(data.NextRechargeTime.has_value());
        _worldPacket.WriteBit(data.RechargeCycleStartTime.has_value());
        _worldPacket.WriteBits(uint8(data.Flags), 5);
        _worldPacket.FlushBits();

        if (data.WeeklyQuantity)
            _worldPacket << uint32(*data.WeeklyQuantity);
        if (data.MaxWeeklyQuantity)
            _worldPacket << uint32(*data.MaxWeeklyQuantity);
        if (data.TrackedQuantity)
            _worldPacket << uint32(*data.TrackedQuantity);
        if (data.MaxQuantity)
            _worldPacket << int32(*data.MaxQuantity);
        if (data.TotalEarned)
            _worldPacket << int32(*data.TotalEarned);
        if (data.NextRechargeTime)
            _worldPacket << *data.NextRechargeTime;
        if (data.RechargeCycleStartTime)
            _worldPacket << *data.RechargeCycleStartTime;
    }

    return &_worldPacket;
}

void WorldPackets::Misc::ViolenceLevel::Read()
{
    _worldPacket >> ViolenceLvl;
}

WorldPacket const* WorldPackets::Misc::TimeSyncRequest::Write()
{
    _worldPacket << SequenceIndex;

    return &_worldPacket;
}

void WorldPackets::Misc::TimeSyncResponse::Read()
{
    _worldPacket >> SequenceIndex;
    _worldPacket >> ClientTime;
}

WorldPacket const* WorldPackets::Misc::ServerTimeOffset::Write()
{
    _worldPacket << Time;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::TriggerMovie::Write()
{
    _worldPacket << uint32(MovieID);

    return &_worldPacket;
}
WorldPacket const* WorldPackets::Misc::TriggerCinematic::Write()
{
    _worldPacket << uint32(CinematicID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::TutorialFlags::Write()
{
    _worldPacket.append(TutorialData, MAX_ACCOUNT_TUTORIAL_VALUES);

    return &_worldPacket;
}

void WorldPackets::Misc::TutorialSetFlag::Read()
{
    Action = _worldPacket.ReadBits(2);

    if (Action == TUTORIAL_ACTION_UPDATE)
        _worldPacket >> TutorialBit;
}

WorldPacket const* WorldPackets::Misc::WorldServerInfo::Write()
{
    _worldPacket << uint32(DifficultyID);
    _worldPacket.WriteBit(IsTournamentRealm);
    _worldPacket.WriteBit(XRealmPvpAlert);
    _worldPacket.WriteBit(BlockExitingLoadingScreen);
    _worldPacket.WriteBit(RestrictedAccountMaxLevel.has_value());
    _worldPacket.WriteBit(RestrictedAccountMaxMoney.has_value());
    _worldPacket.WriteBit(InstanceGroupSize.has_value());

    if (RestrictedAccountMaxLevel)
        _worldPacket << uint32(*RestrictedAccountMaxLevel);

    if (RestrictedAccountMaxMoney)
        _worldPacket << uint64(*RestrictedAccountMaxMoney);

    if (InstanceGroupSize)
        _worldPacket << uint32(*InstanceGroupSize);

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Misc::SetDungeonDifficulty::Read()
{
    _worldPacket >> DifficultyID;
}

void WorldPackets::Misc::SetRaidDifficulty::Read()
{
    _worldPacket >> DifficultyID;
    _worldPacket >> Legacy;
}

WorldPacket const* WorldPackets::Misc::DungeonDifficultySet::Write()
{
    _worldPacket << int32(DifficultyID);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::RaidDifficultySet::Write()
{
    _worldPacket << int32(DifficultyID);
    _worldPacket << uint8(Legacy);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::CorpseReclaimDelay::Write()
{
    _worldPacket << Remaining;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::DeathReleaseLoc::Write()
{
    _worldPacket << MapID;
    _worldPacket << Loc;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PreRessurect::Write()
{
    _worldPacket << PlayerGUID;

    return &_worldPacket;
}

void WorldPackets::Misc::ReclaimCorpse::Read()
{
    _worldPacket >> CorpseGUID;
}

void WorldPackets::Misc::RepopRequest::Read()
{
    CheckInstance = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Misc::RequestCemeteryListResponse::Write()
{
    _worldPacket.WriteBit(IsGossipTriggered);
    _worldPacket.FlushBits();

    _worldPacket << uint32(CemeteryID.size());
    for (uint32 cemetery : CemeteryID)
        _worldPacket << cemetery;

    return &_worldPacket;
}

void WorldPackets::Misc::ResurrectResponse::Read()
{
    _worldPacket >> Resurrecter;
    _worldPacket >> Response;
}

WorldPackets::Misc::Weather::Weather() : ServerPacket(SMSG_WEATHER, 4 + 4 + 1) { }

WorldPackets::Misc::Weather::Weather(WeatherState weatherID, float intensity /*= 0.0f*/, bool abrupt /*= false*/)
    : ServerPacket(SMSG_WEATHER, 4 + 4 + 1), Abrupt(abrupt), Intensity(intensity), WeatherID(weatherID) { }

WorldPacket const* WorldPackets::Misc::Weather::Write()
{
    _worldPacket << uint32(WeatherID);
    _worldPacket << float(Intensity);
    _worldPacket.WriteBit(Abrupt);

    _worldPacket.FlushBits();
    return &_worldPacket;
}

void WorldPackets::Misc::StandStateChange::Read()
{
    uint32 state;
    _worldPacket >> state;

    StandState = UnitStandStateType(state);
}

WorldPacket const* WorldPackets::Misc::StandStateUpdate::Write()
{
    _worldPacket << uint32(AnimKitID);
    _worldPacket << uint8(State);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetAnimTier::Write()
{
    _worldPacket << Unit;
    _worldPacket.WriteBits(Tier, 3);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PlayerBound::Write()
{
    _worldPacket << BinderID;
    _worldPacket << uint32(AreaID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::StartMirrorTimer::Write()
{
    _worldPacket << int32(Timer);
    _worldPacket << int32(Value);
    _worldPacket << int32(MaxValue);
    _worldPacket << int32(Scale);
    _worldPacket << int32(SpellID);
    _worldPacket.WriteBit(Paused);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PauseMirrorTimer::Write()
{
    _worldPacket << int32(Timer);
    _worldPacket.WriteBit(Paused);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::StopMirrorTimer::Write()
{
    _worldPacket << int32(Timer);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::ExplorationExperience::Write()
{
    _worldPacket << int32(AreaID);
    _worldPacket << int32(Experience);

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

    _worldPacket << int32(NumNewTalents);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PlayMusic::Write()
{
    _worldPacket << uint32(SoundKitID);

    return &_worldPacket;
}

void WorldPackets::Misc::RandomRollClient::Read()
{
    bool hasPartyIndex = _worldPacket.ReadBit();
    _worldPacket >> Min;
    _worldPacket >> Max;
    if (hasPartyIndex)
        _worldPacket >> PartyIndex.emplace();
}

WorldPacket const* WorldPackets::Misc::RandomRoll::Write()
{
    _worldPacket << Roller;
    _worldPacket << RollerWowAccount;
    _worldPacket << int32(Min);
    _worldPacket << int32(Max);
    _worldPacket << int32(Result);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::EnableBarberShop::Write()
{
    _worldPacket << uint8(CustomizationScope);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Misc::PhaseShiftDataPhase const& phaseShiftDataPhase)
{
    data << uint32(phaseShiftDataPhase.PhaseFlags);
    data << uint16(phaseShiftDataPhase.Id);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Misc::PhaseShiftData const& phaseShiftData)
{
    data << uint32(phaseShiftData.PhaseShiftFlags);
    data << uint32(phaseShiftData.Phases.size());
    data << phaseShiftData.PersonalGUID;
    for (WorldPackets::Misc::PhaseShiftDataPhase const& phaseShiftDataPhase : phaseShiftData.Phases)
        data << phaseShiftDataPhase;

    return data;
}

WorldPacket const* WorldPackets::Misc::PhaseShiftChange::Write()
{
    _worldPacket << Client;
    _worldPacket << Phaseshift;
    _worldPacket << uint32(VisibleMapIDs.size() * 2);           // size in bytes
    for (uint16 visibleMapId : VisibleMapIDs)
        _worldPacket << uint16(visibleMapId);                   // Active terrain swap map id

    _worldPacket << uint32(PreloadMapIDs.size() * 2);           // size in bytes
    for (uint16 preloadMapId : PreloadMapIDs)
        _worldPacket << uint16(preloadMapId);                   // Inactive terrain swap map id

    _worldPacket << uint32(UiMapPhaseIDs.size() * 2);           // size in bytes
    for (uint16 uiMapPhaseId : UiMapPhaseIDs)
        _worldPacket << uint16(uiMapPhaseId);                   // phase id, controls only map display (visible on all maps)

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::ZoneUnderAttack::Write()
{
    _worldPacket << int32(AreaID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::DurabilityDamageDeath::Write()
{
    _worldPacket << int32(Percent);

    return &_worldPacket;
}

void WorldPackets::Misc::ObjectUpdateFailed::Read()
{
    _worldPacket >> ObjectGUID;
}

void WorldPackets::Misc::ObjectUpdateRescued::Read()
{
    _worldPacket >> ObjectGUID;
}

WorldPacket const* WorldPackets::Misc::PlayObjectSound::Write()
{
    _worldPacket << int32(SoundKitID);
    _worldPacket << SourceObjectGUID;
    _worldPacket << TargetObjectGUID;
    _worldPacket << Position;
    _worldPacket << int32(BroadcastTextID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PlaySound::Write()
{
    _worldPacket << int32(SoundKitID);
    _worldPacket << SourceObjectGuid;
    _worldPacket << int32(BroadcastTextID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PlaySpeakerbotSound::Write()
{
    _worldPacket << SourceObjectGUID;
    _worldPacket << int32(SoundKitID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::StopSpeakerbotSound::Write()
{
    _worldPacket << SourceObjectGUID;

    return &_worldPacket;
}

void WorldPackets::Misc::FarSight::Read()
{
    Enable = _worldPacket.ReadBit();
}

void WorldPackets::Misc::SaveCUFProfiles::Read()
{
    CUFProfiles.resize(_worldPacket.read<uint32>());
    for (std::unique_ptr<CUFProfile>& cufProfile : CUFProfiles)
    {
        cufProfile = std::make_unique<CUFProfile>();

        uint8 strLen = _worldPacket.ReadBits(7);

        // Bool Options
        for (uint8 option = 0; option < CUF_BOOL_OPTIONS_COUNT; option++)
            cufProfile->BoolOptions.set(option, _worldPacket.ReadBit());

        // Other Options
        _worldPacket >> cufProfile->FrameHeight;
        _worldPacket >> cufProfile->FrameWidth;

        _worldPacket >> cufProfile->SortBy;
        _worldPacket >> cufProfile->HealthText;

        _worldPacket >> cufProfile->TopPoint;
        _worldPacket >> cufProfile->BottomPoint;
        _worldPacket >> cufProfile->LeftPoint;

        _worldPacket >> cufProfile->TopOffset;
        _worldPacket >> cufProfile->BottomOffset;
        _worldPacket >> cufProfile->LeftOffset;

        cufProfile->ProfileName = _worldPacket.ReadString(strLen);
    }
}

WorldPacket const* WorldPackets::Misc::LoadCUFProfiles::Write()
{
    _worldPacket << uint32(CUFProfiles.size());

    for (CUFProfile const* cufProfile : CUFProfiles)
    {
        _worldPacket.WriteBits(cufProfile->ProfileName.size(), 7);

        // Bool Options
        for (uint8 option = 0; option < CUF_BOOL_OPTIONS_COUNT; option++)
            _worldPacket.WriteBit(cufProfile->BoolOptions[option]);

        // Other Options
        _worldPacket << cufProfile->FrameHeight;
        _worldPacket << cufProfile->FrameWidth;

        _worldPacket << cufProfile->SortBy;
        _worldPacket << cufProfile->HealthText;

        _worldPacket << cufProfile->TopPoint;
        _worldPacket << cufProfile->BottomPoint;
        _worldPacket << cufProfile->LeftPoint;

        _worldPacket << cufProfile->TopOffset;
        _worldPacket << cufProfile->BottomOffset;
        _worldPacket << cufProfile->LeftOffset;

        _worldPacket.WriteString(cufProfile->ProfileName);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::PlayOneShotAnimKit::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint16(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetAIAnimKit::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint16(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetMovementAnimKit::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint16(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetMeleeAnimKit::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint16(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::SetPlayHoverAnim::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket.WriteBit(PlayHoverAnim);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Misc::SetPvP::Read()
{
    EnablePVP = _worldPacket.ReadBit();
}

void WorldPackets::Misc::SetWarMode::Read()
{
    Enable = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Misc::AccountHeirloomUpdate::Write()
{
    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket.FlushBits();

    _worldPacket << int32(Unk);

    // both lists have to have the same size
    _worldPacket << uint32(Heirlooms->size());
    _worldPacket << uint32(Heirlooms->size());

    for (auto const& item : *Heirlooms)
        _worldPacket << int32(item.first);

    for (auto const& flags : *Heirlooms)
        _worldPacket << uint32(flags.second.flags);

    return &_worldPacket;
}

void WorldPackets::Misc::MountSpecial::Read()
{
    SpellVisualKitIDs.resize(_worldPacket.read<uint32>());
    _worldPacket >> SequenceVariation;
    for (int32& spellVisualKitId : SpellVisualKitIDs)
        _worldPacket >> spellVisualKitId;
}

WorldPacket const* WorldPackets::Misc::SpecialMountAnim::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << uint32(SpellVisualKitIDs.size());
    _worldPacket << int32(SequenceVariation);
    if (!SpellVisualKitIDs.empty())
        _worldPacket.append(SpellVisualKitIDs.data(), SpellVisualKitIDs.size());

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::CrossedInebriationThreshold::Write()
{
    _worldPacket << Guid;
    _worldPacket << int32(Threshold);
    _worldPacket << int32(ItemID);

    return &_worldPacket;
}

void WorldPackets::Misc::SetTaxiBenchmarkMode::Read()
{
    Enable = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Misc::OverrideLight::Write()
{
    _worldPacket << int32(AreaLightID);
    _worldPacket << int32(OverrideLightID);
    _worldPacket << int32(TransitionMilliseconds);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::DisplayGameError::Write()
{
    _worldPacket << uint32(Error);
    _worldPacket.WriteBit(Arg.has_value());
    _worldPacket.WriteBit(Arg2.has_value());
    _worldPacket.FlushBits();

    if (Arg)
        _worldPacket << int32(*Arg);

    if (Arg2)
        _worldPacket << int32(*Arg2);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::AccountMountUpdate::Write()
{
    _worldPacket.WriteBit(IsFullUpdate);
    _worldPacket << uint32(Mounts->size());

    for (auto [spellId, flags] : *Mounts)
    {
        _worldPacket << int32(spellId);
        _worldPacket.WriteBits(flags, 4);
    }

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void WorldPackets::Misc::MountSetFavorite::Read()
{
    _worldPacket >> MountSpellID;
    IsFavorite = _worldPacket.ReadBit();
}

void WorldPackets::Misc::CloseInteraction::Read()
{
    _worldPacket >> SourceGuid;
}

WorldPacket const* WorldPackets::Misc::StartTimer::Write()
{
    _worldPacket << TotalTime;
    _worldPacket << TimeLeft;
    _worldPacket << int32(Type);

    return &_worldPacket;
}

void WorldPackets::Misc::QueryCountdownTimer::Read()
{
    TimerType = _worldPacket.read<CountdownTimerType, int32>();
}

void WorldPackets::Misc::ConversationLineStarted::Read()
{
    _worldPacket >> ConversationGUID;
    _worldPacket >> LineID;
}

WorldPacket const* WorldPackets::Misc::SplashScreenShowLatest::Write()
{
    _worldPacket << int32(UISplashScreenID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Misc::DisplayToast::Write()
{
    _worldPacket << uint64(Quantity);
    _worldPacket << uint8(AsUnderlyingType(DisplayToastMethod));
    _worldPacket << uint32(QuestID);

    _worldPacket.WriteBit(Mailed);
    _worldPacket.WriteBits(AsUnderlyingType(Type), 2);
    _worldPacket.WriteBit(IsSecondaryResult);

    switch (Type)
    {
        case DisplayToastType::NewItem:
            _worldPacket.WriteBit(BonusRoll);
            _worldPacket << Item;
            _worldPacket << int32(LootSpec);
            _worldPacket << int8(Gender);
            break;
        case DisplayToastType::NewCurrency:
            _worldPacket << uint32(CurrencyID);
            break;
        default:
            break;
    }

    _worldPacket.FlushBits();

    return &_worldPacket;
}
