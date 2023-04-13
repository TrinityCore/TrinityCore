//#include "Config.h"
//#include "World.h"
//#include "LFGMgr.h"
//#include "Chat.h"
//
//class spp_lfg_solo : public PlayerScript
//{
//public:
//    spp_lfg_solo() : PlayerScript("spp_lfg_solo") { }
//
//    void OnLogin(Player* player, bool /*loginFirst*/)
//    {
//        if (sConfigMgr->GetBoolDefault("LFG.SoloMode", true))
//        {
//            if (!sLFGMgr->IsTesting())
//            {
//                sLFGMgr->ToggleTesting();
//            }
//        }
//    }
//};
//
//void AddSC_LFG_SoloMode()
//{
//    new spp_lfg_solo;
//}
