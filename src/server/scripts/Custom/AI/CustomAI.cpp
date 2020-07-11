#include "CustomAI.h"

CustomAI::CustomAI(Creature* creature, AI_Type type) : ScriptedAI(creature),
    type(type), summons(creature)
{
    Initialize();
}

void CustomAI::Initialize()
{
    if (type == AI_Type::Distance)
    {
        scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }
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

void CustomAI::SummonedCreatureDies(Creature* summon, Unit* killer)
{
    summons.Despawn(summon);

    ScriptedAI::SummonedCreatureDies(summon, killer);
}

void CustomAI::EnterEvadeMode(EvadeReason why)
{
    summons.DespawnAll();
    scheduler.CancelAll();

    ScriptedAI::EnterEvadeMode(why);
}

void CustomAI::Reset()
{
    Initialize();

    summons.DespawnAll();
    scheduler.CancelAll();

    ScriptedAI::Reset();
}

void CustomAI::JustEngagedWith(Unit* who)
{
    ScriptedAI::JustEngagedWith(who);
}

void CustomAI::JustDied(Unit* killer)
{
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
