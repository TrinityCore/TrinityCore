/*
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "OutdoorPvPObjectiveAI.h"
#include "Creature.h"
#include "Player.h"
#include "Unit.h"
#include "OutdoorPvPMgr.h"
#include "World.h"

#define MAX_OUTDOOR_PVP_DISTANCE 200 // the max value in capture point type go data0 is 100 currently, so use twice that much to handle leaving as well

OutdoorPvPObjectiveAI::OutdoorPvPObjectiveAI(Creature *c) : NullCreatureAI(c)
{
    sLog.outDebug("OutdoorPvP objective AI assigned to creature guid %u", me->GetGUIDLow());
    me->SetReactState(REACT_AGGRESSIVE);
}

void OutdoorPvPObjectiveAI::MoveInLineOfSight(Unit *u)
{
    // IsVisible only passes for players in range, so no need to check again
    // leaving/entering distance will be checked based on go range data
    if((u->GetTypeId() == TYPEID_PLAYER) && me->IsWithinDistInMap(u, MAX_OUTDOOR_PVP_DISTANCE))
        sOutdoorPvPMgr.HandleCaptureCreaturePlayerMoveInLos(((Player*)u), me);
}

int OutdoorPvPObjectiveAI::Permissible(const Creature * c)
{
    // only assigned through AI name, never by permissibility check
    return PERMIT_BASE_NO;
}


