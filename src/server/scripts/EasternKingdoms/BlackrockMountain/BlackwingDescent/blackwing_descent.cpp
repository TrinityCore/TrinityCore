#include "ScriptMgr.h"
#include "blackwing_descent.h"

enum Says
{
    SAY_INTRO_NORMAL = 0,
    SAY_INTRO_HEROIC = 1
};

class mob_nefarian_helper_heroic : public CreatureScript
{
public:
    mob_nefarian_helper_heroic() : CreatureScript("mob_nefarian_helper_heroic") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_nefarian_helper_heroicAI (creature);
    }

    struct mob_nefarian_helper_heroicAI : public ScriptedAI
    {
        mob_nefarian_helper_heroicAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }
    };
};

class mob_nefarian_yeller : public CreatureScript // 49580
{
public:
    mob_nefarian_yeller() : CreatureScript("mob_nefarian_yeller") { }

    struct mob_nefarian_yellerAI : public ScriptedAI
    {
        mob_nefarian_yellerAI(Creature* creature) : ScriptedAI(creature)
        {
            timer = 1000;
            introSaid = false;
            creature->SetReactState(REACT_PASSIVE);
            creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            creature->SetDisplayId(32440);
        }

        uint32 timer;
        bool introSaid;

        void UpdateAI(uint32 diff) override
        {
            if (timer <= diff)
            {
                if (Player* target = me->SelectNearestPlayer(20.0f))
                {
                    if (target->GetDistance(me) <= 20.0f && !introSaid)
                    {
                        if(!me->GetMap()->IsHeroic())
                            Talk(SAY_INTRO_NORMAL);
                        else
                            Talk(SAY_INTRO_HEROIC);

                        introSaid = true;

                        me->DespawnOrUnsummon(15000);
                    } else
                        timer = 1000;
                }
                else
                    timer = 1000;

            } else timer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new mob_nefarian_yellerAI(creature);
    }
};

void AddSC_blackwing_descent()
{
    new mob_nefarian_helper_heroic();
    new mob_nefarian_yeller();
}
