/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "TW_halls_of_reflection.h"


enum TrashSpells
{
    // Ghostly Priest
    SPELL_SHADOW_WORD_PAIN                        = 72318,
    SPELL_CIRCLE_OF_DESTRUCTION                   = 72320,
    SPELL_COWER_IN_FEAR                           = 72321,
    SPELL_DARK_MENDING                            = 72322,

    // Phantom Mage
    SPELL_FIREBALL                                = 72163,
    SPELL_FLAMESTRIKE                             = 72169,
    SPELL_FROSTBOLT                               = 72166,
    SPELL_CHAINS_OF_ICE                           = 72121,
    SPELL_HALLUCINATION                           = 72342,

    // Phantom Hallucination (same as phantom mage + HALLUCINATION_2 when dies)
    SPELL_HALLUCINATION_2                         = 72344,

    // Shadowy Mercenary
    SPELL_SHADOW_STEP                             = 72326,
    SPELL_DEADLY_POISON                           = 72329,
    SPELL_ENVENOMED_DAGGER_THROW                  = 72333,
    SPELL_KIDNEY_SHOT                             = 72335,

    // Spectral Footman
    SPELL_SPECTRAL_STRIKE                         = 72198,
    SPELL_SHIELD_BASH                             = 72194,
    SPELL_TORTURED_ENRAGE                         = 72203,

    // Tortured Rifleman
    SPELL_SHOOT                                   = 72208,
    SPELL_CURSED_ARROW                            = 72222,
    SPELL_FROST_TRAP                              = 72215,
    SPELL_ICE_SHOT                                = 72268,
};

enum TrashEvents
{
    EVENT_TRASH_NONE,

    // Ghostly Priest
    EVENT_SHADOW_WORD_PAIN,
    EVENT_CIRCLE_OF_DESTRUCTION,
    EVENT_COWER_IN_FEAR,
    EVENT_DARK_MENDING,

    // Phantom Mage
    EVENT_FIREBALL,
    EVENT_FLAMESTRIKE,
    EVENT_FROSTBOLT,
    EVENT_CHAINS_OF_ICE,
    EVENT_HALLUCINATION,

    // Shadowy Mercenary
    EVENT_SHADOW_STEP,
    EVENT_DEADLY_POISON,
    EVENT_ENVENOMED_DAGGER_THROW,
    EVENT_KIDNEY_SHOT,

    // Spectral Footman
    EVENT_SPECTRAL_STRIKE,
    EVENT_SHIELD_BASH,
    EVENT_TORTURED_ENRAGE,

    // Tortured Rifleman
    EVENT_SHOOT,
    EVENT_CURSED_ARROW,
    EVENT_FROST_TRAP,
    EVENT_ICE_SHOT,
};

struct TW_hor_trash_dummyAI: public ScriptedAI{
	InstanceScript *instance;
	bool evade;
	
	TW_hor_trash_dummyAI(Creature *c): ScriptedAI(c){
		instance = me->GetInstanceScript();
		evade = false;
	}
	
	void JustDied(Unit *){
// 		me->MonsterYell("I died", LANG_UNIVERSAL, 0);
		instance->SetData(DATA_WAVE_CHECK, 1);
        }
        
        void JustReachedHome(){
		if(instance && !evade){
			evade = true;
			instance->SetData(DATA_WAVE_CHECK, 1);
		}
		ScriptedAI::JustReachedHome();
        }
        
        void DoAction(int32 actionID)
	{
		switch (actionID)
		{
			case ACTION_ENTER_COMBAT:
// 				me->MonsterYell("I should enter combat", LANG_UNIVERSAL, 0);
				// Reset flags
				me->RemoveFlag(UNIT_FIELD_FLAGS, 33555264);
				me->SetReactState(REACT_AGGRESSIVE);

				if (Unit* unit = me->SelectNearestTarget())
				AttackStart(unit);

				DoZoneInCombat();
				break;
		}
	}
};

