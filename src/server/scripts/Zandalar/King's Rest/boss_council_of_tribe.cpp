#include "GameObject.h"
#include "GameObjectAI.h"
#include "kings_rest.h"

enum Spells
{
    SPELL_SEVERING_AXE = 266231,
    SPEL_WHIRLING_AXES = 266206,
    SPELL_DEBILATING_BACKHAND = 266237,
    SPELL_BARREL_THROUGH = 266951,
    SPELL_BARREL_THROUGH_CHARGE = 266941,
    SPELL_BARREL_THROUGH_AOE = 266940,
    SPELL_LIGHTNING_BOLT = 267308,
    SPELL_POISON_NOVA = 267273,
    SPELL_CALL_OF_THE_ELEMENTS = 267060,
};

enum Events
{
    EVENT_SEVERING_AXE = 1,
    EVENT_WHIRLING_AXES,
    EVENT_DEBILATING_BACKHAND,
    EVENT_BARREL_THROUGH,
    EVENT_LIGHTNING_BOLT,
    EVENT_POISON_NOVA,
    EVENT_CALL_OF_THE_ELEMENTS
};

const Position middle_pos = { -1101.0f, 2911.0f, 775.560f, 3.11f };
const Position akali_pos = { -1122.0f, 2931.0f, 775.560f, 5.29f };
const Position zanazal_pos = { -1135.0f, 2911.0f, 775.577f, 0.0f };

//135475,135470,135472
struct boss_council_tribes : public BossAI
{
    boss_council_tribes(Creature* creature) : BossAI(creature, DATA_COUNCIL) { }

    void Reset() override
    {
        BossAI::Reset();
        switch (me->GetEntry())
        {
        case NPC_KULA_THE_BUTCHER:
             me->DespawnCreaturesInArea(NPC_AKALI_THE_CONQUEROR, 125.0f);
             me->DespawnCreaturesInArea(NPC_ZANAZAL_THE_WISE, 125.0f);
             break;
        }
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->AI()->DoZoneInCombat();
    }

    void JustReachedHome() override
    {
        switch (me->GetEntry())
        {
        case NPC_AKALI_THE_CONQUEROR:             
             if (!me->FindNearestCreature(NPC_KULA_THE_BUTCHER, 300.0f, true))
             {
                 if (Creature* kula = instance->GetCreature(NPC_KULA_THE_BUTCHER))
                 {
                     if (kula->isDead())
                     {
                         kula->Respawn();
                         kula->NearTeleportTo(kula->GetHomePosition());
                     }
                 }
             }
             me->DespawnOrUnsummon();
             break;

        case NPC_ZANAZAL_THE_WISE:
            if (!me->FindNearestCreature(NPC_KULA_THE_BUTCHER, 300.0f, true))
            {
                if (Creature* kula = instance->GetCreature(NPC_KULA_THE_BUTCHER))
                {
                    if (kula->isDead())
                    {
                        kula->Respawn();
                        kula->NearTeleportTo(kula->GetHomePosition());
                    }
                }
            }
            me->DespawnOrUnsummon();
             break;
        }
    }

    void JustDied(Unit* u) override
    {
        switch (me->GetEntry())
        {
        case NPC_KULA_THE_BUTCHER:
            _JustDied();
            me->SummonCreature(NPC_AKALI_THE_CONQUEROR, akali_pos, TEMPSUMMON_MANUAL_DESPAWN);
            break;

        case NPC_AKALI_THE_CONQUEROR:
            _JustDied();
            me->SummonCreature(NPC_ZANAZAL_THE_WISE, zanazal_pos, TEMPSUMMON_MANUAL_DESPAWN);
            break;

        case NPC_ZANAZAL_THE_WISE:
            _JustDied();
            if (GameObject* go = me->FindNearestGameObject(GO_THE_COUNCILS_CACHE, 300.0f))
            {
                go->RemoveFlag(GO_FLAG_LOCKED);
            }
            break;
        }
    }

