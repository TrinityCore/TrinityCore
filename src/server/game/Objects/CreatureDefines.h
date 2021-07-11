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

#ifndef __CREATURE_DEFINES_H
#define __CREATURE_DEFINES_H

#include "Common.h"
#include "SharedDefines.h"
#include "UnitDefines.h"
#include "ObjectGuid.h"
#include "Util.h"

#include <array>
#include <vector>


enum TrainerType                                            // this is important type for npcs!
{
    TRAINER_TYPE_CLASS             = 0,
    TRAINER_TYPE_MOUNTS            = 1,                     // on blizz it's 2
    TRAINER_TYPE_TRADESKILLS       = 2,
    TRAINER_TYPE_PETS              = 3
};

#define MAX_TRAINER_TYPE 4

// CreatureType.dbc
enum CreatureType
{
    CREATURE_TYPE_BEAST            = 1,
    CREATURE_TYPE_DRAGONKIN        = 2,
    CREATURE_TYPE_DEMON            = 3,
    CREATURE_TYPE_ELEMENTAL        = 4,
    CREATURE_TYPE_GIANT            = 5,
    CREATURE_TYPE_UNDEAD           = 6,
    CREATURE_TYPE_HUMANOID         = 7,
    CREATURE_TYPE_CRITTER          = 8,
    CREATURE_TYPE_MECHANICAL       = 9,
    CREATURE_TYPE_NOT_SPECIFIED    = 10,
    CREATURE_TYPE_TOTEM            = 11,
};

uint32 const CREATURE_TYPEMASK_HUMANOID_OR_UNDEAD = (1 << (CREATURE_TYPE_HUMANOID - 1)) | (1 << (CREATURE_TYPE_UNDEAD - 1));
uint32 const CREATURE_TYPEMASK_MECHANICAL_OR_ELEMENTAL = (1 << (CREATURE_TYPE_MECHANICAL - 1)) | (1 << (CREATURE_TYPE_ELEMENTAL - 1));

// CreatureFamily.dbc
enum CreatureFamily
{
    CREATURE_FAMILY_WOLF           = 1,
    CREATURE_FAMILY_CAT            = 2,
    CREATURE_FAMILY_SPIDER         = 3,
    CREATURE_FAMILY_BEAR           = 4,
    CREATURE_FAMILY_BOAR           = 5,
    CREATURE_FAMILY_CROCOLISK      = 6,
    CREATURE_FAMILY_CARRION_BIRD   = 7,
    CREATURE_FAMILY_CRAB           = 8,
    CREATURE_FAMILY_GORILLA        = 9,
    CREATURE_FAMILY_HORSE_CUSTOM   = 10,                    // not exist in DBC but used for horse like beasts in DB
    CREATURE_FAMILY_RAPTOR         = 11,
    CREATURE_FAMILY_TALLSTRIDER    = 12,
    CREATURE_FAMILY_FELHUNTER      = 15,
    CREATURE_FAMILY_VOIDWALKER     = 16,
    CREATURE_FAMILY_SUCCUBUS       = 17,
    CREATURE_FAMILY_DOOMGUARD      = 19,
    CREATURE_FAMILY_SCORPID        = 20,
    CREATURE_FAMILY_TURTLE         = 21,
    CREATURE_FAMILY_IMP            = 23,
    CREATURE_FAMILY_BAT            = 24,
    CREATURE_FAMILY_HYENA          = 25,
    CREATURE_FAMILY_OWL            = 26,
    CREATURE_FAMILY_WIND_SERPENT   = 27,
    CREATURE_FAMILY_REMOTE_CONTROL = 28,
};

enum CreatureTypeFlags
{
    CREATURE_TYPEFLAGS_TAMEABLE             = 0x00000001,       // Tameable by any hunter
    CREATURE_TYPEFLAGS_GHOST_VISIBLE        = 0x00000002,       // Creatures which can _also_ be seen when player is a ghost, used in CanInteract function by client, can't be attacked
    CREATURE_TYPEFLAGS_BOSS                 = 0x00000004,       // Changes creature's visible level to "??" in the creature's portrait
    CREATURE_TYPEFLAGS_NO_WOUND_ANIM        = 0x00000008,       // Disables "wounded" animations at spell taken
    CREATURE_TYPEFLAGS_HIDE_FACTION_TOOLTIP = 0x00000010,       // Controls something in client tooltip related to creature faction
    CREATURE_TYPEFLAGS_UNK6                 = 0x00000020,       // May be sound related
    CREATURE_TYPEFLAGS_SPELL_ATTACKABLE     = 0x00000040,       // May be related to attackable / not attackable creatures with spells, used together with lua_IsHelpfulSpell/lua_IsHarmfulSpell
};

