/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef DEF_NEW_KARAZHAN_H
#define DEF_NEW_KARAZHAN_H

#include "Map.h"
#include "Creature.h"
#include "ObjectMgr.h"

#define DataHeader "NKARA"
#define NKARAScriptName "instance_new_karazhan"

constexpr uint8 EncounterCount              = 8;

enum NKARADataIds
{
    DATA_MAIDEN_OF_VIRTUE                   = 1,
    DATA_MOROES                             = 2,
    DATA_OPERA                              = 3,
    DATA_ATTUMEN                            = 4,
    DATA_NIGHTBANE                          = 5,
    DATA_CURATOR                            = 6,
    DATA_SHADE_OF_MEDIVH                    = 7,
    DATA_MANA_DEVOURER                      = 8,
    DATA_VIZADUUM                           = 9,
    DATA_OPERA_EVENT                        = 10,
    DATA_FEL_CANNON                         = 11,
    DATA_FIRST_SHIP                         = 12,
    DATA_SECOND_SHIP                        = 13,
    DATA_NIGHTBANE_TIMER                    = 14,
    DATA_NIGHTBANE_EVENT                    = 15,
    DATA_IMAGE_OF_MEDIVH                    = 16
};

enum NKARACreaturesIds
{
    // Lower Karazhan
    BOSS_MAIDEN_OF_VIRTUE                   = 113971,
    BOSS_MOROES                             = 114312,
    BOSS_ATTUMEN                            = 114262,

    // Opera Event Westfall Story
    BOSS_TOE_KNEE                           = 114261,
    BOSS_MRRGRIA                            = 114260,

    // Opera Event Beatiful Beast
    BOSS_COGGLESTON                         = 114328,
    BOSS_LUMINORE                           = 114329,
    BOSS_BABLET                             = 114330,
    BOSS_MRS_CAULDRONS                      = 114522,

    // Opera Event Wikket
    BOSS_ELFYRA                             = 114284,
    BOSS_GALINDRE                           = 114251,

    // Upper Karazhan
    BOSS_CURATOR                            = 114462,
    BOSS_SHADE_OF_MEDIVH                    = 114350,
    BOSS_MANA_DEVOURER                      = 116494,
    BOSS_VIZADUUM                           = 114790,

    NPC_FEL_CANNON                          = 115274,
    NPC_COMMAND_SHIP                        = 114913,

    // Nighbane
    BOSS_NIGHTBANE                          = 114895,
    NPC_IMAGE_OF_MEDIVH                     = 115038

};

enum NKARAGameObjectsIds
{
    GO_OPERA_RIGHT_DOOR                     = 259702,
    GO_MEDIVH_DOOR                          = 266846,
    GO_MEDIVH_BOOK_DOOR                     = 266510,
    GO_STRANGE_WALL                         = 266508,
    GO_DOOR_BIBLIOTEK                       = 255455,
};

// Opera Events
constexpr uint8 OPERA_EVENT_WIKKET          = 1;
constexpr uint8 OPERA_EVENT_BEATIFUL_BEAST  = 2;
constexpr uint8 OPERA_EVENT_WESTFALL_STORY  = 3;

using SpellTargets = std::list<WorldObject*>;

#endif
