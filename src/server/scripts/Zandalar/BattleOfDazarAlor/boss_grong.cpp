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
#include "ScriptedGossip.h"
#include "PhasingHandler.h"
#include "battle_of_dazaralor.h"

const Position apetagonizer_3000_pos = { -907.793f, 919.714f, 386.374f, 0.08f };

enum Spells
{
    PERIODIC_ENERGY_GAIN = 299956,
    TANTRUM = 281936,
    REVERBERATING_SLAM = 282179,
    FEROCIOUS_ROAR = 290574,
    FEROCIOUS_ROAR_FEAR = 290575,
    BESTIAL_COMBO = 282082,
    BESTIAL_SMASH = 283078,
    BESTIAL_IMPACT = 289412,
    BESTIAL_THROW = 289292,
    BESTIAL_THROW_JUMP = 289406,
    RENDERING_BITE_CAST = 285874,
    RENDERING_BITE = 285875,
    MEGATOMIC_SEEKER_MISSILE = 282213,
    MEGATOMIC_SEEKER_MISSILE_CREATE_AT = 282215,
    MEGATOMIC_AT_PERIODIC_DAMAGE = 283069,
    SHATTERED = 282010,
    //Adds
    PARACHUTE = 55001,
    APETAGONIZE = 282243,
    APETAGONIZE_CORE_MISSILE = 285661,
    APETAGONIZE_CORE_BUFF = 285659,
    DISCHARGE_APETAGONIZE_CORE = 285660,
    LIGHTNING_DETONATION = 285654,
};

enum Events
{
    EVENT_TANTRUM = 1,
    EVENT_REVERBERATING_SLAM,
    EVENT_FEROCIOUS_ROAR,
    EVENT_BESTIAL_COMBO,
    EVENT_APETAGONIZER,
    EVENT_MEGATOMIC,
    EVENT_APETAGONIZE,
};

void AddSC_boss_grong()
{
    
}
