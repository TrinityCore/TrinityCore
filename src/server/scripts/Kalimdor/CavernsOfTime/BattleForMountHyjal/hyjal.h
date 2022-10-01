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

#ifndef DEF_HYJAL_H
#define DEF_HYJAL_H

#include "CreatureAIImpl.h"

#define HyjalScriptName "instance_hyjal"
#define DataHeader "HY"

uint32 const EncounterCount     = 5;

enum HYDataTypes
{
    DATA_RAGEWINTERCHILL        = 0,
    DATA_ANETHERON              = 1,
    DATA_KAZROGAL               = 2,
    DATA_AZGALOR                = 3,
    DATA_ARCHIMONDE             = 4,

    DATA_JAINAPROUDMOORE        = 5,
    DATA_THRALL                 = 6,
    DATA_TYRANDEWHISPERWIND     = 7,
    DATA_TRASH                  = 8,
    DATA_RESET_TRASH_COUNT      = 9,
    DATA_ALLIANCE_RETREAT       = 10,
    DATA_HORDE_RETREAT          = 11,
    DATA_RAIDDAMAGE             = 12,
    DATA_RESET_RAIDDAMAGE       = 13,
    TYPE_RETREAT                = 14,
    DATA_CHANNEL_TARGET         = 15
};

enum HYWorldStateIds
{
    WORLD_STATE_WAVES           = 2842,
    WORLD_STATE_ENEMY           = 2453,
    WORLD_STATE_ENEMYCOUNT      = 2454
};

enum HYCreaturesIds
{
    // Trash Mobs summoned in waves
    NECROMANCER                 = 17899,
    ABOMINATION                 = 17898,
    GHOUL                       = 17895,
    BANSHEE                     = 17905,
    CRYPT_FIEND                 = 17897,
    GARGOYLE                    = 17906,
    FROST_WYRM                  = 17907,
    GIANT_INFERNAL              = 17908,
    FEL_STALKER                 = 17916,

    JAINA                       = 17772,
    THRALL                      = 17852,
    TYRANDE                     = 17948,

    // Bosses summoned after every 8 waves
    RAGE_WINTERCHILL            = 17767,
    ANETHERON                   = 17808,
    KAZROGAL                    = 17888,
    AZGALOR                     = 17842,
    ARCHIMONDE                  = 17968,
    NPC_WORLD_TRIGGER_TINY      = 21987,
    NPC_CHANNEL_TARGET          = 22418
};

enum HYGameobjectIds
{
    GO_HORDE_ENCAMPMENT_PORTAL  = 182060,
    GO_NIGHT_ELF_VILLAGE_PORTAL = 182061,
    GO_ANCIENT_GEM              = 185557,
    GO_ANCIENT_VEIN             = 185557,
    GO_ROARING_FLAME            = 182592
};

#define MINRAIDDAMAGE 700000 // minimal damage before trash can drop loot and reputation, resets if faction leader dies

template <class AI, class T>
inline AI* GetHyjalAI(T* obj)
{
    return GetInstanceAI<AI>(obj, HyjalScriptName);
}

#endif
