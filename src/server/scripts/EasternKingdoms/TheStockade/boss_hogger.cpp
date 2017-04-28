/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "InstanceScript.h"
#include "the_stockade.h"

enum Spells
{
	SPELL_VICIOUS_SLICE = 86604,
	SPELL_MADDENING_CALL = 86620,
	SPELL_ENRAGE = 86736
};

enum Says
{
	SAY_PULL = 0, // Forest just setback!
	SAY_ENRAGE = 1, // AreaTriggerMessage: Hogger Enrages!
	SAY_DEATH = 2, // Yiipe!


	WARDEN_SAY_1 = 0, // Yell - This ends here, Hogger!
	WARDEN_SAY_2 = 1, // Say - He's...he's dead?
	WARDEN_SAY_3 = 2, // Say - It's simply too good to be true. You couldn't have killed him so easily!
};

enum Events
{
	EVENT_VICIOUS_SLICE = 1,
	EVENT_MADDENING_CALL,


	EVENT_WARDEN_SAY_1,
	EVENT_WARDEN_SAY_2,
	EVENT_WARDEN_SAY_3
};

enum Points
{
    POINT_FINISH = 0
};

Position const wardenthelwatermovepos = { 152.019f, 106.198f, -35.1896f, 1.082104f };
Position const wardenthelwaterpos = { 138.369f, 78.2932f, -33.85627f, 1.082104f };

class boss_hogger : public CreatureScript
{
public:
	boss_hogger() : CreatureScript("boss_hogger") {}

	struct boss_hoggerAI : public BossAI
	{
        boss_hoggerAI(Creature* creature) : BossAI(creature, DATA_HOGGER) {}
		
		void Reset() override
		{
            		_Reset();
			isEnraged = false;
		}

		void EnterCombat(Unit* /*who*/) override
		{
            		_EnterCombat();
			Talk(SAY_PULL);
			events.ScheduleEvent(EVENT_VICIOUS_SLICE, randtime(Seconds(3), Seconds(4)));
			events.ScheduleEvent(EVENT_MADDENING_CALL, randtime(Seconds(1), Seconds(2)));
		}

		void JustDied(Unit* /*killer*/) override
		{
			Talk(SAY_DEATH);
			_JustDied();
          		me->SummonCreature(NPC_WARDEN_THELWATER, wardenthelwaterpos);
		}

        	void JustSummoned(Creature* summon) override
        	{
             		BossAI::JustSummoned(summon);
             		if (summon->GetEntry() == NPC_WARDEN_THELWATER)
                		 summon->GetMotionMaster()->MovePoint(POINT_FINISH, wardenthelwatermovepos);

            		summons.Summon(summon);
 
         	}

		void UpdateAI(uint32 diff) override
		{
			if (!UpdateVictim())
				return;

			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_VICIOUS_SLICE:
					DoCastVictim(SPELL_VICIOUS_SLICE);
					events.Repeat(randtime(Seconds(10), Seconds(14)));
					break;
				case EVENT_MADDENING_CALL:
					DoCast(SPELL_MADDENING_CALL);
					events.Repeat(randtime(Seconds(15), Seconds(20)));
					break;
				}
			}

			DoMeleeAttackIfReady();
		}

		void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
		{
			if (me->HealthBelowPct(30) && !isEnraged)
			{
				Talk(SAY_ENRAGE);
				DoCast(SPELL_ENRAGE);
				isEnraged = true;
			}
		}

	private:
		bool isEnraged;

	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return GetStormwindStockadeAI<boss_hoggerAI>(creature);
	}
};

class npc_warden_thelwater : public CreatureScript
{
public:
	npc_warden_thelwater() : CreatureScript("npc_warden_thelwater") {}

	struct npc_warden_thelwaterAI : public ScriptedAI
	{
        npc_warden_thelwaterAI(Creature* creature) : ScriptedAI(creature) {}
	

        	void MovementInform(uint32 type, uint32 id) override
        	{
            		if (type == POINT_MOTION_TYPE)
            		{
                		switch (id)
                		{
                		case POINT_FINISH:
                    		events.ScheduleEvent(EVENT_WARDEN_SAY_1, Seconds(1));
                    		break;
                		}
            		}
        	}

		void UpdateAI(uint32 diff) override
		{

			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_WARDEN_SAY_1:
					Talk(WARDEN_SAY_1);
					events.ScheduleEvent(EVENT_WARDEN_SAY_2, Seconds(4));
					break;
				case EVENT_WARDEN_SAY_2:
					Talk(WARDEN_SAY_2);
					events.ScheduleEvent(EVENT_WARDEN_SAY_3, Seconds(3));
					break;
				case EVENT_WARDEN_SAY_3:
					Talk(WARDEN_SAY_3);
					break;
				}
			}
		}
	private:
		EventMap events;
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return GetStormwindStockadeAI<npc_warden_thelwaterAI>(creature);
	}

};

void AddSC_boss_hogger()
{
	new boss_hogger();
	new npc_warden_thelwater();
}
