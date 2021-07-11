/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOSSERVER_PET_H
#define MANGOSSERVER_PET_H

#include "Common.h"
#include "Creature.h"

enum PetType
{
    SUMMON_PET              = 0,
    HUNTER_PET              = 1,
    GUARDIAN_PET            = 2,
    MINI_PET                = 3,
    MAX_PET_TYPE            = 4
};

#define MAX_PET_STABLES         2

// stored in character_pet.slot
enum PetSaveMode
{
    PET_SAVE_AS_DELETED        = -1,                        // not saved in fact
    PET_SAVE_AS_CURRENT        =  0,                        // in current slot (with player)
    PET_SAVE_FIRST_STABLE_SLOT =  1,
    PET_SAVE_LAST_STABLE_SLOT  =  MAX_PET_STABLES,          // last in DB stable slot index (including), all higher have same meaning as PET_SAVE_NOT_IN_SLOT
    PET_SAVE_NOT_IN_SLOT       =  100,                      // for avoid conflict with stable size grow will use 100
    PET_SAVE_REAGENTS          =  101                       // PET_SAVE_NOT_IN_SLOT with reagents return
};

enum HappinessState
{
    UNHAPPY = 1,
    CONTENT = 2,
    HAPPY   = 3
};

enum LoyaltyLevel
{
    REBELLIOUS  = 1,
    UNRULY      = 2,
    SUBMISSIVE  = 3,
    DEPENDABLE  = 4,
    FAITHFUL    = 5,
    BEST_FRIEND = 6
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
};

struct PetSpell
{
    uint8 active;                                           // use instead enum (not good use *uint8* limited enum in case when value in enum not possitive in *int8*)

    PetSpellState state : 8;
    PetSpellType type   : 8;
};

enum ActionFeedback
{
    FEEDBACK_PET_NONE        = 0,   // custom, not to be sent
    FEEDBACK_PET_DEAD        = 1,
    FEEDBACK_NOTHING_TO_ATT  = 2,
    FEEDBACK_CANT_ATT_TARGET = 3,
    FEEDBACK_NO_PATH_TO      = 4
};

enum PetTalk
{
    PET_TALK_SPECIAL_SPELL  = 0,
    PET_TALK_ATTACK         = 1
};


// [-ZERO] Need recheck and drop not existed cases
enum PetNameInvalidReason
{
    // custom, not send
    PET_NAME_SUCCESS                                        = 0,

    PET_NAME_INVALID                                        = 1,
    PET_NAME_NO_NAME                                        = 2,
    PET_NAME_TOO_SHORT                                      = 3,
    PET_NAME_TOO_LONG                                       = 4,
    PET_NAME_MIXED_LANGUAGES                                = 6,
    PET_NAME_PROFANE                                        = 7,
    PET_NAME_RESERVED                                       = 8,
    PET_NAME_THREE_CONSECUTIVE                              = 11,
    PET_NAME_INVALID_SPACE                                  = 12,
    PET_NAME_CONSECUTIVE_SPACES                             = 13,
    PET_NAME_RUSSIAN_CONSECUTIVE_SILENT_CHARACTERS          = 14,
    PET_NAME_RUSSIAN_SILENT_CHARACTER_AT_BEGINNING_OR_END   = 15,
    PET_NAME_DECLENSION_DOESNT_MATCH_BASE_NAME              = 16
};

typedef std::unordered_map<uint32, PetSpell> PetSpellMap;
typedef std::map<uint32,uint32> TeachSpellMap;
typedef std::vector<uint32> AutoSpellList;

#define HAPPINESS_LEVEL_SIZE        333000

extern uint32 const LevelUpLoyalty[6];
extern uint32 const LevelStartLoyalty[6];

#define ACTIVE_SPELLS_MAX           4

#define PET_FOLLOW_DIST 2.0f
#define PET_FOLLOW_ANGLE (M_PI_F/2.0f)
#define MINI_PET_FOLLOW_ANGLE (M_PI_F)
#define MINI_PET_SUMMON_ANGLE (M_PI_F/4.0f)

class Player;
struct CharacterPetCache;

class Pet : public Creature
{
    public:
        explicit Pet(PetType type = MAX_PET_TYPE);
        ~Pet() override;

        void AddToWorld() override;
        void RemoveFromWorld() override;

        PetType getPetType() const { return m_petType; }
        void setPetType(PetType type) { m_petType = type; }
        bool isControlled() const { return getPetType() == SUMMON_PET || getPetType() == HUNTER_PET; }
        bool isTemporarySummoned() const { return m_duration > 0; }
        bool IsPermanentPetFor(Player* owner) const;              // pet have tab in character windows and set UNIT_FIELD_PETNUMBER

        bool Create (uint32 guidlow, CreatureCreatePos& cPos, CreatureInfo const* cinfo, uint32 pet_number);
        bool CreateBaseAtCreature(Creature* creature);
        bool LoadPetFromDB(Player* owner, uint32 petEntry = 0, uint32 petNumber = 0, bool current = false);
        void SavePetToDB(PetSaveMode mode);
        void Unsummon(PetSaveMode mode, Unit* owner = nullptr);
        void DelayedUnsummon(uint32 timeMSToDespawn, PetSaveMode mode);
        static void DeleteFromDB(uint32 guidlow, bool separate_transaction = true);

        void SetDeathState(DeathState s) override;                   // overwrite virtual Creature::SetDeathState and Unit::SetDeathState
        void Update(uint32 update_diff, uint32 diff) override;  // overwrite virtual Creature::Update and Unit::Update

        uint8 GetPetAutoSpellSize() const override { return m_autospells.size(); }
        uint32 GetPetAutoSpellOnPos(uint8 pos) const override
        {
            if (pos >= m_autospells.size())
                return 0;
            return m_autospells[pos];
        }

