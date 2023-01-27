/*
* Copyright 2021 FuzionCore Project
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

/* Script Data Start
SDName: 
SDAuthor: Frozen
SD%Complete: %
SDComment: still working on structure.
Script Data End */

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
//#include "zone_the_maw"
#include "zone_Sanctum_of_Domination.h"

enum Loot
{
	Ancient_Anima_Vessel    = 186201,
	Self-Replicating_Tissue = 186374,
	Adaptive_Armor_Fragment = 187507,
	Salvaged_Fusion_Amplifier = 186432,
	Shard_of_Cor = 187063,
	Shard_of_Zed = 187079,
	Shard_of_Bek = 187057,
	Echoing_Call = 183132,
	Shard_of_Oth = 187076,
   Enigmatic_Energy_Circuit = 186284,
   Layered_Mane = 183487,
   Shard_of_Dyz = 187073,
   Shard_of_Jas = 187059,
   Sandals_of_Sacred_Symmetry = 186354,
   Shard_of_Kyr = 187065,
   Shard_of_Tel = 187071,
   Ancient_Colossus_Chassis = 186347,
   Unstable_Energizer_Boots = 186363,
   Disintegration-Proof_Waistband = 186317,
   Heavy_Rainfall = 182145,
   Torch_of_Eternal_Knowledge = 186393,
   Shielding_Words = 182307,
   Hyperdense_Greaves = 186344,
   Infinitys_Last_Bulwark = 186416,
   Tempest_Barrier = 181769,
   Insatiable_Appetite = 182133,
   Hack_and_Slash = 181735,
   Move_with_Grace = 181827,
   Poisoned_Katar = 183503,
   Directional_Meltdown_Projector = 186413,
   Reactive_Defense_Matrix = 186433,
   Resplendent_Mist = 181505,
   Pylon_of_the_Great_Purge = 186409,
   Vantus_Rune_Technique: Sanctum_of_Domination = 186671,
};

enum Spells
{
	Disintegration          = 352833,
	Form_Sentry             = 352660,
	Meerahs_Jukebox         = 288865,
	Obliterate_355352       = 355352,
	Obliterate_358619       = 358619,
	Purging_Protocol_350534 = 350534,
	Purging_Protocol_352538 = 352538,
	Shattered_Psyche        = 344663,
	Sunder                  = 350732,
	Threat_Neutralization   = 356090
};

enum Creatures
{
    NPC_Guardian_of_the_First_Ones = 175731,
};

enum Currencies
{
   Stygian_Ember = 1977,
   Renown = 1822,
   Deaths_Advance = 1907,
   Cosmic_Flux = 2009,
};

struct NPC_Guardian_of_the_First_Ones : public CreatureAI
{
	NPC_Guardian_of_the_First_Ones(Creature* Creature) : CreatureData (Data_NPC_Guardian_of_the_First_Ones) { }


}

void AddSC_Boss_Guardian_of_the_First_Ones();
{
	AddSC_Boss_Guardian_of_the_First_Ones();
}