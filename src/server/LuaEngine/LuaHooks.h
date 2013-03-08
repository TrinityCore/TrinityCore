#include "Common.h"
#include "Player.h"

#ifndef LUAHOOKS_H
#define LUAHOOKS_H

enum RegisterTypes
{
    REGTYPE_SERVER,
    REGTYPE_CREATURE,
    REGTYPE_CREATURE_GOSSIP,
    REGTYPE_GAMEOBJECT,
    REGTYPE_GAMEOBJECT_GOSSIP,
    REGTYPE_ITEM,
    REGTYPE_ITEM_GOSSIP,
    REGTYPE_PLAYER_GOSSIP,
    REGTYPE_COUNT
};

enum ServerEvents
{
    // Player
    PLAYER_EVENT_ON_CHARACTER_CREATE        =     1,            // (event, player)
    PLAYER_EVENT_ON_CHARACTER_DELETE        =     2,            // (event, guid)
    PLAYER_EVENT_ON_LOGIN                   =     3,            // (event, player)
    PLAYER_EVENT_ON_LOGOUT                  =     4,            // (event, player)
    PLAYER_EVENT_ON_SPELL_CAST              =     5,            // (event, player, spell, skipCheck)
    PLAYER_EVENT_ON_KILL_PLAYER             =     6,            // (event, killer, killed)
    PLAYER_EVENT_ON_KILL_CREATURE           =     7,            // (event, killer, killed)
    PLAYER_EVENT_ON_KILLED_BY_CREATURE      =     8,            // (event, killer, killed)
    PLAYER_EVENT_ON_DUEL_REQUEST            =     9,            // (event, target, challenger)
    PLAYER_EVENT_ON_DUEL_START              =     10,           // (event, player1, player2)
    PLAYER_EVENT_ON_DUEL_END                =     11,           // (event, winner, loser, type)
    PLAYER_EVENT_ON_GIVE_XP                 =     12,           // (event, player, amount, victim)
    PLAYER_EVENT_ON_LEVEL_CHANGE            =     13,           // (event, player, oldLevel)
    PLAYER_EVENT_ON_MONEY_CHANGE            =     14,           // (event, player, amount)
    PLAYER_EVENT_ON_REPUTATION_CHANGE       =     15,           // (event, player, factionId, standing, incremental)
    PLAYER_EVENT_ON_TALENTS_CHANGE          =     16,           // (event, player, points)
    PLAYER_EVENT_ON_TALENTS_RESET           =     17,           // (event, player, noCost)
    PLAYER_EVENT_ON_CHAT                    =     18,           // (event, player, msg, Type, lang)
    PLAYER_EVENT_ON_WHISPER                 =     19,           // (event, player, msg, Type, lang, receiver)
    PLAYER_EVENT_ON_GROUP_CHAT              =     20,           // (event, player, msg, Type, lang, group)
    PLAYER_EVENT_ON_GUILD_CHAT              =     21,           // (event, player, msg, Type, lang, guild)
    PLAYER_EVENT_ON_CHANNEL_CHAT            =     22,           // (event, player, msg, Type, lang, channel)
    PLAYER_EVENT_ON_EMOTE                   =     23,           // (event, player, emote) -- Not triggered on any known emote
    PLAYER_EVENT_ON_TEXT_EMOTE              =     24,           // (event, player, textEmote, emoteNum, guid)
    PLAYER_EVENT_ON_SAVE                    =     25,           // (event, player)
    PLAYER_EVENT_ON_BIND_TO_INSTANCE        =     26,           // (event, player, difficulty, mapid, permanent)
    PLAYER_EVENT_ON_UPDATE_ZONE             =     27,           // (event, player, newZone, newArea)
    PLAYER_EVENT_ON_MAP_CHANGE              =     28,           // (event, player)

    // Guild
    GUILD_EVENT_ON_ADD_MEMBER               =     29,           // Implemented -- Commented out
    GUILD_EVENT_ON_REMOVE_MEMBER            =     30,           // Implemented -- Commented out
    GUILD_EVENT_ON_MOTD_CHANGE              =     31,           // Implemented -- Commented out
    GUILD_EVENT_ON_INFO_CHANGE              =     32,           // Implemented -- Commented out
    GUILD_EVENT_ON_CREATE                   =     33,           // Implemented -- Commented out
    GUILD_EVENT_ON_DISBAND                  =     34,           // Implemented -- Commented out
    GUILD_EVENT_ON_MONEY_WITHDRAW           =     35,           // Implemented -- Commented out
    GUILD_EVENT_ON_MONEY_DEPOSIT            =     36,           // Implemented -- Commented out
    GUILD_EVENT_ON_ITEM_MOVE                =     37,           // Implemented -- Commented out
    GUILD_EVENT_ON_EVENT                    =     38,           // Implemented -- Commented out
    GUILD_EVENT_ON_BANK_EVENT               =     39,           // Implemented -- Commented out

