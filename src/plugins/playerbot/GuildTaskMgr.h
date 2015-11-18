#ifndef _GuildTaskMgr_H
#define _GuildTaskMgr_H

#include "Common.h"
#include "PlayerbotAIBase.h"

using namespace std;

class GuildTaskMgr
{
    public:
        GuildTaskMgr();
        virtual ~GuildTaskMgr();
        static GuildTaskMgr& instance()
        {
            static GuildTaskMgr instance;
            return instance;
        }

        void Update(Player* owner, Player* guildMaster);

	public:
        static bool HandleConsoleCommand(ChatHandler* handler, char const* args);
        bool IsGuildTaskItem(uint32 itemId, uint32 guildId);
        void CheckItemTask(uint32 itemId, uint32 obtained, Player* owner, Player* bot, bool byMail = false);
        void CheckKillTask(Player* owner, Unit* victim);

    private:
        map<uint32,uint32> GetTaskValues(uint32 owner, string type, uint32 *validIn = NULL);
        uint32 GetTaskValue(uint32 owner, uint32 guildId, string type, uint32 *validIn = NULL);
        uint32 SetTaskValue(uint32 owner, uint32 guildId, string type, uint32 value, uint32 validIn);
        uint32 CreateTask(uint32 owner, uint32 guildId);
        bool SendAdvertisement(uint32 owner, uint32 guildId);
        bool SendItemAdvertisement(uint32 itemId, uint32 owner, uint32 guildId);
        bool SendKillAdvertisement(uint32 creatureId, uint32 owner, uint32 guildId);
        bool SendThanks(uint32 owner, uint32 guildId);
        bool Reward(uint32 owner, uint32 guildId);
        bool CreateItemTask(uint32 owner, uint32 guildId);
        bool CreateKillTask(uint32 owner, uint32 guildId);
        uint32 GetMaxItemTaskCount(uint32 itemId);
};

#define sGuildTaskMgr GuildTaskMgr::instance()

#endif
