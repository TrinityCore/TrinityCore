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

    COMMAND_FAIL_BONED
};

#define MAX_ENCOUNTER 12

enum eCreatures
{
    NPC_LORD_MARROWGAR      = 36612,
    NPC_COLDFLAME           = 36672,
    NPC_BONE_SPIKE          = 38711
};

enum eGameobjects
{
    DOODAD_ICECROWN_ICEWALL02   = 201910,
    ICEWALL                     = 201911,
    LORD_MARROWGAR_S_ENTRANCE   = 201857
};

enum eAchievementCriteria
{
    CRITERIA_BONED_10N  = 12775,
    CRITERIA_BONED_25N  = 12962,
    CRITERIA_BONED_10H  = 13393,
    CRITERIA_BONED_25H  = 13394,
};

#endif // DEF_ICECROWN_CITADEL_H
