/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: Boss_Ingvar_The_Plunderer
SD%Complete: 95
SDComment: Some Problems with Annhylde Movement, Blizzlike Timers (just shadow axe summon needs a new timer)
SDCategory: Udgarde Keep
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "utgarde_keep.h"

enum Yells
{
    YELL_AGGRO_1                                = 0,
    YELL_KILL_1                                 = 1,
    YELL_DEAD_1                                 = 2,

    YELL_AGGRO_2                                = 0,
    YELL_KILL_2                                 = 1,
    YELL_DEAD_2                                 = 2
};

enum Creatures
{
    NPC_INGVAR_HUMAN                            = 23954,
    NPC_ANNHYLDE_THE_CALLER                     = 24068,
    NPC_INGVAR_UNDEAD                           = 23980,
    NPC_THROW_TARGET                            = 23996,
};

enum Events
{
    EVENT_CLEAVE = 1,
    EVENT_SMASH,
    EVENT_STAGGERING_ROAR,
    EVENT_ENRAGE,

    EVENT_DARK_SMASH,
    EVENT_DREADFUL_ROAR,
    EVENT_WOE_STRIKE,
    EVENT_SHADOW_AXE,
    EVENT_JUST_TRANSFORMED,
    EVENT_SUMMON_BANSHEE,

    EVENT_RESURRECT_1,
    EVENT_RESURRECT_2
};

enum Phases
{
    PHASE_HUMAN = 1,
    PHASE_UNDEAD,
    PHASE_EVENT
};

enum Spells
{
    // Ingvar Spells human form
    SPELL_CLEAVE                                = 42724,
    SPELL_SMASH                                 = 42669,
    SPELL_STAGGERING_ROAR                       = 42708,
    SPELL_ENRAGE                                = 42705,

    SPELL_INGVAR_FEIGN_DEATH                    = 42795,
    SPELL_SUMMON_BANSHEE                        = 42912,
    SPELL_SCOURG_RESURRECTION                   = 42863, // Spawn resurrect effect around Ingvar

    // Ingvar Spells undead form
    SPELL_DARK_SMASH                            = 42723,
    SPELL_DREADFUL_ROAR                         = 42729,
    SPELL_WOE_STRIKE                            = 42730,

    SPELL_SHADOW_AXE_SUMMON                     = 42748,

    // Spells for Annhylde
    SPELL_SCOURG_RESURRECTION_HEAL              = 42704, // Heal Max + DummyAura
    SPELL_SCOURG_RESURRECTION_BEAM              = 42857, // Channeling Beam of Annhylde
    SPELL_SCOURG_RESURRECTION_DUMMY             = 42862, // Some Emote Dummy?
    SPELL_INGVAR_TRANSFORM                      = 42796
};

class boss_ingvar_the_plunderer : public CreatureScript
{
    public:
        boss_ingvar_the_plunderer() : CreatureScript("boss_ingvar_the_plunderer") { }

        struct boss_ingvar_the_plundererAI : public BossAI
        {
            boss_ingvar_the_plundererAI(Creature* creature) : BossAI(creature, DATA_INGVAR)
            {
                _isUndead = false;
            }

