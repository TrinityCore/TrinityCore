#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_CLEAVE            = 100029,
    SPELL_PROCOCATION       = 100038
};

enum Casting
{
    CASTING_CLEAVE          = 1,
    CASTING_PROCOCATION
};

class npc_warrior : public CreatureScript
{
    public:
    npc_warrior() : CreatureScript("npc_warrior") {}

    struct npc_warriorAI : public ScriptedAI
    {
        npc_warriorAI(Creature* creature) : ScriptedAI(creature) {}

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(SPELL_CLEAVE, 5s);
            events.ScheduleEvent(SPELL_PROCOCATION, 10s);
        }

        void Reset() override
        {
            events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            // Combat
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case CASTING_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.RescheduleEvent(CASTING_CLEAVE, 14s, 28s);
                        break;

                    case CASTING_PROCOCATION:
                        if (Unit * target = SelectTarget(SELECT_TARGET_MINTHREAT, 0))
                            DoCast(target, SPELL_PROCOCATION);
                        events.RescheduleEvent(CASTING_PROCOCATION, 32s, 60s);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new npc_warriorAI(creature);
    }
};

void AddSC_npc_warrior()
{
    new npc_warrior();
}
