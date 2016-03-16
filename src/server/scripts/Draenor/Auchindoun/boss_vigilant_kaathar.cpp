/*
 * boss_vigilant_kaathar.cpp
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
	SPELL_CONSECRATED_LIGHT = 153006,
	SPELL_HALLOWED_GROUND = 154526,
	SPELL_HOLY_SHIELD = 153480,
	SPELL_SANCTIFIED_GROUND = 153430,
	SPELL_SANCTIFIED_STRIKE = 152954,
};

enum Events{
	EVENT_CONSECRATED_LIGHT,
	EVENT_HALLOWED_GROUND,
	EVENT_HOLY_SHIELD,
	EVENT_SANCTIFIED_GROUND,
	EVENT_SANCTIFIED_STRIKE,
};

class boss_vigilant_kaathar : public CreatureScript
{
public:
	boss_vigilant_kaathar() : CreatureScript("boss_vigilant_kaathar") { }

	struct boss_vigilant_kaatharAI : public BossAI
	{
		boss_vigilant_kaatharAI(Creature* creature) : BossAI(creature, 75839)
		{
		}

		void Reset() override {
			BossAI::Reset();
		}

		void EnterCombat(Unit* victim) override {
			BossAI::EnterCombat(victim);
			
			events.ScheduleEvent(EVENT_CONSECRATED_LIGHT, 4000);
			events.ScheduleEvent(EVENT_HALLOWED_GROUND, 8000);
			events.ScheduleEvent(EVENT_HOLY_SHIELD, 12000);
			events.ScheduleEvent(EVENT_SANCTIFIED_GROUND, 16000);
			events.ScheduleEvent(EVENT_SANCTIFIED_STRIKE, 20000);
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
				case EVENT_CONSECRATED_LIGHT:
					DoCastAOE(SPELL_CONSECRATED_LIGHT);
					events.ScheduleEvent(EVENT_CONSECRATED_LIGHT, 4000);
					break;
				case EVENT_HALLOWED_GROUND:
					DoCastAOE(SPELL_HALLOWED_GROUND);
					events.ScheduleEvent(EVENT_HALLOWED_GROUND, 8000);
					break;
				case EVENT_HOLY_SHIELD:
					DoCastVictim(SPELL_HOLY_SHIELD);
					events.ScheduleEvent(EVENT_HOLY_SHIELD, 12000);
					break;
				case EVENT_SANCTIFIED_GROUND:
					DoCastAOE(SPELL_SANCTIFIED_GROUND);
					events.ScheduleEvent(EVENT_SANCTIFIED_GROUND, 16000);
					break;
				case EVENT_SANCTIFIED_STRIKE:
					DoCastAOE(SPELL_SANCTIFIED_STRIKE);
					events.ScheduleEvent(EVENT_SANCTIFIED_STRIKE, 20000);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override {
		return new boss_vigilant_kaatharAI(creature);
	}
};

void AddSC_boss_vigilant_kaathar()
{
	new boss_vigilant_kaathar();
}
