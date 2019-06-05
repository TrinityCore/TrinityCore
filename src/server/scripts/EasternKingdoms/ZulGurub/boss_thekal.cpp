/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "zulgurub.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

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

// AWFUL HACK WARNING
// To whoever reads this: Zul'Gurub needs your love
// Need to do this calculation to increase/decrease Thekal's damage by 40% (probably some aura missing)
// This is only to compile the scripts after the aura calculation revamp
float const DamageIncrease = 40.0f;
float const DamageDecrease = 100.f / (1.f + DamageIncrease / 100.f) - 100.f;

class boss_thekal : public CreatureScript
{
    public:
        boss_thekal() : CreatureScript("boss_thekal") { }

        struct boss_thekalAI : public BossAI
        {
            boss_thekalAI(Creature* creature) : BossAI(creature, DATA_THEKAL)
            {
                Initialize();
            }

            void Initialize()
            {
                _enraged = false;
                _wasDead = false;
            }

            void Reset() override
            {
                if (events.IsInPhase(PHASE_TWO))
                    me->ApplyStatPctModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, DamageDecrease); // hack
                _Reset();
                Initialize();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                events.ScheduleEvent(EVENT_MORTALCLEAVE, 4s, 0, PHASE_ONE);     // Phase 1
                events.ScheduleEvent(EVENT_SILENCE, 9s, 0, PHASE_ONE);          // Phase 1
                events.ScheduleEvent(EVENT_CHECK_TIMER, 10s, 0, PHASE_ONE);     // Phase 1
                events.ScheduleEvent(EVENT_RESURRECT_TIMER, 10s, 0, PHASE_ONE); // Phase 1
                Talk(SAY_AGGRO);
            }

            void JustReachedHome() override
            {
                instance->SetBossState(DATA_THEKAL, NOT_STARTED);
            }

            void UpdateAI(uint32 diff) override
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
                            events.ScheduleEvent(EVENT_MORTALCLEAVE, 15s, 20s, 0, PHASE_ONE);
                            break;
                        case EVENT_SILENCE:
                            DoCastVictim(SPELL_SILENCE, true);
                            events.ScheduleEvent(EVENT_SILENCE, 20s, 25s, 0, PHASE_ONE);
                            break;
                        case EVENT_RESURRECT_TIMER:
                            // Thekal will transform to Tiger if he died and was not resurrected after 10 seconds.
                            if (_wasDead)
                            {
                                DoCast(me, SPELL_TIGER_FORM); // SPELL_AURA_TRANSFORM
                                me->SetObjectScale(2.00f);
                                me->SetStandState(UNIT_STAND_STATE_STAND);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                /*
                                CreatureTemplate const* cinfo = me->GetCreatureTemplate();
                                me->SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, (cinfo->mindmg +((cinfo->mindmg/100) * 40)));
                                me->SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, (cinfo->maxdmg +((cinfo->maxdmg/100) * 40)));
                                me->UpdateDamagePhysical(BASE_ATTACK);
                                */
                                me->ApplyStatPctModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, DamageIncrease); // hack
                                ResetThreatList();
                                events.ScheduleEvent(EVENT_FRENZY, 30s, 0, PHASE_TWO);          // Phase 2
                                events.ScheduleEvent(EVENT_FORCEPUNCH, 4s, 0, PHASE_TWO);       // Phase 2
                                events.ScheduleEvent(EVENT_SPELL_CHARGE, 12s, 0, PHASE_TWO);    // Phase 2
                                events.ScheduleEvent(EVENT_ENRAGE, 32s, 0, PHASE_TWO);          // Phase 2
                                events.ScheduleEvent(EVENT_SUMMONTIGERS, 25s, 0, PHASE_TWO);    // Phase 2
                                events.SetPhase(PHASE_TWO);
                            }
                            events.ScheduleEvent(EVENT_RESURRECT_TIMER, 10s, 0, PHASE_ONE);
                            break;
                        case EVENT_CHECK_TIMER:
                            // Check_Timer for the death of LorKhan and Zath.
                            if (!_wasDead)
                            {
                                if (instance->GetBossState(DATA_LORKHAN) == SPECIAL)
                                {
                                    // Resurrect LorKhan
                                    if (Creature* lorKhan = instance->GetCreature(DATA_LORKHAN))
                                    {
                                        lorKhan->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                                        lorKhan->SetFaction(FACTION_MONSTER);
                                        lorKhan->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                        lorKhan->SetFullHealth();
                                        instance->SetData(DATA_LORKHAN, DONE);
                                    }
                                }

                                if (instance->GetBossState(DATA_ZATH) == SPECIAL)
                                {
                                    // Resurrect Zath
                                    if (Creature* zath = instance->GetCreature(DATA_ZATH))
                                    {
                                        zath->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                                        zath->SetFaction(FACTION_MONSTER);
                                        zath->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                        zath->SetFullHealth();
                                        instance->SetBossState(DATA_ZATH, DONE);
                                    }
                                }
                            }
                            events.ScheduleEvent(EVENT_CHECK_TIMER, 5s, 0, PHASE_ONE);
                            break;
                        case EVENT_FRENZY:
                            DoCast(me, SPELL_FRENZY);
                            events.ScheduleEvent(EVENT_FRENZY, 30s, 0, PHASE_TWO);
                            break;
                        case EVENT_FORCEPUNCH:
                            DoCastVictim(SPELL_FORCEPUNCH, true);
                            events.ScheduleEvent(EVENT_FORCEPUNCH, 16s, 21s, 0, PHASE_TWO);
                            break;
                        case EVENT_CHARGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.f, true))
                            {
                                ResetThreatList();
                                AttackStart(target);
                                DoCast(target, SPELL_CHARGE);
                            }
                            events.ScheduleEvent(EVENT_CHARGE, 15s, 22s, 0, PHASE_TWO);
                            break;
                        case EVENT_ENRAGE:
                            if (HealthBelowPct(11) && !_enraged)
                            {
                                DoCast(me, SPELL_ENRAGE);
                                _enraged = true;
                            }
                            events.ScheduleEvent(EVENT_ENRAGE, 30s);
                            break;
                        case EVENT_SUMMONTIGERS:
                            DoCastVictim(SPELL_SUMMONTIGERS, true);
                            events.ScheduleEvent(EVENT_SUMMONTIGERS, 10s, 14s, 0, PHASE_TWO);
                            break;
                        default:
                            break;
                    }

                    if (me->IsFullHealth() && _wasDead)
                        _wasDead = false;

                    if ((events.IsInPhase(PHASE_ONE)) && !_wasDead && !HealthAbovePct(5))
                    {
                        me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                        me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
                        me->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->SetStandState(UNIT_STAND_STATE_SLEEP);
                        me->AttackStop();
                        instance->SetBossState(DATA_THEKAL, SPECIAL);
                        _wasDead = true;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool _enraged;
            bool _wasDead;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<boss_thekalAI>(creature);
        }
};

