#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "scarlet_halls.h"

// Cosmetic ToDo: Call for Help (he should summon guards) will be done soon

enum Spells
{
    SPELL_BERSERKER_RAGE  = 111221,
    SPELL_BLADES_OF_LIGHT = 111216,
    SPELL_DRAGONS_REACH   = 111217,
    SPELL_HEROIC_LEAP     = 111218
};

enum Events
{
    EVENT_RAGE = 1,
    EVENT_BLADES,
    EVENT_DRAGON,
    EVENT_HAR_JUMP,
    EVENT_MOVE,
    EVENT_STOP_MOVE,
};

enum Texts
{
    SAY_AGGRO             = 0,
    SAY_CALL_GUARDS       = 1,
    SAY_KILLER1           = 2,
    SAY_KILLER2           = 3,
    SAY_DEATH             = 4
};

//58632
struct boss_armsmaster_harlan : public BossAI
{
    boss_armsmaster_harlan(Creature* creature) : BossAI(creature, DATA_ARMSMASTER_HARLAN) { }

private:
    bool rage;

    void Reset() override
    {
        BossAI::Reset();
        rage = false;
        me->GetMotionMaster()->Clear();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_HAR_JUMP, 30000);
        events.ScheduleEvent(EVENT_DRAGON, 4000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer() && roll_chance_f(15))
            Talk(RAND(SAY_KILLER1, SAY_KILLER2));
    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
    {
        if(!rage && !me->IsNonMeleeSpellCast(false) && HealthBelowPct(10))
        {
            rage = true;
            DoCast(me, SPELL_BERSERKER_RAGE);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch(eventId)
        {
        case EVENT_HAR_JUMP:
            me->GetMotionMaster()->MoveJump(1206.589f, 444.073f, 0.987f, 40.0f, 40.0f, false);
            DoCastAOE(SPELL_HEROIC_LEAP);
            events.ScheduleEvent(EVENT_BLADES, 15000);
            break;
        case EVENT_BLADES:
            me->getThreatManager().resetAllAggro();
            DoCast(me, SPELL_BLADES_OF_LIGHT);
            events.ScheduleEvent(EVENT_MOVE, 7000);
            events.CancelEvent(EVENT_DRAGON);
            break;
        case EVENT_MOVE:
             // the move status (random or with special points?) needs more infos @ retail
             events.ScheduleEvent(EVENT_STOP_MOVE, 12000);
             break;
        case EVENT_STOP_MOVE:
             events.CancelEvent(EVENT_MOVE);
             events.CancelEvent(EVENT_BLADES);
             events.ScheduleEvent(EVENT_HAR_JUMP, 50000);
             events.ScheduleEvent(EVENT_DRAGON, 4000);
             break;
        case EVENT_DRAGON:
            DoCastVictim(SPELL_DRAGONS_REACH);
            events.ScheduleEvent(EVENT_DRAGON, 4000);
            break;
        }
    }
};

void AddSC_armsmaster_harlan()
{
    RegisterCreatureAI(boss_armsmaster_harlan);
}
