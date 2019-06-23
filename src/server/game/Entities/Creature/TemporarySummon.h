/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

enum PetEntry : uint32
{
    // Death Knight pets
    PET_GHOUL           = 26125,
    PET_RISEN_ALLY      = 30230,

    // Shaman pet
    PET_SPIRIT_WOLF     = 29264
};

struct SummonPropertiesEntry;

class TC_GAME_API TempSummon : public Creature
{
    public:
        explicit TempSummon(SummonPropertiesEntry const* properties, WorldObject* owner, bool isWorldObject);
        virtual ~TempSummon() { }
        void Update(uint32 time) override;
        virtual void InitStats(uint32 lifetime);
        virtual void InitSummon();
        void UpdateObjectVisibilityOnCreate() override;
        virtual void UnSummon(uint32 msTime = 0);
        void RemoveFromWorld() override;
        void SetTempSummonType(TempSummonType type);
        void SaveToDB(uint32 /*mapid*/, uint8 /*spawnMask*/, uint32 /*phaseMask*/) override { }
        WorldObject* GetSummoner() const;
        Unit* GetSummonerUnit() const;
        Creature* GetSummonerCreatureBase() const;
        GameObject* GetSummonerGameObject() const;
        ObjectGuid GetSummonerGUID() const { return m_summonerGUID; }
        TempSummonType GetSummonType() const { return m_type; }
        uint32 GetTimer() const { return m_timer; }

        SummonPropertiesEntry const* const m_Properties;

        std::string GetDebugInfo() const override;
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
        void setDeathState(DeathState s) override;
        Unit* GetOwner() const { return m_owner; }
        float GetFollowAngle() const override { return m_followAngle; }
        void SetFollowAngle(float angle) { m_followAngle = angle; }

        // Death Knight pets
        bool IsPetGhoul() const { return GetEntry() == PET_GHOUL; } // Ghoul may be guardian or pet
        bool IsRisenAlly() const { return GetEntry() == PET_RISEN_ALLY; }

        // Shaman pet
        bool IsSpiritWolf() const { return GetEntry() == PET_SPIRIT_WOLF; } // Spirit wolf from feral spirits

        bool IsGuardianPet() const;

        std::string GetDebugInfo() const override;
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
        std::string GetDebugInfo() const override;
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
