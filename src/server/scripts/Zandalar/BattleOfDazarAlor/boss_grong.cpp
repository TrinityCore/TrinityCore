#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedGossip.h"
#include "PhasingHandler.h"
#include "battle_of_dazaralor.h"

const Position apetagonizer_3000_pos = { -907.793f, 919.714f, 386.374f, 0.08f };

enum Spells
{
    PERIODIC_ENERGY_GAIN = 299956,
    TANTRUM = 281936,
    REVERBERATING_SLAM = 282179,
    FEROCIOUS_ROAR = 290574,
    FEROCIOUS_ROAR_FEAR = 290575,
    BESTIAL_COMBO = 282082,
    BESTIAL_SMASH = 283078,
    BESTIAL_IMPACT = 289412,
    BESTIAL_THROW = 289292,
    BESTIAL_THROW_JUMP = 289406,
    RENDERING_BITE_CAST = 285874,
    RENDERING_BITE = 285875,
    MEGATOMIC_SEEKER_MISSILE = 282213,
    MEGATOMIC_SEEKER_MISSILE_CREATE_AT = 282215,
    MEGATOMIC_AT_PERIODIC_DAMAGE = 283069,
    SHATTERED = 282010,
    //Adds
    PARACHUTE = 55001,
    APETAGONIZE = 282243,
    APETAGONIZE_CORE_MISSILE = 285661,
    APETAGONIZE_CORE_BUFF = 285659,
    DISCHARGE_APETAGONIZE_CORE = 285660,
    LIGHTNING_DETONATION = 285654,
};

enum Events
{
    EVENT_TANTRUM = 1,
    EVENT_REVERBERATING_SLAM,
    EVENT_FEROCIOUS_ROAR,
    EVENT_BESTIAL_COMBO,
    EVENT_APETAGONIZER,
    EVENT_MEGATOMIC,
    EVENT_APETAGONIZE,
};

//144637
struct boss_grong : public BossAI
{
    boss_grong(Creature* creature) : BossAI(creature, DATA_GRONG) { }

private:
    bool intro;

