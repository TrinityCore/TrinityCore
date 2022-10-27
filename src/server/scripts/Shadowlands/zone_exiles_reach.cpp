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

#include "Player.h"
#include "ScriptMgr.h"

enum SpellHordeShipCrash
{
    MOVIE_HORDE_SHIP_CRASH = 931,
    SPELL_HORDE_SHIP_CRASH = 325133
};

class spell_Horde_ship_crash : public PlayerScript
{
public:
    spell_Horde_ship_crash() : PlayerScript("spell_Horde_ship_crash") { }

    void OnMovieComplete(Player* player, uint32 movieId) override
    {
        if(movieId == MOVIE_HORDE_SHIP_CRASH)
            player->CastSpell(player, SPELL_HORDE_SHIP_CRASH, true);
    }
};

void AddSC_zone_exiles_reach()
{
    new spell_Horde_ship_crash();
}
