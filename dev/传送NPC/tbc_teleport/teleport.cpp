#include "sc_gossip.h"
#include "GossipDef.h"
#include "Player.h"

bool GossipHello_teleport(Player *player, Creature *_Creature)
{
    player->ADD_GOSSIP_ITEM( 1, "�������Ǵ��� ",         1, GOSSIP_ACTION_INFO_DEF + 1);
    player->ADD_GOSSIP_ITEM( 2, "������������ ",         1, GOSSIP_ACTION_INFO_DEF + 2);
    player->ADD_GOSSIP_ITEM( 3, "�м��������� ",         1, GOSSIP_ACTION_INFO_DEF + 3);
    player->ADD_GOSSIP_ITEM( 4, "�ŶӸ������� ",         1, GOSSIP_ACTION_INFO_DEF + 4);
    player->ADD_GOSSIP_ITEM( 5, "Ұ��BOSS���� ",         1, GOSSIP_ACTION_INFO_DEF + 5);
    player->ADD_GOSSIP_ITEM( 6, "ս������ ",             1, GOSSIP_ACTION_INFO_DEF + 6);
    player->ADD_GOSSIP_ITEM( 7, "����羰���� ",         1, GOSSIP_ACTION_INFO_DEF + 7);
    player->ADD_GOSSIP_ITEM( 8, "�������⹦�� ",         1, GOSSIP_ACTION_INFO_DEF + 8);
    player->ADD_GOSSIP_ITEM( 9, "�������Ǵ��� ",         1, GOSSIP_ACTION_INFO_DEF + 9);
    player->ADD_GOSSIP_ITEM( 10, "�������˸��� ",        1, GOSSIP_ACTION_INFO_DEF + 10);
    player->ADD_GOSSIP_ITEM( 11, "�����ŶӸ��� ",        1, GOSSIP_ACTION_INFO_DEF + 11);

    player->SEND_GOSSIP_MENU(99990,_Creature->GetGUID());
    return true;
}

