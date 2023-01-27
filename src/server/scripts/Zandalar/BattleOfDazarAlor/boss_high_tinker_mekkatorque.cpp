#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "VehicleDefines.h"
#include "battle_of_dazaralor.h"

enum Texts
{
    SAY_AGGRO = 0,
    SAY_DEPLOY_SPARK_BOT,
    SAY_BUSTER_CANNON,
    SAY_GIGAVOLT_CHARGE,
    SAY_BLAST_OFF,
    SAY_WORLD_ENLARGER,
    SAY_STAGE_TWO_BEGINS,
    SAY_HYPERDRIVE,
    SAY_STAGE_THREE_BEGINS,
    SAY_KILL,
    SAY_DEATH
};

enum Spells
{
    SPELL_ELECTROSHOCK_STRIKES_DUMMY = 289696,
    SPELL_ELECTROSHOCK_AMPLIFICATION_STACK = 289699,
    SPELL_BUSTER_CANNON_CAST_DUMMY = 287851,
    SPELL_BUSTER_CANNON_DAMAGE = 282182,
    SPELL_BUSTER_CANNON_CREATE_AT = 282153,
    SPELL_HEAVY_THRUSTERS_DUMMY = 284145,
    SPELL_BLAST_OFF = 282205,
    SPELL_CRASH_DOWN = 282245,
    SPELL_CRASH_DOWN_DAMAGE = 283394,
    SPELL_GIGAVOLT_CHARGE = 286646, // 2 tar, on heroic/myth 3
    SPELL_GIGAVOLT_BLAST = 283411,
    SPELL_SHRINK = 284219,
    SPELL_TRAMPLE = 284214,
    SPELL_DEPLOY_SPARK_BOT = 284042, //npc 144942
    SPELL_SPARK_PULSE = 282408,
    SPELL_GNOMISH_FORCE_SHIELD = 282401,
    SPELL_ANTI_TAMPERING_SHOCK = 286480,
    SPELL_SIGNAL_EXPLODING_SHEEP = 287929, //npc 148450
    SPELL_CRITTER_EXPLOSION = 287877,
    SPELL_SHEEP_SHRAPNEL_DAMAGE = 287891,
    SPELL_CRITTER_EXPLOSION_CREATE_AT = 287885,
    SPELL_HYPERDRIVE = 286051,
    //Heroic
    SPELL_WIND_UP = 287293,
    SPELL_WOUND_UP = 287297,
    SPELL_WORMHOLE_GENERATOR_DUMMY_CAST = 287952,
    SPELL_WORMHOLE_GENERATOR_VISUAL = 288232,
    SPELL_WORMHOLE_GENERATOR_TELEPORT = 287226,
};

enum Events
{
    EVENT_ELETROSHOCK_STRIKES = 1,
    EVENT_BUSTER_CANNON,
    EVENT_HEAVY_THRUSTERS,
    EVENT_GIGAVOLT_CHARGE,
    EVENT_SHRINK,
    EVENT_DEPLOY_SPARK_BOT,
    EVENT_SIGNAL_EXPLODING_SHEEP,
    EVENT_HYPERDRIVE,
    EVENT_PHASE_TWO,
    EVENT_PHASE_THREE,
    EVENT_WORLD_ENLARGER,
    //Heroic
    EVENT_WORMHOLE_GENERATOR,
};

const Position gnomish_support_claw_a = { -1588.186f, 789.644f, 126.965f, 0.0f };
const Position gnomish_support_claw_b = { -1605.073f, 788.459f, 126.965f, 0.0f };
const Position gnomish_support_claw_c = { -1605.872f, 816.764f, 126.965f, 0.0f };

//144796
struct boss_high_tinker_mekkatorque : public BossAI
{
    boss_high_tinker_mekkatorque(Creature* creature) : BossAI(creature, DATA_HIGH_TINKER_MEKKATORQUE) { }

private: 
    bool phase1;
    bool phase2;
    bool phase3;

