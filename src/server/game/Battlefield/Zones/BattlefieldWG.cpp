/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

/// @todo Use spell victory/defeat in wg instead of RewardMarkOfHonor() && RewardHonor
/// @todo Add proper implement of achievement

#include "BattlefieldWG.h"
#include "Creature.h"
#include "GameObject.h"
#include "Player.h"
#include "Unit.h"
#include "World.h"
#include "WorldPacket.h"

uint32 const ClockWorldState[]    = { 3781, 4354 };
uint32 const WintergraspFaction[] = { FACTION_ALLIANCE_GENERIC_WG, FACTION_HORDE_GENERIC_WG, FACTION_FRIENDLY };

WintergraspGraveyardData const WintergraspGraveyards[] =
{
    { GRAVEYARDID_WORKSHOP_NE, 1329, GOSSIP_WINTERGRASP_GRAVEYARD_NE,       TEAM_NEUTRAL  },
    { GRAVEYARDID_WORKSHOP_NW, 1330, GOSSIP_WINTERGRASP_GRAVEYARD_NW,       TEAM_NEUTRAL  },
    { GRAVEYARDID_WORKSHOP_SE, 1333, GOSSIP_WINTERGRASP_GRAVEYARD_SE,       TEAM_NEUTRAL  },
    { GRAVEYARDID_WORKSHOP_SW, 1334, GOSSIP_WINTERGRASP_GRAVEYARD_SW,       TEAM_NEUTRAL  },
    { GRAVEYARDID_KEEP,        1285, GOSSIP_WINTERGRASP_GRAVEYARD_KEEP,     TEAM_NEUTRAL  },
    { GRAVEYARDID_HORDE,       1331, GOSSIP_WINTERGRASP_GRAVEYARD_HORDE,    TEAM_HORDE    },
    { GRAVEYARDID_ALLIANCE,    1332, GOSSIP_WINTERGRASP_GRAVEYARD_ALLIANCE, TEAM_ALLIANCE },
    { GRAVEYARDID_MAX,         0,    0,                                     TEAM_NEUTRAL  }
};

WintergraspBuildingSpawnData const WintergraspGameObjectBuilding[] =
{
    // Entry                        WS    Type
    { 190219,                       3749, OBJECTTYPE_WALL       },
    { 190220,                       3750, OBJECTTYPE_WALL       },
    { 191795,                       3764, OBJECTTYPE_WALL       },
    { 191796,                       3772, OBJECTTYPE_WALL       },
    { 191799,                       3762, OBJECTTYPE_WALL       },
    { 191800,                       3766, OBJECTTYPE_WALL       },
    { 191801,                       3770, OBJECTTYPE_WALL       },
    { 191802,                       3751, OBJECTTYPE_WALL       },
    { 191803,                       3752, OBJECTTYPE_WALL       },
    { 191804,                       3767, OBJECTTYPE_WALL       },
    { 191806,                       3769, OBJECTTYPE_WALL       },
    { 191807,                       3759, OBJECTTYPE_WALL       },
    { 191808,                       3760, OBJECTTYPE_WALL       },
    { 191809,                       3761, OBJECTTYPE_WALL       },
    { 190369,                       3753, OBJECTTYPE_WALL       },
    { 190370,                       3758, OBJECTTYPE_WALL       },
    { 190371,                       3754, OBJECTTYPE_WALL       },
    { 190372,                       3757, OBJECTTYPE_WALL       },
    { 190374,                       3755, OBJECTTYPE_WALL       },
    { 190376,                       3756, OBJECTTYPE_WALL       },
    { 190221,                       3711, OBJECTTYPE_KEEP_TOWER }, // NW
    { 190373,                       3713, OBJECTTYPE_KEEP_TOWER }, // SW
    { 190377,                       3714, OBJECTTYPE_KEEP_TOWER }, // SE
    { 190378,                       3712, OBJECTTYPE_KEEP_TOWER }, // NE
    { 191797,                       3765, OBJECTTYPE_WALL       },
    { 191798,                       3771, OBJECTTYPE_WALL       },
    { 191805,                       3768, OBJECTTYPE_WALL       },
    { 190356,                       3704, OBJECTTYPE_TOWER      }, // W
    { 190357,                       3705, OBJECTTYPE_TOWER      }, // S
    { 190358,                       3706, OBJECTTYPE_TOWER      }, // E
    { GO_WINTERGRASP_FORTRESS_GATE, 3763, OBJECTTYPE_DOOR       },
    { GO_WINTERGRASP_VAULT_GATE,    3773, OBJECTTYPE_DOOR_LAST  },
    { 0,                            0,    OBJECTTYPE_MAX        }
};

