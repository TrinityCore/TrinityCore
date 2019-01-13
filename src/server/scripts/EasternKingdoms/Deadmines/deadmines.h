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

#ifndef DEF_DEADMINES_H
#define DEF_DEADMINES_H

#define DataHeader "DM"
#define DMScriptName "instance_deadmines"

uint32 const EncounterCount = 6;

enum DMDataTypes
{
    // Encounters
    DATA_GLUBTOK                        = 0,
    DATA_HELIX_GEARBREAKER              = 1,
    DATA_FOE_REAPER_5000                = 2,
    DATA_ADMIRAL_RIPSNARL               = 3,
    DATA_CAPTAIN_COOKIE                 = 4,
    DATA_VANESSA_VAN_CLEEF              = 5,

    DATA_TEAM_IN_INSTANCE               = 6,
    DATA_FIREWALL_PLATTER               = 7,
    DATA_LUMBERING_OAF                  = 8,
    DATA_FOE_REAPER_INTRO               = 9,
    DATA_FOE_REAPER_BUNNY               = 10,
    DATA_PROTOTYPE_REAPER               = 11,
    DATA_BROKEN_DOOR                    = 13,
    DATA_IRON_CLAD_DOOR                 = 14,
    DATA_RIPSNARL_FOG                   = 15,
    DATA_VANESSA_VAN_CLEEF_ENCOUNTER    = 16,
    DATA_VANESSAS_TRAP_BUNNY            = 17,
    DATA_VANESSA_ANCHOR_BUNNY           = 18,
    DATA_ACTIVATED_VENT                 = 19,
    DATA_FOUNDRY_DOOR                   = 20,
    DATA_VANESSA_VAN_CLEEF_NIGHTMARE    = 21,
    DATA_EMME_HARRINGTON                = 22,
    DATA_ERIK_HARRINGTON                = 23,
    DATA_CALISSA_HARRINGTON             = 24,
    DATA_SUMMON_ROPES                   = 25
};

enum DMCreatures
{
    // Bosses
    BOSS_GLUBTOK                        = 47162,
    BOSS_HELIX_GEARBREAKER              = 47296,
    BOSS_FOE_REAPER_5000                = 43778,
    BOSS_ADMIRAL_RIPSNARL               = 47626,
    BOSS_CAPTAIN_COOKIE                 = 47739,
    BOSS_VANESSA_VAN_CLEEF              = 49541,

    // Horde Creatures
    NPC_SLINKY_SHARPSHIV                = 46906,
    NPC_KAGTHA                          = 46889,
    NPC_MISS_MAYHEM                     = 46902,
    NPC_SHATTERED_HAND_ASSASSIN         = 46890,
    NPC_MAYHEM_REAPER_PROTOTYPE         = 46903,

    // Alliance Creatures
    NPC_STORMWIND_INVESTIGATOR          = 46614,
    NPC_CRIME_SCENE_ALARM_O_BOT         = 46613,
    NPC_STORMWIND_DEFENDER              = 50595,
    NPC_LIEUTENANT_HORATIO_LAINE        = 46612,
    NPC_QUARTERMASTER_LEWIS             = 491,

