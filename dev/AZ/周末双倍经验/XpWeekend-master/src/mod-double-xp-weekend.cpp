#include "Configuration/Config.h"
#include "ScriptMgr.h"
#include <time.h>

bool Enabled;
uint32 xpAmount;
time_t t = time(NULL);
tm *now = localtime(&t);

class DoubleXpWeekend : public PlayerScript
{
public:
    DoubleXpWeekend() : PlayerScript("DoubleXpWeekend") {}

        void OnLogin(Player* player)
        {
            // Announce to the player that the XP weekend is happeneing.
            if (!Enabled)
                return;

            if (now->tm_wday == 5 /*Friday*/ || now->tm_wday == 6 /*Satureday*/ || now->tm_wday == 0/*Sunday*/)
                ChatHandler(player->GetSession()).PSendSysMessage("Its the Weekend! Your XP rate has been set to: %u", xpAmount);
            else
                ChatHandler(player->GetSession()).PSendSysMessage("XPWeekend Module is enabled");
        }

        void OnGiveXP(Player* p, uint32& amount, Unit* victim) override
        {
            if (!Enabled)
                return;

            if (now->tm_wday == 5 /*Friday*/ || now->tm_wday == 6 /*Satureday*/ || now->tm_wday == 0/*Sunday*/ && now->tm_hour >= 0)
                amount *= xpAmount;
            else
                amount == amount;
        }
};

class DoubleXpWeekendConf : public WorldScript
{
public:
    DoubleXpWeekendConf() : WorldScript("DoubleXpConf") {}

    void OnBeforeConfigLoad(bool reload) override
    {
        if (!reload) {
            std::string conf_path = _CONF_DIR;
            std::string cfg_file = conf_path + "/mod-double-XP-weekend.conf";

#ifdef WIN32
            cfg_file = "mod-double-XP-weekend.conf";
#endif

            std::string cfg_def_file = cfg_file + ".dist";
            sConfigMgr->LoadMore(cfg_def_file.c_str());
            sConfigMgr->LoadMore(cfg_file.c_str());

            Enabled = sConfigMgr->GetBoolDefault("XPWeekend.Enabled", true);
            xpAmount = sConfigMgr->GetIntDefault("XPWeekend.xpAmount", 2);

        }
    }
};


void AdddoublexpScripts()
{
    new DoubleXpWeekendConf();
    new DoubleXpWeekend();
}