WintergraspTowerInfo const TowerData[] =
{
    { TOWERID_FORTRESS_NW,   { TEXT_WINTERGRASP_NW_KEEPTOWER_DAMAGE,   TEXT_WINTERGRASP_NW_KEEPTOWER_DESTROY   } },
    { TOWERID_FORTRESS_SW,   { TEXT_WINTERGRASP_SW_KEEPTOWER_DAMAGE,   TEXT_WINTERGRASP_SW_KEEPTOWER_DESTROY   } },
    { TOWERID_FORTRESS_SE,   { TEXT_WINTERGRASP_SE_KEEPTOWER_DAMAGE,   TEXT_WINTERGRASP_SE_KEEPTOWER_DESTROY   } },
    { TOWERID_FORTRESS_NE,   { TEXT_WINTERGRASP_NE_KEEPTOWER_DAMAGE,   TEXT_WINTERGRASP_NE_KEEPTOWER_DESTROY   } },
    { TOWERID_SHADOWSIGHT,   { TEXT_WINTERGRASP_WESTERN_TOWER_DAMAGE,  TEXT_WINTERGRASP_WESTERN_TOWER_DESTROY  } },
    { TOWERID_WINTER_S_EDGE, { TEXT_WINTERGRASP_SOUTHERN_TOWER_DAMAGE, TEXT_WINTERGRASP_SOUTHERN_TOWER_DESTROY } },
    { TOWERID_FLAMEWATCH,    { TEXT_WINTERGRASP_EASTERN_TOWER_DAMAGE,  TEXT_WINTERGRASP_EASTERN_TOWER_DESTROY  } },
    { TOWERID_MAX,           { 0,                                      0                                       } }
};

