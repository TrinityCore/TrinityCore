#ifndef PROJECT_PACKETS_PREMADE_H
#define PROJECT_PACKETS_PREMADE_H

#include "Packet.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include <array>

namespace PROJECT
{
    namespace Packets
    {
        namespace Premade
        {
            struct LfgListRide
            {
                ObjectGuid Party;
                uint32 Loot = 0;
                uint32 Unk = 0;
                uint32 Timestamp = time(nullptr);
            };

            struct LfgListRoleMember
            {
                uint8 Class = 0;
                uint8 Role = 0;
            };

            struct BlacklistActivity
            {
                uint32 ActivityID = 0;
                uint32 Reason = 0;
            };

            struct LfgListApplication
            {
                uint32 ActivityID = 0;
                float ItemLevelRequired = 0.f;
                uint32 Unk2 = 0;
                std::string Name;
                std::string Comment;
                std::string VoiceChat;
                bool IsAutoAccepted = false;
                bool IsPrivate = false;
                Optional<uint32> Quest;
            };

            struct LfgEntity
            {
                LfgListRide Ride;
                uint32 Unk1 = 0;
                std::array<ObjectGuid, 4> Owners;
                uint32 VirtualRealmAddress = 0;
                std::vector<ObjectGuid> Guid1;
                std::vector<ObjectGuid> Guid2;
                std::vector<ObjectGuid> Guid3;
                std::vector<LfgListRoleMember> MemberRoles;
                uint32 Unk3 = 0;
                uint32 CreationTime = 0;
                uint8 RoleMask = 0;
                LfgListApplication Application;
            };

            class RequestLfgListBlacklist final : public WorldPackets::ClientPacket
            {
            public:
                RequestLfgListBlacklist(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_REQUEST_LFG_LIST_BLACKLIST, std::move(packet)) { }

                void Read() override { };
            };

            class LfgListUpdateBlacklist final : public WorldPackets::ServerPacket
            {
            public:
                LfgListUpdateBlacklist() : WorldPackets::ServerPacket(SMSG_LFG_LIST_UPDATE_BLACKLIST) { }

                WorldPacket const* Write() override;
                
                std::vector<BlacklistActivity> Blacklists;
            };

            class LfgListSearch final : public WorldPackets::ClientPacket
            {
            public:
                LfgListSearch(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_LFG_LIST_SEARCH, std::move(packet)) { }

                void Read() override;

                uint32 Category = 0;
                uint32 SubCategory = 0;
                uint32 Unk1 = 0;
                uint32 Unk2 = 0;
                std::string SearchFilter;
                std::vector<BlacklistActivity> Blacklists;
                std::vector<ObjectGuid> Guids;
            };

            class LfgListSearchResults final : public WorldPackets::ServerPacket
            {
            public:
                LfgListSearchResults() : WorldPackets::ServerPacket(SMSG_LFG_LIST_SEARCH_RESULTS) { }

                WorldPacket const* Write() override;

                std::vector<LfgEntity> Entities;
            };

            class LfgListJoin final : public WorldPackets::ClientPacket
            {
            public:
                LfgListJoin(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_LFG_LIST_JOIN, std::move(packet)) { }

                void Read() override;

                LfgListApplication Application;
            };

            class LfgListUpdateStatus final : public WorldPackets::ServerPacket
            {
            public:
                LfgListUpdateStatus() : WorldPackets::ServerPacket(SMSG_LFG_LIST_UPDATE_STATUS) { }

                WorldPacket const* Write() override;

                LfgListRide Ride;
                LfgListApplication Application;
                uint32 CreationDate = time(nullptr);
                uint8 Reason = 0;
                bool Listed = false;
            };

            class LfgListLeave final : public WorldPackets::ClientPacket
            {
            public:
                LfgListLeave(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_LFG_LIST_LEAVE, std::move(packet)) { }

                void Read() override;

                LfgListRide Ride;
            };

            class LfgListUpdateRequest final : public WorldPackets::ClientPacket
            {
            public:
                LfgListUpdateRequest(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_LFG_LIST_UPDATE_REQUEST, std::move(packet)) { }

                void Read() override;

                LfgListRide Ride;
                LfgListApplication Application;
            };

            class LfgListApplyToGroup final : public WorldPackets::ClientPacket
            {
            public:
                LfgListApplyToGroup(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_LFG_LIST_APPLY_TO_GROUP, std::move(packet)) { }

                void Read() override;

                LfgListRide Ride;
                uint32 ActivityID;
                uint8 RoleMask;
                std::string Comment;
            };

            class LfgListCancelApplication final : public WorldPackets::ClientPacket
            {
            public:
                LfgListCancelApplication(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_LFG_LIST_CANCEL_APPLICATION, std::move(packet)) { }

                void Read() override;

                LfgListRide Ride;
            };

            class LfgListInviteApplicant final : public WorldPackets::ClientPacket
            {
            public:
                LfgListInviteApplicant(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_LFG_LIST_INVITE_APPLICANT, std::move(packet)) { }

                void Read() override;

                struct Member
                {
                    ObjectGuid Guid;
                    uint8 Role;
                };

                LfgListRide RideParty;
                LfgListRide RideApplicant;
                std::vector<Member> Members;
            };

            class LfgListInviteResponse final : public WorldPackets::ClientPacket
            {
            public:
                LfgListInviteResponse(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_LFG_LIST_INVITE_RESPONSE, std::move(packet)) { }

                void Read() override;

                LfgListRide Ride;
                bool Accepted;
            };

            class LfgListDeclineApplication final : public WorldPackets::ClientPacket
            {
            public:
                LfgListDeclineApplication(WorldPacket&& packet) : WorldPackets::ClientPacket(CMSG_LFG_LIST_DECLINE_APPLICANT, std::move(packet)) { }

                void Read() override;

                LfgListRide Ride;
                LfgListRide RideApply;
            };

            class LfgListJoinResult final : public WorldPackets::ServerPacket
            {
            public:
                LfgListJoinResult() : WorldPackets::ServerPacket(SMSG_LFG_LIST_JOIN_RESULT) { }

                WorldPacket const* Write() override;

                LfgListRide Ride;
                uint8 Error = 0;
                uint8 Unk = 0;
            };
        }
    }
}

ByteBuffer& operator<<(ByteBuffer& data, PROJECT::Packets::Premade::LfgListRide const& ride);
ByteBuffer& operator<<(ByteBuffer& data, PROJECT::Packets::Premade::LfgListApplication const& application);
ByteBuffer& operator<<(ByteBuffer& data, PROJECT::Packets::Premade::LfgEntity const& e);
ByteBuffer& operator >> (ByteBuffer& data, PROJECT::Packets::Premade::LfgListRide& ride);
ByteBuffer& operator>>(ByteBuffer& data, PROJECT::Packets::Premade::LfgListApplication& ride);

#endif
