/*
Credits:
Rochet2
Tommy

There were few more, but couldnt find them

Release:
http://emudevs.com/showthread.php/3413-Phased-duel-(pets-work)?p=24109
Original source:
http://emudevs.com/showthread.php/2282-phase-out-dueling-error?p=15483&viewfull=1#post15483
*/
#include "Config.h"

class PhasedDueling : public PlayerScript
{
public:
    PhasedDueling(): PlayerScript("PhasedDueling") {}

    void OnDuelStart(Player* firstplayer, Player* secondplayer) override
    {
		if (sConfigMgr->GetBoolDefault("PhasedDueling.Enable", true))
		{
        Map* map = firstplayer->GetMap();
        if (map->IsDungeon())
            return;

        // Duel flag is used as duel center point
        GameObject* go = map->GetGameObject(ObjectGuid(firstplayer->GetUInt64Value(PLAYER_DUEL_ARBITER)));
        if (!go)
            return;

        // Get players from 100 yard radius ( duel radius is 40-50 yd )
        std::list<Player*> playerList;
        Trinity::AnyPlayerInObjectRangeCheck checker(go, 100.0f);
        Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(go, playerList, checker);
        go->VisitNearbyWorldObject(100.0f, searcher);

        // insert players' phases to used phases, ignore GMs
        uint32 usedPhases = 0;
        if (!playerList.empty())
            for (std::list<Player*>::const_iterator it = playerList.begin(); it != playerList.end(); ++it)
                if (!(*it)->IsGameMaster())
                    usedPhases |= (*it)->GetPhaseMask();
        // loop all unique phases
        for (uint32 phase = 2; phase <= ULONG_MAX / 2; phase *= 2)
        {
            // If phase in use, skip
            if (usedPhases & phase)
                continue;

            // Phase players & pets, dont update visibility yet
            firstplayer->SetPhaseMask(phase, false);
            secondplayer->SetPhaseMask(phase, false);
            // Phase duel flag
            go->SetPhaseMask(phase, true);
            // Update visibility here so pets will be phased and wont despawn
            firstplayer->UpdateObjectVisibility();
            secondplayer->UpdateObjectVisibility();
            return;
        }

        // Couldnt find free unique phase
        firstplayer->GetSession()->SendNotification("There are no free phases");
        secondplayer->GetSession()->SendNotification("There are no free phases");
		}
    }

    // Restore phases
    void OnDuelEnd(Player* firstplayer, Player* secondplayer, DuelCompleteType type) override
    {
		if (sConfigMgr->GetBoolDefault("PhasedDueling.Enable", true))
		{
			// Phase players, dont update visibility yet
			firstplayer->SetPhaseMask(GetNormalPhase(firstplayer), false);
			secondplayer->SetPhaseMask(GetNormalPhase(secondplayer), false);
			// Update visibility here so pets will be phased and wont despawn
			firstplayer->UpdateObjectVisibility();
			secondplayer->UpdateObjectVisibility();
		}
    }

    // Attempt in storing the player phase with spell phases included.
    uint32 GetNormalPhase(Player* player) const
    {
        if (player->IsGameMaster())
            return uint32(PHASEMASK_ANYWHERE);

        // GetPhaseMaskForSpawn copypaste
        uint32 phase = PHASEMASK_NORMAL;
        Player::AuraEffectList const& phases = player->GetAuraEffectsByType(SPELL_AURA_PHASE);
        if (!phases.empty())
            phase = phases.front()->GetMiscValue();
        if (uint32 n_phase = phase & ~PHASEMASK_NORMAL)
            return n_phase;

        return PHASEMASK_NORMAL;
    }
};

void AddSC_PhasedDueling()
{
    new PhasedDueling();
}