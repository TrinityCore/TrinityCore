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

#ifndef TRINITYCORE_INTRUSIVE_FORWARD_LIST_H
#define TRINITYCORE_INTRUSIVE_FORWARD_LIST_H

#include <atomic>
#include <concepts>
#include <type_traits>
#include <utility>

namespace Trinity::Containers
{
namespace Impl
{
template <typename ListLink>
struct IntrusiveForwardListLinkTraits;

template <typename ListLink>
struct IntrusiveForwardListLinkTraits<ListLink*>
{
    using value_type = ListLink;

    inline static ListLink* GetValuePtr(ListLink* link) { return link; }
    inline static ListLink const* GetValuePtr(ListLink const* link) { return link; }
};

template <typename ListLink>
struct IntrusiveForwardListLinkTraits<std::atomic<ListLink*>>
{
    using value_type = ListLink;

    inline static ListLink* GetValuePtr(std::atomic<ListLink*>& link) { return link.load(); }
    inline static ListLink const* GetValuePtr(std::atomic<ListLink*> const& link) { return link.load(); }
};

template <typename ListLink>
struct IntrusiveForwardListTraits;

template <typename Object, typename Member>
struct IntrusiveForwardListTraits<Member Object::*>
{
    using link_type = Member;
    using link_traits = IntrusiveForwardListLinkTraits<link_type>;
    using value_type = typename link_traits::value_type;
};

template <typename ListLink>
concept IntrusiveForwardListLink = std::is_member_object_pointer_v<ListLink>
    && std::same_as<typename IntrusiveForwardListTraits<ListLink>::value_type, typename IntrusiveForwardListTraits<ListLink>::link_traits::value_type>;
}

template <auto ListLink> requires (Impl::IntrusiveForwardListLink<decltype(ListLink)>)
class IntrusiveForwardList
{
    using queue_traits = Impl::IntrusiveForwardListTraits<decltype(ListLink)>;
    using link_traits = typename queue_traits::link_traits;

    using value_type = typename queue_traits::value_type;
    using link_type = typename queue_traits::link_type;

public:
    IntrusiveForwardList() = default;

    IntrusiveForwardList(IntrusiveForwardList const&) = delete;
    IntrusiveForwardList(IntrusiveForwardList&& other) noexcept :
        _head(link_traits::GetValuePtr(other._head)),
        _tail(empty() ? std::addressof(_head) : std::exchange(other._tail, &other._head))
    {
        other._head = nullptr;
    }

    IntrusiveForwardList& operator=(IntrusiveForwardList const&) = delete;
    IntrusiveForwardList& operator=(IntrusiveForwardList&& other) noexcept
    {
        if (this != &other)
        {
            _head = link_traits::GetValuePtr(other._head);
            other._head = nullptr;
            _tail = empty() ? std::addressof(_head) : std::exchange(other._tail, std::addressof(other._head));
        }
        return *this;
    }

    ~IntrusiveForwardList()
    {
        value_type* node = link_traits::GetValuePtr(_head);
        while (node)
        {
            value_type* next = node->*ListLink;
            node->*ListLink = nullptr;
            node = next;
        }
    }

    bool empty() const
    {
        return !link_traits::GetValuePtr(_head);
    }

    value_type& front()
    {
        return *link_traits::GetValuePtr(_head);
    }

    value_type const& front() const
    {
        return *link_traits::GetValuePtr(_head);
    }

    void push_front(value_type& value)
    {
        value.*ListLink = link_traits::GetValuePtr(_head);
        _head = std::addressof(value);
    }

    void push_back(value_type& value)
    {
        *_tail = std::addressof(value);
        _tail = std::addressof(value.*ListLink);
    }

    void pop_front()
    {
        value_type* head = link_traits::GetValuePtr(_head);
        _head = link_traits::GetValuePtr(head->*ListLink);
        head->*ListLink = nullptr;
        if (empty())
            _tail = std::addressof(_head);
    }

    class const_iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = std::add_const_t<IntrusiveForwardList::value_type>;
        using difference_type = ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;

        reference operator*() const { return static_cast<reference>(*link_traits::GetValuePtr(*_link)); }

        pointer operator->() const { return static_cast<pointer>(link_traits::GetValuePtr(*_link)); }

        const_iterator& operator++()
        {
            value_type* current = link_traits::GetValuePtr(*_link);
            _link = std::addressof(current->*ListLink);
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator tmp = *this;
            ++*this;
            return tmp;
        }

        bool operator==(const_iterator const&) const = default;

        bool operator==(std::default_sentinel_t const&) const { return link_traits::GetValuePtr(*_link) == nullptr; }

    protected:
        friend class IntrusiveForwardList;

        explicit const_iterator(link_type const* link) : _link(link) { }

        link_type const* _link;
    };

    class iterator : public const_iterator
    {
        using const_iterator::const_iterator;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = IntrusiveForwardList::value_type;
        using difference_type = ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;

        reference operator*() const { return const_cast<reference>(const_iterator::operator*()); }

        pointer operator->() const { return const_cast<pointer>(const_iterator::operator->()); }

        iterator& operator++()
        {
            const_iterator::operator++();
            return *this;
        }

        const_iterator operator++(int)
        {
            iterator tmp = *this;
            const_iterator::operator++();
            return tmp;
        }
    };

    iterator begin() { return iterator(std::addressof(_head)); }
    const_iterator begin() const { return const_iterator(std::addressof(_head)); }

    std::default_sentinel_t end() const { return std::default_sentinel; }

    iterator erase(const_iterator itr)
    {
        link_type* link = const_cast<link_type*>(itr._link);
        value_type* elem = link_traits::GetValuePtr(*link);
        value_type* next = link_traits::GetValuePtr(elem->*ListLink);
        elem->*ListLink = nullptr;
        *link = next;
        if (!next)
            _tail = link;
        return iterator(link);
    }

private:
    link_type _head = nullptr;                  ///< First item in queue
    link_type* _tail = std::addressof(_head);   ///< Pointer to intrusive link that will receive next inserted item
};
}

#endif // TRINITYCORE_INTRUSIVE_FORWARD_LIST_H
