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
#include "battle_of_dazaralor.h"

const Position adds_pos = { -2023.0f, 833.0f, 6.0f, 4.73f };

enum Texts
{
    //VO_81_Zandalari_Paladin
    SAY_AGGRO = 0,
    SAY_INTRO = 1,    
    SAY_WAVE_OF_LIGHT,
    SAY_PRAYER_FOR_THE_FALLEN,
    SAY_RETRIBUTION,
    SAY_RECKONING,
    SAY_CALL_TO_ARMS,
    SAY_KILL,
    SAY_DEATH
};

enum Spells
{
    PERIODIC_ENERGY_GAIN = 295065, // 2 every 800ms
    SUMMON_DARKFORGE_RAM = 270562,
    SACRED_BLADE = 283572,
    WAVE_OF_LIGHT_CREATE_AT = 283598,
    WAVE_OF_LIGHT_PERIODIC = 283617,
    WAVE_OF_LIGHT_HEAL = 283619,
    SEAL_OF_RETRIBUTION = 284469,
    RETRIBUTION_AOE_DAMAGE = 284488,
    ZEALOTRY = 284459,
    JUDGMENT_RIGHTEOUSNESS = 283933,
    SEAL_OF_RECKONING = 284436,
    JUDGMENT_RECKONING = 284474,
    AVENGING_WRATH = 282113,
    CALL_TO_ARMS = 283662,
    PRAYER_OF_THE_FALLEN = 287469,
    DIVINE_PROTECTION = 288292,
    DIVINE_PROCTECTION_REDUCTION = 288294,
};

enum Events
{
    EVENT_WAVE_OF_LIGHT = 1,
    EVENT_SEAL_OF_RETRIBUTION,
    EVENT_ZEALOTRY,
    EVENT_JUDGMENT_RIGHTEOUSNESS,
    EVENT_SEAL_OF_RECKONING,
    EVENT_AVENGING_WRATH,
    EVENT_PRAYER_FOR_THE_FALLEN,
    EVENT_JUDGMENT_OF_RECKONING,
    EVENT_CALL_TO_ARMS,
    EVENT_SWITCH_SEAL,
    EVENT_DIVINE_PROTECTION,
};

enum Disciple
{
    ANGELIC_RENEWAL = 287419,
    DIVINE_BURST = 283626,
    HEAL_SP = 283628,
    PENANCE_HEAL = 284593,
    PENANCE_DAMAGE = 284595,
    EVENT_DIVINE_BURST = 1,
    EVENT_HEAL,
    EVENT_PENANCE_HEAL,
    EVENT_PENANCE_DAMAGE
};

enum Crusader
{
    AURA_OF_RETRIBUTION = 284468,
    BLINDING_FAITH_DUMMY = 283650,
    BLINDING_FAITH_DISORIENT = 283651,
    CONSECRATION_AT = 283579,
    CRUSADER_STRIKE = 283637,
    DIVINE_MALLET = 287439,
    DIVINE_MALLET_AT = 282074,
    WAVE_OF_LIGHT_HEALING = 283619,
    EVENT_CRUSADER_STRIKE = 1,
    EVENT_CONSECRATION,
    EVENT_DIVINE_MALLET,
    EVENT_BLINDING_FAITH,    
};

void AddSC_boss_rawani_kanae()
{
    
}
