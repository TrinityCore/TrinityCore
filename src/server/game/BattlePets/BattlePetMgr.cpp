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

#include "BattlePetMgr.h"
#include "DB2Stores.h"
#include "Containers.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "Item.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "WorldSession.h"

void BattlePetMgr::BattlePet::CalculateStats()
{
    float health = 0.0f;
    float power = 0.0f;
    float speed = 0.0f;

    // get base breed stats
    auto breedState = _battlePetBreedStates.find(PacketInfo.Breed);
    if (breedState == _battlePetBreedStates.end()) // non existing breed id
        return;

    health = breedState->second[STATE_STAT_STAMINA];
    power = breedState->second[STATE_STAT_POWER];
    speed = breedState->second[STATE_STAT_SPEED];

    // modify stats depending on species - not all pets have this
    auto speciesState = _battlePetSpeciesStates.find(PacketInfo.Species);
    if (speciesState != _battlePetSpeciesStates.end())
    {
        health += speciesState->second[STATE_STAT_STAMINA];
        power += speciesState->second[STATE_STAT_POWER];
        speed += speciesState->second[STATE_STAT_SPEED];
    }

    // modify stats by quality
    for (BattlePetBreedQualityEntry const* battlePetBreedQuality : sBattlePetBreedQualityStore)
    {
        if (battlePetBreedQuality->QualityEnum == PacketInfo.Quality)
        {
            health *= battlePetBreedQuality->StateMultiplier;
            power *= battlePetBreedQuality->StateMultiplier;
            speed *= battlePetBreedQuality->StateMultiplier;
            break;
        }
        // TOOD: add check if pet has existing quality
    }

    // scale stats depending on level
    health *= PacketInfo.Level;
    power *= PacketInfo.Level;
    speed *= PacketInfo.Level;

    // set stats
    // round, ceil or floor? verify this
    PacketInfo.MaxHealth = uint32((round(health / 20) + 100));
    PacketInfo.Power = uint32(round(power / 100));
    PacketInfo.Speed = uint32(round(speed / 100));
}

std::unordered_map<uint16 /*BreedID*/, std::unordered_map<BattlePetState /*state*/, int32 /*value*/, std::hash<std::underlying_type<BattlePetState>::type> >> BattlePetMgr::_battlePetBreedStates;
std::unordered_map<uint32 /*SpeciesID*/, std::unordered_map<BattlePetState /*state*/, int32 /*value*/, std::hash<std::underlying_type<BattlePetState>::type> >> BattlePetMgr::_battlePetSpeciesStates;
std::unordered_map<uint32 /*SpeciesID*/, std::unordered_set<uint8 /*breed*/>> BattlePetMgr::_availableBreedsPerSpecies;
std::unordered_map<uint32 /*SpeciesID*/, uint8 /*quality*/> BattlePetMgr::_defaultQualityPerSpecies;

void BattlePetMgr::Initialize()
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

void BattlePetMgr::LoadAvailablePetBreeds()
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

void BattlePetMgr::LoadDefaultPetQualities()
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

uint16 BattlePetMgr::RollPetBreed(uint32 species)
{
    auto itr = _availableBreedsPerSpecies.find(species);
    if (itr == _availableBreedsPerSpecies.end())
        return 3; // default B/B

    return Trinity::Containers::SelectRandomContainerElement(itr->second);
}

uint8 BattlePetMgr::GetDefaultPetQuality(uint32 species)
{
    auto itr = _defaultQualityPerSpecies.find(species);
    if (itr == _defaultQualityPerSpecies.end())
        return 0; // default poor

    return itr->second;
}

BattlePetMgr::BattlePetMgr(WorldSession* owner)
{
    _owner = owner;
    for (uint8 i = 0; i < MAX_PET_BATTLE_SLOTS; ++i)
    {
        WorldPackets::BattlePet::BattlePetSlot slot;
        slot.Index = i;
        _slots.push_back(slot);
    }
}

