#include "CustomAI.h"

CustomAI::CustomAI(Creature* creature) : ScriptedAI(creature), summons(creature)
{
    Initialize();

    scheduler.SetValidator([this]
    {
        return !me->HasUnitState(UNIT_STATE_CASTING);
    });
}

void CustomAI::JustSummoned(Creature* summon)
{
    summons.Summon(summon);

    ScriptedAI::JustSummoned(summon);
}

void CustomAI::SummonedCreatureDespawn(Creature* summon)
{
    summons.Despawn(summon);

    ScriptedAI::SummonedCreatureDespawn(summon);
}

void CustomAI::EnterEvadeMode(EvadeReason why)
{
    events.Reset();
    summons.DespawnAll();
    scheduler.CancelAll();

    ScriptedAI::EnterEvadeMode(why);
}

void CustomAI::Reset()
{
    Initialize();

    events.Reset();
    summons.DespawnAll();
    scheduler.CancelAll();

    ScriptedAI::Reset();
}

void CustomAI::JustEngagedWith(Unit* who)
{
    events.Reset();
    summons.DespawnAll();
    scheduler.CancelAll();

    ScriptedAI::JustEngagedWith(who);
}

void CustomAI::JustDied(Unit* killer)
{
    events.Reset();
    summons.DespawnAll();
    scheduler.CancelAll();

    ScriptedAI::JustDied(killer);
}

void CustomAI::UpdateAI(uint32 diff)
{
    ScriptedAI::UpdateAI(diff);

    if (!UpdateVictim())
        return;

    scheduler.Update(diff, [this]
    {
        DoMeleeAttackIfReady();
    });
}