    // Encounter Related
    NPC_GENERAL_PURPOSE_DUMMY_JMF       = 45979,
    NPC_GLUBTOK_FIREWALL_PLATTER        = 48974,
    NPC_FIREWALL_PLATTER_1A             = 48975,
    NPC_FIREWALL_PLATTER_1B             = 49039,
    NPC_FIREWALL_PLATTER_1C             = 49040,
    NPC_FIREWALL_PLATTER_2A             = 48976,
    NPC_FIREWALL_PLATTER_2B             = 49041,
    NPC_FIREWALL_PLATTER_2C             = 49042,
    NPC_GENERAL_PURPOSE_BUNNY_L2        = 47242,
    NPC_FIRE_BLOSSOM_BUNNY              = 47282,
    NPC_FROST_BLOSSOM_BUNNY             = 47284,
    NPC_LUMBERING_OAF                   = 47297,
    NPC_HELIX_CREW                      = 49139,
    NPC_STICKY_BOMB                     = 47314,
    NPC_DEFIAS_REAPER                   = 47403,
    NPC_DEFIAS_WATCHER                  = 47404,
    NPC_FOE_REAPER_TARGETING_BUNNY      = 47468,
    NPC_PROTOTYPE_REAPER                = 49208,
    NPC_MOLTEN_SLAG                     = 49229,
    NPC_VAPOR                           = 47714,
    NPC_COOKIES_CAULDRON                = 47754,
    NPC_CORN                            = 48006,
    NPC_ROTTEN_CORN                     = 48276,
    NPC_MELON                           = 48294,
    NPC_ROTTEN_MELON                    = 48293,
    NPC_STEAK                           = 48296,
    NPC_ROTTEN_STEAK                    = 48295,
    NPC_MYSTERY_MEAT                    = 48297,
    NPC_ROTTEN_MYSTERY_MEAT             = 48298,
    NPC_LOAF                            = 48300,
    NPC_ROTTEN_LOAF                     = 48299,
    NPC_BUN                             = 48301,
    NPC_ROTTEN_BUN                      = 48302,
    NPC_A_NOTE_FROM_VANESSA             = 49564,
    NPC_VANESSA_VAN_CLEEF_INTRO         = 49429,
    NPC_VANESSAS_TRAP_BUNNY             = 49454,
    NPC_VANESSA_ANCHOR_BUNNY_JMF        = 51624,
    NPC_STEAM_VALVE                     = 49457,
    NPC_VANESSA_VANCLEEF_NIGHTMARE      = 49671,
    NPC_GLUBTOK_NIGHTMARE_FIRE_BUNNY    = 51594,
    NPC_GLUBTOK_NIGHTMARE               = 49670,
    NPC_HELIX_GEARBREAKER_NIGHTMARE     = 49674,
    NPC_NIGHTMARE_SKITTERLING           = 49493,
    NPC_DARKWEB_DEVOURER                = 49494,
    NPC_CHATTERING_HORROR               = 49495,
    NPC_FOE_REAPER_5000_NIGHTMARE       = 49681,
    NPC_VANESSA_LIGHTNING_PLATTER       = 49520,
    NPC_RIPSNARL_NIGHTMARE              = 49682,
    NPC_EMME_HARRINGTON                 = 49534,
    NPC_ERIK_HARRINGTON                 = 49535,
    NPC_ENRAGED_WORGEN                  = 49532,
    NPC_JAMES_HARRINGTON                = 49539,
    NPC_CALISSA_HARRINGTON              = 49536,
    NPC_DEFIAS_SHADOWGUARD              = 49852,
    NPC_DEFIAS_ENFORCER                 = 49850,
    NPC_ROPE                            = 49550,
    NPC_VANESSAS_ROPE_ANCHOR            = 49552,
}; 

enum DMGameObjects
{
    GO_FACTORY_DOOR     = 13965,
    GO_IRON_CLAD_DOOR   = 16397,
    GO_DEFIAS_CANNON    = 16398,
    GO_DOOR_LEVER       = 101833,
    GO_MAST_ROOM_DOOR   = 16400,
    GO_HEAVY_DOOR       = 17153,
    GO_FOUNDRY_DOOR     = 16399
};

enum DMActions
{
    ACTION_ELECTRICAL_CHARGE = 1,
    ACTION_EJECT_PLAYERS     = 1,
};

enum DMSpells
{
    // -- Admiral Ripsnarl Encounter
    SPELL_FOG                               = 88768,

    // -- Vanessa VanCleef Encounter
    SPELL_RIDE_MAGMA_VEHICLE                = 92378,
    SPELL_MOLTEN_MAGMA                      = 92424,
    SPELL_FORCE_MAGMA_TRAP_THROW            = 92489,
    SPELL_ROPE_BEAM                         = 43785,
    SPELL_CLICK_ME                          = 95527,
    SPELL_STEAM_VENT                        = 92399,
    SPELL_ADRENALINE                        = 92604,
    SPELL_NIGHTMARE_SLOW                    = 92559,
    SPELL_NIGHTMARE_AURA                    = 92563,
    SPELL_CANCEL_NIGHTMARE_AURA_GLUBTOK     = 92584,
    SPELL_CANCEL_NIGHTMARE_AURA_HELIX       = 92585,
    SPELL_CANCEL_NIGHTMARE_AURA_MECHANICAL  = 92586,
    SPELL_CANCEL_NIGHTMARE_AURA_RIPSNARL    = 92587,
    SPELL_SPIRIT_STRIKE                     = 59304,
    SPELL_SUMMON_ICICLE                     = 92189,
    SPELL_OFF_LINE                          = 88348,
    SPELL_NIGHTMARES_END                    = 92603,
    SPELL_CANCEL_NIGHTMARE_ELIXIR           = 92609,
};

