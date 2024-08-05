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
    data << Bits<1>(europaTicketSystemStatus.TicketsEnabled);
    data << Bits<1>(europaTicketSystemStatus.BugsEnabled);
    data << Bits<1>(europaTicketSystemStatus.ComplaintsEnabled);
    data << Bits<1>(europaTicketSystemStatus.SuggestionsEnabled);

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
    data << BitsSize<7>(debugTimeEventInfo.Text);
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
    _worldPacket << int32(ActiveTimerunningSeasonID);
    _worldPacket << int32(RemainingTimerunningSeasonSeconds);

    _worldPacket << int16(MaxPlayerNameQueriesPerPacket);
    _worldPacket << int16(PlayerNameQueryTelemetryInterval);
    _worldPacket << PlayerNameQueryInterval;

    _worldPacket << int32(AddonChatThrottle.MaxTries);
    _worldPacket << int32(AddonChatThrottle.TriesRestoredPerSecond);
    _worldPacket << int32(AddonChatThrottle.UsedTriesPerMessage);

    for (GameRuleValuePair const& gameRuleValue : GameRuleValues)
        _worldPacket << gameRuleValue;

    _worldPacket << Bits<1>(VoiceEnabled);
    _worldPacket << OptionalInit(EuropaTicketSystemStatus);
    _worldPacket << Bits<1>(BpayStoreEnabled);
    _worldPacket << Bits<1>(BpayStoreAvailable);
    _worldPacket << Bits<1>(BpayStoreDisabledByParentalControls);
    _worldPacket << Bits<1>(ItemRestorationButtonEnabled);
    _worldPacket << Bits<1>(BrowserEnabled);
    _worldPacket << OptionalInit(SessionAlert);

    _worldPacket << Bits<1>(RAFSystem.Enabled);
    _worldPacket << Bits<1>(RAFSystem.RecruitingEnabled);
    _worldPacket << Bits<1>(CharUndeleteEnabled);
    _worldPacket << Bits<1>(RestrictedAccount);
    _worldPacket << Bits<1>(CommerceSystemEnabled);
    _worldPacket << Bits<1>(TutorialsEnabled);
    _worldPacket << Bits<1>(Unk67);
    _worldPacket << Bits<1>(WillKickFromWorld);

    _worldPacket << Bits<1>(KioskModeEnabled);
    _worldPacket << Bits<1>(CompetitiveModeEnabled);
    _worldPacket << Bits<1>(TokenBalanceEnabled);
    _worldPacket << Bits<1>(WarModeFeatureEnabled);
    _worldPacket << Bits<1>(ClubsEnabled);
    _worldPacket << Bits<1>(ClubsBattleNetClubTypeAllowed);
    _worldPacket << Bits<1>(ClubsCharacterClubTypeAllowed);
    _worldPacket << Bits<1>(ClubsPresenceUpdateEnabled);

    _worldPacket << Bits<1>(VoiceChatDisabledByParentalControl);
    _worldPacket << Bits<1>(VoiceChatMutedByParentalControl);
    _worldPacket << Bits<1>(QuestSessionEnabled);
    _worldPacket << Bits<1>(IsMuted);
    _worldPacket << Bits<1>(ClubFinderEnabled);
    _worldPacket << Bits<1>(CommunityFinderEnabled);
    _worldPacket << Bits<1>(Unknown901CheckoutRelated);
    _worldPacket << Bits<1>(TextToSpeechFeatureEnabled);

    _worldPacket << Bits<1>(ChatDisabledByDefault);
    _worldPacket << Bits<1>(ChatDisabledByPlayer);
    _worldPacket << Bits<1>(LFGListCustomRequiresAuthenticator);
    _worldPacket << Bits<1>(AddonsDisabled);
    _worldPacket << Bits<1>(TimerunningEnabled);
    _worldPacket << Bits<1>(WarGamesEnabled);
    _worldPacket << Bits<1>(ContentTrackingEnabled);
    _worldPacket << Bits<1>(IsSellAllJunkEnabled);

    _worldPacket << Bits<1>(IsGroupFinderEnabled);
    _worldPacket << Bits<1>(IsLFDEnabled);
    _worldPacket << Bits<1>(IsLFREnabled);
    _worldPacket << Bits<1>(IsPremadeGroupEnabled);
    _worldPacket << Bits<1>(CanShowSetRoleButton);
    _worldPacket << Bits<1>(false); // unused 10.2.7
    _worldPacket << Bits<1>(GuildEventsEditsEnabled);
    _worldPacket << Bits<1>(GuildTradeSkillsEnabled);

    _worldPacket << BitsSize<7>(Unknown1027);
    _worldPacket << Bits<1>(BNSendWhisperUseV2Services);

    _worldPacket << Bits<1>(BNSendGameDataUseV2Services);
    _worldPacket << Bits<1>(IsAccountCurrencyTransferEnabled);

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

    _worldPacket.WriteString(Unknown1027);

    {
        _worldPacket << Bits<1>(Squelch.IsSquelched);
        _worldPacket << Squelch.BnetAccountGuid;
        _worldPacket << Squelch.GuildGuid;
    }

    if (EuropaTicketSystemStatus)
        _worldPacket << *EuropaTicketSystemStatus;

    return &_worldPacket;
}

