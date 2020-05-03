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
#include "Errors.h"

WorldPacket const* WorldPackets::System::FeatureSystemStatus::Write()
{
    _worldPacket << uint8(ComplaintStatus);

    _worldPacket << uint32(ScrollOfResurrectionRequestsRemaining);
    _worldPacket << uint32(ScrollOfResurrectionMaxRequestsPerDay);

    _worldPacket << uint32(CfgRealmID);
    _worldPacket << int32(CfgRealmRecID);

    _worldPacket << uint32(RAFSystem.MaxRecruits);
    _worldPacket << uint32(RAFSystem.MaxRecruitMonths);
    _worldPacket << uint32(RAFSystem.MaxRecruitmentUses);
    _worldPacket << uint32(RAFSystem.DaysInCycle);

    _worldPacket << uint32(TwitterPostThrottleLimit);
    _worldPacket << uint32(TwitterPostThrottleCooldown);

    _worldPacket << uint32(TokenPollTimeSeconds);
    _worldPacket << int64(TokenBalanceAmount);

    _worldPacket << uint32(BpayStoreProductDeliveryDelay);

    _worldPacket << uint32(ClubsPresenceUpdateTimer);
    _worldPacket << uint32(HiddenUIClubsPresenceUpdateTimer);

    _worldPacket.WriteBit(VoiceEnabled);
    _worldPacket.WriteBit(EuropaTicketSystemStatus.is_initialized());
    _worldPacket.WriteBit(ScrollOfResurrectionEnabled);
    _worldPacket.WriteBit(BpayStoreEnabled);
    _worldPacket.WriteBit(BpayStoreAvailable);
    _worldPacket.WriteBit(BpayStoreDisabledByParentalControls);
    _worldPacket.WriteBit(ItemRestorationButtonEnabled);
    _worldPacket.WriteBit(BrowserEnabled);
    _worldPacket.WriteBit(SessionAlert.is_initialized());
    _worldPacket.WriteBit(RAFSystem.Enabled);
    _worldPacket.WriteBit(RAFSystem.RecruitingEnabled);
    _worldPacket.WriteBit(CharUndeleteEnabled);
    _worldPacket.WriteBit(RestrictedAccount);
    _worldPacket.WriteBit(CommerceSystemEnabled);
    _worldPacket.WriteBit(TutorialsEnabled);
    _worldPacket.WriteBit(NPETutorialsEnabled);
    _worldPacket.WriteBit(TwitterEnabled);
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

    {
        _worldPacket.WriteBit(VoiceChatManagerSettings.IsSquelched);
        _worldPacket << VoiceChatManagerSettings.BnetAccountGuid;
        _worldPacket << VoiceChatManagerSettings.GuildGuid;
    }

    if (EuropaTicketSystemStatus)
    {
        _worldPacket.WriteBit(EuropaTicketSystemStatus->TicketsEnabled);
        _worldPacket.WriteBit(EuropaTicketSystemStatus->BugsEnabled);
        _worldPacket.WriteBit(EuropaTicketSystemStatus->ComplaintsEnabled);
        _worldPacket.WriteBit(EuropaTicketSystemStatus->SuggestionsEnabled);

        _worldPacket << uint32(EuropaTicketSystemStatus->ThrottleState.MaxTries);
        _worldPacket << uint32(EuropaTicketSystemStatus->ThrottleState.PerMilliseconds);
        _worldPacket << uint32(EuropaTicketSystemStatus->ThrottleState.TryCount);
        _worldPacket << uint32(EuropaTicketSystemStatus->ThrottleState.LastResetTimeBeforeNow);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::System::FeatureSystemStatusGlueScreen::Write()
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
    _worldPacket.WriteBit(TrialBoostEnabled);
    _worldPacket.WriteBit(TokenBalanceEnabled);
    _worldPacket.WriteBit(LiveRegionCharacterListEnabled);
    _worldPacket.WriteBit(LiveRegionCharacterCopyEnabled);
    _worldPacket.WriteBit(LiveRegionAccountCopyEnabled);
    _worldPacket.FlushBits();

    _worldPacket << uint32(TokenPollTimeSeconds);
    _worldPacket << int64(TokenBalanceAmount);
    _worldPacket << int32(MaxCharactersPerRealm);
    _worldPacket << uint32(BpayStoreProductDeliveryDelay);
    _worldPacket << int32(ActiveCharacterUpgradeBoostType);
    _worldPacket << int32(ActiveClassTrialBoostType);
    _worldPacket << int32(MinimumExpansionLevel);
    _worldPacket << int32(MaximumExpansionLevel);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::System::MOTD::Write()
{
    ASSERT(Text);
    _worldPacket.WriteBits(Text->size(), 4);
    _worldPacket.FlushBits();

    for (std::string const& line : *Text)
    {
        _worldPacket.WriteBits(line.length(), 7);
        _worldPacket.FlushBits();
        _worldPacket.WriteString(line);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::System::SetTimeZoneInformation::Write()
{
    _worldPacket.WriteBits(ServerTimeTZ.length(), 7);
    _worldPacket.WriteBits(GameTimeTZ.length(), 7);
    _worldPacket.FlushBits();

    _worldPacket.WriteString(ServerTimeTZ);
    _worldPacket.WriteString(GameTimeTZ);

    return &_worldPacket;
}
