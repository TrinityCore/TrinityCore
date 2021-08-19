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

#ifndef HACKS_boost_1_74_fibonacci_heap_h__
#define HACKS_boost_1_74_fibonacci_heap_h__

#include "CompilerDefs.h"
#include <boost/version.hpp>

#if TRINITY_COMPILER == TRINITY_COMPILER_MICROSOFT && BOOST_VERSION == 107400
#define BOOST_1_74_FIBONACCI_HEAP_MSVC_COMPILE_FIX(T)                                           \
namespace boost { namespace heap { namespace detail                                             \
{                                                                                               \
    template<class Node>                                                                        \
    void destroy_node(Node& node)                                                               \
    {                                                                                           \
        node.~Node();                                                                           \
    }                                                                                           \
                                                                                                \
    template <>                                                                                 \
    struct node_disposer<boost::heap::detail::heap_node<T, true>,                               \
        boost::heap::detail::heap_node_base<false>,                                             \
        std::allocator<boost::heap::detail::marked_heap_node<T>>>                               \
    {                                                                                           \
        using allocator = std::allocator<boost::heap::detail::marked_heap_node<T>>;             \
        using node_pointer = typename boost::allocator_pointer<allocator>::type;                \
                                                                                                \
        node_disposer(allocator& alloc) : _alloc(alloc)                                         \
        {                                                                                       \
        }                                                                                       \
                                                                                                \
        void operator()(boost::heap::detail::heap_node_base<false>* base)                       \
        {                                                                                       \
            node_pointer n = static_cast<node_pointer>(base);                                   \
            n->clear_subtree(_alloc);                                                           \
            destroy_node(*n); /* <- the change compared to default implementation */            \
            _alloc.deallocate(n, 1);                                                            \
        }                                                                                       \
                                                                                                \
        allocator& _alloc;                                                                      \
    };                                                                                          \
} } }
#else
#define BOOST_1_74_FIBONACCI_HEAP_MSVC_COMPILE_FIX(T)
#endif

#endif // HACKS_boost_1_74_fibonacci_heap_h__
