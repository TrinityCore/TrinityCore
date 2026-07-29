/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CUSTOM_INSTANCE_DEADMINES_H
#define CUSTOM_INSTANCE_DEADMINES_H

#include "CreatureAIImpl.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Position.h"
#include "SpellAuraDefines.h"

namespace Scripts::EasternKingdoms::Deadmines
{
    // Shared crowd-control immunity profile applied to Deadmines bosses.
    inline void ApplyCrowdControlImmunities(Creature* creature)
    {
        creature->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
        creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
        creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
        creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
        creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
        creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
        creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
        creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
        creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
        creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
        creature->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
        creature->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
    }

    namespace Misc
    {
        constexpr char const* DMScriptName = "custom_instance_deadmines";
        constexpr char const* DataHeader = "DM";
        static constexpr int8 EncounterCount = 7;
        static constexpr uint32 DeadminesVersion = 1000;
        static constexpr uint32 EntranceCannonFired = 1001;
        static constexpr uint32 HelixOafDead = 1002;
        static constexpr uint32 GoblinFoundryEventStarted = 1003;
        static constexpr uint32 GoblinFoundryEventNPC = 1004;
        static constexpr uint32 GoblinFoundryTrigger1Fired = 1005;
        static constexpr uint32 GoblinFoundryTrigger2Fired = 1006;
        static constexpr uint32 FoeReaperAddCounter = 1007;
        static constexpr uint32 FoeReaper5000AOEWarning = 1008;
        static constexpr uint32 RipsnarlFogActive = 1009;
        static constexpr uint32 RipsnarlVaporAchievement = 1010;
        static constexpr uint32 CookieDietFailed = 1011;
        static constexpr uint32 VanessaNightmareState = 1012;
        static constexpr uint32 NightmareHelixState = 1013;
        static constexpr uint32 NightmareMechanicalState = 1014;
        static constexpr uint32 SteamValveCount = 1015;
        static constexpr uint32 ActiveNightmare = 1016;
        static constexpr uint32 VindicatorElixirTime = 1017;
    }

    namespace Version
    {
        static constexpr int8 NotSet = 0;
        static constexpr int8 Classic = 1;
        static constexpr int8 Modern = 2;
    }

    namespace DataTypes
    {
        static constexpr int8 BOSS_GLUBTOK = 0;
        static constexpr int8 BOSS_HELIX_GEARBREAKER = 1;
        static constexpr int8 BOSS_FOE_REAPER_5000 = 2;
        static constexpr int8 BOSS_ADMIRAL_RIPSNARL = 3;
        static constexpr int8 BOSS_CAPTAIN_COOKIE = 4;
        static constexpr int8 BOSS_VANESSA_VANCLEEF = 5;
    }

    namespace Creatures
    {
        // Bosses
        static constexpr uint32 Glubtok = 47162;
        static constexpr uint32 HelixGearbreaker = 47296;
        static constexpr uint32 FoeReaper5000 = 43778;
        static constexpr uint32 AdmiralRipsnarl = 47626;
        static constexpr uint32 CaptainCookie = 47739;
        static constexpr uint32 VanessaVanCleef = 49541;

        // Glubtok Adds
        static constexpr uint32 FireBlossom = 48957;
        static constexpr uint32 FrostBlossom = 48958;
        static constexpr uint32 FireWall2A = 48976;
        static constexpr uint32 FireWall1A = 48975;
        static constexpr uint32 FireWall1B = 49039;
        static constexpr uint32 FireWall2B = 49041;
        static constexpr uint32 FireWall1C = 49040;
        static constexpr uint32 FireWall2C = 49042;
        static constexpr uint32 GlubtokMainPlatter = 48974;
        static constexpr uint32 FrostBlossomDummy = 47284;
        static constexpr uint32 FireBlossomDummy = 47282;
        static constexpr uint32 BeamBunny = 47242;
        static constexpr uint32 FirewallBunny = 101052;
        static constexpr uint32 GlubtokDead = 47290;

        // Trash
        static constexpr uint32 OgreHenchman = 48230;
        static constexpr uint32 OgreBodyguard = 48262;
        static constexpr uint32 MiningPowder = 48284;
        static constexpr uint32 MiningMonkey1 = 48278;
        static constexpr uint32 MiningMonkey2 = 48440;
        static constexpr uint32 MiningMonkey3 = 48441;
        static constexpr uint32 MiningMonkey4 = 48442;
        static constexpr uint32 DefiasOverseer = 48421;
        static constexpr uint32 DefiasPirate = 48522;

        // Helix Gearbreaker
        static constexpr uint32 HelixCrew = 49136;
        static constexpr uint32 StickyBomb = 47314;
        static constexpr uint32 LumberingOaf = 47297;
        static constexpr uint32 HelixGearBreaker = 47296;
        static constexpr uint32 MineRat = 51462;

        // Goblin Foundry Event
        static constexpr uint32 GoblinCraftsman = 48280;
        static constexpr uint32 GoblinEngineer = 48439;

        // Foe Reaper 5000
        static constexpr uint32 DefiasReaper = 47403;
        static constexpr uint32 DefiasWatcher = 47404;
        static constexpr uint32 PrototypeReaper = 49208;
        static constexpr uint32 MoltenSlag = 49229;
        static constexpr uint32 GeneralPurposeBunny = 47242;
        static constexpr uint32 HarvestTargetVisual = 47468;

        // Entrance Event
        static constexpr uint32 DefiasCannon = 48266;
        static constexpr uint32 SchorchMarkBunny = 48446;

        // Faction-Specific NPCs
        static constexpr uint32 StormwindDefender = 50595;
        static constexpr uint32 HoratioLaine = 46612;
        static constexpr uint32 CrimeSceneBot = 46613;
        static constexpr uint32 StormwindInvestigator = 46614;
        static constexpr uint32 QuartermasterLewis = 491;

        static constexpr uint32 MissMayhem = 46902;
        static constexpr uint32 MayhemPrototype = 46903;
        static constexpr uint32 Kagtha = 46889;
        static constexpr uint32 SlinkySharpshiv = 46906;
        static constexpr uint32 ShatteredHandAssassin = 46890;

        // Cannon Tunnel
        static constexpr uint32 DefiasEnforcer = 48502;
        static constexpr uint32 DefiasBloodWizzard = 48417;
        static constexpr uint32 DefiasShadowguard = 48505;
        static constexpr uint32 GeneralPurposeBunnyJMF = 45979;

        // Admiral Ripsnarl
        static constexpr uint32 Vapor = 47714;

        // Captain Cookie
        static constexpr uint32 Cauldron = 47754;
        static constexpr uint32 GoodFoodCorn = 48006;
        static constexpr uint32 GoodFoodMelon = 48294;
        static constexpr uint32 GoodFoodSteak = 48296;
        static constexpr uint32 GoodFoodMysteryMeat = 48297;
        static constexpr uint32 GoodFoodLoaf = 48300;
        static constexpr uint32 GoodFoodBun = 48301;
        static constexpr uint32 RottenCorn = 48276;
        static constexpr uint32 RottenMelon = 48293;
        static constexpr uint32 RottenSteak = 48295;
        static constexpr uint32 RottenMysteryMeat = 48298;
        static constexpr uint32 RottenLoaf = 48299;
        static constexpr uint32 RottenBun = 48302;
        static constexpr uint32 VanessaNote = 49564;

