//来源:OpenLCore
//地址:https://github.com/openlcoreteam/OpenLCore/blob/master/src/server/scripts/Custom/debug_lfg.cpp

//发现我已经通过自定义配置实现了,白忙活了

#include "Config.h"
#include "World.h"
#include "LFGMgr.h"
#include "Chat.h"

class debug_lfg : public PlayerScript
{
public:
    debug_lfg() : PlayerScript("debug_lfg") { }

    void OnLogin(Player* /*player*/, bool /*loginFirst*/)
    {
        if (sConfigMgr->GetBoolDefault("Debug.LFG", true))
            if (!sLFGMgr->IsTesting())
                sLFGMgr->ToggleTesting();
    }
};

void AddSC_debug_lfg()
{
    new debug_lfg();
}
