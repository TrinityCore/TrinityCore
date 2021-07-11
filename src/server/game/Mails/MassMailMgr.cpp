/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/**
 * @addtogroup mailing
 * @{
 *
 * @file MassMailMgr.cpp
 * This file contains the the code needed for MaNGOS to handle mass mails send in safe and perfomence not affecting way.
 *
 */

#include "MassMailMgr.h"
#include "Policies/SingletonImp.h"
#include "Database/DatabaseEnv.h"
#include "Database/DatabaseImpl.h"
#include "SharedDefines.h"
#include "World.h"
#include "ObjectMgr.h"

INSTANTIATE_SINGLETON_1(MassMailMgr);

void MassMailMgr::AddMassMailTask(MailDraft* mailProto, MailSender const& sender, uint32 raceMask)
{
    if (RACEMASK_ALL_PLAYABLE & ~raceMask)                  // have races not included in mask
    {
        std::ostringstream ss;
        ss << "SELECT `guid` FROM `characters` WHERE (1 << (`race` - 1)) & " << raceMask << " AND `deleted_time` IS NULL";
        AddMassMailTask(mailProto, sender, ss.str().c_str());
    }
    else
        AddMassMailTask(mailProto, sender, "SELECT `guid` FROM `characters` WHERE `deleted_time` IS NULL");
}

struct MassMailerQueryHandler
{
    void HandleQueryCallback(QueryResult* result, MailDraft* mailProto, MailSender sender)
    {
        if (!result)
            return;

        MassMailMgr::ReceiversList& recievers = sMassMailMgr.AddMassMailTask(mailProto, sender);

        do
        {
            Field* fields = result->Fetch();
            recievers.insert(fields[0].GetUInt32());

        }
        while (result->NextRow());
        delete result;
    }
} massMailerQueryHandler;

void MassMailMgr::AddMassMailTask(MailDraft* mailProto, MailSender const& sender, char const* query)
{
    CharacterDatabase.AsyncPQuery(&massMailerQueryHandler, &MassMailerQueryHandler::HandleQueryCallback, mailProto, sender, query);
}

void MassMailMgr::Update(bool sendall /*= false*/)
{
    if (m_massMails.empty())
        return;

    uint32 maxcount = sWorld.getConfig(CONFIG_UINT32_MASS_MAILER_SEND_PER_TICK);

    do
    {
        MassMail& task = m_massMails.front();

        while (!task.m_receivers.empty() && (sendall || maxcount > 0))
        {
            uint32 receiver_lowguid = *task.m_receivers.begin();
            task.m_receivers.erase(task.m_receivers.begin());

            ObjectGuid receiver_guid = ObjectGuid(HIGHGUID_PLAYER, receiver_lowguid);
            Player* receiver = sObjectMgr.GetPlayer(receiver_guid);

            // last case. can be just send
            if (task.m_receivers.empty())
            {
                // prevent mail return
                task.m_protoMail->SendMailTo(MailReceiver(receiver, receiver_guid), task.m_sender, MAIL_CHECK_MASK_RETURNED);

                if (!sendall)
                    --maxcount;
                break;
            }

            // need clone draft
            MailDraft draft;
            draft.CloneFrom(*task.m_protoMail);

            // prevent mail return
            draft.SendMailTo(MailReceiver(receiver, receiver_guid), task.m_sender, MAIL_CHECK_MASK_RETURNED);

            if (!sendall)
                --maxcount;
        }

        if (task.m_receivers.empty())
            m_massMails.pop_front();
    }
    while (!m_massMails.empty() && (sendall || maxcount > 0));
}

void MassMailMgr::GetStatistic(uint32& tasks, uint32& mails, uint32& needTime) const
{
    tasks = m_massMails.size();

    uint32 mailsCount = 0;
    for (const auto& itr : m_massMails)
        mailsCount += itr.m_receivers.size();

    mails = mailsCount;

    // 50 msecs is tick length
    needTime = 50 * mailsCount / sWorld.getConfig(CONFIG_UINT32_MASS_MAILER_SEND_PER_TICK) / IN_MILLISECONDS;
}


/*! @} */
