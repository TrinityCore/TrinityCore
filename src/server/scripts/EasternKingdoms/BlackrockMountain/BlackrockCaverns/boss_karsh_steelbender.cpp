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
#include "ScriptedCreature.h"
#include "blackrock_caverns.h"

enum Text
{
    YELL_AGGRO                          = 0,
    YELL_KILL                           = 1,
    YELL_QUICKSILVER_ARMOR              = 2,
    YELL_DEATH                          = 3,
    EMOTE_QUICKSILVER_ARMOR             = 4
};

enum Spells
{
    SPELL_CLEAVE                        = 15284,
    SPELL_QUICKSILVER_ARMOR             = 75842,
    SPELL_SUPERHEATED_QUICKSILVER_ARMOR = 75846
};

enum Events
{
    EVENT_CLEAVE                        = 1,
    EVENT_QUICKSILVER_ARMOR             = 2,
    EVENT_SUPERHEATED_QUICKSILVER_ARMOR = 3
};

class boss_karsh_steelbender : public CreatureScript
{
    public:
        boss_karsh_steelbender() : CreatureScript("boss_karsh_steelbender") { }

        struct boss_karsh_steelbenderAI : public BossAI
        {
            boss_karsh_steelbenderAI(Creature* creature) : BossAI(creature, DATA_KARSH_STEELBENDER) { }

            void Reset() override
            {
                _Reset();
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                Talk(YELL_AGGRO);
                events.ScheduleEvent(EVENT_CLEAVE, 10s);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(YELL_KILL);
            }

            void JustDied(Unit* /*victim*/) override
            {
                _JustDied();
                Talk(YELL_DEATH);
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
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, 10s);
                            break;
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockCavernsAI<boss_karsh_steelbenderAI>(creature);
        }
};

void AddSC_boss_karsh_steelbender()
{
    new boss_karsh_steelbender();
}
