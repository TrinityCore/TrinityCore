/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "ScriptedCreature.h"
#include "mogu_shan_palace.h"

class boss_xin_the_weaponmaster : public CreatureScript
{
    public:
        boss_xin_the_weaponmaster() : CreatureScript("boss_xin_the_weaponmaster") {}

        enum eEvents
        {
            EVENT_RING_OF_FIRE          = 1,
            EVENT_HEURT                 = 2,
            EVENT_INCITING_ROAR         = 3,
            EVENT_SWORD_THROWER         = 4,
            EVENT_SWORD_THROWER_STOP    = 5,
            EVENT_AXES_ACTIVATE         = 6,
            EVENT_AXES_DESACTIVATE      = 7
        };

        enum eSpells
        {
            SPELL_HEURT         = 119684,
            SPELL_INCITING_ROAR = 122959,
        };

        struct boss_xin_the_weaponmaster_AI : public BossAI
        {
            boss_xin_the_weaponmaster_AI(Creature* creature) : BossAI(creature, DATA_XIN_THE_WEAPONMASTER)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;

            void Reset() override
            {
                if (pInstance)
                    pInstance->SetData(TYPE_ACTIVATE_SWORD, 0);

                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_RING_OF_FIRE, 3000);
                events.ScheduleEvent(EVENT_HEURT, urand(10000, 15000));
                events.ScheduleEvent(EVENT_INCITING_ROAR, urand(15000, 25000));
                events.ScheduleEvent(EVENT_SWORD_THROWER, 30000);
                events.ScheduleEvent(EVENT_AXES_ACTIVATE, 15000);
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
                        case EVENT_RING_OF_FIRE:
                            if (pInstance)
                                pInstance->SetData(TYPE_ACTIVATE_ANIMATED_STAFF, 0);
                            events.ScheduleEvent(EVENT_RING_OF_FIRE, 20000);
                            break;
                        case EVENT_HEURT:
                            me->CastSpell(me, SPELL_HEURT, false);
                            events.ScheduleEvent(EVENT_HEURT, urand(10000, 15000));
                            break;
                        case EVENT_INCITING_ROAR:
                            me->CastSpell(me, SPELL_INCITING_ROAR, false);
                            events.ScheduleEvent(EVENT_INCITING_ROAR, 30000);
                            break;
                        case EVENT_SWORD_THROWER:
                            if (pInstance)
                                pInstance->SetData(TYPE_ACTIVATE_SWORD, 1);
                            events.ScheduleEvent(EVENT_SWORD_THROWER_STOP, 10000);
                            break;
                        case EVENT_SWORD_THROWER_STOP:
                            if (pInstance)
                                pInstance->SetData(TYPE_ACTIVATE_SWORD, 0);
                            events.ScheduleEvent(EVENT_SWORD_THROWER, 20000);
                            break;
                        case EVENT_AXES_ACTIVATE:
                            if (pInstance)
                                pInstance->SetData(TYPE_ACTIVATE_ANIMATED_AXE, 1);

                            events.ScheduleEvent(EVENT_AXES_DESACTIVATE, 10000);
                            break;
                        case EVENT_AXES_DESACTIVATE:
                            if (pInstance)
                                pInstance->SetData(TYPE_ACTIVATE_ANIMATED_AXE, 0);

                            events.ScheduleEvent(EVENT_AXES_ACTIVATE, 15000);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_xin_the_weaponmaster_AI(creature);
        }
};

class mob_animated_staff : public CreatureScript
{
    public:
        mob_animated_staff() : CreatureScript("mob_animated_staff") {}

        enum eSpells
        {
            SPELL_RING_OF_FIRE_0 = 119544,
            SPELL_RING_OF_FIRE_1 = 119590,
        };

        enum eActions
        {
            ACTION_ACTIVATE,
        };

        enum eEvents
        {
            EVENT_SUMMON_RING_OF_FIRE = 1,
            EVENT_UNSUMMON = 2,
            EVENT_SUMMON_RING_TRIGGER = 3,
        };

