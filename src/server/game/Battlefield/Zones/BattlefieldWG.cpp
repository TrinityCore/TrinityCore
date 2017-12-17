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
#include "AchievementMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "Log.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Random.h"
#include "SpellAuras.h"
#include "TemporarySummon.h"
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
    for (WintergraspWorkshop* workshop : _workshopSet)
        delete workshop;

    for (WintergraspBuilding* building : _buildingSet)
        delete building;
}

bool BattlefieldWintergrasp::SetupBattlefield()
{
    // battlefield
    _battleId = BATTLEFIELD_BATTLEID_WINTERGRASP;
    _zoneId = ZONEID_WINTERGRASP;
    _mapId = MAPID_WINTERGRASP;
    _map = sMapMgr->FindMap(_mapId, 0);
    _maxPlayerCount = sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MAX);
    _enabled = sWorld->getBoolConfig(CONFIG_WINTERGRASP_ENABLE);
    _minPlayerLevel = sWorld->getIntConfig(CONFIG_WINTERGRASP_PLR_MIN_LVL);
    _battleTime = sWorld->getIntConfig(CONFIG_WINTERGRASP_BATTLETIME) * MINUTE * IN_MILLISECONDS;
    _noWarBattleTime = sWorld->getIntConfig(CONFIG_WINTERGRASP_NOBATTLETIME) * MINUTE * IN_MILLISECONDS;
    _restartAfterCrash = sWorld->getIntConfig(CONFIG_WINTERGRASP_RESTART_AFTER_CRASH) * MINUTE * IN_MILLISECONDS;
    _acceptInviteTime = 20;
    _startGroupingTime = 15 * MINUTE * IN_MILLISECONDS;
    _startGrouping = false;
    _data.resize(DATA_WINTERGRASP_MAX);

    if ((sWorld->getWorldState(WORLDSTATE_WINTERGRASP_ACTIVE) == 0) && (sWorld->getWorldState(WORLDSTATE_WINTERGRASP_DEFENDER) == 0) && (sWorld->getWorldState(ClockWorldState[0]) == 0))
    {
        sWorld->setWorldState(WORLDSTATE_WINTERGRASP_ACTIVE, uint64(false));
        sWorld->setWorldState(WORLDSTATE_WINTERGRASP_DEFENDER, uint64(urand(0, 1)));
        sWorld->setWorldState(ClockWorldState[0], uint64(_noWarBattleTime));
    }

    _defenderTeam = TeamId(sWorld->getWorldState(WORLDSTATE_WINTERGRASP_DEFENDER));

    _timer.Reset(sWorld->getWorldState(ClockWorldState[0]));
    if (sWorld->getWorldState(WORLDSTATE_WINTERGRASP_ACTIVE) != 0)
        _timer.Reset(_restartAfterCrash);

    SetData(DATA_WINTERGRASP_WON_ALLIANCE, uint32(sWorld->getWorldState(WORLDSTATE_WINTERGRASP_ATTACKED_ALLIANCE)));
    SetData(DATA_WINTERGRASP_DEF_ALLIANCE, uint32(sWorld->getWorldState(WORLDSTATE_WINTERGRASP_DEFENDED_ALLIANCE)));
    SetData(DATA_WINTERGRASP_WON_HORDE, uint32(sWorld->getWorldState(WORLDSTATE_WINTERGRASP_ATTACKED_HORDE)));
    SetData(DATA_WINTERGRASP_DEF_HORDE, uint32(sWorld->getWorldState(WORLDSTATE_WINTERGRASP_DEFENDED_HORDE)));

    SetGraveyardNumber(GRAVEYARDID_MAX);

    // battlefieldwintergrasp
    _saveTimer.Reset(60000);
    _tenacityTeam = TEAM_NEUTRAL;
    _tenacityStack = 0;
    _relicInteractible = false;

    for (uint8 itr = 0; WintergraspGraveyards[itr].Id < GRAVEYARDID_MAX; ++itr)
    {
        WintergraspGraveyard* graveyard = new WintergraspGraveyard(this);

        // when between games, the graveyard is controlled by the defending team
        if (WintergraspGraveyards[itr].StartControl == TEAM_NEUTRAL)
            graveyard->Initialize(_defenderTeam, WintergraspGraveyards[itr].Entry);
        else
            graveyard->Initialize(WintergraspGraveyards[itr].StartControl, WintergraspGraveyards[itr].Entry);

        graveyard->SetTextId(WintergraspGraveyards[itr].TextId);
        _graveyardList[itr] = graveyard;

        // this graveyard needs special handling since its not located in any special area id
        if (WintergraspGraveyards[itr].Id == GRAVEYARDID_WORKSHOP_NW)
            graveyard->SetIsSpellAreaForced(true);
    }

    // create all WintergraspWorkshop & WintergraspCapturePoint objects
    for (uint8 itr = 0; itr < WORKSHOPID_MAX; ++itr)
    {
        WintergraspWorkshop* workshop = new WintergraspWorkshop(this, itr);
        _workshopSet.insert(workshop);

        if (itr < WORKSHOPID_KEEP_WEST)
        {
            WintergraspCapturePoint* capturePoint = new WintergraspCapturePoint(this, GetDefenderTeam());
            capturePoint->LinkToWorkshop(workshop);
            workshop->LinkCapturePoint(capturePoint);
            AddCapturePoint(capturePoint);
        }

        workshop->UpdateForNoBattle();
        workshop->Save();
    }

    // create all WintergraspBuilding objects
    for (uint8 itr = 0; WintergraspGameObjectBuilding[itr].Entry != 0; ++itr)
    {
        WintergraspBuilding* building = new WintergraspBuilding(this, WintergraspGameObjectBuilding[itr].Type, WintergraspGameObjectBuilding[itr].Entry, WintergraspGameObjectBuilding[itr].WorldState);
        _buildingSet.insert(building);
        building->UpdateForNoBattle(true);
        building->Save();
    }

    UpdateVehicleCounter(true);

    return true;
}

void BattlefieldWintergrasp::Update(uint32 diff)
{
    Battlefield::Update(diff);
    _saveTimer.Update(diff);
    if (_saveTimer.Passed())
    {
        sWorld->setWorldState(WORLDSTATE_WINTERGRASP_ACTIVE, IsWarTime() ? 1 : 0);
        sWorld->setWorldState(WORLDSTATE_WINTERGRASP_DEFENDER, _defenderTeam);
        sWorld->setWorldState(ClockWorldState[0], GetTimer());
        sWorld->setWorldState(WORLDSTATE_WINTERGRASP_ATTACKED_ALLIANCE, GetData(DATA_WINTERGRASP_WON_ALLIANCE));
        sWorld->setWorldState(WORLDSTATE_WINTERGRASP_DEFENDED_ALLIANCE, GetData(DATA_WINTERGRASP_DEF_ALLIANCE));
        sWorld->setWorldState(WORLDSTATE_WINTERGRASP_ATTACKED_HORDE, GetData(DATA_WINTERGRASP_WON_HORDE));
        sWorld->setWorldState(WORLDSTATE_WINTERGRASP_DEFENDED_HORDE, GetData(DATA_WINTERGRASP_DEF_HORDE));
        _saveTimer.Reset(60 * IN_MILLISECONDS);
    }
}

void BattlefieldWintergrasp::OnBattleStart()
{
    _tenacityTeam = TEAM_NEUTRAL;
    _tenacityStack = 0;
    _relicInteractible = false;

    if (GameObject* relic = GetRelic())
    {
        relic->SetFaction(WintergraspFaction[GetAttackerTeam()]);
        relic->m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GM, SEC_PLAYER);
        relic->UpdateObjectVisibility(true);
    }

    // spawn keep cannons
    SpawnGroupSpawn(SPAWNGROUP_WINTERGRASP_KEEP_CANNONS);

    // update keep teleports faction
    for (ObjectGuid teleportGuid : _teleporterList)
    {
        if (GameObject* go = GetGameObject(teleportGuid))
            go->SetFaction(WintergraspFaction[GetDefenderTeam()]);
    }

    // rebuild
    for (WintergraspBuilding* building : _buildingSet)
        building->Rebuild();

    SetData(DATA_WINTERGRASP_BROKEN_TOWER_ATTACK, 0);
    SetData(DATA_WINTERGRASP_BROKEN_TOWER_DEFENCE, 0);
    SetData(DATA_WINTERGRASP_DAMAGED_TOWER_ATTACK, 0);
    SetData(DATA_WINTERGRASP_DAMAGED_TOWER_DEFENCE, 0);

    // update graveyard (in no war time all graveyard is to deffender, in war time, depend of base)
    for (WintergraspWorkshop* workshop : _workshopSet)
        workshop->UpdateForBattle();

    SendInitWorldStatesToAll();

    // initialize vehicle counter
    UpdateVehicleCounter(true);

    // send start warning to all players
    SendWarning(TEXT_WINTERGRASP_START_BATTLE);
}