        // Vanessa VanCleef Encounter
        static constexpr uint32 VanessaIntro = 49429;
        static constexpr uint32 TrapBunny = 49454;
        static constexpr uint32 SteamValve = 49457;
        static constexpr uint32 Spark = 49520;
        static constexpr uint32 SparkPassenger = 49521;
        static constexpr uint32 Rope = 49550;
        static constexpr uint32 RopeAnchor = 49552;
        static constexpr uint32 EnragedWorgen = 49532;
        static constexpr uint32 EmmeHarrington = 49534;
        static constexpr uint32 ErikHarrington = 49535;
        static constexpr uint32 CalissaHarrington = 49536;
        static constexpr uint32 JamesHarrington = 49539;
        static constexpr uint32 JamesHarringtonHuman = 49682;
        static constexpr uint32 NightmareGlubtok = 49670;
        static constexpr uint32 NightmareHelix = 49674;
        static constexpr uint32 NightmareFoeReaper = 49681;
        static constexpr uint32 VanessaNightmare = 49671;
        static constexpr uint32 CollapsingIcicle = 49481;
        static constexpr uint32 NightmareSpider = 49493;
        static constexpr uint32 MainSpider = 49494;
        static constexpr uint32 ChatteringHorror = 49495;
        static constexpr uint32 FireBunny = 51594;
        static constexpr uint32 DefiasEnforcerVanessa = 49502;
        static constexpr uint32 DefiasShadowguardVanessa = 49505;
        static constexpr uint32 DefiasBloodWizardVanessa = 49854;
        static constexpr uint32 DefiasEnvoker = 48418;
        static constexpr uint32 OafLackey = 48445;
        static constexpr uint32 GoblinOverseer = 48279;
        static constexpr uint32 VanessaAnchorBunnyJMF = 51624;
        static constexpr uint32 GeneralPurposeBunnyJMF3 = 47677;
    }

    namespace CreatureSpawns
    {
        static constexpr uint32 OgreHenchmanByCannon = 375931;
        static constexpr uint32 OgreHenchmanSleeper = 375925;

        static constexpr uint32 OafMoveToBunny = 375849;
        static constexpr uint32 OafChargePosition = 375850;

        // Cannons at Ship
        static constexpr uint32 ImpactBunny1 = 376039;
        static constexpr uint32 ImpactBunny2 = 375946;
        static constexpr uint32 ImpactBunny3 = 375953;
        static constexpr uint32 ImpactBunny4 = 375886;
        static constexpr uint32 ImpactBunny5 = 375887;
        static constexpr uint32 ImpactBunny6 = 376045;
        static constexpr uint32 ImpactBunny7 = 375954;

        static constexpr uint32 CannonFiring1 = 376088;
        static constexpr uint32 CannonFiring2 = 376001;
        static constexpr uint32 CannonFiring3 = 376087;
        static constexpr uint32 CannonFiring4 = 376067;
        static constexpr uint32 CannonFiring5 = 376090;
        static constexpr uint32 CannonFiring6 = 376044;
        static constexpr uint32 CannonFiring7 = 376041;

        // Cookie Encounter
        static constexpr uint32 CuldronSpawnBunny = 375838;
        static constexpr uint32 CookieJumpCuldronBunny = 376143;

        // Vanessa Encounter
        static constexpr uint32 HelixNightmareMainSpiderBunny = 375846;
    }

    namespace Objects
    {
        // Doors
        static constexpr uint32 FactoryDoor = 13965;
        static constexpr uint32 IronCladDoor = 16397;
        static constexpr uint32 MastRoomDoor = 16400;
        static constexpr uint32 HeavyDoor = 17153;
        static constexpr uint32 FoundryDoor = 16399;
        static constexpr uint32 DefiasCannon = 442661;
        static constexpr uint32 DoorLever = 101833;

        static constexpr uint32 MysteriousDeadminesChest = 180024;

        // Teleporters
        static constexpr uint32 GoblinTeleporter = 208002;
        static constexpr uint32 BallAndChain = 207079;
    }

    namespace TeleporterSpawnIds
    {
        static constexpr uint32 IronCladCove = 235317;
        static constexpr uint32 DungeonEntrance = 235318;
        static constexpr uint32 FoundryRoom = 235319;
        static constexpr uint32 MastRoom = 235320;
    }

    namespace Achievements
    {
        static constexpr uint32 ReadyForRaidingDeadmines = 5366;
        static constexpr uint32 ItsFrostDamage = 5369;
        static constexpr uint32 ImOnADiet = 5370;
        static constexpr uint32 VigorousVanCleefVindicator = 5371;
    }

    namespace Texts
    {
        static constexpr uint32 GoblinTeleporterMenuID = 12691;

        // Glubtok
        static constexpr int8 GlubtokDeath = 0;
        static constexpr int8 GlubtokArcanePower = 1;
        static constexpr int8 GlubtokAggro = 2;
        static constexpr int8 GlubtokKill = 3;
        static constexpr int8 GlubtokFire = 4;
        static constexpr int8 GlubtokHead1 = 5;
        static constexpr int8 GlubtokFrost = 6;
        static constexpr int8 GlubtokHead2 = 7;

        // Ogre Henchman
        static constexpr int8 OgreHenchmanOOC = 0;
        static constexpr int8 OgreHenchmanSleep = 1;
        static constexpr int8 OgreHenchmanCandle = 2;
        static constexpr int8 OgreHenchmanAggro = 3;

        // Ogre Bodyguard
        static constexpr int8 OgreBodyguardAggro = 0;
        static constexpr int8 OgreBodyguardFrenzy = 1;
        static constexpr int8 OgreBodyguardConversation1 = 2;
        static constexpr int8 OgreBodyguardConversation2 = 3;
        static constexpr int8 OgreBodyguardConversation3 = 4;
        static constexpr int8 OgreBodyguardConversation4 = 5;
        static constexpr int8 OgreBodyguardConversation5 = 6;
        static constexpr int8 OgreBodyguardConversation6 = 7;
        static constexpr int8 OgreBodyguardConversation7 = 8;
        static constexpr int8 OgreBodyguardConversation8 = 9;
        static constexpr int8 OgreBodyguardConversation9 = 10;
        static constexpr int8 OgreBodyguardConversation10 = 11;

        // Helix Crew
        static constexpr int8 HelixCrewStickyBomb = 0;

        // Lumbering Oaf
        static constexpr int8 OafCharge = 0;
        static constexpr int8 OafSmash = 1;

        // Helix
        static constexpr int8 HelixDeath = 0;
        static constexpr int8 HelixKill = 1;
        static constexpr int8 HelixOafDead = 2;
        static constexpr int8 HelixBombs = 3;
        static constexpr int8 HelixFaceRide = 4;
        static constexpr int8 HelixAggro = 5;
        static constexpr int8 HelixChestBomb = 6;