enum CreatureEliteType
{
    CREATURE_ELITE_NORMAL          = 0,
    CREATURE_ELITE_ELITE           = 1,
    CREATURE_ELITE_RAREELITE       = 2,
    CREATURE_ELITE_WORLDBOSS       = 3,
    CREATURE_ELITE_RARE            = 4,
    CREATURE_UNKNOWN               = 5                      // found in 2.2.3 for 2 mobs
};

enum CreatureFlagsExtra
{
    CREATURE_FLAG_EXTRA_INSTANCE_BIND                = 0x00000001, // 1        Killing this creature will bind players to the raid
    CREATURE_FLAG_EXTRA_NO_AGGRO                     = 0x00000002, // 2        Creature will not attack nearby hostile targets (ignore faction/reputation hostility)
    CREATURE_FLAG_EXTRA_NO_PARRY                     = 0x00000004, // 4        Creature can't parry
    CREATURE_FLAG_EXTRA_SUMMON_GUARD                 = 0x00000008, // 8        Creature summons a guard if an opposite faction player gets near or attacks
    CREATURE_FLAG_EXTRA_NO_BLOCK                     = 0x00000010, // 16       Creature can't block
    CREATURE_FLAG_EXTRA_NO_CRUSH                     = 0x00000020, // 32       Creature can't do crush attacks
    CREATURE_FLAG_EXTRA_FIXED_Z                      = 0x00000040, // 64       Creature does not fall
    CREATURE_FLAG_EXTRA_INVISIBLE                    = 0x00000080, // 128      Creature is always invisible for player (mostly trigger creatures)
    CREATURE_FLAG_EXTRA_NOT_TAUNTABLE                = 0x00000100, // 256      Creature is immune to taunt auras and effect attack me
    CREATURE_FLAG_EXTRA_AGGRO_ZONE                   = 0x00000200, // 512      Creature sets itself in combat with zone on aggro
    CREATURE_FLAG_EXTRA_GUARD                        = 0x00000400, // 1024     Creature is a guard
    CREATURE_FLAG_EXTRA_NO_THREAT_LIST               = 0x00000800, // 2048     Creature does not select targets based on threat
    CREATURE_FLAG_EXTRA_KEEP_POSITIVE_AURAS_ON_EVADE = 0x00001000, // 4096     Creature keeps positive auras at reset
    CREATURE_FLAG_EXTRA_ALWAYS_CRUSH                 = 0x00002000, // 8192     Creature always roll a crushing melee outcome when not miss/crit/dodge/parry/block
    CREATURE_FLAG_EXTRA_IMMUNE_AOE                   = 0x00004000, // 16384    Creature is immune to AoE
    CREATURE_FLAG_EXTRA_CHASE_GEN_NO_BACKING         = 0x00008000, // 32768    Creature does not move back when target is within bounding radius
    CREATURE_FLAG_EXTRA_NO_ASSIST                    = 0x00010000, // 65536    Creature does not aggro when nearby creatures aggro
    CREATURE_FLAG_EXTRA_NO_TARGET                    = 0x00020000, // 131072   Creature does not acquire targets
    CREATURE_FLAG_EXTRA_ONLY_VISIBLE_TO_FRIENDLY     = 0x00040000, // 262144   Creature can only be seen by friendly units
    CREATURE_FLAG_EXTRA_PVP                          = 0x00080000, // 524288   Creature has pvp unit flag set by default
    CREATURE_FLAG_EXTRA_CAN_ASSIST                   = 0x00100000, // 1048576  CREATURE_TYPEFLAGS_CAN_ASSIST from TBC
    CREATURE_FLAG_EXTRA_LARGE_AOI                    = 0x00200000, // 2097152  CREATURE_DIFFICULTYFLAGS_LARGE_AOI (200 yards)
    CREATURE_FLAG_EXTRA_GIGANTIC_AOI                 = 0x00400000, // 4194304  CREATURE_DIFFICULTYFLAGS_3_GIGANTIC_AOI (400 yards)
    CREATURE_FLAG_EXTRA_INFINITE_AOI                 = 0x00800000, // 8388606  CREATURE_DIFFICULTYFLAGS_3_INFINITE_AOI
    CREATURE_FLAG_EXTRA_NO_MOVEMENT_PAUSE            = 0x01000000, // 16777216 Creature will not pause movement when player talks to it
    CREATURE_FLAG_EXTRA_ALWAYS_RUN                   = 0x02000000, // 33554432 Creature will use run speed out of combat
    CREATURE_FLAG_EXTRA_NO_UNREACHABLE_EVADE         = 0x04000000, // 67108864 Creature will not evade due to target being unreachable
};

