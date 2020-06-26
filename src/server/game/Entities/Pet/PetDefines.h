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

#ifndef TRINITYCORE_PET_DEFINES_H
#define TRINITYCORE_PET_DEFINES_H

enum PetType
{
    SUMMON_PET              = 0,
    HUNTER_PET              = 1,
    MAX_PET_TYPE            = 4
};

#define MAX_PET_STABLES 20

// stored in character_pet.slot
enum PetSaveMode
{
    PET_SAVE_AS_DELETED        = -1,  // removes pet from DB and erases from playerPetDataStore
    PET_SAVE_UPADTE_SLOT       =  0,  // not used yet
    PET_SAVE_CURRENT_STATE     =  1,  // Saves everything like it is atm, current = true
    PET_SAVE_DISMISS           =  2,  // Saves everything like it is atm, removes auras and current = false
    PET_SAVE_LOGOUT            =  3,  // Saves everything like it is atm, removes auras and current = true
    PET_SAVE_NEW_PET           =  4,   // Saves everything like it is atm, current = true and pushes new into playerPetDataStore
    PET_SAVE_TEMP_UNSUMMON = PET_SAVE_LOGOUT
};

enum PetStableSlot
{
    PET_SLOT_FIRST             = 0,
    PET_SLOT_LAST              = 20,
    PET_SLOT_FIRST_ACTIVE_SLOT = PET_SLOT_FIRST,
    PET_SLOT_LAST_ACTIVE_SLOT  = 4,
    PET_SLOT_FIRST_STABLE_SLOT = 5,
    PET_SLOT_LAST_STABLE_SLOT  = PET_SLOT_LAST
};

enum PetSpellState
{
    PETSPELL_UNCHANGED = 0,
    PETSPELL_CHANGED   = 1,
    PETSPELL_NEW       = 2,
    PETSPELL_REMOVED   = 3
};

enum PetSpellType
{
    PETSPELL_NORMAL = 0,
    PETSPELL_FAMILY = 1,
    PETSPELL_TALENT = 2
};

enum ActionFeedback
{
    FEEDBACK_NONE            = 0,
    FEEDBACK_PET_DEAD        = 1,
    FEEDBACK_NOTHING_TO_ATT  = 2,
    FEEDBACK_CANT_ATT_TARGET = 3
};

enum PetTalk
{
    PET_TALK_SPECIAL_SPELL  = 0,
    PET_TALK_ATTACK         = 1
};

// Used by companions (minipets) and quest slot summons
constexpr float DEFAULT_FOLLOW_DISTANCE = 2.5f;
constexpr float DEFAULT_FOLLOW_DISTANCE_PET = 3.f;
constexpr float DEFAULT_FOLLOW_ANGLE = float(M_PI);

#endif
