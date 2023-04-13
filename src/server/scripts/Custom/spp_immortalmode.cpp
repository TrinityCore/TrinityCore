#include "ScriptMgr.h"
#include "Player.h"
#include "AccountMgr.h"
#include "Common.h"
#include "Config.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"

class ImmortalMode : public PlayerScript
{
public:
    ImmortalMode() : PlayerScript("ImmortalMode") {}

    void OnPlayerKilledByCreature(Creature* /*killer*/, Player* killed)
    {
        if (sConfigMgr->GetBoolDefault("ImmortalMode.PVE.Enable", false))
        {
            uint32 zoneid_conf = sConfigMgr->GetIntDefault("ImmortalMode.PVE.ZoneID", 0);
            uint32 zoneid = killed->GetZoneId();

            if (zoneid_conf > 0)
            {
                if (zoneid_conf == zoneid)
                {
                    killed->ResurrectPlayer(1.0f);
                    killed->SaveToDB();
                }
                else
                    return;
            }
            else
            {
                killed->ResurrectPlayer(1.0f);
                killed->SaveToDB();
            }
        }
    }

    void OnPVPKill(Player* /*killer*/, Player* killed)
    {
        if (sConfigMgr->GetBoolDefault("ImmortalMode.PVP.Enable", true))
        {
            uint32 zoneid_conf = sConfigMgr->GetIntDefault("ImmortalMode.PVP.ZoneID", 0);
            uint32 zoneid = killed->GetZoneId();

            if (zoneid_conf > 0)
            {
                if (zoneid_conf == zoneid)
                {
                    killed->ResurrectPlayer(1.0f);
                    killed->SaveToDB();
                }
                else
                    return;
            }
            else
            {
                killed->ResurrectPlayer(1.0f);
                killed->SaveToDB();
            }
        }
    }
};

void AddSC_AutoReviveScripts()
{
    new ImmortalMode();
}
