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

#ifndef TRINITY_SPELLDEFINES_H
#define TRINITY_SPELLDEFINES_H

#include "Define.h"
#include "FlagsArray.h"
#include "EnumFlag.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Position.h"
#include "ScriptActionResult.h"
#include <any>
#include <vector>

class AuraEffect;
class Corpse;
class GameObject;
class Item;
class Player;
class Spell;
class Unit;
class WorldObject;
enum Difficulty : uint8;
enum ProcFlags : uint32;
enum ProcFlags2 : int32;
enum SpellCastResult : int32;

namespace UF
{
    struct SpellCastVisual;
}

namespace WorldPackets
{
    namespace Spells
    {
        struct SpellCastRequest;
        struct SpellCastVisual;
        struct SpellTargetData;
    }
}

enum class SpellInterruptFlags : uint32
{
    None                        = 0,
    Movement                    = 0x00000001,
    DamagePushbackPlayerOnly    = 0x00000002,
    Stun                        = 0x00000004, // useless, even spells without it get interrupted
    Combat                      = 0x00000008,
    DamageCancelsPlayerOnly     = 0x00000010,
    MeleeCombat                 = 0x00000020, // NYI
    Immunity                    = 0x00000040, // NYI
    DamageAbsorb                = 0x00000080,
    ZeroDamageCancels           = 0x00000100,
    DamagePushback              = 0x00000200,
    DamageCancels               = 0x00000400
};

DEFINE_ENUM_FLAG(SpellInterruptFlags);

enum class SpellAuraInterruptFlags : uint32
{
    None                        = 0,
    HostileActionReceived       = 0x00000001,
    Damage                      = 0x00000002,
    Action                      = 0x00000004,
    Moving                      = 0x00000008,
    Turning                     = 0x00000010,
    Anim                        = 0x00000020,
    Dismount                    = 0x00000040,
    UnderWater                  = 0x00000080, // TODO: disallow casting when swimming (SPELL_FAILED_ONLY_ABOVEWATER)
    AboveWater                  = 0x00000100, // TODO: disallow casting when not swimming (SPELL_FAILED_ONLY_UNDERWATER)
    Sheathing                   = 0x00000200,
    Interacting                 = 0x00000400, // TODO: more than gossip, replace all the feign death removals by aura type
    Looting                     = 0x00000800,
    Attacking                   = 0x00001000,
    ItemUse                     = 0x00002000,
    DamageChannelDuration       = 0x00004000,
    Shapeshifting               = 0x00008000,
    ActionDelayed               = 0x00010000,
    Mount                       = 0x00020000,
    Standing                    = 0x00040000,
    LeaveWorld                  = 0x00080000,
    StealthOrInvis              = 0x00100000,
    InvulnerabilityBuff         = 0x00200000,
    EnterWorld                  = 0x00400000,
    PvPActive                   = 0x00800000,
    NonPeriodicDamage           = 0x01000000,
    LandingOrFlight             = 0x02000000,
    Release                     = 0x04000000,
    DamageCancelsScript         = 0x08000000, // NYI dedicated aura script hook
    EnteringCombat              = 0x10000000,
    Login                       = 0x20000000,
    Summon                      = 0x40000000,
    LeavingCombat               = 0x80000000,

    NOT_VICTIM                  = (HostileActionReceived | Damage | NonPeriodicDamage)
};

DEFINE_ENUM_FLAG(SpellAuraInterruptFlags);

enum class SpellAuraInterruptFlags2 : uint32
{
    None                                        = 0,
    Falling                                     = 0x00000001, // Implemented in Unit::UpdatePosition
    Swimming                                    = 0x00000002,
    NotMoving                                   = 0x00000004, // NYI
    Ground                                      = 0x00000008,
    Transform                                   = 0x00000010, // NYI
    Jump                                        = 0x00000020,
    ChangeSpec                                  = 0x00000040,
    AbandonVehicle                              = 0x00000080, // Implemented in Unit::_ExitVehicle
    StartOfRaidEncounterAndStartOfMythicPlus    = 0x00000100, // Implemented in Unit::AtStartOfEncounter
    EndOfRaidEncounterAndStartOfMythicPlus      = 0x00000200, // Implemented in Unit::AtEndOfEncounter
    Disconnect                                  = 0x00000400, // NYI
    EnteringInstance                            = 0x00000800, // Implemented in Map::AddPlayerToMap
    DuelEnd                                     = 0x00001000, // Implemented in Player::DuelComplete
    LeaveArenaOrBattleground                    = 0x00002000, // Implemented in Battleground::RemovePlayerAtLeave
    ChangeTalent                                = 0x00004000,
    ChangeGlyph                                 = 0x00008000,
    SeamlessTransfer                            = 0x00010000, // NYI
    WarModeLeave                                = 0x00020000, // Implemented in Player::UpdateWarModeAuras
    TouchingGround                              = 0x00040000, // NYI
    ChromieTime                                 = 0x00080000, // NYI
    SplineFlightOrFreeFlight                    = 0x00100000, // NYI
    ProcOrPeriodicAttacking                     = 0x00200000, // NYI
    ChallengeModeStart                          = 0x00400000, // Implemented in Unit::AtStartOfEncounter
    StartOfEncounter                            = 0x00800000, // Implemented in Unit::AtStartOfEncounter
    EndOfEncounter                              = 0x01000000, // Implemented in Unit::AtEndOfEncounter
};

