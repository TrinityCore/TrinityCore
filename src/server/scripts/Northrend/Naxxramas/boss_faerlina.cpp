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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "naxxramas.h"
#include "SpellInfo.h"

#define DATA_FRENZY_DISPELS 1
#define SPELL_WIDOWS_EMBRACE_HELPER SPELL_WIDOWS_EMBRACE

enum Texts
{
    SAY_GREET       = 0,
    SAY_AGGRO       = 1,
    SAY_SLAY        = 2,
    SAY_DEATH       = 3,
    SAY_ENRAGE      = 4,
};

enum Spells
{
    SPELL_POISON_BOLT_VOLLEY    = 28796,
    SPELL_RAIN_OF_FIRE          = 28794,
    SPELL_FRENZY                = 28798,
    SPELL_WIDOWS_EMBRACE        = 28732,
};

enum Events
{
    EVENT_POISON    = 1,
    EVENT_FIRE      = 2,
    EVENT_FRENZY    = 3,
};

enum Actions
{
    ACTION_INTRO    = 1,
};

class boss_faerlina : public CreatureScript
{
    public:
        boss_faerlina() : CreatureScript("boss_faerlina") { }

        struct boss_faerlinaAI : public BossAI
        {
            boss_faerlinaAI(Creature* creature) : BossAI(creature, DATA_FAERLINA)
            {
                _frenzyDispels=0;
                _introDone=false;
                _delayFrenzy=false;
            }

            void Reset()
            {
                _Reset();
                _delayFrenzy = false;
                _frenzyDispels = 0;
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_INTRO:
                       if (!_introDone)
                       {
                           TalkToMap(SAY_GREET);
                           _introDone = true;
                       }
                    break;
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                TalkToMap(SAY_AGGRO);
                events.ScheduleEvent(EVENT_POISON, urand(10000, 15000));
                events.ScheduleEvent(EVENT_FIRE, urand(6000, 18000));
                events.ScheduleEvent(EVENT_FRENZY, urand(60000, 80000));
            }

            void KilledUnit(Unit* /*victim*/)
            {
                TalkToMap(SAY_SLAY);
            }

            void SpellHit(Unit* caster, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_WIDOWS_EMBRACE)
                {
                    ++_frenzyDispels;
                    _delayFrenzy = true;
                    me->Kill(caster);
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                TalkToMap(SAY_DEATH);
            }

            uint32 GetData(uint32 type) const
            {
                if (type == DATA_FRENZY_DISPELS)
                    return _frenzyDispels;

                return 0;
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (_delayFrenzy && !me->HasAura(SPELL_WIDOWS_EMBRACE_HELPER))
                {
                    _delayFrenzy = false;
                    DoCast(me, SPELL_FRENZY, true);
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_POISON:
                            if (!me->HasAura(SPELL_WIDOWS_EMBRACE_HELPER))
                                DoCastAOE(SPELL_POISON_BOLT_VOLLEY);
                            events.ScheduleEvent(EVENT_POISON, urand(8000, 15000));
                            break;
                        case EVENT_FIRE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_RAIN_OF_FIRE);
                            events.ScheduleEvent(EVENT_FIRE, urand(6000, 18000));
                            break;
                        case EVENT_FRENZY:
                            if (!me->HasAura(SPELL_WIDOWS_EMBRACE_HELPER))
                            {
                                TalkToMap(SAY_ENRAGE);
                                DoCast(me, SPELL_FRENZY);
                            }
                            else
                                _delayFrenzy = true;

                            events.ScheduleEvent(EVENT_FRENZY, urand(60000, 80000));
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            uint32 _frenzyDispels;
            bool _introDone;
            bool _delayFrenzy;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetNaxxramasAI<boss_faerlinaAI>(creature);
        }
};

class mob_faerlina_add : public CreatureScript
{
    public:
        mob_faerlina_add() : CreatureScript("mob_faerlina_add") { }

        struct mob_faerlina_addAI : public ScriptedAI
        {
            mob_faerlina_addAI(Creature* creature) : ScriptedAI(creature),
                instance(creature->GetInstanceScript())
            {
            }

            void Reset()
            {
                if (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
                {
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_BIND, true);
                    me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                if (instance && GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
                    if (Creature* faerlina = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_FAERLINA)))
                        DoCast(faerlina, SPELL_WIDOWS_EMBRACE);
            }

        private:
            InstanceScript* const instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetNaxxramasAI<mob_faerlina_addAI>(creature);
        }
};

class achievement_momma_said_knock_you_out : public AchievementCriteriaScript
{
    public:
        achievement_momma_said_knock_you_out() : AchievementCriteriaScript("achievement_momma_said_knock_you_out") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            return target && !target->GetAI()->GetData(DATA_FRENZY_DISPELS);
        }
};

class at_faerlina_intro : public AreaTriggerScript
{
    public:
        at_faerlina_intro() : AreaTriggerScript("at_faerlina_intro") { }

        bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetBossState(DATA_FAERLINA) != DONE)
                    if (Creature* Faerlina = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_FAERLINA)))
                        Faerlina->AI()->DoAction(ACTION_INTRO);
            return true;
        }
};

void AddSC_boss_faerlina()
{
    new boss_faerlina();
    new mob_faerlina_add();
    new achievement_momma_said_knock_you_out();
    new at_faerlina_intro();
}