enum DMVanessasNightmareStages
{
    // IN_PROGRESS = 1,
    // FAIL = 2,
    NIGHTMARE_STATE_PREPARE_TRAP    = 3,
    NIGHTMARE_STAGE_MAGMA_TRAP      = 4,
    NIGHTMARE_STAGE_GLUBTOK         = 5,
    NIGHTMARE_STAGE_HELIX           = 6,
    NIGHTMARE_STAGE_FOE_REAPER      = 7,
    NIGHTMARE_STAGE_RIPSNARL        = 8,
    NIGHTMARE_STAGE_DONE            = 9
};

Position const captainCookieSpawnPos = { -88.13194f, -819.3299f, 39.23453f };
Position const bossVanessaVanCleefSpawnPos = { -79.44965f, -819.8351f, 39.89838f, 0.01745329f };

Position const noteFromVanessaSpawnPos = { -74.36111f, -820.0139f, 40.37145f, 4.014257f };
Position const vanessaVanCleefSpawnPos = { -75.58507f, -819.9636f, 47.06727f, 6.178465f };

Position const vanessaVanCleefNightmareSpawnPos[] =
{
    { -230.717f, -563.0139f, 51.31293f, 1.047198f },
    { -172.809f, -576.9114f, 19.39756f, 4.817109f },
    { -159.3924f, -580.5174f, 19.39817f, 6.195919f },
    { -98.5816f, -662.6632f, 7.498006f,  3.490659f }
};

Position const GlubtokNightmareIntroSpawnPos = { -229.3403f, -560.3629f, 51.31293f, 5.742133f };
Position const GlubtokNightmareSpawnPos = { -174.8212f, -579.7552f, 19.39602f, 3.193953f };

Position const HelixNightmareSpawnPos = { -172.6858f, -580.0469f, 19.39752f, 3.176499f };
Position const GeneralPurposeBunnyPos = { -205.4688f, -567.2049f, 21.06016f };

Position const FoeReaperNightmareIntroSpawnPos = { -155.4705f, -580.6945f, 19.39779f };
Position const FoeReaperNightmareSpawnPos = { -101.4549f, -663.6493f, 7.505813f, 1.850049f };

Position const RipsnarlNightmareIntroSpawnPos = { -101.2135f, -663.4531f, 7.504823f, 1.867502f };
Position const EmmeHarringtonSpawnPos = { -98.63194f, -721.6268f, 8.547067f, 1.53589f };
Position const EnragedWorgenEmmeSpawnPos[] =
{
    {-97.79166f, -717.8542f, 8.668088f, 4.520403f },
    { -94.40278f, -719.7274f, 8.598646f,  3.560472f },
    { -101.9167f, -718.7552f, 8.726379f,  5.51524f },
};

Position const ErikHarringtonSpawnPos = { 5.239583f, -763.0868f, 9.800426f, 2.007129f };

Position const EnragedWorgenErikSpawnPos[] =
{
    { 3.326038f, -760.3063f, 9.713999f, 5.31516f },
    { 8.798013f, -762.2252f, 9.625132f, 3.379143f },
    { 4.232807f, -766.6125f, 9.804724f, 1.292649f }
};

Position const CalissaHarringtonSpawnPos = { -83.86406f, -775.2837f, 28.37906f, 1.710423f };
Position const JamesHarringtonSpawnPos = { -83.16319f, -774.9636f, 26.90351f, 1.710423f };

