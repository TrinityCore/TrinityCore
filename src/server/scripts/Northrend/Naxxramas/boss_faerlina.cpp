/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

enum Yells
{
    SAY_GREET       = 0,
    SAY_AGGRO       = 1,
    SAY_SLAY        = 2,
    SAY_DEATH       = 3
};

enum Spells
{
    SPELL_POISON_BOLT_VOLLEY    = 28796,
    SPELL_RAIN_OF_FIRE          = 28794,
    SPELL_FRENZY                = 28798,
    SPELL_WIDOWS_EMBRACE        = 28732
};

#define SPELL_WIDOWS_EMBRACE_HELPER RAID_MODE<uint32>(28732, 54097)

enum Events
{
    EVENT_POISON    = 1,
    EVENT_FIRE      = 2,
    EVENT_FRENZY    = 3
};

enum Misc
{
    DATA_FRENZY_DISPELS         = 1
};

class boss_faerlina : public CreatureScript
{
    public:
        boss_faerlina() : CreatureScript("boss_faerlina") { }

        struct boss_faerlinaAI : public BossAI
        {
            boss_faerlinaAI(Creature* creature) : BossAI(creature, BOSS_FAERLINA),
                _frenzyDispels(0), _introDone(false), _delayFrenzy(false)
            {
            }


            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                events.ScheduleEvent(EVENT_POISON, urand(10000, 15000));
                events.ScheduleEvent(EVENT_FIRE, urand(6000, 18000));
                events.ScheduleEvent(EVENT_FRENZY, urand(60000, 80000));
            }

            void Reset() override
            {
                _Reset();
                _delayFrenzy = false;
                _frenzyDispels = 0;
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (!_introDone && who->GetTypeId() == TYPEID_PLAYER)
                {
                    Talk(SAY_GREET);
                    _introDone = true;
                }

                BossAI::MoveInLineOfSight(who);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                if (!urand(0, 2))
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_WIDOWS_EMBRACE_HELPER)
                {
                    /// @todo Add Text
                    ++_frenzyDispels;
                    _delayFrenzy = true;
                    me->Kill(caster);
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_FRENZY_DISPELS)
                    return _frenzyDispels;

                return 0;
            }

            void UpdateAI(uint32 diff) override
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
                            /// @todo Add Text
                            if (!me->HasAura(SPELL_WIDOWS_EMBRACE_HELPER))
                                DoCast(me, SPELL_FRENZY);
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_faerlinaAI(creature);
        }
};

class npc_faerlina_add : public CreatureScript
{
    public:
        npc_faerlina_add() : CreatureScript("npc_faerlina_add") { }

        struct npc_faerlina_addAI : public ScriptedAI
        {
            npc_faerlina_addAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript())
            {
            }

            void Reset() override
            {
                if (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL) {
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_BIND, true);
                    me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (_instance && GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
                    if (Creature* faerlina = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_FAERLINA)))
                        DoCast(faerlina, SPELL_WIDOWS_EMBRACE);
            }

        private:
            InstanceScript* const _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<npc_faerlina_addAI>(creature);
        }
};

class achievement_momma_said_knock_you_out : public AchievementCriteriaScript
{
    public:
        achievement_momma_said_knock_you_out() : AchievementCriteriaScript("achievement_momma_said_knock_you_out") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            return target && !target->GetAI()->GetData(DATA_FRENZY_DISPELS);
        }
};

void AddSC_boss_faerlina()
{
    new boss_faerlina();
    new npc_faerlina_add();
    new achievement_momma_said_knock_you_out();
}
