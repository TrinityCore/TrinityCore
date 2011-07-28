// Copyright 2009-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de

#include "OutdoorPvPTW.h"
#include "Group.h"
#include "GroupMgr.h"
#include "MapManager.h"
#include "GameObject.h"

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Tausendwinter
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Destructor
Tausendwinter::~Tausendwinter()
{
    delete m_Raid[TEAM_ALLIANCE];
    delete m_Raid[TEAM_HORDE];
}

// Initialisierung
Tausendwinter::Tausendwinter()
{
    m_TypeId = OUTDOOR_PVP_TW;

    // Verteidigerteam laden / zufällig setzen (beim ersten Realmstart z.B.)
    m_VerteidigerTeamId = TeamId(sWorld->getWorldState(WS_TW_BESITZER));
    if (m_VerteidigerTeamId == TEAM_NEUTRAL)
        m_VerteidigerTeamId = TeamId(urand(TEAM_ALLIANCE, TEAM_HORDE));

    m_Kampf = bool(sWorld->getWorldState(WS_TW_KAMPF));

    m_Zeit = uint32(sWorld->getWorldState(WS_TW_ZEIT));
    if (!m_Zeit) // Wenn keine Zeit geladen wurde, die standard Startzeit nehmen
        m_Zeit = uint32(sWorld->getIntConfig(CONFIG_TW_STARTZEIT));

    m_SpeicherIntervall = uint32(sWorld->getIntConfig(CONFIG_TW_SPEICHER_INTERVALL));

    m_TeamZeit[TEAM_ALLIANCE] = 0;
    m_TeamZeit[TEAM_HORDE] = 0;
    m_ZerstoerteTuerme[TEAM_ALLIANCE] = 0;
    m_ZerstoerteTuerme[TEAM_HORDE] = 0;
    m_AnzahlWerkstaetten[TEAM_ALLIANCE] = 0;
    m_AnzahlWerkstaetten[TEAM_HORDE] = 0;

    m_ErfolgsZeit = 0; // TW_ERFOLG_TW_ZUM_TROTZ - Zeit wird beim Starten des Kampfes gesetzt
    m_PvPCheckZeit = TW_PVP_CHECKZEIT;
    m_Countdown = TW_COUNTDOWN_ZEIT; // Weltnachricht
    m_SiegAuraZeit = TW_SIEGAURA_ZEIT; // Entfernen der Siegaura
    m_HartnaeckigkeitsStapel = 0;

    m_Relikt = NULL;
    m_Festungstuer = NULL;

    m_Raid[TEAM_ALLIANCE] = NULL;
    m_Raid[TEAM_HORDE] = NULL;

    m_VerteidigerWechsel = false;
    m_CmdStart = false;
    m_CmdStop = false;
    m_CmdWechsel = false;
    m_WarnungDone = false;
    m_Fortsetzung = m_Kampf;

    // NPC Paare laden
    LadeTeamPaare(m_CrTeamPaarMap, NPCPaare);
    // GO Displaypaare laden
    LadeTeamPaare(m_GOTeamPaarMap, GODisplayPaare);
}

// Alle Daten sammeln / vorbereiten und übergeben, am Schluss Zone registrieren
bool Tausendwinter::SetupOutdoorPvP()
{
    // Tausendwinter ist nicht aktiviert -> Setup abbrechen
    if (!sWorld->getBoolConfig(CONFIG_TW_AKTIVIERT))
    {
        sLog->outError("TAUSENDWINTER: TW IST DEAKTIVIERT!");
        NotfallAbschaltung();
        return false;
    }

    // Alle NPC und Gameobjekt GUIDs sowie IDs (die in Tausendwinter gespawnt sind) laden
    QueryResult CrResult = WorldDatabase.PQuery("SELECT `guid`,`id`,`faction_A` FROM `creature`,`creature_template` WHERE "
        "`creature`.map=%u AND `creature`.position_x>%f AND `creature`.position_y>%f AND `creature`.position_x<%f AND `creature`.position_y<%f "
        "AND `creature`.id=`creature_template`.entry", TW_KARTE, TWKoords[MinX], TWKoords[MinY], TWKoords[MaxX], TWKoords[MaxY]);
    QueryResult GOResult = WorldDatabase.PQuery("SELECT `guid`,`id` FROM `gameobject`,`gameobject_template` WHERE "
        "`gameobject`.map=%u AND `gameobject`.position_x>%f AND `gameobject`.position_y>%f AND `gameobject`.position_x<%f AND `gameobject`.position_y<%f "
        "AND `gameobject`.id=`gameobject_template`.entry", TW_KARTE, TWKoords[MinX], TWKoords[MinY], TWKoords[MaxX], TWKoords[MaxY]);

    // Dalaran Portale laden
    QueryResult DalaranResult = WorldDatabase.PQuery("SELECT `guid` FROM `gameobject` WHERE `id`=%u", TW_GO_PORTAL_NACH_TAUSENDWINTER);

    ErstelleDalaranPortalSet(DalaranResult);

    if (!CrResult)
    {
        sLog->outError("TAUSENDWINTER: Kann keine NPCs innerhalb der Koordianten von TW finden! Deaktiviere Tausendwintersee.");
        NotfallAbschaltung();
        return false;
    }

    if (!GOResult)
    {
        sLog->outError("TAUSENDWINTER: Kann keine GOs innerhalb der Koordianten von TW finden! Deaktiviere Tausendwintersee.");
        NotfallAbschaltung();
        return false;
    }

    // Listen erstellen, aus den Resultaten
    if (!ErstelleNPCMap(CrResult) || !ErstelleGOMap(GOResult))
    {   // Wichtige NPCs / GOs sind nicht gespawnt!
        sLog->outError("TAUSENDWINTER: KANN NPC UND/ODER GO MAP NICHT ERSTELLEN!");
        NotfallAbschaltung();
        return false;
    }

    // CapturePoints / Werkstätten etc. erstellen
    if (!ErstelleGOStatusMap())
    {
        sLog->outError("TAUSENDWINTER: Es ist ein Fehler beim Erstellen der CapturePoints (Werkstätten etc.) aufgetreten! Deaktiviere Tausendwinter.");
        NotfallAbschaltung();
        return false;
    }

    // Friedhöfe zuordnen / erstellen
    OrdneFriedhoefeZu();

    // Tausendwinter Events aktualisieren
    sGameEventMgr->StopEvent(GameEventTausendwinterVerteidiger[HoleAngreiferTeamId()], true);
    sGameEventMgr->StartEvent(GameEventTausendwinterVerteidiger[m_VerteidigerTeamId], true);

    // Und zum Schluss "bei Mama anmelden"... :-)
    RegisterZone(NORDEND_TAUSENDWINTER);

    // Damit beim ersten Start alles seine Richtigkeit hat
    if (!m_Fortsetzung)
        Reset();

    return true;
}

// Das Herzstück :-)
bool Tausendwinter::Update(uint32 diff)
{
    if (m_Fortsetzung)
        StarteKampf();

    // Die Geisterführer sind immer aktiv, und Geistheiler werden in TW nicht genutzt!
    BearbeiteWiederbelebungen(diff);

    // Die Zeit muss immer gespeichert werden!
    if (m_SpeicherIntervall <= diff)
        Speichern();
    else
        m_SpeicherIntervall -= diff;

    // Da es aus irgendwelchen Gründen (irgendwie) möglich ist, dass Spieler PvP ausschalten können, müssen wir dies überprüfen!
    // TODO: In den Katakomben des Core nach dem Grund für diese PvPFlag Fehler suchen!
    if (m_PvPCheckZeit <= diff)
        PvPCheck();
    else
        m_PvPCheckZeit -= diff;

    if (!sWorld->getBoolConfig(CONFIG_TW_AKTIVIERT))
        return false;

    if (m_CmdStart)
    {
        OutdoorPvP::m_sendUpdate = false;

        if (m_Kampf)
            BeendeKampf();

        StarteKampf();
        m_CmdStart = false;

        OutdoorPvP::m_sendUpdate = true;
        SendeWeltstatus();
        Speichern();
    }

    if (m_CmdStop)
    {
        OutdoorPvP::m_sendUpdate = false;

        if (m_Kampf)
            BeendeKampf();

        Reset(true);
        m_CmdStop = false;

        OutdoorPvP::m_sendUpdate = true;
        SendeWeltstatus();
        Speichern();
    }

    if (m_CmdWechsel)
    {
        OutdoorPvP::m_sendUpdate = false;

        m_VerteidigerTeamId = OTHER_TEAM(m_VerteidigerTeamId);

        if (m_Kampf)
            BeendeKampf();

        Reset(true);
        m_CmdWechsel = false;

        OutdoorPvP::m_sendUpdate = true;
        SendeWeltstatus();
        Speichern();
    }

    // Siegaura löschen
    if (m_SiegAuraZeit && m_SiegAuraZeit <= diff)
    {
        for (PlayerSet::const_iterator iter = m_players[m_VerteidigerTeamId].begin(); iter != m_players[m_VerteidigerTeamId].end(); ++iter)
            (*iter)->RemoveAurasDueToSpell(SPELL_SIEG_AURA);

        m_SiegAuraZeit = 0;
    }
    else
        m_SiegAuraZeit -= diff;

    // Hier wird dann die eigentlich Arbeit gemacht...
    if (m_Zeit > diff)
    {
        m_Zeit -= diff;

        if (m_Kampf)
        {
            OutdoorPvP::Update(diff); // CPs aktualisieren

            m_ErfolgsZeit -= diff;

            if (!m_WarnungDone && m_Zeit <= TW_SIEGWARNUNGSZEIT)
            {
                if (HoleAngreiferTeamId() == TEAM_ALLIANCE)
                    SpieleSoundFuerTeam(TEAM_ALLIANCE, TW_SOUND_NAHE_SIEG_WARNUNG_ALLY);
                else
                    SpieleSoundFuerTeam(TEAM_HORDE, TW_SOUND_NAHE_SIEG_WARNUNG_HORDE);

                m_WarnungDone = true;
            }
        }
        else
        {
            // Weltnachricht Kampfbegin in...
            if (sWorld->getBoolConfig(CONFIG_TW_WELTCOUNTDOWN) && m_Countdown && m_Zeit <= m_Countdown)
            {
                sWorld->SendWorldText(LANG_TAUSENDWINTER_KAMPF_COUNTDOWN, secsToTimeString(HoleZeitInSekunden()).c_str());

                if (m_Countdown > 300000)
                    m_Countdown -= 300000;
                else if (m_Countdown > 60000)
                    m_Countdown -= 60000;
                else
                    m_Countdown = 0;
            }
        }
    }
    else
    {
        OutdoorPvP::m_sendUpdate = false;

        if (m_VerteidigerWechsel)
        {
            m_VerteidigerWechsel = false;
            m_VerteidigerTeamId = OTHER_TEAM(m_VerteidigerTeamId);

            sWorld->SendZoneText(NORDEND_TAUSENDWINTER, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WECHSEL_DES_BESITZERS),
                m_VerteidigerTeamId == TEAM_ALLIANCE ? sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_ALLY) : sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_HORDE)));

            if (sWorld->getBoolConfig(CONFIG_TW_WELTSIEGNACHRICHT))
                sWorld->SendWorldText(LANG_TAUSENDWINTER_FESTUNG_UEBERNOMMEN,
                m_VerteidigerTeamId == TEAM_ALLIANCE ? sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_ALLY) : sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_HORDE));
        }
        else if (m_Kampf)
        {
            sWorld->SendZoneText(NORDEND_TAUSENDWINTER, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_ERFOLGREICH_VERTEIDIGT),
                m_VerteidigerTeamId == TEAM_ALLIANCE ? sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_ALLY) : sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_HORDE)));

            if (sWorld->getBoolConfig(CONFIG_TW_WELTSIEGNACHRICHT))
                sWorld->SendWorldText(LANG_TAUSENDWINTER_ERFOLGREICH_VERTEIDIGT,
                m_VerteidigerTeamId == TEAM_ALLIANCE ? sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_ALLY) : sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_HORDE));
        }

        if (m_Kampf)
            BeendeKampf();
        else
            StarteKampf();

        OutdoorPvP::m_sendUpdate = true;

        SendeWeltstatus();

        Speichern();
    }
    AktualisiereZeit();

    return false;
}

