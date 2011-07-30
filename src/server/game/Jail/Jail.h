// Copyright (C) 2008-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de

#ifndef _JAIL_H
#define _JAIL_H

#include <Chat.h>

struct JailKonfStruktur
{
    uint32 MaxJails;    // Beim erreichen dieses Wertes, wird der Charakter gelöscht / der Account gebannt.
    uint32 MaxDauer;    // Die maximale Dauer für einen Knastausenthalt.
    uint32 MinGrund;    // Minimale Zeichenlänge für den Jailgrund.
    uint32 MapAlly;     // Knastkarte für die Allies
    uint32 MapHorde;    // Knastkarte für die Horde
    uint32 BanDauer;    // Nach dieser Zeit (Std.) wird ein durch das Jail gebannter Account wieder freigeschaltet.
    uint32 Radius;      // Radius in dem der Knastbruder sich bewegen darf.
    uint32 GMAcc;       // Account der zum Bannen genutzt wird
    uint32 Amnestie;    // Monate (nach dem letzten Vorfall), nach denen die Jaileinträge gelöscht werden.

    Position AllyPos;   // Koordinaten für den Allyknast
    Position HordePos;  // Koordinaten für den Hordeknast

    bool WarnUser;      // Spieler warnen, wenn er nur einen Jail von der Charakterlöschung / Accountbannung entfernt ist?
    bool DelChar;       // Charakter löschen, wenn m_MaxJails erreicht wird?
    bool BanAcc;        // Account bannen, wenn m_MaxJails erreicht wird?
    bool Enabled;       // Ist das Jail aktiviert?

    std::string GMChar; // Charname der zum Bannen genutzt wird
};

struct JailEintragStruktur
{
    uint32 Release;         // Entlassungszeit
    uint32 Times;           // Anzahl der Inhaftierungen
    uint32 BTimes;          // Anzahl der Bannungen des Accounts, aufgrund von diesem Char
    uint32 Duration;        // Dauer der Inhaftierung
    uint32 GMAcc;           // Account des GM
    uint32 Time;            // Inhaftierungszeit

    std::string CharName;   // Charaktername des Häftlings
    std::string GMChar;     // Charaktername des GM
    std::string Reason;     // Grund der Inhaftierung

    uint32 account;         // Nicht im Jailtable vorhanden - dient nur zu internen Zwecken!
};

typedef UNORDERED_MAP<uint32, JailEintragStruktur > JailMap;

class Jail
{
    friend class ACE_Singleton<Jail, ACE_Null_Mutex>;
    Jail();
    ~Jail();

private:
    JailKonfStruktur    m_JailKonf; // Konfiguration des Jails
    JailMap             m_JailMap;  // UNORDERED_MAP aller Jaileinträge

    void Amnestie(); // Prüfen ob jemand Amnestie bekommen muss.
    bool SendeInaktiv(ChatHandler * handler);
    bool Inhaftierung(ChatHandler * handler, Player * chr, std::string cname, uint32 jailtime, std::string jailreason, uint32 acc_id, std::string announce);
    bool Inhaftierung(ChatHandler * handler, uint32 guid, std::string cname, uint32 jailtime, std::string jailreason, uint32 acc_id, std::string announce);
    void BannAccount(uint32 acc_id, uint32 guid, Player * chr = NULL);
    char const * fmtstring(char const * format, ...);

public:
    // Konfiguration laden
    bool LadeKonfiguration(bool reload = false);
    // Inhaftierungen laden
    bool Init(bool reload = false);
    // Knast auf nicht mehr existierende Charaktere prüfen
    void KnastAufraeumen();
    // Jede Minute schauen, ob jemand entlassen werden muss.
    void Update();

    // Kommandos aus jail_commandscript bearbeiten
    bool InfoKommando(ChatHandler * handler);
    bool GotoKommando(ChatHandler * handler, const char * args);
    bool PInfoKommando(ChatHandler * handler, const char * args);
    bool ArrestKommando(ChatHandler * handler, const char * args);
    bool ReleaseKommando(ChatHandler * handler, const char * args, bool reset = false);
    bool ResetKommando(ChatHandler * handler, const char * args, bool force = false);
    bool ReloadKommando(ChatHandler * handler);
    bool EnableKommando(ChatHandler * handler);
    bool DisableKommando(ChatHandler * handler);

    Position HoleAllyKnastPos() const { return m_JailKonf.AllyPos; }
    Position HoleHordeKnastPos() const { return m_JailKonf.HordePos; }

    uint32 HoleAllyKnastKarte() const { return m_JailKonf.MapAlly; }
    uint32 HoleHordeKnastKarte() const { return m_JailKonf.MapHorde; }

    void Kontrolle(Player * pPlayer, bool update = false);
    void SendeWarnung(Player * pPlayer);

    JailMap const & HoleJailMap() const { return m_JailMap; }
    void AktualisiereJailMap(uint32 guid, JailEintragStruktur & JES) { m_JailMap[guid] = JES; };

    void GildenhausWache(Player * chr);
};

#define sJail ACE_Singleton<Jail, ACE_Null_Mutex>::instance()

#endif
