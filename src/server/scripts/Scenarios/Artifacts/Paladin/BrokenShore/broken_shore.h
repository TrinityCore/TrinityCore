#ifndef DEF_BROKEN_SHORE
#define DEF_BROKEN_SHORE

enum Spells
{
};

enum Data
{
    DATA_STAGE_1                = 0,
    DATA_STAGE_2                = 1,
    DATA_STAGE_3                = 2,
    DATA_STAGE_4                = 3,
    DATA_STAGE_5                = 4,
    DATA_STAGE_6                = 5,
    DATA_STAGE_FINAL            = 6,

    DATA_TRASH_FIGHT,
    DATA_KILL_TRASH,
};

enum eCreatures
{
    NPC_LORD_MAXWELL_TYROSUS    = 90883,
    NPC_LORD_MAXWELL_TYROSUS_Q  = 91144,

    NPC_JAILER_ZERUS            = 97621,
    NPC_JAILER_ZERUS_BOSS       = 91672,
    NPC_THE_JAILERS_PRISON      = 97824,
    NPC_DEMON_PORTAL            = 93459,

    NPC_BALNAZZAR               = 90981,
    NPC_DOMINATE_MIND           = 108997,
    NPC_HAZE_DREADLORD          = 100060,
    NPC_SHADOW_IMP              = 100154,

    NPC_TIRION_FORDRING_1       = 91255,  //В тюрьме
    NPC_TIRION_FORDRING_2       = 92676,  //При смерти
    NPC_TIRION_FORDRING_3       = 100332, //Мертв
    NPC_TIRION_FORDRING_SOUL    = 94595,
    
//< Trash
    //Allies forces
    NPC_ARGENT_PHALANX_1        = 92858,
    NPC_ARGENT_PHALANX_2        = 92860,
    NPC_ARGENT_PHALANX_3        = 92857,
    NPC_ARGENT_DAWNBRINGER_1    = 92862,
    NPC_ARGENT_DAWNBRINGER_2    = 92865,
    NPC_ARGENT_DAWNBRINGER_3    = 92866,
    NPC_RIGHTEOUS_CRUSADER_1    = 90886,
    NPC_RIGHTEOUS_CRUSADER_2    = 90889,
    NPC_RIGHTEOUS_CRUSADER_3    = 90891,

    //Enemy forces
    NPC_DOOMGUARD_INCINERATOR   = 95962,
    NPC_DARK_INQUISITOR         = 91697,
    NPC_BURNING_CRUSHER         = 96005,
    NPC_MOARG_BRUTALIZER        = 95984,
    NPC_WRATHGUARD_CLEAVER_1    = 91634,
    NPC_WRATHGUARD_CLEAVER_2    = 97566,
    NPC_RAVENOUS_FELSTALKER_1   = 91636,
    NPC_RAVENOUS_FELSTALKER_2   = 97567,
};

enum eGameObects
{
    GO_DEMON_PORTAL_1           = 244580,
    GO_DEMON_PORTAL_2           = 244585,
    GO_DEMON_PORTAL_3           = 240627,
    GO_ZERUS_DOOR               = 243715,
    GO_BOSS_ZERUS_DOOR_1        = 243816,
    GO_BOSS_ZERUS_DOOR_2        = 245962,
};

Position const portalSpawnPos[2] =
{
    {-2511.03f, 60.909f, 8.28f},
    {-2500.67f, 111.22f, 8.25f}
};

Position const forcesPoint[12] =
{
    {-2477.11f, 111.56f, 7.36f},
    {-2472.61f, 100.94f, 7.20f},
    {-2480.5f,  103.21f, 7.12f},
    {-2475.88f, 91.452f, 7.05f},
    {-2485.01f, 92.722f, 7.59f},
    {-2489.59f, 111.30f, 7.91f},
    {-2474.37f, 84.705f, 7.19f},
    {-2467.58f, 92.855f, 7.14f},
    {-2492.34f, 102.92f, 7.88f},
    {-2498.25f, 112.49f, 8.15f},
    {-2491.61f, 95.469f, 8.45f},
    {-2482.51f, 121.60f, 7.74f},
};

Position const flameTarget[36] =
{
    {-2558.13f, 89.05f, 21.84f},
    {-2567.81f, 83.29f, 24.24f},
    {-2561.03f, 75.25f, 22.56f},
    {-2579.42f, 71.36f, 27.23f},
    {-2579.91f, 85.28f, 27.48f},
    {-2574.86f, 91.87f, 26.11f},
    {-2587.08f, 67.08f, 30.15f},
    {-2599.74f, 61.41f, 33.17f},
    {-2605.72f, 75.00f, 34.78f},
    {-2614.97f, 86.25f, 37.35f},
    {-2603.01f, 93.47f, 34.61f},
    {-2621.35f, 82.83f, 38.95f},
    {-2624.01f, 24.37f, 44.17f},
    {-2619.76f, 68.02f, 38.36f},
    {-2619.27f, 44.91f, 40.11f},
    {-2632.45f, 52.95f, 41.67f},
    {-2603.53f, 42.06f, 37.81f},
    {-2605.92f, 33.49f, 38.75f},
    {-2611.51f, 22.44f, 42.09f},
    {-2632.49f, 39.42f, 43.58f},
    {-2645.43f, 48.51f, 45.38f},
    {-2639.17f, 24.08f, 47.07f},
    {-2645.79f, 16.48f, 48.95f},
    {-2654.15f, 12.60f, 49.97f},
    {-2667.30f, 13.20f, 50.57f}, 
    {-2660.94f, -7.65f, 50.97f},
    {-2647.38f, -5.79f, 52.42f},
    {-2637.75f, -6.39f, 50.85f},
    {-2634.75f, 3.174f, 48.77f},
    {-2624.20f, 2.165f, 50.59f},
    {-2617.07f, 9.336f, 47.83f},
    {-2632.12f, 26.00f, 45.56f},
    {-2637.27f, 15.10f, 47.80f},
    {-2645.22f, 7.227f, 49.35f},
    {-2653.04f, 2.794f, 50.43f},
    {-2608.64f, 27.94f, 40.63f}
};

Position const zerusSumPos[4] =
{
    {-2715.02f, -76.29f, 47.64f, 6.14f},
    {-2777.11f, -92.78f, 47.39f, 3.67f},
    {-2696.52f, -79.80f, 47.45f, 2.95f},
    {-2795.02f, -99.68f, 48.73f, 0.50f}
};

Position const demonPortalPos[5] =
{
    {-2795.07f, -100.21f, 37.05f, 0.47f},
    {-2696.24f, -79.557f, 35.82f, 3.10f},
    {-2737.36f, -291.11f, 25.29f, 5.26f},
    {-2754.08f, -281.49f, 26.30f, 5.26f},
    {-2739.93f, -307.08f, 26.20f, 2.23f}
};

Position const hazePos[10] =
{
    {-2774.99f, -318.85f, 32.61f},
    {-2746.55f, -275.19f, 36.93f},
    {-2768.96f, -303.53f, 32.75f},
    {-2770.15f, -281.53f, 33.79f},
    {-2734.31f, -312.36f, 31.67f},
    {-2771.38f, -272.37f, 43.34f},
    {-2711.41f, -319.53f, 28.97f},
    {-2783.31f, -295.80f, 34.35f},
    {-2749.21f, -325.12f, 38.06f}, 
    {-2716.50f, -294.81f, 30.36f}
};

#endif
