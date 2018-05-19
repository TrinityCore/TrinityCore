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

#ifndef BattlePetMgr_h__
#define BattlePetMgr_h__

#include "BattlePet.h"
#include "BattlePetDataStore.h"
#include "BattlePetPackets.h"
#include "DatabaseEnvFwd.h"
#include <unordered_map>

class BattlePetMgr
{
public:
    explicit BattlePetMgr(WorldSession* owner);

    void LoadFromDB(PreparedQueryResult pets, PreparedQueryResult slots);
    void SaveToDB(SQLTransaction& trans);

    BattlePet* GetPet(ObjectGuid guid);
    void AddPet(BattlePet* battlePet);
    void AddPet(uint32 species, uint32 creatureId, uint16 breed, uint8 quality, uint16 level = 1);
    void RemovePet(ObjectGuid guid);

    uint8 GetPetCount(bool aliveOnly = false) const;
    uint8 GetPetCount(uint32 species) const;

    WorldPackets::BattlePet::BattlePetSlot* GetSlot(uint8 slot) { return &_slots[slot]; }
    void UnlockSlot(uint8 slot);

    WorldSession* GetOwner() const { return _owner; }

    uint16 GetTrapLevel() const { return _trapLevel; }
    int32 GetTrapAbilityId() const { return 0; }

    uint16 GetMaxPetLevel() const;
    std::vector<WorldPackets::BattlePet::BattlePetSlot> const& GetSlots() const { return _slots; }

    void CageBattlePet(ObjectGuid guid);
    void HealBattlePetsPct(uint8 pct);

    void SummonPet(ObjectGuid guid);
    void DismissPet();

    void SendJournal();
    void SendUpdates(std::vector<std::reference_wrapper<BattlePet>> pets, bool petAdded);
    void SendError(BattlePetError error, uint32 creatureId);

private:
    WorldSession* _owner;
    uint16 _trapLevel = 0;
    std::unordered_map<uint64 /*battlePetGuid*/, BattlePet> _pets;
    std::vector<WorldPackets::BattlePet::BattlePetSlot> _slots;
};

#endif // BattlePetMgr_h__
