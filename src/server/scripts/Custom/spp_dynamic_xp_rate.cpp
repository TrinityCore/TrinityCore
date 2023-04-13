/*
Single Player Project
*/

#include "Config.h"
#include "ScriptMgr.h"

class spp_dynamic_xp_rate : public PlayerScript
{
public:
    spp_dynamic_xp_rate() : PlayerScript("spp_dynamic_xp_rate") { };

    void OnLogin(Player* player, bool /*firstLogin*/)
    {
        if (sConfigMgr->GetBoolDefault("Dynamic.XP.Rate", false))
        {
            if (player->getLevel() >= 1)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.1-9", 1));

            if (player->getLevel() >= 10)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.10-19", 2));

            if (player->getLevel() >= 20)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.20-29", 3));

            if (player->getLevel() >= 30)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.30-39", 4));

            if (player->getLevel() >= 40)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.40-49", 5));

            if (player->getLevel() >= 50)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.50-59", 6));

            if (player->getLevel() >= 60)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.60-69", 7));

            if (player->getLevel() >= 70)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.70-79", 8));

            if (player->getLevel() >= 80)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.80-89", 9));

            if (player->getLevel() >= 90)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.90-99", 10));

            if (player->getLevel() >= 100)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.100-109", 11));

            if (player->getLevel() >= 110)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.110", 1));
        }

        if (!sConfigMgr->GetBoolDefault("Dynamic.XP.Rate", true))
        {
            player->SetPersonnalXpRate(0);
        }

    }

    void OnLevelChanged(Player* player, uint8 /*oldLevel*/)
    {
        if (sConfigMgr->GetBoolDefault("Dynamic.XP.Rate", true))
        {
            if (player->getLevel() >= 1)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.1-9", 1));

            if (player->getLevel() >= 10)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.10-19", 2));

            if (player->getLevel() >= 20)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.20-29", 3));

            if (player->getLevel() >= 30)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.30-39", 4));

            if (player->getLevel() >= 40)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.40-49", 5));

            if (player->getLevel() >= 50)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.50-59", 6));

            if (player->getLevel() >= 60)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.60-69", 7));

            if (player->getLevel() >= 70)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.70-79", 8));

            if (player->getLevel() >= 80)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.80-89", 9));

            if (player->getLevel() >= 90)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.90-99", 10));

            if (player->getLevel() >= 100)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.100-109", 11));

            if (player->getLevel() >= 110)
                player->SetPersonnalXpRate(sConfigMgr->GetIntDefault("Dynamic.XP.Rate.110", 1));
        }
    }
};

void AddSC_dynamic_xp_rate()
{
    new spp_dynamic_xp_rate();
}
