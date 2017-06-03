#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "StatsAction.h"


using namespace ai;

bool StatsAction::Execute(Event event)
{
    ostringstream out;

    ListGold(out);

    out << ", ";
    ListBagSlots(out);

    out << ", ";
    ListRepairCost(out);

    if (bot->GetUInt32Value(PLAYER_NEXT_LEVEL_XP))
    {
        out << ", ";
        ListXP(out);
    }

    ai->TellMaster(out);
    return true;
}

void StatsAction::ListGold(ostringstream &out)
{
    out << chat->formatMoney(bot->GetMoney());
}

void StatsAction::ListBagSlots(ostringstream &out)
{
    uint32 totalused = 0, total = 16;
    // list out items in main backpack
    for (uint8 slot = INVENTORY_SLOT_ITEM_START; slot < INVENTORY_SLOT_ITEM_END; slot++)
    {
        const Item* const pItem = bot->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
        if (pItem)
            totalused++;
    }
    uint32 totalfree = 16 - totalused;
    // list out items in other removable backpacks
    for (uint8 bag = INVENTORY_SLOT_BAG_START; bag < INVENTORY_SLOT_BAG_END; ++bag)
    {
        const Bag* const pBag = (Bag*) bot->GetItemByPos(INVENTORY_SLOT_BAG_0, bag);
        if (pBag)
        {
            ItemTemplate const* pBagProto = pBag->GetTemplate();
            if (pBagProto->Class == ITEM_CLASS_CONTAINER && pBagProto->SubClass == ITEM_SUBCLASS_CONTAINER)
            {
                total += pBag->GetBagSize();
                totalfree += pBag->GetFreeSlots();
            }
        }

    }

	string color = "ff00ff00";
	if (totalfree < total / 2)
		color = "ffffff00";
	if (totalfree < total / 4)
		color = "ffff0000";
    out << "|h|c" << color << (total - totalfree) << "/" << total << "|h|cffffffff Bag";
}

void StatsAction::ListXP( ostringstream &out )
{
    uint32 curXP = bot->GetUInt32Value(PLAYER_XP);
    uint32 nextLevelXP = bot->GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
    uint32 xpPercent = 0;
    if (nextLevelXP)
        xpPercent = 100 * curXP / nextLevelXP;

    out << "|r|cff00ff00" << xpPercent << "|r|cffffd333%" << "|h|cffffffff XP";
}

void StatsAction::ListRepairCost(ostringstream &out)
{
    out << chat->formatMoney(EstRepairAll()) << " Repair";
}

uint32 StatsAction::EstRepairAll()
{
    uint32 TotalCost = 0;
    // equipped, backpack, bags itself
    for(int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        TotalCost += EstRepair(( (INVENTORY_SLOT_BAG_0 << 8) | i ));

    // bank, buyback and keys not repaired

    // items in inventory bags
    for(int j = INVENTORY_SLOT_BAG_START; j < INVENTORY_SLOT_BAG_END; ++j)
        for(int i = 0; i < MAX_BAG_SIZE; ++i)
            TotalCost += EstRepair(( (j << 8) | i ));
    return TotalCost;
}

uint32 StatsAction::EstRepair(uint16 pos)
{
    Item* item = bot->GetItemByPos(pos);

    uint32 TotalCost = 0;
    if(!item)
        return TotalCost;

    uint32 maxDurability = item->GetUInt32Value(ITEM_FIELD_MAXDURABILITY);
    if(!maxDurability)
        return TotalCost;

    uint32 curDurability = item->GetUInt32Value(ITEM_FIELD_DURABILITY);

    uint32 LostDurability = maxDurability - curDurability;
    if(LostDurability>0)
    {
        ItemTemplate const *ditemProto = item->GetTemplate();

        DurabilityCostsEntry const *dcost = sDurabilityCostsStore.LookupEntry(ditemProto->ItemLevel);
        if(!dcost)
        {
            sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "RepairDurability: Wrong item lvl %u", ditemProto->ItemLevel);
            return TotalCost;
        }

        uint32 dQualitymodEntryId = (ditemProto->Quality+1)*2;
        DurabilityQualityEntry const *dQualitymodEntry = sDurabilityQualityStore.LookupEntry(dQualitymodEntryId);
        if(!dQualitymodEntry)
        {
            sLog->outMessage("playerbot", LOG_LEVEL_ERROR, "RepairDurability: Wrong dQualityModEntry %u", dQualitymodEntryId);
            return TotalCost;
        }

        uint32 dmultiplier = dcost->multiplier[ItemSubClassToDurabilityMultiplierId(ditemProto->Class,ditemProto->SubClass)];
        uint32 costs = uint32(LostDurability*dmultiplier*double(dQualitymodEntry->quality_mod));

        if (costs==0)                                   //fix for ITEM_QUALITY_ARTIFACT
            costs = 1;

        TotalCost = costs;
    }
    return TotalCost;
}