void Tausendwinter::ProcessEvent(WorldObject * obj, uint32 eventId)
{
    GameObject * go = obj->ToGameObject();
    if (!go)
        return;

    std::string ZonenNachricht;
    std::string strGODmgTeam = go->GetGOInfo()->faction == Fraktionen[TEAM_ALLIANCE] ? sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_HORDE) : sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_ALLY);

    switch(eventId)
    {   // Das Relikt
        case TW_EVENT_RELIKT_DER_TITANEN_KLICK:
            // Nur im Kampf, und wenn die Tür zur Kammer zerstört wurde behandeln!
            if (m_Kampf && m_Festungstuer && m_Festungstuer->m_SchadensStatus == ZERSTOERT)
            {
                ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_FESTUNG_UEBERNOMMEN),
                    HoleAngreiferTeamId() == TEAM_ALLIANCE ? sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_ALLY) : sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_HORDE));

                m_VerteidigerWechsel = true;
                m_Zeit = 0; // Kampf beenden
            }
            break;

        // Das Festungstor (Front)
        case TW_EVENT_FESTUNGSTOR_BESCHAEDIGT:
            ZonenNachricht = sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_FESTUNGSTOR_BESCHAEDIGT);
            break;

        case TW_EVENT_FESTUNGSTOR_ZERSTOERT:
            ZonenNachricht = sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_FESTUNGSTOR_ZERSTOERT);
            break;

        // Die Festungstür (Reliktkammer)
        case TW_EVENT_FESTUNGSTUER_BESCHAEDIGT:
            if (m_Festungstuer)
            {
                if (m_VerteidigerTeamId == TEAM_ALLIANCE)
                    SpieleSoundFuerTeam(TEAM_ALLIANCE, TW_SOUND_NAHE_SIEG_WARNUNG_ALLY);
                else
                    SpieleSoundFuerTeam(TEAM_HORDE, TW_SOUND_NAHE_SIEG_WARNUNG_HORDE);

                m_Festungstuer->m_SchadensStatus = BESCHAEDIGT;
                m_Festungstuer->m_GameObject = go;
            }
            ZonenNachricht = sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_FESTUNGSTUER_BESCHAEDIGT);
            break;

        case TW_EVENT_FESTUNGSTUER_ZERSTOERT:
            if (m_Festungstuer)
            {
                m_Festungstuer->m_SchadensStatus = ZERSTOERT;
                m_Festungstuer->m_GameObject = go;
            }
            ZonenNachricht = sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_FESTUNGSTUER_ZERSTOERT);
            break;

        // Die Festungstürme
        case TW_EVENT_FESTUNGSTURM_NW_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_FESTUNG_NW)).c_str());
            break;
        case TW_EVENT_FESTUNGSTURM_NW_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_FESTUNG_NW)).c_str());
            break;
        case TW_EVENT_FESTUNGSTURM_SW_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_FESTUNG_SW)).c_str());
            break;
        case TW_EVENT_FESTUNGSTURM_SW_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_FESTUNG_SW)).c_str());
            break;
        case TW_EVENT_FESTUNGSTURM_SO_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_FESTUNG_SO)).c_str());
            break;
        case TW_EVENT_FESTUNGSTURM_SO_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_FESTUNG_SO)).c_str());
            break;
        case TW_EVENT_FESTUNGSTURM_NO_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_FESTUNG_NO)).c_str());
            break;
        case TW_EVENT_FESTUNGSTURM_NO_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_FESTUNG_NO)).c_str());
            break;

        // Die südlichen Türme
        case TW_EVENT_WINTERSTURZTURM_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_WINTER)).c_str());
            break;
        case TW_EVENT_WINTERSTURZTURM_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_WINTER)).c_str());
            break;
        case TW_EVENT_FLAMMENAUGENTURM_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_FLAMMEN)).c_str());
            break;
        case TW_EVENT_FLAMMENAUGENTURM_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_FLAMMEN)).c_str());
            break;
        case TW_EVENT_SCHATTENBLICKTURM_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_SCHATTEN)).c_str());
            break;
        case TW_EVENT_SCHATTENBLICKTURM_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURM_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_TURMNAME_SCHATTEN)).c_str());
            break;

        // Die Mauern
        case TW_EVENT_WALL_1_BESCHAEDIGT:
        case TW_EVENT_WALL_2_BESCHAEDIGT:
        case TW_EVENT_WALL_3_BESCHAEDIGT:
            ZonenNachricht = sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_FESTUNG_UNTER_BESCHUSS);
            break;

        case TW_EVENT_WALL_1_ZERSTOERT:
        case TW_EVENT_WALL_2_ZERSTOERT:
        case TW_EVENT_WALL_3_ZERSTOERT:
            ZonenNachricht = sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_MAUER_ZERSTOERT);
            break;

        // Die Festungswälle
        case TW_EVENT_FESTUNGSWALL_1_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_2_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_3_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_4_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_5_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_6_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_7_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_8_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_9_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_10_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_11_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_12_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_13_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_14_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_15_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_16_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_17_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_18_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_19_BESCHAEDIGT:
        case TW_EVENT_FESTUNGSWALL_20_BESCHAEDIGT:
            ZonenNachricht = sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_FESTUNG_UNTER_BESCHUSS);
            break;

        case TW_EVENT_FESTUNGSWALL_1_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_2_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_3_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_4_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_5_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_6_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_7_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_8_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_9_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_10_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_11_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_12_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_13_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_14_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_15_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_16_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_17_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_18_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_19_ZERSTOERT:
        case TW_EVENT_FESTUNGSWALL_20_ZERSTOERT:
            ZonenNachricht = sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_FESTUNGSWALL_ZERSTOERT);
            break;

        // Die Werkstätten
        case TW_EVENT_WERKSTATT_FESTUNG_W_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATT_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATTNAME_FESTUNG_W)).c_str(), strGODmgTeam.c_str());
            break;
        case TW_EVENT_WERKSTATT_FESTUNG_W_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATT_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATTNAME_FESTUNG_W)).c_str(), strGODmgTeam.c_str());
            break;
        case TW_EVENT_WERKSTATT_FESTUNG_O_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATT_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATTNAME_FESTUNG_O)).c_str(), strGODmgTeam.c_str());
            break;
        case TW_EVENT_WERKSTATT_FESTUNG_O_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATT_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATTNAME_FESTUNG_O)).c_str(), strGODmgTeam.c_str());
            break;
        case TW_EVENT_WERKSTATT_TEMPEL_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATT_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATTNAME_TEMPEL)).c_str(), strGODmgTeam.c_str());
            break;
        case TW_EVENT_WERKSTATT_TEMPEL_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATT_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATTNAME_TEMPEL)).c_str(), strGODmgTeam.c_str());
            break;
        case TW_EVENT_WERKSTATT_RING_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATT_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATTNAME_RING)).c_str(), strGODmgTeam.c_str());
            break;
        case TW_EVENT_WERKSTATT_RING_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATT_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATTNAME_RING)).c_str(), strGODmgTeam.c_str());
            break;
        case TW_EVENT_WERKSTATT_WESTFUNK_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATT_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATTNAME_WESTFUNK)).c_str(), strGODmgTeam.c_str());
            break;
        case TW_EVENT_WERKSTATT_WESTFUNK_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATT_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATTNAME_WESTFUNK)).c_str(), strGODmgTeam.c_str());
            break;
        case TW_EVENT_WERKSTATT_OSTFUNK_BESCHAEDIGT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATT_SCHADEN), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATTNAME_OSTFUNK)).c_str(), strGODmgTeam.c_str());
            break;
        case TW_EVENT_WERKSTATT_OSTFUNK_ZERSTOERT:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATT_ZERSTOERT), ZonenNachricht.append(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WERKSTATTNAME_OSTFUNK)).c_str(), strGODmgTeam.c_str());
            break;

        // Das Event wurde nicht behandelt -> Fehler ausgeben!
        default:
            ZonenNachricht = fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_STANDARD_EVENT_AUSGABE), eventId);
            sLog->outError("TAUSENDWINTER: Das Ereignis (EventID: %u) wurde nicht behandelt!", eventId);
            break;
    }

    // Die Zonennachricht zum entsprechendem Event an TW senden
    if (ZonenNachricht.size())
        sWorld->SendZoneText(NORDEND_TAUSENDWINTER, ZonenNachricht.c_str());

    if (go->GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
    {
        GOStatusMap::const_iterator iter = m_GOStatus.find(go->GetDBTableGUIDLow());
        if (iter == m_GOStatus.end())
            return;

        GOStatus * status = iter->second;
        if (!status || !status->m_GameObject)
            return;

        if (eventId == go->GetGOInfo()->building.damagedEvent)
        {
            status->m_SchadensStatus = BESCHAEDIGT;

            switch(status->m_Typ)
            {
                case WALL:
                    break;
                case WERKSTATT:
                    break;
                case TURM:
                    ++m_BeschaedigteTuerme[status->HoleTeamId()];
                    // TODO: Workaround für den Bug, dass nach dem damagedEvent die GOs (PoIs) keinen Schaden mehr bekommen! :-(
                    // TODO: Unbedingt den Grund für diesen Fehler finden!!!
                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED);
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                    go->SetUInt32Value(GAMEOBJECT_DISPLAYID, go->GetGOInfo()->building.destroyedDisplayId);
                    go->EventInform(go->GetGOInfo()->building.destroyedEvent);
                    break;
                case TOR:
                    break;
                case TUER:
                    // TODO: Workaround für den Bug, dass nach dem damagedEvent die GOs (PoIs) keinen Schaden mehr bekommen! :-(
                    // TODO: Unbedingt den Grund für diesen Fehler finden!!!
                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED);
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                    go->SetUInt32Value(GAMEOBJECT_DISPLAYID, go->GetGOInfo()->building.destroyedDisplayId);
                    go->EventInform(go->GetGOInfo()->building.destroyedEvent);
                    break;
            }
        }
        else if (eventId == go->GetGOInfo()->building.destroyedEvent)
        {
            status->m_SchadensStatus = ZERSTOERT;

            // Öffnen der unsichtbaren Kollisionen, beim "Tot" der Festungstür
            if (m_Festungstuer && m_Festungstuer->m_GameObject && status->m_GameObject->GetEntry() == m_Festungstuer->m_GameObject->GetEntry())
            {
                uint8 cnt = 0;
                for (GOMap::const_iterator iter = m_GOMap.begin(); iter != m_GOMap.end(); ++iter)
                    if ((*iter).second->m_GameObject)
                    {
                        switch((*iter).second->m_ID)
                        {
                            case TW_GO_KOLLISIONSWAND01:
                            case TW_GO_KOLLISIONSWAND:
                                (*iter).second->m_GameObject->SetGoState(GO_STATE_ACTIVE);
                                ++cnt;
                                break;
                        }
                    }
                if (cnt < 2)
                    sLog->outError("TAUSENDWINTER: Es konnten nicht beide unsichtbaren Wände im Eingang zum Relikt geöffnet werden!");
            }

            switch(status->m_Typ)
            {
                case WALL:
                    break;

                case WERKSTATT:
                    AktualisiereWerkstattAnzahl(status->HoleTeamId(), false);
                    break;

                case TURM:
                    --m_BeschaedigteTuerme[status->HoleTeamId()];
                    ++m_ZerstoerteTuerme[status->HoleTeamId()];

                    if (status->HoleTeamId() == OTHER_TEAM(m_VerteidigerTeamId))
                    {
                        OutdoorPvP::TeamCastSpell(OTHER_TEAM(m_VerteidigerTeamId), -SPELL_TURMKONTROLLE);
                        OutdoorPvP::TeamCastSpell(m_VerteidigerTeamId, -SPELL_TURMKONTROLLE);

                        uint32 AngreiferStapel = 3 - m_ZerstoerteTuerme[OTHER_TEAM(m_VerteidigerTeamId)];

                        if (m_ZerstoerteTuerme[OTHER_TEAM(m_VerteidigerTeamId)])
                        {
                            for (PlayerSet::iterator iter = m_players[m_VerteidigerTeamId].begin(); iter != m_players[m_VerteidigerTeamId].end(); ++iter)
                                if ((*iter) && (*iter)->getLevel() >= TW_MINIMUM_LEVEL)
                                    (*iter)->SetAuraStack(SPELL_TURMKONTROLLE, (*iter), m_ZerstoerteTuerme[OTHER_TEAM(m_VerteidigerTeamId)]);
                        }

                        if (AngreiferStapel)
                        {
                            for (PlayerSet::iterator iter = m_players[OTHER_TEAM(m_VerteidigerTeamId)].begin(); iter != m_players[OTHER_TEAM(m_VerteidigerTeamId)].end(); ++iter)
                                if ((*iter) && (*iter)->getLevel() >= TW_MINIMUM_LEVEL)
                                    (*iter)->SetAuraStack(SPELL_TURMKONTROLLE, (*iter), AngreiferStapel);
                        }
                        else
                        {
                            if (m_Zeit < 600000)
                                m_Zeit = 0;
                            else
                                m_Zeit = m_Zeit - 600000; // - 10 mins
                        }
                    }
                    break;

                case TOR:
                    break;

                case TUER:
                    break;
            }
            SendeStatusAenderung(status);
        }
        Speichern();
    }
}

// GO Daten aktualisieren
void Tausendwinter::AktualisiereGO(GameObject * pGO)
{
    if (!pGO)
        return;

    switch(pGO->GetGOInfo()->displayId)
    {
        case TW_GO_DISPLAY_KOLLISION:
            if (m_Kampf && m_Festungstuer && m_Festungstuer->m_SchadensStatus != ZERSTOERT)
                pGO->SetGoState(GO_STATE_READY);
            break;

        case TW_GO_DISPLAY_TELEPORTER:
            pGO->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[m_VerteidigerTeamId]);
            pGO->UpdateObjectVisibility();
            break;

        case TW_GO_DISPLAY_RELIKT:
            pGO->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[OTHER_TEAM(m_VerteidigerTeamId)]);
            pGO->UpdateObjectVisibility();
            break;

        case TW_GO_DISPLAY_WALL:
        case TW_GO_DISPLAY_FESTUNGSWALL:
        case TW_GO_DISPLAY_FESTUNGSTUERME:
        case TW_GO_DISPLAY_FESTUNGSTOR:
        case TW_GO_DISPLAY_FESTUNGSTUER:
            pGO->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[m_VerteidigerTeamId]);
            pGO->UpdateObjectVisibility();
            break;

        case TW_GO_DISPLAY_TUERME:
            pGO->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[OTHER_TEAM(m_VerteidigerTeamId)]);
            pGO->UpdateObjectVisibility();
            break;

        case TW_GO_DISPLAY_WERKSTATT:
            if (TausendwinterCapturePoint * Werkstatt = HoleWerkstatt(pGO->GetDBTableGUIDLow()))
                pGO->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[Werkstatt->m_GOStatus->HoleTeamId()]);
            else if (IstInDerFestung(pGO))
            {
                pGO->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[m_VerteidigerTeamId]);
                pGO->UpdateObjectVisibility();
            }
            break;
    }

    TeamPaarMap::const_iterator iter = m_GOTeamPaarMap.find(pGO->GetGOInfo()->displayId);
    if (iter != m_GOTeamPaarMap.end())
    {
        pGO->SetUInt32Value(GAMEOBJECT_DISPLAYID, m_VerteidigerTeamId == TEAM_ALLIANCE ? iter->second : iter->first);
        pGO->UpdateObjectVisibility();
    }
}

// NPC Daten aktualisieren
void Tausendwinter::AktualisiereNPC(Creature * pCr)
{
    if (!pCr)
        return;

    switch(HoleNPCTyp(pCr->GetEntry()))
    {
        case TW_NPC_TYP_WACHE:
            pCr->SetVisible(m_Kampf ? false : true);
            pCr->SetReactState(m_Kampf ? REACT_PASSIVE : REACT_AGGRESSIVE);
            {
                TeamPaarMap::const_iterator iter = m_CrTeamPaarMap.find(pCr->GetCreatureData()->id);
                if (iter != m_CrTeamPaarMap.end())
                    ResetNPCEntry(pCr, m_VerteidigerTeamId == TEAM_ALLIANCE ? iter->second : iter->first);
            }
            break;

        case TW_NPC_TYP_CHAMPION:
            {
                TeamPaarMap::const_iterator iter = m_CrTeamPaarMap.find(pCr->GetCreatureData()->id);
                if (iter != m_CrTeamPaarMap.end())
                    ResetNPCEntry(pCr, m_VerteidigerTeamId == TEAM_ALLIANCE ? iter->second : iter->first);
            }
            break;

        case TW_NPC_TYP_RUESTMEISTER_1:
        case TW_NPC_TYP_RUESTMEISTER_2:
            /*if (sWorld->getBoolConfig(CONFIG_TW_VERSCHIEBE_NPCS))
            {
                TeamPaarMap::const_iterator iter = m_CrTeamPaarMap.find(pCr->GetCreatureData()->id);
                if (iter != m_CrTeamPaarMap.end())
                    ResetNPCEntry(pCr, m_VerteidigerTeamId == TEAM_ALLIANCE ? iter->second : iter->first);
            }*/
            break;

        case TW_NPC_TYP_GEISTERFUEHRER:
            pCr->CastSpell(pCr, SPELL_GEISTIGE_IMMUNITAET, true);

            if (pCr->GetPositionX() > TW_FESTUNGS_GEISTERFUEHRER_MIN_X_POS)
            {
                TeamPaarMap::const_iterator iter = m_CrTeamPaarMap.find(pCr->GetCreatureData()->id);
                if (iter != m_CrTeamPaarMap.end())
                    ResetNPCEntry(pCr, m_VerteidigerTeamId == TEAM_ALLIANCE ? iter->second : iter->first);
            }
            if (pCr->GetPositionY() < TW_ALLY_GEISTERFUEHRER_MAX_Y_POS)
                ResetNPCEntry(pCr, TW_NPC_GEISTERFUEHRER_A);

            if (pCr->GetPositionY() > TW_HORDE_GEISTERFUEHRER_MIN_Y_POS)
                ResetNPCEntry(pCr, TW_NPC_GEISTERFUEHRER_H);
            break;

        // Geistheiler haben in TW keine Aufgabe (außer der beim Relikt für die Kammer)
        case TW_NPC_TYP_GEISTHEILER:
            break;

        case TW_NPC_TYP_VERWUESTERINGENIEUR:
            pCr->SetReactState(REACT_PASSIVE);

            if (IstInDerFestung(pCr))
            {
                TeamPaarMap::const_iterator iter = m_CrTeamPaarMap.find(pCr->GetCreatureData()->id);
                if (iter != m_CrTeamPaarMap.end())
                    ResetNPCEntry(pCr, m_VerteidigerTeamId == TEAM_ALLIANCE ? iter->second : iter->first);
            }
            break;

        case TW_NPC_TYP_VERZAUBERER:
        case TW_NPC_TYP_QUESTGEBER_1:
        case TW_NPC_TYP_QUESTGEBER_2:
        case TW_NPC_TYP_QUESTGEBER_3:
        case TW_NPC_TYP_QUESTGEBER_4:
        case TW_NPC_TYP_QUESTGEBER_5:
        case TW_NPC_TYP_QUESTGEBER_6:
        case TW_NPC_TYP_QUESTGEBER_PVP_1:
        case TW_NPC_TYP_QUESTGEBER_PVP_2:
            /*if (sWorld->getBoolConfig(CONFIG_TW_VERSCHIEBE_NPCS))
            {
                TeamPaarMap::const_iterator iter = m_CrTeamPaarMap.find(pCr->GetCreatureData()->id);
                if (iter != m_CrTeamPaarMap.end())
                    ResetNPCEntry(pCr, m_VerteidigerTeamId == TEAM_ALLIANCE ? iter->second : iter->first);
            }*/
            break;

        case TW_NPC_TYP_BELAGERUNGSMASCHINE:
        case TW_NPC_TYP_KATAPULT:
        case TW_NPC_TYP_VERWUESTER:
            if (!m_Kampf && pCr->isAlive())
                pCr->setDeathState(JUST_DIED);
            break;

        case TW_NPC_TYP_TURMKANONE:
            pCr->Respawn(true);
            pCr->setFaction(Fraktionen[m_VerteidigerTeamId]);
            pCr->SetReactState(REACT_PASSIVE);
            pCr->SetVisible(m_Kampf ? true : false);
            pCr->UpdateObjectVisibility();
            break;

        case TW_NPC_TYP_WAFFENKONTROLLE:
            pCr->SetReactState(REACT_PASSIVE);

            if (IstInDerFestung(pCr))
                pCr->setFaction(Fraktionen[m_VerteidigerTeamId]);
            else
                for (OutdoorPvP::OPvPCapturePointMap::const_iterator iter = OutdoorPvP::m_capturePoints.begin(); iter != OutdoorPvP::m_capturePoints.end(); ++iter)
                    if (TausendwinterCapturePoint * Werkstatt = dynamic_cast<TausendwinterCapturePoint*> (iter->second))
                        if (Werkstatt->m_KontrolleGUID == pCr->GetDBTableGUIDLow())
                        {
                            if (Werkstatt->m_Ingi && Werkstatt->m_Kontrolle)
                                Werkstatt->m_Kontrolle->setFaction(Werkstatt->m_Ingi->getFaction());
                            break;
                        }
            break;

        case TW_NPC_TYP_TRASH:
            pCr->Respawn(true);
            pCr->SetVisible(m_Kampf ? false : true);
            pCr->SetReactState(m_Kampf ? REACT_PASSIVE : REACT_AGGRESSIVE);
            break;
    }
}

// Überprüfen, ob der NPC innheralb der Festung ist
bool Tausendwinter::IstInDerFestung(Creature * pCr) const
{
    if (!pCr)
        return false;

    if (pCr->GetPositionY() < TWFestungsKoords[TW_FESTUNGS_MAX_Y] &&
        pCr->GetPositionY() > TWFestungsKoords[TW_FESTUNGS_MIN_Y] &&
        pCr->GetPositionX() < TWFestungsKoords[TW_FESTUNGS_MAX_X] &&
        pCr->GetPositionX() > TWFestungsKoords[TW_FESTUNGS_MIN_X])
        return true;

    return false;
}

// Überprüfen, ob das GO innheralb der Festung ist
bool Tausendwinter::IstInDerFestung(GameObject * pGO) const
{
    if (!pGO)
        return false;

    if (pGO->GetPositionY() < TWFestungsKoords[TW_FESTUNGS_MAX_Y] &&
        pGO->GetPositionY() > TWFestungsKoords[TW_FESTUNGS_MIN_Y] &&
        pGO->GetPositionX() < TWFestungsKoords[TW_FESTUNGS_MAX_X] &&
        pGO->GetPositionX() > TWFestungsKoords[TW_FESTUNGS_MIN_X])
        return true;

    return false;
}

// Spielerzahlen
uint8 Tausendwinter::HoleSpieleranzahl(TeamId teamId) const
{
    uint8 cnt = 0;

    for (PlayerSet::const_iterator iter = m_players[teamId].begin(); iter != m_players[teamId].end(); ++iter)
        if ((*iter) && !(*iter)->isGameMaster() && (*iter)->isGMVisible())
            ++cnt;

    return cnt;
};

