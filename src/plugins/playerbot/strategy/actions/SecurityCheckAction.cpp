#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "../../RandomPlayerbotMgr.h"
#include "SecurityCheckAction.h"
#include "../../../Groups/Group.h"

using namespace ai;


bool SecurityCheckAction::isUseful()
{
    return sRandomPlayerbotMgr.IsRandomBot(bot) && ai->GetMaster() && ai->GetMaster()->GetSession()->GetSecurity() < SEC_GAMEMASTER;
}

bool SecurityCheckAction::Execute(Event event)
{
    Group* group = bot->GetGroup();
    if (group)
    {
        LootMethod method = group->GetLootMethod();
        ItemQualities threshold = group->GetLootThreshold();
        if (method == MASTER_LOOT || method == FREE_FOR_ALL || threshold > ITEM_QUALITY_UNCOMMON)
        {
            ai->TellMaster("I won't do anything until you change loot type to group loot with green threshold");
            ai->ChangeStrategy("+passive,+stay", BOT_STATE_NON_COMBAT);
            ai->ChangeStrategy("+passive,+stay", BOT_STATE_COMBAT);
            return true;
        }
    }
    return false;
}