    void Reset() override
    {
        BossAI::Reset();
        DoCastSelf(SPELL_ELECTROSHOCK_STRIKES_DUMMY);
        Vehicle* vehicle = me->GetVehicleKit();
        me->SummonCreature(NPC_HIGH_TINKER_MEKKATORQUE_GNOME, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
        if (auto* highTinker = me->FindNearestCreature(NPC_HIGH_TINKER_MEKKATORQUE_GNOME, 30.0f, true))
        {
            highTinker->SetReactState(REACT_PASSIVE);      
            highTinker->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
            highTinker->EnterVehicle(me);            
        }
        me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        //if (instance->GetBossState(DATA_JADEFIRE_MASTERS_HORDE) != DONE || instance->GetBossState(DATA_OPULENCE))
            //me->setActive(false); ++
    }

    void JustSummoned(Creature* summon) override
    {
    };

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        Talk(SAY_AGGRO);
        phase1 = true;
        events.ScheduleEvent(EVENT_ELETROSHOCK_STRIKES, 2s);
        events.ScheduleEvent(EVENT_BUSTER_CANNON, 13s);
        events.ScheduleEvent(EVENT_GIGAVOLT_CHARGE, 21s);
        events.ScheduleEvent(EVENT_DEPLOY_SPARK_BOT, 31s);
        events.ScheduleEvent(EVENT_SHRINK, 35s);
        events.ScheduleEvent(EVENT_HEAVY_THRUSTERS, 40s);
        events.ScheduleEvent(EVENT_WORLD_ENLARGER, 74s);

        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_WORMHOLE_GENERATOR, 37s);

        if (auto* encounterDoor = me->FindNearestGameObject(GO_MEKKATORQUE_WALL_OF_SPEARS_ENTRANCE, 125.0f))
            encounterDoor->SetGoState(GO_STATE_READY);

