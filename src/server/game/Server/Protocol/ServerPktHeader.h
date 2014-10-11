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

#ifndef __SERVERPKTHDR_H__
#define __SERVERPKTHDR_H__

#include "Log.h"
#include "WorldPacket.h"

#pragma pack(push, 1)

struct ServerPktHeader
{
    /**
     * size is the length of the payload _plus_ the length of the opcode
     */
    ServerPktHeader(uint32 size, uint32 cmd, WorldPacketCrypt* authCrypt = nullptr) : size(size), isBigHeader(false)
    {
        if (authCrypt && authCrypt->IsInitialized())
        {
            uint32 data =  (size << 13) | cmd & MAX_OPCODE;
            memcpy(header, &data, 4);
            authCrypt->EncryptSend(header, getHeaderLength());
        }
        else
        {
            // if authCrypt == nullPtr then it's init connection string
            if (authCrypt)
            {
                size += 2;
                memset(&header[4], 0, 2);
                isBigHeader = true;
            }

            memcpy(&header[0], &size, 2);
            memcpy(&header[2], &cmd, 2);
        }
    }

    uint8 getHeaderLength()
    {
        return isBigHeader ? 6 : 4;
    }

    uint8 header[6];
    const uint32 size;
    bool isBigHeader;
};

#pragma pack(pop)

#endif
