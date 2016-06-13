#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "LineTargetValue.h"

using namespace ai;

Unit* LineTargetValue::Calculate()
{
    Player* master = GetMaster();
    if (!master)
        return NULL;

    Group* group = master->GetGroup();
    if (!group)
        return NULL;

    Player *prev = master;
    Group::MemberSlotList const& groupSlot = group->GetMemberSlots();
    for (Group::member_citerator itr = groupSlot.begin(); itr != groupSlot.end(); itr++)
    {
        Player *player = sObjectMgr->GetPlayerByLowGUID(itr->guid);
        if( !player || !player->IsAlive() || player == master)
            continue;

        if (player == bot)
            return prev;

        prev = player;
    }

    return master;
}

