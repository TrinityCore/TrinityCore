/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_MAGISTERS_TERRACE_H
#define DEF_MAGISTERS_TERRACE_H

uint32 const EncounterCount = 4;

enum DataTypes
{
    DATA_SELIN,
    DATA_VEXALLUS,
    DATA_DELRISSA,
    DATA_KAELTHAS,

    DATA_KAEL_STATUE_LEFT,
    DATA_KAEL_STATUE_RIGHT,

    DATA_DELRISSA_DEATH_COUNT,
    DATA_KAELTHAS_STATUES,
    DATA_ESCAPE_ORB
};

enum CreatureIds
{
    NPC_SELIN               = 24723,
    NPC_DELRISSA            = 24560,
    NPC_FEL_CRYSTAL         = 24722
};

enum GameObjectIds
{
    GO_VEXALLUS_DOOR        = 187896,
    GO_SELIN_DOOR           = 187979,
    GO_SELIN_ENCOUNTER_DOOR = 188065,
    GO_DELRISSA_DOOR        = 187770,
    GO_KAEL_DOOR            = 188064,
    GO_KAEL_STATUE_1        = 188165,
    GO_KAEL_STATUE_2        = 188166,
    GO_ESCAPE_ORB           = 188173
};

#endif
