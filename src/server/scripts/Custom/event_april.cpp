#include "ScriptPCH.h"
//#include <ScriptMgr.h>
//
//#include "GameEventMgr.h"
//
//#define EVENT_APRIL             100
//
//
//class PlayerScript_Event_April : public PlayerScript
//{
//public:
//    PlayerScript_Event_April() :PlayerScript("PlayerScript_Event_April") {}
//
//    void OnCreatureKill(Player* Player, Creature* /*Creature*/) override
//    {
//        int32 tabFish[14] = { 32263,40855,32646,42160,42161,42162,42163,44563,42808,44562,33312,42836,39936,45246 };
//        if (!sGameEventMgr->IsActiveEvent(EVENT_APRIL))
//            return;
//
//        if (!Player->GetMap())
//            return;
//
//        if (Player->GetMap()->IsBattlegroundOrArena() || Player->GetMap()->IsRaid())
//            return;
//        uint8 idFish = urand(0, 14);
//        Player->SetDisplayId(tabFish[idFish]);
//    }
//
//    void OnPVPKill(Player* Killer, Player* Killed) override
//    {
//        int32 tabFish[14] = { 32263,40855,32646,42160,42161,42162,42163,44563,42808,44562,33312,42836,39936,45246 };
//        if (Killer->GetMap()->IsBattlegroundOrArena() || Killer->GetMap()->IsRaid())
//            return;
//
//        if (!sGameEventMgr->IsActiveEvent(EVENT_APRIL))
//            return;
//
//        uint8 idFish = urand(0, 14);
//        Killer->SetDisplayId(tabFish[idFish]);
//    }
//};
//
//void AddSC_event_april()
//{
//    new PlayerScript_Event_April();
//};
