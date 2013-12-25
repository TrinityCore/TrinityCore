/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef LUAHOOKS_H
#define LUAHOOKS_H

#include "ScriptMgr.h"
#include "Group.h"
#include "GameObjectAI.h"
#include "CreatureAI.h"
#include "Item.h"

class Channel;
class Creature;
class GameObject;
class Guild;
class Group;
class Player;
class Quest;
class Spell;
class SpellCastTargets;
class Transport;
class Unit;
// #include "item.h"

enum RegisterTypes
{
    REGTYPE_SERVER,
    REGTYPE_PLAYER,
    REGTYPE_GUILD,
    REGTYPE_GROUP,
    REGTYPE_CREATURE,
    REGTYPE_CREATURE_GOSSIP,
    REGTYPE_GAMEOBJECT,
    REGTYPE_GAMEOBJECT_GOSSIP,
    REGTYPE_ITEM,
    REGTYPE_ITEM_GOSSIP,
    REGTYPE_PLAYER_GOSSIP,
    REGTYPE_COUNT
};

// RegisterServerEvent(EventId, function)
enum ServerEvents
{
    // Server
    SERVER_EVENT_ON_NETWORK_START           =     1,       // Not Implemented
    SERVER_EVENT_ON_NETWORK_STOP            =     2,       // Not Implemented
    SERVER_EVENT_ON_SOCKET_OPEN             =     3,       // Not Implemented
    SERVER_EVENT_ON_SOCKET_CLOSE            =     4,       // Not Implemented
    SERVER_EVENT_ON_PACKET_RECEIVE          =     5,       // Not Implemented
    SERVER_EVENT_ON_PACKET_RECEIVE_UNKNOWN  =     6,       // Not Implemented
    SERVER_EVENT_ON_PACKET_SEND             =     7,       // Not Implemented

    // World
    WORLD_EVENT_ON_OPEN_STATE_CHANGE        =     8,       // (event, open)
    WORLD_EVENT_ON_CONFIG_LOAD              =     9,       // (event, reload)
    WORLD_EVENT_ON_MOTD_CHANGE              =     10,       // (event, newMOTD)
    WORLD_EVENT_ON_SHUTDOWN_INIT            =     11,       // (event, code, mask)
    WORLD_EVENT_ON_SHUTDOWN_CANCEL          =     12,       // (event)
    WORLD_EVENT_ON_UPDATE                   =     13,       // (event, diff)
    WORLD_EVENT_ON_STARTUP                  =     14,       // (event)
    WORLD_EVENT_ON_SHUTDOWN                 =     15,       // (event)

    // Eluna
    ELUNA_EVENT_ON_RESTART                  =     16,       // (event)

    // Map
    MAP_EVENT_ON_CREATE                     =     17,       // Not Implemented
    MAP_EVENT_ON_DESTROY                    =     18,       // Not Implemented
    MAP_EVENT_ON_LOAD                       =     19,       // Not Implemented
    MAP_EVENT_ON_UNLOAD                     =     20,       // Not Implemented
    MAP_EVENT_ON_PLAYER_ENTER               =     21,       // Not Implemented
    MAP_EVENT_ON_PLAYER_LEAVE               =     22,       // Not Implemented
    MAP_EVENT_ON_UPDATE                     =     23,       // Not Implemented

    // Area trigger
    TRIGGER_EVENT_ON_TRIGGER                =     24,       // (event, player, triggerId)

    // Weather
    WEATHER_EVENT_ON_CHANGE                 =     25,       // (event, weather, state, grade)

    // Auction house
    AUCTION_EVENT_ON_ADD                    =     26,       // Not Implemented
    AUCTION_EVENT_ON_REMOVE                 =     27,       // Not Implemented
    AUCTION_EVENT_ON_SUCCESFUL              =     28,       // Not Implemented
    AUCTION_EVENT_ON_EXPIRE                 =     29,       // Not Implemented

    SERVER_EVENT_COUNT
};

