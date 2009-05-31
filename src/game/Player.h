/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#ifndef _PLAYER_H
#define _PLAYER_H

#include "Common.h"
#include "ItemPrototype.h"
#include "Unit.h"
#include "Item.h"

#include "Database/DatabaseEnv.h"
#include "NPCHandler.h"
#include "QuestDef.h"
#include "Group.h"
#include "Bag.h"
#include "WorldSession.h"
#include "Pet.h"
#include "MapReference.h"
#include "Util.h"                                           // for Tokens typedef
#include "AchievementMgr.h"
#include "ReputationMgr.h"
#include "BattleGround.h"

#include<string>
#include<vector>

struct Mail;
class Channel;
class DynamicObject;
class Creature;
class Pet;
class PlayerMenu;
class UpdateMask;
class SpellCastTargets;
class PlayerSocial;
class OutdoorPvP;

typedef std::deque<Mail*> PlayerMails;

#define PLAYER_MAX_SKILLS       127
#define PLAYER_MAX_DAILY_QUESTS 25
#define AT_LOAD_PET_FLAGS 16

// Note: SPELLMOD_* values is aura types in fact
enum SpellModType
{
    SPELLMOD_FLAT         = 107,                            // SPELL_AURA_ADD_FLAT_MODIFIER
    SPELLMOD_PCT          = 108                             // SPELL_AURA_ADD_PCT_MODIFIER
};

// 2^n values, Player::m_isunderwater is a bitmask. These are mangos internal values, they are never send to any client
enum PlayerUnderwaterState
{
    UNDERWATER_NONE                     = 0x00,
    UNDERWATER_INWATER                  = 0x01,             // terrain type is water and player is afflicted by it
    UNDERWATER_INLAVA                   = 0x02,             // terrain type is lava and player is afflicted by it
    UNDERWATER_INSLIME                  = 0x04,             // terrain type is lava and player is afflicted by it
    UNDERWARER_INDARKWATER              = 0x08,             // terrain type is dark water and player is afflicted by it

    UNDERWATER_EXIST_TIMERS             = 0x10
};

enum PlayerSpellState
{
    PLAYERSPELL_UNCHANGED = 0,
    PLAYERSPELL_CHANGED   = 1,
    PLAYERSPELL_NEW       = 2,
    PLAYERSPELL_REMOVED   = 3
};

struct PlayerSpell
{
    PlayerSpellState state : 8;
    bool active            : 1;                             // show in spellbook
    bool dependent         : 1;                             // learned as result another spell learn, skill grow, quest reward, etc
    bool disabled          : 1;                             // first rank has been learned in result talent learn but currently talent unlearned, save max learned ranks
};

// Spell modifier (used for modify other spells)
struct SpellModifier
{
    SpellModifier() : charges(0), lastAffected(NULL) {}
    SpellModOp   op   : 8;
    SpellModType type : 8;
    int16 charges     : 16;
    int32 value;
    flag96 mask;
    uint32 spellId;
    Spell const* lastAffected;
};

typedef UNORDERED_MAP<uint32, PlayerSpell*> PlayerSpellMap;
typedef std::list<SpellModifier*> SpellModList;

struct SpellCooldown
{
    time_t end;
    uint16 itemid;
};

typedef std::map<uint32, SpellCooldown> SpellCooldowns;

enum TrainerSpellState
{
    TRAINER_SPELL_GREEN = 0,
    TRAINER_SPELL_RED   = 1,
    TRAINER_SPELL_GRAY  = 2,
    TRAINER_SPELL_GREEN_DISABLED = 10                       // custom value, not send to client: formally green but learn not allowed
};

enum ActionButtonUpdateState
{
    ACTIONBUTTON_UNCHANGED = 0,
    ACTIONBUTTON_CHANGED   = 1,
    ACTIONBUTTON_NEW       = 2,
    ACTIONBUTTON_DELETED   = 3
};

struct ActionButton
{
    ActionButton() : action(0), type(0), misc(0), uState( ACTIONBUTTON_NEW ) {}
    ActionButton(uint16 _action, uint8 _type, uint8 _misc) : action(_action), type(_type), misc(_misc), uState( ACTIONBUTTON_NEW ) {}

    uint16 action;
    uint8 type;
    uint8 misc;
    ActionButtonUpdateState uState;
};

enum ActionButtonType
{
    ACTION_BUTTON_SPELL = 0,
    ACTION_BUTTON_EQSET = 32,
    ACTION_BUTTON_MACRO = 64,
    ACTION_BUTTON_CMACRO= 65,
    ACTION_BUTTON_ITEM  = 128
};

#define  MAX_ACTION_BUTTONS 132                             //checked in 2.3.0

typedef std::map<uint8,ActionButton> ActionButtonList;

struct PlayerCreateInfoItem
{
    PlayerCreateInfoItem(uint32 id, uint32 amount) : item_id(id), item_amount(amount) {}

    uint32 item_id;
    uint32 item_amount;
};

typedef std::list<PlayerCreateInfoItem> PlayerCreateInfoItems;

struct PlayerClassLevelInfo
{
    PlayerClassLevelInfo() : basehealth(0), basemana(0) {}
    uint16 basehealth;
    uint16 basemana;
};

struct PlayerClassInfo
{
    PlayerClassInfo() : levelInfo(NULL) { }

    PlayerClassLevelInfo* levelInfo;                        //[level-1] 0..MaxPlayerLevel-1
};

struct PlayerLevelInfo
{
    PlayerLevelInfo() { for(int i=0; i < MAX_STATS; ++i ) stats[i] = 0; }

    uint8 stats[MAX_STATS];
};

typedef std::list<uint32> PlayerCreateInfoSpells;

struct PlayerInfo
{
                                                            // existence checked by displayId != 0             // existence checked by displayId != 0
    PlayerInfo() : displayId_m(0),displayId_f(0),levelInfo(NULL)
    {
    }

    uint32 mapId;
    uint32 zoneId;
    float positionX;
    float positionY;
    float positionZ;
    uint16 displayId_m;
    uint16 displayId_f;
    PlayerCreateInfoItems item;
    PlayerCreateInfoSpells spell;
    std::list<uint16> action[4];

    PlayerLevelInfo* levelInfo;                             //[level-1] 0..MaxPlayerLevel-1
};

struct PvPInfo
{
    PvPInfo() : inHostileArea(false), inNoPvPArea(false), inFFAPvPArea(false), endTimer(0) {}

    bool inHostileArea;
    bool inNoPvPArea;
    bool inFFAPvPArea;
    time_t endTimer;
};

struct DuelInfo
{
    DuelInfo() : initiator(NULL), opponent(NULL), startTimer(0), startTime(0), outOfBound(0) {}

    Player *initiator;
    Player *opponent;
    time_t startTimer;
    time_t startTime;
    time_t outOfBound;
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

#define MAX_RUNES       6
#define RUNE_COOLDOWN   5                                   // 5*2=10 sec

enum RuneType
{
    RUNE_BLOOD      = 0,
    RUNE_UNHOLY     = 1,
    RUNE_FROST      = 2,
    RUNE_DEATH      = 3,
    NUM_RUNE_TYPES  = 4
};

struct RuneInfo
{
    uint8 BaseRune;
    uint8 CurrentRune;
    uint8 Cooldown;
};

struct Runes
{
    RuneInfo runes[MAX_RUNES];
    uint8 runeState;                                        // mask of available runes

    void SetRuneState(uint8 index, bool set = true)
    {
        if(set)
            runeState |= (1 << index);                      // usable
        else
            runeState &= ~(1 << index);                     // on cooldown
    }
};

struct EnchantDuration
{
    EnchantDuration() : item(NULL), slot(MAX_ENCHANTMENT_SLOT), leftduration(0) {};
    EnchantDuration(Item * _item, EnchantmentSlot _slot, uint32 _leftduration) : item(_item), slot(_slot), 
        leftduration(_leftduration){ assert(item); };

    Item * item;
    EnchantmentSlot slot;
    uint32 leftduration;
};

typedef std::list<EnchantDuration> EnchantDurationList;
typedef std::list<Item*> ItemDurationList;

enum LfgType
{
    LFG_TYPE_NONE           = 0,
    LFG_TYPE_DUNGEON        = 1,
    LFG_TYPE_RAID           = 2,
    LFG_TYPE_QUEST          = 3,
    LFG_TYPE_ZONE           = 4,
    LFG_TYPE_HEROIC_DUNGEON = 5
};

enum LfgRoles
{
    LEADER  = 1,
    TANK    = 2,
    HEALER  = 4,
    DAMAGE  = 8
};

struct LookingForGroupSlot
{
    LookingForGroupSlot() : entry(0), type(0) {}
    bool Empty() const { return !entry && !type; }
    void Clear() { entry = 0; type = 0; }
    void Set(uint32 _entry, uint32 _type ) { entry = _entry; type = _type; }
    bool Is(uint32 _entry, uint32 _type) const { return entry == _entry && type == _type; }
    bool canAutoJoin() const { return entry && (type == LFG_TYPE_DUNGEON || type == LFG_TYPE_HEROIC_DUNGEON); }

    uint32 entry;
    uint32 type;
};

#define MAX_LOOKING_FOR_GROUP_SLOT 3

struct LookingForGroup
{
    LookingForGroup() {}
    bool HaveInSlot(LookingForGroupSlot const& slot) const { return HaveInSlot(slot.entry, slot.type); }
    bool HaveInSlot(uint32 _entry, uint32 _type) const
    {
        for(int i = 0; i < MAX_LOOKING_FOR_GROUP_SLOT; ++i)
            if(slots[i].Is(_entry, _type))
                return true;
        return false;
    }

    bool canAutoJoin() const
    {
        for(int i = 0; i < MAX_LOOKING_FOR_GROUP_SLOT; ++i)
            if(slots[i].canAutoJoin())
                return true;
        return false;
    }

    bool Empty() const
    {
        for(int i = 0; i < MAX_LOOKING_FOR_GROUP_SLOT; ++i)
            if(!slots[i].Empty())
                return false;
        return more.Empty();
    }

