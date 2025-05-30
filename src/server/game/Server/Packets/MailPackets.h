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

#ifndef TRINITYCORE_MAIL_PACKETS_H
#define TRINITYCORE_MAIL_PACKETS_H

#include "Packet.h"
#include "ItemPacketsCommon.h"
#include "ObjectGuid.h"

class Player;
struct Mail;

namespace WorldPackets
{
    namespace Mail
    {
        struct MailAttachedItem
        {
            MailAttachedItem(::Item const* item, uint8 pos);

            uint8 Position = 0;
            uint64 AttachID = 0;
            Item::ItemInstance Item;
            int32 Count = 0;
            int32 Charges = 0;
            uint32 MaxDurability = 0;
            int32 Durability = 0;
            bool Unlocked = false;
            std::vector<Item::ItemEnchantData> Enchants;
            std::vector<Item::ItemGemData> Gems;
        };

        struct MailListEntry
        {
            MailListEntry(::Mail const* mail, ::Player* player);

            uint64 MailID = 0;
            uint8 SenderType = 0;
            ObjectGuid SenderCharacter;
            uint32 AltSenderID;
            uint64 Cod = 0;
            int32 StationeryID = 0;
            uint64 SentMoney = 0;
            int32 Flags = 0;
            float DaysLeft = 0.0f;
            int32 MailTemplateID = 0;
            std::string Subject;
            std::string Body;
            std::vector<MailAttachedItem> Attachments;
        };

        class MailGetList final : public ClientPacket
        {
        public:
            explicit MailGetList(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_GET_LIST, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
        };

        class MailListResult final : public ServerPacket
        {
        public:
            explicit MailListResult() : ServerPacket(SMSG_MAIL_LIST_RESULT, 8) { }

            WorldPacket const* Write() override;

            int32 TotalNumRecords = 0;
            std::vector<MailListEntry> Mails;
        };

        class MailCreateTextItem final : public ClientPacket
        {
        public:
            explicit MailCreateTextItem(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_CREATE_TEXT_ITEM, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            uint64 MailID = 0;
        };

        class SendMail final : public ClientPacket
        {
        public:
            struct StructSendMail
            {
                struct MailAttachment
                {
                    uint8 AttachPosition = 0;
                    ObjectGuid ItemGUID;
                };

                ObjectGuid Mailbox;
                int32 StationeryID = 0;
                int64 SendMoney = 0;
                int64 Cod = 0;
                std::string Target;
                std::string Subject;
                std::string Body;
                std::vector<MailAttachment> Attachments;
            };

            explicit SendMail(WorldPacket&& packet) : ClientPacket(CMSG_SEND_MAIL, std::move(packet)) { }

            void Read() override;

            StructSendMail Info;
        };

        class MailCommandResult final : public ServerPacket
        {
        public:
            explicit MailCommandResult() : ServerPacket(SMSG_MAIL_COMMAND_RESULT) { }

            WorldPacket const* Write() override;

            uint64 MailID = 0;
            int32 Command = 0;
            int32 ErrorCode = 0;
            int32 BagResult = 0;
            uint64 AttachID = 0;
            int32 QtyInInventory = 0;
        };

        class MailReturnToSender final : public ClientPacket
        {
        public:
            explicit MailReturnToSender(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_RETURN_TO_SENDER, std::move(packet)) { }

            void Read() override;

            uint64 MailID = 0;
            ObjectGuid SenderGUID;
        };

        class MailMarkAsRead final : public ClientPacket
        {
        public:
            explicit MailMarkAsRead(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_MARK_AS_READ, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            uint64 MailID = 0;
        };

        class MailDelete final : public ClientPacket
        {
        public:
            explicit MailDelete(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_DELETE, std::move(packet)) { }

            void Read() override;

            uint64 MailID = 0;
            int32 DeleteReason = 0;
        };

        class MailTakeItem final : public ClientPacket
        {
        public:
            explicit MailTakeItem(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_TAKE_ITEM, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            uint64 MailID = 0;
            uint64 AttachID = 0;
        };

        class MailTakeMoney final : public ClientPacket
        {
        public:
            explicit MailTakeMoney(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_TAKE_MONEY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            uint64 MailID = 0;
            uint64 Money = 0;
        };

        class MailQueryNextMailTime final : public ClientPacket
        {
        public:
            explicit MailQueryNextMailTime(WorldPacket&& packet) : ClientPacket(CMSG_QUERY_NEXT_MAIL_TIME, std::move(packet)) { }

            void Read() override { }
        };

        class MailQueryNextTimeResult final : public ServerPacket
        {
        public:
            struct MailNextTimeEntry
            {
                MailNextTimeEntry(::Mail const* mail);

                ObjectGuid SenderGuid;
                float TimeLeft = 0.0f;
                int32 AltSenderID = 0;
                int8 AltSenderType = 0;
                int32 StationeryID = 0;
            };

            explicit MailQueryNextTimeResult() : ServerPacket(SMSG_MAIL_QUERY_NEXT_TIME_RESULT, 8) { }

            WorldPacket const* Write() override;

            float NextMailTime = 0.0f;
            std::vector<MailNextTimeEntry> Next;
        };

        class NotifyReceivedMail : ServerPacket
        {
        public:
            explicit NotifyReceivedMail() : ServerPacket(SMSG_NOTIFY_RECEIVED_MAIL, 4) { }

            WorldPacket const* Write() override;

            float Delay = 0.0f;
        };
    }
}

#endif // TRINITYCORE_MAIL_PACKETS_H