// RegisterPlayerEvent(eventId, function)
enum PlayerEvents
{
    PLAYER_EVENT_ON_CHARACTER_CREATE        =     1,        // (event, player)
    PLAYER_EVENT_ON_CHARACTER_DELETE        =     2,        // (event, guid)
    PLAYER_EVENT_ON_LOGIN                   =     3,        // (event, player)
    PLAYER_EVENT_ON_LOGOUT                  =     4,        // (event, player)
    PLAYER_EVENT_ON_SPELL_CAST              =     5,        // (event, player, spell, skipCheck)
    PLAYER_EVENT_ON_KILL_PLAYER             =     6,        // (event, killer, killed)
    PLAYER_EVENT_ON_KILL_CREATURE           =     7,        // (event, killer, killed)
    PLAYER_EVENT_ON_KILLED_BY_CREATURE      =     8,        // (event, killer, killed)
    PLAYER_EVENT_ON_DUEL_REQUEST            =     9,        // (event, target, challenger)
    PLAYER_EVENT_ON_DUEL_START              =     10,       // (event, player1, player2)
    PLAYER_EVENT_ON_DUEL_END                =     11,       // (event, winner, loser, type)
    PLAYER_EVENT_ON_GIVE_XP                 =     12,       // (event, player, amount, victim)
    PLAYER_EVENT_ON_LEVEL_CHANGE            =     13,       // (event, player, oldLevel)
    PLAYER_EVENT_ON_MONEY_CHANGE            =     14,       // (event, player, amount)
    PLAYER_EVENT_ON_REPUTATION_CHANGE       =     15,       // (event, player, factionId, standing, incremental)
    PLAYER_EVENT_ON_TALENTS_CHANGE          =     16,       // (event, player, points)
    PLAYER_EVENT_ON_TALENTS_RESET           =     17,       // (event, player, noCost)
    PLAYER_EVENT_ON_CHAT                    =     18,       // (event, player, msg, Type, lang) - Can return false
    PLAYER_EVENT_ON_WHISPER                 =     19,       // (event, player, msg, Type, lang, receiver)
    PLAYER_EVENT_ON_GROUP_CHAT              =     20,       // (event, player, msg, Type, lang, group) - Can return false
    PLAYER_EVENT_ON_GUILD_CHAT              =     21,       // (event, player, msg, Type, lang, guild) - Can return false
    PLAYER_EVENT_ON_CHANNEL_CHAT            =     22,       // (event, player, msg, Type, lang, channel) - Can return false
    PLAYER_EVENT_ON_EMOTE                   =     23,       // (event, player, emote) - Not triggered on any known emote
    PLAYER_EVENT_ON_TEXT_EMOTE              =     24,       // (event, player, textEmote, emoteNum, guid)
    PLAYER_EVENT_ON_SAVE                    =     25,       // (event, player)
    PLAYER_EVENT_ON_BIND_TO_INSTANCE        =     26,       // (event, player, difficulty, mapid, permanent)
    PLAYER_EVENT_ON_UPDATE_ZONE             =     27,       // (event, player, newZone, newArea)
    PLAYER_EVENT_ON_MAP_CHANGE              =     28,       // (event, player)
    // Custom
    PLAYER_EVENT_ON_EQUIP                   =     29,       // (event, player, item, bag, slot)
    PLAYER_EVENT_ON_FIRST_LOGIN             =     30,       // (event, player)
    PLAYER_EVENT_ON_CAN_USE_ITEM            =     31,       // (event, player, itemEntry)
    PLAYER_EVENT_ON_LOOT_ITEM               =     32,       // (event, player, item, count)
    PLAYER_EVENT_ON_ENTER_COMBAT            =     33,       // (event, player, enemy)
    PLAYER_EVENT_ON_LEAVE_COMBAT            =     34,       // (event, player)
    PLAYER_EVENT_ON_REPOP                   =     35,       // (event, player)
    PLAYER_EVENT_ON_RESURRECT               =     36,       // (event, player)

    PLAYER_EVENT_COUNT
};