void BattlefieldWintergrasp::OnBattleEnd(bool endByTimer)
{
    _tenacityTeam = TEAM_NEUTRAL;
    _tenacityStack = 0;
    _relicInteractible = false;

    if (GameObject* relic = GetRelic())
    {
        relic->SetFaction(WintergraspFaction[GetDefenderTeam()]);
        relic->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE | GO_FLAG_NOT_SELECTABLE);
        relic->m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GM, SEC_GAMEMASTER);
        relic->UpdateObjectVisibility(true);
    }

    // successful defense
    if (endByTimer)
        UpdateData(GetDefenderTeam() == TEAM_HORDE ? DATA_WINTERGRASP_DEF_HORDE : DATA_WINTERGRASP_DEF_ALLIANCE, 1);
    else // successful attack (note that teams have already been swapped, so defender team is the one who won)
        UpdateData(GetDefenderTeam() == TEAM_HORDE ? DATA_WINTERGRASP_WON_HORDE : DATA_WINTERGRASP_WON_ALLIANCE, 1);

    // despawn keep cannons
    SpawnGroupDespawn(SPAWNGROUP_WINTERGRASP_KEEP_CANNONS);

    // update keep teleports faction
    for (ObjectGuid teleportGuid : _teleporterList)
    {
        if (GameObject* go = GetGameObject(teleportGuid))
            go->SetFaction(WintergraspFaction[GetDefenderTeam()]);
    }

    if (BattlefieldGraveyard* graveyard = GetGraveyard(GRAVEYARDID_KEEP))
        graveyard->GiveControlTo(GetDefenderTeam());

    // saving data
    for (WintergraspBuilding* building : _buildingSet)
    {
        building->UpdateForNoBattle();
        building->Save();
    }

    for (WintergraspWorkshop* workshop : _workshopSet)
    {
        workshop->UpdateForNoBattle();
        workshop->Save();
    }

    for (uint8 team = 0; team < 2; ++team)
    {
        for (ObjectGuid guid : _playersInWar[team])
        {
            if (Player* player = ObjectAccessor::FindPlayer(guid))
            {
                if (!player->IsAlive())
                {
                    player->ResurrectPlayer(1.0f);
                    player->SpawnCorpseBones();
                }

                RemoveAurasFromPlayer(player);

                if (team == GetDefenderTeam())
                {
                    // award achievement for succeeding in Wintergrasp in 10 minutes or less
                    if (!endByTimer && GetTimer() >= 20 * MINUTE * IN_MILLISECONDS)
                        DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WIN_WG_TIMER_10, player);

                    // complete victory quests
                    player->AreaExploredOrEventHappens(QUEST_WINTERGRASP_VICTORY_ALLIANCE);
                    player->AreaExploredOrEventHappens(QUEST_WINTERGRASP_VICTORY_HORDE);

                    player->CastSpell(player, SPELL_ESSENCE_OF_WINTERGRASP, true);
                    player->CastSpell(player, SPELL_VICTORY_REWARD, true);
                }
                else
                    player->CastSpell(player, SPELL_DEFEAT_REWARD, true);
            }
        }

        _playersInWar[team].clear();

        for (ObjectGuid guid : _vehicleSet[team])
        {
            if (Creature* creature = GetCreature(guid))
                if (creature->IsVehicle())
                    creature->DespawnOrUnsummon();
        }
    }

    if (!endByTimer)
    {
        for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
        {
            for (auto itr = _players[team].begin(); itr != _players[team].end(); ++itr)
            {
                if (Player* player = ObjectAccessor::FindPlayer(*itr))
                {
                    player->RemoveAurasDueToSpell(_defenderTeam == TEAM_ALLIANCE ? SPELL_HORDE_CONTROL_PHASE_SHIFT : SPELL_ALLIANCE_CONTROL_PHASE_SHIFT, player->GetGUID());
                    player->AddAura(_defenderTeam == TEAM_HORDE ? SPELL_HORDE_CONTROL_PHASE_SHIFT : SPELL_ALLIANCE_CONTROL_PHASE_SHIFT, player);
                }
            }
        }
    }

    if (!endByTimer) // win
        SendWarning(GetDefenderTeam() == TEAM_ALLIANCE ? TEXT_WINTERGRASP_FORTRESS_CAPTURE_ALLIANCE : TEXT_WINTERGRASP_FORTRESS_CAPTURE_HORDE);
    else // defend
        SendWarning(GetDefenderTeam() == TEAM_ALLIANCE ? TEXT_WINTERGRASP_FORTRESS_DEFEND_ALLIANCE : TEXT_WINTERGRASP_FORTRESS_DEFEND_HORDE);
}

void BattlefieldWintergrasp::OnStartGrouping()
{
    SendWarning(TEXT_WINTERGRASP_START_GROUPING);
}

void BattlefieldWintergrasp::OnPlayerJoinWar(Player* player)
{
    RemoveAurasFromPlayer(player);

    player->CastSpell(player, SPELL_RECRUIT, true);

    WorldLocation destination;
    if (player->GetTeamId() == GetDefenderTeam())
        destination = LocationWintergraspKeep;
    else
    {
        if (player->GetTeamId() == TEAM_HORDE)
            destination = LocationWintergraspHorde;
        else
            destination = LocationWintergraspAlliance;
    }
    Position randomize = destination.GetPosition();
    player->MovePosition(randomize, frand(0.f, 5.f), frand(0.f, 2.f * float(M_PI)));
    destination.Relocate(randomize);
    player->TeleportTo(destination);

    UpdateTenacity();

    if (player->GetTeamId() == GetAttackerTeam())
    {
        if (GetData(DATA_WINTERGRASP_BROKEN_TOWER_ATTACK) < 3)
            player->SetAuraStack(SPELL_TOWER_CONTROL, player, 3 - GetData(DATA_WINTERGRASP_BROKEN_TOWER_ATTACK));
    }
    else
    {
        if (GetData(DATA_WINTERGRASP_BROKEN_TOWER_ATTACK) > 0)
            player->SetAuraStack(SPELL_TOWER_CONTROL, player, GetData(DATA_WINTERGRASP_BROKEN_TOWER_ATTACK));
    }
    SendInitWorldStatesTo(player);
}

void BattlefieldWintergrasp::OnPlayerLeaveWar(Player* player)
{
    // remove all aura from WG /// @todo false we can go out of this zone on retail and keep Rank buff, remove on end of WG
    RemoveAurasFromPlayer(player);
    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROL_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROL_PHASE_SHIFT);

    UpdateTenacity();
}

void BattlefieldWintergrasp::OnPlayerLeaveZone(Player* player)
{
    if (!IsWarTime())
        RemoveAurasFromPlayer(player);

    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROLS_FACTORY_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_HORDE_CONTROL_PHASE_SHIFT);
    player->RemoveAurasDueToSpell(SPELL_ALLIANCE_CONTROL_PHASE_SHIFT);
}

void BattlefieldWintergrasp::OnPlayerEnterZone(Player* player)
{
    player->AddAura(_defenderTeam == TEAM_HORDE ? SPELL_HORDE_CONTROL_PHASE_SHIFT : SPELL_ALLIANCE_CONTROL_PHASE_SHIFT, player);

    if (IsEnabled())
    {
        if (!IsWarTime())
            RemoveAurasFromPlayer(player);

        // send worldstate to player
        SendInitWorldStatesTo(player);
    }
}

