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

#include "little_patience.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "CreatureAI.h"
#include "MoveSplineInit.h"
#include "SpellScript.h"
#include "Vehicle.h"
#include "ScenarioMgr.h"

enum Spells
{
    SPELL_GORGE = 134554,
    SPELL_GORGE_EFF = 134555,
    SPELL_BLOOD_RAGE = 134959,
    SPELL_FRENZIED_ASSAULT = 134983,
    SPELL_BLOOD_RAGE_EFF = 134963,
    SPELL_BLOOD_RAGE_FIXATE = 134974,
    SPELL_CRUSHING_LEAP = 135005,
    SPELL_CRUSHING_LEAP_EFF = 135006,
    SPELL_POUNCE = 119579,
    SPELL_POUNCE_EFF = 119578,
    SPELL_RAVAGE = 119580,
    SPELL_VICIOUS_REND = 135498,
    SPELL_SWAMP_GAS = 135494,
    SPELL_SWAMP_GAS_TRIGGERING = 135495,
    SPELL_SWAMP_GAS_EFF = 135496,
    SPELL_SPIRIT_BOMB = 134609,
    SPELL_SPIRIT_BOMB_SUMM = 134610,
    SPELL_SPIRIT_BOMB_TRIGGERING = 134592,
    SPELL_SPIRIT_BOMB_EFF = 134600,
    SPELL_SPIRIT_BARRAGE = 134674,

    // Constructions
    SPELL_JINYU_CONSTRUCTION_PROGRESS = 133311,
    SPELL_GNOME_CONSTRUCTION_PROGRESS = 133849,
    SPELL_DWARF_CONSTRUCTION_PROGRESS = 134086,
    SPELL_PANDAREN_CONSTRUCTION_PROGRESS = 134567,
    SPELL_NIGHT_ELF_CONSTRUCTION_PROGRESS = 135260,
    SPELL_CONSTRUCTION_BAR_MOVEMENT = 133852,
    SPELL_TERRIFIED = 133494,
};

enum Events
{
    EVENT_GORGE = 1,
    EVENT_BLOOD_RAGE,
    EVENT_CRUSHING_LEAP,
    EVENT_POUNCE,
    EVENT_RAVAGE,
    EVENT_VICIOUS_REND,
    EVENT_SWAMP_GAS,
    EVENT_SPIRIT_BOMB,
    EVENT_SPIRIT_BARRAGE,
};

const std::map<uint32, uint32> leadersBarProgress =
{
    { NPC_ELDER_ADLER,       SPELL_JINYU_CONSTRUCTION_PROGRESS     },
    { NPC_ROSEY_AXLEROD,     SPELL_GNOME_CONSTRUCTION_PROGRESS     },
    { NPC_FERA_PEARL,        SPELL_NIGHT_ELF_CONSTRUCTION_PROGRESS },
    { NPC_DUFF_MCSTRUM,      SPELL_DWARF_CONSTRUCTION_PROGRESS     },
    { NPC_MASTER_BROWNSTONE, SPELL_PANDAREN_CONSTRUCTION_PROGRESS  },
};

const std::vector<uint32> progressInspired =
{
    SPELL_INSPIRED_NIGHT_ELF,
    SPELL_INSPIRED_GNOME_EFF,
    SPELL_INSPIRED_JYNUI,
    SPELL_INSPIRED_DWARF
};

void AddSC_little_patience()
{
    
}