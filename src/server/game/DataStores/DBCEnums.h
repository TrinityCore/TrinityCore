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

#ifndef DBCENUMS_H
#define DBCENUMS_H

#include "Define.h"
#include "EnumFlag.h"
#include <array>

#pragma pack(push, 1)

struct DBCPosition2D
{
    float X;
    float Y;
};

struct DBCPosition3D
{
    float X;
    float Y;
    float Z;
};

#pragma pack(pop)

enum LevelLimit
{
    // Client expected level limitation, like as used in DBC item max levels for "until max player level"
    // use as default max player level, must be fit max level for used client
    // also see MAX_LEVEL and STRONG_MAX_LEVEL define
    DEFAULT_MAX_LEVEL = 60,

    // client supported max level for player/pets/etc. Avoid overflow or client stability affected.
    // also see GT_MAX_LEVEL define
    MAX_LEVEL = 123,

    // Server side limitation. Base at used code requirements.
    // also see MAX_LEVEL and GT_MAX_LEVEL define
    STRONG_MAX_LEVEL = 255,
};

enum BattlegroundBracketId                                  // bracketId for level ranges
{
    BG_BRACKET_ID_FIRST          = 0,
    BG_BRACKET_ID_LAST           = 12,

    // must be max value in PvPDificulty slot + 1
    MAX_BATTLEGROUND_BRACKETS
};

enum AreaTeams
{
    AREATEAM_NONE  = 0,
    AREATEAM_ALLY  = 2,
    AREATEAM_HORDE = 4,
    AREATEAM_ANY   = AREATEAM_ALLY+AREATEAM_HORDE
};

enum AchievementFaction
{
    ACHIEVEMENT_FACTION_HORDE           = 0,
    ACHIEVEMENT_FACTION_ALLIANCE        = 1,
    ACHIEVEMENT_FACTION_ANY             = -1
};

enum AchievementFlags
{
    ACHIEVEMENT_FLAG_COUNTER               = 0x00000001,    // Just count statistic (never stop and complete)
    ACHIEVEMENT_FLAG_HIDDEN                = 0x00000002,    // Not sent to client - internal use only
    ACHIEVEMENT_FLAG_PLAY_NO_VISUAL        = 0x00000004,    // Client does not play achievement earned visual
    ACHIEVEMENT_FLAG_SUMM                  = 0x00000008,    // Use summ criteria value from all requirements (and calculate max value)
    ACHIEVEMENT_FLAG_MAX_USED              = 0x00000010,    // Show max criteria (and calculate max value ??)
    ACHIEVEMENT_FLAG_REQ_COUNT             = 0x00000020,    // Use not zero req count (and calculate max value)
    ACHIEVEMENT_FLAG_AVERAGE               = 0x00000040,    // Show as average value (value / time_in_days) depend from other flag (by def use last criteria value)
    ACHIEVEMENT_FLAG_BAR                   = 0x00000080,    // Show as progress bar (value / max vale) depend from other flag (by def use last criteria value)
    ACHIEVEMENT_FLAG_REALM_FIRST_REACH     = 0x00000100,    //
    ACHIEVEMENT_FLAG_REALM_FIRST_KILL      = 0x00000200,    //
    ACHIEVEMENT_FLAG_UNK3                  = 0x00000400,    // ACHIEVEMENT_FLAG_HIDE_NAME_IN_TIE
    ACHIEVEMENT_FLAG_HIDE_INCOMPLETE       = 0x00000800,    // hide from UI if not completed
    ACHIEVEMENT_FLAG_SHOW_IN_GUILD_NEWS    = 0x00001000,    // Shows in guild news
    ACHIEVEMENT_FLAG_SHOW_IN_GUILD_HEADER  = 0x00002000,    // Shows in guild news header
    ACHIEVEMENT_FLAG_GUILD                 = 0x00004000,    //
    ACHIEVEMENT_FLAG_SHOW_GUILD_MEMBERS    = 0x00008000,    //
    ACHIEVEMENT_FLAG_SHOW_CRITERIA_MEMBERS = 0x00010000,    //
    ACHIEVEMENT_FLAG_ACCOUNT               = 0x00020000,
    ACHIEVEMENT_FLAG_UNK5                  = 0x00040000,
    ACHIEVEMENT_FLAG_HIDE_ZERO_COUNTER     = 0x00080000,    // statistic is hidden from UI if no criteria value exists
    ACHIEVEMENT_FLAG_TRACKING_FLAG         = 0x00100000,    // hidden tracking flag, sent to client in all cases except completion announcements
};

uint32 constexpr ACHIVEMENT_CATEGORY_PET_BATTLES = 15117;

enum AreaFlags
{
    AREA_FLAG_SNOW                  = 0x00000001,                // snow (only Dun Morogh, Naxxramas, Razorfen Downs and Winterspring)
    AREA_FLAG_UNK1                  = 0x00000002,                // Razorfen Downs, Naxxramas and Acherus: The Ebon Hold (3.3.5a)
    AREA_FLAG_UNK2                  = 0x00000004,                // Only used for areas on map 571 (development before)
    AREA_FLAG_SLAVE_CAPITAL         = 0x00000008,                // city and city subzones
    AREA_FLAG_UNK3                  = 0x00000010,                // can't find common meaning
    AREA_FLAG_SLAVE_CAPITAL2        = 0x00000020,                // slave capital city flag?
    AREA_FLAG_ALLOW_DUELS           = 0x00000040,                // allow to duel here
    AREA_FLAG_ARENA                 = 0x00000080,                // arena, both instanced and world arenas
    AREA_FLAG_CAPITAL               = 0x00000100,                // main capital city flag
    AREA_FLAG_CITY                  = 0x00000200,                // only for one zone named "City" (where it located?)
    AREA_FLAG_OUTLAND               = 0x00000400,                // expansion zones? (only Eye of the Storm not have this flag, but have 0x00004000 flag)
    AREA_FLAG_SANCTUARY             = 0x00000800,                // sanctuary area (PvP disabled)
    AREA_FLAG_NEED_FLY              = 0x00001000,                // Respawn alive at the graveyard without corpse
    AREA_FLAG_UNUSED1               = 0x00002000,                // Unused in 3.3.5a
    AREA_FLAG_OUTLAND2              = 0x00004000,                // expansion zones? (only Circle of Blood Arena not have this flag, but have 0x00000400 flag)
    AREA_FLAG_OUTDOOR_PVP           = 0x00008000,                // pvp objective area? (Death's Door also has this flag although it's no pvp object area)
    AREA_FLAG_ARENA_INSTANCE        = 0x00010000,                // used by instanced arenas only
    AREA_FLAG_UNUSED2               = 0x00020000,                // Unused in 3.3.5a
    AREA_FLAG_CONTESTED_AREA        = 0x00040000,                // On PvP servers these areas are considered contested, even though the zone it is contained in is a Horde/Alliance territory.
    AREA_FLAG_UNK6                  = 0x00080000,                // Valgarde and Acherus: The Ebon Hold
    AREA_FLAG_LOWLEVEL              = 0x00100000,                // used for some starting areas with area_level <= 15
    AREA_FLAG_TOWN                  = 0x00200000,                // small towns with Inn
    AREA_FLAG_REST_ZONE_HORDE       = 0x00400000,                // Warsong Hold, Acherus: The Ebon Hold, New Agamand Inn, Vengeance Landing Inn, Sunreaver Pavilion (Something to do with team?)
    AREA_FLAG_REST_ZONE_ALLIANCE    = 0x00800000,                // Valgarde, Acherus: The Ebon Hold, Westguard Inn, Silver Covenant Pavilion (Something to do with team?)
    AREA_FLAG_COMBAT                = 0x01000000,                // "combat" area (Script_GetZonePVPInfo), used
    AREA_FLAG_INSIDE                = 0x02000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_OUTSIDE               = 0x04000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_CAN_HEARTH_AND_RESURRECT = 0x08000000,             // Can Hearth And Resurrect From Area
    AREA_FLAG_NO_FLY_ZONE           = 0x20000000,                // Marks zones where you cannot fly
    AREA_FLAG_UNK9                  = 0x40000000
};

enum AreaFlags2
{
    AREA_FLAG_2_DONT_SHOW_SANCTUARY = 0x00000200,                // Hides sanctuary status from zone text color (Script_GetZonePVPInfo)
    AREA_FLAG_2_CAN_ENABLE_WAR_MODE = 0x00001000,                // Allows enabling war mode
};

enum AreaMountFlags
{
    AREA_MOUNT_FLAG_GROUND_ALLOWED      = 0x1,
    AREA_MOUNT_FLAG_FLYING_ALLOWED      = 0x2,
    AREA_MOUNT_FLAG_FLOAT_ALLOWED       = 0x4,
    AREA_MOUNT_FLAG_UNDERWATER_ALLOWED  = 0x8
};

enum ArtifactCategory : uint32
{
    ARTIFACT_CATEGORY_PRIMARY = 1,
    ARTIFACT_CATEGORY_FISHING = 2
};

enum ArtifactPowerFlag : uint8
{
    ARTIFACT_POWER_FLAG_GOLD                        = 0x01,
    ARTIFACT_POWER_FLAG_NO_LINK_REQUIRED            = 0x02,
    ARTIFACT_POWER_FLAG_FINAL                       = 0x04,
    ARTIFACT_POWER_FLAG_SCALES_WITH_NUM_POWERS      = 0x08,
    ARTIFACT_POWER_FLAG_DONT_COUNT_FIRST_BONUS_RANK = 0x10,
    ARTIFACT_POWER_FLAG_MAX_RANK_WITH_TIER          = 0x20,

    ARTIFACT_POWER_FLAG_FIRST                       = ARTIFACT_POWER_FLAG_NO_LINK_REQUIRED | ARTIFACT_POWER_FLAG_DONT_COUNT_FIRST_BONUS_RANK,
};

#define MAX_ARTIFACT_TIER 1

#define MAX_AZERITE_EMPOWERED_TIER 5

#define MAX_AZERITE_ESSENCE_SLOT 4
#define MAX_AZERITE_ESSENCE_RANK 4

enum class AzeriteItemMilestoneType : int32
{
    MajorEssence    = 0,
    MinorEssence    = 1,
    BonusStamina    = 2
};

enum AzeriteTierUnlockSetFlags
{
    AZERITE_TIER_UNLOCK_SET_FLAG_DEFAULT = 0x1
};

#define BATTLE_PET_SPECIES_MAX_ID 3248

enum class BattlePetSpeciesFlags : uint16
{
    NoRename                 = 0x0001,
    WellKnown                = 0x0002,
    NotAccountWide           = 0x0004,
    Capturable               = 0x0008,
    NotTradable              = 0x0010,
    HideFromJournal          = 0x0020,
    LegacyAccountUnique      = 0x0040,
    CantBattle               = 0x0080,
    HordeOnly                = 0x0100,
    AllianceOnly             = 0x0200,
    Boss                     = 0x0400,
    RandomDisplay            = 0x0800,
    NoLicenseRequired        = 0x1000,
    AddsAllowedWithBoss      = 0x2000,
    HideUntilLearned         = 0x4000,
    MatchPlayerHighPetLevel  = 0x8000
};

DEFINE_ENUM_FLAG(BattlePetSpeciesFlags);

enum class BattlemasterListFlags : uint32
{
    InternalOnly                = 0x01,
    RatedOnly                   = 0x02, // Only set for rated battlegrounds
    ObsoleteDoNotList           = 0x04,
    ShowInWarGames              = 0x08,
    ShowInPvpBattlegroundList   = 0x10,
    IsBrawl                     = 0x20,
    IsFactional                 = 0x40,
    IsEpic                      = 0x80
};

DEFINE_ENUM_FLAG(BattlemasterListFlags);

enum class ChrRacesFlag : int32
{
    NPCOnly                                     = 0x000001,
    DoNotComponentFeet                          = 0x000002,
    CanMount                                    = 0x000004,
    HasBald                                     = 0x000008,
    BindToStartingArea                          = 0x000010,
    AlternateForm                               = 0x000020,
    CanMountSelf                                = 0x000040,
    ForceToHDModelIfAvailable                   = 0x000080,
    ExaltedWithAllVendors                       = 0x000100,
    NotSelectable                               = 0x000200,
    ReputationBonus                             = 0x000400,
    UseLoincloth                                = 0x000800,
    RestBonus                                   = 0x001000,
    NoStartKits                                 = 0x002000,
    NoStartingWeapon                            = 0x004000,
    DontRedeemAccountLicenses                   = 0x008000,
    SkinVariationIsHairColor                    = 0x010000,
    UsePandarenRingForComponentingTexture       = 0x020000,
    IgnoreForAssetManifestComponentInfoParsing  = 0x040000,
    IsAlliedRace                                = 0x080000,
    VoidVendorDiscount                          = 0x100000,
    DAMMComponentNoMaleGeneration               = 0x200000,
    DAMMComponentNoFemaleGeneration             = 0x400000,
    NoAssociatedFactionReputationInRaceChange   = 0x800000,
    InternalOnly                                = 0x100000,
};

DEFINE_ENUM_FLAG(ChrRacesFlag);

enum ChrSpecializationFlag
{
    CHR_SPECIALIZATION_FLAG_CASTER                  = 0x01,
    CHR_SPECIALIZATION_FLAG_RANGED                  = 0x02,
    CHR_SPECIALIZATION_FLAG_MELEE                   = 0x04,
    CHR_SPECIALIZATION_FLAG_UNKNOWN                 = 0x08,
    CHR_SPECIALIZATION_FLAG_DUAL_WIELD_TWO_HANDED   = 0x10,     // used for CUnitDisplay::SetSheatheInvertedForDualWield
    CHR_SPECIALIZATION_FLAG_PET_OVERRIDE_SPEC       = 0x20,
    CHR_SPECIALIZATION_FLAG_RECOMMENDED             = 0x40,
};

enum class ContentTuningCalcType : int32
{
    Base                        = 0,
    PlusOne                     = 1,
    PlusMaxLevelForExpansion    = 2
};

enum class ContentTuningFlag : int32
{
    DisabledForItem = 0x04,
    Horde           = 0x8,
    Alliance        = 0x10
};

DEFINE_ENUM_FLAG(ContentTuningFlag);

enum class CorruptionEffectsFlag
{
    None        = 0,
    Disabled    = 0x1
};

DEFINE_ENUM_FLAG(CorruptionEffectsFlag);

enum class CreatureModelDataFlags : uint32
{
    NoFootprintParticles                    = 0x00001,
    NoBreathParticles                       = 0x00002,
    IsPlayerModel                           = 0x00004,
    NoAttachedWeapons                       = 0x00010,
    NoFootprintTrailTextures                = 0x00020,
    DisableHighlight                        = 0x00040,
    CanMountWhileTransformedAsThis          = 0x00080,
    DisableScaleInterpolation               = 0x00100,
    ForceProjectedTex                       = 0x00200,
    CanJumpInPlaceAsMount                   = 0x00400,
    AICannotUseWalkBackwardsAnim            = 0x00800,
    IgnoreSpineLowForSplitBody              = 0x01000,
    IgnoreHeadForSplitBody                  = 0x02000,
    IgnoreSpineLowForSplitBodyWhenFlying    = 0x04000,
    IgnoreHeadForSplitBodyWhenFlying        = 0x08000,
    UseWheelAnimationOnUnitWheelBones       = 0x10000,
    IsHDModel                               = 0x20000,
    SuppressEmittersOnLowSettings           = 0x40000
};

DEFINE_ENUM_FLAG(CreatureModelDataFlags);

enum class CriteriaFailEvent : uint8
{
    None                                = 0,
    Death                               = 1,    // Death
    Hours24WithoutCompletingDailyQuest  = 2,    // 24 hours without completing a daily quest
    LeaveBattleground                   = 3,    // Leave a battleground
    LoseRankedArenaMatchWithTeamSize    = 4,    // Lose a ranked arena match with team size {#Team Size}
    LoseAura                            = 5,    // Lose aura "{Spell}"
    GainAura                            = 6,    // Gain aura "{Spell}"
    GainAuraEffect                      = 7,    // Gain aura effect "{SpellAuraNames.EnumID}"
    CastSpell                           = 8,    // Cast spell "{Spell}"
    BeSpellTarget                       = 9,    // Have spell "{Spell}" cast on you
    ModifyPartyStatus                   = 10,   // Modify your party status
    LosePetBattle                       = 11,   // Lose a pet battle
    BattlePetDies                       = 12,   // Battle pet dies
    DailyQuestsCleared                  = 13,   // Daily quests cleared
    SendEvent                           = 14,   // Send event "{GameEvents}" (player-sent/instance only)

