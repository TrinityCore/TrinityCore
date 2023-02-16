#include "botpch.h"
#include "../../playerbot.h"
#include "CheckMailAction.h"
#include "Mail.h"

#include "../../GuildTaskMgr.h"
#include "../../PlayerbotAIConfig.h"
using namespace ai;

bool CheckMailAction::Execute(Event event)
{
    WorldPacket p;
    bot->GetSession()->HandleQueryNextMailTime(p);

    if (ai->GetMaster() || !bot->GetMailSize())
        return false;

    list<uint32> ids;
    for (PlayerMails::iterator i = bot->GetMailBegin(); i != bot->GetMailEnd(); ++i)
    {
        Mail* mail = *i;

        if (!mail || mail->state == MAIL_STATE_DELETED)
            continue;

        Player* owner = sObjectMgr.GetPlayer(ObjectGuid(HIGHGUID_PLAYER, mail->sender));
        if (!owner)
            continue;

        uint32 account = sObjectMgr.GetPlayerAccountIdByGUID(owner->GetObjectGuid());
        if (sPlayerbotAIConfig.IsInRandomAccountList(account))
            continue;

        ProcessMail(mail, owner);
        ids.push_back(mail->messageID);
        mail->state = MAIL_STATE_DELETED;
    }

    for (list<uint32>::iterator i = ids.begin(); i != ids.end(); ++i)
    {
        uint32 id = *i;
        bot->SendMailResult(id, MAIL_DELETED, MAIL_OK);
        CharacterDatabase.PExecute("DELETE FROM mail WHERE id = '%u'", id);
        CharacterDatabase.PExecute("DELETE FROM mail_items WHERE mail_id = '%u'", id);
        bot->RemoveMail(id);
    }

    return true;
}


void CheckMailAction::ProcessMail(Mail* mail, Player* owner)
{
    if (!mail->HasItems())
        return;

    if (mail->subject.find("Item(s) you asked for") != string::npos)
        return;

    for (MailItemInfoVec::iterator i = mail->items.begin(); i != mail->items.end(); ++i)
    {
        Item *item = bot->GetMItem(i->item_guid);
        if (!item)
            continue;

        if (!sGuildTaskMgr.CheckItemTask(i->item_template, item->GetCount(), owner, bot, true))
        {
            ostringstream body;
            body << "Hello, " << owner->GetName() << ",\n";
            body << "\n";
            body << "Here are the item(s) you've sent me by mistake";
            body << "\n";
            body << "Thanks,\n";
            body << bot->GetName() << "\n";

            MailDraft draft("Item(s) you've sent me", body.str());
            draft.AddItem(item);
            bot->RemoveMItem(i->item_guid);
            draft.SendMailTo(MailReceiver(owner), MailSender(bot));
            return;
        }

        bot->RemoveMItem(i->item_guid);
        item->DestroyForPlayer(bot);
    }
}
