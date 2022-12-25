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
#include "Creature.h"
#include "CreatureAI.h"
#include "Unit.h"
#include "UnitAI.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "PhasingHandler.h"
#include "battle_of_dazaralor.h"

enum Spells
{
    SPELL_BIND_SOULS = 284276,
    SPELL_SCORCHING_DETONATION_DUMMY_DAMAGE_AURA = 284831, //289915
    SPELL_SCORCHING_DETONATION_EXPLOSION = 284846,
    SPELL_PLAGUE_TOADS_CAST = 284933,
    SPELL_PLAGUE_OF_FIRE_CAST = 285346,
    SPELL_PLAGUE_OF_FIRE_AURA = 285349,
    SPELL_PLAGUE_OF_FIRE_MISSILE = 285347,
    SPELL_ZOMBIE_DUST_TOTEM_SUMMON = 285003, //npc 146731
    SPELL_ZOMBIE_DUST_MIND_CONTROL = 284995,
    SPELL_DEATHS_PRESENCE = 284376,
    SPELL_DREAD_REAPING_CREATE_AT = 287116,
    SPELL_DREAD_REAPING_AT_DAMAGE = 287147,
    SPELL_DREAD_REAPING_PORTAL_VISUAL = 287109,
    SPELL_INEVITABLE_END_PULL_CREATE_AT = 287333,
    SPELL_INEVITABLE_END_INSTAKILL = 288576,
    SPELL_UNLIVING_PASSIVE = 284377,    
    SPELL_AURA_OF_DEATH_MAIN = 289924,
    SPELL_AURA_OF_DEATH = 285190,
    SPELL_CARESS_OF_DEATH = 285213,
    SPELL_DEATHS_DOOR_DEBUFF = 288449,
    SPELL_DEATH_RIFT_CREATE_AT = 288048, // 148351, at custom 40019
    SPELL_BWONSAMDIS_BOON = 284446,
    SPELL_BWONSAMDIS_BOON_BUFF = 289169, // script on apply, ever 15s addstack
    SPELL_WITHERING_BURST_DAMAGE = 288053,
    SPELL_UNDYING_RELENTLESSNESS = 289162,    
    SPELL_ALL_ENCOMPASSING_DEATH = 289890,
    SPELL_SPIRIT_EXPULSION = 284521,
    SPELL_DEATHLY_WITHERING = 285195,
    SPELL_SEAL_OF_BWONSAMDI_MISSILE = 286669,
    SPELL_SEAL_OF_BWONSAMDI_CREATE_AT = 286664,
    SPELL_SEAL_OF_BWONSAMDI_DAMAGE = 286671, //script on hit
    SPELL_BWONSAMDIS_WRATH = 286672, 
    SPELL_PLAGUE_OF_TOAD_JUMP = 284917,
    SPELL_PLAGUE_OF_TOAD_CREATE_AT = 284918,
    SPELL_PLAGUE_OF_TOAD_PERSONAL_AT = 285041,
    SPELL_TOAD_TOXIN = 285044,
    //Heroic
    SPELL_GRIEVOUS_AXE = 290955,
    SPELL_GREATER_SERPENT_TOTEM_SUMMON = 285172, //146766
    SPELL_SERPENTS_BREATH = 285178,
    SPELL_POISON_TOAD_SLIME_AT_DAMAGE = 285010, // used for toads
    //Mythic
    SPELL_FOCUSED_DEMISE = 286779,
};

enum ACtions
{
    ACTION_PHASE_TWO = 1,
    ACTION_PHASE_THREE,
    ACTION_PHASE_FOUR
};

enum MiniBosses
{
    SPELL_CRUSHING_LEAP_JUMP = 284719,
    SPELL_CRUSHING_LEAP_DAMAGE = 284730,
    SPELL_METEOR_LEAP = 284686,
    SPELL_METEOR_LEAP_DAMAGE = 284688,
    SPELL_CRUSHED = 289858,
    SEAL_OF_PURIFICATION_CREATE_AT = 286537,
    SPELL_SEAL_OF_PURIFICATION_DAMAGE = 290448,
};

void AddSC_boss_king_rastakhan()
{
   
}
