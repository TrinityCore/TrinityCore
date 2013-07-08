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
#include "blackfathom_deeps.h"

enum Spells
{
    SPELL_POISON_CLOUD     = 3815,
    SPELL_FRENZIED_RAGE    = 3490
};

enum Events
{
    EVENT_POISON_CLOUD     = 1,
    EVENT_FRENZIED_RAGE    = 2
};

class boss_aku_mai : public CreatureScript
{
public:
    boss_aku_mai() : CreatureScript("boss_aku_mai") { }

    struct boss_aku_maiAI : public BossAI
    {
        boss_aku_maiAI(Creature* creature) : BossAI(creature, TYPE_AKU_MAI) { }

        void Reset() OVERRIDE
        {
            IsEnraged = false;
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            events.ScheduleEvent(EVENT_POISON_CLOUD, urand(5000, 9000));
            _EnterCombat();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            _JustDied();
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (!IsEnraged && HealthBelowPct(30))
                events.ScheduleEvent(EVENT_FRENZIED_RAGE, 100);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_POISON_CLOUD:
                        DoCastVictim(SPELL_POISON_CLOUD);
                        events.ScheduleEvent(EVENT_POISON_CLOUD, urand(25000, 50000));
                        break;
                    case EVENT_FRENZIED_RAGE:
                        DoCast(me, SPELL_FRENZIED_RAGE);
                        IsEnraged = true;
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

        private:
            bool IsEnraged;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_aku_maiAI(creature);
    }
};

void AddSC_boss_aku_mai()
{
    new boss_aku_mai();
}
