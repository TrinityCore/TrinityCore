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
	SPELL_BURNINGSLAG = 152939,
	SPELL_BURNINGSLAG_INSTANT = 153227,
	SPELL_FIERYBOULDER = 153247,
	SPELL_HEATWAVE = 152940,
	SPELL_MOLTENREACH = 152941,
};

enum Events
{
	EVENT_BURNINGSLAG,
	EVENT_BURNINGSLAG_INSTANT,
	EVENT_FIERYBOULDER,
	EVENT_HEATWAVE,
	EVENT_MOLTENREACH,
};


class Boss_Roltall : public CreatureScript
{
public:
	Boss_Roltall() : CreatureScript("boss_roltall") { }

	struct Boss_RoltallAI : public BossAI
	{
		Boss_RoltallAI(Creature* creature) : BossAI(creature, 75786)
		{
		}

		void Reset() override {
			BossAI::Reset();
		}

		void EnterCombat(Unit* victim) override {
			 BossAI::EnterCombat(victim);
			 
			events.ScheduleEvent(EVENT_BURNINGSLAG, 4000);
			events.ScheduleEvent(EVENT_BURNINGSLAG_INSTANT, 8000);
			events.ScheduleEvent(EVENT_FIERYBOULDER, 12000);
			events.ScheduleEvent(EVENT_HEATWAVE, 16000);
			events.ScheduleEvent(EVENT_MOLTENREACH, 20000);
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
				case EVENT_BURNINGSLAG:
					DoCastAOE(SPELL_BURNINGSLAG);
					events.ScheduleEvent(EVENT_BURNINGSLAG, 4000);
					break;
				case EVENT_BURNINGSLAG_INSTANT:
					DoCastAOE(SPELL_BURNINGSLAG_INSTANT);
					events.ScheduleEvent(EVENT_BURNINGSLAG_INSTANT, 8000);
					break;
				case EVENT_FIERYBOULDER:
					DoCastAOE(SPELL_FIERYBOULDER);
					events.ScheduleEvent(EVENT_FIERYBOULDER, 12000);
					break;
				case EVENT_HEATWAVE:
					DoCastAOE(SPELL_HEATWAVE);
					events.ScheduleEvent(EVENT_HEATWAVE, 16000);
					break;
				case EVENT_MOLTENREACH:
					DoCastVictim(SPELL_MOLTENREACH);
					events.ScheduleEvent(EVENT_MOLTENREACH, 20000);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override {
		return new Boss_RoltallAI(creature);
	}
};

void AddSC_Boss_Roltall()
{
	new Boss_Roltall();
}
