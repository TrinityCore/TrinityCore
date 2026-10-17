/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "AreaTriggerAI.h"
#include "DB2Stores.h"
#include "Containers.h"
#include "Conversation.h"
#include "ConversationAI.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "GridNotifiers.h"
#include <G3D/Box.h>
#include <G3D/CoordinateFrame.h>
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Position.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Spline.h"
#include "TemporarySummon.h"
#include "G3D/Vector2.h"
#include "sanctum_of_domination.h"

namespace Scripts::Shadowlands::SanctumOfDomination::SylvanasWindrunner
{

// Note: solo/small-group testing behaviour: non-player threat targets can be selected and Withering Fire always shoots 15 arrows. Keep it false outside of testing.
static constexpr bool SoloTesting                              = false;
static constexpr bool TargetPlayersOnly                        = !SoloTesting;

namespace Spells
{
    // Stances
    static constexpr uint32 RangerBowStance                    = 347560;
    static constexpr uint32 RangerDaggersStance                = 348010;

    // Ranger Shot
    static constexpr uint32 RangerShot                         = 347548;

    // Ranger Strike
    static constexpr uint32 RangerStrike                       = 348299;

    // Windrunner
    static constexpr uint32 Windrunner                         = 347504;
    static constexpr uint32 WindrunnerDisappear01              = 352303;
    static constexpr uint32 WindrunnerDisappear02              = 358975;
    static constexpr uint32 WindrunnerSpin                     = 351187;
    static constexpr uint32 WindrunnerMove                     = 347606;

    // Shadow Dagger
    static constexpr uint32 ShadowDaggerCopy                   = 358964;
    static constexpr uint32 ShadowDagger                       = 347670;
    static constexpr uint32 ShadowDaggerMissile                = 348089;
    static constexpr uint32 ShadowDaggerPhaseThree             = 353935;

    // Withering Fire
    static constexpr uint32 WitheringFireCopy                  = 358981;
    static constexpr uint32 WitheringFire                      = 347928;
    static constexpr uint32 BarbedArrow                        = 347807;

    // Desecrating Shot
    static constexpr uint32 DesecratingShot                    = 350652;
    static constexpr uint32 DesecratingShotAreaTrigger         = 348626;
    static constexpr uint32 DesecratingShotJumpFront           = 347957;
    static constexpr uint32 DesecratingShotJumpLeft            = 356191;
    static constexpr uint32 DesecratingShotTriggered           = 348627;

    // Ranger Heartseeker
    static constexpr uint32 RangerHeartseekerAura              = 352649;
    static constexpr uint32 RangerHeartseekerCharge            = 352650;
    static constexpr uint32 RangerHeartseeker                  = 352663;
    static constexpr uint32 RangerHeartseekerPhysicalDamage    = 352651;
    static constexpr uint32 RangerHeartseekerShadowDamage      = 352652;
    static constexpr uint32 BansheeMark                        = 347607;

    // Wailing Arrow
    static constexpr uint32 WailingArrowPointer                = 348064;
    static constexpr uint32 WailingArrow                       = 347609;
    static constexpr uint32 WailingArrowVisualMythic           = 358993;

    // Domination Chains
    static constexpr uint32 DominationChains                   = 349419;
    static constexpr uint32 DominationChainsJump               = 347602;
    static constexpr uint32 DominationArrowShotVisual          = 350426;
    static constexpr uint32 DominationArrowFall                = 352317;
    static constexpr uint32 DominationArrowFallAndVisual       = 352319;
    static constexpr uint32 DominationArrowActivate            = 356650;
    static constexpr uint32 DominationArrowCalamityVisual      = 356769;
    static constexpr uint32 DominationArrowCalamityAreaTrigger = 356624;
    static constexpr uint32 DominationArrowCalamityDamage      = 356649;

    static constexpr uint32 DominationChainPlayer              = 349451;
    static constexpr uint32 DominationChainPeriodic            = 349458;

    // Veil of Darkness (Generic)
    static constexpr uint32 VeilOfDarknessSearcher             = 347720; // Note: this spell should be used as the target searcher for all phases.
    static constexpr uint32 VeilOfDarknessDeselect             = 354366;
    static constexpr uint32 VeilOfDarknessScreenFog            = 354580;
    static constexpr uint32 VeilOfDarknessAbsorbAura           = 347704;
    static constexpr uint32 VeilOfDarknessVisualDummy          = 355749;
    static constexpr uint32 VeilOfDarknessDamage               = 350777;

    // Veil of Darkness (Phase 1)
    static constexpr uint32 VeilOfDarknessPhase1Fade           = 352470;
    static constexpr uint32 VeilOfDarknessPhase1Grow           = 350335;
    static constexpr uint32 VeilOfDarknessPhase1Area           = 357726;
    static constexpr uint32 VeilOfDarknessPhase1               = 347726;

    // Banshee Shroud
    static constexpr uint32 BansheeShroud                      = 350857;

    // Rive
    static constexpr uint32 RiveDisappear                      = 353519;
    static constexpr uint32 Rive                               = 353417;
    static constexpr uint32 RiveFast                           = 353418;
    static constexpr uint32 RiveMarkerAreaTrigger              = 353419;
    static constexpr uint32 RiveChain                          = 353504;
    static constexpr uint32 RiveChainFast                      = 353510;
    static constexpr uint32 RiveAreaTrigger                    = 353375;
    static constexpr uint32 RiveDamage                         = 348145;
    static constexpr uint32 RivenDebris                        = 353413;
    static constexpr uint32 RiveMythicCopy                     = 358431;

    // Banshee Wail
    static constexpr uint32 BansheeWail                        = 348094;
    static constexpr uint32 BansheeWailTriggeredMissile        = 348108;
    static constexpr uint32 BansheeWailMissile                 = 348133;
    static constexpr uint32 BansheeWailSilence                 = 351253;
    static constexpr uint32 BansheeWailMarker                  = 357719;
    static constexpr uint32 BansheeWailExpire                  = 355489;

    static constexpr uint32 TeleportToPhaseTwo                 = 350903;
    static constexpr uint32 TeleportNoIdea                     = 350905; // TARGET_DEST_DB, not sniffed

    // Banshee Form
    static constexpr uint32 BansheeForm                        = 348146;
    static constexpr uint32 BansheeReadyStance                 = 357758;

    // Miscelanea
    static constexpr uint32 GenericAnchorHere                  = 45313;
    static constexpr uint32 GenericDualWield                   = 42459;
    static constexpr uint32 SylvanasRoot                       = 347608;
    static constexpr uint32 SylvanasDisplayPowerSuffering      = 352311;
    static constexpr uint32 SylvanasPowerEnergizeAura          = 352312;

    static constexpr uint32 IntermissionSceneAndStun           = 355488;
    static constexpr uint32 IntermissionScene                  = 359062;
    static constexpr uint32 IntermissionStun                   = 358550;
    static constexpr uint32 PlatformsScene                     = 350943;

    static constexpr uint32 HealthPctCheckIntermission         = 358794;
    static constexpr uint32 ActivateIntermission               = 359429;
    static constexpr uint32 HealthPctCheckFinish               = 359430;

    // Highlord Bolvar Fordragon
    static constexpr uint32 RunicMark                          = 354926;
    static constexpr uint32 RunicMarkTriggered                 = 354927;
    static constexpr uint32 GlyphOfDesintegration              = 354932;

    // Thrall
    static constexpr uint32 Flameaxe                           = 354898;
    static constexpr uint32 Pulverize                          = 354918;
    static constexpr uint32 Stonecrash                         = 357139;
    static constexpr uint32 EarthenGrasp                       = 354900;

    // Jaina Proudmoore
    static constexpr uint32 IceBolt                            = 350002;
    static constexpr uint32 CometBarrage                       = 354938;
    static constexpr uint32 FrigidShards                       = 354933;
    static constexpr uint32 ConeOfCold                         = 350003;
    static constexpr uint32 Blink                              = 362844;
}

namespace Phases
{
    static constexpr uint8 One                                 = 1;
    static constexpr uint8 Intermission                        = 11; // Note: Blizzard uses 11, 21, etc. to set intermissions. In fact, they used 11 as a worldstate data for several spell conditions.
    static constexpr uint8 Two                                 = 2;
    static constexpr uint8 Three                               = 3;
}

namespace EventGroups
{
    static constexpr uint8 Normal                              = 1;
    static constexpr uint8 Windrunner                          = 2;
}

namespace Events
{
    static constexpr uint32 Windrunner                         = 1;
    static constexpr uint32 WitheringFire                      = 2;
    static constexpr uint32 ShadowDagger                       = 3;
    static constexpr uint32 ShadowDaggerTalk                   = 4;
    static constexpr uint32 DesecratingShot                    = 5;
    static constexpr uint32 DesecratingShotLaunch              = 6;
    static constexpr uint32 DesecratingShotLaunchTalk          = 7;
    static constexpr uint32 DominationChains                   = 8;
    static constexpr uint32 WailingArrow                       = 9;
    static constexpr uint32 VeilOfDarkness                     = 10;

    namespace Bolvar
    {
        static constexpr uint32 RunicMark                      = 1;
        static constexpr uint32 GlyphOfDesintegration          = 2;
    }

    namespace Thrall
    {
        static constexpr uint32 Flameaxe                       = 1;
        static constexpr uint32 Pulverize                      = 2;
        static constexpr uint32 StonecrashPhaseOneAndThree     = 3;
        static constexpr uint32 EarthenGrasp                   = 4;
    }
}

namespace Actions
{
    static constexpr int32 ResetMeleeKit                       = 1;
    static constexpr int32 ActivateDominationArrow             = 2;
    static constexpr int32 FinishDominationChains              = 3;
    static constexpr int32 PrepareIntermission                 = 4;
    static constexpr int32 PrepareFinishBoss                   = 5;
}

namespace Texts
{
    static constexpr uint8 Aggro                               = 0;
    static constexpr uint8 Slay                                = 1;
    static constexpr uint8 Disengage                           = 2;
    static constexpr uint8 WindrunnerAnnounce                  = 3;
    static constexpr uint8 ShadowDagger                        = 4;
    static constexpr uint8 DesecratingShot                     = 5;
    static constexpr uint8 WailingArrow                        = 6;
    static constexpr uint8 WailingArrowAnnounce                = 7;
    static constexpr uint8 WailingArrowAnnounceAffected        = 8;
    static constexpr uint8 DominationChains                    = 9;
    static constexpr uint8 DominationChainsAnnounce            = 10;
    static constexpr uint8 VeilOfDarknessAnnounce              = 11;
    static constexpr uint8 VeilOfDarknessPhaseOne              = 12;
    static constexpr uint8 IntermissionBegin                   = 13;
    static constexpr uint8 BansheeWailAnnounce                 = 14;
    static constexpr uint8 IntermissionEnd                     = 15;
    static constexpr uint8 HauntingWaveAnnounce                = 16;
    static constexpr uint8 RuinAnnounce                        = 17;
    static constexpr uint8 WindsOfIcecrownAfter01              = 18;
    static constexpr uint8 VeilOfDarknessPhaseTwoAndThree      = 19;
    static constexpr uint8 BansheeScream                       = 20;
    static constexpr uint8 BansheeScreamAnnounce               = 21;
    static constexpr uint8 WindsOfIcecrownAfter02              = 22;
    static constexpr uint8 StartPhaseThree                     = 23;
    static constexpr uint8 BansheesFury                        = 24;
    static constexpr uint8 RazeAnnounce                        = 25;
    static constexpr uint8 BlackArrow                          = 26;
    static constexpr uint8 BlackArrowAnnounce                  = 27;
    static constexpr uint8 BlackArrowAnnounceAffected          = 28;
    static constexpr uint8 RiveMythicOne                       = 29;
    static constexpr uint8 RiveMythicTwo                       = 30;
}

namespace Conversations
{
    static constexpr uint32 Introduction                       = 17368;
}

namespace ConversationActors
{
    static constexpr uint32 IntroductionSylvanas               = 0;
    static constexpr uint32 IntroductionBolvar                 = 1;
}

namespace SummonGroups
{
    static constexpr uint8 ChampionsFirstPhase                 = 0;
    static constexpr uint8 ChampionsThirdPhase                 = 1;
    static constexpr uint8 ChampionsOutroduction               = 2;
}

namespace Points
{
    static constexpr uint32 Introduction                       = 0;
}

namespace SpellVisualKits
{
    static constexpr uint32 SylvanasIntroductionTalk01         = 150067;
    static constexpr uint32 SylvanasIntroductionTalk02         = 150068;
    static constexpr uint32 SylvanasIntroductionTalk03         = 150069;
    static constexpr uint32 SylvanasIntroductionTalk04         = 150071;
    static constexpr uint32 SylvanasIntroductionTalk05         = 150072;
    static constexpr uint32 SylvanasIntroductionTalk06         = 150070;
    static constexpr uint32 SylvanasIntroductionTalk07         = 150074;
    static constexpr uint32 SylvanasIntroductionTalk08         = 150077;
    static constexpr uint32 SylvanasIntroductionTalk09         = 150076;
    static constexpr uint32 SylvanasIntroductionTalk10         = 150075;
    static constexpr uint32 BolvarIntroductionTalk01           = 150073;

    static constexpr uint32 DominationChainsFinish             = 142405;
    static constexpr uint32 UnsheatheBow                       = 143939;
    static constexpr uint32 UnsheatheBowSpin                   = 142389;
    static constexpr uint32 UnsheatheDaggers                   = 143940;
    static constexpr uint32 UnsheatheDaggersSpin               = 142388;
    static constexpr uint32 VeilOfDarknessPhaseOne             = 142021;
    static constexpr uint32 RiveBreak                          = 145541;
    static constexpr uint32 RiveBreakFast                      = 145608;
    static constexpr uint32 TransformIntoBanshee               = 146063;
    static constexpr uint32 BansheeScreamExpire                = 148298;
    static constexpr uint32 BansheeScreamExpireMythic          = 142507;
    static constexpr uint32 Teleport                           = 150078;
}

namespace SpellVisuals
{
    static constexpr uint32 RangerStrikeRight                  = 106153; // At 1.0f
    static constexpr uint32 RangerStrikeLeft                   = 106160; // At 1.0f
    static constexpr uint32 RangerStrikeFastRight              = 106165; // At 1.0f
    static constexpr uint32 RangerStrikeFastLeft               = 106161; // At 1.0f
    static constexpr uint32 Windrunner01                       = 107722; // At 0.5f
    static constexpr uint32 Windrunner02                       = 110312; // At 0.25f
    static constexpr uint32 Windrunner03                       = 107920; // At 0.25f
    static constexpr uint32 DesecratingArrow                   = 106363; // At 0.40f - 0.12f
    static constexpr uint32 WitheringFirePhaseOne              = 105944; // At 48.0f, false as time
    static constexpr uint32 Heartseeker                        = 107607; // At 36f, false as time
    static constexpr uint32 DominationArrow                    = 107501; // At 2.5f
    static constexpr uint32 DominationArrowSpawn               = 109620; // At 2.5f
    static constexpr uint32 VeilOfDarknessPhaseOneLfrAndNormal = 109159; // At 5.0f
    static constexpr uint32 VeilOfDarknessPhaseOneHeroic       = 107567; // At 5.0f
    static constexpr uint32 VeilOfDarknessPhaseOneMythic       = 109161; // At 5.0f
    static constexpr uint32 VeilOfDarknessSpread               = 108092; // At 0.64f - 0.52f
    static constexpr uint32 TorghastSpireBreak                 = 108070;
    static constexpr uint32 TorghastSpireBreakFast             = 108071;
    static constexpr uint32 RivenDebris                        = 107877; // At 2.203702926635742187f - 1.52007603645324707f
}

namespace Shadowcopy
{
    static constexpr uint8 Index00                             = 0;
    static constexpr uint8 Index01                             = 1;
    static constexpr uint8 Index02                             = 2;
    static constexpr uint8 Index03                             = 3;
    static constexpr uint8 Index04                             = 4;
    static constexpr uint8 Index05                             = 5;
}

namespace DisplayIds
{
    static constexpr uint32 SylvanasElf                        = 101311;
    static constexpr uint32 SylvanasBanshee                    = 101310;
}

namespace VirtualItems
{
    static constexpr uint32 SylvanasDagger                     = 185997;
    static constexpr uint32 SylvanasBow                        = 181374;
}

namespace MeleeCombo
{
    static constexpr uint8 SwitchToMelee                       = 0;
    static constexpr uint8 RangerStrike01                      = 1;
    static constexpr uint8 RangerStrike02                      = 2;
    static constexpr uint8 SwitchToRanged                      = 3;
    static constexpr uint8 Finish                              = 4;
}

namespace AttackTimes
{
    static constexpr uint32 Daggers                            = 900;
    static constexpr uint32 Bow                                = 1750;
}

namespace AreaTriggers
{
    static constexpr uint32 DominationArrow                    = 27683;
}

namespace WindrunnerCounter
{
    static constexpr uint8 One                                 = 1;
    static constexpr uint8 Two                                 = 2;
    static constexpr uint8 Three                               = 3;
    static constexpr uint8 Four                                = 4;
    static constexpr uint8 Five                                = 5;
}

namespace DesecratingShotPattern
{
    static constexpr uint8 None                                = 0;
    static constexpr uint8 Straight                            = 1;
    static constexpr uint8 Scattered                           = 2;
    static constexpr uint8 Wave                                = 3;
    static constexpr uint8 Spiral                              = 4;
    static constexpr uint8 SpiralEnclosed                      = 5;
    static constexpr uint8 Jar                                 = 6;
}

namespace JumpTime
{
    static constexpr uint8 Zero                                = 0;
    static constexpr uint8 One                                 = 1;
    static constexpr uint8 Two                                 = 2;
    static constexpr uint8 Three                               = 3;
    static constexpr uint8 Four                                = 4;
}

namespace CasterKitCombo
{
    static constexpr uint8 NonPowerfulSpell01                  = 0;
    static constexpr uint8 PowerfulSpell01                     = 1;
    static constexpr uint8 NonPowerfulSpell02                  = 2;
    static constexpr uint8 PowerfulSpell02                     = 3;
    static constexpr uint8 NonPowerfulSpell03                  = 4;
}

namespace Positions
{
    static constexpr Position PlatformCenter                   = { 234.9542f, -829.9804f, 4104.986f };