    LookingForGroupSlot slots[MAX_LOOKING_FOR_GROUP_SLOT];
    LookingForGroupSlot more;
    std::string comment;
};

enum PlayerMovementType
{
    MOVE_ROOT       = 1,
    MOVE_UNROOT     = 2,
    MOVE_WATER_WALK = 3,
    MOVE_LAND_WALK  = 4
};

enum DrunkenState
{
    DRUNKEN_SOBER   = 0,
    DRUNKEN_TIPSY   = 1,
    DRUNKEN_DRUNK   = 2,
    DRUNKEN_SMASHED = 3
};

enum PlayerFlags
{
    PLAYER_FLAGS_GROUP_LEADER   = 0x00000001,
    PLAYER_FLAGS_AFK            = 0x00000002,
    PLAYER_FLAGS_DND            = 0x00000004,
    PLAYER_FLAGS_GM             = 0x00000008,
    PLAYER_FLAGS_GHOST          = 0x00000010,
    PLAYER_FLAGS_RESTING        = 0x00000020,
    PLAYER_FLAGS_UNK7           = 0x00000040,
    PLAYER_FLAGS_UNK8           = 0x00000080,               // pre-3.0.3 PLAYER_FLAGS_FFA_PVP flag for FFA PVP state
    PLAYER_FLAGS_CONTESTED_PVP  = 0x00000100,               // Player has been involved in a PvP combat and will be attacked by contested guards
    PLAYER_FLAGS_IN_PVP         = 0x00000200,
    PLAYER_FLAGS_HIDE_HELM      = 0x00000400,
    PLAYER_FLAGS_HIDE_CLOAK     = 0x00000800,
    PLAYER_FLAGS_UNK13          = 0x00001000,               // played long time
    PLAYER_FLAGS_UNK14          = 0x00002000,               // played too long time
    PLAYER_FLAGS_UNK15          = 0x00004000,
    PLAYER_FLAGS_UNK16          = 0x00008000,               // strange visual effect (2.0.1), looks like PLAYER_FLAGS_GHOST flag
    PLAYER_FLAGS_UNK17          = 0x00010000,               // pre-3.0.3 PLAYER_FLAGS_SANCTUARY flag for player entered sanctuary
    PLAYER_FLAGS_UNK18          = 0x00020000,               // taxi benchmark mode (on/off) (2.0.1)
    PLAYER_FLAGS_PVP_TIMER      = 0x00040000,               // 3.0.2, pvp timer active (after you disable pvp manually)
    PLAYER_FLAGS_UNK20          = 0x00080000,
    PLAYER_FLAGS_UNK21          = 0x00100000,
    PLAYER_FLAGS_UNK22          = 0x00200000,
    PLAYER_FLAGS_UNK23          = 0x00400000,
    PLAYER_ALLOW_ONLY_ABILITY   = 0x00800000,                // used by bladestorm and killing spree
    PLAYER_FLAGS_UNK25          = 0x01000000                 // disabled all melee ability on tab include autoattack
};

// used for PLAYER__FIELD_KNOWN_TITLES field (uint64), (1<<bit_index) without (-1)
// can't use enum for uint64 values
#define PLAYER_TITLE_DISABLED              0x0000000000000000LL
#define PLAYER_TITLE_NONE                  0x0000000000000001LL
#define PLAYER_TITLE_PRIVATE               0x0000000000000002LL // 1
#define PLAYER_TITLE_CORPORAL              0x0000000000000004LL // 2
#define PLAYER_TITLE_SERGEANT_A            0x0000000000000008LL // 3
#define PLAYER_TITLE_MASTER_SERGEANT       0x0000000000000010LL // 4
#define PLAYER_TITLE_SERGEANT_MAJOR        0x0000000000000020LL // 5
#define PLAYER_TITLE_KNIGHT                0x0000000000000040LL // 6
#define PLAYER_TITLE_KNIGHT_LIEUTENANT     0x0000000000000080LL // 7
#define PLAYER_TITLE_KNIGHT_CAPTAIN        0x0000000000000100LL // 8
#define PLAYER_TITLE_KNIGHT_CHAMPION       0x0000000000000200LL // 9
#define PLAYER_TITLE_LIEUTENANT_COMMANDER  0x0000000000000400LL // 10
#define PLAYER_TITLE_COMMANDER             0x0000000000000800LL // 11
#define PLAYER_TITLE_MARSHAL               0x0000000000001000LL // 12
#define PLAYER_TITLE_FIELD_MARSHAL         0x0000000000002000LL // 13
#define PLAYER_TITLE_GRAND_MARSHAL         0x0000000000004000LL // 14
#define PLAYER_TITLE_SCOUT                 0x0000000000008000LL // 15
#define PLAYER_TITLE_GRUNT                 0x0000000000010000LL // 16
#define PLAYER_TITLE_SERGEANT_H            0x0000000000020000LL // 17
#define PLAYER_TITLE_SENIOR_SERGEANT       0x0000000000040000LL // 18
#define PLAYER_TITLE_FIRST_SERGEANT        0x0000000000080000LL // 19
#define PLAYER_TITLE_STONE_GUARD           0x0000000000100000LL // 20
#define PLAYER_TITLE_BLOOD_GUARD           0x0000000000200000LL // 21
#define PLAYER_TITLE_LEGIONNAIRE           0x0000000000400000LL // 22
#define PLAYER_TITLE_CENTURION             0x0000000000800000LL // 23
#define PLAYER_TITLE_CHAMPION              0x0000000001000000LL // 24
#define PLAYER_TITLE_LIEUTENANT_GENERAL    0x0000000002000000LL // 25
#define PLAYER_TITLE_GENERAL               0x0000000004000000LL // 26
#define PLAYER_TITLE_WARLORD               0x0000000008000000LL // 27
#define PLAYER_TITLE_HIGH_WARLORD          0x0000000010000000LL // 28
#define PLAYER_TITLE_GLADIATOR             0x0000000020000000LL // 29
#define PLAYER_TITLE_DUELIST               0x0000000040000000LL // 30
#define PLAYER_TITLE_RIVAL                 0x0000000080000000LL // 31
#define PLAYER_TITLE_CHALLENGER            0x0000000100000000LL // 32
#define PLAYER_TITLE_SCARAB_LORD           0x0000000200000000LL // 33
#define PLAYER_TITLE_CONQUEROR             0x0000000400000000LL // 34
#define PLAYER_TITLE_JUSTICAR              0x0000000800000000LL // 35
#define PLAYER_TITLE_CHAMPION_OF_THE_NAARU 0x0000001000000000LL // 36
#define PLAYER_TITLE_MERCILESS_GLADIATOR   0x0000002000000000LL // 37
#define PLAYER_TITLE_OF_THE_SHATTERED_SUN  0x0000004000000000LL // 38
#define PLAYER_TITLE_HAND_OF_ADAL          0x0000008000000000LL // 39
#define PLAYER_TITLE_VENGEFUL_GLADIATOR    0x0000010000000000LL // 40

// used in PLAYER_FIELD_BYTES values
enum PlayerFieldByteFlags
{
    PLAYER_FIELD_BYTE_TRACK_STEALTHED   = 0x00000002,
    PLAYER_FIELD_BYTE_RELEASE_TIMER     = 0x00000008,       // Display time till auto release spirit
    PLAYER_FIELD_BYTE_NO_RELEASE_WINDOW = 0x00000010        // Display no "release spirit" window at all
};

// used in PLAYER_FIELD_BYTES2 values
enum PlayerFieldByte2Flags
{
    PLAYER_FIELD_BYTE2_NONE              = 0x0000,
    PLAYER_FIELD_BYTE2_INVISIBILITY_GLOW = 0x4000
};

enum ActivateTaxiReplies
{
    ERR_TAXIOK                      = 0,
    ERR_TAXIUNSPECIFIEDSERVERERROR  = 1,
    ERR_TAXINOSUCHPATH              = 2,
    ERR_TAXINOTENOUGHMONEY          = 3,
    ERR_TAXITOOFARAWAY              = 4,
    ERR_TAXINOVENDORNEARBY          = 5,
    ERR_TAXINOTVISITED              = 6,
    ERR_TAXIPLAYERBUSY              = 7,
    ERR_TAXIPLAYERALREADYMOUNTED    = 8,
    ERR_TAXIPLAYERSHAPESHIFTED      = 9,
    ERR_TAXIPLAYERMOVING            = 10,
    ERR_TAXISAMENODE                = 11,
    ERR_TAXINOTSTANDING             = 12
};



enum MirrorTimerType
{
    FATIGUE_TIMER      = 0,
    BREATH_TIMER       = 1,
    FIRE_TIMER         = 2
};
#define MAX_TIMERS      3
#define DISABLED_MIRROR_TIMER   -1

// 2^n values
enum PlayerExtraFlags
{
    // gm abilities
    PLAYER_EXTRA_GM_ON              = 0x0001,
    PLAYER_EXTRA_ACCEPT_WHISPERS    = 0x0004,
    PLAYER_EXTRA_TAXICHEAT          = 0x0008,
    PLAYER_EXTRA_GM_INVISIBLE       = 0x0010,
    PLAYER_EXTRA_GM_CHAT            = 0x0020,               // Show GM badge in chat messages

    // other states
    PLAYER_EXTRA_PVP_DEATH          = 0x0100                // store PvP death status until corpse creating.
};

// 2^n values
enum AtLoginFlags
{
    AT_LOGIN_NONE          = 0,
    AT_LOGIN_RENAME        = 1,
    AT_LOGIN_RESET_SPELLS  = 2,
    AT_LOGIN_RESET_TALENTS = 4,
    AT_LOGIN_CUSTOMIZE     = 8,
};

typedef std::map<uint32, QuestStatusData> QuestStatusMap;

enum QuestSlotOffsets
{
    QUEST_ID_OFFSET     = 0,
    QUEST_STATE_OFFSET  = 1,
    QUEST_COUNTS_OFFSET = 2,
    QUEST_TIME_OFFSET   = 3
};

#define MAX_QUEST_OFFSET 4

enum QuestSlotStateMask
{
    QUEST_STATE_NONE     = 0x0000,
    QUEST_STATE_COMPLETE = 0x0001,
    QUEST_STATE_FAIL     = 0x0002
};

class Quest;
class Spell;
class Item;
class WorldSession;

enum PlayerSlots
{
    // first slot for item stored (in any way in player m_items data)
    PLAYER_SLOT_START           = 0,
    // last+1 slot for item stored (in any way in player m_items data)
    PLAYER_SLOT_END             = 200,
    PLAYER_SLOTS_COUNT          = (PLAYER_SLOT_END - PLAYER_SLOT_START)
};

#define INVENTORY_SLOT_BAG_0    255

enum EquipmentSlots                                         // 19 slots
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

enum InventorySlots                                         // 4 slots
{
    INVENTORY_SLOT_BAG_START    = 19,
    INVENTORY_SLOT_BAG_END      = 23
};

enum InventoryPackSlots                                     // 16 slots
{
    INVENTORY_SLOT_ITEM_START   = 23,
    INVENTORY_SLOT_ITEM_END     = 39
};

enum BankItemSlots                                          // 28 slots
{
    BANK_SLOT_ITEM_START        = 39,
    BANK_SLOT_ITEM_END          = 67
};

enum BankBagSlots                                           // 7 slots
{
    BANK_SLOT_BAG_START         = 67,
    BANK_SLOT_BAG_END           = 74
};

enum BuyBackSlots                                           // 12 slots
{
    // stored in m_buybackitems
    BUYBACK_SLOT_START          = 74,
    BUYBACK_SLOT_END            = 86
};

enum KeyRingSlots                                           // 32 slots
{
    KEYRING_SLOT_START          = 86,
    KEYRING_SLOT_END            = 118
};

enum VanityPetSlots                                         // 18 slots
{
    VANITYPET_SLOT_START        = 118,                      // not use, vanity pets stored as spells
    VANITYPET_SLOT_END          = 136                       // not allowed any content in.
};

enum CurrencyTokenSlots                                     // 32 slots
{
    CURRENCYTOKEN_SLOT_START    = 136,
    CURRENCYTOKEN_SLOT_END      = 168
};

enum QuestBagSlots                                          // 32 slots
{
    QUESTBAG_SLOT_START         = 168,                      // not use
    QUESTBAG_SLOT_END           = 200                       // not allowed any content in.
};

struct ItemPosCount
{
    ItemPosCount(uint16 _pos, uint32 _count) : pos(_pos), count(_count) {}
    bool isContainedIn(std::vector<ItemPosCount> const& vec) const;
    uint16 pos;
    uint32 count;
};
typedef std::vector<ItemPosCount> ItemPosCountVec;

enum TradeSlots
{
    TRADE_SLOT_COUNT            = 7,
    TRADE_SLOT_TRADED_COUNT     = 6,
    TRADE_SLOT_NONTRADED        = 6
};

enum TransferAbortReason
{
    TRANSFER_ABORT_ERROR                    = 0x00,
    TRANSFER_ABORT_MAX_PLAYERS              = 0x01,         // Transfer Aborted: instance is full
    TRANSFER_ABORT_NOT_FOUND                = 0x02,         // Transfer Aborted: instance not found
    TRANSFER_ABORT_TOO_MANY_INSTANCES       = 0x03,         // You have entered too many instances recently.
    TRANSFER_ABORT_ZONE_IN_COMBAT           = 0x05,         // Unable to zone in while an encounter is in progress.
    TRANSFER_ABORT_INSUF_EXPAN_LVL          = 0x06,         // You must have <TBC,WotLK> expansion installed to access this area.
    TRANSFER_ABORT_DIFFICULTY               = 0x07,         // <Normal,Heroic,Epic> difficulty mode is not available for %s.
    TRANSFER_ABORT_UNIQUE_MESSAGE           = 0x08,         // Until you've escaped TLK's grasp, you cannot leave this place!
    TRANSFER_ABORT_TOO_MANY_REALM_INSTANCES = 0x09          // Additional instances cannot be launched, please try again later.
};

enum InstanceResetWarningType
{
    RAID_INSTANCE_WARNING_HOURS     = 1,                    // WARNING! %s is scheduled to reset in %d hour(s).
    RAID_INSTANCE_WARNING_MIN       = 2,                    // WARNING! %s is scheduled to reset in %d minute(s)!
    RAID_INSTANCE_WARNING_MIN_SOON  = 3,                    // WARNING! %s is scheduled to reset in %d minute(s). Please exit the zone or you will be returned to your bind location!
    RAID_INSTANCE_WELCOME           = 4                     // Welcome to %s. This raid instance is scheduled to reset in %s.
};

// flags that use in movement check for example at spell casting
MovementFlags const movementFlagsMask = MovementFlags(
    MOVEMENTFLAG_FORWARD |MOVEMENTFLAG_BACKWARD  |MOVEMENTFLAG_STRAFE_LEFT|MOVEMENTFLAG_STRAFE_RIGHT|
    MOVEMENTFLAG_PITCH_UP|MOVEMENTFLAG_PITCH_DOWN|MOVEMENTFLAG_FLY_UNK1    |
    MOVEMENTFLAG_JUMPING |MOVEMENTFLAG_FALLING   |MOVEMENTFLAG_FLY_UP      |
    MOVEMENTFLAG_FLYING  |MOVEMENTFLAG_SPLINE
);

MovementFlags const movementOrTurningFlagsMask = MovementFlags(
    movementFlagsMask | MOVEMENTFLAG_LEFT | MOVEMENTFLAG_RIGHT
);
class InstanceSave;

enum RestType
{
    REST_TYPE_NO        = 0,
    REST_TYPE_IN_TAVERN = 1,
    REST_TYPE_IN_CITY   = 2
};

enum DuelCompleteType
{
    DUEL_INTERUPTED = 0,
    DUEL_WON        = 1,
    DUEL_FLED       = 2
};

enum TeleportToOptions
{
    TELE_TO_GM_MODE             = 0x01,
    TELE_TO_NOT_LEAVE_TRANSPORT = 0x02,
    TELE_TO_NOT_LEAVE_COMBAT    = 0x04,
    TELE_TO_NOT_UNSUMMON_PET    = 0x08,
    TELE_TO_SPELL               = 0x10,
};

/// Type of environmental damages
enum EnviromentalDamage
{
    DAMAGE_EXHAUSTED = 0,
    DAMAGE_DROWNING  = 1,
    DAMAGE_FALL      = 2,
    DAMAGE_LAVA      = 3,
    DAMAGE_SLIME     = 4,
    DAMAGE_FIRE      = 5,
    DAMAGE_FALL_TO_VOID = 6                                 // custom case for fall without durability loss
};

// used at player loading query list preparing, and later result selection
enum PlayerLoginQueryIndex
{
    PLAYER_LOGIN_QUERY_LOADFROM                 = 0,
    PLAYER_LOGIN_QUERY_LOADGROUP                = 1,
    PLAYER_LOGIN_QUERY_LOADBOUNDINSTANCES       = 2,
    PLAYER_LOGIN_QUERY_LOADAURAS                = 3,
    PLAYER_LOGIN_QUERY_LOADSPELLS               = 4,
    PLAYER_LOGIN_QUERY_LOADQUESTSTATUS          = 5,
    PLAYER_LOGIN_QUERY_LOADDAILYQUESTSTATUS     = 6,
    PLAYER_LOGIN_QUERY_LOADTUTORIALS            = 7,        // common for all characters for some account at specific realm
    PLAYER_LOGIN_QUERY_LOADREPUTATION           = 8,
    PLAYER_LOGIN_QUERY_LOADINVENTORY            = 9,
    PLAYER_LOGIN_QUERY_LOADACTIONS              = 10,
    PLAYER_LOGIN_QUERY_LOADMAILCOUNT            = 11,
    PLAYER_LOGIN_QUERY_LOADMAILDATE             = 12,
    PLAYER_LOGIN_QUERY_LOADSOCIALLIST           = 13,
    PLAYER_LOGIN_QUERY_LOADHOMEBIND             = 14,
    PLAYER_LOGIN_QUERY_LOADSPELLCOOLDOWNS       = 15,
    PLAYER_LOGIN_QUERY_LOADDECLINEDNAMES        = 16,
    PLAYER_LOGIN_QUERY_LOADGUILD                = 17,
    PLAYER_LOGIN_QUERY_LOADARENAINFO            = 18,
    PLAYER_LOGIN_QUERY_LOADACHIEVEMENTS         = 19,
    PLAYER_LOGIN_QUERY_LOADCRITERIAPROGRESS     = 20,
    MAX_PLAYER_LOGIN_QUERY                      = 21
};

// Player summoning auto-decline time (in secs)
#define MAX_PLAYER_SUMMON_DELAY                   (2*MINUTE)
#define MAX_MONEY_AMOUNT                       (0x7FFFFFFF-1)

struct InstancePlayerBind
{
    InstanceSave *save;
    bool perm;
    /* permanent PlayerInstanceBinds are created in Raid/Heroic instances for players
       that aren't already permanently bound when they are inside when a boss is killed
       or when they enter an instance that the group leader is permanently bound to. */
    InstancePlayerBind() : save(NULL), perm(false) {}
};

struct AccessRequirement
{
    uint8  levelMin;
    uint8  levelMax;
    uint32 item;
    uint32 item2;
    uint32 heroicKey;
    uint32 heroicKey2;
    uint32 quest;
    std::string questFailedText;
    uint32 heroicQuest;
    std::string heroicQuestFailedText;
};

class TRINITY_DLL_SPEC PlayerTaxi
{
    public:
        PlayerTaxi();
        ~PlayerTaxi() {}
        // Nodes
        void InitTaxiNodesForLevel(uint32 race, uint32 chrClass, uint32 level);
        void LoadTaxiMask(const char* data);