// RegisterGuildEvent(eventId, function)
enum GuildEventTypes
{
    // Guild
    GUILD_EVENT_ON_ADD_MEMBER               =     1,       // (event, guild, player, rank)
    GUILD_EVENT_ON_REMOVE_MEMBER            =     2,       // (event, guild, isDisbanding, isKicked)
    GUILD_EVENT_ON_MOTD_CHANGE              =     3,       // (event, guild, newMotd)
    GUILD_EVENT_ON_INFO_CHANGE              =     4,       // (event, guild, newInfo)
    GUILD_EVENT_ON_CREATE                   =     5,       // (event, guild, leader, name)
    GUILD_EVENT_ON_DISBAND                  =     6,       // (event, guild)
    GUILD_EVENT_ON_MONEY_WITHDRAW           =     7,       // (event, guild, player, amount, isRepair)
    GUILD_EVENT_ON_MONEY_DEPOSIT            =     8,       // (event, guild, player, amount)
    GUILD_EVENT_ON_ITEM_MOVE                =     9,       // (event, guild, player, item, isSrcBank, srcContainer, srcSlotId, isDestBank, destContainer, destSlotId)
    GUILD_EVENT_ON_EVENT                    =     10,      // (event, guild, eventType, plrGUIDLow1, plrGUIDLow2, newRank)
    GUILD_EVENT_ON_BANK_EVENT               =     11,      // (event, guild, eventType, tabId, playerGUIDLow, itemOrMoney, itemStackCount, destTabId)

    GUILD_EVENT_COUNT
};

// RegisterGroupEvent(eventId, function)
enum GroupEvents
{
    // Group
    GROUP_EVENT_ON_MEMBER_ADD               =     1,       // (event, group, guid)
    GROUP_EVENT_ON_MEMBER_INVITE            =     2,       // (event, group, guid)
    GROUP_EVENT_ON_MEMBER_REMOVE            =     3,       // (event, group, guid, method, kicker, reason)
    GROUP_EVENT_ON_LEADER_CHANGE            =     4,       // (event, group, newLeaderGuid, oldLeaderGuid)
    GROUP_EVENT_ON_DISBAND                  =     5,       // (event, group)
    GROUP_EVENT_ON_CREATE                   =     6,       // (event, group, leaderGuid, groupType)

    GROUP_EVENT_COUNT
};

// RegisterCreatureEvent(entry, EventId, function)
enum CreatureEvents
{
    CREATURE_EVENT_ON_ENTER_COMBAT                    = 1,  // (event, creature, target)
    CREATURE_EVENT_ON_LEAVE_COMBAT                    = 2,  // (event, creature)
    CREATURE_EVENT_ON_TARGET_DIED                     = 3,  // (event, creature, victim)
    CREATURE_EVENT_ON_DIED                            = 4,  // (event, creature, killer)
    CREATURE_EVENT_ON_SPAWN                           = 5,  // (event, creature)
    CREATURE_EVENT_ON_REACH_WP                        = 6,  // (event, creature, type, id)
    CREATURE_EVENT_ON_AIUPDATE                        = 7,  // (event, creature, diff)
    CREATURE_EVENT_ON_RECEIVE_EMOTE                   = 8,  // (event, creature, player, emoteid)
    CREATURE_EVENT_ON_DAMAGE_TAKEN                    = 9,  // (event, creature, attacker, damage)
    CREATURE_EVENT_ON_PRE_COMBAT                      = 10, // (event, creature, target)
    CREATURE_EVENT_ON_ATTACKED_AT                     = 11, // (event, creature, attacker)
    CREATURE_EVENT_ON_OWNER_ATTACKED                  = 12, // (event, creature, target)
    CREATURE_EVENT_ON_OWNER_ATTACKED_AT               = 13, // (event, creature, attacker)
    CREATURE_EVENT_ON_HIT_BY_SPELL                    = 14, // (event, creature, caster, spellid)
    CREATURE_EVENT_ON_SPELL_HIT_TARGET                = 15, // (event, creature, target, spellid)
    CREATURE_EVENT_ON_SPELL_CLICK                     = 16, // (event, creature, clicker)
    CREATURE_EVENT_ON_CHARMED                         = 17, // (event, creature, apply)
    CREATURE_EVENT_ON_POSSESS                         = 18, // (event, creature, apply)
    CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE          = 19, // (event, creature, summon)
    CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN       = 20, // (event, creature, summon)
    CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED          = 21, // (event, creature, summon, killer)
    CREATURE_EVENT_ON_SUMMONED                        = 22, // (event, creature, summoner)
    CREATURE_EVENT_ON_RESET                           = 23, // (event, creature)
    CREATURE_EVENT_ON_REACH_HOME                      = 24, // (event, creature)
    CREATURE_EVENT_ON_CAN_RESPAWN                     = 25, // (event, creature)
    CREATURE_EVENT_ON_CORPSE_REMOVED                  = 26, // (event, creature, respawndelay)
    CREATURE_EVENT_ON_MOVE_IN_LOS                     = 27, // (event, creature, unit)
    CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS             = 28, // (event, creature, unit)
    CREATURE_EVENT_ON_PASSANGER_BOARDED               = 29, // (event, creature, passanger, seatid, apply)
    CREATURE_EVENT_ON_DUMMY_EFFECT                    = 30, // (event, caster, spellid, effindex, creature)
    CREATURE_EVENT_ON_QUEST_ACCEPT                    = 31, // (event, player, creature, quest)
    CREATURE_EVENT_ON_QUEST_SELECT                    = 32, // (event, player, creature, quest)
    CREATURE_EVENT_ON_QUEST_COMPLETE                  = 33, // (event, player, creature, quest)
    CREATURE_EVENT_ON_QUEST_REWARD                    = 34, // (event, player, creature, quest, opt)
    CREATURE_EVENT_ON_DIALOG_STATUS                   = 35, // (event, player, creature)
    CREATURE_EVENT_COUNT
};

