/*
 * Copyright (C) 2022 BfaCore Reforged
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


enum CoinoperatedcrowdpummelerSpells : uint32
{
    SPELL_INSUFFICIENT_FUNDS		= 267547,
	
	SPELL_STATIC_PULSE				= 262347,
    SPELL_FOOTBOMB_LAUNCHER			= 269493,
	
    SPELL_TIMED_DETONATION			= 256137,
    SPELL_PUNT						= 255996,
	
    SPELL_BLAZING_AZERITE			= 256163,
	
    SPELL_SHOCKING_CLAW				= 257337,
    SPELL_THROW_COINS				= 271785,
	
    SPELL_COIN_MAGNET				= 271903,
	
    SPELL_PAY_TO_WIN				= 271867
};

enum CoinoperatedcrowdpummelerTalks : uint8
{
    TALK_AGGRO					= 0,
    TALK_STATIC_PULSE			= 1,
	TALK_FOOTBOMB_LAUNCHER		= 2,
    TALK_SHOCKING_CLAW			= 3,
    TALK_COIN_MAGNET			= 4,
    TALK_DEATH					= 5
};

enum CoinoperatedcrowdpummelerEvents : uint8
{
    EVENT_STATIC_PULSE			= 1,
    EVENT_FOOTBOMB_LAUNCHER		= 2,
	EVENT_SHOCKING_CLAW			= 3,
    EVENT_COIN_MAGNET			= 4,
    EVENT_PAY_TO_WIN			= 5
};


// 129214 - Coin Operated Crowd Pummeler 
struct boss_Coin_operated_crowd_pummeler : public BossAI
{
    boss_Coin_operated_crowd_pummeler(Creature* creature) : BossAI(creature, DATA_COIN_OPERATED_CROWD_PUMMELER) { }

    void InitializeAI() override
    {
        BossAI::InitializeAI();
    }

    void Reset() override
    {
        events.Reset();
        BossAI::Reset();
		me->AddAura(SPELL_INSUFFICIENT_FUNDS);
    }

    void EnterCombat(Unit* who) 
    {
		me->RemoveAura(SPELL_INSUFFICIENT_FUNDS);
        Talk(TALK_AGGRO);
		instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_STATIC_PULSE, 8000);
		events.ScheduleEvent(EVENT_FOOTBOMB_LAUNCHER, 4000);
        events.ScheduleEvent(EVENT_SHOCKING_CLAW, 7000);

        if (IsMythic() || IsHeroic())
        {
            events.ScheduleEvent(EVENT_COIN_MAGNET, 8000);
			events.ScheduleEvent(EVENT_PAY_TO_WIN, 1000);
        }

        BossAI::EnterCombat(who);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        _DespawnAtEvade();
        BossAI::EnterEvadeMode(why);
    }


    void JustDied(Unit* killer) override
    {
        Talk(TALK_DEATH);
        BossAI::JustDied(killer);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        scheduler.Update(diff);
		        
		if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
			
            switch (eventId)
            {
                case EVENT_STATIC_PULSE:
                    Talk(TALK_STATIC_PULSE);
                    me->CastSpell(me, SPELL_STATIC_PULSE);
                    events.ScheduleEvent(EVENT_STATIC_PULSE, 20000);
                    break;
                case EVENT_FOOTBOMB_LAUNCHER:
                    me->CastSpell(me, SPELL_FOOTBOMB_LAUNCHER);
                    events.ScheduleEvent(EVENT_FOOTBOMB_LAUNCHER, 38000);
                    break;
                case EVENT_SHOCKING_CLAW:
                    Talk(TALK_SHOCKING_CLAW);
                    DoCastVictim(SPELL_SHOCKING_CLAW);
                    events.ScheduleEvent(EVENT_SHOCKING_CLAW, 30000);
                    break;
                case EVENT_COIN_MAGNET:
					Talk(TALK_COIN_MAGNET);
                    me->CastSpell(me, SPELL_COIN_MAGNET);
                    events.ScheduleEvent(EVENT_COIN_MAGNET, 30000);
                    break;
                case EVENT_PAY_TO_WIN:
                    me->CastSpell(me, SPELL_PAY_TO_WIN);
                    events.ScheduleEvent(EVENT_PAY_TO_WIN, 30000);
                    break;

                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
	TaskScheduler scheduler;
};


void AddSC_boss_Coin_operated_crowd_pummeler()
{
    RegisterCreatureAI(boss_Coin_operated_crowd_pummeler);
}