        if (auto* encounterDoor = me->FindNearestGameObject(GO_MEKKATORQUE_WALL_OF_SPEARS_EXIT, 125.0f))
            encounterDoor->SetGoState(GO_STATE_READY);
    }

    void DamageTaken(Unit* unit, uint32& damage) override
    {
        if (me->HealthBelowPct(41) && phase1)
        {
            phase1 = false;

            phase2 = true;

            if (phase2)
            {
                events.ScheduleEvent(EVENT_PHASE_TWO, 1s);
                events.ScheduleEvent(EVENT_PHASE_THREE, 66s);
                events.ScheduleEvent(EVENT_HYPERDRIVE, 66s);
            }
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            if (roll_chance_i(15))
                Talk(SAY_KILL);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_ELETROSHOCK_STRIKES:
            me->AddAura(SPELL_ELECTROSHOCK_AMPLIFICATION_STACK);
            events.Repeat(2s);
            break;

        case EVENT_BUSTER_CANNON:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                Talk(SAY_BUSTER_CANNON);
                me->CastSpell(nullptr, SPELL_BUSTER_CANNON_CAST_DUMMY);
                me->GetScheduler().Schedule(1s, [this, target] (TaskContext context)
                {
                    me->CastSpell(nullptr, SPELL_BUSTER_CANNON_CREATE_AT, true);
                });
            }
            events.Repeat(20s);
            break;

        case EVENT_HEAVY_THRUSTERS:
            Talk(SAY_BLAST_OFF);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {                
                me->CastSpell(target->GetPosition(), SPELL_BLAST_OFF, false);
                me->GetScheduler().Schedule(3600ms, [this, target](TaskContext context)
                {
                    me->CastSpell(target->GetPosition(), SPELL_CRASH_DOWN_DAMAGE);
                });
            }
            events.Repeat(30s);
            break;

        case EVENT_GIGAVOLT_CHARGE:
        {
            Talk(SAY_GIGAVOLT_CHARGE);
            if (!IsHeroic() || !IsMythic())
            {
                UnitList tarlist;
                SelectTargetList(tarlist, 2, SELECT_TARGET_RANDOM, 100.0f, true);
                for (Unit* target : tarlist)
                me->CastSpell(target, SPELL_GIGAVOLT_CHARGE, true);
            }
            else
            {
                UnitList tarlist;
                SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 100.0f, true);
                for (Unit* target : tarlist)
                me->CastSpell(target, SPELL_GIGAVOLT_CHARGE, true);
            }
            events.Repeat(40s);
            break;
        }

        case EVENT_SHRINK:
        {
            UnitList tarlist;
            SelectTargetList(tarlist, 3, SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* target : tarlist)
            me->CastSpell(target, EVENT_SHRINK, false);
            events.Repeat(50s);
            break;
        }

        case EVENT_DEPLOY_SPARK_BOT:
            Talk(SAY_DEPLOY_SPARK_BOT);
            me->SummonCreature(NPC_GNOMISH_SUPPORT_CLAW, gnomish_support_claw_a, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_GNOMISH_SUPPORT_CLAW, gnomish_support_claw_b, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_GNOMISH_SUPPORT_CLAW, gnomish_support_claw_c, TEMPSUMMON_MANUAL_DESPAWN);
            events.Repeat(60s);
            break;

        case EVENT_SIGNAL_EXPLODING_SHEEP:
            DoCast(SPELL_SIGNAL_EXPLODING_SHEEP);
            for (uint8 i = 0; i < 7; i++)
            {
                me->SummonCreature(NPC_EXPLODING_SHEEP, me->GetRandomPoint(me->GetPosition(), 30.0f));
            }
            break;

        case EVENT_HYPERDRIVE:
            //Talk(SAY_HYPERDRIVE);
            me->AddAura(SPELL_HYPERDRIVE);
            break;

        case EVENT_PHASE_TWO:
            Talk(SAY_STAGE_TWO_BEGINS);            
            events.ScheduleEvent(EVENT_SIGNAL_EXPLODING_SHEEP, 3s);
            break;

        case EVENT_PHASE_THREE:
            Talk(SAY_STAGE_THREE_BEGINS);
            break;

        case EVENT_WORMHOLE_GENERATOR:
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->CastSpell(target, SPELL_WORMHOLE_GENERATOR_VISUAL, true);
                me->CastSpell(nullptr, SPELL_WORMHOLE_GENERATOR_DUMMY_CAST, false);                
                me->GetScheduler().Schedule(5s, [this, target] (TaskContext context)
                {
                    std::list<Player*> pl_li;
                    me->GetPlayerListInGrid(pl_li, 300.0f);
                    for (auto& players : pl_li)
                    {
                        if (!players->HasAura(SPELL_WORMHOLE_GENERATOR_VISUAL))
                            players->CastSpell(target, SPELL_WORMHOLE_GENERATOR_TELEPORT, true);
                    }
                });
            }
            events.Repeat(70s);
            break;
        }    
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();        
        me->RemoveAllAreaTriggers();
        me->DespawnCreaturesInArea(NPC_SPARK_BOT, 125.0f);
        me->DespawnCreaturesInArea(NPC_GNOMISH_SUPPORT_CLAW, 125.0f);
        if (auto* encounterDoor = me->FindNearestGameObject(GO_MEKKATORQUE_WALL_OF_SPEARS_ENTRANCE, 125.0f))
            encounterDoor->SetGoState(GO_STATE_ACTIVE);

        if (auto* encounterDoor = me->FindNearestGameObject(GO_MEKKATORQUE_WALL_OF_SPEARS_EXIT, 125.0f))
            encounterDoor->SetGoState(GO_STATE_ACTIVE);
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*who*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        _JustReachedHome();
        me->RemoveAllAreaTriggers();
        me->DespawnCreaturesInArea(NPC_SPARK_BOT, 125.0f);
        me->DespawnCreaturesInArea(NPC_GNOMISH_SUPPORT_CLAW, 125.0f);
        if (auto* encounterDoor = me->FindNearestGameObject(GO_MEKKATORQUE_WALL_OF_SPEARS_ENTRANCE, 125.0f))
            encounterDoor->SetGoState(GO_STATE_ACTIVE);

        if (auto* encounterDoor = me->FindNearestGameObject(GO_MEKKATORQUE_WALL_OF_SPEARS_EXIT, 125.0f))
            encounterDoor->SetGoState(GO_STATE_ACTIVE);

        if (me->GetMap()->IsMythic())
            instance->DoCompleteAchievement(13312);

        if (GameObject* rawani_collision_horde_only_1 = instance->GetGameObject(GO_RAWANI_COLLISION_HORDE_ONLY_1))
            rawani_collision_horde_only_1->RemoveFromWorld();

        if (GameObject* rawani_collision_horde_only_2 = instance->GetGameObject(GO_RAWANI_COLLISION_HORDE_ONLY_2))
            rawani_collision_horde_only_2->RemoveFromWorld();

        if (Creature* laminaria = instance->GetCreature(NPC_LAMINARIA))
            laminaria->SetVisible(true);
    }
};