Position const glubtokNightmareFireBunnyPos[] =
{
    { -192.2031f,   -595.9636f, 36.37407f,  2.80998f },
    { -220.625f,    -577.9618f, 21.06016f,  2.513274f },
    { -205.3056f,   -563.6285f, 21.06016f,  5.253441f },
    { -214.8958f,   -546.7136f, 19.3898f,   4.712389f },
    { -207.8004f,   -570.6441f, 21.06016f,  1.762783f },
    { -221.4653f,   -549.9358f, 19.3898f,   3.211406f },
    { -229.9635f,   -559.2552f, 19.3898f,   0.0f },
    { -216.8438f,   -568.9011f, 21.06016f,  3.909538f },
    { -235.9045f,   -563.3906f, 19.3898f,   0.0f },
    { -226.6736f,   -580.8316f, 20.43056f,  2.775074f },
    { -227.5226f,   -595.1979f, 20.42358f,  4.206244f },
    { -215.0399f,   -576.3941f, 21.06016f,  3.735005f },
    { -210.592f,    -583.4739f, 21.06016f,  0.0f },
    { -228.592f,    -553.1684f, 19.3898f,   5.550147f },
    { -220.4879f,   -596.382f,  21.95116f,  0.0f },
    { -190.4774f,   -552.2778f, 51.31293f,  5.305801f },
    { -195.6267f,   -550.4393f, 51.31293f,  3.752458f },
    { -209.7257f,   -557.1042f, 51.31293f,  3.525565f },
    { -187.9531f,   -567.0469f, 51.31293f,  5.305801f },
    { -185.2083f,   -562.4844f, 19.3898f,   0.9599311f },
    { -183.4236f,   -577.2674f, 46.87183f,  3.944444f },
    { -184.6528f,   -572.3663f, 49.27317f,  3.159046f },
    { -191.2205f,   -581.4965f, 21.06015f,  2.007129f },
    { -201.224f,    -570.6788f, 21.06016f,  3.577925f },
    { -198.4653f,   -580.757f,  21.06015f,  0.8901179f },
    { -196.8767f,   -574.9688f, 21.06016f,  4.29351f },
    { -194.1302f,   -548.3055f, 19.3898f,   4.153883f },
    { -187.3333f,   -550.8143f, 19.3898f,   3.385939f },
    { -186.9792f,   -556.8472f, 19.3898f,   4.153883f },
    { -196.5504f,   -587.7031f, 21.06015f,  1.27409f },
    { -241.5938f,   -578.6858f, 19.3898f,   2.775074f },
    { -226.1615f,   -573.8021f, 20.40991f,  5.218534f }
};