// Number of spells in one template
#define CREATURE_SPELLS_MAX_SPELLS 8
// Columns in the db for each spell
#define CREATURE_SPELLS_MAX_COLUMNS 11

struct CreatureSpellsEntry
{
    uint16 const spellId;
    uint8 const  probability;
    uint8 const  castTarget;
    uint32 const targetParam1;
    uint32 const targetParam2;
    uint16 const  castFlags;
    uint32 const delayInitialMin;
    uint32 const delayInitialMax;
    uint32 const delayRepeatMin;
    uint32 const delayRepeatMax;
    uint32 const scriptId;
    CreatureSpellsEntry(uint16 Id, uint8 Probability, uint8 CastTarget, uint32 TargetParam1, uint32 TargetParam2, uint16 CastFlags, uint32 InitialMin, uint32 InitialMax, uint32 RepeatMin, uint32 RepeatMax, uint32 ScriptId) : spellId(Id), probability(Probability), castTarget(CastTarget), targetParam1(TargetParam1), targetParam2(TargetParam2), castFlags(CastFlags), delayInitialMin(InitialMin), delayInitialMax(InitialMax), delayRepeatMin(RepeatMin), delayRepeatMax(RepeatMax), scriptId(ScriptId) {}
};

typedef std::vector<CreatureSpellsEntry> CreatureSpellsList;

// GCC have alternative #pragma pack(N) syntax and old gcc version not support pack(push,N), also any gcc version not support it at some platform
#if defined(__GNUC__)
#pragma pack(1)
#else
#pragma pack(push,1)
#endif

#define MAX_DISPLAY_IDS_PER_CREATURE 4                                // only single send to client in static data
#define CREATURE_FLEE_TEXT 1150
#define NPC_MOVEMENT_PAUSE_TIME 180000

#define SPEED_REDUCTION_NONE   1.0f
#define SPEED_REDUCTION_HP_15  0.7f
#define SPEED_REDUCTION_HP_10  0.6f
#define SPEED_REDUCTION_HP_5   0.5f

// from `creature_template` table
struct CreatureInfo
{
    uint32  entry;
    uint32  display_id[MAX_DISPLAY_IDS_PER_CREATURE];
    float   display_scale[MAX_DISPLAY_IDS_PER_CREATURE];
    uint32  display_probability[MAX_DISPLAY_IDS_PER_CREATURE];
    uint32  display_total_probability;
    uint32  mount_display_id;
    char*   name;
    char*   subname;
    uint32  gossip_menu_id;
    uint32  level_min;
    uint32  level_max;
    uint32  health_min;
    uint32  health_max;
    uint32  mana_min;
    uint32  mana_max;
    uint32  armor;
    uint32  faction;
    uint32  npc_flags;
    float   speed_walk;
    float   speed_run;
    float   detection_range;                                // Detection Range for Line of Sight aggro
    float   call_for_help_range;                            // Radius for combat assistance call
    float   leash_range;                                    // Hard limit on allowed chase distance
    uint32  rank;
    float   xp_multiplier;
    float   dmg_min;
    float   dmg_max;
    uint32  dmg_school;
    uint32  attack_power;
    float   dmg_multiplier;
    uint32  base_attack_time;
    uint32  ranged_attack_time;
    uint32  unit_class;                                     // enum Classes. Note only 4 classes are known for creatures.
    uint32  unit_flags;                                     // enum UnitFlags mask values
    uint32  dynamic_flags;
    uint32  pet_family;                                     // enum CreatureFamily values (optional)
    uint32  trainer_type;
    uint32  trainer_spell;
    uint32  trainer_class;
    uint32  trainer_race;
    float   ranged_dmg_min;
    float   ranged_dmg_max;
    uint32  ranged_attack_power;
    uint32  type;                                           // enum CreatureType values
    uint32  type_flags;                                     // enum CreatureTypeFlags mask values
    uint32  loot_id;
    uint32  pickpocket_loot_id;
    uint32  skinning_loot_id;
    int32   holy_res;
    int32   fire_res;
    int32   nature_res;
    int32   frost_res;
    int32   shadow_res;
    int32   arcane_res;
    uint32  spells[CREATURE_MAX_SPELLS];
    uint32  spell_list_id;
    uint32  pet_spell_list_id;
    uint32 const* auras;
    uint32  gold_min;
    uint32  gold_max;
    char const* ai_name;
    uint32  movement_type;
    uint32  inhabit_type;
    uint32  civilian;
    bool    racial_leader;
    uint32  regeneration;
    uint32  equipment_id;
    uint32  trainer_id;
    uint32  vendor_id;
    uint32  mechanic_immune_mask;
    uint32  school_immune_mask;
    uint32  flags_extra;
    uint32  script_id;

