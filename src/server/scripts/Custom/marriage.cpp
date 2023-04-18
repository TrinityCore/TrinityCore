//From:http://www.mangoscn.com/forum.php?mod=viewthread&tid=9651&extra=page%3D3
///* Copyright (C) 2007,2008 --- TYRE TELEPORT v1.0 ---
//* This program is free software; you can redistribute it and/or modify
//* it under the terms of the GNU General Public License as published by
//* the Free Software Foundation; either version 2 of the License, or
//* (at your option) any later version.
//*
//* This program is distributed in the hope that it will be useful,
//* but WITHOUT ANY WARRANTY; without even the implied warranty of
//* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//* GNU General Public License for more details.
//*
//* You should have received a copy of the GNU General Public License
//* along with this program; if not, write to the Free Software
//* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//*/
//
////#include "sc_defines.h"
////#include "ConfigEnv.h"
////#include "DatabasePostgre.h"
//
//
//#include "GossipDef.h"
//#include "Player.h"
//#include "Chat.h"
//#include "DatabaseEnv.h"
//#include "WorldSession.h"
//#include "NPCHandler.h"
//#include "Item.h"
//#include "ObjectMgr.h"
//#include "config.h"
//#include "ScriptMgr.h"
//
//bool GossipHello_Teleport(Player* player, Creature* _Creature)
//{
//    player->ADD_GOSSIP_ITEM(7, " |cff8000FF 【男方求爱】 ", 1, 1001, "", 0);
//    player->ADD_GOSSIP_ITEM(7, " |cff8000FF 【女方接受】 ", 1, 1002, "", 0);
//    player->ADD_GOSSIP_ITEM(7, " |cff8000FF 【我要离婚】 ", 1, 1003, "", 0);
//    player->ADD_GOSSIP_ITEM(7, " |cff8000FF 【待定】 ", 1, 1004, "", 0);
//    player->ADD_GOSSIP_ITEM(7, " |cff8000FF 【待定】 ", 1, 1005, "", 0);
//    player->SEND_GOSSIP_MENU(99990, _Creature->GetGUID());
//    return true;
//}
//
//void SendDefaultMenu_Teleport(Player* player, Creature* _Creature, uint32 action)
//{
//    //此处缺少数据库访问新语法
//
//    /*DatabaseMysql sd2db;
//    Config SD2Config;
//    SD2Config.SetSource("mangosd.conf");
//    char const* dbstring = NULL;
//    if (!SD2Config.GetString("CharacterDatabaseInfo", &dbstring))
//        error_log("SD2: Missing CharacterDatabase Info from configuration file");
//    if (!sd2db.Initialize(dbstring))
//        error_log("SD2: Unable to connect to Database");*/
//
//
//    TC_LOG_INFO("marriage", "SD2: Missing CharacterDatabase Info from configuration file");
//
//    QueryResult* result;//获取当前角色姓名，婚否，爱人id
//    QueryResult* result2;//获取所选择对象的姓名，婚否，爱人姓名
//    uint32 mydear;
//    uint32 selectdear;
//    uint32 merryed;
//    std::string myname;
//    std::string selectname;
//
//    result = sd2db.PQuery("select dearid,ismerry,name,dear from characters where guid='%d'", player->GetGUID());
//    mydear = result->Fetch()[0].GetUInt32();//获取我的对象
//    merryed = result->Fetch()[1].GetUInt32();//获取我是否已婚
//    myname = result->Fetch()[2].GetCppString();//获取我的名字
//    selectdear = player->GetSelection();//获取选择对象id
//    //    selectdear = m_session->GetPlayer()->GetSelection()
//    result2 = sd2db.PQuery("select ismerry,name from characters where guid='%d'", selectdear);
//    selectdear = result2->Fetch()[0].GetUInt32();
//    selectname = result2->Fetch()[1].GetCppString();
//    Player* selectchar = objmgr.GetPlayer(selectdear);
//    switch (action) {
//    case 1001:
//        if (player->getGender() == GENDER_FEMALE)
//        {
//            player->GetSession()->SendAreaTriggerMessage("求婚必须由男方提出，记住：女追男，不值钱");
//            break;
//            return;
//        }
//        if (selectchar->getGender() == GENDER_MALE)
//        {
//            player->GetSession()->SendAreaTriggerMessage("暂时不允许同性恋结婚");
//            break;
//            return;
//        }
//        if (merryed = 1)
//        {
//            player->GetSession()->SendAreaTriggerMessage("你已婚，请先离婚");
//            player->CLOSE_GOSSIP_MENU();
//            break;
//            return;
//        }
//        if (selectname != "")
//        {
//            player->GetSession()->SendAreaTriggerMessage("对方已有心上人");
//            player->CLOSE_GOSSIP_MENU();
//            break;
//            return;
//        }
//
//        player->ADD_GOSSIP_ITEM(9, " |cff8000FF 您的求爱对象： " + selectname, 2, 1006, "", 0);
//        player->ADD_GOSSIP_ITEM(7, " |cff8000FF 确      定 ", 2, 1007, "", 0);
//        player->ADD_GOSSIP_ITEM(7, " |cff8000FF 取      消 ", 2, 1008, "", 0);
//        player->SEND_GOSSIP_MENU(99991, _Creature->GetGUID());
//        break;
//    case 1002:
//        if (player->getGender() == GENDER_MALE)
//        {
//            player->GetSession()->SendAreaTriggerMessage("");
//            break;
//            return;
//        }
//        if (merryed = 1)
//        {
//            player->GetSession()->SendAreaTriggerMessage("你已婚，请先离婚");
//            player->CLOSE_GOSSIP_MENU();
//            break;
//            return;
//        }
//
//        //if (result3->Fetch()[2].GetCppString()=="")
//        //{
//        //    player->GetSession()->SendAreaTriggerMessage("貌似还没人象你求婚呢");
//        //    break;
//        //    return;
//        //}
//
//        player->ADD_GOSSIP_ITEM(9, " |cff8000FF 他象你求婚了，心动吗 " + selectname, 3, 1009, "", 0);
//        player->ADD_GOSSIP_ITEM(7, " |cff8000FF 同      意（心动不如行动啊）", 3, 1010, "", 0);
//        player->ADD_GOSSIP_ITEM(7, " |cff8000FF 拒      绝（他还打动不了我）", 3, 1011, "", 0);
//        player->SEND_GOSSIP_MENU(99992, _Creature->GetGUID());
//        break;
//    case 1003:
//        player->ADD_GOSSIP_ITEM(9, " |cff8000FF 考虑清楚了吗？300金的哦 ", 4, 1012, "", 0);
//        player->ADD_GOSSIP_ITEM(7, " |cff8000FF 确      定 ", 4, 1013, "", 0);
//        player->ADD_GOSSIP_ITEM(7, " |cff8000FF 取      消 ", 4, 1014, "", 0);
//        player->SEND_GOSSIP_MENU(99993, _Creature->GetGUID());
//        break;
//    }
//    delete result;
//    delete result2;
//}
//
//
//bool GossipSelect_Teleport(Player* player, Creature* _Creature, uint32 sender, uint32 action)
//{
//    DatabaseMysql sd2db;
//    Config SD2Config;
//    SD2Config.SetSource("mangosd.conf");
//    char const* dbstring = NULL;
//    if (!SD2Config.GetString("CharacterDatabaseInfo", &dbstring))
//        error_log("SD2: Missing CharacterDatabase Info from configuration file");
//    if (!sd2db.Initialize(dbstring))
//        error_log("SD2: Unable to connect to Database");
//
//    QueryResult* result;
//    QueryResult* result2;
//    uint32 mandear;
//    uint32 selectdear;
//    std::string myname;
//    std::string selectname;
//    selectdear = player->GetSelection();
//    result = sd2db.PQuery("select ismerry,name from characters where guid='%d'", selectdear);
//    result2 = sd2db.PQuery("select dearid from characters where guid='%d'", player->GetGUID());
//
//    Player* selectchar = objmgr.GetPlayer(selectdear);
//    switch (sender) {
//    case 1:
//        SendDefaultMenu_Teleport(player, _Creature, action);
//        break;
//    case 2:
//        switch (action) {
//            //case 1006 :              
//            //      break;
//        case 1007:
//            sd2db.PExecute("update characters set dear = '%s',daerid='%u'", player->GetName(), player->GetGUID());
//            GossipHello_Teleport(player, _Creature);
//            break;
//        case 1008:
//            player->CLOSE_GOSSIP_MENU();
//            break;
//            //case 1009 :
//            //    break;
//        case 1010:
//            mandear = result2->Fetch()[0].GetUInt32();
//            if (mandear != player->GetSelection())
//            {
//                player->GetSession()->SendAreaTriggerMessage("你选择的结婚对象不是你的意中人哦");
//                player->CLOSE_GOSSIP_MENU();
//                break;
//            }
//            else
//            {
//                if (selectchar->GetMoney() < 5000000)
//                {
//                    player->GetSession()->SendAreaTriggerMessage("你的意中人结婚彩礼不足哦");
//                }
//                else
//                {
//                    sd2db.PExecute("update characters set ismerry = 1 where guid='%d'", player->GetGUID());
//                    sd2db.PExecute("update characters set ismerry = 1 ,dear = '%s',daerid='%u' where guid='%d'", player->GetName(), player->GetGUID(), selectdear);
//                    selectchar->ModifyMoney(int32(-5000000));
//                    player->GetSession()->SendAreaTriggerMessage("恭喜你们喜结连理");
//                    player->CLOSE_GOSSIP_MENU();
//                    break;
//                }
//            }
//        case 1011:
//            sd2db.PExecute("update characters set dear="" where guid='%d'", player->GetGUID());
//            player->CLOSE_GOSSIP_MENU();
//            break;
//            //case 1012 :
//            //    break;
//        case 1013:
//            if (player->GetMoney() < 5000000)
//            {
//                player->GetSession()->SendAreaTriggerMessage("你的离婚费用不足哦");
//                player->CLOSE_GOSSIP_MENU();
//                break;
//            }
//            if (mandear != player->GetSelection())
//            {
//                player->GetSession()->SendAreaTriggerMessage("你选择的结婚对象不是你的意中人哦");
//                player->CLOSE_GOSSIP_MENU();
//                break;
//            }
//            sd2db.PExecute("update characters set ismerry = 0 ,dear = "",daerid="" where guid='%d'", player->GetGUID());
//            sd2db.PExecute("update characters set ismerry = 0 ,dear = "",daerid="" where guid='%d'", player->GetSelection());
//            player->ModifyMoney(int32(-5000000));
//            player->GetSession()->SendAreaTriggerMessage("你已成功离婚，祝你好运");
//        case 1014:
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        }
//        break;
//    }
//    delete result;
//    delete result2;
//    return true;
//}
//
//void AddSC_teleport()
//{
//    Script* newscript;
//    newscript = new Script;
//    newscript->Name = "marry";
//    newscript->pGossipHello = &GossipHello_Teleport;
//    newscript->pGossipSelect = &GossipSelect_Teleport;
//    m_scripts[nrscripts++] = newscript;
//}
