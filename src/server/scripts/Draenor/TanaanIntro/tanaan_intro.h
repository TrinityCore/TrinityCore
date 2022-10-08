/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "GameObjectAI.h"
#include "NPCHandler.h"
#include "Vehicle.h"
#include <random>

#ifndef TANAAN_INTRO_H
#define TANAAN_INTRO_H

struct Hut
{
    float X, Y, Z;
    bool Fired;
};

namespace TanaanQuests
{
    enum
    {
        //QuestStartDraenor                   = 36881,
        QuestDarkPortal                       = 34398,
        QuestAzerothsLastStand                = 35933,
        QuestOnslaughtEnd                     = 34392,
        QuestThePortalPower                   = 34393,
        QuestBledDryAlly                      = 35240,
        QuestBledDryHorde                     = 34421,
        QuestCostOfWar                        = 34420,
        QuestBlazeOfGlory                     = 34422,
        QuestAltarAltercation                 = 34423,
        QuestAPotentialAlly                   = 34478,
        QuestAPotentialAllyHorde              = 34427,
        QuestKargatharProvingGrounds          = 34425,
        QuestKillYourHundred                  = 34429,
        QuestMastersOfShadowAlly              = 34431,
        QuestMastersOfShadowHorde             = 34737,
        QuestKeliDanTheBreakerHorde           = 34741,
        QuestKeliDanTheBreakerAlly            = 34436,
        QuestTheGunpowderPlot                 = 34987,
        QuestATasteOfIron                     = 34445,
        QuestTheHomeStretchHorde              = 34446,
        QuestTheHomeStretchAlly               = 35884,
        QuestYrelHorde                        = 34740,
        QuestYrelTanaan                       = 34434,
        QuestABattleToPrepareAlly             = 35019,
        QuestABattleToPrepareHorde            = 35005,
        QuestTheBattleOfTheForge              = 34439,
        QuestTakingATripToTheTopOfTheTank     = 35747,
        QuestGaNarOfTheFrostwolf              = 34442,
        QuestTheProdigalFrostwolf             = 34437,
    };
}

namespace TanaanSceneObjects
{
    enum
    {
        SceneCostOfWarEscort            = 806,
        SceneGulDanFreedom              = 808,
        SceneSouthernCage               = 812,
        SceneEasterCage                 = 813,
        SceneCuriousHatchets            = 817,
        SceneRingOfFire                 = 838,
        SceneKargathFight               = 839,
        SceneUmbralHallsPortals         = 844,
        SceneKelidanVisual1             = 857,
        SceneKelidanVisual2             = 858,
        SceneYrelLeaveAlliance          = 861,
        SceneYrelLeaveHorde             = 870,
        SceneShootingGallery            = 871,
        SceneKhadgarAtDam               = 894,
        SceneBlackHandReveal            = 896,
        SceneBuildingExplosion          = 893,
        SceneBuildingExplosionFallBack  = 902,
        SceneBridgeDestruction          = 903,
        SceneArmingPrisonersHorde       = 906,
        SceneArmingPrisonersAlly        = 981,
        SceneKhadgarGoesToDam           = 908,
        SceneDamExplosion               = 910,
        SceneFreeGanar                  = 911,
        SceneFinaleIronBastion          = 912,
        SceneFromCaveToRidge            = 922,
        SceneLoomingArmy                = 923,
        SceneGulDanReavel               = 925,
        SceneWaterPortal                = 928,
        SceneHoldout                    = 933,
        SceneEyeOfKilrogg               = 938,
        SceneKilRoggRevealed            = 940,
        SceneSneakyArmy                 = 942,
        SceneEnterKarGathArena          = 945,
        SceneEscapingTheArena           = 946,
        SceneQuianaAndMaladaarEnter     = 947,
        SceneLiadrinAndOlinEnter        = 948,
        SceneKargathYells               = 951,
        SceneNerZhulReveal              = 952,
        SceneHordeBoat                  = 953,
        SceneCaveIn                     = 956,
        SceneChoGallsFreedom            = 961,
        SceneTeronGorsFreedom           = 962,
        SceneAllianceBoat               = 986,
        SceneSoulTrain                  = 1018,
        SceneBloodBowl                  = 1029
    };
}

namespace TanaanPhaseSpell
{
    enum
    {
        PHASE_169       = 172329,
        PHASE_170       = 59073,
        PHASE_171       = 59074,
        PHASE_172       = 59087,
        PHASE_173       = 54341,
        //PHASE_174      = 0,
        PHASE_175       = 57569,
        PHASE_176       = 74789,
        PHASE_177       = 69819,
        //PHASE_178     = 0,
        PHASE_179       = 67789,
        PHASE_180       = 68480,
        PHASE_181       = 68481,
        PHASE_182       = 68482,
        PHASE_183       = 68483,
        PHASE_184       = 69077,
        PHASE_185       = 69078,
        PHASE_186       = 69484
    };
}

