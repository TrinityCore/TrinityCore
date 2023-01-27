#include "botpch.h"
#include "../../playerbot.h"
#include "HireAction.h"

using namespace ai;

bool HireAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    if (!sRandomPlayerbotMgr.IsRandomBot(bot))
        return false;

    uint32 account = sObjectMgr.GetPlayerAccountIdByGUID(master->GetObjectGuid());
    QueryResult* results = CharacterDatabase.PQuery("SELECT count(*) FROM characters where account = '%u'", account);

    uint32 charCount = 10;
    if (results)
    {
        Field* fields = results->Fetch();
        charCount = fields[0].GetUInt32();
        delete results;
    }

    if (charCount >= 10)
    {
        ai->TellMaster("You already have the maximum number of characters");
        return false;
    }

    if ((int)bot->getLevel() > (int)master->getLevel())
    {
        ai->TellMaster("You cannot hire higher level characters than you");
        return false;
    }

    uint32 discount = sRandomPlayerbotMgr.GetTradeDiscount(bot, master);
    uint32 moneyReq = 10000 * bot->getLevel();
    if ((int)discount < (int)moneyReq)
    {
        ostringstream out;
        out << "You cannot hire me - I barely know you. Make sure you have at least " << chat->formatMoney(moneyReq) << " as a trade discount";
        ai->TellMaster(out.str());
        return false;
    }

    ai->TellMaster("I will join you at your next relogin");

    sRandomPlayerbotMgr.Remove(bot);
    CharacterDatabase.PExecute("update characters set account = '%u' where guid = '%u'",
            account, bot->GetObjectGuid().GetRawValue());

    return true;
}
