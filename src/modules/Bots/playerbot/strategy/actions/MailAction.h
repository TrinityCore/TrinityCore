#pragma once

#include "../Action.h"
#include "InventoryAction.h"

namespace ai
{

    class MailProcessor
    {
    public:
        virtual bool Before(PlayerbotAI* ai) { return true; }
        virtual bool Process(int index, Mail* mail, PlayerbotAI* ai) = 0;
        virtual bool After(PlayerbotAI* ai) { return true; }

    public:
        static ObjectGuid FindMailbox(PlayerbotAI* ai);

    protected:
        void RemoveMail(Player* bot, uint32 id, ObjectGuid mailbox);
    };


    class MailAction : public InventoryAction
    {
    public:
        MailAction(PlayerbotAI* ai) : InventoryAction(ai, "mail") {}

        virtual bool Execute(Event event);

    private:
        bool CheckMailbox();

    private:
        static map<string, MailProcessor*> processors;
    };

}
