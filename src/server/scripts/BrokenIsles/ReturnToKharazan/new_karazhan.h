#ifndef RETURN_TO_KARAZHAN_H_
#define RETURN_TO_KARAZHAN_H_

enum eData
{
    DATA_OPERA_HALL = 0,
    DATA_MAIDEN_VIRTUE = 1,
    DATA_MIDNIGHT = 2,
    DATA_MOROES = 3,

    DATA_CURATOR = 4,
    DATA_MANA_DEVOURER = 5,
    DATA_SHADE_OF_MEDIVH = 6,
    DATA_VIZADUUM = 7,

    DATA_NIGHTBANE = 8,

    MAX_ENCOUNTER,

    DATA_OPERA_HALL_INTRO,
    DATA_OPERA_HALL_SCENE,

    DATA_OPERA_HALL_WIKKET = 1,
    DATA_OPERA_HALL_WESTFALL = 2,
    DATA_OPERA_HALL_BEAUTIFUL_BEAST = 3,

    DATA_CANNON_TARGET_GUID,
    DATA_VIZADUUM_HP_PHASE,
    DATA_VIZADUUM_PHASE,
    DATA_PHASE2_DOOR,                    //After kill Moroes
    DATA_TIMER_BONUS_BOSS,

    DATA_NIGHTBANE_TIMER,
    DATA_NIGHTBANE_EVENT,
};

enum eCreatures
{
    ///Opera Hall:
        // Other
    NPC_THEATRE_SPOTLIGHT = 18342,

    NPC_SKELETAL_USHER = 114544,
    NPC_GHOSTLY_UNDERSTUDY = 114526,
    NPC_SPECTRAL_PATRON = 114541,
    NPC_SPECTRAL_PATRON_2 = 116550,
    NPC_PHANTOM_CREW = 114584,
    NPC_BACKUP_SINGER = 116549,

    // Wikket
    NPC_THE_MONKEY_KING = 115022,
    NPC_CAGED_ASSISTANT = 115005,
    NPC_HOZEN_CAGE = 115007,
    NPC_WINGED_ASSISTANT = 114324,
    NPC_GALINDRE = 114251, // Boss
    NPC_ELFYRA = 114284, // Boss
    NPC_CRONE_BROOM = 114486,

    // Westfall
    NPC_MRRGRIA = 114260, // Boss
    NPC_TOE_KNEE = 114261, // Boss
    NPC_GANG_RUFFIAN = 114265,
    NPC_SHORELINE_TIDESPEAKER = 114266,
    NPC_WASH_AWAY = 114471,

    // Beautiful Beast
    NPC_COGGLESTON = 114328,
    NPC_LUMINORE = 114329,
    NPC_BABBLET = 114330,
    NPC_CAULDRONS = 114522,
    NPC_BELLA = 114545,
    NPC_ADEM = 114583,
    NPC_BRUTE = 114551,

    ///Attumen the Huntsman
    NPC_ATTUMEN_THE_HUNTSMAN = 114262,
    NPC_MIDNIGHT = 114264,
    NPC_INTANGIBLE_PRESSENCE = 114315,

    ///Moroes
    NPC_MOROES = 114312, // Boss
    NPC_BARONESS_DOROTHEA = 114316, // Baroness Dorothea Millstipe
    NPC_LADY_CATRIONA = 114317, // Lady Catriona Von'Indi
    NPC_BARON_RAFE = 114318, // Baron Rafe Dreuger
    NPC_LADY_KEIRA = 114319, // Lady Keira Berrybuck
    NPC_LORD_ROBIN = 114320, // Lord Robin Daris
    NPC_LORD_CRISPIN = 114321, // Lord Crispin Ference

    NPC_WHIRLING_EDGE = 114327, // Lord Robin Daris - Summons

    //After death Moroes
    NPC_SCENE_ACTOR = 116804,
    NPC_MEDIVH = 115426,
    NPC_NIELAS_ARAN = 115427,

    ///The Curator
    NPC_CURATOR = 114247,
    NPC_VOLATILE_ENERGY = 114249,

    ///Shade of Medivh
    NPC_SHADE_OF_MEDIVH = 114350,
    NPC_GUARDIAN_IMAGE = 114675,

    ///Vizaduum the Watcher
    NPC_VIZADUUM_THE_WATCHER = 114790,
    NPC_FEL_CANNON = 115274,
    NPC_COMMAND_SHIP = 114913,
    NPC_SOUL_HARVESTER = 115694,
    NPC_LEGION_CONSOLE = 115743,
    NPC_FELGUARD_SENTRY = 115730,
    NPC_SHADOW_SPITTER = 115734,
    NPC_DEMONIC_PORTAL = 115493,

