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
#include "PacketOperators.h"
#include "Player.h"

namespace WorldPackets::Mail
{
MailAttachedItem::MailAttachedItem(::Item const* item, uint8 pos)
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
            Item::ItemGemData gem;
            gem.Slot = i;
            gem.Item.Initialize(&gemData);
            Gems.push_back(gem);
        }
        ++i;
    }
}

ByteBuffer& operator<<(ByteBuffer& data, MailAttachedItem const& att)
{
    data << uint8(att.Position);
    data << uint64(att.AttachID);
    data << int32(att.Count);
    data << int32(att.Charges);
    data << uint32(att.MaxDurability);
    data << int32(att.Durability);
    data << att.Item;
    data << BitsSize<4>(att.Enchants);
    data << BitsSize<2>(att.Gems);
    data << Bits<1>(att.Unlocked);
    data.FlushBits();

    for (Item::ItemGemData const& gem : att.Gems)
        data << gem;

    for (Item::ItemEnchantData const& en : att.Enchants)
        data << en;

    return data;
}

MailListEntry::MailListEntry(::Mail const* mail, Player* player)
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
        case MAIL_BLACKMARKET:
        case MAIL_COMMERCE_AUCTION:
        case MAIL_AUCTION_2:
        case MAIL_ARTISANS_CONSORTIUM:
            AltSenderID = mail->sender;
            break;
    }

    Cod = mail->COD;
    StationeryID = mail->stationery;
    SentMoney = mail->money;
    Flags = mail->checked;
    DaysLeft = float(mail->expire_time - GameTime::GetGameTime()) / float(DAY);
    MailTemplateID = mail->mailTemplateId;
    Subject = mail->subject;
    Body = mail->body;

    for (uint8 i = 0; i < mail->items.size(); i++)
    {
        if (::Item* item = player->GetMItem(mail->items[i].item_guid))
            Attachments.emplace_back(item, i);
    }
}

ByteBuffer& operator<<(ByteBuffer& data, MailListEntry const& entry)
{
    data << uint64(entry.MailID);
    data << uint32(entry.SenderType);
    data << uint64(entry.Cod);
    data << int32(entry.StationeryID);
    data << uint64(entry.SentMoney);
    data << int32(entry.Flags);
    data << float(entry.DaysLeft);
    data << int32(entry.MailTemplateID);
    data << WorldPackets::Size<uint32>(entry.Attachments);

    switch (entry.SenderType)
    {
        case MAIL_NORMAL:
            data << entry.SenderCharacter;
            break;
        case MAIL_AUCTION:
        case MAIL_CREATURE:
        case MAIL_GAMEOBJECT:
        case MAIL_CALENDAR:
        case MAIL_BLACKMARKET:
        case MAIL_COMMERCE_AUCTION:
        case MAIL_AUCTION_2:
        case MAIL_ARTISANS_CONSORTIUM:
            data << int32(entry.AltSenderID);
            break;
        default:
            break;
    }

    data << SizedString::BitsSize<8>(entry.Subject);
    data << SizedString::BitsSize<13>(entry.Body);
    data.FlushBits();

    for (MailAttachedItem const& att : entry.Attachments)
        data << att;

    data << SizedString::Data(entry.Subject);
    data << SizedString::Data(entry.Body);

    return data;
}

void MailGetList::Read()
{
    _worldPacket >> Mailbox;
}

WorldPacket const* MailListResult::Write()
{
    _worldPacket << Size<uint32>(Mails);
    _worldPacket << int32(TotalNumRecords);

    for (MailListEntry const& mail : Mails)
        _worldPacket << mail;

    return &_worldPacket;
}

void MailCreateTextItem::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
}

ByteBuffer& operator>>(ByteBuffer& data, SendMail::StructSendMail::MailAttachment& attachment)
{
    data >> attachment.AttachPosition;
    data >> attachment.ItemGUID;

    return data;
}

void SendMail::Read()
{
    _worldPacket >> Info.Mailbox;
    _worldPacket >> Info.StationeryID;
    _worldPacket >> Info.SendMoney;
    _worldPacket >> Info.Cod;

    _worldPacket >> SizedString::BitsSize<9>(Info.Target);
    _worldPacket >> SizedString::BitsSize<9>(Info.Subject);
    _worldPacket >> SizedString::BitsSize<11>(Info.Body);
    _worldPacket >> BitsSize<5>(Info.Attachments);

    _worldPacket >> SizedString::Data(Info.Target);
    _worldPacket >> SizedString::Data(Info.Subject);
    _worldPacket >> SizedString::Data(Info.Body);

    for (StructSendMail::MailAttachment& att : Info.Attachments)
        _worldPacket >> att;
}

void MailReturnToSender::Read()
{
    _worldPacket >> MailID;
    _worldPacket >> SenderGUID;
}

WorldPacket const* MailCommandResult::Write()
{
    _worldPacket << uint64(MailID);
    _worldPacket << int32(Command);
    _worldPacket << int32(ErrorCode);
    _worldPacket << int32(BagResult);
    _worldPacket << uint64(AttachID);
    _worldPacket << int32(QtyInInventory);

    return &_worldPacket;
}

void MailMarkAsRead::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
}

void MailDelete::Read()
{
    _worldPacket >> MailID;
    _worldPacket >> DeleteReason;
}

void MailTakeItem::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
    _worldPacket >> AttachID;
}

void MailTakeMoney::Read()
{
    _worldPacket >> Mailbox;
    _worldPacket >> MailID;
    _worldPacket >> Money;
}

MailQueryNextTimeResult::MailNextTimeEntry::MailNextTimeEntry(::Mail const* mail)
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
        case MAIL_BLACKMARKET:
        case MAIL_COMMERCE_AUCTION:
        case MAIL_AUCTION_2:
        case MAIL_ARTISANS_CONSORTIUM:
            AltSenderID = mail->sender;
            break;
        default:
            break;
    }

    TimeLeft = mail->deliver_time - GameTime::GetGameTime();
    AltSenderType = mail->messageType;
    StationeryID = mail->stationery;
}

WorldPacket const* MailQueryNextTimeResult::Write()
{
    _worldPacket << float(NextMailTime);
    _worldPacket << Size<int32>(Next);

    for (MailNextTimeEntry const& entry : Next)
    {
        _worldPacket << entry.SenderGuid;
        _worldPacket << float(entry.TimeLeft);
        _worldPacket << int32(entry.AltSenderID);
        _worldPacket << int32(entry.AltSenderType);
        _worldPacket << int32(entry.StationeryID);
    }

    return &_worldPacket;
}

WorldPacket const* NotifyReceivedMail::Write()
{
    _worldPacket << float(Delay);

    return &_worldPacket;
}
}
