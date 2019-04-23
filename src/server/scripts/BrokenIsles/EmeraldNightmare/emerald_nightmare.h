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

#ifndef EMERALD_NIGHTMARE_H
#define EMERALD_NIGHTMARE_H

enum DataTypes
{
    DATA_NYTHENDRA              = 0,
    DATA_ILGYNOTH               = 1,
    DATA_ELERETHE_RENFERAL      = 2,
    DATA_URSOC                  = 3,
    DATA_DRAGONS_OF_NIGHTMARE   = 4,
    DATA_CENARIUS               = 5,
    DATA_XAVIUS                 = 6,

    DATA_MAX_ENCOUNTERS
};

enum Creatures
{
    NPC_NYTHENDRA           = 102672,
    NPC_CORRUPTED_VERMIN    = 102998,

    NPC_ILGYNOTH            = 105393,
    NPC_ELERETHE_RENFERAL   = 106087,
    NPC_URSOC               = 100497,
    NPC_YSONDRE             = 102679,
    NPC_EMERISS             = 102683,
    NPC_LETHON              = 102682,
    NPC_TAERAR              = 102681,
    NPC_CENARIUS            = 104636,
    NPC_XAVIUS              = 103769,
};

enum GameObjects
{
    GOB_NYTHENDRA_ENTRANCE_1    = 251535,
    GOB_NYTHENDRA_ENTRANCE_2    = 251536,
};

enum SpellVisualKit
{
    SPELL_VISUAL_KIT_EMERALD_NIGHTMARE_ENTRANCE_LOCATION = 70900,
    SPELL_VISUAL_KIT_EMERALD_NIGHTMATE_POST_XAVIUS_EXIT  = 74270,
};

#endif