    // Server
    SERVER_EVENT_ON_NETWORK_START           =     40,           // Not Implemented
    SERVER_EVENT_ON_NETWORK_STOP            =     41,           // Not Implemented
    SERVER_EVENT_ON_SOCKET_OPEN             =     42,           // Not Implemented
    SERVER_EVENT_ON_SOCKET_CLOSE            =     43,           // Not Implemented
    SERVER_EVENT_ON_PACKET_RECEIVE          =     44,           // Not Implemented
    SERVER_EVENT_ON_PACKET_RECEIVE_UNKNOWN  =     45,           // Not Implemented
    SERVER_EVENT_ON_PACKET_SEND             =     46,           // Not Implemented

    // World
    WORLD_EVENT_ON_OPEN_STATE_CHANGE        =     47,           // (event, open)
    WORLD_EVENT_ON_CONFIG_LOAD              =     48,           // (event, reload)
    WORLD_EVENT_ON_MOTD_CHANGE              =     49,           // (event, newMOTD)
    WORLD_EVENT_ON_SHUTDOWN_INIT            =     50,           // (event, code, mask)
    WORLD_EVENT_ON_SHUTDOWN_CANCEL          =     51,           // (event)
    WORLD_EVENT_ON_UPDATE                   =     52,           // (event, diff)
    WORLD_EVENT_ON_STARTUP                  =     53,           // (event)
    WORLD_EVENT_ON_SHUTDOWN                 =     54,           // (event)

    // Eluna
    ELUNA_EVENT_ON_RESTART                  =     55,           // (event)

    // Map
    MAP_EVENT_ON_CREATE                     =     56,           // Not Implemented
    MAP_EVENT_ON_DESTROY                    =     57,           // Not Implemented
    MAP_EVENT_ON_LOAD                       =     58,           // Not Implemented
    MAP_EVENT_ON_UNLOAD                     =     59,           // Not Implemented
    MAP_EVENT_ON_PLAYER_ENTER               =     60,           // Not Implemented
    MAP_EVENT_ON_PLAYER_LEAVE               =     61,           // Not Implemented
    MAP_EVENT_ON_UPDATE                     =     62,           // Not Implemented

    // Area trigger
    TRIGGER_EVENT_ON_TRIGGER                =     63,           // (event, player, triggerId)

    // Weather
    WEATHER_EVENT_ON_CHANGE                 =     64,           // (event, weather, state, grade)

    // Auction house
    AUCTION_EVENT_ON_ADD                    =     65,           // Not Implemented
    AUCTION_EVENT_ON_REMOVE                 =     66,           // Not Implemented
    AUCTION_EVENT_ON_SUCCESFUL              =     67,           // Not Implemented
    AUCTION_EVENT_ON_EXPIRE                 =     68,           // Not Implemented

    // Group
    GROUP_EVENT_ON_MEMBER_ADD               =     69,           // (event, group, guid)
    GROUP_EVENT_ON_MEMBER_INVITE            =     70,           // (event, group, guid)
    GROUP_EVENT_ON_MEMBER_REMOVE            =     71,           // (event, group, guid, method, kicker, reason)
    GROUP_EVENT_ON_LEADER_CHANGE            =     72,           // (event, group, newLeaderGuid, oldLeaderGuid)
    GROUP_EVENT_ON_DISBAND                  =     73,           // (event, group)

    SERVER_EVENT_COUNT
};

