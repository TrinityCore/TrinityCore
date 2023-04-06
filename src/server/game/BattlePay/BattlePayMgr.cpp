/*
* Copyright 2023 AzgathCore
* Copyright 2021 Thordekk
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Common.h"
#include "ObjectMgr.h"
#include "BattlePayMgr.h"
#include "WorldSession.h"
#include "Player.h"
#include "BattlePayData.h"
#include "DatabaseEnv.h"
#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "CollectionMgr.h"
#include <sstream>

using namespace Battlepay;

BattlepayManager::BattlepayManager(WorldSession* session)
{
    _session = session;
    _purchaseIDCount = 0;
    _distributionIDCount = 0;
    _walletName = "Credits";
    //_walletName = "Shadowlands Credits";//这也行?!
    //重复,暂时注释
}

BattlepayManager::~BattlepayManager() = default;

void BattlepayManager::RegisterStartPurchase(Purchase purchase)
{
    _actualTransaction = purchase;
}

uint64 BattlepayManager::GenerateNewPurchaseID()
{
    return uint64(0x1E77800000000000 | ++_purchaseIDCount);
}

uint64 BattlepayManager::GenerateNewDistributionId()
{
    return uint64(0x1E77800000000000 | ++_distributionIDCount);
}

Purchase* BattlepayManager::GetPurchase()
{
    return &_actualTransaction;
}

std::string const& BattlepayManager::GetDefaultWalletName() const
{
    return _walletName;
}

uint32 BattlepayManager::GetShopCurrency() const
{
    return sWorld->getIntConfig(CONFIG_BATTLE_PAY_CURRENCY);
}

bool BattlepayManager::IsAvailable() const
{
    if (AccountMgr::IsAdminAccount(_session->GetSecurity()))
        return true;

    return sWorld->getBoolConfig(CONFIG_BATTLE_PAY_ENABLED);
}

void BattlepayManager::SavePurchase(Purchase * purchase)
{
    auto displayInfo = sBattlePayDataStore->GetDisplayInfo(purchase->ProductID);
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_PURCHASE);
    stmt->setUInt32(0, _session->GetAccountId());
    stmt->setUInt32(1, GetVirtualRealmAddress());
    stmt->setUInt32(2, _session->GetPlayer() ? _session->GetPlayer()->GetGUID().GetCounter() : 0);
    stmt->setUInt32(3, purchase->ProductID);
    stmt->setString(4, displayInfo->Name1);
    stmt->setUInt32(5, purchase->CurrentPrice);
    stmt->setString(6, _session->GetRemoteAddress());
    LoginDatabase.Execute(stmt);
}


void BattlepayManager::ProcessDelivery(Purchase * purchase)
{
    auto player = _session->GetPlayer();
    if (!player)
        return;

    auto const& product = sBattlePayDataStore->GetProduct(purchase->ProductID);
    auto const& productDisplay = sBattlePayDataStore->GetDisplayInfo(product.ProductID);
    switch (product.WebsiteType)
    {
    case Battlepay::Item:
        for (auto const& itr : product.Items)
            if (player)
                player->AddItem(itr.ItemID, itr.Quantity);
        break;
    case Battlepay::SpellMount:
            if (player)
                player->LearnSpell(product.SpellID, true);
        break;
    case Battlepay::Gold:
        if (player)
            player->ModifyMoney(product.CustomValue);
        break;
        /*case Battlepay::Currency:
            if (player)
                player->ModifyCurrency(currencyID, product.CustomValue); // implement currencyID in DB
            break;*/
    case Battlepay::Level:
    {
        if (player)
        {
            player->SetLevel(product.CustomValue);
            player->SendBattlePayMessage(1, productDisplay->Name1);
        }
        break;
    }
    case Battlepay::BattlePet:
        if (player)
            player->AddBattlePetByCreatureId(product.CustomValue, true, true);
        break;
    case Battlepay::CharacterRename:
        if (player)
            player->SetAtLoginFlag(AT_LOGIN_RENAME);
        break;
    case Battlepay::CharacterFactionChange:
        if (player)
            player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
        break;
    case Battlepay::CharacterCustomization:
        if (player)
            player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
        break;
    case Battlepay::CharacterRaceChange:
        if (player)
            player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
        break;
    default:
        break;
    }
}

