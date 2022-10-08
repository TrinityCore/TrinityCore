/*
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
    SPELL_ALPHA_CANNON			= 260318,
    SPELL_HOMMING_MISSILE		= 260838,
	SPELL_GATLING_GUN			= 260280,
	
    SPELL_CONFIGURATION_DRILL	= 260189,
	SPELL_DRILL_SMASH			= 260202,
	
	SPELL_MICRO_MISSILES		= 276229,
   
};

enum Events
{
    EVENT_GATLING_GUN			= 1,
    EVENT_DRILL_SMASH			= 2,
    EVENT_ALPHA_CANNON          = 3,
    EVENT_MICRO_MISSILES 		= 4,
};

enum Yells
{
    YELL_AGROO					= 0,
    YELL_GATLING_GUN			= 1,
    YELL_DRILL_SMASH			= 2,
    YELL_MICRO_MISSILES  		= 3,
    YELL_KILLED 				= 4,
};

enum AnimKit
{

};

struct boss_mogulrazdunk : public BossAI
{
public:
    boss_mogulrazdunk (Creature* creature) : BossAI(creature, DATA_MOGUL_RAZDUNK)
    {
        Initialize();
    }

    void Initialize()
    {
        events.ScheduleEvent(EVENT_GATLING_GUN, 5000);
        events.ScheduleEvent(EVENT_DRILL_SMASH, 15000);
        events.ScheduleEvent(EVENT_ALPHA_CANNON, 11000);
        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_MICRO_MISSILES, 15800);
    }


    void Reset() override
    {
        BossAI::Reset();
        events.Reset();
        Initialize();
        instance->SetBossState(DATA_MOGUL_RAZDUNK, FAIL);
    }

    void EnterCombat(Unit* who) 
    {
        BossAI::EnterCombat(who);
        Talk(YELL_AGROO);
        instance->SetBossState(DATA_MOGUL_RAZDUNK, IN_PROGRESS);
    }

  
    void JustDied(Unit* killer) override
    {
        _JustDied();
        BossAI::JustDied(killer);
        Talk(YELL_KILLED);
        instance->SetBossState(DATA_MOGUL_RAZDUNK, DONE);
       
    }

    void KilledUnit(Unit* victim) override
    {

    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventID = events.ExecuteEvent())
        {
            switch (eventID)
            {
            case EVENT_GATLING_GUN:
                events.DelayEvents(1000);
                DoCastVictim(SPELL_HOMMING_MISSILE);
				DoCastVictim(SPELL_GATLING_GUN);
                events.ScheduleEvent(EVENT_GATLING_GUN, 40400);
                break;
            case EVENT_DRILL_SMASH:
				Talk(YELL_DRILL_SMASH);
                DoCastVictim(SPELL_CONFIGURATION_DRILL);
				DoCastVictim(SPELL_DRILL_SMASH);
                events.ScheduleEvent(EVENT_DRILL_SMASH, 25000);
                break;
            case EVENT_ALPHA_CANNON:
                me->RemoveAurasDueToSpell(SPELL_CONFIGURATION_DRILL);
                DoCastVictim(SPELL_ALPHA_CANNON);
                events.ScheduleEvent(EVENT_ALPHA_CANNON, 15000);
                break;
            case EVENT_MICRO_MISSILES:
                Talk(YELL_MICRO_MISSILES);
                DoCastVictim(SPELL_MICRO_MISSILES);
                events.ScheduleEvent(EVENT_MICRO_MISSILES, 35000);
                break;
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }
};


void AddSC_boss_mogulrazdunk()
{
    RegisterCreatureAI(boss_mogulrazdunk);
}
