#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "darkheart_thicket.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_NIGHTMARE = 1,
    SAY_CRUSHING = 2,
    SAY_ROOTS = 3,
    SAY_EARTH = 4,
    SAY_DEATH = 5,
};

enum Spells
{
    SPELL_CANCEL_DEEP_ROOTS = 165953, //Remove 165950
    SPELL_SHATTERED_EARTH = 204666,
    SPELL_STRANGLING_ROOTS = 204574,
    SPELL_STRANGLING_ROOTS_AT = 199067,
    SPELL_NIGHTMARE_BREATH = 204667,
    SPELL_CRUSHING_GRIP = 204611,
    //Heroic
    SPELL_UPROOT = 212786,

    //end
    SPELL_TALK = 202883,
};

enum eEvents
{
    EVENT_SHATTERED_EARTH = 1,
    EVENT_STRANGLING_ROOTS = 2,
    EVENT_NIGHTMARE_BREATH = 3,
    EVENT_CRUSHING_GRIP = 4,
    EVENT_REMOVE_PASSENGERS = 5,
    //Heroic
    EVENT_UPROOT = 6,
};

//103344
class boss_oakheart : public CreatureScript
{
public:
    boss_oakheart() : CreatureScript("boss_oakheart") {}

    struct boss_oakheartAI : public BossAI
    {
        boss_oakheartAI(Creature* creature) : BossAI(creature, DATA_OAKHEART) {}

        void Reset() override
        {
            _Reset();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _JustEngagedWith();
            events.RescheduleEvent(EVENT_SHATTERED_EARTH, 6000);
            events.RescheduleEvent(EVENT_STRANGLING_ROOTS, 14000);
            events.RescheduleEvent(EVENT_NIGHTMARE_BREATH, 22000);
            events.RescheduleEvent(EVENT_CRUSHING_GRIP, 30000);

            if (me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
                events.RescheduleEvent(EVENT_UPROOT, 34000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            DoCast(SPELL_TALK);
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (apply)
            {
                //DoCast(me, 204643, true); //Check Targets
                DoCast(204644); //Timing cast
            }
        }

        void SpellHit(Unit* target, const SpellInfo* spell) override
        {
            if (spell->Id == 204644)
            {
                events.RescheduleEvent(EVENT_REMOVE_PASSENGERS, 6000);
               // Unit* pTarget = SelectTarget(SELECT_TARGET_FARTHEST, 0, 0.0f, true);
                DoCast(204651);
                    events.CancelEvent(EVENT_REMOVE_PASSENGERS);

                Talk(SAY_CRUSHING);

            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetVictim())
                return;

            if (who && me->GetDistance(who) < 14.0f)
                AttackStart(who);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SHATTERED_EARTH:
                    DoCast(SPELL_SHATTERED_EARTH);
                    Talk(SAY_EARTH);
                    events.RescheduleEvent(EVENT_SHATTERED_EARTH, 40000);
                    break;
                case EVENT_STRANGLING_ROOTS:
                    DoCast(SPELL_STRANGLING_ROOTS);
                    Talk(SAY_ROOTS);
                    events.RescheduleEvent(EVENT_STRANGLING_ROOTS, 22000);
                    break;
                case EVENT_NIGHTMARE_BREATH:
                    DoCastVictim(SPELL_NIGHTMARE_BREATH);
                    Talk(SAY_NIGHTMARE);
                    events.RescheduleEvent(EVENT_NIGHTMARE_BREATH, 32000);
                    break;
                case EVENT_CRUSHING_GRIP:
                    DoCastVictim(SPELL_CRUSHING_GRIP);
                    events.RescheduleEvent(EVENT_CRUSHING_GRIP, 30000);
                    break;
                case EVENT_REMOVE_PASSENGERS:
                    break;
                case EVENT_UPROOT:
                    DoCast(SPELL_UPROOT);
                    events.RescheduleEvent(EVENT_UPROOT, 34000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_oakheartAI(creature);
    }
};

//100991
class npc_oakheart_strangling_roots : public CreatureScript
{
public:
    npc_oakheart_strangling_roots() : CreatureScript("npc_oakheart_strangling_roots") {}

    struct npc_oakheart_strangling_rootsAI : public ScriptedAI
    {
        npc_oakheart_strangling_rootsAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
        }

        void Reset() override {}

        void IsSummonedBy(Unit* summoner) override
        {
            DoCast(me, SPELL_STRANGLING_ROOTS_AT, true);
        }

        void UpdateAI(uint32 diff) override {}
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_oakheart_strangling_rootsAI(creature);
    }
};

void AddSC_boss_oakheart()
{
    new boss_oakheart();
    new npc_oakheart_strangling_roots();
}
