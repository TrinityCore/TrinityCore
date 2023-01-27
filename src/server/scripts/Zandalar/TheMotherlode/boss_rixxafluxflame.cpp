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

#include "ScriptMgr.h"
#include "the_motherlode.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum Spells
{
    SPELL_CHEMICAL_BURN1	= 259853,
    SPELL_CHEMICAL_BURN2	= 259856,

    SPELL_PROPELLANT_BLAST	= 260669,
	
    SPELL_SEARING_REAGENT	= 259474,
	
};

enum Events
{
    EVENT_CHEMICAL_BURN		= 1,
    EVENT_PROPELLANT_BLAST	= 2,
    EVENT_SEARING_REAGENT	= 3,
};

enum Yells
{
    YELL_AGGRO				= 0,
    YELL_CHEMICAL_BURN 		= 1,
    YELL_PROPELLANT_BLAST	= 2,
    YELL_SEARING_REAGENT	= 3,
    YELL_KILLED				= 4,
};

enum AnimKit
{

};

struct boss_rixxafluxflame : public BossAI
{
public:
    boss_rixxafluxflame(Creature* creature) : BossAI(creature, DATA_RIXXA_FLUXFLAME)
    {
        Initialize();
    }


    void Initialize()
    {
        events.ScheduleEvent(EVENT_CHEMICAL_BURN, 12000);
        events.ScheduleEvent(EVENT_PROPELLANT_BLAST, 6000);
        events.ScheduleEvent(EVENT_SEARING_REAGENT, 1500);
    }

    void Reset() override
    {
        BossAI::Reset();
        events.Reset();
        Initialize();
        instance->SetBossState(DATA_RIXXA_FLUXFLAME, FAIL);
    }

    void EnterCombat(Unit* who)
    {
        BossAI::EnterCombat(who);
        Talk(YELL_AGGRO);
        instance->SetBossState(DATA_RIXXA_FLUXFLAME, IN_PROGRESS);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(YELL_KILLED);
        instance->SetBossState(DATA_RIXXA_FLUXFLAME, DONE);
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
            case EVENT_CHEMICAL_BURN:
                Talk(YELL_CHEMICAL_BURN);
                events.DelayEvents(5000);
                DoCastVictim(SPELL_CHEMICAL_BURN1);
                DoCastVictim(SPELL_CHEMICAL_BURN2);
                events.ScheduleEvent(EVENT_CHEMICAL_BURN, 34500);
                break;
            case EVENT_PROPELLANT_BLAST:
				Talk(YELL_PROPELLANT_BLAST);
                DoCastVictim(SPELL_PROPELLANT_BLAST);
                events.ScheduleEvent(EVENT_PROPELLANT_BLAST, 10000);
                break;
            case EVENT_SEARING_REAGENT:
                Talk(YELL_SEARING_REAGENT);
                DoCastVictim(SPELL_SEARING_REAGENT);
                events.ScheduleEvent(EVENT_SEARING_REAGENT, 15800);
                break;
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }
};


void AddSC_boss_rixxafluxflame()
{
    RegisterCreatureAI(boss_rixxafluxflame);
}