// Copyright (C) 2008-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de

#include <Jail.h>

Jail::Jail()
{
}

Jail::~Jail()
{
}

bool Jail::LadeKonfiguration(bool reload)
{
    // Standardkonfiguration initialisieren...
    m_JailKonf.MaxJails = 3;
    m_JailKonf.MaxDauer = 720;  // 30 Tage
    m_JailKonf.MinGrund = 40;
    m_JailKonf.Radius = 15;     // Yards

    m_JailKonf.MapAlly = 0;
    m_JailKonf.MapHorde = 1;

    m_JailKonf.BanDauer = 168;  // 1 Woche

    m_JailKonf.Amnestie = 3;    // 3 Monate

    m_JailKonf.GMAcc = 0;

    m_JailKonf.AllyPos.m_positionX = -8673.43f;
    m_JailKonf.AllyPos.m_positionY = 631.795f;
    m_JailKonf.AllyPos.m_positionZ = 96.9406f;
    m_JailKonf.AllyPos.m_orientation = 2.1785f;

    m_JailKonf.HordePos.m_positionX = 2179.85f;
    m_JailKonf.HordePos.m_positionY = -4763.96f;
    m_JailKonf.HordePos.m_positionZ = 54.911f;
    m_JailKonf.HordePos.m_orientation = 4.44216f;

    m_JailKonf.DelChar = false;
    m_JailKonf.BanAcc = true;
    m_JailKonf.WarnUser = true;
    m_JailKonf.Enabled = false;

    QueryResult result = CharacterDatabase.Query("SELECT * FROM `jail_conf`");
    if (!result)
        return false;

    Field * fields = result->Fetch();

    m_JailKonf.MaxJails = fields[0].GetUInt32();
    m_JailKonf.MaxDauer = fields[1].GetUInt32();
    m_JailKonf.MinGrund = fields[2].GetUInt32();
    m_JailKonf.WarnUser = fields[3].GetBool();

    m_JailKonf.AllyPos.m_positionX = fields[4].GetFloat();
    m_JailKonf.AllyPos.m_positionY = fields[5].GetFloat();
    m_JailKonf.AllyPos.m_positionZ = fields[6].GetFloat();
    m_JailKonf.AllyPos.m_orientation = fields[7].GetFloat();
    m_JailKonf.MapAlly = fields[8].GetUInt32();

    m_JailKonf.HordePos.m_positionX = fields[9].GetFloat();
    m_JailKonf.HordePos.m_positionY = fields[10].GetFloat();
    m_JailKonf.HordePos.m_positionZ = fields[11].GetFloat();
    m_JailKonf.HordePos.m_orientation = fields[12].GetFloat();
    m_JailKonf.MapHorde = fields[13].GetUInt32();

    m_JailKonf.DelChar = fields[14].GetBool();
    m_JailKonf.BanAcc = fields[15].GetBool();
    m_JailKonf.BanDauer = fields[16].GetUInt32();
    m_JailKonf.Radius = fields[17].GetUInt32();
    m_JailKonf.Enabled = fields[18].GetBool();

    m_JailKonf.GMAcc = fields[19].GetUInt32();
    m_JailKonf.GMChar = fields[20].GetString();
    m_JailKonf.Amnestie = fields[21].GetUInt32();

    if (!reload)
        sLog->outString(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CONF_LOADED));
    else
        sLog->outString(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_RELOAD));

    return true;
}

void Jail::KnastAufraeumen()
{
    sLog->outString(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_STARTUP_CLEANUP));
    CharacterDatabase.PExecute("DELETE FROM `jail` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`)");
}

bool Jail::InfoKommando(ChatHandler * handler)
{
    if (!m_JailKonf.Enabled)
        return SendeInaktiv(handler);

    Player * chr = handler->GetSession()->GetPlayer();
    if (!chr)
        return false;

    JailMap::iterator itr = m_JailMap.find(chr->GetGUIDLow());
    if (itr == m_JailMap.end())
    {
        handler->PSendSysMessage(LANG_JAIL_NOTJAILED_INFO, chr->GetName());
        return true;
    }
    // Nur Bannungen eingetragen
    if (!chr->m_JailAnzahl && chr->m_JailBans)
    {
        handler->PSendSysMessage(LANG_JAIL_GM_INFO_BANS, chr->GetName(), chr->m_JailBans);
        return true;
    }
    // Aktiver oder abgelauferner Jail eingetragen
    time_t localtime = time(NULL);
    uint32 min_left = uint32(floor(float(chr->m_JailRelease - localtime) / MINUTE));

    if (min_left && min_left > (m_JailKonf.MaxDauer*MINUTE)) // Es kann sonst zu "merkwürdigen" Ausgaben kommen. ;)
        min_left = 0;

    if (min_left >= MINUTE)
    {
        uint32 hours = uint32(floor(float(chr->m_JailRelease - localtime) / HOUR));
        handler->PSendSysMessage(LANG_JAIL_JAILED_H_INFO, hours, min_left-(hours*MINUTE));
        handler->PSendSysMessage(LANG_JAIL_REASON, chr->m_JailGMChar.c_str(), chr->m_JailGrund.c_str());
    }
    else if (min_left)
    {
        handler->PSendSysMessage(LANG_JAIL_JAILED_M_INFO, min_left);
        handler->PSendSysMessage(LANG_JAIL_REASON, chr->m_JailGMChar.c_str(), chr->m_JailGrund.c_str());
    }
    else
        handler->SendSysMessage(LANG_JAIL_PRESERVATION);

    return true;
}

