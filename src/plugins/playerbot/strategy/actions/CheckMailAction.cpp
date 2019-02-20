#include "../../../pchdef.h"
#include "../../playerbot.h"
#include "CheckMailAction.h"

#include "../../GuildTaskMgr.h"
using namespace ai;

bool CheckMailAction::Execute(Event event)
{
    if (!bot->IsMailsLoaded())
    {
        WorldPacket p;
        bot->GetSession()->HandleQueryNextMailTime(p);
    }

    if (!bot->GetMailSize())
        return false;

    list<uint32> ids;
    for (PlayerMails::iterator i = bot->GetMailBegin(); i != bot->GetMailEnd(); ++i)
    {
        Mail* mail = *i;

        if (!mail || mail->state == MAIL_STATE_DELETED)
            continue;

        Player* owner = sObjectMgr->GetPlayerByLowGUID(mail->sender);
        if (!owner)
            continue;

        ProcessMail(mail, owner);
        ids.push_back(mail->messageID);
        mail->state = MAIL_STATE_DELETED;
    }

    for (list<uint32>::iterator i = ids.begin(); i != ids.end(); ++i)
    {
        uint32 id = *i;
        bot->SendMailResult(id, MAIL_DELETED, MAIL_OK);
        SQLTransaction tran = CharacterDatabase.BeginTransaction();
        CharacterDatabase.PExecute("DELETE FROM mail WHERE id = '%u'", id);
        CharacterDatabase.PExecute("DELETE FROM mail_items WHERE mail_id = '%u'", id);
        CharacterDatabase.CommitTransaction(tran);
        bot->RemoveMail(id);
    }

    return true;
}


void CheckMailAction::ProcessMail(Mail* mail, Player* owner)
{
    if (!mail->HasItems())
        return;

    for (MailItemInfoVec::iterator i = mail->items.begin(); i != mail->items.end(); ++i)
    {
        Item *item = bot->GetMItem(i->item_guid);
        if (!item)
            continue;

        sGuildTaskMgr.CheckItemTask(i->item_template, item->GetCount(), owner, bot, true);
        bot->RemoveMItem(i->item_guid);
        item->DestroyForPlayer(bot);
    }
}