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
        if (sConfigMgr->GetBoolDefault("Boss.Announcer.Enable", true))//world.conf �����Ƿ���
        {
            //if (boss->isWorldBoss())  ԭ����
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
                    "|r|cff" << plr_colour << " " << plr << //�˴���plr = player->GetName(),�ο�ǰ��Ķ���.����ȡ�������.
                    "|r ���͵Ļ�ɱ�� |CFF" << boss_colour << "[" << boss_n << "]|r " "-BOSS��ɱͨ��-" << "!";//Ӣ��ԭ��
                    //"|r �ĵĶ����ɱ�� |CFF" << boss_colour << "[" << boss_n << "]|r " "boss" << "!";
                sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
            }
        }
    };
};

void AddSC_Boss_Announcer()
{
    new Boss_Announcer;
}
