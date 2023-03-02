#include "kings_rest.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "CreatureAI.h"
#include "CreatureData.h"


enum Texts
{
    SAY_AGGRO = 0,
    SAY_BURN_CORRUPTION,
    SAY_ENTOMB,
    SAY_DEATH,
};

enum Spells
{
    SPELL_BURN_CORRUPTION_DAMAGE = 267639,
    SPELL_DRAIN_FLUIDS = 267618,
    SPELL_BURNING_GROUND_AT_DAMAGE = 267874,
    SPELL_DESSICATION = 267626,
};

enum Events
{
    EVENT_ENTOMB = 1,
    EVENT_BURN_CORRUPTION,
    EVENT_DRAIN_FLUIDS,
};

//134993
struct boss_mchimba : public BossAI
{
    boss_mchimba(Creature* creature) : BossAI(creature, DATA_MCHIMBA) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* u) override
    {        
        _EnterCombat();
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_ENTOMB, 5s);
        events.ScheduleEvent(EVENT_BURN_CORRUPTION, 10s);
        events.ScheduleEvent(EVENT_DRAIN_FLUIDS, 15s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->GetMotionMaster()->MoveTargetedHome();
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        me->RemoveAllAreaTriggers();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_BURN_CORRUPTION:
             Talk(SAY_BURN_CORRUPTION);
             DoCastRandom(SPELL_BURN_CORRUPTION_DAMAGE, 300.0f);
             events.Repeat(15s);
             break;

        case EVENT_DRAIN_FLUIDS:
             DoCastRandom(SPELL_DRAIN_FLUIDS, 300.0f);
             events.Repeat(20s);
             break;

        case EVENT_ENTOMB:
             Talk(SAY_ENTOMB);
             events.Repeat(30s);
             break;
        }
    }

    void JustDied(Unit* u) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }
};

//267618
class aura_drain_fluids : public AuraScript
{
    PrepareAuraScript(aura_drain_fluids);

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (Unit* target = GetTarget())
            caster->AddAura(SPELL_DESSICATION, target);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_drain_fluids::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_mchimba_the_embalmber()
{
    RegisterCreatureAI(boss_mchimba);
    RegisterAuraScript(aura_drain_fluids);
}
