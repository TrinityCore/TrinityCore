/*
* Copyright (C) 2021 ShadowCore
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuraEffects.h"
#include "castle_nathria.h"

enum SireDenathrius
{
    EVENT_GAIN_ENERGY = 1,
    SPELL_MARCH_OF_THE_PENITENT_SEND_EVENT = 328117,
	SPELL_DESOLATION_CREATE_AT = 327982, //pizza
    SPELL_DESOLATION_AT_DAMAGE = 327992,
	SPELL_MASSACRE_CREATE_LINE_AT = 330116,
    SPELL_MASSACRE_CREATE_WEAPON_AT = 330089,
    SPELL_COMMAND_RAVAGE = 327227,
    SPELL_RAVAGE_CAST_DUMMY = 327122,
    SPELL_INEVITABLE_DAMAGE = 328936,
    SPELL_INEVITABLE_TELEPORT = 328934,
    SPELL_FEEDING_TIME_MARK = 327039,
    SPELL_FEEDING_TIME_DRAIN_HEALTH = 327089, // 2 targets
    SPELL_FEEDING_TIME_SUMMON = 327085,
    SPELL_BURDEN_OF_SIN_PERIODIC_DUMMY = 326699,
    SPELL_BURDEN_OF_SIN_DAMAGE = 326700,
    SPELL_CLEANSING_PAIN_ALLLOW_CAST = 327040,
    SPELL_CLEANSING_PAIN = 326707,
    SPELL_PAINFUL_MEMORIES_CHANNEL = 326824,
    SPELL_PAINFUL_MEMORIES_DAMAGE = 326833,
    SPELL_BLOOD_PRICE_CHANNEL = 326994,
    SPELL_BLOOD_PRICE_DAMAGE = 326858,
    SPELL_BLOOD_PRICE_IMMOBILIZE = 326851,
    SPELL_BLOOD_PRICE_SUMMON = 326857,
    SPELL_BLOOD_PRICE_KNOCKBACK = 328527,
    SPELL_BLOOD_PRICE_KNOCKBACK_2 = 339188,
    SPELL_BLOOD_PRICE_EFFECT = 326988,
    //Phase 2
    SPELL_BLOODBOUND = 330580,
    SPELL_CRIMSON_CHORUS = 329711,
    SPELL_WRACKING_PAIN_ALLOW_CAST = 329183,
    SPELL_WRACKING_PAIN = 329181,
    SPELL_CARNAGE = 329875,
    SPEL_CARNAGE_PERIODIC = 329906,
    SPELL_IMPALE_MARK = 329951,
    SPELL_IMPALE_DAMAGE = 329974,
    SPELL_COMMAND_MASSACRE = 330042,
    SPELL_CRIMSON_CHORUS_PERIODIC_DAMAGE = 329785,
    SPEL_HAND_OF_DESTRUCTION_CAST = 333932,
    SPELL_HAND_OF_DESTRUCTION_DAMAGE = 330627,
    SPELL_DUSK_ELEGY = 335875,
    //Phase 3
    SPELL_INDIGNATION = 326005,
    SPELL_INDIGNATION_CREATE_AT = 332746, // 20841
    SPELL_SHATTERING_PAIN_ALLOW_CAST = 333223,
    SPELL_SHATTERING_PAIN_TRIGGER = 332619,
    SPELL_SHATTERING_PAIN_KNOCKBACK_BOSS = 332621,
    SPELL_SHATTERING_PAIN_DAMAGE_KNOCK = 332626,
    SPELL_SHATTER_PAIN_KNOCKBACK_FOR_TARGETS = 339148,
    SPELL_SHATTERING_PAIN_DAMAGE = 332620,
    SPELL_FATAL_FINESSE_PERIODIC_DAMAGE = 332797,
    SPELL_FATAL_FINESSE_SUMMON = 332795,
    SPELL_SINISTER_REFLECTION = 333979,
    SPELL_SINISTER_REFLECTION_CHANGE_MODEL = 332909,
    //Heroic
    SPELL_NIGHT_HUNTER_MISSILE = 334873,
    SPELL_NIGHT_HUNTER_DAMAGE = 327810,
    SPELL_NIGHT_HUNTER_MARK = 327796,
    SPELL_NIGHT_HUNTER_DUMMY = 332213,
    SPELL_RANCOR_CREATE_AREATRIGGER = 335872, //21186
    SPELL_RANCOR_AT_DAMAGE = 335873,
    SPELL_CRESCENDO_MISSILE = 336161,
    SPELL_SMOLDERING_IRE_CREATE_AT = 335997, // 21199, used for dmg?
    SPELL_SMOLDERING_IRE_CREATE_AT_2 = 336000, //21200
    SPELL_SMOLDERING_IRE_SCRIPT_EFFECT = 336004,
    SPELL_SMOLDERING_IRE_DAMAGE = 336008,
    //Mythic
    SPELL_COLLECTIVE_TRAUMA_DAMAGE = 338582,
    SPELL_SPITEFUL = 338510,
    ACTION_INIT_PHASE_2 = 1,
    ACTION_INIT_NIGHTCLOAK,
    ACTION_REMORNIA_EVENTS,
    ACTION_INIT_PHASE_3,
    SPELL_THROUGH_THE_MIRROR_MOD_PHASE = 338738,
    //Sinsear
    SPELL_NATHRIAN_HYMN_SINSEAR_CHANNEL = 341728, //peri dummy
    SPELL_NATHRIAN_HYMN_SINSEAR_DAMAGE = 338683,
    SPELL_NATHRIAN_HYMN_SINSEAR_MOD_DAMAGE_TAKEN = 341730,
    SPELL_NATHRIAN_HYMN_SINSEAR_PERI_DUMMY = 341728,
    SPELL_SINSEAR_SEARING_CENSURE = 341391, //peri dummy
    SPELL_SINSEAR_SEARING_CENSURE_CREATE_AT = 341419, //21707
    SPELL_SINEAR_SEARING_CENSURE_CREATE_AT_TWO = 341733, //21745
    SPELL_SINSEAR_SEARING_CENSURE_DAMAGE_SILENCE = 341732,
    //Evershade
    SPELL_NATHRIAN_HYMN_EVERSHADE_CHANNEL = 338684,
    SPELL_NATHRIAN_HYMN_EVERSHADE_DAMAGE = 338685,
    SPELL_NATHRIAN_HYMN_EVERSHADE_MOD_DAMAGE_TAKEN = 341651,
    SPELL_NATHRIAN_HYMN_EVERSHADE_PERI_DUMMY = 341648,
    SPELL_BALEFUL_SHADOWS_DUMMY = 344313,
    SPELL_EVERSHADE_BALEFUL_SHADOW_SUMMON = 345558,
    SPELL_VENGEFUL_WAIL = 344776,
    //Duskhollow
    SPELL_NATHRIAN_HMYN_DUSKHOLLOW_CHANNEL = 341637,
    SPELL_NATHRIAN_HYMN_DUSKHOLLOW_DAMAGE = 338687,
    SPELL_NATHRIAN_HYMN_DUSKHOLLOW_MOD_DAMAGE_TAKEN = 341638,
    SPELL_NATHRIAN_HYMN_DUSKHOLLOW_PERI_DUMMY = 338686,
    SPELL_HOLLOW_GRASP_DUMMY = 341366,
    //Gloomveil
    SPELL_NATHRIAN_HYMN_GLOOMVEIL_CHANNEL = 341715,
    SPELL_NATHRIAN_HYMN_GLOOMVEIL_DAMAGE = 338689,
    SPELL_NATHRIAN_HYMN_GLOOMVEIL_PERI_DUMMY = 338688,
    SPELL_NATHRIAN_HYMN_GLOOMVEIL_MOD_DAMAGE_TAKEN = 341714,
    SPELL_GLOOM_VEIL_AURA = 340687,
    SPELL_GLOOM_VEIL_CREATE_AT = 340685, //21663
    SPELL_GLOOM_VEIL_CREAT_AT_TWO = 341720, //21744
};

//167406
struct boss_sire_denathrius : public BossAI
{
    boss_sire_denathrius(Creature* creature) : BossAI(creature, DATA_SIRE_DENATHRIUS) { }

private:
    bool introConversation;
    bool intermission;
    bool stage_two;
    bool stage_three;

    void Reset() override
    {
        BossAI::Reset();
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetPowerType(POWER_ENERGY);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
       // me->AddAura(AURA_OVERRIDE_POWER_COLOR_RAGE);
        introConversation = false;
        intermission = false;
        stage_two = false;
        me->LoadEquipment(2, true);
    }

    Creature* GetRemornia()
    {
        return me->FindNearestCreature(NPC_REMORNIA, 250.0f, true);
    }

    Creature* RemorniaIsDead()
    {
        return me->FindNearestCreature(NPC_REMORNIA, 250.0f, false);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        events.ScheduleEvent(EVENT_GAIN_ENERGY, 1s);
        events.ScheduleEvent(SPELL_CLEANSING_PAIN, 5s);
        events.ScheduleEvent(SPELL_FEEDING_TIME_MARK, 13s);
        events.ScheduleEvent(SPELL_BLOOD_PRICE_CHANNEL, 20s);
        std::list<Player*> playerList;
        me->GetPlayerListInGrid(playerList, 100.0f);
        for (Player* players : playerList)
        {
            players->AddAura(SPELL_BURDEN_OF_SIN_PERIODIC_DUMMY);
            if (Aura* burdenSin = players->GetAura(SPELL_BURDEN_OF_SIN_PERIODIC_DUMMY))
                burdenSin->SetStackAmount(4);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        //Ravage
        if (me->GetPower(POWER_ENERGY) == 100 && !stage_two)
        {
            me->SetPower(POWER_ENERGY, 0);
            me->CastSpell(nullptr, SPELL_COMMAND_RAVAGE, false);
        }
        //Massacre
        if (me->GetPower(POWER_ENERGY) == 100 && stage_two)
        {
            me->SetPower(POWER_ENERGY, 0);
            me->StopMoving();
            me->CastSpell(nullptr, SPELL_COMMAND_MASSACRE, false);
        }
        //Sinister Reflection
        if (me->GetPower(POWER_ENERGY) == 100 && stage_three)
        {
            me->SetPower(POWER_ENERGY, 0);
            me->StopMoving();
            me->CastSpell(nullptr, SPELL_SINISTER_REFLECTION, false);
        }
        switch (eventId)
        {
        case EVENT_GAIN_ENERGY:
            me->ModifyPower(POWER_ENERGY, +2);
            events.Repeat(1s);
            break;

        case SPELL_CLEANSING_PAIN:
            me->AddAura(SPELL_CLEANSING_PAIN_ALLLOW_CAST);
            DoCastVictim(SPELL_CLEANSING_PAIN, false);
            events.Repeat(25s);
            break;

        case SPELL_FEEDING_TIME_MARK:
        {
            if (!IsHeroic() || !IsMythic())
            {
                UnitList targetList;
                SelectTargetList(targetList, 3, SELECT_TARGET_RANDOM, 100.0f, true);
                for (Unit* targets : targetList)
                {
                    me->CastSpell(targets, SPELL_FEEDING_TIME_MARK, true);
                    targets->GetScheduler().Schedule(5100ms, [this, targets](TaskContext /*context*/)
                    {
                        if (!targets)
                            return;

                        for (uint8 i = 0; i < 2; i++)
                        {
                            me->CastSpell(nullptr, SPELL_FEEDING_TIME_SUMMON, true);
                        }

                        me->CastSpell(targets, SPELL_FEEDING_TIME_DRAIN_HEALTH, true);
                    });
                }
            }
            else
            {
                UnitList targetList;
                SelectTargetList(targetList, 3, SELECT_TARGET_RANDOM, 100.0f, true);
                for (Unit* targets : targetList)
                {
                    me->AddAura(SPELL_NIGHT_HUNTER_MARK, targets);
                    targets->GetScheduler().Schedule(6100ms, [this, targets](TaskContext /*context*/)
                    {
                        if (!targets)
                            return;

                        targets->CastSpell(nullptr, SPELL_NIGHT_HUNTER_MISSILE, true);
                        me->CastSpell(targets, SPELL_NIGHT_HUNTER_DAMAGE, true);
                    });
                }
            }
        }

        case SPELL_BLOOD_PRICE_CHANNEL:
        {
            me->CastSpell(nullptr, SPELL_BLOOD_PRICE_CHANNEL, false);
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 100.0f);
            for (Player* players : playerList)
            {
                players->GetMotionMaster()->MoveCharge(players->GetPositionX(), players->GetPositionY(), players->GetPositionZ() == 4720.046f, 100.0f);
                me->AddAura(SPELL_BLOOD_PRICE_IMMOBILIZE, players);
                players->GetScheduler().Schedule(3600ms, [this, players](TaskContext /*context*/)
                {
                    if (!players)
                        return;

                    me->CastSpell(players, SPELL_BLOOD_PRICE_EFFECT, true);
                    me->CastSpell(players, SPELL_BLOOD_PRICE_DAMAGE, true);
                    me->CastSpell(players, SPELL_BLOOD_PRICE_KNOCKBACK, true);
                });
            }
            break;
        }

        case SPELL_WRACKING_PAIN:
            me->AddAura(SPELL_WRACKING_PAIN_ALLOW_CAST);
            DoCastVictim(SPELL_WRACKING_PAIN, false);
            events.Repeat(20s);
            break;

        case SPEL_HAND_OF_DESTRUCTION_CAST:
            me->CastSpell(nullptr, SPEL_HAND_OF_DESTRUCTION_CAST, false);
            me->SummonCreature(NPC_HAND_OF_DESTRUCTION, me->GetRandomNearPosition(15.0f), TEMPSUMMON_MANUAL_DESPAWN);
            events.Repeat(45s);
            break;

        case SPELL_INDIGNATION:
            me->CastSpell(nullptr, SPELL_INDIGNATION_CREATE_AT, true);
            me->CastSpell(nullptr, SPELL_INDIGNATION, false);
            break;

        case SPELL_SHATTERING_PAIN_TRIGGER:
            me->AddAura(SPELL_SHATTERING_PAIN_ALLOW_CAST);
            me->CastSpell(nullptr, SPELL_SHATTERING_PAIN_TRIGGER);
         //   if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 25.0f, true))
           // {
             //   me->CastSpell(target, SPELL_SHATTERING_PAIN_DAMAGE, true);
              //  me->GetScheduler().Schedule(3100ms, [this](TaskContext /*context*/)
               // {
                 //   me->CastSpell(nullptr, SPELL_SHATTERING_PAIN_DAMAGE_KNOCK, true);
               // });
           // }
           // events.Repeat(25s);
           // break;
            
        case SPELL_FATAL_FINESSE_PERIODIC_DAMAGE:
            UnitList targetList;
            SelectTargetList(targetList, (urand(3, 4)), SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->AddAura(SPELL_FATAL_FINESSE_PERIODIC_DAMAGE, targets);
                if (IsHeroic() || IsMythic())
                {
                    me->GetScheduler().Schedule(19s, [this, targets](TaskContext /*context*/)
                    {
                        if (!targets)
                            return;

                        me->CastSpell(targets, SPELL_SMOLDERING_IRE_CREATE_AT, true);
                        me->CastSpell(targets, SPELL_SMOLDERING_IRE_CREATE_AT_2, true);
                    });
                }
            }
            events.Repeat(30s);
            break;
        }
    }

    void DoAction(int32 action)
    {
        switch (action)
        {
        case ACTION_INIT_PHASE_2:
        {
            events.Reset();
            stage_two = true;
            if (Creature* remornia = GetRemornia())
            {
                remornia->NearTeleportTo(-1925.044f, -9357.142f, 4338.889f, false);
                remornia->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE));
                remornia->SetReactState(REACT_AGGRESSIVE);
                remornia->SetInCombatWithZone();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, remornia);
                remornia->AI()->DoAction(ACTION_REMORNIA_EVENTS);
            }
            me->NearTeleportTo(-1925.044f, -9357.142f, 4338.889f, false);
            events.ScheduleEvent(EVENT_GAIN_ENERGY, 1s);
            events.ScheduleEvent(SPELL_WRACKING_PAIN, 5s);
            events.ScheduleEvent(SPEL_HAND_OF_DESTRUCTION_CAST, 15s);
            const Position cabalistOnePos = { -1851.677f, -9312.821f, 4338.777f, 4.0f };
            const Position cabalistTwoPos = { -1859.526f, -9403.921f, 4338.777f, 3.43f };
            const Position cabalistThreePos = { -1944.445f, -9404.380f, 4338.777f, 0.54f };
            const Position cabalistFourPos = { -1945.439f, -9310.392f, 4338.777f, 5.96f };
            me->SummonCreature(NPC_CRIMSON_CABALIST, cabalistOnePos, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_CRIMSON_CABALIST, cabalistTwoPos, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_CRIMSON_CABALIST, cabalistThreePos, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_CRIMSON_CABALIST, cabalistFourPos, TEMPSUMMON_MANUAL_DESPAWN);
            me->GetScheduler().Schedule(5s, [this](TaskContext /*context*/)
            {
                if (!IsMythic())
                    return;

                me->AI()->DoAction(ACTION_INIT_NIGHTCLOAK);
            });
            break;
        }

        case ACTION_INIT_NIGHTCLOAK:
            me->SummonCreature(NPC_LADY_SINSEAR, -1950.330f, -9308.497f, 4338.777f, 5.50f, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_LORD_EVERSHADE, -1851.573f, -9307.436f, 4338.777f, 3.95f, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_BARON_DUSKHOLLOW, -1852.687f, -9406.740f, 4338.777f, 2.40f, TEMPSUMMON_MANUAL_DESPAWN);
            me->SummonCreature(NPC_COUNTESS_GLOOMVEIL, -1949.777f, -9406.352f, 4338.776f, 0.78f, TEMPSUMMON_MANUAL_DESPAWN);
            break;

        case ACTION_INIT_PHASE_3:
            if (Creature* remornia = GetRemornia())
                remornia->DespawnOrUnsummon();
            me->LoadEquipment(1, true);
            events.ScheduleEvent(EVENT_GAIN_ENERGY, 1s);
            events.ScheduleEvent(SPELL_INDIGNATION, 3s);
            events.ScheduleEvent(SPELL_SHATTERING_PAIN_TRIGGER, 5s);
            events.ScheduleEvent(SPEL_HAND_OF_DESTRUCTION_CAST, 10s);
            events.ScheduleEvent(SPELL_FATAL_FINESSE_PERIODIC_DAMAGE, 15s);
            events.ScheduleEvent(SPELL_BLOOD_PRICE_CHANNEL, 20s);
            break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) { }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override 
    { 
        if (me->HealthBelowPct(70) && !intermission)
        {
            intermission = true;
            events.Reset();
            me->SetReactState(REACT_PASSIVE);
            if (AreaTrigger* desolation = me->GetAreaTrigger(SPELL_DESOLATION_CREATE_AT))
                desolation->Remove();
            //me->CanFly();
            //me->SetFlying(true);
            //me->NearTeleportTo(-1901.650f, -9359.035f, 4682.766f, false);
            me->CastSpell(nullptr, SPELL_MARCH_OF_THE_PENITENT_SEND_EVENT, false);
            me->GetScheduler().Schedule(16s, [this](TaskContext /*context*/)
            {
                me->AI()->DoAction(ACTION_INIT_PHASE_2);
            });
            std::list<Player*> playerList;
            me->GetPlayerListInGrid(playerList, 100.0f);
            for (Player* players : playerList)
            {
                players->AddUnitState(UNIT_STATE_LOST_CONTROL);
                players->SetWalk(true);
                players->GetMotionMaster()->MovePoint(1, -1901.589f, -9357.918f, 4672.623f);
                players->GetScheduler().Schedule(15s, [this, players](TaskContext /*context*/)
                {                    
                    players->NearTeleportTo(-1901.375f, -9358.053f, 4671.578f, false);
                    players->ClearUnitState(UNIT_STATE_LOST_CONTROL);
                    players->SetWalk(false);
                });
            }
        }
        if (me->HealthBelowPct(40) && !stage_three)
        {
            stage_three = true;
            events.Reset();
            me->AI()->DoAction(ACTION_INIT_PHASE_3);
        }
    }
    void MovementInform(uint32 type, uint32 point) override { }

    void OnSpellFinished(SpellInfo const* spellInfo) override 
    { 
        switch (spellInfo->Id)
        {
        case SPELL_COMMAND_RAVAGE:
            if (Creature* remornia = GetRemornia())
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 25.0f, true))
                {
                    remornia->CastSpell(target, SPELL_RAVAGE_CAST_DUMMY, false);
                    remornia->GetScheduler().Schedule(6100ms, [this, remornia, target](TaskContext /*context*/)
                    {
                        if (!remornia)
                            return;

                        remornia->RemoveAura(SPELL_DESOLATION_CREATE_AT);
                        remornia->CastSpell(target, SPELL_DESOLATION_CREATE_AT, true);                        
                    });
                }
            }
            break;
        
        case SPELL_COMMAND_MASSACRE:
        {
            me->DespawnCreaturesInArea(600601, 100.0f);
            for (uint8 i = 0; i < 12; i++)
            {
                me->SummonCreature(600601, me->GetRandomNearPosition(30.0f), TEMPSUMMON_MANUAL_DESPAWN);
            }
            std::list<Creature*> massacreBunny;
            me->GetCreatureListWithEntryInGrid(massacreBunny, 600601, 100.0f);
            for (Creature* bunnies : massacreBunny)
            {
                bunnies->SetFacingTo(urand(1, 5), true);
                bunnies->CastSpell(nullptr, SPELL_MASSACRE_CREATE_LINE_AT, true);
            }    
            break;
        }

        case SPELL_SINISTER_REFLECTION:
            if (Creature* bunny = me->FindNearestCreature(600600, 100.0f, true))
                me->SummonCreature(NPC_SINISTER_REFLETION, bunny->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
            break;
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _JustReachedHome();
        me->RemoveAllAreaTriggers();
        me->NearTeleportTo(me->GetHomePosition());
        if (Creature* remornia = GetRemornia())
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, remornia);
        me->DespawnCreaturesInArea(NPC_ECHO_OF_SIN, 125.0f);
        me->DespawnCreaturesInArea(NPC_CRIMSON_CABALIST, 125.0f);
        me->DespawnCreaturesInArea(NPC_LADY_SINSEAR, 125.0f);
        me->DespawnCreaturesInArea(NPC_LORD_EVERSHADE, 125.0f);
        me->DespawnCreaturesInArea(NPC_BARON_DUSKHOLLOW, 125.0f);
        me->DespawnCreaturesInArea(NPC_COUNTESS_GLOOMVEIL, 125.0f);
        me->DespawnCreaturesInArea(600601, 125.0f);
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*victim*/) override
    {
        _JustDied();
        me->RemoveAllAreaTriggers();
        if (Creature* remornia = GetRemornia())
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, remornia);
    }
};

