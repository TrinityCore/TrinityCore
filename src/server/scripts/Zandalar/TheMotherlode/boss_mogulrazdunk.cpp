/*
 * Copyright 2023 AzgathCore
 * Copyright (C) 2022 BfaCore Reforged
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "the_motherlode.h"
#include "ScriptedCreature.h"
#include "SpellHistory.h"

enum Spells
{
    SPELL_ALPHA_CANNON_MISSILE = 260318,
    SPELL_ALPHA_CANNON = 260318,
    SPELL_HOMMING_MISSILE = 260838,
    SPELL_GATLING_GUN = 260280,

    SPELL_HOMING_MISSILE_VISUAL = 260815,
    SPELL_HOMING_MISSILE_CAST = 260811,
    SPELL_HOMING_MISSILE_SPEED = 260836,
    SPELL_HOMING_MISSILE_DAMAGE = 260838,
    SPELL_DRILL_SMASH = 260202,

    SPELL_GATLING_GUN_DAMAGE = 260279,
    SPELL_GATLING_GUN_CAST = 260280,
    SPELL_MICRO_MISSILES = 276229,

    SPELL_CONFIGURATION_DRILL = 260189, //x3

    SPELL_DRILL_SMASH_CAST_DAMAGE = 260202, // on player reach Z
    SPELL_BIG_RED_ROCKET_MISSILE = 270276,
    SPELL_BIG_RED_ROCKET_VISUAL = 270279,
    SPELL_DRILL_SMASH_VISUAL = 260194,
    SPELL_DRILL_SMASH_CAST = 271456, // cast while air Z

    SPELL_MICRO_MISSILE_CAST = 276229,
    SPELL_MICRO_MISSILE_MISSILE = 276231,

    SPELL_CONCUSSION_CHARGE_CAST = 281621,
    SPELL_CONCUSSION_CHARGE_MISSILE = 262284,

    SPELL_AZERITE_HEARTSEEKER_CAST = 262515,
    SPELL_AZERITE_HEARTSEEKER_DAMAGE = 262516,
};

enum Events
{
    EVENT_GATLING_GUN = 1,
    EVENT_DRILL_SMASH = 2,
    EVENT_ALPHA_CANNON = 3,
    EVENT_MICRO_MISSILES = 4,

    EVENT_HOMING_MISSILE,

    EVENT_DRILL,
    EVENT_SUMMON_BIG_RED_ROCKET,

    EVENT_MICRO_MISSILE,

    EVENT_MISSILE_EXPLODE,
    EVENT_FIXATE,
    EVENT_FOLLOW,

    EVENT_CONCUSSION_CHARGE,
    EVENT_AZERITE_HEARTSEEKER,
};

enum Yells
{
    YELL_AGROO = 0,
    YELL_GATLING_GUN = 1,
    YELL_DRILL_SMASH = 2,
    YELL_MICRO_MISSILES = 3,
    YELL_KILLED = 4,
};

enum AnimKit
{

};

    struct boss_mogulrazdunk : public BossAI
{
    
public:
    boss_mogulrazdunk(Creature* creature) : BossAI(creature, DATA_MOGUL_RAZDUNK)
    {
        void Initialize();
    }

        void Initialize()
    {
        events.ScheduleEvent(EVENT_GATLING_GUN, Milliseconds(5000));
        events.ScheduleEvent(EVENT_DRILL_SMASH, Milliseconds(15000));
        events.ScheduleEvent(EVENT_ALPHA_CANNON, Milliseconds(11000));
        /*if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_MICRO_MISSILES, Milliseconds(15800));*/
    }

        void Reset() override
    {
        BossAI::Reset();
        events.Reset();
        Initialize();
        instance->SetBossState(DATA_MOGUL_RAZDUNK, FAIL);
    }

};

    enum Timers {
        TIMER_MICRO_MISSILE = 15 * IN_MILLISECONDS,
        TIMER_CONCUSSION_CHARGE = 10 * IN_MILLISECONDS,
        TIMER_AZERITE_HEARTSEEKER = 17 * IN_MILLISECONDS,
        TIMER_BIG_RED_ROCKET = 15 * IN_MILLISECONDS,
    };


   /* BossAI::JustEnteredCombat(Unit* who);

    void JustEnteredCombat(Unit* who) override
    {
       
        Talk(YELL_AGROO);
        instance->SetBossState(DATA_MOGUL_RAZDUNK, IN_PROGRESS);
    };*/



