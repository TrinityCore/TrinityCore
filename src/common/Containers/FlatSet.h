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
#ifndef TRINITYCORE_FLAT_SET_H
#define TRINITYCORE_FLAT_SET_H

#include <functional>
#include <vector>

namespace Trinity::Containers
{
template <class Key, class Compare = std::less<Key>, class KeyContainer = std::vector<Key>>
class FlatSet
{
public:
    using iterator = typename KeyContainer::iterator;
    using const_iterator = typename KeyContainer::const_iterator;

    bool empty() const { return _storage.empty(); }
    auto size() const { return _storage.size(); }

    auto begin()  { return _storage.begin(); }
    auto begin() const { return _storage.begin(); }

    auto end()  { return _storage.end(); }
    auto end() const { return _storage.end(); }

    auto find(Key const& value) const
    {
        auto end = this->end();
        auto itr = std::lower_bound(this->begin(), end, value, Compare());
        if (itr != end && Compare()(value, *itr))
            itr = end;

        return itr;
    }

    auto find(Key const& value)
    {
        auto end = this->end();
        auto itr = std::lower_bound(this->begin(), end, value, Compare());
        if (itr != end && Compare()(value, *itr))
            itr = end;

        return itr;
    }

    template <class... Args>
    std::pair<iterator, bool> emplace(Args&&... args)
    {
        Key newElement(std::forward<Args>(args)...);
        auto end = this->end();
        auto itr = std::lower_bound(this->begin(), end, newElement, Compare());
        if (itr != end && !Compare()(newElement, *itr))
            return { itr, false };

        return { _storage.emplace(itr, std::move(newElement)), true };
    }

    std::pair<iterator, bool> insert(Key const& key) { return emplace(key); }

    std::size_t erase(Key const& key)
    {
        auto itr = this->find(key);
        if (itr == this->end())
            return 0;

        this->erase(itr);
        return 1;
    }
    auto erase(const_iterator itr) { return _storage.erase(itr); }

    void clear() { _storage.clear(); }

    void shrink_to_fit() { _storage.shrink_to_fit(); }

    friend bool operator==(FlatSet const& left, FlatSet const& right)
    {
        return left._storage == right._storage;
    }

    friend bool operator!=(FlatSet const& left, FlatSet const& right)
    {
        return !(left == right);
    }

private:
    KeyContainer _storage;
};
}

#endif // TRINITYCORE_FLAT_SET_H