        void RegenerateAll(uint32 update_diff, bool skipCombatCheck = false) override;
        void RegenerateFocus();
        void LooseHappiness();
        void TickLoyaltyChange();
        void ModifyLoyalty(int32 addvalue);
        HappinessState GetHappinessState() const;
        uint32 GetMaxLoyaltyPoints(uint32 level);
        uint32 GetStartLoyaltyPoints(uint32 level);
        void KillLoyaltyBonus(uint32 level);
        uint32 GetLoyaltyLevel() const { return GetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_PET_LOYALTY); }
        void SetLoyaltyLevel(LoyaltyLevel level);
        void GivePetXP(uint32 xp);
        void GivePetLevel(uint32 level);
        void SynchronizeLevelWithOwner();
        bool InitStatsForLevel(uint32 level, Unit* owner = nullptr);
        bool HaveInDiet(ItemPrototype const* item) const;
        uint32 GetCurrentFoodBenefitLevel(uint32 itemLevel) const;
        void SetDuration(int32 dur) { m_duration = dur; }

        int32 GetBonusDamage() const { return m_bonusdamage; }
        void SetBonusDamage(int32 damage) { m_bonusdamage = damage; }

        bool UpdateStats(Stats stat) override;
        bool UpdateAllStats() override;
        void UpdateResistances(uint32 school) override;
        void UpdateArmor() override;
        void UpdateMaxHealth() override;
        void UpdateMaxPower(Powers power) override;
        void UpdateAttackPowerAndDamage(bool ranged = false) override;
        void UpdateDamagePhysical(WeaponAttackType attType) override;

        bool   CanTakeMoreActiveSpells(uint32 SpellIconID);
        void   ToggleAutocast(uint32 spellid, bool apply);
        bool   HasTPForSpell(uint32 spellid);
        int32  GetTPForSpell(uint32 spellid);

        void SetEnabled(bool on);
        bool IsEnabled() const { return m_enabled; }

        bool HasSpell(uint32 spell) const override;
        void AddTeachSpell(uint32 learned_id, uint32 source_id) { m_teachspells[learned_id] = source_id; }

        void LearnPetPassives();
        void CastPetAuras(bool current);
        void CastPetAura(PetAura const* aura);

        void _LoadSpellCooldowns();
        void _SaveSpellCooldowns();
        void _LoadAuras(uint32 timediff);
        void _SaveAuras();
        void _LoadSpells();
        void _SaveSpells();

        bool AddSpell(uint32 spellId, ActiveStates active = ACT_DECIDE, PetSpellState state = PETSPELL_NEW, PetSpellType type = PETSPELL_NORMAL);
        bool LearnSpell(uint32 spellId);
        bool unlearnSpell(uint32 spellId, bool learn_prev, bool clear_ab = true);
        bool RemoveSpell(uint32 spellId, bool learn_prev, bool clear_ab = true);
        void CleanupActionBar();

        PetSpellMap     m_petSpells;
        TeachSpellMap   m_teachspells;
        AutoSpellList   m_autospells;

        void InitPetCreateSpells();
        void CheckLearning(uint32 spellid);
        uint32 GetResetTalentsCost() const;

        void  SetTP(int32 TP);
        int32 GetDispTP() const;
        uint32 GetSkillIdForPetTraining() const;
        bool CanLearnPetSpell(uint32 spellId) const;

        int32   m_TrainingPoints;
        uint32  m_resetTalentsCost;
        time_t  m_resetTalentsTime;

        uint64 const& GetAuraUpdateMask() const { return m_auraUpdateMask; }
        void SetAuraUpdateSlot(uint8 slot) { m_auraUpdateMask |= (uint64(1) << slot); }
        void SetAuraUpdateMask(uint64 mask) { m_auraUpdateMask = mask; }
        void ResetAuraUpdateMask() { m_auraUpdateMask = 0; }

        // overwrite Creature function for name localization back to WorldObject version without localization
        char const* GetNameForLocaleIdx(int32 locale_idx) const override { return WorldObject::GetNameForLocaleIdx(locale_idx); }

        bool    m_removed;                                  // prevent overwrite pet state in DB at next Pet::Update if pet already removed(saved)
    protected:
        uint32  m_focusTimer;
        uint32  m_happinessTimer;
        uint32  m_loyaltyTimer;
        PetType m_petType;
        int32   m_duration;                                 // time until unsummon (used mostly for summoned guardians and not used for controlled pets)
        int32   m_loyaltyPoints;
        int32   m_bonusdamage;
        uint64  m_auraUpdateMask;
        bool    m_loading;
        CharacterPetCache* m_pTmpCache;
        bool    m_unSummoned;                               // If this pet has already been unsummoned

    private:
        bool m_enabled;

        void SaveToDB(uint32) override { MANGOS_ASSERT(false); }
        void DeleteFromDB() override { MANGOS_ASSERT(false); }
};

inline bool Object::IsPet() const
{
    return IsCreature() && static_cast<Creature const*>(this)->IsPet();
}

inline Pet const* Object::ToPet() const
{
    return IsPet() ? static_cast<Pet const*>(this) : nullptr;
}

inline Pet* Object::ToPet()
{
    return IsPet() ? static_cast<Pet*>(this) : nullptr;
}

class UnsummonPetDelayEvent : public BasicEvent
{
public:
    UnsummonPetDelayEvent(Pet& pet, PetSaveMode mode) : BasicEvent(), m_pet(pet), m_mode(mode) { }

    bool Execute(uint64 e_time, uint32 p_time) override;

private:
    Pet& m_pet;
    PetSaveMode m_mode;
};

#endif