void BattlePetMgr::LoadFromDB(PreparedQueryResult pets, PreparedQueryResult slots)
{
    if (pets)
    {
        do
        {
            Field* fields = pets->Fetch();
            uint32 species = fields[1].GetUInt32();

            if (BattlePetSpeciesEntry const* speciesEntry = sBattlePetSpeciesStore.LookupEntry(species))
            {
                if (GetPetCount(species) >= MAX_BATTLE_PETS_PER_SPECIES)
                {
                    TC_LOG_ERROR("misc", "Battlenet account with id %u has more than 3 battle pets of species %u", _owner->GetBattlenetAccountId(), species);
                    continue;
                }

                BattlePet pet;
                pet.PacketInfo.Guid = ObjectGuid::Create<HighGuid::BattlePet>(fields[0].GetUInt64());
                pet.PacketInfo.Species = species;
                pet.PacketInfo.Breed = fields[2].GetUInt16();
                pet.PacketInfo.Level = fields[3].GetUInt16();
                pet.PacketInfo.Exp = fields[4].GetUInt16();
                pet.PacketInfo.Health = fields[5].GetUInt32();
                pet.PacketInfo.Quality = fields[6].GetUInt8();
                pet.PacketInfo.Flags = fields[7].GetUInt16();
                pet.PacketInfo.Name = fields[8].GetString();
                pet.PacketInfo.CreatureID = speciesEntry->CreatureID;
                pet.SaveInfo = BATTLE_PET_UNCHANGED;
                pet.CalculateStats();
                _pets[pet.PacketInfo.Guid.GetCounter()] = pet;
            }
        } while (pets->NextRow());
    }

    if (slots)
    {
        uint8 i = 0; // slots->GetRowCount() should equal MAX_BATTLE_PET_SLOTS

        do
        {
            Field* fields = slots->Fetch();
            _slots[i].Index = fields[0].GetUInt8();
            auto itr = _pets.find(fields[1].GetUInt64());
            if (itr != _pets.end())
                _slots[i].Pet = itr->second.PacketInfo;
            _slots[i].Locked = fields[2].GetBool();
            i++;
        } while (slots->NextRow());
    }
}

void BattlePetMgr::SaveToDB(LoginDatabaseTransaction& trans)
{
    LoginDatabasePreparedStatement* stmt = nullptr;

    for (auto itr = _pets.begin(); itr != _pets.end();)
    {
        switch (itr->second.SaveInfo)
        {
            case BATTLE_PET_NEW:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BATTLE_PETS);
                stmt->setUInt64(0, itr->first);
                stmt->setUInt32(1, _owner->GetBattlenetAccountId());
                stmt->setUInt32(2, itr->second.PacketInfo.Species);
                stmt->setUInt16(3, itr->second.PacketInfo.Breed);
                stmt->setUInt16(4, itr->second.PacketInfo.Level);
                stmt->setUInt16(5, itr->second.PacketInfo.Exp);
                stmt->setUInt32(6, itr->second.PacketInfo.Health);
                stmt->setUInt8(7, itr->second.PacketInfo.Quality);
                stmt->setUInt16(8, itr->second.PacketInfo.Flags);
                stmt->setString(9, itr->second.PacketInfo.Name);
                trans->Append(stmt);
                itr->second.SaveInfo = BATTLE_PET_UNCHANGED;
                ++itr;
                break;
            case BATTLE_PET_CHANGED:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BATTLE_PETS);
                stmt->setUInt16(0, itr->second.PacketInfo.Level);
                stmt->setUInt16(1, itr->second.PacketInfo.Exp);
                stmt->setUInt32(2, itr->second.PacketInfo.Health);
                stmt->setUInt8(3, itr->second.PacketInfo.Quality);
                stmt->setUInt16(4, itr->second.PacketInfo.Flags);
                stmt->setString(5, itr->second.PacketInfo.Name);
                stmt->setUInt32(6, _owner->GetBattlenetAccountId());
                stmt->setUInt64(7, itr->first);
                trans->Append(stmt);
                itr->second.SaveInfo = BATTLE_PET_UNCHANGED;
                ++itr;
                break;
            case BATTLE_PET_REMOVED:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_BATTLE_PETS);
                stmt->setUInt32(0, _owner->GetBattlenetAccountId());
                stmt->setUInt64(1, itr->first);
                trans->Append(stmt);
                itr = _pets.erase(itr);
                break;
            default:
                ++itr;
                break;
        }
    }

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_BATTLE_PET_SLOTS);
    stmt->setUInt32(0, _owner->GetBattlenetAccountId());
    trans->Append(stmt);

    for (WorldPackets::BattlePet::BattlePetSlot const& slot : _slots)
    {
        stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BATTLE_PET_SLOTS);
        stmt->setUInt8(0, slot.Index);
        stmt->setUInt32(1, _owner->GetBattlenetAccountId());
        stmt->setUInt64(2, slot.Pet.Guid.GetCounter());
        stmt->setBool(3, slot.Locked);
        trans->Append(stmt);
    }
}

