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
	SPELL_CRUSHINGLEAP = 150751,
	SPELL_EARTHCRUSH = 153679,
	SPELL_FEROCIOUSYELL = 150759,
	SPELL_RAISETHEMINNERS = 150801,
	SPELL_WILDSLAM = 150753,
};

enum Events
{
	EVENT_CRUSHINGLEAP,
	EVENT_EARTHCRUSH,
	EVENT_FEROCIOUSYELL,
	EVENT_RAISETHEMINNERS,
	EVENT_WILDSLAM,
};

enum Minners
{
	CAPTURED_MINNER = 74356,
};

class Boss_SlaveWatcherCrushto : public CreatureScript
{
public:
	Boss_SlaveWatcherCrushto() : CreatureScript("Boss_SlaveWatcherCrushto") { }

	struct Boss_SlaveWatcherCrushtoAI : public BossAI
	{
		Boss_SlaveWatcherCrushtoAI(Creature* creature) : BossAI(creature, 74787)
		{
		}

		void Reset() override {
			_Reset();
		}

		void EnterCombat(Unit* /*who*/) override {
			 _EnterCombat();
			events.ScheduleEvent(EVENT_CRUSHINGLEAP, 4000);
			events.ScheduleEvent(EVENT_EARTHCRUSH, 8000);
			events.ScheduleEvent(EVENT_FEROCIOUSYELL, 12000);
			events.ScheduleEvent(EVENT_RAISETHEMINNERS, 16000);
			events.ScheduleEvent(EVENT_WILDSLAM, 20000);
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
				case EVENT_CRUSHINGLEAP:
					DoCastVictim(SPELL_CRUSHINGLEAP);
					events.ScheduleEvent(EVENT_CRUSHINGLEAP, 4000);
					break;
				case EVENT_EARTHCRUSH:
					DoCastAOE(SPELL_EARTHCRUSH);
					events.ScheduleEvent(EVENT_EARTHCRUSH, 8000);
					break;
				case EVENT_FEROCIOUSYELL:
					DoCast(me,SPELL_FEROCIOUSYELL);
					DoCastAOE(SPELL_FEROCIOUSYELL);
					events.ScheduleEvent(EVENT_FEROCIOUSYELL, 12000);
					break;
				case EVENT_RAISETHEMINNERS:
					Position pos = me->GetPosition();
					DoCast(SPELL_RAISETHEMINNERS);
					me->SummonCreature(CAPTURED_MINNER, pos.GetPositionX(), pos.GetPositionY(),pos.GetPositionZ(), 2.1f, TEMPSUMMON_DEAD_DESPAWN, 5000);
					me->SummonCreature(CAPTURED_MINNER, pos.GetPositionX(), pos.GetPositionY(),pos.GetPositionZ(), 2.1f, TEMPSUMMON_DEAD_DESPAWN, 5000);
					me->SummonCreature(CAPTURED_MINNER, pos.GetPositionX(), pos.GetPositionY(),pos.GetPositionZ(), 2.1f, TEMPSUMMON_DEAD_DESPAWN, 5000);
					me->SummonCreature(CAPTURED_MINNER, pos.GetPositionX(), pos.GetPositionY(),pos.GetPositionZ(), 2.1f, TEMPSUMMON_DEAD_DESPAWN, 5000);
					events.ScheduleEvent(EVENT_RAISETHEMINNERS, 16000);
					break;
				case EVENT_WILDSLAM:
					DoCastAOE(SPELL_WILDSLAM);
					events.ScheduleEvent(EVENT_WILDSLAM, 20000);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override {
		return new Boss_SlaveWatcherCrushtoAI(creature);
	}
};

void AddSC_Boss_SlaveWatcherCrushto()
{
	new Boss_SlaveWatcherCrushto();
}
