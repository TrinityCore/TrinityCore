#include "Config.h"

class FireWorksOnLevelUp : public PlayerScript
{
public:
	FireWorksOnLevelUp() : PlayerScript("FireWorksOnLevelUp") { }
	void OnLevelChanged(Player * player, uint8 oldLevel)
	{
		if (sConfigMgr->GetBoolDefault("FireWorksOnLevelUp", true))
		{
			if (oldLevel == 79)
				player->CastSpell(player, 11541, true);
		}
	}
};

void AddSC_FireWorksOnLevelUp()
{
	new FireWorksOnLevelUp();
}