    static constexpr Position Introduction[4] =
    {
        { 231.15799f, -832.816f,   4105.0386f          },
        { 242.00348f, -840.51215f, 4105.0386f          },
        { 241.23091f, -830.0955f,  4105.0386f          },
        { 225.73611f, -844.0746f,  4104.9882f, 1.3613f }
    };

    static constexpr std::array<Position, 8> RiveThrow =
    {
        {
            { 166.617f, -856.656f, 4113.2285f },
            { 208.542f, -761.602f, 4113.2285f },
            { 303.332f, -803.056f, 4113.2285f },
            { 302.793f, -858.021f, 4113.2285f },
            { 183.836f, -777.633f, 4113.2285f },
            { 206.884f, -897.526f, 4113.2285f },
            { 261.473f, -898.365f, 4113.2285f },
            { 287.948f, -778.238f, 4113.2285f }
        }
    };

    static constexpr Position IntermissionFinish               = { 235.1163f, -829.901f, 4105.0386f, 5.4824f };

    static constexpr Position PhaseTwoPre                      = { -14.5625f, -943.441f, 4999.990f, 0.8928f };
}

static constexpr float PlatformRadius                          = 75.0f;

namespace Timers
{
    /* Note: any timer that's set to 90000 means it hasn't been obtained because either there's no proof in sniffs
     * due to the fact that there's no raid group taking so long to switch phase or because DBM or BigWigs do not show
     * timers. Also, it can mean it hasn't been calculated (Black Arrow or Wailing Arrow). We will wait for Dragonflight
     * to correctly obtain the missing ones.
     */

    static constexpr uint32 PhaseOne[4][6][11] =
    {
        // Looking for Raid
        {
            { 8900, 62000, 62000, 61000, 90000                }, // Windrunner
            { 29000, 63900, 63900, 63000, 90000               }, // Domination Chains
            { 34250, 40250, 30250, 33250, 90000               }, // Wailing Arrow (Marker)
            { 40000, 46000, 36500, 39000, 90000               }, // Wailing Arrow
            { 56600, 59300, 59300, 57000, 90000               }  // Veil of Darkness
        },

        // Normal
        {
            { 7800, 54750, 56650, 56400, 90000                }, // Windrunner
            { 25600, 59250, 57150, 57350, 90000               }, // Domination Chains
            { 28350, 40300, 28300, 32100, 90000               }, // Wailing Arrow (Marker)
            { 34350, 46300, 34300, 38100, 90000               }, // Wailing Arrow
            { 50000, 52300, 54800, 55000, 90000               }  // Veil of Darkness
        },

        // Heroic
        {
            { 7000, 51300, 48800, 47500, 52700                }, // Windrunner
            { 23600, 53400, 49600, 53900, 90000               }, // Domination Chains
            { 28900, 32000, 24500, 25700, 31700               }, // Wailing Arrow (Marker)
            { 34900, 38000, 30500, 31700, 37700, 31700        }, // Wailing Arrow
            { 44900, 49400, 46500, 46300, 90000               },  // Veil of Darkness
            { 20100, 19100, 17100, 29900, 4800, 32200, 16100, 12000, 25700, 20600, 4700 } // Ranger's Heartseeker
        },

        // Mythic
        {
            { 6500, 57000, 55100, 56200, 90000                }, // Windrunner
            { 29000, 55000, 64100, 90000, 90000               }, // Domination Chains
            { 34600, 57300, 57300,                            }, // Black Arrow (Marker)
            { 40600, 63300, 63300                             }, // Black Arrow
            { 48000, 43400, 46500, 52400, 90000               }, // Veil of Darkness
            { 20000, 17000, 25000, 17000, 23000, 4000, 31000, 20000, 3000, 8000 } // Ranger's Heartseeker
        }
    };

    namespace PhaseOneRow
    {
        static constexpr uint8 Windrunner                      = 0;
        static constexpr uint8 DominationChains                = 1;
        static constexpr uint8 WailingArrowMarker              = 2; // Black Arrow (Marker) on Mythic
        static constexpr uint8 WailingArrow                    = 3; // Black Arrow on Mythic
        static constexpr uint8 VeilOfDarkness                  = 4;
        static constexpr uint8 RangerHeartseeker               = 5;
    }

    // Note: rows only hold the sniffed casts; past them, the last known timer of the row is repeated instead of reading the zero padding.
    constexpr Milliseconds GetPhaseOneTimer(uint8 difficultyIndex, uint8 row, uint8 count)
    {
        auto const& timers = PhaseOne[difficultyIndex][row];

        size_t index = std::min<size_t>(count, std::size(timers) - 1);
        while (index > 0 && !timers[index])
            --index;

        return Milliseconds(timers[index]);
    }
}

namespace WindrunnerSchedules
{
    struct ScheduledEvent
    {
        uint32 EventId;
        Milliseconds Delay;
    };

    static constexpr ScheduledEvent First[] =
    {
        { Events::ShadowDaggerTalk,          3s + 501ms  },
        { Events::DesecratingShotLaunchTalk, 10s + 491ms },
        { Events::WitheringFire,             1ms         },
        { Events::ShadowDagger,              3s + 141ms  },
        { Events::DesecratingShot,           3s + 141ms  },
        { Events::DesecratingShotLaunch,     5s + 797ms  },
        { Events::WitheringFire,             7s + 750ms  },
        { Events::DesecratingShot,           8s + 200ms  },
        { Events::DesecratingShotLaunch,     10s + 391ms }
    };

    static constexpr ScheduledEvent Second[] =
    {
        { Events::ShadowDaggerTalk,          3s + 391ms  },
        { Events::DesecratingShotLaunchTalk, 11s + 256ms },
        { Events::WitheringFire,             1ms         },
        { Events::ShadowDagger,              3s + 31ms   },
        { Events::DesecratingShot,           3s + 31ms   },
        { Events::DesecratingShotLaunch,     6s + 31ms   },
        { Events::WitheringFire,             8s + 422ms  },
        { Events::DesecratingShot,           8s + 422ms  },
        { Events::DesecratingShotLaunch,     11s + 156ms }
    };

    static constexpr ScheduledEvent Third[] =
    {
        { Events::ShadowDaggerTalk,          361ms       },
        { Events::DesecratingShotLaunchTalk, 11s + 319ms },
        { Events::ShadowDagger,              1ms         },
        { Events::DesecratingShot,           500ms       },
        { Events::DesecratingShotLaunch,     2s + 750ms  },
        { Events::WitheringFire,             5s + 438ms  },
        { Events::ShadowDagger,              8s + 594ms  },
        { Events::DesecratingShot,           9s          },
        { Events::DesecratingShotLaunch,     11s + 219ms },
        { Events::WitheringFire,             13s + 78ms  }
    };

    static constexpr ScheduledEvent Fourth[] =
    {
        { Events::ShadowDaggerTalk,          860ms       },
        { Events::WitheringFire,             1ms         },
        { Events::ShadowDagger,              500ms       },
        { Events::DesecratingShot,           3s + 141ms  },
        { Events::WitheringFire,             5ms         },
        { Events::DesecratingShot,           500ms       },
        { Events::WitheringFire,             5ms         }
    };

    // @Modox: I won't be pushing the fifth one until I'm certain we're not changing how I handle these.
    static constexpr std::span<ScheduledEvent const> ByCast[]  = { First, Second, Third, Fourth };
}

namespace DesecratingShotDistances
{
    static constexpr float Spiral[10] =
    {
        0.0f,
        3.750014f,
        7.464427f,
        11.092868f,
        14.568754f,
        17.0809464f,
        20.716787f,
        23.179819f,
        25.079182f,
        26.294075f
    };

    static constexpr float SpiralEnclosed[10] =
    {
        0.0f,
        3.749988f,
        7.448239f,
        10.986361f,
        14.186308f,
        16.796705f,
        18.506325f,
        18.985258f,
        17.966669f,
        15.394481f
    };
}

namespace DesecratingShotGeometry
{
    /* after hours of research and Pitagoras, each part of the arrow has a different travel speed. The angles are relative
       to where the arrow points to and the distances are measured from its tip. */
    struct ArrowPart
    {
        float Angle;
        float Distance;
        uint32 MarkerDelayPerStep;
        float TravelSpeed;
    };

    static constexpr float BackLeft                            = 135.0f * float(M_PI) / 180;
    static constexpr float BackRight                           = -135.0f * float(M_PI) / 180;

    static constexpr ArrowPart StraightArrow[] =
    {
        { 0.0f,      0.0f,    25, 0.245000004768371f },
        { BackLeft,  2.8284f, 35, 0.384000003337860f },
        { BackRight, 2.8284f, 35, 0.358999997377395f },
        { BackLeft,  5.6568f, 50, 0.517000019550323f },
        { BackRight, 5.6568f, 50, 0.470999985933303f }
    };

    static constexpr ArrowPart ScatteredArrow[] =
    {
        { 0.0f,      0.0f,      5,    0.245000004768371f },
        { BackLeft,  5.196156f, 500,  0.384000003337860f },
        { BackRight, 5.196156f, 1000, 0.470999985933303f }
    };

    static constexpr float BaseTravelSpeed                     = 0.245000004768371f;
    static constexpr float SpiralCenterTravelSpeed             = 0.165999993681907653f;

    static constexpr float SpiralArmAngles[3]                  = { 120.0f, 240.0f, 360.0f };

    static constexpr float WaveSide                            = 90.0f * float(M_PI) / 180;
    static constexpr float WavePointSpacing                    = 3.999978f;

    // indexed by the copy drawing the line: each line is further behind Sylvanas and its markers fall slower.
    static constexpr float WaveLineOffsets[3]                  = { 9.999982f, 5.000011f, 0.0f };
    static constexpr Milliseconds WaveFirstMarkerDelays[3]     = { 78ms, 47ms, 0ms };
    static constexpr uint32 WaveMarkerDelayPerStep[3]          = { 70, 60, 50 };
}

Creature* GetShadowcopy(InstanceScript const* instance, uint8 copyIndex)
{
    return instance->instance->GetCreature(instance->GetGuidData(DATA_SYLVANAS_SHADOWCOPY_00 + copyIndex));
}

struct npc_sylvanas_windrunner_shadowcopy;

npc_sylvanas_windrunner_shadowcopy* GetShadowcopyAI(InstanceScript const* instance, uint8 copyIndex);

constexpr bool IsOnPlatform(Position const& pos)
{
    return Positions::PlatformCenter.IsInDist2d(&pos, PlatformRadius);
}

/* the actor changes below are delayed through the actor's own event processor, so KillAllEvents cancels the pending ones.
   Sylvanas keeps her victim while her attack is paused, and has her swing timer reset when it resumes. */
void ScheduleAttackPause(Unit* actor, Milliseconds delay)
{
    actor->m_Events.AddEventAtOffset([actor]
    {
        actor->InterruptNonMeleeSpells(false);
        actor->GetMotionMaster()->Clear();
        actor->StopMoving();

        if (actor->GetEntry() != BOSS_SYLVANAS_WINDRUNNER)
            actor->AttackStop();

        actor->ToCreature()->SetReactState(REACT_PASSIVE);
    }, delay);
}

void ScheduleAttackResume(Unit* actor, Milliseconds delay)
{
    actor->m_Events.AddEventAtOffset([actor]
    {
        if (actor->ToCreature()->GetReactState() != REACT_AGGRESSIVE)
            actor->ToCreature()->SetReactState(REACT_AGGRESSIVE);

        if (actor->GetEntry() != BOSS_SYLVANAS_WINDRUNNER)
            return;

        if (!actor->GetVictim())
            if (Unit* target = actor->GetAI()->SelectTarget(SelectTargetMethod::MaxThreat, 0, 500.0f, true))
                actor->GetAI()->AttackStart(target);

        actor->setAttackTimer(WeaponAttackType::BASE_ATTACK, 0);
    }, delay);
}

void ScheduleSheath(Unit* actor, SheathState sheath, Milliseconds delay)
{
    actor->m_Events.AddEventAtOffset([actor, sheath] { actor->SetSheath(sheath); }, delay);
}

void ScheduleBaseAttackTime(Unit* actor, uint32 attackTime, Milliseconds delay)
{
    actor->m_Events.AddEventAtOffset([actor, attackTime] { actor->SetBaseAttackTime(BASE_ATTACK, attackTime); }, delay);
}

void ScheduleNameplateOnRidingCopy(Unit* actor, Milliseconds delay)
{
    actor->m_Events.AddEventAtOffset([actor]
    {
        if (InstanceScript* instance = actor->GetInstanceScript())
            if (Creature const* ridingCopy = instance->GetCreature(DATA_SYLVANAS_SHADOWCOPY_RIDING))
                actor->SetNameplateAttachToGUID(ridingCopy->GetGUID());
    }, delay);
}

void ScheduleNameplateReset(Unit* actor, Milliseconds delay)
{
    actor->m_Events.AddEventAtOffset([actor] { actor->SetNameplateAttachToGUID(ObjectGuid::Empty); }, delay);
}

struct SequenceStep
{
    Milliseconds Delay;
    std::function<void()> Action;
};

/* runs the steps one after another, every delay counting from the previous step, so cancelling the scheduler drops the rest
   of the sequence. */
void ScheduleSequence(TaskScheduler& scheduler, std::vector<SequenceStep> steps)
{
    struct Runner
    {
        std::shared_ptr<std::vector<SequenceStep> const> Steps;
        size_t Index;

        void operator()(TaskContext& context) const
        {
            (*Steps)[Index].Action();

            if (Index + 1 < Steps->size())
                context.Schedule((*Steps)[Index + 1].Delay, Runner{ Steps, Index + 1 });
        }
    };

    if (steps.empty())
        return;

    Milliseconds const firstDelay = steps.front().Delay;
    scheduler.Schedule(firstDelay, Runner{ std::make_shared<std::vector<SequenceStep> const>(std::move(steps)), 0 });
}

struct DesecratingArrow
{
    constexpr DesecratingArrow(Position const& pos, uint8 step, float travelSpeed) : Pos(pos), Step(step), TravelSpeed(travelSpeed) {}

    Position const Pos;
    uint8 const Step;
    float const TravelSpeed;
};

namespace EventHelpers
{
    constexpr uint8 GetTimerIndexForDifficulty(Difficulty difficulty)
    {
        switch (difficulty)
        {
            case DIFFICULTY_LFR_NEW:
                return 0;
            case DIFFICULTY_NORMAL_RAID:
                return 1;
            case DIFFICULTY_HEROIC_RAID:
                return 2;
            case DIFFICULTY_MYTHIC_RAID:
                return 3;
            default:
                return 0;
        }
    }

    uint8 GetDifficultyForTimer(WorldObject const* object)
    {
        return GetTimerIndexForDifficulty(object->GetMap()->GetDifficultyID());
    }

    uint8 GetWorldStatePhase(WorldObject const* object)
    {
        return object->GetMap()->GetWorldStateValue(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE);
    }
}

namespace PositionHelpers
{
    Position GetWindrunnerPosition(Unit* unit, float dist)
    {
        Position pos = unit->GetNearPosition(-dist, 0.0f);
        pos.m_positionZ = EventHelpers::GetWorldStatePhase(unit) == Phases::Three ? 5671.90f : 4105.00f;
        return pos;
    }

    Position const GetDominationChainsJumpPosition(Creature const* unit, uint8 jumpCount)
    {
        /* Note: we create one cluster per player found. Each player will compare itself with the rest and adding neighbours
         * if they're at 15.0f yards or closer. Then, we iterate through all clusters and only set the biggest size. Then,
         * we iterate through all clusters again until we find the same one. Finally, we get all the players' positionX
         * and positionY of such cluster and divide them by the cluster's size to obtain the middle common point of the cluster.
         * Lastly, we relocate taking middle of platform into account and return it as usable position.
         */

        using Cluster = std::set<Player const*>;

        std::list<Player*> targets;

        unit->GetPlayerListInGrid(targets, 175.0f);

        std::map<ObjectGuid, Cluster> clusterMap;

        // Note: we compare every player with one another; if they find any at float(neighboorDistance) or closer, they're considered "neighbours".
        for (Player const* player : targets)
        {
            Cluster neighboor;

            for (Player const* secondPlayer : targets)
            {
                if (player->IsWithinDist(secondPlayer, 15.0f))
                    neighboor.insert(secondPlayer);
            }

            clusterMap[player->GetGUID()] = Cluster();
            clusterMap[player->GetGUID()].insert(player);

            for (Player const* secondPlayer : neighboor)
                clusterMap[player->GetGUID()].insert(secondPlayer);
        }

        size_t clusterSize = 0;

        // Note: let's compare each cluster's size in our clusterMap and set the biggest one as our variable.
        for (auto const& cluster : clusterMap)
        {
            if (cluster.second.size() > clusterSize)
                clusterSize = cluster.second.size();
        }

        Position clusterPos;

        // Note: let's find our biggest cluster and get the middle points of each player inside the cluster.
        for (auto const& cluster : clusterMap)
        {
            if (clusterSize && cluster.second.size() != clusterSize)
                continue;

            float posX = 0.0f;
            float posY = 0.0f;

            for (Player const* player : cluster.second)
            {
                posX += player->GetPositionX();
                posY += player->GetPositionY();
            }

            posX /= uint32(clusterSize);
            posY /= uint32(clusterSize);

            clusterPos.m_positionX = posX;
            clusterPos.m_positionY = posY;
            clusterPos.m_positionZ = unit->GetPositionZ();
        }

        Positions::PlatformCenter.RelocatePositionByAngle(clusterPos, float(frand(10.0f, 12.5f) * jumpCount), clusterPos.GetAbsoluteAngle(&Positions::PlatformCenter) + frand(-1.0f, 1.0f), true);

        return clusterPos;
    }
}

// 176369 - Sylvanas Shadowcopy (Fight)
struct npc_sylvanas_windrunner_shadowcopy : public ScriptedAI
{
    npc_sylvanas_windrunner_shadowcopy(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) {}

