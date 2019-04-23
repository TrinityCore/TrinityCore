/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef GarrisonConstants_h__
#define GarrisonConstants_h__

enum GarrisonTimers
{
    GUPDATE_MISSIONS_DISTRIBUTION,

    GUPDATE_COUNT
};

enum GarrisonMisc
{
    GARRISON_WOD_CURRENCY   = 824,
};

enum GarrisonSite
{
    GARRISON_SITE_WOD_ALLIANCE          = 2,
    GARRISON_SITE_WOD_HORDE             = 71,
    GARRISON_SITE_CLASS_HALL_ALLIANCE   = 161,
    GARRISON_SITE_CLASS_HALL_HORDE      = 163,
};

enum GarrisonType : int32
{
    GARRISON_TYPE_NONE          = 0,
    GARRISON_TYPE_GARRISON      = 2,
    GARRISON_TYPE_CLASS_HALL    = 3,
    //GARRISON_TYPE_WAR_CAMPAIGN  = 9,

    GARRISON_TYPE_MIN           = GARRISON_TYPE_GARRISON,
    GARRISON_TYPE_MAX           = GARRISON_TYPE_CLASS_HALL + 1,
};

enum GarrisonFactionIndex
{
    GARRISON_FACTION_INDEX_HORDE    = 0,
    GARRISON_FACTION_INDEX_ALLIANCE = 1
};

enum GarrisonFollowerFlags
{
    GARRISON_FOLLOWER_FLAG_UNIQUE   = 0x1
};

enum GarrisonFollowerType
{
    FOLLOWER_TYPE_GARRISON      = 1,
    FOLLOWER_TYPE_SHIPYARD      = 2,
    FOLLOWER_TYPE_CLASS_HALL    = 4
};

enum GarrisonAbilityFlags
{
    GARRISON_ABILITY_FLAG_TRAIT                         = 0x0001,
    GARRISON_ABILITY_CANNOT_ROLL                        = 0x0002,
    GARRISON_ABILITY_HORDE_ONLY                         = 0x0004,
    GARRISON_ABILITY_ALLIANCE_ONLY                      = 0x0008,
    GARRISON_ABILITY_FLAG_CANNOT_REMOVE                 = 0x0010,
    GARRISON_ABILITY_FLAG_EXCLUSIVE                     = 0x0020,
    GARRISON_ABILITY_FLAG_SINGLE_MISSION_DURATION       = 0x0040,
    GARRISON_ABILITY_FLAG_ACTIVE_ONLY_ON_ZONE_SUPPORT   = 0x0080,
    GARRISON_ABILITY_FLAG_APPLY_TO_FIRST_MISSION        = 0x0100,
    GARRISON_ABILITY_FLAG_IS_SPECIALIZATION             = 0x0200,
    GARRISON_ABILITY_FLAG_IS_EMPTY_SLOT                 = 0x0400
};

enum GarrisonAbilityEffectType
{
    ModUnk0                        = 0,    ///< @TODO
    ModWinRateSolo                 = 1,    ///< Proc if MissionFollowerCount == 1
    ModWinRate                     = 2,    ///< Proc every time
    ModTravelTime                  = 3,    ///< Proc every time
    ModXpGain                      = 4,    ///< Mod the XP earn (self, party)
    ModWinRateClass                = 5,    ///< Proc if Find(MissionFollowers[Class], MiscValueA) != NULL
    ModWinRateDurationMore         = 6,    ///< Proc if Duration > (3600 * MiscValueB)
    ModWinRateDurationLess         = 7,    ///< Proc if Duration < (3600 * MiscValueB)
    ModGarrCurrencyDrop            = 8,    ///< Implemented.
    ModWinRateTravelDurationMore   = 9,    ///< Proc if TravelDuration > (3600 * MiscValueB)
    ModWinRateTravelDurationLess   = 10,   ///< Proc if TravelDuration < (3600 * MiscValueB)
    ModUnk11                       = 11,   ///< UNUSED
    ModDummyProduction             = 12,   ///< @TODO
    ModBronzeTreasureDrop          = 13,   ///< @TODO
    ModSilverTreasureDrop          = 14,   ///< @TODO
    ModGoldTreasureDrop            = 15,   ///< @TODO
    ModChestDropRate               = 16,   ///< @TODO
    ModMissionDuration             = 17    ///< Proc every time
};