bool Jail::GotoKommando(ChatHandler * handler, const char * args)
{
    if (!m_JailKonf.Enabled)
        return SendeInaktiv(handler);

    Player * chr = handler->GetSession()->GetPlayer();
    if (!chr)
        return false;

    std::string tmp;
    char * chartmp = strtok((char*)args, " ");
    if (chartmp == NULL)
    {
        handler->SendSysMessage(LANG_JAIL_NO_SITE);
        handler->SetSentErrorMessage(true);
        return false;
    }
    else
    {
        tmp = chartmp;
        normalizePlayerName(tmp);
    }

    if (tmp == "horde")
        chr->TeleportTo(m_JailKonf.MapHorde, m_JailKonf.HordePos.m_positionX, m_JailKonf.HordePos.m_positionY, m_JailKonf.HordePos.m_positionZ, m_JailKonf.HordePos.m_orientation);
    else
        chr->TeleportTo(m_JailKonf.MapAlly, m_JailKonf.AllyPos.m_positionX, m_JailKonf.AllyPos.m_positionY, m_JailKonf.AllyPos.m_positionZ, m_JailKonf.AllyPos.m_orientation);

    return true;
}

bool Jail::PInfoKommando(ChatHandler * handler, const char * args)
{
    if (!m_JailKonf.Enabled)
        return SendeInaktiv(handler);

    Player * target = NULL;
    uint64 target_guid = 0;
    std::string target_name;

    if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
        return false;

    JailMap::iterator itr = m_JailMap.find(GUID_LOPART(target_guid));
    if (itr == m_JailMap.end())
    {
        handler->PSendSysMessage(LANG_JAIL_GM_NOINFO, target_name.c_str());
        return true;
    }

    if (target)
    {
        // Keine Jails eingetragen
        if (!target->m_JailAnzahl)
        {
            // Keine Banns eingetragen
            if (!target->m_JailBans)
            {
                if (handler->GetSession()->GetPlayer()->GetGUID() == target->GetGUID())
                {
                    handler->SendSysMessage(LANG_JAIL_NOTJAILED_INFO);
                    return true;
                }
                else
                {
                    handler->SendSysMessage(LANG_JAIL_GM_NOINFO);
                    return true;
                }
            }
            // Banns ist nicht auf 0
            else
            {
                handler->PSendSysMessage(LANG_JAIL_GM_INFO_BANS, target_name.c_str(), target->m_JailBans);
                return true;
            }
        }
        // Aktiver oder abgelauferner Jail eingetragen
        time_t localtime = time(NULL);
        uint32 min_left = uint32(floor(float(target->m_JailRelease - localtime) / MINUTE));

        if (min_left && min_left > (m_JailKonf.MaxDauer*MINUTE)) // Es kann sonst zu "merkwürdigen" Ausgaben kommen. ;)
            min_left = 0;

        if (min_left >= MINUTE)
        {
            uint32 hours = uint32(floor(float(target->m_JailRelease - localtime) / HOUR));
            handler->PSendSysMessage(LANG_JAIL_GM_INFO_H, target_name.c_str(), target->m_JailAnzahl, hours, min_left-(hours*MINUTE),
                target->m_JailGMChar.c_str(), TimeToTimestampStr(target->m_JailZeit, GERMAN).c_str(), target->m_JailGrund.c_str());
        }
        else
            handler->PSendSysMessage(LANG_JAIL_GM_INFO, target_name.c_str(), target->m_JailAnzahl, min_left,
            target->m_JailGMChar.c_str(), TimeToTimestampStr(target->m_JailZeit, GERMAN).c_str(), target->m_JailGrund.c_str());

        if (target->m_JailBans)
            handler->PSendSysMessage(LANG_JAIL_GM_INFO_ONLY_BANS, target->m_JailBans);

        return true;
    }
    else
    {
        uint64 GUID = sObjectMgr->GetPlayerGUIDByName(target_name);
        uint32 guid = GUID_LOPART(GUID);

        if (!guid)
        {
            handler->SendSysMessage(LANG_JAIL_WRONG_NAME);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // Keine aktiven / abgelaufenen Jails, aber Bannungen
        if (!itr->second.Times && itr->second.BTimes)
        {
            handler->PSendSysMessage(LANG_JAIL_GM_INFO_BANS, target_name.c_str(), itr->second.BTimes);
            return true;
        }

        time_t localtime = time(NULL);
        uint32 min_left = uint32(floor(float(itr->second.Release - localtime) / MINUTE));

        if (min_left && min_left > (m_JailKonf.MaxDauer*MINUTE)) // Es kann sonst zu "merkwürdigen" Ausgaben kommen. ;)
            min_left = 0;

        if (min_left >= MINUTE)
        {
            uint32 hours = uint32(floor(float(itr->second.Release - localtime) / HOUR));
            handler->PSendSysMessage(LANG_JAIL_GM_INFO_H, target_name.c_str(), itr->second.Times, hours, min_left-(hours*MINUTE),
                itr->second.GMChar.c_str(), TimeToTimestampStr(itr->second.Time, GERMAN).c_str(), itr->second.Reason.c_str());
        }
        else
            handler->PSendSysMessage(LANG_JAIL_GM_INFO, target_name.c_str(), itr->second.Times, min_left, itr->second.GMChar.c_str(), TimeToTimestampStr(itr->second.Time, GERMAN).c_str(), itr->second.Reason.c_str());

        if (itr->second.BTimes)
            handler->PSendSysMessage(LANG_JAIL_GM_INFO_ONLY_BANS, itr->second.BTimes);

        return true;
    }
    return false;
}

bool Jail::ArrestKommando(ChatHandler * handler, const char * args)
{
    if (!m_JailKonf.Enabled)
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
    if (jailtime < 1 || jailtime > m_JailKonf.MaxDauer)
    {
        handler->PSendSysMessage(LANG_JAIL_VALUE, m_JailKonf.MaxDauer);
        handler->SetSentErrorMessage(true);
        return false;
    }

    char * reason = strtok(NULL, "\0");
    std::string jailreason;
    if (reason == NULL || strlen((const char*)reason) < m_JailKonf.MinGrund)
    {
        handler->PSendSysMessage(LANG_JAIL_NOREASON, m_JailKonf.MinGrund);
        handler->SetSentErrorMessage(true);
        return false;
    }
    else
        jailreason = reason;

    uint64 GUID = sObjectMgr->GetPlayerGUIDByName(cname);
    uint32 guid = GUID_LOPART(GUID);

    if (!guid)
    {
        handler->SendSysMessage(LANG_JAIL_WRONG_NAME);
        handler->SetSentErrorMessage(true);
        return false;
    }

    JailMap::iterator itr = m_JailMap.find(guid);
    if (itr != m_JailMap.end())
    {
        // Es gibt bereits einen aktiven Jail! Nicht noch einmal einbuchten lassen!
        if (itr->second.Release)
        {
            handler->PSendSysMessage(LANG_JAIL_GM_ALREADY_JAILED, cname.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }
    }

    if (guid == GUID_LOPART(handler->GetSession()->GetPlayer()->GetGUID()))
    {
        handler->SendSysMessage(LANG_JAIL_NO_JAIL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    uint32 acc_id = sObjectMgr->GetPlayerAccountIdByPlayerName(cname);
    std::string announce = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_ANNOUNCE), cname.c_str(), jailtime, handler->GetSession()->GetPlayerName(), jailreason.c_str());

    if (Player * chr = sObjectMgr->GetPlayerByLowGUID(guid))
    {   // Ohne Klammern springt er zum Ende, wenn chr == NULL ist!!!
        if (Inhaftierung(handler, chr, cname, jailtime, jailreason, acc_id, announce))
            return true;
    }
    else
    {
        if (Inhaftierung(handler, guid, cname, jailtime, jailreason, acc_id, announce))
            return true;
    }
    return false;
}

bool Jail::ReleaseKommando(ChatHandler * handler, const char * args, bool reset)
{
    if (!m_JailKonf.Enabled)
        return SendeInaktiv(handler);

    Player * target = NULL;;
    uint64 target_guid = 0;
    std::string target_name;

    if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
        return false;

    JailMap::iterator itr = m_JailMap.find(GUID_LOPART(target_guid));
    if (itr == m_JailMap.end())
    {
        handler->PSendSysMessage(LANG_JAIL_GM_NOINFO, target_name.c_str());
        handler->SetSentErrorMessage(true);
        return false;
    }

    if (target_guid == handler->GetSession()->GetPlayer()->GetGUID())
    {
        handler->SendSysMessage(LANG_JAIL_NO_JAIL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    if (target)
    {
        if (target->m_Jailed || reset)
        {
            target->m_Jailed = false;
            target->m_JailRelease = 0;

            if (target->m_JailAnzahl)
                --target->m_JailAnzahl;

            if (target->m_JailAnzahl == 0 || reset)
            {
                CharacterDatabase.PExecute("DELETE FROM `jail` WHERE `guid`=%u LIMIT 1", target->GetGUIDLow());
                // Es gibt keinen DB Eintrag mehr -> also löschen!
                m_JailMap.erase(itr);
            }
            else
                target->JailDatenSpeichern(); // Spieler wurde mehr als 1x gejailt, also neue Daten speichern!

            handler->PSendSysMessage(LANG_JAIL_WAS_UNJAILED, target_name.c_str());
            ChatHandler(target).PSendSysMessage(LANG_JAIL_YOURE_UNJAILED, handler->GetSession()->GetPlayerName());

            sLog->outBasic(fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), target_name.c_str(), target->GetGUIDLow()));
            sWorld->SendServerMessage(SERVER_MSG_STRING, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), target_name.c_str(), target->GetGUIDLow()));

            target->TeleportTo(target->GetStartPosition());
        }
        return true;
    }
    else
    {
        if (!itr->second.Release && !reset)
        {
            // Es gibt zwar einen Jaileintrag, aber die Entlassungszeit ist auf 0 ergo -> nicht noch einmal entlassen lassen!
            // Zum Löschen der Jaileinträge ist das 'reset' Kommando da! ;)
            handler->PSendSysMessage(LANG_JAIL_CHAR_NOTJAILED, target_name.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }
        else
        {
            if (itr->second.Times)
                --itr->second.Times;

            if (itr->second.Times == 0 || reset)
            {
                CharacterDatabase.PExecute("DELETE FROM `jail` WHERE `guid`=%u LIMIT 1", GUID_LOPART(target_guid));
                // Es gibt keinen DB Eintrag mehr -> also löschen!
                m_JailMap.erase(itr);
            }
            else
            {
                CharacterDatabase.PExecute("UPDATE `jail` SET `release`=0,`times`=%u WHERE `guid`=%u LIMIT 1", itr->second.Times, GUID_LOPART(target_guid));
                itr->second.Release = 0;
            }

            // Da der Charakter nicht online ist, setzen wir ihn von Hand zurück nach hause. ;)
            CharacterDatabase.PExecute("UPDATE characters c,character_homebind b SET c.position_x=b.posX,c.position_y=b.posY,c.position_z= b.posZ,c.map=b.mapId WHERE c.guid=%u", GUID_LOPART(target_guid));

            sLog->outBasic(fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), target_name.c_str(), GUID_LOPART(target_guid)));
            sWorld->SendServerMessage(SERVER_MSG_STRING, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), target_name.c_str(), GUID_LOPART(target_guid)));

            handler->PSendSysMessage(LANG_JAIL_WAS_UNJAILED, target_name.c_str());
        }
        return true;
    }
    return false;
}

