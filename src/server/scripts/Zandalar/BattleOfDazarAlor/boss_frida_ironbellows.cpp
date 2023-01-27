#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "battle_of_dazaralor.h"

const Position adds_pos = { -631.0f, 1089.0f, 321.0f, 0.77f };

enum Texts
{
    SAY_AGGRO = 0,
    SAY_INTRO = 1,
    SAY_WAVE_OF_LIGHT,
    SAY_PRAYER_FOR_THE_FALLEN,
    SAY_RETRIBUTION,
    SAY_RECKONING,
    SAY_CALL_TO_ARMS,
    SAY_KILL,
    SAY_DEATH
};

enum Spells
{
    PERIODIC_ENERGY_GAIN = 295065,
    SUMMON_DARKFORGE_RAM = 270562,
    SACRED_BLADE = 283572,
    WAVE_OF_LIGHT_CREATE_AT = 283598,
    WAVE_OF_LIGHT_PERIODIC = 283617,
    WAVE_OF_LIGHT_HEAL = 283619,
    SEAL_OF_RETRIBUTION = 284469,
    RETRIBUTION_AOE_DAMAGE = 284488,
    ZEALOTRY = 284459,
    JUDGMENT_RIGHTEOUSNESS = 283933,
    SEAL_OF_RECKONING = 284436,
    JUDGMENT_RECKONING = 284474,
    AVENGING_WRATH = 282113,
    CALL_TO_ARMS = 283662,
    PRAYER_OF_THE_FALLEN = 287469,
    DIVINE_PROTECTION = 288292,
    DIVINE_PROCTECTION_REDUCTION = 288294,
};

enum Events
{
    EVENT_WAVE_OF_LIGHT = 1,
    EVENT_SEAL_OF_RETRIBUTION,
    EVENT_ZEALOTRY,
    EVENT_JUDGMENT_RIGHTEOUSNESS,
    EVENT_SEAL_OF_RECKONING,
    EVENT_AVENGING_WRATH,
    EVENT_PRAYER_FOR_THE_FALLEN,
    EVENT_JUDGMENT_OF_RECKONING,
    EVENT_CALL_TO_ARMS,
    EVENT_SWITCH_SEAL,
    EVENT_DIVINE_PROTECTION,
};

enum Disciple
{
    ANGELIC_RENEWAL = 287419,
    DIVINE_BURST = 283626,
    HEAL_SP = 283628,
    PENANCE_HEAL = 284593,
    PENANCE_DAMAGE = 284595,
    EVENT_DIVINE_BURST = 1,
    EVENT_HEAL,
    EVENT_PENANCE_HEAL,
    EVENT_PENANCE_DAMAGE
};

enum Crusader
{
    AURA_OF_RETRIBUTION = 284468,
    BLINDING_FAITH_DUMMY = 283650,
    BLINDING_FAITH_DISORIENT = 283651,
    CONSECRATION_AT = 283579,
    CONSECRATION_DAMAGE = 294347,
    CONSECRATION_REDUCE_DAMAGE = 283583,
    CRUSADER_STRIKE = 283637,
    DIVINE_MALLET = 287439,
    DIVINE_MALLET_AT = 282074,
    WAVE_OF_LIGHT_HEALING = 283619,
    EVENT_CRUSADER_STRIKE = 1,
    EVENT_CONSECRATION,
    EVENT_DIVINE_MALLET,
    EVENT_BLINDING_FAITH,
};

//144680
struct boss_frida_ironbellows : public BossAI
{
    boss_frida_ironbellows(Creature* creature) : BossAI(creature, DATA_FRIDA_IRONBELLOWS) { }

private:
    Vehicle* vehicle;

