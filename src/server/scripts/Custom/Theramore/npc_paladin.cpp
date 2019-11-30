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
        npc_paladinAI(Creature* creature) : CustomAI(creature), healOnCooldown(false)
        {
            scheduler.SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            });
        }

        void JustEngagedWith(Unit* who) override
        {
            scheduler
                .Schedule(Seconds(5), GROUP_FIGHT, [this](TaskContext divine_storm)
                {
                    DoCast(SPELL_DIVINE_STORM);
                    divine_storm.Repeat(Seconds(18), Seconds(25));
                })
                .Schedule(Seconds(8), GROUP_FIGHT, [this](TaskContext divine_storm)
                {
                    if (Unit* target = DoSelectCastingUnit(SPELL_HAMMER_OF_JUSTICE, 35.f))
                    {
                        DoCast(target, SPELL_HAMMER_OF_JUSTICE);
                        divine_storm.Repeat(Seconds(24), Seconds(32));
                    }
                    else
                    {
                        divine_storm.Repeat(Seconds(1));
                    }
                })
                .Schedule(Seconds(13), [this](TaskContext judgment_of_command)
                {
                    DoCastVictim(SPELL_JUDGMENT_OF_COMMAND);
                    judgment_of_command.Repeat(Seconds(18), Seconds(29));
                })
                .Schedule(Seconds(5), GROUP_FIGHT, [this](TaskContext divine_storm)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_MAXDISTANCE, 0))
                        DoCast(target, SPELL_HAND_OF_RECKONING);
                    divine_storm.Repeat(Seconds(24), Seconds(35));
                });
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (!healOnCooldown && HealthBelowPct(20))
            {
                scheduler.DelayGroup(GROUP_FIGHT, Seconds(5));

                DoCastSelf(SPELL_DIVINE_SHIELD);

                healOnCooldown = true;

                scheduler
                    .Schedule(Seconds(1), [this](TaskContext /*context*/)
                    {
                        DoCastSelf(SPELL_SACRED_LIGHT);
                    })
                    .Schedule(Minutes(1), [this](TaskContext /*context*/)
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
