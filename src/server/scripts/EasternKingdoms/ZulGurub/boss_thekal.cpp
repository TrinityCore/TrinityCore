/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Boss_Thekal
SD%Complete: 95
SDComment: Almost finished.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "zulgurub.h"

enum Says
{
    SAY_AGGRO                 = 0,
    SAY_DEATH                 = 1
};

enum Spells
{
    SPELL_MORTALCLEAVE        = 22859, // Phase 1
    SPELL_SILENCE             = 22666, // Phase 1
    SPELL_TIGER_FORM          = 24169, // Phase 1
    SPELL_RESURRECT           = 24173, // Phase 1    // Not used in script.
    SPELL_FRENZY              = 8269,  // Phase 2
    SPELL_FORCEPUNCH          = 24189, // Phase 2
    SPELL_CHARGE              = 24193, // Phase 2
    SPELL_ENRAGE              = 8269,  // Phase 2
    SPELL_SUMMONTIGERS        = 24183, // Phase 2
    // Zealot Lor'Khan Spells
    SPELL_SHIELD              = 20545,
    SPELL_BLOODLUST           = 24185,
    SPELL_GREATERHEAL         = 24208,
    SPELL_DISARM              = 6713,
    // Zealot Zath Spells
    SPELL_SWEEPINGSTRIKES     = 18765,
    SPELL_SINISTERSTRIKE      = 15581,
    SPELL_GOUGE               = 12540,
    SPELL_KICK                = 15614,
    SPELL_BLIND               = 21060
};

enum Events
{
    EVENT_MORTALCLEAVE        = 1, // Phase 1
    EVENT_SILENCE             = 2, // Phase 1
    EVENT_CHECK_TIMER         = 3, // Phase 1
    EVENT_RESURRECT_TIMER     = 4, // Phase 1
    EVENT_FRENZY              = 5, // Phase 2
    EVENT_FORCEPUNCH          = 6, // Phase 2
    EVENT_SPELL_CHARGE        = 7, // Phase 2
    EVENT_ENRAGE              = 8, // Phase 2
    EVENT_SUMMONTIGERS        = 9  // Phase 2
};

enum Phases
{
    PHASE_ONE                 = 1,
    PHASE_TWO                 = 2
};

class boss_thekal : public CreatureScript
{
    public: boss_thekal() : CreatureScript("boss_thekal") { }

        struct boss_thekalAI : public BossAI
        {
            boss_thekalAI(Creature* creature) : BossAI(creature, DATA_THEKAL) { }

            bool Enraged;
            bool WasDead;