class TW_npc_ghostly_priest : public CreatureScript
{
public:
    TW_npc_ghostly_priest() : CreatureScript("TW_npc_ghostly_priest") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_ghostly_priestAI(creature);
    }

    struct TW_npc_ghostly_priestAI: public TW_hor_trash_dummyAI
    {
        TW_npc_ghostly_priestAI(Creature* creature) : TW_hor_trash_dummyAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }
        

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000); // TODO: adjust timers
            events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000);
            events.ScheduleEvent(EVENT_COWER_IN_FEAR, 10000);
            events.ScheduleEvent(EVENT_DARK_MENDING, 20000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOW_WORD_PAIN:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_SHADOW_WORD_PAIN);
                        events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 8000);
                        return;
                    case EVENT_CIRCLE_OF_DESTRUCTION:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_CIRCLE_OF_DESTRUCTION);
                        events.ScheduleEvent(EVENT_CIRCLE_OF_DESTRUCTION, 12000);
                        return;
                    case EVENT_COWER_IN_FEAR:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_COWER_IN_FEAR);
                        events.ScheduleEvent(EVENT_COWER_IN_FEAR, 10000);
                        return;
                    case EVENT_DARK_MENDING:
                        // find an ally with missing HP
                        if (Unit* target = DoSelectLowestHpFriendly(40, DUNGEON_MODE(30000, 50000)))
                        {
                            DoCast(target, SPELL_DARK_MENDING);
                            events.ScheduleEvent(EVENT_DARK_MENDING, 20000);
                        }
                        else
                        {
                            // no friendly unit with missing hp. re-check in just 5 sec.
                            events.ScheduleEvent(EVENT_DARK_MENDING, 5000);
                        }
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class TW_npc_phantom_mage : public CreatureScript
{
public:
    TW_npc_phantom_mage() : CreatureScript("TW_npc_phantom_mage") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_phantom_mageAI(creature);
    }

    struct TW_npc_phantom_mageAI: public TW_hor_trash_dummyAI
    {
        TW_npc_phantom_mageAI(Creature* creature) : TW_hor_trash_dummyAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_FIREBALL, 3000); // TODO: adjust timers
            events.ScheduleEvent(EVENT_FLAMESTRIKE, 6000);
            events.ScheduleEvent(EVENT_FROSTBOLT, 9000);
            events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 12000);
            events.ScheduleEvent(EVENT_HALLUCINATION, 40000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FIREBALL:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_FIREBALL);
                        events.ScheduleEvent(EVENT_FIREBALL, 15000);
                        return;
                    case EVENT_FLAMESTRIKE:
                        DoCast(SPELL_FLAMESTRIKE);
                        events.ScheduleEvent(EVENT_FLAMESTRIKE, 15000);
                        return;
                    case EVENT_FROSTBOLT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_FROSTBOLT);
                        events.ScheduleEvent(EVENT_FROSTBOLT, 15000);
                        return;
                    case EVENT_CHAINS_OF_ICE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_CHAINS_OF_ICE);
                        events.ScheduleEvent(EVENT_CHAINS_OF_ICE, 15000);
                        return;
                    case EVENT_HALLUCINATION:
                        DoCast(SPELL_HALLUCINATION);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class TW_npc_phantom_hallucination : public CreatureScript
{
public:
    TW_npc_phantom_hallucination() : CreatureScript("TW_npc_phantom_hallucination") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_phantom_hallucinationAI(creature);
    }

    struct TW_npc_phantom_hallucinationAI : public TW_npc_phantom_mage::TW_npc_phantom_mageAI
    {
        TW_npc_phantom_hallucinationAI(Creature* creature) : TW_npc_phantom_mage::TW_npc_phantom_mageAI(creature)
        {
        }

        void JustDied(Unit* /*killer*/)
        {
            DoCast(SPELL_HALLUCINATION_2);
        }
    };

};

