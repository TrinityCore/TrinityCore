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

#include "ScriptMgr.h"
#include "AreaTriggerAI.h"

enum eSpells
{
    SPELL_TENTACLE_BASH = 213420,
    SPELL_SHATTER_CREWMEN = 213532,
    SPELL_CURSED_CREW = 213522,
  
    SPELL_MARAUDING_MISTS = 213665,
    SPELL_SEADOG_SCUTTLE_COST = 213580,
    SPELL_SEADOG_SCUTTLE = 213584,
    SPELL_SEADOG_SCUTTLE_TRIG = 213588,
   
    SPELL_TELEPORT = 215681,
    SPELL_EXPEL_SOUL = 213625,
    SPELL_SOUL_REND = 213605,
    SPELL_SOUL_REND_TRIG = 213638,

    SPELL_SHATTER_CREWMEN_ADD = 213533,
};

enum Bosses
{
    NPC_CAPITAN = 106981,
    NPC_YDORN = 106982,
    NPC_MEVRA = 106984,
};

uint32 const _Bosses[3]
{
    NPC_CAPITAN,
    NPC_YDORN,
    NPC_MEVRA
};

Position const tpPos[6] =
{
    {4930.69f, 489.92f, -53.34f, 2.71f},
    {4904.75f, 471.04f, -53.34f, 2.21f},
    {4863.42f, 449.40f, -53.34f, 1.36f},
    {4840.75f, 476.77f, -53.34f, 0.60f},
    {4820.06f, 510.35f, -53.34f, 0.11f},
    {4878.81f, 524.31f, -48.90f, 4.52f}
};

void AddSC_boss_the_soultakers()
{
    
}
