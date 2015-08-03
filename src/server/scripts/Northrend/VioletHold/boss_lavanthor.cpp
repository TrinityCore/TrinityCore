/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include "violet_hold.h"

enum Spells
{
    SPELL_CAUTERIZING_FLAMES                    = 59466, // Only in heroic
    SPELL_FIREBOLT                              = 54235,
    SPELL_FLAME_BREATH                          = 54282,
    SPELL_LAVA_BURN                             = 54249
};

enum LavanthorEvents
{
    EVENT_CAUTERIZING_FLAMES = 1,
    EVENT_FIREBOLT,
    EVENT_FLAME_BREATH,
    EVENT_LAVA_BURN
};

class boss_lavanthor : public CreatureScript
{
public:
    boss_lavanthor() : CreatureScript("boss_lavanthor") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_lavanthorAI>(creature);
    }

    struct boss_lavanthorAI : public ScriptedAI
    {
        boss_lavanthorAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, NOT_STARTED);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetBossState(DATA_2ND_BOSS_EVENT, NOT_STARTED);

            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (GameObject* door = instance->GetGameObject(DATA_LAVANTHOR_CELL))
                if (door->GetGoState() == GO_STATE_READY)
                {
                    EnterEvadeMode();
                    return;
                }
            if (instance->GetData(DATA_WAVE_COUNT) == 6)
                instance->SetBossState(DATA_1ST_BOSS_EVENT, IN_PROGRESS);
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
                instance->SetBossState(DATA_2ND_BOSS_EVENT, IN_PROGRESS);

            events.ScheduleEvent(EVENT_FIREBOLT, 1000);
            events.ScheduleEvent(EVENT_FLAME_BREATH, 5000);
            events.ScheduleEvent(EVENT_LAVA_BURN, 10000);
            if (IsHeroic())
                events.ScheduleEvent(EVENT_CAUTERIZING_FLAMES, 3000);
        }

        void AttackStart(Unit* who) override
        {
            if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC) || me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                return;

            if (me->Attack(who, true))
            {
                me->AddThreat(who, 0.0f);
                me->SetInCombatWith(who);
                who->SetInCombatWith(me);
                DoStartMovement(who);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case EVENT_FIREBOLT:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_FIREBOLT);
                    events.ScheduleEvent(EVENT_FIREBOLT, urand(5000, 13000));
                    break;
                case EVENT_FLAME_BREATH:
                    DoCast(SPELL_FLAME_BREATH);
                    events.ScheduleEvent(EVENT_FLAME_BREATH, urand(10000, 15000));
                    break;
                case EVENT_LAVA_BURN:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_LAVA_BURN);
                    events.ScheduleEvent(EVENT_LAVA_BURN, urand(15000, 23000));
                    break;
                case EVENT_CAUTERIZING_FLAMES:
                    DoCast(SPELL_CAUTERIZING_FLAMES);
                    events.ScheduleEvent(EVENT_CAUTERIZING_FLAMES, urand(10000, 16000));
                    break;
                default:
                    break;
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance->GetData(DATA_WAVE_COUNT) == 6)
            {
                instance->SetBossState(DATA_1ST_BOSS_EVENT, DONE);
                instance->SetData(DATA_WAVE_COUNT, 7);
            }
            else if (instance->GetData(DATA_WAVE_COUNT) == 12)
            {
                instance->SetBossState(DATA_2ND_BOSS_EVENT, DONE);
                instance->SetData(DATA_WAVE_COUNT, 13);
            }
        }

    private:
        EventMap events;
        InstanceScript* instance;
    };
};

void AddSC_boss_lavanthor()
{
    new boss_lavanthor();
}
