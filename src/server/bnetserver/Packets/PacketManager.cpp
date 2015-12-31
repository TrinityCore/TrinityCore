/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "PacketManager.h"

Battlenet::ClientPacket* Battlenet::PacketManager::CreateClientPacket(PacketHeader const& header, BitStream& stream)
{
    auto packetInfo = _clientPacketTable.find(header);
    if (packetInfo == _clientPacketTable.end())
        return nullptr;

    if (!packetInfo->second.Constructor)
        return nullptr;

    ClientPacket* packet = packetInfo->second.Constructor(header, stream);
    packet->Read();
    return packet;
}

char const* Battlenet::PacketManager::GetClientPacketName(PacketHeader const& header)
{
    auto packetInfo = _clientPacketTable.find(header);
    if (packetInfo == _clientPacketTable.end())
        return nullptr;

    return packetInfo->second.Name;
}

char const* Battlenet::PacketManager::GetServerPacketName(PacketHeader const& header)
{
    auto packetInfo = _serverPacketTable.find(header);
    if (packetInfo == _serverPacketTable.end())
        return nullptr;

    return packetInfo->second.Name;
}

bool Battlenet::PacketManager::IsHandled(PacketHeader const& header)
{
    auto packetInfo = _clientPacketTable.find(header);
    if (packetInfo == _clientPacketTable.end())
        return false;

    return packetInfo->second.HasHandler;
}

Battlenet::PacketManager::PacketManager()
{
    RegisterAuthenticationPackets();
    RegisterConnectionPackets();
    RegisterWoWRealmPackets();
    RegisterFriendsPackets();
    RegisterPresencePackets();
    RegisterChatPackets();
    RegisterSupportPackets();
    RegisterCachePackets();
    RegisterAchievementPackets();
    RegisterProfilePackets();
}

#define REGISTER_CLIENT_PACKET(header, packetClass) RegisterClientPacket<packetClass>(header, #packetClass)
#define REGISTER_SERVER_PACKET(header, packetClass) RegisterPacketName(_serverPacketTable, header, #packetClass)
#define REGISTER_CLIENT_PACKET_NAME(header, name) RegisterPacketName(_clientPacketTable, header, name)
#define REGISTER_SERVER_PACKET_NAME(header, name) RegisterPacketName(_serverPacketTable, header, name)

void Battlenet::PacketManager::RegisterAuthenticationPackets()
{
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Authentication::CMSG_LOGON_REQUEST, AUTHENTICATION), "Authentication::LogonRequest");
    REGISTER_CLIENT_PACKET(PacketHeader(Authentication::CMSG_RESUME_REQUEST, AUTHENTICATION), Authentication::ResumeRequest);
    REGISTER_CLIENT_PACKET(PacketHeader(Authentication::CMSG_PROOF_RESPONSE, AUTHENTICATION), Authentication::ProofResponse);
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Authentication::CMSG_GENERATE_SINGLE_SIGN_ON_TOKEN_REQUEST_2, AUTHENTICATION), "Authentication::GenerateSingleSignOnTokenRequest2");
    REGISTER_CLIENT_PACKET(PacketHeader(Authentication::CMSG_LOGON_REQUEST_3, AUTHENTICATION), Authentication::LogonRequest3);
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Authentication::CMSG_SINGLE_SIGN_ON_REQUEST_3, AUTHENTICATION), "Authentication::SingleSignOnRequest3");

    REGISTER_SERVER_PACKET(PacketHeader(Authentication::SMSG_LOGON_RESPONSE, AUTHENTICATION), Authentication::LogonResponse);
    REGISTER_SERVER_PACKET(PacketHeader(Authentication::SMSG_RESUME_RESPONSE, AUTHENTICATION), Authentication::ResumeResponse);
    REGISTER_SERVER_PACKET(PacketHeader(Authentication::SMSG_PROOF_REQUEST, AUTHENTICATION), Authentication::ProofRequest);
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Authentication::SMSG_PATCH, AUTHENTICATION), "Authentication::Patch");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Authentication::SMSG_AUTHORIZED_LICENSES, AUTHENTICATION), "Authentication::AuthorizedLicenses");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Authentication::SMSG_GENERATE_SINGLE_SIGN_ON_TOKEN_RESPONSE_2, AUTHENTICATION), "Authentication::GenerateSingleSignOnTokenResponse2");
}

