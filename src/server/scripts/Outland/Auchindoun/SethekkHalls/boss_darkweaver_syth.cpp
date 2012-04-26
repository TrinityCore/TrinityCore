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

#include "ScriptPCH.h"
#include "sethekk_halls.h"

enum Texts
{
    SAY_SUMMON  = 0,
    SAY_AGGRO   = 1,
    SAY_SLAY    = 2,
    SAY_DEATH   = 3
};

enum Spells
{
    SPELL_FROST_SHOCK       = 12548,
    SPELL_FLAME_SHOCK       = 15039,
    SPELL_SHADOW_SHOCK      = 33620,
    SPELL_ARCANE_SHOCK      = 33534,
    
    SPELL_CHAIN_LIGHTNING   = 15305,
    
    SPELL_SUMMON            = 33537     // Fire - 33537, Arcane - 33538, Frost - 33539, Shadow - 33540
};

enum Events
{
    EVENT_FLAME_SHOCK       = 1,
    EVENT_ARCANE_SHOCK      = 2,
    EVENT_FROST_SHOCK       = 3,
    EVENT_SHADOW_SHOCK      = 4,
    EVENT_CHAIN_LIGHTNING   = 5
};

class boss_darkweaver_syth : public CreatureScript
{
    public:
        boss_darkweaver_syth() : CreatureScript("boss_darkweaver_syth") { }

        struct boss_darkweaver_sythAI : public BossAI
        {
            boss_darkweaver_sythAI(Creature* creature) : BossAI(creature, BOSS_DARKWEAVER_SYTH), _summons(me)
            {
            }

            void Reset()
            {
                _Reset();
                _summons.DespawnAll();
                _events.Reset();
                _events.ScheduleEvent(EVENT_FLAME_SHOCK, 2000);
                _events.ScheduleEvent(EVENT_ARCANE_SHOCK, 4000);
                _events.ScheduleEvent(EVENT_FROST_SHOCK, 6000);
                _events.ScheduleEvent(EVENT_SHADOW_SHOCK, 8000);
                _events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 15000);

                _healthCheck = 90.0f;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
            }

            void JustDied(Unit* /*killer*/)
            {
                _summons.DespawnAll();
                Talk(SAY_DEATH);

                _JustDied();
            }

            void KilledUnit(Unit* /*victim*/)
            {
                if (urand(0, 1))
                    return;

                Talk(SAY_SLAY);
            }

            void JustSummoned(Creature* summon)
            {
                _summons.Summon(summon);
                switch (summon->GetEntry())
                {
                    case NPC_FIRE_ELEMENTAL:
                        summon->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FIRE, true);
                        break;
                    case NPC_FROST_ELEMENTAL:
                        summon->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_FROST, true);
                        break;
                    case NPC_ARCANE_ELEMENTAL:
                        summon->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_ARCANE, true);
                        break;
                    case NPC_SHADOW_ELEMENTAL:
                        summon->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_SHADOW, true);
                        break;
                }
                
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    summon->AI()->AttackStart(target);
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                _summons.Despawn(summon);
            }

            void SythSummoning()
            {
                Talk(SAY_SUMMON);

                if (me->IsNonMeleeSpellCasted(false))
                    me->InterruptNonMeleeSpells(false);

                for (uint8 itr = 0; itr < 4; itr++)
                    DoCast(me, SPELL_SUMMON + itr, true);
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (_healthCheck > 0.0f && HealthBelowPct(_healthCheck))
                {
                    SythSummoning();
                    _healthCheck -= 40.0f;
                }
                
                _events.Update(diff);
                
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FLAME_SHOCK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_FLAME_SHOCK);
                            _events.ScheduleEvent(EVENT_FLAME_SHOCK, urand(10000, 15000));
                            break;
                        case EVENT_ARCANE_SHOCK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_ARCANE_SHOCK);
                            _events.ScheduleEvent(EVENT_ARCANE_SHOCK, urand(10000, 15000));
                            break;
                        case EVENT_FROST_SHOCK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_FROST_SHOCK);
                            _events.ScheduleEvent(EVENT_FROST_SHOCK, urand(10000, 15000));
                            break;
                        case EVENT_SHADOW_SHOCK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_SHADOW_SHOCK);
                            _events.ScheduleEvent(EVENT_SHADOW_SHOCK, urand(10000, 15000));
                            break;
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_CHAIN_LIGHTNING);
                            _events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 25000);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
            
            private:
                EventMap _events;
                SummonList _summons;
                float _healthCheck;
        };
        
        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_darkweaver_sythAI (creature);
        }
};

void AddSC_boss_darkweaver_syth()
{
    new boss_darkweaver_syth();
}