// Stapel von Hartnaeckigkeit aktualisieren
void Tausendwinter::AktualisiereHartnaeckigkeitsStapel()
{
    if (!m_Kampf)
    {
        for (uint8 i=TEAM_ALLIANCE; i<=TEAM_HORDE; ++i)
            for (PlayerSet::const_iterator iter = m_players[i].begin(); iter != m_players[i].end(); ++iter)
                (*iter)->RemoveAurasDueToSpell(SPELL_HARTNAECKIGKEIT);
        return;
    }

    TeamId team = TEAM_NEUTRAL;
    uint32 AllianzSpieler = 0;
    uint32 HordeSpieler = 0;
    int32 NeueStapel = 0;

    for (PlayerSet::const_iterator iter = m_players[TEAM_ALLIANCE].begin(); iter != m_players[TEAM_ALLIANCE].end(); ++iter)
        if ((*iter) && (*iter)->getLevel() >= TW_MINIMUM_LEVEL && !(*iter)->isGameMaster() && (*iter)->isGMVisible())
            ++AllianzSpieler;

    for (PlayerSet::const_iterator iter = m_players[TEAM_HORDE].begin(); iter != m_players[TEAM_HORDE].end(); ++iter)
        if ((*iter) && (*iter)->getLevel() >= TW_MINIMUM_LEVEL && !(*iter)->isGameMaster() && (*iter)->isGMVisible())
            ++HordeSpieler;

    if (AllianzSpieler && HordeSpieler)
    {
        if (AllianzSpieler < HordeSpieler)
            NeueStapel = int32((float(HordeSpieler) / float(AllianzSpieler) - 1)*4); // Positiv: Auf Allianz casten
        else if (AllianzSpieler > HordeSpieler)
            NeueStapel = int32((1 - float(AllianzSpieler) / float(HordeSpieler))*4); // Negativ: Auf Horde casten
    }

    if (NeueStapel == m_HartnaeckigkeitsStapel)
        return;

    if (m_HartnaeckigkeitsStapel > 0 && NeueStapel <= 0) // Alter Stapel war auf Allianz
        team = TEAM_ALLIANCE;
    else if (m_HartnaeckigkeitsStapel < 0 && NeueStapel >= 0) // Alter Stapel war auf Horde
        team = TEAM_HORDE;

    m_HartnaeckigkeitsStapel = NeueStapel;

    // Alten Stapel löschen
    if (team != TEAM_NEUTRAL)
    {
        for (PlayerSet::const_iterator iter = m_players[team].begin(); iter != m_players[team].end(); ++iter)
            if ((*iter) && (*iter)->getLevel() >= TW_MINIMUM_LEVEL)
                (*iter)->RemoveAurasDueToSpell(SPELL_HARTNAECKIGKEIT);

        for (FahrzeugSet::const_iterator iter = m_FahrzeugSet[team].begin(); iter != m_FahrzeugSet[team].end(); ++iter)
            if ((*iter))
                (*iter)->RemoveAurasDueToSpell(SPELL_HARTNAECKIGKEIT_FAHRZEUGE);
    }

    // Neuen Stapel casten
    if (NeueStapel)
    {
        team = NeueStapel > 0 ? TEAM_ALLIANCE : TEAM_HORDE;

        if (NeueStapel < 0)
            NeueStapel = -NeueStapel;
        if (NeueStapel > 20)
            NeueStapel = 20;

        for (PlayerSet::const_iterator iter = m_players[team].begin(); iter != m_players[team].end(); ++iter)
            if ((*iter) && (*iter)->getLevel() >= TW_MINIMUM_LEVEL)
                (*iter)->SetAuraStack(SPELL_HARTNAECKIGKEIT, (*iter), NeueStapel);

        for (FahrzeugSet::const_iterator iter = m_FahrzeugSet[team].begin(); iter != m_FahrzeugSet[team].end(); ++iter)
            if ((*iter))
                (*iter)->SetAuraStack(SPELL_HARTNAECKIGKEIT_FAHRZEUGE, (*iter), NeueStapel);
    }
}

// Uhr aktualisieren
void Tausendwinter::AktualisiereZeitanzeige(uint32 & Zeit, uint32 digit, uint32 mod)
{
    uint32 wert = Zeit % mod;

    if (m_TeamZeit[digit] != wert)
    {
        m_TeamZeit[digit] = wert;
        OutdoorPvP::SendUpdateWorldState(WeltStatusZeit[digit], uint32(Zeit + time(NULL)));
        sWorld->AktualisiereNaechsteTWSchlachtZeit(uint32(Zeit + time(NULL)), digit);
    }
}

// Uhr aktualisieren
void Tausendwinter::AktualisiereZeit()
{
    uint32 Zeit = HoleZeitInSekunden();

    if (!m_Kampf)
        AktualisiereZeitanzeige(Zeit, 1, 10);
    else
        AktualisiereZeitanzeige(Zeit, 0, 10);
}

void Tausendwinter::HandleKill(Player * killer, Unit * killed)
{
    if (!sWorld->getBoolConfig(CONFIG_TW_AKTIVIERT) || !m_Kampf || !killer || !killed)
        return;

    bool ok = false;

    if (killed->GetTypeId() == TYPEID_PLAYER)
    {
        if (killed->getLevel() >= TW_MINIMUM_LEVEL)
            ok = true;

        if (killed->ToPlayer()->GetTeamId() == TEAM_ALLIANCE)
            killer->RewardPlayerAndGroupAtEvent(TW_NPC_PVP_KILL_ALLIANCE, killed);
        if (killed->ToPlayer()->GetTeamId() == TEAM_HORDE)
            killer->RewardPlayerAndGroupAtEvent(TW_NPC_PVP_KILL_HORDE, killed);
    }
    else
    {
        NPCMap::const_iterator iter = m_NPCMap.find(killed->ToCreature()->GetDBTableGUIDLow());
        if (iter != m_NPCMap.end())
        {
            switch((*iter).second->m_Typ)
            {
                case TW_NPC_TYP_BELAGERUNGSMASCHINE:
                    killer->RewardPlayerAndGroupAtEvent(TW_NPC_PVP_KILL_VEHICLE, killed);
                    ok = true;
                    break;
                case TW_NPC_TYP_WACHE:
                case TW_NPC_TYP_CHAMPION:
                    if ((*iter).second->m_TeamId == TEAM_ALLIANCE)
                        killer->RewardPlayerAndGroupAtEvent(TW_NPC_PVP_KILL_ALLIANCE, killed);
                    if ((*iter).second->m_TeamId == TEAM_HORDE)
                        killer->RewardPlayerAndGroupAtEvent(TW_NPC_PVP_KILL_HORDE, killed);
                    ok = true;
                    break;
                case TW_NPC_TYP_TURMKANONE:
                    ok = true;
                    break;
            }
        }
    }

    if (ok)
    {
        /* Wäre mir neu, dass die ganze Gruppe befördert wird...
        if (Group * pGroup = killer->GetGroup())
        {
            for (GroupReference * iter = pGroup->GetFirstMember(); iter != NULL; iter = iter->next())
                if (iter->getSource()->IsAtGroupRewardDistance(killer) && iter->getSource()->getLevel() >= TW_MINIMUM_LEVEL)
                    BefoerderSpieler(iter->getSource());
        }
        else*/
        if (killer->getLevel() >= TW_MINIMUM_LEVEL)
            BefoerderSpieler(killer);
    }
}

void Tausendwinter::BefoerderSpieler(Player * killer) const
{
    if (!killer)
        return;

    Aura * aur = NULL;

    if (aur = killer->GetAura(SPELL_REKRUT))
    {
        if (aur->GetStackAmount() >= TW_MAX_RANG_STAPEL)
        {
            killer->RemoveAura(SPELL_REKRUT);
            killer->CastSpell(killer, SPELL_FAEHNRICH, true);
            ChatHandler(killer).PSendSysMessage(LANG_TAUSENDWINTER_RANG2);
        }
        else
            killer->CastSpell(killer, SPELL_REKRUT, true);
    }
    else if (aur = killer->GetAura(SPELL_FAEHNRICH))
    {
        if (aur->GetStackAmount() >= TW_MAX_RANG_STAPEL)
        {
            killer->RemoveAura(SPELL_FAEHNRICH);
            killer->CastSpell(killer, SPELL_OBERLEUTNANT, true);
            ChatHandler(killer).PSendSysMessage(LANG_TAUSENDWINTER_RANG3);
        }
        else
            killer->CastSpell(killer, SPELL_FAEHNRICH, true);
    }
}

// Start des Kampfes
void Tausendwinter::StarteKampf()
{
    m_Raid[TEAM_ALLIANCE] = new Group;
    m_Raid[TEAM_HORDE] = new Group;

    m_Kampf = true;
    m_WarnungDone = false;

    if (!m_Fortsetzung)
    {
        // Nur beim Start alles auf Anfang setzen!
        Reset();

        m_Zeit = sWorld->getIntConfig(CONFIG_TW_KAMPFDAUER);
        m_ErfolgsZeit = 600000; // TW_ERFOLG_TW_ZUM_TROTZ
        m_Countdown = TW_COUNTDOWN_ZEIT;
    }
    else
        Reset(true);

    // Alle Spieler zu einer Raidgruppe zwingen, die sich beim Start in TW befinden
    for (uint8 teamId = TEAM_ALLIANCE; teamId < TEAM_NEUTRAL; ++teamId)
    {
        for (PlayerSet::const_iterator iter = m_players[teamId].begin(); iter != m_players[teamId].end(); ++iter)
        {
            if (!(*iter))
                continue;

            // Aus alten Gruppen entfernen
            (*iter)->RemoveFromGroup(GROUP_REMOVEMETHOD_LEAVE);
            // Zum Raid hinzufügen
            FuegeSpielerZumRaidHinzu((*iter), TeamId(teamId));
        }
    }

    // Das Relikt darf nur während des Kampfes an seinem Platz stehen!
    if (GameObjectData const * GOData = sObjectMgr->GetGOData(m_Relikt->m_GUID))
        SpawnGO(m_Relikt->m_GUID, GOData);

    // Alle TW spezifischen Auren löschen / setzen, für das Angreiferteam
    for (PlayerSet::const_iterator iter = m_players[OTHER_TEAM(m_VerteidigerTeamId)].begin(); iter != m_players[OTHER_TEAM(m_VerteidigerTeamId)].end(); ++iter)
    {
        AktualisiereEssenzVonTausendwinter(*iter, NORDEND_TAUSENDWINTER);

        (*iter)->RemoveAurasDueToSpell(SPELL_REKRUT);
        (*iter)->RemoveAurasDueToSpell(SPELL_FAEHNRICH);
        (*iter)->RemoveAurasDueToSpell(SPELL_OBERLEUTNANT);
        (*iter)->RemoveAurasDueToSpell(SPELL_TURMKONTROLLE);
        (*iter)->RemoveAurasDueToSpell(SPELL_GEISTIGE_IMMUNITAET);

        if ((*iter)->getLevel() >= TW_MINIMUM_LEVEL)
        {
            (*iter)->SetAuraStack(SPELL_TURMKONTROLLE, *iter, 3);
            (*iter)->CastSpell(*iter, SPELL_REKRUT, true);
        }
        (*iter)->CastSpell(*iter, SPELL_REGELN_VON_TAUSENDWINTER, true);
    }
    // Alle TW spezifischen Auren löschen / setzen, für das Verteigerteam
    for (PlayerSet::const_iterator iter = m_players[m_VerteidigerTeamId].begin(); iter != m_players[m_VerteidigerTeamId].end(); ++iter)
    {
        AktualisiereEssenzVonTausendwinter(*iter, NORDEND_TAUSENDWINTER);

        (*iter)->RemoveAurasDueToSpell(SPELL_REKRUT);
        (*iter)->RemoveAurasDueToSpell(SPELL_FAEHNRICH);
        (*iter)->RemoveAurasDueToSpell(SPELL_OBERLEUTNANT);
        (*iter)->RemoveAurasDueToSpell(SPELL_TURMKONTROLLE);
        (*iter)->RemoveAurasDueToSpell(SPELL_GEISTIGE_IMMUNITAET);

        if ((*iter)->getLevel() >= TW_MINIMUM_LEVEL)
            (*iter)->CastSpell(*iter, SPELL_REKRUT, true);

        (*iter)->CastSpell(*iter, SPELL_REGELN_VON_TAUSENDWINTER, true);
    }

    AktualisiereHartnaeckigkeitsStapel();

    if (!m_Fortsetzung)
        sWorld->SendZoneText(NORDEND_TAUSENDWINTER, sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_KAMPF_BEGINNT));

    if (!m_CmdStart && !m_Fortsetzung)
    {
        SpieleSoundFuerZone(TW_SOUND_WARNUNG);

        if (sWorld->getBoolConfig(CONFIG_TW_WELTSTARTNACHRICHT))
            sWorld->SendWorldText(LANG_TAUSENDWINTER_KAMPF_HAT_BEGONNEN);
    }

    m_Fortsetzung = false;

    Speichern();

    // Damit er den Kampf sofort wieder beendet, und den Besitzer wechselt.
    if (sWorld->getBoolConfig(CONFIG_TW_AUTOMATISCH))
    {
        m_VerteidigerWechsel = true;
        m_Zeit = 0; // Kampf beenden
    }
}

// Ende des Kampfes
void Tausendwinter::BeendeKampf()
{
    m_Kampf = false;

    Reset(true);

    if (!m_CmdStart && !m_CmdStop && !m_CmdWechsel) // Das Kampfende darf nicht erzwungen wurden sein!
    {
        if (m_VerteidigerTeamId == TEAM_ALLIANCE)
            SpieleSoundFuerTeam(TEAM_ALLIANCE, TW_SOUND_SIEG_ALLY);
        else
            SpieleSoundFuerTeam(TEAM_HORDE, TW_SOUND_SIEG_HORDE);

        if (HoleAngreiferTeamId() == TEAM_ALLIANCE)
            SpieleSoundFuerTeam(TEAM_ALLIANCE, TW_SOUND_UEBERNOMMEN_ALLY);
        else
            SpieleSoundFuerTeam(TEAM_HORDE, TW_SOUND_UEBERNOMMEN_HORDE);

        OutdoorPvP::TeamCastSpell(m_VerteidigerTeamId, SPELL_SIEG_SPRUNG);
        OutdoorPvP::TeamCastSpell(m_VerteidigerTeamId, SPELL_SIEG_AURA);
    }

    m_SiegAuraZeit = TW_SIEGAURA_ZEIT;

    // Das Relikt darf nur während des Kampfes an seinem Platz stehen!
    if (GameObjectData const * GOData = sObjectMgr->GetGOData(m_Relikt->m_GUID))
        EntferneGO(m_Relikt->m_GUID, GOData);

    for (uint8 teamId=TEAM_ALLIANCE; teamId<=TEAM_HORDE; ++teamId)
    {
        // Alle Fahrzeuge zerstören
        while(!m_FahrzeugSet[teamId].empty())
        {
            if (Creature * pCr = (*m_FahrzeugSet[teamId].begin()))
                pCr->setDeathState(JUST_DIED);

            m_FahrzeugSet[teamId].erase(m_FahrzeugSet[teamId].begin());
        }

        if (m_players[teamId].empty())
            continue;

        for (PlayerSet::iterator iter = m_players[teamId].begin(); iter != m_players[teamId].end(); ++iter)
        {
            if (!(*iter))
                continue;

            // Alle Toten wiederbeleben, und "Kampfrückstände" löschen. ;)
            if ((*iter)->isDead())
            {
                (*iter)->ResurrectPlayer(float(TW_WIEDERBELEBUNGS_HP_PROZENT));
                sObjectAccessor->ConvertCorpseForPlayer((*iter)->GetGUID());
            }
            (*iter)->RemoveAurasDueToSpell(SPELL_HARTNAECKIGKEIT);
            (*iter)->CombatStop(true);
            (*iter)->getHostileRefManager().deleteReferences();

            AktualisiereEssenzVonTausendwinter((*iter), NORDEND_TAUSENDWINTER);
        }

        if (m_CmdStart || m_CmdStop || m_CmdWechsel) // Das Kampfende wurde erzwungen, also keine Belohnungen ausgeben!
        {
            m_ErfolgsZeit = 0;

            for (PlayerSet::iterator iter = m_players[teamId].begin(); iter != m_players[teamId].end(); ++iter)
            {
                if (!(*iter))
                    continue;

                (*iter)->RemoveAurasDueToSpell(SPELL_REKRUT);
                (*iter)->RemoveAurasDueToSpell(SPELL_FAEHNRICH);
                (*iter)->RemoveAurasDueToSpell(SPELL_OBERLEUTNANT);
                (*iter)->RemoveAurasDueToSpell(SPELL_TURMKONTROLLE);
                (*iter)->RemoveAurasDueToSpell(SPELL_GEISTIGE_IMMUNITAET);
                (*iter)->RemoveAurasDueToSpell(SPELL_REGELN_VON_TAUSENDWINTER);
            }
            continue;
        }
        else
        {
            // Belohnungen ausgeben
            uint32 AnzahlIntakt = 0;
            uint32 AnzahlDefekt = 0;

            for (OutdoorPvP::OPvPCapturePointMap::const_iterator iter = OutdoorPvP::m_capturePoints.begin(); iter != OutdoorPvP::m_capturePoints.end(); ++iter)
                if (TausendwinterCapturePoint * pWerkstatt = dynamic_cast<TausendwinterCapturePoint*>(iter->second))
                    if (pWerkstatt->m_GOStatus->HoleTeamId() == teamId)
                        if (pWerkstatt->m_GOStatus->m_SchadensStatus == BESCHAEDIGT || pWerkstatt->m_GOStatus->m_SchadensStatus == ZERSTOERT)
                            ++AnzahlDefekt;
                        else if (pWerkstatt->m_GOStatus->m_SchadensStatus == INTAKT)
                            ++AnzahlIntakt;

            uint32 Belohnungsspell = teamId == m_VerteidigerTeamId ? SPELL_SIEG_IN_TAUSENDWINTER : SPELL_NIEDERLAGE_IN_TAUSENDWINTER;
            OutdoorPvP::TeamCastSpell(TeamId(teamId), Belohnungsspell);

            for (PlayerSet::iterator iter = m_players[teamId].begin(); iter != m_players[teamId].end(); ++iter)
            {
                if (!(*iter))
                    continue;

                if ((*iter)->getLevel() < TW_MINIMUM_LEVEL) // Keine Belohnungen für Lowies! ;)
                    continue;

                // TODO: Marken sollte es pro Rang eine geben, es gibt aber immer drei pro Cast, also nur einmal casten
                if ((*iter)->HasAura(SPELL_OBERLEUTNANT) || (*iter)->HasAura(SPELL_FAEHNRICH))
                {
                    for (uint32 i=0; i<AnzahlIntakt; ++i)
                        (*iter)->CastSpell(*iter, SPELL_INTAKTES_GEBAEUDE_VERTEIDIGT, true);

                    for (uint32 i=0; i<AnzahlDefekt; ++i)
                        (*iter)->CastSpell(*iter, SPELL_DAMAGED_BUILDING_REWARD, true);

                    for (uint32 i=0; i<m_BeschaedigteTuerme[OTHER_TEAM(teamId)]; ++i)
                        (*iter)->CastSpell(*iter, SPELL_TOWER_DAMAGED, true);

                    for (uint32 i=0; i<m_ZerstoerteTuerme[OTHER_TEAM(teamId)]; ++i)
                        (*iter)->CastSpell(*iter, SPELL_TURM_ZERSTOERT, true);
                }

                if (teamId == m_VerteidigerTeamId)
                {
                    if (m_ErfolgsZeit > 0)
                    {
                        AchievementEntry const * pAE = GetAchievementStore()->LookupEntry(TW_ERFOLG_TW_ZUM_TROTZ);
                        if (!pAE)
                            sLog->outError("TAUSENDWINTER: Kann den Eintrag für den Erfolg %u nicht erstellen!", TW_ERFOLG_TW_ZUM_TROTZ);
                        else
                            (*iter)->CompletedAchievement(pAE);
                    }

                    if ((*iter)->HasAura(SPELL_OBERLEUTNANT) || (*iter)->HasAura(SPELL_FAEHNRICH))
                    {
                        if ((*iter)->GetTeamId() == TEAM_ALLIANCE)
                            (*iter)->AreaExploredOrEventHappens(TW_QUEST_SIEG_IN_TAUSENDWINTER_A);
                        else
                            (*iter)->AreaExploredOrEventHappens(TW_QUEST_SIEG_IN_TAUSENDWINTER_H);
                    }
                }
                (*iter)->RemoveAurasDueToSpell(SPELL_REKRUT);
                (*iter)->RemoveAurasDueToSpell(SPELL_FAEHNRICH);
                (*iter)->RemoveAurasDueToSpell(SPELL_OBERLEUTNANT);
                (*iter)->RemoveAurasDueToSpell(SPELL_TURMKONTROLLE);
                (*iter)->RemoveAurasDueToSpell(SPELL_GEISTIGE_IMMUNITAET);
                (*iter)->RemoveAurasDueToSpell(SPELL_REGELN_VON_TAUSENDWINTER);
            }
        }
    }

    // Alle Spieler aus der Raidgruppe entfernen
    for (uint8 teamId = TEAM_ALLIANCE; teamId < TEAM_NEUTRAL; ++teamId)
    {
        for (PlayerSet::const_iterator iter = m_players[teamId].begin(); iter != m_players[teamId].end(); ++iter)
        {
            if (!(*iter))
                continue;

            (*iter)->RemoveFromGroup(GROUP_REMOVEMETHOD_LEAVE);
            /*
            if (m_Raid[teamId]->IsMember((*iter)->GetGUID()))
                m_Raid[teamId]->RemoveMember((*iter)->GetGUID(), GROUP_REMOVEMETHOD_LEAVE);
            */
        }
        m_Raid[teamId] = NULL;
    }

    // Das komplette Angreiferteam nach dem Kampf nach Dalaran teleportieren (optional!)
    if (sWorld->getBoolConfig(CONFIG_TW_TELEPORT_DALARAN))
        OutdoorPvP::TeamCastSpell(OTHER_TEAM(m_VerteidigerTeamId), SPELL_NACH_DALARAN_TELEPORTIEREN);

    // Kampf beendet - schauen ob in Dalaran das korrekte Portal steht
    UeberpruefeDalaranPortal();

    // Tausendwinter Events aktualisieren
    sGameEventMgr->StopEvent(GameEventTausendwinterVerteidiger[HoleAngreiferTeamId()], true);
    sGameEventMgr->StartEvent(GameEventTausendwinterVerteidiger[m_VerteidigerTeamId], true);

    m_Zeit = sWorld->getIntConfig(CONFIG_TW_INTERVALL);

    Speichern();
}