    void Reset() override
    {
        BossAI::Reset();
        me->RemoveAura(PERIODIC_ENERGY_GAIN);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);
        Vehicle* vehicle = me->GetVehicleKit();
        intro = false;
        me->RemoveAllAreaTriggers();
        if (me->GetAreaId() == 10373)
            me->SetDisplayId(89250, 1.0f);
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->GetDistance2d(me) < 53.0f && !intro && unit->IsPlayer())
        {
            intro = true;
            std::list<Creature*> grunts_li;
            me->GetCreatureListWithEntryInGrid(grunts_li, NPC_HONORBOUND_GRUNT, 25.0f);
            for (auto& grunts : grunts_li)
            {
                me->Kill(grunts);
            }
        }
    }

    void EnterCombat(Unit* /*unit*/) override
    {
        _EnterCombat();    
        DoCast(PERIODIC_ENERGY_GAIN);
        events.ScheduleEvent(EVENT_REVERBERATING_SLAM, 3s);
        events.ScheduleEvent(EVENT_BESTIAL_COMBO, 11s);
        events.ScheduleEvent(EVENT_MEGATOMIC, 25s);
        events.ScheduleEvent(EVENT_APETAGONIZER, 30s);
        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_FEROCIOUS_ROAR, 8s);

        if (auto* encounterDoor = me->FindNearestGameObject(GO_WALL_OF_SPEARS_GRONG, 100.0f))
            encounterDoor->SetGoState(GO_STATE_READY);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        _DespawnAtEvade();
        me->RemoveAllAreaTriggers();
        me->DespawnCreaturesInArea(NPC_APETAGONIZER_3000);
        me->DespawnCreaturesInArea(NPC_APETAGONIZE_CORE);

        if (auto* encounterDoor = me->FindNearestGameObject(GO_WALL_OF_SPEARS_GRONG, 100.0f))
            encounterDoor->SetGoState(GO_STATE_ACTIVE);
    }

    void JustDied(Unit* /*unit*/) override
    {
        _JustDied();
        me->RemoveAllAreaTriggers();
        me->DespawnCreaturesInArea(NPC_APETAGONIZER_3000);
        me->DespawnCreaturesInArea(NPC_APETAGONIZE_CORE);

        if (auto* expedition_strongbox = me->FindNearestGameObject(GO_EXPEDITION_STRONGBOX_GRONG, 100.0f))
            expedition_strongbox->RemoveFlag(GO_FLAG_LOCKED);

        if (IsMythic())
            instance->DoCompleteAchievement(13293); //Mythic: Grong

        if (Creature* bwonsamdi = me->SummonCreature(NPC_BWONSAMDI, -869.123f, 910.124f, 339.803f, 2.503f, TEMPSUMMON_TIMED_DESPAWN, 30000))
        {
            bwonsamdi->CastSpell(nullptr, 243010, true);
            bwonsamdi->AI()->Talk(0);
            bwonsamdi->GetScheduler().Schedule(10s, [this, bwonsamdi] (TaskContext context)
            {
                bwonsamdi->AI()->Talk(1);
            });
        }

        if (auto* encounterDoor = me->FindNearestGameObject(GO_WALL_OF_SPEARS_GRONG, 100.0f))
            encounterDoor->SetGoState(GO_STATE_ACTIVE);
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == LIGHTNING_DETONATION)
            me->ModifyPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 50);

        if (spell->Id == DISCHARGE_APETAGONIZE_CORE)
            DoCastAOE(TANTRUM);
    }

    void OnSpellFinished(SpellInfo const* spellInfo)
    {
        if (spellInfo->Id == FEROCIOUS_ROAR)
        {
            std::list<Player*> pl_li;
            me->GetPlayerListInGrid(pl_li, 80.0f);
            for (auto& players : pl_li)
            {
                if (!players->SelectNearestPlayer(5.0f))               
                    me->AddAura(FEROCIOUS_ROAR_FEAR, players);
            }
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->GetPowerPct(POWER_ENERGY) == 100)
        {
            me->ModifyPower(POWER_ENERGY, -25);
            events.ScheduleEvent(EVENT_TANTRUM, 100ms);
            std::list<Player*> pl_li;
            me->GetPlayerListInGrid(pl_li, 100.0f);
            for (auto& targets : pl_li)
            me->GetScheduler().Schedule(1s, [this, pl_li, targets] (TaskContext context)
            {
                me->ModifyPower(POWER_ENERGY, -25);
                me->AddAura(SHATTERED, targets);

            }).Schedule(2s, [this, pl_li, targets] (TaskContext context)
            {
                me->ModifyPower(POWER_ENERGY, -25);
                me->AddAura(SHATTERED, targets);

            }).Schedule(3s, [this, pl_li, targets] (TaskContext context)
            {
                me->ModifyPower(POWER_ENERGY, -25);
                me->AddAura(SHATTERED, targets);
            });
        }
        switch (eventId)
        {
        case EVENT_TANTRUM:
        {
            me->StopMoving();
            DoCastAOE(TANTRUM);
            break;
        }
        case EVENT_REVERBERATING_SLAM:
        {
            me->StopMoving();
            DoCastAOE(REVERBERATING_SLAM);
            events.Repeat(20s);
            break;
        }
        case EVENT_MEGATOMIC:
        {
            if (Creature* ape = me->FindNearestCreature(NPC_FLYING_APE, 100.0f, true))
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                {
                    ape->CastSpell(target, MEGATOMIC_SEEKER_MISSILE, true);
                }
            }
            events.Repeat(25s);
            break;
        }
        case EVENT_BESTIAL_COMBO:
        {
            uint32 chooseSpell = urand(0, 2);

            switch (chooseSpell)
            {
            case 0: //Throw
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 10.0f, true))
                {
                    target->EnterVehicle(me);                    
                    me->CastSpell(target, BESTIAL_THROW, false);
                    me->GetScheduler().Schedule(5s, [target, this] (TaskContext context)
                    {
                        target->ExitVehicle();
                        if (Unit* target_throw = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                        {
                            target->CastSpell(target_throw, BESTIAL_THROW_JUMP, true);
                            me->GetScheduler().Schedule(1s, [target, this, target_throw] (TaskContext context)
                            {
                                me->CastSpell(target_throw, BESTIAL_IMPACT, true);
                            });
                        }
                    });
                }
                break;

            case 1://Bite
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 10.0f, true))
                {
                    me->CastSpell(nullptr, RENDERING_BITE_CAST, false);
                    me->GetScheduler().Schedule(3100ms, [this, target](TaskContext context)
                    {
                        me->CastSpell(target, RENDERING_BITE, true);
                    }).Schedule(6200ms, [this, target](TaskContext context)
                    {
                        me->CastSpell(nullptr, RENDERING_BITE_CAST, false);
                    }).Schedule(9300ms, [this, target](TaskContext context)
                    {
                        me->CastSpell(nullptr, RENDERING_BITE_CAST, true);
                    });
                }
                break;

            case 2:
                //Smash
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 10.0f, true))
                {
                    me->CastSpell(target, BESTIAL_SMASH, false);
                }
                break;
            }
            events.Repeat(25s);
            break;
        }
        case EVENT_APETAGONIZER:
        {
            me->SummonCreature(NPC_APETAGONIZER_3000, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
            events.Repeat(45s);
            break;
        }
        case EVENT_FEROCIOUS_ROAR:
        {
            me->StopMoving();
            DoCastAOE(FEROCIOUS_ROAR);
            events.Repeat(30s, 45s);
            break;
        }
        }
    }
};