void BattlefieldWintergrasp::OnCreatureCreate(Creature* creature)
{
    switch (creature->GetEntry())
    {
        case NPC_WINTERGRASP_STALKER:
            _stalkerGUID = creature->GetGUID();
            break;
        case NPC_WINTERGRASP_TOWER_CANNON:
            if (creature->GetSpawnGroupId() == SPAWNGROUP_WINTERGRASP_KEEP_CANNONS)
            {
                _keepCannonList.insert(creature->GetGUID());
                creature->SetFaction(WintergraspFaction[GetDefenderTeam()]);
            }
            break;
        case NPC_DWARVEN_SPIRIT_GUIDE:
        case NPC_TAUNKA_SPIRIT_GUIDE:
        {
            TeamId teamId = (creature->GetEntry() == NPC_DWARVEN_SPIRIT_GUIDE ? TEAM_ALLIANCE : TEAM_HORDE);
            uint8 graveyardId = 0;
            switch (creature->GetSpawnId())
            {
                case 88315: // Horde base spirit
                    graveyardId = GRAVEYARDID_HORDE;
                    break;
                case 88321: // Alliance base spirit
                    graveyardId = GRAVEYARDID_ALLIANCE;
                    break;
                case 88319: // Broken Temple graveyard areaId != Broken Temple workshop areaId
                case 88313:
                    graveyardId = GRAVEYARDID_WORKSHOP_NW;
                    break;
                default:
                    graveyardId = GetSpiritGraveyardId(creature->GetAreaId());
                    break;
            }
            if (BattlefieldGraveyard* graveyard = _graveyardList[graveyardId])
                graveyard->SetSpirit(creature, teamId);
            break;
        }
        case NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE:
        case NPC_WINTERGRASP_SIEGE_ENGINE_HORDE:
        case NPC_WINTERGRASP_CATAPULT:
        case NPC_WINTERGRASP_DEMOLISHER:
            if (IsWarTime())
            {
                TempSummon* summon = creature->ToTempSummon();
                if (!summon)
                    return;

                Player* summoner = ObjectAccessor::GetPlayer(*summon, summon->GetSummonerGUID());
                if (!summoner)
                {
                    creature->DespawnOrUnsummon();
                    return;
                }

                TeamId team = summoner->GetTeamId();
                if (team == TEAM_HORDE)
                {
                    if (GetData(DATA_WINTERGRASP_VEHICLE_HORDE) < GetData(DATA_WINTERGRASP_MAX_VEHICLE_HORDE))
                    {
                        creature->AddAura(SPELL_HORDE_FLAG, creature);
                        if (_tenacityTeam == TEAM_HORDE)
                            ApplyTenacity(creature, true);

                        _vehicleSet[team].insert(creature->GetGUID());
                        UpdateData(DATA_WINTERGRASP_VEHICLE_HORDE, 1);
                        UpdateVehicleCountWG();
                    }
                    else
                    {
                        creature->DespawnOrUnsummon();
                        return;
                    }
                }
                else
                {
                    if (GetData(DATA_WINTERGRASP_VEHICLE_ALLIANCE) < GetData(DATA_WINTERGRASP_MAX_VEHICLE_ALLIANCE))
                    {
                        creature->AddAura(SPELL_ALLIANCE_FLAG, creature);
                        if (_tenacityTeam == TEAM_ALLIANCE)
                            ApplyTenacity(creature, true);

                        _vehicleSet[team].insert(creature->GetGUID());
                        UpdateData(DATA_WINTERGRASP_VEHICLE_ALLIANCE, 1);
                        UpdateVehicleCountWG();
                    }
                    else
                    {
                        creature->DespawnOrUnsummon();
                        return;
                    }
                }

                creature->CastSpell(summoner, SPELL_GRAB_PASSENGER, true);
            }
            break;
        case NPC_WINTERGRASP_SIEGE_TURRET_HORDE:
        case NPC_WINTERGRASP_SIEGE_TURRET_ALLIANCE:
            if (IsWarTime())
            {
                if (creature->IsSummon())
                    if (Unit* creator = ObjectAccessor::GetUnit(*creature, creature->ToTempSummon()->GetSummonerGUID()))
                        creature->SetFaction(creator->GetFaction());
            }
            break;
        default:
            break;
    }
}

void BattlefieldWintergrasp::OnCreatureRemove(Creature* creature)
{
    _keepCannonList.erase(creature->GetGUID());

    for (WintergraspBuilding* building : _buildingSet)
        building->CleanRelatedObject(creature->GetGUID());

    if (IsWarTime())
    {
        switch (creature->GetEntry())
        {
            case NPC_WINTERGRASP_SIEGE_ENGINE_ALLIANCE:
            case NPC_WINTERGRASP_SIEGE_ENGINE_HORDE:
            case NPC_WINTERGRASP_CATAPULT:
            case NPC_WINTERGRASP_DEMOLISHER:
                for (uint32 team = 0; team < PVP_TEAMS_COUNT; ++team)
                {
                    if (_vehicleSet[team].erase(creature->GetGUID()) != 0 && IsWarTime())
                    {
                        UpdateData(team == TEAM_HORDE ? DATA_WINTERGRASP_VEHICLE_HORDE : DATA_WINTERGRASP_VEHICLE_ALLIANCE, -1);
                        UpdateVehicleCountWG();
                    }
                }
                break;
            default:
                break;
        }
    }
}

void BattlefieldWintergrasp::OnGameObjectCreate(GameObject* gameObject)
{
    switch (gameObject->GetEntry())
    {
        case GO_WINTERGRASP_TITAN_S_RELIC:
            _titansRelicGUID = gameObject->GetGUID();
            if (!IsEnabled() || !IsWarTime())
            {
                gameObject->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE | GO_FLAG_NOT_SELECTABLE);
                gameObject->m_serverSideVisibility.SetValue(SERVERSIDE_VISIBILITY_GM, SEC_GAMEMASTER);
            }
            else if (IsWarTime())
            {
                if (CanInteractWithRelic())
                {
                    gameObject->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE | GO_FLAG_NOT_SELECTABLE);
                    gameObject->SetFaction(WintergraspFaction[GetAttackerTeam()]);
                }
                else
                    gameObject->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE | GO_FLAG_NOT_SELECTABLE);
            }
            break;
        case GO_WINTERGRASP_KEEP_COLLISION_WALL:
            if (!IsEnabled())
            {
                gameObject->SetGoState(GO_STATE_ACTIVE);
                gameObject->SetLootState(GO_ACTIVATED);
            }
            else if (WintergraspBuilding* mainGate = GetBuilding(GO_WINTERGRASP_VAULT_GATE))
            {
                if (mainGate->IsDestroyed())
                {
                    gameObject->SetGoState(GO_STATE_ACTIVE);
                    gameObject->SetLootState(GO_ACTIVATED);
                }
            }
            break;
        case GO_WINTERGRASP_VAULT_GATE:
            if (!IsEnabled())
                gameObject->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
        case 190219:
        case 190220:
        case 191795:
        case 191796:
        case 191799:
        case 191800:
        case 191801:
        case 191802:
        case 191803:
        case 191804:
        case 191806:
        case 191807:
        case 191808:
        case 191809:
        case 190369:
        case 190370:
        case 190371:
        case 190372:
        case 190374:
        case 190376:
        case 191797:
        case 191798:
        case 191805:
        case 190221:
        case 190373:
        case 190377:
        case 190378:
        case 190356:
        case 190357:
        case 190358:
        case GO_WINTERGRASP_FORTRESS_GATE:
            if (WintergraspBuilding* building = GetBuilding(gameObject->GetEntry()))
            {
                building->Initialize(gameObject);
                TC_LOG_DEBUG("battlefield", "BattlefieldWintergrasp::OnGameObjectCreate: WintergraspBuilding (%u) initialized", gameObject->GetEntry());
            }
            break;
        case GO_WINTERGRASP_FACTORY_BANNER_NE:
            if (WintergraspWorkshop* workshop = GetWorkshop(WORKSHOPID_NE))
            {
                if (WintergraspCapturePoint* capturePoint = workshop->GetCapturePoint())
                    capturePoint->SetCapturePointData(gameObject);
            }
            break;
        case GO_WINTERGRASP_FACTORY_BANNER_NW:
            if (WintergraspWorkshop* workshop = GetWorkshop(WORKSHOPID_NW))
            {
                if (WintergraspCapturePoint* capturePoint = workshop->GetCapturePoint())
                    capturePoint->SetCapturePointData(gameObject);
            }
            break;
        case GO_WINTERGRASP_FACTORY_BANNER_SE:
            if (WintergraspWorkshop* workshop = GetWorkshop(WORKSHOPID_SE))
            {
                if (WintergraspCapturePoint* capturePoint = workshop->GetCapturePoint())
                    capturePoint->SetCapturePointData(gameObject);
            }
            break;
        case GO_WINTERGRASP_FACTORY_BANNER_SW:
            if (WintergraspWorkshop* workshop = GetWorkshop(WORKSHOPID_SW))
            {
                if (WintergraspCapturePoint* capturePoint = workshop->GetCapturePoint())
                    capturePoint->SetCapturePointData(gameObject);
            }
            break;
        case GO_WINTERGRASP_VEHICLE_TELEPORTER:
            gameObject->SetFaction(WintergraspFaction[GetDefenderTeam()]);
            _teleporterList.insert(gameObject->GetGUID());
            break;
        default:
            break;
    }
}