    // helpers
    static HighGuid GetHighGuid()
    {
        return HIGHGUID_UNIT;                               // in pre-3.x always HIGHGUID_UNIT
    }

    ObjectGuid GetObjectGuid(uint32 lowguid) const { return ObjectGuid(GetHighGuid(), entry, lowguid); }

    bool isTameable() const
    {
        return type == CREATURE_TYPE_BEAST && pet_family != 0 && type_flags & CREATURE_TYPEFLAGS_TAMEABLE;
    }
};

struct EquipmentInfo
{
    uint32  entry;
    uint32  equipentry[3];
};

#define MAX_CREATURE_IDS_PER_SPAWN 4

// from `creature` table
struct CreatureData
{
    std::array<uint32, MAX_CREATURE_IDS_PER_SPAWN> creature_id = {};
    WorldLocation position;
    uint32 spawntimesecsmin = 0;
    uint32 spawntimesecsmax = 0;
    float wander_distance = 0.0f;
    float health_percent = 100.0f;
    float mana_percent = 100.0f;
    uint8 movement_type = 0;
    uint32 spawn_flags = 0;
    float visibility_mod = 0.0f;

    // non db field
    uint32 instanciatedContinentInstanceId;

    // helper function
    ObjectGuid GetObjectGuid(uint32 lowguid) const { return ObjectGuid(CreatureInfo::GetHighGuid(), creature_id[0], lowguid); }
    uint32 GetRandomRespawnTime() const { return urand(spawntimesecsmin, spawntimesecsmax); }
    uint32 ChooseCreatureId() const
    {
        uint32 creatureId = 0;
        uint32 creatureIdCount = 0;
        for (; creatureIdCount < MAX_CREATURE_IDS_PER_SPAWN && creature_id[creatureIdCount]; ++creatureIdCount);

        if (creatureIdCount)
            creatureId = creature_id[urand(0, creatureIdCount - 1)];

        if (!creatureId)
            creatureId = 1;

        return creatureId;
    }
    uint32 GetCreatureIdCount() const
    {
        uint32 creatureIdCount = 0;
        for (; creatureIdCount < MAX_CREATURE_IDS_PER_SPAWN && creature_id[creatureIdCount]; ++creatureIdCount);
        return creatureIdCount;
    }
};

// from `creature_addon` table
struct CreatureDataAddon
{
    uint32 guid;
    uint32 display_id;
    int32  mount_display_id;
    int32  equipment_id;
    uint8  stand_state;
    uint8  sheath_state;                                    // SheathState
    uint32 emote_state;
    uint32 const* auras;                                    // loaded as char* "spell1 spell2 ... "
};

struct CreatureDisplayInfoAddon
{
    uint32 display_id;
    float bounding_radius;
    float combat_reach;
    uint8 gender;
    uint32 display_id_other_gender;                         // The oposite gender for this display id (male/female)
};

// GCC have alternative #pragma pack() syntax and old gcc version not support pack(pop), also any gcc version not support it at some platform
#if defined(__GNUC__)
#pragma pack()
#else
#pragma pack(pop)
#endif

struct CreatureLocale
{
    std::vector<std::string> Name;
    std::vector<std::string> SubName;
};

struct GossipMenuItemsLocale
{
    std::vector<std::string> OptionText;
    std::vector<std::string> BoxText;
};

struct PointOfInterestLocale
{
    std::vector<std::string> IconName;
};

enum InhabitTypeValues
{
    INHABIT_GROUND = 1,
    INHABIT_WATER  = 2,
    INHABIT_AIR    = 4,
    INHABIT_ANYWHERE = INHABIT_GROUND | INHABIT_WATER | INHABIT_AIR
};

