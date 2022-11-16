/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef DEF_SEPULCHER_OF_THE_FIRST_ONES_H_
#define DEF_SEPULCHER_OF_THE_FIRST_ONES_H_

#include "CreatureAIImpl.h"

#define DataHeader "SFO"
#define SFOScriptName "instance_sepulcher_of_the_first_ones"


uint32 const EncounterCount = 11;

enum SepulcherOfTheFirstOnesDataTypes
{
    // Bosses

    DATA_ANDUIN_WRYNN = 7,

    // Encounter-related data

};


enum SepulcherOfTheFirstOnesCreatureIds
{
    // Bosses

    BOSS_ANDUIN_WRYNN = 181954,

    // Anduin Wrynn Encounter

    NPC_LADY_JAINA_PROUDMOORE = 183664,
    NPC_UTHER_THE_LIGHTBRINGER = 183665,
    NPC_SYLVANAS_WINDRUNNER = 183666,

    NPC_BEFOULED_BARRIER = 184585,

    NPC_ANDUIN_DESPAIR = 184520,
    NPC_ANDUIN_HOPE = 184493,
    NPC_ANDUIN_DOUBT = 184494,

    NPC_REMNANT_OF_A_FALLEN_KING = 183463,
    NPC_MONSTROUS_SOUL = 183671,
    NPC_FIENDISH_SOUL = 183669,
    NPC_GRIM_REFLECTION = 183033,

    NPC_BEACON_OF_HOPE = 184830,
    


};

enum SepulcherOfTheFirstOnesTranslocatorIds
{
    NPC_ANCIENT_TRANSLOCATOR = 182431,

};

enum SepulcherOfTheFirstOnesGameObjectIds
{
    GAMEOBJECT_BRIDGE_TO_ANDUIN = 375110,
    GAMEOBJECT_BRIDGE_AFTER_ANDUIN = 375035,
    GAMEOBJECT_ANDUIN_CHEST_LOOT = 375901,
};

enum SepulcherOfTheFirstOnesEvents
{
    EVENT_RESET_PLAYERS_ON_TRANSLOCATOR = 1
};



enum SepulcherOfTheFirstOnesActions
{
    
};

enum SepulcherOfTheFirstOnesAreas
{
    AREA_DOMINATION_GRASP = 13965,
};

enum SepulcherOfTheFirstOnesWorldStates
{


};

template <class AI, class T>
inline AI* GetSepulcherOfTheFirstOnesAI(T* obj)
{
    return GetInstanceAI<AI>(obj, SFOScriptName);
}

#define RegisterSepulcherOfTheFirstOnesCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetSepulcherOfTheFirstOnesAI)

#endif
