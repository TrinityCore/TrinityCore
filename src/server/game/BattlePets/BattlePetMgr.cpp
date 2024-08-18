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
#include "GameTables.h"
#include "GameTime.h"
#include "Item.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Realm.h"
#include "Util.h"
#include "World.h"
#include "WorldSession.h"

namespace BattlePets
{
namespace
{
std::unordered_map<uint16 /*BreedID*/, std::unordered_map<BattlePetState /*state*/, int32 /*value*/, std::hash<std::underlying_type<BattlePetState>::type> >> _battlePetBreedStates;
std::unordered_map<uint32 /*SpeciesID*/, std::unordered_map<BattlePetState /*state*/, int32 /*value*/, std::hash<std::underlying_type<BattlePetState>::type> >> _battlePetSpeciesStates;
std::unordered_map<uint32 /*CreatureID*/, BattlePetSpeciesEntry const*> _battlePetSpeciesByCreature;
std::unordered_map<uint32 /*SpellID*/, BattlePetSpeciesEntry const*> _battlePetSpeciesBySpell;
std::unordered_map<uint32 /*SpeciesID*/, std::unordered_set<uint8 /*breed*/>> _availableBreedsPerSpecies;
std::unordered_map<uint32 /*SpeciesID*/, uint8 /*quality*/> _defaultQualityPerSpecies;
}

void BattlePet::CalculateStats()
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

void BattlePetMgr::Initialize()
{
    if (QueryResult result = LoginDatabase.Query("SELECT MAX(guid) FROM battle_pets"))
        sObjectMgr->GetGenerator<HighGuid::BattlePet>().Set((*result)[0].GetUInt64() + 1);

    for (BattlePetSpeciesEntry const* battlePetSpecies : sBattlePetSpeciesStore)
        if (uint32 creatureId = battlePetSpecies->CreatureID)
            _battlePetSpeciesByCreature[creatureId] = battlePetSpecies;

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
            TC_LOG_ERROR("sql.sql", "Non-existing BattlePetSpecies.db2 entry {} was referenced in `battle_pet_breeds` by row ({}, {}).", speciesId, speciesId, breedId);
            continue;
        }

        // TODO: verify breed id (3 - 12 (male) or 3 - 22 (male and female)) if needed

        _availableBreedsPerSpecies[speciesId].insert(breedId);
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} battle pet breeds.", count);
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

        BattlePetSpeciesEntry const* battlePetSpecies = sBattlePetSpeciesStore.LookupEntry(speciesId);
        if (!battlePetSpecies)
        {
            TC_LOG_ERROR("sql.sql", "Non-existing BattlePetSpecies.db2 entry {} was referenced in `battle_pet_quality` by row ({}, {}).", speciesId, speciesId, quality);
            continue;
        }

        if (quality >= AsUnderlyingType(BattlePetBreedQuality::Count))
        {
            TC_LOG_ERROR("sql.sql", "BattlePetSpecies.db2 entry {} was referenced in `battle_pet_quality` with non-existing quality {}).", speciesId, quality);
            continue;
        }

        if (battlePetSpecies->GetFlags().HasFlag(BattlePetSpeciesFlags::WellKnown) && quality > AsUnderlyingType(BattlePetBreedQuality::Rare))
        {
            TC_LOG_ERROR("sql.sql", "Learnable BattlePetSpecies.db2 entry {} was referenced in `battle_pet_quality` with invalid quality {}. Maximum allowed quality is BattlePetBreedQuality::Rare.", speciesId, quality);
            continue;
        }

        _defaultQualityPerSpecies[speciesId] = quality;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} battle pet qualities.", uint32(_defaultQualityPerSpecies.size()));
}

void BattlePetMgr::AddBattlePetSpeciesBySpell(uint32 spellId, BattlePetSpeciesEntry const* speciesEntry)
{
    _battlePetSpeciesBySpell[spellId] = speciesEntry;
}