// Enums used by StringTextData::Type (CreatureEventAI)
enum ChatType
{
    CHAT_TYPE_SAY               = 0,
    CHAT_TYPE_YELL              = 1,
    CHAT_TYPE_TEXT_EMOTE        = 2,
    CHAT_TYPE_BOSS_EMOTE        = 3,
    CHAT_TYPE_WHISPER           = 4,
    CHAT_TYPE_BOSS_WHISPER      = 5,
    CHAT_TYPE_ZONE_YELL         = 6
};

// Selection method used by SelectAttackingTarget
enum AttackingTarget
{
    ATTACKING_TARGET_RANDOM = 0,                            // Just selects a random target
    ATTACKING_TARGET_TOPAGGRO,                              // Selects targets from top aggro to bottom
    ATTACKING_TARGET_BOTTOMAGGRO,                           // Selects targets from bottom aggro to top
    ATTACKING_TARGET_NEAREST,                               // Selects the closest target
    ATTACKING_TARGET_FARTHEST                               // Selects the farthest away target
};

enum SelectFlags
{
    SELECT_FLAG_IN_LOS              = 0x001,                // Default Selection Requirement for Spell-targets
    SELECT_FLAG_PLAYER              = 0x002,
    SELECT_FLAG_POWER_MANA          = 0x004,                // For Energy based spells, like manaburn
    SELECT_FLAG_POWER_RAGE          = 0x008,
    SELECT_FLAG_POWER_ENERGY        = 0x010,
    SELECT_FLAG_IN_MELEE_RANGE      = 0x040,
    SELECT_FLAG_NOT_IN_MELEE_RANGE  = 0x080,
    SELECT_FLAG_NO_TOTEM            = 0x100,
    SELECT_FLAG_PLAYER_NOT_GM       = 0x200,
    SELECT_FLAG_PET                 = 0x400,
    SELECT_FLAG_NOT_PLAYER          = 0x800,
    SELECT_FLAG_POWER_NOT_MANA      = 0x1000,               // Used in some dungeon encounters
};

#define MAX_SELECT_FLAG_MASK (SELECT_FLAG_IN_LOS | SELECT_FLAG_PLAYER | SELECT_FLAG_POWER_MANA | SELECT_FLAG_POWER_RAGE | SELECT_FLAG_POWER_ENERGY | SELECT_FLAG_IN_MELEE_RANGE | SELECT_FLAG_NOT_IN_MELEE_RANGE | SELECT_FLAG_NO_TOTEM | SELECT_FLAG_PLAYER_NOT_GM | SELECT_FLAG_PET | SELECT_FLAG_NOT_PLAYER | SELECT_FLAG_POWER_NOT_MANA)

enum RegenStatsFlags
{
    REGEN_FLAG_HEALTH               = 0x001,
    REGEN_FLAG_POWER                = 0x002,
};

enum CreatureStateFlag : uint16
{
    CSTATE_ALREADY_CALL_ASSIST   = 0x0001,
    CSTATE_ALREADY_SEARCH_ASSIST = 0x0002,
    CSTATE_REGEN_HEALTH          = 0x0004,
    CSTATE_REGEN_MANA            = 0x0008,
    CSTATE_INIT_AI_ON_RESPAWN    = 0x0010,
    CSTATE_COMBAT                = 0x0020,
    CSTATE_COMBAT_WITH_ZONE      = 0x0040,
    CSTATE_ESCORTABLE            = 0x0080,
    CSTATE_DESPAWNING            = 0x0100,
    CSTATE_TARGETED_EMOTE        = 0x0200,
};

// Vendors
struct VendorItem
{
    VendorItem(uint32 _item, uint32 _maxcount, uint32 _incrtime, uint32 _itemflags, uint32 _conditionId)
        : item(_item), maxcount(_maxcount), incrtime(_incrtime), itemflags(_itemflags), conditionId(_conditionId) {}

    uint32 item;
    uint32 maxcount;                                        // 0 for infinity item amount
    uint32 incrtime;                                        // time for restore items amount if maxcount != 0
    uint32 itemflags;
    uint32 conditionId;                                     // condition to check for this item
};
typedef std::vector<VendorItem*> VendorItemList;

struct VendorItemData
{
    VendorItemList m_items;