void Battlenet::PacketManager::RegisterConnectionPackets()
{
    REGISTER_CLIENT_PACKET(PacketHeader(Connection::CMSG_PING, CONNECTION), Connection::Ping);
    REGISTER_CLIENT_PACKET(PacketHeader(Connection::CMSG_ENABLE_ENCRYPTION, CONNECTION), Connection::EnableEncryption);
    REGISTER_CLIENT_PACKET(PacketHeader(Connection::CMSG_LOGOUT_REQUEST, CONNECTION), Connection::LogoutRequest);
    REGISTER_CLIENT_PACKET(PacketHeader(Connection::CMSG_DISCONNECT_REQUEST, CONNECTION), Connection::DisconnectRequest);
    REGISTER_CLIENT_PACKET(PacketHeader(Connection::CMSG_CONNECTION_CLOSING, CONNECTION), Connection::ConnectionClosing);

    REGISTER_SERVER_PACKET(PacketHeader(Connection::SMSG_PONG, CONNECTION), Connection::Pong);
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Connection::SMSG_BOOM, CONNECTION), "Connection::Boom");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Connection::SMSG_REGULATOR_UPDATE, CONNECTION), "Connection::RegulatorUpdate");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Connection::SMSG_SERVER_VERSION, CONNECTION), "Connection::ServerVersion");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Connection::SMSG_STUN_SERVERS, CONNECTION), "Connection::STUNServers");
}

void Battlenet::PacketManager::RegisterWoWRealmPackets()
{
    REGISTER_CLIENT_PACKET(PacketHeader(WoWRealm::CMSG_LIST_SUBSCRIBE_REQUEST, WOWREALM), WoWRealm::ListSubscribeRequest);
    REGISTER_CLIENT_PACKET(PacketHeader(WoWRealm::CMSG_LIST_UNSUBSCRIBE, WOWREALM), WoWRealm::ListUnsubscribe);
    REGISTER_CLIENT_PACKET(PacketHeader(WoWRealm::CMSG_JOIN_REQUEST_V2, WOWREALM), WoWRealm::JoinRequestV2);
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(WoWRealm::CMSG_MULTI_LOGON_REQUEST_V2, WOWREALM), "WoWRealm::MultiLogonRequestV2");

    REGISTER_SERVER_PACKET(PacketHeader(WoWRealm::SMSG_LIST_SUBSCRIBE_RESPONSE, WOWREALM), WoWRealm::ListSubscribeResponse);
    REGISTER_SERVER_PACKET(PacketHeader(WoWRealm::SMSG_LIST_UPDATE, WOWREALM), WoWRealm::ListUpdate);
    REGISTER_SERVER_PACKET(PacketHeader(WoWRealm::SMSG_LIST_COMPLETE, WOWREALM), WoWRealm::ListComplete);
    REGISTER_SERVER_PACKET(PacketHeader(WoWRealm::SMSG_TOON_READY, WOWREALM), WoWRealm::ToonReady);
    REGISTER_SERVER_PACKET(PacketHeader(WoWRealm::SMSG_TOON_LOGGED_OUT, WOWREALM), WoWRealm::ToonLoggedOut);
    REGISTER_SERVER_PACKET(PacketHeader(WoWRealm::SMSG_JOIN_RESPONSE_V2, WOWREALM), WoWRealm::JoinResponseV2);
}