Position const nightmareSkitterlingPos[] =
{
    { -184.9618f, -552.9132f, 19.3898f },
    { -199.1406f, -573.6893f, 21.06016f },
    { -194.5851f, -578.3386f, 21.06015f },
    { -193.3264f, -569.809f, 21.06016f },
    { -185.7622f, -566.6059f, 19.3898f },
    { -181.401f, -561.684f, 19.3898f },
    { -221.2569f, -549.3316f, 19.3898f },
    { -215.125f, -546.0486f, 19.3898f },
    { -210.3854f, -550.6736f, 19.3898f },
    { -206.8715f, -545.3837f, 19.3898f },
    { -208.3247f, -556.5833f, 19.3898f },
    { -203.1233f, -550.8281f, 19.3898f },
    { -198.2465f, -546.9288f, 19.3898f },
    { -178.6389f, -564.4479f, 19.39f },
    { -193.3698f, -581.8663f, 21.06015f },
    { -188.1788f, -578.3715f, 21.06015f },
    { -185.3385f, -562.592f, 19.3898f },
    { -179.6458f, -557.9063f, 19.3898f },
    { -226.5208f, -587.257f, 19.53274f },
    { -199.3351f, -586.7952f, 21.06015f },
    { -207.6545f, -594.809f, 21.06015f },
    { -201.2587f, -593.309f, 21.06016f },
    { -224.2743f, -592.7917f, 20.29579f },
    { -211.9844f, -569.5417f, 21.06016f },
    { -208.9288f, -563.6094f, 21.06016f },
    { -200.8715f, -557.2518f, 19.3898f },
    { -196.2396f, -553.6927f, 19.3898f },
    { -192.1163f, -550.1024f, 19.3898f },
    { -202.4063f, -563.1337f, 21.06016f },
    { -195.9635f, -560.8889f, 20.58139f },
    { -190.1094f, -557.4722f, 19.3898f },
    { -199.3229f, -550.3785f, 19.3898f },
    { -195.2552f, -557.0087f, 19.3898f },
    { -190.1372f, -553.0625f, 19.3898f },
    { -185.2118f, -557.6406f, 19.3898f },
    { -190.6406f, -561.441f, 19.3898f },
    { -197.7413f, -564.3021f, 21.06016f },
    { -215.5365f, -549.8021f, 19.3898f },
    { -212.1719f, -555.0226f, 19.3898f },
    { -213.2344f, -561.8577f, 21.06016f },
    { -208.5451f, -568.1146f, 21.06016f },
    { -202.7257f, -572.5174f, 21.06016f },
    { -205.6354f, -559.1563f, 21.06016f },
    { -206.1615f, -553.3507f, 19.3898f },
    { -202.5451f, -546.118f, 19.3898f },
    { -204.1024f, -596.7518f, 21.06016f },
    { -204.0087f, -590.8386f, 21.06016f },
    { -198.8316f, -591.7239f, 21.06015f },
    { -195.4375f, -586.2934f, 21.06015f },
    { -197.6493f, -582.4653f, 21.06015f },
    { -219.1337f, -559.7899f, 19.3898f },
    { -221.4063f, -553.1406f, 19.3898f },
    { -216.1215f, -564.882f, 21.06016f },
    { -199.3125f, -578.1996f, 21.06016f },
    { -204.684f, -569.3542f, 21.06016f },
    { -197.8576f, -569.3489f, 21.06016f },
    { -191.7656f, -565.8559f, 21.06016f },
    { -213.4635f, -591.625f, 21.06015f },
    { -206.0781f, -588.0712f, 21.06016f },
    { -213.1997f, -585.125f, 21.06015f },
    { -220.5174f, -581.8143f, 21.06016f },
    { -182.8004f, -569.368f, 19.39167f },
    { -189.0191f, -571.2674f, 21.06016f },
    { -193.7674f, -574.7014f, 21.06016f },
    { -226.1285f, -581.059f, 20.79114f },
    { -218.6076f, -581.0746f, 21.06016f },
    { -216.1094f, -576.8264f, 21.06016f },
    { -222.1545f, -555.1077f, 19.3898f },
    { -212.6059f, -567.2239f, 21.06016f },
    { -203.9184f, -551.0608f, 19.3898f },
    { -202.8663f, -590.1371f, 21.06016f },
    { -196.4757f, -573.0833f, 21.06016f },
    { -185.9288f, -558.125f, 19.3898f },
    { -213.8767f, -559.3125f, 20.02806f },
    { -221.8142f, -556.3976f, 19.3898f },
    { -216.5017f, -553.9722f, 19.3898f },
    { -223.7483f, -574.9896f, 21.06015f },
    { -226.1215f, -563.0382f, 19.3898f },
    { -213.8559f, -574.6094f, 21.06016f },
    { -208.3854f, -571.8004f, 21.06016f },
    { -224.5625f, -568.1476f, 19.92673f },
    { -219.7083f, -588.6094f, 21.06015f },
    { -218.8872f, -570.5643f, 21.06016f },
    { -221.8264f, -562.2795f, 19.3898f },
    { -227.9063f, -559.566f, 19.3898f },
    { -230.4948f, -566.0191f, 19.3898f },
    { -227.0243f, -552.6736f, 19.3898f },
    { -231.566f, -572.1979f, 19.3898f },
    { -231.8802f, -578.5677f, 19.3898f },
    { -232.4462f, -562.8837f, 19.3898f },
    { -232.4514f, -586.2518f, 19.3898f },
    { -230.3767f, -592.8577f, 19.3898f },
    { -232.8004f, -591.1805f, 19.3898f },
    { -234.5208f, -559.4809f, 19.3898f },
    { -236.5712f, -565.5573f, 19.3898f },
    { -237.5799f, -571.5903f, 19.3898f },
    { -238.9063f, -578.1528f, 19.3898f },
    { -234.0608f, -598.0f,    19.95063f },
    { -236.5122f, -591.9913f, 19.3898f },
    { -238.8021f, -584.8594f, 19.3898f },
};

Position const DarkwebDevourerPos[] =
{
    { -215.7064f, -553.3212f, 51.29544f, 0.7243207f },
    { -229.285f, -568.6863f, 51.31313f, 0.8218399f },
    { -231.3453f, -584.1043f, 51.31514f, 1.05134f }
};

Position const ChatteringHorrorPos = { -233.625f, -570.5868f, 19.3898f };

float const LightningPlatterCirclePathHeight[] =
{
    14.28754f,  // -120.9898 Y: -638.3776 Z: 12.34728
    16.38484f,  // -135.3954 Y: -623.0512 Z: 14.44327
    16.18771f,  // -120.1581 Y: -617.6207 Z: 14.24549
    17.47415f,  // -136.7385 Y: -604.6659 Z: 15.53128
    20.52248f,  // -130.4809 Y: -586.5009 Z: 18.57832
    21.08911f   // -143.004  Y: -574.9209 Z: 19.1443
};

