/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "HomeMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"

void HomeMovementGenerator<Creature>::DoInitialize(Creature* owner)
{
    SetTargetLocation(owner);
}

void HomeMovementGenerator<Creature>::DoFinalize(Creature* owner)
{
    if (m_arrived)
    {
        owner->ClearUnitState(UNIT_STATE_EVADE);
        owner->SetWalk(true);
        owner->LoadCreaturesAddon();
        owner->AI()->JustReachedHome();
    }
}

void HomeMovementGenerator<Creature>::DoReset(Creature* owner)
{
    SetTargetLocation(owner);
}

void HomeMovementGenerator<Creature>::SetTargetLocation(Creature* owner)
{
    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE))
        return;

    m_travelInitialized = true;

    Movement::MoveSplineInit init(owner);
    float x, y, z, o;

    // try to get a reset position placed by any other Movement
    if (owner->GetMotionMaster()->empty() || !owner->GetMotionMaster()->top()->GetResetPosition(owner, x, y, z))
    {
        owner->GetHomePosition(x, y, z, o);
        init.SetFacing(o);
    }
    init.MoveTo(x, y, z);
    init.SetWalk(false);
    init.Launch();

    m_arrived = false;

    owner->ClearUnitState(uint32(UNIT_STATE_ALL_STATE & ~(UNIT_STATE_EVADE | UNIT_STATE_IGNORE_PATHFINDING)));
}

bool HomeMovementGenerator<Creature>::DoUpdate(Creature* owner, const uint32 time_diff)
{
    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE))
        return true;

    if (!m_travelInitialized)
        SetTargetLocation(owner);

    // If despawnTimer has passed, initialize the despawn event
    m_despawnTimer.Update(time_diff);
    if (m_despawnTimer.Passed())
    {
        owner->m_Events.AddEvent(new EvadeDespawner(owner), owner->m_Events.CalculateTime(1000));
        return false;
    }
    else
        m_arrived = owner->movespline->Finalized();

    return !m_arrived;
}
