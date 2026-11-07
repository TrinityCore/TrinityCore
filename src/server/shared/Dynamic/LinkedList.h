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

#ifndef TRINITYCORE_LINKED_LIST_H
#define TRINITYCORE_LINKED_LIST_H

#include "Define.h"
#include <iterator>

//============================================
class LinkedListHead;

class LinkedListElement
{
    private:
        friend class LinkedListHead;

        LinkedListElement* iNext;
        LinkedListElement* iPrev;

    public:
        LinkedListElement() : iNext(nullptr), iPrev(nullptr) { }

        bool isInList() const
        {
            return iNext != nullptr /*unlinked element*/
                && iNext != this    /*list head*/;
        }

        LinkedListElement      * next()       { return iNext; }
        LinkedListElement const* next() const { return iNext; }
        LinkedListElement      * prev()       { return iPrev; }
        LinkedListElement const* prev() const { return iPrev; }

        void delink()
        {
            if (iNext)
                iNext->iPrev = iPrev;

            if (iPrev)
                iPrev->iNext = iNext;

            iNext = nullptr;
            iPrev = nullptr;
        }

        void insertBefore(LinkedListElement* pElem)
        {
            pElem->iNext = this;
            pElem->iPrev = iPrev;
            iPrev->iNext = pElem;
            iPrev = pElem;
        }

        void insertAfter(LinkedListElement* pElem)
        {
            pElem->iPrev = this;
            pElem->iNext = iNext;
            iNext->iPrev = pElem;
            iNext = pElem;
        }

    private:
        LinkedListElement(LinkedListElement const&) = delete;
        LinkedListElement(LinkedListElement&&) = delete;
        LinkedListElement& operator=(LinkedListElement const&) = delete;
        LinkedListElement& operator=(LinkedListElement&&) = delete;

    protected:
        ~LinkedListElement()
        {
            delink();
        }
};

//============================================

class LinkedListHead
{
    private:
        LinkedListElement iHeader;
        uint32 iSize;

    public:
        LinkedListHead(): iSize(0)
        {
            // create empty list

            iHeader.iNext = &iHeader;
            iHeader.iPrev = &iHeader;
        }

        bool empty() const { return iHeader.iNext == &iHeader; }

        void push_front(LinkedListElement* pElem)
        {
            iHeader.iNext->insertBefore(pElem);
        }

        void push_back(LinkedListElement* pElem)
        {
            iHeader.insertBefore(pElem);
        }

        void pop_front()
        {
            front_impl<LinkedListElement>()->delink();
        }

        void pop_back()
        {
            back_impl<LinkedListElement>()->delink();
        }

        uint32 size() const
        {
            if (!iSize)
            {
                uint32 result = 0;
                for (auto itr = begin_impl<LinkedListElement>(); itr != end_impl<LinkedListElement>(); ++itr)
                    ++result;

                return result;
            }
            else
                return iSize;
        }

        void incSize() { ++iSize; }
        void decSize() { --iSize; }

        template <typename _Ty>
        class Iterator
        {
            public:
                using iterator_category = std::bidirectional_iterator_tag;
                using value_type = _Ty;
                using difference_type = ptrdiff_t;
                using base_pointer = std::conditional_t<std::is_const_v<_Ty>, LinkedListElement const, LinkedListElement>*;
                using pointer = _Ty*;
                using reference = _Ty&;

                Iterator() : _Ptr(nullptr)
                {                                           // construct with null node pointer
                }

                explicit Iterator(base_pointer _Pnode) : _Ptr(_Pnode)
                {                                           // construct with node pointer _Pnode
                }

                reference operator*() const
                {                                           // return designated value
                    return static_cast<reference>(*_Ptr);
                }

                pointer operator->() const
                {                                           // return pointer to class object
                    return static_cast<pointer>(_Ptr);
                }

                base_pointer node() const
                {
                    return _Ptr;
                }

                Iterator& operator++()
                {                                           // preincrement
                    _Ptr = _Ptr->next();
                    return (*this);
                }

                Iterator operator++(int)
                {                                           // postincrement
                    Iterator _Tmp = *this;
                    ++*this;
                    return (_Tmp);
                }

                Iterator& operator--()
                {                                           // predecrement
                    _Ptr = _Ptr->prev();
                    return (*this);
                }

                Iterator operator--(int)
                {                                           // postdecrement
                    Iterator _Tmp = *this;
                    --*this;
                    return (_Tmp);
                }

                bool operator==(Iterator const& _Right) const = default;
                                                            // test for iterator equality

            protected:
                base_pointer _Ptr;                          // pointer to node
        };

    protected:
        template <typename T>
        T* front_impl() { return static_cast<T*>(iHeader.iNext); }

        template <typename T>
        T const* front_impl() const { return static_cast<T const*>(iHeader.iNext); }

        template <typename T>
        T* back_impl() { return static_cast<T*>(iHeader.iPrev); }

        template <typename T>
        T const* back_impl() const { return static_cast<T const*>(iHeader.iPrev); }

        template <typename T>
        Iterator<T> begin_impl() { return Iterator<T>(iHeader.iNext); }

        template <typename T>
        Iterator<T const> begin_impl() const { return Iterator<T const>(iHeader.iNext); }

        template <typename T>
        Iterator<T> end_impl() { return Iterator<T>(&iHeader); }

        template <typename T>
        Iterator<T const> end_impl() const { return Iterator<T const>(&iHeader); }

        void splice_impl(LinkedListElement* where, LinkedListElement* first, LinkedListElement* last)
        {
            LinkedListElement* wherePrev = where->iPrev;
            LinkedListElement* firstPrev = first->iPrev;
            LinkedListElement* lastPrev = last->iPrev;
            lastPrev->iNext = where;
            where->iPrev = lastPrev;
            firstPrev->iNext = last;
            last->iPrev = firstPrev;
            wherePrev->iNext = first;
            first->iPrev = wherePrev;
        }

        template <typename T>
        void splice_impl(Iterator<T> where, Iterator<T> first, Iterator<T> last)
        {
            splice_impl(where.node(), first.node(), last.node());
        }

    private:
        LinkedListHead(LinkedListHead const&) = delete;
        LinkedListHead(LinkedListHead&&) = delete;
        LinkedListHead& operator=(LinkedListHead const&) = delete;
        LinkedListHead& operator=(LinkedListHead&&) = delete;

    protected:
        ~LinkedListHead() { }
};

//============================================
#endif
