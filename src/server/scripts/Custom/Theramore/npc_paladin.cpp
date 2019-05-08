#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_DIVINE_STORM          = 100034,
    SPELL_HAMMER_OF_JUSTICE     = 100035,
    SPELL_HAND_OF_RECKONING     = 100036,
    SPELL_HAND_OF_PROTECTION    = 100037,
    SPELL_SACRED_LIGHT          =  68013
};

enum Casting
{
    CASTING_DIVINE_STORM        = 1,
    CASTING_HAMMER_OF_JUSTICE,
    CASTING_HAND_OF_RECKONING,
    CASTING_SACRED_LIGHT,
};

class npc_paladin : public CreatureScript
{
    public:
    npc_paladin() : CreatureScript("npc_paladin") {}

    struct npc_paladinAI : public ScriptedAI
    {
        npc_paladinAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            handOfProtection = false;
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_DIVINE_STORM, 5s);
            events.ScheduleEvent(CASTING_HAMMER_OF_JUSTICE, 8s);
            events.ScheduleEvent(CASTING_HAND_OF_RECKONING, 1s);
        }

        void Reset() override
        {
            events.Reset();
            Initialize();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (!handOfProtection && HealthBelowPct(10))
            {
                DoCastSelf(SPELL_HAND_OF_PROTECTION);
                handOfProtection = true;
                events.ScheduleEvent(CASTING_SACRED_LIGHT, 2s);
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
                    case CASTING_DIVINE_STORM:
                        DoCast(SPELL_DIVINE_STORM);
                        events.RescheduleEvent(CASTING_DIVINE_STORM, 8s, 18s);
                        break;

                    case CASTING_HAMMER_OF_JUSTICE:
                        DoCastVictim(SPELL_HAMMER_OF_JUSTICE);
                        events.RescheduleEvent(CASTING_HAMMER_OF_JUSTICE, 8s, 18s);
                        break;

                    case CASTING_HAND_OF_RECKONING:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_HAND_OF_RECKONING);
                        events.RescheduleEvent(CASTING_HAND_OF_RECKONING, 8s, 18s);
                        break;

                    case CASTING_SACRED_LIGHT:
                        if (HealthAbovePct(50))
                        {
                            DoCastSelf(SPELL_SACRED_LIGHT);
                            events.RescheduleEvent(CASTING_HAND_OF_RECKONING, 1s);
                        }
                        else
                            events.CancelEvent(CASTING_HAND_OF_RECKONING);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
        EventMap events;
        bool handOfProtection;
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new npc_paladinAI(creature);
    }
};

void AddSC_npc_paladin()
{
    new npc_paladin();
}
