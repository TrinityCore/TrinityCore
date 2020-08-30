#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CustomAI.h"

enum Constants
{
    SPELL_CLEAVE                = 100029,
    SPELL_PROCOCATION           = 100038,
    SPELL_CHARGE                = 100083,
    SPELL_EXECUTE               = 100084,
    SPELL_INCAPACITATING_SHOUT  = 61578,
    SPELL_BATTLE_SHOUT          = 24438,

    // Aden ignores death
    NPC_LIEUTENANT_ADEN         = 100004
};

class npc_warrior : public CreatureScript
{
    public:
    npc_warrior() : CreatureScript("npc_warrior") {}

    struct npc_warriorAI : public CustomAI
    {
        npc_warriorAI(Creature* creature) : CustomAI(creature, AI_Type::Melee) {}

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            // Que pour la bataille de Theramore et pour Aden
            if (me->GetEntry() == NPC_LIEUTENANT_ADEN && me->GetMapId() == 726)
            {
                if (damage >= me->GetMaxHealth())
                    damage = 0;

                if (HealthBelowPct(20))
                    damage = 0;
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            DoCast(SPELL_BATTLE_SHOUT);

            scheduler
                .Schedule(5ms, 5s, [this](TaskContext charge)
                {
                    DoCast(SPELL_CHARGE);
                })
                .Schedule(5ms, [this](TaskContext execute)
                {
                    if (Unit* victim = me->GetVictim())
                    {
                        if (victim->GetHealthPct() <= 20)
                        {
                            DoCast(SPELL_EXECUTE);
                            execute.Repeat(20s, 35s);
                        }
                        else
                            execute.Repeat(2s);
                    }
                    else
                        execute.Repeat(2s);
                })
                .Schedule(5s, [this](TaskContext incapaciting_shout)
                {
                    DoCast(SPELL_INCAPACITATING_SHOUT);
                    incapaciting_shout.Repeat(40s, 60s);
                })
                .Schedule(8s, [this](TaskContext cleave)
                {
                    DoCast(SPELL_CLEAVE);
                    cleave.Repeat(14s, 28s);
                })
                .Schedule(10s, [this](TaskContext provocation)
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::MinThreat, 0))
                        DoCast(target, SPELL_PROCOCATION);
                    provocation.Repeat(32s, 60s);
                });
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_warriorAI(creature);
    }
};

void AddSC_npc_warrior()
{
    new npc_warrior();
}