WintergraspTowerData const AttackTowers[] =
{
    // West tower
    {
        190356,
        {
            { { 4559.113f, 3606.216f, 419.9992f, 4.799657f }, { 0.f, 0.f, -0.67558960f, 0.73727790f }, 192488, 192501 },  // Flag on tower
            { { 4539.420f, 3622.490f, 420.0342f, 3.211419f }, { 0.f, 0.f, -0.99939060f, 0.03490613f }, 192488, 192501 },  // Flag on tower
            { { 4555.258f, 3641.648f, 419.9740f, 1.675514f }, { 0.f, 0.f,  0.74314400f, 0.66913150f }, 192488, 192501 },  // Flag on tower
            { { 4574.872f, 3625.911f, 420.0792f, 0.087266f }, { 0.f, 0.f,  0.04361916f, 0.99904820f }, 192488, 192501 },  // Flag on tower
            { { 4433.899f, 3534.142f, 360.2750f, 4.433136f }, { 0.f, 0.f, -0.79863550f, 0.60181500f }, 192269, 192278 },  // Flag near workshop
            { { 4572.933f, 3475.519f, 363.0090f, 1.422443f }, { 0.f, 0.f,  0.65275960f, 0.75756520f }, 192269, 192277 }   // Flag near bridge
        },
        {
            { { 4510.57f, 1948.08f, 434.761f, 6.13912f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4433.22f, 1994.53f, 434.586f, 2.44382f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4404.04f, 1949.77f, 433.775f, 3.14283f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4500.64f, 2005.19f, 427.573f, 1.65448f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4471.65f, 2019.57f, 425.178f, 0.916209f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4488.25f, 2046.35f, 416.735f, 0.990828f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4508.41f, 2035.35f, 418.608f, 1.19503f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4501.44f, 2066.22f, 406.414f, 1.24216f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4523.4f,  2061.29f, 406.226f, 1.24216f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4531.41f, 2096.84f, 391.186f, 1.49741f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4509.33f, 2100.84f, 390.311f, 1.37567f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4516.64f, 2131.67f, 383.624f, 1.089f    }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4535.16f, 2125.98f, 382.783f, 1.10785f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4555.55f, 2162.13f, 372.917f, 1.30577f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4535.7f,  2169.13f, 371.985f, 1.18796f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE }
        }
    },
    // South Tower
    {
        190357,
        {
            { { 4416.004f, 2822.666f, 429.8512f, 6.2657330f }, { 0.f, 0.f, -0.00872612f, 0.99996190f }, 192488, 192501 },  // Flag on tower
            { { 4398.819f, 2804.698f, 429.7920f, 4.6949370f }, { 0.f, 0.f, -0.71325020f, 0.70090960f }, 192488, 192501 },  // Flag on tower
            { { 4387.622f, 2719.566f, 389.9351f, 4.7385700f }, { 0.f, 0.f, -0.69779010f, 0.71630230f }, 192366, 192414 },  // Flag near tower
            { { 4464.124f, 2855.453f, 406.1106f, 0.8290324f }, { 0.f, 0.f,  0.40274720f, 0.91531130f }, 192366, 192429 },  // Flag near tower
            { { 4526.457f, 2810.181f, 391.1997f, 3.2899610f }, { 0.f, 0.f, -0.99724960f, 0.07411628f }, 192269, 192278 }   // Flag near bridge
        },
        {
            { { 4469.36f, 2867.61f, 389.342f, 0.642708f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4448.84f, 2891.15f, 389.494f, 1.16814f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4480.92f, 2778.26f, 389.505f, 5.82398f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4521.55f, 2848.17f, 390.813f, 0.121998f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4530.18f, 2814.16f, 389.989f, 0.121998f  }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4482.16f, 2636.3f,  357.839f, 4.77128f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4457.46f, 2646.16f, 360.941f, 4.68488f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4457.16f, 2687.71f, 372.985f, 4.82704f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4476.67f, 2693.18f, 374.875f, 4.75322f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4464.6f,  2746.26f, 390.654f, 5.0501f    }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4427.49f, 2743.73f, 396.151f, 5.25448f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4384.45f, 2865.71f, 404.325f, 1.18691f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4422.27f, 2869.65f, 407.265f, 1.60945f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4415.12f, 2904.67f, 390.771f, 1.39661f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4395.16f, 2903.49f, 391.131f, 1.39661f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4475.34f, 2837.01f, 395.537f, 0.0881266f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4478.68f, 2806.64f, 395.737f, 0.0881266f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4401.22f, 2965.59f, 370.412f, 1.46648f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4420.83f, 2963.3f,  372.254f, 1.63927f   }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE }
        }
    },
    // East Tower
    {
        190358,
        {
            { { 4466.793f, 1960.418f, 459.1437f, 1.151916f }, { 0.f, 0.f,  0.5446386f, 0.8386708f }, 192488, 192501 },     // Flag on tower
            { { 4475.351f, 1937.031f, 459.0702f, 5.846854f }, { 0.f, 0.f, -0.2164392f, 0.9762961f }, 192488, 192501 },     // Flag on tower
            { { 4451.758f, 1928.104f, 459.0759f, 4.276057f }, { 0.f, 0.f, -0.8433914f, 0.5372996f }, 192488, 192501 },     // Flag on tower
            { { 4442.987f, 1951.898f, 459.0930f, 2.740162f }, { 0.f, 0.f,  0.9799242f, 0.1993704f }, 192488, 192501 }      // Flag on tower
        },
        {
            { { 4605.41f, 3648.66f, 398.244f, 4.08579f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4616.86f, 3616.35f, 401.305f, 3.55564f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4462.8f,  3614.09f, 380.907f, 3.88943f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4486.71f, 3595.8f,  385.362f, 3.65774f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4451.71f, 3572.05f, 368.735f, 3.92477f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4434.69f, 3582.99f, 369.727f, 4.18552f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4414.4f,  3545.98f, 360.552f, 4.38186f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4433.56f, 3541.18f, 361.739f, 4.15803f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4548.55f, 3556.25f, 386.659f, 4.74314f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4576.25f, 3555.14f, 387.997f, 4.51537f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4566.49f, 3514.23f, 372.791f, 4.63711f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4545.33f, 3515.82f, 374.606f, 4.64104f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4544.88f, 3469.28f, 362.493f, 5.08872f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE },
            { { 4564.7f,  3477.1f,  363.403f, 5.01804f }, NPC_WINTERGRASP_GUARD_HORDE, NPC_WINTERGRASP_GUARD_ALLIANCE }
        }
    }
};

