/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Creature.h"
#include "GameEventMgr.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"

#define EVENT_MORPH             200
#define SPELL_CLONE             69828
#define MAX_CREATURE_HEALTH     2000000

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
