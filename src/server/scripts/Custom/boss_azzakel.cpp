/*
 * boss_azzakel.cpp
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
	SPELL_CLAWS_OF_ARGUS = 153764,
	SPELL_CURTAIN_OF_FLAME = 153396,
	SPELL_FEL_LASH = 153234,
	SPELL_MALEVOLENT_CRASH = 153499,
};

enum Events{
	EVENT_CLAWS_OF_ARGUS,
	EVENT_CURTAIN_OF_FLAME,
	EVENT_FEL_LASH,
	EVENT_MALEVOLENT_CRASH,
};

class boss_azzakel : public CreatureScript
{
public:
	boss_azzakel() : CreatureScript("boss_azzakel") { }

	struct boss_azzakelAI : public BossAI
	{
		boss_azzakelAI(Creature* creature) : BossAI(creature, 75927)
		{
		}

		void Reset() override {
			_Reset();
		}

		void EnterCombat(Unit* /*who*/) override {
			_EnterCombat();
			events.ScheduleEvent(EVENT_CLAWS_OF_ARGUS, 4000);
			events.ScheduleEvent(EVENT_CURTAIN_OF_FLAME, 8000);
			events.ScheduleEvent(EVENT_FEL_LASH, 12000);
			events.ScheduleEvent(EVENT_MALEVOLENT_CRASH, 16000);
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
				case EVENT_CLAWS_OF_ARGUS:
					DoCast(SPELL_CLAWS_OF_ARGUS);
					events.ScheduleEvent(EVENT_CLAWS_OF_ARGUS, 4000);
					break;
				case EVENT_CURTAIN_OF_FLAME:
					DoCastVictim(SPELL_CURTAIN_OF_FLAME);
					events.ScheduleEvent(EVENT_CURTAIN_OF_FLAME, 8000);
					break;
				case EVENT_FEL_LASH:
					DoCastVictim(SPELL_FEL_LASH);
					events.ScheduleEvent(EVENT_FEL_LASH, 12000);
					break;
				case EVENT_MALEVOLENT_CRASH:
					DoCastAOE(SPELL_MALEVOLENT_CRASH);
					events.ScheduleEvent(EVENT_MALEVOLENT_CRASH, 16000);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override {
		return new boss_azzakelAI(creature);
	}
};

void AddSC_boss_azzakel()
{
	new boss_azzakel();
}