enum CreatureEvents
{
    CREATURE_EVENT_ON_ENTER_COMBAT                    = 1,      //Implemented
    CREATURE_EVENT_ON_LEAVE_COMBAT                    = 2,      //Implemented
    CREATURE_EVENT_ON_TARGET_DIED                     = 3,      //Implemented
    CREATURE_EVENT_ON_DIED                            = 4,      //Implemented
    CREATURE_EVENT_ON_SPAWN                           = 5,      //Implemented
    CREATURE_EVENT_ON_REACH_WP                        = 6,      //Implemented
    CREATURE_EVENT_ON_AIUPDATE                        = 7,      //Implemented
    CREATURE_EVENT_ON_RECEIVE_EMOTE                   = 8,      //Implemented
    CREATURE_EVENT_ON_DAMAGE_TAKEN                    = 9,      //Implemented
    CREATURE_EVENT_ON_PRE_COMBAT                      = 10,     //Implemented
    CREATURE_EVENT_ON_ATTACKED_AT                     = 11,     //Implemented
    CREATURE_EVENT_ON_OWNER_ATTACKED                  = 12,     //Implemented
    CREATURE_EVENT_ON_OWNER_ATTACKED_AT               = 13,     //Implemented
    CREATURE_EVENT_ON_HIT_BY_SPELL                    = 14,     //Implemented
    CREATURE_EVENT_ON_SPELL_HIT_TARGET                = 15,     //Implemented
    CREATURE_EVENT_ON_SPELL_CLICK                     = 16,     //Implemented
    CREATURE_EVENT_ON_CHARMED                         = 17,     //Implemented
    CREATURE_EVENT_ON_POSSESS                         = 18,     //Implemented
    CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE          = 19,     //Implemented
    CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN       = 20,     //Implemented
    CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED          = 21,     //Implemented
    CREATURE_EVENT_ON_SUMMONED                        = 22,     //Implemented
    CREATURE_EVENT_ON_RESET                           = 23,     //Implemented
    CREATURE_EVENT_ON_REACH_HOME                      = 24,     //Implemented
    CREATURE_EVENT_ON_CAN_RESPAWN                     = 25,     //Implemented
    CREATURE_EVENT_ON_CORPSE_REMOVED                  = 26,     //Implemented
    CREATURE_EVENT_ON_MOVE_IN_LOS                     = 27,     //Implemented
    CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS             = 28,     //Implemented
    CREATURE_EVENT_ON_PASSANGER_BOARDED               = 29,     //Implemented
    CREATURE_EVENT_ON_DUMMY_EFFECT                    = 30,     //Implemented
    CREATURE_EVENT_ON_QUEST_ACCEPT                    = 31,     //Implemented
    CREATURE_EVENT_ON_QUEST_SELECT                    = 32,     //Implemented
    CREATURE_EVENT_ON_QUEST_COMPLETE                  = 33,     //Implemented
    CREATURE_EVENT_ON_QUEST_REWARD                    = 34,     //Implemented
    CREATURE_EVENT_ON_DIALOG_STATUS                   = 35,     //Implemented
    CREATURE_EVENT_COUNT
};

enum GameObjectEvents
{
    GAMEOBJECT_EVENT_ON_AIUPDATE                    = 1,    // Implemented
    GAMEOBJECT_EVENT_ON_RESET                       = 2,    // Implemented
    GAMEOBJECT_EVENT_ON_DUMMY_EFFECT                = 3,    // Implemented
    GAMEOBJECT_EVENT_ON_QUEST_ACCEPT                = 4,    // Implemented
    GAMEOBJECT_EVENT_ON_QUEST_REWARD                = 5,    // Implemented
    GAMEOBJECT_EVENT_ON_DIALOG_STATUS               = 6,    // Implemented
    GAMEOBJECT_EVENT_ON_DESTROYED                   = 7,    // Implemented
    GAMEOBJECT_EVENT_ON_DAMAGED                     = 8,    // Implemented
    GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE           = 9,    // Implemented
    GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED            = 10,   // Implemented
    GAMEOBJECT_EVENT_COUNT
};

enum ItemEvents
{
    ITEM_EVENT_ON_DUMMY_EFFECT                      = 1,    // Implemented
    ITEM_EVENT_ON_USE                               = 2,    // Implemented
    ITEM_EVENT_ON_QUEST_ACCEPT                      = 3,    // Implemented
    ITEM_EVENT_ON_EXPIRE                            = 4,    // Implemented
    ITEM_EVENT_COUNT
};

enum GossipEvents
{
    GOSSIP_EVENT_ON_HELLO = 1,
    GOSSIP_EVENT_ON_SELECT = 2,
    GOSSIP_EVENT_COUNT
};

void HandleGossipSelectOption(Player* player, uint64 guid, uint32 sender, uint32 action, std::string code, uint32 menuId);
bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg);
bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg, Group* group);
bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild);
bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg, Channel* channel);
void OnElunaRestart(uint32 eventId);
void Eluna_AddScriptHooks();

#endif
