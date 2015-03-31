
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

#ifndef _FUNCTIONAL_COMPOSITE_UTILITY_HPP_
#define _FUNCTIONAL_COMPOSITE_UTILITY_HPP_

#include <type_traits>
#include <functional>
#include <tuple>

namespace fnc
{
    namespace detail
    {
        template <typename T, bool is_integral>
        struct default_value_of_trivial_impl
        {
            static T get()
            {
                return T();
            }
        };

        template <typename T>
        struct default_value_of_trivial_impl < T, true >
        {
            static T get()
            {
                T t = 0;
                return t;
            }
        };

        template <typename T>
        struct default_value_of
        {
            static T get()
            {
                return default_value_of_trivial_impl<T, std::is_integral<T>::value>::get();
            }
        };

        template <typename T>
        inline bool make_bool(T const b)
        {
            return b ? true : false;
        }

        template <>
        inline bool make_bool<bool>(bool const b)
        {
            return b;
        }

    } // detail

} // fnc

#endif // _FUNCTIONAL_COMPOSITE_UTILITY_HPP_
