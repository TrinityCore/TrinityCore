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

#ifndef __UNIT_H
#define __UNIT_H

#include "Object.h"
#include "CombatManager.h"
#include "OptionalFwd.h"
#include "SpellAuraDefines.h"
#include "ThreatManager.h"
#include "Timer.h"
#include "UnitDefines.h"
#include "Util.h"
#include <map>
#include <memory>
#include <stack>

#define VISUAL_WAYPOINT 1 // Creature Entry ID used for waypoints show, visible only for GMs
#define WORLD_TRIGGER 12999

#define MAX_SPELL_CHARM         4
#define MAX_SPELL_VEHICLE       6
#define MAX_SPELL_POSSESS       8
#define MAX_SPELL_CONTROL_BAR   10

#define MAX_AGGRO_RESET_TIME 10 // in seconds
#define MAX_AGGRO_RADIUS 45.0f  // yards

enum VictimState
{
    VICTIMSTATE_INTACT         = 0, // set when attacker misses
    VICTIMSTATE_HIT            = 1, // victim got clear/blocked hit
    VICTIMSTATE_DODGE          = 2,
    VICTIMSTATE_PARRY          = 3,
    VICTIMSTATE_INTERRUPT      = 4,
    VICTIMSTATE_BLOCKS         = 5, // unused? not set when blocked, even on full block
    VICTIMSTATE_EVADES         = 6,
    VICTIMSTATE_IS_IMMUNE      = 7,
    VICTIMSTATE_DEFLECTS       = 8
};

//i would like to remove this: (it is defined in item.h
enum InventorySlot
{
    NULL_BAG                   = 0,
    NULL_SLOT                  = 255
};

struct AbstractFollower;
struct FactionTemplateEntry;
struct LiquidData;
struct LiquidTypeEntry;
struct SpellValue;

class Aura;
class AuraApplication;
class AuraEffect;
class Creature;
class DynamicObject;
class GameObject;
class Guardian;
class Item;
class Minion;
class MotionMaster;
class Pet;
class PetAura;
class Spell;
class SpellCastTargets;
class SpellHistory;
class SpellInfo;
class Totem;
class Transport;
class TransportBase;
class UnitAI;
class UnitAura;
class Vehicle;
class VehicleJoinEvent;

enum ZLiquidStatus : uint32;
enum MovementGeneratorType : uint8;

typedef std::list<Unit*> UnitList;

class DispelableAura
{
    public:
        DispelableAura(Aura* aura, int32 dispelChance, uint8 dispelCharges);
        ~DispelableAura();

        Aura* GetAura() const { return _aura; }
        bool RollDispel() const;
        uint8 GetDispelCharges() const { return _charges; }

        void IncrementCharges() { ++_charges; }
        bool DecrementCharge()
        {
            if (!_charges)
                return false;

            --_charges;
            return _charges > 0;
        }

    private:
        Aura* _aura;
        int32 _chance;
        uint8 _charges;
};
typedef std::vector<DispelableAura> DispelChargesList;

typedef std::unordered_multimap<uint32 /*type*/, uint32 /*spellId*/> SpellImmuneContainer;

enum UnitModifierFlatType
{
    BASE_VALUE = 0,
    TOTAL_VALUE = 1,
    MODIFIER_TYPE_FLAT_END = 2
};

enum UnitModifierPctType
{
    BASE_PCT = 0,
    TOTAL_PCT = 1,
    MODIFIER_TYPE_PCT_END = 2
};

enum WeaponDamageRange
{
    MINDAMAGE,
    MAXDAMAGE
};

enum UnitMods
{
    UNIT_MOD_STAT_STRENGTH,                                 // UNIT_MOD_STAT_STRENGTH..UNIT_MOD_STAT_SPIRIT must be in existed order, it's accessed by index values of Stats enum.
    UNIT_MOD_STAT_AGILITY,
    UNIT_MOD_STAT_STAMINA,
    UNIT_MOD_STAT_INTELLECT,
    UNIT_MOD_STAT_SPIRIT,
    UNIT_MOD_HEALTH,
    UNIT_MOD_MANA,                                          // UNIT_MOD_MANA..UNIT_MOD_RUNIC_POWER must be in existed order, it's accessed by index values of Powers enum.
    UNIT_MOD_RAGE,
    UNIT_MOD_FOCUS,
    UNIT_MOD_ENERGY,
    UNIT_MOD_HAPPINESS,
    UNIT_MOD_RUNE,
    UNIT_MOD_RUNIC_POWER,
    UNIT_MOD_ARMOR,                                         // UNIT_MOD_ARMOR..UNIT_MOD_RESISTANCE_ARCANE must be in existed order, it's accessed by index values of SpellSchools enum.
    UNIT_MOD_RESISTANCE_HOLY,
    UNIT_MOD_RESISTANCE_FIRE,
    UNIT_MOD_RESISTANCE_NATURE,
    UNIT_MOD_RESISTANCE_FROST,
    UNIT_MOD_RESISTANCE_SHADOW,
    UNIT_MOD_RESISTANCE_ARCANE,
    UNIT_MOD_ATTACK_POWER,
    UNIT_MOD_ATTACK_POWER_RANGED,
    UNIT_MOD_DAMAGE_MAINHAND,
    UNIT_MOD_DAMAGE_OFFHAND,
    UNIT_MOD_DAMAGE_RANGED,
    UNIT_MOD_END,
    // synonyms
    UNIT_MOD_STAT_START = UNIT_MOD_STAT_STRENGTH,
    UNIT_MOD_STAT_END = UNIT_MOD_STAT_SPIRIT + 1,
    UNIT_MOD_RESISTANCE_START = UNIT_MOD_ARMOR,
    UNIT_MOD_RESISTANCE_END = UNIT_MOD_RESISTANCE_ARCANE + 1,
    UNIT_MOD_POWER_START = UNIT_MOD_MANA,
    UNIT_MOD_POWER_END = UNIT_MOD_RUNIC_POWER + 1
};

enum BaseModGroup
{
    CRIT_PERCENTAGE,
    RANGED_CRIT_PERCENTAGE,
    OFFHAND_CRIT_PERCENTAGE,
    SHIELD_BLOCK_VALUE,
    BASEMOD_END
};

enum BaseModType
{
    FLAT_MOD,
    PCT_MOD,
    MOD_END
};

enum DeathState
{
    ALIVE          = 0,
    JUST_DIED      = 1,
    CORPSE         = 2,
    DEAD           = 3,
    JUST_RESPAWNED = 4
};

enum UnitState : uint32
{
    UNIT_STATE_DIED                = 0x00000001,                     // player has fake death aura
    UNIT_STATE_MELEE_ATTACKING     = 0x00000002,                     // player is melee attacking someone
    UNIT_STATE_CHARMED             = 0x00000004,                     // having any kind of charm aura on self
    UNIT_STATE_STUNNED             = 0x00000008,
    UNIT_STATE_ROAMING             = 0x00000010,
    UNIT_STATE_CHASE               = 0x00000020,
    UNIT_STATE_FOCUSING            = 0x00000040,
    UNIT_STATE_FLEEING             = 0x00000080,
    UNIT_STATE_IN_FLIGHT           = 0x00000100,                     // player is in flight mode
    UNIT_STATE_FOLLOW              = 0x00000200,
    UNIT_STATE_ROOT                = 0x00000400,
    UNIT_STATE_CONFUSED            = 0x00000800,
    UNIT_STATE_DISTRACTED          = 0x00001000,
    UNIT_STATE_ISOLATED            = 0x00002000,                     // area auras do not affect other players
    UNIT_STATE_ATTACK_PLAYER       = 0x00004000,
    UNIT_STATE_CASTING             = 0x00008000,
    UNIT_STATE_POSSESSED           = 0x00010000,                     // being possessed by another unit
    UNIT_STATE_CHARGING            = 0x00020000,
    UNIT_STATE_JUMPING             = 0x00040000,
    UNIT_STATE_MOVE                = 0x00100000,
    UNIT_STATE_ROTATING            = 0x00200000,
    UNIT_STATE_EVADE               = 0x00400000,
    UNIT_STATE_ROAMING_MOVE        = 0x00800000,
    UNIT_STATE_CONFUSED_MOVE       = 0x01000000,
    UNIT_STATE_FLEEING_MOVE        = 0x02000000,
    UNIT_STATE_CHASE_MOVE          = 0x04000000,
    UNIT_STATE_FOLLOW_MOVE         = 0x08000000,
    UNIT_STATE_IGNORE_PATHFINDING  = 0x10000000,                 // do not use pathfinding in any MovementGenerator

    UNIT_STATE_ALL_STATE_SUPPORTED = UNIT_STATE_DIED | UNIT_STATE_MELEE_ATTACKING | UNIT_STATE_CHARMED | UNIT_STATE_STUNNED | UNIT_STATE_ROAMING | UNIT_STATE_CHASE
                                   | UNIT_STATE_FOCUSING | UNIT_STATE_FLEEING | UNIT_STATE_IN_FLIGHT | UNIT_STATE_FOLLOW | UNIT_STATE_ROOT | UNIT_STATE_CONFUSED
                                   | UNIT_STATE_DISTRACTED | UNIT_STATE_ISOLATED | UNIT_STATE_ATTACK_PLAYER | UNIT_STATE_CASTING
                                   | UNIT_STATE_POSSESSED | UNIT_STATE_CHARGING | UNIT_STATE_JUMPING | UNIT_STATE_MOVE | UNIT_STATE_ROTATING
                                   | UNIT_STATE_EVADE | UNIT_STATE_ROAMING_MOVE | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE
                                   | UNIT_STATE_CHASE_MOVE | UNIT_STATE_FOLLOW_MOVE | UNIT_STATE_IGNORE_PATHFINDING,

    UNIT_STATE_UNATTACKABLE        = UNIT_STATE_IN_FLIGHT,
    UNIT_STATE_MOVING              = UNIT_STATE_ROAMING_MOVE | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE | UNIT_STATE_CHASE_MOVE | UNIT_STATE_FOLLOW_MOVE,
    UNIT_STATE_CONTROLLED          = UNIT_STATE_CONFUSED | UNIT_STATE_STUNNED | UNIT_STATE_FLEEING,
    UNIT_STATE_LOST_CONTROL        = UNIT_STATE_CONTROLLED | UNIT_STATE_POSSESSED | UNIT_STATE_JUMPING | UNIT_STATE_CHARGING,
    UNIT_STATE_CANNOT_AUTOATTACK   = UNIT_STATE_CONTROLLED | UNIT_STATE_CHARGING | UNIT_STATE_CASTING,
    UNIT_STATE_SIGHTLESS           = UNIT_STATE_LOST_CONTROL | UNIT_STATE_EVADE,
    UNIT_STATE_CANNOT_TURN         = UNIT_STATE_LOST_CONTROL | UNIT_STATE_ROTATING | UNIT_STATE_FOCUSING,
    UNIT_STATE_NOT_MOVE            = UNIT_STATE_ROOT | UNIT_STATE_STUNNED | UNIT_STATE_DIED | UNIT_STATE_DISTRACTED,

    UNIT_STATE_ALL_ERASABLE        = UNIT_STATE_ALL_STATE_SUPPORTED & ~(UNIT_STATE_IGNORE_PATHFINDING),
    UNIT_STATE_ALL_STATE           = 0xffffffff
};

enum UnitMoveType
{
    MOVE_WALK           = 0,
    MOVE_RUN            = 1,
    MOVE_RUN_BACK       = 2,
    MOVE_SWIM           = 3,
    MOVE_SWIM_BACK      = 4,
    MOVE_TURN_RATE      = 5,
    MOVE_FLIGHT         = 6,
    MOVE_FLIGHT_BACK    = 7,
    MOVE_PITCH_RATE     = 8
};

#define MAX_MOVE_TYPE     9

TC_GAME_API extern float baseMoveSpeed[MAX_MOVE_TYPE];
TC_GAME_API extern float playerBaseMoveSpeed[MAX_MOVE_TYPE];