    VendorItem* GetItem(uint32 slot) const
    {
        if (slot>=m_items.size()) return nullptr;
        return m_items[slot];
    }
    bool Empty() const { return m_items.empty(); }
    uint8 GetItemCount() const { return m_items.size(); }
    void AddItem(uint32 item, uint32 maxcount, uint32 ptime, uint32 itemflags, uint32 conditonId)
    {
        m_items.push_back(new VendorItem(item, maxcount, ptime, itemflags, conditonId));
    }
    bool RemoveItem(uint32 item_id);
    VendorItem const* FindItem(uint32 item_id) const;
    size_t FindItemSlot(uint32 item_id) const;

    void Clear()
    {
        for (const auto& item : m_items)
            delete item;
        m_items.clear();
    }
};

struct VendorItemCount
{
    explicit VendorItemCount(uint32 _item, uint32 _count, uint32 _restockDelay)
        : itemId(_item), count(_count), restockDelay(_restockDelay), lastIncrementTime(time(nullptr)) {}

    uint32 itemId;
    uint32 count;
    uint32 restockDelay;
    time_t lastIncrementTime;
};

enum VendorItemFlags
{
    VENDOR_ITEM_FLAG_RANDOM_RESTOCK   = 0x01,
    VENDOR_ITEM_FLAG_DYNAMIC_RESTOCK  = 0x02,
};

typedef std::list<VendorItemCount> VendorItemCounts;

struct TrainerSpell
{
    TrainerSpell() : spell(0), spellCost(0), reqSkill(0), reqSkillValue(0), reqLevel(0) {}

    TrainerSpell(uint32 _spell, uint32 _spellCost, uint32 _reqSkill, uint32 _reqSkillValue, uint32 _reqLevel)
        : spell(_spell), spellCost(_spellCost), reqSkill(_reqSkill), reqSkillValue(_reqSkillValue), reqLevel(_reqLevel)
    {}

    uint32 spell;
    uint32 spellCost;
    uint32 reqSkill;
    uint32 reqSkillValue;
    uint32 reqLevel;
};

typedef std::unordered_map<uint32 /*spellid*/, TrainerSpell> TrainerSpellMap;

struct TrainerSpellData
{
    TrainerSpellData() : trainerType(0) {}

    TrainerSpellMap spellList;
    uint32 trainerType;                                     // trainer type based at trainer spells, can be different from creature_template value.
                                                            // req. for correct show non-prof. trainers like weaponmaster, allowed values 0 and 2.
    TrainerSpell const* Find(uint32 spell_id) const;
    void Clear() { spellList.clear(); }
};

// max different by z coordinate for creature aggro reaction
#define CREATURE_Z_ATTACK_RANGE 3

#define MAX_VENDOR_ITEMS 255                                // Limitation in item count field size in SMSG_LIST_INVENTORY

enum VirtualItemSlot
{
    VIRTUAL_ITEM_SLOT_0 = 0,
    VIRTUAL_ITEM_SLOT_1 = 1,
    VIRTUAL_ITEM_SLOT_2 = 2,
};

#define MAX_VIRTUAL_ITEM_SLOT 3

enum VirtualItemInfoByteOffset
{
    VIRTUAL_ITEM_INFO_0_OFFSET_CLASS         = 0,
    VIRTUAL_ITEM_INFO_0_OFFSET_SUBCLASS      = 1,
    VIRTUAL_ITEM_INFO_0_OFFSET_MATERIAL      = 2,
    VIRTUAL_ITEM_INFO_0_OFFSET_INVENTORYTYPE = 3,

    VIRTUAL_ITEM_INFO_1_OFFSET_SHEATH        = 0,
};

enum CreatureSubtype
{
    CREATURE_SUBTYPE_GENERIC,                               // new Creature
    CREATURE_SUBTYPE_PET,                                   // new Pet
    CREATURE_SUBTYPE_TOTEM,                                 // new Totem
    CREATURE_SUBTYPE_TEMPORARY_SUMMON,                      // new TemporarySummon
};

enum TemporaryFactionFlags                                  // Used at real faction changes
{
    TEMPFACTION_NONE                    = 0x00,             // When no flag is used in temporary faction change, faction will be persistent. It will then require manual change back to default/another faction when changed once
    TEMPFACTION_RESTORE_RESPAWN         = 0x01,             // Default faction will be restored at respawn
    TEMPFACTION_RESTORE_COMBAT_STOP     = 0x02,             // ... at CombatStop() (happens at creature death, at evade or custom scripte among others)
    TEMPFACTION_RESTORE_REACH_HOME      = 0x04,             // ... at reaching home in home movement (evade), if not already done at CombatStop()
    TEMPFACTION_ALL,
};

#endif
