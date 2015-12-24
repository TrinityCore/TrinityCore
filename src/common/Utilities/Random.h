/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
#include <random>

/* Return a random number in the range min..max. */
int32 irand(int32 min, int32 max);

/* Return a random number in the range min..max (inclusive). */
uint32 urand(uint32 min, uint32 max);

/* Return a random millisecond value between min and max seconds. Functionally equivalent to urand(min*IN_MILLISECONDS, max*IN_MILLISECONDS). */
uint32 urandms(uint32 min, uint32 max);

/* Return a random number in the range 0 .. UINT32_MAX. */
uint32 rand32();

/* Return a random number in the range min..max */
float frand(float min, float max);

/* Return a random double from 0.0 to 1.0 (exclusive). */
double rand_norm();

/* Return a random double from 0.0 to 100.0 (exclusive). */
double rand_chance();

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
class SFMTEngine
{
public:
    typedef uint32 result_type;

    result_type min() const { return std::numeric_limits<result_type>::min(); }
    result_type max() const { return std::numeric_limits<result_type>::max(); }
    result_type operator()() const { return rand32(); }

    static SFMTEngine& Instance();
};

#endif // Random_h__
