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

#include "grimrail_depot.h"
#include "MoveSplineInit.h"
#include "Vehicle.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"

enum eSkylordTorvaTalks
{
	TalkAggro = 1,        ///< Rakun, lets give'em hell! [45878]
	TalkDeath,            ///< You ... Can't ... [45879]
	TalkGeneralEvent01,   ///< Another one! [45880]
	TalkGeneralEvent02,   ///< Light'em up!  [45881]
	TalkGeneralEvenet03,  ///< Show them what you're made of! [45882]
	TalkIntro,            ///< No body stops the iron Horde, No body [45883]
	TalkKill01,           ///< Hell shockin' [45884]
	TalkKill02            ///< Haaa [45885]
};

enum eSkylordTorvaActions
{
    ActionCombatStartDragonFlight = 1,
    ActionCombatStopDragonFlight
};

enum eSkylordTorvaCreatures
{
    CreatureTriggerDiffusedEnergy = 324235,
};

enum eSkylordTorvaMovements
{
    MovementTorvaStartShootingLightning = 1,
    MovementTorvaHomePosition,
    MovementFlyPoint,
};

Position const g_TorvaFirstPosition = {1647.38f, 1956.70f, 121.945f};
Position const g_TorvaHomePosition  = {1647.00f, 2000.29f, 107.789f};

Position const g_DrakePointA = {1646.42f, 1909.48f, 134.486f};
Position const g_DrakePointB = {1636.19f, 2079.83f, 137.453f};

#define g_DrakeDisplay 55447
#define g_TovraDisplay 55630
float g_DrakeOrientationWhileFlightIntro = float(1.524283);

void AddSC_boss_skylord_tovra()
{
    
}
