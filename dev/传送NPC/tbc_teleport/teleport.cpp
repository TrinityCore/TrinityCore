#include "sc_gossip.h"
#include "GossipDef.h"
#include "Player.h"

bool GossipHello_teleport(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 1, "世界主城传送 ",         1, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 2, "初级副本传送 ",         1, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 3, "中级副本传送 ",         1, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 4, "团队副本传送 ",         1, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 5, "野外BOSS传送 ",         1, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 6, "战场传送 ",             1, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 7, "世界风景传送 ",         1, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 8, "附加特殊功能 ",         1, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 9, "外域主城传送 ",         1, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 10, "外域五人副本 ",        1, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 11, "外域团队副本 ",        1, GOSSIP_ACTION_INFO_DEF + 11);

    player->SEND_GOSSIP_MENU(99990,_Creature->GetGUID());
    return true;
}

void SendDefaultMenu_Teleport(Player *player, Creature *_Creature, uint32 action)
{
    switch(action) {
    // 世界主城
    case GOSSIP_ACTION_INFO_DEF + 1 :
		if(player->getRace() == 1 || player->getRace() == 3 || player->getRace() == 4 || player->getRace() == 7 || player->getRace() == 11)//判断是否联盟
		{
            player->ADD_GOSSIP_ITEM( 0, "联盟 暴风城 ",   2, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, "联盟 铁炉堡 ",   2, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, "联盟 达纳苏斯 ", 2, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, "联盟 秘蓝岛 ",   2, GOSSIP_ACTION_INFO_DEF + 4);
		}
		else
		{
         // 部落
            player->ADD_GOSSIP_ITEM( 0, "部落 奥格瑞玛 ", 2, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, "部落 雷霆崖 ",   2, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, "部落 幽暗城 ",   2, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, "部落 银月城 ",   2, GOSSIP_ACTION_INFO_DEF + 8);
		}
        //中立
        player->ADD_GOSSIP_ITEM( 0, "中立 棘齿城 ",       2, GOSSIP_ACTION_INFO_DEF + 9);
        player->ADD_GOSSIP_ITEM( 0, "中立 藏宝海湾 ",     2, GOSSIP_ACTION_INFO_DEF + 10);
        player->ADD_GOSSIP_ITEM( 0, "中立 冬泉谷 ",       2, GOSSIP_ACTION_INFO_DEF + 11);
        player->ADD_GOSSIP_ITEM( 0, "中立 加基森 ",       2, GOSSIP_ACTION_INFO_DEF + 12);

        player->ADD_GOSSIP_ITEM( 7, "返回上一级菜单 ",    2, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99991,_Creature->GetGUID());
        break;
    // 初级副本
    case GOSSIP_ACTION_INFO_DEF + 2 :
        player->ADD_GOSSIP_ITEM( 0, "[14] 怒焰裂谷 ",     3, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "[19] 死亡矿坑 ",     3, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "[22] 哀嚎洞穴 ",     3, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "[24] 影牙城堡 ",     3, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "[26] 黑暗深渊 ",     3, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "[27] 暴风城监狱 ",   3, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "[31] 剃刀沼泽 ",     3, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "[33] 诺莫瑞根 ",     3, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "[40] 血色修道院 ",   3, GOSSIP_ACTION_INFO_DEF + 9);
        player->ADD_GOSSIP_ITEM( 0, "[42] 剃刀高地 ",     3, GOSSIP_ACTION_INFO_DEF + 10);
        player->ADD_GOSSIP_ITEM( 0, "[45] 奥达曼 ",       3, GOSSIP_ACTION_INFO_DEF + 11);

        player->ADD_GOSSIP_ITEM( 7, "返回上一级菜单 ",    3, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99992,_Creature->GetGUID());
        break;
    // 中级副本
    case GOSSIP_ACTION_INFO_DEF + 3 :
        player->ADD_GOSSIP_ITEM( 0, "[46] 祖尔法拉克 ",       4, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "[49] 马拉顿 ",           4, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "[53] 失落的神庙 ",       4, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "[57] 黑石深渊 ",         4, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "[60] 通灵学院 ",         4, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "[60] 厄运之槌 (北区) ",  4, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "[60] 厄运之槌 (东区) ",  4, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "[60] 厄运之槌 (西区) ",  4, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "[60] 斯坦索姆 ",         4, GOSSIP_ACTION_INFO_DEF + 9);
        player->ADD_GOSSIP_ITEM( 0, "[60] 黑石塔 ",           4, GOSSIP_ACTION_INFO_DEF + 10);

        player->ADD_GOSSIP_ITEM( 7, "返回上一级菜单 ",        4, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99993,_Creature->GetGUID());
        break;
    // 高级副本
    case GOSSIP_ACTION_INFO_DEF + 4 :
        player->ADD_GOSSIP_ITEM( 0, "[团] 溶火之心 ",         5, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "[团] 黑石塔 ",           5, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "[团] 祖尔格拉布 ",       5, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "[团] 黑翼之巢 ",         5, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "[团] 安其拉神庙 ",       5, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "[团] 安其拉废墟 ",       5, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "[团] 奥妮克希亚的巢穴 ", 5, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "[团] 纳克萨玛斯 ",       5, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "[团] 冰龙巢穴 ",         5, GOSSIP_ACTION_INFO_DEF + 9);

        player->ADD_GOSSIP_ITEM( 7, "返回上一级菜单 ",        5, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99994,_Creature->GetGUID());
        break;
    // 野外BOSS
    case GOSSIP_ACTION_INFO_DEF + 5 :
        player->ADD_GOSSIP_ITEM( 0, "暮色森林 ",       6, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "辛特兰 ",         6, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "灰谷 ",           6, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "艾萨拉 ",         6, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "菲拉斯 ",         6, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "诅咒之地 ",       6, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "水晶谷 ",         6, GOSSIP_ACTION_INFO_DEF + 7);

        player->ADD_GOSSIP_ITEM( 7, "返回上一级菜单 ", 6, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99995,_Creature->GetGUID());
        break;
    // 四大战场
    case GOSSIP_ACTION_INFO_DEF + 6 :
        player->ADD_GOSSIP_ITEM( 0, "古拉巴什竞技场 ", 7, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "奥特兰战场 ",     7, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "战歌峡谷 ",       7, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "阿拉希战场 ",     7, GOSSIP_ACTION_INFO_DEF + 4);
		player->ADD_GOSSIP_ITEM( 0, "暴风之眼 ",       7, GOSSIP_ACTION_INFO_DEF + 5);
		player->ADD_GOSSIP_ITEM( 0, "试炼竞技场 ",       7, GOSSIP_ACTION_INFO_DEF + 6);

        player->ADD_GOSSIP_ITEM( 7, "返回上一级菜单 ", 7, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99996,_Creature->GetGUID());
        break;
    // 世界风景
    case GOSSIP_ACTION_INFO_DEF + 7 :
        player->ADD_GOSSIP_ITEM( 0, "时光之穴 ",       8, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "双塔山 ",         8, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "梦境之树 ",       8, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "暴雪路障 ",       8, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "天涯海滩 ",       8, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "环形山 ",         8, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "飞艇残骸 ",       8, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "石堡瀑布 ",       8, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "海底地铁 ",       8, GOSSIP_ACTION_INFO_DEF + 9);

        player->ADD_GOSSIP_ITEM( 7, "返回上一级菜单 ", 8, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99997,_Creature->GetGUID());
        break;
    // 附加功能
    case GOSSIP_ACTION_INFO_DEF + 8 :
        player->ADD_GOSSIP_ITEM( 0, "个人银行 ",       9, GOSSIP_ACTION_INFO_DEF + 1);

        player->ADD_GOSSIP_ITEM( 7, "返回上一级菜单 ", 9, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99998,_Creature->GetGUID());
        break;
    // 外域主城
    case GOSSIP_ACTION_INFO_DEF + 9 :
        player->ADD_GOSSIP_ITEM( 0, "黑暗之门 ",            10, GOSSIP_ACTION_INFO_DEF + 1);
		player->ADD_GOSSIP_ITEM( 0, "52区 ",                 10, GOSSIP_ACTION_INFO_DEF + 2);
		player->ADD_GOSSIP_ITEM( 0, "赞加沼泽 ",             10, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "海加尔山 ",            10, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "萨尔玛 ",              10, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "荣誉堡 ",              10, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "沙塔斯城 ",            10, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "纳格兰 ",              10, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "风暴尖塔 ",            10, GOSSIP_ACTION_INFO_DEF + 9);

        player->ADD_GOSSIP_ITEM( 7, "返回上一级菜单 ",        10, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99999,_Creature->GetGUID());
        break;
    // 外域五人副本
    case GOSSIP_ACTION_INFO_DEF + 10 :
        player->ADD_GOSSIP_ITEM( 0, "禁魔监狱 ",     11, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "破碎大厅 ",         11, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "血熔炉 ",   11, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "蒸汽洞窟 ",         11, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "地狱火堡垒 ",     11, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "能源舰 ",       11, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "暗影迷宫 ",         11, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "生态船 ",       11, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "赞格沼泽 ",       11, GOSSIP_ACTION_INFO_DEF + 9);
        player->ADD_GOSSIP_ITEM( 0, "黑色沼泽 ",       11, GOSSIP_ACTION_INFO_DEF + 10);
        player->ADD_GOSSIP_ITEM( 0, "幽暗沼泽 ",       11, GOSSIP_ACTION_INFO_DEF + 11);
		player->ADD_GOSSIP_ITEM( 0, "奴隶围栏 ",       11, GOSSIP_ACTION_INFO_DEF + 12);
		player->ADD_GOSSIP_ITEM( 0, "塞泰克大厅 ",       11, GOSSIP_ACTION_INFO_DEF + 13);
		player->ADD_GOSSIP_ITEM( 0, "法力墓地 ",       11, GOSSIP_ACTION_INFO_DEF + 14);
		player->ADD_GOSSIP_ITEM( 0, "旧希尔斯布莱德丘陵 ",       11, GOSSIP_ACTION_INFO_DEF + 15);

        player->SEND_GOSSIP_MENU(100000,_Creature->GetGUID());
        break;
    // 外域团队副本
    case GOSSIP_ACTION_INFO_DEF + 11 :
        player->ADD_GOSSIP_ITEM( 0, "[团] 卡拉赞 ",       12, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "[团] 太阳之井高地 ",         12, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "[团] 风暴要塞 ",       12, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "[团] 黑暗神庙 ",       12, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "[团] 魔导师平台 ",       12, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "[团] 祖阿曼 ",       12, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "[团] 毒蛇神殿 ",       12, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "[团] 格鲁尔的巢穴 ",   12, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "[团] 玛瑟里顿的巢穴 ", 12, GOSSIP_ACTION_INFO_DEF + 9);
		player->ADD_GOSSIP_ITEM( 0, "[团] 海加尔山 ", 12, GOSSIP_ACTION_INFO_DEF + 10);

        player->ADD_GOSSIP_ITEM( 7, "返回上一级菜单 ",        12, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(100001,_Creature->GetGUID());
        break;
    }
}

bool GossipSelect_teleport(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch(sender) {
      // 主选单
      case 1 :
        SendDefaultMenu_Teleport(player, _Creature, action);
        break;
      // 各大主城
      case 2 :
        switch(action) {
          // 暴风城 统一格式说明：(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(0,-9065,434,94,0);
            break;
          // 铁炉堡
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(0,-5032,-819,495,0);
            break;
          // 达纳苏斯
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(1,9961,2055,1329,0);
            break;
          // 秘蓝岛
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(530, -4073.832275, -12030.595703, 1.599608,1.403060);
            break;
          // 奥格瑞玛
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(1,1317,-4383,27,0);
            break;
          // 雷霆崖
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(1,-1391,140,23,0);
            break;
          // 幽暗城
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(0,1909,235,53,0);
            break;
          // 新月城
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(530, 9301.712891, -7268.829102, 15.252191,0.383920);
            break;
          // 棘齿城
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(1,-977,-3788,6,0);
            break;
          // 藏宝海湾
          case GOSSIP_ACTION_INFO_DEF + 10 :
            player->TeleportTo(0,-14302,518,9,0);
            break;
          // 冬泉谷
          case GOSSIP_ACTION_INFO_DEF + 11 :
            player->TeleportTo(1,6723.473145,-4649.303711,720.980835,4.653478);
            break;
          // 加基森
          case GOSSIP_ACTION_INFO_DEF + 12 :
            player->TeleportTo(1,-7177.103516,-3788.077393,8.370177,3.621340);
            break;
          // 返回
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // 初级副本
      case 3:
        switch(action) {
          // [14] 怒焰裂谷 统一格式说明：(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(389,2.024650,-10.021000,-16.187500,0);
            break;
          // [19] 死亡矿井
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(36,-16.4,-383.07,61.78,0);
            break;
          // [22] 哀嚎洞穴
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(43,-161.841995,133.266998,-73.866203,0);
            break;
          // [24] 影牙城堡
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(33,-228.19,2110.56,76.89,0);
            break;
          // [26] 黑暗深渊
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(48,-150.367004,102.995003,-40.555801,0);
            break;
          // [27] 暴风城监狱
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(34,48.29,0.45,-16.14,0);
            break;
          // [31] 剃刀沼泽
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(47,1943,1544,82,0);
            break;
          // [33] 诺莫瑞根
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(90,-332.562988,-3.445,-152.845993,0);
            break;
          // [40] 血色修道院
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(189,855.903992,1321.939941,18.673000,0);
            break;
          // [42] 剃刀高地
          case GOSSIP_ACTION_INFO_DEF + 10 :
            player->TeleportTo(129,2593.209961,1109.459961,51.093300,0);
            break;
          // [45] 奥达曼
          case GOSSIP_ACTION_INFO_DEF + 11 :
            player->TeleportTo(70,-227.529007,45.009800,-46.019600,0);
            break;
          // 返回
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // 中级副本
      case 4:
        switch(action) {
          // [46] 祖尔法拉克 统一格式说明：(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(209,1213,841,8.9,0);
            break;
          // [49] 玛拉顿
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(349,1012.700012,-459.317993,-43.547100,0);
            break;
          // [53] 失落的神庙
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(109,-313.369995,99.955399,-131.848999,0);
            break;
          // [57] 黑石深渊
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(230,456.928986,34.927700,-69.388100,0);
            break;
          // [60] 通灵学院
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(289,199,126,135,0);
            break;
          // [60] 厄运之槌 (北区)
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(429,255.164001,-17.024200,-2.560600,0);
            break;
          // [60] 厄运之槌 (东区)
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(429,46.24,-155.53,-2.71349,0);
            break;
          // [60] 厄运之槌 (西区)
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(429,32.722599,159.417007,-3.470170,0);
            break;
          // [60] 斯坦索姆
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(329,3392,-3379,143,0);
            break;
          // [60] 黑石塔下
          case GOSSIP_ACTION_INFO_DEF + 10 :
            player->TeleportTo(229,78.19,-227.63,49.72,0);
            break;
          // 返回
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // 高级副本
      case 5:
        switch(action) {
          // [团] 溶火之心 统一格式说明：(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(409,1089.601685,-470.190247,-106.413055,0);
            break;
          // [团] 黑石塔上
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(229,78.339836,-227.793518,49.7103,0);
            break;
          // [团] 祖尔格拉布
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(309,-11916,-1251.469971,92.32,0);
            break;
          // [团] 黑翼之巢
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(469,-7674.470215,-1108.380005,396.649994,0);
            break;
          // [团] 安其拉神庙
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(531,-8212.002930,2034.474854,129.141342,0);
            break;
          // [团] 安其拉废墟
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(509,-8443.475586,1518.648560,31.906958,0);
            break;
          // [团] 奥妮克希亚的巢穴
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(249,30.010290,-58.840508,-5.325367,0);
            break;
          // [团] 纳克萨玛斯
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(533,3005.87,-3435.01,293.882,0);
            break;
          // [团] 冰龙巢穴
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(533,3700.35,-5185.92,143.957,4.403038,0);
            break;
          // 返回
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // 野外BOSS
      case 6:
        switch(action) {
          // 暮色森林 统一格式说明：(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(0,-10526.168945,-434.996796,50.894821,0);
            break;
          // 辛特兰
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(0,759.605713,-3893.341309,116.475304,0);
            break;
          // 灰谷
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(1,3120.289307,-3439.444336,139.566345,1);
            break;
          // 艾萨拉
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(1,2622.219971,-5977.930176,100.562897,1);
            break;
          // 菲拉斯
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(1,-2741.290039,2009.481323,31.877323,1);
            break;
          // 诅咒之地
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(0,-12234.000000,-2474.000000,-3.000000,0);
            break;
          //水晶谷
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(1,-6292.463379,1578.029053,0.155348,1);
            break;
          // 返回
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // 五大战场
      case 7 :
        switch(action) {
          // 古拉巴什竞技场 统一格式说明：(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(0,-13289.353516,118.628067,24.414938,1.047498);
            break;
          // 奥特兰战场（部落）
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(30,390.553680,-283.560547,-42.987301,3.135666);
            break;
          // 战歌峡谷（部落）
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(489,1123.168823,1462.474976,315.564148,3.464511);
            break;
          // 阿拉希战场（部落）
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(529,855.156128,828.636108,-57.707348,2.812707);
            break;
			//风暴之眼（部落）
			case GOSSIP_ACTION_INFO_DEF + 5 :
				player->TeleportTo(566,1857.803101,1522.856323,1217.197510,0);
				break;
				//试炼竞技场
				case GOSSIP_ACTION_INFO_DEF + 6 :
					player->TeleportTo(530,-2116.036621,6569.930664,5.254143,5.032809);
					break;
          // 返回
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // 世界风景
      case 8 :
        switch(action) {
          // 时光之穴
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(1,-8173.930176,-4737.463867,33.777351,4.772119);
            break;
          // 双塔山
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(1,-3331.353271,2225.728271,30.987701,6.267522);
            break;
          // 梦境之树
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(1,-2914.756104,1902.199341,34.741035,5.690404);
            break;
          // 暴雪路障
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(1,5478.060059,-3730.850098,1593.439941,5.610376);
            break;
          // 天涯海滩
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(1,-9851.617188,-3608.474121,8.939731,2.513388);
            break;
          // 环形山
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(1,-8562.096680,-2106.056641,8.852538,0.090425);
            break;
          // 飞艇残骸
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(1,-4014.003418,-3768.186523,42.123295,5.220697);
            break;
          // 石堡瀑布
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(0,-9481.493164,-3326.915283,8.864347,0.846896);
            break;
          // 海底地铁
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(369, -9.96166,1238.17,-126.102,0);
            break;
          // 返回
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // 附加功能
      case 9 :
        switch(action) {
          // 个人银行
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(1,-7201,-3828,8.559,3.68);
            break;
          // 返回
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // 外域主城
      case 10 :
        switch(action) {
          // 黑暗之门 统一格式说明：(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(530,-246.600006,946.000000,84.400002,0);
            break;
			//52区
			case GOSSIP_ACTION_INFO_DEF + 2 :
				player->TeleportTo(530,3044.873047,3686.771484,142.496140,0.452384);
				break;
		  //赞加沼泽
				case GOSSIP_ACTION_INFO_DEF + 3 :
					player->TeleportTo(530,-210.348490,5482.061035,23.031778,6.268262);
					break;
          // 海加尔山
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(534,5070.084473,-1791.984497,1320.995483,0);
            break;
          // 萨尔玛
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(530,166.386215,2678.982910,85.363243,0.185327);
            break;
          // 荣誉堡
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(530,-673.018616,2619.374268,86.760292,5.243288);
            break;
          // 沙塔斯城
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(530,-1889,5433,-11,0);
            break;
          // 纳格兰
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(530,-1573.119995,7947.879883,-22.627899,1.002830);
            break;
          // 风暴尖塔
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(530,4151,3041,339,0);
            break;
          // 返回
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // 外域副本A
      case 11 :
        switch(action) {
          // 禁魔监狱 统一格式说明：(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(552, -1.231650, 0.014346, -0.204293, 0.015712);
            break;
          // 破碎大厅
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(540, -41.000000, -22.000000, -14.000000, 0);
            break;
          // 血熔炉
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(542, -3.000000, 11.000000, -45.000000, 0);
            break;
          // 蒸汽洞窟
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(545, -7.500000, 5.900000, -4.300000, 0);
            break;
          // 地狱火堡垒
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(543, -1355.817261, 1646.834595, 68.447365, 0);
            break;
          // 能源舰
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(554, -23.169426, 0.878597, -1.812820,0.034551);
            break;
          // 暗影迷宫
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(555, 2.164014, 0.402381, -1.127880, 0);
            break;
          // 生态船
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(553, 29.156464, -16.256529, -1.123450,2.382123);
            break;
          // 赞格沼泽
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(530, 919.007629, 6854.861816, -66.432899, 0);
            break;
          // 黑色沼泽
          case GOSSIP_ACTION_INFO_DEF + 10 :
            player->TeleportTo(269, -2095.298584, 7125.536133, 34.588596, 0);
            break;
          // 幽暗沼泽
          case GOSSIP_ACTION_INFO_DEF + 11 :
            player->TeleportTo(546, 14.913731, -19.914341, -2.755679, 0);
            break;
			// 奴隶围栏
			case GOSSIP_ACTION_INFO_DEF + 12 :
				player->TeleportTo(547, 123.146225, -122.687210, -0.446336, 0);
				break;
				// 塞泰克大厅
				case GOSSIP_ACTION_INFO_DEF + 13 :
					player->TeleportTo(556, -4.681100, -0.093080, 0.006200, 0.035342);
					break;
					// 法力墓地
					case GOSSIP_ACTION_INFO_DEF + 14 :
						player->TeleportTo(557, 0.019100, 0.947800, -0.954300, 3.031640);
						break;
				//旧希尔斯布莱德丘陵
						case GOSSIP_ACTION_INFO_DEF + 15 :
							player->TeleportTo(560, 2391.084229, 1202.122192, 66.855469, 4.320404);
							break;
        }
        break;
      // 外域团队副本
      case 12 :
        switch(action) {
          // 卡拉赞 统一格式说明：(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(532, -11107.950195, -2002.060059, 49.889999, 0);
            break;
          // 太阳之井高地
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(530, 12564.911133, -6775.376465, 15.091839, 3.091994);
            break;
          // 风暴要塞
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(550, -10.802100, -1.150450, -2.428330, 0.004869);
            break;
          // 黑暗神庙
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(530, -3644.052490, 316.709167, 35.027168, 3.087411);
            break;
          // 魔导师平台
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(530, 12887.391602, -7327.203613, 65.490295, 4.389481);
            break;
          // 祖阿曼
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(530, 6851.197266, -7993.672852, 192.292496, 0);
            break;
          // 毒蛇神殿
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(548, 29.142296, -57.074600, -71.733269, 0);
            break;
          // 格鲁尔的巢穴
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(530, 3543.437012, 5079.009766, 0.952552, 0);
            break;
          // 玛瑟里顿的巢穴
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(544, 188.414261, 29.327892, 67.934464, 0);
            break;
			//海加尔山
			case GOSSIP_ACTION_INFO_DEF + 10 :
				player->TeleportTo(534, 4978.710449, -1870.543091, 1321.728516, 0.660143);
				break;
          // 返回
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
    }
    return true;
}

void AddSC_teleport()
{
        Script *newscript;

        newscript = new Script;
    newscript->Name="teleport";
    newscript->pGossipHello          = &GossipHello_teleport;
    newscript->pGossipSelect         = &GossipSelect_teleport;
    m_scripts[nrscripts++] = newscript;
}

