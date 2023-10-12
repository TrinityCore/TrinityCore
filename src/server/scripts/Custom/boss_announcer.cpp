#pragma execution_character_set("utf-8")
#include "ScriptMgr.h"
#include "Config.h"
#include "Player.h"
#include "World.h"

class Boss_Announcer : public PlayerScript
{
public:
    Boss_Announcer() : PlayerScript("Boss_Announcer") {}

    void OnCreatureKill(Player* player, Creature* boss)
    {
        if (sConfigMgr->GetBoolDefault("Boss.Announcer.Enable", true))//world.conf 设置是否开启
        {
            //if (boss->isWorldBoss())  原代码
            if (boss->isWorldBoss() || boss->IsDungeonBoss())
            {
                std::string plr = player->GetName();
                std::string boss_n = boss->GetName();
                //bool ingroup = player->GetGroup();
                std::string tag_colour = "7bbef7";
                std::string plr_colour = "7bbef7";
                std::string boss_colour = "ff0000";
                std::ostringstream stream;
                stream << "|CFF" << tag_colour <<
                    "|r|cff" << plr_colour << " " << plr << //此处的plr = player->GetName(),参看前面的定义.即获取玩家姓名.
                    "|r 勇猛的击杀了 |CFF" << boss_colour << "[" << boss_n << "]|r " "-BOSS击杀通告-" << "!";//英文原版
                    //"|r 的的队伍击杀了 |CFF" << boss_colour << "[" << boss_n << "]|r " "boss" << "!";
                sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
            }
        }
    };
};

void AddSC_Boss_Announcer()
{
    new Boss_Announcer;
}