BattlePetSpeciesEntry const* BattlePetMgr::GetBattlePetSpeciesByCreature(uint32 creatureId)
{
    return Trinity::Containers::MapGetValuePtr(_battlePetSpeciesByCreature, creatureId);
}

BattlePetSpeciesEntry const* BattlePetMgr::GetBattlePetSpeciesBySpell(uint32 spellId)
{
    return Trinity::Containers::MapGetValuePtr(_battlePetSpeciesBySpell, spellId);
}

uint16 BattlePetMgr::RollPetBreed(uint32 species)
{
    auto itr = _availableBreedsPerSpecies.find(species);
    if (itr == _availableBreedsPerSpecies.end())
        return 3; // default B/B

    return Trinity::Containers::SelectRandomContainerElement(itr->second);
}

BattlePetBreedQuality BattlePetMgr::GetDefaultPetQuality(uint32 species)
{
    auto itr = _defaultQualityPerSpecies.find(species);
    if (itr == _defaultQualityPerSpecies.end())
        return BattlePetBreedQuality::Poor; // Default

    return BattlePetBreedQuality(itr->second);
}

uint32 BattlePetMgr::SelectPetDisplay(BattlePetSpeciesEntry const* speciesEntry)
{
    if (CreatureTemplate const* creatureTemplate = sObjectMgr->GetCreatureTemplate(speciesEntry->CreatureID))
        if (!speciesEntry->GetFlags().HasFlag(BattlePetSpeciesFlags::RandomDisplay))
            if (CreatureModel const* creatureModel = creatureTemplate->GetRandomValidModel())
                return creatureModel->CreatureDisplayID;

    return 0;
}

