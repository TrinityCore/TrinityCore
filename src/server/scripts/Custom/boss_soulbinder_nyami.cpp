/*
 * boss_soulbinder_nyami.cpp
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
	SPELL_MIND_SPIKE = 154415,
	SPELL_SHADOW_WORD_PAIN = 154477,
	SPELL_SOUL_VESSEL = 153477,
	SPELL_TORN_SPIRITS = 153994,
};

enum Events{
	EVENT_MIND_SPIKE,
	EVENT_SHADOW_WORD_PAIN,
	EVENT_SOUL_VESSEL,
	EVENT_TORN_SPIRITS,
};

class boss_soulbinder_nyami : public CreatureScript
{
public:
	boss_soulbinder_nyami() : CreatureScript("boss_soulbinder_nyami") { }

	struct boss_soulbinder_nyamiAI : public BossAI
	{
		boss_soulbinder_nyamiAI(Creature* creature) : BossAI(creature, 76177)
		{
		}

		void Reset() override {
			BossAI::Reset();
		}

		void EnterCombat(Unit* victim) override {
			BossAI::EnterCombat(victim);
			
			events.ScheduleEvent(EVENT_MIND_SPIKE, 4000);
			events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000);
			events.ScheduleEvent(EVENT_SOUL_VESSEL, 12000);
			events.ScheduleEvent(EVENT_TORN_SPIRITS, 16000);
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
				case EVENT_MIND_SPIKE:
					DoCastVictim(SPELL_MIND_SPIKE);
					events.ScheduleEvent(EVENT_MIND_SPIKE, 4000);
					break;
				case EVENT_SHADOW_WORD_PAIN:
					DoCastVictim(SPELL_SHADOW_WORD_PAIN);
					events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000);
					break;
				case EVENT_SOUL_VESSEL:
					DoCastAOE(SPELL_SOUL_VESSEL);
					events.ScheduleEvent(EVENT_SOUL_VESSEL, 12000);
					break;
				case EVENT_TORN_SPIRITS:
					DoCast(SPELL_TORN_SPIRITS);
					events.ScheduleEvent(EVENT_TORN_SPIRITS, 16000);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override {
		return new boss_soulbinder_nyamiAI(creature);
	}
};

void AddSC_boss_soulbinder_nyami()
{
	new boss_soulbinder_nyami();
}

