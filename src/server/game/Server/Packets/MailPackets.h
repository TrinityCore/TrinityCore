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

#ifndef MailPackets_h__
#define MailPackets_h__

#include "Packet.h"
#include "ItemDefines.h"
#include "Mail.h"
#include "Optional.h"
#include "PacketUtilities.h"

namespace WorldPackets
{
    namespace Mail
    {
        // SMSG
        class ShowMailbox final : public ServerPacket
        {
        public:
            ShowMailbox() : ServerPacket(SMSG_SHOW_MAILBOX, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid PostmasterGUID;
        };

        class MailCommandResult final : public ServerPacket
        {
        public:
            MailCommandResult() : ServerPacket(SMSG_SEND_MAIL_RESULT) { }

            WorldPacket const* Write() override;

            uint32 MailID = 0;
            uint32 Command = 0;
            uint32 ErrorCode = 0;
            uint32 BagResult = 0;
            uint32 AttachID = 0;
            uint32 QtyInInventory = 0;
        };

        class NotifyReceivedMail : ServerPacket
        {
        public:
            NotifyReceivedMail() : ServerPacket(SMSG_RECEIVED_MAIL, 4) { }

            WorldPacket const* Write() override;

            float Delay = 0.0f;
        };

        // CMSG
        class SendMailClient final : public ClientPacket
        {
        public:
            SendMailClient(WorldPacket&& packet) : ClientPacket(CMSG_SEND_MAIL, std::move(packet)) { }

            void Read() override;

            struct MailAttachment
            {
                uint8 AttachPosition = 0;
                ObjectGuid ItemGUID;
            };

            ObjectGuid Mailbox;
            int32 StationeryID = 0;
            int32 PackageID = 0;
            int32 SendMoney = 0;
            int32 Cod = 0;
            std::string Target;
            String<255, Strings::NoHyperlinks> Subject;
            String<7999, Strings::NoHyperlinks> Body;
            Array<MailAttachment, MAX_MAIL_ITEMS> Attachments;
        };

        class MailMarkAsRead final : public ClientPacket
        {
        public:
            MailMarkAsRead(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_MARK_AS_READ, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            int32 MailID = 0;
        };

        class MailDelete final : public ClientPacket
        {
        public:
            MailDelete(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_DELETE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            int32 MailID = 0;
            int32 DeleteReason = 0;
        };

        class MailReturnToSender final : public ClientPacket
        {
        public:
            MailReturnToSender(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_RETURN_TO_SENDER, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            int32 MailID = 0;
            ObjectGuid SenderGUID;
        };

        class MailTakeItem final : public ClientPacket
        {
        public:
            MailTakeItem(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_TAKE_ITEM, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            int32 MailID = 0;
            int32 AttachID = 0;
        };

        class MailTakeMoney final : public ClientPacket
        {
        public:
            MailTakeMoney(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_TAKE_MONEY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            int32 MailID = 0;
        };

        class MailGetList final : public ClientPacket
        {
        public:
            MailGetList(WorldPacket&& packet) : ClientPacket(CMSG_GET_MAIL_LIST, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
        };

        class MailCreateTextItem final : public ClientPacket
        {
        public:
            MailCreateTextItem(WorldPacket&& packet) : ClientPacket(CMSG_MAIL_CREATE_TEXT_ITEM, std::move(packet)) { }

            void Read() override;

            ObjectGuid Mailbox;
            uint32 MailID = 0;
        };
    }
}

#endif // MailPackets_h__
