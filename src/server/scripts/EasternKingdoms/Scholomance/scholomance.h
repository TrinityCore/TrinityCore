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

#ifndef DEF_SCHOLOMANCE_H
#define DEF_SCHOLOMANCE_H

#include "CreatureAIImpl.h"

#define ScholomanceScriptName "instance_scholomance"
#define DataHeader "SC"

uint32 const EncounterCount = 8;

enum SCDataTypes
{
    DATA_DOCTORTHEOLENKRASTINOV = 0,
    DATA_INSTRUCTORMALICIA = 1,
    DATA_LADYILLUCIABAROV = 2,
    DATA_LORDALEXEIBAROV = 3,
    DATA_LOREKEEPERPOLKELT = 4,
    DATA_THERAVENIAN = 5,
    DATA_DARKMASTERGANDLING = 6,
    DATA_KIRTONOS = 7,
    DATA_RAS_FROSTWHISPER = 8,
};

enum SCCreatureIds
{
    NPC_DARKMASTER_GANDLING = 1853,
    NPC_BONE_MINION = 16119
};

enum SCGameobjectIds
{
    GO_GATE_KIRTONOS = 175570,
    GO_GATE_GANDLING = 177374,
    GO_GATE_RAVENIAN = 177372,
    GO_GATE_THEOLEN = 177377,
    GO_GATE_ILLUCIA = 177371,
    GO_GATE_MALICIA = 177375,
    GO_GATE_BAROV = 177373,
    GO_GATE_POLKELT = 177376,
    GO_BRAZIER_OF_THE_HERALD = 175564,

    GO_GATE_RAS_FROSTWHISPER = 177370
};

// EJ scripts
enum SCHOLOMANCE_NPC
{
    NPC_SHADOWED_SPIRIT = 14511,
    NPC_CORRUPTED_SPIRIT = 14512,
    NPC_MALICIOUS_SPIRIT = 14513,
    NPC_BANAL_SPIRIT = 14514,
    NPC_ASPECT_OF_BANALITY = 14518,
    NPC_ASPECT_OF_CORRUPTION = 14519,
    NPC_ASPECT_OF_MALICE = 14520,
    NPC_ASPECT_OF_SHADOW = 14521,
    NPC_DEATH_KNIGHT_DARKREAVER = 14516,
    NPC_DARKREAVER_FALLEN_CHARGER = 14568,
};

enum SCHOLOMANCE_SPELL
{
    SPELL_SUMMON_DARKREAVER_FALLEN_CHARGER = 23261,
    SPELL_SUMMON_VISUAL = 26638,
    SPELL_BOON_OF_LIFE = 17179,
};

enum SCHOLOMANCE_LINE_DEATH_KNIGHT_DARKREAVER
{
    LINE_DEATH_KNIGHT_DARKREAVER_0 = 0,
};

enum SCHOLOMANCE_LINE_JANDICE_BAROV
{
    LINE_JANDICE_BAROV_0 = 0,
};

enum SCHOLOMANCE_LINE_DARKMASTER_GANDLING
{
    LINE_DARKMASTER_GANDLING_0 = 0,
};

enum SCHOLOMANCE_LINE_RAS_FROSTWHISPER
{
    LINE_RAS_FROSTWHISPER_0 = 0,
};

template <class AI, class T>
inline AI* GetScholomanceAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ScholomanceScriptName);
}

#endif