BattlePetMgr::BattlePetMgr(WorldSession* owner)
{
    _owner = owner;
    for (uint8 i = 0; i < AsUnderlyingType(BattlePetSlot::Count); ++i)
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
            ObjectGuid ownerGuid = !fields[11].IsNull() ? ObjectGuid::Create<HighGuid::Player>(fields[11].GetInt64()) : ObjectGuid::Empty;

            if (BattlePetSpeciesEntry const* speciesEntry = sBattlePetSpeciesStore.LookupEntry(species))
            {
                if (speciesEntry->GetFlags().HasFlag(BattlePetSpeciesFlags::NotAccountWide))
                {
                    if (ownerGuid.IsEmpty())
                    {
                        TC_LOG_ERROR("misc", "Battlenet account with id {} has battle pet of species {} with BattlePetSpeciesFlags::NotAccountWide but no owner", _owner->GetBattlenetAccountId(), species);
                        continue;
                    }
                }
                else
                {
                    if (!ownerGuid.IsEmpty())
                    {
                        TC_LOG_ERROR("misc", "Battlenet account with id {} has battle pet of species {} without BattlePetSpeciesFlags::NotAccountWide but with owner", _owner->GetBattlenetAccountId(), species);
                        continue;
                    }
                }

                if (HasMaxPetCount(speciesEntry, ownerGuid))
                {
                    if (ownerGuid.IsEmpty())
                        TC_LOG_ERROR("misc", "Battlenet account with id {} has more than maximum battle pets of species {}", _owner->GetBattlenetAccountId(), species);
                    else
                        TC_LOG_ERROR("misc", "Battlenet account with id {} has more than maximum battle pets of species {} for player {}", _owner->GetBattlenetAccountId(), species, ownerGuid.ToString());

                    continue;
                }

                BattlePet pet;
                pet.PacketInfo.Guid = ObjectGuid::Create<HighGuid::BattlePet>(fields[0].GetUInt64());
                pet.PacketInfo.Species = species;
                pet.PacketInfo.Breed = fields[2].GetUInt16();
                pet.PacketInfo.DisplayID = fields[3].GetUInt32();
                pet.PacketInfo.Level = fields[4].GetUInt16();
                pet.PacketInfo.Exp = fields[5].GetUInt16();
                pet.PacketInfo.Health = fields[6].GetUInt32();
                pet.PacketInfo.Quality = fields[7].GetUInt8();
                pet.PacketInfo.Flags = fields[8].GetUInt16();
                pet.PacketInfo.Name = fields[9].GetString();
                pet.NameTimestamp = fields[10].GetInt64();
                pet.PacketInfo.CreatureID = speciesEntry->CreatureID;

                if (!fields[12].IsNull())
                {
                    pet.DeclinedName = std::make_unique<DeclinedName>();
                    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
                        pet.DeclinedName->name[i] = fields[12 + i].GetString();
                }

                if (!ownerGuid.IsEmpty())
                {
                    pet.PacketInfo.OwnerInfo.emplace();
                    pet.PacketInfo.OwnerInfo->Guid = ownerGuid;
                    pet.PacketInfo.OwnerInfo->PlayerVirtualRealm = pet.PacketInfo.OwnerInfo->PlayerNativeRealm = GetVirtualRealmAddress();
                }

                pet.SaveInfo = BATTLE_PET_UNCHANGED;
                pet.CalculateStats();
                _pets[pet.PacketInfo.Guid.GetCounter()] = std::move(pet);
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

void BattlePetMgr::SaveToDB(LoginDatabaseTransaction trans)
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
                stmt->setUInt32(4, itr->second.PacketInfo.DisplayID);
                stmt->setUInt16(5, itr->second.PacketInfo.Level);
                stmt->setUInt16(6, itr->second.PacketInfo.Exp);
                stmt->setUInt32(7, itr->second.PacketInfo.Health);
                stmt->setUInt8(8, itr->second.PacketInfo.Quality);
                stmt->setUInt16(9, itr->second.PacketInfo.Flags);
                stmt->setString(10, itr->second.PacketInfo.Name);
                stmt->setInt64(11, itr->second.NameTimestamp);
                if (itr->second.PacketInfo.OwnerInfo)
                {
                    stmt->setInt64(12, itr->second.PacketInfo.OwnerInfo->Guid.GetCounter());
                    stmt->setInt32(13, realm.Id.Realm);
                }
                else
                {
                    stmt->setNull(12);
                    stmt->setNull(13);
                }

                trans->Append(stmt);

                if (itr->second.DeclinedName)
                {
                    stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BATTLE_PET_DECLINED_NAME);
                    stmt->setUInt64(0, itr->first);

                    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; i++)
                        stmt->setString(i + 1, itr->second.DeclinedName->name[i]);

                    trans->Append(stmt);
                }

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
                stmt->setInt64(6, itr->second.NameTimestamp);
                stmt->setUInt32(7, _owner->GetBattlenetAccountId());
                stmt->setUInt64(8, itr->first);
                trans->Append(stmt);

                stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_BATTLE_PET_DECLINED_NAME);
                stmt->setUInt64(0, itr->first);
                trans->Append(stmt);

                if (itr->second.DeclinedName)
                {
                    stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BATTLE_PET_DECLINED_NAME);
                    stmt->setUInt64(0, itr->first);

                    for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; i++)
                        stmt->setString(i + 1, itr->second.DeclinedName->name[i]);

                    trans->Append(stmt);
                }

                itr->second.SaveInfo = BATTLE_PET_UNCHANGED;
                ++itr;
                break;
            case BATTLE_PET_REMOVED:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_BATTLE_PET_DECLINED_NAME);
                stmt->setUInt64(0, itr->first);
                trans->Append(stmt);

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

BattlePet* BattlePetMgr::GetPet(ObjectGuid guid)
{
    return Trinity::Containers::MapGetValuePtr(_pets, guid.GetCounter());
}