    //After death scene
    NPC_ARCHMAGE_KHADGAR_VIZADUUM = 115497,
    NPC_MEDIVH_VIZADUUM = 114463,

    /// Chess
    NPC_CHESS_HORSE = 115406,
    NPC_CHESS_ELEPHANT_DARK = 115402,
    NPC_CHESS_ELEPHANT_HOLY = 115401,
    NPC_CHESS_ROOK = 115407,
    NPC_CHESS_QUEEN = 115395,
    NPC_CHESS_KING = 115388,

    /// Nightbane (bonus boss)
    NPC_NIGHTBANE = 114895
};

enum eGameObjects
{
    ///Opera GO
    GO_OPERA_SCENE_VELUM = 259684,
    GO_OPERA_SCENE_LEFT_DOOR = 259694,
    GO_OPERA_SCENE_RIGHT_DOOR = 259702,
    GO_OPERA_DECOR_WIKKET_1 = 260311, // Wikket
    GO_OPERA_DECOR_WIKKET_2 = 260312,
    GO_OPERA_DECOR_WIKKET_3 = 260313,
    GO_OPERA_DECOR_WESTFALL_1 = 260304, // Westfall
    GO_OPERA_DECOR_WESTFALL_2 = 260307,
    GO_OPERA_DECOR_WESTFALL_3 = 260306,
    GO_OPERA_DECOR_WESTFALL_4 = 260305,
    GO_OPERA_DECOR_WESTFALL_5 = 260308,
    GO_OPERA_DECOR_BEAUTIFUL_BEAST_1 = 260298, // Beautiful Beast
    GO_OPERA_DECOR_BEAUTIFUL_BEAST_2 = 260299,
    GO_OPERA_DECOR_BEAUTIFUL_BEAST_3 = 260300,
    GO_OPERA_DECOR_BEAUTIFUL_BEAST_4 = 260301,
    GO_OPERA_DECOR_BEAUTIFUL_BEAST_5 = 260303,
    GO_OPERA_DOOR_TO_MOROES = 259730,

    ///Moroes GO
    GO_MOROES_DOOR_1 = 269977,
    GO_MOROES_DOOR_2 = 269978,
    GO_GHOST_TRAP = 259928,

    GO_DOOR_INSTANCE_PH2_1 = 259689,
    GO_DOOR_INSTANCE_PH2_2 = 266803,
    GO_DOOR_INSTANCE_PH2_3 = 266804,

    ///The Curator
    GO_CURATOR_DOOR = 266508,

    ///Shade of Medivh
    GO_MEDIVH_DOOR_1 = 266846,
    GO_MEDIVH_DOOR_2 = 266510,

    ///Mana Devourer
    GO_DEVOURER_CACHE = 266592,

    ///Vizaduum the watcher
    GO_VIZADUUM_DOOR_1 = 266593,
    GO_PORTAL_DALARAN = 266857,
};

enum eOperaActions
{
    ACTION_WIKKET_INTRO_END = 1,
    ACTION_ZONE_IN_COMBAT,
    ACTION_ENCOUNTER_DESPAWN,
};

