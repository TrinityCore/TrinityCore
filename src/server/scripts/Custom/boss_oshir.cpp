/*
 * boss_oshir.cpp
 *
 *  Created on: 14 de mar. de 2016
 *      Author: Infamous
 */

#include "ScriptMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GameEventMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Unit.h"
#include "GameObject.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "Chat.h"
#include "DBCStructure.h"
#include "DBCStores.h"
#include "ObjectMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum Spells{
	SPELL_BREAKOUT = 178124,
	SPELL_FEEDING_FRENZY = 162424,
	SPELL_PRIMAL_ASSAULT = 161256,
	SPELL_TIME_TO_FEED = 162415,
};

enum Events{
	EVENT_BREAKOUT,
	EVENT_FEEDING_FRENZY,
	EVENT_PRIMAL_ASSAULT,
	EVENT_TIME_TO_FEED,
};

class boss_oshir : public CreatureScript
{
public:
	boss_oshir() : CreatureScript("boss_oshir") { }

	struct boss_oshirAI : public BossAI
	{
		boss_oshirAI(Creature* creature) : BossAI(creature, 79852)
		{
		}

		void Reset() override {
			_Reset();
		}

		void EnterCombat(Unit* /*who*/) override {
			_EnterCombat();
			events.ScheduleEvent(EVENT_BREAKOUT, 4000);
			events.ScheduleEvent(EVENT_FEEDING_FRENZY, 8000);
			events.ScheduleEvent(EVENT_PRIMAL_ASSAULT, 12000);
			events.ScheduleEvent(EVENT_TIME_TO_FEED, 16000);
		}

		void KilledUnit(Unit * /*victim*/) override {
		}

		void JustDied(Unit * /*victim*/) override {
			_JustDied();
		}

		void UpdateAI(uint32 diff) override {
			if (!UpdateVictim())
				return;

			events.Update(diff);

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_BREAKOUT:
					DoCast(SPELL_BREAKOUT);
					events.ScheduleEvent(EVENT_BREAKOUT, 4000);
					break;
				case EVENT_FEEDING_FRENZY:
					DoCast(SPELL_FEEDING_FRENZY);
					events.ScheduleEvent(EVENT_FEEDING_FRENZY, 8000);
					break;
				case EVENT_PRIMAL_ASSAULT:
					DoCast(SPELL_PRIMAL_ASSAULT);
					events.ScheduleEvent(EVENT_PRIMAL_ASSAULT, 12000);
					break;
				case EVENT_TIME_TO_FEED:
					DoCastVictim(SPELL_TIME_TO_FEED);
					events.ScheduleEvent(EVENT_TIME_TO_FEED, 16000);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override {
		return new boss_oshirAI(creature);
	}
};

void AddSC_boss_oshir()
{
	new boss_oshir();
}