void BattlePetMgr::AddPet(uint32 species, uint32 display, uint16 breed, BattlePetBreedQuality quality, uint16 level /*= 1*/)
{
    BattlePetSpeciesEntry const* battlePetSpecies = sBattlePetSpeciesStore.LookupEntry(species);
    if (!battlePetSpecies) // should never happen
        return;

    if (!battlePetSpecies->GetFlags().HasFlag(BattlePetSpeciesFlags::WellKnown)) // Not learnable
        return;

    BattlePet pet;
    pet.PacketInfo.Guid = ObjectGuid::Create<HighGuid::BattlePet>(sObjectMgr->GetGenerator<HighGuid::BattlePet>().Generate());
    pet.PacketInfo.Species = species;
    pet.PacketInfo.CreatureID = battlePetSpecies->CreatureID;
    pet.PacketInfo.DisplayID = display;
    pet.PacketInfo.Level = level;
    pet.PacketInfo.Exp = 0;
    pet.PacketInfo.Flags = 0;
    pet.PacketInfo.Breed = breed;
    pet.PacketInfo.Quality = AsUnderlyingType(quality);
    pet.PacketInfo.Name = "";
    pet.CalculateStats();
    pet.PacketInfo.Health = pet.PacketInfo.MaxHealth;

    Player* player = _owner->GetPlayer();
    if (battlePetSpecies->GetFlags().HasFlag(BattlePetSpeciesFlags::NotAccountWide))
    {
        pet.PacketInfo.OwnerInfo.emplace();
        pet.PacketInfo.OwnerInfo->Guid = player->GetGUID();
        pet.PacketInfo.OwnerInfo->PlayerVirtualRealm = pet.PacketInfo.OwnerInfo->PlayerNativeRealm = player->m_playerData->VirtualPlayerRealm;
    }

    pet.SaveInfo = BATTLE_PET_NEW;

    _pets[pet.PacketInfo.Guid.GetCounter()] = std::move(pet);

    std::vector<std::reference_wrapper<BattlePet>> updates;
    updates.push_back(std::ref(pet));
    SendUpdates(std::move(updates), true);

    player->UpdateCriteria(CriteriaType::UniquePetsOwned);
    player->UpdateCriteria(CriteriaType::LearnedNewPet, species);
}

void BattlePetMgr::RemovePet(ObjectGuid guid)
{
    if (!HasJournalLock())
        return;

    BattlePet* pet = GetPet(guid);
    if (!pet)
        return;

    pet->SaveInfo = BATTLE_PET_REMOVED;
}

void BattlePetMgr::ClearFanfare(ObjectGuid guid)
{
    BattlePet* pet = GetPet(guid);
    if (!pet)
        return;

    pet->PacketInfo.Flags &= ~AsUnderlyingType(BattlePetDbFlags::FanfareNeeded);

    if (pet->SaveInfo != BATTLE_PET_NEW)
        pet->SaveInfo = BATTLE_PET_CHANGED;
}

void BattlePetMgr::ModifyName(ObjectGuid guid, std::string const& name, std::unique_ptr<DeclinedName> declinedName)
{
    if (!HasJournalLock())
        return;

    BattlePet* pet = GetPet(guid);
    if (!pet)
        return;

    pet->PacketInfo.Name = name;
    pet->NameTimestamp = GameTime::GetGameTime();

    pet->DeclinedName = std::move(declinedName);

    if (pet->SaveInfo != BATTLE_PET_NEW)
        pet->SaveInfo = BATTLE_PET_CHANGED;

    // Update the timestamp if the battle pet is summoned
    if (Creature* summonedBattlePet = _owner->GetPlayer()->GetSummonedBattlePet())
        if (summonedBattlePet->GetBattlePetCompanionGUID() == guid)
            summonedBattlePet->SetBattlePetCompanionNameTimestamp(pet->NameTimestamp);
}

bool BattlePetMgr::IsPetInSlot(ObjectGuid guid)
{
    for (WorldPackets::BattlePet::BattlePetSlot const& slot : _slots)
        if (slot.Pet.Guid == guid)
            return true;

    return false;
}