WintergraspTowerCannonData const TowerCannon[] =
{
    {
        190221,
        {
            // no cannons at bottom
        },
        {
            { 5255.88f, 3047.63f, 438.499f, 3.13677f },
            { 5280.90f, 3071.32f, 438.499f, 1.62879f }
        }
    },
    {
        190373,
        {
            // no cannons at bottom
        },
        {
            { 5138.59f, 2935.16f, 439.845f, 3.11723f },
            { 5163.06f, 2959.52f, 439.846f, 1.47258f }
        }
    },
    {
        190377,
        {
            // no cannons at bottom
        },
        {
            { 5163.84f, 2723.74f, 439.844f, 4.70659f },
            { 5139.69f, 2747.40f, 439.844f, 3.17221f }
        }
    },
    {
        190378,
        {
            // no cannons at bottom
        },
        {
            { 5278.21f, 2607.23f, 439.755f, 4.71944f },
            { 5255.01f, 2631.98f, 439.755f, 3.15257f }
        }
    },
    {
        190356,
        {
            { 4537.380371f, 3599.531738f, 402.886993f, 3.998462f },
            { 4581.497559f, 3604.087158f, 402.886963f, 5.651723f },
            { 4575.644f,    3646.644f,    402.9699f,   0.942479f },
            { 4534.005f,    3641.883f,    402.9699f,   2.670354f }
        },
        {
            { 4581.895996f, 3626.438477f, 426.539062f, 0.117806f },
            { 4554.502f,    3649.916f,    426.6221f,   1.675516f },
            { 4531.28f,     3621.086f,    426.6221f,   3.333579f },
            { 4559.906f,    3598.084f,    426.6221f,   4.869469f }
        }
    },
    {
        190357,
        {
            { 4421.640137f, 2799.935791f, 412.630920f, 5.459298f },
            { 4420.263184f, 2845.340332f, 412.630951f, 0.742197f },
            { 4377.919f,    2801.679f,    412.7141f,   3.979351f },
            { 4377.097f,    2842.61f,     412.7141f,   2.460914f }
        },
        {
            { 4423.430664f, 2822.762939f, 436.283142f, 6.223487f },
            { 4397.825684f, 2847.629639f, 436.283325f, 1.579430f },
            { 4398.814941f, 2797.266357f, 436.283051f, 4.703747f },
            { 4372.188f,    2822.089f,    436.3663f,   3.263766f }
        }
    },
    {
        190358,
        {
            { 4448.138184f, 1974.998779f, 441.995911f, 1.967238f },
            { 4486.326f,    1954.655f,    441.995f,    4.885527f },
            { 4431.831f,    1934.137f,    442.0783f,   3.647738f },
            { 4469.432f,    1917.064f,    442.0783f,   5.078908f }
        },
        {
            { 4469.448242f, 1966.623779f, 465.647217f, 1.153573f },
            { 4481.996582f, 1933.658325f, 465.647186f, 5.873029f },
            { 4448.705f,    1921.112f,    465.7305f,   4.39823f  },
            { 4436.208f,    1954.791f,    465.7305f,   2.740167f }
        }
    }
};

