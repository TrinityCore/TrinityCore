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

#include "SystemPackets.h"

namespace WorldPackets::System
{
ByteBuffer& operator<<(ByteBuffer& data, SavedThrottleObjectState const& throttleState)
{
    data << uint32(throttleState.MaxTries);
    data << uint32(throttleState.PerMilliseconds);
    data << uint32(throttleState.TryCount);
    data << uint32(throttleState.LastResetTimeBeforeNow);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, EuropaTicketConfig const& europaTicketSystemStatus)
{
    data.WriteBit(europaTicketSystemStatus.TicketsEnabled);
    data.WriteBit(europaTicketSystemStatus.BugsEnabled);
    data.WriteBit(europaTicketSystemStatus.ComplaintsEnabled);
    data.WriteBit(europaTicketSystemStatus.SuggestionsEnabled);

    data << europaTicketSystemStatus.ThrottleState;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, GameRuleValuePair const& gameRuleValue)
{
    data << int32(gameRuleValue.Rule);
    data << int32(gameRuleValue.Value);
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, DebugTimeEventInfo const& debugTimeEventInfo)
{
    data << uint32(debugTimeEventInfo.TimeEvent);
    data.WriteBits(debugTimeEventInfo.Text.length(), 7);
    data.FlushBits();

    data.WriteString(debugTimeEventInfo.Text);

    return data;
}

WorldPacket const* FeatureSystemStatus::Write()
{
    _worldPacket << uint8(ComplaintStatus);

    _worldPacket << uint32(CfgRealmID);
    _worldPacket << int32(CfgRealmRecID);

    _worldPacket << uint32(RAFSystem.MaxRecruits);
    _worldPacket << uint32(RAFSystem.MaxRecruitMonths);
    _worldPacket << uint32(RAFSystem.MaxRecruitmentUses);
    _worldPacket << uint32(RAFSystem.DaysInCycle);
    _worldPacket << uint32(RAFSystem.Unknown1007);

    _worldPacket << uint32(TokenPollTimeSeconds);
    _worldPacket << uint32(KioskSessionMinutes);
    _worldPacket << int64(TokenBalanceAmount);

    _worldPacket << uint32(BpayStoreProductDeliveryDelay);

    _worldPacket << uint32(ClubsPresenceUpdateTimer);
    _worldPacket << uint32(HiddenUIClubsPresenceUpdateTimer);

    _worldPacket << int32(ActiveSeason);
    _worldPacket << uint32(GameRuleValues.size());

    _worldPacket << int16(MaxPlayerNameQueriesPerPacket);
    _worldPacket << int16(PlayerNameQueryTelemetryInterval);
    _worldPacket << PlayerNameQueryInterval;

    for (GameRuleValuePair const& gameRuleValue : GameRuleValues)
        _worldPacket << gameRuleValue;

    _worldPacket.WriteBit(VoiceEnabled);
    _worldPacket.WriteBit(EuropaTicketSystemStatus.has_value());
    _worldPacket.WriteBit(BpayStoreEnabled);
    _worldPacket.WriteBit(BpayStoreAvailable);
    _worldPacket.WriteBit(BpayStoreDisabledByParentalControls);
    _worldPacket.WriteBit(ItemRestorationButtonEnabled);
    _worldPacket.WriteBit(BrowserEnabled);
    _worldPacket.WriteBit(SessionAlert.has_value());

    _worldPacket.WriteBit(RAFSystem.Enabled);
    _worldPacket.WriteBit(RAFSystem.RecruitingEnabled);
    _worldPacket.WriteBit(CharUndeleteEnabled);
    _worldPacket.WriteBit(RestrictedAccount);
    _worldPacket.WriteBit(CommerceSystemEnabled);
    _worldPacket.WriteBit(TutorialsEnabled);
    _worldPacket.WriteBit(Unk67);
    _worldPacket.WriteBit(WillKickFromWorld);

    _worldPacket.WriteBit(KioskModeEnabled);
    _worldPacket.WriteBit(CompetitiveModeEnabled);
    _worldPacket.WriteBit(TokenBalanceEnabled);
    _worldPacket.WriteBit(WarModeFeatureEnabled);
    _worldPacket.WriteBit(ClubsEnabled);
    _worldPacket.WriteBit(ClubsBattleNetClubTypeAllowed);
    _worldPacket.WriteBit(ClubsCharacterClubTypeAllowed);
    _worldPacket.WriteBit(ClubsPresenceUpdateEnabled);

    _worldPacket.WriteBit(VoiceChatDisabledByParentalControl);
    _worldPacket.WriteBit(VoiceChatMutedByParentalControl);
    _worldPacket.WriteBit(QuestSessionEnabled);
    _worldPacket.WriteBit(IsMuted);
    _worldPacket.WriteBit(ClubFinderEnabled);
    _worldPacket.WriteBit(Unknown901CheckoutRelated);
    _worldPacket.WriteBit(TextToSpeechFeatureEnabled);
    _worldPacket.WriteBit(ChatDisabledByDefault);

    _worldPacket.WriteBit(ChatDisabledByPlayer);
    _worldPacket.WriteBit(LFGListCustomRequiresAuthenticator);
    _worldPacket.WriteBit(AddonsDisabled);
    _worldPacket.WriteBit(WarGamesEnabled);
    _worldPacket.WriteBit(false);                   // unk, unused 4.4.0
    _worldPacket.WriteBit(false);                   // unk, unused 4.4.0
    _worldPacket.WriteBit(ContentTrackingEnabled);
    _worldPacket.WriteBit(IsSellAllJunkEnabled);

    _worldPacket.WriteBit(IsGroupFinderEnabled);
    _worldPacket.WriteBit(IsLFDEnabled);
    _worldPacket.WriteBit(IsLFREnabled);
    _worldPacket.WriteBit(IsPremadeGroupEnabled);

    _worldPacket.WriteBits(Field_16F.size(), 8);

    _worldPacket.FlushBits();

    {
        _worldPacket.WriteBit(QuickJoinConfig.ToastsDisabled);
        _worldPacket << float(QuickJoinConfig.ToastDuration);
        _worldPacket << float(QuickJoinConfig.DelayDuration);
        _worldPacket << float(QuickJoinConfig.QueueMultiplier);
        _worldPacket << float(QuickJoinConfig.PlayerMultiplier);
        _worldPacket << float(QuickJoinConfig.PlayerFriendValue);
        _worldPacket << float(QuickJoinConfig.PlayerGuildValue);
        _worldPacket << float(QuickJoinConfig.ThrottleInitialThreshold);
        _worldPacket << float(QuickJoinConfig.ThrottleDecayTime);
        _worldPacket << float(QuickJoinConfig.ThrottlePrioritySpike);
        _worldPacket << float(QuickJoinConfig.ThrottleMinThreshold);
        _worldPacket << float(QuickJoinConfig.ThrottlePvPPriorityNormal);
        _worldPacket << float(QuickJoinConfig.ThrottlePvPPriorityLow);
        _worldPacket << float(QuickJoinConfig.ThrottlePvPHonorThreshold);
        _worldPacket << float(QuickJoinConfig.ThrottleLfgListPriorityDefault);
        _worldPacket << float(QuickJoinConfig.ThrottleLfgListPriorityAbove);
        _worldPacket << float(QuickJoinConfig.ThrottleLfgListPriorityBelow);
        _worldPacket << float(QuickJoinConfig.ThrottleLfgListIlvlScalingAbove);
        _worldPacket << float(QuickJoinConfig.ThrottleLfgListIlvlScalingBelow);
        _worldPacket << float(QuickJoinConfig.ThrottleRfPriorityAbove);
        _worldPacket << float(QuickJoinConfig.ThrottleRfIlvlScalingAbove);
        _worldPacket << float(QuickJoinConfig.ThrottleDfMaxItemLevel);
        _worldPacket << float(QuickJoinConfig.ThrottleDfBestPriority);
    }

    if (SessionAlert)
    {
        _worldPacket << int32(SessionAlert->Delay);
        _worldPacket << int32(SessionAlert->Period);
        _worldPacket << int32(SessionAlert->DisplayTime);
    }

    if (!Field_16F.empty())
        _worldPacket.WriteString(Field_16F);

    {
        _worldPacket.WriteBit(Squelch.IsSquelched);
        _worldPacket << Squelch.BnetAccountGuid;
        _worldPacket << Squelch.GuildGuid;
    }

    if (EuropaTicketSystemStatus)
        _worldPacket << *EuropaTicketSystemStatus;

    return &_worldPacket;
}

WorldPacket const* FeatureSystemStatusGlueScreen::Write()
{
    _worldPacket.WriteBit(BpayStoreEnabled);
    _worldPacket.WriteBit(BpayStoreAvailable);
    _worldPacket.WriteBit(BpayStoreDisabledByParentalControls);
    _worldPacket.WriteBit(CharUndeleteEnabled);
    _worldPacket.WriteBit(CommerceSystemEnabled);
    _worldPacket.WriteBit(Unk14);
    _worldPacket.WriteBit(WillKickFromWorld);
    _worldPacket.WriteBit(IsExpansionPreorderInStore);

    _worldPacket.WriteBit(KioskModeEnabled);
    _worldPacket.WriteBit(CompetitiveModeEnabled);
    _worldPacket.WriteBit(IsBoostEnabled);
    _worldPacket.WriteBit(TrialBoostEnabled);
    _worldPacket.WriteBit(TokenBalanceEnabled);
    _worldPacket.WriteBit(LiveRegionCharacterListEnabled);
    _worldPacket.WriteBit(LiveRegionCharacterCopyEnabled);
    _worldPacket.WriteBit(LiveRegionAccountCopyEnabled);

    _worldPacket.WriteBit(LiveRegionKeyBindingsCopyEnabled);
    _worldPacket.WriteBit(Unknown901CheckoutRelated);
    _worldPacket.WriteBit(false); // unused, 10.0.2
    _worldPacket.WriteBit(EuropaTicketSystemStatus.has_value());
    _worldPacket.WriteBit(IsNameReservationEnabled);
    _worldPacket.WriteBit(LaunchETA.has_value());
    _worldPacket.WriteBit(false); // unused, 4.4.0
    _worldPacket.WriteBit(false); // unused, 4.4.0

    _worldPacket.WriteBit(false); // unused, 4.4.0
    _worldPacket.WriteBit(IsSoMNotificationEnabled);
    _worldPacket.WriteBit(AddonsDisabled);
    _worldPacket.WriteBit(Unused1000);
    _worldPacket.WriteBit(AccountSaveDataExportEnabled);
    _worldPacket.WriteBit(AccountLockedByExport);
    _worldPacket.WriteBit(RealmHiddenAlert.has_value());

    if (RealmHiddenAlert)
        _worldPacket.WriteBits(RealmHiddenAlert->length() + 1, 11);

    _worldPacket.FlushBits();

    if (EuropaTicketSystemStatus)
        _worldPacket << *EuropaTicketSystemStatus;

    _worldPacket << uint32(TokenPollTimeSeconds);
    _worldPacket << uint32(KioskSessionMinutes);
    _worldPacket << int64(TokenBalanceAmount);
    _worldPacket << int32(MaxCharactersPerRealm);
    _worldPacket << uint32(LiveRegionCharacterCopySourceRegions.size());
    _worldPacket << uint32(BpayStoreProductDeliveryDelay);
    _worldPacket << int32(ActiveCharacterUpgradeBoostType);
    _worldPacket << int32(ActiveClassTrialBoostType);
    _worldPacket << int32(MinimumExpansionLevel);
    _worldPacket << int32(MaximumExpansionLevel);
    _worldPacket << int32(ActiveSeason);
    _worldPacket << uint32(GameRuleValues.size());
    _worldPacket << int16(MaxPlayerNameQueriesPerPacket);
    _worldPacket << int16(PlayerNameQueryTelemetryInterval);
    _worldPacket << PlayerNameQueryInterval;
    _worldPacket << uint32(DebugTimeEvents.size());
    _worldPacket << int32(Unused1007);
    _worldPacket << int32(EventRealmQueues);

    if (LaunchETA)
        _worldPacket << int32(*LaunchETA);

    if (RealmHiddenAlert && !RealmHiddenAlert->empty())
        _worldPacket.WriteString(*RealmHiddenAlert);

    if (!LiveRegionCharacterCopySourceRegions.empty())
        _worldPacket.append(LiveRegionCharacterCopySourceRegions.data(), LiveRegionCharacterCopySourceRegions.size());

    for (GameRuleValuePair const& gameRuleValue : GameRuleValues)
        _worldPacket << gameRuleValue;

    for (DebugTimeEventInfo const& debugTimeEventInfo : DebugTimeEvents)
        _worldPacket << debugTimeEventInfo;

    return &_worldPacket;
}

WorldPacket const* SetTimeZoneInformation::Write()
{
    _worldPacket.WriteBits(ServerTimeTZ.length(), 7);
    _worldPacket.WriteBits(GameTimeTZ.length(), 7);
    _worldPacket.WriteBits(ServerRegionalTZ.length(), 7);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(ServerTimeTZ);
    _worldPacket.WriteString(GameTimeTZ);
    _worldPacket.WriteString(ServerRegionalTZ);

    return &_worldPacket;
}
}
