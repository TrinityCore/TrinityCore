/*
 * boss_skulloc.cpp
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
	SPELL_CANNON_BARRAGE = 168929,
	SPELL_GRONN_SMASH = 168227,
};

enum Events{
	EVENT_CANNON_BARRAGE,
	EVENT_GRONN_SMASH,
};

class boss_skulloc : public CreatureScript
{
public:
	boss_skulloc() : CreatureScript("boss_skulloc") { }

	struct boss_skullocAI : public BossAI
	{
		boss_skullocAI(Creature* creature) : BossAI(creature, 83612)
		{
		}

		void Reset() override {
			BossAI::Reset();
		}

		void EnterCombat(Unit* victim) override {
			BossAI::EnterCombat(victim);
			
			events.ScheduleEvent(EVENT_CANNON_BARRAGE, 4000);
			events.ScheduleEvent(EVENT_GRONN_SMASH, 8000);
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
				case EVENT_CANNON_BARRAGE:
					DoCastAOE(SPELL_CANNON_BARRAGE);
					events.ScheduleEvent(EVENT_CANNON_BARRAGE, 4000);
					break;
				case EVENT_GRONN_SMASH:
					DoCastAOE(SPELL_GRONN_SMASH);
					events.ScheduleEvent(EVENT_GRONN_SMASH, 8000);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override {
		return new boss_skullocAI(creature);
	}
};

void AddSC_boss_skulloc()
{
	new boss_skulloc();
}
