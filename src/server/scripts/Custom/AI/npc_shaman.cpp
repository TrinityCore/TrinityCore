#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ThreatManager.h"
#include "CustomAI.h"

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
            SetCombatMovement(false);

            scheduler.SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            });
        }

        void JustEngagedWith(Unit* who) override
        {
            scheduler
                .Schedule(5ms, [this](TaskContext lighting_bolt)
                {
                    DoCastVictim(SPELL_LIGHTNING_BOLT);
                    lighting_bolt.Repeat(10s, 15s);
                })
                .Schedule(12s, [this](TaskContext lightning_chain)
                {
                    DoCastVictim(SPELL_LIGHTNING_CHAIN);
                    lightning_chain.Repeat(14s, 25s);
                })
                .Schedule(3s, [this](TaskContext hex)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_MAXTHREAT, 0))
                        DoCast(target, SPELL_HEX);
                    hex.Repeat(25s, 30s);
                })
                .Schedule(3s, [this](TaskContext healing_wave)
                {
                    if (Unit * target = DoSelectLowestHpFriendly(40.0f))
                    {
                        me->InterruptNonMeleeSpells(true);
                        DoCast(target, SPELL_HEALING_WAVE);
                    }
                    healing_wave.Repeat(8s);
                })
                .Schedule(6s, [this](TaskContext healing_totem)
                {
                    if (Creature* healingTotem = DoSummon(NPC_HEALING_TOTEM, me->GetRandomNearPosition(2.f), 15000, TEMPSUMMON_TIMED_DESPAWN))
                    {
                        healingTotem->SetFaction(me->GetFaction());
                        healingTotem->CastSpell(healingTotem, SPELL_HEALING);
                        healingTotem->SetReactState(REACT_PASSIVE);
                    }
                    healing_totem.Repeat(20s, 30s);
                });
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