bool BattlepayManager::AlreadyOwnProduct(uint32 itemId) const
{
    auto const& player = _session->GetPlayer();
    if (player)
    {
        auto itemTemplate = sObjectMgr->GetItemTemplate(itemId);
        if (!itemTemplate)
            return true;

        for (auto itr : itemTemplate->Effects)
            if (itr->TriggerType == ITEM_SPELLTRIGGER_ON_LEARN && player->HasSpell(itr->SpellID))
                return true;

        uint8 inventoryEnd = INVENTORY_SLOT_ITEM_START + player->GetInventorySlotCount();
        for (uint8 i = INVENTORY_SLOT_ITEM_START; i < inventoryEnd; i++)
            if (player->GetItemCount(itemId))
                return true;
    }

    return false;
}

auto GroupFilterForSession = [](uint32 groupId) -> bool
{
    switch (groupId)
    {
    case ProductGroups::Mount:
    case ProductGroups::Pets:
        return true;
    default:
        return false;
    }
};

auto BattlepayManager::ProductFilter(Product product) -> bool
{
    auto player = _session->GetPlayer();
    if (!player)
    {
        switch (product.WebsiteType)
        {
        case Battlepay::BattlePet:
        case CharacterBoost:
            return true;
        default:
            return false;
        }
    }

    if (product.ClassMask && (player->GetClassMask() & product.ClassMask) == 0)
        return false;

    for (auto& itr : product.Items)
    {
        if (AlreadyOwnProduct(itr.ItemID))
            return false;

    }

    return true;
};

void BattlepayManager::SendProductList()
{
    WorldPackets::BattlePay::ProductListResponse response;
    if (!IsAvailable())
    {
        response.Result = ProductListResult::LockUnk1;
        _session->SendPacket(response.Write());
        return;
    }

    auto const& localeIndex = _session->GetSessionDbLocaleIndex();

    response.Result = ProductListResult::Available;
    response.ProductList.CurrencyID = GetShopCurrency();

    for (auto& itr : sBattlePayDataStore->GetProductGroups())
    {
        if (!_session->GetPlayer() && !GroupFilterForSession(itr.GroupID))
            continue;

        WorldPackets::BattlePay::BattlePayProductGroup pGroup;
        pGroup.GroupID = itr.GroupID;
        pGroup.IconFileDataID = itr.IconFileDataID;
        pGroup.Ordering = itr.Ordering;
        pGroup.UnkInt = 0;
        pGroup.IsAvailableDescription = "";
        pGroup.DisplayType = itr.DisplayType;

        auto name = itr.Name;
        if (auto productLocale = sBattlePayDataStore->GetProductGroupLocale(itr.GroupID))
            ObjectMgr::GetLocaleString(productLocale->Name, localeIndex, name);
        pGroup.Name = name;
        response.ProductList.ProductGroup.emplace_back(pGroup);
    }

    for (auto const& itr : sBattlePayDataStore->GetShopEntries())
    {
        if (!_session->GetPlayer() && !GroupFilterForSession(itr.GroupID))
            continue;

        WorldPackets::BattlePay::BattlePayShopEntry sEntry;
        sEntry.EntryID = itr.EntryID;
        sEntry.GroupID = itr.GroupID;
        sEntry.ProductID = itr.ProductID;
        sEntry.Ordering = itr.Ordering;
        sEntry.VasServiceType = itr.VasServiceType;
        sEntry.StoreDeliveryType = itr.StoreDeliveryType;

        auto data = WriteDisplayInfo(itr.DisplayInfoID, localeIndex);
        if (std::get<0>(data))
        {
            //sEntry.DisplayInfo = boost::in_place();//暂时解决不了,注释掉
            sEntry.DisplayInfo = std::get<1>(data);
        }

        response.ProductList.Shop.emplace_back(sEntry);
    }

    for (auto const& itr : sBattlePayDataStore->GetProducts())
    {
        auto const& product = itr.second;
        if (!ProductFilter(product))
            continue;

        if (!_session->GetPlayer() && !GroupFilterForSession(sBattlePayDataStore->GetProductGroupId(product.ProductID)))
            continue;

        WorldPackets::BattlePay::ProductInfoStruct pInfo;
        pInfo.NormalPriceFixedPoint = product.NormalPriceFixedPoint * g_CurrencyPrecision;
        pInfo.CurrentPriceFixedPoint = product.CurrentPriceFixedPoint * g_CurrencyPrecision;
        pInfo.ProductID = product.ProductID;
        pInfo.ChoiceType = product.ChoiceType;
        pInfo.ProductIDs.emplace_back(product.ProductID);
        pInfo.UnkInt2 = 47; // 2 ?

        auto dataPI = WriteDisplayInfo(product.DisplayInfoID, localeIndex);
        if (std::get<0>(dataPI))
        {
            //pInfo.DisplayInfo = boost::in_place();//暂时解决不了,注释掉
            pInfo.DisplayInfo = std::get<1>(dataPI);
        }

        response.ProductList.ProductInfo.emplace_back(pInfo);

        WorldPackets::BattlePay::BattlePayProduct pProduct;
        pProduct.ProductID = product.ProductID;
        pProduct.Flags = product.Flags;
        pProduct.Type = product.Type;

        for (auto& item : product.Items)
        {
            WorldPackets::BattlePay::ProductItem pItem;
            pItem.ID = item.ID;
            pItem.ItemID = product.Items.size() > 1 ? 0 : item.ItemID; ///< Disable tooltip for packs (client handle only one tooltip).
            pItem.Quantity = item.Quantity;
            pItem.HasPet = AlreadyOwnProduct(item.ItemID);
            pItem.PetResult = item.PetResult;

            auto dataP = WriteDisplayInfo(item.DisplayInfoID, localeIndex);
            if (std::get<0>(dataP))
            {
//                pItem.DisplayInfo = boost::in_place();//tmp
                pItem.DisplayInfo = std::get<1>(dataP);
            }

            pProduct.Items.emplace_back(pItem);
        }

        auto dataP = WriteDisplayInfo(product.DisplayInfoID, localeIndex);
        if (std::get<0>(dataP))
        {
//            pProduct.DisplayInfo = boost::in_place();//tmp
            pProduct.DisplayInfo = std::get<1>(dataP);
        }

        response.ProductList.Product.emplace_back(pProduct);
    }

    _session->SendPacket(response.Write());
}

