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

#include "BattlePet.h"
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

            BattlePetSpeciesEntry const* speciesEntry = sBattlePetSpeciesStore.LookupEntry(species);
            if (!speciesEntry)
            {
                TC_LOG_ERROR("misc", "Battlenet account with id %u has not existing battle pet species %u", _owner->GetBattlenetAccountId(), species);
                continue;
            }

            if (GetPetCount(species) >= MAX_BATTLE_PETS_PER_SPECIES)
            {
                TC_LOG_ERROR("misc", "Battlenet account with id %u has more than 3 battle pets of species %u", _owner->GetBattlenetAccountId(), species);
                continue;
            }

            BattlePet pet;
            pet.Guid = ObjectGuid::Create<HighGuid::BattlePet>(fields[0].GetUInt64());
            pet.Species = species;
            pet.Breed = fields[2].GetUInt16();
            pet.Level = fields[3].GetUInt16();
            pet.Exp = fields[4].GetUInt16();
            pet.Health = fields[5].GetUInt32();
            pet.Quality = fields[6].GetUInt8();
            pet.Flags = fields[7].GetUInt16();
            pet.Name = fields[8].GetString();
            pet.CreatureID = speciesEntry->CreatureID;
            pet.SaveInfo = BATTLE_PET_UNCHANGED;
            pet.CalculateStats();
            _pets[pet.Guid.GetCounter()] = pet;

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
                _slots[i].Pet = itr->second;
            _slots[i].Locked = fields[2].GetBool();
            ++i;
        } while (slots->NextRow());
    }
}