    void JustAppeared() override
    {
        me->SetImmuneToAll(true, true);
        me->SetUninteractible(true);
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override
    {
        _sequences.CancelAll();
        _scheduler.CancelAll();

        _desecratingArrows.clear();
        _dominationChains = DominationChainsState();
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != EFFECT_MOTION_TYPE || id != EVENT_JUMP)
            return;

        DoCastSelf(Spells::GenericAnchorHere, true);

        if (!_dominationChains.Active)
            return;

        ScheduleSequence(_sequences,
        {
            { 150ms, [this] { DoCastSelf(Spells::DominationArrowShotVisual, true); } },
            { 50ms,  [this] { SpawnDominationArrows(); } }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
        _sequences.Update(diff);
    }

    bool IsOnDominationChains() const
    {
        return _dominationChains.Active;
    }

    void StopDominationChains()
    {
        _dominationChains.Active = false;
    }

    void PrepareForIntermission()
    {
        _sequences.CancelAll();
    }

    void ReturnTo(Position const& pos) const
    {
        me->NearTeleportTo(pos);
    }

    void StartWitheringFire()
    {
        // we need to find a way to make this dynamic because the size changes per windrunner cast, difficulty and raid size.
        std::shared_ptr<std::vector<ObjectGuid> const> targets = SelectChoreographyTargets();
        if (!targets)
            return;

        TeleportNearTarget(Shadowcopy::Index00, *targets, 0, 15.0f, SpellVisuals::Windrunner02);

        ScheduleSequence(_sequences,
        {
            { 48ms,  [this, targets] { CastAtTarget(Shadowcopy::Index00, Spells::WitheringFireCopy, *targets, 0); } },
            { 204ms, [this, targets] { TeleportNearTarget(Shadowcopy::Index00, *targets, 1, 10.0f, SpellVisuals::Windrunner02); } },
            { 75ms,  [this, targets] { CastAtTarget(Shadowcopy::Index00, Spells::WitheringFireCopy, *targets, 1); } },
            { 219ms, [this, targets]
            {
                TeleportNearTarget(Shadowcopy::Index00, *targets, 2, 10.0f, SpellVisuals::Windrunner02);
                TeleportNearTarget(Shadowcopy::Index01, *targets, 0, 15.0f);
            } },
            { 75ms,  [this, targets]
            {
                ExecuteWitheringFire(Shadowcopy::Index01, JumpTime::Zero);
                CastAtTarget(Shadowcopy::Index00, Spells::WitheringFireCopy, *targets, 2);
                PlayVisualToSylvanas(Shadowcopy::Index01, SpellVisuals::Windrunner02, 0.25f);
            } },
            { 234ms, [this, targets]
            {
                TeleportNearTarget(Shadowcopy::Index00, *targets, 3, 10.0f, SpellVisuals::Windrunner02);
                TeleportNearTarget(Shadowcopy::Index01, *targets, 1, 15.0f);
            } },
            { 75ms,  [this, targets]
            {
                ExecuteWitheringFire(Shadowcopy::Index01, JumpTime::One);
                CastAtTarget(Shadowcopy::Index00, Spells::WitheringFireCopy, *targets, 3);
                PlayVisualToSylvanas(Shadowcopy::Index01, SpellVisuals::Windrunner02, 0.25f);
            } },
            { 75ms,  [this] { TeleportToSylvanas(Shadowcopy::Index00); } },
            { 75ms,  [this, targets]
            {
                AttachSylvanasNameplate(me->GetGUID());

                if (Unit* target = GetTargetAt(*targets, 2))
                    me->CastSpell(PositionHelpers::GetWindrunnerPosition(target, 10.0f), Spells::WindrunnerMove);
            } },
            { 175ms, [this, targets]
            {
                ExecuteWitheringFire(Shadowcopy::Index00, JumpTime::Two);
                TeleportNearTarget(Shadowcopy::Index01, *targets, 4, 15.0f, SpellVisuals::Windrunner02);
            } },
            { 100ms, [this, targets]
            {
                CastAtTarget(Shadowcopy::Index01, Spells::WitheringFireCopy, *targets, 4);
                PlayVisualToSylvanas(Shadowcopy::Index00, SpellVisuals::Windrunner02, 0.25f);
            } },
            { 103ms, [this]
            {
                if (Creature const* sylvanas = GetSylvanas())
                    me->CastSpell(sylvanas->GetPosition(), Spells::WindrunnerMove);
            } },
            { 75ms,  [this, targets] { TeleportNearTarget(Shadowcopy::Index01, *targets, 3, 15.0f); } },
            { 140ms, [this]
            {
                ExecuteWitheringFire(Shadowcopy::Index01, JumpTime::Three);
                PlayVisualToSylvanas(Shadowcopy::Index01, SpellVisuals::Windrunner02, 0.25f);
                AttachSylvanasNameplate(ObjectGuid::Empty);
            } },
            { 125ms, [this, targets] { TeleportNearTarget(Shadowcopy::Index01, *targets, 4, 15.0f); } },
            { 75ms,  [this]
            {
                ExecuteWitheringFire(Shadowcopy::Index01, JumpTime::Four);
                PlayVisualToSylvanas(Shadowcopy::Index01, SpellVisuals::Windrunner02, 0.25f);
            } },
            { 100ms, [this] { TeleportToSylvanas(Shadowcopy::Index01); } }
        });
    }

    void StartShadowDagger()
    {
        std::shared_ptr<std::vector<ObjectGuid> const> targets = SelectChoreographyTargets();
        if (!targets)
            return;

        TeleportNearTarget(Shadowcopy::Index00, *targets, 0, 3.5f, SpellVisuals::Windrunner01);

        ScheduleSequence(_sequences,
        {
            { 48ms,  [this, targets] { CastAtTarget(Shadowcopy::Index00, Spells::ShadowDaggerCopy, *targets, 0); } },
            { 78ms,  [this, targets] { TeleportNearTarget(Shadowcopy::Index01, *targets, 1, 3.5f); } },
            { 16ms,  [this, targets] { CastAtTarget(Shadowcopy::Index01, Spells::ShadowDaggerCopy, *targets, 1); } },
            { 78ms,  [this, targets] { TeleportNearTarget(Shadowcopy::Index02, *targets, 2, 3.5f); } },
            { 31ms,  [this, targets] { CastAtTarget(Shadowcopy::Index02, Spells::ShadowDaggerCopy, *targets, 2); } },
            { 31ms,  [this, targets]
            {
                CastShadowDagger(*targets, 0);
                PlayVisualBetweenCopies(Shadowcopy::Index00, Shadowcopy::Index01, SpellVisuals::Windrunner01, 0.5f);
            } },
            { 63ms,  [this, targets]
            {
                TeleportNearTarget(Shadowcopy::Index03, *targets, 3, 3.5f);

                if (Creature* shadowCopy4 = GetShadowcopy(_instance, Shadowcopy::Index04))
                {
                    AttachSylvanasNameplate(shadowCopy4->GetGUID());

                    if (Creature const* shadowCopy2 = GetShadowcopy(_instance, Shadowcopy::Index02))
                        shadowCopy4->CastSpell(shadowCopy2->GetPosition(), Spells::WindrunnerMove);
                }
            } },
            { 15ms,  [this, targets] { CastAtTarget(Shadowcopy::Index03, Spells::ShadowDaggerCopy, *targets, 3); } },
            { 32ms,  [this, targets]
            {
                CastShadowDagger(*targets, 1);
                PlayVisualBetweenCopies(Shadowcopy::Index01, Shadowcopy::Index02, SpellVisuals::Windrunner01, 0.5f);
            } },
            { 62ms,  [this, targets] { TeleportNearTarget(Shadowcopy::Index05, *targets, 4, 3.5f); } },
            { 16ms,  [this, targets] { CastAtTarget(Shadowcopy::Index05, Spells::ShadowDaggerCopy, *targets, 4); } },
            { 31ms,  [this, targets]
            {
                CastShadowDagger(*targets, 2);
                PlayVisualBetweenCopies(Shadowcopy::Index02, Shadowcopy::Index03, SpellVisuals::Windrunner01, 0.5f);
            } },
            { 109ms, [this, targets]
            {
                CastShadowDagger(*targets, 3);
                PlayVisualBetweenCopies(Shadowcopy::Index03, Shadowcopy::Index05, SpellVisuals::Windrunner01, 0.5f);
            } },
            { 78ms,  [this]
            {
                Creature* shadowCopy4 = GetShadowcopy(_instance, Shadowcopy::Index04);
                Creature const* sylvanas = GetSylvanas();
                if (shadowCopy4 && sylvanas)
                    shadowCopy4->CastSpell(sylvanas->GetPosition(), Spells::WindrunnerMove);
            } },
            { 32ms,  [this, targets]
            {
                CastShadowDagger(*targets, 4);
                PlayVisualToSylvanas(Shadowcopy::Index05, SpellVisuals::Windrunner01, 0.5f);
            } },
            { 172ms, [this] { AttachSylvanasNameplate(ObjectGuid::Empty); } }
        });
    }

    void StartDominationChains()
    {
        Creature* sylvanas = GetSylvanas();
        if (!sylvanas)
            return;

        _dominationChains.Prepare(GetDominationArrowCount());
        sylvanas->CastSpell(sylvanas, Spells::WindrunnerDisappear02);

        ScheduleSequence(_sequences,
        {
            { 20ms,  [this]
            {
                if (Creature* sylvanas = GetSylvanas())
                {
                    sylvanas->CastSpell(sylvanas, Spells::DominationChains);
                    sylvanas->SetNameplateAttachToGUID(me->GetGUID());
                }
            } },
            { 15ms,  [this] { JumpToDominationChainsPosition(JumpTime::One); } },
            { 120ms, [this]
            {
                if (Creature* sylvanas = GetSylvanas())
                {
                    sylvanas->AI()->Talk(Texts::DominationChainsAnnounce);
                    sylvanas->AI()->Talk(EventHelpers::GetWorldStatePhase(me) == Phases::One ? Texts::DominationChains : Texts::IntermissionBegin);
                }
            } },
            { 616ms, [this] { TeleportSylvanasToJumpPosition(); } },
            { 62ms,  [this] { JumpToDominationChainsPosition(JumpTime::Two); } },
            { 750ms, [this] { TeleportSylvanasToJumpPosition(); } },
            { 63ms,  [this] { JumpToDominationChainsPosition(JumpTime::Three); } },
            { 560ms, [this] { TeleportSylvanasToJumpPosition(); } },
            { 80ms,  [this] { TeleportToSylvanas(Shadowcopy::Index00); } },
            { 220ms, [this]
            {
                if (Creature* sylvanas = GetSylvanas())
                {
                    sylvanas->RemoveAura(Spells::WindrunnerDisappear02);
                    sylvanas->SetNameplateAttachToGUID(ObjectGuid::Empty);
                }
            } },
            { 5s,    [this]
            {
                if (Creature* sylvanas = GetSylvanas())
                    sylvanas->AI()->DoAction(Actions::FinishDominationChains);
            } }
        });
    }

    void StoreDesecratingShot(Position const& pos, uint8 step, float travelSpeed)
    {
        _desecratingArrows.emplace_back(pos, step, travelSpeed);
    }

    void StartDesecratingShotEvent(uint8 pattern, uint8 copyIndex)
    {
        Creature* sylvanas = GetSylvanas();
        if (!sylvanas)
            return;

        switch (pattern)
        {
            case DesecratingShotPattern::Straight:
            case DesecratingShotPattern::Scattered:
            {
                sylvanas->CastSpell(sylvanas, Spells::SylvanasRoot, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2550));
                sylvanas->CastSpell(sylvanas, Spells::WindrunnerDisappear01, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 633));

                me->NearTeleportTo(sylvanas->GetNearPosition(-5.0f, 0.0f));

                _scheduler.Schedule(5ms, [this](TaskContext /*task*/)
                {
                    me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 5.048f, me->GetOrientation());
                });

                _scheduler.Schedule(15ms, [this](TaskContext /*task*/)
                {
                    if (Creature* sylvanas = GetSylvanas())
                        sylvanas->SendPlayOrphanSpellVisual(me->GetPosition(), SpellVisuals::Windrunner01, 0.5f, true);
                });

                _scheduler.Schedule(63ms, [this](TaskContext /*task*/)
                {
                    DoCastSelf(Spells::DesecratingShotJumpFront);

                    AttachSylvanasNameplate(me->GetGUID());
                });

                _scheduler.Schedule(146ms, [this](TaskContext /*task*/)
                {
                    if (Creature const* sylvanas = GetSylvanas())
                        me->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SpellVisuals::Windrunner01, 0.5f, true, false);
                });

                _scheduler.Schedule(193ms, [this](TaskContext /*task*/)
                {
                    ReleaseDesecratingShots();
                });

                _scheduler.Schedule(633ms, [this](TaskContext /*task*/)
                {
                    _desecratingArrows.clear();

                    AttachSylvanasNameplate(ObjectGuid::Empty);
                });
                break;
            }

            case DesecratingShotPattern::Wave:
            case DesecratingShotPattern::Spiral:
            case DesecratingShotPattern::SpiralEnclosed:
            {
                if (_desecratingArrows.empty())
                    return;

                // the wave is shot from its first arrow and the spirals from their center, which is always stored last.
                Position const& shootingPoint = pattern == DesecratingShotPattern::Wave ? _desecratingArrows.front().Pos : _desecratingArrows.back().Pos;

                Position const shootingPos(shootingPoint.GetPositionX(), shootingPoint.GetPositionY(), 4112.0386f);

                me->NearTeleportTo(shootingPos);

                if (copyIndex == Shadowcopy::Index02)
                {
                    sylvanas->CastSpell(sylvanas, Spells::SylvanasRoot, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2950));
                    sylvanas->CastSpell(sylvanas, Spells::WindrunnerDisappear01, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 1204));

                    sylvanas->SendPlayOrphanSpellVisual(shootingPos, SpellVisuals::Windrunner01, 0.5f, true, false);
                }
                else
                {
                    // the visual comes from the copy that shot right before this one.
                    if (Creature* previousCopy = GetShadowcopy(_instance, copyIndex + 1))
                        previousCopy->SendPlayOrphanSpellVisual(shootingPos, SpellVisuals::Windrunner01, 0.5f, true, false);
                }

                _scheduler.Schedule(215ms, [this, shootingPos](TaskContext /*task*/)
                {
                    AttachSylvanasNameplate(me->GetGUID());
                    me->CastSpell(shootingPos, Spells::DesecratingShotJumpFront, true);
                });

                _scheduler.Schedule(240ms, [this](TaskContext /*task*/)
                {
                    ReleaseDesecratingShots();
                });

                _scheduler.Schedule(450ms, [this, copyIndex](TaskContext /*task*/)
                {
                    _desecratingArrows.clear();

                    if (copyIndex != Shadowcopy::Index00)
                        return;

                    if (Creature const* sylvanas = GetSylvanas())
                        me->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), SpellVisuals::Windrunner02, 0.5f, true, false);

                    AttachSylvanasNameplate(ObjectGuid::Empty);
                });
                break;
            }

            case DesecratingShotPattern::Jar:
                break;

            default:
                break;
        }
    }

