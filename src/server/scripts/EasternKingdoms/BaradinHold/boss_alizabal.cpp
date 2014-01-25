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
#include "Player.h"
#include "ObjectAccessor.h"
#include "baradin_hold.h"

enum Texts
{
    SAY_INTRO               = 1,
    SAY_AGGRO               = 2,
    SAY_HATE                = 3,
    SAY_SKEWER              = 4,
    SAY_SKEWER_ANNOUNCE     = 5,
    SAY_BLADE_STORM         = 6,
    SAY_SLAY                = 10,
    SAY_DEATH               = 12
};

enum Spells
{
    SPELL_BLADE_DANCE       = 105784,
    SPELL_BLADE_DANCE_DUMMY = 105828,
    SPELL_SEETHING_HATE     = 105067,
    SPELL_SKEWER            = 104936,
    SPELL_BERSERK           = 47008
};

enum Actions
{
    ACTION_INTRO            = 1
};

    enum Points
{
    POINT_STORM             = 1
};

enum Events
{
    EVENT_RANDOM_CAST       = 1,
    EVENT_STOP_STORM        = 2,
    EVENT_MOVE_STORM        = 3,
    EVENT_CAST_STORM        = 4
};

class at_alizabal_intro : public AreaTriggerScript
{
    public:
        at_alizabal_intro() : AreaTriggerScript("at_alizabal_intro") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (Creature* alizabal = ObjectAccessor::GetCreature(*player, instance->GetData64(DATA_ALIZABAL)))
                    alizabal->AI()->DoAction(ACTION_INTRO);
            return true;
        }
};

class boss_alizabal : public CreatureScript
{
    public:
        boss_alizabal() : CreatureScript("boss_alizabal") { }

        struct boss_alizabalAI : public BossAI
        {
            boss_alizabalAI(Creature* creature) : BossAI(creature, DATA_ALIZABAL)
            {
                _intro = false;
            }

            void Reset() OVERRIDE
            {
                _Reset();
                _hate = false;
                _skewer = false;
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_RANDOM_CAST, 10000);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                _JustDied();
                Talk(SAY_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void KilledUnit(Unit* who) OVERRIDE
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void EnterEvadeMode() OVERRIDE
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->GetMotionMaster()->MoveTargetedHome();
                _DespawnAtEvade();
            }

            void DoAction(int32 action) OVERRIDE
            {
                switch (action)
                {
                    case ACTION_INTRO:
                        if (!_intro)
                        {
                            Talk(SAY_INTRO);
                            _intro = true;
                        }
                        break;
                }
            }

            void MovementInform(uint32 /*type*/, uint32 pointId) OVERRIDE
            {
                switch (pointId)
                {
                    case POINT_STORM:
                        events.ScheduleEvent(EVENT_CAST_STORM, 1);
                        break;
                }
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RANDOM_CAST:
                            switch (urand(0, 1))
                            {
                                case 0:
                                    if (!_skewer)
                                    {
                                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0))
                                        {
                                            DoCast(target, SPELL_SKEWER, true);
                                            Talk(SAY_SKEWER);
                                            Talk(SAY_SKEWER_ANNOUNCE, target);
                                        }
                                        _skewer = true;
                                        events.ScheduleEvent(EVENT_RANDOM_CAST, urand(7000, 10000));
                                    }
                                    else if (!_hate)
                                    {
                                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                        {
                                            DoCast(target, SPELL_SEETHING_HATE, true);
                                            Talk(SAY_HATE);
                                        }
                                        _hate = true;
                                        events.ScheduleEvent(EVENT_RANDOM_CAST, urand(7000, 10000));
                                    }
                                    else if (_hate && _skewer)
                                    {
                                        Talk(SAY_BLADE_STORM);
                                        DoCastAOE(SPELL_BLADE_DANCE_DUMMY);
                                        DoCastAOE(SPELL_BLADE_DANCE);
                                        events.ScheduleEvent(EVENT_RANDOM_CAST, 21000);
                                        events.ScheduleEvent(EVENT_MOVE_STORM, 4050);
                                        events.ScheduleEvent(EVENT_STOP_STORM, 13000);
                                    }
                                    break;
                                case 1:
                                    if (!_hate)
                                    {
                                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                        {
                                            DoCast(target, SPELL_SEETHING_HATE, true);
                                            Talk(SAY_HATE);
                                        }
                                        _hate = true;
                                        events.ScheduleEvent(EVENT_RANDOM_CAST, urand(7000, 10000));
                                    }
                                    else if (!_skewer)
                                    {
                                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0))
                                        {
                                            DoCast(target, SPELL_SKEWER, true);
                                            Talk(SAY_SKEWER);
                                            Talk(SAY_SKEWER_ANNOUNCE, target);
                                        }
                                        _skewer = true;
                                        events.ScheduleEvent(EVENT_RANDOM_CAST, urand(7000, 10000));
                                    }
                                    else if (_hate && _skewer)
                                    {
                                        Talk(SAY_BLADE_STORM);
                                        DoCastAOE(SPELL_BLADE_DANCE_DUMMY);
                                        DoCastAOE(SPELL_BLADE_DANCE);
                                        events.ScheduleEvent(EVENT_RANDOM_CAST, 21000);
                                        events.ScheduleEvent(EVENT_MOVE_STORM, 4050);
                                        events.ScheduleEvent(EVENT_STOP_STORM, 13000);
                                    }
                                    break;
                            }
                            break;
                        case EVENT_MOVE_STORM:
                            me->SetSpeed(MOVE_RUN, 4.0f);
                            me->SetSpeed(MOVE_WALK, 4.0f);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                me->GetMotionMaster()->MovePoint(POINT_STORM, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ());
                            events.ScheduleEvent(EVENT_MOVE_STORM, 4050);
                            break;
                        case EVENT_STOP_STORM:
                            me->RemoveAura(SPELL_BLADE_DANCE);
                            me->RemoveAura(SPELL_BLADE_DANCE_DUMMY);
                            me->SetSpeed(MOVE_WALK, 1.0f);
                            me->SetSpeed(MOVE_RUN, 1.14f);
                            me->GetMotionMaster()->MoveChase(me->GetVictim());
                            _hate = false;
                            _skewer = false;
                            break;
                        case EVENT_CAST_STORM:
                            DoCastAOE(SPELL_BLADE_DANCE);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool _intro;
            bool _hate;
            bool _skewer;

        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetBaradinHoldAI<boss_alizabalAI>(creature);
        }
};

void AddSC_boss_alizabal()
{
    new boss_alizabal();
    new at_alizabal_intro();
}
