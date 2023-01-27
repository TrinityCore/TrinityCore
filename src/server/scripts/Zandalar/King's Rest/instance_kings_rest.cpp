#include "ScriptMgr.h"
#include "Player.h"
#include "InstanceScript.h"
#include "kings_rest.h"

struct instance_kings_rest : public InstanceScript
{
    instance_kings_rest(InstanceMap* map) : InstanceScript(map)
    {
        SetBossNumber(EncounterCount);
    }

    void OnGameObjectCreate(GameObject* go) override
    {
        switch (go->GetEntry())
        {
        case GO_THE_COUNCILS_CACHE:
        case GO_BOON_OF_THE_FIRST_KING:
             go->SetFlags(GO_FLAG_LOCKED);
             break;
        }
    }
};

enum Zul
{
    SPELL_SHADOW_BARRAGE = 272388,
    SPELL_DARK_REVELATION = 271640,
    EVENT_SHADOW_BARRAGE = 1,
    EVENT_DARK_REVELATION,
};

//138489
struct npc_shadow_of_zul : public ScriptedAI
{
    npc_shadow_of_zul(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
        me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
    }

    void EnterCombat(Unit* u) override
    {
        events.ScheduleEvent(EVENT_SHADOW_BARRAGE, 5s);
        events.ScheduleEvent(EVENT_DARK_REVELATION, 10s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_SHADOW_BARRAGE:
             DoCastVictim(SPELL_SHADOW_BARRAGE);
             events.Repeat(3s);

        case EVENT_DARK_REVELATION:
             DoCastRandom(SPELL_DARK_REVELATION, 100.0f);
             me->SummonCreature(NPC_MINION_OF_ZUL, me->GetPosition());
             events.Repeat(10s);
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summon->AI()->DoZoneInCombat();
    }
};

void AddSC_instance_kings_rest()
{
    RegisterInstanceScript(instance_kings_rest, 1762);
    RegisterCreatureAI(npc_shadow_of_zul);
}