        bool IsTaximaskNodeKnown(uint32 nodeidx) const
        {
            uint8  field   = uint8((nodeidx - 1) / 32);
            uint32 submask = 1<<((nodeidx-1)%32);
            return (m_taximask[field] & submask) == submask;
        }
        bool SetTaximaskNode(uint32 nodeidx)
        {
            uint8  field   = uint8((nodeidx - 1) / 32);
            uint32 submask = 1<<((nodeidx-1)%32);
            if ((m_taximask[field] & submask) != submask )
            {
                m_taximask[field] |= submask;
                return true;
            }
            else
                return false;
        }
        void AppendTaximaskTo(ByteBuffer& data,bool all);

        // Destinations
        bool LoadTaxiDestinationsFromString(const std::string& values, uint32 team);
        std::string SaveTaxiDestinationsToString();

        void ClearTaxiDestinations() { m_TaxiDestinations.clear(); }
        void AddTaxiDestination(uint32 dest) { m_TaxiDestinations.push_back(dest); }
        uint32 GetTaxiSource() const { return m_TaxiDestinations.empty() ? 0 : m_TaxiDestinations.front(); }
        uint32 GetTaxiDestination() const { return m_TaxiDestinations.size() < 2 ? 0 : m_TaxiDestinations[1]; }
        uint32 GetCurrentTaxiPath() const;
        uint32 NextTaxiDestination()
        {
            m_TaxiDestinations.pop_front();
            return GetTaxiDestination();
        }
        bool empty() const { return m_TaxiDestinations.empty(); }

        friend std::ostringstream& operator<< (std::ostringstream& ss, PlayerTaxi const& taxi);
    private:
        TaxiMask m_taximask;
        std::deque<uint32> m_TaxiDestinations;
};

std::ostringstream& operator<< (std::ostringstream& ss, PlayerTaxi const& taxi);

class TRINITY_DLL_SPEC Player : public Unit
{
    friend class WorldSession;
    friend void Item::AddToUpdateQueueOf(Player *player);
    friend void Item::RemoveFromUpdateQueueOf(Player *player);
    public:
        explicit Player (WorldSession *session);
        ~Player ( );

        void CleanupsBeforeDelete();

        static UpdateMask updateVisualBits;
        static void InitVisibleBits();

        void AddToWorld();
        void RemoveFromWorld();

        bool TeleportTo(uint32 mapid, float x, float y, float z, float orientation, uint32 options = 0);

        bool TeleportTo(WorldLocation const &loc, uint32 options = 0)
        {
            return TeleportTo(loc.mapid, loc.x, loc.y, loc.z, options);
        }

        void SetSummonPoint(uint32 mapid, float x, float y, float z)
        {
            m_summon_expire = time(NULL) + MAX_PLAYER_SUMMON_DELAY;
            m_summon_mapid = mapid;
            m_summon_x = x;
            m_summon_y = y;
            m_summon_z = z;
        }
        void SummonIfPossible(bool agree);

        bool Create( uint32 guidlow, const std::string& name, uint8 race, uint8 class_, uint8 gender, uint8 skin, uint8 face, uint8 hairStyle, uint8 hairColor, uint8 facialHair, uint8 outfitId );

        void Update( uint32 time );

        void BuildEnumData( QueryResult * result,  WorldPacket * p_data );

        void SetInWater(bool apply);

        bool IsInWater() const { return m_isInWater; }
        bool IsUnderWater() const;

        void SendInitialPacketsBeforeAddToMap();
        void SendInitialPacketsAfterAddToMap();
        void SendTransferAborted(uint32 mapid, uint8 reason, uint8 arg = 0);
        void SendInstanceResetWarning(uint32 mapid, uint32 time);

        Creature* GetNPCIfCanInteractWith(uint64 guid, uint32 npcflagmask);
        bool CanInteractWithNPCs(bool alive = true) const;
        GameObject* GetGameObjectIfCanInteractWith(uint64 guid, GameobjectTypes type) const;

        bool ToggleAFK();
        bool ToggleDND();
        bool isAFK() const { return HasFlag(PLAYER_FLAGS,PLAYER_FLAGS_AFK); };
        bool isDND() const { return HasFlag(PLAYER_FLAGS,PLAYER_FLAGS_DND); };
        uint8 chatTag() const;
        std::string afkMsg;
        std::string dndMsg;

        uint32 GetBarberShopCost(uint8 newhairstyle, uint8 newhaircolor, uint8 newfacialhair);

        PlayerSocial *GetSocial() { return m_social; }

        PlayerTaxi m_taxi;
        void InitTaxiNodesForLevel() { m_taxi.InitTaxiNodesForLevel(getRace(), getClass(), getLevel()); }
        bool ActivateTaxiPathTo(std::vector<uint32> const& nodes, Creature* npc = NULL, uint32 spellid = 0);
        bool ActivateTaxiPathTo(uint32 taxi_path_id, uint32 spellid = 0);
                                                            // mount_id can be used in scripting calls
        bool isAcceptWhispers() const { return m_ExtraFlags & PLAYER_EXTRA_ACCEPT_WHISPERS; }
        void SetAcceptWhispers(bool on) { if(on) m_ExtraFlags |= PLAYER_EXTRA_ACCEPT_WHISPERS; else m_ExtraFlags &= ~PLAYER_EXTRA_ACCEPT_WHISPERS; }
        bool isGameMaster() const { return m_ExtraFlags & PLAYER_EXTRA_GM_ON; }
        void SetGameMaster(bool on);
        bool isGMChat() const { return GetSession()->GetSecurity() >= SEC_MODERATOR && (m_ExtraFlags & PLAYER_EXTRA_GM_CHAT); }
        void SetGMChat(bool on) { if(on) m_ExtraFlags |= PLAYER_EXTRA_GM_CHAT; else m_ExtraFlags &= ~PLAYER_EXTRA_GM_CHAT; }
        bool isTaxiCheater() const { return m_ExtraFlags & PLAYER_EXTRA_TAXICHEAT; }
        void SetTaxiCheater(bool on) { if(on) m_ExtraFlags |= PLAYER_EXTRA_TAXICHEAT; else m_ExtraFlags &= ~PLAYER_EXTRA_TAXICHEAT; }
        bool isGMVisible() const { return !(m_ExtraFlags & PLAYER_EXTRA_GM_INVISIBLE); }
        void SetGMVisible(bool on);
        void SetPvPDeath(bool on) { if(on) m_ExtraFlags |= PLAYER_EXTRA_PVP_DEATH; else m_ExtraFlags &= ~PLAYER_EXTRA_PVP_DEATH; }

        void GiveXP(uint32 xp, Unit* victim);
        void GiveLevel(uint32 level);

        void InitStatsForLevel(bool reapplyMods = false);

        // Played Time Stuff
        time_t m_logintime;
        time_t m_Last_tick;
        uint32 m_Played_time[2];
        uint32 GetTotalPlayedTime() { return m_Played_time[0]; };
        uint32 GetLevelPlayedTime() { return m_Played_time[1]; };

        void setDeathState(DeathState s);                   // overwrite Unit::setDeathState

        void InnEnter (int time,uint32 mapid, float x,float y,float z)
        {
            inn_pos_mapid = mapid;
            inn_pos_x = x;
            inn_pos_y = y;
            inn_pos_z = z;
            time_inn_enter = time;
        };

        float GetRestBonus() const { return m_rest_bonus; };
        void SetRestBonus(float rest_bonus_new);

        RestType GetRestType() const { return rest_type; };
        void SetRestType(RestType n_r_type) { rest_type = n_r_type; };

        uint32 GetInnPosMapId() const { return inn_pos_mapid; };
        float GetInnPosX() const { return inn_pos_x; };
        float GetInnPosY() const { return inn_pos_y; };
        float GetInnPosZ() const { return inn_pos_z; };

        int GetTimeInnEnter() const { return time_inn_enter; };
        void UpdateInnerTime (int time) { time_inn_enter = time; };

        Pet* GetPet() const;
        Pet* SummonPet(uint32 entry, float x, float y, float z, float ang, PetType petType, uint32 despwtime);
        void RemovePet(Pet* pet, PetSaveMode mode, bool returnreagent = false);
        uint32 GetPhaseMaskForSpawn() const;                // used for proper set phase for DB at GM-mode creature/GO spawn

        void Say(const std::string& text, const uint32 language);
        void Yell(const std::string& text, const uint32 language);
        void TextEmote(const std::string& text);
        void Whisper(const std::string& text, const uint32 language,uint64 receiver);
        void BuildPlayerChat(WorldPacket *data, uint8 msgtype, const std::string& text, uint32 language) const;

        /*********************************************************/
        /***                    STORAGE SYSTEM                 ***/
        /*********************************************************/

        void SetVirtualItemSlot( uint8 i, Item* item);
        void SetSheath( SheathState sheathed );             // overwrite Unit version
        uint8 FindEquipSlot( ItemPrototype const* proto, uint32 slot, bool swap ) const;
        uint32 GetItemCount( uint32 item, bool inBankAlso = false, Item* skipItem = NULL ) const;
        Item* GetItemByGuid( uint64 guid ) const;
        Item* GetItemByPos( uint16 pos ) const;
        Item* GetItemByPos( uint8 bag, uint8 slot ) const;
        inline Item* GetUseableItemByPos( uint8 bag, uint8 slot ) const //Does additional check for disarmed weapons
        {
            if (!CanUseAttackType(GetAttackBySlot(slot)))
                return NULL;
            return GetItemByPos(bag, slot);
        }
        Item* GetWeaponForAttack(WeaponAttackType attackType, bool useable = false) const;
        Item* GetShield(bool useable = false) const;
        static uint8 GetAttackBySlot( uint8 slot );        // MAX_ATTACK if not weapon slot
        std::vector<Item *> &GetItemUpdateQueue() { return m_itemUpdateQueue; }
        static bool IsInventoryPos( uint16 pos ) { return IsInventoryPos(pos >> 8,pos & 255); }
        static bool IsInventoryPos( uint8 bag, uint8 slot );
        static bool IsEquipmentPos( uint16 pos ) { return IsEquipmentPos(pos >> 8,pos & 255); }
        static bool IsEquipmentPos( uint8 bag, uint8 slot );
        static bool IsBagPos( uint16 pos );
        static bool IsBankPos( uint16 pos ) { return IsBankPos(pos >> 8,pos & 255); }
        static bool IsBankPos( uint8 bag, uint8 slot );
        bool IsValidPos( uint16 pos ) { return IsBankPos(pos >> 8,pos & 255); }
        bool IsValidPos( uint8 bag, uint8 slot );
        uint8 GetBankBagSlotCount() const { return GetByteValue(PLAYER_BYTES_2, 2); }
        void SetBankBagSlotCount(uint8 count) { SetByteValue(PLAYER_BYTES_2, 2, count); }
        bool HasItemCount( uint32 item, uint32 count, bool inBankAlso = false ) const;
        bool HasItemFitToSpellReqirements(SpellEntry const* spellInfo, Item const* ignoreItem = NULL);
        bool CanNoReagentCast(SpellEntry const* spellInfo) const;
        bool HasItemOrGemWithIdEquipped( uint32 item, uint32 count, uint8 except_slot = NULL_SLOT) const;
        bool HasItemOrGemWithLimitCategoryEquipped( uint32 limitCategory, uint32 count, uint8 except_slot = NULL_SLOT) const;
        uint8 CanTakeMoreSimilarItems(Item* pItem) const { return _CanTakeMoreSimilarItems(pItem->GetEntry(),pItem->GetCount(),pItem); }
        uint8 CanTakeMoreSimilarItems(uint32 entry, uint32 count) const { return _CanTakeMoreSimilarItems(entry,count,NULL); }
        uint8 CanStoreNewItem( uint8 bag, uint8 slot, ItemPosCountVec& dest, uint32 item, uint32 count, uint32* no_space_count = NULL ) const
        {
            return _CanStoreItem(bag, slot, dest, item, count, NULL, false, no_space_count );
        }
        uint8 CanStoreItem( uint8 bag, uint8 slot, ItemPosCountVec& dest, Item *pItem, bool swap = false ) const
        {
            if(!pItem)
                return EQUIP_ERR_ITEM_NOT_FOUND;
            uint32 count = pItem->GetCount();
            return _CanStoreItem( bag, slot, dest, pItem->GetEntry(), count, pItem, swap, NULL );

        }
        uint8 CanStoreItems( Item **pItem,int count) const;
        uint8 CanEquipNewItem( uint8 slot, uint16 &dest, uint32 item, bool swap ) const;
        uint8 CanEquipItem( uint8 slot, uint16 &dest, Item *pItem, bool swap, bool not_loading = true ) const;