bool Jail::ResetKommando(ChatHandler * handler, const char * args, bool force)
{
    if (!m_JailKonf.Enabled)
        return SendeInaktiv(handler);

    Player * target = NULL;
    uint64 target_guid = 0;
    uint32 add_id = 0;
    std::string target_name;

    if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
        return false;

    JailMap::iterator itr = m_JailMap.find(GUID_LOPART(target_guid));
    if (itr == m_JailMap.end())
    {
        handler->PSendSysMessage(LANG_JAIL_GM_NOINFO, target_name.c_str());
        handler->SetSentErrorMessage(true);
        return false;
    }

    if (target_guid == handler->GetSession()->GetPlayer()->GetGUID())
    {
        handler->SendSysMessage(LANG_JAIL_NO_JAIL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    if (itr != m_JailMap.end())
    {
        // Jails, dessen Account gebannt wurde, nicht löschen lassen, es sei denn force (delete Kommando) ist gesetzt!
        if (!force && ((target && target->m_JailBans) || itr->second.BTimes))
        {
            handler->SendSysMessage(LANG_JAIL_GM_NO_DELETE);
            handler->SetSentErrorMessage(true);
            return false;
        }
    }

    add_id = itr->second.account;

    // Erst aus dem Knast holen, bevor der Jaileintrag gelöscht wird!
    ReleaseKommando(handler, args, true);

    CharacterDatabase.PExecute("DELETE FROM `jail` WHERE `guid`=%u LIMIT 1", GUID_LOPART(target_guid));

    if (force)
        LoginDatabase.PExecute("DELETE FROM `account_banned` WHERE `id`=%u LIMIT 1", add_id);

    // Es gibt keinen DB Eintrag mehr -> also löschen! Es kann aber sein, das itr in ReleaseKommando() bereits gelöscht wurde!
    itr = m_JailMap.find(GUID_LOPART(target_guid));
    if (itr != m_JailMap.end())
        m_JailMap.erase(itr);

    return true;
}

bool Jail::EnableKommando(ChatHandler * handler)
{
    m_JailKonf.Enabled = true;
    CharacterDatabase.PExecute("UPDATE `jail_conf` SET `enabled`=1");
    handler->SendSysMessage(LANG_JAIL_ENABLED);
    return Init(true);
}

bool Jail::DisableKommando(ChatHandler * handler)
{
    m_JailKonf.Enabled = false;
    CharacterDatabase.PExecute("UPDATE `jail_conf` SET `enabled`=0");
    handler->SendSysMessage(LANG_JAIL_DISABLED);
    return true;
}

bool Jail::ReloadKommando(ChatHandler * handler)
{
    if (LadeKonfiguration(true))
    {
        handler->SendSysMessage(LANG_JAIL_RELOAD);

        if (Init(true))
            handler->SendSysMessage(LANG_JAIL_RELOAD_JAIL);

        return true;
    }
    return false;
}

void Jail::Kontrolle(Player * pPlayer, bool update)
{
    if (!pPlayer || !m_JailKonf.Enabled)
        return;

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

        if (pPlayer->GetMapId() != map || m_JailKonf.Radius < uint32(pPlayer->GetDistance(pos)))
            pPlayer->TeleportTo(map, pos.m_positionX, pos.m_positionY, pos.m_positionZ, pos.m_orientation);

        // Spieler hat sich gerade eingelogt
        if (!update)
        {
            sLog->outBasic(fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_TELE), pPlayer->GetName(), pPlayer->GetGUIDLow()));
            sWorld->SendServerMessage(SERVER_MSG_STRING, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_TELE), pPlayer->GetName(), pPlayer->GetGUIDLow()));
        }
    }
}

