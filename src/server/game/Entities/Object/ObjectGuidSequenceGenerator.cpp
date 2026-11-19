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

#include "ObjectGuidSequenceGenerator.h"
#include "Log.h"
#include "World.h"

namespace
{
void HandleCounterOverflow(HighGuid high)
{
    TC_LOG_ERROR("misc", "{} guid overflow!! Can't continue, shutting down server. ", ObjectGuid::GetTypeName(high));
    World::StopNow(ERROR_EXIT_CODE);
}

void CheckGuidTrigger(ObjectGuid::LowType newCounter)
{
    World* world = sWorld;
    if (!world->IsGuidAlert() && newCounter > world->getIntConfig(CONFIG_RESPAWN_GUIDALERTLEVEL))
        world->TriggerGuidAlert();
    else if (!world->IsGuidWarning() && newCounter > world->getIntConfig(CONFIG_RESPAWN_GUIDWARNLEVEL))
        world->TriggerGuidWarning();
}

ObjectGuid::LowType CheckGeneratedGuidValue(HighGuid high, ObjectGuid::LowType newCounter)
{
    if (newCounter >= ObjectGuid::GetMaxCounter(high) - 1)
        HandleCounterOverflow(high);

    if (high == HighGuid::Creature || high == HighGuid::Vehicle || high == HighGuid::GameObject || high == HighGuid::Transport)
        CheckGuidTrigger(newCounter);

    return newCounter;
}
}

ObjectGuid::LowType ObjectGuidGenerator::Generate()
{
    return CheckGeneratedGuidValue(_high, _nextGuid++);
}