            void Reset() OVERRIDE
            {
                if (events.IsInPhase(PHASE_TWO))
                    me->HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, 35.0f, false); // hack
                _Reset();
                Enraged = false;
                WasDead = false;
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_MORTALCLEAVE, 4000, 0, PHASE_ONE);     // Phase 1
                events.ScheduleEvent(EVENT_SILENCE, 9000, 0, PHASE_ONE);          // Phase 1
                events.ScheduleEvent(EVENT_CHECK_TIMER, 10000, 0, PHASE_ONE);     // Phase 1
                events.ScheduleEvent(EVENT_RESURRECT_TIMER, 10000, 0, PHASE_ONE); // Phase 1
                Talk(SAY_AGGRO);
            }

            void JustReachedHome() OVERRIDE
            {
                instance->SetBossState(DATA_THEKAL, NOT_STARTED);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                        case EVENT_MORTALCLEAVE:
                            DoCastVictim(SPELL_MORTALCLEAVE, true);
                            events.ScheduleEvent(EVENT_MORTALCLEAVE, urand(15000, 20000), 0, PHASE_ONE);
                            break;
                        case EVENT_SILENCE:
                            DoCastVictim(SPELL_SILENCE, true);
                            events.ScheduleEvent(EVENT_SILENCE, urand(20000, 25000), 0, PHASE_ONE);
                            break;
                        case EVENT_RESURRECT_TIMER:
                            //Thekal will transform to Tiger if he died and was not resurrected after 10 seconds.
                            if (WasDead)
                            {
                                DoCast(me, SPELL_TIGER_FORM); // SPELL_AURA_TRANSFORM
                                me->SetObjectScale(2.00f);
                                me->SetStandState(UNIT_STAND_STATE_STAND);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                /*
                                const CreatureTemplate* cinfo = me->GetCreatureTemplate();
                                me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg +((cinfo->mindmg/100) * 40)));
                                me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg +((cinfo->maxdmg/100) * 40)));
                                me->UpdateDamagePhysical(BASE_ATTACK);
                                */
                                me->HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, 40.0f, true); // hack
                                DoResetThreat();
                                events.ScheduleEvent(EVENT_FRENZY, 30000, 0, PHASE_TWO);          // Phase 2
                                events.ScheduleEvent(EVENT_FORCEPUNCH, 4000, 0, PHASE_TWO);       // Phase 2
                                events.ScheduleEvent(EVENT_SPELL_CHARGE, 12000, 0, PHASE_TWO);    // Phase 2
                                events.ScheduleEvent(EVENT_ENRAGE, 32000, 0, PHASE_TWO);          // Phase 2
                                events.ScheduleEvent(EVENT_SUMMONTIGERS, 25000, 0, PHASE_TWO);    // Phase 2
                                events.SetPhase(PHASE_TWO);
                            }
                            events.ScheduleEvent(EVENT_RESURRECT_TIMER, 10000, 0, PHASE_ONE);
                            break;
                        case EVENT_CHECK_TIMER:
                            //Check_Timer for the death of LorKhan and Zath.
                            if (!WasDead)
                            {
                                if (instance->GetBossState(DATA_LORKHAN) == SPECIAL)
                                {
                                    //Resurrect LorKhan
                                    if (Unit* pLorKhan = Unit::GetUnit(*me, instance->GetData64(DATA_LORKHAN)))
                                    {
                                        pLorKhan->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                                        pLorKhan->setFaction(14);
                                        pLorKhan->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                        pLorKhan->SetFullHealth();
                                        instance->SetData(DATA_LORKHAN, DONE);
                                    }
                                }

                                if (instance->GetBossState(DATA_ZATH) == SPECIAL)
                                {
                                    //Resurrect Zath
                                    if (Unit* pZath = Unit::GetUnit(*me, instance->GetData64(DATA_ZATH)))
                                    {
                                        pZath->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                                        pZath->setFaction(14);
                                        pZath->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                        pZath->SetFullHealth();
                                        instance->SetBossState(DATA_ZATH, DONE);
                                    }
                                }
                            }
                            events.ScheduleEvent(EVENT_CHECK_TIMER, 5000, 0, PHASE_ONE);
                            break;
                        case EVENT_FRENZY:
                            DoCast(me, SPELL_FRENZY);
                            events.ScheduleEvent(EVENT_FRENZY, 30000, 0, PHASE_TWO);
                            break;
                        case EVENT_FORCEPUNCH:
                            DoCastVictim(SPELL_FORCEPUNCH, true);
                            events.ScheduleEvent(EVENT_FORCEPUNCH, urand(16000, 21000), 0, PHASE_TWO);
                            break;
                        case EVENT_CHARGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            {
                                DoCast(target, SPELL_CHARGE);
                                DoResetThreat();
                                AttackStart(target);
                            }
                            events.ScheduleEvent(EVENT_CHARGE, urand(15000, 22000), 0, PHASE_TWO);
                            break;
                        case EVENT_ENRAGE:
                            if (HealthBelowPct(11) && !Enraged)
                            {
                                DoCast(me, SPELL_ENRAGE);
                                Enraged = true;
                            }
                            events.ScheduleEvent(EVENT_ENRAGE, 30000);
                            break;
                        case EVENT_SUMMONTIGERS:
                            DoCastVictim(SPELL_SUMMONTIGERS, true);
                            events.ScheduleEvent(EVENT_SUMMONTIGERS, urand(10000, 14000), 0, PHASE_TWO);
                            break;
                        default:
                            break;
                    }

                    if (me->IsFullHealth() && WasDead)
                        WasDead = false;

                    if ((events.IsInPhase(PHASE_ONE)) && !WasDead && !HealthAbovePct(5))
                    {
                        me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                        me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
                        me->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->SetStandState(UNIT_STAND_STATE_SLEEP);
                        me->AttackStop();
                        instance->SetBossState(DATA_THEKAL, SPECIAL);
                        WasDead=true;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<boss_thekalAI>(creature);
        }
};

