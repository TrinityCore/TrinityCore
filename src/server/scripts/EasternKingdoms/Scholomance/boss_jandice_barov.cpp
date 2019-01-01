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

#include "ScriptMgr.h"
#include "scholomance.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_CURSE_OF_BLOOD        = 24673,
    SPELL_ILLUSION              = 17773
};

enum Events
{
    EVENT_CURSE_OF_BLOOD = 1,
    EVENT_ILLUSION,
    EVENT_CLEAVE,
    EVENT_SET_VISIBILITY
};

class boss_jandice_barov : public CreatureScript
{
public:
    boss_jandice_barov() : CreatureScript("boss_jandice_barov") { }

    struct boss_jandicebarovAI : public ScriptedAI
    {
        boss_jandicebarovAI(Creature* creature) : ScriptedAI(creature), Summons(me) { }

        void Reset() override
        {
            events.Reset();
            Summons.DespawnAll();
        }

        void JustSummoned(Creature* summoned) override
        {
            // Illusions should attack a random target.
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                summoned->AI()->AttackStart(target);

            summoned->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_MAGIC, true); // Not sure if this is correct.
            Summons.Summon(summoned);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, 15000);
            events.ScheduleEvent(EVENT_ILLUSION, 30000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Summons.DespawnAll();
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
                    case EVENT_CURSE_OF_BLOOD:
                        DoCastVictim(SPELL_CURSE_OF_BLOOD);
                        events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, 30000);
                        break;
                    case EVENT_ILLUSION:
                        DoCast(SPELL_ILLUSION);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->SetDisplayId(11686);  // Invisible Model
                        DoModifyThreatPercent(me->GetVictim(), -99);
                        events.ScheduleEvent(EVENT_SET_VISIBILITY, 3000);
                        events.ScheduleEvent(EVENT_ILLUSION, 25000);
                        break;
                    case EVENT_SET_VISIBILITY:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->SetDisplayId(11073);     //Jandice Model
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
        SummonList Summons;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetScholomanceAI<boss_jandicebarovAI>(creature);
    }
};

void AddSC_boss_jandicebarov()
{
    new boss_jandice_barov();
}
