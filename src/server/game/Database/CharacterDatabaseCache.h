#ifndef _CHARACTER_DATABASE_CACHE_H
#define _CHARACTER_DATABASE_CACHE_H

#include "Common.h"
#include "ObjectGuid.h"
#include "DBCEnums.h"

// pet_spell_cooldown
struct PetSpellCoodown
{
    uint32 spell = 0;
    uint64 time = 0;
};

typedef std::vector<PetSpellCoodown> PetSpellCDs;

// pet_spell
struct PetSpellCache
{
    uint32 spell = 0;
    uint8  active = 0;
};
typedef std::vector<PetSpellCache> PetSpells;

struct AuraSaveStruct
{
    ObjectGuid casterGuid = 0;
    uint32 itemLowGuid = 0;
    uint32 spellId = 0;
    uint32 stacks = 0;
    uint32 charges = 0;
    float  damage[MAX_EFFECT_INDEX] = { 0 };
    uint32 periodicTime[MAX_EFFECT_INDEX] = { 0 };
    int32 maxDuration = 0;
    int32 duration = 0;
    uint8 effIndexMask = 0;
};

// pet_aura
typedef AuraSaveStruct PetAuraCache;
typedef std::vector<PetAuraCache> PetAuras;

struct CharacterPetCache
{
    // character_pet
    uint32 id = 0;
    uint32 entry = 0;
    uint32 displayId = 0;
    uint32 level = 0;
    uint32 xp = 0;
    uint32 loyalty = 0;
    uint32 slot = 0;
    uint32 currentHealth = 0;
    uint32 currentMana = 0;
    uint32 currentHappiness = 0;
    uint32 resetTalentsCost = 0;
    uint32 resetTalentsTime = 0;
    uint32 createdBySpell = 0;
    uint32 petType = 0;
    int32 trainingPoints = 0;
    int32 loyaltyPoints = 0;;
    uint32 ownerGuid = 0;
    uint64 saveTime = 0;
    uint8 reactState = 0;
    std::string name, actionBarData, teachSpellData;
    bool renamed = false;
    // pet_spell
    PetSpells   spells;
    // pet_spell_cooldown
    PetSpellCDs spellCooldowns;
    // pet_aura
    PetAuras    auras;
};

typedef std::vector<CharacterPetCache*> CharPetVector;
typedef std::map<uint32 /*owner guid*/, CharPetVector> CharPetMap;
typedef std::map<uint32 /*pet guid*/, CharacterPetCache*> PetGuidToPetMap;

class CharacterDatabaseCache
{
    public:
        CharacterDatabaseCache();
        ~CharacterDatabaseCache();

        static CharacterDatabaseCache* instance()
        {
            static CharacterDatabaseCache* i = new CharacterDatabaseCache();
            return i;
        }
        void LoadAll(uint32 singlePetId = 0);

        void LoadCharacterPet(uint32 singlePetId);
        void LoadPetSpell(uint32 singlePetId);
        void LoadPetSpellCooldown(uint32 singlePetId);
        void LoadPetAura(uint32 singlePetId);

        CharacterPetCache* GetCharacterPetCacheByOwnerAndId(uint32 ownerGuidLow, uint32 id);
        CharacterPetCache* GetCharacterCurrentPet(uint32 owner);
        CharacterPetCache* GetCharacterPetByOwnerAndEntry(uint32 owner, uint32 entry);
        CharacterPetCache* GetCharacterPetByOwner(uint32 owner);
        CharacterPetCache* GetCharacterPetById(uint32 id); // Very slow method (iterates over all the stored pets)
        void CharacterPetSetOthersNotInSlot(CharacterPetCache* pCache);
        void InsertCharacterPet(CharacterPetCache* cache);
        void DeleteCharacterPetById(uint32 id);
        CharPetMap const& GetCharPetsMap() const { return m_petsByCharacter; }
        uint32 GetNextAvailablePetNumber(uint32 minimumValue) const;

    protected:
        // @TODO: Lock these structures for thread safety, and process stable opcodes per map
        CharPetMap      m_petsByCharacter;
        PetGuidToPetMap m_petsByGuid;

};

#define sCharacterDatabaseCache (*(CharacterDatabaseCache::instance()))


#endif