    Count
};

enum class CriteriaStartEvent : uint8
{
    None                            = 0, // - NONE -
    ReachLevel                      = 1, // Reach level {#Level}
    CompleteDailyQuest              = 2, // Complete daily quest "{QuestV2}"
    StartBattleground               = 3, // Start battleground "{Map}"
    WinRankedArenaMatchWithTeamSize = 4, // Win a ranked arena match with team size {#Team Size}
    GainAura                        = 5, // Gain aura "{Spell}"
    GainAuraEffect                  = 6, // Gain aura effect "{SpellAuraNames.EnumID}"
    CastSpell                       = 7, // Cast spell "{Spell}"
    BeSpellTarget                   = 8, // Have spell "{Spell}" cast on you
    AcceptQuest                     = 9, // Accept quest "{QuestV2}"
    KillNPC                         = 10, // Kill NPC "{Creature}"
    KillPlayer                      = 11, // Kill player
    UseItem                         = 12, // Use item "{Item}"
    SendEvent                       = 13, // Send event "{GameEvents}" (player-sent/instance only)
    BeginScenarioStep               = 14, // Begin scenario step "{#Step}" (for use with "Player on Scenario" modifier only)

    Count
};

enum class CriteriaFlags : uint8
{
    FailAchievement         = 0x01, // Fail Achievement
    ResetOnStart            = 0x02, // Reset on Start
    ServerOnly              = 0x04, // Server Only
    AlwaysSaveToDB          = 0x08, // Always Save to DB (Use with Caution)
    AllowCriteriaDecrement  = 0x10, // Allow criteria to be decremented
    IsForQuest              = 0x20  // Is For Quest
};

DEFINE_ENUM_FLAG(CriteriaFlags);

enum class CriteriaType : uint8
{
    KillCreature                                   = 0,   // Kill NPC "{Creature}"
    WinBattleground                                = 1,   // Win battleground "{Map}"
    CompleteResearchProject                        = 2,   /*NYI*/ // Complete research project "{ResearchProject}"
    CompleteAnyResearchProject                     = 3,   /*NYI*/ // Complete any research project
    FindResearchObject                             = 4,   /*NYI*/ // Find research object "{GameObjects}"
    ReachLevel                                     = 5,   // Reach level
    ExhaustAnyResearchSite                         = 6,   /*NYI*/ // Exhaust any research site
    SkillRaised                                    = 7,   // Skill "{SkillLine}" raised
    EarnAchievement                                = 8,   // Earn achievement "{Achievement}"
    CompleteQuestsCount                            = 9,   // Count of complete quests (quest count)
    CompleteAnyDailyQuestPerDay                    = 10,  // Complete any daily quest (per day)
    CompleteQuestsInZone                           = 11,  // Complete quests in "{AreaTable}"
    CurrencyGained                                 = 12,  // Currency "{CurrencyTypes}" gained
    DamageDealt                                    = 13,  // Damage dealt
    CompleteDailyQuest                             = 14,  // Complete daily quest
    ParticipateInBattleground                      = 15,  // Participate in battleground "{Map}"
    DieOnMap                                       = 16,  // Die on map "{Map}"
    DieAnywhere                                    = 17,  // Die anywhere
    DieInInstance                                  = 18,  // Die in an instance which handles at most {#Max Players} players
    RunInstance                                    = 19,  /*NYI*/ // Run an instance which handles at most {#Max Players} players
    KilledByCreature                               = 20,  // Get killed by "{Creature}"
    CompleteInternalCriteria                       = 21,  /*NYI*/ // Designer Value{`Uses Record ID}
    CompleteAnyChallengeMode                       = 22,  /*NYI*/ // Complete any challenge mode
    KilledByPlayer                                 = 23,  // Die to a player
    MaxDistFallenWithoutDying                      = 24,  // Maximum distance fallen without dying
    EarnChallengeModeMedal                         = 25,  /*NYI*/ // Earn a challenge mode medal of "{#Challenge Mode Medal (OBSOLETE)}" (OBSOLETE)
    DieFromEnviromentalDamage                      = 26,  // Die to "{$Env Damage}" environmental damage
    CompleteQuest                                  = 27,  // Complete quest "{QuestV2}"
    BeSpellTarget                                  = 28,  // Have the spell "{Spell}" cast on you
    CastSpell                                      = 29,  // Cast the spell "{Spell}"
    TrackedWorldStateUIModified                    = 30,  // Tracked WorldStateUI value "{WorldStateUI}" is modified
    PVPKillInArea                                  = 31,  // Kill someone in PVP in "{AreaTable}"
    WinArena                                       = 32,  // Win arena "{Map}"
    ParticipateInArena                             = 33,  /*NYI*/ // Participate in arena "{Map}"
    LearnOrKnowSpell                               = 34,  // Learn or Know spell "{Spell}"
    EarnHonorableKill                              = 35,  // Earn an honorable kill
    AcquireItem                                    = 36,  // Acquire item "{Item}"
    WinAnyRankedArena                              = 37,  // Win a ranked arena match (any arena)
    EarnTeamArenaRating                            = 38,  /*NYI*/ // Earn a team arena rating of {#Arena Rating}
    EarnPersonalArenaRating                        = 39,  // Earn a personal arena rating of {#Arena Rating}
    AchieveSkillStep                               = 40,  // Achieve a skill step in "{SkillLine}"
    UseItem                                        = 41,  // Use item "{Item}"
    LootItem                                       = 42,  // Loot "{Item}" via corpse, pickpocket, fishing, disenchanting, etc.
    RevealWorldMapOverlay                          = 43,  // Reveal world map overlay "{WorldMapOverlay}"
    EarnTitle                                      = 44,  /*NYI*/ // Deprecated PVP Titles
    BankSlotsPurchased                             = 45,  // Bank slots purchased
    ReputationGained                               = 46,  // Reputation gained with faction "{Faction}"
    TotalExaltedFactions                           = 47,  // Total exalted factions
    GotHaircut                                     = 48,  // Got a haircut
    EquipItemInSlot                                = 49,  // Equip item in slot "{$Equip Slot}"
    RollNeed                                       = 50,  // Roll need and get {#Need Roll}
    RollGreed                                      = 51,  // Roll greed and get {#Greed Roll}
    DeliverKillingBlowToClass                      = 52,  // Deliver a killing blow to a {ChrClasses}
    DeliverKillingBlowToRace                       = 53,  // Deliver a killing blow to a {ChrRaces}
    DoEmote                                        = 54,  // Do a "{EmotesText}" emote
    HealingDone                                    = 55,  // Healing done
    DeliveredKillingBlow                           = 56,  // Delivered a killing blow
    EquipItem                                      = 57,  // Equip item "{Item}"
    CompleteQuestsInSort                           = 58,  /*NYI*/ // Complete quests in "{QuestSort}"
    MoneyEarnedFromSales                           = 59,  // Sell items to vendors
    MoneySpentOnRespecs                            = 60,  // Money spent on respecs
    TotalRespecs                                   = 61,  // Total respecs
    MoneyEarnedFromQuesting                        = 62,  // Money earned from questing
    MoneySpentOnTaxis                              = 63,  // Money spent on taxis
    KilledAllUnitsInSpawnRegion                    = 64,  /*NYI*/ // Killed all units in spawn region "{SpawnRegion}"
    MoneySpentAtBarberShop                         = 65,  // Money spent at the barber shop
    MoneySpentOnPostage                            = 66,  // Money spent on postage
    MoneyLootedFromCreatures                       = 67,  // Money looted from creatures
    UseGameobject                                  = 68,  // Use Game Object "{GameObjects}"
    GainAura                                       = 69,  // Gain aura "{Spell}"
    KillPlayer                                     = 70,  // Kill a player (no honor check)
    CompleteChallengeMode                          = 71,  /*NYI*/ // Complete a challenge mode on map "{Map}"
    CatchFishInFishingHole                         = 72,  // Catch fish in the "{GameObjects}" fishing hole
    PlayerTriggerGameEvent                         = 73,  /*NYI*/ // Player will Trigger game event "{GameEvents}"
    Login                                          = 74,  // Login (USE SPARINGLY!)
    LearnSpellFromSkillLine                        = 75,  // Learn spell from the "{SkillLine}" skill line
    WinDuel                                        = 76,  // Win a duel
    LoseDuel                                       = 77,  // Lose a duel
    KillAnyCreature                                = 78,  // Kill any NPC
    CreatedItemsByCastingSpellWithLimit            = 79,  /*NYI*/ // Created items by casting a spell (limit 1 per create...)
    MoneyEarnedFromAuctions                        = 80,  // Money earned from auctions
    BattlePetAchievementPointsEarned               = 81,  /*NYI*/ // Battle pet achievement points earned
    ItemsPostedAtAuction                           = 82,  // Number of items posted at auction
    HighestAuctionBid                              = 83,  // Highest auction bid
    AuctionsWon                                    = 84,  // Auctions won
    HighestAuctionSale                             = 85,  // Highest coin value of item sold
    MostMoneyOwned                                 = 86,  // Most money owned
    TotalReveredFactions                           = 87,  // Total revered factions
    TotalHonoredFactions                           = 88,  // Total honored factions
    TotalFactionsEncountered                       = 89,  // Total factions encountered
    LootAnyItem                                    = 90,  // Loot any item
    ObtainAnyItem                                  = 91,  // Obtain any item
    AnyoneTriggerGameEventScenario                 = 92,  /*NYI*/ // Anyone will Trigger game event "{GameEvents}" (Scenario Only)
    RollAnyNeed                                    = 93,  // Roll any number on need
    RollAnyGreed                                   = 94,  // Roll any number on greed
    ReleasedSpirit                                 = 95,  /*NYI*/ // Released Spirit
    AccountKnownPet                                = 96,  /*NYI*/ // Account knows pet "{Creature}" (Backtracked)
    DefeatDungeonEncounterWhileElegibleForLoot     = 97,  /*NYI*/ // Defeat Encounter "{DungeonEncounter}" While Eligible For Loot
    // UNUSED 18{}                                 = 98,  // Unused
    // UNUSED 19{}                                 = 99,  // Unused
    // UNUSED 20{}                                 = 100, // Unused
    HighestDamageDone                              = 101, // Highest damage done in 1 single ability
    HighestDamageTaken                             = 102, // Most damage taken in 1 single hit
    TotalDamageTaken                               = 103, // Total damage taken
    HighestHealCast                                = 104, // Largest heal cast
    TotalHealReceived                              = 105, // Total healing received
    HighestHealReceived                            = 106, // Largest heal received
    AbandonAnyQuest                                = 107, // Abandon any quest
    BuyTaxi                                        = 108, // Buy a taxi
    GetLootByType                                  = 109, // Get loot via "{$Loot Acquisition}"
    LandTargetedSpellOnTarget                      = 110, // Land targeted spell "{Spell}" on a target
    // UNUSED 21{}                                 = 111, // Unused
    LearnTradeskillSkillLine                       = 112, // Learn tradeskill skill line "{SkillLine}"
    HonorableKills                                 = 113, // Honorable kills (number in interface, won't update except for login)
    AcceptSummon                                   = 114, // Accept a summon
    EarnAchievementPoints                          = 115, // Earn achievement points
    RollDisenchant                                 = 116, /*NYI*/ // Roll disenchant and get {#Disenchant Roll}
    RollAnyDisenchant                              = 117, /*NYI*/ // Roll any number on disenchant
    CompletedLFGDungeon                            = 118, /*NYI*/ // Completed an LFG dungeon
    CompletedLFGDungeonWithStrangers               = 119, // Completed an LFG dungeon with strangers
    KickInitiatorInLFGDungeon                      = 120, /*NYI*/ // Kicked in an LFG dungeon (initiator)
    KickVoterInLFGDungeon                          = 121, /*NYI*/ // Kicked in an LFG dungeon (voter)
    KickTargetInLFGDungeon                         = 122, /*NYI*/ // Kicked in an LFG dungeon (target)
    AbandonedLFGDungeon                            = 123, /*NYI*/ // Abandoned an LFG dungeon
    MoneySpentOnGuildRepair                        = 124, /*NYI*/ // Guild repair amount spent
    GuildAttainedLevel                             = 125, /*NYI*/ // Guild attained level
    CreatedItemsByCastingSpell                     = 126, /*NYI*/ // Created items by casting a spell
    FishInAnyPool                                  = 127, /*NYI*/ // Fish in any pool
    GuildBankTabsPurchased                         = 128, /*NYI*/ // Guild bank tabs purchased
    EarnGuildAchievementPoints                     = 129, /*NYI*/ // Earn guild achievement points
    WinAnyBattleground                             = 130, /*NYI*/ // Win any battleground
    ParticipateInAnyBattleground                   = 131, /*NYI*/ // Participate in any battleground
    EarnBattlegroundRating                         = 132, /*NYI*/ // Earn a battleground rating
    GuildTabardCreated                             = 133, /*NYI*/ // Guild tabard created
    CompleteQuestsCountForGuild                    = 134, /*NYI*/ // Count of complete quests for guild (Quest count)
    HonorableKillsForGuild                         = 135, /*NYI*/ // Honorable kills for Guild
    KillAnyCreatureForGuild                        = 136, /*NYI*/ // Kill any NPC for Guild
    GroupedTankLeftEarlyInLFGDungeon               = 137, /*NYI*/ // Grouped tank left early in an LFG dungeon
    CompleteGuildChallenge                         = 138, /*NYI*/ // Complete a "{$Guild Challenge}" guild challenge
    CompleteAnyGuildChallenge                      = 139, /*NYI*/ // Complete any guild challenge
    MarkedAFKInBattleground                        = 140, /*NYI*/ // Marked AFK in a battleground
    RemovedAFKInBattleground                       = 141, /*NYI*/ // Removed for being AFK in a battleground
    StartAnyBattleground                           = 142, /*NYI*/ // Start any battleground (AFK tracking)
    CompleteAnyBattleground                        = 143, /*NYI*/ // Complete any battleground (AFK tracking)
    MarkedSomeoneAFKInBattleground                 = 144, /*NYI*/ // Marked someone for being AFK in a battleground
    CompletedLFRDungeon                            = 145, /*NYI*/ // Completed an LFR dungeon
    AbandonedLFRDungeon                            = 146, /*NYI*/ // Abandoned an LFR dungeon
    KickInitiatorInLFRDungeon                      = 147, /*NYI*/ // Kicked in an LFR dungeon (initiator)
    KickVoterInLFRDungeon                          = 148, /*NYI*/ // Kicked in an LFR dungeon (voter)
    KickTargetInLFRDungeon                         = 149, /*NYI*/ // Kicked in an LFR dungeon (target)
    GroupedTankLeftEarlyInLFRDungeon               = 150, /*NYI*/ // Grouped tank left early in an LFR dungeon
    CompleteAnyScenario                            = 151, /*NYI*/ // Complete a Scenario
    CompleteScenario                               = 152, /*NYI*/ // Complete scenario "{Scenario}"
    EnterAreaTriggerWithActionSet                  = 153, /*NYI*/ // Enter area trigger "{AreaTriggerActionSet}"
    LeaveAreaTriggerWithActionSet                  = 154, /*NYI*/ // Leave area trigger "{AreaTriggerActionSet}"
    LearnedNewPet                                  = 155, // (Account Only) Learned a new pet
    UniquePetsOwned                                = 156, // (Account Only) Unique pets owned
    AccountObtainPetThroughBattle                  = 157, /*NYI*/ // (Account Only) Obtain a pet through battle
    WinPetBattle                                   = 158, /*NYI*/ // Win a pet battle
    LosePetBattle                                  = 159, /*NYI*/ // Lose a pet battle
    BattlePetReachLevel                            = 160, // (Account Only) Battle pet has reached level {#Level}
    PlayerObtainPetThroughBattle                   = 161, /*NYI*/ // (Player) Obtain a pet through battle
    ActivelyEarnPetLevel                           = 162, // (Player) Actively earn level {#Level} with a pet by a player
    EnterArea                                      = 163, /*NYI*/ // Enter Map Area "{AreaTable}"
    LeaveArea                                      = 164, /*NYI*/ // Leave Map Area "{AreaTable}"
    DefeatDungeonEncounter                         = 165, /*NYI*/ // Defeat Encounter "{DungeonEncounter}"
    PlaceAnyGarrisonBuilding                       = 166, /*NYI*/ // Garrison Building: Place any
    PlaceGarrisonBuilding                          = 167, // Garrison Building: Place "{GarrBuilding}"
    ActivateAnyGarrisonBuilding                    = 168, // Garrison Building: Activate any
    ActivateGarrisonBuilding                       = 169, /*NYI*/ // Garrison Building: Activate "{GarrBuilding}"
    UpgradeGarrison                                = 170, /*NYI*/ // Garrison: Upgrade Garrison to Tier "{#Tier:2,3}"
    StartAnyGarrisonMissionWithFollowerType        = 171, /*NYI*/ // Garrison Mission: Start any with FollowerType "{GarrFollowerType}"
    StartGarrisonMission                           = 172, /*NYI*/ // Garrison Mission: Start "{GarrMission}"
    SucceedAnyGarrisonMissionWithFollowerType      = 173, /*NYI*/ // Garrison Mission: Succeed any with FollowerType "{GarrFollowerType}"
    SucceedGarrisonMission                         = 174, /*NYI*/ // Garrison Mission: Succeed "{GarrMission}"
    RecruitAnyGarrisonFollower                     = 175, /*NYI*/ // Garrison Follower: Recruit any
    RecruitGarrisonFollower                        = 176, // Garrison Follower: Recruit "{GarrFollower}"
    AcquireGarrison                                = 177, /*NYI*/ // Garrison: Acquire a Garrison
    LearnAnyGarrisonBlueprint                      = 178, /*NYI*/ // Garrison Blueprint: Learn any
    LearnGarrisonBlueprint                         = 179, /*NYI*/ // Garrison Blueprint: Learn "{GarrBuilding}"
    LearnAnyGarrisonSpecialization                 = 180, /*NYI*/ // Garrison Specialization: Learn any
    LearnGarrisonSpecialization                    = 181, /*NYI*/ // Garrison Specialization: Learn "{GarrSpecialization}"
    CollectGarrisonShipment                        = 182, /*NYI*/ // Garrison Shipment of type "{CharShipmentContainer}" collected
    ItemLevelChangedForGarrisonFollower            = 183, /*NYI*/ // Garrison Follower: Item Level Changed
    LevelChangedForGarrisonFollower                = 184, /*NYI*/ // Garrison Follower: Level Changed
    LearnToy                                       = 185, /*NYI*/ // Learn Toy "{Item}"
    LearnAnyToy                                    = 186, /*NYI*/ // Learn Any Toy
    QualityUpgradedForGarrisonFollower             = 187, /*NYI*/ // Garrison Follower: Quality Upgraded
    LearnHeirloom                                  = 188, /*NYI*/ // Learn Heirloom "{Item}"
    LearnAnyHeirloom                               = 189, /*NYI*/ // Learn Any Heirloom
    EarnArtifactXP                                 = 190, /*NYI*/ // Earn Artifact XP
    AnyArtifactPowerRankPurchased                  = 191, /*NYI*/ // Artifact Power Ranks Purchased
    LearnTransmog                                  = 192, /*NYI*/ // Learn Transmog "{ItemModifiedAppearance}"
    LearnAnyTransmog                               = 193, /*NYI*/ // Learn Any Transmog
    HonorLevelIncrease                             = 194, // (Player) honor level increase
    PrestigeLevelIncrease                          = 195, /*NYI*/ // (Player) prestige level increase
    ActivelyReachLevel                             = 196, // Actively level to level {#Level}
    CompleteResearchAnyGarrisonTalent              = 197, /*NYI*/ // Garrison Talent: Complete Research Any
    CompleteResearchGarrisonTalent                 = 198, /*NYI*/ // Garrison Talent: Complete Research "{GarrTalent}"
    LearnAnyTransmogInSlot                         = 199, // Learn Any Transmog in Slot "{$Equip Slot}"
    RecruitAnyGarrisonTroop                        = 200, /*NYI*/ // Recruit any Garrison Troop
    StartResearchAnyGarrisonTalent                 = 201, /*NYI*/ // Garrison Talent: Start Research Any
    StartResearchGarrisonTalent                    = 202, /*NYI*/ // Garrison Talent: Start Research "{GarrTalent}"
    CompleteAnyWorldQuest                          = 203, /*NYI*/ // Complete Any Quest
    EarnLicense                                    = 204, /*NYI*/ // Earn License "{BattlePayDeliverable}" (does NOT work for box level)
    CollectTransmogSetFromGroup                    = 205, // (Account Only) Collect a Transmog Set from Group "{TransmogSetGroup}"
    ParagonLevelIncreaseWithFaction                = 206, /*NYI*/ // (Player) paragon level increase with faction "{Faction}"
    PlayerHasEarnedHonor                           = 207, /*NYI*/ // Player has earned honor
    KillCreatureScenario                           = 208, /*NYI*/ // Kill NPC "{Creature}" (scenario criteria only, do not use for player)
    ArtifactPowerRankPurchased                     = 209, /*NYI*/ // Artifact Power Rank of "{ArtifactPower}" Purchased
    ChooseAnyRelicTalent                           = 210, /*NYI*/ // Choose any Relic Talent
    ChooseRelicTalent                              = 211, /*NYI*/ // Choose Relic Talent "{ArtifactPower}"
    EarnExpansionLevel                             = 212, /*NYI*/ // Earn Expansion Level "{$Expansion Level}"
    AccountHonorLevelReached                       = 213, /*NYI*/ // (Account Only) honor level {#Level} reached
    EarnArtifactXPForAzeriteItem                   = 214, // Earn Artifact experience for Azerite Item
    AzeriteLevelReached                            = 215, // Azerite Level {#Azerite Level} reached
    MythicPlusCompleted                            = 216, /*NYI*/ // Mythic Plus Completed
    ScenarioGroupCompleted                         = 217, /*NYI*/ // Scenario Group Completed
    CompleteAnyReplayQuest                         = 218, // Complete Any Replay Quest
    BuyItemsFromVendors                            = 219, // Buy items from vendors
    SellItemsToVendors                             = 220, // Sell items to vendors
    ReachMaxLevel                                  = 221, /*NYI*/ // Reach Max Level
    MemorizeSpell                                  = 222, /*NYI*/ // Memorize Spell "{Spell}"
    LearnTransmogIllusion                          = 223, /*NYI*/ // Learn Transmog Illusion
    LearnAnyTransmogIllusion                       = 224, /*NYI*/ // Learn Any Transmog Illusion
    EnterTopLevelArea                              = 225, // Enter Top Level Map Area "{AreaTable}"
    LeaveTopLevelArea                              = 226, /*NYI*/ // Leave Top Level Map Area "{AreaTable}"
    SocketGarrisonTalent                           = 227, /*NYI*/ // Socket Garrison Talent {GarrTalent}
    SocketAnySoulbindConduit                       = 228, /*NYI*/ // Socket Any Soulbind Conduit
    ObtainAnyItemWithCurrencyValue                 = 229, /*NYI*/ // Obtain Any Item With Currency Value "{CurrencyTypes}"
    MythicPlusRatingAttained                       = 230, /*NYI*/ // (Player) Mythic+ Rating "{#DungeonScore}" attained
    SpentTalentPoint                               = 231, /*NYI*/ // (Player) spent talent point

