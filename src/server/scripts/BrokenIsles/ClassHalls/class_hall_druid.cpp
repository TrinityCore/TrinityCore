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
#include "ScriptedCreature.h"
#include "Player.h"
#include "Creature.h"
#include "GameObject.h"
#include "SceneMgr.h"
#include "SceneHelper.h"
#include "ScriptedGossip.h"
#include "PhasingHandler.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Spell.h"
#include "GarrisonPackets.h"
#include "WorldSession.h"
#include "Garrison.h"
#include "LootMgr.h"

enum
{
    SPELL_TELEPORT_MOONGLADE = 18960,
    SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE = 199653,
    PLAYER_CHOICE_DRUID_SELECTION = 247,
    PLAYER_CHOICE_DRUID_BALANCE = 529,
    PLAYER_CHOICE_DRUID_FERAL = 530,
    PLAYER_CHOICE_DRUID_GUARDIAN = 531,
    PLAYER_CHOICE_DRUID_RESTORATION = 545,

    QUEST_GUARDIAN_CHOSEN = 40702,
    QUEST_RESTORATION_CHOSEN = 40703,
    QUEST_FERAL_CHOSEN = 40701,
    QUEST_BALANCE_CHOSEN = 40781,

    KILLED_MONSTER_CREDIT_40643 = 103346,
    QUEST_A_SUMMONS_FROM_MOONGLADE = 40643,
    QUEST_CALL_OF_THE_WILDS = 41106,
    QUEST_THE_DREAMWAY = 40644,
    QUEST_TO_THE_DREAMGROVE = 40645,
    QUEST_WEAPONS_OF_LEGEND = 40646,
    QUEST_ANOTHER_WEAPON_OF_OLD = 43980,
    QUEST_MORE_WEAPONS_OF_OLD = 44431,
    QUEST_WEAPONS_OF_THE_ANCIENTS = 44443,
    QUEST_SOWING_THE_SEED = 41255,
    QUEST_SOWING_THE_SEED_PHASE = 5685,
    QUEST_ASCENDING_THE_CIRCLE = 41332,
    QUEST_A_HEROS_WEAPON = 43409,
    ///GUARDIAN
    QUEST_MISTRESS_OF_THE_CLAW = 41468,
    QUEST_TO_THE_HILLS = 41782,
    QUEST_FALLEN_OFFERINGS = 41783,
    ///FERAL
    QUEST_THE_SHRINE_OF_ASHAMANE = 42428,
    NPC_DELANDROS_SHIMMERMOON_107392 = 107392,
    NPC_VERSTOK_DARKBOUGH_107520 = 107520,
    QUEST_AID_FOR_THE_ASHEN = 42439,
    QUEST_THE_SHRINE_IN_PERIL = 42440,
    NPC_ALGROMON_107593 = 107593,
    ///BALANCE
    QUEST_THE_SCYTHE_OF_ELUNE = 40783,
    QUEST_ITS_RIGHTFUL_PLACE = 40784,
    QUEST_A_FOE_OF_THE_DARK = 40785,
    QUEST_FOLLOWING_THE_CURSE = 40834,
    QUEST_DISTURBING_THE_PAST = 40835,
    QUEST_THE_DEADWIND_HUNT = 40837,
    QUEST_THE_DARK_RIDERS = 40838,
    NPC_NARALEX_103778 = 103778,
    ///RESTORATION
    QUEST_MEET_WITH_MYLUNE = 40649,
    QUEST_NECESSARY_PREPARATIONS = 41422,
    QUEST_JOIN_THE_DREAMER = 41449,
    QUEST_IN_DEEP_SLUMBER = 41436,
    PHASE_IN_DEEP_SLUMBER = 6053, //7541,
    QUEST_RECONVENE = 41690,
    QUEST_CLEANSING_THE_MOTHER_TREE = 41689,
    NPC_NARALEX_104349 = 104349,

    NPC_ARCHDRUID_HAMUUL_RUNETOTEM_101064 = 101064,
    NPC_KEEPER_REMULOS_101065 = 101065,

    NPC_KEEPER_REMULOS_103488 = 103488,
    NPC_KEEPER_REMULOS_103832 = 103832,

    SPELL_FADE = 206809,
};

void AddSC_class_hall_druid()
{
    
}
