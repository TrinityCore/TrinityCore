#include "boss_fleshrender_nokgar.h"

struct boss_fleshrender_nokgarAI : public BossAI
{
    boss_fleshrender_nokgarAI(Creature* pCreature) : BossAI(pCreature, DATA_FLESHRENDER_NOKGAR) { }

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

struct npc_dreadfangAI : public ScriptedAI
{
    npc_dreadfangAI(Creature* pCreature) : ScriptedAI(pCreature) { }

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

void AddSC_boss_fleshrender_nokgar()
{
    new IronDocksAILoader<boss_fleshrender_nokgarAI>("boss_fleshrender_nokgar");
    new IronDocksAILoader<npc_dreadfangAI>("npc_dreadfang");
}
