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
    SAY_NAENO_AGGRO = 0,
    SAY_PEDAL,
    SAY_BURNOUT,
    SAY_ROADKILL,
    SAY_DEATH_NAENO,
    SAY_DEATH_NAENO_TRIXIE = 3,
    SAY_NAENO_KILL,
    SAY_TRIXIE_ELECTRIC_SLIDE = 0,
    SAY_TRIXIE_MEGA_TAZE,
    SAY_TRIXIE_JUMP_START
};

enum Spells
{
    //Trixie
    SPELL_TAZE = 298669,    
    SPELL_MEGA_TAZE_VISUAL_MISSILE = 302687,
    SPELL_MEGA_TAZE_CHANNEL = 302682,
    SPELL_MEGA_TAZE_DAMAGE = 298718,
    SPELL_ELECTRIC_SLIDE = 298849,
    SPELL_JUMP_START = 298897,
    SPELL_SUPER_BOOST = 303525,//When Naeno is defeated, Trixie gains Super Boost granting her 100% Haste for the remainder of the encounter.
    //Naeno
    SPELL_BOLT_BUSTER = 298940,
    SPELL_ROADKILL_CHARGE = 298946,
    SPELL_ROLL_OUT = 298898,
    SPELL_TURBO_BOOST_MAIN = 299153,
    SPELL_TURBO_BOOST = 299241,//When defeated, Trixie uses Turbo Boost on Naeno causing his successful melee attacks to inflict 46607 Nature damage to all players for the remainder of the encounter.	
    //Mechacycle
    SPELL_SMOKE_CLOUD_CREATE_AT = 298573,
    SPELL_SMOKE_CLOUD_AURA = 298602,
    SPELL_PEDAL_TO_THE_METAL = 298651,
    SPELL_BURNOUT = 298571,    
};

enum Events
{
    EVENT_TAZE = 1,
    EVENT_MEGA_TAZE,
    EVENT_ELECTRIC_SLIDE,
    EVENT_JUMP_START,
    EVENT_BOLT_BUSTER,
    EVENT_ROADKILL,    
    EVENT_PEDAL_TO_THE_METAL,
    EVENT_BURNOUT,
    EVENT_ROLL_OUT,
    EVENT_ENTER_VEHICLE,
    EVENT_EXIT_VEHICLE,
    EVENT_RANDOM_MOVE,
    EVENT_SPAWN_WALKIE
};

enum Misc
{
    PHASE_NORMAL = 1,
    PHASE_VEHICLE
};

//150712 trixie, naeno 153755, mechacycle 153756
struct boss_trixie_naeno : public BossAI
{
    boss_trixie_naeno(Creature* creature) : BossAI(creature, DATA_TRIXIE_NAENO) { }

    void Reset() override
    {
        switch (me->GetEntry())
        {
        case NPC_TRIXIE:
            _Reset();
            me->RemoveAllAreaTriggers();
            break;

        case NPC_NAENO:
            _Reset();
            me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            break;

        case NPC_MECHACYCLE:
            _Reset();
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC));
            vehicle = me->GetVehicleKit();
            me->SetReactState(REACT_PASSIVE);
            break;
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_TRIXIE:
            _EnterCombat();
            events.ScheduleEvent(EVENT_TAZE, 3s);
            events.ScheduleEvent(EVENT_ELECTRIC_SLIDE, 10s);
            events.ScheduleEvent(EVENT_MEGA_TAZE, 15s);
            if (Creature* mechacycle = me->FindNearestCreature(NPC_MECHACYCLE, 100.f, true))
                mechacycle->AI()->DoZoneInCombat(nullptr);

            if (Creature* naeno = me->FindNearestCreature(NPC_NAENO, 100.f, true))
                naeno->AI()->DoZoneInCombat(nullptr);
            
            break;

        case NPC_NAENO:            
            _EnterCombat();
            Talk(SAY_NAENO_AGGRO);
            if (Creature* mechacycle = me->FindNearestCreature(NPC_MECHACYCLE, 100.f, true))
            {                 
                me->NearTeleportTo(mechacycle->GetPosition()), false;
                me->EnterVehicle(mechacycle);
                events.SetPhase(PHASE_VEHICLE);
                events.ScheduleEvent(EVENT_PEDAL_TO_THE_METAL, 5s);
                events.ScheduleEvent(EVENT_BURNOUT, 10s);                    
                events.ScheduleEvent(EVENT_EXIT_VEHICLE, 60s);
            }
            break;