void BattlefieldWintergrasp::OnGameObjectRemove(GameObject* gameObject)
{
    for (WintergraspBuilding* building : _buildingSet)
        building->CleanRelatedObject(gameObject->GetGUID());

    _teleporterList.erase(gameObject->GetGUID());
}

void BattlefieldWintergrasp::OnUnitDeath(Unit* unit)
{
    if (unit->IsVehicle())
    {
        for (uint32 team = 0; team < PVP_TEAMS_COUNT; ++team)
        {
            if (_vehicleSet[team].erase(unit->GetGUID()) != 0 && IsWarTime())
            {
                UpdateData(team == TEAM_HORDE ? DATA_WINTERGRASP_VEHICLE_HORDE : DATA_WINTERGRASP_VEHICLE_ALLIANCE, -1);
                UpdateVehicleCountWG();
            }
        }
    }
}

void BattlefieldWintergrasp::DoCompleteOrIncrementAchievement(uint32 achievement, Player* player, uint8 /*incrementNumber = 1*/)
{
    AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(achievement);
    if (!achievementEntry || !player)
        return;

    switch (achievement)
    {
        case ACHIEVEMENTS_WIN_WG_100:
            // player->UpdateAchievementCriteria();
        default:
            player->CompletedAchievement(achievementEntry);
            break;
    }
}

void BattlefieldWintergrasp::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(WORLDSTATE_WINTERGRASP_DEFENDED_ALLIANCE) << uint32(GetData(DATA_WINTERGRASP_DEF_ALLIANCE));
    data << uint32(WORLDSTATE_WINTERGRASP_DEFENDED_HORDE) << uint32(GetData(DATA_WINTERGRASP_DEF_HORDE));
    data << uint32(WORLDSTATE_WINTERGRASP_ATTACKED_ALLIANCE) << uint32(GetData(DATA_WINTERGRASP_WON_ALLIANCE));
    data << uint32(WORLDSTATE_WINTERGRASP_ATTACKED_HORDE) << uint32(GetData(DATA_WINTERGRASP_WON_HORDE));
    data << uint32(WORLDSTATE_WINTERGRASP_ATTACKER) << uint32(GetAttackerTeam());
    data << uint32(WORLDSTATE_WINTERGRASP_DEFENDER) << uint32(GetDefenderTeam());
    data << uint32(WORLDSTATE_WINTERGRASP_ACTIVE) << uint32(IsWarTime() ? 0 : 1); // Note: cleanup these two, their names look awkward
    data << uint32(WORLDSTATE_WINTERGRASP_SHOW_WORLDSTATE) << uint32(IsWarTime() ? 1 : 0);

    for (uint32 i = 0; i < 2; ++i)
        data << ClockWorldState[i] << uint32(time(nullptr) + (GetTimer() / 1000));

    data << uint32(WORLDSTATE_WINTERGRASP_VEHICLE_HORDE) << uint32(GetData(DATA_WINTERGRASP_VEHICLE_HORDE));
    data << uint32(WORLDSTATE_WINTERGRASP_MAX_VEHICLE_HORDE) << uint32(GetData(DATA_WINTERGRASP_MAX_VEHICLE_HORDE));
    data << uint32(WORLDSTATE_WINTERGRASP_VEHICLE_ALLIANCE) << uint32(GetData(DATA_WINTERGRASP_VEHICLE_ALLIANCE));
    data << uint32(WORLDSTATE_WINTERGRASP_MAX_VEHICLE_ALLIANCE) << uint32(GetData(DATA_WINTERGRASP_MAX_VEHICLE_ALLIANCE));

    for (WintergraspBuilding* building : _buildingSet)
        building->FillInitialWorldStates(data);

    for (WintergraspWorkshop* workshop : _workshopSet)
        workshop->FillInitialWorldStates(data);
}

void BattlefieldWintergrasp::SendInitWorldStatesToAll()
{
    for (uint8 team = 0; team < PVP_TEAMS_COUNT; ++team)
    {
        for (auto itr = _players[team].begin(); itr != _players[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                SendInitWorldStatesTo(player);
    }
}

void BattlefieldWintergrasp::HandleKill(Player* killer, Unit* victim)
{
    if (killer == victim)
        return;

    if (victim->GetTypeId() == TYPEID_PLAYER)
    {
        // credit for quest Slay them all! & No Mercy for the Merciless
        killer->KilledMonsterCredit(victim->ToPlayer()->GetTeam() == ALLIANCE ? NPC_WINTERGRASP_PVP_KILL_ALLIANCE : NPC_WINTERGRASP_PVP_KILL_HORDE);

        for (ObjectGuid guid : _playersInWar[killer->GetTeamId()])
        {
            if (Player* player = ObjectAccessor::GetPlayer(*victim, guid))
                if (player->GetDistance2d(victim) < 40.f)
                    PromotePlayer(player);
        }

        // allow to Skin non-released corpse
        victim->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);
    }
}

void BattlefieldWintergrasp::ProcessEvent(WorldObject* object, uint32 eventId)
{
    if (!object)
        return;

    GameObject* gameObject = object->ToGameObject();
    if (!gameObject)
        return;

    // titan relic click
    if (gameObject->GetEntry() == GO_WINTERGRASP_TITAN_S_RELIC)
    {
        gameObject->SetRespawnTime(1);
        if (IsWarTime() && CanInteractWithRelic())
            EndBattle(false);
    }
    else if (IsWarTime())
    {
        // if destroy or damage event, search the wall/tower and update worldstate/send warning message
        if (WintergraspBuilding* building = GetBuilding(gameObject->GetGUID()))
        {
            if (GameObjectTemplate const* goTemp = gameObject->GetGOInfo())
            {
                if (goTemp->building.damagedEvent == eventId)
                    building->Damaged();
                else if (goTemp->building.destroyedEvent == eventId)
                {
                    // southern sabotage & toppling the towers
                    if (building->GetEntry() == GO_WINTERGRASP_SHADOWSIGHT_TOWER || building->GetEntry() == GO_WINTERGRASP_WINTER_S_EDGE_TOWER || building->GetEntry() == GO_WINTERGRASP_FLAMEWATCH_TOWER)
                    {
                        std::list<Player*> playerList = GetPlayerListInSourceRange(gameObject, DEFAULT_VISIBILITY_DISTANCE, GetDefenderTeam());
                        for (Player* player : playerList)
                            player->KilledMonsterCredit(goTemp->building.creditProxyCreature);
                    }
                    building->Destroyed();
                }
            }
        }
    }
}

uint32 BattlefieldWintergrasp::GetData(uint32 data) const
{
    switch (data)
    {
        // used to determine when the phasing spells must be cast
        // see: SpellArea::IsFitToRequirements
        case AREA_THE_SUNKEN_RING:
        case AREA_THE_BROKEN_TEMPLE:
        case AREA_WESTPARK_WORKSHOP:
        case AREA_EASTPARK_WORKSHOP:
            // graveyards and workshops are controlled by the same team.
            if (BattlefieldGraveyard const* graveyard = GetGraveyard(GetSpiritGraveyardId(data)))
                return graveyard->GetControlTeamId();
            break;
        default:
            break;
    }

    return Battlefield::GetData(data);
}

void BattlefieldWintergrasp::RemoveAurasFromPlayer(Player* player)
{
    player->RemoveAurasDueToSpell(SPELL_RECRUIT);
    player->RemoveAurasDueToSpell(SPELL_CORPORAL);
    player->RemoveAurasDueToSpell(SPELL_LIEUTENANT);
    player->RemoveAurasDueToSpell(SPELL_TOWER_CONTROL);
    player->RemoveAurasDueToSpell(SPELL_SPIRITUAL_IMMUNITY);
    player->RemoveAurasDueToSpell(SPELL_TENACITY);
    player->RemoveAurasDueToSpell(SPELL_GREATEST_HONOR);
    player->RemoveAurasDueToSpell(SPELL_GREATER_HONOR);
    player->RemoveAurasDueToSpell(SPELL_GREAT_HONOR);
    player->RemoveAurasDueToSpell(SPELL_ESSENCE_OF_WINTERGRASP);
    player->RemoveAurasDueToSpell(SPELL_WINTERGRASP_RESTRICTED_FLIGHT_AREA);
}

void BattlefieldWintergrasp::SetRelicInteractible()
{
    if (GameObject* relic = GetRelic())
    {
        relic->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE | GO_FLAG_NOT_SELECTABLE);
        relic->SetFaction(WintergraspFaction[GetAttackerTeam()]);
        relic->UpdateObjectVisibility(true);
    }
    _relicInteractible = true;
}