private:
    struct DominationChainsState
    {
        Position JumpPos;
        std::array<uint32, 3> ArrowsPerJump = { };
        uint8 Jumps = 0;
        bool Active = false;

        // the arrows are split as evenly as possible between the three jumps, in a random order.
        void Prepare(uint32 totalArrows)
        {
            uint32 const baseArrowsPerJump = totalArrows / 3;

            ArrowsPerJump.fill(baseArrowsPerJump);

            uint32 const remainder = totalArrows - baseArrowsPerJump * 3;

            for (uint32 i = 0; i < remainder; ++i)
                ++ArrowsPerJump[i];

            Trinity::Containers::RandomShuffle(ArrowsPerJump);

            Jumps = 0;
            Active = true;
        }

        uint32 NextJumpArrows()
        {
            return Jumps < ArrowsPerJump.size() ? ArrowsPerJump[Jumps++] : 0;
        }
    };

    Creature* GetSylvanas() const
    {
        return _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
    }

    // SelectTargetList can return fewer targets than the choreography uses; the steps of the missing ones are skipped.
    Unit* GetTargetAt(std::vector<ObjectGuid> const& targetGUIDs, size_t index) const
    {
        return index < targetGUIDs.size() ? ObjectAccessor::GetUnit(*me, targetGUIDs[index]) : nullptr;
    }

    // the targets are shared by the steps of one cast, so overlapping casts don't affect each other.
    std::shared_ptr<std::vector<ObjectGuid> const> SelectChoreographyTargets() const
    {
        Creature* sylvanas = GetSylvanas();
        if (!sylvanas)
            return nullptr;

        std::list<Unit*> targets;
        sylvanas->GetAI()->SelectTargetList(targets, 5, SelectTargetMethod::Random, 0, 500.0f, TargetPlayersOnly, true);

        std::vector<ObjectGuid> targetGUIDs;
        for (Unit const* target : targets)
            targetGUIDs.push_back(target->GetGUID());

        Trinity::Containers::RandomShuffle(targetGUIDs);

        return std::make_shared<std::vector<ObjectGuid> const>(std::move(targetGUIDs));
    }

    void TeleportShadowcopyToPosition(Position const& chosenPos, uint32 spellVisual = 0) const
    {
        Creature* sylvanas = GetSylvanas();
        if (!sylvanas)
            return;

        // HACKFIX: remove orientation when SPELL_ATTR12_UNK11 (Face Destination) is implemented.
        me->NearTeleportTo(chosenPos.GetPositionX(), chosenPos.GetPositionY(), chosenPos.GetPositionZ(), chosenPos.GetAbsoluteAngle(sylvanas->GetPosition()));

        if (spellVisual > 0)
        {
            float const speed = spellVisual == SpellVisuals::Windrunner01 ? 0.5f : 0.25f;

            sylvanas->SendPlayOrphanSpellVisual(chosenPos, spellVisual, speed, true, false);
        }
    }

    void JumpShadowcopyToPosition(Position const& chosenPos, uint32 spellVisual) const
    {
        me->CastSpell(chosenPos, Spells::DominationChainsJump);

        float const speed = spellVisual == SpellVisuals::Windrunner01 ? 0.5f : 0.25f;

        if (Creature* sylvanas = GetSylvanas())
            sylvanas->SendPlayOrphanSpellVisual(chosenPos, spellVisual, speed, true, false);
    }

    void TeleportNearTarget(uint8 copyIndex, std::vector<ObjectGuid> const& targetGUIDs, size_t targetIndex, float distance, uint32 spellVisual = 0) const
    {
        Unit* target = GetTargetAt(targetGUIDs, targetIndex);
        if (!target)
            return;

        if (npc_sylvanas_windrunner_shadowcopy const* shadowCopyAI = GetShadowcopyAI(_instance, copyIndex))
            shadowCopyAI->TeleportShadowcopyToPosition(PositionHelpers::GetWindrunnerPosition(target, distance), spellVisual);
    }

    void TeleportToSylvanas(uint8 copyIndex) const
    {
        Creature const* sylvanas = GetSylvanas();
        npc_sylvanas_windrunner_shadowcopy const* shadowCopyAI = GetShadowcopyAI(_instance, copyIndex);
        if (sylvanas && shadowCopyAI)
            shadowCopyAI->TeleportShadowcopyToPosition(sylvanas->GetPosition());
    }

    void CastAtTarget(uint8 copyIndex, uint32 spellId, std::vector<ObjectGuid> const& targetGUIDs, size_t targetIndex) const
    {
        Unit const* target = GetTargetAt(targetGUIDs, targetIndex);
        Creature* shadowCopy = GetShadowcopy(_instance, copyIndex);
        if (target && shadowCopy)
            shadowCopy->CastSpell(target->GetPosition(), spellId, true);
    }

    void CastShadowDagger(std::vector<ObjectGuid> const& targetGUIDs, size_t targetIndex) const
    {
        Creature* sylvanas = GetSylvanas();
        Unit* target = GetTargetAt(targetGUIDs, targetIndex);
        if (sylvanas && target)
            sylvanas->CastSpell(target, Spells::ShadowDagger, true);
    }

    void ExecuteWitheringFire(uint8 copyIndex, uint8 jumpTime) const
    {
        if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyAI(_instance, copyIndex))
            shadowCopyAI->ExecuteWitheringFirePhaseOne(jumpTime);
    }

    void ExecuteWitheringFirePhaseOne(uint8 jumpTime)
    {
        // number of casts is dependent on raid's difficulty and size: if mythic, 15; if not, half the raid (min. 5, max. 15).
        uint32 const totalWitheringFires = SoloTesting || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID ? 15
            : std::clamp<uint32>(uint32(std::ceil(me->GetMap()->GetPlayersCountExceptGMs() / 2.0f)), 5, 15);

        /* each copy (of a total of 5) casts up to 2 Withering Fires (if totalWitheringFires is higher than 11), except the third (index starts at 0),
           which casts the remaining because that's the copy where Sylvanas cosmetically jumps to. */
        uint32 const currentWitheringFires = jumpTime == JumpTime::Two
            ? (totalWitheringFires > 11 ? totalWitheringFires - 8 : totalWitheringFires - 4)
            : (totalWitheringFires > 11 ? 2 : 1);

        std::list<Unit*> targetedPlayers;
        if (Creature* sylvanas = GetSylvanas())
            sylvanas->GetAI()->SelectTargetList(targetedPlayers, currentWitheringFires, SelectTargetMethod::Random, 0, 500.0f, TargetPlayersOnly, true);

        for (Unit* target : targetedPlayers)
        {
            me->SendPlaySpellVisual(target, SpellVisuals::WitheringFirePhaseOne, 0, 0, 48.0f, false);

            uint32 const timer = uint32(me->GetDistance(target) * 0.02083 * 1000);

            _scheduler.Schedule(Milliseconds(timer), [this, targetGUID = target->GetGUID()](TaskContext /*task*/)
            {
                Creature* sylvanas = GetSylvanas();
                Unit* witheringFireTarget = ObjectAccessor::GetUnit(*me, targetGUID);
                if (sylvanas && witheringFireTarget)
                    sylvanas->CastSpell(witheringFireTarget, Spells::WitheringFire);
            });
        }
    }

    void PlayVisualToSylvanas(uint8 copyIndex, uint32 spellVisual, float speed) const
    {
        Creature* shadowCopy = GetShadowcopy(_instance, copyIndex);
        Creature const* sylvanas = GetSylvanas();
        if (shadowCopy && sylvanas)
            shadowCopy->SendPlayOrphanSpellVisual(sylvanas->GetPosition(), spellVisual, speed, true, false);
    }

    void PlayVisualBetweenCopies(uint8 sourceIndex, uint8 destinationIndex, uint32 spellVisual, float speed) const
    {
        Creature* source = GetShadowcopy(_instance, sourceIndex);
        Creature const* destination = GetShadowcopy(_instance, destinationIndex);
        if (source && destination)
            source->SendPlayOrphanSpellVisual(destination->GetPosition(), spellVisual, speed, true, false);
    }

    void AttachSylvanasNameplate(ObjectGuid const& guid) const
    {
        if (Creature* sylvanas = GetSylvanas())
            sylvanas->SetNameplateAttachToGUID(guid);
    }

    // number of arrows spawned is dependent on raid's difficulty and size: min. 4, max. 10 (unless on intermission, which is every player alive).
    uint32 GetDominationArrowCount() const
    {
        uint32 const playerCount = me->GetMap()->GetPlayersCountExceptGMs();
        if (EventHelpers::GetWorldStatePhase(me) == Phases::Intermission)
            return playerCount;

        return std::clamp<uint32>(uint32(std::ceil(playerCount / 3.0f)), 4, 10);
    }

    void JumpToDominationChainsPosition(uint8 jumpTime)
    {
        Creature const* sylvanas = GetSylvanas();
        if (!sylvanas)
            return;

        _dominationChains.JumpPos = PositionHelpers::GetDominationChainsJumpPosition(sylvanas, jumpTime);
        JumpShadowcopyToPosition(_dominationChains.JumpPos, SpellVisuals::Windrunner01);
    }

    void TeleportSylvanasToJumpPosition() const
    {
        if (Creature* sylvanas = GetSylvanas())
            sylvanas->NearTeleportTo(_dominationChains.JumpPos, true);
    }

    void SpawnDominationArrows()
    {
        Creature* sylvanas = GetSylvanas();
        if (!sylvanas)
            return;

        for (uint8 i = 0; i < 5; i++)
        {
            Position const falseArrowPos = me->GetRandomPoint(Positions::PlatformCenter, frand(2.5f, 55.0f));

            me->SendPlaySpellVisual(falseArrowPos, SpellVisuals::DominationArrow, 0, 0, 2.0f, true);

            _scheduler.Schedule(2s, [this, falseArrowPos](TaskContext /*task*/)
            {
                if (Creature* sylvanas = GetSylvanas())
                    sylvanas->CastSpell(falseArrowPos, Spells::DominationArrowFall, true);
            });
        }

        uint32 const arrowCount = _dominationChains.NextJumpArrows();
        for (uint32 i = 0; i < arrowCount; ++i)
        {
            Position const arrowPos = me->GetRandomPoint(Positions::PlatformCenter, frand(2.5f, 55.0f));

            Creature const* dominationArrow = sylvanas->SummonCreature(NPC_DOMINATION_ARROW, arrowPos, TEMPSUMMON_MANUAL_DESPAWN);
            if (!dominationArrow)
                continue;

            me->SendPlaySpellVisual(arrowPos, SpellVisuals::DominationArrowSpawn, 0, 0, 2.0f, true);

            _scheduler.Schedule(2s, [this, dominationArrowGUID = dominationArrow->GetGUID()](TaskContext /*task*/)
            {
                Unit* dominationArrow = ObjectAccessor::GetUnit(*me, dominationArrowGUID);
                if (!dominationArrow)
                    return;

                if (Creature* sylvanas = GetSylvanas())
                    sylvanas->CastSpell(dominationArrow, Spells::DominationArrowFallAndVisual, true);

                if (IsHeroicOrHigher())
                    dominationArrow->CastSpell(dominationArrow, Spells::DominationArrowCalamityVisual);
            });
        }
    }

    void ReleaseDesecratingShots()
    {
        for (DesecratingArrow const& desecratingArrow : _desecratingArrows)
        {
            float travelSpeed = desecratingArrow.TravelSpeed;

            if (desecratingArrow.Step >= 2)
                travelSpeed += float((me->GetExactDist(desecratingArrow.Pos) * (0.016465054083896f * desecratingArrow.Step) / 46.5));

            me->SendPlaySpellVisual(desecratingArrow.Pos, SpellVisuals::DesecratingArrow, 0, 0, travelSpeed, true);

            uint32 const timer = uint32(travelSpeed * 1000);

            _scheduler.Schedule(Milliseconds(timer), [this, arrowPos = desecratingArrow.Pos](TaskContext /*task*/)
            {
                Creature* sylvanas = GetSylvanas();
                if (!sylvanas)
                    return;

                sylvanas->CastSpell(arrowPos, Spells::DesecratingShotTriggered, true);

                for (AreaTrigger* desecratingAreatrigger : sylvanas->GetAreaTriggers(Spells::DesecratingShotAreaTrigger))
                    if (desecratingAreatrigger->GetPosition() == arrowPos)
                        desecratingAreatrigger->Remove();
            });
        }
    }

    InstanceScript* _instance;
    TaskScheduler _sequences;
    TaskScheduler _scheduler;
    std::vector<DesecratingArrow> _desecratingArrows;
    DominationChainsState _dominationChains;
};

npc_sylvanas_windrunner_shadowcopy* GetShadowcopyAI(InstanceScript const* instance, uint8 copyIndex)
{
    Creature* shadowCopy = GetShadowcopy(instance, copyIndex);
    if (!shadowCopy)
        return nullptr;

    return CAST_AI(npc_sylvanas_windrunner_shadowcopy, shadowCopy->AI());
}

// 178355 - Sylvanas Shadowcopy (Riding)
struct npc_sylvanas_windrunner_shadowcopy_riding : public ScriptedAI
{
    npc_sylvanas_windrunner_shadowcopy_riding(Creature* creature) : ScriptedAI(creature) {}

    void JustAppeared() override
    {
        me->SetImmuneToAll(true, true);
        me->SetUninteractible(true);
        me->SetReactState(REACT_PASSIVE);
    }
};

// 175732 - Sylvanas Windrunner
struct boss_sylvanas_windrunner : public BossAI
{
    boss_sylvanas_windrunner(Creature* creature) : BossAI(creature, DATA_SYLVANAS_WINDRUNNER)
    {
        // like the events, the sequences wait while Sylvanas is casting; the scheduler keeps running during her casts.
        _sequences.SetValidator([this] { return !me->HasUnitState(UNIT_STATE_CASTING); });
    }

    void JustAppeared() override
    {
        scheduler.ClearValidator();

        DoCastSelf(Spells::GenericDualWield, true);
        DoCastSelf(Spells::SylvanasDisplayPowerSuffering, true);

        me->SetPower(me->GetPowerType(), 0);

        if (instance->GetData(DATA_SYLVANAS_INTRODUCTION) == DONE)
        {
            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetImmuneToAll(false);
            me->SetSpeed(MOVE_RUN, 14.0f);
        }
        else
        {
            me->SetUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetImmuneToAll(true);
            me->SetSpeed(MOVE_RUN, 4.0f);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(Texts::Disengage);

        _EnterEvadeMode();

        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        CleanUpEncounter();

        _DespawnAtEvade();
    }

    void Reset() override
    {
        _Reset();

        _sequences.CancelAll();
        _state = EncounterState();

        // every creature involved in the fight adds UNIT_FLAG_PET_IN_COMBAT or UNIT_FLAG_RENAME when engaging, meaning they're most likely summoned by Sylvanas.
        me->SummonCreatureGroup(SummonGroups::ChampionsFirstPhase);

        instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, Phases::One);

        events.Reset();
    }

    // unlike BossAI::JustSummoned, the summons aren't put in combat.
    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == Points::Introduction)
            DoCastSelf(Spells::GenericAnchorHere, true);
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer() || (time(nullptr) < (_state.LastSlayTalk + 5)))
            return;

        BossAI::KilledUnit(victim);

        _state.LastSlayTalk = time(nullptr);

        Talk(Texts::Slay);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        // it is safe to assume that these are summoned by a serverside spell.
        for (uint8 i = 0; i < 6; ++i)
            me->SummonCreature(NPC_SYLVANAS_SHADOWCOPY_FIGHTER, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);

        Talk(Texts::Aggro);

        HandlePhaseOne();

        DoCastSelf(Spells::SylvanasPowerEnergizeAura, true);
        DoCastSelf(Spells::RangerHeartseekerAura, true);
        DoCastSelf(Spells::HealthPctCheckIntermission, true);
        DoCastSelf(Spells::HealthPctCheckFinish, true);

        // Sylvanas uses her root with 2s at the beginning of the encounter, most likely to avoid her moving when engaging at stance switch.
        DoCastSelf(Spells::SylvanasRoot, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2000));
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case Actions::ResetMeleeKit:
                _state.MeleeComboStep = MeleeCombo::SwitchToMelee;
                break;

            case Actions::FinishDominationChains:
            {
                TeleportShadowcopiesToMe();

                ForEachShadowcopy([](npc_sylvanas_windrunner_shadowcopy& shadowCopy) { shadowCopy.StopDominationChains(); });

                if (events.IsInPhase(Phases::One))
                    ScheduleAttackResume(me, 1s + 500ms);
                else
                {
                    ScheduleAttackPause(me, 0ms);
                    TeleportShadowcopiesToMe();
                    StartRive();
                }
                break;
            }

            // TODO: move this to an event because the transition shouldn't happen at all until on-going events are done.
            case Actions::PrepareIntermission:
            {
                events.CancelEventGroup(EventGroups::Normal);
                events.CancelEventGroup(EventGroups::Windrunner);
                scheduler.CancelAll();
                _sequences.CancelAll();

                HandlePhaseIntermission();

                events.ScheduleEvent(Events::DominationChains, 1s, EventGroups::Normal, Phases::Intermission);
                break;
            }

            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _sequences.Update(diff);

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteEvent(eventId);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoSylvanasAttackIfReady();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case Events::Windrunner:
            {
                Talk(Texts::WindrunnerAnnounce);
                DoCastSelf(Spells::RangerBowStance, CastSpellExtraArgs(TRIGGERED_NONE).SetCustomArg(false));
                HandleWindrunner();
                break;
            }

            case Events::WitheringFire:
            {
                if (EventHelpers::GetWorldStatePhase(me) == Phases::One)
                    StartShadowcopyChoreography(&npc_sylvanas_windrunner_shadowcopy::StartWitheringFire, 2062, 3800);
                break;
            }

            case Events::ShadowDagger:
            {
                if (EventHelpers::GetWorldStatePhase(me) == Phases::One)
                    StartShadowcopyChoreography(&npc_sylvanas_windrunner_shadowcopy::StartShadowDagger, 1500, 3200);
                break;
            }

            case Events::ShadowDaggerTalk:
            {
                Talk(Texts::ShadowDagger);
                break;
            }

            case Events::DesecratingShot:
            {
                DrawDesecratingShot(_state.NextDesecratingShotPattern());
                break;
            }

            case Events::DesecratingShotLaunch:
            {
                TeleportShadowcopiesToMe();
                LaunchDesecratingShot(_state.DesecratingPattern);
                break;
            }

            case Events::DesecratingShotLaunchTalk:
            {
                Talk(Texts::DesecratingShot);
                break;
            }

            case Events::DominationChains:
            {
                TeleportShadowcopiesToMe();

                me->m_Events.KillAllEvents(true);

                DoCastSelf(Spells::RangerBowStance, CastSpellExtraArgs(TRIGGERED_NONE).SetCustomArg(false));

                if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyAI(instance, Shadowcopy::Index00))
                    shadowCopyAI->StartDominationChains();

                ++_state.DominationChainsCasts;

                if (events.IsInPhase(Phases::One))
                    events.Repeat(GetPhaseOneTimer(Timers::PhaseOneRow::DominationChains, _state.DominationChainsCasts));
                break;
            }

            case Events::WailingArrow:
            {
                // we must ensure Ranger Shot doesn't reset AttackTimer incorrectly.
                me->m_Events.KillAllEvents(true);

                if (EventHelpers::GetWorldStatePhase(me) == Phases::One)
                    CastWailingArrow();
                break;
            }

            case Events::VeilOfDarkness:
            {
                StartVeilOfDarkness();
                break;
            }

            default:
                break;
        }
    }

    void DoSylvanasAttackIfReady()
    {
        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(Spells::Windrunner) || me->HasReactState(REACT_PASSIVE))
            return;

        UpdateMeleeComboStep();

        if (!me->isAttackReady(BASE_ATTACK))
            return;

        switch (_state.MeleeComboStep)
        {
            case MeleeCombo::SwitchToMelee:
                DoCastSelf(Spells::RangerDaggersStance);
                ++_state.MeleeComboStep;
                break;

            case MeleeCombo::RangerStrike01:
                DoCastVictim(Spells::RangerStrike);
                _state.MeleeComboStep = roll_chance(70) ? MeleeCombo::RangerStrike02 : MeleeCombo::SwitchToRanged;
                break;

            case MeleeCombo::RangerStrike02:
                DoCastVictim(Spells::RangerStrike);
                ++_state.MeleeComboStep;
                break;

            case MeleeCombo::SwitchToRanged:
                DoCastSelf(Spells::RangerBowStance, CastSpellExtraArgs(TRIGGERED_NONE).SetCustomArg(false));
                ++_state.MeleeComboStep;
                break;

            case MeleeCombo::Finish:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::MaxThreat, 0))
                {
                    if (HasHeartseekerCharges())
                        me->CastSpell(target, Spells::RangerHeartseeker, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 550));
                    else
                        me->CastSpell(target, Spells::RangerShot);
                }

                if (roll_chance(65) && me->IsWithinCombatRange(me->GetVictim(), 4.0f))
                    DoAction(Actions::ResetMeleeKit);
                break;
            }

            default:
                break;
        }

        me->resetAttackTimer(BASE_ATTACK);
    }

