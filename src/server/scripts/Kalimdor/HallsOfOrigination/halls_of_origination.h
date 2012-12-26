/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#ifndef HALLS_OF_ORIGINATION_H
#define HALLS_OF_ORIGINATION_H

#define HoOScriptName "instance_halls_of_origination"

uint32 const EncounterCount = 7;

enum Data
{
    // Bosses
    DATA_TEMPLE_GUARDIAN_ANHUUR,
    DATA_EARTHRAGER_PTAH,
    DATA_ANRAPHET,
    DATA_ISISET,
    DATA_AMMUNAE,
    DATA_SETESH,
    DATA_RAJH,
    
    // Temple Guardian Anhuur
    DATA_ANHUUR_GUID,
    DATA_ANHUUR_LEFT_BEACON,
    DATA_ANHUUR_RIGHT_BEACON,
    DATA_ANHUUR_BRIDGE,
    DATA_ANHUUR_DOOR,
};

enum Creatures
{
    BOSS_TEMPLE_GUARDIAN_ANHUUR     = 39425,
    NPC_CAVE_IN_STALKER             = 40183,
    NPC_SEARING_LIGHT               = 40283,
    
    BOSS_EARTHRAGER_PTAH            = 39428,
    NPC_BEETLE_STALKER              = 40459, // Summons both Jeweled Scarab and Dustbone Horror
    NPC_JEWELED_SCARAB              = 40458,
    NPC_DUSTBONE_HORROR             = 40450,
    NPC_QUICKSAND                   = 40503, // Summoned by a spell not in dbc (75550)
};

enum GameObjects
{
    GO_ANHUURS_BRIDGE               = 206506,
    GO_DOODAD_ULDUM_ELEVATOR_COL01  = 207725,
    GO_ANHUURS_DOOR                 = 202307,
    GO_ANHUURS_RIGHT_BEACON         = 203136,
    GO_ANHUURS_LEFT_BEACON          = 203133,
};

template<class AI>
CreatureAI* GetHallsOfOriginationAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(HoOScriptName))
                return new AI(creature);
    return NULL;
}

#endif // HALLS_OF_ORIGINATION_H
