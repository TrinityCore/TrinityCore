#include "Hw2World.h"
#include "Hw2SystemMgr.h"
#include "World.h"
#include "WorldSession.h"
#include "Player.h"

Hw2World::Hw2World(World *w) {
    world = w;
}

void Hw2World::AzerothExtra(const char *stringa, uint8 scelta) {
    SessionMap m_sessions = world->GetAllSessions();
    
    if (!stringa || !scelta) return;
    // scorre tutti i players ed esegue le operazioni
    switch (scelta) { // itr->second->GetPlayer() aggiunto...per evitare eventuali crashes
        case 0:
            for (SessionMap::iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
                if (itr->second->GetPlayer()) 
                    sHw2->Hw2SendSysMessage(itr->second->GetPlayer(), "ATTENZIONE: %s E' IN FRENESIA!!! <<||>> WARNING: %s IS IN FRENZY!", stringa, stringa);
            return;
            break;
        case 1:
            for (SessionMap::iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
                if (itr->second->GetPlayer()) 
                    sHw2->Hw2SendSysMessage(itr->second->GetPlayer(), "%s E' ENTRATO NEL DEATHMATCH <<||>> %s HAS ENTERED IN THE DEATHMATCH!", stringa, stringa);
            return;
            break;

        case 2:
            for (SessionMap::iterator itr = m_sessions.begin(); itr != m_sessions.end(); ++itr)
                if (sHw2->DmCheckTournament(itr->second->GetPlayer(), false)) 
                    itr->second->GetPlayer()->UpdateZone(itr->second->GetPlayer()->GetZoneId(), itr->second->GetPlayer()->GetAreaId());
            return;
            break;
    }
    return;
}
