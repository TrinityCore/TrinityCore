/*
* Copyright 2023 AzgathCore
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

#include "GameObjectAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "GridNotifiers.h"
#include "fall_of_theramore_horde.h"

// Misc Spells
enum eSpells
{
    SPELL_RIG_THIS_POWDER_BARREL = 37338,
    SPELL_RIG_TO_EXPLODE = 111260,
    SPELL_SUMMON_SABOTAGED_TANK = 111657,

    // Big Bessa
    SPELL_BIG_BESSA_CANNON_SHOT = 114568,

    // Thalen Songweaver
    SPELL_PORTAL_ORGRIMMAR = 111633,
};

enum eTalks
{
    TALK_INTRO,
    TALK_SPECIAL_1,
    TALK_SPECIAL_2,
    TALK_SPECIAL_3,
    TALK_SPECIAL_4,
    TALK_SPECIAL_5,
};

void AddSC_fall_of_theramore_horde_scenario()
{
    
}