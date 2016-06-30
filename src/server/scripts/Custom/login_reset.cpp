//script made by SymbolixDEV
#include "Config.h"

class login_script : public PlayerScript
{
public:
    login_script() : PlayerScript("login_script") { }

    void OnLogin(Player* player, bool)
    {
		if (sConfigMgr->GetBoolDefault("Reset.on.login", true))
		{
			std::string msg;
			if (player->GetSession()->GetSecurity() != SEC_PLAYER)
				msg = "[GM]:";
			else
				msg = "[PLAYER]:";
			msg += player->GetName()+" has logged in!";
			sWorld->SendGlobalText(msg.c_str(), NULL);
			player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA)); // set max mana
			player->SetPower(POWER_ENERGY, player->GetMaxPower(POWER_ENERGY)); //set max rogue/druid enery go on login!
			player->SetPower(POWER_RAGE, player->GetMaxPower(POWER_RAGE)); //set max warrior rage on login!
			player->SetPower(POWER_RUNIC_POWER, player->GetMaxPower(POWER_RUNIC_POWER));  //set max runic power on Death Knight on login!
			player->SetFullHealth(); // set max health on login on game !
			player->GetSpellHistory()->ResetAllCooldowns(); //reset cooldowns on login!
		}
    }
};

void AddSC_login_script()
{
    new login_script();
}