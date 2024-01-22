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

#ifndef _PLAYER_H
#define _PLAYER_H

#include "GridObject.h"
#include "Unit.h"
#include "CUFProfile.h"
#include "DatabaseEnvFwd.h"
#include "DBCEnums.h"
#include "EquipmentSet.h"
#include "GroupReference.h"
#include "Hash.h"
#include "ItemDefines.h"
#include "ItemEnchantmentMgr.h"
#include "MapReference.h"
#include "PetDefines.h"
#include "PlayerTaxi.h"
#include "QuestDef.h"
#include "SceneMgr.h"

struct AccessRequirement;
struct AchievementEntry;
struct AreaTableEntry;
struct AreaTriggerEntry;
struct BarberShopStyleEntry;
struct BattlegroundTemplate;
struct CharTitlesEntry;
struct ChatChannelsEntry;
struct ChrSpecializationEntry;
struct CreatureTemplate;
struct CurrencyTypesEntry;
struct FactionEntry;
struct ItemExtendedCostEntry;
struct ItemLimitCategoryEntry;
struct ItemSetEffect;
struct ItemTemplate;
struct Loot;
struct Mail;
struct MapEntry;
struct PvpTalentEntry;
struct QuestPackageItemEntry;
struct RewardPackEntry;
struct SkillRaceClassInfoEntry;
struct SpellCastRequest;
struct TalentEntry;
struct TrainerSpell;
struct TransferAbortParams;
struct VendorItem;
struct WorldSafeLocsEntry;

class AELootResult;
class Bag;
class Battleground;
class Channel;
class CinematicMgr;
class Creature;
class DynamicObject;
class Group;
class Guild;
class Item;
class LootRoll;
class LootStore;
class OutdoorPvP;
class Pet;
class PetAura;
class PlayerAI;
class PlayerAchievementMgr;
class PlayerMenu;
class PlayerSocial;
class QuestObjectiveCriteriaMgr;
class ReputationMgr;
class RestMgr;
class SpellCastTargets;
class TradeData;

enum class ChrSpecialization : uint32;
enum GroupCategory : uint8;
enum class InstanceResetMethod : uint8;
enum class InstanceResetResult : uint8;
enum InventoryType : uint8;
enum ItemClass : uint8;
enum LootError : uint8;
enum LootType : uint8;
enum PlayerRestState : uint8;
enum class PlayerCreateMode : int8;
enum RestTypes : uint8;
enum TransferAbortReason : uint32;

namespace BattlePets
{
    struct BattlePet;
}

namespace WorldPackets
{
    namespace Character
    {
        struct CharacterCreateInfo;
        struct CustomTabardInfo;
    }

    namespace Movement
    {
        enum class UpdateCollisionHeightReason : uint8;
    }

    namespace Traits
    {
        struct TraitConfig;
        struct TraitEntry;
    }
}

TC_GAME_API uint32 GetBagSize(Bag const* bag);
TC_GAME_API Item* GetItemInBag(Bag const* bag, uint8 slot);

typedef std::deque<Mail*> PlayerMails;

enum PlayerSkillsConstants
{
    PLAYER_MAX_SKILLS   = UF::size<decltype(UF::SkillInfo::SkillLineID)>()
};

enum PlayerExplorationConstants
{
    PLAYER_EXPLORED_ZONES_SIZE  = UF::size<decltype(UF::ActivePlayerData::ExploredZones)>(),
    PLAYER_EXPLORED_ZONES_BITS  = UF::size_of_value_type<decltype(UF::ActivePlayerData::ExploredZones)>() * 8
};

enum SpellModType : uint8
{
    SPELLMOD_FLAT         = 0,                            // SPELL_AURA_ADD_FLAT_MODIFIER
    SPELLMOD_PCT          = 1,                            // SPELL_AURA_ADD_PCT_MODIFIER
    SPELLMOD_LABEL_FLAT   = 2,                            // SPELL_AURA_ADD_FLAT_MODIFIER_BY_SPELL_LABEL
    SPELLMOD_LABEL_PCT    = 3,                            // SPELL_AURA_ADD_PCT_MODIFIER_BY_SPELL_LABEL
    SPELLMOD_END
};

// 2^n values, Player::m_isunderwater is a bitmask. These are Trinity internal values, they are never send to any client
enum PlayerUnderwaterState
{
    UNDERWATER_NONE                     = 0x00,
    UNDERWATER_INWATER                  = 0x01,             // terrain type is water and player is afflicted by it
    UNDERWATER_INLAVA                   = 0x02,             // terrain type is lava and player is afflicted by it
    UNDERWATER_INSLIME                  = 0x04,             // terrain type is lava and player is afflicted by it
    UNDERWATER_INDARKWATER              = 0x08,             // terrain type is dark water and player is afflicted by it

    UNDERWATER_EXIST_TIMERS             = 0x10
};

enum BuyBankSlotResult
{
    ERR_BANKSLOT_FAILED_TOO_MANY    = 0,
    ERR_BANKSLOT_INSUFFICIENT_FUNDS = 1,
    ERR_BANKSLOT_NOTBANKER          = 2,
    ERR_BANKSLOT_OK                 = 3
};

enum PlayerSpellState : uint8
{
    PLAYERSPELL_UNCHANGED = 0,
    PLAYERSPELL_CHANGED   = 1,
    PLAYERSPELL_NEW       = 2,
    PLAYERSPELL_REMOVED   = 3,
    PLAYERSPELL_TEMPORARY = 4
};

struct PlayerSpell
{
    PlayerSpellState state;
    bool active            : 1;                             // show in spellbook
    bool dependent         : 1;                             // learned as result another spell learn, skill grow, quest reward, etc
    bool disabled          : 1;                             // first rank has been learned in result talent learn but currently talent unlearned, save max learned ranks
    bool favorite          : 1;
    Optional<int32> TraitDefinitionId;
};

struct StoredAuraTeleportLocation
{
    WorldLocation Loc;

    enum
    {
        UNCHANGED,
        CHANGED,
        DELETED,
    } State;
};

enum SpecResetType
{
    SPEC_RESET_TALENTS = 0,
    SPEC_RESET_SPECIALIZATION = 1,
    SPEC_RESET_GLYPHS = 2,
    SPEC_RESET_PET_TALENTS = 3
};

// Spell modifier (used for modify other spells)
struct SpellModifier
{
    SpellModifier(Aura* _ownerAura) : op(SpellModOp::HealingAndDamage), type(SPELLMOD_FLAT), spellId(0), ownerAura(_ownerAura) { }
    virtual ~SpellModifier() = default;

    SpellModOp op;
    SpellModType type;

    uint32 spellId;
    Aura* const ownerAura;
};

struct SpellModifierByClassMask : SpellModifier
{
    SpellModifierByClassMask(Aura* _ownerAura) : SpellModifier(_ownerAura), value(0), mask() { }

    int32 value;
    flag128 mask;
};

template<typename T>
struct SpellModifierByLabel : SpellModifier
{
    SpellModifierByLabel(Aura* _ownerAura) : SpellModifier(_ownerAura) { }

    T value;
};

using SpellFlatModifierByLabel = SpellModifierByLabel<UF::SpellFlatModByLabel>;
using SpellPctModifierByLabel = SpellModifierByLabel<UF::SpellPctModByLabel>;

enum PlayerCurrencyState
{
    PLAYERCURRENCY_UNCHANGED = 0,
    PLAYERCURRENCY_CHANGED = 1,
    PLAYERCURRENCY_NEW = 2,
    PLAYERCURRENCY_REMOVED = 3     //not removed just set count == 0
};

struct PlayerCurrency
{
    PlayerCurrencyState state;
    uint32 Quantity;
    uint32 WeeklyQuantity;
    uint32 TrackedQuantity;
    uint32 IncreasedCapQuantity;
    uint32 EarnedQuantity;
    CurrencyDbFlags Flags;
};

struct PlayerTalentState
{
    PlayerSpellState State = PLAYERSPELL_UNCHANGED;
    uint8 Rank = 0;
};

typedef std::unordered_map<uint32, PlayerTalentState> PlayerTalentMap;
typedef std::unordered_map<uint32, PlayerSpell> PlayerSpellMap;
typedef std::unordered_set<SpellModifier*> SpellModContainer;
typedef std::unordered_map<uint32, PlayerCurrency> PlayerCurrenciesMap;

typedef std::unordered_map<uint32 /*instanceId*/, time_t/*releaseTime*/> InstanceTimeMap;

enum ActionButtonUpdateState
{
    ACTIONBUTTON_UNCHANGED = 0,
    ACTIONBUTTON_CHANGED   = 1,
    ACTIONBUTTON_NEW       = 2,
    ACTIONBUTTON_DELETED   = 3
};

enum ActionButtonType
{
    ACTION_BUTTON_SPELL     = 0x00,
    ACTION_BUTTON_C         = 0x01,                         // click?
    ACTION_BUTTON_EQSET     = 0x20,
    ACTION_BUTTON_DROPDOWN  = 0x30,
    ACTION_BUTTON_MACRO     = 0x40,
    ACTION_BUTTON_CMACRO    = ACTION_BUTTON_C | ACTION_BUTTON_MACRO,
    ACTION_BUTTON_COMPANION = 0x50,
    ACTION_BUTTON_MOUNT     = 0x60,
    ACTION_BUTTON_ITEM      = 0x80
};

enum ReputationSource
{
    REPUTATION_SOURCE_KILL,
    REPUTATION_SOURCE_QUEST,
    REPUTATION_SOURCE_DAILY_QUEST,
    REPUTATION_SOURCE_WEEKLY_QUEST,
    REPUTATION_SOURCE_MONTHLY_QUEST,
    REPUTATION_SOURCE_REPEATABLE_QUEST,
    REPUTATION_SOURCE_SPELL
};

#define ACTION_BUTTON_ACTION(X) (uint32(X) & 0x00FFFFFF)
#define ACTION_BUTTON_TYPE(X)   ((uint32(X) & 0xFF000000) >> 24)
#define MAX_ACTION_BUTTON_ACTION_VALUE (0x00FFFFFF+1)

struct ActionButton
{
    ActionButton() : packedData(0), uState(ACTIONBUTTON_NEW) { }

    uint64 packedData;
    ActionButtonUpdateState uState;

    // helpers
    ActionButtonType GetType() const { return ActionButtonType(ACTION_BUTTON_TYPE(packedData)); }
    uint32 GetAction() const { return ACTION_BUTTON_ACTION(packedData); }
    void SetActionAndType(uint32 action, ActionButtonType type)
    {
        uint32 newData = action | (uint32(type) << 24);
        if (newData != packedData || uState == ACTIONBUTTON_DELETED)
        {
            packedData = newData;
            if (uState != ACTIONBUTTON_NEW)
                uState = ACTIONBUTTON_CHANGED;
        }
    }
};

#define MAX_ACTION_BUTTONS 180  //checked in 3.4.3

typedef std::map<uint8, ActionButton> ActionButtonList;

struct PvPInfo
{
    PvPInfo() : IsHostile(false), IsInHostileArea(false), IsInNoPvPArea(false), IsInFFAPvPArea(false), EndTimer(0) { }

    bool IsHostile;
    bool IsInHostileArea;               ///> Marks if player is in an area which forces PvP flag
    bool IsInNoPvPArea;                 ///> Marks if player is in a sanctuary or friendly capital city
    bool IsInFFAPvPArea;                ///> Marks if player is in an FFAPvP area (such as Gurubashi Arena)
    time_t EndTimer;                    ///> Time when player unflags himself for PvP (flag removed after 5 minutes)
};

enum DuelState
{
    DUEL_STATE_CHALLENGED,
    DUEL_STATE_COUNTDOWN,
    DUEL_STATE_IN_PROGRESS,
    DUEL_STATE_COMPLETED
};
struct DuelInfo
{
    DuelInfo(Player* opponent, Player* initiator, bool isMounted) : Opponent(opponent), Initiator(initiator), IsMounted(isMounted) {}

    Player* const Opponent;
    Player* const Initiator;
    bool const IsMounted;
    DuelState State = DUEL_STATE_CHALLENGED;
    time_t StartTime = 0;
    time_t OutOfBoundsTime = 0;
};

struct Areas
{
    uint32 areaID;
    uint32 areaFlag;
    float x1;
    float x2;
    float y1;
    float y2;
};

#define MAX_RUNES 7
#define MAX_RECHARGING_RUNES 3

enum RuneCooldowns
{
    RUNE_BASE_COOLDOWN  = 10000,
    RUNE_MISS_COOLDOWN  = 1500     // cooldown applied on runes when the spell misses
};

struct Runes
{
    std::deque<uint8> CooldownOrder;
    uint32 Cooldown[MAX_RUNES];
    uint8 RuneState;                                        // mask of available runes

    void SetRuneState(uint8 index, bool set = true);
};

struct EnchantDuration
{
    EnchantDuration() : item(nullptr), slot(MAX_ENCHANTMENT_SLOT), leftduration(0) { }
    EnchantDuration(Item* _item, EnchantmentSlot _slot, uint32 _leftduration) : item(_item), slot(_slot),
        leftduration(_leftduration){ ASSERT(item); }

    Item* item;
    EnchantmentSlot slot;
    uint32 leftduration;
};

typedef std::list<EnchantDuration> EnchantDurationList;
typedef std::list<Item*> ItemDurationList;

enum DrunkenState
{
    DRUNKEN_SOBER   = 0,
    DRUNKEN_TIPSY   = 1,
    DRUNKEN_DRUNK   = 2,
    DRUNKEN_SMASHED = 3
};

#define MAX_DRUNKEN   4

enum PlayerFlags
{
    PLAYER_FLAGS_GROUP_LEADER           = 0x00000001,
    PLAYER_FLAGS_AFK                    = 0x00000002,
    PLAYER_FLAGS_DND                    = 0x00000004,
    PLAYER_FLAGS_GM                     = 0x00000008,
    PLAYER_FLAGS_GHOST                  = 0x00000010,
    PLAYER_FLAGS_RESTING                = 0x00000020,
    PLAYER_FLAGS_VOICE_CHAT             = 0x00000040,
    PLAYER_FLAGS_UNK7                   = 0x00000080,       // pre-3.0.3 PLAYER_FLAGS_FFA_PVP flag for FFA PVP state
    PLAYER_FLAGS_CONTESTED_PVP          = 0x00000100,       // Player has been involved in a PvP combat and will be attacked by contested guards
    PLAYER_FLAGS_IN_PVP                 = 0x00000200,
    PLAYER_FLAGS_WAR_MODE_ACTIVE        = 0x00000400,
    PLAYER_FLAGS_WAR_MODE_DESIRED       = 0x00000800,
    PLAYER_FLAGS_PLAYED_LONG_TIME       = 0x00001000,       // played long time
    PLAYER_FLAGS_PLAYED_TOO_LONG        = 0x00002000,       // played too long time
    PLAYER_FLAGS_IS_OUT_OF_BOUNDS       = 0x00004000,
    PLAYER_FLAGS_DEVELOPER              = 0x00008000,       // <Dev> prefix for something?
    PLAYER_FLAGS_LOW_LEVEL_RAID_ENABLED = 0x00010000,       // pre-3.0.3 PLAYER_FLAGS_SANCTUARY flag for player entered sanctuary
    PLAYER_FLAGS_TAXI_BENCHMARK         = 0x00020000,       // taxi benchmark mode (on/off) (2.0.1)
    PLAYER_FLAGS_PVP_TIMER              = 0x00040000,       // 3.0.2, pvp timer active (after you disable pvp manually)
    PLAYER_FLAGS_UBER                   = 0x00080000,
    PLAYER_FLAGS_UNK20                  = 0x00100000,
    PLAYER_FLAGS_UNK21                  = 0x00200000,
    PLAYER_FLAGS_COMMENTATOR2           = 0x00400000,
    PLAYER_FLAGS_HIDE_ACCOUNT_ACHIEVEMENTS = 0x00800000,    // do not send account achievments in inspect packets
    PLAYER_FLAGS_PET_BATTLES_UNLOCKED   = 0x01000000,       // enables pet battles
    PLAYER_FLAGS_NO_XP_GAIN             = 0x02000000,
    PLAYER_FLAGS_UNK26                  = 0x04000000,
    PLAYER_FLAGS_AUTO_DECLINE_GUILD     = 0x08000000,       // Automatically declines guild invites
    PLAYER_FLAGS_GUILD_LEVEL_ENABLED    = 0x10000000,       // Lua_GetGuildLevelEnabled() - enables guild leveling related UI
    PLAYER_FLAGS_VOID_UNLOCKED          = 0x20000000,       // void storage
    PLAYER_FLAGS_TIMEWALKING            = 0x40000000,
    PLAYER_FLAGS_COMMENTATOR_CAMERA     = 0x80000000
};

DEFINE_ENUM_FLAG(PlayerFlags);

enum PlayerFlagsEx
{
    PLAYER_FLAGS_EX_REAGENT_BANK_UNLOCKED   = 0x0001,
    PLAYER_FLAGS_EX_MERCENARY_MODE          = 0x0002,
    PLAYER_FLAGS_EX_ARTIFACT_FORGE_CHEAT    = 0x0004,
    PLAYER_FLAGS_EX_IN_PVP_COMBAT           = 0x0040,       // Forbids /follow
    PLAYER_FLAGS_EX_MENTOR                  = 0x0080,
    PLAYER_FLAGS_EX_NEWCOMER                = 0x0100,
    PLAYER_FLAGS_EX_UNLOCKED_AOE_LOOT       = 0x0200
};

DEFINE_ENUM_FLAG(PlayerFlagsEx);

enum PlayerLocalFlags
{
    PLAYER_LOCAL_FLAG_CONTROLLING_PET               = 0x00000001,   // Displays "You have an active summon already" when trying to tame new pet
    PLAYER_LOCAL_FLAG_TRACK_STEALTHED               = 0x00000002,
    PLAYER_LOCAL_FLAG_RELEASE_TIMER                 = 0x00000008,   // Display time till auto release spirit
    PLAYER_LOCAL_FLAG_NO_RELEASE_WINDOW             = 0x00000010,   // Display no "release spirit" window at all
    PLAYER_LOCAL_FLAG_NO_PET_BAR                    = 0x00000020,   // CGPetInfo::IsPetBarUsed
    PLAYER_LOCAL_FLAG_OVERRIDE_CAMERA_MIN_HEIGHT    = 0x00000040,
    PLAYER_LOCAL_FLAG_NEWLY_BOOSTED_CHARACTER       = 0x00000080,
    PLAYER_LOCAL_FLAG_USING_PARTY_GARRISON          = 0x00000100,
    PLAYER_LOCAL_FLAG_CAN_USE_OBJECTS_MOUNTED       = 0x00000200,
    PLAYER_LOCAL_FLAG_CAN_VISIT_PARTY_GARRISON      = 0x00000400,
    PLAYER_LOCAL_FLAG_WAR_MODE                      = 0x00000800,
    PLAYER_LOCAL_FLAG_ACCOUNT_SECURED               = 0x00001000,   // Script_IsAccountSecured
    PLAYER_LOCAL_FLAG_OVERRIDE_TRANSPORT_SERVER_TIME= 0x00008000,
    PLAYER_LOCAL_FLAG_MENTOR_RESTRICTED             = 0x00020000,
    PLAYER_LOCAL_FLAG_WEEKLY_REWARD_AVAILABLE       = 0x00040000,
};

DEFINE_ENUM_FLAG(PlayerLocalFlags);

// used in PLAYER_FIELD_BYTES2 values
enum PlayerFieldByte2Flags
{
    PLAYER_FIELD_BYTE2_NONE                 = 0x00,
    PLAYER_FIELD_BYTE2_STEALTH              = 0x20,
    PLAYER_FIELD_BYTE2_INVISIBILITY_GLOW    = 0x40
};

enum MirrorTimerType
{
    FATIGUE_TIMER      = 0,
    BREATH_TIMER       = 1,
    FIRE_TIMER         = 2 // feign death
};
#define MAX_TIMERS      3
#define DISABLED_MIRROR_TIMER   -1

// 2^n values
enum PlayerExtraFlags
{
    // gm abilities
    PLAYER_EXTRA_GM_ON                      = 0x0001,
    PLAYER_EXTRA_ACCEPT_WHISPERS            = 0x0004,
    PLAYER_EXTRA_TAXICHEAT                  = 0x0008,
    PLAYER_EXTRA_GM_INVISIBLE               = 0x0010,
    PLAYER_EXTRA_GM_CHAT                    = 0x0020,       // Show GM badge in chat messages

    // other states
    PLAYER_EXTRA_PVP_DEATH                  = 0x0100,       // store PvP death status until corpse creating.