        uint8 CanEquipUniqueItem( Item * pItem, uint8 except_slot = NULL_SLOT, uint32 limit_count = 1 ) const;
        uint8 CanEquipUniqueItem( ItemPrototype const* itemProto, uint8 except_slot = NULL_SLOT, uint32 limit_count = 1 ) const;
        uint8 CanUnequipItems( uint32 item, uint32 count ) const;
        uint8 CanUnequipItem( uint16 src, bool swap ) const;
        uint8 CanBankItem( uint8 bag, uint8 slot, ItemPosCountVec& dest, Item *pItem, bool swap, bool not_loading = true ) const;
        uint8 CanUseItem( Item *pItem, bool not_loading = true ) const;
        bool HasItemTotemCategory( uint32 TotemCategory ) const;
        bool CanUseItem( ItemPrototype const *pItem );
        uint8 CanUseAmmo( uint32 item ) const;
        Item* StoreNewItem( ItemPosCountVec const& pos, uint32 item, bool update,int32 randomPropertyId = 0 );
        Item* StoreItem( ItemPosCountVec const& pos, Item *pItem, bool update );
        Item* EquipNewItem( uint16 pos, uint32 item, bool update );
        Item* EquipItem( uint16 pos, Item *pItem, bool update );
        void AutoUnequipOffhandIfNeed();
        bool StoreNewItemInBestSlots(uint32 item_id, uint32 item_count);
        void AutoStoreLoot(uint8 bag, uint8 slot, uint32 loot_id, LootStore const& store, bool broadcast = false);
        void AutoStoreLoot(uint32 loot_id, LootStore const& store, bool broadcast = false) { AutoStoreLoot(NULL_BAG,NULL_SLOT,loot_id,store,broadcast); }

        uint8 _CanTakeMoreSimilarItems(uint32 entry, uint32 count, Item* pItem, uint32* no_space_count = NULL) const;
        uint8 _CanStoreItem( uint8 bag, uint8 slot, ItemPosCountVec& dest, uint32 entry, uint32 count, Item *pItem = NULL, bool swap = false, uint32* no_space_count = NULL ) const;

        void ApplyEquipCooldown( Item * pItem );
        void SetAmmo( uint32 item );
        void RemoveAmmo();
        float GetAmmoDPS() const { return m_ammoDPS; }
        bool CheckAmmoCompatibility(const ItemPrototype *ammo_proto) const;
        void QuickEquipItem( uint16 pos, Item *pItem);
        void VisualizeItem( uint8 slot, Item *pItem);
        void SetVisibleItemSlot(uint8 slot, Item *pItem);
        Item* BankItem( ItemPosCountVec const& dest, Item *pItem, bool update )
        {
            return StoreItem( dest, pItem, update);
        }
        Item* BankItem( uint16 pos, Item *pItem, bool update );
        void RemoveItem( uint8 bag, uint8 slot, bool update );
        void MoveItemFromInventory(uint8 bag, uint8 slot, bool update);
                                                            // in trade, auction, guild bank, mail....
        void MoveItemToInventory(ItemPosCountVec const& dest, Item* pItem, bool update, bool in_characterInventoryDB = false);
                                                            // in trade, guild bank, mail....
        void RemoveItemDependentAurasAndCasts( Item * pItem );
        void DestroyItem( uint8 bag, uint8 slot, bool update );
        void DestroyItemCount( uint32 item, uint32 count, bool update, bool unequip_check = false);
        void DestroyItemCount( Item* item, uint32& count, bool update );
        void DestroyConjuredItems( bool update );
        void DestroyZoneLimitedItem( bool update, uint32 new_zone );
        void SplitItem( uint16 src, uint16 dst, uint32 count );
        void SwapItem( uint16 src, uint16 dst );
        void AddItemToBuyBackSlot( Item *pItem );
        Item* GetItemFromBuyBackSlot( uint32 slot );
        void RemoveItemFromBuyBackSlot( uint32 slot, bool del );
        uint32 GetMaxKeyringSize() const { return KEYRING_SLOT_END-KEYRING_SLOT_START; }
        void SendEquipError( uint8 msg, Item* pItem, Item *pItem2 );
        void SendBuyError( uint8 msg, Creature* pCreature, uint32 item, uint32 param );
        void SendSellError( uint8 msg, Creature* pCreature, uint64 guid, uint32 param );
        void AddWeaponProficiency(uint32 newflag) { m_WeaponProficiency |= newflag; }
        void AddArmorProficiency(uint32 newflag) { m_ArmorProficiency |= newflag; }
        uint32 GetWeaponProficiency() const { return m_WeaponProficiency; }
        uint32 GetArmorProficiency() const { return m_ArmorProficiency; }
        bool IsUseEquipedWeapon( bool mainhand ) const
        {
            // disarm applied only to mainhand weapon
            return !IsInFeralForm() && (!mainhand || !HasFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_DISARMED) );
        }
        bool IsTwoHandUsed() const
        {
            Item* mainItem = GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
            return mainItem && mainItem->GetProto()->InventoryType == INVTYPE_2HWEAPON && !CanTitanGrip();
        }
        void SendNewItem( Item *item, uint32 count, bool received, bool created, bool broadcast = false );
        bool BuyItemFromVendor(uint64 vendorguid, uint32 item, uint8 count, uint64 bagguid, uint8 slot);

        float GetReputationPriceDiscount( Creature const* pCreature ) const;
        Player* GetTrader() const { return pTrader; }
        void ClearTrade();
        void TradeCancel(bool sendback);
        uint16 GetItemPosByTradeSlot(uint32 slot) const { return tradeItems[slot]; }

        void UpdateEnchantTime(uint32 time);
        void UpdateItemDuration(uint32 time, bool realtimeonly=false);
        void AddEnchantmentDurations(Item *item);
        void RemoveEnchantmentDurations(Item *item);
        void RemoveArenaEnchantments(EnchantmentSlot slot);
        void AddEnchantmentDuration(Item *item,EnchantmentSlot slot,uint32 duration);
        void ApplyEnchantment(Item *item,EnchantmentSlot slot,bool apply, bool apply_dur = true, bool ignore_condition = false);
        void ApplyEnchantment(Item *item,bool apply);
        void SendEnchantmentDurations();
        void AddItemDurations(Item *item);
        void RemoveItemDurations(Item *item);
        void SendItemDurations();
        void LoadCorpse();
        void LoadPet();

        uint32 m_stableSlots;

        /*********************************************************/
        /***                    QUEST SYSTEM                   ***/
        /*********************************************************/

        uint32 GetQuestLevel( Quest const* pQuest ) const { return pQuest && pQuest->GetQuestLevel() ? pQuest->GetQuestLevel() : getLevel(); }

        void PrepareQuestMenu( uint64 guid );
        void SendPreparedQuest( uint64 guid );
        bool IsActiveQuest( uint32 quest_id ) const;
        Quest const *GetNextQuest( uint64 guid, Quest const *pQuest );
        bool CanSeeStartQuest( Quest const *pQuest );
        bool CanTakeQuest( Quest const *pQuest, bool msg );
        bool CanAddQuest( Quest const *pQuest, bool msg );
        bool CanCompleteQuest( uint32 quest_id );
        bool CanCompleteRepeatableQuest(Quest const *pQuest);
        bool CanRewardQuest( Quest const *pQuest, bool msg );
        bool CanRewardQuest( Quest const *pQuest, uint32 reward, bool msg );
        void AddQuest( Quest const *pQuest, Object *questGiver );
        void CompleteQuest( uint32 quest_id );
        void IncompleteQuest( uint32 quest_id );
        void RewardQuest( Quest const *pQuest, uint32 reward, Object* questGiver, bool announce = true );
        void FailQuest( uint32 quest_id );
        void FailTimedQuest( uint32 quest_id );
        bool SatisfyQuestSkillOrClass( Quest const* qInfo, bool msg );
        bool SatisfyQuestLevel( Quest const* qInfo, bool msg );
        bool SatisfyQuestLog( bool msg );
        bool SatisfyQuestPreviousQuest( Quest const* qInfo, bool msg );
        bool SatisfyQuestRace( Quest const* qInfo, bool msg );
        bool SatisfyQuestReputation( Quest const* qInfo, bool msg );
        bool SatisfyQuestStatus( Quest const* qInfo, bool msg );
        bool SatisfyQuestTimed( Quest const* qInfo, bool msg );
        bool SatisfyQuestExclusiveGroup( Quest const* qInfo, bool msg );
        bool SatisfyQuestNextChain( Quest const* qInfo, bool msg );
        bool SatisfyQuestPrevChain( Quest const* qInfo, bool msg );
        bool SatisfyQuestDay( Quest const* qInfo, bool msg );
        bool GiveQuestSourceItem( Quest const *pQuest );
        bool TakeQuestSourceItem( uint32 quest_id, bool msg );
        bool GetQuestRewardStatus( uint32 quest_id ) const;
        QuestStatus GetQuestStatus( uint32 quest_id ) const;
        void SetQuestStatus( uint32 quest_id, QuestStatus status );

        void SetDailyQuestStatus( uint32 quest_id );
        void ResetDailyQuestStatus();

