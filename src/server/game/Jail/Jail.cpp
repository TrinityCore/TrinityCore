// Copyright (C) 2008-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de

#include "Jail.h"

Jail::Jail()
{
}

Jail::~Jail()
{
}

bool Jail::LadeKonfiguration(bool reload)
{
    // Standardkonfiguration initialisieren...
    m_MaxJails = 4;
    m_MaxDauer = 720;   // 30 Tage
    m_MinGrund = 40;
    m_Radius = 10;      // Yards

    m_MapAlly = 0;
    m_MapHorde = 1;

    m_BanDauer = 168;   // 1 Woche

    m_AllyPosX = -8673.43f;
    m_AllyPosY = 631.795f;
    m_AllyPosZ = 96.9406f;
    m_AllyPosO = 2.1785f;

    m_HordePosX = 2179.85f;
    m_HordePosY = -4763.96f;
    m_HordePosZ = 54.911f;
    m_HordePosO = 4.44216f;

    m_DelChar = true;
    m_BanAcc = true;
    m_WarnUser = true;
    m_Enabled = false;

    QueryResult result = CharacterDatabase.Query("SELECT * FROM `jail_conf`");
    if (!result)
        return false;

    Field * fields = result->Fetch();

    m_MaxJails = fields[0].GetUInt32();
    m_MaxDauer = fields[1].GetUInt32();
    m_MinGrund = fields[2].GetUInt32();
    m_WarnUser = fields[3].GetBool();

    m_AllyPosX = fields[4].GetFloat();
    m_AllyPosY = fields[5].GetFloat();
    m_AllyPosZ = fields[6].GetFloat();
    m_AllyPosO = fields[7].GetFloat();
    m_MapAlly = fields[8].GetUInt32();

    m_HordePosX = fields[9].GetFloat();
    m_HordePosY = fields[10].GetFloat();
    m_HordePosZ = fields[11].GetFloat();
    m_HordePosO = fields[12].GetFloat();
    m_MapHorde = fields[13].GetUInt32();

    m_DelChar = fields[14].GetBool();
    m_BanAcc = fields[15].GetBool();
    m_BanDauer = fields[16].GetUInt32();
    m_Radius = fields[17].GetUInt32();
    m_Enabled = fields[18].GetBool();

    if (!reload)
        sLog->outString(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CONF_LOADED));
    else
        sLog->outString(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_RELOAD));

    return true;
}

bool Jail::InfoKommando(ChatHandler * handler)
{
    Player * chr = handler->GetSession()->GetPlayer();
    if (!chr)
        return false;

    if (!m_Enabled)
        return SendeInaktiv(handler);

    time_t localtime = time(NULL);

    if (chr->m_JailRelease > 0)
    {
        uint32 min_left = uint32(floor(float(chr->m_JailRelease - localtime) / 60));

        if (min_left <= 0)
        {
            chr->m_JailRelease = 0;
            chr->JailDatenSpeichern();
            handler->SendSysMessage(LANG_JAIL_NOTJAILED_INFO);
            return true;
        }
        else
        {
            if (min_left >= 60)
                handler->PSendSysMessage(LANG_JAIL_JAILED_H_INFO, uint32(floor(float(chr->m_JailRelease - localtime) / 60 / 60)));
            else
                handler->PSendSysMessage(LANG_JAIL_JAILED_M_INFO, min_left);

            handler->PSendSysMessage(LANG_JAIL_REASON, chr->m_JailGMChar.c_str(), chr->m_JailGrund.c_str());

            return true;
        }
    }
    else
    {
        handler->SendSysMessage(LANG_JAIL_NOTJAILED_INFO);
        return true;
    }
    return false;
}

