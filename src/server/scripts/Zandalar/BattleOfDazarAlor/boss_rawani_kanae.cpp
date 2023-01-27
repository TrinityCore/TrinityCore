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

const Position adds_pos = { -2023.0f, 833.0f, 6.0f, 4.73f };

enum Texts
{
    //VO_81_Zandalari_Paladin
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
    PERIODIC_ENERGY_GAIN = 295065, // 2 every 800ms
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
    CRUSADER_STRIKE = 283637,
    DIVINE_MALLET = 287439,
    DIVINE_MALLET_AT = 282074,
    WAVE_OF_LIGHT_HEALING = 283619,
    EVENT_CRUSADER_STRIKE = 1,
    EVENT_CONSECRATION,
    EVENT_DIVINE_MALLET,
    EVENT_BLINDING_FAITH,    
};

//144683
struct boss_rawani_kanae : public BossAI
{
    boss_rawani_kanae(Creature* creature) : BossAI(creature, DATA_RAWANI_KANAE) { }

    void Reset() override
    {        
        BossAI::Reset();
        me->RemoveAura(PERIODIC_ENERGY_GAIN);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);
        me->AddAura(SACRED_BLADE);
        intro = false;
        hp60 = false;
        hp30 = false;
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
            me->GetCreatureListWithEntryInGrid(encounterNPCs, NPC_ZANDALARI_CRUSADER, 100.0f);
            me->GetCreatureListWithEntryInGrid(encounterNPCs, NPC_REZANI_DISCIPLE, 100.0f);
            for (auto& minions : encounterNPCs)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, minions);
                if (!minions->IsInCombat())
                    minions->AI()->DoZoneInCombat(nullptr);
            }
        }
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
        me->GetCreatureListWithEntryInGrid(encounterNPCs, NPC_ZANDALARI_CRUSADER, 100.0f);
        me->GetCreatureListWithEntryInGrid(encounterNPCs, NPC_REZANI_DISCIPLE, 100.0f);
        for (auto& minions : encounterNPCs)
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, minions);
            minions->NearTeleportTo(minions->GetHomePosition());
            minions->ForcedDespawn(0, 5s);
        }

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
       me->DespawnCreaturesInArea(NPC_ZANDALARI_CRUSADER, 125.0f);
       me->DespawnCreaturesInArea(NPC_REZANI_DISCIPLE, 125.0f);
       me->SummonCreature(NPC_CUSTOM_LIONS_ROAR_TANK, -2185.024f, 803.182f, 5.932f, 0.048f, TEMPSUMMON_MANUAL_DESPAWN);
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
           if (Creature* crusader = me->FindNearestCreature(NPC_ZANDALARI_CRUSADER, 500.0f, true))
               me->CastSpell(crusader, JUDGMENT_RIGHTEOUSNESS);

           break;
       }
       case 1:
       {
           if (Creature* disciple = me->FindNearestCreature(NPC_REZANI_DISCIPLE, 500.0f, true))
               me->CastSpell(disciple, JUDGMENT_RIGHTEOUSNESS);

           break;
       }
       default:
           break;
       }
   }
   
   void OnSpellFinished(SpellInfo const* spellInfo) 
   {
       if (spellInfo->Id == CALL_TO_ARMS)
       {
           me->SummonCreature(NPC_ZANDALARI_CRUSADER, adds_pos, TEMPSUMMON_MANUAL_DESPAWN);
           me->SummonCreature(NPC_REZANI_DISCIPLE, adds_pos, TEMPSUMMON_MANUAL_DESPAWN);
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
            if (Creature* crusader = me->FindNearestCreature(NPC_ZANDALARI_CRUSADER, 100.0f, true))
            {
                if (crusader->HealthBelowPct(99) && !crusader->HasAura(DIVINE_PROCTECTION_REDUCTION)) 
                    crusader->AddAura(DIVINE_PROCTECTION_REDUCTION);
            }
            if (Creature* disciple = me->FindNearestCreature(NPC_REZANI_DISCIPLE, 100.0f, true))
            {
                if (disciple->HealthBelowPct(99) && !disciple->HasAura(DIVINE_PROCTECTION_REDUCTION))      
                    disciple->AddAura(DIVINE_PROCTECTION_REDUCTION);
            }
            events.Repeat(15s);
            break;
        }
        case EVENT_WAVE_OF_LIGHT:
        {
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
             me->GetCreatureListWithEntryInGrid(c_li, NPC_REZANI_DISCIPLE, 250.0f);
             for (auto& disciples : c_li)
             {             
                 disciples->StopMoving();
                 disciples->CastSpell(disciples, ANGELIC_RENEWAL, false);
             }
             std::list<Creature*> c_li_2;
             me->GetCreatureListWithEntryInGrid(c_li_2, NPC_ZANDALARI_CRUSADER, 250.0f);
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

//147896
struct npc_zandalari_crusader_147896 : public ScriptedAI
{
    npc_zandalari_crusader_147896(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterCombat(Unit * u) override
    {
        //instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_CRUSADER_STRIKE, 3s);
        events.ScheduleEvent(EVENT_CONSECRATION, 8s);
        events.ScheduleEvent(EVENT_BLINDING_FAITH, 13s);
        events.ScheduleEvent(EVENT_DIVINE_MALLET, 18s);
    }

    void MoveInLineOfSight(Unit* u) override
    {
        if (Creature* rawani = me->FindNearestCreature(NPC_RAWANI_KANAE, 100.f, true))
        {
            if (me->GetDistance2d(rawani) <= 30.0f)
            {
                if (rawani->HasAura(AURA_OF_RETRIBUTION))
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
        if (Creature* frida = me->FindNearestCreature(NPC_RAWANI_KANAE, 100.0f))
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

//147895
struct npc_rezani_disciple_147895 : public ScriptedAI
{
    npc_rezani_disciple_147895(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterCombat(Unit* u) override
    {
        //instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_DIVINE_BURST, 3s);
        events.ScheduleEvent(EVENT_HEAL, 8s);
        events.ScheduleEvent(EVENT_PENANCE_HEAL, 13s);
        events.ScheduleEvent(EVENT_PENANCE_DAMAGE, 18s);
    }

    void MoveInLineOfSight(Unit* u) override
    {
        if (Creature* rawani = me->FindNearestCreature(NPC_RAWANI_KANAE, 100.0f))
        {
            if (me->GetDistance2d(rawani) <= 30.0f)
            {
                if (rawani->HasAura(AURA_OF_RETRIBUTION))
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
        if (Creature* frida = me->FindNearestCreature(NPC_RAWANI_KANAE, 100.0f))
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
             if (Creature* crusader = me->FindNearestCreature(NPC_ZANDALARI_CRUSADER, 100.0f, true))
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

//500522
struct npc_lions_roar : public ScriptedAI
{
    npc_lions_roar(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        ScriptedAI::Reset();        
    }

    void MovementInform(uint32 type, uint32 point) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (point == 1)
        {            
            me->GetMotionMaster()->Clear(true);
        }
        if (point == 2)
        {
            me->GetMotionMaster()->Clear(true);
            me->DespawnOrUnsummon(3s);
        }
    }

    void IsSummonedBy(Unit* summoner) override
    {
        me->SetFaction(84);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
        me->SetWalk(false);
        me->GetMotionMaster()->MovePoint(1, -2022.489f, 774.871f, 5.931f, true);
        me->GetScheduler().Schedule(8s, [this] (TaskContext context)
        {
            if (auto* collision1 = me->FindNearestGameObject(GO_RAWANI_COLLISION_1, 100.0f))
                collision1->RemoveFromWorld();
            if (auto* collision2 = me->FindNearestGameObject(GO_RAWANI_COLLISION_2, 100.0f))
               collision2->RemoveFromWorld();
            if (auto* collision3 = me->FindNearestGameObject(GO_RAWANI_COLLISION_3, 100.0f))
                collision3->RemoveFromWorld();
            std::list<Creature*> stalker_li;
            me->GetCreatureListWithEntryInGrid(stalker_li, NPC_BARRIER_DESTRUCTION_STALKER, 100.0f);
            for (auto& stalkers : stalker_li)
            stalkers->DespawnOrUnsummon();

            std::list<Creature*> u_li;
            me->GetCreatureListWithEntryInGrid(u_li, NPC_RASTAFARI_ENFORCER, 95.0f);
            me->GetCreatureListWithEntryInGrid(u_li, NPC_RASTAFARI_FLAMESPEAKER, 95.0f);
            for (auto& creatures : u_li)
            {
                if (Unit* units = creatures->ToUnit())
                    units->KillSelf();
            }

            me->GetMotionMaster()->MovePoint(2, -2020.807f, 688.250f, 5.932f, true);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

void AddSC_boss_rawani_kanae()
{
    RegisterCreatureAI(boss_rawani_kanae);
    RegisterCreatureAI(npc_zandalari_crusader_147896);
    RegisterCreatureAI(npc_rezani_disciple_147895);
    RegisterCreatureAI(npc_lions_roar);
}
