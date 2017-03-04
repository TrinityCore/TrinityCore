#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "Player.h"

enum Events
{
	EVENT_SHADOW_VOLLEY			= 1,
	EVENT_THUNDERCLAP,
	EVENT_BERSERK,
	EVENT_CLEAVE,
	EVENT_VOIDBOLT,
	EVENT_MARK_OF_KAZZAK,
	EVENT_TWISTED_REFLECTION
};

enum Spells
{
	SPELL_SHADOW_VOLLEY			= 21341,
	SPELL_THUNDERCLAP			= 26554,
	SPELL_BESERK				= 21340,
	SPELL_CLEAVE				= 20691,
	SPELL_VOIDBOLT				= 21066,
	SPELL_MARK_OF_KAZZAK		= 21056,
	SPELL_CAPTURESOUL			= 21053,
	SPELL_TWISTED_REFLECTION	= 21063
};

class boss_lord_kazzak : public CreatureScript
{
public:
	boss_lord_kazzak() : CreatureScript("boss_lord_kazzak") { }

	struct boss_lordkazzakAI : public WorldBossAI
	{
		boss_lordkazzakAI(Creature* creature) : WorldBossAI(creature)
		{

		}

		void Reset() override
		{
			_Reset();
		}

		void JustRespawned() override
		{
			
		}

		void EnterCombat(Unit* /*who*/) override
		{
			events.ScheduleEvent(EVENT_SHADOW_VOLLEY, urand(3000, 12000));
			events.ScheduleEvent(EVENT_THUNDERCLAP, urand(16000, 20000));
			events.ScheduleEvent(EVENT_BERSERK, 3 * MINUTE * IN_MILLISECONDS);
			events.ScheduleEvent(EVENT_CLEAVE, 7000);
			events.ScheduleEvent(EVENT_VOIDBOLT, 30000);
			events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 25000);
			events.ScheduleEvent(EVENT_TWISTED_REFLECTION, 33000);
		}

		void KilledUnit(Unit* victim) override
		{
			if (victim->GetTypeId() != TYPEID_PLAYER)
				return;

			DoCast(me, SPELL_CAPTURESOUL);
		}

		void JustDied(Unit* /*killer*/) override
		{

		}

		void UpdateAI(uint32 diff) override
		{
			// Return since we have no target
			if (!UpdateVictim())
				return;

			events.Update(diff);

			// Return if Kazzak is already casting something
			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
					case EVENT_SHADOW_VOLLEY:
						DoCast(SPELL_SHADOW_VOLLEY);
						events.ScheduleEvent(EVENT_SHADOW_VOLLEY, urand(5000, 30000));
						break;

					case EVENT_THUNDERCLAP:
						DoCast(SPELL_THUNDERCLAP);
						events.ScheduleEvent(EVENT_THUNDERCLAP, urand(10000, 14000));
						break;

					case EVENT_CLEAVE:
						DoCastVictim(SPELL_CLEAVE);
						events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 12000));
						break;

					case EVENT_VOIDBOLT:
						DoCastVictim(SPELL_VOIDBOLT);
						events.ScheduleEvent(EVENT_VOIDBOLT, urand(15000, 28000));
						break;

					case EVENT_MARK_OF_KAZZAK:
						/* Select a random target that isn't a pet, IS a Mana user but ignores targets that already have the debuff */
						if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, [&](Unit* u) { return u && !u->IsPet() && u->getPowerType() == POWER_MANA && !u->HasAura(SPELL_MARK_OF_KAZZAK); }))
							DoCast(target, SPELL_MARK_OF_KAZZAK);

						events.ScheduleEvent(EVENT_MARK_OF_KAZZAK, 20000);
						break;

					case EVENT_TWISTED_REFLECTION:			
						if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
							DoCast(target, SPELL_TWISTED_REFLECTION);

						events.ScheduleEvent(EVENT_TWISTED_REFLECTION, 15000);
						break;

					case EVENT_BERSERK:
						DoCast(SPELL_BESERK);
						break;

					default:
						break;
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new boss_lordkazzakAI(creature);
	}
};

void AddSC_boss_lordkazzak()
{
	new boss_lord_kazzak();
}