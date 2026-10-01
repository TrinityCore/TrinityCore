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

#ifndef TRINITYCORE_MIRROR_TIMER_H
#define TRINITYCORE_MIRROR_TIMER_H

#include "Define.h"
#include "EnumFlag.h"
#include "Timer.h"

enum MirrorTimerType : uint8
{
    MIRROR_TIMER_FATIGUE        = 0,
    MIRROR_TIMER_BREATH         = 1,
    MIRROR_TIMER_FEIGN_DEATH    = 2,

    MIRROR_TIMER_MAX
};

enum class MirrorTimerFlags : uint8
{
    None            = 0x00,
    Paused          = 0x01,
    Changed         = 0x02,
    PausedChanged   = 0x04
};

DEFINE_ENUM_FLAG(MirrorTimerFlags);

class MirrorTimer
{
public:
    bool IsActive() const { return m_maxValue > 0; }
    bool IsRegenerating() const { return m_scale > 0; }

    int32 GetValue() const { return m_value; }
    void SetValue(int32 value);

    int32 GetMaxValue() const { return m_maxValue; }
    void SetMaxValue(int32 maxValue);

    int32 GetScale() const { return m_scale; }
    void SetScale(int32 scale);

    int32 GetSpellId() const { return m_spellId; }

    bool IsPaused() const { return m_flags.HasFlag(MirrorTimerFlags::Paused) && !IsRegenerating(); }
    void SetPaused(bool state);

    bool IsChanged() const { return m_flags.HasFlag(MirrorTimerFlags::Changed); }
    bool IsPausedChanged() const { return m_flags.HasFlag(MirrorTimerFlags::PausedChanged); }
    void ClearChanged() { m_flags.RemoveFlag(MirrorTimerFlags::Changed | MirrorTimerFlags::PausedChanged); }

    void Start(int32 maxValue, int32 spellId);
    void Start(int32 value, int32 maxValue, int32 spellId);

    void Stop();

    enum class UpdateResult : uint8
    {
        Inactive,
        Decreased,
        DecreasedExpired,
        ExpiredTicked,
        Regenerated
    };

    UpdateResult Update(uint32 diff);

private:
    int32 m_value = 0;
    int32 m_maxValue = 0;
    int32 m_scale = -1;
    int32 m_spellId = 0;
    EnumFlag<MirrorTimerFlags> m_flags = MirrorTimerFlags::None;

    static constexpr Milliseconds ExpiredTickPeriod = 1s;
    PeriodicTimer m_expiredTick { ExpiredTickPeriod.count(), ExpiredTickPeriod.count() };
};

#endif // TRINITYCORE_MIRROR_TIMER_H