//330116
struct at_massacre_line : public AreaTriggerAI
{
    at_massacre_line(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        if (at->GetCaster())
            at->GetCaster()->CastSpell(at->GetCaster(), SPELL_MASSACRE_CREATE_WEAPON_AT, true);
    }
};

//330089
struct at_massacre : public AreaTriggerAI
{
    at_massacre(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        at->SetDuration(5000);
        //at->SetPeriodicProcTimer(250);
        at->GetCaster()->GetScheduler().Schedule(1500ms, [this](TaskContext /*context*/)
        {
            Position castPos = at->GetCaster()->GetPosition();
            at->MovePosition(castPos, 60.0f, 0.0f);
          //  at->SetDestination(castPos, 6000);
        });
    }

    void OnPeriodicProc() override
    {
        //VALIDATE_CASTER();
        //GuidUnorderedSet const& getPlayers = at->GetInsidePlayers();
        //if (Unit* target = ObjectAccessor::GetUnit(*caster, *getPlayers.begin()))
          //  if (target->IsPlayer() && target != caster)
            //    at->GetCaster()->Kill(target, true);
    }
};

//327982
struct at_desolation : public AreaTriggerAI
{
    at_desolation(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        at->SetDuration(360000);
    }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (!target->HasAura(SPELL_DESOLATION_AT_DAMAGE))
            at->GetCaster()->CastSpell(target, SPELL_DESOLATION_AT_DAMAGE, true);
    }

    void OnUnitExit(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->HasAura(SPELL_DESOLATION_AT_DAMAGE))
            target->RemoveAura(SPELL_DESOLATION_AT_DAMAGE);
    }
};