WorldPacket const* FeatureSystemStatusGlueScreen::Write()
{
    _worldPacket << Bits<1>(BpayStoreEnabled);
    _worldPacket << Bits<1>(BpayStoreAvailable);
    _worldPacket << Bits<1>(BpayStoreDisabledByParentalControls);
    _worldPacket << Bits<1>(CharUndeleteEnabled);
    _worldPacket << Bits<1>(CommerceSystemEnabled);
    _worldPacket << Bits<1>(Unk14);
    _worldPacket << Bits<1>(WillKickFromWorld);
    _worldPacket << Bits<1>(IsExpansionPreorderInStore);

    _worldPacket << Bits<1>(KioskModeEnabled);
    _worldPacket << Bits<1>(CompetitiveModeEnabled);
    _worldPacket << Bits<1>(IsBoostEnabled);
    _worldPacket << Bits<1>(TrialBoostEnabled);
    _worldPacket << Bits<1>(TokenBalanceEnabled);
    _worldPacket << Bits<1>(PaidCharacterTransfersBetweenBnetAccountsEnabled);
    _worldPacket << Bits<1>(LiveRegionCharacterListEnabled);
    _worldPacket << Bits<1>(LiveRegionCharacterCopyEnabled);

    _worldPacket << Bits<1>(LiveRegionAccountCopyEnabled);
    _worldPacket << Bits<1>(LiveRegionKeyBindingsCopyEnabled);
    _worldPacket << Bits<1>(Unknown901CheckoutRelated);
    _worldPacket << Bits<1>(false); // unused, 10.0.2
    _worldPacket << OptionalInit(EuropaTicketSystemStatus);
    _worldPacket << Bits<1>(IsNameReservationEnabled);
    _worldPacket << OptionalInit(LaunchETA);
    _worldPacket << Bits<1>(TimerunningEnabled);

    _worldPacket << Bits<1>(AddonsDisabled);
    _worldPacket << Bits<1>(Unused1000);
    _worldPacket << Bits<1>(AccountSaveDataExportEnabled);
    _worldPacket << Bits<1>(AccountLockedByExport);

    _worldPacket << Bits<11>(RealmHiddenAlert.length() + 1);

    _worldPacket << Bits<1>(BNSendWhisperUseV2Services);

    _worldPacket << Bits<1>(BNSendGameDataUseV2Services);
    _worldPacket << Bits<1>(CharacterSelectListModeRealmless);

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
    _worldPacket << int32(ActiveTimerunningSeasonID);
    _worldPacket << int32(RemainingTimerunningSeasonSeconds);
    _worldPacket << int16(MaxPlayerNameQueriesPerPacket);
    _worldPacket << int16(PlayerNameQueryTelemetryInterval);
    _worldPacket << PlayerNameQueryInterval;
    _worldPacket << uint32(DebugTimeEvents.size());
    _worldPacket << int32(Unused1007);
    _worldPacket << uint32(EventRealmQueues);

    if (LaunchETA)
        _worldPacket << int32(*LaunchETA);

    if (!RealmHiddenAlert.empty())
        _worldPacket << RealmHiddenAlert;

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
    _worldPacket << BitsSize<7>(ServerTimeTZ);
    _worldPacket << BitsSize<7>(GameTimeTZ);
    _worldPacket << BitsSize<7>(ServerRegionalTZ);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(ServerTimeTZ);
    _worldPacket.WriteString(GameTimeTZ);
    _worldPacket.WriteString(ServerRegionalTZ);

    return &_worldPacket;
}
}
