/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

enum AuthResult
{
    WOW_SUCCESS                     = 0x00,
    WOW_FAIL_UNKNOWN0               = 0x01,                 ///< ? Unable to connect
    WOW_FAIL_UNKNOWN1               = 0x02,                 ///< ? Unable to connect
    WOW_FAIL_BANNED                 = 0x03,                 ///< This <game> account has been closed and is no longer available for use. Please go to <site>/banned.html for further information.
    WOW_FAIL_UNKNOWN_ACCOUNT        = 0x04,                 ///< The information you have entered is not valid. Please check the spelling of the account name and password. If you need help in retrieving a lost or stolen password, see <site> for more information
    WOW_FAIL_INCORRECT_PASSWORD     = 0x05,                 ///< The information you have entered is not valid. Please check the spelling of the account name and password. If you need help in retrieving a lost or stolen password, see <site> for more information
    WOW_FAIL_ALREADY_ONLINE         = 0x06,                 ///< This account is already logged into <game>. Please check the spelling and try again.
    WOW_FAIL_NO_TIME                = 0x07,                 ///< You have used up your prepaid time for this account. Please purchase more to continue playing
    WOW_FAIL_DB_BUSY                = 0x08,                 ///< Could not log in to <game> at this time. Please try again later.
    WOW_FAIL_VERSION_INVALID        = 0x09,                 ///< Unable to validate game version. This may be caused by file corruption or interference of another program. Please visit <site> for more information and possible solutions to this issue.
    WOW_FAIL_VERSION_UPDATE         = 0x0A,                 ///< Downloading
    WOW_FAIL_INVALID_SERVER         = 0x0B,                 ///< Unable to connect
    WOW_FAIL_SUSPENDED              = 0x0C,                 ///< This <game> account has been temporarily suspended. Please go to <site>/banned.html for further information
    WOW_FAIL_FAIL_NOACCESS          = 0x0D,                 ///< Unable to connect
    WOW_SUCCESS_SURVEY              = 0x0E,                 ///< Connected.
    WOW_FAIL_PARENTCONTROL          = 0x0F,                 ///< Access to this account has been blocked by parental controls. Your settings may be changed in your account preferences at <site>
    WOW_FAIL_LOCKED_ENFORCED        = 0x10,                 ///< You have applied a lock to your account. You can change your locked status by calling your account lock phone number.
    WOW_FAIL_TRIAL_ENDED            = 0x11,                 ///< Your trial subscription has expired. Please visit <site> to upgrade your account.
    WOW_FAIL_USE_BATTLENET          = 0x12,                 ///< WOW_FAIL_OTHER This account is now attached to a Battle.net account. Please login with your Battle.net account email address and password.
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
//3.3.0a build 11159
//3.3.2 build 11403
//3.3.3a build 11723

#define POST_BC_ACCEPTED_CLIENT_BUILD                 {12213, 11723, 11403, 11159, 10571, 10505, 10146, 9947, 8606, 0}
#define PRE_BC_ACCEPTED_CLIENT_BUILD                  {5875, 6005, 0}

#define POST_BC_EXP_FLAG                              0x2
#define PRE_BC_EXP_FLAG                               0x1
#define NO_VALID_EXP_FLAG                             0x0

namespace AuthHelper
{
    bool IsAcceptedClientBuild(int build);
    bool IsPostBCAcceptedClientBuild(int build);
    bool IsPreBCAcceptedClientBuild(int build);
};

#endif