    void Reset() override
    {        
        BossAI::Reset();
        me->RemoveAura(PERIODIC_ENERGY_GAIN);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        intro = false;
        hp60 = false;
        hp30 = false;        
        me->Mount(85394, 0, 141164);
        me->RemoveAllAreaTriggers();
    }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (unit->IsPlayer() && intro == false)
        {
            intro = true;
            Talk(SAY_INTRO);
        }
    }

    void EnterCombat(Unit* /*unit*/) override
    {        
        _EnterCombat();
        Talk(SAY_AGGRO);
        DoCast(PERIODIC_ENERGY_GAIN);
        me->StopMoving();
        me->AddAura(SEAL_OF_RETRIBUTION);
        me->GetScheduler().Schedule(3s, [this] (TaskContext context)
        {
            Talk(SAY_RETRIBUTION);
        });
        events.ScheduleEvent(EVENT_WAVE_OF_LIGHT, 12s);    
        events.ScheduleEvent(EVENT_JUDGMENT_RIGHTEOUSNESS, 50s);
        events.ScheduleEvent(EVENT_JUDGMENT_OF_RECKONING, 60s);
        events.ScheduleEvent(EVENT_CALL_TO_ARMS, 65s);
        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_DIVINE_PROTECTION, 15s);

        if (IsMythic())
            events.ScheduleEvent(EVENT_PRAYER_FOR_THE_FALLEN, 25s);

        if (me->IsInCombat())
        {
            std::list<Creature*> encounterNPCs;
            me->GetCreatureListWithEntryInGrid(encounterNPCs, NPC_DARKFORGED_CRUSADER, 100.0f);
            me->GetCreatureListWithEntryInGrid(encounterNPCs, NPC_ANOINTED_DISCIPLE, 100.0f);
            for (auto& minions : encounterNPCs)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, minions);
                if (!minions->IsInCombat())
                    minions->AI()->DoZoneInCombat(nullptr);
            }
        }

        if (auto* encounterDoor = me->FindNearestGameObject(GO_FRIDA_WALL_OF_SPEARS, 100.0f))
            encounterDoor->SetGoState(GO_STATE_READY);
    }

    void DamageTaken(Unit* unit, uint32& damage) override
    {
        if (me->HealthBelowPct(60) && hp60 == false)        
            hp60 = true;

        if (me->HealthBelowPct(30) && hp30 == false)
        {
            hp30 = true;
            DoCast(AVENGING_WRATH);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override 
    { 
        _JustReachedHome();        
        me->RemoveAllAreaTriggers();
        std::list<Creature*> encounterNPCs;
        me->GetCreatureListWithEntryInGrid(encounterNPCs, NPC_DARKFORGED_CRUSADER, 100.0f);
        me->GetCreatureListWithEntryInGrid(encounterNPCs, NPC_ANOINTED_DISCIPLE, 100.0f);
        for (auto& minions : encounterNPCs)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, minions);
            minions->NearTeleportTo(minions->GetHomePosition());
            minions->ForcedDespawn(0, 5s);            
        }

        if (auto* encounterDoor = me->FindNearestGameObject(GO_FRIDA_WALL_OF_SPEARS, 100.0f))
            encounterDoor->SetGoState(GO_STATE_ACTIVE);

        _DespawnAtEvade();
    }

    void JustSummoned(Creature* summon) override
    {
        summon->AI()->DoZoneInCombat(nullptr, 250.0f);
    }

    void JustDied(Unit* /*unit*/) override
    {
       _JustDied();
       Talk(SAY_DEATH);
       me->RemoveAllAreaTriggers();
       me->DespawnCreaturesInArea(NPC_DARKFORGED_CRUSADER, 125.0f);
       me->DespawnCreaturesInArea(NPC_ANOINTED_DISCIPLE, 125.0f);

       if (auto* encounterDoor = me->FindNearestGameObject(GO_FRIDA_WALL_OF_SPEARS, 100.0f))
           encounterDoor->SetGoState(GO_STATE_ACTIVE);

       if (IsMythic())
           instance->DoCompleteAchievement(13292); //Mythic: Champion of the Light

       if (auto* rokhan = me->FindNearestCreature(NPC_ROKHAN, 100.0f, true))
       {
           rokhan->GetScheduler().Schedule(5s, [rokhan] (TaskContext context)
           {                
                rokhan->Say("Take dat shorty! Nice work, champions!", LANG_UNIVERSAL);
           });
           rokhan->GetScheduler().Schedule(10s, [rokhan](TaskContext context)
           {
                InstanceScript* instance = rokhan->GetInstanceScript();
                instance->DoPlayScenePackageIdOnPlayers(SCENE_BLOOD_MOON_RISING);
                rokhan->GetMotionMaster()->MovePoint(2, -843.791f, 991.902f, 320.982f, true);
                if (auto* talanji = rokhan->FindNearestCreature(NPC_PRINCESS_TALANJI, 100.0f, true))
                {
                    talanji->GetMotionMaster()->MovePoint(2, -622.842f, 1105.355f, 320.464f, true);
                    talanji->GetScheduler().Schedule(5s, [talanji](TaskContext context)
                    {
                        talanji->Say("De city surges with Bwonsamdi's power! My father would not invoke dis ritual unless de odds were dire.", LANG_UNIVERSAL);
                        talanji->SummonCreature(NPC_RIDING_PTERRORDAX, talanji->GetRandomPoint(talanji->GetPosition(), 5.0f));
                        if (auto* pterrodax = talanji->FindNearestCreature(NPC_RIDING_PTERRORDAX, 25.0f, true))
                        {
                            Vehicle* vehicle = pterrodax->GetVehicleKit();
                            pterrodax->SetFlying(true);
                            talanji->EnterVehicle(pterrodax);
                            pterrodax->GetMotionMaster()->MovePoint(1, -842.941f, 981.829f, 361.478f, true);
                        }
                    });
                    rokhan->GetMotionMaster()->MovePoint(2, -843.791f, 991.902f, 320.982f);
                    if (auto* nathanos = rokhan->FindNearestCreature(NPC_NATHANOS_BRIGHTCALLER, 100.0f, true))
                        nathanos->GetMotionMaster()->MovePoint(2, -843.737f, 981.961f, 320.945f, true);
                    if (auto* kaja = rokhan->FindNearestCreature(NPC_BLADEGUARD_KAJA, 100.0f, true))
                        kaja->GetMotionMaster()->MovePoint(2, -836.411f, 977.601f, 320.748f, true);
                }   
           });
       }
    }

    void KilledUnit(Unit* unit) override
    {
        if (unit->IsPlayer())
            if (roll_chance_f(15))
                Talk(SAY_KILL);
    }

   void SpellHit(Unit* caster, SpellInfo const* spell) override 
   {
       if (me->HasAura(SEAL_OF_RECKONING))
           me->AddAura(ZEALOTRY);
   }

   void JudgmentRighteousnessTargets()
   {
       uint32 Choose = urand(0, 1);

       switch (Choose)
       {
       case 0:
       {
           if (Creature* crusader = me->FindNearestCreature(NPC_DARKFORGED_CRUSADER, 500.0f, true))
               me->CastSpell(crusader, JUDGMENT_RIGHTEOUSNESS);
           break;
       }
       case 1:
       {
           if (Creature* disciple = me->FindNearestCreature(NPC_ANOINTED_DISCIPLE, 500.0f, true))
               me->CastSpell(disciple, JUDGMENT_RIGHTEOUSNESS);
           break;
       }
       }
   }
   
   void OnSpellFinished(SpellInfo const* spellInfo) 
   {
       if (spellInfo->Id == CALL_TO_ARMS)
       {
           me->SummonCreature(NPC_DARKFORGED_CRUSADER, adds_pos, TEMPSUMMON_MANUAL_DESPAWN);
           me->SummonCreature(NPC_ANOINTED_DISCIPLE, adds_pos, TEMPSUMMON_MANUAL_DESPAWN);
       }
   }

   void ExecuteEvent(uint32 eventId) override
   {
        if (me->GetPower(POWER_ENERGY) >= 100)
        {
            events.ScheduleEvent(EVENT_SWITCH_SEAL, 100ms);
        }

        switch (eventId)
        {
        case EVENT_DIVINE_PROTECTION:
        {
            if (Creature* crusader = me->FindNearestCreature(NPC_DARKFORGED_CRUSADER, 100.0f, true))
            {
                if (crusader->HealthBelowPct(99) && !crusader->HasAura(DIVINE_PROCTECTION_REDUCTION))
                    crusader->AddAura(DIVINE_PROCTECTION_REDUCTION);
            }
            if (Creature* disciple = me->FindNearestCreature(NPC_ANOINTED_DISCIPLE, 100.0f, true))
            {
                if (disciple->HealthBelowPct(99) && !disciple->HasAura(DIVINE_PROCTECTION_REDUCTION))
                    disciple->AddAura(DIVINE_PROCTECTION_REDUCTION);
            }
            events.Repeat(15s);
            break;
        }
        case EVENT_WAVE_OF_LIGHT:
        {
             Talk(SAY_WAVE_OF_LIGHT);
             if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f))     
             {
                 me->SetFacingToObject(target);
                 me->CastSpell(nullptr, WAVE_OF_LIGHT_CREATE_AT, false);
             }             
             events.Repeat(20s);
             break;
        }
        case EVENT_PRAYER_FOR_THE_FALLEN:
        {
             Talk(SAY_PRAYER_FOR_THE_FALLEN);
             DoCast(PRAYER_OF_THE_FALLEN);
             std::list<Creature*> c_li;
             me->GetCreatureListWithEntryInGrid(c_li, NPC_ANOINTED_DISCIPLE, 250.0f);
             for (auto& disciples : c_li)
             {             
                 disciples->StopMoving();
                 disciples->CastSpell(disciples, ANGELIC_RENEWAL, false);
             }
             std::list<Creature*> c_li_2;
             me->GetCreatureListWithEntryInGrid(c_li_2, NPC_DARKFORGED_CRUSADER, 250.0f);
             for (auto& crusaders : c_li_2)
             crusaders->CastSpell(nullptr, DIVINE_MALLET, false);
             events.Repeat(50s);
             break;
        }
        case EVENT_JUDGMENT_RIGHTEOUSNESS:
        {
             JudgmentRighteousnessTargets();
             events.Repeat(30s);
             break;
        }
        case EVENT_JUDGMENT_OF_RECKONING:
        {
            if (me->GetPower(POWER_ENERGY) >= 100)
            {
                me->StopMoving();
                me->CastStop();
                Talk(SAY_RECKONING);
                me->SetPower(POWER_ENERGY, 0);
                DoCastAOE(JUDGMENT_RECKONING);                
            }
            events.Repeat(60s);
            break;
        }
        case EVENT_SWITCH_SEAL:
        {
            if (me->GetPower(POWER_ENERGY) >= 100)
            {
                if (me->HasAura(SEAL_OF_RETRIBUTION))
                {
                    me->GetScheduler().Schedule(100ms, [this] (TaskContext context)
                    {
                        me->SetPower(POWER_ENERGY, 0);
                        me->RemoveAura(SEAL_OF_RETRIBUTION);
                        me->RemoveAura(PERIODIC_ENERGY_GAIN);                        

                        me->AddAura(SEAL_OF_RECKONING);                        
                    });
                }
                if (me->HasAura(SEAL_OF_RECKONING))
                {
                    me->GetScheduler().Schedule(100ms, [this] (TaskContext context)
                    {
                        me->SetPower(POWER_ENERGY, 0);
                        me->RemoveAura(SEAL_OF_RECKONING);
                        me->RemoveAura(PERIODIC_ENERGY_GAIN);                        

                        me->AddAura(SEAL_OF_RETRIBUTION);
                        me->AddAura(PERIODIC_ENERGY_GAIN);
                    });
                }
            }
            break;
        }
        case EVENT_CALL_TO_ARMS:       
        {
             Talk(SAY_CALL_TO_ARMS);
             me->StopMoving();
             DoCast(CALL_TO_ARMS);
             events.Repeat(35s);
             break;
        }
        }
   }