// Alle relevanten Daten in die DB speichern
void Tausendwinter::Speichern()
{
    // Hauptdaten (TODO: Alle weiteren wichtigen Daten speichern / laden)
    sWorld->setWorldState(WS_TW_BESITZER, uint64(m_VerteidigerTeamId));
    sWorld->setWorldState(WS_TW_KAMPF, uint64(m_Kampf));
    sWorld->setWorldState(WS_TW_ZEIT, uint64(m_Zeit));

    m_SpeicherIntervall = sWorld->getIntConfig(CONFIG_TW_SPEICHER_INTERVALL);
}

// NotfallAbschaltung
void Tausendwinter::NotfallAbschaltung()
{
    sLog->outError("TAUSENDWINTER: void Tausendwinter::NotfallAbschaltung()");
    sWorld->setWorldState(CONFIG_TW_AKTIVIERT, uint64(false));
    sWorld->setWorldState(WS_TW_BESITZER, uint64(m_VerteidigerTeamId));
    sWorld->setWorldState(WS_TW_KAMPF, uint64(m_Kampf));
    sWorld->setWorldState(WS_TW_ZEIT, uint64(m_Zeit));

    m_VerteidigerTeamId = TEAM_NEUTRAL;
    m_Kampf = false;
    m_Zeit = 0;
}

void Tausendwinter::BearbeiteWiederbelebungen(const uint32 diff)
{
    for (NPCMap::const_iterator NPCiter = m_NPCMap.begin(); NPCiter != m_NPCMap.end(); ++NPCiter)
    {
        if ((*NPCiter).second->m_Typ != TW_NPC_TYP_GEISTERFUEHRER)
            continue;

        (*NPCiter).second->m_LetzteWiederbelebung += diff;

        if ((*NPCiter).second->m_Creature && !(*NPCiter).second->m_Creature->HasUnitState(UNIT_STAT_CASTING))
        {
            (*NPCiter).second->m_LetzteWiederbelebung = 0;
            (*NPCiter).second->m_Creature->CastSpell((*NPCiter).second->m_Creature, SPELL_SPIRIT_HEAL_CHANNEL, false);
        }

        if ((*NPCiter).second->m_LetzteWiederbelebung >= RESURRECTION_INTERVAL)
        {
            for (SpielerSet::iterator Spieleriter = (*NPCiter).second->m_SpielerListe.begin(); Spieleriter != (*NPCiter).second->m_SpielerListe.end(); ++Spieleriter)
            {
                Player * pPlr = sObjectAccessor->FindPlayer(*Spieleriter);
                if (!pPlr)
                    continue;

                if ((*NPCiter).second->m_Creature)
                    (*NPCiter).second->m_Creature->CastSpell((*NPCiter).second->m_Creature, SPELL_SPIRIT_HEAL, true);
                else if (!(*NPCiter).second->m_Creature && pPlr->IsInWorld())
                {
                    (*NPCiter).second->m_Creature = pPlr->GetMap()->GetCreature((*NPCiter).second->m_GUID);
                    if ((*NPCiter).second->m_Creature)
                        (*NPCiter).second->m_Creature->CastSpell((*NPCiter).second->m_Creature, SPELL_SPIRIT_HEAL, true);
                }
                pPlr->CastSpell(pPlr, SPELL_RESURRECTION_VISUAL, true);
                (*NPCiter).second->m_WiederbelebungsListe.insert(*Spieleriter);
            }
            (*NPCiter).second->m_LetzteWiederbelebung = 0;

            if ((*NPCiter).second->m_Creature)
            {
                (*NPCiter).second->m_Creature->InterruptNonMeleeSpells(true, SPELL_SPIRIT_HEAL_CHANNEL, false);
                (*NPCiter).second->m_Creature->CastSpell((*NPCiter).second->m_Creature, SPELL_SPIRIT_HEAL_CHANNEL, false);
            }
            (*NPCiter).second->m_SpielerListe.clear();
        }

        if ((*NPCiter).second->m_LetzteWiederbelebung > TW_WIEDERBELEBUNGSVERZOEGERUNG) // Spieler jetzt erst wiederbeleben, damit er die Effekte sieht
        {
            for (SpielerSet::iterator Spieleriter = (*NPCiter).second->m_WiederbelebungsListe.begin(); Spieleriter != (*NPCiter).second->m_WiederbelebungsListe.end(); ++Spieleriter)
            {
                Player * pPlr = sObjectAccessor->FindPlayer(*Spieleriter);
                if (!pPlr)
                    continue;

                pPlr->ResurrectPlayer(float(TW_WIEDERBELEBUNGS_HP_PROZENT));
                pPlr->CastSpell(pPlr, SPELL_SPIRIT_HEAL_MANA, true);
                sObjectAccessor->ConvertCorpseForPlayer(*Spieleriter);
            }
            (*NPCiter).second->m_WiederbelebungsListe.clear();
        }
    }
}

// Alles entsprechend der TeamIds spawnen / verschieben / wiederherstellen
void Tausendwinter::Reset(bool NurWechsel)
{
    if (NurWechsel)
        AktualisiereZerstoerbareGOs();
    else
        ResetZerstoerbareGOs();

    for (GOMap::const_iterator iter = m_GOMap.begin(); iter != m_GOMap.end(); ++iter)
        AktualisiereGO((*iter).second->m_GameObject);

    for (NPCMap::const_iterator iter = m_NPCMap.begin(); iter != m_NPCMap.end(); ++iter)
    {
        AktualisiereNPC((*iter).second->m_Creature);
        (*iter).second->AktualisierePosition(m_VerteidigerTeamId);
    }

    for (OPvPCapturePointMap::const_iterator iter = m_capturePoints.begin(); iter != m_capturePoints.end(); ++iter)
        if (TausendwinterCapturePoint * Werkstatt = dynamic_cast<TausendwinterCapturePoint*> (iter->second))
            Werkstatt->SetzeTeamIdEntsprechendDemGOStatus();

    // Muss hier aufgerufen werden, da sonst nach dem Realmstart falsche Werte angezeigt werden!
    if (!NurWechsel)
        for (uint8 i=TEAM_ALLIANCE; i<=TEAM_HORDE; ++i)
            OutdoorPvP::SendUpdateWorldState(WeltStatusAnzahlFahrzeugeMax[i], m_AnzahlWerkstaetten[i] * TW_WERKSTATT_FAHRZEUGE);
}

// NPC ID Reset
void Tausendwinter::ResetNPCEntry(Creature * pCr, uint32 entry)
{
    if (!pCr)
        return;

    pCr->SetOriginalEntry(entry);
    pCr->LoadCreaturesAddon(true);
    pCr->Respawn(true);
}

// Alle zerstörbaren Gebäude wiederherstellen
void Tausendwinter::ResetZerstoerbareGOs()
{
    m_AnzahlWerkstaetten[TEAM_ALLIANCE] = 0;
    m_AnzahlWerkstaetten[TEAM_HORDE] = 0;

    for (GOStatusMap::const_iterator iter = m_GOStatus.begin(); iter != m_GOStatus.end(); ++iter)
    {
        if (iter->second->m_GameObject)
        {
            AktualisiereGO(iter->second->m_GameObject);

            iter->second->m_GameObject->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING, NULL, true);
            iter->second->m_Health = iter->second->m_GameObject->GetGOValue()->Building.Health;
        }
        else
            iter->second->m_Health = 0;

        if (iter->second->m_Typ == WERKSTATT)
            AktualisiereWerkstattAnzahl(iter->second->HoleTeamId(), true);

        iter->second->m_SchadensStatus = INTAKT;
        iter->second->SetzeTeamId(m_VerteidigerTeamId == TEAM_ALLIANCE ? OTHER_TEAM(iter->second->m_DefaultTeamId) : iter->second->m_DefaultTeamId);
    }
    m_BeschaedigteTuerme[TEAM_ALLIANCE] = 0;
    m_BeschaedigteTuerme[TEAM_HORDE] = 0;
    m_ZerstoerteTuerme[TEAM_ALLIANCE] = 0;
    m_ZerstoerteTuerme[TEAM_HORDE] = 0;
}

// Alle zerstörbaren Gebäude bei Übernahme der Festung aktualisieren
void Tausendwinter::AktualisiereZerstoerbareGOs()
{
    for (GOStatusMap::const_iterator iter = m_GOStatus.begin(); iter != m_GOStatus.end(); ++iter)
    {
        if (iter->second->m_GameObject)
        {
            AktualisiereGO(iter->second->m_GameObject);
            iter->second->m_Health = iter->second->m_GameObject->GetGOValue()->Building.Health;
        }
        else
            iter->second->m_Health = 0;

        if (iter->second->m_Typ == WERKSTATT)
            AktualisiereWerkstattAnzahl(iter->second->HoleTeamId(), true);

        iter->second->SetzeTeamId(m_VerteidigerTeamId == TEAM_ALLIANCE ? OTHER_TEAM(iter->second->m_DefaultTeamId) : iter->second->m_DefaultTeamId);
    }
}

// NPCListen erstellen
bool Tausendwinter::ErstelleNPCMap(QueryResult result)
{
    do
    {   // 0 = GUID - 1 = ID - 2 Fraktion
        Field * fields = result->Fetch();

        switch(fields[1].GetUInt32())
        {
            case TW_NPC_WACHE_A:
            case TW_NPC_WACHE_H:
            case TW_NPC_CHAMPION_A:
            case TW_NPC_CHAMPION_H:
            case TW_NPC_RUESTMEISTER_1_A:
            case TW_NPC_RUESTMEISTER_1_H:
            case TW_NPC_RUESTMEISTER_2_A:
            case TW_NPC_RUESTMEISTER_2_H:
            case TW_NPC_GEISTERFUEHRER_A:
            case TW_NPC_GEISTERFUEHRER_H:
            case TW_NPC_GEISTHEILER_A:
            //case TW_NPC_GEISTHEILER_H:
            case TW_NPC_VERWUESTERINGENIEUR_A:
            case TW_NPC_VERWUESTERINGENIEUR_H:
            case TW_NPC_VERZAUBERER_A:
            case TW_NPC_VERZAUBERER_H:
            case TW_NPC_QUESTGEBER_1_A:
            case TW_NPC_QUESTGEBER_1_H:
            case TW_NPC_QUESTGEBER_2_A:
            case TW_NPC_QUESTGEBER_2_H:
            case TW_NPC_QUESTGEBER_3_A:
            case TW_NPC_QUESTGEBER_3_H:
            case TW_NPC_QUESTGEBER_4_A:
            case TW_NPC_QUESTGEBER_4_H:
            case TW_NPC_QUESTGEBER_5_A:
            case TW_NPC_QUESTGEBER_5_H:
            case TW_NPC_QUESTGEBER_6_A:
            case TW_NPC_QUESTGEBER_6_H:
            case TW_NPC_QUESTGEBER_PVP_1_A:
            case TW_NPC_QUESTGEBER_PVP_1_H:
            case TW_NPC_QUESTGEBER_PVP_2_A:
            case TW_NPC_QUESTGEBER_PVP_2_H:
            case TW_NPC_BELAGERUNGSMASCHINE_A:
            case TW_NPC_BELAGERUNGSMASCHINE_H:
            case TW_NPC_BELAGERUNGSTURM_A:
            case TW_NPC_BELAGERUNGSTURM_H:
            case TW_NPC_KATAPULT_A:
            //case TW_NPC_KATAPULT_H:
            case TW_NPC_VERWUESTER_A:
            //case TW_NPC_VERWUESTER_H:
            case TW_NPC_TURMKANONE_A:
            //case TW_NPC_TURMKANONE_H:
            case TW_NPC_FLUGMEISTER_A:
            case TW_NPC_FLUGMEISTER_H:
            case TW_NPC_WAFFENKONTROLLE_A:
            //case TW_NPC_WAFFENKONTROLLE_H:
            case TW_NPC_ENTDECKUNGSEINHEIT:
            // Elementare
            case TW_NPC_LEBENDER_PEITSCHER:
            case TW_NPC_AUSGEWACHSENER_PEITSCHER:
            case TW_NPC_WANDERNDER_SCHATTEN:
            case TW_NPC_SCHATTENKLAGEGEIST:
            case TW_NPC_EISZEITLICHER_GEIST:
            case TW_NPC_WASSERKLAGEGEIST:
            case TW_NPC_KUEHLER_ERDELEMENTAR:
            case TW_NPC_ERDKLAGEGEIST:
            case TW_NPC_FLUESTERNDER_WIND:
            case TW_NPC_STURMKLAGEGEIST:
            case TW_NPC_TOBENDE_FLAMME:
            case TW_NPC_FEUERKLAGEGEIST:
                m_NPCMap[fields[0].GetUInt32()] = new NPCStruktur(fields[0].GetUInt32(), fields[1].GetUInt32(), fields[2].GetUInt32(), m_VerteidigerTeamId);
                m_NPCMap[fields[0].GetUInt32()]->InitialisiereNPC();
                break;
        }
    } while (result->NextRow());

    if (!m_NPCMap.size())
    {
        sLog->outError("TAUSENDWINTER: Konnte keine NPCs in Tausendwinter finden! Deaktiviere Tausendwintersee.");
        return false;
    }

    // Fehlende Spawns melden
    MeldeFehlendeNPCs();

    return true;
}

