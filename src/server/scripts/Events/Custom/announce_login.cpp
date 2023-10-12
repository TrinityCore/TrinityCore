#pragma execution_character_set("utf-8")
#include "Config.h"
#include "World.h"

class announce_login : public PlayerScript
{
public:
    announce_login() : PlayerScript("announce_login") { }

    void OnLogin(Player* player, bool /*loginFirst*/)
    {   //��¼�����
        player->CastAllObtainSpells();
        if (sConfigMgr->GetBoolDefault("Login.Announcer.Enable", false))//world.conf �趨�Ƿ�����
        {
            if (player->GetTeam() == ALLIANCE)
            {
                std::ostringstream ss;
                ss << "|cff3DAEFF[ -������ʾ- ]|cffFFD800 : -���- |cff4CFF00 " << player->GetName() << " |cffFFD800 -�����ˣ���ӪΪ-|cff0026FF -����-";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
            }
            else
            {
                std::ostringstream ss;
                ss << "|cff3DAEFF[ -������ʾ- ]|cffFFD800 : -���- |cff4CFF00 " << player->GetName() << " |cffFFD800 -�����ˣ���ӪΪ-|cffFF0000 -����-";
                sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
            }
        }
    }
};

void AddSC_announce_login()
{
    new announce_login;
}
