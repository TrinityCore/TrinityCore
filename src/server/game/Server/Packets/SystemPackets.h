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

#ifndef SystemPackets_h__
#define SystemPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Optional.h"

namespace WorldPackets
{
    namespace System
    {
        struct SavedThrottleObjectState
        {
            uint32 MaxTries               = 0;
            uint32 PerMilliseconds        = 0;
            uint32 TryCount               = 0;
            uint32 LastResetTimeBeforeNow = 0;
        };

        struct EuropaTicketConfig
        {
            bool TicketsEnabled     = false;
            bool BugsEnabled        = false;
            bool ComplaintsEnabled  = false;
            bool SuggestionsEnabled = false;

            SavedThrottleObjectState ThrottleState;
        };

        class FeatureSystemStatus final : public ServerPacket
        {
        public:
            struct SessionAlertConfig
            {
                int32 Delay       = 0;
                int32 Period      = 0;
                int32 DisplayTime = 0;
            };

            struct SocialQueueConfig
            {
                bool ToastsDisabled = false;
                float ToastDuration = 0.0f;
                float DelayDuration = 0.0f;
                float QueueMultiplier = 0.0f;
                float PlayerMultiplier = 0.0f;
                float PlayerFriendValue = 0.0f;
                float PlayerGuildValue = 0.0f;
                float ThrottleInitialThreshold = 0.0f;
                float ThrottleDecayTime = 0.0f;
                float ThrottlePrioritySpike = 0.0f;
                float ThrottleMinThreshold = 0.0f;
                float ThrottlePvPPriorityNormal = 0.0f;
                float ThrottlePvPPriorityLow = 0.0f;
                float ThrottlePvPHonorThreshold = 0.0f;
                float ThrottleLfgListPriorityDefault = 0.0f;
                float ThrottleLfgListPriorityAbove = 0.0f;
                float ThrottleLfgListPriorityBelow = 0.0f;
                float ThrottleLfgListIlvlScalingAbove = 0.0f;
                float ThrottleLfgListIlvlScalingBelow = 0.0f;
                float ThrottleRfPriorityAbove = 0.0f;
                float ThrottleRfIlvlScalingAbove = 0.0f;
                float ThrottleDfMaxItemLevel = 0.0f;
                float ThrottleDfBestPriority = 0.0f;
            };

            struct SquelchInfo
            {
                bool IsSquelched = false;
                ObjectGuid BnetAccountGuid;
                ObjectGuid GuildGuid;
            };

            struct RafSystemFeatureInfo
            {
                bool Enabled = false;
                bool RecruitingEnabled = false;
                uint32 MaxRecruits = 0;
                uint32 MaxRecruitMonths = 0;
                uint32 MaxRecruitmentUses = 0;
                uint32 DaysInCycle = 0;
            };

            FeatureSystemStatus() : ServerPacket(SMSG_FEATURE_SYSTEM_STATUS, 48) { }

            WorldPacket const* Write() override;

