#include "boss_grimrail_enforcers.h"

struct boss_grimrail_enforcersAI : public BossAI
{
    boss_grimrail_enforcersAI(Creature* pCreature) : BossAI(pCreature, DATA_GRIMRAIL_ENFORCERS) { }

    void EnterEvadeMode() override
    {
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
    }

    void ExecuteEvent(uint32 eventId) override
    {
    }
};

struct npc_ahriok_dugruAI : public ScriptedAI
{
    npc_ahriok_dugruAI(Creature* pCreature) : ScriptedAI(pCreature) { }

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

struct npc_makogg_emberbladeAI : public ScriptedAI
{
    npc_makogg_emberbladeAI(Creature* pCreature) : ScriptedAI(pCreature) { }

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

struct npc_neesa_noxAI : public ScriptedAI
{
    npc_neesa_noxAI(Creature* pCreature) : ScriptedAI(pCreature) { }

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

void AddSC_boss_grimrail_enforcers()
{
    new IronDocksAILoader<boss_grimrail_enforcersAI>("boss_grimrail_enforcers");
    new IronDocksAILoader<npc_ahriok_dugruAI>("npc_ahriok_dugru");
    new IronDocksAILoader<npc_makogg_emberbladeAI>("npc_makogg_emberblade");
    new IronDocksAILoader<npc_neesa_noxAI>("npc_neesa_nox");
}

