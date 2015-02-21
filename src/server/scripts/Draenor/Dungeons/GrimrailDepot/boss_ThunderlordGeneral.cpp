/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Texts
{
    SAY_AGGRO       		= 0,
    SAY_FREEZING_SNARE  	= 1,
    SAY_DIFFUSED_ENERGY     	= 2,
    SAY_SLAY        		= 3,
    SAY_DEATH       		= 4
};

enum Spells
{
    SPELL_FREEZING_SNARE        = 162066,
    SPELL_SPINNING_SPEAR      	= 162407,
    SPELL_MARK   		= 163447,
    SPELL_DIFFUSED_ENERGY       = 161588,
    SPELL_ENRAGE            	= 176033,
    SPELL_MARK_DEATH        	= 162058,
    SPELL_AURA_DEATH        	= 153616
};

enum Events
{
    EVENT_ENRAGE    		= 1,
    EVENT_SPINNING_SPEAR     	= 2,
    EVENT_MARK     		= 3,
    EVENT_FREEZING_SNARE    	= 4,
    EVENT_DIFFUSED_ENERGY   	= 5
};

class boss_ThunderlordGeneral : public CreatureScript
{
    public:
        boss_ThunderlordGeneral() : CreatureScript("boss_ThunderlordGeneral") { }

        struct boss_ThunderlordGeneralAI : public ScriptedAI
        {
            boss_ThunderlordGeneralAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _inEnrage = false;
            }

            void Reset() override
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_ENRAGE, 0);
                _events.ScheduleEvent(EVENT_SPINNING_SPEAR, urand(5000, 13000));
                _events.ScheduleEvent(EVENT_MARK, urand(10000, 30000));
                _events.ScheduleEvent(EVENT_FREEZING_SNARE, urand(25000, 35000));
                _events.ScheduleEvent(EVENT_DIFFUSED_ENERGY, urand(30000, 45000));
                Initialize();
            }

            void KilledUnit(Unit* victim) override
            {
                victim->CastSpell(victim, SPELL_MARK_DEATH, 0);

                if (urand(0, 4))
                    return;

                Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
            }

            void MoveInLineOfSight(Unit* who) override

            {
                if (who && who->GetTypeId() == TYPEID_PLAYER && me->IsValidAttackTarget(who))
                    if (who->HasAura(SPELL_MARK_DEATH))
                        who->CastSpell(who, SPELL_AURA_DEATH, 1);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ENRAGE:
                            if (!HealthAbovePct(20))
                            {
                                DoCast(me, SPELL_ENRAGE);
                                _events.ScheduleEvent(EVENT_ENRAGE, 6000);
                                _inEnrage = true;
                            }
                            break;
                        case EVENT_DIFFUSED_ENERGY:
                            Talk(SAY_DIFFUSED_ENERGY);
                            DoCastVictim(SPELL_DIFFUSED_ENERGY);
                            _events.ScheduleEvent(EVENT_DIFFUSED_ENERGY, urand(25000, 40000));
                            break;
                        case EVENT_FREEZING_SNARE:
                            if (urand(0, 1))
                                return;

                            Talk(SAY_FREEZING_SNARE);

                            //remove enrage before casting earthquake because enrage + earthquake = 16000dmg over 8sec and all dead
                            if (_inEnrage)
                                me->RemoveAurasDueToSpell(SPELL_ENRAGE);

                            DoCast(me, SPELL_FREEZING_SNARE);
                            _events.ScheduleEvent(EVENT_FREEZING_SNARE, urand(30000, 55000));
                            break;
                        case EVENT_MARK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true))
                                DoCast(target, SPELL_MARK);
                            _events.ScheduleEvent(EVENT_MARK, urand(7000, 27000));
                            break;
                        case EVENT_SPINNING_SPEAR:
                            DoCastVictim(SPELL_SPINNING_SPEAR);
                            _events.ScheduleEvent(EVENT_SPINNING_SPEAR, urand(10000, 25000));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

            private:
                EventMap _events;
                bool _inEnrage;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_ThunderlordGeneralAI(creature);
        }
};

void AddSC_boss_ThunderlordGeneral()
{
    new boss_ThunderlordGeneral();
}
