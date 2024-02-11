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

#ifndef __UNIT_H
#define __UNIT_H

#include "Object.h"
#include "CombatManager.h"
#include "FlatSet.h"
#include "SpellAuraDefines.h"
#include "ThreatManager.h"
#include "Timer.h"
#include "UnitDefines.h"
#include "Util.h"
#include <array>
#include <forward_list>
#include <map>
#include <memory>
#include <stack>

#define VISUAL_WAYPOINT 1 // Creature Entry ID used for waypoints show, visible only for GMs
#define WORLD_TRIGGER 12999
#define ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE 197886
#define SPELL_DH_DOUBLE_JUMP 196055
#define DISPLAYID_HIDDEN_MOUNT 73200

#define WARMODE_ENLISTED_SPELL_OUTSIDE 269083

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
struct CharmInfo;
struct FactionTemplateEntry;
struct LiquidData;
struct LiquidTypeEntry;
struct MountCapabilityEntry;
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
class Spell;
class SpellCastTargets;
class SpellEffectInfo;
class SpellHistory;
class SpellInfo;
class Totem;
class Transport;
class TransportBase;
class UnitAI;
class UnitAura;
class Vehicle;
class VehicleJoinEvent;

enum CharmType : uint8;
enum class EncounterType : uint8;
enum class PetActionFeedback : uint8;
enum MovementGeneratorType : uint8;
enum ProcFlagsHit : uint32;
enum ProcFlagsSpellPhase : uint32;
enum ProcFlagsSpellType : uint32;
enum ZLiquidStatus : uint32;

namespace Movement
{
    class MoveSpline;
    struct SpellEffectExtraData;
}

typedef std::list<Unit*> UnitList;

class TC_GAME_API DispelableAura
{
    public:
        DispelableAura(Aura* aura, int32 dispelChance, uint8 dispelCharges);
        ~DispelableAura();

        Aura* GetAura() const { return _aura; }
        bool RollDispel() const;
        uint8 GetDispelCharges() const { return _charges; }

        void IncrementCharges() { ++_charges; }
        bool DecrementCharge(uint8 charges)
        {
            if (!_charges)
                return false;

            _charges -= charges;
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
    BASE_PCT_EXCLUDE_CREATE = 1,    // percent modifier affecting all stat values from auras and gear but not player base for level
    TOTAL_VALUE = 2,
    MODIFIER_TYPE_FLAT_END = 3
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
    UNIT_MOD_STAT_STRENGTH,                                 // UNIT_MOD_STAT_STRENGTH..UNIT_MOD_STAT_INTELLECT must be in existed order, it's accessed by index values of Stats enum.
    UNIT_MOD_STAT_AGILITY,
    UNIT_MOD_STAT_STAMINA,
    UNIT_MOD_STAT_INTELLECT,
    UNIT_MOD_HEALTH,
    UNIT_MOD_MANA,                                          // UNIT_MOD_MANA..UNIT_MOD_PAIN must be listed in existing order, it is accessed by index values of Powers enum.
    UNIT_MOD_RAGE,
    UNIT_MOD_FOCUS,
    UNIT_MOD_ENERGY,
    UNIT_MOD_COMBO_POINTS,
    UNIT_MOD_RUNES,
    UNIT_MOD_RUNIC_POWER,
    UNIT_MOD_SOUL_SHARDS,
    UNIT_MOD_LUNAR_POWER,
    UNIT_MOD_HOLY_POWER,
    UNIT_MOD_ALTERNATE,
    UNIT_MOD_MAELSTROM,
    UNIT_MOD_CHI,
    UNIT_MOD_INSANITY,
    UNIT_MOD_BURNING_EMBERS,
    UNIT_MOD_DEMONIC_FURY,
    UNIT_MOD_ARCANE_CHARGES,
    UNIT_MOD_FURY,
    UNIT_MOD_PAIN,
    UNIT_MOD_ESSENCE,
    UNIT_MOD_RUNE_BLOOD,
    UNIT_MOD_RUNE_FROST,
    UNIT_MOD_RUNE_UNHOLY,
    UNIT_MOD_ALTERNATE_QUEST,
    UNIT_MOD_ALTERNATE_ENCOUNTER,
    UNIT_MOD_ALTERNATE_MOUNT,
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
    UNIT_MOD_STAT_END = UNIT_MOD_STAT_INTELLECT + 1,
    UNIT_MOD_RESISTANCE_START = UNIT_MOD_ARMOR,
    UNIT_MOD_RESISTANCE_END = UNIT_MOD_RESISTANCE_ARCANE + 1,
    UNIT_MOD_POWER_START = UNIT_MOD_MANA,
    UNIT_MOD_POWER_END = UNIT_MOD_ALTERNATE_MOUNT + 1
};

static_assert(UNIT_MOD_POWER_END - UNIT_MOD_POWER_START == MAX_POWERS, "UnitMods powers section does not match Powers enum!");

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
    UNIT_STATE_DIED                  = 0x00000001, // player has fake death aura
    UNIT_STATE_MELEE_ATTACKING       = 0x00000002, // player is melee attacking someone
    UNIT_STATE_CHARMED               = 0x00000004, // having any kind of charm aura on self
    UNIT_STATE_STUNNED               = 0x00000008,
    UNIT_STATE_ROAMING               = 0x00000010,
    UNIT_STATE_CHASE                 = 0x00000020,
    UNIT_STATE_FOCUSING              = 0x00000040,
    UNIT_STATE_FLEEING               = 0x00000080,
    UNIT_STATE_IN_FLIGHT             = 0x00000100, // player is in flight mode
    UNIT_STATE_FOLLOW                = 0x00000200,
    UNIT_STATE_ROOT                  = 0x00000400,
    UNIT_STATE_CONFUSED              = 0x00000800,
    UNIT_STATE_DISTRACTED            = 0x00001000,
    UNIT_STATE_ISOLATED              = 0x00002000, // area auras do not affect other players
    UNIT_STATE_ATTACK_PLAYER         = 0x00004000,
    UNIT_STATE_CASTING               = 0x00008000,
    UNIT_STATE_POSSESSED             = 0x00010000, // being possessed by another unit
    UNIT_STATE_CHARGING              = 0x00020000,
    UNIT_STATE_JUMPING               = 0x00040000,
    UNIT_STATE_FOLLOW_FORMATION      = 0x00080000,
    UNIT_STATE_MOVE                  = 0x00100000,
    UNIT_STATE_ROTATING              = 0x00200000,
    UNIT_STATE_EVADE                 = 0x00400000,
    UNIT_STATE_ROAMING_MOVE          = 0x00800000,
    UNIT_STATE_CONFUSED_MOVE         = 0x01000000,
    UNIT_STATE_FLEEING_MOVE          = 0x02000000,
    UNIT_STATE_CHASE_MOVE            = 0x04000000,
    UNIT_STATE_FOLLOW_MOVE           = 0x08000000,
    UNIT_STATE_IGNORE_PATHFINDING    = 0x10000000, // do not use pathfinding in any MovementGenerator
    UNIT_STATE_FOLLOW_FORMATION_MOVE = 0x20000000,

    UNIT_STATE_ALL_STATE_SUPPORTED = UNIT_STATE_DIED | UNIT_STATE_MELEE_ATTACKING | UNIT_STATE_CHARMED | UNIT_STATE_STUNNED | UNIT_STATE_ROAMING | UNIT_STATE_CHASE
                                   | UNIT_STATE_FOCUSING | UNIT_STATE_FLEEING | UNIT_STATE_IN_FLIGHT | UNIT_STATE_FOLLOW | UNIT_STATE_ROOT | UNIT_STATE_CONFUSED
                                   | UNIT_STATE_DISTRACTED | UNIT_STATE_ISOLATED | UNIT_STATE_ATTACK_PLAYER | UNIT_STATE_CASTING
                                   | UNIT_STATE_POSSESSED | UNIT_STATE_CHARGING | UNIT_STATE_JUMPING | UNIT_STATE_MOVE | UNIT_STATE_ROTATING
                                   | UNIT_STATE_EVADE | UNIT_STATE_ROAMING_MOVE | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE
                                   | UNIT_STATE_CHASE_MOVE | UNIT_STATE_FOLLOW_MOVE | UNIT_STATE_IGNORE_PATHFINDING | UNIT_STATE_FOLLOW_FORMATION_MOVE,

    UNIT_STATE_UNATTACKABLE        = UNIT_STATE_IN_FLIGHT,
    UNIT_STATE_MOVING              = UNIT_STATE_ROAMING_MOVE | UNIT_STATE_CONFUSED_MOVE | UNIT_STATE_FLEEING_MOVE | UNIT_STATE_CHASE_MOVE | UNIT_STATE_FOLLOW_MOVE | UNIT_STATE_FOLLOW_FORMATION_MOVE,
    UNIT_STATE_CONTROLLED          = UNIT_STATE_CONFUSED | UNIT_STATE_STUNNED | UNIT_STATE_FLEEING,
    UNIT_STATE_LOST_CONTROL        = UNIT_STATE_CONTROLLED | UNIT_STATE_POSSESSED | UNIT_STATE_JUMPING | UNIT_STATE_CHARGING,
    UNIT_STATE_CANNOT_AUTOATTACK   = UNIT_STATE_CONTROLLED | UNIT_STATE_CHARGING,
    UNIT_STATE_SIGHTLESS           = UNIT_STATE_LOST_CONTROL | UNIT_STATE_EVADE,
    UNIT_STATE_CANNOT_TURN         = UNIT_STATE_LOST_CONTROL | UNIT_STATE_ROTATING | UNIT_STATE_FOCUSING,
    UNIT_STATE_NOT_MOVE            = UNIT_STATE_ROOT | UNIT_STATE_STUNNED | UNIT_STATE_DIED | UNIT_STATE_DISTRACTED,

    UNIT_STATE_ALL_ERASABLE        = UNIT_STATE_ALL_STATE_SUPPORTED & ~(UNIT_STATE_IGNORE_PATHFINDING),
    UNIT_STATE_ALL_STATE           = 0xffffffff
};

TC_GAME_API extern float baseMoveSpeed[MAX_MOVE_TYPE];
TC_GAME_API extern float playerBaseMoveSpeed[MAX_MOVE_TYPE];

enum CombatRating
{
    CR_AMPLIFY                          = 0,
    CR_DEFENSE_SKILL                    = 1,
    CR_DODGE                            = 2,
    CR_PARRY                            = 3,
    CR_BLOCK                            = 4,
    CR_HIT_MELEE                        = 5,
    CR_HIT_RANGED                       = 6,
    CR_HIT_SPELL                        = 7,
    CR_CRIT_MELEE                       = 8,
    CR_CRIT_RANGED                      = 9,
    CR_CRIT_SPELL                       = 10,
    CR_CORRUPTION                       = 11,
    CR_CORRUPTION_RESISTANCE            = 12,
    CR_SPEED                            = 13,
    CR_RESILIENCE_CRIT_TAKEN            = 14,
    CR_RESILIENCE_PLAYER_DAMAGE         = 15,
    CR_LIFESTEAL                        = 16,
    CR_HASTE_MELEE                      = 17,
    CR_HASTE_RANGED                     = 18,
    CR_HASTE_SPELL                      = 19,
    CR_AVOIDANCE                        = 20,
    CR_STURDINESS                       = 21,
    CR_UNUSED_7                         = 22,
    CR_EXPERTISE                        = 23,
    CR_ARMOR_PENETRATION                = 24,
    CR_MASTERY                          = 25,
    CR_PVP_POWER                        = 26,
    CR_CLEAVE                           = 27,
    CR_VERSATILITY_DAMAGE_DONE          = 28,
    CR_VERSATILITY_HEALING_DONE         = 29,
    CR_VERSATILITY_DAMAGE_TAKEN         = 30,
    CR_UNUSED_12                        = 31
};

