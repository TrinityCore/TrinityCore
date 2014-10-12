/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef PacketManager_h__
#define PacketManager_h__

#include "Packets.h"
#include <map>
#include <type_traits>

template<typename T>
struct has_call_handler
{
    template<typename U, void(U::*)(Battlenet::Session*)> struct test_has_call_handler { };
    template<typename U> static char Test(test_has_call_handler<U, &U::CallHandler>*);
    template<typename U> static int Test(...);
    static const bool value = sizeof(Test<T>(nullptr)) == sizeof(char);
};

namespace Battlenet
{
    class PacketManager
    {
        typedef ClientPacket*(*PacketCreateFn)(PacketHeader const& header, BitStream& stream);

        struct PacketInfo 
        {
            PacketCreateFn Constructor;
            char const* Name;
            bool HasHandler;
        };

        PacketManager();

        void RegisterAuthenticationPackets();
        void RegisterConnectionPackets();
        void RegisterWoWRealmPackets();
        void RegisterFriendsPackets();
        void RegisterPresencePackets();
        void RegisterChatPackets();
        void RegisterSupportPackets();
        void RegisterAchievementPackets();
        void RegisterCachePackets();
        void RegisterProfilePackets();

        template<class PacketType>
        static ClientPacket* New(PacketHeader const& header, BitStream& stream)
        {
            return new PacketType(header, stream);
        }

        void RegisterPacketName(std::map<PacketHeader, PacketInfo>& packetTable, PacketHeader const& header, char const* name)
        {
            PacketInfo& info = packetTable[header];
            info.Constructor = nullptr;
            info.Name = name;
            info.HasHandler = false;
        }

        template<class PacketType>
        void RegisterClientPacket(PacketHeader const& header, char const* name)
        {
            PacketInfo& info = _clientPacketTable[header];
            info.Constructor = &New<PacketType>;
            info.Name = name;
            info.HasHandler = has_call_handler<PacketType>::value;
        }

    public:
        ClientPacket* CreateClientPacket(PacketHeader const& header, BitStream& stream);

        char const* GetClientPacketName(PacketHeader const& header);
        char const* GetServerPacketName(PacketHeader const& header);

        bool IsHandled(PacketHeader const& header);

        static PacketManager& Instance()
        {
            static PacketManager instance;
            return instance;
        }

    private:
        std::map<PacketHeader, PacketInfo> _clientPacketTable;
        std::map<PacketHeader, PacketInfo> _serverPacketTable;
    };
}

#define sPacketManager Battlenet::PacketManager::Instance()

#endif // PacketManager_h__
