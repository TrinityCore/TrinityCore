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
#include "Optional.h"
#include "Position.h"
#include <vector>

class AuraEffect;
class Corpse;
class GameObject;
class Item;
class Player;
class Unit;
class WorldObject;

namespace WorldPackets
{
    namespace Spells
    {
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

enum SpellModOp : uint8
{
    SPELLMOD_DAMAGE                     =  0,
    SPELLMOD_DURATION                   =  1,
    SPELLMOD_THREAT                     =  2,
    SPELLMOD_EFFECT1                    =  3,
    SPELLMOD_CHARGES                    =  4,
    SPELLMOD_RANGE                      =  5,
    SPELLMOD_RADIUS                     =  6,
    SPELLMOD_CRITICAL_CHANCE            =  7,
    SPELLMOD_ALL_EFFECTS                =  8,
    SPELLMOD_NOT_LOSE_CASTING_TIME      =  9,
    SPELLMOD_CASTING_TIME               = 10,
    SPELLMOD_COOLDOWN                   = 11,
    SPELLMOD_EFFECT2                    = 12,
    SPELLMOD_IGNORE_ARMOR               = 13,
    SPELLMOD_COST                       = 14,
    SPELLMOD_CRIT_DAMAGE_BONUS          = 15,
    SPELLMOD_RESIST_MISS_CHANCE         = 16,
    SPELLMOD_JUMP_TARGETS               = 17,
    SPELLMOD_CHANCE_OF_SUCCESS          = 18,
    SPELLMOD_ACTIVATION_TIME            = 19,
    SPELLMOD_DAMAGE_MULTIPLIER          = 20,
    SPELLMOD_GLOBAL_COOLDOWN            = 21,
    SPELLMOD_DOT                        = 22,
    SPELLMOD_EFFECT3                    = 23,
    SPELLMOD_BONUS_MULTIPLIER           = 24,
    // spellmod 25
    SPELLMOD_PROC_PER_MINUTE            = 26,
    SPELLMOD_VALUE_MULTIPLIER           = 27,
    SPELLMOD_RESIST_DISPEL_CHANCE       = 28,
    SPELLMOD_CRIT_DAMAGE_BONUS_2        = 29, //one not used spell
    SPELLMOD_SPELL_COST_REFUND_ON_FAIL  = 30,

    MAX_SPELLMOD
};

enum SpellValueMod : uint8
{
    SPELLVALUE_BASE_POINT0,
    SPELLVALUE_BASE_POINT1,
    SPELLVALUE_BASE_POINT2,
    SPELLVALUE_RADIUS_MOD,
    SPELLVALUE_MAX_TARGETS,
    SPELLVALUE_AURA_STACK,
    SPELLVALUE_CRIT_CHANCE
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
    TRIGGERED_FULL_DEBUG_MASK                       = 0xFFFFFFFF
};

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
    TARGET_FLAG_UNUSED20        = 0x00080000,               // uint32 counter, loop { vec3 - screen position (?), guid }, not used so far
    TARGET_FLAG_UNIT_PASSENGER  = 0x00100000,               // guessed, used to validate target (if vehicle passenger)

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
    ~SpellCastTargets();

    void Read(ByteBuffer& data, Unit* caster);
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

    float GetElevation() const { return m_elevation; }
    void SetElevation(float elevation) { m_elevation = elevation; }
    float GetSpeed() const { return m_speed; }
    void SetSpeed(float speed) { m_speed = speed; }

    float GetDist2d() const { return m_src._position.GetExactDist2d(&m_dst._position); }
    float GetSpeedXY() const { return m_speed * std::cos(m_elevation); }
    float GetSpeedZ() const { return m_speed * std::sin(m_elevation); }

    void Update(WorldObject* caster);

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

    float m_elevation, m_speed;
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
    CastSpellTargetArg(SpellCastTargets&& targets)
    {
        Targets.emplace(std::move(targets));
    }

    Optional<SpellCastTargets> Targets; // empty optional used to signal error state
};

struct TC_GAME_API CastSpellExtraArgs
{
    CastSpellExtraArgs() {}
    CastSpellExtraArgs(bool triggered) : TriggerFlags(triggered ? TRIGGERED_FULL_MASK : TRIGGERED_NONE) {}
    CastSpellExtraArgs(TriggerCastFlags trigger) : TriggerFlags(trigger) {}
    CastSpellExtraArgs(Item* item) : TriggerFlags(TRIGGERED_FULL_MASK), CastItem(item) {}
    CastSpellExtraArgs(AuraEffect const* eff) : TriggerFlags(TRIGGERED_FULL_MASK), TriggeringAura(eff) {}
    CastSpellExtraArgs(ObjectGuid const& origCaster) : TriggerFlags(TRIGGERED_FULL_MASK), OriginalCaster(origCaster) {}
    CastSpellExtraArgs(AuraEffect const* eff, ObjectGuid const& origCaster) : TriggerFlags(TRIGGERED_FULL_MASK), TriggeringAura(eff), OriginalCaster(origCaster) {}
    CastSpellExtraArgs(SpellValueMod mod, int32 val) { SpellValueOverrides.AddMod(mod, val); }

    CastSpellExtraArgs& SetTriggerFlags(TriggerCastFlags flag) { TriggerFlags = flag; return *this; }
    CastSpellExtraArgs& SetCastItem(Item* item) { CastItem = item; return *this; }
    CastSpellExtraArgs& SetTriggeringAura(AuraEffect const* triggeringAura) { TriggeringAura = triggeringAura; return *this; }
    CastSpellExtraArgs& SetOriginalCaster(ObjectGuid const& guid) { OriginalCaster = guid; return *this; }
    CastSpellExtraArgs& AddSpellMod(SpellValueMod mod, int32 val) { SpellValueOverrides.AddMod(mod, val); return *this; }
    CastSpellExtraArgs& AddSpellBP0(int32 val) { return AddSpellMod(SPELLVALUE_BASE_POINT0, val); } // because i don't want to type SPELLVALUE_BASE_POINT0 300 times

    TriggerCastFlags TriggerFlags = TRIGGERED_NONE;
    Item* CastItem = nullptr;
    AuraEffect const* TriggeringAura = nullptr;
    ObjectGuid OriginalCaster = ObjectGuid::Empty;
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
};

#endif