WintergraspWorkshopInfo const WorkshopData[] =
{
    { WORKSHOPID_NE,        WORLDSTATE_WINTERGRASP_WORKSHOP_NE,     { TEXT_WINTERGRASP_SUNKEN_RING_CAPTURE_ALLIANCE,   TEXT_WINTERGRASP_SUNKEN_RING_ATTACK_ALLIANCE,   TEXT_WINTERGRASP_SUNKEN_RING_CAPTURE_HORDE,   TEXT_WINTERGRASP_SUNKEN_RING_ATTACK_HORDE   } },
    { WORKSHOPID_NW,        WORLDSTATE_WINTERGRASP_WORKSHOP_NW,     { TEXT_WINTERGRASP_BROKEN_TEMPLE_CAPTURE_ALLIANCE, TEXT_WINTERGRASP_BROKEN_TEMPLE_ATTACK_ALLIANCE, TEXT_WINTERGRASP_BROKEN_TEMPLE_CAPTURE_HORDE, TEXT_WINTERGRASP_BROKEN_TEMPLE_ATTACK_HORDE } },
    { WORKSHOPID_SE,        WORLDSTATE_WINTERGRASP_WORKSHOP_SE,     { TEXT_WINTERGRASP_EASTSPARK_CAPTURE_ALLIANCE,     TEXT_WINTERGRASP_EASTSPARK_ATTACK_ALLIANCE,     TEXT_WINTERGRASP_EASTSPARK_CAPTURE_HORDE,     TEXT_WINTERGRASP_EASTSPARK_ATTACK_HORDE     } },
    { WORKSHOPID_SW,        WORLDSTATE_WINTERGRASP_WORKSHOP_SW,     { TEXT_WINTERGRASP_WESTSPARK_CAPTURE_ALLIANCE,     TEXT_WINTERGRASP_WESTSPARK_ATTACK_ALLIANCE,     TEXT_WINTERGRASP_WESTSPARK_CAPTURE_HORDE,     TEXT_WINTERGRASP_WESTSPARK_ATTACK_HORDE     } },
    { WORKSHOPID_KEEP_WEST, WORLDSTATE_WINTERGRASP_WORKSHOP_KEEP_W, { 0,                                               0,                                              0,                                            0                                           } },
    { WORKSHOPID_KEEP_EAST, WORLDSTATE_WINTERGRASP_WORKSHOP_KEEP_E, { 0,                                               0,                                              0,                                            0                                           } },
    { WORKSHOPID_MAX,       0,                                      { 0,                                               0,                                              0,                                            0                                           } }
};

WorldLocation const LocationWintergraspHorde(571, 5025.857422f, 3674.628906f, 362.737122f, 4.135169f);
WorldLocation const LocationWintergraspAlliance(571, 5101.284f, 2186.564f, 373.549f, 3.812f);
WorldLocation const LocationWintergraspKeep(571, 5345.f, 2842.f, 410.f, 3.14f);

BattlefieldWintergrasp::~BattlefieldWintergrasp()
{
}

bool BattlefieldWintergrasp::SetupBattlefield()
{
    return false;
}

void BattlefieldWintergrasp::Update(uint32 diff)
{
}

void BattlefieldWintergrasp::OnBattleStart()
{
}

void BattlefieldWintergrasp::OnBattleEnd(bool endByTimer)
{
}

void BattlefieldWintergrasp::OnStartGrouping()
{
}

void BattlefieldWintergrasp::OnPlayerJoinWar(Player* player)
{
}

void BattlefieldWintergrasp::OnPlayerLeaveWar(Player* player)
{
}

void BattlefieldWintergrasp::OnPlayerLeaveZone(Player* player)
{
}

void BattlefieldWintergrasp::OnPlayerEnterZone(Player* player)
{
}

void BattlefieldWintergrasp::OnCreatureCreate(Creature* creature)
{
}

void BattlefieldWintergrasp::OnCreatureRemove(Creature* creature)
{
}

void BattlefieldWintergrasp::OnGameObjectCreate(GameObject* gameObject)
{
}