DEFINE_ENUM_FLAG(SpellAuraInterruptFlags2);

enum class SpellModOp : uint8
{
    HealingAndDamage            = 0,
    Duration                    = 1,
    Hate                        = 2,
    PointsIndex0                = 3,
    ProcCharges                 = 4,
    Range                       = 5,
    Radius                      = 6,
    CritChance                  = 7,
    Points                      = 8,
    ResistPushback              = 9,
    ChangeCastTime              = 10,
    Cooldown                    = 11,
    PointsIndex1                = 12,
    TargetResistance            = 13,
    PowerCost0                  = 14, // Used when SpellPowerEntry::PowerIndex == 0
    CritDamageAndHealing        = 15,
    HitChance                   = 16,
    ChainTargets                = 17,
    ProcChance                  = 18,
    Period                      = 19,
    ChainAmplitude              = 20,
    StartCooldown               = 21,
    PeriodicHealingAndDamage    = 22,
    PointsIndex2                = 23,
    BonusCoefficient            = 24,
    TriggerDamage               = 25, // NYI
    ProcFrequency               = 26,
    Amplitude                   = 27,
    DispelResistance            = 28,
    CrowdDamage                 = 29, // NYI
    PowerCostOnMiss             = 30,
    Doses                       = 31,
    PointsIndex3                = 32,
    PointsIndex4                = 33,
    PowerCost1                  = 34, // Used when SpellPowerEntry::PowerIndex == 1
    ChainJumpDistance           = 35,
    AreaTriggerMaxSummons       = 36, // NYI
    MaxAuraStacks               = 37,
    ProcCooldown                = 38,
    PowerCost2                  = 39, // Used when SpellPowerEntry::PowerIndex == 2
};

#define MAX_SPELLMOD 40

enum SpellValueMod : uint8
{
    SPELLVALUE_BASE_POINT0,
    SPELLVALUE_BASE_POINT1,
    SPELLVALUE_BASE_POINT2,
    SPELLVALUE_BASE_POINT3,
    SPELLVALUE_BASE_POINT4,
    SPELLVALUE_BASE_POINT5,
    SPELLVALUE_BASE_POINT6,
    SPELLVALUE_BASE_POINT7,
    SPELLVALUE_BASE_POINT8,
    SPELLVALUE_BASE_POINT9,
    SPELLVALUE_BASE_POINT10,
    SPELLVALUE_BASE_POINT11,
    SPELLVALUE_BASE_POINT12,
    SPELLVALUE_BASE_POINT13,
    SPELLVALUE_BASE_POINT14,
    SPELLVALUE_BASE_POINT15,
    SPELLVALUE_BASE_POINT16,
    SPELLVALUE_BASE_POINT17,
    SPELLVALUE_BASE_POINT18,
    SPELLVALUE_BASE_POINT19,
    SPELLVALUE_BASE_POINT20,
    SPELLVALUE_BASE_POINT21,
    SPELLVALUE_BASE_POINT22,
    SPELLVALUE_BASE_POINT23,
    SPELLVALUE_BASE_POINT24,
    SPELLVALUE_BASE_POINT25,
    SPELLVALUE_BASE_POINT26,
    SPELLVALUE_BASE_POINT27,
    SPELLVALUE_BASE_POINT28,
    SPELLVALUE_BASE_POINT29,
    SPELLVALUE_BASE_POINT30,
    SPELLVALUE_BASE_POINT31,
    SPELLVALUE_BASE_POINT_END,
    SPELLVALUE_RADIUS_MOD,
    SPELLVALUE_MAX_TARGETS,
    SPELLVALUE_AURA_STACK,
    SPELLVALUE_CRIT_CHANCE,
    SPELLVALUE_DURATION_PCT,
    SPELLVALUE_DURATION,
    SPELLVALUE_PARENT_SPELL_TARGET_COUNT,
    SPELLVALUE_PARENT_SPELL_TARGET_INDEX
};

