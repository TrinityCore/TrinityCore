/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef CULLING_OF_STRATHOLME_H
#define CULLING_OF_STRATHOLME_H

#include "CreatureAIImpl.h"

#define DataHeader "CS"
#define CoSScriptName "instance_culling_of_stratholme"

uint32 constexpr EncounterCount = 5;

/***********************************************************************************************************************\
|************************* A DEVELOPER'S GUIDE TO FINDING YOUR WAY AROUND THIS INSTANCE SCRIPT *************************|
|***********************************************************************************************************************|
*   The primary instance logic is split between the instance control script (instance_culling_of_stratholme.cpp) and    *
*   Arthas' creature AI (npc_arthas.cpp). The instance script is responsible for global state management and control    *
*   of the Scourge Wave event, as well as spawn control (ties into state management) with the help of the templated     *
*   CreatureScript wrapper (CanSpawn override as well as Despawn checks on state change) defined in this very header.   *
*   Arthas handles all the actual RP timings, pathing, spawns, casts and everything else, really. He also does tons     *
*   of state control for himself (positional snapback and gossip/flag management).                                      *
*   Communication between these two scripts (with some auxiliary other scripts throwing stuff in too) is handled        *
*   via the SetData/SetGuidData/SetGUID methods on CreatureAI and InstanceScript (as appropriate), as well as           *
*   data retrieval using GetData (instance states and the like).                                                        *
*   All values specified in this header find use across multiple files (used for communication between them) while      *
*   the enums in the files themselves contain action IDs, event IDs, entries and whatnot that only find use in that     *
*   particular file.                                                                                                    *
*   Generally, any RP sequence will follow the form:                                                                    *
*    1. RP sequence is started (creature gossip sends SetGuidData with starting player GUID to InstanceScript)          *
*    2. InstanceScript verifies state consistency and advances the global instance state                                *
*    3. InstanceScript passes the player GUID to Arthas AI using SetGUID. The int32 data type serves as action ID.      *
*    4. Arthas AI schedules all necessary events for the sequence and handles it from there using its UpdateAI loop.    *
*    5. At the end of the sequence, Arthas AI notifies the instance script (using SetData).                             *
*    6. The instance script advances the global state again. This state change is propagated to Arthas AI (SetData).    *
*    7. Arthas AI is notified of a state change, gets current progress (GetData) and adjusts gossip availability etc.   *
*    8. The cycle repeats. RP sequences (as above) can (and do) also include combat sequences and similar.              *
|***********************************************************************************************************************|
|*********************************************** KEY METHODS TO LOOK FOR ***********************************************|
|***********************************************************************************************************************|
*   Arthas AI: (npc_arthas_stratholmeAI in npc_arthas.cpp)                                                              *
*    - AdvanceToState:                                                                                                  *
*      - handles all the state updating/position consistency logic                                                      *
*      - invoked from SetData when the instance script notifies Arthas of a state change                                *
*    - ScheduleActionOOC:                                                                                               *
*      - queues the specified action to be passed to DoAction after Arthas finishes combat (JustReachedHome)            *
*      - typically called during RP sequences just after ensuring Arthas has entered combat with all enemies involved   *
*    - MovementInform:                                                                                                  *
*      - handles movement notifications not just for Arthas, but also some other creatures that run RP slave AI         *
*      - all movement IDs are taken from one single PointIDs enum, which means they are still unique                    *
*    - EnterCombat:                                                                                                     *
*      - stores the current spline chain state so we can resume after (JustReachedHome)                                 *
|***********************************************************************************************************************|
*   Instance script: (instance_culling_of_stratholme in instance_culling_of_stratholme.cpp)                             *
*    - GetStableStateFor:                                                                                               *
*      - handles state regression; only certain states should be loaded after a wipe/soft reset                         *
*    - SetInstanceProgress:                                                                                             *
*      - any changing of the global instance state is done through this method                                          *
*      - handles world state adjustments, spawn control (through AI notification) as well as reset behavior             *
*    - SetWorldState/PropagateWorldStateUpdate:                                                                         *
*      - the instance script stores a std::map of all current world state values for the instance                       *
*      - SetWorldState adjusts this map, PropagateWorldStateUpdate sends any changed values to all players              *
*      - FillInitialWorldStates also draws upon this map to ensure all players have the same states at all times        *
|***********************************************************************************************************************|
*   Spawn control script: (StratholmeCreatureScript<ParentAI> in culling_of_stratholme.h)                               *
*    - CanSpawn override:                                                                                               *
*      - gets current instance state using GetData, then checks if we should be allowed to respawn (bitmask check)      *
*    - StratholmeNPCAIWrapper::CheckDespawn:                                                                            *
*      - gets current instance state using GetData, then checks if we should despawn ourselves (bitmask check)          *
\***********************************************************************************************************************/

struct Position;