void BattlefieldWintergrasp::UpdateDamagedTowerCount(TeamId team)
{
    if (team == GetAttackerTeam())
        UpdateData(DATA_WINTERGRASP_DAMAGED_TOWER_ATTACK, 1);
    else
        UpdateData(DATA_WINTERGRASP_DAMAGED_TOWER_DEFENCE, 1);
}

void BattlefieldWintergrasp::UpdatedDestroyedTowerCount(TeamId team)
{
    // Destroy an attack tower
    if (team == GetAttackerTeam())
    {
        // Update counter
        UpdateData(DATA_WINTERGRASP_DAMAGED_TOWER_ATTACK, -1);
        UpdateData(DATA_WINTERGRASP_BROKEN_TOWER_ATTACK, 1);

        // Remove buff stack on attackers
        for (auto itr = _playersInWar[GetAttackerTeam()].begin(); itr != _playersInWar[GetAttackerTeam()].end(); ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                player->RemoveAuraFromStack(SPELL_TOWER_CONTROL);
        }

        // Add buff stack to defenders
        for (auto itr = _playersInWar[GetDefenderTeam()].begin(); itr != _playersInWar[GetDefenderTeam()].end(); ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
            {
                player->CastSpell(player, SPELL_TOWER_CONTROL, true);
                DoCompleteOrIncrementAchievement(ACHIEVEMENTS_WG_TOWER_DESTROY, player);
            }
        }

        // If all three south towers are destroyed (ie. all attack towers), remove ten minutes from battle time
        if (GetData(DATA_WINTERGRASP_BROKEN_TOWER_ATTACK) == 3)
        {
            if (GetTimer() <= 10 * MINUTE * IN_MILLISECONDS)
                EndBattle(true);
            else
                _timer.Update(10 * MINUTE * IN_MILLISECONDS);
            SendInitWorldStatesToAll();
        }
    }
    else
    {
        UpdateData(DATA_WINTERGRASP_DAMAGED_TOWER_DEFENCE, -1);
        UpdateData(DATA_WINTERGRASP_BROKEN_TOWER_DEFENCE, 1);
    }
}

void BattlefieldWintergrasp::UpdateVehicleCountWG()
{
    SendUpdateWorldState(WORLDSTATE_WINTERGRASP_VEHICLE_HORDE, GetData(DATA_WINTERGRASP_VEHICLE_HORDE));
    SendUpdateWorldState(WORLDSTATE_WINTERGRASP_MAX_VEHICLE_HORDE, GetData(DATA_WINTERGRASP_MAX_VEHICLE_HORDE));
    SendUpdateWorldState(WORLDSTATE_WINTERGRASP_VEHICLE_ALLIANCE, GetData(DATA_WINTERGRASP_VEHICLE_ALLIANCE));
    SendUpdateWorldState(WORLDSTATE_WINTERGRASP_MAX_VEHICLE_ALLIANCE, GetData(DATA_WINTERGRASP_MAX_VEHICLE_ALLIANCE));
}

void BattlefieldWintergrasp::UpdateVehicleCounter(bool initialize)
{
    if (initialize)
    {
        SetData(DATA_WINTERGRASP_VEHICLE_HORDE, 0);
        SetData(DATA_WINTERGRASP_VEHICLE_ALLIANCE, 0);
    }
    SetData(DATA_WINTERGRASP_MAX_VEHICLE_HORDE, 0);
    SetData(DATA_WINTERGRASP_MAX_VEHICLE_ALLIANCE, 0);

    for (WintergraspWorkshop* workshop : _workshopSet)
    {
        if (workshop->GetTeamControl() == TEAM_ALLIANCE)
            UpdateData(DATA_WINTERGRASP_MAX_VEHICLE_ALLIANCE, 4);
        else if (workshop->GetTeamControl() == TEAM_HORDE)
            UpdateData(DATA_WINTERGRASP_MAX_VEHICLE_HORDE, 4);
    }

    UpdateVehicleCountWG();
}

void BattlefieldWintergrasp::SendInitWorldStatesTo(Player const* player)
{
    WorldPacket data(SMSG_INIT_WORLD_STATES, 4 + 4 + 4 + 2 + (14 + _buildingSet.size() + _workshopSet.size()) * 8);

    data << uint32(_mapId);
    data << uint32(_zoneId);
    data << uint32(0);                                              // AreaId
    data << uint16(14 + _buildingSet.size() + _workshopSet.size()); // Number of fields

    FillInitialWorldStates(data);

    player->SendDirectMessage(&data);
}

void BattlefieldWintergrasp::HandlePromotion(Player* killer, Unit* killed)
{
    for (ObjectGuid guid : _playersInWar[killer->GetTeamId()])
    {
        if (Player* player = ObjectAccessor::GetPlayer(*killed, guid))
            if (player->GetDistance2d(killed) < 40.0f)
                PromotePlayer(player);
    }
}

void BattlefieldWintergrasp::PromotePlayer(Player* killer)
{
    if (!IsWarTime())
        return;

    // Updating rank of player
    if (Aura* auraRecruit = killer->GetAura(SPELL_RECRUIT))
    {
        if (auraRecruit->GetStackAmount() >= 5)
        {
            killer->RemoveAura(SPELL_RECRUIT);
            killer->CastSpell(killer, SPELL_CORPORAL, true);
            SendWarning(TEXT_WINTERGRASP_RANK_CORPORAL, killer);
        }
        else
            killer->CastSpell(killer, SPELL_RECRUIT, true);
    }
    else if (Aura* auraCorporal = killer->GetAura(SPELL_CORPORAL))
    {
        if (auraCorporal->GetStackAmount() >= 5)
        {
            killer->RemoveAura(SPELL_CORPORAL);
            killer->CastSpell(killer, SPELL_LIEUTENANT, true);
            SendWarning(TEXT_WINTERGRASP_RANK_FIRST_LIEUTENANT, killer);
        }
        else
            killer->CastSpell(killer, SPELL_CORPORAL, true);
    }
}

