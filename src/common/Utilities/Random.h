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

#ifndef Random_h__
#define Random_h__

#include "Define.h"
#include "Duration.h"
#include <limits>
#include <random>

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

    static TRINITY_CONSTEXPR result_type min() { return std::numeric_limits<result_type>::min(); }
    static TRINITY_CONSTEXPR result_type max() { return std::numeric_limits<result_type>::max(); }
    result_type operator()() const { return rand32(); }

    static SFMTEngine& Instance();
};

// Ugly, horrible, i don't even..., hack for VS2013 to work around missing discrete_distribution(iterator, iterator) constructor
namespace Trinity
{
#if COMPILER == COMPILER_MICROSOFT && _MSC_VER <= 1800
    template<typename T>
    struct discrete_distribution_param : public std::discrete_distribution<T>::param_type
    {
        typedef typename std::discrete_distribution<T>::param_type base;

        template<typename InIt>
        discrete_distribution_param(InIt begin, InIt end) : base(_Noinit())
        {
            this->_Pvec.assign(begin, end);
            this->_Init();
        }
    };
#else
    template<typename T>
    using discrete_distribution_param = typename std::discrete_distribution<T>::param_type;
#endif
}

#endif // Random_h__