void Jail::Amnestie()
{
    time_t localtime = time(NULL);

    for (JailMap::iterator itr = m_JailMap.begin(); itr != m_JailMap.end(); ++itr)
        if (itr->second.Time+(m_JailKonf.Amnestie*MONTH) <= localtime)
        {
            CharacterDatabase.PExecute("DELETE FROM `jail` WHERE `guid`=%u LIMIT 1", itr->first);
            m_JailMap.erase(itr);
        }
}

void Jail::Update()
{
    sLog->outDebug(LOG_FILTER_NONE, sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_DEBUG_UPDATE_1));

    if (m_JailMap.empty())
    {
        sLog->outDebug(LOG_FILTER_NONE, sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_DEBUG_UPDATE_2));
        return;
    }

    // Auf Amnestie prüfen, wenn m_JailKonf.Amnestie > 0 ist...
    if (m_JailKonf.Amnestie)
        Amnestie();

    uint32 cnt = 0;
    uint32 oldMSTime = getMSTime();

    for (JailMap::iterator itr = m_JailMap.begin(); itr != m_JailMap.end(); ++itr)
    {
        if (!itr->second.Release)
            continue;

        time_t localtime = time(NULL);

        if (Player * pPlayer = sObjectMgr->GetPlayerByLowGUID(itr->first))
        {
            // Online Char gefunden!
            ++cnt;

            if (itr->second.Release > localtime)
                continue;

            pPlayer->m_Jailed = false;
            pPlayer->m_JailRelease = 0;
            pPlayer->JailDatenSpeichern();
            pPlayer->TeleportTo(pPlayer->GetStartPosition());

            sLog->outBasic(fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), pPlayer->GetName(), pPlayer->GetGUIDLow()));
            sWorld->SendServerMessage(SERVER_MSG_STRING, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), pPlayer->GetName(), pPlayer->GetGUIDLow()));

            continue;
        }

        if (itr->second.Release <= localtime)
        {
            ++cnt;

            itr->second.Release = 0;
            CharacterDatabase.PExecute("UPDATE `jail` SET `release`=%u WHERE `guid`=%u LIMIT 1", itr->second.Release, itr->first);

            // Da der Charakter nicht online ist, setzen wir ihn von Hand zurück nach hause. ;)
            CharacterDatabase.PExecute("UPDATE characters c,character_homebind b SET c.position_x=b.posX,c.position_y=b.posY,c.position_z= b.posZ,c.map=b.mapId WHERE c.guid=%u", itr->first);

            sLog->outBasic(fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), itr->second.CharName.c_str(), itr->first));
            sWorld->SendServerMessage(SERVER_MSG_STRING, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_CHAR_FREE), itr->second.CharName.c_str(), itr->first));
        }
    }
    sLog->outDebug(LOG_FILTER_NONE, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_DEBUG_UPDATE_3), cnt, GetMSTimeDiffToNow(oldMSTime)));
}