    // Character services markers
    PLAYER_EXTRA_HAS_RACE_CHANGED           = 0x0200,
    PLAYER_EXTRA_GRANTED_LEVELS_FROM_RAF    = 0x0400,
    PLAYER_EXTRA_LEVEL_BOOSTED              = 0x0800,
};

// 2^n values
enum AtLoginFlags
{
    AT_LOGIN_NONE              = 0x000,
    AT_LOGIN_RENAME            = 0x001,
    AT_LOGIN_RESET_SPELLS      = 0x002,
    AT_LOGIN_RESET_TALENTS     = 0x004,
    AT_LOGIN_CUSTOMIZE         = 0x008,
    AT_LOGIN_RESET_PET_TALENTS = 0x010,
    AT_LOGIN_FIRST             = 0x020,
    AT_LOGIN_CHANGE_FACTION    = 0x040,
    AT_LOGIN_CHANGE_RACE       = 0x080,
    AT_LOGIN_RESURRECT         = 0x100,
};

typedef std::map<uint32, QuestStatusData> QuestStatusMap;

struct QuestObjectiveStatusData
{
    QuestStatusMap::iterator QuestStatusItr;
    uint32 ObjectiveId;
};

using QuestObjectiveStatusMap = std::unordered_multimap<std::pair<QuestObjectiveType, int32>, QuestObjectiveStatusData>;

typedef std::set<uint32> RewardedQuestSet;

enum QuestSaveType
{
    QUEST_DEFAULT_SAVE_TYPE = 0,
    QUEST_DELETE_SAVE_TYPE,
    QUEST_FORCE_DELETE_SAVE_TYPE
};

//               quest
typedef std::map<uint32, QuestSaveType> QuestStatusSaveMap;

// Size of client completed quests bit map
enum PlayerQuestCompletedConstants
{
    QUESTS_COMPLETED_BITS_SIZE      = UF::size<decltype(UF::ActivePlayerData::QuestCompleted)>(),
    QUESTS_COMPLETED_BITS_PER_BLOCK = UF::size_of_value_type<decltype(UF::ActivePlayerData::QuestCompleted)>() * 8
};

enum PlayerQuestLogConstants
{
    MAX_QUEST_COUNTS    = UF::size<decltype(UF::QuestLog::ObjectiveProgress)>()
};

enum QuestSlotStateMask
{
    QUEST_STATE_NONE     = 0x0000,
    QUEST_STATE_COMPLETE = 0x0001,
    QUEST_STATE_FAIL     = 0x0002
};

enum SkillUpdateState
{
    SKILL_UNCHANGED     = 0,
    SKILL_CHANGED       = 1,
    SKILL_NEW           = 2,
    SKILL_DELETED       = 3
};

struct SkillStatusData
{
    SkillStatusData(uint8 _pos, SkillUpdateState _uState) : pos(_pos), uState(_uState)
    {
    }
    uint8 pos;
    SkillUpdateState uState;
};

typedef std::unordered_map<uint32, SkillStatusData> SkillStatusMap;

class Quest;
class Spell;
class Item;
class WorldSession;

enum PlayerSlots
{
    // first slot for item stored (in any way in player m_items data)
    PLAYER_SLOT_START           = 0,
    // last+1 slot for item stored (in any way in player m_items data)
    PLAYER_SLOT_END             = 141,
    PLAYER_SLOTS_COUNT          = (PLAYER_SLOT_END - PLAYER_SLOT_START)
};

static_assert(UF::size<decltype(UF::ActivePlayerData::InvSlots)>() == PLAYER_SLOT_END);

#define INVENTORY_SLOT_BAG_0    255
#define INVENTORY_DEFAULT_SIZE  16

enum EquipmentSlots : uint8                                 // 19 slots
{
    EQUIPMENT_SLOT_START        = 0,
    EQUIPMENT_SLOT_HEAD         = 0,
    EQUIPMENT_SLOT_NECK         = 1,
    EQUIPMENT_SLOT_SHOULDERS    = 2,
    EQUIPMENT_SLOT_BODY         = 3,
    EQUIPMENT_SLOT_CHEST        = 4,
    EQUIPMENT_SLOT_WAIST        = 5,
    EQUIPMENT_SLOT_LEGS         = 6,
    EQUIPMENT_SLOT_FEET         = 7,
    EQUIPMENT_SLOT_WRISTS       = 8,
    EQUIPMENT_SLOT_HANDS        = 9,
    EQUIPMENT_SLOT_FINGER1      = 10,
    EQUIPMENT_SLOT_FINGER2      = 11,
    EQUIPMENT_SLOT_TRINKET1     = 12,
    EQUIPMENT_SLOT_TRINKET2     = 13,
    EQUIPMENT_SLOT_BACK         = 14,
    EQUIPMENT_SLOT_MAINHAND     = 15,
    EQUIPMENT_SLOT_OFFHAND      = 16,
    EQUIPMENT_SLOT_RANGED       = 17,
    EQUIPMENT_SLOT_TABARD       = 18,
    EQUIPMENT_SLOT_END          = 19
};

enum ProfessionSlots : uint8
{
    PROFESSION_SLOT_PROFESSION1_TOOL     = 19,
    PROFESSION_SLOT_PROFESSION1_GEAR1    = 20,
    PROFESSION_SLOT_PROFESSION1_GEAR2    = 21,
    PROFESSION_SLOT_PROFESSION2_TOOL     = 22,
    PROFESSION_SLOT_PROFESSION2_GEAR1    = 23,
    PROFESSION_SLOT_PROFESSION2_GEAR2    = 24,
    PROFESSION_SLOT_COOKING_TOOL         = 25,
    PROFESSION_SLOT_COOKING_GEAR1        = 26,
    PROFESSION_SLOT_FISHING_TOOL         = 27,
    PROFESSION_SLOT_FISHING_GEAR1        = 28,
    PROFESSION_SLOT_FISHING_GEAR2        = 29,

    PROFESSION_SLOT_END,
    PROFESSION_SLOT_START                = PROFESSION_SLOT_PROFESSION1_TOOL,

    PROFESSION_SLOT_MAX_COUNT            = PROFESSION_SLOT_PROFESSION2_TOOL - PROFESSION_SLOT_PROFESSION1_TOOL
};

enum InventorySlots : uint8                                 // 4 slots
{
    INVENTORY_SLOT_BAG_START    = 30,
    INVENTORY_SLOT_BAG_END      = 34
};

enum ReagentBagSlots : uint8                                // 1 slot
{
    REAGENT_BAG_SLOT_START  = 34,
    REAGENT_BAG_SLOT_END    = 35
};

enum InventoryPackSlots : uint8                             // 24 slots
{
    INVENTORY_SLOT_ITEM_START   = 35,
    INVENTORY_SLOT_ITEM_END     = 59
};

enum BankItemSlots                                          // 28 slots
{
    BANK_SLOT_ITEM_START        = 59,
    BANK_SLOT_ITEM_END          = 87
};

enum BankBagSlots                                           // 7 slots
{
    BANK_SLOT_BAG_START         = 87,
    BANK_SLOT_BAG_END           = 94
};

enum BuyBackSlots                                           // 12 slots
{
    // stored in m_buybackitems
    BUYBACK_SLOT_START          = 94,
    BUYBACK_SLOT_END            = 106
};

enum KeyRingSlots                                           // 32 slots
{
    KEYRING_SLOT_START          = 106,
    KEYRING_SLOT_END            = 138,
};

enum ChildEquipmentSlots
{
    CHILD_EQUIPMENT_SLOT_START   = 138,
    CHILD_EQUIPMENT_SLOT_END     = 141,
};

// slots past 214 are guessed (unused in client)
enum EquipableSpellSlots
{
    EQUIPABLE_SPELL_OFFENSIVE_SLOT1 = 211,
    EQUIPABLE_SPELL_OFFENSIVE_SLOT2 = 212,
    EQUIPABLE_SPELL_OFFENSIVE_SLOT3 = 213,
    EQUIPABLE_SPELL_OFFENSIVE_SLOT4 = 214,
    EQUIPABLE_SPELL_UTILITY_SLOT1   = 215,
    EQUIPABLE_SPELL_UTILITY_SLOT2   = 216,
    EQUIPABLE_SPELL_UTILITY_SLOT3   = 217,
    EQUIPABLE_SPELL_UTILITY_SLOT4   = 218,
    EQUIPABLE_SPELL_DEFENSIVE_SLOT1 = 219,
    EQUIPABLE_SPELL_DEFENSIVE_SLOT2 = 220,
    EQUIPABLE_SPELL_DEFENSIVE_SLOT3 = 221,
    EQUIPABLE_SPELL_DEFENSIVE_SLOT4 = 222,
    EQUIPABLE_SPELL_WEAPON_SLOT1    = 223,
    EQUIPABLE_SPELL_WEAPON_SLOT2    = 224,
    EQUIPABLE_SPELL_WEAPON_SLOT3    = 225,
    EQUIPABLE_SPELL_WEAPON_SLOT4    = 226,
};

struct ItemPosCount
{
    ItemPosCount(uint16 _pos, uint32 _count) : pos(_pos), count(_count) { }
    bool isContainedIn(std::vector<ItemPosCount> const& vec) const;
    uint16 pos;
    uint32 count;
};
typedef std::vector<ItemPosCount> ItemPosCountVec;

enum class ItemSearchLocation
{
    Equipment       = 0x01,
    Inventory       = 0x02,
    Bank            = 0x04,
    ReagentBank     = 0x08,

    Default         = Equipment | Inventory,
    Everywhere      = Equipment | Inventory | Bank | ReagentBank
};

DEFINE_ENUM_FLAG(ItemSearchLocation);

enum class ItemSearchCallbackResult
{
    Stop,
    Continue
};

enum NewWorldReason
{
    NEW_WORLD_NORMAL    = 16,   // Normal map change
    NEW_WORLD_SEAMLESS  = 21,   // Teleport to another map without a loading screen, used for outdoor scenarios
};

enum InstanceResetWarningType
{
    RAID_INSTANCE_WARNING_HOURS     = 1,                    // WARNING! %s is scheduled to reset in %d hour(s).
    RAID_INSTANCE_WARNING_MIN       = 2,                    // WARNING! %s is scheduled to reset in %d minute(s)!
    RAID_INSTANCE_WARNING_MIN_SOON  = 3,                    // WARNING! %s is scheduled to reset in %d minute(s). Please exit the zone or you will be returned to your bind location!
    RAID_INSTANCE_WELCOME           = 4,                    // Welcome to %s. This raid instance is scheduled to reset in %s.
    RAID_INSTANCE_EXPIRED           = 5
};

// PLAYER_FIELD_ARENA_TEAM_INFO_1_1 offsets
enum ArenaTeamInfoType
{
    ARENA_TEAM_ID                = 0,
    ARENA_TEAM_TYPE              = 1,                       // new in 3.2 - team type?
    ARENA_TEAM_MEMBER            = 2,                       // 0 - captain, 1 - member
    ARENA_TEAM_GAMES_WEEK        = 3,
    ARENA_TEAM_GAMES_SEASON      = 4,
    ARENA_TEAM_WINS_SEASON       = 5,
    ARENA_TEAM_PERSONAL_RATING   = 6,
    ARENA_TEAM_END               = 7
};

enum TeleportToOptions
{
    TELE_TO_NONE                = 0x00,
    TELE_TO_GM_MODE             = 0x01,
    TELE_TO_NOT_LEAVE_TRANSPORT = 0x02,
    TELE_TO_NOT_LEAVE_COMBAT    = 0x04,
    TELE_TO_NOT_UNSUMMON_PET    = 0x08,
    TELE_TO_SPELL               = 0x10,
    TELE_TO_TRANSPORT_TELEPORT  = 0x20, // 3.3.5 only
    TELE_REVIVE_AT_TELEPORT     = 0x40,
    TELE_TO_SEAMLESS            = 0x80
};

DEFINE_ENUM_FLAG(TeleportToOptions);

/// Type of environmental damages
enum EnviromentalDamage : uint8
{
    DAMAGE_EXHAUSTED = 0,
    DAMAGE_DROWNING  = 1,
    DAMAGE_FALL      = 2,
    DAMAGE_LAVA      = 3,
    DAMAGE_SLIME     = 4,
    DAMAGE_FIRE      = 5,
    DAMAGE_FALL_TO_VOID = 6                                 // custom case for fall without durability loss
};

enum PlayedTimeIndex
{
    PLAYED_TIME_TOTAL = 0,
    PLAYED_TIME_LEVEL = 1
};

#define MAX_PLAYED_TIME_INDEX 2

// used at player loading query list preparing, and later result selection
enum PlayerLoginQueryIndex
{
    PLAYER_LOGIN_QUERY_LOAD_FROM,
    PLAYER_LOGIN_QUERY_LOAD_CUSTOMIZATIONS,
    PLAYER_LOGIN_QUERY_LOAD_GROUP,
    PLAYER_LOGIN_QUERY_LOAD_AURAS,
    PLAYER_LOGIN_QUERY_LOAD_AURA_EFFECTS,
    PLAYER_LOGIN_QUERY_LOAD_AURA_STORED_LOCATIONS,
    PLAYER_LOGIN_QUERY_LOAD_SPELLS,
    PLAYER_LOGIN_QUERY_LOAD_SPELL_FAVORITES,
    PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS,
    PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS_OBJECTIVES,
    PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS_OBJECTIVES_CRITERIA,
    PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS_OBJECTIVES_CRITERIA_PROGRESS,
    PLAYER_LOGIN_QUERY_LOAD_DAILY_QUEST_STATUS,
    PLAYER_LOGIN_QUERY_LOAD_REPUTATION,
    PLAYER_LOGIN_QUERY_LOAD_INVENTORY,
    PLAYER_LOGIN_QUERY_LOAD_MAILS,
    PLAYER_LOGIN_QUERY_LOAD_MAIL_ITEMS,
    PLAYER_LOGIN_QUERY_LOAD_SOCIAL_LIST,
    PLAYER_LOGIN_QUERY_LOAD_HOME_BIND,
    PLAYER_LOGIN_QUERY_LOAD_SPELL_COOLDOWNS,
    PLAYER_LOGIN_QUERY_LOAD_SPELL_CHARGES,
    PLAYER_LOGIN_QUERY_LOAD_DECLINED_NAMES,
    PLAYER_LOGIN_QUERY_LOAD_GUILD,
    PLAYER_LOGIN_QUERY_LOAD_ARENA_INFO,
    PLAYER_LOGIN_QUERY_LOAD_ACHIEVEMENTS,
    PLAYER_LOGIN_QUERY_LOAD_CRITERIA_PROGRESS,
    PLAYER_LOGIN_QUERY_LOAD_EQUIPMENT_SETS,
    PLAYER_LOGIN_QUERY_LOAD_TRANSMOG_OUTFITS,
    PLAYER_LOGIN_QUERY_LOAD_BG_DATA,
    PLAYER_LOGIN_QUERY_LOAD_GLYPHS,
    PLAYER_LOGIN_QUERY_LOAD_TALENTS,
    PLAYER_LOGIN_QUERY_LOAD_ACCOUNT_DATA,
    PLAYER_LOGIN_QUERY_LOAD_SKILLS,
    PLAYER_LOGIN_QUERY_LOAD_WEEKLY_QUEST_STATUS,
    PLAYER_LOGIN_QUERY_LOAD_RANDOM_BG,
    PLAYER_LOGIN_QUERY_LOAD_BANNED,
    PLAYER_LOGIN_QUERY_LOAD_QUEST_STATUS_REW,
    PLAYER_LOGIN_QUERY_LOAD_INSTANCE_LOCK_TIMES,
    PLAYER_LOGIN_QUERY_LOAD_SEASONAL_QUEST_STATUS,
    PLAYER_LOGIN_QUERY_LOAD_MONTHLY_QUEST_STATUS,
    PLAYER_LOGIN_QUERY_LOAD_VOID_STORAGE,
    PLAYER_LOGIN_QUERY_LOAD_CURRENCY,
    PLAYER_LOGIN_QUERY_LOAD_CUF_PROFILES,
    PLAYER_LOGIN_QUERY_LOAD_CORPSE_LOCATION,
    PLAYER_LOGIN_QUERY_LOAD_PET_SLOTS,
    PLAYER_LOGIN_QUERY_LOAD_TRAIT_ENTRIES,
    PLAYER_LOGIN_QUERY_LOAD_TRAIT_CONFIGS,
    MAX_PLAYER_LOGIN_QUERY
};

enum PlayerDelayedOperations
{
    DELAYED_SAVE_PLAYER         = 0x01,
    DELAYED_RESURRECT_PLAYER    = 0x02,
    DELAYED_SPELL_CAST_DESERTER = 0x04,
    DELAYED_BG_MOUNT_RESTORE    = 0x08,                     ///< Flag to restore mount state after teleport from BG
    DELAYED_BG_TAXI_RESTORE     = 0x10,                     ///< Flag to restore taxi state after teleport from BG
    DELAYED_BG_GROUP_RESTORE    = 0x20,                     ///< Flag to restore group state after teleport from BG
    DELAYED_END
};

// Player summoning auto-decline time (in secs)
#define MAX_PLAYER_SUMMON_DELAY                   (2*MINUTE)
// Maximum money amount : 2^31 - 1
TC_GAME_API extern uint64 const MAX_MONEY_AMOUNT;

enum CharDeleteMethod
{
    CHAR_DELETE_REMOVE = 0,                      // Completely remove from the database
    CHAR_DELETE_UNLINK = 1                       // The character gets unlinked from the account,
                                                 // the name gets freed up and appears as deleted ingame
};

enum ReferAFriendError
{
    ERR_REFER_A_FRIEND_NONE                              = 0,
    ERR_REFER_A_FRIEND_NOT_REFERRED_BY                   = 1,
    ERR_REFER_A_FRIEND_TARGET_TOO_HIGH                   = 2,
    ERR_REFER_A_FRIEND_INSUFFICIENT_GRANTABLE_LEVELS     = 3,
    ERR_REFER_A_FRIEND_TOO_FAR                           = 4,
    ERR_REFER_A_FRIEND_DIFFERENT_FACTION                 = 5,
    ERR_REFER_A_FRIEND_NOT_NOW                           = 6,
    ERR_REFER_A_FRIEND_GRANT_LEVEL_MAX_I                 = 7,
    ERR_REFER_A_FRIEND_NO_TARGET                         = 8,
    ERR_REFER_A_FRIEND_NOT_IN_GROUP                      = 9,
    ERR_REFER_A_FRIEND_SUMMON_LEVEL_MAX_I                = 10,
    ERR_REFER_A_FRIEND_SUMMON_COOLDOWN                   = 11,
    ERR_REFER_A_FRIEND_INSUF_EXPAN_LVL                   = 12,
    ERR_REFER_A_FRIEND_SUMMON_OFFLINE_S                  = 13,
    ERR_REFER_A_FRIEND_NO_XREALM                         = 14,
    ERR_REFER_A_FRIEND_MAP_INCOMING_TRANSFER_NOT_ALLOWED = 15
};

enum PlayerCommandStates
{
    CHEAT_NONE      = 0x00,
    CHEAT_GOD       = 0x01,
    CHEAT_CASTTIME  = 0x02,
    CHEAT_COOLDOWN  = 0x04,
    CHEAT_POWER     = 0x08,
    CHEAT_WATERWALK = 0x10
};

enum PlayerLogXPReason : uint8
{
    LOG_XP_REASON_KILL    = 0,
    LOG_XP_REASON_NO_KILL = 1
};

enum class DisplayToastType : uint8
{
    NewItem     = 0,
    NewCurrency = 1,
    Money       = 2,
    Honor       = 3
};

enum class DisplayToastMethod : uint8
{
    DoNotDisplay            = 0,
    Loot                    = 1,
    PetBattle               = 2,
    PersonalLoot            = 3,
    GarrisonMissionLoot     = 4,
    QuestUpgrade            = 5,
    QuestUpgradeEpic        = 6,
    Shipment                = 7,
    GarrisonMissionSalvage  = 8,
    PvPFactionReward        = 9,
    GarrisonCurrency        = 10,
    LessAwesomeLoot         = 11,
    UpgradedLoot            = 12,
    LegendaryLoot           = 13,
    InvasionLoot            = 14,
    Default                 = 15,
    QuestComplete           = 16,
    RatedPvPReward          = 17,
    CorruptedLoot           = 19
};

class Player;

/// Holder for Battleground data
struct BGData
{
    BGData() : bgInstanceID(0), bgTypeID(BATTLEGROUND_TYPE_NONE), bgAfkReportedCount(0), bgAfkReportedTimer(0),
        bgTeam(TEAM_OTHER), mountSpell(0), queueId(BATTLEGROUND_QUEUE_NONE) { ClearTaxiPath(); }

