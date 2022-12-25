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

#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellPackets.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "PhasingHandler.h"
#include "Position.h"
#include "QuestDef.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"

enum ValarjarEmotes
{
    ONE_SHOT_TALK = 1,
    ONE_SHOT_LAUGH = 11,
    ONE_SHOT_ROAR = 15,
    ONE_SHOT_SHOT = 22,
    ONE_SHOT_POINT = 25,
    ONE_SHOT_SALUTE = 66,
    ONE_SHOT_CHEER_NO_SHEATHE = 71,
    ONE_SHOT_EAT_NO_SHEATHE = 92,
    ONE_SHOT_LAUGH_NO_SHEATHE = 153,
    ONE_SHOT_NO = 274
};
enum ValarjarSpells
{
    SPELL_EMOTE_BELCH = 65937,
    SPELL_WARRIOR_ORDER_FORMATION_SCENE = 193709,
    SPELL_CANCEL_COMPLETE_SCENE_WARRIOR_ORDER_FORMATION = 193711,
    PLAYER_CHOICE_WARRIOR_SELECTION = 236,
    SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE = 197999,
    ACTION_RESPONSEID_1 = 232, //Arms
    ACTION_RESPONSEID_2 = 233, //Fury
    ACTION_RESPONSEID_3 = 234, //Protection
    SPELL_1 = 192191,//SPELL_EFFECT_CREATE_GARRISON SPELL_EFFECT_QUEST_COMPLETE  38894 SPELL_EFFECT_DISCOVER_TAXI 1774

};
enum Phases
{
    PHASE_CLASS_WARRIOR_HORDE = 7300,
    PHASE_CLASS_WARRIOR_ALIANCE = 7302,

    PHASE_ODYN = 5107,
    PHASE_DANICA = 5090
};

enum Quests
{
    QUEST_H_A_DESPERATE_PLEA = 41052,
    QUEST_H_RETURN_TO_THE_BROKEN_SHORE = 38904,
    QUEST_A_RETURN_TO_THE_BROKEN_SHORE = 42815,

    QUEST_A_AN_IMPORTANT_MISSION = 42814,

    QUEST_ODYN_AND_THE_VALARJAR = 39654,
    QUEST_WEAPONS_OF_LEGEND = 40579,
    QUEST_ONE_MORE_LEGEND = 44417,
    QUEST_MORE_WEAPONS_OF_LEGEND = 43949,
    QUEST_ARMS_CHOSEN = 40582,
    QUEST_THE_SWORD_OF_KINGS = 41105,
    QUEST_FURY_CHOSEN = 40581,
    QUEST_THE_HUNTER_OF_HEROES = 40043,
    QUEST_PROT_CHOSEN = 40580,
    QUEST_LEGACY_OF_THE_ICEBREAKER = 39191,

};

enum Creatures
{
    NPC_EITRIGG_93775 = 93775,
    NPC_SERGEANT_DALTON_108961 = 108961,

    NPC_KILL_CREDIT_FOLLOWED_DANICA = 103036,
    NPC_DANICA_THE_RECLAIMER = 93823,
    NPC_KILL_CREDIT_ARRIVED_AT_ODYN = 96532
};
enum Items
{
    ITEM_MONSTER_ITEM_MUTTON_WITH_BITE = 2202,
    ITEM_MONSTER_ITEM_TANKARD_WOODEN = 2703,
    ITEM_HOV_2H_AXE = 137176,
    ITEM_HOV_1H_SWORD = 137263,
    ITEM_HOV_SHIELD_2 = 137265
};

void AddSC_class_hall_warrior()
{

}
