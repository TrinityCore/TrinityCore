/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "throne_of_the_tides.h"
#include "ScriptedCreature.h"
#include "Vehicle.h"


struct npc_tott_ozumat_vehicle_big : public ScriptedAI
{
    npc_tott_ozumat_vehicle_big(Creature* creature) : ScriptedAI(creature), _instance(me->GetInstanceScript()) { }

    void JustAppeared() override
    {
        if (_instance->GetData(DATA_CURRENT_EVENT_PROGRESS) < EVENT_INDEX_DEFENSE_SYSTEM_ACTIVATED)
            if (Creature* ozumat = DoSummon(BOSS_OZUMAT, me->GetPosition()))
                me->HandleSpellClick(ozumat, -1);
    }

    void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
    {
        if (!who)
            return;

        if (apply)
            who->SetFacingTo(3.141593f, true);
    }

private:
    InstanceScript* _instance;
};

class at_tott_first_invader_event : public AreaTriggerScript
{
    public:
        at_tott_first_invader_event() : AreaTriggerScript("at_tott_first_invader_event") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_CURRENT_EVENT_PROGRESS) < EVENT_INDEX_FIRST_INVADERS)
                instance->SetData(DATA_CURRENT_EVENT_PROGRESS, EVENT_INDEX_FIRST_INVADERS);

            return true;
        }
};

void AddSC_throne_of_the_tides()
{
    RegisterThroneOfTheTidesCreatureAI(npc_tott_ozumat_vehicle_big);
    new at_tott_first_invader_event();
}
