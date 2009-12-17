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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/** \file
    \ingroup realmd
*/

#ifndef _AUTHCODES_H
#define _AUTHCODES_H

enum eAuthResults
{
    REALM_AUTH_SUCCESS              = 0x00,
    REALM_AUTH_FAILURE              = 0x01,                 ///< Unable to connect
    REALM_AUTH_UNKNOWN1             = 0x02,                 ///< Unable to connect
    REALM_AUTH_ACCOUNT_BANNED       = 0x03,                 ///< This <game> account has been closed and is no longer available for use. Please go to <site>/banned.html for further information.
    REALM_AUTH_NO_MATCH             = 0x04,                 ///< The information you have entered is not valid. Please check the spelling of the account name and password. If you need help in retrieving a lost or stolen password, see <site> for more information
    REALM_AUTH_UNKNOWN2             = 0x05,                 ///< The information you have entered is not valid. Please check the spelling of the account name and password. If you need help in retrieving a lost or stolen password, see <site> for more information
    REALM_AUTH_ACCOUNT_IN_USE       = 0x06,                 ///< This account is already logged into <game>. Please check the spelling and try again.
    REALM_AUTH_PREPAID_TIME_LIMIT   = 0x07,                 ///< You have used up your prepaid time for this account. Please purchase more to continue playing
    REALM_AUTH_SERVER_FULL          = 0x08,                 ///< Could not log in to <game> at this time. Please try again later.
    REALM_AUTH_WRONG_BUILD_NUMBER   = 0x09,                 ///< Unable to validate game version. This may be caused by file corruption or interference of another program. Please visit <site> for more information and possible solutions to this issue.
    REALM_AUTH_UPDATE_CLIENT        = 0x0a,                 ///< Downloading
    REALM_AUTH_UNKNOWN3             = 0x0b,                 ///< Unable to connect
    REALM_AUTH_ACCOUNT_FREEZED      = 0x0c,                 ///< This <game> account has been temporarily suspended. Please go to <site>/banned.html for further information
    REALM_AUTH_UNKNOWN4             = 0x0d,                 ///< Unable to connect
    REALM_AUTH_UNKNOWN5             = 0x0e,                 ///< Connected.
    REALM_AUTH_PARENTAL_CONTROL     = 0x0f                  ///< Access to this account has been blocked by parental controls. Your settings may be changed in your account preferences at <site>
};

enum LoginResult
{
    LOGIN_OK                = 0x00,
    LOGIN_FAILED            = 0x01,
    LOGIN_FAILED2           = 0x02,
    LOGIN_BANNED            = 0x03,
    LOGIN_UNKNOWN_ACCOUNT   = 0x04,
    LOGIN_UNKNOWN_ACCOUNT3  = 0x05,
    LOGIN_ALREADYONLINE     = 0x06,
    LOGIN_NOTIME            = 0x07,
    LOGIN_DBBUSY            = 0x08,
    LOGIN_BADVERSION        = 0x09,
    LOGIN_DOWNLOAD_FILE     = 0x0A,
    LOGIN_FAILED3           = 0x0B,
    LOGIN_SUSPENDED         = 0x0C,
    LOGIN_FAILED4           = 0x0D,
    LOGIN_CONNECTED         = 0x0E,
    LOGIN_PARENTALCONTROL   = 0x0F,
    LOGIN_LOCKED_ENFORCED   = 0x10,
};

//multirealm supported versions:
//1.12.1 build 5875
//1.12.2 build 6005
//2.4.3 build 8606
//3.1.3 build 9947
//3.1.3 build 10146 Chinese build
//3.2.2a build 10505

#define EXPECTED_TRINITY_CLIENT_BUILD        {10505, 10146, 9947, 8606, 5875, 6005, 0}

#endif
