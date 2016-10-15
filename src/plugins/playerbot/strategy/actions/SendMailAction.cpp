#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "SendMailAction.h"
#include "../../PlayerbotAIConfig.h"

using namespace ai;

bool SendMailAction::Execute(Event event)
{
    Player* master = GetMaster();
    if (!master)
        return false;

    list<ObjectGuid> gos = *context->GetValue<list<ObjectGuid> >("nearest game objects");
    bool mailboxFound = false;
    for (list<ObjectGuid>::iterator i = gos.begin(); i != gos.end(); ++i)
    {
        GameObject* go = ai->GetGameObject(*i);
        if (go && go->GetGoType() == GAMEOBJECT_TYPE_MAILBOX)
        {
            mailboxFound = true;
            break;
        }
    }

    if (!mailboxFound)
    {
        ai->TellMaster("There is no mailbox nearby");
        return false;
    }

    string text = event.getParam();

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    ostringstream body;
    body << "Hello, " << master->GetName() << ",\n";
    body << "\n";
    body << "Here are the items you asked for";
    body << "\n";
    body << "Thanks,\n";
    body << bot->GetName() << "\n";

    ItemIds ids = chat->parseItems(text);
    if (ids.size() > 12)
    {
        ai->TellMaster("You can request no more than 12 items");
        return false;
    }

    MailDraft draft("Items you asked for", body.str());
    for (ItemIds::iterator i =ids.begin(); i != ids.end(); i++)
    {
        FindItemByIdVisitor visitor(*i);
        IterateItems(&visitor, ITERATE_ITEMS_IN_BAGS);
        list<Item*> items = visitor.GetResult();
        for (list<Item*>::iterator i = items.begin(); i != items.end(); ++i)
        {
            Item* item = *i;
            if (item->IsSoulBound() || item->IsConjuredConsumable())
            {
                ostringstream out;
                out << "Cannot send " << ChatHelper::formatItem(item->GetTemplate());
                ai->TellMaster(out);
                continue;
            }

            ItemTemplate const *proto = item->GetTemplate();
            item->SetNotRefundable(bot);
            bot->MoveItemFromInventory(item->GetBagSlot(), item->GetSlot(), true);
            item->DeleteFromInventoryDB(trans);
            item->SetOwnerGUID(master->GetGUID());
            item->SaveToDB(trans);
            draft.AddItem(item);
        }
    }

    draft.SendMailTo(trans, MailReceiver(master), MailSender(bot));
    CharacterDatabase.CommitTransaction(trans);

    ai->TellMaster("Mail sent");
    return true;
}
