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

enum PetEntry
{
    // Warlock pets
    PET_IMP             = 416,
    PET_FEL_HUNTER      = 691,
    PET_VOID_WALKER     = 1860,
    PET_SUCCUBUS        = 1863,
    PET_DOOMGUARD       = 18540,
    PET_FELGUARD        = 30146,
    PET_INCUBUS         = 184600,

    // Death Knight pets
    PET_GHOUL           = 26125,
    PET_ABOMINATION     = 106848,

    // Shaman pet
    PET_SPIRIT_WOLF     = 29264
};

struct SummonPropertiesEntry;

class TC_GAME_API TempSummon : public Creature
{
    public:
        explicit TempSummon(SummonPropertiesEntry const* properties, WorldObject* owner, bool isWorldObject);
        virtual ~TempSummon();
        void Update(uint32 diff) override;
        virtual void InitStats(WorldObject* summoner, Milliseconds duration);
        virtual void InitSummon(WorldObject* summoner);
        void UpdateObjectVisibilityOnCreate() override;
        void UpdateObjectVisibilityOnDestroy() override;
        virtual void UnSummon(uint32 msTime = 0);
        void RemoveFromWorld() override;
        void SetTempSummonType(TempSummonType type);
        void SaveToDB(uint32 /*mapid*/, std::vector<Difficulty> const& /*spawnDifficulties*/) override { }
        WorldObject* GetSummoner() const;
        Unit* GetSummonerUnit() const;
        Creature* GetSummonerCreatureBase() const;
        GameObject* GetSummonerGameObject() const;
        ObjectGuid GetSummonerGUID() const { return m_summonerGUID; }
        TempSummonType GetSummonType() const { return m_type; }
        Milliseconds GetTimer() const { return m_timer; }
        void RefreshTimer() { m_timer = m_lifetime; }
        void ModifyTimer(Milliseconds mod) { m_timer += mod; m_lifetime += mod; }
        Optional<uint32> GetCreatureIdVisibleToSummoner() const { return m_creatureIdVisibleToSummoner; }
        Optional<uint32> GetDisplayIdVisibleToSummoner() const { return m_displayIdVisibleToSummoner; }
        bool CanFollowOwner() const { return m_canFollowOwner; }
        void SetCanFollowOwner(bool can) { m_canFollowOwner = can; }

        bool IsDismissedOnFlyingMount() const { return !HasFlag(CREATURE_STATIC_FLAG_5_DONT_DISMISS_ON_FLYING_MOUNT); }
        void SetDontDismissOnFlyingMount(bool dontDismissOnFlyingMount) { _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_5_DONT_DISMISS_ON_FLYING_MOUNT, dontDismissOnFlyingMount); }

        bool IsAutoResummoned() const { return !HasFlag(CREATURE_STATIC_FLAG_6_DO_NOT_AUTO_RESUMMON); }
        void SetDontAutoResummon(bool dontAutoResummon) { _staticFlags.ApplyFlag(CREATURE_STATIC_FLAG_6_DO_NOT_AUTO_RESUMMON, dontAutoResummon); }

        SummonPropertiesEntry const* const m_Properties;

        std::string GetDebugInfo() const override;

    protected:
        std::ptrdiff_t FindUsableTotemSlot(Unit const* summoner) const;

    private:
        bool IsSharingTotemSlotWith(ObjectGuid objectGuid) const;
        TempSummonType m_type;
        Milliseconds m_timer;
        Milliseconds m_lifetime;
        ObjectGuid m_summonerGUID;
        Optional<uint32> m_creatureIdVisibleToSummoner;
        Optional<uint32> m_displayIdVisibleToSummoner;
        bool m_canFollowOwner;
};

class TC_GAME_API Minion : public TempSummon
{
    public:
        Minion(SummonPropertiesEntry const* properties, Unit* owner, bool isWorldObject);
        void InitStats(WorldObject* summoner, Milliseconds duration) override;
        void RemoveFromWorld() override;
        void setDeathState(DeathState s) override;
        Unit* GetOwner() const { return m_owner; }
        float GetFollowAngle() const override { return m_followAngle; }
        void SetFollowAngle(float angle) { m_followAngle = angle; }

        // Warlock pets
        bool IsPetImp() const { return GetEntry() == PET_IMP; }
        bool IsPetFelhunter() const { return GetEntry() == PET_FEL_HUNTER; }
        bool IsPetVoidwalker() const { return GetEntry() == PET_VOID_WALKER; }
        bool IsPetSayaad() const { return GetEntry() == PET_SUCCUBUS || GetEntry() == PET_INCUBUS; }
        bool IsPetDoomguard() const { return GetEntry() == PET_DOOMGUARD; }
        bool IsPetFelguard() const { return GetEntry() == PET_FELGUARD; }
        bool IsWarlockPet() const { return IsPetImp() || IsPetFelhunter() || IsPetVoidwalker() || IsPetSayaad() || IsPetDoomguard() || IsPetFelguard(); }

        // Death Knight pets
        bool IsPetGhoul() const { return GetEntry() == PET_GHOUL; } // Ghoul may be guardian or pet
        bool IsPetAbomination() const { return GetEntry() == PET_ABOMINATION; } // Sludge Belcher dk talent

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
        void InitStats(WorldObject* summoner, Milliseconds duration) override;
        bool InitStatsForLevel(uint8 level);
        void InitSummon(WorldObject* summoner) override;

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
        void InitStats(WorldObject* summoner, Milliseconds duration) override;
        void InitSummon(WorldObject* summoner) override;
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