class TW_npc_shadowy_mercenary : public CreatureScript
{
public:
    TW_npc_shadowy_mercenary() : CreatureScript("TW_npc_shadowy_mercenary") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_shadowy_mercenaryAI(creature);
    }

    struct TW_npc_shadowy_mercenaryAI: public TW_hor_trash_dummyAI
    {
        TW_npc_shadowy_mercenaryAI(Creature* creature) : TW_hor_trash_dummyAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }
        
        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHADOW_STEP, 8000); // TODO: adjust timers
            events.ScheduleEvent(EVENT_DEADLY_POISON, 5000);
            events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
            events.ScheduleEvent(EVENT_KIDNEY_SHOT, 12000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOW_STEP:
                        DoCast(SPELL_SHADOW_STEP);
                        events.ScheduleEvent(EVENT_SHADOW_STEP, 8000);
                        return;
                    case EVENT_DEADLY_POISON:
                        DoCast(me->GetVictim(), SPELL_DEADLY_POISON);
                        events.ScheduleEvent(EVENT_DEADLY_POISON, 10000);
                        return;
                    case EVENT_ENVENOMED_DAGGER_THROW:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_ENVENOMED_DAGGER_THROW);
                        events.ScheduleEvent(EVENT_ENVENOMED_DAGGER_THROW, 10000);
                        return;
                    case EVENT_KIDNEY_SHOT:
                        DoCast(me->GetVictim(), SPELL_KIDNEY_SHOT);
                        events.ScheduleEvent(EVENT_KIDNEY_SHOT, 10000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class TW_npc_spectral_footman : public CreatureScript
{
public:
    TW_npc_spectral_footman() : CreatureScript("TW_npc_spectral_footman") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_spectral_footmanAI(creature);
    }

    struct TW_npc_spectral_footmanAI: public TW_hor_trash_dummyAI
    {
        TW_npc_spectral_footmanAI(Creature* creature) : TW_hor_trash_dummyAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000); // TODO: adjust timers
            events.ScheduleEvent(EVENT_SHIELD_BASH, 10000);
            events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPECTRAL_STRIKE:
                        DoCast(me->GetVictim(), SPELL_SPECTRAL_STRIKE);
                        events.ScheduleEvent(EVENT_SPECTRAL_STRIKE, 5000);
                        return;
                    case EVENT_SHIELD_BASH:
                        DoCast(me->GetVictim(), SPELL_SHIELD_BASH);
                        events.ScheduleEvent(EVENT_SHIELD_BASH, 5000);
                        return;
                    case EVENT_TORTURED_ENRAGE:
                        DoCast(SPELL_TORTURED_ENRAGE);
                        events.ScheduleEvent(EVENT_TORTURED_ENRAGE, 15000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class TW_npc_tortured_rifleman : public CreatureScript
{
public:
    TW_npc_tortured_rifleman() : CreatureScript("TW_npc_tortured_rifleman") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_tortured_riflemanAI(creature);
    }

    struct TW_npc_tortured_riflemanAI  : public TW_hor_trash_dummyAI
    {
        TW_npc_tortured_riflemanAI(Creature* creature) : TW_hor_trash_dummyAI(creature)
        {
        }

        EventMap events;

        void Reset()
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/)
        {
            events.ScheduleEvent(EVENT_SHOOT, 2000); // TODO: adjust timers
            events.ScheduleEvent(EVENT_CURSED_ARROW, 10000);
            events.ScheduleEvent(EVENT_FROST_TRAP, 1000);
            events.ScheduleEvent(EVENT_ICE_SHOT, 15000);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHOOT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_SHOOT);
                        events.ScheduleEvent(EVENT_SHOOT, 2000);
                        return;
                    case EVENT_CURSED_ARROW:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_CURSED_ARROW);
                        events.ScheduleEvent(EVENT_CURSED_ARROW, 10000);
                        return;
                    case EVENT_FROST_TRAP:
                        DoCast(SPELL_FROST_TRAP);
                        events.ScheduleEvent(EVENT_FROST_TRAP, 30000);
                        return;
                    case EVENT_ICE_SHOT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_ICE_SHOT);
                        events.ScheduleEvent(EVENT_ICE_SHOT, 15000);
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};


///Dummy for Lichking trash

TW_mob_hor_lk_dummyAI::TW_mob_hor_lk_dummyAI( Creature* pCreature ): ScriptedAI(pCreature){
	instance = pCreature->GetInstanceScript();
	isHeroic = pCreature->GetMap()->IsRaidOrHeroicDungeon();
	if( instance )
		instance->SetData( DATA_LK_ADD_MOB, 1 );
	isActivated = false;
	activation_timer = 0;
}

void TW_mob_hor_lk_dummyAI::JustDied( Unit * /*pKiller*/ ){
	if( instance )
		instance->SetData( DATA_LK_DEL_MOB, 1 );
}

void TW_mob_hor_lk_dummyAI::Activate( uint32 activate_in ){
	me->AddAura(40135, me);
	activation_timer = 0;
	ACTIVATION_TIMER = activate_in;
// 	me->MonsterYell("I should enter combat", LANG_UNIVERSAL, 0);
	if (Unit* unit = me->SelectNearestTarget())
		AttackStart(unit);

	DoZoneInCombat();
// 	me->SetSpeed(MOVE_WALK , me->GetSpeedRate(MOVE_WALK) * 0.5, true);
}


bool TW_mob_hor_lk_dummyAI::ActivationCheck( const uint32 uiDiff ){
	if( !isActivated ){
		activation_timer += uiDiff;
		if( activation_timer >= ACTIVATION_TIMER ){
			isActivated = true;
// 			me->MonsterYell("I should be active now", LANG_UNIVERSAL, 0);
// 			me->SetSpeed(MOVE_WALK , me->GetSpeedRate(MOVE_WALK) * 2.0, true);	
			me->RemoveAurasDueToSpell(40135);
		}
	}
	return isActivated;
}

