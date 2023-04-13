///*
//Single Player Project
//*/
//
//#include "Config.h"
//#include "Chat.h"
//#include "Log.h"
//#include "ScriptMgr.h"
//
//namespace {
//
//    class spp_info : public PlayerScript
//    {
//
//    public:
//        spp_info() : PlayerScript("spp_info")
//        {
//        }
//
//        // Informations ingame
//        void OnLogin(Player* player, bool /*firstLogin*/) override
//        {
//            ChatHandler(player->GetSession()).SendSysMessage("This server based on |cffFF0000Single Player Project - Legion V2 |rrepack.");
//            ChatHandler(player->GetSession()).SendSysMessage("Website:|cffADD8E6 spp-forum.de |r");
//        }
//    };
//}
//
//class PrepareToPlay : public WorldScript
//{
//public:
//    PrepareToPlay() : WorldScript("PrepareToPlay") {}
//
//    void OnStartup() override
//    {
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, " ");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "#####################################");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "# Single Player Project - Legion V2 #");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "# Website: spp-forum.de             #");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "#####################################");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, " ");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "Credits:");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- Mr. Unknown");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- koo");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- Warlord Zul'Jin");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- jhonJOE");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- ThordekkSQL");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- R3DF4ST");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, " ");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "Included softwares:");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- TrinityCore          https://github.com/TrinityCore/TrinityCore");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- Notepad++            https://notepad-plus-plus.org");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- 7zip                 https://www.7-zip.org");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- MariaDB              https://mariadb.org");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- Wget for Windows     http://gnuwin32.sourceforge.net/packages/wget.htm");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- Apache               https://httpd.apache.org");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- PHP                  https://www.php.net");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "- Simple Register Page https://github.com/masterking32/WoWSimpleRegistration");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, " ");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, "Now you ready to play.");
//        TC_LOG_INFO(LOG_FILTER_SERVER_LOADING, " ");
//    }
//};
//
//void AddSC_spp_info() {
//    new spp_info();
//    new PrepareToPlay();
//}