bool Jail::Init(bool reload)
{
    m_JailMap.clear(); // Für den Reload

    sLog->outString(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_INIT_1));

    if (!m_JailKonf.Enabled)
    {
         sLog->outString(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_INIT_2));
         return false;
    }

    QueryResult result = CharacterDatabase.Query("SELECT * FROM `jail`");
    if (!result)
    {
        sLog->outString(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_INIT_3));
        return false;
    }

    uint32 cnt = 0;
    uint32 cntaktiv = 0;
    uint32 oldMSTime = getMSTime();

    do
    {
        ++cnt;

        Field * fields = result->Fetch();

        JailEintragStruktur JES;

        uint32 guid     = fields[0].GetUInt32();
        JES.CharName    = fields[1].GetString();
        JES.Release     = fields[2].GetUInt32();
        JES.Reason      = fields[3].GetString();
        JES.Times       = fields[4].GetUInt32();
        JES.GMAcc       = fields[5].GetUInt32();
        JES.GMChar      = fields[6].GetString();
        JES.Time        = fields[7].GetUInt32();
        JES.Duration    = fields[8].GetUInt32();
        JES.BTimes      = fields[9].GetUInt32();
        JES.account     = sObjectMgr->GetPlayerAccountIdByPlayerName(JES.CharName);

        if (JES.Release)
            ++cntaktiv;

         m_JailMap[guid] = JES;

    } while (result->NextRow());

    sLog->outString(fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_INIT_4), cnt, cntaktiv, GetMSTimeDiffToNow(oldMSTime)));

    if (reload)
        sLog->outString(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_RELOAD_JAIL));
    else
        sLog->outString(sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_DATA_LOADED));

    return true;
}

