/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
 
#ifndef TRINITY_RANGEITERATORS_H
#define TRINITY_RANGEITERATORS_H

#include "advstd.h"

namespace Trinity
{

    namespace Impl
    {
        struct NoPredicateType { template <typename T> bool operator()(T const&) const { return true; } };
        struct NoProcessingType { template <typename T> auto operator()(T v) const { return v; } };
        
        template <class IteratorType, class EndType, class Predicate, class Processor>
        struct ProcessedRangePair
        {
            public:
                struct Iterator
                {
                    public:
                        using iterator_category = std::forward_iterator_tag;
                        using value_type = advstd::remove_cvref_t<std::remove_pointer_t<decltype(std::declval<Processor>()(*std::declval<IteratorType>()))>>;
                        using pointer = value_type const*;
                        using reference = value_type const&;
                        using difference_type = void;

                        Iterator(IteratorType it, EndType end, Predicate pred, Processor proc)
                            : _it(it), _end(end), _pred(pred), _proc(proc)
                        {
                            skipInvalid();
                        }

                        bool operator==(Iterator const& other) const { return _it == other._it; }
                        bool operator!=(Iterator const& other) const { return _it != other._it; }
                        bool operator!=(nullptr_t) const { return _it != _end; }

                        Iterator& operator++() { ++_it; skipInvalid(); return *this; }
                        Iterator operator++(int) { Iterator t = *this; ++*this; return t; }

                        auto operator*() const { return _proc(*_it); }

                    private:
                        void skipInvalid() { while ((_it != _end) && !_pred(_proc(*_it))) ++_it; }
                        IteratorType _it;
                        EndType _end;
                        Predicate _pred;
                        Processor _proc;
                };

                ProcessedRangePair(IteratorType it, EndType end, Predicate pred, Processor proc)
                    : _it(it), _end(end), _pred(pred), _proc(proc) {}

                Iterator begin() const { return { _it, _end, _pred, _proc }; }
                auto end() const { return Iterator({ _end, _end, _pred, _proc }); } // @todo replace with return nullptr in c++17!

            private:
                IteratorType const _it;
                EndType const _end;
                Predicate const _pred;
                Processor const _proc;
        };
    }
    
    constexpr Impl::NoPredicateType NoPredicate = Impl::NoPredicateType();
    constexpr Impl::NoProcessingType NoProcessing = Impl::NoProcessingType();

    template <typename IteratorType, typename EndType, typename Predicate, typename Processor>
    auto FilteredProcessedRange(IteratorType begin, EndType end, Predicate pred, Processor proc)
    {
        return Impl::ProcessedRangePair<IteratorType, EndType, Predicate, Processor>(begin, end, pred, proc);
    }

    template <typename ContainerType, typename Predicate, typename Processor>
    auto FilteredProcessedRange(ContainerType& c, Predicate pred, Processor proc)
    {
        return FilteredProcessedRange(std::begin(c), std::end(c), pred, proc);
    }

    template <typename IteratorType, typename EndType, typename Predicate>
    auto FilteredRange(IteratorType begin, EndType end, Predicate pred)
    {
        return FilteredProcessedRange(begin, end, pred, NoProcessing);
    }

    template <typename ContainerType, typename Predicate>
    auto FilteredRange(ContainerType& c, Predicate pred)
    {
        return FilteredRange(std::begin(c), std::end(c), pred);
    }
    
    template <typename IteratorType, typename EndType, typename Processor>
    auto ProcessedRange(IteratorType begin, EndType end, Processor proc)
    {
        return FilteredProcessedRange(begin, end, NoPredicate, proc);
    }

    template <typename ContainerType, typename Processor>
    auto ProcessedRange(ContainerType& c, Processor proc)
    {
        return ProcessedRange(std::begin(c), std::end(c), proc);
    }
}

#endif