bool Jail::PInfoKommando(ChatHandler * handler, const char * args)
{
    Player * target = NULL;
    uint64 target_guid = 0;
    std::string target_name;

    if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
        return false;

    if (!m_Enabled)
        return SendeInaktiv(handler);

    if (target && target->m_JailAnzahl > 0)
    {
        if (target->m_JailRelease > 0)
        {
            time_t localtime = time(NULL);
            uint32 min_left = uint32(floor(float(target->m_JailRelease - localtime) / 60));

            if (min_left <= 0)
            {
                target->m_JailRelease = 0;
                target->JailDatenSpeichern();
                handler->PSendSysMessage(LANG_JAIL_GM_INFO, target_name.c_str(), target->m_JailAnzahl, 0, target->m_JailGMChar.c_str(), target->m_JailGrund.c_str());
                return true;
            }
            else
            {
                if (min_left >= 60)
                {
                    uint32 hours = uint32(floor(float(target->m_JailRelease - localtime) / 60 / 60));
                    handler->PSendSysMessage(LANG_JAIL_GM_INFO_H, target_name.c_str(), target->m_JailAnzahl, hours, min_left-(hours*60), target->m_JailGMChar.c_str(), target->m_JailZeit.c_str(), target->m_JailGrund.c_str());
                }
                else
                    handler->PSendSysMessage(LANG_JAIL_GM_INFO, target_name.c_str(), target->m_JailAnzahl, min_left, target->m_JailGMChar.c_str(), target->m_JailZeit.c_str(), target->m_JailGrund.c_str());

                return true;
            }
        }
        else
        {
            handler->PSendSysMessage(LANG_JAIL_GM_INFO, target_name.c_str(), target->m_JailAnzahl, 0, target->m_JailGMChar.c_str(), target->m_JailZeit.c_str(), target->m_JailGrund.c_str());
            return true;
        }
    }

    if (!target)
    {
        uint64 GUID = sObjectMgr->GetPlayerGUIDByName(target_name.c_str());
        uint32 guid = GUID_LOPART(GUID);
        
        if (!guid)
        {
            handler->SendSysMessage(LANG_JAIL_WRONG_NAME);
            handler->SetSentErrorMessage(true);
            return false;
        }

        QueryResult result = CharacterDatabase.PQuery("SELECT * FROM `jail` WHERE `guid`=%u LIMIT 1", guid);
        if (!result)
        {
            handler->PSendSysMessage(LANG_JAIL_GM_NOINFO, target_name.c_str());
            return true;
        }
        else
        {
            Field * fields = result->Fetch();

            uint32 release = fields[2].GetUInt32();
            std::string reason = fields[3].GetString();
            uint32 times = fields[4].GetUInt32();
            std::string gmchar = fields[6].GetString();
            std::string lasttime = fields[7].GetString();

            if (release > 0)
            {
                time_t localtime = time(NULL);
                uint32 min_left = uint32(floor(float(release - localtime) / 60));

                if (min_left >= 60)
                {
                    uint32 hours = uint32(floor(float(release - localtime) / 60 / 60));
                    handler->PSendSysMessage(LANG_JAIL_GM_INFO_H, target_name.c_str(), times, hours, min_left-(hours*60), gmchar.c_str(), lasttime.c_str(), reason.c_str());
                }
                else
                    handler->PSendSysMessage(LANG_JAIL_GM_INFO, target_name.c_str(), times, min_left, gmchar.c_str(), lasttime.c_str(), reason.c_str());

                return true;
            }
            else
            {
                handler->PSendSysMessage(LANG_JAIL_GM_INFO, target_name.c_str(), times, 0, gmchar.c_str(), lasttime.c_str(), reason.c_str());
                return true;
            }
        }
    }
    return false;
}