//Zealot Lor'Khan
class npc_zealot_lorkhan : public CreatureScript
{
    public: npc_zealot_lorkhan() : CreatureScript("npc_zealot_lorkhan") { }

        struct npc_zealot_lorkhanAI : public ScriptedAI
        {
            npc_zealot_lorkhanAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            uint32 Shield_Timer;
            uint32 BloodLust_Timer;
            uint32 GreaterHeal_Timer;
            uint32 Disarm_Timer;
            uint32 Check_Timer;

            bool FakeDeath;

            InstanceScript* instance;

            void Reset() OVERRIDE
            {
                Shield_Timer = 1000;
                BloodLust_Timer = 16000;
                GreaterHeal_Timer = 32000;
                Disarm_Timer = 6000;
                Check_Timer = 10000;

                FakeDeath = false;

                instance->SetBossState(DATA_LORKHAN, NOT_STARTED);

                me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                //Shield_Timer
                if (Shield_Timer <= diff)
                {
                    DoCast(me, SPELL_SHIELD);
                    Shield_Timer = 61000;
                } else Shield_Timer -= diff;

                //BloodLust_Timer
                if (BloodLust_Timer <= diff)
                {
                    DoCast(me, SPELL_BLOODLUST);
                    BloodLust_Timer = 20000+rand()%8000;
                } else BloodLust_Timer -= diff;

                //Casting Greaterheal to Thekal or Zath if they are in meele range.
                if (GreaterHeal_Timer <= diff)
                {
                    Unit* pThekal = Unit::GetUnit(*me, instance->GetData64(DATA_THEKAL));
                    Unit* pZath = Unit::GetUnit(*me, instance->GetData64(DATA_ZATH));

                    if (!pThekal || !pZath)
                        return;

                    switch (urand(0, 1))
                    {
                        case 0:
                            if (me->IsWithinMeleeRange(pThekal))
                                DoCast(pThekal, SPELL_GREATERHEAL);
                            break;
                        case 1:
                            if (me->IsWithinMeleeRange(pZath))
                                DoCast(pZath, SPELL_GREATERHEAL);
                            break;
                    }

                    GreaterHeal_Timer = 15000+rand()%5000;
                } else GreaterHeal_Timer -= diff;

                //Disarm_Timer
                if (Disarm_Timer <= diff)
                {
                    DoCastVictim(SPELL_DISARM);
                    Disarm_Timer = 15000+rand()%10000;
                } else Disarm_Timer -= diff;

                //Check_Timer for the death of LorKhan and Zath.
                if (!FakeDeath && Check_Timer <= diff)
                {
                    if (instance->GetBossState(DATA_THEKAL) == SPECIAL)
                    {
                        //Resurrect Thekal
                        if (Unit* pThekal = Unit::GetUnit(*me, instance->GetData64(DATA_THEKAL)))
                        {
                            pThekal->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                            pThekal->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            pThekal->setFaction(14);
                            pThekal->SetFullHealth();
                        }
                    }

                    if (instance->GetBossState(DATA_ZATH) == SPECIAL)
                    {
                        //Resurrect Zath
                        if (Unit* pZath = Unit::GetUnit(*me, instance->GetData64(DATA_ZATH)))
                        {
                            pZath->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                            pZath->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            pZath->setFaction(14);
                            pZath->SetFullHealth();
                        }
                    }

                    Check_Timer = 5000;
                } else Check_Timer -= diff;

                if (!HealthAbovePct(5))
                {
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetStandState(UNIT_STAND_STATE_SLEEP);
                    me->setFaction(35);
                    me->AttackStop();

                    instance->SetBossState(DATA_LORKHAN, SPECIAL);

                    FakeDeath = true;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_zealot_lorkhanAI>(creature);
        }
};

//Zealot Zath
class npc_zealot_zath : public CreatureScript
{
    public:

