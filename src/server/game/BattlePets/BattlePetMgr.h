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

#ifndef BattlePetMgr_h__
#define BattlePetMgr_h__

#include "BattlePetPackets.h"
#include "DatabaseEnvFwd.h"
#include "EnumFlag.h"
#include <unordered_map>

struct BattlePetSpeciesEntry;

namespace BattlePets
{
enum BattlePetMisc
{
    DEFAULT_MAX_BATTLE_PETS_PER_SPECIES = 3,
    BATTLE_PET_CAGE_ITEM_ID             = 82800,
    SPELL_VISUAL_UNCAGE_PET             = 222,

    SPELL_BATTLE_PET_TRAINING           = 125610,
    SPELL_REVIVE_BATTLE_PETS            = 125439,
    SPELL_SUMMON_BATTLE_PET             = 118301
};

static constexpr uint16 MAX_BATTLE_PET_LEVEL = 25;

enum class BattlePetBreedQuality : uint8
{
    Poor       = 0,
    Common     = 1,
    Uncommon   = 2,
    Rare       = 3,
    Epic       = 4,
    Legendary  = 5,

    Count
};

enum class BattlePetDbFlags : uint16
{
    None                = 0x000,
    Favorite            = 0x001,
    Converted           = 0x002,
    Revoked             = 0x004,
    LockedForConvert    = 0x008,
    Ability0Selection   = 0x010,
    Ability1Selection   = 0x020,
    Ability2Selection   = 0x040,
    FanfareNeeded       = 0x080,
    DisplayOverridden   = 0x100
};

DEFINE_ENUM_FLAG(BattlePetDbFlags);

enum class BattlePetError : uint8
{
    CantHaveMorePetsOfType = 3, // You can't have any more pets of that type.
    CantHaveMorePets       = 4, // You can't have any more pets.
    TooHighLevelToUncage   = 7  // This pet is too high level for you to uncage.
};

enum class BattlePetSlot : uint8
{
    Slot0 = 0,
    Slot1 = 1,
    Slot2 = 2,

    Count
};

enum class BattlePetXpSource : uint8
{
    PetBattle   = 0,
    SpellEffect = 1,

    Count
};

// 6.2.4
enum FlagsControlType
{
    FLAGS_CONTROL_TYPE_APPLY        = 1,
    FLAGS_CONTROL_TYPE_REMOVE       = 2
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

enum BattlePetSaveInfo
{
    BATTLE_PET_UNCHANGED = 0,
    BATTLE_PET_CHANGED   = 1,
    BATTLE_PET_NEW       = 2,
    BATTLE_PET_REMOVED   = 3
};

struct BattlePet
{
    void CalculateStats();

    WorldPackets::BattlePet::BattlePet PacketInfo;
    time_t NameTimestamp = time_t(0);
    std::unique_ptr<::DeclinedName> DeclinedName;
    BattlePetSaveInfo SaveInfo = BATTLE_PET_UNCHANGED;
};

class TC_GAME_API BattlePetMgr
{
public:
    explicit BattlePetMgr(WorldSession* owner);
    BattlePetMgr(BattlePetMgr const& right) = delete;
    BattlePetMgr(BattlePetMgr&& right) = delete;

    static void Initialize();

    static void AddBattlePetSpeciesBySpell(uint32 spellId, BattlePetSpeciesEntry const* speciesEntry);
    static BattlePetSpeciesEntry const* GetBattlePetSpeciesByCreature(uint32 creatureId);
    static BattlePetSpeciesEntry const* GetBattlePetSpeciesBySpell(uint32 spellId);
    static uint16 RollPetBreed(uint32 species);
    static BattlePetBreedQuality GetDefaultPetQuality(uint32 species);
    static uint32 SelectPetDisplay(BattlePetSpeciesEntry const* speciesEntry);

    void LoadFromDB(PreparedQueryResult pets, PreparedQueryResult slots);
    void SaveToDB(LoginDatabaseTransaction trans);

    BattlePet* GetPet(ObjectGuid guid);
    void AddPet(uint32 species, uint32 display, uint16 breed, BattlePetBreedQuality quality, uint16 level = 1);
    void RemovePet(ObjectGuid guid);
    void ClearFanfare(ObjectGuid guid);
    void ModifyName(ObjectGuid guid, std::string const& name, std::unique_ptr<DeclinedName> declinedName);
    bool IsPetInSlot(ObjectGuid guid);

    uint8 GetPetCount(BattlePetSpeciesEntry const* battlePetSpecies, ObjectGuid ownerGuid) const;
    bool HasMaxPetCount(BattlePetSpeciesEntry const* battlePetSpecies, ObjectGuid ownerGuid) const;
    uint32 GetPetUniqueSpeciesCount() const;

    WorldPackets::BattlePet::BattlePetSlot* GetSlot(BattlePetSlot slot) { return slot < BattlePetSlot::Count ? &_slots[size_t(slot)] : nullptr; }
    void UnlockSlot(BattlePetSlot slot);

    WorldSession* GetOwner() const { return _owner; }

    uint16 GetTrapLevel() const { return _trapLevel; }
    uint16 GetMaxPetLevel() const;
    std::vector<WorldPackets::BattlePet::BattlePetSlot> const& GetSlots() const { return _slots; }

    void CageBattlePet(ObjectGuid guid);
    void ChangeBattlePetQuality(ObjectGuid guid, BattlePetBreedQuality quality);
    void GrantBattlePetExperience(ObjectGuid guid, uint16 xp, BattlePetXpSource xpSource);
    void GrantBattlePetLevel(ObjectGuid guid, uint16 grantedLevels);
    void HealBattlePetsPct(uint8 pct);
    void UpdateBattlePetData(ObjectGuid guid);

    void SummonPet(ObjectGuid guid);
    void DismissPet();

    void SendJournal();
    void SendUpdates(std::vector<std::reference_wrapper<BattlePet>> pets, bool petAdded);
    void SendError(BattlePetError error, uint32 creatureId);

    void SendJournalLockStatus();
    bool IsJournalLockAcquired() const;
    bool HasJournalLock() const { return _hasJournalLock; }
    void ToggleJournalLock(bool lock) { _hasJournalLock = lock; }

    bool IsBattlePetSystemEnabled() { return GetSlot(BattlePetSlot::Slot0)->Locked != true; }

private:
    WorldSession* _owner;
    bool _hasJournalLock = false;
    uint16 _trapLevel = 0;
    std::unordered_map<uint64 /*battlePetGuid*/, BattlePet> _pets;
    std::vector<WorldPackets::BattlePet::BattlePetSlot> _slots;

    static void LoadAvailablePetBreeds();
    static void LoadDefaultPetQualities();
};
}
#endif // BattlePetMgr_h__
