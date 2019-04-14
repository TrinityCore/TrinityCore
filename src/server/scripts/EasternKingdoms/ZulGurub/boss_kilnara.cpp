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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "zulgurub.h"

enum Yells
{
    SAY_AGGRO           = 0,
    SAY_WAVE_OF_AGONY   = 1, // ID - 96457 Wave of Agony
    SAY_TRANSFROM_1     = 2,
    SAY_TRANSFROM_2     = 3,
    SAY_PLAYER_KILL     = 4,
    SAY_DEATH           = 5
};

enum Spells
{
};

enum Events
{
};

class boss_kilnara : public CreatureScript
{
    public:
        boss_kilnara() : CreatureScript("boss_kilnara") { }

        struct boss_kilnaraAI : public BossAI
        {
            boss_kilnaraAI(Creature* creature) : BossAI(creature, DATA_KILNARA) { }

            void Reset() override
            {
                _Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_PLAYER_KILL);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            /*
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        default:
                            break;
                    }
                }
            */

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulGurubAI<boss_kilnaraAI>(creature);
        }
};

void AddSC_boss_kilnara()
{
    new boss_kilnara();
}
