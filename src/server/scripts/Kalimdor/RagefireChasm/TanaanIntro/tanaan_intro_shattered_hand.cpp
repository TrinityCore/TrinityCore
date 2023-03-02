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

#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "tanaan_intro.h"
#include "TemporarySummon.h"

Position g_ShatteredHandSpawn[4] =
{
    { 4419.8500f, -2783.7099f, 15.9326f, 4.84f }, ///< Pos 0, extreme right
    { 4408.6499f, -2786.5200f, 14.3980f, 4.82f }, ///< Pos 1, right
    { 4395.9501f, -2786.4499f, 14.4047f, 4.82f }, ///< Pos 2, left
    { 4384.6699f, -2781.9299f, 15.9378f, 4.58f }  ///< Pos 3, extreme left
};

void AddSC_tanaan_intro_shattered_hand()
{
    
}
