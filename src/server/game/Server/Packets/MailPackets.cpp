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
#include "Item.h"
#include "Mail.h"
#include "Player.h"
#include "World.h"

WorldPackets::Mail::MailAttachedItem::MailAttachedItem(::Item const* item, uint8 pos)
{
    Position = pos;
    AttachID = item->GetGUID().GetCounter();
    ItemID = item->GetEntry();
    RandomPropertiesID = item->GetItemRandomPropertyId();
    RandomPropertiesSeed = item->GetItemSuffixFactor();
    Count = item->GetCount();
    Charges = item->GetSpellCharges();
    MaxDurability = item->GetUInt32Value(ITEM_FIELD_MAXDURABILITY);
    Durability = item->GetInt32Value(ITEM_FIELD_DURABILITY);
    Unlocked = !item->IsLocked();

    for (uint8 j = 0; j < MAX_INSPECTED_ENCHANTMENT_SLOT; j++)
    {
        EnchantmentSlot slot = EnchantmentSlot(j);
        EnchantmentID[slot] = item->GetEnchantmentId(slot);
        EnchantmentDuration[slot] = item->GetEnchantmentDuration(slot);
        EnchantmentCharges[slot] = item->GetEnchantmentCharges(slot);
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Mail::MailAttachedItem const& att)
{
    data << uint8(att.Position);
    data << int32(att.AttachID);
    data << int32(att.ItemID);
    for (uint8 i = 0; i < MAX_INSPECTED_ENCHANTMENT_SLOT; i++)
    {
        data << int32(att.EnchantmentID[i]);
        data << int32(att.EnchantmentDuration[i]);
        data << int32(att.EnchantmentCharges[i]);
    }
    data << int32(att.RandomPropertiesID);
    data << int32(att.RandomPropertiesSeed);
    data << int32(att.Count);
    data << int32(att.Charges);
    data << uint32(att.MaxDurability);
    data << int32(att.Durability);
    data << bool(att.Unlocked);

    return data;
}

WorldPackets::Mail::MailListEntry::MailListEntry(::Mail const* mail, ::Player* player)
{
    MailID = mail->messageID;
    SenderType = mail->messageType;

    switch (mail->messageType)
    {
        case MAIL_NORMAL:
            SenderCharacter = ObjectGuid::Create<HighGuid::Player>(mail->sender);
            break;
        case MAIL_CREATURE:
        case MAIL_GAMEOBJECT:
        case MAIL_AUCTION:
        case MAIL_CALENDAR:
            AltSenderID = mail->sender;
            break;
    }

    Cod = mail->COD;
    StationeryID = mail->stationery;
    SentMoney = mail->money;
    Flags = mail->checked;
    DaysLeft = float(mail->expire_time - time(nullptr)) / DAY;
    MailTemplateID = mail->mailTemplateId;
    Subject = mail->subject;
    Body = mail->body;

    for (uint8 i = 0; i < mail->items.size(); i++)
        if (::Item* item = player->GetMItem(mail->items[i].item_guid))
            Attachments.emplace_back(item, i);
}

std::size_t WorldPackets::Mail::MailListEntry::GetPacketSize() const
{
    return sizeof(uint16) + sizeof(int32) + sizeof(uint8) + (SenderCharacter ? sizeof(uint64) : 0) + (AltSenderID ? sizeof(int32) : 0)
        + sizeof(uint32) + sizeof(int32) + sizeof(int32) + sizeof(uint32) + sizeof(int32) + sizeof(float) + sizeof(int32)
        + Subject.length() + 1 + Body.length() + 1 + sizeof(uint8) + Attachments.size() * MailAttachedItem::GetPacketSize();
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Mail::MailListEntry const& entry)
{
    data << uint16(entry.GetPacketSize());
    data << int32(entry.MailID);
    data << uint8(entry.SenderType);
    if (entry.SenderCharacter)
        data << *entry.SenderCharacter;
    else if (entry.AltSenderID)
        data << int32(*entry.AltSenderID);

    data << uint32(entry.Cod);
    data << int32(entry.PackageID);
    data << int32(entry.StationeryID);
    data << uint32(entry.SentMoney);
    data << int32(entry.Flags);
    data << float(entry.DaysLeft);
    data << int32(entry.MailTemplateID);
    data << entry.Subject;
    data << entry.Body;
    data << uint8(entry.Attachments.size());

    for (WorldPackets::Mail::MailAttachedItem const& att : entry.Attachments)
        data << att;

    return data;
}

void WorldPackets::Mail::MailGetList::Read()
{
    _worldPacket >> Mailbox;
}

WorldPackets::Mail::MailListResult::MailListResult() : ServerPacket(SMSG_MAIL_LIST_RESULT, 8)
{
    _worldPacket << int32(0); // TotalNumRecords
    _worldPacket << uint8(0); // Mails.size()
}

WorldPacket const* WorldPackets::Mail::MailListResult::Write()
{
    _worldPacket.put<int32>(0, TotalNumRecords);
    _worldPacket.put<uint8>(4, Mails.size());

    return &_worldPacket;
}

void WorldPackets::Mail::MailListResult::AddMail(::Mail const* mail, Player* player)
{
    ++TotalNumRecords;
    if (Mails.size() >= 50 || _maxPacketSizeReached)
        return;

    MailListEntry packetEntry(mail, player);
    if (_worldPacket.size() + packetEntry.GetPacketSize() >= std::size_t(std::numeric_limits<int16>::max()))
    {
        _maxPacketSizeReached = true;
        return;
    }

    _worldPacket << Mails.emplace_back(std::move(packetEntry));
}

void WorldPackets::Mail::MailCreateTextItem::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
}

