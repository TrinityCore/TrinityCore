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
#include "PacketOperators.h"
#include "Player.h"

namespace WorldPackets::Misc
{
WorldPacket const* BindPointUpdate::Write()
{
    _worldPacket << BindPosition;
    _worldPacket << uint32(BindMapID);
    _worldPacket << uint32(BindAreaID);

    return &_worldPacket;
}

WorldPacket const* InvalidatePlayer::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

WorldPacket const* LoginSetTimeSpeed::Write()
{
    _worldPacket << ServerTime;
    _worldPacket << GameTime;
    _worldPacket << float(NewSpeed);
    _worldPacket << uint32(ServerTimeHolidayOffset);
    _worldPacket << uint32(GameTimeHolidayOffset);

    return &_worldPacket;
}

WorldPacket const* SetCurrency::Write()
{
    _worldPacket << int32(Type);
    _worldPacket << int32(Quantity);
    _worldPacket << uint32(Flags);
    _worldPacket << Size<uint32>(Toasts);

    for (Item::UiEventToast const& toast : Toasts)
        _worldPacket << toast;

    _worldPacket << OptionalInit(WeeklyQuantity);
    _worldPacket << OptionalInit(TrackedQuantity);
    _worldPacket << OptionalInit(MaxQuantity);
    _worldPacket << OptionalInit(TotalEarned);
    _worldPacket << Bits<1>(SuppressChatLog);
    _worldPacket << OptionalInit(QuantityChange);
    _worldPacket << OptionalInit(QuantityGainSource);
    _worldPacket << OptionalInit(QuantityLostSource);
    _worldPacket << OptionalInit(FirstCraftOperationID);
    _worldPacket << OptionalInit(NextRechargeTime);
    _worldPacket << OptionalInit(RechargeCycleStartTime);
    _worldPacket << OptionalInit(OverflownCurrencyID);
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

void SetSelection::Read()
{
    _worldPacket >> Selection;
}

WorldPacket const* SetupCurrency::Write()
{
    _worldPacket << Size<uint32>(Data);

    for (Record const& data : Data)
    {
        _worldPacket << int32(data.Type);
        _worldPacket << int32(data.Quantity);
        _worldPacket << uint8(data.Flags);

        _worldPacket << OptionalInit(data.WeeklyQuantity);
        _worldPacket << OptionalInit(data.MaxWeeklyQuantity);
        _worldPacket << OptionalInit(data.TrackedQuantity);
        _worldPacket << OptionalInit(data.MaxQuantity);
        _worldPacket << OptionalInit(data.TotalEarned);
        _worldPacket << OptionalInit(data.NextRechargeTime);
        _worldPacket << OptionalInit(data.RechargeCycleStartTime);
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

void ViolenceLevel::Read()
{
    _worldPacket >> ViolenceLvl;
}

WorldPacket const* TimeSyncRequest::Write()
{
    _worldPacket << SequenceIndex;

    return &_worldPacket;
}

void TimeSyncResponse::Read()
{
    _worldPacket >> SequenceIndex;
    _worldPacket >> ClientTime;
}

WorldPacket const* ServerTimeOffset::Write()
{
    _worldPacket << Time;

    return &_worldPacket;
}

WorldPacket const* TriggerMovie::Write()
{
    _worldPacket << uint32(MovieID);

    return &_worldPacket;
}

WorldPacket const* TriggerCinematic::Write()
{
    _worldPacket << uint32(CinematicID);
    _worldPacket << ConversationGuid;

    return &_worldPacket;
}

WorldPacket const* TutorialFlags::Write()
{
    _worldPacket.append(TutorialData);

    return &_worldPacket;
}

void TutorialSetFlag::Read()
{
    _worldPacket >> Bits<2>(Action);

    if (Action == TUTORIAL_ACTION_UPDATE)
        _worldPacket >> TutorialBit;
}

WorldPacket const* WorldServerInfo::Write()
{
    _worldPacket << int16(DifficultyID);
    _worldPacket << HouseGUID;
    _worldPacket << HouseOwnerAccountGUID;
    _worldPacket << HouseCosmeticOwnerGUID;
    _worldPacket << NeighborhoodGUID;
    _worldPacket << Bits<1>(IsTournamentRealm);
    _worldPacket << Bits<1>(XRealmPvpAlert);
    _worldPacket << Bits<1>(BlockExitingLoadingScreen);
    _worldPacket << OptionalInit(RestrictedAccountMaxLevel);
    _worldPacket << OptionalInit(RestrictedAccountMaxMoney);
    _worldPacket << OptionalInit(InstanceGroupSize);
    _worldPacket.FlushBits();

    if (RestrictedAccountMaxLevel)
        _worldPacket << uint32(*RestrictedAccountMaxLevel);

    if (RestrictedAccountMaxMoney)
        _worldPacket << uint64(*RestrictedAccountMaxMoney);

    if (InstanceGroupSize)
        _worldPacket << uint32(*InstanceGroupSize);

    return &_worldPacket;
}

void SetDungeonDifficulty::Read()
{
    _worldPacket >> DifficultyID;
}

void SetRaidDifficulty::Read()
{
    _worldPacket >> Legacy;
    _worldPacket >> DifficultyID;
}

WorldPacket const* DungeonDifficultySet::Write()
{
    _worldPacket << int16(DifficultyID);

    return &_worldPacket;
}

WorldPacket const* RaidDifficultySet::Write()
{
    _worldPacket << int32(Legacy);
    _worldPacket << int16(DifficultyID);

    return &_worldPacket;
}

WorldPacket const* CorpseReclaimDelay::Write()
{
    _worldPacket << Remaining;

    return &_worldPacket;
}

WorldPacket const* DeathReleaseLoc::Write()
{
    _worldPacket << MapID;
    _worldPacket << Loc;

    return &_worldPacket;
}

WorldPacket const* PreRessurect::Write()
{
    _worldPacket << PlayerGUID;

    return &_worldPacket;
}

void ReclaimCorpse::Read()
{
    _worldPacket >> CorpseGUID;
}

void RepopRequest::Read()
{
    _worldPacket >> Bits<1>(CheckInstance);
}

WorldPacket const* RequestCemeteryListResponse::Write()
{
    _worldPacket << Bits<1>(IsGossipTriggered);
    _worldPacket.FlushBits();

    _worldPacket << Size<uint32>(CemeteryID);
    for (uint32 cemetery : CemeteryID)
        _worldPacket << cemetery;

    return &_worldPacket;
}

void ResurrectResponse::Read()
{
    _worldPacket >> Resurrecter;
    _worldPacket >> Response;
}

WorldPacket const* Weather::Write()
{
    _worldPacket << uint32(WeatherID);
    _worldPacket << float(Intensity);
    _worldPacket << Bits<1>(Abrupt);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void StandStateChange::Read()
{
    _worldPacket >> As<uint8>(StandState);
}

WorldPacket const* StandStateUpdate::Write()
{
    _worldPacket << As<uint8>(State);
    _worldPacket << uint32(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* SetAnimTier::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint8(Tier);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* PlayerBound::Write()
{
    _worldPacket << BinderID;
    _worldPacket << uint32(AreaID);

    return &_worldPacket;
}

WorldPacket const* StartMirrorTimer::Write()
{
    _worldPacket << uint8(Timer);
    _worldPacket << int32(Value);
    _worldPacket << int32(MaxValue);
    _worldPacket << int32(Scale);
    _worldPacket << int32(SpellID);
    _worldPacket << Bits<1>(Paused);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* PauseMirrorTimer::Write()
{
    _worldPacket << uint8(Timer);
    _worldPacket << Bits<1>(Paused);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* StopMirrorTimer::Write()
{
    _worldPacket << uint8(Timer);

    return &_worldPacket;
}

WorldPacket const* ExplorationExperience::Write()
{
    _worldPacket << int32(AreaID);
    _worldPacket << int32(Experience);

    return &_worldPacket;
}

WorldPacket const* LevelUpInfo::Write()
{
    _worldPacket << int32(Level);
    _worldPacket << int32(HealthDelta);

    for (int32 power : PowerDelta)
        _worldPacket << power;

    for (int32 stat : StatDelta)
        _worldPacket << stat;

    _worldPacket << int32(NumNewTalents);
    _worldPacket << int32(NumNewPvpTalentSlots);

    return &_worldPacket;
}

WorldPacket const* PlayMusic::Write()
{
    _worldPacket << uint32(SoundKitID);

    return &_worldPacket;
}

void RandomRollClient::Read()
{
    _worldPacket >> OptionalInit(PartyIndex);
    _worldPacket >> Min;
    _worldPacket >> Max;
    if (PartyIndex)
        _worldPacket >> *PartyIndex;
}

WorldPacket const* RandomRoll::Write()
{
    _worldPacket << Roller;
    _worldPacket << RollerWowAccount;
    _worldPacket << int32(Min);
    _worldPacket << int32(Max);
    _worldPacket << int32(Result);

    return &_worldPacket;
}

WorldPacket const* EnableBarberShop::Write()
{
    _worldPacket << uint32(CustomizationFeatureMask);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, PhaseShiftDataPhase const& phaseShiftDataPhase)
{
    data << uint32(phaseShiftDataPhase.PhaseFlags);
    data << uint16(phaseShiftDataPhase.Id);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, PhaseShiftData const& phaseShiftData)
{
    data << uint32(phaseShiftData.PhaseShiftFlags);
    data << WorldPackets::Size<uint32>(phaseShiftData.Phases);
    data << phaseShiftData.PersonalGUID;
    for (PhaseShiftDataPhase const& phaseShiftDataPhase : phaseShiftData.Phases)
        data << phaseShiftDataPhase;

    return data;
}

WorldPacket const* PhaseShiftChange::Write()
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

WorldPacket const* ZoneUnderAttack::Write()
{
    _worldPacket << int32(AreaID);

    return &_worldPacket;
}

WorldPacket const* DurabilityDamageDeath::Write()
{
    _worldPacket << int32(Percent);

    return &_worldPacket;
}

void ObjectUpdateFailed::Read()
{
    _worldPacket >> ObjectGUID;
}

void ObjectUpdateRescued::Read()
{
    _worldPacket >> ObjectGUID;
}

WorldPacket const* PlayObjectSound::Write()
{
    _worldPacket << int32(SoundKitID);
    _worldPacket << SourceObjectGUID;
    _worldPacket << TargetObjectGUID;
    _worldPacket << Position;
    _worldPacket << int32(BroadcastTextID);

    return &_worldPacket;
}

WorldPacket const* PlaySound::Write()
{
    _worldPacket << int32(SoundKitID);
    _worldPacket << SourceObjectGuid;
    _worldPacket << int32(BroadcastTextID);

    return &_worldPacket;
}

WorldPacket const* PlaySpeakerbotSound::Write()
{
    _worldPacket << SourceObjectGUID;
    _worldPacket << int32(SoundKitID);

    return &_worldPacket;
}

WorldPacket const* StopSpeakerbotSound::Write()
{
    _worldPacket << SourceObjectGUID;

    return &_worldPacket;
}

void FarSight::Read()
{
    _worldPacket >> Bits<1>(Enable);
}

void SaveCUFProfiles::Read()
{
    _worldPacket >> Size<uint32>(CUFProfiles);
    for (std::unique_ptr<CUFProfile>& cufProfile : CUFProfiles)
    {
        cufProfile = std::make_unique<CUFProfile>();

        _worldPacket >> SizedString::BitsSize<7>(cufProfile->ProfileName);

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

        _worldPacket >> SizedString::Data(cufProfile->ProfileName);
    }
}

WorldPacket const* LoadCUFProfiles::Write()
{
    _worldPacket << Size<uint32>(CUFProfiles);

    for (CUFProfile const* cufProfile : CUFProfiles)
    {
        _worldPacket << SizedString::BitsSize<7>(cufProfile->ProfileName);

        // Bool Options
        for (uint8 option = 0; option < CUF_BOOL_OPTIONS_COUNT; option++)
            _worldPacket.WriteBit(cufProfile->BoolOptions[option]);

        // Other Options
        _worldPacket << uint16(cufProfile->FrameHeight);
        _worldPacket << uint16(cufProfile->FrameWidth);

        _worldPacket << uint8(cufProfile->SortBy);
        _worldPacket << uint8(cufProfile->HealthText);

        _worldPacket << uint8(cufProfile->TopPoint);
        _worldPacket << uint8(cufProfile->BottomPoint);
        _worldPacket << uint8(cufProfile->LeftPoint);

        _worldPacket << uint16(cufProfile->TopOffset);
        _worldPacket << uint16(cufProfile->BottomOffset);
        _worldPacket << uint16(cufProfile->LeftOffset);

        _worldPacket << SizedString::Data(cufProfile->ProfileName);
    }

    return &_worldPacket;
}

WorldPacket const* PlayOneShotAnimKit::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint16(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* SetAIAnimKit::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint16(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* SetMovementAnimKit::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint16(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* SetMeleeAnimKit::Write()
{
    _worldPacket << Unit;
    _worldPacket << uint16(AnimKitID);

    return &_worldPacket;
}

WorldPacket const* SetPlayHoverAnim::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << Bits<1>(PlayHoverAnim);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

void SetPvP::Read()
{
    _worldPacket >> Bits<1>(EnablePVP);
}

void SetWarMode::Read()
{
    _worldPacket >> Bits<1>(Enable);
}

WorldPacket const* AccountHeirloomUpdate::Write()
{
    _worldPacket << Bits<1>(IsFullUpdate);
    _worldPacket.FlushBits();

    _worldPacket << int8(ItemCollectionType);

    // both lists have to have the same size
    _worldPacket << Size<uint32>(*Heirlooms);
    _worldPacket << Size<uint32>(*Heirlooms);

    for (auto const& [itemId, _] : *Heirlooms)
        _worldPacket << int32(itemId);

    for (auto const& [_, data] : *Heirlooms)
        _worldPacket << uint32(data.flags);

    return &_worldPacket;
}

void MountSpecial::Read()
{
    _worldPacket >> Size<uint32>(SpellVisualKitIDs);
    _worldPacket >> SequenceVariation;
    for (int32& spellVisualKitId : SpellVisualKitIDs)
        _worldPacket >> spellVisualKitId;
}

WorldPacket const* SpecialMountAnim::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << Size<uint32>(SpellVisualKitIDs);
    _worldPacket << int32(SequenceVariation);
    if (!SpellVisualKitIDs.empty())
        _worldPacket.append(SpellVisualKitIDs.data(), SpellVisualKitIDs.size());

    return &_worldPacket;
}

WorldPacket const* CrossedInebriationThreshold::Write()
{
    _worldPacket << Guid;
    _worldPacket << int32(Threshold);
    _worldPacket << int32(ItemID);

    return &_worldPacket;
}

void SetTaxiBenchmarkMode::Read()
{
    _worldPacket >> Bits<1>(Enable);
}

WorldPacket const* OverrideLight::Write()
{
    _worldPacket << int32(AreaLightID);
    _worldPacket << int32(OverrideLightID);
    _worldPacket << int32(TransitionMilliseconds);

    return &_worldPacket;
}

WorldPacket const* DisplayGameError::Write()
{
    _worldPacket << uint32(Error);
    _worldPacket << OptionalInit(Arg);
    _worldPacket << OptionalInit(Arg2);
    _worldPacket.FlushBits();

    if (Arg)
        _worldPacket << int32(*Arg);

    if (Arg2)
        _worldPacket << int32(*Arg2);

    return &_worldPacket;
}

WorldPacket const* AccountMountUpdate::Write()
{
    _worldPacket << Bits<1>(IsFullUpdate);
    _worldPacket << Size<uint32>(*Mounts);

    for (auto const& [spellId, flags] : *Mounts)
    {
        _worldPacket << int32(spellId);
        _worldPacket << Bits<4>(flags);
    }

    _worldPacket.FlushBits();

    return &_worldPacket;
}

void MountSetFavorite::Read()
{
    _worldPacket >> MountSpellID;
    _worldPacket >> Bits<1>(IsFavorite);
}

void CloseInteraction::Read()
{
    _worldPacket >> SourceGuid;
}

WorldPacket const* StartTimer::Write()
{
    _worldPacket << TotalTime;
    _worldPacket << int32(Type);
    _worldPacket << TimeLeft;
    _worldPacket << OptionalInit(PlayerGuid);
    _worldPacket.FlushBits();

    if (PlayerGuid)
        _worldPacket << *PlayerGuid;

    return &_worldPacket;
}

void QueryCountdownTimer::Read()
{
    _worldPacket >> As<int32>(TimerType);
}

void ConversationLineStarted::Read()
{
    _worldPacket >> ConversationGUID;
    _worldPacket >> LineID;
}

WorldPacket const* SplashScreenShowLatest::Write()
{
    _worldPacket << int32(UISplashScreenID);

    return &_worldPacket;
}

WorldPacket const* DisplayToast::Write()
{
    _worldPacket << uint64(Quantity);
    _worldPacket << As<uint8>(DisplayToastMethod);
    _worldPacket << uint32(QuestID);

    _worldPacket << Bits<1>(Mailed);
    _worldPacket << Bits<2>(Type);
    _worldPacket << Bits<1>(IsSecondaryResult);

    switch (Type)
    {
        case DisplayToastType::NewItem:
            _worldPacket << Bits<1>(BonusRoll);
            _worldPacket << Bits<1>(ForceToast);
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

WorldPacket const* AccountWarbandSceneUpdate::Write()
{
    _worldPacket << Bits<1>(IsFullUpdate);
    _worldPacket << Size<uint32>(*WarbandScenes);
    _worldPacket << Size<uint32>(*WarbandScenes);
    _worldPacket << Size<uint32>(*WarbandScenes);

    for (auto const& [warbandSceneId, _] : *WarbandScenes)
        _worldPacket << uint32(warbandSceneId);

    for (auto const& [_, data] : *WarbandScenes)
        _worldPacket << Bits<1>(data.Flags.HasFlag(WarbandSceneCollectionFlags::Favorite));

    for (auto const& [_, data] : *WarbandScenes)
        _worldPacket << Bits<1>(data.Flags.HasFlag(WarbandSceneCollectionFlags::HasFanfare));

    _worldPacket.FlushBits();

    return &_worldPacket;
}
}