private:
    struct EncounterState
    {
        uint8 WindrunnerCasts = 0;
        uint8 DominationChainsCasts = 0;
        uint8 WailingArrowCasts = 0;
        uint8 WailingArrowMarkers = 0;
        uint8 VeilOfDarknessCasts = 0;
        uint8 DesecratingShots = 0;
        uint8 DesecratingPattern = DesecratingShotPattern::None;
        uint8 MeleeComboStep = MeleeCombo::SwitchToMelee;
        ObjectGuid WailingArrowTargetGUID;
        time_t LastSlayTalk = 0;

        // any Windrunner from fifth cast is always the same.
        void AddWindrunnerCast()
        {
            if (WindrunnerCasts < 5)
                ++WindrunnerCasts;
        }

        // first cast is 11s and every following cast has 2 additional seconds.
        int32 GetWindrunnerDuration() const
        {
            return 9000 + 2000 * WindrunnerCasts;
        }

        std::span<WindrunnerSchedules::ScheduledEvent const> GetWindrunnerSchedule() const
        {
            if (!WindrunnerCasts || WindrunnerCasts > std::size(WindrunnerSchedules::ByCast))
                return { };

            return WindrunnerSchedules::ByCast[WindrunnerCasts - 1];
        }

        uint8 NextDesecratingShotPattern()
        {
            ++DesecratingShots;

            switch (WindrunnerCasts)
            {
                case WindrunnerCounter::One:
                    DesecratingPattern = DesecratingShots == 1 ? DesecratingShotPattern::Scattered : DesecratingShotPattern::Straight;
                    break;
                case WindrunnerCounter::Two:
                    DesecratingPattern = DesecratingShots == 3 ? DesecratingShotPattern::Wave : DesecratingShotPattern::SpiralEnclosed;
                    break;
                case WindrunnerCounter::Three:
                    DesecratingPattern = DesecratingShots == 5 ? DesecratingShotPattern::Spiral : DesecratingShotPattern::Scattered;
                    break;
                case WindrunnerCounter::Four:
                    DesecratingPattern = DesecratingShots == 7 ? DesecratingShotPattern::Scattered : DesecratingShotPattern::Jar;
                    break;
                default:
                    DesecratingPattern = DesecratingShotPattern::None;
                    break;
            }

            return DesecratingPattern;
        }
    };

    // the copies are the only summons with their entry, so the summon list is their list too.
    template <typename Action>
    void ForEachShadowcopy(Action const& action) const
    {
        for (ObjectGuid const& summonGUID : summons)
        {
            if (summonGUID.GetEntry() != NPC_SYLVANAS_SHADOWCOPY_FIGHTER)
                continue;

            if (Creature* shadowCopy = ObjectAccessor::GetCreature(*me, summonGUID))
                if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = CAST_AI(npc_sylvanas_windrunner_shadowcopy, shadowCopy->AI()))
                    action(*shadowCopyAI);
        }
    }

    void TeleportShadowcopiesToMe() const
    {
        ForEachShadowcopy([this](npc_sylvanas_windrunner_shadowcopy const& shadowCopy) { shadowCopy.ReturnTo(me->GetPosition()); });
    }

    // Sylvanas switches to her bow before Windrunner, Domination Chains or Veil of Darkness, and whenever her victim is out of melee range.
    void UpdateMeleeComboStep()
    {
        for (uint32 incomingEvent : { Events::Windrunner, Events::DominationChains, Events::VeilOfDarkness })
        {
            if (events.GetTimeUntilEvent(incomingEvent) <= 500ms)
            {
                _state.MeleeComboStep = MeleeCombo::SwitchToRanged;
                return;
            }
        }

        if (HasHeartseekerCharges())
            _state.MeleeComboStep = MeleeCombo::Finish;
        else if (!me->IsWithinCombatRange(me->GetVictim(), 4.0f))
            _state.MeleeComboStep = me->HasAura(Spells::RangerBowStance) ? MeleeCombo::Finish : MeleeCombo::SwitchToRanged;
    }

    bool HasHeartseekerCharges() const
    {
        Aura const* heartseekerAura = me->GetAura(Spells::RangerHeartseekerCharge);
        return heartseekerAura && heartseekerAura->GetStackAmount() >= 3;
    }

    Milliseconds GetPhaseOneTimer(uint8 row, uint8 count) const
    {
        return Timers::GetPhaseOneTimer(EventHelpers::GetDifficultyForTimer(me), row, count);
    }

    void HandlePhaseOne()
    {
        events.SetPhase(Phases::One);
        instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, Phases::One);

        events.ScheduleEvent(Events::Windrunner, GetPhaseOneTimer(Timers::PhaseOneRow::Windrunner, _state.WindrunnerCasts), EventGroups::Normal, Phases::One);
        events.ScheduleEvent(Events::DominationChains, GetPhaseOneTimer(Timers::PhaseOneRow::DominationChains, _state.DominationChainsCasts), EventGroups::Normal, Phases::One);
        events.ScheduleEvent(Events::VeilOfDarkness, GetPhaseOneTimer(Timers::PhaseOneRow::VeilOfDarkness, _state.VeilOfDarknessCasts), EventGroups::Normal, Phases::One);
        events.ScheduleEvent(Events::WailingArrow, GetPhaseOneTimer(Timers::PhaseOneRow::WailingArrow, _state.WailingArrowCasts), EventGroups::Normal, Phases::One);

        ScheduleWailingArrowMarker();
    }

    void HandlePhaseIntermission()
    {
        events.SetPhase(Phases::Intermission);
        instance->DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_PHASE, Phases::Intermission);

        ForEachShadowcopy([](npc_sylvanas_windrunner_shadowcopy& shadowCopy) { shadowCopy.PrepareForIntermission(); });
    }

    void HandleWindrunner()
    {
        _state.AddWindrunnerCast();

        DoCastSelf(Spells::Windrunner, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, _state.GetWindrunnerDuration()));

        for (WindrunnerSchedules::ScheduledEvent const& scheduledEvent : _state.GetWindrunnerSchedule())
            events.ScheduleEvent(scheduledEvent.EventId, scheduledEvent.Delay, EventGroups::Windrunner, Phases::One);

        events.ScheduleEvent(Events::Windrunner, GetPhaseOneTimer(Timers::PhaseOneRow::Windrunner, _state.WindrunnerCasts), EventGroups::Normal, Phases::One);
    }

    void StartShadowcopyChoreography(void (npc_sylvanas_windrunner_shadowcopy::*choreography)(), int32 disappearDuration, int32 rootDuration)
    {
        TeleportShadowcopiesToMe();
        DoCastSelf(Spells::WindrunnerDisappear01, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, disappearDuration));
        DoCastSelf(Spells::SylvanasRoot, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, rootDuration));

        if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyAI(instance, Shadowcopy::Index00))
            (shadowCopyAI->*choreography)();
    }

    void ScheduleWailingArrowMarker()
    {
        scheduler.Schedule(GetPhaseOneTimer(Timers::PhaseOneRow::WailingArrowMarker, _state.WailingArrowMarkers), [this](TaskContext /*task*/)
        {
            Unit* currentTank = SelectTarget(SelectTargetMethod::MaxThreat, 0, 500.0f, true, true);
            if (!currentTank)
                return;

            _state.WailingArrowTargetGUID = currentTank->GetGUID();

            Talk(Texts::WailingArrowAnnounceAffected, currentTank);

            me->CastSpell(currentTank, Spells::WailingArrowPointer, true);

            if (events.IsInPhase(Phases::One))
            {
                std::list<Player*> players;
                GetPlayerListInGrid(players, me, 500.0f);

                for (Player const* player : players)
                    if (player != currentTank)
                        Talk(Texts::WailingArrowAnnounce, player);
            }

            ++_state.WailingArrowMarkers;
        });
    }

    void CastWailingArrow()
    {
        Talk(Texts::WailingArrow);

        if (Player* target = ObjectAccessor::GetPlayer(*me, _state.WailingArrowTargetGUID))
            me->CastSpell(target, Spells::WailingArrow);
        else if (Unit* newTarget = SelectTarget(SelectTargetMethod::MaxThreat, 0, 500.0f, true))
            me->CastSpell(newTarget, Spells::WailingArrow);

        ScheduleAttackResume(me, 4s + 484ms);

        ++_state.WailingArrowCasts;

        ScheduleWailingArrowMarker();

        events.ScheduleEvent(Events::WailingArrow, GetPhaseOneTimer(Timers::PhaseOneRow::WailingArrow, _state.WailingArrowCasts), EventGroups::Normal, Phases::One);
    }

    void StartVeilOfDarkness()
    {
        // we must ensure Ranger Shot doesn't reset AttackTimer incorrectly.
        me->m_Events.KillAllEvents(true);
        ScheduleAttackPause(me, 5ms);
        Talk(Texts::VeilOfDarknessAnnounce);

        if (EventHelpers::GetWorldStatePhase(me) != Phases::One)
            return;

        Talk(Texts::VeilOfDarknessPhaseOne);

        ScheduleSequence(_sequences,
        {
            { 500ms, [this]
            {
                ++_state.VeilOfDarknessCasts;
                DoCastSelf(Spells::VeilOfDarknessPhase1Fade);
                events.ScheduleEvent(Events::VeilOfDarkness, GetPhaseOneTimer(Timers::PhaseOneRow::VeilOfDarkness, _state.VeilOfDarknessCasts), EventGroups::Normal, Phases::One);
            } },
            { 500ms, [this] { me->NearTeleportTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 100.0f, me->GetOrientation()); } },
            { 1s,    [this] { DoCastSelf(Spells::VeilOfDarknessPhase1Grow, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 5000)); } },
            { 1s,    [this] { DoCastSelf(Spells::VeilOfDarknessPhase1); } },
            { 1s,    [this] { TeleportShadowcopiesToMe(); } }
        });
    }

    // Sylvanas throws Rive at every position in a random order, then the intermission ends.
    void StartRive()
    {
        auto rivePositions = Positions::RiveThrow;
        Trinity::Containers::RandomShuffle(rivePositions);

        std::vector<SequenceStep> steps;
        Milliseconds delay = 641ms;

        for (uint8 throwIndex = 0; throwIndex < rivePositions.size(); ++throwIndex)
        {
            Position const rivePos = rivePositions[throwIndex];
            bool const slowRive = throwIndex == 0 || throwIndex == 5;
            std::shared_ptr<ObjectGuid> const riveTargetGUID = std::make_shared<ObjectGuid>();

            steps.push_back({ delay, [this, rivePos]
            {
                for (uint8 copyIndex : { Shadowcopy::Index00, Shadowcopy::Index02, Shadowcopy::Index03 })
                    if (Creature* shadowCopy = GetShadowcopy(instance, copyIndex))
                        shadowCopy->NearTeleportTo(rivePos);
            } });

            steps.push_back({ 600ms, [this, riveTargetGUID]
            {
                Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 500.0f, true, true);
                if (!target)
                    return;

                *riveTargetGUID = target->GetGUID();

                for (uint8 copyIndex : { Shadowcopy::Index00, Shadowcopy::Index02, Shadowcopy::Index03 })
                    if (Creature* shadowCopy = GetShadowcopy(instance, copyIndex))
                        shadowCopy->SetFacingToObject(target);
            } });

            steps.push_back({ 10ms, [this]
            {
                if (Creature* shadowCopy2 = GetShadowcopy(instance, Shadowcopy::Index02))
                    shadowCopy2->NearTeleportTo(shadowCopy2->GetPositionX(), shadowCopy2->GetPositionY(), 4105.00f, shadowCopy2->GetOrientation());
            } });

            steps.push_back({ 10ms, [this]
            {
                if (Creature* shadowCopy2 = GetShadowcopy(instance, Shadowcopy::Index02))
                    shadowCopy2->NearTeleportTo(shadowCopy2->GetNearPosition(24.4f, 0.0f));
            } });

            steps.push_back({ 10ms, [this]
            {
                DoCastSelf(Spells::RiveDisappear, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 500));

                Creature const* shadowCopy2 = GetShadowcopy(instance, Shadowcopy::Index02);
                if (!shadowCopy2)
                    return;

                me->SendPlayOrphanSpellVisual(shadowCopy2->GetPosition(), SpellVisuals::Windrunner03, 0.25f, true, false);

                if (Creature* shadowCopy1 = GetShadowcopy(instance, Shadowcopy::Index01))
                {
                    me->SetNameplateAttachToGUID(shadowCopy1->GetGUID());

                    shadowCopy1->CastSpell(shadowCopy2->GetPosition(), Spells::DominationChainsJump, true);
                }
            } });

            steps.push_back({ 10ms, [this]
            {
                if (Creature const* shadowCopy2 = GetShadowcopy(instance, Shadowcopy::Index02))
                    me->NearTeleportTo(shadowCopy2->GetPosition());

                DoCastSelf(Spells::GenericAnchorHere, true);
            } });

            steps.push_back({ 10ms, [this, riveTargetGUID]
            {
                Player const* target = ObjectAccessor::GetPlayer(*me, *riveTargetGUID);
                if (!target)
                    return;

                if (Creature* shadowCopy = GetShadowcopy(instance, Shadowcopy::Index00))
                    shadowCopy->SetFacingToObject(target);

                // HACKFIX: remove orientation when SPELL_ATTR12_UNK11 (Face Destination) is implemented.
                me->SetFacingToObject(target);
            } });

            steps.push_back({ 35ms, [this, slowRive] { ThrowRive(slowRive); } });

            delay = slowRive ? 4s + 500ms : 2s;
        }

        steps.push_back({ delay, [this]
        {
            ForEachShadowcopy([this](npc_sylvanas_windrunner_shadowcopy& shadowCopy)
            {
                shadowCopy.ReturnTo(me->GetPosition());
                shadowCopy.StopDominationChains();
            });
        } });

        AppendFinishIntermissionSteps(steps);

        ScheduleSequence(_sequences, std::move(steps));
    }

    void ThrowRive(bool slowRive)
    {
        scheduler.Schedule(445ms, [this](TaskContext /*task*/)
        {
            me->SetNameplateAttachToGUID(ObjectGuid::Empty);
        });

        if (slowRive)
        {
            DoCastSelf(Spells::Rive);

            scheduler.Schedule(1s + 750ms, [this](TaskContext /*task*/)
            {
                me->SendPlaySpellVisualKit(SpellVisualKits::RiveBreak, 0, 0);
            });

            scheduler.Schedule(2s + 484ms, [this](TaskContext /*task*/)
            {
                me->CastSpell(me->GetNearPosition(9.0f, 0.0f), Spells::RiveMarkerAreaTrigger, true);
            });
        }
        else
        {
            DoCastSelf(Spells::RiveFast);

            me->SendPlaySpellVisualKit(SpellVisualKits::RiveBreakFast, 0, 0);

            me->CastSpell(me->GetNearPosition(9.0f, 0.0f), Spells::RiveMarkerAreaTrigger, true);
        }
    }

    void AppendFinishIntermissionSteps(std::vector<SequenceStep>& steps)
    {
        steps.push_back({ 1s + 500ms, [this]
        {
            DoCastSelf(Spells::WindrunnerDisappear01, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 500));
            me->SendPlayOrphanSpellVisual(Positions::IntermissionFinish, SpellVisuals::Windrunner01, 0.5f, true, false);

            if (Creature* shadowCopy = GetShadowcopy(instance, Shadowcopy::Index00))
                shadowCopy->CastSpell(Positions::IntermissionFinish, Spells::DominationChainsJump, true);
        } });

        steps.push_back({ 100ms, [this]
        {
            if (Creature const* shadowCopy = GetShadowcopy(instance, Shadowcopy::Index00))
                me->SetNameplateAttachToGUID(shadowCopy->GetGUID());
        } });

        steps.push_back({ 400ms, [this]
        {
            me->NearTeleportTo(Positions::IntermissionFinish);
            me->SetNameplateAttachToGUID(ObjectGuid::Empty);
        } });

        steps.push_back({ 1s + 200ms, [this] { Talk(Texts::IntermissionEnd); } });

        steps.push_back({ 700ms, [this]
        {
            DoCastSelf(Spells::BansheeWail, CastSpellExtraArgs(TRIGGERED_NONE).AddSpellMod(SPELLVALUE_DURATION, 5000));
            Talk(Texts::BansheeWailAnnounce);

            scheduler.Schedule(4s, [this](TaskContext /*task*/)
            {
                me->SendPlaySpellVisualKit(SpellVisualKits::TransformIntoBanshee, 0, 0);
            });
        } });

        steps.push_back({ 6s + 100ms, [this]
        {
            instance->DoCastSpellOnPlayers(Spells::IntermissionSceneAndStun);
            instance->DoCastSpellOnPlayers(Spells::IntermissionScene);
        } });

        steps.push_back({ 900ms, [this]
        {
            me->SendPlayOrphanSpellVisual(Positions::PhaseTwoPre, SpellVisuals::Windrunner01, 0.5f, true, false);
            me->NearTeleportTo(Positions::PhaseTwoPre);
        } });
    }

    // places the markers of every arrow and gives the arrows to the copies that will shoot them.
    void DrawDesecratingShot(uint8 pattern)
    {
        switch (pattern)
        {
            case DesecratingShotPattern::Straight:
            {
                Unit const* target = SelectTarget(SelectTargetMethod::Random, 0, 500.0f, true, true);
                if (!target)
                    break;

                float const orientation = me->GetAbsoluteAngle(target);

                for (uint8 step = 1; step < 30; ++step)
                {
                    float const distance = 7.0f * step;

                    Position const tip(me->GetPositionX() + (std::cos(orientation) * distance), me->GetPositionY() + (std::sin(orientation) * distance), me->GetPositionZ());

                    DrawDesecratingArrow(DesecratingShotGeometry::StraightArrow, tip, orientation, step);
                }
                break;
            }

            case DesecratingShotPattern::Scattered:
            {
                uint8 const targetSize = std::max<uint8>(4, static_cast<uint8>(std::ceil(me->GetMap()->GetPlayersCountExceptGMs() / 3.0f)));

                std::list<Unit*> targets;
                SelectTargetList(targets, targetSize, SelectTargetMethod::Random, 0, 500.0f, TargetPlayersOnly, true);

                for (Unit const* target : targets)
                {
                    float const orientation = target->GetOrientation();

                    Position const tip(target->GetPositionX() + std::cos(orientation), target->GetPositionY() + std::sin(orientation), me->GetPositionZ());

                    DrawDesecratingArrow(DesecratingShotGeometry::ScatteredArrow, tip, orientation, 1);
                }
                break;
            }

            case DesecratingShotPattern::Wave:
            {
                Position const origin = me->GetPosition();

                float const orientation = me->GetOrientation();

                for (uint8 copyIndex : { Shadowcopy::Index02, Shadowcopy::Index01, Shadowcopy::Index00 })
                {
                    Position lineOrigin(origin);
                    lineOrigin.m_positionX += std::cos(orientation + float(M_PI)) * DesecratingShotGeometry::WaveLineOffsets[copyIndex];
                    lineOrigin.m_positionY += std::sin(orientation + float(M_PI)) * DesecratingShotGeometry::WaveLineOffsets[copyIndex];

                    for (uint8 step = 0; step < 30; ++step)
                        DrawDesecratingWaveStep(lineOrigin, orientation, step, copyIndex);
                }
                break;
            }

            case DesecratingShotPattern::Spiral:
            case DesecratingShotPattern::SpiralEnclosed:
            {
                std::list<Unit*> targets;
                SelectTargetList(targets, 3, SelectTargetMethod::Random, 0, 500.0f, TargetPlayersOnly, true);

                uint8 copyIndex = Shadowcopy::Index02;

                for (Unit const* target : targets)
                {
                    for (uint8 step = 10; step > 0; --step)
                        DrawDesecratingSpiralStep(pattern, target->GetPosition(), target->GetOrientation(), step, copyIndex);

                    --copyIndex;
                }
                break;
            }

            case DesecratingShotPattern::Jar:
                break;

            default:
                break;
        }
    }

    void DrawDesecratingArrow(std::span<DesecratingShotGeometry::ArrowPart const> parts, Position const& tip, float orientation, uint8 step)
    {
        for (DesecratingShotGeometry::ArrowPart const& part : parts)
        {
            float const angle = orientation + part.Angle;

            Position const arrowPos(tip.GetPositionX() + (std::cos(angle) * part.Distance), tip.GetPositionY() + (std::sin(angle) * part.Distance), tip.GetPositionZ());

            if (ScheduleDesecratingShotMarker(arrowPos, Milliseconds(step * part.MarkerDelayPerStep)))
                StoreDesecratingShot(Shadowcopy::Index00, arrowPos, step, part.TravelSpeed);
        }
    }

    void DrawDesecratingWaveStep(Position const& lineOrigin, float orientation, uint8 step, uint8 copyIndex)
    {
        float const travelSpeed = DesecratingShotGeometry::BaseTravelSpeed + float(DesecratingShotGeometry::BaseTravelSpeed * (step * 0.025));

        if (step == 0)
        {
            if (ScheduleDesecratingShotMarker(lineOrigin, DesecratingShotGeometry::WaveFirstMarkerDelays[copyIndex]))
                StoreDesecratingShot(copyIndex, lineOrigin, step, travelSpeed);
            return;
        }

        float const pointDistance = DesecratingShotGeometry::WavePointSpacing * step;

        Milliseconds const markerDelay(DesecratingShotGeometry::WaveMarkerDelayPerStep[copyIndex] * (step <= 1 ? step + 5 : step + 15));

        for (float side : { DesecratingShotGeometry::WaveSide, -DesecratingShotGeometry::WaveSide })
        {
            float const angle = orientation + side;

            Position const arrowPos(lineOrigin.GetPositionX() + (std::cos(angle) * pointDistance), lineOrigin.GetPositionY() + (std::sin(angle) * pointDistance), lineOrigin.GetPositionZ());

            if (ScheduleDesecratingShotMarker(arrowPos, markerDelay))
                StoreDesecratingShot(copyIndex, arrowPos, step, travelSpeed);
        }
    }

    void DrawDesecratingSpiralStep(uint8 pattern, Position const& center, float orientation, uint8 step, uint8 copyIndex)
    {
        // the center is drawn last and its marker is placed even outside of the platform.
        if (step == 1)
        {
            if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyAI(instance, copyIndex))
            {
                shadowCopyAI->StoreDesecratingShot(center, 0, DesecratingShotGeometry::SpiralCenterTravelSpeed);

                scheduler.Schedule(16ms, [this, center](TaskContext /*task*/)
                {
                    me->CastSpell(center, Spells::DesecratingShotAreaTrigger, true);
                });
            }
            return;
        }

        float const distance = pattern == DesecratingShotPattern::Spiral ? DesecratingShotDistances::Spiral[step - 1] : DesecratingShotDistances::SpiralEnclosed[step - 1];

        float const travelSpeed = DesecratingShotGeometry::BaseTravelSpeed + float(DesecratingShotGeometry::BaseTravelSpeed * (step * 0.1));

        // every step turns the three arms of the spiral by another 10 degrees.
        for (float armAngle : DesecratingShotGeometry::SpiralArmAngles)
        {
            float const angle = orientation + (armAngle + float(10 * step)) * float(M_PI) / 180;

            Position const arrowPos(center.GetPositionX() + (std::cos(angle) * distance), center.GetPositionY() + (std::sin(angle) * distance), center.GetPositionZ());

            if (ScheduleDesecratingShotMarker(arrowPos, Milliseconds(step * 24)))
                StoreDesecratingShot(copyIndex, arrowPos, step, travelSpeed);
        }
    }

    // places the marker of an arrow that lands on the platform, right away or once its delay is over.
    bool ScheduleDesecratingShotMarker(Position const& arrowPos, Milliseconds delay)
    {
        if (!IsOnPlatform(arrowPos))
            return false;

        if (delay == 0ms)
        {
            me->CastSpell(arrowPos, Spells::DesecratingShotAreaTrigger, true);
            return true;
        }

        scheduler.Schedule(delay, [this, arrowPos](TaskContext /*task*/)
        {
            me->CastSpell(arrowPos, Spells::DesecratingShotAreaTrigger, true);
        });

        return true;
    }

    void StoreDesecratingShot(uint8 copyIndex, Position const& arrowPos, uint8 step, float travelSpeed) const
    {
        if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyAI(instance, copyIndex))
            shadowCopyAI->StoreDesecratingShot(arrowPos, step, travelSpeed);
    }

    void LaunchDesecratingShot(uint8 pattern)
    {
        switch (pattern)
        {
            case DesecratingShotPattern::Straight:
            case DesecratingShotPattern::Scattered:
            {
                if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyAI(instance, Shadowcopy::Index00))
                    shadowCopyAI->StartDesecratingShotEvent(pattern, Shadowcopy::Index00);
                break;
            }

            case DesecratingShotPattern::Wave:
            case DesecratingShotPattern::Spiral:
            case DesecratingShotPattern::SpiralEnclosed:
            {
                if (npc_sylvanas_windrunner_shadowcopy* shadowCopy2AI = GetShadowcopyAI(instance, Shadowcopy::Index02))
                    shadowCopy2AI->StartDesecratingShotEvent(pattern, Shadowcopy::Index02);

                scheduler.Schedule(300ms, [this, pattern](TaskContext /*task*/)
                {
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopy1AI = GetShadowcopyAI(instance, Shadowcopy::Index01))
                        shadowCopy1AI->StartDesecratingShotEvent(pattern, Shadowcopy::Index01);
                });

                scheduler.Schedule(600ms, [this, pattern](TaskContext /*task*/)
                {
                    if (npc_sylvanas_windrunner_shadowcopy* shadowCopyAI = GetShadowcopyAI(instance, Shadowcopy::Index00))
                        shadowCopyAI->StartDesecratingShotEvent(pattern, Shadowcopy::Index00);
                });
                break;
            }

            default:
                break;
        }
    }

    void CleanUpEncounter() const
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(Spells::BarbedArrow);
        instance->DoRemoveAurasDueToSpellOnPlayers(Spells::BansheeMark);
        instance->DoRemoveAurasDueToSpellOnPlayers(Spells::DominationChainPlayer);
        instance->DoRemoveAurasDueToSpellOnPlayers(Spells::DominationChainPeriodic);
        instance->DoRemoveAurasDueToSpellOnPlayers(Spells::VeilOfDarknessAbsorbAura);
    }

    TaskScheduler _sequences;
    EncounterState _state;
};

