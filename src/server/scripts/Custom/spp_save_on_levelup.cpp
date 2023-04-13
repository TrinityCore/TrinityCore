/*
Single Player Project
*/

#include "Chat.h"
#include "Config.h"
#include "ScriptMgr.h"

class spp_save_on_levelup : public PlayerScript
{
public:
    spp_save_on_levelup() : PlayerScript("spp_save_on_levelup") { };

    void OnLevelChanged(Player* player, uint8 /*oldLevel*/)
    {
        if (sConfigMgr->GetBoolDefault("Save.On.LevelUp", true))
        {
            if (sConfigMgr->GetBoolDefault("Save.On.LevelUp.Announcer", true))
            {
                ChatHandler(player->GetSession()).SendSysMessage("Characters saved on the server.");
            }

            ObjectAccessor::SaveAllPlayers();
        }
    }
};

void AddSC_save_on_levelup()
{
    new spp_save_on_levelup();
}
