
#include "ScriptMgr.h"
#include "BattlePayMgr.h"
#include "BattlePayData.h"

class battlepay_commandscript : public CommandScript
{
public:
    battlepay_commandscript() : CommandScript("battlepay_commandscript") { }

    /*std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> BattlepayCommandTable =
        {
            { "reload",                 SEC_ADMINISTRATOR,  false,  &HandleReloadBattlePay,         ""}
        };

        static std::vector<ChatCommand> CommandTable =
        {
             { "battlepay",             SEC_ADMINISTRATOR,  true,   nullptr,                        "", BattlepayCommandTable }
        };

        return CommandTable;
    }*/

    static bool HandleReloadBattlePay(ChatHandler* /*chatHandler*/, char const* /*args*/)
    {
        //sBattlepayMgr->();
        sBattlePayDataStore->Initialize();
        return true;
    }
};

void AddSC_battlepay_commandscript()
{
    //new battlepay_commandscript();
}