void BattlefieldWintergrasp::OnGameObjectRemove(GameObject* gameObject)
{
}

void BattlefieldWintergrasp::DoCompleteOrIncrementAchievement(uint32 achievement, Player* player, uint8 incrementNumber)
{
}

void BattlefieldWintergrasp::FillInitialWorldStates(WorldPacket& data)
{
}

void BattlefieldWintergrasp::SendInitWorldStatesToAll()
{
}

void BattlefieldWintergrasp::OnUnitDeath(Unit* unit)
{
}

void BattlefieldWintergrasp::HandleKill(Player* killer, Unit* victim)
{
}

void BattlefieldWintergrasp::ProcessEvent(WorldObject* object, uint32 eventId)
{
}

uint32 BattlefieldWintergrasp::GetData(uint32 data) const
{
    return uint32();
}

void BattlefieldWintergrasp::HandlePromotion(Player* killer, Unit* killed)
{
}

void BattlefieldWintergrasp::UpdateDamagedTowerCount(TeamId team)
{
}

void BattlefieldWintergrasp::UpdatedDestroyedTowerCount(TeamId team)
{
}

void BattlefieldWintergrasp::RemoveAurasFromPlayer(Player const* player)
{
}

void BattlefieldWintergrasp::SetRelicInteractible(bool allow)
{
}

void BattlefieldWintergrasp::UpdateVehicleCountWG()
{
}

void BattlefieldWintergrasp::UpdateCounterVehicle(bool initialize)
{
}

void BattlefieldWintergrasp::SendInitWorldStatesTo(Player const* player)
{
}

void BattlefieldWintergrasp::PromotePlayer(Player const* killer)
{
}

void BattlefieldWintergrasp::UpdateTenacity()
{
}

void BattlefieldWintergrasp::SendWarning(uint8 id, Player const* target)
{
}

void BattlefieldWintergrasp::SendSpellAreaUpdate(uint32 areaId)
{
}

WintergraspGraveyardId BattlefieldWintergrasp::GetSpiritGraveyardId(uint32 areaId) const
{
    return WintergraspGraveyardId();
}

WintergraspBuilding* BattlefieldWintergrasp::GetBuilding(uint32 entry) const
{
    return nullptr;
}

WintergraspBuilding* BattlefieldWintergrasp::GetBuilding(ObjectGuid guid) const
{
    return nullptr;
}

WintergraspWorkshop* BattlefieldWintergrasp::GetWorkshop(WintergraspWorkshopId id) const
{
    return nullptr;
}

WorldLocation BattlefieldWintergrasp::GetRandomWorldLocation(WorldLocation location) const
{
    return WorldLocation();
}

//*******************************************************
//******************* Graveyard *************************
//*******************************************************

WintergraspGraveyard::WintergraspGraveyard(BattlefieldWintergrasp* battlefield) : BattlefieldGraveyard(battlefield)
{
}

//*******************************************************
//******************* CapturePoint **********************
//*******************************************************

WintergraspCapturePoint::WintergraspCapturePoint(BattlefieldWintergrasp* battlefield, TeamId teamInControl) : BattlefieldCapturePoint(battlefield)
{
}

void WintergraspCapturePoint::ChangeTeam(TeamId oldteam)
{
}

//*******************************************************
//******************* Building **************************
//*******************************************************

WintergraspBuilding::WintergraspBuilding(BattlefieldWintergrasp* wintergrasp, WintergraspBuildingType type, uint32 entry, uint32 worldState)
{
}

void WintergraspBuilding::Initialize(GameObject const* gameObject)
{
}

void WintergraspBuilding::Rebuild()
{
}

void WintergraspBuilding::Damaged()
{
}

void WintergraspBuilding::Destroyed()
{
}

void WintergraspBuilding::CleanRelatedObject(ObjectGuid guid)
{
}

void WintergraspBuilding::UpdateCreatureAndGo()
{
}

void WintergraspBuilding::UpdateTurretAttack(bool disable)
{
}

void WintergraspBuilding::UpdateForNoBattle(bool initialize)
{
}

