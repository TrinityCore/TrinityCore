#include "botpch.h"
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
            ItemPrototype const* pBagProto = pBag->GetProto();
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
    out << "|h|c" << color << totalfree << "/" << total << "|h|cffffffff Bag";
}

void StatsAction::ListXP( ostringstream &out )
{
    uint32 curXP = bot->GetUInt32Value(PLAYER_XP);
    uint32 nextLevelXP = bot->GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
    uint32 restXP = bot->GetUInt32Value(PLAYER_REST_STATE_EXPERIENCE);
    uint32 xpPercent = 0;

    if (nextLevelXP)
        xpPercent = 100 * curXP / nextLevelXP;
    uint32 restPercent = 0;
    if (restXP)
        restPercent = 2 * (100 * restXP / nextLevelXP);

    out << "|cff00ff00" << xpPercent << "|cffffd333/|cff00ff00" << restPercent << "%|cffffffff XP";
}

void StatsAction::ListRepairCost(ostringstream &out)
{
    uint32 totalCost = 0;
    double repairPercent = 0;
    double repairCount = 0;
    for(int i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
    {
        uint16 pos = ( (INVENTORY_SLOT_BAG_0 << 8) | i );
        totalCost += EstRepair(pos);
        double repair = RepairPercent(pos);
        if (repair < 100)
        {
            repairPercent += repair;
            repairCount++;
        }
    }
    repairPercent /= repairCount;

    string color = "ff00ff00";
    if (repairPercent < 50)
        color = "ffffff00";
    if (repairPercent < 25)
        color = "ffff0000";
    out << "|c" << color << (uint32)ceil(repairPercent) << "% (" << chat->formatMoney(totalCost) << ")|cffffffff Dur";
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
        ItemPrototype const *ditemProto = item->GetProto();

        DurabilityCostsEntry const *dcost = sDurabilityCostsStore.LookupEntry(ditemProto->ItemLevel);
        if(!dcost)
        {
            sLog.outError("RepairDurability: Wrong item lvl %u", ditemProto->ItemLevel);
            return TotalCost;
        }

        uint32 dQualitymodEntryId = (ditemProto->Quality+1)*2;
        DurabilityQualityEntry const *dQualitymodEntry = sDurabilityQualityStore.LookupEntry(dQualitymodEntryId);
        if(!dQualitymodEntry)
        {
            sLog.outError("RepairDurability: Wrong dQualityModEntry %u", dQualitymodEntryId);
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

double StatsAction::RepairPercent(uint16 pos)
{
    Item* item = bot->GetItemByPos(pos);
    if (!item)
        return 100;

    uint32 maxDurability = item->GetUInt32Value(ITEM_FIELD_MAXDURABILITY);
    if(!maxDurability)
        return 100;

    uint32 curDurability = item->GetUInt32Value(ITEM_FIELD_DURABILITY);
    if (!curDurability)
        return 0;

    return curDurability * 100.0 / maxDurability;
}
