////From:http://www.mangoscn.com/forum.php?mod=viewthread&tid=44908&extra=page%3D4
////在线改名系统
//#include "precompiled.h"
//#include <cstring>
//#include "Database/DatabaseEnv.h"
//
////This function is called when the player opens the gossip menubool
//bool GossipHello_custom_rename_codebox(Player *player, Creature *_Creature)
//{
//    player->ADD_GOSSIP_ITEM_EXTENDED(0, "Rename? Choose yes/no", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1, "", 0, true);
//    player->ADD_GOSSIP_ITEM(0, "You're not interested.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
//    player->PlayerTalkClass->SendGossipMenu(907,_Creature->GetGUID());
//    return true;
//}
//
////This function is called when the player clicks an option on the gossip menubool
//bool GossipSelect_custom_rename_codebox(Player *player, Creature *_Creature, uint32 sender, uint32 action )
//{
//    if(action == GOSSIP_ACTION_INFO_DEF+2)
//    {
//        _Creature->Say("Mh ok. See ya!", LANG_UNIVERSAL, 0);
//        player->CLOSE_GOSSIP_MENU();
//    }
//    return true;
//}
//
//bool GossipSelectWithCode_custom_rename_codebox( Player *player, Creature *_Creature, uint32 sender, uint32 action, const char* sCode )
//{
//    if(sender == GOSSIP_SENDER_MAIN)
//    {
//        if(action == GOSSIP_ACTION_INFO_DEF+1)
//        {
//            if(std::strcmp(sCode, "yes") ==0)
//            {
//                _Creature->Say("Your nick will change on next login!", LANG_UNIVERSAL, 0);
//                //player->SetAtLoginFlag(AT_LOGIN_RENAME);
//                //CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '1' WHERE guid = '%u'", player->GetGUIDLow());
//
//                player->CLOSE_GOSSIP_MENU();
//               
//            }
//            else if (std::strcmp(sCode, "no") ==0)
//            {
//                _Creature->Say("Mmm take this!", LANG_UNIVERSAL, 0);
//                _Creature->CastSpell(player, 12826, true);
//            }
//            else
//            {
//                player->CLOSE_GOSSIP_MENU();
//            }
//            return true;
//        }
//    }
//    return false;
//}
//
//void AddSC_custom_rename_codebox()
//{
//    Script *newscript;
//
//    newscript = new Script;
//    newscript->Name="custom_rename_codebox";
//    newscript->pGossipHello =           &GossipHello_custom_rename_codebox;
//    newscript->pGossipSelect =          &GossipSelect_custom_rename_codebox;
//    newscript->pGossipSelectWithCode =  &GossipSelectWithCode_custom_rename_codebox;
//    newscript->RegisterSelf();
//}
