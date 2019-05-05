#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_SHADOW_BOLT       = 100028,
    SPELL_FEL_FIREBALL      = 100027
};

enum Casting
{
    CASTING_SHADOWN_BOLT    = 1,
    CASTING_FEL_FIREBALL,
};

class npc_felcaster : public CreatureScript
{
    public:
    npc_felcaster() : CreatureScript("npc_felcaster") {}

    struct npc_felcasterAI : public ScriptedAI
    {
        npc_felcasterAI(Creature* creature) : ScriptedAI(creature) { }

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_SHADOWN_BOLT, 1s);
            events.ScheduleEvent(CASTING_FEL_FIREBALL, 3s);
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
                    case CASTING_SHADOWN_BOLT:
                        DoCastVictim(SPELL_SHADOW_BOLT);
                        events.RescheduleEvent(CASTING_SHADOWN_BOLT, 1180);
                        break;

                    case CASTING_FEL_FIREBALL:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, SPELL_FEL_FIREBALL);
                        events.RescheduleEvent(CASTING_FEL_FIREBALL, 25s, 30s);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

        private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_felcasterAI(creature);
    }
};

void AddSC_npc_felcaster()
{
    new npc_felcaster();
}
