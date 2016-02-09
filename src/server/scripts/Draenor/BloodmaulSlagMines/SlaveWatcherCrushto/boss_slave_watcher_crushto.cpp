#include "boss_slave_watcher_crushto.h"

struct boss_slave_watcher_crushtoAI : public BossAI
{
    boss_slave_watcher_crushtoAI(Creature *creature) : BossAI(creature, DATA_SLAVE_WATCHER_CRUSHTO) { }

    void EnterEvadeMode() override
    {
        _DespawnAtEvade();
    }

    void EnterCombat(Unit *who) override
    {
        BossAI::EnterCombat(who);

        events.ScheduleEvent(EVENT_EARTH_CRUSH, TIME_EARTH_CRUSH_INIT);
        events.ScheduleEvent(EVENT_FEROCIOUS_YELL, TIME_FEROCIOUS_YELL_INIT);
        events.ScheduleEvent(EVENT_WILD_SLAM, TIME_WILD_SLAM_INIT);
        events.ScheduleEvent(EVENT_RAISE_THE_MINERS, TIME_RAISE_THE_MINERS_INIT);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_EARTH_CRUSH:
            {
                DoCastVictim(SPELL_EARTH_CRUSH);

                events.ScheduleEvent(EVENT_EARTH_CRUSH, urand(TIME_EARTH_CRUSH_MIN, TIME_EARTH_CRUSH_MAX));
                break;
            }
            case EVENT_FEROCIOUS_YELL:
            {
                DoCastAOE(SPELL_FEROCIOUS_YELL);

                events.ScheduleEvent(EVENT_FEROCIOUS_YELL, urand(TIME_FEROCIOUS_YELL_MIN, TIME_FEROCIOUS_YELL_MAX));
                break;
            }
            case EVENT_WILD_SLAM:
            {
                DoCastAOE(SPELL_WILD_SLAM);

                events.ScheduleEvent(EVENT_WILD_SLAM, TIME_WILD_SLAM);
                events.ScheduleEvent(EVENT_CRUSHING_LEAP, TIME_CRUSHING_LEAP);
                break;
            }
            case EVENT_CRUSHING_LEAP:
            {
                DoCastAOE(SPELL_CRUSHING_LEAP);
                break;
            }
            case EVENT_RAISE_THE_MINERS:
            {
                DoCast(SPELL_RAISE_THE_MINERS);

                events.ScheduleEvent(EVENT_RAISE_THE_MINERS, urand(TIME_RAISE_THE_MINERS_MIN, TIME_RAISE_THE_MINERS_MAX));
                break;
            }
        }
    }
};

void AddSC_boss_slave_watcher_crushto()
{
    new BloodmaulSlagMinesAILoader<boss_slave_watcher_crushtoAI>("boss_slave_watcher_crushto");
}
