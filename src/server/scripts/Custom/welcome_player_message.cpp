//来源:https://uiwow.com/thread-1102-1-1.html
//角色欢迎公告
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
            message << "|cff3ADF00Please welcome " << player->GetName() << " to our server,a brand new world is waiting for you to explorer!|r";//英文原版
            //message << "|cff3ADF00" << player->GetName() << ",这是你首次来到小女孩的魔兽世界,欢迎你!崭新的世界等你的探索...|r";
            //中文好像不能显示,先使用英文
            sWorld->SendGlobalText(message.str().c_str(), nullptr);
        }
        else
        {
            message << "|cff3ADF00Glade to see you back,how is everything going? " << player->GetName() << "!|r";//英文原版
                       // message << "|cff3ADF00" << player->GetName() << ",欢迎回来!一切过得如何?|r";
            ChatHandler(player->GetSession()).PSendSysMessage(message.str().c_str());
        }
    }
};

void AddSC_onlogin_announcer()
{
    new welcome_player_message();
}