        // Defias Overseer
        static constexpr int8 OverseerLine1 = 0;
        static constexpr int8 OverseerLine2 = 1;
        static constexpr int8 OverseerLine3 = 2;
        static constexpr int8 OverseerLine4 = 3;
        static constexpr int8 OverseerLine5 = 4;
        static constexpr int8 OverseerLine6 = 5;
        static constexpr int8 OverseerLine7 = 6;
        static constexpr int8 OverseerLine8 = 7;
        static constexpr int8 OverseerLine9 = 8;
        static constexpr int8 OverseerLine10 = 9;
        static constexpr int8 OverseerFlee = 10;

        // Foe Reaper 5000
        static constexpr int8 FoeReaperInit = 9;
        static constexpr int8 FoeReaperAggro = 0;
        static constexpr int8 FoeReaperKill = 2;
        static constexpr int8 FoeReaperDeath = 1;
        static constexpr int8 FoeReaperMoltenSlag = 10;
        static constexpr int8 FoeReaperOverdrive = 5;
        static constexpr int8 FoeReaperOverdriveWarning = 6;
        static constexpr int8 FoeReaperHarvest = 4;
        static constexpr int8 FoeReaperHarvestSweep = 3;
        static constexpr int8 FoeReaperSafetyOff = 7;
        static constexpr int8 FoeReaperSafetyOffWarning = 8;

        // Goblin Foundry Event
        // Goblin Craftsman (48280)
        static constexpr int8 GoblinCraftsmanAlive = 0;
        static constexpr int8 GoblinCraftsmanYellAlive = 1;
        static constexpr int8 GoblinCraftsmanNo = 2;

        // Goblin Engineer (48439)
        static constexpr int8 GoblinEngineerRun = 0;

        // Admiral Ripsnarl (47626) - maps to creature_text GroupIDs
        static constexpr int8 RipsnarlDeath = 0;
        static constexpr int8 RipsnarlKill = 1;
        static constexpr int8 RipsnarlFog = 2;
        static constexpr int8 RipsnarlGoForThroat = 3;
        static constexpr int8 RipsnarlAggro = 4;
        static constexpr int8 RipsnarlAnnounceVapor = 5;

        // Cookie
        static constexpr int8 CookieSpawnWarning = 0;
        static constexpr int8 CookieHeroicNote = 1;

        namespace VanessaVanCleef
        {
            // A note from Vanessa
            static constexpr int8 ANoteFromVanessaNotif = 0;

            // Vanessa Intro
            static constexpr int8 VanessaIntroWarning = 0;
            static constexpr int8 VanessaSay1 = 1;
            static constexpr int8 VanessaSay2 = 2;
            static constexpr int8 VanessaSay3 = 3;
            static constexpr int8 VanessaSay4 = 4;
            static constexpr int8 VanessaSay5 = 5;

            // Boss
            static constexpr int8 Aggro = 0;
            static constexpr int8 Summons = 1;
            static constexpr int8 Bomb50pct = 2;
            static constexpr int8 Bomb25pct = 3;
            static constexpr int8 KilledUnit = 4;
            static constexpr int8 VanessaDetonation1 = 5;
            static constexpr int8 VanessaDetonation2 = 6;
            static constexpr int8 VanessaDefeated1 = 7;
            static constexpr int8 VanessaDefeated2 = 8;
            static constexpr int8 VanessaDetonation3 = 9;
            static constexpr int8 VanessaDefeated3 = 10;

            // Trap Bunny
            static constexpr int8 VanessaTrapBunnyWarning = 0;
            static constexpr int8 VanessaTrapBunnyValves = 1;

            // Vanessa Nightmare
            static constexpr int8 VanessaNightmareWarning = 0;
            static constexpr int8 VanessaNightmareGlubtok1 = 1;
            static constexpr int8 VanessaNightmareGlubtok2 = 2;
            static constexpr int8 VanessaNightmare1Warning = 3;
            static constexpr int8 VanessaNightmareGetBackToTheShip = 4;
            static constexpr int8 VanessaNightmareShift = 5;
            static constexpr int8 VanessaNightmare2Warning = 6;
            static constexpr int8 VanessaNightmareHelix1 = 7;
            static constexpr int8 VanessaNightmareHelix2 = 8;
            static constexpr int8 VanessaNightmare3Warning = 9;
            static constexpr int8 VanessaNightmareMechanical1 = 10;
            static constexpr int8 VanessaNightmareMechanical2 = 11;
            static constexpr int8 VanessaNightmareRipsnarl1 = 12;
            static constexpr int8 VanessaNightmareRipsnarl2 = 13;
            static constexpr int8 VanessaNightmare4Warning = 14;
            static constexpr int8 VanessaNightmareSaveEmme = 15;
            static constexpr int8 VanessaNightmareSaveErik = 16;
            static constexpr int8 VanessaNightmareSaveCalissa = 17;
            static constexpr int8 VanessaNightmareElixirOff = 18;

            // Harringtons
            static constexpr int8 JamesHarrington0 = 0;
            static constexpr int8 CalissaHarrington0 = 0;
            static constexpr int8 CalissaHarrington1 = 1;
        }
    }

    namespace Spells
    {
        static constexpr uint32 GoblinTeleporter = 55695;

        // Glubtok
        static constexpr uint32 ArcanePower = 88009;
        static constexpr uint32 FistOfFlame = 87859;
        static constexpr uint32 FistOfFlame0 = 87896;
        static constexpr uint32 FistOfFrost = 87861;
        static constexpr uint32 FistOfFrost0 = 87901;
        static constexpr uint32 FireBlossom = 88129;
        static constexpr uint32 FireBlossomVisual = 88164;
        static constexpr uint32 FrostBlossom = 88169;
        static constexpr uint32 FrostBlossomVisual = 88165;
        static constexpr uint32 TeleportVisual = 88002;
        static constexpr uint32 Blink = 87925;
        static constexpr uint32 BlossomTargetting = 88140;
        static constexpr uint32 ArcaneFire = 88007;
        static constexpr uint32 ArcaneFireBeam = 88072;
        static constexpr uint32 ArcaneFrostBeam = 88093;
        static constexpr uint32 SummonFireBlossom = 91301;
        static constexpr uint32 SummonFrostBlossom = 91302;
        static constexpr uint32 TriggerFireWall = 91398;
        static constexpr uint32 FireWallTriggered = 91397;
        static constexpr uint32 ArcaneOverloadInitial = 88183;
        static constexpr uint32 FeignDeath = 70628;
        static constexpr uint32 ArcaneOverloadSuicide = 88185;
        static constexpr uint32 ArcaneOverloadBoom = 90520;

        // Ogre Henchman
        static constexpr uint32 Uppercut = 91045;
        static constexpr uint32 OgrishMotivationNormal = 89652;
        static constexpr uint32 OgrishMotivationHeroic = 92747;
        static constexpr uint32 AuraSleep = 78677;

        // Ogre Bodyguard
        static constexpr uint32 Bonk = 91050;
        static constexpr uint32 Frenzy = 91053;

        // Mining Powder
        static constexpr uint32 Explode = 89769;

        // Defias Cannon
        static constexpr uint32 DefiasCannonCannonballFire = 89697;

        // Defias Pirate
        static constexpr uint32 LeapCleave = 90905;

