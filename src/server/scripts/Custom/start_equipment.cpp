//来源:https://github.com/openlcoreteam/OpenLCore/blob/master/src/server/scripts/Custom/start_equipment.cpp
#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"
#include "SharedDefines.h"
#include "World.h"

//字面意思是出生送装备
//可能有问题,暂时停用
//class start_equipment : public playerscript
//{
//
//public:
//    start_equipment() : playerscript("start_equipment") { }
//
//    void onlogin(player* player, bool firstlogin) override
//    {
//        if (sconfigmgr->getbooldefault("start.equipment", true))
//        {
//            if (!firstlogin)
//                return;
//
//            uint32 shoulders = 0, chest = 0, trinkett = 0, weapon = 0, weapon2 = 0, weapon3 = 0, shield = 0, shoulders2 = 0, chest2 = 0, trinkett2 = 0, bag = 0;
//
//            bag = 41600;
//
//            switch (player->getclass())
//            {
//            case class_warrior:
//                 warrior
//                shoulders = 93893;
//                chest = 93892;
//                trinkett = 122361;
//                weapon = 122389;
//                shield = 122391;
//                shoulders2 = 122355;
//                chest2 = 122381;
//                weapon2 = 42943;
//                break;
//            case class_paladin:
//                 paladin
//                shoulders = 69890;
//                chest = 69889;
//                trinkett = 42991;
//                weapon = 69893;
//                shield = 122391;
//                shoulders2 = 42951;
//                chest2 = 48683;
//                trinkett2 = 42992;
//                weapon2 = 42948;
//                break;
//            case class_hunter:
//                 hunter
//                shoulders = 42950;
//                chest = 48677;
//                trinkett = 42991;
//                weapon = 42943;
//                weapon2 = 42946;
//                weapon3 = 44093;
//                break;
//            case class_rogue:
//                 rogue
//                shoulders = 42952;
//                chest = 48689;
//                trinkett = 42991;
//                weapon = 42944;
//                weapon2 = 42944;
//                break;
//            case class_priest:
//                 priest
//                shoulders = 42985;
//                chest = 48691;
//                trinkett = 42992;
//                weapon = 42947;
//                break;
//            case class_death_knight:
//                 death knight
//                shoulders = 42949;
//                chest = 48685;
//                trinkett = 42991;
//                weapon = 42945;
//                break;
//            case class_shaman:
//                 shaman
//                shoulders = 122375;
//                chest = 48683;
//                trinkett = 122362;
//                weapon = 122367;
//                shield = 122392;
//                shoulders2 = 122374;
//                chest2 = 122379;
//                weapon2 = 122385;
//                break;
//            case class_mage:
//                 mage
//                shoulders = 42985;
//                chest = 48691;
//                trinkett = 42992;
//                weapon = 42947;
//                break;
//            case class_warlock:
//                 warlock
//                shoulders = 42985;
//                chest = 48691;
//                trinkett = 42992;
//                weapon = 42947;
//                break;
//            case class_druid:
//                 druid
//                shoulders = 42984;
//                chest = 48687;
//                trinkett = 42992;
//                weapon = 42948;
//                shoulders2 = 42952;
//                chest2 = 48689;
//                trinkett2 = 42991;
//                weapon2 = 48718;
//                break;
//            case class_monk:
//                 monk
//                shoulders = 42984;
//                chest = 48687;
//                trinkett = 42992;
//                weapon = 42947;
//                shoulders2 = 42952;
//                chest2 = 48689;
//                trinkett2 = 42991;
//                weapon2 = 48716;
//            default:
//                return;
//            }
//
//            switch (player->getclass())
//            {
//            case class_warrior:
//                player->additem(shoulders, 1);
//                player->additem(chest, 1);
//                player->additem(trinkett, 2);
//                player->additem(weapon, 1);
//                player->additem(shield, 1);
//                player->additem(shoulders2, 1);
//                player->additem(chest2, 1);
//                player->additem(weapon2, 1);
//                player->additem(bag, 4);
//                break;
//            case class_paladin:
//                player->additem(shoulders, 1);
//                player->additem(chest, 1);
//                player->additem(trinkett, 2);
//                player->additem(weapon, 1);
//                player->additem(shield, 1);
//                player->additem(shoulders2, 1);
//                player->additem(chest2, 1);
//                player->additem(trinkett2, 2);
//                player->additem(weapon2, 1);
//                player->additem(bag, 4);
//                break;
//            case class_hunter:
//                player->additem(shoulders, 1);
//                player->additem(trinkett, 2);
//                player->additem(chest, 1);
//                player->additem(weapon, 1);
//                player->additem(weapon2, 1);
//                player->additem(weapon3, 1);
//                player->additem(bag, 4);
//                break;
//            case class_rogue:
//                player->additem(shoulders, 1);
//                player->additem(trinkett, 2);
//                player->additem(chest, 1);
//                player->additem(weapon, 1);
//                player->additem(weapon2, 1);
//                player->additem(bag, 4);
//                break;
//            case class_druid:
//                player->additem(shoulders, 1);
//                player->additem(trinkett, 2);
//                player->additem(chest, 1);
//                player->additem(weapon, 1);
//                player->additem(shoulders2, 1);
//                player->additem(chest2, 1);
//                player->additem(trinkett2, 2);
//                player->additem(weapon2, 1);
//                player->additem(bag, 4);
//                break;
//            case class_shaman:
//                player->additem(shoulders, 1);
//                player->additem(chest, 1);
//                player->additem(trinkett, 2);
//                player->additem(weapon, 1);
//                player->additem(shield, 1);
//                player->additem(shoulders2, 1);
//                player->additem(chest2, 1);
//                player->additem(weapon2, 2);
//                player->additem(bag, 4);
//                break;
//            case class_monk:
//                player->additem(shoulders, 1);
//                player->additem(trinkett, 2);
//                player->additem(chest, 1);
//                player->additem(weapon, 1);
//                player->additem(shoulders2, 1);
//                player->additem(trinkett2, 2);
//                player->additem(chest2, 1);
//                player->additem(weapon2, 1);
//                player->additem(bag, 4);
//                break;
//            default:
//                player->additem(shoulders, 1);
//                player->additem(trinkett, 2);
//                player->additem(chest, 1);
//                player->additem(weapon, 1);
//                player->additem(bag, 4);
//            }
//        }
//    }
//};
//
//void addsc_start_equipment()
//{
//    new start_equipment();
//}