Position const LightningPlatterPos[] =
{
    { -120.9898f, -638.3776f, 12.34728f, 0.03183358f },
    { -135.3954f, -623.0512f, 14.44327f, 0.03133297f },
    { -120.1581f, -617.6207f, 14.24549f, 6.252115f   },
    { -136.7385f, -604.6659f, 15.53128f, 0.03079747f },
    { -130.4809f, -586.5009f, 18.57832f, 0.03022512f },
    { -143.004f, -574.9209f, 19.1443f,   6.253215f   }
};

Position const VanessaEntranceFirePos[] =
{
    { -38.11458f, -795.2952f, 39.45137f, 3.926991f },
    { -64.02257f, -797.4323f, 39.12309f, 3.926991f },
    { -46.48438f, -791.8073f, 39.12098f, 3.926991f },
    { -75.50694f, -787.1597f, 39.16325f, 3.926991f },
    { -66.18229f, -789.2778f, 39.78834f, 3.926991f },
    { -70.9809f, -795.5f, 39.14447f, 3.926991f }
};

Position const RopePos[] =
{
    { -62.17014f, -839.8438f, 41.48514f, 5.044002f },
    { -64.97049f, -840.0087f, 41.22668f, 4.834562f },
    { -67.79166f, -840.1736f, 40.96664f, 4.712389f },
    { -70.62153f, -840.0104f, 40.71846f, 4.537856f },
    { -73.42361f, -839.8646f, 40.47259f, 4.34587f  }
};

Position const RopeAnchorPos[] =
{
    { -63.6059f, -862.7864f, 202.7301f, 4.607669f },
    { -64.21702f, -866.1823f, 195.3946f, 4.607669f },
    { -69.15452f, -868.9636f, 195.2482f, 4.607669f },
    { -71.11459f, -868.4636f, 200.7708f, 4.607669f },
    { -74.29688f, -877.1007f, 195.0443f, 4.607669f }
};

Position const RopePath1[] =
{
    { -59.18403f, -877.3125f, 35.78355f },
    { -58.08333f, -923.9757f, 50.83706f },
    { -52.68403f, -922.8768f, 50.83706f },
    { -58.59201f, -877.1684f, 38.01407f },
    { -62.86285f, -836.3472f, 46.62854f }
};

Position const RopePath2[] =
{
    { -62.23438f, -877.2969f, 35.78355f },
    { -66.63021f, -924.0417f, 50.83706f },
    { -60.85938f, -924.0399f, 50.83706f },
    { -62.03472f, -877.4514f, 38.01407f },
    { -64.96875f, -836.7847f, 46.62854f }
};

Position const RopePath3[] =
{
    { -67.98264f, -877.3785f, 35.78355f },
    { -75.66493f, -924.3958f, 50.83706f },
    { -69.01215f, -923.9114f, 50.83706f },
    { -67.80903f, -877.0972f, 38.01407f },
    { -68.02778f, -836.6268f, 46.62854f }
};

Position const RopePath4[] =
{
    { -74.47049f, -878.3611f, 35.78355f },
    { -82.86111f, -922.4688f, 50.83706f },
    { -77.72396f, -924.1285f, 50.83706f },
    { -71.76563f, -877.132f, 38.01407f },
    { -70.55209f, -836.6754f, 46.62854f }
};

Position const RopePath5[] =
{
    { -77.625f, -877.75f, 35.78355f },
    { -85.46528f, -922.4965f, 50.83706f },
    { -91.52431f, -921.3768f, 50.83706f },
    { -78.06944f, -875.9445f, 38.01407f },
    { -73.34549f, -836.3733f, 46.62854f }
};

