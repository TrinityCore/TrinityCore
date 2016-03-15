/*
 * boss_terongor.cpp
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
	SPELL_AGONY = 156925,
	SPELL_CHAOS_BOLT = 156975,
	SPELL_CHAOS_WAVE = 157001,
	SPELL_CONFLAGRATE = 156960,
	SPELL_CORRUPTION = 156842,
	SPELL_CURSE_OF_EXHAUSTION = 164841,
	SPELL_DEMONIC_LEAP = 157039,
	SPELL_DOOM = 156965,
	SPELL_DRAIN_LIFE = 156854,
	SPELL_IMMOLATE = 156964,
	SPELL_INCINERATE = 156963,
	SPELL_RAIN_OF_FIRE = 156857,
	SPELL_SEED_OF_MALEVOLENCE = 156921,
	SPELL_SHADOW_BOLT = 156829,
	SPELL_TOUCH_OF_CHAOS = 156968,
	SPELL_UNSTABLE_AFFLICTION = 156954,
};

enum Events{
	EVENT_AGONY,
	EVENT_CHAOS_BOLT,
	EVENT_CHAOS_WAVE,
	EVENT_CONFLAGRATE,
	EVENT_CORRUPTION,
	EVENT_CURSE_OF_EXHAUSTION,
	EVENT_DEMONIC_LEAP,
	EVENT_DOOM,
	EVENT_DRAIN_LIFE,
	EVENT_IMMOLATE,
	EVENT_INCINERATE,
	EVENT_RAIN_OF_FIRE,
	EVENT_SEED_OF_MALEVOLENCE,
	EVENT_SHADOW_BOLT,
	EVENT_TOUCH_OF_CHAOS,
	EVENT_UNSTABLE_AFFLICTION,
};

class boss_terongor : public CreatureScript
{
public:
	boss_terongor() : CreatureScript("boss_terongor") { }

	struct boss_terongorAI : public BossAI
	{
		boss_terongorAI(Creature* creature) : BossAI(creature, 77734)
		{
		}

		void Reset() override {
			_Reset();
		}

		void EnterCombat(Unit* /*who*/) override {
			_EnterCombat();
			events.ScheduleEvent(EVENT_AGONY, 4000);
			events.ScheduleEvent(EVENT_CHAOS_BOLT, 8000);
			events.ScheduleEvent(EVENT_CHAOS_WAVE, 12000);
			events.ScheduleEvent(EVENT_CONFLAGRATE, 16000);
			events.ScheduleEvent(EVENT_CORRUPTION, 20000);
			events.ScheduleEvent(EVENT_CURSE_OF_EXHAUSTION, 4000);
			events.ScheduleEvent(EVENT_DEMONIC_LEAP, 8000);
			events.ScheduleEvent(EVENT_DOOM, 12000);
			events.ScheduleEvent(EVENT_DRAIN_LIFE, 16000);
			events.ScheduleEvent(EVENT_IMMOLATE, 20000);
			events.ScheduleEvent(EVENT_INCINERATE, 4000);
			events.ScheduleEvent(EVENT_RAIN_OF_FIRE, 8000);
			events.ScheduleEvent(EVENT_SEED_OF_MALEVOLENCE, 12000);
			events.ScheduleEvent(EVENT_SHADOW_BOLT, 16000);
			events.ScheduleEvent(EVENT_TOUCH_OF_CHAOS, 20000);
			events.ScheduleEvent(EVENT_UNSTABLE_AFFLICTION, 4000);
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
				case EVENT_AGONY:
					DoCastVictim(SPELL_AGONY);
					events.ScheduleEvent(EVENT_AGONY, 4000);
					break;
				case EVENT_CHAOS_BOLT:
					DoCastVictim(SPELL_CHAOS_BOLT);
					events.ScheduleEvent(EVENT_CHAOS_BOLT, 8000);
					break;
				case EVENT_CHAOS_WAVE:
					DoCast(SPELL_CHAOS_WAVE);
					events.ScheduleEvent(EVENT_CHAOS_WAVE, 12000);
					break;
				case EVENT_CONFLAGRATE:
					DoCastVictim(SPELL_CONFLAGRATE);
					events.ScheduleEvent(EVENT_CONFLAGRATE, 16000);
					break;
				case EVENT_CORRUPTION:
					DoCastVictim(SPELL_CORRUPTION);
					events.ScheduleEvent(EVENT_CORRUPTION, 20000);
					break;
				case EVENT_CURSE_OF_EXHAUSTION:
					DoCastVictim(SPELL_CURSE_OF_EXHAUSTION);
					events.ScheduleEvent(EVENT_CURSE_OF_EXHAUSTION, 4000);
					break;
				case EVENT_DEMONIC_LEAP:
					DoCastAOE(SPELL_DEMONIC_LEAP);
					events.ScheduleEvent(EVENT_DEMONIC_LEAP, 8000);
					break;
				case EVENT_DOOM:
					DoCast(SPELL_DOOM);
					events.ScheduleEvent(EVENT_DOOM, 12000);
					break;
				case EVENT_DRAIN_LIFE:
					DoCastVictim(SPELL_DRAIN_LIFE);
					events.ScheduleEvent(EVENT_DRAIN_LIFE, 16000);
					break;
				case EVENT_IMMOLATE:
					DoCastVictim(SPELL_IMMOLATE);
					events.ScheduleEvent(EVENT_IMMOLATE, 20000);
					break;
				case EVENT_INCINERATE:
					DoCastVictim(SPELL_INCINERATE);
					events.ScheduleEvent(EVENT_INCINERATE, 4000);
					break;
				case EVENT_RAIN_OF_FIRE:
					DoCastAOE(SPELL_RAIN_OF_FIRE);
					events.ScheduleEvent(EVENT_RAIN_OF_FIRE, 8000);
					break;
				case EVENT_SEED_OF_MALEVOLENCE:
					DoCastVictim(SPELL_SEED_OF_MALEVOLENCE);
					events.ScheduleEvent(EVENT_SEED_OF_MALEVOLENCE, 12000);
					break;
				case EVENT_SHADOW_BOLT:
					DoCastVictim(SPELL_SHADOW_BOLT);
					events.ScheduleEvent(EVENT_SHADOW_BOLT, 16000);
					break;
				case EVENT_TOUCH_OF_CHAOS:
					DoCastVictim(SPELL_TOUCH_OF_CHAOS);
					events.ScheduleEvent(EVENT_TOUCH_OF_CHAOS, 20000);
					break;
				case EVENT_UNSTABLE_AFFLICTION:
					DoCastVictim(SPELL_UNSTABLE_AFFLICTION);
					events.ScheduleEvent(EVENT_UNSTABLE_AFFLICTION, 4000);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override {
		return new boss_terongorAI(creature);
	}
};

void AddSC_boss_terongor()
{
	new boss_terongor();
}

