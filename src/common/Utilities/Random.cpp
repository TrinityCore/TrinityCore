/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "Errors.h"
#include "SFMTRand.h"
#include <boost/thread/tss.hpp>
#include <random>

static boost::thread_specific_ptr<SFMTRand> sfmtRand;
static RandomEngine engine;

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
    std::uniform_int_distribution<int32> uid(min, max);
    return uid(engine);
}

uint32 urand(uint32 min, uint32 max)
{
    ASSERT(max >= min);
    std::uniform_int_distribution<uint32> uid(min, max);
    return uid(engine);
}

uint32 urandms(uint32 min, uint32 max)
{
    ASSERT(std::numeric_limits<uint32>::max() / Milliseconds::period::den >= max);
    return urand(min * Milliseconds::period::den, max * Milliseconds::period::den);
}

float frand(float min, float max)
{
    ASSERT(max >= min);
    std::uniform_real_distribution<float> urd(min, max);
    return urd(engine);
}

Milliseconds randtime(Milliseconds min, Milliseconds max)
{
    long long diff = max.count() - min.count();
    ASSERT(diff >= 0);
    ASSERT(diff <= (uint32)-1);
    return min + Milliseconds(urand(0, diff));
}

uint32 rand32()
{
    return GetRng()->RandomUInt32();
}

double rand_norm()
{
    std::uniform_real_distribution<double> urd;
    return urd(engine);
}

double rand_chance()
{
    std::uniform_real_distribution<double> urd(0.0, 100.0);
    return urd(engine);
}

uint32 urandweighted(size_t count, double const* chances)
{
    std::discrete_distribution<uint32> dd(chances, chances + count);
    return dd(engine);
}

RandomEngine& RandomEngine::Instance()
{
    return engine;
}
