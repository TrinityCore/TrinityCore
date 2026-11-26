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

#ifndef TRINITYCORE_ADVSTD_STOP_TOKEN_H
#define TRINITYCORE_ADVSTD_STOP_TOKEN_H

#include <version>

#if !defined(_LIBCPP_VERSION) || _LIBCPP_VERSION >= 200000

#include <stop_token>

namespace advstd
{
using std::nostopstate;
using std::stop_token;
using std::stop_source;
}

#else

#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <atomic>
#include <utility>

namespace advstd
{
struct nostopstate_t
{
    explicit nostopstate_t() = default;
} inline constexpr nostopstate { };

// simplified stop state impl without support for std::stop_callback and stop_possible
class simple_stop_state
{
public:
    bool stop_requested() const noexcept { return _stopped.test(std::memory_order::acquire); }

    bool request_stop() noexcept { return _stopped.test_and_set(std::memory_order::release); }

private:
    friend void intrusive_ptr_add_ref(simple_stop_state* p);
    friend void intrusive_ptr_release(simple_stop_state* p);

    std::atomic_flag _stopped;
    std::atomic<std::int32_t> _refs;
};

inline void intrusive_ptr_add_ref(simple_stop_state* p)
{
    p->_refs.fetch_add(1, std::memory_order::acq_rel);
}

inline void intrusive_ptr_release(simple_stop_state* p)
{
    if (p->_refs.fetch_sub(1, std::memory_order::acq_rel) == 1)
        delete p;
}

class stop_token
{
public:
    stop_token() noexcept = default;
    stop_token(stop_token const& other) noexcept = default;
    stop_token(stop_token&& other) noexcept = default;
    stop_token& operator=(stop_token const& other) noexcept = default;
    stop_token& operator=(stop_token&& other) noexcept = default;
    ~stop_token() = default;

    void swap(stop_token& other) noexcept { _state.swap(other._state); }

    bool stop_requested() const noexcept { return _state != nullptr && _state->stop_requested(); }

    bool stop_possible() const noexcept = delete;

    friend bool operator==(stop_token const& left, stop_token const& right) noexcept = default;

    friend void swap(stop_token& left, stop_token& right) noexcept { left.swap(right); }

private:
    boost::intrusive_ptr<simple_stop_state> _state;

    friend class stop_source;
    explicit stop_token(boost::intrusive_ptr<simple_stop_state> const& state) : _state(state) { }
};

class stop_source
{
public:
    stop_source() : _state(new simple_stop_state()) { }
    explicit stop_source(nostopstate_t) noexcept { }
    stop_source(stop_source const& other) noexcept = default;
    stop_source(stop_source&& other) noexcept : _state(std::exchange(other._state, nullptr)) { }
    stop_source& operator=(stop_source const& other) noexcept = default;
    stop_source& operator=(stop_source&& other) noexcept { stop_source(std::move(other)).swap(*this); return *this; }
    ~stop_source() = default;

    void swap(stop_source& other) noexcept { _state.swap(other._state); }

    stop_token get_token() const noexcept { return stop_token(_state); }

    bool stop_requested() const noexcept { return _state != nullptr && _state->stop_requested(); }

    bool stop_possible() const noexcept = delete;

    bool request_stop() noexcept { return _state && _state->request_stop(); }

    friend bool operator==(stop_source const& left, stop_source const& right) noexcept = default;

    friend void swap(stop_source& left, stop_source& right) noexcept { left.swap(right); }

private:
    boost::intrusive_ptr<simple_stop_state> _state;
};
}
#endif

#endif // TRINITYCORE_ADVSTD_STOP_TOKEN_H