//145924
struct npc_gnomish_support_claw : public ScriptedAI
{
    npc_gnomish_support_claw(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        me->CanFly();
        me->SetFlying(true);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->SummonCreature(NPC_SPARK_BOT, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
        me->DespawnOrUnsummon(3s);
    }
};

enum
{
    EVENT_SPARK_PULSE = 1,
};

//144942
struct npc_spark_bot : public ScriptedAI
{
    npc_spark_bot(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        me->CastSpell(nullptr, SPELL_GNOMISH_FORCE_SHIELD, true);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->GetScheduler().Schedule(2s, [this](TaskContext context)
        {
            me->AI()->DoZoneInCombat(nullptr);
        });
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_SPARK_PULSE, 3s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_SPARK_PULSE:
            DoCastSelf(SPELL_SPARK_PULSE);
            events.Repeat(15s);
            break;
        }
    }
};

//148450
struct npc_explosive_sheep : public ScriptedAI
{
    npc_explosive_sheep(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(nullptr, SPELL_CRITTER_EXPLOSION, false);
    }

    void JustDied(Unit* /*target*/) override
    {
        for (uint8 i = 0; i < 5; i++)
        {
            me->CastSpell(me->GetHomePosition(), SPELL_CRITTER_EXPLOSION_CREATE_AT, true);
        }
    }
};

//286646 - Gigavolt charge
class aura_gigavolt_charge : public AuraScript
{
    PrepareAuraScript(aura_gigavolt_charge);

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_GIGAVOLT_BLAST, true);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_gigavolt_charge::HandleRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

//19687
struct at_buster_cannon : public AreaTriggerAI
{
    at_buster_cannon(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnInitialize() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Position pos = caster->GetPosition();

        at->MovePosition(pos, 15.0f, 0.0f);
        at->SetDestination(pos, 3000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer())
            at->GetCaster()->CastSpell(unit, SPELL_BUSTER_CANNON_DAMAGE);
    }
};

//20250, 287885
struct at_sheep_shrapnel : public AreaTriggerAI
{
    at_sheep_shrapnel(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnInitialize() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Position randomPos = at->GetRandomNearPosition(30.0f);
        at->MovePosition(randomPos, 25.0f, 0.0f);
        at->SetDestination(randomPos, 5000);
    }

    void OnDestinationReached() override
    {
        Position randomPos = at->GetRandomNearPosition(30.0f);
        at->MovePosition(randomPos, 25.0f, 0.0f);
        at->SetDestination(randomPos, 5000);
    }
};

void AddSC_boss_high_tinker_mekkatorque()
{
    RegisterCreatureAI(boss_high_tinker_mekkatorque);
    RegisterCreatureAI(npc_gnomish_support_claw);
    RegisterCreatureAI(npc_spark_bot);
    RegisterAuraScript(aura_gigavolt_charge);
    RegisterAreaTriggerAI(at_buster_cannon);
    RegisterCreatureAI(npc_explosive_sheep);
    RegisterAreaTriggerAI(at_sheep_shrapnel);
}