enum GarrisonError
{
    GARRISON_SUCCESS                                            = 0,
    GARRISON_ERROR_NO_GARRISON                                  = 1,
    GARRISON_ERROR_GARRISON_EXISTS                              = 2,
    GARRISON_ERROR_GARRISON_SAME_TYPE_EXISTS                    = 3,
    GARRISON_ERROR_INVALID_GARRISON                             = 4,
    GARRISON_ERROR_INVALID_GARRISON_LEVEL                       = 5,
    GARRISON_ERROR_GARRISON_LEVEL_UNCHANGED                     = 6,
    GARRISON_ERROR_NOT_IN_GARRISON                              = 7,
    GARRISON_ERROR_NO_BUILDING                                  = 8,
    GARRISON_ERROR_BUILDING_EXISTS                              = 9,
    GARRISON_ERROR_INVALID_PLOT_INSTANCEID                      = 10,
    GARRISON_ERROR_INVALID_BUILDINGID                           = 11,
    GARRISON_ERROR_INVALID_UPGRADE_LEVEL                        = 12,
    GARRISON_ERROR_UPGRADE_LEVEL_EXCEEDS_GARRISON_LEVEL         = 13,
    GARRISON_ERROR_PLOTS_NOT_FULL                               = 14,
    GARRISON_ERROR_INVALID_SITE_ID                              = 15,
    GARRISON_ERROR_INVALID_PLOT_BUILDING                        = 16,
    GARRISON_ERROR_INVALID_FACTION                              = 17,
    GARRISON_ERROR_INVALID_SPECIALIZATION                       = 18,
    GARRISON_ERROR_SPECIALIZATION_EXISTS                        = 19,
    GARRISON_ERROR_SPECIALIZATION_ON_COOLDOWN                   = 20,
    GARRISON_ERROR_BLUEPRINT_EXISTS                             = 21,
    GARRISON_ERROR_REQUIRES_BLUEPRINT                           = 22,
    GARRISON_ERROR_INVALID_DOODAD_SET_ID                        = 23,
    GARRISON_ERROR_BUILDING_TYPE_EXISTS                         = 24,
    GARRISON_ERROR_BUILDING_NOT_ACTIVE                          = 25,
    GARRISON_ERROR_CONSTRUCTION_COMPLETE                        = 26,
    GARRISON_ERROR_FOLLOWER_EXISTS                              = 27,
    GARRISON_ERROR_INVALID_FOLLOWER                             = 28,
    GARRISON_ERROR_FOLLOWER_ALREADY_ON_MISSION                  = 29,
    GARRISON_ERROR_FOLLOWER_IN_BUILDING                         = 30,
    GARRISON_ERROR_FOLLOWER_INVALID_FOR_BUILDING                = 31,
    GARRISON_ERROR_INVALID_FOLLOWER_LEVEL                       = 32,
    GARRISON_ERROR_MISSION_EXISTS                               = 33,
    GARRISON_ERROR_INVALID_MISSION                              = 34,
    GARRISON_ERROR_INVALID_MISSION_TIME                         = 35,
    GARRISON_ERROR_INVALID_MISSION_REWARD_INDEX                 = 36,
    GARRISON_ERROR_MISSION_NOT_OFFERED                          = 37,
    GARRISON_ERROR_ALREADY_ON_MISSION                           = 38,
    GARRISON_ERROR_MISSION_SIZE_INVALID                         = 39,
    GARRISON_ERROR_FOLLOWER_SOFT_CAP_EXCEEDED                   = 40,
    GARRISON_ERROR_NOT_ON_MISSION                               = 41,
    GARRISON_ERROR_ALREADY_COMPLETED_MISSION                    = 42,
    GARRISON_ERROR_MISSION_NOT_COMPLETE                         = 43,
    GARRISON_ERROR_MISSION_REWARDS_PENDING                      = 44,
    GARRISON_ERROR_MISSION_EXPIRED                              = 45,
    GARRISON_ERROR_NOT_ENOUGH_CURRENCY                          = 46,
    GARRISON_ERROR_NOT_ENOUGH_GOLD                              = 47,
    GARRISON_ERROR_BUILDING_MISSING                             = 48,
    GARRISON_ERROR_NO_ARCHITECT                                 = 49,
    GARRISON_ERROR_ARCHITECT_NOT_AVAILABLE                      = 50,
    GARRISON_ERROR_NO_MISSION_NPC                               = 51,
    GARRISON_ERROR_MISSION_NPC_NOT_AVAILABLE                    = 52,
    GARRISON_ERROR_INTERNAL_ERROR                               = 53,
    GARRISON_ERROR_INVALID_STATIC_TABLE_VALUE                   = 54,
    GARRISON_ERROR_INVALID_ITEM_LEVEL                           = 55,
    GARRISON_ERROR_INVALID_AVAILABLE_RECRUIT                    = 56,
    GARRISON_ERROR_FOLLOWER_ALREADY_RECRUITED                   = 57,
    GARRISON_ERROR_RECRUITMENT_GENERATION_IN_PROGRESS           = 58,
    GARRISON_ERROR_RECRUITMENT_ON_COOLDOWN                      = 59,
    GARRISON_ERROR_RECRUIT_BLOCKED_BY_GENERATION                = 60,
    GARRISON_ERROR_RECRUITMENT_NPC_NOT_AVAILABLE                = 61,
    GARRISON_ERROR_INVALID_FOLLOWER_QUALITY                     = 62,
    GARRISON_ERROR_PROXY_NOT_OK                                 = 63,
    GARRISON_ERROR_RECALL_PORTAL_USED_LESS_THAN_24_HOURS_AGO    = 64,
    GARRISON_ERROR_ON_REMOVE_BUILDING_SPELL_FAILED              = 65,
    GARRISON_ERROR_OPERATION_NOT_SUPPORTED                      = 66,
    GARRISON_ERROR_FOLLOWER_FATIGUED                            = 67,
    GARRISON_ERROR_UPGRADE_CONDITION_FAILED                     = 68,
    GARRISON_ERROR_FOLLOWER_INACTIVE                            = 69,
    GARRISON_ERROR_FOLLOWER_ACTIVE                              = 70,
    GARRISON_ERROR_FOLLOWER_ACTIVATION_UNAVAILABLE              = 71,
    GARRISON_ERROR_FOLLOWER_TYPE_MISMATCH                       = 72,
    GARRISON_ERROR_INVALID_GARRISON_TYPE                        = 73,
    GARRISON_ERROR_MISSION_START_CONDITION_FAILED               = 74,
    GARRISON_ERROR_INVALID_FOLLOWER_ABILITY                     = 75,
    GARRISON_ERROR_INVALID_MISSION_BONUS_ABILITY                = 76,
    GARRISON_ERROR_HIGHER_BUILDING_TYPE_EXISTS                  = 77,
    GARRISON_ERROR_AT_FOLLOWER_HARD_CAP                         = 78,
    GARRISON_ERROR_FOLLOWER_CANNOT_GAIN_XP                      = 79,
    GARRISON_ERROR_NO_OP                                        = 80,
    GARRISON_ERROR_AT_CLASS_SPEC_CAP                            = 81,
    GARRISON_ERROR_MISSION_REQUIRES_100_TO_START                = 82,
    GARRISON_ERROR_MISSION_MISSING_REQUIRED_FOLLOWER            = 83,
    GARRISON_ERROR_INVALID_TALENT                               = 84,
    GARRISON_ERROR_ALREADY_RESEARCHING_TALENT                   = 85,
    GARRISON_ERROR_FAILED_CONDITION                             = 86,
    GARRISON_ERROR_INVALID_TIER                                 = 87,
    GARRISON_ERROR_INVALID_CLASS                                = 88
};

