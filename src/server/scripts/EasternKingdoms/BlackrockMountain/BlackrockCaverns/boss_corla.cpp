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
#include "blackrock_caverns.h"

enum Text
{
    YELL_AGGRO                     = 0,
    YELL_KILL                      = 1,
    YELL_EVOLVED_ZEALOT            = 2,
    YELL_DEATH                     = 3,
    EMOTE_EVOLVED_ZEALOT           = 4
};

enum Spells
{
    SPELL_SHADOW_POWER             = 35322,
    H_SPELL_SHADOW_POWER           = 39193
};

enum Events
{

};

class boss_corla : public CreatureScript
{
    public:
        boss_corla(): CreatureScript("boss_corla") {}

        struct boss_corlaAI : public BossAI
        {
            boss_corlaAI(Creature* creature) : BossAI(creature, DATA_CORLA) {}

            void Reset() override
            {

            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(YELL_AGGRO);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(YELL_KILL);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(YELL_DEATH);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_corlaAI(creature);
        }
};

void AddSC_boss_corla()
{
    new boss_corla();
}