void SendDefaultMenu_Teleport(Player *player, Creature *_Creature, uint32 action)
{
    switch(action) {
    // ��������
    case GOSSIP_ACTION_INFO_DEF + 1 :
		if(player->getRace() == 1 || player->getRace() == 3 || player->getRace() == 4 || player->getRace() == 7 || player->getRace() == 11)//�ж��Ƿ�����
		{
            player->ADD_GOSSIP_ITEM( 0, "���� ����� ",   2, GOSSIP_ACTION_INFO_DEF + 1);
            player->ADD_GOSSIP_ITEM( 0, "���� ��¯�� ",   2, GOSSIP_ACTION_INFO_DEF + 2);
            player->ADD_GOSSIP_ITEM( 0, "���� ������˹ ", 2, GOSSIP_ACTION_INFO_DEF + 3);
            player->ADD_GOSSIP_ITEM( 0, "���� ������ ",   2, GOSSIP_ACTION_INFO_DEF + 4);
		}
		else
		{
         // ����
            player->ADD_GOSSIP_ITEM( 0, "���� �¸����� ", 2, GOSSIP_ACTION_INFO_DEF + 5);
            player->ADD_GOSSIP_ITEM( 0, "���� ������ ",   2, GOSSIP_ACTION_INFO_DEF + 6);
            player->ADD_GOSSIP_ITEM( 0, "���� �İ��� ",   2, GOSSIP_ACTION_INFO_DEF + 7);
            player->ADD_GOSSIP_ITEM( 0, "���� ���³� ",   2, GOSSIP_ACTION_INFO_DEF + 8);
		}
        //����
        player->ADD_GOSSIP_ITEM( 0, "���� ���ݳ� ",       2, GOSSIP_ACTION_INFO_DEF + 9);
        player->ADD_GOSSIP_ITEM( 0, "���� �ر����� ",     2, GOSSIP_ACTION_INFO_DEF + 10);
        player->ADD_GOSSIP_ITEM( 0, "���� ��Ȫ�� ",       2, GOSSIP_ACTION_INFO_DEF + 11);
        player->ADD_GOSSIP_ITEM( 0, "���� �ӻ�ɭ ",       2, GOSSIP_ACTION_INFO_DEF + 12);

        player->ADD_GOSSIP_ITEM( 7, "������һ���˵� ",    2, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99991,_Creature->GetGUID());
        break;
    // ��������
    case GOSSIP_ACTION_INFO_DEF + 2 :
        player->ADD_GOSSIP_ITEM( 0, "[14] ŭ���ѹ� ",     3, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "[19] ������� ",     3, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "[22] ������Ѩ ",     3, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "[24] Ӱ���Ǳ� ",     3, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "[26] �ڰ���Ԩ ",     3, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "[27] ����Ǽ��� ",   3, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "[31] �굶���� ",     3, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "[33] ŵĪ��� ",     3, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "[40] Ѫɫ�޵�Ժ ",   3, GOSSIP_ACTION_INFO_DEF + 9);
        player->ADD_GOSSIP_ITEM( 0, "[42] �굶�ߵ� ",     3, GOSSIP_ACTION_INFO_DEF + 10);
        player->ADD_GOSSIP_ITEM( 0, "[45] �´��� ",       3, GOSSIP_ACTION_INFO_DEF + 11);

        player->ADD_GOSSIP_ITEM( 7, "������һ���˵� ",    3, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99992,_Creature->GetGUID());
        break;
    // �м�����
    case GOSSIP_ACTION_INFO_DEF + 3 :
        player->ADD_GOSSIP_ITEM( 0, "[46] ��������� ",       4, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "[49] ������ ",           4, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "[53] ʧ������� ",       4, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "[57] ��ʯ��Ԩ ",         4, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "[60] ͨ��ѧԺ ",         4, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "[60] ����֮� (����) ",  4, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "[60] ����֮� (����) ",  4, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "[60] ����֮� (����) ",  4, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "[60] ˹̹��ķ ",         4, GOSSIP_ACTION_INFO_DEF + 9);
        player->ADD_GOSSIP_ITEM( 0, "[60] ��ʯ�� ",           4, GOSSIP_ACTION_INFO_DEF + 10);

        player->ADD_GOSSIP_ITEM( 7, "������һ���˵� ",        4, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99993,_Creature->GetGUID());
        break;
    // �߼�����
    case GOSSIP_ACTION_INFO_DEF + 4 :
        player->ADD_GOSSIP_ITEM( 0, "[��] �ܻ�֮�� ",         5, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "[��] ��ʯ�� ",           5, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "[��] ��������� ",       5, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "[��] ����֮�� ",         5, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "[��] ���������� ",       5, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "[��] ���������� ",       5, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "[��] ���ݿ�ϣ�ǵĳ�Ѩ ", 5, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "[��] �ɿ�����˹ ",       5, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "[��] ������Ѩ ",         5, GOSSIP_ACTION_INFO_DEF + 9);

        player->ADD_GOSSIP_ITEM( 7, "������һ���˵� ",        5, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99994,_Creature->GetGUID());
        break;
    // Ұ��BOSS
    case GOSSIP_ACTION_INFO_DEF + 5 :
        player->ADD_GOSSIP_ITEM( 0, "ĺɫɭ�� ",       6, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "������ ",         6, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "�ҹ� ",           6, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "������ ",         6, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "����˹ ",         6, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "����֮�� ",       6, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "ˮ���� ",         6, GOSSIP_ACTION_INFO_DEF + 7);

        player->ADD_GOSSIP_ITEM( 7, "������һ���˵� ", 6, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99995,_Creature->GetGUID());
        break;
    // �Ĵ�ս��
    case GOSSIP_ACTION_INFO_DEF + 6 :
        player->ADD_GOSSIP_ITEM( 0, "������ʲ������ ", 7, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "������ս�� ",     7, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "ս��Ͽ�� ",       7, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "����ϣս�� ",     7, GOSSIP_ACTION_INFO_DEF + 4);
		player->ADD_GOSSIP_ITEM( 0, "����֮�� ",       7, GOSSIP_ACTION_INFO_DEF + 5);
		player->ADD_GOSSIP_ITEM( 0, "���������� ",       7, GOSSIP_ACTION_INFO_DEF + 6);

        player->ADD_GOSSIP_ITEM( 7, "������һ���˵� ", 7, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99996,_Creature->GetGUID());
        break;
    // ����羰
    case GOSSIP_ACTION_INFO_DEF + 7 :
        player->ADD_GOSSIP_ITEM( 0, "ʱ��֮Ѩ ",       8, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "˫��ɽ ",         8, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "�ξ�֮�� ",       8, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "��ѩ·�� ",       8, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "���ĺ�̲ ",       8, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "����ɽ ",         8, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "��ͧ�к� ",       8, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "ʯ���ٲ� ",       8, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "���׵��� ",       8, GOSSIP_ACTION_INFO_DEF + 9);

        player->ADD_GOSSIP_ITEM( 7, "������һ���˵� ", 8, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99997,_Creature->GetGUID());
        break;
    // ���ӹ���
    case GOSSIP_ACTION_INFO_DEF + 8 :
        player->ADD_GOSSIP_ITEM( 0, "�������� ",       9, GOSSIP_ACTION_INFO_DEF + 1);

        player->ADD_GOSSIP_ITEM( 7, "������һ���˵� ", 9, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99998,_Creature->GetGUID());
        break;
    // ��������
    case GOSSIP_ACTION_INFO_DEF + 9 :
        player->ADD_GOSSIP_ITEM( 0, "�ڰ�֮�� ",            10, GOSSIP_ACTION_INFO_DEF + 1);
		player->ADD_GOSSIP_ITEM( 0, "52�� ",                 10, GOSSIP_ACTION_INFO_DEF + 2);
		player->ADD_GOSSIP_ITEM( 0, "�޼����� ",             10, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "���Ӷ�ɽ ",            10, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "������ ",              10, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "������ ",              10, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "ɳ��˹�� ",            10, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "�ɸ��� ",              10, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "�籩���� ",            10, GOSSIP_ACTION_INFO_DEF + 9);

        player->ADD_GOSSIP_ITEM( 7, "������һ���˵� ",        10, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(99999,_Creature->GetGUID());
        break;
    // �������˸���
    case GOSSIP_ACTION_INFO_DEF + 10 :
        player->ADD_GOSSIP_ITEM( 0, "��ħ���� ",     11, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "������� ",         11, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "Ѫ��¯ ",   11, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "�������� ",         11, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "�������� ",     11, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "��Դ�� ",       11, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "��Ӱ�Թ� ",         11, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "��̬�� ",       11, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "�޸����� ",       11, GOSSIP_ACTION_INFO_DEF + 9);
        player->ADD_GOSSIP_ITEM( 0, "��ɫ���� ",       11, GOSSIP_ACTION_INFO_DEF + 10);
        player->ADD_GOSSIP_ITEM( 0, "�İ����� ",       11, GOSSIP_ACTION_INFO_DEF + 11);
		player->ADD_GOSSIP_ITEM( 0, "ū��Χ�� ",       11, GOSSIP_ACTION_INFO_DEF + 12);
		player->ADD_GOSSIP_ITEM( 0, "��̩�˴��� ",       11, GOSSIP_ACTION_INFO_DEF + 13);
		player->ADD_GOSSIP_ITEM( 0, "����Ĺ�� ",       11, GOSSIP_ACTION_INFO_DEF + 14);
		player->ADD_GOSSIP_ITEM( 0, "��ϣ��˹���������� ",       11, GOSSIP_ACTION_INFO_DEF + 15);

        player->SEND_GOSSIP_MENU(100000,_Creature->GetGUID());
        break;
    // �����ŶӸ���
    case GOSSIP_ACTION_INFO_DEF + 11 :
        player->ADD_GOSSIP_ITEM( 0, "[��] ������ ",       12, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM( 0, "[��] ̫��֮���ߵ� ",         12, GOSSIP_ACTION_INFO_DEF + 2);
        player->ADD_GOSSIP_ITEM( 0, "[��] �籩Ҫ�� ",       12, GOSSIP_ACTION_INFO_DEF + 3);
        player->ADD_GOSSIP_ITEM( 0, "[��] �ڰ����� ",       12, GOSSIP_ACTION_INFO_DEF + 4);
        player->ADD_GOSSIP_ITEM( 0, "[��] ħ��ʦƽ̨ ",       12, GOSSIP_ACTION_INFO_DEF + 5);
        player->ADD_GOSSIP_ITEM( 0, "[��] �氢�� ",       12, GOSSIP_ACTION_INFO_DEF + 6);
        player->ADD_GOSSIP_ITEM( 0, "[��] ������� ",       12, GOSSIP_ACTION_INFO_DEF + 7);
        player->ADD_GOSSIP_ITEM( 0, "[��] ��³���ĳ�Ѩ ",   12, GOSSIP_ACTION_INFO_DEF + 8);
        player->ADD_GOSSIP_ITEM( 0, "[��] ��ɪ��ٵĳ�Ѩ ", 12, GOSSIP_ACTION_INFO_DEF + 9);
		player->ADD_GOSSIP_ITEM( 0, "[��] ���Ӷ�ɽ ", 12, GOSSIP_ACTION_INFO_DEF + 10);

        player->ADD_GOSSIP_ITEM( 7, "������һ���˵� ",        12, GOSSIP_ACTION_INFO_DEF + 99);

        player->SEND_GOSSIP_MENU(100001,_Creature->GetGUID());
        break;
    }
}

bool GossipSelect_teleport(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch(sender) {
      // ��ѡ��
      case 1 :
        SendDefaultMenu_Teleport(player, _Creature, action);
        break;
      // ��������
      case 2 :
        switch(action) {
          // ����� ͳһ��ʽ˵����(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(0,-9065,434,94,0);
            break;
          // ��¯��
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(0,-5032,-819,495,0);
            break;
          // ������˹
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(1,9961,2055,1329,0);
            break;
          // ������
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(530, -4073.832275, -12030.595703, 1.599608,1.403060);
            break;
          // �¸�����
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(1,1317,-4383,27,0);
            break;
          // ������
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(1,-1391,140,23,0);
            break;
          // �İ���
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(0,1909,235,53,0);
            break;
          // ���³�
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(530, 9301.712891, -7268.829102, 15.252191,0.383920);
            break;
          // ���ݳ�
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(1,-977,-3788,6,0);
            break;
          // �ر�����
          case GOSSIP_ACTION_INFO_DEF + 10 :
            player->TeleportTo(0,-14302,518,9,0);
            break;
          // ��Ȫ��
          case GOSSIP_ACTION_INFO_DEF + 11 :
            player->TeleportTo(1,6723.473145,-4649.303711,720.980835,4.653478);
            break;
          // �ӻ�ɭ
          case GOSSIP_ACTION_INFO_DEF + 12 :
            player->TeleportTo(1,-7177.103516,-3788.077393,8.370177,3.621340);
            break;
          // ����
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // ��������
      case 3:
        switch(action) {
          // [14] ŭ���ѹ� ͳһ��ʽ˵����(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(389,2.024650,-10.021000,-16.187500,0);
            break;
          // [19] ������
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(36,-16.4,-383.07,61.78,0);
            break;
          // [22] ������Ѩ
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(43,-161.841995,133.266998,-73.866203,0);
            break;
          // [24] Ӱ���Ǳ�
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(33,-228.19,2110.56,76.89,0);
            break;
          // [26] �ڰ���Ԩ
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(48,-150.367004,102.995003,-40.555801,0);
            break;
          // [27] ����Ǽ���
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(34,48.29,0.45,-16.14,0);
            break;
          // [31] �굶����
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(47,1943,1544,82,0);
            break;
          // [33] ŵĪ���
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(90,-332.562988,-3.445,-152.845993,0);
            break;
          // [40] Ѫɫ�޵�Ժ
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(189,855.903992,1321.939941,18.673000,0);
            break;
          // [42] �굶�ߵ�
          case GOSSIP_ACTION_INFO_DEF + 10 :
            player->TeleportTo(129,2593.209961,1109.459961,51.093300,0);
            break;
          // [45] �´���
          case GOSSIP_ACTION_INFO_DEF + 11 :
            player->TeleportTo(70,-227.529007,45.009800,-46.019600,0);
            break;
          // ����
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // �м�����
      case 4:
        switch(action) {
          // [46] ��������� ͳһ��ʽ˵����(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(209,1213,841,8.9,0);
            break;
          // [49] ������
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(349,1012.700012,-459.317993,-43.547100,0);
            break;
          // [53] ʧ�������
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(109,-313.369995,99.955399,-131.848999,0);
            break;
          // [57] ��ʯ��Ԩ
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(230,456.928986,34.927700,-69.388100,0);
            break;
          // [60] ͨ��ѧԺ
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(289,199,126,135,0);
            break;
          // [60] ����֮� (����)
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(429,255.164001,-17.024200,-2.560600,0);
            break;
          // [60] ����֮� (����)
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(429,46.24,-155.53,-2.71349,0);
            break;
          // [60] ����֮� (����)
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(429,32.722599,159.417007,-3.470170,0);
            break;
          // [60] ˹̹��ķ
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(329,3392,-3379,143,0);
            break;
          // [60] ��ʯ����
          case GOSSIP_ACTION_INFO_DEF + 10 :
            player->TeleportTo(229,78.19,-227.63,49.72,0);
            break;
          // ����
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // �߼�����
      case 5:
        switch(action) {
          // [��] �ܻ�֮�� ͳһ��ʽ˵����(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(409,1089.601685,-470.190247,-106.413055,0);
            break;
          // [��] ��ʯ����
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(229,78.339836,-227.793518,49.7103,0);
            break;
          // [��] ���������
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(309,-11916,-1251.469971,92.32,0);
            break;
          // [��] ����֮��
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(469,-7674.470215,-1108.380005,396.649994,0);
            break;
          // [��] ����������
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(531,-8212.002930,2034.474854,129.141342,0);
            break;
          // [��] ����������
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(509,-8443.475586,1518.648560,31.906958,0);
            break;
          // [��] ���ݿ�ϣ�ǵĳ�Ѩ
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(249,30.010290,-58.840508,-5.325367,0);
            break;
          // [��] �ɿ�����˹
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(533,3005.87,-3435.01,293.882,0);
            break;
          // [��] ������Ѩ
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(533,3700.35,-5185.92,143.957,4.403038,0);
            break;
          // ����
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // Ұ��BOSS
      case 6:
        switch(action) {
          // ĺɫɭ�� ͳһ��ʽ˵����(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(0,-10526.168945,-434.996796,50.894821,0);
            break;
          // ������
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(0,759.605713,-3893.341309,116.475304,0);
            break;
          // �ҹ�
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(1,3120.289307,-3439.444336,139.566345,1);
            break;
          // ������
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(1,2622.219971,-5977.930176,100.562897,1);
            break;
          // ����˹
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(1,-2741.290039,2009.481323,31.877323,1);
            break;
          // ����֮��
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(0,-12234.000000,-2474.000000,-3.000000,0);
            break;
          //ˮ����
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(1,-6292.463379,1578.029053,0.155348,1);
            break;
          // ����
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // ���ս��
      case 7 :
        switch(action) {
          // ������ʲ������ ͳһ��ʽ˵����(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(0,-13289.353516,118.628067,24.414938,1.047498);
            break;
          // ������ս�������䣩
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(30,390.553680,-283.560547,-42.987301,3.135666);
            break;
          // ս��Ͽ�ȣ����䣩
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(489,1123.168823,1462.474976,315.564148,3.464511);
            break;
          // ����ϣս�������䣩
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(529,855.156128,828.636108,-57.707348,2.812707);
            break;
			//�籩֮�ۣ����䣩
			case GOSSIP_ACTION_INFO_DEF + 5 :
				player->TeleportTo(566,1857.803101,1522.856323,1217.197510,0);
				break;
				//����������
				case GOSSIP_ACTION_INFO_DEF + 6 :
					player->TeleportTo(530,-2116.036621,6569.930664,5.254143,5.032809);
					break;
          // ����
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // ����羰
      case 8 :
        switch(action) {
          // ʱ��֮Ѩ
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(1,-8173.930176,-4737.463867,33.777351,4.772119);
            break;
          // ˫��ɽ
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(1,-3331.353271,2225.728271,30.987701,6.267522);
            break;
          // �ξ�֮��
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(1,-2914.756104,1902.199341,34.741035,5.690404);
            break;
          // ��ѩ·��
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(1,5478.060059,-3730.850098,1593.439941,5.610376);
            break;
          // ���ĺ�̲
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(1,-9851.617188,-3608.474121,8.939731,2.513388);
            break;
          // ����ɽ
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(1,-8562.096680,-2106.056641,8.852538,0.090425);
            break;
          // ��ͧ�к�
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(1,-4014.003418,-3768.186523,42.123295,5.220697);
            break;
          // ʯ���ٲ�
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(0,-9481.493164,-3326.915283,8.864347,0.846896);
            break;
          // ���׵���
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(369, -9.96166,1238.17,-126.102,0);
            break;
          // ����
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // ���ӹ���
      case 9 :
        switch(action) {
          // ��������
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(1,-7201,-3828,8.559,3.68);
            break;
          // ����
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // ��������
      case 10 :
        switch(action) {
          // �ڰ�֮�� ͳһ��ʽ˵����(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(530,-246.600006,946.000000,84.400002,0);
            break;
			//52��
			case GOSSIP_ACTION_INFO_DEF + 2 :
				player->TeleportTo(530,3044.873047,3686.771484,142.496140,0.452384);
				break;
		  //�޼�����
				case GOSSIP_ACTION_INFO_DEF + 3 :
					player->TeleportTo(530,-210.348490,5482.061035,23.031778,6.268262);
					break;
          // ���Ӷ�ɽ
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(534,5070.084473,-1791.984497,1320.995483,0);
            break;
          // ������
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(530,166.386215,2678.982910,85.363243,0.185327);
            break;
          // ������
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(530,-673.018616,2619.374268,86.760292,5.243288);
            break;
          // ɳ��˹��
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(530,-1889,5433,-11,0);
            break;
          // �ɸ���
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(530,-1573.119995,7947.879883,-22.627899,1.002830);
            break;
          // �籩����
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(530,4151,3041,339,0);
            break;
          // ����
          case GOSSIP_ACTION_INFO_DEF + 99 :
            GossipHello_teleport(player,_Creature);
            break;
        }
        break;
      // ���򸱱�A
      case 11 :
        switch(action) {
          // ��ħ���� ͳһ��ʽ˵����(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(552, -1.231650, 0.014346, -0.204293, 0.015712);
            break;
          // �������
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(540, -41.000000, -22.000000, -14.000000, 0);
            break;
          // Ѫ��¯
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(542, -3.000000, 11.000000, -45.000000, 0);
            break;
          // ��������
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(545, -7.500000, 5.900000, -4.300000, 0);
            break;
          // ��������
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(543, -1355.817261, 1646.834595, 68.447365, 0);
            break;
          // ��Դ��
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(554, -23.169426, 0.878597, -1.812820,0.034551);
            break;
          // ��Ӱ�Թ�
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(555, 2.164014, 0.402381, -1.127880, 0);
            break;
          // ��̬��
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(553, 29.156464, -16.256529, -1.123450,2.382123);
            break;
          // �޸�����
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(530, 919.007629, 6854.861816, -66.432899, 0);
            break;
          // ��ɫ����
          case GOSSIP_ACTION_INFO_DEF + 10 :
            player->TeleportTo(269, -2095.298584, 7125.536133, 34.588596, 0);
            break;
          // �İ�����
          case GOSSIP_ACTION_INFO_DEF + 11 :
            player->TeleportTo(546, 14.913731, -19.914341, -2.755679, 0);
            break;
			// ū��Χ��
			case GOSSIP_ACTION_INFO_DEF + 12 :
				player->TeleportTo(547, 123.146225, -122.687210, -0.446336, 0);
				break;
				// ��̩�˴���
				case GOSSIP_ACTION_INFO_DEF + 13 :
					player->TeleportTo(556, -4.681100, -0.093080, 0.006200, 0.035342);
					break;
					// ����Ĺ��
					case GOSSIP_ACTION_INFO_DEF + 14 :
						player->TeleportTo(557, 0.019100, 0.947800, -0.954300, 3.031640);
						break;
				//��ϣ��˹����������
						case GOSSIP_ACTION_INFO_DEF + 15 :
							player->TeleportTo(560, 2391.084229, 1202.122192, 66.855469, 4.320404);
							break;
        }
        break;
      // �����ŶӸ���
      case 12 :
        switch(action) {
          // ������ ͳһ��ʽ˵����(MapID, X, Y, Z, 0);
          case GOSSIP_ACTION_INFO_DEF + 1 :
            player->TeleportTo(532, -11107.950195, -2002.060059, 49.889999, 0);
            break;
          // ̫��֮���ߵ�
          case GOSSIP_ACTION_INFO_DEF + 2 :
            player->TeleportTo(530, 12564.911133, -6775.376465, 15.091839, 3.091994);
            break;
          // �籩Ҫ��
          case GOSSIP_ACTION_INFO_DEF + 3 :
            player->TeleportTo(550, -10.802100, -1.150450, -2.428330, 0.004869);
            break;
          // �ڰ�����
          case GOSSIP_ACTION_INFO_DEF + 4 :
            player->TeleportTo(530, -3644.052490, 316.709167, 35.027168, 3.087411);
            break;
          // ħ��ʦƽ̨
          case GOSSIP_ACTION_INFO_DEF + 5 :
            player->TeleportTo(530, 12887.391602, -7327.203613, 65.490295, 4.389481);
            break;
          // �氢��
          case GOSSIP_ACTION_INFO_DEF + 6 :
            player->TeleportTo(530, 6851.197266, -7993.672852, 192.292496, 0);
            break;
          // �������
          case GOSSIP_ACTION_INFO_DEF + 7 :
            player->TeleportTo(548, 29.142296, -57.074600, -71.733269, 0);
            break;
          // ��³���ĳ�Ѩ
          case GOSSIP_ACTION_INFO_DEF + 8 :
            player->TeleportTo(530, 3543.437012, 5079.009766, 0.952552, 0);
            break;
          // ��ɪ��ٵĳ�Ѩ
          case GOSSIP_ACTION_INFO_DEF + 9 :
            player->TeleportTo(544, 188.414261, 29.327892, 67.934464, 0);
            break;
			//���Ӷ�ɽ
			case GOSSIP_ACTION_INFO_DEF + 10 :
				player->TeleportTo(534, 4978.710449, -1870.543091, 1321.728516, 0.660143);
				break;
          // ����
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

