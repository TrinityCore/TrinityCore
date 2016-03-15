/*
 * boss_ahriok_dugru.cpp
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
	SPELL_ABRUPT_RESTORATION = 163705,
	SPELL_BLOOD_BOLT = 165122,
	SPELL_SANGUINE_SPHERE = 163689,
	SPELL_TAINTED_BLOOD = 163740,
};

enum Events{
	EVENT_ABRUPT_RESTORATION,
	EVENT_BLOOD_BOLT,
	EVENT_SANGUINE_SPHERE,
	EVENT_TAINTED_BLOOD,
};

class boss_ahriok_dugru : public CreatureScript
{
public:
	boss_ahriok_dugru() : CreatureScript("boss_ahriok_dugru") { }

	struct boss_ahriok_dugruAI : public BossAI
	{
		boss_ahriok_dugruAI(Creature* creature) : BossAI(creature, 80816)
		{
		}

		void Reset() override {
			_Reset();
		}

		void EnterCombat(Unit* /*who*/) override {
			_EnterCombat();
			events.ScheduleEvent(EVENT_ABRUPT_RESTORATION, 4000);
			events.ScheduleEvent(EVENT_BLOOD_BOLT, 8000);
			events.ScheduleEvent(EVENT_SANGUINE_SPHERE, 12000);
			events.ScheduleEvent(EVENT_TAINTED_BLOOD, 16000);
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
				case EVENT_ABRUPT_RESTORATION:
					DoCast(me,SPELL_ABRUPT_RESTORATION);
					events.ScheduleEvent(EVENT_ABRUPT_RESTORATION, 4000);
					break;
				case EVENT_BLOOD_BOLT:
					DoCast(SPELL_BLOOD_BOLT);
					events.ScheduleEvent(EVENT_BLOOD_BOLT, 8000);
					break;
				case EVENT_SANGUINE_SPHERE:
					DoCast(SPELL_SANGUINE_SPHERE);
					events.ScheduleEvent(EVENT_SANGUINE_SPHERE, 12000);
					break;
				case EVENT_TAINTED_BLOOD:
					DoCastVictim(SPELL_TAINTED_BLOOD);
					events.ScheduleEvent(EVENT_TAINTED_BLOOD, 12000);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override {
		return new boss_ahriok_dugruAI(creature);
	}
};

void AddSC_boss_ahriok_dugru()
{
	new boss_ahriok_dugru();
}