//168156
struct npc_remornia : public ScriptedAI
{
    npc_remornia(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        me->CanFly();
        me->SetFlying(true);
        me->SetReactState(REACT_PASSIVE);
        me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NON_ATTACKABLE));
        me->SetObjectScale(4.5f);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_IMPALE_MARK:
            UnitList targetList;
            SelectTargetList(targetList, (urand(3, 4)), SELECT_TARGET_RANDOM, 100.0f, true);
            for (Unit* targets : targetList)
            {
                me->CastSpell(targets, SPELL_IMPALE_MARK, true);
                targets->GetScheduler().Schedule(6100ms, [this, targets](TaskContext /*context*/)
                {
                    if (!targets)
                        return;

                    me->CastSpell(targets, SPELL_IMPALE_DAMAGE, true);
                    if (targets->HasAura(SPEL_CARNAGE_PERIODIC))
                        me->CastSpell(targets, SPEL_CARNAGE_PERIODIC, true);

                    if (IsHeroic() || IsMythic())
                        me->CastSpell(targets, SPELL_RANCOR_CREATE_AREATRIGGER, true);
                });
            }
            events.Repeat(25s);
            break;
        }
    }

    void DoAction(int32 action)
    {
        switch (action)
        {
        case ACTION_REMORNIA_EVENTS:
            me->AddAura(SPELL_CARNAGE);
            events.ScheduleEvent(SPELL_IMPALE_MARK, 10s);
            break;
        }
    }
};

