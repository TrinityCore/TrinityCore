
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

#ifndef _FUNCTIONAL_COMPOSITE_HPP_
#define _FUNCTIONAL_COMPOSITE_HPP_

#include "functional_composite_detail.hpp"
#include "functional_alias.hpp"
#include "functional_unwrap.hpp"

namespace fnc
{
    // An unordered FunctionComposite that supports insertion and deletion of actions.
    // Actions are called in an unordered way!
    // Only 1 action can occur once per handle
    template<typename Function = Callable, typename Handle = unsigned long>
    using FunctionComposite = detail::FunctionCompositeBase <
        detail::modifyable_function_composite_tag,
        std::tuple<typename std::unordered_map<Handle, typename unwrap_function<Function>::function_type>>,
        typename unwrap_function<Function>::return_type,
        typename unwrap_function<Function>::argument_type > ;

    // An unordered FunctionComposite that supports insertion and deletion of actions.
    // Actions are called in an unordered way!
    // Multiple actions can occur per handle
    template<typename Function = Callable, typename Handle = unsigned long>
    using MultiFunctionComposite = detail::FunctionCompositeBase <
        detail::modifyable_function_composite_tag,
        std::tuple<typename std::unordered_multimap<Handle, typename unwrap_function<Function>::function_type>>,
        typename unwrap_function<Function>::return_type,
        typename unwrap_function<Function>::argument_type > ;

    // An FunctionComposite that supports insertion of actions.
    // Deletion is not supported unless you want to clear all actions.
    // Actions are invoked how it were added.
    template<typename Function = Callable>
    using SimpleFunctionComposite = detail::FunctionCompositeBase <
        detail::simple_function_composite_tag,
        std::tuple<>,
        typename unwrap_function<Function>::return_type,
        typename unwrap_function<Function>::argument_type > ;
}

#endif // _FUNCTIONAL_COMPOSITE_HPP_