    MythicPlusDisplaySeasonEnded                   = 234, /*NYI*/ // {DisplaySeason}
    Count
};

enum class CriteriaTreeFlags : uint16
{
    ProgressBar                 = 0x0001, // Progress Bar
    DoNotDisplay                = 0x0002, // Do Not Display
    IsDate                      = 0x0004, // Is a Date
    IsMoney                     = 0x0008, // Is Money
    ToastOnComplete             = 0x0010, // Toast on Complete
    UseObjectsDescription       = 0x0020, // Use Object's Description
    ShowFactionSpecificChild    = 0x0040, // Show faction specific child
    DisplayAllChildren          = 0x0080, // Display all children
    AwardBonusRep               = 0x0100, // Award Bonus Rep (Hack!!)
    AllianceOnly                = 0x0200, // Treat this criteria or block as Alliance
    HordeOnly                   = 0x0400, // Treat this criteria or block as Horde
    DisplayAsFraction           = 0x0800, // Display as Fraction
    IsForQuest                  = 0x1000  // Is For Quest
};

DEFINE_ENUM_FLAG(CriteriaTreeFlags);

enum class CriteriaTreeOperator : uint8
{
    Complete        = 0, // Complete
    NotComplete     = 1, // Not Complete
    CompleteAll     = 4, // Complete All
    Sum             = 5, // Sum Of Criteria Is
    Highest         = 6, // Highest Criteria Is
    StartedAtLeast  = 7, // Started At Least
    CompleteAtLeast = 8, // Complete At Least
    ProgressBar     = 9  // Progress Bar
};

enum class ChrCustomizationOptionFlag : int32
{
    Disabled    = 0x4,
};

DEFINE_ENUM_FLAG(ChrCustomizationOptionFlag);

enum class ChrCustomizationReqFlag : int32
{
    HasRequirements = 0x1
};

DEFINE_ENUM_FLAG(ChrCustomizationReqFlag);

enum Curves
{
    CURVE_ID_ARTIFACT_RELIC_ITEM_LEVEL_BONUS    = 1718,
    CURVE_ID_AZERITE_EMPOWERED_ITEM_RESPEC_COST = 6785
};

enum Difficulty : uint8
{
    DIFFICULTY_NONE                 = 0,
    DIFFICULTY_NORMAL               = 1,
    DIFFICULTY_HEROIC               = 2,
    DIFFICULTY_10_N                 = 3,
    DIFFICULTY_25_N                 = 4,
    DIFFICULTY_10_HC                = 5,
    DIFFICULTY_25_HC                = 6,
    DIFFICULTY_LFR                  = 7,
    DIFFICULTY_MYTHIC_KEYSTONE      = 8,
    DIFFICULTY_40                   = 9,
    DIFFICULTY_3_MAN_SCENARIO_HC    = 11,
    DIFFICULTY_3_MAN_SCENARIO_N     = 12,
    DIFFICULTY_NORMAL_RAID          = 14,
    DIFFICULTY_HEROIC_RAID          = 15,
    DIFFICULTY_MYTHIC_RAID          = 16,
    DIFFICULTY_LFR_NEW              = 17,
    DIFFICULTY_EVENT_RAID           = 18,
    DIFFICULTY_EVENT_DUNGEON        = 19,
    DIFFICULTY_EVENT_SCENARIO       = 20,
    DIFFICULTY_MYTHIC               = 23,
    DIFFICULTY_TIMEWALKING          = 24,
    DIFFICULTY_WORLD_PVP_SCENARIO   = 25,
    DIFFICULTY_5_MAN_SCENARIO_N     = 26,
    DIFFICULTY_20_MAN_SCENARIO_N    = 27,
    DIFFICULTY_PVEVP_SCENARIO       = 29,
    DIFFICULTY_EVENT_SCENARIO_6     = 30,
    DIFFICULTY_WORLD_PVP_SCENARIO_2 = 32,
    DIFFICULTY_TIMEWALKING_RAID     = 33,
    DIFFICULTY_PVP                  = 34,
    DIFFICULTY_NORMAL_ISLAND        = 38,
    DIFFICULTY_HEROIC_ISLAND        = 39,
    DIFFICULTY_MYTHIC_ISLAND        = 40,
    DIFFICULTY_PVP_ISLAND           = 45,
    DIFFICULTY_NORMAL_WARFRONT      = 147,
    DIFFICULTY_HEROIC_WARFRONT      = 149,
    DIFFICULTY_LFR_15TH_ANNIVERSARY = 151,
    DIFFICULTY_VISIONS_OF_NZOTH     = 152,
    DIFFICULTY_TEEMING_ISLAND       = 153
};

enum DifficultyFlags
{
    DIFFICULTY_FLAG_HEROIC          = 0x01,
    DIFFICULTY_FLAG_DEFAULT         = 0x02,
    DIFFICULTY_FLAG_CAN_SELECT      = 0x04, // Player can select this difficulty in dropdown menu
    DIFFICULTY_FLAG_CHALLENGE_MODE  = 0x08,

    DIFFICULTY_FLAG_LEGACY          = 0x20,
    DIFFICULTY_FLAG_DISPLAY_HEROIC  = 0x40, // Controls icon displayed on minimap when inside the instance
    DIFFICULTY_FLAG_DISPLAY_MYTHIC  = 0x80  // Controls icon displayed on minimap when inside the instance
};

enum class ExpectedStatType : uint8
{
    CreatureHealth          = 0,
    PlayerHealth            = 1,
    CreatureAutoAttackDps   = 2,
    CreatureArmor           = 3,
    PlayerMana              = 4,
    PlayerPrimaryStat       = 5,
    PlayerSecondaryStat     = 6,
    ArmorConstant           = 7,
    None                    = 8,
    CreatureSpellDamage     = 9
};

enum FactionTemplateFlags
{
    FACTION_TEMPLATE_FLAG_PVP               = 0x00000800,   // flagged for PvP
    FACTION_TEMPLATE_FLAG_CONTESTED_GUARD   = 0x00001000,   // faction will attack players that were involved in PvP combats
    FACTION_TEMPLATE_FLAG_HOSTILE_BY_DEFAULT= 0x00002000
};

enum FactionMasks
{
    FACTION_MASK_PLAYER   = 1,                              // any player
    FACTION_MASK_ALLIANCE = 2,                              // player or creature from alliance team
    FACTION_MASK_HORDE    = 4,                              // player or creature from horde team
    FACTION_MASK_MONSTER  = 8                               // aggressive creature from monster team
    // if none flags set then non-aggressive creature
};

enum class FriendshipReputationFlags : int32
{
    NoFXOnReactionChange                            = 0x01,
    NoLogTextOnRepGain                              = 0x02,
    NoLogTextOnReactionChange                       = 0x04,
    ShowRepGainandReactionChangeForHiddenFaction    = 0x08,
    NoRepGainModifiers                              = 0x10
};

DEFINE_ENUM_FLAG(FriendshipReputationFlags);

enum class GlobalCurve : int32
{
    CritDiminishing = 0,
    MasteryDiminishing = 1,
    HasteDiminishing = 2,
    SpeedDiminishing = 3,
    AvoidanceDiminishing = 4,
    VersatilityDoneDiminishing = 5,
    LifestealDiminishing = 6,
    DodgeDiminishing = 7,
    BlockDiminishing = 8,
    ParryDiminishing = 9,

    VersatilityTakenDiminishing = 11,

    ContentTuningPvpItemLevelHealthScaling = 13,
    ContentTuningPvpLevelDamageScaling = 14,
    ContentTuningPvpItemLevelDamageScaling = 15,
};

#define MAX_ITEM_PROTO_FLAGS 4
#define MAX_ITEM_PROTO_ZONES 2
#define MAX_ITEM_PROTO_SOCKETS 3
#define MAX_ITEM_PROTO_STATS  10

enum MapTypes                                               // Lua_IsInInstance
{
    MAP_COMMON          = 0,                                // none
    MAP_INSTANCE        = 1,                                // party
    MAP_RAID            = 2,                                // raid
    MAP_BATTLEGROUND    = 3,                                // pvp
    MAP_ARENA           = 4,                                // arena
    MAP_SCENARIO        = 5                                 // scenario
};

enum MapFlags
{
    MAP_FLAG_CAN_TOGGLE_DIFFICULTY  = 0x0100,
    MAP_FLAG_FLEX_LOCKING           = 0x8000, // All difficulties share completed encounters lock, not bound to a single instance id
                                              // heroic difficulty flag overrides it and uses instance id bind
    MAP_FLAG_GARRISON               = 0x4000000
};

enum AbilytyLearnType
{
    SKILL_LINE_ABILITY_LEARNED_ON_SKILL_VALUE  = 1, // Spell state will update depending on skill value
    SKILL_LINE_ABILITY_LEARNED_ON_SKILL_LEARN  = 2, // Spell will be learned/removed together with entire skill
    SKILL_LINE_ABILITY_REWARDED_FROM_QUEST     = 4  // Learned as quest reward, also re-learned if missing
};

enum class SkillLineAbilityFlags
{
    CanFallbackToLearnedOnSkillLearn            = 0x80, // The skill is rewarded from a quest if player started on exile's reach

};

DEFINE_ENUM_FLAG(SkillLineAbilityFlags);

enum GlyphSlotType
{
    GLYPH_SLOT_MAJOR = 0,
    GLYPH_SLOT_MINOR = 1,
    GLYPH_SLOT_PRIME = 2
};

