/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef SpellHistory_h__
#define SpellHistory_h__

#include "SharedDefines.h"
#include "QueryResult.h"
#include "Transaction.h"
#include <chrono>
#include <deque>

class Item;
class Player;
class Spell;
class SpellInfo;
class Unit;
struct SpellCategoryEntry;

/// Spell cooldown flags sent in SMSG_SPELL_COOLDOWN
enum SpellCooldownFlags
{
    SPELL_COOLDOWN_FLAG_NONE                    = 0x0,
    SPELL_COOLDOWN_FLAG_INCLUDE_GCD             = 0x1,  ///< Starts GCD in addition to normal cooldown specified in the packet
    SPELL_COOLDOWN_FLAG_INCLUDE_EVENT_COOLDOWNS = 0x2   ///< Starts GCD for spells that should start their cooldown on events, requires SPELL_COOLDOWN_FLAG_INCLUDE_GCD set
};

class SpellHistory
{
public:
    typedef std::chrono::system_clock Clock;

    struct CooldownEntry
    {
        CooldownEntry() : ItemId(0), OnHold(false) { }
        CooldownEntry(Clock::time_point endTime, uint32 itemId) : CooldownEnd(endTime), ItemId(itemId), OnHold(false) { }

        Clock::time_point CooldownEnd;
        uint32 ItemId;
        bool OnHold;
    };

    struct ChargeEntry
    {
        ChargeEntry() { }
        ChargeEntry(Clock::time_point startTime, std::chrono::milliseconds rechargeTime) : RechargeStart(startTime), RechargeEnd(startTime + rechargeTime) { }
        ChargeEntry(Clock::time_point startTime, Clock::time_point endTime) : RechargeStart(startTime), RechargeEnd(endTime) { }

        Clock::time_point RechargeStart;
        Clock::time_point RechargeEnd;
    };

    typedef std::unordered_map<uint32 /*spellId*/, CooldownEntry> CooldownStorageType;
    typedef std::unordered_map<uint32 /*categoryId*/, std::deque<ChargeEntry>> ChargeStorageType;
    typedef std::unordered_map<uint32 /*categoryId*/, Clock::time_point> GlobalCooldownStorageType;

    explicit SpellHistory(Unit* owner) : _owner(owner), _schoolLockouts() { }

    template<class OwnerType>
    void LoadFromDB(PreparedQueryResult cooldownsResult, PreparedQueryResult chargesResult);

    template<class OwnerType>
    void SaveToDB(SQLTransaction& trans);

    void Update();

    void HandleCooldowns(SpellInfo const* spellInfo, Item const* item, Spell* spell = nullptr);
    bool IsReady(SpellInfo const* spellInfo) const;
    template<class PacketType>
    void WritePacket(PacketType* packet) const;

    // Cooldowns
    static Clock::duration const InfinityCooldownDelay;  // used for set "infinity cooldowns" for spells and check

    void StartCooldown(SpellInfo const* spellInfo, uint32 itemId, Spell* spell = nullptr, bool onHold = false);
    void SendCooldownEvent(SpellInfo const* spellInfo, uint32 itemId = 0, Spell* spell = nullptr, bool startCooldown = true);

    template<class Type, class Period>
    void AddCooldown(uint32 spellId, uint32 itemId, std::chrono::duration<Type, Period> cooldownDuration)
    {
        AddCooldown(spellId, itemId, Clock::now() + std::chrono::duration_cast<Clock::duration>(cooldownDuration));
    }

    void AddCooldown(uint32 spellId, uint32 itemId, Clock::time_point cooldownEnd, bool onHold = false);
    void ModifyCooldown(uint32 spellId, int32 cooldownModMs);
    void ResetCooldown(uint32 spellId, bool update = false);
    void ResetCooldown(CooldownStorageType::iterator& itr, bool update = false);
    template<typename Predicate>
    void ResetCooldowns(Predicate predicate, bool update = false)
    {
        std::vector<int32> resetCooldowns;
        resetCooldowns.reserve(_spellCooldowns.size());
        for (auto itr = _spellCooldowns.begin(); itr != _spellCooldowns.end();)
        {
            if (predicate(itr))
                ResetCooldown(itr, false);
            else
                ++itr;
        }

        if (update && !resetCooldowns.empty())
            SendClearCooldowns(resetCooldowns);
    }

    void ResetAllCooldowns();
    bool HasCooldown(uint32 spellId) const;
    uint32 GetRemainingCooldown(uint32 spellId) const;

    // School lockouts
    void LockSpellSchool(SpellSchoolMask schoolMask, uint32 lockoutTime);
    bool IsSchoolLocked(SpellSchoolMask schoolMask) const;

    // Charges
    bool ConsumeCharge(SpellCategoryEntry const* chargeCategoryEntry);
    void RestoreCharge(SpellCategoryEntry const* chargeCategoryEntry);
    void ResetCharges(SpellCategoryEntry const* chargeCategoryEntry);
    void ResetAllCharges();
    bool HasCharge(SpellCategoryEntry const* chargeCategoryEntry) const;
    int32 GetMaxCharges(SpellCategoryEntry const* chargeCategoryEntry) const;
    int32 GetChargeRecoveryTime(SpellCategoryEntry const* chargeCategoryEntry) const;

    // Global cooldown
    bool HasGlobalCooldown(SpellInfo const* spellInfo) const;
    void AddGlobalCooldown(SpellInfo const* spellInfo, uint32 duration);
    void CancelGlobalCooldown(SpellInfo const* spellInfo);

private:
    Player* GetPlayerOwner() const;
    void SendClearCooldowns(std::vector<int32> const& cooldowns) const;

    Unit* _owner;
    CooldownStorageType _spellCooldowns;
    Clock::time_point _schoolLockouts[MAX_SPELL_SCHOOL];
    ChargeStorageType _categoryCharges;
    GlobalCooldownStorageType _globalCooldowns;

    template<class T>
    struct PersistenceHelper { };
};

#endif // SpellHistory_h__
