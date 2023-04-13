/*
 * Made by ConanHUN for Single Player Project - Ashamane (legion) repack
 */

#include "Config.h"
#include "Player.h"

class spp_skip_pandaren : public PlayerScript
{
public:
    spp_skip_pandaren() : PlayerScript("spp_skip_pandaren") { }

    void OnLogin(Player* p_Player, bool /*firstLogin*/) override
    {
        if (sConfigMgr->GetBoolDefault("Skip.Pandaren.Enable", false))
        {
            if (p_Player->getRace() == RACE_PANDAREN_NEUTRAL)
            {
                //p_Player->ShowNeutralPlayerFactionSelectUI();
                if (!sConfigMgr->GetBoolDefault("Force.Starting.Level", true))
                {
                    p_Player->SetLevel(5);
                }

                uint32 shoulders = 0, chest = 0, trinkett = 0, weapon = 0, weapon2 = 0, weapon3 = 0, shield = 0, shoulders2 = 0, chest2 = 0, trinkett2 = 0, bag = 0;

                bag = 41600;
                switch (p_Player->getClass())
                {
                case CLASS_WARRIOR:
                    //Warrior
                    shoulders = 93893;
                    chest = 93892;
                    trinkett = 122361;
                    weapon = 122389;
                    shield = 122391;
                    shoulders2 = 122355;
                    chest2 = 122381;
                    weapon2 = 42943;
                    break;

                case CLASS_PALADIN:
                    //Paladin
                    shoulders = 69890;
                    chest = 69889;
                    trinkett = 42991;
                    weapon = 69893;
                    shield = 122391;
                    shoulders2 = 42951;
                    chest2 = 48683;
                    trinkett2 = 42992;
                    weapon2 = 42948;
                    break;

                case CLASS_HUNTER:
                    //Hunter
                    shoulders = 42950;
                    chest = 48677;
                    trinkett = 42991;
                    weapon = 42943;
                    weapon2 = 42946;
                    weapon3 = 44093;
                    break;

                case CLASS_ROGUE:
                    //Rogue
                    shoulders = 42952;
                    chest = 48689;
                    trinkett = 42991;
                    weapon = 42944;
                    weapon2 = 42944;
                    break;

                case CLASS_PRIEST:
                    //Priest
                    shoulders = 42985;
                    chest = 48691;
                    trinkett = 42992;
                    weapon = 42947;
                    break;

                case CLASS_DEATH_KNIGHT:
                    //Death Knight
                    shoulders = 42949;
                    chest = 48685;
                    trinkett = 42991;
                    weapon = 42945;
                    break;

                case CLASS_SHAMAN:
                    //Shaman
                    shoulders = 122375;
                    chest = 48683;
                    trinkett = 122362;
                    weapon = 122367;
                    shield = 122392;
                    shoulders2 = 122374;
                    chest2 = 122379;
                    weapon2 = 122385;
                    break;

                case CLASS_MAGE:
                    //Mage
                    shoulders = 42985;
                    chest = 48691;
                    trinkett = 42992;
                    weapon = 42947;
                    break;

                case CLASS_WARLOCK:
                    //Warlock
                    shoulders = 42985;
                    chest = 48691;
                    trinkett = 42992;
                    weapon = 42947;
                    break;

                case CLASS_DRUID:
                    //Druid
                    shoulders = 42984;
                    chest = 48687;
                    trinkett = 42992;
                    weapon = 42948;
                    shoulders2 = 42952;
                    chest2 = 48689;
                    trinkett2 = 42991;
                    weapon2 = 48718;
                    break;

                case CLASS_MONK:
                    //Monk
                    shoulders = 42984;
                    chest = 48687;
                    trinkett = 42992;
                    weapon = 42947;
                    shoulders2 = 42952;
                    chest2 = 48689;
                    trinkett2 = 42991;
                    weapon2 = 48716;

                default:
                    return;
                }
                switch (p_Player->getClass())
                {
                case CLASS_WARRIOR:
                    p_Player->AddItem(shoulders, 1);
                    p_Player->AddItem(chest, 1);
                    p_Player->AddItem(trinkett, 2);
                    p_Player->AddItem(weapon, 1);
                    p_Player->AddItem(shield, 1);
                    p_Player->AddItem(shoulders2, 1);
                    p_Player->AddItem(chest2, 1);
                    p_Player->AddItem(weapon2, 1);
                    p_Player->AddItem(bag, 4);
                    break;
                case CLASS_PALADIN:
                    p_Player->AddItem(shoulders, 1);
                    p_Player->AddItem(chest, 1);
                    p_Player->AddItem(trinkett, 2);
                    p_Player->AddItem(weapon, 1);
                    p_Player->AddItem(shield, 1);
                    p_Player->AddItem(shoulders2, 1);
                    p_Player->AddItem(chest2, 1);
                    p_Player->AddItem(trinkett2, 2);
                    p_Player->AddItem(weapon2, 1);
                    p_Player->AddItem(bag, 4);
                    break;
                case CLASS_HUNTER:
                    p_Player->AddItem(shoulders, 1);
                    p_Player->AddItem(trinkett, 2);
                    p_Player->AddItem(chest, 1);
                    p_Player->AddItem(weapon, 1);
                    p_Player->AddItem(weapon2, 1);
                    p_Player->AddItem(weapon3, 1);
                    p_Player->AddItem(bag, 4);
                    break;
                case CLASS_ROGUE:
                    p_Player->AddItem(shoulders, 1);
                    p_Player->AddItem(trinkett, 2);
                    p_Player->AddItem(chest, 1);
                    p_Player->AddItem(weapon, 1);
                    p_Player->AddItem(weapon2, 1);
                    p_Player->AddItem(bag, 4);
                    break;
                case CLASS_DRUID:
                    p_Player->AddItem(shoulders, 1);
                    p_Player->AddItem(trinkett, 2);
                    p_Player->AddItem(chest, 1);
                    p_Player->AddItem(weapon, 1);
                    p_Player->AddItem(shoulders2, 1);
                    p_Player->AddItem(chest2, 1);
                    p_Player->AddItem(trinkett2, 2);
                    p_Player->AddItem(weapon2, 1);
                    p_Player->AddItem(bag, 4);
                    break;
                case CLASS_SHAMAN:
                    p_Player->AddItem(shoulders, 1);
                    p_Player->AddItem(chest, 1);
                    p_Player->AddItem(trinkett, 2);
                    p_Player->AddItem(weapon, 1);
                    p_Player->AddItem(shield, 1);
                    p_Player->AddItem(shoulders2, 1);
                    p_Player->AddItem(chest2, 1);
                    p_Player->AddItem(weapon2, 2);
                    p_Player->AddItem(bag, 4);
                    break;
                case CLASS_MONK:
                    p_Player->AddItem(shoulders, 1);
                    p_Player->AddItem(trinkett, 2);
                    p_Player->AddItem(chest, 1);
                    p_Player->AddItem(weapon, 1);
                    p_Player->AddItem(shoulders2, 1);
                    p_Player->AddItem(trinkett2, 2);
                    p_Player->AddItem(chest2, 1);
                    p_Player->AddItem(weapon2, 1);
                    p_Player->AddItem(bag, 4);
                    break;
                default:
                    p_Player->AddItem(shoulders, 1);
                    p_Player->AddItem(trinkett, 2);
                    p_Player->AddItem(chest, 1);
                    p_Player->AddItem(weapon, 1);
                    p_Player->AddItem(bag, 4);
                }
            }
        }
    }
};

void AddSC_skip_pandaren()
{
    new spp_skip_pandaren;
}
