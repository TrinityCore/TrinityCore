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
#include "TSStringConvert.h"

#define _CM_ ,
#define _TN_ typename
#define _ST_ ToStr

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

  LOG(_TN_ A, A a, _ST_(a))

    LOG(_TN_ A _CM_ _TN_ B, A a _CM_ B b, _ST_(a) << " " << _ST_(b))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C, A a _CM_ B b _CM_ C c, _ST_(a) << " " << _ST_(b) << " " << _ST_(c))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D, A a _CM_ B b _CM_ C c _CM_ D d, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D _CM_ _TN_ E, A a _CM_ B b _CM_ C c _CM_ D d _CM_ E e, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d) << " " << _ST_(e))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D _CM_ _TN_ E _CM_ _TN_ F, A a _CM_ B b _CM_ C c _CM_ D d _CM_ E e _CM_ F f, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d) << " " << _ST_(e) << " " << _ST_(f))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D _CM_ _TN_ E _CM_ _TN_ F _CM_ _TN_ G, A a _CM_ B b _CM_ C c _CM_ D d _CM_ E e _CM_ F f _CM_ G g, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d) << " " << _ST_(e) << " " << _ST_(f) << " " << _ST_(g))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D _CM_ _TN_ E _CM_ _TN_ F _CM_ _TN_ G _CM_ _TN_ H, A a _CM_ B b _CM_ C c _CM_ D d _CM_ E e _CM_ F f _CM_ G g _CM_ H h, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d) << " " << _ST_(e) << " " << _ST_(f) << " " << _ST_(g) << " " << _ST_(h))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D _CM_ _TN_ E _CM_ _TN_ F _CM_ _TN_ G _CM_ _TN_ H _CM_ _TN_ I, A a _CM_ B b _CM_ C c _CM_ D d _CM_ E e _CM_ F f _CM_ G g _CM_ H h _CM_ I i, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d) << " " << _ST_(e) << " " << _ST_(f) << " " << _ST_(g) << " " << _ST_(h) << " " << _ST_(i))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D _CM_ _TN_ E _CM_ _TN_ F _CM_ _TN_ G _CM_ _TN_ H _CM_ _TN_ I _CM_ _TN_ J, A a _CM_ B b _CM_ C c _CM_ D d _CM_ E e _CM_ F f _CM_ G g _CM_ H h _CM_ I i _CM_ J j, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d) << " " << _ST_(e) << " " << _ST_(f) << " " << _ST_(g) << " " << _ST_(h) << " " << _ST_(i) << " " << _ST_(j))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D _CM_ _TN_ E _CM_ _TN_ F _CM_ _TN_ G _CM_ _TN_ H _CM_ _TN_ I _CM_ _TN_ J _CM_ _TN_ K, A a _CM_ B b _CM_ C c _CM_ D d _CM_ E e _CM_ F f _CM_ G g _CM_ H h _CM_ I i _CM_ J j _CM_ K k, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d) << " " << _ST_(e) << " " << _ST_(f) << " " << _ST_(g) << " " << _ST_(h) << " " << _ST_(i) << " " << _ST_(j) << " " << _ST_(k))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D _CM_ _TN_ E _CM_ _TN_ F _CM_ _TN_ G _CM_ _TN_ H _CM_ _TN_ I _CM_ _TN_ J _CM_ _TN_ K _CM_ _TN_ L, A a _CM_ B b _CM_ C c _CM_ D d _CM_ E e _CM_ F f _CM_ G g _CM_ H h _CM_ I i _CM_ J j _CM_ K k _CM_ L l, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d) << " " << _ST_(e) << " " << _ST_(f) << " " << _ST_(g) << " " << _ST_(h) << " " << _ST_(i) << " " << _ST_(j) << " " << _ST_(k) << " " << _ST_(l))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D _CM_ _TN_ E _CM_ _TN_ F _CM_ _TN_ G _CM_ _TN_ H _CM_ _TN_ I _CM_ _TN_ J _CM_ _TN_ K _CM_ _TN_ L _CM_ _TN_ M, A a _CM_ B b _CM_ C c _CM_ D d _CM_ E e _CM_ F f _CM_ G g _CM_ H h _CM_ I i _CM_ J j _CM_ K k _CM_ L l _CM_ M m, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d) << " " << _ST_(e) << " " << _ST_(f) << " " << _ST_(g) << " " << _ST_(h) << " " << _ST_(i) << " " << _ST_(j) << " " << _ST_(k) << " " << _ST_(l) << " " << _ST_(m))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D _CM_ _TN_ E _CM_ _TN_ F _CM_ _TN_ G _CM_ _TN_ H _CM_ _TN_ I _CM_ _TN_ J _CM_ _TN_ K _CM_ _TN_ L _CM_ _TN_ M _CM_ _TN_ N, A a _CM_ B b _CM_ C c _CM_ D d _CM_ E e _CM_ F f _CM_ G g _CM_ H h _CM_ I i _CM_ J j _CM_ K k _CM_ L l _CM_ M m _CM_ N n, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d) << " " << _ST_(e) << " " << _ST_(f) << " " << _ST_(g) << " " << _ST_(h) << " " << _ST_(i) << " " << _ST_(j) << " " << _ST_(k) << " " << _ST_(l) << " " << _ST_(m) << " " << _ST_(n))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D _CM_ _TN_ E _CM_ _TN_ F _CM_ _TN_ G _CM_ _TN_ H _CM_ _TN_ I _CM_ _TN_ J _CM_ _TN_ K _CM_ _TN_ L _CM_ _TN_ M _CM_ _TN_ N _CM_ _TN_ O, A a _CM_ B b _CM_ C c _CM_ D d _CM_ E e _CM_ F f _CM_ G g _CM_ H h _CM_ I i _CM_ J j _CM_ K k _CM_ L l _CM_ M m _CM_ N n _CM_ O o, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d) << " " << _ST_(e) << " " << _ST_(f) << " " << _ST_(g) << " " << _ST_(h) << " " << _ST_(i) << " " << _ST_(j) << " " << _ST_(k) << " " << _ST_(l) << " " << _ST_(m) << " " << _ST_(n) << " " << _ST_(o))

    LOG(_TN_ A _CM_ _TN_ B _CM_ _TN_ C _CM_ _TN_ D _CM_ _TN_ E _CM_ _TN_ F _CM_ _TN_ G _CM_ _TN_ H _CM_ _TN_ I _CM_ _TN_ J _CM_ _TN_ K _CM_ _TN_ L _CM_ _TN_ M _CM_ _TN_ N _CM_ _TN_ O _CM_ _TN_ P, A a _CM_ B b _CM_ C c _CM_ D d _CM_ E e _CM_ F f _CM_ G g _CM_ H h _CM_ I i _CM_ J j _CM_ K k _CM_ L l _CM_ M m _CM_ N n _CM_ O o _CM_ P p, _ST_(a) << " " << _ST_(b) << " " << _ST_(c) << " " << _ST_(d) << " " << _ST_(e) << " " << _ST_(f) << " " << _ST_(g) << " " << _ST_(h) << " " << _ST_(i) << " " << _ST_(j) << " " << _ST_(k) << " " << _ST_(l) << " " << _ST_(m) << " " << _ST_(n) << " " << _ST_(o) << " " << _ST_(p))
} console;
