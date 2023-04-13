#include "Configuration/Config.h"
#include "Player.h"
#include "Creature.h"
#include "AccountMgr.h"
#include "ScriptMgr.h"
#include "Define.h"
#include "GossipDef.h"
#include "WorldSession.h"
#include "AppenderConsole.h"
#include "LogMessage.h"
#include "Util.h"
#include <sstream>
#include "Log.h"

class WhoLoggedAnnounce : public PlayerScript
{
public:
    WhoLoggedAnnounce() : PlayerScript("WhoLoggedAnnounce") { }


    void OnLogin(Player* p, bool)
    {
        std::string playerIP = p->GetSession()->GetRemoteAddress();
        std::string playerName = p->GetName();
        uint32 pAccountID = p->GetSession()->GetAccountId();
        uint32 pLevel = p->getLevel();
        std::string pClass;
        std::ostringstream message;


        if (!sConfigMgr->GetBoolDefault("Who-logged.console", true))
        {
            return;
        }

        switch (p->getClass())
        {
        case CLASS_WARLOCK:
            pClass = "Warlock";
            break;
        case CLASS_WARRIOR:
            pClass = "Warrior";
            break;
        case CLASS_MAGE:
            pClass = "Mage";
            break;
        case CLASS_SHAMAN:
            pClass = "Shaman";
            break;
        case CLASS_DEATH_KNIGHT:
            pClass = "Death Knight";
            break;
        case CLASS_DRUID:
            pClass = "Druid";
            break;
        case CLASS_HUNTER:
            pClass = "Hunter";
            break;
        case CLASS_PALADIN:
            pClass = "Paladin";
            break;
        case CLASS_ROGUE:
            pClass = "Rogue";
            break;
        case CLASS_PRIEST:
            pClass = "Priest";
            break;
        case CLASS_DEMON_HUNTER:
            pClass = "Demon Hunter";
            break;
        case CLASS_MONK:
            pClass = "Monk";
            break;
        }

        //SetColor(true, CYAN);
        TC_LOG_INFO("server.worldserver", "Player '%s' has logged in : Level '%u' : Class '%s' : IP '%s' : AccountID '%u'", playerName.c_str(), pLevel, pClass.c_str(), playerIP.c_str(), pAccountID);
        //ResetColor(true);
    }
};

void AddSC_WhoLoggedScripts()
{
    new WhoLoggedAnnounce();
}