private:
    bool hp30;
    bool hp60;
    bool intro;
};

//145903
struct npc_darkforged_crusader_145903 : public ScriptedAI
{
    npc_darkforged_crusader_145903(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();        
    }

    void EnterCombat(Unit * u) override
    {  
        events.ScheduleEvent(EVENT_CRUSADER_STRIKE, 3s);
        events.ScheduleEvent(EVENT_CONSECRATION, 8s);
        events.ScheduleEvent(EVENT_BLINDING_FAITH, 13s);
        events.ScheduleEvent(EVENT_DIVINE_MALLET, 18s);
    }

    void MoveInLineOfSight(Unit* u) override
    {
        if (Creature* frida = me->FindNearestCreature(NPC_FRIDA_IRONBELLOWS, 100.0f, true))
        {
            if (me->GetDistance2d(frida) <= 30.0f)
            {
                if (frida->HasAura(AURA_OF_RETRIBUTION))
                {
                    if (!me->HasAura(AURA_OF_RETRIBUTION))
                        me->AddAura(AURA_OF_RETRIBUTION);
                }
                else
                {
                    if (me->HasAura(AURA_OF_RETRIBUTION))
                        me->RemoveAura(AURA_OF_RETRIBUTION);
                }
            }
        }
    }

    void JustDied(Unit* u) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (Creature* frida = me->FindNearestCreature(NPC_FRIDA_IRONBELLOWS, 100.0f, true))
            frida->AddAura(ZEALOTRY);
    }

    void OnSpellFinished(SpellInfo const* spellInfo) override
    { 
        if (spellInfo->Id == BLINDING_FAITH_DUMMY)
        {
            DoCastVictim(BLINDING_FAITH_DISORIENT);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_CRUSADER_STRIKE:
             me->StopMoving();
             DoCastVictim(CRUSADER_STRIKE);
             events.Repeat(15s);
             break;

        case EVENT_CONSECRATION:
             me->StopMoving();
             DoCastAOE(CONSECRATION_AT);
             events.Repeat(20s);
             break;

        case EVENT_BLINDING_FAITH:
             me->StopMoving();
             DoCastAOE(BLINDING_FAITH_DUMMY);
             events.Repeat(25s);
             break;

        case EVENT_DIVINE_MALLET:
             me->StopMoving();
             DoCastAOE(DIVINE_MALLET_AT);
             events.Repeat(30s);
             break;
        }
    }
};

