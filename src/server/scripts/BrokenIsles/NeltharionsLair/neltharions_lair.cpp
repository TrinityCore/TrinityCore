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

#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "neltharions_lair.h"
#include "CreatureTextMgr.h"

enum Misc
{
    TAXI_NODE_FALLING_START_POINT = 1911,
    TAXI_NODE_FALLING_END_POINT = 1910,
    TAXI_NODE_BARREL_START_POINT = 1909,
    TAXI_NODE_BARREL_END_POINT = 1908,

    NPC_UNDERSTONE_DRUDGE = 92350,
};

enum eSpellsInstance
{
    SPELL_FALLING_VISUAL = 209888,
};

void AddSC_neltharions_lair()
{
   
}
