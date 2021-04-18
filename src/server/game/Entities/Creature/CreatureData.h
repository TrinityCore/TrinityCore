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

#ifndef CreatureData_h__
#define CreatureData_h__

#include "DBCEnums.h"
#include "SharedDefines.h"
#include "SpawnData.h"
#include "UnitDefines.h"
#include "WorldPacket.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>

struct ItemTemplate;
enum class VisibilityDistanceType : uint8;

// EnumUtils: DESCRIBE THIS
enum CreatureFlagsExtra : uint32
{
    CREATURE_FLAG_EXTRA_INSTANCE_BIND        = 0x00000001,       // creature kill bind instance with killer and killer's group
    CREATURE_FLAG_EXTRA_CIVILIAN             = 0x00000002,       // not aggro (ignore faction/reputation hostility)
    CREATURE_FLAG_EXTRA_NO_PARRY             = 0x00000004,       // creature can't parry
    CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN      = 0x00000008,       // creature can't counter-attack at parry
    CREATURE_FLAG_EXTRA_NO_BLOCK             = 0x00000010,       // creature can't block
    CREATURE_FLAG_EXTRA_NO_CRUSHING_BLOWS    = 0x00000020,       // creature can't do crush attacks
    CREATURE_FLAG_EXTRA_NO_XP                = 0x00000040,       // creature kill does not provide XP
    CREATURE_FLAG_EXTRA_TRIGGER              = 0x00000080,       // trigger creature
    CREATURE_FLAG_EXTRA_NO_TAUNT             = 0x00000100,       // creature is immune to taunt auras and 'attack me' effects
    CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE = 0x00000200,       // creature won't update movement flags
    CREATURE_FLAG_EXTRA_GHOST_VISIBILITY     = 0x00000400,       // creature will only be visible to dead players
    CREATURE_FLAG_EXTRA_USE_OFFHAND_ATTACK   = 0x00000800,       // creature will use offhand attacks
    CREATURE_FLAG_EXTRA_NO_SELL_VENDOR       = 0x00001000,       // players can't sell items to this vendor
    CREATURE_FLAG_EXTRA_IGNORE_COMBAT        = 0x00002000,       // creature is not allowed to enter combat
    CREATURE_FLAG_EXTRA_WORLDEVENT           = 0x00004000,       // custom flag for world event creatures (left room for merging)
    CREATURE_FLAG_EXTRA_GUARD                = 0x00008000,       // Creature is guard
    CREATURE_FLAG_EXTRA_IGNORE_FEIGN_DEATH   = 0x00010000,       // creature ignores feign death
    CREATURE_FLAG_EXTRA_NO_CRIT              = 0x00020000,       // creature can't do critical strikes
    CREATURE_FLAG_EXTRA_NO_SKILL_GAINS       = 0x00040000,       // creature won't increase weapon skills
    CREATURE_FLAG_EXTRA_OBEYS_TAUNT_DIMINISHING_RETURNS = 0x00080000,       // Taunt is subject to diminishing returns on this creature
    CREATURE_FLAG_EXTRA_ALL_DIMINISH         = 0x00100000,       // creature is subject to all diminishing returns as players are
    CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ = 0x00200000,       // creature does not need to take player damage for kill credit
    CREATURE_FLAG_EXTRA_UNUSED_22            = 0x00400000,
    CREATURE_FLAG_EXTRA_UNUSED_23            = 0x00800000,
    CREATURE_FLAG_EXTRA_UNUSED_24            = 0x01000000,
    CREATURE_FLAG_EXTRA_UNUSED_25            = 0x02000000,
    CREATURE_FLAG_EXTRA_UNUSED_26            = 0x04000000,
    CREATURE_FLAG_EXTRA_UNUSED_27            = 0x08000000,
    CREATURE_FLAG_EXTRA_DUNGEON_BOSS         = 0x10000000,       // creature is a dungeon boss (SET DYNAMICALLY, DO NOT ADD IN DB)
    CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING   = 0x20000000,       // creature ignore pathfinding
    CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK   = 0x40000000,       // creature is immune to knockback effects
    CREATURE_FLAG_EXTRA_UNUSED_31            = 0x80000000,

    // Masks
    CREATURE_FLAG_EXTRA_UNUSED               = (CREATURE_FLAG_EXTRA_UNUSED_22 |
                                                CREATURE_FLAG_EXTRA_UNUSED_23 | CREATURE_FLAG_EXTRA_UNUSED_24 | CREATURE_FLAG_EXTRA_UNUSED_25 |
                                                CREATURE_FLAG_EXTRA_UNUSED_26 | CREATURE_FLAG_EXTRA_UNUSED_27 | CREATURE_FLAG_EXTRA_UNUSED_31), // SKIP

    CREATURE_FLAG_EXTRA_DB_ALLOWED           = (0xFFFFFFFF & ~(CREATURE_FLAG_EXTRA_UNUSED | CREATURE_FLAG_EXTRA_DUNGEON_BOSS)) // SKIP
};

