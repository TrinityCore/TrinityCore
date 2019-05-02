#include "ScriptMgr.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ThreatManager.h"
#include "CreatureAIImpl.h"

enum Spells
{
    SPELL_LIGHTNING_BOLT    = 100026,
    SPELL_HEALING_WAVE      = 100025,
    SPELL_HEX               = 51514
};

enum Casting
{
    CASTING_LIGHTNING_BOLT  = 1,
    CASTING_HEALING_WAVE,
    CASTING_HEX
};

class npc_shaman : public CreatureScript
{
    public:
    npc_shaman() : CreatureScript("npc_shaman") {}

    struct npc_shamanAI : public ScriptedAI
    {
        npc_shamanAI(Creature* creature) : ScriptedAI(creature) { }

        void JustEngagedWith(Unit* /*who*/) override
        {
            events.ScheduleEvent(CASTING_LIGHTNING_BOLT, 1s);
            events.ScheduleEvent(CASTING_HEALING_WAVE, 3s);
            events.ScheduleEvent(CASTING_HEX, 8s);
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

            switch (events.ExecuteEvent())
            {
                case CASTING_LIGHTNING_BOLT:
                    DoCastVictim(SPELL_LIGHTNING_BOLT);
                    events.RescheduleEvent(CASTING_LIGHTNING_BOLT, 1180);
                    break;

                case CASTING_HEX:
                    if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_HEX);
                    events.RescheduleEvent(CASTING_HEX, 25s, 30s);
                    break;

                case CASTING_HEALING_WAVE:
                    if (Unit * target = DoSelectLowestHpFriendly(40.0f))
                        DoCast(target, SPELL_HEALING_WAVE);
                    events.RescheduleEvent(CASTING_HEALING_WAVE, 3s);
                    break;
            }

            DoMeleeAttackIfReady();
        }

        private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature * creature) const override
    {
        return new npc_shamanAI(creature);
    }
};

void AddSC_npc_shaman()
{
    new npc_shaman();
}
