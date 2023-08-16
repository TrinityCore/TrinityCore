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
    template<class iterator, class end_iterator = iterator>
    class IteratorPair
    {
    public:
        constexpr IteratorPair() : _iterators() { }
        constexpr IteratorPair(iterator first, end_iterator second) : _iterators(first, second) { }
        constexpr IteratorPair(std::pair<iterator, end_iterator> iterators) : _iterators(iterators) { }

        constexpr iterator begin() const { return _iterators.first; }
        constexpr end_iterator end() const { return _iterators.second; }

    private:
        std::pair<iterator, end_iterator> _iterators;
    };

    namespace Containers
    {
        template<typename iterator, class end_iterator = iterator>
        constexpr IteratorPair<iterator, end_iterator> MakeIteratorPair(iterator first, end_iterator second)
        {
            return { first, second };
        }

        template<typename iterator, class end_iterator = iterator>
        constexpr IteratorPair<iterator, end_iterator> MakeIteratorPair(std::pair<iterator, end_iterator> iterators)
        {
            return iterators;
        }

        template<class M>
        auto MapEqualRange(M& map, typename M::key_type const& key)
        {
            return MakeIteratorPair(map.equal_range(key));
        }
    }
    //! namespace Containers
}
//! namespace Trinity

#endif // IteratorPair_h__
