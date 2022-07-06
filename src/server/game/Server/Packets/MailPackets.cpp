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

WorldPackets::Mail::MailAttachedItem::MailAttachedItem(::Item const* item, uint8 pos)
{
    Position = pos;
    AttachID = item->GetGUID().GetCounter();
    Item.Initialize(item);
    Count = item->GetCount();
    Charges = item->GetSpellCharges();
    MaxDurability = item->m_itemData->MaxDurability;
    Durability = item->m_itemData->Durability;
    Unlocked = !item->IsLocked();

    for (uint8 j = 0; j < MAX_INSPECTED_ENCHANTMENT_SLOT; j++)
    {
        EnchantmentSlot slot = EnchantmentSlot(j);
        if (!item->GetEnchantmentId(slot))
            continue;

        Enchants.emplace_back(item->GetEnchantmentId(slot), item->GetEnchantmentDuration(slot), item->GetEnchantmentCharges(slot), j);
    }

    uint8 i = 0;
    for (UF::SocketedGem const& gemData : item->m_itemData->Gems)
    {
        if (gemData.ItemID)
        {
            WorldPackets::Item::ItemGemData gem;
            gem.Slot = i;
            gem.Item.Initialize(&gemData);
            Gems.push_back(gem);
        }
        ++i;
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Mail::MailAttachedItem const& att)
{
    data << uint8(att.Position);
    data << int32(att.AttachID);
    data << int32(att.Count);
    data << int32(att.Charges);
    data << uint32(att.MaxDurability);
    data << int32(att.Durability);
    data << att.Item;
    data.WriteBits(att.Enchants.size(), 4);
    data.WriteBits(att.Gems.size(), 2);
    data.WriteBit(att.Unlocked);
    data.FlushBits();

    for (WorldPackets::Item::ItemGemData const& gem : att.Gems)
        data << gem;

    for (WorldPackets::Item::ItemEnchantData const& en : att.Enchants)
        data << en;

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
    DaysLeft = float(mail->expire_time - GameTime::GetGameTime()) / DAY;
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
    data << uint8(entry.SenderType);
    data << uint64(entry.Cod);
    data << int32(entry.StationeryID);
    data << uint64(entry.SentMoney);
    data << int32(entry.Flags);
    data << float(entry.DaysLeft);
    data << int32(entry.MailTemplateID);
    data << uint32(entry.Attachments.size());
    data.WriteBit(entry.SenderCharacter.is_initialized());
    data.WriteBit(entry.AltSenderID.is_initialized());
    data.WriteBits(entry.Subject.size(), 8);
    data.WriteBits(entry.Body.size(), 13);
    data.FlushBits();

    for (WorldPackets::Mail::MailAttachedItem const& att : entry.Attachments)
        data << att;

    if (entry.SenderCharacter)
        data << *entry.SenderCharacter;

    if (entry.AltSenderID)
        data << int32(*entry.AltSenderID);

    data.WriteString(entry.Subject);
    data.WriteString(entry.Body);

    return data;
}

void WorldPackets::Mail::MailGetList::Read()
{
    _worldPacket >> Mailbox;
}

WorldPacket const* WorldPackets::Mail::MailListResult::Write()
{
    _worldPacket << uint32(Mails.size());
    _worldPacket << int32(TotalNumRecords);

    for (MailListEntry const& mail : Mails)
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

    TimeLeft = mail->deliver_time - GameTime::GetGameTime();
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
