//来源:https://uiwow.com/thread-1103-1-1.html
//pvp击杀公告

#include "ScriptPCH.h"
#include <World.h>

class System_OnKill : public PlayerScript
{
public:
    System_OnKill() : PlayerScript("System_OnKill") {}

    void OnPVPKill(Player* Killer, Player* Victim)
    {
        //uint32 KillerGUID = Killer->GetGUIDLow();
        //uint32 VictimGUID = Victim->GetGUIDLow();

        uint32 KillerGUID = Killer->GetGuildId();//修改上方原文注释的两句
        uint32 VictimGUID = Victim->GetGuildId();

        struct KillStreak_Info
        {
            uint32 killstreak;
            uint32 lastkill;
        };

        static std::map<uint32, KillStreak_Info> KillStreakData;

        if (KillerGUID == VictimGUID || KillStreakData[KillerGUID].lastkill == VictimGUID)
            return;

        if (KillStreakData[VictimGUID].killstreak >= 3)
        {
            std::ostringstream ss;
            ss << "|cFF81CF42" << Killer->GetName() << "|r Server Killer Has Ended |cFFFFFFFF" << Victim->GetName() << " !!!! ";
            //ss << "|cFF81CF42" << Killer->GetName() << "|r 击杀了 |cFFFFFFFF" << Victim->GetName() << " !!!! ";//击杀公告
            sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
        }

        ++KillStreakData[KillerGUID].killstreak;
        KillStreakData[KillerGUID].lastkill = VictimGUID;
        KillStreakData[VictimGUID].killstreak = 0;
        KillStreakData[VictimGUID].lastkill = 0;

        if (KillStreakData[KillerGUID].killstreak % 10 == 0) // send killstreak message every 10 kills
        {
            std::ostringstream ss;
            ss << "|cFF81CF42" << Killer->GetName() << "|r Server Killer Has A KillStreak Of |cFF42A0CF" << KillStreakData[KillerGUID].killstreak << "|r!!!!!";
            sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
        }
        else if (KillStreakData[KillerGUID].killstreak == 3)
        {
            std::ostringstream ss;
            ss << "|cFF81CF42" << Killer->GetName() << "|r Server Killer Is On A KillingSpree!!!!!!";
            sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
        }

    }
};

void AddSC_PvP_System()
{
    new System_OnKill;
}
