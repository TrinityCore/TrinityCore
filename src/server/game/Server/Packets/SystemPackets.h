/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

namespace WorldPackets
{
    namespace System
    {
        class FeatureSystemStatus final : public ServerPacket
        {
        public:
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

            struct SessionAlertConfig
            {
                int32 Delay       = 0;
                int32 Period      = 0;
                int32 DisplayTime = 0;
            };

            FeatureSystemStatus() : ServerPacket(SMSG_FEATURE_SYSTEM_STATUS, 48) { }

            WorldPacket const* Write() override;

            bool VoiceEnabled                        = false;
            bool BrowserEnabled                      = false;
            bool BpayStoreAvailable                  = false;
            bool RecruitAFriendSendingEnabled        = false;
            bool BpayStoreEnabled                    = false;
            Optional<SessionAlertConfig> SessionAlert;
            uint32 ScrollOfResurrectionMaxRequestsPerDay = 0;
            bool ScrollOfResurrectionEnabled         = false;
            Optional<EuropaTicketConfig> EuropaTicketSystemStatus;
            uint32 ScrollOfResurrectionRequestsRemaining = 0;
            uint32 CfgRealmID                            = 0;
            uint8 ComplaintStatus                        = 0;
            int32 CfgRealmRecID                          = 0;
            int32 UnkInt27                               = 0;
            int32 UnkInt29                               = 0;
            bool ItemRestorationButtonEnabled        = false;
            bool CharUndeleteEnabled                 = false; ///< Implemented
            bool BpayStoreDisabledByParentalControls = false;
            bool TwitterEnabled                      = false;

            bool RestrictedAccount                   = false;
            bool TutorialsEnabled                    = false;
            bool UnkBit90                            = false;
            bool UnkBit61                            = false;
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
