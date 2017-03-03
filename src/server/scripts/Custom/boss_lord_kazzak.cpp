#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

class boss_lord_kazzak : public CreatureScript
{
public:
	boss_lord_kazzak() : CreatureScript("boss_lord_kazzak") { }

	struct boss_lordkazzakAI : public ScriptedAI
	{
		boss_lordkazzakAI(Creature* creature) : ScriptedAI(creature)
		{

		}

		void Reset() override
		{
			_events.Reset();
		}

		void JustRespawned() override
		{

		}

		void EnterCombat(Unit* /*who*/) override
		{

		}

		void KilledUnit(Unit* victim) override
		{

		}

		void JustDied(Unit* /*killer*/) override
		{

		}

		void UpdateAI(uint32 diff) override
		{
			// Return since we have no target
			if (!UpdateVictim())
				return;

			_events.Update(diff);

			// Return if Kazzak is already casting something
			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			while (uint32 eventId = _events.ExecuteEvent())
			{
				switch (eventId)
				{
					default:
						break;
				}
			}

			DoMeleeAttackIfReady();
		}

	private:
		EventMap _events;
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