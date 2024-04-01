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

struct battleground_twin_peaks : BattlegroundScript
{
    enum PvpStats : uint32
    {
        BG_TP_FLAG_CAPTURES     = 290,
        BG_TP_FLAG_RETURNS      = 291
    };

    explicit battleground_twin_peaks(BattlegroundMap* map) : BattlegroundScript(map) { }
};

void AddSC_battleground_twin_peaks()
{
    RegisterBattlegroundMapScript(battleground_twin_peaks, 726);
}
