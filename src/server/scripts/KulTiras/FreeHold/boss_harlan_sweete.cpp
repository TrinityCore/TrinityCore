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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "freehold.h"

enum HarlanSweeteSpells
{
    ///Harlan Sweete
    CannonBarrage = 257305,
    CannonBarrageMissile = 257309,
    FlamingShrapnel = 257308,
    FieryDebris = 257460,
    SwiftwindSaber = 257454,
    SwiftwindSaberSummon = 257268,
    SwiftwindSaberDmg = 257293,
    LoadedDiceAllHands = 257402, ///Aplied at 60% of the health
    LoadedDiceManOWar = 257458, ///Aplied at 30% of the health
    ///Irontide Grenadiers
    BlackPowderBomb = 257315,
    BlackPowderBombAura = 257314
};

enum HarlanSweeteEvents
{
    EventCannonBarrage = 1,
    EventSwiftwindSaber,
    EventSummonIrontideGrenadier,
    EventCheckPlayer,
};

enum HarlanTalk
{
    TalkAggro = 0,
    Talk60Percent,
    TalkDead,
    TalkGranadier,
    TalkCannon,
    Talk30Percent,
};

Position const GranadierSummonPos = { -1583.55f, -558.43f, 74.0f, 5.37f };

void AddSC_boss_harlan_sweete()
{
    
}