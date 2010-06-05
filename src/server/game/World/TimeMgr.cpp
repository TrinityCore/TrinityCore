/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#include "TimeMgr.h"
#include "Policies/SingletonImp.h"

INSTANTIATE_SINGLETON_1(GameTime);

bool PeriodicTimer::Update(const uint32 &diff)
{
    if((i_expireTime -= diff) > 0)
        return false;

    i_expireTime += i_period > diff ? i_period : diff;
    return true;
}

void PeriodicTimer::SetPeriodic(int32 period, int32 start_time)
{
    i_expireTime=start_time, i_period=period;
}
