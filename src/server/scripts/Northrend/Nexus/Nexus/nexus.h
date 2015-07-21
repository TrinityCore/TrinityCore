/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_NEXUS_H
#define DEF_NEXUS_H

#define NexusScriptName "instance_nexus"
#define DataHeader "NEX"

uint32 const EncounterCount = 4; 

enum DataTypes
{
    DATA_MAGUS_TELESTRA               = 0,
    DATA_ANOMALUS                     = 1,
    DATA_ORMOROK                      = 2,
    DATA_KERISTRASZA                  = 3,

    ANOMALUS_CONTAINMET_SPHERE        = 4,
    ORMOROKS_CONTAINMET_SPHERE        = 5,
    TELESTRAS_CONTAINMET_SPHERE       = 6
};

enum CreatureIds
{
    NPC_ANOMALUS                      = 26763,
    NPC_KERISTRASZA                   = 26723,
    
    // Alliance
    NPC_ALLIANCE_BERSERKER            = 26800,
    NPC_ALLIANCE_RANGER               = 26802,
    NPC_ALLIANCE_CLERIC               = 26805,
    NPC_ALLIANCE_COMMANDER            = 27949,
    NPC_COMMANDER_STOUTBEARD          = 26796,
    
    // Horde
    NPC_HORDE_BERSERKER               = 26799,
    NPC_HORDE_RANGER                  = 26801,
    NPC_HORDE_CLERIC                  = 26803,
    NPC_HORDE_COMMANDER               = 27947,
    NPC_COMMANDER_KOLURG              = 26798
};

enum GameObjectIds
{
    GO_ANOMALUS_CONTAINMET_SPHERE     = 188527,
    GO_ORMOROKS_CONTAINMET_SPHERE     = 188528,
    GO_TELESTRAS_CONTAINMET_SPHERE    = 188526 
};

#endif