namespace TanaanPhases
{
    enum
    {
        // Devant porte
        PhaseChoGallSpell               = TanaanPhaseSpell::PHASE_175,
        PhaseTeronGorSpell              = TanaanPhaseSpell::PHASE_176,

        // Orbite Sanglante
        PhaseSouthernCageAlly           = TanaanPhaseSpell::PHASE_172,
        PhaseEasternCageAlly            = TanaanPhaseSpell::PHASE_173,
        PhaseSouthernCageHorde          = TanaanPhaseSpell::PHASE_175,
        PhaseEasternCageHorde           = TanaanPhaseSpell::PHASE_176,
        PhaseAfterBlazeGlobal           = TanaanPhaseSpell::PHASE_177,
        PhaseAfterBlazeAlliance         = TanaanPhaseSpell::PHASE_179,
        PhaseAfterBlazeHorde            = TanaanPhaseSpell::PHASE_180,
        PhaseAfterBlazeAriok            = TanaanPhaseSpell::PHASE_181,

        PhaseBridgeIntact               = TanaanPhaseSpell::PHASE_185,
        PhaseBridgeDestroyed            = TanaanPhaseSpell::PHASE_186,

        PhaseArenaEntranceGateClose     = TanaanPhaseSpell::PHASE_179,
        PhaseArenaFight                 = TanaanPhaseSpell::PHASE_180,
        PhaseArenaIced                  = TanaanPhaseSpell::PHASE_181,
        PhaseArenaExitGateClose         = TanaanPhaseSpell::PHASE_182,
        PhaseArenaFightAlliance         = TanaanPhaseSpell::PHASE_183,
        PhaseArenaFightHorde            = TanaanPhaseSpell::PHASE_184,

        PhaseShadowmoonQuianaMaladaar   = TanaanPhaseSpell::PHASE_176,
        PhaseShadowmoonLiadrinOlin      = TanaanPhaseSpell::PHASE_177,

        PhaseBlackrockSlaves            = TanaanPhaseSpell::PHASE_172,
        PhaseBlackrockMainNpcs          = TanaanPhaseSpell::PHASE_173,
        PhaseBlackrockKhadgarRock       = TanaanPhaseSpell::PHASE_177,
        PhaseBlackrockKhadgarUpper      = TanaanPhaseSpell::PHASE_181,
        PhaseBlackrockThaelinLow        = TanaanPhaseSpell::PHASE_184,

        PhaseFinalThaelinCanon          = TanaanPhaseSpell::PHASE_172,
        PhaseFinalSideCanons            = TanaanPhaseSpell::PHASE_175,
        PhaseFinalCanonDeco             = TanaanPhaseSpell::PHASE_176,
    };
}

namespace TanaanKillCredits
{
    enum
    {
        CreditDarkPortalKill            = 78419,
        CreditStatisRuneDestroyed       = 78333,
        CreditEnterGuldanPrison         = 82573,
        CreditAriokEscort               = 78975,
        CreditFindKhadgarAtBridge       = 84456,
        CreditFollowKhadgar             = 80244,
        CreditBloodOrb                  = 78966,
        CreditEasternAllianceCage       = 85142,
        CreditSouthernAllianceCage      = 82871,
        CreditEasternHordeCage          = 78529,
        CreditSouthernHordeCage         = 85141,
        CreditNorthernSpireDisabled     = 82606,
        CreditSouthernSpireDisabled     = 82607,
        CreditAriokGossip               = 78556,
        CreditEnterTheArena             = 82139,
        CreditCombattantSlainInArena    = 82066,
        CreditEscapeKargathArena        = 82140,
        CreditIronHordeSlain            = 80016,
        CreditCombattantSlainAdd        = 82142,
        CreditEscortYrel                = 79794,
        CreditBlackrockGrunt            = 80786,
        CreditOgronWarcrusher           = 80775,
        CreditSpeakWithThaelin          = 80880,
        CreditEscortThaelin             = 80887,
        CreditBoatsReached              = 81024,
        CreditEnterWorldbreakerTurret   = 80929,
        CreditMakeShiftPlunger          = 80520,
        CreditMainCannonTrigger         = 232538
    };
}