//145898
struct npc_antoined_disciple_145898 : public ScriptedAI
{
    npc_antoined_disciple_145898(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterCombat(Unit* u) override
    {
        events.ScheduleEvent(EVENT_DIVINE_BURST, 3s);
        events.ScheduleEvent(EVENT_HEAL, 8s);
        events.ScheduleEvent(EVENT_PENANCE_HEAL, 13s);
        events.ScheduleEvent(EVENT_PENANCE_DAMAGE, 18s);
    }

    void MoveInLineOfSight(Unit* u) override
    {
        if (Creature* frida = me->FindNearestCreature(NPC_FRIDA_IRONBELLOWS, 100.0f, true))
        {
            if (me->GetDistance2d(frida) <= 30.0f)
            {
                if (frida->HasAura(AURA_OF_RETRIBUTION))
                {
                    if (!me->HasAura(AURA_OF_RETRIBUTION))
                    {
                        me->AddAura(AURA_OF_RETRIBUTION);
                    }
                }
                else
                {
                    if (me->HasAura(AURA_OF_RETRIBUTION))
                    {
                        me->RemoveAura(AURA_OF_RETRIBUTION);
                    }
                }
            }
        }
    }

    void JustDied(Unit* u) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (Creature* frida = me->FindNearestCreature(NPC_FRIDA_IRONBELLOWS, 100.0f, true))
            frida->AddAura(ZEALOTRY);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case EVENT_DIVINE_BURST:
             me->StopMoving();
             DoCastRandom(DIVINE_BURST, 100.0f);
             events.Repeat(15s);
             break;

        case EVENT_HEAL:
             me->StopMoving();
             DoCast(HEAL_SP);
             events.Repeat(20s);
             break;

        case EVENT_PENANCE_HEAL:
             me->StopMoving();
             if (Creature* crusader = me->FindNearestCreature(NPC_DARKFORGED_CRUSADER, 100.0f, true))
             {
                 if (crusader->HealthBelowPct(99))
                 {
                     me->CastSpell(crusader, PENANCE_HEAL);
                 }
             }
             events.Repeat(25s);
             break;

        case EVENT_PENANCE_DAMAGE:
             me->StopMoving();
             DoCastRandom(PENANCE_DAMAGE, 500.0f, true);
             events.Repeat(30s);
             break;
        }
    }
};

