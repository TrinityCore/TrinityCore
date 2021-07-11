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
 * @addtogroup mailing The mail system
 * The mailing system in MaNGOS consists of mostly 4 files:
 * - Mail.h
 * - Mail.cpp
 * - MassMailMgr.h
 * - MassMailMgr.cpp
 *
 * @{
 *
 * @file MassMailMgr.h
 * This file contains the the headers needed for MaNGOS to handle mass mails send in safe and perfomence not affecting way.
 *
 */

#ifndef MANGOS_MASS_MAIL_MGR_H
#define MANGOS_MASS_MAIL_MGR_H

#include "Common.h"
#include "Mail.h"
#include "Policies/Singleton.h"

#include <memory>

/**
 * A class to represent the mail send factory to multiple (often all existing) characters.
 *
 * Note: implementation not persistence for server shutdowns
 */
class MassMailMgr
{
    public:                                                 // Constructors
        MassMailMgr() {}

    public:                                                 // Accessors
        void GetStatistic(uint32& tasks, uint32& mails, uint32& needTime) const;

    public:                                                 // modifiers
        typedef std::unordered_set<uint32> ReceiversList;

        /**
         * And new mass mail task for raceMask filter applied to characters list.
         *
         * @param mailProto     prepared mail for clone and send to characters, will deleted in result call.
         * @param raceMask      mask of races that must receive mail.
         *
         * Note: this function safe to be called from Map::Update content/etc, real data add will executed in next tick after query results ready
         */
        void AddMassMailTask(MailDraft* mailProto, MailSender const& sender, uint32 raceMask);

        /**
         * And new mass mail task with SQL query text for fill receivers list.
         *
         * @param mailProto     prepared mail for clone and send to characters, will deleted in result call
         * @param queryStr      SQL query for get guid list of receivers, first field in query result must be uint32 low guids list.
         *
         * Note: this function safe to be called from Map::Update content/etc, real data add will executed in next tick after query results ready
         */
        void AddMassMailTask(MailDraft* mailProto, MailSender const& sender, char const* queryStr);

        /**
         * And new mass mail task and let fill receivers list returned as result.
         *
         * @param mailProto     prepared mail for clone and send to characters, will deleted in result call
         * @returns reference to receivers list for it fill in caller code.
         *
         * Note: this function NOT SAFE for call from Map::Update content/etc
         */
        ReceiversList& AddMassMailTask(MailDraft* mailProto, MailSender const& sender)
        {
            m_massMails.emplace_back(mailProto, sender);
            return m_massMails.rbegin()->m_receivers;
        }

        /**
         * Next step in mass mail activity, send some amount mails from queued tasks
         */
        void Update(bool sendall = false);

    private:

        /// Mass mail task store mail prototype and receivers list who not get mail yet
        struct MassMail
        {
            explicit MassMail(MailDraft* mailProto, MailSender sender)
                : m_protoMail(mailProto), m_sender(sender)
            {
                MANGOS_ASSERT(mailProto);
            }

            MassMail(MassMail const& massmail)
                : m_protoMail(std::move(const_cast<MassMail&>(massmail).m_protoMail)), m_sender(massmail.m_sender)
            {
            }

            /// m_protoMail is owned by MassMail, so at copy original MassMail field set to nullptr
            std::unique_ptr<MailDraft> m_protoMail;

            MailSender m_sender;
            ReceiversList m_receivers;
        };

        typedef std::list<MassMail> MassMailList;

        /// List of current queued mass mail tasks
        MassMailList m_massMails;
};

#define sMassMailMgr MaNGOS::Singleton<MassMailMgr>::Instance()

#endif
/*! @} */
