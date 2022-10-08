#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "MotionMaster.h"
#include "battle_of_dazaralor.h"

const Position living_bomb_pos_a = { -1853.448f, 778.556f, 53.784f, 0.025f };
const Position living_bomb_pos_b = { -1811.786f, 801.702f, 53.390f, 0.033f };
const Position living_bomb_pos_c = { -1854.693f, 831.997f, 53.783f, 3.206f };
const Position at_60_energy_pos = { -905.0f, 847.0f, 369.0f, 4.6f };
const Position center_of_room = { -909.0f, 805.0f, 369.0f, 3.1f };
const Position spirit_of_xuen_pos = { -905.0f, 786.0f, 369.0f, 1.6f };
const Position magma_trap_a = { -891.0f, 818.0f, 369.0f, 3.f };
const Position magma_trap_b = { -892.0f, 810.0f, 369.0f, 3.f };
const Position magma_trap_c = { -892.0f, 798.0f, 369.0f, 3.f };
const Position magma_trap_d = { -892.0f, 798.0f, 369.0f, 3.f };
const Position manceroy_tele_pos = { -898.0f, 736.0f, 369.0f, 1.6f }; // used for barrier phase
const Position mestrah_tele_pos = { -917.0f, 733.0f, 369.0f, 1.58f }; // used for barrier phase

enum Spells
{
    PERIODIC_ENERGY_GAIN = 299956,
    //Monk
    MULTI_SIDED_STRIKE = 284028,
    SUCCESSFUL_DEFENSE = 284089,
    TESTED = 288151,
    ROLL = 109131,
    WHIRLING_JADE_STORM = 286436,
    //Mage
    FIREBALL = 282036, //cast 2s
    RISING_FLAMES = 282037, //triggers burnout, after expire/remove
    BURNOUT = 282041,
    FIRE_SHIELD = 286425,
    PYROBLAST = 286379,
    SEARING_EMBERS = 286988, //5 targets
    UNLEASHED_EMBER = 286989,
    //Team attacks
    FIRE_FROM_MIST = 285428, // at 30 energy, summon two adds npc 146107, on mythic 3, they're stationary, displayid 90376
    BEAM_DAMAGE_AURA = 286503,
    EXPLOSION = 284399,
    //A Flash of Hostility used by Monk, at 60 energy, 
    //BARRIER npc, 147374, displayid 90015
    FLASH_OF_PHOENIXES = 284669,
    RING_OF_HOSTILITY_MESTRAH_PERIODIC_DUMMY = 297568,
    RING_OF_HOSTILITY_KNOCKBACK = 284146,
    PHOENIX_STRIKE_MISSILE = 282043,
    PHOENIX_STRIKE_DAMAGE = 284388,
    //Transmorms, at 100 energy, both bosses transform
    DRAGONS_BREATH = 286396,
    BLAZING_PHOENIX_TRANSFORM = 282040, //npc 147536, 89730 displayid    
    SPIRITS_OF_XUEN = 285645,
    TIGER_PAW = 285634,
    POUNCE = 286086,
    MAGMA_TRAP_MISSILE_TRIGGER = 284373, //on spellhitdest summon trap, spell 282038
    MAGMA_TRAP_KNOCK = 284374,
    MAGMA_TRAP_2 = 98170,
    FORCE_ORB_REDUCE_MOVEMENT_SPEED = 287747,
    PATH_OF_NIUAZUO_SUMMON = 287623, // npc 148344
    PATH_OF_NIUAZUO_AT_DAMAGE = 287615
};

enum Events
{
    EVENT_WHIRLING_JADE_STORM = 1,
    EVENT_FIREBALL,
    EVENT_PYROBLAST,
    EVENT_SEARING_EMBERS,
    EVENT_FIRE_FROM_MIST,
    EVENT_A_FLASH_OF_HOSTILITY,
    EVENT_MARA_GRIMFANG_TRANSFORM,
    EVENT_ANATHOS_FIRECALLER_TRANSFORM,
    EVENT_DRAGONS_BREATH,
    EVENT_MAGMA_TRAPS,
    EVENT_SPIRITS_OF_XUEN,
    EVENT_RISING_FLAMES,
    EVENT_SPIRITS_OF_NIUZAO,
    EVENT_CHECK_BARRIER
};

//148238,146100
struct boss_jadefire_masters_horde : public BossAI
{
    boss_jadefire_masters_horde(Creature* creature) : BossAI(creature, DATA_JADEFIRE_MASTERS_HORDE) 
    { 
        this->deathCount = 0;
    }

private:
    uint8 deathCount;