//19808
struct at_wave_of_light : public AreaTriggerAI
{
    at_wave_of_light(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnInitialize() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Position pos = caster->GetPosition();

        at->MovePosition(pos, 30.0f, 0.0f);
        at->SetDestination(pos, 8000);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsCreature())
        {
            switch (unit->GetEntry())
            {
            case NPC_DARKFORGED_CRUSADER:
            case NPC_ANOINTED_DISCIPLE:
            case NPC_ZANDALARI_CRUSADER:
            case NPC_REZANI_DISCIPLE:
                if (!unit->HasAura(WAVE_OF_LIGHT_HEAL))
                    at->GetCaster()->AddAura(WAVE_OF_LIGHT_HEAL, unit);
                break;
            }
        }

        if (unit->IsPlayer() && !unit->HasAura(WAVE_OF_LIGHT_PERIODIC))
            at->GetCaster()->CastSpell(unit, WAVE_OF_LIGHT_PERIODIC, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->IsCreature())
        {
            switch (unit->GetEntry())
            {
            case NPC_DARKFORGED_CRUSADER:
            case NPC_ANOINTED_DISCIPLE:
            case NPC_ZANDALARI_CRUSADER:
            case NPC_REZANI_DISCIPLE:
                if (unit->HasAura(WAVE_OF_LIGHT_HEAL))
                    unit->RemoveAura(WAVE_OF_LIGHT_HEAL);
                break;
            }
        }
    }
};