//void JustDied(Unit* killer) override
//{
//    _JustDied();
//    BossAI::JustDied(killer);
//    Talk(YELL_KILLED);
//    instance->SetBossState(DATA_MOGUL_RAZDUNK, DONE);
//
//    TIMER_ALPHA_CANNON = 3 * IN_MILLISECONDS,
//        TIMER_GATLING_GUN = 28 * IN_MILLISECONDS,
//        TIMER_HOMING_MISSILE = 10 * IN_MILLISECONDS,
//};
//    }

    //enum Creatures
    //    void KilledUnit(Unit* victim) override
    //    {
    //    BOSS_MOGUL_RAZDUNK = 129232,
    //    NPC_HOMING_MISSILE = 132338,
    //    NPC_BIG_RED_ROCKET = 131973,
    //    NPC_VENTURE_SKYSCORCHER = 133436,
    //    NPC_MISSILE_TARGET = 132271,
    //    NPC_BOOMBA = 141303,
    //};
    //
    //    }
    //
    //enum Actions
    //    void UpdateAI(uint32 diff) override
    //    {
    //    ACTION_ENGAGE_MISSILE = 1,
    //};
    //        if (!UpdateVictim())
    //            return;
    //
    //        events.Update(diff);
    //
    //        if (me->HasUnitState(UNIT_STATE_CASTING))
    //            return;
    //
    //enum Points
    //        while (uint32 eventID = events.ExecuteEvent())
    //        {
    //            switch (eventID)
    //            {
    //    POINT_SPELLS = 1,
    //};
    //            case EVENT_GATLING_GUN:
    //                events.DelayEvents(1000);
    //                DoCastVictim(SPELL_HOMMING_MISSILE);
    //				DoCastVictim(SPELL_GATLING_GUN);
    //                events.ScheduleEvent(EVENT_GATLING_GUN, 40400);
    //                break;
    //            case EVENT_DRILL_SMASH:
    //				Talk(YELL_DRILL_SMASH);
    //                DoCastVictim(SPELL_CONFIGURATION_DRILL);
    //				DoCastVictim(SPELL_DRILL_SMASH);
    //                events.ScheduleEvent(EVENT_DRILL_SMASH, 25000);
    //                break;
    //            case EVENT_ALPHA_CANNON:
    //                me->RemoveAurasDueToSpell(SPELL_CONFIGURATION_DRILL);
    //                DoCastVictim(SPELL_ALPHA_CANNON);
    //                events.ScheduleEvent(EVENT_ALPHA_CANNON, 15000);
    //                break;
    //            case EVENT_MICRO_MISSILES:
    //                Talk(YELL_MICRO_MISSILES);
    //                DoCastVictim(SPELL_MICRO_MISSILES);
    //                events.ScheduleEvent(EVENT_MICRO_MISSILES, 35000);
    //                break;
    //            default:
    //                break;
    //            }
    //        }
    //
    //const Position centerPos = { 1101.65f, -3918.86f, 79.52f }; //40
    //        DoMeleeAttackIfReady();
    //    }
    //};
    //
    //#define INTRO_TEXT "Do you bums realize how much property damage you've done !?"
    //#define AGGRO_TEXT "Right where you belong--under my heel!"
    //#define GATLING_GUN "Taste some high-caliber carnage!"
    //#define DRILL_TEXT "Crush!"
    //#define PHASE2_TEXT "What am I payin' you fools for?! Get out here and fix this!"
    //
    //void AddSC_boss_mogulrazdunk()
    //{
    //    
    //    RegisterCreatureAI(boss_mogulrazdunk);
    //}