            void Reset() OVERRIDE
            {
                if (_isUndead)
                    me->UpdateEntry(NPC_INGVAR_HUMAN);

                _isUndead = false;

                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->SetStandState(UNIT_STAND_STATE_STAND);

                _Reset();
                events.SetPhase(PHASE_HUMAN);

                events.ScheduleEvent(EVENT_CLEAVE, urand(6, 12)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                events.ScheduleEvent(EVENT_STAGGERING_ROAR, urand(18, 21)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                events.ScheduleEvent(EVENT_ENRAGE, urand(7, 14)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                events.ScheduleEvent(EVENT_SMASH, urand(12, 17)*IN_MILLISECONDS, 0, PHASE_HUMAN);
            }

            void DamageTaken(Unit* /*doneBy*/, uint32& damage) OVERRIDE
            {
                if (damage >= me->GetHealth() && !_isUndead)
                {
                    //DoCast(me, SPELL_INGVAR_FEIGN_DEATH, true);  // Dont work ???
                    // visuel hack
                    me->SetHealth(0);
                    me->InterruptNonMeleeSpells(true);
                    me->RemoveAllAuras();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->GetMotionMaster()->MovementExpired(false);
                    me->GetMotionMaster()->MoveIdle();
                    me->SetStandState(UNIT_STAND_STATE_DEAD);
                    // visuel hack end

                    events.SetPhase(PHASE_EVENT);
                    events.ScheduleEvent(EVENT_SUMMON_BANSHEE, 3 * IN_MILLISECONDS, 0, PHASE_EVENT);

                    Talk(YELL_DEAD_1);
                }

                if (events.IsInPhase(PHASE_EVENT))
                    damage = 0;
            }

            void StartZombiePhase()
            {
                _isUndead = true;
                me->UpdateEntry(NPC_INGVAR_UNDEAD);
                events.ScheduleEvent(EVENT_JUST_TRANSFORMED, 2 * IN_MILLISECONDS, 0, PHASE_EVENT);

                Talk(YELL_AGGRO_2);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _EnterCombat();

                if (!_isUndead)
                    Talk(YELL_AGGRO_1);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                _JustDied();
                Talk(YELL_DEAD_2);

                // Ingvar has NPC_INGVAR_UNDEAD id in this moment, so we have to update encounter state for his original id
                instance->UpdateEncounterState(ENCOUNTER_CREDIT_KILL_CREATURE, NPC_INGVAR_HUMAN, me);
            }

            void ScheduleSecondPhase()
            {
                events.SetPhase(PHASE_UNDEAD);
                events.ScheduleEvent(EVENT_DARK_SMASH, urand(14, 18)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                events.ScheduleEvent(EVENT_DREADFUL_ROAR, urand(18, 22)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                events.ScheduleEvent(EVENT_WOE_STRIKE, urand(10, 14)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                events.ScheduleEvent(EVENT_SHADOW_AXE, 30*IN_MILLISECONDS, 0, PHASE_UNDEAD);
            }

            void KilledUnit(Unit* /*victim*/) OVERRIDE
            {
                Talk(_isUndead ? YELL_KILL_1 : YELL_KILL_2);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim() && !events.IsInPhase(PHASE_EVENT))
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        // PHASE ONE
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, urand(6, 12)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                            break;
                        case EVENT_STAGGERING_ROAR:
                            DoCast(me, SPELL_STAGGERING_ROAR);
                            events.ScheduleEvent(EVENT_STAGGERING_ROAR, urand(18, 22)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                            break;
                        case EVENT_ENRAGE:
                            DoCast(me, SPELL_ENRAGE);
                            events.ScheduleEvent(EVENT_ENRAGE, urand(7, 14)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                            break;
                        case EVENT_SMASH:
                            DoCastAOE(SPELL_SMASH);
                            events.ScheduleEvent(EVENT_SMASH, urand(12, 16)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                            break;
                        case EVENT_JUST_TRANSFORMED:
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            me->SetInCombatWithZone();
                            me->GetMotionMaster()->MoveChase(me->GetVictim());
                            ScheduleSecondPhase();
                            return;
                        case EVENT_SUMMON_BANSHEE:
                            DoCast(me, SPELL_SUMMON_BANSHEE);
                            return;
                        // PHASE TWO
                        case EVENT_DARK_SMASH:
                            DoCastVictim(SPELL_DARK_SMASH);
                            events.ScheduleEvent(EVENT_DARK_SMASH, urand(12, 16)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                            break;
                        case EVENT_DREADFUL_ROAR:
                            DoCast(me, SPELL_DREADFUL_ROAR);
                            events.ScheduleEvent(EVENT_DREADFUL_ROAR, urand(18, 22)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                            break;
                        case EVENT_WOE_STRIKE:
                            DoCastVictim(SPELL_WOE_STRIKE);
                            events.ScheduleEvent(EVENT_WOE_STRIKE, urand(10, 14)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                            break;
                        case EVENT_SHADOW_AXE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 1))
                                DoCast(target, SPELL_SHADOW_AXE_SUMMON);

                            events.ScheduleEvent(EVENT_SHADOW_AXE, 30*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool _isUndead;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetUtgardeKeepAI<boss_ingvar_the_plundererAI>(creature);
        }
};

class npc_annhylde_the_caller : public CreatureScript
{
    public:
        npc_annhylde_the_caller() : CreatureScript("npc_annhylde_the_caller") { }

        struct npc_annhylde_the_callerAI : public ScriptedAI
        {
            npc_annhylde_the_callerAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() OVERRIDE
            {
                _events.Reset();

                //! HACK: Creature's can't have MOVEMENTFLAG_FLYING
                me->SetHover(true);

                me->GetPosition(x, y, z);
                DoTeleportTo(x+1, y, z+30);

                if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_INGVAR)))
                {
                    me->GetMotionMaster()->MovePoint(1, x, y, z+15);

        //            Talk(YELL_RESSURECT);
                }
            }

            void MovementInform(uint32 type, uint32 id) OVERRIDE
            {
                if (type != POINT_MOTION_TYPE)
                    return;
    
                if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_INGVAR)))
                {
                    switch (id)
                    {
                        case 1:
                            ingvar->RemoveAura(SPELL_SUMMON_BANSHEE);
                            ingvar->CastSpell(ingvar, SPELL_SCOURG_RESURRECTION_DUMMY, true);
                            DoCast(ingvar, SPELL_SCOURG_RESURRECTION_BEAM);
                            _events.ScheduleEvent(EVENT_RESURRECT_1, 8000);
                            break;
                        case 2:
                            me->DespawnOrUnsummon();
                            break;
                        default:
                            break;
                    }
                }
            }

            void AttackStart(Unit* /*who*/) OVERRIDE { }
            void MoveInLineOfSight(Unit* /*who*/) OVERRIDE { }
            void EnterCombat(Unit* /*who*/) OVERRIDE { }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RESURRECT_1:
                            if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_INGVAR)))
                            {
                                ingvar->SetStandState(UNIT_STAND_STATE_STAND);
                                ingvar->CastSpell(ingvar, SPELL_SCOURG_RESURRECTION_HEAL, false);
                            }
                            _events.ScheduleEvent(EVENT_RESURRECT_2, 3000);
                            break;
                        case EVENT_RESURRECT_2:
                            if (Creature* ingvar = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_INGVAR)))
                            {
                                ingvar->RemoveAurasDueToSpell(SPELL_SCOURG_RESURRECTION_DUMMY);

                                if (ingvar->GetVictim())
                                    if (boss_ingvar_the_plunderer::boss_ingvar_the_plundererAI* ai = CAST_AI(boss_ingvar_the_plunderer::boss_ingvar_the_plundererAI, ingvar->AI()))
                                        ai->StartZombiePhase();

                                me->GetMotionMaster()->MovePoint(2, x+1, y, z+30);
                            }
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            float x, y, z;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetUtgardeKeepAI<npc_annhylde_the_callerAI>(creature);
        }
};

