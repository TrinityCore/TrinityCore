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
#include "EnumFlag.h"
#include "ObjectGuid.h"
#include <vector>

class Item;
class AuraEffect;
enum Difficulty : uint8;

namespace UF
{
    struct SpellCastVisual;
}

namespace WorldPackets
{
    namespace Spells
    {
        struct SpellCastVisual;
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
    None                        = 0,
    Falling                     = 0x00000001, // NYI
    Swimming                    = 0x00000002, // NYI
    NotMoving                   = 0x00000004, // NYI
    Ground                      = 0x00000008, // NYI
    Transform                   = 0x00000010, // NYI
    Jump                        = 0x00000020,
    ChangeSpec                  = 0x00000040, // NYI
    AbandonVehicle              = 0x00000080, // NYI
    StartOfEncounter            = 0x00000100, // NYI
    EndOfEncounter              = 0x00000200, // NYI
    Disconnect                  = 0x00000400, // NYI
    EnteringInstance            = 0x00000800, // NYI
    DuelEnd                     = 0x00001000, // NYI
    LeaveArenaOrBattleground    = 0x00002000, // NYI
    ChangeTalent                = 0x00004000, // NYI
    ChangeGlyph                 = 0x00008000, // NYI
    SeamlessTransfer            = 0x00010000, // NYI
    WarModeLeave                = 0x00020000, // NYI
    TouchingGround              = 0x00040000, // NYI
    ChromieTime                 = 0x00080000, // NYI
    SplineFlightOrFreeFlight    = 0x00100000, // NYI
    ProcOrPeriodicAttacking     = 0x00200000  // NYI
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
    SPELLVALUE_DURATION_PCT
};

enum SpellFacingFlags
{
    SPELL_FACING_FLAG_INFRONT = 0x0001
};

enum TriggerCastFlags : uint32
{
    TRIGGERED_NONE                                  = 0x00000000,   //! Not triggered
    TRIGGERED_IGNORE_GCD                            = 0x00000001,   //! Will ignore GCD
    TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD          = 0x00000002,   //! Will ignore Spell and Category cooldowns
    TRIGGERED_IGNORE_POWER_AND_REAGENT_COST         = 0x00000004,   //! Will ignore power and reagent cost
    TRIGGERED_IGNORE_CAST_ITEM                      = 0x00000008,   //! Will not take away cast item or update related achievement criteria
    TRIGGERED_IGNORE_AURA_SCALING                   = 0x00000010,   //! Will ignore aura scaling
    TRIGGERED_IGNORE_CAST_IN_PROGRESS               = 0x00000020,   //! Will not check if a current cast is in progress
    TRIGGERED_IGNORE_COMBO_POINTS                   = 0x00000040,   //! Will ignore combo point requirement
    TRIGGERED_CAST_DIRECTLY                         = 0x00000080,   //! In Spell::prepare, will be cast directly without setting containers for executed spell
    TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS           = 0x00000100,   //! Will ignore interruptible aura's at cast
    TRIGGERED_IGNORE_SET_FACING                     = 0x00000200,   //! Will not adjust facing to target (if any)
    TRIGGERED_IGNORE_SHAPESHIFT                     = 0x00000400,   //! Will ignore shapeshift checks
    TRIGGERED_IGNORE_CASTER_AURASTATE               = 0x00000800,   //! Will ignore caster aura states including combat requirements and death state
    TRIGGERED_DISALLOW_PROC_EVENTS                  = 0x00001000,   //! Disallows proc events from triggered spell (default)
    TRIGGERED_IGNORE_CASTER_MOUNTED_OR_ON_VEHICLE   = 0x00002000,   //! Will ignore mounted/on vehicle restrictions
    // reuse                                        = 0x00004000,
    // reuse                                        = 0x00008000,
    TRIGGERED_IGNORE_CASTER_AURAS                   = 0x00010000,   //! Will ignore caster aura restrictions or requirements
    TRIGGERED_DONT_RESET_PERIODIC_TIMER             = 0x00020000,   //! Will allow periodic aura timers to keep ticking (instead of resetting)
    TRIGGERED_DONT_REPORT_CAST_ERROR                = 0x00040000,   //! Will return SPELL_FAILED_DONT_REPORT in CheckCast functions
    TRIGGERED_FULL_MASK                             = 0x0007FFFF,   //! Used when doing CastSpell with triggered == true

