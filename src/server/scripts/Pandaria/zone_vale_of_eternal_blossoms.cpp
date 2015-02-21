/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
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


#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"

/* Taijing the Cyclone & Jinho the Windbreaker */

enum JinhoTaijingSpells
{
    SPELL_SPINNING_CRANE_KICK	= 129003,
    SPELL_CYCLONIC_INSPIRATION	= 128943
};

enum JinhoTaijingEvents
{
	EVENT_SPINNING_CRANE_KICK	= 1
};

class npc_jinho_and_taijing : public CreatureScript
{
public:
    npc_jinho_and_taijing() : CreatureScript("npc_jinho_and_taijing") { }

    struct npc_jinho_and_taijingAI : public ScriptedAI
    {
        npc_jinho_and_taijingAI(Creature* creature) : ScriptedAI(creature)
        {	}

		EventMap events;

        void Reset()
		{
			events.Reset();
			events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 1*IN_MILLISECONDS);
		}

        void MoveInLineOfSight(Unit* who)
        {
            if (!me->IsWithinDistInMap(who, 40.0f))
                return;

			if (!who || !who->IsInWorld())
                return;

			if (who && who->ToPlayer() && !who->ToPlayer()->isGameMaster() && !who->HasAura(SPELL_CYCLONIC_INSPIRATION) && !me->IsValidAttackTarget(who) && me->HasAura(SPELL_SPINNING_CRANE_KICK))
                    who->CastSpell(who, SPELL_CYCLONIC_INSPIRATION);
        }

        void UpdateAI(uint32 diff)
		{
			events.Update(diff);

			while(uint32 eventId = events.ExecuteEvent())
			{
				switch(eventId)
				{
					case EVENT_SPINNING_CRANE_KICK:
						DoCast(me, SPELL_SPINNING_CRANE_KICK);

						events.ScheduleEvent(EVENT_SPINNING_CRANE_KICK, 45*IN_MILLISECONDS);
						break;

					default:
						break;
				}
			}

			DoMeleeAttackIfReady();
		}
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_jinho_and_taijingAI(creature);
    }
};

void AddSC_vale_of_eternal_blossoms()
{
    new npc_jinho_and_taijing;
}
