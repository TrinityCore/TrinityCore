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

#ifndef TRINITYCORE_TEMPSUMMON_H
#define TRINITYCORE_TEMPSUMMON_H

#include "Creature.h"

struct SummonPropertiesEntry;

enum PetEntries
{
    // Warlock Pet/Minions
    ENTRY_IMP                       = 416,
    ENTRY_VOIDWALKER                = 1860,
    ENTRY_SUCCUBUS                  = 1863,
    ENTRY_FELHUNTER                 = 417,
    ENTRY_FELGUARD                  = 17252,
    ENTRY_INFERNAL                  = 89,
    ENTRY_EBON_IMP                  = 50675,

    // Mage Pet
    ENTRY_WATER_ELEMENTAL           = 510,

    // Druid Minion
    ENTRY_TREANT                    = 1964,

    // Shaman Minions
    ENTRY_EARTH_ELEMENTAL           = 15352,
    ENTRY_FIRE_ELEMENTAL            = 15438,
    ENTRY_SPIRIT_WOLF               = 29264,

    // Death Knight Pet/Minions
    ENTRY_GHOUL                     = 26125,
    ENTRY_RISEN_ALLY                = 30230,
    ENTRY_BLOODWORM                 = 28017,
    ENTRY_RUNIC_WEAPON              = 27893,
    ENTRY_GARGOYLE                  = 27829,
    ENTRY_SHADOWFIEND               = 19668,
    ENTRY_ARMY_OF_THE_DEAD_GHOUL    = 24207,

    // Hunter Trap Adds
    ENTRY_VENOMOUS_SNAKE            = 19833,
    ENTRY_VIPER                     = 19921
};

enum PlayerPetSpells
{
    // Risen Ghoul
    SPELL_PET_RISEN_GHOUL_SPAWN_IN  = 47448,
    SPELL_PET_RISEN_GHOUL_SELF_STUN = 47466,

    // Hunter Pets
    SPELL_PET_ENERGIZE              = 99289
};

class TC_GAME_API TempSummon : public Creature
{
    public:
        explicit TempSummon(SummonPropertiesEntry const* properties, Unit* owner, bool isWorldObject);
        virtual ~TempSummon() { }
        void Update(uint32 time) override;
        virtual void InitStats(uint32 lifetime);
        virtual void InitSummon();
        void UpdateObjectVisibilityOnCreate() override;
        virtual void UnSummon(uint32 msTime = 0);
        void RemoveFromWorld() override;
        void SetTempSummonType(TempSummonType type);
        void SaveToDB(uint32 /*mapid*/, uint8 /*spawnMask*/) override { }
        Unit* GetSummoner() const;
        Creature* GetSummonerCreatureBase() const;
        ObjectGuid GetSummonerGUID() const { return m_summonerGUID; }
        TempSummonType const& GetSummonType() { return m_type; }
        uint32 GetTimer() const { return m_timer; }

        SummonPropertiesEntry const* const m_Properties;
    private:
        TempSummonType m_type;
        uint32 m_timer;
        uint32 m_lifetime;
        ObjectGuid m_summonerGUID;
};

class TC_GAME_API Minion : public TempSummon
{
    public:
        Minion(SummonPropertiesEntry const* properties, Unit* owner, bool isWorldObject);
        void InitStats(uint32 duration) override;
        void RemoveFromWorld() override;
        Unit* GetOwner() const { return m_owner; }
        bool IsPetGhoul() const { return GetEntry() == ENTRY_GHOUL; } // Ghoul may be guardian or pet
        bool IsRisenAlly() const { return GetEntry() == ENTRY_RISEN_ALLY; }
        bool IsSpiritWolf() const { return GetEntry() == ENTRY_SPIRIT_WOLF; } // Spirit wolf from feral spirits
        bool IsGuardianPet() const;
        bool IsWarlockMinion() const;
    protected:
        Unit* const m_owner;
};

class TC_GAME_API Guardian : public Minion
{
    public:
        Guardian(SummonPropertiesEntry const* properties, Unit* owner, bool isWorldObject);
        void InitStats(uint32 duration) override;
        bool InitStatsForLevel(uint8 level);
        void InitSummon() override;

        bool UpdateStats(Stats stat) override;
        bool UpdateAllStats() override;
        void UpdateResistances(uint32 school) override;
        void UpdateArmor() override;
        void UpdateMaxHealth() override;
        void UpdateMaxPower(Powers power) override;
        void UpdateAttackPowerAndDamage(bool ranged = false) override;
        void UpdateDamagePhysical(WeaponAttackType attType) override;

        int32 GetBonusDamage() const { return m_bonusSpellDamage; }
        float GetBonusStatFromOwner(Stats stat) const { return m_statFromOwner[stat]; }
        void SetBonusDamage(int32 damage);
    protected:
        int32   m_bonusSpellDamage;
        float   m_statFromOwner[MAX_STATS];
};

class TC_GAME_API Puppet : public Minion
{
    public:
        Puppet(SummonPropertiesEntry const* properties, Unit* owner);
        void InitStats(uint32 duration) override;
        void InitSummon() override;
        void Update(uint32 time) override;
        void RemoveFromWorld() override;
};

class TC_GAME_API ForcedUnsummonDelayEvent : public BasicEvent
{
public:
    ForcedUnsummonDelayEvent(TempSummon& owner) : BasicEvent(), m_owner(owner) { }
    bool Execute(uint64 e_time, uint32 p_time) override;

private:
    TempSummon& m_owner;
};
#endif
