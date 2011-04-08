/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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

#ifndef _PROTOCOL_H
#define _PROTOCOL_H

enum eWardendOpcode
{
    MMSG_PING                       = 0x01,
    WMSG_PONG                       = 0x02,
    MMSG_LOAD_MODULE                = 0x03,
    //  uint32  moduleLen;
    //  uint32  accountId;
    //  uint8   module[moduleLen];
    //  uint8   sessionKey[40];
    //  uint8   clientPacket[17];
    WMSG_WARDEN_KEYS                = 0x04,
    //  uint32  accountId;
    //  uint8   serverKey[258];
    //  uint8   clientKey[258];
    //  uint8   seed[16];
};

enum eWardenServerCmd
{
    WARDS_MODULE_INFO               = 0x00,
    WARDS_MODULE_CHUNK              = 0x01,
    WARDS_CHEAT_CHECK               = 0x02,
    WARDS_DATA                      = 0x03,

    WARDS_SEED                      = 0x05
};

enum eWardenClientCmd
{
    WARDC_MODULE_LOAD_FAILED        = 0x00,
    WARDC_MODULE_LOADED             = 0x01,
    WARDC_CHEAT_CHECK_RESULT        = 0x02,

    WARDC_TRANSFORMED_SEED          = 0x04
};

enum eWardenCheckType
{
    WARD_CHECK_MEMORY               = 0,
    WARD_CHECK_PAGE1                = 1,
    WARD_CHECK_PAGE2                = 2,
    WARD_CHECK_FILE                 = 3,
    WARD_CHECK_LUA                  = 4,
    WARD_CHECK_DRIVER               = 5,
    WARD_CHECK_TIMING               = 6,
    WARD_CHECK_PROCESS              = 7,
    WARD_CHECK_MODULE               = 8,
    WARD_CHECK_END                  = 9
};

#define WARDEND_SIGN "GuardM"
#endif