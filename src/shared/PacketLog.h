/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITYCORE_PACKETLOG_H
#define TRINITYCORE_PACKETLOG_H

#include "Common.h"
#include "Policies/Singleton.h"
#include "RealmPacket.h"
#include "WorldPacket.h"

class PacketLog
{
    public:
        PacketLog();
        ~PacketLog();

        int hextoint(char c);
        char makehexchar(int i);

        void HexDump(const unsigned char* data, size_t length, const char* file);
        void HexDump(const char *data, size_t length, const char* file);
        void HexDumpStr(const char *msg, const char *data, size_t len, const char* file);

        void RealmHexDump(RealmPacket * data, uint32 socket, bool direction);

        void WorldHexDump(WorldPacket * data, uint32 socket, bool direction);
};

#define sPacketLog Trinity::Singleton<PacketLog>::Instance()
#endif

