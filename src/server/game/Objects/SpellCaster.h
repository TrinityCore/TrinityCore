/*
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

#ifndef _SPELL_CASTER_OBJECT_H
#define _SPELL_CASTER_OBJECT_H

#include "Object.h"
#include "SpellDefines.h"
#include "Utilities/EventProcessor.h"
#include "nonstd/optional.hpp"
#include <array>
#include <memory>

using nonstd::optional;

class Aura;
class ChatHandler;
class DynamicObject;
class Item;
class Spell;
class SpellCaster;
class SpellEntry;
struct ItemPrototype;

// At least some values expected fixed and used in auras field, other custom
enum MeleeHitOutcome
{
    MELEE_HIT_EVADE = 0,
    MELEE_HIT_MISS = 1,
    MELEE_HIT_DODGE = 2,                                // used as misc in SPELL_AURA_IGNORE_COMBAT_RESULT
    MELEE_HIT_BLOCK = 3,                                // used as misc in SPELL_AURA_IGNORE_COMBAT_RESULT
    MELEE_HIT_PARRY = 4,                                // used as misc in SPELL_AURA_IGNORE_COMBAT_RESULT
    MELEE_HIT_GLANCING = 5,
    MELEE_HIT_CRIT = 6,
    MELEE_HIT_CRUSHING = 7,
    MELEE_HIT_NORMAL = 8,
    MELEE_HIT_BLOCK_CRIT = 9,
};

// Spell damage info structure based on structure sending in SMSG_SPELLNONMELEEDAMAGELOG opcode
struct SpellNonMeleeDamage {
    SpellNonMeleeDamage(SpellCaster* _attacker, Unit* _target, uint32 _SpellID, SpellSchools _school)
        : target(_target), attacker(_attacker), SpellID(_SpellID), damage(0), school(_school),
        absorb(0), resist(0), periodicLog(false), unused(false), blocked(0), HitInfo(0), spell(nullptr)
    {}

    Unit* target;
    SpellCaster* attacker;
    uint32 SpellID;
    uint32 damage;
    SpellSchools school;
    uint32 absorb;
    int32 resist;
    bool   periodicLog;
    bool   unused;
    uint32 blocked;
    uint32 HitInfo;
    Spell* spell;
};

struct CleanDamage
{
    CleanDamage(uint32 _damage, WeaponAttackType _attackType, MeleeHitOutcome _hitOutCome, uint32 _Absorb, int32 _Resist) :
    damage(_damage), attackType(_attackType), hitOutCome(_hitOutCome), absorb(_Absorb), resist(_Resist) {}

    uint32 damage;
    WeaponAttackType attackType;
    MeleeHitOutcome hitOutCome;
    uint32 absorb;
    int32 resist;
};

enum CurrentSpellTypes
{
    CURRENT_MELEE_SPELL             = 0,
    CURRENT_GENERIC_SPELL           = 1,
    CURRENT_AUTOREPEAT_SPELL        = 2,
    CURRENT_CHANNELED_SPELL         = 3
};

#define CURRENT_FIRST_NON_MELEE_SPELL 1
#define CURRENT_MAX_SPELL             4

class CooldownData
{
        friend class CooldownContainer;
    public:
        CooldownData(TimePoint clockNow, uint32 spellId, uint32 duration, uint32 spellCategory, uint32 categoryDuration, uint32 itemId = 0, bool isPermanent = false) :
            m_spellId(spellId),
            m_category(spellCategory),
            m_expireTime(duration ? std::chrono::milliseconds(duration) + clockNow : TimePoint()),
            m_catExpireTime(spellCategory && categoryDuration ? std::chrono::milliseconds(categoryDuration) + clockNow : TimePoint()),
            m_typePermanent(isPermanent),
            m_itemId(itemId)
        {}

        // return false if permanent
        bool GetSpellCDExpireTime(TimePoint& expireTime) const
        {
            if (m_typePermanent)
                return false;

            expireTime = m_expireTime;
            return true;
        }

        // return false if permanent
        bool GetCatCDExpireTime(TimePoint& expireTime) const
        {
            if (m_typePermanent)
                return false;

            expireTime = m_catExpireTime;
            return true;
        }

        bool IsSpellCDExpired(TimePoint const& now) const
        {
            if (m_typePermanent)
                return false;

            return now >= m_expireTime;
        }

        bool IsCatCDExpired(TimePoint const& now) const
        {
            if (m_typePermanent)
                return false;

            if (!m_category)
                return true;

            if (now >= m_catExpireTime)
                return true;

            return false;
        }

        bool IsPermanent() const { return m_typePermanent; }
        uint32 GetItemId() const { return m_itemId; }
        uint32 GetSpellId() const { return m_spellId; }
        uint32 GetCategory() const { return m_category; }

    private:
        uint32            m_spellId;
        uint32            m_category;
        TimePoint         m_expireTime;
        TimePoint         m_catExpireTime;
        bool              m_typePermanent;
        uint32            m_itemId;
};

typedef std::unique_ptr<CooldownData> CooldownDataUPTR;
typedef std::map<uint32, TimePoint> GCDMap;
typedef std::map<SpellSchools, TimePoint> LockoutMap;

class CooldownContainer
{
    public:
        typedef std::map<uint32, CooldownDataUPTR> spellIdMap;
        typedef spellIdMap::const_iterator ConstIterator;
        typedef spellIdMap::iterator Iterator;
        typedef std::map<uint32, ConstIterator> categoryMap;

        void Update(TimePoint const& now)
        {
            auto spellCDItr = m_spellIdMap.begin();
            while (spellCDItr != m_spellIdMap.end())
            {
                auto& cd = spellCDItr->second;
                if (cd->IsSpellCDExpired(now) && cd->IsCatCDExpired(now)) // will not remove permanent CD
                    spellCDItr = erase(spellCDItr);
                else
                {
                    if (cd->m_category && cd->IsCatCDExpired(now))
                        m_categoryMap.erase(cd->m_category);
                    ++spellCDItr;
                }
            }
        }

        bool AddCooldown(TimePoint clockNow, uint32 spellId, uint32 duration, uint32 spellCategory = 0, uint32 categoryDuration = 0, uint32 itemId = 0, bool onHold = false)
        {
            auto resultItr = m_spellIdMap.emplace(spellId, std::unique_ptr<CooldownData>(new CooldownData(clockNow, spellId, duration, spellCategory, categoryDuration, itemId, onHold)));
            if (resultItr.second && spellCategory && categoryDuration)
                m_categoryMap.emplace(spellCategory, resultItr.first);

            return resultItr.second;
        }

        void RemoveBySpellId(uint32 spellId)
        {
            auto spellCDItr = m_spellIdMap.find(spellId);
            if (spellCDItr != m_spellIdMap.end())
            {
                auto& cdData = spellCDItr->second;
                if (cdData->m_category)
                {
                    auto catCDItr = m_categoryMap.find(cdData->m_category);
                    if (catCDItr != m_categoryMap.end())
                        m_categoryMap.erase(catCDItr);
                }
                m_spellIdMap.erase(spellCDItr);
            }
        }

        void RemoveByCategory(uint32 category)
        {
            auto spellCDItr = m_categoryMap.find(category);
            if (spellCDItr != m_categoryMap.end())
                m_categoryMap.erase(spellCDItr);
        }

        Iterator erase(ConstIterator spellCDItr)
        {
            auto& cdData = spellCDItr->second;
            if (cdData->m_category)
            {
                auto catCDItr = m_categoryMap.find(cdData->m_category);
                if (catCDItr != m_categoryMap.end())
                    m_categoryMap.erase(catCDItr);
            }
            return m_spellIdMap.erase(spellCDItr);
        }

        ConstIterator FindBySpellId(uint32 id) const { return m_spellIdMap.find(id); }

        ConstIterator FindByCategory(uint32 category) const
        {
            auto itr = m_categoryMap.find(category);
            return itr != m_categoryMap.end() ? itr->second : end();
        }

        void clear() { m_spellIdMap.clear(); m_categoryMap.clear(); }

        ConstIterator begin() const { return m_spellIdMap.begin(); }
        ConstIterator end() const { return m_spellIdMap.end(); }
        bool IsEmpty() const { return m_spellIdMap.empty(); }
        size_t size() const { return m_spellIdMap.size(); }

    private:
        spellIdMap m_spellIdMap;
        categoryMap m_categoryMap;
};

// Unit* victim, uint32 procAttacker, uint32 procVictim, uint32 procExtra, uint32 amount, WeaponAttackType attType, SpellEntry const* procSpell, bool dontTriggerSpecial

// External struct for passing on data
struct SpellModifier;
struct ProcSystemArguments
{
    Unit* pVictim;
    ObjectGuid victimGuid;

    uint32 procFlagsAttacker;
    uint32 procFlagsVictim;
    uint32 procExtra;

    uint32 amount; // contains full heal or full damage
    SpellEntry const* procSpell;
    WeaponAttackType attType;

    std::list<SpellModifier*> appliedSpellModifiers; // don't dereference pointers
    bool isSpellTriggeredByAura;

    explicit ProcSystemArguments(Unit* pVictim_, uint32 procFlagsAttacker_, uint32 procFlagsVictim_, uint32 procExtra_, uint32 amount_, WeaponAttackType attType_ = BASE_ATTACK,
        SpellEntry const* procSpell_ = nullptr, Spell const* spell = nullptr);
};

// Intermediary absract class to hold all the common spell casting method between Units and GameObjects.
class SpellCaster : public WorldObject
{
public:
    virtual uint32 GetLevel() const = 0;
    uint32 GetLevelForTarget(SpellCaster const* target = nullptr) const;
    uint16 GetSkillMaxForLevel(SpellCaster const* target = nullptr) const { return GetLevelForTarget(target) * 5; };
    uint32 GetWeaponSkillValue(WeaponAttackType attType, SpellCaster const* target = nullptr) const;
    uint32 GetUnitMeleeSkill(SpellCaster const* target = nullptr) const { return GetLevelForTarget(target) * 5; }
    uint32 GetDefenseSkillValue(SpellCaster const* target = nullptr) const;

    Unit* SelectMagnetTarget(Unit* victim, Spell* spell = nullptr, SpellEffectIndex eff = EFFECT_INDEX_0);
    SpellCastResult CastSpell(SpellCaster* pTarget, uint32 spellId, bool triggered, Item* castItem = nullptr, Aura* triggeredByAura = nullptr, ObjectGuid originalCaster = ObjectGuid(), SpellEntry const* triggeredBy = nullptr, SpellEntry const* triggeredByParent = nullptr);
    SpellCastResult CastSpell(SpellCaster* pTarget, SpellEntry const* spellInfo, bool triggered, Item* castItem = nullptr, Aura* triggeredByAura = nullptr, ObjectGuid originalCaster = ObjectGuid(), SpellEntry const* triggeredBy = nullptr, SpellEntry const* triggeredByParent = nullptr);
    void CastCustomSpell(Unit* pTarget, uint32 spellId, optional<int32> bp0, optional<int32> bp1, optional<int32> bp2, bool triggered, Item* castItem = nullptr, Aura* triggeredByAura = nullptr, ObjectGuid originalCaster = ObjectGuid(), SpellEntry const* triggeredBy = nullptr);
    void CastCustomSpell(Unit* pTarget, SpellEntry const* spellInfo, optional<int32> bp0, optional<int32> bp1, optional<int32> bp2, bool triggered, Item* castItem = nullptr, Aura* triggeredByAura = nullptr, ObjectGuid originalCaster = ObjectGuid(), SpellEntry const* triggeredBy = nullptr);
    SpellCastResult CastSpell(float x, float y, float z, uint32 spellId, bool triggered, Item* castItem = nullptr, Aura* triggeredByAura = nullptr, ObjectGuid originalCaster = ObjectGuid(), SpellEntry const* triggeredBy = nullptr);
    SpellCastResult CastSpell(float x, float y, float z, SpellEntry const* spellInfo, bool triggered, Item* castItem = nullptr, Aura* triggeredByAura = nullptr, ObjectGuid originalCaster = ObjectGuid(), SpellEntry const* triggeredBy = nullptr);

    void SetCurrentCastedSpell(Spell* pSpell);
    Spell* GetCurrentSpell(CurrentSpellTypes spellType) const { return m_currentSpells[spellType]; }
    Spell* FindCurrentSpellBySpellId(uint32 spell_id) const;
    bool CheckAndIncreaseCastCounter();
    void DecreaseCastCounter() { if (m_castCounter) --m_castCounter; }

    // set withDelayed to true to account delayed spells as casted
    // delayed+channeled spells are always accounted as casted
    // we can skip channeled or delayed checks using flags
    bool IsNonMeleeSpellCasted(bool withDelayed = false, bool skipChanneled = false, bool skipAutorepeat = false) const;
    bool IsNextSwingSpellCasted() const;
    // for movement generators, check if current casted spell has movement interrupt flags
    bool IsNoMovementSpellCasted() const;

    // set withDelayed to true to interrupt delayed spells too
    // delayed+channeled spells are always interrupted
    void InterruptNonMeleeSpells(bool withDelayed, uint32 spellid = 0);
    void InterruptSpellsWithInterruptFlags(uint32 flags, uint32 except = 0);
    void InterruptSpellsWithChannelFlags(uint32 flags, uint32 except = 0);
    void InterruptSpell(CurrentSpellTypes spellType, bool withDelayed = true);
    void FinishSpell(CurrentSpellTypes spellType, bool ok = true);

    virtual bool IsSpellCrit(Unit const* pVictim, SpellEntry const* spellProto, SpellSchoolMask schoolMask, WeaponAttackType attackType = BASE_ATTACK, Spell* spell = nullptr) const { return false; }
    float SpellCriticalHealingBonus(SpellEntry const* spellProto, uint32 damage, Unit const* pVictim) const;
    uint32 SpellCriticalDamageBonus(SpellEntry const* spellProto, uint32 damage, Unit* pVictim, Spell* spell = nullptr);
    float  MeleeSpellMissChance(Unit* pVictim, WeaponAttackType attType, int32 skillDiff, SpellEntry const* spell, Spell* spellPtr = nullptr);
    SpellMissInfo MeleeSpellHitResult(Unit* pVictim, SpellEntry const* spell, Spell* spellPtr = nullptr);
    SpellMissInfo MagicSpellHitResult(Unit* pVictim, SpellEntry const* spell, Spell* spellPtr = nullptr);
    int32 MagicSpellHitChance(Unit* pVictim, SpellEntry const* spell, Spell* spellPtr = nullptr);
    float GetSpellResistChance(Unit const* victim, uint32 schoolMask, bool innateResists) const;
    SpellMissInfo SpellHitResult(Unit* pVictim, SpellEntry const* spell, SpellEffectIndex effIndex, bool canReflect = false, Spell* spellPtr = nullptr);
    void UpdatePendingProcs(uint32 diff);
    void ProcDamageAndSpell(ProcSystemArguments&& data);
    void ProcDamageAndSpell_real(ProcSystemArguments& data);
    void ProcDamageAndSpell_delayed(ProcSystemArguments& data);
    void CalculateSpellDamage(SpellNonMeleeDamage* damageInfo, float damage, SpellEntry const* spellInfo, SpellEffectIndex effectIndex, WeaponAttackType attackType = BASE_ATTACK, Spell* spell = nullptr);
    float CalculateSpellEffectValue(Unit const* target, SpellEntry const* spellProto, SpellEffectIndex effect_index, int32 const* basePoints = nullptr, Spell* spell = nullptr) const;
    float SpellBonusWithCoeffs(SpellEntry const* spellProto, SpellEffectIndex effectIndex, float total, float benefit, float ap_benefit, DamageEffectType damagetype, bool donePart, SpellCaster* pCaster, Spell* spell = nullptr) const;
    static float CalculateLevelPenalty(SpellEntry const* spellProto);
    float SpellDamageBonusDone(Unit* pVictim, SpellEntry const* spellProto, SpellEffectIndex effectIndex, float pdamage, DamageEffectType damagetype, uint32 stack = 1, Spell* spell = nullptr);
    int32 SpellBaseDamageBonusDone(SpellSchoolMask schoolMask);
    float SpellHealingBonusDone(Unit* pVictim, SpellEntry const* spellProto, SpellEffectIndex effectIndex, float healamount, DamageEffectType damagetype, uint32 stack = 1, Spell* spell = nullptr);
    float SpellBaseHealingBonusDone(SpellSchoolMask schoolMask);
    float CalcArmorReducedDamage(Unit* pVictim, uint32 const damage) const;
    float MeleeDamageBonusDone(Unit* pVictim, float damage, WeaponAttackType attType, SpellEntry const* spellProto = nullptr, SpellEffectIndex effectIndex = EFFECT_INDEX_0, DamageEffectType damagetype = DIRECT_DAMAGE, uint32 stack = 1, Spell* spell = nullptr, bool flat = true);
    virtual SpellSchoolMask GetMeleeDamageSchoolMask() const;
    float GetAPMultiplier(WeaponAttackType attType, bool normalized) const;
    virtual uint32 DealDamage(Unit* pVictim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellSchoolMask damageSchoolMask, SpellEntry const* spellProto, bool durabilityLoss, Spell* spell = nullptr);
    void DealDamageMods(Unit* pVictim, uint32& damage, uint32* absorb);
    void DealSpellDamage(SpellNonMeleeDamage* damageInfo, bool durabilityLoss);
    void SendSpellNonMeleeDamageLog(SpellNonMeleeDamage* log);
    void SendSpellNonMeleeDamageLog(Unit* target, uint32 spellId, uint32 damage, SpellSchoolMask damageSchoolMask, uint32 absorbedDamage, int32 resist, bool isPeriodic, uint32 blocked, bool criticalHit = false, bool split = false);
    void SendSpellMiss(Unit* target, uint32 spellId, SpellMissInfo missInfo);
    void SendSpellOrDamageImmune(Unit* target, uint32 spellId) const;
    int32 DealHeal(Unit* pVictim, uint32 addhealth, SpellEntry const* spellProto, bool critical = false);
    void SendHealSpellLog(Unit const* pVictim, uint32 SpellID, uint32 Damage, bool critical = false) const;
    void EnergizeBySpell(Unit* pVictim, uint32 SpellID, uint32 Damage, Powers powertype);
    void SendEnergizeSpellLog(Unit const* pVictim, uint32 SpellID, uint32 Damage, Powers powertype) const;

    void GetDynObjects(uint32 spellId, SpellEffectIndex effectIndex, std::vector<DynamicObject*>& dynObjsOut);
    DynamicObject* GetDynObject(uint32 spellId, SpellEffectIndex effIndex);
    DynamicObject* GetDynObject(uint32 spellId);
    void AddDynObject(DynamicObject* dynObj);
    void RemoveDynObject(uint32 spellid);
    void RemoveDynObjectWithGUID(ObjectGuid guid) { m_dynObjGUIDs.remove(guid); }
    void RemoveAllDynObjects();

    // cooldown system
    virtual void AddGCD(SpellEntry const& spellEntry, uint32 forcedDuration = 0, bool updateClient = false);
    virtual bool HasGCD(SpellEntry const* spellEntry) const;
    void ResetGCD(SpellEntry const* spellEntry = nullptr);
    virtual void AddCooldown(SpellEntry const& spellEntry, ItemPrototype const* itemProto = nullptr, bool permanent = false, uint32 forcedDuration = 0);
    virtual void RemoveSpellCooldown(SpellEntry const& spellEntry, bool updateClient = true);
    void RemoveSpellCooldown(uint32 spellId, bool updateClient = true);
    virtual void RemoveSpellCategoryCooldown(uint32 category, bool updateClient = true);
    virtual void RemoveAllCooldowns(bool /*sendOnly*/ = false) { m_GCDCatMap.clear(); m_cooldownMap.clear(); m_lockoutMap.clear(); }
    bool IsSpellReady(SpellEntry const& spellEntry, ItemPrototype const* itemProto = nullptr) const;
    bool IsSpellReady(uint32 spellId, ItemPrototype const* itemProto = nullptr) const;
    virtual void LockOutSpells(SpellSchoolMask schoolMask, uint32 duration);
    void PrintCooldownList(ChatHandler& chat) const;
    bool CheckLockout(SpellSchoolMask schoolMask) const;

    // Event handler
    EventProcessor m_Events;