enum class CreatureGroundMovementType : uint8
{
    None,
    Run,
    Hover,

    Max
};

enum class CreatureFlightMovementType : uint8
{
    None,
    DisableGravity,
    CanFly,

    Max
};

enum class CreatureChaseMovementType : uint8
{
    Run,
    CanWalk,
    AlwaysWalk,

    Max
};

enum class CreatureRandomMovementType : uint8
{
    Walk,
    CanRun,
    AlwaysRun,

    Max
};

struct TC_GAME_API CreatureMovementData
{
    CreatureMovementData();

    CreatureGroundMovementType Ground;
    CreatureFlightMovementType Flight;
    bool Swim;
    bool Rooted;
    CreatureChaseMovementType Chase;
    CreatureRandomMovementType Random;
    uint32 InteractionPauseTimer;

    bool IsGroundAllowed() const { return Ground != CreatureGroundMovementType::None; }
    bool IsSwimAllowed() const { return Swim; }
    bool IsFlightAllowed() const { return Flight != CreatureFlightMovementType::None; }
    bool IsRooted() const { return Rooted; }

    CreatureChaseMovementType GetChase() const { return Chase; }
    CreatureRandomMovementType GetRandom() const { return Random; }

    uint32 GetInteractionPauseTimer() const { return InteractionPauseTimer; }

    std::string ToString() const;
};

static const uint32 CREATURE_REGEN_INTERVAL = 2 * IN_MILLISECONDS;
static const uint32 PET_FOCUS_REGEN_INTERVAL = 4 * IN_MILLISECONDS;
static const uint32 CREATURE_NOPATH_EVADE_TIME = 5 * IN_MILLISECONDS;

static const uint8 MAX_KILL_CREDIT = 2;
static const uint32 MAX_CREATURE_MODELS = 4;
static const uint32 MAX_CREATURE_QUEST_ITEMS = 6;
static const uint32 MAX_CREATURE_SPELLS = 8;

// from `creature_template` table
struct TC_GAME_API CreatureTemplate
{
    uint32  Entry;
    uint32  DifficultyEntry[MAX_DIFFICULTY - 1];
    uint32  KillCredit[MAX_KILL_CREDIT];
    uint32  Modelid1;
    uint32  Modelid2;
    uint32  Modelid3;
    uint32  Modelid4;
    std::string  Name;
    std::string  Title;
    std::string  IconName;
    uint32  GossipMenuId;
    uint8   minlevel;
    uint8   maxlevel;
    uint32  expansion;
    uint32  faction;
    uint32  npcflag;
    float   speed_walk;
    float   speed_run;
    float   scale;
    uint32  rank;
    uint32  dmgschool;
    uint32  BaseAttackTime;
    uint32  RangeAttackTime;
    float   BaseVariance;
    float   RangeVariance;
    uint32  unit_class;                                     // enum Classes. Note only 4 classes are known for creatures.
    uint32  unit_flags;                                     // enum UnitFlags mask values
    uint32  unit_flags2;                                    // enum UnitFlags2 mask values
    uint32  dynamicflags;
    CreatureFamily  family;                                 // enum CreatureFamily values (optional)
    uint32  type;                                           // enum CreatureType values
    uint32  type_flags;                                     // enum CreatureTypeFlags mask values
    uint32  lootid;
    uint32  pickpocketLootId;
    uint32  SkinLootId;
    int32   resistance[MAX_SPELL_SCHOOL];
    uint32  spells[MAX_CREATURE_SPELLS];
    uint32  PetSpellDataId;
    uint32  VehicleId;
    uint32  mingold;
    uint32  maxgold;
    std::string AIName;
    uint32  MovementType;
    CreatureMovementData Movement;
    float   HoverHeight;
    float   ModHealth;
    float   ModMana;
    float   ModArmor;
    float   ModDamage;
    float   ModExperience;
    bool    RacialLeader;
    uint32  movementId;
    bool    RegenHealth;
    uint32  MechanicImmuneMask;
    uint32  SpellSchoolImmuneMask;
    uint32  flags_extra;
    uint32  ScriptID;
    WorldPacket QueryData[TOTAL_LOCALES];
    uint32  GetRandomValidModelId() const;
    uint32  GetFirstValidModelId() const;
    uint32  GetFirstInvisibleModel() const;
    uint32  GetFirstVisibleModel() const;

    // helpers
    SkillType GetRequiredLootSkill() const
    {
        if (type_flags & CREATURE_TYPE_FLAG_SKIN_WITH_HERBALISM)
            return SKILL_HERBALISM;
        else if (type_flags & CREATURE_TYPE_FLAG_SKIN_WITH_MINING)
            return SKILL_MINING;
        else if (type_flags & CREATURE_TYPE_FLAG_SKIN_WITH_ENGINEERING)
            return SKILL_ENGINEERING;
        else
            return SKILL_SKINNING;                          // normal case
    }

