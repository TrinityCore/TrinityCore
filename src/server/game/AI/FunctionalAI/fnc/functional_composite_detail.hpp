
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

#ifndef _FUNCTIONAL_COMPOSITE_DETAIL_HPP_
#define _FUNCTIONAL_COMPOSITE_DETAIL_HPP_

#include <vector>
#include <unordered_map>
#include <functional>
#include <type_traits>
#include <iterator>
#include <utility>

#include "functional_collectors.hpp"
#include "functional_alias.hpp"
#include "functional_composite_utility.hpp"

namespace fnc
{
    namespace detail
    {
        // Actions are only allowed to be inserted or cleared
        struct simple_function_composite_tag { };

        // Full support to add and remove single actions
        struct modifyable_function_composite_tag { };

        template <typename _Iterator>
        class ValueIterator
            : public std::iterator < std::forward_iterator_tag, typename _Iterator::value_type::second_type >
        {
        public:
            ValueIterator(_Iterator const& other) : _iterator(other) { }
            ValueIterator& operator++() { ++_iterator; return *this; }

            bool operator==(ValueIterator const& other) const { return _iterator == other._iterator; }
            bool operator!=(ValueIterator const& other) const { return !(*this == other); }

            // TODO: value_type is also possible but clang is complaining
            typename _Iterator::value_type::second_type const&
                operator*() const { return _iterator->second; }

            // TODO: pointer is also possible but clang is complaining
            typename _Iterator::value_type::second_type*
                operator->() const { return &_iterator->second; }

        private:
            _Iterator _iterator;
        };

        template <class Tag, typename Result, typename... Args>
        class FunctionCompositeImpl;

        template <typename Info, typename Result, typename... Args>
        class FunctionCompositeImpl < simple_function_composite_tag, Info, Result, Args... >
        {
            typedef typename std::function<Result(Args...)> function_t;

            typedef typename std::vector<function_t> function_holder_t;

            function_holder_t _function_holder;

        protected:
            FunctionCompositeImpl() : _function_holder() { }

            FunctionCompositeImpl(FunctionCompositeImpl const& right) : _function_holder(right._function_holder) { }

            FunctionCompositeImpl(FunctionCompositeImpl&& right) : _function_holder(std::move(right._function_holder)) { }

        public:
            typedef typename function_holder_t::const_iterator const_iterator;

            inline bool IsEmpty() { return _function_holder.empty(); }

            FunctionCompositeImpl& LazyAdd(function_t const& action)
            {
                _function_holder.push_back(action);
                return *this;
            }

            FunctionCompositeImpl& LazyAdd(function_t&& action)
            {
                _function_holder.push_back(std::forward<function_t>(action));
                return *this;
            }

            FunctionCompositeImpl& operator+=(function_t const& action) { return LazyAdd(action); }

            inline void Clear() { _function_holder.clear(); }

        protected:
            const_iterator begin() { return _function_holder.begin(); }

            const_iterator end() { return _function_holder.end(); }
        };

        template <typename _Container, typename Result, typename... Args>
        class FunctionCompositeImpl < modifyable_function_composite_tag, std::tuple<_Container>, Result, Args... >
        {
            static_assert(std::is_integral<typename _Container::key_type>::value, "Handle is not an integral type!");

        public:
            typedef typename std::function<Result(Args...)> function_t;

            typedef typename _Container::key_type handle_t;

        private:
            typedef _Container function_holder_t;

            function_holder_t _function_holder;

            handle_t _handle;

        protected:
            FunctionCompositeImpl()
                : _function_holder(), _handle(1000) {}

            FunctionCompositeImpl(handle_t const& handle_start)
                : _function_holder(), _handle(handle_start) {}

            FunctionCompositeImpl(FunctionCompositeImpl const& right)
                : _function_holder(right._function_holder), _handle(right.handle) { }

            FunctionCompositeImpl(FunctionCompositeImpl&& right)
                : _function_holder(std::move(right._function_holder)), _handle(std::move(right.handle)) { }

        public:
            typedef ValueIterator<typename function_holder_t::const_iterator> const_iterator;

            inline bool IsEmpty() { return _function_holder.empty(); }

            // Default implementation
            inline handle_t Add(handle_t const& handle, function_t const& action)
            {
                _function_holder.insert(std::make_pair(handle, action));
                return handle;
            }

            inline handle_t Add(function_t const& action) { return Add(_handle++, action); }

            inline handle_t Add(handle_t const& handle, function_t&& action)
            {
                _function_holder.insert(std::make_pair(handle, std::forward<function_t>(action)));
                return handle;
            }

            inline handle_t Add(function_t&& action) { return Add(_handle++, std::forward<function_t>(action)); }

