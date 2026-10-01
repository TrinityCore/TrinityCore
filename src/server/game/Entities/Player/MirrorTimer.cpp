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

#include "MirrorTimer.h"

void MirrorTimer::SetValue(int32 value)
{
    if (IsActive() && value != GetValue())
        m_flags |= MirrorTimerFlags::Changed;

    m_value = value;
}

void MirrorTimer::SetMaxValue(int32 maxValue)
{
    if (!maxValue)
        Stop();

    if (!IsActive())
        return;

    if (maxValue != GetMaxValue())
        m_flags |= MirrorTimerFlags::Changed;

    m_maxValue = maxValue;
    SetValue(std::min(GetValue(), GetMaxValue()));
}

void MirrorTimer::SetScale(int32 scale)
{
    if (!scale)
        return SetPaused(true);

    if (IsActive() && scale != GetScale())
        m_flags |= MirrorTimerFlags::Changed;

    m_scale = scale;
}

void MirrorTimer::SetPaused(bool state)
{
    if (IsActive() && state != IsPaused())
        m_flags |= MirrorTimerFlags::PausedChanged;

    if (state)
        m_flags |= MirrorTimerFlags::Paused;
    else
        m_flags &= ~MirrorTimerFlags::Paused;
}

void MirrorTimer::Start(int32 maxValue, int32 spellId)
{
    if (m_scale < 0)
    {
        m_value = maxValue;
        m_maxValue = maxValue;
        m_spellId = spellId;
        m_flags |= MirrorTimerFlags::Changed;
        m_expiredTick.SetPeriodic(ExpiredTickPeriod.count(), ExpiredTickPeriod.count());
    }
    else
        Stop();
}

void MirrorTimer::Start(int32 value, int32 maxValue, int32 spellId)
{
    Start(maxValue, spellId);

    if (IsActive())
        m_value = value;
}

void MirrorTimer::Stop()
{
    if (!IsActive())
        return;

    m_value = 0;
    m_maxValue = 0;
    m_flags = MirrorTimerFlags::Changed;
}

MirrorTimer::UpdateResult MirrorTimer::Update(uint32 diff)
{
    if (!IsActive() || IsPaused())
        return UpdateResult::Inactive;

    int32 delta = int32(diff) * GetScale();

    if (delta < 0)      // Timer running out
    {
        if (GetValue() > -delta)
        {
            m_value += delta;
            return UpdateResult::Decreased;
        }

        if (!m_value)   // subsequent ticks after expiration
        {
            if (!m_expiredTick.Update(diff))
                return UpdateResult::DecreasedExpired;
        }
        else
            m_value = 0;

        return UpdateResult::ExpiredTicked;
    }
    else                // Timer regenerating
    {
        if (GetValue() + delta < GetMaxValue())
        {
            m_value += delta;
            m_expiredTick.SetPeriodic(ExpiredTickPeriod.count(), ExpiredTickPeriod.count());
        }
        else
            Stop();

        return UpdateResult::Regenerated;
    }
}
