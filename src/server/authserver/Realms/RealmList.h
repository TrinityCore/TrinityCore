/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef _REALMLIST_H
#define _REALMLIST_H

#include <boost/asio/ip/address.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/io_service.hpp>
#include "Common.h"

using namespace boost::asio;

enum RealmFlags
{
    REALM_FLAG_NONE = 0x00,
    REALM_FLAG_INVALID = 0x01,
    REALM_FLAG_OFFLINE = 0x02,
    REALM_FLAG_SPECIFYBUILD = 0x04,
    REALM_FLAG_UNK1 = 0x08,
    REALM_FLAG_UNK2 = 0x10,
    REALM_FLAG_RECOMMENDED = 0x20,
    REALM_FLAG_NEW = 0x40,
    REALM_FLAG_FULL = 0x80
};

// Storage object for a realm
struct Realm
{
    ip::address ExternalAddress;
    ip::address LocalAddress;
    ip::address LocalSubnetMask;
    uint16 port;
    std::string name;
    uint8 icon;
    RealmFlags flag;
    uint8 timezone;
    uint32 m_ID;
    AccountTypes allowedSecurityLevel;
    float populationLevel;
    uint32 gamebuild;
};

/// Storage object for the list of realms on the server
class RealmList
{
public:
    typedef std::map<std::string, Realm> RealmMap;

    static RealmList* instance()
    {
        static RealmList instance;
        return &instance;
    }

    ~RealmList();

    void Initialize(boost::asio::io_service& ioService, uint32 updateInterval);

    void UpdateIfNeed();

    void AddRealm(const Realm& NewRealm) { m_realms[NewRealm.name] = NewRealm; }

    RealmMap::const_iterator begin() const { return m_realms.begin(); }
    RealmMap::const_iterator end() const { return m_realms.end(); }
    uint32 size() const { return m_realms.size(); }

private:
    RealmList();

    void UpdateRealms(bool init = false);
    void UpdateRealm(uint32 id, const std::string& name, ip::address const& address, ip::address const& localAddr,
        ip::address const& localSubmask, uint16 port, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel, float population, uint32 build);

    RealmMap m_realms;
    uint32   m_UpdateInterval;
    time_t   m_NextUpdateTime;
    boost::asio::ip::tcp::resolver* _resolver;
};

#define sRealmList RealmList::instance()
#endif
