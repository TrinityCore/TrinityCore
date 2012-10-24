#include "ScriptPCH.h"
#include "Config.h"

class gm_login : public PlayerScript
{
public:
	gm_login() : PlayerScript("gm_login") { }

	void OnLogin(Player* player)
	{
		if (sWorld->getBoolConfig(CONFIG_GMLOGIN_ENABLED))
		{
			if (player->GetSession()->GetSecurity() >= SEC_MODERATOR)
			{
				ChatHandler handler(player);
				uint16 gmlvl = player->GetSession()->GetSecurity();
				std::string gmname = player->GetName();
				uint32 playeronline = sWorld->GetPlayerCount();
				std::string uptime = secsToTimeString(sWorld->GetUptime());

				handler.PSendSysMessage("|cffff0000=================================|r");
				handler.PSendSysMessage("|cff00ff00Привет,|r %s", gmname.c_str());
				handler.PSendSysMessage("|cff00ff00Твой уровень учетной записи:|r %u", gmlvl);
				handler.PSendSysMessage("|cff00ff00Сейчас|r %u |cff00ff00игроков онлайн|r", playeronline);
				handler.PSendSysMessage("|cff00ff00Время работы сервера:|r %s", uptime.c_str());
				handler.PSendSysMessage("|cff00ff00Удачи и приятной игры|r");
				handler.PSendSysMessage("|cffff0000=================================|r");
				return;
			}
		}
	}
};

void AddSC_gm_login()
{
	new gm_login();
}
