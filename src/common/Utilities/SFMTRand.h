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

#ifndef SFMTRand_h__
#define SFMTRand_h__

#include <SFMT.h>

namespace boost {
    template <typename T> class thread_specific_ptr;
}

/*
 * C++ Wrapper for SFMT
 */
class SFMTRand {
    friend class boost::thread_specific_ptr<SFMTRand>;
public:
    SFMTRand();
    void RandomInit(uint32_t seed); // Re-seed
    int32_t IRandom(int32_t min, int32_t max); // Output random integer
    uint32_t URandom(uint32_t min, uint32_t max);
    double Random(); // Output random floating point number
    uint32_t BRandom(); // Output random bits
    void* operator new(size_t size, std::nothrow_t const&);
    void operator delete(void* ptr, std::nothrow_t const&);
    void* operator new(size_t size);
    void operator delete(void* ptr);
    void* operator new[](size_t size, std::nothrow_t const&);
    void operator delete[](void* ptr, std::nothrow_t const&);
    void* operator new[](size_t size);
    void operator delete[](void* ptr);
private:
    sfmt_t state;
};

#endif // SFMTRand_h__