//169813
struct npc_hand_of_destruction : public ScriptedAI
{
    npc_hand_of_destruction(Creature* c) : ScriptedAI(c) { }

    void IsSummonedBy(Unit* summoner) override
    {
        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        me->GetScheduler().Schedule(6s, [this](TaskContext /*context*/)
        {
            me->CastSpell(nullptr, SPELL_HAND_OF_DESTRUCTION_DAMAGE, true);
            me->DespawnOrUnsummon();
        });
    }

    void JustDied(Unit* summoner) override
    {
        if (instance)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }
};

//169196
struct npc_crimson_cabalist : public ScriptedAI
{
    npc_crimson_cabalist(Creature* c) : ScriptedAI(c) { }

    void IsSummonedBy(Unit* summoner) override
    {
        me->CastSpell(nullptr, SPELL_CRIMSON_CHORUS, false);
    }

    void JustDied(Unit* summoner) override
    {
        if (IsHeroic() || IsMythic())
            me->CastSpell(nullptr, SPELL_CRESCENDO_MISSILE, true);
    }
};

//170710
struct npc_sinister_reflection : public ScriptedAI
{
    npc_sinister_reflection(Creature* c) : ScriptedAI(c) { }

    void IsSummonedBy(Unit* summoner) override
    {
        return;
    }
};

