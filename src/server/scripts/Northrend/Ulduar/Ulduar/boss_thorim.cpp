/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ulduar.h"

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SPECIAL_1                               = 1,
    SAY_SPECIAL_2                               = 2,
    SAY_SPECIAL_3                               = 3,
    SAY_JUMPDOWN                                = 4,
    SAY_SLAY                                    = 5,
    SAY_BERSERK                                 = 6,
    SAY_WIPE                                    = 7,
    SAY_DEATH                                   = 8,
    SAY_END_NORMAL_1                            = 9,
    SAY_END_NORMAL_2                            = 10,
    SAY_END_NORMAL_3                            = 11,
    SAY_END_HARD_1                              = 12,
    SAY_END_HARD_2                              = 13,
    SAY_END_HARD_3                              = 14
};

class boss_thorim : public CreatureScript
{
    public:
        boss_thorim() : CreatureScript("boss_thorim") { }

        struct boss_thorimAI : public BossAI
        {
            boss_thorimAI(Creature* creature) : BossAI(creature, BOSS_THORIM)
            {
            }

            void Reset() override
            {
                _Reset();
            }

            void EnterEvadeMode() override
            {
                Talk(SAY_WIPE);
                _EnterEvadeMode();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;
                //SPELLS @todo

                //
                DoMeleeAttackIfReady();

                EnterEvadeIfOutOfCombatArea(diff);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUlduarAI<boss_thorimAI>(creature);
        }
};

void AddSC_boss_thorim()
{
    new boss_thorim();
}
