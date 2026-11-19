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

#include "ScriptMgr.h"
#include "blackrock_depths.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_FIREBLAST                                        = 15573
};

enum Events
{
    EVENT_FIREBLAST                                        = 1,
    EVENT_SUMMON_SPIRITS                                   = 2
};

class boss_ambassador_flamelash : public CreatureScript
{
    public:
        boss_ambassador_flamelash() : CreatureScript("boss_ambassador_flamelash") { }

        struct boss_ambassador_flamelashAI : public BossAI
        {
            boss_ambassador_flamelashAI(Creature* creature) : BossAI(creature, BOSS_AMBASSADOR_FLAMELASH) { }

            void JustEngagedWith(Unit* who) override
            {
                _JustEngagedWith(who);
                events.ScheduleEvent(EVENT_FIREBLAST, 2s);
                events.ScheduleEvent(EVENT_SUMMON_SPIRITS, 24s);
            }

            void SummonSpirit(Unit* victim)
            {
                if (Creature* spirit = DoSpawnCreature(9178, frand(-9, 9), frand(-9, 9), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60s))
                    spirit->AI()->AttackStart(victim);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIREBLAST:
                            DoCastVictim(SPELL_FIREBLAST);
                            events.ScheduleEvent(EVENT_FIREBLAST, 7s);
                            break;
                        case EVENT_SUMMON_SPIRITS:
                            for (uint32 i = 0; i < 4; ++i)
                                SummonSpirit(me->GetVictim());
                            events.ScheduleEvent(EVENT_SUMMON_SPIRITS, 30s);
                            break;
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockDepthsAI<boss_ambassador_flamelashAI>(creature);
        }
};

void AddSC_boss_ambassador_flamelash()
{
    new boss_ambassador_flamelash();
}
