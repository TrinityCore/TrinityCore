/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2016-2019 MagicStorm
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

#ifndef TrialOfValor_H__
#define TrialOfValor_H__

#define DataHeader "TOV"
#define TrialOfValorScriptName "instance_trial_of_valor"

#include "InstanceScript.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "Player.h"
#include "Unit.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "GameObject.h"

#include <G3D/Quat.h>

uint32 const EncounterCount = 5;

enum DataTypes
{
    DATA_HYMDALL,
    DATA_HYRJA,
    DATA_ODYN,
    DATA_GUARM,
    DATA_HELYA,

    ENCOUNTER_COUNT,
};

enum CreaturesIds
{
    BOSS_HYMDALL = 114361,
    BOSS_HYRJA = 114360,
    BOSS_ODYN = 114263,
    BOSS_GUARM = 114323,
    BOSS_HELYA = 114537,

    NPC_VALARJAR_RUNEBEARER = 114996,

    NPC_GRIPPING_TENTACLE = 114900,
    NPC_DECAYING = 114568,
    NPC_NIGHT_WATCH_MARINER = 114812,
    NPC_GRIMELORD = 114709,
    NPC_BILEWATER_SLIME = 116195,
    NPC_ORB_OF_CORRUPTION = 115166,
    NPC_ORB_OF_CORROSION = 114535,
    NPC_KVALDIR_LONGBOAT = 115941,
};

enum GameObjectsId
{
    GO_VALARJAR_RUNE_GREEN = 245699,
    GO_VALARJAR_RUNE_BLUE = 245696,
    GO_VALARJAR_RUNE_YELLOW = 245695,
    GO_VALARJAR_RUNE_ORANGE = 245697,
    GO_VALARJAR_RUNE_PURPLE = 245698,

    GO_RITUAL_STONE = 265596,

    GO_GUARM_DOOR_HALYA = 266533,

    GO_DOOR_BRIDGE = 244664,
};

enum CommonBossSpells
{
    SPELL_VALARJARS_BOND = 228018,
    SPELL_REVIVIFY = 228171,
};

template<class AI>
CreatureAI* GetTrialOfValorAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, TrialOfValorScriptName);
}

#endif