// Fehlende Spawns melden
void Tausendwinter::MeldeFehlendeNPCs()
{
    uint32 WachenCnt = 0;
    uint32 ChampionCnt = 0;
    uint32 RuestmeisterCnt = 0;
    uint32 FuehrerCnt = 0;
    uint32 HeilerCnt = 0;
    uint32 IngiCnt = 0;
    uint32 ZauberCnt = 0;
    uint32 QuestgeberCnt = 0;
    uint32 FahrzeugeCnt = 0;
    uint32 TurmkanonenCnt = 0;
    uint32 FlugCnt = 0;
    uint32 KontrollenCnt = 0;
    uint32 TrashCnt = 0;
    uint32 TriggerCnt = 0;

    for (NPCMap::iterator iter = m_NPCMap.begin(); iter != m_NPCMap.end(); ++iter)
    {
        switch((*iter).second->m_Typ)
        {
            case TW_NPC_TYP_WACHE:
                ++WachenCnt;
                break;
            case TW_NPC_TYP_CHAMPION:
                ++ChampionCnt;
                break;
            case TW_NPC_TYP_RUESTMEISTER_1:
            case TW_NPC_TYP_RUESTMEISTER_2:
                ++RuestmeisterCnt;
                break;
            case TW_NPC_TYP_GEISTERFUEHRER:
                ++FuehrerCnt;
                break;
            case TW_NPC_TYP_GEISTHEILER:
                ++HeilerCnt;
                break;
            case TW_NPC_TYP_VERWUESTERINGENIEUR:
                ++IngiCnt;
                break;
            case TW_NPC_TYP_VERZAUBERER:
                ++ZauberCnt;
                break;
            case TW_NPC_TYP_QUESTGEBER_1:
            case TW_NPC_TYP_QUESTGEBER_2:
            case TW_NPC_TYP_QUESTGEBER_3:
            case TW_NPC_TYP_QUESTGEBER_4:
            case TW_NPC_TYP_QUESTGEBER_5:
            case TW_NPC_TYP_QUESTGEBER_6:
            case TW_NPC_TYP_QUESTGEBER_PVP_1:
            case TW_NPC_TYP_QUESTGEBER_PVP_2:
                ++QuestgeberCnt;
                break;
            case TW_NPC_TYP_BELAGERUNGSMASCHINE:
            case TW_NPC_TYP_KATAPULT:
            case TW_NPC_TYP_VERWUESTER:
                ++FahrzeugeCnt;
                break;
            case TW_NPC_TYP_TURMKANONE:
                ++TurmkanonenCnt;
                break;
            case TW_NPC_TYP_FLUGMEISTER:
                ++FlugCnt;
                break;
            case TW_NPC_TYP_WAFFENKONTROLLE:
                ++KontrollenCnt;
                break;
            case TW_NPC_TYP_TRASH:
                ++TrashCnt;
                break;
            case TW_NPC_TYP_ENTDECKUNGSEINHEIT:
                ++TriggerCnt;
                break;
        }
    }

    if (!WachenCnt)
        sLog->outErrorDb("TAUSENDWINTER: Es sind keine NPCs mit den IDs %u / %u gespawnt!", TW_NPC_WACHE_A, TW_NPC_WACHE_H);
    if (!ChampionCnt)
        sLog->outErrorDb("TAUSENDWINTER: Es sind keine NPCs mit den IDs %u / %u gespawnt!", TW_NPC_CHAMPION_A, TW_NPC_CHAMPION_H);
    if (RuestmeisterCnt < TW_ANZAHL_RUESTMEISTER)
        sLog->outErrorDb("TAUSENDWINTER: Es sind nicht alle Rüstmeister gespawnt!");
    if (!FuehrerCnt)
        sLog->outErrorDb("TAUSENDWINTER: Es sind keine NPCs mit den IDs %u / %u gespawnt!", TW_NPC_GEISTERFUEHRER_A, TW_NPC_GEISTERFUEHRER_H);
    if (!HeilerCnt)
        sLog->outErrorDb("TAUSENDWINTER: Es sind keine NPCs mit der ID %u gespawnt!", TW_NPC_GEISTHEILER_A);
    if (IngiCnt < TW_GO_ANZAHL_WERKSTAETTEN)
        sLog->outErrorDb("TAUSENDWINTER: Es sind nicht alle notwendigen NPCs mit den IDs %u / %u gespawnt!", TW_NPC_VERWUESTERINGENIEUR_A, TW_NPC_VERWUESTERINGENIEUR_H);
    if (!ZauberCnt)
        sLog->outErrorDb("TAUSENDWINTER: Es sind keine NPCs mit den IDs %u / %u gespawnt!", TW_NPC_VERZAUBERER_A, TW_NPC_VERZAUBERER_H);
    if (!QuestgeberCnt)
        sLog->outErrorDb("TAUSENDWINTER: Es sind keine Questgeber gespawnt!");
    if (FahrzeugeCnt)
        sLog->outErrorDb("TAUSENDWINTER: Es sind Fahrzeuge via DB gespawnt! Unbedingt daraus löschen!");
    if (!TurmkanonenCnt)
        sLog->outErrorDb("TAUSENDWINTER: Es sind keine NPCs mit der ID %u gespawnt!", TW_NPC_TURMKANONE_A);
    if (FlugCnt < TW_ANZAHL_FLUGMEISTER)
        sLog->outErrorDb("TAUSENDWINTER: Es sind nicht alle Flugmeister gespawnt!");
    if (KontrollenCnt < TW_GO_ANZAHL_WERKSTAETTEN)
        sLog->outErrorDb("TAUSENDWINTER: Es sind alle NPCs mit der ID %u gespawnt!", TW_NPC_WAFFENKONTROLLE_A);
    if (!TrashCnt)
        sLog->outErrorDb("TAUSENDWINTER: Es sind keine Trash NPCs gespawnt!");
    if (!TriggerCnt)
        sLog->outErrorDb("TAUSENDWINTER: Es sind keine NPCs mit der ID %u gespawnt!", TW_NPC_ENTDECKUNGSEINHEIT);
}

// Gameobjektlisten erstellen
bool Tausendwinter::ErstelleGOMap(QueryResult result)
{
    do
    {   // 0 = GUID - 1 = ID
        Field * fields = result->Fetch();
        switch(fields[1].GetUInt32())
        {
            // Relikt der Titanen
            case TW_GO_RELIKT_DER_TITANEN:
            // Reliktkammer
            case TW_GO_KOLLISIONSWAND01:
            case TW_GO_KOLLISIONSWAND:
            case TW_GO_FESTUNGSTUER:
            // Werkstätten
            case TW_GO_GOBLINWERKSTATT_FESTUNG_W:
            case TW_GO_GOBLINWERKSTATT_FESTUNG_O:
            case TW_GO_GOBLINWERKSTATT_TEMPEL:
            case TW_GO_GOBLINWERKSTATT_RING:
            case TW_GO_GOBLINWERKSTATT_WESTFUNK:
            case TW_GO_GOBLINWERKSTATT_OSTFUNK:
            // Türme
            case TW_GO_SCHATTENBLICKTURM:
            case TW_GO_WINTERSTURZTURM:
            case TW_GO_FLAMMENAUGENTURM:
            case TW_GO_FESTUNGSTURM_NW:
            case TW_GO_FESTUNGSTURM_SW:
            case TW_GO_FESTUNGSTURM_SO:
            case TW_GO_FESTUNGSTURM_NO:
            // Festung
            case TW_GO_FESTUNGSTOR:
            case TW_GO_TAUSENDWINTERWALL_1:
            case TW_GO_TAUSENDWINTERWALL_2:
            case TW_GO_TAUSENDWINTERWALL_3:
            case TW_GO_WALL_DER_TWFESTUNG_1:
            case TW_GO_WALL_DER_TWFESTUNG_2:
            case TW_GO_WALL_DER_TWFESTUNG_3:
            case TW_GO_WALL_DER_TWFESTUNG_4:
            case TW_GO_WALL_DER_TWFESTUNG_5:
            case TW_GO_WALL_DER_TWFESTUNG_6:
            case TW_GO_WALL_DER_TWFESTUNG_7:
            case TW_GO_WALL_DER_TWFESTUNG_8:
            case TW_GO_WALL_DER_TWFESTUNG_9:
            case TW_GO_WALL_DER_TWFESTUNG_10:
            case TW_GO_WALL_DER_TWFESTUNG_11:
            case TW_GO_WALL_DER_TWFESTUNG_12:
            case TW_GO_WALL_DER_TWFESTUNG_13:
            case TW_GO_WALL_DER_TWFESTUNG_14:
            case TW_GO_WALL_DER_TWFESTUNG_15:
            case TW_GO_WALL_DER_TWFESTUNG_16:
            case TW_GO_WALL_DER_TWFESTUNG_17:
            case TW_GO_WALL_DER_TWFESTUNG_18:
            case TW_GO_WALL_DER_TWFESTUNG_19:
            case TW_GO_WALL_DER_TWFESTUNG_20:
            // Teleporter
            case TW_GO_PORTAL_DES_VERTEIDIGERS_1:
            case TW_GO_PORTAL_DES_VERTEIDIGERS_2:
            case TW_GO_PORTAL_DES_VERTEIDIGERS_3:
            case TW_GO_TELEPORTER_FUER_FAHRZEUGE:
                if (fields[1].GetUInt32() == TW_GO_RELIKT_DER_TITANEN)
                    m_Relikt = new GOStruktur(fields[0].GetUInt32(), fields[1].GetUInt32());
                m_GOMap[fields[0].GetUInt32()] = new GOStruktur(fields[0].GetUInt32(), fields[1].GetUInt32());
                break;
        }
    } while (result->NextRow());

    if (!m_GOMap.size())
    {
        sLog->outError("TAUSENDWINTER: Konnte keine GOs in Tausendwinter finden! Deaktiviere Tausendwintersee.");
        return false;
    }

    // Das Relikt wird nicht via Datenbank gespawnt, also erstellen wir es jetzt
    if (!m_Relikt)
    {
        if (uint32 GUID = sObjectMgr->AddGOData(TW_GO_RELIKT_DER_TITANEN, TW_KARTE, ReliktKoords[RELIKT_X], ReliktKoords[RELIKT_Y], ReliktKoords[RELIKT_Z], 0))
            m_Relikt = new GOStruktur(GUID, TW_GO_RELIKT_DER_TITANEN);

        if (!m_Relikt->m_GUID)
        {
            sLog->outError("TAUSENDWINTER: Das Relikt der Titanen wird nicht via DB gespawnt, und war nicht zu erstellen!");
            sLog->outError("TAUSENDWINTER: Deaktiviere Tausendwintersee.");
            return false;
        }

        if (!m_Kampf)
            if (GameObjectData const * GOData = sObjectMgr->GetGOData(m_Relikt->m_GUID))
                EntferneGO(m_Relikt->m_GUID, GOData);
    }

    // Fehlende Spawns melden
    MeldeFehlendeGOs();

    return true;
}

// Fehlende Spawns melden
void Tausendwinter::MeldeFehlendeGOs()
{
    uint8 Reliktkammer = 0;
    uint8 Werkstaetten = 0;
    uint8 Tuerme = 0;
    uint8 Festung = 0;
    uint8 Teleporter = 0;

    for (GOMap::const_iterator iter = m_GOMap.begin(); iter != m_GOMap.end(); ++iter)
    {
        switch((*iter).second->m_ID)
        {
            // Reliktkammer
            case TW_GO_KOLLISIONSWAND01:
            case TW_GO_KOLLISIONSWAND:
            case TW_GO_FESTUNGSTUER:
                ++Reliktkammer;
                break;
            // Werkstätten
            case TW_GO_GOBLINWERKSTATT_FESTUNG_W:
            case TW_GO_GOBLINWERKSTATT_FESTUNG_O:
            case TW_GO_GOBLINWERKSTATT_TEMPEL:
            case TW_GO_GOBLINWERKSTATT_RING:
            case TW_GO_GOBLINWERKSTATT_WESTFUNK:
            case TW_GO_GOBLINWERKSTATT_OSTFUNK:
                ++Werkstaetten;
                break;
            // Türme
            case TW_GO_SCHATTENBLICKTURM:
            case TW_GO_WINTERSTURZTURM:
            case TW_GO_FLAMMENAUGENTURM:
            case TW_GO_FESTUNGSTURM_NW:
            case TW_GO_FESTUNGSTURM_SW:
            case TW_GO_FESTUNGSTURM_SO:
            case TW_GO_FESTUNGSTURM_NO:
                ++Tuerme;
                break;
            // Festung
            case TW_GO_FESTUNGSTOR:
            case TW_GO_TAUSENDWINTERWALL_1:
            case TW_GO_TAUSENDWINTERWALL_2:
            case TW_GO_TAUSENDWINTERWALL_3:
            case TW_GO_WALL_DER_TWFESTUNG_1:
            case TW_GO_WALL_DER_TWFESTUNG_2:
            case TW_GO_WALL_DER_TWFESTUNG_3:
            case TW_GO_WALL_DER_TWFESTUNG_4:
            case TW_GO_WALL_DER_TWFESTUNG_5:
            case TW_GO_WALL_DER_TWFESTUNG_6:
            case TW_GO_WALL_DER_TWFESTUNG_7:
            case TW_GO_WALL_DER_TWFESTUNG_8:
            case TW_GO_WALL_DER_TWFESTUNG_9:
            case TW_GO_WALL_DER_TWFESTUNG_10:
            case TW_GO_WALL_DER_TWFESTUNG_11:
            case TW_GO_WALL_DER_TWFESTUNG_12:
            case TW_GO_WALL_DER_TWFESTUNG_13:
            case TW_GO_WALL_DER_TWFESTUNG_14:
            case TW_GO_WALL_DER_TWFESTUNG_15:
            case TW_GO_WALL_DER_TWFESTUNG_16:
            case TW_GO_WALL_DER_TWFESTUNG_17:
            case TW_GO_WALL_DER_TWFESTUNG_18:
            case TW_GO_WALL_DER_TWFESTUNG_19:
            case TW_GO_WALL_DER_TWFESTUNG_20:
                ++Festung;
                break;
            // Teleporter
            case TW_GO_PORTAL_DES_VERTEIDIGERS_1:
            case TW_GO_PORTAL_DES_VERTEIDIGERS_2:
            case TW_GO_PORTAL_DES_VERTEIDIGERS_3:
            case TW_GO_TELEPORTER_FUER_FAHRZEUGE:
                ++Teleporter;
                break;
        }
    }

    if (Reliktkammer < TW_GO_ANZAHL_RELIKTKAMMER)
        sLog->outErrorDb("TAUSENDWINTER: Es sind nicht alle Teile der Reliktkammer (GOs / ohne Relikt) gespawnt!");
    if (Werkstaetten < TW_GO_ANZAHL_WERKSTAETTEN)
        sLog->outErrorDb("TAUSENDWINTER: Es sind nicht alle Werkstätten (GOs) gespawnt!");
    if (Tuerme < TW_GO_ANZAHL_TUERME)
        sLog->outErrorDb("TAUSENDWINTER: Es sind nicht alle Türme (GOs) gespawnt!");
    if (Festung < TW_GO_ANZAHL_FESTUNG)
        sLog->outErrorDb("TAUSENDWINTER: Es sind nicht alle Teile der Festung (GOs) gespawnt!");
    if (Teleporter < TW_GO_ANZAHL_TELEPORTER)
        sLog->outErrorDb("TAUSENDWINTER: Es sind nicht alle Teleporter (GOs) gespawnt!");
}

void Tausendwinter::ErstellePOIListe()
{
    for (uint32 i=0; i<sAreaPOIStore.GetNumRows(); ++i)
    {
        const AreaPOIEntry * poiInfo = sAreaPOIStore.LookupEntry(i);
        if (poiInfo && poiInfo->zoneId == NORDEND_TAUSENDWINTER)
            m_PoIListe.push_back(poiInfo);
    }
}

// Gameobjekt Statusliste sowie PoIs und CPs erstellen
bool Tausendwinter::ErstelleGOStatusMap()
{
    ErstellePOIListe();

    for (GOMap::const_iterator GOiter = m_GOMap.begin(); GOiter != m_GOMap.end(); ++GOiter)
    {
        uint32 GOGUID = (*GOiter).second->m_GUID;

        GameObjectData const * goData = sObjectMgr->GetGOData(GOGUID);
        if (!goData)
            continue;

        float x = goData->posX, y = goData->posY;
        float minDist = 100;

        POIListe::iterator poi = m_PoIListe.end();
        for (POIListe::iterator PoIiter = m_PoIListe.begin(); PoIiter != m_PoIListe.end(); ++PoIiter)
        {
            if (!(*PoIiter)->icon[1]) // note: may for other use
                continue;

            float dist = (abs((*PoIiter)->x - x) + abs((*PoIiter)->y - y));
            if (minDist > dist)
            {
                minDist = dist;
                poi = PoIiter;
            }
        }
        if (poi == m_PoIListe.end())
            continue;

        TeamId teamId = x > TW_ZENTRUM_X ? m_VerteidigerTeamId : HoleAngreiferTeamId();
        m_GOStatus[GOGUID] = new GOStatus((*poi)->worldState, teamId, m_VerteidigerTeamId != TEAM_ALLIANCE);

        if ((*poi)->id == TW_POI_FESTUNGSTUER)
        {
            m_Festungstuer = m_GOStatus[GOGUID];
            m_Festungstuer->m_Typ = TUER;
        }

        uint32 CapturePointID = 0;
        switch(goData->id)
        {
            case TW_GO_GOBLINWERKSTATT_TEMPEL:      CapturePointID = TW_GO_BANNER_DER_NW_FABRIK_TEMPEL; break;
            case TW_GO_GOBLINWERKSTATT_RING:        CapturePointID = TW_GO_BANNER_DER_NO_FABRIK_RING; break;
            case TW_GO_GOBLINWERKSTATT_WESTFUNK:    CapturePointID = TW_GO_BANNER_DER_SW_FABRIK_WESTFUNK; break;
            case TW_GO_GOBLINWERKSTATT_OSTFUNK:     CapturePointID = TW_GO_BANNER_DER_SO_FABRIK_OSTFUNK; break;
        }

        if (CapturePointID)
        {
            uint32 IngGUID = 0;
            uint32 GeistGUID = 0;
            uint32 KontrolleGUID = 0;
            float IngiMinDist = 100;
            float GeistMinDist = 255;
            float KontrolleMinDist = 100;

            // Verwüstungsingenieur und Geisterführer für diese Werkstatt finden
            for (NPCMap::const_iterator NPCiter = m_NPCMap.begin(); NPCiter != m_NPCMap.end(); ++NPCiter)
            {
                if ((*NPCiter).second->m_Typ != TW_NPC_TYP_VERWUESTERINGENIEUR &&
                    (*NPCiter).second->m_Typ != TW_NPC_TYP_GEISTERFUEHRER &&
                    (*NPCiter).second->m_Typ != TW_NPC_TYP_WAFFENKONTROLLE)
                    continue;

                CreatureData const * creData = sObjectMgr->GetCreatureData((*NPCiter).first);
                if (!creData)
                    continue;

                float dist = (abs(creData->posX - x) + abs(creData->posY - y));

                if (IngiMinDist > dist)
                {
                    if ((*NPCiter).second->m_Typ == TW_NPC_TYP_VERWUESTERINGENIEUR)
                    {
                        IngiMinDist = dist;
                        IngGUID = (*NPCiter).first;
                    }
                }
                if (GeistMinDist > dist)
                {
                    if ((*NPCiter).second->m_Typ == TW_NPC_TYP_GEISTERFUEHRER)
                    {
                        GeistMinDist = dist;
                        GeistGUID = (*NPCiter).first;
                    }
                }
                if (KontrolleMinDist > dist)
                {
                    if ((*NPCiter).second->m_Typ == TW_NPC_TYP_WAFFENKONTROLLE)
                    {
                        KontrolleMinDist = dist;
                        KontrolleGUID = (*NPCiter).first;
                    }
                }
            }

            if (!IngGUID)
            {
                sLog->outError("TAUSENDWINTER: Kann keinen passenden Verwüstungsingenieur für die Werkstatt %u (GO) finden!", goData->id);
                continue;
            }
            if (!GeistGUID)
            {
                sLog->outError("TAUSENDWINTER: Kann keinen passenden Geisterführer für die Werkstatt %u (GO) finden!", goData->id);
                continue;
            }
            if (!KontrolleGUID)
            {
                sLog->outError("TAUSENDWINTER: Kann keine passende Waffenkontrolle für die Werkstatt %u (GO) finden!", goData->id);
                continue;
            }

            TausendwinterCapturePoint * Werkstatt = new TausendwinterCapturePoint(this, m_GOStatus[GOGUID]);
            if (goData->posX < TW_ZENTRUM_X && !Werkstatt->SetCapturePointData(CapturePointID, goData->mapid, goData->posX + 40 * cos(goData->orientation + M_PI / 2),
                goData->posY + 40 * sin(goData->orientation + M_PI / 2), goData->posZ)) // Werkstätten innerhalb der Festung kann man nicht einnehmen
            {
                sLog->outError("TAUSENDWINTER: Kann den CapturePoint für die Werkstatt %u (GO) nicht erstellen!", goData->id);
                delete Werkstatt;
                continue;
            }

            CreatureData const * ingiData = sObjectMgr->GetCreatureData(IngGUID);
            if (!ingiData)
                continue;

            Werkstatt->m_IngiID = const_cast<uint32*>(&ingiData->id);
            Werkstatt->m_IngiGUID = IngGUID;

            CreatureData const * spiritData = sObjectMgr->GetCreatureData(GeistGUID);
            if (!spiritData)
                continue;

            Werkstatt->m_GeistID = const_cast<uint32*>(&spiritData->id);
            Werkstatt->m_GeistGUID = GeistGUID;

            CreatureData const * kontrolleData = sObjectMgr->GetCreatureData(KontrolleGUID);
            if (!kontrolleData)
                continue;

            Werkstatt->m_KontrolleID = const_cast<uint32*>(&kontrolleData->id);
            Werkstatt->m_KontrolleGUID = KontrolleGUID;

            Werkstatt->AnzahlFahrzeuge = 0;
            Werkstatt->m_WerkstattGUID = GOGUID;
            m_GOStatus[GOGUID]->m_Typ = WERKSTATT;
            Werkstatt->SetzeTeamIdEntsprechendDemGOStatus();

            AddCapturePoint(Werkstatt);
        }
    }

    if (!m_Festungstuer)
    {
        sLog->outError("TAUSENDWINTER: Kann die Festungstür (den PoI) nicht finden!");
        return false;
    }

    return true;
}