namespace TanaanQuestObjectives
{
    enum
    {
        ObjBloodRitualOrbDestroyed      = 273678,
        ObjFollowKhadgar                = 273737,
        ObjBurningBladeDestroyed        = 273438,
        ObjShatteredHandDestroyed       = 273556,
        ObjBlackrockMarkDestroyed       = 273557,
        ObjEasternCageOpened            = 273640,
        ObjSouthernCageOpened           = 273639,
        ObjNorthernSpireDisabled        = 272621,
        ObjSouthernSpireDisabled        = 273946,
        ObjAriokGossip                  = 273075,
        ObjEnterGulDanPrison            = 273930,
        ObjEnterTheArena                = 273758,
        ObjCombattantSlainInArena       = 273713,
        ObjCombattantSlainAddHidden     = 273763,
        ObjUngraMastersOfShadowHorde    = 272982,
        ObjUngraMastersOfShadowAlly     = 272926,
        ObjGurranMastersOfShadowHorde   = 272983,
        ObjGurranMastersOfShadowAlly    = 272927,
        ObjAnkovaMastersOfShadowsHorde  = 272984,
        ObjAnkovaMastersOfShadowsAlly   = 272929,
        ObjIronHordeSlain               = 273041,
        ObjTopOfTheTank                 = 274029
    };
}

namespace TanaanCreatures
{
    enum
    {
        NpcIronGrunt                    = 78883,
        NpcMumper                       = 82188,
        NpcMoriccalas                   = 81990,
        NpcBleedingHollowBloodchosen    = 81895,
        NpcArchmageKhadgarSum           = 80244,
        NpcArchmageKhadgarArena         = 78560,
        NpcBlazeOfGloryTrigger          = 300004,
        NpcKargath                      = 79097,
        NpcShatteredHandBrawler         = 82057,
        NpcHanselHeavyHands             = 78569,
        NpcAriok                        = 78556,
        NpcYrelSummon                   = 79794,
        NpcExarchMaladaar               = 79537,
        NpcLadyLiadrin                  = 79675,
        NpcLadyLiadrinBlackrockSummon   = 81812,
        NpcOlin                         = 79315,
        NpcQiana                        = 79316,
        NpcCordanaFelsong               = 78430,
        NpcThaelinDarkanvil             = 80521,
        NpcGogluk                       = 86039,
        NpcCannonTurret                 = 86690,
        NpcGunTurret                    = 86691,
        NpcThaelinDarkanvilSecond       = 78568,
        NpcBlackRockTrigger             = 300005
    };
}

namespace TanaanGameObjects
{
    enum
    {
        GobWholeBridge          = 231137,
        GobDestroyedBridge      = 231136,
        GobEasternCage          = 229350,
        GobSouthernCage         = 229325,
        GobMarkOfShadowmoon     = 233056,
        GobMarkOfBleedingHollow = 233057,
        GobRingOfFire           = 500003,
        GobIronCageDoor         = 233197
    };
}

enum eFactions
{
    FactionAggressive   = 14,
    FactionFriendly     = 35,
    FactionNeutral      = 7
};

namespace TanaanActions
{
    enum
    {
        ActionTimerSummon       = 1,
        ActionEventSceneArena   = 2,
        ActionSummonHandBrawler = 3
    };
}

namespace TanaanSpells
{
    enum
    {
        SpellTasteOfIronGameAura    = 164042,
        SpellHornOfWinter           = 165762,
        SpellKnockthrough           = 166131,
        SpellArcaneBarrage          = 133123,
        SpellMeteorShower           = 165864,
        SpellCoverOfElune           = 165900,
        SpellCrushingStomp          = 166032,
        SpellCannonBarrage          = 173479,
        SpellMachineGun             = 173502,
        SpellFinaleCinematic        = 177078,
        SpellIronBastionProgressA   = 163524,
        SpellIronBastionProgressB   = 163525,
        SpellIronBastionProgressC   = 163526,
        SpellIronBastionProgressD   = 163527,
        SpellIronBastionProgressE   = 163528,
        SpellIronBastionProgressF   = 163529,
        SpellIronBastionProgressG   = 163530,
        SpellDissociateFaction      = 149211 ///< Originally called "[UNUSED]Talk with Cordana" (unlimited aura dummy)
    };
}

namespace TanaanMovies
{
    enum
    {
        MovieDoorDestruction        = 187,
        MovieEnterPortal            = 199
    };
}

namespace TanaanAchievements
{
    enum
    {
        AchievementWelcomeToDreanorA    = 8921,
        AchievementWelcomeToDreanorH    = 8922,
    };
}

namespace BlazeOfGloryData
{
    enum
    {
        SceneId                 = 934,
        HutsPath                = 10568,
        SpellTrailOfFlameVisual = 165991,
        HutProxDist             = 20
    };
}

#endif
