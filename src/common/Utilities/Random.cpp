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

#include "Random.h"
#include "Errors.h"
#include "SFMTRand.h"
#include <boost/math/tools/roots.hpp>
#include <memory>
#include <random>

namespace
{
constexpr RandomEngine engine;

SFMTRand* GetRng() noexcept
{
    thread_local std::unique_ptr<SFMTRand> sfmtRand = std::make_unique<SFMTRand>();
    return sfmtRand.get();
}
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
    ASSERT(diff <= 0xFFFFFFFF);
    return min + Milliseconds(urand(0, uint32(diff)));
}

uint32 rand32()
{
    return GetRng()->RandomUInt32();
}

float rand_norm()
{
    std::uniform_real_distribution<float> urd;
    return urd(engine);
}

float rand_chance()
{
    std::uniform_real_distribution<float> urd(0.0f, 100.0f);
    return urd(engine);
}

uint32 urandweighted(size_t count, double const* chances)
{
    std::discrete_distribution<uint32> dd(chances, chances + count);
    return dd(engine);
}

namespace
{
struct PseudoRandomDistributionChanceTable : std::array<float, 10000>
{
    PseudoRandomDistributionChanceTable()
    {
        (*this)[0] = 0.0f;
        for (std::size_t i = 1; i < size(); ++i)
            (*this)[i] = NormalizePseudoRandomDistributionChance(i * 0.0001f);
    }

    static float NormalizePseudoRandomDistributionChance(float chance)
    {
        std::uintptr_t iterationLimit = 10;
        return boost::math::tools::newton_raphson_iterate([target = 1.0f / chance](float p) -> std::pair<float, float>
        {
            // (value, derivative) pairs
            std::pair<float, float> chain = { 1.0f, 0.0f };
            std::pair<float, float> result = { 1.0f - target, 0.0f };

            uint32 cap = uint32(std::ceil(1.0f / p));
            for (uint32 i = 1; i < cap; ++i)
            {
                float chanceToFail = 1 - p * i;
                chain.second = chain.second * chanceToFail - chain.first * i;
                chain.first = chain.first * chanceToFail;

                result.first += chain.first;
                result.second += chain.second;
            }

            return result;
        }, chance * chance, 0.0f, chance, 6, iterationLimit);
    }
} const ChanceCache;
}

bool roll_chance(float chance, PseudoRandomDistributionState& state)
{
    std::ptrdiff_t chanceIndex = std::ptrdiff_t(std::round(chance * 100.0f));
    if (chanceIndex < 0)
        return false;

    if (chanceIndex >= std::ssize(ChanceCache) || state.AccumulateChance(ChanceCache[chanceIndex]) > rand_norm())
    {
        state.Reset();
        return true;
    }

    return false;
}
