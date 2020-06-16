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

#include "zulgurub.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum Spells
{
    SPELL_AVATAR = 24646, // Enrage Spell
    SPELL_GROUND_TREMOR = 6524
};

enum Events
{
    EVENT_AVATAR = 1,
    EVENT_GROUND_TREMOR = 2
};

class boss_grilek : public CreatureScript // grilek
{
    public:
        boss_grilek() : CreatureScript("boss_grilek") { }

        struct boss_grilekAI : public BossAI
        {
            boss_grilekAI(Creature* creature) : BossAI(creature, DATA_EDGE_OF_MADNESS) { }

            void Reset() override
            {
                _Reset();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                events.ScheduleEvent(EVENT_AVATAR, 15s, 25s);
                events.ScheduleEvent(EVENT_GROUND_TREMOR, 15s, 25s);
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
                        case EVENT_AVATAR:
                            DoCast(me, SPELL_AVATAR);
                            if (Unit* victim = me->GetVictim())
                            {
                                if (GetThreat(victim))
                                    ModifyThreatByPercent(victim, -50);
                            }

                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1))
                                AttackStart(target);
                            events.ScheduleEvent(EVENT_AVATAR, 25s, 35s);
                            break;
                        case EVENT_GROUND_TREMOR:
                            DoCastVictim(SPELL_GROUND_TREMOR, true);
                            events.ScheduleEvent(EVENT_GROUND_TREMOR, 12s, 16s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<boss_grilekAI>(creature);
        }
};

void AddSC_boss_grilek()
{
    new boss_grilek();
}
