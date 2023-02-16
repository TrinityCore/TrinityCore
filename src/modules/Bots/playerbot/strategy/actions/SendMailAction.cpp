#include "botpch.h"
#include "Mail.h"
#include "../../playerbot.h"
#include "SendMailAction.h"

#include "../../../ahbot/AhBot.h"
#include "../../PlayerbotAIConfig.h"

using namespace ai;

bool SendMailAction::Execute(Event event)
{
    uint32 account = sObjectMgr.GetPlayerAccountIdByGUID(bot->GetObjectGuid());
    bool randomBot = sPlayerbotAIConfig.IsInRandomAccountList(account);

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

    string text = event.getParam();
    Player* receiver = GetMaster();
    Player* tellTo = receiver;
    vector<string> ss = split(text, ' ');
    if (ss.size() > 1)
    {
        Player* p = sObjectMgr.GetPlayer(ss[ss.size() - 1].c_str());
        if (p) receiver = p;
    }

    if (!receiver) receiver = event.getOwner();

    if (!receiver || receiver == bot)
    {
        return false;
    }

    if (!tellTo) tellTo = receiver;

    if (!mailboxFound && !randomBot)
    {
        bot->Whisper("There is no mailbox nearby", LANG_UNIVERSAL, tellTo->GetObjectGuid());
        return false;
    }


    ItemIds ids = chat->parseItems(text);
    if (ids.size() > 1)
    {
        bot->Whisper("You can not request more than one item", LANG_UNIVERSAL, tellTo->GetObjectGuid());
        return false;
    }

    if (ids.empty())
    {
        uint32 money = chat->parseMoney(text);
        if (!money)
            return false;

        if (randomBot)
        {
            bot->Whisper("I cannot send money", LANG_UNIVERSAL, tellTo->GetObjectGuid());
            return false;
        }

        if (bot->GetMoney() < money)
        {
            ai->TellMaster("I don't have enough money");
            return false;
        }

        ostringstream body;
        body << "Hello, " << receiver->GetName() << ",\n";
        body << "\n";
        body << "Here is the money you asked for";
        body << "\n";
        body << "Thanks,\n";
        body << bot->GetName() << "\n";


        MailDraft draft("Money you asked for", body.str());
        draft.SetMoney(money);
        bot->SetMoney(bot->GetMoney() - money);
        draft.SendMailTo(MailReceiver(receiver), MailSender(bot));

        ostringstream out; out << "Sending mail to " << receiver->GetName();
        ai->TellMaster(out.str());
        return true;
    }

    ostringstream body;
    body << "Hello, " << receiver->GetName() << ",\n";
    body << "\n";
    body << "Here are the item(s) you asked for";
    body << "\n";
    body << "Thanks,\n";
    body << bot->GetName() << "\n";

    MailDraft draft("Item(s) you asked for", body.str());
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
                out << "Cannot send " << ChatHelper::formatItem(item->GetProto());
                bot->Whisper(out.str(), LANG_UNIVERSAL, tellTo->GetObjectGuid());
                continue;
            }

            ItemPrototype const *proto = item->GetProto();
            bot->MoveItemFromInventory(item->GetBagSlot(), item->GetSlot(), true);
            item->DeleteFromInventoryDB();
            item->SetOwnerGuid(receiver->GetObjectGuid());
            item->SaveToDB();
            draft.AddItem(item);
            if (randomBot)
            {
                uint32 price = item->GetCount() * auctionbot.GetSellPrice(proto);
                if (!price)
                {
                    ostringstream out;
                    out << ChatHelper::formatItem(item->GetProto()) << ": it is not for sale";
                    bot->Whisper(out.str(), LANG_UNIVERSAL, tellTo->GetObjectGuid());
                    return false;
                }
                draft.SetCOD(price);
            }
            draft.SendMailTo(MailReceiver(receiver), MailSender(bot));

            ostringstream out; out << "Sent mail to " << receiver->GetName();
            bot->Whisper(out.str(), LANG_UNIVERSAL, tellTo->GetObjectGuid());
            return true;
        }
    }

    return false;
}