// Note: These are bitmask values to allow combining, but only a single bit will ever be true in instance script
enum COSProgressStates : uint32
{
    JUST_STARTED            = 0x00001, // dungeon just started, crate count not visible yet; pending chromie interaction
    CRATES_IN_PROGRESS      = 0x00002, // freshly started dungeon, players are revealing scourge crates
    CRATES_DONE             = 0x00004, // all crates revealed, chromie spawns at Stratholme entrance; waiting for player input to begin first RP event
    UTHER_TALK              = 0x00008, // RP event in progress, Uther+Arthas talking
    PURGE_PENDING           = 0x00010, // RP event done, pending player input to start wave event
    PURGE_STARTING          = 0x00020, // Arthas entering Stratholme, RP sequence with Mal'ganis
    WAVES_IN_PROGRESS       = 0x00040, // first section is underway, players are battling waves
    WAVES_DONE              = 0x00080, // wave section completed; Arthas moving to take position in front of Stratholme Town Hall
    TOWN_HALL_PENDING       = 0x00100, // Arthas has reached the Town Hall; pending player input to begin escort section
    TOWN_HALL               = 0x00200, // now escorting Arthas through Stratholme Town Hall
    TOWN_HALL_COMPLETE      = 0x00400, // Town Hall event complete, third boss defeated; pending player input to begin gauntlet transition
    GAUNTLET_TRANSITION     = 0x00800, // Arthas is leading players through the secret passage from Town Hall to the gauntlet
    GAUNTLET_PENDING        = 0x01000, // Pending player input to begin escorting Arthas through the final gauntlet section
    GAUNTLET_IN_PROGRESS    = 0x02000, // Arthas is being escorted through the gauntlet section
    GAUNTLET_COMPLETE       = 0x04000, // Arthas has reached the end of the gauntlet section; player input pending to begin Mal'ganis encounter
    MALGANIS_IN_PROGRESS    = 0x08000, // Arthas has moved into the final square and Mal'ganis encounter begins
    COMPLETE                = 0x10000, // Mal'ganis encounter is completed; dungeon over

    ALL                     = 0x1FFFF
};
COSProgressStates GetStableStateFor(COSProgressStates const state); // defined by instance script
Position const& GetArthasSnapbackFor(COSProgressStates state); // defined by arthas script

enum COSInstanceData
{
    DATA_MEATHOOK,
    DATA_SALRAMM,
    DATA_EPOCH,
    DATA_MAL_GANIS,
    DATA_INFINITE_CORRUPTOR,
    NUM_BOSS_ENCOUNTERS,

    DATA_INSTANCE_PROGRESS = NUM_BOSS_ENCOUNTERS, // GET only
    DATA_GM_RECALL,        // sent by chromie #1 in response to GM recall command (teleport all to arthas)
    DATA_GM_OVERRIDE,      // sent by chromie #1 in response to GM instance state change commands
    DATA_ARTHAS_DIED,      // failure signal, sent by arthas AI on death - regress instance
    DATA_CRATES_START,     // sent by chromie #1 creature script to initiate crate phase
    DATA_CRATE_REVEALED,   // sent by crate helper AI to trigger re-check of crate status
    DATA_UTHER_START,      // sent by chromie #2 creature script to initiate uther RP sequence
    DATA_UTHER_FINISHED,   // sent by arthas AI to signal transition to pre-purge
    DATA_SKIP_TO_PURGE,    // sent by chromie #1 creature script to skip straight to start of purge
    DATA_START_PURGE,      // sent by arthas creature script to begin pre-purge RP event
    DATA_START_WAVES,      // sent by arthas AI to begin wave event
    DATA_NOTIFY_DEATH,     // sent by wave mob AI to instance script on death
    DATA_REACH_TOWN_HALL,  // sent by arthas AI once he reaches stratholme town hall
    DATA_START_TOWN_HALL,  // sent by arthas creature script to begin town hall sequence
    DATA_TOWN_HALL_DONE,   // sent by arthas AI once Epoch is defeated
    DATA_TO_GAUNTLET,      // sent by arthas creature script to begin gauntlet transition
    DATA_GAUNTLET_REACHED, // sent by arthas AI once he arrives at the beginning of the gauntlet section
    DATA_START_GAUNTLET,   // sent by arthas creature script to begin gauntlet escort
    DATA_GAUNTLET_DONE,    // sent by arthas AI once he arrives at the end of the gauntlet section
    DATA_START_MALGANIS,   // sent by arthas creature script to begin mal'ganis event
    DATA_MALGANIS_DONE     // sent by arthas AI once mal'ganis outro is over
};

// these are sent by instance AI to creatures; they are passed as negative values to avoid conflicts with creature script specific actions
enum COSInstanceActions
{
    ACTION_PROGRESS_UPDATE = 1,
    ACTION_CORRUPTOR_LEAVE,
    ACTION_START_RP_EVENT1,   // Arthas/Uther chat in front of town
    ACTION_START_RP_EVENT2,   // Arthas/Mal'ganis chat at entrance
    ACTION_START_RP_EVENT3,   // Town Hall sequence
    ACTION_START_RP_EVENT4_1, // Bookcase transition sequence
    ACTION_START_RP_EVENT4_2, // Gauntlet escort phase
    ACTION_START_RP_EVENT5    // Mal'ganis encounter
};

enum COSInstanceEntries
{
    NPC_ARTHAS = 26499,
    GO_HIDDEN_PASSAGE = 188686,
    SPAWNGRP_CHROMIE_MID = 52,
    SPAWNGRP_CRATE_HELPERS = 53,
    SPAWNGRP_GAUNTLET_TRASH = 54,
    SPAWNGRP_UNDEAD_TRASH = 55,
    SPAWNGRP_RESIDENTS = 56
};

template <class AI, class T>
inline AI* GetCullingOfStratholmeAI(T* obj)
{
    return GetInstanceAI<AI>(obj, CoSScriptName);
}

#endif