enum CombatRating
{
    CR_WEAPON_SKILL             = 0,
    CR_DEFENSE_SKILL            = 1,
    CR_DODGE                    = 2,
    CR_PARRY                    = 3,
    CR_BLOCK                    = 4,
    CR_HIT_MELEE                = 5,
    CR_HIT_RANGED               = 6,
    CR_HIT_SPELL                = 7,
    CR_CRIT_MELEE               = 8,
    CR_CRIT_RANGED              = 9,
    CR_CRIT_SPELL               = 10,
    CR_HIT_TAKEN_MELEE          = 11,
    CR_HIT_TAKEN_RANGED         = 12,
    CR_HIT_TAKEN_SPELL          = 13,
    CR_CRIT_TAKEN_MELEE         = 14,
    CR_CRIT_TAKEN_RANGED        = 15,
    CR_CRIT_TAKEN_SPELL         = 16,
    CR_HASTE_MELEE              = 17,
    CR_HASTE_RANGED             = 18,
    CR_HASTE_SPELL              = 19,
    CR_WEAPON_SKILL_MAINHAND    = 20,
    CR_WEAPON_SKILL_OFFHAND     = 21,
    CR_WEAPON_SKILL_RANGED      = 22,
    CR_EXPERTISE                = 23,
    CR_ARMOR_PENETRATION        = 24
};

#define MAX_COMBAT_RATING         25

enum DamageEffectType : uint8
{
    DIRECT_DAMAGE           = 0,                            // used for normal weapon damage (not for class abilities or spells)
    SPELL_DIRECT_DAMAGE     = 1,                            // spell/class abilities damage
    DOT                     = 2,
    HEAL                    = 3,
    NODAMAGE                = 4,                            // used also in case when damage applied to health but not applied to spell channelInterruptFlags/etc
    SELF_DAMAGE             = 5
};

enum UnitTypeMask
{
    UNIT_MASK_NONE                  = 0x00000000,
    UNIT_MASK_SUMMON                = 0x00000001,
    UNIT_MASK_MINION                = 0x00000002,
    UNIT_MASK_GUARDIAN              = 0x00000004,
    UNIT_MASK_TOTEM                 = 0x00000008,
    UNIT_MASK_PET                   = 0x00000010,
    UNIT_MASK_VEHICLE               = 0x00000020,
    UNIT_MASK_PUPPET                = 0x00000040,
    UNIT_MASK_HUNTER_PET            = 0x00000080,
    UNIT_MASK_CONTROLABLE_GUARDIAN  = 0x00000100,
    UNIT_MASK_ACCESSORY             = 0x00000200
};

namespace Movement{
    class MoveSpline;
}

struct DiminishingReturn
{
    DiminishingReturn() : stack(0), hitTime(0), hitCount(DIMINISHING_LEVEL_1) { }

    void Clear()
    {
        stack = 0;
        hitTime = 0;
        hitCount = DIMINISHING_LEVEL_1;
    }

    uint16                  stack;
    uint32                  hitTime;
    uint32                  hitCount;
};

enum MeleeHitOutcome : uint8
{
    MELEE_HIT_EVADE, MELEE_HIT_MISS, MELEE_HIT_DODGE, MELEE_HIT_BLOCK, MELEE_HIT_PARRY,
    MELEE_HIT_GLANCING, MELEE_HIT_CRIT, MELEE_HIT_CRUSHING, MELEE_HIT_NORMAL
};

class DispelInfo
{
    public:
        explicit DispelInfo(WorldObject* dispeller, uint32 dispellerSpellId, uint8 chargesRemoved) :
            _dispeller(dispeller), _dispellerSpell(dispellerSpellId), _chargesRemoved(chargesRemoved) { }

        WorldObject* GetDispeller() const { return _dispeller; }
        uint32 GetDispellerSpellId() const { return _dispellerSpell; }
        uint8 GetRemovedCharges() const { return _chargesRemoved; }
        void SetRemovedCharges(uint8 amount) { _chargesRemoved = amount; }
    private:
        WorldObject* _dispeller;
        uint32 _dispellerSpell;
        uint8 _chargesRemoved;
};

struct CleanDamage
{
    CleanDamage(uint32 mitigated, uint32 absorbed, WeaponAttackType _attackType, MeleeHitOutcome _hitOutCome) :
    absorbed_damage(absorbed), mitigated_damage(mitigated), attackType(_attackType), hitOutCome(_hitOutCome) { }

    uint32 absorbed_damage;
    uint32 mitigated_damage;

    WeaponAttackType attackType;
    MeleeHitOutcome hitOutCome;
};

struct CalcDamageInfo;
struct SpellNonMeleeDamage;

class TC_GAME_API DamageInfo
{
    private:
        Unit* const m_attacker;
        Unit* const m_victim;
        uint32 m_damage;
        SpellInfo const* const m_spellInfo;
        SpellSchoolMask const m_schoolMask;
        DamageEffectType const m_damageType;
        WeaponAttackType m_attackType;
        uint32 m_absorb;
        uint32 m_resist;
        uint32 m_block;
        uint32 m_hitMask;

        // amalgamation constructor (used for proc)
        DamageInfo(DamageInfo const& dmg1, DamageInfo const& dmg2);

    public:
        DamageInfo(Unit* attacker, Unit* victim, uint32 damage, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, DamageEffectType damageType, WeaponAttackType attackType);
        explicit DamageInfo(CalcDamageInfo const& dmgInfo); // amalgamation wrapper
        DamageInfo(CalcDamageInfo const& dmgInfo, uint8 damageIndex);
        DamageInfo(SpellNonMeleeDamage const& spellNonMeleeDamage, DamageEffectType damageType, WeaponAttackType attackType, uint32 hitMask);

        void ModifyDamage(int32 amount);
        void AbsorbDamage(uint32 amount);
        void ResistDamage(uint32 amount);
        void BlockDamage(uint32 amount);

        Unit* GetAttacker() const { return m_attacker; }
        Unit* GetVictim() const { return m_victim; }
        SpellInfo const* GetSpellInfo() const { return m_spellInfo; }
        SpellSchoolMask GetSchoolMask() const { return m_schoolMask; }
        DamageEffectType GetDamageType() const { return m_damageType; }
        WeaponAttackType GetAttackType() const { return m_attackType; }
        uint32 GetDamage() const { return m_damage; }
        uint32 GetAbsorb() const { return m_absorb; }
        uint32 GetResist() const { return m_resist; }
        uint32 GetBlock() const { return m_block; }

        uint32 GetHitMask() const;
};

class TC_GAME_API HealInfo
{
    private:
        Unit* const _healer;
        Unit* const _target;
        uint32 _heal;
        uint32 _effectiveHeal;
        uint32 _absorb;
        SpellInfo const* const _spellInfo;
        SpellSchoolMask const _schoolMask;
        uint32 _hitMask;

    public:
        HealInfo(Unit* healer, Unit* target, uint32 heal, SpellInfo const* spellInfo, SpellSchoolMask schoolMask);

        void AbsorbHeal(uint32 amount);
        void SetEffectiveHeal(uint32 amount) { _effectiveHeal = amount; }

        Unit* GetHealer() const { return _healer; }
        Unit* GetTarget() const { return _target; }
        uint32 GetHeal() const { return _heal; }
        uint32 GetEffectiveHeal() const { return _effectiveHeal; }
        uint32 GetAbsorb() const { return _absorb; }
        SpellInfo const* GetSpellInfo() const { return _spellInfo; };
        SpellSchoolMask GetSchoolMask() const { return _schoolMask; };

        uint32 GetHitMask() const;
};

class TC_GAME_API ProcEventInfo
{
    public:
        ProcEventInfo(Unit* actor, Unit* actionTarget, Unit* procTarget, uint32 typeMask,
                      uint32 spellTypeMask, uint32 spellPhaseMask, uint32 hitMask,
                      Spell* spell, DamageInfo* damageInfo, HealInfo* healInfo);

        Unit* GetActor() { return _actor; }
        Unit* GetActionTarget() const { return _actionTarget; }
        Unit* GetProcTarget() const { return _procTarget; }

        uint32 GetTypeMask() const { return _typeMask; }
        uint32 GetSpellTypeMask() const { return _spellTypeMask; }
        uint32 GetSpellPhaseMask() const { return _spellPhaseMask; }
        uint32 GetHitMask() const { return _hitMask; }

        SpellInfo const* GetSpellInfo() const;
        SpellSchoolMask GetSchoolMask() const;

        DamageInfo* GetDamageInfo() const { return _damageInfo; }
        HealInfo* GetHealInfo() const { return _healInfo; }

        Spell const* GetProcSpell() const { return _spell; }

    private:
        Unit* const _actor;
        Unit* const _actionTarget;
        Unit* const _procTarget;
        uint32 _typeMask;
        uint32 _spellTypeMask;
        uint32 _spellPhaseMask;
        uint32 _hitMask;
        Spell* _spell;
        DamageInfo* _damageInfo;
        HealInfo* _healInfo;
};

// Struct for use in Unit::CalculateMeleeDamage
// Need create structure like in SMSG_ATTACKERSTATEUPDATE opcode
struct CalcDamageInfo
{
    Unit* Attacker;
    Unit* Target;

    struct
    {
        uint32 DamageSchoolMask;
        uint32 Damage;
        uint32 Absorb;
        uint32 Resist;
    } Damages[2];

    uint32 Blocked;
    uint32 HitInfo;
    uint32 TargetState;

    // Helpers
    WeaponAttackType AttackType;
    uint32 ProcAttacker;
    uint32 ProcVictim;
    uint32 CleanDamage;          // Used only for rage calculation
    MeleeHitOutcome HitOutCome;  /// @todo remove this field (need use TargetState)
};

// Spell damage info structure based on structure sending in SMSG_SPELLNONMELEEDAMAGELOG opcode
struct TC_GAME_API SpellNonMeleeDamage
{
    SpellNonMeleeDamage(Unit* _attacker, Unit* _target, uint32 _SpellID, uint32 _schoolMask)
        : target(_target), attacker(_attacker), SpellID(_SpellID), damage(0), overkill(0), schoolMask(_schoolMask),
        absorb(0), resist(0), periodicLog(false), unused(false), blocked(0), HitInfo(0), cleanDamage(0), fullBlock(false)
    { }

    Unit   *target;
    Unit   *attacker;
    uint32 SpellID;
    uint32 damage;
    uint32 overkill;
    uint32 schoolMask;
    uint32 absorb;
    uint32 resist;
    bool   periodicLog;
    bool   unused;
    uint32 blocked;
    uint32 HitInfo;
    // Used for help
    uint32 cleanDamage;
    bool   fullBlock;
};

struct SpellPeriodicAuraLogInfo
{
    SpellPeriodicAuraLogInfo(AuraEffect const* _auraEff, uint32 _damage, uint32 _overDamage, uint32 _absorb, uint32 _resist, float _multiplier, bool _critical)
        : auraEff(_auraEff), damage(_damage), overDamage(_overDamage), absorb(_absorb), resist(_resist), multiplier(_multiplier), critical(_critical){ }

    AuraEffect const* auraEff;
    uint32 damage;
    uint32 overDamage;                                      // overkill/overheal
    uint32 absorb;
    uint32 resist;
    float  multiplier;
    bool   critical;
};

uint32 createProcHitMask(SpellNonMeleeDamage* damageInfo, SpellMissInfo missCondition);

enum CurrentSpellTypes : uint8
{
    CURRENT_MELEE_SPELL             = 0,
    CURRENT_GENERIC_SPELL           = 1,
    CURRENT_CHANNELED_SPELL         = 2,
    CURRENT_AUTOREPEAT_SPELL        = 3
};

#define CURRENT_FIRST_NON_MELEE_SPELL 1
#define CURRENT_MAX_SPELL             4

#define UNIT_ACTION_BUTTON_ACTION(X) (uint32(X) & 0x00FFFFFF)
#define UNIT_ACTION_BUTTON_TYPE(X)   ((uint32(X) & 0xFF000000) >> 24)
#define MAKE_UNIT_ACTION_BUTTON(A, T) (uint32(A) | (uint32(T) << 24))

struct UnitActionBarEntry
{
    UnitActionBarEntry() : packedData(uint32(ACT_DISABLED) << 24) { }

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
        packedData = MAKE_UNIT_ACTION_BUTTON(action, type);
    }

    void SetType(ActiveStates type)
    {
        packedData = MAKE_UNIT_ACTION_BUTTON(UNIT_ACTION_BUTTON_ACTION(packedData), type);
    }

    void SetAction(uint32 action)
    {
        packedData = (packedData & 0xFF000000) | UNIT_ACTION_BUTTON_ACTION(action);
    }
};