std::tuple<bool, WorldPackets::BattlePay::ProductDisplayInfo> BattlepayManager::WriteDisplayInfo(uint32 displayInfoID, LocaleConstant localeIndex, uint32 productId /*= 0*/)
{
    auto GeneratePackDescription = [localeIndex](Product const& product) -> std::string
    {
        auto getQualityColor = [](uint32 quality) -> std::string
        {
            switch (quality)
            {
            case ITEM_QUALITY_POOR:
                return "|cff9d9d9d";
            case ITEM_QUALITY_NORMAL:
                return "|cffffffff";
            case ITEM_QUALITY_UNCOMMON:
                return "|cff1eff00";
            case ITEM_QUALITY_RARE:
                return "|cff0070dd";
            case ITEM_QUALITY_EPIC:
                return "|cffa335ee";
            case ITEM_QUALITY_LEGENDARY:
                return "|cffff8000";
            case ITEM_QUALITY_ARTIFACT:
                return "|cffe5cc80";
            case ITEM_QUALITY_HEIRLOOM:
                return "|cffe5cc80";
            default:
                return "|cffe5cc80";
            }
        };

        std::string res;
        for (auto itr : product.Items)
            if (auto itemTemplate = sObjectMgr->GetItemTemplate(itr.ItemID))
                res += getQualityColor(itemTemplate->GetQuality()) + itemTemplate->GetName(localeIndex) + "\n";
        return res;
    };

    auto info = WorldPackets::BattlePay::ProductDisplayInfo();
    if (!displayInfoID)
        return std::make_tuple(false, info);

    auto displayInfo = sBattlePayDataStore->GetDisplayInfo(displayInfoID);
    if (!displayInfo)
        return std::make_tuple(false, info);

    auto displayLocale = sBattlePayDataStore->GetDisplayInfoLocale(displayInfoID);

    info.Name1 = displayInfo->Name1;
    if (displayLocale)
        ObjectMgr::GetLocaleString(displayLocale->Name1, localeIndex, info.Name1);

    info.Name2 = displayInfo->Name2;
    if (displayLocale)
        ObjectMgr::GetLocaleString(displayLocale->Name2, localeIndex, info.Name2);

    info.Name3 = displayInfo->Name3;
    if (productId)
    {
        auto product = sBattlePayDataStore->GetProduct(productId);
        if (!product.Items.empty())
            info.Name3 = GeneratePackDescription(product);
    }
    else if (displayLocale)
        ObjectMgr::GetLocaleString(displayLocale->Name3, localeIndex, info.Name3);

    info.Name4 = displayInfo->Name4;
    if (displayLocale)
        ObjectMgr::GetLocaleString(displayLocale->Name4, localeIndex, info.Name4);

    info.Name5 = displayInfo->Name5;
    if (displayLocale)
        ObjectMgr::GetLocaleString(displayLocale->Name5, localeIndex, info.Name5);

    if (displayInfo->CreatureDisplayInfoID != 0)
        info.CreatureDisplayInfoID = displayInfo->CreatureDisplayInfoID;

    if (displayInfo->FileDataID != 0)
        info.FileDataID = displayInfo->FileDataID;

    info.DisplayCardWidth = displayInfo->DisplayCardWidth;

    for (auto& visuals : displayInfo->VisualData)
    {
        WorldPackets::BattlePay::ProductDisplayVisualData visualDatas;
        visualDatas.DisplayId = visuals.DisplayID;
        visualDatas.VisualId = visuals.VisualID;
        visualDatas.ProductName = visuals.ProductName;
        info.Visuals.emplace_back(visualDatas);
    }

    if (displayInfo->Flags != 0)
        info.Flags = displayInfo->Flags;

    return std::make_tuple(true, info);
}

