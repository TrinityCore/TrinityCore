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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "atal_dazar.h"

enum PriestessAlunzaSpells : uint32
{
    SPELL_PRE_RITUAL                    = 258386,

    SPELL_ENERGY_REGEN                  = 258681,
    SPELL_GILDED_CLAWS                  = 255579,
    SPELL_GILDED_CLAWS_TRIGGER_SPELL    = 255581,
    SPELL_TRANSFUSION                   = 260666,
    SPELL_TRANSFUSION_PERIODIC_DUMMY    = 255577,
    SPELL_TRANSFUSION_DAMAGE            = 255836,
    SPELL_TRANSFUSION_DAMAGE_MYTHIC     = 260667,
    SPELL_TRANSFUSION_HEAL              = 255835,
    SPELL_TRANSFUSION_HEAL_MYTHIC       = 260668,
    SPELL_TAINTED_BLOOD_DOT             = 255558,
    SPELL_TAINTED_BLOOD_TARGET_CAULDRON = 255592,
    SPELL_TAINTED_BLOOD_MISSILE_BUBBLE  = 260660, // TARGET_DEST_DEST
    SPELL_TAINTED_BLOOD_CREATE_AT       = 260670,//AT
    SPELL_TAINTED_BLOOD_DAMAGE          = 255842,
    SPELL_TAINTED_BLOOD_SPAWN           = 255619,

    SPELL_MOLTEN_GOLD_POOL_PRE_SELECTOR = 255615,
    SPELL_MOLTEN_GOLD_POOL_SELECTOR     = 255591,
    SPELL_MOLTEN_GOLD_TARGET_SELECT     = 255584,
    SPELL_MOLTEN_GOLD_MISSILE           = 255583,
    SPELL_MOLTEN_GOLD_DOT               = 255582,

    SPELL_CORRUPTED_GOLD_TOUCH          = 258709,
    SPELL_CORRUPTED_GOLD_AT             = 258703,

    SPELL_SUMMON_SPIRIT_OF_GOLD         = 259205,
};

enum PriestessAlunzaTalks : uint8
{
    TALK_AGGRO              = 0,
    TALK_GILDED_CLAWS_EMOTE = 1,
    TALK_GILDED_CLAWS       = 2,
    TALK_TRANSFUSION_EMOTE  = 3,
    TALK_TRANSFUSION        = 4,
    TALK_MOLTEN_GOLD        = 5,
    TALK_DEATH              = 6
};

enum PriestessAlunzaEvents : uint8
{
    EVENT_GILDED_CLAWS = 1,
    EVENT_TRANSFUSION,
    EVENT_MOLTEN_GOLD,
    EVENT_TAINTED_BLOOD_CAST,
    EVENT_TAINTED_BLOOD,
    EVENT_SPAWN_CORRUPTED_GOLD,
    EVENT_SPIRIT_OF_GOLD,
};

enum PriestessAlunzaNPCs : uint32
{
    NPC_BLOOD_TAINTED_CAULDRON  = 128956,
    NPC_CORRUPTED_GOLD = 130738,
    NPC_SPIRIT_OF_GOLD = 131009,
};

enum Actions
{
    ACTION_SPIRIT_DIED = 0,
    ACTION_TAINTED_BLOOD,
};

enum PriestessMisc : uint32
{
    OUT_OF_COMBAT_ANIM_ID       = 1346
};

void AddSC_boss_priestess_alunza()
{
    
}