// 176920 - Domination Arrow
struct npc_sylvanas_windrunner_domination_arrow : public ScriptedAI
{
    npc_sylvanas_windrunner_domination_arrow(Creature* creature) : ScriptedAI(creature) {}

    void JustAppeared() override
    {
        // @Modox: is this really needed? they're spawned by Sylvanas, not sure if manually-spawned creatures inherit combat state from owner.
        DoZoneInCombat();

        me->SetReactState(REACT_PASSIVE);
        me->SetUninteractible(true);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case Actions::ActivateDominationArrow:
            {
                me->SetUninteractible(false);

                me->RemoveAura(Spells::DominationArrowCalamityVisual);

                DoCastSelf(Spells::DominationArrowActivate, true);

                // TODO: the target check should prioritize players at the MinDistance with no Spells::DominationChainPlayer.
                // If the condition cannot be met, it should choose people with the least amounts of Spells::DominationChainPlayer.
                // Why? Intermission can trigger right after Domination Chains, and every new Domination Chain chooses even the ones already affected.
                if (Unit* target = SelectTarget(SelectTargetMethod::MinDistance, 0, 500.0f, true, true, -int32(Spells::DominationChainPlayer)))
                {
                    _playerGUID = target->GetGUID();

                    me->CastSpell(target, Spells::DominationChainPlayer);

                    if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                        target->CastSpell(me, Spells::DominationArrowCalamityAreaTrigger, true);
                }
                break;
            }

            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Player* chainedPlayer = ObjectAccessor::GetPlayer(*me, _playerGUID))
        {
            if (chainedPlayer->HasAura(Spells::DominationChainPlayer, me->GetGUID()))
                chainedPlayer->RemoveAura(Spells::DominationChainPlayer);
        }
    }

private:
    ObjectGuid _playerGUID;
};

// 347560 - Ranger (Bow)
class spell_sylvanas_windrunner_ranger_bow : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::SylvanasRoot, Spells::RangerDaggersStance });
    }

    void HandleOnCast()
    {
        bool const* isTriggeredByHeartseeker = std::any_cast<bool>(&GetSpell()->m_customArg);
        if (isTriggeredByHeartseeker && !*isTriggeredByHeartseeker)
        {
            Unit* caster = GetCaster();

            caster->RemoveAura(Spells::RangerDaggersStance);

            caster->CastSpell(caster, Spells::SylvanasRoot, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 1600));

            caster->SendPlaySpellVisualKit(RAND(SpellVisualKits::UnsheatheBow, SpellVisualKits::UnsheatheBowSpin), 0, 0);

            ScheduleSheath(caster, SHEATH_STATE_UNARMED, 16ms);
            ScheduleSheath(caster, SHEATH_STATE_RANGED, 359ms);

            if (caster->IsInCombat())
                ScheduleAttackResume(caster, 859ms);
        }
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_sylvanas_windrunner_ranger_bow::HandleOnCast);
    }
};

class spell_sylvanas_windrunner_ranger_bow_aura : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        ScheduleBaseAttackTime(GetTarget(), AttackTimes::Bow, 0ms);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_ranger_bow_aura::OnApply, EFFECT_0, SPELL_AURA_ANIM_REPLACEMENT_SET, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 348010 - Ranger (Dagger)
class spell_sylvanas_windrunner_ranger_dagger : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::RangerBowStance });
    }

    void HandleOnCast()
    {
        Unit* caster = GetCaster();

        caster->RemoveAura(Spells::RangerBowStance);

        ScheduleBaseAttackTime(caster, AttackTimes::Daggers, 0ms);

        caster->SendPlaySpellVisualKit(RAND(SpellVisualKits::UnsheatheDaggers, SpellVisualKits::UnsheatheDaggersSpin), 0, 0);

        ScheduleSheath(caster, SHEATH_STATE_UNARMED, 16ms);
        ScheduleSheath(caster, SHEATH_STATE_MELEE, 281ms);

        if (caster->IsInCombat())
            ScheduleAttackResume(caster, 828ms);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_sylvanas_windrunner_ranger_dagger::HandleOnCast);
    }
};

// 347548 - Ranger Shot
class spell_sylvanas_windrunner_ranger_shot : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::SylvanasRoot });
    }

    void OnPrecast() override
    {
        Unit* caster = GetCaster();
        ScheduleAttackResume(caster, 1750ms);
        caster->CastSpell(caster, Spells::SylvanasRoot, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 2500));
    }

    void Register() override {}
};

// 348299 - Ranger Strike
class spell_sylvanas_windrunner_ranger_strike : public SpellScript
{
    void HandleLaunchTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->SendPlaySpellVisual(GetHitUnit(), RAND(SpellVisuals::RangerStrikeRight, SpellVisuals::RangerStrikeLeft,
            SpellVisuals::RangerStrikeFastRight, SpellVisuals::RangerStrikeFastLeft), 0, 0, 1.0f, true);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_sylvanas_windrunner_ranger_strike::HandleLaunchTarget, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
    }
};

// 347504 - Windrunner
class spell_sylvanas_windrunner_windrunner : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->setAttackTimer(WeaponAttackType::BASE_ATTACK, 500);

        target->GetAI()->DoAction(Actions::ResetMeleeKit);

        ScheduleAttackResume(target, 500ms);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_windrunner::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 352303 - Windrunner (Disappear 01)
// 358975 - Windrunner (Disappear 02)
class spell_sylvanas_windrunner_disappear : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::SylvanasRoot });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        InstanceScript* instance = target->GetInstanceScript();
        if (!instance)
            return;

        if (GetSpellInfo()->Id == Spells::WindrunnerDisappear02)
        {
            if (npc_sylvanas_windrunner_shadowcopy const* shadowCopyAI = GetShadowcopyAI(instance, Shadowcopy::Index00))
            {
                if (EventHelpers::GetWorldStatePhase(target) == Phases::One || shadowCopyAI->IsOnDominationChains())
                    target->CastSpell(target, Spells::SylvanasRoot, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3600));
                else if (EventHelpers::GetWorldStatePhase(target) == Phases::Three)
                    target->CastSpell(target, Spells::SylvanasRoot, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 4280));
                else
                    target->CastSpell(target, Spells::SylvanasRoot, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 1750));
            }
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_disappear::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 347928 - Withering Fire
class spell_sylvanas_windrunner_withering_fire : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
        {
            if (EventHelpers::GetWorldStatePhase(caster) == Phases::One)
                sylvanas->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_withering_fire::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 348627 - Desecrating Shot
class spell_sylvanas_windrunner_desecrating_shot : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_desecrating_shot::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 352663 - Ranger's Heartseeker
class spell_sylvanas_windrunner_heartseeker : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::RangerBowStance, Spells::SylvanasRoot });
    }

    void OnPrecast() override
    {
        Unit* caster = GetCaster();

        // there's no SMSG_SPELL_START or SMSG_SPELL_GO, but we must cast serverside. That's why we will prevent the SpellScript from doing anything with customArg.
        caster->CastSpell(caster, Spells::RangerBowStance, CastSpellExtraArgs(TRIGGERED_NONE).SetCustomArg(true));

        caster->CastSpell(caster, Spells::SylvanasRoot, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3750));

        if (Unit* victim = caster->GetVictim())
            caster->SetInFront(victim);

        ScheduleSheath(caster, SHEATH_STATE_UNARMED, 31ms);
        ScheduleSheath(caster, SHEATH_STATE_RANGED, 297ms);
        ScheduleNameplateOnRidingCopy(caster, 406ms);
        ScheduleNameplateReset(caster, 1s + 953ms);

        ScheduleAttackResume(caster, 2s + 984ms);
    }

    void HandleMissiles(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!target)
            return;

        caster->SetInFront(target);

        for (Milliseconds delay : { 0ms, 265ms, 562ms })
            caster->m_Events.AddEventAtOffset([caster, targetGUID = target->GetGUID()] { LaunchMissile(caster, targetGUID); }, delay);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_sylvanas_windrunner_heartseeker::HandleMissiles, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    static void LaunchMissile(Unit* caster, ObjectGuid const& targetGUID)
    {
        Unit* target = ObjectAccessor::GetUnit(*caster, targetGUID);
        if (!target)
            return;

        caster->SendPlaySpellVisual(target, SpellVisuals::Heartseeker, 0, 0, 36.0f, false);

        uint32 const timer = uint32(caster->GetDistance(target) * 0.0277 * 1000);

        if (Aura* heartseeker = caster->GetAura(Spells::RangerHeartseekerCharge))
            heartseeker->ModStackAmount(-1, AuraRemoveMode::AURA_REMOVE_BY_DEFAULT);

        caster->m_Events.AddEventAtOffset([caster, targetGUID] { HitTarget(caster, targetGUID); }, Milliseconds(timer));
    }

    static void HitTarget(Unit* caster, ObjectGuid const& targetGUID)
    {
        Unit* target = ObjectAccessor::GetUnit(*caster, targetGUID);
        if (!target)
            return;

        caster->CastSpell(target, Spells::RangerHeartseekerPhysicalDamage, true);
        caster->CastSpell(target, Spells::RangerHeartseekerShadowDamage, true);
    }
};

