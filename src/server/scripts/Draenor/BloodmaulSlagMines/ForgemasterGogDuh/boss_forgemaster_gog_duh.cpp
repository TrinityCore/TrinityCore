#include "boss_forgemaster_gog_duh.h"

struct boss_forgemaster_gog_duhAI : public BossAI
{
    boss_forgemaster_gog_duhAI(Creature *creature) : BossAI(creature, DATA_FORGEMASTER_GOG_DUH) { }

    void EnterEvadeMode() override
    {
        _DespawnAtEvade();
    }

    void JustDied(Unit *killer) override
    {
        // We do not call BossAI::JustDied(Unit *killer),
        // because the encounter is not complete with Forgemaster Gog'duh dead
    }

    void DamageTaken(Unit *source, uint32 &damage) override
    {
        BossAI::DamageTaken(source, damage);

        if (damage > me->GetHealth())
        {
            damage = me->GetHealth() - 1;

            if (!events.IsInPhase(PHASE_FORGEMASTER_DEAD))
            {
                events.SetPhase(PHASE_FORGEMASTER_DEAD);

                    /*
                        Feign Death
                        Activate Magmolatus
                    */

                events.ScheduleEvent(EVENT_EXPLODE, TIME_EXPLODE);
            }
        }
    }

    void EnterCombat(Unit *who) override
    {
        BossAI::EnterCombat(who);
        events.SetPhase(PHASE_FORGEMASTER_ALIVE);

        events.ScheduleEvent(EVENT_MAGMA_BARRAGE, TIME_MAGMA_BARRAGE_INIT, 0, PHASE_FORGEMASTER_ALIVE);
        events.ScheduleEvent(EVENT_THROW_EARTH, TIME_THROW_EARTH, 0, PHASE_FORGEMASTER_ALIVE);
        events.ScheduleEvent(EVENT_THROW_FIRE, TIME_THROW_FIRE, 0, PHASE_FORGEMASTER_ALIVE);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_MAGMA_BARRAGE:
            {
                DoCastAOE(SPELL_MAGMA_BARRAGE);
                events.ScheduleEvent(EVENT_MAGMA_BARRAGE, TIME_MAGMA_BARRAGE, 0, PHASE_FORGEMASTER_ALIVE);
                break;
            }
            case EVENT_THROW_EARTH:
            {
                DoCastAOE(SPELL_THROW_EARTH);
                break;
            }
            case EVENT_THROW_FIRE:
            {
                DoCastAOE(SPELL_THROW_FIRE);
                break;
            }
            case EVENT_EXPLODE:
            {
                DoCast(SPELL_CAMERA_SHAKE);
                DoCast(SPELL_EXPLOSIVE_DEATH);
                DoCast(SPELL_SUICIDE);
            }
        }
    }
};

struct boss_magmolatusAI : public BossAI
{
    boss_magmolatusAI(Creature *creature) : BossAI(creature, DATA_FORGEMASTER_GOG_DUH) { }


};

void AddSC_boss_forgemaster_gog_duh()
{
    new BloodmaulSlagMinesAILoader<boss_forgemaster_gog_duhAI>("boss_forgemaster_gog_duh");
}
