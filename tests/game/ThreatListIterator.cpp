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

#include "tc_catch2.h"

#include "IteratorPair.h"

class ThreatListIterator
{
private:
    std::function<int const* ()> _generator;
    int const* _current;

public:
    explicit ThreatListIterator(std::function<int const* ()>&& generator)
        : _generator(std::move(generator)), _current(_generator())
    { }

    int const* operator*() const { return _current; }
    int const* operator->() const { return _current; }
    ThreatListIterator& operator++() { _current = _generator(); return *this; }
    bool operator==(ThreatListIterator const& o) const { return _current == o._current; }
    bool operator!=(ThreatListIterator const& o) const { return _current != o._current; }
    bool operator==(std::nullptr_t) const { return _current == nullptr; }
    bool operator!=(std::nullptr_t) const { return _current != nullptr; }
};

std::vector<int> ints{ 1, 2, 3, 4 };

Trinity::IteratorPair<ThreatListIterator, std::nullptr_t> GetUnsortedThreatList()
{
    auto itr = ints.begin();
    auto end = ints.end();
    std::function<int const* ()> generator = [itr, end]() mutable -> int const*
    {
        if (itr == end)
            return nullptr;

        return &*(itr++);
    };
    return { ThreatListIterator{ std::move(generator) }, nullptr };
}

TEST_CASE("Check generator logic", "[ThreatListIterator]")
{
    std::vector<int> iterated;
    for (int const* i : GetUnsortedThreatList())
        iterated.push_back(*i);

    REQUIRE(iterated == ints);
}