            bool VoiceEnabled                        = false;
            bool BrowserEnabled                      = false;
            bool BpayStoreAvailable                  = false;
            bool BpayStoreEnabled                    = false;
            Optional<SessionAlertConfig> SessionAlert;
            uint32 ScrollOfResurrectionMaxRequestsPerDay = 0;
            bool ScrollOfResurrectionEnabled         = false;
            Optional<EuropaTicketConfig> EuropaTicketSystemStatus;
            uint32 ScrollOfResurrectionRequestsRemaining = 0;
            uint32 CfgRealmID                            = 0;
            uint8 ComplaintStatus                        = 0;
            int32 CfgRealmRecID                          = 0;
            uint32 TwitterPostThrottleLimit              = 0; ///< Number of twitter posts the client can send before they start being throttled
            uint32 TwitterPostThrottleCooldown           = 0; ///< Time in seconds the client has to wait before posting again after hitting post limit
            uint32 TokenPollTimeSeconds                  = 0;
            int64 TokenBalanceAmount                     = 0;
            uint32 BpayStoreProductDeliveryDelay         = 0;
            uint32 ClubsPresenceUpdateTimer              = 0;
            uint32 HiddenUIClubsPresenceUpdateTimer      = 0; ///< Timer for updating club presence when communities ui frame is hidden
            uint32 KioskSessionMinutes                   = 0;
            bool ItemRestorationButtonEnabled        = false;
            bool CharUndeleteEnabled                 = false; ///< Implemented
            bool BpayStoreDisabledByParentalControls = false;
            bool TwitterEnabled                      = false;
            bool CommerceSystemEnabled               = false;
            bool Unk67                               = false;
            bool WillKickFromWorld                   = false;
            bool RestrictedAccount                   = false;
            bool TutorialsEnabled                    = false;
            bool NPETutorialsEnabled                 = false;
            bool KioskModeEnabled                    = false;
            bool CompetitiveModeEnabled              = false;
            bool TokenBalanceEnabled                 = false;
            bool WarModeFeatureEnabled               = false;
            bool ClubsEnabled                        = false;
            bool ClubsBattleNetClubTypeAllowed       = false;
            bool ClubsCharacterClubTypeAllowed       = false;
            bool ClubsPresenceUpdateEnabled          = false;
            bool VoiceChatDisabledByParentalControl  = false;
            bool VoiceChatMutedByParentalControl     = false;
            bool QuestSessionEnabled                 = false;
            bool IsMuted                             = false;
            bool ClubFinderEnabled                   = false;
            bool Unknown901CheckoutRelated           = false;

            SocialQueueConfig QuickJoinConfig;
            SquelchInfo Squelch;
            RafSystemFeatureInfo RAFSystem;
        };

        class FeatureSystemStatusGlueScreen final : public ServerPacket
        {
        public:
            FeatureSystemStatusGlueScreen() : ServerPacket(SMSG_FEATURE_SYSTEM_STATUS_GLUE_SCREEN, 1) { }

            WorldPacket const* Write() override;

            bool BpayStoreAvailable                  = false; // NYI
            bool BpayStoreDisabledByParentalControls = false; // NYI
            bool CharUndeleteEnabled                 = false;
            bool BpayStoreEnabled                    = false; // NYI
            bool CommerceSystemEnabled               = false; // NYI
            bool Unk14                               = false; // NYI
            bool WillKickFromWorld                   = false; // NYI
            bool IsExpansionPreorderInStore          = false; // NYI
            bool KioskModeEnabled                    = false; // NYI
            bool CompetitiveModeEnabled              = false; // NYI
            bool TrialBoostEnabled                   = false; // NYI
            bool TokenBalanceEnabled                 = false; // NYI
            bool LiveRegionCharacterListEnabled      = false; // NYI
            bool LiveRegionCharacterCopyEnabled      = false; // NYI
            bool LiveRegionAccountCopyEnabled        = false; // NYI
            bool LiveRegionKeyBindingsCopyEnabled    = false;
            bool Unknown901CheckoutRelated           = false; // NYI
            Optional<EuropaTicketConfig> EuropaTicketSystemStatus;
            std::vector<int32> LiveRegionCharacterCopySourceRegions;
            uint32 TokenPollTimeSeconds              = 0;     // NYI
            int64 TokenBalanceAmount                 = 0;     // NYI
            int32 MaxCharactersPerRealm              = 0;
            uint32 BpayStoreProductDeliveryDelay     = 0;     // NYI
            int32 ActiveCharacterUpgradeBoostType    = 0;     // NYI
            int32 ActiveClassTrialBoostType          = 0;     // NYI
            int32 MinimumExpansionLevel              = 0;
            int32 MaximumExpansionLevel              = 0;
            uint32 KioskSessionMinutes               = 0;
        };

        class MOTD final : public ServerPacket
        {
        public:
            MOTD() : ServerPacket(SMSG_MOTD) { }

            WorldPacket const* Write() override;

            std::vector<std::string> const* Text = nullptr;
        };

        class SetTimeZoneInformation final : public ServerPacket
        {
        public:
            SetTimeZoneInformation() : ServerPacket(SMSG_SET_TIME_ZONE_INFORMATION) { }

            WorldPacket const* Write() override;

            std::string ServerTimeTZ;
            std::string GameTimeTZ;
        };
    }
}

#endif // SystemPackets_h__
