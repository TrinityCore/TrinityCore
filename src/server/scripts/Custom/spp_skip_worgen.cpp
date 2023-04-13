/*
 * Made by ConanHUN for Single Player Project - Ashamane (legion) repack
 */

#include "Config.h"
#include "Player.h"

class spp_skip_worgen : public PlayerScript
{
public:
    spp_skip_worgen() : PlayerScript("spp_skip_worgen") { }

    void OnLogin(Player* p_Player, bool /*firstLogin*/) override
    {
        if (sConfigMgr->GetBoolDefault("Skip.Worgen.Enable", false))//默认不启用
        {
            if (p_Player->GetMapId() == 654)
            {
                p_Player->LearnSpell(72792, true); // Learn Racials
                p_Player->LearnSpell(72857, true); // Learn Two Forms
                p_Player->LearnSpell(95759, true); // Learn Darkflight
                p_Player->TeleportTo(0, -9033.559570f, -45.981701f, 88.419296f, 0.0f);
                ObjectAccessor::SaveAllPlayers();
            }
        }
    }
};

void AddSC_skip_worgen()
{
    new spp_skip_worgen;
}