//326707
class spell_cleansing_pain : public SpellScript
{
    PrepareSpellScript(spell_cleansing_pain);

    void HandleOnHit()
    {
        if (Aura* burdenSin = GetHitUnit()->GetAura(SPELL_BURDEN_OF_SIN_PERIODIC_DUMMY))
            if (burdenSin->GetStackAmount() > 1)
                burdenSin->SetStackAmount(burdenSin->GetStackAmount() - 1);

        GetHitUnit()->SummonCreature(NPC_ECHO_OF_SIN, GetHitUnit()->GetRandomNearPosition(10.0f));

        if (GetCaster()->GetMap()->IsMythic())
            GetCaster()->CastSpell(GetHitUnit(), SPELL_COLLECTIVE_TRAUMA_DAMAGE, true);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_cleansing_pain::HandleOnHit);
    }
};

//329181
class spell_wracking_pain : public SpellScript
{
    PrepareSpellScript(spell_wracking_pain);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetHitUnit()->IsPlayer())
            targets.remove(GetHitUnit());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_wracking_pain::FilterTargets, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//167999
struct npc_echo_of_sin : public ScriptedAI
{
    npc_echo_of_sin(Creature* c) : ScriptedAI(c) { }

    void IsSummonedBy(Unit* summoner) override
    {
        SetCombatMovement(false);
        me->SetReactState(REACT_PASSIVE);
        me->CastSpell(nullptr, SPELL_PAINFUL_MEMORIES_CHANNEL, false);
    }
};

