#include "Config.h"
#include "World.h"

class announce_login : public PlayerScript
{
public:
    announce_login() : PlayerScript("announce_login") { }

    void OnLogin(Player* player, bool /*loginFirst*/)
    {
        if (sConfigMgr->GetBoolDefault("Login.Announcer.Enable", true))//读取配置文件
        {
            if (player->GetTeam() == ALLIANCE)
            {
                std::ostringstream ss;
                ss << "|cff3DAEFF[ Login Announcer ]|cffFFD800 : Player|cff4CFF00 " << player->GetName() << " |cffFFD800Is Online. This Player is|cff0026FF Alliance";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());//**上线了,名字是:**,联盟
            }
            else
            {
                std::ostringstream ss;
                ss << "|cff3DAEFF[ Login Announcer ]|cffFFD800 : Player|cff4CFF00 " << player->GetName() << " |cffFFD800Is Online. This Player is|cffFF0000 Horde";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());//**上线了,名字是:**,部落
            }
        }
    }
};

void AddSC_announce_login()
{
    new announce_login;
}
