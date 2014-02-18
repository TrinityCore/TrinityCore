/*
Originally by Kjanko
Edited by Tommy
Edited by Rochet2 ~ Made dynamic
Last Edit By Estorn
Change : Fix For Last Rev
*/

#include "ScriptPCH.h"

class System_OnKill : public PlayerScript
{
public:
    System_OnKill() : PlayerScript("System_OnKill") {}

    void OnPVPKill(Player * Killer, Player * Victim)
    {
        uint32 KillerGUID = Killer->GetGUIDLow();
        uint32 VictimGUID = Victim->GetGUIDLow();

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
            ss << "|cFF81CF42" << Killer->GetName() << "|r Has Ended |cFFFFFFFF" << Victim->GetName() << " !!!! ";
            sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
        }

        ++KillStreakData[KillerGUID].killstreak;
        KillStreakData[KillerGUID].lastkill = VictimGUID;
        KillStreakData[VictimGUID].killstreak = 0;
        KillStreakData[VictimGUID].lastkill = 0;

        if (KillStreakData[KillerGUID].killstreak % 10 == 0) // send killstreak message every 10 kills
        {
            std::ostringstream ss;
            ss << "|cFF81CF42" << Killer->GetName() << "|r Has A KillStreak Of |cFF42A0CF" << KillStreakData[KillerGUID].killstreak << "|r!!!!!";
            sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
        }
        else if (KillStreakData[KillerGUID].killstreak == 3)
        {
            std::ostringstream ss;
            ss << "|cFF81CF42" << Killer->GetName() << "|r Is On A KillingSpree!!!!!!";
            sWorld->SendServerMessage(SERVER_MSG_STRING, ss.str().c_str());
        }

    }
};

void AddSC_PvP_System()
{
    new System_OnKill;
}