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

#ifndef __UNIT_H
#define __UNIT_H

#include "Common.h"
#include "SharedDefines.h"
#include "ItemPrototype.h"
#include "SpellCaster.h"
#include "UnitDefines.h"
#include "SpellAuraDefines.h"
#include "UpdateFields.h"
#include "ThreatManager.h"
#include "HostileRefManager.h"
#include "FollowerReference.h"
#include "FollowerRefManager.h"
#include "MotionMaster.h"
#include <list>

struct FactionTemplateEntry;
struct Modifier;
struct SpellModifier;

class WorldPacket;
class SpellEntry;
class Aura;
class SpellAuraHolder;
class Creature;
class Spell;
class GameObject;
class Item;
class Pet;
class PetAura;
class Totem;
class CreatureAI;

namespace Movement
{
    class MoveSpline;
}

struct PlayerMovementPendingChange
{
    uint32 movementCounter = 0;
    MovementChangeType movementChangeType = INVALID;
    uint32 time = 0;
    float newValue = 0.0f; // used if speed or height change
    bool apply = false; // used if movement flag change
    bool resent = false; // sending change again because client didn't reply
    ObjectGuid controller;

    struct KnockbackInfo
    {
        float vcos = 0.0f;
        float vsin = 0.0f;
        float speedXY = 0.0f;
        float speedZ = 0.0f;
    } knockbackInfo; // used if knockback

    PlayerMovementPendingChange();
};

/**
 * Structure to keep track of diminishing returns, for more information
 * about the idea behind diminishing returns, see: http://www.wowwiki.com/Diminishing_returns
 * \see Unit::GetDiminishing
 * \see Unit::IncrDiminishing
 * \see Unit::ApplyDiminishingToDuration
 * \see Unit::ApplyDiminishingAura
 */
struct DiminishingReturn
{
    DiminishingReturn(DiminishingGroup group, uint32 t, uint32 count)
        : DRGroup(group), stack(0), hitTime(t), hitCount(count)
    {}

    /**
     * Group that this diminishing return will affect
     */
    DiminishingGroup        DRGroup:16;
    /**
     * Seems to be how many times this has been stacked, modified in
     * Unit::ApplyDiminishingAura
     */
    uint16                  stack:16;
    /**
     * Records at what time the last hit with this DiminishingGroup was done, if it's
     * higher than 15 seconds (ie: 15 000 ms) the DiminishingReturn::hitCount will be reset
     * to DiminishingLevels::DIMINISHING_LEVEL_1, which will do no difference to the duration
     * of the stun etc.
     */
    uint32                  hitTime;
    /**
     * Records how many times a spell of this DiminishingGroup has hit, this in turn
     * decides how how long the duration of the stun etc is.
     */
    uint32                  hitCount;
};

struct WeaponDamageInfo
{
    float damage[2];
    SpellSchools school;
};

struct SubDamageInfo
{
    SpellSchoolMask damageSchoolMask = SPELL_SCHOOL_MASK_NORMAL;
    uint32 damage = 0;
    uint32 absorb = 0;
    int32 resist = 0;
};

// Struct for use in Unit::CalculateMeleeDamage
// Need create structure like in SMSG_ATTACKERSTATEUPDATE opcode
struct CalcDamageInfo
{
    Unit* attacker = nullptr;             // Attacker
    Unit* target = nullptr;               // Target for damage
    uint32 totalDamage = 0;
    uint32 totalAbsorb = 0;
    int32 totalResist = 0;
    SubDamageInfo subDamage[MAX_ITEM_PROTO_DAMAGES] = {};
    uint32 blocked_amount = 0;
    uint32 HitInfo = HITINFO_NORMALSWING;
    uint32 TargetState = VICTIMSTATE_UNAFFECTED;

    // Helper
    WeaponAttackType attackType = BASE_ATTACK;
    uint32 procAttacker = 0;
    uint32 procVictim = 0;
    uint32 procEx = 0;
    uint32 cleanDamage = 0;                        // Used only for rage calculation
    MeleeHitOutcome hitOutCome = MELEE_HIT_EVADE;  // TODO: remove this field (need use TargetState)
};

struct SpellPeriodicAuraLogInfo
{
    SpellPeriodicAuraLogInfo(Aura* _aura, uint32 _damage, uint32 _absorb, int32 _resist, float _multiplier)
        : aura(_aura), damage(_damage), absorb(_absorb), resist(_resist), multiplier(_multiplier) {}

    Aura* aura;
    uint32 damage;
    uint32 absorb;
    int32 resist;
    float  multiplier;
};

uint32 createProcExtendMask(SpellNonMeleeDamage* damageInfo, SpellMissInfo missCondition);

enum SpellAuraProcResult
{
    SPELL_AURA_PROC_OK              = 0,                    // proc was processed, will remove charges
    SPELL_AURA_PROC_FAILED          = 1,                    // proc failed - if at least one aura failed the proc, charges won't be taken
    SPELL_AURA_PROC_CANT_TRIGGER    = 2                     // aura can't trigger - skip charges taking, move to next aura if exists
};

