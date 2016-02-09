#include "boss_skulloc.h"

struct boss_skullocAI : public BossAI
{
    boss_skullocAI(Creature *creature) : BossAI(creature, DATA_SKULLOC) { }

    void EnterEvadeMode() override
    {
        _DespawnAtEvade();
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
    }

    void DamageTaken(Unit* source, uint32& damage) override
    {
        BossAI::DamageTaken(source, damage);
    }

    void EnterCombat(Unit* who) override
    {
        BossAI::EnterCombat(who);
    }

    void ExecuteEvent(uint32 eventId) override
    {
    }
};

struct npc_koramarAI : public ScriptedAI
{
    npc_koramarAI(Creature* pCreature) : ScriptedAI(pCreature) { }

    void EnterEvadeMode() override
    {
    }

    void JustDied(Unit* killer) override
    {
    }

    void DamageTaken(Unit* source, uint32& damage) override
    {
    }

    void EnterCombat(Unit* who) override
    {
    }

    void UpdateAI(uint32 diff) override
    {
    }

    void ExecuteEvent(uint32 eventId)
    {
    }
};

struct npc_zoggoshAI : public ScriptedAI
{
    npc_zoggoshAI(Creature* pCreature) : ScriptedAI(pCreature) { }

    void EnterEvadeMode() override
    {
    }

    void JustDied(Unit* killer) override
    {
    }

    void DamageTaken(Unit* source, uint32& damage) override
    {
    }

    void EnterCombat(Unit* who) override
    {
    }

    void UpdateAI(uint32 diff) override
    {
    }

    void ExecuteEvent(uint32 eventId)
    {
    }
};

void AddSC_boss_skulloc()
{
    new IronDocksAILoader<boss_skullocAI>("boss_skulloc");
    new IronDocksAILoader<npc_koramarAI>("npc_koramar");
    new IronDocksAILoader<npc_zoggoshAI>("npc_zoggosh");
}