uint8 BattlePetMgr::GetPetCount(BattlePetSpeciesEntry const* battlePetSpecies, ObjectGuid ownerGuid) const
{
    return uint8(std::count_if(_pets.begin(), _pets.end(), [battlePetSpecies, ownerGuid](std::pair<uint64 const, BattlePet> const& pet)
    {
        if (pet.second.PacketInfo.Species != battlePetSpecies->ID)
            return false;

        if (pet.second.SaveInfo == BATTLE_PET_REMOVED)
            return false;

        if (battlePetSpecies->GetFlags().HasFlag(BattlePetSpeciesFlags::NotAccountWide))
            if (!ownerGuid.IsEmpty() && pet.second.PacketInfo.OwnerInfo)
                if (pet.second.PacketInfo.OwnerInfo->Guid != ownerGuid)
                    return false;

        return true;
    }));
}

bool BattlePetMgr::HasMaxPetCount(BattlePetSpeciesEntry const* battlePetSpecies, ObjectGuid ownerGuid) const
{
    uint8 maxPetsPerSpecies = battlePetSpecies->GetFlags().HasFlag(BattlePetSpeciesFlags::LegacyAccountUnique) ? 1 : DEFAULT_MAX_BATTLE_PETS_PER_SPECIES;

    return GetPetCount(battlePetSpecies, ownerGuid) >= maxPetsPerSpecies;
}

uint32 BattlePetMgr::GetPetUniqueSpeciesCount() const
{
    std::set<uint32> speciesIds;
    std::transform(_pets.begin(), _pets.end(), std::inserter(speciesIds, speciesIds.end()), [](std::pair<uint64 const, BattlePet> const& pet)
    {
        return pet.second.PacketInfo.Species;
    });
    return speciesIds.size();
}

void BattlePetMgr::UnlockSlot(BattlePetSlot slot)
{
    if (slot >= BattlePetSlot::Count)
        return;

    uint8 slotIndex = AsUnderlyingType(slot);
    if (!_slots[slotIndex].Locked)
        return;

    _slots[slotIndex].Locked = false;

    WorldPackets::BattlePet::PetBattleSlotUpdates updates;
    updates.Slots.push_back(_slots[slotIndex]);
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
    if (!HasJournalLock())
        return;

    BattlePet* pet = GetPet(guid);
    if (!pet)
        return;

    if (BattlePetSpeciesEntry const* battlePetSpecies = sBattlePetSpeciesStore.LookupEntry(pet->PacketInfo.Species))
        if (battlePetSpecies->GetFlags().HasFlag(BattlePetSpeciesFlags::NotTradable))
            return;

    if (IsPetInSlot(guid))
        return;

    if (pet->PacketInfo.Health < pet->PacketInfo.MaxHealth)
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
    item->SetModifier(ITEM_MODIFIER_BATTLE_PET_DISPLAY_ID, pet->PacketInfo.DisplayID);

    _owner->GetPlayer()->SendNewItem(item, 1, true, false);

    RemovePet(guid);

    WorldPackets::BattlePet::BattlePetDeleted deletePet;
    deletePet.PetGuid = guid;
    _owner->SendPacket(deletePet.Write());

    // Battle pet despawns if it's summoned
    Player* player = _owner->GetPlayer();
    if (Creature* summonedBattlePet = player->GetSummonedBattlePet())
    {
        if (summonedBattlePet->GetBattlePetCompanionGUID() == guid)
        {
            summonedBattlePet->DespawnOrUnsummon();
            player->SetBattlePetData(nullptr);
        }
    }
}