        case NPC_MECHACYCLE:
            _EnterCombat();
            events.ScheduleEvent(EVENT_RANDOM_MOVE, 3s);
            break;
        }
    }    

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        std::list<Creature*> gnomes_list;
        gnomes_list.clear();
        me->GetCreatureListWithEntryInGrid(gnomes_list, NPC_TRIXIE, 300.0f);
        me->GetCreatureListWithEntryInGrid(gnomes_list, NPC_NAENO, 300.0f);
        me->GetCreatureListWithEntryInGrid(gnomes_list, NPC_MECHACYCLE, 300.0f);
        for (auto& encounterNPCs : gnomes_list)
        {
            if (encounterNPCs->isDead())
                encounterNPCs->Respawn();

            encounterNPCs->AI()->JustReachedHome();
            encounterNPCs->NearTeleportTo(me->GetHomePosition());
            encounterNPCs->ForcedDespawn(0, 15s);
        }
    }

    void ExecuteEvent(uint32 eventid) override
    {
        switch (eventid)
        {
        case EVENT_TAZE:
            DoCastRandom(SPELL_TAZE, 100.0f, false);
            events.Repeat(5s);
            break;

        case EVENT_ELECTRIC_SLIDE:
            Talk(SAY_TRIXIE_ELECTRIC_SLIDE);
            if (Creature* stalker = me->FindNearestCreature(NPC_JUMP_POINT_STALKER, 25.0f, true))
            {                
                //me->CastSpell(stalker->GetPosition(), SPELL_ELECTRIC_SLIDE, false);
                me->GetMotionMaster()->MoveJump(stalker->GetPosition(), 0.8F, 30.0f, 30.0f, true);
                me->GetScheduler().Schedule(3s, [this] (TaskContext context)
                {
                    me->RemoveAura(SPELL_ELECTRIC_SLIDE);
                });
            }
            events.Repeat(20s);
            break;

        case EVENT_MEGA_TAZE:
            Talk(SAY_TRIXIE_MEGA_TAZE);
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
            {
                me->SetFacingToObject(target);
                me->CastSpell(target, SPELL_MEGA_TAZE_CHANNEL, false);
                me->GetScheduler().Schedule(8s, [target, this] (TaskContext context)
                {
                    if (!target->HasAura(SPELL_SMOKE_CLOUD_AURA))
                    {
                        me->CastSpell(target, SPELL_MEGA_TAZE_VISUAL_MISSILE, true);
                        me->CastSpell(target, SPELL_MEGA_TAZE_DAMAGE, true);
                    }
                });
            }
            events.Repeat(30s);
            break;

        case EVENT_BOLT_BUSTER:
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 100.0f, true))
            {
                me->SetFacingToObject(target);
                me->CastSpell(target, SPELL_BOLT_BUSTER, false);
            }
            events.Repeat(15s);
            break;

        case EVENT_ROADKILL:
            Talk(SAY_ROADKILL);
            if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))            
                me->CastSpell(target, SPELL_ROADKILL_CHARGE, true);
            events.Repeat(20s);
            break;

        case EVENT_ENTER_VEHICLE:            
            if (Creature* mechacycle = me->FindNearestCreature(NPC_MECHACYCLE, 100.f, true))
            {
                me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                events.CancelEvent(EVENT_BOLT_BUSTER);
                events.CancelEvent(EVENT_ROADKILL);
                events.ScheduleEvent(EVENT_PEDAL_TO_THE_METAL, 5s);
                events.ScheduleEvent(EVENT_BURNOUT, 10s);                
                events.ScheduleEvent(EVENT_EXIT_VEHICLE, 60s);
                me->NearTeleportTo(mechacycle->GetPosition()), false;
                me->EnterVehicle(mechacycle);
                events.SetPhase(PHASE_VEHICLE);
            }            
            break;

        case EVENT_EXIT_VEHICLE:
            events.CancelEvent(EVENT_PEDAL_TO_THE_METAL);
            events.CancelEvent(EVENT_BURNOUT);
            me->ExitVehicle();
            events.SetPhase(PHASE_NORMAL);
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            events.ScheduleEvent(EVENT_BOLT_BUSTER, 3s);
            events.ScheduleEvent(EVENT_ROADKILL, 10s);
            events.ScheduleEvent(EVENT_ENTER_VEHICLE, 60s);
            break;

        case EVENT_PEDAL_TO_THE_METAL:
            Talk(SAY_PEDAL);
            if (Creature* mechacycle = me->FindNearestCreature(NPC_MECHACYCLE, 10.0f, true))
            {
                mechacycle->StopMoving();
                if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
                {                    
                    mechacycle->SetFacingToObject(target, true);                    
                    mechacycle->CastSpell(target->GetPosition(), SPELL_PEDAL_TO_THE_METAL, false);
                }
            }
            events.Repeat(20s);
            break;

        case EVENT_BURNOUT:
            Talk(SAY_BURNOUT);
            if (Creature* mechacycle = me->FindNearestCreature(NPC_MECHACYCLE, 10.0f, true))            
                mechacycle->AI()->DoCastSelf(SPELL_BURNOUT);

            events.Repeat(25s);
            break;

        case EVENT_RANDOM_MOVE:
             if (Creature* naeno = me->FindNearestCreature(NPC_NAENO, 100.0f, true))
             {
                if (naeno->IsInCombat() && !me->HasUnitState(UNIT_STATE_CASTING))
                    me->GetMotionMaster()->MoveRandom(15.0f);
             }
            events.Repeat(3s);
            break;
        }
    }

    void JustDied(Unit* killer) override
    {
        switch (me->GetEntry())
        {
        case NPC_TRIXIE:
            _JustDied();
            Talk(SAY_DEATH_NAENO_TRIXIE);
            if (Creature* trixie = me->FindNearestCreature(NPC_TRIXIE, 100.0f, true))            
                trixie->AI()->DoCastSelf(SPELL_SUPER_BOOST);
          
            break;

        case NPC_NAENO:            
            _JustDied();
            Talk(SAY_DEATH_NAENO);
            if (Creature* naeno = me->FindNearestCreature(NPC_NAENO, 100.0f, true))            
                naeno->AI()->DoCastSelf(SPELL_TURBO_BOOST);

            if (Creature* mechacycle = me->FindNearestCreature(NPC_MECHACYCLE, 100.0f, true))
                mechacycle->DespawnOrUnsummon();

            instance->DoModifyPlayerCurrencies(1553, 35);
            break;

        case NPC_MECHACYCLE:
            _JustDied();
            break;
        }
    }

private:
    Vehicle* vehicle;
};

//153761
struct npc_smoke_cloud_stalker : public ScriptedAI
{
    npc_smoke_cloud_stalker(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->CastSpell(nullptr, SPELL_SMOKE_CLOUD_CREATE_AT, true);
    }
};

void AddSC_boss_trixie_naeno()
{
    RegisterCreatureAI(boss_trixie_naeno);
    RegisterCreatureAI(npc_smoke_cloud_stalker);
};
