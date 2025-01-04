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

#ifndef ClubService_h__
#define ClubService_h__

#include "WorldserverService.h"
#include "api/client/v1/club_service.pb.h"

namespace Battlenet::Services
{
class ClubService : public WorldserverService<club::v1::client::ClubService>
{
    typedef WorldserverService<club::v1::client::ClubService> BaseService;

public:

    ClubService(WorldSession* session);

    uint32 HandleGetClubType(club::v1::client::GetClubTypeRequest const* request, club::v1::client::GetClubTypeResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
    uint32 HandleSubscribe(club::v1::client::SubscribeRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
    uint32 HandleGetMembers(club::v1::client::GetMembersRequest const* request, club::v1::client::GetMembersResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
    uint32 HandleGetStreams(club::v1::client::GetStreamsRequest const* request, club::v1::client::GetStreamsResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
    uint32 HandleSubscribeStream(club::v1::client::SubscribeStreamRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
    uint32 HandleUnsubscribeStream(club::v1::client::UnsubscribeStreamRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
    uint32 HandleSetStreamFocus(club::v1::client::SetStreamFocusRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
    uint32 HandleAdvanceStreamViewTime(club::v1::client::AdvanceStreamViewTimeRequest const* request, NoData* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;
    uint32 HandleCreateMessage(club::v1::client::CreateMessageRequest const* request, club::v1::client::CreateMessageResponse* response, std::function<void(ServiceBase*, uint32, ::google::protobuf::Message const*)>& continuation) override;

    static std::unique_ptr<club::v1::UniqueClubType> CreateGuildClubType();

private:
    static void FillStreamMessage(club::v1::client::StreamMessage* message, std::string_view msg, std::chrono::microseconds messageTime, ObjectGuid author);
};
}

#endif // ClubService_h__
