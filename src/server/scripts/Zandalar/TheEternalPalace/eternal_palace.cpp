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

#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "eternal_palace.h"

enum
{
	SPELL_ARCANE_PROJECTION = 303674,
	SPELL_RAGE_OF_AZSHARA = 300997,
	SPELL_ASHVANES_ASCENSION = 302976,
};

const Position szalira_impact_pos = { 767.0f, 635.0f, 1289.0f, 0.62f };

void AddSC_eternal_palace()
{
	
}

