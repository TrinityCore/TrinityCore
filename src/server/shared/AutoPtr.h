/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _TRINITY_AUTO_PTR_H
#define _TRINITY_AUTO_PTR_H

#include <ace/Bound_Ptr.h>

namespace Trinity
{
    template <class Pointer, class Lock>
    class AutoPtr : public ACE_Strong_Bound_Ptr<Pointer, Lock>
    {
        public:
            AutoPtr() : ACE_Strong_Bound_Ptr<Pointer, Lock>() {}

            AutoPtr(Pointer* x)
            {
                ACE_Strong_Bound_Ptr<Pointer, Lock>::reset(x);
            }

            operator bool() const
            {
                return ACE_Strong_Bound_Ptr<Pointer, Lock>::get() != NULL;
            }

            bool operator !() const
            {
                return ACE_Strong_Bound_Ptr<Pointer, Lock>::get() == NULL;
            }

            bool operator !=(Pointer* x) const
            {
                return ACE_Strong_Bound_Ptr<Pointer, Lock>::get() != x;
            }
    };
};

#endif