        // Helix Gearbreaker
        static constexpr uint32 RideOaf = 88277;
        static constexpr uint32 OafSmash = 88300;
        static constexpr uint32 OafSmashHeroic = 91568;
        static constexpr uint32 OafCharge = 88288;
        static constexpr uint32 OafGrabTargeting = 88289;
        static constexpr uint32 HelixRide = 88337;
        static constexpr uint32 HelixRideFaceTimerAura = 88351;
        static constexpr uint32 RideVehicle = 88360; // used for Helix face riding player
        static constexpr uint32 ThrowBomb = 88264;
        static constexpr uint32 OafGuard = 90546;
        static constexpr uint32 HelixLeap = 86345;
        static constexpr uint32 ChestBomb = 88352;
        static constexpr uint32 ChestBombDMG = 88250;

        // Sticky Bomb
        static constexpr uint32 ArmingVisualYellow = 88315;
        static constexpr uint32 ArmingVisualOrange = 88316;
        static constexpr uint32 ArmingVisualRed = 88317;
        static constexpr uint32 ArmedState = 88319;
        static constexpr uint32 StickyBombExplode = 95500; // has normal and heroic effects
        //static constexpr uint32 StickyBombExplode = 88974;
        //static constexpr uint32 StickyBombExplodeHeroic = 91566;

        // Goblin Foundry Event
        static constexpr uint32 CosmeticCower = 78087;

        // Foe Reaper 5000
        static constexpr uint32 Offline = 88348;
        static constexpr uint32 RedEyes = 24263;
        static constexpr uint32 FoeEnergize = 89200; // cast self when immune to dmg
        static constexpr uint32 FoeMoltenSlag = 91839;
        static constexpr uint32 Energize = 89132; // from other reapers to Foe

        static constexpr uint32 Cleave = 90980;
        static constexpr uint32 Energized = 90978;
        static constexpr uint32 OnFire = 91737;
        static constexpr uint32 Watch = 90099;
        static constexpr uint32 ReaperStrike = 88490; //91723 this is for the prototype reaper
        static constexpr uint32 Overdrive = 88481;
        static constexpr uint32 Harvest = 88497; // 88495
        static constexpr uint32 HarvestAura = 88501; // 88497;
        static constexpr uint32 HarvestTargetVisual = 71371;
        static constexpr uint32 HarvestSweep = 88521;
        static constexpr uint32 SafetyOffline = 88522;

        // Prototype Reaper
        static constexpr uint32 PrototypeReaperCharge = 91726;
        static constexpr uint32 PrototypeReaperReaperStrike = 91723;
        static constexpr uint32 PrototypeReaperPressurizedStrike = 91727;

        // Admiral Ripsnarl
        static constexpr uint32 ThirstForBlood = 88736;
        static constexpr uint32 ThirstForBloodAura = 88737;
        static constexpr uint32 Swipe = 88839;
        static constexpr uint32 SwipeHeroic = 91859; // not used since the original spell has effects for diff
        static constexpr uint32 GoForTheThroat = 88836;
        static constexpr uint32 GoForTheThroatHeroic = 91863; // not used since the original spell has effects for diff
        static constexpr uint32 RipsnarlsFogAura = 89247;
        static constexpr uint32 RipsnarlFogVisualSmall = 88768; // applied on GeneralPurposeBunny (47242)
        static constexpr uint32 RipsnarlFogVisualLarge = 88755; // applied on GeneralPurposeBunnyJMF (45979)
        static constexpr uint32 SummonVapor = 88831;
        // Admiral Ripsnarl Vapor
        static constexpr uint32 Condensation = 92013;
        static constexpr uint32 CondenseStage1 = 92014;
        static constexpr uint32 CondenseStage2 = 92018;
        static constexpr uint32 CondenseStage3 = 92031;
        static constexpr uint32 SwirlingVapor = 92007;
        static constexpr uint32 CondensingVapor = 92008;
        static constexpr uint32 FreezingVapor = 92011;
        static constexpr uint32 Coalesce = 92042;
        static constexpr uint32 RipsnarlAchievement = 95647;
        static constexpr uint32 RipsnarlCancelAchievement = 95648;

        // Captain Cookie
        static constexpr uint32 WhoIsThat = 89339;
        static constexpr uint32 Satiated = 89267;
        static constexpr uint32 Nauseated = 89732;
        static constexpr uint32 RottenAura = 89734;
        static constexpr uint32 CauldronSummon = 89250;
        static constexpr uint32 CauldronVisual = 89251;
        static constexpr uint32 CauldronFire = 89252;
        static constexpr uint32 CookieAchievCredit = 95650;
        static constexpr uint32 CookieAchievRemove = 95651;

        // Throw food targeting spells
        static constexpr uint32 ThrowFoodCorn = 89268;
        static constexpr uint32 ThrowFoodRottenCorn = 89740;
        static constexpr uint32 ThrowFoodMelon = 90561;
        static constexpr uint32 ThrowFoodRottenMelon = 90582;
        static constexpr uint32 ThrowFoodSteak = 90562;
        static constexpr uint32 ThrowFoodRottenSteak = 90583;
        static constexpr uint32 ThrowFoodMysteryMeat = 90563;
        static constexpr uint32 ThrowFoodRottenMysteryMeat = 90584;
        static constexpr uint32 ThrowFoodLoaf = 90564;
        static constexpr uint32 ThrowFoodRottenLoaf = 90585;
        static constexpr uint32 ThrowFoodBun = 90565;
        static constexpr uint32 ThrowFoodRottenBun = 90586;
        static constexpr uint32 ThrowFoodWithMurloc = 90680;

        // Direct throw food spells used by the boss
        static constexpr uint32 ThrowFood01 = 90557;
        static constexpr uint32 ThrowFood02 = 90560;
        static constexpr uint32 ThrowFood03 = 90603;
        static constexpr uint32 ThrowFood04 = 89739;
        static constexpr uint32 ThrowFood05 = 90605;
        static constexpr uint32 ThrowFood06 = 90556;
        static constexpr uint32 ThrowFood07 = 90680;
        static constexpr uint32 ThrowFood08 = 90559;
        static constexpr uint32 ThrowFood09 = 90602;
        static constexpr uint32 ThrowFood10 = 89263;
        static constexpr uint32 ThrowFood11 = 90604;
        static constexpr uint32 ThrowFood12 = 90555;

