#include "boss_oshir.h"

struct boss_oshirAI : public BossAI
{
    boss_oshirAI(Creature *creature) : BossAI(creature, DATA_OSHIR) { }

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

struct npc_ravenous_wolfAI : public ScriptedAI
{
    npc_ravenous_wolfAI(Creature* pCreature) : ScriptedAI(pCreature) { }

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

struct npc_rylak_skyterrorAI : public ScriptedAI
{
    npc_rylak_skyterrorAI(Creature* pCreature) : ScriptedAI(pCreature) { }

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

void AddSC_boss_oshir()
{
    new IronDocksAILoader<boss_oshirAI>("boss_oshir");
    new IronDocksAILoader<npc_ravenous_wolfAI>("npc_ravenous_wolf");
    new IronDocksAILoader<npc_rylak_skyterrorAI>("npc_rylak_skyterror");
}
