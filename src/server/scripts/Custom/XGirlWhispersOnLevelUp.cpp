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
			if (oldLevel == start_level)//升2级
                ChatHandler(player->GetSession()).SendSysMessage("Long long ago,the world is a mass...");
            if (oldLevel == start_level+5)//升7级
                ChatHandler(player->GetSession()).SendSysMessage("A little girl appeared...");
		}
	}
};

void AddSC_XGirlWhispersOnLevelUp()
{
	new XGirlWhispersOnLevelUp();
}
