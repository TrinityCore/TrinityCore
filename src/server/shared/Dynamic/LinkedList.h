/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

        bool hasNext() const  { return (iNext && iNext->iNext != nullptr); }
        bool hasPrev() const  { return (iPrev && iPrev->iPrev != nullptr); }
        bool isInList() const { return (iNext != nullptr && iPrev != nullptr); }

        LinkedListElement      * next()       { return hasNext() ? iNext : nullptr; }
        LinkedListElement const* next() const { return hasNext() ? iNext : nullptr; }
        LinkedListElement      * prev()       { return hasPrev() ? iPrev : nullptr; }
        LinkedListElement const* prev() const { return hasPrev() ? iPrev : nullptr; }

        LinkedListElement      * nocheck_next()       { return iNext; }
        LinkedListElement const* nocheck_next() const { return iNext; }
        LinkedListElement      * nocheck_prev()       { return iPrev; }
        LinkedListElement const* nocheck_prev() const { return iPrev; }

        void delink()
        {
            if (!isInList())
                return;

            iNext->iPrev = iPrev;
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
        LinkedListElement& operator=(LinkedListElement const&) = delete;

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

        bool isEmpty() const { return(!iFirst.iNext->isInList()); }

        LinkedListElement      * getFirst()       { return (isEmpty() ? nullptr : iFirst.iNext); }
        LinkedListElement const* getFirst() const { return (isEmpty() ? nullptr : iFirst.iNext); }

        LinkedListElement      * getLast()       { return(isEmpty() ? nullptr : iLast.iPrev); }
        LinkedListElement const* getLast() const { return(isEmpty() ? nullptr : iLast.iPrev); }

        void insertFirst(LinkedListElement* pElem)
        {
            iFirst.insertAfter(pElem);
        }

        void insertLast(LinkedListElement* pElem)
        {
            iLast.insertBefore(pElem);
        }

        uint32 getSize() const
        {
            if (!iSize)
            {
                uint32 result = 0;
                LinkedListElement const* e = getFirst();
                while (e)
                {
                    ++result;
                    e = e->next();
                }
                return result;
            }
            else
                return iSize;
        }

        void incSize() { ++iSize; }
        void decSize() { --iSize; }

        template<class _Ty>
            class Iterator
        {
            public:
                typedef std::bidirectional_iterator_tag     iterator_category;
                typedef _Ty                                 value_type;
                typedef ptrdiff_t                           difference_type;
                typedef ptrdiff_t                           distance_type;
                typedef _Ty*                                pointer;
                typedef _Ty const*                          const_pointer;
                typedef _Ty&                                reference;
                typedef _Ty const &                         const_reference;

                Iterator() : _Ptr(nullptr)
                {                                           // construct with null node pointer
                }

                Iterator(pointer _Pnode) : _Ptr(_Pnode)
                {                                           // construct with node pointer _Pnode
                }

                Iterator& operator=(Iterator const& _Right)
                {
                    _Ptr = _Right._Ptr;
                    return *this;
                }

                Iterator& operator=(const_pointer const& _Right)
                {
                    _Ptr = pointer(_Right);
                    return *this;
                }

                reference operator*()
                {                                           // return designated value
                    return *_Ptr;
                }

                pointer operator->()
                {                                           // return pointer to class object
                    return _Ptr;
                }

                Iterator& operator++()
                {                                           // preincrement
                    _Ptr = _Ptr->next();
                    return (*this);
                }

                Iterator operator++(int)
                {                                           // postincrement
                    iterator _Tmp = *this;
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
                    iterator _Tmp = *this;
                    --*this;
                    return (_Tmp);
                }

                bool operator==(Iterator const& _Right) const
                {                                           // test for iterator equality
                    return (_Ptr == _Right._Ptr);
                }

                bool operator!=(Iterator const& _Right) const
                {                                           // test for iterator inequality
                    return (!(*this == _Right));
                }

                bool operator==(pointer const& _Right) const
                {                                           // test for pointer equality
                    return (_Ptr != _Right);
                }

                bool operator!=(pointer const& _Right) const
                {                                           // test for pointer equality
                    return (!(*this == _Right));
                }

                bool operator==(const_reference _Right) const
                {                                           // test for reference equality
                    return (_Ptr == &_Right);
                }

                bool operator!=(const_reference _Right) const
                {                                           // test for reference equality
                    return (_Ptr != &_Right);
                }

                pointer _Mynode()
                {                                           // return node pointer
                    return (_Ptr);
                }

            protected:
                pointer _Ptr;                               // pointer to node
        };

        typedef Iterator<LinkedListElement> iterator;

    private:
        LinkedListHead(LinkedListHead const&) = delete;
        LinkedListHead& operator=(LinkedListHead const&) = delete;

    protected:
        ~LinkedListHead() { }
};

//============================================
#endif
