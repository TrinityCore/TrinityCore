/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Random.h"
#include "Common.h"
#include "Errors.h"
#include "SFMT.h"
#include <boost/thread/tss.hpp>

static boost::thread_specific_ptr<SFMTRand> sfmtRand;

static SFMTRand* GetRng()
{
    SFMTRand* rand = sfmtRand.get();

    if (!rand)
    {
        rand = new SFMTRand();
        sfmtRand.reset(rand);
    }

    return rand;
}

int32 irand(int32 min, int32 max)
{
    ASSERT(max >= min);
    return int32(GetRng()->IRandom(min, max));
}

uint32 urand(uint32 min, uint32 max)
{
    ASSERT(max >= min);
    return GetRng()->URandom(min, max);
}

uint32 urandms(uint32 min, uint32 max)
{
    ASSERT(max >= min);
    ASSERT(INT_MAX / IN_MILLISECONDS >= max);
    return GetRng()->URandom(min * IN_MILLISECONDS, max * IN_MILLISECONDS);
}

float frand(float min, float max)
{
    ASSERT(max >= min);
    return float(GetRng()->Random() * (max - min) + min);
}

Milliseconds randtime(Milliseconds const& min, Milliseconds const& max)
{
    long long diff = max.count() - min.count();
    ASSERT(diff >= 0);
    ASSERT(diff <= (uint32)-1);
    return min + Milliseconds(urand(0, diff));
}

uint32 rand32()
{
    return GetRng()->BRandom();
}

double rand_norm()
{
    return GetRng()->Random();
}

double rand_chance()
{
    return GetRng()->Random() * 100.0;
}

SFMTEngine& SFMTEngine::Instance()
{
    static SFMTEngine engine;
    return engine;
}
