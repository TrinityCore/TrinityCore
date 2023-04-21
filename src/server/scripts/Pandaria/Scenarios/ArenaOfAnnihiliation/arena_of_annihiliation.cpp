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

#include "arena_of_annihiliation.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "CreatureAI.h"
#include "MoveSplineInit.h"
#include "SpellScript.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_DIZZY = 123930,
    SPELL_ANGRY = 123936,
    SPELL_HEADBUTT = 123931,
    SPELL_FLAMELINE_AREA = 123959,
    SPELL_GROWTH = 122213,
    SPELL_TRAILBLAZE = 123971,
    SPELL_FLYING_SERPENT_KICK_EFF = 127807,
};

void AddSC_arena_of_annihiliation()
{
    
}