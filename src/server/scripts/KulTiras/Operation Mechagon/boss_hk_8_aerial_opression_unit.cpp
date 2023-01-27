#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Vehicle.h"
#include "InstanceScript.h"
#include "operation_mechagon.h"

enum Texts
{
    SAY_HK_AGGRO = 0,
    SAY_CANNON_BLAST,
    SAY_REINFORCEMENTS,
    SAY_STAGE_TWO,
    SAY_DEATH
};

enum Spells
{
    //HK8
    SPELL_CANNON_BLAST_TRIGGER = 295536,
    SPELL_CANNON_BLAST_MISSILE = 302098,
    SPELL_REINFORCEMENT_RELAY_TRIGGER_SUMMON = 301351,
    SPELL_ANNIHILATION_RAY_CHANNEL = 295939,
    SPELL_ANNIHILATION_BLAST = 303206,
    SPELL_HAYWIRE = 296080,
    SPELL_LIFT_OFF = 301177,
    SPELL_FORCE_SHIELD = 300011,

    //Overcharge Station
    SPELL_HACK = 296260,

    //Walkie Shockie X1
    SPELL_AREA_DENIAL_BOT = 296517,
    SPELL_STATIC_DISCHARGE = 302384,
    SPELL_STATIC_DISCHARGE_CREATE_AT = 296518,
    SPELL_CLINGING_STATIC_DAMAGE = 296560,
    SPELL_SELF_DESTRUCT = 296522,
};

const Position boss_hk_default_encounter_pos = { 632.534f, -43.874f, 92.058f, 5.39f };
const Position mk1_spawn_pos = { 607.170f, -20.907f, 71.112f, 5.478f };
const Position annhilation_pos = { 615.586f, -22.346f, 87.0f, 5.43f };

//150190
struct boss_hk_8 : public BossAI
{
    boss_hk_8(Creature* creature) : BossAI(creature, DATA_HK8) { }

    void Reset() override
    {
        BossAI::Reset();
        me->SetCanFly(true);
        me->SetFlying(true);
        flight_to_encounter = false;
        hk_vulnerable = false;
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE || point != 1)
            return;

        if (point == 1 && flight_to_encounter)
        {
            me->SummonCreature(NPC_TANK_BUSTER_MK1, mk1_spawn_pos, TEMPSUMMON_MANUAL_DESPAWN);
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {

    }

    void JustDied(Unit* /*killer*/) override
    {        
        _JustDied();
        Talk(SAY_DEATH);
        instance->DoModifyPlayerCurrencies(1553, 35);
    }

private:
    bool flight_to_encounter;
    bool hk_vulnerable;
};

enum MK1
{
    SPELL_WRECK = 302279,
    SPELLW_WRECK_DAMAGE = 295445,
    SPELL_FULMINATING_ZAP = 302274,
    EVENT_WRECK = 1,
    EVENT_ZAP,
    EVENT_REINFORCEMENTS,
    EVENT_CANNON_BLAST,
    EVENT_ANNIHILATION_EXPLOSION
};

//150295
struct npc_tank_buster_mk1 : public ScriptedAI
{
    npc_tank_buster_mk1(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        init_stage_two = false;        
    }