enum SpellFacingFlags
{
    SPELL_FACING_FLAG_INFRONT = 0x0001
};

enum TriggerCastFlags : uint32
{
    TRIGGERED_NONE                                  = 0x00000000,   //!< Not triggered
    TRIGGERED_IGNORE_GCD                            = 0x00000001,   //!< Will ignore GCD
    TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD          = 0x00000002,   //!< Will ignore Spell and Category cooldowns
    TRIGGERED_IGNORE_POWER_AND_REAGENT_COST         = 0x00000004,   //!< Will ignore power and reagent cost
    TRIGGERED_IGNORE_CAST_ITEM                      = 0x00000008,   //!< Will not take away cast item or update related achievement criteria
    TRIGGERED_IGNORE_AURA_SCALING                   = 0x00000010,   //!< Will ignore aura scaling
    TRIGGERED_IGNORE_CAST_IN_PROGRESS               = 0x00000020,   //!< Will not check if a current cast is in progress
    // reuse                                        = 0x00000040,
    TRIGGERED_CAST_DIRECTLY                         = 0x00000080,   //!< In Spell::prepare, will be cast directly without setting containers for executed spell
    // reuse                                        = 0x00000100,
    TRIGGERED_IGNORE_SET_FACING                     = 0x00000200,   //!< Will not adjust facing to target (if any)
    TRIGGERED_IGNORE_SHAPESHIFT                     = 0x00000400,   //!< Will ignore shapeshift checks
    // reuse                                        = 0x00000800,
    TRIGGERED_DISALLOW_PROC_EVENTS                  = 0x00001000,   //!< Disallows proc events from triggered spell (default)
    TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE   = 0x00002000,   //!< Will ignore mounted/on vehicle restrictions
    // reuse                                        = 0x00004000,
    // reuse                                        = 0x00008000,
    TRIGGERED_IGNORE_CASTER_AURAS                   = 0x00010000,   //!< Will ignore caster aura restrictions or requirements
    TRIGGERED_DONT_RESET_PERIODIC_TIMER             = 0x00020000,   //!< Will allow periodic aura timers to keep ticking (instead of resetting)
    TRIGGERED_DONT_REPORT_CAST_ERROR                = 0x00040000,   //!< Will return SPELL_FAILED_DONT_REPORT in CheckCast functions
    TRIGGERED_FULL_MASK                             = 0x0007FFFF,   //!< Used when doing CastSpell with triggered == true

    // debug flags (used with .cast triggered commands)
    TRIGGERED_IGNORE_EQUIPPED_ITEM_REQUIREMENT      = 0x00080000,   //!< Will ignore equipped item requirements
    TRIGGERED_IGNORE_TARGET_CHECK                   = 0x00100000,   //!< Will ignore most target checks (mostly DBC target checks)
    TRIGGERED_IGNORE_CASTER_AURASTATE               = 0x00200000,   //!< Will ignore caster aura states including combat requirements and death state
    TRIGGERED_FULL_DEBUG_MASK                       = 0xFFFFFFFF
};

DEFINE_ENUM_FLAG(TriggerCastFlags);

