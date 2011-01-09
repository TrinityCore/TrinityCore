/*
 * Copyright (C) 2010 TrinityScript 2
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

#ifndef DEF_EYE_OF_ETERNITY_H
#define DEF_EYE_OF_ETERNITY_H

enum
{
    MAX_ENCOUNTER                = 1,
 
    TYPE_MALYGOS                 = 2,
    TYPE_OUTRO_CHECK             = 4,  // Because this encounter is really hard and outro takes about 90s and malygos dies at its end, I add some check against server crash
    TYPE_DESTROY_PLATFORM        = 5,
    TYPE_VORTEX                  = 6,
    TYPE_PLAYER_HOVER            = 7,
    DATA_DROP_PLAYERS            = 8,
    
    NPC_WYRMREST_SKYTALON        = 30161, // Dragon Vehicle in Third Phase
    NPC_MALYGOS                  = 28859,
};

#endif