// Zealot Lor'Khan
class npc_zealot_lorkhan : public CreatureScript
{
    public: npc_zealot_lorkhan() : CreatureScript("npc_zealot_lorkhan") { }

        struct npc_zealot_lorkhanAI : public ScriptedAI
        {
            npc_zealot_lorkhanAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
            {
                Initialize();
            }

            void Initialize()
            {
                _shieldTimer = 1000;
                _bloodLustTimer = 16000;
                _greaterHealTimer = 32000;
                _disarmTimer = 6000;
                _checkTimer = 10000;
                _fakeDeath = false;
            }

            void Reset() override
            {
                Initialize();

                _instance->SetBossState(DATA_LORKHAN, NOT_STARTED);
                me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (_shieldTimer <= diff)
                {
                    DoCast(me, SPELL_SHIELD);
                    _shieldTimer = 61000;
                }
                else
                    _shieldTimer -= diff;

                if (_bloodLustTimer <= diff)
                {
                    DoCast(me, SPELL_BLOODLUST);
                    _bloodLustTimer = 20000 + rand32() % 8000;
                }
                else
                    _bloodLustTimer -= diff;

                // Casting Greaterheal to Thekal or Zath if they are in meele range.
                if (_greaterHealTimer <= diff)
                {
                    Creature* thekal = _instance->GetCreature(DATA_THEKAL);
                    Creature* zath = _instance->GetCreature(DATA_ZATH);
                    if (!thekal && !zath)
                        return;

                    bool roll = roll_chance_i(50);
                    Creature* target = roll ? (thekal ? thekal : zath) : (zath ? zath : thekal);
                    if (!target)
                        return;

                    if (!me->IsWithinMeleeRange(target))
                        target = roll ? zath : thekal;

                    if (me->IsWithinMeleeRange(target))
                        DoCast(target, SPELL_GREATERHEAL);

                    _greaterHealTimer = 15000 + rand32() % 5000;
                }
                else
                    _greaterHealTimer -= diff;

                if (_disarmTimer <= diff)
                {
                    DoCastVictim(SPELL_DISARM);
                    _disarmTimer = 15000 + rand32() % 10000;
                }
                else
                    _disarmTimer -= diff;

                // Check for the death of LorKhan and Zath.
                if (!_fakeDeath && _checkTimer <= diff)
                {
                    if (_instance->GetBossState(DATA_THEKAL) == SPECIAL)
                    {
                        // Resurrect Thekal
                        if (Creature* thekal = _instance->GetCreature(DATA_THEKAL))
                        {
                            thekal->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                            thekal->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            thekal->SetFaction(FACTION_MONSTER);
                            thekal->SetFullHealth();
                        }
                    }

                    if (_instance->GetBossState(DATA_ZATH) == SPECIAL)
                    {
                        // Resurrect Zath
                        if (Creature* zath = _instance->GetCreature(DATA_ZATH))
                        {
                            zath->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                            zath->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            zath->SetFaction(FACTION_MONSTER);
                            zath->SetFullHealth();
                        }
                    }

                    _checkTimer = 5000;
                }
                else
                    _checkTimer -= diff;

                if (!HealthAbovePct(5))
                {
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetStandState(UNIT_STAND_STATE_SLEEP);
                    me->SetFaction(FACTION_FRIENDLY);
                    me->AttackStop();

                    _instance->SetBossState(DATA_LORKHAN, SPECIAL);

                    _fakeDeath = true;
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _shieldTimer;
            uint32 _bloodLustTimer;
            uint32 _greaterHealTimer;
            uint32 _disarmTimer;
            uint32 _checkTimer;
            bool _fakeDeath;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<npc_zealot_lorkhanAI>(creature);
        }
};

// Zealot Zath
class npc_zealot_zath : public CreatureScript
{
    public:
        npc_zealot_zath() : CreatureScript("npc_zealot_zath") { }