BattlePetMgr::BattlePet* BattlePetMgr::GetPet(ObjectGuid guid)
{
    return Trinity::Containers::MapGetValuePtr(_pets, guid.GetCounter());
}

void BattlePetMgr::AddPet(uint32 species, uint32 creatureId, uint16 breed, uint8 quality, uint16 level /*= 1*/)
{
    BattlePetSpeciesEntry const* battlePetSpecies = sBattlePetSpeciesStore.LookupEntry(species);
    if (!battlePetSpecies) // should never happen
        return;

    BattlePet pet;
    pet.PacketInfo.Guid = ObjectGuid::Create<HighGuid::BattlePet>(sObjectMgr->GetGenerator<HighGuid::BattlePet>().Generate());
    pet.PacketInfo.Species = species;
    pet.PacketInfo.CreatureID = creatureId;
    pet.PacketInfo.Level = level;
    pet.PacketInfo.Exp = 0;
    pet.PacketInfo.Flags = 0;
    pet.PacketInfo.Breed = breed;
    pet.PacketInfo.Quality = quality;
    pet.PacketInfo.Name = "";
    pet.CalculateStats();
    pet.PacketInfo.Health = pet.PacketInfo.MaxHealth;
    pet.SaveInfo = BATTLE_PET_NEW;

    _pets[pet.PacketInfo.Guid.GetCounter()] = pet;

    std::vector<std::reference_wrapper<BattlePet>> updates;
    updates.push_back(std::ref(pet));
    SendUpdates(std::move(updates), true);

    _owner->GetPlayer()->UpdateCriteria(CRITERIA_TYPE_OWN_BATTLE_PET, species);
}

void BattlePetMgr::RemovePet(ObjectGuid guid)
{
    BattlePet* pet = GetPet(guid);
    if (!pet)
        return;

    pet->SaveInfo = BATTLE_PET_REMOVED;

    // spell is not unlearned on retail
    /*if (GetPetCount(pet->PacketInfo.Species) == 0)
        if (BattlePetSpeciesEntry const* speciesEntry = sBattlePetSpeciesStore.LookupEntry(pet->PacketInfo.Species))
            _owner->GetPlayer()->RemoveSpell(speciesEntry->SummonSpellID);*/
}

uint8 BattlePetMgr::GetPetCount(uint32 species) const
{
    return uint8(std::count_if(_pets.begin(), _pets.end(), [species](std::pair<uint64 const, BattlePet> const& pet)
    {
        return pet.second.PacketInfo.Species == species && pet.second.SaveInfo != BATTLE_PET_REMOVED;
    }));
}

void BattlePetMgr::UnlockSlot(uint8 slot)
{
    if (!_slots[slot].Locked)
        return;

    _slots[slot].Locked = false;

    WorldPackets::BattlePet::PetBattleSlotUpdates updates;
    updates.Slots.push_back(_slots[slot]);
    updates.AutoSlotted = false; // what's this?
    updates.NewSlot = true; // causes the "new slot unlocked" bubble to appear
    _owner->SendPacket(updates.Write());
}

uint16 BattlePetMgr::GetMaxPetLevel() const
{
    uint16 level = 0;
    for (auto& pet : _pets)
        if (pet.second.SaveInfo != BATTLE_PET_REMOVED)
            level = std::max(level, pet.second.PacketInfo.Level);

    return level;
}

void BattlePetMgr::CageBattlePet(ObjectGuid guid)
{
    BattlePet* pet = GetPet(guid);
    if (!pet)
        return;

    ItemPosCountVec dest;

    if (_owner->GetPlayer()->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, BATTLE_PET_CAGE_ITEM_ID, 1) != EQUIP_ERR_OK)
        return;

    Item* item = _owner->GetPlayer()->StoreNewItem(dest, BATTLE_PET_CAGE_ITEM_ID, true);
    if (!item)
        return;

    item->SetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID, pet->PacketInfo.Species);
    item->SetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA, pet->PacketInfo.Breed | (pet->PacketInfo.Quality << 24));
    item->SetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL, pet->PacketInfo.Level);
    item->SetModifier(ITEM_MODIFIER_BATTLE_PET_DISPLAY_ID, pet->PacketInfo.CreatureID);

    // FIXME: "You create: ." - item name missing in chat
    _owner->GetPlayer()->SendNewItem(item, 1, true, false);

    RemovePet(guid);

    WorldPackets::BattlePet::BattlePetDeleted deletePet;
    deletePet.PetGuid = guid;
    _owner->SendPacket(deletePet.Write());
}