void BattlefieldWintergrasp::UpdateTenacity()
{
    uint32 const alliancePlayers = _playersInWar[TEAM_ALLIANCE].size();
    uint32 const hordePlayers = _playersInWar[TEAM_HORDE].size();
    uint32 newStack = 0;
    TeamId newTeam = TEAM_NEUTRAL;

    if (alliancePlayers && hordePlayers)
    {
        if (alliancePlayers < hordePlayers)
        {
            newTeam = TEAM_ALLIANCE;
            newStack = uint32((float(hordePlayers) / float(alliancePlayers) - 1.f) * 4.f);
        }
        else if (alliancePlayers > hordePlayers)
        {
            newTeam = TEAM_HORDE;
            newStack = uint32((float(alliancePlayers) / float(hordePlayers) - 1.f) * 4.f);
        }
        else
            newTeam = TEAM_NEUTRAL;
    }

    if (newStack == _tenacityStack && newTeam == _tenacityTeam)
        return;

    TeamId oldTeam = _tenacityTeam;
    _tenacityTeam = newTeam;
    _tenacityStack = newStack;

    // Remove old buff
    if (oldTeam != TEAM_NEUTRAL)
    {
        for (auto itr = _players[oldTeam].begin(); itr != _players[oldTeam].end(); ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
            {
                player->RemoveAurasDueToSpell(SPELL_TENACITY);
                player->RemoveAurasDueToSpell(SPELL_GREATEST_HONOR);
                player->RemoveAurasDueToSpell(SPELL_GREATER_HONOR);
                player->RemoveAurasDueToSpell(SPELL_GREAT_HONOR);
            }
        }

        for (auto itr = _vehicleSet[oldTeam].begin(); itr != _vehicleSet[oldTeam].end(); ++itr)
        {
            if (Creature* creature = GetCreature(*itr))
            {
                creature->RemoveAurasDueToSpell(SPELL_TENACITY_VEHICLE);
                creature->RemoveAurasDueToSpell(SPELL_GREATEST_HONOR);
                creature->RemoveAurasDueToSpell(SPELL_GREATER_HONOR);
                creature->RemoveAurasDueToSpell(SPELL_GREAT_HONOR);
            }
        }
    }

    // Apply new buff
    if (_tenacityStack && _tenacityTeam != TEAM_NEUTRAL)
    {
        for (auto itr = _playersInWar[_tenacityTeam].begin(); itr != _playersInWar[_tenacityTeam].end(); ++itr)
        {
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                ApplyTenacity(player);
        }

        for (auto itr = _vehicleSet[_tenacityTeam].begin(); itr != _vehicleSet[_tenacityTeam].end(); ++itr)
        {
            if (Creature* creature = GetCreature(*itr))
                ApplyTenacity(creature, true);
        }
    }
}

void BattlefieldWintergrasp::SendWarning(uint8 id, Player const* target)
{
    if (!id)
        return;

    if (!target)
    {
        if (Creature* stalker = GetCreature(_stalkerGUID))
            stalker->AI()->Talk(id);
    }
    else if (Creature* stalker = target->FindNearestCreature(NPC_WINTERGRASP_STALKER, SIZE_OF_GRIDS))
        stalker->AI()->Talk(id, target);
}

void BattlefieldWintergrasp::SendSpellAreaUpdate(uint32 areaId)
{
    for (uint8 team = 0; team < 2; ++team)
    {
        for (auto itr = _players[team].begin(); itr != _players[team].end(); ++itr)
            if (Player* player = ObjectAccessor::FindPlayer(*itr))
                if (player->GetAreaId() == areaId)
                    player->UpdateAreaDependentAuras(areaId);
    }
}

WintergraspGraveyardId BattlefieldWintergrasp::GetSpiritGraveyardId(uint32 areaId) const
{
    switch (areaId)
    {
        case AREA_WINTERGRASP_FORTRESS:
            return GRAVEYARDID_KEEP;
        case AREA_THE_SUNKEN_RING:
            return GRAVEYARDID_WORKSHOP_NE;
        case AREA_THE_BROKEN_TEMPLE:
            return GRAVEYARDID_WORKSHOP_NW;
        case AREA_WESTPARK_WORKSHOP:
            return GRAVEYARDID_WORKSHOP_SW;
        case AREA_EASTPARK_WORKSHOP:
            return GRAVEYARDID_WORKSHOP_SE;
        default:
            TC_LOG_DEBUG("battlefield", "BattlefieldWintergrasp::GetSpiritGraveyardId: Unexpected Area Id %u", areaId);
            break;
    }

    return GRAVEYARDID_MAX;
}

WintergraspBuilding* BattlefieldWintergrasp::GetBuilding(uint32 entry) const
{
    for (WintergraspBuilding* building : _buildingSet)
    {
        if (building->GetEntry() == entry)
            return building;
    }

    return nullptr;
}

WintergraspBuilding* BattlefieldWintergrasp::GetBuilding(ObjectGuid guid) const
{
    for (WintergraspBuilding* building : _buildingSet)
    {
        if (building->GetGUID() == guid)
            return building;
    }

    return nullptr;
}

WintergraspWorkshop* BattlefieldWintergrasp::GetWorkshop(WintergraspWorkshopId id) const
{
    for (WintergraspWorkshop* workshop : _workshopSet)
    {
        if (workshop->GetId() == id)
            return workshop;
    }

    return nullptr;
}

void BattlefieldWintergrasp::ApplyTenacity(Unit* target, bool vehicle/* = false*/)
{
    uint32 honorBuffEntry = SPELL_GREATEST_HONOR;
    if (_tenacityStack < 5)
        honorBuffEntry = 0;
    else if (_tenacityStack < 10)
        honorBuffEntry = SPELL_GREAT_HONOR;
    else if (_tenacityStack < 15)
        honorBuffEntry = SPELL_GREATER_HONOR;

    target->SetAuraStack(vehicle ? SPELL_TENACITY_VEHICLE : SPELL_TENACITY, target, std::min(_tenacityStack, uint32(20)));
    if (honorBuffEntry)
        target->CastSpell(target, honorBuffEntry, true);
}

//*******************************************************
//******************* Graveyard *************************
//*******************************************************

WintergraspGraveyard::WintergraspGraveyard(BattlefieldWintergrasp* battlefield) : BattlefieldGraveyard(battlefield)
{
    _battlefield = battlefield;
    _gossipTextId = 0;
}

//*******************************************************
//******************* CapturePoint **********************
//*******************************************************

WintergraspCapturePoint::WintergraspCapturePoint(BattlefieldWintergrasp* battlefield, TeamId teamInControl) : BattlefieldCapturePoint(battlefield)
{
    _battlefield = battlefield;
    _team = teamInControl;
    _workshop = nullptr;
}

void WintergraspCapturePoint::ChangeTeam(TeamId /*oldteam*/)
{
    ASSERT(_workshop);
    _workshop->GiveControlTo(_team);
}

//*******************************************************
//******************* Building **************************
//*******************************************************

WintergraspBuilding::WintergraspBuilding(BattlefieldWintergrasp* wintergrasp, WintergraspBuildingType type, uint32 entry, uint32 worldState)
{
    ASSERT(wintergrasp);

    _battlefield = wintergrasp;
    _teamControl = TEAM_NEUTRAL;
    _type = type;
    _worldState = worldState;
    _entry = entry;
    _state = OBJECTSTATE_NONE;
    _info = nullptr;
}