bool Jail::SendeInaktiv(ChatHandler * handler)
{
    handler->SendSysMessage(LANG_JAIL_NOT_ACTIVE);
    handler->SetSentErrorMessage(true);
    return false;
}

void Jail::SendeWarnung(Player * pPlayer)
{
    if (!pPlayer || !m_JailKonf.Enabled)
        return;

    // Nur warnen, wenn m_MaxJails auch gesetzt ist! ;)
    if (m_JailKonf.WarnUser && m_JailKonf.MaxJails && (m_JailKonf.MaxJails - pPlayer->m_JailAnzahl) <= 1)
    {
        if (m_JailKonf.DelChar)
            pPlayer->GetSession()->SendNotification(LANG_JAIL_WARNING);

        if (m_JailKonf.BanAcc)
            pPlayer->GetSession()->SendNotification(LANG_JAIL_WARNING_BAN);
    }
}

bool Jail::Inhaftierung(ChatHandler * handler, Player * chr, std::string cname, uint32 jailtime, std::string jailreason, uint32 acc_id, std::string announce)
{
    time_t localtime = time(NULL);
    uint32 release = uint32(localtime + (jailtime * HOUR));

    if (!chr || !chr->isValid())
        return false;

    chr->SaveToDB();

    chr->m_Jailed = true;
    chr->m_JailRelease = release;
    chr->m_JailGrund = jailreason;
    chr->m_JailGMAcc = handler->GetSession()->GetAccountId();
    chr->m_JailGMChar = handler->GetSession()->GetPlayerName();
    chr->m_JailDauer = jailtime;
    chr->m_JailZeit = uint32(localtime);

    ++chr->m_JailAnzahl;

    chr->JailDatenSpeichern();

    handler->PSendSysMessage(LANG_JAIL_WAS_JAILED, cname.c_str(), jailtime);
    ChatHandler(chr).PSendSysMessage(LANG_JAIL_YOURE_JAILED, handler->GetSession()->GetPlayerName(), jailtime);
    ChatHandler(chr).PSendSysMessage(LANG_JAIL_REASON, handler->GetSession()->GetPlayerName(), jailreason.c_str());

    sWorld->SendServerMessage(SERVER_MSG_STRING, announce.c_str());

    // Nur wenn m_MaxJails gesetzt ist, hier hinein gehen!
    if (m_JailKonf.MaxJails && m_JailKonf.MaxJails == chr->m_JailAnzahl)
    {
        uint64 GUID = chr->GetGUID();

        if (m_JailKonf.DelChar)
        {
            chr->GetSession()->KickPlayer();
            chr = NULL; // chr wird durch KickPlayer() ungültig!
            Player::DeleteFromDB(GUID, acc_id);
        }

        if (m_JailKonf.BanAcc)
        {
            if (chr)
                BannAccount(acc_id, GUID_LOPART(GUID), chr);
            else
                BannAccount(acc_id, GUID_LOPART(GUID));
        }
    }
    return true;
}