        enum eCreatures
        {
            CREATURE_RING_OF_FIRE = 61499,
        };

        struct mob_animated_staff_AI : public ScriptedAI
        {
            mob_animated_staff_AI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetDisplayId(42195);
                me->SetVirtualItem(0, 76364);
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
            }

            EventMap events;
            float _x;
            float _y;
            float point;

            void Reset() override
            {
                _x = 0.0f;
                _y = 0.0f;
                point = 0.0f;

                me->AddAura(SPELL_PERMANENT_FEIGN_DEATH, me);

                Position home = me->GetHomePosition();
                me->GetMotionMaster()->MovePoint(0, home);
            }

            void EnterCombat(Unit* /*who*/) override {}

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_ACTIVATE:
                        me->RemoveAura(SPELL_PERMANENT_FEIGN_DEATH);
                        events.ScheduleEvent(EVENT_SUMMON_RING_OF_FIRE, 500);
                        break;
                }
            }

            void JustSummoned(Creature* summoned) override
            {
                if (summoned->GetEntry() == CREATURE_RING_OF_FIRE)
                {
                    summoned->SetFaction(14);
                    summoned->SetReactState(REACT_PASSIVE);
                    summoned->AddAura(SPELL_RING_OF_FIRE_0, summoned);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_RING_OF_FIRE:
                        {
                            events.ScheduleEvent(EVENT_UNSUMMON, 9000);
                            Unit* target = nullptr;
                            std::list<Unit*> units;

                            Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();
                            if (!PlayerList.isEmpty())
                                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                    if (Player* plr = i->GetSource())
                                        if (plr->IsAlive() && !plr->IsGameMaster())
                                            units.push_back(plr);

                            if (units.empty())
                                return;

                            target = Trinity::Containers::SelectRandomContainerElement(units);
                            if (!target)
                                return;

                            me->GetMotionMaster()->MovePoint(0, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
                            point = 0.0f;
                            _x = target->GetPositionX();
                            _y = target->GetPositionY();
                            events.ScheduleEvent(EVENT_SUMMON_RING_TRIGGER, 100);
                            break;
                        }
                        case EVENT_UNSUMMON:
                            Reset();
                            break;
                        case EVENT_SUMMON_RING_TRIGGER:
                        {
                            if (point >= 11)
                            {
                                if (TempSummon* tmp = me->SummonCreature(CREATURE_RING_OF_FIRE, _x, _y, me->GetMap()->GetHeight(me->GetPhaseShift(), _x, _y, me->GetPositionZ()), 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10000))
                                {
                                    tmp->RemoveAura(SPELL_RING_OF_FIRE_0);
                                    tmp->CastSpell(tmp, SPELL_RING_OF_FIRE_1, false);
                                }
                                return;
                            }

                            float x = _x + 5.0f * cos(point * M_PI / 5);
                            float y = _y + 5.0f * sin(point * M_PI / 5);
                            me->SummonCreature(CREATURE_RING_OF_FIRE, x, y, me->GetMap()->GetHeight(me->GetPhaseShift(), x, y, me->GetPositionZ()), 0.0f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 10000);
                            ++point;
                            events.ScheduleEvent(EVENT_SUMMON_RING_TRIGGER, 400);
                            break;
                        }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new mob_animated_staff_AI(creature);
        }
};

class OnlyTriggerInFrontPredicate
{
    public:
        OnlyTriggerInFrontPredicate(Unit* caster) : _caster(caster) {}

        bool operator()(WorldObject* target)
        {
            return target->GetEntry() != 59481 || !_caster->isInFront(target, (float)M_PI / 5) || target->GetGUID() == _caster->GetGUID();
        }

    private:
        Unit* _caster;
};

void AddSC_boss_xin_the_weaponmaster()
{
    new boss_xin_the_weaponmaster();
    new mob_animated_staff();
}
