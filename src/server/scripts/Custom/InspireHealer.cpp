//天赋关照系统，奶妈要鼓励？来
//来源:https://uiwow.com/thread-11972-1-5.html
//功能:在特点场景下（一般都是5h和raid）boss击杀，对恢复系玩家进行指定物品的额外奖励，

#include "ScriptMgr.h"
#include "Config.h"
#include <Player.h>
#include <World.h>
//
//void OnCreatureKill(Player* player, Creature* boss) override
//{
//    //if (ModuleEnable && boss->getLevel() > Level && boss->IsDungeonBoss())
//    //{
//        //lets get the info we want
//        Map* map = player->GetMap();
//        std::string p_name;
//        std::string tag_colour = "7bbef7";
//        std::string plr_colour = "7bbef7";
//        std::string guild_colour = "00ff00";
//        std::string boss_colour = "ff0000";
//        std::string alive_text = "00ff00";
//        bool Raid = player->GetMap()->IsRaid();
//
//        Map::PlayerList const& playerlist = map->GetPlayers();
//        std::ostringstream stream;
//        uint32 i = 0;
//
//        stream << "[" << boss->GetNameForLocaleIdx(LOCALE_zhCN) << " KO!]" << std::endl;
//
//        for (Map::PlayerList::const_iterator itr = playerlist.begin(); itr != playerlist.end(); ++itr)
//        {
//            if (!itr->GetSource())
//                continue;
//            ++i;
//
//            p_name = itr->GetSource()->GetName();
//
//            if (itr->GetSource()->HasHealSpec() && Spec & FLAG_HEALER)
//            {
//                itr->GetSource()->AddItem((Raid ? RaidToken : DungeonToken), TokenCount);
//                stream << i << ". |CFF" << tag_colour << "|r|cff" << plr_colour << p_name << "|r " << HMessageText << std::endl;
//                continue;
//            }
//
//            if (itr->GetSource()->HasTankSpec() && Spec & FLAG_TANK)
//            {
//                itr->GetSource()->AddItem((Raid ? RaidToken : DungeonToken), TokenCount);
//                stream << i << ". |CFF" << tag_colour << "|r|cff" << plr_colour << p_name << "|r " << TMessageText << std::endl;
//                continue;
//            }
//
//            if (itr->GetSource()->HasCasterSpec() && Spec & FLAG_DPS)
//            {
//                itr->GetSource()->AddItem((Raid ? RaidToken : DungeonToken), TokenCount);
//                stream << i << ". |CFF" << tag_colour << "|r|cff" << plr_colour << p_name << "|r " << DMessageText << std::endl;
//                continue;
//            }
//        }
//
//        sWorld->SendServerMessage(SERVER_MSG_STRING, stream.str().c_str());
//    }
////}
//
//void AddSC_OnCreatureKill()
//{
//    new OnCreatureKill;
//}
