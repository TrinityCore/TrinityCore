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

#include "MailPackets.h"
#include "GameTime.h"
#include "Item.h"
#include "Mail.h"
#include "Player.h"
#include "World.h"

 // SMSG
WorldPacket const* WorldPackets::Mail::ShowMailbox::Write()
{
    _worldPacket << PostmasterGUID;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Mail::MailCommandResult::Write()
{
    _worldPacket << uint32(MailID);
    _worldPacket << uint32(Command);
    _worldPacket << uint32(ErrorCode);

    if (ErrorCode == MAIL_ERR_EQUIP_ERROR)
        _worldPacket << uint32(BagResult);

    if (Command == MAIL_ITEM_TAKEN)
    {
        if (ErrorCode == MAIL_OK || ErrorCode == MAIL_ERR_ITEM_HAS_EXPIRED)
        {
            _worldPacket << uint32(AttachID);
            _worldPacket << uint32(QtyInInventory);
        }
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Mail::NotifyReceivedMail::Write()
{
    _worldPacket << float(Delay);

    return &_worldPacket;
}

// CMSG
void WorldPackets::Mail::SendMailClient::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> Target;
    _worldPacket >> Subject;
    _worldPacket >> Body;
    _worldPacket >> StationeryID;
    _worldPacket >> PackageID;
    Attachments.resize(_worldPacket.read<uint8>());

    for (auto& att : Attachments)
    {
        _worldPacket >> att.AttachPosition;
        _worldPacket >> att.ItemGUID;
    }

    _worldPacket >> SendMoney;
    _worldPacket >> Cod;
    _worldPacket.read_skip<uint64>();
    _worldPacket.read_skip<uint8>();
}

void WorldPackets::Mail::MailMarkAsRead::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
}

void WorldPackets::Mail::MailDelete::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
    _worldPacket >> DeleteReason;
}

void WorldPackets::Mail::MailReturnToSender::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
    _worldPacket >> SenderGUID;
}

void WorldPackets::Mail::MailTakeItem::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
    _worldPacket >> AttachID;
}

void WorldPackets::Mail::MailTakeMoney::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
}

void WorldPackets::Mail::MailGetList::Read()
{
    _worldPacket >> Mailbox;
}

void WorldPackets::Mail::MailCreateTextItem::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
}
