/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef BattlePetDataStore_h__
#define BattlePetDataStore_h__

#include "Define.h"

enum BattlePetMisc
{
    MAX_PET_BATTLE_SLOTS            = 3,
    MAX_BATTLE_PETS_PER_SPECIES     = 3,
    BATTLE_PET_CAGE_ITEM_ID         = 82800,
    DEFAULT_SUMMON_BATTLE_PET_SPELL = 118301
};

// 6.2.4
enum FlagsControlType
{
    FLAGS_CONTROL_TYPE_APPLY        = 1,
    FLAGS_CONTROL_TYPE_REMOVE       = 2
};

// 6.2.4
enum BattlePetError
{
    BATTLEPETRESULT_CANT_HAVE_MORE_PETS_OF_THAT_TYPE = 3,
    BATTLEPETRESULT_CANT_HAVE_MORE_PETS              = 4,
    BATTLEPETRESULT_TOO_HIGH_LEVEL_TO_UNCAGE         = 7,

    // TODO: find correct values if possible and needed (also wrong order)
    BATTLEPETRESULT_DUPLICATE_CONVERTED_PET,
    BATTLEPETRESULT_NEED_TO_UNLOCK,
    BATTLEPETRESULT_BAD_PARAM,
    BATTLEPETRESULT_LOCKED_PET_ALREADY_EXISTS,
    BATTLEPETRESULT_OK,
    BATTLEPETRESULT_UNCAPTURABLE,
    BATTLEPETRESULT_CANT_INVALID_CHARACTER_GUID
};

// taken from BattlePetState.db2 - it seems to store some initial values for battle pets
// there are only values used in BattlePetSpeciesState.db2 and BattlePetBreedState.db2
// TODO: expand this enum if needed
enum BattlePetState
{
    STATE_MAX_HEALTH_BONUS          = 2,
    STATE_INTERNAL_INITIAL_LEVEL    = 17,
    STATE_STAT_POWER                = 18,
    STATE_STAT_STAMINA              = 19,
    STATE_STAT_SPEED                = 20,
    STATE_MOD_DAMAGE_DEALT_PERCENT  = 23,
    STATE_GENDER                    = 78, // 1 - male, 2 - female
    STATE_COSMETIC_WATER_BUBBLED    = 85,
    STATE_SPECIAL_IS_COCKROACH      = 93,
    STATE_COSMETIC_FLY_TIER         = 128,
    STATE_COSMETIC_BIGGLESWORTH     = 144,
    STATE_PASSIVE_ELITE             = 153,
    STATE_PASSIVE_BOSS              = 162,
    STATE_COSMETIC_TREASURE_GOBLIN  = 176,
    // these are not in BattlePetState.db2 but are used in BattlePetSpeciesState.db2
    STATE_START_WITH_BUFF           = 183,
    STATE_START_WITH_BUFF_2         = 184,
    //
    STATE_COSMETIC_SPECTRAL_BLUE    = 196
};

typedef std::unordered_map<BattlePetState /*state*/, int32 /*value*/, std::hash<std::underlying_type<BattlePetState>::type>> BattlePetStateMap;

class TC_GAME_API BattlePetDataStore
{
public:
    void Initialize();

    uint16 RollPetBreed(uint32 species) const;
    uint8 GetDefaultPetQuality(uint32 species) const;

    BattlePetStateMap* GetPetBreedStats(uint16 BreedID);
    BattlePetStateMap* GetPetSpeciesStats(uint16 SpeciesID);

    static BattlePetDataStore* Instance();

private:
    void LoadAvailablePetBreeds();
    void LoadDefaultPetQualities();

    // hash no longer required in C++14
    std::unordered_map<uint16 /*BreedID*/, BattlePetStateMap> _battlePetBreedStates;
    std::unordered_map<uint32 /*SpeciesID*/, BattlePetStateMap> _battlePetSpeciesStates;
    std::unordered_map<uint32 /*SpeciesID*/, std::unordered_set<uint8 /*breed*/>> _availableBreedsPerSpecies;
    std::unordered_map<uint32 /*SpeciesID*/, uint8 /*quality*/> _defaultQualityPerSpecies;
};

#define sBattlePetDataStore BattlePetDataStore::Instance()

#endif // BattlePetDataStore_h__
