/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "LoginDatabase.h"
#include "PreparedStatement.h"

void LoginDatabaseConnection::DoPrepareStatements()
{
    if (!m_reconnecting)
        m_stmts.resize(MAX_LOGINDATABASE_STATEMENTS);

    PrepareStatement(LOGIN_SEL_REALMLIST, "SELECT id, name, address, localAddress, localSubnetMask, port, icon, flag, timezone, allowedSecurityLevel, population, gamebuild, Region, Battlegroup FROM realmlist WHERE flag <> 3 ORDER BY name", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_DEL_EXPIRED_IP_BANS, "DELETE FROM ip_banned WHERE unbandate<>bandate AND unbandate<=UNIX_TIMESTAMP()", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_EXPIRED_ACCOUNT_BANS, "UPDATE account_banned SET active = 0 WHERE active = 1 AND unbandate<>bandate AND unbandate<=UNIX_TIMESTAMP()", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_IP_INFO, "(SELECT unbandate > UNIX_TIMESTAMP() OR unbandate = bandate AS banned, NULL as country FROM ip_banned WHERE ip = ?) "
        "UNION "
        "(SELECT NULL AS banned, country FROM ip2nation WHERE INET_NTOA(ip) = ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_IP_AUTO_BANNED, "INSERT INTO ip_banned (ip, bandate, unbandate, bannedby, banreason) VALUES (?, UNIX_TIMESTAMP(), UNIX_TIMESTAMP()+?, 'Trinity Auth', 'Failed login autoban')", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_IP_BANNED_ALL, "SELECT ip, bandate, unbandate, bannedby, banreason FROM ip_banned WHERE (bandate = unbandate OR unbandate > UNIX_TIMESTAMP()) ORDER BY unbandate", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_IP_BANNED_BY_IP, "SELECT ip, bandate, unbandate, bannedby, banreason FROM ip_banned WHERE (bandate = unbandate OR unbandate > UNIX_TIMESTAMP()) AND ip LIKE CONCAT('%%', ?, '%%') ORDER BY unbandate", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_BANNED_ALL, "SELECT account.id, username FROM account, account_banned WHERE account.id = account_banned.id AND active = 1 GROUP BY account.id", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_BANNED_BY_USERNAME, "SELECT account.id, username FROM account, account_banned WHERE account.id = account_banned.id AND active = 1 AND username LIKE CONCAT('%%', ?, '%%') GROUP BY account.id", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_DEL_ACCOUNT_BANNED, "DELETE FROM account_banned WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_ACCOUNT_INFO_CONTINUED_SESSION, "UPDATE account SET sessionkey = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_ACCOUNT_INFO_CONTINUED_SESSION, "SELECT username, sessionkey FROM account WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_VS, "UPDATE account SET v = ?, s = ? WHERE username = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_LOGON_COUNTRY, "SELECT country FROM ip2nation WHERE ip < ? ORDER BY ip DESC LIMIT 0,1", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_ID_BY_NAME, "SELECT id FROM account WHERE username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_LIST_BY_NAME, "SELECT id, username FROM account WHERE username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_INFO_BY_NAME, "SELECT a.id, a.sessionkey, ba.last_ip, ba.locked, ba.lock_country, a.expansion, a.mutetime, ba.locale, a.recruiter, a.os, ba.id, aa.gmLevel, "
        "bab.unbandate > UNIX_TIMESTAMP() OR bab.unbandate = bab.bandate, ab.unbandate > UNIX_TIMESTAMP() OR ab.unbandate = ab.bandate, r.id "
        "FROM account a LEFT JOIN account r ON a.id = r.recruiter LEFT JOIN battlenet_accounts ba ON a.battlenet_account = ba.id "
        "LEFT JOIN account_access aa ON a.id = aa.id AND aa.RealmID IN (-1, ?) LEFT JOIN battlenet_account_bans bab ON ba.id = bab.id LEFT JOIN account_banned ab ON a.id = ab.id AND ab.active = 1 "
        "WHERE a.username = ? ORDER BY aa.RealmID DESC LIMIT 1", CONNECTION_ASYNC);

    PrepareStatement(LOGIN_SEL_ACCOUNT_LIST_BY_EMAIL, "SELECT id, username FROM account WHERE email = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_BY_IP, "SELECT id, username FROM account WHERE last_ip = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_BY_ID, "SELECT 1 FROM account WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_INS_IP_BANNED, "INSERT INTO ip_banned (ip, bandate, unbandate, bannedby, banreason) VALUES (?, UNIX_TIMESTAMP(), UNIX_TIMESTAMP()+?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_IP_NOT_BANNED, "DELETE FROM ip_banned WHERE ip = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_ACCOUNT_BANNED, "INSERT INTO account_banned VALUES (?, UNIX_TIMESTAMP(), UNIX_TIMESTAMP()+?, ?, ?, 1)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_ACCOUNT_NOT_BANNED, "UPDATE account_banned SET active = 0 WHERE id = ? AND active != 0", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_REALM_CHARACTERS_BY_REALM, "DELETE FROM realmcharacters WHERE acctid = ? AND realmid = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_REALM_CHARACTERS, "DELETE FROM realmcharacters WHERE acctid = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_REALM_CHARACTERS, "INSERT INTO realmcharacters (numchars, acctid, realmid) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_SUM_REALM_CHARACTERS, "SELECT SUM(numchars) FROM realmcharacters WHERE acctid = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_ACCOUNT, "INSERT INTO account(username, sha_pass_hash, reg_mail, email, joindate, battlenet_account, battlenet_index) VALUES(?, ?, ?, ?, NOW(), ?, ?)", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_INS_REALM_CHARACTERS_INIT, "INSERT INTO realmcharacters (realmid, acctid, numchars) SELECT realmlist.id, account.id, 0 FROM realmlist, account LEFT JOIN realmcharacters ON acctid=account.id WHERE acctid IS NULL", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_EXPANSION, "UPDATE account SET expansion = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_ACCOUNT_LOCK, "UPDATE account SET locked = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_ACCOUNT_LOCK_CONTRY, "UPDATE account SET lock_country = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_LOG, "INSERT INTO logs (time, realm, type, level, string) VALUES (?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_USERNAME, "UPDATE account SET v = 0, s = 0, username = ?, sha_pass_hash = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_PASSWORD, "UPDATE account SET v = 0, s = 0, sha_pass_hash = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_EMAIL, "UPDATE account SET email = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_REG_EMAIL, "UPDATE account SET reg_mail = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_MUTE_TIME, "UPDATE account SET mutetime = ? , mutereason = ? , muteby = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_MUTE_TIME_LOGIN, "UPDATE account SET mutetime = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_LAST_IP, "UPDATE account SET last_ip = ? WHERE username = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_LAST_ATTEMPT_IP, "UPDATE account SET last_attempt_ip = ? WHERE username = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_ACCOUNT_ONLINE, "UPDATE account SET online = 1 WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_UPTIME_PLAYERS, "UPDATE uptime SET uptime = ?, maxplayers = ? WHERE realmid = ? AND starttime = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_OLD_LOGS, "DELETE FROM logs WHERE (time + ?) < ? AND realm = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_ACCOUNT_ACCESS, "DELETE FROM account_access WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_ACCOUNT_ACCESS_BY_REALM, "DELETE FROM account_access WHERE id = ? AND (RealmID = ? OR RealmID = -1)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_ACCOUNT_ACCESS, "INSERT INTO account_access (id,gmlevel,RealmID) VALUES (?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_GET_ACCOUNT_ID_BY_USERNAME, "SELECT id FROM account WHERE username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_GET_ACCOUNT_ACCESS_GMLEVEL, "SELECT gmlevel FROM account_access WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_GET_GMLEVEL_BY_REALMID, "SELECT gmlevel FROM account_access WHERE id = ? AND (RealmID = ? OR RealmID = -1)", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_GET_USERNAME_BY_ID, "SELECT username FROM account WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_CHECK_PASSWORD, "SELECT 1 FROM account WHERE id = ? AND sha_pass_hash = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_CHECK_PASSWORD_BY_NAME, "SELECT 1 FROM account WHERE username = ? AND sha_pass_hash = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_PINFO, "SELECT a.username, aa.gmlevel, a.email, a.reg_mail, a.last_ip, DATE_FORMAT(a.last_login, '%Y-%m-%d %T'), a.mutetime, a.mutereason, a.muteby, a.failed_logins, a.locked, a.OS FROM account a LEFT JOIN account_access aa ON (a.id = aa.id AND (aa.RealmID = ? OR aa.RealmID = -1)) WHERE a.id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_PINFO_BANS, "SELECT unbandate, bandate = unbandate, bannedby, banreason FROM account_banned WHERE id = ? AND active ORDER BY bandate ASC LIMIT 1", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_GM_ACCOUNTS, "SELECT a.username, aa.gmlevel FROM account a, account_access aa WHERE a.id=aa.id AND aa.gmlevel >= ? AND (aa.realmid = -1 OR aa.realmid = ?)", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_INFO, "SELECT a.username, a.last_ip, aa.gmlevel, a.expansion FROM account a LEFT JOIN account_access aa ON (a.id = aa.id) WHERE a.id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_ACCESS_GMLEVEL_TEST, "SELECT 1 FROM account_access WHERE id = ? AND gmlevel > ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_ACCESS, "SELECT a.id, aa.gmlevel, aa.RealmID FROM account a LEFT JOIN account_access aa ON (a.id = aa.id) WHERE a.username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_ACCOUNT_WHOIS, "SELECT username, email, last_ip FROM account WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_LAST_ATTEMPT_IP, "SELECT last_attempt_ip FROM account WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_LAST_IP, "SELECT last_ip FROM account WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_REALMLIST_SECURITY_LEVEL, "SELECT allowedSecurityLevel from realmlist WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_DEL_ACCOUNT, "DELETE FROM account WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_IP2NATION_COUNTRY, "SELECT c.country FROM ip2nationCountries c, ip2nation i WHERE i.ip < ? AND c.code = i.country ORDER BY i.ip DESC LIMIT 0,1", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_AUTOBROADCAST, "SELECT id, weight, text FROM autobroadcast WHERE realmid = ? OR realmid = -1", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_GET_EMAIL_BY_ID, "SELECT email FROM account WHERE id = ?", CONNECTION_SYNCH);
    // 0: uint32, 1: uint32, 2: uint8, 3: uint32, 4: string // Complete name: "Login_Insert_AccountLoginDeLete_IP_Logging"
    PrepareStatement(LOGIN_INS_ALDL_IP_LOGGING, "INSERT INTO logs_ip_actions (account_id,character_guid,type,ip,systemnote,unixtime,time) VALUES (?, ?, ?, (SELECT last_ip FROM account WHERE id = ?), ?, unix_timestamp(NOW()), NOW())", CONNECTION_ASYNC);
    // 0: uint32, 1: uint32, 2: uint8, 3: uint32, 4: string // Complete name: "Login_Insert_FailedAccountLogin_IP_Logging"
    PrepareStatement(LOGIN_INS_FACL_IP_LOGGING, "INSERT INTO logs_ip_actions (account_id,character_guid,type,ip,systemnote,unixtime,time) VALUES (?, ?, ?, (SELECT last_attempt_ip FROM account WHERE id = ?), ?, unix_timestamp(NOW()), NOW())", CONNECTION_ASYNC);
    // 0: uint32, 1: uint32, 2: uint8, 3: string, 4: string // Complete name: "Login_Insert_CharacterDelete_IP_Logging"
    PrepareStatement(LOGIN_INS_CHAR_IP_LOGGING, "INSERT INTO logs_ip_actions (account_id,character_guid,type,ip,systemnote,unixtime,time) VALUES (?, ?, ?, ?, ?, unix_timestamp(NOW()), NOW())", CONNECTION_ASYNC);
    // 0: uint32, 1: string, 2: string                      // Complete name: "Login_Insert_Failed_Account_Login_due_password_IP_Logging"
    PrepareStatement(LOGIN_INS_FALP_IP_LOGGING, "INSERT INTO logs_ip_actions (account_id,character_guid,type,ip,systemnote,unixtime,time) VALUES (?, 0, 1, ?, ?, unix_timestamp(NOW()), NOW())", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_ACCOUNT_ACCESS_BY_ID, "SELECT gmlevel, RealmID FROM account_access WHERE id = ? and (RealmID = ? OR RealmID = -1) ORDER BY gmlevel desc", CONNECTION_SYNCH);

    PrepareStatement(LOGIN_SEL_RBAC_ACCOUNT_PERMISSIONS, "SELECT permissionId, granted FROM rbac_account_permissions WHERE accountId = ? AND (realmId = ? OR realmId = -1) ORDER BY permissionId, realmId", CONNECTION_BOTH);
    PrepareStatement(LOGIN_INS_RBAC_ACCOUNT_PERMISSION, "INSERT INTO rbac_account_permissions (accountId, permissionId, granted, realmId) VALUES (?, ?, ?, ?) ON DUPLICATE KEY UPDATE granted = VALUES(granted)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_RBAC_ACCOUNT_PERMISSION, "DELETE FROM rbac_account_permissions WHERE accountId = ? AND permissionId = ? AND (realmId = ? OR realmId = -1)", CONNECTION_ASYNC);

    PrepareStatement(LOGIN_INS_ACCOUNT_MUTE, "INSERT INTO account_muted VALUES (?, UNIX_TIMESTAMP(), ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_ACCOUNT_MUTE_INFO, "SELECT mutedate, mutetime, mutereason, mutedby FROM account_muted WHERE guid = ? ORDER BY mutedate ASC", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_DEL_ACCOUNT_MUTED, "DELETE FROM account_muted WHERE guid = ?", CONNECTION_ASYNC);

#define BnetAccountInfo "ba.id, UPPER(ba.email), ba.locked, ba.lock_country, ba.last_ip, ba.LoginTicketExpiry, bab.unbandate > UNIX_TIMESTAMP() OR bab.unbandate = bab.bandate, bab.unbandate = bab.bandate"
#define BnetGameAccountInfo "a.id, a.username, ab.unbandate > UNIX_TIMESTAMP() OR ab.unbandate = ab.bandate, ab.unbandate = ab.bandate, aa.gmlevel"

    PrepareStatement(LOGIN_SEL_BNET_AUTHENTICATION, "SELECT ba.id, ba.sha_pass_hash, ba.failed_logins, ba.LoginTicket, ba.LoginTicketExpiry, bab.unbandate > UNIX_TIMESTAMP() OR bab.unbandate = bab.bandate FROM battlenet_accounts ba LEFT JOIN battlenet_account_bans bab ON ba.id = bab.id WHERE email = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_BNET_AUTHENTICATION, "UPDATE battlenet_accounts SET LoginTicket = ?, LoginTicketExpiry = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_BNET_EXISTING_AUTHENTICATION, "SELECT LoginTicketExpiry FROM battlenet_accounts WHERE LoginTicket = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_BNET_EXISTING_AUTHENTICATION, "UPDATE battlenet_accounts SET LoginTicketExpiry = ? WHERE LoginTicket = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_BNET_ACCOUNT_INFO, "SELECT " BnetAccountInfo ", " BnetGameAccountInfo ""
        " FROM battlenet_accounts ba LEFT JOIN battlenet_account_bans bab ON ba.id = bab.id LEFT JOIN account a ON ba.id = a.battlenet_account"
        " LEFT JOIN account_banned ab ON a.id = ab.id AND ab.active = 1 LEFT JOIN account_access aa ON a.id = aa.id AND aa.RealmID = -1 WHERE ba.LoginTicket = ? ORDER BY a.id", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_BNET_LAST_LOGIN_INFO, "UPDATE battlenet_accounts SET last_ip = ?, last_login = NOW(), locale = ?, failed_logins = 0, os = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_BNET_GAME_ACCOUNT_LOGIN_INFO, "UPDATE account SET sessionkey = ?, last_ip = ?, last_login = NOW(), locale = ?, failed_logins = 0, os = ? WHERE username = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_BNET_CHARACTER_COUNTS_BY_ACCOUNT_ID, "SELECT rc.acctid, rc.numchars, r.id, r.Region, r.Battlegroup FROM realmcharacters rc INNER JOIN realmlist r ON rc.realmid = r.id WHERE rc.acctid = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_BNET_CHARACTER_COUNTS_BY_BNET_ID, "SELECT rc.acctid, rc.numchars, r.id, r.Region, r.Battlegroup FROM realmcharacters rc INNER JOIN realmlist r ON rc.realmid = r.id LEFT JOIN account a ON rc.acctid = a.id WHERE a.battlenet_account = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_BNET_LAST_PLAYER_CHARACTERS, "SELECT lpc.accountId, lpc.region, lpc.battlegroup, lpc.realmId, lpc.characterName, lpc.characterGUID, lpc.lastPlayedTime FROM account_last_played_character lpc LEFT JOIN account a ON lpc.accountId = a.id WHERE a.battlenet_account = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_BNET_LAST_PLAYER_CHARACTERS, "DELETE FROM account_last_played_character WHERE accountId = ? AND region = ? AND battlegroup = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_BNET_LAST_PLAYER_CHARACTERS, "INSERT INTO account_last_played_character (accountId, region, battlegroup, realmId, characterName, characterGUID, lastPlayedTime) VALUES (?,?,?,?,?,?,?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_BNET_ACCOUNT, "INSERT INTO battlenet_accounts (`email`,`sha_pass_hash`) VALUES (?, ?)", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_BNET_ACCOUNT_EMAIL_BY_ID, "SELECT email FROM battlenet_accounts WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_BNET_ACCOUNT_ID_BY_EMAIL, "SELECT id FROM battlenet_accounts WHERE email = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_UPD_BNET_PASSWORD, "UPDATE battlenet_accounts SET sha_pass_hash = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_BNET_CHECK_PASSWORD, "SELECT 1 FROM battlenet_accounts WHERE id = ? AND sha_pass_hash = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_UPD_BNET_ACCOUNT_LOCK, "UPDATE battlenet_accounts SET locked = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_BNET_ACCOUNT_LOCK_CONTRY, "UPDATE battlenet_accounts SET lock_country = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_BNET_ACCOUNT_ID_BY_GAME_ACCOUNT, "SELECT battlenet_account FROM account WHERE id = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_UPD_BNET_GAME_ACCOUNT_LINK, "UPDATE account SET battlenet_account = ?, battlenet_index = ? WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_BNET_MAX_ACCOUNT_INDEX, "SELECT MAX(battlenet_index) FROM account WHERE battlenet_account = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_BNET_GAME_ACCOUNT_LIST_SMALL, "SELECT a.id, a.username FROM account a LEFT JOIN battlenet_accounts ba ON a.battlenet_account = ba.id WHERE ba.email = ?", CONNECTION_SYNCH);
    PrepareStatement(LOGIN_SEL_BNET_GAME_ACCOUNT_LIST, "SELECT a.username, a.expansion, ab.bandate, ab.unbandate, ab.banreason FROM account AS a LEFT JOIN account_banned AS ab ON a.id = ab.id AND ab.active = 1 INNER JOIN battlenet_accounts AS ba ON a.battlenet_account = ba.id WHERE ba.LoginTicket = ? ORDER BY a.id", CONNECTION_ASYNC);

    PrepareStatement(LOGIN_UPD_BNET_FAILED_LOGINS, "UPDATE battlenet_accounts SET failed_logins = failed_logins + 1 WHERE id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_BNET_ACCOUNT_AUTO_BANNED, "INSERT INTO battlenet_account_bans(id, bandate, unbandate, bannedby, banreason) VALUES(?, UNIX_TIMESTAMP(), UNIX_TIMESTAMP()+?, 'Trinity Auth', 'Failed login autoban')", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_BNET_EXPIRED_ACCOUNT_BANNED, "DELETE FROM battlenet_account_bans WHERE unbandate<>bandate AND unbandate<=UNIX_TIMESTAMP()", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_BNET_RESET_FAILED_LOGINS, "UPDATE battlenet_accounts SET failed_logins = 0 WHERE id = ?", CONNECTION_ASYNC);

    PrepareStatement(LOGIN_SEL_LAST_CHAR_UNDELETE, "SELECT LastCharacterUndelete FROM battlenet_accounts WHERE Id = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_LAST_CHAR_UNDELETE, "UPDATE battlenet_accounts SET LastCharacterUndelete = UNIX_TIMESTAMP() WHERE Id = ?", CONNECTION_ASYNC);

    // Account wide toys
    PrepareStatement(LOGIN_SEL_ACCOUNT_TOYS, "SELECT itemId, isFavourite FROM battlenet_account_toys WHERE accountId = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_REP_ACCOUNT_TOYS, "REPLACE INTO battlenet_account_toys (accountId, itemId, isFavourite) VALUES (?, ?, ?)", CONNECTION_ASYNC);

    // Battle Pets
    PrepareStatement(LOGIN_SEL_BATTLE_PETS, "SELECT guid, species, breed, level, exp, health, quality, flags, name FROM battle_pets WHERE battlenetAccountId = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_BATTLE_PETS, "INSERT INTO battle_pets (guid, battlenetAccountId, species, breed, level, exp, health, quality, flags, name) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_BATTLE_PETS, "DELETE FROM battle_pets WHERE battlenetAccountId = ? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_UPD_BATTLE_PETS, "UPDATE battle_pets SET level = ?, exp = ?, health = ?, quality = ?, flags = ?, name = ? WHERE battlenetAccountId = ? AND guid = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_BATTLE_PET_SLOTS, "SELECT id, battlePetGuid, locked FROM battle_pet_slots WHERE battlenetAccountId = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_BATTLE_PET_SLOTS, "INSERT INTO battle_pet_slots (id, battlenetAccountId, battlePetGuid, locked) VALUES (?, ?, ?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_BATTLE_PET_SLOTS, "DELETE FROM battle_pet_slots WHERE battlenetAccountId = ?", CONNECTION_ASYNC);

    PrepareStatement(LOGIN_SEL_ACCOUNT_HEIRLOOMS, "SELECT itemId, flags FROM battlenet_account_heirlooms WHERE accountId = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_REP_ACCOUNT_HEIRLOOMS, "REPLACE INTO battlenet_account_heirlooms (accountId, itemId, flags) VALUES (?, ?, ?)", CONNECTION_ASYNC);

    // Account wide mounts
    PrepareStatement(LOGIN_SEL_ACCOUNT_MOUNTS, "SELECT mountSpellId, flags FROM battlenet_account_mounts WHERE battlenetAccountId = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_REP_ACCOUNT_MOUNTS, "REPLACE INTO battlenet_account_mounts (battlenetAccountId, mountSpellId, flags) VALUES (?, ?, ?)", CONNECTION_ASYNC);

    // Transmog collection
    PrepareStatement(LOGIN_SEL_BNET_ITEM_APPEARANCES, "SELECT blobIndex, appearanceMask FROM battlenet_item_appearances WHERE battlenetAccountId = ? ORDER BY blobIndex DESC", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_BNET_ITEM_APPEARANCES, "INSERT INTO battlenet_item_appearances (battlenetAccountId, blobIndex, appearanceMask) VALUES (?, ?, ?) "
        "ON DUPLICATE KEY UPDATE appearanceMask = appearanceMask | VALUES(appearanceMask)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_SEL_BNET_ITEM_FAVORITE_APPEARANCES, "SELECT itemModifiedAppearanceId FROM battlenet_item_favorite_appearances WHERE battlenetAccountId = ?", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_INS_BNET_ITEM_FAVORITE_APPEARANCE, "INSERT INTO battlenet_item_favorite_appearances (battlenetAccountId, itemModifiedAppearanceId) VALUES (?, ?)", CONNECTION_ASYNC);
    PrepareStatement(LOGIN_DEL_BNET_ITEM_FAVORITE_APPEARANCE, "DELETE FROM battlenet_item_favorite_appearances WHERE battlenetAccountId = ? AND itemModifiedAppearanceId = ?", CONNECTION_ASYNC);
}

LoginDatabaseConnection::LoginDatabaseConnection(MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo)
{
}

LoginDatabaseConnection::LoginDatabaseConnection(ProducerConsumerQueue<SQLOperation*>* q, MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo)
{
}

LoginDatabaseConnection::~LoginDatabaseConnection()
{
}