void BattlePetMgr::HealBattlePetsPct(uint8 pct)
{
    // TODO: After each Pet Battle, any injured companion will automatically
    // regain 50 % of the damage that was taken during combat
    std::vector<std::reference_wrapper<BattlePet>> updates;

    for (auto& pet : _pets)
        if (pet.second.PacketInfo.Health != pet.second.PacketInfo.MaxHealth)
        {
            pet.second.PacketInfo.Health += CalculatePct(pet.second.PacketInfo.MaxHealth, pct);
            // don't allow Health to be greater than MaxHealth
            pet.second.PacketInfo.Health = std::min(pet.second.PacketInfo.Health, pet.second.PacketInfo.MaxHealth);
            if (pet.second.SaveInfo != BATTLE_PET_NEW)
                pet.second.SaveInfo = BATTLE_PET_CHANGED;
            updates.push_back(std::ref(pet.second));
        }

    SendUpdates(std::move(updates), false);
}

void BattlePetMgr::SummonPet(ObjectGuid guid)
{
    BattlePet* pet = GetPet(guid);
    if (!pet)
        return;

    BattlePetSpeciesEntry const* speciesEntry = sBattlePetSpeciesStore.LookupEntry(pet->PacketInfo.Species);
    if (!speciesEntry)
        return;

    // TODO: set proper CreatureID for spell DEFAULT_SUMMON_BATTLE_PET_SPELL (default EffectMiscValueA is 40721 - Murkimus the Gladiator)
    _owner->GetPlayer()->SetSummonedBattlePetGUID(guid);
    _owner->GetPlayer()->CastSpell(_owner->GetPlayer(), speciesEntry->SummonSpellID ? speciesEntry->SummonSpellID : uint32(DEFAULT_SUMMON_BATTLE_PET_SPELL));

    // TODO: set pet level, quality... update fields
}

void BattlePetMgr::DismissPet()
{
    Player* ownerPlayer = _owner->GetPlayer();
    Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*ownerPlayer, ownerPlayer->GetCritterGUID());
    if (pet && *ownerPlayer->m_activePlayerData->SummonedBattlePetGUID == pet->GetBattlePetCompanionGUID())
    {
        pet->DespawnOrUnsummon();
        ownerPlayer->SetSummonedBattlePetGUID(ObjectGuid::Empty);
    }
}

void BattlePetMgr::SendJournal()
{
    WorldPackets::BattlePet::BattlePetJournal battlePetJournal;
    battlePetJournal.Trap = _trapLevel;

    for (auto& pet : _pets)
        if (pet.second.SaveInfo != BATTLE_PET_REMOVED)
            battlePetJournal.Pets.push_back(std::ref(pet.second.PacketInfo));

    battlePetJournal.Slots.reserve(_slots.size());
    std::transform(_slots.begin(), _slots.end(), std::back_inserter(battlePetJournal.Slots), [](WorldPackets::BattlePet::BattlePetSlot& slot) { return std::ref(slot); });
    _owner->SendPacket(battlePetJournal.Write());
}

void BattlePetMgr::SendUpdates(std::vector<std::reference_wrapper<BattlePet>> pets, bool petAdded)
{
    WorldPackets::BattlePet::BattlePetUpdates updates;
    for (BattlePet& pet : pets)
        updates.Pets.push_back(std::ref(pet.PacketInfo));

    updates.PetAdded = petAdded;
    _owner->SendPacket(updates.Write());
}

void BattlePetMgr::SendError(BattlePetError error, uint32 creatureId)
{
    WorldPackets::BattlePet::BattlePetError battlePetError;
    battlePetError.Result = error;
    battlePetError.CreatureID = creatureId;
    _owner->SendPacket(battlePetError.Write());
}
