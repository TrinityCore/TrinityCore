/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "scholomance.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Emotes
{
    EMOTE_FRENZY                 = 0
};

enum Spells
{
    SPELL_FLAMESTRIKE            = 18399,
    SPELL_BLAST_WAVE             = 16046,
    SPELL_FIRE_SHIELD            = 19626,
    SPELL_FRENZY                 = 8269  // 28371
};

enum Events
{
    EVENT_FIRE_SHIELD = 1,
    EVENT_BLAST_WAVE,
    EVENT_FRENZY
};

class boss_vectus : public CreatureScript
{
public:
    boss_vectus() : CreatureScript("boss_vectus") { }

    struct boss_vectusAI : public ScriptedAI
    {
        boss_vectusAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_FIRE_SHIELD, 2000);
            events.ScheduleEvent(EVENT_BLAST_WAVE, 14000);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (me->HealthBelowPctDamaged(25, damage))
            {
                DoCast(me, SPELL_FRENZY);
                Talk(EMOTE_FRENZY);
                events.ScheduleEvent(EVENT_FRENZY, 24000);
            }
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
                    case EVENT_FIRE_SHIELD:
                        DoCast(me, SPELL_FIRE_SHIELD);
                        events.ScheduleEvent(EVENT_FIRE_SHIELD, 90000);
                        break;
                    case EVENT_BLAST_WAVE:
                        DoCast(me, SPELL_BLAST_WAVE);
                        events.ScheduleEvent(EVENT_BLAST_WAVE, 12000);
                        break;
                    case EVENT_FRENZY:
                        DoCast(me, SPELL_FRENZY);
                        Talk(EMOTE_FRENZY);
                        events.ScheduleEvent(EVENT_FRENZY, 24000);
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
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetScholomanceAI<boss_vectusAI>(creature);
    }
};

void AddSC_boss_vectus()
{
    new boss_vectus();
}
