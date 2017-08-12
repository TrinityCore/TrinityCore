// Unknown creator
// Some errors fixed by CyBeR-PrO
// Edited by Rochet2

#include <ScriptPCH.h>
#include "Channel.h"
#include "Player.h"
#include "Chat.h"

// only use lowercase letters
// The strings are trimmed of whitespace and compared lowercase
// To add more checks, just add a new line to the checks array
static const char* checks[] = {
    "sytes",
    "instant",
    "dyndns",
    "no-ip",
    "http:",
    ".com",
    ".net",
    ".org",
    ".eu",
    ".fr",
    ".bg",
    ".info",
    ".br",
    "https:",
    "wow",
    "www.",
    "no-ip",
    ".zapto",
    ".biz",
    ".servegame",
    "wow", "wOw", "oxy", "0xy", "server", "сервер", "win", "вов", "оху", "project"
    "trevonwow",
    "megawow",
    "fatalwow",
    "uniforgiven-wow",
    "wow-autolouco",
    "heaven-wow",
    "fireballwow",
    "wowbrasilpa",
    "fatalitywow",
    "demonic-wow",
    "revenge-wow",
    "heavenwow",
    "undead-wow",
    "linebr",
    "azralon",
    "black-wow",
};

static const size_t checksize = sizeof(checks) / sizeof(*checks);
class System_Censure : public PlayerScript
{
public:
    System_Censure() : PlayerScript("System_Censure") { }

    void CheckMessage(Player* player, std::string& msg, uint32 lang)
    {
        if (player->IsGameMaster() || lang == LANG_ADDON)
            return;

        // remove all space characters and transform to lowercase for simpler checking
        std::string checkmsg = msg;
        checkmsg.erase(remove_if(checkmsg.begin(), checkmsg.end(), ::isspace), checkmsg.end());
        std::transform(checkmsg.begin(), checkmsg.end(), checkmsg.begin(), ::tolower);

        for (size_t i = 0; i < checksize; ++i)
        {
            if (checkmsg.find(checks[i]) != std::string::npos)
            {
                msg = "";
                ChatHandler(player->GetSession()).PSendSysMessage("Нельзя рекламировать!");
                return;
            }
        }
    };

    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg) override
    {
        CheckMessage(player, msg, lang);
    }

    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Player* /*receiver*/) override
    {
        CheckMessage(player, msg, lang);
    }

    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Group* /*group*/) override
    {
        CheckMessage(player, msg, lang);
    }

    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Guild* /*guild*/) override
    {
        CheckMessage(player, msg, lang);
    }

    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Channel* /*channel*/) override
    {
        CheckMessage(player, msg, lang);
    }
};

void AddSC_System_Censure()
{
    new System_Censure();
}