    void EnterCombat(Unit* u) override
    {
        switch (me->GetEntry())
        {
        case NPC_KULA_THE_BUTCHER:
             _EnterCombat();
             events.ScheduleEvent(EVENT_SEVERING_AXE, 5s);
             events.ScheduleEvent(EVENT_WHIRLING_AXES, 10s);
             break;

        case NPC_AKALI_THE_CONQUEROR:
             _EnterCombat();
             events.ScheduleEvent(EVENT_DEBILATING_BACKHAND, 5s);
             events.ScheduleEvent(EVENT_BARREL_THROUGH, 10s);
             break;

        case NPC_ZANAZAL_THE_WISE:
             _EnterCombat();
             events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 5s);
             events.ScheduleEvent(EVENT_POISON_NOVA, 10s);
             events.ScheduleEvent(EVENT_CALL_OF_THE_ELEMENTS, 15s);
             break;
        } 
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_SEVERING_AXE:
             DoCastRandom(SPELL_SEVERING_AXE, 100.0f);
             events.Repeat(15s);
             break;

        case EVENT_WHIRLING_AXES:
             DoCastAOE(SPEL_WHIRLING_AXES);
             events.Repeat(20s);
             break;

        case EVENT_DEBILATING_BACKHAND:
             DoCastVictim(SPELL_DEBILATING_BACKHAND);
             events.Repeat(15s);
             break;

        case EVENT_BARREL_THROUGH:
             if (Unit* tar = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
             {
                DoCast(tar, SPELL_BARREL_THROUGH);
                me->GetScheduler().Schedule(8s, [this, tar] (TaskContext context)
                {
                    DoCast(tar, SPELL_BARREL_THROUGH_CHARGE);
                });
                me->GetScheduler().Schedule(10s, [this] (TaskContext context)
                {
                    DoCastAOE(SPELL_BARREL_THROUGH_AOE);
                });
             }
             events.Repeat(20s);
             break;

        case EVENT_LIGHTNING_BOLT:
             DoCastVictim(SPELL_LIGHTNING_BOLT);
             events.Repeat(3s);
             break;

        case EVENT_POISON_NOVA:
             DoCastAOE(SPELL_POISON_NOVA);
             events.Repeat(20s);
             break;

        case EVENT_CALL_OF_THE_ELEMENTS:
             DoCast(SPELL_CALL_OF_THE_ELEMENTS);
             auto* explosive = DoSummon(NPC_EXPLOSIVE_TOTEM, me->GetRandomPoint(middle_pos, 30.0f));
             auto* thunder = DoSummon(NPC_THUNDERING_TOTEM, me->GetRandomPoint(middle_pos,30.0f));
             auto* torrent = DoSummon(NPC_TORRENT_TOTEM, me->GetRandomPoint(middle_pos, 30.0f));
             auto* earthwall = DoSummon(NPC_EARTHWALL_TOTEM, me->GetRandomPoint(middle_pos, 30.0f));
             events.Repeat(30s);
             break;
        }
    }
};

enum TotemSpells
{
    SPELL_EXPLODE = 267077,
    SPELL_THUNDERING_CRASH = 267257,
    SPELL_TORRENT = 267105,
};

//135764,135761,135765,135759
struct npc_zanazal_totem : public ScriptedAI
{
    npc_zanazal_totem(Creature* c) : ScriptedAI(c) { }

    void AttackStart(Unit* u) override
    {
        me->SetWalk(false);
        if (me->Attack(u, true))
            DoStartMovement(u);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->SetReactState(REACT_PASSIVE);
        switch (me->GetEntry())
        {
        case NPC_EXPLOSIVE_TOTEM:
             DoCastAOE(SPELL_EXPLODE);
             break;

        case NPC_THUNDERING_TOTEM:
             DoCastAOE(SPELL_THUNDERING_CRASH);
             break;

        case NPC_TORRENT_TOTEM:            
             break;

        case NPC_EARTHWALL_TOTEM:             
             break;
        }
    }
};

void AddSC_boss_council_of_tribes()
{
    RegisterCreatureAI(boss_council_tribes);
    RegisterCreatureAI(npc_zanazal_totem);
}