    // debug flags (used with .cast triggered commands)
    TRIGGERED_IGNORE_EQUIPPED_ITEM_REQUIREMENT      = 0x00080000,   //! Will ignore equipped item requirements
    TRIGGERED_IGNORE_TARGET_CHECK                   = 0x00100000,   //! Will ignore most target checks (mostly DBC target checks)
    TRIGGERED_FULL_DEBUG_MASK                       = 0xFFFFFFFF
};

struct TC_GAME_API CastSpellExtraArgs
{
    CastSpellExtraArgs() = default;
    CastSpellExtraArgs(bool triggered) : TriggerFlags(triggered ? TRIGGERED_FULL_MASK : TRIGGERED_NONE) {}
    CastSpellExtraArgs(TriggerCastFlags trigger) : TriggerFlags(trigger) {}
    CastSpellExtraArgs(Item* item) : TriggerFlags(TRIGGERED_FULL_MASK), CastItem(item) {}
    CastSpellExtraArgs(AuraEffect const* eff) : TriggerFlags(TRIGGERED_FULL_MASK), TriggeringAura(eff) {}
    CastSpellExtraArgs(ObjectGuid const& origCaster) : TriggerFlags(TRIGGERED_FULL_MASK), OriginalCaster(origCaster) {}
    CastSpellExtraArgs(AuraEffect const* eff, ObjectGuid const& origCaster) : TriggerFlags(TRIGGERED_FULL_MASK), TriggeringAura(eff), OriginalCaster(origCaster) {}
    CastSpellExtraArgs(Difficulty castDifficulty) : CastDifficulty(castDifficulty) {}
    CastSpellExtraArgs(SpellValueMod mod, int32 val) { SpellValueOverrides.AddMod(mod, val); }

    CastSpellExtraArgs& SetTriggerFlags(TriggerCastFlags flag) { TriggerFlags = flag; return *this; }
    CastSpellExtraArgs& SetCastItem(Item* item) { CastItem = item; return *this; }
    CastSpellExtraArgs& SetTriggeringAura(AuraEffect const* triggeringAura) { TriggeringAura = triggeringAura; return *this; }
    CastSpellExtraArgs& SetOriginalCaster(ObjectGuid const& guid) { OriginalCaster = guid; return *this; }
    CastSpellExtraArgs& SetCastDifficulty(Difficulty castDifficulty) { CastDifficulty = castDifficulty; return *this; }
    CastSpellExtraArgs& AddSpellMod(SpellValueMod mod, int32 val) { SpellValueOverrides.AddMod(mod, val); return *this; }
    CastSpellExtraArgs& AddSpellBP0(int32 val) { return AddSpellMod(SPELLVALUE_BASE_POINT0, val); } // because i don't want to type SPELLVALUE_BASE_POINT0 300 times

    TriggerCastFlags TriggerFlags = TRIGGERED_NONE;
    Item* CastItem = nullptr;
    AuraEffect const* TriggeringAura = nullptr;
    ObjectGuid OriginalCaster = ObjectGuid::Empty;
    Difficulty CastDifficulty = Difficulty(0);
    struct
    {
        friend struct CastSpellExtraArgs;
        friend class Unit;

        private:
            void AddMod(SpellValueMod mod, int32 val) { data.push_back({ mod, val }); }

            auto begin() const { return data.cbegin(); }
            auto end() const { return data.cend(); }

            std::vector<std::pair<SpellValueMod, int32>> data;
    } SpellValueOverrides;
};

struct SpellCastVisual
{
    uint32 SpellXSpellVisualID = 0;
    uint32 ScriptVisualID = 0;

    operator UF::SpellCastVisual() const;
    operator WorldPackets::Spells::SpellCastVisual() const;
};

#endif
