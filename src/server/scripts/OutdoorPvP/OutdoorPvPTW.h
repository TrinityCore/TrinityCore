// Copyright 2009-2011 by WarHead - United Worlds of MaNGOS - http://www.uwom.de

#ifndef OUTDOORPVP_TAUSENDWINTER
#define OUTDOORPVP_TAUSENDWINTER

#include "OutdoorPvP.h"
#include "MapManager.h"

class TausendwinterCapturePoint;

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Enum / Defines für Diverses
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#define TausendwinterScriptName "outdoorpvp_tw"

enum TW_ENUM_DIVERSES
{
    // Korrekte Anzahl NPCs
    TW_ANZAHL_RUESTMEISTER                      = 2,
    TW_ANZAHL_FLUGMEISTER                       = 2,
    // Korrekte Anzahl GOs
    TW_GO_ANZAHL_WERKSTAETTEN                   = 6,
    TW_GO_ANZAHL_RELIKTKAMMER                   = 3,        // Ohne Relikt
    TW_GO_ANZAHL_TUERME                         = 7,
    TW_GO_ANZAHL_FESTUNG                        = 24,       // Ohne Türme
    TW_GO_ANZAHL_TELEPORTER                     = 5,        // 2x für Fahrzeuge
    // Flugpunkte
    TW_FP_ALLIANZ                               = 303,
    TW_FP_HORDE                                 = 332,
    // Diverses
    TW_ZENTRUM_X                                = 5100,
    TW_KARTE                                    = 571,
    TW_MINIMUM_LEVEL                            = 70,
    TW_WERKSTATT_FAHRZEUGE                      = 4,
    TW_POI_FESTUNGSTUER                         = 2246,
    TW_PORTAL_NACH_TAUSENDWINTER_A_POS_Y_MIN    = 700,      // >= ist Ally - < ist Horde
    TW_PVP_CHECKZEIT                            = 10000,
    TW_MAX_RANG_STAPEL                          = 5,
    TW_WIEDERBELEBUNGSVERZOEGERUNG              = 300,
    TW_WIEDERBELEBUNGS_HP_PROZENT               = 1,
    TW_COUNTDOWN_ZEIT                           = 900000,   // 15 Min.
    TW_SIEGAURA_ZEIT                            = 5000,     // 5 Sek.
    TW_SIEGWARNUNGSZEIT                         = 300000,   // 5 Min.
    TW_FESTUNGS_GEISTERFUEHRER_MIN_X_POS        = 5500,
    TW_ALLY_GEISTERFUEHRER_MAX_Y_POS            = 2191,
    TW_HORDE_GEISTERFUEHRER_MIN_Y_POS           = 3652,
    TW_FAHRZEUG_TELEPORTERGRENZE_Y              = 2800,
    TW_FAHRZEUG_TELEPORTER_RADIUS               = 3
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Liste aller Spells
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

enum TW_SPELLS
{
    // Kampfauren
    SPELL_REKRUT                        = 37795,
    SPELL_FAEHNRICH                     = 33280,
    SPELL_OBERLEUTNANT                  = 55629,
    SPELL_HARTNAECKIGKEIT               = 58549,
    SPELL_HARTNAECKIGKEIT_FAHRZEUGE     = 59911,
    SPELL_TURMKONTROLLE                 = 62064,
    SPELL_GEISTIGE_IMMUNITAET           = 58729,
    SPELL_TURM_ZERSTOERT_EFFEKT         = 57575, // Erde bebt und Rauchwolke
    SPELL_EINSTUERZENDER_TURM           = 55065, // Wirft den Genger zurück - 5m
    SPELL_REGELN_VON_TAUSENDWINTER      = 52108, // 5% mehr Schaden
    // Belohnungen
    SPELL_SIEG_AURA                     = 60044, // Muss manuell wieder entfernt werden!
    SPELL_SIEG_SPRUNG                   = 52852, // Spieler hüpft
    SPELL_SIEG_IN_TAUSENDWINTER         = 56902, // 3 Ehrenabzeichen von Tausendwinter und 3000 Ehre
    SPELL_NIEDERLAGE_IN_TAUSENDWINTER   = 58494, // 1 Ehrenabzeichen von Tausendwinter und 1250 Ehre
    SPELL_TOWER_DAMAGED                 = 59135, // 750 Ehre
    SPELL_TURM_ZERSTOERT                = 59136, // 750 Ehre
    SPELL_DAMAGED_BUILDING_REWARD       = 59201, // 750 Ehre
    SPELL_INTAKTES_GEBAEUDE_VERTEIDIGT  = 59203, // 1500 Ehre
    // Fahrzeuge bauen
    SPELL_KATAPULT_BAUEN                = 56663,
    SPELL_VERWUESTER_BAUEN              = 56575,
    SPELL_BELAGERUNGSMASCHINE_BAUEN_A   = 56661,
    SPELL_BELAGERUNGSMASCHINE_BAUEN_H   = 61408,
    // Diverse
    SPELL_NACH_DALARAN_TELEPORTIEREN    = 53360,
    SPELL_WASSER_AUS_TAUSENDWINTER      = 36444, // Wirkung des Wassers auf Fahrzeuge
    SPELL_VERSTEINERT                   = 63080, // Archavons Kammer
    SPELL_LANGSAMER_FALL                = 50085  // Da die Abfrage für das Beitreten zur Schlacht (im Kampf) fehlt und Spieler nicht hinaus teleportiert werden,
                                                 // werden sie einfach abgemountet und bekommen diesen Spell.
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Sounds
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

enum TW_SOUNDS
{
    TW_SOUND_WARNUNG                    = 8232,
    TW_SOUND_ZURUECKERORBERT            = 8192,
    TW_SOUND_UEBERNOMMEN_WARNUNG_ALLY   = 8332,
    TW_SOUND_UEBERNOMMEN_ALLY           = 8173,
    TW_SOUND_UEBERNOMMEN_WARNUNG_HORDE  = 8333,
    TW_SOUND_UEBERNOMMEN_HORDE          = 8213,
    TW_SOUND_FESTUNGSANGRIFF_ALLY       = 8212,
    TW_SOUND_FESTUNGSANGRIFF_HORDE      = 8174,
    TW_SOUND_NAHE_SIEG_WARNUNG_ALLY     = 8456,
    TW_SOUND_NAHE_SIEG_WARNUNG_HORDE    = 8457,
    TW_SOUND_SIEG_HORDE                 = 8454,
    TW_SOUND_SIEG_ALLY                  = 8455
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Erfolge
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

enum TW_ERFOLGE
{
    TW_ERFOLG_GERAETEGEMETZEL           = 1723, // Tötet in Tausendwinter 100 Spieler mit einem Fahrzeug oder einer Kanone.
    TW_ERFOLG_MEISTER_VON_TW_H          = 1752, // Schließt die unten aufgelisteten Tausendwinter-Erfolge ab.
    TW_ERFOLG_MEISTER_VON_TW_A          = 2776, // Schließt die unten aufgelisteten Erfolge in Tausendwinter ab.
    TW_ERFOLG_SIEG_IN_TW                = 1717, // Gewinnt die Schlacht um Tausendwinter.
    TW_ERFOLG_SIEGE_UEBER_ARCHAVON_10   = 1753, // Siege über Archavon den Steinwächter (Tausendwinter, 10 Spieler)
    TW_ERFOLG_SIEGE_UEBER_ARCHAVON_25   = 1754, // Siege über Archavon den Steinwächter (Tausendwinter, 25 Spieler)
    TW_ERFOLG_SIEGE_UEBER_EMALON_10     = 2870, // Siege über Emalon den Sturmwächter (Tausendwinter, 10 Spieler)
    TW_ERFOLG_SIEGE_UEBER_EMALON_25     = 3236, // Siege über Emalon den Sturmwächter (Tausendwinter, 25 Spieler)
    TW_ERFOLG_SIEGE_UEBER_KORALON_10    = 4074, // Siege über Koralon den Flammenwächter (Tausendwinter, 10 Spieler)
    TW_ERFOLG_SIEGE_UEBER_KORALON_25    = 4075, // Siege über Koralon den Flammenwächter (Tausendwinter, 25 Spieler)
    TW_ERFOLG_SIEGE_UEBER_TORAVON_10    = 4657, // Siege über Toravon den Eiswächter (Tausendwinter, 10 Spieler)
    TW_ERFOLG_SIEGE_UEBER_TORAVON_25    = 4658, // Siege über Toravon den Eiswächter (Tausendwinter, 25 Spieler)
    TW_ERFOLG_TW_ZUM_TROTZ              = 1755, // Greift Tausendwinter an und seid in höchstens 10 Minuten erfolgreich.
    TW_ERFOLG_VETERAN_VON_TW            = 1718, // Gewinnt 100 Schlachten um Tausendwinter.
    TW_ERFOLG_WALDLAEUFER_VON_TW        = 2199, // Tötet in jedem der unten aufgelisteten Tausendwinter-Gebiete 10 Spieler.
    TW_ERFOLG_DER_SCHIEFE_TURM_VON_TW   = 1727, // Zerstört einen Turm in Tausendwinter.
    TW_ERFOLG_AUS_DEM_SATTEL_PUSTEN     = 1751, // Tötet 20 berittene Spieler mit einer Turmkanone.
    TW_ERFOLG_DESTRUCTION_DERBY_A       = 1737, // Zerstört jedes der unten aufgelisteten Fahrzeuge.
    TW_ERFOLG_DESTRUCTION_DERBY_H       = 2476  // Zerstört jedes der unten aufgelisteten Fahrzeuge.
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Quests
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

enum TW_QUESTS
{
    TW_QUEST_SIEG_IN_TAUSENDWINTER_A            = 13181,
    TW_QUEST_SIEG_IN_TAUSENDWINTER_H            = 13183,
    TW_QUEST_BELAGERUNGSMASCHINEN_VERTEIDIGEN_A = 13222,
    TW_QUEST_BELAGERUNGSMASCHINEN_VERTEIDIGEN_H = 13223,
    TW_QUEST_SABOTAGE_AUS_DEM_SUEDEN_A          = 13538,
    TW_QUEST_EINSTUERZENDE_TURMBAUTEN_H         = 13539,
    TW_QUEST_SETZT_DER_BELAGERUNG_EIN_ENDE_A    = 13186,
    TW_QUEST_SETZT_DER_BELAGERUNG_EIN_ENDE_H    = 13185
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Weltstaten
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

enum TW_STATEN
{
    TW_STATUS_FAHRZEUGE_ANZAHL_A            = 3680,
    TW_STATUS_FAHRZEUGE_MAXIMAL_A           = 3681,
    TW_STATUS_FAHRZEUGE_ANZAHL_H            = 3490,
    TW_STATUS_FAHRZEUGE_MAXIMAL_H           = 3491,
    TW_STATUS_KONTROLLIER_VON_DER_ALLIANZ   = 3803,
    TW_STATUS_KONTROLLIER_VON_DER_HORDE     = 3802,
    TW_STATUS_VERBLEIBENDE_ZEIT             = 3781,
    TW_STATUS_NAECHSTE_SCHLACHT             = 4354
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// GO und GO Display IDs sowie Events
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

enum TW_GO_IDS
{
    TW_GO_BANNER_DER_NO_FABRIK_RING     = 190475, // CapturePoint
    TW_GO_BANNER_DER_NW_FABRIK_TEMPEL   = 190487, // CapturePoint
    TW_GO_BANNER_DER_SO_FABRIK_OSTFUNK  = 194960, // CapturePoint
    TW_GO_BANNER_DER_SW_FABRIK_WESTFUNK = 194963, // CapturePoint
    TW_GO_RELIKT_DER_TITANEN            = 192829,
    TW_GO_KOLLISIONSWAND01              = 194162, // Unsichtbar!
    TW_GO_KOLLISIONSWAND                = 194323, // Unsichtbar!
    TW_GO_FESTUNGSTUER                  = 191810, // Die sichtbare Tür
    TW_GO_GOBLINWERKSTATT_FESTUNG_W     = 192028,
    TW_GO_GOBLINWERKSTATT_FESTUNG_O     = 192029,
    TW_GO_GOBLINWERKSTATT_TEMPEL        = 192030,
    TW_GO_GOBLINWERKSTATT_RING          = 192031,
    TW_GO_GOBLINWERKSTATT_WESTFUNK      = 192032,
    TW_GO_GOBLINWERKSTATT_OSTFUNK       = 192033,
    TW_GO_SCHATTENBLICKTURM             = 190356,
    TW_GO_WINTERSTURZTURM               = 190357,
    TW_GO_FLAMMENAUGENTURM              = 190358,
    TW_GO_FESTUNGSTURM_NW               = 190221,
    TW_GO_FESTUNGSTURM_SW               = 190373,
    TW_GO_FESTUNGSTURM_SO               = 190377,
    TW_GO_FESTUNGSTURM_NO               = 190378,
    TW_GO_FESTUNGSTOR                   = 190375,
    TW_GO_TAUSENDWINTERWALL_1           = 191797,
    TW_GO_TAUSENDWINTERWALL_2           = 191798,
    TW_GO_TAUSENDWINTERWALL_3           = 191805,
    TW_GO_WALL_DER_TWFESTUNG_1          = 190219,
    TW_GO_WALL_DER_TWFESTUNG_2          = 190220,
    TW_GO_WALL_DER_TWFESTUNG_3          = 190369,
    TW_GO_WALL_DER_TWFESTUNG_4          = 190370,
    TW_GO_WALL_DER_TWFESTUNG_5          = 190371,
    TW_GO_WALL_DER_TWFESTUNG_6          = 190372,
    TW_GO_WALL_DER_TWFESTUNG_7          = 190374,
    TW_GO_WALL_DER_TWFESTUNG_8          = 190376,
    TW_GO_WALL_DER_TWFESTUNG_9          = 191795,
    TW_GO_WALL_DER_TWFESTUNG_10         = 191796,
    TW_GO_WALL_DER_TWFESTUNG_11         = 191799,
    TW_GO_WALL_DER_TWFESTUNG_12         = 191800,
    TW_GO_WALL_DER_TWFESTUNG_13         = 191801,
    TW_GO_WALL_DER_TWFESTUNG_14         = 191802,
    TW_GO_WALL_DER_TWFESTUNG_15         = 191803,
    TW_GO_WALL_DER_TWFESTUNG_16         = 191804,
    TW_GO_WALL_DER_TWFESTUNG_17         = 191806,
    TW_GO_WALL_DER_TWFESTUNG_18         = 191807,
    TW_GO_WALL_DER_TWFESTUNG_19         = 191808,
    TW_GO_WALL_DER_TWFESTUNG_20         = 191809,
    TW_GO_PORTAL_DES_VERTEIDIGERS_1     = 190763,
    TW_GO_PORTAL_DES_VERTEIDIGERS_2     = 191575,
    TW_GO_PORTAL_DES_VERTEIDIGERS_3     = 192819,
    TW_GO_TELEPORTER_FUER_FAHRZEUGE     = 192951, // TODO: GAMEOBJECT_TYPE_GENERIC - braucht Skript!
    TW_GO_PORTAL_NACH_TAUSENDWINTER     = 193772  // Dalaran Portal nach Tausendwinter
};

enum TW_GO_DISPLAYIDS
{
    TW_GO_DISPLAY_RELIKT            = 7967,
    TW_GO_DISPLAY_FESTUNGSTUER      = 8165,
    TW_GO_DISPLAY_FESTUNGSTOR       = 7906,
    TW_GO_DISPLAY_KOLLISION         = 8556,
    TW_GO_DISPLAY_TELEPORTER        = 8244,
    TW_GO_DISPLAY_TUERME            = 7900,
    TW_GO_DISPLAY_FESTUNGSTUERME    = 7878,
    TW_GO_DISPLAY_WALL              = 7909,
    TW_GO_DISPLAY_FESTUNGSWALL      = 7877,
    TW_GO_DISPLAY_WERKSTATT         = 8208,
    // Banner
    TW_GO_DISPLAY_BANNER_1_A        = 5651,
    TW_GO_DISPLAY_BANNER_1_H        = 5652,
    TW_GO_DISPLAY_BANNER_2_A        = 5771,
    TW_GO_DISPLAY_BANNER_2_H        = 5773,
    TW_GO_DISPLAY_BANNER_3_A        = 6251,
    TW_GO_DISPLAY_BANNER_3_H        = 6253,
    TW_GO_DISPLAY_BANNER_4_A        = 6252,
    TW_GO_DISPLAY_BANNER_4_H        = 6254,
    TW_GO_DISPLAY_BANNER_5_A        = 8256,
    TW_GO_DISPLAY_BANNER_5_H        = 8257
};

enum TW_GO_EVENTIDS
{
    TW_EVENT_RELIKT_DER_TITANEN_KLICK           = 22097,
    TW_EVENT_FESTUNGSTOR_BESCHAEDIGT            = 19956,
    TW_EVENT_FESTUNGSTOR_ZERSTOERT              = 19957,
    TW_EVENT_FESTUNGSTUER_BESCHAEDIGT           = 19448,
    TW_EVENT_FESTUNGSTUER_ZERSTOERT             = 19607,
    TW_EVENT_FESTUNGSTURM_NW_BESCHAEDIGT        = 19657,
    TW_EVENT_FESTUNGSTURM_NW_ZERSTOERT          = 19661,
    TW_EVENT_FESTUNGSTURM_SW_BESCHAEDIGT        = 19659,
    TW_EVENT_FESTUNGSTURM_SW_ZERSTOERT          = 19662,
    TW_EVENT_FESTUNGSTURM_SO_BESCHAEDIGT        = 19660,
    TW_EVENT_FESTUNGSTURM_SO_ZERSTOERT          = 19664,
    TW_EVENT_FESTUNGSTURM_NO_BESCHAEDIGT        = 19658,
    TW_EVENT_FESTUNGSTURM_NO_ZERSTOERT          = 19663,
    TW_EVENT_WINTERSTURZTURM_BESCHAEDIGT        = 19673,
    TW_EVENT_WINTERSTURZTURM_ZERSTOERT          = 19676,
    TW_EVENT_FLAMMENAUGENTURM_BESCHAEDIGT       = 19672,
    TW_EVENT_FLAMMENAUGENTURM_ZERSTOERT         = 19675,
    TW_EVENT_SCHATTENBLICKTURM_BESCHAEDIGT      = 19674,
    TW_EVENT_SCHATTENBLICKTURM_ZERSTOERT        = 19677,
    TW_EVENT_WALL_1_BESCHAEDIGT                 = 19934,
    TW_EVENT_WALL_1_ZERSTOERT                   = 19943,
    TW_EVENT_WALL_2_BESCHAEDIGT                 = 19940,
    TW_EVENT_WALL_2_ZERSTOERT                   = 19949,
    TW_EVENT_WALL_3_BESCHAEDIGT                 = 19937,
    TW_EVENT_WALL_3_ZERSTOERT                   = 19946,
    TW_EVENT_FESTUNGSWALL_1_BESCHAEDIGT         = 19896,
    TW_EVENT_FESTUNGSWALL_1_ZERSTOERT           = 19910,
    TW_EVENT_FESTUNGSWALL_2_BESCHAEDIGT         = 19897,
    TW_EVENT_FESTUNGSWALL_2_ZERSTOERT           = 19911,
    TW_EVENT_FESTUNGSWALL_3_BESCHAEDIGT         = 19900,
    TW_EVENT_FESTUNGSWALL_3_ZERSTOERT           = 19914,
    TW_EVENT_FESTUNGSWALL_4_BESCHAEDIGT         = 19905,
    TW_EVENT_FESTUNGSWALL_4_ZERSTOERT           = 19919,
    TW_EVENT_FESTUNGSWALL_5_BESCHAEDIGT         = 19901,
    TW_EVENT_FESTUNGSWALL_5_ZERSTOERT           = 19915,
    TW_EVENT_FESTUNGSWALL_6_BESCHAEDIGT         = 19904,
    TW_EVENT_FESTUNGSWALL_6_ZERSTOERT           = 19918,
    TW_EVENT_FESTUNGSWALL_7_BESCHAEDIGT         = 19902,
    TW_EVENT_FESTUNGSWALL_7_ZERSTOERT           = 19916,
    TW_EVENT_FESTUNGSWALL_8_BESCHAEDIGT         = 19903,
    TW_EVENT_FESTUNGSWALL_8_ZERSTOERT           = 19917,
    TW_EVENT_FESTUNGSWALL_9_BESCHAEDIGT         = 19933,
    TW_EVENT_FESTUNGSWALL_9_ZERSTOERT           = 19942,
    TW_EVENT_FESTUNGSWALL_10_BESCHAEDIGT        = 19941,
    TW_EVENT_FESTUNGSWALL_10_ZERSTOERT          = 19950,
    TW_EVENT_FESTUNGSWALL_11_BESCHAEDIGT        = 19909,
    TW_EVENT_FESTUNGSWALL_11_ZERSTOERT          = 19923,
    TW_EVENT_FESTUNGSWALL_12_BESCHAEDIGT        = 19935,
    TW_EVENT_FESTUNGSWALL_12_ZERSTOERT          = 19944,
    TW_EVENT_FESTUNGSWALL_13_BESCHAEDIGT        = 19939,
    TW_EVENT_FESTUNGSWALL_13_ZERSTOERT          = 19948,
    TW_EVENT_FESTUNGSWALL_14_BESCHAEDIGT        = 19898,
    TW_EVENT_FESTUNGSWALL_14_ZERSTOERT          = 19912,
    TW_EVENT_FESTUNGSWALL_15_BESCHAEDIGT        = 19899,
    TW_EVENT_FESTUNGSWALL_15_ZERSTOERT          = 19913,
    TW_EVENT_FESTUNGSWALL_16_BESCHAEDIGT        = 19936,
    TW_EVENT_FESTUNGSWALL_16_ZERSTOERT          = 19945,
    TW_EVENT_FESTUNGSWALL_17_BESCHAEDIGT        = 19938,
    TW_EVENT_FESTUNGSWALL_17_ZERSTOERT          = 19947,
    TW_EVENT_FESTUNGSWALL_18_BESCHAEDIGT        = 19906,
    TW_EVENT_FESTUNGSWALL_18_ZERSTOERT          = 19920,
    TW_EVENT_FESTUNGSWALL_19_BESCHAEDIGT        = 19907,
    TW_EVENT_FESTUNGSWALL_19_ZERSTOERT          = 19921,
    TW_EVENT_FESTUNGSWALL_20_BESCHAEDIGT        = 19908,
    TW_EVENT_FESTUNGSWALL_20_ZERSTOERT          = 19922,
    TW_EVENT_WERKSTATT_FESTUNG_W_BESCHAEDIGT    = 19782,
    TW_EVENT_WERKSTATT_FESTUNG_W_ZERSTOERT      = 19786,
    TW_EVENT_WERKSTATT_FESTUNG_O_BESCHAEDIGT    = 19783,
    TW_EVENT_WERKSTATT_FESTUNG_O_ZERSTOERT      = 19787,
    TW_EVENT_WERKSTATT_TEMPEL_BESCHAEDIGT       = 19777,
    TW_EVENT_WERKSTATT_TEMPEL_ZERSTOERT         = 19779,
    TW_EVENT_WERKSTATT_RING_BESCHAEDIGT         = 19776,
    TW_EVENT_WERKSTATT_RING_ZERSTOERT           = 19778,
    TW_EVENT_WERKSTATT_WESTFUNK_BESCHAEDIGT     = 19784,
    TW_EVENT_WERKSTATT_WESTFUNK_ZERSTOERT       = 19788,
    TW_EVENT_WERKSTATT_OSTFUNK_BESCHAEDIGT      = 19785,
    TW_EVENT_WERKSTATT_OSTFUNK_ZERSTOERT        = 19789
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// NPC IDs und Typen, sowie Idx
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

enum TW_NPC_IDS
{
    TW_NPC_WACHE_A                  = 32308,
    TW_NPC_WACHE_H                  = 32307,
    TW_NPC_CHAMPION_A               = 30740,
    TW_NPC_CHAMPION_H               = 30739,
    TW_NPC_RUESTMEISTER_1_A         = 32294,
    TW_NPC_RUESTMEISTER_1_H         = 32296,
    TW_NPC_RUESTMEISTER_2_A         = 39172,
    TW_NPC_RUESTMEISTER_2_H         = 39173,
    TW_NPC_GEISTERFUEHRER_A         = 31842,
    TW_NPC_GEISTERFUEHRER_H         = 31841,
    TW_NPC_GEISTHEILER_A            = 6491,
    TW_NPC_GEISTHEILER_H            = 6491,
    TW_NPC_VERWUESTERINGENIEUR_A    = 30499,
    TW_NPC_VERWUESTERINGENIEUR_H    = 30400,
    TW_NPC_VERZAUBERER_A            = 31051,
    TW_NPC_VERZAUBERER_H            = 31101,
    TW_NPC_QUESTGEBER_1_A           = 31052,
    TW_NPC_QUESTGEBER_1_H           = 31102,
    TW_NPC_QUESTGEBER_2_A           = 31109,
    TW_NPC_QUESTGEBER_2_H           = 31107,
    TW_NPC_QUESTGEBER_3_A           = 31153,
    TW_NPC_QUESTGEBER_3_H           = 31151,
    TW_NPC_QUESTGEBER_4_A           = 31108,
    TW_NPC_QUESTGEBER_4_H           = 31106,
    TW_NPC_QUESTGEBER_5_A           = 31054,
    TW_NPC_QUESTGEBER_5_H           = 31053,
    TW_NPC_QUESTGEBER_6_A           = 31036,
    TW_NPC_QUESTGEBER_6_H           = 31091,
    TW_NPC_QUESTGEBER_PVP_1_A       = 15351,
    TW_NPC_QUESTGEBER_PVP_1_H       = 15350,
    TW_NPC_QUESTGEBER_PVP_2_A       = 32626,
    TW_NPC_QUESTGEBER_PVP_2_H       = 32615,
    TW_NPC_BELAGERUNGSMASCHINE_A    = 28312,
    TW_NPC_BELAGERUNGSMASCHINE_H    = 32627,
    TW_NPC_BELAGERUNGSTURM_A        = 28319,
    TW_NPC_BELAGERUNGSTURM_H        = 32629,
    TW_NPC_KATAPULT_A               = 27881,
    TW_NPC_KATAPULT_H               = 27881,
    TW_NPC_VERWUESTER_A             = 28094,
    TW_NPC_VERWUESTER_H             = 28094,
    TW_NPC_TURMKANONE_A             = 28366,
    TW_NPC_TURMKANONE_H             = 28366,
    TW_NPC_FLUGMEISTER_A            = 30869,
    TW_NPC_FLUGMEISTER_H            = 30870,
    TW_NPC_WAFFENKONTROLLE_A        = 27852,
    TW_NPC_WAFFENKONTROLLE_H        = 27852,
    TW_NPC_ENTDECKUNGSEINHEIT       = 27869,
    // Elementare
    TW_NPC_LEBENDER_PEITSCHER       = 30845,
    TW_NPC_AUSGEWACHSENER_PEITSCHER = 34300,
    TW_NPC_WANDERNDER_SCHATTEN      = 30842,
    TW_NPC_SCHATTENKLAGEGEIST       = 30872,
    TW_NPC_EISZEITLICHER_GEIST      = 30846,
    TW_NPC_WASSERKLAGEGEIST         = 30877,
    TW_NPC_KUEHLER_ERDELEMENTAR     = 30849,
    TW_NPC_ERDKLAGEGEIST            = 30876,
    TW_NPC_FLUESTERNDER_WIND        = 30848,
    TW_NPC_STURMKLAGEGEIST          = 30875,
    TW_NPC_TOBENDE_FLAMME           = 30847,
    TW_NPC_FEUERKLAGEGEIST          = 30873,
    // Quest Kill Credit NPCs
    TW_NPC_PVP_KILL_ALLIANCE        = 31086,
    TW_NPC_PVP_KILL_HORDE           = 39019,
    TW_NPC_PVP_KILL_VEHICLE         = 31093,
    TW_NPC_PVP_KILL_FIRE            = 31071,
    TW_NPC_PVP_KILL_WATER           = 31072,
    TW_NPC_PVP_KILL_SHADOW          = 31073,
    TW_NPC_PVP_KILL_LIFE            = 31074,
    TW_NPC_PVP_KILL_TOWER           = 31156,
    TW_NPC_PVP_KILL_STRUCTURE       = 31244,
    TW_NPC_PVP_KILL_BRIDGE          = 31286,
    TW_NPC_PVP_KILL_WALL            = 31287,
    TW_NPC_PVP_KILL_WORKSHOP        = 31288,
    TW_NPC_PVP_KILL_GATE            = 31289,
    TW_NPC_PVP_KILL_SOUTHERN_TOWER  = 35074,
    TW_NPC_VEHICLE_PROTECTED        = 31284
};

enum TW_NPC_TYP // Ist auch gleichzeitig der Idx für NPCPaare!
{
    TW_NPC_TYP_WACHE,
    TW_NPC_TYP_CHAMPION,
    TW_NPC_TYP_RUESTMEISTER_1,
    TW_NPC_TYP_RUESTMEISTER_2,
    TW_NPC_TYP_GEISTERFUEHRER,
    TW_NPC_TYP_GEISTHEILER,
    TW_NPC_TYP_VERWUESTERINGENIEUR,
    TW_NPC_TYP_VERZAUBERER,
    TW_NPC_TYP_QUESTGEBER_1,
    TW_NPC_TYP_QUESTGEBER_2,
    TW_NPC_TYP_QUESTGEBER_3,
    TW_NPC_TYP_QUESTGEBER_4,
    TW_NPC_TYP_QUESTGEBER_5,
    TW_NPC_TYP_QUESTGEBER_6,
    TW_NPC_TYP_QUESTGEBER_PVP_1,
    TW_NPC_TYP_QUESTGEBER_PVP_2,
    TW_NPC_TYP_BELAGERUNGSMASCHINE,
    TW_NPC_TYP_KATAPULT,
    TW_NPC_TYP_VERWUESTER,
    TW_NPC_TYP_TURMKANONE,
    TW_NPC_TYP_BELAGERUNGSTURM,
    TW_NPC_TYP_FLUGMEISTER,
    TW_NPC_TYP_WAFFENKONTROLLE,
    TW_NPC_TYP_TRASH,
    TW_NPC_TYP_ENTDECKUNGSEINHEIT,
    TW_NPC_TYP_DIVERS
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Tausendwinter Zonen Abmessungen / Reliktkoordinaten / Tele etc. Indizes
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

enum TWKoordsIdx
{
    MinX,
    MinY,
    MaxX,
    MaxY
};

enum TWFestungsKoordsIdx
{
    TW_FESTUNGS_MIN_X,
    TW_FESTUNGS_MAX_X,
    TW_FESTUNGS_MIN_Y,
    TW_FESTUNGS_MAX_Y
};

enum TWReliktKoordsIdx
{
    RELIKT_X,
    RELIKT_Y,
    RELIKT_Z
};

enum TWFahrzeugTeleIdx
{
    FTeleOst,
    FTeleWest
};

enum TWFahrzeugTeleKoordsIdx
{
    FTeleX,
    FTeleY,
    FTeleZ
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// GO Typen und Zustand
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

enum TWGOTyp
{
    WALL,
    WERKSTATT,
    TURM,
    TOR,
    TUER
};

enum GOSchadensStatus
{
    INTAKT,
    BESCHAEDIGT,
    ZERSTOERT
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// GO und NPC Teampaare
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

const typedef uint32 TeamPaar[2];

static const TeamPaar GODisplayPaare[] =
{//  Ally, Horde
    {TW_GO_DISPLAY_BANNER_1_A, TW_GO_DISPLAY_BANNER_1_H},
    {TW_GO_DISPLAY_BANNER_2_A, TW_GO_DISPLAY_BANNER_2_H},
    {TW_GO_DISPLAY_BANNER_3_A, TW_GO_DISPLAY_BANNER_3_H},
    {TW_GO_DISPLAY_BANNER_4_A, TW_GO_DISPLAY_BANNER_4_H},
    {TW_GO_DISPLAY_BANNER_5_A, TW_GO_DISPLAY_BANNER_5_H},
    {                       0,                        0}  // ENDE
};

static const TeamPaar NPCPaare[] =
{
    {TW_NPC_WACHE_A,                TW_NPC_WACHE_H},
    {TW_NPC_CHAMPION_A,             TW_NPC_CHAMPION_H},
    {TW_NPC_RUESTMEISTER_1_A,       TW_NPC_RUESTMEISTER_1_H},
    {TW_NPC_RUESTMEISTER_2_A,       TW_NPC_RUESTMEISTER_2_H},
    {TW_NPC_GEISTERFUEHRER_A,       TW_NPC_GEISTERFUEHRER_H},
    {TW_NPC_GEISTHEILER_A,          TW_NPC_GEISTHEILER_H},
    {TW_NPC_VERWUESTERINGENIEUR_A,  TW_NPC_VERWUESTERINGENIEUR_H},
    {TW_NPC_VERZAUBERER_A,          TW_NPC_VERZAUBERER_H},
    {TW_NPC_QUESTGEBER_1_A,         TW_NPC_QUESTGEBER_1_H},
    {TW_NPC_QUESTGEBER_2_A,         TW_NPC_QUESTGEBER_2_H},
    {TW_NPC_QUESTGEBER_3_A,         TW_NPC_QUESTGEBER_3_H},
    {TW_NPC_QUESTGEBER_4_A,         TW_NPC_QUESTGEBER_4_H},
    {TW_NPC_QUESTGEBER_5_A,         TW_NPC_QUESTGEBER_5_H},
    {TW_NPC_QUESTGEBER_6_A,         TW_NPC_QUESTGEBER_6_H},
    {TW_NPC_QUESTGEBER_PVP_1_A,     TW_NPC_QUESTGEBER_PVP_1_H},
    {TW_NPC_QUESTGEBER_PVP_2_A,     TW_NPC_QUESTGEBER_PVP_2_H},
    {TW_NPC_BELAGERUNGSMASCHINE_A,  TW_NPC_BELAGERUNGSMASCHINE_H},
    {TW_NPC_KATAPULT_A,             TW_NPC_KATAPULT_H},
    {TW_NPC_VERWUESTER_A,           TW_NPC_VERWUESTER_H},
    {TW_NPC_TURMKANONE_A,           TW_NPC_TURMKANONE_H},
    {0,                             0}  // ENDE
};

enum TW_NPC_POS_IDX
{
    TW_QUESTGEBER_1_POS,
    TW_QUESTGEBER_2_POS,
    TW_QUESTGEBER_3_POS,
    TW_QUESTGEBER_4_POS,
    TW_QUESTGEBER_5_POS,
    TW_QUESTGEBER_6_POS,

