/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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
    // Warlock Pets/Minions
    ENTRY_IMP                     = 416,
    ENTRY_VOIDWALKER              = 1860,
    ENTRY_SUCCUBUS                = 1863,
    ENTRY_FELHUNTER               = 417,
    ENTRY_FELGUARD                = 17252,
    ENTRY_DOOMGUARD               = 11859,
    ENTRY_DOOMGUARD_PET           = 78158,
    ENTRY_INFERNAL                = 89,
    ENTRY_INFERNAL_LORD_OF_FLAMES = 108452,
    ENTRY_INFERNAL_PET            = 78217,
    ENTRY_WILD_IMP                = 55659,
    ENTRY_WILD_IMP_DREADSTALKER   = 99737,
    ENTRY_DREADSTALKER            = 98035,
    ENTRY_DARKGLARE               = 103673,
    ENTRY_CHAOS_TEAR              = 108493,
    ENTRY_UNSTABLE_TEAR           = 94584,
    ENTRY_SHADOWY_TEAR            = 99887,
    // Mage Pet/Minion
    ENTRY_WATER_ELEMENTAL         = 78116,
    // Shaman Pet/Minion
    ENTRY_FIRE_ELEMENTAL          = 95061,
    // Death knight Pet/Minion
    ENTRY_GHOUL                   = 26125,
    ENTRY_BLOODWORM               = 99773,
    ENTRY_RISEN_SKULKER           = 99541,
    // Monk Pet/Minion
    ENTRY_XUEN                    = 63508,
    ENTRY_NIUZAO                  = 73967,
    ENTRY_CHI_JI                  = 100868,
    // Druid Pet/Minion
    ENTRY_TREANT                  = 1964
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
        void SaveToDB(uint32 /*mapid*/, uint32 /*spawnMask*/, uint32 /*phaseMask*/) override { }
        Unit* GetSummoner() const;
        Creature* GetSummonerCreatureBase() const;
        ObjectGuid GetSummonerGUID() const { return m_summonerGUID; }
        TempSummonType const& GetSummonType() { return m_type; }
        uint32 GetTimer() const { return m_timer; }

        const SummonPropertiesEntry* const m_Properties;
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
        float GetFollowAngle() const override { return m_followAngle; }
        void SetFollowAngle(float angle) { m_followAngle = angle; }
        bool IsPetGhoul() const {return GetEntry() == 26125;} // Ghoul may be guardian or pet
        bool IsSpiritWolf() const {return GetEntry() == 29264;} // Spirit wolf from feral spirits
        bool IsGuardianPet() const;
        bool IsWarlockMinion() const;
    protected:
        Unit* const m_owner;
        float m_followAngle;
};

class TC_GAME_API Guardian : public Minion
{
    public:
        Guardian(SummonPropertiesEntry const* properties, Unit* owner, bool isWorldObject);
        void InitStats(uint32 duration) override;
        bool InitStatsForLevel(uint8 level);
        void InitSummon() override;

        bool UpdateAllStats() override;
        void UpdateResistances(uint32 school) override;
        void UpdateArmor() override;
        void UpdateMaxHealth() override;
        void UpdateMaxPower(Powers power) override;
        void UpdateAttackPowerAndDamage(bool ranged = false) override;
        void UpdateDamagePhysical(WeaponAttackType attType) override;
        void UpdateSpellPower();

        int32 GetBonusDamage() const { return m_bonusSpellDamage; }
        void SetBonusDamage(int32 damage);
        void UpdatePlayerFieldModPetHaste();
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
