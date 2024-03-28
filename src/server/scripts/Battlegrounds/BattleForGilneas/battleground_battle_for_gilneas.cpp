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

#include "BattlegroundScript.h"
#include "ScriptMgr.h"

struct battleground_battle_for_gilneas : BattlegroundScript
{
    enum PvpStats : uint32
    {
        BFG_OBJECTIVE_BASES_ASSAULTED               = 370,
        BFG_OBJECTIVE_BASES_DEFENDED                = 371
    };

    explicit battleground_battle_for_gilneas(BattlegroundMap* map) : BattlegroundScript(map) { }
};

void AddSC_battleground_battle_for_gilneas()
{
    RegisterBattlegroundMapScript(battleground_battle_for_gilneas, 761);
}
