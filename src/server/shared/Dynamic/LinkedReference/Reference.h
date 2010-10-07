/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _REFERENCE_H
#define _REFERENCE_H

#include "Dynamic/LinkedList.h"

//=====================================================

template <class TO, class FROM> class Reference : public LinkedListElement
{
    private:
        TO* iRefTo;
        FROM* iRefFrom;
    protected:
        // Tell our refTo (target) object that we have a link
        virtual void targetObjectBuildLink() = 0;

        // Tell our refTo (taget) object, that the link is cut
        virtual void targetObjectDestroyLink() = 0;

        // Tell our refFrom (source) object, that the link is cut (Target destroyed)
        virtual void sourceObjectDestroyLink() = 0;
    public:
        Reference() { iRefTo = NULL; iRefFrom = NULL; }
        virtual ~Reference() {}

        // Create new link
        void link(TO* toObj, FROM* fromObj)
        {
            assert(fromObj);                                // fromObj MUST not be NULL
            if(isValid())
                unlink();
            if(toObj != NULL)
            {
                iRefTo = toObj;
                iRefFrom = fromObj;
                targetObjectBuildLink();
            }
        }

        // We don't need the reference anymore. Call comes from the refFrom object
        // Tell our refTo object, that the link is cut
        void unlink() { targetObjectDestroyLink(); delink(); iRefTo = NULL; iRefFrom = NULL; }

        // Link is invalid due to destruction of referenced target object. Call comes from the refTo object
        // Tell our refFrom object, that the link is cut
        void invalidate()                                   // the iRefFrom MUST remain!!
        {
            sourceObjectDestroyLink(); delink(); iRefTo = NULL;
        }

        bool isValid() const                                // Only check the iRefTo
        {
            return iRefTo != NULL;
        }

        Reference<TO,FROM>       * next()       { return((Reference<TO,FROM>       *) LinkedListElement::next()); }
        Reference<TO,FROM> const * next() const { return((Reference<TO,FROM> const *) LinkedListElement::next()); }
        Reference<TO,FROM>       * prev()       { return((Reference<TO,FROM>       *) LinkedListElement::prev()); }
        Reference<TO,FROM> const * prev() const { return((Reference<TO,FROM> const *) LinkedListElement::prev()); }

        Reference<TO,FROM>       * nocheck_next()       { return((Reference<TO,FROM>       *) LinkedListElement::nocheck_next()); }
        Reference<TO,FROM> const * nocheck_next() const { return((Reference<TO,FROM> const *) LinkedListElement::nocheck_next()); }
        Reference<TO,FROM>       * nocheck_prev()       { return((Reference<TO,FROM>       *) LinkedListElement::nocheck_prev()); }
        Reference<TO,FROM> const * nocheck_prev() const { return((Reference<TO,FROM> const *) LinkedListElement::nocheck_prev()); }

        TO* operator ->() const { return iRefTo; }
        TO* getTarget() const { return iRefTo; }

        FROM* getSource() const { return iRefFrom; }
};

//=====================================================
#endif

