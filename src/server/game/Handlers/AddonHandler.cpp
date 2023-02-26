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

#include "AddonHandler.h"
#include "Database/DatabaseEnv.h"
#include "Opcodes.h"
#include "WorldPacket.h"
#include "Log.h"
#include "Policies/SingletonImp.h"
#include "zlib.h"

INSTANTIATE_SINGLETON_1(AddonHandler);

AddonHandler::AddonHandler()
{
}

AddonHandler::~AddonHandler()
{
}

bool AddonHandler::BuildAddonPacket(WorldPacket* Source, WorldPacket* Target)
{
    ByteBuffer AddOnPacked;
    uLongf AddonRealSize;
    uint32 CurrentPosition;
    uint32 TempValue;

    // broken addon packet, can't be received from real client
    if (Source->rpos() + 4 > Source->size())
        return false;

    *Source >> TempValue;                                   // get real size of the packed structure

    // empty addon packet, nothing process, can't be received from real client
    if (!TempValue)
        return false;

    if (TempValue > 0xFFFFF)
    {
        sLog.outError("WorldSession::ReadAddonsInfo addon info too big, size %u", TempValue);
        return false;
    }

    AddonRealSize = TempValue;                              // temp value because ZLIB only excepts uLongf

    CurrentPosition = Source->rpos();                       // get the position of the pointer in the structure

    AddOnPacked.resize(AddonRealSize);                      // resize target for zlib action

    if (!uncompress(const_cast<uint8*>(AddOnPacked.contents()), &AddonRealSize, const_cast<uint8*>((*Source).contents() + CurrentPosition), (*Source).size() - CurrentPosition) != Z_OK)
    {
        Target->Initialize(SMSG_ADDON_INFO);

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2

        unsigned char tdata[256] =
        {
            0xC3, 0x5B, 0x50, 0x84, 0xB9, 0x3E, 0x32, 0x42, 0x8C, 0xD0, 0xC7, 0x48, 0xFA, 0x0E, 0x5D, 0x54,
            0x5A, 0xA3, 0x0E, 0x14, 0xBA, 0x9E, 0x0D, 0xB9, 0x5D, 0x8B, 0xEE, 0xB6, 0x84, 0x93, 0x45, 0x75,
            0xFF, 0x31, 0xFE, 0x2F, 0x64, 0x3F, 0x3D, 0x6D, 0x07, 0xD9, 0x44, 0x9B, 0x40, 0x85, 0x59, 0x34,
            0x4E, 0x10, 0xE1, 0xE7, 0x43, 0x69, 0xEF, 0x7C, 0x16, 0xFC, 0xB4, 0xED, 0x1B, 0x95, 0x28, 0xA8,
            0x23, 0x76, 0x51, 0x31, 0x57, 0x30, 0x2B, 0x79, 0x08, 0x50, 0x10, 0x1C, 0x4A, 0x1A, 0x2C, 0xC8,
            0x8B, 0x8F, 0x05, 0x2D, 0x22, 0x3D, 0xDB, 0x5A, 0x24, 0x7A, 0x0F, 0x13, 0x50, 0x37, 0x8F, 0x5A,
            0xCC, 0x9E, 0x04, 0x44, 0x0E, 0x87, 0x01, 0xD4, 0xA3, 0x15, 0x94, 0x16, 0x34, 0xC6, 0xC2, 0xC3,
            0xFB, 0x49, 0xFE, 0xE1, 0xF9, 0xDA, 0x8C, 0x50, 0x3C, 0xBE, 0x2C, 0xBB, 0x57, 0xED, 0x46, 0xB9,
            0xAD, 0x8B, 0xC6, 0xDF, 0x0E, 0xD6, 0x0F, 0xBE, 0x80, 0xB3, 0x8B, 0x1E, 0x77, 0xCF, 0xAD, 0x22,
            0xCF, 0xB7, 0x4B, 0xCF, 0xFB, 0xF0, 0x6B, 0x11, 0x45, 0x2D, 0x7A, 0x81, 0x18, 0xF2, 0x92, 0x7E,
            0x98, 0x56, 0x5D, 0x5E, 0x69, 0x72, 0x0A, 0x0D, 0x03, 0x0A, 0x85, 0xA2, 0x85, 0x9C, 0xCB, 0xFB,
            0x56, 0x6E, 0x8F, 0x44, 0xBB, 0x8F, 0x02, 0x22, 0x68, 0x63, 0x97, 0xBC, 0x85, 0xBA, 0xA8, 0xF7,
            0xB5, 0x40, 0x68, 0x3C, 0x77, 0x86, 0x6F, 0x4B, 0xD7, 0x88, 0xCA, 0x8A, 0xD7, 0xCE, 0x36, 0xF0,
            0x45, 0x6E, 0xD5, 0x64, 0x79, 0x0F, 0x17, 0xFC, 0x64, 0xDD, 0x10, 0x6F, 0xF3, 0xF5, 0xE0, 0xA6,
            0xC3, 0xFB, 0x1B, 0x8C, 0x29, 0xEF, 0x8E, 0xE5, 0x34, 0xCB, 0xD1, 0x2A, 0xCE, 0x79, 0xC3, 0x9A,
            0x0D, 0x36, 0xEA, 0x01, 0xE0, 0xAA, 0x91, 0x20, 0x54, 0xF0, 0x72, 0xD8, 0x1E, 0xC7, 0x89, 0xD2
        };
        while (AddOnPacked.rpos() < AddOnPacked.size())
        {
            std::string AddonNames;
            uint8 unk6;
            uint32 crc, unk7;

            AddOnPacked >> AddonNames;

            AddOnPacked >> crc >> unk7 >> unk6;

            //DEBUG_LOG("ADDON: Name:%s CRC:%x Unknown1 :%x Unknown2 :%x", AddonNames.c_str(), crc, unk7, unk6);

            *Target << (uint8)2;

            uint8 unk1 = 1;
            *Target << (uint8)unk1;
            if (unk1)
            {
                uint8 unk2 = crc != UI64LIT(0x1c776d01);           //If addon is Standard addon CRC
                *Target << (uint8)unk2;
                if (unk2)
                    Target->append(tdata, sizeof(tdata));

                *Target << (uint32)0;
            }

            uint8 unk3 = 0;
            *Target << (uint8)unk3;
            if (unk3)
            {
                // String, 256
            }
        }
#else
        uint32 Unknown1;
        uint8 Unknown0;

        AddOnPacked >> Unknown0;
        AddOnPacked >> Unknown1;
        while (AddOnPacked.rpos() < AddOnPacked.size())
        {
            std::string AddonNames;
            uint8 unk6;
            uint64 crc;

            AddOnPacked >> AddonNames;

            AddOnPacked >> crc >> unk6;

            //DEBUG_LOG("ADDON: Name:%s CRC:%llx Unknown1 :%x", AddonNames.c_str(), crc, unk6);

            if (crc == 0x4C1C776D01LL)  // standard addon CRC
            {
                *Target << uint8(0) << uint8(2) << uint8(1) << uint8(0) << uint32(0);
            }
            else // if addon is custom
            {
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
                *Target << uint8(0x00) << uint8(0x01) << uint8(0x00) << uint8(0x01);
#else
                *Target << uint8(0x00) << uint8(0x0) << uint8(0x00) << uint8(0x0);
#endif
            }
        }
#endif
    }
    else
    {
        sLog.outError("Addon packet uncompress error :(");
        return false;
    }
    return true;
}
