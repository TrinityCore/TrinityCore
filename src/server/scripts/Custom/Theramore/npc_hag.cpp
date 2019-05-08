#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
	SPELL_FIREBALL          = 100003,
	SPELL_ICE_LANCE         = 100007,
	SPELL_ICE_BLOCK         = 100008,
	SPELL_BLINK             = 64662,
	SPELL_ARCANE_BLAST      = 100010,
};

enum Casting
{
	CASTING_FIREBALL		= 1,
	CASTING_ICE_LANCE,
	CASTING_BLINK,
	CASTING_ARCANE_BLAST
};

class npc_hag : public CreatureScript
{
    public:
    npc_hag() : CreatureScript("npc_hag") {}

    struct npc_hagAI : public ScriptedAI
    {
        npc_hagAI(Creature* creature) : ScriptedAI(creature)
		{
			Initialize();
		}

		void Initialize()
		{
			iceBlocked = false;
		}

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_FIREBALL, 1s);
            events.ScheduleEvent(CASTING_ICE_LANCE, 5s);
            events.ScheduleEvent(CASTING_BLINK, 10s);
            events.ScheduleEvent(CASTING_ARCANE_BLAST, 3s);
        }

        void AttackStart(Unit* who) override
        {
            if (!who)
                return;

            if (me->Attack(who, false))
                DoStartMovement(who, 35.f);
        }

        void Reset() override
        {
            events.Reset();
			Initialize();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (!iceBlocked && HealthBelowPct(30))
            {
                me->InterruptNonMeleeSpells(false);
                DoCastSelf(SPELL_ICE_BLOCK);
				iceBlocked = true;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            // Combat
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case CASTING_FIREBALL:
                        DoCastVictim(SPELL_FIREBALL);
                        events.RescheduleEvent(CASTING_FIREBALL, 1180);
                        break;

                    case CASTING_ICE_LANCE:
                        me->InterruptNonMeleeSpells(true);
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_ICE_LANCE);
                        events.RescheduleEvent(CASTING_ICE_LANCE, 8s, 15s);
                        break;

                    case CASTING_BLINK:
                        me->InterruptNonMeleeSpells(true);
                        DoCastVictim(SPELL_BLINK);
                        events.RescheduleEvent(CASTING_BLINK, 20s, 30s);
                        break;

                    case CASTING_ARCANE_BLAST:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_ARCANE_BLAST);
                        events.RescheduleEvent(CASTING_ARCANE_BLAST, 8s, 14s);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
        EventMap events;
		bool iceBlocked;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_hagAI(creature);
    }
};

void AddSC_npc_hag()
{
    new npc_hag();
}
