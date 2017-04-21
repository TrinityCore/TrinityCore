#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "LootRollAction.h"
#include "../../../Groups/Group.h"


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

    RollVote vote = PASS;
    for (vector<Roll*>::iterator i = group->GetRolls()->begin(); i != group->GetRolls()->end(); ++i)
    {
        if ((*i)->isValid() && (*i)->itemGUID == guid && (*i)->itemSlot == slot)
        {
            uint32 itemId = (*i)->itemid;
            ItemTemplate const *proto = sObjectMgr->GetItemTemplate(itemId);
            if (!proto)
                continue;

            switch (proto->Class)
            {
            case ITEM_CLASS_WEAPON:
            case ITEM_CLASS_ARMOR:
                if (QueryItemUsage(proto))
                    vote = NEED;
                else if (bot->HasSkill(SKILL_ENCHANTING))
                    vote = DISENCHANT;
                break;
            default:
                if (IsLootAllowed(itemId))
                    vote = NEED;
                break;
            }
            break;
        }
    }

    switch (group->GetLootMethod())
    {
    case MASTER_LOOT:
    case FREE_FOR_ALL:
        group->CountRollVote(bot->GetGUID(), guid, PASS);
        break;
    default:
        group->CountRollVote(bot->GetGUID(), guid, vote);
        break;
    }

    return true;
}
