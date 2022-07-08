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

#include "ZoneScript.h"
#include "Creature.h"
#include "GameEventSender.h"

ZoneScript::ZoneScript()
{
}

ZoneScript::~ZoneScript()
{
}

uint32 ZoneScript::GetCreatureEntry(ObjectGuid::LowType /*guidLow*/, CreatureData const* data)
{
    return data->id;
}

void ZoneScript::TriggerGameEvent(uint32 gameEventId, WorldObject* source /*= nullptr*/, WorldObject* target /*= nullptr*/)
{
    if (source)
        GameEvents::Trigger(gameEventId, source, target);
    else
        ProcessEvent(nullptr, gameEventId, nullptr);
}
