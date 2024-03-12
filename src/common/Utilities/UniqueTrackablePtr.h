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

#ifndef TRINITYCORE_UNIQUE_TRACKABLE_PTR_H
#define TRINITYCORE_UNIQUE_TRACKABLE_PTR_H

#include "Define.h"
#include <memory>

namespace Trinity
{
template <typename T, typename Deleter = std::default_delete<T>>
class unique_trackable_ptr;

template <typename T>
class unique_weak_ptr;

template <typename T>
class unique_strong_ref_ptr;

/**
 * \brief Specialized variant of std::shared_ptr that enforces unique ownership and/or std::unique_ptr with std::weak_ptr capabilities
 * Implementation has the same overhead as a std::shared_ptr, that is, a separate allocation for control block that holds use counters
 * \tparam T Type of held object
 * \tparam Deleter Object deleter (defaults to std::default_delete<T>)
 */
template <typename T, typename Deleter>
class unique_trackable_ptr
{
public:
    using element_type = T;
    using pointer = T*;
    using deleter_type = Deleter;

    unique_trackable_ptr() : _ptr(nullptr, deleter_type()) { }

    explicit unique_trackable_ptr(pointer ptr) : _ptr(ptr, deleter_type()) { }

    explicit unique_trackable_ptr(pointer ptr, deleter_type deleter) : _ptr(ptr, std::move(deleter)) { }

    unique_trackable_ptr(unique_trackable_ptr const&) = delete;

    unique_trackable_ptr(unique_trackable_ptr&& other) noexcept
        : _ptr(std::move(other._ptr)) { }

    unique_trackable_ptr& operator=(unique_trackable_ptr const&) = delete;

    unique_trackable_ptr& operator=(unique_trackable_ptr&& other) noexcept
    {
        _ptr = std::move(other._ptr);
        return *this;
    }

    ~unique_trackable_ptr() = default;

    unique_trackable_ptr& operator=(std::nullptr_t)
    {
        reset();
        return *this;
    }

    void swap(unique_trackable_ptr& other) noexcept
    {
        using std::swap;
        swap(_ptr, other._ptr);
    }

    element_type& operator*() const
    {
        return *_ptr;
    }

    pointer operator->() const
    {
        return _ptr.operator->();
    }

    pointer get() const
    {
        return _ptr.get();
    }

    explicit operator bool() const
    {
        return static_cast<bool>(_ptr);
    }

    void reset(pointer ptr = nullptr, deleter_type deleter = {})
    {
        _ptr.reset(ptr, std::move(deleter));
    }

private:
    template <typename T0>
    friend class unique_weak_ptr;

    template <typename T0, typename... Args>
    friend std::enable_if_t<!std::is_array_v<T0>, unique_trackable_ptr<T0>> make_unique_trackable(Args&&... args);

    template <typename T0>
    friend std::enable_if_t<std::is_unbounded_array_v<T0>, unique_trackable_ptr<T0>> make_unique_trackable(std::size_t N);

    template <typename T0>
    friend std::enable_if_t<std::is_unbounded_array_v<T0>, unique_trackable_ptr<T0>> make_unique_trackable(std::size_t N, std::remove_extent_t<T0> const& val);

    template <typename T0>
    friend std::enable_if_t<std::is_bounded_array_v<T0>, unique_trackable_ptr<T0>> make_unique_trackable();

    template <typename T0>
    friend std::enable_if_t<std::is_bounded_array_v<T0>, unique_trackable_ptr<T0>> make_unique_trackable(std::remove_extent_t<T0> const& val);

    std::shared_ptr<element_type> _ptr;
};

/**
 * \brief Trinity::unique_trackable_ptr companion class, replicating what std::weak_ptr is to std::shared_ptr
 * \tparam T Type of held object
 */
template <typename T>
class unique_weak_ptr
{
public:
    using element_type = T;
    using pointer = T*;

    unique_weak_ptr() = default;

    template<typename Deleter>
    unique_weak_ptr(unique_trackable_ptr<T, Deleter> const& trackable) : _ptr(trackable._ptr)
    {
    }

