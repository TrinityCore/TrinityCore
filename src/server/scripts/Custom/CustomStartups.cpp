//#include "Config.h"
//#include "Chat.h"
//#include "Log.h"
//#include "ScriptMgr.h"
//
//namespace {
//
//    class OnNewCharFirstLogin : public PlayerScript
//    {
//
//    public:
//        OnNewCharFirstLogin() : PlayerScript("OnNewCharFirstLogin")
//        {
//        }
//
//        // run at first login of a new character
//        void OnLogin(Player* player, bool firstLogin) override
//        {
//            if (firstLogin)
//            {
//                ChatHandler(player->GetSession()).SendSysMessage("|cffFF0000LegionCore |r");
//            }
//        }
//    };
//}
//
//class OnWorldserverLoaded : public WorldScript
//{
//public:
//    OnWorldserverLoaded() : WorldScript("OnWorldserverLoaded") {}
//
//    // run always when worldserver has loaded
//    void OnStartup() override
//    {
//        //TC_LOG_INFO(LOG_FILTER_WORLDSERVER, "LegionCore loaded...");
//    }
//};
//
//void AddSC_CustomStartups() {
//    new OnNewCharFirstLogin();
//    new OnWorldserverLoaded();
//}
