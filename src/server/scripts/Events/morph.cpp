#include <ScriptPCH.h>
#include <ScriptMgr.h>

#include "GameEventMgr.h"

#define EVENT_MORPH             100
#define SPELL_CLONE             69828
#define MAX_CREATURE_HEALTH     100000

class PlayerScript_Event_Morph : public PlayerScript
{
    public:
    PlayerScript_Event_Morph():PlayerScript("PlayerScript_Event_Morph") {}

    void OnCreatureKill(Player* Player, Creature* Creature)
    {
        if(!sGameEventMgr->IsActiveEvent(EVENT_MORPH))
            return;

        if (Creature->GetMaxHealth() > MAX_CREATURE_HEALTH)
            return;

        if (!Player->GetMap())
            return;

        if (Player->GetMap()->IsBattlegroundOrArena() || Player->GetMap()->IsRaid())
            return;

        Player->SetDisplayId(Creature->GetDisplayId());
    }

    void OnPVPKill(Player* Killer, Player* Killed)
    {
        if(!sGameEventMgr->IsActiveEvent(EVENT_MORPH))
            return;

        Killed->CastSpell(Killer, SPELL_CLONE, true);
    }
};

void AddSC_event_morph()
{
    new PlayerScript_Event_Morph();
};
