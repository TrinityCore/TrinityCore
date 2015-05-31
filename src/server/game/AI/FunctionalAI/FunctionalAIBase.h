/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef FunctionalAIBase_h__
#define FunctionalAIBase_h__

#include "fnc/functional_composite.hpp"

#include <memory>

template<typename _Return>
struct checked_function;

template<typename _Return, typename... _Args>
struct checked_function<_Return(_Args...)>
    : public std::function<_Return(_Args...)>
{
    template<typename T,
    class = typename std::enable_if<
        std::is_same<_Return, void>::value
        || std::is_convertible<
        decltype(std::declval<T>()(std::declval<_Args>()...)),
        _Return>::value>::type>
        checked_function(T&& function) : std::function<_Return(_Args...)>(std::forward<T>(function)) { }
};

template<typename T>
class PreparedEvent
{
public:
    typedef fnc::Consumer<T&> listener_t;

private:
    listener_t const _listener;
    uint32 const _group;

public:
    PreparedEvent(checked_function<void(T&)> const& listener)
        : _listener(listener), _group(0) { }
    PreparedEvent(uint32 const group, checked_function<void(T&)> const& listener)
        : _listener(listener), _group(group) { }

    listener_t const& GetListener() const
    {
        return _listener;
    }

    uint32 GetGroup() const
    {
        return _group;
    }
};

template <typename T>
class EmptyOptimizedListener
{
    typedef fnc::MultiFunctionComposite<fnc::Consumer<T&>, uint32> composite_t;

    std::unique_ptr<composite_t> _listener;

    inline void InitializeIfNecessary()
    {
        if (!_listener)
            _listener.reset(new composite_t());
    }

public:
    EmptyOptimizedListener() { }

    void AddListener(typename composite_t::function_t const& listener)
    {
        InitializeIfNecessary();
        _listener->Add(listener);
    }

    void AddListener(uint32 const group, typename composite_t::function_t const& listener)
    {
        InitializeIfNecessary();
        _listener->Add(group, listener);
    }

    void AddListener(PreparedEvent<T> const& preparedEvent)
    {
        InitializeIfNecessary();
        _listener->Add(preparedEvent.GetGroup(), preparedEvent.GetListener());
    }

    void RemoveAllListeners()
    {
        if (_listener)
            _listener->Clear();
    }

    void RemoveListener(uint32 const group)
    {
        if (_listener)
            _listener->Remove(group);
    }

    void Invoke(T& event)
    {
        if (_listener)
            _listener->Invoke(event);
    }
};

#define DEFINE_HOOK(ME, EVENT) \
    private: \
        EmptyOptimizedListener<EVENT> _##EVENT; \
    public: \
        ME* AddListener(checked_function<void(EVENT&)> const& listener) \
        { \
            _##EVENT.AddListener(listener);\
            return this; \
        } \
        ME* AddListener(uint32 const group, checked_function<void(EVENT&)> const& listener) \
        { \
            _##EVENT.AddListener(group, listener); \
            return this; \
        } \
        ME* AddListener(PreparedEvent<EVENT> const& preparedEvent) \
        { \
            _##EVENT.AddListener(preparedEvent.GetGroup(), preparedEvent.GetListener()); \
            return this; \
        } \
        ME* RemoveAll##EVENT##Listeners() \
        { \
            _##EVENT.RemoveAllListeners(); \
            return this; \
        } \
        ME* Remove##EVENT##Listeners(uint32 const group) \
        { \
            _##EVENT.RemoveListener(group); \
            return this; \
        }

#endif // FunctionalAIBase_h__