typedef std::list<Player*> SharedVisionList;

enum CharmType
{
    CHARM_TYPE_CHARM,
    CHARM_TYPE_POSSESS,
    CHARM_TYPE_VEHICLE,
    CHARM_TYPE_CONVERT
};

typedef UnitActionBarEntry CharmSpellInfo;

enum ActionBarIndex
{
    ACTION_BAR_INDEX_START = 0,
    ACTION_BAR_INDEX_PET_SPELL_START = 3,
    ACTION_BAR_INDEX_PET_SPELL_END = 7,
    ACTION_BAR_INDEX_END = 10
};

#define MAX_UNIT_ACTION_BAR_INDEX (ACTION_BAR_INDEX_END-ACTION_BAR_INDEX_START)

struct TC_GAME_API CharmInfo
{
    public:
        explicit CharmInfo(Unit* unit);
        ~CharmInfo();
        void RestoreState();
        uint32 GetPetNumber() const { return _petnumber; }
        void SetPetNumber(uint32 petnumber, bool statwindow);

        void SetCommandState(CommandStates st) { _CommandState = st; }
        CommandStates GetCommandState() const { return _CommandState; }
        bool HasCommandState(CommandStates state) const { return (_CommandState == state); }

        void InitPossessCreateSpells();
        void InitCharmCreateSpells();
        void InitPetActionBar();
        void InitEmptyActionBar(bool withAttack = true);

                                                            //return true if successful
        bool AddSpellToActionBar(SpellInfo const* spellInfo, ActiveStates newstate = ACT_DECIDE, uint8 preferredSlot = 0);
        bool RemoveSpellFromActionBar(uint32 spell_id);
        void LoadPetActionBar(const std::string& data);
        void BuildActionBar(WorldPacket* data);
        void SetSpellAutocast(SpellInfo const* spellInfo, bool state);
        void SetActionBar(uint8 index, uint32 spellOrAction, ActiveStates type)
        {
            PetActionBar[index].SetActionAndType(spellOrAction, type);
        }
        UnitActionBarEntry const* GetActionBarEntry(uint8 index) const { return &(PetActionBar[index]); }

        void ToggleCreatureAutocast(SpellInfo const* spellInfo, bool apply);

        CharmSpellInfo* GetCharmSpell(uint8 index) { return &(_charmspells[index]); }

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

        Unit* _unit;
        UnitActionBarEntry PetActionBar[MAX_UNIT_ACTION_BAR_INDEX];
        CharmSpellInfo _charmspells[4];
        CommandStates _CommandState;
        uint32 _petnumber;

        //for restoration after charmed
        ReactStates     _oldReactState;

        bool _isCommandAttack;
        bool _isCommandFollow;
        bool _isAtStay;
        bool _isFollowing;
        bool _isReturning;
        float _stayX;
        float _stayY;
        float _stayZ;
};

// for clearing special attacks
#define REACTIVE_TIMER_START 4000

enum ReactiveType
{
    REACTIVE_DEFENSE        = 0,
    REACTIVE_HUNTER_PARRY   = 1,
    REACTIVE_OVERPOWER      = 2,
    REACTIVE_WOLVERINE_BITE = 3,
    MAX_REACTIVE
};

// delay time next attack to prevent client attack animation problems
#define ATTACK_DISPLAY_DELAY 200
#define MAX_PLAYER_STEALTH_DETECT_RANGE 30.0f               // max distance for detection targets by player

class TC_GAME_API Unit : public WorldObject
{
    public:
        typedef std::set<Unit*> AttackerSet;
        typedef std::set<Unit*> ControlList;
        typedef std::vector<Unit*> UnitVector;

        typedef std::multimap<uint32, Aura*> AuraMap;
        typedef std::pair<AuraMap::const_iterator, AuraMap::const_iterator> AuraMapBounds;
        typedef std::pair<AuraMap::iterator, AuraMap::iterator> AuraMapBoundsNonConst;

        typedef std::multimap<uint32,  AuraApplication*> AuraApplicationMap;
        typedef std::pair<AuraApplicationMap::const_iterator, AuraApplicationMap::const_iterator> AuraApplicationMapBounds;
        typedef std::pair<AuraApplicationMap::iterator, AuraApplicationMap::iterator> AuraApplicationMapBoundsNonConst;

        typedef std::multimap<AuraStateType,  AuraApplication*> AuraStateAurasMap;
        typedef std::pair<AuraStateAurasMap::const_iterator, AuraStateAurasMap::const_iterator> AuraStateAurasMapBounds;

        typedef std::list<AuraEffect*> AuraEffectList;
        typedef std::list<Aura*> AuraList;
        typedef std::list<AuraApplication*> AuraApplicationList;

        typedef std::vector<std::pair<uint8 /*procEffectMask*/, AuraApplication*>> AuraApplicationProcContainer;

        typedef std::map<uint8, AuraApplication*> VisibleAuraMap;

        virtual ~Unit();

        bool IsAIEnabled() const { return (i_AI != nullptr); }
        void AIUpdateTick(uint32 diff);
        UnitAI* GetAI() const { return i_AI.get(); }
        void ScheduleAIChange();
        void PushAI(UnitAI* newAI);
        bool PopAI();
    protected:
        void SetAI(UnitAI* newAI);
        UnitAI* GetTopAI() const { return i_AIs.empty() ? nullptr : i_AIs.top().get(); }
        void RefreshAI();
    public:

        void AddToWorld() override;
        void RemoveFromWorld() override;

        void CleanupBeforeRemoveFromMap(bool finalCleanup);
        void CleanupsBeforeDelete(bool finalCleanup = true) override;                        // used in ~Creature/~Player (or before mass creature delete to remove cross-references to already deleted units)

        virtual bool IsAffectedByDiminishingReturns() const { return (GetCharmerOrOwnerPlayerOrPlayerItself() != nullptr); }
        DiminishingLevels GetDiminishing(DiminishingGroup group) const;
        void IncrDiminishing(SpellInfo const* auraSpellInfo, bool triggered);
        bool ApplyDiminishingToDuration(SpellInfo const* auraSpellInfo, bool triggered, int32& duration, WorldObject* caster, DiminishingLevels previousLevel) const;
        void ApplyDiminishingAura(DiminishingGroup group, bool apply);
        void ClearDiminishings();

        virtual void Update(uint32 time) override;

        void setAttackTimer(WeaponAttackType type, uint32 time) { m_attackTimer[type] = time; }
        void resetAttackTimer(WeaponAttackType type = BASE_ATTACK);
        uint32 getAttackTimer(WeaponAttackType type) const { return m_attackTimer[type]; }
        bool isAttackReady(WeaponAttackType type = BASE_ATTACK) const { return m_attackTimer[type] == 0; }
        bool haveOffhandWeapon() const;
        bool CanDualWield() const { return m_canDualWield; }
        virtual void SetCanDualWield(bool value) { m_canDualWield = value; }
        float GetCombatReach() const override { return m_floatValues[UNIT_FIELD_COMBATREACH]; }
        bool IsWithinCombatRange(Unit const* obj, float dist2compare) const;
        bool IsWithinMeleeRange(Unit const* obj) const { return IsWithinMeleeRangeAt(GetPosition(), obj); }
        bool IsWithinMeleeRangeAt(Position const& pos, Unit const* obj) const;
        float GetMeleeRange(Unit const* target) const;
        virtual SpellSchoolMask GetMeleeDamageSchoolMask(WeaponAttackType attackType = BASE_ATTACK, uint8 damageIndex = 0) const = 0;
        uint32 m_extraAttacks;
        bool m_canDualWield;

        void _addAttacker(Unit* pAttacker);                  // must be called only from Unit::Attack(Unit*)
        void _removeAttacker(Unit* pAttacker);               // must be called only from Unit::AttackStop()
        Unit* getAttackerForHelper() const;                 // If someone wants to help, who to give them
        bool Attack(Unit* victim, bool meleeAttack);
        void CastStop(uint32 except_spellid = 0);
        bool AttackStop();
        void RemoveAllAttackers();
        AttackerSet const& getAttackers() const { return m_attackers; }
        bool isAttackingPlayer() const;
        Unit* GetVictim() const { return m_attacking; }
        // Use this only when 100% sure there is a victim
        Unit* EnsureVictim() const
        {
            ASSERT(m_attacking);
            return m_attacking;
        }

        void ValidateAttackersAndOwnTarget();
        void CombatStop(bool includingCast = false, bool mutualPvP = true);
        void CombatStopWithPets(bool includingCast = false);
        void StopAttackFaction(uint32 faction_id);
        Unit* SelectNearbyTarget(Unit* exclude = nullptr, float dist = NOMINAL_MELEE_RANGE) const;
        void SendMeleeAttackStop(Unit* victim = nullptr);
        void SendMeleeAttackStart(Unit* victim);

        void AddUnitState(uint32 f) { m_state |= f; }
        bool HasUnitState(const uint32 f) const { return (m_state & f) != 0; }
        void ClearUnitState(uint32 f) { m_state &= ~f; }
        bool CanFreeMove() const;

        uint32 HasUnitTypeMask(uint32 mask) const { return mask & m_unitTypeMask; }
        void AddUnitTypeMask(uint32 mask) { m_unitTypeMask |= mask; }
        bool IsSummon() const   { return (m_unitTypeMask & UNIT_MASK_SUMMON) != 0; }
        bool IsGuardian() const { return (m_unitTypeMask & UNIT_MASK_GUARDIAN) != 0; }
        bool IsPet() const      { return (m_unitTypeMask & UNIT_MASK_PET) != 0; }
        bool IsHunterPet() const{ return (m_unitTypeMask & UNIT_MASK_HUNTER_PET) != 0; }
        bool IsTotem() const    { return (m_unitTypeMask & UNIT_MASK_TOTEM) != 0; }
        bool IsVehicle() const  { return (m_unitTypeMask & UNIT_MASK_VEHICLE) != 0; }

