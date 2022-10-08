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
    SAY_AGGRO = 0,
    SAY_GIGA_ZAP,
    SAY_TAKE_OFF,
    SAY_STAGE_TWO,
    SAY_MAGNETO_ARM,
    SAY_KILL,
    SAY_DEATH
};

enum Spells
{    
    SPELL_PULSE_BLAST = 291878,
    SPELL_PLASMA_ORB_DAMAGE_KNOCK = 291915,
    SPELL_PLASMA_ORB_APPLY_AT_VISUAL = 291835,
    SPELL_RECALIBRATE_DAMAGE_KNOCK = 291856,
    SPELL_RECALIBRATE_TAR_DEST_VISUAL = 291845,
    SPELL_GIGA_ZAP_MAIN = 291928,
    SPELL_GIGA_ZAP_DAMAGE = 291939,
    SPELL_TAKE_OFF = 291613,
    SPELL_CUTTING_BEAM_CREATE_AT = 291626,
    SPELL_OBNOXIOUS_MONOLOQUE = 291974,
    SPELL_MAGNETO_ARM_CREATE_AT = 283143,
};

enum Events
{
    EVENT_PULSE_BLAST = 1,
    EVENT_PLASMA_ORBS,
    EVENT_RECALIBRATE,
    EVENT_GIGA_ZAP,
    EVENT_TAKE_OFF,
    EVENT_STAGE_TWO,
    EVENT_CUTTING_BEAM,
    EVENT_MAGNETO_ARM
};

Vehicle* vehicle;

const Position king_mechagon_jump_pos = { 699.518f, 623.309f, -238.285f, 5.25f };
const Position king_mechagon_vehicle_escort_pos = { 633.195f, 551.366f, -266.912f, 5.25f };

//150397
struct boss_king_mechagon : public BossAI
{
    boss_king_mechagon(Creature* creature) : BossAI(creature, DATA_KING_MECHAGON) { }

    void Reset() override
    {
        BossAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->ForcedDespawn(0, 15s);
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        std::list<Creature*> encounter_list;
        encounter_list.clear();
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_AERIEL_UNIT, 300.0f);
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_OMEGA_BUSTER, 300.0f);
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_PLASMA_ORB, 300.0f);
        for (auto& encounterNPCs : encounter_list)
        {
            if (encounterNPCs->isDead())
                encounterNPCs->Respawn();

            encounterNPCs->AI()->JustReachedHome();
            encounterNPCs->NearTeleportTo(me->GetHomePosition());
            encounterNPCs->DespawnOrUnsummon();
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }
};

//150396
struct npc_aeriel_unit : public BossAI
{
    npc_aeriel_unit(Creature* creature) : BossAI(creature, DATA_KING_MECHAGON) { }

