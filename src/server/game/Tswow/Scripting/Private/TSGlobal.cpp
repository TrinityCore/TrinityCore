/*
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

#include "TSGlobal.h"
#include "ObjectAccessor.h"
#include "Mail.h"
#include "Item.h"
#include "Player.h"

void SendMail(uint8 senderType, uint64 from, uint64 to, TSString subject, TSString body, uint32 money, uint32 cod, uint32 delay, TSArray<TSItem> items)
{
    auto player = ObjectAccessor::FindPlayer(ObjectGuid(to));
    MailSender sender(MailMessageType(senderType),from);
    MailDraft draft(subject.std_str(),body.std_str());
    draft.AddMoney(money);
    draft.AddCOD(cod);
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    for(int i=0;i<items.get_length();++i)
    {
        auto item = items.get(i);
        item->item->SaveToDB(trans);
        draft.AddItem(item.item);
    }

    draft.SendMailTo(trans,MailReceiver(player,ObjectGuid(to)),sender, MAIL_CHECK_MASK_NONE, delay);
    CharacterDatabase.CommitTransaction(trans);
}