void BattlePetMgr::ChangeBattlePetQuality(ObjectGuid guid, BattlePetBreedQuality quality)
{
    if (!HasJournalLock())
        return;

    BattlePet* pet = GetPet(guid);
    if (!pet)
        return;

    if (quality > BattlePetBreedQuality::Rare)
        return;

    if (BattlePetSpeciesEntry const* battlePetSpecies = sBattlePetSpeciesStore.LookupEntry(pet->PacketInfo.Species))
        if (battlePetSpecies->GetFlags().HasFlag(BattlePetSpeciesFlags::CantBattle))
            return;

    uint8 qualityValue = AsUnderlyingType(quality);
    if (pet->PacketInfo.Quality >= qualityValue)
        return;

    pet->PacketInfo.Quality = qualityValue;
    pet->CalculateStats();
    pet->PacketInfo.Health = pet->PacketInfo.MaxHealth;

    if (pet->SaveInfo != BATTLE_PET_NEW)
        pet->SaveInfo = BATTLE_PET_CHANGED;

    std::vector<std::reference_wrapper<BattlePet>> updates;
    updates.push_back(std::ref(*pet));
    SendUpdates(std::move(updates), false);

    // UF::PlayerData::CurrentBattlePetBreedQuality isn't updated (Intended)
    // _owner->GetPlayer()->SetCurrentBattlePetBreedQuality(qualityValue);
}

void BattlePetMgr::GrantBattlePetExperience(ObjectGuid guid, uint16 xp, BattlePetXpSource xpSource)
{
    if (!HasJournalLock())
        return;

    BattlePet* pet = GetPet(guid);
    if (!pet)
        return;

    if (xp <= 0 || xpSource >= BattlePetXpSource::Count)
        return;

    if (BattlePetSpeciesEntry const* battlePetSpecies = sBattlePetSpeciesStore.LookupEntry(pet->PacketInfo.Species))
        if (battlePetSpecies->GetFlags().HasFlag(BattlePetSpeciesFlags::CantBattle))
            return;

    uint16 level = pet->PacketInfo.Level;
    if (level >= MAX_BATTLE_PET_LEVEL)
        return;

    GtBattlePetXPEntry const* xpEntry = sBattlePetXPGameTable.GetRow(level);
    if (!xpEntry)
        return;

    Player* player = _owner->GetPlayer();
    uint16 nextLevelXp = uint16(GetBattlePetXPPerLevel(xpEntry));

    if (xpSource == BattlePetXpSource::PetBattle)
        xp *= player->GetTotalAuraMultiplier(SPELL_AURA_MOD_BATTLE_PET_XP_PCT);

    xp += pet->PacketInfo.Exp;

    while (xp >= nextLevelXp && level < MAX_BATTLE_PET_LEVEL)
    {
        xp -= nextLevelXp;

        xpEntry = sBattlePetXPGameTable.GetRow(++level);
        if (!xpEntry)
            return;

        nextLevelXp = uint16(GetBattlePetXPPerLevel(xpEntry));

        player->UpdateCriteria(CriteriaType::BattlePetReachLevel, pet->PacketInfo.Species, level);
        if (xpSource == BattlePetXpSource::PetBattle)
            player->UpdateCriteria(CriteriaType::ActivelyEarnPetLevel, pet->PacketInfo.Species, level);
    }

    pet->PacketInfo.Level = level;
    pet->PacketInfo.Exp = level < MAX_BATTLE_PET_LEVEL ? xp : 0;
    pet->CalculateStats();
    pet->PacketInfo.Health = pet->PacketInfo.MaxHealth;

    if (pet->SaveInfo != BATTLE_PET_NEW)
        pet->SaveInfo = BATTLE_PET_CHANGED;

    std::vector<std::reference_wrapper<BattlePet>> updates;
    updates.push_back(std::ref(*pet));
    SendUpdates(std::move(updates), false);
}

