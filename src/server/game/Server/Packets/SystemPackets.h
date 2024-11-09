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
#include "PacketUtilities.h"

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

        struct GameRuleValuePair
        {
            int32 Rule = 0;
            int32 Value = 0;
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
                uint32 RewardsVersion = 0;
            };

            struct AddonChatThrottleParams
            {
                int32 MaxTries = 0;
                int32 TriesRestoredPerSecond = 0;
                int32 UsedTriesPerMessage = 0;
            };

            FeatureSystemStatus() : ServerPacket(SMSG_FEATURE_SYSTEM_STATUS, 200) { }

            WorldPacket const* Write() override;

            bool VoiceEnabled                        = false;
            bool BrowserEnabled                      = false;
            bool BpayStoreAvailable                  = false;
            bool BpayStoreEnabled                    = false;
            Optional<SessionAlertConfig> SessionAlert;
            Optional<EuropaTicketConfig> EuropaTicketSystemStatus;
            uint32 CfgRealmID                            = 0;
            uint8 ComplaintStatus                        = 0;
            int32 CfgRealmRecID                          = 0;
            uint32 CommercePricePollTimeSeconds          = 0;
            int64 RedeemForBalanceAmount                 = 0;
            uint32 BpayStorePurchaseTimeout              = 0;
            uint32 ClubsPresenceDelay                    = 0;
            uint32 ClubPresenceUnsubscribeDelay          = 0; ///< Timer for updating club presence when communities ui frame is hidden
            uint32 KioskSessionDurationMinutes           = 0;
            int32 ContentSetID                           = 0; ///< Currently active Classic season
            int16 MaxPlayerGuidLookupsPerRequest         = 50;
            int16 NameLookupTelemetryInterval            = 600;
            Duration<Seconds, uint32> NotFoundCacheTimeSeconds = 10s;
            bool ItemRestorationButtonEnabled        = false;
            bool CharUndeleteEnabled                 = false; ///< Implemented
            bool BpayStoreDisabledByParentalControls = false;
            bool CommerceServerEnabled               = false;
            bool VeteranTokenRedeemWillKick          = false;
            bool WorldTokenRedeemWillKick            = false;
            bool RestrictedAccount                   = false;
            bool TutorialEnabled                     = false;
            bool NPETutorialsEnabled                 = false;
            bool KioskModeEnabled                    = false;
            bool CompetitiveModeEnabled              = false;
            bool RedeemForBalanceAvailable           = false;
            bool WarModeEnabled                      = true;
            bool CommunitiesEnabled                  = false;
            bool BnetGroupsEnabled                   = false;
            bool CharacterCommunitiesEnabled         = false;
            bool ClubPresenceAllowSubscribeAll       = false;
            bool VoiceChatParentalDisabled           = false;
            bool VoiceChatParentalMuted              = false;
            bool QuestSessionEnabled                 = false;
            bool IsChatMuted                         = false;
            bool ClubFinderEnabled                   = false;
            bool CommunityFinderEnabled              = false;
            bool BrowserCrashReporterEnabled         = false;
            bool SpeakForMeAllowed                   = false;
            bool DoesAccountNeedAADCPrompt           = false;
            bool IsAccountOptedInToAADC              = false;
            bool LfgRequireAuthenticatorEnabled      = false;
            bool ScriptsDisallowedForBeta            = false;
            bool TimerunningEnabled                  = false;
            bool WarGamesEnabled                     = false; // classic only
            bool IsPlayerContentTrackingEnabled      = false;
            bool SellAllJunkEnabled                  = false;
            bool GroupFinderEnabled                  = true;  // classic only
            bool LfdEnabled                          = true;  // classic only
            bool LfrEnabled                          = true;  // classic only
            bool IsPremadeGroupEnabled               = true;  // classic only
            bool PremadeGroupsEnabled                = true;
            bool GuildEventsEditsEnabled             = true;
            bool GuildTradeSkillsEnabled             = true;
            bool BNSendWhisperUseV2Services          = true; ///< BNSendWhisper will send to v2.WhisperService instead of v1.NotificationService
            bool BNSendGameDataUseV2Services         = true; ///< BNSendGameData will send to v2.NotificationService instead of v1.NotificationService
            bool IsAccountCurrencyTransferEnabled    = false;

            SocialQueueConfig QuickJoinConfig;
            SquelchInfo Squelch;
            RafSystemFeatureInfo RAFSystem;
            std::vector<GameRuleValuePair> GameRules;
            int32 ActiveTimerunningSeasonID          = 0;
            int32 RemainingTimerunningSeasonSeconds  = 0;
            std::string Unknown1027;                          // related to movement lua functions used by keybinds
            AddonChatThrottleParams AddonChatThrottle;
        };

        struct DebugTimeEventInfo
        {
            uint32 TimeEvent = 0;
            std::string_view Text;
        };

        class FeatureSystemStatusGlueScreen final : public ServerPacket
        {
        public:
            FeatureSystemStatusGlueScreen() : ServerPacket(SMSG_FEATURE_SYSTEM_STATUS_GLUE_SCREEN, 64) { }

            WorldPacket const* Write() override;

            bool BpayStoreAvailable                  = false; // NYI
            bool BpayStoreDisabledByParentalControls = false; // NYI
            bool CharUndeleteEnabled                 = false;
            bool BpayStoreEnabled                    = false; // NYI
            bool CommerceServerEnabled               = false; // NYI
            bool VeteranTokenRedeemWillKick          = false; // NYI
            bool WorldTokenRedeemWillKick            = false; // NYI
            bool ExpansionPreorderInStore            = false; // NYI
            bool KioskModeEnabled                    = false; // NYI
            bool CompetitiveModeEnabled              = false; // NYI
            bool BoostEnabled                        = false; // classic only
            bool TrialBoostEnabled                   = false; // NYI
            bool RedeemForBalanceAvailable           = false; // NYI
            bool PaidCharacterTransfersBetweenBnetAccountsEnabled = false;
            bool LiveRegionCharacterListEnabled      = false; // NYI
            bool LiveRegionCharacterCopyEnabled      = false; // NYI
            bool LiveRegionAccountCopyEnabled        = false; // NYI
            bool LiveRegionKeyBindingsCopyEnabled    = false;
            bool BrowserCrashReporterEnabled         = false; // NYI
            bool IsEmployeeAccount                   = false; // NYI
            bool NameReservationOnly                 = false; // classic only
            bool TimerunningEnabled                  = false; // NYI
            bool ScriptsDisallowedForBeta            = false;
            bool PlayerIdentityOptionsEnabled        = false;
            bool AccountExportEnabled                = false;
            bool AccountLockedPostExport             = false;
            bool BNSendWhisperUseV2Services          = true; ///< BNSendWhisper will send to v2.WhisperService instead of v1.NotificationService
            bool BNSendGameDataUseV2Services         = true; ///< BNSendGameData will send to v2.NotificationService instead of v1.NotificationService
            bool CharacterSelectListModeRealmless    = false;
            Optional<EuropaTicketConfig> EuropaTicketSystemStatus;
            std::vector<int32> LiveRegionCharacterCopySourceRegions;
            uint32 CommercePricePollTimeSeconds      = 0;     // NYI
            int64 RedeemForBalanceAmount             = 0;     // NYI
            int32 MaxCharactersOnThisRealm           = 0;
            uint32 BpayStorePurchaseTimeout          = 0;     // NYI
            int32 ActiveBoostType                    = 0;     // NYI
            int32 TrialBoostType                     = 0;     // NYI
            int32 MinimumExpansionLevel              = 0;
            int32 MaximumExpansionLevel              = 0;
            uint32 KioskSessionDurationMinutes       = 0;
            int32 ContentSetID                       = 0;     // Currently active Classic season
            std::vector<GameRuleValuePair> GameRules;
            int32 ActiveTimerunningSeasonID          = 0;
            int32 RemainingTimerunningSeasonSeconds  = 0;
            int16 MaxPlayerGuidLookupsPerRequest     = 50;
            int16 NameLookupTelemetryInterval        = 600;
            Duration<Seconds, uint32> NotFoundCacheTimeSeconds = 10s;
            Optional<int32> LaunchDurationETA;
            std::vector<DebugTimeEventInfo> DebugTimeEvents;
            int32 MostRecentTimeEventID              = 0;
            uint32 EventRealmQueues                  = 0;
            std::string RealmHiddenAlert;
        };

        class SetTimeZoneInformation final : public ServerPacket
        {
        public:
            SetTimeZoneInformation() : ServerPacket(SMSG_SET_TIME_ZONE_INFORMATION) { }

            WorldPacket const* Write() override;

            std::string_view ServerTimeTZ;
            std::string_view GameTimeTZ;
            std::string_view ServerRegionalTimeTZ;
        };
    }
}

#endif // SystemPackets_h__