        namespace VanessaVanCleef
        {
            static constexpr uint32 Backslash = 92619;
            static constexpr uint32 Deflection = 92614;
            static constexpr uint32 DeadlyBlades = 92622;
            static constexpr uint32 Vengeance = 95542;
            static constexpr uint32 PowderExplosion = 96283;
            static constexpr uint32 VanessaCosmeticBombState = 96280;
            static constexpr uint32 FieryBlaze = 93484;
            static constexpr uint32 FieryBlazeDamage = 93485;
            static constexpr uint32 ClickMe = 95527;
            static constexpr uint32 Evasion = 90958;
            static constexpr uint32 Shadowstep = 90956;
            static constexpr uint32 SinisterStrike = 90951;
            static constexpr uint32 WhirlingBlades = 90960;
            static constexpr uint32 Charge = 90928;
            static constexpr uint32 Recklessness = 90929;
            static constexpr uint32 Bloodbath = 90925;
            static constexpr uint32 BloodBolt = 90938;
            static constexpr uint32 BloodWash = 90946;
            static constexpr uint32 Ragezone = 90932;
            static constexpr uint32 HolyFire = 91004;
            static constexpr uint32 RenegadeRunning = 90047;
            static constexpr uint32 Shield = 92001;
            static constexpr uint32 Motivate = 91036;
            static constexpr uint32 Threatening = 91034;
            static constexpr uint32 Uppercut = 91045;
            static constexpr uint32 AxeHead = 90098;
            static constexpr uint32 Enrage = 8599;
            static constexpr uint32 NightmareElixir = 92113;
            static constexpr uint32 NightmareElixirEffect = 92563;
            static constexpr uint32 Blackout = 92120;
            static constexpr uint32 NoxiousConcoction = 92100;
            static constexpr uint32 Sitting = 89279;
            static constexpr uint32 GenericRideVehicle = 46598;
            static constexpr uint32 RopeBeam = 43785;
            static constexpr uint32 AynashasRoot = 18373;
            static constexpr uint32 Icicle = 92189;
            static constexpr uint32 IcicleVisual = 92201;
            static constexpr uint32 IcicleDamage = 62453;
            static constexpr uint32 SpiritStrike = 59304;
            static constexpr uint32 Sprint = 92604;
            static constexpr uint32 GreenMarker = 88455;
            static constexpr uint32 SteamAura = 92399;
            static constexpr uint32 NightmareElixirEffectRemove = 92583;
            static constexpr uint32 NightmareElixirGlubtok = 92565;
            static constexpr uint32 NightmareElixirGlubtokRemove = 92584;
            static constexpr uint32 NightmareElixirHelix = 92566;
            static constexpr uint32 NightmareElixirHelixRemove = 92585;
            static constexpr uint32 NightmareElixirMechanical = 92567;
            static constexpr uint32 NightmareElixirMechanicalRemove = 92586;
            static constexpr uint32 NightmareElixirRipsnarl = 92568;
            static constexpr uint32 NightmareElixirRipsnarlRemove = 92587;
        }
    }

    namespace Events
    {
        static constexpr int8 GlubtokCastFistOfFlame = 1;
        static constexpr int8 GlubtokCastFistOfFrost = 2;
        static constexpr int8 GlubtokCastBlink = 3;
        static constexpr int8 GlubtokCastBlossom = 4;
        static constexpr int8 GlubtokCastArcanePower1 = 5;
        static constexpr int8 GlubtokCastArcanePower2 = 6;
        static constexpr int8 GlubtokCastArcanePower3 = 7;
        static constexpr int8 GlubtokFallGround = 8;
        static constexpr int8 GlubtokSayFirewall = 9;
        static constexpr int8 GlubtokSpawnFirewallBunny = 10;
        static constexpr int8 GlubtokTransformDead = 11;

        // Ogre Henchman
        static constexpr int8 OgreHenchmanUppercut = 12;
        static constexpr int8 OgreHenchmanOOCSay = 13;
        static constexpr int8 OgreHenchmanSleepEvent = 14;
        static constexpr int8 OgreHenchmanSleepAura = 15;
        static constexpr int8 OgreHenchmanWakeUp = 16;

        // Ogre Bodyguard
        static constexpr int8 OgreBodyguardBonk = 17;
        static constexpr int8 OgreBodyguardConversation = 18;
        static constexpr int8 OgreBodyguardDialogueLine = 19;

        // Helix Crew
        static constexpr int8 HelixCrewStickyBomb = 20;

        // Sticky Bomb
        static constexpr int8 StickyBombInitial = 21;
        static constexpr int8 StickyBombYellow = 22;
        static constexpr int8 StickyBombOrange = 23;
        static constexpr int8 StickyBombRed = 24;
        static constexpr int8 StickyBombArmed = 25;
        static constexpr int8 StickyBombExplode = 26;

        // Lumbering Oaf
        static constexpr int8 OafCharge0 = 27;
        static constexpr int8 OafCharge1 = 28;
        static constexpr int8 OafCharge2 = 29;
        static constexpr int8 OafCharge3 = 30;
        static constexpr int8 OafThrowHelix = 31;
        static constexpr int8 OafPickupHelix = 32;

        // Helix Gearbreaker
        static constexpr int8 HelixThrowBomb = 33;
        static constexpr int8 HelixFaceRide = 34;
        static constexpr int8 HelixExitFaceRide = 35;
        static constexpr int8 HelixSummonCrew = 36;

        // Defias Overseer
        static constexpr int8 OverseerInitController = 37;
        static constexpr int8 OverseerDialogueStart = 38;
        static constexpr int8 OverseerDialogueLine = 39;

        // Goblin Foundry Event
        static constexpr int8 GoblinFoundryEventStarted = 40;
        static constexpr int8 GoblinFoundryEventNPC = 41; // SetData flag to mark event NPCs

        // Goblin Foundry Worker Events
        static constexpr int8 GoblinWorkerStartMovement = 1;
        static constexpr int8 GoblinWorkerRunToFinal = 2;
        static constexpr int8 GoblinWorkerCraftsmanNo = 3;

        // Foe Reaper 5000 Add Events
        static constexpr int8 FoeReaperAddCleave = 1;
        static constexpr int8 FoeReaperAddWatch = 2;
        static constexpr int8 FoeReaperAddDeath = 3;

        // Foe Reaper 5000 Boss Events
        static constexpr int8 FoeReaperInit = 4;
        static constexpr int8 FoeReaperAggro = 5;
        static constexpr int8 FoeReaperReaperStrike = 6;
        static constexpr int8 FoeReaperMoltenSlag = 7;
        static constexpr int8 FoeReaperMoltenSlagWarning = 8;
        static constexpr int8 FoeReaperOverdrive = 9;
        static constexpr int8 FoeReaperOverdriveWarning = 10;
        static constexpr int8 FoeReaperOverdriveSwitchTarget = 11;
        static constexpr int8 FoeReaperHarvest = 12;
        static constexpr int8 FoeReaperHarvestSweep = 13;
        static constexpr int8 FoeReaperSafetyOfflineWarning = 14;
        static constexpr int8 FoeReaperSafetyOffline = 15;

        // Defias Pirate Events
        static constexpr int8 DefiasPirateCannonCheck = 1;
        static constexpr int8 DefiasPirateCannonFire = 2;

        // Admiral Ripsnarl Events
        static constexpr int8 RipsnarlSwipe = 1;
        static constexpr int8 RipsnarlGoForThroat = 2;
        static constexpr int8 RipsnarlSummonVapor = 3;
        static constexpr int8 RipsnarlReveal = 4;
        // Admiral Ripsnarl Vapor Events
        static constexpr int8 VaporSwirling = 5;
        static constexpr int8 VaporCondensing = 6;
        static constexpr int8 VaporFreezing = 7;
        static constexpr int8 VaporCoalesce = 8;

        // Captain Cookie Events
        static constexpr int8 CookieMoveToCauldron = 1;
        static constexpr int8 CookieJumpToCauldron = 2;
        static constexpr int8 CookieEnterCauldron = 3;
        static constexpr int8 CookieThrowFood = 4;
        static constexpr int8 CookieEnableMurloc = 5;

