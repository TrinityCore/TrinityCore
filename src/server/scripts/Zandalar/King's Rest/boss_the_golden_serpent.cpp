#include "kings_rest.h"

enum Spells
{
    SPELL_SPIRIT_OF_GOLD_PERIODIC = 265773,
    SPELL_MOLTEN_GOLD_MISSILE = 255583,
    SPELL_MOLTEN_GOLD_AT_DAMAGE = 265914,
    SPELL_LUCRES_CALL = 265923,
    SPELL_LUSTER = 265991,
    SPELL_TAIL_THRASH = 265910,
    SPELL_SERPENTINE_GUST = 265781,
};

enum Events
{
    EVENT_SPIRIT_OF_GOLD = 1,
    EVENT_LUCRESS_CALL,
    EVENT_LUSTER,
    EVENT_TAIL_THRASH,
    EVENT_SERPENT_GUST_WIND
};

struct boss_golden_serpent : public BossAI
{
    boss_golden_serpent(Creature* creature) : BossAI(creature, DATA_GOLDEN_SERPENT) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void EnterCombat(Unit* u) override
    {
        _EnterCombat();
        events.ScheduleEvent(EVENT_SPIRIT_OF_GOLD, 5s);
        events.ScheduleEvent(EVENT_TAIL_THRASH, 10s);
        events.ScheduleEvent(EVENT_SERPENT_GUST_WIND, 15s);
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
        case EVENT_SPIRIT_OF_GOLD:
             DoCastRandom(SPELL_SPIRIT_OF_GOLD_PERIODIC, 100.0f);
             events.Repeat(15s);
             break;

        case EVENT_TAIL_THRASH:
             DoCastVictim(SPELL_TAIL_THRASH);
             events.Repeat(25s);


        case EVENT_SERPENT_GUST_WIND:
             DoCastAOE(SPELL_SERPENTINE_GUST, false);
             events.Repeat(35s);
             break;
        }
    }

    void JustDied(Unit* u) override
    {
        _JustDied();
    }
};

//265773
class aura_spirit_of_gold : public AuraScript
{
    PrepareAuraScript(aura_spirit_of_gold);

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            caster->CastSpell(GetTarget(), SPELL_MOLTEN_GOLD_MISSILE, true);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_spirit_of_gold::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_the_golden_serpent()
{
    RegisterCreatureAI(boss_golden_serpent);
    RegisterAuraScript(aura_spirit_of_gold);
}