void BattlepayManager::SendAccountCredits()
{
    auto sessionId = _session->GetAccountId();

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BATTLE_PAY_ACCOUNT_CREDITS);
    stmt->setUInt32(0, _session->GetAccountId());
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    auto sSession = sWorld->FindSession(sessionId);
    if (!sSession)
        return;

    uint32 balance = 0;
    if (result)
    {
        auto fields = result->Fetch();
        if (auto balanceStr = fields[0].GetCString())
            balance = atoi(balanceStr);
    }

    auto player = sSession->GetPlayer();
    if (!player)
        return;

    player->SendBattlePayMessage(2, "");
}

void BattlepayManager::SendBattlePayDistribution(uint32 productId, uint8 status, uint64 distributionId, ObjectGuid targetGuid)
{
    WorldPackets::BattlePay::DistributionUpdate distributionBattlePay;
    auto product = sBattlePayDataStore->GetProduct(productId);
    if (!product.ProductID)
        return;

    auto const& localeIndex = _session->GetSessionDbLocaleIndex();
    distributionBattlePay.DistributionObject.DistributionID = distributionId;
    distributionBattlePay.DistributionObject.Status = status;
    distributionBattlePay.DistributionObject.ProductID = productId;
    distributionBattlePay.DistributionObject.Revoked = false; // not needed for us

    if (!targetGuid.IsEmpty())
    {
        distributionBattlePay.DistributionObject.TargetPlayer = targetGuid;
        distributionBattlePay.DistributionObject.TargetVirtualRealm = GetVirtualRealmAddress();
        distributionBattlePay.DistributionObject.TargetNativeRealm = GetVirtualRealmAddress();
    }

    WorldPackets::BattlePay::BattlePayProduct productData;

    for (auto const& item : product.Items)
    {
        WorldPackets::BattlePay::ProductItem productItem;

        auto dataP = WriteDisplayInfo(item.DisplayInfoID, localeIndex);
        if (std::get<0>(dataP))
        {
//            productItem.DisplayInfo = boost::in_place();//tmp
            productItem.DisplayInfo = std::get<1>(dataP);
        }

        productItem.PetResult = item.PetResult;
        productItem.ID = item.ID;
        productItem.ItemID = item.ItemID;
        productItem.Quantity = item.Quantity;
        productItem.UnkInt1 = item.DisplayInfoID;
        productItem.UnkInt2 = 0;
        productItem.PetResult = 0;;
        productItem.HasPet = item.HasPet;
        productData.Items.emplace_back(productItem);
    }

    auto dataP = WriteDisplayInfo(product.DisplayInfoID, localeIndex);
    if (std::get<0>(dataP))
    {
//        productData.DisplayInfo = boost::in_place();//tmp
        productData.DisplayInfo = std::get<1>(dataP);
    }

    productData.ProductID = product.ProductID;
    productData.Type = product.Type;
    productData.Flags = product.Flags;
    productData.UnkInt1 = 0;
    productData.SpellID = product.SpellID;
    productData.CreatureID = product.CreatureID;
    productData.UnkInt4 = 0;
    productData.UnkInt5 = 0;
    productData.UnkString = "";
    productData.UnkBit = false;
    distributionBattlePay.DistributionObject.Product = std::move(productData);
    _session->SendPacket(distributionBattlePay.Write());
}

