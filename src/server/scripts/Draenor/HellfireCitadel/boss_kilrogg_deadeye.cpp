#include "ScriptMgr.h"
#include "hellfire_citadel.h"

enum Spells
{
};

enum Events
{
    // Intro
    EVENT_INTRO = 1,
};

enum Phases
{
    PHASE_NORMAL,
    PHASE_INTRO
};

struct boss_kilrogg_deadeye : public BossAI
{
    boss_kilrogg_deadeye(Creature* creature) : BossAI(creature, DATA_KILROGG_DEADEYE) { Initialize(); }

    void Initialize()
    {
        PhaseStatus = Phases::PHASE_INTRO;
        hp20 = false;
    }

    void ScheduleTasks() override
    {
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (!hp20 && HealthBelowPct(20))
        {
            hp20 = true;
        }

        switch (eventId)
        {
        case EVENT_INTRO:
        {
            break;
        }
        default:
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 25.0f, false) && !IsLock)
        {
            IsLock = true;
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            events.ScheduleEvent(EVENT_INTRO, 1s, PHASE_NORMAL);
        }
    }
    uint8 PhaseStatus;
    bool hp20;
};

void AddSC_boss_kilrogg_deadeye()
{
    RegisterCreatureAI(boss_kilrogg_deadeye);
}
