/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "TSMail.h"
#include "Mail.h"
#include "Item.h"

TSMailItemInfo::TSMailItemInfo(MailItemInfo* info)
{
    this->info = info;
}

uint64 TSMailItemInfo::GetGUID()
{
    return info->item_guid;
}

uint32 TSMailItemInfo::GetItemTemplate()
{
    return info->item_template;
}

TSMail::TSMail(Mail* mail)
{
    this->mail = mail;
}

uint32 TSMail::GetID()
{
    return mail->messageID;
}

uint8 TSMail::GetType()
{
    return mail->messageType;
}

uint16 TSMail::GetTemplateID()
{
    return mail->mailTemplateId;
}

uint64 TSMail::GetSender()
{
    return mail->sender;
}

uint64 TSMail::GetReceiver()
{
    return mail->receiver;
}

TSString TSMail::GetSubject()
{
    return TSString(mail->subject);
}

TSString TSMail::GetBody()
{
    return TSString(mail->body);
}

TSArray<TSMailItemInfo> TSMail::GetItems()
{
    TSArray<TSMailItemInfo> arr;
    for(auto& info: mail->items)
    {
        arr.push(TSMailItemInfo(&info));
    }
    return arr;
}

uint32 TSMail::GetItemCount()
{
    return mail->items.size();
}

void TSMail::FilterItems(std::function<bool(TSMailItemInfo)> predicate)
{
    auto it = mail->items.begin();
    while(it != mail->items.end())
    {
        if(!predicate(TSMailItemInfo(&*it)))
        {
            it = mail->items.erase(it);
        }
    }
}

uint16 TSMail::GetState()
{
    return mail->state;
}

uint32 TSMail::GetMoney()
{
    return mail->money;
}

void TSMail::SetMoney(uint32 money)
{
    mail->money = money;
}

uint32 TSMail::GetCOD()
{
    return mail->COD;
}

void TSMail::SetCOD(uint32 cod)
{
    mail->COD = cod;
}

uint32 TSMail::GetChecked()
{
    return mail->checked;
}

void TSMail::SetChecked(uint32 checked)
{
    mail->checked = checked;
}

void TSMail::RemoveAllItems()
{
    mail->items.clear();
}

void TSMail::AddItem(uint32 entry, uint8 count, TSPlayer player)
{
    auto guid = Item::CreateItem(entry,count,player->player)->GetGUID();
    mail->AddItem(guid,entry);
}

void TSMail::SetSender(uint8 type, uint64 guid)
{
    mail->messageType = type;
    mail->sender = ObjectGuid(guid);
}

void TSMail::SetSubject(TSString subject)
{
    mail->subject = subject.std_str();
}

void TSMail::SetBody(TSString body)
{
    mail->body = body.std_str();
}

void TSMail::SetState(uint8 state)
{
    mail->state = MailState(state);
}

TSMailDraft::TSMailDraft(MailDraft* draft)
{
    this->draft = draft;
}

uint16 TSMailDraft::GetTemplateID()
{
    return draft->m_mailTemplateId;
}

TSString TSMailDraft::GetSubject()
{
    return TSString(draft->m_subject);
}

TSString TSMailDraft::GetBody()
{
    return TSString(draft->m_body);
}

uint32 TSMailDraft::GetMoney()
{
    return draft->m_money;
}

uint32 TSMailDraft::GetCOD()
{
    return draft->m_COD;
}

TSArray<uint64> TSMailDraft::GetItemKeys()
{
    TSArray<uint64> arr;
    for(auto& itr : draft->m_items)
    {
        arr.push(itr.first);
    }
    return arr;
}

TSItem TSMailDraft::GetItem(uint64 item)
{
    return draft->m_items[ObjectGuid(item)];
}

void TSMailDraft::SetTemplateID(uint16 id)
{
    draft->m_mailTemplateId = id;
}

void TSMailDraft::SetSubject(TSString subject)
{
    draft->m_subject = subject.std_str();
}

void TSMailDraft::SetBody(TSString body)
{
    draft->m_body = body.std_str();
}

void TSMailDraft::AddItem(uint32 entry, uint8 count, TSPlayer player)
{
    auto item = Item::CreateItem(entry,count,player->player);
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    item->SaveToDB(trans);
    CharacterDatabase.CommitTransaction(trans);
    draft->AddItem(item);
}

void TSMailDraft::FilterItems(std::function<bool(TSItem)> predicate)
{
    auto it = draft->m_items.begin();
    while (it != draft->m_items.end())
    {
        if (!predicate(it->second))
        {
            it = draft->m_items.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