//149611
struct npc_apetagonizer_3000 : public ScriptedAI
{
    npc_apetagonizer_3000(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->UpdatePosition(me->GetPositionX()+ 0.0f, me->GetPositionY() + 0.0f, me->GetPositionZ() + 20.0f, me->GetOrientation());
    }

    void IsSummonedBy(Unit* summoner) override
    {        
        me->AddAura(PARACHUTE);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_APETAGONIZE, 5s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (me->HasAura(PARACHUTE) && me->GetPositionZ() <= 341.0f)
        {
            me->RemoveAura(PARACHUTE);
            Talk(0);            
        }

        switch (eventId)
        {
        case EVENT_APETAGONIZE:
            if (Creature* grong = me->FindNearestCreature(NPC_GRONG, 100.0f, true))
            {
                if (grong->IsAlive())
                {
                    std::list<Creature*> c_li;
                    me->GetCreatureListWithEntryInGrid(c_li, NPC_GRONG, 100.0f);
                    for (auto & grong : c_li)
                    {                        
                        me->AI()->DoCast(grong, APETAGONIZE);
                    }
                }
            }
            events.Repeat(5s);
            break;

        default:
            break;
        }
    }

    void OnSpellCastInterrupt(SpellInfo const* spell) override
    {
        if (spell->Id == APETAGONIZE)
        {
            if (Creature* grong = me->FindNearestCreature(NPC_GRONG, 100.0f, true))
            {
                if (grong->IsAlive())
                {
                    grong->ModifyPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 10);
                }
            }
        }
    }

    void JustDied(Unit* u) override
    {
        Talk(1);
        DoCastAOE(LIGHTNING_DETONATION);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->SummonCreature(NPC_APETAGONIZE_CORE, me->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
    }
};

//500501
struct npc_apetagonize_core : public ScriptedAI
{
    npc_apetagonize_core(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
    }

    void sGossipHello(Player* player) override
    { 
        CloseGossipMenuFor(player);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
        player->AddAura(APETAGONIZE_CORE_BUFF);
        me->DespawnOrUnsummon();
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(me, APETAGONIZE_CORE_MISSILE);
    }
};

//19750
struct at_megatomic : public AreaTriggerAI
{
    at_megatomic(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer() && !unit->HasAura(MEGATOMIC_AT_PERIODIC_DAMAGE))
            at->GetCaster()->AddAura(MEGATOMIC_AT_PERIODIC_DAMAGE, unit);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->IsPlayer() && unit->HasAura(MEGATOMIC_AT_PERIODIC_DAMAGE))
            unit->RemoveAura(MEGATOMIC_AT_PERIODIC_DAMAGE);
    }
};

void AddSC_boss_grong()
{
    RegisterCreatureAI(boss_grong);
    RegisterCreatureAI(npc_apetagonizer_3000);
    RegisterCreatureAI(npc_apetagonize_core);
    RegisterAreaTriggerAI(at_megatomic);
}