void TW_mob_hor_lk_dummyAI::JustReachedHome(){
	if(instance)
		instance->SetData(DATA_LICHKING_EVENT, NOT_STARTED);
}


///===================================================================================
///TODO

#define SPELL_CURSE_OF_DOOM_N		70144
#define SPELL_CURSE_OF_DOOM_H		70183
#define SPELL_CURSE_OF_DOOM		isHeroic?SPELL_CURSE_OF_DOOM_H:SPELL_CURSE_OF_DOOM_N
#define CURSE_OF_DOOM_CASTTIME		1500
#define CURSE_OF_DOOM_TIMER		10000
#define CURSE_OF_DOOM_RANGE		30.0f

#define SPELL_SHADOWBOLT_N		70080
#define SPELL_SHADOWBOLT_H		70182
#define SPELL_SHADOWBOLT		isHeroic?SPELL_SHADOWBOLT_H:SPELL_SHADOWBOLT_N
#define SHADOWBOLT_RANGE		20.0f
#define SHADOWBOLT_CASTTIME		2000
#define SHADOWBOLT_TIMER		6000

#define SPELL_VOLLEY_N			70145
#define SPELL_VOLLEY_H			70184
#define SPELL_VOLLEY			isHeroic?SPELL_VOLLEY_H:SPELL_VOLLEY_N
#define VOLLEY_CASTTIME			2000
#define VOLLEY_TIMER			6000
#define VOLLEY_RANGE			30.0f

class TW_npc_risen_witch_doctor : public CreatureScript
{
public:
    TW_npc_risen_witch_doctor() : CreatureScript("TW_npc_risen_witch_doctor") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_risen_witch_doctorAI(creature);
    }

    struct TW_npc_risen_witch_doctorAI : public TW_mob_hor_lk_dummyAI
    {
        TW_npc_risen_witch_doctorAI(Creature* creature) : TW_mob_hor_lk_dummyAI(creature) {
		Reset();
        }
        
        uint32 curse_of_doom_timer;
	uint32 shadowbolt_timer;
	uint32 volley_timer;

        void Reset()
        {
		curse_of_doom_timer = CURSE_OF_DOOM_CASTTIME;
		shadowbolt_timer = SHADOWBOLT_TIMER / 2;
		volley_timer = 0;
        }

        void EnterCombat(Unit* /*who*/)
        {
        
        }

        void KilledUnit(Unit* /*victim*/)
        {
        
        }

        void UpdateAI(uint32 diff)
        {
		if(instance && instance->GetData(DATA_LICHKING_EVENT)==NOT_STARTED)
			me->DisappearAndDie();
		// Return since we have no target
		if (!UpdateVictim())
			return;
		if(!ActivationCheck(diff))
			return;
			
		curse_of_doom_timer += diff;
		shadowbolt_timer += diff;
		volley_timer += diff;

		if( !IsBusy() ){
			if( Unit *target = ShouldCastCurseOfDoom() )
				CastCurseOfDoom( target );
			else if( ShouldCastShadowbolt() )
				CastShadowbolt();
			else if( Unit *target = ShouldCastVolley() )
				CastVolley( target );
		}

		
		DoMeleeAttackIfReady();
        }
        
        Unit *ShouldCastCurseOfDoom(){
		if( curse_of_doom_timer < CURSE_OF_DOOM_TIMER )
			return 0;
		Unit *target = 0;
		for( uint8 i = 0; i < 5 && target==0; i++ ){
			target = SelectTarget( SELECT_TARGET_RANDOM, 0 );
			if( target == 0 || target->GetTypeId() != TYPEID_PLAYER || me->GetDistance(target) > CURSE_OF_DOOM_RANGE )
				target = 0;
		}
		return target;
	}
	
	void CastCurseOfDoom( Unit *target ){
		DoCast( target, SPELL_CURSE_OF_DOOM );
		curse_of_doom_timer = 0;
	}
	
	bool ShouldCastShadowbolt(){
		Unit *target = me->GetVictim();
		if(!target)
			return false;
		return	shadowbolt_timer > SHADOWBOLT_TIMER
		&&	me->GetDistance( target ) < SHADOWBOLT_RANGE;
	}
	
	void CastShadowbolt(){
		DoCast( me->GetVictim(), SPELL_SHADOWBOLT );
		shadowbolt_timer = 0;
	}
	
	Unit *ShouldCastVolley(){
		if( volley_timer < VOLLEY_TIMER )
			return 0;
		Unit *target = SelectTarget( SELECT_TARGET_RANDOM, 0 );
		if( target == 0 || me->GetDistance( target ) >= VOLLEY_RANGE )
			target = 0;
		return target;
	}
	
	void CastVolley( Unit *target ){
		DoCast( target, SPELL_VOLLEY );
		volley_timer = 0;
	}
	
	bool IsBusy(){
		return	curse_of_doom_timer < CURSE_OF_DOOM_CASTTIME
		||	shadowbolt_timer < SHADOWBOLT_CASTTIME
		||	volley_timer < VOLLEY_CASTTIME;
	}
    };

};