    bool IsExotic() const
    {
        return (type_flags & CREATURE_TYPE_FLAG_TAMEABLE_EXOTIC) != 0;
    }

    bool IsTameable(bool canTameExotic) const
    {
        if (type != CREATURE_TYPE_BEAST || family == CREATURE_FAMILY_NONE || (type_flags & CREATURE_TYPE_FLAG_TAMEABLE) == 0)
            return false;

        // if can tame exotic then can tame any tameable
        return canTameExotic || !IsExotic();
    }

    void InitializeQueryData();
    WorldPacket BuildQueryData(LocaleConstant loc) const;
};

#pragma pack(push, 1)

// Defines base stats for creatures (used to calculate HP/mana/armor/attackpower/rangedattackpower/all damage).
struct TC_GAME_API CreatureBaseStats
{
    uint32 BaseHealth[MAX_EXPANSIONS];
    uint32 BaseMana;
    uint32 BaseArmor;
    uint32 AttackPower;
    uint32 RangedAttackPower;
    float BaseDamage[MAX_EXPANSIONS];

    // Helpers

    uint32 GenerateHealth(CreatureTemplate const* info) const
    {
        return uint32(ceil(BaseHealth[info->expansion] * info->ModHealth));
    }

    uint32 GenerateMana(CreatureTemplate const* info) const
    {
        // Mana can be 0.
        if (!BaseMana)
            return 0;

        return uint32(ceil(BaseMana * info->ModMana));
    }

    uint32 GenerateArmor(CreatureTemplate const* info) const
    {
        return uint32(ceil(BaseArmor * info->ModArmor));
    }

    float GenerateBaseDamage(CreatureTemplate const* info) const
    {
        return BaseDamage[info->expansion];
    }

    static CreatureBaseStats const* GetBaseStats(uint8 level, uint8 unitClass);
};

struct CreatureLocale
{
    std::vector<std::string> Name;
    std::vector<std::string> Title;
};

struct EquipmentInfo
{
    uint32  ItemEntry[MAX_EQUIPMENT_ITEMS];
};

// from `creature` table
struct CreatureData : public SpawnData
{
    CreatureData() : SpawnData(SPAWN_TYPE_CREATURE) { }
    uint32 displayid = 0;
    int8 equipmentId = 0;
    float wander_distance = 0.0f;
    uint32 currentwaypoint = 0;
    uint32 curhealth = 0;
    uint32 curmana = 0;
    uint8 movementType = 0;
    uint32 npcflag = 0;
    uint32 unit_flags = 0;
    uint32 dynamicflags = 0;
};

struct CreatureModelInfo
{
    float bounding_radius;
    float combat_reach;
    uint8 gender;
    uint32 modelid_other_gender;
    bool is_trigger;
};

enum InhabitTypeValues
{
    INHABIT_GROUND = 1,
    INHABIT_WATER  = 2,
    INHABIT_AIR    = 4,
    INHABIT_ROOT   = 8,
    INHABIT_ANYWHERE = INHABIT_GROUND | INHABIT_WATER | INHABIT_AIR | INHABIT_ROOT
};

#pragma pack(pop)

// `creature_addon` table
struct CreatureAddon
{
    uint32 path_id;
    uint32 mount;
    uint32 bytes1;
    uint32 bytes2;
    uint32 emote;
    std::vector<uint32> auras;
    VisibilityDistanceType visibilityDistanceType;
};

// Vendors
struct VendorItem
{
    VendorItem(uint32 _item, int32 _maxcount, uint32 _incrtime, uint32 _ExtendedCost)
        : item(_item), maxcount(_maxcount), incrtime(_incrtime), ExtendedCost(_ExtendedCost) { }

    uint32 item;
    uint32 maxcount;                                        // 0 for infinity item amount
    uint32 incrtime;                                        // time for restore items amount if maxcount != 0
    uint32 ExtendedCost;

    //helpers
    bool IsGoldRequired(ItemTemplate const* pProto) const;
};

struct VendorItemData
{
    std::vector<VendorItem> m_items;

    VendorItem const* GetItem(uint32 slot) const
    {
        if (slot >= m_items.size())
            return nullptr;

        return &m_items[slot];
    }
    bool Empty() const { return m_items.empty(); }
    uint8 GetItemCount() const { return m_items.size(); }
    void AddItem(uint32 item, int32 maxcount, uint32 ptime, uint32 ExtendedCost)
    {
        m_items.emplace_back(item, maxcount, ptime, ExtendedCost);
    }
    bool RemoveItem(uint32 item_id);
    VendorItem const* FindItemCostPair(uint32 item_id, uint32 extendedCost) const;
    void Clear()
    {
        m_items.clear();
    }
};

#endif // CreatureData_h__
