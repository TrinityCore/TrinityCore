#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "temple_of_sethraliss.h"

enum Spells
{
    SPELL_NOXIOUS_BREATH = 272657,
    SPELL_NOXIOUS_BREATH_AT_TRIGGER = 263925, //at 12750
    SPELL_BLINDING_SAND = 263914,
    SPELL_DUST_CLOUD_DUMMY = 256359,
    SPELL_DUST_CLOUD_MISSILE = 256336, // npc 134390, spawn spell 267047
    // When she reach 60% -> burrow
    SPELL_BURROW_KNOCKBACK = 264206,
    SPELL_BURROW_CREAT_AT = 264194, // at 12779
    //After burrow -> npc wave 135846
};

enum Events
{
    EVENT_NOXIOUS_BREATH = 1,
    EVENT_BLINDING_SAND,
    EVENT_BURROW,
    EVENT_UNBURROW,
    EVENT_WAVE_1,
    EVENT_WAVE_2
};

enum Phases
{
    PHASE_1 = 1,
    PHASE_2,
    PHASE_3,
};

const Position wave_1_pos = { 3550.0f, 3447.0f, 51.0f, 4.5f };

//133384
struct boss_merektha : public BossAI
{
    boss_merektha(Creature* creature) : BossAI(creature, DATA_MEREKTHA) { }

    void Reset() override
    {
        BossAI::Reset();
        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
    }

    void EnterCombat(Unit* who) override
    {
        _EnterCombat();
        events.SetPhase(PHASE_1);
        events.ScheduleEvent(EVENT_NOXIOUS_BREATH, 3s);
        events.ScheduleEvent(EVENT_BLINDING_SAND, 8s);
    }

    void JustDied(Unit* u) override
    {
        _JustDied();
        me->NearTeleportTo(me->GetHomePosition());
        me->DespawnCreaturesInArea(NPC_SAND_CRUSHED_STRIKER, 125.0f);
        me->DespawnCreaturesInArea(NPC_SAND_CRUSTED_STRIKER_2, 125.0f);
        if (auto* MerekthaDoor = me->FindNearestGameObject(GO_MEREKTHA_EXIT, 100.0f))
            MerekthaDoor->SetGoState(GO_STATE_ACTIVE);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override 
    { 
        me->DespawnCreaturesInArea(NPC_SAND_CRUSHED_STRIKER, 125.0f);
        me->DespawnCreaturesInArea(NPC_SAND_CRUSTED_STRIKER_2, 125.0f);
    }

    void JustSummoned(Creature* summon) override 
    { 
        summon->AI()->DoZoneInCombat();
        summon->AI()->DoCast(SPELL_DUST_CLOUD_DUMMY);
        summon->AI()->DoCast(SPELL_DUST_CLOUD_MISSILE);
    }

    void DamageTaken(Unit* done_by, uint32& dmg) override
    {
        if (me->HealthBelowPctDamaged(61, dmg) && events.IsInPhase(PHASE_1))
        {
            events.SetPhase(PHASE_2);
            events.ScheduleEvent(EVENT_BURROW, 1s);
            events.ScheduleEvent(EVENT_WAVE_1, 3s);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_NOXIOUS_BREATH:
             DoCastRandom(SPELL_NOXIOUS_BREATH, 5.0f, false);
             events.Repeat(15s);
             break;

        case EVENT_BLINDING_SAND:
             DoCastAOE(SPELL_BLINDING_SAND);
             events.Repeat(20s);
             break;

        case EVENT_BURROW:
             burrow_count++;
             me->CastStop();
             me->SetReactState(REACT_PASSIVE);
             me->AddUnitState(UNIT_STAND_STATE_SUBMERGED);
             me->NearTeleportTo(3557.0f, 3422.0f, 40.0f, 3.3f, false);
             events.CancelEvent(EVENT_NOXIOUS_BREATH);
             events.CancelEvent(EVENT_BLINDING_SAND);
             events.ScheduleEvent(EVENT_UNBURROW, 30s);
             if (burrow_count == 2)
             {
                 events.ScheduleEvent(EVENT_WAVE_2, 3s);
                 events.CancelEvent(EVENT_BURROW);
                 burrow_count = 0;
             }
             break;

        case EVENT_UNBURROW:
             me->NearTeleportTo(me->GetHomePosition());
             me->ClearUnitState(UNIT_STAND_STATE_SUBMERGED);
             me->SetReactState(REACT_AGGRESSIVE);            
             events.ScheduleEvent(EVENT_NOXIOUS_BREATH, 3s);
             events.ScheduleEvent(EVENT_BLINDING_SAND, 8s);
             events.ScheduleEvent(EVENT_BURROW, 30s);
             break;

        case EVENT_WAVE_1:
             for (uint8 i = 0; i < 6; i++)
             {
                me->SummonCreature(NPC_SAND_CRUSHED_STRIKER, me->GetRandomPoint(wave_1_pos, 10.0f), TEMPSUMMON_MANUAL_DESPAWN);
             }
             break;

        case EVENT_WAVE_2:
            for (uint8 i = 0; i < 6; i++)
            {
                me->SummonCreature(NPC_SAND_CRUSTED_STRIKER_2, me->GetRandomPoint(wave_1_pos, 10.0f), TEMPSUMMON_MANUAL_DESPAWN);
            }
            break;
        }
    }
private:
    uint8 burrow_count;
};

void AddSC_boss_merektha()
{
    RegisterCreatureAI(boss_merektha);
}
