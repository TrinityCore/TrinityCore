#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ThreatManager.h"
#include "Custom/AI/CustomAI.h"

enum Spells
{
    SPELL_LIGHTNING_BOLT    = 100026,
    SPELL_HEALING_WAVE      = 100025,
    SPELL_HEX               = 51514,
    SPELL_HEALING           = 100030,
    SPELL_LIGHTNING_CHAIN   = 100031,

    NPC_HEALING_TOTEM       = 100036
};

class npc_shaman : public CreatureScript
{
    public:
    npc_shaman() : CreatureScript("npc_shaman") {}

    struct npc_shamanAI : public CustomAI
    {
        npc_shamanAI(Creature* creature) : CustomAI(creature)
        {
            scheduler.SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            });
        }

        void JustEngagedWith(Unit* who) override
        {
            scheduler
                .Schedule(Seconds(1), [this](TaskContext lighting_bolt)
                {
                    DoCastVictim(SPELL_LIGHTNING_BOLT);
                    lighting_bolt.Repeat(Seconds(10), Seconds(15));
                })
                .Schedule(Seconds(12), [this](TaskContext lightning_chain)
                {
                    DoCastVictim(SPELL_LIGHTNING_CHAIN);
                    lightning_chain.Repeat(Seconds(14), Seconds(25));
                })
                .Schedule(Seconds(3), [this](TaskContext hex)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT, 0))
                        DoCast(target, SPELL_HEX);
                    hex.Repeat(Seconds(25), Seconds(30));
                })
                .Schedule(Seconds(3), [this](TaskContext healing_wave)
                {
                    if (Unit * target = DoSelectLowestHpFriendly(40.0f))
                    {
                        me->InterruptNonMeleeSpells(true);
                        DoCast(target, SPELL_HEALING_WAVE);
                    }
                    healing_wave.Repeat(Seconds(8));
                })
                .Schedule(Seconds(6), [this](TaskContext healing_totem)
                {
                    if (Creature* healingTotem = DoSummon(NPC_HEALING_TOTEM, me->GetRandomNearPosition(2.f), 15000, TEMPSUMMON_TIMED_DESPAWN))
                    {
                        healingTotem->SetFaction(me->GetFaction());
                        healingTotem->CastSpell(healingTotem, SPELL_HEALING);
                        healingTotem->SetReactState(REACT_PASSIVE);
                    }
                    healing_totem.Repeat(Seconds(20), Seconds(30));
                });

            DoStartNoMovement(who);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_shamanAI(creature);
    }
};

void AddSC_npc_shaman()
{
    new npc_shaman();
}