        namespace VanessaVanCleef
        {
            static constexpr int8 Backslash = 1;
            static constexpr int8 Vengeance = 2;
            static constexpr int8 Deflection = 3;
            static constexpr int8 DeadlyBlades = 4;
            static constexpr int8 PowderExplosion = 5;
            static constexpr int8 FieryBlaze = 6;
            static constexpr int8 Shadowguard = 7;
            static constexpr int8 SummonRope = 8;
            static constexpr int8 RopeReady = 9;
            static constexpr int8 Disappear = 10;
            static constexpr int8 FireBoom = 11;
            static constexpr int8 ClearShip = 12;
            static constexpr int8 SummonAdd1 = 13;
            static constexpr int8 SummonAdd2 = 14;
            static constexpr int8 SummonAdd3 = 15;
            static constexpr int8 FinalTimer = 16;
            static constexpr int8 IcicleAOE = 17;
            static constexpr int8 SpiritStrike = 18;
            static constexpr int8 Spiders = 19;
            static constexpr int8 BossIntroMove = 20;
            static constexpr int8 FinalWarning = 21;
            static constexpr int8 FinalDetonation = 22;

            // Intro
            static constexpr int8 IntroJump = 1;
            static constexpr int8 IntroMove = 2;
            static constexpr int8 IntroSay1 = 3;
            static constexpr int8 IntroSay2 = 4;
            static constexpr int8 IntroSay3 = 5;
            static constexpr int8 IntroConcoction = 6;
            static constexpr int8 IntroElixir = 7;
            static constexpr int8 IntroBlackout = 8;

            // Nightmare controller
            static constexpr int8 NightmareSay1 = 29;
            static constexpr int8 NightmareSay2 = 30;
            static constexpr int8 NightmareSummon = 31;
            static constexpr int8 NightmareShift = 32;
            static constexpr int8 NoteTalk = 33;
            static constexpr int8 NoteSummon = 34;
            static constexpr int8 IntroLaugh = 35;
            static constexpr int8 IntroSay4 = 36;
            static constexpr int8 IntroSummonTrap = 37;
            static constexpr int8 IntroBlackout1 = 38;
            static constexpr int8 IntroBlackout2 = 39;
            static constexpr int8 TrapPullPlayers = 40;
            static constexpr int8 TrapDescent = 41;
            static constexpr int8 NightmareGlubtokEntrance = 42;
            static constexpr int8 NightmareFade = 43;
            static constexpr int8 HelixEngage = 44;
            static constexpr int8 GlubtokCharge = 45;
            static constexpr int8 SummonSpiders = 46;
            static constexpr int8 MechanicalEngage = 47;
            static constexpr int8 NightmareElixirReapply = 48;
            static constexpr int8 NightmareSaveEmme = 49;
            static constexpr int8 RopeStartRide = 50;
        }
    }

    namespace Actions
    {
        static constexpr int8 OafCharge = 1;
        static constexpr int8 RipsnarlCoalesce = 2;
        static constexpr int8 GlubtokCharge = 3;
        static constexpr int8 HelixEngage = 4;
        static constexpr int8 MechanicalEngage = 5;

        namespace VanessaVanCleef
        {
            static constexpr int8 EjectAll = 1;
        }
    }

    namespace Points
    {
        namespace VanessaVanCleef
        {
            static constexpr uint32 RopeOut = 1;
            static constexpr uint32 RopeHome = 2;
        }
    }

    namespace Glubtok
    {
        static constexpr Position Phase2Center = { -193.43f, -437.86f, 54.38f, 4.88f };

        static constexpr uint32 PhaseTransitionHealthPct = 50;
        static constexpr uint32 DeathHealthPct = 1;

        // Timers in Seconds
        static constexpr int8 FistOfFlameTimer = 10;
        static constexpr int8 FistOfFrostTimer = 21;
        static constexpr int8 BlinkTimer = 20;
        static constexpr int8 BlossomTimer = 5;
        static constexpr int8 ArcanePower1Timer = 2;
        static constexpr int8 ArcanePower2Timer = 3;
        static constexpr int8 ArcanePower3Timer = 1;
        static constexpr int8 FallGroundTimer = 5;
        static constexpr int8 BoomTimer = 1;
        static constexpr int8 SuicideTimer = 3;
    }

    namespace Items
    {
        static constexpr uint32 DefiasGunpowder = 221485;
    }

    namespace Quests
    {
        static constexpr uint32 YourFortuneAwaitsInDeadmines = 7938;
    }

    namespace Positions
    {
        static constexpr Position MysteriousDeadminesChest = { -32.1232f, -374.64f, 59.06f, 3.082f };

        // Goblin Foundry Event
        static constexpr Position GoblinCraftsman1Spawn = { -227.5972f, -587.4663f, 51.2344f, 2.3098f};
        static constexpr Position GoblinCraftsman1MoveTo = { -235.5213f, -581.7625f, 51.2185f, 2.5064f };
        static constexpr Position GoblinCraftsman2Spawn = { -217.2094f, -559.3613f, 51.23f, 3.8655f };
        static constexpr Position GoblinEngineer1Spawn = { -226.0326f, -567.9048f, 51.2304f, 4.1899f };
        static constexpr Position GoblinEngineer2Spawn = { -209.1832f, -554.1334f, 51.2297f, 3.2826f };
        static constexpr Position GoblinMoveTo = { -235.8898f, -577.8178f, 51.2258f, 3.1784f };
        static constexpr Position GoblinRunTo1 = { -277.722f, -495.944f, 49.6921f, 4.76221f };
        static constexpr Position GoblinRunTo2 = { -272.104f, -488.595f, 49.2876f, 5.79361f };
        static constexpr Position GoblinRunTo3 = { -273.826f, -477.703f, 49.2435f, 1.04438f };
        static constexpr Position GoblinRunTo4 = { -278.252f, -485.319f, 48.8387f, 0.289022f };

        // Helix Encounter
        static constexpr Position HelixCrewSpawn[] =
        {
            {-281.68f, -504.10f, 60.51f, 4.75f},
            {-284.71f, -504.13f, 60.42f, 4.72f},
            {-288.65f, -503.74f, 60.38f, 4.64f},
            {-293.88f, -503.90f, 60.07f, 4.77f},
        };

        static constexpr Position OafRatPos[8] =
        {
            {-290.90f, -486.49f, 49.88f},
            {-288.98f, -483.20f, 49.88f},
            {-293.78f, -483.81f, 49.15f},
            {-286.94f, -482.96f, 49.88f},
            {-288.16f, -484.81f, 49.88f},
            {-291.99f, -486.26f, 49.88f},
            {-289.67f, -487.22f, 49.88f},
            {-290.44f, -484.32f, 49.88f}
        };

        // Foe Reaper Encounter
        static constexpr Position PrototypeSpawn = { -200.499f, -553.946f, 51.2295f, 4.32651f };

        static constexpr Position FoeReaper5000AddSpawns[4] =
        {
            { -228.675f, -565.753f, 19.3898f, 5.98648f },
            { -182.743f, -565.969f, 19.3898f, 3.35103f },
            { -205.535f, -552.747f, 19.3898f, 4.53786f },
            { -229.724f, -590.372f, 19.3898f, 0.715585f }
        };

