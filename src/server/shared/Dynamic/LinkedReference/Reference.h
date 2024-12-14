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

#ifndef _REFERENCE_H
#define _REFERENCE_H

#include "Dynamic/LinkedList.h"
#include "Errors.h" // for ASSERT

//=====================================================

template <class TO, class FROM, class Derived> class Reference : public LinkedListElement
{
    private:
        TO* iRefTo;
        FROM* iRefFrom;

    protected:
        // Notification functions are found by CRTP
        // Tell our refTo (target) object that we have a link
        //virtual void targetObjectBuildLink() = 0;

        // Tell our refTo (taget) object, that the link is cut
        //virtual void targetObjectDestroyLink() = 0;

        // Tell our refFrom (source) object, that the link is cut (Target destroyed)
        //virtual void sourceObjectDestroyLink() = 0;
    public:
        Reference() { iRefTo = nullptr; iRefFrom = nullptr; }
        ~Reference() { }

        // Create new link
        void link(TO* toObj, FROM* fromObj)
        {
            ASSERT(fromObj);                                // fromObj MUST not be NULL
            if (isValid())
                unlink();
            if (toObj != nullptr)
            {
                iRefTo = toObj;
                iRefFrom = fromObj;
                static_cast<Derived*>(this)->targetObjectBuildLink();
            }
        }

        // We don't need the reference anymore. Call comes from the refFrom object
        // Tell our refTo object, that the link is cut
        void unlink()
        {
            static_cast<Derived*>(this)->targetObjectDestroyLink();
            delink();
            iRefTo = nullptr;
            iRefFrom = nullptr;
        }

        // Link is invalid due to destruction of referenced target object. Call comes from the refTo object
        // Tell our refFrom object, that the link is cut
        void invalidate()                                   // the iRefFrom MUST remain!!
        {
            static_cast<Derived*>(this)->sourceObjectDestroyLink();
            delink();
            iRefTo = nullptr;
        }

        bool isValid() const                                // Only check the iRefTo
        {
            return iRefTo != nullptr;
        }

        Derived      * next()       { return static_cast<Derived*>(LinkedListElement::next()); }
        Derived const* next() const { return static_cast<Derived const*>(LinkedListElement::next()); }
        Derived      * prev()       { return static_cast<Derived*>(LinkedListElement::prev()); }
        Derived const* prev() const { return static_cast<Derived const*>(LinkedListElement::prev()); }

        Derived      * nocheck_next()       { return static_cast<Derived*>(LinkedListElement::nocheck_next()); }
        Derived const* nocheck_next() const { return static_cast<Derived const*>(LinkedListElement::nocheck_next()); }
        Derived      * nocheck_prev()       { return static_cast<Derived*>(LinkedListElement::nocheck_prev()); }
        Derived const* nocheck_prev() const { return static_cast<Derived const*>(LinkedListElement::nocheck_prev()); }

        TO* operator->() const { return iRefTo; }
        TO* getTarget() const { return iRefTo; }

        FROM* GetSource() const { return iRefFrom; }

    private:
        Reference(Reference const&) = delete;
        Reference& operator=(Reference const&) = delete;
};

//=====================================================
#endif
