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

#ifndef HALLS_OF_REFLECTION_H_
#define HALLS_OF_REFLECTION_H_

#include "CreatureAIImpl.h"
#include "EventProcessor.h"
#include "ObjectGuid.h"

class Unit;

#define HoRScriptName "instance_halls_of_reflection"
#define DataHeader    "HOR"

uint32 const EncounterCount = 3;

/* Halls of Reflection encounters:
 0 - Falric
 1 - Marwyn
 2 - The Lich King
*/

enum HORDataTypes
{
    DATA_FALRIC                                 = 0,
    DATA_MARWYN                                 = 1,
    DATA_THE_LICH_KING_ESCAPE                   = 2,

    DATA_INTRO_EVENT                            = 3,
    DATA_FROSTSWORN_GENERAL                     = 4,

    DATA_KORELN_LORALEN                         = 5,
    DATA_WAVE_COUNT                             = 6,
    DATA_TEAM_IN_INSTANCE                       = 7,
    DATA_FROSTMOURNE                            = 8,
    DATA_IMPENETRABLE_DOOR                      = 9,
    DATA_ESCAPE_LEADER                          = 10,
    DATA_ICEWALL                                = 11,
    DATA_ICEWALL_TARGET                         = 12,
    DATA_GUNSHIP                                = 13,

    // Quest stuff
    DATA_QUEL_DELAR_EVENT                       = 14,
    DATA_FROSTMOURNE_ALTAR_BUNNY                = 15,
    DATA_UTHER_QUEL_DELAR                       = 16,
    DATA_QUEL_DELAR_INVOKER                     = 17
};

enum HORCreatureIds
{
    NPC_JAINA_INTRO                             = 37221,
    NPC_SYLVANAS_INTRO                          = 37223,
    NPC_UTHER                                   = 37225,
    NPC_THE_LICH_KING_INTRO                     = 37226,
    NPC_KORELN                                  = 37582,
    NPC_LORALEN                                 = 37779,
    NPC_FROSTMOUNRE_ALTAR_BUNNY                 = 37704,

    NPC_FALRIC                                  = 38112,
    NPC_MARWYN                                  = 38113,
    NPC_WAVE_MERCENARY                          = 38177,
    NPC_WAVE_FOOTMAN                            = 38173,
    NPC_WAVE_RIFLEMAN                           = 38176,
    NPC_WAVE_PRIEST                             = 38175,
    NPC_WAVE_MAGE                               = 38172,

    NPC_FROSTSWORN_GENERAL                      = 36723,
    NPC_REFLECTION                              = 37068, // 37107 for tank only?

    NPC_JAINA_ESCAPE                            = 36955,
    NPC_SYLVANAS_ESCAPE                         = 37554,
    NPC_THE_LICH_KING_ESCAPE                    = 36954,
    NPC_ICE_WALL_TARGET                         = 37014,

    NPC_RAGING_GHOUL                            = 36940,
    NPC_RISEN_WITCH_DOCTOR                      = 36941,
    NPC_LUMBERING_ABOMINATION                   = 37069,

    NPC_GUNSHIP_CANNON_HORDE                    = 37593,
    NPC_JUSTIN_BARTLETT                         = 30344,
    NPC_KORM_BLACKSCAR                          = 30824,

    NPC_WORLD_TRIGGER                           = 22515
};

enum HORGameObjectIds
{
    GO_FROSTMOURNE                              = 202302,
    GO_ENTRANCE_DOOR                            = 201976,
    GO_IMPENETRABLE_DOOR                        = 197341,
    GO_SHADOW_THRONE_DOOR                       = 197342,
    GO_ESCAPE_DOOR                              = 197343, // always open ?

    GO_ICE_WALL                                 = 201385,
    GO_CAVE_IN                                  = 201596,

    GO_THE_SKYBREAKER                           = 201598,
    GO_ORGRIMS_HAMMER                           = 201599,
    GO_THE_SKYBREAKER_STAIRS                    = 201709,
    GO_ORGRIMS_HAMMER_STAIRS                    = 202211,
    GO_PORTAL_TO_DALARAN                        = 195682,

