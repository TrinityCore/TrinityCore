#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_LIGHTNING_BOLT    = 100026,
    SPELL_HEALING_WAVE      = 100025,
    SPELL_HEX               = 51514,
    SPELL_HEALING           = 100030,
    SPELL_LIGHTNING_CHAIN   = 100031,

    NPC_HEALING_TOTEM       = 100036
};

enum Casting
{
    CASTING_LIGHTNING_BOLT  = 1,
    CASTING_HEALING_WAVE,
    CASTING_HEX,
    CASTING_HEALING_TOTEM,
    CASTING_LIGHTNING_CHAIN
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
            events.ScheduleEvent(CASTING_HEALING_TOTEM, 6s);
            events.ScheduleEvent(CASTING_LIGHTNING_CHAIN, 14s);
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

                case CASTING_LIGHTNING_CHAIN:
                    DoCastVictim(SPELL_LIGHTNING_CHAIN);
                    events.RescheduleEvent(CASTING_LIGHTNING_CHAIN, 14s, 24s);
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

                case CASTING_HEALING_TOTEM:
                {
                    float alpha = 2.f * float(M_PI) * float(rand_norm());
                    float r = 3.f * sqrtf(float(rand_norm()));
                    float x = r * cosf(alpha) + me->GetPositionX();
                    float y = r * sinf(alpha) + me->GetPositionY();
                    Position pos = { x, y, me->GetPositionZ(), 0.f };

                    if (Creature * totem = DoSummon(NPC_HEALING_TOTEM, pos, 15000, TEMPSUMMON_TIMED_DESPAWN))
                    {
                        totem->SetFaction(me->GetFaction());
                        totem->CastSpell(totem, SPELL_HEALING);
                        totem->SetReactState(REACT_PASSIVE);
                    }

                    events.RescheduleEvent(CASTING_HEALING_TOTEM, 32s, 60s);
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
        return new npc_shamanAI(creature);
    }
};

void AddSC_npc_shaman()
{
    new npc_shaman();
}
