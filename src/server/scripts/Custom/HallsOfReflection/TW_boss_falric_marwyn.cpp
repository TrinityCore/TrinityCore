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
#include "TW_halls_of_reflection.h"

///Ruben: Base class. Rather have it defined in .cpp, as implementations in .h are messy.
struct TW_boss_horAI : ScriptedAI
{
    TW_boss_horAI(Creature* creature) : ScriptedAI(creature)/*, summons(creature)*/
    {
        instance = me->GetInstanceScript();
    }

    InstanceScript* instance;
    EventMap events;

    void Reset()
    {
        events.Reset();
        me->SetVisible(false);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
        me->SetReactState(REACT_PASSIVE);
    }

    void DamageTaken(Unit* /*who*/, uint32 &uiDamage)
    {
        if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE)){
		uiDamage = 0;
        }
    }

    void DoAction(int32 actionID)
    {
        switch (actionID)
        {
            case ACTION_ENTER_COMBAT:  // called by InstanceScript when boss shall enter in combat.
                // Just in case. Should have been done by InstanceScript
                me->SetVisible(true);

                // Reset flags
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, 832);//Some remaining flags that should not be active.
                me->SetReactState(REACT_AGGRESSIVE);

                if (Unit* unit = me->SelectNearestTarget())
                    AttackStart(unit);

                DoZoneInCombat();
                break;
        }
    }
};

///Ruben: Falric's script
// enum FalricYells
// {
//     F_SAY_AGGRO                                     = -1668050,
//     F_SAY_SLAY_1                                    = -1668051,
//     F_SAY_SLAY_2                                    = -1668052,
//     F_SAY_DEATH                                     = -1668053,
//     F_SAY_IMPENDING_DESPAIR                         = -1668054,
//     F_SAY_DEFILING_HORROR                           = -1668055,
// };

enum FalricYells{
	F_SAY_AGGRO,
	F_SAY_SLAY_1,
	F_SAY_SLAY_2,
	F_SAY_DEATH,
	F_SAY_IMPENDING_DESPAIR,
	F_SAY_DEFILING_HORROR,
};

enum FalricSpells
{
    F_SPELL_QUIVERING_STRIKE                        = 72422,
    F_SPELL_IMPENDING_DESPAIR                       = 72426,
    F_SPELL_DEFILING_HORROR                         = 72435,
//     F_SPELL_HOPELESSNESS                            = 72395,
//     F_H_SPELL_HOPELESSNESS                          = 72390, // TODO: not in dbc. Add in DB.
};

#define DEFILING_HORROR_TIMER		4000

#define F_SPELL_HOPELESSNESS_1		72395
#define F_SPELL_HOPELESSNESS_2		72396
#define F_SPELL_HOPELESSNESS_3		72397
#define F_SPELL_HOPELESSNESS	(uiHopelessnessCount==1?F_SPELL_HOPELESSNESS_1:(uiHopelessnessCount==2?F_SPELL_HOPELESSNESS_2:F_SPELL_HOPELESSNESS_3))
#define F_H_SPELL_HOPELESSNESS_1	72390
#define F_H_SPELL_HOPELESSNESS_2	72391
#define F_H_SPELL_HOPELESSNESS_3	72393
#define F_H_SPELL_HOPELESSNESS 	(uiHopelessnessCount==1?F_H_SPELL_HOPELESSNESS_1:(uiHopelessnessCount==2?F_H_SPELL_HOPELESSNESS_2:F_H_SPELL_HOPELESSNESS_3))

enum FalricEvents
{
    F_EVENT_NONE,
    F_EVENT_QUIVERING_STRIKE,
    F_EVENT_IMPENDING_DESPAIR,
    F_EVENT_DEFILING_HORROR,
};