    uint32 bgInstanceID;                    ///< This variable is set to bg->m_InstanceID,
                                            ///  when player is teleported to BG - (it is battleground's GUID)
    BattlegroundTypeId bgTypeID;

    GuidSet            bgAfkReporter;
    uint8              bgAfkReportedCount;
    time_t             bgAfkReportedTimer;

    Team bgTeam;                          ///< What side the player will be added to

    uint32 mountSpell;
    uint32 taxiPath[2];

    WorldLocation joinPos;                  ///< From where player entered BG
    BattlegroundQueueTypeId queueId;

    void ClearTaxiPath()     { taxiPath[0] = taxiPath[1] = 0; }
    bool HasTaxiPath() const { return taxiPath[0] && taxiPath[1]; }
};

struct VoidStorageItem
{
    VoidStorageItem() : ItemId(0), ItemEntry(0), FixedScalingLevel(0), Context(ItemContext::NONE) { }
    VoidStorageItem(uint64 id, uint32 entry, ObjectGuid const& creator, uint32 fixedScalingLevel, ItemRandomProperties randomProperties, ItemContext context) :
        ItemId(id), ItemEntry(entry), CreatorGuid(creator), FixedScalingLevel(fixedScalingLevel), RandomProperties(randomProperties), Context(context) { }
    VoidStorageItem(VoidStorageItem&& vsi) noexcept : ItemId(vsi.ItemId), ItemEntry(vsi.ItemEntry), CreatorGuid(vsi.CreatorGuid),
        FixedScalingLevel(vsi.FixedScalingLevel), RandomProperties(vsi.RandomProperties), Context(vsi.Context) { }

    uint64 ItemId;
    uint32 ItemEntry;
    ObjectGuid CreatorGuid;
    uint32 FixedScalingLevel;
    ItemRandomProperties RandomProperties;
    ItemContext Context;
};

struct ResurrectionData
{
    ObjectGuid GUID;
    WorldLocation Location;
    uint32 Health;
    uint32 Mana;
    uint32 Aura;
};

struct GroupUpdateCounter
{
    ObjectGuid GroupGuid;
    int32 UpdateSequenceNumber;
};

struct TC_GAME_API SpecializationInfo
{
    SpecializationInfo() : ResetTalentsCost(0), ResetTalentsTime(0), ActiveGroup(0), BonusGroups(0)
    {
        Glyphs.fill({});
    }

    PlayerTalentMap Talents[MAX_SPECIALIZATIONS];
    std::array<std::array<uint32, MAX_GLYPH_SLOT_INDEX>, MAX_SPECIALIZATIONS > Glyphs;
    uint32 ResetTalentsCost;
    time_t ResetTalentsTime;
    uint8 ActiveGroup;
    uint8 BonusGroups;

private:
    SpecializationInfo(SpecializationInfo const&) = delete;
    SpecializationInfo& operator=(SpecializationInfo const&) = delete;
};

uint32 constexpr PLAYER_MAX_HONOR_LEVEL = 500;
uint8 constexpr PLAYER_LEVEL_MIN_HONOR = 10;
uint32 constexpr SPELL_PVP_RULES_ENABLED = 134735;
float constexpr MAX_AREA_SPIRIT_HEALER_RANGE = 20.0f;

enum class ZonePVPTypeOverride : uint32
{
    None        = 0,
    Friendly    = 1,
    Hostile     = 2,
    Contested   = 3,
    Combat      = 4
};

class TC_GAME_API Player final : public Unit, public GridObject<Player>
{
    friend class WorldSession;
    friend class CinematicMgr;
    friend class RestMgr;
    friend void AddItemToUpdateQueueOf(Item* item, Player* player);
    friend void RemoveItemFromUpdateQueueOf(Item* item, Player* player);
    public:
        explicit Player(WorldSession* session);
        ~Player();

        PlayerAI* AI() const { return reinterpret_cast<PlayerAI*>(GetAI()); }

        void CleanupsBeforeDelete(bool finalCleanup = true) override;

        void AddToWorld() override;
        void RemoveFromWorld() override;

        void SetObjectScale(float scale) override;

        bool TeleportTo(uint32 mapid, float x, float y, float z, float orientation, TeleportToOptions options = TELE_TO_NONE, Optional<uint32> instanceId = {});
        bool TeleportTo(WorldLocation const& loc, TeleportToOptions options = TELE_TO_NONE, Optional<uint32> instanceId = {});
        bool TeleportToBGEntryPoint();

        bool HasSummonPending() const;
        void SendSummonRequestFrom(Unit* summoner);
        void SummonIfPossible(bool agree);

        bool Create(ObjectGuid::LowType guidlow, WorldPackets::Character::CharacterCreateInfo const* createInfo);

        void Update(uint32 time) override;

        bool IsImmunedToSpellEffect(SpellInfo const* spellInfo, SpellEffectInfo const& spellEffectInfo, WorldObject const* caster, bool requireImmunityPurgesEffectAttribute = false) const override;

        bool IsInAreaTriggerRadius(AreaTriggerEntry const* trigger) const;

        void SendInitialPacketsBeforeAddToMap();
        void SendInitialPacketsAfterAddToMap();
        void SendSupercededSpell(uint32 oldSpell, uint32 newSpell) const;
        void SendTransferAborted(uint32 mapid, TransferAbortReason reason, uint8 arg = 0, int32 mapDifficultyXConditionID = 0) const;

        bool CanInteractWithQuestGiver(Object* questGiver) const;
        Creature* GetNPCIfCanInteractWith(ObjectGuid const& guid, NPCFlags npcFlags, NPCFlags2 npcFlags2) const;
        GameObject* GetGameObjectIfCanInteractWith(ObjectGuid const& guid) const;
        GameObject* GetGameObjectIfCanInteractWith(ObjectGuid const& guid, GameobjectTypes type) const;

        void ToggleAFK();
        void ToggleDND();
        bool isAFK() const { return HasPlayerFlag(PLAYER_FLAGS_AFK); }
        bool isDND() const { return HasPlayerFlag(PLAYER_FLAGS_DND); }
        uint16 GetChatFlags() const;
        std::string autoReplyMsg;

        int64 GetBarberShopCost(Trinity::IteratorPair<UF::ChrCustomizationChoice const*> newCustomizations) const;

        uint32 _questRewardedTalentPoints;

        PlayerSocial* GetSocial() const { return m_social; }
        void RemoveSocial();

        PlayerTaxi m_taxi;
        void InitTaxiNodesForLevel() { m_taxi.InitTaxiNodesForLevel(GetRace(), GetClass(), GetLevel()); }
        bool ActivateTaxiPathTo(std::vector<uint32> const& nodes, Creature* npc = nullptr, uint32 spellid = 0, uint32 preferredMountDisplay = 0);
        bool ActivateTaxiPathTo(uint32 taxi_path_id, uint32 spellid = 0);
        void FinishTaxiFlight();
        void CleanupAfterTaxiFlight();
        void ContinueTaxiFlight() const;

        bool IsDeveloper() const { return HasPlayerFlag(PLAYER_FLAGS_DEVELOPER); }
        void SetDeveloper(bool on) { if (on) SetPlayerFlag(PLAYER_FLAGS_DEVELOPER); else RemovePlayerFlag(PLAYER_FLAGS_DEVELOPER); }
        bool isAcceptWhispers() const { return (m_ExtraFlags & PLAYER_EXTRA_ACCEPT_WHISPERS) != 0; }
        void SetAcceptWhispers(bool on) { if (on) m_ExtraFlags |= PLAYER_EXTRA_ACCEPT_WHISPERS; else m_ExtraFlags &= ~PLAYER_EXTRA_ACCEPT_WHISPERS; }
        bool IsGameMaster() const { return (m_ExtraFlags & PLAYER_EXTRA_GM_ON) != 0; }
        bool IsGameMasterAcceptingWhispers() const { return IsGameMaster() && isAcceptWhispers(); }
        bool CanBeGameMaster() const;
        void SetGameMaster(bool on);
        bool isGMChat() const { return (m_ExtraFlags & PLAYER_EXTRA_GM_CHAT) != 0; }
        void SetGMChat(bool on) { if (on) m_ExtraFlags |= PLAYER_EXTRA_GM_CHAT; else m_ExtraFlags &= ~PLAYER_EXTRA_GM_CHAT; }
        bool isTaxiCheater() const { return (m_ExtraFlags & PLAYER_EXTRA_TAXICHEAT) != 0; }
        void SetTaxiCheater(bool on) { if (on) m_ExtraFlags |= PLAYER_EXTRA_TAXICHEAT; else m_ExtraFlags &= ~PLAYER_EXTRA_TAXICHEAT; }
        bool isGMVisible() const { return !(m_ExtraFlags & PLAYER_EXTRA_GM_INVISIBLE); }
        void SetGMVisible(bool on);
        void SetPvPDeath(bool on) { if (on) m_ExtraFlags |= PLAYER_EXTRA_PVP_DEATH; else m_ExtraFlags &= ~PLAYER_EXTRA_PVP_DEATH; }
        bool HasRaceChanged() const { return (m_ExtraFlags & PLAYER_EXTRA_HAS_RACE_CHANGED) != 0; }
        void SetHasRaceChanged() { m_ExtraFlags |= PLAYER_EXTRA_HAS_RACE_CHANGED; }
        bool HasBeenGrantedLevelsFromRaF() const { return (m_ExtraFlags & PLAYER_EXTRA_GRANTED_LEVELS_FROM_RAF) != 0; }
        void SetBeenGrantedLevelsFromRaF() { m_ExtraFlags |= PLAYER_EXTRA_GRANTED_LEVELS_FROM_RAF; }
        bool HasLevelBoosted() const { return (m_ExtraFlags & PLAYER_EXTRA_LEVEL_BOOSTED) != 0; }
        void SetHasLevelBoosted() { m_ExtraFlags |= PLAYER_EXTRA_LEVEL_BOOSTED; }

        uint32 GetXP() const { return m_activePlayerData->XP; }
        uint32 GetXPForNextLevel() const { return m_activePlayerData->NextLevelXP; }
        void SetXP(uint32 xp);
        void GiveXP(uint32 xp, Unit* victim, float group_rate=1.0f);
        void GiveLevel(uint8 level);
        bool IsMaxLevel() const;

        void InitStatsForLevel(bool reapplyMods = false);

        // .cheat command related
        bool GetCommandStatus(uint32 command) const { return (_activeCheats & command) != 0; }
        void SetCommandStatusOn(uint32 command) { _activeCheats |= command; }
        void SetCommandStatusOff(uint32 command) { _activeCheats &= ~command; }

        // Played Time Stuff
        time_t m_logintime;
        time_t m_Last_tick;
        std::array<uint32, MAX_PLAYED_TIME_INDEX> m_Played_time;
        uint32 GetTotalPlayedTime() const { return m_Played_time[PLAYED_TIME_TOTAL]; }
        uint32 GetLevelPlayedTime() const { return m_Played_time[PLAYED_TIME_LEVEL]; }