bool Jail::ArrestKommando(ChatHandler * handler, const char * args)
{
    if (!m_Enabled)
        return SendeInaktiv(handler);

    std::string cname;
    char * charname = strtok((char*)args, " ");
    if (charname == NULL)
    {
        handler->SendSysMessage(LANG_JAIL_NONAME);
        handler->SetSentErrorMessage(true);
        return false;
    }
    else
    {
        cname = charname;
        normalizePlayerName(cname);
    }

    char * timetojail = strtok(NULL, " ");
    if (timetojail == NULL)
    {
        handler->SendSysMessage(LANG_JAIL_NOTIME);
        handler->SetSentErrorMessage(true);
        return false;
    }

    uint32 jailtime = uint32(atoi(timetojail));
    if (jailtime < 1 || jailtime > m_MaxDauer)
    {
        handler->PSendSysMessage(LANG_JAIL_VALUE, m_MaxDauer);
        handler->SetSentErrorMessage(true);
        return false;
    }

    char * reason = strtok(NULL, "\0");
    std::string jailreason;
    if (reason == NULL || strlen((const char*)reason) < m_MinGrund)
    {
        handler->PSendSysMessage(LANG_JAIL_NOREASON, m_MinGrund);
        handler->SetSentErrorMessage(true);
        return false;
    }
    else
        jailreason = reason;

    uint64 GUID = sObjectMgr->GetPlayerGUIDByName(cname.c_str());
    if (!GUID)
    {
        handler->SendSysMessage(LANG_JAIL_WRONG_NAME);
        handler->SetSentErrorMessage(true);
        return false;
    }

    if (cname.c_str() == handler->GetSession()->GetPlayerName())
    {
        handler->SendSysMessage(LANG_JAIL_NO_JAIL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    time_t localtime = time(NULL);

    uint32 times = 0;
    uint32 release = localtime + (jailtime * 60 * 60);
    uint32 banrelease = localtime + (m_BanDauer * 60 * 60);

    std::string announce = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_ANNOUNCE), cname.c_str(), jailtime, handler->GetSession()->GetPlayerName(), jailreason.c_str());

    Player * chr = sObjectMgr->GetPlayer(GUID);
    if (!chr)
    {
        QueryResult result = CharacterDatabase.PQuery("SELECT * FROM `jail` WHERE `guid`=%u LIMIT 1", GUID_LOPART(GUID));
        if (!result)
        {
            ++times;
            CharacterDatabase.PExecute("INSERT INTO `jail` VALUES (%u,'%s',%u,'%s',%u,%u,'%s',CURRENT_TIMESTAMP,%u)",
                GUID_LOPART(GUID), cname.c_str(), release, jailreason.c_str(), times, handler->GetSession()->GetAccountId(), handler->GetSession()->GetPlayerName(), jailtime);
        }
        else
        {
            Field * fields = result->Fetch();
            times = fields[4].GetUInt32()+1;

            CharacterDatabase.PExecute("UPDATE `jail` SET `release`=%u,`reason`='%s',`times`=%u,`gmacc`=%u,`gmchar`='%s',`duration`=%u WHERE `guid`=%u LIMIT 1",
                release, jailreason.c_str(), times, handler->GetSession()->GetAccountId(), handler->GetSession()->GetPlayerName(), jailtime, GUID_LOPART(GUID));
        }
        handler->PSendSysMessage(LANG_JAIL_WAS_JAILED, cname.c_str(), jailtime);
        sWorld->SendServerMessage(SERVER_MSG_STRING, announce.c_str());

        // Nur wenn m_MaxJails gesetzt ist, hier hinein gehen!
        if (m_MaxJails && m_MaxJails == times)
        {
            if (m_DelChar)
            {
                QueryResult result = CharacterDatabase.PQuery("SELECT * FROM `characters` WHERE `guid`=%u LIMIT 1", GUID_LOPART(GUID));
                if (!result)
                {
                    handler->PSendSysMessage(LANG_NO_PLAYER, cname.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                Field * fields = result->Fetch();
                Player::DeleteFromDB(GUID, fields[1].GetUInt32());
            }
            if (m_BanAcc)
            {
                QueryResult result = CharacterDatabase.PQuery("SELECT * FROM `characters` WHERE `guid`=%u LIMIT 1", GUID_LOPART(GUID));
                if (!result)
                {
                    handler->PSendSysMessage(LANG_NO_PLAYER, cname.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                Field * fields = result->Fetch();
                uint32 acc_id = fields[1].GetUInt32();

                result = LoginDatabase.PQuery("SELECT * FROM `account` WHERE `id`=%u LIMIT 1", acc_id);
                if (!result)
                {
                    handler->PSendSysMessage(LANG_NO_PLAYER, cname.c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }
                LoginDatabase.PExecute("REPLACE INTO `account_banned` (`id`,`bandate`,`unbandate`,`bannedby`,`banreason`) VALUES (%u,UNIX_TIMESTAMP,%u,'%s','%s')",
                    acc_id, banrelease, sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_BAN_BY), sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_BAN_REASON));

                // Wenn der Account gebannt wurde, müssen die Daten im Jail zurück gesetzt werden!
                // Um sehen zu können, warum sie zurück gesetzt wurden, tragen wir dafür die Banndaten ein. ;)
                CharacterDatabase.PExecute("UPDATE `jail` SET `release`=0,`reason`='%s',`times`=0,`gmacc`=0,`gmchar`='%s',`duration`=%u WHERE `guid`=%u LIMIT 1",
                    sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_BAN_REASON), sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_BAN_BY), m_BanDauer, GUID_LOPART(GUID));
            }
        }
        return true;
    }

    QueryResult result = CharacterDatabase.PQuery("SELECT * FROM `characters` WHERE `guid`=%u LIMIT 1", chr->GetGUIDLow());
    if (!result)
    {
        handler->PSendSysMessage(LANG_NO_PLAYER, cname.c_str());
        handler->SetSentErrorMessage(true);
        return false;
    }

    chr->SaveToDB();

    chr->m_Jailed = true;
    chr->m_JailRelease = release;
    chr->m_JailGrund = jailreason;
    chr->m_JailGMAcc = handler->GetSession()->GetAccountId();
    chr->m_JailGMChar = handler->GetSession()->GetPlayerName();
    chr->m_JailDauer = jailtime;

    ++chr->m_JailAnzahl;

    chr->JailDatenSpeichern();

    Field * fields = result->Fetch();

    handler->PSendSysMessage(LANG_JAIL_WAS_JAILED, fields[3].GetString().c_str(), jailtime);
    ChatHandler(chr).PSendSysMessage(LANG_JAIL_YOURE_JAILED, handler->GetSession()->GetPlayerName(), jailtime);
    ChatHandler(chr).PSendSysMessage(LANG_JAIL_REASON, handler->GetSession()->GetPlayerName(), jailreason.c_str());

    sWorld->SendServerMessage(SERVER_MSG_STRING, announce.c_str());

    // Nur wenn m_MaxJails gesetzt ist, hier hinein gehen!
    if (m_MaxJails && m_MaxJails == chr->m_JailAnzahl)
    {
        uint32 acc_id = chr->GetSession()->GetAccountId();

        if (m_DelChar)
        {
            chr->GetSession()->KickPlayer();
            chr = NULL; // chr wird durch KickPlayer() ungültig!
            Player::DeleteFromDB(fields[0].GetUInt64(), fields[1].GetUInt32());
        }
        if (m_BanAcc)
        {
            if (chr)
                chr->GetSession()->KickPlayer();

            LoginDatabase.PExecute("REPLACE INTO `account_banned` (`id`,`bandate`,`unbandate`,`bannedby`,`banreason`) VALUES (%u,UNIX_TIMESTAMP,%u,'%s','%s')",
                acc_id, banrelease, sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_BAN_BY), sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_BAN_REASON));

            // Wenn der Account gebannt wurde, müssen die Daten im Jail zurück gesetzt werden!
            // Um sehen zu können, warum sie zurück gesetzt wurden, tragen wir dafür die Banndaten ein. ;)
            CharacterDatabase.PExecute("UPDATE `jail` SET `release`=0,`reason`='%s',`times`=0,`gmacc`=0,`gmchar`='%s',`duration`=%u WHERE `guid`=%u LIMIT 1",
                sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_BAN_REASON), sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_BAN_BY), m_BanDauer, GUID_LOPART(GUID));
        }
    }
    return true;
}

