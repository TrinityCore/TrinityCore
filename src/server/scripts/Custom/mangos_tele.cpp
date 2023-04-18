////From:http://www.mangoscn.com/forum.php?mod=viewthread&tid=17871&extra=&page=1
////最新7290最稳定的传送宝石精简公开+WLK传送地点
//#include "precompiled.h"
//#include "sc_gossip.h"
//#include "Player.h"
//#include "GossipDef.h"
////#include "../../../../shared/Database/DatabaseEnv.h"
//#include "Opcodes.h"
//
//
//
//bool GossipHello_npc_teleport(Player *player, Creature *_Creature)
//{
//        player->ADD_GOSSIP_ITEM( 1, " |cff8000FF【世界竞技中心】|CFF009933 ",            1, GOSSIP_ACTION_INFO_DEF + 12);
//        player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF【世界主城传送】|CFF009933 ",            1, GOSSIP_ACTION_INFO_DEF + 1);
//        player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF【燃烧远征传送】|CFF009933 ",            1, GOSSIP_ACTION_INFO_DEF + 2);
//        player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF【巫妖王传送点】|CFF009933 ",            1, GOSSIP_ACTION_INFO_DEF + 10);
//        player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF【初级副本传送】|CFF009933 ",            1, GOSSIP_ACTION_INFO_DEF + 3);
//        player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF【中级副本传送】|CFF009933 ",            1, GOSSIP_ACTION_INFO_DEF + 4);
//        player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF【团队副本传送】|CFF009933 ",            1, GOSSIP_ACTION_INFO_DEF + 5);
//        player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF【外域五人副本】|CFF009933 ",            1, GOSSIP_ACTION_INFO_DEF + 6);
//        player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF【外域团队副本】|CFF009933 ",            1, GOSSIP_ACTION_INFO_DEF + 7);
//        player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF【北极副本传送】|CFF009933 ",            1, GOSSIP_ACTION_INFO_DEF + 11);
//        player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF【世界战场传送】|CFF009933 ",            1, GOSSIP_ACTION_INFO_DEF + 8);
//        player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF【附加特殊功能】|CFF009933 ",            1, GOSSIP_ACTION_INFO_DEF + 9);
//        player->SEND_GOSSIP_MENU(999999,_Creature->GetGUID());
//        return true;
//}
//
//void SendDefaultMenu_npc_teleport(Player *player, Creature *_Creature, uint32 action)
//{
//        switch(action) {
//                // 世界竞技中心
//        case GOSSIP_ACTION_INFO_DEF + 12 :
//                player->TeleportTo(0,-13204,276,30,3.5);
//                break;
//                // 世界主城
//        case GOSSIP_ACTION_INFO_DEF + 1 :
//                if(player->getRace() == 1 || player->getRace() == 3 || player->getRace() == 4 || player->getRace() == 7||player->getRace() ==11)
//                {
//                        player->ADD_GOSSIP_ITEM( 2, " |cff8000FF攻打 奥格瑞玛|CFF009933 ", 2, GOSSIP_ACTION_INFO_DEF + 5);
//                        player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF联盟 暴风城|CFF009933 ",   2, GOSSIP_ACTION_INFO_DEF + 1);
//                        player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF联盟 铁炉堡|CFF009933 ",   2, GOSSIP_ACTION_INFO_DEF + 2);
//                        player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF联盟 达纳苏斯|CFF009933 ", 2, GOSSIP_ACTION_INFO_DEF + 3);
//                        player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF联盟 艾克索达|CFF009933 ", 2, GOSSIP_ACTION_INFO_DEF + 4);
//                } else {             // 部落
//                        player->ADD_GOSSIP_ITEM( 2, " |cff8000FF攻打 暴风城|CFF009933 ",   2, GOSSIP_ACTION_INFO_DEF + 1);
//                        player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF部落 奥格瑞玛|CFF009933 ", 2, GOSSIP_ACTION_INFO_DEF + 5);
//                        player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF部落 雷霆崖|CFF009933 ",   2, GOSSIP_ACTION_INFO_DEF + 6);
//                        player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF部落 幽暗城|CFF009933 ",   2, GOSSIP_ACTION_INFO_DEF + 7);
//                        player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF部落 银月城|CFF009933 ",   2, GOSSIP_ACTION_INFO_DEF + 8);
//                }
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF中立 棘齿城|CFF009933 ",       2, GOSSIP_ACTION_INFO_DEF + 9);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF中立 藏宝海湾|CFF009933 ",     2, GOSSIP_ACTION_INFO_DEF + 10);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF中立 冬泉谷|CFF009933 ",       2, GOSSIP_ACTION_INFO_DEF + 11);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF中立 加基森|CFF009933 ",       2, GOSSIP_ACTION_INFO_DEF + 12);
//
//                player->ADD_GOSSIP_ITEM( 7, " |cff8000FF返回上一级菜单|CFF009933 ",    2, GOSSIP_ACTION_INFO_DEF + 99);
//
//                player->SEND_GOSSIP_MENU(999999,_Creature->GetGUID());
//                break;
//                // 外域主城
//        case GOSSIP_ACTION_INFO_DEF + 2 :
//
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF黑暗之门|CFF009933 ",            3, GOSSIP_ACTION_INFO_DEF + 1);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF沙塔斯城|CFF009933 ",            3, GOSSIP_ACTION_INFO_DEF + 6);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF永歌森林|CFF009933 ",            3, GOSSIP_ACTION_INFO_DEF + 2);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF海加尔峰|CFF009933 ",            3, GOSSIP_ACTION_INFO_DEF + 3);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF青草平原|CFF009933 ",            3, GOSSIP_ACTION_INFO_DEF + 4);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF翠叶森林|CFF009933 ",            3, GOSSIP_ACTION_INFO_DEF + 5);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF哈兰|CFF009933 ",                3, GOSSIP_ACTION_INFO_DEF + 7);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF风暴尖塔|CFF009933 ",            3, GOSSIP_ACTION_INFO_DEF + 8);
//
//                player->ADD_GOSSIP_ITEM( 7, " |cff8000FF返回上一级菜单|CFF009933 ",        3, GOSSIP_ACTION_INFO_DEF + 99);
//
//                player->SEND_GOSSIP_MENU(999999,_Creature->GetGUID());
//                break;
//                // 初级副本
//        case GOSSIP_ACTION_INFO_DEF + 3 :
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[14]怒焰裂谷|CFF009933 ",     4, GOSSIP_ACTION_INFO_DEF + 1);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[19]死亡矿井|CFF009933 ",     4, GOSSIP_ACTION_INFO_DEF + 2);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[22]哀嚎洞穴|CFF009933 ",     4, GOSSIP_ACTION_INFO_DEF + 3);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[24]影牙城堡|CFF009933 ",     4, GOSSIP_ACTION_INFO_DEF + 4);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[26]黑暗深渊|CFF009933 ",     4, GOSSIP_ACTION_INFO_DEF + 5);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[27]暴风城监狱|CFF009933 ",   4, GOSSIP_ACTION_INFO_DEF + 6);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[31]剃刀沼泽|CFF009933 ",     4, GOSSIP_ACTION_INFO_DEF + 7);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[33]诺莫瑞根|CFF009933 ",     4, GOSSIP_ACTION_INFO_DEF + 8);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[40]血色修道院|CFF009933 ",   4, GOSSIP_ACTION_INFO_DEF + 9);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[42]剃刀高地|CFF009933 ",     4, GOSSIP_ACTION_INFO_DEF + 10);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[45]奥达曼|CFF009933 ",       4, GOSSIP_ACTION_INFO_DEF + 11);
//
//                player->ADD_GOSSIP_ITEM( 7, " |cff8000FF返回上一级菜单|CFF009933 ",    4, GOSSIP_ACTION_INFO_DEF + 99);
//
//                player->SEND_GOSSIP_MENU(999999,_Creature->GetGUID());
//                break;
//                // 中级副本
//        case GOSSIP_ACTION_INFO_DEF + 4 :
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[46]祖尔法拉克|CFF009933 ",       5, GOSSIP_ACTION_INFO_DEF + 1);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[49]马拉顿|CFF009933 ",           5, GOSSIP_ACTION_INFO_DEF + 2);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[53]失落的神庙|CFF009933 ",       5, GOSSIP_ACTION_INFO_DEF + 3);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[57]黑石深渊|CFF009933 ",         5, GOSSIP_ACTION_INFO_DEF + 4);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[60]通灵学院|CFF009933 ",         5, GOSSIP_ACTION_INFO_DEF + 5);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[60]厄运[北区]|CFF009933 ",     5, GOSSIP_ACTION_INFO_DEF + 6);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[60]厄运[东区]|CFF009933 ",     5, GOSSIP_ACTION_INFO_DEF + 7);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[60]厄运[西区]|CFF009933 ",     5, GOSSIP_ACTION_INFO_DEF + 8);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[60]斯坦索姆|CFF009933 ",         5, GOSSIP_ACTION_INFO_DEF + 9);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[60]黑石塔下|CFF009933 ",           5, GOSSIP_ACTION_INFO_DEF + 10);
//
//                player->ADD_GOSSIP_ITEM( 7, " |cff8000FF返回上一级菜单|CFF009933 ",        5, GOSSIP_ACTION_INFO_DEF + 99);
//
//                player->SEND_GOSSIP_MENU(999999,_Creature->GetGUID());
//                break;
//                // 高级副本
//        case GOSSIP_ACTION_INFO_DEF + 5 :
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]溶火之心|CFF009933 ",         6, GOSSIP_ACTION_INFO_DEF + 1);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]黑石塔|CFF009933 ",           6, GOSSIP_ACTION_INFO_DEF + 2);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]祖尔格拉布|CFF009933 ",       6, GOSSIP_ACTION_INFO_DEF + 3);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]黑翼之巢|CFF009933 ",         6, GOSSIP_ACTION_INFO_DEF + 4);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]安其拉神庙|CFF009933 ",       6, GOSSIP_ACTION_INFO_DEF + 5);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]安其拉废墟|CFF009933 ",       6, GOSSIP_ACTION_INFO_DEF + 6);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]奥妮克希亚的巢穴|CFF009933 ", 6, GOSSIP_ACTION_INFO_DEF + 7);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]纳克萨玛斯|CFF009933 ",       6, GOSSIP_ACTION_INFO_DEF + 8);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]冰龙巢穴|CFF009933 ",         6, GOSSIP_ACTION_INFO_DEF + 9);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]祖阿曼|CFF009933 ",           6, GOSSIP_ACTION_INFO_DEF + 10);
//
//                player->ADD_GOSSIP_ITEM( 7, " |cff8000FF返回上一级菜单|CFF009933 ",        6, GOSSIP_ACTION_INFO_DEF + 99);
//
//                player->SEND_GOSSIP_MENU(999999,_Creature->GetGUID());
//                break;
//                // 外域副本A
//        case GOSSIP_ACTION_INFO_DEF + 6 :
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]暴风城超级监狱|CFF009933 ", 7, GOSSIP_ACTION_INFO_DEF + 1);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]卡拉赞|CFF009933 ",         7, GOSSIP_ACTION_INFO_DEF + 2);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]遗忘之井|CFF009933 ",        7, GOSSIP_ACTION_INFO_DEF + 3);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]鬼魂之地|CFF009933 ",       7, GOSSIP_ACTION_INFO_DEF + 4);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]地狱火城墙|CFF009933 ",     7, GOSSIP_ACTION_INFO_DEF + 5);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]风暴要塞|CFF009933 ",       7, GOSSIP_ACTION_INFO_DEF + 6);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]暗影迷宫|CFF009933 ",         7, GOSSIP_ACTION_INFO_DEF + 7);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]黑暗神殿|CFF009933 ",       7, GOSSIP_ACTION_INFO_DEF + 8);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]赞格沼泽|CFF009933 ",       7, GOSSIP_ACTION_INFO_DEF + 9);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]黑色沼泽|CFF009933 ",       7, GOSSIP_ACTION_INFO_DEF + 10);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF[团]毒蛇神殿|CFF009933 ",       7, GOSSIP_ACTION_INFO_DEF + 11);
//
//                player->ADD_GOSSIP_ITEM( 7, " |cff8000FF返回上一级菜单 ",        7, GOSSIP_ACTION_INFO_DEF + 99);
//
//                player->SEND_GOSSIP_MENU(999999,_Creature->GetGUID());
//                break;
//                // 外域副本B
//        case GOSSIP_ACTION_INFO_DEF + 7 :
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF破碎大厅|CFF009933 ",       8, GOSSIP_ACTION_INFO_DEF + 1);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF鲜血熔炉|CFF009933 ",         8, GOSSIP_ACTION_INFO_DEF + 2);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF生态船|CFF009933 ",       8, GOSSIP_ACTION_INFO_DEF + 3);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF禁魔监狱|CFF009933 ",       8, GOSSIP_ACTION_INFO_DEF + 4);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF能源舰|CFF009933 ",       8, GOSSIP_ACTION_INFO_DEF + 5);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF凤凰大厅|CFF009933 ",       8, GOSSIP_ACTION_INFO_DEF + 6);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF奴隶围栏|CFF009933 ",       8, GOSSIP_ACTION_INFO_DEF + 7);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF蒸汽地窟|CFF009933 ",       8, GOSSIP_ACTION_INFO_DEF + 8);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF幽暗沼泽|CFF009933 ",       8, GOSSIP_ACTION_INFO_DEF + 9);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF格鲁尔的巢穴|CFF009933 ",   8, GOSSIP_ACTION_INFO_DEF + 10);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF玛瑟里顿的巢穴|CFF009933 ", 8, GOSSIP_ACTION_INFO_DEF + 11);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF太阳之井高地|CFF009933 ",   8, GOSSIP_ACTION_INFO_DEF + 12);
//                player->ADD_GOSSIP_ITEM( 0, " |CFF0000FF魔导师平台|CFF009933 ",       8, GOSSIP_ACTION_INFO_DEF + 13);
//
//                player->ADD_GOSSIP_ITEM( 7, " |cff8000FF返回上一级菜单|CFF009933 ",        8, GOSSIP_ACTION_INFO_DEF + 99);
//
//                player->SEND_GOSSIP_MENU(999999,_Creature->GetGUID());
//                break;
//                // 四大战场
//        case GOSSIP_ACTION_INFO_DEF + 8 :
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF奥特兰战场|CFF009933 ",     9, GOSSIP_ACTION_INFO_DEF + 2);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF战歌峡谷|CFF009933 ",       9, GOSSIP_ACTION_INFO_DEF + 3);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF阿拉希战场|CFF009933 ",     9, GOSSIP_ACTION_INFO_DEF + 4);
//
//                player->ADD_GOSSIP_ITEM( 7, " |cff8000FF返回上一级菜单|CFF009933 ", 9, GOSSIP_ACTION_INFO_DEF + 99);
//
//                player->SEND_GOSSIP_MENU(999999,_Creature->GetGUID());
//                break;
//                // 附加功能
//        case GOSSIP_ACTION_INFO_DEF + 9 :
//                player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF版本说明|CFF009933 ",       10, GOSSIP_ACTION_INFO_DEF + 1);
//                player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF个人银行|CFF009933 ",       10, GOSSIP_ACTION_INFO_DEF + 2);
//                player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF装备修复|CFF009933 ",       10, GOSSIP_ACTION_INFO_DEF + 3);
//                player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF开飞行点|CFF009933 ",       10, GOSSIP_ACTION_INFO_DEF + 4);
//                player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF地图全开|CFF009933 ",       10, GOSSIP_ACTION_INFO_DEF + 5);
//
//                player->ADD_GOSSIP_ITEM( 7, " |cff8000FF返回上一级菜单|CFF009933 ", 10, GOSSIP_ACTION_INFO_DEF + 99);
//                player->SEND_GOSSIP_MENU(999999,_Creature->GetGUID());
//                break;
//        case GOSSIP_ACTION_INFO_DEF + 10 :
//        player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF黑暗堡[DK出生地]|CFF009933 ",       11, GOSSIP_ACTION_INFO_DEF + 8);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF肖拉查盆地|CFF009933 ",       11, GOSSIP_ACTION_INFO_DEF + 3);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF北风苔原|CFF009933 ",       11, GOSSIP_ACTION_INFO_DEF + 4);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF龙骨荒野|CFF009933 ",       11, GOSSIP_ACTION_INFO_DEF + 5);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF祖尔德拉克|CFF009933 ",       11, GOSSIP_ACTION_INFO_DEF + 6);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF暴风之颠|CFF009933 ",       11, GOSSIP_ACTION_INFO_DEF + 7);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF寒冰皇冠|CFF009933 ",       11, GOSSIP_ACTION_INFO_DEF + 1);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF尖啸海岸|CFF009933 ",       11, GOSSIP_ACTION_INFO_DEF + 2);
//
//                player->ADD_GOSSIP_ITEM( 7, " |cff8000FF返回上一级菜单|CFF009933 ", 11, GOSSIP_ACTION_INFO_DEF + 99);
//                player->SEND_GOSSIP_MENU(999999,_Creature->GetGUID());
//                break;
//        case GOSSIP_ACTION_INFO_DEF + 11 :
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF北极副本|CFF009933 ",       12, GOSSIP_ACTION_INFO_DEF + 1);
//                player->ADD_GOSSIP_ITEM( 2, " |CFF0000FF蓝龙巢穴|CFF009933 ",       12, GOSSIP_ACTION_INFO_DEF + 2);
//
//                player->ADD_GOSSIP_ITEM( 7, " |cff8000FF返回上一级菜单|CFF009933 ", 12, GOSSIP_ACTION_INFO_DEF + 99);
//                player->SEND_GOSSIP_MENU(999999,_Creature->GetGUID());
//                break;
//        }
//}
//
//bool GossipSelect_npc_teleport(Player *player, Creature *_Creature, uint32 sender, uint32 action )
//{
//        switch(sender) {
//                // 主选单
//          case 1 :
//                  SendDefaultMenu_npc_teleport(player, _Creature, action);
//                  break;
//                  // 各大主城
//          case 2 :
//                  switch(action) {
//                          // 暴风城 统一格式说明：(MapID, X, Y, Z, 0);
//
//          case GOSSIP_ACTION_INFO_DEF + 1 :
//                  player->TeleportTo(0,-8829,626,96,4);
//                  break;
//                  // 铁炉堡
//          case GOSSIP_ACTION_INFO_DEF + 2 :
//
//                  player->TeleportTo(0,-4948,-921,504,5.3);
//
//                  break;
//                  // 达纳苏斯
//          case GOSSIP_ACTION_INFO_DEF + 3 :
//
//                  player->TeleportTo(1,9951,2319,1340,1.6);
//
//                  break;
//                  // 艾克索达
//          case GOSSIP_ACTION_INFO_DEF + 4 :
//
//                  player->TeleportTo(530, -3944, -11620, -136,5);
//
//                  break;
//                  // 奥格瑞玛
//          case GOSSIP_ACTION_INFO_DEF + 5 :
//
//                  player->TeleportTo(1,1541,-4435,13,3);
//
//                  break;
//                  // 雷霆崖
//          case GOSSIP_ACTION_INFO_DEF + 6 :
//
//                  player->TeleportTo(1,-1265,76,129,3);
//
//
//                  break;
//                  // 幽暗城
//          case GOSSIP_ACTION_INFO_DEF + 7 :
//
//                  player->TeleportTo(0,1607,239,-50,1);
//
//                  break;
//                  // 新月城
//          case GOSSIP_ACTION_INFO_DEF + 8 :
//
//                  player->TeleportTo(530, 9687, -7434, 17,1);
//
//                  break;
//                  // 棘齿城
//          case GOSSIP_ACTION_INFO_DEF + 9 :
//
//                  player->TeleportTo(1,-977,-3788,6,0);
//
//                  break;
//                  // 藏宝海湾
//          case GOSSIP_ACTION_INFO_DEF + 10 :
//
//                  player->TeleportTo(0,-14406,425,10,4);
//
//                  break;
//                  // 冬泉谷
//          case GOSSIP_ACTION_INFO_DEF + 11 :
//
//                  player->TeleportTo(1,6706,-4647,723,1);
//
//                  break;
//                  // 加基森
//          case GOSSIP_ACTION_INFO_DEF + 12 :
//
//                  player->TeleportTo(1,-7135,-3787,10,6);
//
//                  break;
//                  // 返回
//          case GOSSIP_ACTION_INFO_DEF + 99 :
//                  GossipHello_npc_teleport(player,_Creature);
//                  break;
//                  }
//                  break;
//                  // 外域主城
//          case 3 :
//
//                  switch(action) {
//                          // 黑暗之门 统一格式说明：(MapID, X, Y, Z, 0);
//          case GOSSIP_ACTION_INFO_DEF + 1 :
//
//                  player->TeleportTo(530,-246.600006,946.000000,84.400002,0);
//
//                  break;
//                  // 永歌森林
//          case GOSSIP_ACTION_INFO_DEF + 2 :
//
//                  player->TeleportTo(530,9336.900391,-7278.399902,13.600000,0);
//
//                  break;
//                  // 海加尔山
//          case GOSSIP_ACTION_INFO_DEF + 3 :
//
//                  player->TeleportTo(534,5070.084473,-1791.984497,1320.995483,0);
//
//                  break;
//                  // 青草平原
//          case GOSSIP_ACTION_INFO_DEF + 4 :
//
//                  player->TeleportTo(169,-2674.500000,-2275.800049,148.092743,0);
//
//                  break;
//                  // 翠叶森林
//          case GOSSIP_ACTION_INFO_DEF + 5 :
//
//                  player->TeleportTo(169,2737.508057,-3318.579590,101.882820,0);
//
//                  break;
//                  // 沙塔斯城
//          case GOSSIP_ACTION_INFO_DEF + 6 :
//
//                  player->TeleportTo(530,-1889,5433,-11,0);
//
//                  break;
//                  // 哈兰
//          case GOSSIP_ACTION_INFO_DEF + 7 :
//
//                  player->TeleportTo(530,-1567,7959,-21,0);
//
//                  break;
//                  // 风暴尖塔
//          case GOSSIP_ACTION_INFO_DEF + 8 :
//
//                  player->TeleportTo(530,4151,3041,339,0);
//
//                  break;
//                  // 返回
//          case GOSSIP_ACTION_INFO_DEF + 99 :
//                  GossipHello_npc_teleport(player,_Creature);
//                  break;
//                  }
//                  break;
//                  // 初级副本
//          case 4:
//
//                  switch(action) {
//                          // [14]怒焰裂谷 统一格式说明：(MapID, X, Y, Z, 0);
//          case GOSSIP_ACTION_INFO_DEF + 1 :
//
//                  player->TeleportTo(389,2.024650,-10.021000,-16.187500,0);
//
//                  break;
//                  // [19]死亡矿井
//          case GOSSIP_ACTION_INFO_DEF + 2 :
//
//                  player->TeleportTo(36,-16.4,-383.07,61.78,0);
//
//                  break;
//                  // [22]哀嚎洞穴
//          case GOSSIP_ACTION_INFO_DEF + 3 :
//
//                  player->TeleportTo(43,-161.841995,133.266998,-73.866203,0);
//
//                  break;
//                  // [24]影牙城堡
//          case GOSSIP_ACTION_INFO_DEF + 4 :
//
//                  player->TeleportTo(33,-228.19,2110.56,76.89,0);
//
//                  break;
//                  // [26]黑暗深渊
//          case GOSSIP_ACTION_INFO_DEF + 5 :
//
//                  player->TeleportTo(48,-150.367004,102.995003,-40.555801,0);
//
//                  break;
//                  // [27]暴风城监狱
//          case GOSSIP_ACTION_INFO_DEF + 6 :
//
//                  player->TeleportTo(34,48.29,0.45,-16.14,0);
//
//                  break;
//                  // [31]剃刀沼泽
//          case GOSSIP_ACTION_INFO_DEF + 7 :
//
//                  player->TeleportTo(47,1943,1544,82,0);
//
//                  break;
//                  // [33]诺莫瑞根
//          case GOSSIP_ACTION_INFO_DEF + 8 :
//
//                  player->TeleportTo(90,-332.562988,-3.445,-152.845993,0);
//
//                  break;
//                  // [40]血色修道院
//          case GOSSIP_ACTION_INFO_DEF + 9 :
//
//                  player->TeleportTo(189,855.903992,1321.939941,18.673000,0);
//
//                  break;
//                  // [42]剃刀高地
//          case GOSSIP_ACTION_INFO_DEF + 10 :
//
//                  player->TeleportTo(129,2593.209961,1109.459961,51.093300,0);
//
//                  break;
//                  // [45]奥达曼
//          case GOSSIP_ACTION_INFO_DEF + 11 :
//
//                  player->TeleportTo(70,-227.529007,45.009800,-46.019600,0);
//
//                  break;
//                  // 返回
//          case GOSSIP_ACTION_INFO_DEF + 99 :
//                  GossipHello_npc_teleport(player,_Creature);
//                  break;
//                  }
//                  break;
//                  // 中级副本
//          case 5:
//
//                  switch(action) {
//                          // [46]祖尔法拉克 统一格式说明：(MapID, X, Y, Z, 0);
//          case GOSSIP_ACTION_INFO_DEF + 1 :
//
//                  player->TeleportTo(209,1213,841,8.9,0);
//
//                  break;
//                  // [49]玛拉顿
//          case GOSSIP_ACTION_INFO_DEF + 2 :
//
//                  player->TeleportTo(349,1012.700012,-459.317993,-43.547100,0);
//
//                  break;
//                  // [53]失落的神庙
//          case GOSSIP_ACTION_INFO_DEF + 3 :
//
//                  player->TeleportTo(109,-313.369995,99.955399,-131.848999,0);
//
//                  break;
//                  // [57]黑石深渊
//          case GOSSIP_ACTION_INFO_DEF + 4 :
//
//                  player->TeleportTo(230,456.928986,34.927700,-69.388100,0);
//
//                  break;
//                  // [60]通灵学院
//          case GOSSIP_ACTION_INFO_DEF + 5 :
//
//                  player->TeleportTo(289,199,126,135,0);
//
//                  break;
//                  // [60]厄运之槌 (北区)
//          case GOSSIP_ACTION_INFO_DEF + 6 :
//
//                  player->TeleportTo(429,255.164001,-17.024200,-2.560600,0);
//
//                  break;
//                  // [60]厄运之槌 (东区)
//          case GOSSIP_ACTION_INFO_DEF + 7 :
//
//                  player->TeleportTo(429,46.24,-155.53,-2.71349,0);
//
//                  break;
//                  // [60]厄运之槌 (西区)
//          case GOSSIP_ACTION_INFO_DEF + 8 :
//
//                  player->TeleportTo(429,32.722599,159.417007,-3.470170,0);
//
//                  break;
//                  // [60]斯坦索姆
//          case GOSSIP_ACTION_INFO_DEF + 9 :
//
//                  player->TeleportTo(329,3392,-3379,143,0);
//
//                  break;
//                  // [60]黑石塔下
//          case GOSSIP_ACTION_INFO_DEF + 10 :
//
//                  player->TeleportTo(229,78.19,-227.63,49.72,0);
//
//                  break;
//                  // 返回
//          case GOSSIP_ACTION_INFO_DEF + 99 :
//                  GossipHello_npc_teleport(player,_Creature);
//                  break;
//                  }
//                  break;
//                  // 团队副本
//          case 6:
//                  switch(action) {
//                          // [团]溶火之心 统一格式说明：(MapID, X, Y, Z, 0);
//          case GOSSIP_ACTION_INFO_DEF + 1 :
//
//                  player->TeleportTo(409,1089.601685,-470.190247,-106.413055,0);
//
//                  break;
//                  // [团]黑石塔上
//          case GOSSIP_ACTION_INFO_DEF + 2 :
//
//                  player->TeleportTo(229,78.339836,-227.793518,49.7103,0);
//
//                  break;
//                  // [团]祖尔格拉布
//          case GOSSIP_ACTION_INFO_DEF + 3 :
//
//                  player->TeleportTo(309,-11916,-1251.469971,92.32,0);
//
//                  break;
//                  // [团]黑翼之巢
//          case GOSSIP_ACTION_INFO_DEF + 4 :
//
//                  player->TeleportTo(469,-7674.470215,-1108.380005,396.649994,0);
//
//                  break;
//                  // [团]安其拉神庙
//          case GOSSIP_ACTION_INFO_DEF + 5 :
//
//                  player->TeleportTo(531,-8212.002930,2034.474854,129.141342,0);
//
//                  break;
//                  // [团]安其拉废墟
//          case GOSSIP_ACTION_INFO_DEF + 6 :
//
//                  player->TeleportTo(509,-8443.475586,1518.648560,31.906958,0);
//
//                  break;
//                  // [团]奥妮克希亚的巢穴
//          case GOSSIP_ACTION_INFO_DEF + 7 :
//
//                  player->TeleportTo(249,30.010290,-58.840508,-5.325367,0);
//
//                  break;
//                  // [团]纳克萨玛斯
//          case GOSSIP_ACTION_INFO_DEF + 8 :
//
//                  player->TeleportTo(533,3005.87,-3435.01,293.882,0);
//
//                  break;
//                  // [团]冰龙巢穴
//          case GOSSIP_ACTION_INFO_DEF + 9 :
//
//                  player->TeleportTo(568,122,1769,45,0,0);
//
//
//                  break;
//                  //祖阿曼
//          case GOSSIP_ACTION_INFO_DEF + 10 :
//
//                  player->TeleportTo(568,122,1769,45,0,0);
//
//                  break;
//                  // 返回
//          case GOSSIP_ACTION_INFO_DEF + 99 :
//                  GossipHello_npc_teleport(player,_Creature);
//                  break;
//                  }
//                  break;
//                  // 外域副本A
//          case 7 :
//
//                  switch(action) {
//                          // 暴风城超级监狱 统一格式说明：(MapID, X, Y, Z, 0);
//          case GOSSIP_ACTION_INFO_DEF + 1 :
//
//                  player->TeleportTo(0,-8644.160156,595.669983,95.699997,0);
//
//                  break;
//                  // 卡拉赞
//          case GOSSIP_ACTION_INFO_DEF + 2 :
//
//                  player->TeleportTo(532, -11107.950195, -2002.060059, 49.889999, 0);
//
//                  break;
//                  // 遗忘之井
//          case GOSSIP_ACTION_INFO_DEF + 3 :
//
//                  player->TeleportTo(0, -11068.07313, -1811.069946, 52.820000, 0);
//
//                  break;
//                  // 鬼魂之地
//          case GOSSIP_ACTION_INFO_DEF + 4 :
//
//                  player->TeleportTo(530, 6851.197266, -7993.672852, 192.292496, 0);
//
//                  break;
//                  // 地狱火堡垒
//          case GOSSIP_ACTION_INFO_DEF + 5 :
//
//                  player->TeleportTo(543, -1355.817261, 1646.834595, 68.447365, 0);
//
//                  break;
//                  // 风暴要塞
//          case GOSSIP_ACTION_INFO_DEF + 6 :
//
//                  player->TeleportTo(530, 3087.556885, 1387.229980, 185.037415,0);
//
//                  break;
//                  // 奥金顿
//          case GOSSIP_ACTION_INFO_DEF + 7 :
//
//                  player->TeleportTo(555, 2.164014, 0.402381, -1.127880, 0);
//
//                  break;
//                  // 黑暗神庙
//          case GOSSIP_ACTION_INFO_DEF + 8 :
//
//                  player->TeleportTo(530, -3562.800049, 247.600006, 42.896927, 0);
//
//                  break;
//                  // 赞格沼泽
//          case GOSSIP_ACTION_INFO_DEF + 9 :
//
//                  player->TeleportTo(530, 919.007629, 6854.861816, -66.432899, 0);
//
//                  break;
//                  // 黑色沼泽
//          case GOSSIP_ACTION_INFO_DEF + 10 :
//
//                  player->TeleportTo(269, -2095.298584, 7125.536133, 34.588596, 0);
//
//                  break;
//                  // 盘牙洞穴
//          case GOSSIP_ACTION_INFO_DEF + 11 :
//
//                  player->TeleportTo(548, 29.142296, -57.074600, -71.733269, 0);
//
//                  break;
//                  // 返回
//          case GOSSIP_ACTION_INFO_DEF + 99 :
//                  GossipHello_npc_teleport(player,_Creature);
//                  break;
//                  }
//                  break;
//
//                  // 外域副本B
//          case 8 :
//
//                  switch(action) {
//                          // 破碎大厅 统一格式说明：(MapID, X, Y, Z, 0);
//          case GOSSIP_ACTION_INFO_DEF + 1 :
//
//                  player->TeleportTo(540, -41.000000, -22.000000, -14.000000, 0);
//
//                  break;
//                  // 血熔炉
//          case GOSSIP_ACTION_INFO_DEF + 2 :
//
//                  player->TeleportTo(542, -3.000000, 11.000000, -45.000000, 0);
//
//                  break;
//                  // 波塔尼卡
//          case GOSSIP_ACTION_INFO_DEF + 3 :
//
//                  player->TeleportTo(553, 40.000000, -28.600000, -1.100000,0);
//
//                  break;
//                  // 亚克崔兹
//          case GOSSIP_ACTION_INFO_DEF + 4 :
//
//                  player->TeleportTo(552, -1.200000, 0.000000, -0.200000, 0);
//
//                  break;
//                  // 麦克那尔
//          case GOSSIP_ACTION_INFO_DEF + 5 :
//
//                  player->TeleportTo(554, -28.900000, 0.700000, -1.800000, 0);
//
//                  break;
//                  // 凤凰大厅
//          case GOSSIP_ACTION_INFO_DEF + 6 :
//
//                  player->TeleportTo(550, -6.800000, -0.900000, -2.400000, 0);
//
//                  break;
//                  // 奴隶监狱
//          case GOSSIP_ACTION_INFO_DEF + 7 :
//
//                  player->TeleportTo(547, 123.146225, -122.687210, -0.446336, 0);
//
//                  break;
//                  // 蒸汽洞窟
//          case GOSSIP_ACTION_INFO_DEF + 8 :
//
//                  player->TeleportTo(545, -7.500000, 5.900000, -4.300000, 0);
//
//                  break;
//                  // 毒牙沼泽
//          case GOSSIP_ACTION_INFO_DEF + 9 :
//
//                  player->TeleportTo(546, 14.913731, -19.914341, -2.755679, 0);
//
//                  break;
//                  // 格鲁尔的巢穴
//          case GOSSIP_ACTION_INFO_DEF + 10 :
//
//                  player->TeleportTo(530, 3543.437012, 5079.009766, 0.952552, 0);
//
//                  break;
//                  // 玛瑟里顿的巢穴
//          case GOSSIP_ACTION_INFO_DEF + 11 :
//
//                  player->TeleportTo(544, 188.414261, 29.327892, 67.934464, 0);
//
//                  break;
//                  // 太阳之井高地
//          case GOSSIP_ACTION_INFO_DEF + 12 :
//
//                  player->TeleportTo(530, 12564.911133, -6775.376465, 15.091839, 3.091994);
//
//                  break;
//                  // 魔导师平台
//          case GOSSIP_ACTION_INFO_DEF + 13 :
//
//                  player->TeleportTo(530, 12887.391602, -7327.203613, 65.490295, 4.389481);
//
//                  break;
//                  // 返回
//          case GOSSIP_ACTION_INFO_DEF + 99 :
//                  GossipHello_npc_teleport(player,_Creature);
//                  break;
//                  }
//                  break;
//                  // 四大战场
//          case 9 :
//
//                  switch(action) {
//                  // 奥特兰战场（部落）
//          case GOSSIP_ACTION_INFO_DEF + 2 :
//
//                  player->TeleportTo(30,390.553680,-283.560547,-42.987301,3.135666);
//
//                  break;
//                  // 战歌峡谷（部落）
//          case GOSSIP_ACTION_INFO_DEF + 3 :
//
//                  player->TeleportTo(489,1123.168823,1462.474976,315.564148,3.464511);
//
//                  break;
//                  // 阿拉希战场（部落）
//          case GOSSIP_ACTION_INFO_DEF + 4 :
//
//                  player->TeleportTo(529,855.156128,828.636108,-57.707348,2.812707);
//
//                  break;
//                  // 返回
//          case GOSSIP_ACTION_INFO_DEF + 99 :
//                  GossipHello_npc_teleport(player,_Creature);
//                  break;
//                  }
//                  break;
//                  // 附加功能
//          case 10 :
//                  switch(action) {
//                          // 版本说明
//          case GOSSIP_ACTION_INFO_DEF + 1 :
//                              player->GetSession()->SendAreaTriggerMessage("解除限制QQ：xxxxxxx");
//                                  player->GetSession()->SendAreaTriggerMessage("服务器版本：巫妖王之怒单机体验版");
//
//                        player->CLOSE_GOSSIP_MENU();
//            break;
//                  // 个人银行
//          case GOSSIP_ACTION_INFO_DEF + 2 :
//                  player->GetSession()->SendShowBank(player->GetGUID());
//                  player->CLOSE_GOSSIP_MENU();
//                  break;
//                  // 装备修复
//          case GOSSIP_ACTION_INFO_DEF + 3 :
//                  player->DurabilityRepairAll(true,0,0);
//                  player->GetSession()->SendAreaTriggerMessage("你的全部装备修理完毕");
//                  player->CLOSE_GOSSIP_MENU();
//                  break;
//                  //开飞行点
//          case GOSSIP_ACTION_INFO_DEF + 4 :
//
//                  for (uint8 i=0; i<8; i++)
//                  { player->SetTaxiCheater(true); }
//                  player->GetSession()->SendAreaTriggerMessage("你的飞行点已全部打开");
//                  player->CLOSE_GOSSIP_MENU();
//
//                  break;
//                  //开地图
//          case GOSSIP_ACTION_INFO_DEF + 5 :
//
//                  for (uint8 i=0; i<64; i++)
//                          player->SetFlag(PLAYER_EXPLORED_ZONES_1+i,0xFFFFFFFF);
//                  player->GetSession()->SendAreaTriggerMessage("你的地图已全开");
//                  player->CLOSE_GOSSIP_MENU();
//                  break;
//
//                  // 返回
//          case GOSSIP_ACTION_INFO_DEF + 99 :
//                  GossipHello_npc_teleport(player,_Creature);
//                  break;
//
//                  }
//                  break;
//          case 11 :
//
//                  switch(action) {
//                  // 肖拉查盆地
//          case GOSSIP_ACTION_INFO_DEF + 3 :
//
//                  player->TeleportTo(571,5562,5738,-64,1);
//
//                  break;
//                  // 北风苔原
//          case GOSSIP_ACTION_INFO_DEF + 4 :
//
//                  player->TeleportTo(571,3272,5279,42,2);
//
//                  break;
//                  // 龙骨荒野
//          case GOSSIP_ACTION_INFO_DEF + 5 :
//
//                  player->TeleportTo(571,3541,275,55,5);
//
//                  break;
//                  // 祖尔德拉克
//          case GOSSIP_ACTION_INFO_DEF + 6 :
//
//                  player->TeleportTo(571,5444,-1213,257,1);
//
//                  break;
//                  // 暴风之颠
//          case GOSSIP_ACTION_INFO_DEF + 7 :
//
//                  player->TeleportTo(571,7881,-1700,1287,0);
//
//                  break;
//                  // 寒冰皇冠
//          case GOSSIP_ACTION_INFO_DEF + 1 :
//
//                  player->TeleportTo(571,5916,2130,650,0.5);
//
//                  break;
//                  // 尖啸海岸
//          case GOSSIP_ACTION_INFO_DEF + 2 :
//
//                  player->TeleportTo(571,1038,-4921,19,0);
//
//                  break;
//                  // 尖啸海岸
//          case GOSSIP_ACTION_INFO_DEF + 8 :
//
//                  player->TeleportTo(609,2370,-5654,446,0.6);
//
//                  break;
//                  // 返回
//          case GOSSIP_ACTION_INFO_DEF + 99 :
//                  GossipHello_npc_teleport(player,_Creature);
//                  break;
//                  }
//                  break;
//                  // 附加功能
//
//                  case 12 :
//
//                  switch(action) {
//                          // 北极副本 统一格式说明：(MapID, X, Y, Z, 0);
//          case GOSSIP_ACTION_INFO_DEF + 1 :
//
//                  player->TeleportTo(574,108,-40,120,1);
//
//                  break;
//                  // 蓝龙巢穴
//          case GOSSIP_ACTION_INFO_DEF + 2 :
//
//                  player->TeleportTo(576,174,-4,-16,1);
//
//                  break;
//
//                  // 返回
//          case GOSSIP_ACTION_INFO_DEF + 99 :
//                  GossipHello_npc_teleport(player,_Creature);
//                  break;
//                  }
//                  break;
//                  // 附加功能
//        }
//        return true;
//}
//
///*******************************************************
//* 传送员结束
//*******************************************************/
//
///*******************************************************
//* AddSC
//*******************************************************/
//
//void AddSC_npc_teleport()
//{
//        Script *newscript;
//
//        newscript = new Script;
//        newscript->Name="npc_teleport";
//        newscript->pGossipHello          = &GossipHello_npc_teleport;
//        newscript->pGossipSelect         = &GossipSelect_npc_teleport;
//        //newscript->GetAI = GetAI_npc_teleport;
//        newscript->RegisterSelf();
//
//}
