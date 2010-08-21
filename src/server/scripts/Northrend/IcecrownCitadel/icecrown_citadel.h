/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef DEF_ICECROWN_CITADEL_H
#define DEF_ICECROWN_CITADEL_H

enum eSharedSpells
{
    SPELL_BERSERK   = 26662
};

enum eData
{
    DATA_LORD_MARROWGAR         = 0,
    DATA_LADY_DEATHWHISPER      = 1,
    DATA_GUNSHIP_EVENT          = 2,
    DATA_DEATHBRINGER_SAURFANG  = 3,
    DATA_FESTERGUT              = 4,
    DATA_ROTFACE                = 5,
    DATA_PROFESSOR_PUTRICIDE    = 6,
    DATA_BLOOD_PRINCE_COUNCIL   = 7,
    DATA_BLOOD_QUEEN_LANA_THEL  = 8,
    DATA_VALITHRIA_DREAMWALKER  = 9,
    DATA_SINDRAGOSA             = 10,
    DATA_THE_LICH_KING          = 11,

    COMMAND_FAIL_BONED,
    DATA_SAURFANG_EVENT_NPC,
    DATA_SAURFANG_DOOR,
};

#define MAX_ENCOUNTER 12

enum eCreatures
{
    NPC_LORD_MARROWGAR              = 36612,
    NPC_COLDFLAME                   = 36672,
    NPC_BONE_SPIKE                  = 36619,

    NPC_LADY_DEATHWHISPER           = 36855,
    NPC_CULT_FANATIC                = 37890,
    NPC_DEFORMED_FANATIC            = 38135,
    NPC_REANIMATED_FANATIC          = 38009,
    NPC_CULT_ADHERENT               = 37949,
    NPC_EMPOWERED_ADHERENT          = 38136,
    NPC_REANIMATED_ADHERENT         = 38010,
    NPC_VENGEFUL_SHADE              = 38222,

    NPC_DEATHBRINGER_SAURFANG       = 37813,
    NPC_BLOOD_BEAST                 = 38508,
    NPC_SE_JAINA_PROUDMOORE         = 37188,    // SE means Saurfang Event
    NPC_SE_MURADIN_BRONZEBEARD      = 37200,
    NPC_SE_KING_VARIAN_WRYNN        = 37879,
    NPC_SE_HIGH_OVERLORD_SAURFANG   = 37187,
    NPC_SE_KOR_KRON_REAVER          = 37920,
    NPC_SE_SKYBREAKER_MARINE        = 37830,
};

enum eGameobjects
{
    DOODAD_ICECROWN_ICEWALL02       = 201910,
    ICEWALL                         = 201911,
    LORD_MARROWGAR_S_ENTRANCE       = 201857,
    ORATORY_OF_THE_DAMNED_ENTRANCE  = 201563,
    LADY_DEATHWHISPER_ELEVATOR      = 202220,
    SAURFANG_S_DOOR                 = 201825,
    DEATHBRINGER_S_CACHE_10N        = 202239,
    DEATHBRINGER_S_CACHE_25N        = 202240,
    DEATHBRINGER_S_CACHE_10H        = 202238,
    DEATHBRINGER_S_CACHE_25H        = 202241,
};

enum eAchievementCriteria
{
    CRITERIA_BONED_10N  = 12775,
    CRITERIA_BONED_25N  = 12962,
    CRITERIA_BONED_10H  = 13393,
    CRITERIA_BONED_25H  = 13394,
};

#endif // DEF_ICECROWN_CITADEL_H
