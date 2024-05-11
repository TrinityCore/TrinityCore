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

#ifndef TRINITYCORE_PET_DEFINES_H
#define TRINITYCORE_PET_DEFINES_H

#include "Define.h"
#include "Optional.h"
#include <array>
#include <string>
#include <vector>

enum ReactStates : uint8;

enum PetType : uint8
{
    SUMMON_PET              = 0,
    HUNTER_PET              = 1,
    MAX_PET_TYPE            = 4
};

#define MAX_ACTIVE_PETS         5
#define MAX_PET_STABLES         200

// stored in character_pet.slot
enum PetSaveMode : int16
{
    PET_SAVE_AS_DELETED        = -2,                        // not saved in fact
    PET_SAVE_AS_CURRENT        = -3,                        // in current slot (with player)
    PET_SAVE_FIRST_ACTIVE_SLOT =  0,
    PET_SAVE_LAST_ACTIVE_SLOT  = PET_SAVE_FIRST_ACTIVE_SLOT + MAX_ACTIVE_PETS,
    PET_SAVE_FIRST_STABLE_SLOT =  5,
    PET_SAVE_LAST_STABLE_SLOT  = PET_SAVE_FIRST_STABLE_SLOT + MAX_PET_STABLES, // last in DB stable slot index
    PET_SAVE_NOT_IN_SLOT       = -1                         // for avoid conflict with stable size grow will use negative value
};

constexpr bool IsActivePetSlot(PetSaveMode slot)
{
    return slot >= PET_SAVE_FIRST_ACTIVE_SLOT && slot < PET_SAVE_LAST_ACTIVE_SLOT;
}

constexpr bool IsStabledPetSlot(PetSaveMode slot)
{
    return slot >= PET_SAVE_FIRST_STABLE_SLOT && slot < PET_SAVE_LAST_STABLE_SLOT;
}

enum PetStableFlags : uint8
{
    PET_STABLE_ACTIVE   = 0x1,
    PET_STABLE_INACTIVE = 0x2,
    PET_STABLE_FAVORITE = 0x8
};

enum PetSpellState
{
    PETSPELL_UNCHANGED = 0,
    PETSPELL_CHANGED   = 1,
    PETSPELL_NEW       = 2,
    PETSPELL_REMOVED   = 3
};

enum PetSpellType
{
    PETSPELL_NORMAL = 0,
    PETSPELL_FAMILY = 1,
    PETSPELL_TALENT = 2
};

enum class PetActionFeedback : uint8
{
    None            = 0,
    Dead            = 1,
    NoTarget        = 2,
    InvalidTarget   = 3,
    NoPath          = 4
};

enum PetTalk
{
    PET_TALK_SPECIAL_SPELL  = 0,
    PET_TALK_ATTACK         = 1
};

#define PET_FOLLOW_DIST  1.0f
#define PET_FOLLOW_ANGLE float(M_PI)

enum class PetTameResult : uint8
{
    Ok                      = 0,
    InvalidCreature         = 1,
    TooMany                 = 2,
    CreatureAlreadyOwned    = 3,
    NotTameable             = 4,
    AnotherSummonActive     = 5,
    UnitsCantTame           = 6,
    NoPetAvailable          = 7,
    InternalError           = 8,
    TooHighLevel            = 9,
    Dead                    = 10,
    NotDead                 = 11,
    CantControlExotic       = 12,
    InvalidSlot             = 13,
    EliteTooHighLevel       = 14
};

enum class StableResult : uint8
{
    NotEnoughMoney        = 1,                              // "you don't have enough money"
    InvalidSlot           = 3,                              // "That slot is locked"
    StableSuccess         = 8,                              // stable success
    UnstableSuccess       = 9,                              // unstable/swap success
    BuySlotSuccess        = 10,                             // buy slot success
    CantControlExotic     = 11,                             // "you are unable to control exotic creatures"
    InternalError         = 12,                             // "Internal pet error"
};

constexpr uint32 CALL_PET_SPELL_ID = 883;
constexpr uint32 PET_SUMMONING_DISORIENTATION = 32752;

class PetStable
{
public:
    struct PetInfo
    {
        PetInfo() { }

        std::string Name;
        std::string ActionBar;
        uint32 PetNumber = 0;
        uint32 CreatureId = 0;
        uint32 DisplayId = 0;
        uint32 Experience = 0;
        uint32 Health = 0;
        uint32 Mana = 0;
        uint32 LastSaveTime = 0;
        uint32 CreatedBySpellId = 0;
        uint16 SpecializationId = 0;
        uint8 Level = 0;
        ReactStates ReactState = ReactStates(0);
        PetType Type = MAX_PET_TYPE;
        bool WasRenamed = false;
    };

    Optional<uint32> CurrentPetIndex;                               // index into ActivePets or UnslottedPets if highest bit is set
    std::array<Optional<PetInfo>, MAX_ACTIVE_PETS> ActivePets;      // PET_SAVE_FIRST_ACTIVE_SLOT - PET_SAVE_LAST_ACTIVE_SLOT
    std::array<Optional<PetInfo>, MAX_PET_STABLES> StabledPets;     // PET_SAVE_FIRST_STABLE_SLOT - PET_SAVE_LAST_STABLE_SLOT
    std::vector<PetInfo> UnslottedPets;                             // PET_SAVE_NOT_IN_SLOT

    PetInfo* GetCurrentPet() { return const_cast<PetInfo*>(const_cast<PetStable const*>(this)->GetCurrentPet()); }
    PetInfo const* GetCurrentPet() const
    {
        if (!CurrentPetIndex)
            return nullptr;

        if (Optional<uint32> activePetIndex = GetCurrentActivePetIndex())
            return ActivePets[*activePetIndex] ? &ActivePets[*activePetIndex].value() : nullptr;

        if (Optional<uint32> unslottedPetIndex = GetCurrentUnslottedPetIndex())
            return *unslottedPetIndex < UnslottedPets.size() ? &UnslottedPets[*unslottedPetIndex] : nullptr;

        return nullptr;
    }

    Optional<uint32> GetCurrentActivePetIndex() const { return CurrentPetIndex && ((*CurrentPetIndex & UnslottedPetIndexMask) == 0) ? CurrentPetIndex : std::nullopt; }
    void SetCurrentActivePetIndex(uint32 index) { CurrentPetIndex = index; }
    Optional<uint32> GetCurrentUnslottedPetIndex() const { return CurrentPetIndex && ((*CurrentPetIndex & UnslottedPetIndexMask) != 0) ? Optional<uint32>(*CurrentPetIndex & ~UnslottedPetIndexMask) : std::nullopt; }
    void SetCurrentUnslottedPetIndex(uint32 index) { CurrentPetIndex = index | UnslottedPetIndexMask; }

private:
    static constexpr uint32 UnslottedPetIndexMask = 0x80000000;
};

#endif