// Friedhöfe zuordnen / erstellen
void Tausendwinter::OrdneFriedhoefeZu()
{
    GraveYardMap::const_iterator graveLow = sObjectMgr->mGraveYardMap.lower_bound(NORDEND_TAUSENDWINTER);
    GraveYardMap::const_iterator graveUp  = sObjectMgr->mGraveYardMap.upper_bound(NORDEND_TAUSENDWINTER);

    for (POIListe::iterator iter = m_PoIListe.begin(); iter != m_PoIListe.end();)
    {
        if ((*iter)->icon[1] == 8)
        {
            WorldSafeLocsEntry const * loc = sObjectMgr->GetClosestGraveYard((*iter)->x, (*iter)->y, (*iter)->z, (*iter)->mapId, 0);
            if (!loc)
            {
                ++iter;
                continue;
            }
            GraveYardMap::const_iterator FriedhofIter;
            for (FriedhofIter = graveLow; FriedhofIter != graveUp; ++FriedhofIter)
                if (FriedhofIter->second.safeLocId == loc->ID)
                    break;

            if (FriedhofIter == graveUp)
            {
                GraveYardData graveData;
                graveData.safeLocId = loc->ID;
                graveData.team = 0;
                FriedhofIter = sObjectMgr->mGraveYardMap.insert(std::make_pair(NORDEND_TAUSENDWINTER, graveData));
            }

            for (GOStatusMap::iterator StatusIter = m_GOStatus.begin(); StatusIter != m_GOStatus.end(); ++StatusIter)
            {
                if (StatusIter->second->m_WeltStatus == (*iter)->worldState)
                {
                    StatusIter->second->m_FriedhofsTeam = const_cast<uint32*>(&FriedhofIter->second.team);
                    break;
                }
            }
            m_PoIListe.erase(iter++);
        }
        else
            ++iter;
    }
    // Die m_PoIListe wird hiernach nicht mehr genutzt, also leeren wir sie
    m_PoIListe.clear();
}

// NPC / GO Display Paare laden
void Tausendwinter::LadeTeamPaare(TeamPaarMap & PaarMap, TeamPaar const * Paar)
{
    while((*Paar)[0])
    {
        PaarMap[(*Paar)[TEAM_ALLIANCE]] = (*Paar)[TEAM_HORDE];
        PaarMap[(*Paar)[TEAM_HORDE]]    = (*Paar)[TEAM_ALLIANCE];
        ++Paar;
    }
}

// Spieler wird wiederbelebt
void Tausendwinter::HandlePlayerResurrects(Player * pPl, uint32 zone)
{
    if (!sWorld->getBoolConfig(CONFIG_TW_AKTIVIERT) || !pPl)
        return;

    if (m_Kampf)
    {
        if (pPl->getLevel() >= TW_MINIMUM_LEVEL)
        {
            // Hartnäckigkeit
            if (pPl->GetTeamId() == TEAM_ALLIANCE && m_HartnaeckigkeitsStapel > 0 || pPl->GetTeamId() == TEAM_HORDE && m_HartnaeckigkeitsStapel < 0)
            {
                if (pPl->HasAura(SPELL_HARTNAECKIGKEIT))
                    pPl->RemoveAurasDueToSpell(SPELL_HARTNAECKIGKEIT);

                int32 NeueStapel = m_HartnaeckigkeitsStapel < 0 ? -m_HartnaeckigkeitsStapel : m_HartnaeckigkeitsStapel;

                if (NeueStapel > 20)
                    NeueStapel = 20;

                pPl->SetAuraStack(SPELL_HARTNAECKIGKEIT, pPl, NeueStapel);
            }
            // Turmkontrolle
            if (pPl->GetTeamId() == HoleAngreiferTeamId())
            {
                if (m_ZerstoerteTuerme[HoleAngreiferTeamId()] < 3)
                    pPl->SetAuraStack(SPELL_TURMKONTROLLE, pPl, 3 - m_ZerstoerteTuerme[HoleAngreiferTeamId()]);
            }
            else
            {
                if (m_ZerstoerteTuerme[HoleAngreiferTeamId()])
                    pPl->SetAuraStack(SPELL_TURMKONTROLLE, pPl, m_ZerstoerteTuerme[HoleAngreiferTeamId()]);
            }
        }
    }
    AktualisiereEssenzVonTausendwinter(pPl, zone);
    OutdoorPvP::HandlePlayerResurrects(pPl, zone);
}

// Essenz von Tausendwinter Spells aktualisieren
void Tausendwinter::AktualisiereEssenzVonTausendwinter(Player * pPl, uint32 ZoneId)
{
    if (!pPl || !ZoneId)
        return;

    if (!sWorld->getBoolConfig(CONFIG_TW_AKTIVIERT) || m_Kampf || pPl->GetTeamId() != m_VerteidigerTeamId)
    {
        pPl->RemoveAurasDueToSpell(SPELL_ESSENZ_VON_TAUSENDWINTER_TW);
        pPl->RemoveAurasDueToSpell(SPELL_ESSENZ_VON_TAUSENDWINTER_NORDEND);
        return;
    }

    switch(ZoneId)
    {   // Offene Gebiete
        case NORDEND_BOREANISCHE_TUNDRA:
        case NORDEND_KRISTALLSANGWALD:
        case NORDEND_DALARAN:
        case NORDEND_DRACHENOEDE:
        case NORDEND_GRIZZLYHUEGEL:
        case NORDEND_HEULENDE_FJORD:
        case NORDEND_HROTHGARS_LANDESTELLE:
        case NORDEND_EISKRONE:
        case NORDEND_SHOLAZARBECKEN:
        case NORDEND_STURMGIPFEL:
        case NORDEND_ZULDRAK:
        // Dungeons
        case NORDEND_AHNKAHET:
        case NORDEND_AZJOL_NERUB:
        case NORDEND_AUSMERZEN_VON_STRATHOLME:
        case NORDEND_PRUEFUNG_DES_CHAMPIONS:
        case NORDEND_FESTE_DRAKTHARON:
        case NORDEND_GUNDRAK:
        case NORDEND_NEXUS:
        case NORDEND_OCULUS:
        case NORDEND_VIOLETTE_FESTUNG:
        case NORDEND_HALLEN_DER_BLITZE:
        case NORDEND_HALLEN_DES_STEINS:
        case NORDEND_BURG_UTGARDE:
        case NORDEND_TURM_UTGARDE:
        case NORDEND_SELENSCHMIEDE:
        case NORDEND_GRUBE_VON_SARON:
        case NORDEND_HALLEN_DER_REFLEKTION:
            pPl->RemoveAurasDueToSpell(SPELL_ESSENZ_VON_TAUSENDWINTER_TW);
            if (!pPl->HasAura(SPELL_ESSENZ_VON_TAUSENDWINTER_NORDEND))
                pPl->CastSpell(pPl, SPELL_ESSENZ_VON_TAUSENDWINTER_NORDEND, true);
            break;
        case NORDEND_TAUSENDWINTER:
            pPl->RemoveAurasDueToSpell(SPELL_ESSENZ_VON_TAUSENDWINTER_NORDEND);
            if (!pPl->HasAura(SPELL_ESSENZ_VON_TAUSENDWINTER_TW))
                pPl->CastSpell(pPl, SPELL_ESSENZ_VON_TAUSENDWINTER_TW, true);
            break;
        default:
            pPl->RemoveAurasDueToSpell(SPELL_ESSENZ_VON_TAUSENDWINTER_TW);
            pPl->RemoveAurasDueToSpell(SPELL_ESSENZ_VON_TAUSENDWINTER_NORDEND);
            break;
    }
}

// TeamId für Fraktion ermitteln
TeamId Tausendwinter::HoleNPCTeamId(const uint32 fraktion)
{
    switch(fraktion)
    {
        case   84:
        case  534:
        case 1732:
        case 1891:
        case 1892:
            return TEAM_ALLIANCE;

        case   83:
        case  714:
        case 1735:
        case 1979:
        case 1981:
            return TEAM_HORDE;

        default:
            return TEAM_NEUTRAL;
    }
}

// Archavons Kammer - NPCs versteinern
void Tausendwinter::DarfAngegriffenWerden(Creature * pCr)
{
    if (!pCr)
        return;

    if (!sWorld->getBoolConfig(CONFIG_TW_AKTIVIERT) || m_Kampf || HoleZeitInMinuten() < 15)
    {
        pCr->AI()->EnterEvadeMode();
        pCr->CastSpell(pCr, SPELL_VERSTEINERT, true);
        pCr->SetUInt32Value(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_DISABLE_MOVE);
        pCr->SetReactState(REACT_PASSIVE);
    }
    else
    {
        pCr->RemoveAurasDueToSpell(SPELL_VERSTEINERT);
        pCr->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE|UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_DISABLE_MOVE);
        pCr->SetReactState(REACT_AGGRESSIVE);
    }
}

// Archavons Kammer - Zugang zur Instanz
bool Tausendwinter::DarfArchavonsKammerBetreten(Player * pPl)
{
    if (!sWorld->getBoolConfig(CONFIG_TW_AKTIVIERT) || !pPl || m_Kampf || m_VerteidigerTeamId != pPl->GetTeamId())
        return false;

    return true;
}

// GOs spawnen
void Tausendwinter::SpawnGO(uint32 GUID, GameObjectData const * GOData)
{
    sObjectMgr->AddGameobjectToGrid(GUID, GOData);

    if (Map * map = const_cast<Map*>(sMapMgr->CreateBaseMap(GOData->mapid)))
    {
        if (!map->IsLoaded(GOData->posX, GOData->posY))
            return;

        if (GameObject * pGO = new GameObject)
        {
            if (!pGO->LoadFromDB(GUID, map))
                delete pGO;
            else
                if (pGO->isSpawnedByDefault())
                    map->Add(pGO);
        }
    }
}

// GOs entfernen
void Tausendwinter::EntferneGO(uint32 GUID, GameObjectData const * GOData)
{
    sObjectMgr->RemoveGameobjectFromGrid(GUID, GOData);
    if (GameObject * pGO = sObjectAccessor->GetObjectInWorld(MAKE_NEW_GUID(GUID, GOData->id, HIGHGUID_GAMEOBJECT), (GameObject*)NULL))
        pGO->AddObjectToRemoveList();
}

// NPC spawnen
void Tausendwinter::SpawnNPC(uint32 GUID, CreatureData const * NPCData)
{
    sObjectMgr->AddCreatureToGrid(GUID, NPCData);

    if (Map * map = const_cast<Map*>(sMapMgr->CreateBaseMap(TW_KARTE)))
    {
        if (!map->IsLoaded(NPCData->posX, NPCData->posY))
            map->LoadGrid(NPCData->posX, NPCData->posY);

        if (Creature * pCr = new Creature)
        {
            if (!pCr->LoadFromDB(GUID, map))
                delete pCr;
            else
            {
                map->Add(pCr);

                if (!pCr->isAlive())
                    pCr->Respawn(true);
            }
        }
    }
}

// NPC entfernen
void Tausendwinter::EntferneNPC(uint32 GUID, CreatureData const * NPCData)
{
    sObjectMgr->RemoveCreatureFromGrid(GUID, NPCData);
    if (Creature * pCr = sObjectAccessor->GetObjectInWorld(MAKE_NEW_GUID(GUID, NPCData->id, HIGHGUID_UNIT), (Creature*)NULL))
        pCr->AddObjectToRemoveList();
}

// Portale beim Start des Realms aus der Welt entfernen, und überzählige löschen
void Tausendwinter::ErstelleDalaranPortalSet(QueryResult result)
{
    if (!result)
        return;

    do
    {
        Field * fields = result->Fetch();
        m_DalaranPortaleSet.insert(fields[0].GetUInt32());
    } while (result->NextRow());

    switch(m_DalaranPortaleSet.size())
    {
        case 0:
            sLog->outErrorDb("TAUSENDWINTER: Es sind keine Dalaran Portale nach Tausendwinter gespawnt!");
            return;
        case 1:
            sLog->outErrorDb("TAUSENDWINTER: Es ist nur ein Dalaran Portal nach Tausendwinter gespawnt!");
            break;
        case 2:
            sLog->outDebug(LOG_FILTER_NONE, "TAUSENDWINTER: Es wurden genau zwei Dalaran nach Tausendwinter Portale gefunden.");
            break;
        default:
            sLog->outErrorDb("TAUSENDWINTER: Es sind mehr als zwei Dalaran Portale nach Tausendwinter gespawnt!");
            sLog->outErrorDb("TAUSENDWINTER: Nutze / behandel nur die ersten beiden, und entferne den Rest aus der Welt.");
            break;
    }

    uint8 cnt = 0;
    // Beim start des Realms erst einmal alle aus der Welt entfernen, und überzählige löschen
    for (GOGUIDSet::iterator iter = m_DalaranPortaleSet.begin(); iter != m_DalaranPortaleSet.end(); ++iter)
    {
        ++cnt;

        GameObjectData const * GOData = const_cast<GameObjectData*> (sObjectMgr->GetGOData(*iter));
        if (!GOData)
        {
            sLog->outError("TAUSENDWINTER: Konnte für ein Dalaran Portal nach Tausendwinter keine GameOjectData erstellen!");
            m_DalaranPortaleSet.erase(iter++);
            continue;
        }
        else if (cnt >= 3)
        {
            EntferneGO(*iter, GOData);
            m_DalaranPortaleSet.erase(iter++);
            continue;
        }
        else
            EntferneGO(*iter, GOData);
    }
    UeberpruefeDalaranPortal();
}

// Immer nur das Portal spawnen, welches auf der Seite des Verteidigerteams steht
void Tausendwinter::UeberpruefeDalaranPortal()
{
    if (!m_DalaranPortaleSet.size())
        return;

    for (GOGUIDSet::const_iterator iter = m_DalaranPortaleSet.begin(); iter != m_DalaranPortaleSet.end(); ++iter)
    {
        GameObjectData const * GOData = const_cast<GameObjectData*> (sObjectMgr->GetGOData(*iter));
        if (!GOData)
            continue;

        // Anhand der Koords schauen, welches Portal wir gerade bearbeiten
        if (GOData->posY >= TW_PORTAL_NACH_TAUSENDWINTER_A_POS_Y_MIN)
        {
            // Ally Portal
            if (m_VerteidigerTeamId == TEAM_HORDE)
                EntferneGO(*iter, GOData);
            else
                SpawnGO(*iter, GOData);
        }
        else
        {
            // Horde Portal
            if (m_VerteidigerTeamId == TEAM_ALLIANCE)
                EntferneGO(*iter, GOData);
            else
                SpawnGO(*iter, GOData);
        }
    }
}

// Da es aus irgendwelchen Gründen (irgendwie) möglich ist, dass Spieler PvP ausschalten können, müssen wir dies überprüfen!
// TODO: In den Katakomben des Core nach dem Grund für diese PvPFlag Fehler suchen!
void Tausendwinter::PvPCheck()
{
    for (uint8 teamId=TEAM_ALLIANCE; teamId<=TEAM_HORDE; ++teamId)
        for (PlayerSet::const_iterator iter = OutdoorPvP::m_players[teamId].begin(); iter != OutdoorPvP::m_players[teamId].end(); ++iter)
            if ((*iter) && !(*iter)->IsPvP())
                (*iter)->SetPvP(true);

    m_PvPCheckZeit = TW_PVP_CHECKZEIT;
}

void Tausendwinter::SendeStatusAenderung(GOStatus * status) const
{
    if (OutdoorPvP::m_sendUpdate)
        for (uint8 i=TEAM_ALLIANCE; i<TEAM_HORDE; ++i)
            for (PlayerSet::const_iterator iter = m_players[i].begin(); iter != m_players[i].end(); ++iter)
                if ((*iter))
                    status->SendUpdate(*iter);
}

void Tausendwinter::FillInitialWorldStates(WorldPacket & data)
{
    data << uint32(TW_STATUS_KONTROLLIER_VON_DER_ALLIANZ) << uint32(m_VerteidigerTeamId == TEAM_ALLIANCE ? 1 : 0);
    data << uint32(TW_STATUS_KONTROLLIER_VON_DER_HORDE) << uint32(m_VerteidigerTeamId != TEAM_ALLIANCE ? 1 : 0);
    data << uint32(3801) << uint32(m_Kampf ? 0 : 1);
    data << uint32(3710) << uint32(m_Kampf ? 1 : 0);

    for (uint8 i=TEAM_ALLIANCE; i<=TEAM_HORDE; ++i)
        data << WeltStatusZeit[i] << m_TeamZeit[i];

    data << uint32(TW_STATUS_FAHRZEUGE_ANZAHL_A) << uint32(m_FahrzeugSet[TEAM_ALLIANCE].size());
    data << uint32(TW_STATUS_FAHRZEUGE_MAXIMAL_A) << m_AnzahlWerkstaetten[TEAM_ALLIANCE] * TW_WERKSTATT_FAHRZEUGE;

    data << uint32(TW_STATUS_FAHRZEUGE_ANZAHL_H) << uint32(m_FahrzeugSet[TEAM_HORDE].size());
    data << uint32(TW_STATUS_FAHRZEUGE_MAXIMAL_H) << m_AnzahlWerkstaetten[TEAM_HORDE] * TW_WERKSTATT_FAHRZEUGE;

    for (GOStatusMap::const_iterator iter = m_GOStatus.begin(); iter != m_GOStatus.end(); ++iter)
        (*iter).second->FillData(data);
}