            FunctionCompositeImpl& LazyAdd(handle_t const& handle, function_t const& action)
            {
                Add(handle, action);
                return *this;
            }

            FunctionCompositeImpl& LazyAdd(function_t const& action)
            {
                Add(action);
                return *this;
            }

            FunctionCompositeImpl& LazyAdd(handle_t const& handle, function_t&& action)
            {
                Add(handle, std::forward<function_t>(action));
                return *this;
            }

            FunctionCompositeImpl& LazyAdd(function_t&& action)
            {
                Add(std::forward<function_t>(action)); return *this;
            }

            FunctionCompositeImpl& operator+=(function_t const& action) { return LazyAdd(action); }

            bool Remove(handle_t const& handle)
            {
                return make_bool(_function_holder.erase(handle));
            }

            FunctionCompositeImpl& LazyRemove(handle_t const& handle)
            {
                erase(handle);
                return *this;
            }

            FunctionCompositeImpl& operator-=(handle_t const& handle) { return LazyRemove(handle); }

            inline void Clear() { _function_holder.clear(); }

        protected:
            const_iterator begin() { return const_iterator(_function_holder.begin()); }

            const_iterator end() const { return const_iterator(_function_holder.end()); }
        };

        template<class Tag, typename Info, typename ResultType, typename ArgsType>
        class FunctionCompositeBase;

        // Implementation for void return types
        template<class Tag, typename Info, typename... Args>
        class FunctionCompositeBase < Tag, Info, void, std::tuple<Args...> >
            : public FunctionCompositeImpl < Tag, Info, void, Args... >
        {
        public:
            FunctionCompositeBase()
                : FunctionCompositeImpl<Tag, Info, void, Args...>() {}
            FunctionCompositeBase(FunctionCompositeBase const& right)
                : FunctionCompositeImpl<Tag, Info, void, Args...>(right) {}

            // TODO Add move constructor

            void Invoke(Args const&... args)
            {
                for (auto const& action : *this)
                    action(args...);
            }

            void operator()(Args const&... args) { Invoke(args...); }
        };

        // Implementation for other return types (including collector support)
        template<class Tag, typename Info, typename Result, typename... Args>
        class FunctionCompositeBase < Tag, Info, Result, std::tuple<Args...> >
            : public FunctionCompositeImpl < Tag, Info, Result, Args... >
        {
        public:
            typedef Collector<Result> collector_function;

            typedef typename std::decay<Result>::type result_t;

        private:
            // Collector function to collect results from action calls
            collector_function _collector;

            // At begin of collection it uses this default value
            Result _initial_collected_value;

        public:
            // Default constructor
            FunctionCompositeBase()
                : _collector(DropCollector<result_t>()),
                _initial_collected_value(default_value_of<Result>::get()),
                FunctionCompositeImpl<Tag, Info, Result, Args...>() { }

            // Use a collector, extract it from binary operators or std::functions
            FunctionCompositeBase(collector_function const& collector)
                : _collector(collector),
                _initial_collected_value(default_value_of<Result>::get()),
                FunctionCompositeImpl<Tag, Info, Result, Args...>() { }

            // Use a collector and a default value for collection phase
            FunctionCompositeBase(collector_function const& collector, result_t const& default_collector_value)
                : _collector(collector),
                _initial_collected_value(default_collector_value),
                FunctionCompositeImpl<Tag, Info, Result, Args...>() { }

            // Move a collector into this FunctionComposite
            FunctionCompositeBase(Collector<Result>&& collector)
                : _collector(std::forward<Collector<Result>>(collector)),
                _initial_collected_value(default_value_of<Result>::get()),
                FunctionCompositeImpl<Tag, Info, Result, Args...>() { }

            // Copy an FunctionComposite into this
            FunctionCompositeBase(FunctionCompositeBase const& right)
                : _collector(right._collector),
                _initial_collected_value(right._initial_collected_value),
                FunctionCompositeImpl<Tag, Info, Result, Args...>(right) { }

            // TODO Add move constructor

            collector_function GetCollector() const { return _collector; }
            void SetCollector(collector_function const& collector) { _collector = collector; }
            void SetCollector(collector_function&& collector) { _collector = std::forward(collector); }

            result_t GetDefaultCollectorValue() const { return _initial_collected_value; }
            void SetDefaultCollectorValue(result_t const& initial_collected_value) { _initial_collected_value = initial_collected_value; }

            result_t Invoke(Args const&... args)
            {
                Result r = _initial_collected_value;
                for (auto const& action : *this)
                  r = std::move(_collector(r, action(args...)));

                return r;
            }

            Result operator()(Args const&... args) { return Invoke(args...); }
        };
    }
}

#endif // _FUNCTIONAL_COMPOSITE_DETAIL_HPP_