        uint8 GetLevel() const { return uint8(GetUInt32Value(UNIT_FIELD_LEVEL)); }
        uint8 GetLevelForTarget(WorldObject const* /*target*/) const override { return GetLevel(); }
        void SetLevel(uint8 lvl, bool sendUpdate = true);
        uint8 GetRace() const { return GetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_RACE); }
        void SetRace(uint8 race) { SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_RACE, race); }
        uint32 GetRaceMask() const { return 1 << (GetRace() - 1); }
        uint8 GetClass() const { return GetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS); }
        void SetClass(uint8 unitClass) { SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS, unitClass); }
        uint32 GetClassMask() const { return 1 << (GetClass() - 1); }
        uint8 GetGender() const { return GetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER); }
        void SetGender(uint8 gender) { SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_GENDER, gender); }
        virtual uint8 GetNativeGender() const { return GetGender(); }
        virtual void SetNativeGender(uint8 gender) { SetGender(gender); }

        float GetStat(Stats stat) const { return float(GetUInt32Value(UNIT_FIELD_STAT0+stat)); }
        void SetStat(Stats stat, int32 val) { SetStatInt32Value(UNIT_FIELD_STAT0+stat, val); }
        uint32 GetArmor() const { return GetResistance(SPELL_SCHOOL_NORMAL); }
        void SetArmor(int32 val) { SetResistance(SPELL_SCHOOL_NORMAL, val); }

        uint32 GetResistance(SpellSchools school) const { return GetUInt32Value(UNIT_FIELD_RESISTANCES+school); }
        uint32 GetResistance(SpellSchoolMask mask) const;
        void SetResistance(SpellSchools school, int32 val) { SetStatInt32Value(UNIT_FIELD_RESISTANCES+school, val); }
        static float CalculateAverageResistReduction(WorldObject const* caster, SpellSchoolMask schoolMask, Unit const* victim, SpellInfo const* spellInfo = nullptr);

        uint32 GetHealth()    const { return GetUInt32Value(UNIT_FIELD_HEALTH); }
        uint32 GetMaxHealth() const { return GetUInt32Value(UNIT_FIELD_MAXHEALTH); }

        bool IsFullHealth() const { return GetHealth() == GetMaxHealth(); }
        bool HealthBelowPct(int32 pct) const { return GetHealth() < CountPctFromMaxHealth(pct); }
        bool HealthBelowPctDamaged(int32 pct, uint32 damage) const { return int64(GetHealth()) - int64(damage) < int64(CountPctFromMaxHealth(pct)); }
        bool HealthAbovePct(int32 pct) const { return GetHealth() > CountPctFromMaxHealth(pct); }
        bool HealthAbovePctHealed(int32 pct, uint32 heal) const { return uint64(GetHealth()) + uint64(heal) > CountPctFromMaxHealth(pct); }
        float GetHealthPct() const { return GetMaxHealth() ? 100.f * GetHealth() / GetMaxHealth() : 0.0f; }
        uint32 CountPctFromMaxHealth(int32 pct) const { return CalculatePct(GetMaxHealth(), pct); }
        uint32 CountPctFromCurHealth(int32 pct) const { return CalculatePct(GetHealth(), pct); }

        void SetHealth(uint32 val);
        void SetMaxHealth(uint32 val);
        inline void SetFullHealth() { SetHealth(GetMaxHealth()); }
        int32 ModifyHealth(int32 val);
        int32 GetHealthGain(int32 dVal);

        Powers GetPowerType() const { return Powers(GetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_POWER_TYPE)); }
        void SetPowerType(Powers power, bool sendUpdate = true);
        void UpdateDisplayPower();
        uint32 GetPower(Powers power) const { return GetUInt32Value(UNIT_FIELD_POWER1   +power); }
        uint32 GetMaxPower(Powers power) const { return GetUInt32Value(UNIT_FIELD_MAXPOWER1+power); }
        void SetPower(Powers power, uint32 val);
        void SetMaxPower(Powers power, uint32 val);
        inline void SetFullPower(Powers power) { SetPower(power, GetMaxPower(power)); }
        // returns the change in power
        int32 ModifyPower(Powers power, int32 val);

        uint32 GetAttackTime(WeaponAttackType att) const;
        void SetAttackTime(WeaponAttackType att, uint32 val) { SetFloatValue(UNIT_FIELD_BASEATTACKTIME+att, val*m_modAttackSpeedPct[att]); }
        void ApplyAttackTimePercentMod(WeaponAttackType att, float val, bool apply);
        void ApplyCastTimePercentMod(float val, bool apply);

        SheathState GetSheath() const { return SheathState(GetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_SHEATH_STATE)); }
        virtual void SetSheath(SheathState sheathed) { SetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_SHEATH_STATE, sheathed); }

        // faction template id
        uint32 GetFaction() const override { return GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE); }
        void SetFaction(uint32 faction) override { SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, faction); }

        bool IsInPartyWith(Unit const* unit) const;
        bool IsInRaidWith(Unit const* unit) const;
        void GetPartyMembers(std::list<Unit*> &units);
        bool IsContestedGuard() const;
        bool IsInSanctuary() const { return HasByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_SANCTUARY); }
        bool IsPvP() const { return HasByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_PVP); }
        bool IsFFAPvP() const { return HasByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PVP_FLAG, UNIT_BYTE2_FLAG_FFA_PVP); }
        virtual void SetPvP(bool state);

        uint32 GetCreatureType() const;
        uint32 GetCreatureTypeMask() const;

        uint8 GetStandState() const { return GetByteValue(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_STAND_STATE); }
        bool IsSitState() const;
        bool IsStandState() const;
        void SetStandState(uint8 state);

        void SetStandFlags(uint8 flags) { SetByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, flags); }
        void RemoveStandFlags(uint8 flags) { RemoveByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, flags); }

        bool IsMounted() const { return HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_MOUNT); }
        uint32 GetMountID() const { return GetUInt32Value(UNIT_FIELD_MOUNTDISPLAYID); }
        void Mount(uint32 mount, uint32 vehicleId = 0, uint32 creatureEntry = 0);
        void Dismount();

        uint32 GetMaxSkillValueForLevel(Unit const* target = nullptr) const { return (target ? GetLevelForTarget(target) : GetLevel()) * 5; }
        static void DealDamageMods(Unit const* victim, uint32& damage, uint32* absorb);
        static uint32 DealDamage(Unit* attacker, Unit* victim, uint32 damage, CleanDamage const* cleanDamage = nullptr, DamageEffectType damagetype = DIRECT_DAMAGE, SpellSchoolMask damageSchoolMask = SPELL_SCHOOL_MASK_NORMAL, SpellInfo const* spellProto = nullptr, bool durabilityLoss = true);
        static void Kill(Unit* attacker, Unit* victim, bool durabilityLoss = true);
        void KillSelf(bool durabilityLoss = true) { Unit::Kill(this, this, durabilityLoss); }
        static void DealHeal(HealInfo& healInfo);

        static void ProcSkillsAndAuras(Unit* actor, Unit* actionTarget, uint32 typeMaskActor, uint32 typeMaskActionTarget,
                                uint32 spellTypeMask, uint32 spellPhaseMask, uint32 hitMask, Spell* spell,
                                DamageInfo* damageInfo, HealInfo* healInfo);

        void GetProcAurasTriggeredOnEvent(AuraApplicationProcContainer& aurasTriggeringProc, AuraApplicationList* procAuras, ProcEventInfo& eventInfo);
        void TriggerAurasProcOnEvent(Unit* actionTarget, uint32 typeMaskActor, uint32 typeMaskActionTarget,
                                     uint32 spellTypeMask, uint32 spellPhaseMask, uint32 hitMask, Spell* spell,
                                     DamageInfo* damageInfo, HealInfo* healInfo);
        void TriggerAurasProcOnEvent(ProcEventInfo& eventInfo, AuraApplicationProcContainer& procAuras);

        void HandleEmoteCommand(uint32 anim_id);
        void AttackerStateUpdate (Unit* victim, WeaponAttackType attType = BASE_ATTACK, bool extra = false);

        void CalculateMeleeDamage(Unit* victim, CalcDamageInfo* damageInfo, WeaponAttackType attackType = BASE_ATTACK);
        void DealMeleeDamage(CalcDamageInfo* damageInfo, bool durabilityLoss);
        void HandleProcExtraAttackFor(Unit* victim);

        void CalculateSpellDamageTaken(SpellNonMeleeDamage* damageInfo, int32 damage, SpellInfo const* spellInfo, WeaponAttackType attackType = BASE_ATTACK, bool crit = false);
        void DealSpellDamage(SpellNonMeleeDamage* damageInfo, bool durabilityLoss);

        // player or player's pet resilience (-1%)
        float GetMeleeCritChanceReduction() const { return GetCombatRatingReduction(CR_CRIT_TAKEN_MELEE); }
        float GetRangedCritChanceReduction() const { return GetCombatRatingReduction(CR_CRIT_TAKEN_RANGED); }
        float GetSpellCritChanceReduction() const { return GetCombatRatingReduction(CR_CRIT_TAKEN_SPELL); }

        // player or player's pet resilience (-1%)
        uint32 GetMeleeCritDamageReduction(uint32 damage) const { return GetCombatRatingDamageReduction(CR_CRIT_TAKEN_MELEE, 2.2f, 33.0f, damage); }
        uint32 GetRangedCritDamageReduction(uint32 damage) const { return GetCombatRatingDamageReduction(CR_CRIT_TAKEN_RANGED, 2.2f, 33.0f, damage); }
        uint32 GetSpellCritDamageReduction(uint32 damage) const { return GetCombatRatingDamageReduction(CR_CRIT_TAKEN_SPELL, 2.2f, 33.0f, damage); }

        // player or player's pet resilience (-1%), cap 100%
        uint32 GetMeleeDamageReduction(uint32 damage) const { return GetCombatRatingDamageReduction(CR_CRIT_TAKEN_MELEE, 2.0f, 100.0f, damage); }
        uint32 GetRangedDamageReduction(uint32 damage) const { return GetCombatRatingDamageReduction(CR_CRIT_TAKEN_RANGED, 2.0f, 100.0f, damage); }
        uint32 GetSpellDamageReduction(uint32 damage) const { return GetCombatRatingDamageReduction(CR_CRIT_TAKEN_SPELL, 2.0f, 100.0f, damage); }

        virtual bool CanApplyResilience() const;
        static void ApplyResilience(Unit const* victim, float* crit, int32* damage, bool isCrit, CombatRating type);

        int32 CalculateAOEAvoidance(int32 damage, uint32 schoolMask, ObjectGuid const& casterGuid) const;

        float MeleeSpellMissChance(Unit const* victim, WeaponAttackType attType, int32 skillDiff, uint32 spellId) const override;
        SpellMissInfo MeleeSpellHitResult(Unit* victim, SpellInfo const* spellInfo) const override;

        float GetUnitDodgeChance(WeaponAttackType attType, Unit const* victim) const;
        float GetUnitParryChance(WeaponAttackType attType, Unit const* victim) const;
        float GetUnitBlockChance(WeaponAttackType attType, Unit const* victim) const;
        float GetUnitMissChance() const;
        float GetUnitCriticalChanceDone(WeaponAttackType attackType) const;
        float GetUnitCriticalChanceTaken(Unit const* attacker, WeaponAttackType attackType, float critDone) const;
        float GetUnitCriticalChanceAgainst(WeaponAttackType attackType, Unit const* victim) const;
        int32 GetMechanicResistChance(SpellInfo const* spellInfo) const;
        bool CanUseAttackType(uint8 attacktype) const;

        virtual uint32 GetShieldBlockValue() const = 0;
        uint32 GetShieldBlockValue(uint32 soft_cap, uint32 hard_cap) const;
        uint32 GetDefenseSkillValue(Unit const* target = nullptr) const;
        uint32 GetWeaponSkillValue(WeaponAttackType attType, Unit const* target = nullptr) const;
        float GetWeaponProcChance() const;
        float GetPPMProcChance(uint32 WeaponSpeed, float PPM, SpellInfo const* spellProto) const;

        MeleeHitOutcome RollMeleeOutcomeAgainst(Unit const* victim, WeaponAttackType attType) const;

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
        bool IsServiceProvider() const;
        bool IsSpiritService() const { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPIRITHEALER | UNIT_NPC_FLAG_SPIRITGUIDE); }
        bool IsCritter() const { return GetCreatureType() == CREATURE_TYPE_CRITTER; }

        bool IsInFlight()  const { return HasUnitState(UNIT_STATE_IN_FLIGHT); }

        /// ====================== THREAT & COMBAT ====================
        bool CanHaveThreatList() const { return m_threatManager.CanHaveThreatList(); }
        // This value can be different from IsInCombat, for example:
        // - when a projectile spell is midair against a creature (combat on launch - threat+aggro on impact)
        // - when the creature has no targets left, but the AI has not yet ceased engaged logic
        virtual bool IsEngaged() const { return IsInCombat(); }
        bool IsEngagedBy(Unit const* who) const { return CanHaveThreatList() ? IsThreatenedBy(who) : IsInCombatWith(who); }
        void EngageWithTarget(Unit* who); // Adds target to threat list if applicable, otherwise just sets combat state
        // Combat handling
        CombatManager& GetCombatManager() { return m_combatManager; }
        CombatManager const& GetCombatManager() const { return m_combatManager; }
        void AtTargetAttacked(Unit* target, bool canInitialAggro);

        bool IsImmuneToAll() const { return IsImmuneToPC() && IsImmuneToNPC(); }
        void SetImmuneToAll(bool apply, bool keepCombat);
        virtual void SetImmuneToAll(bool apply) { SetImmuneToAll(apply, false); }
        bool IsImmuneToPC() const { return HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC); }
        void SetImmuneToPC(bool apply, bool keepCombat);
        virtual void SetImmuneToPC(bool apply) { SetImmuneToPC(apply, false); }
        bool IsImmuneToNPC() const { return HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC); }
        void SetImmuneToNPC(bool apply, bool keepCombat);
        virtual void SetImmuneToNPC(bool apply) { SetImmuneToNPC(apply, false); }

        bool IsInCombat() const { return HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT); }
        bool IsInCombatWith(Unit const* who) const { return who && m_combatManager.IsInCombatWith(who); }
        void SetInCombatWith(Unit* enemy) { if (enemy) m_combatManager.SetInCombatWith(enemy); }
        void ClearInCombat() { m_combatManager.EndAllCombat(); }
        void UpdatePetCombatState();
        // Threat handling
        bool IsThreatened() const;
        bool IsThreatenedBy(Unit const* who) const { return who && m_threatManager.IsThreatenedBy(who, true); }
        // Exposes the threat manager directly - be careful when interfacing with this
        // As a general rule of thumb, any unit pointer MUST be null checked BEFORE passing it to threatmanager methods
        // threatmanager will NOT null check your pointers for you - misuse = crash
        ThreatManager& GetThreatManager() { return m_threatManager; }
        ThreatManager const& GetThreatManager() const { return m_threatManager; }

        void SendClearTarget();

        bool HasAuraTypeWithFamilyFlags(AuraType auraType, uint32 familyName, uint32 familyFlags) const;
        bool virtual HasSpell(uint32 /*spellID*/) const { return false; }
        bool HasBreakableByDamageAuraType(AuraType type, uint32 excludeAura = 0) const;
        bool HasBreakableByDamageCrowdControlAura(Unit* excludeCasterChannel = nullptr) const;

        bool HasStealthAura()      const { return HasAuraType(SPELL_AURA_MOD_STEALTH); }
        bool HasInvisibilityAura() const { return HasAuraType(SPELL_AURA_MOD_INVISIBILITY); }
        bool IsFeared()  const { return HasAuraType(SPELL_AURA_MOD_FEAR); }
        bool IsRooted() const { return HasAuraType(SPELL_AURA_MOD_ROOT); }
        bool IsPolymorphed() const;
        bool IsFrozen() const { return HasAuraState(AURA_STATE_FROZEN); }

        bool isTargetableForAttack(bool checkFakeDeath = true) const;

        virtual bool IsInWater() const;
        virtual bool IsUnderWater() const;
        bool isInAccessiblePlaceFor(Creature const* c) const;

        void SendHealSpellLog(HealInfo& healInfo, bool critical = false);
        int32 HealBySpell(HealInfo& healInfo, bool critical = false);
        void SendEnergizeSpellLog(Unit* victim, uint32 spellId, int32 damage, Powers powerType);
        void EnergizeBySpell(Unit* victim, uint32 spellId, int32 damage, Powers powerType);
        void EnergizeBySpell(Unit* victim, SpellInfo const* spellInfo, int32 damage, Powers powerType);

        Aura* AddAura(uint32 spellId, Unit* target);
        Aura* AddAura(SpellInfo const* spellInfo, uint8 effMask, Unit* target);
        void SetAuraStack(uint32 spellId, Unit* target, uint32 stack);
        void SendPlaySpellVisual(uint32 id) const;
        void SendPlaySpellImpact(ObjectGuid guid, uint32 id) const;

        void DeMorph();

        void SendAttackStateUpdate(CalcDamageInfo* damageInfo);
        void SendAttackStateUpdate(uint32 HitInfo, Unit* target, uint8 SwingType, SpellSchoolMask damageSchoolMask, uint32 Damage, uint32 AbsorbDamage, uint32 Resist, VictimState TargetState, uint32 BlockedAmount);
        void SendSpellNonMeleeDamageLog(SpellNonMeleeDamage* log);
        void SendSpellNonMeleeDamageLog(Unit* target, uint32 spellID, uint32 damage, SpellSchoolMask damageSchoolMask, uint32 absorbedDamage, uint32 resist, bool isPeriodic, uint32 blocked, bool criticalHit = false, bool split = false);
        void SendPeriodicAuraLog(SpellPeriodicAuraLogInfo* pInfo);
        void SendSpellDamageResist(Unit* target, uint32 spellId);
        void SendSpellDamageImmune(Unit* target, uint32 spellId);

        void NearTeleportTo(Position const& pos, bool casting = false);
        void NearTeleportTo(float x, float y, float z, float orientation, bool casting = false) { NearTeleportTo(Position(x, y, z, orientation), casting); }
        void SendTeleportPacket(Position const& pos, bool teleportingTransport = false);
        virtual bool UpdatePosition(float x, float y, float z, float ang, bool teleport = false);
        // returns true if unit's position really changed
        virtual bool UpdatePosition(Position const& pos, bool teleport = false);
        void UpdateOrientation(float orientation);
        void UpdateHeight(float newZ);

        void KnockbackFrom(float x, float y, float speedXY, float speedZ);
        void JumpTo(float speedXY, float speedZ, bool forward = true);
        void JumpTo(WorldObject* obj, float speedZ, bool withOrientation = false);

        void MonsterMoveWithSpeed(float x, float y, float z, float speed, bool generatePath = false, bool forceDestination = false);
        //void SetFacing(float ori, WorldObject* obj = nullptr);
        //void SendMonsterMove(float NewPosX, float NewPosY, float NewPosZ, uint8 type, uint32 MovementFlags, uint32 Time, Player* player = nullptr);
        void SendMovementFlagUpdate(bool self = false);

        bool IsLevitating() const { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY); }
        bool IsWalking() const { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_WALKING); }
        bool IsHovering() const { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_HOVER); }
        virtual bool SetWalk(bool enable);
        virtual bool SetDisableGravity(bool disable, bool packetOnly = false);
        virtual bool SetSwim(bool enable);
        virtual bool SetCanFly(bool enable, bool packetOnly = false);
        virtual bool SetWaterWalking(bool enable, bool packetOnly = false);
        virtual bool SetFeatherFall(bool enable, bool packetOnly = false);
        virtual bool SetHover(bool enable, bool packetOnly = false);

        void SetInFront(WorldObject const* target);
        void SetFacingTo(float const ori, bool force = true);
        void SetFacingToObject(WorldObject const* object, bool force = true);

        void BuildHeartBeatMsg(WorldPacket* data) const;

        bool IsAlive() const { return (m_deathState == ALIVE); }
        bool isDying() const { return (m_deathState == JUST_DIED); }
        bool isDead() const { return (m_deathState == DEAD || m_deathState == CORPSE); }
        bool IsGhouled() const;
        DeathState getDeathState() const { return m_deathState; }
        virtual void setDeathState(DeathState s);           // overwrited in Creature/Player/Pet

        ObjectGuid GetOwnerGUID() const override { return GetGuidValue(UNIT_FIELD_SUMMONEDBY); }
        void SetOwnerGUID(ObjectGuid owner);
        ObjectGuid GetCreatorGUID() const { return GetGuidValue(UNIT_FIELD_CREATEDBY); }
        void SetCreatorGUID(ObjectGuid creator) { SetGuidValue(UNIT_FIELD_CREATEDBY, creator); }
        ObjectGuid GetMinionGUID() const { return GetGuidValue(UNIT_FIELD_SUMMON); }
        void SetMinionGUID(ObjectGuid guid) { SetGuidValue(UNIT_FIELD_SUMMON, guid); }
        void SetPetGUID(ObjectGuid guid) { m_SummonSlot[SUMMON_SLOT_PET] = guid; }
        ObjectGuid GetPetGUID() const { return m_SummonSlot[SUMMON_SLOT_PET]; }
        void SetCritterGUID(ObjectGuid guid) { SetGuidValue(UNIT_FIELD_CRITTER, guid); }
        ObjectGuid GetCritterGUID() const { return GetGuidValue(UNIT_FIELD_CRITTER); }

        ObjectGuid GetCharmerGUID() const { return GetGuidValue(UNIT_FIELD_CHARMEDBY); }
        Unit* GetCharmer() const { return m_charmer; }

        ObjectGuid GetCharmedGUID() const { return GetGuidValue(UNIT_FIELD_CHARM); }
        Unit* GetCharmed() const { return m_charmed; }

        bool IsControlledByPlayer() const { return m_ControlledByPlayer; }
        Player* GetControllingPlayer() const;
        ObjectGuid GetCharmerOrOwnerGUID() const override { return IsCharmed() ? GetCharmerGUID() : GetOwnerGUID(); }
        bool IsCharmedOwnedByPlayerOrPlayer() const { return GetCharmerOrOwnerOrOwnGUID().IsPlayer(); }

        Guardian* GetGuardianPet() const;
        Minion* GetFirstMinion() const;
        Unit* GetCharmerOrOwner() const { return IsCharmed() ? GetCharmer() : GetOwner(); }

        void SetMinion(Minion *minion, bool apply);
        void GetAllMinionsByEntry(std::list<Creature*>& Minions, uint32 entry);
        void RemoveAllMinionsByEntry(uint32 entry);
        void SetCharm(Unit* target, bool apply);
        Unit* GetNextRandomRaidMemberOrPet(float radius);
        bool SetCharmedBy(Unit* charmer, CharmType type, AuraApplication const* aurApp = nullptr);
        void RemoveCharmedBy(Unit* charmer);
        void RestoreFaction();

        ControlList m_Controlled;
        Unit* GetFirstControlled() const;
        void RemoveAllControlled();

        bool IsCharmed() const { return !GetCharmerGUID().IsEmpty(); }
        bool isPossessed() const { return HasUnitState(UNIT_STATE_POSSESSED); }
        bool isPossessedByPlayer() const;
        bool isPossessing() const;
        bool isPossessing(Unit* u) const;

        CharmInfo* GetCharmInfo() { return m_charmInfo; }
        CharmInfo* InitCharmInfo();
        void DeleteCharmInfo();

        // all of these are for DIRECT CLIENT CONTROL only
        void SetMovedUnit(Unit* target);
        // returns the unit that this player IS CONTROLLING
        Unit* GetUnitBeingMoved() const { return m_unitMovedByMe; }
        // returns the player that this unit is BEING CONTROLLED BY
        Player* GetPlayerMovingMe() const { return m_playerMovingMe; }

        SharedVisionList const& GetSharedVisionList() { return m_sharedVision; }
        void AddPlayerToVision(Player* player);
        void RemovePlayerFromVision(Player* player);
        bool HasSharedVision() const { return !m_sharedVision.empty(); }
        void RemoveBindSightAuras();
        void RemoveCharmAuras();

        Pet* CreateTamedPetFrom(Creature* creatureTarget, uint32 spell_id = 0);
        Pet* CreateTamedPetFrom(uint32 creatureEntry, uint32 spell_id = 0);
        bool InitTamedPet(Pet* pet, uint8 level, uint32 spell_id);

        // aura apply/remove helpers - you should better not use these
        Aura* _TryStackingOrRefreshingExistingAura(AuraCreateInfo& createInfo);
        void _AddAura(UnitAura* aura, Unit* caster);
        AuraApplication* _CreateAuraApplication(Aura* aura, uint8 effMask);
        void _ApplyAuraEffect(Aura* aura, uint8 effIndex);
        void _ApplyAura(AuraApplication* aurApp, uint8 effMask);
        void _UnapplyAura(AuraApplicationMap::iterator& i, AuraRemoveMode removeMode);
        void _UnapplyAura(AuraApplication* aurApp, AuraRemoveMode removeMode);
        void _RemoveNoStackAurasDueToAura(Aura* aura);
        void _RegisterAuraEffect(AuraEffect* aurEff, bool apply);

        // m_ownedAuras container management
        AuraMap      & GetOwnedAuras()       { return m_ownedAuras; }
        AuraMap const& GetOwnedAuras() const { return m_ownedAuras; }

        void RemoveOwnedAura(AuraMap::iterator& i, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveOwnedAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, uint8 reqEffMask = 0, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveOwnedAura(Aura* aura, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);

        Aura* GetOwnedAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint8 reqEffMask = 0, Aura* except = nullptr) const;

        // m_appliedAuras container management
        AuraApplicationMap      & GetAppliedAuras()       { return m_appliedAuras; }
        AuraApplicationMap const& GetAppliedAuras() const { return m_appliedAuras; }

        void RemoveAura(AuraApplicationMap::iterator &i, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, uint8 reqEffMask = 0, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAura(AuraApplication * aurApp, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAura(Aura* aur, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);

        // Convenience methods removing auras by predicate
        void RemoveAppliedAuras(std::function<bool(AuraApplication const*)> const& check);
        void RemoveOwnedAuras(std::function<bool(Aura const*)> const& check);

        // Optimized overloads taking advantage of map key
        void RemoveAppliedAuras(uint32 spellId, std::function<bool(AuraApplication const*)> const& check);
        void RemoveOwnedAuras(uint32 spellId, std::function<bool(Aura const*)> const& check);

        void RemoveAurasByType(AuraType auraType, std::function<bool(AuraApplication const*)> const& check);

        void RemoveAurasDueToSpell(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, uint8 reqEffMask = 0, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAuraFromStack(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAurasDueToSpellByDispel(uint32 spellId, uint32 dispellerSpellId, ObjectGuid casterGUID, WorldObject* dispeller, uint8 chargesRemoved = 1);
        void RemoveAurasDueToSpellBySteal(uint32 spellId, ObjectGuid casterGUID, WorldObject* stealer);
        void RemoveAurasDueToItemSpell(uint32 spellId, ObjectGuid castItemGuid);
        void RemoveAurasByType(AuraType auraType, ObjectGuid casterGUID = ObjectGuid::Empty, Aura* except = nullptr, bool negative = true, bool positive = true);
        void RemoveNotOwnSingleTargetAuras(uint32 newPhase = 0x0);
        void RemoveAurasWithInterruptFlags(uint32 flag, uint32 except = 0);
        void RemoveAurasWithAttribute(uint32 flags);
        void RemoveAurasWithFamily(SpellFamilyNames family, uint32 familyFlag1, uint32 familyFlag2, uint32 familyFlag3, ObjectGuid casterGUID);
        void RemoveAurasWithMechanic(uint32 mechanic_mask, AuraRemoveMode removemode = AURA_REMOVE_BY_DEFAULT, uint32 except = 0);
        void RemoveMovementImpairingAuras(bool withRoot);
        void RemoveAurasByShapeShift();

        void RemoveAreaAurasDueToLeaveWorld();
        void RemoveAllAuras();
        void RemoveArenaAuras();
        void RemoveAurasOnEvade();
        void RemoveAllAurasOnDeath();
        void RemoveAllAurasRequiringDeadTarget();
        void RemoveAllAurasExceptType(AuraType type);
        void RemoveAllAurasExceptType(AuraType type1, AuraType type2); /// @todo: once we support variadic templates use them here
        void RemoveAllGroupBuffsFromCaster(ObjectGuid casterGUID);
        void DelayOwnedAuras(uint32 spellId, ObjectGuid caster, int32 delaytime);

        void _RemoveAllAuraStatMods();
        void _ApplyAllAuraStatMods();

        AuraEffectList const& GetAuraEffectsByType(AuraType type) const { return m_modAuras[type]; }
        AuraList      & GetSingleCastAuras()       { return m_scAuras; }
        AuraList const& GetSingleCastAuras() const { return m_scAuras; }

        AuraEffect* GetAuraEffect(uint32 spellId, uint8 effIndex, ObjectGuid casterGUID = ObjectGuid::Empty) const;
        AuraEffect* GetAuraEffectOfRankedSpell(uint32 spellId, uint8 effIndex, ObjectGuid casterGUID = ObjectGuid::Empty) const;
        AuraEffect* GetAuraEffect(AuraType type, SpellFamilyNames name, uint32 iconId, uint8 effIndex) const; // spell mustn't have familyflags
        AuraEffect* GetAuraEffect(AuraType type, SpellFamilyNames family, uint32 familyFlag1, uint32 familyFlag2, uint32 familyFlag3, ObjectGuid casterGUID = ObjectGuid::Empty) const;
        AuraEffect* GetDummyAuraEffect(SpellFamilyNames name, uint32 iconId, uint8 effIndex) const;

        AuraApplication * GetAuraApplication(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint8 reqEffMask = 0, AuraApplication * except = nullptr) const;
        Aura* GetAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint8 reqEffMask = 0) const;

        AuraApplication * GetAuraApplicationOfRankedSpell(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint8 reqEffMask = 0, AuraApplication * except = nullptr) const;
        Aura* GetAuraOfRankedSpell(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint8 reqEffMask = 0) const;

        void GetDispellableAuraList(WorldObject const* caster, uint32 dispelMask, DispelChargesList& dispelList, bool isReflect = false) const;

        bool HasAuraEffect(uint32 spellId, uint8 effIndex, ObjectGuid caster = ObjectGuid::Empty) const;
        uint32 GetAuraCount(uint32 spellId) const;
        bool HasAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint8 reqEffMask = 0) const;
        bool HasAuraType(AuraType auraType) const;
        bool HasAuraTypeWithCaster(AuraType auraType, ObjectGuid caster) const;
        bool HasAuraTypeWithMiscvalue(AuraType auraType, int32 miscValue) const;
        bool HasAuraTypeWithAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const;
        bool HasAuraTypeWithValue(AuraType auraType, int32 value) const;
        bool HasNegativeAuraWithInterruptFlag(uint32 flag, ObjectGuid guid = ObjectGuid::Empty) const;
        bool HasAuraWithMechanic(uint32 mechanicMask) const;
        bool HasStrongerAuraWithDR(SpellInfo const* auraSpellInfo, Unit* caster, bool triggered) const;

        AuraEffect* IsScriptOverriden(SpellInfo const* spell, int32 script) const;
        uint32 GetDiseasesByCaster(ObjectGuid casterGUID, bool remove = false);
        uint32 GetDoTsByCaster(ObjectGuid casterGUID) const;

        int32 GetTotalAuraModifier(AuraType auraType) const;
        float GetTotalAuraMultiplier(AuraType auraType) const;
        int32 GetMaxPositiveAuraModifier(AuraType auraType) const;
        int32 GetMaxNegativeAuraModifier(AuraType auraType) const;

        int32 GetTotalAuraModifier(AuraType auraType, std::function<bool(AuraEffect const*)> const& predicate) const;
        float GetTotalAuraMultiplier(AuraType auraType, std::function<bool(AuraEffect const*)> const& predicate) const;
        int32 GetMaxPositiveAuraModifier(AuraType auraType, std::function<bool(AuraEffect const*)> const& predicate) const;
        int32 GetMaxNegativeAuraModifier(AuraType auraType, std::function<bool(AuraEffect const*)> const& predicate) const;

        int32 GetTotalAuraModifierByMiscMask(AuraType auraType, uint32 misc_mask) const;
        float GetTotalAuraMultiplierByMiscMask(AuraType auraType, uint32 misc_mask) const;
        int32 GetMaxPositiveAuraModifierByMiscMask(AuraType auraType, uint32 misc_mask, AuraEffect const* except = nullptr) const;
        int32 GetMaxNegativeAuraModifierByMiscMask(AuraType auraType, uint32 misc_mask) const;

        int32 GetTotalAuraModifierByMiscValue(AuraType auraType, int32 misc_value) const;
        float GetTotalAuraMultiplierByMiscValue(AuraType auraType, int32 misc_value) const;
        int32 GetMaxPositiveAuraModifierByMiscValue(AuraType auraType, int32 misc_value) const;
        int32 GetMaxNegativeAuraModifierByMiscValue(AuraType auraType, int32 misc_value) const;

        int32 GetTotalAuraModifierByAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const;
        float GetTotalAuraMultiplierByAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const;
        int32 GetMaxPositiveAuraModifierByAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const;
        int32 GetMaxNegativeAuraModifierByAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const;

        void UpdateResistanceBuffModsMod(SpellSchools school);
        void InitStatBuffMods();
        void UpdateStatBuffMod(Stats stat);
        void SetCreateStat(Stats stat, float val) { m_createStats[stat] = val; }
        void SetCreateHealth(uint32 val) { SetUInt32Value(UNIT_FIELD_BASE_HEALTH, val); }
        uint32 GetCreateHealth() const { return GetUInt32Value(UNIT_FIELD_BASE_HEALTH); }
        void SetCreateMana(uint32 val) { SetUInt32Value(UNIT_FIELD_BASE_MANA, val); }
        uint32 GetCreateMana() const { return GetUInt32Value(UNIT_FIELD_BASE_MANA); }
        uint32 GetCreatePowerValue(Powers power) const;
        float GetPosStat(Stats stat) const { return GetFloatValue(UNIT_FIELD_POSSTAT0+stat); }
        float GetNegStat(Stats stat) const { return GetFloatValue(UNIT_FIELD_NEGSTAT0+stat); }
        float GetCreateStat(Stats stat) const { return m_createStats[stat]; }

        ObjectGuid GetChannelObjectGuid() const { return GetGuidValue(UNIT_FIELD_CHANNEL_OBJECT); }
        void SetChannelObjectGuid(ObjectGuid guid) { SetGuidValue(UNIT_FIELD_CHANNEL_OBJECT, guid); }

        void SetCurrentCastSpell(Spell* pSpell);
        void InterruptSpell(CurrentSpellTypes spellType, bool withDelayed = true, bool withInstant = true);
        void FinishSpell(CurrentSpellTypes spellType, bool ok = true);

        // set withDelayed to true to account delayed spells as cast
        // delayed+channeled spells are always accounted as cast
        // we can skip channeled or delayed checks using flags
        bool IsNonMeleeSpellCast(bool withDelayed, bool skipChanneled = false, bool skipAutorepeat = false, bool isAutoshoot = false, bool skipInstant = true) const;

        // set withDelayed to true to interrupt delayed spells too
        // delayed+channeled spells are always interrupted
        void InterruptNonMeleeSpells(bool withDelayed, uint32 spellid = 0, bool withInstant = true);

        Spell* GetCurrentSpell(CurrentSpellTypes spellType) const { return m_currentSpells[spellType]; }
        Spell* GetCurrentSpell(uint32 spellType) const { return m_currentSpells[spellType]; }
        Spell* FindCurrentSpellBySpellId(uint32 spell_id) const;
        int32 GetCurrentSpellCastTime(uint32 spell_id) const;

        virtual bool HasSpellFocus(Spell const* /*focusSpell*/ = nullptr) const { return false; }
        virtual bool IsMovementPreventedByCasting() const;

        SpellHistory* GetSpellHistory() { return m_spellHistory; }
        SpellHistory const* GetSpellHistory() const { return m_spellHistory; }

        ObjectGuid m_SummonSlot[MAX_SUMMON_SLOT];
        ObjectGuid m_ObjectSlot[MAX_GAMEOBJECT_SLOT];

        ShapeshiftForm GetShapeshiftForm() const { return ShapeshiftForm(GetByteValue(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_SHAPESHIFT_FORM)); }
        void SetShapeshiftForm(ShapeshiftForm form);

        bool IsInFeralForm() const;

        bool IsInDisallowedMountForm() const;

        float m_modMeleeHitChance;
        float m_modRangedHitChance;
        float m_modSpellHitChance;
        int32 m_baseSpellCritChance;

        float m_modAttackSpeedPct[MAX_ATTACK];

        // stat system
        void HandleStatFlatModifier(UnitMods unitMod, UnitModifierFlatType modifierType, float amount, bool apply);
        void ApplyStatPctModifier(UnitMods unitMod, UnitModifierPctType modifierType, float amount);

        void SetStatFlatModifier(UnitMods unitMod, UnitModifierFlatType modifierType, float val);
        void SetStatPctModifier(UnitMods unitMod, UnitModifierPctType modifierType, float val);

        float GetFlatModifierValue(UnitMods unitMod, UnitModifierFlatType modifierType) const;
        float GetPctModifierValue(UnitMods unitMod, UnitModifierPctType modifierType) const;

        void UpdateUnitMod(UnitMods unitMod);

        // only players have item requirements
        virtual bool CheckAttackFitToAuraRequirement(WeaponAttackType /*attackType*/, AuraEffect const* /*aurEff*/) const { return true; }

        virtual void UpdateDamageDoneMods(WeaponAttackType attackType, int32 skipEnchantSlot = -1);
        void UpdateAllDamageDoneMods();

        void UpdateDamagePctDoneMods(WeaponAttackType attackType);
        void UpdateAllDamagePctDoneMods();

        float GetTotalStatValue(Stats stat) const;
        float GetTotalAuraModValue(UnitMods unitMod) const;
        SpellSchools GetSpellSchoolByAuraGroup(UnitMods unitMod) const;
        Stats GetStatByAuraGroup(UnitMods unitMod) const;
        Powers GetPowerTypeByAuraGroup(UnitMods unitMod) const;
        bool CanModifyStats() const { return m_canModifyStats; }
        void SetCanModifyStats(bool modifyStats) { m_canModifyStats = modifyStats; }
        virtual bool UpdateStats(Stats stat) = 0;
        virtual bool UpdateAllStats() = 0;
        virtual void UpdateResistances(uint32 school) = 0;
        virtual void UpdateAllResistances();
        virtual void UpdateArmor() = 0;
        virtual void UpdateMaxHealth() = 0;
        virtual void UpdateMaxPower(Powers power) = 0;
        virtual void UpdateAttackPowerAndDamage(bool ranged = false) = 0;
        virtual void UpdateDamagePhysical(WeaponAttackType attType);
        float GetTotalAttackPowerValue(WeaponAttackType attType) const;
        float GetWeaponDamageRange(WeaponAttackType attType, WeaponDamageRange type, uint8 damageIndex = 0) const;
        void SetBaseWeaponDamage(WeaponAttackType attType, WeaponDamageRange damageRange, float value, uint8 damageIndex = 0) { m_weaponDamage[attType][damageRange][damageIndex] = value; }
        virtual void CalculateMinMaxDamage(WeaponAttackType attType, bool normalized, bool addTotalPct, float& minDamage, float& maxDamage, uint8 damageIndex) const = 0;
        uint32 CalculateDamage(WeaponAttackType attType, bool normalized, bool addTotalPct, uint8 itemDamagesMask = 0) const;
        float GetAPMultiplier(WeaponAttackType attType, bool normalized) const;

        bool isInFrontInMap(Unit const* target, float distance, float arc = float(M_PI)) const;
        bool isInBackInMap(Unit const* target, float distance, float arc = float(M_PI)) const;

        // Visibility system
        bool IsVisible() const;
        void SetVisible(bool x);

        // common function for visibility checks for player/creatures with detection code
        void SetPhaseMask(uint32 newPhaseMask, bool update) override;// overwrite WorldObject::SetPhaseMask
        void UpdateObjectVisibility(bool forced = true) override;

        SpellImmuneContainer m_spellImmune[MAX_SPELL_IMMUNITY];
        uint32 m_lastSanctuaryTime;

        VisibleAuraMap const* GetVisibleAuras() { return &m_visibleAuras; }
        AuraApplication * GetVisibleAura(uint8 slot) const;
        void SetVisibleAura(uint8 slot, AuraApplication * aur);
        void RemoveVisibleAura(uint8 slot);

        uint32 GetInterruptMask() const { return m_interruptMask; }
        void AddInterruptMask(uint32 mask) { m_interruptMask |= mask; }
        void UpdateInterruptMask();

        uint32 GetDisplayId() const { return GetUInt32Value(UNIT_FIELD_DISPLAYID); }
        virtual void SetDisplayId(uint32 modelId);
        uint32 GetNativeDisplayId() const { return GetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID); }
        void RestoreDisplayId();
        void SetNativeDisplayId(uint32 modelId) { SetUInt32Value(UNIT_FIELD_NATIVEDISPLAYID, modelId); }
        void SetTransformSpell(uint32 spellid) { m_transformSpell = spellid;}
        uint32 GetTransformSpell() const { return m_transformSpell;}

        // DynamicObject management
        void _RegisterDynObject(DynamicObject* dynObj);
        void _UnregisterDynObject(DynamicObject* dynObj);
        DynamicObject* GetDynObject(uint32 spellId);
        void RemoveDynObject(uint32 spellId);
        void RemoveAllDynObjects();

        GameObject* GetGameObject(uint32 spellId) const;
        void AddGameObject(GameObject* gameObj);
        void RemoveGameObject(GameObject* gameObj, bool del);
        void RemoveGameObject(uint32 spellid, bool del);
        void RemoveAllGameObjects();

        void ModifyAuraState(AuraStateType flag, bool apply);
        uint32 BuildAuraStateUpdateForTarget(Unit* target) const;
        bool HasAuraState(AuraStateType flag, SpellInfo const* spellProto = nullptr, Unit const* Caster = nullptr) const;
        void UnsummonAllTotems();
        bool IsMagnet() const;
        Unit* GetMeleeHitRedirectTarget(Unit* victim, SpellInfo const* spellInfo = nullptr);

        int32 SpellBaseDamageBonusDone(SpellSchoolMask schoolMask) const;
        uint32 SpellDamageBonusDone(Unit* victim, SpellInfo const* spellProto, uint32 pdamage, DamageEffectType damagetype, uint8 effIndex, Optional<float> const& donePctTotal, uint32 stack = 1) const;
        float SpellDamagePctDone(Unit* victim, SpellInfo const* spellProto, DamageEffectType damagetype) const;
        uint32 SpellDamageBonusTaken(Unit* caster, SpellInfo const* spellProto, uint32 pdamage, DamageEffectType damagetype) const;
        int32 SpellBaseHealingBonusDone(SpellSchoolMask schoolMask) const;
        uint32 SpellHealingBonusDone(Unit* victim, SpellInfo const* spellProto, uint32 healamount, DamageEffectType damagetype, uint8 effIndex, Optional<float> const& donePctTotal, uint32 stack = 1) const;
        float SpellHealingPctDone(Unit* victim, SpellInfo const* spellProto) const;
        uint32 SpellHealingBonusTaken(Unit* caster, SpellInfo const* spellProto, uint32 healamount, DamageEffectType damagetype) const;

        uint32 MeleeDamageBonusDone(Unit* pVictim, uint32 damage, WeaponAttackType attType, SpellInfo const* spellProto = nullptr, SpellSchoolMask damageSchoolMask = SPELL_SCHOOL_MASK_NORMAL);
        uint32 MeleeDamageBonusTaken(Unit* attacker, uint32 pdamage, WeaponAttackType attType, SpellInfo const* spellProto = nullptr, SpellSchoolMask damageSchoolMask = SPELL_SCHOOL_MASK_NORMAL);

        bool isSpellBlocked(Unit* victim, SpellInfo const* spellProto, WeaponAttackType attackType = BASE_ATTACK);
        bool isBlockCritical();
        float SpellCritChanceDone(SpellInfo const* spellInfo, SpellSchoolMask schoolMask, WeaponAttackType attackType = BASE_ATTACK, bool isPeriodic = false) const;
        float SpellCritChanceTaken(Unit const* caster, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, float doneChance, WeaponAttackType attackType = BASE_ATTACK, bool isPeriodic = false) const;
        static uint32 SpellCriticalDamageBonus(Unit const* caster, SpellInfo const* spellProto, uint32 damage, Unit* victim);
        static uint32 SpellCriticalHealingBonus(Unit const* caster, SpellInfo const* spellProto, uint32 damage, Unit* victim);

        void SetLastManaUse(uint32 spellCastTime) { m_lastManaUse = spellCastTime; }
        bool IsUnderLastManaUseEffect() const;

        uint32 GetCastingTimeForBonus(SpellInfo const* spellProto, DamageEffectType damagetype, uint32 CastingTime) const;
        float CalculateDefaultCoefficient(SpellInfo const* spellInfo, DamageEffectType damagetype) const;

        void ApplySpellImmune(uint32 spellId, uint32 op, uint32 type, bool apply);
        virtual bool IsImmunedToSpell(SpellInfo const* spellInfo, WorldObject const* caster) const;
        uint32 GetSchoolImmunityMask() const;
        uint32 GetDamageImmunityMask() const;
        uint32 GetMechanicImmunityMask() const;

        bool IsImmunedToDamage(SpellSchoolMask meleeSchoolMask) const;
        bool IsImmunedToDamage(SpellInfo const* spellInfo) const;
        virtual bool IsImmunedToSpellEffect(SpellInfo const* spellInfo, uint32 index, WorldObject const* caster) const;

        static bool IsDamageReducedByArmor(SpellSchoolMask damageSchoolMask, SpellInfo const* spellInfo = nullptr);
        static uint32 CalcArmorReducedDamage(Unit const* attacker, Unit* victim, uint32 damage, SpellInfo const* spellInfo, WeaponAttackType attackType = MAX_ATTACK, uint8 attackerLevel = 0);
        static uint32 CalcSpellResistedDamage(Unit const* attacker, Unit* victim, uint32 damage, SpellSchoolMask schoolMask, SpellInfo const* spellInfo);
        static void CalcAbsorbResist(DamageInfo& damageInfo);
        static void CalcHealAbsorb(HealInfo& healInfo);

        void UpdateSpeed(UnitMoveType mtype);
        float GetSpeed(UnitMoveType mtype) const;
        float GetSpeedRate(UnitMoveType mtype) const { return m_speed_rate[mtype]; }
        void SetSpeed(UnitMoveType mtype, float newValue);
        void SetSpeedRate(UnitMoveType mtype, float rate);

        float CalculateSpellpowerCoefficientLevelPenalty(SpellInfo const* spellInfo) const;

        void FollowerAdded(AbstractFollower* f) { m_followingMe.insert(f); }
        void FollowerRemoved(AbstractFollower* f) { m_followingMe.erase(f); }
        void RemoveAllFollowers();

        MotionMaster* GetMotionMaster() { return i_motionMaster; }
        MotionMaster const* GetMotionMaster() const { return i_motionMaster; }
        virtual MovementGeneratorType GetDefaultMovementType() const;

        bool IsStopped() const { return !(HasUnitState(UNIT_STATE_MOVING)); }
        void StopMoving();
        void PauseMovement(uint32 timer = 0, uint8 slot = 0, bool forced = true); // timer in ms
        void ResumeMovement(uint32 timer = 0, uint8 slot = 0); // timer in ms

        void AddUnitMovementFlag(uint32 f) { m_movementInfo.flags |= f; }
        void RemoveUnitMovementFlag(uint32 f) { m_movementInfo.flags &= ~f; }
        bool HasUnitMovementFlag(uint32 f) const { return (m_movementInfo.flags & f) == f; }
        uint32 GetUnitMovementFlags() const { return m_movementInfo.flags; }
        void SetUnitMovementFlags(uint32 f) { m_movementInfo.flags = f; }

        void AddExtraUnitMovementFlag(uint16 f) { m_movementInfo.flags2 |= f; }
        void RemoveExtraUnitMovementFlag(uint16 f) { m_movementInfo.flags2 &= ~f; }
        uint16 HasExtraUnitMovementFlag(uint16 f) const { return m_movementInfo.flags2 & f; }
        uint16 GetExtraUnitMovementFlags() const { return m_movementInfo.flags2; }
        void SetExtraUnitMovementFlags(uint16 f) { m_movementInfo.flags2 = f; }

        void SetControlled(bool apply, UnitState state);
        void ApplyControlStatesIfNeeded();

        ///-----------Combo point system-------------------
        // This unit having CP on other units
        uint8 GetComboPoints(Unit const* who = nullptr) const { return (who && m_comboTarget != who) ? 0 : m_comboPoints; }
        uint8 GetComboPoints(ObjectGuid const& guid) const { return (m_comboTarget && m_comboTarget->GetGUID() == guid) ? m_comboPoints : 0; }
        Unit* GetComboTarget() const { return m_comboTarget; }
        ObjectGuid GetComboTargetGUID() const { return m_comboTarget ? m_comboTarget->GetGUID() : ObjectGuid::Empty; }
        void AddComboPoints(Unit* target, int8 count);
        void AddComboPoints(int8 count) { AddComboPoints(nullptr, count); }
        void ClearComboPoints();
        void SendComboPoints();
        // Other units having CP on this unit
        void AddComboPointHolder(Unit* unit) { m_ComboPointHolders.insert(unit); }
        void RemoveComboPointHolder(Unit* unit) { m_ComboPointHolders.erase(unit); }
        void ClearComboPointHolders();

        ///----------Pet responses methods-----------------
        void SendPetActionFeedback (uint8 msg);
        void SendPetTalk (uint32 pettalk);
        void SendPetAIReaction(ObjectGuid guid);
        ///----------End of Pet responses methods----------

        void PropagateSpeedChange();

        // reactive attacks
        void ClearAllReactives();
        void StartReactiveTimer(ReactiveType reactive) { m_reactiveTimer[reactive] = REACTIVE_TIMER_START;}
        void UpdateReactives(uint32 p_time);

        // group updates
        void UpdateAuraForGroup(uint8 slot);

        // proc trigger system
        bool CanProc() const { return !m_procDeep; }
        void SetCantProc(bool apply);

        uint32 GetModelForForm(ShapeshiftForm form, uint32 spellId) const;

        friend class VehicleJoinEvent;
        ObjectGuid LastCharmerGUID;
        bool CreateVehicleKit(uint32 id, uint32 creatureEntry);
        void RemoveVehicleKit();
        Vehicle* GetVehicleKit() const { return m_vehicleKit; }
        Vehicle* GetVehicle() const { return m_vehicle; }
        void SetVehicle(Vehicle* vehicle) { m_vehicle = vehicle; }
        bool IsOnVehicle(Unit const* vehicle) const;
        Unit* GetVehicleBase() const;
        Unit* GetVehicleRoot() const;
        Creature* GetVehicleCreatureBase() const;
        ObjectGuid GetTransGUID()   const override;
        /// Returns the transport this unit is on directly (if on vehicle and transport, return vehicle)
        TransportBase* GetDirectTransport() const;

        void HandleSpellClick(Unit* clicker, int8 seatId = -1);
        void EnterVehicle(Unit* base, int8 seatId = -1);
        void ExitVehicle(Position const* exitPosition = nullptr);
        void ChangeSeat(int8 seatId, bool next = true);

        // Should only be called by AuraEffect::HandleAuraControlVehicle(AuraApplication const* auraApp, uint8 mode, bool apply) const;
        void _ExitVehicle(Position const* exitPosition = nullptr);
        void _EnterVehicle(Vehicle* vehicle, int8 seatId, AuraApplication const* aurApp = nullptr);

        void BuildMovementPacket(ByteBuffer* data) const;
        static void BuildMovementPacket(Position const& pos, Position const& transportPos, MovementInfo const& movementInfo, ByteBuffer* data);

        bool isMoving() const   { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_MASK_MOVING); }
        bool isTurning() const  { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_MASK_TURNING); }
        virtual bool CanFly() const = 0;
        bool IsFlying() const   { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_FLYING | MOVEMENTFLAG_DISABLE_GRAVITY); }
        bool IsFalling() const;
        virtual bool CanSwim() const;

        float GetHoverOffset() const
        {
            return HasUnitMovementFlag(MOVEMENTFLAG_HOVER) ? GetFloatValue(UNIT_FIELD_HOVERHEIGHT) : 0.0f;
        }

        void RewardRage(uint32 damage, uint32 weaponSpeedHitFactor, bool attacker);

        virtual float GetFollowAngle() const { return static_cast<float>(M_PI/2); }

        void OutDebugInfo() const;
        virtual bool IsLoading() const { return false; }
        bool IsDuringRemoveFromWorld() const {return m_duringRemoveFromWorld;}

        Pet* ToPet() { if (IsPet()) return reinterpret_cast<Pet*>(this); else return nullptr; }
        Pet const* ToPet() const { if (IsPet()) return reinterpret_cast<Pet const*>(this); else return nullptr; }

        Totem* ToTotem() { if (IsTotem()) return reinterpret_cast<Totem*>(this); else return nullptr; }
        Totem const* ToTotem() const { if (IsTotem()) return reinterpret_cast<Totem const*>(this); else return nullptr; }

        TempSummon* ToTempSummon() { if (IsSummon()) return reinterpret_cast<TempSummon*>(this); else return nullptr; }
        TempSummon const* ToTempSummon() const { if (IsSummon()) return reinterpret_cast<TempSummon const*>(this); else return nullptr; }

        ObjectGuid GetTarget() const { return GetGuidValue(UNIT_FIELD_TARGET); }
        virtual void SetTarget(ObjectGuid /*guid*/) = 0;

        void SetInstantCast(bool set) { _instantCast = set; }
        bool CanInstantCast() const { return _instantCast; }

        // Movement info
        Movement::MoveSpline * movespline;

        int32 GetHighestExclusiveSameEffectSpellGroupValue(AuraEffect const* aurEff, AuraType auraType, bool checkMiscValue = false, int32 miscValue = 0) const;
        bool IsHighestExclusiveAura(Aura const* aura, bool removeOtherAuraApplications = false);

        virtual void Talk(std::string const& text, ChatMsg msgType, Language language, float textRange, WorldObject const* target);
        virtual void Say(std::string const& text, Language language, WorldObject const* target = nullptr);
        virtual void Yell(std::string const& text, Language language, WorldObject const* target = nullptr);
        virtual void TextEmote(std::string const& text, WorldObject const* target = nullptr, bool isBossEmote = false);
        virtual void Whisper(std::string const& text, Language language, Player* target, bool isBossWhisper = false);
        virtual void Talk(uint32 textId, ChatMsg msgType, float textRange, WorldObject const* target);
        virtual void Say(uint32 textId, WorldObject const* target = nullptr);
        virtual void Yell(uint32 textId, WorldObject const* target = nullptr);
        virtual void TextEmote(uint32 textId, WorldObject const* target = nullptr, bool isBossEmote = false);
        virtual void Whisper(uint32 textId, Player* target, bool isBossWhisper = false);

        float GetCollisionHeight() const override;

        std::string GetDebugInfo() const override;
    protected:
        explicit Unit (bool isWorldObject);

        void BuildValuesUpdate(uint8 updatetype, ByteBuffer* data, Player* target) const override;

        void _UpdateSpells(uint32 time);
        void _DeleteRemovedAuras();

        void _UpdateAutoRepeatSpell();

        bool m_ControlledByPlayer;

        bool m_AutoRepeatFirstCast;

        uint32 m_attackTimer[MAX_ATTACK];

        float m_createStats[MAX_STATS];

        AttackerSet m_attackers;
        Unit* m_attacking;

        DeathState m_deathState;

        int32 m_procDeep;

        typedef std::list<DynamicObject*> DynObjectList;
        DynObjectList m_dynObj;

        typedef std::list<GameObject*> GameObjectList;
        GameObjectList m_gameObj;

        uint32 m_transformSpell;

        Spell* m_currentSpells[CURRENT_MAX_SPELL];

        AuraMap m_ownedAuras;
        AuraApplicationMap m_appliedAuras;
        AuraList m_removedAuras;
        AuraMap::iterator m_auraUpdateIterator;
        uint32 m_removedAurasCount;

        AuraEffectList m_modAuras[TOTAL_AURAS];
        AuraList m_scAuras;                        // cast singlecast auras
        AuraApplicationList m_interruptableAuras;  // auras which have interrupt mask applied on unit
        AuraStateAurasMap m_auraStateAuras;        // Used for improve performance of aura state checks on aura apply/remove
        uint32 m_interruptMask;

        float m_auraFlatModifiersGroup[UNIT_MOD_END][MODIFIER_TYPE_FLAT_END];
        float m_auraPctModifiersGroup[UNIT_MOD_END][MODIFIER_TYPE_PCT_END];
        float m_weaponDamage[MAX_ATTACK][2][2];
        bool m_canModifyStats;
        VisibleAuraMap m_visibleAuras;

        float m_speed_rate[MAX_MOVE_TYPE];

        Unit* m_unitMovedByMe;    // only ever set for players, and only for direct client control
        Player* m_playerMovingMe; // only set for direct client control (possess effects, vehicles and similar)
        Unit* m_charmer; // Unit that is charming ME
        Unit* m_charmed; // Unit that is being charmed BY ME
        CharmInfo* m_charmInfo;
        SharedVisionList m_sharedVision;

        MotionMaster* i_motionMaster;

        uint32 m_reactiveTimer[MAX_REACTIVE];
        uint32 m_regenTimer;

        Vehicle* m_vehicle;
        Vehicle* m_vehicleKit;

        uint32 m_unitTypeMask;
        LiquidTypeEntry const* _lastLiquid;

        bool IsAlwaysVisibleFor(WorldObject const* seer) const override;
        bool IsAlwaysDetectableFor(WorldObject const* seer) const override;

        void DisableSpline();

        void ProcessPositionDataChanged(PositionFullTerrainStatus const& data) override;
        virtual void ProcessTerrainStatusUpdate(ZLiquidStatus status, Optional<LiquidData> const& liquidData);

        // notifiers
        virtual void AtEnterCombat() { }
        virtual void AtExitCombat();

        virtual void AtEngage(Unit* /*target*/) {}
        virtual void AtDisengage() {}

    private:

        void UpdateSplineMovement(uint32 t_diff);
        void UpdateSplinePosition();

        // player or player's pet
        float GetCombatRatingReduction(CombatRating cr) const;
        uint32 GetCombatRatingDamageReduction(CombatRating cr, float rate, float cap, uint32 damage) const;

        void ProcSkillsAndReactives(bool isVictim, Unit* procTarget, uint32 typeMask, uint32 hitMask, WeaponAttackType attType);

        void SetFeared(bool apply);
        void SetConfused(bool apply);
        void SetStunned(bool apply);
        void SetRooted(bool apply);

        uint32 m_rootTimes;

        uint32 m_state;                                     // Even derived shouldn't modify
        uint32 m_lastManaUse;                               // msecs
        TimeTrackerSmall m_movesplineTimer;

        DiminishingReturn m_Diminishing[DIMINISHING_MAX];

        // Threat+combat management
        friend class CombatManager;
        CombatManager m_combatManager;
        friend class ThreatManager;
        ThreatManager m_threatManager;

        void UpdateCharmAI();
        void RestoreDisabledAI();
        typedef std::stack<std::shared_ptr<UnitAI>> UnitAIStack;
        UnitAIStack i_AIs;
        std::shared_ptr<UnitAI> i_AI;
        bool m_aiLocked;

        std::unordered_set<AbstractFollower*> m_followingMe;

        Unit* m_comboTarget;
        int8 m_comboPoints;
        std::unordered_set<Unit*> m_ComboPointHolders;

        bool m_cleanupDone; // lock made to not add stuff after cleanup before delete
        bool m_duringRemoveFromWorld; // lock made to not add stuff after begining removing from world
        bool _instantCast;

        uint32 _oldFactionId;           ///< faction before charm
        bool _isWalkingBeforeCharm;     ///< Are we walking before we were charmed?

        SpellHistory* m_spellHistory;
};

