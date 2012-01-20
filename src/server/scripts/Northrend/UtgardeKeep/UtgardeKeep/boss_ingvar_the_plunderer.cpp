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

/* ScriptData
SDName: Boss_Ingvar_The_Plunderer
SD%Complete: 95
SDComment: Some Problems with Annhylde Movement, Blizzlike Timers
SDCategory: Udgarde Keep
EndScriptData */

#include "ScriptPCH.h"
#include "utgarde_keep.h"

enum Yells
{
    //Yells Ingvar
    YELL_AGGRO_1                                = -1574005,
    YELL_AGGRO_2                                = -1574006,

    YELL_DEAD_1                                 = -1574007,
    YELL_DEAD_2                                 = -1574008,

    YELL_KILL_1                                 = -1574009,
    YELL_KILL_2                                 = -1574010,
};

enum Creatures
{
    MOB_INGVAR_HUMAN                            = 23954,
    MOB_ANNHYLDE_THE_CALLER                     = 24068,
    MOB_INGVAR_UNDEAD                           = 23980,
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
    EVENT_SHADOW_AXE
};

enum Phases
{
    PHASE_HUMAN = 1,
    PHASE_UNDEAD,
};

enum Spells
{
    //Ingvar Spells human form
    SPELL_CLEAVE                                = 42724,
    SPELL_SMASH                                 = 42669,
    SPELL_STAGGERING_ROAR                       = 42708,
    SPELL_ENRAGE                                = 42705,

    SPELL_INGVAR_FEIGN_DEATH                    = 42795,
    SPELL_SUMMON_BANSHEE                        = 42912,
    SPELL_SCOURG_RESURRECTION                   = 42863, // Spawn resurrect effect around Ingvar

    //Ingvar Spells undead form
    SPELL_DARK_SMASH                            = 42723,
    SPELL_DREADFUL_ROAR                         = 42729,
    SPELL_WOE_STRIKE                            = 42730,

    ENTRY_THROW_TARGET                          = 23996,
    SPELL_SHADOW_AXE_SUMMON                     = 42749
};

