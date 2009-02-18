/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

#include "Tools.h"

// THIS CAN BE A LOT FASTER
bool readGUID(WorldPacket & data, uint64& guid)
{
    if(data.rpos()+1 > data.size())
        return false;

    uint8 guidmark=0;
    uint8 bit;
    uint8 shiftdata=0x1;
    uint64 Temp=0;

    guid = 0;

    data >> guidmark;
    for(int i=0;i<8;i++)
    {
        if(guidmark & shiftdata)
        {
            Temp = 0;

            if(data.rpos()+1 > data.size())
                return false;

            data >> bit;
            Temp = bit;
            Temp <<= i*8;
            guid |= Temp;
        }
        shiftdata=shiftdata<<1;
    }

    return true;
}

void  writeGUID(WorldPacket & data, uint64 & guid)
{
    uint8 RAWmask = 0;
    uint8 PackedGuid[8] = {0,0,0,0,0,0,0,0};

    int j = 1;
    uint8 * test = (uint8*)&guid;

    if (*test)
    {
        PackedGuid[j] = *test;
        RAWmask |= 1;
        ++j;
    }
    if (*(test+1))
    {
        PackedGuid[j] = *(test+1);
        RAWmask |= 2;
        ++j;
    }
    if (*(test+2))
    {
        PackedGuid[j] = *(test+2);
        RAWmask |= 4;
        ++j;
    }
    if (*(test+3))
    {
        PackedGuid[j] = *(test+3);
        RAWmask |= 8;
        ++j;
    }
    if (*(test+4))
    {
        PackedGuid[j] = *(test+4);
        RAWmask |= 16;
        ++j;
    }
    if (*(test+5))
    {
        PackedGuid[j] = *(test+5);
        RAWmask |= 32;
        ++j;
    }
    if (*(test+6))
    {
        PackedGuid[j] = *(test+6);
        RAWmask |= 64;
        ++j;
    }
    if (*(test+7))
    {
        PackedGuid[j] = *(test+7);
        RAWmask |= 128;
        ++j;
    }
    PackedGuid[0] = RAWmask;

    data.append(PackedGuid,j);
}

