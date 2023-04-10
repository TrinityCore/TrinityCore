/*
 * Copyright 2021 DekkCore
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

#include "BattlePetPackets.h"
#include "Common.h"

#ifndef BattlePet_h__
#define BattlePet_h__

class Field;

#define MAX_PET_BATTLE_SLOTS 3
#define MAX_PET_BATTLE_TEAM 2
#define MAX_PET_BATTLE_ABILITIES 3
#define MAX_PET_BATTLE_ABILITY_TURN 10

#define PET_BATTLE_ENTER_MOVE_SPLINE_ID 0xA42BA70B

#define PET_BATTLE_NULL_ID 0
#define PET_BATTLE_NULL_SLOT -1

#define PET_BATTLE_TEAM_1 0
#define PET_BATTLE_TEAM_2 1
#define PET_BATTLE_PVE_TEAM_ID 1

#define PET_BATTLE_UPDATE_INTERVAL 300

enum BattlePetMisc
{
    BATTLE_PET_CAGE_ITEM_ID     = 82800,

    BATTLE_PET_MAX_LEVEL        = 25,
    MAX_BATTLE_PET_PER_SPECIES  = 3,

};

enum PveBattlePetType
{
    PVE_BATTLE_PET_WILD,
    PVE_BATTLE_PET_TRAINER
};

enum BattlePetQualities
{
    BATTLE_PET_QUALITY_POOR         = 0,
    BATTLE_PET_QUALITY_COMMON       = 1,
    BATTLE_PET_QUALITY_UNCOMMON     = 2,
    BATTLE_PET_QUALITY_RARE         = 3,
    BATTLE_PET_QUALITY_EPIC         = 4,
    BATTLE_PET_QUALITY_LEGENDARY    = 5,
    BATTLE_PET_QUALITY_INHERITED    = 7,
};

enum eBattlePetTypes : int8
{
    BATTLE_PET_TYPE_ALL           = -1,
    BATTLE_PET_TYPE_HUMANOID      = 0,
    BATTLE_PET_TYPE_DRAGONKIN     = 1,
    BATTLE_PET_TYPE_FLYING        = 2,
    BATTLE_PET_TYPE_UNDEAD        = 3,
    BATTLE_PET_TYPE_CRITTER       = 4,
    BATTLE_PET_TYPE_MAGIC         = 5,
    BATTLE_PET_TYPE_ELEMENTAL     = 6,
    BATTLE_PET_TYPE_BEAST         = 7,
    BATTLE_PET_TYPE_AQUATIC       = 8,
    BATTLE_PET_TYPE_MECHANICAL    = 9,
    NUM_BATTLE_PET_TYPES
};

enum eBattlePetFlags
{
    BATTLE_PET_FLAG_FAVORITE        = 0x01,
    BATTLE_PET_FLAG_CAPTURED        = 0x01,
    BATTLE_PET_FLAG_ABILITY_1       = 0x10,
    BATTLE_PET_FLAG_ABILITY_2       = 0x20,
    BATTLE_PET_FLAG_ABILITY_3       = 0x40,
    BATTLE_PET_FLAG_GIFT            = 0x80
};

enum class BattlePetError : uint16
{
    ERR_CANT_HAVE_MORE_PETS_OF_THAT_TYPE    = 3,
    ERR_CANT_HAVE_MORE_PETS                 = 4,
    ERR_PET_TOO_HIGH_LEVEL_TO_UNCAGE        = 7,
};

enum BattlePetState
{
    BATTLE_PET_STATE_Internal_InitialHealth          = 3,
    BATTLE_PET_STATE_Internal_InitialLevel           = 17,
    BATTLE_PET_STATE_Internal_CaptureBoost           = 90,
    BATTLE_PET_STATE_Internal_EffectSucceeded        = 91,
    BATTLE_PET_STATE_Internal_HealthBeforeInstakill  = 145,

    BATTLE_PET_STATE_Is_Dead                         =   1,
    BATTLE_PET_STATE_maxHealthBonus                  =   2,
    BATTLE_PET_STATE_Stat_Kharma                     =   4,
    BATTLE_PET_STATE_Stat_Power                      =  18,
    BATTLE_PET_STATE_Stat_Stamina                    =  19,
    BATTLE_PET_STATE_Stat_Speed                      =  20,
    BATTLE_PET_STATE_Mechanic_IsPoisoned             =  21,
    BATTLE_PET_STATE_Mechanic_IsStunned              =  22,
    BATTLE_PET_STATE_Mod_DamageDealtPercent          =  23,
    BATTLE_PET_STATE_Mod_DamageTakenPercent          =  24,
    BATTLE_PET_STATE_Mod_SpeedPercent                =  25,
    BATTLE_PET_STATE_Ramping_DamageID                =  26,
    BATTLE_PET_STATE_Ramping_DamageUses              =  27,
    BATTLE_PET_STATE_Condition_WasDamagedThisTurn    =  28,
    BATTLE_PET_STATE_untargettable                   =  29,
    BATTLE_PET_STATE_Mechanic_IsUnderground          =  30,
    BATTLE_PET_STATE_Last_HitTaken                   =  31,
    BATTLE_PET_STATE_Last_HitDealt                   =  32,
    BATTLE_PET_STATE_Mechanic_IsFlying               =  33,
    BATTLE_PET_STATE_Mechanic_IsBurning              =  34,
    BATTLE_PET_STATE_turnLock                        =  35,
    BATTLE_PET_STATE_swapOutLock                     =  36,
    BATTLE_PET_STATE_Stat_CritChance                 =  40,
    BATTLE_PET_STATE_Stat_Accuracy                   =  41,
    BATTLE_PET_STATE_Passive_Critter                 =  42,
    BATTLE_PET_STATE_Passive_Beast                   =  43,
    BATTLE_PET_STATE_Passive_Humanoid                =  44,
    BATTLE_PET_STATE_Passive_Flying                  =  45,
    BATTLE_PET_STATE_Passive_Dragon                  =  46,
    BATTLE_PET_STATE_Passive_Elemental               =  47,
    BATTLE_PET_STATE_Passive_Mechanical              =  48,
    BATTLE_PET_STATE_Passive_Magic                   =  49,
    BATTLE_PET_STATE_Passive_Undead                  =  50,
    BATTLE_PET_STATE_Passive_Aquatic                 =  51,
    BATTLE_PET_STATE_Mechanic_IsChilled              =  52,
    BATTLE_PET_STATE_Weather_BurntEarth              =  53,
    BATTLE_PET_STATE_Weather_ArcaneStorm             =  54,
    BATTLE_PET_STATE_Weather_Moonlight               =  55,
    BATTLE_PET_STATE_Weather_Darkness                =  56,
    BATTLE_PET_STATE_Weather_Sandstorm               =  57,
    BATTLE_PET_STATE_Weather_Blizzard                =  58,
    BATTLE_PET_STATE_Weather_Mud                     =  59,
    BATTLE_PET_STATE_Weather_Rain                    =  60,
    BATTLE_PET_STATE_Weather_Sunlight                =  61,
    BATTLE_PET_STATE_Weather_LightningStorm          =  62,
    BATTLE_PET_STATE_Weather_Windy                   =  63,
    BATTLE_PET_STATE_Mechanic_IsWebbed               =  64,
    BATTLE_PET_STATE_Mod_HealingDealtPercent         =  65,
    BATTLE_PET_STATE_Mod_HealingTakenPercent         =  66,
    BATTLE_PET_STATE_Mechanic_IsInvisible            =  67,
    BATTLE_PET_STATE_unkillable                      =  68,
    BATTLE_PET_STATE_Mechanic_IsObject               =  69,
    BATTLE_PET_STATE_Special_Plant                   =  70,
    BATTLE_PET_STATE_Add_FlatDamageTaken             =  71,
    BATTLE_PET_STATE_Add_FlatDamageDealt             =  72,
    BATTLE_PET_STATE_Stat_Dodge                      =  73,
    BATTLE_PET_STATE_Special_BlockedAttackCount      =  74,
    BATTLE_PET_STATE_Special_ObjectRedirectionAuraID =  75,
    BATTLE_PET_STATE_Mechanic_IsBleeding             =  77,
    BATTLE_PET_STATE_Stat_Gender                     =  78,
    BATTLE_PET_STATE_Mechanic_IsBlind                =  82,
    BATTLE_PET_STATE_Cosmetic_Stealthed              =  84,
    BATTLE_PET_STATE_Cosmetic_WaterBubbled           =  85,
    BATTLE_PET_STATE_Mod_PetTypeDamageDealtPercent   =  87,
    BATTLE_PET_STATE_Mod_PetTypeDamageTakenPercent   =  88,
    BATTLE_PET_STATE_Mod_PetType_ID                  =  89,
    BATTLE_PET_STATE_Special_IsCockroach             =  93,
    BATTLE_PET_STATE_swapInLock                      =  98,
    BATTLE_PET_STATE_Mod_MaxHealthPercent            =  99,
    BATTLE_PET_STATE_Clone_Active                    = 100,
    BATTLE_PET_STATE_Clone_PBOID                     = 101,
    BATTLE_PET_STATE_Clone_PetAbility1               = 102,
    BATTLE_PET_STATE_Clone_PetAbility2               = 103,
    BATTLE_PET_STATE_Clone_PetAbility3               = 104,
    BATTLE_PET_STATE_Clone_Health                    = 105,
    BATTLE_PET_STATE_Clone_MaxHealth                 = 106,
    BATTLE_PET_STATE_Clone_LastAbilityID             = 107,
    BATTLE_PET_STATE_Clone_LastAbilityTurn           = 108,
    BATTLE_PET_STATE_Special_IsCharging              = 113,
    BATTLE_PET_STATE_Special_IsRecovering            = 114,
    BATTLE_PET_STATE_Clone_CloneAbilityID            = 117,
    BATTLE_PET_STATE_Clone_CloneAuraID               = 118,
    BATTLE_PET_STATE_DarkSimulacrum_AbilityID        = 119,
    BATTLE_PET_STATE_Special_ConsumedCorpse          = 120,
    BATTLE_PET_STATE_Ramping_PBOID                   = 121,
    BATTLE_PET_STATE_reflecting                      = 122,
    BATTLE_PET_STATE_Special_BlockedFriendlyMode     = 123,
    BATTLE_PET_STATE_Special_TypeOverride            = 124,
    BATTLE_PET_STATE_Mechanic_IsWall                 = 126,
    BATTLE_PET_STATE_Condition_DidDamageThisRound    = 127,
    BATTLE_PET_STATE_Cosmetic_FlyTier                = 128,
    BATTLE_PET_STATE_Cosmetic_FetishMask             = 129,
    BATTLE_PET_STATE_Mechanic_IsBomb                 = 136,
    BATTLE_PET_STATE_Special_IsCleansing             = 141,
    BATTLE_PET_STATE_Cosmetic_Bigglesworth           = 144,
    BATTLE_PET_STATE_resilient                       = 149,
    BATTLE_PET_STATE_Passive_Elite                   = 153,
    BATTLE_PET_STATE_Cosmetic_Chaos                  = 158,
    BATTLE_PET_STATE_Passive_Boss                    = 162,
    BATTLE_PET_STATE_Cosmetic_TreasureGoblin         = 176,
    BATTLE_PET_STATE_Ignore_Damage_Below_Threshold   = 191,
    BATTLE_PET_STATE_Cosmetic_Spectral_Blue          = 196,
    BATTLE_PET_STATE_Special_Egg                     = 199,
    BATTLE_PET_STATE_Ignore_Damage_Above_Threshold   = 200,
    NUM_BATTLE_PET_STATES
};

class BattlePet
{
    public:
        virtual ~BattlePet() = default;

        void Load(Field* fields);
        void CloneFrom(std::shared_ptr<BattlePet> & p_BattlePet);
        void Save(CharacterDatabaseTransaction& trans);

        ObjectGuid::LowType AddToPlayer(Player* player);
        void AddToPlayer(Player* player, CharacterDatabaseTransaction& trans);
        void Remove(Player* player);
        void UpdateAbilities();
        void UpdateStats();
        

        uint32 AccountID;                              ///< Owner account ID
        ObjectGuid JournalID;                              ///< As companion (db/journal id)
        int32 Slot;                                    ///< Battle slot
        std::string Name;                                   ///< Name
        uint32 NameTimeStamp;                          ///< Name timestamp
        uint32 Species;                                ///< Species ID
        uint32 DisplayModelID;                         ///< Display id (no real usage, client can deduce it for some species)
        uint32 Breed;                                  ///< Breed quality (factor for some states)
        uint32 Quality;                                ///< Pet quality (factor for some states)
        uint32 Abilities[MAX_PET_BATTLE_ABILITIES];    ///< Available abilities
        int32 Health;                                  ///< Current health
        uint32 Level;                                  ///< Pet level
        uint32 XP;                                     ///< Pet XP
        uint32 Flags;                                  ///< Flags
        int32 InfoPower;                               ///< Info power (need UpdateStats calls)
        int32 InfoMaxHealth;                           ///< Info max health (need UpdateStats calls)
        int32 InfoSpeed;                               ///< Info speed (need UpdateStats calls)
        int32 InfoGender;                              ///< Info gender (need UpdateStats calls)
        std::string DeclinedNames[MAX_DECLINED_NAME_CASES]; ///< Declined names
        bool needSave = false;
        bool needDelete = false;
};

#endif // BattlePet_h__