    void EnterCombat(Unit* who) override
    {
        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_WRECK, 3s);
        events.ScheduleEvent(EVENT_ZAP, 8s);
        events.ScheduleEvent(EVENT_REINFORCEMENTS, 13s);
        events.ScheduleEvent(EVENT_CANNON_BLAST, 19s);
        if (Creature* hk8 = me->FindNearestCreature(NPC_HK_8_AERIAL_OPPRESION_UNIT, 100.0f, true))
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, hk8);
            hk8->AI()->Talk(SAY_HK_AGGRO);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnOrUnsummon();
        std::list<Creature*> encounter_list;
        encounter_list.clear();
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_HK_8_AERIAL_OPPRESION_UNIT, 300.0f);
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_TANK_BUSTER_MK1, 300.0f);
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_TANK_BUSTER_MK2, 300.0f);
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_WALKIE_SHOCKIE_X1, 300.0f);        
        for (auto& encounterNPCs : encounter_list)
        {
            if (encounterNPCs->isDead())
                encounterNPCs->Respawn();

            encounterNPCs->AI()->JustReachedHome();
            encounterNPCs->NearTeleportTo(me->GetHomePosition());
            encounterNPCs->DespawnOrUnsummon();
        }
    }

    void DamageTaken(Unit* u, uint32& dmg)
    {
        if (me->HealthBelowPct(2) && !init_stage_two)
        {
            events.CancelEvent(EVENT_CANNON_BLAST);
            events.CancelEvent(EVENT_REINFORCEMENTS);
            init_stage_two = true;
            me->AttackStop();
            me->SetReactState(REACT_PASSIVE);
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            me->SetHealth(me->GetMaxHealth());
            me->SetFaction(35);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->DespawnOrUnsummon(3s);
            if (Creature* hk8 = me->FindNearestCreature(NPC_HK_8_AERIAL_OPPRESION_UNIT, 100.0f, true))
            {                
                hk8->AI()->Talk(SAY_STAGE_TWO);
                hk8->SetInCombatWithZone();
                hk8->SetReactState(REACT_PASSIVE);
                if (Creature* center_stalker = me->FindNearestCreature(NPC_HK8_CENTER_ARENA_STALKER, 100.0f, true))
                {
                    hk8->NearTeleportTo(annhilation_pos, false);
                    hk8->CastSpell(center_stalker, SPELL_ANNIHILATION_RAY_CHANNEL, false);
                    events.ScheduleEvent(EVENT_ANNIHILATION_EXPLOSION, 3min);
                }
                if (Creature* station = me->FindNearestCreature(NPC_OVERCHARGE_STATION, 250.0f, true))
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, station);
                    station->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                }
            }
        }
    }

    void ExecuteEvent(uint32 eventid) override
    {
        switch (eventid)
        {
        case EVENT_WRECK:
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                DoCast(target, SPELL_WRECK, false);
                me->GetScheduler().Schedule(2900ms, [target, this] (TaskContext context)
                {
                    DoCast(target, SPELLW_WRECK_DAMAGE, false);
                });
            }
            events.Repeat(3s);
            break;

        case EVENT_ZAP:
            DoCastRandom(SPELL_FULMINATING_ZAP, false);
            events.Repeat(15s);
            break;

        case EVENT_REINFORCEMENTS:
            if (Creature* center_stalker = me->FindNearestCreature(NPC_HK8_CENTER_ARENA_STALKER, 100.0f, true))
            {
                if (Creature* hk8 = me->FindNearestCreature(NPC_HK_8_AERIAL_OPPRESION_UNIT, 100.0f, true))
                {
                    hk8->AI()->Talk(SAY_REINFORCEMENTS);
                    me->CastSpell(center_stalker, SPELL_REINFORCEMENT_RELAY_TRIGGER_SUMMON, false);
                }
            }
            events.Repeat(30s);
            break;

        case EVENT_CANNON_BLAST:
            if (Creature* hk8 = me->FindNearestCreature(NPC_HK_8_AERIAL_OPPRESION_UNIT, 100.0f, true))
            {
                if (Creature* center_stalker = me->FindNearestCreature(NPC_HK8_CENTER_ARENA_STALKER, 100.0f, true))
                {
                    hk8->AI()->Talk(SAY_CANNON_BLAST);
                    hk8->AI()->DoCast(SPELL_CANNON_BLAST_TRIGGER);
                    me->GetScheduler().Schedule(3s, [hk8, this] (TaskContext context)
                    {
                        std::list<Player*> target_list;
                        target_list.clear();
                        me->GetPlayerListInGrid(target_list, 300.0f);
                        for (auto& targets : target_list)                        
                            hk8->CastSpell(targets, SPELL_CANNON_BLAST_MISSILE);
                    });
                }
            }
            events.Repeat(35s);
            break;

        case EVENT_ANNIHILATION_EXPLOSION:
            if (Creature* hk8 = me->FindNearestCreature(NPC_HK_8_AERIAL_OPPRESION_UNIT, 200.0f, true))
            {
                hk8->AI()->DoCastAOE(SPELL_ANNIHILATION_BLAST, false);
            }
            break;
        }
    }
private:
    bool init_stage_two;
    uint8 encountered;
};

//163746
struct npc_walkie_shockie_x1 : public ScriptedAI
{
    npc_walkie_shockie_x1(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetWalk(true);
        me->SetPower(POWER_ENERGY, 100);
        DoCastSelf(SPELL_AREA_DENIAL_BOT);
        me->GetScheduler().Schedule(10s, [this] (TaskContext context)
        {                
            DoCastAOE(SPELL_SELF_DESTRUCT);
        });
    }