enum SpellCastTargetFlags : uint32
{
    TARGET_FLAG_NONE            = 0x00000000,
    TARGET_FLAG_UNUSED_1        = 0x00000001,               // not used
    TARGET_FLAG_UNIT            = 0x00000002,               // pguid
    TARGET_FLAG_UNIT_RAID       = 0x00000004,               // not sent, used to validate target (if raid member)
    TARGET_FLAG_UNIT_PARTY      = 0x00000008,               // not sent, used to validate target (if party member)
    TARGET_FLAG_ITEM            = 0x00000010,               // pguid
    TARGET_FLAG_SOURCE_LOCATION = 0x00000020,               // pguid, 3 float
    TARGET_FLAG_DEST_LOCATION   = 0x00000040,               // pguid, 3 float
    TARGET_FLAG_UNIT_ENEMY      = 0x00000080,               // not sent, used to validate target (if enemy)
    TARGET_FLAG_UNIT_ALLY       = 0x00000100,               // not sent, used to validate target (if ally)
    TARGET_FLAG_CORPSE_ENEMY    = 0x00000200,               // pguid
    TARGET_FLAG_UNIT_DEAD       = 0x00000400,               // not sent, used to validate target (if dead creature)
    TARGET_FLAG_GAMEOBJECT      = 0x00000800,               // pguid, used with TARGET_GAMEOBJECT_TARGET
    TARGET_FLAG_TRADE_ITEM      = 0x00001000,               // pguid
    TARGET_FLAG_STRING          = 0x00002000,               // string
    TARGET_FLAG_GAMEOBJECT_ITEM = 0x00004000,               // not sent, used with TARGET_GAMEOBJECT_ITEM_TARGET
    TARGET_FLAG_CORPSE_ALLY     = 0x00008000,               // pguid
    TARGET_FLAG_UNIT_MINIPET    = 0x00010000,               // pguid, used to validate target (if non combat pet)
    TARGET_FLAG_GLYPH_SLOT      = 0x00020000,               // used in glyph spells
    TARGET_FLAG_DEST_TARGET     = 0x00040000,               // sometimes appears with DEST_TARGET spells (may appear or not for a given spell)
    TARGET_FLAG_EXTRA_TARGETS   = 0x00080000,               // uint32 counter, loop { vec3 - screen position (?), guid }, not used so far
    TARGET_FLAG_UNIT_PASSENGER  = 0x00100000,               // guessed, used to validate target (if vehicle passenger)
    TARGET_FLAG_UNK400000       = 0X00400000,
    TARGET_FLAG_UNK1000000      = 0X01000000,
    TARGET_FLAG_UNK4000000      = 0X04000000,
    TARGET_FLAG_UNK10000000     = 0X10000000,
    TARGET_FLAG_UNK40000000     = 0X40000000,

    TARGET_FLAG_UNIT_MASK = TARGET_FLAG_UNIT | TARGET_FLAG_UNIT_RAID | TARGET_FLAG_UNIT_PARTY
        | TARGET_FLAG_UNIT_ENEMY | TARGET_FLAG_UNIT_ALLY | TARGET_FLAG_UNIT_DEAD | TARGET_FLAG_UNIT_MINIPET | TARGET_FLAG_UNIT_PASSENGER,
    TARGET_FLAG_GAMEOBJECT_MASK = TARGET_FLAG_GAMEOBJECT | TARGET_FLAG_GAMEOBJECT_ITEM,
    TARGET_FLAG_CORPSE_MASK = TARGET_FLAG_CORPSE_ALLY | TARGET_FLAG_CORPSE_ENEMY,
    TARGET_FLAG_ITEM_MASK = TARGET_FLAG_TRADE_ITEM | TARGET_FLAG_ITEM | TARGET_FLAG_GAMEOBJECT_ITEM
};

struct TC_GAME_API SpellDestination
{
    SpellDestination();
    SpellDestination(float x, float y, float z, float orientation = 0.0f, uint32 mapId = MAPID_INVALID);
    SpellDestination(Position const& pos);
    SpellDestination(WorldLocation const& loc);
    SpellDestination(WorldObject const& wObj);

    void Relocate(Position const& pos);
    void RelocateOffset(Position const& offset);

    WorldLocation _position;
    ObjectGuid _transportGUID;
    Position _transportOffset;
};

class TC_GAME_API SpellCastTargets
{
public:
    SpellCastTargets();
    SpellCastTargets(Unit* caster, WorldPackets::Spells::SpellCastRequest const& spellCastRequest);
    ~SpellCastTargets();

    void Write(WorldPackets::Spells::SpellTargetData& data);

    uint32 GetTargetMask() const { return m_targetMask; }
    void SetTargetMask(uint32 newMask) { m_targetMask = newMask; }

    void SetTargetFlag(SpellCastTargetFlags flag) { m_targetMask |= flag; }

    ObjectGuid GetUnitTargetGUID() const;
    Unit* GetUnitTarget() const;
    void SetUnitTarget(Unit* target);

    ObjectGuid GetGOTargetGUID() const;
    GameObject* GetGOTarget() const;
    void SetGOTarget(GameObject* target);

    ObjectGuid GetCorpseTargetGUID() const;
    Corpse* GetCorpseTarget() const;

    WorldObject* GetObjectTarget() const;
    ObjectGuid GetObjectTargetGUID() const;
    void RemoveObjectTarget();

