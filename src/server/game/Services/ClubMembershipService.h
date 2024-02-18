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
#include "club_membership_service.pb.h"

namespace Battlenet::Services
{
class ClubMembershipService : public WorldserverService<club::v1::membership::ClubMembershipService>
{
    typedef WorldserverService<club::v1::membership::ClubMembershipService> BaseService;

public:
    ClubMembershipService(WorldSession* session);

    uint32 HandleSubscribe(club::v1::membership::SubscribeRequest const* request, club::v1::membership::SubscribeResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
    uint32 HandleUnsubscribe(club::v1::membership::UnsubscribeRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;

    static std::unique_ptr<club::v1::MemberId> CreateClubMemberId(ObjectGuid guid);
};
}

#endif // ClubMembershipService_h__