#define MAX_COMBAT_RATING         32

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
        uint32 const m_originalDamage;
        SpellInfo const* const m_spellInfo;
        SpellSchoolMask const m_schoolMask;
        DamageEffectType const m_damageType;
        WeaponAttackType m_attackType;
        uint32 m_absorb;
        uint32 m_resist;
        uint32 m_block;
        ProcFlagsHit m_hitMask;
    public:
        DamageInfo(Unit* attacker, Unit* victim, uint32 damage, SpellInfo const* spellInfo, SpellSchoolMask schoolMask, DamageEffectType damageType, WeaponAttackType attackType);
        explicit DamageInfo(CalcDamageInfo const& dmgInfo);
        DamageInfo(SpellNonMeleeDamage const& spellNonMeleeDamage, DamageEffectType damageType, WeaponAttackType attackType, ProcFlagsHit hitMask);

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
        uint32 GetOriginalDamage() const { return m_originalDamage; }
        uint32 GetAbsorb() const { return m_absorb; }
        uint32 GetResist() const { return m_resist; }
        uint32 GetBlock() const { return m_block; }

        ProcFlagsHit GetHitMask() const;
};

class TC_GAME_API HealInfo
{
    private:
        Unit* const _healer;
        Unit* const _target;
        uint32 _heal;
        uint32 const _originalHeal;
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
        uint32 GetOriginalHeal() const { return _originalHeal; }
        uint32 GetEffectiveHeal() const { return _effectiveHeal; }
        uint32 GetAbsorb() const { return _absorb; }
        SpellInfo const* GetSpellInfo() const { return _spellInfo; };
        SpellSchoolMask GetSchoolMask() const { return _schoolMask; };

        uint32 GetHitMask() const;
};

class TC_GAME_API ProcEventInfo
{
    public:
        ProcEventInfo(Unit* actor, Unit* actionTarget, Unit* procTarget, ProcFlagsInit const& typeMask,
                      ProcFlagsSpellType spellTypeMask, ProcFlagsSpellPhase spellPhaseMask, ProcFlagsHit hitMask,
                      Spell* spell, DamageInfo* damageInfo, HealInfo* healInfo);

        Unit* GetActor() const { return _actor; }
        Unit* GetActionTarget() const { return _actionTarget; }
        Unit* GetProcTarget() const { return _procTarget; }

        ProcFlagsInit GetTypeMask() const { return _typeMask; }
        ProcFlagsSpellType GetSpellTypeMask() const { return _spellTypeMask; }
        ProcFlagsSpellPhase GetSpellPhaseMask() const { return _spellPhaseMask; }
        ProcFlagsHit GetHitMask() const { return _hitMask; }

        SpellInfo const* GetSpellInfo() const;
        SpellSchoolMask GetSchoolMask() const;

        DamageInfo* GetDamageInfo() const { return _damageInfo; }
        HealInfo* GetHealInfo() const { return _healInfo; }

        Spell const* GetProcSpell() const { return _spell; }

    private:
        Unit* const _actor;
        Unit* const _actionTarget;
        Unit* const _procTarget;
        ProcFlagsInit _typeMask;
        ProcFlagsSpellType _spellTypeMask;
        ProcFlagsSpellPhase _spellPhaseMask;
        ProcFlagsHit _hitMask;
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
    uint32 DamageSchoolMask;
    uint32 Damage;
    uint32 OriginalDamage;
    uint32 Absorb;
    uint32 Resist;
    uint32 Blocked;
    uint32 HitInfo;
    uint32 TargetState;

    // Helpers
    WeaponAttackType AttackType; //
    ProcFlagsInit ProcAttacker;
    ProcFlagsInit ProcVictim;
    uint32 CleanDamage;          // Used only for rage calculation
    MeleeHitOutcome HitOutCome;  /// @todo remove this field (need use TargetState)
};

// Spell damage info structure based on structure sending in SMSG_SPELLNONMELEEDAMAGELOG opcode
struct TC_GAME_API SpellNonMeleeDamage
{
    SpellNonMeleeDamage(Unit* _attacker, Unit* _target, SpellInfo const* _spellInfo, SpellCastVisual spellVisual, uint32 _schoolMask, ObjectGuid _castId = ObjectGuid::Empty);

    Unit   *target;
    Unit   *attacker;
    ObjectGuid castId;
    SpellInfo const* Spell;
    SpellCastVisual SpellVisual;
    uint32 damage;
    uint32 originalDamage;
    uint32 schoolMask;
    uint32 absorb;
    uint32 resist;
    bool   periodicLog;
    uint32 blocked;
    uint32 HitInfo;
    // Used for help
    uint32 cleanDamage;
    bool   fullBlock;
    uint32 preHitHealth;
};

struct SpellPeriodicAuraLogInfo
{
    SpellPeriodicAuraLogInfo(AuraEffect const* _auraEff, uint32 _damage, uint32 _originalDamage, uint32 _overDamage, uint32 _absorb, uint32 _resist, float _multiplier, bool _critical)
        : auraEff(_auraEff), damage(_damage), originalDamage(_originalDamage), overDamage(_overDamage), absorb(_absorb), resist(_resist), multiplier(_multiplier), critical(_critical){ }

    AuraEffect const* auraEff;
    uint32 damage;
    uint32 originalDamage;
    uint32 overDamage;                                      // overkill/overheal
    uint32 absorb;
    uint32 resist;
    float  multiplier;
    bool   critical;
};

ProcFlagsHit createProcHitMask(SpellNonMeleeDamage* damageInfo, SpellMissInfo missCondition);

enum CurrentSpellTypes : uint8
{
    CURRENT_MELEE_SPELL             = 0,
    CURRENT_GENERIC_SPELL           = 1,
    CURRENT_CHANNELED_SPELL         = 2,
    CURRENT_AUTOREPEAT_SPELL        = 3
};

#define CURRENT_FIRST_NON_MELEE_SPELL 1
#define CURRENT_MAX_SPELL             4

typedef std::list<Player*> SharedVisionList;

// for clearing special attacks
#define REACTIVE_TIMER_START 4000

enum ReactiveType
{
    REACTIVE_DEFENSE      = 0,
    REACTIVE_DEFENSE_2    = 1,
    MAX_REACTIVE
};

struct PositionUpdateInfo
{
    void Reset()
    {
        Relocated = false;
        Turned = false;
    }

    bool Relocated = false;
    bool Turned = false;
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

        typedef std::forward_list<AuraEffect*> AuraEffectList;
        typedef std::forward_list<Aura*> AuraList;
        typedef std::forward_list<AuraApplication*> AuraApplicationList;
        typedef std::array<DiminishingReturn, DIMINISHING_MAX> Diminishing;

        typedef std::vector<std::pair<uint32 /*procEffectMask*/, AuraApplication*>> AuraApplicationProcContainer;

        struct VisibleAuraSlotCompare { bool operator()(AuraApplication* left, AuraApplication* right) const; };
        typedef std::set<AuraApplication*, VisibleAuraSlotCompare> VisibleAuraContainer;

        static std::vector<AuraEffect*> CopyAuraEffectList(AuraEffectList const& list);

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
        UnitAI* GetScheduledChangeAI();
        bool HasScheduledAIChange() const;
    public:

        void AddToWorld() override;
        void RemoveFromWorld() override;

        void CleanupBeforeRemoveFromMap(bool finalCleanup);
        void CleanupsBeforeDelete(bool finalCleanup = true) override;                        // used in ~Creature/~Player (or before mass creature delete to remove cross-references to already deleted units)

