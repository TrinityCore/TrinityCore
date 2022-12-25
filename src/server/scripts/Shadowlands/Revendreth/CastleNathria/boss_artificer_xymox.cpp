/*
* Copyright (C) 2021 AzgathCore
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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "SpellAuraEffects.h"
#include "castle_nathria.h"

enum Spells
{
    SPELL_DIMENSIONAL_TEAR_CAST = 328437,
    SPELL_DIMENSIONAL_TEAR_DEBUFF = 328448,
    SPELL_DIMENSIONAL_TEAR_EXP = 328545,
    SPELL_WORMHOLE_A_SUMMON = 328308, //168726
    SPELL_WORMHOLE_B_SUMMON = 328312, //168730
    SPELL_GLYPH_OF_DESTRUCTION = 325361,
    SPELL_GLYPH_OF_DESTRUCTION_PERIODIC = 325236,
    SPELL_GLYPH_OF_DESTRUCTION_EXP = 325324,
    SPELL_RIFT_BLAST_CAST = 335013,
    SPELL_RIFT_BLAST_DAMAGE = 329256, //169271
    SPELL_RIFT_BLAST_SUMMON = 329459,
    SPELL_HYPERLIGHT_SPARK = 325399,
    SPELL_CRYSTAL_OF_PHANTASM = 327887,
    SPELL_POSSESION = 327414,
    SPELL_SOUL_SINGE = 340824,
    //Phase 2
    SPELL_ROOT_OF_EXTINCTION_CAST = 329770,
    SPELL_ROOT_OF_EXTINCTION_VISUAL = 329243,
    SPELL_ROOT_OF_EXTINCTION_CREATE_AT = 329982, //1697 explode on create after 18s
    SPELL_SEED_OF_EXTINCTION_BUTTON = 329090,
    SPELL_SEED_OF_EXTINCTION_CAST = 329834,
    SPELL_SEED_OF_EXTINCTION_EXP = 329107,
    SPELL_WITHERING_TOUCH_MISSILE = 340854,
    SPELL_WITHERING_TOUCH_PERIODIC_DAMAGE = 340860,
    //Phase 3
    SPELL_EDGE_OF_ANNIHILATION_CAST = 328880,
    SPELL_EDGE_OF_ANNIHILATION_VISUAL = 258832,
    SPELL_EDGE_OF_ANNIHILATION_KNOCKBACK = 329613,
    EVENT_EDGE_OF_ANNIHILATION_DRAG = 1, // every 35s, 45s
    SPELL_AURA_OF_DREAD = 340870,
    //Heroic
    SPELL_STASIS_TRAP_CAST = 326271,
    SPELL_STASIS_TRAP_TRIGGER = 326272,
    SPELL_STASIS_TRAP_CREATE_AT = 326275, //20168
    SPELL_STASIS_TRAP_STUN = 326302,
    //Mythic
};

void AddSC_boss_artificer_xymox()
{
    
}