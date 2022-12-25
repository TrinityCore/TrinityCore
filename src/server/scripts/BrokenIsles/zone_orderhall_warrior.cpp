/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "Containers.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"

enum ValarjarSpells
{
    SPELL_EMOTE_BELCH                                   = 65937,
    SPELL_WARRIOR_ORDER_FORMATION_SCENE                 = 193709,
    SPELL_CANCEL_COMPLETE_SCENE_WARRIOR_ORDER_FORMATION = 193711
};

enum Phases
{
    PHASE_ODYN      = 5107,
    PHASE_DANICA    = 5090
};

enum Quests
{
    QUEST_ODYN_AND_THE_VALARJAR = 39654
};

enum Creatures
{
    NPC_KILL_CREDIT_FOLLOWED_DANICA = 103036,
    NPC_DANICA_THE_RECLAIMER        = 93823,
    NPC_KILL_CREDIT_ARRIVED_AT_ODYN = 96532
};

enum Items
{
    ITEM_MONSTER_ITEM_MUTTON_WITH_BITE  = 2202,
    ITEM_MONSTER_ITEM_TANKARD_WOODEN    = 2703,
    ITEM_HOV_2H_AXE                     = 137176,
    ITEM_HOV_1H_SWORD                   = 137263,
    ITEM_HOV_SHIELD_2                   = 137265
};

struct npc_danica_the_reclaimer : public ScriptedAI
{
    npc_danica_the_reclaimer(Creature* creature) : ScriptedAI(creature) { }

    Position const DanicaPath01[6] =
    {
        { 1050.219f, 7232.470f, 100.5846f },
        { 1046.207f, 7240.372f, 100.5846f },
        { 1040.963f, 7245.498f, 100.6819f },
        { 1034.726f, 7250.083f, 100.5846f },
        { 1027.422f, 7257.835f, 100.5846f },
        { 1027.542f, 7259.735f, 100.5846f }
    };

    using DanicaPath01Size = std::extent<decltype(DanicaPath01)>;

    Position const DanicaPath02[6] =
    {
        { 1018.493f, 7247.438f, 100.5846f },
        { 1013.535f, 7243.327f, 100.5846f },
        { 1007.063f, 7235.723f, 100.5846f },
        { 1003.337f, 7229.650f, 100.5846f },
        { 995.4549f, 7227.286f, 100.5846f },
        { 984.4410f, 7224.357f, 100.5846f }
    };

    using DanicaPath02Size = std::extent<decltype(DanicaPath02)>;

    Position const DanicaPath03[5] =
    {
        { 962.5208f, 7223.089f, 100.5846f },
        { 934.2795f, 7223.116f, 100.5846f },
        { 911.8507f, 7223.776f, 100.5846f },
        { 879.0139f, 7224.100f, 100.9079f },
        { 851.691f, 7224.5490f, 109.5846f }
    };

    using DanicaPath03Size = std::extent<decltype(DanicaPath03)>;

    enum Texts
    {
        SAY_FIRST_LINE  = 1,
        SAY_SECOND_LINE = 2,
        SAY_THIRD_LINE  = 3
    };

    enum Points
    {
        POINT_FORGE_OF_ODYN,
        POINT_INTRODUCE_MEAD_HALL,
        POINT_ODYN
    };
};

void AddSC_orderhall_warrior()
{
    
}