bool Jail::ReleaseKommando(ChatHandler * handler, const char * args)
{
    Player * target = NULL;
    uint64 target_guid = 0;
    std::string target_name;

    if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
        return false;

    if (!m_Enabled)
        return SendeInaktiv(handler);

    if (target)
    {
        if (target_name == handler->GetSession()->GetPlayerName())
        {
            handler->SendSysMessage(LANG_JAIL_NO_UNJAIL);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (target->m_Jailed)
        {
            target->m_Jailed = false;
            target->m_JailRelease = 0;
            if (target->m_JailAnzahl)
                --target->m_JailAnzahl;

            target->JailDatenSpeichern();

            if (target->m_JailAnzahl == 0)
                CharacterDatabase.PExecute("DELETE FROM `jail` WHERE `guid`=%u LIMIT 1", target->GetGUIDLow());

            handler->PSendSysMessage(LANG_JAIL_WAS_UNJAILED, target_name.c_str());
            ChatHandler(target).PSendSysMessage(LANG_JAIL_YOURE_UNJAILED, handler->GetSession()->GetPlayerName());

            sLog->outBasic(fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), target_name.c_str(), target->GetGUIDLow()));
            sWorld->SendServerMessage(SERVER_MSG_STRING, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), target_name.c_str(), target->GetGUIDLow()));

            target->CastSpell(target, SPELL_STACK, true);
        }
        else
        {
            handler->PSendSysMessage(LANG_JAIL_CHAR_NOTJAILED, target_name.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }
        return true;
    }
    else
    {
        QueryResult result = CharacterDatabase.PQuery("SELECT * FROM `jail` WHERE `guid`=%u LIMIT 1", GUID_LOPART(target_guid));
        if (!result)
        {
            handler->PSendSysMessage(LANG_JAIL_CHAR_NOTJAILED, target_name.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        Field * fields = result->Fetch();
        
        if (!fields[2].GetUInt32())
        {
            // Es gibt zwar einen Jaileintrag, aber die Entlassungszeit ist auf 0 ergo -> nicht noch einmal entlassen lassen!
            // Zum Löschen der Jaileinträge ist das 'reset' Kommando da! ;)
            handler->PSendSysMessage(LANG_JAIL_CHAR_NOTJAILED, target_name.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }
        else
        {
            uint32 jail_times = fields[4].GetUInt32()-1;

            if (jail_times == 0)
                CharacterDatabase.PExecute("DELETE FROM `jail` WHERE `guid`=%u LIMIT 1", GUID_LOPART(target_guid));
            else
                CharacterDatabase.PExecute("UPDATE `jail` SET `release`=0,`times`=%u WHERE `guid`=%u LIMIT 1", jail_times, GUID_LOPART(target_guid));

            // Da der Charakter nicht online ist, setzen wir ihn von Hand zurück nach hause. ;)
            QueryResult cresult = CharacterDatabase.PQuery("SELECT * FROM `character_homebind` WHERE `guid`=%u", GUID_LOPART(target_guid));
            if (cresult)
            {
                Field * fields = cresult->Fetch();
                CharacterDatabase.PExecute("UPDATE `characters` SET `position_x`=%u,`position_y`=%u,`position_z`=%u,`map`=%u WHERE `guid`=%u LIMIT 1",
                    fields[3].GetFloat(), fields[4].GetFloat(), fields[5].GetFloat(), fields[1].GetUInt32(), GUID_LOPART(target_guid));
            }

            handler->PSendSysMessage(LANG_JAIL_WAS_UNJAILED, target_name.c_str());

            sLog->outBasic(fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), target_name.c_str(), GUID_LOPART(target_guid)));
            sWorld->SendServerMessage(SERVER_MSG_STRING, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), target_name.c_str(), GUID_LOPART(target_guid)));

            return true;
        }

    }
    return false;
}

