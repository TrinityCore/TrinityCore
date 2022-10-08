/*
* Copyright (C) 2021 BfaCore Reforged
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#ifndef CATHEDRAL_OF_ETERNAL_NIGHT_H_
#define CATHEDRAL_OF_ETERNAL_NIGHT_H_

enum eData
{
    DATA_AGRONOX            = 0,
    DATA_THRASHBITE         = 1,
    DATA_DOMATRAX           = 2,
    DATA_MEPHISTROTH        = 3,
    
    MAX_ENCOUNTER,
    
};

enum eCreatures
{
    NPC_ILLIDAN_INTRO       = 120792,
    NPC_MAIEV_INTRO         = 119147,
    
    // adds on agronox
    NPC_FLUMINATING_LASHERS = 119169,
    NPC_CHOKING_VINES       = 120014,
    NPC_THRASHBITE_THE_SCORNFUL = 117194,
    
    BOSS_THRASHBITE         = 117194,
    NPC_GAZERAX             = 118723,
    
    NPC_NALASHA             = 118705,
    
    // Domatrax
    BOSS_DOMATRAX           = 118804,
    NPC_EGIDA_START         = 118884,
    NPC_PORTAL_OWNER        = 118834,    
    
    NPC_IMP                 = 118801, // both first wave
    NPC_FELGUARD            = 119157, // heroic second wave
    NPC_SHIVARRA            = 118802, // mytic second wave
    
    // mephistroth
    BOSS_MEPHISTROTH        = 116944,
    NPC_BATS_INTRO          = 120405,
    NPC_BATS_FLY            = 118642, 
    NPC_EGIDA_GIVE_BUFF     = 118418,
    NPC_SHADOW_OF_MEPHISTROTH = 117590,
    NPC_ILLIDAN_MEPHISTROTH = 117855,
    NPC_ILLIDAN_VISUAL_OUT  = 121982,
    
    NPC_EGIDA_FINAL         = 119146,
    NPC_EGVIN_FINAL         = 121234,
};

enum eGameObjects
{
    GO_AGRONOX_DOOR          = 269221,
    
    GO_THRASHBITE_DOOR_ENTER = 268709,
    GO_THRASHBITE_DOOR       = 268710,
    
    GO_THRASHBITE_BOOKCASE_1 = 268374,
    GO_THRASHBITE_BOOKCASE_2 = 268375,
    GO_THRASHBITE_BOOKCASE_3 = 268372,
    GO_THRASHBITE_BOOKCASE_4 = 268373,
    
    GO_NALASHA_EVENT         = 269121,
    
    GO_EGIDA_FINAL           = 269173,
    GO_LAST_DOORS            = 268680
};

#endif