void Battlenet::PacketManager::RegisterFriendsPackets()
{
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_FRIEND_INVITE, FRIENDS), "Friends::FriendInvite");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_FRIEND_INVITE_RESPONSE, FRIENDS), "Friends::FriendInviteResponse");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_FRIEND_REMOVE, FRIENDS), "Friends::FriendRemove");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_FRIEND_NOTE, FRIENDS), "Friends::FriendNote");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_TOONS_OF_FRIEND_REQUEST, FRIENDS), "Friends::ToonsOfFriendRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_BLOCK_ADD, FRIENDS), "Friends::BlockAdd");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_BLOCK_REMOVE, FRIENDS), "Friends::BlockRemove");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_GET_FRIENDS_OF_FRIEND, FRIENDS), "Friends::GetFriendsOfFriend");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_GET_SOCIAL_NETWORK_FRIENDS, FRIENDS), "Friends::GetSocialNetworkFriends");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_SOCIAL_NETWORK_CONNECT, FRIENDS), "Friends::SocialNetworkConnect");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_SOCIAL_NETWORK_DISCONNECT, FRIENDS), "Friends::SocialNetworkDisconnect");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_SOCIAL_NETWORK_CHECK_CONNECTED, FRIENDS), "Friends::SocialNetworkCheckConnected");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Friends::CMSG_REALID_FRIEND_INVITE, FRIENDS), "Friends::RealIdFriendInvite");
    REGISTER_CLIENT_PACKET(PacketHeader(Friends::CMSG_SEND_INVITATION_REQUEST, FRIENDS), Friends::SendInvitationRequest);

    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_FRIEND_INVITE_NOTIFY, FRIENDS), "Friends::FriendInviteNotify");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_FRIEND_INVITE_RESULT, FRIENDS), "Friends::FriendInviteResult");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_TOONS_OF_FRIEND_NOTIFY, FRIENDS), "Friends::ToonsOfFriendNotify");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_BLOCK_INVITE_NOTIFY, FRIENDS), "Friends::BlockInviteNotify");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_BLOCK_ADD_FAILURE, FRIENDS), "Friends::BlockAddFailure");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_FRIENDS_OF_FRIEND, FRIENDS), "Friends::FriendsOfFriend");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_SOCIAL_NETWORK_FRIENDS, FRIENDS), "Friends::SocialNetworkFriends");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_SOCIAL_NETWORK_CONNECT_RESULT, FRIENDS), "Friends::SocialNetworkConnectResult");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_SOCIAL_NETWORK_DISCONNECT_RESULT, FRIENDS), "Friends::SocialNetworkDisconnectResult");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_SOCIAL_NETWORK_CHECK_CONNECTED_RESULT, FRIENDS), "Friends::SocialNetworkCheckConnectedResult");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_MAX_FRIENDS_NOTIFY, FRIENDS), "Friends::MaxFriendsNotify");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_FRIENDS_LIST_NOTIFY_3, FRIENDS), "Friends::FriendsListNotify3");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_SEND_INVITATION_RESULT, FRIENDS), "SendInvitationResult");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_FRIEND_INVITATION_ADDED_NOTIFY, FRIENDS), "Friends::FriendInvitationAddedNotify");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_FRIEND_INVITATION_REMOVED_NOTIFY, FRIENDS), "Friends::FriendInvitationRemovedNotify");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_FRIENDS_LIST_NOTIFY_5, FRIENDS), "Friends::FriendsListNotify5");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_ACCOUNT_BLOCK_ADDED_NOTIFY, FRIENDS), "Friends::AccountBlockAddedNotify");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_ACCOUNT_BLOCK_REMOVED_NOTIFY, FRIENDS), "Friends::AccountBlockRemovedNotify");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_TOON_BLOCK_NOTIFY, FRIENDS), "Friends::ToonBlockNotify");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Friends::SMSG_FRIENDS_OF_FRIEND_RESULT, FRIENDS), "Friends::FriendsOfFriendResult");
}

void Battlenet::PacketManager::RegisterPresencePackets()
{
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Presence::CMSG_UPDATE_REQUEST, PRESENCE), "Presence::UpdateRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Presence::CMSG_STATISTIC_SUBSCRIBE, PRESENCE), "Presence::StatisticSubscribe");

    REGISTER_SERVER_PACKET_NAME(PacketHeader(Presence::SMSG_UPDATE_NOTIFY, PRESENCE), "Presence::UpdateNotify");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Presence::SMSG_FIELD_SPEC_ANNOUNCE, PRESENCE), "Presence::FieldSpecAnnounce");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Presence::SMSG_STATISTICS_UPDATE, PRESENCE), "Presence::StatisticsUpdate");
}

