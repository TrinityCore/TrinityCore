
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

#ifndef _FUNCTIONAL_ALIAS_HPP_
#define _FUNCTIONAL_ALIAS_HPP_

#include <functional>

namespace fnc
{
    template <typename T>
    using Supplier = std::function<T()>;

    using Callable = Supplier<void>;

    template <typename T>
    using Consumer = std::function<void(T)>;

    template <typename T>
    using Predicate = std::function<bool(T)>;   
}

#endif // _FUNCTIONAL_ALIAS_HPP_