void WintergraspBuilding::Initialize(GameObject* gameObject)
{
    if (!gameObject)
        return;

    // GameObject associated to object
    _buildGUID = gameObject->GetGUID();
    gameObject->SetFaction(WintergraspFaction[_teamControl]);

    _state = WintergraspGameObjectState(sWorld->getWorldState(_worldState));
    switch (_state)
    {
        case OBJECTSTATE_NEUTRAL_INTACT:
        case OBJECTSTATE_ALLIANCE_INTACT:
        case OBJECTSTATE_HORDE_INTACT:
            gameObject->SetDestructibleState(GO_DESTRUCTIBLE_INTACT, nullptr, true);
            break;
        case OBJECTSTATE_NEUTRAL_DESTROYED:
        case OBJECTSTATE_ALLIANCE_DESTROYED:
        case OBJECTSTATE_HORDE_DESTROYED:
            gameObject->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED, nullptr, true);
            break;
        case OBJECTSTATE_NEUTRAL_DAMAGED:
        case OBJECTSTATE_ALLIANCE_DAMAGED:
        case OBJECTSTATE_HORDE_DAMAGED:
            gameObject->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED, nullptr, true);
            break;
        default:
            break;
    }

    int32 towerId = -1;
    switch (gameObject->GetEntry())
    {
        case GO_WINTERGRASP_FORTRESS_TOWER_1:
            towerId = TOWERID_FORTRESS_NW;
            break;
        case GO_WINTERGRASP_FORTRESS_TOWER_2:
            towerId = TOWERID_FORTRESS_SW;
            break;
        case GO_WINTERGRASP_FORTRESS_TOWER_3:
            towerId = TOWERID_FORTRESS_SE;
            break;
        case GO_WINTERGRASP_FORTRESS_TOWER_4:
            towerId = TOWERID_FORTRESS_NE;
            break;
        case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
            towerId = TOWERID_SHADOWSIGHT;
            break;
        case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
            towerId = TOWERID_WINTER_S_EDGE;
            break;
        case GO_WINTERGRASP_FLAMEWATCH_TOWER:
            towerId = TOWERID_FLAMEWATCH;
            break;
        default:
            break;
    }

    if (towerId >= TOWERID_SHADOWSIGHT) // Attacker towers
    {
        if (_gameObjectList[TEAM_HORDE].size() != AttackTowers[towerId - 4].GameObject.size())
            _gameObjectList[TEAM_HORDE].resize(AttackTowers[towerId - 4].GameObject.size(), ObjectGuid::Empty);
        if (_gameObjectList[TEAM_ALLIANCE].size() != AttackTowers[towerId - 4].GameObject.size())
            _gameObjectList[TEAM_ALLIANCE].resize(AttackTowers[towerId - 4].GameObject.size(), ObjectGuid::Empty);

        // Spawn associated gameobjects
        for (size_t position = 0; position < AttackTowers[towerId - 4].GameObject.size(); ++position)
        {
            WintergraspGameObjectData const& gobData = AttackTowers[towerId - 4].GameObject[position];
            if (_gameObjectList[TEAM_HORDE][position].IsEmpty())
                if (GameObject* goHorde = _battlefield->SpawnGameObject(gobData.HordeEntry, gobData.Location, gobData.Rotation))
                    _gameObjectList[TEAM_HORDE][position] = goHorde->GetGUID();

            if (_gameObjectList[TEAM_ALLIANCE][position].IsEmpty())
                if (GameObject* goAlliance = _battlefield->SpawnGameObject(gobData.AllianceEntry, gobData.Location, gobData.Rotation))
                    _gameObjectList[TEAM_ALLIANCE][position] = goAlliance->GetGUID();
        }

        if (_creatureList[TEAM_HORDE].size() != AttackTowers[towerId - 4].CreatureBottom.size())
            _creatureList[TEAM_HORDE].resize(AttackTowers[towerId - 4].CreatureBottom.size(), ObjectGuid::Empty);
        if (_creatureList[TEAM_ALLIANCE].size() != AttackTowers[towerId - 4].CreatureBottom.size())
            _creatureList[TEAM_ALLIANCE].resize(AttackTowers[towerId - 4].CreatureBottom.size(), ObjectGuid::Empty);

        // Spawn associated NPCs
        for (size_t position = 0; position < AttackTowers[towerId - 4].CreatureBottom.size(); ++position)
        {
            WintergraspObjectPositionData const& creatureData = AttackTowers[towerId - 4].CreatureBottom[position];
            if (_creatureList[TEAM_HORDE][position].IsEmpty())
            {
                if (Creature* creature = _battlefield->SpawnCreature(creatureData.HordeEntry, creatureData.Location))
                {
                    _creatureList[TEAM_HORDE][position] = creature->GetGUID();
                    creature->SetRespawnTime(2 * MINUTE);
                }
            }

            if (_creatureList[TEAM_ALLIANCE][position].IsEmpty())
            {
                if (Creature* creature = _battlefield->SpawnCreature(creatureData.AllianceEntry, creatureData.Location))
                {
                    _creatureList[TEAM_ALLIANCE][position] = creature->GetGUID();
                    creature->SetRespawnTime(2 * MINUTE);
                }
            }
        }

        UpdateCreatureAndGo();
    }

    if (towerId >= 0)
    {
        ASSERT(towerId < TOWERID_MAX);
        _info = &TowerData[towerId];

        if (_bottomCannonList.size() != TowerCannon[towerId].TowerCannonBottom.size())
            _bottomCannonList.resize(TowerCannon[towerId].TowerCannonBottom.size(), ObjectGuid::Empty);

        // Spawn Turret bottom
        for (size_t position = 0; position < TowerCannon[towerId].TowerCannonBottom.size(); position++)
        {
            Position const& turretPos = TowerCannon[towerId].TowerCannonBottom[position];
            if (_bottomCannonList[position].IsEmpty())
            {
                if (Creature* turret = _battlefield->SpawnCreature(NPC_WINTERGRASP_TOWER_CANNON, turretPos))
                {
                    switch (gameObject->GetEntry())
                    {
                        case GO_WINTERGRASP_FORTRESS_TOWER_1:
                        case GO_WINTERGRASP_FORTRESS_TOWER_2:
                        case GO_WINTERGRASP_FORTRESS_TOWER_3:
                        case GO_WINTERGRASP_FORTRESS_TOWER_4:
                            turret->SetFaction(WintergraspFaction[_battlefield->GetDefenderTeam()]);
                            break;
                        case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                        case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                        case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                            turret->SetFaction(WintergraspFaction[_battlefield->GetAttackerTeam()]);
                            break;
                        default:
                            break;
                    }
                    _bottomCannonList[position] = turret->GetGUID();
                    turret->SetRespawnTime(2 * MINUTE);
                }
            }
        }

        if (_topCannonList.size() != TowerCannon[towerId].TurretTop.size())
            _topCannonList.resize(TowerCannon[towerId].TurretTop.size(), ObjectGuid::Empty);

        // Spawn Turret top
        for (size_t position = 0; position < TowerCannon[towerId].TurretTop.size(); ++position)
        {
            Position const& turretPos = TowerCannon[towerId].TurretTop[position];
            if (_topCannonList[position].IsEmpty())
            {
                if (Creature* turret = _battlefield->SpawnCreature(NPC_WINTERGRASP_TOWER_CANNON, turretPos))
                {
                    switch (gameObject->GetEntry())
                    {
                        case GO_WINTERGRASP_FORTRESS_TOWER_1:
                        case GO_WINTERGRASP_FORTRESS_TOWER_2:
                        case GO_WINTERGRASP_FORTRESS_TOWER_3:
                        case GO_WINTERGRASP_FORTRESS_TOWER_4:
                            turret->SetFaction(WintergraspFaction[_battlefield->GetDefenderTeam()]);
                            break;
                        case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                        case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                        case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                            turret->SetFaction(WintergraspFaction[_battlefield->GetAttackerTeam()]);
                            break;
                        default:
                            break;
                    }
                    _topCannonList[position] = turret->GetGUID();
                    turret->SetRespawnTime(2 * MINUTE);
                }
            }
        }

        UpdateTurretAttack(!_battlefield->IsWarTime());
    }
}

void WintergraspBuilding::Rebuild()
{
    switch (_type)
    {
        case OBJECTTYPE_KEEP_TOWER:
        case OBJECTTYPE_DOOR_LAST:
        case OBJECTTYPE_DOOR:
        case OBJECTTYPE_WALL:
            _teamControl = _battlefield->GetDefenderTeam();      // Objects that are part of the keep should be the defender's
            break;
        case OBJECTTYPE_TOWER:
            _teamControl = _battlefield->GetAttackerTeam();      // The towers in the south should be the attacker's
            break;
        default:
            _teamControl = TEAM_NEUTRAL;
            break;
    }

    if (GameObject* build = _battlefield->GetGameObject(_buildGUID))
    {
        // Rebuild gameobject
        if (build->IsDestructibleBuilding())
        {
            build->SetDestructibleState(GO_DESTRUCTIBLE_REBUILDING, nullptr, true);

            if (build->GetEntry() == GO_WINTERGRASP_VAULT_GATE)
            {
                if (GameObject* go = build->FindNearestGameObject(GO_WINTERGRASP_KEEP_COLLISION_WALL, 50.0f))
                {
                    go->SetGoState(GO_STATE_READY);
                    go->SetLootState(GO_JUST_DEACTIVATED);
                }
            }
        }

        build->SetFaction(WintergraspFaction[_teamControl]);
    }

    _state = WintergraspGameObjectState(OBJECTSTATE_ALLIANCE_INTACT - (_teamControl * 3));
    _battlefield->SendUpdateWorldState(_worldState, _state);

    switch (_type)
    {
        case OBJECTTYPE_TOWER:
            UpdateCreatureAndGo();
        case OBJECTTYPE_KEEP_TOWER:
            UpdateTurretAttack(false);
            break;
        default:
            break;
    }
}