//335872
struct at_rancor : public AreaTriggerAI
{
    at_rancor(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnCreate() override
    {
        at->SetDuration(60000);
    }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (!target->HasAura(SPELL_RANCOR_AT_DAMAGE))
            at->GetCaster()->CastSpell(target, SPELL_RANCOR_AT_DAMAGE, true);
    }

    void OnUnitExit(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->HasAura(SPELL_RANCOR_AT_DAMAGE))
            target->RemoveAura(SPELL_RANCOR_AT_DAMAGE);
    }
};

//174161,174134,174126,173164
struct npc_nightcloak : public ScriptedAI
{
    npc_nightcloak(Creature* c) : ScriptedAI(c) { SetCombatMovement(false); }

    void Reset() override
    {
        switch (me->GetEntry())
        {
        case NPC_LADY_SINSEAR:
            me->CastSpell(nullptr, SPELL_NATHRIAN_HYMN_SINSEAR_PERI_DUMMY, false);
            break;

        case NPC_LORD_EVERSHADE:
            me->CastSpell(nullptr, SPELL_NATHRIAN_HYMN_EVERSHADE_PERI_DUMMY, false);
            break;

        case NPC_BARON_DUSKHOLLOW:
            me->CastSpell(nullptr, SPELL_NATHRIAN_HYMN_DUSKHOLLOW_PERI_DUMMY, false);
            break;

        case NPC_COUNTESS_GLOOMVEIL:
            me->CastSpell(nullptr, SPELL_NATHRIAN_HYMN_GLOOMVEIL_PERI_DUMMY, false);
            break;
        }
    }
};

