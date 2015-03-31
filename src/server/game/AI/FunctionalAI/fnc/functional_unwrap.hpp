
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

#ifndef _FUNCTIONAL_UNWRAP_HPP_
#define _FUNCTIONAL_UNWRAP_HPP_

namespace fnc
{
    /// Trait to unwrap function parameters of following types:
    /// Function style definition: Result(Parameters...)
    /// STL `std::function` : std::function<Result(Parameters...)>
    /// STL `std::tuple` : std::tuple<Result, Parameters...>
    /// C++ Function pointers: `Result(*)(Parameters...)`
    /// C++ Class method pointers: `Result(Class::*)(Parameters...)`
    template<typename Function>
    struct unwrap_function;

    template<typename _RTy, typename... _ATy>
    struct unwrap_function<_RTy(_ATy...)>
    {
        /// The return type of the function.
        typedef _RTy return_type;

        /// The argument types of the function as pack in std::tuple.
        typedef std::tuple<_ATy...> argument_type;

        /// The function provided as std::function
        typedef std::function<_RTy(_ATy...)> function_type;

        /// The function provided as function_ptr
        typedef _RTy(*function_ptr)(_ATy...);
    };

    /// STL: std::function
    template<typename _RTy, typename... _ATy>
    struct unwrap_function<std::function<_RTy(_ATy...)>>
        : unwrap_function<_RTy(_ATy...)> { };

    /// STL: std::tuple
    template<typename _RTy, typename... _ATy>
    struct unwrap_function<std::tuple<_RTy, _ATy...>>
        : unwrap_function<_RTy(_ATy...)> { };

    /// Function pointers
    template<typename _RTy, typename... _ATy>
    struct unwrap_function<_RTy(*const)(_ATy...)>
        : unwrap_function<_RTy(_ATy...)> { };

    /// Class Method pointers
    template<typename _CTy, typename _RTy, typename... _ATy>
    struct unwrap_function<_RTy(_CTy::*)(_ATy...) const>
        : unwrap_function<_RTy(_ATy...)> { };

    // Helper
    template<typename Function>
    using return_type_t = typename unwrap_function<Function>::return_type;

    template<typename Function>
    using argument_type_t = typename unwrap_function<Function>::argument_type;

    template<typename Function>
    using function_type_t = typename unwrap_function<Function>::function_type;

    template<typename Function>
    using function_ptr_t = typename unwrap_function<Function>::function_ptr;

    // Tries to unwrap the function through the () operator.
    template <typename Function>
    struct operator_unwrap
        : public unwrap_function<decltype(&Function::operator())> { };
} // fnc

#endif // _FUNCTIONAL_UNWRAP_HPP_
