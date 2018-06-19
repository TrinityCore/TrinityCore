/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "MoveSplineInit.h"
#include "SpellAuraEffects.h"
#include "G3D/Vector3.h"
//#include "Group.h"

#ifndef HIGHMAUL_HPP
#define HIGHMAUL_HPP

Position const g_PlayScenePos = { 3448.069f, 7573.542f, 55.30419f, 0.3921495f };

enum eHighmaulDatas
{
    /// Bosses
    BossKargathBladefist,
    BossTheButcher,
    BossBrackenspore,
    BossTectus,
    BossTwinOgron,
    BossKoragh,
    BossImperatorMargok,
    MaxHighmaulBosses,

    /// Instance datas
    ElevatorActivated = 0,
    TestsActivated,
    KargathAchievement,
    ButcherAchievement,
    TectusAchievement,
    BrackensporeAchievement,
    TwinOgronAchievement,
    KoraghOverflowingEnergy,
    KoraghNullificationBarrier,
    KoraghAchievement,
    ImperatorAchievement,

    /// Misc values
    /// Global
    PhaseNone = 1,
    PhaseKargathDefeated = 2,
    /// Kargath
    RaidGrate001 = 0,
    RaidGrate002,
    RaidGrate003,
    RaidGrate004,
    MaxRaidGrates,
    HighmaulSweeperCount = 2,
    HighmaulSweeperMovesCount = 9,
    /// The Butcher
    MaxMaggotToKill = 6,
    /// Brackenspore
    MaxCreepingMoss = 16,
    MaxFleshEaterPos = 2,
    BurningInfusionNeeded = 15,
    /// The Market
    MaxTectusGuardians = 3,
    /// Twin Ogron
    DispositionPCT = 30,
    /// Ko'ragh
    MaxOverflowingEnergy = 14,
    /// Imperator Mar'gok
    MaxIntervalles = 2
};

enum eHighmaulCreatures
{
    /// Walled City
    GhargArenaMaster        = 84971,
    GorianEnforcer          = 88724,
    /// The Coliseum
    KargathBladefist        = 78714,
    JhornTheMad             = 83377,
    ThoktarIronskull        = 83378,
    Vulgor                  = 80048,
    BladespireSorcerer      = 80071,
    CrowdAreatrigger        = 79260,
    MargokCosmetic          = 83268,
    IronBomberSpawner       = 79712,
    IronBomber              = 78926,
    DrunkenBileslinger      = 78954,
    HighmaulSweeper         = 88874,
    /// The Underbelly
    TheButcher              = 77404,
    /// Gorian Strands
    IronGrunt               = 88118,
    BlackrockGrunt          = 86610,
    LowBatchDeadPale        = 86283,
    NightTwistedPaleVis     = 82694,
    CosmeticGorianWarr      = 82690,
    GorianCivilian          = 85371,
    Brackenspore            = 78491,
    BFC9000                 = 81403,
    /// The Market
    Tectus                  = 78948,
    Rokka                   = 86071,
    Oro                     = 86072,
    Lokk                    = 86073,
    /// The Gorthenon
    Phemos                  = 78237,
    Pol                     = 78238,
    /// Chamber of Nullification
    Koragh                  = 79015,
    RuneOfNullification     = 79559,
    VolatileAnomaly         = 79956,
    /// Throne of the Imperator
    ImperatorMargok         = 77428,
    HighCouncilorMalgris    = 81811,
    KingPrison              = 89185,
    Chogall                 = 78623
};

enum eHighmaulGameobjects
{
    ArenaElevator           = 233098,
    CollisionWall           = 234299,
    InstancePortal2         = 231770,

    /// Kargath's Doors
    GateArenaExit           = 231781,
    GateArenaInner          = 231780,

    /// The Butcher's Doors
    EarthenPillar           = 239110,

    /// Brackenspore's Doors
    FungalGiantDoor         = 239124,
    WindDoor                = 236703,

    /// Kargath Bladefist
    RaidGrate1              = 232368,
    RaidGrate2              = 232369,
    RaidGrate3              = 232370,
    RaidGrate4              = 232371,

    /// Tectus's Doors
    Earthwall1              = 237777,
    Earthwall2              = 237778,
    Earthwall3              = 237779,
    Earthwall4              = 237780,
    HighmaulLFRDoor         = 239126,
    HighmaulLFRDoorColiseum = 239125,

    /// Twin Ogron's Doors
    TwinOgronEntrance       = 236211,
    TwinOgronExit           = 236212,

    /// Ko'ragh's Doors
    FelBreakerEntrance      = 236213,
    FelBreakerExitDoor      = 236214,

    /// Imperator Margokk Door
    ThroneRoomDoor          = 231938,
    StairBlockingDoor       = 236210,

    /// Misc
    Teleporter              = 231776,
    SLGGenericMoPLargeAoI   = 68553
};

enum eHighmaulWorldStates
{
    UnknownHighmaulWorldState   = 8902,
    DisableCrowdSound           = 8903,
    UnknownHighmaulWorldState2  = 9118,
    IronBomberEnable            = 9722,
    IronBomberRemaining         = 9723,
    DrunkenBileslingerEnable    = 9724,
    DrunkenBileslingerRemaining = 9725
};

enum eHighmaulSpells
{
    PlayChogallScene    = 178333,
    ChogallNight        = 163661,
    Berserker           = 26662,
    PermanentFeignDeath = 167082
};

enum eHighmaulLocs
{
    BeachEntrance       = 4780,
    ExitTarget          = 4782,
    ArenaCenter         = 4783,
    KargathDefeated     = 4784,
    PalaceFrontGate     = 4785,
    FelBreakerRoom      = 4786,
    ImperatorsRise      = 4787,
    CityBaseTeleporter  = 4788
};

enum eHighmaulDungeons
{
    WalledCity      = 849,
    ArcaneSanctum   = 850,
    ImperatorsFall  = 851
};

enum eHighmaulAchievements
{
    FlameOn             = 8948,
    HurryUpMaggot       = 8947,
    MoreLikeWreckedUs   = 8974,
    AFungusAmongUs      = 8975,
    BrothersInArms      = 8958,
    PairAnnihilation    = 8976,
    LineageOfPower      = 8977,
    AheadOfTheCurve     = 9441,
    CuttingEdge         = 9442
};

#endif