//341728,341648,338686,338688
class aura_nathrian_hymn : public AuraScript
{
    PrepareAuraScript(aura_nathrian_hymn);

    void OnTick(AuraEffect const* auraEff)
    {
        if (GetCaster())
            return;

        switch (GetCaster()->GetEntry())
        {
        case NPC_LADY_SINSEAR:
            GetCaster()->CastSpell(nullptr, SPELL_NATHRIAN_HYMN_SINSEAR_DAMAGE, false);
            break;

        case NPC_LORD_EVERSHADE:
            GetCaster()->CastSpell(nullptr, SPELL_NATHRIAN_HYMN_EVERSHADE_DAMAGE, false);
            break;

        case NPC_BARON_DUSKHOLLOW:
            GetCaster()->CastSpell(nullptr, SPELL_NATHRIAN_HYMN_DUSKHOLLOW_DAMAGE, false);
            break;

        case NPC_COUNTESS_GLOOMVEIL:
            GetCaster()->CastSpell(nullptr, SPELL_NATHRIAN_HYMN_GLOOMVEIL_DAMAGE, false);
            break;
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_nathrian_hymn::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//326699
class aura_burden_sin : public AuraScript
{
    PrepareAuraScript(aura_burden_sin);

    void OnTick(AuraEffect const* auraEff)
    {
        if (GetCaster() || GetTarget())
            return;

        GetCaster()->CastSpell(GetTarget(), SPELL_BURDEN_OF_SIN_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_burden_sin::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//324831
class aura_painful_memories : public AuraScript
{
    PrepareAuraScript(aura_painful_memories);

    void OnApply(AuraEffect const* /*p_AurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetCaster())
            return;

        GetCaster()->CastSpell(nullptr, SPELL_PAINFUL_MEMORIES_DAMAGE, true);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(aura_painful_memories::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_sire_denathrius()
{
    RegisterCreatureAI(boss_sire_denathrius);
    RegisterAreaTriggerAI(at_massacre_line);
    RegisterAreaTriggerAI(at_massacre);
    RegisterAreaTriggerAI(at_desolation);
    RegisterCreatureAI(npc_remornia);
    RegisterCreatureAI(npc_hand_of_destruction);
    RegisterCreatureAI(npc_crimson_cabalist);
    RegisterCreatureAI(npc_sinister_reflection);
    RegisterCreatureAI(npc_echo_of_sin);
    RegisterSpellScript(spell_cleansing_pain);
    RegisterSpellScript(spell_wracking_pain);
    RegisterAreaTriggerAI(at_rancor);
    RegisterCreatureAI(npc_nightcloak);
    RegisterAuraScript(aura_nathrian_hymn);
    RegisterAuraScript(aura_burden_sin);
    RegisterAuraScript(aura_painful_memories);
}