    void Reset() override
    {
        BossAI::Reset();
        me->SetPowerType(POWER_ENERGY);
        me->RemoveAura(PERIODIC_ENERGY_GAIN);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
        me->DespawnCreaturesInArea(NPC_MAGMA_TRAP_BOD, 125.0f);
        me->DespawnCreaturesInArea(NPC_SPIRIT_OF_XUEN, 125.0f);
        instance->DoRemoveAurasDueToSpellOnPlayers(MAGMA_TRAP_KNOCK);
        instance->DoRemoveAurasDueToSpellOnPlayers(285632);
        me->NearTeleportTo(me->GetHomePosition());
        me->ClearUnitState(UNIT_STATE_ROOT);
        if (me->GetEntry() == NPC_ANATHOS_FIRECALLER)
            me->AddAura(AURA_OVERRIDE_POWER_COLOR_ENTROPIC);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        switch (me->GetEntry())
        {
        case NPC_MARA_GRIMFANG:
            //me->SetNativeDisplayId(89013, 1.5f);
            if (Creature* mara = me->FindNearestCreature(NPC_MARA_GRIMFANG, 100.0f))
            {
                if (mara->isDead())
                {
                    mara->Respawn();
                    mara->NearTeleportTo(mara->GetHomePosition());
                }
            }
            break;

        case NPC_ANATHOS_FIRECALLER:
            //me->SetNativeDisplayId(89012, 1.5f);
            if (Creature* anathos = me->FindNearestCreature(NPC_ANATHOS_FIRECALLER, 100.0f))
            {
                if (anathos->isDead())
                {
                    anathos->Respawn();
                    anathos->NearTeleportTo(anathos->GetHomePosition());
                }
            }
            break;
        }
    }

    void EnterCombat(Unit* /*unit*/) override
    {
        switch (me->GetEntry())
        {
        case NPC_MARA_GRIMFANG:
            _EnterCombat();
            Talk(0);
            DoCast(PERIODIC_ENERGY_GAIN);
            events.ScheduleEvent(EVENT_WHIRLING_JADE_STORM, 3s);
            events.ScheduleEvent(EVENT_SPIRITS_OF_XUEN, 20s);
            //events.ScheduleEvent(EVENT_A_FLASH_OF_HOSTILITY, 60s);            
            if (Creature* mara = me->FindNearestCreature(NPC_MANCEROY_FLAMEFIST, 100.0f, true))
            {
                if (mara->IsInCombat())
                    return;
                else
                    mara->AI()->DoZoneInCombat(nullptr, 250.0f);
            }
            this->barrier_count = 0;
            break;

        case NPC_ANATHOS_FIRECALLER:
            _EnterCombat();
            me->GetScheduler().Schedule(4s, [this](TaskContext context)
            {
                Talk(0);
            });
            DoCast(PERIODIC_ENERGY_GAIN);
            events.ScheduleEvent(EVENT_FIREBALL, 1s);
            events.ScheduleEvent(EVENT_PYROBLAST, 15s);
            events.ScheduleEvent(EVENT_SEARING_EMBERS, 20s);
            events.ScheduleEvent(EVENT_MAGMA_TRAPS, 25s);
            events.ScheduleEvent(EVENT_FIRE_FROM_MIST, 30s);
            //events.ScheduleEvent(EVENT_A_FLASH_OF_HOSTILITY, 60s);
            if (Creature* mara = me->FindNearestCreature(NPC_MARA_GRIMFANG, 100.0f, true))
            {
                if (mara->IsInCombat())
                    return;
                else
                    mara->AI()->DoZoneInCombat(nullptr, 250.0f);
            }
            break;
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer() && roll_chance_f(15))
        {
            switch (me->GetEntry())
            {
            case NPC_MARA_GRIMFANG:
                Talk(6);
                break;

            case NPC_ANATHOS_FIRECALLER:
                Talk(6);
                break;
            }
        }
    }

   void OnSpellFinished(SpellInfo const* spellInfo) override
   {
       if (spellInfo->Id == BLAZING_PHOENIX_TRANSFORM)
       {
       }      
   }

   void SpellHitDest(SpellDestination const* dest, SpellInfo const* spellInfo)
   {
       if (spellInfo->Id == MAGMA_TRAP_MISSILE_TRIGGER)
       {       
       }
   }