    unique_weak_ptr(unique_weak_ptr const& other) = default;
    unique_weak_ptr(unique_weak_ptr&& other) noexcept = default;

    template<typename Deleter>
    unique_weak_ptr& operator=(unique_trackable_ptr<T, Deleter> const& trackable)
    {
        _ptr = trackable._ptr;
        return *this;
    }

    unique_weak_ptr& operator=(unique_weak_ptr const& other) = default;
    unique_weak_ptr& operator=(unique_weak_ptr&& other) noexcept = default;

    ~unique_weak_ptr() = default;

    void swap(unique_weak_ptr& other) noexcept
    {
        using std::swap;
        swap(_ptr, other._ptr);
    }

    bool expired() const
    {
        return _ptr.expired();
    }

    unique_strong_ref_ptr<element_type> lock() const
    {
        return unique_strong_ref_ptr<element_type>(_ptr.lock());
    }

private:
    std::weak_ptr<element_type> _ptr;
};

/**
 * \brief Result of unique_weak_ptr::lock() function, this class holds a temporary strong reference to held object
 * to prevent it from being deallocated by another thread while it is being actively accessed.
 * This class is non-movable and non-copypable and is intended only for short lived local variables
 * \tparam T Type of held object
 */
template <typename T>
class unique_strong_ref_ptr
{
public:
    using element_type = T;
    using pointer = T*;

    unique_strong_ref_ptr(unique_strong_ref_ptr const&) = delete;
    unique_strong_ref_ptr(unique_strong_ref_ptr&&) = delete;
    unique_strong_ref_ptr& operator=(unique_strong_ref_ptr const&) = delete;
    unique_strong_ref_ptr& operator=(unique_strong_ref_ptr&&) = delete;

    ~unique_strong_ref_ptr() = default;

    element_type& operator*() const
    {
        return *_ptr;
    }

    pointer operator->() const
    {
        return _ptr.operator->();
    }

    pointer get() const
    {
        return _ptr.get();
    }

    explicit operator bool() const
    {
        return static_cast<bool>(_ptr);
    }

    friend std::strong_ordering operator<=>(unique_strong_ref_ptr const&, unique_strong_ref_ptr const&) = default;

private:
    template <typename T0>
    friend class unique_weak_ptr;

    unique_strong_ref_ptr(std::shared_ptr<element_type> ptr) : _ptr(std::move(ptr)) { }

    std::shared_ptr<element_type> _ptr;
};

template <typename T, typename... Args>
std::enable_if_t<!std::is_array_v<T>, unique_trackable_ptr<T>> make_unique_trackable(Args&&... args)
{
    unique_trackable_ptr<T> ptr;
    ptr._ptr = std::make_shared<T>(std::forward<Args>(args)...);
    return ptr;
}

template <typename T>
std::enable_if_t<std::is_unbounded_array_v<T>, unique_trackable_ptr<T>> make_unique_trackable(std::size_t N)
{
    unique_trackable_ptr<T> ptr;
    ptr._ptr = std::make_shared<T>(N);
    return ptr;
}

template <typename T>
std::enable_if_t<std::is_unbounded_array_v<T>, unique_trackable_ptr<T>> make_unique_trackable(std::size_t N, std::remove_extent_t<T> const& val)
{
    unique_trackable_ptr<T> ptr;
    ptr._ptr = std::make_shared<T>(N, val);
    return ptr;
}

template <typename T>
std::enable_if_t<std::is_bounded_array_v<T>, unique_trackable_ptr<T>> make_unique_trackable()
{
    unique_trackable_ptr<T> ptr;
    ptr._ptr = std::make_shared<T>();
    return ptr;
}

template <typename T>
std::enable_if_t<std::is_bounded_array_v<T>, unique_trackable_ptr<T>> make_unique_trackable(std::remove_extent_t<T> const& val)
{
    unique_trackable_ptr<T> ptr;
    ptr._ptr = std::make_shared<T>(val);
    return ptr;
}
}

#endif // TRINITYCORE_UNIQUE_TRACKABLE_PTR_H