// Weltstatusdaten senden
void Tausendwinter::SendeWeltstatus(Player * pPl) const
{
    WorldPacket data(SMSG_INIT_WORLD_STATES, (4+4+4+2+(m_GOStatus.size()*8)));

    data << uint32(TW_KARTE);
    data << uint32(NORDEND_TAUSENDWINTER);
    data << uint32(0);
    data << uint16(4+2+4+m_GOStatus.size());

    data << uint32(TW_STATUS_KONTROLLIER_VON_DER_ALLIANZ) << uint32(m_VerteidigerTeamId == TEAM_ALLIANCE ? 1 : 0);
    data << uint32(TW_STATUS_KONTROLLIER_VON_DER_HORDE) << uint32(m_VerteidigerTeamId != TEAM_ALLIANCE ? 1 : 0);
    data << uint32(3801) << uint32(m_Kampf ? 0 : 1);
    data << uint32(3710) << uint32(m_Kampf ? 1 : 0);

    for (uint8 i=0; i<2; ++i)
        data << WeltStatusZeit[i] << m_TeamZeit[i];

    data << uint32(TW_STATUS_FAHRZEUGE_ANZAHL_A) << uint32(m_FahrzeugSet[TEAM_ALLIANCE].size());
    data << uint32(TW_STATUS_FAHRZEUGE_MAXIMAL_A) << m_AnzahlWerkstaetten[TEAM_ALLIANCE] * TW_WERKSTATT_FAHRZEUGE;

    data << uint32(TW_STATUS_FAHRZEUGE_ANZAHL_H) << uint32(m_FahrzeugSet[TEAM_HORDE].size());
    data << uint32(TW_STATUS_FAHRZEUGE_MAXIMAL_H) << m_AnzahlWerkstaetten[TEAM_HORDE] * TW_WERKSTATT_FAHRZEUGE;

    for (GOStatusMap::const_iterator iter = m_GOStatus.begin(); iter != m_GOStatus.end(); ++iter)
        (*iter).second->FillData(data);

    if (pPl)
        pPl->GetSession()->SendPacket(&data);
    else
        OutdoorPvP::BroadcastPacket(data);
}

void Tausendwinter::HandlePlayerEnterZone(Player * pPl, uint32 zone)
{
    if (!sWorld->getBoolConfig(CONFIG_TW_AKTIVIERT) || !pPl)
        return;

    bool UnMount = true;
    bool CntPlr = true;

    // Spieler die nicht in TW landen wollen (Flugroute), nicht buffen / zählen  / unmounten etc...
    if (!pPl->m_taxi.empty())
    {
        UnMount = false;

        if (uint32 Dest = pPl->m_taxi.GetTaxiDestination())
        {
            TaxiNodesEntry const* DestNode = sTaxiNodesStore.LookupEntry(Dest);
            if (DestNode->ID != TW_FP_ALLIANZ && DestNode->ID != TW_FP_HORDE)
                CntPlr = false;
        }
    }

    // Da das PvPFlag System nicht wirklich korrekt funktioniert, muss dies zur Sicherheit sein!
    if (CntPlr && !pPl->IsPvP())
        pPl->SetPvP(true);

    // Niemand hat jemals mit einem Fahrzeug (egal welcher Art!) TW zu betreten! Schon vorgekommen! :-(
    if (Vehicle * Veh = pPl->GetVehicle())
    {
        if (Veh->GetBase())
            Veh->GetBase()->ToCreature()->ForcedDespawn();

        pPl->CastSpell(pPl, SPELL_LANGSAMER_FALL, true);
    }

    if (CntPlr)
    {
        if (m_Kampf)
        {   // Im Kampf hat niemand etwas mit einem Flugmount / "Flugzeug" / Flugform in TW zu suchen!
            if (UnMount && (pPl->IsFlying() || pPl->isInFlight() || pPl->IsMounted() || pPl->GetVehicle() || pPl->HasAuraType(SPELL_AURA_MOD_SHAPESHIFT)))
            {
                pPl->RemoveAurasByType(SPELL_AURA_MOD_SHAPESHIFT);
                pPl->Unmount();

                if (Vehicle * Veh = pPl->GetVehicle())
                    if (Veh->GetBase())
                        Veh->GetBase()->ToCreature()->setDeathState(JUST_DIED);

                // TODO: Besseren / "korrekten" Spell suchen!
                pPl->CastSpell(pPl, SPELL_LANGSAMER_FALL, true);
            }

            if (pPl->getLevel() >= TW_MINIMUM_LEVEL)
            {
                if (!pPl->HasAura(SPELL_REKRUT) && !pPl->HasAura(SPELL_FAEHNRICH) && !pPl->HasAura(SPELL_OBERLEUTNANT))
                    pPl->CastSpell(pPl, SPELL_REKRUT, true);

                if (pPl->GetTeamId() == HoleAngreiferTeamId())
                {
                    if (m_ZerstoerteTuerme[HoleAngreiferTeamId()] < 3)
                        pPl->SetAuraStack(SPELL_TURMKONTROLLE, pPl, 3 - m_ZerstoerteTuerme[HoleAngreiferTeamId()]);
                }
                else
                {
                    if (m_ZerstoerteTuerme[HoleAngreiferTeamId()])
                        pPl->SetAuraStack(SPELL_TURMKONTROLLE, pPl, m_ZerstoerteTuerme[HoleAngreiferTeamId()]);
                }
                pPl->CastSpell(pPl, SPELL_REGELN_VON_TAUSENDWINTER, true);
            }
        }
        else
        {
            pPl->RemoveAurasDueToSpell(SPELL_REKRUT);
            pPl->RemoveAurasDueToSpell(SPELL_FAEHNRICH);
            pPl->RemoveAurasDueToSpell(SPELL_OBERLEUTNANT);
            pPl->RemoveAurasDueToSpell(SPELL_TURMKONTROLLE);
            pPl->RemoveAurasDueToSpell(SPELL_GEISTIGE_IMMUNITAET);
            pPl->RemoveAurasDueToSpell(SPELL_HARTNAECKIGKEIT);
            pPl->RemoveAurasDueToSpell(SPELL_REGELN_VON_TAUSENDWINTER);
            pPl->RemoveAurasDueToSpell(SPELL_SIEG_AURA);
        }
        SendeWeltstatus(pPl);

        AktualisiereHartnaeckigkeitsStapel();
    }
    OutdoorPvP::HandlePlayerEnterZone(pPl, zone);
}

void Tausendwinter::HandlePlayerLeaveZone(Player * pPl, uint32 zone)
{
    if (!sWorld->getBoolConfig(CONFIG_TW_AKTIVIERT))
        return;

    // Nur Spieler behandeln, die nicht auf einer Flugroute sind!
    if (pPl->m_taxi.empty())
    {
        if (!pPl->GetSession()->PlayerLogout())
        {   // Niemand verlässt den Saal mit Fahrzeug! :-)
            if (Vehicle * Veh = pPl->GetVehicle())
                Veh->Dismiss();

            pPl->RemoveAurasDueToSpell(SPELL_REKRUT);
            pPl->RemoveAurasDueToSpell(SPELL_FAEHNRICH);
            pPl->RemoveAurasDueToSpell(SPELL_OBERLEUTNANT);
            pPl->RemoveAurasDueToSpell(SPELL_TURMKONTROLLE);
            pPl->RemoveAurasDueToSpell(SPELL_GEISTIGE_IMMUNITAET);
            pPl->RemoveAurasDueToSpell(SPELL_REGELN_VON_TAUSENDWINTER);
            pPl->RemoveAurasDueToSpell(SPELL_SIEG_AURA);
        }
        pPl->RemoveAurasDueToSpell(SPELL_HARTNAECKIGKEIT);

        if (pPl->isAlive())
            RemovePlayerFromResurrectQueue(pPl->GetGUID());

        AktualisiereHartnaeckigkeitsStapel();

        pPl->SetPvP(false);

        if (m_Kampf)
            pPl->RemoveFromGroup(GROUP_REMOVEMETHOD_LEAVE);
    }
    OutdoorPvP::HandlePlayerLeaveZone(pPl, zone);
}

// Spieler die in TW sind (während der Kampf startet) automatisch zu einem Raid hinzufügen
void Tausendwinter::FuegeSpielerZumRaidHinzu(Player * pPlr, TeamId teamId)
{
    if (!pPlr)
        return;

    if (!m_Raid[teamId]->IsCreated())
    {
        m_Raid[teamId]->Create(pPlr);
        m_Raid[teamId]->ConvertToRaid();
        m_Raid[teamId]->SetRaidDifficulty(REGULAR_DIFFICULTY);
        sGroupMgr->AddGroup(m_Raid[teamId]);
    }
    else
        m_Raid[teamId]->AddMember(pPlr);
}

void Tausendwinter::OnGameObjectCreate(GameObject * go)
{
    OutdoorPvP::OnGameObjectCreate(go);

    GOMap::iterator iter = m_GOMap.find(go->GetDBTableGUIDLow());
    if (iter != m_GOMap.end())
        (*iter).second->m_GameObject = go;

    if (go->GetEntry() == m_Relikt->m_ID)
        m_Relikt->m_GameObject = go;

    AktualisiereGO(go);

    if (go->GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
    {
        GOStatusMap::const_iterator iter = m_GOStatus.find(go->GetDBTableGUIDLow());
        if (iter != m_GOStatus.end())
        {
            iter->second->m_GameObject = go;

            switch(go->GetGOInfo()->displayId)
            {
                case TW_GO_DISPLAY_FESTUNGSTUERME:
                    go->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[m_VerteidigerTeamId]);
                    go->UpdateObjectVisibility();
                    iter->second->m_Typ = TURM;
                    break;

                case TW_GO_DISPLAY_TUERME:
                    go->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[OTHER_TEAM(m_VerteidigerTeamId)]);
                    go->UpdateObjectVisibility();
                    iter->second->m_Typ = TURM;
                    break;

                case TW_GO_DISPLAY_WALL:
                case TW_GO_DISPLAY_FESTUNGSWALL:
                    go->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[m_VerteidigerTeamId]);
                    go->UpdateObjectVisibility();
                    iter->second->m_Typ = WALL;
                    break;

                case TW_GO_DISPLAY_WERKSTATT:
                    iter->second->m_Typ = WERKSTATT;
                    if (IstInDerFestung(go))
                    {
                        go->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[m_VerteidigerTeamId]);
                        go->UpdateObjectVisibility();
                    }
                    else
                    {
                        go->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[OTHER_TEAM(m_VerteidigerTeamId)]);
                        go->UpdateObjectVisibility();
                    }
                    break;

                case TW_GO_DISPLAY_FESTUNGSTOR:
                    go->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[m_VerteidigerTeamId]);
                    go->UpdateObjectVisibility();
                    iter->second->m_Typ = TOR;
                    break;

                case TW_GO_DISPLAY_FESTUNGSTUER:
                    go->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[m_VerteidigerTeamId]);
                    go->UpdateObjectVisibility();
                    iter->second->m_Typ = TUER;
                    break;
            }

            if (iter->second->m_SchadensStatus == INTAKT && !iter->second->m_Health)
                iter->second->m_Health = go->GetGOValue()->Building.Health;
            else
            {
                go->GetGOValue()->Building.Health = iter->second->m_Health;

                if (iter->second->m_SchadensStatus == BESCHAEDIGT)
                    go->SetUInt32Value(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED);
                else if (iter->second->m_SchadensStatus == ZERSTOERT)
                    go->SetUInt32Value(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
            }
        }
    }
}

