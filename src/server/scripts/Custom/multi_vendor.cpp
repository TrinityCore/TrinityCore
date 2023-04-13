//#include "GameTables.h"
//#include "PrecompiledHeaders/ScriptPCH.h"
//#include "ScriptedEscortAI.h"
//#include "Spell.h"
//#include "ObjectMgr.h"
//#include "PlayerDump.h"
//#include "CharacterService.h"
//#include "Guild.h"
//#include "GuildPackets.h"
//#include "GuildMgr.h"
//#include "CharacterData.h"
//#include "WordFilterMgr.h"
//
//// Options
//enum eEnums
//{
//    CHANGE_ITEMBACK = 0,
//    CHANGE_FACTION = 1,
//    CHANGE_RACE = 2,
//    CHANGE_GENDER = 3,
//
//    LEVEL_UP = 6,
//    CHANGE_NAME = 7,
//    ART_LEVEL_UP = 8,
//    BUY_GOLD = 9,
//    ADD_BONUS = 10,
//    RENAME_GUILD = 11,
//
//    CHANGE_FACTION_COUNT = 200,
//    CHANGE_RACE_COUNT = 150,
//    CHANGE_GENDER_COUNT = 100,
//
//    NPC_PREVIEWER = 230017,
//};
//
//enum eService // like types on DB
//{
//    SERVICE_GUILD_RENAME = -12,
//    SERVICE_CUSTOM_FLY_MOUNT = -11,
//
//    SERVICE_CUSTOM_GR_MOUNT = -10,
//    SERVICE_CUSTOM_MORPH = -9,
//
//    SERVICE_SELL_ADD_BONUS = -8,
//    SERVICE_SELL_ART_XP = -7,
//    SERVICE_SELL_GOLD = -6,
//    SERVICE_CHANGE_NAME = -5,
//    SERVICE_CHANGE_GENDER = -4,
//    SERVICE_CHANGE_FACTION = -3,
//    SERVICE_CHANGE_RACE = -2,
//    SERVICE_LEVEL_UP = -1,
//};
//
//std::string getBalansInfo(Player* player)
//{
//    std::ostringstream str1;
//    uint32 balans = player->GetDonateTokens();
//
//    if (sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS)) // if test, then free donate
//        balans = 10000;
//
//    if (sWorld->getBoolConfig(CONFIG_ARGUSWOW_ENABLE))
//    {
//        if (player->GetSession()->GetSessionDbLocaleIndex() == 8) // rus
//        {
//            str1 << "Ваш баланс: " << balans;
//
//            if (balans % 100 > 10 && balans % 100 < 20)
//                str1 << " коинов";
//            else if (balans % 10 == 1)
//                str1 << " коин";
//            else if (balans % 10 >= 2 && balans % 10 <= 4)
//                str1 << " коина";
//            else
//                str1 << " коинов";
//        }
//        else
//            str1 << "Your balance: " << balans << " coin";
//    }
//    else
//    {
//        if (player->GetSession()->GetSessionDbLocaleIndex() == 8) // rus
//        {
//            str1 << "Ваш баланс: " << balans;
//
//            if (balans % 100 > 10 && balans % 100 < 20)
//                str1 << " токенов";
//            else if (balans % 10 == 1)
//                str1 << " токен";
//            else if (balans % 10 >= 2 && balans % 10 <= 4)
//                str1 << " токена";
//            else
//                str1 << " токенов";
//        }
//        else
//            str1 << "Your balance: " << balans << " token";
//    }
//
//    return str1.str();
//}
//
//std::string getDiscontsInfo(LocaleConstant& localeConstant)
//{
//    char discounts[500]{};
//    float rate = (sObjectMgr->GetDonateDiscount() == 0 ? 1.0f : sObjectMgr->GetDonateDiscount());
//    if (rate != 1.0f)
//    {
//        float disc = (1 - rate) * 100;
//        sprintf(discounts, sObjectMgr->GetTrinityString(20036, localeConstant), disc);
//    }
//    return std::string(discounts);
//}
//
//class multi_vendor : public CreatureScript
//{
//public:
//    multi_vendor() : CreatureScript("multi_vendor") {}
//
//    bool OnGossipHello(Player* player, Creature* creature)  override
//    {
//        if (!sObjectMgr->IsActivateDonateService())
//            return false;
//
//        LocaleConstant localeConstant = player->GetSession()->GetSessionDbLocaleIndex();
//
//        if (!getDiscontsInfo(localeConstant).empty())
//            player->ADD_GOSSIP_ITEM(5, getDiscontsInfo(localeConstant), GOSSIP_SENDER_MAIN, 3001);
//
//
//        char printinfo[500]; // Max length
//
//        player->ADD_GOSSIP_ITEM(5, getBalansInfo(player), GOSSIP_SENDER_MAIN, 3001);
//
//        // QueryResult check_service = LoginDatabase.PQuery("SELECT `sp`.`item`, `spr`.`token` FROM `store_products` AS sp LEFT JOIN `store_product_realms` AS spr ON `spr`.`product` = `sp`.`id` WHERE `sp`.`enable` = '1' AND `spr`.`realm` = '%u' AND `spr`.`enable` = 1 and `sp`.`category` = '-1'", realm.Id.Realm); // check service
//
//        VendorItemData const* vendorItems = sObjectMgr->GetNpcDonateVendorItemList(-1);
//        if (vendorItems)
//        {
//            for (uint8 slot = 0; slot < vendorItems->GetItemCount(); ++slot)
//            {
//                VendorItem const* vendorItem = vendorItems->GetItem(slot);
//                if (!vendorItem)
//                    continue;
//
//                int32 id = vendorItem->item;
//                int32 cost = vendorItem->DonateCost;
//
//                switch (id)
//                {
//                case SERVICE_GUILD_RENAME:
//                    sprintf(printinfo, sObjectMgr->GetTrinityString(20089, localeConstant), cost);
//                    player->ADD_GOSSIP_ITEM_EXTENDED(0, printinfo, GOSSIP_SENDER_MAIN, RENAME_GUILD, sObjectMgr->GetTrinityString(20039, localeConstant), 0, false);
//                    break;
//                case SERVICE_SELL_ADD_BONUS:
//                    player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20060, localeConstant), GOSSIP_SENDER_MAIN, ADD_BONUS); // addition bonusses
//                    break;
//                case SERVICE_SELL_ART_XP:
//                    player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20044, localeConstant), GOSSIP_SENDER_MAIN, ART_LEVEL_UP); // art
//                    break;
//                case SERVICE_SELL_GOLD:
//                    sprintf(printinfo, sObjectMgr->GetTrinityString(20045, localeConstant), cost);
//                    player->ADD_GOSSIP_ITEM_EXTENDED(0, printinfo, GOSSIP_SENDER_MAIN, 3005, sObjectMgr->GetTrinityString(20046, localeConstant), 0, true); // gold
//                    break;
//                case SERVICE_CHANGE_NAME:
//                    sprintf(printinfo, sObjectMgr->GetTrinityString(20035, localeConstant), cost);
//                    player->ADD_GOSSIP_ITEM_EXTENDED(0, printinfo, GOSSIP_SENDER_MAIN, CHANGE_NAME, sObjectMgr->GetTrinityString(20039, localeConstant), 0, false);
//                    break;
//                case SERVICE_CHANGE_GENDER:
//                    sprintf(printinfo, sObjectMgr->GetTrinityString(20005, localeConstant), cost);
//                    player->ADD_GOSSIP_ITEM_EXTENDED(0, printinfo, GOSSIP_SENDER_MAIN, CHANGE_GENDER, sObjectMgr->GetTrinityString(20039, localeConstant), 0, false);
//                    break;
//                case SERVICE_CHANGE_FACTION:
//                    sprintf(printinfo, sObjectMgr->GetTrinityString(20003, localeConstant), cost);
//                    player->ADD_GOSSIP_ITEM_EXTENDED(0, printinfo, GOSSIP_SENDER_MAIN, CHANGE_FACTION, sObjectMgr->GetTrinityString(20039, localeConstant), 0, false);
//                    break;
//                case SERVICE_CHANGE_RACE:
//                    sprintf(printinfo, sObjectMgr->GetTrinityString(20004, localeConstant), cost);
//                    player->ADD_GOSSIP_ITEM_EXTENDED(0, printinfo, GOSSIP_SENDER_MAIN, CHANGE_RACE, sObjectMgr->GetTrinityString(20039, localeConstant), 0, false);
//                    break;
//                case SERVICE_LEVEL_UP:
//                    player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20032, localeConstant), GOSSIP_SENDER_MAIN, LEVEL_UP);
//                    break;
//                default:
//                    break;
//                }
//            }
//        }
//
//        player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20010, localeConstant), GOSSIP_SENDER_MAIN, 3001);
//        player->SEND_GOSSIP_MENU(100006, creature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)  override
//    {
//        if (!player || !creature || !player->getAttackers()->empty())
//            return true;
//
//        if (player->InBattlegroundQueue())
//        {
//            ChatHandler(player).PSendSysMessage("You should leave from battleground queue.");
//            return true;
//        }
//
//        float rate = (sObjectMgr->GetDonateDiscount() == 0 ? 1.0f : sObjectMgr->GetDonateDiscount());
//        if (sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS)) // if test, then free donate
//            rate = 0;
//
//        uint32 priceFaction = uint32(400 * rate);
//        uint32 priceName = uint32(200 * rate);
//        uint32 priceRace = uint32(300 * rate);
//        uint32 priceGender = uint32(200 * rate);
//        uint32 priceRecobery = uint32(450 * rate);
//
//        VendorItemData const* vendorItems = sObjectMgr->GetNpcDonateVendorItemList(-1);
//        if (vendorItems)
//        {
//            for (uint8 slot = 0; slot < vendorItems->GetItemCount(); ++slot)
//            {
//                VendorItem const* vendorItem = vendorItems->GetItem(slot);
//                if (!vendorItem)
//                    continue;
//
//                int32 id = vendorItem->item;
//                int32 cost = vendorItem->DonateCost;
//
//                if (id == SERVICE_CHANGE_FACTION)
//                    priceFaction = cost;
//                else if (id == SERVICE_CHANGE_RACE)
//                    priceRace = cost;
//                else if (id == SERVICE_CHANGE_GENDER)
//                    priceGender = cost;
//                else if (id == SERVICE_CHANGE_NAME)
//                    priceName = cost;
//            }
//        }
//        uint32 accountId = player->GetSession()->GetAccountId();
//        LocaleConstant localeConstant = player->GetSession()->GetSessionDbLocaleIndex();
//        if (accountId < 1)
//            return true;
//
//        auto activate = false;
//        auto chH = ChatHandler(player);
//
//        switch (sender)
//        {
//        case GOSSIP_SENDER_MAIN:
//        {
//            switch (action)
//            {
//            case CHANGE_FACTION: // 64
//            {
//                QueryResult result = CharacterDatabase.PQuery("SELECT at_login FROM characters where guid = %u", player->GetGUID().GetCounter());
//                if (result)
//                {
//                    Field* fields = result->Fetch();
//                    uint32 flags = fields[0].GetUInt32();
//                    if (flags & AT_LOGIN_CHANGE_FACTION) // if  faction
//                    {
//                        chH.PSendSysMessage(20034);
//                        player->CLOSE_GOSSIP_MENU();
//                        break;
//                    }
//                }
//                else
//                {
//                    chH.PSendSysMessage(20034);
//                    player->CLOSE_GOSSIP_MENU();
//                    break;
//                }
//
//                if (!sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//                {
//                    if (player->DestroyDonateTokenCount(priceFaction))
//                    {
//                        player->UpdateDonateStatistics(SERVICE_CHANGE_FACTION);
//                        uint8 index = 0;
//                        SQLTransaction trans = LoginDatabase.BeginTransaction();
//                        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_STORE_ADD_ITEM_LOG_SERVICE);
//                        stmt->setUInt32(index, realm.Id.Realm);
//                        stmt->setUInt32(++index, player->GetSession()->GetAccountId());
//                        stmt->setUInt32(++index, player->GetSession()->GetBattlenetAccountId()); // select battlenet_account from account where id = %u
//                        stmt->setUInt64(++index, player->GetGUIDLow());
//                        stmt->setUInt64(++index, 0); // item_guid
//                        stmt->setInt32(++index, SERVICE_CHANGE_FACTION); // item entry
//                        stmt->setUInt32(++index, 1); // item count
//                        stmt->setInt64(++index, priceFaction); // cost
//                        stmt->setUInt32(++index, player->getLevel()); // level
//                        stmt->setInt32(++index, SERVICE_CHANGE_FACTION); // item entry
//
//                        trans->Append(stmt);
//                        LoginDatabase.CommitTransaction(trans);
//                        TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Service] Type: %d, cost = %u %s", SERVICE_CHANGE_FACTION, priceFaction, player->GetInfoForDonate().c_str());
//                    }
//                    else
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        break;
//                    }
//                }
//                //  LoginDatabase.PExecute("INSERT INTO `store_history` (`realm`, `account`, `bnet_account`, `char_guid`, `char_level`, `product`, `count`, `token`) VALUES (%u, %u, %u, %u, %u, %u, %u, %u);", realm.Id.Realm, player->GetSession()->GetAccountId(), player->GetSession()->GetBattlenetAccountId(), player->GetGUID().GetCounter(), player->getLevel(), -3, 1, priceFaction);
//                sCharacterService->ChangeFaction(player);
//
//                activate = true;
//                player->SaveToDB();
//                player->CLOSE_GOSSIP_MENU();
//                break;
//            }
//            case CHANGE_RACE: // 128
//            {
//                QueryResult result = CharacterDatabase.PQuery("SELECT at_login FROM characters where guid = %u", player->GetGUID().GetCounter());
//                if (result)
//                {
//                    Field* fields = result->Fetch();
//                    uint32 flags = fields[0].GetUInt32();
//                    if (flags & AT_LOGIN_CHANGE_RACE || flags & AT_LOGIN_CHANGE_FACTION) // if race or faction
//                    {
//                        chH.PSendSysMessage(20034);
//                        player->CLOSE_GOSSIP_MENU();
//                        break;
//                    }
//                }
//                else
//                {
//                    chH.PSendSysMessage(20034);
//                    player->CLOSE_GOSSIP_MENU();
//                    break;
//                }
//
//                if (!sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//                {
//                    if (player->DestroyDonateTokenCount(priceRace))
//                    {
//                        player->UpdateDonateStatistics(SERVICE_CHANGE_RACE);
//                        uint8 index = 0;
//                        SQLTransaction trans = LoginDatabase.BeginTransaction();
//                        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_STORE_ADD_ITEM_LOG_SERVICE);
//                        stmt->setUInt32(index, realm.Id.Realm);
//                        stmt->setUInt32(++index, player->GetSession()->GetAccountId());
//                        stmt->setUInt32(++index, player->GetSession()->GetBattlenetAccountId()); // select battlenet_account from account where id = %u
//                        stmt->setUInt64(++index, player->GetGUIDLow());
//                        stmt->setUInt64(++index, 0); // item_guid
//                        stmt->setInt32(++index, SERVICE_CHANGE_RACE); // item entry
//                        stmt->setUInt32(++index, 1); // item count
//                        stmt->setInt64(++index, priceRace); // cost
//                        stmt->setUInt32(++index, player->getLevel()); // level
//                        stmt->setInt32(++index, SERVICE_CHANGE_RACE); // item entry
//
//                        trans->Append(stmt);
//                        LoginDatabase.CommitTransaction(trans);
//                        TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Service] Type: %d, cost = %u %s", SERVICE_CHANGE_RACE, priceRace, player->GetInfoForDonate().c_str());
//                    }
//                    else
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        break;
//                    }
//                }
//
//                //   LoginDatabase.PExecute("INSERT INTO `store_history` (`realm`, `account`, `bnet_account`, `char_guid`, `char_level`, `product`, `count`, `token`) VALUES (%u, %u, %u, %u, %u, %u, %u, %u);", realm.Id.Realm, player->GetSession()->GetAccountId(), player->GetSession()->GetBattlenetAccountId(), player->GetGUID().GetCounter(), player->getLevel(), -2, 1, priceRace);
//                sCharacterService->ChangeRace(player);
//
//                activate = true;
//                player->SaveToDB();
//                player->CLOSE_GOSSIP_MENU();
//                break;
//            }
//            case CHANGE_GENDER: // 8
//            {
//                QueryResult result = CharacterDatabase.PQuery("SELECT at_login FROM characters where guid = %u", player->GetGUID().GetCounter());
//                if (result)
//                {
//                    Field* fields = result->Fetch();
//                    uint32 flags = fields[0].GetUInt32();
//                    if (flags & AT_LOGIN_CUSTOMIZE || flags & AT_LOGIN_CHANGE_FACTION || flags & AT_LOGIN_CHANGE_RACE) // if gender of faction or race
//                    {
//                        chH.PSendSysMessage(20034);
//                        player->CLOSE_GOSSIP_MENU();
//                        break;
//                    }
//                }
//                else
//                {
//                    chH.PSendSysMessage(20034);
//                    player->CLOSE_GOSSIP_MENU();
//                    break;
//                }
//
//                if (!sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//                {
//                    if (player->DestroyDonateTokenCount(priceGender))
//                    {
//                        player->UpdateDonateStatistics(SERVICE_CHANGE_GENDER);
//                        SQLTransaction trans = LoginDatabase.BeginTransaction();
//                        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_STORE_ADD_ITEM_LOG_SERVICE);
//                        uint8 index = 0;
//                        stmt->setUInt32(index, realm.Id.Realm);
//                        stmt->setUInt32(++index, player->GetSession()->GetAccountId());
//                        stmt->setUInt32(++index, player->GetSession()->GetBattlenetAccountId()); // select battlenet_account from account where id = %u
//                        stmt->setUInt64(++index, player->GetGUIDLow());
//                        stmt->setUInt64(++index, 0); // item_guid
//                        stmt->setInt32(++index, SERVICE_CHANGE_GENDER); // item entry
//                        stmt->setUInt32(++index, 1); // item count
//                        stmt->setInt64(++index, priceGender); // cost
//                        stmt->setUInt32(++index, player->getLevel()); // level
//                        stmt->setInt32(++index, SERVICE_CHANGE_GENDER); // item entry
//
//                        trans->Append(stmt);
//                        LoginDatabase.CommitTransaction(trans);
//                        TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Service] Type: %d, cost = %u %s", SERVICE_CHANGE_GENDER, priceGender, player->GetInfoForDonate().c_str());
//                    }
//                    else
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        break;
//                    }
//                }
//
//                // LoginDatabase.PExecute("INSERT INTO `store_history` (`realm`, `account`, `bnet_account`, `char_guid`, `char_level`, `product`, `count`, `token`) VALUES (%u, %u, %u, %u, %u, %u, %u, %u);", realm.Id.Realm, player->GetSession()->GetAccountId(), player->GetSession()->GetBattlenetAccountId(), player->GetGUID().GetCounter(), player->getLevel(), -4, 1, priceGender);
//                sCharacterService->Customize(player);
//
//                activate = true;
//                player->SaveToDB();
//                player->CLOSE_GOSSIP_MENU();
//                break;
//            }
//            case CHANGE_NAME: // 1
//            {
//                QueryResult result = CharacterDatabase.PQuery("SELECT at_login FROM characters where guid = %u", player->GetGUID().GetCounter());
//                if (result)
//                {
//                    Field* fields = result->Fetch();
//                    uint32 flags = fields[0].GetUInt32();
//                    if (flags & AT_LOGIN_RENAME || flags & AT_LOGIN_CHANGE_FACTION || flags & AT_LOGIN_CHANGE_RACE || flags & AT_LOGIN_CUSTOMIZE) // if name or race or faction or gender
//                    {
//                        chH.PSendSysMessage(20034);
//                        player->CLOSE_GOSSIP_MENU();
//                        break;
//                    }
//                }
//                else
//                {
//                    chH.PSendSysMessage(20034);
//                    player->CLOSE_GOSSIP_MENU();
//                    break;
//                }
//
//                if (!sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//                {
//                    if (player->DestroyDonateTokenCount(priceName))
//                    {
//                        player->UpdateDonateStatistics(SERVICE_CHANGE_NAME);
//                        SQLTransaction trans = LoginDatabase.BeginTransaction();
//                        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_STORE_ADD_ITEM_LOG_SERVICE);
//                        uint8 index = 0;
//                        stmt->setUInt32(index, realm.Id.Realm);
//                        stmt->setUInt32(++index, player->GetSession()->GetAccountId());
//                        stmt->setUInt32(++index, player->GetSession()->GetBattlenetAccountId()); // select battlenet_account from account where id = %u
//                        stmt->setUInt64(++index, player->GetGUIDLow());
//                        stmt->setUInt64(++index, 0); // item_guid
//                        stmt->setInt32(++index, SERVICE_CHANGE_NAME); // item entry
//                        stmt->setUInt32(++index, 1); // item count
//                        stmt->setInt64(++index, priceName); // cost
//                        stmt->setUInt32(++index, player->getLevel()); // level
//                        stmt->setInt32(++index, SERVICE_CHANGE_NAME); // item entry
//
//                        trans->Append(stmt);
//                        LoginDatabase.CommitTransaction(trans);
//                        TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Service] Type: %d, cost = %u %s", SERVICE_CHANGE_NAME, priceName, player->GetInfoForDonate().c_str());
//                    }
//                    else
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        break;
//                    }
//                }
//
//                // LoginDatabase.PExecute("INSERT INTO `store_history` (`realm`, `account`, `bnet_account`, `char_guid`, `char_level`, `product`, `count`, `token`) VALUES (%u, %u, %u, %u, %u, %u, %u, %u);", realm.Id.Realm, player->GetSession()->GetAccountId(), player->GetSession()->GetBattlenetAccountId(), player->GetGUID().GetCounter(), player->getLevel(), -4, 1, priceGender);
//
//                sCharacterService->SetRename(player);
//
//                activate = true;
//                player->SaveToDB();
//                player->CLOSE_GOSSIP_MENU();
//                break;
//            }
//            case LEVEL_UP:
//            {
//                player->PlayerTalkClass->ClearMenus();
//                if (player->getLevel() < 100)
//                    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityString(30100, localeConstant), GOSSIP_SENDER_MAIN, 3003, sObjectMgr->GetTrinityString(20040, localeConstant), 0, true); // level
//
//                player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityString(30104, localeConstant), GOSSIP_SENDER_MAIN, 3004, sObjectMgr->GetTrinityString(20040, localeConstant), 0, true); // calculate
//                player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(30102, localeConstant), GOSSIP_SENDER_MAIN, 3001); // exit
//                player->SEND_GOSSIP_MENU(100005, creature->GetGUID());
//                return true;
//            }
//            break;
//            case ART_LEVEL_UP:
//            {
//                player->PlayerTalkClass->ClearMenus();
//                player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityString(30100, localeConstant), GOSSIP_SENDER_MAIN, 3007, sObjectMgr->GetTrinityString(20040, localeConstant), 0, true); // level
//
//                player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityString(30104, localeConstant), GOSSIP_SENDER_MAIN, 3006, sObjectMgr->GetTrinityString(20040, localeConstant), 0, true); // calculate
//                player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(30102, localeConstant), GOSSIP_SENDER_MAIN, 3001); // exit
//                player->SEND_GOSSIP_MENU(100007, creature->GetGUID());
//                return true;
//            }
//            break;
//            case ADD_BONUS:
//            {
//                player->PlayerTalkClass->ClearMenus();
//
//                // QueryResult result_price = LoginDatabase.PQuery("SELECT level, token FROM `store_level_prices` WHERE realm = %u and type = 2", sWorld->GetRealmId());
//
//                if (sObjectMgr->GetPricesForAddBonus())
//                {
//                    PriceForAddBonus const* price = sObjectMgr->GetPricesForAddBonus();
//                    char namebonus[500], question[500];
//                    Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);
//                    if (!pItem)
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        chH.PSendSysMessage(20057);
//                        // return false;
//                    }
//
//                    ItemTemplate const* pProto = pItem ? pItem->GetTemplate() : nullptr;
//                    for (auto itr = price->begin(); itr != price->end(); ++itr)
//                    {
//                        uint32 bonus = (*itr).first;
//                        uint32 tcost = (*itr).second;
//
//                        { // check, that we can add this bonus
//                            std::vector<uint32> bonusVec{ bonus };
//
//                            if (pProto)
//                                sObjectMgr->DeleteBugBonus(bonusVec, pProto->HasEnchantment(), pProto->GetQuality() < ITEM_QUALITY_LEGENDARY, pProto->HasStats());
//
//                            if (bonusVec.empty())
//                                continue;
//                        }
//
//                        switch (bonus)
//                        {
//                        case 42: // Скорость передвижения
//                            sprintf(namebonus, sObjectMgr->GetTrinityString(20052, localeConstant), tcost);
//                            sprintf(question, sObjectMgr->GetTrinityString(20064, localeConstant), namebonus,
//                                (pProto ? pProto->GetName()->Str[localeConstant] : "Item not found"));
//                            player->ADD_GOSSIP_ITEM_EXTENDED(0, namebonus, GOSSIP_SENDER_MAIN, 3002, question, 0, false);
//                            break;
//                        case 43: // Неразрушимый
//                            sprintf(namebonus, sObjectMgr->GetTrinityString(20053, localeConstant), tcost);
//                            sprintf(question, sObjectMgr->GetTrinityString(20064, localeConstant), namebonus,
//                                (pProto ? pProto->GetName()->Str[localeConstant] : "Item not found"));
//                            player->ADD_GOSSIP_ITEM_EXTENDED(0, namebonus, GOSSIP_SENDER_MAIN, 3003, question, 0, false);
//                            break;
//                        case 41: // Самоисцеление
//                            sprintf(namebonus, sObjectMgr->GetTrinityString(20054, localeConstant), tcost);
//                            sprintf(question, sObjectMgr->GetTrinityString(20064, localeConstant), namebonus,
//                                (pProto ? pProto->GetName()->Str[localeConstant] : "Item not found"));
//                            player->ADD_GOSSIP_ITEM_EXTENDED(0, namebonus, GOSSIP_SENDER_MAIN, 3004, question, 0, false);
//                            break;
//                        case 40: // Уклонение
//                            sprintf(namebonus, sObjectMgr->GetTrinityString(20055, localeConstant), tcost);
//                            sprintf(question, sObjectMgr->GetTrinityString(20064, localeConstant), namebonus,
//                                (pProto ? pProto->GetName()->Str[localeConstant] : "Item not found"));
//                            player->ADD_GOSSIP_ITEM_EXTENDED(0, namebonus, GOSSIP_SENDER_MAIN, 3005, question, 0, false);
//                            break;
//                        case 1808: // Бесцветное гнездо
//                            sprintf(namebonus, sObjectMgr->GetTrinityString(20056, localeConstant), tcost);
//                            sprintf(question, sObjectMgr->GetTrinityString(20064, localeConstant), namebonus,
//                                (pProto ? pProto->GetName()->Str[localeConstant] : "Item not found"));
//                            player->ADD_GOSSIP_ITEM_EXTENDED(0, namebonus, GOSSIP_SENDER_MAIN, 3006, question, 0, false);
//                            break;
//                        default:
//                            break;
//                        }
//                    };
//
//                    if (pItem)
//                    {
//                        QueryResult result_donate = LoginDatabase.PQuery("SELECT bonus FROM `store_history` WHERE realm = %u and product = (select `id` from `store_products` where `item` = %d) and account = %u and bnet_account = %u and char_guid = %u and item_guid = %u and item = %u and status = 0", sWorld->GetRealmId(), SERVICE_SELL_ADD_BONUS, player->GetSession()->GetAccountId(), player->GetSession()->GetBattlenetAccountId(), player->GetGUIDLow(), pItem->GetGUIDLow(), pItem->GetEntry());
//                        if (result_donate)
//                        {
//                            //char namebonus[500], question[500];
//                            sprintf(namebonus, sObjectMgr->GetTrinityString(20070, localeConstant), (pProto ? pProto->GetName()->Str[localeConstant] : "Item not found"));
//                            player->ADD_GOSSIP_ITEM(1, namebonus, GOSSIP_SENDER_MAIN, 3001); // exit
//                            sprintf(question, sObjectMgr->GetTrinityString(20071, localeConstant), (pProto ? pProto->GetName()->Str[localeConstant] : "Item not found"));
//                            do
//                            {
//
//                                Field* fields = result_donate->Fetch();
//                                const char* bonusstr = fields[0].GetCString();
//
//                                uint32 bonus = atoi(bonusstr);
//                                switch (bonus)
//                                {
//                                case 42: // Скорость передвижения
//                                    player->ADD_GOSSIP_ITEM_EXTENDED(1, sObjectMgr->GetTrinityString(20072, localeConstant), GOSSIP_SENDER_MAIN, 3012, question, 0, false);
//                                    break;
//                                    // case 43: // Неразрушимый
//                                        // player->ADD_GOSSIP_ITEM_EXTENDED(0, namebonus, GOSSIP_SENDER_MAIN, 3013, question, 0, false);
//                                        // break;
//                                case 41: // Самоисцеление
//                                    player->ADD_GOSSIP_ITEM_EXTENDED(1, sObjectMgr->GetTrinityString(20074, localeConstant), GOSSIP_SENDER_MAIN, 3014, question, 0, false);
//                                    break;
//                                case 40: // Уклонение
//                                    player->ADD_GOSSIP_ITEM_EXTENDED(1, sObjectMgr->GetTrinityString(20075, localeConstant), GOSSIP_SENDER_MAIN, 3015, question, 0, false);
//                                    break;
//                                    // case 1808: // Бесцветное гнездо
//                                        // player->ADD_GOSSIP_ITEM_EXTENDED(0, namebonus, GOSSIP_SENDER_MAIN, 3016, question, 0, false);
//                                        // break;
//                                default:
//                                    break;
//                                }
//                            } while (result_donate->NextRow());
//                        }
//                    }
//                }
//
//                player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(30102, localeConstant), GOSSIP_SENDER_MAIN, 3001); // exit
//                player->SEND_GOSSIP_MENU(100008, creature->GetGUID());
//                return true;
//            }
//            break;
//
//            // add bonus
//            case 3002:
//            case 3003:
//            case 3004:
//            case 3005:
//            case 3006:
//            {
//
//                uint32 IdBonus = 0;
//                switch (action)
//                {
//                case 3002: // Скорость передвижения
//                    IdBonus = 42;
//                    break;
//                case 3003: // Неразрушимый
//                    IdBonus = 43;
//                    break;
//                case 3004: // Самоисцеление
//                    IdBonus = 41;
//                    break;
//                case 3005: // Уклонение
//                    IdBonus = 40;
//                    break;
//                case 3006: // Гнездо
//                    IdBonus = 1808;
//                    break;
//                default:
//                    break;
//                }
//
//                if (!IdBonus)
//                {
//                    player->CLOSE_GOSSIP_MENU();
//                    return false;
//                }
//
//                Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);
//                if (!pItem)
//                {
//                    player->CLOSE_GOSSIP_MENU();
//                    chH.PSendSysMessage(20057);
//                    return false;
//                }
//                uint8 msg = player->CanUseItem(pItem);
//                if (msg != EQUIP_ERR_OK)
//                {
//                    player->CLOSE_GOSSIP_MENU();
//                    player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//                    return false;
//                }
//
//                if (ItemTemplate const* proto = pItem->GetTemplate())
//                {
//                    if (proto->GetClass() != ITEM_CLASS_ARMOR || proto->GetQuality() == ITEM_QUALITY_LEGENDARY)
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//                        return false;
//                    }
//                    if (proto->GetBaseRequiredLevel() < 101)
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        player->SendEquipError(EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED, NULL, NULL);
//                        return false;
//                    }
//
//                    // check, that we can add this bonus
//                    std::vector<uint32> bonusVec{ IdBonus };
//                    if (proto)
//                        sObjectMgr->DeleteBugBonus(bonusVec, proto->HasEnchantment(), proto->GetQuality() < ITEM_QUALITY_LEGENDARY, proto->HasStats());
//
//                    if (bonusVec.empty())
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//                        return false;
//                    }
//
//                }
//
//                for (uint32 bonusListID : pItem->GetDynamicValues(ITEM_DYNAMIC_FIELD_BONUS_LIST_IDS))
//                {
//                    if (bonusListID == IdBonus)
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        chH.PSendSysMessage(20058);
//                        return false;
//                    }
//
//                    if (IdBonus != 1808 && IdBonus != 43) // check for use only one from main stats
//                    {
//                        if (bonusListID == 42 || bonusListID == 41 || bonusListID == 40)
//                        {
//                            player->CLOSE_GOSSIP_MENU();
//                            chH.PSendSysMessage(20061);
//                            return false;
//                        }
//                    }
//                }
//
//                if (!sObjectMgr->GetPricesForAddBonus())
//                {
//                    player->CLOSE_GOSSIP_MENU();
//                    return false;
//                }
//
//                PriceForAddBonus const* price = sObjectMgr->GetPricesForAddBonus();
//                auto itr = price->find(IdBonus);
//                if (itr == price->end())
//                {
//                    player->CLOSE_GOSSIP_MENU();
//                    return false;
//                }
//
//                uint32 tcost = (*itr).second;
//                if (player->HasDonateToken(tcost))
//                {
//                    if (!sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//                    {
//                        if (player->DestroyDonateTokenCount(tcost))
//                        {
//                            player->UpdateDonateStatistics(SERVICE_SELL_ADD_BONUS);
//                            uint8 index = 0;
//                            SQLTransaction trans = LoginDatabase.BeginTransaction();
//                            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_STORE_ADD_ITEM_LOG_BONUS);
//                            stmt->setUInt32(index, realm.Id.Realm);
//                            stmt->setUInt32(++index, player->GetSession()->GetAccountId());
//                            stmt->setUInt32(++index, player->GetSession()->GetBattlenetAccountId()); // select battlenet_account from account where id = %u
//                            stmt->setUInt64(++index, player->GetGUIDLow());
//                            stmt->setUInt64(++index, pItem->GetGUIDLow()); // item_guid
//                            stmt->setUInt32(++index, pItem->GetEntry()); // item entry
//                            stmt->setUInt32(++index, 1); // item count
//                            stmt->setInt64(++index, tcost); // cost
//                            stmt->setUInt32(++index, player->getLevel()); // level
//                            stmt->setInt32(++index, SERVICE_SELL_ADD_BONUS); // donate Store id
//                            stmt->setInt32(++index, IdBonus); // bonus
//
//                            trans->Append(stmt);
//                            LoginDatabase.CommitTransaction(trans);
//                            TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Service] Type: %d, cost = %u, itemguid = %u, itemid = %u, bonus = %u,  %s", SERVICE_SELL_ADD_BONUS, tcost, pItem->GetGUIDLow(), pItem->GetEntry(), IdBonus, player->GetInfoForDonate().c_str());
//                        }
//                        else
//                        {
//                            player->CLOSE_GOSSIP_MENU();
//                            break;
//                        }
//                    }
//                    pItem->AddBonuses(IdBonus);
//                    pItem->SetState(ITEM_CHANGED, player);
//                    chH.PSendSysMessage(20059);
//                    player->SaveToDB();
//                }
//                else
//                    chH.PSendSysMessage(20000, tcost);
//
//                player->CLOSE_GOSSIP_MENU();
//                return true;
//            }
//            break;
//            // delete bonus
//            case 3012:
//                // case 3013:
//            case 3014:
//            case 3015:
//                // case 3016:
//            {
//
//                uint32 IdBonus = 0;
//                switch (action)
//                {
//                case 3012: // Скорость передвижения
//                    IdBonus = 42;
//                    break;
//                    // case 3013: // Неразрушимый
//                        // IdBonus = 43;
//                        // break;
//                case 3014: // Самоисцеление
//                    IdBonus = 41;
//                    break;
//                case 3015: // Уклонение
//                    IdBonus = 40;
//                    break;
//                    // case 3016: // Гнездо
//                        // IdBonus = 1808;
//                        // break;
//                default:
//                    break;
//                }
//
//                if (!IdBonus)
//                {
//                    player->CLOSE_GOSSIP_MENU();
//                    return false;
//                }
//
//                Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);
//                if (!pItem)
//                {
//                    player->CLOSE_GOSSIP_MENU();
//                    chH.PSendSysMessage(20057);
//                    return false;
//                }
//                uint8 msg = player->CanUseItem(pItem);
//                if (msg != EQUIP_ERR_OK)
//                {
//                    player->CLOSE_GOSSIP_MENU();
//                    player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//                    return false;
//                }
//
//                if (ItemTemplate const* proto = pItem->GetTemplate())
//                {
//                    if (proto->GetClass() != ITEM_CLASS_ARMOR || proto->GetQuality() == ITEM_QUALITY_LEGENDARY)
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//                        return false;
//                    }
//                    if (proto->GetBaseRequiredLevel() < 101)
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        player->SendEquipError(EQUIP_ERR_SCALING_STAT_ITEM_LEVEL_EXCEEDED, NULL, NULL);
//                        return false;
//                    }
//                }
//
//                bool find = false;
//                std::vector<uint32> new_bonus;
//                for (uint32 bonusListID : pItem->GetDynamicValues(ITEM_DYNAMIC_FIELD_BONUS_LIST_IDS))
//                {
//                    if (bonusListID == IdBonus)
//                        find = true;
//                    else
//                        new_bonus.push_back(bonusListID);
//                }
//
//                if (!find)
//                {
//                    chH.PSendSysMessage(20077);
//                    return false;
//                }
//
//                // some magic with delete one bonus
//                pItem->ClearDynamicValue(ITEM_DYNAMIC_FIELD_BONUS_LIST_IDS);
//                pItem->_bonusData.Initialize(pItem->GetTemplate());
//
//                for (uint32 bonusID : new_bonus)
//                    pItem->AddBonuses(bonusID);
//
//                pItem->SetState(ITEM_CHANGED, player);
//
//                player->SaveToDB();
//
//                LoginDatabase.PExecute("UPDATE `store_history` set status = 7 WHERE realm = %u and product = (select `id` from `store_products` where `item` = %d) and account = %u and bnet_account = %u and char_guid = %u and item_guid = %u and item = %u and status = 0", sWorld->GetRealmId(), SERVICE_SELL_ADD_BONUS, player->GetSession()->GetAccountId(), player->GetSession()->GetBattlenetAccountId(), player->GetGUIDLow(), pItem->GetGUIDLow(), pItem->GetEntry());
//
//                chH.PSendSysMessage(20078);
//                player->CLOSE_GOSSIP_MENU();
//                return true;
//            }
//            break;
//            case RENAME_GUILD:
//            {
//                Guild* guild = player->GetGuild();
//                if (!guild)
//                {
//                    player->CLOSE_GOSSIP_MENU();
//                    Guild::SendCommandResult(player->GetSession(), GUILD_PROMOTE_SS, ERR_GUILD_PLAYER_NOT_IN_GUILD);
//                    return false;
//                }
//
//                if (guild->GetLeaderGUID() != player->GetGUID())
//                {
//                    Guild::SendCommandResult(player->GetSession(), GUILD_PROMOTE_SS, ERR_GUILD_PERMISSIONS);
//                    player->CLOSE_GOSSIP_MENU();
//                    return false;
//                }
//
//                if (guild->IsFlaggedForRename())
//                {
//                    chH.PSendSysMessage("You just buyed it");
//                    player->CLOSE_GOSSIP_MENU();
//                    return false;
//                }
//
//                VendorItemData const* vendorItems = sObjectMgr->GetNpcDonateVendorItemList(-1);
//                if (!vendorItems)
//                {
//                    chH.PSendSysMessage(20038);
//                    player->CLOSE_GOSSIP_MENU();
//                    return false;
//                }
//
//                uint32 cost = 0;
//                for (uint8 slot = 0; slot < vendorItems->GetItemCount(); ++slot)
//                {
//                    VendorItem const* vendorItem = vendorItems->GetItem(slot);
//                    if (!vendorItem)
//                        continue;
//
//                    if (vendorItem->item == SERVICE_GUILD_RENAME)
//                    {
//                        cost = vendorItem->DonateCost;
//                        break;
//                    }
//                }
//
//                if (!player->HasDonateToken(cost))
//                {
//                    chH.PSendSysMessage(20000, cost);
//                    player->CLOSE_GOSSIP_MENU();
//                    return false;
//                }
//
//                if (!sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//                {
//                    if (player->DestroyDonateTokenCount(cost))
//                    {
//                        player->UpdateDonateStatistics(SERVICE_GUILD_RENAME);
//                        uint8 index = 0;
//                        SQLTransaction trans = LoginDatabase.BeginTransaction();
//                        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_STORE_ADD_ITEM_LOG_GUILD_RENAME);
//                        stmt->setUInt32(index, realm.Id.Realm);
//                        stmt->setUInt32(++index, player->GetSession()->GetAccountId());
//                        stmt->setUInt32(++index, player->GetSession()->GetBattlenetAccountId()); // select battlenet_account from account where id = %u
//                        stmt->setUInt64(++index, player->GetGUIDLow());
//                        stmt->setUInt64(++index, guild->GetGUID().GetGUIDLow()); // item_guid
//                        stmt->setInt32(++index, SERVICE_GUILD_RENAME); // item entry
//                        stmt->setUInt32(++index, 1); // item count
//                        stmt->setUInt32(++index, cost); // cost
//                        stmt->setUInt32(++index, player->getLevel()); // level
//                        stmt->setInt32(++index, SERVICE_GUILD_RENAME); // item entry
//                        stmt->setString(++index, guild->GetName().c_str()); // item entry
//
//                        trans->Append(stmt);
//                        LoginDatabase.CommitTransaction(trans);
//                        TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Service] Type: %d, cost = %u, buy_levels = %u,  %s", SERVICE_GUILD_RENAME, cost, 1, player->GetInfoForDonate().c_str());
//                        //  LoginDatabase.PExecute("INSERT INTO `store_history` (`realm`, `account`, `bnet_account`, `char_guid`, `char_level`, `product`, `count`, `token`) VALUES (%u, %u, %u, %u, %u, %u, %u, %u);", realm.Id.Realm, player->GetSession()->GetAccountId(), player->GetSession()->GetBattlenetAccountId(), player->GetGUID().GetCounter(), level, -1, ucode, efirendu);
//                    }
//                    else
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        return false;
//                    }
//                }
//
//                guild->SetRename(true);
//
//                player->CLOSE_GOSSIP_MENU();
//                break;
//            }
//            case 3001:
//                player->CLOSE_GOSSIP_MENU();
//                return true;
//            default:
//                break;
//            }
//            break;
//        }
//        default:
//            break;
//        }
//
//        if (activate)
//            chH.PSendSysMessage(LANG_CUSTOMIZE_PLAYER, chH.GetNameLink(player).c_str());
//
//        player->CLOSE_GOSSIP_MENU();
//        return true;
//    }
//
//    bool OnGossipSelectCode(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action, const char* code) override
//    {
//        LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
//        player->PlayerTalkClass->ClearMenus();
//        ChatHandler chH = ChatHandler(player);
//
//        switch (action)
//        {
//        case 3003:
//        case 3004: // level up
//        {
//            if (!code)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//
//            float efir = 0;
//            uint32 ucode = atoi(code);
//            if (!ucode)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//            uint32 level = player->getLevel();
//
//            if (ucode > 100 || ucode <= level)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//
//            for (uint32 i = level + 1; i <= ucode; i++)
//            {
//                if (float const* price = sObjectMgr->GetPriceForLevelUp(i))
//                {
//                    if (price)
//                    {
//                        efir += *price; // how many tokens need for get level i
//                    }
//                    else
//                    {
//                        chH.PSendSysMessage(20038);
//                        player->CLOSE_GOSSIP_MENU();
//                        return false;
//                    }
//                }
//            }
//
//            float efirend = ceil(efir);
//            uint32 efirendu = uint32(efirend);
//            if ((!efirendu || efirendu <= 0) && !sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//            {
//                chH.PSendSysMessage(20038);
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//
//            if (sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//                efirendu = 0;
//
//            // calculate gold with arithmetic progression =)
//            uint32 start_cost = 1;
//            uint32 d = 2;
//            uint32 a1 = start_cost + d * (level);
//            uint32 an = start_cost + d * (ucode - 1);
//            uint64 sum = (a1 + an) * (ucode - level) / 2.; // i hope, that i am smart
//            uint64 gold = sum * 10000;
//            if (action == 3004)
//                chH.PSendSysMessage(30105, ucode, efirendu, sum);
//            else if (action == 3003)
//            {
//                if (player->HasDonateToken(efirendu))
//                {
//                    if (!sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//                    {
//                        if (player->DestroyDonateTokenCount(efirendu))
//                        {
//                            player->UpdateDonateStatistics(SERVICE_LEVEL_UP);
//                            uint8 index = 0;
//                            SQLTransaction trans = LoginDatabase.BeginTransaction();
//                            PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_STORE_ADD_ITEM_LOG_SERVICE);
//                            stmt->setUInt32(index, realm.Id.Realm);
//                            stmt->setUInt32(++index, player->GetSession()->GetAccountId());
//                            stmt->setUInt32(++index, player->GetSession()->GetBattlenetAccountId()); // select battlenet_account from account where id = %u
//                            stmt->setUInt64(++index, player->GetGUIDLow());
//                            stmt->setUInt64(++index, 0); // item_guid
//                            stmt->setInt32(++index, SERVICE_LEVEL_UP); // item entry
//                            stmt->setUInt32(++index, (ucode - level)); // item count
//                            stmt->setUInt32(++index, efirendu); // cost
//                            stmt->setUInt32(++index, level); // level
//                            stmt->setInt32(++index, SERVICE_LEVEL_UP); // item entry
//
//                            trans->Append(stmt);
//                            LoginDatabase.CommitTransaction(trans);
//                            TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Service] Type: %d, cost = %u, buy_levels = %u,  %s", SERVICE_LEVEL_UP, efirendu, (ucode - level), player->GetInfoForDonate().c_str());
//                            //  LoginDatabase.PExecute("INSERT INTO `store_history` (`realm`, `account`, `bnet_account`, `char_guid`, `char_level`, `product`, `count`, `token`) VALUES (%u, %u, %u, %u, %u, %u, %u, %u);", realm.Id.Realm, player->GetSession()->GetAccountId(), player->GetSession()->GetBattlenetAccountId(), player->GetGUID().GetCounter(), level, -1, ucode, efirendu);
//                        }
//                        else
//                        {
//                            player->CLOSE_GOSSIP_MENU();
//                            return false;
//                        }
//                    }
//                    player->GiveLevel(ucode);
//
//                    uint64 moneyuser = player->GetMoney();
//                    int64 newmoney = moneyuser + gold;
//                    if (newmoney >= MAX_MONEY_AMOUNT)
//                    {
//                        newmoney = MAX_MONEY_AMOUNT;
//                        player->SetMoney(newmoney);
//                    }
//                    else
//                        player->ModifyMoney(int64(gold));
//                    player->SaveToDB();
//                }
//                else
//                    chH.PSendSysMessage(20000, efirendu);
//            }
//            break;
//        }
//        case 3005: // buy gold
//        {
//            if (!code)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//
//            uint64 ucode = atoi(code);
//            if (!ucode)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//            uint64 addmoney = (ucode * 10000) * 1000;
//
//            if (!addmoney || addmoney <= 0)
//            {
//                chH.PSendSysMessage(20038);
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//
//            uint64 moneyuser = player->GetMoney();
//
//            int64 newmoney = moneyuser + addmoney;
//            if (newmoney > MAX_MONEY_AMOUNT)
//            {
//                chH.PSendSysMessage(20038);
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//
//            // QueryResult findCost = LoginDatabase.PQuery("SELECT `spr`.`token` FROM `store_products` AS sp LEFT JOIN `store_product_realms` AS spr ON `spr`.`product` = `sp`.`id` WHERE `sp`.`enable` = '1' AND `spr`.`realm` = '%u' and `sp`.`category` = '-1' and `sp`.`item` = '-6'", realm.Id.Realm);
//
//            VendorItemData const* vendorItems = sObjectMgr->GetNpcDonateVendorItemList(-1);
//            if (!vendorItems)
//            {
//                chH.PSendSysMessage(20038);
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//            uint32 cost = 0;
//            for (uint8 slot = 0; slot < vendorItems->GetItemCount(); ++slot)
//            {
//                VendorItem const* vendorItem = vendorItems->GetItem(slot);
//                if (!vendorItem)
//                    continue;
//
//                if (vendorItem->item == -6)
//                {
//                    cost = vendorItem->DonateCost;
//                    break;
//                }
//            }
//
//            if (cost <= 0)
//            {
//                chH.PSendSysMessage(20038);
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//
//            int64 itokens = ucode * cost;
//            if ((!itokens || itokens <= 0) && !sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//            {
//                chH.PSendSysMessage(20038);
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//
//            uint32 tokens = uint32(itokens);
//            if (!tokens)
//            {
//                chH.PSendSysMessage(20038);
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//
//            if (player->HasDonateToken(tokens))
//            {
//                if (!sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//                {
//                    if (player->DestroyDonateTokenCount(tokens))
//                    {
//                        player->UpdateDonateStatistics(SERVICE_SELL_GOLD);
//                        uint8 index = 0;
//                        SQLTransaction trans = LoginDatabase.BeginTransaction();
//                        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_STORE_ADD_ITEM_LOG_SERVICE);
//                        stmt->setUInt32(index, realm.Id.Realm);
//                        stmt->setUInt32(++index, player->GetSession()->GetAccountId());
//                        stmt->setUInt32(++index, player->GetSession()->GetBattlenetAccountId()); // select battlenet_account from account where id = %u
//                        stmt->setUInt64(++index, player->GetGUIDLow());
//                        stmt->setUInt64(++index, 0); // item_guid
//                        stmt->setInt32(++index, SERVICE_SELL_GOLD); // item entry
//                        stmt->setInt64(++index, ucode * 1000); // item count
//                        stmt->setInt64(++index, tokens); // cost
//                        stmt->setUInt32(++index, player->getLevel()); // level
//                        stmt->setInt32(++index, SERVICE_SELL_GOLD); // item entry
//
//                        trans->Append(stmt);
//                        LoginDatabase.CommitTransaction(trans);
//                        TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Service] Type: %d, cost =  %u, buy_golds = " SI64FMTD ",  %s", SERVICE_SELL_GOLD, tokens, ucode * 1000, player->GetInfoForDonate().c_str());
//                    }
//                    else
//                    {
//                        player->CLOSE_GOSSIP_MENU();
//                        return false;
//                    }
//                }
//                player->ModifyMoney(int64(addmoney));
//                player->SaveToDB();
//                chH.PSendSysMessage(20050, ucode * 1000, uint32(tokens));
//            }
//            else
//                chH.PSendSysMessage(20000, tokens);
//
//            break;
//
//        }
//        case 3006:
//        case 3007: // buy art xp
//        {
//            if (!code)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//
//            float efir;
//            efir = 0;
//            uint32 ucode = atoi(code);
//            if (!ucode)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                return false;
//            }
//            if (Item* artifact = player->GetArtifactWeapon())
//            {
//                uint32 level = artifact->GetTotalPurchasedArtifactPowers();
//                int64 xpCost = 0;
//                uint64 free_xp = artifact->GetUInt64Value(ITEM_FIELD_ARTIFACT_XP);
//                if (ucode <= level || ucode > 101)
//                {
//                    chH.PSendSysMessage(20048);
//                    player->CLOSE_GOSSIP_MENU();
//                    return false;
//                }
//
//                if (ucode > 36 && artifact->GetModifier(ITEM_MODIFIER_ARTIFACT_TIER) != 1)
//                {
//                    chH.PSendSysMessage(20051);
//                    player->CLOSE_GOSSIP_MENU();
//                    return false;
//                }
//
//                uint32 countbuy = 0;
//                for (uint32 i = level + 1; i <= ucode; i++)
//                {
//                    if (GtArtifactLevelXPEntry const* cost = sArtifactLevelXPGameTable.GetRow(i))
//                    {
//                        uint64 tempCost = uint64(artifact->GetModifier(ITEM_MODIFIER_ARTIFACT_TIER) == 1 ? cost->XP2 : cost->XP);
//                        if (tempCost <= free_xp) // если свободного опыта хватает на этот лвл, то мы пропускаем его
//                        {
//                            free_xp -= tempCost;
//                            level++;
//                            continue;
//                        }
//                        xpCost += tempCost;
//                    }
//
//                    if (float const* price = sObjectMgr->GetPriceForArtLevelUp(i))
//                    {
//                        if (price)
//                        {
//                            efir += *price; // how many tokens need for get level i
//                            countbuy++;
//                        }
//                        else
//                        {
//                            chH.PSendSysMessage(20049);
//                            player->CLOSE_GOSSIP_MENU();
//                            return false;
//                        }
//                    }
//                    else
//                    {
//                        chH.PSendSysMessage(20049);
//                        player->CLOSE_GOSSIP_MENU();
//                        return false;
//                    }
//                }
//
//                float efirend = ceil(efir);
//                uint32 efirendu = uint32(efirend);
//                if ((!efirendu || efirendu <= 0) && !sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//                {
//                    chH.PSendSysMessage(20049);
//                    player->CLOSE_GOSSIP_MENU();
//                    return false;
//                }
//
//                if (sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//                    efirendu = 0;
//
//                if (action == 3006)
//                    chH.PSendSysMessage(30106, ucode, efirendu);
//                else if (action == 3007)
//                {
//                    if (player->HasDonateToken(efirendu))
//                    {
//                        if (!sWorld->getBoolConfig(CONFIG_DONATE_ON_TESTS))
//                        {
//                            if (player->DestroyDonateTokenCount(efirendu))
//                            {
//                                player->UpdateDonateStatistics(SERVICE_SELL_ART_XP);
//                                uint8 index = 0;
//                                SQLTransaction trans = LoginDatabase.BeginTransaction();
//                                PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_STORE_ADD_ITEM_LOG_SERVICE_ART);
//                                stmt->setUInt32(index, realm.Id.Realm);
//                                stmt->setUInt32(++index, player->GetSession()->GetAccountId());
//                                stmt->setUInt32(++index, player->GetSession()->GetBattlenetAccountId()); // select battlenet_account from account where id = %u
//                                stmt->setUInt64(++index, player->GetGUIDLow());
//                                stmt->setUInt64(++index, 0); // item_guid
//                                stmt->setInt32(++index, SERVICE_SELL_ART_XP); // item entry
//                                stmt->setUInt32(++index, countbuy); // item count
//                                stmt->setUInt32(++index, efirendu); // cost
//                                stmt->setUInt32(++index, player->getLevel()); // level
//                                stmt->setInt32(++index, SERVICE_SELL_ART_XP); // item entry
//
//                                char outArt[500];
//                                sprintf(outArt, "%d:%d", artifact->GetEntry(), level);
//
//
//                                stmt->setString(++index, outArt); // ART
//
//                                trans->Append(stmt);
//                                LoginDatabase.CommitTransaction(trans);
//                                TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Service] Type: %d, cost = %u, buy_art_levels = %u,  %s, art = %s", SERVICE_SELL_ART_XP, efirendu, countbuy, player->GetInfoForDonate().c_str(), outArt);
//                            }
//                            else
//                            {
//                                player->CLOSE_GOSSIP_MENU();
//                                return false;
//                            }
//                        }
//
//                        artifact->GiveArtifactXp(xpCost, NULL, 0);
//                        player->SaveToDB();
//                    }
//                }
//            }
//            else
//                chH.PSendSysMessage(20047);
//            break;
//        }
//        }
//        player->CLOSE_GOSSIP_MENU();
//        return true;
//    }
//};
//
//class item_back : public CreatureScript
//{
//public:
//    item_back() : CreatureScript("item_back") {}
//
//    bool OnGossipHello(Player* player, Creature* creature)  override
//    {
//        QueryResult result = LoginDatabase.PQuery("SELECT `s_h`.`item_guid`, `s_h`.`item`, `s_h`.`count`, `s_h`.`token` FROM `store_history` AS s_h JOIN `store_products` AS s_p ON CASE WHEN `s_h`.`trans_project` <> '' THEN `s_p`.`item` = `s_h`.`item` AND `s_p`.`bonus` = `s_h`.`bonus` ELSE `s_p`.`id` = `s_h`.`product` END JOIN `store_product_realms` AS s_p_r ON `s_p_r`.`product` = `s_p`.`id` JOIN `store_category_realms` AS s_c_r ON `s_c_r`.`category` = `s_p`.`category` WHERE `s_h`.`char_guid` = '%u' AND `s_h`.`status` IN ('0', '6') AND `s_h`.`item` > '0' AND `s_h`.`realm` = '%u' AND (`s_c_r`.`return` = '1' OR `s_p_r`.`return` = '1') AND `s_p_r`.`realm` = '%u' AND `s_c_r`.`realm` = '%u'", player->GetGUIDLow(), realm.Id.Realm, realm.Id.Realm, realm.Id.Realm);
//        if (!result)
//        {
//            LocaleConstant localeConstant = player->GetSession()->GetSessionDbLocaleIndex();
//            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20008, localeConstant), GOSSIP_SENDER_MAIN, CHANGE_ITEMBACK);
//            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//        }
//        else
//        {
//            LocaleConstant localeConstant = player->GetSession()->GetSessionDbLocaleIndex();
//            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20006, localeConstant), GOSSIP_SENDER_MAIN, CHANGE_ITEMBACK);
//            do
//            {
//                Field* fields = result->Fetch();
//                uint32 item_guid = fields[0].GetUInt32();
//                uint32 entry = fields[1].GetUInt32();
//                uint32 count = fields[2].GetUInt32();
//                uint32 token = fields[3].GetUInt32() * 0.7;
//                ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(entry);
//                if (pProto && pProto->GetStackable() < 2)
//                {
//                    char printinfo[500];
//                    sprintf(printinfo, sObjectMgr->GetTrinityString(20043, localeConstant), pProto->GetName()->Str[localeConstant], token);
//                    player->ADD_GOSSIP_ITEM_EXTENDED(0, printinfo, GOSSIP_SENDER_MAIN, item_guid, sObjectMgr->GetTrinityString(20042, localeConstant), 0, false);
//                }
//            } while (result->NextRow());
//        }
//
//        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
//    {
//        TC_LOG_DEBUG(LOG_FILTER_NETWORKIO, "item_back sender %u, action %u", sender, action);
//
//        if (!player || !creature || sender != GOSSIP_SENDER_MAIN || !player->getAttackers()->empty())
//            return true;
//
//        ChatHandler chH = ChatHandler(player);
//
//        if (player->InBattlegroundQueue())
//        {
//            chH.PSendSysMessage("You should leave from battleground queue.");
//            return true;
//        }
//
//        TC_LOG_DEBUG(LOG_FILTER_NETWORKIO, "item_back sender %u, action %u", sender, action);
//
//        if (action > 0)
//        {
//            QueryResult result = LoginDatabase.PQuery("SELECT `s_h`.`char_guid`, `s_h`.`item`, `s_h`.`token`, `s_h`.`count` FROM `store_history` AS s_h JOIN `store_products` AS s_p ON CASE WHEN `s_h`.`trans_project` <> '' THEN `s_p`.`item` = `s_h`.`item` AND `s_p`.`bonus` = `s_h`.`bonus` ELSE `s_p`.`id` = `s_h`.`product` END JOIN `store_product_realms` AS s_p_r ON `s_p_r`.`product` = `s_p`.`id` JOIN `store_category_realms` AS s_c_r ON `s_c_r`.`category` = `s_p`.`category` WHERE `s_h`.`item_guid` = '%u' AND `s_h`.`status` IN ('0', '6') AND `s_h`.`realm` = '%u' AND`s_h`.`item` > 0 AND (`s_c_r`.`return` = '1' OR `s_p_r`.`return` = '1') AND `s_p_r`.`realm` = '%u' AND `s_c_r`.`realm` = '%u'", action, realm.Id.Realm, realm.Id.Realm, realm.Id.Realm);
//            if (!result)
//            {
//                player->CLOSE_GOSSIP_MENU(); return true;
//            }
//
//            Field* fields = result->Fetch();
//            ObjectGuid::LowType owner_guid = fields[0].GetUInt64();
//            uint32 entry = fields[1].GetUInt32();
//            uint32 efircount = fields[2].GetUInt32();
//            uint32 count = fields[3].GetUInt32();
//            uint32 countitem = player->GetItemCount(entry, false);
//
//            if (owner_guid != player->GetGUID().GetCounter())
//            {
//                player->CLOSE_GOSSIP_MENU(); return true;
//            }
//
//            QueryResult result2 = CharacterDatabase.PQuery("SELECT `owner_guid` FROM item_instance WHERE guid = '%u'", action);
//            if (!result2 || countitem == 0)
//            {
//                player->CLOSE_GOSSIP_MENU(); return true;
//            }
//
//            Field* fields2 = result2->Fetch();
//            uint32 owner_guid2 = fields2[0].GetUInt32();
//            if (owner_guid != owner_guid2)
//            {
//                player->CLOSE_GOSSIP_MENU(); return true;
//            }
//
//            if (player->GetGUID().GetCounter() != owner_guid2)
//            {
//                player->CLOSE_GOSSIP_MENU(); return true;
//            }
//
//            //Warning!! action should be uint64
//            if (Item* item = GetItemByGuid(ObjectGuid::Create<HighGuid::Item>(action), player))
//            {
//                uint32 item_guid = item->GetGUIDLow();
//                uint32 item_entry = item->GetEntry();
//
//                if (player->AddDonateTokenCount(uint32(efircount * 0.7)))
//                {
//                    TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Status] Return item  guid = %u, entry = %u, return_tokens = %u %s", item_guid, item_entry, uint32(efircount * 0.7), player->GetInfoForDonate().c_str());
//                    { // status
//                        SQLTransaction transs = LoginDatabase.BeginTransaction();
//
//                        uint8 index = 0;
//                        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_HISTORY_RETURN);
//                        // stmt->setString(  ++index, TimeToTimestampStr(time(NULL)).c_str());
//                        stmt->setUInt32(index, action); // return
//                        stmt->setUInt32(++index, realm.Id.Realm);
//
//                        transs->Append(stmt);
//                        LoginDatabase.CommitTransaction(transs);
//                    }
//
//                    player->DestroyItemCount(item, count, true);
//                    player->SaveToDB();
//
//                    chH.PSendSysMessage(20002, uint32(efircount * 0.7));
//                }
//                else
//                    chH.PSendSysMessage("Some problems... try later again");
//            }
//        }
//        else
//            chH.PSendSysMessage(20001);
//
//        player->CLOSE_GOSSIP_MENU();
//        return true;
//    }
//
//    Item* GetItemByGuid(ObjectGuid const& guid, Player* player) const
//    {
//        for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
//            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
//                if (pItem->GetGUID() == guid)
//                    return pItem;
//
//        for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_ITEM_END; ++i)
//            if (Item* pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
//                if (pItem->GetGUID() == guid)
//                    return pItem;
//
//        for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
//            if (Bag* pBag = player->GetBagByPos(i))
//                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
//                    if (Item* pItem = pBag->GetItemByPos(j))
//                        if (pItem->GetGUID() == guid)
//                            return pItem;
//
//        for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
//            if (Bag* pBag = player->GetBagByPos(i))
//                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
//                    if (Item* pItem = pBag->GetItemByPos(j))
//                        if (pItem->GetGUID() == guid)
//                            return pItem;
//        return NULL;
//    }
//};
//
//
//class char_transfer : public CreatureScript
//{
//public:
//    char_transfer() : CreatureScript("char_transfer") {}
//
//    bool OnGossipHello(Player* player, Creature* creature)  override
//    {
//        QueryResult result = LoginDatabase.PQuery("SELECT `to_realm`, `name` FROM realm_transfer WHERE from_realm = '%u';", realm.Id.Realm);
//        if (!result)
//        {
//            LocaleConstant localeConstant = player->GetSession()->GetSessionDbLocaleIndex();
//            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20027, localeConstant), GOSSIP_SENDER_MAIN, 0);
//            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//        }
//        else
//        {
//            LocaleConstant localeConstant = player->GetSession()->GetSessionDbLocaleIndex();
//            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20031, localeConstant), GOSSIP_SENDER_MAIN, 0);
//            do
//            {
//                Field* fields = result->Fetch();
//                uint32 realm = fields[0].GetUInt32();
//                std::string name = fields[1].GetString();
//
//                player->ADD_GOSSIP_ITEM(0, name, GOSSIP_SENDER_MAIN, realm);
//            } while (result->NextRow());
//        }
//
//        player->SetTransferId(0);
//        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)  override
//    {
//        if (!player || !creature || !player->getAttackers()->empty())
//            return true;
//
//        player->PlayerTalkClass->ClearMenus();
//        ChatHandler chH = ChatHandler(player);
//
//        switch (sender)
//        {
//        case GOSSIP_SENDER_MAIN:
//        {
//            if (QueryResult check_wpe = LoginDatabase.PQuery("SELECT `name` FROM realm_transfer WHERE from_realm = '%u' AND to_realm = '%u';", realm.Id.Realm, action))
//                player->SetTransferId(action);
//            else
//                return true;
//
//            QueryResult result = CharacterDatabase.PQuery("SELECT guid, name FROM characters WHERE account = '%u' AND transfer = 0", player->GetSession()->GetAccountId());
//            if (!result)
//            {
//                LocaleConstant localeConstant = player->GetSession()->GetSessionDbLocaleIndex();
//                player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20027, localeConstant), GOSSIP_SENDER_MAIN, 0);
//                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//            }
//            else
//            {
//                LocaleConstant localeConstant = player->GetSession()->GetSessionDbLocaleIndex();
//                player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20028, localeConstant), GOSSIP_SENDER_MAIN, 0);
//                do
//                {
//                    Field* fields = result->Fetch();
//                    ObjectGuid::LowType guid = fields[0].GetUInt64();
//                    std::string name = fields[1].GetString();
//
//                    player->ADD_GOSSIP_ITEM(0, name, GOSSIP_SENDER_INN_INFO, guid);
//                } while (result->NextRow());
//            }
//            break;
//        }
//        case GOSSIP_SENDER_INN_INFO:
//        {
//            if (action > 0)
//            {
//                QueryResult result = CharacterDatabase.PQuery("SELECT guid, name FROM characters WHERE guid = '%u' AND account = '%u' AND transfer = 0", action, player->GetSession()->GetAccountId());
//                if (!result)
//                {
//                    player->CLOSE_GOSSIP_MENU();
//                    return true;
//                }
//
//                Field* fields = result->Fetch();
//                ObjectGuid::LowType guid = fields[0].GetUInt64();
//                std::string name = fields[1].GetString();
//                uint32 account_id = player->GetSession()->GetAccountId();
//                std::string dump;
//
//                if (PlayerDumpWriter().WriteDump(uint32(guid), dump) != DUMP_SUCCESS)
//                {
//                    chH.PSendSysMessage(LANG_COMMAND_EXPORT_FAILED);
//                    chH.SetSentErrorMessage(true);
//                    return false;
//                }
//
//                PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SET_DUMP);
//                if (stmt)
//                {
//                    stmt->setUInt32(0, account_id);
//                    stmt->setUInt64(1, guid);
//                    stmt->setUInt32(2, realm.Id.Realm);
//                    stmt->setUInt32(3, player->GetTransferId());
//                    stmt->setUInt32(4, 1);
//                    stmt->setString(5, dump);
//                    LoginDatabase.Execute(stmt);
//                }
//                CharacterDatabase.PQuery("UPDATE characters SET deleteInfos_Name = name, deleteInfos_Account = account, deleteDate = UNIX_TIMESTAMP(), name = '', account = 0, `transfer` = '%u' WHERE guid = %u", player->GetTransferId(), guid);
//
//                if (player->GetGUID().GetCounter() == guid)
//                    player->GetSession()->KickPlayer();
//            }
//            break;
//        }
//        default:
//            break;
//        }
//        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
//        return true;
//    }
//};
//
//inline bool IsAvailableFaction(uint8 faction, Player* player)
//{
//    if (faction && !player->isGameMaster())
//    {
//        if (player->GetTeam() != TEAM_OTHER && player->GetTeam() != PANDAREN_NEUTRAL)
//        {
//            uint8 tempFaction = player->GetTeam() == ALLIANCE ? 1 : 2;
//            if (tempFaction != faction)
//                return false;
//        }
//    }
//
//    return true;
//}
//
//inline void PrintInfoByThisCategory(Player* player, uint32 action, bool preview = false)
//{
//    LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
//
//    if (DonVenCatBase const* donvencat = sObjectMgr->GetDonateVendorCat(action))
//    {
//        if (donvencat->categories.empty())
//        {
//            player->CLOSE_GOSSIP_MENU();
//            return;
//        }
//
//        for (std::vector<DonVenCat>::const_iterator itr = donvencat->categories.begin(); itr != donvencat->categories.end(); ++itr)
//        {
//            if ((*itr).action == -1)
//                continue;
//
//            if (!IsAvailableFaction((*itr).faction, player))
//                continue;
//
//            if (preview && !(*itr).is_available_for_preview)
//                continue;
//
//            if (loc_idx < 12)
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, (*itr).Names[loc_idx], GOSSIP_SENDER_MAIN, (*itr).action);
//            else
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, (*itr).Names[0], GOSSIP_SENDER_MAIN, (*itr).action);
//
//        }
//    }
//    else if (action != 0)
//    {
//        player->CLOSE_GOSSIP_MENU();
//        return;
//    }
//}
//
//// To-Do: 
//// GOSSIP_SENDER_INN_INFO звания 1
//// GOSSIP_SENDER_INFO ачивы 2
//// GOSSIP_SENDER_SEC_PROFTRAIN донат морфы 3
//// GOSSIP_SENDER_SEC_CLASSTRAIN Донат маунты земля 4
//// GOSSIP_SENDER_SEC_BATTLEINFO донат маунты флай 5
//
//// 230000
//
//class many_in_one_donate : public CreatureScript
//{
//public:
//    many_in_one_donate() : CreatureScript("many_in_one_donate") { }
//
//    std::unordered_map<ObjectGuid, uint32> playersMorphPreview{};
//
//    bool OnGossipHello(Player* player, Creature* creature)  override
//    {
//        LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
//
//        if (!getDiscontsInfo(loc_idx).empty())
//            player->ADD_GOSSIP_ITEM(5, getDiscontsInfo(loc_idx), GOSSIP_SENDER_MAIN, 230099);
//
//        player->ADD_GOSSIP_ITEM(5, getBalansInfo(player), GOSSIP_SENDER_MAIN, 230099);
//
//        PrintInfoByThisCategory(player, 0);
//
//        player->SEND_GOSSIP_MENU(60000, creature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 type, uint32 action) override
//    {
//        LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
//        player->PlayerTalkClass->ClearMenus();
//
//        if (type == DONATE_TYPE_ITEM)  // = GOSSIP_SENDER_MAIN
//        {
//            if (action == 230099)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                return true;
//            }
//
//            DonVenCatBase const* donvencat = sObjectMgr->GetDonateVendorCat(action);
//            if (action >= 230100 && (!donvencat || donvencat->type == DONATE_TYPE_ITEM))
//            {
//                player->GetSession()->SendListInventory(creature->GetGUID(), action);
//                player->CustomMultiDonate = action;
//            }
//            else
//            {
//                if (!getDiscontsInfo(loc_idx).empty())
//                    player->ADD_GOSSIP_ITEM(5, getDiscontsInfo(loc_idx), GOSSIP_SENDER_MAIN, 230099);
//                player->ADD_GOSSIP_ITEM(5, getBalansInfo(player), GOSSIP_SENDER_MAIN, 230099);
//
//                if (!donvencat)
//                {
//                    player->CLOSE_GOSSIP_MENU();
//                    return true;
//                }
//
//                switch (donvencat->type)
//                {
//                case DONATE_TYPE_ITEM:
//                    PrintInfoByThisCategory(player, action);
//                    break;
//                case DONATE_TYPE_TITLE:
//                {
//                    for (auto itr = donvencat->additionals.begin(); itr != donvencat->additionals.end(); ++itr)
//                    {
//                        if ((*itr).type != DONATE_TYPE_TITLE)
//                            continue;
//
//                        if (!IsAvailableFaction((*itr).faction, player))
//                            continue;
//
//                        CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry((*itr).action);
//                        if (!titleInfo)
//                            continue;
//
//                        char const* targetName = player->GetName();
//                        char titleNameStr[100];
//                        snprintf(titleNameStr, 100, (player->getGender() == GENDER_MALE ? titleInfo->Name->Str[loc_idx] : titleInfo->Name1->Str[loc_idx]), targetName);
//
//                        char printinfo[500];
//                        sprintf(printinfo, sObjectMgr->GetTrinityString(20043, loc_idx), titleNameStr, (*itr).cost);
//
//                        char questionInfo[200];
//                        sprintf(questionInfo, "[%s] \n %s", printinfo, sObjectMgr->GetTrinityString(20039, loc_idx));
//
//                        if (player->HasTitle(titleInfo))
//                            sprintf(printinfo, "%s |cff00ff00[%s]|r", printinfo, (loc_idx == 8 ? "Bought" : "Buyed"));
//
//                        player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_DOT, printinfo, (*itr).type, (*itr).action, questionInfo, 0, false);
//                    }
//
//                    break;
//                }
//                case DONATE_TYPE_MORPH:
//                {
//                    uint32 accountId = player->GetSession()->GetAccountId();
//                    uint32 bnaccountId = player->GetSession()->GetBattlenetAccountId();
//
//                    if (!donvencat->additionals.empty())
//                    {
//                        auto itr = playersMorphPreview.find(player->GetGUID());
//                        if ((itr != playersMorphPreview.end() && time(NULL) - (*itr).second >= 60) || itr == playersMorphPreview.end())
//                            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ACTION_TABARD, sObjectMgr->GetTrinityString(20088, loc_idx), DONATE_TYPE_MORPH, 1, "", 0, false); // for preview
//                    }
//
//                    for (auto itr = donvencat->additionals.begin(); itr != donvencat->additionals.end(); ++itr)
//                    {
//                        if ((*itr).type != DONATE_TYPE_MORPH)
//                            continue;
//
//                        if (!IsAvailableFaction((*itr).faction, player))
//                            continue;
//
//                        if (!sObjectMgr->GetCreatureTemplate((*itr).action))
//                            continue;
//
//                        char printinfo[500];
//                        // if (loc_idx < 12)
//                            // sprintf(printinfo, sObjectMgr->GetTrinityString(20043, loc_idx), (*itr).Names[loc_idx], (*itr).cost);
//                        // else
//                        sprintf(printinfo, sObjectMgr->GetTrinityString(20043, loc_idx), (*itr).Names[loc_idx < 12 ? loc_idx : 0].c_str(), (*itr).cost);
//
//
//                        char questionInfo[500];
//                        sprintf(questionInfo, "[%s] \n %s", printinfo, sObjectMgr->GetTrinityString(20039, loc_idx));
//
//                        QueryResult result = LoginDatabase.PQuery("SELECT bonus FROM store_history WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-9' AND `status` = '0' AND bonus = '%u' AND realm = '%u';", accountId, bnaccountId, (*itr).action, realm.Id.Realm);
//                        if (result)
//                            sprintf(printinfo, "%s |cff00ff00[%s]|r", printinfo, (loc_idx == 8 ? "Bought" : "Buyed"));
//
//                        player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_DOT, printinfo, (*itr).type, (*itr).action, questionInfo, 0, false);
//                    }
//
//                    break;
//                }
//                default:
//                    break;
//                }
//
//                if (donvencat->next_page != -1)
//                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, (loc_idx == 8 ? ">> Next Page" : ">> Next page"), GOSSIP_SENDER_MAIN, donvencat->next_page);
//
//                if (donvencat->prev_page != -1)
//                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, (loc_idx == 8 ? "<< Previous Page" : "<< Previous page"), GOSSIP_SENDER_MAIN, donvencat->prev_page);
//
//                if (action != 0)
//                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, (loc_idx == 8 ? "Back" : "Back"), GOSSIP_SENDER_MAIN, donvencat->parent);
//
//                player->SEND_GOSSIP_MENU(60000, creature->GetGUID());
//            }
//        }
//        else
//        {
//            if (type >= DONATE_TYPE_MAX)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                return true;
//            }
//
//            if (action == 1 && type == DONATE_TYPE_MORPH) // preview
//            {
//                playersMorphPreview[player->GetGUID()] = time(NULL);
//                player->SummonCreature(NPC_PREVIEWER, player->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 60000, 0, player->GetGUID());
//                player->CLOSE_GOSSIP_MENU();
//                return true;
//            }
//            if (DonVenAdd const* infoAdd = sObjectMgr->GetDonateVendorAdditionalInfo(type, action))
//            {
//                switch (type)
//                {
//                case DONATE_TYPE_TITLE:
//                {
//                    CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(infoAdd->action);
//                    if (!titleInfo || player->HasTitle(titleInfo))
//                    {
//                        ChatHandler(player).PSendSysMessage("You just have this title");
//                        player->CLOSE_GOSSIP_MENU();
//                        return true;
//                    }
//                    break;
//                }
//                case DONATE_TYPE_MORPH:
//                {
//                    if (!sObjectMgr->GetCreatureTemplate(action))
//                    {
//                        ChatHandler(player).PSendSysMessage("Error. This morph don't exist!");
//                        player->CLOSE_GOSSIP_MENU();
//                        return true;
//                    }
//                    uint32 accountId = player->GetSession()->GetAccountId();
//                    uint32 bnaccountId = player->GetSession()->GetBattlenetAccountId();
//                    QueryResult result = LoginDatabase.PQuery("SELECT bonus FROM store_history WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-9' AND `status` = '0' AND bonus = '%u' AND realm = '%u';", accountId, bnaccountId, action, realm.Id.Realm);
//                    if (result)
//                    {
//                        ChatHandler(player).PSendSysMessage("You just have this morph!");
//                        player->CLOSE_GOSSIP_MENU();
//                        return true;
//                    }
//                    break;
//                }
//                default:
//                    player->CLOSE_GOSSIP_MENU();
//                    return true;
//                }
//
//                if (player->HasDonateToken(infoAdd->cost) && player->DestroyDonateTokenCount(infoAdd->cost))
//                {
//                    SQLTransaction trans = LoginDatabase.BeginTransaction();
//                    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_STORE_ADD_ITEM_LOG_ADDITIONAL);
//                    uint8 index = 0;
//                    stmt->setUInt32(index, realm.Id.Realm);
//                    stmt->setUInt32(++index, player->GetSession()->GetAccountId());
//                    stmt->setUInt32(++index, player->GetSession()->GetBattlenetAccountId()); // select battlenet_account from account where id = %u
//                    stmt->setUInt64(++index, player->GetGUIDLow());
//                    stmt->setUInt64(++index, 0); // item_guid
//
//                    int32 item_entry = infoAdd->action;
//                    if (type == DONATE_TYPE_MORPH)
//                        item_entry = -9;
//
//                    stmt->setInt32(++index, item_entry); // item entry
//                    stmt->setUInt32(++index, 1); // item count
//                    stmt->setInt64(++index, infoAdd->cost); // cost
//                    stmt->setUInt32(++index, player->getLevel()); // level
//                    stmt->setInt32(++index, infoAdd->storeId);
//                    stmt->setInt32(++index, infoAdd->action); // item entry
//
//                    trans->Append(stmt);
//                    LoginDatabase.CommitTransaction(trans);
//
//                    switch (type)
//                    {
//                    case DONATE_TYPE_TITLE:
//                    {
//                        CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(infoAdd->action);
//                        player->SetTitle(titleInfo);                            // to be sure that title now known
//                        player->SetUInt32Value(PLAYER_FIELD_PLAYER_TITLE, titleInfo->MaskID);
//                        TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Buy] Title entry = %u, cost = %u, %s", infoAdd->action, infoAdd->cost, player->GetInfoForDonate().c_str());
//                        break;
//                    }
//                    case DONATE_TYPE_MORPH:
//                    {
//                        ChatHandler(player).PSendSysMessage("You can use your morph with macro: .donate morph use %u", infoAdd->action);
//                        TC_LOG_DEBUG(LOG_FILTER_DONATE, "[Buy] Morph entry = %u, cost = %u, %s", infoAdd->action, infoAdd->cost, player->GetInfoForDonate().c_str());
//                        break;
//                    }
//                    default:
//                        break;
//                    }
//                }
//
//                player->CLOSE_GOSSIP_MENU();
//                return true;
//            }
//
//        }
//
//        return true;
//    }
//
//};
//
//// 230008
//class npc_morph_previewr : public CreatureScript
//{
//public:
//    npc_morph_previewr() : CreatureScript("npc_morph_previewr") { }
//
//    bool OnGossipHello(Player* player, Creature* creature)  override
//    {
//        LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
//
//        PrintInfoByThisCategory(player, 0, true);
//        player->SEND_GOSSIP_MENU(60002, creature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 type, uint32 action) override
//    {
//        LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
//        player->PlayerTalkClass->ClearMenus();
//
//        if (type == DONATE_TYPE_ITEM)  // = GOSSIP_SENDER_MAIN
//        {
//            if (action == 230099)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                return true;
//            }
//
//            DonVenCatBase const* donvencat = sObjectMgr->GetDonateVendorCat(action);
//
//            if (!donvencat)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                return true;
//            }
//
//            switch (donvencat->type)
//            {
//            case DONATE_TYPE_ITEM:
//                PrintInfoByThisCategory(player, action, true);
//                break;
//            case DONATE_TYPE_TITLE:
//            {
//                break;
//            }
//            case DONATE_TYPE_MORPH:
//            {
//                uint32 accountId = player->GetSession()->GetAccountId();
//                uint32 bnaccountId = player->GetSession()->GetBattlenetAccountId();
//
//                for (auto itr = donvencat->additionals.begin(); itr != donvencat->additionals.end(); ++itr)
//                {
//                    if ((*itr).type != DONATE_TYPE_MORPH)
//                        continue;
//
//                    if (!sObjectMgr->GetCreatureTemplate((*itr).action))
//                        continue;
//
//                    char printinfo[500];
//                    sprintf(printinfo, sObjectMgr->GetTrinityString(20043, loc_idx), (*itr).Names[loc_idx < 12 ? loc_idx : 0].c_str(), (*itr).cost);
//
//                    QueryResult result = LoginDatabase.PQuery("SELECT bonus FROM store_history WHERE account = '%u' AND bnet_account = '%u' AND `item` = '-9' AND `status` = '0' AND bonus = '%u' AND realm = '%u';", accountId, bnaccountId, (*itr).action, realm.Id.Realm);
//                    if (result)
//                        sprintf(printinfo, "%s |cff00ff00[%s]|r", printinfo, (loc_idx == 8 ? "Bought" : "Buyed"));
//
//                    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_DOT, printinfo, (*itr).type, (*itr).action, "", 0, false);
//                }
//
//                break;
//            }
//            default:
//                break;
//            }
//
//            if (donvencat->next_page != -1)
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, (loc_idx == 8 ? ">> Next Page" : ">> Next page"), GOSSIP_SENDER_MAIN, donvencat->next_page);
//
//            if (donvencat->prev_page != -1)
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, (loc_idx == 8 ? "<< Previous Page" : "<< Previous page"), GOSSIP_SENDER_MAIN, donvencat->prev_page);
//
//            if (action != 0)
//                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, (loc_idx == 8 ? "Back" : "Back"), GOSSIP_SENDER_MAIN, donvencat->parent);
//
//            player->SEND_GOSSIP_MENU(60002, creature->GetGUID());
//        }
//        else
//        {
//            if (type >= DONATE_TYPE_MAX)
//            {
//                player->CLOSE_GOSSIP_MENU();
//                return true;
//            }
//
//            if (DonVenAdd const* infoAdd = sObjectMgr->GetDonateVendorAdditionalInfo(type, action))
//            {
//                switch (type)
//                {
//                case DONATE_TYPE_MORPH:
//                {
//                    if (!sObjectMgr->GetCreatureTemplate(action))
//                    {
//                        ChatHandler(player).PSendSysMessage("Error. This morph don't exist!");
//                        player->CLOSE_GOSSIP_MENU();
//                        return true;
//                    }
//
//                    if (CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(action))
//                    {
//                        uint32 modelid = ci->GetRandomValidModelId();
//                        creature->SetCustomDisplayId(modelid);
//                        creature->SetDisplayId(modelid, true);
//                        creature->CastSpell(creature, 61456);
//                        creature->AI()->Talk(1);
//                    }
//
//                    break;
//                }
//                default:
//                    player->CLOSE_GOSSIP_MENU();
//                    return true;
//                }
//
//                player->CLOSE_GOSSIP_MENU();
//                return true;
//            }
//        }
//        return true;
//    }
//
//    struct npc_morph_previewrAI : public ScriptedAI
//    {
//        npc_morph_previewrAI(Creature* creature) : ScriptedAI(creature) {}
//
//        void IsSummonedBy(Unit* owner) override
//        {
//            me->CastSpell(me, 60427);
//            me->AddDelayedEvent(1000, [this]() -> void
//                {
//                    if (Unit* owner = me->GetAnyOwner())
//                        Talk(0, owner->GetGUID());
//                });
//        }
//
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_morph_previewrAI(creature);
//    }
//};
//
//enum TransmogrifyActions {
//    ACTION_TRANSMOGRIFY_ADD_DISPLAY,
//    ACTION_TRANSMOGRIFY_ADD_DISPLAY_LEFT,
//    ACTION_TRANSMOGRIFY_REMOVE_DISPLAY,
//    ACTION_TRANSMOGRIFY_REMOVE_DISPLAY_LEFT
//};
//
//class npc_transmogrify : public CreatureScript
//{
//public:
//    npc_transmogrify() : CreatureScript("npc_transmogrify") { }
//
//    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
//    {
//        LocaleConstant localeConstant = pPlayer->GetSession()->GetSessionDbLocaleIndex();
//
//        uint32 PriceInGold = 500000; // 50 golds
//        bool advanced = false;
//        if (Item* transmogrified = pPlayer->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START))
//        {
//            if (pPlayer->CanUseItem(sObjectMgr->GetItemTemplate(transmogrified->GetEntry())) == EQUIP_ERR_OK)
//                if (!transmogrified->GetChildItem().IsEmpty())
//                    advanced = true;
//        }
//        if (advanced)
//        {
//            pPlayer->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, sObjectMgr->GetTrinityString(20080, localeConstant), GOSSIP_SENDER_MAIN, ACTION_TRANSMOGRIFY_ADD_DISPLAY, sObjectMgr->GetTrinityString(20086, localeConstant), PriceInGold, false);
//            pPlayer->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, sObjectMgr->GetTrinityString(20081, localeConstant), GOSSIP_SENDER_MAIN, ACTION_TRANSMOGRIFY_ADD_DISPLAY_LEFT, sObjectMgr->GetTrinityString(20086, localeConstant), PriceInGold, false);
//            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, sObjectMgr->GetTrinityString(20082, localeConstant), GOSSIP_SENDER_MAIN, ACTION_TRANSMOGRIFY_REMOVE_DISPLAY);
//            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, sObjectMgr->GetTrinityString(20083, localeConstant), GOSSIP_SENDER_MAIN, ACTION_TRANSMOGRIFY_REMOVE_DISPLAY_LEFT);
//        }
//        else
//        {
//            pPlayer->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, sObjectMgr->GetTrinityString(20084, localeConstant), GOSSIP_SENDER_MAIN, ACTION_TRANSMOGRIFY_ADD_DISPLAY, sObjectMgr->GetTrinityString(20086, localeConstant), PriceInGold, false);
//            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, sObjectMgr->GetTrinityString(20085, localeConstant), GOSSIP_SENDER_MAIN, ACTION_TRANSMOGRIFY_REMOVE_DISPLAY);
//        }
//        pPlayer->SEND_GOSSIP_MENU(100009, pCreature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
//    {
//        player->PlayerTalkClass->SendCloseGossip();
//
//        switch (action)
//        {
//        case ACTION_TRANSMOGRIFY_ADD_DISPLAY:
//            TransmogrifyItem(player, creature);
//            break;
//        case ACTION_TRANSMOGRIFY_ADD_DISPLAY_LEFT:
//            TransmogrifyItemLeft(player, creature);
//            break;
//        case ACTION_TRANSMOGRIFY_REMOVE_DISPLAY:
//            ClearItem(player, creature);
//            break;
//        case ACTION_TRANSMOGRIFY_REMOVE_DISPLAY_LEFT:
//            ClearItemLeft(player, creature);
//            break;
//        default:
//            break;
//        }
//        return true;
//    }
//
//    void TransmogrifyItem(Player* player, Creature* creature)
//    {
//        uint64 PriceInGold = 500000; // 1k golds
//        ChatHandler handler(player);
//        Item* transmogrified = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);
//        Item* displayItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START + 1);
//        if (!transmogrified || !displayItem)
//        {
//            handler.PSendSysMessage("Put the items in the first and second slot!");
//            return;
//        }
//
//        if (displayItem->GetEntry() < 160000)
//        {
//            handler.PSendSysMessage("You can only use transmogrification via this mobile phone on drawings.!");
//            return;
//        }
//
//        if (!player->HasEnoughMoney(PriceInGold))
//        {
//            player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY);
//            return;
//        }
//
//        if (uint32 transmogId = sDB2Manager.GetTransmogId(displayItem->GetEntry()))
//        {
//            ItemModifiedAppearanceEntry const* itemModifiedAppearance = sItemModifiedAppearanceStore.LookupEntry(transmogId);
//            if (!itemModifiedAppearance)
//                return;
//
//
//            if (player->CanUseItem(sObjectMgr->GetItemTemplate(itemModifiedAppearance->ItemID)) != EQUIP_ERR_OK || player->CanUseItem(sObjectMgr->GetItemTemplate(transmogrified->GetEntry())) != EQUIP_ERR_OK)
//            {
//                player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//                return;
//            }
//
//            if (!Item::CanTransmogrifyItemWithItem(transmogrified, itemModifiedAppearance))
//            {
//                player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//                return;
//            }
//
//            if ((transmogrified->IsRangedWeapon() && !displayItem->IsRangedWeapon()) || (!transmogrified->IsRangedWeapon() && displayItem->IsRangedWeapon()))
//            {
//                player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//                return;
//            }
//
//            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, transmogId);
//            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, 0);
//            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, 0);
//            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, 0);
//            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, 0);
//
//            player->SetVisibleItemSlot(transmogrified->GetSlot(), transmogrified);
//
//            transmogrified->SetNotRefundable(player);
//            transmogrified->ClearSoulboundTradeable(player);
//            transmogrified->SetState(ITEM_CHANGED, player);
//
//            player->ModifyMoney(-1 * PriceInGold);
//            creature->CastSpell(player, 40646);
//        }
//        else
//            handler.PSendSysMessage("No Appearance.");
//    }
//
//    void ClearItem(Player* player, Creature* creature)
//    {
//        ChatHandler handler(player);
//        Item* trItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);
//        if (!trItem)
//        {
//            handler.PSendSysMessage("Put the item in the first slot!");
//            return;
//        }
//
//        if (player->CanUseItem(sObjectMgr->GetItemTemplate(trItem->GetEntry())) != EQUIP_ERR_OK)
//        {
//            player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//            return;
//        }
//
//        trItem->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, 0);
//        trItem->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, 0);
//        trItem->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, 0);
//        trItem->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, 0);
//        trItem->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, 0);
//
//        creature->CastSpell(player, 40646);
//    }
//
//    // clone for left hand
//    void TransmogrifyItemLeft(Player* player, Creature* creature)
//    {
//        uint64 PriceInGold = 500000; // 1k golds
//        ChatHandler handler(player);
//        Item* transmogrified = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);
//        Item* displayItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START + 1);
//        if (!transmogrified || !displayItem)
//        {
//            handler.PSendSysMessage("Put the items in the first and second slot!");
//            return;
//        }
//
//        if (transmogrified->GetChildItem().IsEmpty())
//        {
//            handler.PSendSysMessage("There is no 'left' part for this subject.");
//            return;
//        }
//
//        if (ItemChildEquipmentEntry const* itemChildEquipment = sDB2Manager.GetItemChildEquipment(transmogrified->GetEntry()))
//        {
//            if (Item* temp = player->GetChildItemByGuid(transmogrified->GetChildItem()))
//                transmogrified = temp;
//            else
//            {
//                handler.PSendSysMessage("There is no 'left' part for this subject.");
//                return;
//            }
//        }
//        else
//        {
//            handler.PSendSysMessage("There is no 'left' part for this subject.");
//            return;
//        }
//
//
//        if (displayItem->GetEntry() < 160000)
//        {
//            handler.PSendSysMessage("You can only use transmogrification via this mobile phone on drawings.!");
//            return;
//        }
//
//        if (!player->HasEnoughMoney(PriceInGold))
//        {
//            player->SendBuyError(BUY_ERR_NOT_ENOUGHT_MONEY);
//            return;
//        }
//
//        if (uint32 transmogId = sDB2Manager.GetTransmogId(displayItem->GetEntry()))
//        {
//            ItemModifiedAppearanceEntry const* itemModifiedAppearance = sItemModifiedAppearanceStore.LookupEntry(transmogId);
//            if (!itemModifiedAppearance)
//                return;
//
//
//            if (player->CanUseItem(sObjectMgr->GetItemTemplate(itemModifiedAppearance->ItemID)) != EQUIP_ERR_OK || player->CanUseItem(sObjectMgr->GetItemTemplate(transmogrified->GetEntry())) != EQUIP_ERR_OK)
//            {
//                player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//                return;
//            }
//
//            if (!Item::CanTransmogrifyItemWithItem(transmogrified, itemModifiedAppearance))
//            {
//                player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//                return;
//            }
//
//            if ((transmogrified->IsRangedWeapon() && !displayItem->IsRangedWeapon()) || (!transmogrified->IsRangedWeapon() && displayItem->IsRangedWeapon()))
//            {
//                player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//                return;
//            }
//
//
//            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, transmogId);
//            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, 0);
//            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, 0);
//            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, 0);
//            transmogrified->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, 0);
//
//            player->SetVisibleItemSlot(transmogrified->GetSlot(), transmogrified);
//
//            transmogrified->SetNotRefundable(player);
//            transmogrified->ClearSoulboundTradeable(player);
//            transmogrified->SetState(ITEM_CHANGED, player);
//
//            player->ModifyMoney(-1 * PriceInGold);
//            creature->CastSpell(player, 40646);
//        }
//        else
//            handler.PSendSysMessage("Нет Аппеаранса");
//    }
//
//    void ClearItemLeft(Player* player, Creature* creature)
//    {
//        ChatHandler handler(player);
//        Item* trItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, INVENTORY_SLOT_ITEM_START);
//        if (!trItem)
//        {
//            handler.PSendSysMessage("Put the item in the first slot!");
//            return;
//        }
//
//        if (trItem->GetChildItem().IsEmpty())
//        {
//            handler.PSendSysMessage("There is no 'left' part for this subject.");
//            return;
//        }
//
//        if (ItemChildEquipmentEntry const* itemChildEquipment = sDB2Manager.GetItemChildEquipment(trItem->GetEntry()))
//        {
//            if (Item* temp = player->GetChildItemByGuid(trItem->GetChildItem()))
//                trItem = temp;
//            else
//            {
//                handler.PSendSysMessage("There is no 'left' part for this subject.");
//                return;
//            }
//        }
//        else
//        {
//            handler.PSendSysMessage("There is no 'left' part for this subject.");
//            return;
//        }
//
//        if (player->CanUseItem(sObjectMgr->GetItemTemplate(trItem->GetEntry())) != EQUIP_ERR_OK)
//        {
//            player->SendEquipError(EQUIP_ERR_NOT_EQUIPPABLE);
//            return;
//        }
//
//        trItem->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_ALL_SPECS, 0);
//        trItem->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_1, 0);
//        trItem->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_2, 0);
//        trItem->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_3, 0);
//        trItem->SetModifier(ITEM_MODIFIER_TRANSMOG_APPEARANCE_SPEC_4, 0);
//
//        creature->CastSpell(player, 40646);
//    }
//};
//
//
//class npc_change_rates : public CreatureScript
//{
//public:
//    npc_change_rates() : CreatureScript("npc_change_rates") { }
//
//    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
//    {
//        LocaleConstant localeConstant = pPlayer->GetSession()->GetSessionDbLocaleIndex();
//
//        // info about server rates
//        char rates[500];
//        float Server_Rate = sWorld->getRate(RATE_XP_KILL);
//        sprintf(rates, sObjectMgr->GetTrinityString(20066, localeConstant), Server_Rate);
//        pPlayer->ADD_GOSSIP_ITEM(3, rates, GOSSIP_SENDER_MAIN, 0);
//
//        // info about rates now
//        float Rate_Now = (pPlayer->GetSession()->GetPersonalXPRate() ? pPlayer->GetSession()->GetPersonalXPRate() : sWorld->getRate(RATE_XP_KILL));
//        sprintf(rates, sObjectMgr->GetTrinityString(20065, localeConstant), Rate_Now);
//        pPlayer->ADD_GOSSIP_ITEM(3, rates, GOSSIP_SENDER_MAIN, 0);
//
//        if (!sWorld->getRate(RATE_XP_CHANGE_MAX) || !sWorld->getRate(RATE_XP_CHANGE_STEP))
//        {
//            pPlayer->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20067, localeConstant), GOSSIP_SENDER_MAIN, 0);
//            pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, pCreature->GetGUID());
//            return true;
//        }
//
//        // Create dynamicly buttons with selecting rates. Let's fun!
//        float Current_Rate = sWorld->getRate(RATE_XP_CHANGE_MIN);
//        float Max_Rate = sWorld->getRate(RATE_XP_CHANGE_MAX);
//        float Step_Rate = sWorld->getRate(RATE_XP_CHANGE_STEP);
//        for (; Current_Rate <= Max_Rate; Current_Rate += Step_Rate)
//        {
//            char Rate_Info[500];
//            sprintf(Rate_Info, sObjectMgr->GetTrinityString(20068, localeConstant), (!Current_Rate ? 1 : Current_Rate));
//            pPlayer->ADD_GOSSIP_ITEM(4, Rate_Info, GOSSIP_SENDER_MAIN, uint32(!Current_Rate ? 1 : Current_Rate));
//        }
//
//        pPlayer->SEND_GOSSIP_MENU(100011, pCreature->GetGUID());
//        return true;
//    }
//
//    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
//    {
//        LocaleConstant localeConstant = player->GetSession()->GetSessionDbLocaleIndex();
//        if (!action)
//        {
//            player->CLOSE_GOSSIP_MENU();
//            return true;
//        }
//
//        if (float(action) == sWorld->getRate(RATE_XP_KILL)) //if server rate, can delete custom
//            player->GetSession()->SetPersonalXPRate(0);
//        else
//            player->GetSession()->SetPersonalXPRate(float(action));
//
//        ChatHandler(player).PSendSysMessage(sObjectMgr->GetTrinityString(20069, localeConstant), action);
//        player->CLOSE_GOSSIP_MENU();
//        return true;
//
//    }
//};
//
//void AddSC_multi_vendor()
//{
//    new multi_vendor();
//    new item_back();
//    new char_transfer();
//
//    new many_in_one_donate();
//    new npc_morph_previewr();
//    new npc_transmogrify();
//
//    new npc_change_rates();
//}