enum ItemEnchantmentType
{
    ITEM_ENCHANTMENT_TYPE_NONE                              = 0,
    ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL                      = 1,
    ITEM_ENCHANTMENT_TYPE_DAMAGE                            = 2,
    ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL                       = 3,
    ITEM_ENCHANTMENT_TYPE_RESISTANCE                        = 4,
    ITEM_ENCHANTMENT_TYPE_STAT                              = 5,
    ITEM_ENCHANTMENT_TYPE_TOTEM                             = 6,
    ITEM_ENCHANTMENT_TYPE_USE_SPELL                         = 7,
    ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET                  = 8,
    ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_BY_TYPE = 9,
    ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_BY_ID   = 10,
    ITEM_ENCHANTMENT_TYPE_BONUS_LIST_ID                     = 11,
    ITEM_ENCHANTMENT_TYPE_BONUS_LIST_CURVE                  = 12,
    ITEM_ENCHANTMENT_TYPE_ARTIFACT_POWER_BONUS_RANK_PICKER  = 13
};

enum ItemExtendedCostFlags
{
    ITEM_EXT_COST_FLAG_REQUIRE_GUILD                = 0x01,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_1   = 0x02,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_2   = 0x04,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_3   = 0x08,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_4   = 0x10,
    ITEM_EXT_COST_CURRENCY_REQ_IS_SEASON_EARNED_5   = 0x20,
};

enum ItemBonusType
{
    ITEM_BONUS_ITEM_LEVEL                       = 1,
    ITEM_BONUS_STAT                             = 2,
    ITEM_BONUS_QUALITY                          = 3,
    ITEM_BONUS_NAME_SUBTITLE                    = 4,              // Text under name
    ITEM_BONUS_SUFFIX                           = 5,
    ITEM_BONUS_SOCKET                           = 6,
    ITEM_BONUS_APPEARANCE                       = 7,
    ITEM_BONUS_REQUIRED_LEVEL                   = 8,
    ITEM_BONUS_DISPLAY_TOAST_METHOD             = 9,
    ITEM_BONUS_REPAIR_COST_MULTIPLIER           = 10,
    ITEM_BONUS_SCALING_STAT_DISTRIBUTION        = 11,
    ITEM_BONUS_DISENCHANT_LOOT_ID               = 12,
    ITEM_BONUS_SCALING_STAT_DISTRIBUTION_FIXED  = 13,
    ITEM_BONUS_ITEM_LEVEL_CAN_INCREASE          = 14,             // Displays a + next to item level indicating it can warforge
    ITEM_BONUS_RANDOM_ENCHANTMENT               = 15,             // Responsible for showing "<Random additional stats>" or "+%d Rank Random Minor Trait" in the tooltip before item is obtained
    ITEM_BONUS_BONDING                          = 16,
    ITEM_BONUS_RELIC_TYPE                       = 17,
    ITEM_BONUS_OVERRIDE_REQUIRED_LEVEL          = 18,
    ITEM_BONUS_AZERITE_TIER_UNLOCK_SET          = 19,
    ITEM_BONUS_SCRAPPING_LOOT_ID                = 20,
    ITEM_BONUS_OVERRIDE_CAN_DISENCHANT          = 21,
    ITEM_BONUS_OVERRIDE_CAN_SCRAP               = 22,
    ITEM_BONUS_ITEM_EFFECT_ID                   = 23,
    ITEM_BONUS_MODIFIED_CRAFTING_STAT           = 25,
    ITEM_BONUS_REQUIRED_LEVEL_CURVE             = 27,
    ITEM_BONUS_DESCRIPTION_TEXT                 = 30,             // Item description
    ITEM_BONUS_OVERRIDE_NAME                    = 31,             // ItemNameDescription id
};

enum class ItemContext : uint8
{
    NONE                                = 0,
    Dungeon_Normal                      = 1,
    Dungeon_Heroic                      = 2,
    Raid_Normal                         = 3,
    Raid_Raid_Finder                    = 4,
    Raid_Heroic                         = 5,
    Raid_Mythic                         = 6,
    PVP_Unranked_1                      = 7,
    PVP_Ranked_1_Unrated                = 8,
    Scenario_Normal                     = 9,
    Scenario_Heroic                     = 10,
    Quest_Reward                        = 11,
    In_Game_Store                       = 12,
    Trade_Skill                         = 13,
    Vendor                              = 14,
    Black_Market                        = 15,
    MythicPlus_End_of_Run               = 16,
    Dungeon_Lvl_Up_1                    = 17,
    Dungeon_Lvl_Up_2                    = 18,
    Dungeon_Lvl_Up_3                    = 19,
    Dungeon_Lvl_Up_4                    = 20,
    Force_to_NONE                       = 21,
    Timewalking                         = 22,
    Dungeon_Mythic                      = 23,
    Pvp_Honor_Reward                    = 24,
    World_Quest_1                       = 25,
    World_Quest_2                       = 26,
    World_Quest_3                       = 27,
    World_Quest_4                       = 28,
    World_Quest_5                       = 29,
    World_Quest_6                       = 30,
    Mission_Reward_1                    = 31,
    Mission_Reward_2                    = 32,
    MythicPlus_End_of_Run_Time_Chest    = 33,
    zzChallenge_Mode_3                  = 34,
    MythicPlus_Jackpot                  = 35,
    World_Quest_7                       = 36,
    World_Quest_8                       = 37,
    PVP_Ranked_2_Combatant              = 38,
    PVP_Ranked_3_Challenger             = 39,
    PVP_Ranked_4_Rival                  = 40,
    PVP_Unranked_2                      = 41,
    World_Quest_9                       = 42,
    World_Quest_10                      = 43,
    PVP_Ranked_5_Duelist                = 44,
    PVP_Ranked_6_Elite                  = 45,
    PVP_Ranked_7                        = 46,
    PVP_Unranked_3                      = 47,
    PVP_Unranked_4                      = 48,
    PVP_Unranked_5                      = 49,
    PVP_Unranked_6                      = 50,
    PVP_Unranked_7                      = 51,
    PVP_Ranked_8                        = 52,
    World_Quest_11                      = 53,
    World_Quest_12                      = 54,
    World_Quest_13                      = 55,
    PVP_Ranked_Jackpot                  = 56,
    Tournament_Realm                    = 57,
    Relinquished                        = 58,
    Legendary_Forge                     = 59,
    Quest_Bonus_Loot                    = 60,
    Character_Boost_BFA                 = 61,
    Character_Boost_Shadowlands         = 62,
    Legendary_Crafting_1                = 63,
    Legendary_Crafting_2                = 64,
    Legendary_Crafting_3                = 65,
    Legendary_Crafting_4                = 66,
    Legendary_Crafting_5                = 67,
    Legendary_Crafting_6                = 68,
    Legendary_Crafting_7                = 69,
    Legendary_Crafting_8                = 70,
    Legendary_Crafting_9                = 71,
    Weekly_Rewards_Additional           = 72,
    Weekly_Rewards_Concession           = 73,
    World_Quest_Jackpot                 = 74,
    New_Character                       = 75,
    War_Mode                            = 76,
    PvP_Brawl_1                         = 77,
    PvP_Brawl_2                         = 78,
    Torghast                            = 79,
    Corpse_Recovery                     = 80,
    World_Boss                          = 81,
    Raid_Normal_Extended                = 82,
    Raid_Raid_Finder_Extended           = 83,
    Raid_Heroic_Extended                = 84,
    Raid_Mythic_Extended                = 85,
    Character_Template_9_1              = 86,

    Max
};

enum ItemLimitCategoryMode
{
    ITEM_LIMIT_CATEGORY_MODE_HAVE       = 0,                      // limit applied to amount items in inventory/bank
    ITEM_LIMIT_CATEGORY_MODE_EQUIP      = 1                       // limit applied to amount equipped items (including used gems)
};

enum ItemSetFlags
{
    ITEM_SET_FLAG_LEGACY_INACTIVE = 0x01,
};

enum ItemSpecStat
{
    ITEM_SPEC_STAT_INTELLECT        = 0,
    ITEM_SPEC_STAT_AGILITY          = 1,
    ITEM_SPEC_STAT_STRENGTH         = 2,
    ITEM_SPEC_STAT_SPIRIT           = 3,
    ITEM_SPEC_STAT_HIT              = 4,
    ITEM_SPEC_STAT_DODGE            = 5,
    ITEM_SPEC_STAT_PARRY            = 6,
    ITEM_SPEC_STAT_ONE_HANDED_AXE   = 7,
    ITEM_SPEC_STAT_TWO_HANDED_AXE   = 8,
    ITEM_SPEC_STAT_ONE_HANDED_SWORD = 9,
    ITEM_SPEC_STAT_TWO_HANDED_SWORD = 10,
    ITEM_SPEC_STAT_ONE_HANDED_MACE  = 11,
    ITEM_SPEC_STAT_TWO_HANDED_MACE  = 12,
    ITEM_SPEC_STAT_DAGGER           = 13,
    ITEM_SPEC_STAT_FIST_WEAPON      = 14,
    ITEM_SPEC_STAT_GUN              = 15,
    ITEM_SPEC_STAT_BOW              = 16,
    ITEM_SPEC_STAT_CROSSBOW         = 17,
    ITEM_SPEC_STAT_STAFF            = 18,
    ITEM_SPEC_STAT_POLEARM          = 19,
    ITEM_SPEC_STAT_THROWN           = 20,
    ITEM_SPEC_STAT_WAND             = 21,
    ITEM_SPEC_STAT_SHIELD           = 22,
    ITEM_SPEC_STAT_RELIC            = 23,
    ITEM_SPEC_STAT_CRIT             = 24,
    ITEM_SPEC_STAT_HASTE            = 25,
    ITEM_SPEC_STAT_BONUS_ARMOR      = 26,
    ITEM_SPEC_STAT_CLOAK            = 27,
    ITEM_SPEC_STAT_WARGLAIVES       = 28,
    ITEM_SPEC_STAT_RELIC_IRON       = 29,
    ITEM_SPEC_STAT_RELIC_BLOOD      = 30,
    ITEM_SPEC_STAT_RELIC_SHADOW     = 31,
    ITEM_SPEC_STAT_RELIC_FEL        = 32,
    ITEM_SPEC_STAT_RELIC_ARCANE     = 33,
    ITEM_SPEC_STAT_RELIC_FROST      = 34,
    ITEM_SPEC_STAT_RELIC_FIRE       = 35,
    ITEM_SPEC_STAT_RELIC_WATER      = 36,
    ITEM_SPEC_STAT_RELIC_LIFE       = 37,
    ITEM_SPEC_STAT_RELIC_WIND       = 38,
    ITEM_SPEC_STAT_RELIC_HOLY       = 39,

    ITEM_SPEC_STAT_NONE             = 40
};

enum MapDifficultyFlags : uint8
{
    MAP_DIFFICULTY_FLAG_CANNOT_EXTEND   = 0x10
};