void Battlenet::PacketManager::RegisterChatPackets()
{
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_JOIN_REQUEST_2, CHAT), "Chat::JoinRequest2");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_LEAVE_REQUEST, CHAT), "Chat::LeaveRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_INVITE_REQUEST, CHAT), "Chat::InviteRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_CREATE_AND_INVITE_REQUEST, CHAT), "Chat::CreateAndInviteRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_MESSAGE_SEND, CHAT), "Chat::MessageSend");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_DATAGRAM_CONNECTION_UPDATE, CHAT), "Chat::DatagramConnectionUpdate");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_REPORT_SPAM_REQUEST, CHAT), "Chat::ReportSpamRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_WHISPER_SEND, CHAT), "Chat::WhisperSend");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_ENUM_CATEGORY_DESCRIPTIONS, CHAT), "Chat::EnumCategoryDescriptions");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_ENUM_CONFERENCE_DESCRIPTIONS, CHAT), "Chat::EnumConferenceDescriptions");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_ENUM_CONFERENCE_MEMBER_COUNTS, CHAT), "Chat::EnumConferenceMemberCounts");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_MODIFY_CHANNEL_LIST_REQUEST, CHAT), "Chat::ModifyChannelListRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_GET_MEMBER_COUNT_REQUEST, CHAT), "Chat::GetMemberCountRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_MODIFY_CHANNEL_LIST_REQUEST_2, CHAT), "Chat::ModifyChannelListRequest2");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Chat::CMSG_GAME_DATA_SEND_REQUEST, CHAT), "Chat::GameDataSendRequest");

    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_MEMBERSHIP_CHANGE_NOTIFY, CHAT), "Chat::MembershipChangeNotify");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_INVITE_NOTIFY, CHAT), "Chat::InviteNotify");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_INVITE_CANCELED, CHAT), "Chat::InviteCanceled");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_MESSAGE_RECV, CHAT), "Chat::MessageRecv");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_MESSAGE_UNDELIVERABLE, CHAT), "Chat::MessageUndeliverable");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_DATAGRAM_CONNECTION_UPDATE, CHAT), "Chat::DatagramConnectionUpdate");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_INVITE_FAILURE, CHAT), "Chat::InviteFailed");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_SYSTEM_MESSAGE, CHAT), "Chat::SystemMessage");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_MESSAGE_BLOCKED, CHAT), "Chat::MessageBlocked");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_WHISPER_RECV, CHAT), "Chat::WhisperRecv");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_WHISPER_UNDELIVERABLE, CHAT), "Chat::WhisperUndeliverable");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_CATEGORY_DESCRIPTIONS, CHAT), "Chat::CategoryDescriptions");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_CONFERENCE_DESCRIPTIONS, CHAT), "Chat::ConferenceDescriptions");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_CONFERENCE_MEMBER_COUNTS, CHAT), "Chat::ConferenceMemberCounts");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_JOIN_NOTIFY_2, CHAT), "Chat::JoinNotify2");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_MODIFY_CHANNEL_LIST_RESPONSE, CHAT), "Chat::ModifyChannelListResponse");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_CONFIG_CHANGED, CHAT), "Chat::ConfigChanged");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_WHISPER_ECHO_RECV, CHAT), "Chat::WhisperEchoRecv");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_GET_MEMBER_COUNT_RESPONSE, CHAT), "Chat::GetMemberCountResponse");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_MODIFY_CHANNEL_LIST_RESPONSE_2, CHAT), "Chat::ModifyChannelListResponse2");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_GAME_DATA_SEND_RESPONSE, CHAT), "Chat::GameDataSendResponse");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Chat::SMSG_GAME_DATA_RECV, CHAT), "Chat::GameDataRecv");
}

void Battlenet::PacketManager::RegisterSupportPackets()
{
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Support::CMSG_COMPLAINT_REQUEST, SUPPORT), "Support::ComplaintRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Support::CMSG_COMPLAINT_REQUEST_2, SUPPORT), "Support::ComplaintRequest2");
}

