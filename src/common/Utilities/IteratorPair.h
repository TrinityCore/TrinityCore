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

#ifndef IteratorPair_h__
#define IteratorPair_h__

#include "Define.h"
#include <utility>

namespace Trinity
{
    /**
     * @class IteratorPair
     *
     * @brief Utility class to enable range for loop syntax for multimap.equal_range uses
     */
    template<class iterator>
    class IteratorPair
    {
    public:
        IteratorPair() : _iterators() { }
        IteratorPair(std::pair<iterator, iterator> iterators) : _iterators(iterators) { }

        iterator begin() const { return _iterators.first; }
        iterator end() const { return _iterators.second; }

    private:
        std::pair<iterator, iterator> _iterators;
    };

    namespace Containers
    {
        template<class M>
        inline auto MapEqualRange(M& map, typename M::key_type const& key) -> IteratorPair<decltype(map.begin())>
        {
            return { map.equal_range(key) };
        }
    }
    //! namespace Containers
}
//! namespace Trinity

#endif // IteratorPair_h__
