/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "culling_of_stratholme.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"

enum Spells
{
    SPELL_CORRUPTING_BLIGHT = 60588,
    SPELL_VOID_STRIKE = 60590,
    SPELL_CORRUPTION_OF_TIME_CHANNEL = 60422,
    SPELL_CORRUPTION_OF_TIME_TARGET = 60451
};

enum Yells
{
    SAY_AGGRO = 0,
    SAY_DEATH = 1,
    SAY_FAIL = 2
};

enum Events
{
    EVENT_CORRUPTING_BLIGHT = 1,
    EVENT_VOID_STRIKE
};

enum Entries
{
    NPC_TIME_RIFT = 28409,
    NPC_GUARDIAN_OF_TIME = 32281
};

enum Misc
{
    MOVEMENT_TIME_RIFT = 1
};

class boss_infinite_corruptor : public CreatureScript
{
    public:
        boss_infinite_corruptor() : CreatureScript("boss_infinite_corruptor") { }

        struct boss_infinite_corruptorAI : public BossAI
        {
            boss_infinite_corruptorAI(Creature* creature) : BossAI(creature, DATA_INFINITE_CORRUPTOR) { }

            void Reset() override
            {
                _Reset();
                DoCastAOE(SPELL_CORRUPTION_OF_TIME_CHANNEL); // implicitly targets the Guardian
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_CORRUPTION_OF_TIME_CHANNEL)
                    target->CastSpell(target, SPELL_CORRUPTION_OF_TIME_TARGET, true);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _JustEngagedWith();
                events.ScheduleEvent(EVENT_CORRUPTING_BLIGHT, 7s);
                events.ScheduleEvent(EVENT_VOID_STRIKE, 5s);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();

                if (Creature* guardian = me->FindNearestCreature(NPC_GUARDIAN_OF_TIME, 100.0f))
                {
                    guardian->RemoveAurasDueToSpell(SPELL_CORRUPTION_OF_TIME_TARGET);
                    guardian->DespawnOrUnsummon(5000);
                }

                if (Creature* rift = me->FindNearestCreature(NPC_TIME_RIFT, 100.0f))
                    rift->DespawnOrUnsummon();
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_CORRUPTING_BLIGHT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                            DoCast(target, SPELL_CORRUPTING_BLIGHT);
                        events.ScheduleEvent(EVENT_CORRUPTING_BLIGHT, 15s);
                        break;
                    case EVENT_VOID_STRIKE:
                        DoCastVictim(SPELL_VOID_STRIKE);
                        events.ScheduleEvent(EVENT_VOID_STRIKE, 5s);
                        break;
                    default:
                        break;
                }
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                if (me->HasReactState(REACT_PASSIVE))
                    return;
                BossAI::EnterEvadeMode(why);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE && id == MOVEMENT_TIME_RIFT)
                {
                    me->DespawnOrUnsummon(Seconds(2));
                    instance->SetBossState(DATA_INFINITE_CORRUPTOR, FAIL);
                }
            }

            void DoAction(int32 action) override
            {
                if (action == -ACTION_CORRUPTOR_LEAVE)
                {
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_FAIL);
                    if (Creature* rift = me->FindNearestCreature(NPC_TIME_RIFT, 300.0f))
                    {
                        if (me->IsWithinDist2d(rift, 5.0f))
                            MovementInform(POINT_MOTION_TYPE, MOVEMENT_TIME_RIFT);
                        else
                            me->GetMotionMaster()->MovePoint(MOVEMENT_TIME_RIFT, rift->GetPosition()); // @todo offset
                    }
                    else
                        MovementInform(POINT_MOTION_TYPE, MOVEMENT_TIME_RIFT);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetCullingOfStratholmeAI<boss_infinite_corruptorAI>(creature);
        }
};

void AddSC_boss_infinite_corruptor()
{
    new boss_infinite_corruptor();
}