    ObjectGuid GetItemTargetGUID() const { return m_itemTargetGUID; }
    Item* GetItemTarget() const { return m_itemTarget; }
    uint32 GetItemTargetEntry() const { return m_itemTargetEntry; }
    void SetItemTarget(Item* item);
    void SetTradeItemTarget(Player* caster);
    void UpdateTradeSlotItem();

    SpellDestination const* GetSrc() const;
    Position const* GetSrcPos() const;
    void SetSrc(float x, float y, float z);
    void SetSrc(Position const& pos);
    void SetSrc(WorldObject const& wObj);
    void ModSrc(Position const& pos);
    void RemoveSrc();

    SpellDestination const* GetDst() const;
    WorldLocation const* GetDstPos() const;
    void SetDst(float x, float y, float z, float orientation, uint32 mapId = MAPID_INVALID);
    void SetDst(Position const& pos);
    void SetDst(WorldObject const& wObj);
    void SetDst(SpellDestination const& spellDest);
    void SetDst(SpellCastTargets const& spellTargets);
    void ModDst(Position const& pos);
    void ModDst(SpellDestination const& spellDest);
    void RemoveDst();

    bool HasSrc() const;
    bool HasDst() const;
    bool HasTraj() const { return m_speed != 0; }

    float GetPitch() const { return m_pitch; }
    void SetPitch(float pitch) { m_pitch = pitch; }
    float GetSpeed() const { return m_speed; }
    void SetSpeed(float speed) { m_speed = speed; }

    float GetDist2d() const { return m_src._position.GetExactDist2d(&m_dst._position); }
    float GetSpeedXY() const { return m_speed * std::cos(m_pitch); }
    float GetSpeedZ() const { return m_speed * std::sin(m_pitch); }

    void Update(WorldObject* caster);
    std::string GetTargetString() const { return m_strTarget; }

private:
    uint32 m_targetMask;

    // objects (can be used at spell creating and after Update at casting)
    WorldObject* m_objectTarget;
    Item* m_itemTarget;

    // object GUID/etc, can be used always
    ObjectGuid m_objectTargetGUID;
    ObjectGuid m_itemTargetGUID;
    uint32 m_itemTargetEntry;

    SpellDestination m_src;
    SpellDestination m_dst;

    float m_pitch, m_speed;
    std::string m_strTarget;
};

struct TC_GAME_API CastSpellTargetArg
{
    CastSpellTargetArg() { Targets.emplace(); }
    CastSpellTargetArg(std::nullptr_t) { Targets.emplace(); }
    CastSpellTargetArg(WorldObject* target);
    CastSpellTargetArg(Item* itemTarget)
    {
        Targets.emplace();
        Targets->SetItemTarget(itemTarget);
    }
    CastSpellTargetArg(Position const& dest)
    {
        Targets.emplace();
        Targets->SetDst(dest);
    }
    CastSpellTargetArg(SpellDestination const& dest)
    {
        Targets.emplace();
        Targets->SetDst(dest);
    }
    CastSpellTargetArg(SpellCastTargets&& targets)
    {
        Targets.emplace(std::move(targets));
    }

    Optional<SpellCastTargets> Targets; // empty optional used to signal error state
};

struct TC_GAME_API CastSpellExtraArgs
{
    CastSpellExtraArgs();
    CastSpellExtraArgs(bool triggered) : TriggerFlags(triggered ? TRIGGERED_FULL_MASK : TRIGGERED_NONE) {}
    CastSpellExtraArgs(TriggerCastFlags trigger) : TriggerFlags(trigger) {}
    CastSpellExtraArgs(Item* item) : TriggerFlags(TRIGGERED_FULL_MASK), CastItem(item) {}
    CastSpellExtraArgs(Spell const* triggeringSpell) : TriggerFlags(TRIGGERED_FULL_MASK) { SetTriggeringSpell(triggeringSpell); }
    CastSpellExtraArgs(AuraEffect const* eff) : TriggerFlags(TRIGGERED_FULL_MASK) { SetTriggeringAura(eff); }
    CastSpellExtraArgs(Difficulty castDifficulty) : CastDifficulty(castDifficulty) {}
    CastSpellExtraArgs(SpellValueMod mod, int32 val) { SpellValueOverrides.AddMod(mod, val); }

    CastSpellExtraArgs(CastSpellExtraArgs const& other);
    CastSpellExtraArgs(CastSpellExtraArgs&& other) noexcept;

