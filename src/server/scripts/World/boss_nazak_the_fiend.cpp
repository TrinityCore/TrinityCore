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
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Creature.h"
#include "Player.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "ObjectAccessor.h"

enum eSpells
{
    SPELL_CORRODING_SPRAY = 219349, // 23
    SPELL_WEB_WRAP = 219861, // 42
    SPELL_FOUNDATIONAL_COLLAPSE = 219591, // 57 + cast. + script for crystalls
    SPELL_ABSORB_LEYSTONES = 219813, // after above. Script for stacks   
    SPELL_LEY_INFUSION = 219836,
};

void AddSC_boss_nazak_the_fiend()
{
    
}