    void Reset() override
    {
        ScriptedAI::Reset();        
        vehicle = me->GetVehicleKit();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        if (Creature* king = me->FindNearestCreature(NPC_KING_MECHAGON, 100.0f, true))
        {
            king->EnterVehicle(me);
            king->AI()->Talk(SAY_AGGRO);
            if (!king->IsInCombat())
                king->AI()->DoZoneInCombat(nullptr);
        }
        events.ScheduleEvent(EVENT_PLASMA_ORBS, 1s);
        events.ScheduleEvent(EVENT_PULSE_BLAST, 2s);
        events.ScheduleEvent(EVENT_RECALIBRATE, 7s);
        events.ScheduleEvent(EVENT_CUTTING_BEAM, 12s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->ForcedDespawn(0, 15s);
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        std::list<Creature*> encounter_list;
        encounter_list.clear();
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_AERIEL_UNIT, 300.0f);
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_OMEGA_BUSTER, 300.0f);
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_PLASMA_ORB, 300.0f);
        for (auto& encounterNPCs : encounter_list)
        {
            if (encounterNPCs->isDead())
                encounterNPCs->Respawn();

            encounterNPCs->AI()->JustReachedHome();
            encounterNPCs->NearTeleportTo(me->GetHomePosition());
            encounterNPCs->DespawnOrUnsummon();
        }
    }

    void KilledUnit(Unit* victim) override
    {        
        if (victim->IsPlayer())
        {
            uint32 Random = urand(0, 1);
            switch (Random)
            {
            case 0:
                return;
                break;
            case 1:
                if (Creature* king = me->FindNearestCreature(NPC_KING_MECHAGON, 100.0f, true))
                    king->AI()->Talk(SAY_KILL);
                break;
            }
        }
    }

    void ExecuteEvent(uint32 eventid) override
    {
        switch (eventid)
        {
        case EVENT_PULSE_BLAST:
            DoCastVictim(SPELL_PULSE_BLAST, false);
            events.Repeat(2s);
            break;

        case EVENT_PLASMA_ORBS:
            for (uint8 i = 0; i < 5; i++)
            {
                me->SummonCreature(NPC_PLASMA_ORB, me->GetRandomPoint(me->GetPosition(), 15.0f));
            }
            break;

        case EVENT_RECALIBRATE:
        {
            if (Unit* targets = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
            {
                std::list<Creature*> plasma_orbs_list;
                plasma_orbs_list.clear();
                me->GetCreatureListWithEntryInGrid(plasma_orbs_list, NPC_BUZZ_SAW, 300.0f);
                for (auto& plasma_orbs : plasma_orbs_list)
                {
                    plasma_orbs->SetFacingToObject(targets);
                    me->GetScheduler().Schedule(1s, [plasma_orbs, targets, this] (TaskContext context)
                    {
                        plasma_orbs->CastSpell(targets, SPELL_RECALIBRATE_TAR_DEST_VISUAL, false);
                        plasma_orbs->GetMotionMaster()->MoveCharge(targets->GetPositionX(), targets->GetPositionY(), targets->GetPositionZ(), 80.0f, 1, true);
                    });
                    me->GetScheduler().Schedule(2s, [plasma_orbs, targets] (TaskContext context)
                    {
                        plasma_orbs->AI()->DoCastAOE(SPELL_RECALIBRATE_DAMAGE_KNOCK, true);
                    });
                }
            }
            events.Repeat(20s);
            break;
        }

        case EVENT_CUTTING_BEAM:
            DoCast(SPELL_TAKE_OFF);
            if (Creature* king = me->FindNearestCreature(NPC_KING_MECHAGON, 100.0f, true))            
                king->AI()->Talk(SAY_TAKE_OFF);
            me->GetScheduler().Schedule(11s, [this] (TaskContext context)
            {
                me->UpdatePosition(me->GetPositionX() + 0.0f, me->GetPositionY() + 0, me->GetPositionZ() + 15.0f, me->GetOrientation());
                DoCastSelf(SPELL_CUTTING_BEAM_CREATE_AT);
            });
            events.Repeat(30s);
            break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustReachedHome();
        if (Creature* king = me->FindNearestCreature(NPC_KING_MECHAGON, 100.0f, true))
        {
            king->ExitVehicle();
            king->AI()->Talk(SAY_STAGE_TWO);
            if (Creature* omega = me->FindNearestCreature(NPC_OMEGA_BUSTER, 100.0f, true))
            {                
                if (omega->HasUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE)))
                {
                    omega->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE));
                    king->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    king->AI()->DoCastAOE(SPELL_OBNOXIOUS_MONOLOQUE);
                    king->EnterVehicle(omega);
                    omega->AI()->DoZoneInCombat(nullptr);
                }
            }
        }
        me->DespawnCreaturesInArea(NPC_PLASMA_ORB, 125.0f);
    }
};

