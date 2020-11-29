/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include <iostream>
#include "TSArray.h"

template <typename I>
constexpr inline const char* pass(TSArray<I> i) {
    std::cout << "[";
    for (auto& g : i) {
        std::cout << g << ",";
    }
    std::cout << "]";
    return "";
}

template <typename I, class = std::enable_if_t<!std::is_enum_v<I>>>
constexpr inline I pass(I i) {
    return i;
}

template <typename I, class = std::enable_if_t<std::is_enum_v<I>>>
constexpr inline size_t pass(I i) {
    return static_cast<size_t>(i);
}

static struct Console
{
    Console()
    {
#ifdef UNICODE        
        std::wcout << std::boolalpha;
#else        
        std::cout << std::boolalpha;
#endif        
    }

    constexpr Console* operator->()
    {
        return this;
    }

    template <class... Args>
    void log(Args&&... args)
    {
#ifdef UNICODE        
        auto dummy = { (std::wcout << pass(args), 0)... };
        std::wcout << std::endl;
#else
        auto dummy = { (std::cout << pass(args), 0)... };
        std::cout << std::endl;
#endif        
    }

    template <class... Args>
    void warn(Args&&... args)
    {
#ifdef UNICODE 
        auto dummy = { (std::wclog << pass(args), 0)... };
        std::wclog << std::endl;
#else        
        auto dummy = { (std::clog << pass(args), 0)... };
        std::clog << std::endl;
#endif          
    }

    template <class... Args>
    void error(Args&&... args)
    {
#ifdef UNICODE 
        auto dummy = { (std::wcerr << pass(args), 0)... };
        std::wcerr << std::endl;
#else        
        auto dummy = { (std::cerr << pass(args), 0)... };
        std::cerr << std::endl;
#endif          
    }

    template <class... Args>
    void debug(Args&&... args)
    {
#ifdef UNICODE 
        auto dummy = { (std::wclog << pass(args), 0)... };
        std::wclog << std::endl;
#else        
        auto dummy = { (std::clog << pass(args), 0)... };
        std::clog << std::endl;
#endif          
    }
} console;