// 352652 - Ranger's Heartseeker (Shadow damage)
class spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::BansheeMark });
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), Spells::BansheeMark, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 349419 - Domination Chains
class spell_sylvanas_windrunner_domination_chains : public SpellScript
{
    void OnCast(SpellMissInfo /*missInfo*/)
    {
        Unit* caster = GetCaster();

        caster->GetAI()->DoAction(Actions::ResetMeleeKit);

        caster->SendPlaySpellVisualKit(SpellVisualKits::DominationChainsFinish, 0, 0);
    }

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();

        std::list<Creature*> arrowList;
        GetCreatureListWithEntryInGrid(arrowList, caster, NPC_DOMINATION_ARROW, 500.0f);

        for (Creature* arrow : arrowList)
            arrow->GetAI()->DoAction(Actions::ActivateDominationArrow);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_domination_chains::OnCast);
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_domination_chains::HandleAfterCast);
    }
};

// 352317 - Domination Arrow (Fall)
// 352319 - Domination Arrow (Fall and Spawn)
class spell_sylvanas_windrunner_domination_arrow : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleHit(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_domination_arrow::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 349451 - Domination Chain (Player)
class spell_sylvanas_windrunner_domination_chain : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::BarbedArrow, Spells::DominationChainPeriodic });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        GetTarget()->RemoveAura(Spells::BarbedArrow);

        sylvanas->CastSpell(GetTarget(), Spells::DominationChainPeriodic, true);

        _arrowAreaTriggerGUID = AreaTrigger::CreateNewMovementForceId(caster->GetMap(), AreaTriggers::DominationArrow);

        GetTarget()->ApplyMovementForce(_arrowAreaTriggerGUID, caster->GetPosition(), 3.20000004768371582f, MovementForceType::Gravity);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(Spells::DominationChainPeriodic);

        GetTarget()->RemoveMovementForce(_arrowAreaTriggerGUID);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_domination_chain::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_domination_chain::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }

private:
    ObjectGuid _arrowAreaTriggerGUID;
};

// 349458 - Domination Chain (Periodic)
class spell_sylvanas_windrunner_domination_chain_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::DominationChainPeriodic });
    }

    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (aurEff->GetTickNumber() == 3)
            caster->CastSpell(GetTarget(), Spells::DominationChainPeriodic, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_domination_chain_periodic::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 347609 - Wailing Arrow
class spell_sylvanas_windrunner_wailing_arrow : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    int32 CalcCastTime(int32 castTime) override
    {
        if (EventHelpers::GetWorldStatePhase(GetCaster()) == Phases::Three)
            return 1500;

        return castTime;
    }

    void OnPrecast() override
    {
        if (EventHelpers::GetWorldStatePhase(GetCaster()) == Phases::One)
        {
            ScheduleNameplateOnRidingCopy(GetCaster(), 1s + 531ms);
            ScheduleNameplateReset(GetCaster(), 3s + 331ms);
        }
    }

    void HandleLaunchTarget(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow::HandleLaunchTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 348056 - Wailing Arrow (Trigger)
class spell_sylvanas_windrunner_wailing_arrow_trigger : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell, spellInfo->GetEffect(EFFECT_1).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow_trigger::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow_trigger::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 357618 - Wailing Arrow (Raid damage)
class spell_sylvanas_windrunner_wailing_arrow_raid_damage : public SpellScript
{
    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        // Note: this is completely based off research on different sniffs. The reduction might be inaccurate, but it's pretty close to Blizzard's.
        int32 damage = GetHitDamage();

        float const distanceDmgMod = GetCaster()->GetExactDist2d(GetHitUnit()) / 4.5f;

        if (distanceDmgMod < 1.0f)
            return;

        damage /= uint32(distanceDmgMod);

        SetHitDamage(damage);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_wailing_arrow_raid_damage::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 352470 - Veil of Darkness (Fade - Phase 1)
class spell_sylvanas_windrunner_veil_of_darkness_fade : public SpellScript
{
    PrepareSpellScript(spell_sylvanas_windrunner_veil_of_darkness_fade);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo
        ({
            Spells::SylvanasRoot,
            Spells::VeilOfDarknessDeselect,
            Spells::VeilOfDarknessScreenFog
        });
    }

    void OnPrecast() override
    {
        uint32 duration = 0;

        switch (GetSpellInfo()->Id)
        {
            case Spells::VeilOfDarknessPhase1Fade:
                duration = 9750;
                break;
            default:
                break;
        }

        GetCaster()->CastSpell(GetCaster(), Spells::SylvanasRoot, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, duration));
    }

    void OnCast(SpellMissInfo /*missInfo*/)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        instance->DoCastSpellOnPlayers(Spells::VeilOfDarknessScreenFog);

        GetCaster()->CastSpell(GetCaster(), Spells::VeilOfDarknessDeselect, true);
        GetCaster()->SetPower(GetCaster()->GetPowerType(), 0);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_veil_of_darkness_fade::OnCast);
    }
};

// 350335 - Veil of Darkness (Grow - Phase 1)
class spell_sylvanas_windrunner_veil_of_darkness_grow_phase_1 : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetAnimTier(AnimTier::Fly);
        target->SetDisableGravity(true);
        target->SetHover(true);

        target->SetDisplayId(DisplayIds::SylvanasBanshee);

        for (uint8 virtualItem = 0; virtualItem < 3; ++virtualItem)
            target->SetVirtualItem(virtualItem, 0);

        ScheduleNameplateOnRidingCopy(target, 0ms);

        // TODO: on mythic it prefers the biggest clump of ranger players.
        if (Unit const* darknessTarget = target->GetAI()->SelectTarget(SelectTargetMethod::Random, 0, 500.0f, true, true))
        {
            Position const darknessTargetPos(darknessTarget->GetPositionX(), darknessTarget->GetPositionY(), darknessTarget->GetPositionZ());

            uint32 spellVisual = 0;

            switch (target->GetMap()->GetDifficultyID())
            {
                case DIFFICULTY_HEROIC_RAID:
                    spellVisual = SpellVisuals::VeilOfDarknessPhaseOneHeroic;
                    break;
                case DIFFICULTY_MYTHIC_RAID:
                    spellVisual = SpellVisuals::VeilOfDarknessPhaseOneMythic;
                    break;
                default:
                    spellVisual = SpellVisuals::VeilOfDarknessPhaseOneLfrAndNormal;
                    break;
            }

            target->SendPlayOrphanSpellVisual(Position(darknessTargetPos.GetPositionX(), darknessTargetPos.GetPositionY(), darknessTargetPos.GetPositionZ() + 0.05f), spellVisual, 5.0f, true, false);

            target->NearTeleportTo(darknessTargetPos);
        }

        target->SendPlaySpellVisualKit(SpellVisualKits::VeilOfDarknessPhaseOne, 0, 0);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetAnimTier(AnimTier::Ground);
        target->SetDisableGravity(false);
        target->SetHover(false);

        target->SetDisplayId(DisplayIds::SylvanasElf);

        target->SetVirtualItem(0, VirtualItems::SylvanasDagger);
        target->SetVirtualItem(1, VirtualItems::SylvanasDagger);
        target->SetVirtualItem(2, VirtualItems::SylvanasBow);

        ScheduleNameplateReset(target, 0ms);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_veil_of_darkness_grow_phase_1::OnApply, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_veil_of_darkness_grow_phase_1::AfterRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 347726 - Veil of Darkness (Cast - Phase 1)
class spell_sylvanas_windrunner_veil_of_darkness_phase_1 : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo
        ({
            Spells::SylvanasRoot,
            spellInfo->GetEffect(EFFECT_0).TriggerSpell,
            spellInfo->GetEffect(EFFECT_1).TriggerSpell
        });
    }

    int32 CalcCastTime(int32 castTime) override
    {
        if (EventHelpers::GetWorldStatePhase(GetCaster()) == Phases::One)
            return 4000;

        return castTime;
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void HandleAfterCast()
    {
        ScheduleAttackResume(GetCaster(), 1s + 985ms);

        GetCaster()->CastSpell(GetCaster(), Spells::SylvanasRoot, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 3750));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_phase_1::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_phase_1::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_veil_of_darkness_phase_1::HandleAfterCast);
    }
};

// 350777 - Veil of Darkness (Damage)
class spell_sylvanas_windrunner_veil_of_darkness_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::VeilOfDarknessAbsorbAura })
            && ValidateSpellEffect({ { Spells::VeilOfDarknessAbsorbAura, EFFECT_4 } });
    }

    void HandleOnHit(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();

        if (caster->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC_RAID && caster->GetMap()->GetDifficultyID() != DIFFICULTY_HEROIC_RAID)
            return;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(Spells::VeilOfDarknessAbsorbAura, GetCastDifficulty());

        for (int32 stackAmount = spellInfo->GetEffect(EFFECT_4).CalcValue() - 1; stackAmount > 0; --stackAmount)
            caster->CastSpell(GetHitUnit(), Spells::VeilOfDarknessAbsorbAura, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_veil_of_darkness_damage::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 355749 - Veil of Darkness (Periodic)
class spell_sylvanas_windrunner_veil_of_darkness_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::VeilOfDarknessAbsorbAura })
            && ValidateSpellEffect({ { Spells::VeilOfDarknessAbsorbAura, EFFECT_0 }, { Spells::VeilOfDarknessAbsorbAura, EFFECT_3 } });
    }

    void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (!GetCaster())
            return;

        Unit* target = GetTarget();

        Aura* veilOfDarknessDebuff = target->GetAura(Spells::VeilOfDarknessAbsorbAura);
        if (!veilOfDarknessDebuff || veilOfDarknessDebuff->GetStackAmount() == 1)
            return;

        float const radius = veilOfDarknessDebuff->GetSpellInfo()->GetEffect(EFFECT_3).CalcValue();
        uint8 const targetSize = veilOfDarknessDebuff->GetSpellInfo()->GetEffect(EFFECT_0).CalcValue();

        std::list<Player*> playerList;
        target->GetPlayerListInGrid(playerList, radius);
        playerList.remove_if([target](Player const* player) { return player == target; });
        if (playerList.size() > targetSize)
            playerList.resize(targetSize);

        for (Player* spreadTarget : playerList)
        {
            target->SendPlaySpellVisual(spreadTarget, SpellVisuals::VeilOfDarknessSpread, 0, 0, 0.60f, true);
            target->m_Events.AddEventAtOffset([target, spreadTargetGUID = spreadTarget->GetGUID()] { Spread(target, spreadTargetGUID); }, 600ms);
        }

        if (!playerList.empty())
            veilOfDarknessDebuff->ModStackAmount(-int32(playerList.size()));
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_veil_of_darkness_periodic::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    static void Spread(Unit* source, ObjectGuid const& spreadTargetGUID)
    {
        Unit* spreadTarget = ObjectAccessor::GetUnit(*source, spreadTargetGUID);
        InstanceScript* instance = source->GetInstanceScript();
        if (!spreadTarget || !instance)
            return;

        if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->CastSpell(spreadTarget, Spells::VeilOfDarknessAbsorbAura, true);
    }
};

// 347704 - Veil of Darkness (Absorb)
class spell_sylvanas_windrunner_veil_of_darkness_debuff : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::VeilOfDarknessVisualDummy });
    }

    void OnHealAbsorb(AuraEffect* /*aurEff*/, HealInfo& healInfo, uint32& absorbAmount)
    {
        absorbAmount = CalculatePct(healInfo.GetHeal(), GetEffectInfo(EFFECT_2).CalcValue());
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget()->GetMap()->GetDifficultyID() != DIFFICULTY_MYTHIC_RAID && GetTarget()->GetMap()->GetDifficultyID() != DIFFICULTY_HEROIC_RAID)
            return;

        if (GetStackAmount() == 1)
            GetTarget()->RemoveAurasDueToSpell(Spells::VeilOfDarknessVisualDummy);
    }

    void Register() override
    {
        OnEffectAbsorbHeal += AuraEffectAbsorbHealFn(spell_sylvanas_windrunner_veil_of_darkness_debuff::OnHealAbsorb, EFFECT_1);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_veil_of_darkness_debuff::AfterRemove, EFFECT_1, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

// 353417 - Rive
// 353418 - Rive (Fast)
class spell_sylvanas_windrunner_rive : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo
        ({
            Spells::RiveChain,
            Spells::RiveChainFast,
            spellInfo->GetEffect(EFFECT_0).TriggerSpell
        });
    }

    void OnPrecast() override
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        if (Creature* shadowCopy3 = GetShadowcopy(instance, Shadowcopy::Index03))
        {
            shadowCopy3->CastSpell(sylvanas, GetSpellInfo()->Id == Spells::Rive ? Spells::RiveChain : Spells::RiveChainFast);

            for (uint32 platformSpireIndex = GAMEOBJECT_TORGHAST_SPIKE_01; platformSpireIndex < GAMEOBJECT_TORGHAST_SPIKE_12 + 1; platformSpireIndex++)
            {
                std::list<GameObject*> platformSpire;
                shadowCopy3->GetGameObjectListWithEntryInGrid(platformSpire, platformSpireIndex, 10.0f);

                if (platformSpire.empty())
                    continue;

                if (GameObject* nearestPlatformSpire = platformSpire.front())
                    nearestPlatformSpire->SetSpellVisualId(GetSpellInfo()->Id == Spells::Rive ? SpellVisuals::TorghastSpireBreak : SpellVisuals::TorghastSpireBreakFast, sylvanas->GetGUID());
            }
        }
    }

    void HandleAfterCast()
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        if (Creature const* shadowCopy = GetShadowcopy(instance, Shadowcopy::Index00))
            sylvanas->CastSpell(shadowCopy->GetPosition(), GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_rive::HandleAfterCast);
    }
};

// 353375 - Rive (AreaTrigger)
class spell_sylvanas_windrunner_rive_areatrigger : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        // TODO: find out why it won't relocate.
        dest.RelocateOffset({ 0.0f, 0.0f, 0.0f, float(M_PI + 0.040f) });
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_sylvanas_windrunner_rive_areatrigger::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 348094 - Banshee Wail
class spell_sylvanas_windrunner_banshee_wail : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo
        ({
            Spells::BansheeWailExpire,
            Spells::BansheeWailMarker,
            spellInfo->GetEffect(EFFECT_0).TriggerSpell
        });
    }

    void OnPrecast() override
    {
        GetCaster()->CastSpell(GetCaster(), Spells::BansheeWailExpire, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 5000));

        std::list<Player*> targetList;
        GetPlayerListInGrid(targetList, GetCaster(), 500.0f);

        for (Player* target : targetList)
            GetCaster()->CastSpell(target, Spells::BansheeWailMarker, CastSpellExtraArgs(TRIGGERED_FULL_MASK).AddSpellMod(SPELLVALUE_DURATION, 4650));
    }

    void HandleAfterCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        std::list<Player*> targetList;
        GetPlayerListInGrid(targetList, caster, 500.0f);

        for (Player* target : targetList)
            caster->CastSpell(target, GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sylvanas_windrunner_banshee_wail::HandleAfterCast);
    }
};

// 357719 - Banshee Wail (Marker)
class spell_sylvanas_windrunner_banshee_wail_marker : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SendPlaySpellVisualKit(GetTarget()->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID ?
            SpellVisualKits::BansheeScreamExpireMythic : SpellVisualKits::BansheeScreamExpire, 0, 0);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_banshee_wail_marker::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 348108 - Banshee Wail (Triggered Missile)
class spell_sylvanas_windrunner_banshee_wail_triggered_missile : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell, spellInfo->GetEffect(EFFECT_1).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_banshee_wail_triggered_missile::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_banshee_wail_triggered_missile::HandleDummyEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 351252 - Banshee Wail (Interrupt)
class spell_sylvanas_windrunner_banshee_wail_interrupt : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ Spells::BansheeWailSilence });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (target->HasUnitState(UNIT_STATE_CASTING))
            GetCaster()->CastSpell(target, Spells::BansheeWailSilence, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_banshee_wail_interrupt::HandleHit, EFFECT_0, SPELL_EFFECT_INTERRUPT_CAST);
    }
};

// 348146 - Banshee Form
class spell_sylvanas_windrunner_banshee_form : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetAnimTier(AnimTier::Fly);
        target->SetDisableGravity(true);
        target->SetHover(true);

        for (uint8 virtualItem = 0; virtualItem < 3; ++virtualItem)
            target->SetVirtualItem(virtualItem, 0);

        ScheduleNameplateOnRidingCopy(target, 0ms);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();

        target->SetAnimTier(AnimTier::Ground);
        target->SetDisableGravity(false);
        target->SetHover(false);

        target->SetVirtualItem(0, VirtualItems::SylvanasDagger);
        target->SetVirtualItem(1, VirtualItems::SylvanasDagger);
        target->SetVirtualItem(2, VirtualItems::SylvanasBow);

        ScheduleNameplateReset(target, 0ms);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_banshee_form::OnApply, EFFECT_0, SPELL_AURA_FLY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_banshee_form::AfterRemove, EFFECT_0, SPELL_AURA_FLY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 178081 - Highlord Bolvar Fordragon