//19808
struct at_consecration : public AreaTriggerAI
{
    at_consecration(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsCreature())
        {
            switch (unit->GetEntry())
            {
            case NPC_DARKFORGED_CRUSADER:
            case NPC_ANOINTED_DISCIPLE:
            case NPC_ZANDALARI_CRUSADER:
            case NPC_REZANI_DISCIPLE:
                if (!unit->HasAura(CONSECRATION_REDUCE_DAMAGE))
                    at->GetCaster()->AddAura(CONSECRATION_REDUCE_DAMAGE, unit);
                break;
            }
        }

        if (unit->IsPlayer() && !unit->HasAura(CONSECRATION_DAMAGE))
            at->GetCaster()->AddAura(CONSECRATION_DAMAGE, unit);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->IsPlayer() && unit->HasAura(CONSECRATION_DAMAGE))
            unit->RemoveAura(CONSECRATION_DAMAGE);
    }
};

void AddSC_boss_frida_ironbellows()
{
    RegisterCreatureAI(boss_frida_ironbellows);
    RegisterCreatureAI(npc_darkforged_crusader_145903);
    RegisterCreatureAI(npc_antoined_disciple_145898);
    RegisterAreaTriggerAI(at_wave_of_light);
    RegisterAreaTriggerAI(at_consecration);
}
