/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "Mail.h"
#include "MailPackets.h"
#include "Player.h"
#include "World.h"

WorldPackets::Mail::MailAttachedItem::MailAttachedItem(::Item const* item, uint8 pos)
{
    Position = pos;
    AttachID = item->GetGUID().GetCounter();
    Item.Initalize(item);
    Count = item->GetCount();
    Charges = item->GetSpellCharges();
    MaxDurability = item->GetUInt32Value(ITEM_FIELD_MAXDURABILITY);
    Durability = item->GetUInt32Value(ITEM_FIELD_DURABILITY);
    Unlocked = !item->IsLocked(); //TODO: Check

    for (uint8 j = 0; j < MAX_INSPECTED_ENCHANTMENT_SLOT; j++)
    {
        Enchants[j].Enchant = item->GetEnchantmentId((EnchantmentSlot)j);
        Enchants[j].Duration = item->GetEnchantmentDuration((EnchantmentSlot)j);
        Enchants[j].Charges = item->GetEnchantmentCharges((EnchantmentSlot)j);
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Mail::MailAttachedItem const& att)
{
    data << uint8(att.Position);
    data << uint32(att.AttachID);
    data << att.Item;

    for (auto const& en : att.Enchants)
    {
        data << int32(en.Enchant);
        data << int32(en.Duration);
        data << int32(en.Charges);
    }

    data << int32(att.Count);
    data << int32(att.Charges);
    data << int32(att.MaxDurability);
    data << int32(att.Durability);
    data.WriteBit(att.Unlocked);
    data.FlushBits();

    return data;
}

WorldPackets::Mail::MailListEntry::MailListEntry(::Mail const* mail, ::Player* player)
{
    MailID = mail->messageID;
    SenderType = mail->messageType;

    switch (mail->messageType)
    {
        case MAIL_NORMAL:
            SenderCharacter.Set(ObjectGuid::Create<HighGuid::Player>(mail->sender));
            break;
        case MAIL_CREATURE:
        case MAIL_GAMEOBJECT:
        case MAIL_AUCTION:
        case MAIL_CALENDAR:
            AltSenderID.Set(mail->sender);
            break;
    }

    Cod = mail->COD;
    PackageID = 0;
    StationeryID = mail->stationery;
    SentMoney = mail->money;
    Flags = mail->checked;
    DaysLeft = float(mail->expire_time - time(nullptr)) / DAY;
    MailTemplateID = mail->mailTemplateId;
    Subject = mail->subject;
    Body = mail->body;

    for (uint8 i = 0; i < mail->items.size(); i++)
    {
        if (::Item* item = player->GetMItem(mail->items[i].item_guid))
            Attachments.emplace_back(item, i);
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Mail::MailListEntry const& entry)
{
    data << int32(entry.MailID);
    data << int8(entry.SenderType);

    data << int64(entry.Cod);
    data << int32(entry.PackageID);
    data << int32(entry.StationeryID);
    data << int64(entry.SentMoney);
    data << int32(entry.Flags);
    data << float(entry.DaysLeft);
    data << int32(entry.MailTemplateID);

    data << int32(entry.Attachments.size());

    for (auto const& att : entry.Attachments)
        data << att;

    data.WriteBit(entry.SenderCharacter.HasValue);
    data.WriteBit(entry.AltSenderID.HasValue);

    data.WriteBits(entry.Subject.size(), 8);
    data.WriteBits(entry.Body.size(), 13);
    data.FlushBits();

    if (entry.SenderCharacter.HasValue)
        data << entry.SenderCharacter.Value;

    if (entry.AltSenderID.HasValue)
        data << int32(entry.AltSenderID.Value);

    data.WriteString(entry.Subject);
    data.WriteString(entry.Body);

    return data;
}

void WorldPackets::Mail::MailGetList::Read()
{
    _worldPacket >> Mailbox;
    LowGuids.resize(_worldPacket.read<int32>());

    for (auto& l : LowGuids)
        _worldPacket >> l;
}

WorldPacket const* WorldPackets::Mail::MailListResult::Write()
{
    _worldPacket << int32(Mails.size());
    _worldPacket << int32(TotalNumRecords);

    for (auto const& mail : Mails)
        _worldPacket << mail;

    return &_worldPacket;
}

void WorldPackets::Mail::MailCreateTextItem::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
}

void WorldPackets::Mail::SendMail::Read()
{
    _worldPacket >> Info.Mailbox;
    _worldPacket >> Info.StationeryID;
    _worldPacket >> Info.PackageID;
    _worldPacket >> Info.SendMoney;
    _worldPacket >> Info.Cod;

    uint32 targetLength = _worldPacket.ReadBits(9);
    uint32 subjectLength = _worldPacket.ReadBits(9);
    uint32 bodyLength = _worldPacket.ReadBits(11);

    Info.Attachments.resize(_worldPacket.ReadBits(5));

    Info.Target = _worldPacket.ReadString(targetLength);
    Info.Subject = _worldPacket.ReadString(subjectLength);
    Info.Body = _worldPacket.ReadString(bodyLength);

    for (auto& att : Info.Attachments)
    {
        _worldPacket >> att.AttachPosition;
        _worldPacket >> att.ItemGUID;
    }
}

void WorldPackets::Mail::MailReturnToSender::Read()
{
    _worldPacket >> MailID;
    _worldPacket >> SenderGUID;
}

WorldPacket const* WorldPackets::Mail::MailCommandResult::Write()
{
    _worldPacket << uint32(MailID);
    _worldPacket << uint32(Command);
    _worldPacket << uint32(ErrorCode);
    _worldPacket << uint32(BagResult);
    _worldPacket << uint32(AttachID);
    _worldPacket << uint32(QtyInInventory);

    return &_worldPacket;
}

void WorldPackets::Mail::MailMarkAsRead::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
    BiReceipt = _worldPacket.ReadBit();
}

void WorldPackets::Mail::MailDelete::Read()
{
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
    _worldPacket >> Money;
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
        _worldPacket << float(entry.TimeLeft);
        _worldPacket << int32(entry.AltSenderID);
        _worldPacket << int8(entry.AltSenderType);
        _worldPacket << int32(entry.StationeryID);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Mail::NotifyRecievedMail::Write()
{
    _worldPacket << float(Delay);

    return &_worldPacket;
}