        virtual bool IsAffectedByDiminishingReturns() const { return (GetCharmerOrOwnerPlayerOrPlayerItself() != nullptr); }
        DiminishingLevels GetDiminishing(DiminishingGroup group) const;
        void IncrDiminishing(SpellInfo const* auraSpellInfo);
        bool ApplyDiminishingToDuration(SpellInfo const* auraSpellInfo, int32& duration, WorldObject* caster, DiminishingLevels previousLevel) const;
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
        float GetCombatReach() const override { return m_unitData->CombatReach; }
        void SetCombatReach(float combatReach) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::CombatReach), combatReach); }
        float GetBoundingRadius() const { return m_unitData->BoundingRadius; }
        void SetBoundingRadius(float boundingRadius) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::BoundingRadius), boundingRadius); }
        bool IsWithinCombatRange(Unit const* obj, float dist2compare) const;
        bool IsWithinMeleeRange(Unit const* obj) const { return IsWithinMeleeRangeAt(GetPosition(), obj); }
        bool IsWithinMeleeRangeAt(Position const& pos, Unit const* obj) const;
        float GetMeleeRange(Unit const* target) const;
        virtual SpellSchoolMask GetMeleeDamageSchoolMask(WeaponAttackType attackType = BASE_ATTACK) const = 0;
        bool IsWithinBoundaryRadius(const Unit* obj) const;
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

        int32 GetContentTuning() const { return m_unitData->ContentTuningID; }
        uint8 GetLevel() const { return uint8(m_unitData->Level); }
        uint8 GetLevelForTarget(WorldObject const* /*target*/) const override { return GetLevel(); }
        void SetLevel(uint8 lvl, bool sendUpdate = true);
        uint8 GetRace() const { return m_unitData->Race; }
        void SetRace(uint8 race) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Race), race); }
        uint64 GetRaceMask() const { return UI64LIT(1) << (GetRace() - 1); }
        uint8 GetClass() const { return m_unitData->ClassId; }
        void SetClass(uint8 classId) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ClassId), classId); }
        uint32 GetClassMask() const { return 1 << (GetClass()-1); }
        Gender GetGender() const { return Gender(*m_unitData->Sex); }
        void SetGender(Gender gender) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Sex), gender); }
        virtual Gender GetNativeGender() const { return GetGender(); }
        virtual void SetNativeGender(Gender gender) { SetGender(gender); }

        float GetStat(Stats stat) const { return float(m_unitData->Stats[stat]); }
        void SetStat(Stats stat, int32 val) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Stats, stat), val); }
        uint32 GetArmor() const { return GetResistance(SPELL_SCHOOL_NORMAL); }
        void SetArmor(int32 val, int32 bonusVal)
        {
            SetResistance(SPELL_SCHOOL_NORMAL, val);
            SetBonusResistanceMod(SPELL_SCHOOL_NORMAL, bonusVal);
        }

        int32 GetResistance(SpellSchools school) const { return m_unitData->Resistances[school]; }
        int32 GetBonusResistanceMod(SpellSchools school) const { return m_unitData->BonusResistanceMods[school]; }
        int32 GetResistance(SpellSchoolMask mask) const;
        void SetResistance(SpellSchools school, int32 val) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Resistances, school), val); }
        void SetBonusResistanceMod(SpellSchools school, int32 val) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::BonusResistanceMods, school), val); }
        static float CalculateAverageResistReduction(WorldObject const* caster, SpellSchoolMask schoolMask, Unit const* victim, SpellInfo const* spellInfo = nullptr);

        uint64 GetHealth()    const { return m_unitData->Health; }
        uint64 GetMaxHealth() const { return m_unitData->MaxHealth; }

        bool IsFullHealth() const { return GetHealth() == GetMaxHealth(); }
        bool HealthBelowPct(int32 pct) const { return GetHealth() < CountPctFromMaxHealth(pct); }
        bool HealthBelowPctDamaged(int32 pct, uint32 damage) const { return int64(GetHealth()) - int64(damage) < int64(CountPctFromMaxHealth(pct)); }
        bool HealthAbovePct(int32 pct) const { return GetHealth() > CountPctFromMaxHealth(pct); }
        bool HealthAbovePctHealed(int32 pct, uint32 heal) const { return uint64(GetHealth()) + uint64(heal) > CountPctFromMaxHealth(pct); }
        float GetHealthPct() const { return GetMaxHealth() ? 100.f * GetHealth() / GetMaxHealth() : 0.0f; }
        uint64 CountPctFromMaxHealth(int32 pct) const { return CalculatePct(GetMaxHealth(), pct); }
        uint64 CountPctFromCurHealth(int32 pct) const { return CalculatePct(GetHealth(), pct); }

        void SetHealth(uint64 val);
        void SetMaxHealth(uint64 val);
        inline void SetFullHealth() { SetHealth(GetMaxHealth()); }
        int64 ModifyHealth(int64 val);
        int64 GetHealthGain(int64 dVal);
        void TriggerOnHealthChangeAuras(uint64 oldVal, uint64 newVal);

        virtual float GetHealthMultiplierForTarget(WorldObject const* /*target*/) const { return 1.0f; }
        virtual float GetDamageMultiplierForTarget(WorldObject const* /*target*/) const { return 1.0f; }
        virtual float GetArmorMultiplierForTarget(WorldObject const* /*target*/) const { return 1.0f; }

        Powers GetPowerType() const { return Powers(*m_unitData->DisplayPower); }
        void SetPowerType(Powers power, bool sendUpdate = true);
        void SetOverrideDisplayPowerId(uint32 powerDisplayId) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::OverrideDisplayPowerID), powerDisplayId); }
        Powers CalculateDisplayPowerType() const;
        void UpdateDisplayPower();
        int32 GetPower(Powers power) const;
        int32 GetMinPower(Powers power) const { return power == POWER_LUNAR_POWER ? -100 : 0; }
        int32 GetMaxPower(Powers power) const;
        float GetPowerPct(Powers power) const { return GetMaxPower(power) ? 100.f * GetPower(power) / GetMaxPower(power) : 0.0f; }
        int32 CountPctFromMaxPower(Powers power, int32 pct) const { return CalculatePct(GetMaxPower(power), pct); }
        void SetPower(Powers power, int32 val, bool withPowerUpdate = true);
        void SetMaxPower(Powers power, int32 val);
        void TriggerOnPowerChangeAuras(Powers power, int32 oldVal, int32 newVal);
        inline void SetFullPower(Powers power) { SetPower(power, GetMaxPower(power)); }
        // returns the change in power
        int32 ModifyPower(Powers power, int32 val, bool withPowerUpdate = true);

        void ApplyModManaCostMultiplier(float manaCostMultiplier, bool apply) { ApplyModUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ManaCostMultiplier),  manaCostMultiplier, apply); }
        void ApplyModManaCostModifier(SpellSchools school, int32 mod, bool apply) { ApplyModUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ManaCostModifier, school), mod, apply); }

        uint32 GetBaseAttackTime(WeaponAttackType att) const;
        void SetBaseAttackTime(WeaponAttackType att, uint32 val);
        void UpdateAttackTimeField(WeaponAttackType att);
        void ApplyAttackTimePercentMod(WeaponAttackType att, float val, bool apply);
        void ApplyCastTimePercentMod(float val, bool apply);

        void SetModCastingSpeed(float castingSpeed) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModCastingSpeed), castingSpeed); }
        void SetModSpellHaste(float spellHaste) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModSpellHaste), spellHaste); }
        void SetModHaste(float haste) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModHaste), haste); }
        void SetModRangedHaste(float rangedHaste) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModRangedHaste), rangedHaste); }
        void SetModHasteRegen(float hasteRegen) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModHasteRegen), hasteRegen); }
        void SetModTimeRate(float timeRate) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ModTimeRate), timeRate); }

        bool HasUnitFlag(UnitFlags flags) const { return (*m_unitData->Flags & flags) != 0; }
        void SetUnitFlag(UnitFlags flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Flags), flags); }
        void RemoveUnitFlag(UnitFlags flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Flags), flags); }
        void ReplaceAllUnitFlags(UnitFlags flags) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Flags), flags); }

        bool HasUnitFlag2(UnitFlags2 flags) const { return (*m_unitData->Flags2 & flags) != 0; }
        void SetUnitFlag2(UnitFlags2 flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Flags2), flags); }
        void RemoveUnitFlag2(UnitFlags2 flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Flags2), flags); }
        void ReplaceAllUnitFlags2(UnitFlags2 flags) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Flags2), flags); }

        bool HasUnitFlag3(UnitFlags3 flags) const { return (*m_unitData->Flags3 & flags) != 0; }
        void SetUnitFlag3(UnitFlags3 flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Flags3), flags); }
        void RemoveUnitFlag3(UnitFlags3 flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Flags3), flags); }
        void ReplaceAllUnitFlags3(UnitFlags3 flags) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Flags3), flags); }

        void SetCreatedBySpell(int32 spellId) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::CreatedBySpell), spellId); }

        void SetNameplateAttachToGUID(ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::NameplateAttachToGUID), guid); }

        Emote GetEmoteState() const { return Emote(*m_unitData->EmoteState); }
        void SetEmoteState(Emote emote) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::EmoteState), emote); }

        SheathState GetSheath() const { return SheathState(*m_unitData->SheatheState); }
        void SetSheath(SheathState sheathed);

        // faction template id
        uint32 GetFaction() const override { return m_unitData->FactionTemplate; }
        void SetFaction(uint32 faction) override { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::FactionTemplate), faction); }

        bool IsInPartyWith(Unit const* unit) const;
        bool IsInRaidWith(Unit const* unit) const;
        void GetPartyMembers(std::list<Unit*> &units);
        bool IsContestedGuard() const;

        UnitPVPStateFlags GetPvpFlags() const { return UnitPVPStateFlags(*m_unitData->PvpFlags); }
        bool HasPvpFlag(UnitPVPStateFlags flags) const { return (*m_unitData->PvpFlags & flags) != 0; }
        void SetPvpFlag(UnitPVPStateFlags flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::PvpFlags), flags); }
        void RemovePvpFlag(UnitPVPStateFlags flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::PvpFlags), flags); }
        void ReplaceAllPvpFlags(UnitPVPStateFlags flags) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::PvpFlags), flags); }

        bool IsInSanctuary() const { return HasPvpFlag(UNIT_BYTE2_FLAG_SANCTUARY); }
        bool IsPvP() const { return HasPvpFlag(UNIT_BYTE2_FLAG_PVP); }
        bool IsFFAPvP() const { return HasPvpFlag(UNIT_BYTE2_FLAG_FFA_PVP); }
        virtual void SetPvP(bool state);

        UnitPetFlag GetPetFlags() const { return UnitPetFlag(*m_unitData->PetFlags); }
        bool HasPetFlag(UnitPetFlag flags) const { return (*m_unitData->PetFlags & flags) != 0; }
        void SetPetFlag(UnitPetFlag flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::PetFlags), flags); }
        void RemovePetFlag(UnitPetFlag flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::PetFlags), flags); }
        void ReplaceAllPetFlags(UnitPetFlag flags) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::PetFlags), flags); }

        uint32 GetCreatureType() const;
        uint32 GetCreatureTypeMask() const;

        UnitStandStateType GetStandState() const { return UnitStandStateType(*m_unitData->StandState); }
        bool IsSitState() const;
        bool IsStandState() const;
        void SetStandState(UnitStandStateType state, uint32 animKitID = 0);

        void SetVisFlag(UnitVisFlags flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::VisFlags), flags); }
        void RemoveVisFlag(UnitVisFlags flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::VisFlags), flags); }
        void ReplaceAllVisFlags(UnitVisFlags flags) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::VisFlags), flags); }

        AnimTier GetAnimTier() const { return AnimTier(*m_unitData->AnimTier); }
        void SetAnimTier(AnimTier animTier, bool notifyClient = true);

        bool IsMounted() const { return HasUnitFlag(UNIT_FLAG_MOUNT); }
        uint32 GetMountDisplayId() const { return m_unitData->MountDisplayID; }
        void SetMountDisplayId(uint32 mountDisplayId) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::MountDisplayID), mountDisplayId); }
        uint32 GetCosmeticMountDisplayId() const { return m_unitData->CosmeticMountDisplayID; }
        void SetCosmeticMountDisplayId(uint32 mountDisplayId) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::CosmeticMountDisplayID), mountDisplayId); }
        void Mount(uint32 mount, uint32 vehicleId = 0, uint32 creatureEntry = 0);
        void Dismount();
        MountCapabilityEntry const* GetMountCapability(uint32 mountType) const;
        void UpdateMountCapability();

        void SendDurabilityLoss(Player* receiver, uint32 percent);
        void PlayOneShotAnimKitId(uint16 animKitId);
        void SetAIAnimKitId(uint16 animKitId);
        uint16 GetAIAnimKitId() const override { return _aiAnimKitId; }
        void SetMovementAnimKitId(uint16 animKitId);
        uint16 GetMovementAnimKitId() const override { return _movementAnimKitId; }
        void SetMeleeAnimKitId(uint16 animKitId);
        uint16 GetMeleeAnimKitId() const override { return _meleeAnimKitId; }

        uint16 GetMaxSkillValueForLevel(Unit const* target = nullptr) const { return (target ? GetLevelForTarget(target) : GetLevel()) * 5; }
        static void DealDamageMods(Unit const* attacker, Unit const* victim, uint32& damage, uint32* absorb);
        static uint32 DealDamage(Unit* attacker, Unit* victim, uint32 damage, CleanDamage const* cleanDamage = nullptr, DamageEffectType damagetype = DIRECT_DAMAGE, SpellSchoolMask damageSchoolMask = SPELL_SCHOOL_MASK_NORMAL, SpellInfo const* spellProto = nullptr, bool durabilityLoss = true);
        static void Kill(Unit* attacker, Unit* victim, bool durabilityLoss = true, bool skipSettingDeathState = false);
        void KillSelf(bool durabilityLoss = true, bool skipSettingDeathState = false) { Unit::Kill(this, this, durabilityLoss, skipSettingDeathState); }
        static void DealHeal(HealInfo& healInfo);

        static void ProcSkillsAndAuras(Unit* actor, Unit* actionTarget, ProcFlagsInit const& typeMaskActor, ProcFlagsInit const& typeMaskActionTarget,
                                ProcFlagsSpellType spellTypeMask, ProcFlagsSpellPhase spellPhaseMask, ProcFlagsHit hitMask, Spell* spell,
                                DamageInfo* damageInfo, HealInfo* healInfo);

        void GetProcAurasTriggeredOnEvent(AuraApplicationProcContainer& aurasTriggeringProc, AuraApplicationList* procAuras, ProcEventInfo& eventInfo);
        void TriggerAurasProcOnEvent(AuraApplicationList* myProcAuras, AuraApplicationList* targetProcAuras,
                                     Unit* actionTarget, ProcFlagsInit const& typeMaskActor, ProcFlagsInit const& typeMaskActionTarget,
                                     ProcFlagsSpellType spellTypeMask, ProcFlagsSpellPhase spellPhaseMask, ProcFlagsHit hitMask, Spell* spell,
                                     DamageInfo* damageInfo, HealInfo* healInfo);
        void TriggerAurasProcOnEvent(ProcEventInfo& eventInfo, AuraApplicationProcContainer& procAuras);

        void HandleEmoteCommand(Emote emoteId, Player* target = nullptr, Trinity::IteratorPair<int32 const*> spellVisualKitIds = {}, int32 sequenceVariation = 0);
        void DoMeleeAttackIfReady();
        void AttackerStateUpdate(Unit* victim, WeaponAttackType attType = BASE_ATTACK, bool extra = false);

        void CalculateMeleeDamage(Unit* victim, CalcDamageInfo* damageInfo, WeaponAttackType attackType = BASE_ATTACK);
        void DealMeleeDamage(CalcDamageInfo* damageInfo, bool durabilityLoss);
        void HandleProcExtraAttackFor(Unit* victim, uint32 count);

        void SetLastExtraAttackSpell(uint32 spellId) { _lastExtraAttackSpell = spellId; }
        uint32 GetLastExtraAttackSpell() const { return _lastExtraAttackSpell; }
        void AddExtraAttacks(uint32 count);
        void SetLastDamagedTargetGuid(ObjectGuid guid) { _lastDamagedTargetGuid = guid; }
        ObjectGuid GetLastDamagedTargetGuid() const { return _lastDamagedTargetGuid; }

        void CalculateSpellDamageTaken(SpellNonMeleeDamage* damageInfo, int32 damage, SpellInfo const* spellInfo, WeaponAttackType attackType = BASE_ATTACK, bool crit = false, bool blocked = false, Spell* spell = nullptr);
        void DealSpellDamage(SpellNonMeleeDamage const* damageInfo, bool durabilityLoss);

        // player or player's pet resilience (-1%)
        uint32 GetDamageReduction(uint32 damage) const { return GetCombatRatingDamageReduction(CR_RESILIENCE_PLAYER_DAMAGE, 1.0f, 100.0f, damage); }

        virtual bool CanApplyResilience() const;
        static void ApplyResilience(Unit const* victim, int32* damage);

        int32 CalculateAOEAvoidance(int32 damage, uint32 schoolMask, bool npcCaster) const;

        float MeleeSpellMissChance(Unit const* victim, WeaponAttackType attType, SpellInfo const* spellInfo) const override;
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

        virtual float GetBlockPercent(uint8 /*attackerLevel*/) const { return 30.0f; }

        float GetWeaponProcChance() const;
        float GetPPMProcChance(uint32 WeaponSpeed, float PPM, SpellInfo const* spellProto) const;

        MeleeHitOutcome RollMeleeOutcomeAgainst(Unit const* victim, WeaponAttackType attType) const;

        NPCFlags GetNpcFlags() const { return NPCFlags(m_unitData->NpcFlags[0]); }
        bool HasNpcFlag(NPCFlags flags) const { return (m_unitData->NpcFlags[0] & flags) != 0; }
        void SetNpcFlag(NPCFlags flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::NpcFlags, 0), flags); }
        void RemoveNpcFlag(NPCFlags flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::NpcFlags, 0), flags); }
        void ReplaceAllNpcFlags(NPCFlags flags) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::NpcFlags, 0), flags); }

        NPCFlags2 GetNpcFlags2() const { return NPCFlags2(m_unitData->NpcFlags[1]); }
        bool HasNpcFlag2(NPCFlags2 flags) const { return (m_unitData->NpcFlags[1] & flags) != 0; }
        void SetNpcFlag2(NPCFlags2 flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::NpcFlags, 1), flags); }
        void RemoveNpcFlag2(NPCFlags2 flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::NpcFlags, 1), flags); }
        void ReplaceAllNpcFlags2(NPCFlags2 flags) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::NpcFlags, 1), flags); }

        bool IsVendor()         const { return HasNpcFlag(UNIT_NPC_FLAG_VENDOR); }
        bool IsTrainer()        const { return HasNpcFlag(UNIT_NPC_FLAG_TRAINER); }
        bool IsQuestGiver()     const { return HasNpcFlag(UNIT_NPC_FLAG_QUESTGIVER); }
        bool IsGossip()         const { return HasNpcFlag(UNIT_NPC_FLAG_GOSSIP); }
        bool IsTaxi()           const { return HasNpcFlag(UNIT_NPC_FLAG_FLIGHTMASTER); }
        bool IsGuildMaster()    const { return HasNpcFlag(UNIT_NPC_FLAG_PETITIONER); }
        bool IsBattleMaster()   const { return HasNpcFlag(UNIT_NPC_FLAG_BATTLEMASTER); }
        bool IsBanker()         const { return HasNpcFlag(UNIT_NPC_FLAG_BANKER); }
        bool IsInnkeeper()      const { return HasNpcFlag(UNIT_NPC_FLAG_INNKEEPER); }
        bool IsSpiritHealer()   const { return HasNpcFlag(UNIT_NPC_FLAG_SPIRIT_HEALER); }
        bool IsAreaSpiritHealer() const { return HasNpcFlag(UNIT_NPC_FLAG_AREA_SPIRIT_HEALER); }
        bool IsTabardDesigner() const { return HasNpcFlag(UNIT_NPC_FLAG_TABARDDESIGNER); }
        bool IsAuctioner()      const { return HasNpcFlag(UNIT_NPC_FLAG_AUCTIONEER); }
        bool IsArmorer()        const { return HasNpcFlag(UNIT_NPC_FLAG_REPAIR); }
        bool IsWildBattlePet()  const { return HasNpcFlag(UNIT_NPC_FLAG_WILD_BATTLE_PET); }
        bool IsServiceProvider() const;
        bool IsSpiritService() const { return HasNpcFlag(UNIT_NPC_FLAG_SPIRIT_HEALER | UNIT_NPC_FLAG_AREA_SPIRIT_HEALER); }
        bool IsAreaSpiritHealerIndividual() const { return HasNpcFlag2(UNIT_NPC_FLAG_2_AREA_SPIRIT_HEALER_INDIVIDUAL); }
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
        bool IsImmuneToPC() const { return HasUnitFlag(UNIT_FLAG_IMMUNE_TO_PC); }
        void SetImmuneToPC(bool apply, bool keepCombat);
        virtual void SetImmuneToPC(bool apply) { SetImmuneToPC(apply, false); }
        bool IsImmuneToNPC() const { return HasUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC); }
        void SetImmuneToNPC(bool apply, bool keepCombat);
        virtual void SetImmuneToNPC(bool apply) { SetImmuneToNPC(apply, false); }

        bool IsUninteractible() const { return HasUnitFlag(UNIT_FLAG_UNINTERACTIBLE); }
        void SetUninteractible(bool apply);

        bool CannotTurn() const { return HasUnitFlag2(UNIT_FLAG2_CANNOT_TURN); }
        void SetCannotTurn(bool apply);

        bool IsInCombat() const { return HasUnitFlag(UNIT_FLAG_IN_COMBAT); }
        bool IsInCombatWith(Unit const* who) const { return who && m_combatManager.IsInCombatWith(who); }
        void SetInCombatWith(Unit* enemy, bool addSecondUnitSuppressed = false) { if (enemy) m_combatManager.SetInCombatWith(enemy, addSecondUnitSuppressed); }
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

        bool HasAuraTypeWithFamilyFlags(AuraType auraType, uint32 familyName, flag128 familyFlags) const;
        bool virtual HasSpell(uint32 /*spellID*/) const { return false; }
        bool HasBreakableByDamageAuraType(AuraType type, uint32 excludeAura = 0) const;
        bool HasBreakableByDamageCrowdControlAura(Unit* excludeCasterChannel = nullptr) const;

        bool HasStealthAura()      const { return HasAuraType(SPELL_AURA_MOD_STEALTH); }
        bool HasInvisibilityAura() const { return HasAuraType(SPELL_AURA_MOD_INVISIBILITY); }
        bool IsFeared()  const { return HasAuraType(SPELL_AURA_MOD_FEAR); }
        bool HasRootAura() const { return HasAuraType(SPELL_AURA_MOD_ROOT) || HasAuraType(SPELL_AURA_MOD_ROOT_2) || HasAuraType(SPELL_AURA_MOD_ROOT_DISABLE_GRAVITY); }
        bool IsPolymorphed() const;
        bool IsFrozen() const { return HasAuraState(AURA_STATE_FROZEN); }

        bool isTargetableForAttack(bool checkFakeDeath = true) const;

        bool IsInWater() const;
        bool IsUnderWater() const;
        bool IsOnOceanFloor() const;
        bool isInAccessiblePlaceFor(Creature const* c) const;

        void SendHealSpellLog(HealInfo& healInfo, bool critical = false);
        int32 HealBySpell(HealInfo& healInfo, bool critical = false);
        void SendEnergizeSpellLog(Unit* victim, uint32 spellId, int32 damage, int32 overEnergize, Powers powerType);
        void EnergizeBySpell(Unit* victim, SpellInfo const* spellInfo, int32 damage, Powers powerType);

        Aura* AddAura(uint32 spellId, Unit* target);
        Aura* AddAura(SpellInfo const* spellInfo, uint32 effMask, Unit* target);
        void SetAuraStack(uint32 spellId, Unit* target, uint32 stack);

        void SendPlaySpellVisual(Unit* target, uint32 spellVisualId, uint16 missReason, uint16 reflectStatus, float travelSpeed, bool speedAsTime = false, float launchDelay = 0.0f);
        void SendPlaySpellVisual(Position const& targetPosition, uint32 spellVisualId, uint16 missReason, uint16 reflectStatus, float travelSpeed, bool speedAsTime = false, float launchDelay = 0.0f);
        void SendCancelSpellVisual(uint32 id);

        void SendPlaySpellVisualKit(uint32 id, uint32 type, uint32 duration) const;
        void SendCancelSpellVisualKit(uint32 id);

        void CancelSpellMissiles(uint32 spellId, bool reverseMissile = false, bool abortSpell = false);

        void DeMorph();

        void SendAttackStateUpdate(CalcDamageInfo* damageInfo);
        void SendAttackStateUpdate(uint32 HitInfo, Unit* target, uint8 SwingType, SpellSchoolMask damageSchoolMask, uint32 Damage, uint32 AbsorbDamage, uint32 Resist, VictimState TargetState, uint32 BlockedAmount);
        void SendSpellNonMeleeDamageLog(SpellNonMeleeDamage const* log);
        void SendPeriodicAuraLog(SpellPeriodicAuraLogInfo* pInfo);
        void SendSpellDamageResist(Unit* target, uint32 spellId);
        void SendSpellDamageImmune(Unit* target, uint32 spellId, bool isPeriodic);

        void NearTeleportTo(Position const& pos, bool casting = false);
        void NearTeleportTo(float x, float y, float z, float orientation, bool casting = false) { NearTeleportTo(Position(x, y, z, orientation), casting); }
        void SendTeleportPacket(Position const& pos);
        virtual bool UpdatePosition(float x, float y, float z, float ang, bool teleport = false);
        // returns true if unit's position really changed
        virtual bool UpdatePosition(Position const& pos, bool teleport = false);
        void UpdateOrientation(float orientation);
        void UpdateHeight(float newZ);

        void SendMoveKnockBack(Player* player, float speedXY, float speedZ, float vcos, float vsin);
        void KnockbackFrom(Position const& origin, float speedXY, float speedZ, Movement::SpellEffectExtraData const* spellEffectExtraData = nullptr);
        void JumpTo(float speedXY, float speedZ, float angle, Optional<Position> dest = {});
        void JumpTo(WorldObject* obj, float speedZ, bool withOrientation = false);

        void MonsterMoveWithSpeed(float x, float y, float z, float speed, bool generatePath = false, bool forceDestination = false);

        bool IsPlayingHoverAnim() const { return _playHoverAnim; }
        void SetPlayHoverAnim(bool enable, bool sendUpdate = true);
        void CalculateHoverHeight();
        void SetHoverHeight(float hoverHeight) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::HoverHeight), hoverHeight); }

        bool IsGravityDisabled() const { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_DISABLE_GRAVITY); }
        bool IsWalking() const { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_WALKING); }
        bool IsHovering() const { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_HOVER); }
        bool SetWalk(bool enable);
        bool SetDisableGravity(bool disable, bool updateAnimTier = true);
        bool SetFall(bool enable);
        bool SetSwim(bool enable);
        bool SetCanFly(bool enable);
        bool SetWaterWalking(bool enable);
        bool SetFeatherFall(bool enable);
        bool SetHover(bool enable, bool updateAnimTier = true);
        bool SetCollision(bool disable);
        bool SetCanTransitionBetweenSwimAndFly(bool enable);
        bool SetCanTurnWhileFalling(bool enable);
        bool SetCanDoubleJump(bool enable);
        bool SetDisableInertia(bool disable);
        void SendSetVehicleRecId(uint32 vehicleId);

        MovementForces const* GetMovementForces() const { return _movementForces.get(); }
        void ApplyMovementForce(ObjectGuid id, Position origin, float magnitude, MovementForceType type, Position direction = {}, ObjectGuid transportGuid = ObjectGuid::Empty);
        void RemoveMovementForce(ObjectGuid id);
        bool SetIgnoreMovementForces(bool ignore);
        void UpdateMovementForcesModMagnitude();

        void SetInFront(WorldObject const* target);
        void SetFacingTo(float const ori, bool force = true);
        void SetFacingToObject(WorldObject const* object, bool force = true);
        void SetFacingToPoint(Position const& point, bool force = true);

        bool IsAlive() const { return (m_deathState == ALIVE); }
        bool isDying() const { return (m_deathState == JUST_DIED); }
        bool isDead() const { return (m_deathState == DEAD || m_deathState == CORPSE); }
        DeathState getDeathState() const { return m_deathState; }
        virtual void setDeathState(DeathState s);           // overwrited in Creature/Player/Pet

        ObjectGuid GetOwnerGUID() const override { return m_unitData->SummonedBy; }
        void SetOwnerGUID(ObjectGuid owner);
        ObjectGuid GetCreatorGUID() const override { return m_unitData->CreatedBy; }
        void SetCreatorGUID(ObjectGuid creator) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::CreatedBy), creator); }
        ObjectGuid GetMinionGUID() const { return m_unitData->Summon; }
        void SetMinionGUID(ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Summon), guid); }
        ObjectGuid GetPetGUID() const { return m_SummonSlot[SUMMON_SLOT_PET]; }
        void SetPetGUID(ObjectGuid guid) { m_SummonSlot[SUMMON_SLOT_PET] = guid; }
        ObjectGuid GetCritterGUID() const { return m_unitData->Critter; }
        void SetCritterGUID(ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Critter), guid); }
        ObjectGuid GetBattlePetCompanionGUID() const { return m_unitData->BattlePetCompanionGUID; }
        void SetBattlePetCompanionGUID(ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::BattlePetCompanionGUID), guid); }
        ObjectGuid GetDemonCreatorGUID() const { return m_unitData->DemonCreator; }
        void SetDemonCreatorGUID(ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::DemonCreator), guid); }
        Unit* GetDemonCreator() const;
        Player* GetDemonCreatorPlayer() const;

        ObjectGuid GetCharmerGUID() const { return m_unitData->CharmedBy; }
        Unit* GetCharmer() const { return m_charmer; }

        ObjectGuid GetCharmedGUID() const { return m_unitData->Charm; }
        Unit* GetCharmed() const { return m_charmed; }

        bool IsControlledByPlayer() const { return m_ControlledByPlayer; }
        Player* GetControllingPlayer() const;
        ObjectGuid GetCharmerOrOwnerGUID() const override { return IsCharmed() ? GetCharmerGUID() : GetOwnerGUID(); }
        bool IsCharmedOwnedByPlayerOrPlayer() const { return GetCharmerOrOwnerOrOwnGUID().IsPlayer(); }

        Guardian* GetGuardianPet() const;
        Minion* GetFirstMinion() const;
        Unit* GetCharmerOrOwner() const { return IsCharmed() ? GetCharmer() : GetOwner(); }

        void SetMinion(Minion *minion, bool apply);
        void GetAllMinionsByEntry(std::list<TempSummon*>& Minions, uint32 entry);
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

        CharmInfo* GetCharmInfo() { return m_charmInfo.get(); }
        CharmInfo* InitCharmInfo();
        void DeleteCharmInfo();
        void SetPetNumberForClient(uint32 petNumber) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::PetNumber), petNumber); }
        void SetPetNameTimestamp(uint32 timestamp) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::PetNameTimestamp), timestamp); }

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

        uint32 GetBattlePetCompanionNameTimestamp() const { return m_unitData->BattlePetCompanionNameTimestamp; }
        void SetBattlePetCompanionNameTimestamp(uint32 timestamp) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::BattlePetCompanionNameTimestamp), timestamp); }
        uint32 GetBattlePetCompanionExperience() const { return m_unitData->BattlePetCompanionExperience; }
        void SetBattlePetCompanionExperience(uint32 experience) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::BattlePetCompanionExperience), experience); }
        uint32 GetWildBattlePetLevel() const { return m_unitData->WildBattlePetLevel; }
        void SetWildBattlePetLevel(uint32 wildBattlePetLevel) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::WildBattlePetLevel), wildBattlePetLevel); }

        // aura apply/remove helpers - you should better not use these
        Aura* _TryStackingOrRefreshingExistingAura(AuraCreateInfo& createInfo);
        void _AddAura(UnitAura* aura, Unit* caster);
        AuraApplication* _CreateAuraApplication(Aura* aura, uint32 effMask);
        void _ApplyAuraEffect(Aura* aura, uint8 effIndex);
        void _ApplyAura(AuraApplication* aurApp, uint32 effMask);
        void _UnapplyAura(AuraApplicationMap::iterator& i, AuraRemoveMode removeMode);
        void _UnapplyAura(AuraApplication* aurApp, AuraRemoveMode removeMode);
        void _RemoveNoStackAurasDueToAura(Aura* aura, bool owned);
        void _RegisterAuraEffect(AuraEffect* aurEff, bool apply);

        // m_ownedAuras container management
        AuraMap      & GetOwnedAuras()       { return m_ownedAuras; }
        AuraMap const& GetOwnedAuras() const { return m_ownedAuras; }

        void RemoveOwnedAura(AuraMap::iterator& i, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveOwnedAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveOwnedAura(Aura* aura, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);

        Aura* GetOwnedAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0, Aura* except = nullptr) const;

        // m_appliedAuras container management
        AuraApplicationMap      & GetAppliedAuras()       { return m_appliedAuras; }
        AuraApplicationMap const& GetAppliedAuras() const { return m_appliedAuras; }

        void RemoveAura(AuraApplicationMap::iterator &i, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAura(AuraApplication * aurApp, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAura(Aura* aur, AuraRemoveMode mode = AURA_REMOVE_BY_DEFAULT);

        // Convenience methods removing auras by predicate
        void RemoveAppliedAuras(std::function<bool(AuraApplication const*)> const& check, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveOwnedAuras(std::function<bool(Aura const*)> const& check, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);

        // Optimized overloads taking advantage of map key
        void RemoveAppliedAuras(uint32 spellId, std::function<bool(AuraApplication const*)> const& check, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveOwnedAuras(uint32 spellId, std::function<bool(Aura const*)> const& check, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);

        void RemoveAurasByType(AuraType auraType, std::function<bool(AuraApplication const*)> const& check, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);

        void RemoveAurasDueToSpell(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT);
        void RemoveAuraFromStack(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT, uint16 num = 1);
        void RemoveAurasDueToSpellByDispel(uint32 spellId, uint32 dispellerSpellId, ObjectGuid casterGUID, WorldObject* dispeller, uint8 chargesRemoved = 1);
        void RemoveAurasDueToSpellBySteal(uint32 spellId, ObjectGuid casterGUID, WorldObject* stealer, int32 stolenCharges = 1);
        void RemoveAurasDueToItemSpell(uint32 spellId, ObjectGuid castItemGuid);
        void RemoveAurasByType(AuraType auraType, ObjectGuid casterGUID = ObjectGuid::Empty, Aura* except = nullptr, bool negative = true, bool positive = true);
        void RemoveNotOwnSingleTargetAuras(bool onPhaseChange = false);
        template <typename InterruptFlags>
        void RemoveAurasWithInterruptFlags(InterruptFlags flag, SpellInfo const* source = nullptr);
        void RemoveAurasWithAttribute(uint32 flags);
        void RemoveAurasWithFamily(SpellFamilyNames family, flag128 const& familyFlag, ObjectGuid casterGUID);
        void RemoveAurasWithMechanic(uint64 mechanicMaskToRemove, AuraRemoveMode removeMode = AURA_REMOVE_BY_DEFAULT, uint32 exceptSpellId = 0, bool withEffectMechanics = false);
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
        AuraEffectList& GetAuraEffectsByType(AuraType type) { return m_modAuras[type]; }
        AuraList      & GetSingleCastAuras()       { return m_scAuras; }
        AuraList const& GetSingleCastAuras() const { return m_scAuras; }

        AuraEffect* GetAuraEffect(uint32 spellId, uint8 effIndex, ObjectGuid casterGUID = ObjectGuid::Empty) const;
        AuraEffect* GetAuraEffectOfRankedSpell(uint32 spellId, uint8 effIndex, ObjectGuid casterGUID = ObjectGuid::Empty) const;
        AuraEffect* GetAuraEffect(AuraType type, SpellFamilyNames family, flag128 const& familyFlag, ObjectGuid casterGUID = ObjectGuid::Empty) const;

        AuraApplication* GetAuraApplication(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0, AuraApplication* except = nullptr) const;
        AuraApplication* GetAuraApplication(uint32 spellId, std::function<bool(AuraApplication const*)> const& predicate) const;
        AuraApplication* GetAuraApplication(uint32 spellId, std::function<bool(Aura const*)> const& predicate) const;
        AuraApplication* GetAuraApplication(std::function<bool(AuraApplication const*)> const& predicate) const;
        AuraApplication* GetAuraApplication(std::function<bool(Aura const*)> const& predicate) const;

        Aura* GetAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0) const;
        Aura* GetAura(uint32 spellId, std::function<bool(Aura const*)> const& predicate) const;
        Aura* GetAura(std::function<bool(Aura const*)> const& predicate) const;

        AuraApplication* GetAuraApplicationOfRankedSpell(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0, AuraApplication* except = nullptr) const;
        Aura* GetAuraOfRankedSpell(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0) const;

        void GetDispellableAuraList(WorldObject const* caster, uint32 dispelMask, DispelChargesList& dispelList, bool isReflect = false) const;

        bool HasAuraEffect(uint32 spellId, uint8 effIndex, ObjectGuid caster = ObjectGuid::Empty) const;
        uint32 GetAuraCount(uint32 spellId) const;
        bool HasAura(uint32 spellId, ObjectGuid casterGUID = ObjectGuid::Empty, ObjectGuid itemCasterGUID = ObjectGuid::Empty, uint32 reqEffMask = 0) const;
        bool HasAura(std::function<bool(Aura const*)> const& predicate) const;
        bool HasAuraType(AuraType auraType) const;
        bool HasAuraTypeWithCaster(AuraType auraType, ObjectGuid caster) const;
        bool HasAuraTypeWithMiscvalue(AuraType auraType, int32 miscValue) const;
        bool HasAuraTypeWithAffectMask(AuraType auraType, SpellInfo const* affectedSpell) const;
        bool HasAuraTypeWithValue(AuraType auraType, int32 value) const;
        bool HasAuraTypeWithTriggerSpell(AuraType auratype, uint32 triggerSpell) const;
        template <typename InterruptFlags>
        bool HasNegativeAuraWithInterruptFlag(InterruptFlags flag, ObjectGuid guid = ObjectGuid::Empty) const;
        bool HasAuraWithMechanic(uint64 mechanicMask) const;
        bool HasStrongerAuraWithDR(SpellInfo const* auraSpellInfo, Unit* caster) const;

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

        void InitStatBuffMods();
        void UpdateStatBuffMod(Stats stat);
        void UpdateStatBuffModForClient(Stats stat);
        void SetCreateStat(Stats stat, float val) { m_createStats[stat] = val; }
        void SetCreateHealth(uint32 val) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::BaseHealth), val); }
        uint32 GetCreateHealth() const { return m_unitData->BaseHealth; }
        void SetCreateMana(uint32 val) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::BaseMana), val); }
        uint32 GetCreateMana() const { return m_unitData->BaseMana; }
        virtual int32 GetCreatePowerValue(Powers power) const;
        float GetPosStat(Stats stat) const { return m_unitData->StatPosBuff[stat]; }
        float GetNegStat(Stats stat) const { return m_unitData->StatNegBuff[stat]; }
        float GetCreateStat(Stats stat) const { return m_createStats[stat]; }

        uint32 GetChannelSpellId() const { return m_unitData->ChannelData->SpellID; }
        void SetChannelSpellId(uint32 channelSpellId)
        {
            SetUpdateFieldValue(m_values
                .ModifyValue(&Unit::m_unitData)
                .ModifyValue(&UF::UnitData::ChannelData)
                .ModifyValue(&UF::UnitChannel::SpellID), channelSpellId);
        }
        uint32 GetChannelSpellXSpellVisualId() const { return m_unitData->ChannelData->SpellVisual.SpellXSpellVisualID; }
        uint32 GetChannelScriptVisualId() const { return m_unitData->ChannelData->SpellVisual.ScriptVisualID; }
        void SetChannelVisual(SpellCastVisual channelVisual)
        {
            SetUpdateFieldValue(m_values
                .ModifyValue(&Unit::m_unitData)
                .ModifyValue(&UF::UnitData::ChannelData)
                .ModifyValue(&UF::UnitChannel::SpellVisual), channelVisual);
        }
        void AddChannelObject(ObjectGuid guid) { AddDynamicUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ChannelObjects)) = guid; }
        void SetChannelObject(uint32 slot, ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ChannelObjects, slot), guid); }
        void RemoveChannelObject(ObjectGuid guid)
        {
            int32 index = m_unitData->ChannelObjects.FindIndex(guid);
            if (index >= 0)
                RemoveDynamicUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ChannelObjects), index);
        }
        void ClearChannelObjects() { ClearDynamicUpdateFieldValues(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::ChannelObjects)); }

        void SetCurrentCastSpell(Spell* pSpell);
        void InterruptSpell(CurrentSpellTypes spellType, bool withDelayed = true, bool withInstant = true);
        void FinishSpell(CurrentSpellTypes spellType, SpellCastResult result = SPELL_CAST_OK);

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
        virtual SpellInfo const* GetCastSpellInfo(SpellInfo const* spellInfo, TriggerCastFlags& triggerFlag) const;
        uint32 GetCastSpellXSpellVisualId(SpellInfo const* spellInfo) const override;

        virtual bool HasSpellFocus(Spell const* /*focusSpell*/ = nullptr) const { return false; }
        virtual bool IsMovementPreventedByCasting() const;
        bool CanCastSpellWhileMoving(SpellInfo const* spellInfo) const;

        bool IsSilenced(SpellSchoolMask schoolMask) const { return (*m_unitData->SilencedSchoolMask & schoolMask) != 0; }
        void SetSilencedSchoolMask(SpellSchoolMask schoolMask) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::SilencedSchoolMask), schoolMask); }
        void ReplaceAllSilencedSchoolMask(SpellSchoolMask schoolMask) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::SilencedSchoolMask), schoolMask); }

        SpellHistory* GetSpellHistory() { return _spellHistory.get(); }
        SpellHistory const* GetSpellHistory() const { return _spellHistory.get(); }

        std::array<ObjectGuid, MAX_SUMMON_SLOT> m_SummonSlot;
        std::array<ObjectGuid, MAX_GAMEOBJECT_SLOT> m_ObjectSlot;

        ShapeshiftForm GetShapeshiftForm() const { return ShapeshiftForm(*m_unitData->ShapeshiftForm); }
        void SetShapeshiftForm(ShapeshiftForm form);

        bool IsInFeralForm() const;

        bool IsInDisallowedMountForm() const;
        bool IsDisallowedMountForm(uint32 spellId, ShapeshiftForm form, uint32 displayId) const;

        float m_modMeleeHitChance;
        float m_modRangedHitChance;
        float m_modSpellHitChance;
        float m_baseSpellCritChance;

        std::array<uint32, MAX_ATTACK> m_baseAttackSpeed;
        std::array<float, MAX_ATTACK> m_modAttackSpeedPct;
        std::array<uint32, MAX_ATTACK> m_attackTimer;

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
        bool CanModifyStats() const { return m_canModifyStats; }
        void SetCanModifyStats(bool modifyStats) { m_canModifyStats = modifyStats; }
        virtual bool UpdateStats(Stats stat) = 0;
        virtual bool UpdateAllStats() = 0;
        virtual void UpdateResistances(uint32 school);
        virtual void UpdateAllResistances();
        virtual void UpdateArmor() = 0;
        virtual void UpdateMaxHealth() = 0;
        virtual void UpdateMaxPower(Powers power) = 0;
        virtual uint32 GetPowerIndex(Powers power) const = 0;
        virtual void UpdateAttackPowerAndDamage(bool ranged = false) = 0;
        void SetAttackPower(int32 attackPower) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::AttackPower), attackPower); }
        void SetAttackPowerModPos(int32 attackPowerMod) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::AttackPowerModPos), attackPowerMod); }
        void SetAttackPowerModNeg(int32 attackPowerMod) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::AttackPowerModNeg), attackPowerMod); }
        void SetAttackPowerMultiplier(float attackPowerMult) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::AttackPowerMultiplier), attackPowerMult); }
        void SetRangedAttackPower(int32 attackPower) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::RangedAttackPower), attackPower); }
        void SetRangedAttackPowerModPos(int32 attackPowerMod) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::RangedAttackPowerModPos), attackPowerMod); }
        void SetRangedAttackPowerModNeg(int32 attackPowerMod) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::RangedAttackPowerModNeg), attackPowerMod); }
        void SetRangedAttackPowerMultiplier(float attackPowerMult) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::RangedAttackPowerMultiplier), attackPowerMult); }
        void SetMainHandWeaponAttackPower(int32 attackPower) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::MainHandWeaponAttackPower), attackPower); }
        void SetOffHandWeaponAttackPower(int32 attackPower) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::OffHandWeaponAttackPower), attackPower); }
        void SetRangedWeaponAttackPower(int32 attackPower) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::RangedWeaponAttackPower), attackPower); }
        virtual void UpdateDamagePhysical(WeaponAttackType attType);
        float GetTotalAttackPowerValue(WeaponAttackType attType, bool includeWeapon = true) const;
        float GetWeaponDamageRange(WeaponAttackType attType, WeaponDamageRange type) const;
        void SetBaseWeaponDamage(WeaponAttackType attType, WeaponDamageRange damageRange, float value) { m_weaponDamage[attType][damageRange] = value; }
        virtual void CalculateMinMaxDamage(WeaponAttackType attType, bool normalized, bool addTotalPct, float& minDamage, float& maxDamage) const = 0;
        uint32 CalculateDamage(WeaponAttackType attType, bool normalized, bool addTotalPct) const;
        float GetAPMultiplier(WeaponAttackType attType, bool normalized) const;

        bool isInFrontInMap(Unit const* target, float distance, float arc = float(M_PI)) const;
        bool isInBackInMap(Unit const* target, float distance, float arc = float(M_PI)) const;

        // Visibility system
        bool IsVisible() const;
        void SetVisible(bool x);

        // common function for visibility checks for player/creatures with detection code
        virtual void OnPhaseChange();
        void UpdateObjectVisibility(bool forced = true) override;

        SpellImmuneContainer m_spellImmune[MAX_SPELL_IMMUNITY];
        uint32 m_lastSanctuaryTime;

        VisibleAuraContainer const& GetVisibleAuras() const { return m_visibleAuras; }
        bool HasVisibleAura(AuraApplication* aurApp) const { return m_visibleAuras.count(aurApp) > 0; }
        void SetVisibleAura(AuraApplication* aurApp);
        void SetVisibleAuraUpdate(AuraApplication* aurApp) { m_visibleAurasToUpdate.insert(aurApp); }
        void RemoveVisibleAura(AuraApplication* aurApp);

        bool HasInterruptFlag(SpellAuraInterruptFlags flags) const { return m_interruptMask.HasFlag(flags); }
        bool HasInterruptFlag(SpellAuraInterruptFlags2 flags) const { return m_interruptMask2.HasFlag(flags); }
        void AddInterruptMask(SpellAuraInterruptFlags flags, SpellAuraInterruptFlags2 flags2)
        {
            m_interruptMask |= flags;
            m_interruptMask2 |= flags2;
        }
        void UpdateInterruptMask();

        virtual float GetNativeObjectScale() const { return 1.0f; }
        virtual void RecalculateObjectScale();
        uint32 GetDisplayId() const { return m_unitData->DisplayID; }
        float GetDisplayScale() const { return m_unitData->DisplayScale; }
        virtual void SetDisplayId(uint32 displayId, bool setNative = false);
        uint32 GetNativeDisplayId() const { return m_unitData->NativeDisplayID; }
        float GetNativeDisplayScale() const { return m_unitData->NativeXDisplayScale; }
        void RestoreDisplayId(bool ignorePositiveAurasPreventingMounting = false);
        void SetTransformSpell(uint32 spellid) { m_transformSpell = spellid;}
        uint32 GetTransformSpell() const { return m_transformSpell;}

        // DynamicObject management
        void _RegisterDynObject(DynamicObject* dynObj);
        void _UnregisterDynObject(DynamicObject* dynObj);
        DynamicObject* GetDynObject(uint32 spellId) const;
        std::vector<DynamicObject*> GetDynObjects(uint32 spellId) const;
        void RemoveDynObject(uint32 spellId);
        void RemoveAllDynObjects();

        GameObject* GetGameObject(uint32 spellId) const;
        std::vector<GameObject*> GetGameObjects(uint32 spellId) const;
        void AddGameObject(GameObject* gameObj);
        void RemoveGameObject(GameObject* gameObj, bool del);
        void RemoveGameObject(uint32 spellid, bool del);
        void RemoveAllGameObjects();

        // AreaTrigger management
        void _RegisterAreaTrigger(AreaTrigger* areaTrigger);
        void _UnregisterAreaTrigger(AreaTrigger* areaTrigger);
        AreaTrigger* GetAreaTrigger(uint32 spellId) const;
        std::vector<AreaTrigger*> GetAreaTriggers(uint32 spellId) const;
        void RemoveAreaTrigger(uint32 spellId);
        void RemoveAreaTrigger(AuraEffect const* aurEff);
        void RemoveAllAreaTriggers();

        void ModifyAuraState(AuraStateType flag, bool apply);
        uint32 BuildAuraStateUpdateForTarget(Unit const* target) const;
        bool HasAuraState(AuraStateType flag, SpellInfo const* spellProto = nullptr, Unit const* Caster = nullptr) const;
        void UnsummonAllTotems();
        bool IsMagnet() const;
        Unit* GetMeleeHitRedirectTarget(Unit* victim, SpellInfo const* spellInfo = nullptr);

        int32 SpellBaseDamageBonusDone(SpellSchoolMask schoolMask) const;
        int32 SpellDamageBonusDone(Unit* victim, SpellInfo const* spellProto, int32 pdamage, DamageEffectType damagetype, SpellEffectInfo const& spellEffectInfo, uint32 stack = 1, Spell* spell = nullptr, AuraEffect const* aurEff = nullptr) const;
        float SpellDamagePctDone(Unit* victim, SpellInfo const* spellProto, DamageEffectType damagetype, SpellEffectInfo const& spellEffectInfo) const;
        int32 SpellDamageBonusTaken(Unit* caster, SpellInfo const* spellProto, int32 pdamage, DamageEffectType damagetype) const;
        int32 SpellBaseHealingBonusDone(SpellSchoolMask schoolMask) const;
        int32 SpellHealingBonusDone(Unit* victim, SpellInfo const* spellProto, int32 healamount, DamageEffectType damagetype, SpellEffectInfo const& spellEffectInfo, uint32 stack = 1, Spell* spell = nullptr, AuraEffect const* aurEff = nullptr) const;
        float SpellHealingPctDone(Unit* victim, SpellInfo const* spellProto) const;
        int32 SpellHealingBonusTaken(Unit* caster, SpellInfo const* spellProto, int32 healamount, DamageEffectType damagetype) const;

        int32 MeleeDamageBonusDone(Unit* pVictim, int32 damage, WeaponAttackType attType, DamageEffectType damagetype, SpellInfo const* spellProto = nullptr, Mechanics mechanic = MECHANIC_NONE, SpellSchoolMask damageSchoolMask = SPELL_SCHOOL_MASK_NORMAL, Spell* spell = nullptr, AuraEffect const* aurEff = nullptr);
        int32 MeleeDamageBonusTaken(Unit* attacker, int32 pdamage, WeaponAttackType attType, DamageEffectType damagetype, SpellInfo const* spellProto = nullptr, SpellSchoolMask damageSchoolMask = SPELL_SCHOOL_MASK_NORMAL);

        bool IsBlockCritical();
        float SpellCritChanceDone(Spell* spell, AuraEffect const* aurEff, SpellSchoolMask schoolMask, WeaponAttackType attackType = BASE_ATTACK) const;
        float SpellCritChanceTaken(Unit const* caster, Spell* spell, AuraEffect const* aurEff, SpellSchoolMask schoolMask, float doneChance, WeaponAttackType attackType = BASE_ATTACK) const;
        static uint32 SpellCriticalDamageBonus(Unit const* caster, SpellInfo const* spellProto, uint32 damage, Unit* victim);
        static uint32 SpellCriticalHealingBonus(Unit const* caster, SpellInfo const* spellProto, uint32 damage, Unit* victim);

        void ApplySpellImmune(uint32 spellId, SpellImmunity op, uint32 type, bool apply);
        bool IsImmunedToSpell(SpellInfo const* spellInfo, WorldObject const* caster, bool requireImmunityPurgesEffectAttribute = false) const;
        uint32 GetSchoolImmunityMask() const;
        uint32 GetDamageImmunityMask() const;
        uint64 GetMechanicImmunityMask() const;

        bool IsImmunedToDamage(SpellSchoolMask meleeSchoolMask) const;
        bool IsImmunedToDamage(SpellInfo const* spellInfo, SpellEffectInfo const* spellEffectInfo = nullptr) const;
        virtual bool IsImmunedToSpellEffect(SpellInfo const* spellInfo, SpellEffectInfo const& spellEffectInfo, WorldObject const* caster, bool requireImmunityPurgesEffectAttribute = false) const;

        static bool IsDamageReducedByArmor(SpellSchoolMask damageSchoolMask, SpellInfo const* spellInfo = nullptr);
        static uint32 CalcArmorReducedDamage(Unit const* attacker, Unit* victim, uint32 damage, SpellInfo const* spellInfo, WeaponAttackType attackType = MAX_ATTACK, uint8 attackerLevel = 0);
        static uint32 CalcSpellResistedDamage(Unit const* attacker, Unit* victim, uint32 damage, SpellSchoolMask schoolMask, SpellInfo const* spellInfo);
        static void CalcAbsorbResist(DamageInfo& damageInfo, Spell* spell = nullptr);
        static void CalcHealAbsorb(HealInfo& healInfo);

        void UpdateSpeed(UnitMoveType mtype);
        float GetSpeed(UnitMoveType mtype) const;
        float GetSpeedRate(UnitMoveType mtype) const { return m_speed_rate[mtype]; }
        void SetSpeed(UnitMoveType mtype, float newValue);
        void SetSpeedRate(UnitMoveType mtype, float rate);

        void FollowerAdded(AbstractFollower* f) { m_followingMe.insert(f); }
        void FollowerRemoved(AbstractFollower* f) { m_followingMe.erase(f); }
        void RemoveAllFollowers();

        MotionMaster* GetMotionMaster() { return i_motionMaster.get(); }
        MotionMaster const* GetMotionMaster() const { return i_motionMaster.get(); }
        virtual MovementGeneratorType GetDefaultMovementType() const;

        bool IsStopped() const { return !(HasUnitState(UNIT_STATE_MOVING)); }
        void StopMoving();
        void PauseMovement(uint32 timer = 0, uint8 slot = 0, bool forced = true); // timer in ms
        void ResumeMovement(uint32 timer = 0, uint8 slot = 0); // timer in ms

        void AddUnitMovementFlag(uint32 f) { m_movementInfo.AddMovementFlag(f); }
        void RemoveUnitMovementFlag(uint32 f) { m_movementInfo.RemoveMovementFlag(f); }
        bool HasUnitMovementFlag(uint32 f) const { return m_movementInfo.HasMovementFlag(f); }
        uint32 GetUnitMovementFlags() const { return m_movementInfo.GetMovementFlags(); }
        void SetUnitMovementFlags(uint32 f) { m_movementInfo.SetMovementFlags(f); }

        void AddExtraUnitMovementFlag(uint32 f) { m_movementInfo.AddExtraMovementFlag(f); }
        void RemoveExtraUnitMovementFlag(uint32 f) { m_movementInfo.RemoveExtraMovementFlag(f); }
        bool HasExtraUnitMovementFlag(uint32 f) const { return m_movementInfo.HasExtraMovementFlag(f); }
        uint32 GetExtraUnitMovementFlags() const { return m_movementInfo.GetExtraMovementFlags(); }
        void SetExtraUnitMovementFlags(uint32 f) { m_movementInfo.SetExtraMovementFlags(f); }

        void AddExtraUnitMovementFlag2(uint32 f) { m_movementInfo.AddExtraMovementFlag2(f); }
        void RemoveExtraUnitMovementFlag2(uint32 f) { m_movementInfo.RemoveExtraMovementFlag2(f); }
        bool HasExtraUnitMovementFlag2(uint32 f) const { return m_movementInfo.HasExtraMovementFlag2(f); }
        uint32 GetExtraUnitMovementFlags2() const { return m_movementInfo.GetExtraMovementFlags2(); }
        void SetExtraUnitMovementFlags2(uint32 f) { m_movementInfo.SetExtraMovementFlags2(f); }

        bool IsSplineEnabled() const;

        void SetControlled(bool apply, UnitState state);
        void ApplyControlStatesIfNeeded();

        ///----------Pet responses methods-----------------
        void SendPetActionFeedback(PetActionFeedback msg, uint32 spellId);
        void SendPetTalk(uint32 pettalk);
        void SendPetAIReaction(ObjectGuid guid);
        ///----------End of Pet responses methods----------

        void PropagateSpeedChange();

        // reactive attacks
        void ClearAllReactives();
        void StartReactiveTimer(ReactiveType reactive) { m_reactiveTimer[reactive] = REACTIVE_TIMER_START;}
        void UpdateReactives(uint32 p_time);

        // group updates
        void UpdateAuraForGroup();

        // proc trigger system
        bool CanProc() const { return !m_procDeep; }
        void SetCantProc(bool apply);
        int32 GetProcChainLength() const { return m_procChainLength; }

        uint32 GetModelForForm(ShapeshiftForm form, uint32 spellId) const;

        friend class VehicleJoinEvent;
        ObjectGuid LastCharmerGUID;
        bool CreateVehicleKit(uint32 id, uint32 creatureEntry, bool loading = false);
        void RemoveVehicleKit(bool onRemoveFromWorld = false);
        Vehicle* GetVehicleKit() const { return m_vehicleKit.get(); }
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
        virtual void ExitVehicle(Position const* exitPosition = nullptr);
        void ChangeSeat(int8 seatId, bool next = true);

        // Should only be called by AuraEffect::HandleAuraControlVehicle(AuraApplication const* auraApp, uint8 mode, bool apply) const;
        void _ExitVehicle(Position const* exitPosition = nullptr);
        void _EnterVehicle(Vehicle* vehicle, int8 seatId, AuraApplication const* aurApp = nullptr);

        bool isMoving() const   { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_MASK_MOVING); }
        bool isTurning() const  { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_MASK_TURNING); }
        virtual bool CanFly() const = 0;
        bool IsFlying() const   { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_FLYING | MOVEMENTFLAG_DISABLE_GRAVITY); }
        bool IsFalling() const;
        virtual bool CanEnterWater() const = 0;
        virtual bool CanSwim() const;

        float GetHoverOffset() const
        {
            return HasUnitMovementFlag(MOVEMENTFLAG_HOVER) ? *m_unitData->HoverHeight : 0.0f;
        }

        void RewardRage(uint32 baseRage);

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

        ObjectGuid GetTarget() const { return m_unitData->Target; }
        virtual void SetTarget(ObjectGuid const& /*guid*/) = 0;

        void SetInstantCast(bool set) { _instantCast = set; }
        bool CanInstantCast() const { return _instantCast; }

        // Movement info
        std::unique_ptr<Movement::MoveSpline> movespline;

        int32 GetHighestExclusiveSameEffectSpellGroupValue(AuraEffect const* aurEff, AuraType auraType, bool checkMiscValue = false, int32 miscValue = 0) const;
        bool IsHighestExclusiveAura(Aura const* aura, bool removeOtherAuraApplications = false);
        bool IsHighestExclusiveAuraEffect(SpellInfo const* spellInfo, AuraType auraType, int32 effectAmount, uint32 auraEffectMask, bool removeOtherAuraApplications = false);

        virtual void Talk(std::string_view text, ChatMsg msgType, Language language, float textRange, WorldObject const* target);
        virtual void Say(std::string_view text, Language language, WorldObject const* target = nullptr);
        virtual void Yell(std::string_view text, Language language, WorldObject const* target = nullptr);
        virtual void TextEmote(std::string_view text, WorldObject const* target = nullptr, bool isBossEmote = false);
        virtual void Whisper(std::string_view text, Language language, Player* target, bool isBossWhisper = false);
        virtual void Talk(uint32 textId, ChatMsg msgType, float textRange, WorldObject const* target);
        virtual void Say(uint32 textId, WorldObject const* target = nullptr);
        virtual void Yell(uint32 textId, WorldObject const* target = nullptr);
        virtual void TextEmote(uint32 textId, WorldObject const* target = nullptr, bool isBossEmote = false);
        virtual void Whisper(uint32 textId, Player* target, bool isBossWhisper = false);

        float GetCollisionHeight() const override;
        uint32 GetVirtualItemId(uint32 slot) const;
        uint16 GetVirtualItemAppearanceMod(uint32 slot) const;
        void SetVirtualItem(uint32 slot, uint32 itemId, uint16 appearanceModId = 0, uint16 itemVisual = 0);

        // returns if the unit can't enter combat
        bool IsCombatDisallowed() const { return _isCombatDisallowed; }
        // enables / disables combat interaction of this unit
        void SetIsCombatDisallowed(bool apply) { _isCombatDisallowed = apply; }

        void AddWorldEffect(int32 worldEffectId) { AddDynamicUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::WorldEffects)) = worldEffectId; }
        void RemoveWorldEffect(int32 worldEffectId)
        {
            int32 index = m_unitData->WorldEffects.FindIndex(worldEffectId);
            if (index >= 0)
                RemoveDynamicUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::WorldEffects), index);
        }
        void ClearWorldEffects() { ClearDynamicUpdateFieldValues(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::WorldEffects)); }

        std::string GetDebugInfo() const override;

        UF::UpdateField<UF::UnitData, 0, TYPEID_UNIT> m_unitData;

    protected:
        explicit Unit (bool isWorldObject);

        UF::UpdateFieldFlag GetUpdateFieldFlagsFor(Player const* target) const override;
        void BuildValuesCreate(ByteBuffer* data, Player const* target) const override;
        void BuildValuesUpdate(ByteBuffer* data, Player const* target) const override;

    public:
        void BuildValuesUpdateWithFlag(ByteBuffer* data, UF::UpdateFieldFlag flags, Player const* target) const override;
        void BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask,
            UF::UnitData::Mask const& requestedUnitMask, Player const* target) const;

        struct ValuesUpdateForPlayerWithMaskSender // sender compatible with MessageDistDeliverer
        {
            explicit ValuesUpdateForPlayerWithMaskSender(Unit const* owner) : Owner(owner) { }

            Unit const* Owner;
            UF::ObjectData::Base ObjectMask;
            UF::UnitData::Base UnitMask;

            void operator()(Player const* player) const;
        };

    protected:
        void DestroyForPlayer(Player* target) const override;
        void ClearUpdateMask(bool remove) override;

        void _UpdateSpells(uint32 time);
        void _DeleteRemovedAuras();

        void _UpdateAutoRepeatSpell();

        bool m_ControlledByPlayer;

        std::array<float, MAX_STATS> m_createStats;
        std::array<float, MAX_STATS> m_floatStatPosBuff;
        std::array<float, MAX_STATS> m_floatStatNegBuff;

        AttackerSet m_attackers;
        Unit* m_attacking;

        DeathState m_deathState;

        int32 m_procDeep;               // tracked for proc system correctness (what spells should proc what)
        int32 m_procChainLength;        // tracked to protect against infinite proc loops (hard limit, will disallow procs even if they should happen)

        typedef std::vector<DynamicObject*> DynObjectList;
        DynObjectList m_dynObj;

        typedef std::list<GameObject*> GameObjectList;
        GameObjectList m_gameObj;

        typedef std::vector<AreaTrigger*> AreaTriggerList;
        AreaTriggerList m_areaTrigger;

        uint32 m_transformSpell;

        std::array<Spell*, CURRENT_MAX_SPELL> m_currentSpells;

        AuraMap m_ownedAuras;
        AuraApplicationMap m_appliedAuras;
        AuraList m_removedAuras;
        AuraMap::iterator m_auraUpdateIterator;
        uint32 m_removedAurasCount;

        std::array<AuraEffectList, TOTAL_AURAS> m_modAuras;
        AuraList m_scAuras;                        // cast singlecast auras
        AuraApplicationList m_interruptableAuras;  // auras which have interrupt mask applied on unit
        AuraStateAurasMap m_auraStateAuras;        // Used for improve performance of aura state checks on aura apply/remove
        EnumFlag<SpellAuraInterruptFlags> m_interruptMask;
        EnumFlag<SpellAuraInterruptFlags2> m_interruptMask2;

        float m_auraFlatModifiersGroup[UNIT_MOD_END][MODIFIER_TYPE_FLAT_END];
        float m_auraPctModifiersGroup[UNIT_MOD_END][MODIFIER_TYPE_PCT_END];
        float m_weaponDamage[MAX_ATTACK][2];
        bool m_canModifyStats;

        VisibleAuraContainer m_visibleAuras;
        Trinity::Containers::FlatSet<AuraApplication*, VisibleAuraSlotCompare> m_visibleAurasToUpdate;

        std::array<float, MAX_MOVE_TYPE> m_speed_rate;

        Unit* m_unitMovedByMe;    // only ever set for players, and only for direct client control
        Player* m_playerMovingMe; // only set for direct client control (possess effects, vehicles and similar)
        Unit* m_charmer; // Unit that is charming ME
        Unit* m_charmed; // Unit that is being charmed BY ME
        std::unique_ptr<CharmInfo> m_charmInfo;
        SharedVisionList m_sharedVision;

        std::unique_ptr<MotionMaster> i_motionMaster;

        std::array<uint32, MAX_REACTIVE> m_reactiveTimer;
        uint32 m_regenTimer;

        Vehicle* m_vehicle;
        std::unique_ptr<Vehicle> m_vehicleKit;

        uint32 m_unitTypeMask;
        LiquidTypeEntry const* _lastLiquid;

        bool IsAlwaysVisibleFor(WorldObject const* seer) const override;
        bool IsAlwaysDetectableFor(WorldObject const* seer) const override;

        void DisableSpline();

        void ProcessPositionDataChanged(PositionFullTerrainStatus const& data) override;
        virtual void ProcessTerrainStatusUpdate(ZLiquidStatus oldLiquidStatus, Optional<LiquidData> const& newLiquidData);

        // notifiers
        virtual void AtEnterCombat();
        virtual void AtExitCombat();

        virtual void AtEngage(Unit* /*target*/) {}
        virtual void AtDisengage() {}

    public:
        void AtStartOfEncounter(EncounterType type);
        void AtEndOfEncounter(EncounterType type);

    private:

        void UpdateSplineMovement(uint32 t_diff);
        void UpdateSplinePosition();
        void InterruptMovementBasedAuras();

        // player or player's pet
        float GetCombatRatingReduction(CombatRating cr) const;
        uint32 GetCombatRatingDamageReduction(CombatRating cr, float rate, float cap, uint32 damage) const;

        void ProcSkillsAndReactives(bool isVictim, Unit* procTarget, ProcFlagsInit const& typeMask, ProcFlagsHit hitMask, WeaponAttackType attType);

    protected:
        void SetFeared(bool apply);
        void SetConfused(bool apply);
        void SetStunned(bool apply);
        void SetRooted(bool apply, bool packetOnly = false);

        uint32 m_movementCounter;       ///< Incrementing counter used in movement packets

    private:

        uint32 m_state;                                     // Even derived shouldn't modify
        TimeTracker m_splineSyncTimer;

        Diminishing m_Diminishing;

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

        uint32 _lastExtraAttackSpell;
        std::unordered_map<ObjectGuid /*guid*/, uint32 /*count*/> extraAttacksTargets;
        ObjectGuid _lastDamagedTargetGuid;

        bool m_cleanupDone; // lock made to not add stuff after cleanup before delete
        bool m_duringRemoveFromWorld; // lock made to not add stuff after begining removing from world
        bool _instantCast;

        uint32 _oldFactionId;           ///< faction before charm
        bool _isWalkingBeforeCharm;     ///< Are we walking before we were charmed?

        bool _playHoverAnim;

        uint16 _aiAnimKitId;
        uint16 _movementAnimKitId;
        uint16 _meleeAnimKitId;

        std::unique_ptr<SpellHistory> _spellHistory;

        std::unique_ptr<MovementForces> _movementForces;
        PositionUpdateInfo _positionUpdateInfo;

        bool _isCombatDisallowed;
};

#endif
