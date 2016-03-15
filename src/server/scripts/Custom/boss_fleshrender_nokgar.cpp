/*
 * boss_fleshrender_nokgar.cpp
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

enum Spells
{
	SPELL_BARBED_ARROW_BARRAGE = 166923,
	SPELL_INTIMIDATED = 164504,
	SPELL_RECKLESS_PROVOCATION = 164426,
};

enum Events{
	EVENT_BARBED_ARROW_BARRAGE,
	EVENT_INTIMIDATED,
	EVENT_RECKLESS_PROVOCATION,
};

class boss_fleshrender_nokgar : public CreatureScript
{
public:
	boss_fleshrender_nokgar() : CreatureScript("boss_fleshrender_nokgar") { }

	struct boss_fleshrender_nokgarAI : public BossAI
	{
		boss_fleshrender_nokgarAI(Creature* creature) : BossAI(creature, 81305)
		{
		}

		void Reset() override {
			_Reset();
		}

		void EnterCombat(Unit* /*who*/) override {
			_EnterCombat();
			events.ScheduleEvent(EVENT_BARBED_ARROW_BARRAGE, 4000);
			events.ScheduleEvent(EVENT_INTIMIDATED, 8000);
			events.ScheduleEvent(EVENT_RECKLESS_PROVOCATION, 12000);
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
				case EVENT_BARBED_ARROW_BARRAGE:
					DoCastAOE(SPELL_BARBED_ARROW_BARRAGE);
					events.ScheduleEvent(EVENT_BARBED_ARROW_BARRAGE, 4000);
					break;
				case EVENT_INTIMIDATED:
					DoCastAOE(SPELL_INTIMIDATED);
					events.ScheduleEvent(EVENT_INTIMIDATED, 8000);
					break;
				case EVENT_RECKLESS_PROVOCATION:
					DoCastAOE(SPELL_RECKLESS_PROVOCATION);
					events.ScheduleEvent(EVENT_RECKLESS_PROVOCATION, 12000);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override {
		return new boss_fleshrender_nokgarAI(creature);
	}
};

void AddSC_boss_fleshrender_nokgar()
{
	new boss_fleshrender_nokgar();
}
