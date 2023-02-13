#include "botpch.h"
#include "../../playerbot.h"
#include "LootRollAction.h"

#include "../values/ItemUsageValue.h"

using namespace ai;

bool LootRollAction::Execute(Event event)
{
    Player *bot = QueryItemUsageAction::ai->GetBot();

    WorldPacket p(event.getPacket()); //WorldPacket packet for CMSG_LOOT_ROLL, (8+4+1)
    ObjectGuid guid;
    uint32 slot;
    uint8 rollType;
    p.rpos(0); //reset packet pointer
    p >> guid; //guid of the item rolled
    p >> slot; //number of players invited to roll
    p >> rollType; //need,greed or pass on roll

    Group* group = bot->GetGroup();
    if(!group)
        return false;

#ifdef MANGOS
    RollVote vote = ROLL_PASS;
    for (vector<Roll*>::iterator i = group->GetRolls().begin(); i != group->GetRolls().end(); ++i)
    {
        if ((*i)->isValid() && (*i)->lootedTargetGUID == guid && (*i)->itemSlot == slot)
        {
            uint32 itemId = (*i)->itemid;
            ItemPrototype const *proto = sItemStorage.LookupEntry<ItemPrototype>(itemId);
            if (!proto)
                continue;

            vote = CalculateRollVote(proto);
            if (vote != ROLL_PASS) break;
        }
    }

    switch (group->GetLootMethod())
    {
    case MASTER_LOOT:
    case FREE_FOR_ALL:
        group->CountRollVote(bot, guid, slot, ROLL_PASS);
        break;
    default:
        group->CountRollVote(bot, guid, slot, vote);
        break;
    }
#endif

#ifdef CMANGOS
    Loot* loot = sLootMgr.GetLoot(bot, guid);
    if (!loot)
        return false;

    LootItem* item = loot->GetLootItemInSlot(slot);
    ItemPrototype const *proto = sItemStorage.LookupEntry<ItemPrototype>(item->itemId);
    if (!proto)
        return false;

    RollVote vote = CalculateRollVote(proto);

    GroupLootRoll* lootRoll = loot->GetRollForSlot(slot);
    if (!lootRoll)
        return false;

    lootRoll->PlayerVote(bot, vote);
#endif

    return true;
}

RollVote LootRollAction::CalculateRollVote(ItemPrototype const *proto)
{
    ostringstream out; out << proto->ItemId;
    ItemUsage usage = AI_VALUE2(ItemUsage, "item usage", out.str());

    RollVote needVote = ROLL_GREED;
    switch (usage)
    {
    case ITEM_USAGE_EQUIP:
    case ITEM_USAGE_REPLACE:
    case ITEM_USAGE_GUILD_TASK:
        needVote = ROLL_NEED;
        break;
    case ITEM_USAGE_SKILL:
    case ITEM_USAGE_USE:
    case ITEM_USAGE_DISENCHANT:
        needVote = ROLL_GREED;
        break;
    }

    return StoreLootAction::IsLootAllowed(proto->ItemId, bot->GetPlayerbotAI()) ? needVote : ROLL_PASS;
}