void BattlePetMgr::SaveToDB(SQLTransaction& trans)
{
    PreparedStatement* stmt = nullptr;

    for (auto itr = _pets.begin(); itr != _pets.end();)
    {
        switch (itr->second.SaveInfo)
        {
            case BATTLE_PET_NEW:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_BATTLE_PETS);
                stmt->setUInt64(0, itr->first);
                stmt->setUInt32(1, _owner->GetBattlenetAccountId());
                stmt->setUInt32(2, itr->second.Species);
                stmt->setUInt16(3, itr->second.Breed);
                stmt->setUInt16(4, itr->second.Level);
                stmt->setUInt16(5, itr->second.Exp);
                stmt->setUInt32(6, itr->second.Health);
                stmt->setUInt8(7, itr->second.Quality);
                stmt->setUInt16(8, itr->second.Flags);
                stmt->setString(9, itr->second.Name);
                trans->Append(stmt);
                itr->second.SaveInfo = BATTLE_PET_UNCHANGED;
                ++itr;
                break;
            case BATTLE_PET_CHANGED:
                stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BATTLE_PETS);
                stmt->setUInt16(0, itr->second.Level);
                stmt->setUInt16(1, itr->second.Exp);
                stmt->setUInt32(2, itr->second.Health);
                stmt->setUInt8(3, itr->second.Quality);
                stmt->setUInt16(4, itr->second.Flags);
                stmt->setString(5, itr->second.Name);
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

BattlePet* BattlePetMgr::GetPet(ObjectGuid guid)
{
    return Trinity::Containers::MapGetValuePtr(_pets, guid.GetCounter());
}

void BattlePetMgr::AddPet(BattlePet* battlePet)
{
    AddPet(battlePet->Species, battlePet->CreatureID, battlePet->Breed, battlePet->Quality, battlePet->Level);
}

void BattlePetMgr::AddPet(uint32 species, uint32 creatureId, uint16 breed, uint8 quality, uint16 level /*= 1*/)
{
    BattlePetSpeciesEntry const* battlePetSpecies = sBattlePetSpeciesStore.LookupEntry(species);
    if (!battlePetSpecies) // should never happen
        return;

    if (GetPetCount(species) >= MAX_BATTLE_PETS_PER_SPECIES)
        return;

    BattlePet pet;
    pet.Guid = ObjectGuid::Create<HighGuid::BattlePet>(sObjectMgr->GetGenerator<HighGuid::BattlePet>().Generate());
    pet.Species = species;
    pet.CreatureID = creatureId;
    pet.Level = level;
    pet.Exp = 0;
    pet.Flags = 0;
    pet.Breed = breed;
    pet.Quality = quality;
    pet.Name = "";
    pet.CalculateStats();
    pet.Health = pet.MaxHealth;
    pet.SaveInfo = BATTLE_PET_NEW;

    _pets[pet.Guid.GetCounter()] = pet;

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
    /*if (GetPetCount(pet->Species) == 0)
        if (BattlePetSpeciesEntry const* speciesEntry = sBattlePetSpeciesStore.LookupEntry(pet->Species))
            _owner->GetPlayer()->RemoveSpell(speciesEntry->SummonSpellID);*/
}

uint8 BattlePetMgr::GetPetCount(bool aliveOnly /*= false*/) const
{
    return uint8(std::count_if(_pets.begin(), _pets.end(), [aliveOnly](std::pair<uint64 const, BattlePet> const& pet)
    {
        return (!aliveOnly || pet.second.Health != 0) && pet.second.SaveInfo != BATTLE_PET_REMOVED;
    }));
}

uint8 BattlePetMgr::GetPetCount(uint32 species) const
{
    return uint8(std::count_if(_pets.begin(), _pets.end(), [species](std::pair<uint64 const, BattlePet> const& pet)
    {
        return pet.second.Species == species && pet.second.SaveInfo != BATTLE_PET_REMOVED;
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
            level = std::max(level, pet.second.Level);

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

    item->SetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID, pet->Species);
    item->SetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA, pet->Breed | (pet->Quality << 24));
    item->SetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL, pet->Level);
    item->SetModifier(ITEM_MODIFIER_BATTLE_PET_DISPLAY_ID, pet->CreatureID);

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
        if (pet.second.Health != pet.second.MaxHealth)
        {
            pet.second.Health += CalculatePct(pet.second.MaxHealth, pct);
            // don't allow Health to be greater than MaxHealth
            pet.second.Health = std::min(pet.second.Health, pet.second.MaxHealth);
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

    BattlePetSpeciesEntry const* speciesEntry = sBattlePetSpeciesStore.LookupEntry(pet->Species);
    if (!speciesEntry)
        return;

    // TODO: set proper CreatureID for spell DEFAULT_SUMMON_BATTLE_PET_SPELL (default EffectMiscValueA is 40721 - Murkimus the Gladiator)
    _owner->GetPlayer()->SetGuidValue(ACTIVE_PLAYER_FIELD_SUMMONED_BATTLE_PET_ID, guid);
    _owner->GetPlayer()->CastSpell(_owner->GetPlayer(), speciesEntry->SummonSpellID ? speciesEntry->SummonSpellID : uint32(DEFAULT_SUMMON_BATTLE_PET_SPELL));

    // TODO: set pet level, quality... update fields
}

void BattlePetMgr::DismissPet()
{
    Player* ownerPlayer = _owner->GetPlayer();
    Creature* pet = ObjectAccessor::GetCreatureOrPetOrVehicle(*ownerPlayer, ownerPlayer->GetCritterGUID());
    if (pet && ownerPlayer->GetGuidValue(ACTIVE_PLAYER_FIELD_SUMMONED_BATTLE_PET_ID) == pet->GetGuidValue(UNIT_FIELD_BATTLE_PET_COMPANION_GUID))
    {
        pet->DespawnOrUnsummon();
        ownerPlayer->SetGuidValue(ACTIVE_PLAYER_FIELD_SUMMONED_BATTLE_PET_ID, ObjectGuid::Empty);
    }
}

void BattlePetMgr::SendJournal()
{
    WorldPackets::BattlePet::BattlePetJournal battlePetJournal;
    battlePetJournal.Trap = _trapLevel;

    for (auto& pet : _pets)
        if (pet.second.SaveInfo != BATTLE_PET_REMOVED)
            battlePetJournal.Pets.push_back(std::ref(pet.second));

    battlePetJournal.Slots.reserve(_slots.size());
    std::transform(_slots.begin(), _slots.end(), std::back_inserter(battlePetJournal.Slots), [](WorldPackets::BattlePet::BattlePetSlot& slot) { return std::ref(slot); });
    _owner->SendPacket(battlePetJournal.Write());
}

void BattlePetMgr::SendUpdates(std::vector<std::reference_wrapper<BattlePet>> pets, bool petAdded)
{
    WorldPackets::BattlePet::BattlePetUpdates updates;
    for (BattlePet& pet : pets)
        updates.Pets.push_back(std::ref(pet));

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
