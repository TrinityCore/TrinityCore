#include "ScriptMgr.h"
#include "Chat.h"
#include <vector>
// Use printf until we figure out how to use TC_LOG_* 
// without buffering
#include <stdio.h>
#include <fstream>
#include <string>

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

class wp_tswow : public CommandScript
{
public:
    wp_tswow() : CommandScript("wp_tswow") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        // TODO: Add our own rbac permission here
        std::vector<ChatCommand> commandTable = {
            { "at", rbac::RBAC_PERM_AT, false, &At, ""},
            { "clearat", rbac::RBAC_PERM_CLEAR_AT, false, &ClearAt, ""},
            { "id", rbac::RBAC_PERM_ID, false, &Id, ""}
        };
        return commandTable;
    }

    static bool Id(ChatHandler* handler, char const* args)
    {
        Creature* target = handler->getSelectedCreature();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* player = handler->GetPlayer();
        if (player) {
            CreatureTemplate const* cInfo = target->GetCreatureTemplate();
            ChatHandler(player->GetSession())
                .SendSysMessage(cInfo->Name+" "+std::to_string(cInfo->Entry));
        }
    }

    static bool ClearAt(ChatHandler* handler, char const* args)
    {
        std::ofstream outfile;
        outfile.open("../../positions.txt", std::ofstream::out | std::ofstream::trunc);
        Player* player = handler->GetPlayer();
        if (player) {
            ChatHandler(player->GetSession())
                .SendSysMessage("Cleared positions file.");
        }
        return true;
    }

    static bool At(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetPlayer();
        // Can't do this command without player
        if (!player)
        {
            return false;
        }

        std::string str = "{" +
            std::string("map:")+std::to_string(player->GetMap()->GetId()) + "," +
            std::string("x:")+std::to_string(player->GetPositionX()) + "," +
            std::string("y:")+std::to_string(player->GetPositionY()) + "," +
            std::string("z:")+std::to_string(player->GetPositionZ()) + "," +
            std::string("o:")+std::to_string(player->GetOrientation()) + "},";

        if(args && strlen(args)>0)
        {
            str += " // ";
            str+=args;
        }

        ChatHandler(player->GetSession()).SendSysMessage(("Wrote " + str).c_str());
        std::ofstream outfile;
        outfile.open("../../positions.txt", std::ios_base::app);
        outfile << str << "\n";
        return true;
    }
};

void AddSC_tswow_commandscript()
{
    new wp_tswow();
}