void WintergraspBuilding::FillInitialWorldStates(WorldPacket& data)
{
}

void WintergraspBuilding::Save()
{
}

//*******************************************************
//******************* Workshop **************************
//*******************************************************

WintergraspWorkshop::WintergraspWorkshop(BattlefieldWintergrasp* wintergrasp, uint8 type)
{
    ASSERT(wintergrasp && type < WORKSHOPID_MAX);

    _battlefield = wintergrasp;
    _capturePoint = nullptr;
    _state = OBJECTSTATE_NONE;
    _teamControl = TEAM_NEUTRAL;
    _info = &WorkshopData[type];
}

void WintergraspWorkshop::GiveControlTo(TeamId teamId, bool initialize)
{
    switch (teamId)
    {
        case TEAM_NEUTRAL:
            _battlefield->SendWarning(_teamControl == TEAM_ALLIANCE ? _info->TextIds.HordeAttack : _info->TextIds.AllianceAttack);
            break;
        case TEAM_ALLIANCE:
            // Updating worldstate
            _state = OBJECTSTATE_ALLIANCE_INTACT;
            _battlefield->SendUpdateWorldState(_info->WorldStateId, _state);

            // Warning message
            if (!initialize)
                _battlefield->SendWarning(_info->TextIds.AllianceCapture);

            if (_info->WorkshopId < WORKSHOPID_KEEP_WEST)
                if (BattlefieldGraveyard* graveyard = _battlefield->GetGraveyard(_info->WorkshopId))
                    graveyard->GiveControlTo(TEAM_ALLIANCE);

            _teamControl = teamId;
            break;
        case TEAM_HORDE:
            // Update worldstate
            _state = OBJECTSTATE_HORDE_INTACT;
            _battlefield->SendUpdateWorldState(_info->WorldStateId, _state);

            // Warning message
            if (!initialize)
                _battlefield->SendWarning(_info->TextIds.HordeCapture);

            if (_info->WorkshopId < WORKSHOPID_KEEP_WEST)
                if (BattlefieldGraveyard* graveyard = _battlefield->GetGraveyard(_info->WorkshopId))
                    graveyard->GiveControlTo(TEAM_HORDE);

            _teamControl = teamId;
            break;
        default:
            break;
    }

    if (!initialize)
    {
        _battlefield->UpdateCounterVehicle(false);

        uint32 areaId = 0;
        switch (_info->WorkshopId)
        {
            case WORKSHOPID_NE:
                areaId = AREA_THE_SUNKEN_RING;
                break;
            case WORKSHOPID_NW:
                areaId = AREA_THE_BROKEN_TEMPLE;
                break;
            case WORKSHOPID_SW:
                areaId = AREA_WESTPARK_WORKSHOP;
                break;
            case WORKSHOPID_SE:
                areaId = AREA_EASTPARK_WORKSHOP;
                break;
            default:
                break;
        }
        if (areaId != 0)
            _battlefield->SendSpellAreaUpdate(areaId);
    }
}

void WintergraspWorkshop::UpdateForBattle()
{
    if (_info->WorkshopId < WORKSHOPID_KEEP_WEST)
    {
        GiveControlTo(_battlefield->GetAttackerTeam(), true);
        _capturePoint->SetTeam(_battlefield->GetAttackerTeam());
    }
    else
        GiveControlTo(_battlefield->GetDefenderTeam(), true);
}

void WintergraspWorkshop::UpdateForNoBattle()
{
    if (_info->WorkshopId < WORKSHOPID_KEEP_WEST)
        _capturePoint->SetTeam(_battlefield->GetDefenderTeam());

    GiveControlTo(_battlefield->GetDefenderTeam(), true);
}

void WintergraspWorkshop::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(_info->WorldStateId) << uint32(_state);
}

void WintergraspWorkshop::Save()
{
    sWorld->setWorldState(_info->WorldStateId, _state);
}

WintergraspWorkshopId WintergraspWorkshop::GetId() const
{
    return _info->WorkshopId;
}