class boss_ingvar_the_plunderer : public CreatureScript
{
public:
    boss_ingvar_the_plunderer() : CreatureScript("boss_ingvar_the_plunderer") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_ingvar_the_plundererAI(creature);
    }

    struct boss_ingvar_the_plundererAI : public ScriptedAI
    {
        boss_ingvar_the_plundererAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        InstanceScript* instance;

        bool bIsUndead;
        bool bEventInProgress;

        uint32 uiCleaveTimer;
        uint32 uiSmashTimer;
        uint32 uiEnrageTimer;
        uint32 uiRoarTimer;
        uint32 uiSpawnResTimer;

        void Reset()
        {
            if (bIsUndead)
                me->UpdateEntry(MOB_INGVAR_HUMAN);

            bIsUndead = false;
            bEventInProgress = false;

            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            me->SetStandState(UNIT_STAND_STATE_STAND);

            events.Reset();
            events.SetPhase(PHASE_HUMAN);

            events.ScheduleEvent(EVENT_CLEAVE, urand(6,12)*IN_MILLISECONDS, 0, PHASE_HUMAN);
            events.ScheduleEvent(EVENT_STAGGERING_ROAR, urand(18,21)*IN_MILLISECONDS, 0, PHASE_HUMAN);
            events.ScheduleEvent(EVENT_ENRAGE, urand(7,14)*IN_MILLISECONDS, 0, PHASE_HUMAN);
            events.ScheduleEvent(EVENT_SMASH, urand(12,17)*IN_MILLISECONDS, 0, PHASE_HUMAN);

            events.ScheduleEvent(EVENT_DARK_SMASH, urand(14,22)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
            events.ScheduleEvent(EVENT_DREADFUL_ROAR, urand(18,21)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
            events.ScheduleEvent(EVENT_WOE_STRIKE, urand(10,14)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
            events.ScheduleEvent(EVENT_SHADOW_AXE, 30*IN_MILLISECONDS, 0, PHASE_UNDEAD);

            uiSpawnResTimer = 3000;

            if (instance)
                instance->SetData(DATA_INGVAR_EVENT, NOT_STARTED);
        }

        void DamageTaken(Unit* /*done_by*/, uint32 &damage)
        {
            if (damage >= me->GetHealth() && !bIsUndead)
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

                bEventInProgress = true;
                bIsUndead = true;
                events.SetPhase(PHASE_UNDEAD);

                DoScriptText(YELL_DEAD_1, me);
            }

            if (bEventInProgress)
            {
                damage = 0;
            }
        }

        void StartZombiePhase()
        {
            bIsUndead = true;
            bEventInProgress = false;
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->UpdateEntry(MOB_INGVAR_UNDEAD);
            me->SetInCombatWith(me->getVictim());
            me->GetMotionMaster()->MoveChase(me->getVictim());

            DoScriptText(YELL_AGGRO_2, me);
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(YELL_AGGRO_1, me);

            if (instance)
                instance->SetData(DATA_INGVAR_EVENT, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(YELL_DEAD_2, me);

            if (instance)
            {
                // Ingvar has MOB_INGVAR_UNDEAD id in this moment, so we have to update encounter state for his original id
                instance->UpdateEncounterState(ENCOUNTER_CREDIT_KILL_CREATURE, MOB_INGVAR_HUMAN, me);
                instance->SetData(DATA_INGVAR_EVENT, DONE);
            }
        }

        void KilledUnit(Unit* /*victim*/)
        {
            if (bIsUndead)
                DoScriptText(YELL_KILL_1, me);
            else
                DoScriptText(YELL_KILL_2, me);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (bEventInProgress)
            {
                if (uiSpawnResTimer)
                {
                    if (uiSpawnResTimer <= diff)
                    {
                        DoCast(me, SPELL_SUMMON_BANSHEE); // Summons directly on caster position
                        // DoCast(me, SPELL_SCOURG_RESURRECTION, true); // Not needed ?
                        uiSpawnResTimer = 0;
                    } else uiSpawnResTimer -= diff;
                }

                return;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    // PHASE ONE
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, urand(6,12)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                        break;
                    case EVENT_STAGGERING_ROAR:
                        DoCast(me, SPELL_STAGGERING_ROAR);
                        events.ScheduleEvent(EVENT_STAGGERING_ROAR, urand(18,21)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                        break;
                    case EVENT_ENRAGE:
                        DoCast(me, SPELL_ENRAGE);
                        events.ScheduleEvent(EVENT_ENRAGE, urand(7,14)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                        break;
                    case EVENT_SMASH:
                        DoCastVictim(SPELL_SMASH);
                        events.ScheduleEvent(EVENT_SMASH, urand(12,17)*IN_MILLISECONDS, 0, PHASE_HUMAN);
                        break;
                    // PHASE TWO
                    case EVENT_DARK_SMASH:
                        DoCastVictim(SPELL_DARK_SMASH);
                        events.ScheduleEvent(EVENT_DARK_SMASH, urand(14,22)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                        break;
                    case EVENT_DREADFUL_ROAR:
                        DoCast(me, SPELL_DREADFUL_ROAR);
                        events.ScheduleEvent(EVENT_DREADFUL_ROAR, urand(18,21)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                        break;
                    case EVENT_WOE_STRIKE:
                        DoCastVictim(SPELL_WOE_STRIKE);
                        events.ScheduleEvent(EVENT_WOE_STRIKE, urand(10,14)*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                        break;
                    case EVENT_SHADOW_AXE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 1))
                        {
                            me->SummonCreature(ENTRY_THROW_TARGET, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 2000);
                            DoCast(me, SPELL_SHADOW_AXE_SUMMON);
                        }
                        events.ScheduleEvent(EVENT_SHADOW_AXE, 30*IN_MILLISECONDS, 0, PHASE_UNDEAD);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    private:
        EventMap events;
    };

};

enum eSpells
{
//we don't have that text in db so comment it until we get this text
//    YELL_RESSURECT                      = -1574025,

//Spells for Annhylde
    SPELL_SCOURG_RESURRECTION_HEAL              = 42704, //Heal Max + DummyAura
    SPELL_SCOURG_RESURRECTION_BEAM              = 42857, //Channeling Beam of Annhylde
    SPELL_SCOURG_RESURRECTION_DUMMY             = 42862, //Some Emote Dummy?
    SPELL_INGVAR_TRANSFORM                      = 42796
};

class mob_annhylde_the_caller : public CreatureScript
{
public:
    mob_annhylde_the_caller() : CreatureScript("mob_annhylde_the_caller") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_annhylde_the_callerAI (creature);
    }

    struct mob_annhylde_the_callerAI : public ScriptedAI
    {
        mob_annhylde_the_callerAI(Creature* c) : ScriptedAI(c)
        {
            instance = c->GetInstanceScript();
        }

        float x, y, z;
        InstanceScript* instance;
        uint32 uiResurectTimer;
        uint32 uiResurectPhase;

        void Reset()
        {
            me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING | MOVEMENTFLAG_HOVER);
            me->SetSpeed(MOVE_SWIM, 1.0f);
            me->SetSpeed(MOVE_RUN, 1.0f);
            me->SetSpeed(MOVE_WALK, 1.0f);
            //me->SetSpeed(MOVE_FLIGHT, 1.0f);

            me->GetPosition(x, y, z);
            DoTeleportTo(x+1, y, z+30);

            Unit* ingvar = Unit::GetUnit(*me, instance ? instance->GetData64(DATA_INGVAR) : 0);
            if (ingvar)
            {
                me->GetMotionMaster()->MovePoint(1, x, y, z+15);

    //            DoScriptText(YELL_RESSURECT, me);
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;
            Unit* ingvar = Unit::GetUnit((*me), instance ? instance->GetData64(DATA_INGVAR) : 0);
            if (ingvar)
            {
                switch (id)
                {
                case 1:
                    ingvar->RemoveAura(SPELL_SUMMON_BANSHEE);
                    ingvar->CastSpell(ingvar, SPELL_SCOURG_RESURRECTION_DUMMY, true);
                    DoCast(ingvar, SPELL_SCOURG_RESURRECTION_BEAM);
                    uiResurectTimer = 8000;
                    uiResurectPhase = 1;
                    break;
                case 2:
                    me->SetVisible(false);
                    me->DealDamage(me, me->GetHealth());
                    me->RemoveCorpse();
                    break;
                }
            }
        }

        void AttackStart(Unit* /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
        void EnterCombat(Unit* /*who*/) {}
        void UpdateAI(const uint32 diff)
        {
            if (uiResurectTimer)
            {
                if (uiResurectTimer <= diff)
                {
                    if (uiResurectPhase == 1)
                    {
                        Unit* ingvar = Unit::GetUnit(*me, instance ? instance->GetData64(DATA_INGVAR) : 0);
                        if (ingvar)
                        {
                            ingvar->SetStandState(UNIT_STAND_STATE_STAND);
                            ingvar->CastSpell(ingvar, SPELL_SCOURG_RESURRECTION_HEAL, false);
                        }
                        uiResurectTimer = 3000;
                        uiResurectPhase = 2;
                    }
                    else if (uiResurectPhase == 2)
                    {
                        if (Creature* ingvar = Unit::GetCreature(*me, instance ? instance->GetData64(DATA_INGVAR) : 0))
                        {
                            ingvar->RemoveAurasDueToSpell(SPELL_SCOURG_RESURRECTION_DUMMY);

                            if (boss_ingvar_the_plunderer::boss_ingvar_the_plundererAI* pAI = CAST_AI(boss_ingvar_the_plunderer::boss_ingvar_the_plundererAI, ingvar->AI()))
                                pAI->StartZombiePhase();

                            me->GetMotionMaster()->MovePoint(2, x+1, y, z+30);
                            ++uiResurectPhase;
                            uiResurectTimer = 0;
                        }
                    }
                } else uiResurectTimer -= diff;
            }
        }
    };
};

enum eShadowAxe
{
    SPELL_SHADOW_AXE_DAMAGE                     = 42750,
    H_SPELL_SHADOW_AXE_DAMAGE                   = 59719
};

class mob_ingvar_throw_dummy : public CreatureScript
{
public:
    mob_ingvar_throw_dummy() : CreatureScript("mob_ingvar_throw_dummy") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_ingvar_throw_dummyAI (creature);
    }

    struct mob_ingvar_throw_dummyAI : public ScriptedAI
    {
        mob_ingvar_throw_dummyAI(Creature* c) : ScriptedAI(c)
        {
        }

        uint32 uiDespawnTimer;

        void Reset()
        {
            Unit* target = me->FindNearestCreature(ENTRY_THROW_TARGET, 50);
            if (target)
            {
                DoCast(me, SPELL_SHADOW_AXE_DAMAGE);
                float x, y, z;
                target->GetPosition(x, y, z);
                me->GetMotionMaster()->MovePoint(0, x, y, z);
            }
            uiDespawnTimer = 7000;
        }
        void AttackStart(Unit* /*who*/) {}
        void MoveInLineOfSight(Unit* /*who*/) {}
        void EnterCombat(Unit* /*who*/) {}
        void UpdateAI(const uint32 diff)
        {
            if (uiDespawnTimer <= diff)
            {
                me->DealDamage(me, me->GetHealth());
                me->RemoveCorpse();
                uiDespawnTimer = 0;
            } else uiDespawnTimer -= diff;
        }
    };

};

void AddSC_boss_ingvar_the_plunderer()
{
    new boss_ingvar_the_plunderer();
    new mob_annhylde_the_caller();
    new mob_ingvar_throw_dummy();
}