enum class ModifierTreeType : int32
{
    None                                                                = 0,   // No modifier
    PlayerInebriationLevelEqualOrGreaterThan                            = 1,   // Player inebriation level is {#Drunkenness} or more
    PlayerMeetsCondition                                                = 2,   // Player meets condition "{PlayerCondition}"
    MinimumItemLevel                                                    = 3,   // Minimum item level is {#Item Level}
    TargetCreatureId                                                    = 4,   // Target is NPC "{Creature}"
    TargetIsPlayer                                                      = 5,   // Target is player
    TargetIsDead                                                        = 6,   // Target is dead
    TargetIsOppositeFaction                                             = 7,   // Target is opposite faction
    PlayerHasAura                                                       = 8,   // Player has aura "{Spell}"
    PlayerHasAuraEffect                                                 = 9,   // Player has aura effect "{SpellAuraNames.EnumID}"
    TargetHasAura                                                       = 10,  // Target has aura "{Spell}"
    TargetHasAuraEffect                                                 = 11,  // Target has aura effect "{SpellAuraNames.EnumID}"
    TargetHasAuraState                                                  = 12,  // Target has aura state "{$Aura State}"
    PlayerHasAuraState                                                  = 13,  // Player has aura state "{$Aura State}"
    ItemQualityIsAtLeast                                                = 14,  // Item quality is at least {$Item Quality}
    ItemQualityIsExactly                                                = 15,  // Item quality is exactly {$Item Quality}
    PlayerIsAlive                                                       = 16,  // Player is alive
    PlayerIsInArea                                                      = 17,  // Player is in area "{AreaTable}"
    TargetIsInArea                                                      = 18,  // Target is in area "{AreaTable}"
    ItemId                                                              = 19,  // Item is "{Item}"
    LegacyDungeonDifficulty                                             = 20,  // Legacy dungeon difficulty is "{$Dungeon Difficulty}"
    PlayerToTargetLevelDeltaGreaterThan                                 = 21,  // Exceeds the target's level by {#Level Delta} levels
    TargetToPlayerLevelDeltaGreaterThan                                 = 22,  // Target exceeds your level by {#Level Delta} levels
    PlayerLevelEqualTargetLevel                                         = 23,  // You and the target are equal level
    PlayerInArenaWithTeamSize                                           = 24,  // Player is in an arena with team size {#Team Size}
    PlayerRace                                                          = 25,  // Player race is "{ChrRaces}"
    PlayerClass                                                         = 26,  // Player class is "{ChrClasses}"
    TargetRace                                                          = 27,  // Target race is "{ChrRaces}"
    TargetClass                                                         = 28,  // Target class is "{ChrClasses}"
    LessThanTappers                                                     = 29,  // Less than {#Tappers} tappers
    CreatureType                                                        = 30,  // Creature is type "{CreatureType}"
    CreatureFamily                                                      = 31,  // Creature is family "{CreatureFamily}"
    PlayerMap                                                           = 32,  // Player is on map "{Map}"
    ClientVersionEqualOrLessThan                                        = 33,  // Milestone is at or before "{WowStaticSchemas}"
    BattlePetTeamLevel                                                  = 34,  // All three winning battle pets are at or above level {#Battle Pet Level}
    PlayerIsNotInParty                                                  = 35,  // Player is not in a party
    PlayerIsInParty                                                     = 36,  // Player is in a party
    HasPersonalRatingEqualOrGreaterThan                                 = 37,  // Has a Personal Rating of at least {#Personal Rating}
    HasTitle                                                            = 38,  // Has title "{CharTitles.Mask_ID}"
    PlayerLevelEqual                                                    = 39,  // Player is exactly level {#Level}
    TargetLevelEqual                                                    = 40,  // Target is exactly level {#Level}
    PlayerIsInZone                                                      = 41,  // Player is in top-level area "{AreaTable}"
    TargetIsInZone                                                      = 42,  // Target is in top-level area "{AreaTable}"
    PlayerHealthBelowPercent                                            = 43,  // Player health below {#Percent}%
    PlayerHealthAbovePercent                                            = 44,  // Player health above {#Percent}%
    PlayerHealthEqualsPercent                                           = 45,  // Player health equals {#Percent}%
    TargetHealthBelowPercent                                            = 46,  // Target health below {#Percent}%
    TargetHealthAbovePercent                                            = 47,  // Target health above {#Percent}%
    TargetHealthEqualsPercent                                           = 48,  // Target health equals {#Percent}%
    PlayerHealthBelowValue                                              = 49,  // Player health below {#Hit Points} HP
    PlayerHealthAboveValue                                              = 50,  // Player health above {#Hit Points} HP
    PlayerHealthEqualsValue                                             = 51,  // Player health equals {#Hit Points} HP
    TargetHealthBelowValue                                              = 52,  // Target health below {#Hit Points} HP
    TargetHealthAboveValue                                              = 53,  // Target health above {#Hit Points} HP
    TargetHealthEqualsValue                                             = 54,  // Target health equals {#Hit Points} HP
    TargetIsPlayerAndMeetsCondition                                     = 55,  // Target is a player with condition "{PlayerCondition}"
    PlayerHasMoreThanAchievementPoints                                  = 56,  // Player has over {#Achievement Pts} achievement points
    PlayerInLfgDungeon                                                  = 57,  // Player is in a LFG dungeon
    PlayerInRandomLfgDungeon                                            = 58,  // Player is in a random LFG dungeon
    PlayerInFirstRandomLfgDungeon                                       = 59,  // Player is in a first random LFG dungeon
    PlayerInRankedArenaMatch                                            = 60,  // Player is in a ranked arena match
    PlayerInGuildParty                                                  = 61,  /*NYI*/ // Player is in a guild party
    PlayerGuildReputationEqualOrGreaterThan                             = 62,  // Player has guild reputation of {#Guild Reputation} or more
    PlayerInRatedBattleground                                           = 63,  // Player is in rated battleground
    PlayerBattlegroundRatingEqualOrGreaterThan                          = 64,  // Player has a battleground rating of {#Battleground Rating} or more
    ResearchProjectRarity                                               = 65,  /*NYI*/ // Research project rarity is "{$Project Rarity}"
    ResearchProjectBranch                                               = 66,  /*NYI*/ // Research project is in branch "{ResearchBranch}"
    WorldStateExpression                                                = 67,  // World state expression "{WorldStateExpression}" is true
    DungeonDifficulty                                                   = 68,  // Dungeon difficulty is "{Difficulty}"
    PlayerLevelEqualOrGreaterThan                                       = 69,  // Player level is {#Level} or more
    TargetLevelEqualOrGreaterThan                                       = 70,  // Target level is {#Level} or more
    PlayerLevelEqualOrLessThan                                          = 71,  // Player level is {#Level} or less
    TargetLevelEqualOrLessThan                                          = 72,  // Target level is {#Level} or less
    ModifierTree                                                        = 73,  // Modifier tree "{ModifierTree}" is also true
    PlayerScenario                                                      = 74,  // Player is on scenario "{Scenario}"
    TillersReputationGreaterThan                                        = 75,  // Reputation with Tillers is above {#Reputation}
    BattlePetAchievementPointsEqualOrGreaterThan                        = 76,  // Battle pet achievement points are at least {#Achievement Pts}
    UniqueBattlePetsEqualOrGreaterThan                                  = 77,  // (Account) At least {#Pets Known} unique pets known
    BattlePetType                                                       = 78,  // Battlepet is of type "{$Battle Pet Types}"
    BattlePetHealthPercentLessThan                                      = 79,  /*NYI*/ // (Account) Battlepet's health is below {#Health Percent} percent
    GuildGroupMemberCountEqualOrGreaterThan                             = 80,  // Be in a group with at least {#Members} guild members
    BattlePetOpponentCreatureId                                         = 81,  /*NYI*/ // Battle pet opponent is "{Creature}"
    PlayerScenarioStep                                                  = 82,  // Player is on scenario step number {#Step Number}
    ChallengeModeMedal                                                  = 83,  // Challenge mode medal earned is "{#Challenge Mode Medal(OBSOLETE)}" (OBSOLETE)
    PlayerOnQuest                                                       = 84,  // Player is currently on the quest "{QuestV2}"
    ExaltedWithFaction                                                  = 85,  // Reach exalted with "{Faction}"
    EarnedAchievementOnAccount                                          = 86,  // Earned achievement "{Achievement}" on this account
    EarnedAchievementOnPlayer                                           = 87,  // Earned achievement "{Achievement}" on this player
    OrderOfTheCloudSerpentReputationGreaterThan                         = 88,  // Reputation with Order of the Cloud Serpent is above {#Reputation}
    BattlePetQuality                                                    = 89,  /*NYI*/ // Battle pet is of quality "{BattlePetBreedQuality}"
    BattlePetFightWasPVP                                                = 90,  /*NYI*/ // Battle pet fight was PVP
    BattlePetSpecies                                                    = 91,  // Battle pet is species type "{BattlePetSpecies}"
    ServerExpansionEqualOrGreaterThan                                   = 92,  // Server expansion level is "{$Expansion Level}" or higher
    PlayerHasBattlePetJournalLock                                       = 93,  // Player has battle pet journal lock
    FriendshipRepReactionIsMet                                          = 94,  // Friendship rep reaction "{FriendshipRepReaction}" is met
    ReputationWithFactionIsEqualOrGreaterThan                           = 95,  // Reputation with "{Faction}" is {#Reputation} or more
    ItemClassAndSubclass                                                = 96,  // Item is class "{ItemClass.ClassID}", subclass "{^ItemSubclass.SubclassID:ItemSubclass.ClassID = ?}"
    PlayerGender                                                        = 97,  // Player's gender is "{$Gender}"
    PlayerNativeGender                                                  = 98,  // Player's native gender is "{$Gender}"
    PlayerSkillEqualOrGreaterThan                                       = 99,  // Player skill "{SkillLine}" is level {#Skill Level} or higher
    PlayerLanguageSkillEqualOrGreaterThan                               = 100, // Player language "{Languages}" is level {#Language Level} or higher
    PlayerIsInNormalPhase                                               = 101, // Player is in normal phase
    PlayerIsInPhase                                                     = 102, // Player is in phase "{Phase}"
    PlayerIsInPhaseGroup                                                = 103, // Player is in phase group "{PhaseGroup}"
    PlayerKnowsSpell                                                    = 104, // Player knows spell "{Spell}"
    PlayerHasItemQuantity                                               = 105, // Player is carrying item "{Item}", quantity {#Quantity}
    PlayerExpansionLevelEqualOrGreaterThan                              = 106, // Player expansion level is "{$Expansion Level}" or higher
    PlayerHasAuraWithLabel                                              = 107, // Player has aura with label {Label}
    PlayersRealmWorldState                                              = 108, // Player's realm state "{WorldState}" equals {#Value}
    TimeBetween                                                         = 109, // Time is between "{/Begin Date}" and "{/End Date}"
    PlayerHasCompletedQuest                                             = 110, // Player has previously completed quest "{QuestV2}"
    PlayerIsReadyToTurnInQuest                                          = 111, // Player is ready to turn in quest "{QuestV2}"
    PlayerHasCompletedQuestObjective                                    = 112, // Player has completed Quest Objective "{QuestObjective}"
    PlayerHasExploredArea                                               = 113, // Player has explored area "{AreaTable}"
    PlayerHasItemQuantityIncludingBank                                  = 114, // Player or bank has item "{Item}", quantity {#Quantity}
    Weather                                                             = 115, // Weather is "{Weather}"
    PlayerFaction                                                       = 116, // Player faction is {$Player Faction}
    LfgStatusEqual                                                      = 117, // Looking-for-group status "{$LFG Status}" equals {#Value}
    LFgStatusEqualOrGreaterThan                                         = 118, // Looking-for-group status "{$LFG Status}" is {#Value} or more
    PlayerHasCurrencyEqualOrGreaterThan                                 = 119, // Player has currency "{CurrencyTypes}" in amount {#Amount} or more
    TargetThreatListSizeLessThan                                        = 120, // Player Killed creature with less than "{#Targets}" threat list targets
    PlayerHasTrackedCurrencyEqualOrGreaterThan                          = 121, // Player has currency "{CurrencyTypes}" tracked (per season) in amount {#Amount} or more
    PlayerMapInstanceType                                               = 122, // Player is on a map of type "{@INSTANCE_TYPE}"
    PlayerInTimeWalkerInstance                                          = 123, // Player was in a Time Walker instance
    PvpSeasonIsActive                                                   = 124, // PVP season is active
    PvpSeason                                                           = 125, // Current PVP season is {#Season}
    GarrisonTierEqualOrGreaterThan                                      = 126, // Garrison is tier {#Tier} or higher for garrison type "{GarrType}"
    GarrisonFollowersWithLevelEqualOrGreaterThan                        = 127, // At least {#Followers} followers of at least level {#Level} for follower type "{GarrFollowerType}"
    GarrisonFollowersWithQualityEqualOrGreaterThan                      = 128, // At least {#Followers} followers at least quality "{@GARR_FOLLOWER_QUALITY}" for follower type "{GarrFollowerType}"
    GarrisonFollowerWithAbilityAtLevelEqualOrGreaterThan                = 129, // Follower of at least level {#Level} has ability {GarrAbility} for follower type "{GarrFollowerType}"
    GarrisonFollowerWithTraitAtLevelEqualOrGreaterThan                  = 130, // Follower of at least level {#Level} has trait {GarrAbility} for follower type "{GarrFollowerType}"
    GarrisonFollowerWithAbilityAssignedToBuilding                       = 131, // Follower with ability "{GarrAbility}" is assigned to building type "{@GARRISON_BUILDING_TYPE}" for garrison type "{GarrType}"
    GarrisonFollowerWithTraitAssignedToBuilding                         = 132, // Follower with trait "{GarrAbility}" is assigned to building type "{@GARRISON_BUILDING_TYPE}" for garrison type "{GarrType}"
    GarrisonFollowerWithLevelAssignedToBuilding                         = 133, // Follower at least level {#Level} is assigned to building type "{@GARRISON_BUILDING_TYPE}" for garrison type "GarrType}"
    GarrisonBuildingWithLevelEqualOrGreaterThan                         = 134, // Building "{@GARRISON_BUILDING_TYPE}" is at least level {#Level} for garrison type "{GarrType}"
    HasBlueprintForGarrisonBuilding                                     = 135, // Has blueprint for garrison building "{GarrBuilding}" of type "{GarrType}"
    HasGarrisonBuildingSpecialization                                   = 136, // Has garrison building specialization "{GarrSpecialization}"
    AllGarrisonPlotsAreFull                                             = 137, // All garrison type "{GarrType}" plots are full
    PlayerIsInOwnGarrison                                               = 138, // Player is in their own garrison
    GarrisonShipmentOfTypeIsPending                                     = 139, /*NYI*/ // Shipment of type "{CharShipmentContainer}" is pending
    GarrisonBuildingIsUnderConstruction                                 = 140, // Garrison building "{GarrBuilding}" is under construction
    GarrisonMissionHasBeenCompleted                                     = 141, /*NYI*/ // Garrison mission "{GarrMission}" has been completed
    GarrisonBuildingLevelEqual                                          = 142, // Building {@GARRISON_BUILDING_TYPE} is exactly level {#Level} for garrison type "{GarrType}"
    GarrisonFollowerHasAbility                                          = 143, // This follower has ability "{GarrAbility}" for garrison type "{GarrType}"
    GarrisonFollowerHasTrait                                            = 144, // This follower has trait "{GarrAbility}" for garrison type "{GarrType}"
    GarrisonFollowerQualityEqual                                        = 145, // This Garrison Follower is {@GARR_FOLLOWER_QUALITY} quality
    GarrisonFollowerLevelEqual                                          = 146, // This Garrison Follower is level {#Level}
    GarrisonMissionIsRare                                               = 147, /*NYI*/ // This Garrison Mission is Rare
    GarrisonMissionIsElite                                              = 148, /*NYI*/ // This Garrison Mission is Elite
    CurrentGarrisonBuildingLevelEqual                                   = 149, // This Garrison Building is level {#Level} - building type passed as argument
    GarrisonPlotInstanceHasBuildingThatIsReadyToActivate                = 150, // Garrison plot instance "{GarrPlotInstance}" has building that is ready to activate
    BattlePetTeamWithSpeciesEqualOrGreaterThan                          = 151, // Battlepet: with at least {#Amount} "{BattlePetSpecies}"
    BattlePetTeamWithTypeEqualOrGreaterThan                             = 152, // Battlepet: with at least {#Amount} pets of type "{$Battle Pet Types}"
    PetBattleLastAbility                                                = 153, /*NYI*/ // Battlepet: last ability was "{BattlePetAbility}"
    PetBattleLastAbilityType                                            = 154, /*NYI*/ // Battlepet: last ability was of type "{$Battle Pet Types}"
    BattlePetTeamWithAliveEqualOrGreaterThan                            = 155, // Battlepet: with at least {#Alive} alive
    HasGarrisonBuildingActiveSpecialization                             = 156, // Has Garrison building active specialization "{GarrSpecialization}"
    HasGarrisonFollower                                                 = 157, // Has Garrison follower "{GarrFollower}"
    PlayerQuestObjectiveProgressEqual                                   = 158, // Player's progress on Quest Objective "{QuestObjective}" is equal to {#Value}
    PlayerQuestObjectiveProgressEqualOrGreaterThan                      = 159, // Player's progress on Quest Objective "{QuestObjective}" is at least {#Value}
    IsPTRRealm                                                          = 160, // This is a PTR Realm
    IsBetaRealm                                                         = 161, // This is a Beta Realm
    IsQARealm                                                           = 162, // This is a QA Realm
    GarrisonShipmentContainerIsFull                                     = 163, /*NYI*/ // Shipment Container "{CharShipmentContainer}" is full
    PlayerCountIsValidToStartGarrisonInvasion                           = 164, // Player count is valid to start garrison invasion
    InstancePlayerCountEqualOrLessThan                                  = 165, // Instance has at most {#Players} players
    AllGarrisonPlotsFilledWithBuildingsWithLevelEqualOrGreater          = 166, // All plots are full and at least level {#Level} for garrison type "{GarrType}"
    GarrisonMissionType                                                 = 167, /*NYI*/ // This mission is type "{GarrMissionType}"
    GarrisonFollowerItemLevelEqualOrGreaterThan                         = 168, // This follower is at least item level {#Level}
    GarrisonFollowerCountWithItemLevelEqualOrGreaterThan                = 169, // At least {#Followers} followers are at least item level {#Level} for follower type "{GarrFollowerType}"
    GarrisonTierEqual                                                   = 170, // Garrison is exactly tier {#Tier} for garrison type "{GarrType}"
    InstancePlayerCountEqual                                            = 171, // Instance has exactly {#Players} players
    CurrencyId                                                          = 172, // The currency is type "{CurrencyTypes}"
    SelectionIsPlayerCorpse                                             = 173, // Target is player corpse
    PlayerCanAcceptQuest                                                = 174, // Player is currently eligible for quest "{QuestV2}"
    GarrisonFollowerCountWithLevelEqualOrGreaterThan                    = 175, // At least {#Followers} followers exactly level {#Level} for follower type "{GarrFollowerType}"
    GarrisonFollowerIsInBuilding                                        = 176, // Garrison follower "{GarrFollower}" is in building "{GarrBuilding}"
    GarrisonMissionCountLessThan                                        = 177, /*NYI*/ // Player has less than {#Available} available and {#In-Progress} in-progress missions of garrison type "{GarrType}"
    GarrisonPlotInstanceCountEqualOrGreaterThan                         = 178, // Player has at least {#Amount} instances of plot "{GarrPlot}" available
    CurrencySource                                                      = 179, /*NYI*/ // Currency source is {$Currency Source}
    PlayerIsInNotOwnGarrison                                            = 180, // Player is in another garrison (not their own)
    HasActiveGarrisonFollower                                           = 181, // Has active Garrison follower "{GarrFollower}"
    PlayerDailyRandomValueMod_X_Equals                                  = 182, /*NYI*/ // Player daily random value mod {#Mod Value} equals {#Equals Value}
    PlayerHasMount                                                      = 183, // Player has Mount "{Mount}"
    GarrisonFollowerCountWithInactiveWithItemLevelEqualOrGreaterThan    = 184, // At least {#Followers} followers (including inactive) are at least item level {#Level} for follower type "{GarrFollowerType}"
    GarrisonFollowerIsOnAMission                                        = 185, // Garrison follower "{GarrFollower}" is on a mission
    GarrisonMissionCountInSetLessThan                                   = 186, /*NYI*/ // Player has less than {#Missions} available and in-progress missions of set "{GarrMissionSet}" in garrison type "{GarrType}"
    GarrisonFollowerType                                                = 187, // This Garrison Follower is of type "{GarrFollowerType}"
    PlayerUsedBoostLessThanHoursAgoRealTime                             = 188, /*NYI*/ // Player has boosted and boost occurred < {#Hours} hours ago (real time)
    PlayerUsedBoostLessThanHoursAgoGameTime                             = 189, /*NYI*/ // Player has boosted and boost occurred < {#Hours} hours ago (in-game time)
    PlayerIsMercenary                                                   = 190, // Player is currently Mercenary
    PlayerEffectiveRace                                                 = 191, /*NYI*/ // Player effective race is "{ChrRaces}"
    TargetEffectiveRace                                                 = 192, /*NYI*/ // Target effective race is "{ChrRaces}"
    HonorLevelEqualOrGreaterThan                                        = 193, // Honor level >= {#Level}
    PrestigeLevelEqualOrGreaterThan                                     = 194, // Prestige level >= {#Level}
    GarrisonMissionIsReadyToCollect                                     = 195, /*NYI*/ // Garrison mission "{GarrMission}" is ready to collect
    PlayerIsInstanceOwner                                               = 196, /*NYI*/ // Player is the instance owner (requires 'Lock Instance Owner' LFGDungeon flag)
    PlayerHasHeirloom                                                   = 197, // Player has heirloom "{Item}"
    TeamPoints                                                          = 198, /*NYI*/ // Team has {#Points} Points
    PlayerHasToy                                                        = 199, // Player has toy "{Item}"
    PlayerHasTransmog                                                   = 200, // Player has transmog "{ItemModifiedAppearance}"
    GarrisonTalentSelected                                              = 201, /*NYI*/ // Garrison has talent "{GarrTalent}" selected
    GarrisonTalentResearched                                            = 202, /*NYI*/ // Garrison has talent "{GarrTalent}" researched
    PlayerHasRestriction                                                = 203, // Player has restriction of type "{@CHARACTER_RESTRICTION_TYPE}"
    PlayerCreatedCharacterLessThanHoursAgoRealTime                      = 204, /*NYI*/ // Player has created their character < {#Hours} hours ago (real time)
    PlayerCreatedCharacterLessThanHoursAgoGameTime                      = 205, // Player has created their character < {#Hours} hours ago (in-game time)
    QuestHasQuestInfoId                                                 = 206, // Quest has Quest Info "{QuestInfo}"
    GarrisonTalentResearchInProgress                                    = 207, /*NYI*/ // Garrison is researching talent "{GarrTalent}"
    PlayerEquippedArtifactAppearanceSet                                 = 208, // Player has equipped Artifact Appearance Set "{ArtifactAppearanceSet}"
    PlayerHasCurrencyEqual                                              = 209, // Player has currency "{CurrencyTypes}" in amount {#Amount} exactly
    MinimumAverageItemHighWaterMarkForSpec                              = 210, /*NYI*/ // Minimum average item high water mark is {#Item High Water Mark} for "{$Item History Spec Match}")
    PlayerScenarioType                                                  = 211, // Player in scenario of type "{$Scenario Type}"
    PlayersAuthExpansionLevelEqualOrGreaterThan                         = 212, // Player's auth expansion level is "{$Expansion Level}" or higher
    PlayerLastWeek2v2Rating                                             = 213, /*NYI*/ // Player achieved at least a rating of {#Rating} in 2v2 last week player played
    PlayerLastWeek3v3Rating                                             = 214, /*NYI*/ // Player achieved at least a rating of {#Rating} in 3v3 last week player played
    PlayerLastWeekRBGRating                                             = 215, /*NYI*/ // Player achieved at least a rating of {#Rating} in RBG last week player played
    GroupMemberCountFromConnectedRealmEqualOrGreaterThan                = 216, // At least {#Num Players} members of the group are from your connected realms
    ArtifactTraitUnlockedCountEqualOrGreaterThan                        = 217, // At least {#Num Traits} traits have been unlocked in artifact "{Item}"
    ParagonReputationLevelEqualOrGreaterThan                            = 218, // Paragon level >= "{#Level}"
    GarrisonShipmentIsReady                                             = 219, /*NYI*/ // Shipment in container type "{CharShipmentContainer}" ready
    PlayerIsInPvpBrawl                                                  = 220, // Player is in PvP Brawl
    ParagonReputationLevelWithFactionEqualOrGreaterThan                 = 221, // Paragon level >= "{#Level}" with faction "{Faction}"
    PlayerHasItemWithBonusListFromTreeAndQuality                        = 222, // Player has an item with bonus list from tree "{ItemBonusTree}" and of quality "{$Item Quality}"
    PlayerHasEmptyInventorySlotCountEqualOrGreaterThan                  = 223, // Player has at least "{#Number of empty slots}" empty inventory slots
    PlayerHasItemInHistoryOfProgressiveEvent                            = 224, /*NYI*/ // Player has item "{Item}" in the item history of progressive event "{ProgressiveEvent}"
    PlayerHasArtifactPowerRankCountPurchasedEqualOrGreaterThan          = 225, // Player has at least {#Purchased Ranks} ranks of {ArtifactPower} on equipped artifact
    PlayerHasBoosted                                                    = 226, // Player has boosted
    PlayerHasRaceChanged                                                = 227, // Player has race changed
    PlayerHasBeenGrantedLevelsFromRaF                                   = 228, // Player has been granted levels from Recruit a Friend
    IsTournamentRealm                                                   = 229, // Is Tournament Realm
    PlayerCanAccessAlliedRaces                                          = 230, // Player can access allied races
    GroupMemberCountWithAchievementEqualOrLessThan                      = 231, // No More Than {#Group Members} With Achievement {Achievement} In Group (true if no group)
    PlayerMainhandWeaponType                                            = 232, // Player has main hand weapon of type "{$Weapon Type}"
    PlayerOffhandWeaponType                                             = 233, // Player has off-hand weapon of type "{$Weapon Type}"
    PlayerPvpTier                                                       = 234, // Player is in PvP tier {PvpTier}
    PlayerAzeriteLevelEqualOrGreaterThan                                = 235, // Players' Azerite Item is at or above level "{#Azerite Level}"
    PlayerIsOnQuestInQuestline                                          = 236, // Player is on quest in questline "{QuestLine}"
    PlayerIsQnQuestLinkedToScheduledWorldStateGroup                     = 237, // Player is on quest associated with current progressive unlock group "{ScheduledWorldStateGroup}"
    PlayerIsInRaidGroup                                                 = 238, // Player is in raid group
    PlayerPvpTierInBracketEqualOrGreaterThan                            = 239, // Player is at or above "{@PVP_TIER_ENUM}" for "{@PVP_BRACKET}"
    PlayerCanAcceptQuestInQuestline                                     = 240, // Player is eligible for quest in questline "{Questline}"
    PlayerHasCompletedQuestline                                         = 241, // Player has completed questline "{Questline}"
    PlayerHasCompletedQuestlineQuestCount                               = 242, // Player has completed "{#Quests}" quests in questline "{Questline}"
    PlayerHasCompletedPercentageOfQuestline                             = 243, // Player has completed "{#Percentage}" % of quests in questline "{Questline}"
    PlayerHasWarModeEnabled                                             = 244, // Player has WarMode Enabled (regardless of shard state)
    PlayerIsOnWarModeShard                                              = 245, // Player is on a WarMode Shard
    PlayerIsAllowedToToggleWarModeInArea                                = 246, // Player is allowed to toggle WarMode in area
    MythicPlusKeystoneLevelEqualOrGreaterThan                           = 247, /*NYI*/ // Mythic Plus Keystone Level Atleast {#Level}
    MythicPlusCompletedInTime                                           = 248, /*NYI*/ // Mythic Plus Completed In Time
    MythicPlusMapChallengeMode                                          = 249, /*NYI*/ // Mythic Plus Map Challenge Mode {MapChallengeMode}
    MythicPlusDisplaySeason                                             = 250, /*NYI*/ // Mythic Plus Display Season {#Season}
    MythicPlusMilestoneSeason                                           = 251, /*NYI*/ // Mythic Plus Milestone Season {#Season}
    PlayerVisibleRace                                                   = 252, // Player visible race is "{ChrRaces}"
    TargetVisibleRace                                                   = 253, // Target visible race is "{ChrRaces}"
    FriendshipRepReactionEqual                                          = 254, // Friendship rep reaction is exactly "{FriendshipRepReaction}"
    PlayerAuraStackCountEqual                                           = 255, // Player has exactly {#Stacks} stacks of aura "{Spell}"
    TargetAuraStackCountEqual                                           = 256, // Target has exactly {#Stacks} stacks of aura "{Spell}"
    PlayerAuraStackCountEqualOrGreaterThan                              = 257, // Player has at least {#Stacks} stacks of aura "{Spell}"
    TargetAuraStackCountEqualOrGreaterThan                              = 258, // Target has at least {#Stacks} stacks of aura "{Spell}"
    PlayerHasAzeriteEssenceRankLessThan                                 = 259, // Player has Azerite Essence {AzeriteEssence} at less than rank {#rank}
    PlayerHasAzeriteEssenceRankEqual                                    = 260, // Player has Azerite Essence {AzeriteEssence} at rank {#rank}
    PlayerHasAzeriteEssenceRankGreaterThan                              = 261, // Player has Azerite Essence {AzeriteEssence} at greater than rank {#rank}
    PlayerHasAuraWithEffectIndex                                        = 262, // Player has Aura {Spell} with Effect Index {#index} active
    PlayerLootSpecializationMatchesRole                                 = 263, // Player loot specialization matches role {@LFG_ROLE}
    PlayerIsAtMaxExpansionLevel                                         = 264, // Player is at max expansion level
    TransmogSource                                                      = 265, // Transmog Source is "{@TRANSMOG_SOURCE}"
    PlayerHasAzeriteEssenceInSlotAtRankLessThan                         = 266, // Player has Azerite Essence in slot {@AZERITE_ESSENCE_SLOT} at less than rank {#rank}
    PlayerHasAzeriteEssenceInSlotAtRankGreaterThan                      = 267, // Player has Azerite Essence in slot {@AZERITE_ESSENCE_SLOT} at greater than rank {#rank}
    PlayerLevelWithinContentTuning                                      = 268, // Player has level within Content Tuning {ContentTuning}
    TargetLevelWithinContentTuning                                      = 269, // Target has level within Content Tuning {ContentTuning}
    PlayerIsScenarioInitiator                                           = 270, /*NYI*/ // Player is Scenario Initiator
    PlayerHasCompletedQuestOrIsOnQuest                                  = 271, // Player is currently on or previously completed quest "{QuestV2}"
    PlayerLevelWithinOrAboveContentTuning                               = 272, // Player has level within or above Content Tuning {ContentTuning}
    TargetLevelWithinOrAboveContentTuning                               = 273, // Target has level within or above Content Tuning {ContentTuning}
    PlayerLevelWithinOrAboveLevelRange                                  = 274, /*NYI*/ // Player has level within or above Level Range {LevelRange}
    TargetLevelWithinOrAboveLevelRange                                  = 275, /*NYI*/ // Target has level within or above Level Range {LevelRange}
    MaxJailersTowerLevelEqualOrGreaterThan                              = 276, // Max Jailers Tower Level Atleast {#Level}
    GroupedWithRaFRecruit                                               = 277, // Grouped With Recruit
    GroupedWithRaFRecruiter                                             = 278, // Grouped with Recruiter
    PlayerSpecialization                                                = 279, // Specialization is "{ChrSpecialization}"
    PlayerMapOrCosmeticChildMap                                         = 280, // Player is on map or cosmetic child map "{Map}"
    PlayerCanAccessShadowlandsPrepurchaseContent                        = 281, // Player can access Shadowlands (9.0) prepurchase content
    PlayerHasEntitlement                                                = 282, /*NYI*/ // Player has entitlement "{BattlePayDeliverable}"
    PlayerIsInPartySyncGroup                                            = 283, /*NYI*/ // Player is in party sync group
    QuestHasPartySyncRewards                                            = 284, /*NYI*/ // Quest is eligible for party sync rewards
    HonorGainSource                                                     = 285, /*NYI*/ // Player gained honor from source {@SPECIAL_MISC_HONOR_GAIN_SOURCE}
    JailersTowerActiveFloorIndexEqualOrGreaterThan                      = 286, /*NYI*/ // Active Floor Index Atleast {#Level}
    JailersTowerActiveFloorDifficultyEqualOrGreaterThan                 = 287, /*NYI*/ // Active Floor Difficulty Atleast {#Level}
    PlayerCovenant                                                      = 288, // Player is member of covenant "{Covenant}"
    HasTimeEventPassed                                                  = 289, // Has time event "{TimeEvent}" passed
    GarrisonHasPermanentTalent                                          = 290, /*NYI*/ // Garrison has permanent talent "{GarrTalent}"
    HasActiveSoulbind                                                   = 291, // Has Active Soulbind "{Soulbind}"
    HasMemorizedSpell                                                   = 292, /*NYI*/ // Has memorized spell "{Spell}"
    PlayerHasAPACSubscriptionReward_2020                                = 293, // Player has APAC Subscription Reward 2020
    PlayerHasTBCCDEWarpStalker_Mount                                    = 294, // Player has TBCC:DE Warp Stalker Mount
    PlayerHasTBCCDEDarkPortal_Toy                                       = 295, // Player has TBCC:DE Dark Portal Toy
    PlayerHasTBCCDEPathOfIllidan_Toy                                    = 296, // Player has TBCC:DE Path of Illidan Toy
    PlayerHasImpInABallToySubscriptionReward                            = 297, // Player has Imp in a Ball Toy Subscription Reward
    PlayerIsInAreaGroup                                                 = 298, // Player is in area group "{AreaGroup}"
    TargetIsInAreaGroup                                                 = 299, // Target is in area group "{AreaGroup}"
    PlayerIsInChromieTime                                               = 300, // Player has selected Chromie Time ID "{UiChromieTimeExpansionInfo}"
    PlayerIsInAnyChromieTime                                            = 301, // Player has selected ANY Chromie Time ID
    ItemIsAzeriteArmor                                                  = 302, // Item is Azerite Armor
    PlayerHasRuneforgePower                                             = 303, // Player Has Runeforge Power "{RuneforgeLegendaryAbility}"
    PlayerInChromieTimeForScaling                                       = 304, // Player is Chromie Time for Scaling
    IsRaFRecruit                                                        = 305, // Is RAF recruit
    AllPlayersInGroupHaveAchievement                                    = 306, // All Players In Group Have Achievement "{Achievement}"
    PlayerHasSoulbindConduitRankEqualOrGreaterThan                      = 307, /*NYI*/ // Player has Conduit "{SoulbindConduit}" at Rank {#Rank} or Higher
    PlayerSpellShapeshiftFormCreatureDisplayInfoSelection               = 308, // Player has chosen {CreatureDisplayInfo} for shapeshift form {SpellShapeshiftForm}
    PlayerSoulbindConduitCountAtRankEqualOrGreaterThan                  = 309, /*NYI*/ // Player has at least {#Level} Conduits at Rank {#Rank} or higher.
    PlayerIsRestrictedAccount                                           = 310, // Player is a Restricted Account
    PlayerIsFlying                                                      = 311, // Player is flying
    PlayerScenarioIsLastStep                                            = 312, // Player is on the last step of a Scenario
    PlayerHasWeeklyRewardsAvailable                                     = 313, // Player has weekly rewards available
    TargetCovenant                                                      = 314, // Target is member of covenant "{Covenant}"
    PlayerHasTBCCollectorsEdition                                       = 315, // Player has TBC Collector's Edition
    PlayerHasWrathCollectorsEdition                                     = 316, // Player has Wrath Collector's Edition
    GarrisonTalentResearchedAndAtRankEqualOrGreaterThan                 = 317, /*NYI*/ // Garrison has talent "{GarrTalent}" researched and active at or above {#Rank}
    CurrencySpentOnGarrisonTalentResearchEqualOrGreaterThan             = 318, /*NYI*/ // Currency {CurrencyTypes} Spent on Garrison Talent Research in Tree {GarrTalentTree} is greater than or equal to {#Quantity}
    RenownCatchupActive                                                 = 319, /*NYI*/ // Renown Catchup Active
    RapidRenownCatchupActive                                            = 320, /*NYI*/ // Rapid Renown Catchup Active
    PlayerMythicPlusRatingEqualOrGreaterThan                            = 321, /*NYI*/ // Player has Mythic+ Rating of at least "{#DungeonScore}"
    PlayerMythicPlusRunCountInCurrentExpansionEqualOrGreaterThan        = 322, /*NYI*/ // Player has completed at least "{#MythicKeystoneRuns}" Mythic+ runs in current expansion
    PlayerHasCustomizationChoice                                        = 323, // (Mainline) Player has Customization Choice "{ChrCustomizationChoice}"
    PlayerBestWeeklyWinPvpTier                                          = 324, // (Mainline) Player has best weekly win in PVP tier {PvpTier}
    PlayerBestWeeklyWinPvpTierInBracketEqualOrGreaterThan               = 325, // (Mainline) Player has best weekly win at or above "{@PVP_TIER_ENUM}" for "{@PVP_BRACKET}"
    PlayerHasVanillaCollectorsEdition                                   = 326, // Player has Vanilla Collector's Edition
    PlayerHasItemWithKeystoneLevelModifierEqualOrGreaterThan            = 327,

