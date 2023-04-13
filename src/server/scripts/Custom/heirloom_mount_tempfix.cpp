///* ------------------------------------ */
///* AUTHOR   Azgath                      */
///*    FOR   Az'gath Private Server      */
///* ------------------------------------ */
//
//#include "Player.h"
//#include "WorldSession.h"
//#include "CollectionMgr.h"
//#include "Chat.h"
//
//class heirloom_mount_tempfix : public PlayerScript {
//private:
//    const uint32 heirloomSpell = 179244;
//    const int16 heirloomRequiredSize = 35;
//    const uint32 heirloomAchievement = 9909;
//
//public:
//    heirloom_mount_tempfix() : PlayerScript("heirloom_mount_tempfix") {}
//
//    void OnUpdate(Player* player, uint32 /*diff*/) {
//        if (!player->HasSpell(heirloomSpell)) {
//            const CollectionMgr* sCollectionMgr = player->GetSession()->GetCollectionMgr();
//
//            if (sCollectionMgr->GetAccountHeirlooms().size() == heirloomRequiredSize) {
//                player->CompletedAchievement(heirloomAchievement);
//                player->LearnSpell(heirloomSpell, false);
//            }
//        }
//    }
//};
//
//void AddSC_heirloom_mount_tempfix() {
//    new heirloom_mount_tempfix();
//}
