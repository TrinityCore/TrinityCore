/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef _LOGINDATABASE_H
#define _LOGINDATABASE_H

#include "MySQLConnection.h"

enum LoginDatabaseStatements : uint32
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */

    LOGIN_SEL_REALMLIST,
    LOGIN_DEL_EXPIRED_IP_BANS,
    LOGIN_UPD_EXPIRED_ACCOUNT_BANS,
    LOGIN_SEL_IP_INFO,
    LOGIN_INS_IP_AUTO_BANNED,
    LOGIN_SEL_ACCOUNT_BANNED_ALL,
    LOGIN_SEL_ACCOUNT_BANNED_BY_FILTER,
    LOGIN_SEL_ACCOUNT_BANNED_BY_USERNAME,
    LOGIN_INS_ACCOUNT_AUTO_BANNED,
    LOGIN_DEL_ACCOUNT_BANNED,
    LOGIN_UPD_VS,
    LOGIN_UPD_LOGONPROOF,
    LOGIN_SEL_LOGONCHALLENGE,
    LOGIN_SEL_RECONNECTCHALLENGE,
    LOGIN_UPD_FAILEDLOGINS,
    LOGIN_SEL_ACCOUNT_ID_BY_NAME,
    LOGIN_SEL_ACCOUNT_LIST_BY_NAME,
    LOGIN_SEL_ACCOUNT_INFO_BY_NAME,
    LOGIN_SEL_ACCOUNT_LIST_BY_EMAIL,
    LOGIN_SEL_REALM_CHARACTER_COUNTS,
    LOGIN_SEL_ACCOUNT_BY_IP,
    LOGIN_INS_IP_BANNED,
    LOGIN_DEL_IP_NOT_BANNED,
    LOGIN_SEL_IP_BANNED_ALL,
    LOGIN_SEL_IP_BANNED_BY_IP,
    LOGIN_SEL_ACCOUNT_BY_ID,
    LOGIN_INS_ACCOUNT_BANNED,
    LOGIN_UPD_ACCOUNT_NOT_BANNED,
    LOGIN_DEL_REALM_CHARACTERS_BY_REALM,
    LOGIN_DEL_REALM_CHARACTERS,
    LOGIN_INS_REALM_CHARACTERS,
    LOGIN_SEL_SUM_REALM_CHARACTERS,
    LOGIN_INS_ACCOUNT,
    LOGIN_INS_REALM_CHARACTERS_INIT,
    LOGIN_UPD_EXPANSION,
    LOGIN_UPD_ACCOUNT_LOCK,
    LOGIN_UPD_ACCOUNT_LOCK_COUNTRY,
    LOGIN_INS_LOG,
    LOGIN_UPD_USERNAME,
    LOGIN_UPD_PASSWORD,
    LOGIN_UPD_EMAIL,
    LOGIN_UPD_REG_EMAIL,
    LOGIN_UPD_MUTE_TIME,
    LOGIN_UPD_MUTE_TIME_LOGIN,
    LOGIN_UPD_LAST_IP,
    LOGIN_UPD_LAST_ATTEMPT_IP,
    LOGIN_UPD_ACCOUNT_ONLINE,
    LOGIN_UPD_UPTIME_PLAYERS,
    LOGIN_DEL_OLD_LOGS,
    LOGIN_DEL_ACCOUNT_ACCESS,
    LOGIN_DEL_ACCOUNT_ACCESS_BY_REALM,
    LOGIN_INS_ACCOUNT_ACCESS,
    LOGIN_GET_ACCOUNT_ID_BY_USERNAME,
    LOGIN_GET_ACCOUNT_ACCESS_GMLEVEL,
    LOGIN_GET_GMLEVEL_BY_REALMID,
    LOGIN_GET_USERNAME_BY_ID,
    LOGIN_SEL_CHECK_PASSWORD,
    LOGIN_SEL_CHECK_PASSWORD_BY_NAME,
    LOGIN_SEL_PINFO,
    LOGIN_SEL_PINFO_BANS,
    LOGIN_SEL_GM_ACCOUNTS,
    LOGIN_SEL_ACCOUNT_INFO,
    LOGIN_SEL_ACCOUNT_ACCESS_GMLEVEL_TEST,
    LOGIN_SEL_ACCOUNT_ACCESS,
    LOGIN_SEL_ACCOUNT_WHOIS,
    LOGIN_SEL_REALMLIST_SECURITY_LEVEL,
    LOGIN_DEL_ACCOUNT,
    LOGIN_SEL_AUTOBROADCAST,
    LOGIN_SEL_LAST_ATTEMPT_IP,
    LOGIN_SEL_LAST_IP,
    LOGIN_GET_EMAIL_BY_ID,
    LOGIN_INS_ALDL_IP_LOGGING,
    LOGIN_INS_FACL_IP_LOGGING,
    LOGIN_INS_CHAR_IP_LOGGING,
    LOGIN_INS_FALP_IP_LOGGING,

    LOGIN_SEL_ACCOUNT_ACCESS_BY_ID,
    LOGIN_SEL_RBAC_ACCOUNT_PERMISSIONS,
    LOGIN_INS_RBAC_ACCOUNT_PERMISSION,
    LOGIN_DEL_RBAC_ACCOUNT_PERMISSION,

    LOGIN_INS_ACCOUNT_MUTE,
    LOGIN_SEL_ACCOUNT_MUTE_INFO,
    LOGIN_DEL_ACCOUNT_MUTED,

    LOGIN_SEL_SECRET_DIGEST,
    LOGIN_INS_SECRET_DIGEST,
    LOGIN_DEL_SECRET_DIGEST,

    LOGIN_SEL_ACCOUNT_TOTP_SECRET,
    LOGIN_UPD_ACCOUNT_TOTP_SECRET,

    MAX_LOGINDATABASE_STATEMENTS
};

class TC_DATABASE_API LoginDatabaseConnection : public MySQLConnection
{
public:
    typedef LoginDatabaseStatements Statements;

    //- Constructors for sync and async connections
    LoginDatabaseConnection(MySQLConnectionInfo& connInfo);
    LoginDatabaseConnection(ProducerConsumerQueue<SQLOperation*>* q, MySQLConnectionInfo& connInfo);
    ~LoginDatabaseConnection();

    //- Loads database type specific prepared statements
    void DoPrepareStatements() override;
};

#endif