    PlayerMythicPlusRatingInDisplaySeasonEqualOrGreaterThan             = 329, /*NYI*/ // Player has Mythic+ Rating of at least "{#DungeonScore}" in {DisplaySeason}

    MythicPlusRatingIsInTop01Percent                                    = 334, // top 0.1% rating
};

enum class ModifierTreeOperator : int8
{
    SingleTrue  = 2,
    SingleFalse = 3,
    All         = 4,
    Some        = 8
};

enum MountCapabilityFlags
{
    MOUNT_CAPABILITY_FLAG_GROUND                = 0x1,
    MOUNT_CAPABILITY_FLAG_FLYING                = 0x2,
    MOUNT_CAPABILITY_FLAG_FLOAT                 = 0x4,
    MOUNT_CAPABILITY_FLAG_UNDERWATER            = 0x8,
    MOUNT_CAPABIILTY_FLAG_IGNORE_RESTRICTIONS   = 0x20,
};

enum MountFlags
{
    MOUNT_FLAG_SELF_MOUNT               = 0x02,                   // Player becomes the mount himself
    MOUNT_FLAG_FACTION_SPECIFIC         = 0x04,
    MOUNT_FLAG_PREFERRED_SWIMMING       = 0x10,
    MOUNT_FLAG_PREFERRED_WATER_WALKING  = 0x20,
    MOUNT_FLAG_HIDE_IF_UNKNOWN          = 0x40
};