    TW_VERZAUBERER_POS,

    TW_RUESTMEISTER_1_POS,
    TW_RUESTMEISTER_2_POS,

    TW_QUESTGEBER_PVP_1_POS,
    TW_QUESTGEBER_PVP_2_POS,

    TW_MAX_NPC_POS_IDX
 };

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// GO und NPC Teampaare
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

const typedef float TW_NPC_PositionsPaare[TW_MAX_NPC_POS_IDX][2][4];

static const TW_NPC_PositionsPaare AngreiferPos =
{   //  Ally,                                         Horde
    { { 5100.07f, 2168.89f, 365.779f, 1.97222f  },  { 5030.44f, 3659.82f, 363.194f, 1.83336f             } },
    { { 5080.4f,  2199.0f,  359.489f, 2.96706f  },  { 5008.64f, 3659.91f, 361.07f,  4.0796f              } },
    { { 5088.49f, 2188.18f, 365.647f, 5.25344f  },  { 5032.33f, 3680.7f,  363.018f, 3.43167f             } },
    { { 5095.67f, 2193.28f, 365.924f, 4.93928f  },  { 5032.66f, 3674.28f, 363.053f, 2.9447f              } },
    { { 5088.61f, 2167.66f, 365.689f, 0.680678f },  { 5032.44f, 3668.66f, 363.11f,  2.87402f             } },
    { { 5078.28f, 2183.7f,  365.029f, 1.46608f  },  { 5022.43f, 3659.91f, 361.61f,  1.35426f             } },
    { { 5081.7f,  2173.73f, 365.878f, 0.855211f },  { 5043.480469f, 3675.430908f, 363.063293f, 3.014616f } },
    { { 0.0f,     0.0f,     0.0f,     0.0f      },  { 0.0f,     0.0f,     0.0f,     0.0f                 } }, // Rüstmeister stehen nur für die Verteidiger in TW!
    { { 0.0f,     0.0f,     0.0f,     0.0f      },  { 0.0f,     0.0f,     0.0f,     0.0f                 } }, // Rüstmeister stehen nur für die Verteidiger in TW!
    { { 0.0f,     0.0f,     0.0f,     0.0f      },  { 0.0f,     0.0f,     0.0f,     0.0f                 } }, // Dieser Händler/Questgeber steht nur für die Verteidiger in TW!
    { { 0.0f,     0.0f,     0.0f,     0.0f      },  { 0.0f,     0.0f,     0.0f,     0.0f                 } }  // Dieser Händler/Questgeber steht nur für die Verteidiger in TW!
};

static const TW_NPC_PositionsPaare VerteigerPos =
{   //  Ally,                                                     Horde
    { { 5298.43f,     2738.76f,     409.316f,    3.97174f  },   { 5298.43f, 2738.76f, 409.316f, 3.97174f             } },
    { { 5234.97f,     2883.4f,      409.275f,    4.29351f  },   { 5234.97f, 2883.4f,  409.275f, 4.29351f             } },
    { { 5366.13f,     2833.4f,      409.323f,    3.14159f  },   { 5366.13f, 2833.4f,  409.323f, 3.14159f             } },
    { { 5295.56f,     2926.67f,     409.275f,    0.872665f },   { 5295.56f, 2926.67f, 409.275f, 0.872665f            } },
    { { 5371.4f,      3026.51f,     409.206f,    3.25003f  },   { 5371.4f,  3026.51f, 409.206f, 3.25003f             } },
    { { 5359.13f,     2837.99f,     409.364f,    4.69893f  },   { 5359.13f, 2837.99f, 409.364f, 4.69893f             } },
    { { 5370.662109f, 2874.185059f, 409.239258f, 3.105465f },   { 5296.56f, 2789.87f, 409.275f, 0.733038f            } },
    { { 5374.631348f, 2790.541748f, 409.238007f, 2.691720f },   { 5374.631348f, 2790.541748f, 409.238007f, 2.691720f } },
    { { 5373.229980f, 2786.881104f, 409.332733f, 2.775757f },   { 5373.229980f, 2786.881104f, 409.332733f, 2.775757f } },
    { { 5020.66f,     3647.64f,     360.786f,    1.83871f  },   { 5020.66f,     3647.64f,     360.786f,    1.83871f  } },
    { { 5419.254395f, 2862.260010f, 418.675293f, 4.207110f },   { 5419.254395f, 2862.260010f, 418.675293f, 4.207110f } }
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Definitionen diverser Konstanter
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

static const uint8 GameEventTausendwinterVerteidiger[2] = { 48, 49 };

static const float TWKoords[4] = { 3995.559570f, 1659.029175f, 5540.0f, 4270.252930f };
static const float TWFestungsKoords[4] = { 5278.0f, 5482.0f, 2640.0f, 3047.0f };

static const float ReliktKoords[3] = { 5440.0f, 2840.8f, 430.43f };
static const float FahrzeugTeleportKoords[2][3] = { { 5249.890137f, 2703.110107f, 409.274994f }, { 5247.028809f, 2978.265381f, 409.190247f } };

static const uint32 AreaPOIIconId[3][3] = { {7,8,9},{4,5,6},{1,2,3} };
static const uint32 Fraktionen[3] = { 1732, 1735, 35 };

static const uint32 WeltStatusZeit[2] = { TW_STATUS_VERBLEIBENDE_ZEIT, TW_STATUS_NAECHSTE_SCHLACHT };
static const uint32 WeltStatusAnzahlFahrzeuge[2] = { TW_STATUS_FAHRZEUGE_ANZAHL_A, TW_STATUS_FAHRZEUGE_ANZAHL_H };
static const uint32 WeltStatusAnzahlFahrzeugeMax[2] = { TW_STATUS_FAHRZEUGE_MAXIMAL_A, TW_STATUS_FAHRZEUGE_MAXIMAL_H };

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Tausendwinter Klasse
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Tausendwinter : public OutdoorPvP
{
    friend class TausendwinterCapturePoint;

public:
    Tausendwinter();
    ~Tausendwinter();

    // Alle Daten sammeln / vorbereiten und übergeben, am Schluss Zone registrieren
    bool SetupOutdoorPvP();

    // Team Stuff
    TeamId HoleVerteidigerTeamId() const { return m_VerteidigerTeamId; };
    TeamId HoleAngreiferTeamId() const { return OTHER_TEAM(m_VerteidigerTeamId); };

    // Zeit Stuff
    void SetzeZeit(uint32 Zeit) { if (Zeit >= 0) m_Zeit = Zeit; };
    uint32 HoleZeitInMinuten() const { return uint32(m_Zeit/IN_MILLISECONDS/MINUTE); };
    uint32 HoleZeitInSekunden() const { return uint32(m_Zeit/IN_MILLISECONDS); };

    // Spielerzahlen
    uint8 HoleSpieleranzahl(TeamId teamId) const;

    // Ist gerade Kampf?
    bool IstKampf() const { return m_Kampf; };

    // Essenz von Tausendwinter Spells aktualisieren
    void AktualisiereEssenzVonTausendwinter(Player * pPl, uint32 ZoneId);

    // Archavons Kammer - Zugang zur Instanz prüfen und NPCs versteinern
    bool DarfArchavonsKammerBetreten(Player * pPl);
    void DarfAngegriffenWerden(Creature * pCr);

    // Für die Konsolen / InGame Kommandos
    void ErzwingeTeamwechsel()  { m_CmdWechsel  = true; };
    void ErzwingeKampfBeenden() { m_CmdStop     = true; };
    void ErzwingeKampfStarten() { m_CmdStart    = true; };

    // Aktuelle Anzahl der Fahrzeuge einer Werkstatt erhöhen / senken / holen
    void ErhoeheFahrzeuganzahlDerWerkstatt(uint32 lowguid); // GUID des Ingis der Werkstatt oder der Werkstatt selbst
    void SenkeFahrzeuganzahlEinerWerkstatt();
    uint8 HoleAnzahlFahrzeugeDerWerkstatt(uint32 lowguid); // GUID des Ingis der Werkstatt oder der Werkstatt selbst

    void SendAreaSpiritHealerQueryOpcode(Player * pPlr, uint64 & NPCGuid);
    void AddPlayerToResurrectQueue(uint32 NPCLowGuid, uint64 PlayerGUID);
    void RemovePlayerFromResurrectQueue(uint64 PlayerGUID);

protected:
    // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Struktur wo alle NPCs gespeichert werden
    // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    typedef std::set<uint64> SpielerSet;

    struct NPCStruktur
    {
        NPCStruktur(uint32 lowguid, uint32 entry, uint32 fraktion, TeamId verteidiger) : m_Creature(NULL), m_GUID(lowguid), m_ID(entry), m_Typ(Tausendwinter::HoleNPCTyp(entry)),
            m_TeamId(Tausendwinter::HoleNPCTeamId(fraktion)), m_Verteidiger(verteidiger), m_Idx(TW_MAX_NPC_POS_IDX), m_LetzteWiederbelebung(RESURRECTION_INTERVAL) {}

    public:
        Creature * m_Creature;              // Zeiger auf den NPC
        uint32 m_GUID;                      // Datenbank GUID

        TW_NPC_TYP m_Typ;                   // Typ des NPCs (Questgeber / Geisterführer etc.)
        TeamId m_TeamId;                    // Die TeamId, zu dem dieser NPC gehört

        SpielerSet m_SpielerListe;          // Bei einem Geisterfhrer sind hier die Spieler gespeichert, die später in die m_Wiederbelebungsliste kommen
        SpielerSet m_WiederbelebungsListe;  // Bei einem Geisterführer sind hier die Spieler gespeichert, die wiederbelebt werden müssen
        uint32 m_LetzteWiederbelebung;      // Bei einem Geisterführer ist hier die Zeit der letzten Wiederbelebung gespeichert

        void InitialisiereNPC()
        {
            switch(m_Typ)
            {
                case TW_NPC_TYP_RUESTMEISTER_1:     m_Idx = TW_RUESTMEISTER_1_POS;      break;
                case TW_NPC_TYP_RUESTMEISTER_2:     m_Idx = TW_RUESTMEISTER_2_POS;      break;
                case TW_NPC_TYP_VERZAUBERER:        m_Idx = TW_VERZAUBERER_POS;         break;
                case TW_NPC_TYP_QUESTGEBER_1:       m_Idx = TW_QUESTGEBER_1_POS;        break;
                case TW_NPC_TYP_QUESTGEBER_2:       m_Idx = TW_QUESTGEBER_2_POS;        break;
                case TW_NPC_TYP_QUESTGEBER_3:       m_Idx = TW_QUESTGEBER_3_POS;        break;
                case TW_NPC_TYP_QUESTGEBER_4:       m_Idx = TW_QUESTGEBER_4_POS;        break;
                case TW_NPC_TYP_QUESTGEBER_5:       m_Idx = TW_QUESTGEBER_5_POS;        break;
                case TW_NPC_TYP_QUESTGEBER_6:       m_Idx = TW_QUESTGEBER_6_POS;        break;
                case TW_NPC_TYP_QUESTGEBER_PVP_1:   m_Idx = TW_QUESTGEBER_PVP_1_POS;    break;
                case TW_NPC_TYP_QUESTGEBER_PVP_2:   m_Idx = TW_QUESTGEBER_PVP_2_POS;    break;
                default:                            m_Idx = TW_MAX_NPC_POS_IDX;         break;
            }
            AktualisierePosition(m_Verteidiger);
        }

        void AktualisierePosition(TeamId verteidiger)
        {
            m_Verteidiger = verteidiger;

            CreatureData const * NPCData = sObjectMgr->GetCreatureData(m_GUID);

            if (NPCData)
            {
                switch(m_Typ)
                {
                    case TW_NPC_TYP_RUESTMEISTER_1:
                    case TW_NPC_TYP_RUESTMEISTER_2:
                    case TW_NPC_TYP_QUESTGEBER_PVP_1:
                    case TW_NPC_TYP_QUESTGEBER_PVP_2:
                        m_Pos.Relocate(VerteigerPos[m_Idx][m_TeamId][0], VerteigerPos[m_Idx][m_TeamId][1], VerteigerPos[m_Idx][m_TeamId][2], VerteigerPos[m_Idx][m_TeamId][3]);

                        if (m_Creature)
                            Tausendwinter::EntferneNPC(m_GUID, NPCData);

                        if (m_TeamId == m_Verteidiger)
                        {
                            Tausendwinter::SpawnNPC(m_GUID, NPCData);
                            sObjectMgr->MoveCreData(m_GUID, TW_KARTE, m_Pos);
                        }
                        break;

                    default:
                        // TODO: AB HIER IST BAUSTELLE HOCH DREI!!! Das ganze Verschieben funzt noch nicht wirklich!!!
                        if (!sWorld->getBoolConfig(CONFIG_TW_VERSCHIEBE_NPCS))
                            break;

                        // Nur NPCs mit Positionsangaben bearbeiten
                        if (m_Idx == TW_MAX_NPC_POS_IDX)
                            break;

                        if (!m_Creature)
                            Tausendwinter::SpawnNPC(m_GUID, NPCData);

                        if (m_TeamId == m_Verteidiger)
                            m_Pos.Relocate(VerteigerPos[m_Idx][m_TeamId][0], VerteigerPos[m_Idx][m_TeamId][1], VerteigerPos[m_Idx][m_TeamId][2], VerteigerPos[m_Idx][m_TeamId][3]);
                        else
                            m_Pos.Relocate(AngreiferPos[m_Idx][m_TeamId][0], AngreiferPos[m_Idx][m_TeamId][1], AngreiferPos[m_Idx][m_TeamId][2], AngreiferPos[m_Idx][m_TeamId][3]);

                        sObjectMgr->MoveCreData(m_GUID, TW_KARTE, m_Pos);

                        break;
                }
            }
        }

    private:
        uint32 m_ID;                    // NPC ID

        Position m_Pos;                 // Aktuelle Position
        TeamId m_Verteidiger;           // Aktuelles Verteidigerteam

        TW_NPC_POS_IDX m_Idx;           // Index zu seinen Positionen
    };

    // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // GOStatus Struktur
    // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    struct GOStatus
    {
        explicit GOStatus(uint32 _WeltSatus, TeamId _TeamId, bool DefaultTeamId) : m_GameObject(NULL), m_Typ(WALL), m_WeltStatus(_WeltSatus), m_Health(0),
            m_DefaultTeamId(DefaultTeamId ? _TeamId : OTHER_TEAM(_TeamId)), m_FriedhofsTeam(NULL), m_TeamId(_TeamId), m_SchadensStatus(INTAKT) {}

        GameObject * m_GameObject;
        TWGOTyp m_Typ;
        uint32 m_WeltStatus;
        uint32 m_Health;
        uint32 * m_FriedhofsTeam;
        TeamId m_DefaultTeamId;
        GOSchadensStatus m_SchadensStatus;

        void SendUpdate(Player * pPl) const
        {
            if (pPl)
                pPl->SendUpdateWorldState(m_WeltStatus, AreaPOIIconId[m_TeamId][m_SchadensStatus]);
        }

        void FillData(WorldPacket & data)
        {
            data << m_WeltStatus << AreaPOIIconId[m_TeamId][m_SchadensStatus];
        }

        TeamId HoleTeamId() const { return m_TeamId; }

        void SetzeTeamId(TeamId teamId)
        {
            m_TeamId = teamId;
            if (m_FriedhofsTeam)
                if (uint32 newTeam = TeamId2Team[teamId])
                    *m_FriedhofsTeam = newTeam;
        }
    private:
        TeamId m_TeamId;
    };

    // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // Struktur wo alle GOs gespeichert werden
    // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    struct GOStruktur
    {
        GOStruktur(uint32 lowguid, uint32 entry) : m_GameObject(NULL), m_GUID(lowguid), m_ID(entry) {}

        GameObject * m_GameObject;  // Zeiger auf das GO
        uint32 m_GUID;              // Datenbank GUID
        uint32 m_ID;                // GO ID
    };

private:
    typedef std::list<const AreaPOIEntry*> POIListe;

    typedef std::map<uint32, GOStatus*> GOStatusMap;
    typedef std::map<uint32, NPCStruktur*> NPCMap;
    typedef std::map<uint32, GOStruktur*> GOMap;

    typedef std::map<uint32, uint32> TeamPaarMap;
    typedef std::set<Creature*> FahrzeugSet;
    typedef std::set<uint32> GOGUIDSet;

    // Überschreibungen von (virtuellen) OutdoorPvP Funktionen
    void HandlePlayerResurrects(Player * pPl, uint32 zone);
    void FillInitialWorldStates(WorldPacket & data);

    void ProcessEvent(WorldObject * obj, uint32 eventId);
    void HandleKill(Player * killer, Unit * killed);

    void HandlePlayerEnterZone(Player * pPl, uint32 zone);
    void HandlePlayerLeaveZone(Player * pPl, uint32 zone);

    void OnGameObjectCreate(GameObject * go);
    void OnGameObjectRemove(GameObject * go);

    void OnCreatureCreate(Creature * pCr);
    void OnCreatureRemove(Creature * pCr);

    // Weltstatusdaten senden
    void SendeWeltstatus(Player * pPl = NULL) const;
    // Änderungen bei einem GO senden
    void SendeStatusAenderung(GOStatus * status) const;

    // Alle relevanten Daten speichern
    void Speichern();

    // NotfallAbschaltung
    void NotfallAbschaltung();

    // Alles entsprechend der TeamId spawnen / verschieben / wiederherstellen
    void Reset(bool NurWechsel = false);
    // NPC ID Reset
    void ResetNPCEntry(Creature * pCr, uint32 entry);
    // Alle zerstörbaren Gebäude wiederherstellen
    void ResetZerstoerbareGOs();

    // Friedhöfe zuordnen / erstellen
    void OrdneFriedhoefeZu();

    // Listen erstellen
    bool ErstelleNPCMap(QueryResult result);
    bool ErstelleGOMap(QueryResult result);
    void ErstelleDalaranPortalSet(QueryResult result);
    void ErstellePOIListe();
    bool ErstelleGOStatusMap();

    // Fehlende Spawns melden
    void MeldeFehlendeNPCs();
    void MeldeFehlendeGOs();

    // NPC / GO Display Paare laden
    void LadeTeamPaare(TeamPaarMap & PaarMap, TeamPaar const * Paar);

    // Immer nur das Portal spawnen, welches auf der Seite des Verteidigerteams steht
    void UeberpruefeDalaranPortal();
    // Überprüfen, ob der NPC innheralb der Festung ist
    bool IstInDerFestung(Creature * pCr) const;
    // Überprüfen, ob das GO innerhalb der Festung ist
    bool IstInDerFestung(GameObject * pGO) const;

    // GOs spawnen
    void SpawnGO(uint32 GUID, GameObjectData const * GOData);
    // GOs entfernen
    void EntferneGO(uint32 GUID, GameObjectData const * GOData);

    // NPC spawnen
    static void SpawnNPC(uint32 GUID, CreatureData const * NPCData);
    // NPC entfernen
    static void EntferneNPC(uint32 GUID, CreatureData const * NPCData);

    // Das Herzstück :-)
    bool Update(uint32 diff);

    // Wiederbelebungsliste der Geisterführer abarbeiten
    void BearbeiteWiederbelebungen(const uint32 diff);

    // Start und Ende des Kampfes
    void StarteKampf();
    void BeendeKampf();

    // Stapel von Hartnaeckigkeit aktualisieren
    void AktualisiereHartnaeckigkeitsStapel();
    // GO Daten aktualisieren
    void AktualisiereGO(GameObject * pGO);
    // Alle zerstörbaren Gebäude bei Übernahme der Festung aktualisieren
    void AktualisiereZerstoerbareGOs();
    // NPC Daten aktualisieren
    void AktualisiereNPC(Creature * pCr);
    // Uhr aktualisieren
    void AktualisiereZeit();
    void AktualisiereZeitanzeige(uint32 & Zeit, uint32 digit, uint32 mod);
    // Aktualisiere die Werkstattanzahl
    void AktualisiereWerkstattAnzahl(TeamId teamId, bool add);

    // Werkstatt mit Werkstatt oder Ingi GUID holen
    TausendwinterCapturePoint * HoleWerkstatt(uint32 lowguid) const;

    // NPC Typen holen
    static TW_NPC_TYP HoleNPCTyp(const uint32 entry);
    // TeamId für Fraktion ermitteln
    static TeamId HoleNPCTeamId(const uint32 fraktion);

    // Da es aus irgendwelchen Gründen (irgendwie) möglich ist, dass Spieler PvP ausschalten können, müssen wir dies überprüfen!
    // TODO: In den Katakomben des Core nach dem Grund für diese PvPFlag Fehler suchen!
    void PvPCheck();

    void VerschiebeToteSpieler(Creature * pCr);

    void BefoerderSpieler(Player * killer) const;

    void SpieleSoundFuerTeam(TeamId teamId, uint32 soundId);
    void SpieleSoundFuerZone(uint32 soundId);

    // Spieler die in TW sind (während der Kampf startet) automatisch zu einem Raid hinzufügen
    void FuegeSpielerZumRaidHinzu(Player * pPlr, TeamId teamId);

    // Listen
    POIListe m_PoIListe;

    NPCMap m_NPCMap;
    GOMap m_GOMap;
    GOStatusMap m_GOStatus;

    TeamPaarMap m_CrTeamPaarMap;
    TeamPaarMap m_GOTeamPaarMap;

    FahrzeugSet m_FahrzeugSet[TEAM_NEUTRAL];

    GOGUIDSet m_DalaranPortaleSet;

    // Vars
    GOStruktur * m_Relikt;
    GOStatus * m_Festungstuer;

    Group * m_Raid[TEAM_NEUTRAL];

    uint32 m_Zeit;
    uint32 m_TeamZeit[TEAM_NEUTRAL];
    uint32 m_ErfolgsZeit; // TW_ERFOLG_TW_ZUM_TROTZ
    uint32 m_SpeicherIntervall;
    uint32 m_PvPCheckZeit;
    uint32 m_Countdown; // Kampfbegin Weltcountdown
    uint32 m_SiegAuraZeit; // Entfernen der Siegaura

    uint8 m_HartnaeckigkeitsStapel;
    uint8 m_BeschaedigteTuerme[TEAM_NEUTRAL];
    uint8 m_ZerstoerteTuerme[TEAM_NEUTRAL];
    uint8 m_AnzahlWerkstaetten[TEAM_NEUTRAL];

    bool m_Kampf;
    bool m_VerteidigerWechsel;
    bool m_CmdStart;
    bool m_CmdStop;
    bool m_CmdWechsel;
    bool m_WarnungDone;
    bool m_Fortsetzung;

    TeamId m_VerteidigerTeamId;
};

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// TausendwinterCapturePoint Klasse
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class TausendwinterCapturePoint : public OPvPCapturePoint
{
    friend class Tausendwinter;

public:
    explicit TausendwinterCapturePoint(Tausendwinter * pvp, Tausendwinter::GOStatus * status);

protected:
    void SetzeTeamIdEntsprechendDemGOStatus();

private:
    void ChangeState() {}
    void SendChangePhase() {}
    void ChangeTeam(TeamId AlteTeamId);

    Tausendwinter * m_TW;

    Tausendwinter::GOStatus * m_GOStatus;

    Creature * m_Ingi;
    Creature * m_Geist;
    Creature * m_Kontrolle;

    uint32 * m_IngiID;
    uint32 * m_GeistID;
    uint32 * m_KontrolleID;

    uint32 m_IngiGUID;
    uint32 m_GeistGUID;
    uint32 m_KontrolleGUID;

    uint32 m_WerkstattGUID;

    uint8 AnzahlFahrzeuge;
};

#endif
