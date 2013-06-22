/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_DARKPORTAL_H
#define DEF_DARKPORTAL_H

uint32 const EncounterCount             = 2;

enum DataTypes
{
    TYPE_MEDIVH                         = 1,
    TYPE_RIFT                           = 2,
    TYPE_AEONUS                         = 3,
    TYPE_TEMPORUS                       = 4,
    TYPE_CRONO_LORD_DEJA                = 5,
    DATA_MEDIVH                         = 10,
    DATA_PORTAL_COUNT                   = 11,
    DATA_SHIELD                         = 12
};

enum WorldStateIds
{
    WORLD_STATE_BM                      = 2541,
    WORLD_STATE_BM_SHIELD               = 2540,
    WORLD_STATE_BM_RIFT                 = 2784
};

enum QuestIds
{
    QUEST_OPENING_PORTAL                = 10297,
    QUEST_MASTER_TOUCH                  = 9836
};

enum CreatureIds
{
    NPC_MEDIVH                          = 15608,
    NPC_TIME_RIFT                       = 17838,
    NPC_TIME_KEEPER                     = 17918,
    NPC_RIFT_KEEPER                     = 21104,
    NPC_RIFT_LORD                       = 17839,
    NPC_CRONO_LORD_DEJA                 = 17879,
    NPC_TEMPORUS                        = 17880,
    NPC_AEONUS                          = 17881,
    NPC_INFINITE_ASSASIN                = 17835,
    NPC_INFINITE_WHELP                  = 21818,
    NPC_INFINITE_CRONOMANCER            = 17892,
    NPC_INFINITE_EXECUTIONER            = 18994,
    NPC_INFINITE_VANQUISHER             = 18995
};

#endif

