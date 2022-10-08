/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "violet_hold_assault.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

const uint32 DemonMinions [] =
{
    NPC_CORROSIVE_FELHOUND    ,
    NPC_EREDAR_INVADER        ,
    NPC_FEL_INCITER           ,
    NPC_FELGUARD_DESTROYER    ,
    NPC_FELHOUND_MAGE_SLAYER  ,
    NPC_FELSTALKER_RAVENER    ,
    NPC_SHADOW_COUNCIL_WARLOCK,
    NPC_WRATHGUARD_BLADEWEAVER,
};

constexpr uint32 EVENT_SPAWN_MINION = 1;
constexpr uint32 ACTION_SPAWN_MINION = 1;

class npc_vha_demon_portal : public CreatureScript
{
    public:
        npc_vha_demon_portal() : CreatureScript("npc_vha_demon_portal")
        {}

        struct npc_vha_demon_portal_AI : public ScriptedAI
        {
                npc_vha_demon_portal_AI(Creature* creature) : ScriptedAI(creature)
                {}

                void DoAction(int32 action) override
                {
                    if (action == ACTION_SPAWN_MINION)
                        _events.ScheduleEvent(EVENT_SPAWN_MINION, Seconds(15));
                }

                void SummonedCreatureDies(Creature* summon, Unit* /**/) override
                {
                    if (!summon)
                        return;

                    if (summon->GetEntry() == NPC_PORTAL_INQUISITOR || summon->GetEntry() == NPC_PORTAL_DREADLORD ||
                        summon->GetEntry() == NPC_PORTAL_FELGUARD || summon->GetEntry() == NPC_PORTAL_JAILER)
                        {
                            _events.Reset();
                            me->RemoveAllAuras();
                        }
                }

                void UpdateAI(uint32 diff) override
                {
                    _events.Update(diff);

                    while (uint32 eventId = _events.ExecuteEvent())
                    {
                        if (eventId == EVENT_SPAWN_MINION)
                        {
                            uint32 entry = Trinity::Containers::SelectRandomContainerElement(DemonMinions);

                            if (entry == NPC_EREDAR_INVADER)
                            {
                                DoSummon(entry, me->GetPosition(), 10 * IN_MILLISECONDS, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                                DoSummon(entry, me->GetPosition(), 10 * IN_MILLISECONDS, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                            }
                            else
                                DoSummon(entry, me->GetPosition(), 10 * IN_MILLISECONDS, TEMPSUMMON_CORPSE_TIMED_DESPAWN);

                            _events.ScheduleEvent(EVENT_SPAWN_MINION, Seconds(15));
                        }
                    }
                }

                private:
                    EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_vha_demon_portal_AI(creature);
        }
};

void AddSC_violet_hold_assault()
{
    new npc_vha_demon_portal();
}