//144249
struct npc_omega_buster : public BossAI
{
    npc_omega_buster(Creature* creature) : BossAI(creature, DATA_KING_MECHAGON) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        vehicle = me->GetVehicleKit();
        me->AddUnitState(UNIT_STATE_ROOT);
        me->SetCombatReach(40.0f);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();        
        events.ScheduleEvent(EVENT_GIGA_ZAP, 5s);
        events.ScheduleEvent(EVENT_PLASMA_ORBS, 10s);
        events.ScheduleEvent(EVENT_RECALIBRATE, 15s);
        events.ScheduleEvent(EVENT_MAGNETO_ARM, 20s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->ForcedDespawn(0, 15s);
        _JustReachedHome();
        me->NearTeleportTo(me->GetHomePosition());
        std::list<Creature*> encounter_list;
        encounter_list.clear();
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_AERIEL_UNIT, 300.0f);
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_OMEGA_BUSTER, 300.0f);
        me->GetCreatureListWithEntryInGrid(encounter_list, NPC_PLASMA_ORB, 300.0f);
        for (auto& encounterNPCs : encounter_list)
        {
            if (encounterNPCs->isDead())
                encounterNPCs->Respawn();

            encounterNPCs->AI()->JustReachedHome();
            encounterNPCs->NearTeleportTo(me->GetHomePosition());
            encounterNPCs->DespawnOrUnsummon();
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
        {
            uint32 Random = urand(0, 1);
            switch (Random)
            {
            case 0:
                return;
                break;
            case 1:
                if (Creature* king = me->FindNearestCreature(NPC_KING_MECHAGON, 100.0f, true))
                    king->AI()->Talk(SAY_KILL);
                break;
            }
        }
    }

    void ExecuteEvent(uint32 eventid) override
    {
        switch (eventid)
        {
        case EVENT_GIGA_ZAP:
            if (Creature* king = me->FindNearestCreature(NPC_KING_MECHAGON, 100.0f, true))
            {
                king->AI()->Talk(SAY_GIGA_ZAP);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                {
                    me->CastSpell(target, SPELL_GIGA_ZAP_MAIN);
                }
            }
            events.Repeat(20s);
            break;

        case EVENT_PLASMA_ORBS:
            for (uint8 i = 0; i < 5; i++)
            {
                me->SummonCreature(NPC_PLASMA_ORB, me->GetRandomPoint(me->GetPosition(), 15.0f));
            }
            break;

        case EVENT_RECALIBRATE:
        {
            if (Unit* targets = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
            {
                std::list<Creature*> plasma_orbs_list;
                plasma_orbs_list.clear();
                me->GetCreatureListWithEntryInGrid(plasma_orbs_list, NPC_BUZZ_SAW, 300.0f);
                for (auto& plasma_orbs : plasma_orbs_list)
                {
                    plasma_orbs->SetFacingToObject(targets);
                    me->GetScheduler().Schedule(1s, [plasma_orbs, targets, this](TaskContext context)
                    {
                        plasma_orbs->CastSpell(targets, SPELL_RECALIBRATE_TAR_DEST_VISUAL, false);
                        plasma_orbs->GetMotionMaster()->MoveCharge(targets->GetPositionX(), targets->GetPositionY(), targets->GetPositionZ(), 80.0f, 1, true);
                    });
                    me->GetScheduler().Schedule(2s, [plasma_orbs, targets](TaskContext context)
                    {
                        plasma_orbs->AI()->DoCastAOE(SPELL_RECALIBRATE_DAMAGE_KNOCK, true);
                    });
                }
            }
            events.Repeat(25s);
            break;

        case EVENT_MAGNETO_ARM:
            if (Creature* king = me->FindNearestCreature(NPC_KING_MECHAGON, 100.0f, true))
                king->AI()->Talk(SAY_MAGNETO_ARM);
            std::list<Creature*> plasma_orbs_list;
            plasma_orbs_list.clear();
            me->GetCreatureListWithEntryInGrid(plasma_orbs_list, NPC_PLASMA_ORB, 300.0f);
            for (auto& plasma_orbs : plasma_orbs_list)
            {
                plasma_orbs->SetWalk(true);
                plasma_orbs->GetMotionMaster()->MoveFollow(me, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
            }
            events.Repeat(30s);
            break;
        }
        }
    };

    void JustDied(Unit* /*unit*/) override
    {
        _JustDied();
        me->DespawnCreaturesInArea(NPC_PLASMA_ORB, 125.0f);
        me->SetVisible(false);
        if (Creature* king = me->FindNearestCreature(NPC_KING_MECHAGON, 100.0f, true))
        {
            king->ExitVehicle(me);
            king->NearTeleportTo(king_mechagon_jump_pos, false);
            king->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
        }
    }
};

//150485
struct npc_plasma_orb : public ScriptedAI
{
    npc_plasma_orb(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        me->SetReactState(REACT_PASSIVE);
        me->CastSpell(nullptr, SPELL_PLASMA_ORB_APPLY_AT_VISUAL);
        me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
    }
};

//500521
struct npc_transport_mechagon : public ScriptedAI
{
    npc_transport_mechagon(Creature* creature) : ScriptedAI(creature) { }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
        if (instance)
        {
            if (instance->GetBossState(DATA_HEAD_MACHINIST_SPARKFLUX) == DONE)
            {
                me->GetScheduler().Schedule(3s, [this](TaskContext context)
                {
                    std::list<Player*> player_list;
                    me->GetPlayerListInGrid(player_list, 5.0f);            
                    for (auto& players : player_list)
                    {
                        players->TeleportTo(2097, king_mechagon_vehicle_escort_pos);
                    }
                });
            }
        }
    }

private:
    TaskScheduler scheduler;
};

void AddSC_boss_king_mechagon()
{
    RegisterCreatureAI(boss_king_mechagon);
    RegisterCreatureAI(npc_aeriel_unit);
    RegisterCreatureAI(npc_omega_buster);
    RegisterCreatureAI(npc_plasma_orb);
    RegisterCreatureAI(npc_transport_mechagon);
};
