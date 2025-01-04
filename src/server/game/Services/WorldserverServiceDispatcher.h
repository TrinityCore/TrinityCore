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

#ifndef WorldserverServiceDispatcher_h__
#define WorldserverServiceDispatcher_h__

#include "WorldSession.h"
#include "MessageBuffer.h"
#include "Log.h"
#include "account_service.pb.h"
#include "authentication_service.pb.h"
#include "api/client/v1/block_list_listener.pb.h"
#include "api/client/v1/block_list_service.pb.h"
#include "challenge_service.pb.h"
#include "api/client/v1/club_listener.pb.h"
#include "api/client/v1/club_membership_listener.pb.h"
#include "ClubMembershipService.h"
#include "ClubService.h"
#include "connection_service.pb.h"
#include "friends_service.pb.h"
#include "WorldserverGameUtilitiesService.h"
#include "notification_service.pb.h"
#include "api/client/v2/notification_listener.pb.h"
#include "api/client/v2/notification_service.pb.h"
#include "presence_listener.pb.h"
#include "presence_service.pb.h"
#include "report_service.pb.h"
#include "api/client/v2/report_service.pb.h"
#include "resource_service.pb.h"
#include "api/client/v2/whisper_listener.pb.h"
#include "api/client/v2/whisper_service.pb.h"

namespace Battlenet
{
    class WorldserverServiceDispatcher
    {
    public:
        void Dispatch(WorldSession* session, uint32 serviceHash, uint32 token, uint32 methodId, MessageBuffer buffer);

        static WorldserverServiceDispatcher& Instance();

    private:
        WorldserverServiceDispatcher();

        template<class Service>
        void AddService()
        {
            _dispatchers[Service::OriginalHash::value] = &WorldserverServiceDispatcher::Dispatch<Service>;
        }

        template<class Service>
        static void Dispatch(WorldSession* session, uint32 token, uint32 methodId, MessageBuffer buffer)
        {
            Service(session).CallServerMethod(token, methodId, std::move(buffer));
        }

        typedef void(*ServiceMethod)(WorldSession*, uint32, uint32, MessageBuffer);
        std::unordered_map<uint32, ServiceMethod> _dispatchers;
    };
}

#define sServiceDispatcher Battlenet::WorldserverServiceDispatcher::Instance()

#endif // WorldserverServiceDispatcher_h__