struct npc_sylvanas_windrunner_bolvar : public ScriptedAI
{
    npc_sylvanas_windrunner_bolvar(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                me->GetAI()->AttackStart(sylvanas);

        _events.ScheduleEvent(Events::Bolvar::RunicMark, 1s);
        _events.ScheduleEvent(Events::Bolvar::GlyphOfDesintegration, 5s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case Events::Bolvar::RunicMark:
                    DoCastVictim(!me->IsWithinMeleeRange(me->GetVictim()) ? Spells::RunicMark : Spells::RunicMarkTriggered);
                    _events.Repeat(6s, 8s);
                    break;

                case Events::Bolvar::GlyphOfDesintegration:
                    DoCastVictim(Spells::GlyphOfDesintegration);
                    _events.Repeat(10s, 12s);
                    break;

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 354928 - Runic Mark (Triggered)
class spell_sylvanas_windrunner_runic_mark_triggered : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_sylvanas_windrunner_runic_mark_triggered::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 176532 - Thrall
struct npc_sylvanas_windrunner_thrall : public ScriptedAI
{
    npc_sylvanas_windrunner_thrall(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                me->GetAI()->AttackStart(sylvanas);

        _events.ScheduleEvent(Events::Thrall::Flameaxe, 6s + 300ms);
        _events.ScheduleEvent(Events::Thrall::Pulverize, 9s);

        //_events.ScheduleEvent(Events::Thrall::StonecrashPhaseOneAndThree, 8s + 400ms, EventGroups::Normal, Phases::One);

        if (me->GetAreaId() != AREA_THE_CRUCIBLE)
            _events.ScheduleEvent(Events::Thrall::EarthenGrasp, 11s + 800ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case Events::Thrall::Flameaxe:
                    DoCastSelf(Spells::Flameaxe);
                    _events.Repeat(18s, 20s);
                    break;

                case Events::Thrall::Pulverize:
                    DoCastVictim(Spells::Pulverize);
                    _events.Repeat(9s + 750ms, 15s + 800ms);
                    break;

                case Events::Thrall::StonecrashPhaseOneAndThree:
                    DoCastVictim(Spells::Stonecrash);
                    _events.Repeat(12s, 18s);
                    break;

                case Events::Thrall::EarthenGrasp:
                    DoCastVictim(Spells::EarthenGrasp);
                    if (me->GetAreaId() != AREA_THE_CRUCIBLE)
                        _events.Repeat(8s, 10s);
                    break;

                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 354918 - Pulverize
class spell_sylvanas_windrunner_pulverize : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sylvanas_windrunner_pulverize::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 354923 - Pulverize (Triggered)
class spell_sylvanas_windrunner_pulverize_triggered : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_pulverize_triggered::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 357139 - Stonecrash (Phase 1 and 3)
class spell_sylvanas_windrunner_stonecrash_phase_one_and_three : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_stonecrash_phase_one_and_three::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 176533 - Jaina Proudmoore
struct npc_sylvanas_windrunner_jaina : public ScriptedAI
{
    npc_sylvanas_windrunner_jaina(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _casterKitCombo = 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                me->GetAI()->AttackStartCaster(sylvanas, 25.0f);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;

        DoJainaAttackIfReady();
    }

    void DoJainaAttackIfReady()
    {
        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasReactState(REACT_PASSIVE))
            return;

        if (me->isAttackReady(BASE_ATTACK))
        {
            switch (_casterKitCombo)
            {
                case CasterKitCombo::NonPowerfulSpell01:
                case CasterKitCombo::NonPowerfulSpell02:
                case CasterKitCombo::NonPowerfulSpell03:
                    DoCastVictim(Spells::IceBolt);
                    _casterKitCombo++;
                    break;

                case CasterKitCombo::PowerfulSpell01:
                    DoCastVictim(Spells::CometBarrage);
                    _casterKitCombo++;
                    break;

                case CasterKitCombo::PowerfulSpell02:
                    DoCastVictim(me->GetDistance(me->GetVictim()) > 8.0f ? Spells::FrigidShards : Spells::ConeOfCold);
                    _casterKitCombo = 0;
                    break;

                default:
                    break;
            }

            me->resetAttackTimer(BASE_ATTACK);
        }
    }

private:
    uint8 _casterKitCombo = 0;
};

// 354933 - Frigid Shards
class spell_sylvanas_windrunner_frigid_shards : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(GetTarget(), aurEff->GetSpellEffectInfo().TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_frigid_shards::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 354938 - Comet Barrage
class spell_sylvanas_windrunner_comet_barrage : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitDest()->GetPosition(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_sylvanas_windrunner_comet_barrage::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 352312 - Energize Power Aura (Sylvanas)
class spell_sylvanas_windrunner_energize_power_aura : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        int32 const powerGained = _sylvanasPowerRegenCycle[_powerRegenCycle];

        _powerRegenCycle = (_powerRegenCycle + 1) % _sylvanasPowerRegenCycle.size();

        GetTarget()->ModifyPower(GetTarget()->GetPowerType(), powerGained);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_sylvanas_windrunner_energize_power_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    // Note: Sylvanas regenerates 10 energy points every 3s roughly.
    static constexpr std::array<int32, 3> _sylvanasPowerRegenCycle = { 3, 3, 4 };

    uint8 _powerRegenCycle = 0;
};

// 359429 - Activate Phase Intermission
class spell_sylvanas_windrunner_activate_phase_intermission : public SpellScript
{
    void HandleBeforeHit(SpellMissInfo /*missInfo*/)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->GetAI()->DoAction(Actions::PrepareIntermission);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_activate_phase_intermission::HandleBeforeHit);
    }
};

// 359431 - Activate Finish Boss
class spell_sylvanas_windrunner_activate_finish_boss : public SpellScript
{
    void HandleBeforeHit(SpellMissInfo /*missInfo*/)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->GetAI()->DoAction(Actions::PrepareFinishBoss);
    }

    void Register() override
    {
        BeforeHit += BeforeSpellHitFn(spell_sylvanas_windrunner_activate_finish_boss::HandleBeforeHit);
    }
};

// 355537 - Modify Champions' Faction
class spell_sylvanas_windrunner_modify_champions_faction : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetUnitFlag2(UNIT_FLAG2_IGNORE_REPUTATION);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveUnitFlag2(UNIT_FLAG2_IGNORE_REPUTATION);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_sylvanas_windrunner_modify_champions_faction::OnApply, EFFECT_0, SPELL_AURA_MOD_FACTION, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_sylvanas_windrunner_modify_champions_faction::OnRemove, EFFECT_0, SPELL_AURA_MOD_FACTION, AURA_EFFECT_HANDLE_REAL);
    }
};

// 23028 - Rive
struct at_sylvanas_windrunner_rive : AreaTriggerAI
{
    at_sylvanas_windrunner_rive(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) {}

    void OnUpdate(uint32 /*diff*/) override
    {
        if (!at->HasSplines())
            return;

        int32 const splineIndex = GetCurrentSplineIndex();
        if (splineIndex == _lastSplineIndex)
            return;

        _lastSplineIndex = splineIndex;
        OnSplineIndexReached(splineIndex);
    }

    void OnDestinationReached() override
    {
        if (!at->HasSplines())
            return;

        // AreaTrigger::Update calls this before OnUpdate, so the final index isn't handled twice in the same tick.
        _lastSplineIndex = GetCurrentSplineIndex();
        OnSplineIndexReached(_lastSplineIndex);
    }

    // mirrors the progress calculation of AreaTrigger::CalculateLocalSplinePositionAndRotation, translated to the index of the points passed to AreaTrigger::InitSplines.
    int32 GetCurrentSplineIndex() const
    {
        float progress = at->GetTimeToTarget() ? std::clamp(float(at->GetElapsedTimeForMovement()) / float(at->GetTimeToTarget()), 0.0f, 1.0f) : 1.0f;

        if (uint32 const moveCurveId = at->m_areaTriggerData->MoveCurveId)
        {
            float const curveProgress = sDB2Manager.GetCurveValueAt(moveCurveId, progress);
            if (curveProgress >= 0.0f && curveProgress <= 1.0f)
                progress = curveProgress;
        }

        ::Movement::Spline<float> const& spline = at->GetSpline();

        int32 splineIndex = 0;
        float percentFromLastPoint = 0.0f;
        spline.computeIndex(progress, splineIndex, percentFromLastPoint);

        return splineIndex - spline.first();
    }

    void OnSplineIndexReached(int32 splineIndex) const
    {
        if (!_instance)
            return;

        Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        if (!sylvanas)
            return;

        if (splineIndex != 0 && splineIndex != 14)
        {
            for (uint8 i = 0; i < 2; i++)
            {
                Position const debrisPos = at->GetRandomNearPosition(25.0f);
                if (!IsOnPlatform(debrisPos))
                    continue;

                float const speed = frand(1.52007603645324707f, 2.203702926635742187f);

                at->SendPlayOrphanSpellVisual(debrisPos, SpellVisuals::RivenDebris, speed, true, false);

                uint32 const timer = uint32(speed * 1000);

                sylvanas->m_Events.AddEventAtOffset([sylvanas, debrisPos] { sylvanas->CastSpell(debrisPos, Spells::RivenDebris, true); }, Milliseconds(timer));
            }
        }

        if (splineIndex == 14)
            at->Remove();
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || !unit->IsPlayer())
            return;

        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            sylvanas->CastSpell(unit, Spells::RiveDamage, true);
    }

private:
    InstanceScript* const _instance;
    int32 _lastSplineIndex = -1;
};

// 45 - Sylvanas Windrunner's Position Z Check (Serverside)
struct at_sylvanas_windrunner_z_check : AreaTriggerAI
{
    at_sylvanas_windrunner_z_check(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsAlive())
            return;

        if (Player* player = unit->ToPlayer())
        {
            if (player->IsGameMaster())
                return;

            if (player->IsAlive())
                player->KillSelf(false);
        }
    }
};

// 46 - Sylvanas Windrunner's Conversation Introduction (Serverside)
struct at_sylvanas_windrunner_introduction : AreaTriggerAI
{
    at_sylvanas_windrunner_introduction(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void OnUnitEnter(Unit* unit) override
    {
        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            Conversation::CreateConversation(Conversations::Introduction, sylvanas, sylvanas->GetPosition(), ObjectGuid::Empty);

        // Note: we're removing it to improve performance since AreaTrigger keeps using GridSearcher even if we return Update.
        at->Remove();
    }
};

struct IntroductionStep
{
    Milliseconds Delay;
    void (*Action)(Creature* sylvanas, Creature* bolvar);
};

static constexpr IntroductionStep IntroductionSteps[] =
{
    { 5s + 500ms, [](Creature* sylvanas, Creature* bolvar)
    {
        sylvanas->SendPlaySpellVisualKit(SpellVisualKits::SylvanasIntroductionTalk01, 0, 0);
        sylvanas->SetFacingToObject(bolvar);
    } },
    { 1s + 140ms,  [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->GetMotionMaster()->MovePoint(Points::Introduction, Positions::Introduction[0], false); } },
    { 1s + 500ms,  [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->SendPlaySpellVisualKit(SpellVisualKits::SylvanasIntroductionTalk02, 0, 0); } },
    { 3s + 360ms,  [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->GetMotionMaster()->MovePoint(Points::Introduction, Positions::Introduction[1], false); } },
    { 469ms,       [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->SendPlaySpellVisualKit(SpellVisualKits::SylvanasIntroductionTalk03, 0, 0); } },
    { 3s + 500ms,  [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->SendPlaySpellVisualKit(SpellVisualKits::SylvanasIntroductionTalk04, 0, 0); } },
    { 2s,          [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->SendPlaySpellVisualKit(SpellVisualKits::SylvanasIntroductionTalk05, 0, 0); } },
    { 5s,          [](Creature* sylvanas, Creature* bolvar) { sylvanas->SetFacingToObject(bolvar); } },
    { 750ms,       [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->SendPlaySpellVisualKit(SpellVisualKits::SylvanasIntroductionTalk06, 0, 0); } },
    { 457ms,       [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->GetMotionMaster()->MovePoint(Points::Introduction, Positions::Introduction[2], false); } },
    { 5s + 89ms, [](Creature* sylvanas, Creature* bolvar)
    {
        bolvar->SetFacingToObject(sylvanas);
        bolvar->SendPlaySpellVisualKit(SpellVisualKits::BolvarIntroductionTalk01, 0, 0);
    } },
    { 13s + 567ms, [](Creature* sylvanas, Creature* bolvar) { sylvanas->SetFacingToObject(bolvar); } },
    { 484ms,       [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->SendPlaySpellVisualKit(SpellVisualKits::SylvanasIntroductionTalk07, 0, 0); } },
    { 5s + 516ms,  [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->SendPlaySpellVisualKit(SpellVisualKits::SylvanasIntroductionTalk08, 0, 0); } },
    { 1s + 516ms, [](Creature* sylvanas, Creature* /*bolvar*/)
    {
        sylvanas->NearTeleportTo(Positions::Introduction[3], false);
        sylvanas->SendPlaySpellVisualKit(SpellVisualKits::Teleport, 0, 0);
    } },
    { 1s + 265ms,  [](Creature* sylvanas, Creature* bolvar) { sylvanas->SetFacingToObject(bolvar); } },
    { 969ms,       [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->SendPlaySpellVisualKit(SpellVisualKits::SylvanasIntroductionTalk09, 0, 0); } },
    { 4s + 766ms,  [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->SendPlaySpellVisualKit(SpellVisualKits::SylvanasIntroductionTalk10, 0, 0); } },
    { 3s + 250ms,  [](Creature* sylvanas, Creature* /*bolvar*/) { sylvanas->CastSpell(sylvanas, Spells::RangerBowStance, CastSpellExtraArgs(TRIGGERED_NONE).SetCustomArg(false)); } },
    { 16ms, [](Creature* sylvanas, Creature* /*bolvar*/)
    {
        sylvanas->CastSpell(sylvanas, Spells::GenericAnchorHere);

        if (InstanceScript* instance = sylvanas->GetInstanceScript())
            instance->SetData(DATA_SYLVANAS_INTRODUCTION, DONE);
    } }
};

// 17368 - Sylvanas Windrunner's Introduction (Conversation)
class conversation_sylvanas_windrunner_introduction : public ConversationAI
{
public:
    conversation_sylvanas_windrunner_introduction(Conversation* conversation) : ConversationAI(conversation) {}

    void OnCreate(Unit* creator) override
    {
        InstanceScript* instance = creator->GetInstanceScript();
        if (!instance)
            return;

        Creature* bolvar = instance->GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE);
        if (!bolvar)
            return;

        instance->SetData(DATA_SYLVANAS_INTRODUCTION, IN_PROGRESS);

        conversation->AddActor(NPC_BOLVAR_FORDRAGON_PINNACLE, ConversationActors::IntroductionBolvar, bolvar->GetGUID());

        std::vector<SequenceStep> steps;
        for (IntroductionStep const& step : IntroductionSteps)
        {
            steps.push_back({ step.Delay, [this, action = step.Action]
            {
                Creature* sylvanas = conversation->GetActorCreature(ConversationActors::IntroductionSylvanas);
                Creature* bolvar = conversation->GetActorCreature(ConversationActors::IntroductionBolvar);
                if (sylvanas && bolvar)
                    action(sylvanas, bolvar);
            } });
        }

        ScheduleSequence(_scheduler, std::move(steps));
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 2799 - Sylvanas Windrunner's Intermission Scene
class scene_sylvanas_windrunner_intermission : public SceneScript
{
public:
    scene_sylvanas_windrunner_intermission() : SceneScript("scene_sylvanas_windrunner_intermission") {}

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        if (player->GetAreaId() != AREA_PINNACLE_OF_DOMINANCE)
            return;

        if (InstanceScript* instance = player->GetInstanceScript())
            instance->SetData(DATA_SYLVANAS_INTERMISSION_FINISH, 1);
    }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        if (player->GetAreaId() != AREA_PINNACLE_OF_DOMINANCE)
            return;

        if (InstanceScript* instance = player->GetInstanceScript())
            instance->SetData(DATA_SYLVANAS_INTERMISSION_FINISH, 1);
    }
};
}

void AddSC_boss_sylvanas_windrunner()
{
    using namespace Scripts::Shadowlands::SanctumOfDomination::SylvanasWindrunner;

    RegisterSanctumOfDominationCreatureAI(boss_sylvanas_windrunner);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_shadowcopy);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_shadowcopy_riding);
    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_domination_arrow);

    RegisterSpellAndAuraScriptPair(spell_sylvanas_windrunner_ranger_bow, spell_sylvanas_windrunner_ranger_bow_aura);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_dagger);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_shot);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_strike);
    RegisterSpellScript(spell_sylvanas_windrunner_windrunner);
    RegisterSpellScript(spell_sylvanas_windrunner_disappear);
    RegisterSpellScript(spell_sylvanas_windrunner_withering_fire);
    RegisterSpellScript(spell_sylvanas_windrunner_desecrating_shot);
    RegisterSpellScript(spell_sylvanas_windrunner_heartseeker);
    RegisterSpellScript(spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_chains);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_arrow);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_chain);
    RegisterSpellScript(spell_sylvanas_windrunner_domination_chain_periodic);
    RegisterSpellScript(spell_sylvanas_windrunner_wailing_arrow);
    RegisterSpellScript(spell_sylvanas_windrunner_wailing_arrow_trigger);
    RegisterSpellScript(spell_sylvanas_windrunner_wailing_arrow_raid_damage);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_fade);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_grow_phase_1);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_phase_1);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_damage);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_periodic);
    RegisterSpellScript(spell_sylvanas_windrunner_veil_of_darkness_debuff);
    RegisterSpellScript(spell_sylvanas_windrunner_rive);
    RegisterSpellScript(spell_sylvanas_windrunner_rive_areatrigger);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail_marker);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail_triggered_missile);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_wail_interrupt);
    RegisterSpellScript(spell_sylvanas_windrunner_banshee_form);

    RegisterSpellScript(spell_sylvanas_windrunner_energize_power_aura);
    RegisterSpellScript(spell_sylvanas_windrunner_activate_phase_intermission);
    RegisterSpellScript(spell_sylvanas_windrunner_activate_finish_boss);
    RegisterSpellScript(spell_sylvanas_windrunner_modify_champions_faction);

    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_bolvar);
    RegisterSpellScript(spell_sylvanas_windrunner_runic_mark_triggered);

    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_thrall);
    RegisterSpellScript(spell_sylvanas_windrunner_pulverize);
    RegisterSpellScript(spell_sylvanas_windrunner_pulverize_triggered);
    RegisterSpellScript(spell_sylvanas_windrunner_stonecrash_phase_one_and_three);

    RegisterSanctumOfDominationCreatureAI(npc_sylvanas_windrunner_jaina);
    RegisterSpellScript(spell_sylvanas_windrunner_frigid_shards);
    RegisterSpellScript(spell_sylvanas_windrunner_comet_barrage);

    RegisterAreaTriggerAI(at_sylvanas_windrunner_rive);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_introduction);
    RegisterAreaTriggerAI(at_sylvanas_windrunner_z_check);

    new scene_sylvanas_windrunner_intermission();

    RegisterConversationAI(conversation_sylvanas_windrunner_introduction);
}
