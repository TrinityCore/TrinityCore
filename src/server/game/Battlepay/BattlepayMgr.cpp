/*
* Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "BattlePayMgr.h"
#include "Language.h"

BattlePayMgr::~BattlePayMgr()
{
    for (BattlePayProductSet::iterator itr = m_productStore.begin(); itr != m_productStore.end(); ++itr)
        delete *itr;

    for (BattlePayProductGroupSet::iterator itr = m_groupStore.begin(); itr != m_groupStore.end(); ++itr)
        delete *itr;

    for (BattlePayShopEntryset::iterator itr = m_shopEntryStore.begin(); itr != m_shopEntryStore.end(); ++itr)
        delete *itr;

    m_productStore.clear();
    m_groupStore.clear();
    m_shopEntryStore.clear();
}

uint32 BattlePayMgr::GetProducts(uint32 id) const
{
    for (BattlePayProductSet::const_iterator citr = m_productStore.begin(); citr != m_productStore.end(); ++citr)
        (*citr)->ID = id;
           
    return true;
}

void BattlePayMgr::LoadFromDb()
{
    LoadProductsFromDb();
    LoadGroupsFromDb();
    LoadEntriesFromDb();
}

bool BattlePayMgr::LoadProductsFromDb()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT ID, Name1, Name2, Name3, NormalPrice, CurrentPrice, ItemId, Quantity, DisplayId, Type, Flags FROM battle_pay_product");
    if (!result)
    {
        TC_LOG_INFO("sql.sql", ">> Loaded 0 Battle Pay store products, table `battle_pay_product` is empty!");
        return false;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 ID = fields[0].GetUInt32();
        std::string Name1 = fields[1].GetString();
        std::string Name2 = fields[2].GetString();
        std::string Name3 = fields[3].GetString();
        uint32 NormalPrice = fields[4].GetUInt32();
        uint32 CurrentPrice = fields[5].GetUInt32();
        uint32 ItemID = fields[6].GetUInt32();
        uint32 Quantity = fields[7].GetUInt32();
        uint32 DisplayID = fields[8].GetUInt32();
        uint8 Type = fields[9].GetUInt8();
        uint32 Flags = fields[10].GetUInt32();

        if (HasProductId(ID))
        {
            TC_LOG_ERROR("sql.sql", "Product id %u defined in `battle_pay_product` already exists, skipped!", ID);
            continue;
        }

        if (Name1.size() > MAX_BATTLE_PAY_PRODUCT_TITLE_SIZE)
        {
            TC_LOG_ERROR("sql.sql", "Title for product id %u defined in `battle_pay_product` is too large (max %d), skipped!",
                ID, MAX_BATTLE_PAY_PRODUCT_TITLE_SIZE);

            continue;
        }

        if (Name2.size() > MAX_BATTLE_PAY_PRODUCT_DESCRIPTION_SIZE)
        {
            TC_LOG_ERROR("sql.sql", "Description for product id %u defined in `battle_pay_product` is too large (max %d), skipped!",
                ID, MAX_BATTLE_PAY_PRODUCT_DESCRIPTION_SIZE);

            continue;
        }

        if (CurrentPrice > NormalPrice)
        {
            TC_LOG_ERROR("sql.sql", "Current price of product id %u defined in `battle_pay_product` is larger then the normal price. "
                "Current price has been updated to the normal price", ID);

            CurrentPrice = NormalPrice;
        }

        if (!sObjectMgr->GetItemTemplate(ItemID))
        {
            TC_LOG_ERROR("sql.sql", "Item id %u for product id %u defined in `battle_pay_product` doesn't exist, skipped!", ItemID, ID);
            continue;
        }

        BattlePayProduct* product = new BattlePayProduct(ID, Name1, Name2, Name3, NormalPrice, CurrentPrice,
            ItemID, Quantity, DisplayID, Type, Flags);

        m_productStore.insert(product);
        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u Battle Pay store products in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

    return true;
}

bool BattlePayMgr::LoadGroupsFromDb()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT id, `order`, name, icon, type FROM battle_pay_group");
    if (!result)
    {
        TC_LOG_INFO("sql.sql", ">> Loaded 0 Battle Pay store groups, table `battle_pay_group` is empty!");
        return false;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();
        uint32 order = fields[1].GetUInt32();
        std::string name = fields[2].GetString();
        uint32 icon = fields[3].GetUInt32();
        uint8 type = fields[4].GetUInt8();

        if (HasGroupId(id))
        {
            TC_LOG_ERROR("sql.sql", "Group id %u defined in `battle_pay_group` already exists, skipped!", id);
            continue;
        }

        if (HasGroupName(name))
        {
            TC_LOG_ERROR("sql.sql", "Group name %s defined in `battle_pay_group` is invalid because a group of the same name already exists, skipped!", name, id);
            continue;
        }

        if (name.size() > MAX_BATTLE_PAY_GROUP_NAME_SIZE)
        {
            TC_LOG_ERROR("sql.sql", "Name for group id %u defined in `battle_pay_group` is too large (max %d), skipped!",
                id, MAX_BATTLE_PAY_GROUP_NAME_SIZE);

            continue;
        }

        if (type >= BATTLE_PAY_GROUP_TYPE_END)
        {
            TC_LOG_ERROR("sql.sql", "Group id %u defined in `battle_pay_group` has invalid group type %u, skipped!", id, type);
            continue;
        }

        m_groupStore.insert(new BattlePayProductGroup(id, order, name, icon, type));
        count++;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u Battle Pay store groups in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

    return true;
}

bool BattlePayMgr::LoadEntriesFromDb()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT id, `order`, groupId, productId, flags, banner FROM battle_pay_entry");
    if (!result)
    {
        TC_LOG_INFO("sql.sql", ">> Loaded 0 Battle Pay store entries, table `battle_pay_entry` is empty!");
        return false;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();

        uint32 id        = fields[0].GetUInt32();
        uint32 order     = fields[1].GetUInt32();
        uint32 groupId   = fields[2].GetUInt32();
        uint32 productId = fields[3].GetUInt32();
        uint32 flags     = fields[4].GetUInt32();
        uint32 banner    = fields[5].GetUInt32();

        if (!id)
        {
            TC_LOG_ERROR("sql.sql", "Id defined in `battle_pay_entry` is invalid because it has a value of 0, skipped!");
            continue;
        }

        if (!HasGroupId(groupId))
        {
            TC_LOG_ERROR("sql.sql", "Group id %u for entry id %u defined in `battle_pay_entry` is invalid because the group doesn't exists, skipped!", groupId, id);
            continue;
        }

        if (!HasProductId(productId))
        {
            TC_LOG_ERROR("sql.sql", "Product id %u for entry id %u defined in `battle_pay_entry` is invalid because the group doesn't exists, skipped!", productId, id);
            continue;
        }

        if (banner >= BATTLE_PAY_BANNER_TYPE_END)
        {
            TC_LOG_ERROR("sql.sql", "Entry id %u defined in `battle_pay_entry` has invalid banner type %u, skipped!", id, banner);
            continue;
        }

        m_shopEntryStore.insert(new BattlePayShopEntry(id, order, groupId, productId, flags, banner));
        count++;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u Battle Pay store entries in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

    return true;
}

bool BattlePayMgr::HasProductId(uint32 id)
{
    for (BattlePayProductSet::const_iterator citr = m_productStore.begin(); citr != m_productStore.end(); ++citr)
        if ((*citr)->ID == id)
            return true;

    return false;
}

bool BattlePayMgr::HasGroupId(uint32 id)
{
    for (BattlePayProductGroupSet::const_iterator citr = m_groupStore.begin(); citr != m_groupStore.end(); ++citr)
        if ((*citr)->GroupID == id)
            return true;

    return false;
}

bool BattlePayMgr::HasGroupName(std::string name)
{
    for (BattlePayProductGroupSet::const_iterator citr = m_groupStore.begin(); citr != m_groupStore.end(); ++citr)
        if ((*citr)->Name == name)
            return true;

    return false;
}

void BattlePayMgr::SendBattlePayPurchaseList()
{
    WorldPackets::BattlePay::BattlePayGetPurchaseListResponse response;
    response.Result = 0;

    for (auto const& p : response.Purchases)
    {
        WorldPackets::BattlePay::BattlePayPurchase purchase;
        response.Purchases.push_back(purchase);
    }

    session->SendPacket(response.Write());
}

void BattlePayMgr::SendBattlePayDistributionList()
{
    WorldPackets::BattlePay::BattlePayGetDistributionListResponse response;
    response.Result = 0;

    for (auto const& p : response.DistributionObjects)
    {
        WorldPackets::BattlePay::BattlePayDistributionObject object;

        /*object.ProductID = 0;
        object.Product = boost::in_place();
        object.Revoked = false;
        object.Status = 0;
        object.TargetNativeRealm = 0;
        object.TargetVirtualRealm = 0;
        object.DistributionID = 0;
        object.TargetPlayer = _owner->GetGUID();*/
        response.DistributionObjects.push_back(object);
    }

    session->SendPacket(response.Write());
}