   void JustDied(Unit* /*who*/) override
   {
       _JustDied();
       deathCount++;
       if (this->deathCount == 2)
           instance->DoPlayScenePackageIdOnPlayers(SCENE_BLOOD_MOON_RISING);
   }

   void JustSummoned(Creature* summon) override
   {
       switch (summon->GetEntry())
       {
       case NPC_LIVING_BOMB_BOD:
            me->SetReactState(REACT_PASSIVE);
            summon->AI()->DoCastAOE(EXPLOSION);
            break;

       case NPC_MAGMA_TRAP_BOD:   
            summon->SetReactState(REACT_PASSIVE);
            break;

       case NPC_SPIRIT_OF_XUEN:            
            if (Unit* tar = SelectTarget(SELECT_TARGET_FARTHEST, 0, 500.0f, true))
            {
                 summon->GetMotionMaster()->MoveChase(tar, 500.0f, PET_FOLLOW_ANGLE);
                 summon->AI()->AttackStart(tar);
                 summon->AddThreat(tar, 1000.0f, SpellSchoolMask::SPELL_SCHOOL_MASK_NORMAL);
                 if (tar->HasAura(285632))
                     return;
                 else
                     summon->AddAura(285632, tar); //Stalking            
            }    
            break;
       }
   }

   void ExecuteEvent(uint32 eventId) override
   {
       if (me->GetPower(POWER_ENERGY) == 100)
       {
           switch (me->GetEntry())
           {
           case NPC_MESTRAH:
                me->SetPower(POWER_ENERGY, 0);
                events.ScheduleEvent(EVENT_MARA_GRIMFANG_TRANSFORM, 100ms);
                break;

           case NPC_MANCEROY_FLAMEFIST:
                me->SetPower(POWER_ENERGY, 0);
                events.ScheduleEvent(EVENT_ANATHOS_FIRECALLER_TRANSFORM, 100ms);
                break;
           }

       }
       switch (eventId)
       {
       case EVENT_WHIRLING_JADE_STORM:
       {
           if (Creature* stalker = me->FindNearestCreature(500504, 100.0f, true))
           {
               me->AttackStop();
               me->CastStop();
               me->SetReactState(REACT_PASSIVE);
               me->CastSpell(stalker, ROLL);
               me->GetScheduler().Schedule(1s, [this] (TaskContext context)
               {
                    me->SetReactState(REACT_DEFENSIVE);
                    DoCastAOE(WHIRLING_JADE_STORM);
               });
           }
           events.Repeat(15s);
           break;
       }
       case EVENT_FIREBALL:
       {
            DoCastVictim(FIREBALL);
            events.Repeat(3s);
            break;
       }
       case EVENT_PYROBLAST:
       {
           me->AddAura(FIRE_SHIELD);
           DoCastRandom(PYROBLAST, 300.0f);
           events.Repeat(20s);
           break;
       }
       case EVENT_SEARING_EMBERS:
       {          
           if (me->GetNativeDisplayId())
           {
               Talk(0);
               UnitList tarlist;
               SelectTargetList(tarlist, 5, SELECT_TARGET_RANDOM, 100.0f, true);
               for (Unit* tar : tarlist)
               DoCast(tar, SEARING_EMBERS);
           }      
           events.Repeat(25s);
           break;
       }
       case EVENT_FIRE_FROM_MIST:
       {
           //Talk(3);
           if (me->GetPower(POWER_ENERGY) == 30)
           {
               if (IsMythic())
               {
                   me->SummonCreature(NPC_LIVING_BOMB_BOD, living_bomb_pos_a, TEMPSUMMON_MANUAL_DESPAWN);
                   me->SummonCreature(NPC_LIVING_BOMB_BOD, living_bomb_pos_b, TEMPSUMMON_MANUAL_DESPAWN);
                   me->SummonCreature(NPC_LIVING_BOMB_BOD, living_bomb_pos_c, TEMPSUMMON_MANUAL_DESPAWN);
               }
               else
               {
                   me->SummonCreature(NPC_LIVING_BOMB_BOD, living_bomb_pos_a, TEMPSUMMON_MANUAL_DESPAWN);
                   me->SummonCreature(NPC_LIVING_BOMB_BOD, living_bomb_pos_b, TEMPSUMMON_MANUAL_DESPAWN);
               }
           }       
       }
       case EVENT_A_FLASH_OF_HOSTILITY:
       {    
           Talk(4);
           switch (me->GetEntry())
           {
           case NPC_ANATHOS_FIRECALLER:
                if (me->GetPower(POWER_ENERGY) >= 60)
                {
                }                
                break;

           case NPC_MARA_GRIMFANG:
                me->AddAura(RING_OF_HOSTILITY_MESTRAH_PERIODIC_DUMMY);
                break;
           }
       }
       case EVENT_MARA_GRIMFANG_TRANSFORM:
       {
           if (me->GetPower(POWER_ENERGY) == 100)
           {
               events.Reset();
               events.CancelEvent(EVENT_WHIRLING_JADE_STORM);
               if (me->GetNativeDisplayId())
               {
                   Talk(5);
                   me->SetDisplayId(46087);
                   events.ScheduleEvent(EVENT_DRAGONS_BREATH, 3s);
               }               
           }
           break;
       }
       case EVENT_ANATHOS_FIRECALLER_TRANSFORM:
       {
           Talk(5);
           events.Reset();
           events.CancelEvent(EVENT_FIREBALL);
           events.CancelEvent(EVENT_PYROBLAST);
           events.CancelEvent(EVENT_SEARING_EMBERS);
           if (me->GetPower(POWER_ENERGY) == 100)
           {
               if (me->GetNativeDisplayId())
               {
                   //DoCast(BLAZING_PHOENIX_TRANSFORM);
                   me->SetDisplayId(89730);                   
                   me->AddAura(282040);
                   me->SetObjectScale(2.0f);
                   events.ScheduleEvent(EVENT_RISING_FLAMES, 3s);
                   events.ScheduleEvent(EVENT_MAGMA_TRAPS, 8s);
               }               
           }          
       }
       break;

       case EVENT_DRAGONS_BREATH:
       {           
           DoCastRandom(DRAGONS_BREATH, 100.0f);
           events.Repeat(15s);
           break;
       }

       case EVENT_RISING_FLAMES:
       {
           DoCastVictim(RISING_FLAMES);
           events.Repeat(3s);
           break;
       }

       case EVENT_MAGMA_TRAPS:
       {           
           if (me->GetNativeDisplayId())
               Talk(0);

           for (uint8 i = 0; i < 3; i++)
           {
               me->SummonCreature(NPC_MAGMA_STALKER, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
           }

           std::list<Creature*> c_li;
           me->GetCreatureListWithEntryInGrid(c_li, NPC_MAGMA_STALKER, 500.0f);
           for (auto& stalkers : c_li)
           me->AI()->DoCast(stalkers, MAGMA_TRAP_2);
           events.Repeat(35s);
           break;
       }

       case EVENT_SPIRITS_OF_XUEN:
       {
           Talk(2);
           if (IsMythic())
           {
               me->SummonCreature(NPC_SPIRIT_OF_XUEN, me->GetRandomNearPosition(10), TEMPSUMMON_MANUAL_DESPAWN);
               me->SummonCreature(NPC_SPIRIT_OF_XUEN, me->GetRandomNearPosition(10), TEMPSUMMON_MANUAL_DESPAWN);
           }
           else
           {
               me->SummonCreature(NPC_SPIRIT_OF_XUEN, me->GetRandomNearPosition(10), TEMPSUMMON_MANUAL_DESPAWN);
           }           
           events.Repeat(30s);
           break;
       }

       case EVENT_CHECK_BARRIER:
       {
           if (me->FindNearestCreature(NPC_BARRIER_BOD, 500.0f, false))
           {
                barrier_count++;
           }
           if (this->barrier_count >= 3)
           {
               events.CancelEvent(EVENT_CHECK_BARRIER);
               switch (me->GetEntry())
               {
               case NPC_ANATHOS_FIRECALLER:
                    me->ClearUnitState(UNIT_STATE_ROOT);
                    if (!me->HasReactState(REACT_AGGRESSIVE))
                        me->SetReactState(REACT_AGGRESSIVE);
                    DoCast(PERIODIC_ENERGY_GAIN);
                    break;

               case NPC_MARA_GRIMFANG:
                    me->ClearUnitState(UNIT_STATE_ROOT);
                    if (!me->HasReactState(REACT_AGGRESSIVE))
                        me->SetReactState(REACT_AGGRESSIVE);

                    DoCast(PERIODIC_ENERGY_GAIN);
                    break;
               }
           }
           events.Repeat(1s);
           break;
       }
       }
   }
private:
    uint8 barrier_count;
};

void AddSC_boss_jadefire_masters_horde()
{
    RegisterCreatureAI(boss_jadefire_masters_horde);
}
