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
#include "waycrest_manor.h"
#include "SpellAuras.h"
#include "SpellScript.h"

enum Spells
{
	CLAIM_THE_IRIS = 260852,
	IRONBARK_SHIELD = 261265, //briar
	RUNIC_MARK = 261266, //malady
	//BRIAR
	BRAMBLE_BOLT = 260701,
	JAGGED_NEATTLES = 260741,
	AURA_OF_THORNS = 268122,
	//MALADY
	RUINOUS_BOLT = 260700,
	UNSTABLE_RUNIC_MARK = 260703,
	UNSTABLE_RUNIC_MARK_EXP = 260702,
	AURA_OF_DREAD = 268088,
	AURA_OF_DREAD_DEBUFF = 268086,
	//SOLENA
	SOUL_BOLT = 260699,
	SOUL_MANIPULATION = 260907,
	SOUL_CHANNELED = 260926,
	SOUL_MANIPULATION_AURA = 260900,
	SOUL_MANIPULATION_REDUCE_DAMAGE = 260923,
	AURA_OF_APATHY = 268077,
	AURA_OF_APATHY_DEBUFF = 268080,
	//FOCUSING IRIS
	FOCUSING_IRIS = 260805,
	DIRE_RITUAL = 260773,
};

enum Events
{
	EVENT_BRAMBLE_BOLT = 1,
	EVENT_JAGGED_NEATTLES,
	EVENT_RUINOUS_BOLT,
	EVENT_UNSTABLE_RUNIC_MARK,
	EVENT_SOUL_BOLT,
	EVENT_SOUL_MANIPULATION,
	EVENT_DIRE_RITUAL,
	EVENT_FOCUSING_IRIS,
	EVENT_RESET_IRIS,
	EVENT_AURA_OF_APATHY,
	EVENT_AURA_OF_THORNS,
	EVENT_AURA_OF_DREAD,
};

enum Texts
{
	SAY_SOLENA_AGGRO = 7,
	SAY_PASSING_IRIS_SOLENA = 1,
	SAY_PASSING_IRIS_BRIAR = 0,
	SAY_PASSING_IRIS_MALADY = 1,
	SAY_MALADY_ABILITY = 2,
	SAY_BRIAR_ABILITY = 2,
	SAY_SOLENA_SOUL_MANIP = 0,
	SAY_DEATH_SOLENA = 6,
	SAY_DEATH_BRIAR = 5,
	SAY_DEATH_MALADY = 5,
	SAY_WARNING_DIRE_RITUAL = 3,
	SAY_DIRE_RITUAL_SOLENA = 4,
	SAY_THORN_AURA_BRIAR = 1,
	SAY_DREAD_AURA_MALADY = 0,
	SAY_KILL_MALADY = 3,
	SAY_KILL_SOLENA = 5,
	SAY_KILL_BRIAR = 3,
	//OUTRO//
	//Inquisitor Yorrick says : I can rest more easily knowing these foul creatures no longer prowl the night.
	//Inquisitor Yorrick says : Continue your hunt for Lady Waycrest.I will ensure these rooms are clear.
};

void AddSC_boss_heartsbane_triad()
{
	
}