bool Jail::Inhaftierung(ChatHandler * handler, uint32 guid, std::string cname, uint32 jailtime, std::string jailreason, uint32 acc_id, std::string announce)
{
    time_t localtime = time(NULL);
    uint32 release = uint32(localtime + (jailtime * HOUR));
    uint32 times = 0;
    JailEintragStruktur JES;

    JailMap::iterator itr = m_JailMap.find(guid);
    if (itr == m_JailMap.end()) // Kein Eintrag vorhanden
    {
        ++times;

        CharacterDatabase.PExecute("INSERT INTO `jail` (`guid`,`char`,`release`,`reason`,`times`,`gmacc`,`gmchar`,`lasttime`,`duration`) VALUES (%u,'%s',%u,'%s',%u,%u,'%s',%u,%u)",
            guid, cname.c_str(), release, jailreason.c_str(), times, handler->GetSession()->GetAccountId(), handler->GetSession()->GetPlayerName(), localtime, jailtime);

        JES.BTimes = 0;
        JES.CharName = cname;
        JES.Duration = jailtime;
        JES.GMAcc = handler->GetSession()->GetAccountId();
        JES.GMChar = handler->GetSession()->GetPlayerName();
        JES.Reason = jailreason;
        JES.Time = uint32(localtime);
        JES.Times = times;
        JES.Release = release;

        m_JailMap[guid] = JES;
    }
    else // Es gibt bereits einen Eintrag
    {
        times = ++itr->second.Times;

        CharacterDatabase.PExecute("UPDATE `jail` SET `release`=%u,`reason`='%s',`times`=%u,`gmacc`=%u,`gmchar`='%s',`lasttime`=%u,`duration`=%u WHERE `guid`=%u LIMIT 1",
            release, jailreason.c_str(), times, handler->GetSession()->GetAccountId(), handler->GetSession()->GetPlayerName(), localtime, jailtime, guid);

        itr->second.Release = release;
        itr->second.Reason = jailreason;
        itr->second.GMAcc = handler->GetSession()->GetAccountId();
        itr->second.GMChar = handler->GetSession()->GetPlayerName();
        itr->second.Time = uint32(localtime);
        itr->second.Duration = jailtime;
    }
    handler->PSendSysMessage(LANG_JAIL_WAS_JAILED, cname.c_str(), jailtime);
    sWorld->SendServerMessage(SERVER_MSG_STRING, announce.c_str());

    // Nur wenn m_MaxJails gesetzt ist, hier hinein gehen!
    if (m_JailKonf.MaxJails && m_JailKonf.MaxJails == times)
    {
        if (m_JailKonf.DelChar)
            Player::DeleteFromDB(guid, acc_id);

        if (m_JailKonf.BanAcc)
            BannAccount(acc_id, guid);
    }
    return true;
}

void Jail::BannAccount(uint32 acc_id, uint32 guid, Player * chr)
{
    uint32 btimes = 0;
    time_t localtime = time(NULL);
    uint32 banrelease = uint32(localtime + (m_JailKonf.BanDauer * HOUR));

    JailMap::iterator itr = m_JailMap.find(guid);
    if (itr != m_JailMap.end())
    {
        btimes = ++itr->second.BTimes;

        itr->second.Release = 0;
        itr->second.Reason = sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_BAN_REASON);
        itr->second.Times = 0;
        itr->second.GMAcc = m_JailKonf.GMAcc;
        itr->second.GMChar = m_JailKonf.GMChar;
        itr->second.Duration = m_JailKonf.BanDauer;
    }
    else
        btimes = 1;

    LoginDatabase.PExecute("REPLACE INTO `account_banned` (`id`,`bandate`,`unbandate`,`bannedby`,`banreason`) VALUES (%u,%u,%u,'%s','%s')",
        acc_id, localtime, banrelease, m_JailKonf.GMChar.c_str(), sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_BAN_REASON));

    // Wenn der Account gebannt wurde, müssen die Daten im Jail zurück gesetzt werden!
    // Um sehen zu können, warum sie zurück gesetzt wurden, tragen wir dafür die Banndaten ein. ;)
    CharacterDatabase.PExecute("UPDATE `jail` SET `release`=0,`reason`='%s',`times`=0,`gmacc`=%u,`gmchar`='%s',`duration`=%u,`btimes`=%u WHERE `guid`=%u LIMIT 1",
        sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_BAN_REASON), m_JailKonf.GMAcc, m_JailKonf.GMChar.c_str(), m_JailKonf.BanDauer, btimes, guid);

    if (chr)
    {
        chr->JailDatenSpeichern();
        chr->GetSession()->KickPlayer();
    }
}

