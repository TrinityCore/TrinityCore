#include "../pchdef.h"
#include "Category.h"
#include "ItemBag.h"
#include "AhBotConfig.h"
#include "PricingStrategy.h"

using namespace ahbot;

uint32 Category::GetStackCount(ItemTemplate const* proto)
{
    if (proto->Quality > ITEM_QUALITY_UNCOMMON)
        return 1;

    return urand(1, proto->GetMaxStackSize());
}

uint32 Category::GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
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

bool QualityCategoryWrapper::Contains(ItemTemplate const* proto)
{
    return proto->Quality == quality && category->Contains(proto);
}

uint32 QualityCategoryWrapper::GetMaxAllowedAuctionCount()
{
    uint32 count = sAhBotConfig.GetMaxAllowedAuctionCount(combinedName);
    return count > 0 ? count : category->GetMaxAllowedAuctionCount();
}

uint32 QualityCategoryWrapper::GetMaxAllowedItemAuctionCount(ItemTemplate const* proto)
{
    return category->GetMaxAllowedItemAuctionCount(proto);
}