enum class PhaseEntryFlags : uint16
{
    ReadOnly                = 0x001,
    InternalPhase           = 0x002,
    Normal                  = 0x008,
    Cosmetic                = 0x010,
    Personal                = 0x020,
    Expensive               = 0x040,
    EventsAreObservable     = 0x080,
    UsesPreloadConditions   = 0x100,
    UnshareablePersonal     = 0x200,
    ObjectsAreVisible       = 0x400,
};

DEFINE_ENUM_FLAG(PhaseEntryFlags);

// PhaseUseFlags fields in different db2s
enum PhaseUseFlagsValues : uint8
{
    PHASE_USE_FLAGS_NONE            = 0x0,
    PHASE_USE_FLAGS_ALWAYS_VISIBLE  = 0x1,
    PHASE_USE_FLAGS_INVERSE         = 0x2,

    PHASE_USE_FLAGS_ALL             = PHASE_USE_FLAGS_ALWAYS_VISIBLE | PHASE_USE_FLAGS_INVERSE
};

enum class PlayerConditionLfgStatus : uint8
{
    InLFGDungeon            = 1,
    InLFGRandomDungeon      = 2,
    InLFGFirstRandomDungeon = 3,
    PartialClear            = 4,
    StrangerCount           = 5,
    VoteKickCount           = 6,
    BootCount               = 7,
    GearDiff                = 8
};

enum PrestigeLevelInfoFlags : uint8
{
    PRESTIGE_FLAG_DISABLED  = 0x01                      // Prestige levels with this flag won't be included to calculate max prestigelevel.
};

enum QuestPackageFilter
{
    QUEST_PACKAGE_FILTER_LOOT_SPECIALIZATION    = 0,    // Players can select this quest reward if it matches their selected loot specialization
    QUEST_PACKAGE_FILTER_CLASS                  = 1,    // Players can select this quest reward if it matches their class
    QUEST_PACKAGE_FILTER_UNMATCHED              = 2,    // Players can select this quest reward if no class/loot_spec rewards are available
    QUEST_PACKAGE_FILTER_EVERYONE               = 3     // Players can always select this quest reward
};

enum ScenarioStepFlags
{
    SCENARIO_STEP_FLAG_BONUS_OBJECTIVE      = 0x1,
    SCENARIO_STEP_FLAG_HEROIC_ONLY          = 0x2
};

enum SkillRaceClassInfoFlags
{
    SKILL_FLAG_NO_SKILLUP_MESSAGE       = 0x2,
    SKILL_FLAG_ALWAYS_MAX_VALUE         = 0x10,
    SKILL_FLAG_UNLEARNABLE              = 0x20,     // Skill can be unlearned
    SKILL_FLAG_INCLUDE_IN_SORT          = 0x80,     // Spells belonging to a skill with this flag will additionally compare skill ids when sorting spellbook in client
    SKILL_FLAG_NOT_TRAINABLE            = 0x100,
    SKILL_FLAG_MONO_VALUE               = 0x400     // Skill always has value 1 - clientside display flag, real value can be different
};

enum SpellCategoryFlags
{
    SPELL_CATEGORY_FLAG_COOLDOWN_SCALES_WITH_WEAPON_SPEED   = 0x01, // unused
    SPELL_CATEGORY_FLAG_COOLDOWN_STARTS_ON_EVENT            = 0x04,
    SPELL_CATEGORY_FLAG_COOLDOWN_EXPIRES_AT_DAILY_RESET     = 0x08
};

enum class SpellEffectAttributes
{
    None                                    = 0,
    UnaffectedByInvulnerability             = 0x000001, // not cancelled by immunities
    NoScaleWithStack                        = 0x000040,
    StackAuraAmountOnRecast                 = 0x008000, // refreshing periodic auras with this attribute will add remaining damage to new aura
    AllowAnyExplicitTarget                  = 0x100000,
    IgnoreDuringCooldownTimeRateCalculation = 0x800000
};

DEFINE_ENUM_FLAG(SpellEffectAttributes);

#define MAX_SPELL_EFFECTS 32
#define MAX_EFFECT_MASK 0xFFFFFFFF

#define MAX_SPELL_AURA_INTERRUPT_FLAGS 2

enum class SpellItemEnchantmentFlags : uint16
{
    Soulbound               = 0x001,
    DoNotLog                = 0x002,
    MainhandOnly            = 0x004,
    AllowEnteringArena      = 0x008,
    DoNotSaveToDB           = 0x010,
    ScaleAsAGem             = 0x020,
    DisableInChallengeModes = 0x040,
    DisableInProvingGrounds = 0x080,
    AllowTransmog           = 0x100,
    HideUntilCollected      = 0x200,
};

DEFINE_ENUM_FLAG(SpellItemEnchantmentFlags);

enum SpellProcsPerMinuteModType
{
    SPELL_PPM_MOD_HASTE         = 1,
    SPELL_PPM_MOD_CRIT          = 2,
    SPELL_PPM_MOD_CLASS         = 3,
    SPELL_PPM_MOD_SPEC          = 4,
    SPELL_PPM_MOD_RACE          = 5,
    SPELL_PPM_MOD_ITEM_LEVEL    = 6,
    SPELL_PPM_MOD_BATTLEGROUND  = 7
};

constexpr std::size_t MAX_POWERS_PER_SPELL = 4;

enum class SpellShapeshiftFormFlags : int32
{
    Stance                      = 0x00000001,
    NotToggleable               = 0x00000002,   // player cannot cancel the aura giving this shapeshift
    PersistOnDeath              = 0x00000004,
    CanInteractNPC              = 0x00000008,   // if the form does not have SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT then this flag must be present to allow NPC interaction
    DontUseWeapon               = 0x00000010,

    CanUseEquippedItems         = 0x00000040,   // if the form does not have SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT then this flag allows equipping items without ITEM_FLAG_USABLE_WHEN_SHAPESHIFTED
    CanUseItems                 = 0x00000080,   // if the form does not have SHAPESHIFT_FORM_IS_NOT_A_SHAPESHIFT then this flag allows using items without ITEM_FLAG_USABLE_WHEN_SHAPESHIFTED
    DontAutoUnshift             = 0x00000100,   // clientside
    ConsideredDead              = 0x00000200,
    CanOnlyCastShapeshiftSpells = 0x00000400,   // prevents using spells that don't have any shapeshift requirement
    StanceCancelsAtFlightmaster = 0x00000800,
    NoEmoteSounds               = 0x00001000,
    NoTriggerTeleport           = 0x00002000,
    CannotChangeEquippedItems   = 0x00004000,

    CannotUseGameObjects        = 0x00010000
};

DEFINE_ENUM_FLAG(SpellShapeshiftFormFlags);

enum class SpellVisualEffectNameType : uint32
{
    Model                           = 0,
    Item                            = 1,
    Creature                        = 2,
    UnitItemMainHand                = 3,
    UnitItemOffHand                 = 4,
    UnitItemRanged                  = 5,
    UnitAmmoBasic                   = 6,
    UnitAmmoPreferred               = 7,
    UnitItemMainHandIgnoreDisarmed  = 8,
    UnitItemOffHandIgnoreDisarmed   = 9,
    UnitItemRangedIgnoreDisarmed    = 10
};

#define TaxiMaskSize 345
typedef std::array<uint8, TaxiMaskSize> TaxiMask;

enum TotemCategoryType
{
    TOTEM_CATEGORY_TYPE_KNIFE           = 1,
    TOTEM_CATEGORY_TYPE_TOTEM           = 2,
    TOTEM_CATEGORY_TYPE_ROD             = 3,
    TOTEM_CATEGORY_TYPE_PICK            = 21,
    TOTEM_CATEGORY_TYPE_STONE           = 22,
    TOTEM_CATEGORY_TYPE_HAMMER          = 23,
    TOTEM_CATEGORY_TYPE_SPANNER         = 24
};

// SummonProperties.dbc, col 1
enum SummonPropGroup
{
    SUMMON_PROP_GROUP_UNKNOWN1       = 0,                   // 1160 spells in 3.0.3
    SUMMON_PROP_GROUP_UNKNOWN2       = 1,                   // 861 spells in 3.0.3
    SUMMON_PROP_GROUP_PETS           = 2,                   // 52 spells in 3.0.3, pets mostly
    SUMMON_PROP_GROUP_CONTROLLABLE   = 3,                   // 13 spells in 3.0.3, mostly controllable
    SUMMON_PROP_GROUP_UNKNOWN3       = 4                    // 86 spells in 3.0.3, taxi/mounts
};

// SummonProperties.dbc, col 3
enum SummonPropType
{
    SUMMON_PROP_TYPE_UNKNOWN         = 0,                   // different summons, 1330 spells in 3.0.3
    SUMMON_PROP_TYPE_SUMMON          = 1,                   // generic summons, 49 spells in 3.0.3
    SUMMON_PROP_TYPE_GUARDIAN        = 2,                   // summon guardian, 393 spells in 3.0.3
    SUMMON_PROP_TYPE_ARMY            = 3,                   // summon army, 5 spells in 3.0.3
    SUMMON_PROP_TYPE_TOTEM           = 4,                   // summon totem, 169 spells in 3.0.3
    SUMMON_PROP_TYPE_CRITTER         = 5,                   // critter/minipet, 195 spells in 3.0.3
    SUMMON_PROP_TYPE_DK              = 6,                   // summon DRW/Ghoul, 2 spells in 3.0.3
    SUMMON_PROP_TYPE_BOMB            = 7,                   // summon bot/bomb, 4 spells in 3.0.3
    SUMMON_PROP_TYPE_PHASING         = 8,                   // something todo with DK prequest line, 2 spells in 3.0.3
    SUMMON_PROP_TYPE_SIEGE_VEH       = 9,                   // summon different vehicles, 14 spells in 3.0.3
    SUMMON_PROP_TYPE_DRAKE_VEH       = 10,                  // summon drake (vehicle), 3 spells
    SUMMON_PROP_TYPE_LIGHTWELL       = 11,                  // summon lightwell, 6 spells in 3.0.3
    SUMMON_PROP_TYPE_JEEVES          = 12,                  // summon Jeeves, 1 spell in 3.3.5a
    SUMMON_PROP_TYPE_LASHTAIL        = 13                   // Lashtail Hatchling, 1 spell in 4.2.2
};

enum class SummonPropertiesFlags : uint32
{
    None                              = 0x00000000,
    AttackSummoner                    = 0x00000001, // NYI
    HelpWhenSummonedInCombat          = 0x00000002, // NYI
    UseLevelOffset                    = 0x00000004, // NYI
    DespawnOnSummonerDeath            = 0x00000008, // NYI
    OnlyVisibleToSummoner             = 0x00000010,
    CannotDismissPet                  = 0x00000020, // NYI
    UseDemonTimeout                   = 0x00000040, // NYI
    UnlimitedSummons                  = 0x00000080, // NYI
    UseCreatureLevel                  = 0x00000100,
    JoinSummonerSpawnGroup            = 0x00000200, // NYI
    DoNotToggle                       = 0x00000400, // NYI
    DespawnWhenExpired                = 0x00000800, // NYI
    UseSummonerFaction                = 0x00001000,
    DoNotFollowMountedSummoner        = 0x00002000, // NYI
    SavePetAutocast                   = 0x00004000, // NYI
    IgnoreSummonerPhase               = 0x00008000, // Wild Only
    OnlyVisibleToSummonerGroup        = 0x00010000,
    DespawnOnSummonerLogout           = 0x00020000, // NYI
    CastRideVehicleSpellOnSummoner    = 0x00040000, // NYI
    GuardianActsLikePet               = 0x00080000, // NYI
    DontSnapSessileToGround           = 0x00100000, // NYI
    SummonFromBattlePetJournal        = 0x00200000,
    UnitClutter                       = 0x00400000, // NYI
    DefaultNameColor                  = 0x00800000, // NYI
    UseOwnInvisibilityDetection       = 0x01000000, // NYI. Ignore Owner's Invisibility Detection
    DespawnWhenReplaced               = 0x02000000, // NYI. Totem Slots Only
    DespawnWhenTeleportingOutOfRange  = 0x04000000, // NYI
    SummonedAtGroupFormationPosition  = 0x08000000, // NYI
    DontDespawnOnSummonerDeath        = 0x10000000, // NYI
    UseTitleAsCreatureName            = 0x20000000, // NYI
    AttackableBySummoner              = 0x40000000, // NYI
    DontDismissWhenEncounterIsAborted = 0x80000000  // NYI
};

DEFINE_ENUM_FLAG(SummonPropertiesFlags);

#define MAX_TALENT_TIERS 7
#define MAX_TALENT_COLUMNS 3
#define MAX_PVP_TALENT_SLOTS 4

enum TaxiNodeFlags
{
    TAXI_NODE_FLAG_ALLIANCE             = 0x01,
    TAXI_NODE_FLAG_HORDE                = 0x02,
    TAXI_NODE_FLAG_USE_FAVORITE_MOUNT   = 0x10
};

enum TaxiPathNodeFlags
{
    TAXI_PATH_NODE_FLAG_TELEPORT    = 0x1,
    TAXI_PATH_NODE_FLAG_STOP        = 0x2
};

enum class UiMapFlag : int32
{
    None                    = 0,
    NoHighlight             = 0x00000001,
    ShowOverlays            = 0x00000002,
    ShowTaxiNodes           = 0x00000004,
    GarrisonMap             = 0x00000008,
    FallbackToParentMap     = 0x00000010,
    NoHighlightTexture      = 0x00000020,
    ShowTaskObjectives      = 0x00000040,
    NoWorldPositions        = 0x00000080,
    HideArchaeologyDigs     = 0x00000100,
    Deprecated              = 0x00000200,
    HideIcons               = 0x00000400,
    HideVignettes           = 0x00000800,
    ForceAllOverlayExplored = 0x00001000,
    FlightMapShowZoomOut    = 0x00002000,
    FlightMapAutoZoom       = 0x00004000,
    ForceOnNavbar           = 0x00008000
};

DEFINE_ENUM_FLAG(UiMapFlag);

enum UiMapSystem : int8
{
    UI_MAP_SYSTEM_WORLD     = 0,
    UI_MAP_SYSTEM_TAXI      = 1,
    UI_MAP_SYSTEM_ADVENTURE = 2,
    UI_MAP_SYSTEM_MINIMAP   = 3,
    MAX_UI_MAP_SYSTEM
};

enum UiMapType : int8
{
    UI_MAP_TYPE_COSMIC      = 0,
    UI_MAP_TYPE_WORLD       = 1,
    UI_MAP_TYPE_CONTINENT   = 2,
    UI_MAP_TYPE_ZONE        = 3,
    UI_MAP_TYPE_DUNGEON     = 4,
    UI_MAP_TYPE_MICRO       = 5,
    UI_MAP_TYPE_ORPHAN      = 6,
};

enum class UnitConditionFlags : uint8
{
    LogicOr = 0x1
};

DEFINE_ENUM_FLAG(UnitConditionFlags);

enum class UnitConditionOp : int8
{
    EqualTo                 = 1,
    NotEqualTo              = 2,
    LessThan                = 3,
    LessThanOrEqualTo       = 4,
    GreaterThan             = 5,
    GreaterThanOrEqualTo    = 6
};

