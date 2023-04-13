///***
// *  @project: Firestorm Freelance
// *  @author: Meltie2013 (github) aka Lilcrazy
// *  @copyright: 2017
// */
//
//#include "ScriptMgr.h"
//#include "Config.h"
//#include "World.h"
//#include "WorldSession.h"
//
// // Check to see if the player is attempting to multi-box
//class multi_login_check : public PlayerScript
//{
//public:
//    multi_login_check() : PlayerScript("multi_login_check") { }
//
//    void OnLogin(Player* player, bool /*firstLogin*/) override
//    {
//        if (sConfigMgr->GetBoolDefault("Disallow.Multiple.Client", true))
//        {
//            SessionMap sessions = sWorld->GetAllSessions();
//            for (SessionMap::iterator itr = sessions.begin(); itr != sessions.end(); ++itr)
//            {
//                if (Player* login = itr->second->GetPlayer())
//                {
//                    if (player != login)
//                    {
//                        // If Remote Address matches, remove the player from the world
//                        if (player->GetSession()->GetRemoteAddress() == login->GetSession()->GetRemoteAddress())
//                            player->GetSession()->KickPlayer();
//                    }
//                }
//            }
//        }
//    }
//};
//
//
//void AddSC_player_session_checks()
//{
//    new multi_login_check;
//}
