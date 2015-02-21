/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef HIGHMAUL_H
#define HIGHMAUL_H

#define DataHeader "HM"

uint32 const EncounterCount       = 8;

enum Data
{
    // Encounter States/Boss GUIDs
    DATA_BRACKENSPORE             = 0,
    DATA_KARGATHBLADEFIST         = 1,
    DATA_KORAGH                   = 2,
    DATA_MARGOK                   = 3,
    DATA_TECTUS                   = 4,
    DATA_THEBUTCHER               = 5,
    DATA_TWINOGRONPOL             = 6,
    DATA_TWINOGRONPHEMOS          = 7
};

enum CreatureIds
{
    BOSS_BRACKENSPORE              = 78491,
    BOSS_KARGATHBLADEFIST          = 78714,
    BOSS_KORAGH                    = 79015,
    BOSS_MARGOK                    = 77428,
    BOSS_TECTUS                    = 78948,
    BOSS_THEBUTCHER                = 77404,
    BOSS_TWINOGRONPOL              = 78238,
    BOSS_TWINOGRONPHEMOS           = 78237
};

enum GameObjectIds
{
};

#endif