// RegisterGameObjectEvent(entry, EventId, function)
enum GameObjectEvents
{
    GAMEOBJECT_EVENT_ON_AIUPDATE                    = 1,    // (event, go, diff)
    GAMEOBJECT_EVENT_ON_RESET                       = 2,    // (event, go)
    GAMEOBJECT_EVENT_ON_DUMMY_EFFECT                = 3,    // (event, caster, spellid, effindex, go)
    GAMEOBJECT_EVENT_ON_QUEST_ACCEPT                = 4,    // (event, player, go, quest)
    GAMEOBJECT_EVENT_ON_QUEST_REWARD                = 5,    // (event, player, go, quest, opt)
    GAMEOBJECT_EVENT_ON_DIALOG_STATUS               = 6,    // (event, player, go)
    GAMEOBJECT_EVENT_ON_DESTROYED                   = 7,    // (event, go, player)          // TODO
    GAMEOBJECT_EVENT_ON_DAMAGED                     = 8,    // (event, go, player)          // TODO
    GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE           = 9,    // (event, go, state, unit)     // TODO
    GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED            = 10,   // (event, go, state)           // TODO
    GAMEOBJECT_EVENT_ON_QUEST_COMPLETE              = 11,   // (event, player, go, quest)
    GAMEOBJECT_EVENT_COUNT
};

// RegisterItemEvent(entry, EventId, function)
enum ItemEvents
{
    ITEM_EVENT_ON_DUMMY_EFFECT                      = 1,    // (event, caster, spellid, effindex, item)
    ITEM_EVENT_ON_USE                               = 2,    // (event, player, item, target)
    ITEM_EVENT_ON_QUEST_ACCEPT                      = 3,    // (event, player, item, quest)
    ITEM_EVENT_ON_EXPIRE                            = 4,    // (event, player, itemid)
    ITEM_EVENT_COUNT
};

// RegisterCreatureGossipEvent(entry, EventId, function)
// RegisterGameObjectGossipEvent(entry, EventId, function)
// RegisterItemGossipEvent(entry, EventId, function)
// RegisterPlayerGossipEvent(menu_id, EventId, function)
enum GossipEvents
{
    GOSSIP_EVENT_ON_HELLO                           = 1,    // (event, player, object) - Object is the Creature/GameObject/Item
    GOSSIP_EVENT_ON_SELECT                          = 2,    // (event, player, object, sender, intid, code, menu_id) - Object is the Creature/GameObject/Item/Player, menu_id is only for player gossip
    GOSSIP_EVENT_COUNT
};

struct HookMgr
{
    struct ElunaCreatureAI;
    struct ElunaGameObjectAI;
    struct ElunaWorldAI;
    CreatureAI* GetAI(Creature* creature);
    GameObjectAI* GetAI(GameObject* gameObject);

