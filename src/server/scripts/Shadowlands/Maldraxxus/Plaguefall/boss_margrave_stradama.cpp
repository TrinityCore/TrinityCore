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
#include "Player.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuras.h"
#include "plaguefall.h"

enum Spells
{
    SPELL_PLAGUE_ROT_CAST = 322491,
    SPELL_PLAGUE_ROT_PERIODIC = 322492,
    SPELL_INFECTION_RAIN = 322232,
    SPELL_PLAGUE_CRASH_MAIN_LAND = 322475,
    EVENT_PLAGUE_CRASH_END = 1,
};

void AddSC_boss_margrave_stradama()
{
    
}
