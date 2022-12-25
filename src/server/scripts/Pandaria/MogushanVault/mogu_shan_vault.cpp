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

#include "ScriptedCreature.h"
#include "mogu_shan_vault.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "CreatureAI.h"
#include "MoveSplineInit.h"

enum eSpells
{
    SPELL_SPIRIT_BOLT = 121224,
    SPELL_GROUND_SLAM = 121087,
    SPELL_PETRIFICATION = 125090,
    SPELL_PETRIFIED = 125092,
    SPELL_FULLY_PETRIFIED = 115877,
    SPELL_MONSTROUS_BITE = 125096,
    SPELL_SUNDERING_BITE = 116970,
    SPELL_PROTECTIVE_FENZY = 116982,
    SPELL_SHATTERING_STONE = 116977,
    SPELL_FOCUSED_ASSAULT = 116990,
    SPELL_POSE_1 = 120650,
    SPELL_POSE_2 = 120613,
    SPELL_STONE = 120663,
    SPELL_BRONZE = 120661,
    SPELL_GHOST_ESSENCE = 120764,
    SPELL_INACTIVE = 118205,
    SPELL_ACTIVATION_VISUAL = 118212,
    SPELL_CHARGED_SHADOWS = 117685,
    SPELL_SHADOW_BLAST = 119365,
    SPELL_ANNIHILATE = 119521,
    SPELL_COWARDICE = 119635,
    SPELL_VOLLEY = 119554,
    SPELL_TROLL_RUSH = 116006,
    SPELL_CRUSHING_ATTACKS = 119514,
    SPELL_SHOOT = 119524,
    SPELL_ENRAGE = 119629,
    SPELL_REFLECTIVE_SHIELDS = 119630,
    SPELL_FLESH_TO_STONE = 118552,
    SPELL_STONE_BLOCK = 118529,
    SPELL_FORCEFUL_SWING = 126955,
    SPELL_TOUCH_OF_NALAK_SHA = 126958,
    SPELL_WARDEN_S_FURY = 126970,
    SPELL_ENHANCED_RECONSTRUCTION = 126980,
    SPELL_RECONSTRUCTING = 126985
};

enum eEvents
{
    EVENT_CURSED_MOGU_SPIRIT_BOLT,
    EVENT_CURSED_MOGU_GROUND_SLAM,
    EVENT_CURSED_MOGU_ATTACK,
    EVENT_ENORMOUS_QUILEN_BITE,
    EVENT_QUILEN_SUNDERING_BITE,
    EVENT_QUILEN_SHATTERING_STONE,
    EVENT_QUILEN_FOCUSED_ASSAULT,
    EVENT_ZANDALARI_TROLL_RUSH,
    EVENT_ZIAN_CHARGED_SHADOWS,
    EVENT_SORCERER_SHADOW_BLAST,
    EVENT_QIANG_ANNIHILATE,
    EVENT_QIANG_START_SECOND_FIGHT,
    EVENT_MOUNTED_MOGU_CRUSHING_ATTACKS,
    EVENT_SUBETAI_VOLLEY,
    EVENT_SUBETAI_START_THIRD_COMBAT,
    EVENT_MOGU_ARCHER_SHOOT,
    EVENT_MENG_START_FOURTH_COMBAT,
    EVENT_MENG_COWARDICE,
    EVENT_KINGS_GUARD_ENRAGE,
    EVENT_KINGS_GUARD_REFLECTIVE_SHIELDS,
    EVENT_SECRET_FLESH_TO_STONE,
    EVENT_SECRET_STONE_BLOCK,
    EVENT_WARDEN_FORCEFUL_SWING,
    EVENT_WARDEN_TOUCH_OF_NALAK_SHA,
    EVENT_WARDEN_WARDEN_S_FURY,
    EVENT_KEEPER_ENHANCED_RECONSTRUCTION,
    EVENT_KEEPER_RECONSTRUCTING
};

enum eEquipIds
{
    EQUIP_ZIAN_STAFF = 76369,
    EQUIP_QIANG_POLEARM = 86777,
    EQUIP_MOUNTED_MOGU_WEAPON = 80132,
    EQUIP_SUBETAI_SWORD = 80283,
    EQUIP_SUBETAI_BOW = 60790
};

enum eTrashsActions
{
    ACTION_CURSED_MOGU_ATTACK_PLAYER = 1
};

void StartNextFight(uint32 p_PreviousAdd, uint32 p_NextAdd, uint32 p_PreviousBoss, uint32 p_NextBoss, uint32 p_Action, uint32 /*p_NextAction*/, Creature* me)
{
    std::list<Creature*> l_CreatureList;
    me->GetCreatureListWithEntryInGrid(l_CreatureList, p_PreviousAdd, 200.0f);

    for (Creature* l_Creature : l_CreatureList)
    {
        if (l_Creature->IsAlive() && l_Creature == me)
            return;
    }

    me->AI()->DoAction(p_Action);

    if (Creature* l_Boss = GetClosestCreatureWithEntry(me, p_PreviousBoss, 200.0f))
    {
        if (l_Boss->GetAI())
            l_Boss->AI()->DoAction(p_Action);
    }

    l_CreatureList.clear();
    me->GetCreatureListWithEntryInGrid(l_CreatureList, p_NextAdd, 200.0f);

    for (Creature* l_Creature : l_CreatureList)
        l_Creature->AI()->DoAction(ACTION_BEFORE_COMBAT);

    if (Creature* l_Boss = GetClosestCreatureWithEntry(me, p_NextBoss, 200.0f))
    {
        if (l_Boss->GetAI())
            l_Boss->AI()->DoAction(ACTION_BEFORE_COMBAT);
    }
}

void AddSC_mogu_shan_vault()
{
    
}
