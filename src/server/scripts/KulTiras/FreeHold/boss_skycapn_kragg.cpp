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
#include "Vehicle.h"
#include "freehold.h"

enum KraggSpells
{
    ///Rider SkyCap Kragg (Before Fight with Boss)
    VileBombadment = 256005,
    VileCoating = 256016,
    ///Boss SkyCap Kragg
    Charrrrrge = 255952, /// With Mount 
    PistolShot = 255966, /// With Mount 
    AzeritePowderShot = 256106, /// Without Mount 
    RevitalizingBrewSkyCap = 256060, /// Without Mount
    RevitalizingBrewPlayer = 263297,
    ///Heroic
    DiveBomb = 272046  ///Sharkbait will then charge across the arena in a straight line, dealing damage and knocking back all players in the path
};

enum KraggEvents
{
    EventVileBombadment = 1,
    EventChaaarrge,
    EventPistolShot,
    EventAzeritePowderShot,
    EventRevitalizingBrew,
    ///Heroic Event
    EventDiveBombs,
};

enum KraggDatas
{
    DataCharge,
    DataMountInCombat
};

enum KraggPhases
{
    PhaseMount,
    PhaseUnmount
};

enum KraggMovementPoint
{
    MovementPointMiddle,
    MovementPointDiveBomb,
    MovementPointDiveBombCasted
};

enum KraggTalk
{
    TalkAggro1 = 0,
    TalkUnmount = 1,
    TalkAzeritePowderShot1 = 2,
    TalkDead = 5,
    TalkAggro2 = 6,
    TalkAzeritePowderShot2 = 7,
    TalkDiveBomb = 8
};

Position const MiddlePos = { -1768.29f, -1009.25f, 110.0f, 0.418879f };

///Todo Add damage on mechanic Dive Bombs, is necesary make  SPELL_EFFECT_254 is something related about charge effect and target front the trajectory 

Position GetRandomPositionAround(Unit* unit, float distMin, float distMax)
{
    double angle = rand_norm() * 2.0 * M_PI;
    float x = unit->GetPositionX() + (float)(frand(distMin, distMax) * std::sin(angle));
    float y = unit->GetPositionY() + (float)(frand(distMin, distMax) * std::cos(angle));
    float z = unit->GetPositionZ();
    unit->UpdateAllowedPositionZ(x, y, z);
    return { x, y, z };
}


void AddSC_boss_skycapn_kragg()
{
   
}