namespace Trinity
{
    // Binary predicate for sorting Units based on percent value of a power
    class PowerPctOrderPred
    {
        public:
            PowerPctOrderPred(Powers power, bool ascending = true) : _power(power), _ascending(ascending) { }

            bool operator()(WorldObject const* objA, WorldObject const* objB) const
            {
                Unit const* a = objA->ToUnit();
                Unit const* b = objB->ToUnit();
                float rA = (a && a->GetMaxPower(_power)) ? float(a->GetPower(_power)) / float(a->GetMaxPower(_power)) : 0.0f;
                float rB = (b && b->GetMaxPower(_power)) ? float(b->GetPower(_power)) / float(b->GetMaxPower(_power)) : 0.0f;
                return _ascending ? rA < rB : rA > rB;
            }

            bool operator()(Unit const* a, Unit const* b) const
            {
                float rA = a->GetMaxPower(_power) ? float(a->GetPower(_power)) / float(a->GetMaxPower(_power)) : 0.0f;
                float rB = b->GetMaxPower(_power) ? float(b->GetPower(_power)) / float(b->GetMaxPower(_power)) : 0.0f;
                return _ascending ? rA < rB : rA > rB;
            }

        private:
            Powers const _power;
            bool const _ascending;
    };

    // Binary predicate for sorting Units based on percent value of health
    class HealthPctOrderPred
    {
        public:
            HealthPctOrderPred(bool ascending = true) : _ascending(ascending) { }

            bool operator()(WorldObject const* objA, WorldObject const* objB) const
            {
                Unit const* a = objA->ToUnit();
                Unit const* b = objB->ToUnit();
                float rA = (a && a->GetMaxHealth()) ? float(a->GetHealth()) / float(a->GetMaxHealth()) : 0.0f;
                float rB = (b && b->GetMaxHealth()) ? float(b->GetHealth()) / float(b->GetMaxHealth()) : 0.0f;
                return _ascending ? rA < rB : rA > rB;
            }

            bool operator() (Unit const* a, Unit const* b) const
            {
                float rA = a->GetMaxHealth() ? float(a->GetHealth()) / float(a->GetMaxHealth()) : 0.0f;
                float rB = b->GetMaxHealth() ? float(b->GetHealth()) / float(b->GetMaxHealth()) : 0.0f;
                return _ascending ? rA < rB : rA > rB;
            }

        private:
            bool const _ascending;
    };
}

#endif