class TW_boss_falric : public CreatureScript
{
public:
    TW_boss_falric() : CreatureScript("TW_boss_falric") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_boss_falricAI(creature);
    }

    struct TW_boss_falricAI : public TW_boss_horAI
    {
        TW_boss_falricAI(Creature* creature) : TW_boss_horAI(creature) {}

        uint8 uiHopelessnessCount;
        uint32 defiling_horror_timer;

        void Reset()
        {
            TW_boss_horAI::Reset();

            uiHopelessnessCount = 0;
            defiling_horror_timer = 0;

            if (instance)
                instance->SetData(DATA_FALRIC_EVENT, NOT_STARTED);
        }
        
        
	void JustReachedHome(){
		if(instance)
			instance->SetData(DATA_FALRIC_EVENT, FAIL);
	}

        void EnterCombat(Unit* /*who*/)
        {
            Talk(F_SAY_AGGRO);
            if (instance)
                instance->SetData(DATA_FALRIC_EVENT, IN_PROGRESS);

            events.ScheduleEvent(F_EVENT_QUIVERING_STRIKE, 23000);
            events.ScheduleEvent(F_EVENT_IMPENDING_DESPAIR, 9000);
            events.ScheduleEvent(F_EVENT_DEFILING_HORROR, urand(15000, 25000)); // TODO adjust timer.
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(F_SAY_DEATH);

            if (instance)
                instance->SetData(DATA_FALRIC_EVENT, DONE);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(RAND(F_SAY_SLAY_1, F_SAY_SLAY_2));
        }

        void UpdateAI(uint32 diff)
        {
            // Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);
            if(defiling_horror_timer < diff)
		defiling_horror_timer = 0;
	    else
		defiling_horror_timer -= diff;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case F_EVENT_QUIVERING_STRIKE:
                    DoCast(F_SPELL_QUIVERING_STRIKE);
                    events.ScheduleEvent(F_EVENT_QUIVERING_STRIKE, 10000);
                    break;
                case F_EVENT_IMPENDING_DESPAIR:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        Talk(F_SAY_IMPENDING_DESPAIR);
                        DoCast(target, F_SPELL_IMPENDING_DESPAIR);
                    }
                    events.ScheduleEvent(F_EVENT_IMPENDING_DESPAIR, 13000);
                    break;
                case F_EVENT_DEFILING_HORROR:///TODO: add auras more or less...
                    DoCast(F_SPELL_DEFILING_HORROR);//Doesn't do much other than have him look awesome.
                    Unit *target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0);
                    for(uint8 i = 1; target != 0; i++){
						if(target->GetTypeId() == TYPEID_PLAYER)
							me->AddAura(F_SPELL_DEFILING_HORROR, target);
						target = SelectTarget(SELECT_TARGET_TOPAGGRO, i);
                    }
                    defiling_horror_timer = DEFILING_HORROR_TIMER;
                    Talk(F_SAY_DEFILING_HORROR);
                    events.ScheduleEvent(F_EVENT_DEFILING_HORROR, urand(15000, 25000)); // TODO adjust timer.
                    break;
            }

            if ((uiHopelessnessCount < 1 && HealthBelowPct(66))
                || (uiHopelessnessCount < 2 && HealthBelowPct(33))
                || (uiHopelessnessCount < 3 && HealthBelowPct(10)))
            {
		me->RemoveAurasDueToSpell(DUNGEON_MODE(F_SPELL_HOPELESSNESS, F_H_SPELL_HOPELESSNESS));
                uiHopelessnessCount++;
                DoCast(DUNGEON_MODE(F_SPELL_HOPELESSNESS, F_H_SPELL_HOPELESSNESS));
            }

            if(defiling_horror_timer == 0)
		DoMeleeAttackIfReady();
        }
    };

};

void AddSC_TW_boss_falric()
{
    new TW_boss_falric();
}

