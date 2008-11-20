/*
 * Copyright (C) 2005-2008 MaNGOS <http://getmangos.com/>
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

#ifndef _GMTICKETMGR_H
#define _GMTICKETMGR_H

#include "Policies/Singleton.h"
#include "Database/DatabaseEnv.h"
#include "Util.h"
#include <map>

class GMTicket
{
    public:
        explicit GMTicket()
        {
        }

        GMTicket(uint32 guid, std::string text, time_t update) : m_guid(guid), m_text(text), m_lastUpdate(update)
        {

        }

        const char* GetText() const
        {
            return m_text.c_str();
        }

        uint64 GetLastUpdate() const
        {
            return m_lastUpdate;
        }

        void SetText(const char* text)
        {
            m_text = text ? text : "";
            m_lastUpdate = time(NULL);

            std::string escapedString = m_text;
            CharacterDatabase.escape_string(escapedString);
            CharacterDatabase.PExecute("UPDATE character_ticket SET ticket_text = '%s' WHERE guid = '%u'", escapedString.c_str(), m_guid);
        }

        void DeleteFromDB() const
        {
            CharacterDatabase.PExecute("DELETE FROM character_ticket WHERE guid = '%u' LIMIT 1", m_guid);
        }

        void SaveToDB() const
        {
            CharacterDatabase.BeginTransaction();
            DeleteFromDB();

            std::string escapedString = m_text;
            CharacterDatabase.escape_string(escapedString);

            CharacterDatabase.PExecute("INSERT INTO character_ticket (guid, ticket_text) VALUES ('%u', '%s')", m_guid, escapedString.c_str());
            CharacterDatabase.CommitTransaction();
        }
    private:
        uint32 m_guid;
        std::string m_text;
        time_t m_lastUpdate;
};
typedef std::map<uint32, GMTicket> GMTicketMap;

class GMTicketMgr
{
    public:
        GMTicketMgr() {  }
        ~GMTicketMgr() {  }

        void LoadGMTickets();

        GMTicket* GetGMTicket(uint32 guid)
        {
            GMTicketMap::iterator itr = m_GMTicketMap.find(guid);
            if(itr == m_GMTicketMap.end())
                return NULL;
            return &(itr->second);
        }

        size_t GetTicketCount() const
        {
            return m_GMTicketMap.size();
        }

        void Delete(uint32 guid)
        {
            GMTicketMap::iterator itr = m_GMTicketMap.find(guid);
            if(itr == m_GMTicketMap.end())
                return;
            itr->second.DeleteFromDB();
            m_GMTicketMap.erase(itr);
        }

        void DeleteAll();

        void Create(uint32 guid, const char* text)
        {
            GMTicket t = GMTicket(guid, text, time(NULL));
            t.SaveToDB();
            m_GMTicketMap[guid] = t;
        }
    private:
        GMTicketMap m_GMTicketMap;
};

#define ticketmgr Trinity::Singleton<GMTicketMgr>::Instance()
#endif