bool Jail::ResetKommando(ChatHandler * handler, const char * args)
{
    Player * target = NULL;
    uint64 target_guid = 0;
    std::string target_name;

    if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
        return false;

    if (!m_Enabled)
        return SendeInaktiv(handler);

    // Erst aus dem Knast holen, bevor der Jaileintrag gelöscht wird
    ReleaseKommando(handler, args);

    CharacterDatabase.PExecute("DELETE FROM `jail` WHERE `guid`=%u LIMIT 1", GUID_LOPART(target_guid));

    return true;
}

bool Jail::EnableKommando(ChatHandler * handler)
{
    m_Enabled = true;
    handler->SendSysMessage(LANG_JAIL_ENABLED);
    return true;
}

bool Jail::DisableKommando(ChatHandler * handler)
{
    m_Enabled = false;
    handler->SendSysMessage(LANG_JAIL_DISABLED);
    return true;
}

bool Jail::ReloadKommando(ChatHandler * handler)
{
    if (LadeKonfiguration(true))
    {
        handler->SendSysMessage(LANG_JAIL_RELOAD);
        return true;
    }
    return false;
}

Position Jail::HoleAllyKnastPos()
{
    Position pos;
    pos.m_positionX = m_AllyPosX;
    pos.m_positionY = m_AllyPosY;
    pos.m_positionZ = m_AllyPosZ;
    pos.m_orientation = m_AllyPosO;
    return pos;
}

