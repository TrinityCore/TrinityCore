//��Դ:https://uiwow.com/thread-1102-1-1.html
//��ɫ��ӭ����
#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"
#include <World.h>

class welcome_player_message : public PlayerScript
{
public:
    welcome_player_message() : PlayerScript("welcome_player_message") { }

    void OnLogin(Player* player, bool firstLogin) override
    {
        std::ostringstream message;
        if (firstLogin)
        {
            //message << "|cff3ADF00Please welcome " << player->GetName() << " to our server!|r";//Ӣ��ԭ��
            message << "|cff3ADF00" << player->GetName() << ",�������״�����СŮ����ħ������,��ӭ��!ո�µ���������̽��...|r";
            sWorld->SendGlobalText(message.str().c_str(), nullptr);
        }
        else
        {
            //message << "|cff3ADF00Glade to see you back " << player->GetName() << "!|r";//Ӣ��ԭ��
            message << "|cff3ADF00" << player->GetName() << ",��ӭ����!һ�й������?|r";
            ChatHandler(player->GetSession()).PSendSysMessage(message.str().c_str());
        }
    }
};

void AddSC_onlogin_announcer()
{
    new welcome_player_message();
}