void BattlepayManager::AssignDistributionToCharacter(ObjectGuid const& targetCharGuid, uint64 distributionId, uint32 productId, uint16 /*specId*/, uint16 /*choiceId*/)
{
    WorldPackets::BattlePay::UpgradeStarted upgrade;
    upgrade.CharacterGUID = targetCharGuid;
    _session->SendPacket(upgrade.Write());

    WorldPackets::BattlePay::BattlePayStartDistributionAssignToTargetResponse assignResponse;
    assignResponse.DistributionID = distributionId;
    assignResponse.unkint1 = 0;
    assignResponse.unkint2 = 0;
    _session->SendPacket(upgrade.Write());

    auto purchase = GetPurchase();
    purchase->Status = DistributionStatus::BATTLE_PAY_DIST_STATUS_ADD_TO_PROCESS;

    SendBattlePayDistribution(productId, purchase->Status, distributionId, targetCharGuid);
}

void BattlepayManager::Update(uint32 /*diff*/)
{
    auto& data = _actualTransaction;
    auto& product = sBattlePayDataStore->GetProduct(data.ProductID);

    switch (data.Status)
    {
    case DistributionStatus::BATTLE_PAY_DIST_STATUS_ADD_TO_PROCESS:
    {
        switch (product.WebsiteType)
        {
        case CharacterBoost:
        {
            auto const& player = data.TargetCharacter;
            if (!player)
                break;

            /*WorldPackets::BattlePay::BattlePayCharacterUpgradeQueued responseQueued;
            responseQueued.EquipmentItems = sDB2Manager.GetItemLoadOutItemsByClassID(player->getClass(), 3)[0];
            responseQueued.Character = data.TargetCharacter;
            _session->SendPacket(responseQueued.Write());*/

            data.Status = DistributionStatus::BATTLE_PAY_DIST_STATUS_PROCESS_COMPLETE;
            SendBattlePayDistribution(data.ProductID, data.Status, data.DistributionId, data.TargetCharacter);
            break;
        }
        default:
            break;
        }
        break;
    }
    case DistributionStatus::BATTLE_PAY_DIST_STATUS_PROCESS_COMPLETE: //send SMSG_BATTLE_PAY_VAS_PURCHASE_STARTED
    {
        switch (product.WebsiteType)
        {
        case CharacterBoost:
        {
            data.Status = DistributionStatus::BATTLE_PAY_DIST_STATUS_FINISHED;
            SendBattlePayDistribution(data.ProductID, data.Status, data.DistributionId, data.TargetCharacter);
            break;
        }
        default:
            break;
        }
        break;
    }
    case DistributionStatus::BATTLE_PAY_DIST_STATUS_FINISHED:
    {
        switch (product.WebsiteType)
        {
        case CharacterBoost:
            SendBattlePayDistribution(data.ProductID, data.Status, data.DistributionId, data.TargetCharacter);
            break;
        default:
            break;
        }
        break;
    }
    case DistributionStatus::BATTLE_PAY_DIST_STATUS_AVAILABLE:
    case DistributionStatus::BATTLE_PAY_DIST_STATUS_NONE:
    default:
        break;
    }
}
