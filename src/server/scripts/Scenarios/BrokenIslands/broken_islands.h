/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_A_BROKEN_ISLANDS
#define DEF_A_BROKEN_ISLANDS

enum Spells
{
};

enum Data
{
    DATA_SCENARIO_TEAM = 0,
};

enum steps
{
    SCENARIO_STEP_8 = 7,
    SCENARION_STEP_9 = 8,
    SCENARION_STEP_END
};

enum eCreatures : uint32
{
    VIEWPOINT = 93219,
    STEP6_VEHICLE = 100959,
    NPC_KROSS = 90544,

    NPC_VARIAN = 90713, //0x202090B680589640001EFF000053DF33
    NPC_JAINA = 90714,
    NPC_TIRION = 91951,
    NPC_GULDAN = 94276,

    NPC_LORD_JAR = 105179,
    NPC_BRUTAL = 91902,
    NPC_TIHONDR = 90688,

    NPC_STAGE3_HORDE_FEL_COMMANDER = 93719,

    //Horde at stage 4 (others)
    NPC_HORDE_BAINE_BLOODHOOF = 90710,
    NPC_SYLVANA = 90709,
};

enum eGameObects
{
    GO_ALLIANCE_SHIP = 251604,
    GO_HORDE_SHIP = 255203,
    TRANSPORT_ALLIANCE = 251513,
    TRANSPORT_HORDE = 254124,
    //Spires of Woe destroyed
    GO_SPIRES_OF_WOE = 240194,
};

#endif