        Gender GetNativeGender() const override { return Gender(*m_playerData->NativeSex); }
        void SetNativeGender(Gender gender) override { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::NativeSex), gender); }

        void setDeathState(DeathState s) override;                   // overwrite Unit::setDeathState

        PetStable* GetPetStable() { return m_petStable.get(); }
        PetStable& GetOrInitPetStable();
        PetStable const* GetPetStable() const { return m_petStable.get(); }
        void AddPetToUpdateFields(PetStable::PetInfo const& pet, PetSaveMode slot, PetStableFlags flags);
        void SetPetSlot(uint32 petNumber, PetSaveMode dstPetSlot);
        ObjectGuid GetStableMaster() const;
        void SetStableMaster(ObjectGuid stableMaster);

        Pet* GetPet() const;
        Pet* SummonPet(uint32 entry, Optional<PetSaveMode> slot, float x, float y, float z, float ang, uint32 despwtime, bool* isNew = nullptr);
        void RemovePet(Pet* pet, PetSaveMode mode, bool returnreagent = false);
        void SendTameFailure(PetTameResult result);

        // pet auras
        std::unordered_set<PetAura const*> m_petAuras;
        void AddPetAura(PetAura const* petSpell);
        void RemovePetAura(PetAura const* petSpell);

        Creature* GetSummonedBattlePet();
        void SetBattlePetData(BattlePets::BattlePet const* pet = nullptr);

        /// Handles said message in regular chat based on declared language and in config pre-defined Range.
        void Say(std::string_view text, Language language, WorldObject const* = nullptr) override;
        void Say(uint32 textId, WorldObject const* target = nullptr) override;
        /// Handles yelled message in regular chat based on declared language and in config pre-defined Range.
        void Yell(std::string_view text, Language language, WorldObject const* = nullptr) override;
        void Yell(uint32 textId, WorldObject const* target = nullptr) override;
        /// Outputs an universal text which is supposed to be an action.
        void TextEmote(std::string_view text, WorldObject const* = nullptr, bool = false) override;
        void TextEmote(uint32 textId, WorldObject const* target = nullptr, bool isBossEmote = false) override;
        /// Handles whispers from Addons and players based on sender, receiver's guid and language.
        void Whisper(std::string_view text, Language language, Player* receiver, bool = false) override;
        void Whisper(uint32 textId, Player* target, bool isBossWhisper = false) override;
        void WhisperAddon(std::string const& text, std::string const& prefix, bool isLogged, Player* receiver);

        bool CanUnderstandLanguage(Language language) const;

        /*********************************************************/
        /***                    STORAGE SYSTEM                 ***/
        /*********************************************************/

        /**
         * @brief Iterate over each item in the player storage
         * @tparam T ItemSearchCallbackResult ItemCallback(Item* item)
         * @param location Locations of the items to iterate over
         * @param callback Callback called on each item. Will continue as long as it returns ItemSearchCallbackResult::Continue
         */
        template <typename T>
        bool ForEachItem(ItemSearchLocation location, T callback) const
        {
            EnumFlag<ItemSearchLocation> flag = location;

            if (flag.HasFlag(ItemSearchLocation::Equipment))
            {
                for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
                    if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                        if (callback(pItem) == ItemSearchCallbackResult::Stop)
                            return false;

                for (uint8 i = PROFESSION_SLOT_START; i < PROFESSION_SLOT_END; ++i)
                    if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                        if (callback(pItem) == ItemSearchCallbackResult::Stop)
                            return false;
            }

            if (flag.HasFlag(ItemSearchLocation::Inventory))
            {
                uint8 inventoryEnd = INVENTORY_SLOT_ITEM_START + GetInventorySlotCount();
                for (uint8 i = INVENTORY_SLOT_BAG_START; i < inventoryEnd; ++i)
                    if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                        if (callback(pItem) == ItemSearchCallbackResult::Stop)
                            return false;

                for (uint8 i = KEYRING_SLOT_START; i < KEYRING_SLOT_END; ++i)
                    if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                        if (callback(pItem) == ItemSearchCallbackResult::Stop)
                            return false;

                for (uint8 i = CHILD_EQUIPMENT_SLOT_START; i < CHILD_EQUIPMENT_SLOT_END; ++i)
                    if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                        if (callback(pItem) == ItemSearchCallbackResult::Stop)
                            return false;

                for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
                    if (Bag* pBag = GetBagByPos(i))
                        for (uint32 j = 0; j < GetBagSize(pBag); ++j)
                            if (Item* pItem = GetItemInBag(pBag, j))
                                if (callback(pItem) == ItemSearchCallbackResult::Stop)
                                    return false;
            }

            if (flag.HasFlag(ItemSearchLocation::Bank))
            {
                for (uint8 i = BANK_SLOT_ITEM_START; i < BANK_SLOT_BAG_END; ++i)
                    if (Item* pItem = GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                        if (callback(pItem) == ItemSearchCallbackResult::Stop)
                            return false;

                for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
                    if (Bag* pBag = GetBagByPos(i))
                        for (uint32 j = 0; j < GetBagSize(pBag); ++j)
                            if (Item* pItem = GetItemInBag(pBag, j))
                                if (callback(pItem) == ItemSearchCallbackResult::Stop)
                                    return false;
            }

            if (flag.HasFlag(ItemSearchLocation::ReagentBank))
            {
                for (uint8 i = REAGENT_BAG_SLOT_START; i < REAGENT_BAG_SLOT_END; ++i)
                    if (Bag* bag = GetBagByPos(i))
                        for (uint32 j = 0; j < GetBagSize(bag); ++j)
                            if (Item* pItem = GetItemInBag(bag, j))
                                if (callback(pItem) == ItemSearchCallbackResult::Stop)
                                    return false;
            }

            return true;
        }

    public:
        void UpdateAverageItemLevelTotal();
        void UpdateAverageItemLevelEquipped();

        uint8 FindEquipSlot(Item const* item, uint32 slot, bool swap) const;
        uint32 GetFreeInventorySlotCount(EnumFlag<ItemSearchLocation> location = ItemSearchLocation::Inventory) const;
        uint32 GetItemCount(uint32 item, bool inBankAlso = false, Item* skipItem = nullptr) const;
        uint32 GetItemCountWithLimitCategory(uint32 limitCategory, Item* skipItem = nullptr) const;
        Item* GetItemByGuid(ObjectGuid guid) const;
        Item* GetItemByEntry(uint32 entry, ItemSearchLocation where = ItemSearchLocation::Default) const;
        std::vector<Item*> GetItemListByEntry(uint32 entry, bool inBankAlso = false) const;
        Item* GetItemByPos(uint16 pos) const;
        Item* GetItemByPos(uint8 bag, uint8 slot) const;
        Item* GetUseableItemByPos(uint8 bag, uint8 slot) const;
        Bag*  GetBagByPos(uint8 slot) const;
        std::vector<Item*> GetCraftingReagentItemsToDeposit();
        uint32 GetFreeInventorySpace() const;
        Item* GetWeaponForAttack(WeaponAttackType attackType, bool useable = false) const;
        Item* GetShield(bool useable = false) const;
        static WeaponAttackType GetAttackBySlot(uint8 slot, InventoryType inventoryType);        // MAX_ATTACK if not weapon slot
        std::vector<Item*>& GetItemUpdateQueue() { return m_itemUpdateQueue; }
        static bool IsInventoryPos(uint16 pos) { return IsInventoryPos(pos >> 8, pos & 255); }
        static bool IsInventoryPos(uint8 bag, uint8 slot);
        static bool IsEquipmentPos(uint16 pos) { return IsEquipmentPos(pos >> 8, pos & 255); }
        static bool IsEquipmentPos(uint8 bag, uint8 slot);
        static bool IsBagPos(uint16 pos);
        static bool IsBankPos(uint16 pos) { return IsBankPos(pos >> 8, pos & 255); }
        static bool IsBankPos(uint8 bag, uint8 slot);
        static bool IsChildEquipmentPos(uint16 pos) { return IsChildEquipmentPos(pos >> 8, pos & 255); }
        static bool IsChildEquipmentPos(uint8 bag, uint8 slot);
        bool IsValidPos(uint16 pos, bool explicit_pos) const { return IsValidPos(pos >> 8, pos & 255, explicit_pos); }
        bool IsValidPos(uint8 bag, uint8 slot, bool explicit_pos) const;
        uint8 GetInventorySlotCount() const { return m_activePlayerData->NumBackpackSlots; }
        void SetInventorySlotCount(uint8 slots);
        uint8 GetBankBagSlotCount() const { return m_playerData->NumBankSlots; }
        void SetBankBagSlotCount(uint8 count) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::NumBankSlots), count); }
        bool HasItemCount(uint32 item, uint32 count = 1, bool inBankAlso = false) const;
        bool HasItemFitToSpellRequirements(SpellInfo const* spellInfo, Item const* ignoreItem = nullptr) const;
        bool CanNoReagentCast(SpellInfo const* spellInfo) const;
        void SetNoRegentCostMask(flag128 mask)
        {
            for (uint8 i = 0; i < 4; ++i)
                SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::NoReagentCostMask, i), mask[i]);
        }
        bool HasItemOrGemWithIdEquipped(uint32 item, uint32 count, uint8 except_slot = NULL_SLOT) const;
        bool HasItemWithLimitCategoryEquipped(uint32 limitCategory, uint32 count, uint8 except_slot = NULL_SLOT) const;
        bool HasGemWithLimitCategoryEquipped(uint32 limitCategory, uint32 count, uint8 except_slot = NULL_SLOT) const;
        InventoryResult CanTakeMoreSimilarItems(Item* pItem, uint32* offendingItemId = nullptr) const;
        InventoryResult CanTakeMoreSimilarItems(uint32 entry, uint32 count, uint32* offendingItemId = nullptr) const { return CanTakeMoreSimilarItems(entry, count, nullptr, nullptr, offendingItemId); }
        InventoryResult CanStoreNewItem(uint8 bag, uint8 slot, ItemPosCountVec& dest, uint32 item, uint32 count, uint32* no_space_count = nullptr) const;
        InventoryResult CanStoreItem(uint8 bag, uint8 slot, ItemPosCountVec& dest, Item* pItem, bool swap = false) const;
        InventoryResult CanStoreItems(Item** items, int count, uint32* offendingItemId) const;
        InventoryResult CanEquipNewItem(uint8 slot, uint16& dest, uint32 item, bool swap) const;
        InventoryResult CanEquipItem(uint8 slot, uint16& dest, Item* pItem, bool swap, bool not_loading = true) const;

        InventoryResult CanEquipUniqueItem(Item* pItem, uint8 except_slot = NULL_SLOT, uint32 limit_count = 1) const;
        InventoryResult CanEquipUniqueItem(ItemTemplate const* itemProto, uint8 except_slot = NULL_SLOT, uint32 limit_count = 1) const;
        InventoryResult CanUnequipItems(uint32 item, uint32 count) const;
        InventoryResult CanUnequipItem(uint16 src, bool swap) const;
        InventoryResult CanBankItem(uint8 bag, uint8 slot, ItemPosCountVec& dest, Item* pItem, bool swap, bool not_loading = true) const;
        InventoryResult CanUseItem(Item* pItem, bool not_loading = true) const;
        bool HasItemTotemCategory(uint32 TotemCategory) const;
        InventoryResult CanUseItem(ItemTemplate const* pItem, bool skipRequiredLevelCheck = false) const;
        InventoryResult CanRollNeedForItem(ItemTemplate const* item, Map const* map, bool restrictOnlyLfg) const;
        Item* StoreNewItem(ItemPosCountVec const& pos, uint32 itemId, bool update, ItemRandomProperties randomProperties = ItemRandomProperties(), GuidSet const& allowedLooters = GuidSet(),
            ItemContext context = ItemContext::NONE, bool addToCollection = true);
        Item* StoreItem(ItemPosCountVec const& pos, Item* pItem, bool update);
        Item* EquipNewItem(uint16 pos, uint32 item, ItemContext context, bool update);
        Item* EquipItem(uint16 pos, Item* pItem, bool update);
        void AutoUnequipOffhandIfNeed(bool force = false);
        bool StoreNewItemInBestSlots(uint32 itemId, uint32 amount, ItemContext context);
        void AutoStoreLoot(uint8 bag, uint8 slot, uint32 loot_id, LootStore const& store, ItemContext context = ItemContext::NONE, bool broadcast = false, bool createdByPlayer = false);
        void AutoStoreLoot(uint32 loot_id, LootStore const& store, ItemContext context = ItemContext::NONE, bool broadcast = false, bool createdByPlayer = false) { AutoStoreLoot(NULL_BAG, NULL_SLOT, loot_id, store, context, broadcast, createdByPlayer); }
        void StoreLootItem(ObjectGuid lootWorldObjectGuid, uint8 lootSlot, Loot* loot, AELootResult* aeResult = nullptr);

        InventoryResult CanTakeMoreSimilarItems(uint32 entry, uint32 count, Item* pItem, uint32* no_space_count = nullptr, uint32* offendingItemId = nullptr) const;
        InventoryResult CanStoreItem(uint8 bag, uint8 slot, ItemPosCountVec& dest, uint32 entry, uint32 count, Item* pItem = nullptr, bool swap = false, uint32* no_space_count = nullptr) const;

        void AddRefundReference(ObjectGuid it);
        void DeleteRefundReference(ObjectGuid it);

        /// Send full data about all currencies to client
        void SendCurrencies() const;
        /// Send conquest currency points and their cap week/arena
        void SendPvpRewards() const;
        /// Initialize currency amount for custom initialization at create character
        void SetCreateCurrency(uint32 id, uint32 amount);
        /// Modify currency amount
        void ModifyCurrency(uint32 id, int32 amount, CurrencyGainSource gainSource = CurrencyGainSource::Cheat, CurrencyDestroyReason destroyReason = CurrencyDestroyReason::Cheat);
        void AddCurrency(uint32 id, uint32 amount, CurrencyGainSource gainSource = CurrencyGainSource::Cheat);
        void RemoveCurrency(uint32 id, int32 amount, CurrencyDestroyReason destroyReason = CurrencyDestroyReason::Cheat);
        /// Increase currency cap
        void IncreaseCurrencyCap(uint32 id, uint32 amount);
        /// Reset weekly quantity
        void ResetCurrencyWeekCap();

        uint32 GetCurrencyQuantity(uint32 id) const;
        uint32 GetCurrencyWeeklyQuantity(uint32 id) const;
        uint32 GetCurrencyTrackedQuantity(uint32 id) const;
        uint32 GetCurrencyIncreasedCapQuantity(uint32 id) const;
        uint32 GetCurrencyMaxQuantity(CurrencyTypesEntry const* currency, bool onLoad = false, bool onUpdateVersion = false) const;
        uint32 GetCurrencyWeeklyCap(uint32 id) const;
        uint32 GetCurrencyWeeklyCap(CurrencyTypesEntry const* currency) const;
        bool HasCurrency(uint32 id, uint32 amount) const;

        void SetInvSlot(uint32 slot, ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::InvSlots, slot), guid); }

        void ApplyEquipCooldown(Item* pItem);
        void QuickEquipItem(uint16 pos, Item* pItem);
        void VisualizeItem(uint8 slot, Item* pItem);
        void SetVisibleItemSlot(uint8 slot, Item* pItem);
        Item* BankItem(ItemPosCountVec const& dest, Item* pItem, bool update);
        void RemoveItem(uint8 bag, uint8 slot, bool update);
        void MoveItemFromInventory(uint8 bag, uint8 slot, bool update);
                                                            // in trade, auction, guild bank, mail....
        void MoveItemToInventory(ItemPosCountVec const& dest, Item* pItem, bool update, bool in_characterInventoryDB = false);
                                                            // in trade, guild bank, mail....
        void RemoveItemDependentAurasAndCasts(Item* pItem);
        void DestroyItem(uint8 bag, uint8 slot, bool update);
        uint32 DestroyItemCount(uint32 item, uint32 count, bool update, bool unequip_check = false);
        void DestroyItemCount(Item* item, uint32& count, bool update);
        void DestroyConjuredItems(bool update);
        void DestroyZoneLimitedItem(bool update, uint32 new_zone);
        void SplitItem(uint16 src, uint16 dst, uint32 count);
        void SwapItem(uint16 src, uint16 dst);
        void AddItemToBuyBackSlot(Item* pItem);
        void SetBuybackPrice(uint32 slot, uint32 price) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::BuybackPrice, slot), price); }
        void SetBuybackTimestamp(uint32 slot, time_t timestamp) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::BuybackTimestamp, slot), timestamp); }
        Item* GetItemFromBuyBackSlot(uint32 slot);
        void RemoveItemFromBuyBackSlot(uint32 slot, bool del);
        void SendEquipError(InventoryResult msg, Item const* item1 = nullptr, Item const* item2 = nullptr, uint32 itemId = 0) const;
        void SendBuyError(BuyResult msg, Creature* creature, uint32 item, uint32 param) const;
        void SendSellError(SellResult msg, Creature* creature, ObjectGuid guid) const;
        void AddWeaponProficiency(uint32 newflag) { m_WeaponProficiency |= newflag; }
        void AddArmorProficiency(uint32 newflag) { m_ArmorProficiency |= newflag; }
        uint32 GetWeaponProficiency() const { return m_WeaponProficiency; }
        uint32 GetArmorProficiency() const { return m_ArmorProficiency; }
        bool IsUseEquipedWeapon(bool mainhand) const;
        bool IsTwoHandUsed() const;
        bool IsUsingTwoHandedWeaponInOneHand() const;
        void SendNewItem(Item* item, uint32 quantity, bool received, bool created, bool broadcast = false, uint32 dungeonEncounterId = 0);
        bool BuyItemFromVendorSlot(ObjectGuid vendorguid, uint32 vendorslot, uint32 item, uint8 count, uint8 bag, uint8 slot);
        bool BuyCurrencyFromVendorSlot(ObjectGuid vendorGuid, uint32 vendorSlot, uint32 currency, uint32 count);
        bool _StoreOrEquipNewItem(uint32 vendorslot, uint32 item, uint8 count, uint8 bag, uint8 slot, int64 price, ItemTemplate const* pProto, Creature* pVendor, VendorItem const* crItem, bool bStore);

        float GetReputationPriceDiscount(Creature const* creature) const;
        float GetReputationPriceDiscount(FactionTemplateEntry const* factionTemplate) const;

        Player* GetTrader() const;
        TradeData* GetTradeData() const { return m_trade; }
        void TradeCancel(bool sendback);

        CinematicMgr* GetCinematicMgr() const { return _cinematicMgr.get(); }

        void UpdateEnchantTime(uint32 time);
        void UpdateSoulboundTradeItems();
        void AddTradeableItem(Item* item);
        void RemoveTradeableItem(Item* item);
        void UpdateItemDuration(uint32 time, bool realtimeonly = false);
        void AddEnchantmentDurations(Item* item);
        void RemoveEnchantmentDurations(Item* item);
        void RemoveEnchantmentDurationsReferences(Item* item);
        void RemoveArenaEnchantments(EnchantmentSlot slot);
        void AddEnchantmentDuration(Item* item, EnchantmentSlot slot, uint32 duration);
        void ApplyEnchantment(Item* item, EnchantmentSlot slot, bool apply, bool apply_dur = true, bool ignore_condition = false);
        void ApplyEnchantment(Item* item, bool apply);
        void UpdateSkillEnchantments(uint16 skill_id, uint16 curr_value, uint16 new_value);
        void SendEnchantmentDurations();
        void AddItemDurations(Item* item);
        void RemoveItemDurations(Item* item);
        void SendItemDurations();
        void LoadCorpse(PreparedQueryResult result);

        bool AddItem(uint32 itemId, uint32 count);

        /*********************************************************/
        /***                    GOSSIP SYSTEM                  ***/
        /*********************************************************/

        void PrepareGossipMenu(WorldObject* source, uint32 menuId, bool showQuests = false);
        void SendPreparedGossip(WorldObject* source);
        void OnGossipSelect(WorldObject* source, int32 gossipOptionId, uint32 menuId);

        uint32 GetGossipTextId(uint32 menuId, WorldObject* source);
        uint32 GetGossipTextId(WorldObject* source);
        uint32 GetGossipMenuForSource(WorldObject* source);

        /*********************************************************/
        /***                    QUEST SYSTEM                   ***/
        /*********************************************************/

        int32 GetQuestLevel(Quest const* quest) const
        {
            if (!quest)
                return GetLevel();
            return quest->GetQuestLevel() > 0 ? quest->GetQuestLevel() : std::min<int32>(GetLevel(), quest->GetQuestMaxScalingLevel());
        }

        void PrepareQuestMenu(ObjectGuid guid);
        void SendPreparedQuest(WorldObject* source);
        bool IsActiveQuest(uint32 quest_id) const;
        Quest const* GetNextQuest(Object const* questGiver, Quest const* quest) const;
        bool CanSeeStartQuest(Quest const* quest) const;
        bool CanTakeQuest(Quest const* quest, bool msg) const;
        bool CanAddQuest(Quest const* quest, bool msg) const;
        bool CanCompleteQuest(uint32 quest_id, uint32 ignoredQuestObjectiveId = 0);
        bool CanCompleteRepeatableQuest(Quest const* quest);
        bool CanRewardQuest(Quest const* quest, bool msg) const;
        bool CanRewardQuest(Quest const* quest, LootItemType rewardType, uint32 rewardId, bool msg) const;
        void AddQuestAndCheckCompletion(Quest const* quest, Object* questGiver);
        void AddQuest(Quest const* quest, Object* questGiver);
        void AbandonQuest(uint32 quest_id);
        void CompleteQuest(uint32 quest_id);
        void IncompleteQuest(uint32 quest_id);
        uint32 GetQuestMoneyReward(Quest const* quest) const;
        uint32 GetQuestXPReward(Quest const* quest);
        bool CanSelectQuestPackageItem(QuestPackageItemEntry const* questPackageItem) const;
        void RewardQuestPackage(uint32 questPackageId, ItemContext context, uint32 onlyItemId = 0);
        void RewardQuest(Quest const* quest, LootItemType rewardType, uint32 rewardId, Object* questGiver, bool announce = true);
        void SetRewardedQuest(uint32 quest_id);
        void FailQuest(uint32 quest_id);
        void FailQuestsWithFlag(QuestFlags flag);
        bool SatisfyQuestSkill(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestLevel(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestMinLevel(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestMaxLevel(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestLog(bool msg) const;
        bool SatisfyQuestDependentQuests(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestPreviousQuest(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestDependentPreviousQuests(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestBreadcrumbQuest(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestDependentBreadcrumbQuests(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestClass(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestRace(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestReputation(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestStatus(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestConditions(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestTimed(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestExclusiveGroup(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestDay(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestWeek(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestMonth(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestSeasonal(Quest const* qInfo, bool msg) const;
        bool SatisfyQuestExpansion(Quest const* qInfo, bool msg) const;
        bool GiveQuestSourceItem(Quest const* quest);
        bool TakeQuestSourceItem(uint32 questId, bool msg);
        bool GetQuestRewardStatus(uint32 quest_id) const;
        QuestStatus GetQuestStatus(uint32 quest_id) const;
        void SetQuestStatus(uint32 questId, QuestStatus status, bool update = true);
        void RemoveActiveQuest(uint32 questId, bool update = true);
        void RemoveRewardedQuest(uint32 questId, bool update = true);
        void SendQuestUpdate(uint32 questId);
        QuestGiverStatus GetQuestDialogStatus(Object const* questGiver) const;
        void SkipQuests(std::vector<uint32> const& questIds); // removes quest from log, flags rewarded, but does not give any rewards to player
        void DespawnPersonalSummonsForQuest(uint32 questId);

        void SetDailyQuestStatus(uint32 quest_id);
        bool IsDailyQuestDone(uint32 quest_id) const;
        void SetWeeklyQuestStatus(uint32 quest_id);
        void SetMonthlyQuestStatus(uint32 quest_id);
        void SetSeasonalQuestStatus(uint32 quest_id);
        void DailyReset();
        void ResetWeeklyQuestStatus();
        void ResetMonthlyQuestStatus();
        void ResetSeasonalQuestStatus(uint16 event_id, time_t eventStartTime);

        uint16 FindQuestSlot(uint32 quest_id) const;
        uint32 GetQuestSlotQuestId(uint16 slot) const;
        uint32 GetQuestSlotState(uint16 slot) const;
        uint16 GetQuestSlotCounter(uint16 slot, uint8 counter) const;
        int64 GetQuestSlotEndTime(uint16 slot) const;
        int32 GetQuestSlotObjectiveData(uint16 slot, QuestObjective const& objective) const;
        int32 GetQuestObjectiveData(uint32 questId, uint32 objectiveId) const;
        void SetQuestSlot(uint16 slot, uint32 quest_id);
        void SetQuestSlotCounter(uint16 slot, uint8 counter, uint16 count);
        void SetQuestSlotState(uint16 slot, uint32 state);
        void RemoveQuestSlotState(uint16 slot, uint32 state);
        void SetQuestSlotEndTime(uint16 slot, time_t endTime);
        void SetQuestCompletedBit(uint32 questBit, bool completed);

        uint16 GetReqKillOrCastCurrentCount(uint32 quest_id, int32 entry) const;
        void AreaExploredOrEventHappens(uint32 questId);
        void GroupEventHappens(uint32 questId, WorldObject const* pEventObject);
        void ItemAddedQuestCheck(uint32 entry, uint32 count, Optional<bool> boundItemFlagRequirement = {}, bool* hadBoundItemObjective = nullptr);
        void ItemRemovedQuestCheck(uint32 entry, uint32 count);
        void KilledMonster(CreatureTemplate const* cInfo, ObjectGuid guid);
        void KilledMonsterCredit(uint32 entry, ObjectGuid guid = ObjectGuid::Empty);
        void KilledPlayerCredit(ObjectGuid victimGuid);
        void KillCreditGO(uint32 entry, ObjectGuid guid = ObjectGuid::Empty);
        void TalkedToCreature(uint32 entry, ObjectGuid guid);
        void KillCreditCriteriaTreeObjective(QuestObjective const& questObjective);
        void MoneyChanged(uint64 value);
        void ReputationChanged(FactionEntry const* factionEntry, int32 change);
        void CurrencyChanged(uint32 currencyId, int32 change);
        void UpdateQuestObjectiveProgress(QuestObjectiveType objectiveType, int32 objectId, int64 addCount, ObjectGuid victimGuid = ObjectGuid::Empty,
            std::vector<QuestObjective const*>* updatedObjectives = nullptr, std::function<bool(QuestObjective const*)> const* objectiveFilter = nullptr);
        bool HasQuestForItem(uint32 itemId) const;
        QuestObjective const* GetQuestObjectiveForItem(uint32 itemId, bool onlyIncomplete) const;
        bool HasQuestForGO(int32 goId) const;
        void UpdateVisibleGameobjectsOrSpellClicks();
        bool CanShareQuest(uint32 questId) const;

        int32 GetQuestObjectiveData(QuestObjective const& objective) const;
        void SetQuestObjectiveData(QuestObjective const& objective, int32 data);
        bool IsQuestObjectiveCompletable(uint16 slot, Quest const* quest, QuestObjective const& objective) const;
        bool IsQuestObjectiveComplete(uint16 slot, Quest const* quest, QuestObjective const& objective) const;
        bool IsQuestObjectiveComplete(uint32 questId, uint32 objectiveId) const;
        bool IsQuestObjectiveProgressBarComplete(uint16 slot, Quest const* quest) const;
        void SendQuestComplete(uint32 questId) const;
        void SendQuestReward(Quest const* quest, Creature const* questGiver, uint32 xp, bool hideChatMessage) const;
        void SendQuestFailed(uint32 questId, InventoryResult reason = EQUIP_ERR_OK) const;
        void SendQuestTimerFailed(uint32 questId) const;
        void SendCanTakeQuestResponse(QuestFailedReason reason, bool sendErrorMessage = true, std::string reasonText = "") const;
        void SendQuestConfirmAccept(Quest const* quest, Player* receiver) const;
        void SendPushToPartyResponse(Player const* player, QuestPushReason reason, Quest const* quest = nullptr) const;
        void SendQuestUpdateAddCredit(Quest const* quest, ObjectGuid guid, QuestObjective const& obj, uint16 count) const;
        void SendQuestUpdateAddCreditSimple(QuestObjective const& obj) const;
        void SendQuestUpdateAddItem(ItemTemplate const* itemTemplate, QuestObjective const& obj, uint16 count) const;
        void SendQuestUpdateAddPlayer(Quest const* quest, uint16 newCount) const;
        void SendQuestGiverStatusMultiple();
        void SendQuestGiverStatusMultiple(GuidUnorderedSet const& guids);
        void SendDisplayToast(uint32 entry, DisplayToastType type, bool isBonusRoll, uint32 quantity, DisplayToastMethod method, uint32 questId = 0, Item* item = nullptr) const;

        uint32 GetSharedQuestID() const { return m_sharedQuestId; }
        ObjectGuid GetPlayerSharingQuest() const { return m_playerSharingQuest; }
        void SetQuestSharingInfo(ObjectGuid guid, uint32 id) { m_playerSharingQuest = guid; m_sharedQuestId = id; }
        void ClearQuestSharingInfo() { m_playerSharingQuest = ObjectGuid::Empty; m_sharedQuestId = 0; }

        uint32 GetInGameTime() const { return m_ingametime; }
        void SetInGameTime(uint32 time) { m_ingametime = time; }

        void AddTimedQuest(uint32 questId) { m_timedquests.insert(questId); }
        void RemoveTimedQuest(uint32 questId) { m_timedquests.erase(questId); }

        void SaveCUFProfile(uint8 id, std::nullptr_t) { _CUFProfiles[id] = nullptr; } ///> Empties a CUF profile at position 0-4
        void SaveCUFProfile(uint8 id, std::unique_ptr<CUFProfile> profile) { _CUFProfiles[id] = std::move(profile); } ///> Replaces a CUF profile at position 0-4
        CUFProfile* GetCUFProfile(uint8 id) const { return _CUFProfiles[id].get(); } ///> Retrieves a CUF profile at position 0-4
        uint8 GetCUFProfilesCount() const
        {
            uint8 count = 0;
            for (uint8 i = 0; i < MAX_CUF_PROFILES; ++i)
                if (_CUFProfiles[i])
                    ++count;
            return count;
        }

        bool HasPvPForcingQuest() const;

        /*********************************************************/
        /***                   LOAD SYSTEM                     ***/
        /*********************************************************/

        bool LoadFromDB(ObjectGuid guid, CharacterDatabaseQueryHolder const& holder);
        bool IsLoading() const override;

        static uint32 GetZoneIdFromDB(ObjectGuid guid);
        static bool   LoadPositionFromDB(uint32& mapid, float& x, float& y, float& z, float& o, bool& in_flight, ObjectGuid guid);

        static bool IsValidGender(uint8 Gender) { return Gender <= GENDER_FEMALE; }
        static bool IsValidClass(uint8 Class) { return ((1 << (Class - 1)) & CLASSMASK_ALL_PLAYABLE) != 0; }
        static bool IsValidRace(uint8 Race) { return Trinity::RaceMask<uint64>{ RACEMASK_ALL_PLAYABLE }.HasRace(Race); }

        /*********************************************************/
        /***                   SAVE SYSTEM                     ***/
        /*********************************************************/

        void SaveToDB(bool create = false);
        void SaveToDB(LoginDatabaseTransaction loginTransaction, CharacterDatabaseTransaction trans, bool create = false);
        void SaveInventoryAndGoldToDB(CharacterDatabaseTransaction trans);                    // fast save function for item/money cheating preventing
        void SaveGoldToDB(CharacterDatabaseTransaction trans) const;

        static void SaveCustomizations(CharacterDatabaseTransaction trans, ObjectGuid::LowType guid,
            Trinity::IteratorPair<UF::ChrCustomizationChoice const*> customizations);
        static void SavePositionInDB(WorldLocation const& loc, uint16 zoneId, ObjectGuid guid, CharacterDatabaseTransaction trans);

        static void DeleteFromDB(ObjectGuid playerguid, uint32 accountId, bool updateRealmChars = true, bool deleteFinally = false);
        static void DeleteOldCharacters();
        static void DeleteOldCharacters(uint32 keepDays);

        bool m_mailsUpdated;

        void SetBindPoint(ObjectGuid guid) const;
        void SendRespecWipeConfirm(ObjectGuid const& guid, uint32 cost, SpecResetType respecType) const;
        void RegenerateAll();
        void Regenerate(Powers power);
        void InterruptPowerRegen(Powers power);
        void RegenerateHealth();
        void setRegenTimerCount(uint32 time) {m_regenTimerCount = time;}
        void setWeaponChangeTimer(uint32 time) {m_weaponChangeTimer = time;}

        uint64 GetMoney() const { return m_activePlayerData->Coinage; }
        bool ModifyMoney(int64 amount, bool sendError = true);
        bool HasEnoughMoney(uint64 amount) const { return (GetMoney() >= amount); }
        bool HasEnoughMoney(int64 amount) const{ return (amount < 0) || HasEnoughMoney(uint64(amount)); }
        void SetMoney(uint64 value);

        RewardedQuestSet const& getRewardedQuests() const { return m_RewardedQuests; }
        QuestStatusMap& getQuestStatusMap() { return m_QuestStatus; }

        size_t GetRewardedQuestCount() const { return m_RewardedQuests.size(); }
        bool IsQuestRewarded(uint32 quest_id) const;

        Unit* GetSelectedUnit() const;
        Player* GetSelectedPlayer() const;

        void SetTarget(ObjectGuid const& /*guid*/) override { } /// Used for serverside target changes, does not apply to players
        void SetSelection(ObjectGuid const& guid) { SetUpdateFieldValue(m_values.ModifyValue(&Unit::m_unitData).ModifyValue(&UF::UnitData::Target), guid); }

        void SendMailResult(uint64 mailId, MailResponseType mailAction, MailResponseResult mailError, uint32 equipError = 0, ObjectGuid::LowType itemGuid = UI64LIT(0), uint32 itemCount = 0) const;
        void SendNewMail() const;
        void UpdateNextMailTimeAndUnreads();
        void AddNewMailDeliverTime(time_t deliver_time);

        void RemoveMail(uint64 id);

        void AddMail(Mail* mail) { m_mail.push_front(mail);}// for call from WorldSession::SendMailTo
        uint32 GetMailSize() const { return uint32(m_mail.size()); }
        Mail* GetMail(uint64 id);

        PlayerMails const& GetMails() const { return m_mail; }

        void SendItemRetrievalMail(uint32 itemEntry, uint32 count, ItemContext context); // Item retrieval mails sent by The Postmaster (34337), used in multiple places.

        /*********************************************************/
        /*** MAILED ITEMS SYSTEM ***/
        /*********************************************************/

        uint8 unReadMails;
        time_t m_nextMailDelivereTime;

        typedef std::unordered_map<ObjectGuid::LowType, Item*> ItemMap;

        ItemMap mMitems;                                    //template defined in objectmgr.cpp

        Item* GetMItem(ObjectGuid::LowType id);
        void AddMItem(Item* it);
        bool RemoveMItem(ObjectGuid::LowType id);

        void SendOnCancelExpectedVehicleRideAura() const;
        void PetSpellInitialize();
        void CharmSpellInitialize();
        void PossessSpellInitialize();
        void VehicleSpellInitialize();
        void SendRemoveControlBar() const;
        bool HasSpell(uint32 spell) const override;
        bool HasActiveSpell(uint32 spell) const;            // show in spellbook
        SpellInfo const* GetCastSpellInfo(SpellInfo const* spellInfo, TriggerCastFlags& triggerFlag) const override;
        bool IsSpellFitByClassAndRace(uint32 spell_id) const;
        bool HandlePassiveSpellLearn(SpellInfo const* spellInfo);

        void SendProficiency(ItemClass itemClass, uint32 itemSubclassMask) const;
        void SendKnownSpells();
        void SendUnlearnSpells();
        bool AddSpell(uint32 spellId, bool active, bool learning, bool dependent, bool disabled, bool loading = false, int32 fromSkill = 0, bool favorite = false, Optional<int32> traitDefinitionId = {});
        void LearnSpell(uint32 spell_id, bool dependent, int32 fromSkill = 0, bool suppressMessaging = false, Optional<int32> traitDefinitionId = {});
        void RemoveSpell(uint32 spell_id, bool disabled = false, bool learn_low_rank = true, bool suppressMessaging = false);
        void ResetSpells(bool myClassOnly = false);
        void LearnCustomSpells();
        void LearnDefaultSkills();
        void LearnDefaultSkill(SkillRaceClassInfoEntry const* rcInfo);
        void LearnQuestRewardedSpells();
        void LearnQuestRewardedSpells(Quest const* quest);
        void AddTemporarySpell(uint32 spellId);
        void RemoveTemporarySpell(uint32 spellId);
        void SetOverrideSpellsId(int32 overrideSpellsId) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::OverrideSpellsID), overrideSpellsId);  }
        void AddOverrideSpell(uint32 overridenSpellId, uint32 newSpellId);
        void RemoveOverrideSpell(uint32 overridenSpellId, uint32 newSpellId);
        void AddSpellCategoryCooldownMod(int32 spellCategoryId, int32 mod);
        void RemoveSpellCategoryCooldownMod(int32 spellCategoryId, int32 mod);
        void SetSpellFavorite(uint32 spellId, bool favorite);

        void AddStoredAuraTeleportLocation(uint32 spellId);
        void RemoveStoredAuraTeleportLocation(uint32 spellId);
        WorldLocation const* GetStoredAuraTeleportLocation(uint32 spellId) const;

        void SetReputation(uint32 factionentry, int32 value);
        int32 GetReputation(uint32 factionentry) const;
        std::string GetGuildName() const;

        // Loot Spec
        void SetLootSpecId(uint32 id) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::LootSpecID), id); }
        uint32 GetLootSpecId() const { return m_activePlayerData->LootSpecID; }

        ZonePVPTypeOverride GetOverrideZonePVPType() const { return ZonePVPTypeOverride(*m_activePlayerData->OverrideZonePVPType); }
        void SetOverrideZonePVPType(ZonePVPTypeOverride type) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::OverrideZonePVPType), uint32(type)); }

        // Talents
        uint32 GetTalentResetCost() const { return _specializationInfo.ResetTalentsCost; }
        void SetTalentResetCost(uint32 cost)  { _specializationInfo.ResetTalentsCost = cost; }
        time_t GetTalentResetTime() const { return _specializationInfo.ResetTalentsTime; }
        void SetTalentResetTime(time_t time_)  { _specializationInfo.ResetTalentsTime = time_; }
        PlayerTalentMap const& GetPlayerTalentMap(uint8 talentGroupId) const { return _specializationInfo.Talents[talentGroupId]; }
        PlayerTalentMap& GetPlayerTalentMap(uint8 talentGroupId) { return _specializationInfo.Talents[talentGroupId]; }

        std::array<uint32, MAX_GLYPH_SLOT_INDEX>& GetGlyphs(uint8 talentGroupId) { return _specializationInfo.Glyphs[talentGroupId]; }
        std::array<uint32, MAX_GLYPH_SLOT_INDEX> const& GetGlyphs(uint8 talentGroupId) const { return _specializationInfo.Glyphs[talentGroupId]; }

        ChrSpecialization GetPrimarySpecialization() const { return ChrSpecialization(*m_playerData->CurrentSpecID); }
        void SetPrimarySpecialization(uint32 spec) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::CurrentSpecID), spec); }
        uint8 GetActiveTalentGroup() const { return _specializationInfo.ActiveGroup; }
        void SetActiveTalentGroup(uint8 group) { _specializationInfo.ActiveGroup = group; }
        uint8 GetBonusTalentGroupCount() const { return _specializationInfo.BonusGroups; }
        void SetBonusTalentGroupCount(uint8 amount);
        uint32 GetSpentTalentPointsCount() const;
        uint32 GetDefaultSpecId() const;
        ChrSpecializationEntry const* GetPrimarySpecializationEntry() const;

        bool ResetTalents(bool noCost = false);
        uint32 GetNextResetTalentsCost() const;
        void InitTalentForLevel();
        void InitGlyphsForLevel();
        void SetGlyph(uint8 slot, uint32 glyph);
        uint32 GetGlyph(uint8 slot) const { return m_activePlayerData->Glyphs[slot]; }
        void SetGlyphSlot(uint8 slot, uint32 id) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::GlyphSlots, slot), id); }
        uint32 GetGlyphSlot(uint8 slot) const { return m_activePlayerData->GlyphSlots[slot]; }
        void SendTalentsInfoData();
        uint32 CalculateTalentsPoints() const;
        bool LearnTalent(uint32 talentId, uint8 requestedRank);
        bool AddTalent(TalentEntry const* talent, uint8 rank, uint8 talentGroupId, bool learning);
        void RemoveTalent(TalentEntry const* talent);

        void EnablePvpRules(bool dueToCombat = false);
        void DisablePvpRules();
        bool HasPvpRulesEnabled() const;
        bool IsInAreaThatActivatesPvpTalents() const;
        bool IsAreaThatActivatesPvpTalents(uint32 areaID) const;

        // Dual Spec
        void ActivateTalentGroup(uint8 talentGroup);

        ActionButtonList const& GetActionButtons() const { return m_actionButtons; }
        void StartLoadingActionButtons(std::function<void()>&& callback = nullptr);
        void LoadActions(PreparedQueryResult result);

        // Traits
        void CreateTraitConfig(WorldPackets::Traits::TraitConfig& traitConfig);
        void AddTraitConfig(WorldPackets::Traits::TraitConfig const& traitConfig);
        UF::TraitConfig const* GetTraitConfig(int32 configId) const;
        void UpdateTraitConfig(WorldPackets::Traits::TraitConfig&& newConfig, int32 savedConfigId, bool withCastTime);
        void ApplyTraitEntryChanges(int32 editedConfigId, WorldPackets::Traits::TraitConfig const& newConfig, bool applyTraits, bool consumeCurrencies);
        void RenameTraitConfig(int32 editedConfigId, std::string&& newName);
        void DeleteTraitConfig(int32 deletedConfigId);
        void ApplyTraitConfig(int32 configId, bool apply);
        void ApplyTraitEntry(int32 traitNodeEntryId, int32 rank, int32 grantedRanks, bool apply);
        void SetActiveCombatTraitConfigID(int32 traitConfigId) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::ActiveCombatTraitConfigID), traitConfigId); }
        void SetTraitConfigUseStarterBuild(int32 traitConfigId, bool useStarterBuild);
        void SetTraitConfigUseSharedActionBars(int32 traitConfigId, bool usesSharedActionBars, bool isLastSelectedSavedConfig);

        uint32 GetFreePrimaryProfessionPoints() const { return m_activePlayerData->CharacterPoints; }
        void SetFreePrimaryProfessions(uint16 profs) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::CharacterPoints), profs); }
        void InitPrimaryProfessions();

        PlayerSpellMap const& GetSpellMap() const { return m_spells; }
        PlayerSpellMap      & GetSpellMap()       { return m_spells; }

        void AddSpellMod(SpellModifier* mod, bool apply);
        static bool IsAffectedBySpellmod(SpellInfo const* spellInfo, SpellModifier const* mod, Spell* spell = nullptr);
        template <class T>
        void GetSpellModValues(SpellInfo const* spellInfo, SpellModOp op, Spell* spell, T base, int32* flat, float* pct) const;
        template <class T>
        void ApplySpellMod(SpellInfo const* spellInfo, SpellModOp op, T& basevalue, Spell* spell = nullptr) const;
        static void ApplyModToSpell(SpellModifier* mod, Spell* spell);
        void SetSpellModTakingSpell(Spell* spell, bool apply);
        void SendSpellModifiers() const;

        void RemoveArenaSpellCooldowns(bool removeActivePetCooldowns = false);
        uint32 GetLastPotionId() const { return m_lastPotionId; }
        void SetLastPotionId(uint32 item_id) { m_lastPotionId = item_id; }
        void UpdatePotionCooldown(Spell* spell = nullptr);

        void SetResurrectRequestData(WorldObject const* caster, uint32 health, uint32 mana, uint32 appliedAura);
        void ClearResurrectRequestData()
        {
            _resurrectionData.reset();
        }

        bool IsResurrectRequestedBy(ObjectGuid const& guid) const
        {
            if (!IsResurrectRequested())
                return false;

            return !_resurrectionData->GUID.IsEmpty() && _resurrectionData->GUID == guid;
        }

        bool IsResurrectRequested() const { return _resurrectionData.get() != nullptr; }
        void ResurrectUsingRequestData();
        void ResurrectUsingRequestDataImpl();

        PlayerCreateMode GetCreateMode() const { return m_createMode;  }

        uint8 getCinematic() const { return m_cinematic; }
        void setCinematic(uint8 cine) { m_cinematic = cine; }

        uint32 GetMovie() const { return m_movie; }
        void SetMovie(uint32 movie) { m_movie = movie; }

        ActionButton* AddActionButton(uint8 button, uint32 action, uint8 type);
        void RemoveActionButton(uint8 button);
        ActionButton const* GetActionButton(uint8 button);
        void SendInitialActionButtons() const { SendActionButtons(0); }
        void SendActionButtons(uint32 state) const;
        bool IsActionButtonDataValid(uint8 button, uint32 action, uint8 type) const;
        void SetMultiActionBars(uint8 mask) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::MultiActionBars), mask); }

        PvPInfo pvpInfo;
        void InitPvP();
        void UpdatePvPState(bool onlyFFA = false);
        void SetPvP(bool state) override;
        void UpdatePvP(bool state, bool override = false);
        void UpdateZone(uint32 newZone, uint32 newArea);
        void UpdateArea(uint32 newArea);
        void UpdateHostileAreaState(AreaTableEntry const* area);
        void UpdateZoneDependentAuras(uint32 zone_id);    // zones
        void UpdateAreaDependentAuras(uint32 area_id);    // subzones

        void UpdateAfkReport(time_t currTime);
        void UpdatePvPFlag(time_t currTime);
        void SetContestedPvP(Player* attackedPlayer = nullptr);
        void UpdateContestedPvP(uint32 currTime);
        void SetContestedPvPTimer(uint32 newTime) {m_contestedPvPTimer = newTime;}
        void ResetContestedPvP();

        /// @todo: maybe move UpdateDuelFlag+DuelComplete to independent DuelHandler
        std::unique_ptr<DuelInfo> duel;
        void UpdateDuelFlag(time_t currTime);
        void CheckDuelDistance(time_t currTime);
        void DuelComplete(DuelCompleteType type);
        void SetDuelArbiter(ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::DuelArbiter), guid); }
        void SetDuelTeam(uint32 duelTeam) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::DuelTeam), duelTeam); }

        bool IsGroupVisibleFor(Player const* p) const;
        bool IsInSameGroupWith(Player const* p) const;
        bool IsInSameRaidWith(Player const* p) const;
        void UninviteFromGroup();
        static void RemoveFromGroup(Group* group, ObjectGuid guid, RemoveMethod method = GROUP_REMOVEMETHOD_DEFAULT, ObjectGuid kicker = ObjectGuid::Empty, char const* reason = nullptr);
        void RemoveFromGroup(RemoveMethod method = GROUP_REMOVEMETHOD_DEFAULT) { RemoveFromGroup(GetGroup(), GetGUID(), method); }
        void SendUpdateToOutOfRangeGroupMembers();

        void SetInGuild(ObjectGuid::LowType guildId);
        void SetGuildRank(uint8 rankId) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::GuildRankID), rankId); }
        uint8 GetGuildRank() const { return uint8(m_playerData->GuildRankID); }
        void SetGuildLevel(uint32 level) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::GuildLevel), level); }
        uint32 GetGuildLevel() const { return m_playerData->GuildLevel; }
        void SetGuildIdInvited(ObjectGuid::LowType GuildId) { m_GuildIdInvited = GuildId; }
        ObjectGuid::LowType GetGuildId() const { return m_unitData->GuildGUID->GetCounter(); /* return only lower part */ }
        Guild* GetGuild();
        Guild const* GetGuild() const;
        ObjectGuid::LowType GetGuildIdInvited() const { return m_GuildIdInvited; }
        static void RemovePetitionsAndSigns(ObjectGuid guid);

        // Arena Team
        void SetInArenaTeam(uint32 ArenaTeamId, uint8 slot, uint8 type);
        void SetArenaTeamInfoField(uint8 slot, ArenaTeamInfoType type, uint32 value);
        static void LeaveAllArenaTeams(ObjectGuid guid);
        uint32 GetArenaTeamId(uint8 /*slot*/) const { return 0; }
        uint32 GetArenaPersonalRating(uint8 slot) const;
        void SetArenaTeamIdInvited(uint32 ArenaTeamId) { m_ArenaTeamIdInvited = ArenaTeamId; }
        uint32 GetArenaTeamIdInvited() const { return m_ArenaTeamIdInvited; }
        uint32 GetRBGPersonalRating() const { return GetArenaPersonalRating(3); }
        UF::PVPInfo const* GetPvpInfoForBracket(int8 bracket) const;

        Difficulty GetDifficultyID(MapEntry const* mapEntry) const;
        Difficulty GetDungeonDifficultyID() const { return m_dungeonDifficulty; }
        Difficulty GetRaidDifficultyID() const { return m_raidDifficulty; }
        Difficulty GetLegacyRaidDifficultyID() const { return m_legacyRaidDifficulty; }
        void SetDungeonDifficultyID(Difficulty dungeon_difficulty) { m_dungeonDifficulty = dungeon_difficulty; }
        void SetRaidDifficultyID(Difficulty raid_difficulty) { m_raidDifficulty = raid_difficulty; }
        void SetLegacyRaidDifficultyID(Difficulty raid_difficulty) { m_legacyRaidDifficulty = raid_difficulty; }
        static Difficulty CheckLoadedDungeonDifficultyID(Difficulty difficulty);
        static Difficulty CheckLoadedRaidDifficultyID(Difficulty difficulty);
        static Difficulty CheckLoadedLegacyRaidDifficultyID(Difficulty difficulty);
        void SendRaidGroupOnlyMessage(RaidGroupReason reason, int32 delay) const;

        bool UpdateSkillPro(uint16 skillId, int32 chance, uint32 step);
        bool UpdateCraftSkill(SpellInfo const* spellInfo);
        bool UpdateGatherSkill(uint32 skillId, uint32 skillValue, uint32 redLevel, uint32 multiplicator = 1, WorldObject const* object = nullptr);
        bool UpdateFishingSkill(int32 expansion);

        float GetHealthBonusFromStamina() const;
        float GetManaBonusFromIntellect() const;

        bool UpdateStats(Stats stat) override;
        bool UpdateAllStats() override;
        void ApplySpellPenetrationBonus(int32 amount, bool apply);
        void ApplyModTargetResistance(int32 mod, bool apply) { ApplyModUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::ModTargetResistance), mod, apply); }
        void ApplyModTargetPhysicalResistance(int32 mod, bool apply) { ApplyModUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::ModTargetPhysicalResistance), mod, apply); }
        void UpdateResistances(uint32 school) override;
        void UpdateArmor() override;
        void UpdateMaxHealth() override;
        void UpdateMaxPower(Powers power) override;
        uint32 GetPowerIndex(Powers power) const override;
        void UpdateAttackPowerAndDamage(bool ranged = false) override;
        void ApplySpellPowerBonus(int32 amount, bool apply);
        void UpdateSpellDamageAndHealingBonus();
        void ApplyModDamageDonePos(SpellSchools school, int32 mod, bool apply) { ApplyModUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::ModDamageDonePos, school), mod, apply); }
        void ApplyModDamageDoneNeg(SpellSchools school, int32 mod, bool apply) { ApplyModUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::ModDamageDoneNeg, school), mod, apply); }
        void ApplyModDamageDonePercent(SpellSchools school, float pct, bool apply) { ApplyPercentModUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::ModDamageDonePercent, school), pct, apply); }
        void SetModDamageDonePercent(uint8 school, float pct) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::ModDamageDonePercent, school), pct); }
        void ApplyRatingMod(CombatRating cr, int32 value, bool apply);
        void UpdateRating(CombatRating cr);
        void UpdateAllRatings();
        void UpdateMastery();
        void UpdateVersatilityDamageDone();
        void UpdateHealingDonePercentMod();
        bool CanUseMastery() const;

        void CalculateMinMaxDamage(WeaponAttackType attType, bool normalized, bool addTotalPct, float& minDamage, float& maxDamage) const override;

        void RecalculateRating(CombatRating cr) { ApplyRatingMod(cr, 0, true);}
        void GetDodgeFromAgility(float &diminishing, float &nondiminishing) const;
        float OCTRegenHPPerSpirit() const;
        float OCTRegenMPPerSpirit() const;
        float GetRatingMultiplier(CombatRating cr) const;
        float GetRatingBonusValue(CombatRating cr) const;

        /// Returns base spellpower bonus from spellpower stat on items, without spellpower from intellect stat
        uint32 GetBaseSpellPowerBonus() const { return m_baseSpellPower; }
        int32 GetSpellPenetrationItemMod() const { return m_spellPenetrationItemMod; }

        bool CanApplyResilience() const override { return true; }

        float GetExpertiseDodgeOrParryReduction(WeaponAttackType attType) const;
        void UpdateBlockPercentage();
        void UpdateCritPercentage(WeaponAttackType attType);
        void UpdateAllCritPercentages();
        void UpdateParryPercentage();
        void UpdateDodgePercentage();
        void UpdateMeleeHitChances();
        void UpdateRangedHitChances();
        void UpdateSpellHitChances();

        void UpdateSpellCritChance();
        void UpdateCorruption();
        void UpdateArmorPenetration(int32 amount);
        void UpdateExpertise(WeaponAttackType attType);
        void ApplyManaRegenBonus(int32 amount, bool apply);
        void ApplyHealthRegenBonus(int32 amount, bool apply);
        void UpdateManaRegen();
        void UpdateAllRunesRegen();

        void SetPetSpellPower(uint32 spellPower) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::PetSpellPower), spellPower); }

        ObjectGuid const& GetLootGUID() const { return m_playerData->LootTargetGUID; }
        void SetLootGUID(ObjectGuid const& guid) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::LootTargetGUID), guid); }
        Loot* GetLootByWorldObjectGUID(ObjectGuid const& lootWorldObjectGuid) const;
        std::unordered_map<ObjectGuid, Loot*> const& GetAELootView() const { return m_AELootView; }
        LootRoll* GetLootRoll(ObjectGuid const& lootObjectGuid, uint8 lootListId);
        void AddLootRoll(LootRoll* roll) { m_lootRolls.push_back(roll); }
        void RemoveLootRoll(LootRoll* roll);

        void RemovedInsignia(Player* looterPlr);

        WorldSession* GetSession() const { return m_session; }

    protected:
        UF::UpdateFieldFlag GetUpdateFieldFlagsFor(Player const* target) const override;
        void BuildValuesCreate(ByteBuffer* data, Player const* target) const override;
        void BuildValuesUpdate(ByteBuffer* data, Player const* target) const override;
        void ClearUpdateMask(bool remove) override;

    public:
        void BuildCreateUpdateBlockForPlayer(UpdateData* data, Player* target) const override;
        void BuildValuesUpdateWithFlag(ByteBuffer* data, UF::UpdateFieldFlag flags, Player const* target) const override;
        void BuildValuesUpdateForPlayerWithMask(UpdateData* data, UF::ObjectData::Mask const& requestedObjectMask, UF::UnitData::Mask const& requestedUnitMask,
            UF::PlayerData::Mask const& requestedPlayerMask, UF::ActivePlayerData::Mask const& requestedActivePlayerMask, Player const* target) const;

        struct ValuesUpdateForPlayerWithMaskSender // sender compatible with MessageDistDeliverer
        {
            explicit ValuesUpdateForPlayerWithMaskSender(Player const* owner) : Owner(owner) { }

            Player const* Owner;
            UF::ObjectData::Base ObjectMask;
            UF::UnitData::Base UnitMask;
            UF::PlayerData::Base PlayerMask;
            UF::ActivePlayerData::Base ActivePlayerMask;

            void operator()(Player const* player) const;
        };

        void DestroyForPlayer(Player* target) const override;

        // notifiers
        void SendAttackSwingCancelAttack() const;
        void SetAttackSwingError(Optional<AttackSwingErr> err);
        void SendAutoRepeatCancel(Unit* target);
        void SendExplorationExperience(uint32 Area, uint32 Experience) const;

        void SendDungeonDifficulty(int32 forcedDifficulty = -1) const;
        void SendRaidDifficulty(bool legacy, int32 forcedDifficulty = -1) const;
        void ResetInstances(InstanceResetMethod method);
        void SendResetInstanceSuccess(uint32 MapId) const;
        void SendResetInstanceFailed(ResetFailedReason reason, uint32 mapID) const;
        void SendResetFailedNotify(uint32 mapid) const;
        bool IsLockedToDungeonEncounter(uint32 dungeonEncounterId) const;
        bool IsLockedToDungeonEncounter(uint32 dungeonEncounterId, Difficulty difficulty) const;

        bool UpdatePosition(float x, float y, float z, float orientation, bool teleport = false) override;
        bool UpdatePosition(Position const& pos, bool teleport = false) override { return UpdatePosition(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), teleport); }
        void ProcessTerrainStatusUpdate(ZLiquidStatus oldLiquidStatus, Optional<LiquidData> const& newLiquidData) override;
        void AtEnterCombat() override;
        void AtExitCombat() override;

        void SendMessageToSet(WorldPacket const* data, bool self) const override { SendMessageToSetInRange(data, GetVisibilityRange(), self); }
        void SendMessageToSetInRange(WorldPacket const* data, float dist, bool self) const override;
        void SendMessageToSetInRange(WorldPacket const* data, float dist, bool self, bool own_team_only, bool required3dDist = false) const;
        void SendMessageToSet(WorldPacket const* data, Player const* skipped_rcvr) const override;

        void SendChatMessageToSetInRange(ChatMsg chatMsg, Language lanugageId, std::string&& text, float range);

        Corpse* GetCorpse() const;
        void SpawnCorpseBones(bool triggerSave = true);
        Corpse* CreateCorpse();
        void KillPlayer();
        static void OfflineResurrect(ObjectGuid const& guid, CharacterDatabaseTransaction trans);
        bool HasCorpse() const { return _corpseLocation.GetMapId() != MAPID_INVALID; }
        WorldLocation GetCorpseLocation() const { return _corpseLocation; }
        void InitializeSelfResurrectionSpells();
        void ResurrectPlayer(float restore_percent, bool applySickness = false);
        void BuildPlayerRepop();
        void RepopAtGraveyard();

        void DurabilityLossAll(double percent, bool inventory);
        void DurabilityLoss(Item* item, double percent);
        void DurabilityPointsLossAll(int32 points, bool inventory);
        void DurabilityPointsLoss(Item* item, int32 points);
        void DurabilityPointLossForEquipSlot(EquipmentSlots slot);
        void DurabilityRepairAll(bool takeCost, float discountMod, bool guildBank);
        void DurabilityRepair(uint16 pos, bool takeCost, float discountMod);

        void UpdateMirrorTimers();
        void StopMirrorTimers();
        bool IsMirrorTimerActive(MirrorTimerType type) const;

        bool CanJoinConstantChannelInZone(ChatChannelsEntry const* channel, AreaTableEntry const* zone) const;

        void JoinedChannel(Channel* c);
        void LeftChannel(Channel* c);
        void CleanupChannels();
        void UpdateLocalChannels(uint32 newZone);
        void LeaveLFGChannel();

        typedef std::list<Channel*> JoinedChannelsList;
        JoinedChannelsList const& GetJoinedChannels() const { return m_channels; }

        void InitializeSkillFields();
        void SetSkill(uint32 id, uint16 step, uint16 newVal, uint16 maxVal);
        uint16 GetMaxSkillValue(uint32 skill) const;        // max + perm. bonus + temp bonus
        uint16 GetPureMaxSkillValue(uint32 skill) const;    // max
        uint16 GetSkillValue(uint32 skill) const;           // skill value + perm. bonus + temp bonus
        uint16 GetBaseSkillValue(uint32 skill) const;       // skill value + perm. bonus
        uint16 GetPureSkillValue(uint32 skill) const;       // skill value
        int16 GetSkillPermBonusValue(uint32 skill) const;
        int16 GetSkillTempBonusValue(uint32 skill) const;
        uint16 GetSkillStep(uint32 skill) const;            // 0...6
        uint32 GetProfessionSkillForExp(uint32 skill, int32 expansion) const;
        bool HasSkill(uint32 skill) const;
        void LearnSkillRewardedSpells(uint32 skillId, uint32 skillValue, Races race);
        int32 GetProfessionSlotFor(uint32 skillId) const;
        int32 FindEmptyProfessionSlotFor(uint32 skillId) const;
        void SetSkillLineId(uint32 pos, uint16 skillLineId) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::Skill).ModifyValue(&UF::SkillInfo::SkillLineID, pos), skillLineId); }
        void SetSkillStep(uint32 pos, uint16 step) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::Skill).ModifyValue(&UF::SkillInfo::SkillStep, pos), step); };
        void SetSkillRank(uint32 pos, uint16 rank) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::Skill).ModifyValue(&UF::SkillInfo::SkillRank, pos), rank); }
        void SetSkillStartingRank(uint32 pos, uint16 starting) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::Skill).ModifyValue(&UF::SkillInfo::SkillStartingRank, pos), starting); }
        void SetSkillMaxRank(uint32 pos, uint16 max) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::Skill).ModifyValue(&UF::SkillInfo::SkillMaxRank, pos), max); }
        void SetSkillTempBonus(uint32 pos, uint16 bonus) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::Skill).ModifyValue(&UF::SkillInfo::SkillTempBonus, pos), bonus); }
        void SetSkillPermBonus(uint32 pos, uint16 bonus) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::Skill).ModifyValue(&UF::SkillInfo::SkillPermBonus, pos), bonus); }

        WorldLocation& GetTeleportDest() { return m_teleport_dest; }
        Optional<uint32> GetTeleportDestInstanceId() const { return m_teleport_instanceId; }
        uint32 GetTeleportOptions() const { return m_teleport_options; }
        bool IsBeingTeleported() const { return IsBeingTeleportedNear() || IsBeingTeleportedFar(); }
        bool IsBeingTeleportedNear() const { return mSemaphoreTeleport_Near; }
        bool IsBeingTeleportedFar() const { return mSemaphoreTeleport_Far; }
        bool IsBeingTeleportedSeamlessly() const { return IsBeingTeleportedFar() && m_teleport_options & TELE_TO_SEAMLESS; }
        void SetSemaphoreTeleportNear(bool semphsetting) { mSemaphoreTeleport_Near = semphsetting; }
        void SetSemaphoreTeleportFar(bool semphsetting) { mSemaphoreTeleport_Far = semphsetting; }
        void ProcessDelayedOperations();

        void CheckAreaExploreAndOutdoor(void);
        void AddExploredZones(uint32 pos, uint64 mask) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::ExploredZones, pos), mask); }
        void RemoveExploredZones(uint32 pos, uint64 mask) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::ExploredZones, pos), mask); }

        static Team TeamForRace(uint8 race);
        static TeamId TeamIdForRace(uint8 race);
        static uint8 GetFactionGroupForRace(uint8 race);
        Team GetTeam() const { return m_team; }
        TeamId GetTeamId() const { return m_team == ALLIANCE ? TEAM_ALLIANCE : TEAM_HORDE; }
        void SetFactionForRace(uint8 race);

        Team GetEffectiveTeam() const { return HasPlayerFlagEx(PLAYER_FLAGS_EX_MERCENARY_MODE) ? (GetTeam() == ALLIANCE ? HORDE : ALLIANCE) : Team(GetTeam()); }
        TeamId GetEffectiveTeamId() const { return GetEffectiveTeam() == ALLIANCE ? TEAM_ALLIANCE : TEAM_HORDE; }

        void InitDisplayIds();

        bool IsAtGroupRewardDistance(WorldObject const* pRewardSource) const;
        bool IsAtRecruitAFriendDistance(WorldObject const* pOther) const;
        void RewardPlayerAndGroupAtEvent(uint32 creature_id, WorldObject* pRewardSource);
        bool isHonorOrXPTarget(Unit const* victim) const;

        bool GetsRecruitAFriendBonus(bool forXP);

        ReputationMgr&       GetReputationMgr()       { return *m_reputationMgr; }
        ReputationMgr const& GetReputationMgr() const { return *m_reputationMgr; }
        ReputationRank GetReputationRank(uint32 faction_id) const;
        void RewardReputation(Unit* victim, float rate);
        void RewardReputation(Quest const* quest);

        int32 CalculateReputationGain(ReputationSource source, uint32 creatureOrQuestLevel, int32 rep, int32 faction, bool noQuestBonus = false);

        void UpdateSkillsForLevel();
        void ModifySkillBonus(uint32 skillid, int32 val, bool talent);

        /*********************************************************/
        /***                  PVP SYSTEM                       ***/
        /*********************************************************/
        void UpdateHonorFields();
        bool RewardHonor(Unit* victim, uint32 groupsize, int32 honor = -1, bool pvptoken = false);
        void ResetHonorStats();
        uint32 GetMaxPersonalArenaRatingRequirement(uint32 minarenaslot) const;

        // duel health and mana reset methods
        void SaveHealthBeforeDuel() { healthBeforeDuel = GetHealth(); }
        void SaveManaBeforeDuel() { manaBeforeDuel = GetPower(POWER_MANA); }
        void RestoreHealthAfterDuel() { SetHealth(healthBeforeDuel); }
        void RestoreManaAfterDuel() { SetPower(POWER_MANA, manaBeforeDuel); }

        uint32 GetHonorLevel() const { return m_playerData->HonorLevel; }
        void AddHonorXP(uint32 xp);
        void SetHonorLevel(uint8 honorLevel);
        bool IsMaxHonorLevel() const { return GetHonorLevel() == PLAYER_MAX_HONOR_LEVEL; }
        // Updates PLAYER_FIELD_HONOR_NEXT_LEVEL based on PLAYER_FIELD_HONOR_LEVEL
        void UpdateHonorNextLevel();
        //End of PvP System

        void RewardPlayerWithRewardPack(uint32 rewardPackID);
        void RewardPlayerWithRewardPack(RewardPackEntry const* rewardPackEntry);

        void SetDrunkValue(uint8 newDrunkValue, uint32 itemId = 0);
        uint8 GetDrunkValue() const { return m_playerData->Inebriation; }
        static DrunkenState GetDrunkenstateByValue(uint8 value);

        uint32 GetDeathTimer() const { return m_deathTimer; }
        uint32 GetCorpseReclaimDelay(bool pvp) const;
        void UpdateCorpseReclaimDelay();
        int32 CalculateCorpseReclaimDelay(bool load = false) const;
        void SendCorpseReclaimDelay(uint32 delay) const;

        float GetBlockPercent(uint8 attackerLevel) const override;
        bool CanParry() const { return m_canParry; }
        void SetCanParry(bool value);
        bool CanBlock() const { return m_canBlock; }
        void SetCanBlock(bool value);
        bool CanTitanGrip() const { return m_canTitanGrip; }
        void SetCanTitanGrip(bool value, uint32 penaltySpellId = 0);
        void CheckTitanGripPenalty();
        bool CanTameExoticPets() const { return IsGameMaster() || HasAuraType(SPELL_AURA_ALLOW_TAME_PET_TYPE); }

        void SetRegularAttackTime();

        void HandleBaseModFlatValue(BaseModGroup modGroup, float amount, bool apply);
        void ApplyBaseModPctValue(BaseModGroup modGroup, float pct);

        void SetBaseModFlatValue(BaseModGroup modGroup, float val);
        void SetBaseModPctValue(BaseModGroup modGroup, float val);

        void UpdateDamageDoneMods(WeaponAttackType attackType, int32 skipEnchantSlot = -1) override;
        void UpdateBaseModGroup(BaseModGroup modGroup);

        float GetBaseModValue(BaseModGroup modGroup, BaseModType modType) const;
        float GetTotalBaseModValue(BaseModGroup modGroup) const;

        void _ApplyAllStatBonuses();
        void _RemoveAllStatBonuses();

        void ResetAllPowers();

        SpellSchoolMask GetMeleeDamageSchoolMask(WeaponAttackType attackType = BASE_ATTACK) const override;

        void CastAllObtainSpells();
        void ApplyItemObtainSpells(Item* item, bool apply);

        void UpdateWeaponDependentCritAuras(WeaponAttackType attackType);
        void UpdateAllWeaponDependentCritAuras();

        void UpdateWeaponDependentAuras(WeaponAttackType attackType);
        void ApplyItemDependentAuras(Item* item, bool apply);

        bool CheckAttackFitToAuraRequirement(WeaponAttackType attackType, AuraEffect const* aurEff) const override;

        void _ApplyItemMods(Item* item, uint8 slot, bool apply, bool updateItemAuras = true, bool onlyForScalingItems = false);
        void _RemoveAllItemMods();
        void _ApplyAllItemMods();
        void _ApplyAllLevelScaleItemMods(bool apply);
        void _ApplyItemBonuses(Item* item, uint8 slot, bool apply, bool onlyForScalingItems = false);
        void _ApplyWeaponDamage(uint8 slot, Item* item, bool apply);
        bool EnchantmentFitsRequirements(uint32 enchantmentcondition, int8 slot) const;
        void ToggleMetaGemsActive(uint8 exceptslot, bool apply);
        void CorrectMetaGemEnchants(uint8 slot, bool apply);
        void InitDataForForm(bool reapplyMods = false);

        void ApplyItemEquipSpell(Item* item, bool apply, bool formChange = false);
        void ApplyEquipSpell(SpellInfo const* spellInfo, Item* item, bool apply, bool formChange = false);
        void UpdateEquipSpellsAtFormChange();
        void UpdateItemSetAuras(bool formChange = false);

        void CastItemCombatSpell(DamageInfo const& damageInfo);
        void CastItemCombatSpell(DamageInfo const& damageInfo, Item* item, ItemTemplate const* proto);
        void CastItemUseSpell(Item* item, SpellCastTargets const& targets, ObjectGuid castCount, int32* misc);
        void ApplyItemLootedSpell(Item* item, bool apply);
        void ApplyItemLootedSpell(ItemTemplate const* itemTemplate);

        void SendEquipmentSetList();
        void SetEquipmentSet(EquipmentSetInfo::EquipmentSetData const& newEqSet);
        void DeleteEquipmentSet(uint64 id);

        void SendInitWorldStates(uint32 zoneId, uint32 areaId);
        void SendUpdateWorldState(uint32 variable, uint32 value, bool hidden = false) const;
        void SendDirectMessage(WorldPacket const* data) const;

        void SendAurasForTarget(Unit* target) const;

        std::unique_ptr<PlayerMenu> PlayerTalkClass;
        std::vector<ItemSetEffect*> ItemSetEff;

        void SendLoot(Loot& loot, bool aeLooting = false);
        void SendLootError(ObjectGuid const& lootObj, ObjectGuid const& owner, LootError error) const;
        void SendLootRelease(ObjectGuid guid) const;
        void SendLootReleaseAll() const;
        void SendNotifyLootItemRemoved(ObjectGuid lootObj, ObjectGuid owner, uint8 lootListId) const;
        void SendNotifyLootMoneyRemoved(ObjectGuid lootObj) const;

        /*********************************************************/
        /***               BATTLEGROUND SYSTEM                 ***/
        /*********************************************************/

        bool InBattleground()       const                { return m_bgData.bgInstanceID != 0; }
        bool InArena()              const;
        uint32 GetBattlegroundId()  const                { return m_bgData.bgInstanceID; }
        BattlegroundTypeId GetBattlegroundTypeId() const { return m_bgData.bgTypeID; }
        Battleground* GetBattleground() const;

        uint32 GetBattlegroundQueueJoinTime(BattlegroundQueueTypeId bgQueueTypeId) const;
        bool InBattlegroundQueue(bool ignoreArena = false) const;
        bool IsDeserter() const { return HasAura(26013); }

        BattlegroundQueueTypeId GetBattlegroundQueueTypeId(uint32 index) const;
        uint32 GetBattlegroundQueueIndex(BattlegroundQueueTypeId bgQueueTypeId) const;
        bool IsInvitedForBattlegroundQueueType(BattlegroundQueueTypeId bgQueueTypeId) const;
        bool InBattlegroundQueueForBattlegroundQueueType(BattlegroundQueueTypeId bgQueueTypeId) const;

        void SetBattlegroundId(uint32 val, BattlegroundTypeId bgTypeId, BattlegroundQueueTypeId queueId);
        uint32 AddBattlegroundQueueId(BattlegroundQueueTypeId val);
        bool HasFreeBattlegroundQueueId() const;
        void RemoveBattlegroundQueueId(BattlegroundQueueTypeId val);
        void SetInviteForBattlegroundQueueType(BattlegroundQueueTypeId bgQueueTypeId, uint32 instanceId);
        bool IsInvitedForBattlegroundInstance(uint32 instanceId) const;
        void SetMercenaryForBattlegroundQueueType(BattlegroundQueueTypeId bgQueueTypeId, bool mercenary);
        bool IsMercenaryForBattlegroundQueueType(BattlegroundQueueTypeId bgQueueTypeId) const;
        WorldLocation const& GetBattlegroundEntryPoint() const { return m_bgData.joinPos; }
        void SetBattlegroundEntryPoint();

        void SetBGTeam(Team team);
        Team GetBGTeam() const;

        void LeaveBattleground(bool teleportToEntryPoint = true);
        bool CanJoinToBattleground(BattlegroundTemplate const* bg) const;
        bool CanReportAfkDueToLimit();
        void ReportedAfkBy(Player* reporter);
        void ClearAfkReports() { m_bgData.bgAfkReporter.clear(); }

        bool GetBGAccessByLevel(BattlegroundTypeId bgTypeId) const;
        bool CanUseBattlegroundObject(GameObject* gameobject) const;
        bool isTotalImmune() const;
        bool CanCaptureTowerPoint() const;

        bool GetRandomWinner() const { return m_IsBGRandomWinner; }
        void SetRandomWinner(bool isWinner);

        /*********************************************************/
        /***               OUTDOOR PVP SYSTEM                  ***/
        /*********************************************************/

        OutdoorPvP* GetOutdoorPvP() const;
        // returns true if the player is in active state for outdoor pvp objective capturing, false otherwise
        bool IsOutdoorPvPActive() const;

        /*********************************************************/
        /***              ENVIROMENTAL SYSTEM                  ***/
        /*********************************************************/

        bool IsImmuneToEnvironmentalDamage() const;
        uint32 EnvironmentalDamage(EnviromentalDamage type, uint32 damage);

        /*********************************************************/
        /***               FLOOD FILTER SYSTEM                 ***/
        /*********************************************************/

        struct ChatFloodThrottle
        {
            enum Index
            {
                REGULAR = 0,
                ADDON = 1,
                MAX
            };

            time_t Time = 0;
            uint32 Count = 0;
        };

        void UpdateSpeakTime(ChatFloodThrottle::Index index);

        /*********************************************************/
        /***                 VARIOUS SYSTEMS                   ***/
        /*********************************************************/
        void UpdateFallInformationIfNeed(MovementInfo const& minfo, uint16 opcode);
        // only changed for direct client control (possess, vehicle etc.), not stuff you control using pet commands
        WorldObject* m_seer;
        void SetFallInformation(uint32 time, float z);
        void HandleFall(MovementInfo const& movementInfo);

        void SetClientControl(Unit* target, bool allowMove);

        void SetSeer(WorldObject* target) { m_seer = target; }
        void SetViewpoint(WorldObject* target, bool apply);
        WorldObject* GetViewpoint() const;
        void StopCastingCharm();
        void StopCastingBindSight() const;

        uint32 GetSaveTimer() const { return m_nextSave; }
        void SetSaveTimer(uint32 timer) { m_nextSave = timer; }

        void SaveRecallPosition()
        {
            m_recall_location.WorldRelocate(*this);
            m_recall_instanceId = GetInstanceId();
        }
        void Recall() { TeleportTo(m_recall_location, TELE_TO_NONE, m_recall_instanceId); }

        void SetHomebind(WorldLocation const& loc, uint32 areaId);
        void SendBindPointUpdate() const;
        void SendPlayerBound(ObjectGuid const& binderGuid, uint32 areaId) const;

        // Homebind coordinates
        WorldLocation m_homebind;
        uint16 m_homebindAreaId;

        uint8 GetStartLevel(uint8 race, uint8 playerClass, Optional<int32> characterTemplateId) const;

        // currently visible objects at player client
        GuidUnorderedSet m_clientGUIDs;
        GuidUnorderedSet m_visibleTransports;

        bool HaveAtClient(Object const* u) const;

        bool IsNeverVisibleFor(WorldObject const* seer, bool allowServersideObjects = false) const override;

        bool IsVisibleGloballyFor(Player const* player) const;

        void SendInitialVisiblePackets(Unit* target) const;
        void OnPhaseChange() override;
        void UpdateObjectVisibility(bool forced = true) override;
        void UpdateVisibilityForPlayer();
        void UpdateVisibilityOf(WorldObject* target);
        void UpdateVisibilityOf(Trinity::IteratorPair<WorldObject**> targets);
        void UpdateTriggerVisibility();

        template<class T>
        void UpdateVisibilityOf(T* target, UpdateData& data, std::set<Unit*>& visibleNow);

        std::array<uint8, MAX_MOVE_TYPE> m_forced_speed_changes;
        uint8 m_movementForceModMagnitudeChanges;

        bool HasAtLoginFlag(AtLoginFlags f) const { return (m_atLoginFlags & f) != 0; }
        void SetAtLoginFlag(AtLoginFlags f) { m_atLoginFlags |= f; }
        void RemoveAtLoginFlag(AtLoginFlags flags, bool persist = false);

        bool isUsingLfg() const;
        bool inRandomLfgDungeon() const;

        typedef std::set<uint32> DFQuestsDoneList;
        DFQuestsDoneList m_DFQuests;

        // Temporarily removed pet cache
        uint32 GetTemporaryUnsummonedPetNumber() const { return m_temporaryUnsummonedPetNumber; }
        void SetTemporaryUnsummonedPetNumber(uint32 petnumber) { m_temporaryUnsummonedPetNumber = petnumber; }
        Optional<ReactStates> GetTemporaryPetReactState() const { return m_temporaryPetReactState; }
        void DisablePetControlsOnMount(ReactStates reactState, CommandStates commandState);
        void EnablePetControlsOnDismount();
        void UnsummonPetTemporaryIfAny();
        void ResummonPetTemporaryUnSummonedIfAny();
        bool IsPetNeedBeTemporaryUnsummoned() const;

        void SendCinematicStart(uint32 CinematicSequenceId) const;
        void SendMovieStart(uint32 movieId);

        uint32 DoRandomRoll(uint32 minimum, uint32 maximum);
        uint8 GetItemLimitCategoryQuantity(ItemLimitCategoryEntry const* limitEntry) const;

        void UpdateItemLevelAreaBasedScaling();
        void ActivatePvpItemLevels(bool activate) { _usePvpItemLevels = activate; }
        bool IsUsingPvpItemLevels() const { return _usePvpItemLevels; }

        /*********************************************************/
        /***                 INSTANCE SYSTEM                   ***/
        /*********************************************************/

        void UpdateHomebindTime(uint32 time);

        uint32 m_HomebindTimer;
        bool m_InstanceValid;
        // permanent binds and solo binds by difficulty
        uint32 GetRecentInstanceId(uint32 mapId) const
        {
            auto itr = m_recentInstances.find(mapId);
            return itr != m_recentInstances.end() ? itr->second : 0;
        }

        void SetRecentInstance(uint32 mapId, uint32 instanceId)
        {
            m_recentInstances[mapId] = instanceId;
        }

        std::unordered_map<uint32 /*mapId*/, uint32 /*instanceId*/> m_recentInstances;
        void ConfirmPendingBind();
        void SetPendingBind(uint32 instanceId, uint32 bindTimer);
        bool HasPendingBind() const { return _pendingBindId > 0; }
        void SendRaidInfo();
        bool Satisfy(AccessRequirement const* ar, uint32 target_map, TransferAbortParams* params = nullptr, bool report = false);
        bool CheckInstanceValidity(bool /*isLogin*/);
        bool CheckInstanceCount(uint32 instanceId) const;
        void AddInstanceEnterTime(uint32 instanceId, time_t enterTime);
        WorldSafeLocsEntry const* GetInstanceEntrance(uint32 targetMapId);

        // last used pet number (for BG's)
        uint32 GetLastPetNumber() const { return m_lastpetnumber; }
        void SetLastPetNumber(uint32 petnumber) { m_lastpetnumber = petnumber; }

        /*********************************************************/
        /***                   GROUP SYSTEM                    ***/
        /*********************************************************/

        bool IsInGroup(ObjectGuid groupGuid) const;
        Group* GetGroupInvite() const { return m_groupInvite; }
        void SetGroupInvite(Group* group) { m_groupInvite = group; }
        Group* GetGroup(Optional<uint8> partyIndex) { return const_cast<Group*>(const_cast<Player const*>(this)->GetGroup(partyIndex)); }
        Group const* GetGroup(Optional<uint8> partyIndex) const;
        Group* GetGroup() { return m_group.getTarget(); }
        Group const* GetGroup() const { return const_cast<Group const*>(m_group.getTarget()); }
        GroupReference& GetGroupRef() { return m_group; }
        void SetGroup(Group* group, int8 subgroup = -1);
        uint8 GetSubGroup() const { return m_group.getSubGroup(); }
        uint32 GetGroupUpdateFlag() const { return m_groupUpdateMask; }
        void SetGroupUpdateFlag(uint32 flag) { m_groupUpdateMask |= flag; }
        void RemoveGroupUpdateFlag(uint32 flag) { m_groupUpdateMask &= ~flag; }
        void SetPartyType(GroupCategory category, uint8 type);
        void ResetGroupUpdateSequenceIfNeeded(Group const* group);
        int32 NextGroupUpdateSequenceNumber(GroupCategory category);
        Player* GetNextRandomRaidMember(float radius);
        PartyResult CanUninviteFromGroup(ObjectGuid guidMember, Optional<uint8> partyIndex) const;

        // Battleground / Battlefield Group System
        void SetBattlegroundOrBattlefieldRaid(Group* group, int8 subgroup = -1);
        void RemoveFromBattlegroundOrBattlefieldRaid();
        Group* GetOriginalGroup() const { return m_originalGroup.getTarget(); }
        GroupReference& GetOriginalGroupRef() { return m_originalGroup; }
        uint8 GetOriginalSubGroup() const { return m_originalGroup.getSubGroup(); }
        void SetOriginalGroup(Group* group, int8 subgroup = -1);

        void SetPassOnGroupLoot(bool bPassOnGroupLoot) { m_bPassOnGroupLoot = bPassOnGroupLoot; }
        bool GetPassOnGroupLoot() const { return m_bPassOnGroupLoot; }

        MapReference &GetMapRef() { return m_mapRef; }

        // Set map to player and add reference
        void SetMap(Map* map) override;
        void ResetMap() override;

        bool isAllowedToLoot(Creature const* creature) const;

        DeclinedName const* GetDeclinedNames() const { return m_declinedname.get(); }
        uint8 GetRunesState() const;
        uint32 GetRuneCooldown(uint8 index) const { return m_runes->Cooldown[index]; }
        uint32 GetRuneBaseCooldown() const;
        void SetRuneCooldown(uint8 index, uint32 cooldown);
        void ResyncRunes() const;
        void InitRunes();

        void SendRespondInspectAchievements(Player* player) const;
        uint32 GetAchievementPoints() const;
        std::vector<uint32> GetCompletedAchievementIds() const;
        bool HasAchieved(uint32 achievementId) const;
        void ResetAchievements();
        void FailCriteria(CriteriaFailEvent condition, int32 failAsset);
        void UpdateCriteria(CriteriaType type, uint64 miscValue1 = 0, uint64 miscValue2 = 0, uint64 miscValue3 = 0, WorldObject* ref = nullptr);
        void StartCriteria(CriteriaStartEvent startEvent, uint32 entry, Milliseconds timeLost = Milliseconds::zero());
        void CompletedAchievement(AchievementEntry const* entry);
        bool ModifierTreeSatisfied(uint32 modifierTreeId) const;

        bool HasTitle(uint32 bitIndex) const;
        bool HasTitle(CharTitlesEntry const* title) const;
        void SetTitle(CharTitlesEntry const* title, bool lost = false);
        void SetChosenTitle(int32 title) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::PlayerTitle), title); }
        void SetKnownTitles(uint32 index, uint64 mask) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::KnownTitles, index), mask); }

        //bool isActiveObject() const { return true; }
        bool CanSeeSpellClickOn(Creature const* creature) const;

        uint32 GetChampioningFaction() const { return m_ChampioningFaction; }
        void SetChampioningFaction(uint32 faction) { m_ChampioningFaction = faction; }
        Spell* m_spellModTakingSpell;

        float GetAverageItemLevel() const;
        bool isDebugAreaTriggers;

        void ClearWhisperWhiteList() { WhisperList.clear(); }
        void AddWhisperWhiteList(ObjectGuid guid) { WhisperList.push_back(guid); }
        bool IsInWhisperWhiteList(ObjectGuid guid);
        void RemoveFromWhisperWhiteList(ObjectGuid guid) { WhisperList.remove(guid); }

        void ValidateMovementInfo(MovementInfo* mi);

        void SendMovementSetCollisionHeight(float height, WorldPackets::Movement::UpdateCollisionHeightReason reason);

        bool CanFly() const override { return m_movementInfo.HasMovementFlag(MOVEMENTFLAG_CAN_FLY); }
        bool CanEnterWater() const override { return true; }

        std::string GetMapAreaAndZoneString() const;
        std::string GetCoordsMapAreaAndZoneString() const;

        // Void Storage
        bool IsVoidStorageUnlocked() const { return HasPlayerFlag(PLAYER_FLAGS_VOID_UNLOCKED); }
        void UnlockVoidStorage() { SetPlayerFlag(PLAYER_FLAGS_VOID_UNLOCKED); }
        void LockVoidStorage() { RemovePlayerFlag(PLAYER_FLAGS_VOID_UNLOCKED); }
        uint8 GetNextVoidStorageFreeSlot() const;
        uint8 GetNumOfVoidStorageFreeSlots() const;
        uint8 AddVoidStorageItem(VoidStorageItem&& item);
        void DeleteVoidStorageItem(uint8 slot);
        bool SwapVoidStorageItem(uint8 oldSlot, uint8 newSlot);
        VoidStorageItem* GetVoidStorageItem(uint8 slot) const;
        VoidStorageItem* GetVoidStorageItem(uint64 id, uint8& slot) const;

        // Reagent Bank
        bool IsReagentBankUnlocked() const { return HasPlayerFlagEx(PLAYER_FLAGS_EX_REAGENT_BANK_UNLOCKED); }
        void UnlockReagentBank() { SetPlayerFlagEx(PLAYER_FLAGS_EX_REAGENT_BANK_UNLOCKED); }

        bool IsAdvancedCombatLoggingEnabled() const { return _advancedCombatLoggingEnabled; }
        void SetAdvancedCombatLogging(bool enabled) { _advancedCombatLoggingEnabled = enabled; }

        SceneMgr& GetSceneMgr() { return m_sceneMgr; }
        SceneMgr const& GetSceneMgr() const { return m_sceneMgr; }
        RestMgr& GetRestMgr() const { return *_restMgr; }
        void SetRestState(RestTypes type, PlayerRestState state)
        {
            SetUpdateFieldValue(m_values
                .ModifyValue(&Player::m_activePlayerData)
                .ModifyValue(&UF::ActivePlayerData::RestInfo, type)
                .ModifyValue(&UF::RestInfo::StateID), state);
        }
        void SetRestThreshold(RestTypes type, uint32 threshold)
        {
            SetUpdateFieldValue(m_values
                .ModifyValue(&Player::m_activePlayerData)
                .ModifyValue(&UF::ActivePlayerData::RestInfo, type)
                .ModifyValue(&UF::RestInfo::Threshold), threshold);
        }

        void SendPlayerChoice(ObjectGuid sender, int32 choiceId);

        bool MeetPlayerCondition(uint32 conditionId) const;

        bool HasPlayerFlag(PlayerFlags flags) const { return (*m_playerData->PlayerFlags & flags) != 0; }
        void SetPlayerFlag(PlayerFlags flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::PlayerFlags), flags); }
        void RemovePlayerFlag(PlayerFlags flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::PlayerFlags), flags); }
        void ReplaceAllPlayerFlags(PlayerFlags flags) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::PlayerFlags), flags); }

        bool HasPlayerFlagEx(PlayerFlagsEx flags) const { return (*m_playerData->PlayerFlagsEx & flags) != 0; }
        void SetPlayerFlagEx(PlayerFlagsEx flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::PlayerFlagsEx), flags); }
        void RemovePlayerFlagEx(PlayerFlagsEx flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::PlayerFlagsEx), flags); }
        void ReplaceAllPlayerFlagsEx(PlayerFlagsEx flags) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::PlayerFlagsEx), flags); }

        void SetAverageItemLevelTotal(float newItemLevel) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::AvgItemLevel, 0), newItemLevel); }
        void SetAverageItemLevelEquipped(float newItemLevel) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::AvgItemLevel, 1), newItemLevel); }

        uint32 GetCustomizationChoice(uint32 chrCustomizationOptionId) const
        {
            int32 choiceIndex = m_playerData->Customizations.FindIndexIf([chrCustomizationOptionId](UF::ChrCustomizationChoice choice)
            {
                return choice.ChrCustomizationOptionID == chrCustomizationOptionId;
            });

            if (choiceIndex >= 0)
                return m_playerData->Customizations[choiceIndex].ChrCustomizationChoiceID;

            return 0;
        }

        template<typename Iter>
        void SetCustomizations(Trinity::IteratorPair<Iter> customizations, bool markChanged = true)
        {
            if (markChanged)
                m_customizationsChanged = true;

            ClearDynamicUpdateFieldValues(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::Customizations));
            for (auto&& customization : customizations)
            {
                UF::ChrCustomizationChoice& newChoice = AddDynamicUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::Customizations));
                newChoice.ChrCustomizationOptionID = customization.ChrCustomizationOptionID;
                newChoice.ChrCustomizationChoiceID = customization.ChrCustomizationChoiceID;
            }
        }
        void SetPvpTitle(uint8 pvpTitle) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::PvpTitle), pvpTitle); }
        void SetArenaFaction(uint8 arenaFaction) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::ArenaFaction), arenaFaction); }
        void ApplyModFakeInebriation(int32 mod, bool apply) { ApplyModUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::FakeInebriation), mod, apply); }
        void SetVirtualPlayerRealm(uint32 virtualRealmAddress) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::VirtualPlayerRealm), virtualRealmAddress); }
        void SetCurrentBattlePetBreedQuality(uint8 battlePetBreedQuality) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_playerData).ModifyValue(&UF::PlayerData::CurrentBattlePetBreedQuality), battlePetBreedQuality);  }

        void AddHeirloom(int32 itemId, uint32 flags)
        {
            AddDynamicUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::Heirlooms)) = itemId;
            AddDynamicUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::HeirloomFlags)) = flags;
        }
        void SetHeirloom(uint32 slot, int32 itemId) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::Heirlooms, slot), itemId); }
        void SetHeirloomFlags(uint32 slot, uint32 flags) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::HeirloomFlags, slot), flags); }

        void AddToy(int32 itemId, uint32 /*flags*/) { AddDynamicUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::Toys)) = itemId; }

        void AddTransmogBlock(uint32 blockValue) { AddDynamicUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::Transmog)) = blockValue; }
        void AddTransmogFlag(uint32 slot, uint32 flag) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::Transmog, slot), flag); }

        void AddConditionalTransmog(uint32 itemModifiedAppearanceId) { AddDynamicUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::ConditionalTransmog)) = itemModifiedAppearanceId; }
        void RemoveConditionalTransmog(uint32 itemModifiedAppearanceId)
        {
            int32 index = m_activePlayerData->ConditionalTransmog.FindIndex(itemModifiedAppearanceId);
            if (index >= 0)
                RemoveDynamicUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::ConditionalTransmog), uint32(index));
        }

        void AddSelfResSpell(int32 spellId) { AddDynamicUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::SelfResSpells)) = spellId; }
        void RemoveSelfResSpell(int32 spellId)
        {
            int32 index = m_activePlayerData->SelfResSpells.FindIndex(spellId);
            if (index >= 0)
                RemoveDynamicUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::SelfResSpells), uint32(index));
        }
        void ClearSelfResSpell() { ClearDynamicUpdateFieldValues(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::SelfResSpells)); }

        ObjectGuid GetSummonedBattlePetGUID() const { return m_activePlayerData->SummonedBattlePetGUID; }
        void SetSummonedBattlePetGUID(ObjectGuid guid) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::SummonedBattlePetGUID), guid); }

        void SetTrackCreatureFlag(uint32 flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::TrackCreatureMask), flags); }
        void RemoveTrackCreatureFlag(uint32 flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::TrackCreatureMask), flags); }

        void SetVersatilityBonus(float value) { SetUpdateFieldStatValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::VersatilityBonus), value); }

        void ApplyModOverrideSpellPowerByAPPercent(float mod, bool apply) { ApplyModUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::OverrideSpellPowerByAPPercent), mod, apply); }

        void ApplyModOverrideAPBySpellPowerPercent(float mod, bool apply) { ApplyModUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::OverrideAPBySpellPowerPercent), mod, apply); }

        bool HasPlayerLocalFlag(PlayerLocalFlags flags) const { return (*m_activePlayerData->LocalFlags & flags) != 0; }
        void SetPlayerLocalFlag(PlayerLocalFlags flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::LocalFlags), flags); }
        void RemovePlayerLocalFlag(PlayerLocalFlags flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::LocalFlags), flags); }
        void ReplaceAllPlayerLocalFlags(PlayerLocalFlags flags) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::LocalFlags), flags); }

        uint8 GetNumRespecs() const { return m_activePlayerData->NumRespecs; }
        void SetNumRespecs(uint8 numRespecs) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::NumRespecs), numRespecs); }

        void SetWatchedFactionIndex(int32 index) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::WatchedFactionIndex), index); }

        void AddAuraVision(PlayerFieldByte2Flags flags) { SetUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::AuraVision), flags); }
        void RemoveAuraVision(PlayerFieldByte2Flags flags) { RemoveUpdateFieldFlagValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::AuraVision), flags); }

        void SetTransportServerTime(int32 transportServerTime) { SetUpdateFieldValue(m_values.ModifyValue(&Player::m_activePlayerData).ModifyValue(&UF::ActivePlayerData::TransportServerTime), transportServerTime); }

        bool IsInFriendlyArea() const;
        bool IsFriendlyArea(AreaTableEntry const* inArea) const;

        void SetWarModeDesired(bool enabled);
        bool IsWarModeDesired() const { return HasPlayerFlag(PLAYER_FLAGS_WAR_MODE_DESIRED); }
        bool IsWarModeActive() const { return HasPlayerFlag(PLAYER_FLAGS_WAR_MODE_ACTIVE); }
        bool IsWarModeLocalActive() const { return HasPlayerLocalFlag(PLAYER_LOCAL_FLAG_WAR_MODE); }
        void SetWarModeLocal(bool enabled);
        bool CanEnableWarModeInArea() const;
        void UpdateWarModeAuras();

        std::string GetDebugInfo() const override;

        UF::UpdateField<UF::PlayerData, 0, TYPEID_PLAYER> m_playerData;
        UF::UpdateField<UF::ActivePlayerData, 0, TYPEID_ACTIVE_PLAYER> m_activePlayerData;

        void SetAreaSpiritHealer(Creature* creature);
        ObjectGuid const& GetSpiritHealerGUID() const { return _areaSpiritHealerGUID; }
        bool CanAcceptAreaSpiritHealFrom(Unit* spiritHealer) const { return spiritHealer->GetGUID() == _areaSpiritHealerGUID; }
        void SendAreaSpiritHealerTime(Unit* spiritHealer) const;
        void SendAreaSpiritHealerTime(ObjectGuid const& spiritHealerGUID, int32 timeLeft) const;

    protected:
        // Gamemaster whisper whitelist
        GuidList WhisperList;
        TimePoint m_regenInterruptTimestamp;
        uint32 m_regenTimerCount;
        uint32 m_foodEmoteTimerCount;
        std::array<float, MAX_POWERS_PER_CLASS> m_powerFraction;
        uint32 m_contestedPvPTimer;

        /*********************************************************/
        /***               BATTLEGROUND SYSTEM                 ***/
        /*********************************************************/

        /*
        this is an array of BG queues (BgTypeIDs) in which is player
        */
        struct BgBattlegroundQueueID_Rec
        {
            BattlegroundQueueTypeId bgQueueTypeId;
            uint32 invitedToInstance;
            uint32 joinTime;
            bool mercenary;
        };

        BgBattlegroundQueueID_Rec m_bgBattlegroundQueueID[PLAYER_MAX_BATTLEGROUND_QUEUES];
        BGData                    m_bgData;

        bool m_IsBGRandomWinner;

        /*********************************************************/
        /***                    QUEST SYSTEM                   ***/
        /*********************************************************/

        void PushQuests();

        //We allow only one timed quest active at the same time. Below can then be simple value instead of set.
        typedef std::set<uint32> QuestSet;
        typedef std::unordered_map<uint32, time_t> SeasonalQuestMapByQuest;
        typedef std::unordered_map<uint32, SeasonalQuestMapByQuest> SeasonalQuestMapByEvent;
        QuestSet m_timedquests;
        QuestSet m_weeklyquests;
        QuestSet m_monthlyquests;
        SeasonalQuestMapByEvent m_seasonalquests;

        ObjectGuid m_playerSharingQuest;
        uint32 m_sharedQuestId;
        uint32 m_ingametime;

        /*********************************************************/
        /***                   LOAD SYSTEM                     ***/
        /*********************************************************/

        void _LoadActions(PreparedQueryResult result);
        void _LoadAuras(PreparedQueryResult auraResult, PreparedQueryResult effectResult, uint32 timediff);
        void _LoadGlyphAuras();
        void _LoadInventory(PreparedQueryResult result, uint32 timeDiff);
        void _LoadVoidStorage(PreparedQueryResult result);
        void _LoadMail(PreparedQueryResult mailsResult, PreparedQueryResult mailItemsResult);
        static Item* _LoadMailedItem(ObjectGuid const& playerGuid, Player* player, uint64 mailId, Mail* mail, Field* fields);
        void _LoadQuestStatus(PreparedQueryResult result);
        void _LoadQuestStatusObjectives(PreparedQueryResult result);
        void _LoadQuestStatusRewarded(PreparedQueryResult result);
        void _LoadDailyQuestStatus(PreparedQueryResult result);
        void _LoadWeeklyQuestStatus(PreparedQueryResult result);
        void _LoadMonthlyQuestStatus(PreparedQueryResult result);
        void _LoadSeasonalQuestStatus(PreparedQueryResult result);
        void _LoadRandomBGStatus(PreparedQueryResult result);
        void _LoadGroup(PreparedQueryResult result);
        void _LoadSkills(PreparedQueryResult result);
        void _LoadSpells(PreparedQueryResult result, PreparedQueryResult favoritesResult);
        void _LoadStoredAuraTeleportLocations(PreparedQueryResult result);
        bool _LoadHomeBind(PreparedQueryResult result);
        void _LoadDeclinedNames(PreparedQueryResult result);
        void _LoadArenaTeamInfo(PreparedQueryResult result);
        void _LoadEquipmentSets(PreparedQueryResult result);
        void _LoadTransmogOutfits(PreparedQueryResult result);
        void _LoadBGData(PreparedQueryResult result);
        void _LoadGlyphs(PreparedQueryResult result);
        void _LoadTalents(PreparedQueryResult result);
        void _LoadTraits(PreparedQueryResult configsResult, PreparedQueryResult entriesResult);
        void _LoadInstanceTimeRestrictions(PreparedQueryResult result);
        void _LoadPetStable(uint32 summonedPetNumber, PreparedQueryResult result);
        void _LoadCurrency(PreparedQueryResult result);
        void _LoadCUFProfiles(PreparedQueryResult result);

        /*********************************************************/
        /***                   SAVE SYSTEM                     ***/
        /*********************************************************/

        void _SaveCustomizations(CharacterDatabaseTransaction trans);
        void _SaveActions(CharacterDatabaseTransaction trans);
        void _SaveAuras(CharacterDatabaseTransaction trans);
        void _SaveInventory(CharacterDatabaseTransaction trans);
        void _SaveVoidStorage(CharacterDatabaseTransaction trans);
        void _SaveMail(CharacterDatabaseTransaction trans);
        void _SaveQuestStatus(CharacterDatabaseTransaction trans);
        void _SaveDailyQuestStatus(CharacterDatabaseTransaction trans);
        void _SaveWeeklyQuestStatus(CharacterDatabaseTransaction trans);
        void _SaveMonthlyQuestStatus(CharacterDatabaseTransaction trans);
        void _SaveSeasonalQuestStatus(CharacterDatabaseTransaction trans);
        void _SaveSkills(CharacterDatabaseTransaction trans);
        void _SaveSpells(CharacterDatabaseTransaction trans);
        void _SaveStoredAuraTeleportLocations(CharacterDatabaseTransaction trans);
        void _SaveEquipmentSets(CharacterDatabaseTransaction trans);
        void _SaveBGData(CharacterDatabaseTransaction trans);
        void _SaveGlyphs(CharacterDatabaseTransaction trans) const;
        void _SaveTalents(CharacterDatabaseTransaction trans);
        void _SaveTraits(CharacterDatabaseTransaction trans);
        void _SaveStats(CharacterDatabaseTransaction trans) const;
        void _SaveInstanceTimeRestrictions(CharacterDatabaseTransaction trans);
        void _SaveCurrency(CharacterDatabaseTransaction trans);
        void _SaveCUFProfiles(CharacterDatabaseTransaction trans);

        /*********************************************************/
        /***              ENVIRONMENTAL SYSTEM                 ***/
        /*********************************************************/
        void HandleSobering();
        void SendMirrorTimer(MirrorTimerType Type, uint32 MaxValue, uint32 CurrentValue, int32 Regen);
        void StopMirrorTimer(MirrorTimerType Type);
        void HandleDrowning(uint32 time_diff);
        int32 getMaxTimer(MirrorTimerType timer) const;

        /*********************************************************/
        /***                  HONOR SYSTEM                     ***/
        /*********************************************************/
        time_t m_lastHonorUpdateTime;

        void outDebugValues() const;

        Team m_team;
        uint32 m_nextSave;
        bool m_customizationsChanged;
        std::array<ChatFloodThrottle, ChatFloodThrottle::MAX> m_chatFloodData;
        Difficulty m_dungeonDifficulty;
        Difficulty m_raidDifficulty;
        Difficulty m_legacyRaidDifficulty;

        uint32 m_atLoginFlags;

        Item* m_items[PLAYER_SLOTS_COUNT];
        uint32 m_currentBuybackSlot;

        PlayerCurrenciesMap _currencyStorage;

        VoidStorageItem* _voidStorageItems[VOID_STORAGE_MAX_SLOT];

        std::vector<Item*> m_itemUpdateQueue;
        bool m_itemUpdateQueueBlocked;

        uint32 m_ExtraFlags;

        QuestStatusMap m_QuestStatus;
        QuestObjectiveStatusMap m_questObjectiveStatus;
        QuestStatusSaveMap m_QuestStatusSave;

        RewardedQuestSet m_RewardedQuests;
        QuestStatusSaveMap m_RewardedQuestsSave;

        SkillStatusMap mSkillStatus;

        ObjectGuid::LowType m_GuildIdInvited;
        uint32 m_ArenaTeamIdInvited;

        PlayerMails m_mail;
        PlayerSpellMap m_spells;
        std::unordered_map<uint32 /*overridenSpellId*/, std::unordered_set<uint32> /*newSpellId*/> m_overrideSpells;
        uint32 m_lastPotionId;                              // last used health/mana potion in combat, that block next potion use
        std::unordered_map<uint32, StoredAuraTeleportLocation> m_storedAuraTeleportLocations;

        SpecializationInfo _specializationInfo;

        std::unordered_map<int32, PlayerSpellState> m_traitConfigStates;

        ActionButtonList m_actionButtons;

        std::array<float, BASEMOD_END> m_auraBaseFlatMod;
        std::array<float, BASEMOD_END> m_auraBasePctMod;
        std::array<int16, MAX_COMBAT_RATING> m_baseRatingValue;
        uint32 m_baseSpellPower;
        uint32 m_baseManaRegen;
        uint32 m_baseHealthRegen;
        int32 m_spellPenetrationItemMod;

        SpellModContainer m_spellMods[MAX_SPELLMOD][SPELLMOD_END];

        EnchantDurationList m_enchantDuration;
        ItemDurationList m_itemDuration;
        GuidUnorderedSet m_itemSoulboundTradeable;

        std::unique_ptr<ResurrectionData> _resurrectionData;

        WorldSession* m_session;

        JoinedChannelsList m_channels;

        time_t m_createTime;
        PlayerCreateMode m_createMode;
        uint8 m_cinematic;

        uint32 m_movie;

        TradeData* m_trade;

        bool   m_DailyQuestChanged;
        bool   m_WeeklyQuestChanged;
        bool   m_MonthlyQuestChanged;
        bool   m_SeasonalQuestChanged;
        time_t m_lastDailyQuestTime;

        uint32 m_hostileReferenceCheckTimer;
        uint32 m_drunkTimer;
        uint32 m_weaponChangeTimer;

        uint32 m_zoneUpdateId;
        uint32 m_zoneUpdateTimer;
        uint32 m_areaUpdateId;

        uint32 m_deathTimer;
        time_t m_deathExpireTime;

        uint32 m_WeaponProficiency;
        uint32 m_ArmorProficiency;
        bool m_canParry;
        bool m_canBlock;
        bool m_canTitanGrip;
        uint32 m_titanGripPenaltySpellId;
        Optional<AttackSwingErr> m_swingErrorMsg;

        // Social
        PlayerSocial* m_social;

        // Groups
        GroupReference m_group;
        GroupReference m_originalGroup;
        Group* m_groupInvite;
        uint32 m_groupUpdateMask;
        bool m_bPassOnGroupLoot;
        std::array<GroupUpdateCounter, 2> m_groupUpdateSequences;

        // last used pet number (for BG's)
        uint32 m_lastpetnumber;

        // Player summoning
        time_t m_summon_expire;
        WorldLocation m_summon_location;
        uint32 m_summon_instanceId;

        // Recall position
        WorldLocation m_recall_location;
        uint32 m_recall_instanceId;

        std::unique_ptr< DeclinedName> m_declinedname;
        std::unique_ptr<Runes> m_runes;
        EquipmentSetContainer _equipmentSets;

        bool CanNeverSee(WorldObject const* obj) const override;
        bool CanAlwaysSee(WorldObject const* obj) const override;

        bool IsAlwaysDetectableFor(WorldObject const* seer) const override;

        uint8 m_fishingSteps;

        std::array<std::unique_ptr<CUFProfile>, MAX_CUF_PROFILES> _CUFProfiles;

        TimeTracker m_groupUpdateTimer;

    private:
        // internal common parts for CanStore/StoreItem functions
        InventoryResult CanStoreItem_InSpecificSlot(uint8 bag, uint8 slot, ItemPosCountVec& dest, ItemTemplate const* pProto, uint32& count, bool swap, Item* pSrcItem) const;
        InventoryResult CanStoreItem_InBag(uint8 bag, ItemPosCountVec& dest, ItemTemplate const* pProto, uint32& count, bool merge, bool non_specialized, Item* pSrcItem, uint8 skip_bag, uint8 skip_slot) const;
        InventoryResult CanStoreItem_InInventorySlots(uint8 slot_begin, uint8 slot_end, ItemPosCountVec& dest, ItemTemplate const* pProto, uint32& count, bool merge, Item* pSrcItem, uint8 skip_bag, uint8 skip_slot) const;
        Item* _StoreItem(uint16 pos, Item* pItem, uint32 count, bool clone, bool update);
        Item* _LoadItem(CharacterDatabaseTransaction trans, uint32 zoneId, uint32 timeDiff, Field* fields);

        std::unique_ptr<CinematicMgr> _cinematicMgr;

        GuidSet m_refundableItems;
        void SendRefundInfo(Item* item);
        void RefundItem(Item* item);
        void SendItemRefundResult(Item* item, ItemExtendedCostEntry const* iece, uint8 error) const;

        void AdjustQuestObjectiveProgress(Quest const* quest);

        bool IsCanDelayTeleport() const { return m_bCanDelayTeleport; }
        void SetCanDelayTeleport(bool setting) { m_bCanDelayTeleport = setting; }
        bool IsHasDelayedTeleport() const { return m_bHasDelayedTeleport; }
        void SetDelayedTeleportFlag(bool setting) { m_bHasDelayedTeleport = setting; }
        void ScheduleDelayedOperation(uint32 operation) { if (operation < DELAYED_END) m_DelayedOperations |= operation; }

        bool IsInstanceLoginGameMasterException() const;

        MapReference m_mapRef;

        uint32 m_lastFallTime;
        float  m_lastFallZ;

        std::array<int32, MAX_TIMERS> m_MirrorTimer;
        uint8 m_MirrorTimerFlags;
        uint8 m_MirrorTimerFlagsLast;

        // Current teleport data
        WorldLocation m_teleport_dest;
        Optional<uint32> m_teleport_instanceId;
        TeleportToOptions m_teleport_options;
        bool mSemaphoreTeleport_Near;
        bool mSemaphoreTeleport_Far;

        uint32 m_DelayedOperations;
        bool m_bCanDelayTeleport;
        bool m_bHasDelayedTeleport;

        std::unique_ptr<PetStable> m_petStable;

        // Temporary removed pet cache
        uint32 m_temporaryUnsummonedPetNumber;
        Optional<ReactStates> m_temporaryPetReactState;
        uint32 m_oldpetspell;

        std::unique_ptr<PlayerAchievementMgr> m_achievementMgr;
        std::unique_ptr<ReputationMgr> m_reputationMgr;
        std::unique_ptr<QuestObjectiveCriteriaMgr> m_questObjectiveCriteriaMgr;

        uint32 m_ChampioningFaction;

        InstanceTimeMap _instanceResetTimes;
        uint32 _pendingBindId;
        uint32 _pendingBindTimer;

        uint32 _activeCheats;

        bool _advancedCombatLoggingEnabled;

        // variables to save health and mana before duel and restore them after duel
        uint64 healthBeforeDuel;
        uint32 manaBeforeDuel;

        WorldLocation _corpseLocation;

        SceneMgr m_sceneMgr;

        std::unordered_map<ObjectGuid /*LootObject*/, Loot*> m_AELootView;
        std::vector<LootRoll*> m_lootRolls;                                     // loot rolls waiting for answer

        void _InitHonorLevelOnLoadFromDB(uint32 honor, uint32 honorLevel);
        std::unique_ptr<RestMgr> _restMgr;

        bool _usePvpItemLevels;
        ObjectGuid _areaSpiritHealerGUID;

        // Spell cast request handling
    public:
        // Queues up a spell cast request that has been received via packet and processes it whenever possible.
        void RequestSpellCast(std::unique_ptr<SpellCastRequest> castRequest);
        void CancelPendingCastRequest();
        bool CanRequestSpellCast(SpellInfo const* spell, Unit const* castingUnit) const;

    private:
        std::unique_ptr<SpellCastRequest> _pendingSpellCastRequest;
        void ExecutePendingSpellCastRequest();
        bool ProcessItemCast(SpellCastRequest& castRequest, SpellCastTargets const& targets);
        bool CanExecutePendingSpellCastRequest();
};

TC_GAME_API void AddItemsSetItem(Player* player, Item const* item);
TC_GAME_API void RemoveItemsSetItem(Player* player, Item const* item);

// Transforms a container of customization choices with continuous storage into iterator pair that does not depend on container
// and doesn't force implementations in header files
template<typename Container>
Trinity::IteratorPair<UF::ChrCustomizationChoice const*> MakeChrCustomizationChoiceRange(Container const& container)
{
    static_assert(std::is_same<typename Container::value_type, UF::ChrCustomizationChoice>::value,
        "MakeChrCustomizationChoiceRange must be used with containers of UF::ChrCustomizationChoice");

    return { container.data(), container.data() + container.size() };
}

#endif