enum class UnitConditionVariable : uint8
{
    None                                = 0,  // - NONE -
    Race                                = 1,  // Race {$Is/Is Not} "{ChrRaces}"
    Class                               = 2,  // Class {$Is/Is Not} "{ChrClasses}"
    Level                               = 3,  // Level {$Relative Op} "{#Level}"
    IsSelf                              = 4,  // Is self? {$Yes/No}{=1}
    IsMyPet                             = 5,  // Is my pet? {$Yes/No}{=1}
    IsMaster                            = 6,  // Is master? {$Yes/No}{=1}
    IsTarget                            = 7,  // Is target? {$Yes/No}{=1}
    CanAssist                           = 8,  // Can assist? {$Yes/No}{=1}
    CanAttack                           = 9,  // Can attack? {$Yes/No}{=1}
    HasPet                              = 10, // Has pet? {$Yes/No}{=1}
    HasWeapon                           = 11, // Has weapon? {$Yes/No}{=1}
    HealthPct                           = 12, // Health {$Relative Op} {#Health %}%
    ManaPct                             = 13, // Mana {$Relative Op} {#Mana %}%
    RagePct                             = 14, // Rage {$Relative Op} {#Rage %}%
    EnergyPct                           = 15, // Energy {$Relative Op} {#Energy %}%
    ComboPoints                         = 16, // Combo Points {$Relative Op} {#Points}
    HasHelpfulAuraSpell                 = 17, // Has helpful aura spell? {$Yes/No} "{Spell}"
    HasHelpfulAuraDispelType            = 18, // Has helpful aura dispel type? {$Yes/No} "{SpellDispelType}"
    HasHelpfulAuraMechanic              = 19, // Has helpful aura mechanic? {$Yes/No} "{SpellMechanic}"
    HasHarmfulAuraSpell                 = 20, // Has harmful aura spell? {$Yes/No} "{Spell}"
    HasHarmfulAuraDispelType            = 21, // Has harmful aura dispel type? {$Yes/No} "{SpellDispelType}"
    HasHarmfulAuraMechanic              = 22, // Has harmful aura mechanic? {$Yes/No} "{SpellMechanic}"
    HasHarmfulAuraSchool                = 23, // Has harmful aura school? {$Yes/No} "{Resistances}"
    DamagePhysicalPct                   = 24, // NYI Damage (Physical) {$Relative Op} {#Physical Damage %}%
    DamageHolyPct                       = 25, // NYI Damage (Holy) {$Relative Op} {#Holy Damage %}%
    DamageFirePct                       = 26, // NYI Damage (Fire) {$Relative Op} {#Fire Damage %}%
    DamageNaturePct                     = 27, // NYI Damage (Nature) {$Relative Op} {#Nature Damage %}%
    DamageFrostPct                      = 28, // NYI Damage (Frost) {$Relative Op} {#Frost Damage %}%
    DamageShadowPct                     = 29, // NYI Damage (Shadow) {$Relative Op} {#Shadow Damage %}%
    DamageArcanePct                     = 30, // NYI Damage (Arcane) {$Relative Op} {#Arcane Damage %}%
    InCombat                            = 31, // In combat? {$Yes/No}{=1}
    IsMoving                            = 32, // Is moving? {$Yes/No}{=1}
    IsCasting                           = 33, // Is casting? {$Yes/No}{=1}
    IsCastingSpell                      = 34, // Is casting spell? {$Yes/No}{=1}
    IsChanneling                        = 35, // Is channeling? {$Yes/No}{=1}
    IsChannelingSpell                   = 36, // Is channeling spell? {$Yes/No}{=1}
    NumberOfMeleeAttackers              = 37, // Number of melee attackers {$Relative Op} {#Attackers}
    IsAttackingMe                       = 38, // Is attacking me? {$Yes/No}{=1}
    Range                               = 39, // Range {$Relative Op} {#Yards}
    InMeleeRange                        = 40, // In melee range? {$Yes/No}{=1}
    PursuitTime                         = 41, // NYI Pursuit time {$Relative Op} {#Seconds}
    HasHarmfulAuraCanceledByDamage      = 42, // Has harmful aura canceled by damage? {$Yes/No}{=1}
    HasHarmfulAuraWithPeriodicDamage    = 43, // Has harmful aura with periodic damage? {$Yes/No}{=1}
    NumberOfEnemies                     = 44, // Number of enemies {$Relative Op} {#Enemies}
    NumberOfFriends                     = 45, // NYI Number of friends {$Relative Op} {#Friends}
    ThreatPhysicalPct                   = 46, // NYI Threat (Physical) {$Relative Op} {#Physical Threat %}%
    ThreatHolyPct                       = 47, // NYI Threat (Holy) {$Relative Op} {#Holy Threat %}%
    ThreatFirePct                       = 48, // NYI Threat (Fire) {$Relative Op} {#Fire Threat %}%
    ThreatNaturePct                     = 49, // NYI Threat (Nature) {$Relative Op} {#Nature Threat %}%
    ThreatFrostPct                      = 50, // NYI Threat (Frost) {$Relative Op} {#Frost Threat %}%
    ThreatShadowPct                     = 51, // NYI Threat (Shadow) {$Relative Op} {#Shadow Threat %}%
    ThreatArcanePct                     = 52, // NYI Threat (Arcane) {$Relative Op} {#Arcane Threat %}%
    IsInterruptible                     = 53, // NYI Is interruptible? {$Yes/No}{=1}
    NumberOfAttackers                   = 54, // Number of attackers {$Relative Op} {#Attackers}
    NumberOfRangedAttackers             = 55, // Number of ranged attackers {$Relative Op} {#Ranged Attackers}
    CreatureType                        = 56, // Creature type {$Is/Is Not} "{CreatureType}"
    IsMeleeAttacking                    = 57, // Is melee-attacking? {$Yes/No}{=1}
    IsRangedAttacking                   = 58, // Is ranged-attacking? {$Yes/No}{=1}
    Health                              = 59, // Health {$Relative Op} {#HP} HP
    SpellKnown                          = 60, // Spell known? {$Yes/No} "{Spell}"
    HasHarmfulAuraEffect                = 61, // Has harmful aura effect? {$Yes/No} "{#Spell Aura}"
    IsImmuneToAreaOfEffect              = 62, // NYI Is immune to area-of-effect? {$Yes/No}{=1}
    IsPlayer                            = 63, // Is player? {$Yes/No}{=1}
    DamageMagicPct                      = 64, // NYI Damage (Magic) {$Relative Op} {#Magic Damage %}%
    DamageTotalPct                      = 65, // NYI Damage (Total) {$Relative Op} {#Damage %}%
    ThreatMagicPct                      = 66, // NYI Threat (Magic) {$Relative Op} {#Magic Threat %}%
    ThreatTotalPct                      = 67, // NYI Threat (Total) {$Relative Op} {#Threat %}%
    HasCritter                          = 68, // Has critter? {$Yes/No}{=1}
    HasTotemInSlot1                     = 69, // Has totem in slot 1? {$Yes/No}{=1}
    HasTotemInSlot2                     = 70, // Has totem in slot 2? {$Yes/No}{=1}
    HasTotemInSlot3                     = 71, // Has totem in slot 3? {$Yes/No}{=1}
    HasTotemInSlot4                     = 72, // Has totem in slot 4? {$Yes/No}{=1}
    HasTotemInSlot5                     = 73, // NYI Has totem in slot 5? {$Yes/No}{=1}
    Creature                            = 74, // Creature {$Is/Is Not} "{Creature}"
    StringID                            = 75, // NYI String ID {$Is/Is Not} "{StringID}"
    HasAura                             = 76, // Has aura? {$Yes/No} {Spell}
    IsEnemy                             = 77, // Is enemy? {$Yes/No}{=1}
    IsSpecMelee                         = 78, // Is spec - melee? {$Yes/No}{=1}
    IsSpecTank                          = 79, // Is spec - tank? {$Yes/No}{=1}
    IsSpecRanged                        = 80, // Is spec - ranged? {$Yes/No}{=1}
    IsSpecHealer                        = 81, // Is spec - healer? {$Yes/No}{=1}
    IsPlayerControlledNPC               = 82, // Is player controlled NPC? {$Yes/No}{=1}
    IsDying                             = 83, // Is dying? {$Yes/No}{=1}
    PathFailCount                       = 84, // NYI Path fail count {$Relative Op} {#Path Fail Count}
    IsMounted                           = 85, // Is mounted? {$Yes/No}{=1}
    Label                               = 86, // NYI Label {$Is/Is Not} "{Label}"
    IsMySummon                          = 87, //
    IsSummoner                          = 88, //
    IsMyTarget                          = 89, //
    Sex                                 = 90, // Sex {$Is/Is Not} "{UnitSex}"
    LevelWithinContentTuning            = 91, // Level is within {$Is/Is Not} {ContentTuning}

    IsFlying                            = 93, // Is flying? {$Yes/No}{=1}
    IsHovering                          = 94, // Is hovering? {$Yes/No}{=1}
    HasHelpfulAuraEffect                = 95, // Has helpful aura effect? {$Yes/No} "{#Spell Aura}"
    HasHelpfulAuraSchool                = 96, // Has helpful aura school? {$Yes/No} "{Resistances}"
};

enum VehicleSeatFlags
{
    VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_ENTER                         = 0x00000001,
    VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_RIDE                          = 0x00000002,
    VEHICLE_SEAT_FLAG_DISABLE_GRAVITY                                  = 0x00000004, // Passenger will not be affected by gravity
    VEHICLE_SEAT_FLAG_SHOULD_USE_VEH_SEAT_EXIT_ANIM_ON_VOLUNTARY_EXIT  = 0x00000008,
    VEHICLE_SEAT_FLAG_UNK5                                             = 0x00000010,
    VEHICLE_SEAT_FLAG_UNK6                                             = 0x00000020,
    VEHICLE_SEAT_FLAG_UNK7                                             = 0x00000040,
    VEHICLE_SEAT_FLAG_UNK8                                             = 0x00000080,
    VEHICLE_SEAT_FLAG_UNK9                                             = 0x00000100,
    VEHICLE_SEAT_FLAG_HIDE_PASSENGER                                   = 0x00000200, // Passenger is hidden
    VEHICLE_SEAT_FLAG_ALLOW_TURNING                                    = 0x00000400, // needed for CGCamera__SyncFreeLookFacing
    VEHICLE_SEAT_FLAG_CAN_CONTROL                                      = 0x00000800, // Lua_UnitInVehicleControlSeat
    VEHICLE_SEAT_FLAG_CAN_CAST_MOUNT_SPELL                             = 0x00001000, // Can cast spells with SPELL_AURA_MOUNTED from seat (possibly 4.x only, 0 seats on 3.3.5a)
    VEHICLE_SEAT_FLAG_UNCONTROLLED                                     = 0x00002000, // can override !& VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT
    VEHICLE_SEAT_FLAG_CAN_ATTACK                                       = 0x00004000, // Can attack, cast spells and use items from vehicle
    VEHICLE_SEAT_FLAG_SHOULD_USE_VEH_SEAT_EXIT_ANIM_ON_FORCED_EXIT     = 0x00008000,
    VEHICLE_SEAT_FLAG_UNK17                                            = 0x00010000,
    VEHICLE_SEAT_FLAG_UNK18                                            = 0x00020000, // Needs research and support (28 vehicles): Allow entering vehicles while keeping specific permanent(?) auras that impose visuals (states like beeing under freeze/stun mechanic, emote state animations).
    VEHICLE_SEAT_FLAG_HAS_VEH_EXIT_ANIM_VOLUNTARY_EXIT                 = 0x00040000,
    VEHICLE_SEAT_FLAG_HAS_VEH_EXIT_ANIM_FORCED_EXIT                    = 0x00080000,
    VEHICLE_SEAT_FLAG_PASSENGER_NOT_SELECTABLE                         = 0x00100000,
    VEHICLE_SEAT_FLAG_UNK22                                            = 0x00200000,
    VEHICLE_SEAT_FLAG_REC_HAS_VEHICLE_ENTER_ANIM                       = 0x00400000,
    VEHICLE_SEAT_FLAG_IS_USING_VEHICLE_CONTROLS                        = 0x00800000, // Lua_IsUsingVehicleControls
    VEHICLE_SEAT_FLAG_ENABLE_VEHICLE_ZOOM                              = 0x01000000,
    VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT                                = 0x02000000, // Lua_CanExitVehicle - can enter and exit at free will
    VEHICLE_SEAT_FLAG_CAN_SWITCH                                       = 0x04000000, // Lua_CanSwitchVehicleSeats
    VEHICLE_SEAT_FLAG_HAS_START_WARITING_FOR_VEH_TRANSITION_ANIM_ENTER = 0x08000000,
    VEHICLE_SEAT_FLAG_HAS_START_WARITING_FOR_VEH_TRANSITION_ANIM_EXIT  = 0x10000000,
    VEHICLE_SEAT_FLAG_CAN_CAST                                         = 0x20000000, // Lua_UnitHasVehicleUI
    VEHICLE_SEAT_FLAG_UNK2                                             = 0x40000000, // checked in conjunction with 0x800 in CastSpell2
    VEHICLE_SEAT_FLAG_ALLOWS_INTERACTION                               = 0x80000000
};

enum VehicleSeatFlagsB
{
    VEHICLE_SEAT_FLAG_B_NONE                     = 0x00000000,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED            = 0x00000002,
    VEHICLE_SEAT_FLAG_B_TARGETS_IN_RAIDUI        = 0x00000008,           // Lua_UnitTargetsVehicleInRaidUI
    VEHICLE_SEAT_FLAG_B_EJECTABLE                = 0x00000020,           // ejectable
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_2          = 0x00000040,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_3          = 0x00000100,
    VEHICLE_SEAT_FLAG_B_PASSENGER_MIRRORS_ANIMS  = 0x00010000,           // Passenger forced to repeat all vehicle animations
    VEHICLE_SEAT_FLAG_B_KEEP_PET                 = 0x00020000,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_4          = 0x02000000,
    VEHICLE_SEAT_FLAG_B_CAN_SWITCH               = 0x04000000,
    VEHICLE_SEAT_FLAG_B_VEHICLE_PLAYERFRAME_UI   = 0x80000000            // Lua_UnitHasVehiclePlayerFrameUI - actually checked for flagsb &~ 0x80000000
};

// CurrencyTypes.dbc
enum CurrencyTypes
{
    CURRENCY_TYPE_JUSTICE_POINTS        = 395,
    CURRENCY_TYPE_VALOR_POINTS          = 396,
    CURRENCY_TYPE_APEXIS_CRYSTALS       = 823,
    CURRENCY_TYPE_AZERITE               = 1553
};

enum WorldMapTransformsFlags
{
    WORLD_MAP_TRANSFORMS_FLAG_DUNGEON   = 0x04
};

enum class WorldStateExpressionValueType : uint8
{
    Constant    = 1,
    WorldState  = 2,
    Function    = 3
};

enum class WorldStateExpressionLogic : uint8
{
    None    = 0,
    And     = 1,
    Or      = 2,
    Xor     = 3,
};

enum class WorldStateExpressionComparisonType : uint8
{
    None            = 0,
    Equal           = 1,
    NotEqual        = 2,
    Less            = 3,
    LessOrEqual     = 4,
    Greater         = 5,
    GreaterOrEqual  = 6,
};

enum class WorldStateExpressionOperatorType : uint8
{
    None            = 0,
    Sum             = 1,
    Substraction    = 2,
    Multiplication  = 3,
    Division        = 4,
    Remainder       = 5,
};

enum WorldStateExpressionFunctions
{
    WSE_FUNCTION_NONE = 0,
    WSE_FUNCTION_RANDOM,
    WSE_FUNCTION_MONTH,
    WSE_FUNCTION_DAY,
    WSE_FUNCTION_TIME_OF_DAY,
    WSE_FUNCTION_REGION,
    WSE_FUNCTION_CLOCK_HOUR,
    WSE_FUNCTION_OLD_DIFFICULTY_ID,
    WSE_FUNCTION_HOLIDAY_START,
    WSE_FUNCTION_HOLIDAY_LEFT,
    WSE_FUNCTION_HOLIDAY_ACTIVE,
    WSE_FUNCTION_TIMER_CURRENT_TIME,
    WSE_FUNCTION_WEEK_NUMBER,
    WSE_FUNCTION_UNK13,
    WSE_FUNCTION_UNK14,
    WSE_FUNCTION_DIFFICULTY_ID,
    WSE_FUNCTION_WAR_MODE_ACTIVE,
    WSE_FUNCTION_UNK17,
    WSE_FUNCTION_UNK18,
    WSE_FUNCTION_UNK19,
    WSE_FUNCTION_UNK20,
    WSE_FUNCTION_UNK21,
    WSE_FUNCTION_WORLD_STATE_EXPRESSION,
    WSE_FUNCTION_KEYSTONE_AFFIX,
    WSE_FUNCTION_UNK24,
    WSE_FUNCTION_UNK25,
    WSE_FUNCTION_UNK26,
    WSE_FUNCTION_UNK27,
    WSE_FUNCTION_KEYSTONE_LEVEL,
    WSE_FUNCTION_UNK29,
    WSE_FUNCTION_UNK30,
    WSE_FUNCTION_UNK31,
    WSE_FUNCTION_UNK32,
    WSE_FUNCTION_MERSENNE_RANDOM,
    WSE_FUNCTION_UNK34,
    WSE_FUNCTION_UNK35,
    WSE_FUNCTION_UNK36,
    WSE_FUNCTION_UI_WIDGET_DATA,

    WSE_FUNCTION_MAX,
};

#endif
