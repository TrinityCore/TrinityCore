#include "../botpch.h"
#include "Category.h"
#include "../playerbot/RandomItemMgr.h"
#include "ItemBag.h"
#include "AhBotConfig.h"
#include "PricingStrategy.h"
#include "ServerFacade.h"

using namespace ahbot;

uint32 Category::GetStackCount(ItemPrototype const* proto)
{
    if (proto->Quality > ITEM_QUALITY_UNCOMMON)
        return 1;

    double rarity = GetPricingStrategy()->GetRarityPriceMultiplier(proto->ItemId);
    return (uint32)max(1.0, proto->GetMaxStackSize() / rarity);
}

uint32 Category::GetMaxAllowedItemAuctionCount(ItemPrototype const* proto)
{
    return 0;
}

uint32 Category::GetMaxAllowedAuctionCount()
{
    return sAhBotConfig.GetMaxAllowedAuctionCount(GetName());
}

PricingStrategy* Category::GetPricingStrategy()
{
    if (pricingStrategy)
        return pricingStrategy;

    ostringstream out; out << "AhBot.PricingStrategy." << GetName();
    string name = sAhBotConfig.GetStringDefault(out.str().c_str(), "default");
    return pricingStrategy = PricingStrategyFactory::Create(name, this);
}

QualityCategoryWrapper::QualityCategoryWrapper(Category* category, uint32 quality) : Category(), quality(quality), category(category)
{
    ostringstream out; out << category->GetName() << ".";
    switch (quality)
    {
    case ITEM_QUALITY_POOR:
        out << "gray";
        break;
    case ITEM_QUALITY_NORMAL:
        out << "white";
        break;
    case ITEM_QUALITY_UNCOMMON:
        out << "green";
        break;
    case ITEM_QUALITY_RARE:
        out << "blue";
        break;
    default:
        out << "epic";
        break;
    }

    combinedName = out.str();
}

bool QualityCategoryWrapper::Contains(ItemPrototype const* proto)
{
    return proto->Quality == quality && category->Contains(proto);
}

uint32 QualityCategoryWrapper::GetMaxAllowedAuctionCount()
{
    uint32 count = sAhBotConfig.GetMaxAllowedAuctionCount(combinedName);
    return count > 0 ? count : category->GetMaxAllowedAuctionCount();
}

uint32 QualityCategoryWrapper::GetMaxAllowedItemAuctionCount(ItemPrototype const* proto)
{
    return category->GetMaxAllowedItemAuctionCount(proto);
}