Position const operaSpawnPos[40] =
{
    // Wikket
    {-10874.0f, -1757.86f, 90.56f, 3.23f},  //0  - 115005
    {-10872.5f, -1751.04f, 90.56f, 3.90f},  //1  - 115005
    {-10896.3f, -1745.27f, 90.55f, 4.55f},  //2  - 115005
    {-10905.9f, -1743.38f, 90.55f, 5.06f},  //3  - 115005
    {-10880.5f, -1747.40f, 90.55f, 3.90f},  //4  - 115005
    {-10872.7f, -1751.13f, 90.56f, 3.90f},  //5  - 115007
    {-10896.4f, -1745.43f, 90.55f, 4.55f},  //6  - 115007
    {-10874.1f, -1757.86f, 90.56f, 3.23f},  //7  - 115007
    {-10905.8f, -1743.53f, 90.55f, 5.06f},  //8  - 115007
    {-10880.6f, -1747.50f, 90.55f, 3.90f},  //9  - 115007
    {-10888.8f, -1756.79f, 104.94f, 4.59f}, //10 - 114251 - intro pos
    {-10891.5f, -1761.89f,  90.47f, 4.56f}, //11 - 114251 - final pos
    {-10876.3f, -1805.15f, 116.51f, 1.67f}, //12 - 114284 - intro pos
    {-10896.4f,  -1758.5f,  90.48f, 4.58f}, //13 - 114284 - final pos

    // Westfall
    {-10879.0f, -1756.53f, 90.55f, 2.92f}, //14 - 114260
    {-10905.0f, -1755.24f, 90.55f, 0.0f},  //15 - 114261
    {-10908.7f, -1760.70f, 90.56f, 0.35f}, //16 - 114265
    {-10909.4f, -1756.20f, 90.56f, 6.18f}, //17 - 114265
    {-10907.4f, -1752.71f, 90.55f, 5.88f}, //18 - 114265
    {-10874.1f, -1756.75f, 90.56f, 2.71f}, //19 - 114266
    {-10872.5f, -1759.25f, 90.56f, 2.68f}, //20 - 114266
    {-10874.5f, -1753.44f, 90.56f, 3.55f}, //21 - 114266
    {-10870.89f, -1773.27f, 90.56f, 3.0f}, //22 - 114471
    {-10867.05f, -1751.13f, 90.56f, 3.0f}, //23 - 114471
    {-10913.78f, -1741.09f, 90.55f, 6.1f}, //24 - 114471
    {-10913.43f, -1779.65f, 90.56f, 6.1f}, //25 - 114471
    {-10916.08f, -1771.52f, 90.56f, 6.1f}, //26 - 114471
    {-10870.82f, -1766.00f, 90.56f, 3.0f}, //27 - 114471
    {-10871.60f, -1780.78f, 90.56f, 3.0f}, //28 - 114471
    {-10913.08f, -1749.38f, 90.56f, 6.1f}, //29 - 114471
    {-10913.13f, -1756.79f, 90.56f, 6.1f}, //30 - 114471
    {-10878.17f, -1787.46f, 90.56f, 3.0f}, //31 - 114471
    {-10916.40f, -1763.52f, 90.56f, 6.1f}, //32 - 114471
    {-10870.98f, -1758.55f, 90.56f, 3.0f}, //33 - 114471

    // Beautiful Beast
    {-10883.4f, -1752.55f, 90.55f, 3.74f}, //34 - 114328 
    {-10888.2f, -1751.59f, 90.55f, 3.62f}, //35 - 114329 
    {-10892.2f, -1749.48f, 90.55f, 3.74f}, //36 - 114330 
    {-10884.7f, -1757.01f, 90.56f, 3.74f}, //37 - 114522 
    {-10903.3f, -1752.55f, 90.55f, 3.60f}, //38 - 114545 
    {-10906.3f, -1754.22f, 90.55f, 0.55f}, //39 - 114583 
};

Position const helperPos[4] =
{
    {-10988.90f, -1878.57f, 81.81f, 0.04f},
    {-10986.40f, -1876.76f, 81.81f, 4.26f},
    {-10978.29f, -1877.71f, 81.81f, 4.87f},
    {-10976.29f, -1879.96f, 81.81f, 3.19f}
};

Position const moroesScenePos[2] =
{
    {-10987.85f, -1882.53f, 81.72f, 0.12f},
    {-10979.08f, -1881.64f, 81.72f, 3.27f}
};

Position const medivhSEventPos[3] =
{
    {-4581.10f, -2526.68f, 2876.63f},
    {-4618.89f, -2526.83f, 2876.63f},
    {-4599.80f, -2494.75f, 2876.63f}
};

Position const commandPos[3] =
{
    {3397.11f, -2142.85f, 977.43f, 6.1f},
    {3496.74f, -1959.66f, 996.70f, 5.8f},
    {3800.63f, -1876.49f, 869.97f, 4.1f}
};

Position const harvestPos[4] =
{
    {3939.42f, -2007.51f, 926.93f},
    {3974.58f, -2001.94f, 927.57f},
    {3948.79f, -1980.31f, 926.93f},
    {3964.87f, -2028.79f, 927.57f}
};

Position const guardPos[8] =
{
    {3471.18f, -2030.16f, 1039.92f, 1.11f},
    {3454.24f, -2021.22f, 1039.92f, 0.86f},
    {3491.31f, -1947.53f, 1039.72f, 1.76f},
    {3483.37f, -1964.85f, 1039.72f, 1.01f},
    {3473.50f, -1976.96f, 1039.72f, 4.01f},
    {3500.32f, -1979.89f, 1039.72f, 4.66f},
    {3504.10f, -1965.63f, 1039.72f, 1.14f},
    {3512.49f, -1948.06f, 1039.72f, 0.47f}
};

Position const spitterPos[4] =
{
    {3453.50f, -2028.14f, 1065.27f},
    {3454.75f, -1963.09f, 1059.92f},
    {3526.33f, -2001.64f, 1059.92f},
    {3532.10f, -1962.30f, 1067.61f}
};

Position const khadgarEventPos[2] =
{
    {3470.38f, -2027.17f, 1039.97f, 1.29f},
    {3456.75f, -2019.77f, 1039.97f, 0.34f}
};

Position const endPortalPos = { 3649.46f, -2146.04f, 815.59f, 5.56f };

#endif
