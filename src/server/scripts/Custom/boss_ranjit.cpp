/*
 * boss_ranjit.cpp
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
	SPELL_FAN_OF_BLADES = 153757,
	SPELL_FOUR_WINDS = 156793,
	SPELL_PIERCING_RUSH = 165733,
	SPELL_WINDWALL = 153315,
};

enum Events{
	EVENT_FAN_OF_BLADES,
	EVENT_FOUR_WINDS,
	EVENT_PIERCING_RUSH,
	EVENT_WINDWALL,
};

class boss_ranjit : public CreatureScript
{
public:
	boss_ranjit() : CreatureScript("boss_ranjit") { }

	struct boss_ranjitAI : public BossAI
	{
		boss_ranjitAI(Creature* creature) : BossAI(creature, 75964)
		{
		}

		void Reset() override {
			_Reset();
		}

		void EnterCombat(Unit* /*who*/) override {
			 _EnterCombat();
			events.ScheduleEvent(EVENT_FAN_OF_BLADES, 4000);
			events.ScheduleEvent(EVENT_FOUR_WINDS, 8000);
			events.ScheduleEvent(EVENT_PIERCING_RUSH, 12000);
			events.ScheduleEvent(EVENT_WINDWALL, 16000);
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
				case EVENT_FAN_OF_BLADES:
					DoCastAOE(SPELL_FAN_OF_BLADES);
					events.ScheduleEvent(EVENT_FAN_OF_BLADES, 4000);
					break;
				case EVENT_FOUR_WINDS:
					DoCastAOE(SPELL_FOUR_WINDS);
					events.ScheduleEvent(EVENT_FOUR_WINDS, 8000);
					break;
				case EVENT_PIERCING_RUSH:
					DoCastVictim(SPELL_PIERCING_RUSH);
					events.ScheduleEvent(EVENT_PIERCING_RUSH, 12000);
					break;
				case EVENT_WINDWALL:
					DoCastAOE(SPELL_WINDWALL);
					events.ScheduleEvent(EVENT_WINDWALL, 16000);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override {
		return new boss_ranjitAI(creature);
	}
};

void AddSC_boss_ranjit()
{
	new boss_ranjit();
}