enum ShadowAxe
{
    SPELL_SHADOW_AXE_DAMAGE                     = 42750,
    H_SPELL_SHADOW_AXE_DAMAGE                   = 59719,
    POINT_TARGET                                = 28
};

class npc_ingvar_throw_dummy : public CreatureScript
{
public:
    npc_ingvar_throw_dummy() : CreatureScript("npc_ingvar_throw_dummy") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_ingvar_throw_dummyAI(creature);
    }

    struct npc_ingvar_throw_dummyAI : public ScriptedAI
    {
        npc_ingvar_throw_dummyAI(Creature* creature) : ScriptedAI(creature)
        {
        }

        void Reset() OVERRIDE
        {
            if (Creature* target = me->FindNearestCreature(NPC_THROW_TARGET, 50.0f))
            {
                float x, y, z;
                target->GetPosition(x, y, z);
                me->GetMotionMaster()->MoveCharge(x, y, z, 42.0f, POINT_TARGET);
                target->DisappearAndDie();
            }
            else
                me->DisappearAndDie();
        }

        void MovementInform(uint32 type, uint32 id) OVERRIDE
        {
            if (type == EFFECT_MOTION_TYPE && id == POINT_TARGET)
            {
                DoCast(me, SPELL_SHADOW_AXE_DAMAGE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                me->DespawnOrUnsummon(10000);
            }
        }
    };
};

void AddSC_boss_ingvar_the_plunderer()
{
    new boss_ingvar_the_plunderer();
    new npc_annhylde_the_caller();
    new npc_ingvar_throw_dummy();
}