        struct npc_zealot_zathAI : public ScriptedAI
        {
            npc_zealot_zathAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
            {
                Initialize();
            }

            void Initialize()
            {
                _sweepingStrikesTimer = 13000;
                _sinisterStrikeTimer = 8000;
                _gougeTimer = 25000;
                _kickTimer = 18000;
                _blindTimer = 5000;
                _checkTimer = 10000;
                _fakeDeath = false;
            }

            void Reset() override
            {
                Initialize();

                _instance->SetBossState(DATA_ZATH, NOT_STARTED);

                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (_sweepingStrikesTimer <= diff)
                {
                    DoCastVictim(SPELL_SWEEPINGSTRIKES);
                    _sweepingStrikesTimer = 22000 + rand32() % 4000;
                }
                else
                    _sweepingStrikesTimer -= diff;

                if (_sinisterStrikeTimer <= diff)
                {
                    DoCastVictim(SPELL_SINISTERSTRIKE);
                    _sinisterStrikeTimer = 8000 + rand32() % 8000;
                }
                else
                    _sinisterStrikeTimer -= diff;

                if (_gougeTimer <= diff)
                {
                    DoCastVictim(SPELL_GOUGE);

                    if (GetThreat(me->GetVictim()))
                        ModifyThreatByPercent(me->GetVictim(), -100);

                    _gougeTimer = 17000 + rand32() % 10000;
                }
                else
                    _gougeTimer -= diff;

                if (_kickTimer <= diff)
                {
                    DoCastVictim(SPELL_KICK);
                    _kickTimer = 15000 + rand32() % 10000;
                }
                else
                    _kickTimer -= diff;

                if (_blindTimer <= diff)
                {
                    DoCastVictim(SPELL_BLIND);
                    _blindTimer = 10000 + rand32() % 10000;
                }
                else
                    _blindTimer -= diff;

                // Check for the death of LorKhan and Thekal.
                if (!_fakeDeath && _checkTimer <= diff)
                {
                    if (_instance->GetBossState(DATA_LORKHAN) == SPECIAL)
                    {
                        // Resurrect LorKhan
                        if (Creature* lorkhan = _instance->GetCreature(DATA_LORKHAN))
                        {
                            lorkhan->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                            lorkhan->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            lorkhan->SetFaction(14);
                            lorkhan->SetFullHealth();
                        }
                    }

                    if (_instance->GetBossState(DATA_THEKAL) == SPECIAL)
                    {
                        // Resurrect Thekal
                        if (Creature* thekal = _instance->GetCreature(DATA_THEKAL))
                        {
                            thekal->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
                            thekal->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            thekal->SetFaction(FACTION_MONSTER);
                            thekal->SetFullHealth();
                        }
                    }

                    _checkTimer = 5000;
                }
                else
                    _checkTimer -= diff;

                if (!HealthAbovePct(5))
                {
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->SetStandState(UNIT_STAND_STATE_SLEEP);
                    me->SetFaction(35);
                    me->AttackStop();

                    _instance->SetBossState(DATA_ZATH, SPECIAL);

                    _fakeDeath = true;
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint32 _sweepingStrikesTimer;
            uint32 _sinisterStrikeTimer;
            uint32 _gougeTimer;
            uint32 _kickTimer;
            uint32 _blindTimer;
            uint32 _checkTimer;
            bool _fakeDeath;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<npc_zealot_zathAI>(creature);
        }
};

void AddSC_boss_thekal()
{
    new boss_thekal();
    new npc_zealot_lorkhan();
    new npc_zealot_zath();
}
