#ifndef _PLAYERBOTMGR_H
#define _PLAYERBOTMGR_H

#include "Common.h"
#include "PlayerbotAIBase.h"
#include "../pchdef.h"

class WorldPacket;
class Player;
class Unit;
class Object;
class Item;

typedef map<uint64, Player*> PlayerBotMap;

class PlayerbotHolder : public PlayerbotAIBase
{
public:
    PlayerbotHolder();
    virtual ~PlayerbotHolder();

    void AddPlayerBot(uint64 guid, uint32 masterAccountId);
    void LogoutPlayerBot(uint64 guid);
    Player* GetPlayerBot (uint64 guid) const;
    PlayerBotMap::const_iterator GetPlayerBotsBegin() const { return playerBots.begin(); }
    PlayerBotMap::const_iterator GetPlayerBotsEnd()   const { return playerBots.end();   }

    virtual void UpdateAIInternal(uint32 elapsed);
    void UpdateSessions(uint32 elapsed);

    void LogoutAllBots();
    void OnBotLogin(Player * const bot);

    list<string> HandlePlayerbotCommand(char const* args, Player* master = NULL);
    string ProcessBotCommand(string cmd, ObjectGuid guid, bool admin, uint32 masterAccountId, uint32 masterGuildId);
    uint32 GetAccountId(string name);
    string ListBots(Player* master);

protected:
    virtual void OnBotLoginInternal(Player * const bot) = 0;

protected:
    PlayerBotMap playerBots;
};

class PlayerbotMgr : public PlayerbotHolder
{
public:
    PlayerbotMgr(Player* const master);
    virtual ~PlayerbotMgr();

    static bool HandlePlayerbotMgrCommand(ChatHandler* handler, char const* args);
    void HandleMasterIncomingPacket(const WorldPacket& packet);
    void HandleMasterOutgoingPacket(const WorldPacket& packet);
    void HandleCommand(uint32 type, const string& text);

    virtual void UpdateAIInternal(uint32 elapsed);

    Player* GetMaster() const { return master; };

    void SaveToDB();

protected:
    virtual void OnBotLoginInternal(Player * const bot);

private:
    Player* const master;
};

#endif
