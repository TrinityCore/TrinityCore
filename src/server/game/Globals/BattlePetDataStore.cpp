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

#include "BattlePetDataStore.h"
#include "Containers.h"

void BattlePetDataStore::Initialize()
{
    if (QueryResult result = LoginDatabase.Query("SELECT MAX(guid) FROM battle_pets"))
        sObjectMgr->GetGenerator<HighGuid::BattlePet>().Set((*result)[0].GetUInt64() + 1);

    for (BattlePetBreedStateEntry const* battlePetBreedState : sBattlePetBreedStateStore)
        _battlePetBreedStates[battlePetBreedState->BattlePetBreedID][BattlePetState(battlePetBreedState->BattlePetStateID)] = battlePetBreedState->Value;

    for (BattlePetSpeciesStateEntry const* battlePetSpeciesState : sBattlePetSpeciesStateStore)
        _battlePetSpeciesStates[battlePetSpeciesState->BattlePetSpeciesID][BattlePetState(battlePetSpeciesState->BattlePetStateID)] = battlePetSpeciesState->Value;

    LoadAvailablePetBreeds();
    LoadDefaultPetQualities();
}

void BattlePetDataStore::LoadAvailablePetBreeds()
{
    QueryResult result = WorldDatabase.Query("SELECT speciesId, breedId FROM battle_pet_breeds");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 battle pet breeds. DB table `battle_pet_breeds` is empty.");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();
        uint32 speciesId = fields[0].GetUInt32();
        uint16 breedId = fields[1].GetUInt16();

        if (!sBattlePetSpeciesStore.LookupEntry(speciesId))
        {
            TC_LOG_ERROR("sql.sql", "Non-existing BattlePetSpecies.db2 entry %u was referenced in `battle_pet_breeds` by row (%u, %u).", speciesId, speciesId, breedId);
            continue;
        }

        // TODO: verify breed id (3 - 12 (male) or 3 - 22 (male and female)) if needed

        _availableBreedsPerSpecies[speciesId].insert(breedId);
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u battle pet breeds.", count);
}

void BattlePetDataStore::LoadDefaultPetQualities()
{
    QueryResult result = WorldDatabase.Query("SELECT speciesId, quality FROM battle_pet_quality");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 battle pet qualities. DB table `battle_pet_quality` is empty.");
        return;
    }

    do
    {
        Field* fields = result->Fetch();
        uint32 speciesId = fields[0].GetUInt32();
        uint8 quality = fields[1].GetUInt8();

        if (!sBattlePetSpeciesStore.LookupEntry(speciesId))
        {
            TC_LOG_ERROR("sql.sql", "Non-existing BattlePetSpecies.db2 entry %u was referenced in `battle_pet_quality` by row (%u, %u).", speciesId, speciesId, quality);
            continue;
        }

        // TODO: verify quality (0 - 3 for player pets or 0 - 5 for both player and tamer pets) if needed

        _defaultQualityPerSpecies[speciesId] = quality;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u battle pet qualities.", uint32(_defaultQualityPerSpecies.size()));
}

uint16 BattlePetDataStore::RollPetBreed(uint32 species) const
{
    auto itr = _availableBreedsPerSpecies.find(species);
    if (itr == _availableBreedsPerSpecies.end())
        return 3; // default B/B

    return Trinity::Containers::SelectRandomContainerElement(itr->second);
}

uint8 BattlePetDataStore::GetDefaultPetQuality(uint32 species) const
{
    auto itr = _defaultQualityPerSpecies.find(species);
    if (itr == _defaultQualityPerSpecies.end())
        return 0; // default poor

    return itr->second;
}

BattlePetStateMap* BattlePetDataStore::GetPetBreedStats(uint16 BreedID)
{
    auto breedState = _battlePetBreedStates.find(BreedID);
    if (breedState == _battlePetBreedStates.end()) // non existing breed id
        return nullptr;

    return &breedState->second;
}

BattlePetStateMap* BattlePetDataStore::GetPetSpeciesStats(uint16 SpeciesID)
{
    auto speciesState = _battlePetSpeciesStates.find(SpeciesID);
    if (speciesState == _battlePetSpeciesStates.end())
        return nullptr;

    return &speciesState->second;
}

BattlePetDataStore* BattlePetDataStore::Instance()
{
    static BattlePetDataStore instance;
    return &instance;
}