Position const VanessaNightmareFirePos[] =
{
    { -85.18403f, -822.6042f, 39.48589f, 3.926991f },
    { -62.18924f, -834.6563f, 41.49004f, 3.193953f },
    { -76.88889f, -806.1927f, 40.12347f, 3.926991f },
    { -60.28472f, -806.1979f, 41.61631f, 2.75762f },
    { -41.65799f, -834.1059f, 34.51352f, 3.926991f },
    { -79.61111f, -794.7726f, 38.50275f, 3.926991f },
    { -54.19097f, -789.9566f, 38.85344f, 3.926991f },
    { -59.27778f, -787.6597f, 39.37201f, 3.926991f },
    { -44.94792f, -801.1077f, 40.703f, 3.926991f },
    { -75.33681f, -833.434f, 40.29444f, 3.193953f },
    { -62.4375f, -825.9114f, 41.42738f, 3.193953f },
    { -70.38889f, -824.9722f, 40.70635f, 3.193953f },
    { -66.54514f, -815.118f, 41.0335f, 3.193953f },
    { -57.90972f, -816.8611f, 41.85588f, 2.75762f },
    { -54.5382f, -833.9739f, 42.20368f, 2.75762f },  
    { -81.48264f, -832.3143f, 39.79344f, 2.75762f },
    { -76.38541f, -821.6371f, 40.15092f, 2.75762f },
    { -84.03125f, -817.4323f, 39.54358f, 2.75762f },
    { -34.31597f, -825.7864f, 35.14482f, 3.926991f },
    { -101.6024f, -822.2257f, 38.22025f, 3.926991f },
    { -110.0f, -821.908f, 30.27846f, 3.926991f },
    { -54.32118f, -840.3108f, 33.4867f, 3.926991f },
    { -92.3125f, -835.5712f, 31.01794f, 3.926991f },
    { -95.20313f, -826.7986f, 38.69661f, 3.926991f },
    { -81.6875f, -791.7795f, 25.86889f, 3.926991f },
    { -75.52952f, -788.3438f, 26.0653f, 3.926991f },
    { -104.3299f, -806.0121f, 30.58083f, 3.926991f },
    { -87.6875f, -830.8108f, 39.29154f, 2.75762f },
    { -46.73611f, -821.1771f, 52.5815f, 3.193953f },
    { -69.06944f, -834.368f, 40.86119f, 3.193953f },
    { -68.94444f, -805.1528f, 40.82362f, 3.926991f },
    { -38.67708f, -816.1389f, 43.68202f, 3.926991f },
    { -46.09722f, -830.2518f, 43.00029f, 2.75762f },
    { -46.44965f, -809.7448f, 42.93429f, 3.926991f },
    { -54.49479f, -826.5833f, 42.19642f, 3.926991f },
    { -37.77257f, -824.493f, 43.78171f, 3.926991f },
    { -106.7882f, -827.8351f, 30.3655f, 3.926991f },
    { -85.05209f, -808.5243f, 39.47224f, 3.926991f },
    { -108.5208f, -840.7136f, 17.11709f, 3.926991f },
    { -74.0f, -813.632f, 40.37197f, 3.926991f },
    { -101.724f, -815.1875f, 38.20302f, 3.926991f },
    { -109.6736f, -832.7049f, 20.99191f, 3.926991f },
    { -93.49653f, -809.6979f, 38.80095f, 3.926991f },
    { -92.09202f, -843.8507f, 21.32712f, 3.926991f },
    { -82.74479f, -853.8368f, 17.44633f, 3.926991f },
    { -83.51563f, -847.0851f, 18.62521f, 3.926991f },
    { -77.3316f, -848.7101f, 16.88625f, 3.926991f },
    { -47.97917f, -851.7882f, 18.46356f, 3.926991f },
    { -54.41667f, -846.2222f, 22.62641f, 3.926991f },
    { -46.15799f, -843.5104f, 23.03055f, 3.926991f },
    { -32.24479f, -844.8195f, 19.15213f, 3.926991f },
    { -28.87847f, -840.0226f, 19.30344f, 3.926991f },
    { -31.54861f, -830.5191f, 23.84564f, 3.926991f },
    { -53.39583f, -808.4184f, 42.27031f, 2.75762f },
    { -59.65799f, -786.8472f, 18.00813f, 3.926991f },
    { -51.8559f, -788.4774f, 18.27221f, 3.926991f },
    { -115.3142f, -827.2327f, 20.94427f, 3.926991f },
    { -116.1042f, -835.6597f, 17.07181f, 3.926991f },
    { -17.43924f, -821.8785f, 19.89213f, 3.926991f },
    { -22.3125f, -807.7292f, 19.61356f, 3.926991f },
    { -17.77431f, -814.7327f, 19.87694f, 3.926991f },
    { -116.9809f, -803.1337f, 17.05497f, 3.926991f },
    { -122.8872f, -816.658f, 17.01834f, 3.926991f },
    { -65.53993f, -768.6545f, 28.01228f, 3.926991f },
    { -123.3351f, -807.2153f, 16.98381f, 3.926991f }
};

template<class AI>
AI* GetDeadminesAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, DMScriptName);
}

template<class AI>
AI* GetDeadminesAI(GameObject* go)
{
    return GetInstanceAI<AI>(go, DMScriptName);
}

#endif
