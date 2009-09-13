#include "precompiled.h"
#include <cstring>

//This function is called when the player logs in (every login)
void OnLogin(Player *pPlayer)
{

}

//This function is called when the player logs out
void OnLogout(Player *pPlayer)
{

}

//This function is called when the player kills another player
void OnPVPKill(Player *killer, Player *killed)
{

}

 void AddSC_onevents()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "scripted_on_events";
    newscript->pOnLogin = &OnLogin;
    newscript->pOnLogout = &OnLogout;
    newscript->pOnPVPKill = &OnPVPKill;
    newscript->RegisterSelf();
}