        static constexpr Position MoltenSlagSpawn[4] =
        {
            { -205.582f, -572.034f, 20.97f, 1.59f },
            { -199.143f, -579.843f, 20.97f, 6.16f },
            { -206.385f, -585.898f, 20.97f, 5.17f },
            { -212.704f, -579.072f, 20.97f, 3.09f }
        };

        // Cannon Event (modern version)
        static constexpr Position DefiasBloodWizzard1 = { -97.467f, -675.726f, 7.50242f, 1.78024f };
        static constexpr Position DefiasBloodWizzard2 = { -100.878f, -676.349f, 7.49962f, 1.78024f };
        static constexpr Position DefiasShadowguard = { -98.4774f, -672.389f, 7.50265f, 1.23918f };
        static constexpr Position DefiasEnforcer = { -101.089f, -673.014f, 7.50165f, 1.79769f };

        // Admiral Ripsnarl
        static constexpr Position RipsnarlCaptainCookieSpawn = { -88.1319f, -819.33f, 39.2345f, 0.0f };
        static constexpr Position RipsnarlVaporFinalSpawn[3] =
        {
            { -70.59f, -820.57f, 40.56f, 6.28f },
            { -55.73f, -815.84f, 41.97f, 3.85f },
            { -55.73f, -825.54f, 41.99f, 2.60f },
        };

        // Captain Cookie
        static constexpr Position CookieCauldronSpawn = { -64.2552f, -820.2449f, 41.2374f };
        static constexpr Position VanessaNoteSpawn = { -74.3611f, -820.014f, 40.3714f, 0.0f };

        // Vanessa VanCleef
        static constexpr Position Shadowspawn[3] =
        {
            { -74.61f, -822.91f, 40.22f, 6.24f },
            { -74.98f, -816.88f, 40.18f, 6.24f },
            { -76.12f, -819.95f, 40.08f, 6.24f },
        };

        static constexpr Position VanessaIntroSpawn = { -75.58507f, -819.9636f, 47.06727f, 6.178465f };
        static constexpr Position VanessaIntroMoveTo = { -65.41f, -838.43f, 41.10f };
        static constexpr Position MagmaPullPlayers = { -205.7569f, -579.0972f, 42.98623f, 2.3f };
        static constexpr Position MagmaRopeCeiling = { -205.772781f, -579.3796f, 51.0859f };
        static constexpr Position MagmaPullPlayerExit = { -223.217f, -566.0531f, 51.2296f, 2.3254f };
        static constexpr Position VanessaNightmare1 = { -230.717f, -563.0139f, 51.31293f, 1.047198f };
        static constexpr Position GlubtokNightmare1 = { -229.3403f, -560.3629f, 51.31293f, 5.742133f };
        static constexpr Position GlubtokNightmareCharge = { -174.85f, -579.76f, 19.31f };
        static constexpr Position VanessaNightmare2 = { -174.9222f, -575.641f, 19.3136f, 4.7574f };
        static constexpr Position HelixNightmareSpawn = { -174.85f, -579.76f, 19.31f, 3.14f };
        static constexpr Position VanessaNightmare3 = { -158.648f, -580.9235f, 19.3112f, 0.f };
        static constexpr Position MechanicalNightmareSpawn = { -152.0788f, -581.003f, 19.3151f, 0.1639f };
        static constexpr Position VanessaNightmare4 = { -96.46f, -660.42f, 7.41f, 3.4061f };
        static constexpr Position VanessaNightmare5 = { -103.72f, -724.06f, 8.47f };
        static constexpr Position VanessaNightmare6 = { 2.56f, -776.13f, 9.52f };
        static constexpr Position VanessaNightmare7 = { -83.16319f, -774.9636f, 26.90351f };
        static constexpr Position FoeReaperNightmareSpawn = { -101.4549f, -663.6493f, 7.505813f, 1.85f };
        static constexpr Position VanessaBossSpawn = { -79.44965f, -819.8351f, 39.89838f, 0.01745329f };
        static constexpr Position VanessaBossJumpAtopShip = { -52.31f, -820.18f, 51.91f };

        static constexpr Position ElectricSpark[7] =
        {
            { -101.4959f, -648.5552f, 8.121676f, 0.04567058f },
            { -120.96f, -638.3806f, 13.38522f, 6.237791f },
            { -135.365f, -623.0541f, 15.48179f, 6.237976f },
            { -120.1277f, -617.6179f, 15.28394f, 0.04498905f },
            { -136.7082f, -604.6687f, 16.56965f, 6.2384f },
            { -130.45f, -586.5038f, 19.61726f, 6.238641f },
            { -142.9731f, -574.9221f, 20.18317f, 6.238891f },
        };

        static constexpr Position FieryBlaze[43] =
        {
            { -178.2031f, -594.9965f, 40.6501f, 4.415683f },
            { -220.625f, -577.9618f, 21.06016f, 2.513274f },
            { -205.3056f, -563.6285f, 21.06016f, 5.25344f },
            { -214.8958f, -546.7136f, 19.3898f, 4.712389f },
            { -207.8004f, -570.6441f, 21.06016f, 1.762783f },
            { -221.4653f, -549.9358f, 19.3898f, 3.211406f },
            { -229.9635f, -559.2552f, 19.3898f, 0.0f },
            { -216.8438f, -568.9011f, 21.06016f, 3.909538f },
            { -235.9045f, -563.3906f, 19.3898f, 0.0f },
            { -226.6736f, -580.8316f, 20.43056f, 2.775074f },
            { -227.5226f, -595.1979f, 20.42358f, 4.206244f },
            { -215.0399f, -576.3941f, 21.06016f, 3.735005f },
            { -210.592f, -583.4739f, 21.06016f, 0.0f },
            { -216.5399f, -602.6528f, 24.88029f, 2.687807f },
            { -220.4879f, -596.382f, 21.95116f, 0.0f },
            { -190.4774f, -552.2778f, 51.31293f, 5.305801f },
            { -195.6267f, -550.4393f, 51.31293f, 3.752458f },
            { -209.7257f, -557.1042f, 51.31293f, 3.525565f },
            { -187.9531f, -567.0469f, 51.31293f, 5.305801f },
            { -192.2031f, -595.9636f, 36.37407f, 2.80998f },
            { -183.4236f, -577.2674f, 46.87183f, 3.944444f },
            { -184.6528f, -572.3663f, 49.27317f, 3.159046f },
            { -187.3333f, -550.8143f, 19.3898f, 3.385939f },
            { -185.2083f, -562.4844f, 19.3898f, 0.9599311f },
            { -228.592f, -553.1684f, 19.3898f, 5.550147f },
            { -210.7431f, -603.2813f, 27.17259f, 4.904375f },
            { -194.1302f, -548.3055f, 19.3898f, 4.153883f },
            { -181.2379f, -555.3177f, 19.3898f, 0.3141593f },
            { -191.2205f, -581.4965f, 21.06015f, 2.007129f },
            { -198.4653f, -580.757f, 21.06015f, 0.8901179f },
            { -196.5504f, -587.7031f, 21.06015f, 1.27409f },
            { -241.5938f, -578.6858f, 19.3898f, 2.775074f },
            { -226.1615f, -573.8021f, 20.40991f, 5.218534f },
            { -186.9792f, -556.8472f, 19.3898f, 4.153883f },
            { -201.224f, -570.6788f, 21.06016f, 3.577925f },
            { -196.8767f, -574.9688f, 21.06016f, 4.29351f },
            { -225.6962f, -601.3871f, 21.82762f, 4.555309f },
            { -215.7205f, -608.4722f, 25.87703f, 2.530727f },
            { -197.1007f, -609.7257f, 32.38494f, 0.0f },
            { -221.8629f, -607.2205f, 23.7542f, 4.939282f },
            { -201.9757f, -611.8663f, 30.62297f, 2.897247f },
        };

