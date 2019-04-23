/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef COURT_OF_STARS_H
#define COURT_OF_STARS_H

#define DataHeader "COSTAR"

uint32 const EncounterCount = 3;

enum DataTypes
{
    DATA_PATROL_CAPTAIN_GERDO   = 0,
    DATA_TALIXAE_FRAMEWREATH    = 1,
    DATA_ADVISOR_MELANDRUS      = 2
};

enum CreatureIds
{
    NPC_PATROL_CAPTAIN_GERDO    = 104215,
    NPC_TALIXAE_FRAMEWREATH     = 104217,
    NPC_ADVISOR_MELANDRUS       = 101831
};

#endif // COURT_OF_STARS_H