        uint16 FindQuestSlot( uint32 quest_id ) const;
        uint32 GetQuestSlotQuestId(uint16 slot) const { return GetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_ID_OFFSET); }
        uint32 GetQuestSlotState(uint16 slot)   const { return GetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_STATE_OFFSET); }
        uint32 GetQuestSlotCounters(uint16 slot)const { return GetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET); }
        uint8 GetQuestSlotCounter(uint16 slot,uint8 counter) const { return GetByteValue(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET,counter); }
        uint32 GetQuestSlotTime(uint16 slot)    const { return GetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_TIME_OFFSET); }
        void SetQuestSlot(uint16 slot,uint32 quest_id, uint32 timer = 0)
        {
            SetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_ID_OFFSET,quest_id);
            SetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_STATE_OFFSET,0);
            SetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET,0);
            SetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_TIME_OFFSET,timer);
        }
        void SetQuestSlotCounter(uint16 slot,uint8 counter,uint8 count) { SetByteValue(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_COUNTS_OFFSET,counter,count); }
        void SetQuestSlotState(uint16 slot,uint32 state) { SetFlag(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_STATE_OFFSET,state); }
        void RemoveQuestSlotState(uint16 slot,uint32 state) { RemoveFlag(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_STATE_OFFSET,state); }
        void SetQuestSlotTimer(uint16 slot,uint32 timer) { SetUInt32Value(PLAYER_QUEST_LOG_1_1 + slot*MAX_QUEST_OFFSET + QUEST_TIME_OFFSET,timer); }
        void SwapQuestSlot(uint16 slot1,uint16 slot2)
        {
            for (int i = 0; i < MAX_QUEST_OFFSET ; ++i )
            {
                uint32 temp1 = GetUInt32Value(PLAYER_QUEST_LOG_1_1 + MAX_QUEST_OFFSET *slot1 + i);
                uint32 temp2 = GetUInt32Value(PLAYER_QUEST_LOG_1_1 + MAX_QUEST_OFFSET *slot2 + i);

                SetUInt32Value(PLAYER_QUEST_LOG_1_1 + MAX_QUEST_OFFSET *slot1 + i, temp2);
                SetUInt32Value(PLAYER_QUEST_LOG_1_1 + MAX_QUEST_OFFSET *slot2 + i, temp1);
            }
        }
        uint32 GetReqKillOrCastCurrentCount(uint32 quest_id, int32 entry);
        void AreaExploredOrEventHappens( uint32 questId );
        void GroupEventHappens( uint32 questId, WorldObject const* pEventObject );
        void ItemAddedQuestCheck( uint32 entry, uint32 count );
        void ItemRemovedQuestCheck( uint32 entry, uint32 count );
        void KilledMonster( uint32 entry, uint64 guid );
        void CastedCreatureOrGO( uint32 entry, uint64 guid, uint32 spell_id );
        void TalkedToCreature( uint32 entry, uint64 guid );
        void MoneyChanged( uint32 value );
        void ReputationChanged(FactionEntry const* factionEntry );
        bool HasQuestForItem( uint32 itemid ) const;
        bool HasQuestForGO(int32 GOId) const;
        void UpdateForQuestWorldObjects();
        bool CanShareQuest(uint32 quest_id) const;

        void SendQuestComplete( uint32 quest_id );
        void SendQuestReward( Quest const *pQuest, uint32 XP, Object* questGiver );
        void SendQuestFailed( uint32 quest_id );
        void SendQuestTimerFailed( uint32 quest_id );
        void SendCanTakeQuestResponse( uint32 msg );
        void SendPushToPartyResponse( Player *pPlayer, uint32 msg );
        void SendQuestUpdateAddItem( Quest const* pQuest, uint32 item_idx, uint32 count );
        void SendQuestUpdateAddCreatureOrGo( Quest const* pQuest, uint64 guid, uint32 creatureOrGO_idx, uint32 old_count, uint32 add_count );

        uint64 GetDivider() { return m_divider; };
        void SetDivider( uint64 guid ) { m_divider = guid; };

        uint32 GetInGameTime() { return m_ingametime; };

        void SetInGameTime( uint32 time ) { m_ingametime = time; };

        void AddTimedQuest( uint32 quest_id ) { m_timedquests.insert(quest_id); }

        /*********************************************************/
        /***                   LOAD SYSTEM                     ***/
        /*********************************************************/

        bool LoadFromDB(uint32 guid, SqlQueryHolder *holder);

        bool MinimalLoadFromDB(QueryResult *result, uint32 guid);
        static bool   LoadValuesArrayFromDB(Tokens& data,uint64 guid);
        static uint32 GetUInt32ValueFromArray(Tokens const& data, uint16 index);
        static float  GetFloatValueFromArray(Tokens const& data, uint16 index);
        static uint32 GetUInt32ValueFromDB(uint16 index, uint64 guid);
        static float  GetFloatValueFromDB(uint16 index, uint64 guid);
        static uint32 GetZoneIdFromDB(uint64 guid);
        static bool   LoadPositionFromDB(uint32& mapid, float& x,float& y,float& z,float& o, bool& in_flight, uint64 guid);

        /*********************************************************/
        /***                   SAVE SYSTEM                     ***/
        /*********************************************************/

        void SaveToDB();
        void SaveInventoryAndGoldToDB();                    // fast save function for item/money cheating preventing
        void SaveDataFieldToDB();
        static bool SaveValuesArrayInDB(Tokens const& data,uint64 guid);
        static void SetUInt32ValueInArray(Tokens& data,uint16 index, uint32 value);
        static void SetFloatValueInArray(Tokens& data,uint16 index, float value);
        static void SetUInt32ValueInDB(uint16 index, uint32 value, uint64 guid);
        static void SetFloatValueInDB(uint16 index, float value, uint64 guid);
        static void Customize(uint64 guid, uint8 gender, uint8 skin, uint8 face, uint8 hairStyle, uint8 hairColor, uint8 facialHair);
        static void SavePositionInDB(uint32 mapid, float x,float y,float z,float o,uint32 zone,uint64 guid);

        bool m_mailsLoaded;
        bool m_mailsUpdated;

        void SetBindPoint(uint64 guid);
        void SendTalentWipeConfirm(uint64 guid);
        void RewardRage( uint32 damage, uint32 weaponSpeedHitFactor, bool attacker );
        void SendPetSkillWipeConfirm();
        void CalcRage( uint32 damage,bool attacker );
        void RegenerateAll();
        void Regenerate(Powers power);
        void RegenerateHealth();
        void setRegenTimer(uint32 time) {m_regenTimer = time;}
        void setWeaponChangeTimer(uint32 time) {m_weaponChangeTimer = time;}

        uint32 GetMoney() { return GetUInt32Value (PLAYER_FIELD_COINAGE); }
        void ModifyMoney( int32 d )
        {
            if(d < 0)
                SetMoney (GetMoney() > uint32(-d) ? GetMoney() + d : 0);
            else
                SetMoney (GetMoney() < uint32(MAX_MONEY_AMOUNT - d) ? GetMoney() + d : MAX_MONEY_AMOUNT);

            // "At Gold Limit"
            if(GetMoney() >= MAX_MONEY_AMOUNT)
                SendEquipError(EQUIP_ERR_TOO_MUCH_GOLD,NULL,NULL);
        }
        void SetMoney( uint32 value )
        {
            SetUInt32Value (PLAYER_FIELD_COINAGE, value);
            MoneyChanged( value );
            UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED);
        }

        uint32 GetTutorialInt(uint32 intId )
        {
            ASSERT( (intId < 8) );
            return m_Tutorials[intId];
        }

        void SetTutorialInt(uint32 intId, uint32 value)
        {
            ASSERT( (intId < 8) );
            if(m_Tutorials[intId]!=value)
            {
                m_Tutorials[intId] = value;
                m_TutorialsChanged = true;
            }
        }

        QuestStatusMap& getQuestStatusMap() { return mQuestStatus; };

        const uint64& GetSelection( ) const { return m_curSelection; }
        void SetSelection(const uint64 &guid) { m_curSelection = guid; SetUInt64Value(UNIT_FIELD_TARGET, guid); }

        uint8 GetComboPoints() { return m_comboPoints; }
        const uint64& GetComboTarget() const { return m_comboTarget; }

        void AddComboPoints(Unit* target, int8 count);
        void ClearComboPoints();
        void SendComboPoints();

        void SendMailResult(uint32 mailId, MailResponseType mailAction, MailResponseResult mailError, uint32 equipError = 0, uint32 item_guid = 0, uint32 item_count = 0);
        void SendNewMail();
        void UpdateNextMailTimeAndUnreads();
        void AddNewMailDeliverTime(time_t deliver_time);
        bool IsMailsLoaded() const { return m_mailsLoaded; }

        //void SetMail(Mail *m);
        void RemoveMail(uint32 id);

        void AddMail(Mail* mail) { m_mail.push_front(mail);}// for call from WorldSession::SendMailTo
        uint32 GetMailSize() { return m_mail.size();};
        Mail* GetMail(uint32 id);

        PlayerMails::iterator GetmailBegin() { return m_mail.begin();};
        PlayerMails::iterator GetmailEnd() { return m_mail.end();};

        /*********************************************************/
        /*** MAILED ITEMS SYSTEM ***/
        /*********************************************************/

        uint8 unReadMails;
        time_t m_nextMailDelivereTime;

        typedef UNORDERED_MAP<uint32, Item*> ItemMap;

        ItemMap mMitems;                                    //template defined in objectmgr.cpp

        Item* GetMItem(uint32 id)
        {
            ItemMap::const_iterator itr = mMitems.find(id);
            return itr != mMitems.end() ? itr->second : NULL;
        }

        void AddMItem(Item* it)
        {
            ASSERT( it );
            //assert deleted, because items can be added before loading
            mMitems[it->GetGUIDLow()] = it;
        }

        bool RemoveMItem(uint32 id)
        {
            return mMitems.erase(id) ? true : false;
        }

        void PetSpellInitialize();
        void CharmSpellInitialize();
        void PossessSpellInitialize();
        void VehicleSpellInitialize();
        void SendRemoveControlBar();
        bool HasSpell(uint32 spell) const;
        bool HasActiveSpell(uint32 spell) const;            // show in spellbook
        TrainerSpellState GetTrainerSpellState(TrainerSpell const* trainer_spell) const;
        bool IsSpellFitByClassAndRace( uint32 spell_id ) const;
        bool IsNeedCastPassiveSpellAtLearn(SpellEntry const* spellInfo) const;

        void SendProficiency(uint8 pr1, uint32 pr2);
        void SendInitialSpells();
        bool addSpell(uint32 spell_id, bool active, bool learning, bool dependent, bool disabled);
        void learnSpell(uint32 spell_id, bool dependent);
        void removeSpell(uint32 spell_id, bool disabled = false, bool update_action_bar_for_low_rank = false);
        void resetSpells();
        void learnDefaultSpells();
        void learnQuestRewardedSpells();
        void learnQuestRewardedSpells(Quest const* quest);
        void learnSpellHighRank(uint32 spellid);

        uint32 GetFreeTalentPoints() const { return GetUInt32Value(PLAYER_CHARACTER_POINTS1); }
        void SetFreeTalentPoints(uint32 points) { SetUInt32Value(PLAYER_CHARACTER_POINTS1,points); }
        bool resetTalents(bool no_cost = false);
        uint32 resetTalentsCost() const;
        void InitTalentForLevel();

        void LearnTalent(uint32 talentId, uint32 talentRank);
        void LearnPetTalent(uint64 petGuid, uint32 talentId, uint32 talentRank);

        uint32 CalculateTalentsPoints() const;

        void InitGlyphsForLevel();
        void SetGlyphSlot(uint8 slot, uint32 slottype) { SetUInt32Value(PLAYER_FIELD_GLYPH_SLOTS_1 + slot, slottype); }
        uint32 GetGlyphSlot(uint8 slot) { return GetUInt32Value(PLAYER_FIELD_GLYPH_SLOTS_1 + slot); }
        void SetGlyph(uint8 slot, uint32 glyph) { SetUInt32Value(PLAYER_FIELD_GLYPHS_1 + slot, glyph); }
        uint32 GetGlyph(uint8 slot) { return GetUInt32Value(PLAYER_FIELD_GLYPHS_1 + slot); }

        uint32 GetFreePrimaryProffesionPoints() const { return GetUInt32Value(PLAYER_CHARACTER_POINTS2); }
        void SetFreePrimaryProffesions(uint16 profs) { SetUInt32Value(PLAYER_CHARACTER_POINTS2, profs); }
        void InitPrimaryProffesions();

        PlayerSpellMap const& GetSpellMap() const { return m_spells; }
        PlayerSpellMap      & GetSpellMap()       { return m_spells; }

        void AddSpellMod(SpellModifier* mod, bool apply);
        bool IsAffectedBySpellmod(SpellEntry const *spellInfo, SpellModifier *mod, Spell const* spell = NULL);
        template <class T> T ApplySpellMod(uint32 spellId, SpellModOp op, T &basevalue, Spell const* spell = NULL);
        void RemoveSpellMods(Spell const* spell);

        bool HasSpellCooldown(uint32 spell_id) const
        {
            SpellCooldowns::const_iterator itr = m_spellCooldowns.find(spell_id);
            return itr != m_spellCooldowns.end() && itr->second.end > time(NULL);
        }
        uint32 GetSpellCooldownDelay(uint32 spell_id) const
        {
            SpellCooldowns::const_iterator itr = m_spellCooldowns.find(spell_id);
            time_t t = time(NULL);
            return itr != m_spellCooldowns.end() && itr->second.end > t ? itr->second.end - t : 0;
        }
        void AddSpellAndCategoryCooldowns(SpellEntry const* spellInfo, uint32 itemId, Spell* spell = NULL, bool infinityCooldown = false );
        void AddSpellCooldown(uint32 spell_id, uint32 itemid, time_t end_time);
        void SendCooldownEvent(SpellEntry const *spellInfo, uint32 itemId = 0, Spell* spell = NULL);
        void ProhibitSpellScholl(SpellSchoolMask idSchoolMask, uint32 unTimeMs );
        void RemoveSpellCooldown(uint32 spell_id, bool update = false);
        void RemoveCategoryCooldown(uint32 cat);
        void RemoveArenaSpellCooldowns();
        void RemoveAllSpellCooldown();
        void _LoadSpellCooldowns(QueryResult *result);
        void _SaveSpellCooldowns();
        void SetLastPotionId(uint32 item_id) { m_lastPotionId = item_id; }
        void UpdatePotionCooldown(Spell* spell = NULL);

        void setResurrectRequestData(uint64 guid, uint32 mapId, float X, float Y, float Z, uint32 health, uint32 mana)
        {
            m_resurrectGUID = guid;
            m_resurrectMap = mapId;
            m_resurrectX = X;
            m_resurrectY = Y;
            m_resurrectZ = Z;
            m_resurrectHealth = health;
            m_resurrectMana = mana;
        };
        void clearResurrectRequestData() { setResurrectRequestData(0,0,0.0f,0.0f,0.0f,0,0); }
        bool isRessurectRequestedBy(uint64 guid) const { return m_resurrectGUID == guid; }
        bool isRessurectRequested() const { return m_resurrectGUID != 0; }
        void ResurectUsingRequestData();

        int getCinematic()
        {
            return m_cinematic;
        }
        void setCinematic(int cine)
        {
            m_cinematic = cine;
        }

        bool addActionButton(uint8 button, uint16 action, uint8 type, uint8 misc);
        void removeActionButton(uint8 button);
        void SendInitialActionButtons() const;

        PvPInfo pvpInfo;
        void UpdatePvPState(bool onlyFFA = false);
        void SetPvP(bool state)
        {
            Unit::SetPvP(state);
            for(ControlList::iterator itr = m_Controlled.begin(); itr != m_Controlled.end(); ++itr)
                (*itr)->SetPvP(state);
        }
        void UpdatePvP(bool state, bool ovrride=false);
        void UpdateZone(uint32 newZone,uint32 newArea);
        void UpdateArea(uint32 newArea);

        void UpdateZoneDependentAuras( uint32 zone_id );    // zones
        void UpdateAreaDependentAuras( uint32 area_id );    // subzones

        void UpdateAfkReport(time_t currTime);
        void UpdatePvPFlag(time_t currTime);
        void UpdateContestedPvP(uint32 currTime);
        void SetContestedPvPTimer(uint32 newTime) {m_contestedPvPTimer = newTime;}
        void ResetContestedPvP()
        {
            clearUnitState(UNIT_STAT_ATTACK_PLAYER);
            RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_CONTESTED_PVP);
            m_contestedPvPTimer = 0;
        }

        /** todo: -maybe move UpdateDuelFlag+DuelComplete to independent DuelHandler.. **/
        DuelInfo *duel;
        void UpdateDuelFlag(time_t currTime);
        void CheckDuelDistance(time_t currTime);
        void DuelComplete(DuelCompleteType type);

        bool IsGroupVisibleFor(Player* p) const;
        bool IsInSameGroupWith(Player const* p) const;
        bool IsInSameRaidWith(Player const* p) const { return p==this || (GetGroup() != NULL && GetGroup() == p->GetGroup()); }
        void UninviteFromGroup();
        static void RemoveFromGroup(Group* group, uint64 guid);
        void RemoveFromGroup() { RemoveFromGroup(GetGroup(),GetGUID()); }
        void SendUpdateToOutOfRangeGroupMembers();

        void SetInGuild(uint32 GuildId) { SetUInt32Value(PLAYER_GUILDID, GuildId); }
        void SetRank(uint32 rankId){ SetUInt32Value(PLAYER_GUILDRANK, rankId); }
        void SetGuildIdInvited(uint32 GuildId) { m_GuildIdInvited = GuildId; }
        uint32 GetGuildId() { return GetUInt32Value(PLAYER_GUILDID);  }
        static uint32 GetGuildIdFromDB(uint64 guid);
        uint32 GetRank(){ return GetUInt32Value(PLAYER_GUILDRANK); }
        static uint32 GetRankFromDB(uint64 guid);
        int GetGuildIdInvited() { return m_GuildIdInvited; }
        static void RemovePetitionsAndSigns(uint64 guid, uint32 type);

        // Arena Team
        void SetInArenaTeam(uint32 ArenaTeamId, uint8 slot)
        {
            SetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (slot * 6), ArenaTeamId);
        }
        uint32 GetArenaTeamId(uint8 slot) { return GetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (slot * 6)); }
        static uint32 GetArenaTeamIdFromDB(uint64 guid, uint8 slot);
        void SetArenaTeamIdInvited(uint32 ArenaTeamId) { m_ArenaTeamIdInvited = ArenaTeamId; }
        uint32 GetArenaTeamIdInvited() { return m_ArenaTeamIdInvited; }
        static void LeaveAllArenaTeams(uint64 guid);

        void SetDifficulty(uint32 dungeon_difficulty) { m_dungeonDifficulty = dungeon_difficulty; }
        uint8 GetDifficulty() { return m_dungeonDifficulty; }

        bool UpdateSkill(uint32 skill_id, uint32 step);
        bool UpdateSkillPro(uint16 SkillId, int32 Chance, uint32 step);

        bool UpdateCraftSkill(uint32 spellid);
        bool UpdateGatherSkill(uint32 SkillId, uint32 SkillValue, uint32 RedLevel, uint32 Multiplicator = 1);
        bool UpdateFishingSkill();

        uint32 GetBaseDefenseSkillValue() const { return GetBaseSkillValue(SKILL_DEFENSE); }
        uint32 GetBaseWeaponSkillValue(WeaponAttackType attType) const;

        uint32 GetSpellByProto(ItemPrototype *proto);

        float GetHealthBonusFromStamina();
        float GetManaBonusFromIntellect();

        bool UpdateStats(Stats stat);
        bool UpdateAllStats();
        void UpdateResistances(uint32 school);
        void UpdateArmor();
        void UpdateMaxHealth();
        void UpdateMaxPower(Powers power);
        void ApplyFeralAPBonus(int32 amount, bool apply);
        void UpdateAttackPowerAndDamage(bool ranged = false);
        void UpdateShieldBlockValue();
        void UpdateDamagePhysical(WeaponAttackType attType);
        void ApplySpellDamageBonus(int32 amount, bool apply);
        void ApplySpellHealingBonus(int32 amount, bool apply);
        void UpdateSpellDamageAndHealingBonus();

        void CalculateMinMaxDamage(WeaponAttackType attType, bool normalized, float& min_damage, float& max_damage);

        void UpdateDefenseBonusesMod();
        void ApplyRatingMod(CombatRating cr, int32 value, bool apply);
        float GetMeleeCritFromAgility();
        float GetDodgeFromAgility();
        float GetSpellCritFromIntellect();
        float OCTRegenHPPerSpirit();
        float OCTRegenMPPerSpirit();
        float GetRatingCoefficient(CombatRating cr) const;
        float GetRatingBonusValue(CombatRating cr) const;
        uint32 GetMeleeCritDamageReduction(uint32 damage) const;
        uint32 GetRangedCritDamageReduction(uint32 damage) const;
        uint32 GetSpellCritDamageReduction(uint32 damage) const;
        uint32 GetDotDamageReduction(uint32 damage) const;
        uint32 GetBaseSpellDamageBonus() { return m_baseSpellDamage;}
        uint32 GetBaseSpellHealingBonus() { return m_baseSpellHealing;}

        float GetExpertiseDodgeOrParryReduction(WeaponAttackType attType) const;
        void UpdateBlockPercentage();
        void UpdateCritPercentage(WeaponAttackType attType);
        void UpdateAllCritPercentages();
        void UpdateParryPercentage();
        void UpdateDodgePercentage();
        void UpdateMeleeHitChances();
        void UpdateRangedHitChances();
        void UpdateSpellHitChances();

        void UpdateAllSpellCritChances();
        void UpdateSpellCritChance(uint32 school);
        void UpdateExpertise(WeaponAttackType attType);
        void ApplyManaRegenBonus(int32 amount, bool apply);
        void UpdateManaRegen();

        const uint64& GetLootGUID() const { return m_lootGuid; }
        void SetLootGUID(const uint64 &guid) { m_lootGuid = guid; }

        void RemovedInsignia(Player* looterPlr);

        WorldSession* GetSession() const { return m_session; }
        void SetSession(WorldSession *s) { m_session = s; }

        void BuildCreateUpdateBlockForPlayer( UpdateData *data, Player *target ) const;
        void DestroyForPlayer( Player *target ) const;
        void SendDelayResponse(const uint32);
        void SendLogXPGain(uint32 GivenXP,Unit* victim,uint32 RestXP);

        //notifiers
        void SendAttackSwingCantAttack();
        void SendAttackSwingCancelAttack();
        void SendAttackSwingDeadTarget();
        void SendAttackSwingNotStanding();
        void SendAttackSwingNotInRange();
        void SendAttackSwingBadFacingAttack();
        void SendAutoRepeatCancel();
        void SendExplorationExperience(uint32 Area, uint32 Experience);

        void SendDungeonDifficulty(bool IsInGroup);
        void ResetInstances(uint8 method);
        void SendResetInstanceSuccess(uint32 MapId);
        void SendResetInstanceFailed(uint32 reason, uint32 MapId);
        void SendResetFailedNotify(uint32 mapid);

        bool SetPosition(float x, float y, float z, float orientation, bool teleport = false);
        void UpdateUnderwaterState( Map * m, float x, float y, float z );

        void SendMessageToSet(WorldPacket *data, bool self);// overwrite Object::SendMessageToSet
        void SendMessageToSetInRange(WorldPacket *data, float fist, bool self);// overwrite Object::SendMessageToSetInRange
        void SendMessageToSetInRange(WorldPacket *data, float dist, bool self, bool own_team_only);

        static void DeleteFromDB(uint64 playerguid, uint32 accountId, bool updateRealmChars = true);

        Corpse *GetCorpse() const;
        void SpawnCorpseBones();
        void CreateCorpse();
        void KillPlayer();
        uint32 GetResurrectionSpellId();
        void ResurrectPlayer(float restore_percent, bool applySickness = false);
        void BuildPlayerRepop();
        void RepopAtGraveyard();

        void DurabilityLossAll(double percent, bool inventory);
        void DurabilityLoss(Item* item, double percent);
        void DurabilityPointsLossAll(int32 points, bool inventory);
        void DurabilityPointsLoss(Item* item, int32 points);
        void DurabilityPointLossForEquipSlot(EquipmentSlots slot);
        uint32 DurabilityRepairAll(bool cost, float discountMod, bool guildBank);
        uint32 DurabilityRepair(uint16 pos, bool cost, float discountMod, bool guildBank);

        void UpdateMirrorTimers();
        void StopMirrorTimers()
        {
            StopMirrorTimer(FATIGUE_TIMER);
            StopMirrorTimer(BREATH_TIMER);
            StopMirrorTimer(FIRE_TIMER);
        }

        void SetMovement(PlayerMovementType pType);

        void JoinedChannel(Channel *c);
        void LeftChannel(Channel *c);
        void CleanupChannels();
        void UpdateLocalChannels( uint32 newZone );
        void LeaveLFGChannel();

        void UpdateDefense();
        void UpdateWeaponSkill (WeaponAttackType attType);
        void UpdateCombatSkills(Unit *pVictim, WeaponAttackType attType, bool defence);

        void SetSkill(uint32 id, uint16 currVal, uint16 maxVal);
        uint16 GetMaxSkillValue(uint32 skill) const;        // max + perm. bonus + temp bonus
        uint16 GetPureMaxSkillValue(uint32 skill) const;    // max
        uint16 GetSkillValue(uint32 skill) const;           // skill value + perm. bonus + temp bonus
        uint16 GetBaseSkillValue(uint32 skill) const;       // skill value + perm. bonus
        uint16 GetPureSkillValue(uint32 skill) const;       // skill value
        int16 GetSkillPermBonusValue(uint32 skill) const;
        int16 GetSkillTempBonusValue(uint32 skill) const;
        bool HasSkill(uint32 skill) const;
        void learnSkillRewardedSpells(uint32 id, uint32 value);

        WorldLocation& GetTeleportDest() { return m_teleport_dest; }
        bool IsBeingTeleported() const { return mSemaphoreTeleport_Near || mSemaphoreTeleport_Far; }
        bool IsBeingTeleportedNear() const { return mSemaphoreTeleport_Near; }
        bool IsBeingTeleportedFar() const { return mSemaphoreTeleport_Far; }
        void SetSemaphoreTeleportNear(bool semphsetting) { mSemaphoreTeleport_Near = semphsetting; }
        void SetSemaphoreTeleportFar(bool semphsetting) { mSemaphoreTeleport_Far = semphsetting; }

        void CheckExploreSystem(void);

        static uint32 TeamForRace(uint8 race);
        uint32 GetTeam() const { return m_team; }
        TeamId GetTeamId() const { return m_team == ALLIANCE ? TEAM_ALLIANCE : TEAM_HORDE; }
        static uint32 getFactionForRace(uint8 race);
        void setFactionForRace(uint8 race);

        bool IsAtGroupRewardDistance(WorldObject const* pRewardSource) const;
        bool RewardPlayerAndGroupAtKill(Unit* pVictim);
        void RewardPlayerAndGroupAtEvent(uint32 creature_id,WorldObject* pRewardSource);
        bool isHonorOrXPTarget(Unit* pVictim);

        ReputationMgr&       GetReputationMgr()       { return m_reputationMgr; }
        ReputationMgr const& GetReputationMgr() const { return m_reputationMgr; }
        ReputationRank GetReputationRank(uint32 faction_id) const;
        void RewardReputation(Unit *pVictim, float rate);
        void RewardReputation(Quest const *pQuest);

        void UpdateSkillsForLevel();
        void UpdateSkillsToMaxSkillsForLevel();             // for .levelup
        void ModifySkillBonus(uint32 skillid,int32 val, bool talent);

        /*********************************************************/
        /***                  PVP SYSTEM                       ***/
        /*********************************************************/
        void UpdateArenaFields();
        void UpdateHonorFields();
        bool RewardHonor(Unit *pVictim, uint32 groupsize, float honor = -1, bool pvptoken = false);
        uint32 GetHonorPoints() { return GetUInt32Value(PLAYER_FIELD_HONOR_CURRENCY); }
        uint32 GetArenaPoints() { return GetUInt32Value(PLAYER_FIELD_ARENA_CURRENCY); }
        void ModifyHonorPoints( int32 value );
        void ModifyArenaPoints( int32 value );
        uint32 GetMaxPersonalArenaRatingRequirement();

        //End of PvP System

        inline SpellCooldowns GetSpellCooldowns() const { return m_spellCooldowns; }

        void SetDrunkValue(uint16 newDrunkValue, uint32 itemid=0);
        uint16 GetDrunkValue() const { return m_drunk; }
        static DrunkenState GetDrunkenstateByValue(uint16 value);

        uint32 GetDeathTimer() const { return m_deathTimer; }
        uint32 GetCorpseReclaimDelay(bool pvp) const;
        void UpdateCorpseReclaimDelay();
        void SendCorpseReclaimDelay(bool load = false);

        uint32 GetShieldBlockValue() const;                 // overwrite Unit version (virtual)
        bool CanParry() const { return m_canParry; }
        void SetCanParry(bool value);
        bool CanBlock() const { return m_canBlock; }
        void SetCanBlock(bool value);
        bool CanTitanGrip() const { return m_canTitanGrip ; }
        void SetCanTitanGrip(bool value) { m_canTitanGrip = value; }

        void SetRegularAttackTime();
        void SetBaseModValue(BaseModGroup modGroup, BaseModType modType, float value) { m_auraBaseMod[modGroup][modType] = value; }
        void HandleBaseModValue(BaseModGroup modGroup, BaseModType modType, float amount, bool apply);
        float GetBaseModValue(BaseModGroup modGroup, BaseModType modType) const;
        float GetTotalBaseModValue(BaseModGroup modGroup) const;
        float GetTotalPercentageModValue(BaseModGroup modGroup) const { return m_auraBaseMod[modGroup][FLAT_MOD] + m_auraBaseMod[modGroup][PCT_MOD]; }
        void _ApplyAllStatBonuses();
        void _RemoveAllStatBonuses();

        void _ApplyWeaponDependentAuraMods(Item *item, WeaponAttackType attackType, bool apply);
        void _ApplyWeaponDependentAuraCritMod(Item *item, WeaponAttackType attackType, AuraEffect* aura, bool apply);
        void _ApplyWeaponDependentAuraDamageMod(Item *item, WeaponAttackType attackType, AuraEffect* aura, bool apply);

        void _ApplyItemMods(Item *item,uint8 slot,bool apply);
        void _RemoveAllItemMods();
        void _ApplyAllItemMods();
        void _ApplyItemBonuses(ItemPrototype const *proto,uint8 slot,bool apply);
        void _ApplyAmmoBonuses();
        bool EnchantmentFitsRequirements(uint32 enchantmentcondition, int8 slot);
        void ToggleMetaGemsActive(uint8 exceptslot, bool apply);
        void CorrectMetaGemEnchants(uint8 slot, bool apply);
        void InitDataForForm(bool reapplyMods = false);

        void ApplyItemEquipSpell(Item *item, bool apply, bool form_change = false);
        void ApplyEquipSpell(SpellEntry const* spellInfo, Item* item, bool apply, bool form_change = false);
        void UpdateEquipSpellsAtFormChange();
        void CastItemCombatSpell(Item *item, CalcDamageInfo *damageInfo, ItemPrototype const * proto);
        void CastItemUseSpell(Item *item,SpellCastTargets const& targets,uint8 cast_count, uint32 glyphIndex);

        void SendInitWorldStates(uint32 zone, uint32 area);
        void SendUpdateWorldState(uint32 Field, uint32 Value);
        void SendDirectMessage(WorldPacket *data);

        void SendAurasForTarget(Unit *target);

        PlayerMenu* PlayerTalkClass;
        std::vector<ItemSetEffect *> ItemSetEff;

        void SendLoot(uint64 guid, LootType loot_type);
        void SendLootRelease( uint64 guid );
        void SendNotifyLootItemRemoved(uint8 lootSlot);
        void SendNotifyLootMoneyRemoved();

        /*********************************************************/
        /***               BATTLEGROUND SYSTEM                 ***/
        /*********************************************************/

        bool InBattleGround()       const                { return m_bgBattleGroundID != 0; }
        bool InArena()              const;
        uint32 GetBattleGroundId()  const                { return m_bgBattleGroundID; }
        BattleGroundTypeId GetBattleGroundTypeId() const { return m_bgTypeID; }
        BattleGround* GetBattleGround() const;


        BGQueueIdBasedOnLevel GetBattleGroundQueueIdFromLevel(BattleGroundTypeId bgTypeId) const;

        bool InBattleGroundQueue() const
        {
            for (int i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
                if (m_bgBattleGroundQueueID[i].bgQueueTypeId != BATTLEGROUND_QUEUE_NONE)
                    return true;
            return false;
        }

        BattleGroundQueueTypeId GetBattleGroundQueueTypeId(uint32 index) const { return m_bgBattleGroundQueueID[index].bgQueueTypeId; }
        uint32 GetBattleGroundQueueIndex(BattleGroundQueueTypeId bgQueueTypeId) const
        {
            for (int i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
                if (m_bgBattleGroundQueueID[i].bgQueueTypeId == bgQueueTypeId)
                    return i;
            return PLAYER_MAX_BATTLEGROUND_QUEUES;
        }
        bool IsInvitedForBattleGroundQueueType(BattleGroundQueueTypeId bgQueueTypeId) const
        {
            for (int i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
                if (m_bgBattleGroundQueueID[i].bgQueueTypeId == bgQueueTypeId)
                    return m_bgBattleGroundQueueID[i].invitedToInstance != 0;
            return false;
        }
        bool InBattleGroundQueueForBattleGroundQueueType(BattleGroundQueueTypeId bgQueueTypeId) const
        {
            return GetBattleGroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES;
        }

        void SetBattleGroundId(uint32 val, BattleGroundTypeId bgTypeId)
        {
            m_bgBattleGroundID = val;
            m_bgTypeID = bgTypeId;
        }
        uint32 AddBattleGroundQueueId(BattleGroundQueueTypeId val)
        {
            for (int i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
            {
                if (m_bgBattleGroundQueueID[i].bgQueueTypeId == BATTLEGROUND_QUEUE_NONE || m_bgBattleGroundQueueID[i].bgQueueTypeId == val)
                {
                    m_bgBattleGroundQueueID[i].bgQueueTypeId = val;
                    m_bgBattleGroundQueueID[i].invitedToInstance = 0;
                    return i;
                }
            }
            return PLAYER_MAX_BATTLEGROUND_QUEUES;
        }
        bool HasFreeBattleGroundQueueId()
        {
            for (int i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
                if (m_bgBattleGroundQueueID[i].bgQueueTypeId == BATTLEGROUND_QUEUE_NONE)
                    return true;
            return false;
        }
        void RemoveBattleGroundQueueId(BattleGroundQueueTypeId val)
        {
            for (int i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
            {
                if (m_bgBattleGroundQueueID[i].bgQueueTypeId == val)
                {
                    m_bgBattleGroundQueueID[i].bgQueueTypeId = BATTLEGROUND_QUEUE_NONE;
                    m_bgBattleGroundQueueID[i].invitedToInstance = 0;
                    return;
                }
            }
        }
        void SetInviteForBattleGroundQueueType(BattleGroundQueueTypeId bgQueueTypeId, uint32 instanceId)
        {
            for (int i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
                if (m_bgBattleGroundQueueID[i].bgQueueTypeId == bgQueueTypeId)
                    m_bgBattleGroundQueueID[i].invitedToInstance = instanceId;
        }
        bool IsInvitedForBattleGroundInstance(uint32 instanceId) const
        {
            for (int i=0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
                if (m_bgBattleGroundQueueID[i].invitedToInstance == instanceId)
                    return true;
            return false;
        }
        WorldLocation const& GetBattleGroundEntryPoint() const { return m_bgEntryPoint; }
        void SetBattleGroundEntryPoint(uint32 Map, float PosX, float PosY, float PosZ, float PosO )
        {
            m_bgEntryPoint = WorldLocation(Map,PosX,PosY,PosZ,PosO);
        }

        void SetBGTeam(uint32 team) { m_bgTeam = team; }
        uint32 GetBGTeam() const { return m_bgTeam ? m_bgTeam : GetTeam(); }

        void LeaveBattleground(bool teleportToEntryPoint = true);
        bool CanJoinToBattleground() const;
        bool CanReportAfkDueToLimit();
        void ReportedAfkBy(Player* reporter);
        void ClearAfkReports() { m_bgAfkReporter.clear(); }

        bool GetBGAccessByLevel(BattleGroundTypeId bgTypeId) const;
        bool isTotalImmunity();
        bool CanUseBattleGroundObject();
        bool isTotalImmune();
        bool CanCaptureTowerPoint();

        /*********************************************************/
        /***               OUTDOOR PVP SYSTEM                  ***/
        /*********************************************************/

        OutdoorPvP * GetOutdoorPvP() const;
        // returns true if the player is in active state for outdoor pvp objective capturing, false otherwise
        bool IsOutdoorPvPActive();

        /*********************************************************/
        /***                    REST SYSTEM                    ***/
        /*********************************************************/

        bool isRested() const { return GetRestTime() >= 10*IN_MILISECONDS; }
        uint32 GetXPRestBonus(uint32 xp);
        uint32 GetRestTime() const { return m_restTime;};
        void SetRestTime(uint32 v) { m_restTime = v;};

        /*********************************************************/
        /***              ENVIROMENTAL SYSTEM                  ***/
        /*********************************************************/

        void EnvironmentalDamage(EnviromentalDamage type, uint32 damage);

        /*********************************************************/
        /***               FLOOD FILTER SYSTEM                 ***/
        /*********************************************************/

        void UpdateSpeakTime();
        bool CanSpeak() const;
        void ChangeSpeakTime(int utime);

        /*********************************************************/
        /***                 VARIOUS SYSTEMS                   ***/
        /*********************************************************/
        void UpdateFallInformationIfNeed(MovementInfo const& minfo,uint16 opcode);
        Unit *m_mover;
        WorldObject *m_seer;
        void SetFallInformation(uint32 time, float z)
        {
            m_lastFallTime = time;
            m_lastFallZ = z;
        }
        void HandleFall(MovementInfo const& movementInfo);

        bool isMoving() const { return HasUnitMovementFlag(movementFlagsMask); }
        bool isMovingOrTurning() const { return HasUnitMovementFlag(movementOrTurningFlagsMask); }

        bool CanFly() const { return HasUnitMovementFlag(MOVEMENTFLAG_CAN_FLY); }
        bool IsFlying() const { return HasUnitMovementFlag(MOVEMENTFLAG_FLYING); }
        bool IsAllowUseFlyMountsHere() const;

        void SetClientControl(Unit* target, uint8 allowMove);

        void SetMover(Unit* target) { m_mover = target; }
        void SetSeer(WorldObject *target) { m_seer = target; }
        void SetViewpoint(WorldObject *target, bool apply);
        WorldObject* GetViewpoint() const;
        void StopCastingCharm();
        void StopCastingBindSight();

        uint32 GetSaveTimer() const { return m_nextSave; }
        void   SetSaveTimer(uint32 timer) { m_nextSave = timer; }

        // Recall position
        uint32 m_recallMap;
        float  m_recallX;
        float  m_recallY;
        float  m_recallZ;
        float  m_recallO;
        void   SaveRecallPosition();

        // Homebind coordinates
        uint32 m_homebindMapId;
        uint16 m_homebindZoneId;
        float m_homebindX;
        float m_homebindY;
        float m_homebindZ;
        void RelocateToHomebind() { SetMapId(m_homebindMapId); Relocate(m_homebindX,m_homebindY,m_homebindZ); }

        // currently visible objects at player client
        typedef std::set<uint64> ClientGUIDs;
        ClientGUIDs m_clientGUIDs;

        bool HaveAtClient(WorldObject const* u) const { return u==this || m_clientGUIDs.find(u->GetGUID())!=m_clientGUIDs.end(); }

        bool canSeeOrDetect(Unit const* u, bool detect, bool inVisibleList = false, bool is3dDistance = true) const;
        bool IsVisibleInGridForPlayer(Player const* pl) const;
        bool IsVisibleGloballyFor(Player* pl) const;

        void UpdateVisibilityOf(WorldObject* target);
        void SendInitialVisiblePackets(Unit* target);

        template<class T>
            void UpdateVisibilityOf(T* target, UpdateData& data, std::set<WorldObject*>& visibleNow);

        // Stealth detection system
        uint32 m_DetectInvTimer;
        void HandleStealthedUnitsDetection();

        uint8 m_forced_speed_changes[MAX_MOVE_TYPE];

        bool HasAtLoginFlag(AtLoginFlags f) const { return m_atLoginFlags & f; }
        void SetAtLoginFlag(AtLoginFlags f) { m_atLoginFlags |= f; }
        uint32 GetAtLoginFlag() { return m_atLoginFlags; }
        void SetPetAtLoginFlag(uint8 f) { m_atLoginFlags |= uint32(f<<AT_LOAD_PET_FLAGS); }

        LookingForGroup m_lookingForGroup;

        // Temporarily removed pet cache
        uint32 GetTemporaryUnsummonedPetNumber() const { return m_temporaryUnsummonedPetNumber; }
        void SetTemporaryUnsummonedPetNumber(uint32 petnumber) { m_temporaryUnsummonedPetNumber = petnumber; }
        void UnsummonPetTemporaryIfAny();
        void ResummonPetTemporaryUnSummonedIfAny();
        bool IsPetNeedBeTemporaryUnsummoned() const { return !IsInWorld() || !isAlive() || IsMounted() /*+in flight*/; }

        void SendCinematicStart(uint32 CinematicSequenceId);
        void SendMovieStart(uint32 MovieId);

        /*********************************************************/
        /***                 INSTANCE SYSTEM                   ***/
        /*********************************************************/

        typedef UNORDERED_MAP< uint32 /*mapId*/, InstancePlayerBind > BoundInstancesMap;

        void UpdateHomebindTime(uint32 time);

        uint32 m_HomebindTimer;
        bool m_InstanceValid;
        // permanent binds and solo binds by difficulty
        BoundInstancesMap m_boundInstances[TOTAL_DIFFICULTIES];
        InstancePlayerBind* GetBoundInstance(uint32 mapid, uint8 difficulty);
        BoundInstancesMap& GetBoundInstances(uint8 difficulty) { return m_boundInstances[difficulty]; }
        void UnbindInstance(uint32 mapid, uint8 difficulty, bool unload = false);
        void UnbindInstance(BoundInstancesMap::iterator &itr, uint8 difficulty, bool unload = false);
        InstancePlayerBind* BindToInstance(InstanceSave *save, bool permanent, bool load = false);
        void SendRaidInfo();
        void SendSavedInstances();
        static void ConvertInstancesToGroup(Player *player, Group *group = NULL, uint64 player_guid = 0);
        bool Satisfy(AccessRequirement const*, uint32 target_map, bool report = false);

        /*********************************************************/
        /***                   GROUP SYSTEM                    ***/
        /*********************************************************/

        Group * GetGroupInvite() { return m_groupInvite; }
        void SetGroupInvite(Group *group) { m_groupInvite = group; }
        Group * GetGroup() { return m_group.getTarget(); }
        const Group * GetGroup() const { return (const Group*)m_group.getTarget(); }
        GroupReference& GetGroupRef() { return m_group; }
        void SetGroup(Group *group, int8 subgroup = -1);
        uint8 GetSubGroup() const { return m_group.getSubGroup(); }
        uint32 GetGroupUpdateFlag() const { return m_groupUpdateMask; }
        void SetGroupUpdateFlag(uint32 flag) { m_groupUpdateMask |= flag; }
        const uint64& GetAuraUpdateMaskForRaid() const { return m_auraRaidUpdateMask; }
        void SetAuraUpdateMaskForRaid(uint8 slot) { m_auraRaidUpdateMask |= (uint64(1) << slot); }
        Player* GetNextRandomRaidMember(float radius);
        PartyResult CanUninviteFromGroup() const;
        // BattleGround Group System
        void SetBattleGroundRaid(Group *group, int8 subgroup = -1);
        void RemoveFromBattleGroundRaid();
        Group * GetOriginalGroup() { return m_originalGroup.getTarget(); }
        GroupReference& GetOriginalGroupRef() { return m_originalGroup; }
        uint8 GetOriginalSubGroup() const { return m_originalGroup.getSubGroup(); }
        void SetOriginalGroup(Group *group, int8 subgroup = -1);

        GridReference<Player> &GetGridRef() { return m_gridRef; }
        MapReference &GetMapRef() { return m_mapRef; }

        bool isAllowedToLoot(Creature* creature);

        DeclinedName const* GetDeclinedNames() const { return m_declinedname; }
        uint8 GetRunesState() const { return m_runes->runeState; }
        uint8 GetBaseRune(uint8 index) const { return m_runes->runes[index].BaseRune; }
        uint8 GetCurrentRune(uint8 index) const { return m_runes->runes[index].CurrentRune; }
        uint8 GetRuneCooldown(uint8 index) const { return m_runes->runes[index].Cooldown; }
        void SetBaseRune(uint8 index, uint8 baseRune) { m_runes->runes[index].BaseRune = baseRune; }
        void SetCurrentRune(uint8 index, uint8 currentRune) { m_runes->runes[index].CurrentRune = currentRune; }
        void SetRuneCooldown(uint8 index, uint8 cooldown) { m_runes->runes[index].Cooldown = cooldown; m_runes->SetRuneState(index, (cooldown == 0) ? true : false); }
        void ConvertRune(uint8 index, uint8 newType);
        void ResyncRunes(uint8 count);
        void AddRunePower(uint8 index);
        void InitRunes();
        AchievementMgr& GetAchievementMgr() { return m_achievementMgr; }
        void UpdateAchievementCriteria(AchievementCriteriaTypes type, uint32 miscvalue1=0, uint32 miscvalue2=0, Unit *unit=NULL, uint32 time=0);
        bool HasTitle(uint32 bitIndex);
        bool HasTitle(CharTitlesEntry const* title) { return HasTitle(title->bit_index); }
        void SetTitle(CharTitlesEntry const* title);

        //bool isActiveObject() const { return true; }
        bool canSeeSpellClickOn(Creature const* creature) const;
    protected:

        /*********************************************************/
        /***               BATTLEGROUND SYSTEM                 ***/
        /*********************************************************/

        /* this variable is set to bg->m_InstanceID, when player is teleported to BG - (it is battleground's GUID)*/
        uint32 m_bgBattleGroundID;
        BattleGroundTypeId m_bgTypeID;
        /*
        this is an array of BG queues (BgTypeIDs) in which is player
        */
        struct BgBattleGroundQueueID_Rec
        {
            BattleGroundQueueTypeId bgQueueTypeId;
            uint32 invitedToInstance;
        };
        BgBattleGroundQueueID_Rec m_bgBattleGroundQueueID[PLAYER_MAX_BATTLEGROUND_QUEUES];
        WorldLocation m_bgEntryPoint;

        std::set<uint32> m_bgAfkReporter;
        uint8 m_bgAfkReportedCount;
        time_t m_bgAfkReportedTimer;
        uint32 m_contestedPvPTimer;

        uint32 m_bgTeam;    // what side the player will be added to

        /*********************************************************/
        /***                    QUEST SYSTEM                   ***/
        /*********************************************************/

        std::set<uint32> m_timedquests;

        uint64 m_divider;
        uint32 m_ingametime;

        /*********************************************************/
        /***                   LOAD SYSTEM                     ***/
        /*********************************************************/

        void _LoadActions(QueryResult *result);
        void _LoadAuras(QueryResult *result, uint32 timediff);
        void _LoadGlyphAuras();
        void _LoadBoundInstances(QueryResult *result);
        void _LoadInventory(QueryResult *result, uint32 timediff);
        void _LoadMailInit(QueryResult *resultUnread, QueryResult *resultDelivery);
        void _LoadMail();
        void _LoadMailedItems(Mail *mail);
        void _LoadQuestStatus(QueryResult *result);
        void _LoadDailyQuestStatus(QueryResult *result);
        void _LoadGroup(QueryResult *result);
        void _LoadSkills();
        void _LoadSpells(QueryResult *result);
        void _LoadTutorials(QueryResult *result);
        void _LoadFriendList(QueryResult *result);
        bool _LoadHomeBind(QueryResult *result);
        void _LoadDeclinedNames(QueryResult *result);
        void _LoadArenaTeamInfo(QueryResult *result);

        /*********************************************************/
        /***                   SAVE SYSTEM                     ***/
        /*********************************************************/

        void _SaveActions();
        void _SaveAuras();
        void _SaveInventory();
        void _SaveMail();
        void _SaveQuestStatus();
        void _SaveDailyQuestStatus();
        void _SaveSpells();
        void _SaveTutorials();

        void _SetCreateBits(UpdateMask *updateMask, Player *target) const;
        void _SetUpdateBits(UpdateMask *updateMask, Player *target) const;

        /*********************************************************/
        /***              ENVIRONMENTAL SYSTEM                 ***/
        /*********************************************************/
        void HandleSobering();
        void SendMirrorTimer(MirrorTimerType Type, uint32 MaxValue, uint32 CurrentValue, int32 Regen);
        void StopMirrorTimer(MirrorTimerType Type);
        void HandleDrowning(uint32 time_diff);
        int32 getMaxTimer(MirrorTimerType timer);

        /*********************************************************/
        /***                  HONOR SYSTEM                     ***/
        /*********************************************************/
        time_t m_lastHonorUpdateTime;

        void outDebugValues() const;
        uint64 m_lootGuid;

        uint32 m_race;
        uint32 m_class;
        uint32 m_team;
        uint32 m_nextSave;
        time_t m_speakTime;
        uint32 m_speakCount;
        uint32 m_dungeonDifficulty;

        uint32 m_atLoginFlags;

        Item* m_items[PLAYER_SLOTS_COUNT];
        uint32 m_currentBuybackSlot;

        std::vector<Item*> m_itemUpdateQueue;
        bool m_itemUpdateQueueBlocked;

        uint32 m_ExtraFlags;
        uint64 m_curSelection;

        uint64 m_comboTarget;
        int8 m_comboPoints;

        QuestStatusMap mQuestStatus;

        uint32 m_GuildIdInvited;
        uint32 m_ArenaTeamIdInvited;

        PlayerMails m_mail;
        PlayerSpellMap m_spells;
        uint32 m_lastPotionId;                              // last used health/mana potion in combat, that block next potion use

        ActionButtonList m_actionButtons;

        float m_auraBaseMod[BASEMOD_END][MOD_END];
        int16 m_baseRatingValue[MAX_COMBAT_RATING];
        uint16 m_baseSpellDamage;
        uint16 m_baseSpellHealing;
        uint16 m_baseFeralAP;
        uint16 m_baseManaRegen;

        SpellModList m_spellMods[MAX_SPELLMOD];
        int32 m_SpellModRemoveCount;
        EnchantDurationList m_enchantDuration;
        ItemDurationList m_itemDuration;

        uint64 m_resurrectGUID;
        uint32 m_resurrectMap;
        float m_resurrectX, m_resurrectY, m_resurrectZ;
        uint32 m_resurrectHealth, m_resurrectMana;

        WorldSession *m_session;

        typedef std::list<Channel*> JoinedChannelsList;
        JoinedChannelsList m_channels;

        int m_cinematic;

        Player *pTrader;
        bool acceptTrade;
        uint16 tradeItems[TRADE_SLOT_COUNT];
        uint32 tradeGold;

        time_t m_nextThinkTime;

        uint32 m_Tutorials[8];
        bool   m_TutorialsChanged;

        bool   m_DailyQuestChanged;
        time_t m_lastDailyQuestTime;

        uint32 m_drunkTimer;
        uint16 m_drunk;
        uint32 m_weaponChangeTimer;

        uint32 m_zoneUpdateId;
        uint32 m_zoneUpdateTimer;
        uint32 m_areaUpdateId;

        uint32 m_deathTimer;
        time_t m_deathExpireTime;

        uint32 m_restTime;

        uint32 m_WeaponProficiency;
        uint32 m_ArmorProficiency;
        bool m_canParry;
        bool m_canBlock;
        bool m_canTitanGrip;
        uint8 m_swingErrorMsg;
        float m_ammoDPS;

        ////////////////////Rest System/////////////////////
        int time_inn_enter;
        uint32 inn_pos_mapid;
        float  inn_pos_x;
        float  inn_pos_y;
        float  inn_pos_z;
        float m_rest_bonus;
        RestType rest_type;
        ////////////////////Rest System/////////////////////

        uint32 m_resetTalentsCost;
        time_t m_resetTalentsTime;
        uint32 m_usedTalentCount;
        uint32 m_questRewardTalentCount;

        // Social
        PlayerSocial *m_social;

        // Groups
        GroupReference m_group;
        GroupReference m_originalGroup;
        Group *m_groupInvite;
        uint32 m_groupUpdateMask;
        uint64 m_auraRaidUpdateMask;

        // Player summoning
        time_t m_summon_expire;
        uint32 m_summon_mapid;
        float  m_summon_x;
        float  m_summon_y;
        float  m_summon_z;

        DeclinedName *m_declinedname;
        Runes *m_runes;
    private:
        // internal common parts for CanStore/StoreItem functions
        uint8 _CanStoreItem_InSpecificSlot( uint8 bag, uint8 slot, ItemPosCountVec& dest, ItemPrototype const *pProto, uint32& count, bool swap, Item *pSrcItem ) const;
        uint8 _CanStoreItem_InBag( uint8 bag, ItemPosCountVec& dest, ItemPrototype const *pProto, uint32& count, bool merge, bool non_specialized, Item *pSrcItem, uint8 skip_bag, uint8 skip_slot ) const;
        uint8 _CanStoreItem_InInventorySlots( uint8 slot_begin, uint8 slot_end, ItemPosCountVec& dest, ItemPrototype const *pProto, uint32& count, bool merge, Item *pSrcItem, uint8 skip_bag, uint8 skip_slot ) const;
        Item* _StoreItem( uint16 pos, Item *pItem, uint32 count, bool clone, bool update );

        void UpdateKnownCurrencies(uint32 itemId, bool apply);
        int32 CalculateReputationGain(uint32 creatureOrQuestLevel, int32 rep, int32 faction, bool for_quest);
        void AdjustQuestReqItemCount( Quest const* pQuest, QuestStatusData& questStatusData );

        GridReference<Player> m_gridRef;
        MapReference m_mapRef;

        void UpdateCharmedAI();
        UnitAI *i_AI;

        uint32 m_lastFallTime;
        float  m_lastFallZ;

        int32 m_MirrorTimer[MAX_TIMERS];
        uint8 m_MirrorTimerFlags;
        uint8 m_MirrorTimerFlagsLast;
        bool m_isInWater;

        // Current teleport data
        WorldLocation m_teleport_dest;
        bool mSemaphoreTeleport_Near;
        bool mSemaphoreTeleport_Far;

        // Temporary removed pet cache
        uint32 m_temporaryUnsummonedPetNumber;
        uint32 m_oldpetspell;

        AchievementMgr m_achievementMgr;
        ReputationMgr  m_reputationMgr;

        SpellCooldowns m_spellCooldowns;
};

void AddItemsSetItem(Player*player,Item *item);
void RemoveItemsSetItem(Player*player,ItemPrototype const *proto);

// "the bodies of template functions must be made available in a header file"
template <class T> T Player::ApplySpellMod(uint32 spellId, SpellModOp op, T &basevalue, Spell const* spell)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);
    if (!spellInfo) return 0;
    int32 totalpct = 0;
    int32 totalflat = 0;
    for (SpellModList::iterator itr = m_spellMods[op].begin(); itr != m_spellMods[op].end(); ++itr)
    {
        SpellModifier *mod = *itr;

        if(!IsAffectedBySpellmod(spellInfo,mod,spell))
            continue;
        if (mod->type == SPELLMOD_FLAT)
            totalflat += mod->value;
        else if (mod->type == SPELLMOD_PCT)
        {
            // skip percent mods for null basevalue (most important for spell mods with charges )
            if(basevalue == T(0))
                continue;

            // special case (skip >10sec spell casts for instant cast setting)
            if( mod->op==SPELLMOD_CASTING_TIME  && basevalue >= T(10000) && mod->value <= -100)
                continue;

            totalpct += mod->value;
        }

        if (mod->charges > 0 )
        {
            --mod->charges;
            if (mod->charges == 0)
            {
                mod->charges = -1;
                mod->lastAffected = spell;
                if(!mod->lastAffected)
                    mod->lastAffected = FindCurrentSpellBySpellId(spellId);
                ++m_SpellModRemoveCount;
            }
        }
    }

    float diff = (float)basevalue*(float)totalpct/100.0f + (float)totalflat;
    basevalue = T((float)basevalue + diff);
    return T(diff);
}
#endif

