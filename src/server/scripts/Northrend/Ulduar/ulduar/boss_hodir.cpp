/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
    SAY_AGGRO                                   = -1603210,
    SAY_SLAY_1                                  = -1603211,
    SAY_SLAY_2                                  = -1603212,
    SAY_FLASH_FREEZE                            = -1603213,
    SAY_STALACTITE                              = -1603214,
    SAY_DEATH                                   = -1603215,
    SAY_BERSERK                                 = -1603216,
    SAY_YS_HELP                                 = -1603217,
    SAY_HARD_MODE_MISSED                        = -1603218,
};

class boss_hodir : public CreatureScript
{
public:
    boss_hodir() : CreatureScript("boss_hodir") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_hodirAI(pCreature);
    }

    struct boss_hodirAI : public BossAI
    {
        boss_hodirAI(Creature *pCreature) : BossAI(pCreature, TYPE_HODIR)
        {
        }

        void Reset()
        {
            _Reset();
        }

        void KilledUnit(Unit * /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
        }

        void JustDied(Unit * /*victim*/)
        {
            DoScriptText(SAY_DEATH, me);
            _JustDied();
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoScriptText(SAY_AGGRO, me);
            _EnterCombat();
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;
    //SPELLS TODO:

    //
            DoMeleeAttackIfReady();

            EnterEvadeIfOutOfCombatArea(diff);
        }
    };

};

void AddSC_boss_hodir()
{
    new boss_hodir();
}