void BattlePayMgr::SendBattlePayUpdateVasPurchaseStates()
{
}

void BattlePayMgr::SendBattlePayProductList()
{
    WorldPackets::BattlePay::BattlePayGetProductListResponse response;

    response.Result = 0; // BATTLE_PAY_RESULT_PRODUCT_LISTED
    response.CurrencyID = sBattlePayMgr->GetStoreCurrency();

    for (auto const& p : response.Products)
    {
        WorldPackets::BattlePay::BattlePayProduct product;
        /*product.ProductID = GetProductID();
        product.DisplayInfo = boost::in_place();
        product.CurrentPriceFixedPoint = 0;
        product.Flags = 0;
        product.NormalPriceFixedPoint = 0;*/

        for (auto const& i : product.Items)
        {
            WorldPackets::BattlePay::BattlePayProductItem item;
            /*item.ID = 0;
            item.ItemID = 0;
            item.DisplayInfo = boost::in_place();
            item.HasMount = false;
            item.PetResult = boost::in_place();
            item.Quantity = 0;
            item.HasPet = false;*/
            product.Items.push_back(item);
        }

        /*product.Type = BATTLE_PAY_TYPE_END;
        product.Unk62_1 = 0;*/
        response.Products.push_back(product);
    }

    for (auto const& p : response.Groups)
    {
        WorldPackets::BattlePay::BattlePayProductGroup group;
        /*group.GroupID = 0;
        group.IconFileDataID = 0;
        group.DisplayType = 0;
        group.Ordering = 0;*/
        response.Groups.push_back(group);
    }

    for (auto const& p : response.ShopEntries)
    {
        WorldPackets::BattlePay::BattlePayShopEntry entry;
        /*entry.Ordering = 0;
        entry.EntryID = 0;
        entry.DisplayInfo = boost::in_place();
        entry.BannerType = 0;
        entry.Flags = 0;
        entry.ProductID = 0;
        entry.GroupID = 0;*/
        response.ShopEntries.push_back(entry);
    }

    TC_LOG_INFO("network", "WORLD: Received SMSG_BATTLE_PAY_GET_PRODUCT_LIST");
    session->SendPacket(response.Write());
}
