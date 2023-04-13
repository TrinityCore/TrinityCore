///*
//*   uwow.biz
//*   arena 1v1
//*/
//
//#include "Battleground.h"
//#include "BattlegroundMgr.h"
//#include "Bracket.h"
//#include "custom_arena_1v1.h"
//#include "Group.h"
//#include "ObjectMgr.h"
//#include "ScriptMgr.h"
//#include "Chat.h"
//#include "ScriptedGossip.h"
//
//enum Actions
//{
//    MENU_1V1 = 1000,
//    MENU_DEATHMATCH = 1010,
//    MENU_DEATHMATCH_STORE_MORPHS = 1020,
//    MENU_DEATHMATCH_STORE_LOGO = 1030,
//    MENU_SOLOQ3V3 = 1040,
//
//    INVITE_1V1 = 2000,
//    INVITE_DM = 2010,
//    INVITE_DM_PRIVATE = 2020,
//    INVITE_SOLOQ3V3 = 2030,
//};
//
////230003
//class npc_1v1arena : public CreatureScript
//{
//public:
//    npc_1v1arena() : CreatureScript("npc_1v1arena") {}
//
//    bool OnGossipHello(Player* player, Creature* creature) override
//    {
//        player->ADD_GOSSIP_ITEM(9, "1v1 Death Arena (Lvl 110 Required)", GOSSIP_SENDER_MAIN, MENU_1V1);
//
//        std::vector<DeathMatchStore> const* store = sObjectMgr->GetDeathMatchStore(DM_TYPE_MORPH);
//        if (store && !store->empty())
//            player->ADD_GOSSIP_ITEM(6, "Store of DeathMatch's morphs", GOSSIP_SENDER_MAIN, MENU_DEATHMATCH_STORE_MORPHS);
//        store = sObjectMgr->GetDeathMatchStore(DM_TYPE_LOGO);
//        if (store && !store->empty())
//            player->ADD_GOSSIP_ITEM(6, "Store of DeathMatch's logos", GOSSIP_SENDER_MAIN, MENU_DEATHMATCH_STORE_LOGO);
//
//        if (sWorld->getBoolConfig(CONFIG_ARENA_DEATHMATCH))
//            player->ADD_GOSSIP_ITEM(9, "DeathMatch", GOSSIP_SENDER_MAIN, MENU_DEATHMATCH);
//        if (sWorld->getBoolConfig(CONFIG_ARENA_SOLOQ_3v3))
//            player->ADD_GOSSIP_ITEM(9, "3v3 Death Arena", GOSSIP_SENDER_MAIN, MENU_SOLOQ3V3);
//
//        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction) override
//    {
//        player->PlayerTalkClass->ClearMenus();
//        switch (uiSender)
//        {
//        case GOSSIP_SENDER_MAIN:
//        {
//            switch (uiAction)
//            {
//            case MENU_1V1:
//                if (player->InBattlegroundQueueForBattlegroundQueueType(MS::Battlegrounds::BattlegroundQueueTypeId::Arena1v1))
//                    player->ADD_GOSSIP_ITEM(9, "You already in the queue on 1v1 Death Arena ", GOSSIP_SENDER_MAIN, 0);
//                else
//                    player->ADD_GOSSIP_ITEM(9, "Join in the queue on 1v1 Death Arena", GOSSIP_SENDER_MAIN, INVITE_1V1);
//
//                if (Bracket* bracket = player->getBracket(MS::Battlegrounds::BracketType::Arena1v1))
//                {
//                    char printfo[500];
//                    sprintf(printfo, "Your rating of Arena 1x1 (MMR)= %u", bracket->getMMV());
//                    player->ADD_GOSSIP_ITEM(8, printfo, GOSSIP_SENDER_MAIN, 0);
//
//                    PrintInfoAboutBracket(player, bracket);
//                }
//                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//                break;
//            case MENU_DEATHMATCH:
//                if (player->InBattlegroundQueueForBattlegroundQueueType(MS::Battlegrounds::BattlegroundQueueTypeId::BattlegroundDeathMatch))
//                    player->ADD_GOSSIP_ITEM(9, "You already in the queue on DeathMatch", GOSSIP_SENDER_MAIN, 0);
//                else
//                {
//                    player->ADD_GOSSIP_ITEM(9, "Join in the queue on DeathMatch", GOSSIP_SENDER_MAIN, INVITE_DM);
//                    player->ADD_GOSSIP_ITEM(0, "Join in the queue on DeathMatch (private for your group without rewards)", GOSSIP_SENDER_MAIN, INVITE_DM_PRIVATE);
//                }
//
//                if (DeathMatchScore* dmScore = player->getDeathMatchScore())
//                {
//                    char printfo[500];
//                    sprintf(printfo, "Your rating of Death Matches = %u", dmScore->rating);
//                    player->ADD_GOSSIP_ITEM(8, printfo, GOSSIP_SENDER_MAIN, 0);
//
//                    sprintf(printfo, "Kills by season = %u", dmScore->kills);
//                    player->ADD_GOSSIP_ITEM(10, printfo, GOSSIP_SENDER_MAIN, 0);
//
//                    sprintf(printfo, "Deaths by season = %u", dmScore->deaths);
//                    player->ADD_GOSSIP_ITEM(10, printfo, GOSSIP_SENDER_MAIN, 0);
//
//                    sprintf(printfo, "Damage by season = %u", dmScore->damage);
//                    player->ADD_GOSSIP_ITEM(10, printfo, GOSSIP_SENDER_MAIN, 0);
//
//                    sprintf(printfo, "Matches by season = %u", dmScore->matches);
//                    player->ADD_GOSSIP_ITEM(10, printfo, GOSSIP_SENDER_MAIN, 0);
//
//                    sprintf(printfo, "You balance of DeathMatch's currency = %u", dmScore->totalKills);
//                    player->ADD_GOSSIP_ITEM(8, printfo, GOSSIP_SENDER_MAIN, 0);
//                }
//                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//                break;
//            case MENU_SOLOQ3V3:
//                if (player->InBattlegroundQueueForBattlegroundQueueType(MS::Battlegrounds::BattlegroundQueueTypeId::ArenaSoloQ3v3))
//                    player->ADD_GOSSIP_ITEM(9, "You already in the queue on 3v3 Death Arena", GOSSIP_SENDER_MAIN, 0);
//                else
//                    player->ADD_GOSSIP_ITEM(9, "Join in the queue on 3v3 Death Arena", GOSSIP_SENDER_MAIN, INVITE_SOLOQ3V3);
//
//                if (Bracket* bracket = player->getBracket(MS::Battlegrounds::BracketType::ArenaSoloQ3v3))
//                {
//                    char printfo[500];
//                    sprintf(printfo, "Your rating of 3v3 Death Arena (MMR)= %u", bracket->getMMV());
//                    player->ADD_GOSSIP_ITEM(8, printfo, GOSSIP_SENDER_MAIN, 0);
//
//                    PrintInfoAboutBracket(player, bracket);
//                }
//                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//                break;
//            case INVITE_1V1:
//            case INVITE_SOLOQ3V3:
//                if (player->InBattlegroundQueue())
//                {
//                    ChatHandler(player).PSendSysMessage("You need to leave from the queue!");
//                    return true;
//                }
//                if (!JoinQueueArena(player, (uiAction == INVITE_1V1 ? MS::Battlegrounds::BracketType::Arena1v1 : MS::Battlegrounds::BracketType::ArenaSoloQ3v3)))
//                    ChatHandler(player).PSendSysMessage("Error on the joining to queue. Not Level 110?");
//
//                player->CLOSE_GOSSIP_MENU();
//                break;
//            case INVITE_DM:
//            case INVITE_DM_PRIVATE:
//                if (player->InBattlegroundQueue())
//                {
//                    ChatHandler(player).PSendSysMessage("You need to leave from queue!");
//                    return true;
//                }
//                if (!JoinQueueDeathMatch(player, (uiAction == INVITE_DM_PRIVATE ? true : false)))
//                    ChatHandler(player).PSendSysMessage("Error on the joining to queue. Not Level 110?");
//                player->CLOSE_GOSSIP_MENU();
//                break;
//            case MENU_DEATHMATCH_STORE_MORPHS:
//            {
//                std::stringstream os;
//                os << "You balanance: " << player->getDeathMatchScore()->totalKills;
//
//                player->ADD_GOSSIP_ITEM(0, os.str(), GOSSIP_SENDER_MAIN, 0);
//                player->ADD_GOSSIP_ITEM(6, "Cancel active morph", GOSSIP_SENDER_INN_INFO, 0);
//
//                std::vector<DeathMatchStore> const* store = sObjectMgr->GetDeathMatchStore(DM_TYPE_MORPH);
//                if (store && !store->empty())
//                {
//                    for (auto itr = store->begin(); itr != store->end(); ++itr)
//                    {
//                        std::ostringstream ss;
//                        ss << (*itr).name;
//                        if (player->getDeathMatchScore()->HasMorph((*itr).product))
//                            ss << " |cff00ff00[Bought]|r";
//                        if (player->getDeathMatchScore()->selectedMorph == (*itr).product)
//                            ss << " |cffFF0000[Active]|r";
//
//                        player->ADD_GOSSIP_ITEM(6, ss.str(), GOSSIP_SENDER_INN_INFO, (*itr).personal_id);
//                    }
//                }
//                player->SEND_GOSSIP_MENU(100012, creature->GetGUID());
//                break;
//            }
//            case MENU_DEATHMATCH_STORE_LOGO:
//            {
//                std::stringstream os;
//                os << "You balanance: " << player->getDeathMatchScore()->totalKills;
//
//                player->ADD_GOSSIP_ITEM(0, os.str(), GOSSIP_SENDER_MAIN, 0);
//                player->ADD_GOSSIP_ITEM(6, "Cancel active logo", GOSSIP_SENDER_INFO, 0);
//                std::vector<DeathMatchStore> const* store = sObjectMgr->GetDeathMatchStore(DM_TYPE_LOGO);
//                if (store && !store->empty())
//                {
//                    for (auto itr = store->begin(); itr != store->end(); ++itr)
//                    {
//                        std::ostringstream ss;
//                        ss << (*itr).name;
//                        if (player->hasChatLogo((*itr).logo))
//                            ss << " |cff00ff00[Bought]|r";
//                        if (player->getSelectedChatLogo() == (*itr).logo)
//                            ss << " |cffFF0000[Active]|r";
//                        player->ADD_GOSSIP_ITEM(6, ss.str(), GOSSIP_SENDER_INFO, (*itr).personal_id);
//                    }
//                }
//                player->SEND_GOSSIP_MENU(100012, creature->GetGUID());
//                break;
//            }
//            break;
//            }
//            break;
//        }
//        case GOSSIP_SENDER_INN_INFO: // morph
//        case GOSSIP_SENDER_INFO: // logo
//        {
//            if (uiAction == 0)
//            {
//                if (uiSender == GOSSIP_SENDER_INN_INFO) // morph
//                    player->getDeathMatchScore()->selectedMorph = 0;
//                else
//                    player->setSelectedChatLogo("");
//                break;
//            }
//            if (std::vector<DeathMatchStore> const* store = sObjectMgr->GetDeathMatchStoreById(uiAction))
//            {
//                for (auto temp = store->begin(); temp != store->end(); ++temp)
//                {
//                    if ((*temp).type == uiSender - 2 && (*temp).personal_id == uiAction)
//                    {
//                        if ((*temp).type == DM_TYPE_MORPH)
//                        {
//                            if (player->getDeathMatchScore()->HasMorph((*temp).product))
//                            {
//                                player->getDeathMatchScore()->selectedMorph = (*temp).product;
//                                ChatHandler(player).PSendSysMessage("Was selected morph %u", (*temp).product);
//                            }
//                            else if (player->getDeathMatchScore()->BuyMorph((*temp).product, (*temp).cost))
//                            {
//                                player->SaveToDB();
//                                ChatHandler(player).PSendSysMessage("Was nought and selected morph %u", (*temp).product);
//                            }
//                            else
//                                ChatHandler(player).PSendSysMessage("Your balanance of kills are too low for buying morph!");
//                        }
//                        else if ((*temp).type == DM_TYPE_LOGO)
//                        {
//                            if (player->hasChatLogo((*temp).logo))
//                            {
//                                ChatHandler(player).PSendSysMessage("Was selected logo %s", (*temp).logo.c_str());
//                                player->setSelectedChatLogo((*temp).logo);
//                                // player->Say("I really love this server! =) [test message]", LANG_UNIVERSAL);
//                            }
//                            else if (player->BuyChatLogoByDeathMatch((*temp).logo, (*temp).cost))
//                            {
//                                player->SaveToDB();
//                                ChatHandler(player).PSendSysMessage("Was bought and selected logo %s", (*temp).logo.c_str());
//                                // player->Say("|cff00ff00 [test message] |r", LANG_UNIVERSAL);
//                            }
//                            else
//                                ChatHandler(player).PSendSysMessage("Your balanance of kills very low for buying logo!");
//                        }
//                    }
//                }
//            }
//            player->CLOSE_GOSSIP_MENU();
//            break;
//        }
//        break;
//        }
//
//        return true;
//    }
//
//    void PrintInfoAboutBracket(Player* player, Bracket* bracket)
//    {
//        if (!player || !bracket)
//            return;
//
//        char printfo[500];
//
//        player->ADD_GOSSIP_ITEM(3, " --- Statistics by week: ---", GOSSIP_SENDER_MAIN, 0);
//
//        sprintf(printfo, "    Best rating = %u", bracket->GetBracketInfo(BRACKET_WEEK_BEST));
//        player->ADD_GOSSIP_ITEM(10, printfo, GOSSIP_SENDER_MAIN, 0);
//
//        sprintf(printfo, "    Wins = %u", bracket->GetBracketInfo(BRACKET_WEEK_WIN));
//        player->ADD_GOSSIP_ITEM(10, printfo, GOSSIP_SENDER_MAIN, 0);
//
//        sprintf(printfo, "    Played matches = %u", bracket->GetBracketInfo(BRACKET_WEEK_GAMES));
//        player->ADD_GOSSIP_ITEM(10, printfo, GOSSIP_SENDER_MAIN, 0);
//
//        player->ADD_GOSSIP_ITEM(3, " --- Statics by season: ---", GOSSIP_SENDER_MAIN, 0);
//
//        sprintf(printfo, "    Best rating = %u", bracket->GetBracketInfo(BRACKET_BEST));
//        player->ADD_GOSSIP_ITEM(10, printfo, GOSSIP_SENDER_MAIN, 0);
//
//        sprintf(printfo, "    Wins = %u", bracket->GetBracketInfo(BRACKET_SEASON_WIN));
//        player->ADD_GOSSIP_ITEM(10, printfo, GOSSIP_SENDER_MAIN, 0);
//
//        sprintf(printfo, "    Played matches = %u", bracket->GetBracketInfo(BRACKET_SEASON_GAMES));
//        player->ADD_GOSSIP_ITEM(10, printfo, GOSSIP_SENDER_MAIN, 0);
//    }
//
//    bool JoinQueueArena(Player* player, uint8 bracket_type)
//    {
//        if (!player)
//            return false;
//
//        if (player->getLevel() < 110)
//            return false;
//
//        if (player->InBattleground())
//            return false;
//
//        if (bracket_type == MS::Battlegrounds::BracketType::Arena1v1 && !Arena1v1CheckTalents(player))
//            return false;
//
//        Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(MS::Battlegrounds::BattlegroundTypeId::ArenaAll);
//        if (!bg)
//            return false;
//
//        uint8 jointype = MS::Battlegrounds::GetJoinTypeByBracketSlot(bracket_type);
//        uint16 bgTypeId = bg->GetTypeID();
//        uint8 bgQueueTypeId = MS::Battlegrounds::GetBgQueueTypeIdByBgTypeID(bgTypeId, jointype);
//        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
//
//        PVPDifficultyEntry const* bracketEntry = sDB2Manager.GetBattlegroundBracketByLevel(bg->GetMapId(), player->getLevel());
//        if (!bracketEntry)
//            return false;
//
//        if (player->isUsingLfg())
//        {
//            ChatHandler(player).PSendSysMessage("1");
//            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
//            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bg, player, 0, MS::Battlegrounds::GroupJoinBattlegroundResult::ERR_LFG_CANT_USE_BATTLEGROUND);
//            player->SendDirectMessage(battlefieldStatus.Write());
//            return false;
//        }
//
//        if (!player->CanJoinToBattleground(MS::Battlegrounds::IternalPvpTypes::Battleground))
//        {
//            ChatHandler(player).PSendSysMessage("2");
//            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
//            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bg, player, 0, MS::Battlegrounds::GroupJoinBattlegroundResult::ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS);
//            player->SendDirectMessage(battlefieldStatus.Write());
//            return false;
//        }
//
//        if (player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
//        {
//            ChatHandler(player).PSendSysMessage("3");
//            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
//            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bg, player, 0, MS::Battlegrounds::GroupJoinBattlegroundResult::ERR_IN_RANDOM_BG);
//            player->SendDirectMessage(battlefieldStatus.Write());
//            return false;
//        }
//
//        if (player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
//        {
//            ChatHandler(player).PSendSysMessage("5");
//            return false;
//        }
//
//        if (!player->HasFreeBattlegroundQueueId())
//        {
//            ChatHandler(player).PSendSysMessage("6");
//            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
//            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bg, player, 0, MS::Battlegrounds::GroupJoinBattlegroundResult::ERR_BATTLEGROUND_TOO_MANY_QUEUES);
//            player->SendDirectMessage(battlefieldStatus.Write());
//            return false;
//        }
//
//        bg->SetRated(true);
//
//        auto bracket = player->getBracket(bracket_type);
//        if (!bracket)
//            return false;
//
//        auto ginfo = bgQueue.AddGroup(player, nullptr, bgTypeId, bracketEntry, jointype, true, true, WorldPackets::Battleground::IgnorMapInfo(), bracket->getMMV());
//        if (!ginfo)
//            return false;
//
//        WorldPackets::Battleground::BattlefieldStatusQueued queued;
//        sBattlegroundMgr->BuildBattlegroundStatusQueued(&queued, bg, player, player->AddBattlegroundQueueId(bgQueueTypeId), ginfo->JoinTime, bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->RangeIndex), ginfo->JoinType, false);
//        player->SendDirectMessage(queued.Write());
//
//        sBattlegroundMgr->ScheduleQueueUpdate(new QueueSchedulerItem(bracket->getMMV(), jointype, bgQueueTypeId, bgTypeId, bracketEntry->RangeIndex));
//        return true;
//    }
//
//    bool JoinQueueDeathMatch(Player* player, bool privated = false)
//    {
//        if (!player)
//            return false;
//
//        if (privated && !player->GetGroup())
//            return false;
//
//        uint16 queueID = MS::Battlegrounds::BattlegroundTypeId::BattlegroundDeathMatch;
//
//        if (!sBattlemasterListStore.LookupEntry(queueID))
//        {
//            ChatHandler(player).PSendSysMessage("Battleground: invalid bgtype (%u) received. possible cheater? player guid %u", queueID, player->GetGUIDLow());
//            return false;
//        }
//
//        if (player->InBattleground())
//            return false;
//
//        Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(queueID);
//        if (!bg)
//        {
//            ChatHandler(player).PSendSysMessage("BG");
//            return false;
//        }
//
//        PVPDifficultyEntry const* bracketEntry = sDB2Manager.GetBattlegroundBracketByLevel(bg->GetMapId(), player->getLevel());
//        if (!bracketEntry)
//        {
//            ChatHandler(player).PSendSysMessage("Bracket");
//            return false;
//        }
//
//        if (player->isUsingLfg())
//        {
//            ChatHandler(player).PSendSysMessage("1");
//            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
//            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bg, player, 0, MS::Battlegrounds::GroupJoinBattlegroundResult::ERR_LFG_CANT_USE_BATTLEGROUND);
//            player->SendDirectMessage(battlefieldStatus.Write());
//            return false;
//        }
//
//        if (!player->CanJoinToBattleground(MS::Battlegrounds::IternalPvpTypes::Battleground))
//        {
//            ChatHandler(player).PSendSysMessage("2");
//            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
//            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bg, player, 0, MS::Battlegrounds::GroupJoinBattlegroundResult::ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS);
//            player->SendDirectMessage(battlefieldStatus.Write());
//            return false;
//        }
//
//        if (player->GetBattlegroundQueueIndex(MS::Battlegrounds::GetBgQueueTypeIdByBgTypeID(MS::Battlegrounds::BattlegroundTypeId::BattlegroundRandom)) < PLAYER_MAX_BATTLEGROUND_QUEUES)
//        {
//            ChatHandler(player).PSendSysMessage("3");
//            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
//            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bg, player, 0, MS::Battlegrounds::GroupJoinBattlegroundResult::ERR_IN_RANDOM_BG);
//            player->SendDirectMessage(battlefieldStatus.Write());
//            return false;
//        }
//
//        if (player->InBattlegroundQueue() && queueID == MS::Battlegrounds::BattlegroundTypeId::BattlegroundRandom)
//        {
//            ChatHandler(player).PSendSysMessage("4");
//            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
//            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bg, player, 0, MS::Battlegrounds::GroupJoinBattlegroundResult::ERR_IN_NON_RANDOM_BG);
//            player->SendDirectMessage(battlefieldStatus.Write());
//            return false;
//        }
//
//        uint8 bgQueueTypeId = MS::Battlegrounds::GetBgQueueTypeIdByBgTypeID(queueID);
//        if (player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
//        {
//            ChatHandler(player).PSendSysMessage("5");
//            return false;
//        }
//
//        if (!player->HasFreeBattlegroundQueueId())
//        {
//            ChatHandler(player).PSendSysMessage("6");
//            WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
//            sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bg, player, 0, MS::Battlegrounds::GroupJoinBattlegroundResult::ERR_BATTLEGROUND_TOO_MANY_QUEUES);
//            player->SendDirectMessage(battlefieldStatus.Write());
//            return false;
//        }
//
//        if (!privated)
//        {
//            BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
//            WorldPackets::Battleground::IgnorMapInfo ignore;
//            GroupQueueInfo* ginfo = bgQueue.AddGroup(player, nullptr, queueID, bracketEntry, 0, true, false, ignore, 1);
//            uint32 avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->RangeIndex);
//            uint32 queueSlot = player->AddBattlegroundQueueId(bgQueueTypeId);
//
//            WorldPackets::Battleground::BattlefieldStatusQueued queued;
//            sBattlegroundMgr->BuildBattlegroundStatusQueued(&queued, bg, player, queueSlot, ginfo->JoinTime, avgTime, ginfo->JoinType, false);
//            player->SendDirectMessage(queued.Write());
//
//            sBattlegroundMgr->ScheduleQueueUpdate(new QueueSchedulerItem(1, 0, bgQueueTypeId, queueID, bracketEntry->RangeIndex, Roles(ROLES_DPS), bracketEntry->MinLevel));
//            return true;
//        }
//        uint8 err = MS::Battlegrounds::GroupJoinBattlegroundResult::ERR_BATTLEGROUND_NONE;
//        Group* grp = player->GetGroup();
//        if (!grp || grp->GetLeaderGUID() != player->GetGUID())
//            return false;
//
//        ObjectGuid errorGuid;
//        err = grp->CanJoinBattlegroundQueue(bg, bgQueueTypeId, 0, false, 0, errorGuid);
//
//        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
//        GroupQueueInfo* ginfo = nullptr;
//        uint32 avgTime = 0;
//
//        if (!err)
//        {
//            WorldPackets::Battleground::IgnorMapInfo ignore;
//            ginfo = bgQueue.AddGroup(player, grp, queueID, bracketEntry, 0, false, true, ignore, 0);
//            avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->RangeIndex);
//        }
//
//        for (GroupReference* itr = grp->GetFirstMember(); itr != nullptr; itr = itr->next())
//        {
//            Player* member = itr->getSource();
//            if (!member)
//                continue;
//
//            if (err)
//            {
//                WorldPackets::Battleground::BattlefieldStatusFailed battlefieldStatus;
//                sBattlegroundMgr->BuildBattlegroundStatusFailed(&battlefieldStatus, bg, member, 0, err, &errorGuid);
//                member->SendDirectMessage(battlefieldStatus.Write());
//                continue;
//            }
//
//            WorldPackets::Battleground::BattlefieldStatusQueued queued;
//            sBattlegroundMgr->BuildBattlegroundStatusQueued(&queued, bg, member, member->AddBattlegroundQueueId(bgQueueTypeId), ginfo->JoinTime, avgTime, ginfo->JoinType, true);
//            member->SendDirectMessage(queued.Write());
//        }
//
//        sBattlegroundMgr->ScheduleQueueUpdate(new QueueSchedulerItem(0, 0, bgQueueTypeId, queueID, bracketEntry->RangeIndex, Roles(ROLES_DPS), bracketEntry->MinLevel));
//
//        return true;
//    }
//};
//
//
//void AddSC_custom_arena_1v1()
//{
//    new npc_1v1arena();
//}