    /* Misc */
    void OnWorldUpdate(uint32 diff);
    void OnLootItem(Player* pPlayer, Item* pItem, uint32 count, uint64 guid);
    void OnFirstLogin(Player* pPlayer);
    void OnEquip(Player* pPlayer, Item* pItem, uint8 bag, uint8 slot);
    void OnRepop(Player* pPlayer);
    void OnResurrect(Player* pPlayer);
    InventoryResult OnCanUseItem(const Player* pPlayer, uint32 itemEntry);
    void OnEngineRestart();
    /* Item */
    bool OnDummyEffect(Unit* pCaster, uint32 spellId, SpellEffIndex effIndex, Item* pTarget);
    bool OnQuestAccept(Player* pPlayer, Item* pItem, Quest const* pQuest);
    bool OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& targets);
    bool OnExpire(Player* pPlayer, ItemTemplate const* pProto);
    void HandleGossipSelectOption(Player* pPlayer, Item* item, uint32 sender, uint32 action, std::string code);
    /* Creature */
    bool OnDummyEffect(Unit* pCaster, uint32 spellId, SpellEffIndex effIndex, Creature* pTarget);
    bool OnGossipHello(Player* pPlayer, Creature* pCreature);
    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action);
    bool OnGossipSelectCode(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action, const char* code);
    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest);
    bool OnQuestSelect(Player* pPlayer, Creature* pCreature, Quest const* pQuest);
    bool OnQuestComplete(Player* pPlayer, Creature* pCreature, Quest const* pQuest);
    bool OnQuestReward(Player* pPlayer, Creature* pCreature, Quest const* pQuest);
    uint32 GetDialogStatus(Player* pPlayer, Creature* pCreature);
    /* GameObject */
    bool OnDummyEffect(Unit* pCaster, uint32 spellId, SpellEffIndex effIndex, GameObject* pTarget);
    bool OnGossipHello(Player* pPlayer, GameObject* pGameObject);
    bool OnGossipSelect(Player* pPlayer, GameObject* pGameObject, uint32 sender, uint32 action);
    bool OnGossipSelectCode(Player* pPlayer, GameObject* pGameObject, uint32 sender, uint32 action, const char* code);
    bool OnQuestAccept(Player* pPlayer, GameObject* pGameObject, Quest const* pQuest);
    bool OnQuestComplete(Player* pPlayer, GameObject* pGameObject, Quest const* pQuest);
    bool OnQuestReward(Player* pPlayer, GameObject* pGameObject, Quest const* pQuest);
    bool OnGameObjectUse(Player* pPlayer, GameObject* pGameObject) { return false; }; // TODO? Not on TC
    uint32 GetDialogStatus(Player* pPlayer, GameObject* pGameObject);
    void OnDestroyed(GameObject* pGameObject, Player* pPlayer);
    void OnDamaged(GameObject* pGameObject, Player* pPlayer);
    void OnLootStateChanged(GameObject* pGameObject, uint32 state, Unit* pUnit);
    void OnGameObjectStateChanged(GameObject* pGameObject, uint32 state);
    /* Player */
    void OnPlayerEnterCombat(Player* pPlayer, Unit* pEnemy);
    void OnPlayerLeaveCombat(Player* pPlayer);
    void OnPVPKill(Player* pKiller, Player* pKilled);
    void OnCreatureKill(Player* pKiller, Creature* pKilled);
    void OnPlayerKilledByCreature(Creature* pKiller, Player* pKilled);
    void OnLevelChanged(Player* pPlayer, uint8 oldLevel);
    void OnFreeTalentPointsChanged(Player* pPlayer, uint32 newPoints);
    void OnTalentsReset(Player* pPlayer, bool noCost);
    void OnMoneyChanged(Player* pPlayer, int32& amount);
    void OnGiveXP(Player* pPlayer, uint32& amount, Unit* pVictim);
    void OnReputationChange(Player* pPlayer, uint32 factionID, int32& standing, bool incremental);
    void OnDuelRequest(Player* pTarget, Player* pChallenger);
    void OnDuelStart(Player* pStarter, Player* pChallenger);
    void OnDuelEnd(Player* pWinner, Player* pLoser, DuelCompleteType type);
    void OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Player* pReceiver);
    bool OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg);
    bool OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Group* pGroup);
    bool OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Guild* pGuild);
    bool OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Channel* pChannel);
    void OnEmote(Player* pPlayer, uint32 emote);
    void OnTextEmote(Player* pPlayer, uint32 textEmote, uint32 emoteNum, uint64 guid);
    void OnSpellCast(Player* pPlayer, Spell* pSpell, bool skipCheck);
    void OnLogin(Player* pPlayer);
    void OnLogout(Player* pPlayer);
    void OnCreate(Player* pPlayer);
    void OnDelete(uint32 guid);
    void OnSave(Player* pPlayer);
    void OnBindToInstance(Player* pPlayer, Difficulty difficulty, uint32 mapid, bool permanent);
    void OnUpdateZone(Player* pPlayer, uint32 newZone, uint32 newArea);
    void OnMapChanged(Player* pPlayer); // TODO
    void HandleGossipSelectOption(Player* pPlayer, uint32 menuId, uint32 sender, uint32 action, std::string code);
    /* AreaTrigger */
    bool OnAreaTrigger(Player* pPlayer, AreaTriggerEntry const* pTrigger);
    /* Weather */
    void OnChange(Weather* weather, WeatherState state, float grade);
    // condition
    bool OnConditionCheck(Condition* condition, ConditionSourceInfo& sourceInfo) { return false; }; // TODO ?
    // transport
    void OnAddPassenger(Transport* transport, Player* player);
    void OnAddCreaturePassenger(Transport* transport, Creature* creature);
    void OnRemovePassenger(Transport* transport, Player* player);
    void OnRelocate(Transport* transport, uint32 waypointId, uint32 mapId, float x, float y, float z);
    /* Guild */
    void OnAddMember(Guild* guild, Player* player, uint32 plRank);
    void OnRemoveMember(Guild* guild, Player* player, bool isDisbanding, bool isKicked);
    void OnMOTDChanged(Guild* guild, const std::string& newMotd);
    void OnInfoChanged(Guild* guild, const std::string& newInfo);
    void OnCreate(Guild* guild, Player* leader, const std::string& name); // TODO: Implement to TC
    void OnDisband(Guild* guild);
    void OnMemberWitdrawMoney(Guild* guild, Player* player, uint32 &amount, bool isRepair);
    void OnMemberDepositMoney(Guild* guild, Player* player, uint32 &amount);
    void OnItemMove(Guild* guild, Player* player, Item* pItem, bool isSrcBank, uint8 srcContainer, uint8 srcSlotId, bool isDestBank, uint8 destContainer, uint8 destSlotId);
    void OnEvent(Guild* guild, uint8 eventType, uint32 playerGuid1, uint32 playerGuid2, uint8 newRank);
    void OnBankEvent(Guild* guild, uint8 eventType, uint8 tabId, uint32 playerGuid, uint32 itemOrMoney, uint16 itemStackCount, uint8 destTabId);
    /* Group */
    void OnAddMember(Group* group, uint64 guid);
    void OnInviteMember(Group* group, uint64 guid);
    void OnRemoveMember(Group* group, uint64 guid, uint8 method, uint64 kicker, const char* reason);
    void OnChangeLeader(Group* group, uint64 newLeaderGuid, uint64 oldLeaderGuid);
    void OnDisband(Group* group);
    void OnCreate(Group* group, uint64 leaderGuid, GroupType groupType);
};
#define sHookMgr ACE_Singleton<HookMgr, ACE_Null_Mutex>::instance()

class ElunaCreatureScript : public CreatureScript
{
public:
    ElunaCreatureScript() : CreatureScript("Smart_ElunaCreatureScript") { } // Smart suppressing error @startup 
    ~ElunaCreatureScript() { }
    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return sHookMgr->GetAI(creature);
    }
};

class ElunaGameObjectScript : public GameObjectScript
{
public:
    ElunaGameObjectScript() : GameObjectScript("Smart_ElunaGameObjectScript") { } // Smart suppressing error @startup
    ~ElunaGameObjectScript() { }
    GameObjectAI* GetAI(GameObject* gameObject) const OVERRIDE
    {
        return sHookMgr->GetAI(gameObject);
    }
};

#endif
