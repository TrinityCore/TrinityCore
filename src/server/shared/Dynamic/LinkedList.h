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

#ifndef _LINKEDLIST
#define _LINKEDLIST

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
        LinkedListElement iFirst;
        LinkedListElement iLast;
        uint32 iSize;

    public:
        LinkedListHead(): iSize(0)
        {
            // create empty list

            iFirst.iNext = &iLast;
            iLast.iPrev = &iFirst;
        }

        bool empty() const { return iFirst.iNext == &iLast; }

        void push_front(LinkedListElement* pElem)
        {
            iFirst.insertAfter(pElem);
        }

        void push_back(LinkedListElement* pElem)
        {
            iLast.insertBefore(pElem);
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
        T* front_impl() { return static_cast<T*>(iFirst.iNext); }

        template <typename T>
        T const* front_impl() const { return static_cast<T const*>(iFirst.iNext); }

        template <typename T>
        T* back_impl() { return static_cast<T*>(iLast.iPrev); }

        template <typename T>
        T const* back_impl() const { return static_cast<T const*>(iLast.iPrev); }

        template <typename T>
        Iterator<T> begin_impl() { return Iterator<T>(iFirst.iNext); }

        template <typename T>
        Iterator<T const> begin_impl() const { return Iterator<T const>(iFirst.iNext); }

        template <typename T>
        Iterator<T> end_impl() { return Iterator<T>(&iLast); }

        template <typename T>
        Iterator<T const> end_impl() const { return Iterator<T const>(&iLast); }

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
