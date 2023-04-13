//#include "ScriptMgr.h"
//#include "ObjectMgr.h"
//#include "Chat.h"
//#include "Player.h"
//
//class command_donate : public CommandScript
//{
//public:
//    command_donate() : CommandScript("command_donate") { }
//
//    ChatCommand* GetCommands() const
//    {
//
//        static ChatCommand morphCommandTable[] =
//        {
//            { "list",           SEC_PLAYER,         false, &HandleListMorphCommand,             "", NULL },
//            { "use",            SEC_PLAYER,         false, &HandleUseMorphCommand,              "", NULL },
//            { "remove",         SEC_PLAYER,         false, &HandleRemoveMorphCommand,           "", NULL },
//            { "add",            SEC_ADMINISTRATOR,  false, &HandleAddMorphCommand,              "", NULL },
//            { "del",            SEC_ADMINISTRATOR,  false, &HandleDelMorphCommand,              "", NULL },
//            { NULL,             0,                  false, NULL,                                "", NULL }
//        };
//
//        static ChatCommand mountFlyCommandTable[] =
//        {
//            { "list",           SEC_PLAYER,         false, &HandleListMountFlyCommand,             "", NULL },
//            { "use",            SEC_PLAYER,         false, &HandleUseMountFlyCommand,              "", NULL },
//            { "add",            SEC_ADMINISTRATOR,  false, &HandleAddMountFlyCommand,              "", NULL },
//            { "del",            SEC_ADMINISTRATOR,  false, &HandleDelMountFlyCommand,              "", NULL },
//            { NULL,             0,                  false, NULL,                                "", NULL }
//        };
//
//        static ChatCommand mountGroundCommandTable[] =
//        {
//            { "list",           SEC_PLAYER,         false, &HandleListMountGroundCommand,             "", NULL },
//            { "use",            SEC_PLAYER,         false, &HandleUseMountGroundCommand,              "", NULL },
//            { "add",            SEC_ADMINISTRATOR,  false, &HandleAddMountGroundCommand,              "", NULL },
//            { "del",            SEC_ADMINISTRATOR,  false, &HandleDelMountGroundCommand,              "", NULL },
//            { NULL,             0,                  false, NULL,                                "", NULL }
//        };
//
//        static ChatCommand mountCommandTable[] =
//        {
//            { "fly",           SEC_PLAYER,         false, NULL,             "", mountFlyCommandTable },
//            { "ground",        SEC_PLAYER,         false, NULL,             "", mountGroundCommandTable },
//            { NULL,             0,                  false, NULL,                                "", NULL }
//        };
//
//        static ChatCommand tokensCommandTable[] =
//        {
//            { "info",           SEC_CONFIRMED_GAMEMASTER,         false, &HandleInfoTokensCommand,           "", NULL },
//            { "modify",         SEC_ADMINISTRATOR,         false, &HandleModTokensCommand,            "", NULL },
//            { NULL,             0,                  false, NULL,                                "", NULL }
//        };
//
//        static ChatCommand donateCommandTable[] =
//        {
//            { "morph",          SEC_PLAYER,         false, NULL,                                "", morphCommandTable },
//            { "mount",          SEC_PLAYER,         false, NULL,                                "", mountCommandTable },
//            { "add",            SEC_ADMINISTRATOR,  false, &HandleAddDonatCommand,              "", NULL },
//            { "tokens",         SEC_CONFIRMED_GAMEMASTER,  false, NULL,                         "", tokensCommandTable },
//            { NULL,             0,                  false, NULL,                                "", NULL }
//        };
//
//        static ChatCommand commandTable[] =
//        {
//            { "donate",         SEC_PLAYER,         false, NULL,                                "", donateCommandTable },
//            { NULL,             0,                  false, NULL,                                "", NULL }
//        };
//        return commandTable;
//    }
//
//    static bool HandleListMorphCommand(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//        uint32 accountId = handler->GetSession()->GetAccountId();
//        uint32 bnaccountId = handler->GetSession()->GetBattlenetAccountId();
//
//        QueryResult result = LoginDatabase.PQuery("SELECT bonus FROM store_history WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-9' AND `status` = '0' AND realm = '%u';", accountId, bnaccountId, realm.Id.Realm);
//        if (result)
//        {
//            do
//            {
//                Field* fetch = result->Fetch();
//                std::string entry = fetch[0].GetString();
//
//                handler->PSendSysMessage(".donate morph use %s", entry.c_str());
//            } while (result->NextRow());
//        }
//        else
//            handler->PSendSysMessage("Cant find morph to use.");
//        return true;
//    }
//
//    static bool HandleUseMorphCommand(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//        uint32 accountId = handler->GetSession()->GetAccountId();
//        uint32 bnaccountId = handler->GetSession()->GetBattlenetAccountId();
//
//        char* morphId = strtok((char*)args, " ");
//        if (!morphId || !player)
//            return false;
//
//        int32 morph = atoi(morphId);
//        if (!morph)
//            return false;
//
//        QueryResult result = LoginDatabase.PQuery("SELECT bonus FROM store_history WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-9' AND `status` = '0' AND bonus = '%u' AND realm = '%u';", accountId, bnaccountId, morph, realm.Id.Realm);
//        if (player->isGameMaster() || result)
//        {
//            if (CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(morph))
//            {
//                uint32 modelid = ci->GetRandomValidModelId();
//                player->SetCustomDisplayId(modelid);
//                player->SetDisplayId(modelid, true);
//            }
//            else
//                handler->PSendSysMessage("Cant find morph to use.");
//        }
//        else
//            handler->PSendSysMessage("Cant find morph to use.");
//
//        return true;
//    }
//
//    static bool HandleRemoveMorphCommand(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//        //    player->DeMorph();
//        player->ResetCustomDisplayId();
//        player->SetObjectScale(1.0f);
//        return true;
//    }
//
//    static bool HandleAddMorphCommand(ChatHandler* handler, const char* args)
//    {
//        char* nameStr;
//        char* morphStr;
//        handler->extractOptFirstArg((char*)args, &nameStr, &morphStr);
//
//        char* tokenCountStr = strtok(NULL, "\r");
//
//        Player* player = handler->GetSession()->GetPlayer();
//        Player* target;
//        ObjectGuid target_guid;
//        std::string target_name;
//        if (!handler->extractPlayerTarget(nameStr, &target, &target_guid, &target_name))
//            return false;
//        if (!target && target_guid)
//            target = sObjectMgr->GetPlayerByLowGUID(target_guid.GetGUIDLow());
//        if (!target)
//            return false;
//        uint32 accountId = target->GetSession()->GetAccountId();
//        uint32 bnaccountId = target->GetSession()->GetBattlenetAccountId();
//
//        if (!morphStr)
//            return false;
//        uint32 morphId = atoi(morphStr);
//
//        if (!tokenCountStr)
//            return false;
//        uint32 tokenCount = atoi(tokenCountStr);
//
//        if (!target->HasDonateToken(tokenCount))
//        {
//            handler->PSendSysMessage("Target don`t have token count %u in bags", tokenCount);
//            return true;
//        }
//
//        QueryResult result = LoginDatabase.PQuery("select `id` from `store_products` where `item` = %d;", -9);
//        if (!result)
//        {
//            handler->PSendSysMessage("On your realm don't activate this service");
//            return true;
//        }
//
//        if (!target->DestroyDonateTokenCount(tokenCount))
//        {
//            handler->PSendSysMessage("Target don`t have token count %u in bags", tokenCount);
//            return true;
//        }
//
//        TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Buy] Morph entry = %u, cost = %u, %s", morphId, tokenCount, target->GetInfoForDonate().c_str());
//
//        LoginDatabase.PExecute("INSERT INTO `store_history` (`realm`, `account`, `bnet_account`, `char_guid`, `item_guid`, `item`, `count`, `token`, `char_level`, `product`, `bonus`) VALUES (%u, %u, %u, %u, %u, %d, 1, %u, %u, (select `id` from `store_products` where `item` = %d), %u);", realm.Id.Realm, accountId, bnaccountId, target_guid.GetGUIDLow(), 0, -9, tokenCount, target->getLevel(), -9, morphId);
//        handler->PSendSysMessage("Morph add %u for %u tokens", morphId, tokenCount);
//
//        return true;
//    }
//    static bool HandleDelMorphCommand(ChatHandler* handler, const char* args)
//    {
//        char* nameStr;
//        char* morphStr;
//        handler->extractOptFirstArg((char*)args, &nameStr, &morphStr);
//
//        Player* player = handler->GetSession()->GetPlayer();
//        Player* target;
//        ObjectGuid target_guid;
//        std::string target_name;
//        if (!handler->extractPlayerTarget(nameStr, &target, &target_guid, &target_name))
//            return false;
//        if (!target && target_guid)
//            target = sObjectMgr->GetPlayerByLowGUID(target_guid.GetGUIDLow());
//        if (!target)
//            return false;
//        uint32 accountId = target->GetSession()->GetAccountId();
//        uint32 bnaccountId = target->GetSession()->GetBattlenetAccountId();
//
//        if (!morphStr)
//            return false;
//        uint32 morphId = atoi(morphStr);
//
//        QueryResult result = LoginDatabase.PQuery("SELECT token FROM store_history WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-9' AND `status` = '0' AND bonus = '%u' and realm = '%u';", accountId, bnaccountId, morphId, realm.Id.Realm);
//        if (result)
//        {
//            do
//            {
//                Field* fetch = result->Fetch();
//                uint32 tokenCount = fetch[0].GetUInt32();
//
//                if (target->AddDonateTokenCount(tokenCount))
//                {
//                    TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Status] Return morph entry = %u, return_tokens = %u, %s", morphId, tokenCount, target->GetInfoForDonate().c_str());
//                    LoginDatabase.PExecute("update `store_history` set `status` = 7 WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-9' AND `status` = '0' AND bonus = '%u' and realm = '%u';", accountId, bnaccountId, morphId, realm.Id.Realm);
//                    handler->PSendSysMessage("Morph %u delete and %u tokens give player", morphId, tokenCount);
//                }
//                else
//                    handler->PSendSysMessage("Some problems... try later again");
//            } while (result->NextRow());
//        }
//        else
//            handler->PSendSysMessage("Morph %u dont find", morphId);
//
//        return true;
//    }
//
//    /////////////// mounts 
//    static bool HandleListMountFlyCommand(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//        uint32 accountId = handler->GetSession()->GetAccountId();
//        uint32 bnaccountId = handler->GetSession()->GetBattlenetAccountId();
//
//        QueryResult result = LoginDatabase.PQuery("SELECT bonus FROM store_history WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-11' AND `status` = '0' AND realm = '%u';", accountId, bnaccountId, realm.Id.Realm);
//        if (result)
//        {
//            do
//            {
//                Field* fetch = result->Fetch();
//                std::string entry = fetch[0].GetString();
//
//                handler->PSendSysMessage(".donate mount fly use %s", entry.c_str());
//            } while (result->NextRow());
//        }
//        else
//            handler->PSendSysMessage("Cant find mount to use.");
//        return true;
//    }
//
//    static bool HandleUseMountFlyCommand(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//        uint32 accountId = handler->GetSession()->GetAccountId();
//        uint32 bnaccountId = handler->GetSession()->GetBattlenetAccountId();
//
//        char* mountId = strtok((char*)args, " ");
//        if (!mountId)
//            return false;
//
//        int32 mount = atoi(mountId);
//        if (!mount)
//            return false;
//
//        if (player->isGameMaster())
//        {
//            CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(mount);
//            if (!(ci))
//                return false;
//
//            uint32 displayID = sObjectMgr->ChooseDisplayId(0, ci);
//            sObjectMgr->GetCreatureModelRandomGender(&displayID);
//            player->CastSpell(player, 31700);
//            player->Mount(displayID);
//            handler->PSendSysMessage("It's demo version for GM with GM spell");
//            return true;
//        }
//
//        QueryResult result = LoginDatabase.PQuery("SELECT bonus FROM store_history WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-11' AND `status` = '0' AND bonus = '%u' AND realm = '%u';", accountId, bnaccountId, mount, realm.Id.Realm);
//        if (result)
//        {
//            player->CastSpell(player, 215545); // 215545
//            //player->Mount(displayID, ci->VehicleId, mount);
//            new mount_set_display_fly(player, mount);
//        }
//        else
//            handler->PSendSysMessage("Cant find mount to use.");
//
//        return true;
//    }
//
//    static bool HandleAddMountFlyCommand(ChatHandler* handler, const char* args)
//    {
//        char* nameStr;
//        char* mountStr;
//        handler->extractOptFirstArg((char*)args, &nameStr, &mountStr);
//
//        char* tokenCountStr = strtok(NULL, "\r");
//
//        Player* player = handler->GetSession()->GetPlayer();
//        Player* target;
//        ObjectGuid target_guid;
//        std::string target_name;
//        if (!handler->extractPlayerTarget(nameStr, &target, &target_guid, &target_name))
//            return false;
//        if (!target && target_guid)
//            target = sObjectMgr->GetPlayerByLowGUID(target_guid.GetGUIDLow());
//        if (!target)
//            return false;
//        uint32 accountId = target->GetSession()->GetAccountId();
//        uint32 bnaccountId = target->GetSession()->GetBattlenetAccountId();
//
//        if (!mountStr)
//            return false;
//        uint32 mountId = atoi(mountStr);
//
//        if (!tokenCountStr)
//            return false;
//        uint32 tokenCount = atoi(tokenCountStr);
//
//        if (!target->HasDonateToken(tokenCount))
//        {
//            handler->PSendSysMessage("Target don`t have token count %u in bags", tokenCount);
//            return true;
//        }
//
//        QueryResult result = LoginDatabase.PQuery("select `id` from `store_products` where `item` = %d;", -11);
//        if (!result)
//        {
//            handler->PSendSysMessage("On your realm don't activate this service");
//            return true;
//        }
//
//
//        if (!target->DestroyDonateTokenCount(tokenCount))
//        {
//            handler->PSendSysMessage("Target don`t have token count %u in bags", tokenCount);
//            return true;
//        }
//
//
//        TC_LOG_DEBUG(LOG_FILTER_DONATE, "[But] Fly mount entry = %u, cost = %u, %s", mountId, tokenCount, target->GetInfoForDonate().c_str());
//
//        LoginDatabase.PExecute("INSERT INTO `store_history` (`realm`, `account`, `bnet_account`, `char_guid`, `item_guid`, `item`, `count`, `token`, `char_level`, `product`, `bonus`) VALUES (%u, %u, %u, %u, %u, %d, 1, %u, %u, (select `id` from `store_products` where `item` = %d), %u);", realm.Id.Realm, accountId, bnaccountId, target_guid.GetGUIDLow(), 0, -11, tokenCount, target->getLevel(), -11, mountId);
//        handler->PSendSysMessage("Fly mount add %u for %u tokens", mountId, tokenCount);
//
//        return true;
//    }
//
//    static bool HandleDelMountFlyCommand(ChatHandler* handler, const char* args)
//    {
//        char* nameStr;
//        char* morphStr;
//        handler->extractOptFirstArg((char*)args, &nameStr, &morphStr);
//
//        Player* player = handler->GetSession()->GetPlayer();
//        Player* target;
//        ObjectGuid target_guid;
//        std::string target_name;
//        if (!handler->extractPlayerTarget(nameStr, &target, &target_guid, &target_name))
//            return false;
//        if (!target && target_guid)
//            target = sObjectMgr->GetPlayerByLowGUID(target_guid.GetGUIDLow());
//        if (!target)
//            return false;
//        uint32 accountId = target->GetSession()->GetAccountId();
//        uint32 bnaccountId = target->GetSession()->GetBattlenetAccountId();
//
//        if (!morphStr)
//            return false;
//        uint32 mountId = atoi(morphStr);
//
//        QueryResult result = LoginDatabase.PQuery("SELECT token FROM store_history WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-11' AND `status` = '0' AND bonus = '%u' and realm = '%u';", accountId, bnaccountId, mountId, realm.Id.Realm);
//        if (result)
//        {
//            do
//            {
//                Field* fetch = result->Fetch();
//                uint32 tokenCount = fetch[0].GetUInt32();
//
//                if (target->AddDonateTokenCount(tokenCount))
//                {
//
//                    TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Status] Return fly mount entry = %u, return_tokens = %u, %s", mountId, tokenCount, target->GetInfoForDonate().c_str());
//
//                    LoginDatabase.PExecute("update `store_history` set `status` = 7 WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-11' AND `status` = '0' AND bonus = '%u' and realm = '%u';", accountId, bnaccountId, mountId, realm.Id.Realm);
//                    handler->PSendSysMessage("Fly mount %u delete and %u tokens give player", mountId, tokenCount);
//                }
//                else
//                    handler->PSendSysMessage("Some problems... try later again");
//            } while (result->NextRow());
//        }
//        else
//            handler->PSendSysMessage("Fly mount %u dont find", mountId);
//
//        return true;
//    }
//
//    // ground
//    static bool HandleListMountGroundCommand(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//        uint32 accountId = handler->GetSession()->GetAccountId();
//        uint32 bnaccountId = handler->GetSession()->GetBattlenetAccountId();
//
//        QueryResult result = LoginDatabase.PQuery("SELECT bonus FROM store_history WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-10' AND `status` = '0' AND realm = '%u';", accountId, bnaccountId, realm.Id.Realm);
//        if (result)
//        {
//            do
//            {
//                Field* fetch = result->Fetch();
//                std::string entry = fetch[0].GetString();
//                handler->PSendSysMessage(".donate mount ground use %s", entry.c_str());
//            } while (result->NextRow());
//        }
//        else
//            handler->PSendSysMessage("Cant find mount to use.");
//        return true;
//    }
//
//    static bool HandleUseMountGroundCommand(ChatHandler* handler, const char* args)
//    {
//        Player* player = handler->GetSession()->GetPlayer();
//        uint32 accountId = handler->GetSession()->GetAccountId();
//        uint32 bnaccountId = handler->GetSession()->GetBattlenetAccountId();
//
//        char* mountId = strtok((char*)args, " ");
//        if (!mountId)
//            return false;
//
//        int32 mount = atoi(mountId);
//        if (!mount)
//            return false;
//
//        if (player->isGameMaster())
//        {
//            CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(mount);
//            if (!(ci))
//                return false;
//
//            uint32 displayID = sObjectMgr->ChooseDisplayId(0, ci);
//            sObjectMgr->GetCreatureModelRandomGender(&displayID);
//            player->CastSpell(player, 31700);
//            player->Mount(displayID);
//            handler->PSendSysMessage("It's demo version for GM with GM spell");
//            return true;
//        }
//
//        QueryResult result = LoginDatabase.PQuery("SELECT bonus FROM store_history WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-10' AND `status` = '0' AND bonus = '%u' AND realm = '%u';", accountId, bnaccountId, mount, realm.Id.Realm);
//        if (result)
//        {
//            player->CastSpell(player, 165974);
//
//            //player->Mount(displayID, ci->VehicleId, mount);
//            new mount_set_display_ground(player, mount);
//        }
//        else
//            handler->PSendSysMessage("Cant find mount to use.");
//
//        return true;
//    }
//
//    static bool HandleAddMountGroundCommand(ChatHandler* handler, const char* args)
//    {
//        char* nameStr;
//        char* mountStr;
//        handler->extractOptFirstArg((char*)args, &nameStr, &mountStr);
//
//        char* tokenCountStr = strtok(NULL, "\r");
//
//        Player* player = handler->GetSession()->GetPlayer();
//        Player* target;
//        ObjectGuid target_guid;
//        std::string target_name;
//        if (!handler->extractPlayerTarget(nameStr, &target, &target_guid, &target_name))
//            return false;
//        if (!target && target_guid)
//            target = sObjectMgr->GetPlayerByLowGUID(target_guid.GetGUIDLow());
//        if (!target)
//            return false;
//        uint32 accountId = target->GetSession()->GetAccountId();
//        uint32 bnaccountId = target->GetSession()->GetBattlenetAccountId();
//
//        if (!mountStr)
//            return false;
//        uint32 mountId = atoi(mountStr);
//
//        if (!tokenCountStr)
//            return false;
//        uint32 tokenCount = atoi(tokenCountStr);
//
//        if (!target->HasDonateToken(tokenCount))
//        {
//            handler->PSendSysMessage("Target don`t have token count %u in bags", tokenCount);
//            return true;
//        }
//        if (!target->DestroyDonateTokenCount(tokenCount))
//        {
//            handler->PSendSysMessage("Target don`t have token count %u in bags", tokenCount);
//            return true;
//        }
//
//        QueryResult result = LoginDatabase.PQuery("select `id` from `store_products` where `item` = %d;", -10);
//        if (!result)
//        {
//            handler->PSendSysMessage("On your realm don't activate this service");
//            return true;
//        }
//
//        TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Buy] Ground mount entry = %u, cost = %u, %s", mountId, tokenCount, target->GetInfoForDonate().c_str());
//
//        LoginDatabase.PExecute("INSERT INTO `store_history` (`realm`, `account`, `bnet_account`, `char_guid`, `item_guid`, `item`, `count`, `token`, `char_level`, `product`, `bonus`) VALUES (%u, %u, %u, %u, %u, %d, 1, %u, %u, (select `id` from `store_products` where `item` = %d), %u);", realm.Id.Realm, accountId, bnaccountId, target_guid.GetGUIDLow(), 0, -10, tokenCount, target->getLevel(), -10, mountId);
//        handler->PSendSysMessage("Ground mount add %u for %u tokens", mountId, tokenCount);
//
//        return true;
//    }
//
//    static bool HandleDelMountGroundCommand(ChatHandler* handler, const char* args)
//    {
//        char* nameStr;
//        char* morphStr;
//        handler->extractOptFirstArg((char*)args, &nameStr, &morphStr);
//
//        Player* player = handler->GetSession()->GetPlayer();
//        Player* target;
//        ObjectGuid target_guid;
//        std::string target_name;
//        if (!handler->extractPlayerTarget(nameStr, &target, &target_guid, &target_name))
//            return false;
//        if (!target && target_guid)
//            target = sObjectMgr->GetPlayerByLowGUID(target_guid.GetGUIDLow());
//        if (!target)
//            return false;
//        uint32 accountId = target->GetSession()->GetAccountId();
//        uint32 bnaccountId = target->GetSession()->GetBattlenetAccountId();
//
//        if (!morphStr)
//            return false;
//        uint32 mountId = atoi(morphStr);
//
//        QueryResult result = LoginDatabase.PQuery("SELECT token FROM store_history WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-10' AND `status` = '0' AND bonus = '%u' and realm = '%u';", accountId, bnaccountId, mountId, realm.Id.Realm);
//        if (result)
//        {
//            do
//            {
//                Field* fetch = result->Fetch();
//                uint32 tokenCount = fetch[0].GetUInt32();
//
//                if (target->AddDonateTokenCount(tokenCount))
//                {
//                    TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Status] Return ground mount entry = %u, return_tokens = %u, %s", mountId, tokenCount, target->GetInfoForDonate().c_str());
//                    LoginDatabase.PExecute("update `store_history` set `status` = 7 WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-10' AND `status` = '0' AND bonus = '%u' and realm = '%u';", accountId, bnaccountId, mountId, realm.Id.Realm);
//                    handler->PSendSysMessage("Ground mount %u delete and %u tokens give player", mountId, tokenCount);
//                }
//                else
//                    handler->PSendSysMessage("Some problems... try later again");
//            } while (result->NextRow());
//        }
//        else
//            handler->PSendSysMessage("Ground mount %u don`t find", mountId);
//
//        return true;
//    }
//
//    static bool HandleAddDonatCommand(ChatHandler* handler, const char* args)
//    {
//        char* nameStr;
//        char* itemStr;
//        handler->extractOptFirstArg((char*)args, &nameStr, &itemStr);
//
//        char* tokenCountStr = strtok(NULL, "\r");
//
//        Player* player = handler->GetSession()->GetPlayer();
//        Player* target;
//        ObjectGuid target_guid;
//        std::string target_name;
//        if (!handler->extractPlayerTarget(nameStr, &target, &target_guid, &target_name))
//            return false;
//        if (!target && target_guid)
//            target = sObjectMgr->GetPlayerByLowGUID(target_guid.GetGUIDLow());
//        if (!target)
//            return false;
//        uint32 accountId = target->GetSession()->GetAccountId();
//        uint32 bnaccountId = target->GetSession()->GetBattlenetAccountId();
//
//        if (!itemStr)
//            return false;
//        uint32 itemId = atoi(itemStr);
//
//        if (!tokenCountStr)
//            return false;
//        uint32 tokenCount = atoi(tokenCountStr);
//
//        if (!target->HasDonateToken(tokenCount))
//        {
//            handler->PSendSysMessage("Target don`t have token count %u in bags", tokenCount);
//            return false;
//        }
//        if (!target->DestroyDonateTokenCount(tokenCount))
//        {
//            handler->PSendSysMessage("Target don`t have token count %u in bags", tokenCount);
//            return true;
//        }
//
//        target->AddItem(itemId, 1);
//
//        TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Buy Online] item entry = %u, cost = %u, %s", itemId, tokenCount, target->GetInfoForDonate().c_str());
//
//        SQLTransaction trans = LoginDatabase.BeginTransaction();
//
//        uint8 index = 0;
//        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_STORE_ADD_ITEM_LOG);
//        stmt->setUInt32(index, realm.Id.Realm);
//        stmt->setUInt32(++index, target->GetSession()->GetAccountId());
//        stmt->setUInt32(++index, target->GetSession()->GetBattlenetAccountId()); // select battlenet_account from account where id = %u
//        stmt->setUInt64(++index, target->GetGUIDLow());
//        stmt->setUInt64(++index, 0); // item_guid
//        stmt->setUInt32(++index, itemId); // item entry
//        stmt->setUInt32(++index, 1); // item count
//        stmt->setInt64(++index, tokenCount); // cost
//        stmt->setUInt32(++index, target->getLevel()); // level
//        stmt->setInt32(++index, 0); // donate Store id
//        stmt->setInt32(++index, 0); // select for bonus
//
//        trans->Append(stmt);
//        LoginDatabase.CommitTransaction(trans);
//        return true;
//    }
//    static bool HandleModTokensCommand(ChatHandler* handler, const char* args)
//    {
//        char* nameStr;
//        char* tokenCountStr;
//        handler->extractOptFirstArg((char*)args, &nameStr, &tokenCountStr);
//        if (!nameStr)
//            return false;
//
//        Player* target;
//        ObjectGuid target_guid;
//        std::string target_name;
//        if (!handler->extractPlayerTarget(nameStr, &target, &target_guid, &target_name))
//            return false;
//        if (!target && target_guid)
//            target = sObjectMgr->GetPlayerByLowGUID(target_guid.GetGUIDLow());
//        if (!target)
//            return false;
//        uint32 bnaccountId = target->GetSession()->GetBattlenetAccountId();
//
//        if (!tokenCountStr)
//            return false;
//        int32 tokenCount = atoi(tokenCountStr);
//
//        if (tokenCount < 0)
//        {
//            if (target->HasDonateToken(-1 * tokenCount) && target->DestroyDonateTokenCount(-1 * tokenCount))
//                handler->PSendSysMessage("You delete %d tokens by player: %s", -1 * tokenCount, target->GetName());
//            else
//                handler->PSendSysMessage("Player %s don't have %d tokens", target->GetName(), -1 * tokenCount);
//        }
//        else
//        {
//            if (target->AddDonateTokenCount(tokenCount))
//                handler->PSendSysMessage("You add %d tokens for player: %s", tokenCount, target->GetName());
//            else
//                handler->PSendSysMessage("Some problems... try later again");
//        }
//
//        return true;
//    }
//
//    static bool HandleInfoTokensCommand(ChatHandler* handler, const char* args)
//    {
//        Player* target;
//        ObjectGuid target_guid;
//        std::string target_name;
//        if (!handler->extractPlayerTarget((char*)args, &target, &target_guid, &target_name))
//            return false;
//        if (!target && target_guid)
//            target = sObjectMgr->GetPlayerByLowGUID(target_guid.GetGUIDLow());
//        if (!target)
//            return false;
//
//        uint32 bnaccountId = target->GetSession()->GetBattlenetAccountId();
//
//        // if (!tokenCountStr)
//            // return false;
//        // int32 tokenCount = atoi(tokenCountStr);
//
//
//        QueryResult result = LoginDatabase.PQuery("SELECT balans FROM battlenet_accounts where id = %u", bnaccountId);
//        if (result)
//        {
//            do
//            {
//                Field* fetch = result->Fetch();
//                uint32 getTokens = fetch[0].GetUInt32();
//
//                handler->PSendSysMessage("Target %s have %d tokens", target->GetName(), getTokens);
//            } while (result->NextRow());
//        }
//        else
//            handler->PSendSysMessage("Some problem. (Player not found????)");
//
//        return true;
//    }
//
//    class mount_set_display_fly : public BasicEvent
//    {
//    public:
//        mount_set_display_fly(Player* player, uint32 mount) : player(player), mount(mount)
//        {
//            player->m_Events.AddEvent(this, player->m_Events.CalculateTime(1550));
//        }
//
//        bool Execute(uint64 /*time*/, uint32 /*diff*/)
//        {
//            if (player->HasAura(215545))
//            {
//                Player* pPlayer = player->GetSession()->GetPlayer();
//
//                CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(mount);
//                if (!(ci))
//                    return false;
//
//                uint32 displayID = sObjectMgr->ChooseDisplayId(0, ci);
//                sObjectMgr->GetCreatureModelRandomGender(&displayID);
//
//                player->Mount(displayID, ci->VehicleId, mount);
//            }
//
//            return true;
//        }
//        Player* player;
//        uint32 mount;
//    };
//
//    class mount_set_display_ground : public BasicEvent
//    {
//    public:
//        mount_set_display_ground(Player* player, uint32 mount) : player(player), mount(mount)
//        {
//            player->m_Events.AddEvent(this, player->m_Events.CalculateTime(1550));
//        }
//
//        bool Execute(uint64 /*time*/, uint32 /*diff*/)
//        {
//            if (player->HasAura(165974))
//            {
//                Player* pPlayer = player->GetSession()->GetPlayer();
//
//                CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(mount);
//                if (!(ci))
//                    return false;
//
//                uint32 displayID = sObjectMgr->ChooseDisplayId(0, ci);
//                sObjectMgr->GetCreatureModelRandomGender(&displayID);
//
//                player->Mount(displayID, ci->VehicleId, mount);
//            }
//
//            return true;
//        }
//
//        Player* player;
//        uint32 mount;
//
//    };
//};
//
//
//
//void AddSC_command_donate()
//{
//    new command_donate();
//}
