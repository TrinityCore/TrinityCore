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

#ifndef ClubMembershipService_h__
#define ClubMembershipService_h__

#include "WorldserverService.h"
#include "api/client/v1/club_membership_service.pb.h"

namespace Battlenet::Services
{
class ClubMembershipService : public WorldserverService<club_membership::v1::client::ClubMembershipService>
{
    typedef WorldserverService<club_membership::v1::client::ClubMembershipService> BaseService;

public:
    ClubMembershipService(WorldSession* session);

    uint32 HandleSubscribe(club_membership::v1::client::SubscribeRequest const* request, club_membership::v1::client::SubscribeResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
    uint32 HandleUnsubscribe(club_membership::v1::client::UnsubscribeRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;

    static std::unique_ptr<club::v1::MemberId> CreateClubMemberId(ObjectGuid guid);
};
}

#endif // ClubMembershipService_h__
