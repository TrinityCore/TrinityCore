/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "DamageEventMap.h"
#include "Random.h"
#include "Unit.h"

void DamageEventMap::Reset()
{
    _eventMap.clear();
    _phase = 0;
}

void DamageEventMap::SetPhase(uint16 phase)
{
    if (!phase)
        _phase = 0;
    else if (phase <= 16)
        _phase = uint16(1 << (phase - 1));
}

bool DamageEventMap::HasEvent(uint32 eventId) const
{
    for (DamageEventStore::const_iterator itr = _eventMap.begin(); itr != _eventMap.end(); ++itr)
        if ((itr->second & 0x00000000FFFFFFFF) == eventId)
            return true;

    return false;
}

void DamageEventMap::ScheduleEventBelowHealthPct(uint32 eventId, uint8 healthPct, uint16 group /*= 0*/, uint16 phase /*= 0*/)
{
    if (group && group < 16)
        eventId |= (1LL << (group + 31));

    if (phase && phase < 16)
        eventId |= (1LL << (phase + 47));

    _eventMap.insert(DamageEventStore::value_type(healthPct, eventId));
}

uint32 DamageEventMap::OnDamageTaken(uint32 damageTaken)
{
    while (!Empty())
    {
        DamageEventStore::iterator itr = _eventMap.begin();

        if (!_target->HealthWillBeBelowPctDamaged(itr->first, damageTaken))
            return 0;
        else if (_phase && (itr->second & 0xFFFF000000000000) && !((itr->second >> 48) & _phase))
            _eventMap.erase(itr);
        else
        {
            uint32 eventId = (itr->second & 0x00000000FFFFFFFF);
            _lastEvent = itr->second; // include phase/group
            _eventMap.erase(itr);
            return eventId;
        }
    }

    return 0;
}

void DamageEventMap::CancelEvent(uint32 eventId)
{
    if (Empty())
        return;

    for (DamageEventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (eventId == (itr->second & 0x00000000FFFFFFFF))
            _eventMap.erase(itr++);
        else
            ++itr;
    }
}

void DamageEventMap::CancelEventGroup(uint16 group)
{
    if (!group || group > 16 || Empty())
        return;

    for (DamageEventStore::iterator itr = _eventMap.begin(); itr != _eventMap.end();)
    {
        if (itr->second & (1ULL << (group + 31)))
            _eventMap.erase(itr++);
        else
            ++itr;
    }
}
