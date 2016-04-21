/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

enum Spells
{
    SPELL_MAGMAERUPTION = 150776,
    SPELL_MOLTENBLAST = 150677,
    SPELL_MOLTENCORE = 150678,
    SPELL_SUMMON_UNSTABLE_SLAG = 150755,
};

enum Events
{
    EVENT_MAGMAERUPTION = 1,
    EVENT_MOLTENBLAST,
    EVENT_MOLTENCORE,
    EVENT_SUMMON_UNSTABLE_SLAG,
};

enum Slag
{
    UNSTABLE_SLAG = 74927,
};

enum Slag_Spells
{
    SPELL_EMPOWERED_FLAMES = 152091,
};

class Boss_Gugrokk : public CreatureScript
{
public:
    Boss_Gugrokk() : CreatureScript("boss_gugrokk") { }

    struct Boss_GugrokkAI : public BossAI
    {
        Boss_GugrokkAI(Creature* creature) : BossAI(creature, 74790)
        {
        }

        void Reset() override
        {
            BossAI::Reset();
        }

        void EnterCombat(Unit* victim) override
        {
            BossAI::EnterCombat(victim);
            events.ScheduleEvent(EVENT_MAGMAERUPTION, 4000);
            events.ScheduleEvent(EVENT_MOLTENBLAST, 8000);
            events.ScheduleEvent(EVENT_MOLTENCORE, 12000);
            events.ScheduleEvent(EVENT_SUMMON_UNSTABLE_SLAG, 16000);
        }

        void KilledUnit(Unit * /*victim*/) override
        {
        }

        void JustDied(Unit * /*victim*/) override
        {
            _JustDied();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            Position pos = me->GetPosition();

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_MAGMAERUPTION:
                    DoCastAOE(SPELL_MAGMAERUPTION);
                    events.ScheduleEvent(EVENT_MAGMAERUPTION, 4000);
                    break;
                case EVENT_MOLTENBLAST:
                    DoCastVictim(SPELL_MOLTENBLAST);
                    events.ScheduleEvent(EVENT_MOLTENBLAST, 8000);
                    break;
                case EVENT_MOLTENCORE:
                    DoCast(me,SPELL_MOLTENCORE);
                    events.ScheduleEvent(EVENT_MOLTENCORE, 12000);
                    break;
                case EVENT_SUMMON_UNSTABLE_SLAG:
                    DoCast(SPELL_SUMMON_UNSTABLE_SLAG);
                    me->SummonCreature(UNSTABLE_SLAG, pos.GetPositionX(), pos.GetPositionY(),pos.GetPositionZ(), 2.1f, TEMPSUMMON_DEAD_DESPAWN, 5000);
                    events.ScheduleEvent(EVENT_SUMMON_UNSTABLE_SLAG, 30000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new Boss_GugrokkAI(creature);
    }
};

class NPC_Unstable_Slag : public CreatureScript
{
public:
    NPC_Unstable_Slag() : CreatureScript("NPC_Unstable_Slag"){ }

    struct NPC_Unstable_SlagAI : public ScriptedAI{
        NPC_Unstable_SlagAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(true);
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!UpdateVictim())
                return;

            if(!isFlaming){
                DoCastAOE(SPELL_EMPOWERED_FLAMES);
                isFlaming = true;
            }else{
                DoMeleeAttackIfReady();
                isFlaming = false;
            }
        }

    private:
        bool isFlaming = false;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new NPC_Unstable_SlagAI(creature);
    }
};

void AddSC_Boss_Gugrokk()
{
    new Boss_Gugrokk();
    new NPC_Unstable_Slag();
}
