/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ulduar.h"

enum Yells
{
    SAY_AGGRO_1                                 = -1603270,
    SAY_AGGRO_2                                 = -1603271,
    SAY_SPECIAL_1                               = -1603272,
    SAY_SPECIAL_2                               = -1603273,
    SAY_SPECIAL_3                               = -1603274,
    SAY_JUMPDOWN                                = -1603275,
    SAY_SLAY_1                                  = -1603276,
    SAY_SLAY_2                                  = -1603277,
    SAY_BERSERK                                 = -1603278,
    SAY_WIPE                                    = -1603279,
    SAY_DEATH                                   = -1603280,
    SAY_END_NORMAL_1                            = -1603281,
    SAY_END_NORMAL_2                            = -1603282,
    SAY_END_NORMAL_3                            = -1603283,
    SAY_END_HARD_1                              = -1603284,
    SAY_END_HARD_2                              = -1603285,
    SAY_END_HARD_3                              = -1603286,
    SAY_YS_HELP                                 = -1603287,
};
class boss_thorim : public CreatureScript
{
public:
    boss_thorim() : CreatureScript("boss_thorim") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_thorimAI(pCreature);
    }

    struct boss_thorimAI : public BossAI
    {
        boss_thorimAI(Creature* pCreature) : BossAI(pCreature, TYPE_THORIM)
        {
        }

        void Reset()
        {
            _Reset();
        }

        void EnterEvadeMode()
        {
            DoScriptText(SAY_WIPE, me);
            _EnterEvadeMode();
        }

        void KilledUnit(Unit * /*victim*/)
        {
            DoScriptText(RAND(SAY_SLAY_1,SAY_SLAY_2), me);
        }

        void JustDied(Unit * /*victim*/)
        {
            DoScriptText(SAY_DEATH, me);
            _JustDied();
        }

        void EnterCombat(Unit* /*pWho*/)
        {
            DoScriptText(RAND(SAY_AGGRO_1,SAY_AGGRO_2), me);
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


void AddSC_boss_thorim()
{
    new boss_thorim();
}
