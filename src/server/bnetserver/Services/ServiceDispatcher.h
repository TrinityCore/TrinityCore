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

#ifndef ServiceDispatcher_h__
#define ServiceDispatcher_h__

#include "MessageBuffer.h"
#include "Log.h"
#include "Common.h"
#include "AccountService.h"
#include "AuthenticationService.h"
#include "challenge_service.pb.h"
#include "club_listener.pb.h"
#include "club_membership_listener.pb.h"
#include "club_membership_service.pb.h"
#include "club_service.pb.h"
#include "ConnectionService.h"
#include "friends_service.pb.h"
#include "GameUtilitiesService.h"
#include "presence_listener.pb.h"
#include "presence_service.pb.h"
#include "report_service.pb.h"
#include "api/client/v2/report_service.pb.h"
#include "resource_service.pb.h"
#include "user_manager_service.pb.h"

namespace Battlenet
{
    class Session;

    class ServiceDispatcher
    {
    public:
        void Dispatch(Session* session, uint32 serviceHash, uint32 token, uint32 methodId, MessageBuffer buffer);

        static ServiceDispatcher& Instance();

    private:
        ServiceDispatcher();

        template<class Service>
        void AddService()
        {
            _dispatchers[Service::OriginalHash::value] = &ServiceDispatcher::Dispatch<Service>;
        }

        template<class Service>
        static void Dispatch(Session* session, uint32 token, uint32 methodId, MessageBuffer buffer)
        {
            Service(session).CallServerMethod(token, methodId, std::move(buffer));
        }

        typedef void(*ServiceMethod)(Session*, uint32, uint32, MessageBuffer);
        std::unordered_map<uint32, ServiceMethod> _dispatchers;
    };
}

#define sServiceDispatcher ServiceDispatcher::Instance()

#endif // ServiceDispatcher_h__