        static constexpr Position FamilySpawn[4] =
        {
            { -98.63194f, -721.6268f, 8.547067f, 1.53589f },
            { 5.239583f, -763.0868f, 9.800426f, 2.007129f },
            { -83.86406f, -775.2837f, 28.37906f, 1.710423f },
            { -83.16319f, -774.9636f, 26.90351f, 1.710423f }, // Worgen James
        };

        static constexpr Position EnragedWorgen1[3] =
        {
            { -97.79166f, -717.8542f, 8.668088f, 4.520403f },
            { -94.40278f, -719.7274f, 8.598646f, 3.560472f },
            { -101.9167f, -718.7552f, 8.726379f, 5.51524f },
        };

        static constexpr Position EnragedWorgen2[3] =
        {
            { 3.137153f, -760.0313f, 9.725998f, 5.393067f },
            { 8.798013f, -762.2252f, 9.625132f, 3.379143f },
            { 4.232807f, -766.6125f, 9.804724f, 1.292649f },
        };

        static constexpr Position NightmareSpidersSpawn[4] =
        {
            { -198.2469f, -571.0089f, -21.0601f, 3.19f },
            { -200.0299f, -565.434f, -21.0601f, 5.61f },
            { -203.f, -589.4429f, -21.0601f, 5.03f },
            { -206.1629f, -568.8489f, -24.6352f, 5.15f },
        };

        static constexpr Position RopeSpawn[5] =
        {
            { -64.01f, -839.84f, 41.22f, 0.0f },
            { -66.82f, -839.92f, 40.97f, 0.0f },
            { -69.75f, -839.87f, 40.71f, 0.0f },
            { -72.32f, -839.71f, 40.48f, 0.0f },
            { -75.76f, -839.33f, 40.18f, 0.0f },
        };
    }

    namespace Ripsnarl
    {
        static constexpr uint32 FogPhasePct75 = 75;
        static constexpr uint32 FogPhasePct50 = 50;
        static constexpr uint32 FogPhasePct25 = 25;
        static constexpr uint32 HeroicVaporPhasePct = 10;

        static constexpr float FogBunnyRange = 75.0f;

        // Timers in seconds
        static constexpr int8 SwipeTimer = 10;
        static constexpr int8 GoForThroatTimer = 15;
        static constexpr int8 RevealTimer = 20;
        static constexpr int8 SummonVaporTimer = 5;
        // Vapor stage delays (seconds)
        static constexpr int8 VaporStage1Delay = 5;
        static constexpr int8 VaporStage2Delay = 6;
        static constexpr int8 VaporStage3Delay = 5;
        static constexpr int8 VaporCoalesceDelay = 8;
    }

    namespace CannonEvent
    {
        static constexpr int8 DATA_EVENT = 1;

        static constexpr int8 STATE_CANNON_NOT_USED = 0;
        static constexpr int8 STATE_CANNON_GUNPOWDER_USED = 1;
        static constexpr int8 STATE_CANNON_BLAST_INITIATED = 2;
        static constexpr int8 STATE_PIRATES_ATTACK = 3;
        static constexpr int8 STATE_DONE = 4;

        static constexpr uint32 BLAST_TIMER = 3000;
        static constexpr uint32 PIRATES_TIMER = 1000;
    }

    namespace CannonsFiringEvent
    {
        struct CannonImpactPair
        {
            uint32 cannonSpawnId;
            uint32 impactSpawnId;
        };

        static constexpr CannonImpactPair CannonImpactMap[] =
        {
            { CreatureSpawns::CannonFiring1, CreatureSpawns::ImpactBunny1 },
            { CreatureSpawns::CannonFiring2, CreatureSpawns::ImpactBunny2 },
            { CreatureSpawns::CannonFiring3, CreatureSpawns::ImpactBunny3 },
            { CreatureSpawns::CannonFiring4, CreatureSpawns::ImpactBunny4 },
            { CreatureSpawns::CannonFiring5, CreatureSpawns::ImpactBunny5 },
            { CreatureSpawns::CannonFiring6, CreatureSpawns::ImpactBunny6 },
            { CreatureSpawns::CannonFiring7, CreatureSpawns::ImpactBunny7 },
        };

    }

    static constexpr ObjectData modernCreatureData[] =
    {
        { Creatures::Glubtok,              DataTypes::BOSS_GLUBTOK            },
        { Creatures::HelixGearbreaker,     DataTypes::BOSS_HELIX_GEARBREAKER  },
        { Creatures::FoeReaper5000,        DataTypes::BOSS_FOE_REAPER_5000    },
        { Creatures::AdmiralRipsnarl,      DataTypes::BOSS_ADMIRAL_RIPSNARL   },
        { Creatures::CaptainCookie,        DataTypes::BOSS_CAPTAIN_COOKIE     },
        { Creatures::VanessaVanCleef,      DataTypes::BOSS_VANESSA_VANCLEEF   },
    };

    static constexpr DoorData doorData[] =
    {
        { Objects::FactoryDoor,      DataTypes::BOSS_GLUBTOK,           EncounterDoorBehavior::OpenWhenDone             },
        { Objects::MastRoomDoor,     DataTypes::BOSS_HELIX_GEARBREAKER, EncounterDoorBehavior::OpenWhenDone             },
        { Objects::HeavyDoor,        DataTypes::BOSS_HELIX_GEARBREAKER, EncounterDoorBehavior::OpenWhenNotInProgress    },
        { Objects::FoundryDoor,      DataTypes::BOSS_FOE_REAPER_5000,   EncounterDoorBehavior::OpenWhenDone             },
    };

    static constexpr DungeonEncounterData modernEncounters[] =
    {
        { DataTypes::BOSS_GLUBTOK,             {{ 2976, 2981 }}  },
        { DataTypes::BOSS_HELIX_GEARBREAKER,   {{ 2977, 2982 }}  },
        { DataTypes::BOSS_FOE_REAPER_5000,     {{ 2975, 2980 }}  },
        { DataTypes::BOSS_ADMIRAL_RIPSNARL,    {{ 2974, 2979 }}  },
        { DataTypes::BOSS_CAPTAIN_COOKIE,      {{ 2973, 2978 }}  },
        { DataTypes::BOSS_VANESSA_VANCLEEF,    {{ 1081 }}  }
    };
    template <class AI, class T>
    inline AI* GetDeadminesAI(T* obj)
    {
        return GetInstanceAI<AI>(obj, Misc::DMScriptName);
    }
}

#endif // CUSTOM_INSTANCE_DEADMINES_H
