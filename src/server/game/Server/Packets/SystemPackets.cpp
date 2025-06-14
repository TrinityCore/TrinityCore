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
#include "PacketOperators.h"

namespace WorldPackets::System
{
ByteBuffer& operator<<(ByteBuffer& data, SocialQueueConfig const& socialQueueConfig)
{
    data << Bits<1>(socialQueueConfig.ToastsDisabled);
    data << float(socialQueueConfig.ToastDuration);
    data << float(socialQueueConfig.DelayDuration);
    data << float(socialQueueConfig.QueueMultiplier);
    data << float(socialQueueConfig.PlayerMultiplier);
    data << float(socialQueueConfig.PlayerFriendValue);
    data << float(socialQueueConfig.PlayerGuildValue);
    data << float(socialQueueConfig.ThrottleInitialThreshold);
    data << float(socialQueueConfig.ThrottleDecayTime);
    data << float(socialQueueConfig.ThrottlePrioritySpike);
    data << float(socialQueueConfig.ThrottleMinThreshold);
    data << float(socialQueueConfig.ThrottlePvPPriorityNormal);
    data << float(socialQueueConfig.ThrottlePvPPriorityLow);
    data << float(socialQueueConfig.ThrottlePvPHonorThreshold);
    data << float(socialQueueConfig.ThrottleLfgListPriorityDefault);
    data << float(socialQueueConfig.ThrottleLfgListPriorityAbove);
    data << float(socialQueueConfig.ThrottleLfgListPriorityBelow);
    data << float(socialQueueConfig.ThrottleLfgListIlvlScalingAbove);
    data << float(socialQueueConfig.ThrottleLfgListIlvlScalingBelow);
    data << float(socialQueueConfig.ThrottleRfPriorityAbove);
    data << float(socialQueueConfig.ThrottleRfIlvlScalingAbove);
    data << float(socialQueueConfig.ThrottleDfMaxItemLevel);
    data << float(socialQueueConfig.ThrottleDfBestPriority);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, SessionAlertConfig const& sessionAlert)
{
    data << int32(sessionAlert.Delay);
    data << int32(sessionAlert.Period);
    data << int32(sessionAlert.DisplayTime);

    return data;
}

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

ByteBuffer& operator<<(ByteBuffer& data, SquelchInfo const& squelch)
{
    data << Bits<1>(squelch.IsSquelched);
    data << squelch.BnetAccountGuid;
    data << squelch.GuildGuid;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, GameRuleValuePair const& gameRuleValue)
{
    data << int32(gameRuleValue.Rule);
    data << int32(gameRuleValue.Value);
    data << float(gameRuleValue.ValueF);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, DebugTimeEventInfo const& debugTimeEventInfo)
{
    data << uint32(debugTimeEventInfo.TimeEvent);
    data << SizedString::BitsSize<7>(debugTimeEventInfo.Text);
    data.FlushBits();

    data << SizedString::Data(debugTimeEventInfo.Text);

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
    _worldPacket << uint32(RAFSystem.RewardsVersion);

    _worldPacket << uint32(CommercePricePollTimeSeconds);
    _worldPacket << uint32(KioskSessionDurationMinutes);
    _worldPacket << int64(RedeemForBalanceAmount);

    _worldPacket << uint32(BpayStorePurchaseTimeout);

    _worldPacket << uint32(ClubsPresenceDelay);
    _worldPacket << uint32(ClubPresenceUnsubscribeDelay);

    _worldPacket << int32(ContentSetID);
    _worldPacket << Size<uint32>(GameRules);
    _worldPacket << int32(ActiveTimerunningSeasonID);
    _worldPacket << int32(RemainingTimerunningSeasonSeconds);

    _worldPacket << int16(MaxPlayerGuidLookupsPerRequest);
    _worldPacket << int16(NameLookupTelemetryInterval);
    _worldPacket << NotFoundCacheTimeSeconds;

    _worldPacket << uint32(RealmPvpTypeOverride);

    _worldPacket << int32(AddonChatThrottle.MaxTries);
    _worldPacket << int32(AddonChatThrottle.TriesRestoredPerSecond);
    _worldPacket << int32(AddonChatThrottle.UsedTriesPerMessage);

    _worldPacket << float(AddonPerformanceMsgWarning);
    _worldPacket << float(AddonPerformanceMsgError);
    _worldPacket << float(AddonPerformanceMsgOverall);

    for (GameRuleValuePair const& gameRuleValue : GameRules)
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
    _worldPacket << Bits<1>(CommerceServerEnabled);
    _worldPacket << Bits<1>(TutorialEnabled);
    _worldPacket << Bits<1>(VeteranTokenRedeemWillKick);
    _worldPacket << Bits<1>(WorldTokenRedeemWillKick);

    _worldPacket << Bits<1>(KioskModeEnabled);
    _worldPacket << Bits<1>(CompetitiveModeEnabled);
    _worldPacket << Bits<1>(RedeemForBalanceAvailable);
    _worldPacket << Bits<1>(WarModeEnabled);
    _worldPacket << Bits<1>(CommunitiesEnabled);
    _worldPacket << Bits<1>(BnetGroupsEnabled);
    _worldPacket << Bits<1>(CharacterCommunitiesEnabled);
    _worldPacket << Bits<1>(ClubPresenceAllowSubscribeAll);

    _worldPacket << Bits<1>(VoiceChatParentalDisabled);
    _worldPacket << Bits<1>(VoiceChatParentalMuted);
    _worldPacket << Bits<1>(QuestSessionEnabled);
    _worldPacket << Bits<1>(IsChatMuted);
    _worldPacket << Bits<1>(ClubFinderEnabled);
    _worldPacket << Bits<1>(CommunityFinderEnabled);
    _worldPacket << Bits<1>(BrowserCrashReporterEnabled);
    _worldPacket << Bits<1>(SpeakForMeAllowed);

    _worldPacket << Bits<1>(DoesAccountNeedAADCPrompt);
    _worldPacket << Bits<1>(IsAccountOptedInToAADC);
    _worldPacket << Bits<1>(LfgRequireAuthenticatorEnabled);
    _worldPacket << Bits<1>(ScriptsDisallowedForBeta);
    _worldPacket << Bits<1>(TimerunningEnabled);
    _worldPacket << Bits<1>(WarGamesEnabled);
    _worldPacket << Bits<1>(IsPlayerContentTrackingEnabled);
    _worldPacket << Bits<1>(SellAllJunkEnabled);

    _worldPacket << Bits<1>(GroupFinderEnabled);
    _worldPacket << Bits<1>(IsPremadeGroupEnabled);
    _worldPacket << Bits<1>(false); // unused 10.2.7
    _worldPacket << Bits<1>(GuildEventsEditsEnabled);
    _worldPacket << Bits<1>(GuildTradeSkillsEnabled);
    _worldPacket << SizedString::BitsSize<7>(Unknown1027);
    _worldPacket << Bits<1>(BNSendWhisperUseV2Services);
    _worldPacket << Bits<1>(BNSendGameDataUseV2Services);
    _worldPacket << Bits<1>(IsAccountCurrencyTransferEnabled);
    _worldPacket << Bits<1>(false); // unused 11.0.7

    _worldPacket << Bits<1>(LobbyMatchmakerQueueFromMainlineEnabled);
    _worldPacket << Bits<1>(CanSendLobbyMatchmakerPartyCustomizations);
    _worldPacket << Bits<1>(AddonProfilerEnabled);

    _worldPacket.FlushBits();

    _worldPacket << QuickJoinConfig;

    if (SessionAlert)
        _worldPacket << *SessionAlert;

    _worldPacket << SizedString::Data(Unknown1027);

    _worldPacket << Squelch;

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
    _worldPacket << Bits<1>(CommerceServerEnabled);
    _worldPacket << Bits<1>(VeteranTokenRedeemWillKick);
    _worldPacket << Bits<1>(WorldTokenRedeemWillKick);
    _worldPacket << Bits<1>(ExpansionPreorderInStore);

    _worldPacket << Bits<1>(KioskModeEnabled);
    _worldPacket << Bits<1>(CompetitiveModeEnabled);
    _worldPacket << Bits<1>(BoostEnabled);
    _worldPacket << Bits<1>(TrialBoostEnabled);
    _worldPacket << Bits<1>(RedeemForBalanceAvailable);
    _worldPacket << Bits<1>(PaidCharacterTransfersBetweenBnetAccountsEnabled);
    _worldPacket << Bits<1>(LiveRegionCharacterListEnabled);
    _worldPacket << Bits<1>(LiveRegionCharacterCopyEnabled);

    _worldPacket << Bits<1>(LiveRegionAccountCopyEnabled);
    _worldPacket << Bits<1>(LiveRegionKeyBindingsCopyEnabled);
    _worldPacket << Bits<1>(BrowserCrashReporterEnabled);
    _worldPacket << Bits<1>(IsEmployeeAccount);
    _worldPacket << OptionalInit(EuropaTicketSystemStatus);
    _worldPacket << Bits<1>(NameReservationOnly);
    _worldPacket << OptionalInit(LaunchDurationETA);
    _worldPacket << Bits<1>(TimerunningEnabled);

    _worldPacket << Bits<1>(ScriptsDisallowedForBeta);
    _worldPacket << Bits<1>(PlayerIdentityOptionsEnabled);
    _worldPacket << Bits<1>(AccountExportEnabled);
    _worldPacket << Bits<1>(AccountLockedPostExport);

    _worldPacket << SizedCString::BitsSize<11>(RealmHiddenAlert);

    _worldPacket << Bits<1>(BNSendWhisperUseV2Services);

    _worldPacket << Bits<1>(BNSendGameDataUseV2Services);
    _worldPacket << Bits<1>(CharacterSelectListModeRealmless);

    _worldPacket.FlushBits();

    if (EuropaTicketSystemStatus)
        _worldPacket << *EuropaTicketSystemStatus;

    _worldPacket << uint32(CommercePricePollTimeSeconds);
    _worldPacket << uint32(KioskSessionDurationMinutes);
    _worldPacket << int64(RedeemForBalanceAmount);
    _worldPacket << int32(MaxCharactersOnThisRealm);
    _worldPacket << Size<uint32>(LiveRegionCharacterCopySourceRegions);
    _worldPacket << uint32(BpayStorePurchaseTimeout);
    _worldPacket << int32(ActiveBoostType);
    _worldPacket << int32(TrialBoostType);
    _worldPacket << int32(MinimumExpansionLevel);
    _worldPacket << int32(MaximumExpansionLevel);
    _worldPacket << int32(ContentSetID);
    _worldPacket << Size<uint32>(GameRules);
    _worldPacket << int32(ActiveTimerunningSeasonID);
    _worldPacket << int32(RemainingTimerunningSeasonSeconds);
    _worldPacket << int16(MaxPlayerGuidLookupsPerRequest);
    _worldPacket << int16(NameLookupTelemetryInterval);
    _worldPacket << NotFoundCacheTimeSeconds;
    _worldPacket << Size<uint32>(DebugTimeEvents);
    _worldPacket << int32(MostRecentTimeEventID);
    _worldPacket << uint32(EventRealmQueues);

    if (LaunchDurationETA)
        _worldPacket << int32(*LaunchDurationETA);

    _worldPacket << SizedCString::Data(RealmHiddenAlert);

    if (!LiveRegionCharacterCopySourceRegions.empty())
        _worldPacket.append(LiveRegionCharacterCopySourceRegions.data(), LiveRegionCharacterCopySourceRegions.size());

    for (GameRuleValuePair const& gameRuleValue : GameRules)
        _worldPacket << gameRuleValue;

    for (DebugTimeEventInfo const& debugTimeEventInfo : DebugTimeEvents)
        _worldPacket << debugTimeEventInfo;

    return &_worldPacket;
}

WorldPacket const* SetTimeZoneInformation::Write()
{
    _worldPacket << SizedString::BitsSize<7>(ServerTimeTZ);
    _worldPacket << SizedString::BitsSize<7>(GameTimeTZ);
    _worldPacket << SizedString::BitsSize<7>(ServerRegionalTimeTZ);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(ServerTimeTZ);
    _worldPacket << SizedString::Data(GameTimeTZ);
    _worldPacket << SizedString::Data(ServerRegionalTimeTZ);

    return &_worldPacket;
}
}