///===================================================================================

#define SPELL_LEAP	70150
#define LEAP_RANGE_MAX	30.0f
#define LEAP_RANGE_MIN	5.0f

class TW_npc_raging_ghoul : public CreatureScript
{
public:
    TW_npc_raging_ghoul() : CreatureScript("TW_npc_raging_ghoul") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_raging_ghoulAI(creature);
    }

    struct TW_npc_raging_ghoulAI : public TW_mob_hor_lk_dummyAI
    {
        TW_npc_raging_ghoulAI(Creature* creature) : TW_mob_hor_lk_dummyAI(creature) {
		Reset();
        }
        
        bool hasLeaped;

        void Reset()
        {
		hasLeaped = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
        
        }

        void KilledUnit(Unit* /*victim*/)
        {
        
        }

        void UpdateAI(uint32 diff)
        {
		if(instance && instance->GetData(DATA_LICHKING_EVENT)==NOT_STARTED)
			me->DisappearAndDie();
		// Return since we have no target
		if (!UpdateVictim())
			return;
		if(!ActivationCheck(diff))
			return;

		if( !hasLeaped && me->GetVictim() ){
			float dist = me->GetDistance( me->GetVictim() );
			if( dist <= LEAP_RANGE_MAX && dist >= LEAP_RANGE_MIN ){
				DoCast( me->GetVictim(), SPELL_LEAP );
				hasLeaped = true;
			}
		}
		
		DoMeleeAttackIfReady();
        }
    };

};

///===================================================================================

#define SPELL_CLEAVE		40505
#define CLEAVE_TIMER		10000

#define SPELL_VOMIT		70176
#define VOMIT_TIMER_MIN		10000
#define VOMIT_TIMER_MAX		25000

class TW_npc_lumbering_abomination : public CreatureScript
{
public:
    TW_npc_lumbering_abomination() : CreatureScript("TW_npc_lumbering_abomination") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_lumbering_abominationAI(creature);
    }

    struct TW_npc_lumbering_abominationAI : public TW_mob_hor_lk_dummyAI
    {
        TW_npc_lumbering_abominationAI(Creature* creature) : TW_mob_hor_lk_dummyAI(creature) {
		Reset();
        }
        
        uint32 vomit_timer, VOMIT_TIMER;;
        uint32 cleave_timer;

        void Reset()
        {
		vomit_timer = 0;
		VOMIT_TIMER = VOMIT_TIMER_MIN + rand() % (VOMIT_TIMER_MAX-VOMIT_TIMER_MIN);
		cleave_timer = 0;
        }

        void EnterCombat(Unit* /*who*/)
        {
        
        }

        void KilledUnit(Unit* /*victim*/)
        {
        
        }

        void UpdateAI(uint32 diff)
        {
		if(instance && instance->GetData(DATA_LICHKING_EVENT)==NOT_STARTED)
			me->DisappearAndDie();
            // Return since we have no target
            if (!UpdateVictim())
                return;
            if(!ActivationCheck(diff))
			return;
            
            vomit_timer += diff;
            cleave_timer += diff;
            
            if(vomit_timer > VOMIT_TIMER){
		if(me->GetVictim() && (me->GetDistance(me->GetVictim()) < 10.0f)){
			DoCast(me->GetVictim(), SPELL_VOMIT);
			vomit_timer = 0;
			VOMIT_TIMER = VOMIT_TIMER_MIN + rand() % (VOMIT_TIMER_MAX-VOMIT_TIMER_MIN);
		}
            }else if(cleave_timer > CLEAVE_TIMER){
		DoCast(SPELL_CLEAVE);
		cleave_timer = 0;
            }

        
            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_TW_halls_of_reflection_trash()
{
    new TW_npc_ghostly_priest();
    new TW_npc_phantom_mage();
    new TW_npc_phantom_hallucination();
    new TW_npc_shadowy_mercenary();
    new TW_npc_spectral_footman();
    new TW_npc_tortured_rifleman();
    new TW_npc_risen_witch_doctor();
    new TW_npc_raging_ghoul();
    new TW_npc_lumbering_abomination();
}
