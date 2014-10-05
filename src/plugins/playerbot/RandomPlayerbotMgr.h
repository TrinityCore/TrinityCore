#ifndef _RandomPlayerbotMgr_H
#define _RandomPlayerbotMgr_H

#include "Common.h"
#include "PlayerbotAIBase.h"
#include "PlayerbotMgr.h"

class WorldPacket;
class Player;
class Unit;
class Object;
class Item;

using namespace std;

class RandomPlayerbotMgr : public PlayerbotHolder
{
    public:
        RandomPlayerbotMgr();
        virtual ~RandomPlayerbotMgr();
        static RandomPlayerbotMgr& instance()
        {
            static RandomPlayerbotMgr instance;
            return instance;
        }

        virtual void UpdateAIInternal(uint32 elapsed);

	public:
        static bool HandlePlayerbotConsoleCommand(ChatHandler* handler, char const* args);
        bool IsRandomBot(Player* bot);
        bool IsRandomBot(uint32 bot);
        void Randomize(Player* bot);
        void RandomizeFirst(Player* bot);
        void IncreaseLevel(Player* bot);
        void ScheduleTeleport(uint32 bot);
        void HandleCommand(uint32 type, const string& text, Player& fromPlayer);
        string HandleRemoteCommand(string request);
        void OnPlayerLogout(Player* player);
        void OnPlayerLogin(Player* player);
        Player* GetRandomPlayer();
        void PrintStats();
        double GetBuyMultiplier(Player* bot);
        double GetSellMultiplier(Player* bot);
        uint32 GetLootAmount(Player* bot);
        void SetLootAmount(Player* bot, uint32 value);
        uint32 GetTradeDiscount(Player* bot);
        void Refresh(Player* bot);
        void RandomTeleportForLevel(Player* bot);

	protected:
	    virtual void OnBotLoginInternal(Player * const bot) {}

    private:
        uint32 GetEventValue(uint32 bot, string event);
        uint32 SetEventValue(uint32 bot, string event, uint32 value, uint32 validIn);
        list<uint32> GetBots();
        vector<uint32> GetFreeBots(bool alliance);
        uint32 AddRandomBot(bool alliance);
        bool ProcessBot(uint32 bot);
        void ScheduleRandomize(uint32 bot, uint32 time);
        void RandomTeleport(Player* bot, uint16 mapId, float teleX, float teleY, float teleZ);
        void RandomTeleport(Player* bot, vector<WorldLocation> &locs);
        uint32 GetZoneLevel(uint16 mapId, float teleX, float teleY, float teleZ);

    private:
        vector<Player*> players;
        int processTicks;
};

#define sRandomPlayerbotMgr RandomPlayerbotMgr::instance()

#endif
