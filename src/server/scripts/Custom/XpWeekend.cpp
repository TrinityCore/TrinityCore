#include "Player.h"
#include "ScriptMgr.h"
#include "Chat.h"
#include "World.h"
#include "boost/date_time.hpp"
#include "Config.h"

    class XpWeekend : public PlayerScript
    {
    public:
        XpWeekend() : PlayerScript("XpWeekend") { }
        void OnGiveXP(Player* /*player*/, uint32& amount, Unit* /*victim*/)override
        {
            if (sConfigMgr->GetBoolDefault("DynamicXP.Enable", true))   //配置里要增加DynamicXP.Enable选项
            {
                boost::gregorian::date date(boost::gregorian::day_clock::local_day());//检测是否是星期五、六或兴趣天,是则加倍经验
                auto day = date.day_of_week();
                if (day == boost::date_time::Friday ||   
                    day == boost::date_time::Saturday ||
                    day == boost::date_time::Sunday) {

                    amount = amount * 2;
                }
            }
        }
        void OnLogin(Player* player, bool /*firstLogin*/)
        {
            if (sConfigMgr->GetBoolDefault("DynamicXP.Enable", true))
            {
                boost::gregorian::date date(boost::gregorian::day_clock::local_day());
                auto day = date.day_of_week();
                if (day == boost::date_time::Friday ||
                    day == boost::date_time::Saturday ||
                    day == boost::date_time::Sunday) {

                    ChatHandler(player->GetSession()).PSendSysMessage("Double XP | ACTIVATED");
                }
            }
        }
    };

void AddSC_XpWeekend()
{
    new XpWeekend();
}
