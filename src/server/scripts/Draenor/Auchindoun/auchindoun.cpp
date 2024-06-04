/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "AreaTriggerAI.h"
#include "auchindoun.h"

// 155647 - NPC Reaction
struct areatrigger_npc_reaction : AreaTriggerAI
{
    areatrigger_npc_reaction(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer() || unit->IsPet () || unit->GetEmoteState() == EMOTE_STATE_READY1H_ALLOW_MOVEMENT || unit->GetEntry() == NPC_SOULBINDER_NYAMI)
            return;

        _scheduler.Schedule(1500ms, [this, unit](TaskContext task)
        {
            unit->SetFacingToObject(at->GetCaster());
            unit->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);

            task.Schedule(4s, [this, unit](TaskContext /*task*/)
            {
                unit->SetFacingTo(unit->ToCreature()->GetHomePosition().GetOrientation());
            });
        });
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

void AddSC_auchindoun()
{
    RegisterAreaTriggerAI(areatrigger_npc_reaction);
}
