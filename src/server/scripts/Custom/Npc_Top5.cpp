////From:https://uiwow.com/forum.php?mod=viewthread&tid=8395&_dsign=ad269cec
//#define NAMEKILLS       "姓名：|cFF000099%s|r  杀敌数：|cFFFF00CC%u|r "
//#define NAMEMONEY       "姓名:|cFF000099%s|r 资产:|cFFFF00CC%u|r金|cFFFF00CC%u|r银|cFFFF00CC%u|r铜"
//#define NAMETOTALTIME   "姓名：|cFF000099%s|r 共计：|cFFFF00CC%u|r天|cFFFF00CC%u|r时|cFFFF00CC%u|r分"
//#define NAMEARENA       "姓名：|cFF000099%s|r  竞技场分数：|cFFFF00CC%u|r分"
//
////仿函数从大到小排序
//class Cmp
//{
//public:
//    bool operator()(const uint32 &x, const uint32 &y)
//    {
//        return x > y;
//    }
//};
//
////击杀、金钱、在线时间，时时刷新
//class Npc_Top5 : public CreatureScript
//{
//public:
//    Npc_Top5() : CreatureScript("Npc_Top5") {}
//
//    bool OnGossipHello(Player *player, Creature *creature)
//    {
//        player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_BALOON, "★★★欢迎使用|cFFCC0000[时时排行榜]|r系统★★★", TRADESKILL_LEVEL_NONE, MERCHANT_OFFSET_GH_ID_TO_ACTION + 119);
//        player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_BALOON, "      |cFF000099该排行榜只公布前 20 名玩家|r", TRADESKILL_LEVEL_NONE, MERCHANT_OFFSET_GH_ID_TO_ACTION + 119);
//        player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_BALOON, "|TInterface\\ICONS\\Ability_Warrior_OffensiveStance.blp:35:35:-20:0|t 击杀排行榜", TRADESKILL_LEVEL_NONE, MERCHANT_OFFSET_GH_ID_TO_ACTION + 10);
//        player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_BALOON, "|TInterface/Icons/INV_Misc_Bag_07:35:35:-20:0|t 富豪排行榜", TRADESKILL_LEVEL_NONE, MERCHANT_OFFSET_GH_ID_TO_ACTION + 11);
//        player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_BALOON, "|TInterface\\icons\\Spell_Shadow_DeathScream:35:35:-20:0|t 肝帝排行榜", TRADESKILL_LEVEL_NONE, MERCHANT_OFFSET_GH_ID_TO_ACTION + 12);
//        player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_BALOON, "|TInterface\\icons\\Achievement_Quests_Completed_08:35:35:-20:0|t 竞技场排行榜", TRADESKILL_LEVEL_NONE, MERCHANT_OFFSET_GH_ID_TO_ACTION + 13);
//        player->SEND_GOSSIP_MENU(1, creature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player *player, Creature *creature, uint32 /*senders*/, uint32 action)
//    {
//        QueryResult topkill = CharacterDatabase.Query("SELECT name, totalKills FROM characters ;");//击杀数
//        QueryResult topmoney = CharacterDatabase.Query("SELECT name, money FROM characters ;");//富豪数
//        QueryResult toptotaltime = CharacterDatabase.Query("SELECT name, totaltime FROM characters ;");//肝帝数
//        QueryResult toparena = CharacterDatabase.Query("SELECT name, rating FROM arena_team ;");//竞技场排序
//        Field * fields = nullptr;//存放数据的容器
//        std::multimap<uint32, std::string, Cmp> multimap;//用于排序用
//        player->PlayerTalkClass->ClearMenus();//关闭上一级菜单
//        int index = 1;//计数器
//        switch (action)
//        {
//        case  MERCHANT_OFFSET_GH_ID_TO_ACTION + 10://击杀榜
//            if (!topkill)
//                return false;
//            player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_GOLD, "★★★欢迎使用|cFFCC0000[击杀排行榜]|r系统★★★", TRADESKILL_LEVEL_NONE, MERCHANT_OFFSET_GH_ID_TO_ACTION + 666);
//            multimap.clear();
//            do
//            {
//                fields = topkill->Fetch();
//                multimap.insert(make_pair(fields[1].GetInt32(), fields[0].GetString()));
//            } while (topkill->NextRow());
//
//            //截取前面10最大的升序显示出来
//            for (std::multimap<uint32, std::string, Cmp>::iterator it = multimap.begin(); it != multimap.end(); it++)
//            {
//                if (index <= 20)
//                {
//                    const uint32 kills = it->first;
//                    const std::string name = it->second;
//                    char namekills[100] = "";
//                    sprintf(namekills, NAMEKILLS, name.c_str(), kills, false);
//                    player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_XSWORDS, namekills, 2, MERCHANT_OFFSET_GH_ID_TO_ACTION + 666);
//                    index++;
//                }
//                else
//                {
//                    break;
//                }
//
//            }
//            player->SEND_GOSSIP_MENU(1, creature->GetGUID());
//            break;
//
//        case  MERCHANT_OFFSET_GH_ID_TO_ACTION + 11://富豪榜
//            if (!topmoney)
//                return false;
//            player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_GOLD, "★★★欢迎使用|cFFCC0000[富豪排行榜]|r系统★★★", TRADESKILL_LEVEL_NONE, MERCHANT_OFFSET_GH_ID_TO_ACTION + 666);
//            //读取所有数据，到map容器，并升序
//            multimap.clear();//清空容器
//            do
//            {
//                fields = topmoney->Fetch();
//                multimap.insert(make_pair(fields[1].GetInt32(), fields[0].GetString()));
//            } while (topmoney->NextRow());
//
//            //截取前面10最大的升序显示出来
//            for (std::multimap<uint32, std::string, Cmp>::iterator it = multimap.begin(); it != multimap.end(); it++)
//            {
//                if (index <= 20)
//                {
//                    const uint32 money = it->first;
//                    const std::string name = it->second;
//                    uint32 gold = (money / 10000);                         //金
//                    uint32 silver = ((money - (gold * 10000)) / 100);        //银
//                    uint32 copper = (money - (gold * 10000 + silver * 100));   //铜
//                    char nameMoney[100] = "";
//                    sprintf(nameMoney, NAMEMONEY, name.c_str(), gold, silver, copper, false);//拼接
//                    player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_GOLD, nameMoney, 2, MERCHANT_OFFSET_GH_ID_TO_ACTION + 666);
//                    index++;
//                }
//                else
//                {
//                    break;
//                }
//            }
//            player->SEND_GOSSIP_MENU(1, creature->GetGUID());
//            break;
//
//        case  MERCHANT_OFFSET_GH_ID_TO_ACTION + 12://肝帝榜
//            if (!toptotaltime)
//                return false;
//            player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_GOLD, "★★★欢迎使用|cFFCC0000[肝帝排行榜]|r系统★★★", TRADESKILL_LEVEL_NONE, MERCHANT_OFFSET_GH_ID_TO_ACTION + 666);
//            //读取所有数据，到map容器，并升序
//            multimap.clear();//清空容器
//            do
//            {
//                fields = toptotaltime->Fetch();
//                multimap.insert(make_pair(fields[1].GetInt32(), fields[0].GetString()));
//            } while (toptotaltime->NextRow());
//
//            //截取前面10最大的升序显示出来
//            for (std::multimap<uint32, std::string, Cmp>::iterator it = multimap.begin(); it != multimap.end(); it++)
//            {
//                if (index <= 20)
//                {
//                    const uint32 playerTime = it->first;
//                    const std::string name = it->second;
//                    uint32 days = (playerTime / (24 * 3600));
//                    uint32 hours = ((playerTime - (days * 24 * 3600)) / 3600);
//                    uint32 mins = ((playerTime - (days * 24 * 3600 + hours * 3600)) / 60);
//                    char nameTotalTime[100] = "";
//                    sprintf(nameTotalTime, NAMETOTALTIME, name.c_str(), days, hours, mins, false);//拼接
//                    player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_WHEEL2, nameTotalTime, 2, MERCHANT_OFFSET_GH_ID_TO_ACTION + 666);
//                    index++;
//                }
//                else
//                {
//                    break;
//                }
//            }
//            player->SEND_GOSSIP_MENU(1, creature->GetGUID());
//            break;
//
//        case  MERCHANT_OFFSET_GH_ID_TO_ACTION + 13://竞技场排行榜
//            if (!toparena)
//                return false;
//            player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_GOLD, "★★★欢迎使用|cFFCC0000[竞技场排行榜]|r系统★★★", TRADESKILL_LEVEL_NONE, MERCHANT_OFFSET_GH_ID_TO_ACTION + 666);
//            //读取所有数据，到map容器，并升序
//            multimap.clear();//清空容器
//            do
//            {
//                fields = toparena->Fetch();
//                multimap.insert(make_pair(fields[1].GetInt32(), fields[0].GetString()));
//            } while (toparena->NextRow());
//
//            //截取前面10最大的升序显示出来
//            for (std::multimap<uint32, std::string, Cmp>::iterator it = multimap.begin(); it != multimap.end(); it++)
//            {
//                if (index <= 20)
//                {
//                    uint32 rating = it->first;
//                    std::string name = it->second;
//                    char nameArena[100] = "";
//                    sprintf(nameArena, NAMEARENA, name.c_str(), rating, false);//拼接
//                    player->ADD_GOSSIP_ITEM(MERCHANT_ICON_GOSSIP_XSWORDS, nameArena, 2, MERCHANT_OFFSET_GH_ID_TO_ACTION + 666);
//                    index++;
//                }
//                else
//                {
//                    break;
//                }
//
//            }
//            player->SEND_GOSSIP_MENU(1, creature->GetGUID());
//            break;
//
//        }
//        return true;
//    }
//
//
//};
