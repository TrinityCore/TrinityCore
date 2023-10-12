#pragma execution_character_set("utf-8")
#include "Config.h"
#include "World.h"

class announce_login : public PlayerScript
{
public:
    announce_login() : PlayerScript("announce_login") { }

    void OnLogin(Player* player, bool /*loginFirst*/)
    {   //登录激活护符
        player->CastAllObtainSpells();
        if (sConfigMgr->GetBoolDefault("Login.Announcer.Enable", false))//world.conf 设定是否启动
        {
            if (player->GetTeam() == ALLIANCE)
            {
                std::ostringstream ss;
                ss << "|cff3DAEFF[ -上线提示- ]|cffFFD800 : -玩家- |cff4CFF00 " << player->GetName() << " |cffFFD800 -上线了，阵营为-|cff0026FF -联盟-";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
            }
            else
            {
                std::ostringstream ss;
                ss << "|cff3DAEFF[ -上线提示- ]|cffFFD800 : -玩家- |cff4CFF00 " << player->GetName() << " |cffFFD800 -上线了，阵营为-|cffFF0000 -部落-";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
            }
        }
    }
};

void AddSC_announce_login()
{
    new announce_login;
}
