#ifndef _BOTMGR_H
#define _BOTMGR_H

#include "Common.h"

class Creature;
class Map;
class Player;

struct Position;

enum BotAddResult
{
    BOT_ADD_DISABLED                    = 0x001,
    BOT_ADD_ALREADY_HAVE                = 0x002,
    BOT_ADD_MAX_EXCEED                  = 0x004,
    BOT_ADD_MAX_CLASS_EXCEED            = 0x008,
    BOT_ADD_CANT_AFFORD                 = 0x010,
    BOT_ADD_INSTANCE_LIMIT              = 0x020,
    BOT_ADD_BUSY                        = 0x040,
    BOT_ADD_NOT_AVAILABLE               = 0x080,

    BOT_ADD_SUCCESS                     = 0x100,

    BOT_ADD_ALL_MASK                    = 0xFFF,

    BOT_ADD_FATAL                       = (BOT_ADD_DISABLED | BOT_ADD_CANT_AFFORD | BOT_ADD_MAX_EXCEED | BOT_ADD_MAX_CLASS_EXCEED)
};

enum BotRemoveType
{
    BOT_REMOVE_LOGOUT                   = 0,
    BOT_REMOVE_DISMISS                  = 1,
    BOT_REMOVE_HIDE                     = 2, //NYI
    BOT_REMOVE_UNSUMMON                 = 3,
    BOT_REMOVE_BY_DEFAULT               = BOT_REMOVE_LOGOUT
};

typedef std::unordered_map<ObjectGuid /*guid*/, Creature* /*bot*/> BotMap;

class BotMgr
{
    public:
        BotMgr(Player* const master);
        ~BotMgr();

        Player* GetOwner() const { return _owner; }

        BotMap const* GetBotMap() const { return &_bots; }
        BotMap* GetBotMap() { return &_bots; }

        static bool IsNpcBotModEnabled();
        static bool IsAllowGMModEnabled();
        static bool IsNpcBotDungeonFinderEnabled();

        static void ReloadConfig() { LoadConfig(true); }
        static void LoadConfig(bool force = false);

        void Update(uint32 diff);

        Creature* GetBot(ObjectGuid guid) const;
        bool HaveBot() const { return !_bots.empty(); }
        uint8 GetNpcBotsCount(bool inWorldOnly = false) const;
        static uint8 GetMaxNpcBots();
        static uint8 GetNpcBotXpReduction();
        static bool LimitBots(Map const* map);
        bool RestrictBots(Creature const* bot, bool add) const;

        static uint32 GetNpcBotCost(uint8 level, Creature* creature);
        static std::string GetNpcBotCostStr(uint8 level, Creature* creature);

        void OnTeleportFar(uint32 mapId, float x, float y, float z, float ori = 0.f);
        void ReviveAllBots();
        void SendBotCommandState(CommandStates state);

        void CleanupsBeforeBotDelete(ObjectGuid guid);
        void RemoveAllBots(uint8 removetype = BOT_REMOVE_LOGOUT);
        void RemoveBot(ObjectGuid guid, uint8 removetype = BOT_REMOVE_LOGOUT);
        BotAddResult AddBot(Creature* bot, bool takeMoney = false);
        bool AddBotToGroup(Creature* bot);
        bool RemoveBotFromGroup(Creature* bot);
        bool RemoveAllBotsFromGroup(bool newGroup);

        uint8 GetBotFollowDist() const { return _followdist; }
        void SetBotFollowDist(int8 dist) { _followdist = dist; }

        void SetBotsShouldUpdateStats();

        static void ReviveBot(Creature* bot) { _reviveBot(bot); }

        //TELEPORT BETWEEN MAPS
        //CONFIRMEND UNSAFE (charmer,owner)
        static void TeleportBot(Creature* bot, Map* newMap, Position* pos);

    private:
        static void _teleportBot(Creature* bot, Map* newMap, float x, float y, float z, float ori = 0.f);

        bool _isPartyInCombat() const;
        static void _reviveBot(Creature* bot);

        void _addBotToRemoveList(ObjectGuid guid);

        Player* const _owner;
        BotMap _bots;
        GuidList _removeList;

        int8 _followdist;
};

#endif
