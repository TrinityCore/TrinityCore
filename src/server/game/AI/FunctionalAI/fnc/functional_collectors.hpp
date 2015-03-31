
/*
 *  Functional Composites/Collectors/Chrono Scheduling <https://github.com/Naios/FnC-Cpp>
 *
 *  Copyright (C) 2015 Naios <naios-dev@live.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _FUNCTIONAL_COLLECTORS_HPP_
#define _FUNCTIONAL_COLLECTORS_HPP_

#include <type_traits>
#include <functional>

namespace fnc
{
    template <typename T>
    using Collector = std::function<typename std::decay<T>::type(
        typename std::decay<T>::type const&, typename std::decay<T>::type const&)>;

    template<typename T>
    struct DropCollector : public std::binary_function<T, T, bool>
    {
        T operator()(T const& left, T const& /*right*/) const
        {
            return left;
        }
    };
}

#endif // _FUNCTIONAL_COLLECTORS_HPP_