        npc_zealot_zath()
            : CreatureScript("npc_zealot_zath")
        {
        }

        struct npc_zealot_zathAI : public ScriptedAI
        {
            npc_zealot_zathAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            uint32 SweepingStrikes_Timer;
            uint32 SinisterStrike_Timer;
            uint32 Gouge_Timer;
            uint32 Kick_Timer;
            uint32 Blind_Timer;
            uint32 Check_Timer;

            bool FakeDeath;

            InstanceScript* instance;

            void Reset() OVERRIDE
            {
                SweepingStrikes_Timer = 13000;
                SinisterStrike_Timer = 8000;
                Gouge_Timer = 25000;
                Kick_Timer = 18000;
                Blind_Timer = 5000;
                Check_Timer = 10000;

                FakeDeath = false;

                instance->SetBossState(DATA_ZATH, NOT_STARTED);

                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                //SweepingStrikes_Timer
                if (SweepingStrikes_Timer <= diff)
                {
                    DoCastVictim(SPELL_SWEEPINGSTRIKES);
                    SweepingStrikes_Timer = 22000+rand()%4000;
                } else SweepingStrikes_Timer -= diff;

                //SinisterStrike_Timer
                if (SinisterStrike_Timer <= diff)
                {
                    DoCastVictim(SPELL_SINISTERSTRIKE);
                    SinisterStrike_Timer = 8000+rand()%8000;
                } else SinisterStrike_Timer -= diff;

                //Gouge_Timer
                if (Gouge_Timer <= diff)
                {
                    DoCastVictim(SPELL_GOUGE);

                    if (DoGetThreat(me->GetVictim()))
                        DoModifyThreatPercent(me->GetVictim(), -100);

                    Gouge_Timer = 17000+rand()%10000;
                } else Gouge_Timer -= diff;

                //Kick_Timer
                if (Kick_Timer <= diff)
                {
                    DoCastVictim(SPELL_KICK);
                    Kick_Timer = 15000+rand()%10000;
                } else Kick_Timer -= diff;

                //Blind_Timer
                if (Blind_Timer <= diff)
                {
                    DoCastVictim(SPELL_BLIND);
                    Blind_Timer = 10000+rand()%10000;
                } else Blind_Timer -= diff;

                //Check_Timer for the death of LorKhan and Zath.
                if (!FakeDeath && Check_Timer <= diff)
                {
                    if (instance->GetBossState(DATA_LORKHAN) == SPECIAL)
                    {
                        //Resurrect LorKhan
                        if (Unit* pLorKhan = Unit::GetUnit(*me, instance->GetData64(DATA_LORKHAN)))
                        {
                            pLorKhan->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                            pLorKhan->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            pLorKhan->setFaction(14);
                            pLorKhan->SetFullHealth();
                        }
                    }

                    if (instance->GetBossState(DATA_THEKAL) == SPECIAL)
                    {
                        //Resurrect Thekal
                        if (Unit* pThekal = Unit::GetUnit(*me, instance->GetData64(DATA_THEKAL)))
                        {
                            pThekal->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                            pThekal->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            pThekal->setFaction(14);
                            pThekal->SetFullHealth();
                        }
                    }

                    Check_Timer = 5000;
                } else Check_Timer -= diff;

                if (!HealthAbovePct(5))
                {
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetStandState(UNIT_STAND_STATE_SLEEP);
                    me->setFaction(35);
                    me->AttackStop();

                    instance->SetBossState(DATA_ZATH, SPECIAL);

                    FakeDeath = true;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetInstanceAI<npc_zealot_zathAI>(creature);
        }
};

void AddSC_boss_thekal()
{
    new boss_thekal();
    new npc_zealot_lorkhan();
    new npc_zealot_zath();
}