void Tausendwinter::OnGameObjectRemove(GameObject * go)
{
    OutdoorPvP::OnGameObjectRemove(go);

    GOMap::iterator iter = m_GOMap.find(go->GetDBTableGUIDLow());
    if (iter != m_GOMap.end())
        (*iter).second->m_GameObject = NULL;

    if (go->GetEntry() == m_Relikt->m_ID)
        m_Relikt->m_GameObject = NULL;

    if (go->GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
    {
        GOStatusMap::const_iterator iter = m_GOStatus.find(go->GetDBTableGUIDLow());
        if (iter != m_GOStatus.end())
        {
            iter->second->m_GameObject = NULL;

            if (iter->second->m_SchadensStatus == INTAKT && !iter->second->m_Health)
                iter->second->m_Health = go->GetGOValue()->Building.Health;
            else
            {
                go->GetGOValue()->Building.Health = iter->second->m_Health;

                if (iter->second->m_SchadensStatus == BESCHAEDIGT)
                    go->SetUInt32Value(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED);
                else if (iter->second->m_SchadensStatus == ZERSTOERT)
                    go->SetUInt32Value(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
            }
        }
    }
}

void Tausendwinter::OnCreatureCreate(Creature * pCr)
{
    NPCMap::iterator iter = m_NPCMap.find(pCr->GetDBTableGUIDLow());
    if (iter != m_NPCMap.end())
        (*iter).second->m_Creature = pCr;

    AktualisiereNPC(pCr);

    switch(HoleNPCTyp(pCr->GetEntry()))
    {
        case TW_NPC_TYP_GEISTERFUEHRER:
            for (OutdoorPvP::OPvPCapturePointMap::const_iterator iter = OutdoorPvP::m_capturePoints.begin(); iter != OutdoorPvP::m_capturePoints.end(); ++iter)
                if (TausendwinterCapturePoint * Werkstatt = dynamic_cast<TausendwinterCapturePoint*> (iter->second))
                    if (Werkstatt->m_GeistGUID == pCr->GetDBTableGUIDLow())
                    {
                        Werkstatt->m_Geist = pCr;
                        break;
                    }
            break;

        case TW_NPC_TYP_VERWUESTERINGENIEUR:
            for (OutdoorPvP::OPvPCapturePointMap::const_iterator iter = OutdoorPvP::m_capturePoints.begin(); iter != OutdoorPvP::m_capturePoints.end(); ++iter)
                if (TausendwinterCapturePoint * Werkstatt = dynamic_cast<TausendwinterCapturePoint*> (iter->second))
                    if (Werkstatt->m_IngiGUID == pCr->GetDBTableGUIDLow())
                    {
                        Werkstatt->m_Ingi = pCr;
                        break;
                    }
            break;

        case TW_NPC_TYP_BELAGERUNGSMASCHINE:
        case TW_NPC_TYP_KATAPULT:
        case TW_NPC_TYP_VERWUESTER:
            {
                TeamId teamId = TEAM_NEUTRAL;
                if (pCr->getFaction() == Fraktionen[TEAM_ALLIANCE])
                    teamId = TEAM_ALLIANCE;
                else if (pCr->getFaction() == Fraktionen[TEAM_HORDE])
                    teamId = TEAM_HORDE;

                m_FahrzeugSet[teamId].insert(pCr);

                if (m_HartnaeckigkeitsStapel > 0 && teamId == TEAM_ALLIANCE)
                    pCr->SetAuraStack(SPELL_HARTNAECKIGKEIT_FAHRZEUGE, pCr, m_HartnaeckigkeitsStapel);
                else if (m_HartnaeckigkeitsStapel < 0 && teamId == TEAM_HORDE)
                    pCr->SetAuraStack(SPELL_HARTNAECKIGKEIT_FAHRZEUGE, pCr, -m_HartnaeckigkeitsStapel);

                OutdoorPvP::SendUpdateWorldState(WeltStatusAnzahlFahrzeuge[teamId], m_FahrzeugSet[teamId].size());
            }
            break;

        case TW_NPC_TYP_WAFFENKONTROLLE:
            if (IstInDerFestung(pCr))
                pCr->setFaction(Fraktionen[m_VerteidigerTeamId]);
            else for (OutdoorPvP::OPvPCapturePointMap::const_iterator iter = OutdoorPvP::m_capturePoints.begin(); iter != OutdoorPvP::m_capturePoints.end(); ++iter)
                if (TausendwinterCapturePoint * Werkstatt = dynamic_cast<TausendwinterCapturePoint*> (iter->second))
                    if (Werkstatt->m_KontrolleGUID == pCr->GetDBTableGUIDLow())
                    {
                        Werkstatt->m_Kontrolle = pCr;
                        if (Werkstatt->m_Ingi && Werkstatt->m_Kontrolle)
                            Werkstatt->m_Kontrolle->setFaction(Werkstatt->m_Ingi->getFaction());
                        break;
                    }
            break;
    }
}

void Tausendwinter::OnCreatureRemove(Creature * pCr)
{
    NPCMap::iterator iter = m_NPCMap.find(pCr->GetDBTableGUIDLow());
    if (iter != m_NPCMap.end())
        (*iter).second->m_Creature = NULL;

    switch(HoleNPCTyp(pCr->GetEntry()))
    {
        case TW_NPC_TYP_GEISTERFUEHRER:
            for (OutdoorPvP::OPvPCapturePointMap::const_iterator iter = OutdoorPvP::m_capturePoints.begin(); iter != OutdoorPvP::m_capturePoints.end(); ++iter)
                if (TausendwinterCapturePoint * Werkstatt = dynamic_cast<TausendwinterCapturePoint*> (iter->second))
                    if (Werkstatt->m_GeistGUID == pCr->GetDBTableGUIDLow())
                    {
                        Werkstatt->m_Geist = NULL;
                        break;
                    }
            break;

        case TW_NPC_TYP_VERWUESTERINGENIEUR:
            for (OutdoorPvP::OPvPCapturePointMap::const_iterator iter = OutdoorPvP::m_capturePoints.begin(); iter != OutdoorPvP::m_capturePoints.end(); ++iter)
                if (TausendwinterCapturePoint * Werkstatt = dynamic_cast<TausendwinterCapturePoint*> (iter->second))
                    if (Werkstatt->m_IngiGUID == pCr->GetDBTableGUIDLow())
                    {
                        Werkstatt->m_Ingi = NULL;
                        break;
                    }
            break;

        case TW_NPC_TYP_BELAGERUNGSMASCHINE:
        case TW_NPC_TYP_KATAPULT:
        case TW_NPC_TYP_VERWUESTER:
            {
                TeamId teamId = TEAM_NEUTRAL;
                if (pCr->getFaction() == Fraktionen[TEAM_ALLIANCE])
                    teamId = TEAM_ALLIANCE;
                else if (pCr->getFaction() == Fraktionen[TEAM_HORDE])
                    teamId = TEAM_HORDE;

                FahrzeugSet::iterator iter = m_FahrzeugSet[teamId].find(pCr);
                if (iter != m_FahrzeugSet[teamId].end())
                    m_FahrzeugSet[teamId].erase(pCr);

                OutdoorPvP::SendUpdateWorldState(WeltStatusAnzahlFahrzeuge[teamId], m_FahrzeugSet[teamId].size());
            }
            break;

        case TW_NPC_TYP_WAFFENKONTROLLE:
            for (OutdoorPvP::OPvPCapturePointMap::const_iterator iter = OutdoorPvP::m_capturePoints.begin(); iter != OutdoorPvP::m_capturePoints.end(); ++iter)
                if (TausendwinterCapturePoint * Werkstatt = dynamic_cast<TausendwinterCapturePoint*> (iter->second))
                    if (Werkstatt->m_KontrolleGUID == pCr->GetDBTableGUIDLow())
                    {
                        Werkstatt->m_Kontrolle = NULL;
                        break;
                    }
            break;
    }
}

TW_NPC_TYP Tausendwinter::HoleNPCTyp(const uint32 entry)
{
    switch(entry)
    {
        case TW_NPC_WACHE_A:
        case TW_NPC_WACHE_H:
            return TW_NPC_TYP_WACHE;
        case TW_NPC_CHAMPION_A:
        case TW_NPC_CHAMPION_H:
            return TW_NPC_TYP_CHAMPION;
        case TW_NPC_RUESTMEISTER_1_A:
        case TW_NPC_RUESTMEISTER_1_H:
            return TW_NPC_TYP_RUESTMEISTER_1;
        case TW_NPC_RUESTMEISTER_2_A:
        case TW_NPC_RUESTMEISTER_2_H:
            return TW_NPC_TYP_RUESTMEISTER_2;
        case TW_NPC_GEISTERFUEHRER_A:
        case TW_NPC_GEISTERFUEHRER_H:
            return TW_NPC_TYP_GEISTERFUEHRER;
        case TW_NPC_GEISTHEILER_A:
        //case TW_NPC_GEISTHEILER_H:
            return TW_NPC_TYP_GEISTHEILER;
        case TW_NPC_VERWUESTERINGENIEUR_A:
        case TW_NPC_VERWUESTERINGENIEUR_H:
            return TW_NPC_TYP_VERWUESTERINGENIEUR;
        case TW_NPC_VERZAUBERER_A:
        case TW_NPC_VERZAUBERER_H:
            return TW_NPC_TYP_VERZAUBERER;
        case TW_NPC_QUESTGEBER_1_A:
        case TW_NPC_QUESTGEBER_1_H:
            return TW_NPC_TYP_QUESTGEBER_1;
        case TW_NPC_QUESTGEBER_2_A:
        case TW_NPC_QUESTGEBER_2_H:
            return TW_NPC_TYP_QUESTGEBER_2;
        case TW_NPC_QUESTGEBER_3_A:
        case TW_NPC_QUESTGEBER_3_H:
            return TW_NPC_TYP_QUESTGEBER_3;
        case TW_NPC_QUESTGEBER_4_A:
        case TW_NPC_QUESTGEBER_4_H:
            return TW_NPC_TYP_QUESTGEBER_4;
        case TW_NPC_QUESTGEBER_5_A:
        case TW_NPC_QUESTGEBER_5_H:
            return TW_NPC_TYP_QUESTGEBER_5;
        case TW_NPC_QUESTGEBER_6_A:
        case TW_NPC_QUESTGEBER_6_H:
            return TW_NPC_TYP_QUESTGEBER_6;
        case TW_NPC_QUESTGEBER_PVP_1_A:
        case TW_NPC_QUESTGEBER_PVP_1_H:
            return TW_NPC_TYP_QUESTGEBER_PVP_1;
        case TW_NPC_QUESTGEBER_PVP_2_A:
        case TW_NPC_QUESTGEBER_PVP_2_H:
            return TW_NPC_TYP_QUESTGEBER_PVP_2;
        case TW_NPC_BELAGERUNGSMASCHINE_A:
        case TW_NPC_BELAGERUNGSMASCHINE_H:
            return TW_NPC_TYP_BELAGERUNGSMASCHINE;
        case TW_NPC_BELAGERUNGSTURM_A:
        case TW_NPC_BELAGERUNGSTURM_H:
            return TW_NPC_TYP_BELAGERUNGSTURM;
        case TW_NPC_KATAPULT_A:
        //case TW_NPC_KATAPULT_H:
            return TW_NPC_TYP_KATAPULT;
        case TW_NPC_VERWUESTER_A:
        //case TW_NPC_VERWUESTER_H:
            return TW_NPC_TYP_VERWUESTER;
        case TW_NPC_TURMKANONE_A:
        //case TW_NPC_TURMKANONE_H:
            return TW_NPC_TYP_TURMKANONE;
        case TW_NPC_FLUGMEISTER_A:
        case TW_NPC_FLUGMEISTER_H:
            return TW_NPC_TYP_FLUGMEISTER;
        case TW_NPC_WAFFENKONTROLLE_A:
        //case TW_NPC_WAFFENKONTROLLE_H:
            return TW_NPC_TYP_WAFFENKONTROLLE;
        case TW_NPC_LEBENDER_PEITSCHER:
        case TW_NPC_AUSGEWACHSENER_PEITSCHER:
        case TW_NPC_WANDERNDER_SCHATTEN:
        case TW_NPC_SCHATTENKLAGEGEIST:
        case TW_NPC_EISZEITLICHER_GEIST:
        case TW_NPC_WASSERKLAGEGEIST:
        case TW_NPC_KUEHLER_ERDELEMENTAR:
        case TW_NPC_ERDKLAGEGEIST:
        case TW_NPC_FLUESTERNDER_WIND:
        case TW_NPC_STURMKLAGEGEIST:
        case TW_NPC_TOBENDE_FLAMME:
        case TW_NPC_FEUERKLAGEGEIST:
            return TW_NPC_TYP_TRASH;
        case TW_NPC_ENTDECKUNGSEINHEIT:
            return TW_NPC_TYP_ENTDECKUNGSEINHEIT;

        default:
            return TW_NPC_TYP_DIVERS;
    }
}

void Tausendwinter::SpieleSoundFuerTeam(TeamId teamId, uint32 soundId)
{
    WorldPacket data(SMSG_PLAY_SOUND, 4);
    data << soundId;
    sWorld->SendZoneMessage(NORDEND_TAUSENDWINTER, &data, 0, teamId);
}

void Tausendwinter::SpieleSoundFuerZone(uint32 soundId)
{
    WorldPacket data(SMSG_PLAY_SOUND, 4);
    data << soundId;
    sWorld->SendZoneMessage(NORDEND_TAUSENDWINTER, &data);
}

// Aktualisiere die Werkstattanzahl
void Tausendwinter::AktualisiereWerkstattAnzahl(TeamId teamId, bool add)
{
    if (teamId == TEAM_NEUTRAL)
        return;

    if (add)
        ++m_AnzahlWerkstaetten[teamId];
    else if (m_AnzahlWerkstaetten[teamId])
        --m_AnzahlWerkstaetten[teamId];
    else
        sLog->outError("TAUSENDWINTER: Tausendwinter::AktualisiereWerkstattAnzahl: Negative Werkstattanzahl!");

    OutdoorPvP::SendUpdateWorldState(WeltStatusAnzahlFahrzeugeMax[teamId], m_AnzahlWerkstaetten[teamId] * TW_WERKSTATT_FAHRZEUGE);

    Speichern();
}

// Aktuelle Anzahl der Fahrzeuge einer Werkstatt erhöhen
void Tausendwinter::ErhoeheFahrzeuganzahlDerWerkstatt(uint32 lowguid) // GUID des Ingis der Werkstatt oder der Werkstatt selbst
{
    if (TausendwinterCapturePoint * Werkstatt = HoleWerkstatt(lowguid))
        if (Werkstatt->AnzahlFahrzeuge < TW_WERKSTATT_FAHRZEUGE)
            ++Werkstatt->AnzahlFahrzeuge;
}

// Aktuelle Anzahl der Fahrzeuge einer Werkstatt senken
void Tausendwinter::SenkeFahrzeuganzahlEinerWerkstatt()
{
    for (OutdoorPvP::OPvPCapturePointMap::const_iterator iter = OutdoorPvP::m_capturePoints.begin(); iter != OutdoorPvP::m_capturePoints.end(); ++iter)
        if (TausendwinterCapturePoint * Werkstatt = dynamic_cast<TausendwinterCapturePoint*> (iter->second))
            if (Werkstatt->AnzahlFahrzeuge)
            {
                --Werkstatt->AnzahlFahrzeuge;
                return;
            }
}

// Aktuelle Anzahl der Fahrzeuge einer Werkstatt holen
uint8 Tausendwinter::HoleAnzahlFahrzeugeDerWerkstatt(uint32 lowguid) // GUID des Ingis der Werkstatt oder der Werkstatt selbst
{
    if (TausendwinterCapturePoint * Werkstatt = HoleWerkstatt(lowguid))
        return Werkstatt->AnzahlFahrzeuge;

    return 0;
}

// Werkstatt mit Werkstatt oder Ingi GUID holen
TausendwinterCapturePoint * Tausendwinter::HoleWerkstatt(uint32 lowguid) const
{
    if (OPvPCapturePoint * cp = OutdoorPvP::GetCapturePoint(lowguid))
        return dynamic_cast<TausendwinterCapturePoint*> (cp);

    for (OutdoorPvP::OPvPCapturePointMap::const_iterator iter = OutdoorPvP::m_capturePoints.begin(); iter != OutdoorPvP::m_capturePoints.end(); ++iter)
        if (TausendwinterCapturePoint * Werkstatt = dynamic_cast<TausendwinterCapturePoint*> (iter->second))
            if (Werkstatt->m_IngiGUID == lowguid)
                return Werkstatt;

    for (OutdoorPvP::OPvPCapturePointMap::const_iterator iter = OutdoorPvP::m_capturePoints.begin(); iter != OutdoorPvP::m_capturePoints.end(); ++iter)
        if (TausendwinterCapturePoint * Werkstatt = dynamic_cast<TausendwinterCapturePoint*> (iter->second))
            if (Werkstatt->m_WerkstattGUID == lowguid)
                return Werkstatt;

    return NULL;
}

void Tausendwinter::SendAreaSpiritHealerQueryOpcode(Player * pPlr, uint64 & NPCGuid)
{
    if (!pPlr)
        return;

    if (Creature * pCr = pPlr->GetMap()->GetCreature(NPCGuid))
    {
        NPCMap::const_iterator NPCiter = m_NPCMap.find(pCr->GetDBTableGUIDLow());
        if (NPCiter != m_NPCMap.end())
        {
            WorldPacket data(SMSG_AREA_SPIRIT_HEALER_TIME, 12);
            uint32 time_ = 30000 - (*NPCiter).second->m_LetzteWiederbelebung;
            if (time_ == uint32(-1))
                time_ = 0;
            data << NPCGuid << time_;
            pPlr->GetSession()->SendPacket(&data);
        }
    }
}

void Tausendwinter::AddPlayerToResurrectQueue(uint32 NPCLowGuid, uint64 PlayerGUID)
{
    Player * pPlr = sObjectAccessor->FindPlayer(PlayerGUID);
    if (!pPlr)
        return;

    NPCMap::const_iterator NPCiter = m_NPCMap.find(NPCLowGuid);
    if (NPCiter != m_NPCMap.end())
    {
        SpielerSet::const_iterator Spieleriter = (*NPCiter).second->m_SpielerListe.find(PlayerGUID);
        if (Spieleriter == (*NPCiter).second->m_SpielerListe.end())
            (*NPCiter).second->m_SpielerListe.insert(PlayerGUID);
        else
            return;
    }
    else
        return;

    pPlr->CastSpell(pPlr, SPELL_WAITING_FOR_RESURRECT, true);
}

void Tausendwinter::RemovePlayerFromResurrectQueue(uint64 PlayerGUID)
{
    for (NPCMap::const_iterator NPCiter = m_NPCMap.begin(); NPCiter != m_NPCMap.end(); ++NPCiter)
    {
        if ((*NPCiter).second->m_Typ != TW_NPC_TYP_GEISTERFUEHRER)
            continue;

        if (!(*NPCiter).second->m_SpielerListe.empty())
        {
            SpielerSet::iterator Spieleriter = (*NPCiter).second->m_SpielerListe.find(PlayerGUID);
            if (Spieleriter != (*NPCiter).second->m_SpielerListe.end())
            {
                if (Player * pPlr = sObjectAccessor->FindPlayer(*Spieleriter))
                    pPlr->RemoveAurasDueToSpell(SPELL_WAITING_FOR_RESURRECT);

                (*NPCiter).second->m_SpielerListe.erase(Spieleriter);

                return;
            }
        }

        if (!(*NPCiter).second->m_WiederbelebungsListe.empty())
        {
            SpielerSet::iterator Spieleriter = (*NPCiter).second->m_WiederbelebungsListe.find(PlayerGUID);
            if (Spieleriter != (*NPCiter).second->m_WiederbelebungsListe.end())
            {
                if (Player * pPlr = sObjectAccessor->FindPlayer(*Spieleriter))
                    pPlr->RemoveAurasDueToSpell(SPELL_WAITING_FOR_RESURRECT);

                (*NPCiter).second->m_WiederbelebungsListe.erase(Spieleriter);

                return;
            }
        }
    }
}

void Tausendwinter::VerschiebeToteSpieler(Creature * pCr)
{
    if (!pCr || HoleNPCTyp(pCr->GetEntry()) != TW_NPC_TYP_GEISTERFUEHRER)
        return;

    NPCMap::const_iterator iter = m_NPCMap.find(pCr->GetGUIDLow());
    if (iter != m_NPCMap.end())
    {
        if (!(*iter).second->m_WiederbelebungsListe.empty())
        {
            SpielerSet WiederbelebungsListe = (*iter).second->m_WiederbelebungsListe;
            for (SpielerSet::const_iterator iter = WiederbelebungsListe.begin(); iter != WiederbelebungsListe.end(); ++iter)
            {
                Player * pPlr = sObjectAccessor->FindPlayer(*iter);
                if (!pPlr)
                    continue;

                if (WorldSafeLocsEntry const * NaechsterFriedhof = sObjectMgr->GetClosestGraveYard(pPlr->GetPositionX(), pPlr->GetPositionY(), pPlr->GetPositionZ(), pPlr->GetMapId(), pPlr->GetTeam()))
                    pPlr->TeleportTo(pPlr->GetMapId(), NaechsterFriedhof->x, NaechsterFriedhof->y, NaechsterFriedhof->z, pPlr->GetOrientation());
            }
        }
    }
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// TausendwinterCapturePoint
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

TausendwinterCapturePoint::TausendwinterCapturePoint(Tausendwinter * pvp, Tausendwinter::GOStatus * status) : OPvPCapturePoint(pvp), m_GOStatus(status), m_TW(pvp),
m_WerkstattGUID(0), m_IngiID(NULL), m_IngiGUID(0), m_Ingi(NULL), m_GeistID(NULL), m_GeistGUID(0), m_Geist(NULL), m_KontrolleID(NULL), m_KontrolleGUID(0), m_Kontrolle(NULL) {}

void TausendwinterCapturePoint::SetzeTeamIdEntsprechendDemGOStatus()
{
    if (m_GOStatus->HoleTeamId() == TEAM_ALLIANCE)
    {
        m_value = m_maxValue;
        m_State = OBJECTIVESTATE_ALLIANCE;
    }
    else if (m_GOStatus->HoleTeamId() == TEAM_HORDE)
    {
        m_value = -m_maxValue;
        m_State = OBJECTIVESTATE_HORDE;
    }
    else
    {
        m_value = 0;
        m_State = OBJECTIVESTATE_NEUTRAL;
    }

    if (m_team != m_GOStatus->HoleTeamId())
    {
        TeamId AlteTeamId = m_team;
        m_team = m_GOStatus->HoleTeamId();
        ChangeTeam(AlteTeamId);
    }
    SendChangePhase();
}

void TausendwinterCapturePoint::ChangeTeam(TeamId AlteTeamId)
{
    uint32 IngiID = 0;
    uint32 GeistID = 0;

    if (AlteTeamId != TEAM_NEUTRAL)
        m_TW->AktualisiereWerkstattAnzahl(AlteTeamId, false);

    if (m_team != TEAM_NEUTRAL)
    {
        IngiID = m_team == TEAM_ALLIANCE ? TW_NPC_VERWUESTERINGENIEUR_A : TW_NPC_VERWUESTERINGENIEUR_H;
        GeistID = m_team == TEAM_ALLIANCE ? TW_NPC_GEISTERFUEHRER_A : TW_NPC_GEISTERFUEHRER_H;
        m_TW->AktualisiereWerkstattAnzahl(m_team, true);
    }

    if (m_capturePoint)
        GameObject::SetGoArtKit(CapturePointArtKit[m_team], m_capturePoint, m_capturePointGUID);

    m_GOStatus->SetzeTeamId(m_team);
    m_TW->SendeStatusAenderung(m_GOStatus);

    if (m_GOStatus->m_GameObject)
        m_GOStatus->m_GameObject->SetUInt32Value(GAMEOBJECT_FACTION, Fraktionen[m_team]);

    if (IngiID)
    {
        if (m_IngiGUID)
        {
            *m_IngiID = IngiID;
            m_TW->ResetNPCEntry(m_Ingi, IngiID);
        }
        if (m_GeistGUID)
        {
            *m_GeistID = GeistID;
            m_TW->ResetNPCEntry(m_Geist, GeistID);
            m_TW->VerschiebeToteSpieler(m_Geist);
        }
    }
    else if (m_Ingi)
        m_Ingi->SetVisible(false);
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// TausendwinterScript
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class OutdoorPvP_Tausendwinter : public OutdoorPvPScript
{
public:
    OutdoorPvP_Tausendwinter() : OutdoorPvPScript(TausendwinterScriptName) { }

    OutdoorPvP * GetOutdoorPvP() const
    {
        return new Tausendwinter();
    }
};

void AddSC_outdoorpvp_tw()
{
    new OutdoorPvP_Tausendwinter();
}