void Jail::GildenhausWache(Player * chr)
{
    if (!m_JailKonf.Enabled)
        return;

    if (!chr || !chr->isValid() || !chr->IsInWorld() || chr->GetSession()->GetSecurity() > SEC_VETERAN)
        return;

    if (chr->GetMapId() != 1)
        return;

    if ((chr->GetPositionX() > 16185.0f && chr->GetPositionX() < 16348.0f) && (chr->GetPositionY() > 16171.0f && chr->GetPositionY() < 16403.0f))
        if (chr->GetGuildId() != sWorld->getIntConfig(CONFIG_GILDEN_ID))
        {
            time_t localtime = time(NULL);
            uint32 release = uint32(localtime + (12 * HOUR));

            chr->m_Jailed = true;
            chr->m_JailRelease = release;
            chr->m_JailGrund = "Aufenthalt im Gildenhaus-Bereich, ohne der Gilde anzugehören, die dieses zur Zeit besitzt.";
            chr->m_JailGMAcc = m_JailKonf.GMAcc;
            chr->m_JailGMChar = m_JailKonf.GMChar;
            chr->m_JailDauer = 12;
            chr->m_JailZeit = uint32(localtime);

            ++chr->m_JailAnzahl;

            chr->JailDatenSpeichern();

            ChatHandler(chr).PSendSysMessage(LANG_JAIL_YOURE_JAILED, m_JailKonf.GMChar.c_str(), 12);
            ChatHandler(chr).PSendSysMessage(LANG_JAIL_REASON, m_JailKonf.GMChar.c_str(), chr->m_JailGrund.c_str());

            std::string announce1;
            std::string announce2;

            announce1.append("Der Charakter ");
            announce1.append(chr->GetName());
            announce1.append(" wurde von ");
            announce1.append(m_JailKonf.GMChar.c_str());
            announce1.append(" eingebuchtet.");
            announce2.append("Der Grund: ");
            announce2.append(chr->m_JailGrund.c_str());

            sWorld->SendServerMessage(SERVER_MSG_STRING, announce1.c_str());
            sWorld->SendServerMessage(SERVER_MSG_STRING, announce2.c_str());

            // Nur wenn m_MaxJails gesetzt ist, hier hinein gehen!
            if (m_JailKonf.MaxJails && m_JailKonf.MaxJails == chr->m_JailAnzahl)
            {
                uint64 GUID = chr->GetGUID();
                uint32 acc = chr->GetSession()->GetAccountId();

                if (m_JailKonf.DelChar)
                {
                    chr->GetSession()->KickPlayer();
                    chr = NULL; // chr wird durch KickPlayer() ungültig!
                    Player::DeleteFromDB(GUID, acc);
                }

                if (m_JailKonf.BanAcc)
                {
                    if (chr)
                        BannAccount(acc, GUID_LOPART(GUID), chr);
                    else
                        BannAccount(acc, GUID_LOPART(GUID));
                }
            }
        }
}

char const * Jail::fmtstring(char const * format, ...)
{
    va_list     argptr;
    static char temp_buffer[MAX_FMT_STRING];
    static char string[MAX_FMT_STRING];
    static int  index = 0;
    char        *buf;
    int         len;

    va_start(argptr, format);
    vsnprintf(temp_buffer,MAX_FMT_STRING, format, argptr);
    va_end(argptr);

    len = strlen(temp_buffer);

    if (len >= MAX_FMT_STRING)
        return sObjectMgr->GetTrinityStringForDBCLocale(LANG_JAIL_FMTSTR);

    if (len + index >= MAX_FMT_STRING-1)
        index = 0;

    buf = &string[index];
    memcpy(buf, temp_buffer, len+1);

    index += len + 1;

    return buf;
}