///Ruben: Marwyn's script.
// enum MarwynYells
// {
//     M_SAY_AGGRO                                     = -1668060,
//     M_SAY_SLAY_1                                    = -1668061,
//     M_SAY_SLAY_2                                    = -1668062,
//     M_SAY_DEATH                                     = -1668063,
//     M_SAY_CORRUPTED_FLESH_1                         = -1668064,
//     M_SAY_CORRUPTED_FLESH_2                         = -1668065,
// };

enum MarwynYells{
	M_SAY_AGGRO,
	M_SAY_SLAY_1,
	M_SAY_SLAY_2,
	M_SAY_DEATH,
	M_SAY_CORRUPTED_FLESH_1,
	M_SAY_CORRUPTED_FLESH_2,
};

enum MarwynSpells
{
    M_SPELL_OBLITERATE                              = 72360,
    M_SPELL_WELL_OF_CORRUPTION                      = 72362,
    M_SPELL_CORRUPTED_FLESH                         = 72363,
    M_SPELL_SHARED_SUFFERING                        = 72368,
};

enum MarwynEvents
{
    M_EVENT_NONE,
    M_EVENT_OBLITERATE,
    M_EVENT_WELL_OF_CORRUPTION,
    M_EVENT_CORRUPTED_FLESH,
    M_EVENT_SHARED_SUFFERING,
};

class TW_boss_marwyn : public CreatureScript
{
public:
    TW_boss_marwyn() : CreatureScript("TW_boss_marwyn") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_boss_marwynAI(creature);
    }

    struct TW_boss_marwynAI : public TW_boss_horAI
    {
        TW_boss_marwynAI(Creature* creature) : TW_boss_horAI(creature) {}

        void Reset()
        {
            TW_boss_horAI::Reset();

            if (instance)
                instance->SetData(DATA_MARWYN_EVENT, NOT_STARTED);
        }
        
        void EnterEvadeMode(){
		if(instance)
			instance->SetData(DATA_MARWYN_EVENT, FAIL);
	}

        void EnterCombat(Unit* /*who*/)
        {
            Talk(M_SAY_AGGRO);
            if (instance)
                instance->SetData(DATA_MARWYN_EVENT, IN_PROGRESS);

            events.ScheduleEvent(M_EVENT_OBLITERATE, 30000);          // TODO Check timer
            events.ScheduleEvent(M_EVENT_WELL_OF_CORRUPTION, 13000);
            events.ScheduleEvent(M_EVENT_CORRUPTED_FLESH, 20000);
            events.ScheduleEvent(M_EVENT_SHARED_SUFFERING, 20000);    // TODO Check timer
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(M_SAY_DEATH);

            if (instance)
                instance->SetData(DATA_MARWYN_EVENT, DONE);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            Talk(RAND(M_SAY_SLAY_1, M_SAY_SLAY_2));
        }

        void UpdateAI(uint32 diff)
        {
            // Return since we have no target
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case M_EVENT_OBLITERATE:
                    DoCast(M_SPELL_OBLITERATE);
                    events.ScheduleEvent(M_EVENT_OBLITERATE, 30000);
                    break;
                case M_EVENT_WELL_OF_CORRUPTION:
                    DoCast(M_SPELL_WELL_OF_CORRUPTION);
                    events.ScheduleEvent(M_EVENT_WELL_OF_CORRUPTION, 13000);
                    break;
                case M_EVENT_CORRUPTED_FLESH:
                    Talk(RAND(M_SAY_CORRUPTED_FLESH_1, M_SAY_CORRUPTED_FLESH_2));
                    DoCast(M_SPELL_CORRUPTED_FLESH);
                    events.ScheduleEvent(M_EVENT_CORRUPTED_FLESH, 20000);
                    break;
                case M_EVENT_SHARED_SUFFERING:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        DoCast(target, M_SPELL_SHARED_SUFFERING);
                    events.ScheduleEvent(M_EVENT_SHARED_SUFFERING, 20000);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_TW_boss_marwyn()
{
    new TW_boss_marwyn();
}