    void IsSummonedBy(Unit* unit) override
    {
        me->GetScheduler().Schedule(1500ms, [this] (TaskContext context)
        {
            me->AI()->DoZoneInCombat(nullptr);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

//152138
struct npc_overcharge_station : public ScriptedAI
{
    npc_overcharge_station(Creature* creature) : ScriptedAI(creature)
    {
        me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }

    void Reset() override
    {
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 100);
        me->AddAura(AURA_OVERRIDE_POWER_COLOR_OCEAN);
        overcharged = false;
        move_fall = false;
        me->SetFaction(35);
    }

    void OnSpellClick(Unit* clicker, bool& result) override
    {
        if (!overcharged)
        {
            overcharged = true;
            me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            if (Player* player = clicker->ToPlayer())
            {
                player->CastSpell(me, SPELL_HACK, false);
                me->ModifyPower(POWER_ENERGY, -100);
                me->DespawnOrUnsummon();
                HK8Fall();
            }
        }
    }

    void HK8Fall()
    {
        if (Creature* hk8 = me->FindNearestCreature(NPC_HK_8_AERIAL_OPPRESION_UNIT, 250.0f, true))
        {
            if (hk8->IsInCombat() && !move_fall)
            {
                move_fall = true;
                hk8->RemoveAura(SPELL_FORCE_SHIELD);
                hk8->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                hk8->SetReactState(REACT_PASSIVE);
                hk8->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
                hk8->SetCanFly(false);
                hk8->SetFlying(false);
                hk8->GetMotionMaster()->MoveFall();
                hk8->AddAura(SPELL_HAYWIRE);
                if (hk8->HasUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC)))
                    hk8->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));

                 hk8->GetScheduler().Schedule(31s, [hk8, this] (TaskContext context)
                 {
                    events.CancelEvent(EVENT_ANNIHILATION_EXPLOSION);
                    hk8->AI()->DoCast(SPELL_LIFT_OFF);
                    //hk8->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                    hk8->SetCanFly(true);
                    hk8->SetFlying(true);
                    hk8->GetMotionMaster()->MoveTargetedHome();
                    //TODO Phase 1 repeat
                 });
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
    bool overcharged;
    bool move_fall;
};

//152272
struct npc_hk8_arena_center_stalker : public ScriptedAI
{
    npc_hk8_arena_center_stalker(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->DespawnCreaturesInArea(NPC_HK_8_AERIAL_OPPRESION_UNIT, 125.0f);
        me->DespawnCreaturesInArea(NPC_TANK_BUSTER_MK1, 125.0f);
        me->DespawnCreaturesInArea(NPC_WALKIE_SHOCKIE_X1, 125.0f);
        me->DespawnCreaturesInArea(NPC_TANK_BUSTER_MK2, 125.0f);
        me->RemoveAllAreaTriggers();
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer()) /*&& instance->GetBossState(DATA_TRIXIE_NAENO) == DONE && instance->GetBossState(DATA_GUNKER) == DONE)*/
        {            
            if (instance->GetBossState(DATA_HK8) != DONE)
            {
                if (Creature* stalker = me->FindNearestCreature(NPC_HK_8_AERIAL_OPPRESION_UNIT, 100.0f, true))                
                    return;
                else
                {
                    me->SummonCreature(NPC_HK_8_AERIAL_OPPRESION_UNIT, boss_hk_default_encounter_pos, TEMPSUMMON_MANUAL_DESPAWN);
                    me->SummonCreature(NPC_TANK_BUSTER_MK1, mk1_spawn_pos, TEMPSUMMON_MANUAL_DESPAWN);
                }
            }
        }
    }
};

//hardmode - 155760
struct npc_tank_buster_mk2 : public ScriptedAI
{
    npc_tank_buster_mk2(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();        
    }
};

void AddSC_boss_hk8()
{
    RegisterCreatureAI(boss_hk_8);
    RegisterCreatureAI(npc_tank_buster_mk1);
    RegisterCreatureAI(npc_walkie_shockie_x1);
    RegisterCreatureAI(npc_overcharge_station);
    RegisterCreatureAI(npc_tank_buster_mk2);
    RegisterCreatureAI(npc_hk8_arena_center_stalker);
};