    GO_THE_CAPTAIN_CHEST_ALLIANCE_NORMAL        = 201710,
    GO_THE_CAPTAIN_CHEST_HORDE_NORMAL           = 202212,
    GO_THE_CAPTAIN_CHEST_ALLIANCE_HEROIC        = 202336,
    GO_THE_CAPTAIN_CHEST_HORDE_HEROIC           = 202337
};

enum HORAchievements
{
    ACHIEV_NOT_RETREATING_EVENT                 = 22615,
    SPELL_ACHIEV_CHECK                          = 72830
};

// Common actions from Instance Script to Boss Script
enum HORActions
{
    ACTION_ENTER_COMBAT                         = -668001,
    ACTION_START_PREFIGHT                       = -668002,
    ACTION_WALL_BROKEN                          = -668003,
    ACTION_GUNSHIP_ARRIVAL                      = -668004,
    ACTION_GUNSHIP_ARRIVAL_2                    = -668005
};

enum HORInstanceEvents
{
    EVENT_SPAWN_WAVES                           = 1,
    EVENT_NEXT_WAVE                             = 2,
    EVENT_DO_WIPE                               = 3,
    EVENT_ADD_WAVE                              = 4,
    EVENT_SPAWN_ESCAPE_EVENT                    = 5,
    EVENT_QUEL_DELAR_SUMMON_UTHER               = 6
};

enum HORInstanceEventIds
{
    EVENT_GUNSHIP_ARRIVAL                       = 22709,
    EVENT_GUNSHIP_ARRIVAL_2                     = 22714,
    EVENT_ICE_WALL_SUMMONED                     = 22795
};

enum HORInstanceSpells
{
    // Trash
    SPELL_WELL_OF_SOULS                         = 72630, // cast when spawn (become visible)
    SPELL_SPIRIT_ACTIVATE                       = 72130, // cast when unit activates

    // Start Quests
    SPELL_START_HALLS_OF_REFLECTION_QUEST_A     = 71351,
    SPELL_START_HALLS_OF_REFLECTION_QUEST_H     = 71542,
    SPELL_START_HALLS_OF_REFLECTION_QUEST_AE    = 72900,

    // Quest Credits
    SPELL_CREDIT_FINDING_SYLVANAS               = 71536,
    SPELL_CREDIT_FINDING_JAINA                  = 71538,
    SPELL_CREDIT_ESCAPING_ARTHAS                = 71352,

    // Gunship
    SPELL_GUNSHIP_CANNON_FIRE                   = 70017,
    SPELL_GUNSHIP_CANNON_FIRE_MISSILE_ALLIANCE  = 70021,
    SPELL_GUNSHIP_CANNON_FIRE_MISSILE_HORDE     = 70246,

    // Halls of Reflection quest
    SPELL_QUEL_DELAR_COMPULSION                 = 70013,
    SPELL_ESSENCE_OF_CAPTURED                   = 70720
};

enum HORInstanceQuests
{
    QUEST_HALLS_OF_REFLECTION_ALLIANCE          = 24480,
    QUEST_HALLS_OF_REFLECTION_HORDE             = 24561
};

enum HORInstanceWorldStates
{
    WORLD_STATE_HOR_WAVES_ENABLED               = 4884,
    WORLD_STATE_HOR_WAVE_COUNT                  = 4882
};

enum HORInstanceYells
{
    SAY_CAPTAIN_FIRE                            = 0,
    SAY_CAPTAIN_FINAL                           = 1
};

class GameObjectDeleteDelayEvent : public BasicEvent
{
    public:
        GameObjectDeleteDelayEvent(Unit* owner, ObjectGuid gameObjectGUID) : _owner(owner), _gameObjectGUID(gameObjectGUID) { }

        void DeleteGameObject();

        bool Execute(uint64 /*execTime*/, uint32 /*diff*/) override
        {
            DeleteGameObject();
            return true;
        }

        void Abort(uint64 /*execTime*/) override
        {
            DeleteGameObject();
        }

    private:
        Unit* _owner;
        ObjectGuid _gameObjectGUID;
};

template <class AI, class T>
inline AI* GetHallsOfReflectionAI(T* obj)
{
    return GetInstanceAI<AI>(obj, HoRScriptName);
}

#endif // HALLS_OF_REFLECTION_H_