Position Jail::HoleHordeKnastPos()
{
    Position pos;
    pos.m_positionX = m_HordePosX;
    pos.m_positionY = m_HordePosY;
    pos.m_positionZ = m_HordePosZ;
    pos.m_orientation = m_HordePosO;
    return pos;
}

void Jail::Kontrolle(Player * pPlayer, bool update)
{
    if (!pPlayer || !m_Enabled)
        return;

    if (pPlayer->m_JailRelease == 0)
    {
        pPlayer->m_Jailed = false;
        return;
    }

    time_t localtime = time(NULL);

    if (pPlayer->m_JailRelease <= localtime)
    {
        pPlayer->m_Jailed = false;
        pPlayer->m_JailRelease = 0;

        pPlayer->JailDatenSpeichern();

        sLog->outBasic(fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), pPlayer->GetName(), pPlayer->GetGUIDLow()));
        sWorld->SendServerMessage(SERVER_MSG_STRING, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), pPlayer->GetName(), pPlayer->GetGUIDLow()));

        pPlayer->CastSpell(pPlayer, SPELL_STACK, true);

        return;
    }

    if (pPlayer->m_Jailed)
    {
        Position pos;
        uint32 map;

        if (pPlayer->GetTeam() == ALLIANCE)
        {
            map = HoleAllyKnastKarte();
            pos = HoleAllyKnastPos();
        }
        else
        {
            map = HoleHordeKnastKarte();
            pos = HoleHordeKnastPos();
        }

        if (pPlayer->GetMapId() != map || m_Radius < uint32(pPlayer->GetDistance(pos)))
            pPlayer->TeleportTo(map, pos.m_positionX, pos.m_positionY, pos.m_positionZ, pos.m_orientation);

        if (!update)
        {
            sLog->outBasic(fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_TELE), pPlayer->GetName(), pPlayer->GetGUIDLow()));
            sWorld->SendServerMessage(SERVER_MSG_STRING, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_TELE), pPlayer->GetName(), pPlayer->GetGUIDLow()));
        }
    }
}

bool Jail::SendeInaktiv(ChatHandler * handler)
{
    handler->SendSysMessage(LANG_JAIL_NOT_ACTIVE);
    handler->SetSentErrorMessage(true);
    return false;
}

void Jail::SendeWarnung(Player * pPlayer)
{
    if (!pPlayer || !m_Enabled)
        return;

    // Nur warnen, wenn m_MaxJails auch gesetzt ist! ;)
    if (m_WarnUser && m_MaxJails && (m_MaxJails - pPlayer->m_JailAnzahl) <= 1)
    {
        if (m_DelChar)
            pPlayer->GetSession()->SendNotification(LANG_JAIL_WARNING);

        if (m_BanAcc)
            pPlayer->GetSession()->SendNotification(LANG_JAIL_WARNING_BAN);
    }
}
