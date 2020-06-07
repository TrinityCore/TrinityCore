#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Custom/AI/CustomAI.h"

enum Spells
{
    SPELL_DIVINE_STORM          = 100034,
    SPELL_HAMMER_OF_JUSTICE     = 100035,
    SPELL_HAND_OF_RECKONING     = 100036,
    SPELL_SACRED_LIGHT          = 100071,
    SPELL_DIVINE_SHIELD         = 100072,
    SPELL_JUDGMENT_OF_COMMAND   = 100073
};

enum Groups
{
    GROUP_FIGHT
};

class npc_paladin : public CreatureScript
{
    public:
    npc_paladin() : CreatureScript("npc_paladin")
    {
    }

    struct npc_paladinAI : public CustomAI
    {
        npc_paladinAI(Creature* creature) : CustomAI(creature, DISTANCE), healOnCooldown(false)
        {
            scheduler.SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            });
        }

        void JustEngagedWith(Unit* who) override
        {
            scheduler
                .Schedule(5s, GROUP_FIGHT, [this](TaskContext divine_storm)
                {
                    DoCast(SPELL_DIVINE_STORM);
                    divine_storm.Repeat(18s, 25s);
                })
                .Schedule(8s, GROUP_FIGHT, [this](TaskContext divine_storm)
                {
                    if (Unit* target = DoSelectCastingUnit(SPELL_HAMMER_OF_JUSTICE, 35.f))
                    {
                        DoCast(target, SPELL_HAMMER_OF_JUSTICE);
                        divine_storm.Repeat(24s, 32s);
                    }
                    else
                    {
                        divine_storm.Repeat(1s);
                    }
                })
                .Schedule(13s, [this](TaskContext judgment_of_command)
                {
                    DoCastVictim(SPELL_JUDGMENT_OF_COMMAND);
                    judgment_of_command.Repeat(18s, 29s);
                })
                .Schedule(5s, GROUP_FIGHT, [this](TaskContext divine_storm)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_MAXDISTANCE, 0))
                        DoCast(target, SPELL_HAND_OF_RECKONING);
                    divine_storm.Repeat(24s, 35s);
                });
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (!healOnCooldown && HealthBelowPct(20))
            {
                scheduler.DelayGroup(GROUP_FIGHT, 5s);

                DoCastSelf(SPELL_DIVINE_SHIELD);

                healOnCooldown = true;

                scheduler
                    .Schedule(1s, [this](TaskContext /*context*/)
                    {
                        DoCastSelf(SPELL_SACRED_LIGHT);
                    })
                    .Schedule(1min, [this](TaskContext /*context*/)
                    {
                        healOnCooldown = false;
                    });
            }
        }

        private:
        bool healOnCooldown;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_paladinAI(creature);
    }
};

void AddSC_npc_paladin()
{
    new npc_paladin();
}
