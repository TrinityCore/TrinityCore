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
    SPELL_AZERITE_INFUSION1 = 257597,
    SPELL_AZERITE_INFUSION2 = 271698,

    SPELL_CALL_EARTHRAGER 	= 257593,
	
    SPELL_RESONANT_PULSE 	= 258622,
	
    SPELL_TECTONIC_SMASH 	= 275907,
   
};

enum Events
{
    EVENT_AZERITE_INFUSION 		= 1,
    EVENT_CALL_EARTHRAGER 		= 2,
    EVENT_RESONANT_PULSE 		= 3,
    EVENT_TECTONIC_SMASH 		= 4,
};

enum Yells
{
    YELL_AZERITE_INFUSION 		= 0,
    YELL_CALL_EARTHRAGER 		= 1,
    YELL_RESONANT_PULSE 		= 2,
    YELL_TECTONIC_SMASH  		= 3,
    YELL_KILLED 				= 4,
    YELL_KILL 					= 5,
	YELL_ENTER_COMBAT			= 6, 
};

enum AnimKit
{

};

struct boss_azerokk : public BossAI
{
public:
    boss_azerokk(Creature* creature) : BossAI(creature, DATA_AZEROKK)
    {
        Initialize();
    }


    void Initialize()
    {
        events.ScheduleEvent(EVENT_AZERITE_INFUSION, 6000);
        events.ScheduleEvent(EVENT_CALL_EARTHRAGER, 3000);
        events.ScheduleEvent(EVENT_RESONANT_PULSE, 3000);
        if (IsHeroic() || IsMythic())
            events.ScheduleEvent(EVENT_TECTONIC_SMASH, 5000);
    }

    void Reset() override
    {
        BossAI::Reset();
        events.Reset();
        Initialize();
        instance->SetBossState(DATA_AZEROKK, FAIL);
    }

    void EnterCombat(Unit* who)
    {
        BossAI::EnterCombat(who);
        Talk(YELL_ENTER_COMBAT);
        instance->SetBossState(DATA_AZEROKK, IN_PROGRESS);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(YELL_KILLED);
        instance->SetBossState(DATA_AZEROKK, DONE);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(YELL_KILL);
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

            case EVENT_AZERITE_INFUSION:
                Talk(YELL_AZERITE_INFUSION);
                events.DelayEvents(1000);
                DoCastVictim(SPELL_AZERITE_INFUSION1);
                DoCastVictim(SPELL_AZERITE_INFUSION2);
                events.ScheduleEvent(EVENT_AZERITE_INFUSION, 30000);
                break;
            case EVENT_CALL_EARTHRAGER:
				Talk(YELL_CALL_EARTHRAGER);
                DoCastVictim(SPELL_CALL_EARTHRAGER);
                events.ScheduleEvent(EVENT_CALL_EARTHRAGER, 10000);
                break;
            case EVENT_RESONANT_PULSE:
                Talk(YELL_TECTONIC_SMASH);
                DoCastVictim(SPELL_RESONANT_PULSE);
                events.ScheduleEvent(EVENT_RESONANT_PULSE, 15800);
                break;
            case EVENT_TECTONIC_SMASH:
                Talk(YELL_TECTONIC_SMASH);
                DoCastVictim(SPELL_TECTONIC_SMASH, me);
                events.ScheduleEvent(EVENT_TECTONIC_SMASH, 47400);
                break;
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }
};


void AddSC_boss_azerokk()
{
    RegisterCreatureAI(boss_azerokk);
}
