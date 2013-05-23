/* GamingConsortium .rates command */

#include "ScriptMgr.h"
#include "Chat.h"

class rates_commandscript : public CommandScript
{
public:
    rates_commandscript() : CommandScript("rates_commandscript") { }
    ChatCommand* GetCommands() const
    {
        static ChatCommand commandTable[] =
        {
            { "rates",          SEC_PLAYER,         false, &HandleRatesCommand,               "", NULL },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }
    
    static bool HandleRatesCommand(ChatHandler* handler, const char* /*args*/)
    {
        Player * player = handler->GetSession()->GetPlayer();
        player->HandleRates();
        return true;
    }
};

void AddSC_rates_commandscript()
{
    new rates_commandscript();
}