typedef SpellAuraProcResult(Unit::*pAuraProcHandler)(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
extern pAuraProcHandler AuraProcHandler[TOTAL_AURAS];

#define UNIT_SPELL_UPDATE_TIME_BUFFER 60

struct SpellImmune
{
    uint32 type;
    uint32 spellId;
};

typedef std::list<SpellImmune> SpellImmuneList;

#define UNIT_ACTION_BUTTON_ACTION(X) (uint32(X) & 0x00FFFFFF)
#define UNIT_ACTION_BUTTON_TYPE(X)   ((uint32(X) & 0xFF000000) >> 24)
#define MAX_UNIT_ACTION_BUTTON_ACTION_VALUE (0x00FFFFFF+1)
#define MAKE_UNIT_ACTION_BUTTON(A,T) (uint32(A) | (uint32(T) << 24))

struct UnitActionBarEntry
{
    UnitActionBarEntry() : packedData(uint32(ACT_DISABLED) << 24) {}

    uint32 packedData;

    // helper
    ActiveStates GetType() const { return ActiveStates(UNIT_ACTION_BUTTON_TYPE(packedData)); }
    uint32 GetAction() const { return UNIT_ACTION_BUTTON_ACTION(packedData); }
    bool IsActionBarForSpell() const
    {
        ActiveStates Type = GetType();
        return Type == ACT_DISABLED || Type == ACT_ENABLED || Type == ACT_PASSIVE;
    }

    void SetActionAndType(uint32 action, ActiveStates type)
    {
        packedData = MAKE_UNIT_ACTION_BUTTON(action,type);
    }

    void SetType(ActiveStates type)
    {
        packedData = MAKE_UNIT_ACTION_BUTTON(UNIT_ACTION_BUTTON_ACTION(packedData),type);
    }

    void SetAction(uint32 action)
    {
        packedData = (packedData & 0xFF000000) | UNIT_ACTION_BUTTON_ACTION(action);
    }
};

typedef UnitActionBarEntry CharmSpellEntry;

struct CharmInfo
{
    explicit CharmInfo(Unit* unit);
    uint32 GetPetNumber() const { return m_petNumber; }
    void SetPetNumber(uint32 petNumber, bool statWindow);

    void SetCommandState(CommandStates state) { m_commandState = state; }
    CommandStates GetCommandState() const { return m_commandState; }
    bool HasCommandState(CommandStates state) const { return m_commandState == state; }
    void SetReactState(ReactStates st) { m_reactState = st; }
    ReactStates GetReactState() const { return m_reactState; }
    bool HasReactState(ReactStates state) const { return m_reactState == state; }

    FactionTemplateEntry const* GetOriginalFactionTemplate() const { return m_originalFactionTemplate; }
    void SetOriginalFactionTemplate(FactionTemplateEntry const* ft) { m_originalFactionTemplate = ft; }

    void InitPossessCreateSpells();
    void InitCharmCreateSpells();
    void InitPetActionBar();
    void InitEmptyActionBar();

                                                        //return true if successful
    bool AddSpellToActionBar(uint32 spellId, ActiveStates newstate = ACT_DECIDE);
    bool RemoveSpellFromActionBar(uint32 spellId);
    void LoadPetActionBar(std::string const& data);
    void BuildActionBar(WorldPacket* data);
    void SetSpellAutocast(uint32 spellId, bool state);
    void SetActionBar(uint8 index, uint32 spellOrAction,ActiveStates type)
    {
        m_petActionBar[index].SetActionAndType(spellOrAction,type);
    }
    UnitActionBarEntry const* GetActionBarEntry(uint8 index) const { return &(m_petActionBar[index]); }

    void ToggleCreatureAutocast(uint32 spellid, bool apply);

    CharmSpellEntry* GetCharmSpell(uint8 index) { return &(m_charmSpells[index]); }

    void SetIsCommandAttack(bool val);
    bool IsCommandAttack();
    void SetIsCommandFollow(bool val);
    bool IsCommandFollow();
    void SetIsAtStay(bool val);
    bool IsAtStay();
    void SetIsFollowing(bool val);
    bool IsFollowing();
    void SetIsReturning(bool val);
    bool IsReturning();
    void SaveStayPosition();
    void GetStayPosition(float &x, float &y, float &z);
private:

    Unit* m_unit;
    FactionTemplateEntry const* m_originalFactionTemplate;

    UnitActionBarEntry m_petActionBar[MAX_UNIT_ACTION_BAR_INDEX];
    CharmSpellEntry m_charmSpells[CREATURE_MAX_SPELLS];
    CommandStates   m_commandState;
    ReactStates     m_reactState;
    uint32          m_petNumber;

    bool m_isCommandAttack;
    bool m_isCommandFollow;
    bool m_isAtStay;
    bool m_isFollowing;
    bool m_isReturning;
    float m_stayX;
    float m_stayY;
    float m_stayZ;
};

typedef std::set<ObjectGuid> GuardianPetList;

struct SpellProcEventEntry;                                 // used only privately

struct ProhibitSpellInfo
{
    SpellSchoolMask SchoolMask;
    uint32 RestingMsTime;
};

#define DEBUG_UNIT(unit, flags, ...) do { if (unit->GetDebugFlags() & flags) unit->Debug(flags, __VA_ARGS__); } while (false)
#define DEBUG_UNIT_IF(cond, unit, flags, ...) do { if (unit->GetDebugFlags() & flags && cond) unit->Debug(flags, __VA_ARGS__); } while (false)

struct ProcTriggeredData
{
    ProcTriggeredData(SpellProcEventEntry const* _spellProcEvent, SpellAuraHolder* _triggeredByHolder, Unit* _target, uint32 _procFlag)
        : spellProcEvent(_spellProcEvent), triggeredByHolder(_triggeredByHolder), target(_target), procFlag(_procFlag)
        {}
    SpellProcEventEntry const* spellProcEvent;
    SpellAuraHolder* triggeredByHolder;
    Unit* target;
    uint32 procFlag;
};

typedef std::list< ProcTriggeredData > ProcTriggeredList;

class Unit : public SpellCaster
{
    public:
        static Unit* GetUnit(WorldObject &obj, uint64 const& Guid);

        typedef std::set<Unit*> AttackerSet;
        typedef std::multimap< uint32, SpellAuraHolder*> SpellAuraHolderMap;
        typedef std::pair<SpellAuraHolderMap::iterator, SpellAuraHolderMap::iterator> SpellAuraHolderBounds;
        typedef std::pair<SpellAuraHolderMap::const_iterator, SpellAuraHolderMap::const_iterator> SpellAuraHolderConstBounds;
        typedef std::list<SpellAuraHolder*> SpellAuraHolderList;
        typedef std::list<Aura*> AuraList;
        typedef std::list<DiminishingReturn> Diminishing;
        typedef std::set<uint32> ComboPointHolderSet;
        typedef std::map<SpellEntry const*, ObjectGuid> SingleCastSpellTargetMap;

        ~Unit () override;

        void AddToWorld() override;
        void RemoveFromWorld() override;
        void CleanupsBeforeDelete() override;               // used in ~Creature/~Player (or before mass creature delete to remove cross-references to already deleted units)
        void Update(uint32 update_diff, uint32 time) override;

        /*********************************************************/
        /***                   STAT SYSTEM                     ***/
        /*********************************************************/

    protected:
        float m_createStats[MAX_STATS];
        int32 m_createResistances[MAX_SPELL_SCHOOL];
        float m_auraModifiersGroup[UNIT_MOD_END][MODIFIER_TYPE_END];
        WeaponDamageInfo m_weaponDamage[MAX_ATTACK][MAX_ITEM_PROTO_DAMAGES];
        uint8 m_weaponDamageCount[MAX_ATTACK];
        bool m_canModifyStats;
        int32 m_regenTimer;

#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_6_1
        uint32 m_createHealth = 0;
        void SetCreateHealth(uint32 val) { m_createHealth = val; }
#else
        void SetCreateHealth(uint32 val) { SetUInt32Value(UNIT_FIELD_BASE_HEALTH, val); }
#endif

        void SetCreateStat(Stats stat, float val) { m_createStats[stat] = val; }
        void SetCreateMana(uint32 val) { SetUInt32Value(UNIT_FIELD_BASE_MANA, val); }
        void SetCreateResistance(SpellSchools school, int32 val) { m_createResistances[school] = val; }
        void SetStat(Stats stat, int32 val) { SetStatInt32Value(UNIT_FIELD_STAT0 + stat, val); }
        void SetResistance(SpellSchools school, int32 val) { SetInt32Value(UNIT_FIELD_RESISTANCES + school, val); }
        float GetRegenHPPerSpirit() const;
        float GetRegenMPPerSpirit() const;
    public:
        // Data
        float m_modMeleeHitChance;
        float m_modRangedHitChance;
        float m_modSpellHitChance;
        int32 m_baseSpellCritChance;
        float m_threatModifier[MAX_SPELL_SCHOOL];
        float m_modAttackSpeedPct[3];
        float m_modRecalcDamagePct[3];

#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_6_1
        uint32 GetCreateHealth() const { return m_createHealth; }
#else
        uint32 GetCreateHealth() const { return GetUInt32Value(UNIT_FIELD_BASE_HEALTH); }
#endif

        float GetCreateStat(Stats stat) const { return m_createStats[stat]; }
        uint32 GetCreateMana() const { return GetUInt32Value(UNIT_FIELD_BASE_MANA); }
        uint32 GetCreatePowers(Powers power) const;
        int32 GetCreateResistance(SpellSchools school) const { return m_createResistances[school]; }
        float GetStat(Stats stat) const { return float(GetUInt32Value(UNIT_FIELD_STAT0+stat)); }
        int32 GetArmor() const { return GetResistance(SPELL_SCHOOL_NORMAL); }
        void SetArmor(int32 val) { SetStatInt32Value(UNIT_FIELD_RESISTANCES, val); }
        int32 GetResistance(SpellSchools school) const { return GetInt32Value(UNIT_FIELD_RESISTANCES + school); }

        uint32 GetHealth() const { return GetUInt32Value(UNIT_FIELD_HEALTH); }
        uint32 GetMaxHealth() const { return GetUInt32Value(UNIT_FIELD_MAXHEALTH); }
        float GetHealthPercent() const { return (GetHealth()*100.0f) / GetMaxHealth(); }
        void SetHealth(uint32 val);
        void SetMaxHealth(uint32 val);
        void SetHealthPercent(float percent);
        int32 ModifyHealth(int32 val);
        bool IsFullHealth() const { return GetHealth() == GetMaxHealth(); }
        bool HealthBelowPct(int32 pct) const { return GetHealth() * 100 < GetMaxHealth() * pct; }
        bool HealthBelowPctDamaged(int32 pct, uint32 damage) const { return (int32(GetHealth()) - damage) * 100 < GetMaxHealth() * pct; }
        bool HealthAbovePct(int32 pct) const { return GetHealth() * 100 > GetMaxHealth() * pct; }
        uint32 CountPctFromMaxHealth(int32 pct) const { return uint32(float(pct) * GetMaxHealth() / 100.0f); }
        void SetFullHealth() { SetHealth(GetMaxHealth()); }

        Powers GetPowerType() const { return Powers(GetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_POWER_TYPE)); }
        void SetPowerType(Powers power);
        void SetInitCreaturePowerType();
        uint32 GetPower(Powers power) const { return GetUInt32Value(UNIT_FIELD_POWER1   +power); }
        uint32 GetMaxPower(Powers power) const { return GetUInt32Value(UNIT_FIELD_MAXPOWER1+power); }
        float GetPowerPercent(Powers power) const { return GetMaxPower(power) ? ((GetPower(power)*100.0f) / GetMaxPower(power)) : 100.0f; }
        void SetPower(Powers power, uint32 val);
        void SetMaxPower(Powers power, uint32 val);
        void SetPowerPercent(Powers power, float percent);
        int32 ModifyPower(Powers power, int32 val);
        void ApplyPowerMod(Powers power, uint32 val, bool apply);
        void ApplyMaxPowerMod(Powers power, uint32 val, bool apply);

        uint32 GetAttackTime(WeaponAttackType att) const { return (uint32)(GetFloatValue(UNIT_FIELD_BASEATTACKTIME+att)/m_modAttackSpeedPct[att]); }
        void SetAttackTime(WeaponAttackType att, uint32 val, bool resetAttTime = true)
        {
            SetFloatValue(UNIT_FIELD_BASEATTACKTIME+att,val*m_modAttackSpeedPct[att]);
            if (resetAttTime)
                ResetAttackTimer(att);
        }
        void ApplyAttackTimePercentMod(WeaponAttackType att,float val, bool apply, bool recalcDamage = false);
        void ApplyCastTimePercentMod(float val, bool apply);

        float GetObjectBoundingRadius() const final { return m_floatValues[UNIT_FIELD_BOUNDINGRADIUS]; }
        float GetCombatReach() const final { return m_floatValues[UNIT_FIELD_COMBATREACH]; }

        float GetUnitDodgeChance() const;
        float GetUnitParryChance() const;
        float GetUnitBlockChance() const;
        float GetUnitCriticalChance(WeaponAttackType attackType, Unit const* pVictim) const;

        virtual uint32 GetShieldBlockValue() const = 0;
        float GetPPMProcChance(uint32 WeaponSpeed, float PPM) const;

        bool HandleStatModifier(UnitMods unitMod, UnitModifierType modifierType, float amount, bool apply);
        void SetModifierValue(UnitMods unitMod, UnitModifierType modifierType, float value) { m_auraModifiersGroup[unitMod][modifierType] = value; }
        float GetModifierValue(UnitMods unitMod, UnitModifierType modifierType) const;
        float GetTotalStatValue(Stats stat) const;
        int32 GetTotalResistanceValue(SpellSchools school) const;
        float GetTotalAuraModValue(UnitMods unitMod) const;

        SpellSchools GetSpellSchoolByAuraGroup(UnitMods unitMod) const;
        Stats GetStatByAuraGroup(UnitMods unitMod) const;
        Powers GetPowerTypeByAuraGroup(UnitMods unitMod) const;
        bool CanModifyStats() const { return m_canModifyStats; }
        void SetCanModifyStats(bool modifyStats) { m_canModifyStats = modifyStats; }

        virtual bool UpdateStats(Stats stat) = 0;
        virtual bool UpdateAllStats() = 0;
        virtual void UpdateResistances(uint32 school) = 0;
        virtual void UpdateArmor() = 0;
        virtual void UpdateMaxHealth() = 0;
        virtual void UpdateMaxPower(Powers power) = 0;
        virtual void UpdateManaRegen() = 0;

        virtual void UpdateAttackPowerAndDamage(bool ranged = false) = 0;
        virtual void UpdateDamagePhysical(WeaponAttackType attType) = 0;
        float GetTotalAttackPowerValue(WeaponAttackType attType) const;
        float GetWeaponDamageRange(WeaponAttackType attType, WeaponDamageRange damageRange, uint8 index = 0) const;
        SpellSchools GetWeaponDamageSchool(WeaponAttackType attType, uint8 index = 0) const { return m_weaponDamage[attType][index].school; }
        void SetBaseWeaponDamage(WeaponAttackType attType, WeaponDamageRange damageRange, float value, uint8 index = 0) { m_weaponDamage[attType][index].damage[damageRange] = value; }
        void SetWeaponDamageSchool(WeaponAttackType attType, SpellSchools school, uint8 index = 0) { m_weaponDamage[attType][index].school = school; }
        uint8 GetWeaponDamageCount(WeaponAttackType attType) const { return m_weaponDamageCount[attType]; }

    private:
        ComboPointHolderSet m_ComboPointHolders;
    public:
        void AddComboPointHolder(uint32 lowguid) { m_ComboPointHolders.insert(lowguid); }
        void RemoveComboPointHolder(uint32 lowguid) { m_ComboPointHolders.erase(lowguid); }
        void ClearComboPointHolders();

        /*********************************************************/
        /***                   STATE SYSTEM                    ***/
        /*********************************************************/

    private:
        uint32 m_stateFlags; // Even derived shouldn't modify
        bool m_AINotifyScheduled;
    protected:
        DeathState m_deathState;
        uint32 m_transform;
        float m_modelCollisionHeight;
        bool m_isCreatureLinkingTrigger;
        bool m_isSpawningLinked;
        float m_nativeScale = 1.0f;
        float m_nativeScaleOverride = 1.0f;
    public:
        void AddUnitState(uint32 f) { m_stateFlags |= f; }
        bool HasUnitState(uint32 f) const { return m_stateFlags & f; }
        void ClearUnitState(uint32 f) { m_stateFlags &= ~f; }
        uint32 GetUnitState() const { return m_stateFlags; }
        void UpdateControl();
        bool CanFreeMove() const { return !HasUnitState(UNIT_STAT_NO_FREE_MOVE) && !GetOwnerGuid(); }
        uint32 GetCreatureType() const;
        uint32 GetCreatureTypeMask() const
        {
            uint32 creatureType = GetCreatureType();
            return creatureType ? (1 << (creatureType - 1)) : 0;
        }
        bool IsAlive() const { return m_deathState == ALIVE; }
        bool IsDead() const { return m_deathState == DEAD || m_deathState == CORPSE; }
        DeathState GetDeathState() const { return m_deathState; }
        virtual void SetDeathState(DeathState s);           // overwritten in Creature/Player/Pet
        uint32 GetLevel() const final { return GetUInt32Value(UNIT_FIELD_LEVEL); }
        void SetLevel(uint32 lvl);
        uint8 GetRace() const { return GetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_RACE); }
        uint32 GetRaceMask() const { return GetRace() ? 1 << (GetRace()-1) : 0x0; }
        uint8 GetClass() const { return GetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS); }
        uint32 GetClassMask() const { return GetClass() ? 1 << (GetClass()-1) : 0x0; }
        uint8 GetGender() const final { return GetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER); }
        SheathState GetSheath() const { return SheathState(GetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_SHEATH_STATE)); }
        virtual void SetSheath(SheathState sheathed) { SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_SHEATH_STATE, sheathed); }
        void SetStandState(uint8 state);
        uint8 GetStandState() const { return GetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_STAND_STATE); }
        bool IsSittingDown() const;
        bool IsStandingUp() const;
        bool IsMounted() const { return (GetMountID() != 0); }
        uint32 GetMountID() const { return GetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID); }
        virtual UnitMountResult Mount(uint32 mount, uint32 spellId = 0);
        virtual UnitDismountResult Unmount(bool from_aura = false);
        ShapeshiftForm GetShapeshiftForm() const { return ShapeshiftForm(GetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_SHAPESHIFT_FORM)); }
        void SetShapeshiftForm(ShapeshiftForm form) { SetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_SHAPESHIFT_FORM, form); }
        bool IsShapeShifted() const; // mirrors clientside logic, moonkin form not counted as shapeshift
        bool IsInFeralForm() const
        {
            ShapeshiftForm form = GetShapeshiftForm();
            return form == FORM_CAT || form == FORM_BEAR || form == FORM_DIREBEAR;
        }
        bool IsInDisallowedMountForm() const;
        uint32 GetDisplayId() const { return GetUInt32Value(UNIT_FIELD_DISPLAYID); }
        void SetDisplayId(uint32 displayId);
        uint32 GetNativeDisplayId() const { return GetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID); }
        void SetNativeDisplayId(uint32 displayId) { SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, displayId); }
        void SetTransForm(uint32 spellid) { m_transform = spellid; }
        uint32 GetTransForm() const { return m_transform; }
        void SetTransformScale(float scale);
        void ResetTransformScale();
        float GetNativeScale() const;
        void SetNativeScale(float scale);
        float GetCollisionHeight() const { return m_modelCollisionHeight * m_nativeScaleOverride; }
        void UpdateModelData(); // at any changes to scale and/or displayId
        void InitPlayerDisplayIds();
        void DeMorph();

        bool IsVendor()       const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_VENDOR); }
        bool IsTrainer()      const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_TRAINER); }
        bool IsQuestGiver()   const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER); }
        bool IsGossip()       const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP); }
        bool IsTaxi()         const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_FLIGHTMASTER); }
        bool IsGuildMaster()  const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PETITIONER); }
        bool IsBattleMaster() const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_BATTLEMASTER); }
        bool IsBanker()       const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_BANKER); }
        bool IsInnkeeper()    const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_INNKEEPER); }
        bool IsSpiritHealer() const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPIRITHEALER); }
        bool IsSpiritGuide()  const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPIRITGUIDE); }
        bool IsTabardDesigner()const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_TABARDDESIGNER); }
        bool IsAuctioner()    const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_AUCTIONEER); }
        bool IsArmorer()      const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_REPAIR); }
        bool IsServiceProvider() const
        {
            return HasFlag(UNIT_NPC_FLAGS,
                UNIT_NPC_FLAG_VENDOR | UNIT_NPC_FLAG_TRAINER | UNIT_NPC_FLAG_FLIGHTMASTER |
                UNIT_NPC_FLAG_PETITIONER | UNIT_NPC_FLAG_BATTLEMASTER | UNIT_NPC_FLAG_BANKER |
                UNIT_NPC_FLAG_INNKEEPER | UNIT_NPC_FLAG_SPIRITHEALER |
                UNIT_NPC_FLAG_SPIRITGUIDE | UNIT_NPC_FLAG_TABARDDESIGNER | UNIT_NPC_FLAG_AUCTIONEER);
        }
        bool IsSpiritService() const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPIRITHEALER | UNIT_NPC_FLAG_SPIRITGUIDE); }
        bool IsTaxiFlying() const { return HasUnitState(UNIT_STAT_TAXI_FLIGHT); }

        bool IsCaster() const;
        CreatureAI* AI() const;
        void ScheduleAINotify(uint32 delay);
        bool IsAINotifyScheduled() const { return m_AINotifyScheduled; }
        void SetAINotifyScheduled(bool on) { m_AINotifyScheduled = on; }       // only for call from RelocationNotifyEvent code
        bool IsLinkingEventTrigger() const { return m_isCreatureLinkingTrigger; }

        void HandleEmote(uint32 emote_id);                  // auto-select command/state
        void HandleEmoteCommand(uint32 emote_id);
        void HandleEmoteState(uint32 emote_id);
                                                                               // debug.
        void Debug(uint32 debugType, char const* str, ...) const ATTR_PRINTF(3, 4);
        void SetDebugger(ObjectGuid playerGuid, uint32 flags)
        {
            m_debuggerGuid = playerGuid;
            m_debugFlags = flags;
        }
        uint32 GetDebugFlags() const { return m_debugFlags; }
        ObjectGuid GetDebuggerGuid() const { return m_debuggerGuid; }
    protected:
        mutable ObjectGuid m_debuggerGuid;
        mutable uint32 m_debugFlags;

        /*********************************************************/
        /***                VISIBILITY SYSTEM                  ***/
        /*********************************************************/

    private:
        UnitVisibility m_Visibility;
        Position m_last_notified_position;
    public:
        uint32 m_detectInvisibilityMask;
        uint32 m_invisibilityMask;
        virtual bool CanBeDetected() const { return true; }
        UnitVisibility GetVisibility() const { return m_Visibility; }
        void SetVisibility(UnitVisibility x);
        void UpdateVisibilityAndView() override;

        // common function for visibility checks for player/creatures with detection code
        bool IsVisibleForOrDetect(WorldObject const* pDetector, WorldObject const* viewPoint, bool detect, bool inVisibleList = false, bool* alert = nullptr) const final;
        bool CanDetectInvisibilityOf(Unit const* u) const;
        bool CanDetectStealthOf(Unit const* u, float distance, bool* alert = nullptr) const;

        // virtual functions for all world objects types
        bool IsVisibleForInState(WorldObject const* pDetector, WorldObject const* viewPoint, bool inVisibleList) const override;
        // function for low level grid visibility checks in player/creature cases
        virtual bool IsVisibleInGridForPlayer(Player const* pl) const = 0;
        bool IsInvisibleForAlive() const;
        bool IsVisibleForDead() const;

        /*********************************************************/
        /***                   SPELL SYSTEM                    ***/
        /*********************************************************/

    private:
        Diminishing m_Diminishing;
    protected:
        SpellAuraHolderMap m_spellAuraHolders;
        SpellAuraHolderMap::iterator m_spellAuraHoldersUpdateIterator; // != end() in Unit::m_spellAuraHolders update and point to next element
        AuraList m_deletedAuras;                                       // auras removed while in ApplyModifier and waiting deleted
        SpellAuraHolderList m_deletedHolders;
        SingleCastSpellTargetMap m_singleCastSpellTargets;  // casted by unit single per-caster auras
        typedef std::list<GameObject*> GameObjectList;
        GameObjectList m_gameObj;
        AuraList m_modAuras[TOTAL_AURAS];
        uint32 m_lastManaUseSpellId;
        uint32 m_lastManaUseTimer;
        uint32 m_spellUpdateTimeBuffer;

        void _UpdateSpells(uint32 time);
        void _UpdateAutoRepeatSpell();

    public:
        /**
         * Stop all spells from casting except the one give by except_spellid
         * @param except_spellid This spell id will not be stopped from casting, defaults to 0
         * \see Unit::InterruptSpell
         */
        void CastStop(uint32 except_spellid = 0);
        /**
         * Gets the current DiminishingLevels for the given group
         * @param group The group that you would like to know the current diminishing return level for
         * @return The current diminishing level, up to DIMINISHING_LEVEL_IMMUNE
         */
        DiminishingLevels GetDiminishing(DiminishingGroup  group);
        /**
         * Increases the level of the DiminishingGroup by one level up until
         * DIMINISHING_LEVEL_IMMUNE where the target becomes immune to spells of
         * that DiminishingGroup
         * @param group The group to increase the level for by one
         */
        void IncrDiminishing(DiminishingGroup group);
        /**
         * Calculates how long the duration of a spell should be considering
         * diminishing returns, ie, if the Level passed in is DIMINISHING_LEVEL_IMMUNE
         * then the duration will be zeroed out. If it is DIMINISHING_LEVEL_1 then a full
         * duration will be used
         * @param group The group to affect
         * @param duration The duration to be changed, will be updated with the new duration
         * @param caster Who's casting the spell, used to decide whether anything should be calculated
         * @param Level The current level of diminishing returns for the group, decides the new duration
         * @param isReflected Whether the spell was reflected or not, used to determine if we should do any calculations at all.
         */
        void ApplyDiminishingToDuration(DiminishingGroup  group, int32& duration, WorldObject const* caster, DiminishingLevels Level, bool isReflected = false);
        /**
         * Applies a diminishing return to the given group if apply is true,
         * otherwise lowers the level by one (?)
         * @param group The group to affect
         * @param apply whether this aura is being added/removed
         */
        void ApplyDiminishingAura(DiminishingGroup  group, bool apply);
        /**
         * Clears all the current diminishing returns for this Unit.
         */
        void ClearDiminishings() { m_Diminishing.clear(); }

        void SendSpellGo(Unit* target, uint32 spellId) const;
        void SendPlaySpellVisual(uint32 id) const;
        void SendPeriodicAuraLog(SpellPeriodicAuraLogInfo* pInfo, AuraType auraTypeOverride = SPELL_AURA_NONE) const;
        void SendEnvironmentalDamageLog(uint8 type, uint32 damage, uint32 absorb, int32 resist) const;
        uint32 SpellNonMeleeDamageLog(Unit* pVictim, uint32 spellId, uint32 damage);
        void WritePetSpellsCooldown(WorldPacket& data) const;

        SpellAuraHolder* AddAura(uint32 spellId, uint32 addAuraFlags = 0, Unit* pCaster = nullptr);
        SpellAuraHolder* RefreshAura(uint32 spellId, int32 duration);
        bool AddSpellAuraHolder(SpellAuraHolder* holder);
        void AddAuraToModList(Aura* aura);

        // pet auras
        typedef std::set<PetAura const*> PetAuraSet;
        PetAuraSet m_petAuras;
        void AddPetAura(PetAura const* petSpell);
        void RemovePetAura(PetAura const* petSpell);

        // Apply SpellEffects::EffectSummonPet after ressurecting in BG.
        ObjectGuid EffectSummonPet(uint32 spellId, uint32 petEntry, uint32 petLevel);
        void ModPossess(Unit* target, bool apply, AuraRemoveMode m_removeMode = AURA_REMOVE_BY_DEFAULT);

    private:
        void CleanupDeletedAuras();

    public:
        // removing specific aura stack
        void RemoveAura(Aura* aura, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAura(uint32 spellId, SpellEffectIndex effindex, Aura* except = nullptr);
        void RemoveSpellAuraHolder(SpellAuraHolder* holder, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveSingleAuraFromSpellAuraHolder(SpellAuraHolder* holder, SpellEffectIndex index, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveSingleAuraFromSpellAuraHolder(uint32 id, SpellEffectIndex index, ObjectGuid casterGuid, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveSingleAuraDueToItemSet(uint32 spellId, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void DeleteAuraHolder(SpellAuraHolder* holder);

        // removing specific aura stacks by diff reasons and selections
        void RemoveAurasDueToSpell(uint32 spellId, SpellAuraHolder* except = nullptr, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAurasDueToItemSpell(Item* castItem, uint32 spellId);
        void RemoveAurasByCasterSpell(uint32 spellId, ObjectGuid casterGuid, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAurasDueToSpellByCancel(uint32 spellId);

        // removing unknown aura stacks by diff reasons and selections
        void RemoveNotOwnSingleTargetAuras();
        void RemoveAurasAtMechanicImmunity(uint32 mechMask, uint32 exceptSpellId, bool non_positive = false);
        void RemoveSpellsCausingAura(AuraType auraType);
        void RemoveSpellsCausingAura(AuraType auraType, SpellAuraHolder* except);
        void RemoveNegativeSpellsCausingAura(AuraType auraType);
        void RemoveNonPassiveSpellsCausingAura(AuraType auraType);
        bool RemoveNoStackAurasDueToAuraHolder(SpellAuraHolder* holder);
        void RemoveAurasWithInterruptFlags(uint32 flags, uint32 except = 0, bool checkProcFlags = false);
        void RemoveAurasWithAttribute(uint32 flags);
        void RemoveAurasWithDispelType(DispelType type, ObjectGuid casterGuid = ObjectGuid());
        void RemoveAllAuras(AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAllNegativeAuras(AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAuraTypeOnDeath(AuraType auraType);
        void RemoveAllAurasOnDeath();
        bool RemoveAuraDueToDebuffLimit(SpellAuraHolder* currentAura); // Returns true if we remove 'currentAura'
        void RemoveFearEffectsByDamageTaken(uint32 damage, uint32 exceptSpellId, DamageEffectType damagetype);
        uint32 GetNegativeAurasCount(); // Limit debuffs to 16

        // removing specific aura FROM stack by diff reasons and selections
        void RemoveAuraHolderFromStack(uint32 spellId, uint32 stackAmount = 1, ObjectGuid casterGuid = ObjectGuid(), AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAuraHolderDueToSpellByDispel(uint32 spellId, uint32 stackAmount, ObjectGuid casterGuid);

        void _RemoveAllAuraMods();
        void _ApplyAllAuraMods();

        // group updates
        void UpdateAuraForGroup(uint8 slot);

        // Managing objects spawned by:
        // SPELL_EFFECT_DUEL
        // SPELL_EFFECT_SUMMON_OBJECT_SLOT
        // SPELL_EFFECT_TRANS_DOOR
        GameObject* GetGameObject(uint32 spellId) const;
        void AddGameObject(GameObject* pGo);
        void RemoveGameObject(GameObject* pGo, bool del);
        void RemoveGameObject(uint32 spellid, bool del);
        void RemoveAllGameObjects();
        ObjectGuid m_ObjectSlotGuid[4];

        uint32 m_lastSanctuaryTime; // Used by SPELL_EFFECT_SANCTUARY.
        bool m_AutoRepeatFirstCast; // auto shoot and wand

        SingleCastSpellTargetMap      & GetSingleCastSpellTargets() { return m_singleCastSpellTargets; }
        SingleCastSpellTargetMap const& GetSingleCastSpellTargets() const { return m_singleCastSpellTargets; }
        SpellImmuneList m_spellImmune[MAX_SPELL_IMMUNITY];

        Aura* GetAura(uint32 spellId, SpellEffectIndex effindex);
        Aura* GetAura(AuraType type, SpellFamily family, uint64 familyFlag, ObjectGuid casterGuid = ObjectGuid());
        SpellAuraHolder* GetSpellAuraHolder(uint32 spellid) const;
        SpellAuraHolder* GetSpellAuraHolder(uint32 spellid, ObjectGuid casterGUID) const;

        SpellAuraHolderMap      & GetSpellAuraHolderMap() { return m_spellAuraHolders; }
        SpellAuraHolderMap const& GetSpellAuraHolderMap() const { return m_spellAuraHolders; }
        void DelaySpellAuraHolder(uint32 spellId, int32 delaytime, ObjectGuid casterGuid);
        AuraList const& GetAurasByType(AuraType type) const { return m_modAuras[type]; }

        float GetTotalAuraModifier(AuraType auratype) const;
        float GetTotalAuraMultiplier(AuraType auratype) const;
        int32 GetMaxPositiveAuraModifier(AuraType auratype) const;
        int32 GetMaxNegativeAuraModifier(AuraType auratype) const;

        int32 GetTotalAuraModifierByMiscMask(AuraType auratype, uint32 misc_mask) const;
        float GetTotalAuraMultiplierByMiscMask(AuraType auratype, uint32 misc_mask) const;
        int32 GetTotalAuraModifierByMiscValue(AuraType auratype, int32 misc_value) const;
        float GetTotalAuraMultiplierByMiscValue(AuraType auratype, int32 misc_value) const;

        uint64 GetAuraApplicationMask() const;
        uint64 GetNegativeAuraApplicationMask() const;

        SpellAuraHolderBounds GetSpellAuraHolderBounds(uint32 spellId)
        {
            return m_spellAuraHolders.equal_range(spellId);
        }
        SpellAuraHolderConstBounds GetSpellAuraHolderBounds(uint32 spellId) const
        {
            return m_spellAuraHolders.equal_range(spellId);
        }

        bool HasAuraType(AuraType auraType) const;
        bool HasAuraTypeByCaster(AuraType auraType, ObjectGuid casterGuid) const;
        bool HasAura(uint32 spellId, SpellEffectIndex effIndex) const;
        bool HasAura(uint32 spellId) const { return m_spellAuraHolders.find(spellId) != m_spellAuraHolders.end(); }
        bool virtual HasSpell(uint32 /*spellId*/) const { return false; }
        bool HasStealthAura()      const { return HasAuraType(SPELL_AURA_MOD_STEALTH); }
        bool HasInvisibilityAura() const { return HasAuraType(SPELL_AURA_MOD_INVISIBILITY); }
        bool IsFeared()  const { return HasAuraType(SPELL_AURA_MOD_FEAR); }
        bool IsInRoots() const { return HasAuraType(SPELL_AURA_MOD_ROOT); }
        bool IsPolymorphed() const;
        bool IsImmuneToSchoolMask(uint32 schoolMask) const;
        bool IsImmuneToMechanic(Mechanics mechanic) const;
        bool IsFrozen() const { return HasAuraState(AURA_STATE_FROZEN); }
        bool IsFeigningDeath() const { return ((HasFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_DEAD) || IsFeigningDeathSuccessfully()) && IsAlive()); }
        bool IsFeigningDeathSuccessfully() const { return HasUnitState(UNIT_STAT_FEIGN_DEATH); }

        bool HasBreakableByDamageCrowdControlAura(Unit* excludeCasterChannel = nullptr) const;
        bool HasBreakableByDamageAuraType(AuraType type, uint32 excludeAura) const;
        bool HasAuraPetShouldAvoidBreaking(Unit* excludeCasterChannel = nullptr) const;
        bool HasMorePowerfulSpellActive(SpellEntry const* spellInfos) const;
        Aura* GetMostImportantAuraAfter(Aura const* like, Aura const* except = nullptr) const; // Returns the most important aura of the same type as 'like' except 'except'

        void ModifyAuraState(AuraState flag, bool apply);
        bool HasAuraState(AuraState flag) const { return HasFlag(UNIT_FIELD_AURASTATE, 1 << (flag - 1)); }

        int32 SpellBaseDamageBonusTaken(SpellSchoolMask schoolMask) const;
        float SpellDamageBonusTaken(SpellCaster* pCaster, SpellEntry const* spellProto, SpellEffectIndex effectIndex, float pdamage, DamageEffectType damagetype, uint32 stack = 1, Spell* spell = nullptr) const;
        int32 SpellBaseHealingBonusTaken(SpellSchoolMask schoolMask) const;
        float SpellHealingBonusTaken(SpellCaster* pCaster, SpellEntry const* spellProto, SpellEffectIndex effectIndex, float healamount, DamageEffectType damagetype, uint32 stack = 1, Spell* spell = nullptr) const;
        void CalculateDamageAbsorbAndResist(SpellCaster* pCaster, SpellSchoolMask schoolMask, DamageEffectType damagetype, uint32 const damage, uint32* absorb, int32* resist, SpellEntry const* spellProto = nullptr, Spell* spell = nullptr);
        void CalculateAbsorbResistBlock(SpellCaster* pCaster, SpellNonMeleeDamage* damageInfo, SpellEntry const* spellProto, WeaponAttackType attType = BASE_ATTACK, Spell* spell = nullptr);
        float RollMagicResistanceMultiplierOutcomeAgainst(float resistanceChance, SpellSchoolMask schoolMask, DamageEffectType dmgType, SpellEntry const* spellProto) const;
        bool IsSpellBlocked(SpellCaster* pCaster, Unit* pVictim, SpellEntry const* spellProto, WeaponAttackType attackType = BASE_ATTACK) const;
        bool IsSpellCrit(Unit const* pVictim, SpellEntry const* spellProto, SpellSchoolMask schoolMask, WeaponAttackType attackType = BASE_ATTACK, Spell* spell = nullptr) const final;
        bool IsEffectResist(SpellEntry const* spell, int eff) const; // SPELL_AURA_MOD_MECHANIC_RESISTANCE
        
        void ProcDamageAndSpellFor(bool isVictim, Unit* pTarget, uint32 procFlag, uint32 procExtra, WeaponAttackType attType, SpellEntry const* procSpell, uint32 damage, ProcTriggeredList& triggeredList, std::list<SpellModifier*> const& appliedSpellModifiers, bool isSpellTriggeredByAura);
        void ProcSkillsAndReactives(bool isVictim, Unit* pTarget, uint32 procFlag, uint32 procExtra, WeaponAttackType attType);
        void HandleTriggers(Unit* pVictim, uint32 procExtra, uint32 amount, SpellEntry const* procSpell, ProcTriggeredList const& procTriggered);

        bool IsTriggeredAtSpellProcEvent(Unit* pVictim, SpellAuraHolder* holder, SpellEntry const* procSpell, uint32 procFlag, uint32 procExtra, WeaponAttackType attType, bool isVictim, SpellProcEventEntry const*& spellProcEvent, bool dontTriggerSpecial) const;
        // only to be used in proc handlers - basepoints is expected to be a MAX_EFFECT_INDEX sized array
        SpellAuraProcResult TriggerProccedSpell(Unit* target, int32* basepoints, uint32 triggeredSpellId, Item* castItem, Aura* triggeredByAura, uint32 cooldown, ObjectGuid originalCaster = ObjectGuid(), SpellEntry const* triggeredByParent = nullptr);
        SpellAuraProcResult TriggerProccedSpell(Unit* target, int32* basepoints, SpellEntry const* spellInfo, Item* castItem, Aura* triggeredByAura, uint32 cooldown, ObjectGuid originalCaster = ObjectGuid(), SpellEntry const* triggeredByParent = nullptr);
        // Aura proc handlers
        SpellAuraProcResult HandleDummyAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleHasteAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleProcTriggerSpellAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleProcTriggerDamageAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleOverrideClassScriptAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleModCastingSpeedNotStackAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleReflectSpellsSchoolAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleModPowerCostSchoolAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleMechanicImmuneResistanceAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleAddTargetTriggerAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleModResistanceAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleRemoveByDamageChanceProc(Unit *pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const *procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleInvisibilityAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleModDamageAuraProc(Unit* pVictim, uint32 damage, Aura* triggeredByAura, SpellEntry const* procSpell, uint32 procFlag, uint32 procEx, uint32 cooldown);
        SpellAuraProcResult HandleNULLProc(Unit* /*pVictim*/, uint32 /*damage*/, Aura* /*triggeredByAura*/, SpellEntry const* /*procSpell*/, uint32 /*procFlag*/, uint32 /*procEx*/, uint32 /*cooldown*/)
        {
            // no proc handler for this aura type
            return SPELL_AURA_PROC_OK;
        }
        SpellAuraProcResult HandleCantTrigger(Unit* /*pVictim*/, uint32 /*damage*/, Aura* /*triggeredByAura*/, SpellEntry const* /*procSpell*/, uint32 /*procFlag*/, uint32 /*procEx*/, uint32 /*cooldown*/)
        {
            // this aura type can't proc
            return SPELL_AURA_PROC_CANT_TRIGGER;
        }

        void SetLastManaUse(uint32 spellId) { m_lastManaUseTimer = 5000; m_lastManaUseSpellId = spellId; }
        bool IsUnderLastManaUseEffect() const { return m_lastManaUseTimer; }

        void ApplySpellImmune(uint32 spellId, uint32 op, uint32 type, bool apply);
        void ApplySpellDispelImmunity(SpellEntry const* spellProto, DispelType type, bool apply);
        virtual bool IsImmuneToSpell(SpellEntry const* spellInfo, bool castOnSelf) const;
        virtual bool IsImmuneToDamage(SpellSchoolMask meleeSchoolMask, SpellEntry const* spellInfo = nullptr) const;
        virtual bool IsImmuneToSpellEffect(SpellEntry const* spellInfo, SpellEffectIndex index, bool castOnSelf) const;
        bool IsImmuneToSchool(SpellEntry const* spellInfo, uint8 effectMask) const;

        void ModConfuseSpell(bool apply, ObjectGuid casterGuid, uint32 spellId, MovementModType modType, uint32 time = 0);
        void SetFleeing(bool apply, ObjectGuid casterGuid = ObjectGuid(), uint32 spellId = 0, uint32 time = 0);
        void SetFeared(bool apply, ObjectGuid casterGuid = ObjectGuid(), uint32 spellId = 0, uint32 time = 0);/*DEPRECATED METHOD*/
        void SetConfused(bool apply, ObjectGuid casterGuid = ObjectGuid(), uint32 spellId = 0);/*DEPRECATED METHOD*/
        void SetFeignDeath(bool apply, ObjectGuid casterGuid = ObjectGuid(), bool success = true);

        /*********************************************************/
        /***                  COMBAT SYSTEM                    ***/
        /*********************************************************/

    private:
        uint32 m_CombatTimer;
        uint32 m_extraAttacks;
        bool m_extraMute;
        bool m_doExtraAttacks;
        float m_meleeZLimit;
        float m_meleeZReach;
        ThreatManager m_ThreatManager; // Manage all Units threatening us
        HostileRefManager m_HostileRefManager; // Manage all Units that are threatened by us
    protected:
        uint32 m_attackTimer[MAX_ATTACK];
        AttackerSet m_attackers;
        Unit* m_attacking;
        uint32 m_reactiveTimer[MAX_REACTIVE];
        ObjectGuid m_reactiveTarget[MAX_REACTIVE];
        typedef std::map<ObjectGuid /*attackerGuid*/, uint32 /*damage*/ > DamageTakenHistoryMap;
        DamageTakenHistoryMap   m_damageTakenHistory;
        uint32                  m_lastDamageTaken;
    public:
        /**
         * Updates the attack time for the given WeaponAttackType
         * @param type The type of weapon that we want to update the time for
         * @param time the remaining time until we can attack with the WeaponAttackType again
         */
        void SetAttackTimer(WeaponAttackType type, uint32 time) { m_attackTimer[type] = time; }
        /**
         * Resets the attack timer to the base value decided by Unit::m_modAttackSpeedPct and
         * Unit::GetAttackTime
         * @param type The weapon attack type to reset the attack timer for.
         */
        void ResetAttackTimer(WeaponAttackType type = BASE_ATTACK);
        /**
         * Get's the remaining time until we can do an attack
         * @param type The weapon type to check the remaining time for
         * @return The remaining time until we can attack with this weapon type.
         */
        uint32 GetAttackTimer(WeaponAttackType type) const { return m_attackTimer[type]; }
        /**
         * Checks whether the unit can do an attack. Does this by checking the attacktimer for the
         * WeaponAttackType, can probably be thought of as a cooldown for each swing/shot
         * @param type What weapon should we check for
         * @return true if the Unit::m_attackTimer is zero for the given WeaponAttackType
         */
        bool IsAttackReady(WeaponAttackType type = BASE_ATTACK) const;
        /**
         * Checks if the current Unit has an offhand weapon
         * @return True if there is a offhand weapon.
         */
        bool HaveOffhandWeapon() const;
        /**
         * Does an attack if any of the timers allow it and resets them, if the user
         * isn't in range or behind the target an error is sent to the client.
         * Also makes sure to not make and offhand and mainhand attack at the same
         * time. Only handles non-spells ie melee attacks.
         * @return True if an attack was made and no error happened, false otherwise
         */
        bool UpdateMeleeAttackingState();
        /**
         * Delays both main and off hand attacks by 100 ms if they are ready.
         * Called from UpdateMeleeAttackingState if attack can't happen now.
         */
        void DelayAutoAttacks();
        /**
         * Checks that need to be done before an auto attack swing happens.
         * Target's faction is only checked for players since its done elsewhere
         * for creatures and there is no need to check it on attack for them.
         */
        virtual AutoAttackCheckResult CanAutoAttackTarget(Unit const*) const;
        /**
         * Check is a given equipped weapon can be used, ie the mainhand, offhand etc.
         * @param attackType The attack type to check, ie: main/offhand/ranged
         * @return True if the weapon can be used, true except for shapeshifts and if disarmed.
         */
        bool CanUseEquippedWeapon(WeaponAttackType attackType) const
        {
            if (IsInFeralForm())
                return false;

            switch(attackType)
            {
                default:
                case BASE_ATTACK:
                    return !HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISARMED);
                case OFF_ATTACK:
                case RANGED_ATTACK:
                    return true;
            }
        }

        void AttackerStateUpdate(Unit* pVictim, WeaponAttackType attType = BASE_ATTACK, bool checkLoS = true, bool extra = false);
        void SendAttackStateUpdate(CalcDamageInfo* damageInfo) const;
        void SendAttackStateUpdate(uint32 HitInfo, Unit* target, uint8 SwingType, SpellSchoolMask damageSchoolMask, uint32 Damage, uint32 AbsorbDamage, int32 Resist, VictimState TargetState, uint32 BlockedAmount) const;
        void SendMeleeAttackStop(Unit* victim) const;
        void SendMeleeAttackStart(Unit* pVictim) const;

        void ClearAllReactives();
        void StartReactiveTimer(ReactiveType reactive, ObjectGuid target) { m_reactiveTimer[reactive] = REACTIVE_TIMER_START; m_reactiveTarget[reactive] = target; }
        ObjectGuid const& GetReactiveTarget(ReactiveType reactive) const { return m_reactiveTarget[reactive]; }
        void UpdateReactives(uint32 p_time);

        float MeleeMissChanceCalc(Unit const* pVictim, WeaponAttackType attType) const;
        void CalculateMeleeDamage(Unit* pVictim, uint32 damage, CalcDamageInfo* damageInfo, WeaponAttackType attackType = BASE_ATTACK);
        void UnitDamaged(ObjectGuid from, uint32 damage) { m_damageTakenHistory[from] += damage; m_lastDamageTaken = 0; }
        void DealMeleeDamage(CalcDamageInfo* damageInfo, bool durabilityLoss);
        float CalculateDamage(WeaponAttackType attType, bool normalized, uint8 index = 0) const;
        float MeleeDamageBonusTaken(SpellCaster* pCaster, float pdamage, WeaponAttackType attType, SpellEntry const* spellProto = nullptr, SpellEffectIndex effectIndex = EFFECT_INDEX_0, DamageEffectType damagetype = DIRECT_DAMAGE, uint32 stack = 1, Spell* spell = nullptr, bool flat = true);
        MeleeHitOutcome RollMeleeOutcomeAgainst(Unit const* pVictim, WeaponAttackType attType) const;
        MeleeHitOutcome RollMeleeOutcomeAgainst(Unit const* pVictim, WeaponAttackType attType, int32 crit_chance, int32 miss_chance, int32 dodge_chance, int32 parry_chance, int32 block_chance, bool SpellCasted) const;

        // Extra attacks methods
        void ResetExtraAttacks() { m_extraAttacks = 0; }
        void AddExtraAttack() { ++m_extraAttacks; }
        void SetExtraAttaks(uint32 attacks) { m_extraAttacks = attacks; }
        uint32 GetExtraAttacks() const { return m_extraAttacks; }
        bool IsExtraAttacksLocked() const { return m_extraMute; }
        void ExtraAttacksLocked(bool mute) { m_extraMute = mute; }
        void AddExtraAttackOnUpdate() { m_doExtraAttacks = true; };

        bool CanAttack(Unit const* target, bool force = false) const;
        bool IsTargetable(bool forAttack, bool isAttackerPlayer, bool forAoE = false, bool checkAlive = true) const;

        bool CanReachWithMeleeAutoAttack(Unit const* pVictim, float flat_mod = 0.0f) const;
        bool CanReachWithMeleeAutoAttackAtPosition(Unit const* pVictim, float x, float y, float z, float flat_mod = 0.0f) const;
        float GetMeleeReach() const;
        float GetCombatReach(bool forMeleeRange /*=true*/) const;
        float GetCombatReach(Unit const* pVictim, bool ability, float flat_mod) const;
        void SetMeleeZLimit(float newZLimit) { m_meleeZLimit = newZLimit; }
        float GetMeleeZLimit() const { return m_meleeZLimit; }
        void SetMeleeZReach(float newZReach) { m_meleeZReach = newZReach; }
        float GetMeleeZReach() const { return m_meleeZReach; }
        void GetRandomAttackPoint(Unit const* target, float &x, float &y, float &z) const;

        /**
         * Tries to attack a Unit/Player, also makes sure to stop attacking the current target
         * if we're already attacking someone.
         * @param victim The Unit to attack
         * @param meleeAttack Whether we should attack with melee or ranged/magic
         * @return True if an attack was initiated, false otherwise
         */
        bool Attack(Unit* victim, bool meleeAttack);
        /**
         * Called when we are attacked by someone in someway, might be when a fear runs out and
         * we want to notify AI to attack again or when a spell hits.
         * @param attacker Who's attacking us
         */
        void AttackedBy(Unit* attacker);
        /**
         * Stops attacking whatever we are attacking at the moment and tells the Unit we are attacking
         * that we are not doing that anymore.
         * @param targetSwitch if we are switching targets or not, defaults to false
         * @return false if we weren't attacking already, true otherwise
         * \see Unit::m_attacking
         */
        bool AttackStop(bool targetSwitch = false);
        /**
         * Removes all attackers from the Unit::m_attackers set and logs it if someone that
         * wasn't attacking it was in the list. Does this check by checking if Unit::AttackStop()
         * returned false.
         * \see Unit::AttackStop
         */
        void RemoveAllAttackers();

        void _addAttacker(Unit* pAttacker)                  // (Internal Use) must be called only from Unit::Attack(Unit*)
        {
            AttackerSet::const_iterator itr = m_attackers.find(pAttacker);
            if (itr == m_attackers.end())
                m_attackers.insert(pAttacker);
        }
        void _removeAttacker(Unit* pAttacker)               // (Internal Use) must be called only from Unit::AttackStop()
        {
            m_attackers.erase(pAttacker);
        }
        Unit*  GetAttackerForHelper() const                 // Return a possible enemy from this unit to help in combat
        {
            if (GetVictim() != nullptr)
                return GetVictim();

            if (!m_attackers.empty())
                return *(m_attackers.begin());

            return nullptr;
        }

        // Returns the Unit::m_attackers, that stores the units that are attacking you
        AttackerSet const& GetAttackers() const { return m_attackers; }

        // Returns the victim that this unit is currently attacking
        Unit* GetVictim() const { return m_attacking; }
        bool SelectHostileTarget();
        Unit* GetTauntTarget() const;
        void TauntApply(Unit* pVictim);
        void TauntFadeOut(Unit* taunter);
        
        // Threat related methods
        bool CanHaveThreatList() const;
        bool IsSecondaryThreatTarget() const;
        void AddThreat(Unit* pVictim, float threat = 0.0f, bool crit = false, SpellSchoolMask schoolMask = SPELL_SCHOOL_MASK_NONE, SpellEntry const* threatSpell = nullptr);
        float ApplyTotalThreatModifier(float threat, SpellSchoolMask schoolMask = SPELL_SCHOOL_MASK_NORMAL);
        void RemoveAttackersThreat(Unit* owner);
        void DeleteThreatList();
        ThreatManager& GetThreatManager() { return m_ThreatManager; }
        ThreatManager const& GetThreatManager() const { return m_ThreatManager; }

        void AddHatedBy(HostileReference* pHostileReference) { m_HostileRefManager.insertFirst(pHostileReference); };
        void RemoveHatedBy(HostileReference* /*pHostileReference*/) { /* nothing to do yet */ }
        HostileRefManager& GetHostileRefManager() { return m_HostileRefManager; }
        HostileRefManager const& GetHostileRefManager() const { return m_HostileRefManager; }

        // Script Helpers
        uint8 GetEnemyCountInRadiusAround(Unit* pTarget, float radius) const;
        Unit* SelectNearestTarget(float dist) const;
        Unit* SelectRandomUnfriendlyTarget(Unit* except = nullptr, float radius = ATTACK_DISTANCE, bool inFront = false, bool isValidAttackTarget = false) const;
        Unit* SelectRandomFriendlyTarget(Unit* except = nullptr, float radius = ATTACK_DISTANCE, bool inCombat = false) const;
        Player* FindNearestHostilePlayer(float range) const;
        Player* FindNearestFriendlyPlayer(float range) const;
        Unit* FindLowestHpFriendlyUnit(float fRange, uint32 uiMinHPDiff = 1, bool bPercent = false, Unit* except = nullptr) const;
        Unit* FindFriendlyUnitMissingBuff(float range, uint32 spellid, Unit* except = nullptr) const;
        Unit* FindFriendlyUnitCC(float range) const;
        Unit* SummonCreatureAndAttack(uint32 creatureEntry, Unit* pVictim = nullptr);

        // Kills the victim.
        void DoKillUnit(Unit* pVictim = nullptr);
        uint32 DealDamage(Unit* pVictim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellSchoolMask damageSchoolMask, SpellEntry const* spellProto, bool durabilityLoss, Spell* spell = nullptr) final;

        // Called after this unit kills someone.
        void Kill(Unit* pVictim, SpellEntry const* spellProto, bool durabilityLoss = true);
        void PetOwnerKilledUnit(Unit* pVictim);
        
        bool IsInCombat() const { return HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT); }
        void SetInCombatState(bool bPvP, Unit* pEnemy = nullptr);
        void SetInCombatWith(Unit* pEnemy);
        void SetInCombatWithAssisted(Unit* pAssisted);
        void SetInCombatWithAggressor(Unit* pAggressor, bool touchOnly = false);
        inline void SetOutOfCombatWithAggressor(Unit* pAggressor) { SetInCombatWithAggressor(pAggressor, true); }
        void SetInCombatWithVictim(Unit* pVictim, bool touchOnly = false);
        inline void SetOutOfCombatWithVictim(Unit* pVictim) { SetInCombatWithVictim(pVictim, true); }
        void TogglePlayerPvPFlagOnAttackVictim(Unit const* pVictim, bool touchOnly = false);
        uint32 GetCombatTimer() const { return m_CombatTimer; }
        void SetCombatTimer(uint32 t) { m_CombatTimer = t; }
        virtual void OnEnterCombat(Unit* /*pAttacker*/, bool /*notInCombat*/) {} // (pAttacker must be valid)

        // Stop this unit from combat, if includingCast==true, also interrupt casting
        void CombatStop(bool includingCast = false);
        void CombatStopWithPets(bool includingCast = false);
        void StopAttackFaction(uint32 faction_id);
        void CombatStopInRange(float dist = 0.0f); // CombatStop all enemies
        void ClearInCombat();
        virtual void OnLeaveCombat() {}
        void InterruptSpellsCastedOnMe(bool killDelayed = false, bool interruptPositiveSpells = false);
        void InterruptAttacksOnMe(float dist = 0.0f, bool guard_check = false); // Interrupt auto-attacks
        
        // Script helpers.
        uint32 DespawnNearCreaturesByEntry(uint32 entry, float range);
        uint32 RespawnNearCreaturesByEntry(uint32 entry, float range);
        
        /*********************************************************/
        /***                 RELATIONS SYSTEM                  ***/
        /*********************************************************/

    private:
        Unit* _GetTotem(TotemSlot slot) const;              // for templated function without include need
        Pet* _GetPet(ObjectGuid guid) const;                // for templated function without include need
        FollowerRefManager m_FollowingRefManager;
        GuardianPetList m_guardianPets;
        ObjectGuid m_TotemSlot[MAX_TOTEM_SLOT];
    protected:
        CharmInfo* m_charmInfo;
        ObjectGuid m_possessorGuid; // Guid of unit possessing this one
    public:
        uint32 GetFactionTemplateId() const final { return GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE); }
        void SetFactionTemplateId(uint32 faction) { SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, faction); }
        void RestoreFaction();

        bool IsHostileTo(WorldObject const* target) const override;
        bool IsHostileToPlayers() const;
        bool IsFriendlyTo(WorldObject const* target) const override;
        bool IsNeutralToAll() const;
        bool IsContestedGuard() const;
        bool IsInPartyWith(Unit const* unit) const;
        bool IsInRaidWith(Unit const* unit) const;

        bool IsPvP() const { return HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP); }
        void SetPvP(bool state);
        bool IsPvPContested() const;
        void SetPvPContested(bool state);
        bool IsPassiveToHostile() const { return HasFlag(UNIT_FIELD_FLAGS, (UNIT_FLAG_IMMUNE_TO_PLAYER | UNIT_FLAG_IMMUNE_TO_NPC)); }

        void SetTargetGuid(ObjectGuid targetGuid) { SetGuidValue(UNIT_FIELD_TARGET, targetGuid); }
        ObjectGuid const& GetTargetGuid() const { return GetGuidValue(UNIT_FIELD_TARGET); }
        void ClearTarget() { SetTargetGuid(ObjectGuid()); }
        ObjectGuid const& GetChannelObjectGuid() const { return GetGuidValue(UNIT_FIELD_CHANNEL_OBJECT); }
        void SetChannelObjectGuid(ObjectGuid targetGuid) { SetGuidValue(UNIT_FIELD_CHANNEL_OBJECT, targetGuid); }

        CharmInfo* GetCharmInfo() const { return m_charmInfo; }
        CharmInfo* InitCharmInfo(Unit* charm);

        Unit* GetOwner() const;
        Creature* GetOwnerCreature() const;
        ObjectGuid const& GetOwnerGuid() const { return  GetGuidValue(UNIT_FIELD_SUMMONEDBY); }
        void SetOwnerGuid(ObjectGuid owner) { SetGuidValue(UNIT_FIELD_SUMMONEDBY, owner); ForceValuesUpdateAtIndex(UNIT_FIELD_HEALTH); ForceValuesUpdateAtIndex(UNIT_FIELD_MAXHEALTH); }
        ObjectGuid const& GetCreatorGuid() const { return GetGuidValue(UNIT_FIELD_CREATEDBY); }
        void SetCreatorGuid(ObjectGuid creator) { SetGuidValue(UNIT_FIELD_CREATEDBY, creator); }
        
        ObjectGuid const& GetPetGuid() const { return GetGuidValue(UNIT_FIELD_SUMMON); }
        void SetPetGuid(ObjectGuid pet) { SetGuidValue(UNIT_FIELD_SUMMON, pet); }
        Pet* GetPet() const;
        void SetPet(Pet* pet);
        virtual Pet* GetMiniPet() const { return nullptr; }    // overwritten in Player
        bool UnsummonOldPetBeforeNewSummon(uint32 newPetEntry);

        // Pet responses methods
        void SendPetCastFail(uint32 spellid, SpellCastResult msg);
        void SendPetActionFeedback(uint8 msg);
        void SendPetTalk(uint32 pettalk);
        void SendPetAIReaction();

        void AddGuardian(Pet* pet);
        void RemoveGuardian(Pet* pet);
        void RemoveGuardians();
        void RemoveGuardiansWithEntry(uint32 entry);
        Pet* FindGuardianWithEntry(uint32 entry);
        uint32 GetGuardianCountWithEntry(uint32 entry);

        ObjectGuid const& GetTotemGuid(TotemSlot slot) const { return m_TotemSlot[slot]; }
        Totem* GetTotem(TotemSlot slot) const;
        bool IsAllTotemSlotsUsed() const;
        void _AddTotem(TotemSlot slot, Totem* totem);       // only for call from Totem summon code
        void _RemoveTotem(Totem* totem);                    // only for call from Totem class
        void UnsummonAllTotems();

        Unit* GetCharmer() const;
        ObjectGuid const& GetCharmerGuid() const { return GetGuidValue(UNIT_FIELD_CHARMEDBY); }
        void SetCharmerGuid(ObjectGuid owner) { SetGuidValue(UNIT_FIELD_CHARMEDBY, owner); ForceValuesUpdateAtIndex(UNIT_FIELD_HEALTH); ForceValuesUpdateAtIndex(UNIT_FIELD_MAXHEALTH); }
        bool IsCharmed() const { return !GetCharmerGuid().IsEmpty(); }
        bool IsCharmerOrOwnerPlayerOrPlayerItself() const final { return IsPlayer() || GetCharmerOrOwnerGuid().IsPlayer(); }
        ObjectGuid const& GetCharmerOrOwnerGuid() const { return GetCharmerGuid() ? GetCharmerGuid() : GetOwnerGuid(); }
        ObjectGuid const& GetCharmerOrOwnerOrOwnGuid() const
        {
            if (ObjectGuid const& guid = GetCharmerOrOwnerGuid())
                return guid;
            return GetObjectGuid();
        }
        Player* GetCharmerOrOwnerPlayerOrPlayerItself() const;
        Unit* GetCharmerOrOwner() const { return GetCharmerGuid() ? GetCharmer() : GetOwner(); }
        Unit* GetCharmerOrOwnerOrSelf()
        {
            if (Unit* u = GetCharmerOrOwner())
                return u;

            return this;
        }
        Unit const* GetCharmerOrOwnerOrSelf() const
        {
            Unit const* u = GetCharmerOrOwner();
            return u ? u : this;
        }

        Unit* GetCharm() const;
        void SetCharm(Unit* pet);
        void Uncharm();
        void RemoveCharmAuras();
        ObjectGuid const& GetCharmGuid() const { return GetGuidValue(UNIT_FIELD_CHARM); }
        void SetCharmGuid(ObjectGuid charm) { SetGuidValue(UNIT_FIELD_CHARM, charm); }

        Player* GetSpellModOwner() const;
        Player* GetAffectingPlayer() const final;

        Player* GetPossessor() const;
        ObjectGuid const& GetPossessorGuid() const { return m_possessorGuid; }
        void SetPossessorGuid(ObjectGuid possession) { m_possessorGuid = possession; }
        
        template<typename Func>
        void CallForAllControlledUnits(Func const& func, uint32 controlledMask);
        template<typename Func>
        bool CheckAllControlledUnits(Func const& func, uint32 controlledMask) const;

        void AddFollower(FollowerReference* pRef) { m_FollowingRefManager.insertFirst(pRef); }
        void RemoveFollower(FollowerReference* /*pRef*/) { /* nothing to do yet */ }

        /*********************************************************/
        /***                 MOVEMENT SYSTEM                   ***/
        /*********************************************************/

    private:
        // when a player controls this unit, and when change is made to this unit which requires an ack from the client to be acted (change of speed for example), this movementCounter is incremented
        uint32 m_movementCounter = 0;
        std::deque<PlayerMovementPendingChange> m_pendingMovementChanges;
        std::map<MovementChangeType, uint32> m_lastMovementChangeCounterPerType;
        float m_casterChaseDistance;
        float m_speed_rate[MAX_MOVE_TYPE];
        float m_jumpInitialSpeed = 0;
        void UpdateSplineMovement(uint32 t_diff);
    protected:
        MotionMaster i_motionMaster;
    public:
        void SendHeartBeat(bool includingSelf = true);
        void SendMovementPacket(uint16 opcode, bool includingSelf = true);
        virtual void SetFly(bool enable);
        
        void SetRooted(bool apply);
        void SetRootedReal(bool apply);
        bool IsRooted() const { return m_movementInfo.HasMovementFlag(MOVEFLAG_ROOT); }

        void SetWaterWalking(bool apply);
        void SetWaterWalkingReal(bool apply);
        bool IsWaterWalking() const { return m_movementInfo.HasMovementFlag(MOVEFLAG_WATERWALKING); }

        void SetHover(bool apply);
        void SetHoverReal(bool apply);
        bool IsHovering() const { return m_movementInfo.HasMovementFlag(MOVEFLAG_HOVER); }

        void SetFeatherFall(bool apply);
        void SetFeatherFallReal(bool apply);
        bool IsFallingSlow() const { return m_movementInfo.HasMovementFlag(MOVEFLAG_SAFE_FALL); }

        void SetLevitate(bool apply);
        bool IsLevitating() const { return m_movementInfo.HasMovementFlag(MOVEFLAG_LEVITATING); }

        void KnockBackFrom(WorldObject* target, float horizontalSpeed, float verticalSpeed);
        void KnockBack(float angle, float horizontalSpeed, float verticalSpeed);

        // reflects direct client control (examples: a player MC another player or a creature (possess effects). etc...)
        bool IsMovedByPlayer() const;
        Player* GetPlayerMovingMe();

        uint32 GetMovementCounterAndInc() { return m_movementCounter++; }
        uint32 GetMovementCounter() const { return m_movementCounter; }
        uint32 GetLastCounterForMovementChangeType(MovementChangeType changeType)
        {
            return m_lastMovementChangeCounterPerType[changeType];
        }

        PlayerMovementPendingChange PopPendingMovementChange();
        void PushPendingMovementChange(PlayerMovementPendingChange newChange);
        bool HasPendingMovementChange() const { return !m_pendingMovementChanges.empty(); }
        bool HasPendingMovementChange(MovementChangeType changeType) const;
        void ResolvePendingMovementChanges(bool sendToClient, bool includingTeleport);
        void ResolvePendingMovementChange(PlayerMovementPendingChange& change, bool sendToClient);
        bool FindPendingMovementFlagChange(uint32 movementCounter, bool applyReceived, MovementChangeType changeTypeReceived);
        bool FindPendingMovementRootChange(uint32 movementCounter, bool applyReceived);
        bool FindPendingMovementTeleportChange(uint32 movementCounter);
        bool FindPendingMovementKnockbackChange(MovementInfo& movementInfo, uint32 movementCounter);
        bool FindPendingMovementSpeedChange(float speedReceived, uint32 movementCounter, UnitMoveType moveType);
        void CheckPendingMovementChanges();

        void SetWalk(bool enable, bool asDefault = true);
        void SetSpeedRate(UnitMoveType mtype, float rate);
        void SetSpeedRateReal(UnitMoveType mtype, float rate);
        void UpdateSpeed(UnitMoveType mtype, bool forced, float ratio = 1.0f);
        float GetSpeed(UnitMoveType mtype) const;
        float GetXZFlagBasedSpeed() const;
        float GetXZFlagBasedSpeed(uint32 moveFlags) const;
        float GetSpeedRate(UnitMoveType mtype) const { return m_speed_rate[mtype]; }
        void PropagateSpeedChange() { GetMotionMaster()->PropagateSpeedChange(); }
        float GetSpeedForMovementInfo(MovementInfo const& movementInfo) const;
        bool ExtrapolateMovement(MovementInfo const& mi, uint32 diffMs, float &x, float &y, float &z, float &o) const;
        void SetJumpInitialSpeed(float speed) { m_jumpInitialSpeed = speed; }
        float GetJumpInitialSpeed() const { return m_jumpInitialSpeed; }

        // Terrain checks
        virtual bool IsInWater() const;
        virtual bool IsUnderwater() const;
        bool IsReachableBySwmming() const;
        bool IsInAccessablePlaceFor(Creature const* c) const;

        // Inhabit type checks
        virtual bool CanWalk() const = 0;
        virtual bool CanFly() const = 0;
        virtual bool CanSwim() const = 0;
        
        void SetInFront(Unit const* pTarget);
        void SetFacingTo(float ori);
        void SetFacingToObject(WorldObject* pObject);
        bool IsBehindTarget(Unit const* pTarget, bool strict = true) const;
        bool CantPathToVictim() const;

        MotionMaster* GetMotionMaster() { return &i_motionMaster; }
        MotionMaster const* GetMotionMaster() const { return &i_motionMaster; }
        void RestoreMovement();

        template <class T>
        void NearTeleportTo(T const& pos, uint32 teleportOptions = TELE_TO_NOT_LEAVE_TRANSPORT | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET) { NearTeleportTo(pos.x, pos.y, pos.z, pos.o, teleportOptions); }
        void NearTeleportTo(float x, float y, float z, float orientation, uint32 teleportOptions = TELE_TO_NOT_LEAVE_TRANSPORT | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET);
        void NearLandTo(float x, float y, float z, float orientation);
        template <class T>
        void TeleportPositionRelocation(T const& pos) { TeleportPositionRelocation(pos.x, pos.y, pos.z, pos.o); }
        void TeleportPositionRelocation(float x, float y, float z, float o);

        void MonsterMove(float x, float y, float z);
        void MonsterMoveWithSpeed(float x, float y, float z, float o, float speed, uint32 options);
        bool IsStopped() const { return !(HasUnitState(UNIT_STAT_MOVING)); }
        void StopMoving(bool force = false);
        void DisableSpline();

        // Caster movement
        float GetMinChaseDistance(Unit* target) const;
        float GetMaxChaseDistance(Unit* target) const;
        bool HasDistanceCasterMovement() const { return (m_casterChaseDistance >= 1.0f); }
        void SetCasterChaseDistance(float dist) { m_casterChaseDistance = dist; }

        Movement::MoveSpline* movespline;
        // Serialize access to the movespline to prevent thread race conditions in async
        // move spline updates (one thread updates a spline, while another checks the
        // spline for end point with targeted move gen)
        std::mutex asyncMovesplineLock;

        void OnRelocated();
        void ProcessRelocationVisibilityUpdates();
        bool m_needUpdateVisibility;

    protected:
        explicit Unit ();     
};

inline Unit* Object::ToUnit()
{
    return IsUnit() ? static_cast<Unit*>(this) : nullptr;
}

inline Unit const* Object::ToUnit() const
{
    return IsUnit() ? static_cast<Unit const*>(this) : nullptr;
}

inline Unit* ToUnit(Object* object)
{
    return object && object->IsUnit() ? static_cast<Unit*>(object) : nullptr;
}

inline Unit const* ToUnit(Object const* object)
{
    return object && object->IsUnit() ? static_cast<Unit const*>(object) : nullptr;
}

template<typename Func>
void Unit::CallForAllControlledUnits(Func const& func, uint32 controlledMask)
{
    if (controlledMask & CONTROLLED_PET)
        if (Pet* pet = GetPet())
            func(pet);

    if (controlledMask & CONTROLLED_MINIPET)
        if (Pet* mini = GetMiniPet())
            func(mini);

    if (controlledMask & CONTROLLED_GUARDIANS)
    {
        for(GuardianPetList::const_iterator itr = m_guardianPets.begin(); itr != m_guardianPets.end();)
            if (Pet* guardian = _GetPet(*(itr++)))
                func(guardian);
    }

    if (controlledMask & CONTROLLED_TOTEMS)
    {
        for (int i = 0; i < MAX_TOTEM_SLOT; ++i)
            if (Unit* totem = _GetTotem(TotemSlot(i)))
                func(totem);
    }

    if (controlledMask & CONTROLLED_CHARM)
        if (Unit* charm = GetCharm())
            func(charm);
}


template<typename Func>
bool Unit::CheckAllControlledUnits(Func const& func, uint32 controlledMask) const
{
    if (controlledMask & CONTROLLED_PET)
        if (Pet const* pet = GetPet())
            if (func(pet))
                return true;

    if (controlledMask & CONTROLLED_MINIPET)
        if (Pet* mini = GetMiniPet())
            if (func(mini))
                return true;

    if (controlledMask & CONTROLLED_GUARDIANS)
    {
        for(GuardianPetList::const_iterator itr = m_guardianPets.begin(); itr != m_guardianPets.end();)
            if (Pet const* guardian = _GetPet(*(itr++)))
                if (func(guardian))
                    return true;

    }

    if (controlledMask & CONTROLLED_TOTEMS)
    {
        for (int i = 0; i < MAX_TOTEM_SLOT; ++i)
            if (Unit const* totem = _GetTotem(TotemSlot(i)))
                if (func(totem))
                    return true;
    }

    if (controlledMask & CONTROLLED_CHARM)
        if (Unit const* charm = GetCharm())
            if (func(charm))
                return true;

    return false;
}

#endif