enum GarrisonFollowerStatus
{
    FOLLOWER_STATUS_FAVORITE    = 0x01,
    FOLLOWER_STATUS_EXHAUSTED   = 0x02,
    FOLLOWER_STATUS_INACTIVE    = 0x04,
    FOLLOWER_STATUS_TROOP       = 0x08,
    FOLLOWER_STATUS_NO_XP_GAIN  = 0x10
};

#define GARRISON_MISSION_DISTRIB_FOLLOWER_COEFF (1.5f)
namespace GarrisonMission
{
    enum State
    {
        Offered = 0,
        InProgress = 1,
        Completed = 2,
        OvermaxRewardPending = 3,
        Reward1Claimed = 4,
        Reward2Claimed = 5,
        Reward3Claimed = 6,
    };

    enum Type
    {
        Combat                      = 3,
        Generic                     = 4,
        Salvage                     = 5,
        Logistics                   = 6,
        Wildlife                    = 7,
        Trading                     = 8,
        Construction                = 9,
        Provision                   = 10,
        Recruitement                = 11,
        Training                    = 12,
        Patrol                      = 13,
        Research                    = 14,
        Defense                     = 15,
        Exploration                 = 16,
        Siege                       = 17,
        Alchemy                     = 18,
        BlackSmithing               = 19,
        Enchanting                  = 20,
        Engineering                 = 21,
        Inscription                 = 22,
        JewelCrafting               = 23,
        LeatherWorking              = 24,
        Tailoring                   = 25,
        Treasure                    = 35,
        PetBattle                   = 36,
        ShipCombat                  = 37,
        ShipOil                     = 38,
        ShipTraining                = 39,
        ShipTreasure                = 40,
        ShipSiegeA                  = 41,
        ShipSiegeH                  = 42,
        ShipBonus                   = 47,
        ShipLegendary               = 48,
        ShipSiegeIHA                = 49,
        ShipSiegeIHH                = 50,
        ZoneSupportAlliance         = 51,
        Invastion                   = 52,
        ArtifactMonk                = 53,
        GenericLegion               = 54,
        TutorialLegion              = 55,
        ZoneSupportHorde            = 57,
        ArtifactShaman              = 58,
        ArtifactDruid               = 59,
        ArtifactMage                = 60,
        ArtifactHunter              = 61,
        ArtifactPaladin             = 63,
        ArtifactWarlock             = 64,
        ArtifactDemonHunter         = 65,
        ArtifactRogue               = 66,
        ArtifactPriest              = 67,
        ArtifactDeathKnight         = 68,
        ArtifactWarrior             = 69,
        ClassHallCampaign           = 70,
        ClassHallGeneric            = 71,
        ClassHallTreasure           = 72,
        ClassHallSpecialReward      = 73,
        ClassHallQuest              = 74,
        ClassHallTreasureDungeon    = 75,
        ClassHallTreasonRaid        = 76,
        BrokenShoreGeneric          = 79,
    };

    enum Flags
    {
        isRare = 0x01,
        isElite = 0x02,
        appliesFatigue = 0x04,
        alwaysFail = 0x08,
        isZoneSupport = 0x10,
    };

    enum BonusRollResults
    {
        Ok    = 0,
        Error = 1
    };

    enum Result
    {
        Success = 0,
        Fail    = 1,
    };

    enum RewardType
    {
        Normal  = 0,
        Bonus   = 1,
    };
}

#endif
