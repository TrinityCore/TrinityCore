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

#ifndef BNetRealmList_h__
#define BNetRealmList_h__

#include "Define.h"
#include "Realm.h"
#include <map>
#include <vector>
#include <unordered_set>

class WorldListener;

namespace boost
{
    namespace system
    {
        class error_code;
    }
}

/// Storage object for the list of realms on the server
class BNetRealmList
{
    public:
        typedef std::map<Battlenet::RealmHandle, Realm> RealmMap;

        static BNetRealmList* Instance();

        ~BNetRealmList();

        void Initialize(Trinity::Asio::IoContext& ioContext, uint32 updateInterval, uint16 worldListenPort);
        void Close();

        RealmMap const& GetRealms() const { return _realms; }
        Realm const* GetRealm(Battlenet::RealmHandle const& id) const;

    private:
        BNetRealmList();

        void UpdateRealms(boost::system::error_code const& error);
        void UpdateRealm(Battlenet::RealmHandle const& id, uint32 build, std::string const& name,
            boost::asio::ip::address&& address, boost::asio::ip::address&& localAddr, boost::asio::ip::address&& localSubmask,
            uint16 port, uint8 icon, RealmFlags flag, uint8 timezone, AccountTypes allowedSecurityLevel, float population);

        RealmMap _realms;
        uint32 _updateInterval;
        std::unique_ptr<Trinity::Asio::DeadlineTimer> _updateTimer;
        std::unique_ptr<Trinity::Asio::Resolver> _resolver;
        std::unique_ptr<WorldListener> _worldListener;
};

#define sBNetRealmList BNetRealmList::Instance()

#endif // BNetRealmList_h__