void WorldPackets::Mail::SendMail::Read()
{
    _worldPacket >> Info.Mailbox;
    _worldPacket >> Info.Target;
    _worldPacket >> Info.Subject;
    _worldPacket >> Info.Body;
    _worldPacket >> Info.StationeryID;
    _worldPacket >> Info.PackageID;
    Info.Attachments.resize(_worldPacket.read<uint8>());

    for (auto& att : Info.Attachments)
    {
        _worldPacket >> att.AttachPosition;
        _worldPacket >> att.ItemGUID;
    }

    _worldPacket >> Info.SendMoney;
    _worldPacket >> Info.Cod;
    _worldPacket.read_skip<uint64>();
    _worldPacket.read_skip<uint8>();
}

void WorldPackets::Mail::MailReturnToSender::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
    _worldPacket >> SenderGUID;
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

WorldPackets::Mail::MailQueryNextTimeResult::MailNextTimeEntry::MailNextTimeEntry(::Mail const* mail)
{
    switch (mail->messageType)
    {
        case MAIL_NORMAL:
            SenderGuid = ObjectGuid::Create<HighGuid::Player>(mail->sender);
            break;
        case MAIL_AUCTION:
        case MAIL_CREATURE:
        case MAIL_GAMEOBJECT:
        case MAIL_CALENDAR:
            AltSenderID = mail->sender;
            break;
    }

    TimeLeft = mail->deliver_time - time(nullptr);
    AltSenderType = mail->messageType;
    StationeryID = mail->stationery;
}

WorldPacket const* WorldPackets::Mail::MailQueryNextTimeResult::Write()
{
    _worldPacket << float(NextMailTime);
    _worldPacket << int32(Next.size());

    for (auto const& entry : Next)
    {
        _worldPacket << entry.SenderGuid;
        _worldPacket << int32(entry.AltSenderID);
        _worldPacket << int32(entry.AltSenderType);
        _worldPacket << int32(entry.StationeryID);
        _worldPacket << float(entry.TimeLeft);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Mail::NotifyReceivedMail::Write()
{
    _worldPacket << float(Delay);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Mail::ShowMailbox::Write()
{
    _worldPacket << PostmasterGUID;

    return &_worldPacket;
}
