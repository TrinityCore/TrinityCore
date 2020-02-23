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

#include "GenericMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "MoveSpline.h"
#include "Unit.h"

void GenericMovementGenerator::Initialize(Unit* /*owner*/)
{
    _duration.Reset(_splineInit.Launch());
}

bool GenericMovementGenerator::Update(Unit* owner, uint32 diff)
{
    // Cyclic splines never expire, so update the duration only if it's not cyclic
    if (!owner->movespline->isCyclic())
        _duration.Update(diff);

    if (_duration.Passed())
        return false;

    return !owner->movespline->Finalized();
}

void GenericMovementGenerator::Finalize(Unit* owner)
{
    MovementInform(owner);
}

void GenericMovementGenerator::MovementInform(Unit* owner)
{
    if (Creature* creature = owner->ToCreature())
        if (creature->AI())
            creature->AI()->MovementInform(_type, _pointId);
}