void Battlenet::PacketManager::RegisterAchievementPackets()
{
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Achievement::CMSG_LISTEN_REQUEST, ACHIEVEMENT), "Achievement::ListenRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Achievement::CMSG_CRITERIA_FLUSH_REQUEST, ACHIEVEMENT), "Achievement::CriteriaFlushRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Achievement::CMSG_CHANGE_TROPHY_CASE_REQUEST, ACHIEVEMENT), "Achievement::ChangeTrophyCaseRequest");

    REGISTER_SERVER_PACKET_NAME(PacketHeader(Achievement::SMSG_DATA, ACHIEVEMENT), "Achievement::Data");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Achievement::SMSG_CRITERIA_FLUSH_RESPONSE, ACHIEVEMENT), "Achievement::CriteriaFlushResponse");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Achievement::SMSG_ACHIEVEMENT_HANDLE_UPDATE, ACHIEVEMENT), "Achievement::AchievementHandleUpdate");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Achievement::SMSG_CHANGE_TROPHY_CASE_RESULT, ACHIEVEMENT), "Achievement::ChangeTrophyCaseResult");
}

void Battlenet::PacketManager::RegisterCachePackets()
{
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Cache::CMSG_GATEWAY_LOOKUP_REQUEST, CACHE), "Cache::GatewayLookupRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Cache::CMSG_CONNECT_REQUEST, CACHE), "Cache::ConnectRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Cache::CMSG_DATA_CHUNK, CACHE), "Cache::DataChunk");
    REGISTER_CLIENT_PACKET(PacketHeader(Cache::CMSG_GET_STREAM_ITEMS_REQUEST, CACHE), Cache::GetStreamItemsRequest);

    REGISTER_SERVER_PACKET_NAME(PacketHeader(Cache::SMSG_GATEWAY_LOOKUP_RESPONSE, CACHE), "Cache::GatewayLookupResponse");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Cache::SMSG_CONNECT_RESPONSE, CACHE), "Cache::ConnectResponse");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Cache::SMSG_PUBLISH_LIST_RESPONSE, CACHE), "Cache::PublishListResponse");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Cache::SMSG_RESULT, CACHE), "Cache::Result");
    REGISTER_SERVER_PACKET(PacketHeader(Cache::SMSG_GET_STREAM_ITEMS_RESPONSE, CACHE), Cache::GetStreamItemsResponse);
}

void Battlenet::PacketManager::RegisterProfilePackets()
{
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Profile::CMSG_READ_REQUEST, PROFILE), "Profile::ReadRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Profile::CMSG_ADDRESS_QUERY_REQUEST, PROFILE), "Profile::AddressQueryRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Profile::CMSG_RESOLVE_TOON_HANDLE_TO_NAME_REQUEST, PROFILE), "Profile::ResolveHandleToToonNameRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Profile::CMSG_RESOLVE_TOON_NAME_TO_HANDLE_REQUEST, PROFILE), "Profile::ResolveToonNameToHandleRequest");
    REGISTER_CLIENT_PACKET_NAME(PacketHeader(Profile::CMSG_CHANGE_SETTINGS, PROFILE), "Profile::ChangeSettings");

    REGISTER_SERVER_PACKET_NAME(PacketHeader(Profile::SMSG_READ_RESPONSE, PROFILE), "Profile::ReadResponse");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Profile::SMSG_ADDRESS_QUERY_RESPONSE, PROFILE), "Profile::AddressQueryResponse");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Profile::SMSG_RESOLVE_TOON_HANDLE_TO_NAME_RESPONSE, PROFILE), "Profile::ResolveHandleToToonNameResponse");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Profile::SMSG_RESOLVE_TOON_NAME_TO_HANDLE_RESPONSE, PROFILE), "Profile::ResolveToonNameToHandleResponse");
    REGISTER_SERVER_PACKET_NAME(PacketHeader(Profile::SMSG_SETTINGS_AVAILABLE, PROFILE), "Profile::SettingsAvailable");
}
