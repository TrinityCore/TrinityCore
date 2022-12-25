/*
 * Copyright 2023 AzgathCore
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

#ifndef THE_MOTHERLODE_H
#define THE_MOTHERLODE_H

#define DataHeader "TM"

uint32 const EncounterCount = 4;

enum EncounterData
{
    DATA_COIN_OPERATED_CROWD_PUMMELER	= 0,
    DATA_AZEROKK						= 1,
    DATA_RIXXA_FLUXFLAME				= 2,
    DATA_MOGUL_RAZDUNK					= 3,
};

enum CreatureIds
{
	NPC_COIN_OPERATED_CROWD_PUMMELER	= 129214,
    NPC_AZEROKK							= 129227,
    NPC_RIXXA_FLUXFLAME					= 129231,
    NPC_MOGUL_RAZDUNK					= 129232,
};

#endif // THE_MOTHERLODE_H
