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

#ifndef Random_h__
#define Random_h__

#include "Define.h"
#include "Duration.h"
#include <limits>

/* Return a random number in the range min..max. */
TC_COMMON_API int32 irand(int32 min, int32 max);

/* Return a random number in the range min..max (inclusive). */
TC_COMMON_API uint32 urand(uint32 min, uint32 max);

/* Return a random millisecond value between min and max seconds. Functionally equivalent to urand(min*IN_MILLISECONDS, max*IN_MILLISECONDS). */
TC_COMMON_API uint32 urandms(uint32 min, uint32 max);

/* Return a random number in the range 0 .. UINT32_MAX. */
TC_COMMON_API uint32 rand32();

/* Return a random time in the range min..max (up to millisecond precision). Only works for values where millisecond difference is a valid uint32. */
TC_COMMON_API Milliseconds randtime(Milliseconds const& min, Milliseconds const& max);

/* Return a random number in the range min..max */
TC_COMMON_API float frand(float min, float max);

/* Return a random double from 0.0 to 1.0 (exclusive). */
TC_COMMON_API double rand_norm();

/* Return a random double from 0.0 to 100.0 (exclusive). */
TC_COMMON_API double rand_chance();

/* Return a random number in the range 0..count (exclusive) with each value having a different chance of happening */
TC_COMMON_API uint32 urandweighted(size_t count, double const* chances);

/* Return true if a random roll fits in the specified chance (range 0-100). */
inline bool roll_chance_f(float chance)
{
    return chance > rand_chance();
}

/* Return true if a random roll fits in the specified chance (range 0-100). */
inline bool roll_chance_i(int chance)
{
    return chance > irand(0, 99);
}

/*
* SFMT wrapper satisfying UniformRandomNumberGenerator concept for use in <random> algorithms
*/
class TC_COMMON_API SFMTEngine
{
public:
    typedef uint32 result_type;

    static constexpr result_type min() { return std::numeric_limits<result_type>::min(); }
    static constexpr result_type max() { return std::numeric_limits<result_type>::max(); }
    result_type operator()() const { return rand32(); }

    static SFMTEngine& Instance();
};

#endif // Random_h__