protected:
    explicit SpellCaster() = default;

    // cooldown system
    void UpdateCooldowns(TimePoint const& now);
    bool GetExpireTime(SpellEntry const& spellEntry, TimePoint& expireTime, bool& isPermanent) const;

    GCDMap            m_GCDCatMap;
    LockoutMap        m_lockoutMap;
    CooldownContainer m_cooldownMap;

    typedef std::list<ObjectGuid> DynObjectGUIDs;
    DynObjectGUIDs m_dynObjGUIDs;

    uint32 m_procsUpdateTimer = 0;
    std::vector<ProcSystemArguments> m_pendingProcChecks;
    std::array<Spell*, CURRENT_MAX_SPELL> m_currentSpells{};
    uint32 m_castCounter = 0;                           // count casts chain of triggered spells for prevent infinity cast crashes
private:
    // Error traps for some wrong args using
    // this will catch and prevent build for any cases when all optional args skipped and instead triggered used non boolean type
    // no bodies expected for this declarations
    template <typename TR>
    SpellCastResult CastSpell(SpellCaster* Victim, uint32 spell, TR triggered);
    template <typename TR>
    SpellCastResult CastSpell(SpellCaster* Victim, SpellEntry const* spell, TR triggered);
    template <typename TR>
    void CastCustomSpell(Unit* Victim, uint32 spell, optional<int32> bp0, optional<int32> bp1, optional<int32> bp2, TR triggered);
    template <typename SP, typename TR>
    void CastCustomSpell(Unit* Victim, SpellEntry const* spell, optional<int32> bp0, optional<int32> bp1, optional<int32> bp2, TR triggered);
    template <typename TR>
    SpellCastResult CastSpell(float x, float y, float z, uint32 spell, TR triggered);
    template <typename TR>
    SpellCastResult CastSpell(float x, float y, float z, SpellEntry const* spell, TR triggered);
};

inline SpellCaster* Object::ToSpellCaster()
{
    return IsSpellCaster() ? static_cast<SpellCaster*>(this) : nullptr;
}

inline SpellCaster const* Object::ToSpellCaster() const
{
    return IsSpellCaster() ? static_cast<SpellCaster const*>(this) : nullptr;
}

inline SpellCaster* ToSpellCaster(Object* object)
{
    return object && object->IsSpellCaster() ? static_cast<SpellCaster*>(object) : nullptr;
}

inline SpellCaster const* ToSpellCaster(Object const* object)
{
    return object && object->IsSpellCaster() ? static_cast<SpellCaster const*>(object) : nullptr;
}

#endif