void WintergraspBuilding::Damaged()
{
    // Update worldstate
    _state = WintergraspGameObjectState(OBJECTSTATE_ALLIANCE_DAMAGED - (_teamControl * 3));
    _battlefield->SendUpdateWorldState(_worldState, _state);

    // Send warning message
    if (_info)
        _battlefield->SendWarning(_info->TextIds.Damaged);

    for (ObjectGuid guid : _topCannonList)
    {
        if (Creature* creature = _battlefield->GetCreature(guid))
            _battlefield->HideCreature(creature);
    }

    if (_type == OBJECTTYPE_KEEP_TOWER)
        _battlefield->UpdateDamagedTowerCount(_battlefield->GetDefenderTeam());
    else if (_type == OBJECTTYPE_TOWER)
        _battlefield->UpdateDamagedTowerCount(_battlefield->GetAttackerTeam());
}

void WintergraspBuilding::Destroyed()
{
    // Update worldstate
    _state = WintergraspGameObjectState(OBJECTSTATE_ALLIANCE_DESTROYED - (_teamControl * 3));
    _battlefield->SendUpdateWorldState(_worldState, _state);

    // Warn players
    if (_info)
        _battlefield->SendWarning(_info->TextIds.Destroyed);

    switch (_type)
    {
        // Inform the global wintergrasp script of the destruction of this object
        case OBJECTTYPE_TOWER:
        case OBJECTTYPE_KEEP_TOWER:
            _battlefield->UpdatedDestroyedTowerCount(_teamControl);
            break;
        case OBJECTTYPE_DOOR_LAST:
            if (GameObject* build = _battlefield->GetGameObject(_buildGUID))
            {
                if (GameObject* go = build->FindNearestGameObject(GO_WINTERGRASP_KEEP_COLLISION_WALL, 50.0f))
                {
                    go->SetGoState(GO_STATE_ACTIVE);
                    go->SetLootState(GO_ACTIVATED);
                }
            }

            _battlefield->SetRelicInteractible();
            break;
        default:
            break;
    }
}

void WintergraspBuilding::CleanRelatedObject(ObjectGuid guid)
{
    if (guid.IsUnit())
    {
        GuidVector::iterator itr = std::find(_creatureList[TEAM_ALLIANCE].begin(), _creatureList[TEAM_ALLIANCE].end(), guid);
        if (itr != _creatureList[TEAM_ALLIANCE].end())
            *itr = ObjectGuid::Empty;
        itr = std::find(_creatureList[TEAM_HORDE].begin(), _creatureList[TEAM_HORDE].end(), guid);
        if (itr != _creatureList[TEAM_HORDE].end())
            *itr = ObjectGuid::Empty;
        itr = std::find(_bottomCannonList.begin(), _bottomCannonList.end(), guid);
        if (itr != _bottomCannonList.end())
            *itr = ObjectGuid::Empty;
        itr = std::find(_topCannonList.begin(), _topCannonList.end(), guid);
        if (itr != _topCannonList.end())
            *itr = ObjectGuid::Empty;
    }
    else if (guid.IsGameObject())
    {
        GuidVector::iterator itr = std::find(_gameObjectList[TEAM_ALLIANCE].begin(), _gameObjectList[TEAM_ALLIANCE].end(), guid);
        if (itr != _gameObjectList[TEAM_ALLIANCE].end())
            *itr = ObjectGuid::Empty;
        itr = std::find(_gameObjectList[TEAM_HORDE].begin(), _gameObjectList[TEAM_HORDE].end(), guid);
        if (itr != _gameObjectList[TEAM_HORDE].end())
            *itr = ObjectGuid::Empty;
    }
}

void WintergraspBuilding::UpdateCreatureAndGo()
{
    for (ObjectGuid guid : _creatureList[_battlefield->GetOtherTeam(_teamControl)])
    {
        if (Creature* creature = _battlefield->GetCreature(guid))
            _battlefield->HideCreature(creature);
    }

    for (ObjectGuid guid : _creatureList[_teamControl])
    {
        if (Creature* creature = _battlefield->GetCreature(guid))
            _battlefield->ShowCreature(creature, true);
    }

    for (ObjectGuid guid : _gameObjectList[_battlefield->GetOtherTeam(_teamControl)])
    {
        if (GameObject* go = _battlefield->GetGameObject(guid))
            go->SetRespawnTime(DAY);
    }

    for (ObjectGuid guid : _gameObjectList[_teamControl])
    {
        if (GameObject* go = _battlefield->GetGameObject(guid))
            go->SetRespawnTime(IsDestroyed() ? DAY : 1);
    }
}

void WintergraspBuilding::UpdateTurretAttack(bool disable)
{
    for (ObjectGuid guid : _bottomCannonList)
    {
        if (Creature* creature = _battlefield->GetCreature(guid))
        {
            if (disable || IsDestroyed())
                _battlefield->HideCreature(creature);
            else
            {
                _battlefield->ShowCreature(creature, false);
                switch (_buildGUID.GetEntry())
                {
                    case GO_WINTERGRASP_FORTRESS_TOWER_1:
                    case GO_WINTERGRASP_FORTRESS_TOWER_2:
                    case GO_WINTERGRASP_FORTRESS_TOWER_3:
                    case GO_WINTERGRASP_FORTRESS_TOWER_4:
                        creature->SetFaction(WintergraspFaction[_teamControl]);
                        break;
                    case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                    case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                    case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                        creature->SetFaction(WintergraspFaction[_teamControl]);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    for (ObjectGuid guid : _topCannonList)
    {
        if (Creature* creature = _battlefield->GetCreature(guid))
        {
            if (disable || IsDestroyed() || IsDamaged())
                _battlefield->HideCreature(creature);
            else
            {
                _battlefield->ShowCreature(creature, false);
                switch (_buildGUID.GetEntry())
                {
                    case GO_WINTERGRASP_FORTRESS_TOWER_1:
                    case GO_WINTERGRASP_FORTRESS_TOWER_2:
                    case GO_WINTERGRASP_FORTRESS_TOWER_3:
                    case GO_WINTERGRASP_FORTRESS_TOWER_4:
                        creature->SetFaction(WintergraspFaction[_teamControl]);
                        break;
                    case GO_WINTERGRASP_SHADOWSIGHT_TOWER:
                    case GO_WINTERGRASP_WINTER_S_EDGE_TOWER:
                    case GO_WINTERGRASP_FLAMEWATCH_TOWER:
                        creature->SetFaction(WintergraspFaction[_teamControl]);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

void WintergraspBuilding::UpdateForNoBattle(bool initialize)
{
    _teamControl = _battlefield->GetDefenderTeam();

    // Update worldstate
    if (initialize)
        _state = _state = WintergraspGameObjectState(OBJECTSTATE_ALLIANCE_INTACT - (_teamControl * 3));
    else
    {
        if (_state >= OBJECTSTATE_ALLIANCE_INTACT && _teamControl == TEAM_HORDE)
            _state = WintergraspGameObjectState(_state - 3);
        else if (_state < OBJECTSTATE_ALLIANCE_INTACT && _state >= OBJECTSTATE_HORDE_INTACT && _teamControl == TEAM_ALLIANCE)
            _state = WintergraspGameObjectState(_state + 3);
    }

    _battlefield->SendUpdateWorldState(_worldState, _state);

    if (GameObject* build = _battlefield->GetGameObject(_buildGUID))
        build->SetFaction(WintergraspFaction[_teamControl]);

    switch (_type)
    {
        case OBJECTTYPE_TOWER:
            UpdateCreatureAndGo();
        case OBJECTTYPE_KEEP_TOWER:
            UpdateTurretAttack(true);
            break;
        default:
            break;
    }
}

void WintergraspBuilding::FillInitialWorldStates(WorldPacket& data)
{
    data << uint32(_worldState) << uint32(_state);
}

void WintergraspBuilding::Save()
{
    sWorld->setWorldState(_worldState, _state);
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
        _battlefield->UpdateVehicleCounter(false);

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