    CastSpellExtraArgs& operator=(CastSpellExtraArgs const& other);
    CastSpellExtraArgs& operator=(CastSpellExtraArgs&& other) noexcept;

    ~CastSpellExtraArgs();

    CastSpellExtraArgs& SetTriggerFlags(TriggerCastFlags flag) { TriggerFlags = flag; return *this; }
    CastSpellExtraArgs& SetCastItem(Item* item) { CastItem = item; return *this; }
    CastSpellExtraArgs& SetTriggeringSpell(Spell const* triggeringSpell);
    CastSpellExtraArgs& SetTriggeringAura(AuraEffect const* triggeringAura);
    CastSpellExtraArgs& SetOriginalCaster(ObjectGuid const& guid) { OriginalCaster = guid; return *this; }
    CastSpellExtraArgs& SetCastDifficulty(Difficulty castDifficulty) { CastDifficulty = castDifficulty; return *this; }
    CastSpellExtraArgs& SetOriginalCastId(ObjectGuid const& castId) { OriginalCastId = castId; return *this; }
    CastSpellExtraArgs& AddSpellMod(SpellValueMod mod, int32 val) { SpellValueOverrides.AddMod(mod, val); return *this; }
    CastSpellExtraArgs& AddSpellBP0(int32 val) { return AddSpellMod(SPELLVALUE_BASE_POINT0, val); } // because i don't want to type SPELLVALUE_BASE_POINT0 300 times
    CastSpellExtraArgs& SetCustomArg(std::any customArg) { CustomArg = std::move(customArg); return *this; }
    CastSpellExtraArgs& SetScriptResult(Scripting::v2::ActionResultSetter<SpellCastResult> scriptResult) { ScriptResult.emplace(std::move(scriptResult)); return *this; }
    CastSpellExtraArgs& SetScriptWaitsForSpellHit(bool scriptWaitsForSpellHit) { ScriptWaitsForSpellHit = scriptWaitsForSpellHit; return *this; }

    TriggerCastFlags TriggerFlags = TRIGGERED_NONE;
    Item* CastItem = nullptr;
    Spell const* TriggeringSpell = nullptr;
    AuraEffect const* TriggeringAura = nullptr;
    ObjectGuid OriginalCaster = ObjectGuid::Empty;
    Difficulty CastDifficulty = Difficulty(0);
    ObjectGuid OriginalCastId = ObjectGuid::Empty;
    Optional<int32> OriginalCastItemLevel;
    struct
    {
        friend struct CastSpellExtraArgs;
        friend class WorldObject;

    private:
        void AddMod(SpellValueMod mod, int32 val) { data.push_back({ mod, val }); }

        auto begin() const { return data.cbegin(); }
        auto end() const { return data.cend(); }

        std::vector<std::pair<SpellValueMod, int32>> data;
    } SpellValueOverrides;
    std::any CustomArg;

    Optional<Scripting::v2::ActionResultSetter<SpellCastResult>> ScriptResult;
    bool ScriptWaitsForSpellHit = false;
};

struct SpellCastVisual
{
    uint32 SpellXSpellVisualID = 0;

    operator UF::SpellCastVisual() const;
    operator WorldPackets::Spells::SpellCastVisual() const;
};

class ProcFlagsInit : public FlagsArray<int32, 2>
{
    using Base = FlagsArray<int32, 2>;

public:
    constexpr ProcFlagsInit(ProcFlags procFlags = {}, ProcFlags2 procFlags2 = {})
    {
        _storage[0] = int32(procFlags);
        _storage[1] = int32(procFlags2);
    }

    constexpr ProcFlagsInit& operator|=(ProcFlags procFlags)
    {
        _storage[0] |= int32(procFlags);
        return *this;
    }

    constexpr ProcFlagsInit& operator|=(ProcFlags2 procFlags2)
    {
        _storage[1] |= int32(procFlags2);
        return *this;
    }

    using Base::operator&;

    constexpr ProcFlags operator&(ProcFlags procFlags) const
    {
        return static_cast<ProcFlags>(_storage[0] & procFlags);
    }

    constexpr ProcFlags2 operator&(ProcFlags2 procFlags2) const
    {
        return static_cast<ProcFlags2>(_storage[1] & procFlags2);
    }

    using Base::operator=;

    constexpr ProcFlagsInit& operator=(Base const& right)
    {
        _storage[0] = right[0];
        _storage[1] = right[1];
        return *this;
    }
};

#endif
