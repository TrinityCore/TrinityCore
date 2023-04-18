////http://www.mangoscn.com/forum.php?mod=viewthread&tid=17873&extra=&page=1
////启发性代码[旧版销售员]
////积分商店
//#include "sc_gossip.h"
//#include "Player.h"
//#include "Chat.h"
//#include "GossipDef.h"
//#include "../../../../shared/Database/DatabaseEnv.h"
//#include "Opcodes.h"
///*******************************************************
//* 积分商店开始
//*******************************************************/
//bool GossipHello_jf_sd_vendors(Player *player, Creature *_Creature)
//{
//        player->ADD_GOSSIP_ITEM( 1, " |CFF0000FF【大芒果系统体验版WWW.MangosCn.COM】|CFF009933 ", 1, GOSSIP_ACTION_INFO_DEF + 10);
//        player->ADD_GOSSIP_ITEM( 4,  " |CFF000066■|CFFFF0000账户查询|CFF000066■ ",            1, GOSSIP_ACTION_INFO_DEF + 1);
//        player->ADD_GOSSIP_ITEM( 1,  " |CFF000066■|CFFFF0000对我训练|CFF000066■ ",            1, GOSSIP_ACTION_INFO_DEF + 2);
//        player->ADD_GOSSIP_ITEM( 1,  " |CFF000066■|CFFFF0000打开商店|CFF000066■ ",            1, GOSSIP_ACTION_INFO_DEF + 3);
//        player->SEND_GOSSIP_MENU(999998,_Creature->GetGUID());
//        return true;
//}
//void SendDefaultMenu_jf_sd_vendors(Player *player, Creature *_Creature, uint32 action)
//{
//        std::ostringstream AccountLevel;
//        std::ostringstream AccountJf;
//        if(player->GetSession()->GetSecurity()==0){
//                AccountLevel<<" |CFF0000FF帐户等级:|CFF000066普通会员 ";       
//        }
//        else        if(player->GetSession()->GetSecurity()==1){
//                AccountLevel<<" |CFF0000FF帐户等级:|CFF000066一级会员 ";       
//        }
//        else        if(player->GetSession()->GetSecurity()==2){
//                AccountLevel<<" |CFF0000FF帐户等级:|CFF000066高级会员 ";       
//        }
//        else        if(player->GetSession()->GetSecurity()>=3){
//                AccountLevel<<" |CFF0000FF帐户等级:|CFF000066游戏管理员 ";       
//        }
//        else{
//                AccountLevel<<" |CFF0000FF帐户等级:|CFF000066非会员 ";       
//        }
//        AccountJf<<" |CFF0000FF剩余积分:|CFF000066"<<player->GetAccountJf(player->GetSession()->GetAccountId());
//        switch(action) {
//                //积分查询
//        case GOSSIP_ACTION_INFO_DEF + 1 :
//                player->ADD_GOSSIP_ITEM( 0, AccountLevel.str().c_str(), 11, GOSSIP_ACTION_INFO_DEF + 1);
//                player->ADD_GOSSIP_ITEM( 0, AccountJf.str().c_str(), 11, GOSSIP_ACTION_INFO_DEF + 2);
//                player->ADD_GOSSIP_ITEM( 7, " |CFFFF0000返回上一级菜单 ",    11, GOSSIP_ACTION_INFO_DEF + 99);
//                player->SEND_GOSSIP_MENU(999998,_Creature->GetGUID());
//                break;
//        case GOSSIP_ACTION_INFO_DEF + 2 ://打开训练师
//                if(player->GetSession()->GetSecurity() >= 1 /*player->GetMyintConfig("VipTrainerShop")*/)
//                {
//                        player->SEND_TRAINERLIST(_Creature->GetGUID());
//                        player->CLOSE_GOSSIP_MENU();
//                }else
//                {
//                        player->GetSession()->SendAreaTriggerMessage(" 对不起你的会员级别不够 ");
//                }
//                break;
//        case GOSSIP_ACTION_INFO_DEF + 3 ://打开商店
//
//                 player->CLOSE_GOSSIP_MENU();
//                if(player->GetSession()->GetSecurity() >= 1 /*player->GetMyintConfig("VipVendorShop")*/)
//                {
//                        player->SEND_VENDORLIST(_Creature->GetGUID());
//                        player->CLOSE_GOSSIP_MENU();
//                }else
//                {
//                        player->GetSession()->SendAreaTriggerMessage(" 对不起你的会员级别不够 ");
//                }
//                break;
//        }
//}
//
//bool GossipSelect_jf_sd_vendors(Player *player, Creature *_Creature, uint32 sender, uint32 action )
//{
//        switch(sender) {
//                // 主选单
//          case 1 :
//                  SendDefaultMenu_jf_sd_vendors(player, _Creature, action);
//                  break;
//          case 11 ://积分查询
//                  switch(action) {
//          case GOSSIP_ACTION_INFO_DEF + 1 :
//                  GossipHello_jf_sd_vendors(player,_Creature);
//                  break;
//          case GOSSIP_ACTION_INFO_DEF + 2 :
//                  GossipHello_jf_sd_vendors(player,_Creature);
//                  break;
//          case GOSSIP_ACTION_INFO_DEF + 99 :
//                  GossipHello_jf_sd_vendors(player,_Creature);
//                  break;
//
//                  }
//                  break;
//        }
//        return true;
//}
///*******************************************************
//* 积分商店结束
//*******************************************************/
///*******************************************************
//* AddSC
//*******************************************************/
//void AddSC_jf_sd_vendors()
//{
//        Script *newscript;
//
//        newscript = new Script;
//        newscript->Name="jf_sd_vendors";
//        newscript->pGossipHello          = &GossipHello_jf_sd_vendors;
//        newscript->pGossipSelect         = &GossipSelect_jf_sd_vendors;
//        m_scripts[nrscripts++] = newscript;
//
//}
