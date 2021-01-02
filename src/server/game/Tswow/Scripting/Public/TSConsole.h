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

#define _COMMA_ ,

#ifdef UNICODE
#define LOG(targs,args,ops) template < targs > \
    void log(args) {\
        std::cout << ops << std::endl; \
    } \
    template < targs > \
    void warn(args) {\
        std::clog << ops << std::endl; \
    } \
    template < targs > \
    void error(args) { \
        std::cerr << ops << std::endl; \
    } \
    template < targs > \
    void debug(args) { \
        std::clog << ops << std::endl; \
    }
#else
#define LOG(targs,args,ops) template < targs > \
    void log(args) {\
        std::wcout << ops << std::endl; \
    } \
    template < targs > \
    void warn(args) {\
        std::wclog << ops << std::endl; \
    } \
    template < targs > \
    void error(args) { \
        std::wcerr << ops << std::endl; \
    } \
    template < targs > \
    void debug(args) { \
        std::wclog << ops << std::endl; \
    }
#endif

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

    LOG(typename A, A a, a)

        LOG(typename A _COMMA_ typename B, A a _COMMA_ B b, a << " " << b)

        LOG(typename A _COMMA_ typename B _COMMA_ typename C, A a _COMMA_ B b _COMMA_ C c, a << " " << b << " " << c)

        LOG(typename A _COMMA_ typename B _COMMA_ typename C _COMMA_ typename D, A a _COMMA_ B b _COMMA_ C c _COMMA_ D d, a << " " << b << " " << c << " " << d)

        LOG(typename A _COMMA_ typename B _COMMA_ typename C _COMMA_ typename D _COMMA_ typename E, A a _COMMA_ B b _COMMA_ C c _COMMA_ D d _COMMA_ E e, a << " " << b << " " << c << " " << d << " " << e)

        LOG(typename A _COMMA_ typename B _COMMA_ typename C _COMMA_ typename D _COMMA_ typename E _COMMA_ typename F, A a _COMMA_ B b _COMMA_ C c _COMMA_ D d _COMMA_ E e _COMMA_ F f, a << " " << b << " " << c << " " << d << " " << e << " " << f)

        LOG(typename A _COMMA_ typename B _COMMA_ typename C _COMMA_ typename D _COMMA_ typename E _COMMA_ typename F _COMMA_ typename G, A a _COMMA_ B b _COMMA_ C c _COMMA_ D d _COMMA_ E e _COMMA_ F f _COMMA_ G g, a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g)

        LOG(typename A _COMMA_ typename B _COMMA_ typename C _COMMA_ typename D _COMMA_ typename E _COMMA_ typename F _COMMA_ typename G _COMMA_ typename H, A a _COMMA_ B b _COMMA_ C c _COMMA_ D d _COMMA_ E e _COMMA_ F f _COMMA_ G g _COMMA_ H h, a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h)

        LOG(typename A _COMMA_ typename B _COMMA_ typename C _COMMA_ typename D _COMMA_ typename E _COMMA_ typename F _COMMA_ typename G _COMMA_ typename H _COMMA_ typename I, A a _COMMA_ B b _COMMA_ C c _COMMA_ D d _COMMA_ E e _COMMA_ F f _COMMA_ G g _COMMA_ H h _COMMA_ I i, a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i)

        LOG(typename A _COMMA_ typename B _COMMA_ typename C _COMMA_ typename D _COMMA_ typename E _COMMA_ typename F _COMMA_ typename G _COMMA_ typename H _COMMA_ typename I _COMMA_ typename J, A a _COMMA_ B b _COMMA_ C c _COMMA_ D d _COMMA_ E e _COMMA_ F f _COMMA_ G g _COMMA_ H h _COMMA_ I i _COMMA_ J j, a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j)

        LOG(typename A _COMMA_ typename B _COMMA_ typename C _COMMA_ typename D _COMMA_ typename E _COMMA_ typename F _COMMA_ typename G _COMMA_ typename H _COMMA_ typename I _COMMA_ typename J _COMMA_ typename K, A a _COMMA_ B b _COMMA_ C c _COMMA_ D d _COMMA_ E e _COMMA_ F f _COMMA_ G g _COMMA_ H h _COMMA_ I i _COMMA_ J j _COMMA_ K k, a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << " " << k)

        LOG(typename A _COMMA_ typename B _COMMA_ typename C _COMMA_ typename D _COMMA_ typename E _COMMA_ typename F _COMMA_ typename G _COMMA_ typename H _COMMA_ typename I _COMMA_ typename J _COMMA_ typename K _COMMA_ typename L, A a _COMMA_ B b _COMMA_ C c _COMMA_ D d _COMMA_ E e _COMMA_ F f _COMMA_ G g _COMMA_ H h _COMMA_ I i _COMMA_ J j _COMMA_ K k _COMMA_ L l, a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << " " << k << " " << l)

        LOG(typename A _COMMA_ typename B _COMMA_ typename C _COMMA_ typename D _COMMA_ typename E _COMMA_ typename F _COMMA_ typename G _COMMA_ typename H _COMMA_ typename I _COMMA_ typename J _COMMA_ typename K _COMMA_ typename L _COMMA_ typename M, A a _COMMA_ B b _COMMA_ C c _COMMA_ D d _COMMA_ E e _COMMA_ F f _COMMA_ G g _COMMA_ H h _COMMA_ I i _COMMA_ J j _COMMA_ K k _COMMA_ L l _COMMA_ M m, a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << " " << k << " " << l << " " << m)
} console;
