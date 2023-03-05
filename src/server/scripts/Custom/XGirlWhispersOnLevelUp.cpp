#include "Config.h"
#include "Chat.h"

class XGirlWhispersOnLevelUp : public PlayerScript
{
    enum levels
    {
        start_level = 1,
        max_level = 70
    };

public:
	XGirlWhispersOnLevelUp() : PlayerScript("XGirlWhispersOnLevelUp") { }
	void OnLevelChanged(Player * player, uint8 oldLevel)
	{
        if (sConfigMgr->GetBoolDefault("XGirlWhispersOnLevelUp", true))
        {
            if (oldLevel == start_level)//玩家升2级
                ChatHandler(player->GetSession()).SendSysMessage("Long long ago,the world is a mass...");//很久以前,世界一片混乱

            if (oldLevel == start_level + 5)//玩家升7级
                ChatHandler(player->GetSession()).SendSysMessage("A little girl appeared...");//一个小女孩出现了

            if (oldLevel == start_level + 6)//玩家升8级
            {
                //ChatHandler(player->GetSession()).SendSysMessage("愿小女神指引你的方向~");//中文没成功
                ChatHandler(player->GetSession()).SendSysMessage("Wish the god of XGirl show you the path~");
                if(player->GetName() == "大女孩")//无尽沉沦的"大女孩"角色升8级,guid值为190
                    ChatHandler(player->GetSession()).SendSysMessage("I heard ur big,where?");//听说你很大,哪大?
            }
                
            if (oldLevel == start_level + 7)//玩家升9级
            {
                if (player->GetGUID().GetCounter() == 190)//无尽沉沦的"大女孩"角色升9级
                {
                    ChatHandler(player->GetSession()).SendSysMessage("The Teacher from AC-WEB QQ group wants to teach u.");
                    //感谢AC群老师提供的方法,老师要教教你
                    player->PlayDirectSound(38372, player);//根据GPT的提示,应该是女妖的声音
                    //更多声音可以访问:https://www.bilibili.com/read/cv17861125
                }
                
            }
            if (oldLevel == start_level + 8 && player->GetGUID().GetCounter() == 190)//无尽沉沦的"大女孩"角色升11级
            {
                player->PlayDirectSound(29546, player);//人人都得吃香蕉
            }
        }
	}
};

void AddSC_XGirlWhispersOnLevelUp()
{
	new XGirlWhispersOnLevelUp();
}
