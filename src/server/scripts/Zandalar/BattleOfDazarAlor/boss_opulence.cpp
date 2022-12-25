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

enum Texts
{
    SAY_GALLYWIX_OPULENCE_AGGRO = 0,
    SAY_GALLYWIX_STAGE_TWO_BEGINS = 2,
    SAY_GALLYWIX_STAGE_TWO_BEGINS_1 = 1,
    SAY_GALLYWIX_KILL = 3,
    SAY_GALLYWIX_DEATH = 4,
};

enum Spells
{
    PERIODIC_ENERGY_GAIN = 299956,
    HOARD_POWER = 287070,
    COIN_SHOWER_AT = 285014,
    COIN_SHOWER_MISSILE = 285027,
    COIN_SHOWER_DAMAGE = 285046,
    COIN_SWEEP = 287037,
    FOCUSED_ANIMUS_AURA = 284614,
    GREED_AURA = 284943,
    LIQUID_GOLD_AURA = 287072,
    LIQUID_GOLD_CREATE_AT = 287073,
    LIQUID_GOLD_AT_DAMAGE = 287074,
    SPIRITS_OF_GOLD = 285995,
    SURGING_GOLD = 289155,
    WAIL_OF_GREED = 284941,
    WAIL_OF_GREED_MOD_DAMAGE = 284942,
    //Add
    CHANNEL_OF_GOLD = 286026,
    GOLD_BURST_DAMAGE = 286040,
};

enum Events
{
    EVENT_HOARD_POWER = 1,
    EVENT_SPIRITS_OF_GOLD,
    EVENT_LIQUID_GOLD,
    EVENT_COIN_SHOWER,
    EVENT_WAIL_OF_GREED,
    EVENT_COIN_SWEEP,
};

void AddSC_boss_opulence()
{
    
}