void BattlePetMgr::GrantBattlePetLevel(ObjectGuid guid, uint16 grantedLevels)
{
    if (!HasJournalLock())
        return;

    BattlePet* pet = GetPet(guid);
    if (!pet)
        return;

    if (BattlePetSpeciesEntry const* battlePetSpecies = sBattlePetSpeciesStore.LookupEntry(pet->PacketInfo.Species))
        if (battlePetSpecies->GetFlags().HasFlag(BattlePetSpeciesFlags::CantBattle))
            return;

    uint16 level = pet->PacketInfo.Level;
    if (level >= MAX_BATTLE_PET_LEVEL)
        return;

    while (grantedLevels > 0 && level < MAX_BATTLE_PET_LEVEL)
    {
        ++level;
        --grantedLevels;

        _owner->GetPlayer()->UpdateCriteria(CriteriaType::BattlePetReachLevel, pet->PacketInfo.Species, level);
    }

    pet->PacketInfo.Level = level;
    if (level >= MAX_BATTLE_PET_LEVEL)
        pet->PacketInfo.Exp = 0;
    pet->CalculateStats();
    pet->PacketInfo.Health = pet->PacketInfo.MaxHealth;

    if (pet->SaveInfo != BATTLE_PET_NEW)
        pet->SaveInfo = BATTLE_PET_CHANGED;

    std::vector<std::reference_wrapper<BattlePet>> updates;
    updates.push_back(std::ref(*pet));
    SendUpdates(std::move(updates), false);
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

void BattlePetMgr::UpdateBattlePetData(ObjectGuid guid)
{
    BattlePet* pet = GetPet(guid);
    if (!pet)
        return;

    Player* player = _owner->GetPlayer();

    // Update battle pet related update fields
    if (Creature* summonedBattlePet = player->GetSummonedBattlePet())
    {
        if (summonedBattlePet->GetBattlePetCompanionGUID() == guid)
        {
            summonedBattlePet->SetWildBattlePetLevel(pet->PacketInfo.Level);
            player->SetBattlePetData(pet);
        }
    }
}

void BattlePetMgr::SummonPet(ObjectGuid guid)
{
    BattlePet* pet = GetPet(guid);
    if (!pet)
        return;

    BattlePetSpeciesEntry const* speciesEntry = sBattlePetSpeciesStore.LookupEntry(pet->PacketInfo.Species);
    if (!speciesEntry)
        return;

    Player* player = _owner->GetPlayer();
    player->SetBattlePetData(pet);

    CastSpellExtraArgs args;
    uint32 summonSpellId = speciesEntry->SummonSpellID;
    if (!summonSpellId)
    {
        summonSpellId = uint32(SPELL_SUMMON_BATTLE_PET);
        args.AddSpellBP0(speciesEntry->CreatureID);
    }
    player->CastSpell(_owner->GetPlayer(), summonSpellId, args);
}

void BattlePetMgr::DismissPet()
{
    Player* player = _owner->GetPlayer();
    if (Creature* summonedBattlePet = player->GetSummonedBattlePet())
    {
        summonedBattlePet->DespawnOrUnsummon();
        player->SetBattlePetData(nullptr);
    }
}

void BattlePetMgr::SendJournal()
{
    if (!HasJournalLock())
        SendJournalLockStatus();

    WorldPackets::BattlePet::BattlePetJournal battlePetJournal;
    battlePetJournal.Trap = _trapLevel;
    battlePetJournal.HasJournalLock = _hasJournalLock;

    for (auto& pet : _pets)
        if (pet.second.SaveInfo != BATTLE_PET_REMOVED)
            if (!pet.second.PacketInfo.OwnerInfo || pet.second.PacketInfo.OwnerInfo->Guid == _owner->GetPlayer()->GetGUID())
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
    battlePetError.Result = AsUnderlyingType(error);
    battlePetError.CreatureID = creatureId;
    _owner->SendPacket(battlePetError.Write());
}

void BattlePetMgr::SendJournalLockStatus()
{
    if (!IsJournalLockAcquired())
        ToggleJournalLock(true);

    if (HasJournalLock())
    {
        WorldPackets::BattlePet::BattlePetJournalLockAcquired battlePetJournalLockAcquired;
        _owner->SendPacket(battlePetJournalLockAcquired.Write());
    }
    else
    {
        WorldPackets::BattlePet::BattlePetJournalLockDenied BattlePetJournalLockDenied;
        _owner->SendPacket(BattlePetJournalLockDenied.Write());
    }
}

bool BattlePetMgr::IsJournalLockAcquired() const
{
    return sWorld->IsBattlePetJournalLockAcquired(_owner->GetBattlenetAccountGUID());
}
}
