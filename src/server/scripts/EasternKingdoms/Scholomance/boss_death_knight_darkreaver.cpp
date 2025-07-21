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
#include "scholomance.h"
#include "ScriptedCreature.h"

enum DarkreaverSpells
{
    SUMMON_FALLEN_CHARGER       = 23261
};

// 14516 - Death Knight Darkreaver
struct boss_death_knight_darkreaver : public ScriptedAI
{
    boss_death_knight_darkreaver(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SUMMON_FALLEN_CHARGER, true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
    }
};

void AddSC_boss_death_knight_darkreaver()
{
    RegisterScholomanceCreatureAI(boss_death_knight_darkreaver);
}
