// Copyright (C) 2008-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de

#ifndef _JAIL_H
#define _JAIL_H

#include "Chat.h"

#define SPELL_STACK 7355

class Jail
{
    friend class ACE_Singleton<Jail, ACE_Null_Mutex>;
    Jail();
    ~Jail();

private:
    uint32 m_MaxJails;  // Beim erreichen dieses Wertes, wird der Charakter gelöscht / der Account gebannt.
    uint32 m_MaxDauer;  // Die maximale Dauer für einen Knastausenthalt.
    uint32 m_MinGrund;  // Minimale Zeichenlänge für den Jailgrund.
    uint32 m_Radius;    // Radius in dem der Knastbruder sich bewegen darf.

    uint32 m_MapAlly;   // Knastkarte für die Allies
    uint32 m_MapHorde;  // Knastkarte für die Horde

    uint32 m_BanDauer;  // Nach dieser Zeit (Std.) wird ein durch das Jail gebannter Account wieder freigeschaltet.

    float m_AllyPosX;   // Koordinaten für den Allyknast
    float m_AllyPosY;
    float m_AllyPosZ;
    float m_AllyPosO;

    float m_HordePosX;  // Koordinaten für den Hordeknast
    float m_HordePosY;
    float m_HordePosZ;
    float m_HordePosO;

    bool m_DelChar;     // Charakter löschen, wenn m_MaxJails erreicht wird?
    bool m_BanAcc;      // Account bannen, wenn m_MaxJails erreicht wird?
    bool m_WarnUser;    // Spieler warnen, wenn er nur einen Jail von der Charakterlöschung / Accountbannung entfernt ist?

public:
    bool LadeKonfiguration(bool reload = false);

    // Kommandos aus jail_commandscript bearbeiten
    bool InfoKommando(ChatHandler * handler);
    bool PInfoKommando(ChatHandler * handler, const char * args);
    bool ArrestKommando(ChatHandler * handler, const char * args);
    bool ReleaseKommando(ChatHandler * handler, const char * args);
    bool ResetKommando(ChatHandler * handler, const char * args);
    bool ReloadKommando() { return LadeKonfiguration(true); };

    Position HoleAllyKnastPos();
    Position HoleHordeKnastPos();

    const uint32 HoleAllyKnastKarte() { return m_MapAlly; };
    const uint32 HoleHordeKnastKarte() { return m_MapHorde; };

    void Kontrolle(Player * pPlayer, bool update = false);
    void SendeWarnung(Player * pPlayer);
};

#define sJail ACE_Singleton<Jail, ACE_Null_Mutex>::instance()

#endif
